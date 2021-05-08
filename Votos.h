/**
 * Votos.h
 * Declaracao de funções e da classe Voto
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 03/05/2021
**/

#ifndef VOTOS_H
#define VOTOS_H

#include <iostream>
using namespace std;

/**
 * Esta classe representa os tipos de votos numa eleicao. Englobando 
 * votos nominais, votos de legenda e a soma dos dois.
 */
class Votos {
    private:
        int votosNominais;
        int votosLegenda;
        int votosTotais;

    public:
        /**
         * Constructor da classe Votos. Inicializa apenas com 
         * votos de legenda. Votos nominais eh atribuido 0.
         * @param votosLegenda quantidade de votos de legenda
         */
        Votos(int votosLegenda);

        /**
         * Constructor da classe Votos. Inicializa com votos 
         * de legenda e nominais.
         * @param votosLegenda quantidade de votos de legenda
         * @param votosNominais quantidade de votos nominais
         */
        Votos(int votosLegenda, int votosNominais);

        /**
         * Constructor da classe Votos. Inicializa com votos 
         * de legenda e nominais zerado.
         */
        Votos();

        /**
         * Retorna a quantidade de votos de legenda. 
         * @return quantidade de votos de legenda.
         */
        int getVotosLegenda() const;

        /**
         * Retorna a quantidade de votos nominais. 
         * @return quantidade de votos nominais.
         */
        int getVotosNominais() const;

        /**
         * Retorna a quantidade de votos totais. 
         * @return quantidade de votos totais.
         */
        int getVotosTotais() const;

        /**
         * Modifica a quantidade de votos de legenda. 
         * @param votos nova quantidade de votos de legenda
         */
        void setVotosLegenda(int votos);

        /**
         * Modifica a quantidade de votos nominais. 
         * @param votos nova quantidade de votos nominais
         */
        void setVotosNominais(int votos);
};

#endif