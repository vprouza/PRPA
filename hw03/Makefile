CFLAGS+=  -pedantic -Wall -std=c99 -O2
HW=hw02-b0b99prpa

program: main.c 
	$(CC) $(CFLAGS) main.c -o program

zip:
	zip $(HW)-brute.zip main.c

clean:
	rm -f *.o
	rm -f program
	rm -f $(HW)-brute.zip

.PHONY: clear zip
