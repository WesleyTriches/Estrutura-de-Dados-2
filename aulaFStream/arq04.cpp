#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

int main(){
    ifstream arq("gpl3.txt");
    if(!arq){
        cout << "não abriu" << endl;
        exit(1);
    }

    char ch;
    int frequencia[256] = {};   // array inicializado com 0's
    while(arq.get(ch)){        //le cada caracter do arquivo
        frequencia[unsigned(ch)]++; //incrementa aquele indice
    }

    for(int i=0; i<256; i++){
        if(frequencia[i]>0)
        cout << setw(3) << i 
            << ' '
            << (isprint(i) ? char(i) : ' ')  // se é imprimivel, imprime o caracter, se nao, imprime espaco
            << ' '
            << setw(4) << frequencia[i] 
            << "\n";
    }

    arq.close();
   
}
