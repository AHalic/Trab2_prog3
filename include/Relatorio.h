#ifndef RELATORIO_H
#define RELATORIO_H

#include <string>

#include "../include/Eleicao.h"
#include "../include/Candidato.h"
#include "../include/Partido.h"

using namespace std;

void mostraNumeroVagas(Eleicao eleicao);

void mostraVereadoresEleitos(Eleicao eleicao);

void mostraCandidatosMaisVotados(Eleicao eleicao);

int mostraNaoEleitoMajoritario(Eleicao eleicao);

void mostraEleitosBeneficiados(Eleicao eleicao, int nEleitos);

void mostraInfoPartido(Eleicao eleicao);

void mostraPrimeiroUltimoPartido(Eleicao eleicao);

void mostraEleitosPorIdade(Eleicao eleicao);

void mostraeleitosPorGenero(Eleicao eleicao);

void mostraVotosEleicao(Eleicao eleicao);

#endif
