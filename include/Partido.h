#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>
#include <string>
#include <vector>

#include "../include/Candidato.h"
#include "../include/Votos.h"

using namespace std;

class Partido {
    private: 
        int numero;
        Votos votos;
        string sigla;
        vector<Candidato*> candidatos;
        
    public:
        Partido();  
        string getNome() const;
        void setNome(string);
};

#endif