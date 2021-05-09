/**
 * Relatorio.h
 * Declaracao de funcoes e da classe Eleicao
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 04/05/2021
**/

#ifndef ELEICAO_H
#define ELEICAO_H

#include "Eleicao.h"

#include <string>
#include <iostream>
#include <ctime>
#include <vector>

#include "Partido.h"
#include "Candidato.h"

using namespace std;

/**
 * Esta classe representa a Eleicao
 */
class Eleicao {
    private:
        time_t dataEleicao;
        Votos votos;
        int vagas;
        vector<Partido*> partidos;
        vector<Candidato*> candidatos;

        void setVotosTotais();

    public:
        /**
         * Constructor da classe Eleicao
         * @param dataEleicao data em que esta eleição foi realizada
         * @param candidatos lista de candidatos participando desta eleição
         * @param partidos lista de partidos presentes nesta eleição
         */
        Eleicao(time_t& dataEleicao, vector<Partido*> partidos, vector<Candidato*> candidatos);
        void liberaInformacoes();

        /**
         * Retorna a data em que a eleição foi realizada
         * @return data da eleição
         */  
        time_t getDataEleicao() const;

        /**
         * Retorna a quantidade de votos nominais 
         * obtidas nesta eleição
         * @return votos nominais
         */
        virtual int getVotosNominais() const;

        /**
         * Retorna a quantidade de votos de legenda
         * obtidos nesta eleição
         * @return votos de legenda
         */        
        virtual int getVotosLegenda() const;

        /**
         * Retorna a quantidade de votos totais
         * obtidas nesta eleição
         * @return votos totais
         */
        virtual int getVotosTotais() const;

        /**
         * Retorna a quantidade de candidatos eleitos nesta eleição
         * @return vagas desta eleição
         */
        int getVagas() const;

        /**
         * Retorna o vetor de candidatos desta Eleição
         * @return vetor de candidatos
         */
        vector<Candidato*> getCandidatos() const;

        /**
         * Retorna o vetor de partido desta Eleição
         * @return vetor de partidos
         */
        vector<Partido*> getPartidos() const;

        /**
         * Calcula a quantidade de candidatos nesta eleição
         * de genero feminino
         * @return quantidade de F
         */
        int getFEleitas() const;

        /**  
         * Retorna a quantidade de candidatos com idade em um intervalo definido
         * @param limMin menor idade do intervalo
         * @param limMax maior idade do intervalo
         * @param data data para calculo da idade
         * @return quantidade de candidatos no intervalo
        **/
        int getCandidatosPorIdade(int limMin, int limMax, time_t data);

        /**
         * Calcula a quantidade de candidatos eleitos
         * e modifica a quantidade de vagas desta Eleição
         */
        void setQtdVagas();

        /**
         * Ordena o vetor de candidatos de cada partido 
         * do vetor de partidos desta Eleição
        **/
        void ordenaCandidatosPartidos();

        /**
         * Ordena o vetor de partidos desta Eleição com base na quantidade
         * total de votos dos partidos, no caso de empate com base no numero deles
         */
        void ordenaPartidos();

        /**
         * Ordena o vetor de candidatos desta Eleição com base na quantidade
         * votos deles, e no caso de empate com base na idade deles
         */
        void ordenaCandidatos();

        /**
         * Ordena o vetor de partidos desta Eleição com base na quatidade de 
         * votos do primeiro candidato de cada partido, e no caso de empate
         * com base no numero do candidato
         */
        void ordenaPartidosVotosPrimeiroCandidato();
};

#endif

