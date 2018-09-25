/*  upipe.h	Thu Jan 19 2012 16:27:48 chwon */

/*

Module:  upipe.h

Function:
	Home for the UPIPE structure.

Version:
	V3.01f	Thu Jan 19 2012 16:27:48 chwon	Edit level 7

Copyright notice:
	This file copyright (C) 2002, 2005-2006, 2012 by

		MCCI Corporation
		3520 Krums Corners Road
		Ithaca, NY  14850

	An unpublished work.  All rights reserved.
	
	This file is proprietary information, and may not be disclosed or
	copied without the prior permission of MCCI Corporation
 
Author:
	Terry Moore, MCCI Corporation	May 2002

Revision history:
   1.79a  Mon May 27 2002 23:00:00  tmm
	Module created.

   1.91d  2005-05-31  tmm
	For high-speed, we need to clarify the values to be stored in
	the UPIPE.  Add documentation.

   1.97e  Mon Aug 07 2006 18:45:09  tmm
	Documentation changes only: remove references to unimplemented
	API.

   3.01f  Thu Jan 19 2012 16:27:48  chwon
	14623: added UPIPE_GET_SETTING_MASK() and UPIPE_GET_EPADDR_MASK().

*/

#ifndef _UPIPE_H_		/* prevent multiple includes */
#define _UPIPE_H_

#ifndef _USBPUMPENV_H_
# include "usbpumpenv.h"
#endif

/*

Type:	UPIPE

Function:
	Represents a single USB pipe on a USB DataPump device.

Description:
	Each possible pipe offered by given USB device is represented
	by a UPIPE instance.  UPIPE instances are prepared during
	DataPump initialization by code generated by UBSRC, based on
	the endpoints listed in the descriptors for the device.  In 
	addition to the UPIPEs for the default pipe (one OUT and one IN),
	there is one UPIPE per endpoint descriptor.  Pipes in
	different alternate settings and configurations may use the same 
	underlying hardware.  The underylying hardware is represented
	by UENDPOINT structures.  Therefore the relationship between
	UPIPEs and UENDPOINTs is logically many-to-one.  The UPIPE
	currently associated with a given UENDPOINT (if any) is found
	by examining the UENDPOINT's uep_pPipe pointer.

	Numerous fields in the UPIPE are static (since they are supposed
	to be based on the info in the endpoint descxriptor).  However,
	for computational efficiency, the values are copied into the
	UPIPE, and in the process may be normalized so that the
	DCD software and DataPump core doesn'th ave to worry about
	the peculiarities of encoding.

Contents:
	UINTERFACE *upipe_pInterface;
		Pointer to owning UINTERFACE for this UPIPE.
		Set at init-time by USBRC-generated code, and thereafter 
		read-only.

	UENDPOINT *upipe_pEndpoint;
		Pointer to UENDPOINT used for moving data for this
		UPIPE.  Set at init-time by USBRC-generated code, and 
		thereafter read-only.

	CONST USBIF_EPDESC_WIRE *upipe_pEpDesc;
		Pointer to the endpoint descriptor that defines this
		UPIPE.  Set at init-time by USBRC-generated code, and
		thereafter read-only.

	VOID *upipe_extension;
		Pipe-specific information.  Reserved for use by MCCI
		DataPump core code.  Presently only used by the (deprecated)
		UsbCreateIntRegisters() facility.

	UEVENTNODE *upipe_noteq;
		Head of the queue of UEVENTNODES linked to this UPIPE.
		These are by clients for receiving host-initiated events
		(or bus-initiated events) that are relevant to this UPIPE.

	USHORT upipe_wMaxPacketSize;
		The maximum packet size for this endpoint.  Set at init-time
		by USBRC-generated code, and thereafter read-only.

		Note that this is *not* identical to the value in the
		endpoint-descriptor's wMaxPacketSize field.  It always
		represents the actual max packet size for this endpoint.
		(For high-speed isoch, the bits that determine number
		of packets per microframe are not extracted.)

	UCHAR upipe_bmAtttributes;
		The pipe type (based on the USB 1.1 / USB 2.0 full-speed
		usage of this field).  Bits 0..1 are copied from the
		endpoint descriptors bmAtributes byte.  The other bits
		are zero.   Therefore, this byte may be used for
		determining the endpoint type (BULK, INT, CONTROL or
		ISOCHRONOUS) without masking.

		Set at init-time by USBRC-generated code, and thereafter 
		read-only.

	UCHAR upipe_bEndpointAddress;
		Contains the endpoint address and direction bits.
		Bit 7 is set for IN pipes, clear for OUT pipes.  Bits
		3..0 contain the endpoint address.  Bits 6..4 are
		reserved and must be zero.

		Set at init-time by USBRC-generated code, and thereafter 
		read-only.

Notes:
	Most of these fields are read-only and generated at init time.
	In principal these could all be learned from the endpoint
	descriptor.  However, that's slow, and it's also not why we
	have the pEpDesc -- that's in case you need to look at endpoint-
	specific class or vendor descriptors (or extra info for audio
	class).

	Two UPIPEs are needed for a control endpoint, one OUT, one IN.

	Control endpoints are presently only supported for the default
	pipe.

	The UDEVICE, if needed, must be found by using the UINTERFACE
	pointer.

See Also:
	UENDPOINT, UDEVICE, UINTERFACE.

	Compare with the host-controller structure USBPUMP_HCD_PIPE,
	which presents similar info from the hosts point of view.

Implementation Notes:
	If you change this, you need to look at USBRC also, so that
	the initialization logic is properly handled.

*/

struct TTUSB_UPIPE
	{
	__TMS_UINTERFACE *upipe_pInterface;	/* owning interface */
	__TMS_UENDPOINT *upipe_pEndpoint;	/* hw endpoint used */
	__TMS_CONST __TMS_USBIF_EPDESC_WIRE *upipe_pEpDesc;
	__TMS_VOID	*upipe_extension;	/* pipe-specific info */
	__TMS_UEVENTNODE *upipe_noteq;		/* pointer to the note queue */
	__TMS_USHORT	upipe_wMaxPacketSize;	/* the packet size */
	__TMS_UCHAR	upipe_bmAttributes;	/* the endpoint type */
	__TMS_UCHAR	upipe_bEndpointAddress;	/* the endpoint address */
	};

/****************************************************************************\
|
|	Flags for functions that need to match pipes -- these are documented 
|	at UsbPumpInterface_EnumeratePipes(), which is in turn used by
|	the UDATASTREAM plumbing.
|
\****************************************************************************/

/* the binding flags */
#define __TMS_UPIPE_SETTING_MASK_CONTROL_OUT	(1 << 0)
#define __TMS_UPIPE_SETTING_MASK_ISO_OUT	(1 << 1)
#define __TMS_UPIPE_SETTING_MASK_BULK_OUT	(1 << 2)
#define __TMS_UPIPE_SETTING_MASK_INT_OUT	(1 << 3)
#define __TMS_UPIPE_SETTING_MASK_CONTROL_IN	(1 << 4)
#define __TMS_UPIPE_SETTING_MASK_ISO_IN		(1 << 5)
#define __TMS_UPIPE_SETTING_MASK_BULK_IN	(1 << 6)
#define __TMS_UPIPE_SETTING_MASK_INT_IN		(1 << 7)
#define __TMS_UPIPE_SETTING_MASK_ANY		(0xFF)
#define __TMS_UPIPE_SETTING_MASK_DATA		(0xEE)
#define __TMS_UPIPE_SETTING_MASK_DATA_IN	(0xE0)
#define __TMS_UPIPE_SETTING_MASK_DATA_OUT	(0x0E)

#define __TMS_UPIPE_SETTING_MASK_BULKINT_IN	\
	(__TMS_UPIPE_SETTING_MASK_BULK_IN  |	\
	 __TMS_UPIPE_SETTING_MASK_INT_IN)

#define __TMS_UPIPE_SETTING_MASK_BULKINT_OUT	\
	(__TMS_UPIPE_SETTING_MASK_BULK_OUT |	\
	 __TMS_UPIPE_SETTING_MASK_INT_OUT)

/*

Macro:	UPIPE_SETTING_MASK()

Function:
	Return a bit mask that represents a given actual combination
	of pipe attributes.

Definition:
	ARG_UCHAR UPIPE_SETTING_MASK(
		ARG_UCHAR bmAttr,
		ARG_UCHAR EpAddr
		);

Description:
	bmAttr is the endpoint type from upipe_bmAttributes.  EpAddr
	is the endpoint address from upipe_bEndpointAddress.  This
	macro prepares a bitmask that can be compared to a 
	UPIPE_SETTING_MASK value using a bitwise AND, to see if the
	pipe has the desired qualities.

	The resuling bitmask is a one-hot code.

	Bits 7..4:  set for Interrupt, Bulk, ISO, or control IN, 
	respectively.

	Bits 3..0:  set for Interrupt, Bulk, ISO or control OUT,
	respectively.

*/

/* a macro for converting bmAttr and address to mask */
#define	__TMS_UPIPE_SETTING_MASK(bmAttr, EpAddr)	\
	((1 << ((bmAttr) & 3)) << (((EpAddr) >> (7 - 2)) & 4))

/*

Macro:	UPIPE_GET_SETTING_MASK()

Function:
	Return a bit mask that represents a given pipe.

Definition:
	ARG_UCHAR UPIPE_GET_SETTING_MASK(
		UPIPE *pPipe
		);

Description:
	This macro prepares a bitmask that can be compared to a 
	UPIPE_SETTING_MASK value using a bitwise AND, to see if the
	pipe has the desired qualities.

	The resuling bitmask is a one-hot code.

	Bits 7..4:  set for Interrupt, Bulk, ISO, or control IN, 
	respectively.

	Bits 3..0:  set for Interrupt, Bulk, ISO or control OUT,
	respectively.

*/

#define	__TMS_UPIPE_GET_SETTING_MASK(pPipe)		\
	__TMS_UPIPE_SETTING_MASK(			\
		(pPipe)->upipe_bmAttributes,		\
		(pPipe)->upipe_bEndpointAddress		\
		)

/****************************************************************************\
|
|	Address selection mask macro
|
\****************************************************************************/

#define __TMS_UPIPE_EPADDR_MASK(EpAddr)	(1 << ((EpAddr) & 0xF))

#define	__TMS_UPIPE_GET_EPADDR_MASK(pPipe)	\
	__TMS_UPIPE_EPADDR_MASK((pPipe)->upipe_bEndpointAddress)

/****************************************************************************\
|
|	Uncloaked names
|
\****************************************************************************/

/**** uncloaked names generated by uncloak-defs.sh ****/
#if !__TMS_CLOAKED_NAMES_ONLY
# define UPIPE_SETTING_MASK_CONTROL_OUT	\
   __TMS_UPIPE_SETTING_MASK_CONTROL_OUT
# define UPIPE_SETTING_MASK_ISO_OUT	\
   __TMS_UPIPE_SETTING_MASK_ISO_OUT
# define UPIPE_SETTING_MASK_BULK_OUT	\
   __TMS_UPIPE_SETTING_MASK_BULK_OUT
# define UPIPE_SETTING_MASK_INT_OUT	\
   __TMS_UPIPE_SETTING_MASK_INT_OUT
# define UPIPE_SETTING_MASK_CONTROL_IN	\
   __TMS_UPIPE_SETTING_MASK_CONTROL_IN
# define UPIPE_SETTING_MASK_ISO_IN	\
   __TMS_UPIPE_SETTING_MASK_ISO_IN
# define UPIPE_SETTING_MASK_BULK_IN	\
   __TMS_UPIPE_SETTING_MASK_BULK_IN
# define UPIPE_SETTING_MASK_INT_IN	\
   __TMS_UPIPE_SETTING_MASK_INT_IN
# define UPIPE_SETTING_MASK_ANY	\
   __TMS_UPIPE_SETTING_MASK_ANY
# define UPIPE_SETTING_MASK_DATA	\
   __TMS_UPIPE_SETTING_MASK_DATA
# define UPIPE_SETTING_MASK_DATA_IN	\
   __TMS_UPIPE_SETTING_MASK_DATA_IN
# define UPIPE_SETTING_MASK_DATA_OUT	\
   __TMS_UPIPE_SETTING_MASK_DATA_OUT
# define UPIPE_SETTING_MASK_BULKINT_IN	\
   __TMS_UPIPE_SETTING_MASK_BULKINT_IN
# define UPIPE_SETTING_MASK_BULKINT_OUT	\
   __TMS_UPIPE_SETTING_MASK_BULKINT_OUT
# define UPIPE_SETTING_MASK(bmAttr, EpAddr)	\
   __TMS_UPIPE_SETTING_MASK(bmAttr, EpAddr)
# define UPIPE_GET_SETTING_MASK(pPipe)	\
   __TMS_UPIPE_GET_SETTING_MASK(pPipe)
# define UPIPE_EPADDR_MASK(EpAddr)	\
   __TMS_UPIPE_EPADDR_MASK(EpAddr)
# define UPIPE_GET_EPADDR_MASK(pPipe)	\
   __TMS_UPIPE_GET_EPADDR_MASK(pPipe)
#endif /* !__TMS_CLOAKED_NAMES_ONLY */

/**** end of upipe.h ****/
#endif /* _UPIPE_H_ */