#include "test_helpers.h"

void test_mv_super_downscale_levels()
{
    assert_int_equal(mv_super_downscale_levels(1280, 4), 9);
    assert_int_equal(mv_super_downscale_levels(1280, 16), 7);
}

int main(void)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_mv_super_downscale_levels),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
