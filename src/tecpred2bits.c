#include "tecpred.h"

// Função para técnica de predição 2-bits
void pred2bits(const char* arquivoTrace, int nLinhasBPB, medidasDesempenho* md) {
    int *BPB = calloc(nLinhasBPB, sizeof(int));
    iniciarMedidas(md);
    char linha[TAMANHO_LINHA];
    FILE *trace = fopen(arquivoTrace, "r");
    if (!trace) {
        printf("Erro ao abrir o arquivo de trace!\n");
        exit(EXIT_FAILURE);
    }
    dadosLinha dados;
    while(fgets(linha, TAMANHO_LINHA, trace)) {
        pegarDadosLinha(linha, &dados);
        int idx = (dados.endBranch >> 2) % nLinhasBPB;
        int state = BPB[idx];
        char p = (state >= 2) ? 'T' : 'N';
        if (p == dados.desvio) md->nAcertos2bits++;
        if (dados.desvio == 'T' && state < 3) BPB[idx]++;
        else if (dados.desvio == 'N' && state > 0) BPB[idx]--;
        md->nBranchesExecutados++;
    }
    free(BPB);
    fclose(trace);
}
