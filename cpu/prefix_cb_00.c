#include <aiv_gb.h>

//RLC B
int aiv_gb_prefix_cb_00(aiv_gameboy *gb)
{
    gb->b = (gb->b << 1) | (gb->b >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->b == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, gb->b >> 7);
    return 8;
}

//RLC C
int aiv_gb_prefix_cb_01(aiv_gameboy *gb)
{
    gb->c = (gb->c << 1) | (gb->c >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->c == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, gb->c >> 7);
    return 8;
}

//RLC D
int aiv_gb_prefix_cb_02(aiv_gameboy *gb)
{
    gb->d = (gb->d << 1) | (gb->d >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->d == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, gb->d >> 7);
    return 8;
}

//RLC E
int aiv_gb_prefix_cb_03(aiv_gameboy *gb)
{
    gb->e = (gb->e << 1) | (gb->e >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->e == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, gb->e >> 7);
    return 8;
}

//RLC H
int aiv_gb_prefix_cb_04(aiv_gameboy *gb)
{
    gb->h = (gb->h << 1) | (gb->h >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->h == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, gb->h >> 7);
    return 8;
}

//RLC L
int aiv_gb_prefix_cb_05(aiv_gameboy *gb)
{
    gb->l = (gb->l << 1) | (gb->l >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->l == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, gb->l >> 7);
    return 8;
}

//TODO
//RLC HL
int aiv_gb_prefix_cb_06(aiv_gameboy *gb)
{
	gb->hl = (gb->hl << 1) | (gb->hl >> 15);
	aiv_gb_set_flag(gb, ZERO, gb->hl == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, gb->hl >> 15);
    return 16;
}

//RLC A
int aiv_gb_prefix_cb_07(aiv_gameboy *gb)
{
    gb->a = (gb->a << 1) | (gb->a >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, gb->a >> 7);
    return 8;
}

//RRC B
int aiv_gb_prefix_cb_08(aiv_gameboy *gb)
{
	gb->b = (gb->b >> 1) | ((gb->b & 0x1) << 7);
	aiv_gb_set_flag(gb, ZERO, gb->b == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->b & 0x1));
	return 8;
}

//RRC C
int aiv_gb_prefix_cb_09(aiv_gameboy *gb)
{
	gb->c = (gb->c >> 1) | ((gb->c & 0x1) << 7);
	aiv_gb_set_flag(gb, ZERO, gb->c == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->c & 0x1));
	return 8;
}

//RRC D
int aiv_gb_prefix_cb_0a(aiv_gameboy *gb)
{
	gb->d = (gb->d >> 1) | ((gb->d & 0x1) << 7);
	aiv_gb_set_flag(gb, ZERO, gb->d == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->d & 0x1));
	return 8;
}

//RRC E
int aiv_gb_prefix_cb_0b(aiv_gameboy *gb)
{
	gb->e = (gb->e >> 1) | ((gb->e & 0x1) << 7);
	aiv_gb_set_flag(gb, ZERO, gb->e == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->e & 0x1));
	return 8;
}

//RRC H
int aiv_gb_prefix_cb_0c(aiv_gameboy *gb)
{
	gb->h = (gb->h >> 1) | ((gb->h & 0x1) << 7);
	aiv_gb_set_flag(gb, ZERO, gb->h == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->h & 0x1));
	return 8;
}

//RRC L
int aiv_gb_prefix_cb_0d(aiv_gameboy *gb)
{
	gb->l = (gb->l >> 1) | ((gb->l & 0x1) << 7);
	aiv_gb_set_flag(gb, ZERO, gb->l == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->l & 0x1));
	return 8;
}

//RRC HL
int aiv_gb_prefix_cb_0e(aiv_gameboy *gb)
{
	gb->hl = (gb->hl >> 1) | ((gb->hl & 0x1) << 15);
	aiv_gb_set_flag(gb, ZERO, gb->hl == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->hl & 0x1));
	return 16;
}

//RRC A
int aiv_gb_prefix_cb_0f(aiv_gameboy *gb)
{
	gb->a = (gb->a >> 1) | ((gb->a & 0x1) << 7);
	aiv_gb_set_flag(gb, ZERO, gb->a == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->a & 0x1));
	return 8;
}

void aiv_gb_register_prefix_cb_00(aiv_gameboy *gb)
{
    gb->prefix_opcodes[0x00] = aiv_gb_prefix_cb_00;
    gb->prefix_opcodes[0x01] = aiv_gb_prefix_cb_01;
    gb->prefix_opcodes[0x02] = aiv_gb_prefix_cb_02;
    gb->prefix_opcodes[0x03] = aiv_gb_prefix_cb_03;
    gb->prefix_opcodes[0x04] = aiv_gb_prefix_cb_04;
    gb->prefix_opcodes[0x05] = aiv_gb_prefix_cb_05;
    gb->prefix_opcodes[0x06] = aiv_gb_prefix_cb_06;
    gb->prefix_opcodes[0x07] = aiv_gb_prefix_cb_07;

	gb->prefix_opcodes[0x08] = aiv_gb_prefix_cb_08;
	gb->prefix_opcodes[0x09] = aiv_gb_prefix_cb_09;
	gb->prefix_opcodes[0x0a] = aiv_gb_prefix_cb_0a;
	gb->prefix_opcodes[0x0b] = aiv_gb_prefix_cb_0b;
	gb->prefix_opcodes[0x0c] = aiv_gb_prefix_cb_0c;
	gb->prefix_opcodes[0x0d] = aiv_gb_prefix_cb_0d;
	gb->prefix_opcodes[0x0e] = aiv_gb_prefix_cb_0e;
	gb->prefix_opcodes[0x0f] = aiv_gb_prefix_cb_0f;
}
