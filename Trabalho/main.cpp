/**
 * Trabalho 2 de Programacao 3.
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 06/05/2021
**/

#include <locale>

#include "Eleicao.h"
#include "Leitura.h"
#include "Relatorio.h"
#include "DateUtils.h"

using namespace std;
using namespace leitura;
using namespace relatorio;
using namespace cpp_util;

int main (int argc, char *argv[]) {
    // configura local, uso de virgula e quantidade de casas decimais
    setlocale(LC_ALL, "pt_BR.UTF-8");     
    cout.imbue(locale("pt_BR.UTF-8"));    
    cout.precision(2);

    // verifica se recebeu a quantidade correta de argumentos
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
            throw runtime_error("Partidos vazios");
        
        candidatos = leCandidatos(caminhoCandidato, partidos);

        if (candidatos.empty()) 
            throw runtime_error("Candidatos vazios");

    } catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

    Eleicao eleicao = Eleicao(dataEleicao, partidos, candidatos);

    // mostra relatorios
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
    
    // libera memoria alocada por partido e candidato
    eleicao.liberaInformacoes();

    // libera os allocs causado pelo locale("pt_BR.utf8")
    cout.imbue(locale());    

    return 0;
}
