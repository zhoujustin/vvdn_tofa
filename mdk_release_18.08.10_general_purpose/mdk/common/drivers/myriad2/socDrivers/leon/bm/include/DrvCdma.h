///
/// @file DrvCdma.h
/// @copyright All code copyright Movidius Ltd 2016, all rights reserved
///            For License Warranty see: common/license.txt
/// @defgroup DrvCdma Cdma Driver
/// @{
/// @brief     CMX DMA driver API
///
/// Driver usage example:
///
///  #include "DrvCdma.h"
///
///  static DrvCmxDmaTransaction list[LIST_SIZE]
///      __attribute__((section(".cmx_direct.bss")));
///  static DrvCmxDmaTransactionHnd dma_handle;
///
///  static DrvCmxDmaSetupStruct setup = {
///      .irq_priority = IRQ_PRIO,
///      .irq_enable = 1,  // 0 to disable CMX DMA interrupts
///      .agent = DRV_CMX_DMA_AGENT1
///  };
///
///  // use NULL as parameter instead of config for default configuration
///  int32_t status = DrvCmxDmaInitialize(&config);
///
///  if (status == MYR_DRV_SUCCESS) {
///    DrvCdmaCreateTransaction(&dma_handle, &list[0], src_buff, dst_buff,
///                             transfer_size);
///    for (i = 1; i < LIST_SIZE; i++)
///      DrvCmxDmaAddTransaction(&dma_handle, &list[i], src_buff, dst_buff,
///                              transfer_size);
///    // callback and context are not mandatory; replace their
///    // corresponding parameters with NULL if not needed
///    DrvCmxDmaStartTransfer(&dma_handle, callback, context);
///    DrvCmxDmaWaitTransaction(&dma_handle);
///  }
///


#ifndef COMMON_DRIVERS_MYRIAD2_SOCDRIVERS_LEON_BM_INCLUDE_DRVCDMA_H_
#define COMMON_DRIVERS_MYRIAD2_SOCDRIVERS_LEON_BM_INCLUDE_DRVCDMA_H_

#ifdef USE_CMX_DMA_NEW_DRIVER

// 1: Includes
// ----------------------------------------------------------------------------
#include <stdarg.h>
#include <stdint.h>
#include "DrvCdmaDefines.h"
#include "DrvRegUtils.h"
#include "DrvMutex.h"

#ifdef __cplusplus
extern "C" {
#endif

// 2: Defines
// ----------------------------------------------------------------------------

// 3:  Exported Global Data (generally better to avoid)
// ----------------------------------------------------------------------------

// 4:  Exported Functions (non-inline)
// ----------------------------------------------------------------------------

/// Initializes CMX DMA driver
///
/// This must be the first function called before using any other function form
/// the driver
///
/// @param [in] config Structure containing CMX DMA driver parameters
///
/// @return
///     MYR_DRV_SUCCESS the driver was successfully initialized
///     MYR_DRV_ERROR an error happened during driver initialization
///     MYR_DRV_ALREADY_INITIALIZED the driver was already initialized by
///      a previous call to this function
///
int32_t DrvCmxDmaInitialize(DrvCmxDmaSetupStruct *config);

/// Configures transaction parameters
///
/// This function is optional. If it is not called the transaction will
/// use the default parameters set at it's creation.
///
/// @param [in] transaction the transaction that need to be configured
/// @param [in] params a structure containing the new configuration
///
/// @return
///     MYR_DRV_SUCCESS the transaction was successfully configured
///     MYR_DRV_ERROR the couldn't be configured
///
int32_t DrvCmxDmaTransactionConfig(DrvCmxDmaTransaction *transaction,
                                   DrvCmxDmaConfParams *params);

/// Creates a new 1D transaction
///
/// The function returns a handle to the new transaction
///
/// @param [out] handle a handle to a transaction list containing only the newly
///             created transaction
/// @param [in] transaction the new transaction to be created
/// @param [in] src source address for the transaction
/// @param [in] dst destination address for the transaction
/// @param [in] size transaction size in bytes
///
/// @return
///     MYR_DRV_SUCCESS the transaction was successfully created
///     MYR_DRV_ERROR the transaction could not be created
///
int32_t DrvCmxDmaCreateTransaction(DrvCmxDmaTransactionHnd *handle,
                                 DrvCmxDmaTransaction *transaction,
                                 uint8_t *src, uint8_t *dst,
                                 uint32_t size);

/// Creates and links a new 1D transaction to an existing transaction list
///
/// @param [out] handle for the list on which the new transaction will be added
/// @param [in] transaction the new transaction that need to be created and
///             added to the list
/// @param [in] src source address for the transaction
/// @param [in] dst destination address for the transaction
/// @param [in] size transaction size in bytes
///
/// @return
///     MYR_DRV_SUCCESS the transaction was successfully added
///     MYR_DRV_ERROR the new transaction could not be added
///
int32_t DrvCmxDmaAddTransaction(DrvCmxDmaTransactionHnd *handle,
                                DrvCmxDmaTransaction *transaction,
                                uint8_t *src, uint8_t *dst,
                                uint32_t size);

/// Creates a new 2D transaction
///
/// The function returns a handle to the new transaction
///
/// @param [out] handle a handle to a transaction list containing only the newly
///             created transaction
/// @param [in] transaction the new transaction to be created
/// @param [in] src source address for the transaction
/// @param [in] dst destination address for the transaction
/// @param [in] src_width line width for source in bytes
/// @param [in] dst_width line width for destination in bytes
/// @param [in] src_stride stride size for source, defined as the size in bytes
///            from the start of a line to the start of the following line
/// @param [in] dst_stride stride size for destination, defined as the size in
/// bytes
///            from the start of a line to the start of the following line
/// @param [in] size transaction size in bytes
///
/// @return
///     MYR_DRV_SUCCESS the transaction was successfully created
///     MYR_DRV_ERROR the new transaction could not be created
///
int32_t DrvCmxDmaCreateStrideTransaction(DrvCmxDmaTransactionHnd *handle,
                                         DrvCmxDmaTransaction *transaction,
                                         uint8_t *src, uint8_t *dst,
                                         uint32_t src_width, uint32_t dst_width,
                                         uint32_t src_stride,
                                         uint32_t dst_stride, uint32_t size);

/// Creates and links a new 2D transaction to an existing transaction list
///
/// @param [in] handle handle to the list on which the new transaction will be
/// added
/// @param [in] transaction the new trasaction to be added
/// @param [in] src source address for the transaction
/// @param [in] dst destination address for the transaction
/// @param [in] src_width line width for source in bytes
/// @param [in] dst_width line width for destination in bytes
/// @param [in] src_stride stride size for source, defined as the size in bytes
///            from the start of a line to the start of the following line
/// @param [in] dst_stride stride size for destination, defined as the size in
/// bytes
///            from the start of a line to the start of the following line
/// @param [in] size transaction size in bytes
///
/// @return
///     MYR_DRV_SUCCESS the transaction was successfully added
///     MYR_DRV_ERROR the new transaction could not be added
///
int32_t DrvCmxDmaAddStrideTransaction(DrvCmxDmaTransactionHnd *handle,
                                      DrvCmxDmaTransaction *transaction,
                                      uint8_t *src, uint8_t *dst,
                                      uint32_t src_width, uint32_t dst_width,
                                      uint32_t src_stride, uint32_t dst_stride,
                                      uint32_t size);

/// @brief Creates a new 3D transaction.
/// @brief The function returns a handle to the new transaction.
/// @param [out] handle a handle to a transaction list containing only the newly
///             created transaction.
/// @param [in] transaction the new 3D transaction to be created.
/// @param [in] src source address for the transaction.
/// @param [in] dst destination address for the transaction.
/// @param [in] src_width line width for source in bytes.
/// @param [in] dst_width line width for destination in bytes.
/// @param [in] src_stride stride size for source, defined as the size in bytes
///             from the start of a line to the start of the following line.
/// @param [in] dst_stride stride size for destination, defined as the size in
///             bytes from the start of a line to the start of the following line.
/// @param [in] num_planes number of planes of data to be transfered. The value
///             needs to be greater than zero for 3D transaction.
/// @param [in] src_plane_stride plane stride size for source, defined as the
///             size in bytes from the start of a plane to the start of the
///             following plane.
/// @param [in] dst_plane_stride plane stride size for destination, defined as
///             the size in bytes from the start of a plane to the start of the
///             following plane.
/// @param [in] size transaction size in bytes.
///
/// @return
///     MYR_DRV_SUCCESS the transaction was successfully created
///     MYR_DRV_ERROR the new transaction could not be created
///
int32_t DrvCmxDmaCreate3DTransaction(
    DrvCmxDmaTransactionHnd *handle, DrvCmxDmaTransaction *transaction,
    uint8_t *src, uint8_t *dst, uint32_t src_width, uint32_t dst_width,
    uint32_t src_stride, uint32_t dst_stride, uint32_t num_planes,
    uint32_t src_plane_stride, uint32_t dst_plane_stride, uint32_t size);

/// @brief Creates and links a new 3D transaction to an existing transaction list.
/// @param [in] handle handle to the list on which the new transaction will be
///                    added.
/// @param [in] transaction the new 3D transaction to be added.
/// @param [in] src source address for the transaction.
/// @param [in] dst destination address for the transaction.
/// @param [in] src_width line width for source in bytes.
/// @param [in] dst_width line width for destination in bytes.
/// @param [in] src_stride stride size for source, defined as the size in bytes
///             from the start of a line to the start of the following line.
/// @param [in] dst_stride stride size for destination, defined as the size in
///             bytes from the start of a line to the start of the following line.
/// @param [in] num_planes number of planes of data to be transfered. The value
///             needs to be greater than zero for 3D transaction.
/// @param [in] src_plane_stride plane stride size for source, defined as the
///             size in bytes from the start of a plane to the start of the
///             following plane.
/// @param [in] dst_plane_stride plane stride size for destination, defined as
///             the size in bytes from the start of a plane to the start of the
///             following plane.
/// @param [in] size transaction size in bytes.
///
/// @return
///     MYR_DRV_SUCCESS the transaction was successfully added
///     MYR_DRV_ERROR the new transaction could not be added
///
int32_t DrvCmxDmaAdd3DTransaction(
    DrvCmxDmaTransactionHnd *handle, DrvCmxDmaTransaction *transaction,
    uint8_t *src, uint8_t *dst, uint32_t src_width, uint32_t dst_width,
    uint32_t src_stride, uint32_t dst_stride, uint32_t num_planes,
    uint32_t src_plane_stride, uint32_t dst_plane_stride, uint32_t size);

/// Start the DMA transfer for a transaction list
///
/// @param [in] handle for the transaction list
/// @param [in] callback a function to be called when the transfer is finished
///            This parameter is no mandatory. If it's value is NULL, no
///            function
///            will be executes when the transfer ends.
///            The callback is called only when CMX DMA interrupt is enabled
/// @param [in] callback context parameter for transfer finished callback
///            If no callback is provided this parameter is ignored.
///
/// @return
///     MYR_DRV_SUCCESS the transaction was successfully started
///     MYR_DRV_ERROR the couldn't be started
///
///     This function doesn't wait for the transfer to finish. It returns
///     immediately after the transfer starts.
///
int32_t DrvCmxDmaStartTransfer(DrvCmxDmaTransactionHnd *handle,
                               DrvCmxDmaOnCompletionCallback callback,
                               void *ctx);

/// Create a new list by joining the lists given as parameters
///
/// @param [out] handle the handle for the new list
/// @param [in] list_no the number of lists to be joined
/// @param [in] ... handles for task_no lists to be joined
///
/// @return
///     MYR_DRV_SUCCESS the transactions were successfully linked
///     MYR_DRV_ERROR the transactions could not be linked
///
int32_t DrvCmxDmaLinkTransactions(DrvCmxDmaTransactionHnd *handle,
                                  uint32_t list_cnt, ...);

/// Waits for one or more transactions started by DrvCmxDmaStartTransfer to
/// finish
///
/// @param [in] handle for a transaction or a list of transactions
///
/// @return
///     MYR_DRV_SUCCESS the transaction finished successfully
///     MYR_DRV_ERROR transfer finished with an error
///
int32_t DrvCmxDmaWaitTransaction(DrvCmxDmaTransactionHnd *handle);

/// Returns the current status of the transaction
///
/// @param [in] handle for a transaction or a list of transactions
/// @param [out] t_status transaction status; can be one of the following;
///     DRV_CMX_DMA_FINISHED - the transfer has finished
///     DRV_CMX_DMA_PENDING - transaction has been queued but it has not been
///     started yet
///
/// @return
///     MYR_DRV_SUCCESS the status was retrieved successfully
///     MYR_DRV_ERROR an error happened
///
int32_t DrvCmxDmaGetTransactionStatus(DrvCmxDmaTransactionHnd *handle,
                                      DrvCmxDmaTransactionStatus *t_status);

/// CMX DMA interrupt handler
///
/// @param [in] source - interrupt source
///
/// NOTE: This function is only exported to be used by sipp framework
///       It must not be used in any other cases
///
void DrvCmxDmaIrqHandler(uint32_t source);

/// DrvCmxDmaGetIrqMask
///
/// @return  The mask dicttaing which internal CDMA irqs will be handled
///          within driver
///

uint32_t DrvCmxDmaGetIrqMask ();

#ifdef __cplusplus
}
#endif

#endif  // USE_CMX_DMA_NEW_DRIVER

#endif  // COMMON_DRIVERS_MYRIAD2_SOCDRIVERS_LEON_BM_INCLUDE_DRVCDMA_H_


///@}
