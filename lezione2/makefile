main: main.o vettore.o funzioni.o
	g++ main.o vettore.o funzioni.o -o main

main.o: main.cc funzioni.h
	g++ -c main.cc -o main.o

funzioni.o: funzioni.cc funzioni.h
	g++ -c funzioni.cc -o funzioni.o

vettore.o: vettore.cc vettore.h
	g++ -c vettore.cc -o vettore.o

clean: 
	rm *.o

cleanall: 
	rm main
