#ifndef LEITURA_H
#define LEITURA_H

#include <iostream>
#include <string>
#include <vector>

#include "../include/Partido.h"
#include "../include/Candidato.h"

using namespace std;

vector<Partido*> lePartidos(string caminho);
vector<Candidato*> leCandidatos(string caminho);

#endif