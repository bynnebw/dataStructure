SeqList:main.o SeqList.o
	gcc -o SeqList main.o SeqList.o
main.o:main.c SeqList.h
	gcc -c main.c
SeqList.o:SeqList.c SeqList.h
	gcc -c SeqList.c
clean:
	rm SeqList main.o SeqList.o