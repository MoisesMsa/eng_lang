#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./label_generator.h"

char *generateLabel(){
    static int labelCounter = 1;
    char *label = (char *)malloc(20* sizeof(char));
    if(!label){
        printf("Erro ao alocar memória para o label. \n");
        exit(1);
    }
    sprintf(label, "b%d", labelCounter++);
    return label;
}