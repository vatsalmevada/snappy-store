// This is just rehash of topology_5.inc. Instead of actual logical subgroups
// named of the subgroups have been set.

// PROPERTIES:
//      managed_1_Hosts         number of logical hosts in managed_1 group
//      managed_1_VMsPerHost    number of VMs per host in managed_1 group
//      managed_1_ThreadsPerVM  number of threads per VM in managed_1 group

//
//      managed_2_Hosts         number of logical hosts in managed_2 group
//      managed_2_VMsPerHost    number of VMs per host in managed_2 group
//      managed_2_ThreadsPerVM  number of threads per VM in managed_2 group

//      locator_managing_Hosts         number of logical hosts in locator_managing group
//      locator_managing_VMsPerHost    number of VMs per host in locator_managing group
//      locator_managing_ThreadsPerVM  number of threads per VM in locator_managing group

//      managing_1_Hosts         number of logical hosts in managing_1 group
//      managing_1_VMsPerHost    number of VMs per host in managing_1 group
//      managing_1_ThreadsPerVM  number of threads per VM in managing_1 group

//      edge_Hosts         number of logical hosts in managing_1 group
//      edge_VMsPerHost    number of VMs per host in managing_1 group
//      edge_ThreadsPerVM  number of threads per VM in managing_1 group


hydra.HostPrms-names = fcn "hydra.TestConfigFcns.generateNames
                            (\"managed_1_host\", ${managed_1_Hosts})"
                       ncf
                       fcn "hydra.TestConfigFcns.generateNames
                            (\"managed_2_host\", ${managed_2_Hosts})"
                       ncf
                       fcn "hydra.TestConfigFcns.generateNames
                            (\"locator_managing_host\", ${locator_managing_Hosts})"
                       ncf
                       fcn "hydra.TestConfigFcns.generateNames
                            (\"managing_1_host\", ${managing_1_Hosts})"
                       ncf
                       fcn "hydra.TestConfigFcns.generateNames
                            (\"edge_host\", ${edge_Hosts})"
                       ncf;
                       
hydra.VmPrms-names         = fcn "hydra.TestConfigFcns.generateNames
                                  (\"managed_1_vm\", ${managed_1_Hosts})"
                             ncf
                             fcn "hydra.TestConfigFcns.generateNames
                                  (\"managed_2_vm\", ${managed_2_Hosts})"
                             ncf
                             fcn "hydra.TestConfigFcns.generateNames
                                  (\"locator_managing_vm\", ${locator_managing_Hosts})"
                             ncf
                             fcn "hydra.TestConfigFcns.generateNames
                                  (\"managing_1_vm\", ${managing_1_Hosts})"
                             ncf
                             fcn "hydra.TestConfigFcns.generateNames
                                  (\"edge_vm\", ${edge_Hosts})"
                             ncf;
hydra.VmPrms-hostNames     = fcn "hydra.TestConfigFcns.generateNames
                                  (\"managed_1_host\", ${managed_1_Hosts})"
                             ncf
                             fcn "hydra.TestConfigFcns.generateNames
                                  (\"managed_2_host\", ${managed_2_Hosts})"
                             ncf
                             fcn "hydra.TestConfigFcns.generateNames
                                  (\"locator_managing_host\", ${locator_managing_Hosts})"
                             ncf
                             fcn "hydra.TestConfigFcns.generateNames
                                  (\"managing_1_host\", ${managing_1_Hosts})"
                             ncf
                             fcn "hydra.TestConfigFcns.generateNames
                                  (\"edge_host\", ${edge_Hosts})"
                             ncf;
                             
hydra.GemFirePrms-names     = fcn "hydra.TestConfigFcns.generateNames
                                   (\"managed_1_gemfire\", ${managed_1_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.generateNames
                                   (\"managed_2_gemfire\", ${managed_2_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.generateNames
                                   (\"locator_managing_gemfire\", ${locator_managing_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.generateNames
                                   (\"managing_1_gemfire\", ${managing_1_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.generateNames
                                  (\"edge_gemfire\", ${edge_Hosts})"
                              ncf;
hydra.GemFirePrms-hostNames = fcn "hydra.TestConfigFcns.generateNames
                                   (\"managed_1_host\", ${managed_1_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.generateNames
                                   (\"managed_2_host\", ${managed_2_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.generateNames
                                   (\"locator_managing_host\", ${locator_managing_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.generateNames
                                   (\"managing_1_host\", ${managing_1_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.generateNames
                                  (\"edge_host\", ${edge_Hosts})"
                              ncf;
                              
hydra.GemFirePrms-jmxManager =  fcn "hydra.TestConfigFcns.duplicate
                                     (\"false\", ${managed_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"false\", ${managed_2_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"true\", ${locator_managing_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"true\", ${managing_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"false\",  ${edge_Hosts})"
                              	ncf;
                                
hydra.GemFirePrms-jmxManagerPort =  fcn "hydra.TestConfigFcns.duplicate
                                     (\"false\", ${managed_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"false\", ${managed_2_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"true\", ${locator_managing_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"true\", ${managing_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"false\",  ${edge_Hosts})"
                              	ncf;
                                
hydra.GemFirePrms-jmxManagerStart = fcn "hydra.TestConfigFcns.duplicate
                                     (\"false\", ${managed_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"false\", ${managed_2_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"true\", ${locator_managing_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"true\", ${managing_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"false\",  ${edge_Hosts})"
                              	ncf;                              
                              
hydra.GemFirePrms-distributedSystem = fcn "hydra.TestConfigFcns.duplicate
                                   (\"bridgeds\", ${managed_1_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.duplicate
                                   (\"bridgeds\",  ${managed_2_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.duplicate
                                   (\"bridgeds\",  ${locator_managing_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.duplicate
                                   (\"bridgeds\",  ${managing_1_Hosts})"
                              ncf
                              fcn "hydra.TestConfigFcns.duplicate
                                   (\"loner\",  ${edge_Hosts})"
                              ncf;                                                            
                              
hydra.ClientPrms-names        = fcn "hydra.TestConfigFcns.generateNames
                                     (\"managed_1\", ${managed_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"managed_2\", ${managed_2_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"locator_managing\", ${locator_managing_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"managing_1\", ${managing_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"edge\", ${edge_Hosts})"
                                ncf;                                
                                                                ;
hydra.ClientPrms-vmNames      = fcn "hydra.TestConfigFcns.generateNames
                                     (\"managed_1_vm\", ${managed_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"managed_2_vm\", ${managed_2_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"locator_managing_vm\", ${locator_managing_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"managing_1_vm\", ${managing_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"edge_vm\", ${edge_Hosts})"
                                ncf;
hydra.ClientPrms-gemfireNames = fcn "hydra.TestConfigFcns.generateNames
                                     (\"managed_1_gemfire\", ${managed_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"managed_2_gemfire\", ${managed_2_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"locator_managing_gemfire\", ${locator_managing_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"managing_1_gemfire\", ${managing_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.generateNames
                                     (\"edge_gemfire\", ${edge_Hosts})"
                                ncf;
hydra.ClientPrms-vmQuantities = fcn "hydra.TestConfigFcns.duplicate
                                     (\"${managed_1_VMsPerHost}\", ${managed_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"${managed_2_VMsPerHost}\", ${managed_2_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"${locator_managing_VMsPerHost}\", ${locator_managing_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"${managing_1_VMsPerHost}\", ${managing_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"${edge_VMsPerHost}\", ${edge_Hosts})"
                                ncf;
hydra.ClientPrms-vmThreads    = fcn "hydra.TestConfigFcns.duplicate
                                     (\"${managed_1_ThreadsPerVM}\", ${managed_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"${managed_2_ThreadsPerVM}\", ${managed_2_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"${locator_managing_ThreadsPerVM}\", ${locator_managing_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"${managing_1_ThreadsPerVM}\", ${managing_1_Hosts})"
                                ncf
                                fcn "hydra.TestConfigFcns.duplicate
                                     (\"${edge_ThreadsPerVM}\", ${edge_Hosts})"
                                ncf;
                                
hydra.Prms-manageLocatorAgents=false;                                