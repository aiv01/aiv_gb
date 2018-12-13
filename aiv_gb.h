typedef unsigned char u8_t;
typedef signed char s8_t;
typedef unsigned short u16_t;
typedef signed short s16_t;
typedef unsigned long long u64_t;

#define SET_Z(gb) gb->f |= 0x80
#define UNSET_Z(gb) gb->f &= ~0x80

#define SET_N(gb) gb->f |= 0x40
#define UNSET_N(gb) gb->f &= ~0x40

#define SET_H(gb) gb->f |= 0x20
#define UNSET_H(gb) gb->f &= ~0x20

#define SET_C(gb) gb->f |= 0x10
#define UNSET_C(gb) gb->f &= ~0x10

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

} aiv_gameboy;