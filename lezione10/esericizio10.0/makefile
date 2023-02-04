LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main : main.cc randomgen.h
	g++ -o main main.cc ${INCS} ${LIBS} 

clean:
	rm main.cc