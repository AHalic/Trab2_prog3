#include "../include/Relatorio.h"

#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Metodo para calcular a porcentagem e converter para String. Usa "," como separador das 
 *  casa decimais.
 * @param valor Valor o qual quer saber a porcentagem
 * @param total A quantidade total
 * @return porcentagem da razao valor/total (max 100)
 */
static float calculaPorcentagem(int valor, int total) {
    float porcentagem = (float) valor / (float) total;
    return porcentagem * 100;    
}

void mostraNumeroVagas(Eleicao &eleicao) {
    cout << "Número de vagas: " << eleicao.getVagas() << endl;
    cout << endl;
}

void mostraVereadoresEleitos(Eleicao &eleicao) {
    int contador = 1;

    cout << "Vereadores eleitos:" << endl;
    for (Candidato* c: eleicao.getCandidatos()) {
        if(c->ehEleito()) {
            cout << contador << " - " << c << endl;
            contador++;
        }

        if(contador == eleicao.getVagas() + 1)
            break;
    }

    cout << endl;
}

void mostraCandidatosMaisVotados(Eleicao &eleicao) {
    int contador = 1;

    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    for(Candidato* c: eleicao.getCandidatos()) {
        cout << contador << " - " << c << endl;
        contador++;

        if(contador == (eleicao.getVagas() + 1))
            break;
    }

    cout << endl;
}

int mostraNaoEleitoMajoritario(Eleicao &eleicao) {
    int contador = 1;
    int nEleitos = 0;

    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    for (Candidato* c: eleicao.getCandidatos()) {
        if (!c->ehEleito()) {
            cout << contador << " - " << c << endl;
            nEleitos++;
        }
        
        contador++;
        
        if (contador == eleicao.getVagas() + 1)
            break;
    }

    cout << endl;

    return nEleitos;
}

void mostraEleitosBeneficiados(Eleicao &eleicao, int nEleitos) {
    int contador = 1, eleitos = 0;

    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    
    
    if (eleicao.getVagas() <= eleicao.getCandidatos().size()) {
        for(Candidato *c: eleicao.getCandidatos()) {

            if(c->ehEleito()) {
                eleitos++;
                
                // So imprime os ultimos nEleitos (estes são os que se beneficiaram)
                if(eleicao.getVagas() - eleitos < nEleitos)
                    cout << contador << " - " << c << endl;
            }
            contador++;
        }  

        cout << endl;      	
    }
}

// precisa ta ordenado
void mostraInfoPartido(Eleicao &eleicao) {
    int contador = 1;

    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;

    for (Partido* p : eleicao.getPartidos()) {
        cout << contador << " - " << p << endl;
        contador++;
    }

    cout << endl;
}

// precisa ordenar
void mostraPrimeiroUltimoPartido(Eleicao &eleicao) {
    int cont = 1;

    // precisa ordenar
    
    cout << "Primeiro e último colocados de cada partido:" << endl;

    for (Partido* p: eleicao.getPartidos()) {
        if (p->getVotosTotais() > 0) {
            cout << cont << " - " << p->getSigla() << " - " << p->getNumero() << ", ";

            if (!p->getCandidatos().empty()) {                
                Candidato* prim = p->getCandidatos().front();
                Candidato* ult = p->getCandidatos().back();         

                // cout << prim->shortToString() + " / ";
                // cout << ult->shortToString() << endl;
            }

            cont++;
        }
    }

    cout << endl;
}

// falta
void mostraEleitosPorIdade(Eleicao &eleicao) {

}
 
void mostraeleitosPorGenero(Eleicao &eleicao) {
    int vagas = eleicao.getVagas();
    int F = eleicao.getFEleitas();
    int M = vagas - F;

    float porF = calculaPorcentagem(F, vagas);
    float porM = calculaPorcentagem(M, vagas);
    
    if (vagas > 0) {
        cout << "Eleitos, por sexo:" << endl;
        
        cout << "Feminino:  " << to_string(F);
        cout << " (" << fixed << porF << "%)" << endl;

        cout << "Masculino: " << to_string(M);
        cout << " (" << fixed << porM << "%)" << endl;

        cout << endl;
    }   
}

void mostraVotosEleicao(Eleicao &eleicao) {
    int votosNominais = eleicao.getVotosNominais();
    int votosLegenda = eleicao.getVotosLegenda();
    int votosTotais = eleicao.getVotosTotais();

    float porNominais = calculaPorcentagem(votosNominais, votosTotais);
    float porLegenda = calculaPorcentagem(votosLegenda, votosTotais);

    cout << "Total de votos válidos:    "  << to_string(votosTotais) << endl;
    
    cout << "Total de votos nominais:   " << to_string(votosNominais);
    cout << " (" << fixed << porNominais << "%)" << endl;

    cout << "Total de votos de Legenda: " << to_string(votosLegenda);
    cout << " (" << fixed << porLegenda << "%)" << endl;
}
