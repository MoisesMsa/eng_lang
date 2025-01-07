%{
#include "parser.tab.h"         // Incluindo o arquivo gerado pelo Bison
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isUnaryMinus = 1;           // Variável para controlar se o MINUS é unário ou binário

void addToken(const char *tokenType, const char *value) {
    printf("Token: %s, Value: %s\n", tokenType, value);
}
%}

%%

[\n]                            {yylineno++;}
[ \t\r]+                      { /* Ignorar espaços em branco */ }
[0-9]+                          { yylval.ival = atoi(yytext); isUnaryMinus = 0; return NUMBER; }
[0-9]+\.[0-9]+                  { yylval.fval = atof(yytext); return FLOAT; }
"print"                         { return PRINT; }
"do"                            { return DO; }
[iI][fF]                        { return IF; }
"else"                          { return ELSE; }
"while"                         { return WHILE; }
"for"                           { return FOR; }
"in"                            { return IN; }
"def"                           { return FUNCTION; }
"->"                            { return ARROW; }
"int"|"void"|"float"|"double"   { yylval.sval = strdup(yytext); return TYPE; }
[a-zA-Z_][a-zA-Z0-9_]*          { yylval.sval = strdup(yytext); isUnaryMinus = 0; return ID; }
"+"                             { return PLUS; }
"-"                             {
                                    if (isUnaryMinus) {
                                        isUnaryMinus = 0; 
                                        return UMINUS;  // Tratar como operador unário
                                    } else {
                                        return MINUS;   // Tratar como operador binário
                                    }
                                }
"*"                             { return TIMES; }
"/"                             { return DIVIDE; }
"="                             { return ASSIGNMENT; }
"=="                            { return EQUALS; }
"!="                            { return NOTEQUALS; }
"<"                             { return LESSTHAN; }
">"                             { return GREATERTHAN; }
"<="                            { return LESSEQUAL; }
">="                            { return GREATEREQUAL; }
"+="                            { return PLUSEQUAL; }
"++"                            { return INCREMENT; }
"("                             { return LPAREN; }
")"                             { return RPAREN; }
"{"                             { return LBRACE; }
"}"                             { return RBRACE; }
"["                             { return LBRACKET; }
"]"                             { return RBRACKET; }
":"                             { return COLON; }
";"                             { return SEMICOLON; }
","                             { return COMMA; }
"^"                             { return POWER; }
\"(\\.|[^\"])*\"                { yylval.sval = strdup(yytext); return STRING; }
[\/\/].*                        { /* Ignorar comentários de linha única */ }
.                               { 
                                    fprintf(stderr, "Lexer: Caractere inválido: %s\n", yytext);
                                }
%%

int yywrap(void) {
    return 1;
}
