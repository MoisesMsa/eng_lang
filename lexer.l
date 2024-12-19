%{
#include "parser.tab.h"  // Incluindo o arquivo gerado pelo Bison

int isUnaryMinus = 1;    // Variável para controlar se o MINUS é unário ou binário
%}

%%

[0-9]+             { yylval.ival = atoi(yytext); isUnaryMinus = 0; return NUMBER; }
[0-9]+\.[0-9]+     { yylval.fval = atof(yytext); return FLOAT; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.sval = strdup(yytext); isUnaryMinus = 0; return ID; }
"+"                 { return PLUS; }
"-"                 {
                     if (isUnaryMinus) {
                         isUnaryMinus = 0;  // Após o MINUS ser reconhecido, ele deixa de ser unário
                         return UMINUS;      // Tratar como operador unário
                     } else {
                         return MINUS;      // Tratar como operador binário
                     }
                    }
"*"                 { return TIMES; }
"/"                 { return DIVIDE; }
"^"                 { return POWER; }
"="                 { return ASSIGNMENT; }
"=="                { return EQUALS; }
"!="                { return NOTEQUALS; }
"<"                 { return LESSTHAN; }
">"                 { return GREATERTHAN; }
"<="                { return LESSEQUAL; }
">="                { return GREATEREQUAL; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
";"                 { return SEMICOLON; }
","                 { return COMMA; }
":"                 { return COLON; }
"++"                { return INCREMENT; }
"--"                { return DECREMENT; }

[ \t\n\r]+          { /* Ignorar espaços em branco */ }
.                   { 
                        fprintf(stderr, "Caractere inválido: %s\n", yytext); 
                    }

%%

int yywrap(void) {
    return 1;
}
