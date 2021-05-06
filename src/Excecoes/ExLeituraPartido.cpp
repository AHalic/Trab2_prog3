#include <iostream>
#include <string>

#include "../../include/Excecoes/ExLeituraPartido.h"

using namespace std;
  
ExLeituraPartido::ExLeituraPartido(const string &msg) : _msg(msg) {
    this->_msg = "Erro encontrado na leitura de partidos!\n" + msg;
    this->_linha = -1;
}

ExLeituraPartido::ExLeituraPartido(const string &msg, const int &linha) : _msg(msg) {
    this->_msg = "Erro encontrado na leitura de partidos!\n" + msg;
    this->_linha = linha;
}

ExLeituraPartido::ExLeituraPartido() {
    this->_msg = "Erro encontrado na leitura de partidos!";
    this->_linha = -1;
}

const char * ExLeituraPartido::what() const throw () {
    string out = _msg;
    
    if (_linha > -1) {
        out += "\nProblema na linha: " + to_string(this->_linha);
    }

    return out.c_str();
}
