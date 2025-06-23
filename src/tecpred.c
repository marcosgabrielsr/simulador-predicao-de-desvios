// Incluindo bibliotecas
#include "tecpred.h"

// Função para inicializar medidas de desempenho como zero
void iniciarMedidas(medidasDesempenho *md) {
    md->nBranchesExecutados = 0;
    md->nAcertosNT = 0;
    md->nAcertosT = 0;
    md->nAcertosDirecao = 0;
    md->nAcertos1bit = 0;
    md->nAcertos2bits = 0;
}

// Função para pegar os dados da linha do trace a armazená-los
void pegarDadosLinha(char* linha, dadosLinha *dados) {
    int pEspacos[3], c = 0;
    char aux[TAMANHO_LINHA];

    for(int i = 0; linha[i] != '\0'; i++) {
        if(linha[i] == ' ') {
            pEspacos[c] = i;
            c++;
        }
    }   
    // Copia endereço da branch para array auxiliar e depois converte o mesmo para inteiro
    memcpy(aux, linha, pEspacos[0]*sizeof(char));
    dados->endBranch = atoi(aux);

    // Copia endereço alvo para array auxiliar e depois converte o mesmo para inteiro
    memcpy(aux, &linha[pEspacos[0] + 1], (pEspacos[1] - pEspacos[0])*sizeof(char));
    dados->endAlvo = atoi(aux);

    // Caso esteja não esteja na última linha do arquivo, o desvio esta na posinção [x - 2]
    dados->desvio = (linha[strlen(linha) - 1] == '\n') ? linha[strlen(linha) - 2] : linha[strlen(linha) - 1];
}

// Função apra simulação da técnica de predição
void simulacao(const char* arquivoTrace, medidasDesempenho *md, void (*predicao)(dadosLinha, medidasDesempenho*)) {
    char linha[TAMANHO_LINHA];
    FILE *trace = fopen(arquivoTrace, "r");
    iniciarMedidas(md);

    if(!trace) {
        printf("Erro ao abrir o arquivo de trace!\n");
        exit(0);
    }

    dadosLinha dados;
    while(fgets(linha, TAMANHO_LINHA, trace) != NULL) {
        pegarDadosLinha(linha, &dados);
        predicao(dados, md);

        md->nBranchesExecutados++;
    }

    fclose(trace);
}

//Função para técnica de predição not-taken
void predNotTaken(dadosLinha dados, medidasDesempenho* md){
    char ocorrido = dados.desvio;

    if(ocorrido == 'N'){
        md->nAcertosNT++;
    }
}

//Função para técnica de predição taken
void predTaken(dadosLinha dados, medidasDesempenho* md){
    char ocorrido = dados.desvio;

    if(ocorrido == 'T'){
        md->nAcertosT++;
    }
}

// Função para técnica de predição por direção
void predPorDirecao(dadosLinha dados, medidasDesempenho* md) {
    char p;
    p = (dados.endBranch < dados.endAlvo) ? 'N' : 'T';

    if(p == dados.desvio) {
        md->nAcertosDirecao++;
    }
}