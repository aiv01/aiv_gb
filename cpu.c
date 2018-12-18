#include "aiv_gb.h"

static int aiv_gb_unregistered_opcode(aiv_gameboy *gb)
{
    u8_t opcode = gb->memory_read[(gb->pc - 1) >> 12](gb, gb->pc - 1);
    fprintf(stderr, "unregistered opcode: %02x\n", opcode);
    exit(1);
    return 0;
}

int aiv_gb_tick(aiv_gameboy *gb)
{
    u8_t opcode = aiv_gb_memory_read8(gb, gb->pc++);
    int ticks = gb->opcodes[opcode](gb);
    gb->ticks += ticks;

    return ticks;
}

int aiv_gb_loop(aiv_gameboy *gb)
{
    for (;;)
    {
        aiv_gb_tick(gb);
    }

    return 0;
}

void aiv_gb_set_flag(aiv_gameboy *gb, u8_t flag, u8_t value)
{
    if (value)
    {
        gb->f |= flag;
        return;
    }
    gb->f &= ~flag;
}

u8_t aiv_gb_get_flag(aiv_gameboy *gb, u8_t flag)
{
    return gb->f & flag;
}

void aiv_gb_init(aiv_gameboy *gb)
{
    memset(gb, 0, sizeof(aiv_gameboy));
    aiv_gb_register_opcodes_50(gb);


    aiv_gb_memory_init(gb);

    int i = 0;
    for (i = 0; i < 256; i++)
    {
        gb->opcodes[i] = aiv_gb_unregistered_opcode;
    }
    aiv_gb_register_opcodes_50(gb);

}
