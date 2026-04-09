// Binary tree
#include <string>
#include <algorithm>
#include <iostream>

namespace bynarytree{
    struct node {
        std::string value;
        node *left;
        node *right;
    };

    node *createnode(const std::string &val){
        node *nd = new node;
        nd->value = val;
        nd->left = nd->right = nullptr;
        return nd;
    }

    // Calcula a altura da árvore
    int height(node *root){
        if(!root) 
            return -1; 

        return std::max(height(root->left), height(root->right)) +1;
    }

    // TODO: usar alguma forma de representação de árvore
    void show(node *root, int level = 0){
        if(!root) 
            return;
        std::cout << std::string(level, '\t') << root->value << "\n";
        show(root->left, level +1);
        show(root->right, level+1);
    }
} // namespace bynarytree



/*
--createnode--  
    aloca memória para um novo node, define o valor
    armazenado e inicializa os ponteiros dos filhos como nullptr.

-- height
    se a árvore for vazia retorna -1
    se não, calcula a altura e soma mais 1
*/