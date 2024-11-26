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
  void addToken(const char *type, const char *value) {
      strcpy(tokens[tokenCount].type, type);
      strcpy(tokens[tokenCount].value, value);
      tokenCount++;
  }
%}

%%

[ \t\n]               ;
[0-9]+                { addToken("NUMBER", yytext); }
"begin"               { addToken("BEGIN", ""); }
"end"                 { addToken("END", ""); }
"do"                  { addToken("DO", ""); }
[iI][fF]              { addToken("IF", ""); }
"then"                { addToken("THEN", ""); }
"else"                { addToken("ELSE", ""); }
"("                   { addToken("LPARENTHESIS", ""); }
")"                   { addToken("RPARENTHESIS", ""); }
"{"                   { addToken("LKEY", ""); }
"}"                   { addToken("DKEY", ""); }
"["                   { addToken("LBRACKET", ""); }
"]"                   { addToken("DBRACKET", ""); }
":"                   { addToken("COLON", ""); }
";"                   { addToken("SEMICOLON", ""); }
"="                   { addToken("ASSIGNMENT", ""); }
"+="                  { addToken("PLUSEQUAL", ""); }
","                   { addToken("COMMA", ""); }
"=="                  { addToken("EQUALS", ""); }
"-"                   { addToken("MINUS", ""); }
"+"                   { addToken("PLUS", ""); }
"*"                   { addToken("MULTIPLICATION", ""); }
"/"                   { addToken("DIVISION", ""); }
"++"                  { addToken("INCREMENT", ""); }
"<"                   { addToken("LESST", ""); }
">"                   { addToken("GREATERT", ""); }
"while"               { addToken("WHILE", ""); }
"for"                 { addToken("FOR", ""); }
"in"                  { addToken("IN", ""); }
"def"                 { addToken("FUNCTION", ""); }
"->"                  { addToken("ARROW", ""); }
"int"|"void"|"float"|"double" { addToken("TYPE", yytext); }
[a-zA-Z][a-zA-Z0-9]*  { addToken("ID", yytext); }
[\/\/.*]              { /* Ignorar comentários de linha única */ }
.                     { addToken("INVALID", yytext); }

%%

int main(void)
{
    yylex();
    // Salvar os tokens em um ficheiro ou processá-los
    for (int i = 0; i < tokenCount; i++) {
        printf("Token: %s, Value: %s\n", tokens[i].type, tokens[i].value);
    }
    return 0;
}
