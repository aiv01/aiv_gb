#include <aiv_gb.h>

// JR NZ, r8
static int aiv_gb_opcode_20(aiv_gameboy *gb)
{
    if(GET_Z(gb))
    {
        gb->pc += aiv_gb_memory_read8(gb, gb->pc);
        return 12;
    }
    return 8;
}



void aiv_gb_register_opcodes_20(aiv_gameboy *gb)
{
    gb->opcodes[0x20] = aiv_gb_opcode_20;
}
