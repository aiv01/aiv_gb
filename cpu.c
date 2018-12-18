#include "aiv_gb.h"

int aiv_gb_tick(aiv_gameboy *gb)
{
    u8_t opcode = aiv_gb_memory_read8(gb, gb->pc++);
    int ticks = gb->opcodes[opcode](gb);
    gb->ticks += ticks;

    return 0;
}

int aiv_gb_loop(aiv_gameboy *gb)
{
    for (;;)
    {
        aiv_gb_tick(gb);
    }

    return 0;
}

void aiv_gb_init(aiv_gameboy *gb)
{
    memset(gb, 0, sizeof(aiv_gameboy));
    aiv_gb_register_opcodes_50(gb);

}
