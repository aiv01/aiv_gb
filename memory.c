#include "aiv_gb.h"

u8_t aiv_gb_memory_read8(aiv_gameboy *gb, u16_t address)
{
    return gb->cartridge[address];
}

void aiv_gb_memory_write8(aiv_gameboy *gb, u16_t address, u8_t value)
{
    gb->cartridge[address] = value;
}

u16_t aiv_gb_memory_read16(aiv_gameboy *gb, u16_t address)
{
    u16_t low = (u16_t)aiv_gb_memory_read8(gb, address);
    u16_t high = (u16_t)aiv_gb_memory_read8(gb, address + 1);
    u16_t value = high << 8 | low;
    return value;
}

void aiv_gb_memory_write16(aiv_gameboy *gb, u16_t address, u16_t value)
{
    u16_t low = value & 0x00ff;
    u16_t high = value >> 8;

    aiv_gb_memory_write8(gb, address, low);
    aiv_gb_memory_write8(gb, address + 1, high);
}