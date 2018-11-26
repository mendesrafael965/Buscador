#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;
using std::endl;

string minusculo(string palavra){
    for(unsigned int i = 0; i < palavra.length(); i++){
        palavra[i] = tolower(palavra[i]);    //toupper()–> Retorna a minúscula de uma letra
    }
    return palavra;
}

string retira_caracter(string palavra){
    string s = palavra;
    unsigned int i, j = 0;
    for(i = 0; i < palavra.length(); i++){
        if(isalnum(palavra[i])){   //isalnum() -> Retorna verdadeiro se o argumento é uma letra do alfabeto ou um dígito; falso em caso contrário.
            s[j] = palavra[i];
            j += 1;
        }
    }
    i = (i - j);
    s.erase(j,i);   //Apaga sub-string de j até k;
    return s;
}

bool busca_no_txt(string palavra, string n_arq){
    string s1;
    char *a = &(n_arq[0]);    //Converte string para stringC
    ifstream streamDeEntrada(a);

    //Testa se o arquivo foi aberto com sucesso
    if(streamDeEntrada.fail()){
        cout << "Problema na abertura do arquivo" << endl;
        exit(1);
    }

    //O loop é enserrado caso chege o fim o arquivo ou a palavra procurada seja encontrada
    do{
        //Lê strings do arquivo uma a uma
        streamDeEntrada >> s1;
        s1 = minusculo(s1);
        s1 = retira_caracter(s1);

        //Verifica se a string lida é igual a string procurada
        if(s1 == palavra){
            return true;
        }
    }while(streamDeEntrada.eof() == false && s1 != palavra);
    streamDeEntrada.close();

    return false;
}
