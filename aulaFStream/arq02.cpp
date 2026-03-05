#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main(){
    ifstream arq("gpl3.txt");
    if(!arq){
        cout << "não abriu" << endl;
        exit(1);
    }

    char ch;
    int maiusculas = 0, minusculas = 0;
    while(arq.get(ch)){
        if(isupper(ch)){
            maiusculas ++;
        }
        else if(islower(ch)){
            minusculas ++;
        }
    }

    // char ch;
    // while(arq.get(ch){
    //     cout << ch;
    // } le caracter por caracter

    arq.close();
    cout << minusculas << " minusculas\n";
    cout << maiusculas << " maiusculas\n";
    
}