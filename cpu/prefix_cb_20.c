#include <aiv_gb.h>

//SLA B
int aiv_gb_prefix_cb_20(aiv_gameboy *gb)
{
    gb->b = (gb->b << 1);
    aiv_gb_set_flag(gb, CARRY, gb->b >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->b == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SLA C
int aiv_gb_prefix_cb_21(aiv_gameboy *gb)
{
    gb->c = (gb->c << 1);
    aiv_gb_set_flag(gb, CARRY, gb->c >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->c == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SLA D
int aiv_gb_prefix_cb_22(aiv_gameboy *gb)
{
    gb->d = (gb->d << 1);
    aiv_gb_set_flag(gb, CARRY, gb->d >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->d == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SLA E
int aiv_gb_prefix_cb_23(aiv_gameboy *gb)
{
    gb->e = (gb->e << 1);
    aiv_gb_set_flag(gb, CARRY, gb->e >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->e == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SLA H
int aiv_gb_prefix_cb_24(aiv_gameboy *gb)
{
    gb->h = (gb->h << 1);
    aiv_gb_set_flag(gb, CARRY, gb->h >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->h == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SLA L
int aiv_gb_prefix_cb_25(aiv_gameboy *gb)
{
    gb->l = (gb->l << 1);
    aiv_gb_set_flag(gb, CARRY, gb->l >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->l == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SLA HL
int aiv_gb_prefix_cb_26(aiv_gameboy *gb)
{
    gb->hl = (gb->hl << 1);
    aiv_gb_set_flag(gb, CARRY, gb->hl >> 15);
    aiv_gb_set_flag(gb, ZERO, gb->hl == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 16;
}

//SLA A
int aiv_gb_prefix_cb_27(aiv_gameboy *gb)
{
    gb->a = (gb->a << 1);
    aiv_gb_set_flag(gb, CARRY, gb->a >> 7);
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRA B
int aiv_gb_prefix_cb_28(aiv_gameboy *gb)
{
    gb->b = (gb->b >> 1) | (gb->b & ZERO);
    aiv_gb_set_flag(gb, CARRY, (gb->b & 1));
    aiv_gb_set_flag(gb, ZERO, gb->b == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRA C
int aiv_gb_prefix_cb_29(aiv_gameboy *gb)
{
    gb->c = (gb->c >> 1) | (gb->c & ZERO);
    aiv_gb_set_flag(gb, CARRY, (gb->c& 1));
    aiv_gb_set_flag(gb, ZERO, gb->c == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRA D
int aiv_gb_prefix_cb_2a(aiv_gameboy *gb)
{
    gb->d = (gb->d >> 1) | (gb->d & ZERO);
	aiv_gb_set_flag(gb, CARRY, (gb->d & 1));
    aiv_gb_set_flag(gb, ZERO, gb->d == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRA E
int aiv_gb_prefix_cb_2b(aiv_gameboy *gb)
{
    gb->e = (gb->e >> 1) | (gb->e & ZERO);
	aiv_gb_set_flag(gb, CARRY, (gb->e & 1));
    aiv_gb_set_flag(gb, ZERO, gb->e == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRA H
int aiv_gb_prefix_cb_2c(aiv_gameboy *gb)
{
    gb->h = (gb->h >> 1) | (gb->h & ZERO);
	aiv_gb_set_flag(gb, CARRY, (gb->h & 1));
    aiv_gb_set_flag(gb, ZERO, gb->h == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRA L
int aiv_gb_prefix_cb_2d(aiv_gameboy *gb)
{
    gb->l = (gb->l >> 1) | (gb->l & ZERO);
	aiv_gb_set_flag(gb, CARRY, (gb->l & 1));
    aiv_gb_set_flag(gb, ZERO, gb->l == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRA HL
int aiv_gb_prefix_cb_2e(aiv_gameboy *gb)
{
    gb->hl = (gb->hl >> 1) | (gb->hl & 1);
    aiv_gb_set_flag(gb, CARRY, (gb->hl & 1));
    aiv_gb_set_flag(gb, ZERO, gb->hl == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 16;
}

//SRA A
int aiv_gb_prefix_cb_2f(aiv_gameboy *gb)
{
    gb->a = (gb->a >> 1) | (gb->a & ZERO);
	aiv_gb_set_flag(gb, CARRY, (gb->a & 1));
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

void aiv_gb_register_prefix_cb_20(aiv_gameboy *gb)
{
    gb->prefix_opcodes[0x20] = aiv_gb_prefix_cb_20;
    gb->prefix_opcodes[0x21] = aiv_gb_prefix_cb_21;
    gb->prefix_opcodes[0x22] = aiv_gb_prefix_cb_22;
    gb->prefix_opcodes[0x23] = aiv_gb_prefix_cb_23;
    gb->prefix_opcodes[0x24] = aiv_gb_prefix_cb_24;
    gb->prefix_opcodes[0x25] = aiv_gb_prefix_cb_25;
    gb->prefix_opcodes[0x26] = aiv_gb_prefix_cb_26;
    gb->prefix_opcodes[0x27] = aiv_gb_prefix_cb_27;

    gb->prefix_opcodes[0x28] = aiv_gb_prefix_cb_28;
    gb->prefix_opcodes[0x29] = aiv_gb_prefix_cb_29;
    gb->prefix_opcodes[0x2a] = aiv_gb_prefix_cb_2a;
    gb->prefix_opcodes[0x2b] = aiv_gb_prefix_cb_2b;
    gb->prefix_opcodes[0x2c] = aiv_gb_prefix_cb_2c;
    gb->prefix_opcodes[0x2d] = aiv_gb_prefix_cb_2d;
    gb->prefix_opcodes[0x2e] = aiv_gb_prefix_cb_2e;
    gb->prefix_opcodes[0x2f] = aiv_gb_prefix_cb_2f;
}