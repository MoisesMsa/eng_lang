%{
  #include "parser.tab.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
%}

%%

[\n]                  {yylineno++;}
[ \t\r]               {}
[0-9]+                { yyval.sValue = strdup(yytext); 
                        return NUMBER;}
[0-9]+\.[0-9]+        { yyval.sValue = strdup(yytext);
                        return FLOAT;}
\"(\\.|[^\"])*\"      { yyval.sValue = strdup(yytext);
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
"&&"                  { return(AND); }
"||"                  { return(OR); }
"while"               { return(WHILE); }
"for"                 { return(FOR); }
"in"                  { return(IN); }
"def"                 { return(FUNCTION); }
"->"                  { return(ARROW); }
"matrix"              { return(MATRIX); }
"int"|"void"|"float"|"double" { yyval.sValue = strdup(yytext);
                                return(TYPE); }
[a-zA-Z][a-zA-Z0-9]*  { yyval.sValue = strdup(yytext);
                        return(ID); }
[\/\/.*]              { /* Ignorar comentários de linha única */ }
.                     { yyval.sValue = strdup(yytext);
                        return(INVALID); }

%%

#ifndef yywrap
    int yywrap(void) {return 1;}
#endif

int main(void)
{
    yylex();
    return 0;
}
