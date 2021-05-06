#include <iostream>
#include <string>

using namespace std;

class ExLeituraCandidato : public exception{
    private:
        string _msg;
        int _linha;

    public:

    ExLeituraCandidato(const string &msg);
    ExLeituraCandidato(const string &msg, const int &linha);
    ExLeituraCandidato();
    
    virtual const char* what() const throw();
};
