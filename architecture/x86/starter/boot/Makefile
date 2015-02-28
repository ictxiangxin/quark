include ../../../../tools.make

.PHONY : clean

head   = ../../include/
inline = ../../library/inline/

boot.b: boot.o
	$(LD) -Ttext 0 --oformat binary -melf_i386 -o $@ $<

boot.i: boot.S
	$(CC) -E -I $(head) -I $(inline) -o $@ $<

boot.o: boot.i
	$(AS) --warn --32 -o $@ $<

clean:
	$(RM) -f *.i *.o *.b

