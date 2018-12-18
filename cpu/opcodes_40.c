#include <aiv_gb.h>

// LD B,B
static int aiv_gb_opcode_40(aiv_gameboy *gb)
{
    gb->b = gb->b;

    return 4;
}

// LD B,C
static int aiv_gb_opcode_41(aiv_gameboy *gb)
{
    gb->b = gb->c;
 
    return 4;
}

// LD B,D
static int aiv_gb_opcode_42(aiv_gameboy *gb)
{
    gb->b = gb->d;

    return 4;
}

// LD B,E
static int aiv_gb_opcode_43(aiv_gameboy *gb)
{
    gb->b = gb->e;

    return 4;
}

// LD B,H
static int aiv_gb_opcode_44(aiv_gameboy *gb)
{
    gb->b = gb->h;

    return 4;
}

// LD B,L
static int aiv_gb_opcode_45(aiv_gameboy *gb)
{
    gb->b = gb->l;

    return 4;
}

// LD B,(HL)
static int aiv_gb_opcode_46(aiv_gameboy *gb)
{

    gb->b = aiv_gb_memory_read8(gb, gb->hl);

    return 8;
}

// LD B,A
static int aiv_gb_opcode_47(aiv_gameboy *gb)
{
    gb->b = gb->a;

    return 4;
}

// LD C,B
static int aiv_gb_opcode_48(aiv_gameboy *gb)
{
    gb->c = gb->b;

    return 4;
}

// LD C,C
static int aiv_gb_opcode_49(aiv_gameboy *gb)
{
    gb->c = gb->c;

    return 4;
}

// LD C,D
static int aiv_gb_opcode_4a(aiv_gameboy *gb)
{
    gb->c = gb->d;

    return 4;
}

// LD C,E
static int aiv_gb_opcode_4b(aiv_gameboy *gb)
{
    gb->c = gb->e;

    return 4;
}

// LD C,H
static int aiv_gb_opcode_4c(aiv_gameboy *gb)
{
    gb->c = gb->h;
  
    return 4;
}

// LD C,L
static int aiv_gb_opcode_4d(aiv_gameboy *gb)
{
    gb->c = gb->l;
  
    return 4;
}

// LD C,(HL)
static int aiv_gb_opcode_4e(aiv_gameboy *gb)
{
    gb->c = aiv_gb_memory_read8(gb, gb->hl);
 
    return 8;
}

// LD C,A
static int aiv_gb_opcode_4f(aiv_gameboy *gb)
{
    gb->c = gb->a;

    return 4;
}

void aiv_gb_register_opcodes_40(aiv_gameboy *gb)
{
    gb->opcodes[0x40] = aiv_gb_opcode_40;
    gb->opcodes[0x41] = aiv_gb_opcode_41;
    gb->opcodes[0x42] = aiv_gb_opcode_42;
    gb->opcodes[0x43] = aiv_gb_opcode_43;

    gb->opcodes[0x44] = aiv_gb_opcode_44;
    gb->opcodes[0x45] = aiv_gb_opcode_45;
    gb->opcodes[0x46] = aiv_gb_opcode_46;
    gb->opcodes[0x47] = aiv_gb_opcode_47;

    gb->opcodes[0x48] = aiv_gb_opcode_48;
    gb->opcodes[0x49] = aiv_gb_opcode_49;
    gb->opcodes[0x4a] = aiv_gb_opcode_4a;
    gb->opcodes[0x4b] = aiv_gb_opcode_4b;

    gb->opcodes[0x4c] = aiv_gb_opcode_4c;
    gb->opcodes[0x4d] = aiv_gb_opcode_4d;
    gb->opcodes[0x4e] = aiv_gb_opcode_4e;
    gb->opcodes[0x4f] = aiv_gb_opcode_4f;
}
