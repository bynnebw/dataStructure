BTree_Traversal:main.o LinkQueue.o BTree.o
	gcc -o BTree_Traversal main.o LinkQueue.o BTree.o
main.o:main.c LinkQueue.h BTree.h
	gcc -c main.c
BTree.o:BTree.c BTree.h
	gcc -c BTree.c
LinkQueue.o:LinkQueue.c LinkQueue.h
	gcc -c LinkQueue.c
clean:
	rm main.o LinkQueue.o BTree.o