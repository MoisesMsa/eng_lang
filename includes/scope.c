#include "./scope.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack_scope *scope_create(){
    stack_scope *stack = (stack_scope *)malloc(sizeof(stack_scope));
    stack->top = NULL;
    return stack;
}

void scope_push(stack_scope *stack, const char *scope_id){
    scope *new = (scope *)malloc(sizeof(scope));
    new->scope_id = strdup(scope_id);
    new->idx = (stack->top == NULL) ? 0 : stack->top->idx + 1;
    new->next = stack->top;
    stack->top = new;
}

void scope_pop(stack_scope *stack){
    if(stack->top == NULL){
        printf("error");
        return;
    }

    scope *rem = stack->top;
    stack->top = stack->top->next;
    free(rem->scope_id);
    free(rem);
}

void scope_free(stack_scope *stack){
    while(stack->top != NULL){
        scope_pop(stack);
    }
    free(stack);
}

stack_scope *scope_duplicate(stack_scope *original){
    stack_scope *copy = scope_create();
    scope *current = original->top;

    stack_scope *temp = scope_create();
    while(current != NULL){
        scope_push(temp, current->scope_id);
        current = current->next;
    }
    while(temp->top != NULL){
        scope_push(copy, temp->top->scope_id);
        scope_pop(temp);
    }
    scope_free(temp);
    return copy;
}

char *scope_get(stack_scope *stack){
    if(stack->top == NULL){
        return strdup("");
    }
    char *scp =(char *)malloc(sizeof(char) * stack->top->idx + 1);
    scp = "";
    stack_scope *aux = scope_duplicate(stack);
    while(aux->top != NULL){
        if(scp == ""){
            sprintf(scp, "%s", aux->top->scope_id);
        } else {
            sprintf(scp, "%s%s", aux->top->scope_id, scp);
        }
        scope_pop(aux);
    }
    scope_free(aux);
    return scp;
}

