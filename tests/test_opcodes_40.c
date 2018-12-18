#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(ld_in_b_b)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.b = 2;

    gb.cartridge[0] = 0x40;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.b == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_in_b_c)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.b = 2;
    gb.c = 1;

    gb.cartridge[0] = 0x41;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 1);
    ASSERT_THAT(gb.b == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_in_b_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.b = 2;
    gb.d = 1;

    gb.cartridge[0] = 0x42;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.d == 1);
    ASSERT_THAT(gb.b == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_in_b_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.b = 2;
    gb.e = 1;

    gb.cartridge[0] = 0x43;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.e == 1);
    ASSERT_THAT(gb.b == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_in_b_h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.b = 2;
    gb.h = 1;

    gb.cartridge[0] = 0x44;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 1);
    ASSERT_THAT(gb.b == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_in_b_l)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.b = 2;
    gb.l = 1;

    gb.cartridge[0] = 0x45;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 1);
    ASSERT_THAT(gb.b == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_in_b_hl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 0x100;
    gb.b = 2;

    gb.cartridge[0] = 0x46;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.b == 0);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_in_b_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.b = 2;
    gb.a = 1;

    gb.cartridge[0] = 0x47;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 1);
    ASSERT_THAT(gb.b == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_in_c_c)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 1;

    gb.cartridge[0] = 0x49;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_in_c_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 2;
    gb.d = 1;

    gb.cartridge[0] = 0x4a;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 1);
    ASSERT_THAT(gb.d == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_in_c_b)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 2;
    gb.b = 1;

    gb.cartridge[0] = 0x4a;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 1);
    ASSERT_THAT(gb.b == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_in_c_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 2;
    gb.e = 1;

    gb.cartridge[0] = 0x4b;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 1);
    ASSERT_THAT(gb.e == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_in_c_h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 2;
    gb.h = 1;

    gb.cartridge[0] = 0x4c;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 1);
    ASSERT_THAT(gb.h == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(ld_in_c_l)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 2;
    gb.l = 1;

    gb.cartridge[0] = 0x4d;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 1);
    ASSERT_THAT(gb.l == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_in_c_hl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 0x100;
    gb.c = 2;

    gb.cartridge[0] = 0x4e;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.b == 0);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_in_c_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 2;
    gb.a = 1;

    gb.cartridge[0] = 0x4f;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 1);
    ASSERT_THAT(gb.a == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

void aiv_gb_tests_run_opcodes_40()
{
    RUN_TEST(ld_in_b_b);
    RUN_TEST(ld_in_b_c);
    RUN_TEST(ld_in_b_d);
    RUN_TEST(ld_in_b_e);

    RUN_TEST(ld_in_b_h);
    RUN_TEST(ld_in_b_l);
    RUN_TEST(ld_in_b_hl);
    RUN_TEST(ld_in_b_a);

    RUN_TEST(ld_in_c_b);
    RUN_TEST(ld_in_c_c);
    RUN_TEST(ld_in_c_d);
    RUN_TEST(ld_in_c_e);

    RUN_TEST(ld_in_c_h);
    RUN_TEST(ld_in_c_l);
    RUN_TEST(ld_in_c_hl);
    RUN_TEST(ld_in_c_a);
}
