include ../tools.make

.PHONY : clean

all: core.b

core.b: core
	$(OBJCOPY) -O binary $< $@

core: entry.o core.o
	$(LD) -s -Ttext 0x10000 -o $@ $^

core.o: core.c
	$(CC) -c -o $@ $<

entry.o: entry.S
	$(AS) --warn -o $@ $<

clean:
	$(RM) -f *.o *.b core starter
