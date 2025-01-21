#include "type_table.h"
#include <string.h>
#include <stdio.h>

#define TABLE_SIZE 100

unsigned int type_hash(const char *key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = 31 * hash + key[i];
    }
    return hash % TABLE_SIZE;
}

type_table *type_table_create() {
    type_table *table = malloc(sizeof(type_table));
    table->entries = malloc(sizeof(type_entry *) * TABLE_SIZE);

    for (int i = 0; i < TABLE_SIZE; i++) {
        table->entries[i] = NULL;
    }
    return table;
}

type_entry *type_table_pair(const char *type_name, char **attributes, int attribute_count) {
    type_entry *entry = malloc(sizeof(type_entry));
    entry->key = strdup(type_name);
    entry->attributes = malloc(sizeof(char *) * attribute_count);
    for (int i = 0; i < attribute_count; i++) {
        entry->attributes[i] = strdup(attributes[i]);
    }
    entry->attribute_count = attribute_count;
    entry->next = NULL;
    return entry;
}

void type_table_set(type_table *table, const char *type_name, char **attributes, int attribute_count) {
    unsigned int index = type_hash(type_name);
    type_entry *entry = table->entries[index];

    while (entry) {
        if (strcmp(entry->key, type_name) == 0) {
            for (int i = 0; i < entry->attribute_count; i++) {
                free(entry->attributes[i]);
            }
            free(entry->attributes);

            entry->attributes = malloc(sizeof(char *) * attribute_count);
            for (int i = 0; i < attribute_count; i++) {
                entry->attributes[i] = strdup(attributes[i]);
            }
            entry->attribute_count = attribute_count;
            return;
        }
        entry = entry->next;
    }

    type_entry *new_entry = type_table_pair(type_name, attributes, attribute_count);
    new_entry->next = table->entries[index];
    table->entries[index] = new_entry;
}

type_entry *type_table_get(type_table *table, const char *type_name) {
    unsigned int index = type_hash(type_name);
    type_entry *entry = table->entries[index];
    while (entry) {
        if (strcmp(entry->key, type_name) == 0) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

void type_table_free(type_table *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        type_entry *entry = table->entries[i];
        while (entry) {
            type_entry *temp = entry;
            free(entry->key);
            for (int j = 0; j < entry->attribute_count; j++) {
                free(entry->attributes[j]);
            }
            free(entry->attributes);
            entry = entry->next;
            free(temp);
        }
    }
    free(table->entries);
    free(table);
}
