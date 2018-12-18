#include <aiv_unit_test.h>
#include <aiv_gb.h>
#define SETUP_GB    \
    aiv_gameboy gb; \
    aiv_gb_init(&gb)

TEST(SLA_B)
{
    SETUP_GB;
    gb.b = 16;
    gb.cartridge[0] = 0x20;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.b == 32);
}

TEST(SLA_C)
{
    SETUP_GB;
    gb.c = 16;
    gb.cartridge[0] = 0x21;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.c == 32);
}

TEST(SLA_D)
{
    SETUP_GB;
    gb.d = 1;
    gb.cartridge[0] = 0x22;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.d == 2);
}

TEST(SLA_E)
{
    SETUP_GB;
    gb.e = 128;
    gb.cartridge[0] = 0x23;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.e == 0);
}

TEST(SLA_H)
{
    SETUP_GB;
    gb.h = 32;
    gb.cartridge[0] = 0x24;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.h == 64);
}

TEST(SLA_L)
{
    SETUP_GB;
    gb.l = 6;
    gb.cartridge[0] = 0x25;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.l == 12);
}

TEST(SLA_HL)
{
    SETUP_GB;
    gb.hl = 3584;
    gb.cartridge[0] = 0x26;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.hl == 7168);
}

TEST(SLA_A)
{
    SETUP_GB;
    gb.a = 4;
    gb.cartridge[0] = 0x27;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.a == 8);
}

TEST(SRA_B)
{
    SETUP_GB;
    gb.b = 16;
    gb.cartridge[0] = 0x28;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.b == 8);
}

TEST(SRA_C)
{
    SETUP_GB;
    gb.c = 16;
    gb.cartridge[0] = 0x29;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.c == 8);
}

TEST(SRA_D)
{
    SETUP_GB;
    gb.d = 64;
    gb.cartridge[0] = 0x2a;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.d == 32);
}

TEST(SRA_E)
{
    SETUP_GB;
    gb.e = 48;
    gb.cartridge[0] = 0x2b;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.e == 24);
}

TEST(SRA_H)
{
    SETUP_GB;
    gb.h = 32;
    gb.cartridge[0] = 0x2c;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.h == 16);
}

TEST(SRA_L)
{
    SETUP_GB;
    gb.l = 6;
    gb.cartridge[0] = 0x2d;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.l == 3);
}

TEST(SRA_HL)
{
    SETUP_GB;
    gb.hl = 3584;
    gb.cartridge[0] = 0x2e;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.hl == 1792);
}

TEST(SRA_A)
{
    SETUP_GB;
    gb.a = 1;
    gb.cartridge[0] = 0x2f;

    u8_t prefix = aiv_gb_memory_read8(&gb, gb.pc++);
    int ticks = gb.prefix_opcodes[prefix](&gb);
    gb.ticks += ticks;

    ASSERT_THAT(gb.a == 0);
}

void aiv_gb_tests_run_prefix_20()
{
    RUN_TEST(SLA_B);
    RUN_TEST(SLA_C);
    RUN_TEST(SLA_D);
    RUN_TEST(SLA_E);
    RUN_TEST(SLA_H);
    RUN_TEST(SLA_L);
    RUN_TEST(SLA_HL);
    RUN_TEST(SLA_A);

    RUN_TEST(SRA_B);
    RUN_TEST(SRA_C);
    RUN_TEST(SRA_D);
    RUN_TEST(SRA_E);
    RUN_TEST(SRA_H);
    RUN_TEST(SRA_L);
    RUN_TEST(SRA_HL);
    RUN_TEST(SRA_A);
}