DLinkList:main.o DLinkList.o
	gcc -o DLinkList main.o DLinkList.o
main.o:main.c DLinkList.h
	gcc -c main.c
DLinkList.o:DLinkList.c DLinkList.h
	gcc -c DLinkList.c
clean:
	rm DLinkList main.o DLinkList.o