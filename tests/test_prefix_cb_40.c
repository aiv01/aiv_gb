#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(prefix_cb_40_bit0_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x40;
        gb.b=0x01;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_40_bit0_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x40;
        gb.b=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_41_bit0_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x41;
        gb.c=0x01;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_41_bit0_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x41;
        gb.c=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_42_bit0_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x42;
        gb.d=0x01;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_42_bit0_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x42;
        gb.d=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_43_bit0_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x43;
        gb.e=0x01;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_43_bit0_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x43;
        gb.e=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_44_bit0_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x44;
        gb.h=0x01;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_44_bit0_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x44;
        gb.h=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_45_bit0_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x45;
        gb.l=0x01;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_45_bit0_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x45;
        gb.l=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_46_bit0_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x46;
        gb.hl=0x01;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_46_bit0_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x46;
        gb.hl=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_47_bit0_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x47;
        gb.a=0x01;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_47_bit0_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x47;
        gb.a=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_48_bit1_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x48;
        gb.b=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_48_bit1_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x48;
        gb.b=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_49_bit1_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x49;
        gb.c=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_49_bit1_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x49;
        gb.c=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_4a_bit1_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4a;
        gb.d=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_4a_bit1_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4a;
        gb.d=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_4b_bit1_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4b;
        gb.e=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_4b_bit1_unset)
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
TEST(prefix_cb_4c_bit1_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4c;
        gb.h=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_4c_bit1_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4c;
        gb.h=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_4d_bit1_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4d;
        gb.l=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_4d_bit1_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4d;
        gb.l=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_4e_bit1_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4e;
        gb.hl=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_4e_bit1_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4e;
        gb.hl=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_4f_bit1_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4f;
        gb.a=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_4f_bit1_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x4f;
        gb.a=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }


void aiv_gb_tests_run_prefix_cb_40()
{
    RUN_TEST(prefix_cb_40_bit0_set);
    RUN_TEST(prefix_cb_40_bit0_unset);
    RUN_TEST(prefix_cb_41_bit0_set);
    RUN_TEST(prefix_cb_41_bit0_unset);
    RUN_TEST(prefix_cb_42_bit0_set);
    RUN_TEST(prefix_cb_42_bit0_unset);
    RUN_TEST(prefix_cb_43_bit0_set);
    RUN_TEST(prefix_cb_43_bit0_unset);
    RUN_TEST(prefix_cb_44_bit0_set);
    RUN_TEST(prefix_cb_44_bit0_unset);
    RUN_TEST(prefix_cb_45_bit0_set);
    RUN_TEST(prefix_cb_45_bit0_unset);
    RUN_TEST(prefix_cb_46_bit0_set);
    RUN_TEST(prefix_cb_46_bit0_unset);
    RUN_TEST(prefix_cb_47_bit0_set);
    RUN_TEST(prefix_cb_47_bit0_unset);
    RUN_TEST(prefix_cb_48_bit1_set);
    RUN_TEST(prefix_cb_48_bit1_unset);
    RUN_TEST(prefix_cb_49_bit1_set);
    RUN_TEST(prefix_cb_49_bit1_unset);
    RUN_TEST(prefix_cb_4a_bit1_set);
    RUN_TEST(prefix_cb_4a_bit1_unset);
    RUN_TEST(prefix_cb_4b_bit1_set);
    RUN_TEST(prefix_cb_4b_bit1_unset);
    RUN_TEST(prefix_cb_4c_bit1_set);
    RUN_TEST(prefix_cb_4c_bit1_unset);
    RUN_TEST(prefix_cb_4d_bit1_set);
    RUN_TEST(prefix_cb_4d_bit1_unset);
    RUN_TEST(prefix_cb_4e_bit1_set);
    RUN_TEST(prefix_cb_4e_bit1_unset);
    RUN_TEST(prefix_cb_4f_bit1_set);
    RUN_TEST(prefix_cb_4f_bit1_unset);
}