#include <aiv_gb.h>

// JR NZ, r8
static int aiv_gb_opcode_20(aiv_gameboy *gb)
{
    gb->bc = aiv_gb_memory_read16(gb, gb->pc);
    gb->pc += 2;
    return 12;
}

void aiv_gb_register_opcodes_20(aiv_gameboy *gb)
{
    gb->opcodes[0x20] = aiv_gb_opcode_20;
}