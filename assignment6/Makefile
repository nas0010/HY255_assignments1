all: createData3.c createData6.c createData9.c
	gcc -Wall -ansi -pedantic -o createData3 createData3.c
	./createData3 > data3
	gcc -Wall -ansi -pedantic -o createData6 createData6.c
	./createData6 > data6
	gcc -Wall -ansi -pedantic -o createData9 createData9.c
	./createData9 > data9

data3: createData3.c 
	gcc -Wall -ansi -pedantic -o createData3 createData3.c
	./createData3 > data3

data6: createData6.c 
	gcc -Wall -ansi -pedantic -o createData6 createData6.c
	./createData6 > data6

data9: createData9.c 
	gcc -Wall -ansi -pedantic -o createData9 createData9.c
	./createData9 > data9

clean:
	rm createData3
	rm createData6
	rm createData9
	rm data3
	rm data6
	rm data9
	

