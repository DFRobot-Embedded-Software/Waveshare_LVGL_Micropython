/**
  @file netif_arch.h
 */
/*
 * ============================================================================
 * History
 * =======
 * 2017-03-15 : Created
 *
 * (C) Copyright Bridgetek Pte Ltd
 * ============================================================================
 *
 * This source code ("the Software") is provided by Bridgetek Pte Ltd
 * ("Bridgetek") subject to the licence terms set out
 * http://www.ftdichip.com/FTSourceCodeLicenceTerms.htm ("the Licence Terms").
 * You must read the Licence Terms before downloading or using the Software.
 * By installing or using the Software you agree to the Licence Terms. If you
 * do not agree to the Licence Terms then do not download or use the Software.
 *
 * Without prejudice to the Licence Terms, here is a summary of some of the key
 * terms of the Licence Terms (and in the event of any conflict between this
 * summary and the Licence Terms then the text of the Licence Terms will
 * prevail).
 *
 * The Software is provided "as is".
 * There are no warranties (or similar) in relation to the quality of the
 * Software. You use it at your own risk.
 * The Software should not be used in, or for, any medical device, system or
 * appliance. There are exclusions of Bridgetek liability for certain types of loss
 * such as: special loss or damage; incidental loss or damage; indirect or
 * consequential loss or damage; loss of income; loss of business; loss of
 * profits; loss of revenue; loss of contracts; business interruption; loss of
 * the use of money or anticipated savings; loss of information; loss of
 * opportunity; loss of goodwill or reputation; and/or loss of, damage to or
 * corruption of data.
 * There is a monetary cap on Bridgetek's liability.
 * The Software may have subsequently been amended by another user and then
 * distributed by that other user ("Adapted Software").  If so that user may
 * have additional licence terms that apply to those amendments. However, Bridgetek
 * has no liability in relation to those amendments.
 * ============================================================================
 */

#ifndef NETIF_ARCH_H_
#define NETIF_ARCH_H_

#if defined(__FT32__)

#include <stdlib.h>
#include <ft900.h>
#include <registers/ft900_eth_registers.h>
#include <lwip/inet.h>
#include <lwip/sys.h>
#include <lwip/tcp.h>
#include <lwip/netif.h>
#include <lwip/init.h>
#include <lwip/stats.h>
#include <netif/etharp.h>
#include <lwip/igmp.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

err_t arch_ft900_init(struct netif *netif);
err_t arch_ft900_link_output(struct netif *netif, struct pbuf *p);
err_t arch_ft900_tick(struct netif *netif);
void arch_ft900_recv_on();
void arch_ft900_recv_off();


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif // defined(__FT32__)

#endif /* NETIF_ARCH_H_ */