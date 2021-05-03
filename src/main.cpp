#include <iostream>
#include <vector>

#include "../include/Candidato.h"
#include "../include/DateUtils.h"
#include "../include/Erros.h"
#include "../include/Leitura.h"
#include "../include/Partido.h"
#include "../include/Pessoa.h"
#include "../include/Votos.h"

int main (int argc, char *argv[]) {
    string caminhoCandidato = argv[1];
    string caminhoPartido = argv[2];
    string dataStr = argv[3];

    cout << caminhoPartido << endl;
    try {
        vector<Partido*> partidos = lePartidos(caminhoPartido);
        
        if (partidos.empty())
            throw domain_error("Partidos vazios");
        
        vector<Candidato*> candidatos = leCandidatos(caminhoCandidato);

        if (candidatos.empty()) 
            throw domain_error("Candidatos vazios");

    } catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}