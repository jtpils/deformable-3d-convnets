//
// Created by lshi on 17-9-25.
//

//#ifndef DEFORM3D_NEW_PYTORCH_DEFORM_CONV3D_CUDA_BACKWARD_CU_H
//#define DEFORM3D_NEW_PYTORCH_DEFORM_CONV3D_CUDA_BACKWARD_CU_H

//#include "THC/THC.h"
//#include "TH/TH.h"

template<typename DType>
void deformable_im2col(cudaStream_t stream,
                       const DType *data_in, const DType *data_offset,
                       const int input_c,
                       const int input_l, const int input_h, const int input_w,
                       const int output_l, const int output_h, const int output_w,
                       const int kernel_l, const int kernel_h, const int kernel_w,
                       const int pad_l, const int pad_h, const int pad_w,
                       const int stride_l, const int stride_h, const int stride_w,
                       const int dilation_l, const int dilation_h, const int dilation_w,
                       const int channel_per_deformable_group, DType *data_col);


template<typename DType>
void deformable_col2im_input(cudaStream_t stream,
                             const DType *data_col, const DType *data_offset,
                             const int input_c,
                             const int input_l, const int input_h, const int input_w,
                             const int output_l, const int output_h, const int output_w,
                             const int kernel_l, const int kernel_h, const int kernel_w,
                             const int pad_l, const int pad_h, const int pad_w,
                             const int stride_l, const int stride_h, const int stride_w,
                             const int dilation_l, const int dilation_h, const int dilation_w,
                             const int channel_per_deformable_group, DType *grad_im);

template<typename DType>
void deformable_col2im_offset(cudaStream_t stream, const DType *data_col,
                              const DType *data_im, const DType *data_offset,
                              const int input_c,
                              const int input_l, const int input_h, const int input_w,
                              const int output_l, const int output_h, const int output_w,
                              const int kernel_l, const int kernel_h, const int kernel_w,
                              const int pad_l, const int pad_h, const int pad_w,
                              const int stride_l, const int stride_h, const int stride_w,
                              const int dilation_l, const int dilation_h, const int dilation_w,
                              const int channel_per_deformable_group,
                              DType *grad_offset);

//#endif //DEFORM3D_NEW_PYTORCH_DEFORM_CONV3D_CUDA_BACKWARD_CU_H
