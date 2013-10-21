memory: memory.o main.o
	gcc -o $@ memory.o main.o

memory.o: memory.c memory.h
	gcc -c $*.c

main.o: main.c memory.h
	gcc -c $*.c
	
