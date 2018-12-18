#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(ld_sp_d16)
{
    printf("Stirlani");
    aiv_gameboy gb;

    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x31;
    gb.cartridge[1] = 0x01;
    gb.cartridge[2] = 0x02;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.sp == 0x0201);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 3);
}
TEST(inc_sp)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x33;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.sp == 1);
    ASSERT_THAT(gb.ticks == 8);
}
TEST(inc_HL_value)
{
    printf("Stirlani");

    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x34;
    gb.hl = 1;
    u8_t val = aiv_gb_memory_read8(&gb, gb.hl);

    aiv_gb_tick(&gb);

    u8_t val2 = aiv_gb_memory_read8(&gb, gb.hl);

    ASSERT_THAT(val < val2);
    ASSERT_THAT(gb.ticks == 12);
    u8_t flag = aiv_gb_get_flag(&gb, NEG);
    ASSERT_THAT(flag == 0);
}
TEST(inc_HL_value_zero)
{
    printf("Stirlani");

    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x34;
    gb.cartridge[1] = 0xff;
    gb.hl = 1;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.ticks == 12);
    u8_t flag = aiv_gb_get_flag(&gb, ZERO);
    ASSERT_THAT(flag == 128);
}
TEST(inc_HL_value_half_zero)
{
    printf("Stirlani");

    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x34;
    gb.cartridge[1] = 0x0f;
    gb.hl = 1;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.ticks == 12);
    u8_t flag = aiv_gb_get_flag(&gb, HALF);
    ASSERT_THAT(flag == 32);
}
TEST(dec_HL_value)
{
    printf("Stirlani");

    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x35;
    gb.cartridge[1] = 0x02;

    gb.hl = 1;
    u8_t val = aiv_gb_memory_read8(&gb, gb.hl);

    aiv_gb_tick(&gb);

    u8_t val2 = aiv_gb_memory_read8(&gb, gb.hl);
    printf("%i", val2);

    ASSERT_THAT(val > val2);
    ASSERT_THAT(gb.ticks == 12);
    u8_t flag = aiv_gb_get_flag(&gb, NEG);
    ASSERT_THAT(flag == 64);
}
TEST(dec_HL_value_zero)
{
    printf("Stirlani: ");

    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x35;
    gb.cartridge[1] = 0x01;

    gb.hl = 1;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.ticks == 12);

    u8_t flag = aiv_gb_get_flag(&gb, ZERO);
    ASSERT_THAT(flag == 128);
}
TEST(dec_HL_value_half_zero)
{
    printf("Stirlani: ");

    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x35;
    gb.cartridge[1] = 0xaf;

    gb.hl = 1;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.ticks == 12);

    u8_t flag = aiv_gb_get_flag(&gb, HALF);
    ASSERT_THAT(flag == 32);
}
TEST(jr)
{
    printf("Stirlani: ");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x30;
    gb.cartridge[1] = 0x01;
    gb.cartridge[2] = 0x02;
    aiv_gb_tick(&gb);
}
TEST(ld_hl_dec_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.a = 1;
    gb.hl = 2;
    gb.cartridge[0] = 0x32;
    gb.cartridge[1] = 0x02;
    gb.cartridge[2] = 0x04;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.hl == 1);
    ASSERT_THAT(gb.hl + 1 == 2);
}
TEST(LD_HL_d8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.hl = 1;
    gb.cartridge[0] = 0x36;
    gb.cartridge[1] = 0x47;
    gb.cartridge[2] = 0x01;

    aiv_gb_tick(&gb);
    printf("%i", gb.hl);
    ASSERT_THAT(gb.hl == 1)
}
TEST(SCF)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x37;

    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == 16);
}
TEST(ADD_HL_SP_test)
{

    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x39;
    gb.cartridge[1] = 0x01;
    gb.cartridge[2] = 0x02;
    gb.cartridge[3] = 0x03;
    gb.hl = 1;
    gb.sp = 1;

    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
    ASSERT_THAT(gb.hl == 2);
}
TEST(ADD_HL_SP_test_carry)
{

    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x39;
    gb.cartridge[1] = 0x01;
    gb.cartridge[2] = 0x02;
    gb.cartridge[3] = 0x03;
    gb.hl = 0xffff;
    gb.sp = 0x0001;

    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_get_flag(&gb, CARRY) == 16);
}
TEST(LD_A_HL_test)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3a;
    gb.cartridge[1] = 0x01;
    gb.cartridge[2] = 0x02;
    gb.cartridge[3] = 0x03;

    gb.hl = 2;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.hl == 1);
    ASSERT_THAT(gb.a == 2);
}
TEST(dec_sp_test)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3b;
    gb.sp = 3;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.sp == 2);
    ASSERT_THAT(gb.ticks == 8);
}
TEST(inc_a_test)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3c;
    gb.a = 3;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 4);
    ASSERT_THAT(gb.ticks == 4);
}
TEST(inc_a_test_neg)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3c;
    gb.a = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 0);
}
TEST(inc_a_test_zero)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3c;
    gb.a = 0xff;
    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 128);
}
TEST(inc_a_test_half)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3c;
    gb.a = 0x0f;
    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 32);
}

TEST(dec_a_test)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3d;
    gb.a = 3;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
}
TEST(dec_a_test_neg)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3d;
    gb.a = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_get_flag(&gb, NEG) == 64);
}
TEST(dec_a_test_zero)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3d;
    gb.a = 0x01;
    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_get_flag(&gb, ZERO) == 128);
}
TEST(dec_a_test_half)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3d;
    gb.a = 0x00;
    aiv_gb_tick(&gb);
    ASSERT_THAT(aiv_gb_get_flag(&gb, HALF) == 32);
}
TEST(CCF_test_carry_unset)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    aiv_gb_set_flag(&gb, CARRY, 1);

    gb.cartridge[0] = 0x3f;

    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_get_flag(&gb,CARRY) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb,HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb,NEG) == 0);
}
TEST(CCF_test_carry_set)
{
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    aiv_gb_set_flag(&gb, CARRY, 0);

    gb.cartridge[0] = 0x3f;

    aiv_gb_tick(&gb);

    ASSERT_THAT(aiv_gb_get_flag(&gb,CARRY) == 16);
    ASSERT_THAT(aiv_gb_get_flag(&gb,HALF) == 0);
    ASSERT_THAT(aiv_gb_get_flag(&gb,NEG) == 0);
}
TEST(ld_on_a_register_a_value){
    printf("Stirlani");
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x3e;
    gb.cartridge[1] = 0x05;
    gb.cartridge[2] = 0x66;
    gb.cartridge[3] = 0x88;

    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 5);
    ASSERT_THAT(gb.sp == 1);
    ASSERT_THAT(gb.ticks == 8);
}
void aiv_gb_tests_run_opcodes_30()
{
    RUN_TEST(ld_sp_d16);
    RUN_TEST(inc_sp);
    RUN_TEST(inc_HL_value);
    RUN_TEST(inc_HL_value_zero);
    RUN_TEST(inc_HL_value_half_zero);
    RUN_TEST(dec_HL_value);
    RUN_TEST(dec_HL_value_zero);
    RUN_TEST(dec_HL_value_half_zero);
    RUN_TEST(jr);
    RUN_TEST(ld_hl_dec_a);
    RUN_TEST(LD_HL_d8);
    RUN_TEST(SCF);
    RUN_TEST(ADD_HL_SP_test);
    RUN_TEST(ADD_HL_SP_test_carry);
    RUN_TEST(LD_A_HL_test);
    RUN_TEST(dec_sp_test);
    RUN_TEST(inc_a_test);
    RUN_TEST(inc_a_test_neg);
    RUN_TEST(inc_a_test_zero);
    RUN_TEST(inc_a_test_half);
    RUN_TEST(dec_a_test);
    RUN_TEST(dec_a_test_neg);
    RUN_TEST(dec_a_test_zero);
    RUN_TEST(dec_a_test_half);
    RUN_TEST(CCF_test_carry_unset);
    RUN_TEST(CCF_test_carry_set);
    RUN_TEST(ld_on_a_register_a_value);
}