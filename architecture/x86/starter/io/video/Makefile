include ../../../../../tools.make

.PHONY : clean

global = ../../../../../include/
head   = ../../../include/

all: vga_character.o print.o

vga_character.o: vga_character.S
	$(CC) -E -I $(head) -o vga_character.i $<
	$(AS) --warn -o $@ vga_character.i

print.o: print.c
	$(CC) -c -I $(global) -I $(head) -o $@ $<

clean:
	$(RM) -f *.i *.o
