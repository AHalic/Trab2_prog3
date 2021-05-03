#include "../include/Leitura.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

static Partido* criaPartido(string linha, int contador) {
    stringstream s(linha);
    Partido* partidoAux = NULL;
    string nome, sigla, numeroPartidoStr, votosLegendaStr;
    int numeroPartido, votosLegenda;

    try {
        getline(s, numeroPartidoStr, ',');
        getline(s, votosLegendaStr, ',');
        getline(s, nome, ',');
        getline(s, sigla, ',');

        if (numeroPartidoStr.empty() || votosLegendaStr.empty() || nome.empty() || sigla.empty()) {
            throw runtime_error("Linha não contém todas informações necessárias de um partido!");
        }

    } catch (exception &e) {
        cerr << "Erro ao usar o getline: " << e.what() << endl;
        cerr << "Problema encontrado na linha: " << contador << endl;
        return NULL;
    }
    
    try {
        numeroPartido = stoi(&numeroPartidoStr[0]);
        votosLegenda = stoi(&votosLegendaStr[0]);
    } catch (exception &e){
        cerr << "Erro de parsing de string para int" << endl;
        cerr << "Problema encontrado na linha: " << contador << endl;
        return NULL;
    }

    return partidoAux;
}

vector<Partido*> lePartidos(string caminho) {
    ifstream fin;
    string linhaAux;
    Partido* partidoAux;
    vector<Partido*> partidos;
    int contador = 0;

    try {
        fin.open(caminho, ios::in);     
        if (!fin.is_open()) {
            throw runtime_error("Não foi possível abrir arquivo.");
        }
        
        // ler header
        getline (fin, linhaAux); // TODO: verificar se linhaAux tem informacoes certas

        // verifica se o cabecalho esta vazio 
        if (linhaAux.empty()) {
            throw runtime_error("Arquivo vazio");
        }        

        // ler proximas linhas
        while(getline(fin, linhaAux)) {
            contador++;                                        // contador de partidos
            partidoAux = criaPartido(linhaAux, contador);      // ler linha e cria um partido
            
            if (partidoAux)
                partidos.insert(partidos.begin(), partidoAux); // adiciona partido a vetor caso nao for vazio
        }
    }
    catch (exception &e) {
        cerr << "Problemas com IO: " << e.what() << endl;
    }

    fin.close();
    return partidos;
}

static Candidato* criaCandidato(string linha, int contador) {
    stringstream s(linha);
    Candidato* candidatoAux = NULL;

    string nome, nomeUrna;
    string genero, dataNascStr;
    string numeroIdStr, votosNominaisStr, numeroPartidoStr;
    string situacao, destinoVoto;

    int numeroId, votosNominais, numeroPartido;

    try {
        getline(s, numeroIdStr, ',');
        getline(s, votosNominaisStr, ',');
        getline(s, situacao, ',');
        getline(s, nome, ',');
        getline(s, nomeUrna, ',');
        getline(s, genero, ',');
        getline(s, dataNascStr, ',');
        getline(s, destinoVoto, ',');
        getline(s, numeroPartidoStr, ',');

        if (numeroIdStr.empty() || votosNominaisStr.empty() || situacao.empty() || nome.empty() || nomeUrna.empty() ||
            genero.empty() || dataNascStr.empty() || destinoVoto.empty() || numeroPartidoStr.empty()) {
            throw runtime_error("Linha não contém todas informações necessárias de um candidato!");
        }
        
    } catch (exception &e) {
        cerr << "Erro ao usar o getline: " << e.what() << endl;
        cerr << "Problema encontrado na linha: " << contador << endl;
        return NULL;
    }
    
    try {
        numeroId = stoi(&numeroIdStr[0]);
        numeroPartido = stoi(&numeroPartidoStr[0]);
        votosNominais = stoi(&votosNominaisStr[0]);
    } catch (exception &e){
        cerr << "Erro de parsing de string para int" << endl;
        cerr << "Problema encontrado na linha: " << contador << endl;
        return NULL;
    }

    return candidatoAux;
}

vector<Candidato*> leCandidatos(string caminho) {
    ifstream fin;
    string linhaAux;
    Candidato* candidatoAux;
    vector<Candidato*> candidatos;
    int contador = 0;

    try {
        fin.open(caminho, ios::in);     
        if (!fin.is_open()) {
            cout << "oi" << endl;
            throw runtime_error("Não foi possível abrir arquivo.");
        }
        
        // ler header
        getline (fin, linhaAux); // TODO: verificar se linhaAux tem informacoes certas

        // verifica se o cabecalho esta vazio 
        if (linhaAux.empty()) {
            throw runtime_error("Arquivo vazio");
        }        

        // ler proximas linhas
        while(getline(fin, linhaAux)) {
            contador++;                                        // contador de partidos
            candidatoAux = criaCandidato(linhaAux, contador);      // ler linha e cria um partido
            
            if (candidatoAux)
                candidatos.insert(candidatos.begin(), candidatoAux); // adiciona partido a vetor caso nao for vazio
        }
    }
    catch (exception &e) {
        cerr << "Problemas com IO: " << e.what() << endl;
    }

    fin.close();
    return candidatos;
}
