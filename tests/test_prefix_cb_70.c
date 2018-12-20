#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(prefix_cb_70_bit6_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x70;
        gb.b=0x40;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_70_bit6_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x70;
        gb.b=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_71_bit6_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x71;
        gb.c=0x40;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_71_bit6_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x71;
        gb.c=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_72_bit6_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x72;
        gb.d=0x40;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_72_bit6_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x72;
        gb.d=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_73_bit6_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x73;
        gb.e=0x40;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_73_bit6_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x73;
        gb.e=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_74_bit6_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x74;
        gb.h=0x40;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_74_bit6_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x74;
        gb.h=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_75_bit6_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x75;
        gb.l=0x40;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_75_bit6_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x75;
        gb.l=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_76_bit6_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x76;
        gb.hl=0x40;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_76_bit6_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x76;
        gb.hl=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_77_bit6_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x77;
        gb.a=0x40;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_77_bit6_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x77;
        gb.a=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_78_bit7_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x78;
        gb.b=0x80;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_78_bit7_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x78;
        gb.b=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_79_bit7_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x79;
        gb.c=0x80;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_79_bit7_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x79;
        gb.c=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_7a_bit7_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7a;
        gb.d=0x80;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_7a_bit7_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7a;
        gb.d=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_7b_bit7_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7b;
        gb.e=0x80;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_7b_bit7_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4b;
        gb.e=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_7c_bit7_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7c;
        gb.h=0x80;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_7c_bit7_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7c;
        gb.h=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_7d_bit7_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7d;
        gb.l=0x80;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_7d_bit7_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7d;
        gb.l=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_7e_bit7_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7e;
        gb.hl=0x80;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_7e_bit7_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7e;
        gb.hl=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_7f_bit7_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7f;
        gb.a=0x80;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_7f_bit7_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x7f;
        gb.a=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }


void aiv_gb_tests_run_prefix_cb_70()
{
    RUN_TEST(prefix_cb_70_bit6_set);
    RUN_TEST(prefix_cb_70_bit6_unset);
    RUN_TEST(prefix_cb_71_bit6_set);
    RUN_TEST(prefix_cb_71_bit6_unset);
    RUN_TEST(prefix_cb_72_bit6_set);
    RUN_TEST(prefix_cb_72_bit6_unset);
    RUN_TEST(prefix_cb_73_bit6_set);
    RUN_TEST(prefix_cb_73_bit6_unset);
    RUN_TEST(prefix_cb_74_bit6_set);
    RUN_TEST(prefix_cb_74_bit6_unset);
    RUN_TEST(prefix_cb_75_bit6_set);
    RUN_TEST(prefix_cb_75_bit6_unset);
    RUN_TEST(prefix_cb_76_bit6_set);
    RUN_TEST(prefix_cb_76_bit6_unset);
    RUN_TEST(prefix_cb_77_bit6_set);
    RUN_TEST(prefix_cb_77_bit6_unset);
    RUN_TEST(prefix_cb_78_bit7_set);
    RUN_TEST(prefix_cb_78_bit7_unset);
    RUN_TEST(prefix_cb_79_bit7_set);
    RUN_TEST(prefix_cb_79_bit7_unset);
    RUN_TEST(prefix_cb_7a_bit7_set);
    RUN_TEST(prefix_cb_7a_bit7_unset);
    RUN_TEST(prefix_cb_7b_bit7_set);
    RUN_TEST(prefix_cb_7b_bit7_unset);
    RUN_TEST(prefix_cb_7c_bit7_set);
    RUN_TEST(prefix_cb_7c_bit7_unset);
    RUN_TEST(prefix_cb_7d_bit7_set);
    RUN_TEST(prefix_cb_7d_bit7_unset);
    RUN_TEST(prefix_cb_7e_bit7_set);
    RUN_TEST(prefix_cb_7e_bit7_unset);
    RUN_TEST(prefix_cb_7f_bit7_set);
    RUN_TEST(prefix_cb_7f_bit7_unset);
}