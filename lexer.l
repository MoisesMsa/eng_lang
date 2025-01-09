%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
%}

%%

[ \t\n]               ;
[0-9]+                { yyval.sValue = strdup(yytext); 
                        return NUMBER;}
"begin"               { return(BEGIN); }
"end"                 { return(END); }
"do"                  { return(DO); }
[iI][fF]              { return(IF); }
"then"                { return(THEN); }
"else"                { return(ELSE); }
"("                   { return(yytext[0]); }
")"                   { return(yytext[0]); }
"{"                   { return(yytext[0]); }
"}"                   { return(yytext[0]); }
"["                   { return(yytext[0]); }
"]"                   { return(yytext[0]); }
":"                   { return(COLON); }
";"                   { return(yytext[0]); }
"="                   { return(ASSIGN); }
"+="                  { return(PLUSEQUAL); }
","                   { return(COMMA); }
"=="                  { return(EQUALS); }
"-"                   { return(MINUS); }
"+"                   { return(PLUS); }
"*"                   { return(MULT); }
"/"                   { return(DIVISION); }
"**"                  { return (EXPOENT); }
"++"                  { return(INCREMENT); }
"<"                   { return(LESST); }
">"                   { return(GREATERT); }
"while"               { return(WHILE); }
"for"                 { return(FOR); }
"in"                  { return(IN); }
"def"                 { return(FUNCTION); }
"->"                  { return(ARROW); }
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
    // Salvar os tokens em um ficheiro ou processá-los
    for (int i = 0; i < tokenCount; i++) {
        printf("Token: %s, Value: %s\n", tokens[i].type, tokens[i].value);
    }
    return 0;
}
