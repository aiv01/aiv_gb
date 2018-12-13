#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(jr_nz_r8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    SET_Z(gb);

    gb.cartridge[0] = 0x20;
    gb.cartridge[1] = 0x02;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.pc == 4);
    ASSERT_THAT(gb.ticks == 12)
}

TEST(not_jr_nz_r8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    UNSET_Z(gb);

    gb.cartridge[0] = 0x20;
    gb.cartridge[1] = 0x02;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.pc == 2);
    ASSERT_THAT(gb.ticks == 8)
}

TEST(ld_hl_d16)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x21;
    gb.cartridge[1] = 0x01;
    gb.cartridge[2] = 0x02;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.hl == 0x0201);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 3);
}

TEST(ld_hl_inc_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 2;
    gb.hl = 1;
    aiv_gb_memory_write16(&gb, gb.hl, 2);
    gb.cartridge[0] = 0x22;

    aiv_gb_tick(&gb);

    u8_t val = aiv_gb_memory_read8(&gb, gb.hl);
    ASSERT_THAT(val == 0x02);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 4);
    ASSERT_THAT(gb.hl == 2);
}

void aiv_gb_tests_run_opcodes_20()
{
    RUN_TEST(jr_nz_r8);
    RUN_TEST(not_jr_nz_r8);
    RUN_TEST(ld_hl_d16);
    RUN_TEST(ld_hl_inc_a);


}
