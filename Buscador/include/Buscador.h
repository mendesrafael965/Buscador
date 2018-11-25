#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <map>
#include <string>
#include <iterator>
#include <vector>


using namespace std;

class Buscador
{
    public:
        Buscador();
        Buscador(string chave, string valor);
        virtual ~Buscador();
        void inserir(string chave, string valor);
        vector<string> busca(string chave);


    private:
        multimap<string, string> elem_;  //
        vector<string> valores_;        //Vetor dinâmico que recebe valores associados a chave passada como parâmetro
};

#endif // BUSCADOR_H
