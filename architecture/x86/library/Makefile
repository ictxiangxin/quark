include ../../../tools.make

.PHONY : clean

all: physical_memory.o

physical_memory.o: physical_memory.S
	$(CC) -E -o physical_memory.i $<
	$(AS) --warn -o $@ physical_memory.i

clean:
	rm -f *.i *.o

