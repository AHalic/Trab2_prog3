#ifndef VOTOS_H
#define VOTOS_H

class Votos {
    private:
        int votosNominais;
        int votosLegenda;
        int votosTotais;

    public:
        Votos(int votosLegenda);
        Votos();

        int getVotosLegenda() const;
        int getVotosNominais() const;
        int getVotosTotais() const;

        void setVotosLegenda(int votos);
        void setVotosNominais(int votos);
};

#endif