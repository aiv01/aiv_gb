section "CODE", rom0

LD b, $88
LD c, $00
LD h, $FF
Ld d, $FF
ld e, $FF
LD l, $AA

LD a, $88
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
ld [hl], $FF
xor [hl]
xor a

halt

