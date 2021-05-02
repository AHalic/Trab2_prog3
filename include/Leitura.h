#ifndef LEITURA_H
#define LEITURA_H

#include <iostream>
#include <string>

#include "../include/Partido.h"
#include "../include/Candidato.h"

using namespace std;

Partido* lerPartidos(string caminho);
Candidato* lerCandidatos(string caminho);

#endif