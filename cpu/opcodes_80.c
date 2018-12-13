#include <aiv_gb.h>

static int check_set_h(aiv_gameboy *gb)
{
    u8_t value = gb->a & 0x0f;
    value += 1;

    if (value > 0x08)
        return 1;

    return 0;
}

static int aiv_gb_opcode_80(aiv_gameboy *gb)
{
    gb->a += gb->b;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_81(aiv_gameboy *gb)
{
    gb->a += gb->c;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_82(aiv_gameboy *gb)
{
    gb->a += gb->d;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_83(aiv_gameboy *gb)
{
    gb->a += gb->e;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_84(aiv_gameboy *gb)
{
    gb->a += gb->h;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_85(aiv_gameboy *gb)
{
    gb->a += gb->l;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_86(aiv_gameboy *gb)
{
    gb->a += gb->hl;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_87(aiv_gameboy *gb)
{
    gb->a += gb->a;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}
static int aiv_gb_opcode_88(aiv_gameboy *gb)
{
    gb->a += gb->b;

    if (gb->f == 0x10)
        gb->a += 1;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_89(aiv_gameboy *gb)
{
    gb->a += gb->c;

    if (gb->f == 0x10)
        gb->a += 1;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_8a(aiv_gameboy *gb)
{
    gb->a += gb->d;

    if (gb->f == 0x10)
        gb->a += 1;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_8b(aiv_gameboy *gb)
{
    gb->a += gb->e;

    if (gb->f == 0x10)
        gb->a += 1;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_8c(aiv_gameboy *gb)
{
    gb->a += gb->h;

    if (gb->f == 0x10)
        gb->a += 1;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_8d(aiv_gameboy *gb)
{
    gb->a += gb->l;

    if (gb->f == 0x10)
        gb->a += 1;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_8e(aiv_gameboy *gb)
{
    gb->a += gb->hl;

    if (gb->f == 0x10)
        gb->a += 1;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

static int aiv_gb_opcode_8f(aiv_gameboy *gb)
{
    gb->a += gb->a;

    if (gb->f == 0x10)
        gb->a += 1;

    if (gb->a == 0)
        SET_Z(gb);

    if (check_set_h(gb) == 1)
        SET_H(gb);

    UNSET_N(gb);

    return 4;
}

void aiv_gb_register_opcodes_80(aiv_gameboy *gb)
{
    gb->opcodes[0x80] = aiv_gb_opcode_80;
    gb->opcodes[0x81] = aiv_gb_opcode_81;
    gb->opcodes[0x82] = aiv_gb_opcode_82;
    gb->opcodes[0x83] = aiv_gb_opcode_83;
    gb->opcodes[0x84] = aiv_gb_opcode_84;
    gb->opcodes[0x85] = aiv_gb_opcode_85;
    gb->opcodes[0x86] = aiv_gb_opcode_86;
    gb->opcodes[0x87] = aiv_gb_opcode_87;
    gb->opcodes[0x88] = aiv_gb_opcode_88;
    gb->opcodes[0x89] = aiv_gb_opcode_89;
    gb->opcodes[0x8a] = aiv_gb_opcode_8a;
    gb->opcodes[0x8b] = aiv_gb_opcode_8b;
    gb->opcodes[0x8c] = aiv_gb_opcode_8c;
    gb->opcodes[0x8d] = aiv_gb_opcode_8d;
    gb->opcodes[0x8e] = aiv_gb_opcode_8e;
    gb->opcodes[0x8f] = aiv_gb_opcode_8f;
}