#ifndef BUSCADOR_H
#define BUSCADOR_H
#include <map>
#include <string>
#include <iterator>
#include <vector>

using std::string;
using std::vector;
using std::multimap;

class Buscador
{
    public:
        Buscador();
        Buscador(string palavra);
        Buscador(string chave, string valor);
        virtual ~Buscador();
        void inserir(string chave, string valor);
        vector<string> busca(string chave);
        string retira_caracter();
        string minusculo();

    private:
        multimap<string, string> elem_;
        vector<string> valores_;        //Vetor dinâmico que recebe valores associados a chave passada como parâmetro
        string palavra_;
};

#endif // BUSCADOR_H
