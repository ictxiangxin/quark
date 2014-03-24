include ../../../tools.make

.PHONY : boot io clean

head   = ../include/
inline = ../library/inline/
global = ../../../include/

all: boot io real_mode.b

boot:
	(cd boot; $(MAKE))

io:
	(cd io; $(MAKE))

real_mode.b: real_mode.S
	$(CC) -E -I $(head) -I $(inline) -I $(global) -o real_mode.i $<
	$(AS) --warn -o real_mode.o real_mode.i
	$(OBJCOPY) -O binary real_mode.o $@

clean:
	$(RM) -f *.i *.o *.b
	(cd boot; $(MAKE) $@)
	(cd io; $(MAKE) $@)
