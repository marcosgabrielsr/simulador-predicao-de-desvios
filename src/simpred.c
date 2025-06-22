#include <stdio.h>
#include <stdlib.h>
#include "tecpred.h"

int main(int argc, char const *argv[])
{
    // Lendo nome do arquivo e número de linhas do BPB
    const char *arquivo = argv[1];
    int nLinhasBPB = atoi(argv[2]);
    medidasDesempenho mdPPD;

    // predicao por direcao
    simulacao(arquivo, &mdPPD, predPorDirecao);
    printf("Medidas de desempenho Predicao por Direcao:\n");
    printf("-> nAcertosDirecao: %d\n", mdPPD.nAcertosDirecao);
    printf("-> nBranchesExecutados: %d\n", mdPPD.nBranchesExecutados);

    // Predicao 1-bit
    pred1bit(arquivo, nLinhasBPB, &mdPPD);
    printf("Medidas de desempenho Predicao 1-bit:\n");
    printf("-> nAcertos1bit: %d\n", mdPPD.nAcertos1bit);
    printf("-> nBranchesExecutados: %d\n", mdPPD.nBranchesExecutados);

    // Predicao 2-bits
    pred2bits(arquivo, nLinhasBPB, &mdPPD);
    printf("Medidas de desempenho Predicao 2-bits:\n");
    printf("-> nAcertos2bits: %d\n", mdPPD.nAcertos2bits);
    printf("-> nBranchesExecutados: %d\n", mdPPD.nBranchesExecutados);

    return EXIT_SUCCESS;
}