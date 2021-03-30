.PHONY: clean
#all: main.o
#	g++ main.o -L./lib -lgtest -lpthread
#main.o: main.c
#	g++ -I./include -c main.c
#clean:
#	rm -f *.o a.out
all: main.o haizei/test.o haizei/test.h
	g++ -I./ main.o haizei/test.o -o ./bin/haizei
main.o: main.c haizei/test.h
	g++ -I./ -c main.c 
haizei/test.o: haizei/test.c haizei/test.h
	g++ -I./ -c haizei/test.c -o haizei/test.o
clean:
	rm -rf bin/haizei main.o haizei/test.o
