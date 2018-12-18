#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(ldh_n8_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 0x12;

    gb.cartridge[0] = 0xe0;
    gb.cartridge[1] = 0x01;

    aiv_gb_tick(&gb);
    u8_t ret = aiv_gb_memory_read8(&gb, 0xFF01);

    ASSERT_THAT(ret == gb.a);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 2);
}

TEST(pop_hl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.sp = 0xff;
    aiv_gb_memory_write16(&gb, gb.sp - 1, 0xff00);
    gb.sp -= 2;

    gb.cartridge[0] = 0xe1;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.sp == 0xff00);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 3);
}

// TEST(ld_addr_in_bc_a)
// {
//     aiv_gameboy gb;
//     aiv_gb_init(&gb);

//     gb.a = 17;
//     gb.bc = 0x100;

//     gb.cartridge[0] = 0x02;

//     aiv_gb_tick(&gb);
//     ASSERT_THAT(aiv_gb_memory_read8(&gb, 0x100) == 17);
//     ASSERT_THAT(gb.ticks == 8);
//     ASSERT_THAT(gb.pc == 1);
// }

void aiv_gb_tests_run_opcodes_e0()
{
    RUN_TEST(ldh_n8_a);
    RUN_TEST(pop_hl);
}