#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(prefix_cb_60_bit4_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x60;
        gb.b=0x10;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_60_bit4_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x60;
        gb.b=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_61_bit4_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x61;
        gb.c=0x10;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_61_bit4_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x61;
        gb.c=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_62_bit4_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x62;
        gb.d=0x10;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_62_bit4_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x62;
        gb.d=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_63_bit4_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x63;
        gb.e=0x10;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_63_bit4_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x63;
        gb.e=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_64_bit4_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x64;
        gb.h=0x10;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_64_bit4_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x64;
        gb.h=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_65_bit4_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x65;
        gb.l=0x10;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_65_bit4_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x65;
        gb.l=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_66_bit4_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x66;
        gb.hl=0x10;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_66_bit4_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x66;
        gb.hl=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_67_bit4_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x67;
        gb.a=0x10;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_67_bit4_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x67;
        gb.a=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_68_bit5_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x68;
        gb.b=0x20;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_68_bit5_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x68;
        gb.b=0x00;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_69_bit5_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x69;
        gb.c=0x20;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_69_bit5_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x69;
        gb.c=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_6a_bit5_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6a;
        gb.d=0x20;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_6a_bit5_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6a;
        gb.d=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_6b_bit5_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6b;
        gb.e=0x20;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_6b_bit5_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6b;
        gb.e=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_6c_bit5_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6c;
        gb.h=0x20;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_6c_bit5_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6c;
        gb.h=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_6d_bit5_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6d;
        gb.l=0x20;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_6d_bit5_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6d;
        gb.l=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_6e_bit5_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6e;
        gb.hl=0x20;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_6e_bit5_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6e;
        gb.hl=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }
TEST(prefix_cb_6f_bit5_set)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6f;
        gb.a=0x20;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0x20);
    }
TEST(prefix_cb_6f_bit5_unset)
    {
        aiv_gameboy gb;
        aiv_gb_init(&gb);

        gb.cartridge[0]=0xcb;
        gb.cartridge[1]=0x6f;
        gb.a=0x02;
        gb.f=0x00;
        aiv_gb_tick(&gb);
        ASSERT_THAT(gb.f==0xa0);
    }


void aiv_gb_tests_run_prefix_cb_60()
{
    RUN_TEST(prefix_cb_60_bit4_set);
    RUN_TEST(prefix_cb_60_bit4_unset);
    RUN_TEST(prefix_cb_61_bit4_set);
    RUN_TEST(prefix_cb_61_bit4_unset);
    RUN_TEST(prefix_cb_62_bit4_set);
    RUN_TEST(prefix_cb_62_bit4_unset);
    RUN_TEST(prefix_cb_63_bit4_set);
    RUN_TEST(prefix_cb_63_bit4_unset);
    RUN_TEST(prefix_cb_64_bit4_set);
    RUN_TEST(prefix_cb_64_bit4_unset);
    RUN_TEST(prefix_cb_65_bit4_set);
    RUN_TEST(prefix_cb_65_bit4_unset);
    RUN_TEST(prefix_cb_66_bit4_set);
    RUN_TEST(prefix_cb_66_bit4_unset);
    RUN_TEST(prefix_cb_67_bit4_set);
    RUN_TEST(prefix_cb_67_bit4_unset);
    RUN_TEST(prefix_cb_68_bit5_set);
    RUN_TEST(prefix_cb_68_bit5_unset);
    RUN_TEST(prefix_cb_69_bit5_set);
    RUN_TEST(prefix_cb_69_bit5_unset);
    RUN_TEST(prefix_cb_6a_bit5_set);
    RUN_TEST(prefix_cb_6a_bit5_unset);
    RUN_TEST(prefix_cb_6b_bit5_set);
    RUN_TEST(prefix_cb_6b_bit5_unset);
    RUN_TEST(prefix_cb_6c_bit5_set);
    RUN_TEST(prefix_cb_6c_bit5_unset);
    RUN_TEST(prefix_cb_6d_bit5_set);
    RUN_TEST(prefix_cb_6d_bit5_unset);
    RUN_TEST(prefix_cb_6e_bit5_set);
    RUN_TEST(prefix_cb_6e_bit5_unset);
    RUN_TEST(prefix_cb_6f_bit5_set);
    RUN_TEST(prefix_cb_6f_bit5_unset);
}