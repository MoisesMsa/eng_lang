#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaração da estrutura node
typedef struct node {
    struct node *left;
    struct node *right;
    int tokcode;
    char *token;
} node;

// Função para criar um novo nó
node *mknode(node *left, node *right, int tokcode, const char *token) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        perror("Erro na alocação de memória para novo nó.");
        exit(1);
    }
    newnode->left = left;
    newnode->right = right;
    newnode->tokcode = tokcode;
    newnode->token = strdup(token);  // Duplicar a string para evitar problemas de memória
    return newnode;
}

// Função para imprimir a árvore
void printtree(node *tree) {
    if (tree) {
        printf("(");
        printtree(tree->left);
        printf(" %s ", tree->token);
        printtree(tree->right);
        printf(")");
    }
}

// Função para gerar algum código a partir da árvore (a ser implementado)
void generate(node *tree) {
    if (tree != NULL) {
        generate(tree->left);
        generate(tree->right);
    }
}

// Função para liberar memória da árvore
void freeTree(node *tree) {
    if (tree) {
        freeTree(tree->left);
        freeTree(tree->right);
        free(tree->token);  // Liberar a string duplicada
        free(tree);
    }
}

int main(void) {
    // Exemplo de criação de uma árvore simples
    node *n1 = mknode(NULL, NULL, 1, "10");
    node *n2 = mknode(NULL, NULL, 2, "20");
    node *root = mknode(n1, n2, 3, "+");
    
    // Imprimir a árvore
    printtree(root);
    printf("\n");
    
    // Liberar memória
    freeTree(root);
    
    return 0;
}
