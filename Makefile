CC=gcc 
CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99
OBJECTS = parfait.o bv.o sieve.o

.PHONY: all
all: parfait

parfait: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(CFLAGS) -lm -o parfait

parfait.o: parfait.c
	$(CC) $(CFLAGS) -c parfait.c

bv.o: bv.c bv.h
	$(CC) $(CFLAGS) -c bv.c

sieve.o: sieve.c sieve.h
	$(CC) $(CFLAGS) -c sieve.c

.PHONY: clean
clean:
	rm $(OBJECTS) parfait
