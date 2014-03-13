include ./tools.make

x86:
	(cd architecture; $(MAKE) $@)

clean:
	(cd architecture; $(MAKE) $@)
