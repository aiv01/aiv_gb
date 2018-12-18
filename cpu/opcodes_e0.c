#include <aiv_gb.h>
#define START_IO_REGISTER 0xFF00

// LDH [n8], A
static int aiv_gb_opcode_e0(aiv_gameboy *gb)
{
    u8_t n8 = aiv_gb_memory_read8(gb, gb->pc);
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

//PUSH HL
static int aiv_gb_opcode_e5(aiv_gameboy *gb)
{
    aiv_gb_memory_write16(gb, gb->sp - 2, gb->hl);
    gb->sp -= 2;
    return 16;
}

//AND (d8)
static int aiv_gb_opcode_e6(aiv_gameboy *gb)
{
    u8_t d8 = aiv_gb_memory_read8(gb, gb->pc);

    if ((gb->a & d8) < 0x80)
    {
        aiv_gb_set_flag(gb, ZERO, 0);
        aiv_gb_set_flag(gb, NEG, 0);
        aiv_gb_set_flag(gb, CARRY, 0);
        aiv_gb_set_flag(gb, HALF, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 1);
        aiv_gb_set_flag(gb, NEG, 0);
        aiv_gb_set_flag(gb, CARRY, 0);
        aiv_gb_set_flag(gb, HALF, 1);
    }
    gb->a &= d8;
    gb->pc++;
    return 8;
}

//RST 20H
static int aiv_gb_opcode_e7(aiv_gameboy *gb)
{
    aiv_gb_memory_write16(gb, gb->sp - 2, gb->pc);
    gb->pc = 0x0020;
    gb->sp -= 2;
    return 16;
}

//ADD SP, r8
static int aiv_gb_opcode_e8(aiv_gameboy *gb)
{
    
    return 16;
}

void aiv_gb_register_opcodes_e0(aiv_gameboy *gb)
{
    gb->opcodes[0xe0] = aiv_gb_opcode_e0;
    gb->opcodes[0xe1] = aiv_gb_opcode_e1;
    gb->opcodes[0xe2] = aiv_gb_opcode_e2;
    gb->opcodes[0xe5] = aiv_gb_opcode_e5;
    gb->opcodes[0xe6] = aiv_gb_opcode_e6;
    gb->opcodes[0xe7] = aiv_gb_opcode_e7;
    gb->opcodes[0xe8] = aiv_gb_opcode_e8;
}