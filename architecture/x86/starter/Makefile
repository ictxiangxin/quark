include ../../../tools.make

.PHONY : boot io clean

global = ../../../include/
head   = ../include/
inline = ../library/inline/

all: boot io real_mode.b initialize.o

boot:
	(cd boot; $(MAKE))

io:
	(cd io; $(MAKE))

real_mode.b: real_mode.S
	$(CC) -E -I $(head) -I $(inline) -I $(global) -D _ASSEMBLY_ -o real_mode.i $<
	$(AS) --warn -o real_mode.o real_mode.i
	$(OBJCOPY) -O binary real_mode.o $@

initialize.o: initialize.c
	$(CC) -c -I $(head) -I $(global) -o $@ $<

clean:
	$(RM) -f *.i *.o *.b
	(cd boot; $(MAKE) $@)
	(cd io; $(MAKE) $@)
