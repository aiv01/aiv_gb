#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(prefixcb40_bit0_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=cb;
        gb.cartridge[1]=40;
        gb.b=0x01;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
    TEST(prefixcb40_bit0_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=cb;
        gb.cartridge[1]=40;
        gb.b=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefixcb41)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb42)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb43)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb44)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb45)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb46)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb47)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb48)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb49)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb4a)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb4b)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb4c)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb4d)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb4e)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }
TEST(prefixcb4f)
    {
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    aiv_gb_tick(&gb);
    }

void aiv_gb_tests_run_prefix_cb_40()
{
    RUN_TEST(prefixcb40);
    RUN_TEST(prefixcb41);
    RUN_TEST(prefixcb42);
    RUN_TEST(prefixcb43);
    RUN_TEST(prefixcb44);
    RUN_TEST(prefixcb45);
    RUN_TEST(prefixcb46);
    RUN_TEST(prefixcb47);
    RUN_TEST(prefixcb48);
    RUN_TEST(prefixcb49);
    RUN_TEST(prefixcb4a);
    RUN_TEST(prefixcb4b);
    RUN_TEST(prefixcb4c);
    RUN_TEST(prefixcb4d);
    RUN_TEST(prefixcb4e);
    RUN_TEST(prefixcb4f);
}