#include <iostream>
#include <fstream> //file stream
#include <cstdlib> // exit

using namespace std;

int main(){
    ifstream arq;
    arq.open("numeros.txt");

    if(!arq){
        cout << "Erro ao abrir o arquivo\n";
        exit(1); //termina com 1 pois pode ser por falha ou algo assim, se fosse no fim seria 0
    }

    double num;

    while(arq >> num){ //EOF
        cout << "Dobro: " << num * 2 << endl;
    }
    
    arq.close();

    return 0;
}



// ifstream -> input file steam
//g++ learq.cpp -o learq 
// ./learq