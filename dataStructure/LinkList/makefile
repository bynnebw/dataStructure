LinkList:main.o LinkList.o
	gcc -o LinkList main.o LinkList.o
main.o:main.c LinkList.h
	gcc -c main.c
LinkList.o:SeqList.c LinkList.h
	gcc -c LlinkList.c
clean:
	rm LinkList main.o LinkList.o