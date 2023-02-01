INCS := `root-config --cflags`
LIBS := `root-config --libs`

main: main.cc funzioni.h 
	g++ -o main main.cc ${INCS} ${LIBS}

clean:
	rm main