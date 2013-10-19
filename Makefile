%.o: %.c

memory: memory.o main.o
	gcc -o $@ memory.o main.o

memory.o: memory.h
	gcc -c $*.c

main.o: memory.h
	gcc -c $*.c
	
