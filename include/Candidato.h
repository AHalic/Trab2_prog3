#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <iostream>
#include <string>

#include "../include/Pessoa.h"
#include "../include/Partido.h"

#include <string>

using namespace std;

class Candidato: Pessoa {
    private:
        Partido* partido;
        int id;
        int votosNominais;
        string situacao;
        string nomeUrna;
        string destinoVoto;
    public:
        string getNome() const;
};

#endif