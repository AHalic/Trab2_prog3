/**
 * Leitura.cpp
 * Declaracao de funcoes utilizada para leitura dos arquivos csv. 
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 03/05/2021
**/

#include "../include/Leitura.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>

#include "../include/Verificador.h"
#include "../include/DateUtils.h"
#include "../include/Candidato.h"
#include "../include/Partido.h"

using namespace cpp_util;

/**
 * Faz leitura e parsing da linha com informacoes do partido. Se alguma informação lida não eh 
 * valida o partido nao eh criado e a funcao retorna null.
 * @param linha string de linha de partido.csv com informacao de partido
 * @param contador numero da linha lida do csv
 * @return Partido construido ou null.
 */
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

        if (!linhaPartidoValida(numeroPartidoStr, votosLegendaStr, nome, sigla))
            throw runtime_error("Linha não contém todas informações necessárias de um partido!");

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
    
    try {
        if (!ehPositivo(numeroPartido) || !ehPositivo(votosLegenda))
            throw runtime_error("Valores negativos!");
    } catch (exception &e) {
        cerr << e.what() << endl;
        cerr << "Problema encontrado na linha: " << contador << endl;
        return NULL;
    }

    partidoAux = new Partido(nome, sigla, votosLegenda, numeroPartido);

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

        // verifica se tem todos os atributos
        if(!PartidoHeaderValido(linhaAux)) {
            throw runtime_error("Arquivo csv não possui todas as caracteristicas de partido.");
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

/**
 * Faz leitura e parsing da linha com informacoes do candidato. Se alguma informação lida não eh 
 * valida o candidato nao eh criado e a funcao retorna null. 
 * @param linha string de linha de candidato.csv com informacao de candidato
 * @param contador numero da linha lida no csv
 * @param partidos vetor de partidos existentes
 * @return Candidato com as informações preenchida ou null.
 */
static Candidato* criaCandidato(string linha, int contador, vector<Partido*> partidos) {
    stringstream s(linha);

    string nome, nomeUrna;
    string generoStr, dataNascStr;
    string numeroIdStr, votosNominaisStr, numeroPartidoStr;
    string situacao, destinoVoto;

    Partido* partidoAux = NULL;
    int numeroId, votosNominais, numeroPartido;
    time_t dataNasc;
    char genero;

    try {
        getline(s, numeroIdStr, ',');
        getline(s, votosNominaisStr, ',');
        getline(s, situacao, ',');
        getline(s, nome, ',');
        getline(s, nomeUrna, ',');
        getline(s, generoStr, ',');
        getline(s, dataNascStr, ',');
        getline(s, destinoVoto, ',');
        getline(s, numeroPartidoStr, ',');

        if (!linhaCandidatoValida(numeroIdStr, votosNominaisStr, situacao, nome, nomeUrna, generoStr, dataNascStr, destinoVoto, numeroPartidoStr))
            throw runtime_error("Linha não contém todas informações necessárias de um candidato!");
        
        genero = generoStr[0];
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

    try {
        if (!validDate(dataNascStr)) {
            throw logic_error("Data de nascimendo inválida.");
        }

        dataNasc = parseDate(dataNascStr);
    } catch (exception &e) {
        cerr << e.what() << endl;
        cerr << "Problema encontrado na linha: " << contador << endl;
        return NULL;
    }

    try {
        if (!ehPositivo(numeroId) || !ehPositivo(numeroPartido) || !ehPositivo(votosNominais))
            throw logic_error("Valores negativos!");
        if (!generoValido(generoStr))
            throw logic_error("Gênero não reconhecido!");
    } catch (exception &e) {
        cerr << e.what() << endl;
        cerr << "Problema encontrado na linha: " << contador << endl;
        return NULL;
    }

    try {
        for (Partido* p: partidos) {
            if (p->getNumero() == numeroPartido) {
                partidoAux = p;
                break;
            }
        }

        if(!partidoAux)
            throw("Não foi encontrado o partido no vetor de partidos!");

    } catch (exception &e) {
        cerr << e.what() << endl;
        cerr << "Problema encontrado na linha: " << contador << endl;
        return NULL;
    }

    Candidato* candidatoAux = NULL;
    if (destinoValida(destinoVoto)) {
        candidatoAux = new Candidato(nome, genero, dataNasc, situacao, nomeUrna, votosNominais, numeroId, destinoVoto, partidoAux);
        partidoAux->insereCandidato(candidatoAux);
    }

    return candidatoAux;
}

vector<Candidato*> leCandidatos(string caminho, vector<Partido*> partidos) {
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

        // verifica se tem todos atributos
        if(!CandidatoHeaderValido(linhaAux)) {
            throw runtime_error("Arquivo csv não possui todas as caracteristicas de candidato.");
        }

        // ler proximas linhas
        while(getline(fin, linhaAux)) {
            contador++;                                        // contador de partidos
            candidatoAux = criaCandidato(linhaAux, contador, partidos);      // ler linha e cria um partido
            
            if (candidatoAux)
                candidatos.insert(candidatos.begin(), candidatoAux); // adiciona partido a vetor caso nao for vazio
        }
    }
    catch (exception &e) {
        cerr << "Exceção encontrada! " << e.what() << endl;
    }

    fin.close();
    return candidatos;
}
