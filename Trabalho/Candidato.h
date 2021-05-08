/**
 * Candidato.h
 * Definição de metodos da classe Candidato e funcoes 
 * referente 
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 03/05/2021
**/

#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <iostream>
#include <string>

#include "Pessoa.h"
#include "Partido.h"

#include <string>

class Partido;
using namespace std;

/**
 * Esta classe representa o Candidato, que herda os atributos de Pessoa
**/
class Candidato: public Pessoa {
    private:
        Partido *partido; 
        int numero;
        int votosTotal;
        string situacao;
        string nomeUrna;
        string destinoVoto;

    public:

        /**
         * Constructor da classe Candidato
         * @param nome nome desta Pessoa
         * @param genero pode ser F ou M
         * @param nascimento data de nascimento desta Pessoa 
         * @param situacao situacao do candidato (se ele eh eleito, suplente ou nao eleito)
         * @param nomeUrna nome do candidato de urna
         * @param vT votos do candidato
         * @param numero numero de id do candidato
         * @param destVoto destino do votos do candidato 
         * @param partido ponteiro ao partido a qual o candidato pertence
         */
        Candidato(string& nome, char genero, time_t& nascimento, string& situacao, 
            string& nomeUrna, int vT, int numero, string& destVoto, Partido *partido);
        
        /**
         * Destrutor de Candidato
         */
        // virtual ~Candidato();

        /** 
         * Retorna a situacao do candidato.
         * @return Situacao (Eleito, Suplente ou Não Eleito)
         */	
        string getSituacao() const;

        /**
         * Retorna o nome de urna do candidato.
         * @return Nome de urna
         */
        string getNomeUrna() const;

        /**
         * Retorna a quantidade de votos que o candidato obteve
         * @return Votos totais
         */
        int getVotosTotal() const;

        /**
         * Retorna o numero (id) do candidato
         * @return Numero do candidato
         */
        int getNumero() const;

        /**
         * Retorna a situacao do destino dos votos do candidato
         * @return String do destino do voto
         */
        string getDestVoto() const;

        /**
         * Retorna o partido do candidato
         * @return Partido
         */ 
        Partido getPartido() const;

        /**
         * Recebe um candidato e compara o nome dele ao do candidato da classe
         * @param c2 - Candidato que será usado para comparar nomes
         * @return {true} se os candidatos possuem o mesmo nome, {false} caso contrario
         */
        bool comparaNome(const Candidato& c2) const;

        /** 
         * Retorna se o candidato foi eleitos
         * @return {true} se eleito, {false} se nao
         */
        bool ehEleito() const;

        /** 
         * Retorna se o destino do candidato eh valido
         * @return {true} se Válido, {false} se nao
        */
        bool ehValido() const;

        /**
         * Representação de string mais curta do objeto na forma:
         * Layout: "Nome na urna (numero, votosTotais votos)"
         * @return Representação em String (curta).
         */
        string toString() const;


};

/**
 * Sobrescrita do operador << para impressao simplificada 
 * das producoes diretamente pelo cout.
 * @relatesalso Candidato
 * @return formato de candidato
 */
ostream& operator << (ostream &os, const Candidato *c);

/**
 * Compara a quantidade de votos do candidato c1 ao candidato c2. 
 * Caso os dois tenham a mesma quantidade de votos, compara a 
 * data de nascimento.
 * @param c1 ponteiro para candidato 
 * @param c2 ponteiro para candidato
 * 
 * @return {true} se candidato c1 tem mais votos, {false} caso contrario
 */
bool comparaVotos(const Candidato *c1, const Candidato *c2);

#endif