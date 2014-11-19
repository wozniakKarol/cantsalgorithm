FLAGS=-Wall -g 
MFLAGS=-lm
PART=-c
CC=gcc
OBJS=main.o macierz.o display.o ants.o pheromon.o prog.o trail.o

mrowki: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o mrowki $(MFLAGS)

main.o: main.c
	$(CC) $(FLAGS) $(PART) main.c -o main.o

macierz.o: macierz.c
	$(CC) $(FLAGS) $(PART) macierz.c -o macierz.o

display.o: display.c
	$(CC) $(FLAGS) $(PART) display.c -o display.o
	
ants.o: ants.c
	$(CC) $(FLAGS) $(PART) ants.c -o ants.o 	
pheromon.o: pheromon.c
	$(CC) $(FLAGS) $(PART) pheromon.c -o pheromon.o
	
prog.o: prog.c
	$(CC) $(FLAGS)  $(PART) prog.c -lm -o prog.o  
	
trail.o: trail.c
	$(CC) $(FLAGS) $(PART) trail.c -o trail.o





clean:
	rm -f *.o
