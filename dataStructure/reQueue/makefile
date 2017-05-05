SQueue:main.o SQueue.o LinkList.o LinkStack.o
	gcc -o SQueue main.o SQueue.o LinkList.o LinkStack.o
main.o:main.c SQueue.h
	gcc -c main.c
SQueue.o:SQueue.c SQueue.h LinkList.h LinkStack.h
	gcc -c SQueue.c
LinkStack.o:LinkStack.c LinkStack.h
	gcc -c LinkStack.c
LinkList.o:LinkList.c LinkList.h
	gcc -c LinkList.c
clean:
	rm SQueue main.o SQueue.o LinkList.o LinkStack.o