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

TEST(ld_add_in_hl_h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.h = 17;
    gb.hl = 0x100;

    gb.cartridge[0] = 0x66;

    aiv_gb_tick(&gb);

    // ASSERT_THAT(aiv_gb_memory_read8(&gb, 0x100) == 17);
    ASSERT_THAT(gb.ticks == 8);
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
    RUN_TEST(ld_add_in_hl_h);
}
