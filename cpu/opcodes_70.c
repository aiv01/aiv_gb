#include <aiv_gb.h>

// LD (HL), B
static int aiv_gb_opcode_70(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->b, gb->hl);
    return 8;
}

// LD (HL), C
static int aiv_gb_opcode_71(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->c, gb->hl);
    return 8;
}

// LD (HL), D
static int aiv_gb_opcode_72(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->d, gb->hl);
    return 8;
}

// LD (HL), E
static int aiv_gb_opcode_73(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->e, gb->hl);
    return 8;
}

// LD (HL), H
static int aiv_gb_opcode_74(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->h, gb->hl);
    return 8;
}

// LD (HL), L
static int aiv_gb_opcode_75(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->l, gb->hl);
    return 8;
}

//HALT
static int aiv_gb_opcode_76(aiv_gameboy *gb)
{
    printf("HALT");
    return 4;
}

// LD (HL), A
static int aiv_gb_opcode_77(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->a, gb->hl);
    return 8;
}

// LD A, B
static int aiv_gb_opcode_78(aiv_gameboy *gb)
{
    gb->b = gb->a;
    return 4;
}

// LD A, C
static int aiv_gb_opcode_79(aiv_gameboy *gb)
{
    gb->c = gb->a;
    return 4;
}

// LD A, D
static int aiv_gb_opcode_7A(aiv_gameboy *gb)
{
    gb->d = gb->a;
    return 4;
}

// LD A, E
static int aiv_gb_opcode_7B(aiv_gameboy *gb)
{
    gb->e = gb->a;
    return 4;
}

// LD A, H
static int aiv_gb_opcode_7C(aiv_gameboy *gb)
{
    gb->h = gb->a;
    return 4;
}

// LD A, L
static int aiv_gb_opcode_7D(aiv_gameboy *gb)
{
    gb->l = gb->a;
    return 4;
}

// LD A, (HL)
static int aiv_gb_opcode_7E(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->hl, gb->a);
    return 8;
}

// LD A, A
static int aiv_gb_opcode_7F(aiv_gameboy *gb)
{
    gb->a = gb->a;
    return 4;
}

void aiv_gb_register_opcodes_70(aiv_gameboy *gb)
{
    gb->opcodes[0x70] = aiv_gb_opcode_70;
    gb->opcodes[0x71] = aiv_gb_opcode_71;
    gb->opcodes[0x72] = aiv_gb_opcode_72;
    gb->opcodes[0x73] = aiv_gb_opcode_73;
    gb->opcodes[0x74] = aiv_gb_opcode_74;
    gb->opcodes[0x75] = aiv_gb_opcode_75;
    gb->opcodes[0x76] = aiv_gb_opcode_76;
    gb->opcodes[0x77] = aiv_gb_opcode_77;
    gb->opcodes[0x78] = aiv_gb_opcode_78;
    gb->opcodes[0x79] = aiv_gb_opcode_79;
    gb->opcodes[0x7a] = aiv_gb_opcode_7A;
    gb->opcodes[0x7b] = aiv_gb_opcode_7B;
    gb->opcodes[0x7c] = aiv_gb_opcode_7C;
    gb->opcodes[0x7d] = aiv_gb_opcode_7D;
    gb->opcodes[0x7e] = aiv_gb_opcode_7E;
    gb->opcodes[0x7f] = aiv_gb_opcode_7F;
}