#ifndef FUNCTION_HASHTABLE_H
#define FUNCTION_HASHTABLE_H

#include <stdlib.h>

typedef struct function_entry {
    char *key;                     // Nome (ID) da função
    char *return_type;             // Tipo de retorno
    char **parameters;             // Lista de tipos dos parâmetros
    int param_count;               // Quantidade de parâmetros
    struct function_entry *next;   // Próximo elemento na lista (em caso de colisões)
} function_entry;

typedef struct {
    function_entry **entries;      // Array de ponteiros para entradas
} function_table;

// Função hash
unsigned int function_hash(const char *key);

// Cria uma nova tabela de funções
function_table *function_table_create();

// Cria um novo par para a tabela de funções
function_entry *function_table_pair(const char *id, const char *return_type, char **parameters, int param_count);

// Insere ou atualiza uma função na tabela
void function_table_set(function_table *table, const char *id, const char *return_type, char **parameters, int param_count);

// Retorna informações sobre uma função
function_entry *function_table_get(function_table *table, const char *id);

// Libera a memória alocada para a tabela de funções
void function_table_free(function_table *table);

#endif
