// Binary tree
#include <string>
#include <algorithm>
#include <iostream>
#include <queue> // FIFO

namespace binarytree{
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

    // Representação por barras
    void show(node* root, int level=0)
    {
        if (!root){
            std::cout << std::string(level, '\t') << "∅" << "\n";
            return;
        }

        std::cout << std::string(level, '\t') << root->value << "\n";
        if(!root->left && !root->right) return;

        show(root->left, level+1);
        show(root->right, level+1);
    }

    // Representação por parênteses aninhado
    void show2(node* root)
    {
        if (!root){
            std::cout << "∅";
            return;
        }

        std::cout << "(" << root->value;

        if(root->left || root->right){
        show2(root->left);
        show2(root->right);
        }
        std::cout << ")";
    }

    void DFS_preorder(node* root){
        if(!root) return;   // Se a árvore é vazia, retorna

        std::cout << root->value << " ";    // visita o nodo (N)
        DFS_preorder(root->left);           // Visita esquerda (L)
        DFS_preorder(root->right);          // Visita esquerda (R)
    }

    void DFS_inorder(node* root){
        if(!root) return;   // Se a árvore é vazia, retorna

        DFS_inorder(root->left);           // Visita esquerda (L)
        std::cout << root->value << " ";   // visita o nodo (N)
        DFS_inorder(root->right);          // Visita esquerda (R)
    }

    void DFS_postorder(node* root){
        if(!root) return;   // Se a árvore é vazia, retorna

        DFS_postorder(root->left);           // Visita esquerda (L)
        DFS_postorder(root->right);          // Visita esquerda (R)
        std::cout << root->value << " ";    // visita o nodo (N)
    }
     
    void BFS(node *root){
        if(!root) return;
        std::queue<node *> q;

        q.push(root);
        while(!q.empty()){
            auto current = q.front(); // consulta quem está na frente da fila
            std::cout << current->value << " ";
            if(current->left) q.push(current->left); // filho da esquerda
            if(current->right) q.push(current->right); // filho da direita
            q.pop();
        }
    }

    void destroy(node *root){
        if(!root) return;

        destroy(root->left);
        destroy(root->right);
        delete(root);
    }

    namespace BST { // arvore binaria de pesquisa
        void insert(node *&root, const std::string &val){
            if(!root){
                root = createnode(val);
            }
            else if(root->value > val){
                insert(root->left, val);
            }
            else if(root->value < val){
                insert(root->right, val);
            }
        }
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
