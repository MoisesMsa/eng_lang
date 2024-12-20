#ifndef NODE_H
#define NODE_H

// Estrutura para um nó da árvore
typedef struct node {
    struct node *left;      // Ponteiro para o nó filho à esquerda
    struct node *right;     // Ponteiro para o nó filho à direita
    int tokcode;            // Código do token (identificador do tipo de token)
    const char *token;      // String que representa o token (não será modificada)
} node;

#endif
