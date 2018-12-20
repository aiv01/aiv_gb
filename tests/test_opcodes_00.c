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

TEST(inc_bc)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.bc = 2;
    gb.cartridge[0] = 0x03;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.bc == 3);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(dec_bc)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.bc = 2;
    gb.cartridge[0] = 0x0b;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.bc == 1);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(dec_c)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 2;
    gb.cartridge[0] = 0x0d;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.c == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(inc_c)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.c = 2;
    gb.cartridge[0] = 0x0c;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.c == 3);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ld_a16_sp)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x08;
    gb.cartridge[1] = 100;
    gb.sp = 2;

    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_memory_read16(&gb, 100) == 2);
    ASSERT_THAT(gb.ticks == 20);
    ASSERT_THAT(gb.pc == 5);
}

TEST(ld_c_d8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x0e;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 1);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

void aiv_gb_tests_run_opcodes_00()
{
    RUN_TEST(nop);
    RUN_TEST(ld_bc_d16);
    RUN_TEST(ld_addr_in_bc_a);    
    RUN_TEST(inc_bc);
    RUN_TEST(dec_bc);
    RUN_TEST(dec_c);
    RUN_TEST(inc_c);
    RUN_TEST(ld_a16_sp);
    RUN_TEST(ld_c_d8);
}

