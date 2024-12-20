CC = gcc
LEX = flex
BISON = bison

# Nome do executável
EXEC = parser

# Incluir o arquivo node.h para garantir a definição das estruturas
INCLUDES = -I./includes

all: $(EXEC)

$(EXEC): parser.tab.c lex.yy.c
	$(CC) $(INCLUDES) -o $(EXEC) parser.tab.c lex.yy.c -lfl -lm

parser.tab.c parser.tab.h: parser.y
	$(BISON) -d parser.y -Wcounterexamples

lex.yy.c: lexer.l
	$(LEX) lexer.l

clean:
	rm -f $(EXEC) parser.tab.c parser.tab.h lex.yy.c
