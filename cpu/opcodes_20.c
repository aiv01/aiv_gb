#include <aiv_gb.h>

// JR NZ, r8
static int aiv_gb_opcode_20(aiv_gameboy *gb)
{
    s8_t val = aiv_gb_memory_read8(gb, gb->pc++);

    if (aiv_gb_get_flag(gb, ZERO))
    {
        s16_t _pc = gb->pc;
        _pc += val;
        gb->pc = _pc;
        return 12;
    }
    return 8;
}

// JR Z, r8
static int aiv_gb_opcode_28(aiv_gameboy *gb)
{
    s8_t val = aiv_gb_memory_read8(gb, gb->pc);
    gb->pc += 1;

    if(aiv_gb_get_flag(gb, ZERO) == 0)
    {
        s16_t _pc = gb->pc;
        _pc += val;
        gb->pc = _pc;
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

// LD H, d8
static int aiv_gb_opcode_26(aiv_gameboy *gb)
{
    gb->h = aiv_gb_memory_read8(gb, gb->pc);
    gb->pc += 1;
    return 8;
}

// LD L, d8
static int aiv_gb_opcode_2E(aiv_gameboy *gb)
{
    gb->l = aiv_gb_memory_read8(gb, gb->pc);
    gb->pc += 1;
    return 8;
}

// INC HL
static int aiv_gb_opcode_23(aiv_gameboy *gb)
{
    gb->hl++;
    return 8;
}

// DEC HL
static int aiv_gb_opcode_2B(aiv_gameboy *gb)
{
    gb->hl--;
    return 8;
}

// INC H
static int aiv_gb_opcode_24(aiv_gameboy *gb)
{
    u8_t val = (gb->h & 0x0f) + 1;
    aiv_gb_set_flag(gb, HALF, (val == 0x10));

    aiv_gb_set_flag(gb, NEG, 0);

    gb->h++;
    aiv_gb_set_flag(gb, ZERO, (gb->h) == 0);

    return 4;
}

// DEC H
static int aiv_gb_opcode_25(aiv_gameboy *gb)
{
    u8_t val = (gb->h & 0x0f) - 1;
    aiv_gb_set_flag(gb, HALF, (val == 0xff));

    aiv_gb_set_flag(gb, NEG, 1);

    gb->h--;
    aiv_gb_set_flag(gb, ZERO, (gb->h) == 0);

    return 4;
}

// INC L
static int aiv_gb_opcode_2C(aiv_gameboy *gb)
{
    u8_t val = (gb->l & 0x0f) + 1;
    aiv_gb_set_flag(gb, HALF, (val == 0x10));

    aiv_gb_set_flag(gb, NEG, 0);

    gb->l++;
    aiv_gb_set_flag(gb, ZERO, (gb->l) == 0);

    return 4;
}

// DEC L
static int aiv_gb_opcode_2D(aiv_gameboy *gb)
{
    u8_t val = (gb->l & 0x0f) - 1;
    aiv_gb_set_flag(gb, HALF, (val == 0xff));

    aiv_gb_set_flag(gb, NEG, 1);

    gb->l--;
    aiv_gb_set_flag(gb, ZERO, (gb->l) == 0);

    return 4;
}

// LD (HL+), A
static int aiv_gb_opcode_22(aiv_gameboy *gb)
{
    u16_t val = aiv_gb_memory_read16(gb, gb->hl);
    gb->pc += 2;
    gb->hl++;

    aiv_gb_memory_write8(gb, val, gb->a);
    gb->pc += 1;
    return 8;
}

// LD A, (HL+)
static int aiv_gb_opcode_2A(aiv_gameboy *gb)
{
    u8_t val = aiv_gb_memory_read8(gb, gb->hl);
    gb->pc += 1;
    gb->hl++;

    gb->a = val;
    return 8;
}


// ADD HL, HL
static int aiv_gb_opcode_29(aiv_gameboy *gb)
{
    aiv_gb_set_flag(gb, NEG, 0);

    u16_t l = gb->l;
    aiv_gb_set_flag(gb, HALF, (l + l) / 0xff);

    u32_t hl = gb->hl + gb->hl;
    aiv_gb_set_flag(gb, CARRY, hl / 0xffff);
    gb->hl = hl % 0xffff;

    return 8;
}

// CPL
static int aiv_gb_opcode_2F(aiv_gameboy *gb)
{
    gb->a = ~gb->a;
 
    aiv_gb_set_flag(gb, NEG, 1);
    aiv_gb_set_flag(gb, HALF, 1);
    return 4;
}

// DAA
static int aiv_gb_opcode_27(aiv_gameboy *gb)
{
    // if addiction
    if (aiv_gb_get_flag(gb, NEG) == 0)
    {
        if (aiv_gb_get_flag(gb, CARRY) || gb->a > 0x99)
        { 
            gb->a += 0x60; 
            aiv_gb_set_flag(gb, CARRY, 1);
        }
        else
            aiv_gb_set_flag(gb, CARRY, 0);

        if (aiv_gb_get_flag(gb, HALF) || (gb->a & 0x0f) > 0x09)
            gb->a += 0x6;
    } 
    // if subtraction
    else 
    {
        if (aiv_gb_get_flag(gb, CARRY))
            gb->a -= 0x60;
        else
            aiv_gb_set_flag(gb, CARRY, 0);
        
        if (aiv_gb_get_flag(gb, HALF))
            gb->a -= 0x6;
    }

    aiv_gb_set_flag(gb, ZERO, (gb->a == 0));
    aiv_gb_set_flag(gb, HALF, 0);

    return 4;
}

void aiv_gb_register_opcodes_20(aiv_gameboy *gb)
{
    gb->opcodes[0x20] = aiv_gb_opcode_20;
    gb->opcodes[0x21] = aiv_gb_opcode_21;
    gb->opcodes[0x22] = aiv_gb_opcode_22;
    gb->opcodes[0x23] = aiv_gb_opcode_23;
    gb->opcodes[0x24] = aiv_gb_opcode_24;
    gb->opcodes[0x25] = aiv_gb_opcode_25;
    gb->opcodes[0x26] = aiv_gb_opcode_26;
    gb->opcodes[0x27] = aiv_gb_opcode_27;
    gb->opcodes[0x28] = aiv_gb_opcode_28;
    gb->opcodes[0x29] = aiv_gb_opcode_29;
    gb->opcodes[0x2A] = aiv_gb_opcode_2A;
    gb->opcodes[0x2B] = aiv_gb_opcode_2B;
    gb->opcodes[0x2C] = aiv_gb_opcode_2C;
    gb->opcodes[0x2D] = aiv_gb_opcode_2D;
    gb->opcodes[0x2E] = aiv_gb_opcode_2E;
    gb->opcodes[0x2F] = aiv_gb_opcode_2F;
}
