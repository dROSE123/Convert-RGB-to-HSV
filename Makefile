all: convert.o MaxMin.h.gch
	gcc convert.o MaxMin.h -o gitHub

convert.o: convert.c MaxMin.h.gch
	gcc -c convert.c

MaxMin.h.gch: MaxMin.h
	gcc -c MaxMin.h

clean:
	rm *.o *.gch 
