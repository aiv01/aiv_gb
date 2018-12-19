#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(func_alessio)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    ASSERT_THAT(aiv_gb_load_cartridge(&gb, "tests/roms/AlessioRom.gb") == 0);

    u8_t ret = 0;
    while(ret >= 0)
    {
        ret = aiv_gb_tick(&gb);
    }
    //printf_s("///////////////////////////////////////////////////////////////\n");
    ASSERT_THAT(gb.a == 6)
    ASSERT_THAT(gb.h == 0)
    ASSERT_THAT(gb.l == 5)
    ASSERT_THAT(gb.d == 0)
    ASSERT_THAT(gb.e == 0xA)
}

void aiv_gb_tests_run_func_alessio()
{
    RUN_TEST(func_alessio);
}