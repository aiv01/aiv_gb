#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8_t;
typedef signed char s8_t;
typedef unsigned short u16_t;
typedef signed short s16_t;
typedef unsigned int u32_t;
typedef unsigned long long u64_t;

#define ZERO 0x80
#define NEG 0x40
#define HALF 0x20
#define CARRY 0x10

#define CARTRIDGE_SIZE 32768
#define VRAM_SIZE 8192
#define RAM_SIZE 8192
#define EXTERNAL_RAM_SIZE 8192

typedef struct aiv_gameboy
{
    // AF
    union {
        u16_t af;
        struct
        {
            u8_t f;
            u8_t a;
        };
    };

    // BC
    union {
        u16_t bc;
        struct
        {
            u8_t c;
            u8_t b;
        };
    };

    // DE
    union {
        u16_t de;
        struct
        {
            u8_t e;
            u8_t d;
        };
    };

    // HL
    union {
        u16_t hl;
        struct
        {
            u8_t l;
            u8_t h;
        };
    };

    u16_t pc;
    u16_t sp;

    u64_t ticks;

    // opcodes table, each entry is a pointer to a function
    int (*opcodes[256])(struct aiv_gameboy *);
    int (*prefix_opcodes[256])(struct aiv_gameboy *);

    u8_t (*memory_read[16])(struct aiv_gameboy *, u16_t);
    void (*memory_write[16])(struct aiv_gameboy *, u16_t, u8_t);

    u8_t cartridge[CARTRIDGE_SIZE];
    u8_t vram[VRAM_SIZE];
    u8_t external_ram[EXTERNAL_RAM_SIZE];
    u8_t ram[RAM_SIZE];

} aiv_gameboy;

u8_t aiv_gb_memory_read8(aiv_gameboy *gb, u16_t address);
void aiv_gb_memory_write8(aiv_gameboy *gb, u16_t address, u8_t value);
u16_t aiv_gb_memory_read16(aiv_gameboy *gb, u16_t address);
void aiv_gb_memory_write16(aiv_gameboy *gb, u16_t address, u16_t value);

void aiv_gb_register_opcodes_00(aiv_gameboy *gb);
void aiv_gb_register_opcodes_10(aiv_gameboy *gb);
void aiv_gb_register_opcodes_20(aiv_gameboy *gb);
void aiv_gb_register_opcodes_30(aiv_gameboy *gb);
void aiv_gb_register_opcodes_40(aiv_gameboy *gb);
void aiv_gb_register_opcodes_50(aiv_gameboy *gb);
void aiv_gb_register_opcodes_60(aiv_gameboy *gb);
void aiv_gb_register_opcodes_70(aiv_gameboy *gb);
void aiv_gb_register_opcodes_80(aiv_gameboy *gb);
void aiv_gb_register_opcodes_90(aiv_gameboy *gb);
void aiv_gb_register_opcodes_a0(aiv_gameboy *gb);
void aiv_gb_register_opcodes_b0(aiv_gameboy *gb);
void aiv_gb_register_opcodes_c0(aiv_gameboy *gb);
void aiv_gb_register_opcodes_d0(aiv_gameboy *gb);
void aiv_gb_register_opcodes_e0(aiv_gameboy *gb);
void aiv_gb_register_opcodes_f0(aiv_gameboy *gb);
void aiv_gb_register_prefix_cb_00(aiv_gameboy *gb);
void aiv_gb_register_prefix_cb_10(aiv_gameboy *gb);
void aiv_gb_register_prefix_cb_20(aiv_gameboy *gb);
void aiv_gb_register_prefix_cb_30(aiv_gameboy *gb);
void aiv_gb_register_prefix_cb_40(aiv_gameboy *gb);
void aiv_gb_register_prefix_cb_50(aiv_gameboy *gb);
void aiv_gb_register_prefix_cb_60(aiv_gameboy *gb);
void aiv_gb_register_prefix_cb_70(aiv_gameboy *gb);


int aiv_gb_tick(aiv_gameboy *gb);
int aiv_gb_loop(aiv_gameboy *gb);
void aiv_gb_init(aiv_gameboy *gb);

void aiv_gb_set_flag(aiv_gameboy *gb, u8_t flag, u8_t value);
u8_t aiv_gb_get_flag(aiv_gameboy *gb, u8_t flag);

void aiv_gb_memory_init(aiv_gameboy *gb);

int aiv_gb_load_cartridge(aiv_gameboy *gb, const char *filename);

void aiv_gb_vram_to_rgb(aiv_gameboy *gb, u8_t *data);
