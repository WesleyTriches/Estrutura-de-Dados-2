#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string l;
        int contador = 0;
        int menor = 0;
        cin >> l;
        for(int j = 0; j < l.size(); j++) {  
            if(l[j] == '<'){
                menor ++;
            }
            else if(l[j] == '>' && menor > 0){
                contador ++;
                menor --;
            }
        }
        cout << contador << endl;
    }
    return 0;
}
