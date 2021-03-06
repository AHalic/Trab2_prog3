/**
 * ExLeituraPartido.cpp
 * Definição de metodos da classe ExLeituraPartido.
 * Classe representa uma excecao.
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 06/05/2021
**/

#include <iostream>
#include <string>

#include "ExLeituraPartido.h"

using namespace std;
  
ExLeituraPartido::ExLeituraPartido(const string &msg) : _msg(msg) {
    this->_msg = "Erro encontrado na leitura de partidos!\n" + msg;
    this->_linha = -1;
}

ExLeituraPartido::ExLeituraPartido(const string &msg, const int &linha) : _msg(msg) {
    this->_msg = "Erro encontrado na leitura de partidos!\n" + msg;
    this->_linha = linha;
}

ExLeituraPartido::~ExLeituraPartido() noexcept {}

const char * ExLeituraPartido::what() const noexcept {
    string out = _msg;
    
    if (_linha > -1) {
        out += "\nProblema na linha: " + to_string(this->_linha);
    }

    return out.c_str();
}
