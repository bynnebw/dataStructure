LGraph:main.o LGraph.o LinkList.o
	gcc -o LGraph main.o LGraph.o LinkList.o
main.o:main.c LGraph.h LinkList.h
	gcc -c main.c
LGraph.o:LGraph.c LGraph.h LinkList.h
	gcc -c LGraph.c 
LinkList.o:LinkList.c LinkList.h
	gcc -c LinkList.c
clean: 
	rm main.o LGraph.o LinkList.o
