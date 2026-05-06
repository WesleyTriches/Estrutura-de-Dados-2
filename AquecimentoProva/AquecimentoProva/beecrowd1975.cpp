#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    
    int P, A, R;
    
    while (cin >> P >> A >> R && (P || A || R)) {
        cin.ignore();
        
        vector<string> perolas(P);
        for (int i = 0; i < P; i++) {
            getline(cin, perolas[i]);
        }
        
        map<string, int> contagem;
        
        for (int i = 0; i < A; i++) {
            string nome;
            getline(cin, nome);
            
            int erros = 0;
            for (int j = 0; j < R; j++) {
                string resposta;
                getline(cin, resposta);
                
                for (int k = 0; k < P; k++) {
                    if (resposta == perolas[k]) {
                        erros++;
                        break;
                    }
                }
            }
            contagem[nome] = erros;
        }
        
        int maxVal = 0;
        for (auto& [nome, erros] : contagem) {
            if (erros > maxVal) maxVal = erros;
        }
        
        vector<string> vencedores;
        for (auto& [nome, erros] : contagem) {
            if (erros == maxVal) {
                vencedores.push_back(nome);
            }
        }
        
        for (int i = 0; i < (int)vencedores.size(); i++) {
            if (i > 0) cout << ", ";
            cout << vencedores[i];
        }
        cout << "\n";
    }
    
    return 0;
}