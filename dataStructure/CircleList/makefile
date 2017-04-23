CircleList:main.o CircleList.o
	gcc -o CircleList main.o CircleList.o
main.o:main.c CircleList.h
	gcc -c main.c
CircleList.o:CircleList.c CircleList.h
	gcc -c CircleList.c
clean:
	rm CircleList main.o CircleList.o