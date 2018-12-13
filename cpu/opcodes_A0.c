#include <aiv_gb.h>
#include <stdio.h>

#define AND(val, gb) \
    gb->a &= val; \
    aiv_gb_set_flag(gb, HALF, 1); \
    if(gb-> a == 0){ \
        aiv_gb_set_flag(gb, ZERO, 1); \
    } else{ \
        aiv_gb_set_flag(gb, ZERO, 0); \
    }

#define XOR(val, gb) \
    gb->a = gb->a ^ val; \
    if(gb-> a == 0){ \
        aiv_gb_set_flag(gb, ZERO, 1); \
    } else{ \
        aiv_gb_set_flag(gb, ZERO, 0); \
    }

// AND B
static int aiv_gb_opcode_A0(aiv_gameboy *gb){
    AND(gb->b, gb);
    return 4;
}

// AND C
static int aiv_gb_opcode_A1(aiv_gameboy *gb){
    AND(gb->c, gb);
    return 4;
}
// AND D
static int aiv_gb_opcode_A2(aiv_gameboy *gb){
    AND(gb->d, gb);
    return 4;
}

// AND E
static int aiv_gb_opcode_A3(aiv_gameboy *gb){
    AND(gb->e, gb);
    return 4;
}

// AND H
static int aiv_gb_opcode_A4(aiv_gameboy *gb){
    AND(gb->h, gb);
    return 4;
}

// AND L
static int aiv_gb_opcode_A5(aiv_gameboy *gb){
    AND(gb->l, gb);
    return 4;
}
// AND (HL)
static int aiv_gb_opcode_A6(aiv_gameboy *gb){
    AND(gb->hl, gb);
    return 8;
}
// AND A
static int aiv_gb_opcode_A7(aiv_gameboy *gb){
    AND(gb->a, gb);
    return 4;
}

//XOR B
static int aiv_gb_opcode_A8(aiv_gameboy *gb){
    XOR(gb->b, gb);
    return 4;
}

//XOR C
static int aiv_gb_opcode_A9(aiv_gameboy *gb){
    XOR(gb->c, gb);
    return 4;
}

//XOR D
static int aiv_gb_opcode_AA(aiv_gameboy *gb){
    XOR(gb->d, gb);
    return 4;
}

//XOR E
static int aiv_gb_opcode_AB(aiv_gameboy *gb){
    XOR(gb->e, gb);
    return 4;
}

//XOR H
static int aiv_gb_opcode_AC(aiv_gameboy *gb){
    XOR(gb->h, gb);
    return 4;
}

//XOR L
static int aiv_gb_opcode_AD(aiv_gameboy *gb){
    XOR(gb->l, gb);
    return 4;
}

//XOR (HL)
static int aiv_gb_opcode_AE(aiv_gameboy *gb){
    XOR(gb->hl, gb);
    return 8;
}

//XOR A
static int aiv_gb_opcode_AF(aiv_gameboy *gb){
    XOR(gb->a, gb);
    return 4;
}


void aiv_gb_register_opcodes_a0(aiv_gameboy *gb)
{
    gb->opcodes[0xA0] = aiv_gb_opcode_A0;
    gb->opcodes[0xA1] = aiv_gb_opcode_A1;
    gb->opcodes[0xA2] = aiv_gb_opcode_A2;
    gb->opcodes[0xA3] = aiv_gb_opcode_A3;
    gb->opcodes[0xA4] = aiv_gb_opcode_A4;
    gb->opcodes[0xA5] = aiv_gb_opcode_A5;
    gb->opcodes[0xA6] = aiv_gb_opcode_A6;
    gb->opcodes[0xA7] = aiv_gb_opcode_A7;
    gb->opcodes[0xA8] = aiv_gb_opcode_A8;
    gb->opcodes[0xA9] = aiv_gb_opcode_A9;
    gb->opcodes[0xAA] = aiv_gb_opcode_AA;
    gb->opcodes[0xAB] = aiv_gb_opcode_AB;
    gb->opcodes[0xAC] = aiv_gb_opcode_AC;
    gb->opcodes[0xAD] = aiv_gb_opcode_AD;
    gb->opcodes[0xAE] = aiv_gb_opcode_AE;
    gb->opcodes[0xAF] = aiv_gb_opcode_AF;
}