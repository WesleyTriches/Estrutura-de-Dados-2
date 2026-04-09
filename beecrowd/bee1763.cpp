/*Nicolau já está bastante cansado e sua memória não é mais a mesma.Você, como navegador, 
deverá auxiliar o Papai Noel a gritar a frase "Feliz Natal" no idioma correto de cada país de que trenó está sobrevoando.
Como você é um elfo muito esperto,você já criou um pequeno app no seu celular
(sim, elfos tem celular) que irá lhe informar a frase no idioma correto dado o nome do país.Como o trenó 
é moderno(foi atualizado no ano 2000) ele exibe no painel de navegação o nome do país atual. */

 #include <iostream>
 #include<unordered_map>
 using namespace std;

 int main(){
     unordered_map<string, string> fraseNatal {
        {"brasil",         "Feliz Natal!"},
        {"alemanha",       "Frohliche Weihnachten!"},
        {"austria",        "Frohe Weihnacht!"},
        {"coreia",         "Chuk Sung Tan!"},
        {"espanha",        "Feliz Navidad!"},
        {"grecia",         "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra",     "Merry Christmas!"},
        {"australia",      "Merry Christmas!"},
        {"portugal",       "Feliz Natal!"},
        {"suecia",         "God Jul!"},
        {"turquia",        "Mutlu Noeller"},
        {"argentina",      "Feliz Navidad!"},
        {"chile",          "Feliz Navidad!"},
        {"mexico",         "Feliz Navidad!"},
        {"antardida",      "Merry Christmas!"},
        {"canada",         "Merry Christmas!"},
        {"irlanda",        "Nollaig Shona Dhuit!"},
        {"belgica",        "Zalig Kerstfeest!"},
        {"italia",         "Buon Natale!"},
        {"libia",          "Buon Natale!"},
        {"siria",          "Milad Mubarak!"},
        {"marrocos",       "Milad Mubarak!"},
        {"japao",          "Merii Kurisumasu!"}
     };

     string pais;
     while(cin >> pais){
         if(fraseNatal.count(pais)){
            cout << fraseNatal[pais] << endl;
         }
         else
            cout << "--- NOT FOUND ---" << endl;

     }

    return 0;
 }

