%{
  #include "parser.tab.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  extern int yyerror(char *msg);
%}

%%

[\n]                  {yylineno++;}
[ \t\r]               {}
[0-9]+                { yylval.sValue = strdup(yytext); 
                        return NUMBER;}
[0-9]+\.[0-9]+        { yylval.sValue = strdup(yytext);
                        return FLOAT;}
\"(\\.|[^\"])*\"      { yylval.sValue = strdup(yytext);
                        return STRING;}
[iI][fF]              { return(IF); }
"else"                { return(ELSE); }
"("                   { return(yytext[0]); }
")"                   { return(yytext[0]); }
"{"                   { return(yytext[0]); }
"}"                   { return(yytext[0]); }
"["                   { return(yytext[0]); }
"]"                   { return(yytext[0]); }
":"                   { return(yytext[0]); }
";"                   { return(yytext[0]); }
"="                   { return(ASSIGN); }
"+="                  { return(INCREMENT_ASSIGN); }
"-="                  { return(DECREMENT_ASSIGN);}
","                   { return(yytext[0]); }
"=="                  { return(EQUALS); }
"!="                  { return(DIFF); }
"!"                   { return(NOT); }
"-"                   { return(MINUS); }
"+"                   { return(PLUS); }
"*"                   { return(MULT); }
"/"                   { return(DIVISION); }
"**"                  { return(EXPOENT); }
"++"                  { return(INCREMENT); }
"--"                  { return(DECREMENT); }
"<"                   { return(LESS); }
">"                   { return(GREATER); }
">="                  { return(GREATEREQUALS); }
"<="                  { return(LESSEQUALS); }
"and"                 { return(AND); }
"or"                  { return(OR); }
"while"               { return(WHILE); }
"for"                 { return(FOR); }
"in"                  { return(IN); }
"def"                 { return(FUNCTION); }
"->"                  { return(ARROW); }
"matrix"              { return(MATRIX); }
"struct"              { return(STRUCT); }
"true"|"false"        { yylval.sValue = strdup(yytext);
                        return(BOOL);}
"int"|"void"|"float"|"double" { yylval.sValue = strdup(yytext);
                                return(TYPE); }
[a-zA-Z][a-zA-Z0-9]*  { yylval.sValue = strdup(yytext);
                        return(ID); }
[\/\/.*]              { /* Ignorar comentários de linha única */ }
.                     { yyerror("Caractere invalido"); }

%%

#ifndef yywrap
    int yywrap(void) {return 1;}
#endif
