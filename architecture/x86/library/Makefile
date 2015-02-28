include ../../../tools.make

.PHONY : clean

global = ../../../include/
head   = ../include/

all: low_level.o physical_memory.o protected_mode.o

low_level.o: low_level.i
	$(AS) --warn --32 -o $@ $<

low_level.i: low_level.S
	$(CC) -E -o $@ $<

physical_memory.o: physical_memory.i
	$(AS) --warn --32 -o $@ $<

physical_memory.i: physical_memory.S
	$(CC) -E -o $@ $<

protected_mode.o: protected_mode.c
	$(CC) -c -std=c99 -m32 -I $(head) -I$(global) -o $@ $<

clean:
	rm -f *.i *.o

