CC=clang
CFLAGS=-O2 -Wall -Werror -I.

OPCODES=$(patsubst %.c,%.o,$(wildcard cpu/*.c))
TESTS=$(patsubst %.c,%.o,$(wildcard tests/*.c))
BINARY=aiv_gb
BINARY_TESTS=run_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

all: gameboy

cpu/opcodes_%.o: cpu/opcodes_%.c aiv_gb.h
	$(CC) -c -o $@ $(CFLAGS) $<

cpu.o: cpu.c aiv_gb.h
	$(CC) -c -o $@ $(CFLAGS) $<

memory.o: memory.c aiv_gb.h
	$(CC) -c -o $@ $(CFLAGS) $<

tests/test_%.o: tests/test_%.c aiv_gb.h aiv_unit_test.h
	$(CC) -c -o $@ $(CFLAGS) $<

test: cpu.o memory.o tests.o $(OPCODES) $(TESTS)
	$(CC) -o $(BINARY_TESTS) $(LDFLAGS) $^
	./run_tests

gameboy: $(OPCODES)
	$(CC) -o $(BINARY) $^

clean:
	rm *.o cpu/*.o tests/*.o
	rm run_tests
