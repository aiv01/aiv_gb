segment "CODE", romA

LD b, 0x88
LD c, 0x00
LD h, 0xFF
Ld d, 0xFF
ld e, 0xFF
LD l, 0xAA

LD a, 0x88
and b
and c
and d
and e
and h
and l
and [hl]
and a

ld a,b
xor b
xor c
xor d
xor e
xor h
xor l
ld [hl],0xFF
xor [hl]
xor a

halt

