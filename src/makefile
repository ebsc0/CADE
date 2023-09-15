CC=gcc
CFLAGS=-Wall -g -std=gnu99
DEPS = matrix.h
OBJ = matrix.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

src: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)