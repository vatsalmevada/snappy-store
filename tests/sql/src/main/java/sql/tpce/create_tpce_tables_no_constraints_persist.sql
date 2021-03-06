-- This version of schema implements the server group in addition to v2.
-- v4 is changed from v3:
-- last_trade to REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS; -- distributed join limitation
-- v5 is changed from v4:
-- sector, industry, company, company_competitor should be replicated to CustomerGroup as well to support
-- BrokerVolume query
-- create a table holding_summary_tbl to work around 46865, the holding_summary issue
-- =========================================
-- TYPE MAPPING FOR TPCE:GEMFIREXD
-- IDENT_T NUM(11):BIGINT(BIGINT)
-- TRADE_T NUM(15):BIGINT(BIGINT)
-- FIN_AGG_T SENUM(15,2): FLOAT(FLOAT) --> DECIMAL(15,2) 
-- S_PRICE ENUM(8,2):FLOAT(FLOAT) --> DECIMAL(8,2) 
-- S_COUNT_T NUM(12):BIGINT(BIGINT)
-- S_PRICE_T ENUM(8,2):FLOAT(FLOAT)--> DECIMAL(8,2) 
-- S_QTY_T SNUM(6): INTEGER (INTEGER)
-- BALANCE_T SENUM(12,2): FLOAT (FLOAT) --> DECIMAL(12,2) 
-- VALUE_T SENUM(10,2):FLOAT(FLOAT) --> DECIMAL(10,2) 
-- NUM(1):SMALLINT (SMALLINT)
-- BOOLEAN:SMALLINT (TINYINT)
-- CHAR:VARCHAR(VARCHAR for some)
-- DATETIME:TIMESTAMP(TIMESTAMP)
-- DATE:DATE (TIMESTAMP)
-- Foreign Key is implicitly indexed in GemFireXD
-- Partition/Replicate Strategies:
-- 1. Limitted by partition/colocate on parent/child/grandchild tables
-- 2. Limitted by distributed join
-- 3. Dimension tables are recommended to replicate
-- Two server groups:
-- 1. MarketGroup: include all markets tables
-- 2. CustomerGroup: include all customer and broker tables
-- 3. Replicated tables exchange, security and dimension tables are included in two server groups

-- =========================================
-- DIMENSION TABLES
-- =========================================

CREATE SCHEMA TPCEGFXD;

SET SCHEMA TPCEGFXD;

-- TPC-E Clause 2.2.7.4
CREATE TABLE zip_code (
   zc_code CHAR(12) NOT NULL,
   zc_town VARCHAR(80) NOT NULL,
   zc_div VARCHAR(80) NOT NULL,
   PRIMARY KEY (zc_code)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.7.1
CREATE TABLE address (
   ad_id BIGINT NOT NULL,
   ad_line1 VARCHAR(80),
   ad_line2 VARCHAR(80),
   ad_zc_code CHAR(12) NOT NULL, 
   ad_ctry VARCHAR(80),
   PRIMARY KEY (ad_id)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.7.2
CREATE TABLE status_type (
   st_id CHAR(4) NOT NULL,
   st_name CHAR(10) NOT NULL,
   PRIMARY KEY (st_id)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.7.3
-- tx_rate NUM(6,5)
CREATE TABLE taxrate (
   tx_id CHAR(4) NOT NULL,
   tx_name VARCHAR(50) NOT NULL,
   tx_rate NUMERIC(6,5) NOT NULL CHECK (tx_rate >= 0),
   PRIMARY KEY (tx_id)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- =========================================
-- CUSTOMER TABLES (1/2)
-- =========================================

-- TPC-E Clause 2.2.4.2
-- c_tier NUM(1)
CREATE TABLE customer (
   c_id BIGINT NOT NULL,
   c_tax_id VARCHAR(20) NOT NULL,
   c_st_id CHAR(4) NOT NULL, 
   c_l_name VARCHAR(25) NOT NULL,
   c_f_name VARCHAR(20) NOT NULL,
   c_m_name CHAR(1),
   c_gndr CHAR(1),
   c_tier SMALLINT NOT NULL CHECK (c_tier IN (1,2,3)),
   c_dob DATE NOT NULL,
   c_ad_id BIGINT NOT NULL, 
   c_ctry_1 CHAR(3),
   c_area_1 CHAR(3),
   c_local_1 CHAR(10),
   c_ext_1 CHAR(5),
   c_ctry_2 CHAR(3),
   c_area_2 CHAR(3),
   c_local_2 CHAR(10),
   c_ext_2 CHAR(5),
   c_ctry_3 CHAR(3),
   c_area_3 CHAR(3),
   c_local_3 CHAR(10),
   c_ext_3 CHAR(5),
   c_email_1 VARCHAR(50),
   c_email_2 VARCHAR(50),
   PRIMARY KEY (c_id)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;
CREATE INDEX i_c_tax_id ON customer (c_tax_id);

-- =========================================
-- MARKET TABLES
-- =========================================

-- TPC-E Clause 2.2.6.4
-- ex_num_symb NUM(6) (INTEGER)
-- ex_open NUM(4) (INTEGER)
-- ex_close NUM(4) (INTEGER)
CREATE TABLE exchange (
   ex_id CHAR(6) NOT NULL,
   ex_name VARCHAR(100) NOT NULL,
   ex_num_symb NUMERIC(6) NOT NULL,
   ex_open NUMERIC(4) NOT NULL,
   ex_close NUMERIC(4) NOT NULL,
   ex_desc VARCHAR(150),
   ex_ad_id BIGINT NOT NULL, 
   PRIMARY KEY (ex_id)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.6.10
CREATE TABLE sector (
   sc_id CHAR(2) NOT NULL,
   sc_name VARCHAR(30) NOT NULL,
   PRIMARY KEY (sc_id)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.6.6
CREATE TABLE industry (
   in_id CHAR(2) NOT NULL,
   in_name VARCHAR(50) NOT NULL,
   in_sc_id CHAR(2) NOT NULL, 
   PRIMARY KEY (in_id)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.6.1
CREATE TABLE company (
   co_id BIGINT NOT NULL,
   co_st_id CHAR(4) NOT NULL, 
   co_name VARCHAR(60) NOT NULL,
   co_in_id CHAR(2) NOT NULL, 
   co_sp_rate CHAR(4) NOT NULL,
   co_ceo VARCHAR(46) NOT NULL,
   co_ad_id BIGINT NOT NULL, 
   co_desc VARCHAR(150) NOT NULL,
   co_open_date DATE NOT NULL,
   PRIMARY KEY (co_id)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;
CREATE INDEX i_co_name ON company (co_name);

-- TPC-E Clause 2.2.6.2
CREATE TABLE company_competitor (
   cp_co_id BIGINT NOT NULL, 
   cp_comp_co_id BIGINT NOT NULL, 
   cp_in_id CHAR(2) NOT NULL, 
   PRIMARY KEY (cp_co_id, cp_comp_co_id, cp_in_id)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.6.11
-- s_pe/s_dividend VALUE_T
-- s_52wk_high/s_52wk_low S_PRICE_T
-- s_yield NUM(5,2)
CREATE TABLE security (
   s_symb CHAR(15) NOT NULL,
   s_issue CHAR(6) NOT NULL,
   s_st_id CHAR(4) NOT NULL, 
   s_name VARCHAR(70) NOT NULL,
   s_ex_id CHAR(6) NOT NULL, 
   s_co_id BIGINT NOT NULL, 
   s_num_out BIGINT NOT NULL,
   s_start_date DATE NOT NULL,
   s_exch_date DATE NOT NULL,
   s_pe DECIMAL(10,2) NOT NULL,
   s_52wk_high DECIMAL(8,2) NOT NULL,
   s_52wk_high_date DATE NOT NULL,
   s_52wk_low DECIMAL(8,2) NOT NULL,
   s_52wk_low_date DATE NOT NULL,
   s_dividend DECIMAL(10,2) NOT NULL,
   s_yield FLOAT NOT NULL,
   PRIMARY KEY (s_symb)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;
CREATE INDEX i_security ON security (s_co_id, s_issue);

-- TPC-E Clause 2.2.6.3
-- dm_close/dm_low/dm_high S_PRICE_T
CREATE TABLE daily_market (
   dm_date DATE NOT NULL,
   dm_s_symb CHAR(15) NOT NULL, 
   dm_close DECIMAL(8,2) NOT NULL,
   dm_high DECIMAL(8,2) NOT NULL,
   dm_low DECIMAL(8,2) NOT NULL,
   dm_vol BIGINT NOT NULL,
   PRIMARY KEY (dm_date, dm_s_symb)
) PARTITION BY PRIMARY KEY SERVER GROUPS(MarketGroup) PERSISTENT ASYNCHRONOUS;
-- CREATE INDEX i_dm_s_symb ON daily_market (dm_s_symb);

-- TPC-E Clause 2.2.6.5
-- fi_year NUM(4) (INTEGER)
-- SMALLINT used for fi_qty NUM(1)
-- fi_revenue/fi_net_earn/fi_inventory/fi_assets/fi_liability FIN_AGG_T
-- fi_basic_eps/fidilut_eps/fi_margin VALUE_T


CREATE TABLE financial (
   fi_co_id BIGINT NOT NULL, 
   fi_year NUMERIC(4) NOT NULL,
   fi_qtr SMALLINT NOT NULL,
   fi_qtr_start_date DATE NOT NULL,
   fi_revenue DECIMAL(15,2) NOT NULL,
   fi_net_earn DECIMAL(15,2) NOT NULL,
   fi_basic_eps DECIMAL(10,2) NOT NULL,
   fi_dilut_eps DECIMAL(10,2) NOT NULL,
   fi_margin DECIMAL(10,2) NOT NULL,
   fi_inventory DECIMAL(15,2) NOT NULL,
   fi_assets DECIMAL(15,2) NOT NULL,
   fi_liability DECIMAL(15,2) NOT NULL,
   fi_out_basic BIGINT NOT NULL,
   fi_out_dilut BIGINT NOT NULL,
   PRIMARY KEY (fi_co_id, fi_year, fi_qtr)
) PARTITION BY PRIMARY KEY SERVER GROUPS(MarketGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.6.7
-- lt_dts DATETIME: TIMESTAMP
-- lt_price/lt_open_price S_PRICE_T
CREATE TABLE last_trade (
   lt_s_symb CHAR(15) NOT NULL, 
   lt_dts TIMESTAMP NOT NULL,
   lt_price DECIMAL(8,2) NOT NULL,
   lt_open_price DECIMAL(8,2) NOT NULL,
   lt_vol BIGINT,
   PRIMARY KEY (lt_s_symb)
) REPLICATE SERVER GROUPS(MarketGroup, CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.6.8
-- =========
-- ni_dts DATETIME:TIMESTAMP
-- ni_item BLOB(100K), no BLOB_REF (VARCHAR(2000))
CREATE TABLE news_item (
   ni_id BIGINT NOT NULL,
   ni_headline VARCHAR(80) NOT NULL,
   ni_summary VARCHAR(255) NOT NULL,
   ni_item BLOB(100K) NOT NULL,
   ni_dts TIMESTAMP NOT NULL,
   ni_source VARCHAR(30) NOT NULL,
   ni_author VARCHAR(30),
   PRIMARY KEY (ni_id)
) PARTITION BY PRIMARY KEY SERVER GROUPS(MarketGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.6.9
CREATE TABLE news_xref (
   nx_ni_id BIGINT NOT NULL, 
   nx_co_id BIGINT NOT NULL, 
   PRIMARY KEY (nx_ni_id, nx_co_id)
) REPLICATE SERVER GROUPS(MarketGroup) PERSISTENT ASYNCHRONOUS;

-- =========================================
-- BROKER TABLES
-- =========================================

-- TPC-E Clause 2.2.5.1
-- b_num_trades NUM(9)
-- b_comm_total BALANCE_T
CREATE TABLE broker (
   b_id BIGINT NOT NULL,
   b_st_id CHAR(4) NOT NULL, 
   b_name VARCHAR(49) NOT NULL,
   b_num_trades INTEGER NOT NULL,
   b_comm_total DECIMAL(12,2) NOT NULL,
   PRIMARY KEY (b_id)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- =========================================
-- CUSTOMER TABLES (2/2)
-- =========================================

-- TPC-E Clause 2.2.4.3
-- ca_tax_st NUM(1) -added the constraint in (0,1,2)
-- ca_bal BALANCE_T (senum(12,2))
CREATE TABLE customer_account (
   ca_id BIGINT NOT NULL,
   ca_b_id BIGINT NOT NULL, 
   ca_c_id BIGINT NOT NULL, 
   ca_name VARCHAR(50),
   ca_tax_st SMALLINT NOT NULL CHECK (ca_tax_st IN (0,1,2)),
   ca_bal DECIMAL(12,2) NOT NULL,
   PRIMARY KEY (ca_id)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;
-- CREATE INDEX i_ca_c_id ON customer_account (ca_c_id);

-- TPC-E Clause 2.2.4.1
CREATE TABLE account_permission (
   ap_ca_id BIGINT NOT NULL, 
   ap_acl CHAR(4) NOT NULL,
   ap_tax_id VARCHAR(20) NOT NULL,
   ap_l_name VARCHAR(25) NOT NULL,
   ap_f_name VARCHAR(20) NOT NULL,
   PRIMARY KEY (ap_ca_id, ap_tax_id)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.4.4
CREATE TABLE customer_taxrate (
   cx_tx_id CHAR(4) NOT NULL, 
   cx_c_id BIGINT NOT NULL, 
   PRIMARY KEY (cx_tx_id, cx_c_id)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- =========================================
-- BROKER TABLES (2/2)
-- =========================================

-- TPC-E Clause 2.2.5.9
-- tt_is_sell/tt_is_mrkt BOOLEAN
CREATE TABLE trade_type (
   tt_id CHAR(3) NOT NULL,
   tt_name CHAR(12) NOT NULL,
   tt_is_sell SMALLINT NOT NULL CHECK (tt_is_sell IN (0,1)),
   tt_is_mrkt SMALLINT NOT NULL CHECK (tt_is_mrkt IN (0,1)),
   PRIMARY KEY (tt_id)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.5.6
-- t_dts DATETIME
-- t_is_cash/t_lifo BOOLEAN
-- t_bid_price/t_trade_price S_PRICE_T (ENUM(8,2))
-- t_chrg/t_comm/t_tax VALUE_T(SENUM(10,2))
CREATE TABLE trade (
   t_id BIGINT NOT NULL GENERATED BY DEFAULT AS IDENTITY,
   t_dts TIMESTAMP NOT NULL,
   t_st_id CHAR(4) NOT NULL, 
   t_tt_id CHAR(3) NOT NULL, 
   t_is_cash SMALLINT NOT NULL CHECK (t_is_cash in (0, 1)),
   t_s_symb CHAR(15) NOT NULL, 
   t_qty INTEGER NOT NULL CHECK (t_qty > 0),
   t_bid_price DECIMAL(8,2) NOT NULL CHECK (t_bid_price > 0),
   t_ca_id BIGINT NOT NULL, 
   t_exec_name VARCHAR(49) NOT NULL,
   t_trade_price DECIMAL(8,2),
   t_chrg DECIMAL(10,2) NOT NULL CHECK (t_chrg >= 0),
   t_comm DECIMAL(10,2) NOT NULL CHECK (t_comm >= 0),
   t_tax DECIMAL(10,2) NOT NULL CHECK (t_tax >= 0),
   t_lifo SMALLINT NOT NULL CHECK (t_lifo in (0, 1)),
   PRIMARY KEY (t_id)
) PARTITION BY PRIMARY KEY SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;
-- CREATE INDEX i_t_st_id ON trade (t_st_id);
-- CREATE INDEX i_t_ca_id ON trade (t_ca_id);

-- TPC-E Clause 2.2.5.5
-- se_amt VALUE_T
CREATE TABLE settlement (
   se_t_id BIGINT NOT NULL, 
   se_cash_type VARCHAR(40) NOT NULL,
   se_cash_due_date DATE NOT NULL,
   se_amt DECIMAL(10,2) NOT NULL,
   PRIMARY KEY (se_t_id)
) PARTITION BY COLUMN (se_t_id) COLOCATE WITH (trade) SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.5.7
-- th_dts DATETIME
CREATE TABLE trade_history (
   th_t_id BIGINT NOT NULL, 
   th_dts TIMESTAMP NOT NULL,
   th_st_id CHAR(4) NOT NULL, 
   PRIMARY KEY (th_t_id, th_st_id)
) PARTITION BY COLUMN (th_t_id) COLOCATE WITH (trade) SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.4.7
-- CREATE TABLE holding_summary (
--   hs_ca_id BIGINT NOT NULL, 
--   hs_s_symb CHAR(15) NOT NULL, 
--   hs_qty INTEGER NOT NULL,
--   PRIMARY KEY (hs_ca_id, hs_s_symb)
-- );

-- TPC-E Clause 2.2.4.7 -- view does not work in gemfirexd
CREATE TABLE holding_summary_tbl (
     hs_ca_id BIGINT NOT NULL, 
     hs_s_symb CHAR(15) NOT NULL, 
     hs_qty INTEGER NOT NULL,
     PRIMARY KEY (hs_ca_id, hs_s_symb)
     ) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.4.5
-- h_dts DATETIME:TIMESTAMP
-- h_price S_PRICE_T (enum(8,2))
-- h_qty S_QTY (snum(6)):INTEGER
-- CREATE TABLE holding (
--   h_t_id BIGINT NOT NULL, 
--   h_ca_id BIGINT NOT NULL,
--   h_s_symb CHAR(15) NOT NULL,
--   h_dts TIMESTAMP NOT NULL,
--   h_price FLOAT NOT NULL CHECK (h_price > 0),
--   h_qty INTEGER NOT NULL,
--   PRIMARY KEY (h_t_id),
--   FOREIGN KEY (h_ca_id, h_s_symb), 
-- ) REPLICATE;
-- CREATE INDEX i_holding ON holding (h_ca_id, h_s_symb);

-- Implement the holding_summary as the view of holding:
-- ====================================================
-- TPC-E Clause 2.2.4.5
-- h_dts DATETIME:TIMESTAMP
-- h_price S_PRICE_T (enum(8,2))
-- h_qty S_QTY (snum(6)):INTEGER
-- FOREIGN KEY (h_ca_id, h_s_symb), 
--
CREATE TABLE holding (
   h_t_id BIGINT NOT NULL, 
   h_ca_id BIGINT NOT NULL, 
   h_s_symb CHAR(15) NOT NULL, 
   h_dts TIMESTAMP NOT NULL,
   h_price DECIMAL(8,2) NOT NULL CHECK (h_price > 0),
   h_qty INTEGER NOT NULL,
   PRIMARY KEY (h_t_id)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- Verified against holding_summary physical table with:
-- select count (hs_qty_diff) from (select v.hs_qty - t.hs_qty as hs_qty_diff from holding_summary_vw v, holding_summary t
-- where v.hs_ca_id = t.hs_ca_id and v.hs_s_symb = t.hs_s_symb) hs_diff where hs_diff.hs_qty_diff != 0;
CREATE VIEW holding_summary (hs_ca_id, hs_s_symb, hs_qty)
   AS SELECT h_ca_id, h_s_symb, sum(h_qty)
   FROM holding GROUP BY h_ca_id, h_s_symb;

-- TPC-E Clause 2.2.4.6
-- hh_h_t_id: the trade_id that originally created this holding. In TPC-E, this information is just retrieval.
-- hh_t_id: the trade_id of current trade
-- so it will make more sense if we partiton this table on hh_t_id
-- hh_h_t_id/hh_t_id TRADE_T:BIGINT
-- hh_before_qty/hh_after_qty S_QTY_T:INTEGER
CREATE TABLE holding_history (
   hh_h_t_id BIGINT NOT NULL, 
   hh_t_id BIGINT NOT NULL, 
   hh_before_qty INTEGER NOT NULL,
   hh_after_qty INTEGER NOT NULL,
   PRIMARY KEY (hh_h_t_id, hh_t_id)
) PARTITION BY COLUMN (hh_t_id) COLOCATE WITH (trade) SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.4.9
CREATE TABLE watch_list (
   wl_id BIGINT NOT NULL,
   wl_c_id BIGINT NOT NULL, 
   PRIMARY KEY (wl_id)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;
-- CREATE INDEX i_wl_c_id ON watch_list (wl_c_id);

-- TPC-E Clause 2.2.4.8
CREATE TABLE watch_item (
   wi_wl_id BIGINT NOT NULL, 
   wi_s_symb CHAR(15) NOT NULL, 
   PRIMARY KEY (wi_wl_id, wi_s_symb)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- =========================================
-- BROKER TABLES
-- =========================================

-- TPC-E Clause 2.2.5.2
-- ct_dts DATETIME: TIMESTAMP
-- ct_amt VALUE_T (SENUM(10,2))
CREATE TABLE cash_transaction (
   ct_t_id BIGINT NOT NULL, 
   ct_dts TIMESTAMP NOT NULL,
   ct_amt DECIMAL(10,2) NOT NULL,
   ct_name VARCHAR(100),
   PRIMARY KEY (ct_t_id)
) PARTITION BY COLUMN (ct_t_id) COLOCATE WITH (trade) SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.5.3
-- ch_c_tier NUM(1) -add constraint (1,2,3)
CREATE TABLE charge (
   ch_tt_id CHAR(3) NOT NULL, 
   ch_c_tier SMALLINT CHECK (ch_c_tier IN (1,2,3)),
   ch_chrg FLOAT CHECK (ch_chrg >= 0),
   PRIMARY KEY (ch_tt_id, ch_c_tier)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.5.4
-- cr_c_tier NUM(1) -add constraint (1,2,3)
-- cr_rate NUM(5,2): (FLOAT)
CREATE TABLE commission_rate (
   cr_c_tier SMALLINT NOT NULL CHECK (cr_c_tier in (1,2,3)),
   cr_tt_id CHAR(3) NOT NULL, 
   cr_ex_id CHAR(6) NOT NULL, 
   cr_from_qty INTEGER NOT NULL CHECK (cr_from_qty >= 0),
   cr_to_qty INTEGER NOT NULL,
   cr_rate NUMERIC(5,2) NOT NULL CHECK (cr_rate >= 0),
   PRIMARY KEY (cr_c_tier, cr_tt_id, cr_ex_id, cr_from_qty),
   CONSTRAINT cr_c CHECK (cr_to_qty > cr_from_qty)
) REPLICATE SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;

-- TPC-E Clause 2.2.5.8
-- S_PRICE_T:FLOAT
-- To Do: Need check which, tr_ca_id or tr_b_id or both, is needed
CREATE TABLE trade_request (
   tr_t_id BIGINT NOT NULL, 
   tr_tt_id CHAR(3) NOT NULL, 
   tr_s_symb CHAR(15) NOT NULL, 
   tr_qty INTEGER NOT NULL CHECK (tr_qty > 0),
   tr_bid_price DECIMAL(8,2) NOT NULL CHECK (tr_bid_price > 0),
   tr_ca_id BIGINT NOT NULL, 
   tr_b_id BIGINT NOT NULL, 
   PRIMARY KEY (tr_t_id)
) PARTITION BY COLUMN (tr_t_id) COLOCATE WITH (trade) SERVER GROUPS(CustomerGroup) PERSISTENT ASYNCHRONOUS;
-- CREATE INDEX i_tr_s_symb ON trade_request (tr_s_symb);
exit;
