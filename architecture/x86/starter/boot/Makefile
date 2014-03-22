include ../../../../tools.make

.PHONY : clean

head   = ../../include/
inline = ../../library/inline/

boot.b: boot.S
	$(CC) -E -I $(head) -I $(inline) -o boot.i $<
	$(AS) --warn -o boot.o boot.i
	$(OBJCOPY) -O binary boot.o $@

clean:
	$(RM) -f *.i *.o *.b

