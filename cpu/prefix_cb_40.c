#include <aiv_gb.h>

// BIT 0, B
static int
aiv_gb_prefix_cb_40(aiv_gameboy *gb)
{
	u8_t value = gb->b;
	if (value & 0x01)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 0, C
static int
aiv_gb_prefix_cb_41(aiv_gameboy *gb)
{
	u8_t value = gb->c;
	if (value & 0x01)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 0, D
static int
aiv_gb_prefix_cb_42(aiv_gameboy *gb)
{
	u8_t value = gb->d;
	if (value & 0x01)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 0, E
static int
aiv_gb_prefix_cb_43(aiv_gameboy *gb)
{
	u8_t value = gb->e;
	if (value & 0x01)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 0, H
static int
aiv_gb_prefix_cb_44(aiv_gameboy *gb)
{
	u8_t value = gb->h;
	if (value & 0x01)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 0, L
static int
aiv_gb_prefix_cb_45(aiv_gameboy *gb)
{
	u8_t value = gb->l;
	if (value & 0x01)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 0, HL
static int
aiv_gb_prefix_cb_46(aiv_gameboy *gb)
{
	u8_t value = gb->hl;
	if (value & 0x01)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 0, A
static int
aiv_gb_prefix_cb_47(aiv_gameboy *gb)
{
	u8_t value = gb->a;
	if (value & 0x01)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 1, B
static int
aiv_gb_prefix_cb_48(aiv_gameboy *gb)
{
	u8_t value = gb->b;
	if (value & 0x02)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 1, C
static int
aiv_gb_prefix_cb_49(aiv_gameboy *gb)
{
	u8_t value = gb->c;
	if (value & 0x02)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 1, D
static int
aiv_gb_prefix_cb_4a(aiv_gameboy *gb)
{
	u8_t value = gb->d;
	if (value & 0x02)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 1, E
static int
aiv_gb_prefix_cb_4b(aiv_gameboy *gb)
{
	u8_t value = gb->e;
	if (value & 0x02)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 1, H
static int
aiv_gb_prefix_cb_4c(aiv_gameboy *gb)
{
	u8_t value = gb->h;
	if (value & 0x02)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 1, L
static int
aiv_gb_prefix_cb_4d(aiv_gameboy *gb)
{
	u8_t value = gb->l;
	if (value & 0x02)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 1, HL
static int
aiv_gb_prefix_cb_4e(aiv_gameboy *gb)
{
	u8_t value = gb->hl;
	if (value & 0x02)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
//BIT 1, A
static int
aiv_gb_prefix_cb_4f(aiv_gameboy *gb)
{
	u8_t value = gb->a;
	if (value & 0x02)
	{
		aiv_gb_set_flag(gb, ZERO, 0);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	else
	{
		aiv_gb_set_flag(gb, ZERO, 1);
		aiv_gb_set_flag(gb, NEG, 0);
		aiv_gb_set_flag(gb, HALF, 1);
		return 8;
	}
	return 8;
}
void aiv_gb_register_prefix_cb_40(aiv_gameboy *gb)
{
	gb->prefix_opcodes[0x40] = aiv_gb_prefix_cb_40;
	gb->prefix_opcodes[0x41] = aiv_gb_prefix_cb_41;
	gb->prefix_opcodes[0x42] = aiv_gb_prefix_cb_42;
	gb->prefix_opcodes[0x43] = aiv_gb_prefix_cb_43;
	gb->prefix_opcodes[0x44] = aiv_gb_prefix_cb_44;
	gb->prefix_opcodes[0x45] = aiv_gb_prefix_cb_45;
	gb->prefix_opcodes[0x46] = aiv_gb_prefix_cb_46;
	gb->prefix_opcodes[0x47] = aiv_gb_prefix_cb_47;
	gb->prefix_opcodes[0x48] = aiv_gb_prefix_cb_48;
	gb->prefix_opcodes[0x49] = aiv_gb_prefix_cb_49;
	gb->prefix_opcodes[0x4a] = aiv_gb_prefix_cb_4a;
	gb->prefix_opcodes[0x4b] = aiv_gb_prefix_cb_4b;
	gb->prefix_opcodes[0x4c] = aiv_gb_prefix_cb_4c;
	gb->prefix_opcodes[0x4d] = aiv_gb_prefix_cb_4d;
	gb->prefix_opcodes[0x4e] = aiv_gb_prefix_cb_4e;
	gb->prefix_opcodes[0x4f] = aiv_gb_prefix_cb_4f;
}
