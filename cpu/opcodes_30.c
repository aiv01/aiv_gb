#include <aiv_gb.h>
#include <aiv_unit_test.h>
// JR 0x30
static int aiv_gb_opcode_30(aiv_gameboy *gb)
{

    return 0;
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
    u8_t val = aiv_gb_memory_read8(gb,gb->hl);
    
    val++;
    aiv_gb_memory_write8(gb,gb->hl, val);
    
    if(val == 0){
        SET_Z((*gb));
    }
    else{
        UNSET_Z((*gb));
    }
    if(val >15 ){
        SET_H((*gb));
    }
    else{
        UNSET_H((*gb));
    }
    UNSET_N((*gb));
    return 12;
}
//dec (hl)
static int aiv_gb_opcode_35(aiv_gameboy *gb)
{
    u8_t val = aiv_gb_memory_read8(gb,gb->hl);
    val--;
    aiv_gb_memory_write8(gb,gb->hl, val);

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