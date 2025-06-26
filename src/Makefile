
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

exp2:
	./simpred traces/trace_fft_mi.txt 0
	./simpred traces/trace_gsm_decoder_me.txt 0
	./simpred traces/trace_patricia_mi.txt 0

exp3:
	./simpred traces/trace_rijndael_encoder_mi.txt 16
	./simpred traces/trace_rijndael_encoder_mi.txt 32
	./simpred traces/trace_rijndael_encoder_mi.txt 64
	./simpred traces/trace_rijndael_encoder_mi.txt 128
	./simpred traces/trace_rijndael_encoder_mi.txt 256
	./simpred traces/trace_rijndael_encoder_mi.txt 512
	./simpred traces/trace_rijndael_encoder_mi.txt 1024
	./simpred traces/trace_rijndael_encoder_mi.txt 2048
