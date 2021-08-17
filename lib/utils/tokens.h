#pragma once

typedef enum yytokentypes {
  IF = 258,
  ELSE,
  RETURN,
  FOR,
  NIL,
  TYPE,
  INT_NUM,
  REAL_NUM,
  ID,
  ASSIGN, // =
  LISTCTR, // :
  BOOLOP,  // || &&
  EQOP,  // == !=
  INEQOP,  // > < >= <=
  LISTFNOP,  // >> <<
  ARITHOP, // + - * /
  UNARYOP, // ! ? % - +
} TokenTypes;
