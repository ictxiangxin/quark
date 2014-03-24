include ../tools.make

.PHONY : io clean

architecture_object = $(x86_object)
architecture_library = $(x86_library)

x86_object = ../architecture/x86/starter/io/video/vga_character.o \
             ../architecture/x86/starter/io/video/print.o \

x86_library = ../architecture/x86/library/physical_memory.o \

io_object = io/video/print.o

all: io core.b

core.b: core
	$(OBJCOPY) -O binary $< $@

core: entry.o core.o
	$(LD) -s -Ttext 0x10000 -o $@ $^ $(architecture_object) $(architecture_library) $(io_object)

core.o: core.c
	$(CC) -c -o $@ $<

entry.o: entry.S
	$(AS) --warn -o $@ $<

io:
	(cd io; $(MAKE))

clean:
	$(RM) -f *.o *.b core starter
	(cd io; $(MAKE) $@)
