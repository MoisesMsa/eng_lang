### Compilação:

```flex lexer/lexer.l```
```gcc lex.yy.c -o lexerApp```

(checar se precisa usar as flags -ll ou -lfl)

### Execução
```./lexerApp < assets/test/mergesort.txt```
