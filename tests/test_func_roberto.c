#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(func_roberto)
{
    //initialize gameboy
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/roberto.gb") == 0);

    int ret = 0;
    while (ret >= 0)
    {
        ret = aiv_gb_tick(&gb);
    }
    ASSERT_THAT(gb.e == 39);
}

void aiv_gb_tests_func_roberto()
{
    RUN_TEST(func_roberto);
}