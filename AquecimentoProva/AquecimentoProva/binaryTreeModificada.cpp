// Binary tree
#include <string>
#include <algorithm>
#include <iostream>
#include <queue> // FIFO
#include <map> // usado no bee3484
 
namespace binarytree{
    struct node {
        std::string value;
        node *left;
        node *right;
    };
 
    // createnode
    //   aloca memória para um novo node, define o valor
    //   armazenado e inicializa os ponteiros dos filhos como nullptr.
    node *createnode(const std::string &val){
        node *nd = new node;
        nd->value = val;
        nd->left = nd->right = nullptr;
        return nd;
    }
 
    // height
    //   se a árvore for vazia retorna -1.
    //   se não, calcula recursivamente a maior altura
    //   entre a subárvore esquerda e direita, somando +1 a cada nível.
    int height(node *root){
        if(!root) 
            return -1; 
 
        return std::max(height(root->left), height(root->right)) +1;
    }
 
    // show
    //   exibe a árvore com indentação por tabulações (representação por barras).
    //   nós nulos são exibidos como ∅.
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
 
    // show2
    //   exibe a árvore em representação por parênteses aninhados.
    //   nós nulos são exibidos como ∅.
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
 
    // DFS_preorder
    //   percorre a árvore em pré-ordem: visita o nó (N),
    //   depois a subárvore esquerda (L), depois a direita (R).
    void DFS_preorder(node* root){
        if(!root) return;
 
        std::cout << root->value << " ";
        DFS_preorder(root->left);
        DFS_preorder(root->right);
    }
 
    // DFS_inorder
    //   percorre a árvore em ordem simétrica: visita a subárvore
    //   esquerda (L), o nó (N), depois a subárvore direita (R).
    //   em uma BST, produz os valores em ordem crescente.
    void DFS_inorder(node* root){
        if(!root) return;
 
        DFS_inorder(root->left);
        std::cout << root->value << " ";
        DFS_inorder(root->right);
    }
 
    // DFS_postorder
    //   percorre a árvore em pós-ordem: visita a subárvore
    //   esquerda (L), a direita (R), depois o nó (N).
    //   útil para deletar a árvore ou avaliar expressões.
    void DFS_postorder(node* root){
        if(!root) return;
 
        DFS_postorder(root->left);
        DFS_postorder(root->right);
        std::cout << root->value << " ";
    }
 
    // BFS
    //   percorre a árvore em largura (nível por nível) usando uma fila.
    //   visita todos os nós de um nível antes de descer para o próximo.
    void BFS(node *root){
        if(!root) return;
        std::queue<node *> q;
 
        q.push(root);
        while(!q.empty()){
            auto current = q.front();
            std::cout << current->value << " ";
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
            q.pop();
        }
    }
 
    // show_level
    //   exibe todos os nós do nível especificado.
    //   o nível da raiz é 1; a cada chamada recursiva decrementa level em 1.
    //   quando level chega a 1, o nó atual está no nível desejado e é exibido.
    //   se não houver nós naquele nível, não exibe nada.
    void show_level(node *root, int level){
        if(!root) return;
 
        if(level == 1){
            std::cout << root->value << "\n";
            return;
        }
 
        show_level(root->left, level - 1);
        show_level(root->right, level - 1);
    }
 
    // count_nodes
    //   conta e retorna o número total de nós da árvore.
    //   se a árvore for vazia, retorna 0.
    int count_nodes(node *root){
        if(!root) return 0;
        return 1 + count_nodes(root->left) + count_nodes(root->right);
    }
 
    // count_leaves
    //   conta e retorna o número de folhas da árvore.
    //   uma folha é um nó que não possui filhos (left e right são nullptr).
    //   se a árvore for vazia, retorna 0.
    int count_leaves(node *root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return count_leaves(root->left) + count_leaves(root->right);
    }
 
    // count_level
    //   conta e retorna quantos nós existem no nível especificado.
    //   usa a mesma lógica de show_level: decrementa level a cada chamada.
    //   se não houver nós naquele nível, retorna 0.
    int count_level(node *root, int level){
        if(!root) return 0;
        if(level == 1) return 1;
        return count_level(root->left, level - 1) + count_level(root->right, level - 1);
    }

    // menor_por_nivel
    //   percorre a árvore inteira e guarda, em um map,
    //   o menor valor encontrado em cada nível.
    //   o nível da raiz deve começar em 0.
    //   exemplo:
    //      nível 0 -> menor valor da raiz
    //      nível 1 -> menor valor entre os filhos da raiz
    //      nível 2 -> menor valor entre os netos, etc.
    void menor_por_nivel(node *root, int nivel, std::map<int, int> &menores){
        if(!root) return;

        int valor = std::stoi(root->value);

        if(menores.find(nivel) == menores.end()){
            menores[nivel] = valor;
        }
        else if(valor < menores[nivel]){
            menores[nivel] = valor;
        }

        menor_por_nivel(root->left, nivel + 1, menores);
        menor_por_nivel(root->right, nivel + 1, menores);
    }

    // maior_por_nivel
    //   percorre a árvore inteira e guarda, em um map,
    //   o maior valor encontrado em cada nível.
    //   funciona igual ao menor_por_nivel,
    //   mas troca apenas se o valor atual for maior.
    void maior_por_nivel(node *root, int nivel, std::map<int, int> &maiores){
        if(!root) return;

        int valor = std::stoi(root->value);

        if(maiores.find(nivel) == maiores.end()){
            maiores[nivel] = valor;
        }
        else if(valor > maiores[nivel]){
            maiores[nivel] = valor;
        }

        maior_por_nivel(root->left, nivel + 1, maiores);
        maior_por_nivel(root->right, nivel + 1, maiores);
    }
 
    // destroy
    //   libera toda a memória alocada pela árvore.
    //   percorre em pós-ordem para garantir que os filhos
    //   sejam deletados antes do nó pai.
    void destroy(node *root){
        if(!root) return;
 
        destroy(root->left);
        destroy(root->right);
        delete(root);
    }
 
    namespace BST { // arvore binaria de pesquisa
 
        // insert
        //   insere um novo valor na BST mantendo a propriedade de ordem:
        //   valores menores vão para a esquerda, maiores para a direita.
        //   valores iguais são ignorados (sem duplicatas).
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
 
        // search
        //   busca um valor na BST e retorna o ponteiro para o nó encontrado.
        //   aproveita a propriedade de ordem para descartar metade da árvore
        //   a cada passo (busca eficiente O(h), onde h é a altura).
        //   retorna nullptr se o valor não existir.
        node* search(node *root, const std::string &val){
            if(!root) return nullptr;
            if(root->value == val) return root;
            if(root->value > val) return search(root->left, val);
            return search(root->right, val);
        }
 
        // min
        //   retorna o ponteiro para o nó com o menor valor da BST.
        //   na BST, o menor valor está sempre no nó mais à esquerda.
        //   retorna nullptr se a árvore for vazia.
        node* min(node *root){
            if(!root) return nullptr;
            if(!root->left) return root;
            return min(root->left);
        }
 
        // max
        //   retorna o ponteiro para o nó com o maior valor da BST.
        //   na BST, o maior valor está sempre no nó mais à direita.
        //   retorna nullptr se a árvore for vazia.
        node* max(node *root){
            if(!root) return nullptr;
            if(!root->right) return root;
            return max(root->right);
        }
 
        // remove
        //   remove um nó com o valor especificado da BST mantendo a propriedade de ordem.
        //   três casos possíveis:
        //     1. nó sem filhos (folha): simplesmente deletado.
        //     2. nó com um filho: substituído pelo filho.
        //     3. nó com dois filhos: substituído pelo menor valor da subárvore direita
        //        (sucessor em ordem), que então é removido recursivamente.
        void remove(node *&root, const std::string &val){
            if(!root) return;
 
            if(root->value > val){
                remove(root->left, val);
            }
            else if(root->value < val){
                remove(root->right, val);
            }
            else {
                // caso 1 e 2: sem filho esquerdo
                if(!root->left){
                    node *temp = root;
                    root = root->right;
                    delete temp;
                }
                // caso 2: sem filho direito
                else if(!root->right){
                    node *temp = root;
                    root = root->left;
                    delete temp;
                }
                // caso 3: dois filhos
                else {
                    node *successor = min(root->right);
                    root->value = successor->value;
                    remove(root->right, successor->value);
                }
            }
        }
 
    } // namespace BST
 
} // namespace binarytree
 