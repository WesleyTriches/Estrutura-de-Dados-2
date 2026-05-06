/*

1) Escrever um programa (letras.cpp) que abre um arquivo cujo nome foi informado pelo usuário. 
Exibir o percentual de letras e o percentual de outros caracteres armazenados no arquivo. Exibir os valores 
com 1 casa decimal. Seguir exatamente o modelo de saída abaixo:

exemplo.txt possui 73.2% de letras e 26.8% de outros caracteres

*/ 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(){

    string nomeArq;
    cin >> nomeArq;

    ifstream arq(nomeArq);
     if(!arq){
        cout << "não abriu" << endl;
        exit(1);
    }

    char ch;
    int countLetras = 0, countOutros = 0;

    while(arq.get(ch)){
        if(isalpha(ch)){
            countLetras++;
        }
        else{
            countOutros++;
        }
    }

    int total = countLetras + countOutros;
    double percLetras = (countLetras * 100.0) / total;
    double percOutros = (countOutros * 100.0) / total;


    arq.close();
    
    cout << fixed << setprecision(1);
    cout << nomeArq << " possui " 
     << percLetras << "% de letras e "
     << percOutros << "% de outros caracteres" << endl;
}