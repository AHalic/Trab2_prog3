#include "../include/Partido.h"

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
    this->candidatos; 
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

vector <Candidato*> Partido::getCandidatos() const {
    return candidatos;    
}

void Partido::setVotosNominais(int votos) {
    this->votos->setVotosNominais(votos);
}

void Partido::insereCandidato(Candidato* c) {
    candidatos.insert(candidatos.begin(), c);
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
    return true;
}

void Partido::ordenaCandidatos() {
    sort(candidatos.begin(), candidatos.end(), comparaVotos);
}
        