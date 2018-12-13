#include <aiv_unit_test.h>
#include <aiv_gb.h>

#define INIT_GB     \
    aiv_gameboy gb; \
    aiv_gb_init(&gb)

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
}
TEST(opcode_92)
{
    INIT_GB;
    gb.d = 10;
    gb.a = 12;
    gb.cartridge[0] = 0x92;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
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
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

void aiv_gb_tests_run_opcodes_90()
{

    RUN_TEST(opcode_90);
    RUN_TEST(opcode_91);
    RUN_TEST(opcode_92);
    RUN_TEST(opcode_93);

    RUN_TEST(opcode_94);
    RUN_TEST(opcode_95);
    RUN_TEST(opcode_96);
    RUN_TEST(opcode_97);

    RUN_TEST(opcode_98);
    RUN_TEST(opcode_99);
    RUN_TEST(opcode_9a);
    RUN_TEST(opcode_9b);

    RUN_TEST(opcode_9c);
    RUN_TEST(opcode_9d);
    RUN_TEST(opcode_9e);
    RUN_TEST(opcode_9f);
}