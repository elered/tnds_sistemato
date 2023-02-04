LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main : main.cc posizione.h campovettoriale.h particella.h puntomateriale.h
	g++ -o main main.cc ${INCS} ${LIBS} 

mainesempio : mainesempio.cc posizione.h campovettoriale.h particella.h puntomateriale.h
	g++ -o mainesempio mainesempio.cc ${INCS} ${LIBS} 

tgraph : tgraph.cc
	g++ -o tgraph tgraph.cc ${INCS} ${LIBS} 

clean:
	rm main.cc tgraph.cc mainesempio.cc