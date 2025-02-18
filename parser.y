%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./includes/record.h"

int yylex(void);
int yyerror(char *s);
extern char * yytext;
extern int yylineno;

char * cat(char *, char *, char *, char *, char *);
%}

// sera se vai ser preciso criar um union para arrays e matrizes? 
// do tipo struct que vai ter linhas e colunas
%union {
	char * sValue;  /* string value */
	struct record * rec;
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

%left NOT AND OR

%type <rec> sub_programs sub_program stmt stmts_list structs declaration declarations
%type <rec> block param param_list dms condition
%type <rec> stmt_array stmt_matrix dms_acess matrix_twod
%type <rec> expr term factor exp expr_list args

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

declaration : ID ':' TYPE ';' {
                $$ = createRecord($1, "");
                free($1);
              }
            | ID ':' TYPE dms ';' {
               //int matriz[valor]  
               char * s1 = cat($3, " ", $1, $4->code, "");
               printf("%s", s1);
               free($3);
               free($1);
               free($4);
               $$ = createRecord(s1, "");
               free(s1);
            }
            | ID ':' MATRIX ';' {}
            ;

//@todo add opção de vazio
sub_programs : sub_programs sub_program {
                char * s = cat($1->code, "\n", $2->code, "", "");
                freeRecord($1);
                freeRecord($2);
                $$ = createRecord(s, "");
                free(s);
               }
             | sub_program {
                $$ = createRecord($1->code, "");
                free($1);
             }
             ;

sub_program : FUNCTION ID '(' param_list ')' ARROW TYPE block {
               //int name(args) { code }
               char * s1 = cat($7, " ", $2, "(", $4->code);
               char * s2 = cat(s1, ")\n", "{\n", $8->code, "}");
               free(s1);
               free($7);
               free($2);
               freeRecord($4);
               freeRecord($8);
               $$ = createRecord(s2, "");
               free(s2);
             }
            | FUNCTION ID '(' param_list ')' block {
               //void name(args) { code }
               char * s1 = cat("void", " ", $2, "(", $4->code);
               char * s2 = cat(s1, ")\n", "{\n", $6->code, "}");
               free(s1);
               free($2);
               freeRecord($4);
               freeRecord($6);
               $$ = createRecord(s2, "");
               free(s2);
            }
            ;

param_list : param {

          }
          | param ',' param_list {
             
          }
          ;

param : ID ':' TYPE {}
      | ID ':' TYPE dms {}
      | %empty {}
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
       | %empty {}
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
//@todo remover dms_access? ou por no formato ID[]
dms_acess : ID '[' expr ']' {}
          | ID '[' expr ']' dms_acess {}

//obs: a matriz precisa sempre ser declarada com um tamanho
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

args : %empty {}
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

char * cat(char * s1, char * s2, char * s3, char * s4, char * s5){
  int tam;
  char * output;

  tam = strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) + strlen(s5)+ 1;
  output = (char *) malloc(sizeof(char) * tam);
  
  if (!output){
    printf("Allocation problem. Closing application...\n");
    exit(0);
  }
  
  sprintf(output, "%s%s%s%s%s", s1, s2, s3, s4, s5);
  
  return output;
}