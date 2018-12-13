CFLAGS=-O2 -Wall -Werror
OPCODES=$(patsubst %.c,%.o,$(wildcard cpu/*.c))

all: gameboy

cpu/opcodes_%.o: cpu/opcodes_%.c
	$(CC) -c -o $@ $(CFLAGS) $<

gameboy: $(OPCODES)
	$(CC) -o aiv_gb $^
