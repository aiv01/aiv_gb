#include "aiv_unit_test.h"
#include "aiv_gb.h"

TEST(ld_addr_in_b_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.b = 10;
    gb.d = 3;

    gb.cartridge[0] = 0X50;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.d == 3);
    ASSERT_THAT(gb.b == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_c_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 10;
    gb.d = 3;

    gb.cartridge[0] = 0X51;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.d == 3);
    ASSERT_THAT(gb.c == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_d_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);


    gb.d = 3;

    gb.cartridge[0] = 0X52;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.d == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_e_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.e = 10;
    gb.d = 3;

    gb.cartridge[0] = 0X53;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.d == 3);
    ASSERT_THAT(gb.e == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_h_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.h = 10;
    gb.d = 3;

    gb.cartridge[0] = 0X54;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.d == 3);
    ASSERT_THAT(gb.h == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_l_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.l = 10;
    gb.d = 3;

    gb.cartridge[0] = 0X55;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.d == 3);
    ASSERT_THAT(gb.l == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_addr_in_hl_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 0X100;
    gb.d = 2;

    gb.cartridge[0] = 0X56;

    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_memory_read8(&gb, gb.hl) == 0);
   // ASSERT_THAT(gb.d == 2);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_addr_in_a_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;
    gb.d = 3;

    gb.cartridge[0] = 0X57;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.d == 3);
    ASSERT_THAT(gb.a == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_b_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.b = 10;
    gb.e = 3;

    gb.cartridge[0] = 0X58;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.e == 3);
    ASSERT_THAT(gb.b == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_c_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 10;
    gb.e = 3;

    gb.cartridge[0] = 0X59;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.e == 3);
    ASSERT_THAT(gb.c == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_d_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.d = 10;
    gb.e = 3;

    gb.cartridge[0] = 0X5a;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.e == 3);
    ASSERT_THAT(gb.d == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_e_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.e = 3;

    gb.cartridge[0] = 0X5b;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.e == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_h_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.h = 10;
    gb.e = 3;

    gb.cartridge[0] = 0X5c;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.e == 3);
    ASSERT_THAT(gb.h == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_l_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.l = 10;
    gb.e = 3;

    gb.cartridge[0] = 0X5d;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.e == 3);
    ASSERT_THAT(gb.l == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_addr_in_hl_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 0X100;
    gb.e = 2;

    gb.cartridge[0] = 0X5e;

    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_memory_read8(&gb, gb.hl) == 0);
    ASSERT_THAT(gb.e == 0);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_addr_in_a_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;
    gb.e = 3;

    gb.cartridge[0] = 0X5f;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.e == 3);
    ASSERT_THAT(gb.a == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

void aiv_gb_tests_run_opcodes_50()
{
    RUN_TEST(ld_addr_in_b_d);
    RUN_TEST(ld_addr_in_c_d);
    RUN_TEST(ld_addr_in_d_d);
    RUN_TEST(ld_addr_in_e_d);
    RUN_TEST(ld_addr_in_h_d);
    RUN_TEST(ld_addr_in_l_d);
    RUN_TEST(ld_addr_in_a_d);
    RUN_TEST(ld_addr_in_b_e);
    RUN_TEST(ld_addr_in_c_e);
    RUN_TEST(ld_addr_in_d_e);
    RUN_TEST(ld_addr_in_e_e);
    RUN_TEST(ld_addr_in_h_e);
    RUN_TEST(ld_addr_in_l_e);
    RUN_TEST(ld_addr_in_a_e);
    RUN_TEST(ld_addr_in_hl_d);
    RUN_TEST(ld_addr_in_hl_e);
}