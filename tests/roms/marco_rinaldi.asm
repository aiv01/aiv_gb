section "code", rom0

ld b, 10
ld [hl], b

ld c, 12
ld [hl],c

ld d, 15
ld [hl],d

ld e, 20
ld [hl], e

ld h, 14
ld [hl], h

ld l,25
ld [hl],l

ld a, 14
ld [hl], a

ld a, b

ld a, c

ld a, d

ld a, e

ld a, h

ld a, l

ld [hl],14
ld a,[hl]

ld a, a

halt
