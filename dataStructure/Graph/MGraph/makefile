MGraph:main.o MGraph.o
	gcc -o MGraph main.c MGraph.c
main.o:main.c MGraph.h
	gcc -c main.c
MGraph.o:MGraph.h
	gcc -c MGraph.c
clean:
	rm main.o MGraph.o