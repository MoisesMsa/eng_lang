%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);  // Declarando yylex
extern char* yytext;     // Declarando yytext

// Definição da estrutura de 'node'
typedef struct node {
    int type;
    struct node *left;
    struct node *right;
    char *value;
} node;

// Funções auxiliares para manipulação da árvore
node* mknode(node *left, node *right, int type, char *value);
void printtree(node *n);
void freeTree(node *n);

// Função de erro para bison
void yyerror(const char *s);
%}

%union {
    int ival;
    float fval;
    char* sval;
    struct node* nval;
}

// Declaração dos tokens
%token NUMBER FLOAT ID STRING
%token PLUS MINUS TIMES DIVIDE POWER
%token ASSIGNMENT EQUALS NOTEQUALS LESSTHAN GREATERTHAN LESSEQUAL GREATEREQUAL
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA COLON
%token INCREMENT DECREMENT

// Definindo o token UMINUS para operador unário
%token UMINUS

// Precedência e associatividade
%right POWER        // Exponenciação, associatividade à direita
%right ASSIGNMENT   // Atribuição, associatividade à direita
%left TIMES DIVIDE  // Multiplicação e divisão
%left PLUS MINUS    // Soma e subtração

%type <nval> statements statement expr term factor

%%

statements:
    statement { 
        printf("Statement: %s\n", $1->value);
        $$ = $1;
    }
    | statements statement {
        printf("Statement: %s\n", $2->value);
        $$ = $2;
    }
;

statement:
    expr { 
        $$ = mknode($1, NULL, 0, "EXPRESSION"); 
    }
    | expr ASSIGNMENT expr { 
        $$ = mknode($1, $3, ASSIGNMENT, "="); 
    }
;

expr:
    expr PLUS term { 
        $$ = mknode($1, $3, PLUS, "+");
    }
    | expr MINUS term { 
        $$ = mknode($1, $3, MINUS, "-");
    }
    | term { 
        $$ = $1;
    }
    | MINUS factor %prec UMINUS {  // Operador unário menos
        $$ = mknode(NULL, $2, UMINUS, "-");
    }
;

term:
    term TIMES factor { 
        $$ = mknode($1, $3, TIMES, "*");
    }
    | term DIVIDE factor { 
        $$ = mknode($1, $3, DIVIDE, "/");
    }
    | factor { 
        $$ = $1;
    }
;

factor:
    factor POWER factor { 
        $$ = mknode($1, $3, POWER, "^");
    }
    | LPAREN expr RPAREN { 
        $$ = $2;
    }
    | NUMBER { 
        $$ = mknode(NULL, NULL, NUMBER, yytext);
    }
    | FLOAT { 
        $$ = mknode(NULL, NULL, FLOAT, yytext);
    }
    | ID { 
        $$ = mknode(NULL, NULL, ID, yytext);
    }
;

%%

// Função yyerror para tratar erros de sintaxe
void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}

node* mknode(node *left, node *right, int type, char *value) {
    node *n = (node *) malloc(sizeof(node));
    n->type = type;
    n->left = left;
    n->right = right;
    n->value = value ? strdup(value) : NULL;
    return n;
}

void printtree(node *n) {
    if (n) {
        printf("Node Type: %d, Value: %s\n", n->type, n->value);
        printtree(n->left);
        printtree(n->right);
    }
}

void freeTree(node *n) {
    if (n) {
        freeTree(n->left);
        freeTree(n->right);
        free(n->value);
        free(n);
    }
}

int main(void) {
    yyparse();  // Inicia a análise
    return 0;
}
