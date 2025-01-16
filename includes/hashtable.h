#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct entry_point_base{
    char *key;
    char *value;
    struct entry_point_base *next;
} entry_point_base;

typedef struct {
    entry_point_base **entries;
} hash_table_base;

// função hash
unsigned int hash(const char *key);

// cria um par chave-valor
entry_point_base *hashtable_pair(const char *key, const char *value);

// cria uma nova hashtable
hash_table_base *hashtable_create(void);

// devolve um valor do hashtable
char *hashtable_get(hash_table_base *hashtable, const char *key);

// insere ou atualiza um valor no hashtable
void hashtable_set(hash_table_base *hashtable, const char *key, const char *value);

// libera a memoria alocada para a hashtable
void hashtable_free(hash_table_base *hashtable);

#endif