LinkQueue:main.o LinkQueue.o LinkList.o
	gcc -o LinkQueue main.o LinkQueue.o LinkList.o
main.o:main.c LinkQueue.h
	gcc -c main.c
LinkQueue.o:LinkQueue.c LinkQueue.h LinkList.h
	gcc -c LinkQueue.c
LinkList.o:LinkList.c LinkList.h
	gcc -c LinkList.c
clean:
	rm LinkQueue main.o LinkQueue.o LinkList.o