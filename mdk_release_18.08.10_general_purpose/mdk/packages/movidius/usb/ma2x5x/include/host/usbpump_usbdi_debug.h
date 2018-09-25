/* usbpump_usbdi_debug.h	Thu Dec 16 2010 11:47:45 chwon */

/*

Module:  usbpump_usbdi_debug.h

Function:
	Debug definitions for USBDI and the rest of the host stack.

Version:
	V3.01d	Thu Dec 16 2010 11:47:45 chwon	Edit level 2

Copyright notice:
	This file copyright (C) 2005, 2010 by

		MCCI Corporation
		3520 Krums Corners Road
		Ithaca, NY  14850

	An unpublished work.  All rights reserved.
	
	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of MCCI Corporation
 
Author:
	Terry Moore, MCCI Corporation	August 2005

Revision history:
   1.91h  Sat Aug 13 2005 22:47:19  tmm
	Module created.

   3.01d  Thu Dec 16 2010 11:47:45  chwon
	12178: re-arrange debug flags due to conflict with UDMASK_HCD

*/

#ifndef _USBPUMP_USBDI_DEBUG_H_		/* prevent multiple includes */
#define _USBPUMP_USBDI_DEBUG_H_

#ifndef _USBPUMPDEBUG_H_
# include "usbpumpdebug.h"
#endif

/* some additional flags and definitions */
/*	__TMS_UDMASK_HCD		(1UL << (__TMS_UDMASK_DEVBASE_N + 0)) */
#define	__TMS_UDMASK_USBDI_MATCH	(1UL << (__TMS_UDMASK_DEVBASE_N + 1))
#define	__TMS_UDMASK_USBDI_URB		(1UL << (__TMS_UDMASK_DEVBASE_N + 2))

/* remaining bits are still reserved */

/**** uncloaked names generated by uncloak-defs.sh ****/
#if !__TMS_CLOAKED_NAMES_ONLY
# define UDMASK_USBDI_MATCH	__TMS_UDMASK_USBDI_MATCH
# define UDMASK_USBDI_URB	__TMS_UDMASK_USBDI_URB
#endif /* !__TMS_CLOAKED_NAMES_ONLY */

/**** end of usbpump_usbdi_debug.h ****/
#endif /* _USBPUMP_USBDI_DEBUG_H_ */