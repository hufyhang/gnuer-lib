BIN=prog
GCC=gcc -g -Wall

${BIN}: prog.o arraylist.o
	${GCC} -o ${BIN} arraylist.o prog.o

arraylist.o: arraylist.h arraylist.c
	${GCC} -c arraylist.c

prog.o: prog.c arraylist.h
	${GCC} -c prog.c
