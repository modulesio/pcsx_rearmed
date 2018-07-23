#ifndef __GPU_H__
#define __GPU_H__

#ifdef __cplusplus
extern "C"
{
#endif

int gpuReadStatus();

void psxDma2(u32 madr, u32 bcr, u32 chcr);
void gpuInterrupt();

#define HW_GPU_STATUS psxHu32ref(0x1814)

#ifdef __cplusplus
}
#endif

#endif
