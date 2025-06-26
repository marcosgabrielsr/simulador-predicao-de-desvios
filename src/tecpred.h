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
    int nAcertosDirecao;
    int nAcertos1bit;
    int nAcertos2bits;
} medidasDesempenho;

//-> Protótipos das funções
// Função para inicializar medidas de desempenho como zero
void iniciarMedidas(medidasDesempenho *md);
// Função para pegar os dados da linha do trace a armazená-los
void pegarDadosLinha(char* linha, dadosLinha *dados);
// Executa simulações das predições de desvio estáticas
void simulacao(const char* arquivoTrace, medidasDesempenho *md, void (*predicao)(dadosLinha, medidasDesempenho*));
// Função para técnica de predição not-taken
void predNotTaken(dadosLinha dados, medidasDesempenho* md);
// Função para técnica de predição taken
void predTaken(dadosLinha dados, medidasDesempenho* md);
// Função para técnica de predição por direção
void predPorDirecao(dadosLinha dados, medidasDesempenho* md);
// função para tecnica de predição 1-bit
void pred1bit(const char* arquivoTrace, int nLinhasBPB, medidasDesempenho* md);
// função para técnica de predição 2-bits
void pred2bits(const char* arquivoTrace, int nLinhasBPB, medidasDesempenho* md);