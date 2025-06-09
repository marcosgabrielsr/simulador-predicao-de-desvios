all: PredicaoPorDirecao.o
	g++ PredicaoPorDirecao.o main.cpp -o main -Wall
	rm *.o

PredicaoPorDirecao.o : TecnicaPredicao.o PredicaoPorDirecao.cpp
	g++ -c PredicaoPorDirecao.cpp

TecnicaPredicao.o : TecnicaPredicao.cpp
	g++ -c TecnicaPredicao.cpp

clean:
	rm main

teste:
	./main traceTest1.txt 5