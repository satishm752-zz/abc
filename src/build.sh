lex scanner.l
yacc parser.y
g++ y.tab.c -ll -ly
./a.out hello.c

