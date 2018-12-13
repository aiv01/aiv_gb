#include <aiv_gb.h>

// JR NZ, r8
static int aiv_gb_opcode_20(aiv_gameboy *gb)
{
    if(GET_Z(gb) == 0)
    {
        gb->pc += aiv_gb_memory_read8(gb, gb->pc);
        return 12;
    }
    return 8;
}

// LD HL, d16
static int aiv_gb_opcode_21(aiv_gameboy *gb)
{
    gb->hl = aiv_gb_memory_read16(gb, gb->pc);
    gb->pc += 2;
    return 12;
}

void aiv_gb_register_opcodes_20(aiv_gameboy *gb)
{
    gb->opcodes[0x20] = aiv_gb_opcode_20;
    gb->opcodes[0x21] = aiv_gb_opcode_21;

}