#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(ld_de_d16)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x11;
    gb.cartridge[1] = 210;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.de == 210);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 3);
}

TEST(ld_addr_in_de)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.a = 17;

    gb.cartridge[0] = 0x12;
    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_memory_read16(&gb,gb.de) == 17);
  //  ASSERT_THAT(gb.ticks == 8);
   // ASSERT_THAT(gb.pc == 1);
}

TEST(incr_de)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.de = 0x01;
    gb.cartridge[0] = 0x13;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.de == 0x02);
}

TEST(incr_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.d = 1;
    gb.cartridge[0] = 0x14;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.d == 2);
}

TEST(decr_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.d = 1;
    gb.cartridge[0] = 0x15;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.d == 0);
}

TEST(ld_d_d8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x16;
    gb.cartridge[1] = 210;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.d == 210);
    //ASSERT_THAT(gb.ticks == 12);
    // ASSERT_THAT(gb.pc == 3);
}

TEST(rtate_left_addr)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x17;
    gb.a = 2; ////11010010
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 4); //10100101
}

TEST(jmp_relative_r8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x18;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.pc == 2);
}
TEST(add_hl_de)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.hl = 0x01;
    gb.de = 0x01;
    gb.cartridge[0] = 0x19;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.hl == 0x02);
}

TEST(ld_de_in_addr)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x1a;
    gb.de = 100;
    aiv_gb_memory_write8(&gb,gb.de,2);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2);
}

TEST(dec_de)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.de = 0x02;
    gb.cartridge[0] = 0x1b;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.de == 0x01);
}

TEST(incr_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.e = 1;
    gb.cartridge[0] = 0x1c;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.e == 2);
}

TEST(decr_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.e = 1;
    gb.cartridge[0] = 0x1d;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.e == 0);
}

TEST(ld_e_d8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x1e;
    gb.cartridge[1] = 63;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.e == 63);
}

TEST(rtate_right_addr)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x1f;
    gb.a = 4; 
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 2); 
}

void aiv_gb_tests_run_opcodes_10()
{
    RUN_TEST(ld_de_d16);
    RUN_TEST(ld_addr_in_de);
    RUN_TEST(incr_de);
    RUN_TEST(incr_d);
    RUN_TEST(decr_d);
    RUN_TEST(ld_d_d8);
    RUN_TEST(rtate_left_addr);
    RUN_TEST(jmp_relative_r8);
    RUN_TEST(add_hl_de);
    RUN_TEST(ld_de_in_addr);
    RUN_TEST(dec_de);
    RUN_TEST(incr_e);
    RUN_TEST(decr_e);
    RUN_TEST(ld_e_d8);
    RUN_TEST(rtate_right_addr);
}
