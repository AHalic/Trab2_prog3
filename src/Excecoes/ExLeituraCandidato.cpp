/**
 * ExLeituraCandidato.cpp
 * Definição de metodos da classe ExLeituraCandidato.
 * Classe representa uma excecao.
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 06/05/2021
**/

#include <iostream>
#include <string>

#include "../../include/Excecoes/ExLeituraCandidato.h"

using namespace std;
  
ExLeituraCandidato::ExLeituraCandidato(const string &msg) : _msg(msg) {
    this->_msg = "Erro encontrado na leitura de candidatos!\n" + msg;
    this->_linha = -1;
}

ExLeituraCandidato::ExLeituraCandidato(const string &msg, const int &linha) : _msg(msg) {
    this->_msg = "Erro encontrado na leitura de candidatos!\n" + msg;
    this->_linha = linha;
}

ExLeituraCandidato::~ExLeituraCandidato() {
    this->_msg = "Erro encontrado na leitura de candidatos!";
    this->_linha = -1;
}

const char * ExLeituraCandidato::what() const throw () {
    string out = _msg;
    
    if (_linha > -1) {
        out += "\nProblema na linha: " + to_string(this->_linha);
    }

    return out.c_str();
}
