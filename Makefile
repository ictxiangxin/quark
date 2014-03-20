include ./tools.make

x86:
	(cd architecture; $(MAKE) $@)
	(cd starter; $(MAKE))

clean:
	(cd architecture; $(MAKE) $@)
	(cd starter; $(MAKE) $@)
