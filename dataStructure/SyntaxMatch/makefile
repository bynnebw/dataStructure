SyntaxMatch:main.o LinkStack.o LinkList.o
	gcc -o SyntaxMatch main.o LinkStack.o LinkList.o
main.o:main.c LinkStack.h
	gcc -c main.c
LinkStack.o:LinkStack.c LinkStack.h LinkList.h
	gcc -c LinkStack.c
LinkList.o:LinkList.c LinkList.h
	gcc -c LinkList.c
clean:
	rm LinkStack main.o LinkStack.o LinkList.o