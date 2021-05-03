#include "../include/Votos.h"

using namespace std;

Votos::Votos(int votosLegenda) {
    this->votosLegenda = votosLegenda;
    this->votosNominais = 0;
    this->votosTotais = votosLegenda;
}

Votos::Votos() {
    this->votosLegenda = 0;
    this->votosNominais = 0;
    this->votosTotais = 0;
}

int Votos::getVotosLegenda() const {
    return votosLegenda;
}

int Votos::getVotosNominais() const {
    return votosNominais;
}

int Votos::getVotosTotais() const {
    return votosTotais;
}

void Votos::setVotosLegenda(int votos) {
    this->votosLegenda = votos;
    this->votosTotais = this->votosLegenda + this->votosNominais;
}

void Votos::setVotosNominais(int votos) {
    this->votosNominais = votos;
    this->votosTotais = this->votosLegenda + this->votosNominais;
}