#include <aiv_gb.h>

//LD D,B
static int aiv_gb_opcode_50(aiv_gameboy *gb)
{
    gb->b = gb->d;
    return 4;
}
//LD D,C
static int aiv_gb_opcode_51(aiv_gameboy *gb)
{
    gb->c = gb->d;
    return 4;
}
//LD D,D
static int aiv_gb_opcode_52(aiv_gameboy *gb)
{
    gb->d = gb->d;
    return 4;
}
//LD D,E
static int aiv_gb_opcode_53(aiv_gameboy *gb)
{
    gb->e = gb->d;
    return 4;
}
//LD D,H
static int aiv_gb_opcode_54(aiv_gameboy *gb)
{
    gb->h = gb->d;
    return 4;
}
//LD D,L
static int aiv_gb_opcode_55(aiv_gameboy *gb)
{
    gb->l = gb->d;
    return 4;
}

/////////////////////////////////////////////////////////////////////////

//LD D,(HL)
static int aiv_gb_opcode_56(aiv_gameboy *gb)
{
    gb->d = aiv_gb_memory_read8(gb, gb->hl);
    return 8;
}

/////////////////////////////////////////////////////////////////////////

//LD D,A
static int aiv_gb_opcode_57(aiv_gameboy *gb)
{
    gb->a = gb->d;
    return 4;
}
//LD E,B
static int aiv_gb_opcode_58(aiv_gameboy *gb)
{
    gb->b = gb->e;
    return 4;
}
//LD E,C
static int aiv_gb_opcode_59(aiv_gameboy *gb)
{
    gb->c = gb->e;
    return 4;
}
//LD E,D
static int aiv_gb_opcode_5A(aiv_gameboy *gb)
{
    gb->d = gb->e;
    return 4;
}
//LD E,E
static int aiv_gb_opcode_5B(aiv_gameboy *gb)
{
    gb->e = gb->e;
    return 4;
}
//LD E,H
static int aiv_gb_opcode_5C(aiv_gameboy *gb)
{
    gb->h = gb->e;
    return 4;
}
//LD E,L
static int aiv_gb_opcode_5D(aiv_gameboy *gb)
{
    gb->l = gb->e;
    return 4;
}

////////////////////////////////////////////////////

//LD E,HL
static int aiv_gb_opcode_5E(aiv_gameboy *gb)
{
   gb->e = aiv_gb_memory_read8(gb, gb->hl);
    return 8;
}

//////////////////////////////////////////////////

//LD E,A
static int aiv_gb_opcode_5F(aiv_gameboy *gb)
{
    gb->a = gb->e;
    return 4;
}
void aiv_gb_register_opcodes_50(aiv_gameboy *gb)
{
    gb->opcodes[0x50] = aiv_gb_opcode_50;
    gb->opcodes[0x51] = aiv_gb_opcode_51;
    gb->opcodes[0x52] = aiv_gb_opcode_52;
    gb->opcodes[0x53] = aiv_gb_opcode_53;
    gb->opcodes[0x54] = aiv_gb_opcode_54;
    gb->opcodes[0x55] = aiv_gb_opcode_55;
    gb->opcodes[0x56] = aiv_gb_opcode_56;
    gb->opcodes[0x57] = aiv_gb_opcode_57;
    gb->opcodes[0x58] = aiv_gb_opcode_58;
    gb->opcodes[0x59] = aiv_gb_opcode_59;
    gb->opcodes[0x5a] = aiv_gb_opcode_5A;
    gb->opcodes[0x5b] = aiv_gb_opcode_5B;
    gb->opcodes[0x5c] = aiv_gb_opcode_5C;
    gb->opcodes[0x5d] = aiv_gb_opcode_5D;
    gb->opcodes[0x5e] = aiv_gb_opcode_5E;
    gb->opcodes[0x5f] = aiv_gb_opcode_5F;
}