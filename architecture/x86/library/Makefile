include ../../../tools.make

.PHONY : clean

global = ../../../include/
head   = ../include/

all: physical_memory.o protected_mode.o

physical_memory.o: physical_memory.i
	$(AS) --warn --32 -o $@ $<

physical_memory.i: physical_memory.S
	$(CC) -E -o $@ $<

protected_mode.o: protected_mode.c
	$(CC) -c -std=c99 -m32 -I $(head) -I$(global) -o $@ $<

clean:
	rm -f *.i *.o

