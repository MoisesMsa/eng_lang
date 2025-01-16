#ifndef SCOPE_H
#define SCOPE_H

typedef struct scope {
    char *scope_id;
    int idx;
    struct scope *next;
} scope;

typedef struct {
    scope *top;
} stack_scope;

stack_scope *scope_create();
void scope_push(stack_scope * stack, const char *scope_id);
void scope_pop(stack_scope *stack);
char *scope_get(stack_scope *stack);
stack_scope *scope_duplicate(stack_scope *original);
void scope_free(stack_scope *stack);

#endif