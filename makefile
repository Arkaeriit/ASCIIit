FLAGS = -Wall -Werror -g

all : ASCIIit.bin

boolArrayList.o : boolArrayList.c boolArrayList.h
	gcc -c boolArrayList.c $(FLAGS) -o boolArrayList.o

main.o : main.c main.h
	gcc -c main.c $(FLAGS) -o main.o

test.o : test.c
	gcc -c test.c $(FLAGS) -o test.o

test.bin : test.o boolArrayList.o 
	gcc boolArrayList.o test.o  $(FLAGS) -o test.bin

ASCIIit.bin : main.o boolArrayList.o 
	gcc boolArrayList.o morseZipConvert.o $(FLAGS) -o morseZip.bin

test : test.bin
	touch in1 #a file named in1 is needed for the test
	./test.bin

clean :
	rm -f *.o
	rm -f *.bin
	rm -f out*

