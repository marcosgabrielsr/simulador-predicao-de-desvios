#include <stdio.h>
#include <stdlib.h>
#include "tecpred.h"

int main(int argc, char const *argv[])
{
    // Lendo nome do arquivo e número de linhas do BPB
    const char *arquivo = argv[1];
    int nLinhasBPB = atoi(argv[2]);
    medidasDesempenho md;


    printf("=========================== %s ============================\n", arquivo);

    // Predicao Not Taken
    simulacao(arquivo, &md, predNotTaken);
    printf("Predicao Not Taken:\n");
    printf("-> nAcertosNT: %d\n", md.nAcertosNT);
    printf("-> nBranchesExecutados: %d\n", md.nBranchesExecutados);
    printf("-> Taxa de acertos: %.3lf\n", ((double)md.nAcertosNT/md.nBranchesExecutados)*100);

    printf("\n");

    // Predicao Taken
    simulacao(arquivo, &md, predTaken);
    printf("Predicao Taken:\n");
    printf("-> nAcertosT: %d\n", md.nAcertosT);
    printf("-> nBranchesExecutados: %d\n", md.nBranchesExecutados);
    printf("-> Taxa de acertos: %.3lf\n", ((double)md.nAcertosT/md.nBranchesExecutados)*100);

    printf("\n");

    // Predicao por direcao
    simulacao(arquivo, &md, predPorDirecao);
    printf("Medidas de desempenho Predicao por Direcao:\n");
    printf("-> nAcertosDirecao: %d\n", md.nAcertosDirecao);
    printf("-> nBranchesExecutados: %d\n", md.nBranchesExecutados);
    printf("-> Taxa de acertos: %.3lf\n", ((double)md.nAcertosDirecao/md.nBranchesExecutados)*100);

    // printf("\n");

    if(nLinhasBPB != 0) {
        // Predicao 1-bit
        pred1bit(arquivo, nLinhasBPB, &md);
        printf("Medidas de desempenho Predicao 1-bit:\n");
        printf("-> nAcertos1bit: %d\n", md.nAcertos1bit);
        printf("-> nBranchesExecutados: %d\n", md.nBranchesExecutados);
        printf("-> taxa de acertos: %.2lf\n", 100*((double)md.nAcertos1bit)/md.nBranchesExecutados);

        printf("\n");

        // Predicao 2-bits
        pred2bits(arquivo, nLinhasBPB, &md);
        printf("Medidas de desempenho Predicao 2-bits:\n");
        printf("-> nAcertos2bits: %d\n", md.nAcertos2bits);
        printf("-> nBranchesExecutados: %d\n", md.nBranchesExecutados);
        printf("-> taxa de acertos: %.2lf\n", 100*((double)md.nAcertos2bits)/md.nBranchesExecutados);

        printf("\n");
    }

    printf("==============================================================================================================\n\n");

    return EXIT_SUCCESS;
}