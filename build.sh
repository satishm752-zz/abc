lex scanner.l
yacc parser.y
g++ y.tab.c -ll -ly -std=c++11
./a.out hello.c

