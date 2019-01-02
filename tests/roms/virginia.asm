section "code", rom0

LD b, $00
LD c, $00
LD d, $88
LD e, $88
LD h, $FF
LD l, $FF

LD a, $AA
or b 
or c
or d
or e
or h 
or l 
or [hl]
or a

cp b 
cp c 
cp d
cp e
cp h
cp l 
cp [hl]
cp a

halt