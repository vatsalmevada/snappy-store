/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
/*
 * Changes for GemFireXD distributed data platform.
 *
 * Portions Copyright (c) 2010-2015 Pivotal Software, Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You
 * may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * permissions and limitations under the License. See accompanying
 * LICENSE file.
 */
/*
 * Changes for TIBCO Project SnappyData data platform.
 *
 * Portions Copyright (c) 2017-2019 TIBCO Software Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You
 * may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * permissions and limitations under the License. See accompanying
 * LICENSE file.
 */

package io.snappydata.thrift;

import com.gemstone.gemfire.internal.shared.HostLocationBase;
import org.apache.thrift.scheme.IScheme;
import org.apache.thrift.scheme.SchemeFactory;
import org.apache.thrift.scheme.StandardScheme;

import org.apache.thrift.scheme.TupleScheme;
import org.apache.thrift.protocol.TTupleProtocol;
import org.apache.thrift.protocol.TProtocolException;
import org.apache.thrift.EncodingUtils;
import org.apache.thrift.TException;
import org.apache.thrift.async.AsyncMethodCallback;
import org.apache.thrift.server.AbstractNonblockingServer.*;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.EnumMap;
import java.util.Set;
import java.util.HashSet;
import java.util.EnumSet;
import java.util.Collections;
import java.util.BitSet;
import java.nio.ByteBuffer;
import java.util.Arrays;
import javax.annotation.Generated;

import org.apache.thrift.transport.TTransportException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

@SuppressWarnings({"cast", "rawtypes", "serial", "unchecked"})
@Generated(value = "Autogenerated by Thrift Compiler (0.9.3)", date = "2019-08-09")
public class HostAddress extends HostLocationBase<HostAddress>
    implements org.apache.thrift.TBase<HostAddress, HostAddress._Fields>, java.io.Serializable, Cloneable, Comparable<HostAddress> {
  private static final org.apache.thrift.protocol.TStruct STRUCT_DESC = new org.apache.thrift.protocol.TStruct("HostAddress");

  private static final org.apache.thrift.protocol.TField HOST_NAME_FIELD_DESC = new org.apache.thrift.protocol.TField("hostName", org.apache.thrift.protocol.TType.STRING, (short)1);
  private static final org.apache.thrift.protocol.TField PORT_FIELD_DESC = new org.apache.thrift.protocol.TField("port", org.apache.thrift.protocol.TType.I32, (short)2);
  private static final org.apache.thrift.protocol.TField IP_ADDRESS_FIELD_DESC = new org.apache.thrift.protocol.TField("ipAddress", org.apache.thrift.protocol.TType.STRING, (short)3);
  private static final org.apache.thrift.protocol.TField SERVER_TYPE_FIELD_DESC = new org.apache.thrift.protocol.TField("serverType", org.apache.thrift.protocol.TType.I32, (short)4);
  private static final org.apache.thrift.protocol.TField IS_CURRENT_FIELD_DESC = new org.apache.thrift.protocol.TField("isCurrent", org.apache.thrift.protocol.TType.BOOL, (short)5);

  private static final SchemeFactory STANDARD_SCHEME_FACTORY =
      new HostAddressStandardSchemeFactory();
  private static final SchemeFactory TUPLE_SCHEME_FACTORY =
      new HostAddressTupleSchemeFactory();

  protected String ipAddress; // optional
  /**
   * 
   * @see ServerType
   */
  protected ServerType serverType; // optional
  protected boolean isCurrent; // optional

  public static final HostAddress NULL_ADDRESS = new HostAddress("", -1);

  /** The set of fields this struct contains, along with convenience methods for finding and manipulating them. */
  public enum _Fields implements org.apache.thrift.TFieldIdEnum {
    HOST_NAME((short)1, "hostName"),
    PORT((short)2, "port"),
    IP_ADDRESS((short)3, "ipAddress"),
    /**
     * 
     * @see ServerType
     */
    SERVER_TYPE((short)4, "serverType"),
    IS_CURRENT((short)5, "isCurrent");

    private static final Map<String, _Fields> byName = new HashMap<String, _Fields>();

    static {
      for (_Fields field : EnumSet.allOf(_Fields.class)) {
        byName.put(field.getFieldName(), field);
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, or null if its not found.
     */
    public static _Fields findByThriftId(int fieldId) {
      switch(fieldId) {
        case 1: // HOST_NAME
          return HOST_NAME;
        case 2: // PORT
          return PORT;
        case 3: // IP_ADDRESS
          return IP_ADDRESS;
        case 4: // SERVER_TYPE
          return SERVER_TYPE;
        case 5: // IS_CURRENT
          return IS_CURRENT;
        default:
          return null;
      }
    }

    /**
     * Find the _Fields constant that matches fieldId, throwing an exception
     * if it is not found.
     */
    public static _Fields findByThriftIdOrThrow(int fieldId) {
      _Fields fields = findByThriftId(fieldId);
      if (fields == null) throw new IllegalArgumentException("Field " + fieldId + " doesn't exist!");
      return fields;
    }

    /**
     * Find the _Fields constant that matches name, or null if its not found.
     */
    public static _Fields findByName(String name) {
      return byName.get(name);
    }

    private final short _thriftId;
    private final String _fieldName;

    _Fields(short thriftId, String fieldName) {
      _thriftId = thriftId;
      _fieldName = fieldName;
    }

    public short getThriftFieldId() {
      return _thriftId;
    }

    public String getFieldName() {
      return _fieldName;
    }
  }

  // isset id assignments
  private static final int __PORT_ISSET_ID = 0;
  private static final int __ISCURRENT_ISSET_ID = 1;
  private byte __isset_bitfield = 0;
  private static final _Fields optionals[] = {_Fields.IP_ADDRESS,_Fields.SERVER_TYPE,_Fields.IS_CURRENT};
  public static final Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> metaDataMap;
  static {
    Map<_Fields, org.apache.thrift.meta_data.FieldMetaData> tmpMap = new EnumMap<_Fields, org.apache.thrift.meta_data.FieldMetaData>(_Fields.class);
    tmpMap.put(_Fields.HOST_NAME, new org.apache.thrift.meta_data.FieldMetaData("hostName", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.PORT, new org.apache.thrift.meta_data.FieldMetaData("port", org.apache.thrift.TFieldRequirementType.REQUIRED, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.I32)));
    tmpMap.put(_Fields.IP_ADDRESS, new org.apache.thrift.meta_data.FieldMetaData("ipAddress", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.STRING)));
    tmpMap.put(_Fields.SERVER_TYPE, new org.apache.thrift.meta_data.FieldMetaData("serverType", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.EnumMetaData(org.apache.thrift.protocol.TType.ENUM, ServerType.class)));
    tmpMap.put(_Fields.IS_CURRENT, new org.apache.thrift.meta_data.FieldMetaData("isCurrent", org.apache.thrift.TFieldRequirementType.OPTIONAL, 
        new org.apache.thrift.meta_data.FieldValueMetaData(org.apache.thrift.protocol.TType.BOOL)));
    metaDataMap = Collections.unmodifiableMap(tmpMap);
    org.apache.thrift.meta_data.FieldMetaData.addStructMetaDataMap(HostAddress.class, metaDataMap);
  }

  public HostAddress() {
  }

  public HostAddress(
    String hostName,
    int port)
  {
    super(hostName, port);
    setPortIsSet(true);
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public HostAddress(HostAddress other) {
    __isset_bitfield = other.__isset_bitfield;
    if (other.isSetHostName()) {
      this.hostName = other.hostName;
    }
    this.port = other.port;
    if (other.isSetIpAddress()) {
      this.ipAddress = other.ipAddress;
    }
    if (other.isSetServerType()) {
      this.serverType = other.serverType;
    }
    this.isCurrent = other.isCurrent;
  }

  public InetAddress resolveHost() throws TTransportException {
    // TODO: SW: JDK's InetAddress has an inbuilt cache but it is no good
    // and does not honour DNS TTL etc. Custom DNSCacheService should be
    // added for better behaviour.

    // InetAddress addr = DNSCacheService.getInstance().lookupCache(hostName);
    try {
      return InetAddress.getByName(this.hostName);
    } catch (UnknownHostException uhe) {
      // use ipAddress if available
      if (this.ipAddress != null) {
        try {
          return InetAddress.getByName(this.ipAddress);
        } catch (UnknownHostException e) {
          throw new TTransportException(e);
        }
      }
      else {
        throw new TTransportException(uhe);
      }
    }
  }

  @Override
  public HostAddress deepCopy() {
    return new HostAddress(this);
  }

  @Override
  public void clear() {
    this.hostName = null;
    setPortIsSet(false);
    this.port = 0;
    this.ipAddress = null;
    this.serverType = null;
    setIsCurrentIsSet(false);
    this.isCurrent = false;
  }

  public HostAddress setHostName(String hostName) {
    this.hostName = hostName;
    return this;
  }

  public void unsetHostName() {
    this.hostName = null;
  }

  /** Returns true if field hostName is set (has been assigned a value) and false otherwise */
  public boolean isSetHostName() {
    return this.hostName != null;
  }

  public void setHostNameIsSet(boolean value) {
    if (!value) {
      this.hostName = null;
    }
  }

  public HostAddress setPort(int port) {
    this.port = port;
    setPortIsSet(true);
    return this;
  }

  public void unsetPort() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __PORT_ISSET_ID);
  }

  /** Returns true if field port is set (has been assigned a value) and false otherwise */
  public boolean isSetPort() {
    return EncodingUtils.testBit(__isset_bitfield, __PORT_ISSET_ID);
  }

  public void setPortIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __PORT_ISSET_ID, value);
  }

  public String getIpAddress() {
    return this.ipAddress;
  }

  public HostAddress setIpAddress(String ipAddress) {
    this.ipAddress = ipAddress;
    return this;
  }

  public void unsetIpAddress() {
    this.ipAddress = null;
  }

  /** Returns true if field ipAddress is set (has been assigned a value) and false otherwise */
  public boolean isSetIpAddress() {
    return this.ipAddress != null;
  }

  public void setIpAddressIsSet(boolean value) {
    if (!value) {
      this.ipAddress = null;
    }
  }

  /**
   * 
   * @see ServerType
   */
  public ServerType getServerType() {
    return this.serverType;
  }

  /**
   * 
   * @see ServerType
   */
  public HostAddress setServerType(ServerType serverType) {
    this.serverType = serverType;
    return this;
  }

  public void unsetServerType() {
    this.serverType = null;
  }

  /** Returns true if field serverType is set (has been assigned a value) and false otherwise */
  public boolean isSetServerType() {
    return this.serverType != null;
  }

  public void setServerTypeIsSet(boolean value) {
    if (!value) {
      this.serverType = null;
    }
  }

  public boolean isIsCurrent() {
    return this.isCurrent;
  }

  public HostAddress setIsCurrent(boolean isCurrent) {
    this.isCurrent = isCurrent;
    setIsCurrentIsSet(true);
    return this;
  }

  public void unsetIsCurrent() {
    __isset_bitfield = EncodingUtils.clearBit(__isset_bitfield, __ISCURRENT_ISSET_ID);
  }

  /** Returns true if field isCurrent is set (has been assigned a value) and false otherwise */
  public boolean isSetIsCurrent() {
    return EncodingUtils.testBit(__isset_bitfield, __ISCURRENT_ISSET_ID);
  }

  public void setIsCurrentIsSet(boolean value) {
    __isset_bitfield = EncodingUtils.setBit(__isset_bitfield, __ISCURRENT_ISSET_ID, value);
  }

  public void setFieldValue(_Fields field, Object value) {
    switch (field) {
    case HOST_NAME:
      if (value == null) {
        unsetHostName();
      } else {
        setHostName((String)value);
      }
      break;

    case PORT:
      if (value == null) {
        unsetPort();
      } else {
        setPort((Integer)value);
      }
      break;

    case IP_ADDRESS:
      if (value == null) {
        unsetIpAddress();
      } else {
        setIpAddress((String)value);
      }
      break;

    case SERVER_TYPE:
      if (value == null) {
        unsetServerType();
      } else {
        setServerType((ServerType)value);
      }
      break;

    case IS_CURRENT:
      if (value == null) {
        unsetIsCurrent();
      } else {
        setIsCurrent((Boolean)value);
      }
      break;

    }
  }

  public Object getFieldValue(_Fields field) {
    switch (field) {
    case HOST_NAME:
      return getHostName();

    case PORT:
      return getPort();

    case IP_ADDRESS:
      return getIpAddress();

    case SERVER_TYPE:
      return getServerType();

    case IS_CURRENT:
      return isIsCurrent();

    }
    throw new IllegalStateException();
  }

  /** Returns true if field corresponding to fieldID is set (has been assigned a value) and false otherwise */
  public boolean isSet(_Fields field) {
    if (field == null) {
      throw new IllegalArgumentException();
    }

    switch (field) {
    case HOST_NAME:
      return isSetHostName();
    case PORT:
      return isSetPort();
    case IP_ADDRESS:
      return isSetIpAddress();
    case SERVER_TYPE:
      return isSetServerType();
    case IS_CURRENT:
      return isSetIsCurrent();
    }
    throw new IllegalStateException();
  }

  @Override
  public final boolean equals(final HostLocationBase<?> other) {
    if (this == other) {
      return true;
    }
    if (port != other.getPort()) {
      return false;
    }
    if (other instanceof HostAddress) {
      final HostAddress otherAddr = (HostAddress)other;
      if (super.equalsHostName(otherAddr)) {
        // compare the IP addresses if set
        // assume null IP address means some problem in resolving IP address
        // and so ignore its comparison (assuming true as per hostName
        // comparison)
        return this.ipAddress == null || otherAddr.ipAddress == null
            || this.ipAddress.equals(otherAddr.ipAddress);
      }
      // hostname of one may be IP address of other
      else if (this.ipAddress != null) {
        return this.ipAddress.equals(otherAddr.hostName);
      }
      else if (otherAddr.ipAddress != null) {
        return otherAddr.ipAddress.equals(this.hostName);
      }
      else {
        return false;
      }
    }
    else {
      return super.equalsHostName(other);
    }
  }

  @Override
  public int compareTo(HostAddress other) {
    if (!equals(other)) {
      return super.compareTo(other);
    }
    else {
      return 0;
    }
  }

  public _Fields fieldForId(int fieldId) {
    return _Fields.findByThriftId(fieldId);
  }

  public void read(org.apache.thrift.protocol.TProtocol iprot) throws org.apache.thrift.TException {
    scheme(iprot).read(iprot, this);
  }

  public void write(org.apache.thrift.protocol.TProtocol oprot) throws org.apache.thrift.TException {
    scheme(oprot).write(oprot, this);
  }

  public String getHostString() {
    return super.toString();
  }

  public String getHostAddressString() {
    if (this.ipAddress == null) {
      return this.hostName + '[' + this.port + ']';
    } else {
      return this.hostName + '/' + this.ipAddress + '[' + this.port + ']';
    }
  }

  @Override
  public String toString() {
    ServerType serverType = this.serverType;
    if (serverType != null && serverType.isThriftWithDefaults()) {
      serverType = null;
    }
    if (this.ipAddress == null) {
      if (serverType == null) {
        return super.toString();
      }
      else {
        return this.hostName + '[' + this.port + "]{" + serverType.toString()
            + '}';
      }
    }
    else if (serverType == null) {
      return this.hostName + '/' + this.ipAddress + '[' + this.port + ']';
    }
    else {
      return this.hostName + '/' + this.ipAddress + '[' + this.port + "]{"
          + serverType.toString() + '}';
    }
  }

  public void validate() throws org.apache.thrift.TException {
    // check for required fields
    if (hostName == null) {
      throw new org.apache.thrift.protocol.TProtocolException("Required field 'hostName' was not present! Struct: " + toString());
    }
    // alas, we cannot check 'port' because it's a primitive and you chose the non-beans generator.
    // check for sub-struct validity
  }

  private void writeObject(java.io.ObjectOutputStream out) throws java.io.IOException {
    try {
      write(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(out)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private void readObject(java.io.ObjectInputStream in) throws java.io.IOException, ClassNotFoundException {
    try {
      // it doesn't seem like you should have to do this, but java serialization is wacky, and doesn't call the default constructor.
      __isset_bitfield = 0;
      read(new org.apache.thrift.protocol.TCompactProtocol(new org.apache.thrift.transport.TIOStreamTransport(in)));
    } catch (org.apache.thrift.TException te) {
      throw new java.io.IOException(te);
    }
  }

  private static class HostAddressStandardSchemeFactory implements SchemeFactory {
    public HostAddressStandardScheme getScheme() {
      return new HostAddressStandardScheme();
    }
  }

  private static class HostAddressStandardScheme extends StandardScheme<HostAddress> {

    public void read(org.apache.thrift.protocol.TProtocol iprot, HostAddress struct) throws org.apache.thrift.TException {
      org.apache.thrift.protocol.TField schemeField;
      iprot.readStructBegin();
      while (true)
      {
        schemeField = iprot.readFieldBegin();
        if (schemeField.type == org.apache.thrift.protocol.TType.STOP) { 
          break;
        }
        switch (schemeField.id) {
          case 1: // HOST_NAME
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.hostName = iprot.readString();
              struct.setHostNameIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 2: // PORT
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.port = iprot.readI32();
              struct.setPortIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 3: // IP_ADDRESS
            if (schemeField.type == org.apache.thrift.protocol.TType.STRING) {
              struct.ipAddress = iprot.readString();
              struct.setIpAddressIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 4: // SERVER_TYPE
            if (schemeField.type == org.apache.thrift.protocol.TType.I32) {
              struct.serverType = io.snappydata.thrift.ServerType.findByValue(iprot.readI32());
              struct.setServerTypeIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          case 5: // IS_CURRENT
            if (schemeField.type == org.apache.thrift.protocol.TType.BOOL) {
              struct.isCurrent = iprot.readBool();
              struct.setIsCurrentIsSet(true);
            } else { 
              org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
            }
            break;
          default:
            org.apache.thrift.protocol.TProtocolUtil.skip(iprot, schemeField.type);
        }
        iprot.readFieldEnd();
      }
      iprot.readStructEnd();

      // check for required fields of primitive type, which can't be checked in the validate method
      if (!struct.isSetPort()) {
        throw new org.apache.thrift.protocol.TProtocolException("Required field 'port' was not found in serialized data! Struct: " + toString());
      }
      struct.validate();
    }

    public void write(org.apache.thrift.protocol.TProtocol oprot, HostAddress struct) throws org.apache.thrift.TException {
      struct.validate();

      oprot.writeStructBegin(STRUCT_DESC);
      if (struct.hostName != null) {
        oprot.writeFieldBegin(HOST_NAME_FIELD_DESC);
        oprot.writeString(struct.hostName);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldBegin(PORT_FIELD_DESC);
      oprot.writeI32(struct.port);
      oprot.writeFieldEnd();
      if (struct.ipAddress != null) {
        if (struct.isSetIpAddress()) {
          oprot.writeFieldBegin(IP_ADDRESS_FIELD_DESC);
          oprot.writeString(struct.ipAddress);
          oprot.writeFieldEnd();
        }
      }
      if (struct.serverType != null) {
        if (struct.isSetServerType()) {
          oprot.writeFieldBegin(SERVER_TYPE_FIELD_DESC);
          oprot.writeI32(struct.serverType.getValue());
          oprot.writeFieldEnd();
        }
      }
      if (struct.isSetIsCurrent()) {
        oprot.writeFieldBegin(IS_CURRENT_FIELD_DESC);
        oprot.writeBool(struct.isCurrent);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }

  }

  private static class HostAddressTupleSchemeFactory implements SchemeFactory {
    public HostAddressTupleScheme getScheme() {
      return new HostAddressTupleScheme();
    }
  }

  private static class HostAddressTupleScheme extends TupleScheme<HostAddress> {

    @Override
    public void write(org.apache.thrift.protocol.TProtocol prot, HostAddress struct) throws org.apache.thrift.TException {
      TTupleProtocol oprot = (TTupleProtocol) prot;
      oprot.writeString(struct.hostName);
      oprot.writeI32(struct.port);
      BitSet optionals = new BitSet();
      if (struct.isSetIpAddress()) {
        optionals.set(0);
      }
      if (struct.isSetServerType()) {
        optionals.set(1);
      }
      if (struct.isSetIsCurrent()) {
        optionals.set(2);
      }
      oprot.writeBitSet(optionals, 3);
      if (struct.isSetIpAddress()) {
        oprot.writeString(struct.ipAddress);
      }
      if (struct.isSetServerType()) {
        oprot.writeI32(struct.serverType.getValue());
      }
      if (struct.isSetIsCurrent()) {
        oprot.writeBool(struct.isCurrent);
      }
    }

    @Override
    public void read(org.apache.thrift.protocol.TProtocol prot, HostAddress struct) throws org.apache.thrift.TException {
      TTupleProtocol iprot = (TTupleProtocol) prot;
      struct.hostName = iprot.readString();
      struct.setHostNameIsSet(true);
      struct.port = iprot.readI32();
      struct.setPortIsSet(true);
      BitSet incoming = iprot.readBitSet(3);
      if (incoming.get(0)) {
        struct.ipAddress = iprot.readString();
        struct.setIpAddressIsSet(true);
      }
      if (incoming.get(1)) {
        struct.serverType = io.snappydata.thrift.ServerType.findByValue(iprot.readI32());
        struct.setServerTypeIsSet(true);
      }
      if (incoming.get(2)) {
        struct.isCurrent = iprot.readBool();
        struct.setIsCurrentIsSet(true);
      }
    }
  }

  private static <S extends IScheme> S scheme(
      org.apache.thrift.protocol.TProtocol proto) {
    return (StandardScheme.class.equals(proto.getScheme())
        ? STANDARD_SCHEME_FACTORY : TUPLE_SCHEME_FACTORY).getScheme();
  }
}
