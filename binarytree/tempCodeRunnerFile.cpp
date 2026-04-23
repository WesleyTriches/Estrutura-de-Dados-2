#include "./binarytree.cpp"
#include <iostream>

using namespace binarytree;

int main(){
    node *root=createnode("A");
    root->left = createnode("B");
    root->left->left = createnode("D");
    root->left->right = createnode("E");
    root->right = createnode("C");
    root->right->left = createnode("F");
    root->right->right = createnode("G");
    
    std::cout << "DFS preorder: ";
    DFS_preorder(root);

    std::cout << "\nDFS inorder: ";
    DFS_inorder(root);

    std::cout << "\nDFS posorder: ";
    DFS_posorder(root);

    destroy(root);

}
