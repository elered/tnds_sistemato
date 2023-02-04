LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main : main.cpp FunzioneBase.h RandomGen.h funzioni.h
	g++ -o main main.cpp ${INCS} ${LIBS} 

clean:
	rm main