#防止目录下有名为clean的文件出现歧义
.PHONY: clean
all: header1.o header2.o header3.o test.o
	gcc header1.o header2.o header3.o test.o
header1.o: ./src/header1.c
	gcc -I./include -c ./src/header1.c
header2.o: ./src/header2.c
	gcc -I./include -c ./src/header2.c
header3.o: ./src/header3.c
	gcc -I./include -c ./src/header3.c
test.o: test.c
	gcc -I./include -c test.c
clean:
	rm -rf *.o a.out
