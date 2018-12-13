#include <aiv_unit_test.h>
#include <aiv_gb.h>



TEST(ld_sp_d16){
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
TEST(inc_sp){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x33;
    aiv_gb_tick(&gb);

    ASSERT_THAT(gb.sp == 1);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 2);

    
}
TEST(inc_HL_value){

    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.cartridge[0] = 0x34;
    gb.hl = 1;
    u8_t val = aiv_gb_memory_read8(&gb,gb.hl);


    aiv_gb_tick(&gb);

    u8_t val2 = aiv_gb_memory_read8(&gb,gb.hl);
    
    ASSERT_THAT(val < val2);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 2);
    
}
TEST(dec_HL_value){

    aiv_gameboy gb;
    aiv_gb_init(&gb);
    
    gb.cartridge[0] = 0x35;
    gb.cartridge[1] = 0x02;

    gb.hl = 1;
    u8_t val = aiv_gb_memory_read8(&gb,gb.hl);

    aiv_gb_tick(&gb);

    u8_t val2 = aiv_gb_memory_read8(&gb,gb.hl);
    
    ASSERT_THAT(val > val2);
    ASSERT_THAT(gb.ticks == 12);
    ASSERT_THAT(gb.pc == 2);
}
void aiv_gb_tests_run_opcodes_30()
{
    RUN_TEST(ld_sp_d16);
    RUN_TEST(inc_sp);
    RUN_TEST(inc_HL_value);
    RUN_TEST(dec_HL_value);
    
}