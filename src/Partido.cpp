#include "../include/Partido.h"

#include <iostream>
#include <algorithm>
#include <string>

#include "../include/Votos.h"
#include "../include/Candidato.h"

using namespace std;

Partido::Partido(string nome, string sigla, int votosLegenda, int numero) {
    this->nome = nome;
    this->sigla = sigla;
    this->votos = new Votos(votosLegenda);
    this->numero = numero;
    this->vagas = 0;
}

string Partido::getNome() const {
    return nome;
}

string Partido::getSigla() const {
    return sigla;
}

int Partido::getNumero() const {
    return numero;
}

int Partido::getVotosNominais() const {
    return votos->getVotosNominais();
}

int Partido::getVotosLegenda() const {
    return votos->getVotosLegenda();
}

int Partido::getVotosTotais() const {
    return votos->getVotosTotais();
}

int Partido::getQtdVagas() const {
    return vagas;    
}

vector<Candidato*> Partido::getCandidatos() const {
    return candidatos;    
}

void Partido::setVotosNominais(int votos) {
    this->votos->setVotosNominais(votos);
}

void Partido::insereCandidato(Candidato* c) {
    candidatos.insert(candidatos.begin(), c);
    int votosNominais = c->getVotosTotal() + votos->getVotosNominais();    
    this->setVotosNominais(votosNominais);

    if(c->ehEleito()) 
        vagas++;
}


string Partido::toString() const{
    string fraseCandidatoEleito = " candidato eleito";
    string fraseVoto = " voto";
    string fraseNominal = " nominal";

    if (this->getQtdVagas() > 1) 
        fraseCandidatoEleito = " candidatos eleitos";

    if (this->votos->getVotosTotais() > 1)
        fraseVoto = " votos";

    if (this->votos->getVotosNominais() > 1)
        fraseNominal = " nominais";

	string out = this->sigla + " - " + to_string(this->numero) + ", " + to_string(this->votos->getVotosTotais()) + 
                 fraseVoto + " (" + to_string(this->votos->getVotosNominais()) + fraseNominal + " e " + 
                 to_string(this->votos->getVotosLegenda()) + " de legenda), " + to_string(this->vagas) + fraseCandidatoEleito;

    return out;
}

bool Partido::comparaVotos(Candidato* c1, Candidato* c2) {
    int votos1 = c1->getVotosTotal();
    int votos2 = c2->getVotosTotal();

    if (votos1 > votos2) 
        return -1;
    else if (votos1 == votos2) {
        if (c1->getNascimento() < c2->getNascimento())
            return -1;
    }
    return 1;
}

void Partido::ordenaCandidatos() {
    sort(this->candidatos.begin(), this->candidatos.end(), comparaVotos);
}

ostream& operator << (ostream &os, const Partido* p) {
    string fraseCandidatoEleito = " candidato eleito";
    string fraseVoto = " voto";
    string fraseNominal = " nominal";

    if (p->getQtdVagas() > 1) 
        fraseCandidatoEleito = " candidatos eleitos";

    if (p->getVotosTotais() > 1)
        fraseVoto = " votos";

    if (p->getVotosNominais() > 1)
        fraseNominal = " nominais";

	return (os << p->getSigla() << " - " << to_string(p->getNumero()) << ", " << to_string(p->getVotosTotais()) << 
                 fraseVoto << " (" << to_string(p->getVotosNominais()) << fraseNominal << " e " << 
                 to_string(p->getVotosLegenda()) << " de legenda), " << to_string(p->getQtdVagas()) << fraseCandidatoEleito);

}
        