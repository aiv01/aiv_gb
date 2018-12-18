#include <aiv_unit_test.h>
#include <aiv_gb.h>
#define SETUP_GB    \
    aiv_gameboy gb; \
    aiv_gb_init(&gb)

TEST(RL_B)
{
    SETUP_GB;
    gb.b = 16;
    gb.cartridge[0] = 0x10;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.b == 48);
}

TEST(RL_C)
{
    SETUP_GB;
    gb.c = 16;
    gb.cartridge[0] = 0x11;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.c == 48);
}

TEST(RL_D)
{
    SETUP_GB;
    gb.d = 1;
    gb.cartridge[0] = 0x12;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.d == 18);
}

TEST(RL_E)
{
    SETUP_GB;
    gb.e = 48;
    gb.cartridge[0] = 0x13;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.e == 112);
}

TEST(RL_H)
{
    SETUP_GB;
    gb.h = 32;
    gb.cartridge[0] = 0x14;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.h == 80);
}

TEST(RL_L)
{
    SETUP_GB;
    gb.l = 6;
    gb.cartridge[0] = 0x15;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.l == 28);
}

TEST(RL_HL)
{
    SETUP_GB;
    gb.hl = 3584;
    gb.cartridge[0] = 0x16;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.hl == 7184);
}

TEST(RL_A)
{
    SETUP_GB;
    gb.a = 4;
    gb.cartridge[0] = 0x17;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.a == 24);
}

TEST(RR_B)
{
    SETUP_GB;
    gb.b = 16;
    gb.cartridge[0] = 0x18;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.b == 8);
}

TEST(RR_C)
{
    SETUP_GB;
    gb.c = 16;
    gb.cartridge[0] = 0x19;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.c == 8);
}

TEST(RR_D)
{
    SETUP_GB;
    gb.d = 1;
    gb.cartridge[0] = 0x1a;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;


    ASSERT_THAT(gb.d == 0);
}

TEST(RR_E)
{
    SETUP_GB;
    gb.e = 48;
    gb.cartridge[0] = 0x1b;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.e == 24);
}

TEST(RR_H)
{
    SETUP_GB;
    gb.h = 32;
    gb.cartridge[0] = 0x1c;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.h == 16);
}

TEST(RR_L)
{
    SETUP_GB;
    gb.l = 6;
    gb.cartridge[0] = 0x1d;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.l == 3);
}

TEST(RR_HL)
{
    SETUP_GB;
    gb.hl = 3584;
    gb.cartridge[0] = 0x1e;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.hl == 1792);
}

TEST(RR_A)
{
    SETUP_GB;
    gb.a = 4;
    gb.cartridge[0] = 0x1f;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.a == 2);
}

void aiv_gb_tests_run_prefix_10()
{
    RUN_TEST(RL_B);
    RUN_TEST(RL_C);
    RUN_TEST(RL_D);
    RUN_TEST(RL_E);
    RUN_TEST(RL_H);
    RUN_TEST(RL_L);
    RUN_TEST(RL_HL);
    RUN_TEST(RL_A);

    RUN_TEST(RR_B);
    RUN_TEST(RR_C);
    RUN_TEST(RR_D);
    RUN_TEST(RR_E);
    RUN_TEST(RR_H);
    RUN_TEST(RR_L);
    RUN_TEST(RR_HL);
    RUN_TEST(RR_A);
}