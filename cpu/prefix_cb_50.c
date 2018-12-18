#include <aiv_gb.h>

//BIT 2,B
static int aiv_gb_prefix_cb_50(aiv_gameboy *gb)
    {
        u8_t value = gb->b;
        if(value & 0x04){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 2,C
static int aiv_gb_prefix_cb_51(aiv_gameboy *gb)
    {
        u8_t value = gb->c;
        if(value & 0x04){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 2,D
static int aiv_gb_prefix_cb_52(aiv_gameboy *gb)
    {
        u8_t value = gb->d;
        if(value & 0x04){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 2,E
static int aiv_gb_prefix_cb_53(aiv_gameboy *gb)
    {
        u8_t value = gb->e;
        if(value & 0x04){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 2,H
static int aiv_gb_prefix_cb_54(aiv_gameboy *gb)
    {
        u8_t value = gb->h;
        if(value & 0x04){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 2,L
static int aiv_gb_prefix_cb_55(aiv_gameboy *gb)
    {
        u8_t value = gb->l;
        if(value & 0x04){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 2,HL
static int aiv_gb_prefix_cb_56(aiv_gameboy *gb)
    {
        u8_t value = gb->hl;
        if(value & 0x04){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 2,A
static int aiv_gb_prefix_cb_57(aiv_gameboy *gb)
    {
        u8_t value = gb->a;
        if(value & 0x04){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 3,B
static int aiv_gb_prefix_cb_58(aiv_gameboy *gb)
    {
        u8_t value = gb->b;
        if(value&0x08){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 3,C
static int aiv_gb_prefix_cb_59(aiv_gameboy *gb)
    {
        u8_t value = gb->c;
        if(value&0x08){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 3,D
static int aiv_gb_prefix_cb_5a(aiv_gameboy *gb)
    {
        u8_t value = gb->d;
        if(value & 0x08){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 3,E
static int aiv_gb_prefix_cb_5b(aiv_gameboy *gb)
    {
        u8_t value = gb->e;
        if(value & 0x08){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 3,H
static int aiv_gb_prefix_cb_5c(aiv_gameboy *gb)
    {
        u8_t value = gb->h;
        if(value & 0x08){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 3,L
static int aiv_gb_prefix_cb_5d(aiv_gameboy *gb)
    {
        u8_t value = gb->l;
        if(value & 0x08){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 3,HL
static int aiv_gb_prefix_cb_5e(aiv_gameboy *gb)
    {
        u8_t value = gb->hl;
        if(value & 0x08){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
//BIT 3,A
static int aiv_gb_prefix_cb_5f(aiv_gameboy *gb)
    {
        u8_t value = gb->a;
        if(value & 0x08){
            aiv_gb_set_flag(gb,ZERO,0);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        else{
            aiv_gb_set_flag(gb,ZERO,1);
            aiv_gb_set_flag(gb,NEG,0);
            aiv_gb_set_flag(gb,HALF,1);
            return 8;
        }
        return 8;
    }
void aiv_gb_register_prefix_cb_50(aiv_gameboy *gb)
    {
        gb->prefix_opcodes[0x50] = aiv_gb_prefix_cb_50;
        gb->prefix_opcodes[0x51] = aiv_gb_prefix_cb_51;
        gb->prefix_opcodes[0x52] = aiv_gb_prefix_cb_52;
        gb->prefix_opcodes[0x53] = aiv_gb_prefix_cb_53;
        gb->prefix_opcodes[0x54] = aiv_gb_prefix_cb_54;
        gb->prefix_opcodes[0x55] = aiv_gb_prefix_cb_55;
        gb->prefix_opcodes[0x56] = aiv_gb_prefix_cb_56;
        gb->prefix_opcodes[0x57] = aiv_gb_prefix_cb_57;
        gb->prefix_opcodes[0x58] = aiv_gb_prefix_cb_58;
        gb->prefix_opcodes[0x59] = aiv_gb_prefix_cb_59;
        gb->prefix_opcodes[0x5a] = aiv_gb_prefix_cb_5a;
        gb->prefix_opcodes[0x5b] = aiv_gb_prefix_cb_5b;
        gb->prefix_opcodes[0x5c] = aiv_gb_prefix_cb_5c;
        gb->prefix_opcodes[0x5d] = aiv_gb_prefix_cb_5d;
        gb->prefix_opcodes[0x5e] = aiv_gb_prefix_cb_5e;
        gb->prefix_opcodes[0x5f] = aiv_gb_prefix_cb_5f;
    }
