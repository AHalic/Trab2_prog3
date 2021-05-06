/**
 * Leitura.cpp
 * Declaracao de funcoes utilizada para leitura dos arquivos csv. 
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 06/05/2021
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
#include "../include/StringUtils.h"
#include "../include/Candidato.h"
#include "../include/Partido.h"

using namespace cpp_util;
using namespace verificador;

namespace leitura {
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
            trim(numeroPartidoStr);
            getline(s, votosLegendaStr, ',');
            trim(votosLegendaStr);
            getline(s, nome, ',');
            trim(nome);
            getline(s, sigla, ',');
            trim(sigla);

            if (!linhaPartidoValida(numeroPartidoStr, votosLegendaStr, nome, sigla))
                throw ExLeituraPartido("Linha não contém todas informações necessárias de um partido!", contador);

        } catch (exception &e) {
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
                throw ExLeituraPartido("Valores negativos!", contador);
        } catch (exception &e) {
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
        int contador = 1;

        try {
            fin.open(caminho, ios::in);     
            if (!fin.is_open()) {
                throw runtime_error("Não foi possível abrir arquivo.");
            }
            
            // ler header
            getline (fin, linhaAux); // TODO: verificar se linhaAux tem informacoes certas

            // verifica se o cabecalho esta vazio 
            if (linhaAux.empty()) {
                throw ExLeituraPartido("Arquivo de partido vazio!");
            }

            // verifica se tem todos os atributos
            if(!PartidoHeaderValido(linhaAux)) {
                throw ExLeituraPartido("Arquivo csv não possui todas as caracteristicas de partido!");
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
            trim(numeroIdStr);
            getline(s, votosNominaisStr, ',');
            trim(votosNominaisStr);
            getline(s, situacao, ',');
            trim(situacao);
            getline(s, nome, ',');
            trim(nome);
            getline(s, nomeUrna, ',');
            trim(nomeUrna);
            getline(s, generoStr, ',');
            trim(generoStr);
            getline(s, dataNascStr, ',');
            trim(dataNascStr);
            getline(s, destinoVoto, ',');
            trim(destinoVoto);
            getline(s, numeroPartidoStr, ',');
            trim(numeroPartidoStr);

            if (!linhaCandidatoValida(numeroIdStr, votosNominaisStr, situacao, nome, nomeUrna, generoStr, dataNascStr, destinoVoto, numeroPartidoStr))
                throw ExLeituraCandidato("Linha não contém todas informações necessárias de um candidato!", contador);
            
            genero = generoStr[0];

        } catch (exception &e) {
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
                throw ExLeituraCandidato("Data de nascimendo inválida.", contador);
            }
            dataNasc = parseDate(dataNascStr);
        } catch (exception &e) {
            return NULL;
        }

        try {
            if (!ehPositivo(numeroId) || !ehPositivo(numeroPartido) || !ehPositivo(votosNominais))
                throw ExLeituraCandidato("Valores negativos!", contador);
            if (!generoValido(generoStr))
                throw ExLeituraCandidato("Gênero não reconhecido!", contador);
        } catch (exception &e) {
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
                throw ExLeituraCandidato("Não foi encontrado o partido no vetor de partidos!", contador);

        } catch (exception &e) {
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
        int contador = 1;

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
                throw ExLeituraCandidato("Arquivo de candidato vazio!");
            }        

            // verifica se tem todos atributos
            if(!CandidatoHeaderValido(linhaAux)) {
                throw ExLeituraCandidato("Arquivo csv não possui todas as caracteristicas de candidato.");
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
        }

        fin.close();
        return candidatos;
    }
}