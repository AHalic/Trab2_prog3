#include "../include/Candidato.h"

#include <string>
#include <iostream>

#include "../include/Partido.h"

using namespace std;

Candidato::Candidato(string nome, char genero, time_t nascimento, string situacao, 
                    string nomeUrna, int vT, int numero, string destVoto, Partido* partido) 
                    : Pessoa(nome, genero, nascimento) {
    
    this->situacao = situacao;
    this->nomeUrna = nomeUrna;
    this->numero = numero;
    this->partido = partido;
    this->destinoVoto = destVoto;
    this->votosTotal = vT;
}

string Candidato::getSituacao() const {
    return this->situacao;
}

string Candidato::getNomeUrna() const {
    return this->nomeUrna;
}

int Candidato::getVotosTotal() const {
    return this->votosTotal;
}

int Candidato::getNumero() const {
    return this->numero;
}

string Candidato::getDestVoto() const {
    return this->destinoVoto;
}

bool Candidato::comparaNome(Candidato* c2) const {
    return (this->getNome() == c2->getNome());
}

bool Candidato::ehEleito() const {
    return (this->situacao == "Eleito");
}

bool Candidato::ehValido() const {
    return (this->destinoVoto == "Válido");
}

Partido* Candidato::getPartido() const{
    return this->partido;
}

ostream& operator << (ostream &os, const Candidato *c) {
    return (os << c->getNome() + " / " + c->getNomeUrna() + " (" + c->getPartido()->getSigla() + ", " + to_string(c->getVotosTotal()) + "votos)");
}
