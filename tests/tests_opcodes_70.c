#include <aiv_unit_test.h>
#include <aiv_gb.h>

#define SETUP_GB    \
    aiv_gameboy gb; \
    aiv_gb_init(&gb)

TEST(ld_addr_hl_b)
{
    SETUP_GB;

    gb.b = 17;
    gb.hl = 0x100;

    gb.cartridge[0] = 0x70;

    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_memory_read8(&gb, 0x100) == 17);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_addr_hl_c)
{
    SETUP_GB;

    gb.c = 17;
    gb.hl = 0x100;

    gb.cartridge[0] = 0x71;

    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_memory_read8(&gb, 0x100) == 17);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_addr_hl_d)
{
    SETUP_GB;

    gb.d = 17;
    gb.hl = 0x100;

    gb.cartridge[0] = 0x72;

    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_memory_read8(&gb, 0x100) == 17);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_addr_hl_e)
{
    SETUP_GB;

    gb.e = 17;
    gb.hl = 0x100;

    gb.cartridge[0] = 0x73;

    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_memory_read8(&gb, 0x100) == 17);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_addr_hl_h)
{
    SETUP_GB;

    gb.h = 17;
    gb.hl = 0x100;

    gb.cartridge[0] = 0x74;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_addr_hl_l)
{
    SETUP_GB;

    gb.l = 17;
    gb.hl = 0x100;

    gb.cartridge[0] = 0x75;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(halt)
{
    SETUP_GB;

    gb.cartridge[0] = 0x76;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_addr_hl_a)
{
    SETUP_GB;

    gb.a = 17;
    gb.hl = 0x100;

    gb.cartridge[0] = 0x77;

    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_memory_read8(&gb, 0x100) == 17);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_a_b)
{
    SETUP_GB;

    gb.b = 6;
    gb.a = 2;

    gb.cartridge[0] = 0x78;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.b == gb.a);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_a_c)
{
    SETUP_GB;

    gb.c = 6;
    gb.a = 2;

    gb.cartridge[0] = 0x79;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == gb.a);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_a_d)
{
    SETUP_GB;

    gb.d = 6;
    gb.a = 2;

    gb.cartridge[0] = 0x7a;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.d == gb.a);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_a_e)
{
    SETUP_GB;

    gb.e = 6;
    gb.a = 2;

    gb.cartridge[0] = 0x7b;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.e == gb.a);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_a_h)
{
    SETUP_GB;

    gb.h = 6;
    gb.a = 2;

    gb.cartridge[0] = 0x7c;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == gb.a);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_a_l)
{
    SETUP_GB;

    gb.l = 6;
    gb.a = 2;

    gb.cartridge[0] = 0x7d;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == gb.a);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_a_a)
{
    SETUP_GB;

    gb.a = 6;

    gb.cartridge[0] = 0x7f;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

void aiv_gb_tests_run_opcodes_70()
{
    RUN_TEST(ld_addr_hl_b);
    RUN_TEST(ld_addr_hl_c);
    RUN_TEST(ld_addr_hl_d);
    RUN_TEST(ld_addr_hl_e);
    RUN_TEST(ld_addr_hl_h);
    RUN_TEST(ld_addr_hl_l);
    RUN_TEST(halt);
    RUN_TEST(ld_addr_hl_a);
    RUN_TEST(ld_a_b);
    RUN_TEST(ld_a_c);
    RUN_TEST(ld_a_d);
    RUN_TEST(ld_a_e);
    RUN_TEST(ld_a_h);
    RUN_TEST(ld_a_l);
    RUN_TEST(ld_a_a);
}