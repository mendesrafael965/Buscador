#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "Buscador.h"
#include "util.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string objetivo;
    do{
        cout << "Digite o que deseja buscar ou sair, para sair:" << endl;
        Buscador linha;
        cin >> objetivo;
        objetivo = minusculo(objetivo);
        objetivo = retira_caracter(objetivo);
        string n_arq;
        for(int i = 1; i < 4; i++){
                //Define qual arquivo será aberto
            switch(i){
                case 1:
                    n_arq = "d1.txt";
                break;
                case 2:
                    n_arq = "d2.txt";
                break;
                case 3:
                    n_arq = "d3.txt";
                break;
            }

            if(busca_no_txt(objetivo,n_arq) == 1){
                linha.inserir(objetivo,n_arq); //Insere palavra encontrada no dicionário
            }
        }
        //Busca
        vector<string> valor;
        valor = linha.busca(objetivo);
        for(unsigned int i = 0; i < valor.size(); i++){
            cout << valor[i] << endl;
        }
        cout << endl;
    }while(objetivo != "sair");
    return 0;
}
