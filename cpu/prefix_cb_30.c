#include <aiv_gb.h>

//SWAP B
int aiv_gb_prefix_cb_30(aiv_gameboy *gb)
{
    gb->b = ((gb->b & 0x0F) << 4) | ((gb->b & 0xF0) >> 4);
    aiv_gb_set_flag(gb, CARRY, 0);
    aiv_gb_set_flag(gb, ZERO, gb->b == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SWAP C
int aiv_gb_prefix_cb_31(aiv_gameboy *gb)
{
    gb->c = ((gb->c & 0x0F) << 4) | ((gb->c & 0xF0) >> 4);
    aiv_gb_set_flag(gb, CARRY, 0);
    aiv_gb_set_flag(gb, ZERO, gb->c == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SWAP D
int aiv_gb_prefix_cb_32(aiv_gameboy *gb)
{
    gb->d = ((gb->d & 0x0F) << 4) | ((gb->d & 0xF0) >> 4);
    aiv_gb_set_flag(gb, CARRY, 0);
    aiv_gb_set_flag(gb, ZERO, gb->d == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SWAP E
int aiv_gb_prefix_cb_33(aiv_gameboy *gb)
{
    gb->e = ((gb->e & 0x0F) << 4) | ((gb->e & 0xF0) >> 4);
    aiv_gb_set_flag(gb, CARRY, 0);
    aiv_gb_set_flag(gb, ZERO, gb->e == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SWAP H
int aiv_gb_prefix_cb_34(aiv_gameboy *gb)
{
    gb->h = ((gb->h & 0x0F) << 4) | ((gb->h & 0xF0) >> 4);
    aiv_gb_set_flag(gb, CARRY, 0);
    aiv_gb_set_flag(gb, ZERO, gb->h == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SWAP L
int aiv_gb_prefix_cb_35(aiv_gameboy *gb)
{
    gb->l = ((gb->l & 0x0F) << 4) | ((gb->l & 0xF0) >> 4);
    aiv_gb_set_flag(gb, CARRY, 0);
    aiv_gb_set_flag(gb, ZERO, gb->l == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SWAP HL
int aiv_gb_prefix_cb_36(aiv_gameboy *gb)
{
    gb->hl = ((gb->hl & 0xF00) << 4) | ((gb->hl & 0xF000) >> 4);
    aiv_gb_set_flag(gb, CARRY, 0);
    aiv_gb_set_flag(gb, ZERO, gb->hl == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 16;
}

//SWAP A
int aiv_gb_prefix_cb_37(aiv_gameboy *gb)
{
    gb->a = ((gb->a & 0x0F) << 4) | ((gb->a & 0xF0) >> 4);
    aiv_gb_set_flag(gb, CARRY, 0);
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRL B
int aiv_gb_prefix_cb_38(aiv_gameboy *gb)
{
    gb->b = (gb->b >> 1);
    aiv_gb_set_flag(gb, CARRY, (gb->b & 1));
    aiv_gb_set_flag(gb, ZERO, gb->b == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRL C
int aiv_gb_prefix_cb_39(aiv_gameboy *gb)
{
    gb->c = (gb->c >> 1);
    aiv_gb_set_flag(gb, CARRY, (gb->c& 1));
    aiv_gb_set_flag(gb, ZERO, gb->c == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRL D
int aiv_gb_prefix_cb_3a(aiv_gameboy *gb)
{
    gb->d = (gb->d >> 1);
	aiv_gb_set_flag(gb, CARRY, (gb->d & 1));
    aiv_gb_set_flag(gb, ZERO, gb->d == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRL E
int aiv_gb_prefix_cb_3b(aiv_gameboy *gb)
{
    gb->e = (gb->e >> 1);
	aiv_gb_set_flag(gb, CARRY, (gb->e & 1));
    aiv_gb_set_flag(gb, ZERO, gb->e == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRA H
int aiv_gb_prefix_cb_3c(aiv_gameboy *gb)
{
    gb->h = (gb->h >> 1);
	aiv_gb_set_flag(gb, CARRY, (gb->h & 1));
    aiv_gb_set_flag(gb, ZERO, gb->h == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRL L
int aiv_gb_prefix_cb_3d(aiv_gameboy *gb)
{
    gb->l = (gb->l >> 1);
	aiv_gb_set_flag(gb, CARRY, (gb->l & 1));
    aiv_gb_set_flag(gb, ZERO, gb->l == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

//SRL HL
int aiv_gb_prefix_cb_3e(aiv_gameboy *gb)
{
    gb->hl = (gb->hl >> 1);
    aiv_gb_set_flag(gb, CARRY, (gb->hl & 1));
    aiv_gb_set_flag(gb, ZERO, gb->hl == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 16;
}

//SRL A
int aiv_gb_prefix_cb_3f(aiv_gameboy *gb)
{
    gb->a = (gb->a >> 1);
	aiv_gb_set_flag(gb, CARRY, (gb->a & 1));
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 8;
}

void aiv_gb_register_prefix_cb_30(aiv_gameboy *gb)
{
    gb->prefix_opcodes[0x30] = aiv_gb_prefix_cb_30;
    gb->prefix_opcodes[0x31] = aiv_gb_prefix_cb_31;
    gb->prefix_opcodes[0x32] = aiv_gb_prefix_cb_32;
    gb->prefix_opcodes[0x33] = aiv_gb_prefix_cb_33;
    gb->prefix_opcodes[0x34] = aiv_gb_prefix_cb_34;
    gb->prefix_opcodes[0x35] = aiv_gb_prefix_cb_35;
    gb->prefix_opcodes[0x36] = aiv_gb_prefix_cb_36;
    gb->prefix_opcodes[0x37] = aiv_gb_prefix_cb_37;

    gb->prefix_opcodes[0x38] = aiv_gb_prefix_cb_38;
    gb->prefix_opcodes[0x39] = aiv_gb_prefix_cb_39;
    gb->prefix_opcodes[0x3a] = aiv_gb_prefix_cb_3a;
    gb->prefix_opcodes[0x3b] = aiv_gb_prefix_cb_3b;
    gb->prefix_opcodes[0x3c] = aiv_gb_prefix_cb_3c;
    gb->prefix_opcodes[0x3d] = aiv_gb_prefix_cb_3d;
    gb->prefix_opcodes[0x3e] = aiv_gb_prefix_cb_3e;
    gb->prefix_opcodes[0x3f] = aiv_gb_prefix_cb_3f;
}

