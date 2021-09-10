/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "src/bison/grammar.y"

    #include <stdarg.h>
	#include <stdio.h>
    #include <string.h>
    #include <stdbool.h>

    #include "data-structures/ast/ast.h"
    #include "data-structures/stack.h"
    #include "data-structures/context.h"
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"

    AST *root;
    StackNode *scopes;
    ListNode *contexts;
    Cursor error_cursor;
    Context *current_context;
    Context *previous_context;
    StackNode *parent_stacknode_ref;
    char *last_line_ref;
    bool p_ctx_name = true, is_fn_blck = false;

    void free_scope_cb(StackNode *node) { scope_free(node->data); }

    StackNode *context_get_current_stacknode_ref() {
        LIST_FOR_EACH_REVERSE(current_context->scopes, {
            if (((Scope *)__IT__->data)->index == current_context->current_scope) {
                return __IT__;
            }
        });
        return NULL;
    }

    #define p_error_ctx_info {                                                       \
        if (p_ctx_name) {                                                            \
            if (current_context->current_scope) {                                    \
                CIPL_PRINTF(WHT "%s:" RESET " In function " BBLU "'%s'" RESET ":\n", \
                            filename, current_context->name);                        \
            } else {                                                                 \
                CIPL_PRINTF(WHT "%s:" RESET " At top level:\n", filename);           \
            }                                                                        \
            p_ctx_name = false;                                                      \
        }                                                                            \
    }

    #define show_error_range(__R__, __FMT__, ...) {                             \
        p_error_ctx_info;                                                       \
        Cursor beg = (Cursor){.line=__R__.first_line, .col=__R__.first_column}; \
        Cursor end = (Cursor){.line=__R__.last_line, .col=__R__.last_column};   \
        yyerror(end.line, end.col, NULL);                                       \
        LineInfo *li = list_peek(&lines, beg.line - 1);                         \
        li = li ? li : curr_line_info;                                          \
        CIPL_PERROR_CURSOR_RANGE(                                               \
            __FMT__,                                                            \
            li->text,                                                           \
            beg,                                                                \
            end,                                                                \
            ##__VA_ARGS__                                                       \
        );                                                                      \
        yyerrok;                                                                \
    }

    #define show_error(__R__, __FMT__, ...) {                  \
        p_error_ctx_info;                                      \
        yyerror(__R__.last_line, __R__.last_column, NULL);     \
        LineInfo *li = list_peek(&lines, __R__.last_line - 1); \
        li = li ? li : curr_line_info;                         \
        CIPL_PERROR_CURSOR(                                    \
            __FMT__,                                           \
            li->text,                                          \
            error_cursor,                                      \
            ##__VA_ARGS__                                      \
        );                                                     \
        yyerrok;                                               \
    }

    #define cleanup_expr_err(__OP__, __AST__) \
        { free(__OP__); ast_free(__AST__); }


#line 153 "src/bison/grammar.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison/grammar.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER_INT = 3,                 /* NUMBER_INT  */
  YYSYMBOL_NIL = 4,                        /* NIL  */
  YYSYMBOL_NUMBER_REAL = 5,                /* NUMBER_REAL  */
  YYSYMBOL_NAME = 6,                       /* NAME  */
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_WRITE = 8,                      /* WRITE  */
  YYSYMBOL_MULT = 9,                       /* MULT  */
  YYSYMBOL_ADD = 10,                       /* ADD  */
  YYSYMBOL_REL = 11,                       /* REL  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_COLON = 15,                     /* COLON  */
  YYSYMBOL_DL_DG = 16,                     /* DL_DG  */
  YYSYMBOL_EXCLAMATION = 17,               /* EXCLAMATION  */
  YYSYMBOL_PERCENT = 18,                   /* PERCENT  */
  YYSYMBOL_QUESTION = 19,                  /* QUESTION  */
  YYSYMBOL_STR_LITERAL = 20,               /* STR_LITERAL  */
  YYSYMBOL_INT = 21,                       /* INT  */
  YYSYMBOL_FLOAT = 22,                     /* FLOAT  */
  YYSYMBOL_LIST = 23,                      /* LIST  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_THEN = 28,                      /* THEN  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_prog = 37,                      /* prog  */
  YYSYMBOL_external_declaration_list = 38, /* external_declaration_list  */
  YYSYMBOL_external_declaration = 39,      /* external_declaration  */
  YYSYMBOL_var_declaration = 40,           /* var_declaration  */
  YYSYMBOL_41_1 = 41,                      /* @1  */
  YYSYMBOL_func_declaration = 42,          /* func_declaration  */
  YYSYMBOL_43_2 = 43,                      /* @2  */
  YYSYMBOL_44_3 = 44,                      /* $@3  */
  YYSYMBOL_45_param_list_opt = 45,         /* param_list.opt  */
  YYSYMBOL_params_list = 46,               /* params_list  */
  YYSYMBOL_param_decl = 47,                /* param_decl  */
  YYSYMBOL_compound_stmt = 48,             /* compound_stmt  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_50_block_item_list_opt = 50,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 51,           /* block_item_list  */
  YYSYMBOL_block_item = 52,                /* block_item  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_io_stmt = 54,                   /* io_stmt  */
  YYSYMBOL_expr_stmt = 55,                 /* expr_stmt  */
  YYSYMBOL_cond_stmt = 56,                 /* cond_stmt  */
  YYSYMBOL_jmp_stmt = 57,                  /* jmp_stmt  */
  YYSYMBOL_iter_stmt = 58,                 /* iter_stmt  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_60_expression_opt = 60,         /* expression.opt  */
  YYSYMBOL_logical_or_expr = 61,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 62,          /* logical_and_expr  */
  YYSYMBOL_eq_expr = 63,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 64,                  /* rel_expr  */
  YYSYMBOL_list_expr = 65,                 /* list_expr  */
  YYSYMBOL_add_expr = 66,                  /* add_expr  */
  YYSYMBOL_mult_expr = 67,                 /* mult_expr  */
  YYSYMBOL_unary_expr = 68,                /* unary_expr  */
  YYSYMBOL_unary_ops = 69,                 /* unary_ops  */
  YYSYMBOL_postfix_expr = 70,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 71,             /* arg_expr_list  */
  YYSYMBOL_72_arg_expr_list_opt = 72,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 73,              /* primary_expr  */
  YYSYMBOL_id = 74,                        /* id  */
  YYSYMBOL_type = 75,                      /* type  */
  YYSYMBOL_constant = 76,                  /* constant  */
  YYSYMBOL_string_literal = 77             /* string_literal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9740

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  655

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   130,   130,   131,   134,   135,   138,   139,   140,   147,
     147,   169,   174,   182,   217,   182,   224,   233,   234,   237,
     238,   239,   245,   259,   259,   272,   273,   276,   277,   280,
     281,   284,   285,   286,   287,   288,   289,   292,   299,   304,
     309,   314,   321,   324,   327,   330,   335,   340,   346,   353,
     354,   360,   363,   370,   377,   386,   387,   388,   395,   396,
     399,   400,   404,   409,   416,   417,   421,   426,   433,   434,
     438,   443,   450,   451,   455,   460,   467,   468,   472,   476,
     481,   486,   491,   498,   499,   503,   508,   515,   516,   520,
     525,   532,   533,   539,   540,   541,   542,   545,   546,   566,
     567,   568,   574,   575,   578,   588,   589,   590,   596,   599,
     600,   601,   608,   617,   618,   619,   622
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "NUMBER_INT", "NIL",
  "NUMBER_REAL", "NAME", "READ", "WRITE", "MULT", "ADD", "REL", "AND",
  "OR", "EQ", "COLON", "DL_DG", "EXCLAMATION", "PERCENT", "QUESTION",
  "STR_LITERAL", "INT", "FLOAT", "LIST", "IF", "ELSE", "FOR", "RETURN",
  "THEN", "';'", "'='", "'('", "')'", "','", "'{'", "'}'", "$accept",
  "prog", "external_declaration_list", "external_declaration",
  "var_declaration", "@1", "func_declaration", "@2", "$@3",
  "param_list.opt", "params_list", "param_decl", "compound_stmt", "$@4",
  "block_item_list.opt", "block_item_list", "block_item", "statement",
  "io_stmt", "expr_stmt", "cond_stmt", "jmp_stmt", "iter_stmt",
  "expression", "expression.opt", "logical_or_expr", "logical_and_expr",
  "eq_expr", "rel_expr", "list_expr", "add_expr", "mult_expr",
  "unary_expr", "unary_ops", "postfix_expr", "arg_expr_list",
  "arg_expr_list.opt", "primary_expr", "id", "type", "constant",
  "string_literal", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    59,
      61,    40,    41,    44,   123,   125
};
#endif

#define YYPACT_NINF (-354)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-117)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    5214,  1043,   843,  9232,  9244,  9198,   -23,     6,   239,   402,
     657,   926,     1,    37,    31,    34,  1988,  2029,  5246,    33,
    5282,  5314,  5346,  5378,  5410,  5442,  5474,  5506,  5538,  5570,
    5602,    51,    58,   260,   165,   335,   717,  3236,  3106,  9254,
    1175,  9266,  9276,  9209,    13,  9288,  1265,  2039,  2326,  2367,
    2377,  2565,  2326,  2326,    28,    71,    32,    77,  2664,   299,
    9342,    66,  3334,    -1,  5634,  -354,  5670,  5702,  2705,  2715,
    2903,  3002,  3043,  3053,  3393,  3459,  3488,  9298,     8,  5734,
      14,   217,  9354,    98,  9363,  9375,   441,   885,  2012,   323,
    3087,   385,   776,   909,  1337,  1480,   102,   139,  8694,   157,
     160,   172,  8705,   190,  9384,   195,   209,  5766,  5798,  9310,
    9320,  5830,   246,  5865,  5900,  5935,    41,  9396,   405,  9405,
     613,  9417,  1606,  9426,  1676,  9438,  9447,  9459,  1782,  9468,
    1819,  9480,  9489,  9501,    96,  4766,   104,   136,   245,   163,
     252,   227,   264,   295,   318,    27,   286,   296,   312,   316,
     322,   333,  1111,  3701,   475,   575,  5971,  6003,   350,  3525,
    9332,   287,   432,   450,  6039,    14,  6071,  6103,  6135,  6167,
    6199,  6231,  7621,    93,  6263,   261,   348,  9510,   356,   468,
    6295,   486,   360,  6327,  7621,  7621,   125,   125,   144,   370,
    6359,  6391,   379,   390,  8718,   395,   287,  7621,  7621,  7621,
    7621,  6423,  6455,  6487,  6519,  6551,  8550,  8561,  8574,  3864,
    3569,    91,   128,   800,   412,   476,   426,  8729,  8585,  1313,
    8598,  8609,  8537,  8622,   309,  9522,  9531,  9543,  4612,  3662,
    1265,  9552,  9564,  9221,  9573,   400,  2190,  3907,  3972,  3982,
    4062,  4292,  3972,  3972,   418,   434,    44,   110,   440,   444,
    4377,  5246,  6583,  6618,  6653,  6688,  6723,  6758,   448,  3727,
    4157,  4190,  1094,  7749,   133,   204,   294,   169,   201,   585,
    8225,  4227,  3439,  4328,  8150,  1225,  8162,    99,   132,   492,
    6793,  3927,  7759,  7769,  7788,  7798,  7808,  7769,  7769,   509,
     453,   460,   466,   474,  7827,  5246,   744,   884,   965,  1000,
    1195,  1442,   478,   514,   495,  3673,  4168,   507,  8742,   511,
    7837,  7847,  7866,  7876,  7886,  7905,  7915,  7925,  7944,  8633,
       8,  8753,   513,  9585,     8,  8766,  8777,  8790,  4553,  7954,
    8801,  2190,  8814,  8825,  8646,  8838,   540,  8849,  8862,   606,
     521,  2350,   834,  3852,   369,   854,   545,   632,   682,   202,
     705,    50,    63,  7964,  1032,  9594,   522,  5634,  6828,  8873,
     518,  7983,  7993,  8003,  8022,  8032,  8042,  8061,  8071,  8081,
    8175,     8,   546,   556,  8237,  8250,  8262,  4111,  8100,  8275,
    3927,  8287,  8300,  4388,  8312,   564,  8325,  8337,  1174,   515,
    2563,   783,  4217,   278,  1143,   670,  1288,  1386,   229,   936,
    8110,  1145,  9606,   554,  5634,  1479,  6863,  6898,  8657,  8670,
    8886,   381,  8897,  1070,  8910,   721,  8921,   966,  8934,  8945,
    8958,  1033,  8969,  1443,  8982,  8993,  9006,   119,   542,  9615,
    9627,   543,  9017,   555,  9030,     8,   559,   573,  9041,   587,
     619,  9054,   620,  9636,   557,  6933,  6968,   553,  8187,  8200,
    8350,   300,  8362,   981,  8375,  1393,  8387,  1724,  8400,  8412,
    8425,  1890,  8437,  2062,  8450,  8462,  8475,   242,   621,  9065,
     622,  8487,     8,   623,   624,  9078,   627,   646,  9089,   653,
    9648,   660,  1534,  1781,   655,  8681,  9657,  9102,  9113,   659,
     669,   678,   683,   684,   692,  4345,  4518,   475,  1352,  7003,
    8212,  8500,  8512,   667,   713,   714,   726,   727,   728,  7493,
    7525,   475,  1514,  1818,  9126,  7038,  7073,  7108,  7143,  7178,
     733,   736,   743,  7653,   745,  8120,  5246,  1605,  1850,  1943,
    2119,  2156,  2210,  2281,   729,  7213,  2457,   750,  9669,   751,
    8525,  2494,  2526,  2795,  2832,  2864,  7685,  3133,  3170,  3202,
     759,  9678,   760,   292,  1650,  8139,  7248,  1691,  9690,   769,
    5634,  7653,  2619,  7653,   125,   125,   222,  3299,  7685,  7685,
     125,   125,   355,   789,   790,  9137,   793,   794,  9150,   799,
    9699,   772,  2957,  3624,   773,  7283,  7318,   803,   804,  9161,
     805,  4028,  4128,   818,   839,  9174,   861,   857,   866,   871,
     875,   878,  7557,  7589,   475,  1889,  3779,  7653,  7653,  7653,
    7653,  7685,  7685,  7685,  7685,  4426,  4478,  4585,  4632,  4669,
    7717,  4704,  4739,  4802,   883,  9711,   890,  7353,  7388,  7423,
    7458,  4840,  4872,  4904,  4936,  4968,  7717,  7717,   125,   125,
     442,  5003,  5038,   881,   892,  9185,   901,  7717,  7717,  7717,
    7717,  5073,  5108,  5143,  5178
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -354,  -354,  -354,   915,     3,   791,  -354,  -354,  -354,   782,
    -354,   786,   170,  -250,  -353,  -354,   845,    21,   191,   231,
     314,   520,   677,     0,  -102,  4230,  4006,  3901,  3643,  3052,
    3536,  3198,  1362,  1700,  2038,  -354,  -314,  2376,  1023,     2,
    2714,  -345
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   111,   146,    23,   165,   189,   140,
     141,   142,   252,    64,   112,   113,   114,   115,   253,   254,
     255,   256,   257,   105,   106,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,   137,   138,    42,    43,   116,
      45,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   357,    44,    22,   447,   440,   428,  -109,    54,   135,
     431,   259,   260,   261,   262,   139,    61,    63,     8,   224,
      31,    25,    44,    22,    56,     9,    10,    11,   -13,    96,
    -109,   110,  -109,    65,   235,   277,   278,    55,  -111,   263,
    -103,    25,    79,  -110,    80,   404,   -17,   279,   -13,   -13,
    -109,   484,   176,   178,   477,   100,  -111,   468,   103,   -13,
      57,  -111,    58,  -111,   258,    59,  -110,   351,  -110,  -112,
     280,    68,    98,  -109,   206,   207,   208,   209,   136,  -111,
      67,     8,   143,  -112,   192,   193,   195,   -55,     9,    10,
      11,    99,  -112,   -46,   -46,   108,   -46,   -46,   -46,   -46,
     -46,   -46,   210,   -46,   310,  -109,  -112,    46,  -112,    68,
     -46,   -46,   -46,   258,   -46,   -46,  -110,   -46,   184,   -46,
     -46,   489,   372,   -55,   -46,   -56,   306,   -46,   206,   207,
     208,   209,   310,   352,   147,     8,  -100,  -100,  -110,  -110,
     311,   -60,     9,    10,    11,   194,   361,   206,   207,   208,
     209,   -56,   302,   302,     8,   373,   210,   -58,   503,   179,
     -60,     9,    10,    11,   143,   -55,   -55,   143,  -102,   159,
      24,   148,    31,   173,   175,   210,   -58,   -64,   -64,    70,
     364,   -68,   -68,   -68,    31,    31,   307,   307,   307,  -116,
      24,    26,   150,   183,   -64,   -21,   -21,    31,    31,    31,
      31,   -68,   -68,   436,   151,   190,   191,   584,   235,   577,
     309,    26,   -72,   -72,   -72,   -72,   362,   -60,   202,   203,
     204,   205,   153,   589,   -59,   206,   207,   208,   209,   322,
     473,    27,     8,   -72,   -72,   235,   -60,   -60,   155,     9,
      10,    11,   -95,   -95,   -95,   -95,    -9,   144,   145,   -95,
     356,    27,   444,   210,   -58,   361,   -95,   -95,   -95,   -18,
     162,   -43,   -43,   360,   -43,   -43,   -43,   -43,   -43,   -43,
     -95,   -43,    69,   -60,   -56,   -56,   560,   160,   -43,   -43,
     -43,   156,   -43,   -43,   161,   -43,   185,   -43,   -43,   -60,
     362,   -63,   -43,   573,   403,   -43,   -20,   -20,   235,   481,
     104,   289,     2,     3,     4,     5,   -64,   -64,   363,     8,
     -63,   -63,   362,   -61,    28,   166,     9,    10,    11,   164,
     136,    18,   296,   296,   136,   167,   -64,   -64,   -58,   433,
      17,   180,   -61,   -61,    28,   -67,   -67,    70,  -108,  -108,
    -108,   168,    24,   297,   297,   169,    71,   -68,   -68,   -68,
     439,   170,   -67,   442,    24,    24,   595,   258,   206,   207,
     208,   209,   171,    26,   -68,     8,   201,    24,    24,    24,
      24,   136,     9,    10,    11,    26,    26,   186,   470,    -9,
     303,   311,   -63,   298,   298,   188,   210,   -58,    26,    26,
      26,    26,   -14,   311,   -61,   537,   539,    69,   -63,   476,
     479,   -63,   196,    27,   258,   -93,   -93,   -93,   -93,   550,
     552,   197,   -93,   -61,   -63,    27,    27,    69,   -61,   -93,
     -93,   -93,   198,   313,   -68,   -68,   -68,   200,    27,    27,
      27,    27,  -108,   -93,   -61,   136,   314,   -76,   -76,   -76,
     -76,   315,   316,   645,   -68,   206,   207,   208,   209,   349,
      46,    47,     8,   277,   278,   581,    52,    53,   -76,     9,
      10,    11,   587,   588,   590,   350,   299,   299,   593,   594,
     596,   353,   136,   210,   -58,   354,     1,   358,     2,     3,
       4,     5,   -22,   -22,   398,     8,    28,   -72,   -72,   -72,
     -72,   399,     9,    10,    11,   534,   534,   400,    28,    28,
     -99,   -99,   624,   626,   -58,   401,    17,   405,   -72,   302,
     302,    28,    28,    28,    28,   406,   528,   536,   -19,   -19,
      29,  -108,  -108,   258,   407,   559,   -75,   -75,   -75,   -75,
     547,   549,   -75,   -75,   -75,   -75,   643,   644,   646,   -59,
      29,  -108,  -108,   409,   556,   430,   302,   -75,   -75,   236,
     449,   446,  -111,   -75,   576,   579,   313,   -71,   -71,   -71,
     258,   258,  -112,   258,   307,   307,   307,   567,   302,   302,
     307,   307,   307,   281,   485,   486,   177,   -71,     2,     3,
       4,     5,   585,   483,   586,     8,   498,   488,   499,   591,
     592,   490,     9,    10,    11,   365,   -76,   -76,   -76,   -76,
     366,   367,   534,   534,   -58,   491,    17,   258,   258,   258,
     258,   302,   302,   302,   302,   236,   237,   -76,   -76,   493,
     534,   242,   243,   621,   623,   -65,   -65,    70,   627,   628,
     629,   630,   631,   632,   633,   634,   534,   534,   307,   307,
     307,   635,   -65,   -82,   -82,   -82,   -82,   534,   534,   534,
     534,   494,   496,   500,   502,   504,   505,   641,   642,   507,
     -94,   -94,   -94,   -94,   -82,   527,   527,   -94,   651,   652,
     653,   654,   300,   300,   -94,   -94,   -94,    30,   508,   296,
     296,   364,   -71,   -71,   -71,   510,   529,   529,   -94,   512,
     513,   514,    29,   -81,   -81,   -81,   -81,    30,   515,   540,
     297,   297,   -71,   -71,    29,    29,   438,   516,   206,   207,
     208,   209,   517,   518,   -81,     8,   296,    29,    29,    29,
      29,   519,     9,    10,    11,    99,   530,   530,   -72,   -72,
     -72,   -72,   313,   -69,   -69,   -69,   210,   297,   296,   296,
     298,   298,   541,   542,   -32,   -32,   -72,   -32,   -32,   -32,
     -32,   -32,   -32,   -69,   -32,   543,   544,   545,   562,   297,
     297,   -32,   -32,   -32,   553,   -32,   -32,   554,   -32,   -32,
     -32,   -32,   527,   527,   555,   -32,   557,   298,   -32,   564,
     566,   296,   296,   296,   296,    46,    47,    48,   570,   572,
     527,    52,    53,   529,   529,   -67,   -67,   363,   583,   298,
     298,   605,   297,   297,   297,   297,   527,   527,   606,   531,
     531,   529,   -64,   -64,   312,   -67,   -67,   527,   527,   527,
     527,   597,   598,   299,   299,   600,   601,   529,   529,   301,
     301,   603,   -64,   530,   530,   607,   608,   610,   529,   529,
     529,   529,   298,   298,   298,   298,   -67,   -67,   312,    30,
     611,   530,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
     299,    30,    30,   236,   237,   238,   -67,   530,   530,   242,
     243,   612,  -114,  -114,    30,    30,    30,    30,   530,   530,
     530,   530,   299,   299,   -36,   -36,   615,   -36,   -36,   -36,
     -36,   -36,   -36,   614,   -36,   616,   -75,   -75,   -75,   -75,
     617,   -36,   -36,   -36,   618,   -36,   -36,   619,   -36,   -36,
     -36,   -36,   638,   647,   -75,   -36,   531,   531,   -36,   640,
      71,   -71,   -71,   -71,   648,   299,   299,   299,   299,   -96,
     -96,   -96,   -96,   650,   531,    66,   -96,   475,   -71,   206,
     207,   208,   209,   -96,   -96,   -96,     8,   182,   181,   304,
     531,   531,     0,     9,    10,    11,    99,   -96,   157,     0,
       0,   531,   531,   531,   531,   -31,   -31,   210,   -31,   -31,
     -31,   -31,   -31,   -31,     0,   -31,     0,   -73,   -73,   -73,
     -73,     0,   -31,   -31,   -31,     0,   -31,   -31,     0,   -31,
     -31,   -31,   -31,   -65,   -65,   363,   -31,     0,   -73,   -31,
     -33,   -33,     0,   -33,   -33,   -33,   -33,   -33,   -33,     0,
     -33,     0,     0,   -65,   -65,   532,   532,   -33,   -33,   -33,
       0,   -33,   -33,     0,   -33,   -33,   -33,   -33,     0,   300,
     300,   -33,     0,   443,   -33,     2,     3,     4,     5,     0,
     222,     0,     8,     0,   -78,   -78,   -78,   -78,     0,     9,
      10,    11,    46,    47,    48,    49,    50,    51,    52,    53,
       0,   -58,     0,    17,     0,   -78,   300,    81,     0,   233,
     233,   233,   233,   233,   233,   233,   233,    97,   222,     0,
       0,   222,   -65,   -65,   312,     0,     0,     0,   300,   300,
       0,   233,   233,   233,   233,   233,   233,   233,   233,   233,
       0,   275,   -65,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,     0,     1,     0,     2,     3,     4,     5,   290,   291,
       0,     8,   532,   532,  -108,  -108,  -108,  -108,     9,    10,
      11,   300,   300,   300,   300,   292,   172,   293,   294,   158,
     532,     0,    17,     0,     0,   295,   480,     0,     2,     3,
       4,     5,   281,   282,   283,     8,   532,   532,   287,   288,
       0,     0,     9,    10,    11,     0,   163,   532,   532,   532,
     532,     0,   533,   533,   -58,     0,    17,     0,     2,     3,
       4,     5,   275,   281,   282,     8,   301,   301,     0,   287,
     288,     0,     9,    10,    11,   -34,   -34,     0,   -34,   -34,
     -34,   -34,   -34,   -34,     0,   -34,    17,     0,     0,   222,
     222,   222,   -34,   -34,   -34,     0,   -34,   -34,     0,   -34,
     -34,   -34,   -34,   301,     0,     0,   -34,     0,     0,   -34,
       0,     0,     0,   222,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,   222,     0,     0,   301,   301,     0,     0,     0,
       0,     0,   222,   233,     0,  -104,   371,  -104,  -104,   334,
     334,   334,   334,   334,   334,   334,   334,     0,   225,   226,
     227,   228,     0,     0,     0,     8,     0,     0,     0,   533,
     533,     0,     9,    10,    11,     0,   222,     0,   301,   301,
     301,   301,     0,     0,     0,   275,   229,   533,     0,   -82,
     -82,   -82,   -82,     0,   383,   383,   383,   383,   383,   383,
     383,   383,     0,   533,   533,     0,   206,   207,   208,   209,
     -82,   -82,     0,     8,   533,   533,   533,   533,     0,     0,
       9,    10,    11,   334,   334,   334,   334,   334,   334,   334,
     334,   334,     0,   275,   210,     0,     0,   275,   -82,   -82,
     -82,   -82,   222,   538,   334,     2,     3,     4,     5,     0,
       0,     0,     8,     0,     0,     0,   -82,     0,     0,     9,
      10,    11,   437,   222,     0,     0,   222,     0,     0,   218,
       0,   -58,     0,    17,   383,   383,   383,   383,   383,   383,
     383,   383,   383,     0,   275,     0,     0,   -81,   -81,   -81,
     -81,   222,    77,   383,   364,   -69,   -69,   -69,    82,    85,
      85,    85,    85,    85,    85,    85,     0,   218,   -81,   -81,
     218,   474,   222,   222,     0,   -69,   -69,     0,     0,     0,
      85,    85,    85,    85,    85,    85,    85,   132,    85,     0,
     271,     0,   -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,
     -35,     0,   -35,     0,   -77,   -77,   -77,   -77,   275,   -35,
     -35,   -35,     0,   -35,   -35,     0,   -35,   -35,   -35,   -35,
       0,     0,     0,   -35,     0,   -77,   -35,     0,     0,   -42,
     -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,
       0,   -81,   -81,   -81,   -81,   275,   -42,   -42,   -42,     0,
     -42,   -42,     0,   -42,   -42,   -42,   -42,     0,     0,   -81,
     -42,     0,     0,   -42,     0,   551,     0,     2,     3,     4,
       5,   271,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   -50,   -50,     0,   -50,   -50,   -50,
     -50,   -50,   -50,   -58,   -50,    17,     0,     0,   218,   218,
     218,   -50,   -50,   -50,     0,   -50,   -50,     0,   -50,   -50,
     -50,   -50,     0,     0,     0,   -50,     0,     0,   -50,     0,
       0,     0,   218,     0,     0,     0,   574,   222,   222,     0,
       0,   319,     0,     0,     0,     0,     0,   222,   222,   222,
       0,   218,   323,   222,   222,   222,     0,     0,   330,   338,
     338,   338,   338,   338,   338,   338,   -32,     0,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,     0,    71,   -69,   -69,
     -69,     0,   -32,   -32,   -32,   218,   -32,   -32,     0,   -32,
     -32,   -32,   -32,     0,   370,   -69,   -32,     0,     0,   -32,
     -32,     0,     0,   379,   387,   387,   387,   387,   387,   387,
     387,   575,     0,   206,   207,   208,   209,     0,     0,     0,
       8,   222,   222,   222,     0,     0,     0,     9,    10,    11,
      99,     0,   338,   338,   338,   338,   338,   338,   338,   425,
     338,   210,   271,     0,     0,     0,   271,   -73,   -73,   -73,
     -73,   218,   580,   434,     2,     3,     4,     5,     0,     0,
       0,     8,     0,     0,     0,   -73,     0,     0,     9,    10,
      11,     0,   218,     0,     0,   218,     0,   219,     0,     0,
     -58,     0,    17,   387,   387,   387,   387,   387,   387,   387,
     465,   387,     0,   271,     0,   -73,   -73,   -73,   -73,     0,
     218,     0,   471,     0,     0,     0,   230,   230,   230,   230,
     230,   230,   230,   230,     0,   219,   -73,   -73,   219,     0,
       0,   218,   218,     0,     0,     0,     0,     0,   230,   230,
     230,   230,   230,   230,   230,   230,   230,     0,   272,     0,
       0,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,   -49,     0,   -78,   -78,   -78,   -78,   271,   -49,   -49,
     -49,     0,   -49,   -49,     0,   -49,   -49,   -49,   -49,     0,
       0,   -78,   -49,     0,     0,   -49,     0,     0,   -24,   -24,
       0,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,     0,
     -77,   -77,   -77,   -77,   271,   -24,   -24,   -24,     0,   -24,
     -24,     0,   -24,   -24,   -24,   -24,     0,     0,   -77,   -24,
       0,   -46,   -24,   -46,   -46,   -46,   -46,   -46,   -46,   272,
     -46,     0,     0,     0,     0,     0,     0,   -46,   -46,   -46,
       0,   -46,   -46,     0,   -46,   561,   -46,   -46,     0,     0,
       0,   -46,     0,     0,   -46,   -46,   219,   219,   219,     0,
     625,     0,     2,     3,     4,     5,     0,     0,     0,     8,
       0,   -78,   -78,   -78,   -78,     0,     9,    10,    11,     0,
     219,     0,     0,     0,     0,     0,   218,   218,   -58,   219,
      17,     0,   -78,   -78,     0,     0,   218,   218,   218,   219,
     230,     0,   218,   218,   218,     0,   331,   331,   331,   331,
     331,   331,   331,   331,   -36,     0,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,     0,     0,     0,     0,     0,     0,
     -36,   -36,   -36,   219,   -36,   -36,     0,   -36,   -36,   -36,
     -36,     0,   272,     0,   -36,     0,     0,   -36,   -36,     0,
       0,   380,   380,   380,   380,   380,   380,   380,   380,    60,
       0,     2,     3,     4,     5,     0,     0,     0,     8,     0,
     218,   218,   218,     0,     0,     9,    10,    11,     0,     0,
     331,   331,   331,   331,   331,   331,   331,   331,   331,    17,
     272,    46,    47,    48,   272,     0,    51,    52,    53,   219,
      62,   331,   206,   207,   208,   209,     0,     0,     0,     8,
      83,     0,   225,   226,   227,   228,     9,    10,    11,     8,
     219,     0,     0,   219,     0,   220,     9,    10,    11,     0,
     210,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     229,   272,     0,   -77,   -77,   -77,   -77,     0,   219,     0,
     380,     0,     0,     0,   231,   231,   231,   231,   231,   231,
     231,   231,     0,   220,   -77,   -77,   220,     0,     0,   219,
     219,     0,     0,     0,     0,     0,   231,   231,   231,   231,
     231,   231,   231,   231,   231,     0,   273,     0,     0,     0,
     -31,     0,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,
       0,     0,     0,     0,     0,   272,   -31,   -31,   -31,     0,
     -31,   -31,     0,   -31,   -31,   -31,   -31,     0,     0,     0,
     -31,     0,     0,   -31,   -31,     0,     0,   -33,     0,   -33,
     -33,   -33,   -33,   -33,   -33,     0,   -33,     0,     0,     0,
       0,     0,   272,   -33,   -33,   -33,     0,   -33,   -33,     0,
     -33,   -33,   -33,   -33,     0,     0,     0,   -33,     0,     0,
     -33,   -33,     0,   325,   326,   327,   328,   273,     0,     0,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
       0,   -34,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,
     -34,   329,     0,     0,   220,   220,   220,   -34,   -34,   -34,
       0,   -34,   -34,     0,   -34,   -34,   -34,   -34,     0,     0,
       0,   -34,     0,     0,   -34,   -34,     0,     0,   220,     0,
       0,     0,     0,     0,   219,   219,     0,   220,     0,     0,
       0,     0,     0,     0,   219,   219,   219,   220,   231,     0,
     219,   219,   219,     0,   332,   332,   332,   332,   332,   332,
     332,   332,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,
       0,   -35,     0,     0,     0,     0,     0,     0,   -35,   -35,
     -35,   220,   -35,   -35,     0,   -35,   -35,   -35,   -35,     0,
     273,     0,   -35,     0,     0,   -35,   -35,     0,     0,   381,
     381,   381,   381,   381,   381,   381,   381,    86,     0,   225,
     226,   227,   228,     0,     0,     0,     8,     0,   219,   219,
     219,     0,     0,     9,    10,    11,     0,     0,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   229,   273,   236,
     237,   238,   273,     0,   241,   242,   243,   220,    88,   332,
     225,   226,   227,   228,     0,     0,     0,     8,    90,     0,
     225,   226,   227,   228,     9,    10,    11,     8,   220,     0,
       0,   220,     0,   221,     9,    10,    11,     0,   229,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   229,   273,
       0,     0,     0,     0,     0,     0,   220,     0,   381,     0,
       0,     0,   232,   232,   232,   232,   232,   232,   232,   232,
       0,   221,     0,     0,   221,     0,     0,   220,   220,     0,
       0,     0,     0,     0,   232,   232,   232,   232,   232,   232,
     232,   232,   232,     0,   274,     0,     0,     0,   -43,     0,
     -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,     0,     0,
       0,     0,     0,   273,   -43,   -43,   -43,     0,   -43,   -43,
       0,   -43,   563,   -43,   -43,     0,     0,     0,   -43,     0,
       0,   -43,   -43,     0,   -41,   -41,     0,   -41,   -41,   -41,
     -41,   -41,   -41,     0,   -41,     0,     0,     0,     0,     0,
     273,   -41,   -41,   -41,     0,   -41,   -41,     0,   -41,   -41,
     -41,   -41,     0,     0,     0,   -41,   -37,   -37,   -41,   -37,
     -37,   -37,   -37,   -37,   -37,   274,   -37,     0,     0,     0,
       0,     0,     0,   -37,   -37,   -37,     0,   -37,   -37,     0,
     -37,   -37,   -37,   -37,     0,     0,     0,   -37,     0,     0,
     -37,     0,   221,   221,   221,     0,    92,     0,   225,   226,
     227,   228,   281,   282,   283,     8,     0,   286,   287,   288,
       0,     0,     9,    10,    11,     0,   221,     0,     0,     0,
       0,     0,   220,   220,     0,   221,   229,     0,     0,     0,
       0,     0,   220,   220,   220,   221,   232,     0,   220,   220,
     220,     0,   333,   333,   333,   333,   333,   333,   333,   333,
     -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,
       0,     0,     0,     0,     0,     0,   -42,   -42,   -42,   221,
     -42,   -42,     0,   -42,   -42,   -42,   -42,     0,   274,     0,
     -42,     0,     0,   -42,   -42,     0,     0,   382,   382,   382,
     382,   382,   382,   382,   382,   102,     0,   206,   207,   208,
     209,     0,     0,     0,     8,     0,   220,   220,   220,     0,
       0,     9,    10,    11,     0,     0,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   210,   274,     0,     0,     0,
     274,     0,     0,     0,     0,   221,   117,   333,   225,   226,
     227,   228,     0,     0,     0,     8,   119,     0,   225,   226,
     227,   228,     9,    10,    11,     8,   221,     0,     0,   221,
       0,   223,     9,    10,    11,     0,   229,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   229,   274,     0,     0,
       0,     0,     0,     0,   221,     0,   382,     0,     0,     0,
     234,   234,   234,   234,   234,   234,   234,   234,     0,   223,
       0,     0,   223,     0,     0,   221,   221,     0,     0,     0,
       0,     0,   234,   234,   234,   234,   234,   234,   234,   234,
     234,     0,   276,     0,     0,   -40,   -40,     0,   -40,   -40,
     -40,   -40,   -40,   -40,     0,   -40,     0,     0,     0,     0,
       0,   274,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,
     -40,   -40,   -40,     0,     0,     0,   -40,     0,     0,   -40,
       0,     0,   -38,   -38,     0,   -38,   -38,   -38,   -38,   -38,
     -38,     0,   -38,     0,     0,     0,     0,     0,   274,   -38,
     -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,   -38,
       0,     0,     0,   -38,   -39,   -39,   -38,   -39,   -39,   -39,
     -39,   -39,   -39,   276,   -39,     0,     0,     0,     0,     0,
       0,   -39,   -39,   -39,     0,   -39,   -39,     0,   -39,   -39,
     -39,   -39,     0,     0,     0,   -39,     0,     0,   -39,     0,
     223,   223,   223,     0,   121,     0,   225,   226,   227,   228,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,     0,   223,     0,     0,     0,     0,     0,
     221,   221,     0,   223,   229,     0,     0,     0,     0,     0,
     221,   221,   221,   223,   234,     0,   221,   221,   221,     0,
     335,   335,   335,   335,   335,   335,   335,   335,   -50,     0,
     -50,   -50,   -50,   -50,   -50,   -50,     0,   -50,     0,     0,
       0,     0,     0,     0,   -50,   -50,   -50,   223,   -50,   -50,
       0,   -50,   -50,   -50,   -50,     0,   276,     0,   -50,     0,
       0,   -50,   -50,     0,     0,   384,   384,   384,   384,   384,
     384,   384,   384,   123,     0,   225,   226,   227,   228,     0,
       0,     0,     8,     0,   221,   221,   221,     0,     0,     9,
      10,    11,     0,     0,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   229,   276,     0,     0,     0,   276,     0,
       0,     0,     0,   223,   125,   335,   225,   226,   227,   228,
       0,     0,     0,     8,   127,     0,   225,   226,   227,   228,
       9,    10,    11,     8,   223,     0,     0,   223,     0,   215,
       9,    10,    11,     0,   229,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   229,   276,     0,     0,     0,     0,
       0,     0,   223,     0,   384,     0,    46,    47,    48,    49,
      87,    51,    52,    53,    94,    95,     0,   215,     0,     0,
     215,     0,     0,   223,   223,    75,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   124,     0,   128,   130,     0,     0,     0,
     268,     0,     0,   -46,   -46,   -83,   -46,   -46,   -46,   -46,
     -46,   -46,     0,   -46,     0,     0,     0,     0,     0,   276,
     -46,   -46,   -46,     0,   -46,   -46,     0,   -46,   568,   -46,
     -46,     0,     0,     0,   -46,     0,     0,   -46,     0,     0,
     -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,
     -45,     0,     0,     0,     0,     0,   276,   -45,   -45,   -45,
       0,   -45,   -45,     0,   -45,   -45,   -45,   -45,     0,     0,
       0,   -45,   -43,   -43,   -45,   -43,   -43,   -43,   -43,   -43,
     -43,   268,   -43,     0,     0,   217,     0,     0,     0,   -43,
     -43,   -43,     0,   -43,   -43,     0,   -43,   569,   -43,   -43,
       0,     0,     0,   -43,     0,     0,   -43,     0,   215,   215,
     215,     0,     0,     0,     0,    84,    72,   -76,   -76,   -76,
     -76,    73,    74,   217,     0,     0,   217,     0,     0,     0,
       0,     0,   215,     0,     0,   -76,     0,     0,   223,   223,
     126,     0,     0,     0,     0,     0,   270,     0,   223,   223,
     223,   215,     0,     0,   223,   223,   223,     0,     0,     0,
     340,   215,   215,   215,   347,   348,     0,     0,     0,   -48,
     -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,
       0,     0,     0,     0,     0,   215,   -48,   -48,   -48,     0,
     -48,   -48,     0,   -48,   -48,   -48,   -48,     0,     0,     0,
     -48,     0,     0,   -48,     0,   389,   268,   268,   268,   396,
     397,     0,     0,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   223,   223,   223,     0,     0,   270,     0,     0,
       0,     0,   215,   215,   215,   417,   109,   421,   423,     0,
     215,     0,   268,     0,     0,     0,   268,     0,     0,     0,
       0,   215,     0,     0,   217,   217,   217,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   225,   226,   227,   228,
       0,     0,   215,     8,     0,   215,     0,     0,   217,     0,
       9,    10,    11,   268,   268,   268,   457,     0,   461,   463,
       0,   268,     0,   268,   229,     0,     0,   217,     0,     0,
     215,     0,     0,     0,     0,   337,   217,   217,   217,   217,
     217,   217,   259,   260,   261,   262,     0,     0,     0,     8,
       0,   215,   215,     0,     0,     0,     9,    10,    11,     0,
     131,   217,   225,   226,   227,   228,     0,     0,     0,     8,
     263,     0,     0,     0,     0,     0,     9,    10,    11,     0,
     386,   270,   270,   270,   270,   270,   270,   268,     0,   133,
     229,   225,   226,   227,   228,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   217,   217,
     217,   217,   419,   217,   217,     0,   217,     0,   270,   229,
       0,     0,   270,     0,   268,     0,   305,   217,   259,   260,
     261,   262,     0,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,     0,     0,     0,   217,     0,
       0,   217,     0,   216,     0,     0,   263,     0,     0,   270,
     270,   270,   270,   459,   270,   270,     0,   270,     0,   270,
     308,     0,   206,   207,   208,   209,   217,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,     0,
       0,   216,     0,     0,   216,     0,     0,   217,   217,     0,
     210,     0,     0,     0,     0,     0,   215,   215,     0,     0,
       0,     0,     0,     0,   269,     0,   215,   215,   215,     0,
       0,     0,   215,   215,   215,   -49,     0,   -49,   -49,   -49,
     -49,   -49,   -49,   270,   -49,     0,     0,     0,     0,     0,
       0,   -49,   -49,   -49,     0,   -49,   -49,     0,   -49,   -49,
     -49,   -49,     0,     0,     0,   -49,     0,     0,   -49,   -49,
     214,     0,     0,   321,     0,   206,   207,   208,   209,     0,
     270,     0,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   281,   282,   283,   284,   285,   286,   287,   288,
     215,   215,   215,   210,    93,   269,     0,     0,   214,     0,
       0,   214,     1,     0,     2,     3,     4,     5,   290,   291,
       0,     8,     0,   122,     0,     0,     0,     0,     9,    10,
      11,   267,   216,   216,   216,   292,   174,   293,   294,     0,
       0,     0,    17,     0,     0,   295,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,     0,     0,   216,     0,     0,     0,
       0,     0,   217,   217,     0,     0,     0,  -114,     0,  -114,
    -114,     0,   217,   217,   217,   216,     0,     0,   217,   217,
     217,     0,     0,     0,   216,   216,   216,   216,   216,   216,
     -24,     0,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,
       0,     0,     0,     0,     0,     0,   -24,   -24,   -24,   216,
     -24,   -24,   267,   -24,   -24,   -24,   -24,     0,     0,     0,
     -24,     0,     0,   -24,   -24,     0,     0,     0,     0,   269,
     269,   269,   269,   269,   269,     0,     0,     0,     0,   214,
     214,   214,     0,     0,     0,     0,   217,   217,   217,     0,
       0,     0,     0,     0,     0,     0,   216,   216,   216,   216,
       0,   216,   216,   214,   216,     0,   269,     0,     0,     0,
     269,   236,   237,   238,   239,   216,   241,   242,   243,     0,
       0,     0,   214,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,     0,   214,   214,   346,     0,   216,     0,     0,   216,
       0,     0,     0,     0,  -108,  -108,  -108,   269,   269,   269,
     269,     0,   269,   269,     0,   269,   214,   269,   336,     0,
     325,   326,   327,   328,   216,     0,     0,     8,   213,     0,
       0,     0,     0,     0,     9,    10,    11,   267,   267,   395,
     374,   375,   376,   377,     0,   216,   216,     8,   329,     0,
       0,     0,     0,     0,     9,    10,    11,     0,     0,     0,
      89,     0,     0,   214,   214,   415,   213,     0,   378,   213,
       0,   214,     0,   267,     0,     0,     0,   267,     0,     0,
     120,   269,   214,   339,     0,   325,   326,   327,   328,   266,
       0,     0,     8,   341,     0,   325,   326,   327,   328,     9,
      10,    11,     8,   214,     0,     0,   214,     0,     0,     9,
      10,    11,     0,   329,   267,   267,   455,     0,   269,     0,
       0,     0,   267,   329,   267,     0,     0,     0,     0,     0,
       0,   214,     0,   212,     0,     0,     0,     0,   -47,   -47,
       0,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,     0,
       0,     0,   214,   214,     0,   -47,   -47,   -47,     0,   -47,
     -47,     0,   -47,   -47,   -47,   -47,    91,     0,     0,   -47,
     266,   212,   -47,   343,   212,   325,   326,   327,   328,     0,
       0,     0,     8,     0,   118,     0,     0,     0,   267,     9,
      10,    11,     0,     0,   265,     0,     0,   213,   213,   213,
     216,   216,     0,   329,     0,     0,     0,     0,     0,     0,
     216,   216,   216,     0,     0,     0,   216,   216,   216,     0,
       0,   213,     0,     0,     0,   267,     0,     0,     0,     0,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,   -44,   -44,
     213,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,     0,
     342,   213,  -108,  -108,  -108,   -44,   -44,   -44,     0,   -44,
     -44,     0,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,
       0,     0,   -44,     0,   213,   265,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,   216,   216,   216,   236,   237,   238,
     239,   240,   241,   242,   243,   391,   266,  -115,     0,  -115,
    -115,     0,   212,   212,   212,     0,     0,   214,   214,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,   214,   214,   214,
       0,   213,   413,   214,   214,   214,   212,     0,     0,   213,
    -113,   266,  -113,  -113,     0,   266,   281,   282,   283,   284,
     213,   286,   287,   288,     0,   212,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,     0,     0,   344,   211,     0,     0,
       0,   213,     0,     0,   213,     0,     0,   369,     0,   -87,
     -87,     0,   266,   453,     0,     0,     0,     0,     0,   212,
     266,     0,   266,     0,     0,     0,     0,     0,     0,   213,
       0,   214,   214,   214,     0,   211,     0,     0,   211,     0,
       0,   393,     0,   345,     0,   325,   326,   327,   328,     0,
     213,   213,     8,     0,     0,     0,   134,     0,   264,     9,
      10,    11,     0,     0,     0,     0,   411,     0,     0,     0,
       0,     0,     0,   329,   212,     0,   265,     0,     0,     0,
     265,     0,     0,     0,     0,   212,   266,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,     0,     1,     0,     2,     3,
       4,     5,   520,   521,     0,     8,   212,     0,   -91,   212,
     -91,   -91,     9,    10,    11,     0,     0,   451,     0,   522,
     523,   524,   525,   266,     0,   265,    17,   265,   355,   526,
       2,     3,     4,     5,   212,     0,     0,     8,     0,   264,
       0,     0,     0,     0,     9,    10,    11,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,   212,   212,     0,    17,     0,
       0,     0,     0,     0,     0,     0,   211,   211,   211,   472,
    -104,  -104,     0,     0,     0,     0,     0,   -41,     0,   -41,
     -41,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,     0,
     211,   265,     0,   -41,   -41,   -41,     0,   -41,   -41,     0,
     -41,   -41,   -41,   -41,     0,   213,   213,   -41,     0,   211,
     -41,   -41,     0,     0,     0,   213,   213,   213,     0,     0,
       0,   213,   213,   213,     0,     0,     0,     0,   265,   -37,
       0,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,     0,
       0,     0,     0,   211,     0,   -37,   -37,   -37,     0,   -37,
     -37,     0,   -37,   -37,   -37,   -37,     0,     0,     0,   -37,
       0,     0,   -37,   -37,     0,     0,     0,     0,     0,     1,
       0,     2,     3,     4,     5,   520,   521,     0,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,     0,   213,
     213,   213,   522,   535,   524,   525,     0,     0,   427,    17,
     264,     0,   526,     0,   264,     0,     0,     0,     0,   211,
     212,   212,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
     212,   212,   212,     0,     0,     0,   212,   212,   212,     0,
     211,     0,     0,   211,  -108,  -108,   -40,     0,   -40,   -40,
     -40,   -40,   -40,   -40,     0,   -40,     0,     0,     0,   467,
       0,   264,   -40,   -40,   -40,     0,   -40,   -40,   211,   -40,
     -40,   -40,   -40,     0,     0,     0,   -40,     0,     0,   -40,
     -40,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,   211,
     211,     0,     0,   -38,     0,   -38,   -38,   -38,   -38,   -38,
     -38,  -108,   -38,  -108,   212,   212,   212,     0,     0,   -38,
     -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,   -38,
       0,     0,     0,   -38,     0,   264,   -38,   -38,     0,     0,
     -39,     0,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,
       0,     0,     0,     0,     0,     0,   -39,   -39,   -39,     0,
     -39,   -39,     0,   -39,   -39,   -39,   -39,     0,     0,     0,
     -39,     0,   264,   -39,   -39,   -46,     0,   -46,   -46,   -46,
     -46,   -46,   -46,     0,   -46,     0,     0,     0,     0,     0,
       0,   -46,   -46,   -46,     0,   -46,   -46,     0,   -46,   636,
     -46,   -46,     0,     0,     0,   -46,     0,     0,   -46,   -46,
     -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,   -45,
       0,     0,     0,     0,     0,     0,   -45,   -45,   -45,     0,
     -45,   -45,     0,   -45,   -45,   -45,   -45,     0,     0,     0,
     -45,     0,     0,   -45,   -45,   281,   282,   283,   284,   285,
     286,   287,   288,     0,   211,   211,     0,     0,     0,     0,
       0,     0,     0,     0,   211,   211,   211,     0,  -101,  -101,
     211,   211,   211,   -43,     0,   -43,   -43,   -43,   -43,   -43,
     -43,     0,   -43,     0,     0,     0,     0,     0,     0,   -43,
     -43,   -43,     0,   -43,   -43,     0,   -43,   637,   -43,   -43,
       0,     0,     0,   -43,     0,     0,   -43,   -43,     0,     0,
     -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,     0,
     -52,     0,     0,     0,     0,     0,     0,   -52,   -52,   -52,
       0,   -52,   -52,     0,   -52,   -52,   -52,   -52,   211,   211,
     211,   -52,   -53,   -53,   -52,   -53,   -53,   -53,   -53,   -53,
     -53,     0,   -53,     0,     0,     0,     0,     0,     0,   -53,
     -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,   -53,
       0,     0,     0,   -53,   -54,   -54,   -53,   -54,   -54,   -54,
     -54,   -54,   -54,     0,   -54,     0,     0,     0,     0,     0,
       0,   -54,   -54,   -54,     0,   -54,   -54,     0,   -54,   -54,
     -54,   -54,     0,     0,     0,   -54,   -51,   -51,   -54,   -51,
     -51,   -51,   -51,   -51,   -51,     0,   -51,     0,     0,     0,
       0,     0,     0,   -51,   -51,   -51,     0,   -51,   -51,     0,
     -51,   -51,   -51,   -51,     0,     0,     0,   -51,     0,   -48,
     -51,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,     0,
       0,     0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,
     -48,     0,   -48,   -48,   -48,   -48,     0,     0,     0,   -48,
       0,     0,   -48,   -48,   -47,     0,   -47,   -47,   -47,   -47,
     -47,   -47,     0,   -47,     0,     0,     0,     0,     0,     0,
     -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,
     -47,     0,     0,     0,   -47,     0,     0,   -47,   -47,   -44,
       0,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,     0,
       0,     0,     0,     0,     0,   -44,   -44,   -44,     0,   -44,
     -44,     0,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,
       0,     0,   -44,   -44,   -52,     0,   -52,   -52,   -52,   -52,
     -52,   -52,     0,   -52,     0,     0,     0,     0,     0,     0,
     -52,   -52,   -52,     0,   -52,   -52,     0,   -52,   -52,   -52,
     -52,     0,     0,     0,   -52,     0,     0,   -52,   -52,   -53,
       0,   -53,   -53,   -53,   -53,   -53,   -53,     0,   -53,     0,
       0,     0,     0,     0,     0,   -53,   -53,   -53,     0,   -53,
     -53,     0,   -53,   -53,   -53,   -53,     0,     0,     0,   -53,
       0,     0,   -53,   -53,   -54,     0,   -54,   -54,   -54,   -54,
     -54,   -54,     0,   -54,     0,     0,     0,     0,     0,     0,
     -54,   -54,   -54,     0,   -54,   -54,     0,   -54,   -54,   -54,
     -54,     0,     0,     0,   -54,     0,     0,   -54,   -54,   -51,
       0,   -51,   -51,   -51,   -51,   -51,   -51,     0,   -51,     0,
       0,     0,     0,     0,     0,   -51,   -51,   -51,     0,   -51,
     -51,     0,   -51,   -51,   -51,   -51,     0,     0,     0,   -51,
       0,     0,   -51,   -51,    -3,     1,     0,     2,     3,     4,
       5,     6,     7,     0,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,     0,    12,    13,     0,    14,     0,
      15,    16,     0,     0,     0,    17,     0,   -23,    18,   -23,
     -23,   -23,   -23,   -23,   -23,     0,   -23,     0,     0,     0,
       0,     0,     0,   -23,   -23,   -23,     0,   -23,   -23,     0,
     -23,     0,   -23,   -23,     0,     0,     0,   -23,     0,     0,
     -23,   -23,    -2,     1,     0,     2,     3,     4,     5,     6,
       7,     0,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,     0,    12,    13,     0,    14,     0,    15,    16,
       0,     0,     0,    17,    -5,    -5,    18,    -5,    -5,    -5,
      -5,    -5,    -5,     0,    -5,     0,     0,     0,     0,     0,
       0,    -5,    -5,    -5,     0,    -5,    -5,     0,    -5,     0,
      -5,    -5,     0,     0,     0,    -5,    -7,    -7,    -5,    -7,
      -7,    -7,    -7,    -7,    -7,     0,    -7,     0,     0,     0,
       0,     0,     0,    -7,    -7,    -7,     0,    -7,    -7,     0,
      -7,     0,    -7,    -7,     0,     0,     0,    -7,    -6,    -6,
      -7,    -6,    -6,    -6,    -6,    -6,    -6,     0,    -6,     0,
       0,     0,     0,     0,     0,    -6,    -6,    -6,     0,    -6,
      -6,     0,    -6,     0,    -6,    -6,     0,     0,     0,    -6,
     -32,   -32,    -6,   -32,   -32,   -32,   -32,   -32,   -32,     0,
     -32,     0,     0,     0,     0,     0,     0,   -32,   -32,   -32,
       0,   -32,   -32,     0,   -32,     0,   -32,   -32,     0,     0,
       0,   -32,    -8,    -8,   -32,    -8,    -8,    -8,    -8,    -8,
      -8,     0,    -8,     0,     0,     0,     0,     0,     0,    -8,
      -8,    -8,     0,    -8,    -8,     0,    -8,     0,    -8,    -8,
       0,     0,     0,    -8,   -36,   -36,    -8,   -36,   -36,   -36,
     -36,   -36,   -36,     0,   -36,     0,     0,     0,     0,     0,
       0,   -36,   -36,   -36,     0,   -36,   -36,     0,   -36,     0,
     -36,   -36,     0,     0,     0,   -36,   -31,   -31,   -36,   -31,
     -31,   -31,   -31,   -31,   -31,     0,   -31,     0,     0,     0,
       0,     0,     0,   -31,   -31,   -31,     0,   -31,   -31,     0,
     -31,     0,   -31,   -31,     0,     0,     0,   -31,   -33,   -33,
     -31,   -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,     0,
       0,     0,     0,     0,     0,   -33,   -33,   -33,     0,   -33,
     -33,     0,   -33,     0,   -33,   -33,     0,     0,     0,   -33,
     -34,   -34,   -33,   -34,   -34,   -34,   -34,   -34,   -34,     0,
     -34,     0,     0,     0,     0,     0,     0,   -34,   -34,   -34,
       0,   -34,   -34,     0,   -34,     0,   -34,   -34,     0,     0,
       0,   -34,   -35,   -35,   -34,   -35,   -35,   -35,   -35,   -35,
     -35,     0,   -35,     0,     0,     0,     0,     0,     0,   -35,
     -35,   -35,     0,   -35,   -35,     0,   -35,     0,   -35,   -35,
       0,     0,     0,   -35,     0,     1,   -35,     2,     3,     4,
       5,   244,   245,     0,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,     0,   246,   247,     0,   248,     0,
     249,   250,     0,     0,     0,    17,     0,     0,   251,   -26,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,     0,     0,     0,     0,     0,     0,    -4,    -4,    -4,
       0,    -4,    -4,     0,    -4,     0,    -4,    -4,     0,     0,
       0,    -4,   -42,   -42,    -4,   -42,   -42,   -42,   -42,   -42,
     -42,     0,   -42,     0,     0,     0,     0,     0,     0,   -42,
     -42,   -42,     0,   -42,   -42,     0,   -42,     0,   -42,   -42,
       0,     0,     0,   -42,   -11,   -11,   -42,   -11,   -11,   -11,
     -11,   -11,   -11,     0,   -11,     0,     0,     0,     0,     0,
       0,   -11,   -11,   -11,     0,   -11,   -11,     0,   -11,     0,
     -11,   -11,     0,     0,     0,   -11,   -50,   -50,   -11,   -50,
     -50,   -50,   -50,   -50,   -50,     0,   -50,     0,     0,     0,
       0,     0,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,
     -50,     0,   -50,   -50,     0,     0,     0,   -50,   -49,   -49,
     -50,   -49,   -49,   -49,   -49,   -49,   -49,     0,   -49,     0,
       0,     0,     0,     0,     0,   -49,   -49,   -49,     0,   -49,
     -49,     0,   -49,     0,   -49,   -49,     0,     0,     0,   -49,
       0,   -29,   -49,   -29,   -29,   -29,   -29,   -29,   -29,     0,
     -29,     0,     0,     0,     0,     0,     0,   -29,   -29,   -29,
       0,   -29,   -29,     0,   -29,     0,   -29,   -29,     0,     0,
       0,   -29,     0,     0,   -29,   -29,     1,     0,     2,     3,
       4,     5,   244,   245,     0,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,     0,   246,   247,     0,   248,
       0,   249,   250,     0,     0,     0,    17,     0,     0,   251,
     -25,   -28,     0,   -28,   -28,   -28,   -28,   -28,   -28,     0,
     -28,     0,     0,     0,     0,     0,     0,   -28,   -28,   -28,
       0,   -28,   -28,     0,   -28,     0,   -28,   -28,     0,     0,
       0,   -28,     0,     0,   -28,   -28,   -30,     0,   -30,   -30,
     -30,   -30,   -30,   -30,     0,   -30,     0,     0,     0,     0,
       0,     0,   -30,   -30,   -30,     0,   -30,   -30,     0,   -30,
       0,   -30,   -30,     0,     0,     0,   -30,     0,     0,   -30,
     -30,   -24,   -24,     0,   -24,   -24,   -24,   -24,   -24,   -24,
       0,   -24,     0,     0,     0,     0,     0,     0,   -24,   -24,
     -24,     0,   -24,   -24,     0,   -24,     0,   -24,   -24,     0,
       0,     0,   -24,     0,   -27,   -24,   -27,   -27,   -27,   -27,
     -27,   -27,     0,   -27,     0,     0,     0,     0,     0,     0,
     -27,   -27,   -27,     0,   -27,   -27,     0,   -27,     0,   -27,
     -27,     0,     0,     0,   -27,     0,     0,   -27,   -27,   -12,
     -12,     0,   -12,   -12,   -12,   -12,   -12,   -12,     0,   -12,
       0,     0,     0,     0,     0,     0,   -12,   -12,   -12,     0,
     -12,   -12,     0,   -12,     0,   -12,   -12,     0,     0,     0,
     -12,   -10,   -10,   -12,   -10,   -10,   -10,   -10,   -10,   -10,
       0,   -10,     0,     0,     0,     0,     0,     0,   -10,   -10,
     -10,     0,   -10,   -10,     0,   -10,     0,   -10,   -10,     0,
       0,     0,   -10,   -41,   -41,   -10,   -41,   -41,   -41,   -41,
     -41,   -41,     0,   -41,     0,     0,     0,     0,     0,     0,
     -41,   -41,   -41,     0,   -41,   -41,     0,   -41,     0,   -41,
     -41,     0,     0,     0,   -41,   -37,   -37,   -41,   -37,   -37,
     -37,   -37,   -37,   -37,     0,   -37,     0,     0,     0,     0,
       0,     0,   -37,   -37,   -37,     0,   -37,   -37,     0,   -37,
       0,   -37,   -37,     0,     0,     0,   -37,   -40,   -40,   -37,
     -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,
       0,     0,     0,     0,   -40,   -40,   -40,     0,   -40,   -40,
       0,   -40,     0,   -40,   -40,     0,     0,     0,   -40,   -38,
     -38,   -40,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,
       0,     0,     0,     0,     0,     0,   -38,   -38,   -38,     0,
     -38,   -38,     0,   -38,     0,   -38,   -38,     0,     0,     0,
     -38,   -39,   -39,   -38,   -39,   -39,   -39,   -39,   -39,   -39,
       0,   -39,     0,     0,     0,     0,     0,     0,   -39,   -39,
     -39,     0,   -39,   -39,     0,   -39,     0,   -39,   -39,     0,
       0,     0,   -39,   -45,   -45,   -39,   -45,   -45,   -45,   -45,
     -45,   -45,     0,   -45,     0,     0,     0,     0,     0,     0,
     -45,   -45,   -45,     0,   -45,   -45,     0,   -45,     0,   -45,
     -45,     0,     0,     0,   -45,   -16,   -16,   -45,   -16,   -16,
     -16,   -16,   -16,   -16,     0,   -16,     0,     0,     0,     0,
       0,     0,   -16,   -16,   -16,     0,   -16,   -16,     0,   -16,
       0,   -16,   -16,     0,     0,     0,   -16,   -48,   -48,   -16,
     -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,
       0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,   -48,
       0,   -48,     0,   -48,   -48,     0,     0,     0,   -48,   -47,
     -47,   -48,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,
       0,     0,     0,     0,     0,     0,   -47,   -47,   -47,     0,
     -47,   -47,     0,   -47,     0,   -47,   -47,     0,     0,     0,
     -47,   -44,   -44,   -47,   -44,   -44,   -44,   -44,   -44,   -44,
       0,   -44,     0,     0,     0,     0,     0,     0,   -44,   -44,
     -44,     0,   -44,   -44,     0,   -44,     0,   -44,   -44,     0,
       0,     0,   -44,   -15,   -15,   -44,   -15,   -15,   -15,   -15,
     -15,   -15,     0,   -15,     0,     0,     0,     0,     0,     0,
     -15,   -15,   -15,     0,   -15,   -15,     0,   -15,     0,   -15,
     -15,     0,     0,     0,   -15,   -52,   -52,   -15,   -52,   -52,
     -52,   -52,   -52,   -52,     0,   -52,     0,     0,     0,     0,
       0,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,   -52,
       0,   -52,   -52,     0,     0,     0,   -52,   -53,   -53,   -52,
     -53,   -53,   -53,   -53,   -53,   -53,     0,   -53,     0,     0,
       0,     0,     0,     0,   -53,   -53,   -53,     0,   -53,   -53,
       0,   -53,     0,   -53,   -53,     0,     0,     0,   -53,   -54,
     -54,   -53,   -54,   -54,   -54,   -54,   -54,   -54,     0,   -54,
       0,     0,     0,     0,     0,     0,   -54,   -54,   -54,     0,
     -54,   -54,     0,   -54,     0,   -54,   -54,     0,     0,     0,
     -54,   -51,   -51,   -54,   -51,   -51,   -51,   -51,   -51,   -51,
       0,   -51,     0,     0,     0,     0,     0,     0,   -51,   -51,
     -51,     0,   -51,   -51,     0,   -51,     0,   -51,   -51,     0,
       0,     0,   -51,     0,   -32,   -51,   -32,   -32,   -32,   -32,
     -32,   -32,     0,   -32,     0,     0,     0,     0,     0,     0,
     -32,   -32,   -32,     0,   -32,   -32,     0,   -32,     0,   -32,
     -32,     0,     0,     0,   -32,     0,     0,   -32,   -32,   -36,
       0,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,     0,
       0,     0,     0,     0,     0,   -36,   -36,   -36,     0,   -36,
     -36,     0,   -36,     0,   -36,   -36,     0,     0,     0,   -36,
       0,     0,   -36,   -36,   -31,     0,   -31,   -31,   -31,   -31,
     -31,   -31,     0,   -31,     0,     0,     0,     0,     0,     0,
     -31,   -31,   -31,     0,   -31,   -31,     0,   -31,     0,   -31,
     -31,     0,     0,     0,   -31,     0,     0,   -31,   -31,   -33,
       0,   -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,     0,
       0,     0,     0,     0,     0,   -33,   -33,   -33,     0,   -33,
     -33,     0,   -33,     0,   -33,   -33,     0,     0,     0,   -33,
       0,     0,   -33,   -33,   -34,     0,   -34,   -34,   -34,   -34,
     -34,   -34,     0,   -34,     0,     0,     0,     0,     0,     0,
     -34,   -34,   -34,     0,   -34,   -34,     0,   -34,     0,   -34,
     -34,     0,     0,     0,   -34,     0,     0,   -34,   -34,   -35,
       0,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,     0,
       0,     0,     0,     0,     0,   -35,   -35,   -35,     0,   -35,
     -35,     0,   -35,     0,   -35,   -35,     0,     0,     0,   -35,
       0,     0,   -35,   -35,   -11,     0,   -11,   -11,   -11,   -11,
     -11,   -11,     0,   -11,     0,     0,     0,     0,     0,     0,
     -11,   -11,   -11,     0,   -11,   -11,     0,   -11,     0,   -11,
     -11,     0,     0,     0,   -11,     0,     0,   -11,   -11,   -42,
       0,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,     0,
       0,     0,     0,     0,     0,   -42,   -42,   -42,     0,   -42,
     -42,     0,   -42,     0,   -42,   -42,     0,     0,     0,   -42,
       0,     0,   -42,   -42,   -12,     0,   -12,   -12,   -12,   -12,
     -12,   -12,     0,   -12,     0,     0,     0,     0,     0,     0,
     -12,   -12,   -12,     0,   -12,   -12,     0,   -12,     0,   -12,
     -12,     0,     0,     0,   -12,     0,     0,   -12,   -12,   -10,
       0,   -10,   -10,   -10,   -10,   -10,   -10,     0,   -10,     0,
       0,     0,     0,     0,     0,   -10,   -10,   -10,     0,   -10,
     -10,     0,   -10,     0,   -10,   -10,     0,     0,     0,   -10,
       0,     0,   -10,   -10,   -50,     0,   -50,   -50,   -50,   -50,
     -50,   -50,     0,   -50,     0,     0,     0,     0,     0,     0,
     -50,   -50,   -50,     0,   -50,   -50,     0,   -50,     0,   -50,
     -50,     0,     0,     0,   -50,     0,     0,   -50,   -50,   -49,
       0,   -49,   -49,   -49,   -49,   -49,   -49,     0,   -49,     0,
       0,     0,     0,     0,     0,   -49,   -49,   -49,     0,   -49,
     -49,     0,   -49,     0,   -49,   -49,     0,     0,     0,   -49,
       0,     0,   -49,   -49,   -24,     0,   -24,   -24,   -24,   -24,
     -24,   -24,     0,   -24,     0,     0,     0,     0,     0,     0,
     -24,   -24,   -24,     0,   -24,   -24,     0,   -24,     0,   -24,
     -24,     0,     0,     0,   -24,     0,     0,   -24,   -24,   -41,
       0,   -41,   -41,   -41,   -41,   -41,   -41,     0,   -41,     0,
       0,     0,     0,     0,     0,   -41,   -41,   -41,     0,   -41,
     -41,     0,   -41,     0,   -41,   -41,     0,     0,     0,   -41,
       0,     0,   -41,   -41,   -37,     0,   -37,   -37,   -37,   -37,
     -37,   -37,     0,   -37,     0,     0,     0,     0,     0,     0,
     -37,   -37,   -37,     0,   -37,   -37,     0,   -37,     0,   -37,
     -37,     0,     0,     0,   -37,     0,     0,   -37,   -37,   -40,
       0,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,
       0,     0,     0,     0,     0,   -40,   -40,   -40,     0,   -40,
     -40,     0,   -40,     0,   -40,   -40,     0,     0,     0,   -40,
       0,     0,   -40,   -40,   -38,     0,   -38,   -38,   -38,   -38,
     -38,   -38,     0,   -38,     0,     0,     0,     0,     0,     0,
     -38,   -38,   -38,     0,   -38,   -38,     0,   -38,     0,   -38,
     -38,     0,     0,     0,   -38,     0,     0,   -38,   -38,   -39,
       0,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,     0,
       0,     0,     0,     0,     0,   -39,   -39,   -39,     0,   -39,
     -39,     0,   -39,     0,   -39,   -39,     0,     0,     0,   -39,
       0,     0,   -39,   -39,   -45,     0,   -45,   -45,   -45,   -45,
     -45,   -45,     0,   -45,     0,     0,     0,     0,     0,     0,
     -45,   -45,   -45,     0,   -45,   -45,     0,   -45,     0,   -45,
     -45,     0,     0,     0,   -45,     0,     0,   -45,   -45,   -48,
       0,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,     0,
       0,     0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,
     -48,     0,   -48,     0,   -48,   -48,     0,     0,     0,   -48,
       0,     0,   -48,   -48,   -47,     0,   -47,   -47,   -47,   -47,
     -47,   -47,     0,   -47,     0,     0,     0,     0,     0,     0,
     -47,   -47,   -47,     0,   -47,   -47,     0,   -47,     0,   -47,
     -47,     0,     0,     0,   -47,     0,     0,   -47,   -47,   -44,
       0,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,     0,
       0,     0,     0,     0,     0,   -44,   -44,   -44,     0,   -44,
     -44,     0,   -44,     0,   -44,   -44,     0,     0,     0,   -44,
       0,     0,   -44,   -44,   -52,     0,   -52,   -52,   -52,   -52,
     -52,   -52,     0,   -52,     0,     0,     0,     0,     0,     0,
     -52,   -52,   -52,     0,   -52,   -52,     0,   -52,     0,   -52,
     -52,     0,     0,     0,   -52,     0,     0,   -52,   -52,   -53,
       0,   -53,   -53,   -53,   -53,   -53,   -53,     0,   -53,     0,
       0,     0,     0,     0,     0,   -53,   -53,   -53,     0,   -53,
     -53,     0,   -53,     0,   -53,   -53,     0,     0,     0,   -53,
       0,     0,   -53,   -53,   -54,     0,   -54,   -54,   -54,   -54,
     -54,   -54,     0,   -54,     0,     0,     0,     0,     0,     0,
     -54,   -54,   -54,     0,   -54,   -54,     0,   -54,     0,   -54,
     -54,     0,     0,     0,   -54,     0,     0,   -54,   -54,   -51,
       0,   -51,   -51,   -51,   -51,   -51,   -51,     0,   -51,     0,
       0,     0,     0,     0,     0,   -51,   -51,   -51,     0,   -51,
     -51,     0,   -51,     0,   -51,   -51,     0,     0,     0,   -51,
       0,     0,   -51,   -51,     1,     0,     2,     3,     4,     5,
     290,   291,     0,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,     0,     0,     0,     0,   292,   546,   293,
     294,     0,     0,     0,    17,     0,     1,   295,     2,     3,
       4,     5,   290,   291,     0,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,     0,     0,     0,     0,   292,
     548,   293,   294,     0,     0,     0,    17,     0,     1,   295,
       2,     3,     4,     5,   520,   521,     0,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,     0,     0,     0,
       0,   522,   620,   524,   525,     0,     0,     0,    17,     0,
       1,   526,     2,     3,     4,     5,   520,   521,     0,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,     0,
       0,     0,     0,   522,   622,   524,   525,     0,     0,     0,
      17,     0,     1,   526,     2,     3,     4,     5,     6,     7,
       0,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,     0,     0,     0,     0,    14,     0,    15,    16,     0,
       0,     0,    17,     0,     1,    18,     2,     3,     4,     5,
     244,   245,     0,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,     0,     0,     0,     0,   248,     0,   249,
     250,     0,     0,     0,    17,     0,     1,   251,     2,     3,
       4,     5,   290,   291,     0,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,     0,     0,     0,     0,   292,
       0,   293,   294,     0,     0,     0,    17,     0,     1,   295,
       2,     3,     4,     5,   520,   521,     0,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,     0,     0,     0,
       0,   522,     0,   524,   525,     0,     0,     0,    17,     0,
     359,   526,   206,   207,   208,   209,     0,     0,     0,     8,
     385,     0,   374,   375,   376,   377,     9,    10,    11,     8,
     388,     0,   374,   375,   376,   377,     9,    10,    11,     8,
     210,     0,     0,     0,     0,     0,     9,    10,    11,   390,
     378,   374,   375,   376,   377,     0,     0,     0,     8,   392,
     378,   374,   375,   376,   377,     9,    10,    11,     8,   394,
       0,   374,   375,   376,   377,     9,    10,    11,     8,   378,
       0,     0,     0,     0,     0,     9,    10,    11,   402,   378,
       2,     3,     4,     5,     0,     0,     0,     8,   410,   378,
     325,   326,   327,   328,     9,    10,    11,     8,   412,     0,
     325,   326,   327,   328,     9,    10,    11,     8,    17,     0,
       0,     0,     0,     0,     9,    10,    11,   414,   329,   325,
     326,   327,   328,     0,     0,     0,     8,   416,   329,   325,
     326,   327,   328,     9,    10,    11,     8,   418,     0,   325,
     326,   327,   328,     9,    10,    11,     8,   329,     0,     0,
       0,     0,     0,     9,    10,    11,   420,   329,   325,   326,
     327,   328,     0,     0,     0,     8,   422,   329,   325,   326,
     327,   328,     9,    10,    11,     8,   424,     0,   325,   326,
     327,   328,     9,    10,    11,     8,   329,     0,     0,     0,
       0,     0,     9,    10,    11,   426,   329,   325,   326,   327,
     328,     0,     0,     0,     8,   432,   329,   206,   207,   208,
     209,     9,    10,    11,     8,   441,     0,   206,   207,   208,
     209,     9,    10,    11,     8,   329,     0,     0,     0,     0,
       0,     9,    10,    11,   450,   210,   374,   375,   376,   377,
       0,     0,     0,     8,   452,   210,   374,   375,   376,   377,
       9,    10,    11,     8,   454,     0,   374,   375,   376,   377,
       9,    10,    11,     8,   378,     0,     0,     0,     0,     0,
       9,    10,    11,   456,   378,   374,   375,   376,   377,     0,
       0,     0,     8,   458,   378,   374,   375,   376,   377,     9,
      10,    11,     8,   460,     0,   374,   375,   376,   377,     9,
      10,    11,     8,   378,     0,     0,     0,     0,     0,     9,
      10,    11,   462,   378,   374,   375,   376,   377,     0,     0,
       0,     8,   464,   378,   374,   375,   376,   377,     9,    10,
      11,     8,   466,     0,   374,   375,   376,   377,     9,    10,
      11,     8,   378,     0,     0,     0,     0,     0,     9,    10,
      11,   469,   378,   206,   207,   208,   209,     0,     0,     0,
       8,   478,   378,   206,   207,   208,   209,     9,    10,    11,
       8,   558,     0,     2,     3,     4,     5,     9,    10,    11,
       8,   210,     0,     0,     0,     0,     0,     9,    10,    11,
     578,   210,   206,   207,   208,   209,     0,     0,     0,     8,
       0,    17,     0,     0,     0,     0,     9,    10,    11,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,     0,     0,     0,
     210,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,     0,
     -97,     0,   -97,   -97,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,  -105,     0,  -105,  -105,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,     0,   -92,     0,   -92,   -92,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -107,     0,  -107,
    -107,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,     0,
    -106,     0,  -106,  -106,   368,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -98,     0,   -98,   -98,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,     0,     0,     0,   -83,   -83,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,     0,     0,  -114,
    -114,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,
       0,     0,  -115,  -115,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,     0,     0,  -113,  -113,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,     0,     0,     0,   -90,   -90,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,     0,     0,   -91,
     -91,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,     0,
       0,     0,   -97,   -97,   368,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,     0,     0,  -105,  -105,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,     0,     0,     0,   -86,   -86,   281,
     282,   283,   284,   -62,   286,   287,   288,     0,     0,   -87,
     -87,   281,   282,   283,   -66,   -66,   286,   287,   288,     0,
       0,     0,   -62,   -62,   281,   282,   283,   -70,   -70,   -70,
     287,   288,     0,     0,   -66,   -66,   281,   282,   -74,   -74,
     -74,   -74,   287,   288,     0,     0,     0,   -70,   -70,   281,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,     0,     0,   -74,
     -74,   368,   -84,   -84,   -84,   -84,   -84,   -84,   -84,     0,
       0,     0,   -85,   -85,   281,   282,   -80,   -80,   -80,   -80,
     287,   288,     0,     0,   -84,   -84,   281,   282,   -79,   -79,
     -79,   -79,   287,   288,     0,     0,     0,   -80,   -80,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,     0,     0,   -79,
     -79,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,     0,
       0,     0,   -89,   -89,   281,   282,   283,   284,   285,   286,
     287,   288,     0,     0,   -88,   -88,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,     0,     0,     0,   -57,   -57,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,     0,     0,   -92,
     -92,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,     0,
       0,     0,  -107,  -107,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,     0,     0,  -106,  -106,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,     0,     0,     0,   -98,   -98,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -104,   320,  -104,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,     0,     0,
    -114,     0,  -114,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -115,     0,  -115,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,     0,     0,  -113,     0,  -113,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   318,     0,   -87,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,     0,     0,   -91,     0,
     -91,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   -97,
       0,   -97,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
       0,     0,  -105,     0,  -105,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,   -92,     0,   -92,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,     0,     0,     0,   435,  -104,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -107,     0,  -107,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,     0,     0,
    -106,     0,  -106,   236,   237,   238,   239,   240,   241,   242,
     243,   -98,     0,   -98,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,     0,     0,   149,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,   152,   317,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,     0,     0,     0,     0,
     199,   236,   237,   238,   239,   240,   241,   242,   243,     0,
       0,   -83,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     0,     0,     0,   408,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,     0,     0,   429,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,     0,     0,     0,     0,  -114,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,     0,  -115,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,     0,     0,
       0,     0,  -113,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,     0,     0,   -90,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,     0,     0,     0,     0,   -91,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,     0,     0,   -97,   317,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,     0,     0,     0,     0,
    -105,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,     0,
       0,   -86,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     0,     0,     0,   -87,   236,   237,   238,   239,   -62,
     241,   242,   243,     0,     0,   448,   236,   237,   238,   -66,
     -66,   241,   242,   243,     0,     0,     0,     0,   -62,   236,
     237,   238,   -70,   -70,   -70,   242,   243,     0,     0,   -66,
     236,   237,   -74,   -74,   -74,   -74,   242,   243,     0,     0,
       0,     0,   -70,   236,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,     0,     0,   -74,   317,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,     0,     0,     0,     0,   -85,   236,   237,   -80,
     -80,   -80,   -80,   242,   243,     0,     0,   -84,   236,   237,
     -79,   -79,   -79,   -79,   242,   243,     0,     0,     0,     0,
     -80,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,     0,
       0,   -79,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
       0,     0,     0,     0,   -89,   236,   237,   238,   239,   240,
     241,   242,   243,     0,     0,   -88,   236,   237,   238,   239,
     240,   241,   242,   243,     0,     0,     0,     0,   -57,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,     0,     0,   487,
     236,   237,   238,   239,   240,   241,   242,   243,     0,     0,
       0,     0,   -92,   236,   237,   238,   239,   240,   241,   242,
     243,     0,     0,   492,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,     0,     0,   495,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,   501,   236,   237,
     238,   239,   240,   241,   242,   243,     0,     0,     0,     0,
     506,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,     0,
       0,   509,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
       0,     0,     0,     0,  -107,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,     0,     0,  -106,   236,   237,   238,   239,
     240,   241,   242,   243,     0,     0,     0,     0,   -98,   236,
     237,   238,   239,   240,   241,   242,   243,     0,     0,   599,
     236,   237,   238,   239,   240,   241,   242,   243,     0,     0,
       0,     0,   602,   236,   237,   238,   239,   240,   241,   242,
     243,     0,     0,   609,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,     0,     0,   613,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,     0,     0,   649,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,     0,  -108,  -108,  -108,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
      78,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,     0,
    -104,     0,   324,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -115,  -115,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,     0,     0,  -113,  -113,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -87,    76,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,     0,     0,   -91,   -91,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,   -97,   -97,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,     0,     0,  -105,  -105,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,   -92,   -92,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,     0,     0,  -107,
    -107,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,  -106,
    -106,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,   -98,   -98,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   107,    75,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
       0,     0,     0,   -90,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -86,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,   -87,    46,    47,    48,    49,   -62,
      51,    52,    53,   154,    46,    47,    48,   -66,   -66,    51,
      52,    53,     0,     0,     0,   -62,    46,    47,    48,   -70,
     -70,   -70,    52,    53,   -66,    46,    47,   -74,   -74,   -74,
     -74,    52,    53,     0,     0,     0,   -70,    46,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -74,    75,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,     0,     0,     0,   -85,    46,    47,
     -80,   -80,   -80,   -80,    52,    53,   -84,    46,    47,   -79,
     -79,   -79,   -79,    52,    53,     0,     0,     0,   -80,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -79,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,     0,     0,     0,   -89,
      46,    47,    48,    49,    50,    51,    52,    53,   -88,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,     0,
     -57,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,   187,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,     0,     0,
       0,  -114,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -115,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,     0,
       0,     0,  -113,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -91,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
       0,     0,     0,   -97,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,  -105,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,   -92,    46,    47,    48,    49,    50,
      51,    52,    53,   445,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,     0,     0,     0,   482,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -107,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,  -106,    46,    47,    48,
      49,    50,    51,    52,    53,   497,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,     0,     0,     0,   511,    46,    47,
      48,    49,    50,    51,    52,    53,   -98,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,   565,    46,
      47,    48,    49,    50,    51,    52,    53,   571,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,   582,
      46,    47,    48,    49,    50,    51,    52,    53,   604,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     639
};

static const yytype_int16 yycheck[] =
{
       0,   251,     0,     0,   357,   350,   320,     6,    31,     1,
     324,     3,     4,     5,     6,     1,    16,    17,    10,     6,
      20,     0,    20,    20,    23,    17,    18,    19,     1,     1,
      29,    32,    31,     0,     6,    21,    22,    31,     6,    31,
      32,    20,    29,     6,    31,   295,    32,     6,    21,    22,
       6,   404,   154,   155,   399,    55,     6,   371,    58,    32,
      23,    29,    31,    31,    64,    31,    29,    23,    31,     6,
      29,    13,     1,    29,     3,     4,     5,     6,    78,    29,
      29,    10,    80,     6,   186,   187,   188,    29,    17,    18,
      19,    20,    29,     0,     1,    29,     3,     4,     5,     6,
       7,     8,    31,    10,    13,     6,    29,     9,    31,    13,
      17,    18,    19,   113,    21,    22,     6,    24,    25,    26,
      27,   435,    23,    32,    31,    29,     1,    34,     3,     4,
       5,     6,    13,    23,    32,    10,    32,    33,     6,    29,
      12,    13,    17,    18,    19,     1,    13,     3,     4,     5,
       6,    32,   152,   153,    10,    23,    31,    32,   472,   159,
      32,    17,    18,    19,   162,    32,    33,   165,    32,    33,
       0,    32,   172,   152,   153,    31,    32,    12,    13,    14,
      11,    12,    13,    14,   184,   185,   186,   187,   188,    32,
      20,     0,    32,   172,    29,    32,    33,   197,   198,   199,
     200,    32,    33,     1,    32,   184,   185,   560,     6,   554,
     210,    20,    11,    12,    13,    14,    12,    13,   197,   198,
     199,   200,    32,     1,    29,     3,     4,     5,     6,   229,
       1,     0,    10,    32,    33,     6,    32,    33,    29,    17,
      18,    19,     3,     4,     5,     6,    29,    30,    31,    10,
     250,    20,   354,    31,    32,    13,    17,    18,    19,    32,
      33,     0,     1,   263,     3,     4,     5,     6,     7,     8,
      31,    10,    12,    13,    32,    33,   526,    32,    17,    18,
      19,    35,    21,    22,    32,    24,    25,    26,    27,    29,
      12,    13,    31,     1,   294,    34,    32,    33,     6,   401,
       1,     6,     3,     4,     5,     6,    12,    13,    14,    10,
      32,    33,    12,    13,     0,    29,    17,    18,    19,     1,
     320,    34,   152,   153,   324,    29,    32,    33,    29,   329,
      31,   161,    32,    33,    20,    12,    13,    14,    29,    30,
      31,    29,   172,   152,   153,    29,    11,    12,    13,    14,
     350,    29,    29,   353,   184,   185,     1,   357,     3,     4,
       5,     6,    29,   172,    29,    10,   196,   197,   198,   199,
     200,   371,    17,    18,    19,   184,   185,    29,   378,    29,
      30,    12,    13,   152,   153,    29,    31,    32,   197,   198,
     199,   200,    32,    12,    13,   497,   498,    12,    13,   399,
     400,    32,    32,   172,   404,     3,     4,     5,     6,   511,
     512,    32,    10,    32,    29,   184,   185,    12,    13,    17,
      18,    19,    32,    11,    12,    13,    14,    32,   197,   198,
     199,   200,    32,    31,    29,   435,    10,    11,    12,    13,
      14,    15,    16,     1,    32,     3,     4,     5,     6,    31,
       9,    10,    10,    21,    22,   557,    15,    16,    32,    17,
      18,    19,   564,   565,   566,    31,   152,   153,   570,   571,
     572,    31,   472,    31,    32,    31,     1,    29,     3,     4,
       5,     6,    32,    33,    31,    10,   172,    11,    12,    13,
      14,    31,    17,    18,    19,   495,   496,    31,   184,   185,
      32,    33,   604,   605,    29,    31,    31,    29,    32,   509,
     510,   197,   198,   199,   200,     1,   495,   496,    32,    33,
       0,    29,    30,   523,    29,   525,    11,    12,    13,    14,
     509,   510,    11,    12,    13,    14,   638,   639,   640,    32,
      20,    32,    33,    32,   523,    32,   546,    32,    33,     9,
      32,    29,     6,    32,   554,   555,    11,    12,    13,    14,
     560,   561,     6,   563,   564,   565,   566,   546,   568,   569,
     570,   571,   572,     9,    32,    32,     1,    32,     3,     4,
       5,     6,   561,    29,   563,    10,    29,    32,    35,   568,
     569,    32,    17,    18,    19,    10,    11,    12,    13,    14,
      15,    16,   602,   603,    29,    32,    31,   607,   608,   609,
     610,   611,   612,   613,   614,     9,    10,    32,    33,    32,
     620,    15,    16,   602,   603,    12,    13,    14,   607,   608,
     609,   610,   611,   612,   613,   614,   636,   637,   638,   639,
     640,   620,    29,    11,    12,    13,    14,   647,   648,   649,
     650,    32,    32,    32,    32,    32,    32,   636,   637,    32,
       3,     4,     5,     6,    32,   495,   496,    10,   647,   648,
     649,   650,   152,   153,    17,    18,    19,     0,    32,   509,
     510,    11,    12,    13,    14,    32,   495,   496,    31,    29,
      35,    32,   172,    11,    12,    13,    14,    20,    29,    32,
     509,   510,    32,    33,   184,   185,     1,    29,     3,     4,
       5,     6,    29,    29,    32,    10,   546,   197,   198,   199,
     200,    29,    17,    18,    19,    20,   495,   496,    11,    12,
      13,    14,    11,    12,    13,    14,    31,   546,   568,   569,
     509,   510,    29,    29,     0,     1,    29,     3,     4,     5,
       6,     7,     8,    32,    10,    29,    29,    29,    29,   568,
     569,    17,    18,    19,    31,    21,    22,    31,    24,    25,
      26,    27,   602,   603,    31,    31,    31,   546,    34,    29,
      29,   611,   612,   613,   614,     9,    10,    11,    29,    29,
     620,    15,    16,   602,   603,    12,    13,    14,    29,   568,
     569,    29,   611,   612,   613,   614,   636,   637,    35,   495,
     496,   620,    12,    13,    14,    32,    33,   647,   648,   649,
     650,    32,    32,   509,   510,    32,    32,   636,   637,   152,
     153,    32,    32,   602,   603,    32,    32,    32,   647,   648,
     649,   650,   611,   612,   613,   614,    12,    13,    14,   172,
      32,   620,     9,    10,    11,    12,    13,    14,    15,    16,
     546,   184,   185,     9,    10,    11,    32,   636,   637,    15,
      16,    32,    29,    30,   197,   198,   199,   200,   647,   648,
     649,   650,   568,   569,     0,     1,    29,     3,     4,     5,
       6,     7,     8,    32,    10,    29,    11,    12,    13,    14,
      29,    17,    18,    19,    29,    21,    22,    29,    24,    25,
      26,    27,    29,    32,    29,    31,   602,   603,    34,    29,
      11,    12,    13,    14,    32,   611,   612,   613,   614,     3,
       4,     5,     6,    32,   620,    20,    10,     1,    29,     3,
       4,     5,     6,    17,    18,    19,    10,   165,   162,   158,
     636,   637,    -1,    17,    18,    19,    20,    31,   113,    -1,
      -1,   647,   648,   649,   650,     0,     1,    31,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    11,    12,    13,
      14,    -1,    17,    18,    19,    -1,    21,    22,    -1,    24,
      25,    26,    27,    12,    13,    14,    31,    -1,    32,    34,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    32,    33,   495,   496,    17,    18,    19,
      -1,    21,    22,    -1,    24,    25,    26,    27,    -1,   509,
     510,    31,    -1,     1,    34,     3,     4,     5,     6,    -1,
      17,    -1,    10,    -1,    11,    12,    13,    14,    -1,    17,
      18,    19,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    29,    -1,    31,    -1,    32,   546,    44,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    12,    13,    14,    -1,    -1,    -1,   568,   569,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    32,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,   602,   603,    30,    31,    32,    33,    17,    18,
      19,   611,   612,   613,   614,    24,    25,    26,    27,   116,
     620,    -1,    31,    -1,    -1,    34,     1,    -1,     3,     4,
       5,     6,     9,    10,    11,    10,   636,   637,    15,    16,
      -1,    -1,    17,    18,    19,    -1,   143,   647,   648,   649,
     650,    -1,   495,   496,    29,    -1,    31,    -1,     3,     4,
       5,     6,   159,     9,    10,    10,   509,   510,    -1,    15,
      16,    -1,    17,    18,    19,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    31,    -1,    -1,   186,
     187,   188,    17,    18,    19,    -1,    21,    22,    -1,    24,
      25,    26,    27,   546,    -1,    -1,    31,    -1,    -1,    34,
      -1,    -1,    -1,   210,     9,    10,    11,    12,    13,    14,
      15,    16,   219,    -1,    -1,   568,   569,    -1,    -1,    -1,
      -1,    -1,   229,   230,    -1,    30,    31,    32,    33,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    -1,    -1,   602,
     603,    -1,    17,    18,    19,    -1,   263,    -1,   611,   612,
     613,   614,    -1,    -1,    -1,   272,    31,   620,    -1,    11,
      12,    13,    14,    -1,   281,   282,   283,   284,   285,   286,
     287,   288,    -1,   636,   637,    -1,     3,     4,     5,     6,
      32,    33,    -1,    10,   647,   648,   649,   650,    -1,    -1,
      17,    18,    19,   310,   311,   312,   313,   314,   315,   316,
     317,   318,    -1,   320,    31,    -1,    -1,   324,    11,    12,
      13,    14,   329,     1,   331,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    29,    -1,    -1,    17,
      18,    19,   349,   350,    -1,    -1,   353,    -1,    -1,    17,
      -1,    29,    -1,    31,   361,   362,   363,   364,   365,   366,
     367,   368,   369,    -1,   371,    -1,    -1,    11,    12,    13,
      14,   378,    40,   380,    11,    12,    13,    14,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    32,    33,
      58,   398,   399,   400,    -1,    32,    33,    -1,    -1,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    -1,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    11,    12,    13,    14,   435,    17,
      18,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    32,    34,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    11,    12,    13,    14,   472,    17,    18,    19,    -1,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    29,
      31,    -1,    -1,    34,    -1,     1,    -1,     3,     4,     5,
       6,   159,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,    29,    10,    31,    -1,    -1,   186,   187,
     188,    17,    18,    19,    -1,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    -1,   210,    -1,    -1,    -1,   553,   554,   555,    -1,
      -1,   219,    -1,    -1,    -1,    -1,    -1,   564,   565,   566,
      -1,   229,   230,   570,   571,   572,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    11,    12,    13,
      14,    -1,    17,    18,    19,   263,    21,    22,    -1,    24,
      25,    26,    27,    -1,   272,    29,    31,    -1,    -1,    34,
      35,    -1,    -1,   281,   282,   283,   284,   285,   286,   287,
     288,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      10,   638,   639,   640,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,   310,   311,   312,   313,   314,   315,   316,   317,
     318,    31,   320,    -1,    -1,    -1,   324,    11,    12,    13,
      14,   329,     1,   331,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    29,    -1,    -1,    17,    18,
      19,    -1,   350,    -1,    -1,   353,    -1,    17,    -1,    -1,
      29,    -1,    31,   361,   362,   363,   364,   365,   366,   367,
     368,   369,    -1,   371,    -1,    11,    12,    13,    14,    -1,
     378,    -1,   380,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    32,    33,    58,    -1,
      -1,   399,   400,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    11,    12,    13,    14,   435,    17,    18,
      19,    -1,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    29,    31,    -1,    -1,    34,    -1,    -1,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      11,    12,    13,    14,   472,    17,    18,    19,    -1,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    29,    31,
      -1,     1,    34,     3,     4,     5,     6,     7,     8,   159,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,   186,   187,   188,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    11,    12,    13,    14,    -1,    17,    18,    19,    -1,
     210,    -1,    -1,    -1,    -1,    -1,   554,   555,    29,   219,
      31,    -1,    32,    33,    -1,    -1,   564,   565,   566,   229,
     230,    -1,   570,   571,   572,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,   263,    21,    22,    -1,    24,    25,    26,
      27,    -1,   272,    -1,    31,    -1,    -1,    34,    35,    -1,
      -1,   281,   282,   283,   284,   285,   286,   287,   288,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,
     638,   639,   640,    -1,    -1,    17,    18,    19,    -1,    -1,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    31,
     320,     9,    10,    11,   324,    -1,    14,    15,    16,   329,
       1,   331,     3,     4,     5,     6,    -1,    -1,    -1,    10,
       1,    -1,     3,     4,     5,     6,    17,    18,    19,    10,
     350,    -1,    -1,   353,    -1,    17,    17,    18,    19,    -1,
      31,   361,   362,   363,   364,   365,   366,   367,   368,   369,
      31,   371,    -1,    11,    12,    13,    14,    -1,   378,    -1,
     380,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    32,    33,    58,    -1,    -1,   399,
     400,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,   435,    17,    18,    19,    -1,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,   472,    17,    18,    19,    -1,    21,    22,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,     3,     4,     5,     6,   159,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    31,    -1,    -1,   186,   187,   188,    17,    18,    19,
      -1,    21,    22,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,   554,   555,    -1,   219,    -1,    -1,
      -1,    -1,    -1,    -1,   564,   565,   566,   229,   230,    -1,
     570,   571,   572,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,   263,    21,    22,    -1,    24,    25,    26,    27,    -1,
     272,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,   281,
     282,   283,   284,   285,   286,   287,   288,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,   638,   639,
     640,    -1,    -1,    17,    18,    19,    -1,    -1,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    31,   320,     9,
      10,    11,   324,    -1,    14,    15,    16,   329,     1,   331,
       3,     4,     5,     6,    -1,    -1,    -1,    10,     1,    -1,
       3,     4,     5,     6,    17,    18,    19,    10,   350,    -1,
      -1,   353,    -1,    17,    17,    18,    19,    -1,    31,   361,
     362,   363,   364,   365,   366,   367,   368,   369,    31,   371,
      -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,   380,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    -1,    58,    -1,    -1,   399,   400,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,   435,    17,    18,    19,    -1,    21,    22,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
     472,    17,    18,    19,    -1,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,     7,     8,   159,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,   186,   187,   188,    -1,     1,    -1,     3,     4,
       5,     6,     9,    10,    11,    10,    -1,    14,    15,    16,
      -1,    -1,    17,    18,    19,    -1,   210,    -1,    -1,    -1,
      -1,    -1,   554,   555,    -1,   219,    31,    -1,    -1,    -1,
      -1,    -1,   564,   565,   566,   229,   230,    -1,   570,   571,
     572,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,   263,
      21,    22,    -1,    24,    25,    26,    27,    -1,   272,    -1,
      31,    -1,    -1,    34,    35,    -1,    -1,   281,   282,   283,
     284,   285,   286,   287,   288,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    -1,   638,   639,   640,    -1,
      -1,    17,    18,    19,    -1,    -1,   310,   311,   312,   313,
     314,   315,   316,   317,   318,    31,   320,    -1,    -1,    -1,
     324,    -1,    -1,    -1,    -1,   329,     1,   331,     3,     4,
       5,     6,    -1,    -1,    -1,    10,     1,    -1,     3,     4,
       5,     6,    17,    18,    19,    10,   350,    -1,    -1,   353,
      -1,    17,    17,    18,    19,    -1,    31,   361,   362,   363,
     364,   365,   366,   367,   368,   369,    31,   371,    -1,    -1,
      -1,    -1,    -1,    -1,   378,    -1,   380,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      -1,    -1,    58,    -1,    -1,   399,   400,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    -1,    -1,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,   435,    17,    18,    19,    -1,    21,    22,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      -1,    -1,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,   472,    17,
      18,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,     7,     8,   159,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
     186,   187,   188,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,   210,    -1,    -1,    -1,    -1,    -1,
     554,   555,    -1,   219,    31,    -1,    -1,    -1,    -1,    -1,
     564,   565,   566,   229,   230,    -1,   570,   571,   572,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,   263,    21,    22,
      -1,    24,    25,    26,    27,    -1,   272,    -1,    31,    -1,
      -1,    34,    35,    -1,    -1,   281,   282,   283,   284,   285,
     286,   287,   288,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    -1,   638,   639,   640,    -1,    -1,    17,
      18,    19,    -1,    -1,   310,   311,   312,   313,   314,   315,
     316,   317,   318,    31,   320,    -1,    -1,    -1,   324,    -1,
      -1,    -1,    -1,   329,     1,   331,     3,     4,     5,     6,
      -1,    -1,    -1,    10,     1,    -1,     3,     4,     5,     6,
      17,    18,    19,    10,   350,    -1,    -1,   353,    -1,    17,
      17,    18,    19,    -1,    31,   361,   362,   363,   364,   365,
     366,   367,   368,   369,    31,   371,    -1,    -1,    -1,    -1,
      -1,    -1,   378,    -1,   380,    -1,     9,    10,    11,    12,
      48,    14,    15,    16,    52,    53,    -1,    55,    -1,    -1,
      58,    -1,    -1,   399,   400,     9,    10,    11,    12,    13,
      14,    15,    16,    71,    -1,    73,    74,    -1,    -1,    -1,
      78,    -1,    -1,     0,     1,    29,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,   435,
      17,    18,    19,    -1,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,   472,    17,    18,    19,
      -1,    21,    22,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,     7,
       8,   159,    10,    -1,    -1,    17,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    -1,   186,   187,
     188,    -1,    -1,    -1,    -1,    47,    10,    11,    12,    13,
      14,    15,    16,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    29,    -1,    -1,   554,   555,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,   564,   565,
     566,   229,    -1,    -1,   570,   571,   572,    -1,    -1,    -1,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,   263,    17,    18,    19,    -1,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    -1,   283,   284,   285,   286,   287,
     288,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,   638,   639,   640,    -1,    -1,   159,    -1,    -1,
      -1,    -1,   310,   311,   312,   313,    32,   315,   316,    -1,
     318,    -1,   320,    -1,    -1,    -1,   324,    -1,    -1,    -1,
      -1,   329,    -1,    -1,   186,   187,   188,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,   350,    10,    -1,   353,    -1,    -1,   210,    -1,
      17,    18,    19,   361,   362,   363,   364,    -1,   366,   367,
      -1,   369,    -1,   371,    31,    -1,    -1,   229,    -1,    -1,
     378,    -1,    -1,    -1,    -1,   237,   238,   239,   240,   241,
     242,   243,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,   399,   400,    -1,    -1,    -1,    17,    18,    19,    -1,
       1,   263,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      31,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,
     282,   283,   284,   285,   286,   287,   288,   435,    -1,     1,
      31,     3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,    31,
      -1,    -1,   324,    -1,   472,    -1,     1,   329,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    -1,    -1,    -1,   350,    -1,
      -1,   353,    -1,    17,    -1,    -1,    31,    -1,    -1,   361,
     362,   363,   364,   365,   366,   367,    -1,   369,    -1,   371,
       1,    -1,     3,     4,     5,     6,   378,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,
      -1,    55,    -1,    -1,    58,    -1,    -1,   399,   400,    -1,
      31,    -1,    -1,    -1,    -1,    -1,   554,   555,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,   564,   565,   566,    -1,
      -1,    -1,   570,   571,   572,     1,    -1,     3,     4,     5,
       6,     7,     8,   435,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      17,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
     472,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,     9,    10,    11,    12,    13,    14,    15,    16,
     638,   639,   640,    31,    51,   159,    -1,    -1,    55,    -1,
      -1,    58,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    70,    -1,    -1,    -1,    -1,    17,    18,
      19,    78,   186,   187,   188,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,   554,   555,    -1,    -1,    -1,    30,    -1,    32,
      33,    -1,   564,   565,   566,   229,    -1,    -1,   570,   571,
     572,    -1,    -1,    -1,   238,   239,   240,   241,   242,   243,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,   263,
      21,    22,   159,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,   283,
     284,   285,   286,   287,   288,    -1,    -1,    -1,    -1,   186,
     187,   188,    -1,    -1,    -1,    -1,   638,   639,   640,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,   311,   312,   313,
      -1,   315,   316,   210,   318,    -1,   320,    -1,    -1,    -1,
     324,     9,    10,    11,    12,   329,    14,    15,    16,    -1,
      -1,    -1,   229,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,   239,   240,   241,    -1,   350,    -1,    -1,   353,
      -1,    -1,    -1,    -1,    30,    31,    32,   361,   362,   363,
     364,    -1,   366,   367,    -1,   369,   263,   371,     1,    -1,
       3,     4,     5,     6,   378,    -1,    -1,    10,    17,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,   284,   285,   286,
       3,     4,     5,     6,    -1,   399,   400,    10,    31,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,
      49,    -1,    -1,   310,   311,   312,    55,    -1,    31,    58,
      -1,   318,    -1,   320,    -1,    -1,    -1,   324,    -1,    -1,
      69,   435,   329,     1,    -1,     3,     4,     5,     6,    78,
      -1,    -1,    10,     1,    -1,     3,     4,     5,     6,    17,
      18,    19,    10,   350,    -1,    -1,   353,    -1,    -1,    17,
      18,    19,    -1,    31,   361,   362,   363,    -1,   472,    -1,
      -1,    -1,   369,    31,   371,    -1,    -1,    -1,    -1,    -1,
      -1,   378,    -1,    17,    -1,    -1,    -1,    -1,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,   399,   400,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    25,    26,    27,    50,    -1,    -1,    31,
     159,    55,    34,     1,    58,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    -1,    68,    -1,    -1,    -1,   435,    17,
      18,    19,    -1,    -1,    78,    -1,    -1,   186,   187,   188,
     554,   555,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
     564,   565,   566,    -1,    -1,    -1,   570,   571,   572,    -1,
      -1,   210,    -1,    -1,    -1,   472,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     1,
     229,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
     239,   240,    31,    32,    33,    17,    18,    19,    -1,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    -1,   263,   159,     9,    10,    11,    12,
      13,    14,    15,    16,   638,   639,   640,     9,    10,    11,
      12,    13,    14,    15,    16,   284,   285,    30,    -1,    32,
      33,    -1,   186,   187,   188,    -1,    -1,   554,   555,     9,
      10,    11,    12,    13,    14,    15,    16,   564,   565,   566,
      -1,   310,   311,   570,   571,   572,   210,    -1,    -1,   318,
      30,   320,    32,    33,    -1,   324,     9,    10,    11,    12,
     329,    14,    15,    16,    -1,   229,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,   240,    17,    -1,    -1,
      -1,   350,    -1,    -1,   353,    -1,    -1,    30,    -1,    32,
      33,    -1,   361,   362,    -1,    -1,    -1,    -1,    -1,   263,
     369,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,   378,
      -1,   638,   639,   640,    -1,    55,    -1,    -1,    58,    -1,
      -1,   285,    -1,     1,    -1,     3,     4,     5,     6,    -1,
     399,   400,    10,    -1,    -1,    -1,    76,    -1,    78,    17,
      18,    19,    -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,
      -1,    -1,    -1,    31,   318,    -1,   320,    -1,    -1,    -1,
     324,    -1,    -1,    -1,    -1,   329,   435,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,   350,    -1,    30,   353,
      32,    33,    17,    18,    19,    -1,    -1,   361,    -1,    24,
      25,    26,    27,   472,    -1,   369,    31,   371,     1,    34,
       3,     4,     5,     6,   378,    -1,    -1,    10,    -1,   159,
      -1,    -1,    -1,    -1,    17,    18,    19,     9,    10,    11,
      12,    13,    14,    15,    16,   399,   400,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
     210,   435,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      24,    25,    26,    27,    -1,   554,   555,    31,    -1,   229,
      34,    35,    -1,    -1,    -1,   564,   565,   566,    -1,    -1,
      -1,   570,   571,   572,    -1,    -1,    -1,    -1,   472,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,   263,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,   638,
     639,   640,    24,    25,    26,    27,    -1,    -1,   318,    31,
     320,    -1,    34,    -1,   324,    -1,    -1,    -1,    -1,   329,
     554,   555,     9,    10,    11,    12,    13,    14,    15,    16,
     564,   565,   566,    -1,    -1,    -1,   570,   571,   572,    -1,
     350,    -1,    -1,   353,    31,    32,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,   369,
      -1,   371,    17,    18,    19,    -1,    21,    22,   378,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     9,    10,    11,    12,    13,    14,    15,    16,   399,
     400,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,    29,    10,    31,   638,   639,   640,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,   435,    34,    35,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,   472,    34,    35,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,   554,   555,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   564,   565,   566,    -1,    32,    33,
     570,   571,   572,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    -1,    24,    25,    26,    27,   638,   639,
     640,    31,     0,     1,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,     1,    34,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,     0,     1,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,     0,     1,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,     0,     1,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,
       1,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,     0,     1,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,     0,     1,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,     0,     1,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,
       1,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,     0,     1,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,     0,     1,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,     0,     1,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,
       1,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,     0,     1,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,     1,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    -1,    -1,    -1,    -1,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,
      -1,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,     3,     4,     5,     6,    -1,    -1,    -1,    10,
       1,    -1,     3,     4,     5,     6,    17,    18,    19,    10,
       1,    -1,     3,     4,     5,     6,    17,    18,    19,    10,
      31,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,     1,
      31,     3,     4,     5,     6,    -1,    -1,    -1,    10,     1,
      31,     3,     4,     5,     6,    17,    18,    19,    10,     1,
      -1,     3,     4,     5,     6,    17,    18,    19,    10,    31,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,     1,    31,
       3,     4,     5,     6,    -1,    -1,    -1,    10,     1,    31,
       3,     4,     5,     6,    17,    18,    19,    10,     1,    -1,
       3,     4,     5,     6,    17,    18,    19,    10,    31,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,     1,    31,     3,
       4,     5,     6,    -1,    -1,    -1,    10,     1,    31,     3,
       4,     5,     6,    17,    18,    19,    10,     1,    -1,     3,
       4,     5,     6,    17,    18,    19,    10,    31,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,     1,    31,     3,     4,
       5,     6,    -1,    -1,    -1,    10,     1,    31,     3,     4,
       5,     6,    17,    18,    19,    10,     1,    -1,     3,     4,
       5,     6,    17,    18,    19,    10,    31,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,     1,    31,     3,     4,     5,
       6,    -1,    -1,    -1,    10,     1,    31,     3,     4,     5,
       6,    17,    18,    19,    10,     1,    -1,     3,     4,     5,
       6,    17,    18,    19,    10,    31,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,     1,    31,     3,     4,     5,     6,
      -1,    -1,    -1,    10,     1,    31,     3,     4,     5,     6,
      17,    18,    19,    10,     1,    -1,     3,     4,     5,     6,
      17,    18,    19,    10,    31,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,     1,    31,     3,     4,     5,     6,    -1,
      -1,    -1,    10,     1,    31,     3,     4,     5,     6,    17,
      18,    19,    10,     1,    -1,     3,     4,     5,     6,    17,
      18,    19,    10,    31,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,     1,    31,     3,     4,     5,     6,    -1,    -1,
      -1,    10,     1,    31,     3,     4,     5,     6,    17,    18,
      19,    10,     1,    -1,     3,     4,     5,     6,    17,    18,
      19,    10,    31,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,     1,    31,     3,     4,     5,     6,    -1,    -1,    -1,
      10,     1,    31,     3,     4,     5,     6,    17,    18,    19,
      10,     1,    -1,     3,     4,     5,     6,    17,    18,    19,
      10,    31,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
       1,    31,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    31,    -1,    -1,    -1,    -1,    17,    18,    19,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      31,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      30,    -1,    32,    33,     9,    10,    11,    12,    13,    14,
      15,    16,    30,    -1,    32,    33,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    30,    -1,    32,    33,     9,
      10,    11,    12,    13,    14,    15,    16,    30,    -1,    32,
      33,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      30,    -1,    32,    33,     9,    10,    11,    12,    13,    14,
      15,    16,    30,    -1,    32,    33,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    32,    33,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    32,
      33,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    32,    33,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    32,    33,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    32,    33,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    32,
      33,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    32,    33,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    32,    33,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    32,    33,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    32,
      33,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    32,    33,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    32,    33,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    32,    33,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    32,
      33,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    32,    33,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    32,    33,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    32,    33,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    32,
      33,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    32,    33,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    32,    33,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    32,    33,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    32,
      33,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    32,    33,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    32,    33,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    32,    33,     9,
      10,    11,    12,    13,    14,    15,    16,    30,    31,    32,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      30,    -1,    32,     9,    10,    11,    12,    13,    14,    15,
      16,    30,    -1,    32,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    30,    -1,    32,     9,    10,    11,
      12,    13,    14,    15,    16,    30,    -1,    32,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    30,    -1,
      32,     9,    10,    11,    12,    13,    14,    15,    16,    30,
      -1,    32,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    30,    -1,    32,     9,    10,    11,    12,    13,
      14,    15,    16,    30,    -1,    32,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    31,    32,     9,
      10,    11,    12,    13,    14,    15,    16,    30,    -1,    32,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      30,    -1,    32,     9,    10,    11,    12,    13,    14,    15,
      16,    30,    -1,    32,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    32,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    32,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      32,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    32,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    32,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    32,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    32,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    32,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    32,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    32,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    32,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    32,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      32,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    32,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    32,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    32,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    32,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    32,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    32,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    32,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    32,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    32,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      32,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    32,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    32,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    32,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    32,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    32,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    32,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    32,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    32,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    32,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      32,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    32,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    32,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    32,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    32,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    32,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    32,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    32,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    32,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    32,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    29,    30,    31,
       9,    10,    11,    12,    13,    14,    15,    16,    29,    30,
      31,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      29,    -1,    31,     9,    10,    11,    12,    13,    14,    15,
      16,    29,    30,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    29,    30,     9,    10,    11,    12,    13,
      14,    15,    16,    29,    30,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    29,    30,     9,    10,    11,
      12,    13,    14,    15,    16,    29,    30,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    29,    30,     9,
      10,    11,    12,    13,    14,    15,    16,    29,    30,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    29,
      30,     9,    10,    11,    12,    13,    14,    15,    16,    29,
      30,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    29,    30,     9,    10,    11,    12,    13,    14,    15,
      16,    29,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    29,     9,    10,    11,    12,    13,    14,
      15,    16,    29,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    29,     9,    10,    11,    12,    13,
      14,    15,    16,    29,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    29,     9,    10,    11,    12,
      13,    14,    15,    16,    29,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    29,     9,    10,    11,
      12,    13,    14,    15,    16,    29,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    29,     9,    10,
      11,    12,    13,    14,    15,    16,    29,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    29,     9,
      10,    11,    12,    13,    14,    15,    16,    29,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    29,
       9,    10,    11,    12,    13,    14,    15,    16,    29,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      29,     9,    10,    11,    12,    13,    14,    15,    16,    29,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    29,     9,    10,    11,    12,    13,    14,    15,    16,
      29,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    29,     9,    10,    11,    12,    13,    14,    15,
      16,    29,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    29,     9,    10,    11,    12,    13,    14,
      15,    16,    29,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    29,     9,    10,    11,    12,    13,
      14,    15,    16,    29,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    29,     9,    10,    11,    12,
      13,    14,    15,    16,    29,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    29,     9,    10,    11,
      12,    13,    14,    15,    16,    29,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    29,     9,    10,
      11,    12,    13,    14,    15,    16,    29,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    29,     9,
      10,    11,    12,    13,    14,    15,    16,    29,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    29,
       9,    10,    11,    12,    13,    14,    15,    16,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    10,    17,
      18,    19,    21,    22,    24,    26,    27,    31,    34,    37,
      38,    39,    40,    42,    48,    53,    54,    55,    56,    57,
      58,    59,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    73,    74,    75,    76,     9,    10,    11,    12,
      13,    14,    15,    16,    31,    31,    23,    23,    31,    31,
       1,    59,     1,    59,    49,     0,    39,    29,    13,    12,
      14,    11,    10,    15,    16,     9,    30,    68,    31,    29,
      31,    74,    68,     1,    67,    68,     1,    65,     1,    63,
       1,    62,     1,    64,    65,    65,     1,    74,     1,    20,
      59,    77,     1,    59,     1,    59,    60,    29,    29,    32,
      32,    40,    50,    51,    52,    53,    75,     1,    62,     1,
      63,     1,    64,     1,    65,     1,    67,     1,    65,     1,
      65,     1,    68,     1,    61,     1,    59,    71,    72,     1,
      45,    46,    47,    75,    30,    31,    41,    32,    32,    32,
      32,    32,    32,    32,    29,    29,    35,    52,    74,    33,
      32,    32,    33,    74,     1,    43,    29,    29,    29,    29,
      29,    29,    25,    53,    25,    53,    60,     1,    60,    59,
      48,    47,    45,    53,    25,    25,    29,    29,    29,    44,
      53,    53,    60,    60,     1,    60,    32,    32,    32,    32,
      32,    48,    53,    53,    53,    53,     3,     4,     5,     6,
      31,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    73,    74,    76,     6,     3,     4,     5,     6,    31,
      69,    70,    73,    74,    76,     6,     9,    10,    11,    12,
      13,    14,    15,    16,     7,     8,    21,    22,    24,    26,
      27,    34,    48,    54,    55,    56,    57,    58,    59,     3,
       4,     5,     6,    31,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    73,    74,    76,    21,    22,     6,
      29,     9,    10,    11,    12,    13,    14,    15,    16,     6,
       7,     8,    24,    26,    27,    34,    48,    54,    55,    56,
      57,    58,    59,    30,    41,     1,     1,    59,     1,    59,
      13,    12,    14,    11,    10,    15,    16,     9,    30,    68,
      31,     1,    59,    68,    31,     3,     4,     5,     6,    31,
      68,    69,    70,    73,    74,    76,     1,    67,    68,     1,
      65,     1,    63,     1,    62,     1,    64,    65,    65,    31,
      31,    23,    23,    31,    31,     1,    59,    49,    29,     1,
      59,    13,    12,    14,    11,    10,    15,    16,     9,    30,
      68,    31,    23,    23,     3,     4,     5,     6,    31,    68,
      69,    70,    73,    74,    76,     1,    67,    68,     1,    65,
       1,    63,     1,    62,     1,    64,    65,    65,    31,    31,
      31,    31,     1,    59,    49,    29,     1,    29,    32,    32,
       1,    62,     1,    63,     1,    64,     1,    65,     1,    67,
       1,    65,     1,    65,     1,    68,     1,    61,    72,    32,
      32,    72,     1,    59,    68,    31,     1,    74,     1,    59,
      77,     1,    59,     1,    60,    29,    29,    50,    32,    32,
       1,    62,     1,    63,     1,    64,     1,    65,     1,    67,
       1,    65,     1,    65,     1,    68,     1,    61,    72,     1,
      59,    68,    31,     1,    74,     1,    59,    77,     1,    59,
       1,    60,    29,    29,    50,    32,    32,    32,    32,    72,
      32,    32,    32,    32,    32,    32,    32,    29,    29,    35,
      32,    32,    32,    72,    32,    32,    32,    32,    32,    32,
      32,    29,    29,    35,    32,    29,    29,    29,    29,    29,
       7,     8,    24,    25,    26,    27,    34,    48,    53,    54,
      55,    56,    57,    58,    59,    25,    53,    60,     1,    60,
      32,    29,    29,    29,    29,    29,    25,    53,    25,    53,
      60,     1,    60,    31,    31,    31,    53,    31,     1,    59,
      49,    25,    29,    25,    29,    29,    29,    53,    25,    25,
      29,    29,    29,     1,    74,     1,    59,    77,     1,    59,
       1,    60,    29,    29,    50,    53,    53,    60,    60,     1,
      60,    53,    53,    60,    60,     1,    60,    32,    32,    32,
      32,    32,    32,    32,    29,    29,    35,    32,    32,    32,
      32,    32,    32,    32,    32,    29,    29,    29,    29,    29,
      25,    53,    25,    53,    60,     1,    60,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    25,    25,    29,    29,
      29,    53,    53,    60,    60,     1,    60,    32,    32,    32,
      32,    53,    53,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    39,    41,
      40,    40,    40,    43,    44,    42,    42,    45,    45,    46,
      46,    46,    47,    49,    48,    50,    50,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      54,    54,    55,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    59,    59,    59,    60,    60,
      61,    61,    61,    61,    62,    62,    62,    62,    63,    63,
      63,    63,    64,    64,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    66,    66,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    70,    70,    71,
      71,    71,    72,    72,    73,    73,    73,    73,    74,    75,
      75,    75,    75,    76,    76,    76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     0,
       4,     2,     4,     0,     0,     8,     5,     0,     1,     3,
       1,     1,     2,     0,     4,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       5,     5,     2,     5,     7,     5,     5,     7,     6,     3,
       3,     9,     9,     9,     9,     1,     3,     3,     0,     1,
       1,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     1,     2,     1,     1,     1,     1,     1,     4,     3,
       1,     1,     1,     0,     1,     1,     3,     3,     1,     1,
       1,     2,     2,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (line, col, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, line, col); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, int line, int col)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (line);
  YY_USE (col);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, int line, int col)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, line, col);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, int line, int col)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), line, col);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, line, col); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          goto yyexhaustedlab;                                          \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, int line, int col)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (line);
  YY_USE (col);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_NAME: /* NAME  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3672 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3678 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3684 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3690 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3696 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3702 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3708 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3714 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3720 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3726 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3732 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3738 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3744 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3750 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3756 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3762 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3768 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3774 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3780 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3786 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_1: /* @1  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3792 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3798 "src/bison/grammar.c"
        break;

    case YYSYMBOL_43_2: /* @2  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3804 "src/bison/grammar.c"
        break;

    case YYSYMBOL_45_param_list_opt: /* param_list.opt  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3810 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3816 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3822 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3828 "src/bison/grammar.c"
        break;

    case YYSYMBOL_50_block_item_list_opt: /* block_item_list.opt  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3834 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3840 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3846 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3852 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3858 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3864 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3870 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3876 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3882 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3888 "src/bison/grammar.c"
        break;

    case YYSYMBOL_60_expression_opt: /* expression.opt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3894 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3900 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3906 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3912 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3918 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3924 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3930 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3936 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3942 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3948 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3954 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3960 "src/bison/grammar.c"
        break;

    case YYSYMBOL_72_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3966 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3972 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3978 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3984 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3990 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3996 "src/bison/grammar.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (int line, int col)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 3: /* prog: %empty  */
#line 131 "src/bison/grammar.y"
             { show_error((yyloc), "ISO C-IPL forbids an empty translation unit\n"); }
#line 4305 "src/bison/grammar.c"
    break;

  case 4: /* external_declaration_list: external_declaration_list external_declaration  */
#line 134 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4311 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration  */
#line 135 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4317 "src/bison/grammar.c"
    break;

  case 8: /* external_declaration: statement  */
#line 140 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4327 "src/bison/grammar.c"
    break;

  case 9: /* @1: %empty  */
#line 147 "src/bison/grammar.y"
                              {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-1].pchar));
        if (sym) {
            if (sym->scope) {
                show_error_range((yylsp[0]), "redeclaration of " BCYN "'%s'\n" RESET, (yyvsp[0].sym)->name);
            } else if (sym->is_fn) {
                show_error_range((yylsp[0]), BBLU "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[0].sym)->name);
            } else if (sym->type != decl_type) {
                show_error_range((yylsp[-1]), "conflicting types for " BCYN "'%s'\n" RESET, (yyvsp[0].sym)->name);
            }
            (yyval.ast) = NULL;
        }
        else {
            symbol_update_type((yyvsp[0].sym), decl_type);
            (yyval.ast) = ast_symref_init(context_declare_variable(current_context, (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 4352 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type id @1 ';'  */
#line 166 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 4360 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 169 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4370 "src/bison/grammar.c"
    break;

  case 12: /* var_declaration: type id '=' error  */
#line 174 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4381 "src/bison/grammar.c"
    break;

  case 13: /* @2: %empty  */
#line 182 "src/bison/grammar.y"
                                   {
        p_ctx_name = true;
        Symbol *sym = context_has_symbol(current_context, (yyvsp[-1].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-2].pchar));

        // always push a context for the function even if not valid so is possible to pop later
        previous_context = current_context;
        list_push(&contexts, context_init((yyvsp[-1].sym)->name));
        current_context = list_peek_last(&contexts);

        if (sym) {
            if (!sym->is_fn) {
                show_error((yylsp[-1]), BCYN "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
            } else if (sym->type != decl_type) {
                show_error((yylsp[-2]), "conflicting types for " BBLU "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            } else {
                show_error((yylsp[-1]), "redefinition of " BBLU "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            }
            (yyval.ast) = NULL;
        } else {
            symbol_update_type((yyvsp[-1].sym), decl_type);
            Symbol *declared = context_declare_function(previous_context, (yyvsp[-1].sym));
            if (!declared) {
                show_error((yylsp[-1]), BCYN "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
                (yyval.ast) = NULL;
            } else {
                (yyval.ast) = ast_symref_init(declared);
            }
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 4422 "src/bison/grammar.c"
    break;

  case 14: /* $@3: %empty  */
#line 217 "src/bison/grammar.y"
                     {
        is_fn_blck = true;
    }
#line 4430 "src/bison/grammar.c"
    break;

  case 15: /* func_declaration: type id '(' @2 param_list.opt $@3 ')' compound_stmt  */
#line 219 "src/bison/grammar.y"
                        {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4440 "src/bison/grammar.c"
    break;

  case 16: /* func_declaration: type '(' param_list.opt ')' compound_stmt  */
#line 224 "src/bison/grammar.y"
                                                {
        show_error_range((yylsp[-3]), "expected identifier before " WHT "')'" RESET "\n");
        free((yyvsp[-4].pchar));
        LIST_FREE((yyvsp[-2].list), { ast_free(__IT__->data); });
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4452 "src/bison/grammar.c"
    break;

  case 17: /* param_list.opt: %empty  */
#line 233 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4458 "src/bison/grammar.c"
    break;

  case 19: /* params_list: params_list ',' param_decl  */
#line 237 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4464 "src/bison/grammar.c"
    break;

  case 20: /* params_list: param_decl  */
#line 238 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4470 "src/bison/grammar.c"
    break;

  case 21: /* params_list: error  */
#line 239 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4479 "src/bison/grammar.c"
    break;

  case 22: /* param_decl: type id  */
#line 245 "src/bison/grammar.y"
                    {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        if (sym) {
            show_error_range((yylsp[0]), "redefinition of parameter " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            symbol_update_type((yyvsp[0].sym), symbol_type_from_str((yyvsp[-1].pchar)));
            (yyval.ast) = ast_symref_init(context_declare_variable(current_context, (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 4496 "src/bison/grammar.c"
    break;

  case 23: /* $@4: %empty  */
#line 259 "src/bison/grammar.y"
                   {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        if (!is_fn_blck) context_push_scope(current_context);
        is_fn_blck = false;
    }
#line 4506 "src/bison/grammar.c"
    break;

  case 24: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 263 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 4518 "src/bison/grammar.c"
    break;

  case 25: /* block_item_list.opt: block_item_list  */
#line 272 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4524 "src/bison/grammar.c"
    break;

  case 26: /* block_item_list.opt: %empty  */
#line 273 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4530 "src/bison/grammar.c"
    break;

  case 27: /* block_item_list: block_item_list block_item  */
#line 276 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4536 "src/bison/grammar.c"
    break;

  case 28: /* block_item_list: block_item  */
#line 277 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4542 "src/bison/grammar.c"
    break;

  case 37: /* io_stmt: READ '(' id ')' ';'  */
#line 292 "src/bison/grammar.y"
                             {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(func), ast_symref_init(param));
        symbol_free((yyvsp[-4].sym));
        symbol_free((yyvsp[-2].sym));
    }
#line 4554 "src/bison/grammar.c"
    break;

  case 38: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 299 "src/bison/grammar.y"
                                   {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(func), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 4564 "src/bison/grammar.c"
    break;

  case 39: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 304 "src/bison/grammar.y"
                                       {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(func), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 4574 "src/bison/grammar.c"
    break;

  case 40: /* io_stmt: WRITE '(' error ')' ';'  */
#line 309 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        symbol_free((yyvsp[-4].sym));
        (yyval.ast) = NULL;
    }
#line 4584 "src/bison/grammar.c"
    break;

  case 41: /* io_stmt: READ '(' error ')' ';'  */
#line 314 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        symbol_free((yyvsp[-4].sym));
        (yyval.ast) = NULL;
    }
#line 4594 "src/bison/grammar.c"
    break;

  case 42: /* expr_stmt: expression ';'  */
#line 321 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 4600 "src/bison/grammar.c"
    break;

  case 43: /* cond_stmt: IF '(' expression ')' statement  */
#line 324 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 4608 "src/bison/grammar.c"
    break;

  case 44: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 327 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4616 "src/bison/grammar.c"
    break;

  case 45: /* cond_stmt: IF '(' expression ')' ELSE  */
#line 330 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4626 "src/bison/grammar.c"
    break;

  case 46: /* cond_stmt: IF '(' error ')' statement  */
#line 335 "src/bison/grammar.y"
                                            {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4636 "src/bison/grammar.c"
    break;

  case 47: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 340 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4647 "src/bison/grammar.c"
    break;

  case 48: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 346 "src/bison/grammar.y"
                                      {
        show_error((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4657 "src/bison/grammar.c"
    break;

  case 49: /* jmp_stmt: RETURN expression ';'  */
#line 353 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 4663 "src/bison/grammar.c"
    break;

  case 50: /* jmp_stmt: RETURN error ';'  */
#line 354 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 4672 "src/bison/grammar.c"
    break;

  case 51: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 360 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4680 "src/bison/grammar.c"
    break;

  case 52: /* iter_stmt: FOR '(' error ';' expression.opt ';' expression.opt ')' statement  */
#line 363 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-6]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4692 "src/bison/grammar.c"
    break;

  case 53: /* iter_stmt: FOR '(' expression.opt ';' error ';' expression.opt ')' statement  */
#line 370 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-4]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4704 "src/bison/grammar.c"
    break;

  case 54: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' error ')' statement  */
#line 377 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-2]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4716 "src/bison/grammar.c"
    break;

  case 56: /* expression: unary_expr '=' logical_or_expr  */
#line 387 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 4722 "src/bison/grammar.c"
    break;

  case 57: /* expression: unary_expr '=' error  */
#line 388 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4732 "src/bison/grammar.c"
    break;

  case 58: /* expression.opt: %empty  */
#line 395 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 4738 "src/bison/grammar.c"
    break;

  case 61: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 400 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4747 "src/bison/grammar.c"
    break;

  case 62: /* logical_or_expr: logical_or_expr OR error  */
#line 404 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4757 "src/bison/grammar.c"
    break;

  case 63: /* logical_or_expr: error OR logical_and_expr  */
#line 409 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4767 "src/bison/grammar.c"
    break;

  case 65: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 417 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4776 "src/bison/grammar.c"
    break;

  case 66: /* logical_and_expr: logical_and_expr AND error  */
#line 421 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4786 "src/bison/grammar.c"
    break;

  case 67: /* logical_and_expr: error AND eq_expr  */
#line 426 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4796 "src/bison/grammar.c"
    break;

  case 69: /* eq_expr: eq_expr EQ rel_expr  */
#line 434 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4805 "src/bison/grammar.c"
    break;

  case 70: /* eq_expr: eq_expr EQ error  */
#line 438 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4815 "src/bison/grammar.c"
    break;

  case 71: /* eq_expr: error EQ rel_expr  */
#line 443 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4825 "src/bison/grammar.c"
    break;

  case 73: /* rel_expr: rel_expr REL list_expr  */
#line 451 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4834 "src/bison/grammar.c"
    break;

  case 74: /* rel_expr: rel_expr REL error  */
#line 455 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4844 "src/bison/grammar.c"
    break;

  case 75: /* rel_expr: error REL list_expr  */
#line 460 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4854 "src/bison/grammar.c"
    break;

  case 77: /* list_expr: add_expr DL_DG list_expr  */
#line 468 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4863 "src/bison/grammar.c"
    break;

  case 78: /* list_expr: add_expr COLON list_expr  */
#line 472 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4872 "src/bison/grammar.c"
    break;

  case 79: /* list_expr: add_expr DL_DG error  */
#line 476 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4882 "src/bison/grammar.c"
    break;

  case 80: /* list_expr: add_expr COLON error  */
#line 481 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4892 "src/bison/grammar.c"
    break;

  case 81: /* list_expr: error DL_DG list_expr  */
#line 486 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4902 "src/bison/grammar.c"
    break;

  case 82: /* list_expr: error COLON list_expr  */
#line 491 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4912 "src/bison/grammar.c"
    break;

  case 84: /* add_expr: add_expr ADD mult_expr  */
#line 499 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4921 "src/bison/grammar.c"
    break;

  case 85: /* add_expr: add_expr ADD error  */
#line 503 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4931 "src/bison/grammar.c"
    break;

  case 86: /* add_expr: error ADD mult_expr  */
#line 508 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4941 "src/bison/grammar.c"
    break;

  case 88: /* mult_expr: mult_expr MULT unary_expr  */
#line 516 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4950 "src/bison/grammar.c"
    break;

  case 89: /* mult_expr: mult_expr MULT error  */
#line 520 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4960 "src/bison/grammar.c"
    break;

  case 90: /* mult_expr: error MULT unary_expr  */
#line 525 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4970 "src/bison/grammar.c"
    break;

  case 92: /* unary_expr: unary_ops unary_expr  */
#line 533 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4979 "src/bison/grammar.c"
    break;

  case 98: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 546 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-3].sym));
        AST *params = ast_params_init((yyvsp[-1].list));
        if (!sym) {
            show_error_range((yylsp[-3]), "implicit declaration of function " BBLU "'%s'\n" RESET, (yyvsp[-3].sym)->name);
            (yyval.ast) = NULL;
            ast_free(params);
        } else {
            if (!sym->is_fn) {
                show_error_range((yylsp[-3]), "called object " BCYN "'%s'" RESET " is not a function\n", sym->name);
                (yyval.ast) = NULL;
                ast_free(params);
            } else {
                (yyval.ast) = ast_funcall_init(ast_symref_init(sym), params);
            }
        }
        symbol_free((yyvsp[-3].sym));
    }
#line 5002 "src/bison/grammar.c"
    break;

  case 99: /* arg_expr_list: arg_expr_list ',' expression  */
#line 566 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5008 "src/bison/grammar.c"
    break;

  case 100: /* arg_expr_list: expression  */
#line 567 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5014 "src/bison/grammar.c"
    break;

  case 101: /* arg_expr_list: error  */
#line 568 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5023 "src/bison/grammar.c"
    break;

  case 103: /* arg_expr_list.opt: %empty  */
#line 575 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5029 "src/bison/grammar.c"
    break;

  case 104: /* primary_expr: id  */
#line 578 "src/bison/grammar.y"
                 {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[0].sym));
        if (!sym) {
            show_error_range((yylsp[0]), BCYN "'%s'" RESET " undeclared (first use in this function)\n", (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            (yyval.ast) = ast_symref_init(sym);
        }
        symbol_free((yyvsp[0].sym));
    }
#line 5044 "src/bison/grammar.c"
    break;

  case 106: /* primary_expr: '(' expression ')'  */
#line 589 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 5050 "src/bison/grammar.c"
    break;

  case 107: /* primary_expr: '(' error ')'  */
#line 590 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5059 "src/bison/grammar.c"
    break;

  case 111: /* type: INT LIST  */
#line 601 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5071 "src/bison/grammar.c"
    break;

  case 112: /* type: FLOAT LIST  */
#line 608 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5083 "src/bison/grammar.c"
    break;

  case 113: /* constant: NUMBER_REAL  */
#line 617 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5089 "src/bison/grammar.c"
    break;

  case 114: /* constant: NUMBER_INT  */
#line 618 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5095 "src/bison/grammar.c"
    break;

  case 115: /* constant: NIL  */
#line 619 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5101 "src/bison/grammar.c"
    break;

  case 116: /* string_literal: STR_LITERAL  */
#line 622 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5110 "src/bison/grammar.c"
    break;


#line 5114 "src/bison/grammar.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (line, col, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, line, col);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, line, col);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (line, col, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, line, col);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, line, col);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 628 "src/bison/grammar.y"


void yyerror(int l, int c, const char *s, ...) {
    error_cursor = (Cursor){.line=l, .col=c};
    last_line_ref = curr_line_buffer;
    // enable error print when bison calls yyerror()
    /* if (s) {
        CIPL_PRINTF_COLOR(BRED, "%s\n", s);
        CIPL_PRINTF_COLOR(BYEL, "%d:%d: at line: %s\n", error_cursor.line, error_cursor.col, last_line_ref);
    } */
    // prevent count up errors when bison calls yyerror()
    if (!s) {
        ++errors_count;
    }
}
