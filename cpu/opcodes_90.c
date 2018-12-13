#include <aiv_gb.h>

void _aiv_gb_set_flags_internal(aiv_gameboy *gb);
static void _aiv_gb_set_flags_internal(aiv_gameboy *gb)
{
    if (gb->a)
    {
        UNSET_Z(gb);
    }
    else
    {
        SET_Z(gb);
    }

    if (((gb->a & 0x0f) + 1) & 0xf0)
    {
        SET_H(gb);
    }
    else
    {
        UNSET_H(gb);
    }

    SET_N(gb);
}
//SUB B
static int aiv_gb_opcode_90(aiv_gameboy *gb)
{
    gb->a -= gb->b;

    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SUB C
static int aiv_gb_opcode_91(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SUB D
static int aiv_gb_opcode_92(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SUB E
static int aiv_gb_opcode_93(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SUB H
static int aiv_gb_opcode_94(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SUB L
static int aiv_gb_opcode_95(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SUB (HL)
static int aiv_gb_opcode_96(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 8;
}

//SUB A
static int aiv_gb_opcode_97(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SBC A,B
static int aiv_gb_opcode_98(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SBC A,C
static int aiv_gb_opcode_99(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SBC A,D
static int aiv_gb_opcode_9a(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SBC A,E
static int aiv_gb_opcode_9b(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SBC A,H
static int aiv_gb_opcode_9c(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SBC A,L
static int aiv_gb_opcode_9d(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 4;
}

//SBC A,(HL)
static int aiv_gb_opcode_9e(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

    return 8;
}

//SBC A,A
static int aiv_gb_opcode_9f(aiv_gameboy *gb)
{
    _aiv_gb_set_flags_internal(gb);

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