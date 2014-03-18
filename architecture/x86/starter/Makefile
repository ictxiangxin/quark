include ../../../tools.make

.PHONY : boot clean

head   = ../include/
inline = library/inline/

all: boot real.b

boot:
	(cd boot; $(MAKE))

real.b: real.S
	$(CC) -E -I $(head) -I $(inline) -o real.i $<
	$(AS) --warn -o real.o real.i
	$(OBJCOPY) -O binary real.o $@

clean:
	$(RM) -f *.i *.o *.b
	(cd boot; $(MAKE) $@)
