/**
 * Verificador.h
 * Declaracao de funcoes utilizada para verificacao e validacao 
 * das informacoes.
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 06/05/2021
**/

#ifndef VERIFICADOR_H
#define VERIFICADOR_H

#include <string>

using namespace std;

namespace verificador {

    /**
     * Verifica se todas as informacoes lidas da linha do csv  de candidato 
     * sao validas (string nao vazia).
     * @param numeroIdStr string referente ao numero do candidato
     * @param votosNominaisStr string referente a quantidade de votos nominais
     * @param situacao string referente a situacao do candidato
     * @param nome string referente ao nome do candidato
     * @param nomeUrna string referente ao nome de urna do candidato
     * @param genero string referente ao genero do candidato
     * @param dataNascStr string referente a data de nascimento do candidato
     * @param destinoVoto string referente a situacao do destino dos votos do candidato
     * @param numeroPartidStr string referente a numero de partido ao qual o candidato pertence
     * 
     * @return {true} se valido, {false} caso contrario
     */ 
    bool linhaCandidatoValida (string &numeroIdStr, string &votosNominaisStr, string &situacao, string &nome, string &nomeUrna, string &genero, string &dataNascStr, string &destinoVoto, string &numeroPartidoStr);

    /**
     * Verifica se todas as informacoes lidas da linha do csv de partido  
     * sao validas (string nao vazia).
     * @param numeroPartidoStr string referente ao numero do partido
     * @param votosLegendaStr string referente a quantidade de votos de legenda
     * @param nome string referente ao nome do partido
     * @param sigla string referente a sigla do partido
     * 
     * @return {true} se valido, {false} caso contrario
     */ 
    bool linhaPartidoValida (string &numeroPartidoStr, string &votosLegendaStr, string &nome, string &sigla);

    /**
     * Verifica se a quantidade das informacoes lidas do header do csv de candidato   
     * eh igual a 9.
     * @param sigla string referente ao header do arquivo candidato.csv
     * 
     * @return {true} se valido, {false} caso contrario
     */ 
    bool CandidatoHeaderValido(string &linha);

    /**
     * Verifica se a quantidade das informacoes lidas do header do csv de partido   
     * eh igual a 4.
     * @param sigla string referente ao header do arquivo arquivo.csv
     * 
     * @return {true} se valido, {false} caso contrario
     */ 
    bool PartidoHeaderValido(string &linha);

    /**
     * Verifica se o valor eh positivo.
     * @param valor valor inteiro
     * 
     * @return {true} se valido, {false} caso contrario
     */
    bool ehPositivo(int &valor);

    /**
     * Verifica se o genero eh F ou M.
     * @param genero string referente ao genero
     * 
     * @return {true} se valido, {false} caso contrario
     */
    bool generoValido(string &genero);

    /**
     * Verifica se o valor de destino eh igual a "Válido" 
     * @param genero string referente ao genero
     * 
     * @return {true} se valido, {false} caso contrario
     */
    bool destinoValida (string &destino);
}

#endif