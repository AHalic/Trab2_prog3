#include <iostream>
#include <vector>

#include "../include/Votos.h"
#include "../include/Pessoa.h"
#include "../include/Candidato.h"
#include "../include/Partido.h"
#include "../include/Eleicao.h"
#include "../include/Leitura.h"
#include "../include/DateUtils.h"
#include "../include/Erros.h"

using namespace std;
using namespace cpp_util;

int main (int argc, char *argv[]) {
    setlocale(LC_ALL, "pt_BR.utf8");

    if(argc != 4) {
        cerr << "Quantidade de argumentos inválida!" << endl;
        exit(1);
    }
    
    string caminhoCandidato = argv[1];
    string caminhoPartido = argv[2];
    string dataEleicaoStr = argv[3];
    
    time_t dataEleicao;
    vector<Partido*> partidos;
    vector<Candidato*> candidatos;

    try {
        if(!validDate(dataEleicaoStr)) {
            throw runtime_error("Erro de parsing de string para time_t.");
        }

        dataEleicao = parseDate(dataEleicaoStr);
    } catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

    try {
        partidos = lePartidos(caminhoPartido);
        
        if (partidos.empty())
            throw domain_error("Partidos vazios");
        
        candidatos = leCandidatos(caminhoCandidato, partidos);

        if (candidatos.empty()) 
            throw domain_error("Candidatos vazios");

    } catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

    Eleicao* eleicao = new Eleicao(dataEleicao, partidos, candidatos);
    cout << "Sobre a eleicao:" << endl;
    cout << "Vagas: " << eleicao->getVagas() << endl;
    cout << "F: " << eleicao->getFEleitas() << endl;
    cout << "Votos: " << eleicao->getVotosTotais() << endl;

    // cout << "oi" << endl;
    // for(Partido* aux: partidos) {
    //     cout << "oi" << endl;
    //     aux->ordenaCandidatos();
    // }
    // Teste de Pessoa
    // time_t niver = parseDate("22/07/1998");
    // time_t hoje = parseDate("03/05/2021");
    // Partido* p = new Partido("Partido da Sophie", "SP", 3, 1);
    // Candidato* c = new Candidato("Sophie", 'F', niver, "Eleito", "Halic", 35, 11111, "Eleito", p);
    // Pessoa* p = new Pessoa("bea maia", 'F', niver);
    // cout << "pessoa: "<< p << endl;
    // cout << p->calculaIdade(hoje) << endl;
    // cout << c << endl;

    return 0;
}