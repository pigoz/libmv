#include <mv.h>

int main(int argc, char **argv) {
    mv_clinfo();
    mv_context *ctx = mv_context_create();
    mv_context_initialize(ctx);
    return 0;
}
