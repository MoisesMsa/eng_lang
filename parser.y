%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);
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
%token IF ELSE WHILE FOR IN ARROW ASSIGN
%token PLUS MINUS MULT DIVISION EXPOENT
%token AND OR NOT
%token EQUALS DIFF LESS GREATER LESSEQUALS GREATEREQUALS
%token INCREMENT DECREMENT
%token MATRIX

%right EXPOENT
%right ASSIGN
%left MULT DIVISION
%left PLUS MINUS
%left EQUALS DIFF LESS GREATER LESSEQUALS GREATEREQUALS
%left AND
%left OR
%left NOT

%type <sValue> sub_programs sub_program stmt stmts_list
%type <sValue> block param param_list dms
%type <sValue> stmt_array stmt_matrix dms_acess matrix_acess matrix_twod
%type <sValue> expr term factor exp expr_list args

%start program

%%

program : sub_programs { }
        ;

sub_programs : sub_programs sub_program {}
             | sub_program {}
             ;

sub_program : FUNCTION ID '(' param_list ')' ARROW TYPE block {}
            ;

param_list : {}
           | param ',' param_list {}
           | param {}
           ;

param : ID ':' TYPE {}
      | ID ':' TYPE dms {}
      |
      | ID ':' MATRIX {}
      ;

block : '{' stmts_list '}'
      ;

stmts_list : stmt ';' {}
           | stmt ';' stmts_list
           ;

stmt : ID ASSIGN expr {}
     | ID ':' TYPE ASSIGN expr {}
     | ID ASSIGN '(' expr ')' {} // acho que pode tirar, talvez seja redundante
     | ID '+=' expr {}
     | ID '-=' expr {}
     | ID '[' expr ':' expr ']' ASSIGN expr {} // slice de array
     | IF condition block {}
     | IF condition block ELSE block {}
     | WHILE condition block {}
     | FOR ID IN ID block {}
     | stmt_array {}
     | stmt_matrix {}
     | expr {} // permito coisas como chamada de função e incremento e decremento em todo lugar
     ;

stmt_array : ID '[' expr ':' expr ']' ASSIGN expr {}
           | ID ':' TYPE dms ASSIGN expr {}
           | ID dms_acess ASSIGN expr {}
           ;

stmt_matrix : ID ':' MATRIX ASSIGN expr {} // matriz padrão com 2 dimensões
            | ID ':' MATRIX '[' expr ']' ASSIGN expr {}  // define quantas dimensões são
            | ID matrix_twod ASSIGN expr {}
            | ID matrix_acess ASSIGN expr {}
            ;

matrix_twod : '[' expr ']' '[' ']' {} // aqui devolveria apenas a linha que ele quer, apenas para 2d
             | '[' ']' '[' expr ']' {} // aqui devolveria apenas a coluna que ele quer, apenas para 2d
             ;

matrix_acess : '[' expr ']' '[' expr ']' {}
             | '[' expr ']' '[' expr ']' dms_acess {}

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
exp : '(' expr ')' {}
    | '-' expr {} // semanticamente, como faço isso voltar sendo um -float por exemplo? 
    | ID {}
    | NUMBER {}
    | FLOAT {}
    | STRING {}
    | ID dms_acess {} 
    | ID '[' expr  ':' expr ']' {} // slice de array
    | ID '(' args ')' {} // chamada de função
    | '[' expr_list ']' {}
    | dms {}
    | ID INCREMENT {}
    | ID DECREMENT {}
    | ID matrix_twod {}
    | ID matrix_acess {}
    ;

expr_list : expr {}
          | expr ',' expr_list {}
          ;

args : {}
     | expr {}
     | expr ',' args {}
     ;

int main(void) {
     return yyparse();
}

int yyerror(char *msg){
     fprintf(stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
     return 0;
}