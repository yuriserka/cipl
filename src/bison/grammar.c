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
    Scope *params_scope;
    StackNode *parent_stacknode_ref;
    char *last_line_ref;

    void free_scope_cb(StackNode *node) { scope_free(node->data); }

    StackNode *context_get_current_stacknode_ref() {
        LIST_FOR_EACH_REVERSE(current_context->scopes, {
            if (((Scope *)__IT__->data)->index == current_context->current_scope) {
                return __IT__;
            }
        });
        return NULL;
    }

    #define show_error(__LINE__, __COL__, __FMT__, ...) {               \
        yyerror(__LINE__, __COL__, NULL);                               \
        LineInfo *li = list_peek(&lines, __LINE__ - 1);                 \
        li = li ? li : curr_line_info;                                  \
        CIPL_PERROR_CURSOR(                                             \
            __FMT__,                                                    \
            li->text,                                                   \
            error_cursor,                                               \
            ##__VA_ARGS__                                               \
        );                                                              \
    }

#line 117 "src/bison/grammar.c"

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
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* '='  */
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
  YYSYMBOL_id_expr = 74,                   /* id_expr  */
  YYSYMBOL_id = 75,                        /* id  */
  YYSYMBOL_type = 76,                      /* type  */
  YYSYMBOL_constant = 77,                  /* constant  */
  YYSYMBOL_string_literal = 78             /* string_literal  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  335

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
      30,    31,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
       0,    93,    93,    94,   100,   101,   104,   105,   108,   108,
     134,   141,   171,   141,   190,   191,   194,   195,   198,   207,
     207,   226,   227,   230,   231,   234,   235,   238,   239,   240,
     241,   242,   243,   246,   253,   260,   263,   266,   269,   275,
     284,   285,   292,   297,   298,   299,   308,   309,   312,   313,
     317,   326,   327,   331,   340,   341,   345,   354,   355,   359,
     368,   369,   373,   377,   384,   393,   394,   398,   407,   408,
     412,   421,   422,   428,   429,   430,   431,   434,   435,   440,
     441,   444,   445,   448,   449,   450,   451,   454,   467,   470,
     471,   472,   479,   488,   489,   490,   493
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
  "THEN", "';'", "'('", "')'", "','", "'{'", "'}'", "'='", "$accept",
  "prog", "external_declaration_list", "external_declaration",
  "var_declaration", "@1", "func_declaration", "@2", "$@3",
  "param_list.opt", "params_list", "param_decl", "compound_stmt", "$@4",
  "block_item_list.opt", "block_item_list", "block_item", "statement",
  "io_stmt", "expr_stmt", "cond_stmt", "jmp_stmt", "iter_stmt",
  "expression", "expression.opt", "logical_or_expr", "logical_and_expr",
  "eq_expr", "rel_expr", "list_expr", "add_expr", "mult_expr",
  "unary_expr", "unary_ops", "postfix_expr", "arg_expr_list",
  "arg_expr_list.opt", "primary_expr", "id_expr", "id", "type", "constant",
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
      40,    41,    44,   123,   125,    61
};
#endif

#define YYPACT_NINF (-227)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-97)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      75,    36,    64,    16,   118,   171,   236,   248,     0,    14,
      44,  -227,   286,    72,   293,   104,   273,    33,   345,   298,
      58,   222,   268,   119,   125,   321,   337,   145,   340,   694,
     303,   855,  1694,  3196,  3223,   150,   158,  2697,  2715,  2733,
    2751,  3231,   161,   179,     8,  2769,   998,  1159,   185,  1372,
    1620,  1734,  1781,  1814,  1846,  1878,  1910,   195,   -10,    -5,
     390,   667,   971,  1294,  1480,  3258,  2787,  3266,  3293,  1398,
    2916,    62,  3301,  3328,   232,  2769,   146,  2679,   217,   226,
     220,   357,  1942,  1974,   271,   589,   744,   772,   893,  1048,
    1076,  1197,  1552,  3336,   164,   242,   253,   256,   266,   281,
     250,   287,  2006,  2038,  3363,   193,   124,  4258,   160,   743,
     842,  1026,  1059,  1199,  4473,  4279,  1209,  1324,  1331,  1356,
    4287,  4308,   301,   221,   360,   404,   291,   330,   334,   269,
     269,  2679,  2805,  3371,  2070,  2102,    27,   391,   336,   406,
     341,   341,  2661,  2134,  2166,   346,   102,  2198,    88,   154,
     409,  2943,   694,  3398,  3406,  3433,  2951,  3441,  2769,    59,
       9,   297,   440,   451,  4235,  1265,  3468,  2769,  3476,  3503,
    2978,  2986,  3511,  3538,   364,  2230,   358,  4316,  4337,  4345,
    4198,  4366,  2769,  2823,  4374,  4395,  4206,  4228,  4403,  4424,
    1509,  3013,  3021,  2871,  3048,  2769,    85,   513,   455,   418,
     464,   251,  3648,  3056,  2805,  3083,  3091,  2881,  2908,  3118,
    3126,   376,   694,   383,   401,   414,   855,   392,  1601,  1660,
    2328,  2349,  2370,  2391,  2412,  2433,  2454,  3546,   164,   395,
    4432,   164,   402,  2475,  2496,  2517,  2538,  2559,  2580,  2601,
    2622,  2643,  3153,   164,  2262,   855,   388,  3573,   100,  3958,
    3966,  3989,  3904,  3997,  2769,    43,  4020,  2841,  4028,  4051,
    3927,  3935,  4059,  4082,   130,   878,   888,   479,   555,   599,
    4249,  4090,   695,   722,   755,   783,  4113,  4121,   415,   117,
     416,  4453,   425,  3161,   114,  3672,  3680,  3704,  3608,  3712,
    2769,   570,  3736,  2859,  3744,  3768,  3616,  3640,  3776,  3800,
     592,   584,   651,   615,   728,   837,  4135,  3808,   919,  1032,
    1141,  1223,  3832,  3840,   412,   208,   427,   439,  2294,   428,
    4144,   164,  3581,  4461,   449,  3864,   164,  3188,   554,  4167,
     450,  3872,   453,  4175,  3896
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
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
    -227,  -227,  -227,   481,   243,   393,  -227,  -227,  -227,  -227,
    -227,   472,   -26,  -148,  -206,  -227,   474,   343,  -227,  -227,
    -227,  -227,  -227,   110,   -43,   229,  1502,  1483,  1453,  1208,
    1272,  1240,   113,   296,   417,  -227,  -226,   600,   721,    -8,
      67,   904,  1025
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,    46,    17,     7,    18,    27,    20,
      21,    22,    47,    31,    48,    49,    50,    51,    52,    53,
      54,    55,    56,   124,   101,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   125,   126,   169,   170,   171,
      71,   172,   173
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    30,   280,    84,   216,   282,    13,    85,   -48,    78,
     246,    32,    33,    34,   151,    26,    11,   316,    37,   -43,
     -91,   219,   -48,    70,   -48,    38,    39,    40,    41,    14,
     -38,   -38,   -38,   -38,   -38,   -38,    70,   -38,    45,   317,
     -48,    70,   -89,   -91,   -38,   -38,   -38,   -38,   -38,   -38,
     -92,   -38,   140,   -38,   -38,   219,   -49,   -38,    70,     9,
     -38,   -38,    19,    95,   245,   -89,    96,     8,   174,    70,
     -90,     8,   218,   -92,   -49,    -3,   187,   187,   187,   187,
     187,   187,   187,   187,   187,    23,   208,    10,   138,    24,
     -43,   175,    23,   -90,   -89,   330,     1,     2,   233,   145,
     332,   -88,   -88,   136,   137,    32,    33,    34,   151,    35,
      36,   214,    37,   -50,   143,   144,   -43,   -43,    -2,    38,
      39,    40,    41,    70,   208,   150,    42,   -50,    43,    44,
     218,   -50,    45,    -8,    16,   152,    85,   -49,    70,     1,
       2,    57,   -53,   -53,    65,   -50,   -50,    98,   -44,   153,
     154,   155,   156,   -49,    79,    80,    37,    65,   -12,    57,
     -90,   -53,    65,    38,    39,    40,   157,   190,   191,   192,
     193,    -5,   -53,   -53,    37,   187,   158,   215,    29,    93,
      74,    38,    39,    40,   194,    97,    99,   100,    75,   -53,
      65,    76,    -5,    -5,   195,   -82,   208,   107,   107,   107,
     107,   107,   107,   107,   121,   107,   -50,   203,    70,    77,
     261,   261,   261,   261,   261,   261,   261,   261,   261,    81,
     208,   233,   -50,   208,    83,   297,   297,   297,   297,   297,
     297,   297,   297,   297,    84,   208,    -7,    70,   176,   -44,
     -44,   100,   139,     6,    65,   203,   102,     6,    -6,   261,
     -44,   104,   213,   -15,    25,   103,    57,    -7,    -7,    65,
      58,   237,   -60,   -60,   -60,   -60,   238,   239,   217,    -6,
      -6,    -8,   105,    58,   177,   178,   179,   180,    58,   -47,
     227,    37,   -60,   -60,   127,   297,    -4,   128,    38,    39,
      40,   181,   229,   -10,   -11,   -11,   230,   129,    -9,   -17,
     -17,   182,   212,   -13,   -11,   232,    58,    -4,    -4,   -51,
     -51,   220,   130,   208,   -10,   -10,   131,   242,   208,    -9,
      -9,   123,   133,   196,   -13,   -13,    57,    66,   -51,    65,
     -45,   256,   256,   256,   256,   256,   256,   256,   277,   256,
      66,   203,   148,   149,   203,    66,   292,   292,   292,   292,
     292,   292,   292,   313,   292,    57,   203,   -20,    65,   134,
      58,   196,    66,   135,   319,   142,   148,   149,   -18,   -18,
     320,   -16,   -16,    66,   152,    58,   -14,   146,   -20,   -20,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   -88,
     204,   -79,   -79,   -88,   -36,   -36,   -36,   -36,   -36,   -36,
     324,   -36,   -51,   -51,    86,   244,   325,   -91,   -36,   -36,
     -36,   -36,   -36,   -36,   -47,   -36,   141,   -36,   -36,   -51,
     -92,   -36,   318,   247,   -36,   -36,   281,    66,   204,   236,
     -54,   -54,   -54,   283,   203,   -81,   132,   -80,   -80,   203,
     -88,   -88,    66,   -45,   -45,    58,   -45,   322,    67,   -54,
     -54,   221,   -54,   -54,   -54,   279,   323,   196,   327,   329,
     196,    67,   -57,   -57,   -57,   -57,    67,   -51,   -51,   235,
     315,   -54,   196,   328,    58,   -57,   -57,   -57,   -57,   183,
     331,   333,   -57,    67,   334,    12,   -51,   -51,   211,   147,
     221,   -55,   -55,   -55,    67,   -57,   -57,    28,     0,     0,
     204,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     -55,   205,    66,     0,   257,   257,   257,   257,   257,   257,
     257,   257,   257,    82,   204,   234,   -48,   204,     0,   293,
     293,   293,   293,   293,   293,   293,   293,   293,     0,   204,
       0,    66,     0,     0,   -48,   -48,     0,     0,    67,   205,
     196,     0,     0,   257,     0,   196,     0,   -20,   -20,   -20,
     -20,   -20,   -20,    67,   -20,     0,   -59,   -59,   -59,   -59,
       0,   -20,   -20,   -20,   -20,   -20,   -20,     0,   -20,   -20,
     -20,   -20,   234,   -49,   -20,     0,   -59,   -20,   -20,   293,
     108,     0,   177,   178,   179,   180,   -52,   -52,   235,    37,
     184,   -49,   -49,     0,   -53,   -53,    38,    39,    40,   181,
     -58,   -58,   -58,   -58,     0,   -52,   -52,   204,     0,   182,
       0,   205,   204,   -53,   -53,     0,   236,   -55,   -55,   -55,
     -58,    68,     0,    67,     0,   258,   258,   258,   258,   258,
     258,   258,   258,   258,    68,   205,   -55,   -55,   205,    68,
     294,   294,   294,   294,   294,   294,   294,   294,   294,     0,
     205,     0,    67,   -56,   -56,   -56,    68,     0,     0,     0,
       0,     0,     0,     0,   258,     0,     0,    68,    87,   -54,
     -54,   -54,   -56,   -56,   185,   185,   185,   185,   185,   185,
     185,   185,   185,     0,   206,     0,   -54,   -19,   -19,   -19,
     -19,   -19,   -19,     0,   -19,     0,   -64,   -64,   -64,   -64,
     294,   -19,   -19,   -19,   -19,   -19,   -19,     0,   -19,     0,
     -19,   -19,     0,     0,   -19,     0,   -64,   -19,   -19,     0,
       0,    68,   206,   -62,   -62,   -62,   -62,     0,   205,   -59,
     -59,   -59,   -59,   205,     0,   110,    68,   177,   178,   179,
     180,     0,    69,   -62,    37,   -52,   -52,    86,     0,   -59,
     -59,    38,    39,    40,   181,    69,   -63,   -63,   -63,   -63,
      69,     0,   -52,   112,   182,   177,   178,   179,   180,     0,
       0,     0,    37,   185,     0,     0,   -63,    69,     0,    38,
      39,    40,   181,     0,   -61,   -61,   -61,   -61,    69,     0,
       0,     0,   182,     0,   206,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   -61,   207,    68,     0,   259,   259,
     259,   259,   259,   259,   259,   259,   259,     0,   206,     0,
       0,   206,     0,   295,   295,   295,   295,   295,   295,   295,
     295,   295,     0,   206,     0,    68,     0,     0,   -58,   -58,
     -58,   -58,    69,   207,   -56,   -56,   -56,   259,    32,    33,
      34,   151,    35,    36,     0,    37,     0,    69,   -58,   -58,
       0,   -56,    38,    39,    40,    41,     1,     2,     0,    42,
       0,    43,    44,     0,     0,    45,     0,     0,   152,   -22,
     -52,   -52,   220,   295,   114,     0,   177,   178,   179,   180,
     -56,   -56,   -56,    37,   186,     0,     0,     0,     0,   -52,
      38,    39,    40,   181,     0,     0,     0,     0,     0,   -56,
       0,   206,     0,   182,     0,   207,   206,     0,     0,     0,
     -64,   -64,   -64,   -64,     0,    72,     0,    69,     0,   260,
     260,   260,   260,   260,   260,   260,   260,   260,    72,   207,
     -64,   -64,   207,    72,   296,   296,   296,   296,   296,   296,
     296,   296,   296,     0,   207,     0,    69,     0,     0,     0,
      72,     0,     0,     0,     0,     0,     0,     0,   260,     0,
       0,    72,   -57,   -57,   -57,   -57,     0,     0,   188,   188,
     188,   188,   188,   188,   188,   188,   188,     0,   209,     0,
     -57,   -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,     0,
       0,     0,     0,     0,   296,   -25,   -25,   -25,   -25,   -25,
     -25,     0,   -25,     0,   -25,   -25,     0,     0,   -25,     0,
       0,   -25,   -25,     0,     0,    72,   209,    87,   -55,   -55,
     -55,     0,   207,   -62,   -62,   -62,   -62,   207,     0,   116,
      72,   177,   178,   179,   180,   -55,    73,     0,    37,     0,
       0,     0,     0,   -62,   -62,    38,    39,    40,   181,    73,
     -59,   -59,   -59,   -59,    73,     0,     0,   118,   182,   177,
     178,   179,   180,     0,     0,     0,    37,   188,   -59,     0,
       0,    73,     0,    38,    39,    40,   181,     0,     0,     0,
       0,     0,    73,     0,     0,     0,   182,     0,   209,   189,
     189,   189,   189,   189,   189,   189,   189,   189,     0,   210,
      72,     0,   262,   262,   262,   262,   262,   262,   262,   262,
     262,     0,   209,     0,     0,   209,     0,   298,   298,   298,
     298,   298,   298,   298,   298,   298,     0,   209,     0,    72,
       0,     0,   -63,   -63,   -63,   -63,    73,   210,     0,     0,
       0,   262,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,
       0,    73,   -63,   -63,     0,     0,   -28,   -28,   -28,   -28,
     -28,   -28,     0,   -28,     0,   -28,   -28,     0,     0,   -28,
       0,     0,   -28,   -28,     0,     0,     0,   298,   120,     0,
     177,   178,   179,   180,     0,     0,     0,    37,   189,     0,
     -58,   -58,   -58,   -58,    38,    39,    40,   181,     0,     0,
     -64,   -64,   -64,   -64,     0,   209,     0,   182,   -58,   210,
     209,     0,     0,     0,   -61,   -61,   -61,   -61,   -64,    62,
       0,    73,     0,   263,   263,   263,   263,   263,   263,   263,
     263,   263,    62,   210,   -61,   -61,   210,    62,   299,   299,
     299,   299,   299,   299,   299,   299,   299,     0,   210,     0,
      73,    64,     0,     0,   225,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   263,     0,    64,    62,     0,     0,     0,    64,
       0,     0,    62,    62,    62,   113,   -65,   117,   119,     0,
      62,     0,   200,    63,    88,   -60,   -60,   -60,   -60,    89,
      90,     0,     0,     0,     0,     0,    63,    64,   299,     0,
       0,    63,     0,   -60,    64,    64,    64,    64,   115,    64,
      64,     0,    64,     0,   202,   -62,   -62,   -62,   -62,    62,
     200,     0,   -63,   -63,   -63,   -63,   210,     0,     0,    63,
       0,   210,     0,   -62,    62,     0,    63,    63,    63,    63,
     -63,    63,    63,     0,    63,     0,   201,   -61,   -61,   -61,
     -61,    64,   202,     0,     0,    32,    33,    34,   151,    35,
      36,     0,    37,     0,     0,   -61,    64,     0,     0,    38,
      39,    40,    41,     1,     2,     0,    42,     0,    43,    44,
       0,     0,    45,    63,   201,   152,   -21,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,     0,     0,     0,    63,     0,
       0,     0,     0,     0,    62,     0,     0,   -83,    94,   269,
       0,   273,   275,   -83,     0,     0,   200,     0,     0,   200,
       0,   200,   200,   200,   305,     0,   309,   311,     0,   200,
       0,   200,     0,    62,     0,     0,    64,     0,     0,     0,
       0,     0,   271,     0,     0,     0,     0,     0,   202,     0,
       0,   202,     0,   202,   202,   202,   202,   307,   202,   202,
       0,   202,     0,   202,    61,    64,     0,     0,    63,    91,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,    61,     0,     0,
     201,     0,    61,   201,     0,   201,   201,   201,   201,   -65,
     201,   201,     0,   201,    60,   201,     0,    63,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,     0,    60,     0,   200,
      61,     0,    60,    59,   200,     0,     0,    61,    61,   111,
     -94,   -94,     0,     0,   -94,    61,    59,   199,     0,     0,
       0,    59,     0,   122,     0,   177,   178,   179,   180,     0,
      60,   202,    37,     0,     0,     0,   202,    60,   109,    38,
      39,    40,   181,     0,     0,    60,     0,   198,     0,    59,
       0,     0,   182,     0,    61,   199,   106,     0,     0,     0,
       0,     0,     0,   201,    59,     0,   197,     0,   201,    61,
       0,     0,   248,     0,   249,   250,   251,   252,     0,     0,
       0,    37,     0,     0,    60,   198,     0,     0,    38,    39,
      40,   253,     0,   -24,   -24,   -24,   -24,   -24,   -24,    60,
     -24,   254,     0,    59,   197,     0,     0,   -24,   -24,   -24,
     -24,   -24,   -24,     0,   -24,     0,   -24,   -24,    59,     0,
     -24,     0,     0,   -24,   -24,     0,     0,     0,     0,     0,
       0,   264,     0,   249,   250,   251,   252,     0,     0,    61,
      37,     0,     0,   267,     0,     0,     0,    38,    39,    40,
     253,   199,     0,     0,   199,     0,   199,   199,   303,     0,
     254,     0,     0,     0,   199,     0,   199,     0,    61,    60,
       0,     0,   265,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   198,     0,     0,   198,     0,   198,   301,    59,     0,
     255,     0,     0,   -94,   198,     0,   198,     0,    60,   -94,
     197,     0,     0,   197,     0,   291,     0,   -26,   -26,   -26,
     -26,   -26,   -26,   197,   -26,   197,     0,    59,     0,     0,
       0,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,     0,
     -26,   -26,     0,     0,   -26,     0,     0,   -26,   -26,     0,
       0,     0,     0,     0,   199,     0,     0,     0,     0,   199,
       0,     0,     0,     0,   -32,   -32,   -32,   -32,   -32,   -32,
       0,   -32,     0,     0,     0,     0,     0,     0,   -32,   -32,
     -32,   -32,   -32,   -32,   198,   -32,     0,   -32,   -32,   198,
       0,   -32,     0,     0,   -32,   -32,     0,   -27,   -27,   -27,
     -27,   -27,   -27,   197,   -27,     0,     0,     0,   197,     0,
       0,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,     0,
     -27,   -27,     0,     0,   -27,     0,     0,   -27,   -27,   -29,
     -29,   -29,   -29,   -29,   -29,     0,   -29,     0,     0,     0,
       0,     0,     0,   -29,   -29,   -29,   -29,   -29,   -29,     0,
     -29,     0,   -29,   -29,     0,     0,   -29,     0,     0,   -29,
     -29,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,     0,
       0,     0,     0,     0,     0,   -30,   -30,   -30,   -30,   -30,
     -30,     0,   -30,     0,   -30,   -30,     0,     0,   -30,     0,
       0,   -30,   -30,   -31,   -31,   -31,   -31,   -31,   -31,     0,
     -31,     0,     0,     0,     0,     0,     0,   -31,   -31,   -31,
     -31,   -31,   -31,     0,   -31,     0,   -31,   -31,     0,     0,
     -31,     0,     0,   -31,   -31,   -23,   -23,   -23,   -23,   -23,
     -23,     0,   -23,     0,     0,     0,     0,     0,     0,   -23,
     -23,   -23,   -23,   -23,   -23,     0,   -23,     0,   -23,   -23,
       0,     0,   -23,     0,     0,   -23,   -23,   -35,   -35,   -35,
     -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,     0,
       0,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,     0,
     -35,   -35,     0,     0,   -35,     0,     0,   -35,   -35,   -41,
     -41,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,     0,
       0,     0,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,
     -41,     0,   -41,   -41,     0,     0,   -41,     0,     0,   -41,
     -41,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,
       0,     0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,
     -40,     0,   -40,     0,   -40,   -40,     0,     0,   -40,     0,
       0,   -40,   -40,   -33,   -33,   -33,   -33,   -33,   -33,     0,
     -33,     0,     0,     0,     0,     0,     0,   -33,   -33,   -33,
     -33,   -33,   -33,     0,   -33,     0,   -33,   -33,     0,     0,
     -33,     0,     0,   -33,   -33,   -34,   -34,   -34,   -34,   -34,
     -34,     0,   -34,     0,     0,     0,     0,     0,     0,   -34,
     -34,   -34,   -34,   -34,   -34,     0,   -34,     0,   -34,   -34,
       0,     0,   -34,     0,     0,   -34,   -34,   -39,   -39,   -39,
     -39,   -39,   -39,     0,   -39,     0,     0,     0,     0,     0,
       0,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,     0,
     -39,   -39,     0,     0,   -39,     0,     0,   -39,   -39,   -37,
     -37,   -37,   -37,   -37,   -37,     0,   -37,     0,     0,     0,
       0,     0,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,
     -37,     0,   -37,   -37,     0,     0,   -37,     0,     0,   -37,
     -37,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,     0,
       0,     0,     0,     0,     0,   -42,   -42,   -42,   -42,   -42,
     -42,     0,   -42,     0,   -42,   -42,     0,     0,   -42,     0,
       0,   -42,   -42,   -10,   -10,   -10,   -10,   -10,   -10,     0,
     -10,     0,     0,     0,     0,     0,     0,   -10,   -10,   -10,
     -10,   -10,   -10,     0,   -10,     0,   -10,   -10,     0,     0,
     -10,     0,     0,   -10,   -10,    -9,    -9,    -9,    -9,    -9,
      -9,     0,    -9,     0,     0,     0,     0,     0,     0,    -9,
      -9,    -9,    -9,    -9,    -9,     0,    -9,     0,    -9,    -9,
       0,     0,    -9,     0,     0,    -9,    -9,   -20,   -20,   -20,
     -20,   -20,   -20,     0,   -20,     0,     0,     0,     0,     0,
       0,   -20,   -20,   -20,   -20,   -20,   -20,     0,   -20,     0,
     -20,   -20,     0,     0,   -20,     0,     0,   -20,   -20,   266,
       0,   249,   250,   251,   252,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,    38,    39,    40,   253,     0,
     268,     0,   249,   250,   251,   252,     0,     0,   254,    37,
       0,     0,     0,     0,     0,     0,    38,    39,    40,   253,
       0,   270,     0,   249,   250,   251,   252,     0,     0,   254,
      37,     0,     0,     0,     0,     0,     0,    38,    39,    40,
     253,     0,   272,     0,   249,   250,   251,   252,     0,     0,
     254,    37,     0,     0,     0,     0,     0,     0,    38,    39,
      40,   253,     0,   274,     0,   249,   250,   251,   252,     0,
       0,   254,    37,     0,     0,     0,     0,     0,     0,    38,
      39,    40,   253,     0,   276,     0,   249,   250,   251,   252,
       0,     0,   254,    37,     0,     0,     0,     0,     0,     0,
      38,    39,    40,   253,     0,   278,     0,   249,   250,   251,
     252,     0,     0,   254,    37,     0,     0,     0,     0,     0,
       0,    38,    39,    40,   253,     0,   284,     0,   285,   286,
     287,   288,     0,     0,   254,    37,     0,     0,     0,     0,
       0,     0,    38,    39,    40,   289,     0,   300,     0,   285,
     286,   287,   288,     0,     0,   290,    37,     0,     0,     0,
       0,     0,     0,    38,    39,    40,   289,     0,   302,     0,
     285,   286,   287,   288,     0,     0,   290,    37,     0,     0,
       0,     0,     0,     0,    38,    39,    40,   289,     0,   304,
       0,   285,   286,   287,   288,     0,     0,   290,    37,     0,
       0,     0,     0,     0,     0,    38,    39,    40,   289,     0,
     306,     0,   285,   286,   287,   288,     0,     0,   290,    37,
       0,     0,     0,     0,     0,     0,    38,    39,    40,   289,
       0,   308,     0,   285,   286,   287,   288,     0,     0,   290,
      37,     0,     0,     0,     0,     0,     0,    38,    39,    40,
     289,     0,   310,     0,   285,   286,   287,   288,     0,     0,
     290,    37,     0,     0,     0,     0,     0,     0,    38,    39,
      40,   289,     0,   312,     0,   285,   286,   287,   288,     0,
       0,   290,    37,     0,     0,     0,     0,     0,     0,    38,
      39,    40,   289,     0,   314,     0,   285,   286,   287,   288,
       0,     0,   290,    37,     0,     0,     0,     0,     0,     0,
      38,    39,    40,   289,   153,   154,   155,   156,     0,     0,
       0,    37,     0,   290,     0,     0,     0,     0,    38,    39,
      40,   157,    32,    33,    34,   151,     0,     0,     0,    37,
       0,   158,   -46,     0,     0,     0,    38,    39,    40,    41,
     -75,   -75,   -75,   -75,     0,     0,     0,   -75,   -46,    45,
       0,     0,     0,     0,   -75,   -75,   -75,   -75,   -73,   -73,
     -73,   -73,     0,     0,     0,   -73,     0,   -75,     0,     0,
       0,     0,   -73,   -73,   -73,   -73,   -74,   -74,   -74,   -74,
       0,     0,     0,   -74,     0,   -73,     0,     0,     0,     0,
     -74,   -74,   -74,   -74,   -76,   -76,   -76,   -76,     0,     0,
       0,   -76,     0,   -74,     0,     0,     0,     0,   -76,   -76,
     -76,   -76,   153,   154,   155,   156,     0,     0,     0,    37,
       0,   -76,     0,     0,     0,     0,    38,    39,    40,   157,
      32,    33,    34,   151,     0,     0,     0,    37,     0,   158,
       0,     0,     0,     0,    38,    39,    40,    41,   190,   191,
     192,   193,     0,     0,     0,    37,     0,    45,     0,     0,
       0,     0,    38,    39,    40,   194,   177,   178,   179,   180,
       0,     0,     0,    37,     0,   195,     0,     0,     0,     0,
      38,    39,    40,   181,   249,   250,   251,   252,     0,     0,
       0,    37,     0,   182,     0,     0,     0,     0,    38,    39,
      40,   253,   285,   286,   287,   288,     0,     0,     0,    37,
       0,   254,     0,     0,     0,     0,    38,    39,    40,   289,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,     0,   290,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,     0,     0,
       0,   -88,   -88,   -88,     0,     0,   -88,     0,     0,     0,
       0,   243,   -83,   -83,     0,     0,   -83,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,     0,     0,     0,     0,     0,   -87,   -87,
     -87,     0,     0,   -87,     0,   -87,   -87,     0,     0,     0,
       0,   -87,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,     0,     0,
       0,     0,   -88,   -88,     0,     0,     0,     0,   -88,     0,
       0,   -88,   -88,     0,     0,     0,   -88,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,     0,     0,     0,     0,     0,   228,   -83,
       0,     0,     0,   -83,     0,     0,   -87,   -87,     0,     0,
       0,   -87,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,     0,
       0,     0,     0,     0,   -95,   -95,     0,     0,   -95,     0,
       0,     0,   -93,   -93,     0,     0,   -93,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,     0,     0,     0,     0,     0,     0,   -96,
     -96,     0,     0,   -96,     0,     0,     0,   -68,   -68,     0,
       0,   241,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,
       0,     0,     0,     0,   -71,   -71,     0,     0,   -71,     0,
       0,     0,   -77,   -77,     0,     0,   -77,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,     0,     0,     0,     0,     0,     0,   -84,
     -84,     0,     0,   -84,     0,     0,     0,   -85,   -85,     0,
       0,   -85,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,     0,     0,
       0,     0,     0,     0,   -72,   -72,     0,     0,   -72,     0,
       0,     0,   -86,   -86,     0,     0,   -86,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,     0,     0,     0,     0,     0,     0,   -78,
     -78,     0,     0,   -78,     0,   -95,     0,     0,     0,     0,
       0,   -95,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,     0,
       0,     0,   -93,     0,     0,     0,     0,     0,   -93,     0,
     -96,     0,     0,     0,     0,     0,   -96,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,     0,     0,   -68,     0,     0,
       0,     0,     0,    92,     0,   -71,     0,     0,     0,     0,
       0,   -71,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,     0,     0,
       0,     0,   -77,     0,     0,     0,     0,     0,   -77,     0,
     -84,     0,     0,     0,     0,     0,   -84,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,     0,   -85,     0,     0,
       0,     0,     0,   -85,     0,   -72,     0,     0,     0,     0,
       0,   -72,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
       0,     0,   -86,     0,     0,     0,     0,     0,   -86,     0,
     -78,     0,     0,     0,     0,     0,   -78,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,     0,     0,     0,     0,     0,     0,   -94,
       0,     0,     0,   -94,     0,     0,     0,   -95,     0,     0,
       0,   -95,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,     0,
       0,     0,     0,     0,   -93,     0,     0,     0,   -93,     0,
       0,     0,   -96,     0,     0,     0,   -96,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,     0,     0,     0,     0,   -68,
       0,     0,     0,   226,     0,     0,     0,   -71,     0,     0,
       0,   -71,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,     0,     0,
       0,     0,     0,     0,   -77,     0,     0,     0,   -77,     0,
       0,     0,   -84,     0,     0,     0,   -84,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,     0,     0,     0,   -85,
       0,     0,     0,   -85,     0,     0,     0,   -72,     0,     0,
       0,   -72,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
       0,     0,     0,     0,   -86,     0,     0,     0,   -86,     0,
       0,     0,   -78,     0,     0,     0,   -78,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,     0,     0,     0,     0,     0,   -88,   -88,
     -88,     0,     0,     0,     0,     0,   326,   -83,   -83,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   240,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,     0,     0,     0,     0,     0,
     -87,   -87,   -87,     0,     0,     0,     0,     0,     0,   -65,
     -65,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,     0,     0,     0,
       0,     0,     0,   -94,   -94,     0,     0,     0,     0,     0,
       0,   -95,   -95,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,
       0,     0,     0,     0,     0,   -93,   -93,     0,     0,     0,
       0,     0,     0,   -96,   -96,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,     0,     0,     0,     0,     0,     0,   -68,   -68,     0,
       0,     0,     0,     0,     0,   -71,   -71,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,     0,     0,     0,     0,     0,     0,   -77,
     -77,     0,     0,     0,     0,     0,     0,   -84,   -84,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   240,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,     0,     0,     0,     0,     0,
       0,   -85,   -85,     0,     0,     0,     0,     0,     0,   -66,
     -66,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,
       0,     0,     0,   -70,   -70,     0,     0,     0,     0,     0,
       0,   -69,   -69,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,     0,
       0,     0,     0,     0,     0,   -72,   -72,     0,     0,     0,
       0,     0,     0,   -86,   -86,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,     0,     0,     0,     0,     0,     0,   -78,   -78,     0,
       0,     0,     0,     0,   -88,   -88,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,     0,     0,     0,     0,     0,   321,   -83,     0,
       0,     0,     0,     0,     0,   -87,   -87,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,     0,     0,     0,     0,     0,     0,   -94,
       0,     0,     0,     0,     0,     0,     0,   -95,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,     0,     0,     0,     0,     0,     0,
     -93,     0,     0,     0,     0,     0,     0,     0,   -96,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,     0,     0,     0,     0,     0,
       0,   -68,     0,     0,     0,     0,     0,     0,     0,   -71,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,     0,     0,     0,     0,
       0,     0,   -77,     0,     0,     0,     0,     0,     0,     0,
     -84,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   225,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,
       0,     0,     0,   -85,     0,     0,     0,     0,     0,     0,
       0,   -66,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,
       0,     0,     0,     0,   -70,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -69,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,     0,     0,     0,   -67,   -67,     0,     0,
       0,     0,     0,     0,     0,   -72,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,     0,     0,     0,     0,     0,     0,   -86,     0,
       0,     0,     0,     0,     0,     0,   -78,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,     0,     0,     0,     0,   -88,   -88,     0,
       0,     0,     0,     0,     0,   -83,   231,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   222,   -60,   -60,   -60,   -60,
     223,   224,     0,     0,     0,     0,     0,   -87,   -87,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -60,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,     0,     0,     0,     0,     0,
     -67,     0,     0,     0,     0,     0,     0,   -68,    91,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,     0,     0,     0,     0,   -66,     0,
       0,     0,     0,     0,     0,     0,   -70,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,     0,     0,     0,     0,   -69,     0,     0,
       0,     0,     0,     0,     0,   -94,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,     0,     0,     0,     0,   -95,     0,     0,     0,
       0,     0,     0,     0,   -93,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,     0,     0,     0,     0,   -96,     0,     0,     0,     0,
       0,     0,     0,   -71,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
       0,     0,     0,     0,   -77,     0,     0,     0,     0,     0,
       0,     0,   -84,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,
       0,     0,     0,   -85,     0,     0,     0,     0,     0,     0,
       0,   -72,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
       0,     0,   -86,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -67
};

static const yytype_int16 yycheck[] =
{
       8,    27,   228,    13,   152,   231,     6,    12,    13,     1,
     216,     3,     4,     5,     6,    23,     0,   243,    10,    29,
       6,    12,    13,    31,    29,    17,    18,    19,    20,    29,
       3,     4,     5,     6,     7,     8,    44,    10,    30,   245,
      31,    49,     6,    29,    17,    18,    19,    20,    21,    22,
       6,    24,    25,    26,    27,    12,    13,    30,    66,    23,
      33,    34,    29,    71,   212,    29,    74,     0,     6,    77,
       6,     4,    13,    29,    31,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    18,    94,    23,   131,    31,
      31,    29,    25,    29,     6,   321,    21,    22,    13,   142,
     326,    29,    30,   129,   130,     3,     4,     5,     6,     7,
       8,    23,    10,    13,   140,   141,    31,    32,     0,    17,
      18,    19,    20,   131,   132,     6,    24,    13,    26,    27,
      13,    31,    30,    29,    30,    33,    12,    13,   146,    21,
      22,    31,    12,    13,    31,    31,    32,     1,    31,     3,
       4,     5,     6,    29,    44,    45,    10,    44,    33,    49,
       6,    31,    49,    17,    18,    19,    20,     3,     4,     5,
       6,     0,    12,    13,    10,   183,    30,    23,    33,    66,
      30,    17,    18,    19,    20,    75,    76,    77,    30,    29,
      77,    30,    21,    22,    30,    31,   204,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    13,    94,   216,    30,
     218,   219,   220,   221,   222,   223,   224,   225,   226,    34,
     228,    13,    29,   231,    29,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    13,   243,     0,   245,     6,    31,
      32,   131,   132,     0,   131,   132,    29,     4,     0,   257,
      29,    31,   142,    31,    32,    29,   146,    21,    22,   146,
      31,    10,    11,    12,    13,    14,    15,    16,   158,    21,
      22,    29,     1,    44,     3,     4,     5,     6,    49,    29,
     167,    10,    31,    32,    31,   293,     0,    31,    17,    18,
      19,    20,   182,     0,    21,    22,   183,    31,     0,    31,
      32,    30,    33,     0,    31,   195,    77,    21,    22,    12,
      13,    14,    31,   321,    21,    22,    29,   204,   326,    21,
      22,    92,    31,    94,    21,    22,   216,    31,    31,   216,
      29,   218,   219,   220,   221,   222,   223,   224,   225,   226,
      44,   228,    21,    22,   231,    49,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   245,   243,     0,   245,    29,
     131,   132,    66,    29,   254,    29,    21,    22,    31,    32,
     257,    31,    32,    77,    33,   146,    31,    31,    21,    22,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    31,
      94,    31,    32,    29,     3,     4,     5,     6,     7,     8,
     290,    10,    12,    13,    14,    29,   293,     6,    17,    18,
      19,    20,    21,    22,    31,    24,    25,    26,    27,    29,
       6,    30,    34,    31,    33,    34,    31,   131,   132,    11,
      12,    13,    14,    31,   321,    31,    32,    31,    32,   326,
      31,    32,   146,    31,    32,   216,    31,    31,    31,    31,
      32,    11,    12,    13,    14,   226,    31,   228,    31,    31,
     231,    44,    11,    12,    13,    14,    49,    12,    13,    14,
     241,    31,   243,    34,   245,    11,    12,    13,    14,   183,
      31,    31,    31,    66,    31,     4,    31,    32,    95,   146,
      11,    12,    13,    14,    77,    31,    32,    25,    -1,    -1,
     204,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      31,    94,   216,    -1,   218,   219,   220,   221,   222,   223,
     224,   225,   226,    49,   228,    12,    13,   231,    -1,   233,
     234,   235,   236,   237,   238,   239,   240,   241,    -1,   243,
      -1,   245,    -1,    -1,    31,    32,    -1,    -1,   131,   132,
     321,    -1,    -1,   257,    -1,   326,    -1,     3,     4,     5,
       6,     7,     8,   146,    10,    -1,    11,    12,    13,    14,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    12,    13,    30,    -1,    31,    33,    34,   293,
       1,    -1,     3,     4,     5,     6,    12,    13,    14,    10,
     183,    31,    32,    -1,    12,    13,    17,    18,    19,    20,
      11,    12,    13,    14,    -1,    31,    32,   321,    -1,    30,
      -1,   204,   326,    31,    32,    -1,    11,    12,    13,    14,
      31,    31,    -1,   216,    -1,   218,   219,   220,   221,   222,
     223,   224,   225,   226,    44,   228,    31,    32,   231,    49,
     233,   234,   235,   236,   237,   238,   239,   240,   241,    -1,
     243,    -1,   245,    12,    13,    14,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    77,    11,    12,
      13,    14,    31,    32,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    -1,    29,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    11,    12,    13,    14,
     293,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    31,    33,    34,    -1,
      -1,   131,   132,    11,    12,    13,    14,    -1,   321,    11,
      12,    13,    14,   326,    -1,     1,   146,     3,     4,     5,
       6,    -1,    31,    31,    10,    12,    13,    14,    -1,    31,
      32,    17,    18,    19,    20,    44,    11,    12,    13,    14,
      49,    -1,    29,     1,    30,     3,     4,     5,     6,    -1,
      -1,    -1,    10,   183,    -1,    -1,    31,    66,    -1,    17,
      18,    19,    20,    -1,    11,    12,    13,    14,    77,    -1,
      -1,    -1,    30,    -1,   204,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    31,    94,   216,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,   226,    -1,   228,    -1,
      -1,   231,    -1,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,   243,    -1,   245,    -1,    -1,    11,    12,
      13,    14,   131,   132,    12,    13,    14,   257,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,   146,    31,    32,
      -1,    29,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
      12,    13,    14,   293,     1,    -1,     3,     4,     5,     6,
      12,    13,    14,    10,   183,    -1,    -1,    -1,    -1,    31,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    31,
      -1,   321,    -1,    30,    -1,   204,   326,    -1,    -1,    -1,
      11,    12,    13,    14,    -1,    31,    -1,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,    44,   228,
      31,    32,   231,    49,   233,   234,   235,   236,   237,   238,
     239,   240,   241,    -1,   243,    -1,   245,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    77,    11,    12,    13,    14,    -1,    -1,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    -1,
      29,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,   293,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    -1,   131,   132,    11,    12,    13,
      14,    -1,   321,    11,    12,    13,    14,   326,    -1,     1,
     146,     3,     4,     5,     6,    29,    31,    -1,    10,    -1,
      -1,    -1,    -1,    31,    32,    17,    18,    19,    20,    44,
      11,    12,    13,    14,    49,    -1,    -1,     1,    30,     3,
       4,     5,     6,    -1,    -1,    -1,    10,   183,    29,    -1,
      -1,    66,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    30,    -1,   204,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
     216,    -1,   218,   219,   220,   221,   222,   223,   224,   225,
     226,    -1,   228,    -1,    -1,   231,    -1,   233,   234,   235,
     236,   237,   238,   239,   240,   241,    -1,   243,    -1,   245,
      -1,    -1,    11,    12,    13,    14,   131,   132,    -1,    -1,
      -1,   257,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,   146,    31,    32,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    -1,    -1,   293,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    10,   183,    -1,
      11,    12,    13,    14,    17,    18,    19,    20,    -1,    -1,
      11,    12,    13,    14,    -1,   321,    -1,    30,    29,   204,
     326,    -1,    -1,    -1,    11,    12,    13,    14,    29,    31,
      -1,   216,    -1,   218,   219,   220,   221,   222,   223,   224,
     225,   226,    44,   228,    31,    32,   231,    49,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,   243,    -1,
     245,    31,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,   257,    -1,    44,    77,    -1,    -1,    -1,    49,
      -1,    -1,    84,    85,    86,    87,    31,    89,    90,    -1,
      92,    -1,    94,    31,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    44,    77,   293,    -1,
      -1,    49,    -1,    29,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    -1,    94,    11,    12,    13,    14,   131,
     132,    -1,    11,    12,    13,    14,   321,    -1,    -1,    77,
      -1,   326,    -1,    29,   146,    -1,    84,    85,    86,    87,
      29,    89,    90,    -1,    92,    -1,    94,    11,    12,    13,
      14,   131,   132,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    29,   146,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,   131,   132,    33,    34,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,   146,    -1,
      -1,    -1,    -1,    -1,   216,    -1,    -1,    29,    30,   221,
      -1,   223,   224,    35,    -1,    -1,   228,    -1,    -1,   231,
      -1,   233,   234,   235,   236,    -1,   238,   239,    -1,   241,
      -1,   243,    -1,   245,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,   228,    -1,
      -1,   231,    -1,   233,   234,   235,   236,   237,   238,   239,
      -1,   241,    -1,   243,    31,   245,    -1,    -1,   216,     9,
      10,    11,    12,    13,    14,    15,    16,    44,    -1,    -1,
     228,    -1,    49,   231,    -1,   233,   234,   235,   236,    29,
     238,   239,    -1,   241,    31,   243,    -1,   245,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    44,    -1,   321,
      77,    -1,    49,    31,   326,    -1,    -1,    84,    85,    86,
      31,    32,    -1,    -1,    35,    92,    44,    94,    -1,    -1,
      -1,    49,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      77,   321,    10,    -1,    -1,    -1,   326,    84,    85,    17,
      18,    19,    20,    -1,    -1,    92,    -1,    94,    -1,    77,
      -1,    -1,    30,    -1,   131,   132,    84,    -1,    -1,    -1,
      -1,    -1,    -1,   321,    92,    -1,    94,    -1,   326,   146,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    -1,   131,   132,    -1,    -1,    17,    18,
      19,    20,    -1,     3,     4,     5,     6,     7,     8,   146,
      10,    30,    -1,   131,   132,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,   146,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,   216,
      10,    -1,    -1,   220,    -1,    -1,    -1,    17,    18,    19,
      20,   228,    -1,    -1,   231,    -1,   233,   234,   235,    -1,
      30,    -1,    -1,    -1,   241,    -1,   243,    -1,   245,   216,
      -1,    -1,   219,     9,    10,    11,    12,    13,    14,    15,
      16,   228,    -1,    -1,   231,    -1,   233,   234,   216,    -1,
     218,    -1,    -1,    29,   241,    -1,   243,    -1,   245,    35,
     228,    -1,    -1,   231,    -1,   233,    -1,     3,     4,     5,
       6,     7,     8,   241,    10,   243,    -1,   245,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,    -1,   326,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,   321,    24,    -1,    26,    27,   326,
      -1,    30,    -1,    -1,    33,    34,    -1,     3,     4,     5,
       6,     7,     8,   321,    10,    -1,    -1,    -1,   326,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    30,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,    30,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      30,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    30,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    30,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    -1,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    30,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,     1,    -1,     3,     4,
       5,     6,    -1,    -1,    30,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    30,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    30,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    30,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    30,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,    30,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      30,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    30,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    30,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    30,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    30,    31,    -1,    -1,    -1,    17,    18,    19,    20,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    29,    30,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    30,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    30,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    30,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    30,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    30,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    30,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    30,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    30,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    30,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    30,    31,    32,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    35,    -1,    29,    30,    -1,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    30,    31,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    35,    -1,    -1,    30,    31,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    30,    31,     9,    10,    11,    12,
      13,    14,    15,    16,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
       9,    10,    11,    12,    13,    14,    15,    16,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    10,    11,    12,    13,    14,
      15,    16,    31,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,     9,    10,    11,    12,
      13,    14,    15,    16,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,     9,    10,    11,
      12,    13,    14,    15,    16,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    29,    30,    10,
      11,    12,    13,    14,    15,    16,    31,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    29,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,     9,    10,    11,    12,
      13,    14,    15,    16,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    29,    10,    11,    12,    13,    14,    15,    16,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    22,    37,    38,    39,    40,    42,    76,    23,
      23,     0,    39,     6,    29,    75,    30,    41,    43,    29,
      45,    46,    47,    76,    31,    32,    75,    44,    47,    33,
      48,    49,     3,     4,     5,     7,     8,    10,    17,    18,
      19,    20,    24,    26,    27,    30,    40,    48,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    73,    74,
      75,    76,    77,    78,    30,    30,    30,    30,     1,    59,
      59,    34,    52,    29,    13,    12,    14,    11,    10,    15,
      16,     9,    35,    68,    30,    75,    75,    59,     1,    59,
      59,    60,    29,    29,    31,     1,    62,    68,     1,    63,
       1,    64,     1,    65,     1,    67,     1,    65,     1,    65,
       1,    68,     1,    61,    59,    71,    72,    31,    31,    31,
      31,    29,    32,    31,    29,    29,    48,    48,    60,    59,
      25,    25,    29,    48,    48,    60,    31,    53,    21,    22,
       6,     6,    33,     3,     4,     5,     6,    20,    30,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    73,
      74,    75,    77,    78,     6,    29,     6,     3,     4,     5,
       6,    20,    30,    69,    70,    73,    74,    75,    77,    78,
       3,     4,     5,     6,    20,    30,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    73,    74,    75,    77,
      78,    41,    33,    59,    23,    23,    49,    59,    13,    12,
      14,    11,    10,    15,    16,     9,    35,    68,    30,    59,
      68,    30,    59,    13,    12,    14,    11,    10,    15,    16,
       9,    35,    68,    30,    29,    49,    50,    31,     1,     3,
       4,     5,     6,    20,    30,    62,    68,    69,    70,    73,
      74,    75,    77,    78,     1,    63,     1,    64,     1,    65,
       1,    67,     1,    65,     1,    65,     1,    68,     1,    61,
      72,    31,    72,    31,     1,     3,     4,     5,     6,    20,
      30,    62,    68,    69,    70,    73,    74,    75,    77,    78,
       1,    63,     1,    64,     1,    65,     1,    67,     1,    65,
       1,    65,     1,    68,     1,    61,    72,    50,    34,    59,
      68,    30,    31,    31,    59,    68,    30,    31,    34,    31,
      72,    31,    72,    31,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    41,    40,
      40,    43,    44,    42,    45,    45,    46,    46,    47,    49,
      48,    50,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    56,    56,    56,    56,
      57,    57,    58,    59,    59,    59,    60,    60,    61,    61,
      61,    62,    62,    62,    63,    63,    63,    64,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    66,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    74,    75,    76,
      76,    76,    76,    77,    77,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     0,     4,
       2,     0,     0,     8,     0,     1,     3,     1,     2,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     2,     5,     7,     5,     7,
       3,     3,     9,     1,     3,     3,     0,     1,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     2,     1,     1,     1,     1,     1,     4,     1,
       3,     1,     0,     1,     1,     1,     3,     1,     1,     1,
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
#line 89 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2487 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 89 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2493 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 89 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2499 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2505 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2511 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2517 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2523 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2529 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2535 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2541 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2547 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2553 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2559 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2565 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2571 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2577 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2583 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2589 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2595 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2601 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_1: /* @1  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2607 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2613 "src/bison/grammar.c"
        break;

    case YYSYMBOL_43_2: /* @2  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2619 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2625 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2631 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2637 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2643 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2649 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2655 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2661 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2667 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2673 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2679 "src/bison/grammar.c"
        break;

    case YYSYMBOL_60_expression_opt: /* expression.opt  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2685 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2691 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2697 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2703 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2709 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2715 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2721 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2727 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2733 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2739 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2745 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2751 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id_expr: /* id_expr  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2757 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 89 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2763 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 88 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2769 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2775 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 90 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2781 "src/bison/grammar.c"
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
#line 94 "src/bison/grammar.y"
             {
        yyerror(1, 1, NULL);
        CIPL_PERROR("ISO C-IPL forbids an empty translation unit\n");
    }
#line 3093 "src/bison/grammar.c"
    break;

  case 4: /* external_declaration_list: external_declaration_list external_declaration  */
#line 100 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 3099 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration  */
#line 101 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 3105 "src/bison/grammar.c"
    break;

  case 8: /* @1: %empty  */
#line 108 "src/bison/grammar.y"
                              {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-1].pchar));
        if (sym) {
            if (sym->scope) {
                yyerror((yylsp[0]).last_line, (yylsp[0]).last_column, NULL);
                CIPL_PERROR_CURSOR("redeclaration of '%s'\n", last_line_ref, error_cursor, (yyvsp[0].sym)->name);
            } else if (sym->is_fn) {
                yyerror((yyloc).last_line, (yyloc).last_column, NULL);
                CIPL_PERROR_CURSOR("'%s' redeclared as different kind of symbol\n", last_line_ref, error_cursor, (yyvsp[0].sym)->name);
            } else if (sym->type != decl_type) {
                yyerror((yylsp[-1]).last_line, (yylsp[-1]).last_column, NULL);
                CIPL_PERROR_CURSOR("conflicting types for '%s'\n", last_line_ref, error_cursor, (yyvsp[0].sym)->name);
            } 
            (yyval.ast) = NULL;
        }
        else {
            Symbol *declared = context_declare_variable(current_context, (yyvsp[0].sym));
            symbol_update_type(declared, decl_type);
            (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 3134 "src/bison/grammar.c"
    break;

  case 9: /* var_declaration: type id @1 ';'  */
#line 131 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 3142 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type ';'  */
#line 134 "src/bison/grammar.y"
               {
        show_error((yylsp[-1]).last_line, (yylsp[-1]).last_column, "useless '%s' in empty declaration\n", (yyvsp[-1].pchar));
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
    }
#line 3152 "src/bison/grammar.c"
    break;

  case 11: /* @2: %empty  */
#line 141 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[-1].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-2].pchar));

        // always push a context for the function even if not valid so is possible to pop later
        previous_context = current_context;
        list_push(&contexts, context_init((yyvsp[-1].sym)->name));
        current_context = list_peek_last(&contexts);

        if (sym) {
            yyerror((yyloc).last_line, (yyloc).last_column, NULL);
            if (!sym->is_fn) {
                show_error((yyloc).last_line, (yyloc).last_column, "'%s' redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
            } else if (sym->type != decl_type) {
                show_error((yylsp[-2]).last_line, (yylsp[-2]).last_column, "conflicting types for '%s'\n", (yyvsp[-1].sym)->name);
            } else {
                show_error((yylsp[-1]).last_line, (yylsp[-1]).last_column, "redefinition of '%s'\n", (yyvsp[-1].sym)->name);
            }
            (yyval.ast) = NULL;
        } else {
            Symbol *declared = context_declare_function(previous_context, (yyvsp[-1].sym));
            symbol_update_type(declared, decl_type);
            (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 3188 "src/bison/grammar.c"
    break;

  case 12: /* $@3: %empty  */
#line 171 "src/bison/grammar.y"
                         {
        LIST_FOR_EACH((yyvsp[-1].list), {
            SymbolRefAST *symref = ((AST *)__IT__->data)->value.symref;
            Symbol *sym = context_has_symbol(current_context, symref->symbol);
            if (sym) {
                show_error((yylsp[-1]).first_line, (yylsp[0]).last_column, "redefinition of parameter '%s'\n", symref->symbol->name);
            } else {
                context_declare_variable(current_context, symref->symbol);
            }
        });
        // hack to save the scope of params and append to the scope of the body
        params_scope = scope_init_copy(stack_peek(&current_context->scopes));
        stack_pop(&current_context->scopes, free_scope_cb);
    }
#line 3207 "src/bison/grammar.c"
    break;

  case 13: /* func_declaration: type id '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 184 "src/bison/grammar.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 3216 "src/bison/grammar.c"
    break;

  case 14: /* param_list.opt: %empty  */
#line 190 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 3222 "src/bison/grammar.c"
    break;

  case 16: /* params_list: params_list ',' param_decl  */
#line 194 "src/bison/grammar.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3228 "src/bison/grammar.c"
    break;

  case 17: /* params_list: param_decl  */
#line 195 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3234 "src/bison/grammar.c"
    break;

  case 18: /* param_decl: type id  */
#line 198 "src/bison/grammar.y"
                    {
        symbol_update_context((yyvsp[0].sym), current_context);
        symbol_update_type((yyvsp[0].sym), symbol_type_from_str((yyvsp[-1].pchar)));
        (yyval.ast) = ast_symref_init(symbol_init_copy((yyvsp[0].sym)));
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 3246 "src/bison/grammar.c"
    break;

  case 19: /* $@4: %empty  */
#line 207 "src/bison/grammar.y"
                   {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        // hack to update the current scope
        if (params_scope) {
            stack_push(&current_context->scopes, params_scope);
            current_context->current_scope = ((Scope *)stack_peek(&current_context->scopes))->index;
            params_scope = NULL;
        } else {
            context_push_scope(current_context);
        }
    }
#line 3262 "src/bison/grammar.c"
    break;

  case 20: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 217 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 3274 "src/bison/grammar.c"
    break;

  case 21: /* block_item_list.opt: block_item_list  */
#line 226 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 3280 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list.opt: %empty  */
#line 227 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3286 "src/bison/grammar.c"
    break;

  case 23: /* block_item_list: block_item_list block_item  */
#line 230 "src/bison/grammar.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3292 "src/bison/grammar.c"
    break;

  case 24: /* block_item_list: block_item  */
#line 231 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3298 "src/bison/grammar.c"
    break;

  case 33: /* io_stmt: READ '(' id ')' ';'  */
#line 246 "src/bison/grammar.y"
                             {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(func)), ast_symref_init(symbol_init_copy(param)));
        symbol_free((yyvsp[-4].sym));
        symbol_free((yyvsp[-2].sym));
    }
#line 3310 "src/bison/grammar.c"
    break;

  case 34: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 253 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(sym)), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 3320 "src/bison/grammar.c"
    break;

  case 35: /* expr_stmt: expression ';'  */
#line 260 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 3326 "src/bison/grammar.c"
    break;

  case 36: /* cond_stmt: IF '(' expression ')' compound_stmt  */
#line 263 "src/bison/grammar.y"
                                                          {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 3334 "src/bison/grammar.c"
    break;

  case 37: /* cond_stmt: IF '(' expression ')' compound_stmt ELSE compound_stmt  */
#line 266 "src/bison/grammar.y"
                                                             {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3342 "src/bison/grammar.c"
    break;

  case 38: /* cond_stmt: IF '(' error ')' compound_stmt  */
#line 269 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-2]).last_line, (yylsp[-2]).last_column, "expected expression before ‘)’ token\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[0].ast));
        yyerrok;
    }
#line 3353 "src/bison/grammar.c"
    break;

  case 39: /* cond_stmt: IF '(' error ')' compound_stmt ELSE compound_stmt  */
#line 275 "src/bison/grammar.y"
                                                        {
        show_error((yylsp[-4]).last_line, (yylsp[-4]).last_column, "expected expression before ‘)’ token\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        yyerrok;
    }
#line 3365 "src/bison/grammar.c"
    break;

  case 40: /* jmp_stmt: RETURN expression ';'  */
#line 284 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 3371 "src/bison/grammar.c"
    break;

  case 41: /* jmp_stmt: RETURN error ';'  */
#line 285 "src/bison/grammar.y"
                       {
        show_error((yyloc).last_line, (yyloc).last_column, "'return' with no value\n");
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 3381 "src/bison/grammar.c"
    break;

  case 42: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 292 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3389 "src/bison/grammar.c"
    break;

  case 44: /* expression: unary_expr '=' logical_or_expr  */
#line 298 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3395 "src/bison/grammar.c"
    break;

  case 45: /* expression: unary_expr '=' error  */
#line 299 "src/bison/grammar.y"
                           {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ‘;’ token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3407 "src/bison/grammar.c"
    break;

  case 46: /* expression.opt: %empty  */
#line 308 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 3413 "src/bison/grammar.c"
    break;

  case 49: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 313 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3422 "src/bison/grammar.c"
    break;

  case 50: /* logical_or_expr: logical_or_expr OR error  */
#line 317 "src/bison/grammar.y"
                               {
        show_error((yylsp[0]).last_line, (yylsp[0]).last_column, "expected expression before ';' token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3434 "src/bison/grammar.c"
    break;

  case 52: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 327 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3443 "src/bison/grammar.c"
    break;

  case 53: /* logical_and_expr: logical_and_expr AND error  */
#line 331 "src/bison/grammar.y"
                                 {
        show_error((yylsp[0]).last_line, (yylsp[0]).last_column, "expected expression before ';' token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3455 "src/bison/grammar.c"
    break;

  case 55: /* eq_expr: eq_expr EQ rel_expr  */
#line 341 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3464 "src/bison/grammar.c"
    break;

  case 56: /* eq_expr: eq_expr EQ error  */
#line 345 "src/bison/grammar.y"
                       {
        show_error((yylsp[0]).last_line, (yylsp[0]).last_column, "expected expression before ';' token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3476 "src/bison/grammar.c"
    break;

  case 58: /* rel_expr: rel_expr REL list_expr  */
#line 355 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3485 "src/bison/grammar.c"
    break;

  case 59: /* rel_expr: rel_expr REL error  */
#line 359 "src/bison/grammar.y"
                         {
        show_error((yylsp[0]).last_line, (yylsp[0]).last_column, "expected expression before ';' token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3497 "src/bison/grammar.c"
    break;

  case 61: /* list_expr: add_expr DL_DG list_expr  */
#line 369 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3506 "src/bison/grammar.c"
    break;

  case 62: /* list_expr: add_expr COLON list_expr  */
#line 373 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3515 "src/bison/grammar.c"
    break;

  case 63: /* list_expr: add_expr DL_DG error  */
#line 377 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]).last_line, (yylsp[0]).last_column, "expected expression before ';' token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3527 "src/bison/grammar.c"
    break;

  case 64: /* list_expr: add_expr COLON error  */
#line 384 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]).last_line, (yylsp[0]).last_column, "expected expression before ';' token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3539 "src/bison/grammar.c"
    break;

  case 66: /* add_expr: add_expr ADD mult_expr  */
#line 394 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3548 "src/bison/grammar.c"
    break;

  case 67: /* add_expr: add_expr ADD error  */
#line 398 "src/bison/grammar.y"
                         {
        show_error((yylsp[0]).last_line, (yylsp[0]).last_column, "expected expression before ';' token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3560 "src/bison/grammar.c"
    break;

  case 69: /* mult_expr: mult_expr MULT unary_expr  */
#line 408 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3569 "src/bison/grammar.c"
    break;

  case 70: /* mult_expr: mult_expr MULT error  */
#line 412 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]).last_line, (yylsp[0]).last_column, "expected expression before ';' token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3581 "src/bison/grammar.c"
    break;

  case 72: /* unary_expr: unary_ops unary_expr  */
#line 422 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3590 "src/bison/grammar.c"
    break;

  case 78: /* postfix_expr: id_expr '(' arg_expr_list.opt ')'  */
#line 435 "src/bison/grammar.y"
                                        {
        (yyval.ast) = ast_funcall_init((yyvsp[-3].ast), ast_params_init((yyvsp[-1].list)));
    }
#line 3598 "src/bison/grammar.c"
    break;

  case 79: /* arg_expr_list: expression  */
#line 440 "src/bison/grammar.y"
                          { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3604 "src/bison/grammar.c"
    break;

  case 80: /* arg_expr_list: arg_expr_list ',' expression  */
#line 441 "src/bison/grammar.y"
                                   { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3610 "src/bison/grammar.c"
    break;

  case 82: /* arg_expr_list.opt: %empty  */
#line 445 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3616 "src/bison/grammar.c"
    break;

  case 86: /* primary_expr: '(' expression ')'  */
#line 451 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 3622 "src/bison/grammar.c"
    break;

  case 87: /* id_expr: id  */
#line 454 "src/bison/grammar.y"
            {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[0].sym));
        if (!sym) {
            show_error((yyloc).last_line, (yyloc).last_column, "'%s' undeclared (first use in this function)\n", (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        }   else {
            symbol_update_context((yyvsp[0].sym), current_context);
            (yyval.ast) = ast_symref_init(symbol_init_copy(sym ? sym : (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
    }
#line 3638 "src/bison/grammar.c"
    break;

  case 91: /* type: INT LIST  */
#line 472 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3650 "src/bison/grammar.c"
    break;

  case 92: /* type: FLOAT LIST  */
#line 479 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3662 "src/bison/grammar.c"
    break;

  case 93: /* constant: NUMBER_REAL  */
#line 488 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 3668 "src/bison/grammar.c"
    break;

  case 94: /* constant: NUMBER_INT  */
#line 489 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3674 "src/bison/grammar.c"
    break;

  case 95: /* constant: NIL  */
#line 490 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3680 "src/bison/grammar.c"
    break;

  case 96: /* string_literal: STR_LITERAL  */
#line 493 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 3689 "src/bison/grammar.c"
    break;


#line 3693 "src/bison/grammar.c"

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

#line 499 "src/bison/grammar.y"


void yyerror(int l, int c, const char *s, ...) {
    error_cursor = (Cursor){.line=l, .col=c};
    last_line_ref = curr_line_buffer;
    // enable error print when bison calls yyerror()
    /* if (s) CIPL_PERROR_CURSOR("%s\n", last_line_ref, error_cursor, s); */
    // prevent count up errors when bison calls yyerror()
    if (!s) {
        ++errors_count;
    }
}
