# C-IPL

> C-like language with native list suport

## Usage

```shell
flex lex-def.l
gcc -o mylex.out -O lex.yy.c -lfl
./mylex.out < tests/<program>.cipl
```

Running valgrind to check for memory leaks

```shell
make mem_check
```

## Installation

```shell
sudo apt install flex bison gcc make autoconf
autoreconf --install
./configure
make
```

## Author

Yuri Serka do Carmo Rodrigues - 17/0024385

## License

[MIT](./LICENSE)
