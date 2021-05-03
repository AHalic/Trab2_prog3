#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>
#include <string>
#include <vector>

#include "../include/Candidato.h"
#include "../include/Votos.h"

using namespace std;

class Partido {
    private: 
        string nome;
        string sigla;
        int numero;
        Votos* votos;
        vector<Candidato*> candidatos;
        int vagas;
        static bool comparaVotos(Candidato* c1, Candidato* c2);

    public:
        Partido(string nome, string sigla, int votosLegenda, int numero);  
        
        string getNome() const;
        string getSigla() const;
        int getNumero() const;
        int getVotosNominais() const;
        int getVotosLegenda() const;
        int getVotosTotais() const;
        int getQtdVagas() const;
        vector <Candidato*> getCandidatos() const;
        
        void setVotosNominais(int votos);

        string toString() const;

        void insereCandidato(Candidato* c);
        void ordenaCandidatos();  
};

#endif