#include <iostream>
#include <vector>

#include "../include/Candidato.h"
#include "../include/DateUtils.h"
#include "../include/Erros.h"
#include "../include/Leitura.h"
#include "../include/Partido.h"
#include "../include/Pessoa.h"
#include "../include/Votos.h"

using namespace cpp_util;

int main (int argc, char *argv[]) {
    /*
    string caminhoCandidato = argv[1];
    string caminhoPartido = argv[2];
    string dataStr = argv[3];

    cout << caminhoPartido << endl;
    try {
        vector<Partido*> partidos = lePartidos(caminhoPartido);
        
        if (partidos.empty())
            throw domain_error("Partidos vazios");

        for (Partido* aux : partidos) {
            cout << aux << endl;
        }
        
        vector<Candidato*> candidatos = leCandidatos(caminhoCandidato);

        if (candidatos.empty()) 
            throw domain_error("Candidatos vazios");

    } catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    }
    */

    /*
    // Teste de Pessoa
    time_t niver = parseDate("22/07/1998");
    time_t hoje = parseDate("03/05/2021");
    Pessoa* p = new Pessoa("bea maia", 'F', niver);
    cout << "pessoa: "<< p << endl;
    cout << p->calculaIdade(hoje) << endl;
    */
    return 0;
}