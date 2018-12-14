#include <aiv_unit_test.h>
#include <aiv_gb.h>
extern void _aiv_gb_sub_internal(aiv_gameboy *gb, u8_t to_sub);
#define INIT_GB       \
    aiv_gameboy gb;   \
    aiv_gb_init(&gb); \
    aiv_gb_set_flag(&gb, CARRY, 1);

TEST(_aiv_gb_sub)
{
    INIT_GB;
    aiv_gb_set_flag(&gb, CARRY, 0);
    gb.a = 12;
    _aiv_gb_sub_internal(&gb, 10);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 0);
    ASSERT_THAT(gb.pc == 0);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(_aiv_gb_sub_with_carry)
{
    INIT_GB;
    gb.a = 12;
    _aiv_gb_sub_internal(&gb, 10 + (aiv_gb_get_flag(&gb, CARRY) != 0));
    ASSERT_THAT(gb.a == 1);
    ASSERT_THAT(gb.ticks == 0);
    ASSERT_THAT(gb.pc == 0);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(_aiv_gb_sub_with_zero)
{
    INIT_GB;
    gb.a = 14;
    _aiv_gb_sub_internal(&gb, 13 + (aiv_gb_get_flag(&gb, CARRY) != 0));
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 0);
    ASSERT_THAT(gb.pc == 0);
    ASSERT_THAT(gb.f == (NEG | ZERO));
}
TEST(_aiv_gb_sub_with_half)
{
    INIT_GB;
    gb.a = 12;
    _aiv_gb_sub_internal(&gb, 12 + (aiv_gb_get_flag(&gb, CARRY) != 0));
    ASSERT_THAT(gb.a == 255);
    ASSERT_THAT(gb.ticks == 0);
    ASSERT_THAT(gb.pc == 0);
    ASSERT_THAT(gb.f == (NEG | CARRY | HALF));
}
TEST(_aiv_gb_sub_with_no_half)
{
    INIT_GB;
    gb.a = 2;
    _aiv_gb_sub_internal(&gb, 254 + (aiv_gb_get_flag(&gb, CARRY) != 0));
    ASSERT_THAT(gb.a == 3);
    ASSERT_THAT(gb.ticks == 0);
    ASSERT_THAT(gb.pc == 0);
    ASSERT_THAT(gb.f == (NEG | CARRY));
}
TEST(opcode_90)
{
    INIT_GB;

    gb.cartridge[0] = 0x90;
    gb.b = 10;
    gb.a = 12;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_91)
{
    INIT_GB;
    gb.c = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x91;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_92)
{
    INIT_GB;
    gb.d = 12;
    gb.a = 12;
    gb.cartridge[0] = 0x92;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG | ZERO));
}
TEST(opcode_93)
{
    INIT_GB;
    gb.e = 15;
    gb.a = 12;
    gb.cartridge[0] = 0x93;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 253);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG | CARRY | HALF));
}

TEST(opcode_94)
{
    INIT_GB;
    gb.h = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x94;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_95)
{
    INIT_GB;
    gb.l = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x95;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
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
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_97)
{
    INIT_GB;

    gb.a = 12;
    gb.cartridge[0] = 0x97;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG | ZERO));
}

TEST(opcode_98)
{
    INIT_GB;
    gb.b = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x98;
    aiv_gb_set_flag(&gb, CARRY, 0);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_99)
{
    INIT_GB;
    gb.c = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x99;
    aiv_gb_set_flag(&gb, CARRY, 0);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_9a)
{
    INIT_GB;
    gb.d = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9a;
    aiv_gb_set_flag(&gb, CARRY, 0);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_9b)
{
    INIT_GB;
    gb.e = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9b;
    aiv_gb_set_flag(&gb, CARRY, 0);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}

TEST(opcode_9c)
{
    INIT_GB;
    gb.h = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9c;
    aiv_gb_set_flag(&gb, CARRY, 0);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_9d)
{
    INIT_GB;
    gb.l = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9d;
    aiv_gb_set_flag(&gb, CARRY, 0);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_9e)
{
    INIT_GB;
    gb.hl = 100;
    aiv_gb_memory_write8(&gb, gb.hl, 10);
    gb.a = 12;
    gb.cartridge[0] = 0x9e;
    aiv_gb_set_flag(&gb, CARRY, 0);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_9f)
{
    INIT_GB;

    gb.a = 12;
    gb.cartridge[0] = 0x9f;
    aiv_gb_set_flag(&gb, CARRY, 0);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG | ZERO));
}

TEST(opcode_90_with_carry)
{
    INIT_GB;

    gb.cartridge[0] = 0x90;
    gb.b = 10;
    gb.a = 12;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_91_with_carry)
{
    INIT_GB;
    gb.c = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x91;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_92_with_carry)
{
    INIT_GB;
    gb.d = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x92;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_93_with_carry)
{
    INIT_GB;
    gb.e = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x93;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}

TEST(opcode_94_with_carry)
{
    INIT_GB;
    gb.h = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x94;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_95_with_carry)
{
    INIT_GB;
    gb.l = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x95;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_96_with_carry)
{
    INIT_GB;
    gb.hl = 100;
    aiv_gb_memory_write8(&gb, gb.hl, 10);
    gb.a = 12;
    gb.cartridge[0] = 0x96;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_97_with_carry)
{
    INIT_GB;

    gb.a = 12;
    gb.cartridge[0] = 0x97;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG | ZERO));
}

TEST(opcode_98_with_carry)
{
    INIT_GB;
    gb.b = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x98;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_99_with_carry)
{
    INIT_GB;
    gb.c = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x99;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_9a_with_carry)
{
    INIT_GB;
    gb.d = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9a;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_9b_with_carry)
{
    INIT_GB;
    gb.e = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9b;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}

TEST(opcode_9c_with_carry)
{
    INIT_GB;
    gb.h = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9c;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_9d_with_carry)
{
    INIT_GB;
    gb.l = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x9d;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 1);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_9e_with_carry)
{
    INIT_GB;
    gb.hl = 100;
    aiv_gb_memory_write8(&gb, gb.hl, 10);
    gb.a = 12;
    gb.cartridge[0] = 0x9e;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 1);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG));
}
TEST(opcode_9f_with_carry)
{
    INIT_GB;

    gb.a = 12;
    gb.cartridge[0] = 0x9f;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 255);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.f == (NEG | CARRY | HALF));
}

void aiv_gb_tests_run_opcodes_90()
{
    RUN_TEST(_aiv_gb_sub);
    RUN_TEST(_aiv_gb_sub_with_carry);
    RUN_TEST(_aiv_gb_sub_with_zero);
    RUN_TEST(_aiv_gb_sub_with_half);
    RUN_TEST(_aiv_gb_sub_with_no_half);
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
