#include <aiv_gb.h>

//A | B
static int aiv_gb_opcode_b0(aiv_gameboy *gb)
{
    gb->a |= gb->b;
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, 0);
    return 4;
}
//A | C
static int aiv_gb_opcode_b1(aiv_gameboy *gb)
{
    gb->a |= gb->c;
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, 0);
    return 4;
}
//A | D
static int aiv_gb_opcode_b2(aiv_gameboy *gb)
{
    gb->a |= gb->d;
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, 0);
    return 4;
}
//A | E
static int aiv_gb_opcode_b3(aiv_gameboy *gb)
{
    gb->a |= gb->e;
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, 0);
    return 4;
}
//A | H
static int aiv_gb_opcode_b4(aiv_gameboy *gb)
{
    gb->a |= gb->h;
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, 0);
    return 4;
}
//A | L
static int aiv_gb_opcode_b5(aiv_gameboy *gb)
{
    gb->a |= gb->l;
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, 0);
    return 4;
}
//A | (HL)
static int aiv_gb_opcode_b6(aiv_gameboy *gb)
{
    gb->a |= gb->hl;
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, 0);
    return 8;
}
//A | A
static int aiv_gb_opcode_b7(aiv_gameboy *gb)
{
    gb->a |= gb->a;
    aiv_gb_set_flag(gb, ZERO, gb->a == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, 0);
    return 4;
}

//CP B
static int aiv_gb_opcode_b8(aiv_gameboy *gb)
{
    if (gb->a == gb->b)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
        aiv_gb_set_flag(gb, HALF, 1);
        aiv_gb_set_flag(gb, CARRY, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
        aiv_gb_set_flag(gb, HALF, 0);
        aiv_gb_set_flag(gb, CARRY, 0);
    }

    aiv_gb_set_flag(gb, NEG, 1);
    return 4;
}

//CP C
static int aiv_gb_opcode_b9(aiv_gameboy *gb)
{
    if (gb->a == gb->c)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
        aiv_gb_set_flag(gb, HALF, 1);
        aiv_gb_set_flag(gb, CARRY, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
        aiv_gb_set_flag(gb, HALF, 0);
        aiv_gb_set_flag(gb, CARRY, 0);
    }

    aiv_gb_set_flag(gb, NEG, 1);
    return 4;
}

//CP D
static int aiv_gb_opcode_ba(aiv_gameboy *gb)
{
    if (gb->a == gb->d)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
        aiv_gb_set_flag(gb, HALF, 1);
        aiv_gb_set_flag(gb, CARRY, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
        aiv_gb_set_flag(gb, HALF, 0);
        aiv_gb_set_flag(gb, CARRY, 0);
    }

    aiv_gb_set_flag(gb, NEG, 1);
    return 4;
}

//CP E
static int aiv_gb_opcode_bb(aiv_gameboy *gb)
{
    if (gb->a == gb->e)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
        aiv_gb_set_flag(gb, HALF, 1);
        aiv_gb_set_flag(gb, CARRY, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
        aiv_gb_set_flag(gb, HALF, 0);
        aiv_gb_set_flag(gb, CARRY, 0);
    }

    aiv_gb_set_flag(gb, NEG, 1);
    return 4;
}

//CP H
static int aiv_gb_opcode_bc(aiv_gameboy *gb)
{
    if (gb->a == gb->h)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
        aiv_gb_set_flag(gb, HALF, 1);
        aiv_gb_set_flag(gb, CARRY, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
        aiv_gb_set_flag(gb, HALF, 0);
        aiv_gb_set_flag(gb, CARRY, 0);
    }

    aiv_gb_set_flag(gb, NEG, 1);
    return 4;
}


//CP L
static int aiv_gb_opcode_bd(aiv_gameboy *gb)
{
    if (gb->a == gb->l)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
        aiv_gb_set_flag(gb, HALF, 1);
        aiv_gb_set_flag(gb, CARRY, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
        aiv_gb_set_flag(gb, HALF, 0);
        aiv_gb_set_flag(gb, CARRY, 0);
    }

    aiv_gb_set_flag(gb, NEG, 1);
    return 4;
}

// CP (HL)

//CP A
static int aiv_gb_opcode_bf(aiv_gameboy *gb)
{
    if (gb->a == gb->a)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
        aiv_gb_set_flag(gb, HALF, 1);
        aiv_gb_set_flag(gb, CARRY, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
        aiv_gb_set_flag(gb, HALF, 0);
        aiv_gb_set_flag(gb, CARRY, 0);
    }

    aiv_gb_set_flag(gb, NEG, 1);
    return 4;
}

void aiv_gb_register_opcodes_b0(aiv_gameboy *gb)
{
    gb->opcodes[0xb0] = aiv_gb_opcode_b0;
    gb->opcodes[0xb1] = aiv_gb_opcode_b1;
    gb->opcodes[0xb2] = aiv_gb_opcode_b2;
    gb->opcodes[0xb3] = aiv_gb_opcode_b3;
    gb->opcodes[0xb4] = aiv_gb_opcode_b4;
    gb->opcodes[0xb5] = aiv_gb_opcode_b5;
    gb->opcodes[0xb6] = aiv_gb_opcode_b6;
    gb->opcodes[0xb7] = aiv_gb_opcode_b7;
    gb->opcodes[0xb8] = aiv_gb_opcode_b8;
    gb->opcodes[0xb9] = aiv_gb_opcode_b9;
    gb->opcodes[0xba] = aiv_gb_opcode_ba;
    gb->opcodes[0xbb] = aiv_gb_opcode_bb;
    gb->opcodes[0xbc] = aiv_gb_opcode_bc;
    gb->opcodes[0xbd] = aiv_gb_opcode_bd;
    // gb->opcodes[0xbe] = aiv_gb_opcode_be;
    gb->opcodes[0xbf] = aiv_gb_opcode_bf;
}
