#include <aiv_unit_test.h>
#include <aiv_gb.h>

TEST(aiv_gb_opcode_c0)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp=0xFF;
    gb.f=0;
    gb.sp-=1;
    aiv_gb_memory_write16(&gb,gb.sp,8080);
    gb.sp-=1;
    gb.cartridge[0]=0xc1;   
    gb.opcodes[0xc0](&gb);
    ASSERT_THAT(gb.pc==8080);
}

TEST(aiv_gb_opcode_c1)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp=0xFF;
    gb.sp-=1;
    aiv_gb_memory_write16(&gb,gb.sp,8080);
    gb.sp-=1;
     gb.cartridge[0]=0xc1;   
    gb.opcodes[0xc1](&gb);
    ASSERT_THAT(gb.bc==8080);
}

TEST(aiv_gb_opcode_c1_stack_position)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);
    gb.sp=0xFF;
    gb.sp-=1;
    aiv_gb_memory_write16(&gb,gb.sp,8080);
    gb.sp-=1;
    gb.cartridge[0]=0xc1;   
    gb.opcodes[0xc1](&gb);
    ASSERT_THAT(gb.sp==0xFF);
}

TEST(aiv_gb_opcode_c2)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);    
    gb.f=00;
    gb.cartridge[gb.pc]=0xc2;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;
    aiv_gb_tick(&gb); 
    ASSERT_THAT(gb.pc==0x8080);
}

TEST(aiv_gb_opcode_c2_z_flag_set)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);    
    gb.f=0xFF;
    gb.cartridge[gb.pc]=0xc2;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;
    int ticks=gb.ticks;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.ticks-ticks==12);
}

TEST(aiv_gb_opcode_c3)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);   
    gb.cartridge[gb.pc]=0xc3;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;
    aiv_gb_tick(&gb); 
    ASSERT_THAT(gb.pc==0x8080);
}

TEST(aiv_gb_opcode_c4)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;   
    gb.f=00;
    gb.cartridge[gb.pc]=0xc4;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;
    aiv_gb_tick(&gb); 
    ASSERT_THAT(gb.pc==0x8080);
}
TEST(aiv_gb_opcode_c4_z_flag_set)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.f=0xFF;  
    gb.cartridge[gb.pc]=0xc4;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;
    int ticks=gb.ticks;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.ticks-ticks==12);
}

TEST(aiv_gb_opcode_c5)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.bc=0x8080;       
    gb.cartridge[gb.pc]=0xc5;
    gb.cartridge[gb.pc+1]=0;
    gb.cartridge[gb.pc+2]=0;
    aiv_gb_tick(&gb);
    u16_t stack_value=aiv_gb_memory_read16(&gb,gb.sp+1);
    ASSERT_THAT(stack_value==0x8080);
}

TEST(aiv_gb_opcode_c6)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.a=0x01;      
    gb.cartridge[gb.pc]=0xc6;
    gb.cartridge[gb.pc+1]=0x01;
    gb.cartridge[gb.pc+2]=0;
    aiv_gb_tick(&gb);    
    ASSERT_THAT(gb.a==0x02);
}

TEST(aiv_gb_opcode_c6_carry_flag)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.a=0xFF;      
    gb.cartridge[gb.pc]=0xc6;
    gb.cartridge[gb.pc+1]=0x02;
    gb.cartridge[gb.pc+2]=0;
    aiv_gb_tick(&gb); 
    gb.f&=0x10;   
    ASSERT_THAT(gb.f==0x10);
}

TEST(aiv_gb_opcode_c7_check_stack)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.pc=0x0100;    
    gb.cartridge[gb.pc]=0xc7;
    gb.cartridge[gb.pc+1]=0;
    gb.cartridge[gb.pc+2]=0;
    aiv_gb_tick(&gb);
    u16_t stack_value=aiv_gb_memory_read16(&gb,gb.sp+1);      
    ASSERT_THAT(stack_value==0x0101);
}

TEST(aiv_gb_opcode_c7)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.pc=0x0100;    
    gb.cartridge[gb.pc]=0xc7;
    gb.cartridge[gb.pc+1]=0;
    gb.cartridge[gb.pc+2]=0;
    aiv_gb_tick(&gb);    
    ASSERT_THAT(gb.pc==0);
}

TEST(aiv_gb_opcode_c8)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.f=0xFF;  
    gb.sp-=1;
    aiv_gb_memory_write16(&gb,gb.sp,0x8080);
    gb.sp-=1;
    gb.cartridge[gb.pc]=0xc8;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;    
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.pc==0x8080);
}
TEST(aiv_gb_opcode_c8_check_unset_flag)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.f=0x00;  
    gb.sp-=1;
    aiv_gb_memory_write16(&gb,gb.sp,0x8080);
    gb.sp-=1;
    gb.cartridge[gb.pc]=0xc8;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80; 
    int ticks=gb.ticks;   
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.ticks-ticks==0x08);
}

TEST(aiv_gb_opcode_c9)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;     
    gb.sp-=1;
    aiv_gb_memory_write16(&gb,gb.sp,0x8080);
    gb.sp-=1;
    gb.cartridge[gb.pc]=0xc9;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;    
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.pc==0x8080);
}

TEST(aiv_gb_opcode_ca)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);    
    gb.f=0xFF;
    gb.cartridge[gb.pc]=0xca;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;
    aiv_gb_tick(&gb); 
    ASSERT_THAT(gb.pc==0x8080);
}

TEST(aiv_gb_opcode_ca_z_flag_set)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb);    
    gb.f=0x00;
    gb.cartridge[gb.pc]=0xca;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;
    int ticks=gb.ticks;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.ticks-ticks==12);
}

TEST(aiv_gb_opcode_cc)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;   
    gb.f=0xFF;
    gb.cartridge[gb.pc]=0xcc;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;
    aiv_gb_tick(&gb); 
    ASSERT_THAT(gb.pc==0x8080);
}
TEST(aiv_gb_opcode_cc_z_flag_set)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.f=0x00;  
    gb.cartridge[gb.pc]=0xcc;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;
    int ticks=gb.ticks;
    aiv_gb_tick(&gb);
    ASSERT_THAT(gb.ticks-ticks==12);
}

TEST(aiv_gb_opcode_cc_z_stack)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.f=0xFF; 
    gb.pc=0x0100; 
    gb.cartridge[gb.pc]=0xcc;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;    
    aiv_gb_tick(&gb);
    u16_t stack_value=aiv_gb_memory_read16(&gb,gb.sp+1);
    ASSERT_THAT(stack_value==0x0103);
}

TEST(aiv_gb_opcode_cd)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;   
    gb.cartridge[gb.pc]=0xcd;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;
    aiv_gb_tick(&gb); 
    ASSERT_THAT(gb.pc==0x8080);
}

TEST(aiv_gb_opcode_cd_z_stack)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.pc=0x0100; 
    gb.cartridge[gb.pc]=0xcd;
    gb.cartridge[gb.pc+1]=0x80;
    gb.cartridge[gb.pc+2]=0x80;    
    aiv_gb_tick(&gb);
    u16_t stack_value=aiv_gb_memory_read16(&gb,gb.sp+1);
    ASSERT_THAT(stack_value==0x0103);
}

TEST(aiv_gb_opcode_ce)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.a=0x01;      
    gb.cartridge[gb.pc]=0xce;
    gb.cartridge[gb.pc+1]=0x01;
    gb.cartridge[gb.pc+2]=0;
    aiv_gb_tick(&gb);    
    ASSERT_THAT(gb.a==0x02);
}
TEST(aiv_gb_opcode_ce_carry_flag)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.a=0xFF;      
    gb.cartridge[gb.pc]=0xce;
    gb.cartridge[gb.pc+1]=0x02;
    gb.cartridge[gb.pc+2]=0;
    aiv_gb_tick(&gb); 
    gb.f&=0x10;   
    ASSERT_THAT(gb.f==0x10);
}

TEST(aiv_gb_opcode_cf_check_stack)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.pc=0x0100;    
    gb.cartridge[gb.pc]=0xcf;
    gb.cartridge[gb.pc+1]=0;
    gb.cartridge[gb.pc+2]=0;
    aiv_gb_tick(&gb);
    u16_t stack_value=aiv_gb_memory_read16(&gb,gb.sp+1);      
    ASSERT_THAT(stack_value==0x0101);
}

TEST(aiv_gb_opcode_cf)
{
    aiv_gameboy gb;
    aiv_gb_init(&gb); 
    gb.sp=0xFF;
    gb.pc=0x0100;    
    gb.cartridge[gb.pc]=0xcf;
    gb.cartridge[gb.pc+1]=0;
    gb.cartridge[gb.pc+2]=0;
    aiv_gb_tick(&gb);    
    ASSERT_THAT(gb.pc==0x08);
}

void aiv_gb_tests_run_opcodes_c0()
{
    RUN_TEST(aiv_gb_opcode_c0);
    RUN_TEST(aiv_gb_opcode_c1);
    RUN_TEST(aiv_gb_opcode_c1_stack_position);
    RUN_TEST(aiv_gb_opcode_c2);
    RUN_TEST(aiv_gb_opcode_c2_z_flag_set);
    RUN_TEST(aiv_gb_opcode_c3);
    RUN_TEST(aiv_gb_opcode_c4);
    RUN_TEST(aiv_gb_opcode_c4_z_flag_set);
    RUN_TEST(aiv_gb_opcode_c5);
    RUN_TEST(aiv_gb_opcode_c6);
    RUN_TEST(aiv_gb_opcode_c6_carry_flag);
    RUN_TEST(aiv_gb_opcode_c7_check_stack);
    RUN_TEST(aiv_gb_opcode_c7);
    RUN_TEST(aiv_gb_opcode_c8);
    RUN_TEST(aiv_gb_opcode_c8_check_unset_flag);
    RUN_TEST(aiv_gb_opcode_c9);
    RUN_TEST(aiv_gb_opcode_ca);
    RUN_TEST(aiv_gb_opcode_ca_z_flag_set);
    RUN_TEST(aiv_gb_opcode_cc);
    RUN_TEST(aiv_gb_opcode_cc_z_flag_set);
    RUN_TEST(aiv_gb_opcode_cc_z_stack);
    RUN_TEST(aiv_gb_opcode_cd);
    RUN_TEST(aiv_gb_opcode_cd_z_stack);
    RUN_TEST(aiv_gb_opcode_ce);
    RUN_TEST(aiv_gb_opcode_ce_carry_flag);
    RUN_TEST(aiv_gb_opcode_cf_check_stack);
    RUN_TEST(aiv_gb_opcode_cf);
}