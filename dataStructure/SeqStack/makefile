SeqStack:main.o SeqStack.o SeqList.o
	gcc -o SeqStack main.o SeqStack.o SeqList.o
main.o:main.c SeqStack.h SeqList.h 
	gcc -c main.c
SeqStack.o:SeqStack.c SeqStack.h SeqList.h
	gcc -c SeqStack.c
SeqList.o:SeqList.c SeqList.h
	gcc -c SeqList.c
clean:
	rm SeqStack main.o SeqStack.o