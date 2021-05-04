#include <iostream>
#include <vector>
#include <locale>

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
    setlocale(LC_ALL, "pt_BR.utf8");     // acho q eh inutil
    setlocale(LC_NUMERIC, "pt_BR.utf8"); // inutil
    setlocale(LC_TIME, "pt_BR.utf8");    // inutil 
    float x = 3.4546;
    cout << "antes " << x << endl;

    cout.imbue(locale("pt_BR.utf8"));    // oq realmente funciona

    if(argc != 4) {
        cerr << "Quantidade de argumentos inválida!" << endl;
        exit(1);
    }
    cout << "depois " << x << endl;
    
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
    // eleicao->ordenaCandidatos();
    // eleicao->ordenaPartidoCandidatos();
    
    // cout << "------ordenado--------" << endl;
    // for (Partido* p : eleicao->getPartidos()) {
    //     cout << endl;
    //     cout << p << endl;
    //     for(Candidato* c : p->getCandidatos()) {
    //         cout << c << endl;
    //     }
    // }
    // cout << "------fim--------" << endl;

    return 0;
}
