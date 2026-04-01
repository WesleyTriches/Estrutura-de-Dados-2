#include <unordered_map> 
#include <iostream>
using namespace std;

int main(){
    unordered_map<int, string> alunos; // primeiro na < é chave, depois da ',' é o valor
    
    alunos[987654] = "Fulano de Tal";
    alunos[808080] = "Maria José";
    alunos[101010] = "João Binário";

    cout << alunos[808080] << endl;

}