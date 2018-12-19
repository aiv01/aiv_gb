section "code", romB


LD b, 0x00
LD c, 0x00
LD d, 0x88
LD e, 0x88
LD h, 0xFF
LD l, 0xFF

LD a, 0xAA
or b 
or c
or d
or e
or h 
or l 
or [hl]
or a

ld f, 0x00
cp b 
cp c 
cp d
cp e
cp h
cp l 
cp [hl]
cp a

halt