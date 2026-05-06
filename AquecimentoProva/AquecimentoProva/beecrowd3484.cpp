#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

namespace binarytree {
    struct node {
        string value;
        node *left;
        node *right;
    };

    node *createnode(const string &val) {
        node *nd = new node;
        nd->value = val;
        nd->left = nd->right = nullptr;
        return nd;
    }

    namespace BST {
        void insert(node *&root, const string &val) {
            if (!root) {
                root = createnode(val);
            }
            else if (stoi(root->value) > stoi(val)) {
                insert(root->left, val);
            }
            else if (stoi(root->value) < stoi(val)) {
                insert(root->right, val);
            }
        }
    }

    void menor_por_nivel(node *root, int nivel, map<int, int> &menores) {
        if (!root) return;

        int valor = stoi(root->value); //converte de string para int

        if (menores.find(nivel) == menores.end()) {
            menores[nivel] = valor;
        }
        else if (valor < menores[nivel]) {
            menores[nivel] = valor;
        }

        menor_por_nivel(root->left, nivel + 1, menores);
        menor_por_nivel(root->right, nivel + 1, menores);
    }

    void destroy(node *root) {
        if (!root) return;

        destroy(root->left);
        destroy(root->right);
        delete root;
    }
}

int main() {
    int N;
    cin >> N;

    binarytree::node *root = nullptr;

    for (int i = 0; i < N; i++) {
        string altura;
        cin >> altura;

        binarytree::BST::insert(root, altura);
    }

    map<int, int> menores; // a funcao modifica esse menores

    binarytree::menor_por_nivel(root, 0, menores); // passado 0 porque comeca na raiz (nivel 0)

    for (auto it = menores.begin(); it != menores.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    binarytree::destroy(root);

    return 0;
}