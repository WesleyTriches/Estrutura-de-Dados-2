#include <unordered_set> // set é um conjuntos de valores distintos(não repetidos)
#include <iostream>

using namespace std;

int main(){
    unordered_set<int> numeros;
    int n;

    cout << "Digite valores inteiros (0 para sair)\n";
    while(cin >> n && n!=0){
        numeros.insert(n);
    }

    cout << "Tamanho do conunto: " << numeros.size() << endl;
    cout << "Valores no conjunto\n";
    for(auto num : numeros){
        cout << num << endl;
    }
}