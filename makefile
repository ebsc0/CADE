CC= clang
CFLAGS= -Wall -g -std=c99

LIBS= -lc

all: main matrix.o ops.o

main: main.o matrix.o ops.o common.h
	$(CC) -o main main.o matrix.o ops.o

matrix.o: matrix.c
	$(CC) -c matrix.c $(CFLAGS) $(LIBS)

ops.o: ops.c
	$(CC) -c ops.c $(CFLAGS) $(LIBS)

clean:
	rm -f *.o main