/**
 * Copyright (C) 2016,  Netronome Systems, Inc.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @file          link_ctrl.h
 * @brief         Code for configuring the Ethernet link.
 */


#ifndef _LINK_CTRL_H_
#define _LINK_CTRL_H_


#include <nfp.h>
#include <stdint.h>


/* *** MAC RX Enable/Disable Functions *** */

/**
 * Check if the MAC RX is enabled for a given port.
 *
 * @param mac_isl        MAC island to query
 * @param mac_core       MAC core to query
 * @param mac_core_port  MAC core port to check
 *
 * @return 0 = disabled, 1 = enabled
 */
__intrinsic int mac_eth_check_rx_enable(unsigned int mac_isl,
                                        unsigned int mac_core,
                                        unsigned int mac_core_port);

/**
 * Disable the MAC RX for a given port.
 *
 * @param mac_isl        MAC island to configure
 * @param mac_core       MAC core to configure
 * @param mac_core_port  MAC core port to disable
 * @param num_lanes      Number of lanes associated with the port
 *
 * @note This function is not safe for multi-threaded use.
 */
__intrinsic void mac_eth_disable_rx(unsigned int mac_isl,
                                    unsigned int mac_core,
                                    unsigned int mac_core_port,
                                    unsigned int num_lanes);

/**
 * Enable the MAC RX for a given port.
 *
 * @param mac_isl        MAC island to configure
 * @param mac_core       MAC core to configure
 * @param mac_core_port  MAC core port to enable
 *
 * @note This function is not safe for multi-threaded use.
 */
__intrinsic void mac_eth_enable_rx(unsigned int mac_isl, unsigned int mac_core,
                                   unsigned int mac_core_port);


/* *** MAC TX Flush Enable/Disable Functions *** */

/**
 * Check if the MAC TX flush is enabled for a given port.
 *
 * @param mac_isl        MAC island to query
 * @param mac_core       MAC core to query
 * @param mac_core_port  MAC core port to check
 *
 * @return 0 = disabled, 1 = enabled
 */
__intrinsic int mac_eth_check_tx_flush_enable(unsigned int mac_isl,
                                              unsigned int mac_core,
                                              unsigned int mac_core_port);

/**
 * Disable the MAC TX flush for a given port.
 *
 * @param mac_isl        MAC island to configure
 * @param mac_core       MAC core to configure
 * @param mac_core_port  MAC core port to disable TX flush
 *
 * @note This function is not safe for multi-threaded use.
 */
__intrinsic void mac_eth_disable_tx_flush(unsigned int mac_isl,
                                          unsigned int mac_core,
                                          unsigned int mac_core_port);

/**
 * Enable the MAC TX flush for a given port.
 *
 * @param mac_isl        MAC island to configure
 * @param mac_core       MAC core to configure
 * @param mac_core_port  MAC core port to enable TX flush
 *
 * @note This function is not safe for multi-threaded use.
 */
__intrinsic void mac_eth_enable_tx_flush(unsigned int mac_isl,
                                         unsigned int mac_core,
                                         unsigned int mac_core_port);


/* *** NBI TM Queue Enable/Disable Functions *** */

/**
 * Disable the NBI TM queue.
 *
 * @param nbi_isl  NBI island to configure
 * @param tm_q     NBI TM queue to disable
 *
 * @note This function is not safe for multi-threaded use.
 */
__intrinsic void nbi_tm_disable_queue(unsigned int nbi_isl, unsigned int tm_q);

/**
 * Enable the NBI TM queue.
 *
 * @param nbi_isl  NBI island to configure
 * @param tm_q     NBI TM queue to enable
 *
 * @note This function is not safe for multi-threaded use.
 */
__intrinsic void nbi_tm_enable_queue(unsigned int nbi_isl, unsigned int tm_q);


#endif /* _LINK_CTRL_H_ */