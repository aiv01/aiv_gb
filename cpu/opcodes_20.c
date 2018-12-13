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

// LD HL, d16
static int aiv_gb_opcode_21(aiv_gameboy *gb)
{
    gb->hl = aiv_gb_memory_read16(gb, gb->pc);
    gb->pc += 2;
    return 12;
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

void aiv_gb_register_opcodes_20(aiv_gameboy *gb)
{
    gb->opcodes[0x20] = aiv_gb_opcode_20;
    gb->opcodes[0x21] = aiv_gb_opcode_21;
    gb->opcodes[0x22] = aiv_gb_opcode_22;


}
