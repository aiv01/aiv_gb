#include <aiv_gb.h>

// NOP
static int aiv_gb_opcode_00(aiv_gameboy *gb)
{
    return 4;
}

// LD BC, d16
static int aiv_gb_opcode_01(aiv_gameboy *gb)
{
    gb->bc = aiv_gb_memory_read16(gb, gb->pc);
    gb->pc += 2;
    return 12;
}

// LD (BC), A
static int aiv_gb_opcode_02(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->bc, gb->a);
    return 8;
}

void aiv_gb_register_opcodes_00(aiv_gameboy *gb)
{
    gb->opcodes[0x00] = aiv_gb_opcode_00;
    gb->opcodes[0x01] = aiv_gb_opcode_01;
    gb->opcodes[0x02] = aiv_gb_opcode_02;
}
