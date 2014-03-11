include ../../../../tools.make

header = ../../include/
inline = ../library/inline/

boot.b: boot.S
	$(CC) -E -I $(header) -I $(inline) -o boot.i $<
	$(AS) -o boot.o boot.i
	$(OBJCOPY) -O binary boot.o $@

clean:
	$(RM) -f *.i *.o *.b

