/**
 * Votos.cpp
 * Declaracao de funcoes utilizada para verificacao e validacao 
 * das informacoes.
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 04/05/2021
**/

#include "../include/Verificador.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

bool linhaCandidatoValida (string &numeroIdStr, string &votosNominaisStr, string &situacao, string &nome, string &nomeUrna, string &genero, string &dataNascStr, string &destinoVoto, string &numeroPartidoStr) {
    if (numeroIdStr.empty() || votosNominaisStr.empty() || situacao.empty() || nome.empty() || nomeUrna.empty() ||
        genero.empty() || dataNascStr.empty() || destinoVoto.empty() || numeroPartidoStr.empty()) {
        return false;
    }

    return true;
}

bool linhaPartidoValida (string &numeroPartidoStr, string &votosLegendaStr, string &nome, string &sigla) {
    if (numeroPartidoStr.empty() || votosLegendaStr.empty() || nome.empty() || sigla.empty()) {
        return false;
    }

    return true;
}

bool CandidatoHeaderValido(string &linha) {
    int contador = 0;
    string aux;
    stringstream s(linha);

    while(getline(s, aux, ',')) {
        contador++;
    }

    if(contador == 9)
        return true;
    
    return false;
}

bool PartidoHeaderValido(string &linha) {
    int contador = 0;
    string aux;
    stringstream s(linha);

    while(getline(s, aux, ',')) {
        contador++;
    }

    if(contador == 4)
        return true;
    
    return false;
}

bool ehPositivo(int &valor) {
    if (valor >= 0)
        return true;
    return false;
}

bool generoValido(string &genero) {
    if(!genero.compare("M") || !genero.compare("F"))
        return true;
    return false;
}

bool destinoValida (string &destino) {
    if (!destino.compare("Válido")) {
        return true;
    }
    
    return false;
}