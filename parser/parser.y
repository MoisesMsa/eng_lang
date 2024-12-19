%{
#inclued <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(char * 5);
extern char * yytext;
%}

%union {
    char *sValue;
};

%token <sValue> ID
%token <sValue> NUMBER
%token IF THEN ELSE WHILE DO BEGIN END ASSIGN
%token PLUS MINUS MULT DIVISION 

%type <sValue>