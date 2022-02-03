exp: lex.yy.o y.tab.o
	gcc -o sclp lex.yy.o y.tab.o -ly -ll 

y.tab.o y.tab.h : parser.y 
	yacc -dv parser.y 
	gcc -c y.tab.c

lex.yy.o : lexer.l y.tab.h
	lex lexer.l
	gcc -c lex.yy.c 

clean:
	rm -f lex.yy.* y.tab.* y.output a.out parser *.log *.toks

	
