include ./tools.make

x86:
	(cd architecture; $(MAKE) $@)
	dd if=architecture/$@/starter/boot/boot.b of=hd.img count=1 conv=notrunc

clean:
	(cd architecture; $(MAKE) $@)
