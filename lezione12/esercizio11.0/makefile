LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main : main.cc prisma.cc randomgen.h prisma.h
	g++ -o main main.cc prisma.cc ${INCS} ${LIBS} 

clean:
	rm main.cc