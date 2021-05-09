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

#include "Partido.h"
#include "Candidato.h"
#include "DateUtils.h"
#include "ExLeituraCandidato.h"
#include "ExLeituraPartido.h"

using namespace std;

namespace leitura {
    /**
     * Abre o arquivo e adiciona todos os partidos a um vetor. Linha do arquivo com informação 
     * incompleta ou inválida não são utilizadas para criação do partido e consequentemente
     * não adicionados ao vetor de partidos.
     * @param caminho string do caminho do arquivo de partidos.csv
     * @return Vetor de partidos.
     * 
     * @throws runtime_error se nao foi encontrado o arquivo em "caminho"
     * @throws ExLeituraPartido se o arquivo nao possui informacoes 
     *         no formato correto ou se ele estiver vazio
     */
    vector<Partido*> lePartidos(string caminho);

    /**
     * Abre o arquivo e adiciona todos os candidatos a um vetor. Linha do arquivo com informações 
     * incompletas ou inválidas não são criados candidatos referente a informação daquela 
     * linha e não são adicionados ao vetor.
     * @param caminho string do caminho do arquivo de candidato.csv
     * @param partidos - vetor de partidos
     * @return Vetor de candidatos.
     * 
     * @throws runtime_error se nao foi encontrado arquivo em "caminho" 
     * @throws ExLeituraCandidato se o arquivo nao possui informacoes
     *         no formato correto ou se ele estiver vazio
     */
    vector<Candidato*> leCandidatos(string caminho, vector<Partido*> partidos);
}

#endif