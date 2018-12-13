#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(nop)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x00;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

void aiv_gb_tests_run_opcodes_00()
{
    RUN_TEST(nop);
    RUN_TEST(ld_bc_d16);
}