section "code", rom0



cp 39
jr z, success
halt
success:
ld e, d
halt

section "ram", wram0
var000:
ds 1