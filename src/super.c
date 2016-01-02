#include <mv.h>
#include <math.h>

int mv_super_downscale_levels(int size, int min_blk_size)
{
    int levels = 0;
    for (int n = 0; size / powf(2, n) > min_blk_size; n++)
        levels++;
    return levels;
}
