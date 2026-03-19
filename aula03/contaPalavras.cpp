// para cada palavra, contar quantas são distintas
#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std;

struct wordcount{
    string word;
    int count;
};

int main(){
    ifstream arq("clarissa.txt");
    // TODO: testar se abriu com sucesso
    char ch;
    string word;
    int nchar = 0, nwords = 0;
    vector<wordcount> distinctWords;

    while(arq.get(ch)){ // lê um caracter por vez
        nchar ++;
        
        if(isalpha(ch)){ // é letra?
            word += tolower(ch); // concatena em minuscula
        }

        else if(word != ""){ // se a string não for vazia printa, o espaço não vai printar 
            bool found = false;
            for(auto &wc: distinctWords){ // para cada palavra contida no vector

                if(wc.word == word){  // se já existe
                    wc.count ++;
                    found = true;
                    break;
                }

            }

            if(!found){ // Não achou
                    distinctWords.push_back({word, 1});
                }

            word = ""; // limpa a string
            nwords ++;
        }
    }

    arq.close();
    cout << nchar << " caracteres\n"
        << nwords << " palavras\n"
        << distinctWords.size() << " distintas\n";

    ofstream csv("dados.csv"); 
        for(auto &wc : distinctWords){
            csv << "\"" << wc.word << "\";" << wc.count << "\n";
        }
    csv.close();
}