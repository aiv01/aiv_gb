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

    u8_t value = aiv_gb_memory_read8(&gb, 0xFF01);
    printf("%d", value);

    ASSERT_THAT(value == gb.a);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 3);
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

    ASSERT_THAT(gb.hl == 0xff00);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 1);
}

TEST(ldh_c_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 17;
    gb.c = 0x50;

    gb.cartridge[0] = 0xe2;
    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_memory_read8(&gb, 0xFF50) == 17);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 1);
}

TEST(push_hl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    gb.hl = 0xd000;

    gb.cartridge[0] = 0xe5;
    aiv_gb_tick(&gb);
    u16_t value = aiv_gb_memory_read16(&gb, gb.sp + 1);

    ASSERT_THAT(value == 0xd000);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 16);
}

TEST(and_d8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;

    gb.cartridge[0] = 0xe6;
    gb.cartridge[1] = 0x09;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 8);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 2);
}

TEST(rst_20h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    gb.cartridge[0] = 0xe7;
    aiv_gb_tick(&gb);

    u16_t stored_opcode = aiv_gb_memory_read16(&gb, gb.sp + 1);

    ASSERT_THAT(stored_opcode == 1);
    ASSERT_THAT(gb.ticks == 16);
    ASSERT_THAT(gb.pc == 0x0020);
}

TEST(rst_28h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    gb.cartridge[0] = 0xeF;
    aiv_gb_tick(&gb);

    u16_t stored_opcode = aiv_gb_memory_read16(&gb, gb.sp + 1);

    ASSERT_THAT(stored_opcode == 1);
    ASSERT_THAT(gb.ticks == 16);
    ASSERT_THAT(gb.pc == 0x0028);
}

void aiv_gb_tests_run_opcodes_e0()
{
    RUN_TEST(ldh_n8_a);
    RUN_TEST(pop_hl);
    RUN_TEST(ldh_c_a);
    RUN_TEST(push_hl);
    RUN_TEST(and_d8);
    RUN_TEST(rst_20h);

    RUN_TEST(rst_28h);
}