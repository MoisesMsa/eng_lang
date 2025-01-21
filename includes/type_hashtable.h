#ifndef TYPE_HASHTABLE_H
#define TYPE_HASHTABLE_H

#include <stdlib.h>

typedef struct type_entry {
    char *key;                   // Nome do tipo
    char **attributes;           // Lista de atributos (somente para tipos do usuário)
    int attribute_count;         // Quantidade de atributos
    struct type_entry *next;     // Próximo elemento na lista (em caso de colisões)
} type_entry;

typedef struct {
    type_entry **entries;        // Array de ponteiros para entradas
} type_table;

// Função hash
unsigned int type_hash(const char *key);

// Cria uma nova tabela de tipos
type_table *type_table_create();

// Cria um novo par para a tabela de tipos
type_entry *type_table_pair(const char *type_name, char **attributes, int attribute_count);

// Insere ou atualiza um tipo na tabela
void type_table_set(type_table *table, const char *type_name, char **attributes, int attribute_count);

// Retorna informações sobre um tipo
type_entry *type_table_get(type_table *table, const char *type_name);

// Libera a memória alocada para a tabela de tipos
void type_table_free(type_table *table);

#endif
