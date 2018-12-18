#include <aiv_unit_test.h>
#include <aiv_gb.h>

//TESTED ALL OPCODES, GREENLIGHT TEST ONLY SHOULD BE ENOUGH, WILL ADD REDLIGHT IF NEEDED.

TEST(and_b_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 2;
    gb.b = 10;

    gb.cartridge[0] = 0xA0;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 2);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 0);
}
TEST(and_b_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.b = 15;

    gb.cartridge[0] = 0xA0;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 8);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(and_c_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 0;
    gb.c = 10;

    gb.cartridge[0] = 0xA1;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(and_c_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.c = 255;

    gb.cartridge[0] = 0xA1;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 24);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(and_d_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 0;
    gb.d = 10;

    gb.cartridge[0] = 0xA2;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(and_d_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.d = 255;

    gb.cartridge[0] = 0xA2;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 24);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(and_e_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 0;
    gb.e = 10;

    gb.cartridge[0] = 0xA3;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(and_e_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.e = 255;

    gb.cartridge[0] = 0xA3;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 24);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(and_h_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 0;
    gb.h = 10;

    gb.cartridge[0] = 0xA4;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(and_h_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.h = 255;

    gb.cartridge[0] = 0xA4;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 24);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(and_l_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 0;
    gb.l = 10;

    gb.cartridge[0] = 0xA5;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(and_l_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.l = 255;

    gb.cartridge[0] = 0xA5;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 24);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(and_hl_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 0;
    gb.hl = 10;

    gb.cartridge[0] = 0xA6;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}
TEST(and_hl_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.hl = 255;

    gb.cartridge[0] = 0xA6;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 24);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(and_a_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 0;

    gb.cartridge[0] = 0xA7;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(and_a_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;

    gb.cartridge[0] = 0xA7;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & HALF) == HALF);
    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 24);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(xor_b_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;
    gb.b = 10;

    gb.cartridge[0] = 0xA8;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(xor_b_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.b = 15;

    gb.cartridge[0] = 0xA8;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 23);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(xor_c_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;
    gb.c = 10;

    gb.cartridge[0] = 0xA9;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(xor_c_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.c = 15;

    gb.cartridge[0] = 0xA9;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 23);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(xor_d_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;
    gb.d = 10;

    gb.cartridge[0] = 0xAA;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(xor_d_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.d = 15;

    gb.cartridge[0] = 0xAA;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 23);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(xor_e_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;
    gb.e = 10;

    gb.cartridge[0] = 0xAB;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(xor_e_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.e = 15;

    gb.cartridge[0] = 0xAB;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 23);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(xor_h_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;
    gb.h = 10;

    gb.cartridge[0] = 0xAC;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(xor_h_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.h = 15;

    gb.cartridge[0] = 0xAC;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 23);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(xor_l_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;
    gb.l = 10;

    gb.cartridge[0] = 0xAD;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(xor_l_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.l = 15;

    gb.cartridge[0] = 0xAD;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 23);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

TEST(xor_hl_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;
    gb.hl = 10;

    gb.cartridge[0] = 0xAE;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}
TEST(xor_hl_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.hl = 15;

    gb.cartridge[0] = 0xAE;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) != ZERO);
    ASSERT_THAT(gb.a == 23);
    ASSERT_THAT(gb.ticks == 8);
    ASSERT_THAT(gb.pc == 1);
}

TEST(xor_a_green_0){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 10;

    gb.cartridge[0] = 0xAF;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}
TEST(xor_a_green_1){
    aiv_gameboy gb;
    aiv_gb_init(&gb);

    gb.a = 24;
    gb.hl = 15;

    gb.cartridge[0] = 0xAF;
    aiv_gb_tick(&gb);

    ASSERT_THAT((gb.f & ZERO) == ZERO);
    ASSERT_THAT(gb.a == 0);
    ASSERT_THAT(gb.ticks == 4);
    ASSERT_THAT(gb.pc == 1);
}

void aiv_gb_tests_run_opcodes_a0()
{
    RUN_TEST(and_b_green_0);
    RUN_TEST(and_b_green_1);
    RUN_TEST(and_c_green_0);
    RUN_TEST(and_c_green_1);
    RUN_TEST(and_d_green_0);
    RUN_TEST(and_d_green_1);
    RUN_TEST(and_e_green_0);
    RUN_TEST(and_e_green_1);
    RUN_TEST(and_h_green_0);
    RUN_TEST(and_h_green_1);
    RUN_TEST(and_l_green_0);
    RUN_TEST(and_l_green_1);
    RUN_TEST(and_hl_green_0);
    RUN_TEST(and_hl_green_1);
    RUN_TEST(and_a_green_0);
    RUN_TEST(and_a_green_1);

    RUN_TEST(xor_b_green_0);
    RUN_TEST(xor_b_green_1);
    RUN_TEST(xor_c_green_0);
    RUN_TEST(xor_c_green_1);
    RUN_TEST(xor_d_green_0);
    RUN_TEST(xor_d_green_1);
    RUN_TEST(xor_e_green_0);
    RUN_TEST(xor_e_green_1);
    RUN_TEST(xor_h_green_0);
    RUN_TEST(xor_h_green_1);
    RUN_TEST(xor_l_green_0);
    RUN_TEST(xor_l_green_1);
    RUN_TEST(xor_hl_green_0);
    RUN_TEST(xor_hl_green_1);
    RUN_TEST(xor_a_green_0);
    RUN_TEST(xor_a_green_1);
}