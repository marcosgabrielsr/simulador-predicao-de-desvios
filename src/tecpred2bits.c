/*
 * simupred/src/tecpred2bits.c
 * Preditor de 2 bits com flip após 2 erros consecutivos
 */

#include "tecpred.h"
#include <stdio.h>
#include <stdlib.h>

// Função para técnica de predição 2‐bits com flip após 2 erros
void pred2bits(const char* arquivoTrace, int nLinhasBPB, medidasDesempenho* md) {
    // BPB: contador saturante de 2 bits (0…3)
    unsigned char *BPB = calloc(nLinhasBPB, sizeof(unsigned char));
    if (!BPB) { fprintf(stderr, "Erro ao alocar BPB\n"); exit(EXIT_FAILURE); }
    // erro consecutivo por entrada
    unsigned char *errCount = calloc(nLinhasBPB, sizeof(unsigned char));
    if (!errCount) { free(BPB); fprintf(stderr, "Erro ao alocar errCount\n"); exit(EXIT_FAILURE); }

    iniciarMedidas(md);  // zera contadores

    char linha[TAMANHO_LINHA];
    FILE *trace = fopen(arquivoTrace, "r");
    if (!trace) { free(BPB); free(errCount); fprintf(stderr, "Erro ao abrir trace '%s'!\n", arquivoTrace); exit(EXIT_FAILURE); }

    dadosLinha dados;
    while (fgets(linha, TAMANHO_LINHA, trace)) {
        pegarDadosLinha(linha, &dados);
        int idx = (dados.endBranch >> 2) % nLinhasBPB;

        // estado atual e predição base
        unsigned char state = BPB[idx];
        char pred = (state >= 2) ? 'T' : 'N';

        // verifica acerto
        int hit = (pred == dados.desvio);
        if (hit) {
            md->nAcertos2bits++;
            errCount[idx] = 0;  // zera contador de erros
        } else {
            // incrementa erros consecutivos
            errCount[idx]++;
            // se atingiu 2 erros, faz flip e reseta
            if (errCount[idx] >= 2) {
                if (pred == 'T') {
                    BPB[idx] = 0;  // flip para Strongly Not Taken
                } else {
                    BPB[idx] = 3;  // flip para Strongly Taken
                }
                errCount[idx] = 0;
                // recalcula estado e predição pós-flip
                state = BPB[idx];
                pred = (state >= 2) ? 'T' : 'N';
                // não conta este flip como acerto
            }
        }

        // atualização saturante padrão
        if (dados.desvio == 'T') {
            if (BPB[idx] < 3) BPB[idx]++;
        } else {
            if (BPB[idx] > 0) BPB[idx]--;
        }

        md->nBranchesExecutados++;
    }

    fclose(trace);
    free(BPB);
    free(errCount);
}
