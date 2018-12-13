#include <aiv_gb.h>
#define START_IO_REGISTER 0xFF00

// LDH [n8], A
static int aiv_gb_opcode_e0(aiv_gameboy *gb)
{
    u8_t n8 = gb->pc;
    aiv_gb_memory_write8(gb, START_IO_REGISTER + n8, gb->a);
    gb->pc++;
    return 12;
}

//POP HL
static int aiv_gb_opcode_e1(aiv_gameboy *gb)
{
    gb->hl = aiv_gb_memory_read16(gb, gb->sp + 1);
    gb->sp += 2;
    return 12;
}

//LD (C) A
static int aiv_gb_opcode_e2(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, START_IO_REGISTER + gb->c, gb->a);
    return 12;
}

void aiv_gb_register_opcodes_e0(aiv_gameboy *gb)
{
    gb->opcodes[0xe0] = aiv_gb_opcode_e0;
    gb->opcodes[0xe1] = aiv_gb_opcode_e1;
    gb->opcodes[0xe2] = aiv_gb_opcode_e2;
}