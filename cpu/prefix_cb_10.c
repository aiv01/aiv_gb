#include <aiv_gb.h>

//RL B
int aiv_gb_prefix_cb_10(aiv_gameboy *gb)
{
	gb->b = (gb->b << 1) | CARRY;
	aiv_gb_set_flag(gb, CARRY, gb->b >> 7);
	aiv_gb_set_flag(gb, ZERO, gb->b == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	return 8;
}

//RL C
int aiv_gb_prefix_cb_11(aiv_gameboy *gb)
{
	gb->c = (gb->c << 1) | CARRY;
	aiv_gb_set_flag(gb, CARRY, gb->c >> 7);
	aiv_gb_set_flag(gb, ZERO, gb->c == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	return 8;
}

//RL D
int aiv_gb_prefix_cb_12(aiv_gameboy *gb)
{
	gb->d = (gb->d << 1) | CARRY;
	aiv_gb_set_flag(gb, CARRY, gb->d >> 7);
	aiv_gb_set_flag(gb, ZERO, gb->d == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	return 8;
}

//RL E
int aiv_gb_prefix_cb_13(aiv_gameboy *gb)
{
	gb->e = (gb->e << 1) | CARRY;
	aiv_gb_set_flag(gb, CARRY, gb->e >> 7);
	aiv_gb_set_flag(gb, ZERO, gb->e == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	return 8;
}

//RL H
int aiv_gb_prefix_cb_14(aiv_gameboy *gb)
{
	gb->h = (gb->h << 1) | CARRY;
	aiv_gb_set_flag(gb, CARRY, gb->h >> 7);
	aiv_gb_set_flag(gb, ZERO, gb->h == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	return 8;
}

//RL L
int aiv_gb_prefix_cb_15(aiv_gameboy *gb)
{
	gb->l = (gb->l << 1) | CARRY;
	aiv_gb_set_flag(gb, CARRY, gb->l >> 7);
	aiv_gb_set_flag(gb, ZERO, gb->l == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	return 8;
}

//RL HL
int aiv_gb_prefix_cb_16(aiv_gameboy *gb)
{
	gb->hl = (gb->hl << 1) | CARRY;
	aiv_gb_set_flag(gb, CARRY, gb->hl >> 15);
	aiv_gb_set_flag(gb, ZERO, gb->hl == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	return 16;
}

//RL A
int aiv_gb_prefix_cb_17(aiv_gameboy *gb)
{
	gb->a = (gb->a << 1) | CARRY;
	aiv_gb_set_flag(gb, CARRY, gb->a >> 7);
	aiv_gb_set_flag(gb, ZERO, gb->a == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	return 8;
}

//RR B
int aiv_gb_prefix_cb_18(aiv_gameboy *gb)
{
	gb->b = (gb->b >> 1) | (CARRY << 7);
	aiv_gb_set_flag(gb, CARRY, (gb->b & 0x1));
	aiv_gb_set_flag(gb, ZERO, gb->b == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	return 8;
}

//RR C
int aiv_gb_prefix_cb_19(aiv_gameboy *gb)
{
	gb->c = (gb->c >> 1) | (CARRY << 7);
	aiv_gb_set_flag(gb, ZERO, gb->c == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->c & 0x1));
	return 8;
}

//RR D
int aiv_gb_prefix_cb_1a(aiv_gameboy *gb)
{
	gb->d = (gb->d >> 1) | (CARRY << 7);
	aiv_gb_set_flag(gb, ZERO, gb->d == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->d & 0x1));
	return 8;
}

//RR E
int aiv_gb_prefix_cb_1b(aiv_gameboy *gb)
{
	gb->e = (gb->e >> 1) | (CARRY << 7);
	aiv_gb_set_flag(gb, ZERO, gb->e == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->e & 0x1));
	return 8;
}

//RR H
int aiv_gb_prefix_cb_1c(aiv_gameboy *gb)
{
	gb->h = (gb->h >> 1) | (CARRY << 7);
	aiv_gb_set_flag(gb, ZERO, gb->h == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->h & 0x1));
	return 8;
}

//RR L
int aiv_gb_prefix_cb_1d(aiv_gameboy *gb)
{
	gb->l = (gb->l >> 1) | (CARRY << 7);
	aiv_gb_set_flag(gb, ZERO, gb->l == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->l & 0x1));
	return 8;
}

//RR HL
int aiv_gb_prefix_cb_1e(aiv_gameboy *gb)
{
	gb->hl = (gb->hl >> 1) | (CARRY << 15);
	aiv_gb_set_flag(gb, ZERO, gb->hl == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->hl & 0x1));
	return 16;
}

//RR A
int aiv_gb_prefix_cb_1f(aiv_gameboy *gb)
{
	gb->a = (gb->a >> 1) | (CARRY << 7);
	aiv_gb_set_flag(gb, ZERO, gb->a == 0);
	aiv_gb_set_flag(gb, NEG, 0);
	aiv_gb_set_flag(gb, HALF, 0);
	aiv_gb_set_flag(gb, CARRY, (gb->a & 0x1));
	return 8;
}

void aiv_gb_register_prefix_cb_10(aiv_gameboy *gb)
{
	gb->prefix_opcodes[0x10] = aiv_gb_prefix_cb_10;
	gb->prefix_opcodes[0x11] = aiv_gb_prefix_cb_11;
	gb->prefix_opcodes[0x12] = aiv_gb_prefix_cb_12;
	gb->prefix_opcodes[0x13] = aiv_gb_prefix_cb_13;
	gb->prefix_opcodes[0x14] = aiv_gb_prefix_cb_14;
	gb->prefix_opcodes[0x15] = aiv_gb_prefix_cb_15;
	gb->prefix_opcodes[0x16] = aiv_gb_prefix_cb_16;
	gb->prefix_opcodes[0x17] = aiv_gb_prefix_cb_17;

	gb->prefix_opcodes[0x18] = aiv_gb_prefix_cb_18;
	gb->prefix_opcodes[0x19] = aiv_gb_prefix_cb_19;
	gb->prefix_opcodes[0x1a] = aiv_gb_prefix_cb_1a;
	gb->prefix_opcodes[0x1b] = aiv_gb_prefix_cb_1b;
	gb->prefix_opcodes[0x1c] = aiv_gb_prefix_cb_1c;
	gb->prefix_opcodes[0x1d] = aiv_gb_prefix_cb_1d;
	gb->prefix_opcodes[0x1e] = aiv_gb_prefix_cb_1e;
	gb->prefix_opcodes[0x1f] = aiv_gb_prefix_cb_1f;
}