#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    for(int c = 0; c < N; c++){
        int M;
        cin >> M;
        vector<int> vetor(M);

        for (int j = 0; j < M; j++) {
            cin >> vetor[j];
        }

        int contador = 0;
        vector<int> aux = vetor;
        sort(aux.begin(), aux.end());
        reverse(aux.begin(), aux.end());

        for(int i = 0; i < M; i++){        
            if(vetor[i] == aux[i]){
                contador++;
            }
        }
        cout << contador << endl;
    }
    return 0;
}