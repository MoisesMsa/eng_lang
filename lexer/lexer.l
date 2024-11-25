%{
  #include <stdio.h>  
%}

%%

[ \t\n]               ;
[0-9]+                {printf("NUMBER(%s)\n",yytext);}
"begin"               {printf("BEGIN\n");}
"end"                 {printf("END\n");}
"do"                  {printf("DO\n");}
[iI][fF]              {printf("IF\n");}
"then"                {printf("THEN\n");}
"else"                {printf("ELSE\n");}
"("                   {printf("LPARENTHESIS\n");}
")"                   {printf("RPARENTHESIS\n");}
"{"                   {printf("LKEY\n");}
"}"                   {printf("DKEY\n");}
"["                   {printf("LBRACKET\n");}
"]"                   {printf("DBRACKET\n");}
":"                   {printf("COLON\n");}
";"                   {printf("SEMICOLON\n");}
":="                  {printf("ASSIGNMENT\n");}
"+="                  {printf("PLUSEQUAL\n");}
","                   {printf("COMMA\n");}
"="                   {printf("EQUALS\n");}
"-"                   {printf("MINUS\n");}
"+"                   {printf("PLUS\n");}
"*"                   {printf("MULTIPLICATION\n");}
"/"                   {printf("DIVISION\n");}
"++"                  {printf("INCREMENT\n");}
"<"                   {printf("LESST\n");}
">"                   {printf("GREATERT\n");}
"while"               {printf("WHILE\n");}
"for"                 {printf("FOR\n");}
"in"                  {printf("IN\n");}
"def"                 {printf("FUNCTION\n");}
"->"                  {printf("ARROW\n");}
"int"|"void"|"float"|"double" { printf("TYPE(%s)\n", yytext); }
[a-zA-Z][a-zA-Z0-9]*	{printf("ID(%s)\n",yytext);}
[\/\/.*]    { /* Ignorar comentários de linha única */ }
.                     {printf("Invalid character.\n");}

%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif


int main(void)
{
  yylex();  
  return 0;
}