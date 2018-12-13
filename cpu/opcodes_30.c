#include <aiv_gb.h>

// NOP
//static int aiv_gb_opcode_30(aiv_gameboy *gb)
//{
//    return 4;
//}

// LD SP, d16
static int aiv_gb_opcode_31(aiv_gameboy *gb)
{
    gb->sp = aiv_gb_memory_read16(gb, gb->pc);
    gb->pc += 2;
    return 12;
}

void aiv_gb_register_opcodes_30(aiv_gameboy *gb)
{
    //gb->opcodes[0x30] = aiv_gb_opcode_30;
    gb->opcodes[0x31] = aiv_gb_opcode_31;
}