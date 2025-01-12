%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(char *s);
extern char * yytext;
%}

%union {
    char *sValue;
};

%token <sValue> ID
%token <sValue> NUMBER
%token <sValue> TYPE
%token IF THEN ELSE WHILE DO BEGIN END ASSIGN
%token PLUS MINUS MULT DIVISION EXPOENT

%type <sValue> stmt stmts_list expr term factor expr

%start program

%%

program : sub_programs { }
        ;

sub_programs : sub_programs sub_program {}
             | sub_program {}
             ;

sub_program : FUNCTION ID '(' param_list ')' ARROW TYPE block {}
            ;

block : '{' stmts_list '}'
      ;

stmts_list : stmt {}
           | stmt ';' stmts_list
           ;

stmt : ID ASSIGN expr {}
     | IF expr THEN stmt {}
     | IF expr THEN stmt ELSE stmt {}
     | WHILE expr DO stmt {}
     | FOR ID IN ID stmt {}
     | sub_program {}
     | expr {}
     | block {}
     | ID param ASSIGN expr 
     ;

param_list : param ',' param_list {}
           | param {}
           ;

param : ID ':' TYPE {}
      |
      ;

expr : expr PLUS term {}
     | expr MINUS term {}
     | term
     ;

term : term MULT factor {}
     | term DIVISION factor {}
     | factor
     ;

factor : exp EXPOENT factor {}
       | exp
       ;

exp : '(' expr ')' {}
    | ID {}
    | NUMBER {}
    ;
