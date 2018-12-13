#include <aiv_gb.h>

// LD H, B
static int aiv_gb_opcode_60(aiv_gameboy *gb)
{
    gb->h = gb->b;
    return 4;
}

// LD H, C
static int aiv_gb_opcode_61(aiv_gameboy *gb)
{
    gb->h = gb->c;
    return 4;
}

// LD H, D
static int aiv_gb_opcode_62(aiv_gameboy *gb)
{
    gb->h = gb->d;
    return 4;
}

// LD H, E
static int aiv_gb_opcode_63(aiv_gameboy *gb)
{
    gb->h = gb->e;
    return 4;
}

// LD H, H
static int aiv_gb_opcode_64(aiv_gameboy *gb)
{
    gb->h = gb->h;
    return 4;
}

// LD H, L
static int aiv_gb_opcode_65(aiv_gameboy *gb)
{
    gb->h = gb->l;
    return 4;
}

// LD H, (HL)
static int aiv_gb_opcode_66(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->hl, gb->h);
    return 8;
}

// LD H, A
static int aiv_gb_opcode_67(aiv_gameboy *gb)
{
    gb->h = gb->a;
    return 4;
}

// LD L, B
static int aiv_gb_opcode_68(aiv_gameboy *gb)
{
   gb->l = gb->b;
    return 4;
}

// LD L, C
static int aiv_gb_opcode_69(aiv_gameboy *gb)
{
    gb->l = gb->c;
    return 4;
}

// LD L, D
static int aiv_gb_opcode_6a(aiv_gameboy *gb)
{
    gb->l = gb->d;
    return 4;
}

// LD L, E
static int aiv_gb_opcode_6b(aiv_gameboy *gb)
{
    gb->l = gb->e;
    return 4;
}

// LD L, H
static int aiv_gb_opcode_6c(aiv_gameboy *gb)
{
    gb->l = gb->h;
    return 4;
}

// LD L, L
static int aiv_gb_opcode_6d(aiv_gameboy *gb)
{
    gb->l = gb->l;
    return 4;
}

// LD L, (HL)
static int aiv_gb_opcode_6e(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->hl, gb->l);
    return 8;
}

// LD L, A
static int aiv_gb_opcode_6f(aiv_gameboy *gb)
{
    gb->l = gb->a;
    return 4;
}

void aiv_gb_register_opcodes_60(aiv_gameboy *gb)
{
    gb->opcodes[0x60] = aiv_gb_opcode_60;
    gb->opcodes[0x61] = aiv_gb_opcode_61;
    gb->opcodes[0x62] = aiv_gb_opcode_62;
    gb->opcodes[0x63] = aiv_gb_opcode_63;
    gb->opcodes[0x64] = aiv_gb_opcode_64;
    gb->opcodes[0x65] = aiv_gb_opcode_65;
    gb->opcodes[0x66] = aiv_gb_opcode_66;
    gb->opcodes[0x67] = aiv_gb_opcode_67;
    gb->opcodes[0x68] = aiv_gb_opcode_68;
    gb->opcodes[0x69] = aiv_gb_opcode_69;
    gb->opcodes[0x6a] = aiv_gb_opcode_6a;
    gb->opcodes[0x6b] = aiv_gb_opcode_6b;
    gb->opcodes[0x6c] = aiv_gb_opcode_6c;
    gb->opcodes[0x6d] = aiv_gb_opcode_6d;
    gb->opcodes[0x6e] = aiv_gb_opcode_6e;
    gb->opcodes[0x6f] = aiv_gb_opcode_6f;
}
