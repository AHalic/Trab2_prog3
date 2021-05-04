#include "../include/Eleicao.h"

#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

#include "../include/Partido.h"
#include "../include/Candidato.h"

using namespace std;

Eleicao::Eleicao(time_t dataEleicao, vector<Partido*> partidos, vector<Candidato*> candidatos) {
    this->dataEleicao = dataEleicao;
    this->partidos = partidos;
    this->candidatos = candidatos;
    this->votos = new Votos();
    this->vagas = 0;

    this->setQtdVagas();
    this->setVotosTotais();
    this->ordenaCandidatos();
    this->ordenaPartidoCandidatos();
    // falta ordenar o vetor de partidos
}

        
time_t Eleicao::getDataEleicao() const {
    return dataEleicao;
}

int Eleicao::getVotosNominais() const {
    return this->votos->getVotosNominais();
}

int Eleicao::getVotosLegenda() const {
    return this->votos->getVotosLegenda();
}

int Eleicao::getVotosTotais() const {
    return this->votos->getVotosTotais();
}

int Eleicao::getVagas() const {
    return vagas;
}

vector<Candidato*> Eleicao::getCandidatos() const {
    return candidatos;
}

vector<Partido*> Eleicao::getPartidos() const {
    return partidos;
}

void Eleicao::setQtdVagas() {
    for (Partido* aux: partidos) {
        vagas += aux->getQtdVagas();
    }
}

void Eleicao::setVotosTotais(){
    int nominais = 0;
    int legenda = 0;

    for (Partido* aux: this->partidos) {
        nominais += aux->getVotosNominais();
        legenda += aux->getVotosLegenda();
    }

    votos->setVotosLegenda(legenda);
    votos->setVotosNominais(nominais);
}


int Eleicao::getFEleitas() const {
    int qtdF = 0;
    for (Candidato* aux : candidatos) {
        if(aux->ehGeneroF() && aux->ehEleito()) 
            qtdF++;
    }

    return qtdF;
}

void Eleicao::ordenaPartidoCandidatos() {
    if (!this->partidos.empty()) {
        for (Partido* aux: this->partidos) {
            aux->ordenaCandidatos();
        }
    }
}

void Eleicao::ordenaCandidatos() {
    if(!this->candidatos.empty())
        sort(this->candidatos.begin(), this->candidatos.end(), comparaVotos);
}