#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(prefix_cb_50_bit2_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x50;
        gb.b=0x04;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_50_bit2_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x50;
        gb.b=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_51_bit2_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x51;
        gb.c=0x04;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_51_bit2_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x51;
        gb.c=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_52_bit2_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x52;
        gb.d=0x04;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_52_bit2_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x52;
        gb.d=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_53_bit2_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x53;
        gb.e=0x04;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_53_bit2_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x53;
        gb.e=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_54_bit2_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x54;
        gb.h=0x04;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_54_bit2_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x54;
        gb.h=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_55_bit2_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x55;
        gb.l=0x04;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_55_bit2_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x55;
        gb.l=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_56_bit2_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x56;
        gb.hl=0x04;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_56_bit2_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x56;
        gb.hl=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_57_bit2_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x57;
        gb.a=0x04;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_57_bit2_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x57;
        gb.a=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_58_bit3_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x58;
        gb.b=0x08;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_58_bit3_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x58;
        gb.b=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_59_bit3_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x59;
        gb.c=0x08;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_59_bit3_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x59;
        gb.c=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_5a_bit3_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5a;
        gb.d=0x08;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_5a_bit3_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5a;
        gb.d=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_5b_bit3_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5b;
        gb.e=0x08;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_5b_bit3_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5b;
        gb.e=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_5c_bit3_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5c;
        gb.h=0x08;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_5c_bit3_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5c;
        gb.h=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_5d_bit3_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5d;
        gb.l=0x08;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_5d_bit3_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5d;
        gb.l=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_5e_bit3_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5e;
        gb.hl=0x08;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_5e_bit3_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5e;
        gb.hl=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_5f_bit3_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5f;
        gb.a=0x08;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_5f_bit3_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x5f;
        gb.a=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }


void aiv_gb_tests_run_prefix_cb_50()
{
    RUN_TEST(prefix_cb_50_bit2_set);
    RUN_TEST(prefix_cb_50_bit2_unset);
    RUN_TEST(prefix_cb_51_bit2_set);
    RUN_TEST(prefix_cb_51_bit2_unset);
    RUN_TEST(prefix_cb_52_bit2_set);
    RUN_TEST(prefix_cb_52_bit2_unset);
    RUN_TEST(prefix_cb_53_bit2_set);
    RUN_TEST(prefix_cb_53_bit2_unset);
    RUN_TEST(prefix_cb_54_bit2_set);
    RUN_TEST(prefix_cb_54_bit2_unset);
    RUN_TEST(prefix_cb_55_bit2_set);
    RUN_TEST(prefix_cb_55_bit2_unset);
    RUN_TEST(prefix_cb_56_bit2_set);
    RUN_TEST(prefix_cb_56_bit2_unset);
    RUN_TEST(prefix_cb_57_bit2_set);
    RUN_TEST(prefix_cb_57_bit2_unset);
    RUN_TEST(prefix_cb_58_bit3_set);
    RUN_TEST(prefix_cb_58_bit3_unset);
    RUN_TEST(prefix_cb_59_bit3_set);
    RUN_TEST(prefix_cb_59_bit3_unset);
    RUN_TEST(prefix_cb_5a_bit3_set);
    RUN_TEST(prefix_cb_5a_bit3_unset);
    RUN_TEST(prefix_cb_5b_bit3_set);
    RUN_TEST(prefix_cb_5b_bit3_unset);
    RUN_TEST(prefix_cb_5c_bit3_set);
    RUN_TEST(prefix_cb_5c_bit3_unset);
    RUN_TEST(prefix_cb_5d_bit3_set);
    RUN_TEST(prefix_cb_5d_bit3_unset);
    RUN_TEST(prefix_cb_5e_bit3_set);
    RUN_TEST(prefix_cb_5e_bit3_unset);
    RUN_TEST(prefix_cb_5f_bit3_set);
    RUN_TEST(prefix_cb_5f_bit3_unset);
}