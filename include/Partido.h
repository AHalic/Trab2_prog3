#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>
#include <string>

#include "../include/Candidato.h"

using namespace std;

class Partido {
    private: 
        int numero;

        string sigla;
        vector<Candidato*> candidatos;
        
    public:
        Pessoa();  
        string getNome() const;
        void setNome(string);
};

#endif