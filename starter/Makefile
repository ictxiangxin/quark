include ../tools.make

.PHONY : io clean

architecture_object = $(x86_object)
architecture_library = $(x86_library)

head = ../include/
starter_head = ./include/

x86_object = ../architecture/x86/starter/io/video/vga_character.o \
             ../architecture/x86/starter/io/video/print.o \
             ../architecture/x86/starter/initialize.o

x86_library = ../architecture/x86/library/physical_memory.o \
              ../architecture/x86/library/low_level.o

io_object = io/video/print.o

all: io core.b

core.b: entry.o core.o
	$(LD) -s -Ttext 0x10000 --oformat binary -melf_i386 -o $@ $^ $(architecture_object) $(architecture_library) $(io_object)

core.o: core.c
	$(CC) -c -std=c99 -m32 -I $(head) -I $(starter_head) -o $@ $<

entry.o: entry.S
	$(AS) --warn --32 -o $@ $<

io:
	(cd io; $(MAKE))

clean:
	$(RM) -f *.o *.b core starter
	(cd io; $(MAKE) $@)
