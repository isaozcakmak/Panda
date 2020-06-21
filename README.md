# SPI (Simple Pascal Interpreter)

This is a simple interpreter, which I have been writing in C++. It's based on a series ["Let's Build A Simple Interpreter"](https://ruslanspivak.com/lsbasi-part1/). I highly recommend it to you.

This branch is a basic calculator.

For now, the interpreter supports following stuff:
- Binary operations: '+', '-', '*', and '/';
- Unary operations: '+', '-';
- Parenthesized expressions with arbitrary depth nesting.

### Grammar
```
    expr : ((PLUS | MINUS) term)*

    term : factor ((MUL |DIV) factor)*

    factor : (PLUS| MINUS) factor 
		    | INTEGER 
		    | LPAREN expr RPAREN

```
### How to use
```
> Spi.exe test.txt
```