/**
 * Leitura.h
 * Declaracao de funcoes utilizada para leitura dos arquivos csv. 
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 06/05/2021
**/

#ifndef LEITURA_H
#define LEITURA_H

#include <iostream>
#include <string>
#include <vector>

#include "../include/Partido.h"
#include "../include/Candidato.h"
#include "../include/DateUtils.h"
#include "../include/Excecoes/ExLeituraCandidato.h"
#include "../include/Excecoes/ExLeituraPartido.h"

using namespace std;

namespace leitura {
    /**
     * Abre o arquivo e adiciona todos os partidos a um vetor. Linha do arquivo com informação 
     * incompleta ou inválida não são utilizadas para criação do partido e consequentemente
     * não adicionados ao vetor de partidos.
     * @param caminho string do caminho do arquivo de partidos.csv
     * @return Vetor de partidos.
     */
    vector<Partido*> lePartidos(string caminho);

    /**
     * Abre o arquivo e adiciona todos os candidatos a um vetor. Linha do arquivo com informações 
     * incompletas ou inválidas não são criados candidatos referente a informação daquela 
     * linha e não são adicionados ao vetor.
     * @param caminho string do caminho do arquivo de candidato.csv
     * @param partidos - vetor de partidos
     * @return Vetor de candidatos.
     */
    vector<Candidato*> leCandidatos(string caminho, vector<Partido*> partidos);
}

#endif