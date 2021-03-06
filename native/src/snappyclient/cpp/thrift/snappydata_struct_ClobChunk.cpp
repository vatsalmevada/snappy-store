/**
 * Autogenerated by Thrift Compiler (0.10.0)
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
#include "snappydata_struct_ClobChunk.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace io { namespace snappydata { namespace thrift {


ClobChunk::~ClobChunk() noexcept {
}


void ClobChunk::__set_chunk(const std::string& val) {
  this->chunk = val;
}

void ClobChunk::__set_last(const bool val) {
  this->last = val;
}

void ClobChunk::__set_lobId(const int64_t val) {
  this->lobId = val;
__isset.lobId = true;
}

void ClobChunk::__set_offset(const int64_t val) {
  this->offset = val;
__isset.offset = true;
}

void ClobChunk::__set_totalLength(const int64_t val) {
  this->totalLength = val;
__isset.totalLength = true;
}

uint32_t ClobChunk::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_chunk = false;
  bool isset_last = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->chunk);
          isset_chunk = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->last);
          isset_last = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->lobId);
          this->__isset.lobId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->offset);
          this->__isset.offset = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->totalLength);
          this->__isset.totalLength = true;
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

  if (!isset_chunk)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_last)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t ClobChunk::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("ClobChunk");

  xfer += oprot->writeFieldBegin("chunk", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->chunk);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("last", ::apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool(this->last);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.lobId) {
    xfer += oprot->writeFieldBegin("lobId", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->lobId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.offset) {
    xfer += oprot->writeFieldBegin("offset", ::apache::thrift::protocol::T_I64, 4);
    xfer += oprot->writeI64(this->offset);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.totalLength) {
    xfer += oprot->writeFieldBegin("totalLength", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->totalLength);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ClobChunk &a, ClobChunk &b) {
  using ::std::swap;
  swap(a.chunk, b.chunk);
  swap(a.last, b.last);
  swap(a.lobId, b.lobId);
  swap(a.offset, b.offset);
  swap(a.totalLength, b.totalLength);
  swap(a.__isset, b.__isset);
}

ClobChunk::ClobChunk(const ClobChunk& other8) {
  chunk = other8.chunk;
  last = other8.last;
  lobId = other8.lobId;
  offset = other8.offset;
  totalLength = other8.totalLength;
  __isset = other8.__isset;
}
ClobChunk::ClobChunk( ClobChunk&& other9) noexcept {
  chunk = std::move(other9.chunk);
  last = std::move(other9.last);
  lobId = std::move(other9.lobId);
  offset = std::move(other9.offset);
  totalLength = std::move(other9.totalLength);
  __isset = std::move(other9.__isset);
}
ClobChunk& ClobChunk::operator=(const ClobChunk& other10) {
  chunk = other10.chunk;
  last = other10.last;
  lobId = other10.lobId;
  offset = other10.offset;
  totalLength = other10.totalLength;
  __isset = other10.__isset;
  return *this;
}
ClobChunk& ClobChunk::operator=(ClobChunk&& other11) noexcept {
  chunk = std::move(other11.chunk);
  last = std::move(other11.last);
  lobId = std::move(other11.lobId);
  offset = std::move(other11.offset);
  totalLength = std::move(other11.totalLength);
  __isset = std::move(other11.__isset);
  return *this;
}
void ClobChunk::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ClobChunk(";
  out << "chunk=" << to_string(chunk);
  out << ", " << "last=" << to_string(last);
  out << ", " << "lobId="; (__isset.lobId ? (out << to_string(lobId)) : (out << "<null>"));
  out << ", " << "offset="; (__isset.offset ? (out << to_string(offset)) : (out << "<null>"));
  out << ", " << "totalLength="; (__isset.totalLength ? (out << to_string(totalLength)) : (out << "<null>"));
  out << ")";
}

}}} // namespace
