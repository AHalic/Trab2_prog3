#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Pessoa {
    private: 
        string nome;
        char genero;
        time_t aniversario;

    public:
        Pessoa();  
        string getNome() const;
        void setNome(string);
        int calculaIdade(time_t data);
};

#endif