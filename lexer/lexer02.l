%{
  #include <stdio.h>  
%}

%%

// Tokens: estruturas de controle, funções, loops, tipos numericos, ignorar comentarios
// O arquivo deve ser capaz de analisar o merge sort do ultimo trabalho
[ \t\n]               ;
[0-9]+                {printf("NUMBER(%s)\n",yytext);}
"while"               {printf("WHILE\n");}
"begin"               {printf("BEGIN\n");}
"end"                 {printf("END\n");}
"do"                  {printf("DO\n");}
[iI][fF]              {printf("IF\n");}
"then"                {printf("THEN\n");}
"else"                {printf("ELSE\n");}
"{"                   {printf("OPENKEY\n");}
"}"                   {printf("CLOSEKEY\n");}
":"                   {printf("COLON\n");}
";"                   {printf("SEMICOLON\n");}
":="                  {printf("ASSIGNMENT\n");}
"for"                 {printf("FOR\n");}
"in"                  {printf("IN");}
[a-zA-Z][a-zA-Z0-9]*	{printf("ID(%s)\n",yytext);}
.                     {printf("Invalid character.\n");}

%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif

// @to do use argv and argc 
//nome de executavel, entrada e saida
// flags para compilar no GCC -ll -lfl

int main(void)
{
  yylex();  
  return 0;
}