CC=gcc
CFFLAGS=
RM=rm -rf
OUT=VECTOR

all: build

build: main.o vector.o
	$(CC) $(CFFLAGS) -o $(OUT) main.c vector.c
	$(RM) *.o

debug: CFFLAGS+=-DDEBUG_ON
debug: build

vector.o: vector.c vector.h
	$(CC) $(CFFLAGS) -c vector.c

clean:
	$(RM) *.o $(OUT)