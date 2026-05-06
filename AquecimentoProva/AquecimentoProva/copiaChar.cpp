/*

2) Escrever um programa que recebe o nome de dois arquivos 
e copia o conteúdo do primeiro arquivo para o segundo, exceto os espaços em brancos e, 
ao final, mostra o número de caracteres que foram copiados.

Foram copiados 324 caracteres

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype> // isspace, issalpha...

using namespace std;

int main(){
    
    string primArq, segArq;
    cin >> primArq >> segArq;

    ifstream input(primArq);
    if(!input){
        cout << "Erro ao tentar abrir o arquivo de entrada" << endl;
        exit(1);
    }

    ofstream output(segArq);
    if(!output){
        cout << "Erro ao tentar abrir o arquivo de saida" << endl;
        exit(2);
    }

    
    char ch;
    int countChar = 0;
    while(input.get(ch)){
        if(!isspace(ch)){
            output << ch;
            countChar ++;
        }
    }

    input.close();
    output.close();

    cout << "Foram copiados " << countChar << " caracteres";
}