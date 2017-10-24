all: convert.o MaxMin.h
	gcc convert.o MaxMin.h -lm -o gitHub

convert.o: convert.c MaxMin.h
	gcc -c convert.c

MaxMin.h:
	gcc -c MaxMin.h

clean:
	rm *.o *.gch gitHub 
