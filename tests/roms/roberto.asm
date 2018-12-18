section "code", rom0

nop
nop 
ld bc, var000
ld a, 17
ld [bc], a

ld hl, bc

ld d, [hl]
ld a, 22
add a, d

cp 39
halt
.success


section "ram", wram0
.var000
db 0