//-> Incluindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-> Definindo constantes
#define TAMANHO_LINHA 30

//-> Definindo structs
typedef struct {
    int endBranch, endAlvo;
    char desvio;
} dadosLinha;

typedef struct {
    int nBranchesExecutados;
    int nAcertosNT;
    int nAcertosT;
    int nAcertosDireção;
    int nAcertos1bit;
    int nAcertos2bits;
} medidasDesempenho;

//-> Protótipos das funções
// Função para simulação da técnica de predição
void simulacao(const char* arquivoTrace, medidasDesempenho *md, void (*predicao)(dadosLinha, medidasDesempenho*));

// Função para técnica de predição por direção
void predPorDirecao(dadosLinha dados, medidasDesempenho* md);