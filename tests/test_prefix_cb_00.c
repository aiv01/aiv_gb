#include <aiv_unit_test.h>
#include <aiv_gb.h>
#define SETUP_GB    \
	aiv_gameboy gb; \
	aiv_gb_init(&gb)

TEST(RLC_B)
{
	SETUP_GB;
	gb.b = 16;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x00;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.b == 32);
}

TEST(RLC_C)
{
	SETUP_GB;
	gb.c = 240;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x01;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.c == 225);
}

TEST(RLC_D)
{
	SETUP_GB;
	gb.d = 1;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x02;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.d == 2);
}

TEST(RLC_E)
{
	SETUP_GB;
	gb.e = 130;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x03;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.e == 5);
}

TEST(RLC_H)
{
	SETUP_GB;
	gb.h = 32;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x04;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.h == 64);
}

TEST(RLC_L)
{
	SETUP_GB;
	gb.l = 96;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x05;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.l == 192);
}

TEST(RLC_HL)
{
	SETUP_GB;
	gb.hl = 1024;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x06;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.hl == 2048);
}

TEST(RLC_A)
{
	SETUP_GB;
	gb.a = 16;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x07;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.a == 32);
}

TEST(RRC_B)
{
	SETUP_GB;
	gb.b = 16;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x08;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.b == 8);
}

TEST(RRC_C)
{
	SETUP_GB;
	gb.c = 24;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x09;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.c == 12);
}

TEST(RRC_D)
{
	SETUP_GB;
	gb.d = 16;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x0a;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.d == 8);
}

TEST(RRC_E)
{
	SETUP_GB;
	gb.e = 2;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x0b;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.e == 1);
}

TEST(RRC_H)
{
	SETUP_GB;
	gb.h = 146;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x0c;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.h == 73);
}

TEST(RRC_L)
{
	SETUP_GB;
	gb.l = 192;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x0d;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.l == 96);
}

TEST(RRC_HL)
{
	SETUP_GB;
	gb.hl = 14336;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x0e;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.hl == 7168);
}

TEST(RRC_A)
{
	SETUP_GB;
	gb.a = 32;

	gb.cartridge[0] = 0xcb;
	gb.cartridge[1] = 0x0f;

	aiv_gb_tick(&gb);

	ASSERT_THAT(gb.a == 16);
}

void aiv_gb_tests_run_prefix_cb_00()
{
	RUN_TEST(RLC_B);
	RUN_TEST(RLC_C);
	RUN_TEST(RLC_D);
	RUN_TEST(RLC_E);
	RUN_TEST(RLC_H);
	RUN_TEST(RLC_L);
	RUN_TEST(RLC_HL);
	RUN_TEST(RLC_A);

	RUN_TEST(RRC_B);
	RUN_TEST(RRC_C);
	RUN_TEST(RRC_D);
	RUN_TEST(RRC_E);
	RUN_TEST(RRC_H);
	RUN_TEST(RRC_L);
	RUN_TEST(RRC_HL);
	RUN_TEST(RRC_A);
}