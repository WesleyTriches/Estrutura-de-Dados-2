#include <iostream>
#include <string>
using namespace std;

struct node {
    string value;
    node *left;
    node *right;
};

node* createNode(const string &val){
    node* n = new node;
    n->value = val;
    n->left = n->right = nullptr;
    return n;
}

void insert(node* &root, const string &val){
    if(!root) root = createNode(val);
    else if(val < root->value) insert(root->left, val);
    else if(val > root->value) insert(root->right, val);
}

bool search(node* root, const string &val){
    if(!root) return false;
    if(root->value == val) return true;
    if(val < root->value) return search(root->left, val);
    return search(root->right, val);
}

void inorder(node* root, bool &first){
    if(!root) return;
    inorder(root->left, first);
    if(!first) cout << " ";
    cout << root->value;
    first = false;
    inorder(root->right, first);
}

void preorder(node* root, bool &first){
    if(!root) return;
    if(!first) cout << " ";
    cout << root->value;
    first = false;
    preorder(root->left, first);
    preorder(root->right, first);
}

void postorder(node* root, bool &first){
    if(!root) return;
    postorder(root->left, first);
    postorder(root->right, first);
    if(!first) cout << " ";
    cout << root->value;
    first = false;
}

int main(){
    node* root = nullptr;
    string cmd, val;

    while(cin >> cmd){
        if(cmd == "I"){
            cin >> val;
            insert(root, val);
        }
        else if(cmd == "INFIXA"){
            bool first = true;
            inorder(root, first);
            cout << endl;
        }
        else if(cmd == "PREFIXA"){
            bool first = true;
            preorder(root, first);
            cout << endl;
        }
        else if(cmd == "POSFIXA"){
            bool first = true;
            postorder(root, first);
            cout << endl;
        }
        else if(cmd == "P"){
            cin >> val;
            if(search(root, val))
                cout << val << " existe\n";
            else
                cout << val << " nao existe\n";
        }
    }
}