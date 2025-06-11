
all: tecpred.o
	gcc tecpred.o simpred.c -o simpred -Wall
	rm *.o

tecpred.o: tecpred.h
	gcc -c tecpred.c

clean:
	rm *.o

teste:
	./simpred traceTest1.txt
