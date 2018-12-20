#include <aiv_unit_test.h>
#include <aiv_gb.h>
#define SETUP_GB    \
    aiv_gameboy gb; \
    aiv_gb_init(&gb)

TEST(SWAP_B)
{
    SETUP_GB;
    gb.b = 16;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x30;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.b == 1);
}

TEST(SWAP_C)
{
    SETUP_GB;
    gb.c = 16;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x31;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 1);
}

TEST(SWAP_D)
{
    SETUP_GB;
    gb.d = 1;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x32;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.d == 16);
}

TEST(SWAP_E)
{
    SETUP_GB;
    gb.e = 128;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x33;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.e == 8);
}

TEST(SWAP_H)
{
    SETUP_GB;
    gb.h = 32;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x34;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 2);
}

TEST(SWAP_L)
{
    SETUP_GB;
    gb.l = 6;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x35;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 96);
}

TEST(SWAP_HL)
{
    SETUP_GB;
    gb.hl = 256;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x36;

	aiv_gb_tick(&gb);


    ASSERT_THAT(gb.hl == 4096);
}

TEST(SWAP_A)
{
    SETUP_GB;
    gb.a = 4;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x37;

	aiv_gb_tick(&gb);
    ASSERT_THAT(gb.a == 64);
}

TEST(SRL_B)
{
    SETUP_GB;
    gb.b = 16;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x38;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.b == 8);
}

TEST(SRL_C)
{
    SETUP_GB;
    gb.c = 16;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x39;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.c == 8);
}

TEST(SRL_D)
{
    SETUP_GB;
    gb.d = 64;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x3a;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.d == 32);
}

TEST(SRL_E)
{
    SETUP_GB;
    gb.e = 48;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x3b;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.e == 24);
}

TEST(SRL_H)
{
    SETUP_GB;
    gb.h = 32;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x3c;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.h == 16);
}

TEST(SRL_L)
{
    SETUP_GB;
    gb.l = 6;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x3d;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.l == 3);
}

TEST(SRL_HL)
{
    SETUP_GB;
    gb.hl = 3584;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x3e;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.hl == 1792);
}

TEST(SRL_A)
{
    SETUP_GB;
    gb.a = 1;
	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x3f;

	aiv_gb_tick(&gb);

    ASSERT_THAT(gb.a == 0);
}

void aiv_gb_tests_run_prefix_cb_30()
{
    RUN_TEST(SWAP_B);
    RUN_TEST(SWAP_C);
    RUN_TEST(SWAP_D);
    RUN_TEST(SWAP_E);
    RUN_TEST(SWAP_H);
    RUN_TEST(SWAP_L);
    RUN_TEST(SWAP_HL);
    RUN_TEST(SWAP_A);

    RUN_TEST(SRL_B);
    RUN_TEST(SRL_C);
    RUN_TEST(SRL_D);
    RUN_TEST(SRL_E);
    RUN_TEST(SRL_H);
    RUN_TEST(SRL_L);
    RUN_TEST(SRL_HL);
    RUN_TEST(SRL_A);
}