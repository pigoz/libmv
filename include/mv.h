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

typedef enum mv_error {
    /**
     * No error happened (used to signal successful operation).
     * Keep in mind that many API functions returning error codes can also
     * return positive values, which also indicate success. API users can
     * hardcode the fact that ">= 0" means success.
     */
    MV_ERROR_SUCCESS = 0,

    /**
     * Could not initialize a valid OpenCL context
     */
    MV_ERROR_OPENCL_INIT_FAILED = -1,
} mv_error;

mv_context *mv_context_create(void);
int mv_context_initialize(mv_context *);
void mv_context_free(mv_context *);
void mv_clinfo(void);

#ifdef __cplusplus
}
#endif

#endif
