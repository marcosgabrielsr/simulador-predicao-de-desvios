// Includingo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "tecpred.h"

int main(int argc, char const *argv[])
{
    // Lendo nome do arquivo e número de linhas do BPB
    const char *arquivo = argv[1];
    //int nLinhasBPB = atoi(argv[2]);
    medidasDesempenho mdPPD;

    simulacao(arquivo, &mdPPD, predPorDirecao);
    printf("Medidas de desempenho Predição por Direção: \n");
    printf("-> nAcertosDirecao: %d\n", mdPPD.nAcertosDireção);
    printf("-> nBranchesExecutados: %d\n", mdPPD.nBranchesExecutados);
    
    return EXIT_SUCCESS;
}
