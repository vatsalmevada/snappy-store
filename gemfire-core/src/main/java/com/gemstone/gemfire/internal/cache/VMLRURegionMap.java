/*
 * Copyright (c) 2010-2015 Pivotal Software, Inc. All rights reserved.
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

package com.gemstone.gemfire.internal.cache;

import com.gemstone.gemfire.internal.cache.lru.*;
//import com.gemstone.gemfire.internal.util.Sizeof;

/**
 * Internal implementation of {@link RegionMap} for regions stored
 * in normal VM memory that maintain an LRU.
 *
 * @since 3.5.1
 *
 * @author Darrel Schneider
 *
 */
final class VMLRURegionMap extends AbstractLRURegionMap {

  VMLRURegionMap(Object owner, Attributes attr,
      InternalRegionArguments internalRegionArgs) {
    super(internalRegionArgs);
    initialize(owner, attr, internalRegionArgs);
  }

  // LRU fields and accessors
  /**
   *  A tool from the eviction controller for sizing entries and
   *  expressing limits.
   */
  private EnableLRU ccHelper;
  /**  The list of nodes in LRU order */
  private NewLRUClockHand lruList;

  @Override
  protected final void _setCCHelper(EnableLRU ccHelper) {
    this.ccHelper = ccHelper;
  }
  @Override
  protected final EnableLRU _getCCHelper() {
    return this.ccHelper;
  }
  @Override
  protected final void _setLruList(NewLRUClockHand lruList) {
    this.lruList = lruList;
  }
  @Override
  public final NewLRUClockHand _getLruList() {
    return this.lruList;
  }
}
