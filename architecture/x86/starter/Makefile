include ../../../tools.make

.PHONY : boot io clean

global_head = ../../../include/
head   = ../include/
inline = ../library/inline/

all: boot io real_mode.b initialize.o

boot:
	(cd boot; $(MAKE))

io:
	(cd io; $(MAKE))

real_mode.b: real_mode.o
	$(LD) -Ttext 0 --oformat binary -melf_i386 -o $@ $<

real_mode.o: real_mode.i
	$(AS) --warn --32 -o $@ $<

real_mode.i: real_mode.S
	$(CC) -E -I $(head) -I $(inline) -I $(global_head) -D _ASSEMBLY_ -o $@ $<

initialize.o: initialize.c
	$(CC) -c -std=c99 -m32 -I $(head) -I $(global_head) -o $@ $<

clean:
	$(RM) -f *.i *.o *.b
	(cd boot; $(MAKE) $@)
	(cd io; $(MAKE) $@)
