#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(pop_de)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    aiv_gb_memory_write16(&gb, gb.sp - 1, 0xd000);
    gb.sp -= 2;

    gb.cartridge[0] = 0xd1;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.de == 0xd000);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 12);
}

TEST(jp_nc_a16)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0xd2;
    gb.cartridge[1] = 0x80;
    gb.cartridge[2] = 0x80;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 0x8080);
    ASSERT_THAT(gb.ticks == 16);
}

TEST(jp_nc_a16_red_light)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    aiv_gb_set_flag(&gb, CARRY, 1);

    gb.cartridge[0] = 0xd2;
    gb.cartridge[1] = 0x80;
    gb.cartridge[2] = 0x80;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 3);
    ASSERT_THAT(gb.ticks == 12);
}

TEST(ret_nc)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    aiv_gb_memory_write16(&gb, gb.sp - 1, 0xd000);
    gb.sp -= 2;

    gb.cartridge[0] = 0xd0;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 0xd000);
    ASSERT_THAT(gb.ticks == 20);
}

TEST(ret_nc_red_light)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    aiv_gb_set_flag(&gb, CARRY, 1);

    aiv_gb_memory_write16(&gb, gb.sp - 1, 0xd000);
    gb.sp -= 2;

    gb.cartridge[0] = 0xd0;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 8);
}

TEST(call_nc_a16)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    gb.cartridge[0] = 0xd4;
    gb.cartridge[1] = 0x80;
    gb.cartridge[2] = 0x80;
    gb.cartridge[3] = 0xd0;
    aiv_gb_tick(&gb);

    u8_t next_opcode = aiv_gb_memory_read8(&gb, gb.cartridge[gb.sp + 1]);

    ASSERT_THAT(next_opcode == 0xd0);
    ASSERT_THAT(gb.pc == 0x8080);
    ASSERT_THAT(gb.ticks == 24);
}

TEST(call_nc_a16_red_light)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    aiv_gb_set_flag(&gb, CARRY, 1);

    gb.cartridge[0] = 0xd4;
    gb.cartridge[1] = 0x80;
    gb.cartridge[2] = 0x80;
    gb.cartridge[3] = 0xd0;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 3);
    ASSERT_THAT(gb.ticks == 12);
}

TEST(push_de)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    gb.de = 0xd000;

    gb.cartridge[0] = 0xd5;
    aiv_gb_tick(&gb);

    u16_t value = aiv_gb_memory_read16(&gb, gb.sp + 1);
    ASSERT_THAT(value == 0xd000);
    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 16);
}

TEST(sub_d8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 5;

    gb.cartridge[0] = 0xd6;
    gb.cartridge[1] = 0x04;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 2);
    ASSERT_THAT(gb.a == 1);

    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == NEG);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == CARRY);
}

TEST(sub_d8_zero)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 4;

    gb.cartridge[0] = 0xd6;
    gb.cartridge[1] = 0x04;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 2);
    ASSERT_THAT(gb.a == 0);

    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == ZERO);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == NEG);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == CARRY);
}

TEST(sub_d8_overflow)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 4;

    gb.cartridge[0] = 0xd6;
    gb.cartridge[1] = 0x05;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 2);
    ASSERT_THAT(gb.a == 255);

    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == NEG);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == HALF);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == 0);
}

TEST(ret_c)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    aiv_gb_set_flag(&gb, CARRY, 1);

    aiv_gb_memory_write16(&gb, gb.sp - 1, 0xd000);
    gb.sp -= 2;

    gb.cartridge[0] = 0xd8;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 0xd000);
    ASSERT_THAT(gb.ticks == 20);
}

TEST(ret_c_red_light)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp = 0xff;

    aiv_gb_memory_write16(&gb, gb.sp - 1, 0xd000);
    gb.sp -= 2;

    gb.cartridge[0] = 0xd8;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 1);
    ASSERT_THAT(gb.ticks == 8);
}

TEST(jp_c_a16)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    aiv_gb_set_flag(&gb, CARRY, 1);

    gb.cartridge[0] = 0xda;
    gb.cartridge[1] = 0x80;
    gb.cartridge[2] = 0x80;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 0x8080);
    ASSERT_THAT(gb.ticks == 16);
}

TEST(jp_c_a16_red_light)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0xda;
    gb.cartridge[1] = 0x80;
    gb.cartridge[2] = 0x80;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.pc == 3);
    ASSERT_THAT(gb.ticks == 12);
}

void aiv_gb_tests_run_opcodes_d0()
{
    RUN_TEST(pop_de);

    RUN_TEST(jp_nc_a16);
    RUN_TEST(jp_nc_a16_red_light);

    RUN_TEST(ret_nc);
    RUN_TEST(ret_nc_red_light);

    RUN_TEST(call_nc_a16);
    RUN_TEST(call_nc_a16_red_light);

    RUN_TEST(push_de);

    RUN_TEST(sub_d8);
    RUN_TEST(sub_d8_zero);
    RUN_TEST(sub_d8_overflow);

    RUN_TEST(ret_c);
    RUN_TEST(ret_c_red_light);

    RUN_TEST(jp_c_a16);
    RUN_TEST(jp_c_a16_red_light);
}