
all: tecpred.o tecpred1bit.o tecpred2bits.o
	gcc tecpred.o tecpred1bit.o tecpred2bits.o simpred.c -o simpred -Wall
	rm *.o

tecpred.o: tecpred.h
	gcc -c tecpred.c

tecpred1bit.o: tecpred.h
	gcc -c tecpred1bit.c

tecpred2bits.o: tecpred.h
	gcc -c tecpred2bits.c

clean:
	rm *.o

teste:
	./simpred traceTest1.txt

experimento:
	./simpred traces/trace_fft_mi.txt 0
	./simpred traces/trace gsm decoder me.txt 0
	./simpred traces/trace patricia mi.txt 0
	./simpred traces/Taxa de acertos média.txt 0

