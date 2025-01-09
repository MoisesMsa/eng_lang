%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);  // Declarando yylex
extern char* yytext;     // Declarando yytext
extern int yylineno;

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

%type <nval> statements statement expr term factor condition block param param_list
%type <sval> ID TYPE STRING

%start program

%%

program : statements { }
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

param_list : param COMMA param_list {}
           | param {}
           ;

param : ID COLON TYPE                  { $$ = mknode(NULL, NULL, TYPE, $3); }
      | ID COLON TYPE LBRACKET RBRACKET { $$ = mknode(NULL, NULL, TYPE, "int[]"); }

statement:
    expr SEMICOLON { 
        $$ = mknode($1, NULL, 0, "EXPRESSION");
    }
    | ID ASSIGNMENT expr SEMICOLON { 
        $$ = mknode(mknode(NULL, NULL, ID, $1), $3, ASSIGNMENT, "=");
    }
    | ID COLON TYPE ASSIGNMENT expr SEMICOLON { 
        $$ = mknode(mknode(NULL, mknode(NULL, NULL, TYPE, $3), ID, $1), $5, ASSIGNMENT, "=");
    }
    | IF condition block { 
        $$ = mknode($2, $3, IF, "IF");
    }
    | IF condition block ELSE block { 
        $$ = mknode($2, mknode($3, $5, ELSE, "ELSE"), IF, "IF");
    }
    | WHILE condition block {
        $$ = mknode($2, $3, WHILE, "WHILE");
    }
    | FOR LPAREN statement condition SEMICOLON expr RPAREN block { 
        $$ = mknode(mknode($3, mknode($4, $6, 0, "FOR CONDITION"), 0, "FOR INIT"), $8, FOR, "FOR");
    }
    | FUNCTION ID LPAREN param_list RPAREN ARROW TYPE block {
    $$ = mknode(mknode(NULL, mknode(NULL, NULL, TYPE, $7), ID, $2), $8, FUNCTION, "FUNCTION");
    }
    | PRINT expr SEMICOLON { 
        printf("%s\n", $2->value); 
        $$ = mknode($2, NULL, PRINT, "PRINT");
    }
;

block:
    LBRACE statements RBRACE { 
        $$ = mknode($2, NULL, 0, "BLOCK");
    }
;

condition:
    expr LESSTHAN expr { 
        $$ = mknode($1, $3, LESSTHAN, "<");
    }
    | expr LESSEQUAL expr { 
        $$ = mknode($1, $3, LESSEQUAL, "<=");
    }
    | expr GREATERTHAN expr { 
        $$ = mknode($1, $3, GREATERTHAN, ">");
    }
    | expr GREATEREQUAL expr { 
        $$ = mknode($1, $3, GREATEREQUAL, ">=");
    }
    | expr EQUALS expr { 
        $$ = mknode($1, $3, EQUALS, "==");
    }
    | expr NOTEQUALS expr { 
        $$ = mknode($1, $3, NOTEQUALS, "!=");
    }
    | condition AND condition { 
        $$ = mknode($1, $3, AND, "and");
    }
    | condition OR condition { 
        $$ = mknode($1, $3, OR, "or");
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
    | ID LBRACKET expr COLON expr RBRACKET { 
        $$ = mknode(mknode(mknode(NULL, NULL, ID, $1), $3, 0, "START"), $5, 0, "SLICE");
    }
    | STRING { 
        $$ = mknode(NULL, NULL, STRING, yytext);
    }
;

%%

// Função yyerror para tratar erros de sintaxe
void yyerror(const char *s) {
    fprintf(stderr, "-> Linha %d: Erro de sintaxe em: %s\n", yylineno, yytext);
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