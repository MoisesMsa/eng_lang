#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estruturas e definições
typedef struct {
    char type[20];
    char value[100];
} Token;

Token tokens[1000];
int tokenCount = 0;

// Arrays e funções para simular o Merge Sort
int array[100];
int arraySize = 0;

void merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            array[k] = leftArr[i];
            i++;
        } else {
            array[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void interpret() {
    int parsingArray = 0; // Flag para indicar que está processando o array
    int arrayStart = 0;

    printf("Starting interpretation...\n");
    printf("Total tokens: %d\n", tokenCount);

    for (int i = 0; i < tokenCount; i++) {
        printf("Debug: Token[%d] Type=%s, Value=%s\n", i, tokens[i].type, tokens[i].value);

        // Detectar o início do array
        if (strcmp(tokens[i].type, "ID") == 0 && strcmp(tokens[i].value, "arr") == 0) {
            parsingArray = 1;
            printf("Array 'arr' detected at Token %d.\n", i);
        }

        // Detectar a abertura do array
        if (parsingArray && strcmp(tokens[i].type, "LBRACKET") == 0) {
            arrayStart = 1;
            printf("Array opening '[' detected at Token %d.\n", i);
        }

        // Adicionar valores ao array
        if (arrayStart && 
            (strcmp(tokens[i].type, "NUMBER") == 0 || 
             strcmp(tokens[i].type, "LBRACKET") == 0 || 
             strcmp(tokens[i].type, "COMMA") == 0)) {
            
            if (isdigit(tokens[i].value[0])) { // Verifica se o valor começa com um dígito
                array[arraySize] = atoi(tokens[i].value);
                printf("Added value %d to array.\n", array[arraySize]);
                arraySize++;
            }
        }

        // Detectar o fechamento do array
        if (arrayStart && strcmp(tokens[i].type, "DBRACKET") == 0) {
            printf("Array closing ']' detected at Token %d.\n", i);
            parsingArray = 0;
            arrayStart = 0;
        }
    }

    if (arraySize == 0) {
        printf("No array found or parsed.\n");
        return;
    }

    // Ordenar o array
    mergeSort(0, arraySize - 1);

    // Exibir o array ordenado
    printf("Sorted array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void loadTokens() {
    FILE *file = fopen("tokens.txt", "r");
    if (!file) {
        printf("Error: Could not open tokens.txt.\n");
        exit(1);
    }

    tokenCount = 0;
    while (fscanf(file, "Token: %[^,], Value: %[^\n]\n", tokens[tokenCount].type, tokens[tokenCount].value) == 2) {
        // Limpar "Token:" e "Value:" caso estejam no arquivo
        if (strncmp(tokens[tokenCount].value, "Token:", 6) == 0) {
            sscanf(tokens[tokenCount].value, "Token: %*[^,], Value: %[^\n]", tokens[tokenCount].value);
        }
        printf("Loaded Token %d: Type=%s, Value=%s\n", tokenCount, tokens[tokenCount].type, tokens[tokenCount].value);
        tokenCount++;
    }

    fclose(file);

    if (tokenCount == 0) {
        printf("Error: No tokens found in tokens.txt.\n");
        exit(1);
    }
}

int main() {
    loadTokens();
    interpret();
    return 0;
}
