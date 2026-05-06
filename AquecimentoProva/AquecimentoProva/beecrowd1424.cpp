#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int N, M;

    while (cin >> N >> M) {

        map<int, vector<int>> posicoes;

        for (int i = 1; i <= N; i++) {
            int x;

            cin >> x;

            // guarda a posição i para o valor x
            // se x não existir, cria um vector vazio automaticamente
            posicoes[x].push_back(i);
        }

        for (int i = 0; i < M; i++) {
            int k, v;
            cin >> k >> v;

            if (posicoes[v].size() >= k) {
                cout << posicoes[v][k - 1] << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}