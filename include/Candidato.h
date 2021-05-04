#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <iostream>
#include <string>

#include "../include/Pessoa.h"
#include "../include/Partido.h"

#include <string>

class Partido;
using namespace std;

class Candidato: public Pessoa {
    private:
        Partido *partido; // TODO: ver se eh so int
        int numero;
        int votosTotal;
        string situacao;
        string nomeUrna;
        string destinoVoto;
    public:
        Candidato(string nome, char genero, time_t nascimento, string situacao, 
            string nomeUrna, int vT, int numero, string destVoto, Partido *partido);
		
        string getSituacao() const;
        string getNomeUrna() const;
        int getVotosTotal() const;
        int getNumero() const;
        string getDestVoto() const;
        bool comparaNome(const Candidato& c2) const;
        bool ehEleito() const;
        bool ehValido() const;
        Partido getPartido() const;
};

ostream& operator << (ostream &os, const Candidato& c);
bool comparaVotos(const Candidato *c1, const Candidato *c2);

#endif