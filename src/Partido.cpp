/**
 * Partido.cpp
 * Definição de metodos da classe Partido
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 05/05/2021
**/

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
    this->votos = Votos(votosLegenda);
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
    return votos.getVotosNominais();
}

int Partido::getVotosLegenda() const {
    return votos.getVotosLegenda();
}

int Partido::getVotosTotais() const {
    return votos.getVotosTotais();
}

int Partido::getQtdVagas() const {
    return vagas;    
}

vector<Candidato*> Partido::getCandidatos() const {
    return candidatos;    
}

void Partido::setVotosNominais(int votos) {
    this->votos.setVotosNominais(votos);
}

void Partido::insereCandidato(Candidato* c) {
    candidatos.insert(candidatos.begin(), c);
    int votosNominais = c->getVotosTotal() + votos.getVotosNominais();
    this->setVotosNominais(votosNominais);

    if(c->ehEleito()) 
        vagas++;
}

bool comparaVotosPartidos(const Partido* p1, const Partido* p2) {
    if(!p1->getCandidatos().empty() && !p2->getCandidatos().empty()) {
        int votos1 = p1->getCandidatos().front()->getVotosTotal();
        int votos2 = p2->getCandidatos().front()->getVotosTotal();

        if (votos1 > votos2) {
            return true;
        }
        else if (votos1 == votos2) {
            if (p1->getCandidatos().front()->getNumero() < p2->getCandidatos().front()->getNumero()) {
                return true;   
            }
        }
        return false;
    }
    else {
        if (!p1->getCandidatos().empty() && p2->getCandidatos().empty()) {
            return true;
        }
        return false;
    }
}

bool comparaVotosTotais(const Partido* p1, const Partido* p2) {
    int votos1 = p1->getVotosTotais();
    int votos2 = p2->getVotosTotais();

    if(votos1 > votos2)
        return true;
    else if(votos1 == votos2)
        if(p1->getNumero() < p2->getNumero())
            return true;
    return false;
}

void Partido::ordenaCandidatos() {
    if(!this->candidatos.empty())
        sort(this->candidatos.begin(), this->candidatos.end(), comparaVotos);
}

void Partido::liberaCandidatos() {
    for (Candidato *c : this->candidatos) {
        if (c != NULL)
            delete c;
    }
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
        