flags=-O2 -Wall -std=c2x
ldflags=-lbu

.PHONY: all clean

all: clean SPOB

PROJECTNAME: SPOB.o
	cc $(flags) $^ -o $@ $(ldflags)

PROJECTNAME.o: SPOB.c SPOB.h
	cc $(flags) -c $<

clean:
	rm -f *.o SPOB
