# SPI (Simple Pascal Interpreter)

This is a simple interpreter, which I have been writing in C++. It's based on a series ["Let's Build A Simple Interpreter"](https://ruslanspivak.com/lsbasi-part1/). I highly recommend it to you.

For now, the interpreter supports following stuff:
- PROGRAM keyword;
- Block for declaration variables, which starts with VAR keyword;
- BEGIN ... END blocks;
- Assignment operator ':=';
- Integer and real variables;
- Binary operations: '+', '-', '*', 'div' and '/';
- Unary operations: '+', '-';
- Parenthesized expressions with arbitrary depth nesting.

### Grammar
```
	program : PROGRAM variable SEMI block DOT

    block : declarations compound_statement

    declarations : VAR (variable_declaration SEMI)+
                 | empty

    variable_declaration : ID (COMMA ID)* COLON type_spec

    type_spec : INTEGER | REAL

    compound_statement : BEGIN statement_list END

    statement_list : statement
                   | statement SEMI statement_list

    statement : compound_statement
              | assignment_statement
              | empty

    assignment_statement : variable ASSIGN expr

    empty :

    expr : term ((PLUS | MINUS) term)*

    term : factor ((MUL | INTEGER_DIV | FLOAT_DIV) factor)*

    factor : PLUS factor
           | MINUS factor
           | INTEGER_CONST
           | REAL_CONST
           | LPAREN expr RPAREN
           | variable

    variable: ID
```
### How to use
```
> Spi.exe test.pas
```