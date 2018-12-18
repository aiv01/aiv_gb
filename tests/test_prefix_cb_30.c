#include <aiv_unit_test.h>
#include <aiv_gb.h>
#define SETUP_GB    \
    aiv_gameboy gb; \
    aiv_gb_init(&gb)

TEST(SWAP_B)
{
    SETUP_GB;
    gb.b = 16;
    gb.cartridge[0] = 0x30;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.b == 1);
}

TEST(SWAP_C)
{
    SETUP_GB;
    gb.c = 16;
    gb.cartridge[0] = 0x31;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.c == 1);
}

TEST(SWAP_D)
{
    SETUP_GB;
    gb.d = 1;
    gb.cartridge[0] = 0x32;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.d == 16);
}

TEST(SWAP_E)
{
    SETUP_GB;
    gb.e = 128;
    gb.cartridge[0] = 0x33;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.e == 8);
}

TEST(SWAP_H)
{
    SETUP_GB;
    gb.h = 32;
    gb.cartridge[0] = 0x34;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.h == 2);
}

TEST(SWAP_L)
{
    SETUP_GB;
    gb.l = 6;
    gb.cartridge[0] = 0x35;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.l == 96);
}

TEST(SWAP_HL)
{
    SETUP_GB;
    gb.hl = 256;
    gb.cartridge[0] = 0x36;


    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;


    ASSERT_THAT(gb.hl == 4096);
}

TEST(SWAP_A)
{
    SETUP_GB;
    gb.a = 4;
    gb.cartridge[0] = 0x37;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.a == 64);
}

TEST(SRL_B)
{
    SETUP_GB;
    gb.b = 16;
    gb.cartridge[0] = 0x38;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.b == 8);
}

TEST(SRL_C)
{
    SETUP_GB;
    gb.c = 16;
    gb.cartridge[0] = 0x39;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.c == 8);
}

TEST(SRL_D)
{
    SETUP_GB;
    gb.d = 64;
    gb.cartridge[0] = 0x3a;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.d == 32);
}

TEST(SRL_E)
{
    SETUP_GB;
    gb.e = 48;
    gb.cartridge[0] = 0x3b;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.e == 24);
}

TEST(SRL_H)
{
    SETUP_GB;
    gb.h = 32;
    gb.cartridge[0] = 0x3c;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.h == 16);
}

TEST(SRL_L)
{
    SETUP_GB;
    gb.l = 6;
    gb.cartridge[0] = 0x3d;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.l == 3);
}

TEST(SRL_HL)
{
    SETUP_GB;
    gb.hl = 3584;
    gb.cartridge[0] = 0x3e;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.hl == 1792);
}

TEST(SRL_A)
{
    SETUP_GB;
    gb.a = 1;
    gb.cartridge[0] = 0x3f;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.a == 0);
}

void aiv_gb_tests_run_prefix_30()
{
    RUN_TEST(SWAP_B);
    RUN_TEST(SWAP_C);
    RUN_TEST(SWAP_D);
    RUN_TEST(SWAP_E);
    RUN_TEST(SWAP_H);
    RUN_TEST(SWAP_L);
    RUN_TEST(SWAP_HL);
    RUN_TEST(SWAP_A);

    RUN_TEST(SRL_B);
    RUN_TEST(SRL_C);
    RUN_TEST(SRL_D);
    RUN_TEST(SRL_E);
    RUN_TEST(SRL_H);
    RUN_TEST(SRL_L);
    RUN_TEST(SRL_HL);
    RUN_TEST(SRL_A);
}