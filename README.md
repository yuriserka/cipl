# C-IPL

> C-like language with native list suport

## Usage

```shell
./tradutor tests/{input}.cipl (> {output}.txt)?
./tac-module/tac tests/{input}.cipl (> {output}.txt)?
```

Running valgrind to check for memory leaks

```shell
make mem_check filename=tests/{input}.cipl
```

## Installation

```shell
sudo apt install flex gcc make bison
git submodule init && git submodule update
cd tac-module && ./autogen.sh && ./configure && make
cd .. && make
```

## Language Specification

### Data Types

- `float` -> stores a double number
- `int` -> stores a long int number
- `int list` -> stores a list of integers
- `float list` -> stores a list of reals

### NULL

- `NIL` -> similar to NULL from C and also used to initialize the list types

### Flow Control

- `return` -> same as C despite the fact that you always has to return some value
- `for` -> same as C despite the fact that you can't initialize a variable inside it
- `if` -> same as C
- `if-else` -> same as C

### I/O

- `read()` -> prompt user to scan an `int` or a `float`
- `write()` -> write to stdout a `int`, `float` or a `string literal`
- `writeln()` -> same as `write()` + new line

### Operators

- `:` -> **list cons:** _only applicable in lists_, used to append elements to the beggining of a list
- `<<` -> **list filter:** _only applicable in lists_, apply a function to every element of the list and return the elements whose the return is a truthy value
- `>>` -> **list map:** _only applicable in lists_, apply a function to every element of input list and return a new list
- `&&, ||` -> **boolean:** same as C
- `==, !=` -> **equality:** same as C
- `<, >, <=, >=` -> **comparison:** same as C and `NIL` cant be used as operand
- `+, -, *, /` -> **arithmetic:** same as C and `NIL` cant be used as operand
- `!` -> **exclamation:** if used in list returns its tail else return the truthy value of the number
- `?` -> **list head:** _only applicable in lists_, return the head
- `%` -> **list pop-tail:** _only applicable in lists_, return the tail and pop the head

## Author

Yuri Serka do Carmo Rodrigues - 17/0024385

## License

[MIT](./LICENSE)
