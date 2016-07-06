/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>
#include "snappydata_struct_StatementResult.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace io { namespace snappydata { namespace thrift {


StatementResult::~StatementResult() noexcept {
}


void StatementResult::__set_resultSet(const RowSet& val) {
  this->resultSet = val;
__isset.resultSet = true;
}

void StatementResult::__set_updateCount(const int32_t val) {
  this->updateCount = val;
__isset.updateCount = true;
}

void StatementResult::__set_batchUpdateCounts(const std::vector<int32_t> & val) {
  this->batchUpdateCounts = val;
__isset.batchUpdateCounts = true;
}

void StatementResult::__set_procedureOutParams(const std::map<int32_t, ColumnValue> & val) {
  this->procedureOutParams = val;
__isset.procedureOutParams = true;
}

void StatementResult::__set_generatedKeys(const RowSet& val) {
  this->generatedKeys = val;
__isset.generatedKeys = true;
}

void StatementResult::__set_warnings(const SnappyExceptionData& val) {
  this->warnings = val;
__isset.warnings = true;
}

void StatementResult::__set_preparedResult(const PrepareResult& val) {
  this->preparedResult = val;
__isset.preparedResult = true;
}

uint32_t StatementResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->resultSet.read(iprot);
          this->__isset.resultSet = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->updateCount);
          this->__isset.updateCount = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->batchUpdateCounts.clear();
            uint32_t _size311;
            ::apache::thrift::protocol::TType _etype314;
            xfer += iprot->readListBegin(_etype314, _size311);
            this->batchUpdateCounts.resize(_size311);
            uint32_t _i315;
            for (_i315 = 0; _i315 < _size311; ++_i315)
            {
              xfer += iprot->readI32(this->batchUpdateCounts[_i315]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.batchUpdateCounts = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->procedureOutParams.clear();
            uint32_t _size316;
            ::apache::thrift::protocol::TType _ktype317;
            ::apache::thrift::protocol::TType _vtype318;
            xfer += iprot->readMapBegin(_ktype317, _vtype318, _size316);
            uint32_t _i320;
            for (_i320 = 0; _i320 < _size316; ++_i320)
            {
              int32_t _key321;
              xfer += iprot->readI32(_key321);
              ColumnValue& _val322 = this->procedureOutParams[_key321];
              xfer += _val322.read(iprot);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.procedureOutParams = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->generatedKeys.read(iprot);
          this->__isset.generatedKeys = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->warnings.read(iprot);
          this->__isset.warnings = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->preparedResult.read(iprot);
          this->__isset.preparedResult = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t StatementResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("StatementResult");

  if (this->__isset.resultSet) {
    xfer += oprot->writeFieldBegin("resultSet", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->resultSet.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.updateCount) {
    xfer += oprot->writeFieldBegin("updateCount", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->updateCount);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.batchUpdateCounts) {
    xfer += oprot->writeFieldBegin("batchUpdateCounts", ::apache::thrift::protocol::T_LIST, 3);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->batchUpdateCounts.size()));
      std::vector<int32_t> ::const_iterator _iter323;
      for (_iter323 = this->batchUpdateCounts.begin(); _iter323 != this->batchUpdateCounts.end(); ++_iter323)
      {
        xfer += oprot->writeI32((*_iter323));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.procedureOutParams) {
    xfer += oprot->writeFieldBegin("procedureOutParams", ::apache::thrift::protocol::T_MAP, 4);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->procedureOutParams.size()));
      std::map<int32_t, ColumnValue> ::const_iterator _iter324;
      for (_iter324 = this->procedureOutParams.begin(); _iter324 != this->procedureOutParams.end(); ++_iter324)
      {
        xfer += oprot->writeI32(_iter324->first);
        xfer += _iter324->second.write(oprot);
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.generatedKeys) {
    xfer += oprot->writeFieldBegin("generatedKeys", ::apache::thrift::protocol::T_STRUCT, 5);
    xfer += this->generatedKeys.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.warnings) {
    xfer += oprot->writeFieldBegin("warnings", ::apache::thrift::protocol::T_STRUCT, 6);
    xfer += this->warnings.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.preparedResult) {
    xfer += oprot->writeFieldBegin("preparedResult", ::apache::thrift::protocol::T_STRUCT, 7);
    xfer += this->preparedResult.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(StatementResult &a, StatementResult &b) noexcept {
  using ::std::swap;
  static_assert(noexcept(swap(a, b)), "throwing swap");
  swap(a.resultSet, b.resultSet);
  swap(a.updateCount, b.updateCount);
  swap(a.batchUpdateCounts, b.batchUpdateCounts);
  swap(a.procedureOutParams, b.procedureOutParams);
  swap(a.generatedKeys, b.generatedKeys);
  swap(a.warnings, b.warnings);
  swap(a.preparedResult, b.preparedResult);
  swap(a.__isset, b.__isset);
}

StatementResult::StatementResult(const StatementResult& other325) {
  resultSet = other325.resultSet;
  updateCount = other325.updateCount;
  batchUpdateCounts = other325.batchUpdateCounts;
  procedureOutParams = other325.procedureOutParams;
  generatedKeys = other325.generatedKeys;
  warnings = other325.warnings;
  preparedResult = other325.preparedResult;
  __isset = other325.__isset;
}
StatementResult::StatementResult( StatementResult&& other326) noexcept {
  resultSet = std::move(other326.resultSet);
  updateCount = std::move(other326.updateCount);
  batchUpdateCounts = std::move(other326.batchUpdateCounts);
  procedureOutParams = std::move(other326.procedureOutParams);
  generatedKeys = std::move(other326.generatedKeys);
  warnings = std::move(other326.warnings);
  preparedResult = std::move(other326.preparedResult);
  __isset = std::move(other326.__isset);
}
StatementResult& StatementResult::operator=(const StatementResult& other327) {
  resultSet = other327.resultSet;
  updateCount = other327.updateCount;
  batchUpdateCounts = other327.batchUpdateCounts;
  procedureOutParams = other327.procedureOutParams;
  generatedKeys = other327.generatedKeys;
  warnings = other327.warnings;
  preparedResult = other327.preparedResult;
  __isset = other327.__isset;
  return *this;
}
StatementResult& StatementResult::operator=(StatementResult&& other328) noexcept {
  resultSet = std::move(other328.resultSet);
  updateCount = std::move(other328.updateCount);
  batchUpdateCounts = std::move(other328.batchUpdateCounts);
  procedureOutParams = std::move(other328.procedureOutParams);
  generatedKeys = std::move(other328.generatedKeys);
  warnings = std::move(other328.warnings);
  preparedResult = std::move(other328.preparedResult);
  __isset = std::move(other328.__isset);
  return *this;
}
void StatementResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "StatementResult(";
  out << "resultSet="; (__isset.resultSet ? (out << to_string(resultSet)) : (out << "<null>"));
  out << ", " << "updateCount="; (__isset.updateCount ? (out << to_string(updateCount)) : (out << "<null>"));
  out << ", " << "batchUpdateCounts="; (__isset.batchUpdateCounts ? (out << to_string(batchUpdateCounts)) : (out << "<null>"));
  out << ", " << "procedureOutParams="; (__isset.procedureOutParams ? (out << to_string(procedureOutParams)) : (out << "<null>"));
  out << ", " << "generatedKeys="; (__isset.generatedKeys ? (out << to_string(generatedKeys)) : (out << "<null>"));
  out << ", " << "warnings="; (__isset.warnings ? (out << to_string(warnings)) : (out << "<null>"));
  out << ", " << "preparedResult="; (__isset.preparedResult ? (out << to_string(preparedResult)) : (out << "<null>"));
  out << ")";
}

}}} // namespace