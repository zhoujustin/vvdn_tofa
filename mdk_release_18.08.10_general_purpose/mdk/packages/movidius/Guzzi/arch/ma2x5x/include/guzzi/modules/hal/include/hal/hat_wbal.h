/* =============================================================================
* Copyright (c) 2013-2014 MM Solutions AD
* All rights reserved. Property of MM Solutions AD.
*
* This source code may not be used against the terms and conditions stipulated
* in the licensing agreement under which it has been supplied, or without the
* written permission of MM Solutions. Rights to use, copy, modify, and
* distribute or disclose this source code and its documentation are granted only
* through signed licensing agreement, provided that this copyright notice
* appears in all copies, modifications, and distributions and subject to the
* following conditions:
* THIS SOURCE CODE AND ACCOMPANYING DOCUMENTATION, IS PROVIDED AS IS, WITHOUT
* WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. MM SOLUTIONS SPECIFICALLY DISCLAIMS
* ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN
* NO EVENT SHALL MM SOLUTIONS BE LIABLE TO ANY PARTY FOR ANY CLAIM, DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST
* PROFITS, OR OTHER LIABILITY, ARISING OUT OF THE USE OF OR IN CONNECTION WITH
* THIS SOURCE CODE AND ITS DOCUMENTATION.
* =========================================================================== */
/**
* @file hat_wbal.h
*
* @author ( MM Solutions AD )
*
*/
/* -----------------------------------------------------------------------------
*!
*! Revision History
*! ===================================
*! 05-Nov-2013 : Author ( MM Solutions AD )
*! Created
* =========================================================================== */

#ifndef __HAL_TYPES_WBAL_H__
#define __HAL_TYPES_WBAL_H__

#include <hal/hat_types.h>
#include <hal/hat_pix_fmt.h>
#include <hal/hat_dgain.h>

/*
 * R  = R  * c.r  + o.r
 * Gr = Gr * c.gr + o.gr
 * Gb = Gb * c.gb + o.gb
 * B  = B  * c.b  + o.b
 */
typedef struct  {
	hat_dgain_t dgain;    	// float  - Digital gain
    hat_bayer_float_t c;     // float - Coefficient of white balance gain
    hat_bayer_float_t o;   	// float - Offset of white balance offset - [0.0 .. 1.0]
}hat_wbal_coef_t;

#endif // __HAL_TYPES_WBAL_H__
