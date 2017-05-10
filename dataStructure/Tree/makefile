GTree:main.o GTree.o LinkList.o
	gcc -o GTree main.o GTree.o LinkList.o
main.o:main.c GTree.h
	gcc -c main.c
GTree.o:GTree.c GTree.h LinkList.h
	gcc -c GTree.c
LinkList.o:LinkList.c LinkList.h
	gcc -c LinkList.c
clean:
	rm main.o GTree.o LinkList.o