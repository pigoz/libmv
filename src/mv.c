#include <mv.h>
#include "ta.h"

typedef struct mv_context {
    cl_context cl_ctx;
} mv_context;

void mv_context_destructor(void *vctx)
{
    mv_context *ctx = vctx;
    clReleaseContext(ctx->cl_ctx);
}

mv_context *mv_context_create(void)
{
    mv_context *ctx = ta_xznew(NULL, mv_context);
    return ctx;
}

int mv_context_initialize(mv_context *ctx)
{
    const cl_device_type type = CL_DEVICE_TYPE_GPU;
    ctx->cl_ctx = clCreateContextFromType(NULL, type, NULL, NULL, NULL);
    if (!ctx->cl_ctx)
        return MV_ERROR_OPENCL_INIT_FAILED;
    ta_set_destructor(ctx, mv_context_destructor);
    return MV_ERROR_SUCCESS;
}

void mv_context_free(mv_context *ctx)
{
    ta_free(ctx);
}
