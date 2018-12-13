#include <aiv_gb.h>

//RET NC
static int aiv_gb_opcode_d0(aiv_gameboy *gb)
{
    if (aiv_gb_get_flag(gb, CARRY))
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

void aiv_gb_register_opcodes_d0(aiv_gameboy *gb)
{
    gb->opcodes[0xd0] = aiv_gb_opcode_d0;
    gb->opcodes[0xd1] = aiv_gb_opcode_d1;
}
