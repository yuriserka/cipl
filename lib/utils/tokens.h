#pragma once

typedef enum yytokentypes {
  IF = 258,
  ELSE,
  RETURN,
  BREAK,
  FOR,
  NIL,
  TYPE,
  INT_NUM,
  REAL_NUM,
  ID,
  ASSIGN,
  INCDECOP,
  APPENDLISTOP,
  BINOP8,  // //
  BINOP7,  // &&
  BINOP6,  // |
  BINOP5,  // ^
  BINOP4,  // &
  BINOP3,  // == !=
  BINOP2,  // > < >= <=
  BINOP1,  // >> <<
  UNIOP,
} TokenTypes;
