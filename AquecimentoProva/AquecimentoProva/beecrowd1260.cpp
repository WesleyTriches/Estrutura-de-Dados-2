#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main() {

    int N;
    cin >> N;
    cin.ignore();
    cin.ignore();

    for (int i = 0; i < N; i++){
        map<string, int> contagem;
        string especie;
        int total = 0;

        // lê até linha vazia
        while(getline(cin, especie) && especie != "") {
            contagem[especie]++;
            total++;
        }

        // imprime ordenado com percentual
        for(auto [nome, qtd] : contagem) {
            double percentual = (qtd * 100.0) / total;

            cout << nome << " ";
            cout << fixed << setprecision(4) << percentual << endl;
        }

        // linha em branco entre casos (exceto no último)
        if(i != N - 1) cout << endl;
    }

    return 0;
}