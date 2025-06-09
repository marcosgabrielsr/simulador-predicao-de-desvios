#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TecnicaPredicao {
    public:
        // Atributos públicos
        // -- Medidas de desempenho
        int nBranchesExecutados, nAcertosNT, nAcertosT;
        int nAcertosDirecao, nAcertos1bit, nAcertos2bits;
        
        // -- Arquivo do Trace
        string arquivoTrace;

        // Método construtor
        TecnicaPredicao(const string _arquivoTrace) {
            nBranchesExecutados = 0;
            nAcertosNT = 0;
            nAcertosT = 0;
            nAcertosDirecao = 0;
            nAcertos1bit = 0;
            nAcertos2bits = 0;

            arquivoTrace = _arquivoTrace;
        }

        // Método modelo para executar predicao
        void predicao(int endBranch, int endAlvo, string desvio) {
            cout << "Este metodo serve como modelo para os demais metodos de predicao";
        }

        // Método pega da linha os valores endBranch, endAlvo e desvio
        void pegarDadosLinha(string linha, int &endBranch, int &endAlvo, string &desvio) {
            // Inicializa variaveis inicio e fim para pegar texto de tamanho n = fim - inicio que começa na posição inicio
            int inicio = 0, fim = linha.find(' ', inicio);
            
            endBranch = stoi(linha.substr(inicio, fim - inicio));
            inicio = fim + 1;
            fim = linha.find(' ', inicio);

            endAlvo = stoi(linha.substr(inicio, fim - inicio));
            inicio = fim + 1;
            fim = linha.find(' ', inicio);

            desvio = linha.substr(inicio, fim - inicio);
        }

        // Método para executar a simulação da técnia de predição dado um arquivo de trace
        void simulacao() {
            ifstream trace(arquivoTrace);
            if (!trace.is_open()) {
                cerr << "Erro ao abrir o arquivo: " << arquivoTrace << endl;
                return;
            }

            string linha, desvio;
            int endBranch, endAlvo;
            while (getline(trace, linha)) {
                pegarDadosLinha(linha, endBranch, endAlvo, desvio);
                predicao(endBranch, endAlvo, desvio);
                nBranchesExecutados++;
            }

            trace.close();
        }

        // Método para imprimir os resultados (medidas de desempenho) da Técnica de Predição de desvios
        void resultados() {
            cout << "nBranchesExecutados: " << nBranchesExecutados << "\n";
            cout << "nAcertosNT: " << nAcertosNT << "\n";
            cout << "nAcertosT: " << nAcertosT << "\n";
            cout << "nAcertosDirecao: " << nAcertosDirecao << "\n";
            cout << "nAcertos1bit: " << nAcertos1bit << "\n";
            cout << "nAcertos2bits: " << nAcertos2bits << "\n";
        }
};