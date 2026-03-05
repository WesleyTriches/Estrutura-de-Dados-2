#include <iostream>
#include <cctype>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string seq;
        cin >> seq;
        int c1 = seq[0] - '0';
        int c3 = seq[2] - '0';
        if(c1 == c3){
            cout << c1 * c3 << endl;
        }
        else if(isupper(seq[1])){
            cout << c3 - c1 << endl;
        }
         else if(islower(seq[1])){
             cout << c1 + c3 << endl;
         }
    }
    return 0;
}