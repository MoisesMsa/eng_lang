%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // Estrutura para armazenar tokens
  typedef struct Token {
      char type[20];
      char value[100];
  } Token;

  Token tokens[1000];
  int tokenCount = 0;

  // Função para adicionar um token à lista
  void addToxken(const char *type, const char *value) {
      strcpy(tokens[tokenCount].type, type);
      strcpy(tokens[tokenCount].value, value);
      tokenCount++;
  }
%}

%%

[ \t\n]               ;
[0-9]+                { yyval.sValue = strdup{yytext} 
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
";"                   { return(SEMICOLON); }
"="                   { return(ASSIGN); }
"+="                  { return(PLUSEQUAL); }
","                   { return(COMMA); }
"=="                  { return(EQUALS); }
"-"                   { return(MINUS); }
"+"                   { return(PLUS); }
"*"                   { return(MULT); }
"/"                   { return(DIVISION); }
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
