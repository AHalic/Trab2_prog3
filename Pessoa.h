/**
 * Pessoa.h
 * Declaracao de funcoes e da classe Pessoa
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 03/05/2021
**/

#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/**
 * Esta classe representa uma Pessoa
**/
class Pessoa {
    private: 
        string nome;
        char genero;
        time_t nascimento;

    public:
    	
        /**
         * Constructor da classe Pessoa
         * @param nome nome desta Pessoa
         * @param genero pode ser F ou M
         * @param nascimento data de nascimento desta Pessoa 
         */
        Pessoa(string& nome, char genero, time_t& nascimento);  

        /**
         * Retorna o nome desta Pessoa
         * @return nome
         */   
        string getNome() const;

        /**
         * Retorna o genero desta Pessoa
         * @return genero
         */       
        char getGenero() const;

        /**
         * Retorna o nascimento desta Pessoa
         * @return nascimento
         */
        time_t getNascimento() const;
	
        /**
         * Verifica se o genero desta Pessoa é F 
         * @return {@code true} se sim, {@code false} se não
         */
        bool ehGeneroF();
        
        /**
         * Retorna a idade desta Pessoa com base em uma data
         * @param data data para cálculo da idade
         * @return idade 
         */
        int calculaIdade(time_t& data);

        // virtual ~Pessoa();
};

/**
 * Sobrescrita do operador << para impressao simplificada 
 * das producoes diretamente pelo cout.
 * @relatesalso Pessoa
 * @return nome desta Pessoa em maiúsculo
 */
ostream& operator << (ostream &os, const Pessoa *p);

#endif