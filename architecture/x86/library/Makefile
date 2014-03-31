include ../../../tools.make

.PHONY : clean

global = ../../../include/
head   = ../include/

all: low_level.o physical_memory.o protected_mode.o

low_level.o: low_level.S
	$(CC) -E -o low_level.i $<
	$(AS) --warn -o $@ low_level.i

physical_memory.o: physical_memory.S
	$(CC) -E -o physical_memory.i $<
	$(AS) --warn -o $@ physical_memory.i

protected_mode.o: protected_mode.c
	$(CC) -c -I $(head) -I$(global) -o $@ $<

clean:
	rm -f *.i *.o

