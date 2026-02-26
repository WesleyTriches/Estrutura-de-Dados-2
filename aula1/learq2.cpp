#include <iostream>
#include <fstream> //file stream
#include <cstdlib> // exit

using namespace std;

int main(){
    ifstream input;
    input.open("numeros.txt");

    if(!input){
        cout << "Erro ao abrir o arquivo de entrada\n";
        exit(1); //termina com 1 pois pode ser por falha ou algo assim, se fosse no fim seria 0
    }

    ofstream output;
    output.open("dobro.txt"); // o arquivo de output sempre cria um novo se não fizermos uma condição
    if(!output){
        cout << "Erro ao abrir arquivo de saída\n";
        exit(2);
    }

    double num;
    while(input >> num){ //EOF
        output << "Dobro: " << num * 2 << endl;
    }
    
    input.close();
    output.close();

    return 0;
}



// ifstream -> input file steam
// ofstream -> output file stream
//g++ learq.cpp -o learq 
// ./learq