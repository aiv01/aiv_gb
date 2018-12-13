#include <aiv_gb.h>

//RET NC
static int aiv_gb_opcode_d0(aiv_gameboy *gb)
{
    //check if C == 1
    if ((gb->f & 0x10) == 0x10)
    {
        return 8;
    }

    gb->pc = aiv_gb_memory_read16(gb, gb->sp + 1);
    gb->sp += 2;

    return 20;
}

//POP DE
static int aiv_gb_opcode_d1(aiv_gameboy *gb)
{
    gb->de = aiv_gb_memory_read16(gb, gb->sp + 1);
    gb->sp += 2;

    return 12;
}

//JP NC,a16
static int aiv_gb_opcode_d2(aiv_gameboy *gb)
{
    //check if C == 1
    if ((gb->f & 0x10) == 0x10)
    {
        gb->pc += 2;
        return 12;
    }

    gb->pc = aiv_gb_memory_read16(gb, gb->pc);
    return 16;
}

//PUSH DE
static int aiv_gb_opcode_d5(aiv_gameboy *gb)
{
    aiv_gb_memory_write16(gb, gb->sp - 1, gb->de);
    gb->sp -= 2;

    return 16;
}

void aiv_gb_register_opcodes_d0(aiv_gameboy *gb)
{
    gb->opcodes[0xd0] = aiv_gb_opcode_d0;
    gb->opcodes[0xd1] = aiv_gb_opcode_d1;
    gb->opcodes[0xd2] = aiv_gb_opcode_d2;
    gb->opcodes[0xd5] = aiv_gb_opcode_d5;
}
