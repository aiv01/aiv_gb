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

//INC BC
static int aiv_gb_opcode_03(aiv_gameboy *gb)
{
    gb->bc++;
    return 8;
}

//DEC BC
static int aiv_gb_opcode_0b(aiv_gameboy *gb)
{
    gb->bc--;
    return 8;
}

//DEC C
static int aiv_gb_opcode_0d(aiv_gameboy *gb)
{
    u8_t val = (gb->c & 0x0f) - 1;
    aiv_gb_set_flag(gb, HALF, (val == 0x10));

    aiv_gb_set_flag(gb, NEG, 0);

    gb->c--;
    aiv_gb_set_flag(gb, ZERO, (gb->c) == 0);

    return 4;
}

//INC C
static int aiv_gb_opcode_0c(aiv_gameboy *gb)
{
    u8_t val = (gb->c & 0x0f) + 1;
    aiv_gb_set_flag(gb, HALF, (val == 0x10));

    aiv_gb_set_flag(gb, NEG, 0);

    gb->c++;
    aiv_gb_set_flag(gb, ZERO, (gb->c) == 0);

    return 4;
}

//LD (a16), SP 
static int aiv_gb_opcode_08(aiv_gameboy *gb)
{
    u16_t add = aiv_gb_memory_read16(gb, gb->pc);
    gb->pc += 2;
    aiv_gb_memory_write16(gb, add, gb->sp);
    gb->pc += 2;

    return 20;
}

//LD C, d8
static int aiv_gb_opcode_0e(aiv_gameboy *gb)
{
    gb->c = gb->pc;

    return 8;
}

void aiv_gb_register_opcodes_00(aiv_gameboy *gb)
{
    gb->opcodes[0x00] = aiv_gb_opcode_00;
    gb->opcodes[0x01] = aiv_gb_opcode_01;
    gb->opcodes[0x02] = aiv_gb_opcode_02;
    gb->opcodes[0x03] = aiv_gb_opcode_03;
    gb->opcodes[0x0b] = aiv_gb_opcode_0b;
    gb->opcodes[0x0c] = aiv_gb_opcode_0c;
    gb->opcodes[0x0d] = aiv_gb_opcode_0d;
    gb->opcodes[0x08] = aiv_gb_opcode_08;
    gb->opcodes[0x0e] = aiv_gb_opcode_0e;
}
