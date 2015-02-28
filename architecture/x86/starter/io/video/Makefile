include ../../../../../tools.make

.PHONY : clean

global_head = ../../../../../include/
head   = ../../../include/

all: vga_character.o print.o

vga_character.o: vga_character.i
	$(AS) --warn --32 -o $@ $<

vga_character.i: vga_character.S
	$(CC) -E -I $(head) -o $@ $<

print.o: print.c
	$(CC) -c -std=c99 -m32 -I $(global_head) -I $(head) -o $@ $<

clean:
	$(RM) -f *.i *.o
