/**
 * ExLeituraCandidato.h
 * Definição de metodos da classe ExLeituraCandidato.
 * Classe representa uma excecao.
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 06/05/2021
**/

#include <iostream>
#include <string>

using namespace std;

/**
 * Esta classe herda exception e eh referente aos erros 
 * ocorridos durante a leitura de candidatos.
**/
class ExLeituraCandidato : public exception{
    private:
        string _msg;
        int _linha;

    public:

    ExLeituraCandidato(const string &msg);
    ExLeituraCandidato(const string &msg, const int &linha);
    ExLeituraCandidato();
    
    virtual const char* what() const throw();
};
