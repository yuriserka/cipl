#include "data-structures/symbol-table/symbol.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/globals.h"
#include "data-structures/context.h"
#include "utils/io.h"

Symbol *symbol_init(char *name, SymbolTypes type, SymbolKinds kind, int scope,
                    char *ctx_name, int temp, Cursor pos) {
  Symbol *sym = calloc(1, sizeof(Symbol));
  symbol_update(sym, name, type, kind, scope, ctx_name, temp, pos);
  symbol_init_value(sym);
  return sym;
}

void symbol_update_type(Symbol *sym, SymbolTypes type) { sym->type = type; }

Symbol *symbol_init_copy(Symbol *other) {
  return symbol_init(other->name, other->type, other->kind, other->scope,
                     other->context_name, other->temp, other->def_pos);
}

Symbol *symbol_found(char *name, Cursor pos) {
  return symbol_init(name, SYM_INVALID, false, 0, NULL, -1, pos);
}

void symbol_update_context(Symbol *sym, Context *ctx) {
  sym->context_name = ctx->name;
  sym->scope = ctx->current_scope;
}

void symbol_update_temp(Symbol *sym, int temp_num) { sym->temp = temp_num; }

void symbol_update(Symbol *sym, char *name, SymbolTypes type, SymbolKinds kind,
                   int scope, char *ctx_name, int temp, Cursor pos) {
  sym->name = name ? strdup(name) : NULL;
  sym->context_name = ctx_name;
  sym->scope = scope;
  sym->def_pos = pos;
  sym->type = type;
  sym->kind = kind;
  sym->temp = temp;
}

void symbol_free(Symbol *sym) {
  if (!sym) return;

  if (sym->name) free(sym->name);

  switch (sym->type) {
    case SYM_INT_LIST:
    case SYM_REAL_LIST:
      list_free(sym->value.list, NULL);
    default:
      break;
  }

  free(sym);
}

void symbol_print(Symbol *sym) {
  printf(
      "{ name: '%s', type: %s%s, declared_at: '%s:%d:%d', ctx: '%s', scope: "
      "%d}, ",
      sym->name, sym->kind == FUNC ? "SYM_FUNC " : "",
      symbol_type_from_enum(sym->type), filename, sym->def_pos.line,
      sym->def_pos.col, sym->context_name, sym->scope);
}

void symbol_print_pretty(Symbol *sym) {
  const char *color = sym->kind == FUNC ? BBLU : BCYN;
  CIPL_PRINTF_COLOR(BGRN,
                    "%s%s "
                    "%s"
                    "%s " BHWHT "@%d:%d\n",
                    sym->kind == FUNC ? "SYM_FUNC " : "",
                    symbol_type_from_enum(sym->type), color, sym->name,
                    sym->def_pos.line, sym->def_pos.col);
  // disable value print
  if (0) {
    printf(BHBLK " #");
    switch (sym->type) {
      case SYM_REAL_LIST: {
        if (!sym->value.list) {
          printf("NIL");
        } else {
          printf("[");
          LIST_FOR_EACH(sym->value.list, {
            printf("%lf%s", *((double *)__IT__->data),
                   __IT__->next ? ", " : "");
          });
          printf("]");
        }
      } break;
      case SYM_INT_LIST: {
        if (!sym->value.list) {
          printf("NIL");
        } else {
          printf("[");
          LIST_FOR_EACH(sym->value.list, {
            printf("%d%s", *((int *)__IT__->data), __IT__->next ? ", " : "");
          });
          printf("]");
        }
      } break;
      case SYM_INT:
        printf("%d", sym->value.integer);
        break;
      case SYM_REAL:
        printf("%lf", sym->value.real);
        break;
      default:
        printf("NULL");
    }
    printf("\n" RESET);
  }
}

SymbolTypes symbol_type_from_str(char *type) {
  if (!type) return SYM_INVALID;

  if (!strcmp(type, "int")) return SYM_INT;
  if (!strcmp(type, "float")) return SYM_REAL;
  if (!strcmp(type, "int list")) return SYM_INT_LIST;
  if (!strcmp(type, "float list")) return SYM_REAL_LIST;

  return SYM_INVALID;
}

char *symbol_type_from_enum(SymbolTypes type) {
  switch (type) {
    case SYM_INT:
      return "SYM_INT";
    case SYM_INT_LIST:
      return "SYM_INT_LIST";
    case SYM_REAL:
      return "SYM_REAL";
    case SYM_REAL_LIST:
      return "SYM_REAL_LIST";
    case SYM_PTR:
      return "SYM_PTR";
    default:
      return "SYM_INVALID";
  }
}

char *symbol_canonical_type_function(AST *func_declarator) {
  AST *func_decl;
  AST_FIND_NODE(root, AST_USER_FUNC,
                {
                  AST *key = list_peek(&__AST__->children, 0);
                  if (!strcmp(key->value.symref->symbol->name,
                              func_declarator->value.symref->symbol->name)) {
                    func_decl = __AST__;
                    __FOUND__ = 1;
                  }
                },
                {});
  AST *func_decl_params = list_peek(&func_decl->children, 1);
  ParamsAST *params_l = func_decl_params->value.params;
  char *tmp = calloc(1024, sizeof(char));
  sprintf(tmp, "%s (",
          symbol_canonical_type_from_enum(func_declarator->value_type));
  LIST_FOR_EACH(params_l->value, {
    AST *param = __IT__->data;
    strcat(tmp, symbol_canonical_type_from_enum(param->value_type));
    strcat(tmp, __IT_NXT__ ? ", " : "");
  });
  strcat(tmp, ")");
  return tmp;
}

char *symbol_canonical_type_from_enum(SymbolTypes type) {
  switch (type) {
    case SYM_INT:
      return "int";
    case SYM_INT_LIST:
      return "int list";
    case SYM_REAL:
      return "float";
    case SYM_REAL_LIST:
      return "float list";
    case SYM_PTR:
      return "NIL";
    default:
      return "SYM_INVALID";
  }
}

void symbol_init_value(Symbol *sym) {
  switch (sym->type) {
    case SYM_INT:
      sym->value = (SymbolValues){.integer = 0};
      break;
    case SYM_REAL:
      sym->value = (SymbolValues){.real = 0.0};
      break;
    case SYM_INT_LIST:
    case SYM_REAL_LIST:
      sym->value = (SymbolValues){.list = NULL};
      break;
    default:
      break;
  }
}

void symbol_update_value(Symbol *sym, int mArgs, ...) {
  va_list ptr;
  va_start(ptr, mArgs);

  switch (sym->type) {
    case SYM_INT:
    case SYM_INVALID:
      sym->value = (SymbolValues){.integer = va_arg(ptr, int)};
      break;
    case SYM_REAL:
      sym->value = (SymbolValues){.real = va_arg(ptr, double)};
      break;
    case SYM_INT_LIST: {
      int *elemp = calloc(1, sizeof(int));
      *elemp = va_arg(ptr, int);
      list_push(&sym->value.list, elemp);
    } break;
    case SYM_REAL_LIST: {
      double *elemp = calloc(1, sizeof(double));
      *elemp = va_arg(ptr, double);
      list_push(&sym->value.list, elemp);
    } break;
    default:
      break;
  }

  va_end(ptr);
}

bool can_assign(SymbolTypes lhs, SymbolTypes rhs) {
  SymbolTypes max_t = MAX(lhs, rhs);
  if (max_t >= SYM_PTR) {
    if (lhs < SYM_PTR || rhs < SYM_PTR) {
      return false;
    } else {
      return (rhs == SYM_PTR) || (lhs == rhs);
    }
  }
  return true;
}

bool can_arith(SymbolTypes lhs, SymbolTypes rhs) {
  return MAX(lhs, rhs) < SYM_PTR;
}

bool can_compare(SymbolTypes lhs, SymbolTypes rhs) {
  SymbolTypes max_t = MAX(lhs, rhs);
  if (max_t >= SYM_PTR) {
    if (lhs < SYM_PTR || rhs < SYM_PTR) {
      return false;
    } else {
      return (rhs == SYM_PTR) || (lhs == rhs);
    }
  }
  return true;
}

bool can_mapfil_list(SymbolTypes lhs, SymbolTypes rhs) {
  return MAX(lhs, rhs) > SYM_PTR;
}

bool can_cons_list(SymbolTypes lhs, SymbolTypes rhs) {
  if (rhs < SYM_PTR || lhs >= SYM_PTR) return false;
  return can_assign(rhs - SYM_PTR, lhs);
}

bool can_cast(SymbolTypes type1, SymbolTypes type2) {
  return type1 < SYM_PTR && type2 < SYM_PTR && type1 != type2;
}
