#include <iostream>
#include <vector>
#include <locale>

#include "../include/Votos.h"
#include "../include/Pessoa.h"
#include "../include/Candidato.h"
#include "../include/Partido.h"
#include "../include/Eleicao.h"
#include "../include/Leitura.h"
#include "../include/Relatorio.h"
#include "../include/DateUtils.h"

using namespace std;
using namespace cpp_util;

int main (int argc, char *argv[]) {
    // configura local, uso de virgula e quantidade de casas decimais
    setlocale(LC_ALL, "pt_BR.utf8");     
    // cout.imbue(locale("pt_BR.utf8"));    // causa allocs 
    cout.precision(2);

    if(argc != 4) {
        cerr << "Quantidade de argumentos inválida!" << endl;
        exit(1);
    }

    string caminhoCandidato = argv[1];
    string caminhoPartido = argv[2];
    string dataEleicaoStr = argv[3];
    
    time_t dataEleicao;
    vector<Partido*> partidos;
    vector<Candidato*> candidatos;

    try {
        if(!validDate(dataEleicaoStr)) {
            throw runtime_error("Erro de parsing de string para time_t.");
        }

        dataEleicao = parseDate(dataEleicaoStr);
    } catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

    try {
        partidos = lePartidos(caminhoPartido);
        
        if (partidos.empty())
            throw domain_error("Partidos vazios");
        
        candidatos = leCandidatos(caminhoCandidato, partidos);

        if (candidatos.empty()) 
            throw domain_error("Candidatos vazios");

    } catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

    Eleicao eleicao = Eleicao(dataEleicao, partidos, candidatos);

    mostraNumeroVagas(eleicao);
    mostraVereadoresEleitos(eleicao);
    mostraCandidatosMaisVotados(eleicao);
    int nEleitos = mostraNaoEleitoMajoritario(eleicao);
    mostraEleitosBeneficiados(eleicao, nEleitos);
    mostraInfoPartido(eleicao);
    mostraPrimeiroUltimoPartido(eleicao);
    mostraEleitosPorIdade(eleicao);
    mostraeleitosPorGenero(eleicao);
    mostraVotosEleicao(eleicao);
    
    eleicao.liberaPartidos();

    return 0;
}
