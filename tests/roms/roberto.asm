section "code", rom0

nop
nop 
ld bc, var000
ld a, 17
ld [bc], a

ld h, b
ld l, c

ld d, [hl]
ld a, 22
add a, d

cp 39
jr z, success
halt
success:
ld e, d
halt


section "ram", wram0
var000:
ds 1