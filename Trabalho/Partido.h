/**
 * Partido.cpp
 * Definição de metodos da classe Partido
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 05/05/2021
**/

#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>
#include <string>
#include <vector>

#include "Votos.h"

// declaracao devida as dependencias circulares 
class Candidato;
using namespace std;

/**
 * Esta classe representa o Partido
**/
class Partido {
    private: 
        string nome;
        string sigla;
        int numero;
        Votos votos;
        vector<Candidato*> candidatos;
        int vagas;

    public:

        /**
         * Constructor da classe Partido
         * @param nome nome deste Partido
         * @param sigla sigla deste Partido
         * @param votosLegenda total de votos de legenda para este Partido
         * @param numero número referente a este Partido
         */
        Partido(string& nome, string& sigla, int votosLegenda, int numero);  

        /**
         * Destrutor de Partido
         */
        virtual ~Partido();
        
        /**
         * Retorna o nome deste Partido
         * @return nome
         */
        string getNome() const;

        /**
         * Retorna a sigla deste Partido
         * @return sigla
         */
        string getSigla() const;

        /**
         * Retorna o número deste Partido
         * @return numPartido
         */
        int getNumero() const;

        /**
         * Retorna a quantidade de votos nominais possuidos por este Partido
         * @return votos nominais
         */
        virtual int getVotosNominais() const;

        /**
         * Retorna a quantidade de votos de legenda a este Partido
         * @return votos de legenda
         */
        virtual int getVotosLegenda() const;

        /**
         * Retorna a quantidade total de votos deste PArtido
         * @return votos de Legenda + votos nominais
         */
        virtual int getVotosTotais() const;

        /**
         * Retorna a quantidade de Candidatos 
         * deste Partido que foram eleitos
         * @return vagas
         */
        int getQtdVagas() const;


        vector<Candidato*> getCandidatos() const;
        
        /**
         * Calcula a soma dos votos nominais de todos 
         * Candidatos deste Partido e então
         * muda a quantidade de votos nominais deste
         */
        void setVotosNominais(int votos);

        /**
         * Insere um Candidato na lista de candidatos deste Partido
         * e verifica se esse foi eleito, caso sim incrementa o número de vagas
         * @param candidato ponteiro para candidato que será inserido
         */
        void insereCandidato(Candidato* c);

        /**
         * Ordena a lista de candidatos deste Partido com base na quantidade
         * votos deles, e no caso de empate com base na idade deles
         */
        void ordenaCandidatos();  

};

/**
 * Sobrescrita do operador << para impressao simplificada 
 * das producoes diretamente pelo cout.
 * @relatesalso partido
 * @return formato de partido
 */
ostream& operator << (ostream &os, const Partido *p);

/**
 * Compara a quantidade de votos do primeiro candidato de
 * partido p1 ao do primeiro candidato do partido p2. 
 * Caso os dois tenham a mesma quantidade de votos, compara o 
 * id do primeiro candidato no partido
 * @param c1 ponteiro para partido 
 * @param c2 ponteiro para partido
 * 
 * @return {true} se o partido p1 tem mais votos, {false} caso o contrario
 */
bool comparaVotosPartidos(const Partido* p1, const Partido* p2);

/**
 * Compara a quantidade de votos do partido p1 ao partido p2. 
 * Caso os dois tenham a mesma quantidade de votos, compara o 
 * id do primeiro candidato no partido
 * @param c1 ponteiro para partido 
 * @param c2 ponteiro para partido
 * 
 * @return {true} se o partido p1 tem mais votos, {false} caso o contrario
 */
bool comparaVotosTotais(const Partido* p1, const Partido* p2);

#endif