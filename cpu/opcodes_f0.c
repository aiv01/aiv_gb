#include <aiv_gb.h>
#define START_IO_REGISTER 0xFF00

// LDH A, (a8)
static int aiv_gb_opcode_f0(aiv_gameboy *gb)
{
    u8_t a8 = aiv_gb_memory_read8(gb, gb->pc);
    aiv_gb_memory_write8(gb, gb->a, START_IO_REGISTER + a8);
    gb->pc++;
    return 12;
}

//POP AF
static int aiv_gb_opcode_f1(aiv_gameboy *gb)
{
    gb->af = aiv_gb_memory_read16(gb, gb->sp + 1);
    gb->sp += 2;
    return 12;
}

//LD (A) C
static int aiv_gb_opcode_f2(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->a, START_IO_REGISTER + gb->c);
    return 12;
}

//PUSH AF
static int aiv_gb_opcode_f5(aiv_gameboy *gb)
{
    aiv_gb_memory_write16(gb, gb->sp - 2, gb->af);
    gb->sp -= 2;
    return 16;
}

// OR d8
static int aiv_gb_opcode_f6(aiv_gameboy *gb)
{
    u8_t d8 = aiv_gb_memory_read8(gb, gb->pc);

    if ((gb->a | d8) == 0)
        aiv_gb_set_flag(gb, ZERO, 0);
    else
        aiv_gb_set_flag(gb, ZERO, 1);

    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, CARRY, 0);
    aiv_gb_set_flag(gb, HALF, 0);

    gb->a |= d8;
    gb->pc++;
    return 8;
}

//RST 30H
static int aiv_gb_opcode_f7(aiv_gameboy *gb)
{
    aiv_gb_memory_write16(gb, gb->sp - 2, gb->pc);
    gb->pc = 0x0030;
    gb->sp -= 2;
    return 16;
}

// LD SP, HL
static int aiv_gb_opcode_f9(aiv_gameboy *gb)
{
    gb->sp = gb->hl;
    return 8;
}

// LD A, (a16)
static int aiv_gb_opcode_fa(aiv_gameboy *gb)
{
    u16_t a16 = aiv_gb_memory_read16(gb, gb->pc);
    aiv_gb_memory_write16(gb, gb->a, START_IO_REGISTER + a16);
    gb->pc++;
    return 16;
}

// CP d8
static int aiv_gb_opcode_fe(aiv_gameboy *gb)
{
    u8_t value = aiv_gb_memory_read8(gb, gb->pc++);
    u8_t cp = gb->a - value;

    aiv_gb_set_flag(gb, ZERO, cp == 0);
    aiv_gb_set_flag(gb, HALF, (((gb->a & 0xf) - (value & 0x0f)) & 0x10) == 0x10);
    aiv_gb_set_flag(gb, CARRY, gb->a < value);
    aiv_gb_set_flag(gb, NEG, 1);
    return 8;
}

//RST 38H
static int aiv_gb_opcode_ff(aiv_gameboy *gb)
{
    aiv_gb_memory_write16(gb, gb->sp - 1, gb->pc);
    gb->sp -= 2;

    gb->pc = 0x0038;

    return 16;
}

void aiv_gb_register_opcodes_f0(aiv_gameboy *gb)
{
    gb->opcodes[0xf0] = aiv_gb_opcode_f0;
    gb->opcodes[0xf1] = aiv_gb_opcode_f1;
    gb->opcodes[0xf2] = aiv_gb_opcode_f2;
    gb->opcodes[0xf5] = aiv_gb_opcode_f5;
    gb->opcodes[0xf6] = aiv_gb_opcode_f6;
    gb->opcodes[0xf7] = aiv_gb_opcode_f7;
    gb->opcodes[0xf9] = aiv_gb_opcode_f9;
    gb->opcodes[0xfa] = aiv_gb_opcode_fa;
    gb->opcodes[0xfe] = aiv_gb_opcode_fe;
    gb->opcodes[0xff] = aiv_gb_opcode_ff;
}
