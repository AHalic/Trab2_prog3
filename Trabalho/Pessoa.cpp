/**
 * Pessoa.cpp
 * Definição de metodos da classe Pessoa
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 03/05/2021
**/

#include "Pessoa.h"
#include <string>
#include <algorithm>

Pessoa::Pessoa(string& nome, char genero, time_t& nascimento) {
    transform(nome.begin(), nome.end(), nome.begin(), ::toupper);
    this->genero = genero;
    this->nascimento = nascimento;
    this->nome = nome;
}

Pessoa::~Pessoa() {}

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

int Pessoa::calculaIdade(time_t& data){
    int anoGregoriaAnoS = 31556952;
    return (((difftime(data, this->nascimento) / anoGregoriaAnoS)));
}