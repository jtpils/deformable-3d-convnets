import torch
import torch.nn as nn
from torch.autograd import Variable

from model.deform3d.deform_conv3d_modules import ConvOffset3d

batchsize = 2
c_in = 1
c_out = 1
in_l = in_h = in_w = 3
kernel_l = kernel_h = kernel_w = 1
out_l = out_h = out_w = 3
stri = 1
pad = 2
dilation = 2
channel_per_group = 1

conv = nn.Conv3d(
    c_in,
    c_in // channel_per_group * 3 * kernel_l * kernel_h * kernel_w,
    kernel_size=(kernel_l, kernel_h, kernel_w),
    stride=(stri, stri, stri),
    padding=(pad, pad, pad),
    dilation=(dilation, dilation, dilation),
    bias=False).cuda()
conv_offset3d = ConvOffset3d(c_in, c_out, (kernel_l, kernel_h, kernel_w), stri, pad, channel_per_group).cuda()

inputs = Variable(torch.randn(batchsize, c_in, in_l, in_h, in_w).cuda())
offset = conv(inputs)
output = conv_offset3d(inputs, offset)
out_0 = torch.rand(*output.size()).cuda()
a = output.backward(out_0)
print(output.size())
