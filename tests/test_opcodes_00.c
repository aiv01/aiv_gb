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

TEST(ld_bc_d16)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x01;
    gb.cartridge[1] = 0x01;
    gb.cartridge[2] = 0x02;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.bc == 0x0201);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 3);
}

TEST(ld_addr_in_bc_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 17;
    gb.bc = 0x100;

    gb.cartridge[0] = 0x02;

    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_memory_read8(&gb, 0x100) == 17);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

void aiv_gb_tests_run_opcodes_00()
{
    RUN_TEST(nop);
    RUN_TEST(ld_bc_d16);
    RUN_TEST(ld_addr_in_bc_a);    
}

