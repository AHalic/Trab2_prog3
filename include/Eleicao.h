#ifndef ELEICAO_H
#define ELEICAO_H

#include "../include/Eleicao.h"

#include <string>
#include <iostream>
#include <ctime>
#include <vector>

#include "../include/Partido.h"
#include "../include/Candidato.h"

using namespace std;

class Eleicao {
    private:
        time_t dataEleicao;
        Votos* votos;
        int vagas;
        vector<Partido*> partidos;
        vector<Candidato*> candidatos;
        void setVotosTotais();
        void ordenaCandidatosPorVoto();

    public:
        Eleicao(time_t dataEleicao, vector<Partido*> partidos, vector<Candidato*> candidatos);
        
        time_t getDataEleicao() const;
        int getVotosNominais() const;
        int getVotosLegenda() const;
        int getVotosTotais() const;
        int getVagas() const;
        vector<Candidato*> getCandidatos() const;
        vector<Partido*> getPartidos() const;
        void ordenaPartidoCandidatos();
        void ordenaCandidatos();

        void setQtdVagas();

        int getFEleitas() const;

};

#endif

