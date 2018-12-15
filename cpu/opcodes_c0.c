#include <aiv_gb.h>

//RET NZ
int aiv_gb_opcode_c0(aiv_gameboy *gb)
{
    u16_t address = aiv_gb_memory_read16(gb,gb->sp+1);
    gb->sp+=2;
    u8_t i=gb->f;
    if((i&=0x80)==0x00){
        gb->pc=address;
        return 20;
    }
    return 8;
}

//POP BC
int aiv_gb_opcode_c1(aiv_gameboy *gb)
{ 
    gb->bc = aiv_gb_memory_read16(gb,gb->sp+1);
    gb->sp+=2;   
    return 12;
}

//JP NZ,a16
int aiv_gb_opcode_c2(aiv_gameboy *gb)
{  
    u8_t i=gb->f;
    if((i&=0x80)==0x00){
        u16_t address = aiv_gb_memory_read16(gb,gb->pc);       
        gb->pc=address;        
    return 16;
    }
    return 12;
}

//JP a16
int aiv_gb_opcode_c3(aiv_gameboy *gb)
{        
    u16_t jump_address = aiv_gb_memory_read16(gb,gb->pc);    
    gb->pc=jump_address;
    return 16;    
}

//CALL NZ,a16
int aiv_gb_opcode_c4(aiv_gameboy *gb)
{        
    u8_t i=gb->f;
    if((i&=0x80)==0x00){
        u16_t func_address = aiv_gb_memory_read16(gb,gb->pc);
        gb->pc+=2;  
        gb->sp-=1;
        aiv_gb_memory_write16(gb,gb->sp,gb->pc);
        gb->sp-=1;
        gb->pc=func_address;
    return 24;   
    } 
    gb->pc+=3;
    return 12;
}

//PUSH BC
int aiv_gb_opcode_c5(aiv_gameboy *gb)
{
    u16_t value=gb->bc;
    gb->sp-=1;
    aiv_gb_memory_write16(gb,gb->sp,value);
    gb->sp-=1;
    return 12;
}

//ADD a,d8
int aiv_gb_opcode_c6(aiv_gameboy *gb)
{  
    gb->f&=0x00;
    int a=gb->a;
    int b= aiv_gb_memory_read8(gb,gb->pc);
    if(a+b>0xFF){
        gb->f|=0x10;
        gb->a=0xFF;
        gb->pc+=1;
        return 8;
    }
    gb->a=a+b;
    gb->pc+=1;
    return 8;
}

//RST 00H
int aiv_gb_opcode_c7(aiv_gameboy *gb)
{
    u16_t ret_address=gb->pc;
    gb->sp-=1;
    aiv_gb_memory_write16(gb,gb->sp,ret_address); 
    gb->sp-=1;   
    gb->pc=0x00;
    return 16;
}

//RET Z
int aiv_gb_opcode_c8(aiv_gameboy *gb)
{
    u16_t address = aiv_gb_memory_read16(gb,gb->sp+1);
    gb->sp+=2;
    u8_t i=gb->f;
    if((i&=0x80)==0x80){
        gb->pc=address;
        return 20;
    }
    return 8;
}

//RET
int aiv_gb_opcode_c9(aiv_gameboy *gb)
{
    u16_t address = aiv_gb_memory_read16(gb,gb->sp+1);
    gb->sp+=2;    
    gb->pc=address;
    return 16;    
}

//JP Z,a16
int aiv_gb_opcode_ca(aiv_gameboy *gb)
{     
    u8_t i=gb->f;    
    if((i&=0x80)==0x80){
    u16_t jump_address = aiv_gb_memory_read16(gb,gb->pc);      
    gb->pc=jump_address;
    return 16;
    }
    return 12;
}

//PREFIX cb
int aiv_gb_opcode_cb(aiv_gameboy *gb)
{    
    u8_t opcode = aiv_gb_memory_read8(gb, gb->pc++);
    int ticks = gb->prefix_opcodes[opcode](gb);    
    return ticks;
}

//CALL Z,a16
int aiv_gb_opcode_cc(aiv_gameboy *gb)
{        
    u8_t i=gb->f;
    if((i&=0x80)==0x80){
    u16_t func_address = aiv_gb_memory_read16(gb,gb->pc);
    gb->pc+=2; 
    gb->sp-=1;
    aiv_gb_memory_write16(gb,gb->sp,gb->pc);
    gb->sp-=1;
    gb->pc=func_address;
    return 24;   
    } 
    return 12;
}

//CALL a16
int aiv_gb_opcode_cd(aiv_gameboy *gb)
{        
    u16_t func_address = aiv_gb_memory_read16(gb,gb->pc);
    gb->pc+=2;
    gb->sp-=1;
    aiv_gb_memory_write16(gb,gb->sp,gb->pc);
    gb->sp-=1;
    gb->pc=func_address;
    return 24;      
}

//ADC A,d8
int aiv_gb_opcode_ce(aiv_gameboy *gb)
{  
   gb->f&=0x00;  
   int a=gb->a;
    int b= aiv_gb_memory_read8(gb,gb->pc);
    if(a+b>0xFF){
        gb->f|=0x10;
        gb->a=0xFF;
        gb->pc+=1;
        return 8;
    }
    gb->a=a+b;
    gb->pc+=1;
    return 8;  
}

//RST 08H
int aiv_gb_opcode_cf(aiv_gameboy *gb)
{
    u16_t ret_address=gb->pc;
    gb->sp-=1;
    aiv_gb_memory_write16(gb,gb->sp,ret_address); 
    gb->sp-=1;   
    gb->pc=0x08;
    return 16;
}

void aiv_gb_register_opcodes_c0(aiv_gameboy *gb)
{
    gb->opcodes[0xc0] = aiv_gb_opcode_c0;
    gb->opcodes[0xc1] = aiv_gb_opcode_c1;
    gb->opcodes[0xc2] = aiv_gb_opcode_c2;
    gb->opcodes[0xc3] = aiv_gb_opcode_c3;
    gb->opcodes[0xc4] = aiv_gb_opcode_c4;
    gb->opcodes[0xc5] = aiv_gb_opcode_c5;
    gb->opcodes[0xc6] = aiv_gb_opcode_c6;
    gb->opcodes[0xc7] = aiv_gb_opcode_c7;
    gb->opcodes[0xc8] = aiv_gb_opcode_c8;
    gb->opcodes[0xc9] = aiv_gb_opcode_c9;
    gb->opcodes[0xca] = aiv_gb_opcode_ca;
    gb->opcodes[0xcb] = aiv_gb_opcode_cb;
    gb->opcodes[0xcc] = aiv_gb_opcode_cc;
    gb->opcodes[0xcd] = aiv_gb_opcode_cd;
    gb->opcodes[0xce] = aiv_gb_opcode_ce;
    gb->opcodes[0xcf] = aiv_gb_opcode_cf;
    

}