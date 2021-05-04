#ifndef VOTOS_H
#define VOTOS_H

/**
 * Esta classe representa os tipos de votos numa eleicao. Englobando 
 * votos nominais, votos de legenda e a soma dos dois.
 * 
 * @author Beatriz Maia & Sophie Dilhon
 * @version 1.0
 * @since 04/05/2021
 */
class Votos {
    private:
        int votosNominais;
        int votosLegenda;
        int votosTotais;

    public:
        Votos(int votosLegenda);
        Votos(int votosLegenda, int votosNominais);
        Votos();

        int getVotosLegenda() const;
        int getVotosNominais() const;
        int getVotosTotais() const;

        void setVotosLegenda(int votos);
        void setVotosNominais(int votos);
};

#endif