#ifndef VERIFICADOR_H
#define VERIFICADOR_H

#include <string>

using namespace std;

bool linhaCandidatoValida (string &numeroIdStr, string &votosNominaisStr, string &situacao, string &nome, string &nomeUrna, string &genero, string &dataNascStr, string &destinoVoto, string &numeroPartidoStr);
bool linhaPartidoValida (string &numeroPartidoStr, string &votosLegendaStr, string &nome, string &sigla);
bool CandidatoHeaderValido(string &linha);
bool PartidoHeaderValido(string &linha);
bool ehPositivo(int &valor);
bool generoValido(string &genero);
bool destinoValida (string &destino);


#endif