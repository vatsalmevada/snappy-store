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

import java.util.Properties;

import junit.framework.Assert;

import com.gemstone.gemfire.cache.PartitionAttributesFactory;
import com.gemstone.gemfire.cache.CacheLoader;
import com.gemstone.gemfire.cache.CacheLoaderException;
import com.gemstone.gemfire.cache.LoaderHelper;
import com.gemstone.gemfire.cache.Declarable;

/**
 * @author gthombar
 * This class is cacheLoader for the partition region
 */
public class PartitionedRegionCacheLoaderForSubRegion implements CacheLoader, Declarable {

	public Object load(LoaderHelper helper) throws CacheLoaderException {

		/* checking the attributes set in xml file */
		PartitionedRegion pr = (PartitionedRegion) helper.getRegion();
		if (pr.getAttributes().getPartitionAttributes().getRedundantCopies() != 1)
			Assert
					.fail("Redundancy of the partition region is not 1");
		
		Assert.assertEquals(pr.getAttributes()
				.getPartitionAttributes().getGlobalProperties().getProperty(
						PartitionAttributesFactory.GLOBAL_MAX_BUCKETS_PROPERTY),
				"11");
		Assert.assertEquals(pr.getAttributes()
				.getPartitionAttributes().getLocalMaxMemory(), 200);
		/*
		 * Returning the same key. This is to check CaccheLoader is invoked or
		 * not
		 */
		return helper.getKey();

	}

	public void close() {

	}

	public void init(Properties props) {

	}

}
