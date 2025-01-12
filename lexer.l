%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
%}

%%

[ \t\n]               ;
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
"+="                  { return(yytext[0]); }
"-="                  { return(yytext[0]);}
","                   { return(yytext[0]); }
"=="                  { return(yytext[0]); }
"!="                  { return(yytext[0]); }
"!"                   { return(yytext[0]); }
"-"                   { return(MINUS); }
"+"                   { return(PLUS); }
"*"                   { return(MULT); }
"/"                   { return(DIVISION); }
"**"                  { return(EXPOENT); }
"++"                  { return(INCREMENT); }
"--"                  { return(DECREMENT); }
"<"                   { return(yytext[0]); }
">"                   { return(yytext[0]); }
">="                  { return(yytext[0]); }
"<="                  { return(yytext[0]); }
"&&"                  { return(yytext[0]); }
"||"                  { return(yytext[0]); }
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
