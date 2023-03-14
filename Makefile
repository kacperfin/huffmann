a.out: main.o huffmann.o ascii.o
	$(CC) -o a.out main.o huffmann.o ascii.o

.PHONY: clean

clean:
	-rm *.o
