# C-Onjunto

> C-like language with native set suport

background details relevant to understanding what this module does

## Usage

```shell
flex lex-def.l
gcc -o mylex -O lex.yy.c -lfl
./mylex < tests/<program>.my-lang
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
