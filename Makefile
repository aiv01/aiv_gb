CFLAGS=-O2 -Wall -Werror -I.
OPCODES=$(patsubst %.c,%.o,$(wildcard cpu/*.c))
TESTS=$(patsubst %.c,%.o,$(wildcard tests/*.c))

all: gameboy

cpu/opcodes_%.o: cpu/opcodes_%.c aiv_gb.h
	$(CC) -c -o $@ $(CFLAGS) $<

cpu.o: cpu.c aiv_gb.h
	$(CC) -c -o $@ $(CFLAGS) $<

memory.o: memory.c aiv_gb.h
	$(CC) -c -o $@ $(CFLAGS) $<

tests/test_%.o: tests/test_%.c aiv_gb.h
	$(CC) -c -o $@ $(CFLAGS) $<

test: cpu.o memory.o tests.o $(OPCODES) $(TESTS)
	$(CC) -o run_tests $(LDFLAGS) $^
	./run_tests

gameboy: $(OPCODES)
	$(CC) -o aiv_gb $^

clean:
	rm *.o cpu/*.o tests/*.o
