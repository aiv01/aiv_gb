#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(jr_nz_r8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    aiv_gb_set_flag(&gb, ZERO, 1);

    gb.cartridge[0] = 0x20;
    gb.cartridge[1] = 0x02;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.pc == 4);
    ASSERT_THAT(gb.ticks == 12)
}

void aiv_gb_tests_run_opcodes_20()
{
    RUN_TEST(jr_nz_r8);
}