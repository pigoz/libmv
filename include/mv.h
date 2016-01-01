#ifndef MV_API_H
#define MV_API_H

#include <stddef.h>
#include <stdint.h>

#ifdef __APPLE__
    #include <OpenCL/opencl.h>
#else
    #include <CL/cl.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MV_ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define MV_MAKE_VERSION(major, minor) (((major) << 16) | (minor) | 0UL)
#define MV_API_VERSION MEC_MAKE_VERSION(0, 1)

typedef struct mv_context mv_context;

mv_context *mv_context_create(void);
void mv_clinfo(void);

#ifdef __cplusplus
}
#endif

#endif
