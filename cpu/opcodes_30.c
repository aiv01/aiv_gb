#include <aiv_gb.h>
#include <aiv_unit_test.h>
// JR 0x30
static int aiv_gb_opcode_30(aiv_gameboy *gb)
{
    u8_t carry = aiv_gb_get_flag(gb, CARRY);
    if (carry == 0)
    {
        gb->sp++;
        s8_t value = gb->cartridge[gb->sp];
        printf("%d", value);
        return 12;
    }
    return 8;
}

// LD SP, d16 0x31
static int aiv_gb_opcode_31(aiv_gameboy *gb)
{
    gb->sp = aiv_gb_memory_read16(gb, gb->pc);
    gb->pc += 2;
    return 12;
}
//inc sp
static int aiv_gb_opcode_33(aiv_gameboy *gb)
{
    gb->sp++;
    return 8;
}
//inc (hl)
static int aiv_gb_opcode_34(aiv_gameboy *gb)
{
    u8_t val = aiv_gb_memory_read8(gb, gb->hl);
    val++;
    aiv_gb_memory_write8(gb, gb->hl, val);

    if (val == 0)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
    }
    if (val > 15)
    {
        aiv_gb_set_flag(gb, HALF, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, HALF, 0);
    }
    aiv_gb_set_flag(gb, NEG, 0);
    //UNSET_N((*gb));
    return 12;
}
//dec (hl)
static int aiv_gb_opcode_35(aiv_gameboy *gb)
{
    u8_t val = aiv_gb_memory_read8(gb, gb->hl);
    val--;
    aiv_gb_memory_write8(gb, gb->hl, val);

    if (val == 0)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
    }
    if (val > 15)
    {
        aiv_gb_set_flag(gb, HALF, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, HALF, 0);
    }
    aiv_gb_set_flag(gb, NEG, 1);

    return 12;
}
void aiv_gb_register_opcodes_30(aiv_gameboy *gb)
{
    gb->opcodes[0x30] = aiv_gb_opcode_30;
    gb->opcodes[0x31] = aiv_gb_opcode_31;
    gb->opcodes[0x33] = aiv_gb_opcode_33;
    gb->opcodes[0x34] = aiv_gb_opcode_34;
    gb->opcodes[0x35] = aiv_gb_opcode_35;
}