include ../../../../tools.make

.PHONY : clean

global_head = ../../../../include/
head = ../../../include/

print.o: print.c
	$(CC) -c -I $(global_head) -I $(head) -o $@ $<

clean:
	$(RM) -f *.o
