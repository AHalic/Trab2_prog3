/**
 * Pessoa.h
 * Declaração de funções e da classe Pessoa
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 03/05/2021
**/

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
        time_t nascimento;

    public:
        Pessoa(string nome, char genero, time_t nascimento);  

        string getNome() const;
        char getGenero() const;
        time_t getNascimento() const;

        bool ehGeneroF();
        
        void setNome(string nome);
        int calculaIdade(time_t data);
};

ostream& operator << (ostream &os, const Pessoa *p);

#endif