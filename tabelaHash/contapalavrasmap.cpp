// para cada palavra, contar quantas são distintas
#include <iostream>
#include <cctype>
#include <fstream>
#include <unordered_map>

using namespace std;


int main(){
    ifstream arq("clarissa.txt");
    if(!arq){
        cout << "Não abriu arquivo de entrada \n";
        return 1;
    }
    char ch;
    string word;
    int nchar = 0, nwords = 0;
    unordered_map<string, int> distinctwords;

    while(arq.get(ch)){ // lê um caracter por vez
        nchar ++;
        
        if(isalpha(ch)){ // é letra?
            word += tolower(ch); // concatena em minuscula
        }

        else if(word != ""){ // se a string não for vazia printa, o espaço não vai printar 
            distinctwords[word]++; // igual distinctwords[word] = distinctwords[word] +1;

            word = ""; // limpa a string
            nwords ++;
        }
    }

    arq.close();

    ofstream csv("dados.csv"); 
    int total = 0;
    for(auto [key, value]: distinctwords){
        csv << '"' << key << '"' << ';' << value << '\n';
    }
    csv.close();
    cout << nchar << " caracteres\n"
        << nwords << " palavras\n"
        << distinctwords.size() << " distintas\n";

}
    
