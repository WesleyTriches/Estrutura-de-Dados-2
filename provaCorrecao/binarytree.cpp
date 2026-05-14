#include <iostream>
#include <string>

namespace binarytree {

struct node {
    std::string value;
    node* left;
    node* right;
};

node* createnode(const std::string& val)
{
    node* nd = new node;
    nd->value = val;
    nd->left = nd->right = nullptr;
    return nd;
}

void show(node* root, int level = 0)
{
    if (!root) {
        std::cout << std::string(level, '\t') << "∅" << "\n";
        return;
    }

    std::cout << std::string(level, '\t') << root->value << "\n";
    if (!root->left && !root->right)
        return;

    show(root->left, level + 1);
    show(root->right, level + 1);
}

void destroy(node* root)
{
    if (!root)
        return;

    destroy(root->left);
    destroy(root->right);
    delete root;
}

bool test_proper(node* root)
{
    if (!root)
        return true;

    if (!root->left && !root->right)
        return true;

    if (!root->left || !root->right)
        return false;

    return test_proper(root->left) && test_proper(root->right);
}
}


