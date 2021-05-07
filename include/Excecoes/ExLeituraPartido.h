/**
 * ExLeituraPartido.h
 * Definição de metodos da classe ExLeituraPartido.
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
 * ocorridos durante a leitura de partidos.
**/
class ExLeituraPartido : public exception{
    private:
        string _msg;
        int _linha;

    public:

    ExLeituraPartido(const string &msg);
    ExLeituraPartido(const string &msg, const int &linha);
    ~ExLeituraPartido();
    
    virtual const char* what() const throw();
};
