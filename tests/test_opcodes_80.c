#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(check_add_ticks)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x80;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(check_add_a_b)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x80;

    gb.a = 2;
    gb.b = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_add_a_c)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x81;

    gb.a = 2;
    gb.c = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_add_a_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x82;

    gb.a = 2;
    gb.d = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_add_a_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x83;

    gb.a = 2;
    gb.e = 4;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 6);
}

TEST(check_add_a_h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x84;

    gb.a = 2;
    gb.h = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_add_a_l)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x85;

    gb.a = 2;
    gb.l = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_add_a_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x87;

    gb.a = 2;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 4);
}

TEST(check_add_a_hl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x86;

    gb.a = 2;
    gb.hl = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

//-------------------------------------

TEST(check_adc_a_b)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x88;

    gb.a = 2;
    gb.b = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_adc_a_c)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x89;

    gb.a = 2;
    gb.c = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_adc_a_d)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x8a;

    gb.a = 2;
    gb.d = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_adc_a_e)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x8b;

    gb.a = 2;
    gb.e = 4;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 6);
}

TEST(check_adc_a_h)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x8c;

    gb.a = 2;
    gb.h = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_adc_a_l)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x8d;

    gb.a = 2;
    gb.l = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_adc_a_a)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x8f;

    gb.a = 2;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 4);
}

TEST(check_adc_a_hl)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.cartridge[0] = 0x8e;

    gb.a = 2;
    gb.hl = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}
//----------------------------------

void aiv_gb_tests_run_opcodes_80()
{
    RUN_TEST(check_add_ticks);
    RUN_TEST(check_add_a_b);
    RUN_TEST(check_add_a_c);
    RUN_TEST(check_add_a_d);
    RUN_TEST(check_add_a_e);
    RUN_TEST(check_add_a_h);
    RUN_TEST(check_add_a_l);
    RUN_TEST(check_add_a_hl);
    RUN_TEST(check_add_a_a);
    RUN_TEST(check_adc_a_b);
    RUN_TEST(check_add_a_c);
    RUN_TEST(check_adc_a_d);
    RUN_TEST(check_adc_a_e);
    RUN_TEST(check_adc_a_h);
    RUN_TEST(check_adc_a_l);
    RUN_TEST(check_adc_a_hl);
    RUN_TEST(check_adc_a_a);

    PRINT_TEST_RESULTS();
}