BTree:main.o BTree.o
	gcc -o BTree main.o BTree.o
main.o:main.c BTree.h
	gcc -c main.c
BTree.o:BTree.c BTree.h
	gcc -c BTree.c
clean:
	rm main.o BTree.o