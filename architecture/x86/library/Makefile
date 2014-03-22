include ../../../tools.make

.PHONY : io clean

all: physical_memory.o io

physical_memory.o: physical_memory.S
	$(CC) -E -o physical_memory.i $<
	$(AS) --warn -o $@ physical_memory.i

io:
	(cd io; $(MAKE))

clean:
	rm -f *.i *.o
	(cd io; $(MAKE) $@)
