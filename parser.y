<<<<<<< HEAD
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
=======
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(char *s);
extern char * yytext;
extern int yylineno;
%}

// sera se vai ser preciso criar um union para arrays e matrizes? 
// do tipo struct que vai ter linhas e colunas
%union {
    char *sValue;
};

%token <sValue> ID
%token <sValue> NUMBER
%token <sValue> FLOAT
%token <sValue> STRING
%token <sValue> TYPE
%token <sValue> BOOL
%token IF ELSE WHILE FOR IN ARROW ASSIGN FUNCTION
%token PLUS MINUS MULT DIVISION EXPOENT
%token AND OR NOT
%token EQUALS DIFF LESS GREATER LESSEQUALS GREATEREQUALS
%token INCREMENT DECREMENT INCREMENT_ASSIGN DECREMENT_ASSIGN
%token MATRIX
%token STRUCT

%right EXPOENT
%right ASSIGN
%left MULT DIVISION
%left PLUS MINUS
%left EQUALS DIFF LESS GREATER LESSEQUALS GREATEREQUALS
%left AND
%left OR
%left NOT

%type <sValue> sub_programs sub_program stmt stmts_list structs declaration declarations
%type <sValue> block param param_list dms condition
%type <sValue> stmt_array stmt_matrix dms_acess matrix_twod
%type <sValue> expr term factor exp expr_list args

%start program

%%

program : sub_programs { }
        | structs {}
        ;

structs : STRUCT ID '{' declarations '}' {}
        | STRUCT ID '{' declarations sub_programs '}' {}
        ;

declarations : declaration {}
             | declaration declarations {}
             ;

declaration : ID ':' TYPE ';' {}
            | ID ':' TYPE dms ';' {}
            | ID ':' MATRIX ';' {}
            ;

sub_programs : sub_programs sub_program {}
             | sub_program {}
             ;

sub_program : FUNCTION ID '(' param_list ')' ARROW TYPE block {}
            ;

param_list : param ',' param_list {}
           | param {}
           ;

param : ID ':' TYPE {}
      | ID ':' TYPE dms {}
      | {}
      | ID ':' MATRIX {}
      ;

block : '{' stmts_list '}' {}
      ;

stmts_list : stmt {}
           | stmt stmts_list {}
           ;

stmt : ID ASSIGN expr ';' {}
     | ID ':' TYPE ASSIGN expr ';' {}
     | ID INCREMENT ';' {}
     | ID DECREMENT ';' {}
     | ID INCREMENT_ASSIGN expr ';' {}
     | ID DECREMENT_ASSIGN expr ';' {}
     | ID '(' args ')' ';' {} // chamada de função
     | declaration {}
     | if_stmt {}
     | WHILE condition block {}
     | FOR ID IN ID block {}
     | stmt_array ';' {}
     | stmt_matrix ';' {}
     ;

if_stmt : IF condition block elseif {}
        ;

elseif : ELSE IF condition block elseif {}
       | ELSE block {}
       | {}
       ;

stmt_array : ID '[' expr ':' expr ']' ASSIGN expr {} // slice de array
           | ID ':' TYPE dms ASSIGN expr {}
           | ID dms_acess ASSIGN expr {}
           ;

stmt_matrix : ID ':' MATRIX ASSIGN expr {} // matriz padrão com 2 dimensões
            | ID ':' MATRIX '[' expr ']' ASSIGN expr {}  // define quantas dimensões são
            | ID matrix_twod ASSIGN expr {}
            ;

matrix_twod : '[' expr ']' '[' ']' {} // aqui devolveria apenas a linha que ele quer, apenas para 2d
             | '[' ']' '[' expr ']' {} // aqui devolveria apenas a coluna que ele quer, apenas para 2d
             ;

dms_acess : '[' expr ']' {}
          | '[' expr ']' dms_acess {}

dms : '[' ']' {}
    | '[' ']' dms {}
    ;

condition : expr LESS expr {}
          | expr GREATER expr {}
          | expr LESSEQUALS expr {}
          | expr GREATEREQUALS expr {}
          | expr EQUALS expr {}
          | expr DIFF expr {}
          | NOT condition {}
          | condition AND condition {}
          | condition OR condition {}
          | ID {}
          | BOOL {}
          | ID '(' args ')' ';' {} // chamada de função
          ;

// abaixo disso é tudo lado direito
// abordaremos as operacoes em matrizes de maneira individual? 
// eu acho que pela tabela de simbolos, aqui da pra fazer a soma de matrizes identificando os tipos
// assim nao precisando de um token especifico pra soma de matriz, ja que vamos disponibilizar como primitivo
expr : expr PLUS term {}
     | expr MINUS term {}
     | term
     ;

// o mesmo para multiplicacao de matrizes, temos que pensar apenas na regra da transposicao
term : term MULT factor {}
     | term DIVISION factor {}
     | factor
     ;

factor : exp EXPOENT factor {}
       | exp
       ;

// falta abordar de passar uma matriz como por exemplo [[1,2][3,4]]
// falta tratar o - unario
exp : '(' expr ')' {}
    | ID {}
    | NUMBER {}
    | FLOAT {}
    | STRING {}
    | BOOL {}
    | ID dms_acess {} 
    | ID '[' expr  ':' expr ']' {} // slice de array
    | ID '(' args ')' {} // chamada de função
    | '[' expr_list ']' {}
    | dms {}
    | ID INCREMENT {}
    | ID DECREMENT {}
    | ID matrix_twod {}
    ;

expr_list : expr {}
          | expr ',' expr_list {}
          ;

args : {}
     | expr {}
     | expr ',' args {}
     ;

%%

int main(void) {
     return yyparse();
}

int yyerror(char *msg){
     fprintf(stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
     return 0;
}
>>>>>>> origin/feature-sintatico
