#ifndef LEITURA_H
#define LEITURA_H

#include <iostream>
#include <string>
#include <vector>

#include "../include/Partido.h"
#include "../include/Candidato.h"
#include "../include/DateUtils.h"

using namespace std;
class Partido;

vector<Partido*> lePartidos(string caminho);
vector<Candidato*> leCandidatos(string caminho, vector<Partido*> partidos);

#endif