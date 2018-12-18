#include <aiv_gb.h>

u8_t aiv_gb_memory_read8(aiv_gameboy *gb, u16_t address)
{
    return gb->memory_read[address >> 12](gb, address);
}

void aiv_gb_memory_write8(aiv_gameboy *gb, u16_t address, u8_t value)
{
    gb->memory_write[address >> 12](gb, address, value);
}

u16_t aiv_gb_memory_read16(aiv_gameboy *gb, u16_t address)
{
    u16_t low = (u16_t)aiv_gb_memory_read8(gb, address);
    u16_t high = (u16_t)aiv_gb_memory_read8(gb, address + 1);
    u16_t value = high << 8 | low;
    return value;
}

static u8_t aiv_gb_memory_read_cartridge(aiv_gameboy *gb, u16_t address)
{
    return gb->cartridge[address];
}

static void aiv_gb_memory_write_cartridge(aiv_gameboy *gb, u16_t address, u8_t value)
{
    gb->cartridge[address] = value;
}

void aiv_gb_memory_init(aiv_gameboy *gb)
{
    gb->memory_read[0x0] = aiv_gb_memory_read_cartridge;
    gb->memory_read[0x1] = aiv_gb_memory_read_cartridge;
    gb->memory_read[0x2] = aiv_gb_memory_read_cartridge;
    gb->memory_read[0x3] = aiv_gb_memory_read_cartridge;
    gb->memory_read[0x4] = aiv_gb_memory_read_cartridge;
    gb->memory_read[0x5] = aiv_gb_memory_read_cartridge;
    gb->memory_read[0x6] = aiv_gb_memory_read_cartridge;
    gb->memory_read[0x7] = aiv_gb_memory_read_cartridge;

    gb->memory_write[0x0] = aiv_gb_memory_write_cartridge;
    gb->memory_write[0x1] = aiv_gb_memory_write_cartridge;
    gb->memory_write[0x2] = aiv_gb_memory_write_cartridge;
    gb->memory_write[0x3] = aiv_gb_memory_write_cartridge;
    gb->memory_write[0x4] = aiv_gb_memory_write_cartridge;
    gb->memory_write[0x5] = aiv_gb_memory_write_cartridge;
    gb->memory_write[0x6] = aiv_gb_memory_write_cartridge;
    gb->memory_write[0x7] = aiv_gb_memory_write_cartridge;
}

void aiv_gb_memory_write16(aiv_gameboy *gb, u16_t address, u16_t value)
{
    u16_t low = value & 0x00ff;
    u16_t high = value >> 8;

    aiv_gb_memory_write8(gb, address, low);
    aiv_gb_memory_write8(gb, address + 1, high);
}