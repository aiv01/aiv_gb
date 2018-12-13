#include <aiv_gb.h>
#define IS_CARRY_SETTED(gb) (aiv_gb_get_flag(gb, CARRY) != 0)
void _aiv_gb_sub(aiv_gameboy *gb, u8_t to_sub)
{
    aiv_gb_set_flag(gb, CARRY, gb->a < to_sub);
    aiv_gb_set_flag(gb, HALF, (((gb->a & 0x0f) - to_sub) & 0xf0));
    gb->a -= to_sub;
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 1);
}
//SUB B
static int aiv_gb_opcode_90(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->b);

    return 4;
}

//SUB C
static int aiv_gb_opcode_91(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->c);

    return 4;
}

//SUB D
static int aiv_gb_opcode_92(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->d);

    return 4;
}

//SUB E
static int aiv_gb_opcode_93(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->e);

    return 4;
}

//SUB H
static int aiv_gb_opcode_94(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->h);

    return 4;
}

//SUB L
static int aiv_gb_opcode_95(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->l);

    return 4;
}

//SUB (HL)
static int aiv_gb_opcode_96(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, aiv_gb_memory_read8(gb, gb->hl));

    return 8;
}

//SUB A
static int aiv_gb_opcode_97(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->a);

    return 4;
}

//SBC A,B
static int aiv_gb_opcode_98(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->b + IS_CARRY_SETTED(gb));

    return 4;
}

//SBC A,C
static int aiv_gb_opcode_99(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->c + IS_CARRY_SETTED(gb));

    return 4;
}

//SBC A,D
static int aiv_gb_opcode_9a(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->d + IS_CARRY_SETTED(gb));

    return 4;
}

//SBC A,E
static int aiv_gb_opcode_9b(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->e + IS_CARRY_SETTED(gb));

    return 4;
}

//SBC A,H
static int aiv_gb_opcode_9c(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->h + IS_CARRY_SETTED(gb));

    return 4;
}

//SBC A,L
static int aiv_gb_opcode_9d(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->l + IS_CARRY_SETTED(gb));

    return 4;
}

//SBC A,(HL)
static int aiv_gb_opcode_9e(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, aiv_gb_memory_read8(gb, gb->hl) + IS_CARRY_SETTED(gb));

    return 8;
}

//SBC A,A
static int aiv_gb_opcode_9f(aiv_gameboy *gb)
{
    _aiv_gb_sub(gb, gb->a + IS_CARRY_SETTED(gb));

    return 4;
}

void aiv_gb_register_opcodes_90(aiv_gameboy *gb)
{
    gb->opcodes[0x90] = aiv_gb_opcode_90;
    gb->opcodes[0x91] = aiv_gb_opcode_91;
    gb->opcodes[0x92] = aiv_gb_opcode_92;
    gb->opcodes[0x93] = aiv_gb_opcode_93;
    gb->opcodes[0x94] = aiv_gb_opcode_94;
    gb->opcodes[0x95] = aiv_gb_opcode_95;
    gb->opcodes[0x96] = aiv_gb_opcode_96;
    gb->opcodes[0x97] = aiv_gb_opcode_97;
    gb->opcodes[0x98] = aiv_gb_opcode_98;
    gb->opcodes[0x99] = aiv_gb_opcode_99;
    gb->opcodes[0x9a] = aiv_gb_opcode_9a;
    gb->opcodes[0x9b] = aiv_gb_opcode_9b;
    gb->opcodes[0x9c] = aiv_gb_opcode_9c;
    gb->opcodes[0x9d] = aiv_gb_opcode_9d;
    gb->opcodes[0x9e] = aiv_gb_opcode_9e;
    gb->opcodes[0x9f] = aiv_gb_opcode_9f;
}
