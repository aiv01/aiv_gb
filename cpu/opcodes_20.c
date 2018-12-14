#include <aiv_gb.h>

// JR NZ, r8
static int aiv_gb_opcode_20(aiv_gameboy *gb)
{
    s8_t val = aiv_gb_memory_read8(gb, gb->pc);
    gb->pc += 1;

    if(GET_Z(gb))
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

    if(GET_Z(gb) == 0)
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

// INC HL
static int aiv_gb_opcode_23(aiv_gameboy *gb)
{
    gb->hl++;
    return 8;
}

// INC H
static int aiv_gb_opcode_24(aiv_gameboy *gb)
{
    u8_t val = gb->h & 0x0f;
    val++;

    if(val == 0x10)
        SET_H((*gb));
    else
        UNSET_H((*gb));

    UNSET_N((*gb));

    gb->h++;
    if(gb->h == 0)
        SET_Z((*gb));
    else
        UNSET_Z((*gb));

    return 4;
}

// DEC H
static int aiv_gb_opcode_25(aiv_gameboy *gb)
{
    u8_t val = gb->h & 0x0f;
    val--;

    if(val == 0xff)
        SET_H((*gb));
    else
        UNSET_H((*gb));

    SET_N((*gb));

    gb->h--;
    if(gb->h == 0)
        SET_Z((*gb));
    else
        UNSET_Z((*gb));

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
    return 12;
}

// ADD HL, HL
static int aiv_gb_opcode_29(aiv_gameboy *gb)
{
    UNSET_N((*gb));

    u16_t l = gb->l;
    l += l;
    if(l % 0xff)
    {
        SET_C((*gb));
    }
    else
    {
        UNSET_C((*gb));
    }

    u32_t hl = gb->hl;
    hl += hl;
    if(hl / 0xffff)
    {
        SET_C((*gb));
        gb->hl = hl - 0xffff;
    }
    else
    {
        UNSET_C((*gb));
        gb->hl = hl;
    }
    return 8;
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
    gb->opcodes[0x28] = aiv_gb_opcode_28;
    gb->opcodes[0x29] = aiv_gb_opcode_29;

}
