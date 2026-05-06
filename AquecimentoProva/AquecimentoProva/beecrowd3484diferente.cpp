#include <iostream>
#include <map>
#include "binaryTreeModificada.cpp"
using namespace binarytree;

int main() {
    int N;
    std::cin >> N;

    binarytree::node *root = nullptr;

    for (int i = 0; i < N; i++) {
        std::string altura;
        std::cin >> altura;

        binarytree::BST::insert(root, altura);
    }

    std::map<int, int> menores;

    binarytree::menor_por_nivel(root, 0, menores);

    for (auto [chave, valor] : menores) {
        std::cout << chave << " " << valor << std::endl;
    }

    binarytree::destroy(root);

    return 0;
}