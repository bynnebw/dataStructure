MGraph:main.o MGraph.o
	gcc -o MGraph main.o MGraph.o
main.o:main.c MGraph.h
	gcc -c main.c
MGraph.o:MGraph.c MGraph.h
	gcc -c MGraph.c
clean:
	rm main.o MGraph.o