#include <aiv_unit_test.h>
#include <aiv_gb.h>
#define INIT_GB       \
    aiv_gameboy gb;   \
    aiv_gb_init(&gb); \
    gb.pc = 0;        \
    gb.f = 0;
extern void _aiv_gb_set_flags_internal(aiv_gameboy *gb, u8_t to_sub);

TEST(set_carry_bool)
{
    INIT_GB;
    ASSERT_THAT(!GET_C(&gb));
    SET_C_BOOL(gb, 1);
    ASSERT_THAT(GET_C(&gb));
    SET_C_BOOL(gb, 0);
    ASSERT_THAT(!GET_C(&gb));
}
TEST(set_half_bool)
{
    INIT_GB;
    ASSERT_THAT(!GET_H(&gb));
    SET_H_BOOL(gb, 1);
    ASSERT_THAT(GET_H(&gb));
    SET_H_BOOL(gb, 0);
    ASSERT_THAT(!GET_H(&gb));
}
TEST(set_zero_bool)
{
    INIT_GB;
    ASSERT_THAT(!GET_Z(&gb));
    SET_Z_BOOL(gb, 1);
    ASSERT_THAT(GET_Z(&gb));
    SET_Z_BOOL(gb, 0);
    ASSERT_THAT(!GET_Z(&gb));
}
TEST(set_neg_bool)
{
    INIT_GB;
    ASSERT_THAT(!GET_N(&gb));
    SET_N_BOOL(gb, 1);
    ASSERT_THAT(GET_N(&gb));
    SET_N_BOOL(gb, 0);
    ASSERT_THAT(!GET_N(&gb));
}

TEST(set_carry)
{
    INIT_GB;
    ASSERT_THAT(!GET_C(&gb));
    SET_C(gb);
    ASSERT_THAT(GET_C(&gb));
    UNSET_C(gb);
    ASSERT_THAT(!GET_C(&gb));
}
TEST(set_half)
{
    INIT_GB;
    ASSERT_THAT(!GET_H(&gb));
    SET_H(gb);
    ASSERT_THAT(GET_H(&gb));
    UNSET_H(gb);
    ASSERT_THAT(!GET_H(&gb));
}
TEST(set_zero)
{
    INIT_GB;
    ASSERT_THAT(!GET_Z(&gb));
    SET_Z(gb);
    ASSERT_THAT(GET_Z(&gb));
    UNSET_Z(gb);
    ASSERT_THAT(!GET_Z(&gb));
}
TEST(set_neg)
{
    INIT_GB;
    ASSERT_THAT(!GET_N(&gb));
    SET_N(gb);
    ASSERT_THAT(GET_N(&gb));
    UNSET_N(gb);
    ASSERT_THAT(!GET_N(&gb));
}

TEST(get_carry)
{
    INIT_GB;
    ASSERT_THAT(!GET_C(&gb));
    gb.f |= 0x10;
    ASSERT_THAT(GET_C(&gb));
    gb.f &= 0x00;
    ASSERT_THAT(!GET_C(&gb));
}
TEST(get_half)
{
    INIT_GB;
    ASSERT_THAT(!GET_H(&gb));
    gb.f |= 0x20;
    ASSERT_THAT(GET_H(&gb));
    gb.f &= 0x00;
    ASSERT_THAT(!GET_H(&gb));
}
TEST(get_zero)
{
    INIT_GB;
    ASSERT_THAT(!GET_Z(&gb));
    gb.f |= 0x80;
    ASSERT_THAT(GET_Z(&gb));
    gb.f &= 0x00;
    ASSERT_THAT(!GET_Z(&gb));
}
TEST(get_neg)
{
    INIT_GB;
    ASSERT_THAT(!GET_N(&gb));
    gb.f |= 0x40;
    ASSERT_THAT(GET_N(&gb));
    gb.f &= 0x00;
    ASSERT_THAT(!GET_N(&gb));
}

TEST(_aiv_gb_set_flags_internal)
{
    INIT_GB;

    gb.a = 12;
    _aiv_gb_set_flags_internal(&gb, 10);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 0);
    ASSERT_THAT(gb.pc == 0);
}
TEST(_aiv_gb_set_flags_internal_carry)
{
    INIT_GB;

    gb.a = 12;
    _aiv_gb_set_flags_internal(&gb, 14);
    ASSERT_THAT(gb.a == 254);
    ASSERT_THAT(GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 0);
    ASSERT_THAT(gb.pc == 0);
}
TEST(_aiv_gb_set_flags_internal_half)
{
    INIT_GB;

    gb.a = 6;
    _aiv_gb_set_flags_internal(&gb, 10);
    ASSERT_THAT(gb.a == 252);
    ASSERT_THAT(GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 0);
    ASSERT_THAT(gb.pc == 0);
}
TEST(_aiv_gb_set_flags_internal_zero)
{
    INIT_GB;

    gb.a = 12;
    _aiv_gb_set_flags_internal(&gb, 12);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 0);
    ASSERT_THAT(gb.pc == 0);
}
TEST(opcode_90)
{
    INIT_GB;

    gb.cartridge[0] = 0x90;
    gb.b = 10;
    gb.a = 12;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_91)
{
    INIT_GB;
    gb.c = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x91;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_92)
{
    INIT_GB;
    gb.d = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x92;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_93)
{
    INIT_GB;
    gb.e = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x93;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(opcode_94)
{
    INIT_GB;
    gb.h = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x94;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_95)
{
    INIT_GB;
    gb.l = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x95;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_96)
{
    INIT_GB;
    gb.hl = 100;
    aiv_gb_memory_write8(&gb, gb.hl, 10);
    gb.a = 12;
    gb.cartridge[0] = 0x96;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_97)
{
    INIT_GB;

    gb.a = 12;
    gb.cartridge[0] = 0x97;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(opcode_98)
{
    INIT_GB;
    gb.b = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x98;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_99)
{
    INIT_GB;
    gb.c = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x99;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_9a)
{
    INIT_GB;
    gb.d = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9a;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_9b)
{
    INIT_GB;
    gb.e = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9b;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(opcode_9c)
{
    INIT_GB;
    gb.h = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9c;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_9d)
{
    INIT_GB;
    gb.l = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9d;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_9e)
{
    INIT_GB;
    gb.hl = 100;
    aiv_gb_memory_write8(&gb, gb.hl, 10);
    gb.a = 12;
    gb.cartridge[0] = 0x9e;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_9f)
{
    INIT_GB;

    gb.a = 12;
    gb.cartridge[0] = 0x9f;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(opcode_90_with_carry)
{
    INIT_GB;

    gb.cartridge[0] = 0x90;
    gb.b = 10;
    SET_C(gb);
    gb.a = 12;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_91_with_carry)
{
    INIT_GB;
    gb.c = 10;
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x91;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_92_with_carry)
{
    INIT_GB;
    gb.d = 10;
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x92;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_93_with_carry)
{
    INIT_GB;
    gb.e = 10;
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x93;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(opcode_94_with_carry)
{
    INIT_GB;
    gb.h = 10;
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x94;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_95_with_carry)
{
    INIT_GB;
    gb.l = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x95;
    SET_C(gb);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_96_with_carry)
{
    INIT_GB;
    gb.hl = 100;
    aiv_gb_memory_write8(&gb, gb.hl, 10);
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x96;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_97_with_carry)
{
    INIT_GB;

    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x97;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(opcode_98_with_carry)
{
    INIT_GB;
    gb.b = 10;
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x98;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_99_with_carry)
{
    INIT_GB;
    gb.c = 10;
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x99;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_9a_with_carry)
{
    INIT_GB;
    gb.d = 10;
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x9a;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_9b_with_carry)
{
    INIT_GB;
    gb.e = 10;
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x9b;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(opcode_9c_with_carry)
{
    INIT_GB;
    SET_C(gb);
    gb.h = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9c;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_9d_with_carry)
{
    INIT_GB;
    gb.l = 10;
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x9d;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_9e_with_carry)
{
    INIT_GB;
    gb.hl = 100;
    SET_C(gb);
    aiv_gb_memory_write8(&gb, gb.hl, 10);
    gb.a = 12;
    gb.cartridge[0] = 0x9e;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(!GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(!GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}
TEST(opcode_9f_with_carry)
{
    INIT_GB;
    SET_C(gb);
    gb.a = 12;
    gb.cartridge[0] = 0x9f;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 255);
    ASSERT_THAT(GET_C((&gb)));
    ASSERT_THAT(GET_N((&gb)));
    ASSERT_THAT(GET_H((&gb)));
    ASSERT_THAT(!GET_Z((&gb)));
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

void aiv_gb_tests_run_opcodes_90()
{
    RUN_TEST(set_carry_bool);
    RUN_TEST(set_half_bool);
    RUN_TEST(set_zero_bool);
    RUN_TEST(set_neg_bool);

    RUN_TEST(set_carry);
    RUN_TEST(set_half);
    RUN_TEST(set_zero);
    RUN_TEST(set_neg);

    RUN_TEST(get_carry);
    RUN_TEST(get_half);
    RUN_TEST(get_zero);
    RUN_TEST(get_neg);

    RUN_TEST(_aiv_gb_set_flags_internal);
    RUN_TEST(_aiv_gb_set_flags_internal_carry);
    RUN_TEST(_aiv_gb_set_flags_internal_half);
    RUN_TEST(_aiv_gb_set_flags_internal_zero);
    RUN_TEST(opcode_90);
    RUN_TEST(opcode_91);
    RUN_TEST(opcode_92);
    RUN_TEST(opcode_93);

    RUN_TEST(opcode_94);
    RUN_TEST(opcode_95);
    RUN_TEST(opcode_96);
    RUN_TEST(opcode_97);

    RUN_TEST(opcode_90_with_carry);
    RUN_TEST(opcode_91_with_carry);
    RUN_TEST(opcode_92_with_carry);
    RUN_TEST(opcode_93_with_carry);

    RUN_TEST(opcode_94_with_carry);
    RUN_TEST(opcode_95_with_carry);
    RUN_TEST(opcode_96_with_carry);
    RUN_TEST(opcode_97_with_carry);

    RUN_TEST(opcode_98);
    RUN_TEST(opcode_99);
    RUN_TEST(opcode_9a);
    RUN_TEST(opcode_9b);

    RUN_TEST(opcode_9c);
    RUN_TEST(opcode_9d);
    RUN_TEST(opcode_9e);
    RUN_TEST(opcode_9f);

    RUN_TEST(opcode_98_with_carry);
    RUN_TEST(opcode_99_with_carry);
    RUN_TEST(opcode_9a_with_carry);
    RUN_TEST(opcode_9b_with_carry);

    RUN_TEST(opcode_9c_with_carry);
    RUN_TEST(opcode_9d_with_carry);
    RUN_TEST(opcode_9e_with_carry);
    RUN_TEST(opcode_9f_with_carry);
}