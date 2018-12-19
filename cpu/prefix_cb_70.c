#include <aiv_gb.h>

//BIT 6,B
static int aiv_gb_prefix_cb_70(aiv_gameboy *gb)
    {
        u8_t value = gb->b;
        if(value & 0x40){
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
//BIT 6,C
static int aiv_gb_prefix_cb_71(aiv_gameboy *gb)
    {
        u8_t value = gb->c;
        if(value & 0x40){
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
//BIT 6,D
static int aiv_gb_prefix_cb_72(aiv_gameboy *gb)
    {
        u8_t value = gb->d;
        if(value & 0x40){
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
//BIT 6,E
static int aiv_gb_prefix_cb_73(aiv_gameboy *gb)
    {
        u8_t value = gb->e;
        if(value & 0x40){
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
//BIT 6,H
static int aiv_gb_prefix_cb_74(aiv_gameboy *gb)
    {
        u8_t value = gb->h;
        if(value & 0x40){
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
//BIT 6,L
static int aiv_gb_prefix_cb_75(aiv_gameboy *gb)
    {
        u8_t value = gb->l;
        if(value & 0x40){
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
//BIT 6,HL
static int aiv_gb_prefix_cb_76(aiv_gameboy *gb)
    {
        u8_t value = gb->hl;
        if(value & 0x40){
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
//BIT 6,A
static int aiv_gb_prefix_cb_77(aiv_gameboy *gb)
    {
        u8_t value = gb->a;
        if(value & 0x40){
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
//BIT 7,B
static int aiv_gb_prefix_cb_78(aiv_gameboy *gb)
    {
        u8_t value = gb->b;
        if(value & 0x80){
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
//BIT 7,C
static int aiv_gb_prefix_cb_79(aiv_gameboy *gb)
    {
        u8_t value = gb->c;
        if(value & 0x80){
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
//BIT 7,D
static int aiv_gb_prefix_cb_7a(aiv_gameboy *gb)
    {
        u8_t value = gb->d;
        if(value & 0x80){
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
//BIT 7,E
static int aiv_gb_prefix_cb_7b(aiv_gameboy *gb)
    {
        u8_t value = gb->e;
        if(value & 0x80){
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
//BIT 7,H
static int aiv_gb_prefix_cb_7c(aiv_gameboy *gb)
    {
        u8_t value = gb->h;
        if(value & 0x80){
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
//BIT 7,L
static int aiv_gb_prefix_cb_7d(aiv_gameboy *gb)
    {
        u8_t value = gb->l;
        if(value & 0x80){
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
//BIT 7,HL
static int aiv_gb_prefix_cb_7e(aiv_gameboy *gb)
    {
        u8_t value = gb->hl;
        if(value & 0x80){
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
//BIT 7,A
static int aiv_gb_prefix_cb_7f(aiv_gameboy *gb)
    {
        u8_t value = gb->a;
        if(value & 0x80){
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
void aiv_gb_register_prefix_cb_70(aiv_gameboy *gb)
    {
        gb->prefix_opcodes[0x70] = aiv_gb_prefix_cb_70;
        gb->prefix_opcodes[0x71] = aiv_gb_prefix_cb_71;
        gb->prefix_opcodes[0x72] = aiv_gb_prefix_cb_72;
        gb->prefix_opcodes[0x73] = aiv_gb_prefix_cb_73;
        gb->prefix_opcodes[0x74] = aiv_gb_prefix_cb_74;
        gb->prefix_opcodes[0x75] = aiv_gb_prefix_cb_75;
        gb->prefix_opcodes[0x76] = aiv_gb_prefix_cb_76;
        gb->prefix_opcodes[0x77] = aiv_gb_prefix_cb_77;
        gb->prefix_opcodes[0x78] = aiv_gb_prefix_cb_78;
        gb->prefix_opcodes[0x79] = aiv_gb_prefix_cb_79;
        gb->prefix_opcodes[0x7a] = aiv_gb_prefix_cb_7a;
        gb->prefix_opcodes[0x7b] = aiv_gb_prefix_cb_7b;
        gb->prefix_opcodes[0x7c] = aiv_gb_prefix_cb_7c;
        gb->prefix_opcodes[0x7d] = aiv_gb_prefix_cb_7d;
        gb->prefix_opcodes[0x7e] = aiv_gb_prefix_cb_7e;
        gb->prefix_opcodes[0x7f] = aiv_gb_prefix_cb_7f;
    }
