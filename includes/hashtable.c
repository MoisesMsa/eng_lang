#include "./hashtable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  TABLE_SIZE 100

// baseado no djb2
unsigned int hash(const char *key) {
    unsigned long hash = 5381;
    int c;
    while((c = *key++)){
        hash = ((hash << 5) + hash) + c;
    }
    // GARANTE QUE O VALUE SEJA ENTRE 0 E TABLE SIZE
    return hash % TABLE_SIZE;
}

entry_point_base *hashtable_pair(const char *key, const char *value){
    entry_point_base *entry_point = malloc(sizeof(entry_point_base) * 1);
    entry_point->key = malloc(strlen(key) + 1);
    entry_point->value = malloc(strlen(value) + 1);

    // como são ponteiros, copia o valor
    strcpy(entry_point->key, key);
    strcpy(entry_point->value, value);
    entry_point->next = NULL;
    return entry_point;
}

hash_table_base *hashtable_create(void){
    hash_table_base *hashtable = malloc(sizeof(hash_table_base) * 1);
    hashtable->entries = malloc(sizeof(entry_point_base *) * TABLE_SIZE);

    int i = 0;
    for(; i < TABLE_SIZE ; ++i){
        hashtable->entries[i] = NULL;
    }
    return hashtable;
}

char *hashtable_get(hash_table_base *hashtable, const char *key){
    if(hashtable == NULL || key == NULL){
        return NULL;
    }

    unsigned int slot = hash(key);
    entry_point_base *entry_point = hashtable->entries[slot];
    while(entry_point != NULL){
        if(strcmp(entry_point->key, key) == 0){
            return entry_point->value;
        }
        entry_point = entry_point->next;
    }

    return NULL;
}

void hashtable_set(hash_table_base *hashtable, const char *key, const char *value){
    if(hashtable == NULL || key == NULL || value == NULL){
        return;
    }

    unsigned int slot = hash(key);
    entry_point_base *entry_point = hashtable->entries[slot];

    if(entry_point == NULL){
        hashtable->entries[slot] = hashtable_pair(key, value);
        return;
    }

    entry_point_base *prev;

    while(entry_point != NULL){
        if(strcmp(entry_point->key, key) == 0){
            free(entry_point->value);
            entry_point->value = malloc(strlen(value) + 1);
            strcpy(entry_point->value, value);
            return;
        }

        prev = entry_point;
        entry_point = prev->next;
    }
    if(prev == NULL) {
        hashtable->entries[slot] = hashtable_pair(key, value);
    } else {
        prev->next = hashtable_pair(key, value);
    }

}

void hashtable_free(hash_table_base *hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        entry_point_base *entry_point = hashtable->entries[i];
        while(entry_point != NULL ){
            entry_point_base *temp = entry_point;
            entry_point = temp->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(hashtable->entries);
    free(hashtable);
} 
