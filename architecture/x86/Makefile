include ../../tools.make

.PHONY : starter library clean

all: starter library

starter:
	(cd starter; $(MAKE))

library:
	(cd library; $(MAKE))

clean:
	(cd starter; $(MAKE) $@)
	(cd library; $(MAKE) $@)
