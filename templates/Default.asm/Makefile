flags=-f elf
ldflags=

.PHONY: clean

all: SPOB

PROJECTNAME: SPOB.o
	ld $^ -o $@ $(ldflags)

PROJECTNAME.o: SPOB.asm SPOB.asmh
	nasm $(flags) $<

clean:
	rm -f *.o SPOB
