#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream arq("gpl3.txt");
    if(!arq){
        cout << "não abriu" << endl;
        exit(1);
    }

    int cont = 0;
    string linha;
    while(getline(arq , linha)){
        cout << linha << endl;
        cont ++;
    }

    arq.close();
    cout << "\nForam lidas " << cont << " linhas\n";
}