#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(pop_de)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    aiv_gb_memory_write16(&gb, gb.sp - 1, 0xd000);
    gb.sp -= 2;

    gb.cartridge[0] = 0xd1;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.de == 0xd000);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 12);
}

TEST(ret_nc)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    aiv_gb_memory_write16(&gb, gb.sp - 1, 0xd000);
    gb.sp -= 2;

    gb.cartridge[0] = 0xd0;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 0xd000);
    ASSERT_THAT(gb.ticks == 20);
}

TEST(ret_nc_red_light)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    aiv_gb_set_flag(&gb, CARRY, 1);

    aiv_gb_memory_write16(&gb, gb.sp - 1, 0xd000);
    gb.sp -= 2;

    gb.cartridge[0] = 0xd0;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 8);
}

void aiv_gb_tests_run_opcodes_d0()
{
    RUN_TEST(pop_de);
    RUN_TEST(ret_nc);
    RUN_TEST(ret_nc_red_light);
}