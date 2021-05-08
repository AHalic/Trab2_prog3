/**
 * Votos.cpp
 * Definição de metodos da classe Votos
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 03/05/2021
**/

#include "Votos.h"

Votos::Votos(int votosLegenda) {
    this->votosLegenda = votosLegenda;
    this->votosNominais = 0;
    this->votosTotais = votosLegenda;
}

Votos::Votos(int votosLegenda, int votosNominais) {
    this->votosLegenda = votosLegenda;
    this->votosNominais = votosNominais;
    this->votosTotais = votosLegenda + votosNominais;
}

Votos::Votos() {
    this->votosLegenda = 0;
    this->votosNominais = 0;
    this->votosTotais = 0;
}

// Votos::~Votos() {}

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