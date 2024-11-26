### Compilação:

```flex lexer/lexer.l```
```gcc lex.yy.c -o lexerApp -lfl```

(checar se precisa usar as flags -ll ou -lfl)

```gcc interpretador.c -o interpretador```

### Execução
```./lexerApp < assets/test/mergesort.txt > tokens.txt```
```./interpretador```