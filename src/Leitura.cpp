#include "../include/Leitura.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

static Partido* lerPartidoLinha(string linha) {
    stringstream s(linha);
    Partido* partidoAux = NULL;

    string nome, sigla, numeroPartidoStr, votosLegendaStr;
    int numeroPartido, votosLegenda;

    getline(s, numeroPartidoStr, ',');
    getline(s, votosLegendaStr, ',');
    getline(s, nome, ',');
    getline(s, sigla, ',');

    numeroPartido = atoi(&numeroPartidoStr[0]);
    votosLegenda = atoi(&votosLegendaStr[0]);

    cout << "Nome: " << nome << endl;
    cout << "Sigla: " << sigla << endl;
    cout << "Num: " << numeroPartido << endl;
    cout << "Votos: " << votosLegenda << endl;

    return partidoAux;
}

Partido* lerPartidos(string caminho) {
    ifstream fin;
    string linhaAux;
    Partido* partidoAux;
    vector<Partido*> partidos;

    try {
        fin.open(caminho, ios::in);
        // ler header
        getline (fin, linhaAux); // TODO: verificar se linhaAux tem informacoes certas
        
        while(getline(fin, linhaAux)) {
            partidoAux = lerPartidoLinha(linhaAux);
            cout << "\n\n";
        }
    }
    catch (const ifstream::failure& e) {
        // cerr << "Problemas com IO: " << strerror(errno);
        fin.close();
        return NULL;
    }
}

Candidato* lerCandidato(string caminho) {

}
