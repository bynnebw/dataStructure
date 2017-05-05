LinkQueue:main.o LinkQueue.o
	gcc -o LinkQueue main.o LinkQueue.o 
main.o:main.c LinkQueue.h
	gcc -c main.c
LinkQueue.o:LinkQueue.c LinkQueue.h
	gcc -c LinkQueue.c
clean:
	rm LinkQueue main.o LinkQueue.o