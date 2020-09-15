all: add-nbo

add-nbo: add-nbo.o main.o
	gcc -o add-nbo add-nbo.o main.o

add-nbo.o: add-nbo.h add-nbo.c
	gcc -c -o add-nbo.o add-nbo.c

main.o: add-nbo.h main.c
	gcc -c -o main.o main.c

clean:
	rm -f add-nbo *.o

