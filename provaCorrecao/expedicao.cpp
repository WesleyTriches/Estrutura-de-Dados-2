#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{

    unordered_map<string, int> itens; // nome -> quantidade

    ifstream arqExpedicao("../expedicao2.txt");
    if (!arqExpedicao) {
        cout << "Erro ao abrir expedicao.txt\n";
        exit(1);
    }

    ofstream CSV("expedicao.csv");
    if (!CSV) {
        cout << "Erro ao criar expedicao.csv\n";
        exit(2);
    }

    string nome;
    int quantidade;

    int total = 0;
    while (arqExpedicao >> nome) {
        itens[nome]++;
        total++;
    }

    cout << total << " itens expedidos";
    CSV << "Produto,Percentual" << endl;
    for (auto [nome, quantidade] : itens) {
        double percentual = (quantidade * 100.0) / total;
        CSV << nome << "," << fixed << setprecision(3) << percentual << endl;
    }

    arqExpedicao.close();
    CSV.close();

    return 0;
}