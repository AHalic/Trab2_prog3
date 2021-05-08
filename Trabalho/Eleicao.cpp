/**
 * Relatorio.cpp
 * Declaracao de funcoes e da classe Eleicao
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 04/05/2021
**/

#include "Eleicao.h"

#include <string>
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

#include "Partido.h"
#include "Candidato.h"


Eleicao::Eleicao(time_t& dataEleicao, vector<Partido*> partidos, vector<Candidato*> candidatos) {
    this->dataEleicao = dataEleicao;
    this->partidos = partidos;
    this->candidatos = candidatos;
    this->votos = Votos();
    this->vagas = 0;

    this->setQtdVagas();
    this->setVotosTotais();
    this->ordenaCandidatos();
    this->ordenaCandidatosPartidos();
    this->ordenaPartidos();
}

// Eleicao::~Eleicao() { 
//     // for (Partido* p: partidos) {
//     //     delete p;
//     // }

//     // for (Candidato* c: candidatos) {
//     //     delete c;
//     // }
// }
        
time_t Eleicao::getDataEleicao() const {
    return dataEleicao;
}

int Eleicao::getVotosNominais() const {
    return this->votos.getVotosNominais();
}

int Eleicao::getVotosLegenda() const {
    return this->votos.getVotosLegenda();
}

int Eleicao::getVotosTotais() const {
    return this->votos.getVotosTotais();
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

    votos.setVotosLegenda(legenda);
    votos.setVotosNominais(nominais);
}

int Eleicao::getFEleitas() const {
    int qtdF = 0;
    for (Candidato* aux : candidatos) {
        if(aux->ehGeneroF() && aux->ehEleito()) 
            qtdF++;
    }

    return qtdF;
}

void Eleicao::ordenaCandidatosPartidos() {
    if (!this->partidos.empty()) {
        for (Partido* aux: this->partidos) {
            aux->ordenaCandidatos();
        }
    }
}

void Eleicao::ordenaPartidos() {
    if (!this->partidos.empty()) {
        sort(this->partidos.begin(), this->partidos.end(), comparaVotosTotais);
    }
}

void Eleicao::ordenaCandidatos() {
    if(!this->candidatos.empty())
        sort(this->candidatos.begin(), this->candidatos.end(), comparaVotos);
}

void Eleicao::ordenaPartidosVotosPrimeiroCandidato() {
    if(!this->partidos.empty()){
        sort(this->partidos.begin(), this->partidos.end(), comparaVotosPartidos);
    }
}

int Eleicao::getCandidatosPorIdade(int limMin, int limMax, time_t data) {
    int idadeCandidatos = 0;

    for(Candidato* c : this->candidatos) {
        int idade = c->calculaIdade(data);
        if (limMin <= idade && idade < limMax && c->ehEleito()) {
            idadeCandidatos++;
        }
    }
    return idadeCandidatos;
}

void Eleicao::liberaInformacoes() {
    for (Partido* p: partidos) {
        delete p;
    }

    for (Candidato* c: candidatos) {
        delete c;
    }
}