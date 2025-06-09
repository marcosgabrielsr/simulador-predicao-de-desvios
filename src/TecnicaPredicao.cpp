#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TecnicaPredicao {
    public:
        // Atributos públicos
        int nBranchesExecutados, nAcertosNT, nAcertosT;
        int nAcertosDirecao, nAcertos1bit, nAcertos2bits;
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
        void predicao(int endBranch, int endAlvo) {
            cout << "Esta funcao retorna a predicao";
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
                // Fragmentando linha para endBranch, andAlvo, desvio
                int inicio = 0, fim = linha.find(' ', inicio);
                cout << linha << "\n";
                cout << fim << "\n";
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