include ../../../tools.make

.PHONY : clean

global_head = ../../../include/
head = ../../include/
starter_head = ../../include/

print.o: print.c
	$(CC) -c -std=c99 -I $(global_head) -I $(head) -I $(starter_head) -o $@ $<

clean:
	$(RM) -f *.o
