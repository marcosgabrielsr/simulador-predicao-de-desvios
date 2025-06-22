#include "tecpred.h"

// função para a tecnica de predição 1-bit
void pred1bit(const char* arquivoTrace, int nLinhasBPB, medidasDesempenho* md) {
    int *BPB = calloc(nLinhasBPB, sizeof(int));             // tabela inicializada com zeros
    iniciarMedidas(md);                                    // zera todos os contadores

    char linha[TAMANHO_LINHA];
    FILE *trace = fopen(arquivoTrace, "r");
    if (!trace) {
        printf("Erro ao abrir o arquivo de trace!\n");
        exit(EXIT_FAILURE);
    }
    dadosLinha dados;
    while (fgets(linha, TAMANHO_LINHA, trace)) {
        pegarDadosLinha(linha, &dados);                     // extrai endBranch, endAlvo e desvio
        int idx = (dados.endBranch >> 2) % nLinhasBPB;
        char p = BPB[idx] ? 'T' : 'N';                      // faz previsão usando o bit atual
        if (p == dados.desvio) {
            md->nAcertos1bit++;                       // incrementa acertos se previsão for correta
        }
        BPB[idx] = (dados.desvio == 'T');            // atualiza o bit de predição  
        md->nBranchesExecutados++;               // incrementa o contador de branches executados   
    }
    free(BPB);  // libera a memória alocada para a tabela de predição           
    fclose(trace);
}
