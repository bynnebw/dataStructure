StaticList:main.o StaticList.o
	gcc -o StackList main.o StaticList.o
main.o:main.c StaticList.h
	gcc -c main.c
StaticList.o:StaticList.c StaticList.h
	gcc -c StaticList.c
clean:
	rm StaticList main.o StaticList.o