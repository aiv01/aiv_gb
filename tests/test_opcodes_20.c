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

TEST(jr_z_r8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    UNSET_Z(gb);

    gb.cartridge[0] = 0x28;
    gb.cartridge[1] = 0x02;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.pc == 4);
    ASSERT_THAT(gb.ticks == 12)
}

TEST(not_jr_z_r8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    SET_Z(gb);

    gb.cartridge[0] = 0x28;
    gb.cartridge[1] = 0x02;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.pc == 2);
    ASSERT_THAT(gb.ticks == 8)
}

TEST(inc_h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x24;
    gb.h = 1;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 0x02);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(GET_N((&gb)) == 0);
    ASSERT_THAT(GET_H((&gb)) == 0);
    ASSERT_THAT(GET_Z((&gb)) == 0);
}

TEST(inc_h_half)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x24;
    gb.h = 0x0f;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 0x10);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(GET_N((&gb)) == 0);
    ASSERT_THAT(GET_H((&gb)) == 0x20);
    ASSERT_THAT(GET_Z((&gb)) == 0);
}

TEST(inc_h_zero)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x24;
    gb.h = 0xff;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 0x00);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(GET_N((&gb)) == 0);
    ASSERT_THAT(GET_H((&gb)) == 0x20);
    ASSERT_THAT(GET_Z((&gb)) == 0x80);
}

TEST(dec_h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x25;
    gb.h = 2;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 0x01);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(GET_N((&gb)) == 0x40);
    ASSERT_THAT(GET_H((&gb)) == 0);
    ASSERT_THAT(GET_Z((&gb)) == 0);
}

TEST(dec_h_half)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x25;
    gb.h = 0x10;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 0x0f);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(GET_N((&gb)) == 0x40);
    ASSERT_THAT(GET_H((&gb)) == 0x20);
    ASSERT_THAT(GET_Z((&gb)) == 0);
}

TEST(dec_h_zero)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x25;
    gb.h = 0x01;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 0x00);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(GET_N((&gb)) == 0x40);
    ASSERT_THAT(GET_H((&gb)) == 0);
    ASSERT_THAT(GET_Z((&gb)) == 0x80);
}

TEST(inc_hl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 2;
    gb.cartridge[0] = 0x23;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.hl == 0x03);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
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

TEST(ld_h_d8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x26;
    gb.cartridge[1] = 0x01;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.h == 0x01);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 2);
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

TEST(add_hl_hl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 2;
    gb.cartridge[0] = 0x29;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.hl == 0x04);
    ASSERT_THAT(gb.ticks == 8);
    printf_s("%d\n", gb.pc);
    ASSERT_THAT(gb.pc == 2);
}

void aiv_gb_tests_run_opcodes_20()
{
    RUN_TEST(jr_nz_r8);
    RUN_TEST(not_jr_nz_r8);
    RUN_TEST(jr_z_r8);
    RUN_TEST(not_jr_z_r8);
    RUN_TEST(ld_hl_d16);
    RUN_TEST(ld_hl_inc_a);
    RUN_TEST(inc_hl);
    RUN_TEST(inc_h);
    RUN_TEST(inc_h_half);
    RUN_TEST(inc_h_zero);
    RUN_TEST(dec_h);
    RUN_TEST(dec_h_half);
    RUN_TEST(dec_h_zero);
    RUN_TEST(ld_h_d8);
    RUN_TEST(add_hl_hl);

}
