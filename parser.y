%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);  // Declarando yylex
extern char* yytext;     // Declarando yytext
extern int yylineno;

// Definição da estrutura de 'node'
typedef struct node {
    struct node *left;
    struct node *right;
    int type;
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
%token NUMBER FLOAT ID STRING PRINT
%token PLUS MINUS TIMES DIVIDE POWER
%token ASSIGNMENT EQUALS NOTEQUALS LESSTHAN GREATERTHAN LESSEQUAL GREATEREQUAL
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA COLON
%token INCREMENT DECREMENT FUNCTION WHILE IF ELSE DO FOR ARROW TYPE
%token IN PLUSEQUAL
%token UMINUS  // Token específico para tratar o operador unário '-'
%token AND OR

// Precedência e associatividade
%right POWER           // Exponenciação
%right ASSIGNMENT      // Atribuição
%left TIMES DIVIDE     // Multiplicação e divisão
%left PLUS MINUS       // Soma e subtração
%left LESSTHAN LESSEQUAL GREATERTHAN GREATEREQUAL EQUALS NOTEQUALS
%left OR
%left AND

%type <nval> statements statement expr term factor condition block param param_list nlist
%type <sval> ID TYPE STRING

%start program

%%

program :
    statements { }
;

// Regras da gramática

statements:
    statement { 
        $$ = $1;
    } 
    | statements statement {
        $$ = mknode($1, $2, 0, "STATEMENTS");
    } 
;

param_list:
    param COMMA param_list {}
    | param {}
;

param: 
    | expr 
    | ID
    | ID COLON TYPE {
        $$ = mknode(NULL, NULL, TYPE, $3);
    }
    | ID COLON TYPE LBRACKET RBRACKET {
        $$ = mknode(NULL, NULL, TYPE, "int[]");
    }

statement:
    expr SEMICOLON {
        $$ = $1;
    }
    | ID ASSIGNMENT expr SEMICOLON {
        $$ = mknode(NULL, $3, ASSIGNMENT, "=");
    }
    | ID dms ASSIGNMENT nlist SEMICOLON {
        $$ = mknode(NULL, $4, ASSIGNMENT, "=");
    }
    | ID COLON TYPE ASSIGNMENT expr SEMICOLON {
        $$ = mknode(NULL, $5, ASSIGNMENT, "=");
    }
    | ID LPAREN param_list RPAREN block {
        // $$ = mknode($1, $3, FUNCTION, $5);
    }
    | ID LPAREN param_list RPAREN SEMICOLON {
    }
    | IF condition block {
    }
    | IF condition block ELSE block {
    }
    | WHILE condition block {
    }
    | FOR ID IN expr block {
    }
    | FUNCTION ID LPAREN param_list RPAREN ARROW TYPE block {
    }
    | FUNCTION ID LPAREN param_list RPAREN LBRACE statements RBRACE {
    }
    | PRINT expr SEMICOLON {
    }
;

block:
    LBRACE statements RBRACE { 
    }
    | LBRACE expr RBRACE { 
    }
;

condition:
    expr LESSTHAN expr { 
    }
    | expr LESSEQUAL expr { 
    }
    | expr GREATERTHAN expr { 
    }
    | expr GREATEREQUAL expr { 
    }
    | expr EQUALS expr { 
    }
    | expr NOTEQUALS expr { 
    }
    | condition AND condition { 
    }
    | condition OR condition { 
    }
;

/* @todo checar string */
expr:
    expr PLUS term {
        $$ = mknode($1, $3, PLUS, "+");
    }
    | expr MINUS term {
        $$ = mknode($1, $3, MINUS, "-");
    }
    | ID PLUSEQUAL expr {
    }
    | term { 
        $$ = $1;
    }
    | MINUS factor %prec UMINUS {  // Operador unário menos
    }
    | dms
    | ID dms
;

dms: 
    /* @todo checar ids vazios */
    | LBRACKET RBRACKET
    | LBRACKET RBRACKET dms
    | LBRACKET ID RBRACKET dms
    | LBRACKET nlist RBRACKET
;
 
 nlist:
      | expr
      | expr COLON nlist
      | expr COMMA nlist
;

term:
    term TIMES factor { 
    }
    | term DIVIDE factor { 
    }
    | factor { 
        $$ = $1;
    }
;

factor:
    factor POWER factor { 
    }
    | LPAREN expr RPAREN { 
        $$ = $2;
    }
    | ID { 
    }
    | ID LPAREN expr RPAREN{ 
    }
    | ID LBRACKET expr COLON expr RBRACKET { 
    }
    | NUMBER { 
    }
    | FLOAT { 
    }
    | STRING { 
    }
;

%%

// Função yyerror para tratar erros de sintaxe
void yyerror(const char *s) {
    fprintf(stderr, "-> Linha %d: Erro de sintaxe em: %s\n", yylineno, yytext);
}

node* mknode(node *left, node *right, int type, char *value) {
    node *n = (node *) malloc(sizeof(node));
    n->left = left;
    n->right = right;
    n->type = type;
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
