#include <iostream>
#include <string>

using namespace std;

class ExLeituraPartido : public exception{
    private:
        string _msg;
        int _linha;

    public:

    ExLeituraPartido(const string &msg);
    ExLeituraPartido(const string &msg, const int &linha);
    ExLeituraPartido();
    
    virtual const char* what() const throw();
};
