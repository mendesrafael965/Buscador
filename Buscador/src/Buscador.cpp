#include "Buscador.h"

using std::multimap;
using std::pair;

Buscador::Buscador(){

}

Buscador::Buscador(string chave, string valor){
    elem_.insert(pair <string, string> (chave, valor));
}

Buscador::~Buscador(){

}

void Buscador::inserir(string chave, string valor){
    elem_.insert(pair <string, string> (chave, valor));
}

vector<string> Buscador::busca(string chave){

    multimap<string, string>::iterator itr;    //Ponteiro para multimap<string, string>

    for (itr = elem_.begin(); itr != elem_.end(); ++itr)
    {
        if(itr->first == chave){
            valores_.push_back(itr->second);    //-> sintax usada para acessar elementos da classe via ponteiro
        }
    }
    return valores_;
}
