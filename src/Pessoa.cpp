/**
 * Pessoa.cpp
 * Definição de funções da classe Pessoa
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 03/05/2021
**/

#include "../include/Pessoa.h"
#include <string>


Pessoa::Pessoa(string nome, char genero, time_t nascimento) {
    this->genero = genero;
    this->nascimento = nascimento;
    
    for (int i = 0; i < nome.length(); i++) {
        nome[i] = toupper(nome[i]);
    }
    this->nome = nome;
}

string Pessoa::getNome() const {
    return this->nome;
}

char Pessoa::getGenero() const {
    return this->genero;
}
time_t Pessoa::getNascimento() const {
    return this->nascimento;
}

bool Pessoa::ehGeneroF() {
    if (this->genero == 'F') {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator << (ostream &os, const Pessoa *p) {
    return (os << p->getNome());
}

int Pessoa::calculaIdade(time_t data){
    return (((difftime(data, this->nascimento) + 86400L/2) / 86400L) / 365);
}