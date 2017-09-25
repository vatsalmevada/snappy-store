/*
 * Copyright (c) 2017 SnappyData, Inc. All rights reserved.
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

package com.pivotal.gemfirexd.internal.snappy;

import java.util.HashSet;
import java.util.Iterator;

import com.gemstone.gemfire.distributed.internal.membership.InternalDistributedMember;
import com.gemstone.gemfire.internal.ByteArrayDataInput;
import com.gemstone.gemfire.internal.shared.Version;
import com.pivotal.gemfirexd.internal.iapi.sql.ParameterValueSet;
import com.pivotal.gemfirexd.internal.iapi.types.DataValueDescriptor;
import com.pivotal.gemfirexd.internal.impl.sql.execute.ValueRow;

/**
 * Callbacks that are required for cluster management of Snappy should go here.
 */
public interface ClusterCallbacks {

  HashSet<String> getLeaderGroup();

  void launchExecutor(String driver_url, InternalDistributedMember driverDM);

  String getDriverURL();

  void stopExecutor();

  SparkSQLExecute getSQLExecute(String sql, String schema, LeadNodeExecutionContext ctx,
      Version v, boolean isPreparedStatement, boolean isPreparedPhase, ParameterValueSet pvs);

  Object readDataType(ByteArrayDataInput in);

  /**
   * Deserialize/decompress the SnappyResultHolder data and get an iterator.
   */
  Iterator<ValueRow> getRowIterator(DataValueDescriptor[] dvds, int[] types,
      int[] precisions, int[] scales, Object[] dataTypes, ByteArrayDataInput in);

  void clearSnappySessionForConnection(Long connectionId);

  void publishColumnTableStats();

  String getClusterType();
}
