#include <aiv_gb.h>

//STOP (?)
static int aiv_gb_opcode_10(aiv_gameboy *gb)
{
    printf("STOP!");
    return -1;
}

// LD DE, d16 (d16  means immediate 16 bit data)
static int aiv_gb_opcode_11(aiv_gameboy *gb)
{
    gb->de = aiv_gb_memory_read16(gb, gb->pc);
    gb->pc += 2;
    return 12;
}

// LD (DE), A
static int aiv_gb_opcode_12(aiv_gameboy *gb)
{
    aiv_gb_memory_write8(gb, gb->de, gb->a);
    return 8;
}

//INC DE
static int aiv_gb_opcode_13(aiv_gameboy *gb)
{
    gb->de++;
    return 8;
}

//INC D
static int aiv_gb_opcode_14(aiv_gameboy *gb)
{
    gb->d++;
    aiv_gb_set_flag(gb, ZERO, gb->d == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    //  aiv_gb_set_flag(gb, HALF, (((gb->d & 0x0f) - 0xf0) & 0xf0));
    return 4;
}

//DEC D
static int aiv_gb_opcode_15(aiv_gameboy *gb)
{
    gb->d--;
    aiv_gb_set_flag(gb, ZERO, gb->d == 0);
    aiv_gb_set_flag(gb, NEG, 0);
    // aiv_gb_set_flag(gb, HALF, (((gb->d & 0x0f) - 0xf0) & 0xf0));
    return 4;
}

//LD D, d8 (d8  means immediate 8 bit data)
static int aiv_gb_opcode_16(aiv_gameboy *gb)
{
    gb->d = aiv_gb_memory_read8(gb, gb->pc);
    gb->pc += 1;
    return 8;
}

//RLA
static int aiv_gb_opcode_17(aiv_gameboy *gb)
{
    gb->a = gb->a << 1;
    aiv_gb_set_flag(gb, ZERO, 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    // aiv_gb_set_flag(gb, CARRY, gb->a );
    return 4;
}
//JR r8    (r8  means 8 bit signed data, which are added to program counter)
static int aiv_gb_opcode_18(aiv_gameboy *gb)
{
    gb->pc += aiv_gb_memory_read8(gb, gb->pc);
    gb->pc += 1;
    return 12;
}

//ADD HL,DE
static int aiv_gb_opcode_19(aiv_gameboy *gb)
{
    gb->hl += gb->de;
    //flags : - 0 H C  half carry missing
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    aiv_gb_set_flag(gb, CARRY, (gb->hl + gb->de >= 65535));
    return 8;
}

//LD A, (DE)
static int aiv_gb_opcode_1a(aiv_gameboy *gb)
{
   gb->a= aiv_gb_memory_read8(gb, gb->de);
    return 8;
}
//DEC DE
static int aiv_gb_opcode_1b(aiv_gameboy *gb)
{
    gb->de--;
    return 8;
}
//INC E
static int aiv_gb_opcode_1c(aiv_gameboy *gb)
{
    gb->e++;
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, ZERO, (gb->d == 0));
    aiv_gb_set_flag(gb, HALF, ((gb->d & 0x0f) + 1 > 0x08));
    return 4;
}
//DEC E
static int aiv_gb_opcode_1d(aiv_gameboy *gb)
{
    gb->e--;
    aiv_gb_set_flag(gb, NEG, 1);
    aiv_gb_set_flag(gb, ZERO, gb->e == 0);
    aiv_gb_set_flag(gb, HALF, (gb->e & 0x0f) + 1 > 0x08);
    return 4;
}
//LD E,d8 (d8  means immediate 8 bit data)
static int aiv_gb_opcode_1e(aiv_gameboy *gb)
{
   gb->e= aiv_gb_memory_read8(gb, gb->pc);
    gb->pc += 1;
    return 8;
}
//RRA
static int aiv_gb_opcode_1f(aiv_gameboy *gb)
{
    gb->a = gb->a >> 1;
    aiv_gb_set_flag(gb, CARRY, (gb->a >= 255));
    aiv_gb_set_flag(gb, ZERO, 0);
    aiv_gb_set_flag(gb, NEG, 0);
    aiv_gb_set_flag(gb, HALF, 0);
    return 4;
}

void aiv_gb_register_opcodes_10(aiv_gameboy *gb)
{
    gb->opcodes[0x10] = aiv_gb_opcode_10;
    gb->opcodes[0x11] = aiv_gb_opcode_11;
    gb->opcodes[0x12] = aiv_gb_opcode_12;
    gb->opcodes[0x13] = aiv_gb_opcode_13;
    gb->opcodes[0x14] = aiv_gb_opcode_14;
    gb->opcodes[0x15] = aiv_gb_opcode_15;
    gb->opcodes[0x16] = aiv_gb_opcode_16;
    gb->opcodes[0x17] = aiv_gb_opcode_17;
    gb->opcodes[0x18] = aiv_gb_opcode_18;
    gb->opcodes[0x19] = aiv_gb_opcode_19;
    gb->opcodes[0x1a] = aiv_gb_opcode_1a;
    gb->opcodes[0x1b] = aiv_gb_opcode_1b;
    gb->opcodes[0x1c] = aiv_gb_opcode_1c;
    gb->opcodes[0x1d] = aiv_gb_opcode_1d;
    gb->opcodes[0x1e] = aiv_gb_opcode_1e;
    gb->opcodes[0x1f] = aiv_gb_opcode_1f;
}