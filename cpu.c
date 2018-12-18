#include <aiv_gb.h>

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

    aiv_gb_memory_init(gb);

    aiv_gb_register_opcodes_00(gb);
    //aiv_gb_register_opcodes_10(gb);
    aiv_gb_register_opcodes_20(gb);
    aiv_gb_register_opcodes_30(gb);

    //aiv_gb_register_opcodes_40(gb);
    //aiv_gb_register_opcodes_50(gb);
    aiv_gb_register_opcodes_60(gb);
    aiv_gb_register_opcodes_70(gb);

    aiv_gb_register_opcodes_80(gb);
    aiv_gb_register_opcodes_90(gb);
    aiv_gb_register_opcodes_a0(gb);
    aiv_gb_register_opcodes_b0(gb);


    aiv_gb_register_opcodes_c0(gb);

    aiv_gb_register_opcodes_d0(gb);

    //aiv_gb_register_opcodes_e0(gb);
    //aiv_gb_register_opcodes_f0(gb);
}
