#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(ld_h_b)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.h = 6;
    gb.b = 2;

    gb.cartridge[0] = 0x60;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == gb.b);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_h_c)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.h = 6;
    gb.c = 2;

    gb.cartridge[0] = 0x61;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == gb.c);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_h_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.h = 6;
    gb.d = 2;

    gb.cartridge[0] = 0x62;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == gb.d);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_h_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.h = 6;
    gb.e = 2;

    gb.cartridge[0] = 0x63;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == gb.e);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_h_h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.h = 6;

    gb.cartridge[0] = 0x64;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 6);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_h_l)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.h = 6;
    gb.l = 2;

    gb.cartridge[0] = 0x65;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == gb.l);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_address_in_hl_h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 0x100;
    gb.h = 6;

    gb.cartridge[0] = 0x66;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 0);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_h_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.h = 6;
    gb.a = 2;

    gb.cartridge[0] = 0x67;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == gb.a);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_l_b)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.l = 6;
    gb.b = 2;

    gb.cartridge[0] = 0x68;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == gb.b);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_l_c)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.l = 6;
    gb.c = 2;

    gb.cartridge[0] = 0x69;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == gb.c);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_l_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.l = 6;
    gb.d = 2;

    gb.cartridge[0] = 0x6a;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == gb.d);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_l_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.l = 6;
    gb.e = 2;

    gb.cartridge[0] = 0x6b;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == gb.e);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_l_h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.l = 6;
    gb.h = 2;

    gb.cartridge[0] = 0x6c;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == gb.h);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_l_l)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.l = 6;

    gb.cartridge[0] = 0x6d;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 6);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_address_in_hl_l)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 0x100;
    gb.l = 6;

    gb.cartridge[0] = 0x6e;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 0);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_l_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.l = 6;
    gb.a = 2;

    gb.cartridge[0] = 0x6f;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == gb.a);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

void aiv_gb_tests_run_opcodes_60()
{
    RUN_TEST(ld_h_b);
    RUN_TEST(ld_h_c);
    RUN_TEST(ld_h_d);
    RUN_TEST(ld_h_e);
    RUN_TEST(ld_h_h);
    RUN_TEST(ld_h_l);
    RUN_TEST(ld_address_in_hl_h);
    RUN_TEST(ld_h_a);
    RUN_TEST(ld_l_b);
    RUN_TEST(ld_l_c);
    RUN_TEST(ld_l_d);
    RUN_TEST(ld_l_e);
    RUN_TEST(ld_l_h);
    RUN_TEST(ld_l_l);
    RUN_TEST(ld_address_in_hl_l);
    RUN_TEST(ld_l_a);
}
