/**
 * Relatorio.h
 * Declaracao de funcoes utilizada para mostra dos relatorios. 
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 04/05/2021
**/

#ifndef RELATORIO_H
#define RELATORIO_H

#include <string>

#include "../include/Eleicao.h"
#include "../include/Candidato.h"
#include "../include/Partido.h"

using namespace std;

/**
 * Relatorio 1 
 * - 
 * Mostra no terminal a quantidade de vagas na eleicao.
 * @param eleicao eleicao com todas informacoes importantes 
 */
void mostraNumeroVagas(Eleicao &eleicao);

/**
 * Relatorio 2 
 *  - 
 * Mostra os vereadores eleitos.
 * @param eleicao eleicao com todas informacoes importantes
 */
void mostraVereadoresEleitos(Eleicao &eleicao);

/**
 * Relatorio 3 
 * -
 * Mostra os candidatos mais votados dentro da quantidade de vagas.
 * @param eleicao eleicao com todas informacoes importantes
 */
void mostraCandidatosMaisVotados(Eleicao &eleicao);

/**
 * Relatorio 4 
 *  - 
 * Mostra quais candidatos que dentro do limite de vagas nao foram eleitos. Caso a votacao
 * fosse majoritaria, eles seriam eleitos. 
 * @param eleicao eleicao com todas informacoes importantes
 * 
 * @return Numero de pessoas eleitas dentro dos votos majoritarios.
 */
int mostraNaoEleitoMajoritario(Eleicao &eleicao);

/**
 * Relatorio 5 
 *  - 
 * Mostra quais candidatos eleitos se beneficiaram do sistema proporcional.
 * @param eleicao eleicao com todas informacoes importantes
 * @param {nEleitos} quantidade de pessoas eleitas dentro dos votos majoritarios
 */
void mostraEleitosBeneficiados(Eleicao &eleicao, int nEleitos);

/**
* Relatorio 6 
*  - 
* Mostra informacao de cada partido. Votacao e o numero de candidatos eleitos.
* @param eleicao eleicao com todas informacoes importantes
*/
void mostraInfoPartido(Eleicao &eleicao);

/**
 * Relatorio 7 
 * - 
 * Mostra primeiro e ultimo colocados de cada partido, ordenado por votos.
 * @param eleicao eleicao com todas informacoes importantes
 */
void mostraPrimeiroUltimoPartido(Eleicao &eleicao);

/**
 * Relatorio 8 
 * - 
 * Mostra a quantidade de eleitos dentro dos seguintes limites de idade: 
 * 
 * | 0 <= idade < 30  | e 
 * | 30 <= idade < 40 | e 
 * | 40 <= idade < 50 | e 
 * | 50 <= idade < 60 | e 
 * | 60 <= idade <    |.
 * 
 * @param eleicao eleicao com todas informacoes importantes
 */
void mostraEleitosPorIdade(Eleicao &eleicao);

/**
 * Relatorio 9 
 * - 
 * Mostra a quantidade eleitos por genero (apenas feminino e masculino).
 * @param eleicao eleicao com todas informacoes importantes
*/
void mostraeleitosPorGenero(Eleicao &eleicao);

/**
 * Relatorio 10 
 *  - 
 * Mostra a quantidade de votos validos, nominais e de legenda
 * @param eleicao eleicao com todas informacoes importantes
 */
void mostraVotosEleicao(Eleicao &eleicao);

#endif
