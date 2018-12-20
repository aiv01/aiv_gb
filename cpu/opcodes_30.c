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

//LD (HL-),A
static int aiv_gb_opcode_32(aiv_gameboy *gb)
{
    u8_t val2 = aiv_gb_memory_read8(gb, gb->a);
    aiv_gb_memory_write8(gb, gb->hl, val2);
    gb->hl--;
    return 8;
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

//LD (HL),d8
static int aiv_gb_opcode_36(aiv_gameboy *gb)
{
    u8_t val2 = aiv_gb_memory_read8(gb, gb->sp + 1);
    aiv_gb_memory_write8(gb, gb->hl, val2);
    gb->pc++;
    return 12;
}

//SCF
static int aiv_gb_opcode_37(aiv_gameboy *gb)
{

    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, 1);
    return 4;
}

//ADD HL,SP
static int aiv_gb_opcode_39(aiv_gameboy *gb)
{
    u16_t pre = gb->hl;
    gb->hl += gb->sp;
    aiv_gb_set_flag(gb, NEG, 0);
    u8_t val = aiv_gb_memory_read8(gb, gb->hl);
    if (val > 15)
    {
        aiv_gb_set_flag(gb, HALF, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, HALF, 0);
    }
    u16_t aft = gb->hl;
    if (aft < pre)
    {
        aiv_gb_set_flag(gb, CARRY, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, CARRY, 0);
    }
    return 8;
}

//LD A,(HL-)
static int aiv_gb_opcode_3a(aiv_gameboy *gb)
{
    u8_t val2 = aiv_gb_memory_read8(gb, gb->hl);
    gb->a = val2;
    gb->hl--;
    return 8;
}

//dec sp
static int aiv_gb_opcode_3b(aiv_gameboy *gb)
{
    gb->sp--;
    return 8;
}

//INC A
static int aiv_gb_opcode_3c(aiv_gameboy *gb)
{
    gb->a++;
    aiv_gb_set_flag(gb, NEG, 0);
    if (gb->a == 0)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
    }
    if (gb->a > 15)
    {
        aiv_gb_set_flag(gb, HALF, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, HALF, 0);
    }
    return 4;
}

//DEC A
static int aiv_gb_opcode_3d(aiv_gameboy *gb)
{
    gb->a--;
    aiv_gb_set_flag(gb, NEG, 1);
    if (gb->a == 0)
    {
        aiv_gb_set_flag(gb, ZERO, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, ZERO, 0);
    }
    if (gb->a > 15)
    {
        aiv_gb_set_flag(gb, HALF, 1);
    }
    else
    {
        aiv_gb_set_flag(gb, HALF, 0);
    }
    return 4;
}

//LD A,d8
static int aiv_gb_opcode_3e(aiv_gameboy *gb)
{
    gb->a = aiv_gb_memory_read8(gb, gb->pc++);
    return 8;
}

//CCF
static int aiv_gb_opcode_3f(aiv_gameboy *gb)
{

    u8_t carry = aiv_gb_get_flag(gb, CARRY);
    if (carry == 16)
    {
        aiv_gb_set_flag(gb, CARRY, 0);
    }
    else
    {
        aiv_gb_set_flag(gb, CARRY, 1);
    }
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, NEG, 0);

    return 4;
}

void aiv_gb_register_opcodes_30(aiv_gameboy *gb)
{
    gb->opcodes[0x30] = aiv_gb_opcode_30;
    gb->opcodes[0x31] = aiv_gb_opcode_31;
    gb->opcodes[0x32] = aiv_gb_opcode_32;
    gb->opcodes[0x33] = aiv_gb_opcode_33;
    gb->opcodes[0x34] = aiv_gb_opcode_34;
    gb->opcodes[0x35] = aiv_gb_opcode_35;
    gb->opcodes[0x36] = aiv_gb_opcode_36;
    gb->opcodes[0x37] = aiv_gb_opcode_37;
    gb->opcodes[0x39] = aiv_gb_opcode_39;
    gb->opcodes[0x3a] = aiv_gb_opcode_3a;
    gb->opcodes[0x3b] = aiv_gb_opcode_3b;
    gb->opcodes[0x3c] = aiv_gb_opcode_3c;
    gb->opcodes[0x3d] = aiv_gb_opcode_3d;
    gb->opcodes[0x3e] = aiv_gb_opcode_3e;

    gb->opcodes[0x3f] = aiv_gb_opcode_3f;
}