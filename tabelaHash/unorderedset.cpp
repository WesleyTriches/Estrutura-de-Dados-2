#include <unordered_map> 
#include <iostream>
using namespace std;

int main(){
    unordered_map<int, string> alunos; // primeiro na < é chave, depois da ',' é o valor
    
    alunos[987654] = "Fulano de Tal";
    alunos[808080] = "Maria José";
    alunos[101010] = "João Binário";

    int mat;
    while(true){
        cout << " consulta na turma com "
                << alunos.size()
                    << " alunos\n";
        cout << "Matricula (0 para sair)";
        cin >> mat;

        if(mat == 0) break;

        if(alunos.count(mat)== 0)
            cout << "Matricula não encontrada\n";

        else
            cout << alunos[mat] << endl;
    }

    // se buscar uma matricula por exemplo e ela não existir, se não tratar ele insere.
    

}