#include <aiv_unit_test.h>
#include <aiv_gb.h>

#define GB_INIT       \
    aiv_gameboy gb;   \
    aiv_gb_init(&gb); 

#define ADD_A_B 0x80
#define ADD_A_C 0x81
#define ADD_A_D 0x82
#define ADD_A_E 0x83
#define ADD_A_H 0x84
#define ADD_A_L 0x85
#define ADD_A_HL 0x86
#define ADD_A_A 0x87

#define ADC_A_B 0x88
#define ADC_A_C 0x89
#define ADC_A_D 0x8a
#define ADC_A_E 0x8b
#define ADC_A_H 0x8c
#define ADC_A_L 0x8d
#define ADC_A_HL 0x8e
#define ADC_A_A 0x8f

TEST(check_add_ticks)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_B;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(check_add_a_b)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_B;

    gb.a = 2;
    gb.b = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_add_a_c)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_C;

    gb.a = 2;
    gb.c = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_add_a_d)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_D;

    gb.a = 2;
    gb.d = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_add_a_e)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_E;

    gb.a = 2;
    gb.e = 4;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 6);
}

TEST(check_add_a_h)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_H;

    gb.a = 2;
    gb.h = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_add_a_l)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_L;

    gb.a = 2;
    gb.l = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_add_a_a)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_A;

    gb.a = 2;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 4);
}

TEST(check_add_a_hl)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_HL;

    gb.a = 2;
    gb.hl = 300;
    aiv_gb_memory_write8(&gb, gb.hl, 3);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

//-------------------------------------

TEST(check_adc_a_b)
{
    GB_INIT
    gb.cartridge[0] = ADC_A_B;

    gb.a = 2;
    gb.b = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_adc_a_c)
{
    GB_INIT
    gb.cartridge[0] = ADC_A_C;

    gb.a = 2;
    gb.c = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_adc_a_d)
{
    GB_INIT
    gb.cartridge[0] = ADC_A_D;

    gb.a = 2;
    gb.d = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_adc_a_e)
{
    GB_INIT
    gb.cartridge[0] = ADC_A_E;

    gb.a = 2;
    gb.e = 4;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 6);
}

TEST(check_adc_a_h)
{
    GB_INIT
    gb.cartridge[0] = ADC_A_H;

    gb.a = 2;
    gb.h = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_adc_a_l)
{
    GB_INIT
    gb.cartridge[0] = ADC_A_L;

    gb.a = 2;
    gb.l = 3;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}

TEST(check_adc_a_a)
{
    GB_INIT
    gb.cartridge[0] = ADC_A_A;

    gb.a = 2;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 4);
}

TEST(check_adc_a_hl)
{
    GB_INIT
    gb.cartridge[0] = ADC_A_HL;

    gb.a = 2;
    //address
    gb.hl = 300;
    aiv_gb_memory_write8(&gb, gb.hl, 3);
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 5);
}
//----------------------------------

TEST(check_carry_flag)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_B;
    
    gb.a = 150;
    gb.b = 150;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a < 255); 
    ASSERT_THAT(gb.f == CARRY);
}

TEST(check_h_flag)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_B;
    
    gb.a = 8;
    gb.b = 8;

    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.f == HALF);
}

TEST(check_n_flag)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_B;

    gb.a = 2;
    gb.b = 4;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.f == 0x00);
}

TEST(check_zero_flag)
{
    GB_INIT
    gb.cartridge[0] = ADD_A_B;
   
    gb.a = 0;
    gb.b = 0;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.f == ZERO);
}


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
    RUN_TEST(check_adc_a_c);
    RUN_TEST(check_adc_a_d);
    RUN_TEST(check_adc_a_e);
    RUN_TEST(check_adc_a_h);
    RUN_TEST(check_adc_a_l);
    RUN_TEST(check_adc_a_hl);
    RUN_TEST(check_adc_a_a);
    RUN_TEST(check_carry_flag);
    RUN_TEST(check_zero_flag);
    RUN_TEST(check_n_flag);
    RUN_TEST(check_h_flag);
    PRINT_TEST_RESULTS();
}