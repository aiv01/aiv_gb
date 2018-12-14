#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(or_a_b)
{
    //initialize gameboy
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    //set in your cartridge your op-code
    gb.cartridge[0] = 0xb0;
    //initialize values in a and b
    gb.a = 0x05;
    gb.b = 0x09;
    //give a tick to your gb, in order to do one tick
    aiv_gb_tick(&gb);
    ASSERT_THAT((gb.a | gb.b) == 0xd);

}
void aiv_gb_tests_run_opcodes_b0()
{
    RUN_TEST(or_a_b);
    
}