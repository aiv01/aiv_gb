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
    u16_t addr = START_IO_REGISTER + gb->c;
    aiv_gb_memory_write8(gb, addr, gb->a);
    return 12;
}

//PUSH HL
static int aiv_gb_opcode_e5(aiv_gameboy *gb)
{
    aiv_gb_memory_write16(gb, gb->sp - 1, gb->hl);
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
    aiv_gb_memory_write16(gb, gb->sp - 1, gb->pc);
    gb->pc = 0x0020;
    gb->sp -= 2;
    return 16;
}

//ADD SP, r8
static int aiv_gb_opcode_e8(aiv_gameboy *gb)
{
    s8_t r8 = aiv_gb_memory_read8(gb, gb->pc);
    u16_t pre_sp = gb->sp;

    if (r8 > 127)
    {
        r8 = -((~r8 + 1) & 255);
    }

    aiv_gb_set_flag(gb, ZERO, 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, (((gb->sp & 0x0f) - r8) & 0xf0));
    gb->pc++;
    gb->sp += r8;
    aiv_gb_set_flag(gb, CARRY, gb->sp < pre_sp);

    return 16;
}

//JP (HL)
static int aiv_gb_opcode_e9(aiv_gameboy *gb)
{
    gb->pc = aiv_gb_memory_read16(gb, gb->hl);
    return 4;
}

//LD (a16) A
static int aiv_gb_opcode_eA(aiv_gameboy *gb)
{
    u16_t a16 = aiv_gb_memory_read16(gb, gb->pc);
    aiv_gb_memory_write8(gb, a16, gb->a);
    gb->pc += 2;
    return 16;
}

//XOR d8
static int aiv_gb_opcode_eE(aiv_gameboy *gb)
{
    u8_t d8 = aiv_gb_memory_read8(gb, gb->pc);
    gb->a ^= d8;
    if (gb->a == 0)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
    }
    aiv_gb_set_flag(gb, CARRY, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, NEG, 0);
    return 8;
}

//RST 28H
static int aiv_gb_opcode_eF(aiv_gameboy *gb)
{
    aiv_gb_memory_write16(gb, gb->sp - 1, gb->pc);
    gb->pc = 0x0028;
    gb->sp -= 2;
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
    gb->opcodes[0xe9] = aiv_gb_opcode_e9;
    gb->opcodes[0xeA] = aiv_gb_opcode_eA;
    gb->opcodes[0xeE] = aiv_gb_opcode_eE;
    gb->opcodes[0xeF] = aiv_gb_opcode_eF;
}