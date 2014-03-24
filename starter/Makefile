include ../tools.make

.PHONY : library clean

architecture_library = $(x86_library)

x86_library = ../architecture/x86/library/io/video/vga_character.o \
              ../architecture/x86/library/io/video/print.o \
              ../architecture/x86/library/physical_memory.o \

library = library/io/video/print.o

all: library core.b

core.b: core
	$(OBJCOPY) -O binary $< $@

core: entry.o core.o
	$(LD) -s -Ttext 0x10000 -o $@ $^ $(architecture_library) $(library)

core.o: core.c
	$(CC) -c -o $@ $<

entry.o: entry.S
	$(AS) --warn -o $@ $<

library:
	(cd library; $(MAKE))

clean:
	$(RM) -f *.o *.b core starter
	(cd library; $(MAKE) $@)
