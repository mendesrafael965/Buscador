#include "Buscador.h"

using namespace std;

Buscador::Buscador(){

}

Buscador::Buscador(string chave, string valor){
    elem_.insert(pair <string, string> (chave, valor));
}

Buscador::Buscador(string palavra){
    elem_.insert(pair <string, string> ("", ""));
    palavra_ = palavra;
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
string Buscador::minusculo(){
    for(unsigned int i = 0; i < palavra_.length(); i++){
        palavra_[i] = tolower(palavra_[i]);    //toupper()–> Retorna a minúscula de uma letra
    }
    return palavra_;
}

string Buscador::retira_caracter(){
    string s = palavra_;
    unsigned int i, j = 0;
    for(i = 0; i < palavra_.length(); i++){
        if(isalnum(palavra_[i])){   //isalnum() -> Retorna verdadeiro se o argumento é uma letra do alfabeto ou um dígito; falso em caso contrário.
            s[j] = palavra_[i];
            j += 1;
        }
    }
    i = (i - j);
    s.erase(j,i);   //Apaga sub-string de j até k;
    return s;
}
