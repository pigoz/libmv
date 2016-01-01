#include <mv.h>
#include "ta.h"

typedef struct mv_context {
} mv_context;

mv_context *mv_context_create(void) {
    mv_context *ctx = ta_znew(NULL, mv_context);
    return ctx;
}
