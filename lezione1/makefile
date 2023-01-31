all: compila

compila: main.o funzioni.o
	g++ main.o funzioni.o -o compila

main.o: main.cc funzioni.h
	g++ -c main.cc -o main.o

funzioni.o: funzioni.cc funzioni.h
	g++ -c funzioni.cc -o funzioni.o

clean: 
	rm compila
	rm *.o