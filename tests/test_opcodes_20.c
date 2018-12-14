#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(jr_nz_r8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    aiv_gb_set_flag(&gb, ZERO, 1);

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

    aiv_gb_set_flag(&gb, ZERO, 0);

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
    aiv_gb_set_flag(&gb, ZERO, 0);

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
    aiv_gb_set_flag(&gb, ZERO, 1);

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
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
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
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0x20);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
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
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0x20);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0x80);
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
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0x40);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
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
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0x40);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0x20);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
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
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0x40);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0x80);
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

TEST(dec_hl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 2;
    gb.cartridge[0] = 0x2B;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.hl == 1);
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

TEST(ld_l_d8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x2E;
    gb.cartridge[1] = 0x03;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.l == 0x03);
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
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 4);
    ASSERT_THAT(gb.hl == 2);
}

TEST(ld_a_hl_inc)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 2;
    aiv_gb_memory_write16(&gb, gb.hl, 5);
    gb.cartridge[0] = 0x2A;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 5);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 2);
    ASSERT_THAT(gb.hl == 3);
}

TEST(add_hl_hl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 7;
    gb.cartridge[0] = 0x29;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.hl == 14);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == 0);
}

TEST(add_hl_hl_over_half)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 0x00ff;
    gb.cartridge[0] = 0x29;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.hl == 0x01fe);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0x20);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == 0);
}

TEST(add_hl_hl_over)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.hl = 0xee00;
    gb.cartridge[0] = 0x29;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.hl == 0xdc01);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == 0x10);
}

TEST(inc_l)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x2C;
    gb.l = 1;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 0x02);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
}

TEST(inc_l_half)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x2C;
    gb.l = 0x0f;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 0x10);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0x20);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
}

TEST(inc_l_zero)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x2C;
    gb.l = 0xff;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 0x00);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0x20);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0x80);
}

TEST(dec_l)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x2D;
    gb.l = 2;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 0x01);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0x40);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
}

TEST(dec_l_half)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x2D;
    gb.l = 0x10;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 0x0f);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0x40);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0x20);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
}

TEST(dec_l_zero)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x2D;
    gb.l = 0x01;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 0x00);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0x40);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0x80);
}

TEST(cpl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x2F;
    gb.a = 0x59;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 0xa6);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0x40);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0x20);
}

TEST(daa_addiction_carry)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x27;
    aiv_gb_set_flag(&gb, NEG, 0);

    //case 09 + AB = B4
    //bcd result should be 14 with carry
    gb.a = 0xB4;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 0x14);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == 0x10);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 4);
}

TEST(daa_addiction_half_carry)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x27;
    aiv_gb_set_flag(&gb, NEG, 0);

    //case 09 + A2 = AB
    //bcd result should be 11 with carry and half carry
    gb.a = 0xAB;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 0x11);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == 0x10);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 4);
}

TEST(daa_subtraction_carry)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x27;
    aiv_gb_set_flag(&gb, NEG, 0x40);
    aiv_gb_set_flag(&gb, CARRY, 0x10);

    //case 09 - AB = 5E
    //bcd result should be FE with carry
    gb.a = 0x5E;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 0xFE);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == 0x10);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 4);
}

TEST(daa_subtraction_half_carry)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x27;
    aiv_gb_set_flag(&gb, NEG, 0x40);
    aiv_gb_set_flag(&gb, HALF, 0x20);

    //case 03 - 09 = FA
    //bcd result should be 11
    gb.a = 0xFA;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 0xF4);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 4);
}

void aiv_gb_tests_run_opcodes_20()
{
    RUN_TEST(jr_nz_r8);
    RUN_TEST(not_jr_nz_r8);
    RUN_TEST(jr_z_r8);
    RUN_TEST(not_jr_z_r8);
    RUN_TEST(ld_hl_d16);
    RUN_TEST(ld_hl_inc_a);
    RUN_TEST(ld_a_hl_inc);
    RUN_TEST(inc_hl);
    RUN_TEST(dec_hl);
    RUN_TEST(inc_h);
    RUN_TEST(inc_h_half);
    RUN_TEST(inc_h_zero);
    RUN_TEST(dec_h);
    RUN_TEST(dec_h_half);
    RUN_TEST(dec_h_zero);
    RUN_TEST(inc_l);
    RUN_TEST(inc_l_half);
    RUN_TEST(inc_l_zero);
    RUN_TEST(dec_l);
    RUN_TEST(dec_l_half);
    RUN_TEST(dec_l_zero);
    RUN_TEST(ld_h_d8);
    RUN_TEST(ld_l_d8);
    RUN_TEST(add_hl_hl);
    RUN_TEST(add_hl_hl_over_half);
    RUN_TEST(add_hl_hl_over);
    RUN_TEST(cpl);
    RUN_TEST(daa_addiction_carry);
    RUN_TEST(daa_addiction_half_carry);
    RUN_TEST(daa_subtraction_carry);
    RUN_TEST(daa_subtraction_half_carry);
}
