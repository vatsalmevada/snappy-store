/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#ifndef SNAPPYDATA_STRUCT_STATEMENTATTRS_H
#define SNAPPYDATA_STRUCT_STATEMENTATTRS_H


#include "snappydata_struct_Decimal.h"
#include "snappydata_struct_BlobChunk.h"
#include "snappydata_struct_ClobChunk.h"
#include "snappydata_struct_TransactionXid.h"
#include "snappydata_struct_ServiceMetaData.h"
#include "snappydata_struct_ServiceMetaDataArgs.h"
#include "snappydata_struct_OpenConnectionArgs.h"
#include "snappydata_struct_ConnectionProperties.h"
#include "snappydata_struct_HostAddress.h"
#include "snappydata_struct_SnappyExceptionData.h"

#include "snappydata_types.h"

namespace io { namespace snappydata { namespace thrift {

typedef struct _StatementAttrs__isset {
  _StatementAttrs__isset() : resultSetType(false), updatable(false), holdCursorsOverCommit(false), requireAutoIncCols(false), autoIncColumns(false), autoIncColumnNames(false), batchSize(true), fetchReverse(false), lobChunkSize(false), maxRows(false), maxFieldSize(false), timeout(false), cursorName(false), possibleDuplicate(false), poolable(false), doEscapeProcessing(false), pendingTransactionAttrs(false), bucketIds(false), bucketIdsTable(false), retainBucketIds(false), metadataVersion(false), snapshotTransactionId(false), catalogVersion(false) {}
  bool resultSetType :1;
  bool updatable :1;
  bool holdCursorsOverCommit :1;
  bool requireAutoIncCols :1;
  bool autoIncColumns :1;
  bool autoIncColumnNames :1;
  bool batchSize :1;
  bool fetchReverse :1;
  bool lobChunkSize :1;
  bool maxRows :1;
  bool maxFieldSize :1;
  bool timeout :1;
  bool cursorName :1;
  bool possibleDuplicate :1;
  bool poolable :1;
  bool doEscapeProcessing :1;
  bool pendingTransactionAttrs :1;
  bool bucketIds :1;
  bool bucketIdsTable :1;
  bool retainBucketIds :1;
  bool metadataVersion :1;
  bool snapshotTransactionId :1;
  bool catalogVersion :1;
} _StatementAttrs__isset;

class StatementAttrs {
 public:

  StatementAttrs(const StatementAttrs&);
  StatementAttrs(StatementAttrs&&) noexcept;
  StatementAttrs& operator=(const StatementAttrs&);
  StatementAttrs& operator=(StatementAttrs&&) noexcept;
  StatementAttrs() : resultSetType(0), updatable(0), holdCursorsOverCommit(0), requireAutoIncCols(0), batchSize(8192), fetchReverse(0), lobChunkSize(0), maxRows(0), maxFieldSize(0), timeout(0), cursorName(), possibleDuplicate(0), poolable(0), doEscapeProcessing(0), bucketIdsTable(), retainBucketIds(0), metadataVersion(0), snapshotTransactionId(), catalogVersion(0) {
  }

  virtual ~StatementAttrs() noexcept;
  int8_t resultSetType;
  bool updatable;
  bool holdCursorsOverCommit;
  bool requireAutoIncCols;
  std::vector<int32_t>  autoIncColumns;
  std::vector<std::string>  autoIncColumnNames;
  int32_t batchSize;
  bool fetchReverse;
  int32_t lobChunkSize;
  int32_t maxRows;
  int32_t maxFieldSize;
  int32_t timeout;
  std::string cursorName;
  bool possibleDuplicate;
  bool poolable;
  bool doEscapeProcessing;
  std::map<TransactionAttribute::type, bool>  pendingTransactionAttrs;
  std::set<int32_t>  bucketIds;
  std::string bucketIdsTable;
  bool retainBucketIds;
  int32_t metadataVersion;
  std::string snapshotTransactionId;
  int64_t catalogVersion;

  _StatementAttrs__isset __isset;

  void __set_resultSetType(const int8_t val);

  void __set_updatable(const bool val);

  void __set_holdCursorsOverCommit(const bool val);

  void __set_requireAutoIncCols(const bool val);

  void __set_autoIncColumns(const std::vector<int32_t> & val);

  void __set_autoIncColumnNames(const std::vector<std::string> & val);

  void __set_batchSize(const int32_t val);

  void __set_fetchReverse(const bool val);

  void __set_lobChunkSize(const int32_t val);

  void __set_maxRows(const int32_t val);

  void __set_maxFieldSize(const int32_t val);

  void __set_timeout(const int32_t val);

  void __set_cursorName(const std::string& val);

  void __set_possibleDuplicate(const bool val);

  void __set_poolable(const bool val);

  void __set_doEscapeProcessing(const bool val);

  void __set_pendingTransactionAttrs(const std::map<TransactionAttribute::type, bool> & val);

  void __set_bucketIds(const std::set<int32_t> & val);

  void __set_bucketIdsTable(const std::string& val);

  void __set_retainBucketIds(const bool val);

  void __set_metadataVersion(const int32_t val);

  void __set_snapshotTransactionId(const std::string& val);

  void __set_catalogVersion(const int64_t val);

  bool operator == (const StatementAttrs & rhs) const
  {
    if (__isset.resultSetType != rhs.__isset.resultSetType)
      return false;
    else if (__isset.resultSetType && !(resultSetType == rhs.resultSetType))
      return false;
    if (__isset.updatable != rhs.__isset.updatable)
      return false;
    else if (__isset.updatable && !(updatable == rhs.updatable))
      return false;
    if (__isset.holdCursorsOverCommit != rhs.__isset.holdCursorsOverCommit)
      return false;
    else if (__isset.holdCursorsOverCommit && !(holdCursorsOverCommit == rhs.holdCursorsOverCommit))
      return false;
    if (__isset.requireAutoIncCols != rhs.__isset.requireAutoIncCols)
      return false;
    else if (__isset.requireAutoIncCols && !(requireAutoIncCols == rhs.requireAutoIncCols))
      return false;
    if (__isset.autoIncColumns != rhs.__isset.autoIncColumns)
      return false;
    else if (__isset.autoIncColumns && !(autoIncColumns == rhs.autoIncColumns))
      return false;
    if (__isset.autoIncColumnNames != rhs.__isset.autoIncColumnNames)
      return false;
    else if (__isset.autoIncColumnNames && !(autoIncColumnNames == rhs.autoIncColumnNames))
      return false;
    if (__isset.batchSize != rhs.__isset.batchSize)
      return false;
    else if (__isset.batchSize && !(batchSize == rhs.batchSize))
      return false;
    if (__isset.fetchReverse != rhs.__isset.fetchReverse)
      return false;
    else if (__isset.fetchReverse && !(fetchReverse == rhs.fetchReverse))
      return false;
    if (__isset.lobChunkSize != rhs.__isset.lobChunkSize)
      return false;
    else if (__isset.lobChunkSize && !(lobChunkSize == rhs.lobChunkSize))
      return false;
    if (__isset.maxRows != rhs.__isset.maxRows)
      return false;
    else if (__isset.maxRows && !(maxRows == rhs.maxRows))
      return false;
    if (__isset.maxFieldSize != rhs.__isset.maxFieldSize)
      return false;
    else if (__isset.maxFieldSize && !(maxFieldSize == rhs.maxFieldSize))
      return false;
    if (__isset.timeout != rhs.__isset.timeout)
      return false;
    else if (__isset.timeout && !(timeout == rhs.timeout))
      return false;
    if (__isset.cursorName != rhs.__isset.cursorName)
      return false;
    else if (__isset.cursorName && !(cursorName == rhs.cursorName))
      return false;
    if (__isset.possibleDuplicate != rhs.__isset.possibleDuplicate)
      return false;
    else if (__isset.possibleDuplicate && !(possibleDuplicate == rhs.possibleDuplicate))
      return false;
    if (__isset.poolable != rhs.__isset.poolable)
      return false;
    else if (__isset.poolable && !(poolable == rhs.poolable))
      return false;
    if (__isset.doEscapeProcessing != rhs.__isset.doEscapeProcessing)
      return false;
    else if (__isset.doEscapeProcessing && !(doEscapeProcessing == rhs.doEscapeProcessing))
      return false;
    if (__isset.pendingTransactionAttrs != rhs.__isset.pendingTransactionAttrs)
      return false;
    else if (__isset.pendingTransactionAttrs && !(pendingTransactionAttrs == rhs.pendingTransactionAttrs))
      return false;
    if (__isset.bucketIds != rhs.__isset.bucketIds)
      return false;
    else if (__isset.bucketIds && !(bucketIds == rhs.bucketIds))
      return false;
    if (__isset.bucketIdsTable != rhs.__isset.bucketIdsTable)
      return false;
    else if (__isset.bucketIdsTable && !(bucketIdsTable == rhs.bucketIdsTable))
      return false;
    if (__isset.retainBucketIds != rhs.__isset.retainBucketIds)
      return false;
    else if (__isset.retainBucketIds && !(retainBucketIds == rhs.retainBucketIds))
      return false;
    if (__isset.metadataVersion != rhs.__isset.metadataVersion)
      return false;
    else if (__isset.metadataVersion && !(metadataVersion == rhs.metadataVersion))
      return false;
    if (__isset.snapshotTransactionId != rhs.__isset.snapshotTransactionId)
      return false;
    else if (__isset.snapshotTransactionId && !(snapshotTransactionId == rhs.snapshotTransactionId))
      return false;
    if (__isset.catalogVersion != rhs.__isset.catalogVersion)
      return false;
    else if (__isset.catalogVersion && !(catalogVersion == rhs.catalogVersion))
      return false;
    return true;
  }
  bool operator != (const StatementAttrs &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const StatementAttrs & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(StatementAttrs &a, StatementAttrs &b);

inline std::ostream& operator<<(std::ostream& out, const StatementAttrs& obj)
{
  obj.printTo(out);
  return out;
}

}}} // namespace

#endif
