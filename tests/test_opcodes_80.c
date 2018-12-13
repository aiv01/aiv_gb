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

void aiv_gb_tests_run_opcodes_80()
{
    RUN_TEST(check_add_ticks);
   RUN_TEST(check_add_a_b);
   PRINT_TEST_RESULTS();
}