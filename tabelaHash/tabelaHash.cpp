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
const int HASHSIZE = 10;

// unsigned hashfn(string &str){
//     unsigned sum = 0;
//     for(auto c : str)
//         sum += unsigned(c); // somando o cod da tabela ASCII

//     return sum % HASHSIZE;
// }

unsigned hashfn(string &str){ //DJB2
        unsigned hash = 5381;
        for(auto c : str)
            hash = hash * 33 + unsigned(c);
        return hash % HASHSIZE; 
}

int main(){
    ifstream arq("clarissa.txt");
    // TODO: testar se abriu com sucesso
    char ch;
    string word;
    int nchar = 0, nwords = 0;
    vector<wordcount> distinctWords[HASHSIZE];

    while(arq.get(ch)){ // lê um caracter por vez
        nchar ++;
        
        if(isalpha(ch)){ // é letra?
            word += tolower(ch); // concatena em minuscula
        }

        else if(word != ""){ // se a string não for vazia printa, o espaço não vai printar 
            bool found = false;

            auto h = hashfn(word);
            for(auto &wc: distinctWords[h]){ // para cada palavra contida no vector

                if(wc.word == word){  // se já existe
                    wc.count ++;
                    found = true;
                    break;
                }

            }

            if(!found){ // Não achou
                    distinctWords[h].push_back({word, 1});
                }

            word = ""; // limpa a string
            nwords ++;
        }
    }

    arq.close();

    ofstream csv("dados.csv");
    int total = 0;

    for(int h=0; h<HASHSIZE; h++){
        for(auto &wc : distinctWords[h]){
            csv << "\"" << wc.word << "\";" << wc.count << "\n";
        } 
        total += distinctWords[h].size();
        cout << h << '\t' << distinctWords[h].size() << '\n';
    }
    csv.close();

}