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
#line 4 "src/bison/math.y"

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
    cursor_position error_cursor;
    Context *current_context;
    Context *previous_context;
    Scope *params_scope;
    int parent_scope = 0;

    void free_scope_cb(StackNode *node) { scope_free(node->data); }

#line 95 "src/bison/grammar.c"

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
  YYSYMBOL_NUMBER_REAL = 4,                /* NUMBER_REAL  */
  YYSYMBOL_NAME = 5,                       /* NAME  */
  YYSYMBOL_MULT = 6,                       /* MULT  */
  YYSYMBOL_ADD = 7,                        /* ADD  */
  YYSYMBOL_REL = 8,                        /* REL  */
  YYSYMBOL_AND = 9,                        /* AND  */
  YYSYMBOL_OR = 10,                        /* OR  */
  YYSYMBOL_EQ = 11,                        /* EQ  */
  YYSYMBOL_COLON = 12,                     /* COLON  */
  YYSYMBOL_DL_DG = 13,                     /* DL_DG  */
  YYSYMBOL_EXCLAMATION = 14,               /* EXCLAMATION  */
  YYSYMBOL_PERCENT = 15,                   /* PERCENT  */
  YYSYMBOL_QUESTION = 16,                  /* QUESTION  */
  YYSYMBOL_STR_LITERAL = 17,               /* STR_LITERAL  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_FLOAT = 19,                     /* FLOAT  */
  YYSYMBOL_LIST = 20,                      /* LIST  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_LET = 25,                       /* LET  */
  YYSYMBOL_NIL = 26,                       /* NIL  */
  YYSYMBOL_THEN = 27,                      /* THEN  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* ','  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '}'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_prog = 36,                      /* prog  */
  YYSYMBOL_external_declaration = 37,      /* external_declaration  */
  YYSYMBOL_declaration = 38,               /* declaration  */
  YYSYMBOL_39_1 = 39,                      /* @1  */
  YYSYMBOL_func_declaration = 40,          /* func_declaration  */
  YYSYMBOL_41_2 = 41,                      /* @2  */
  YYSYMBOL_42_3 = 42,                      /* $@3  */
  YYSYMBOL_43_param_list_opt = 43,         /* param_list.opt  */
  YYSYMBOL_params_list = 44,               /* params_list  */
  YYSYMBOL_param_decl = 45,                /* param_decl  */
  YYSYMBOL_compound_stmt = 46,             /* compound_stmt  */
  YYSYMBOL_47_4 = 47,                      /* $@4  */
  YYSYMBOL_48_block_item_list_opt = 48,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 49,           /* block_item_list  */
  YYSYMBOL_block_item = 50,                /* block_item  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_declarator = 52,                /* declarator  */
  YYSYMBOL_expr_stmt = 53,                 /* expr_stmt  */
  YYSYMBOL_cond_stmt = 54,                 /* cond_stmt  */
  YYSYMBOL_jmp_stmt = 55,                  /* jmp_stmt  */
  YYSYMBOL_iter_stmt = 56,                 /* iter_stmt  */
  YYSYMBOL_expression = 57,                /* expression  */
  YYSYMBOL_58_expression_opt = 58,         /* expression.opt  */
  YYSYMBOL_assign_expr = 59,               /* assign_expr  */
  YYSYMBOL_logical_or_expr = 60,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 61,          /* logical_and_expr  */
  YYSYMBOL_eq_expr = 62,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 63,                  /* rel_expr  */
  YYSYMBOL_dl_dg_expr = 64,                /* dl_dg_expr  */
  YYSYMBOL_add_expr = 65,                  /* add_expr  */
  YYSYMBOL_mult_expr = 66,                 /* mult_expr  */
  YYSYMBOL_unary_expr = 67,                /* unary_expr  */
  YYSYMBOL_unary_ops = 68,                 /* unary_ops  */
  YYSYMBOL_postfix_expr = 69,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 70,             /* arg_expr_list  */
  YYSYMBOL_71_arg_expr_list_opt = 71,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 72,              /* primary_expr  */
  YYSYMBOL_id = 73,                        /* id  */
  YYSYMBOL_type = 74,                      /* type  */
  YYSYMBOL_constant = 75                   /* constant  */
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

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      29,    30,     2,     2,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,    34,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    63,    66,    67,    70,    70,    89,    97,
     126,    97,   143,   144,   147,   148,   151,   154,   154,   171,
     172,   175,   176,   179,   180,   183,   184,   185,   186,   187,
     190,   191,   194,   197,   200,   205,   208,   213,   216,   217,
     220,   221,   224,   225,   231,   232,   238,   239,   245,   246,
     252,   253,   257,   263,   264,   270,   271,   277,   278,   284,
     285,   286,   287,   290,   291,   296,   297,   300,   301,   304,
     317,   318,   321,   324,   325,   326,   333,   342,   343
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER_INT",
  "NUMBER_REAL", "NAME", "MULT", "ADD", "REL", "AND", "OR", "EQ", "COLON",
  "DL_DG", "EXCLAMATION", "PERCENT", "QUESTION", "STR_LITERAL", "INT",
  "FLOAT", "LIST", "IF", "ELSE", "FOR", "RETURN", "LET", "NIL", "THEN",
  "';'", "'('", "')'", "','", "'{'", "'}'", "'='", "$accept", "prog",
  "external_declaration", "declaration", "@1", "func_declaration", "@2",
  "$@3", "param_list.opt", "params_list", "param_decl", "compound_stmt",
  "$@4", "block_item_list.opt", "block_item_list", "block_item",
  "statement", "declarator", "expr_stmt", "cond_stmt", "jmp_stmt",
  "iter_stmt", "expression", "expression.opt", "assign_expr",
  "logical_or_expr", "logical_and_expr", "eq_expr", "rel_expr",
  "dl_dg_expr", "add_expr", "mult_expr", "unary_expr", "unary_ops",
  "postfix_expr", "arg_expr_list", "arg_expr_list.opt", "primary_expr",
  "id", "type", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    59,    40,
      41,    44,   123,   125,    61
};
#endif

#define YYPACT_NINF (-194)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-79)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     280,   103,   236,    51,     6,    11,    26,    35,    18,   125,
     153,    -9,  -194,    79,    66,   169,   110,   147,    87,    -3,
       4,    27,   150,   120,   102,    52,   227,   253,   270,    33,
     211,    75,   296,   458,   202,   619,   327,  2269,   256,   708,
     869,  1030,    93,    95,  1403,  1408,   780,   941,   135,  1652,
    1777,  1809,  1832,  1855,  1878,  1901,   100,   155,   101,   373,
     489,   812,   973,  3088,  3032,   384,  1403,  2298,  2306,  2335,
     213,  2343,  1408,    85,   156,   187,   226,  1924,  1947,  1581,
    1581,  1581,  1581,  1581,  1581,  1581,  1581,  1403,   545,    54,
     158,   189,   218,   238,  1970,  2372,   460,  3043,   650,  1154,
    1242,  3055,  1492,  1500,  3066,   247,   323,   368,   200,  1475,
      85,  1617,  2380,   148,   258,   385,  1528,   130,  1993,   224,
    1528,  2016,   234,   169,   266,   412,   169,   454,  2409,   306,
     458,  2417,  2446,  2454,  1408,   282,   131,   492,   239,   300,
     710,   658,  1095,   748,  1408,  2483,  2491,  2520,  2528,   288,
     169,   301,  2923,  2936,  2947,  1408,  1581,  2960,  2971,  2984,
    2995,  2113,  2121,  2150,  1408,    36,   436,  1067,   485,   646,
     497,  2708,   426,  1617,  2158,  2187,  2195,  2224,   313,   322,
     328,  1403,   458,   299,   355,   516,   677,   838,   347,   335,
     356,   359,   357,   619,   370,  1705,  1705,  1705,  1705,  1705,
    1705,  1705,  1705,  1408,   909,    54,   372,   398,  3078,    54,
     400,  2593,  2593,  2593,  2593,  2593,  2593,  2593,  2593,  1617,
     587,    54,  2039,  1408,    85,   431,   619,   999,   410,   513,
    2062,   442,  2557,  1295,  2773,  2786,  1408,   653,  2873,  1705,
    2798,  2811,  2823,  2836,   821,   871,  1032,  2886,  1108,  1227,
    2898,   434,   448,   461,  3008,   482,  2232,   337,  2604,  2617,
    1408,   597,  2721,  2593,  2630,  2643,  2656,  2669,  1442,   807,
     818,  2734,   968,   979,  2747,   529,   484,   488,   498,  1128,
     496,  2085,   506,  2911,    54,  2565,  3019,   517,  2760,    54,
    2261,  1475,    85,  1165,  2848,   520,  2682,   531,  1260,   518,
    2861,  2695,  1475,   130,  1362,   532,  1475,  1742
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,  -194,   559,    13,   486,  -194,  -194,  -194,  -194,  -194,
     547,   -29,  -126,  -188,  -194,   540,   -77,    -7,   -69,   -68,
     -67,   -59,   -24,  -107,  1037,  1519,  1494,  1404,  1358,  1011,
    1245,  1132,   208,   369,   530,  -194,  -193,   691,    -8,    14,
     852
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,    46,    21,     7,    23,    31,    25,    26,
      27,    47,    35,    48,    49,    50,    51,    28,    52,    53,
      54,    55,    56,    93,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   107,   108,    68,    69,    70,
      71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    16,    34,   114,   193,   231,    12,   124,    19,    -9,
     119,    -3,   252,     6,     8,   127,   255,     6,     8,    18,
      74,    75,   127,    14,     1,     2,    -5,    22,   276,    -3,
      -3,     3,   113,    -9,    -9,    -4,    -3,   147,   280,   118,
     184,   185,   186,   121,    -5,    -5,   211,    15,    91,    92,
     187,    -5,    11,    -4,    -4,    24,   226,   161,   162,   163,
      -4,    38,   151,    90,   147,   -10,   -40,   -40,    39,    40,
      41,   159,   159,   159,   159,   159,   159,   159,   159,    -2,
     183,   176,    29,   164,   -68,   188,    92,    -8,    36,    37,
     128,   295,    38,   189,   -72,   -72,   297,    -2,    -2,    39,
      40,    41,    -7,   176,    -2,    -8,    -8,    33,   -73,   147,
     194,    79,    -8,   -38,    45,   124,   190,   278,   124,   191,
      -7,    -7,    72,     9,    73,   125,   147,    -7,    78,   -40,
     -75,   207,   -73,   131,   132,   133,   147,    38,    -6,    20,
     210,   195,   124,   206,    39,    40,    41,   147,   159,   126,
     -12,   -33,   -33,   -33,   -75,   -33,   147,   225,   -76,   134,
     -38,   -40,   -33,   -33,   -33,   176,   -33,   -33,    76,   -33,
     116,   -33,   -33,   -33,   122,   -30,   -30,   -33,   -31,   -31,
     -33,   -33,   -76,   -37,    94,   299,    -6,   242,   242,   242,
     242,   242,   242,   242,   242,   147,   305,   176,   123,   277,
      92,   176,   -11,   266,   266,   266,   266,   266,   266,   266,
     266,   176,   282,   176,   298,   147,   125,    95,   149,   109,
     -11,   -11,   184,   185,   186,   304,   -18,   -11,   147,   307,
     112,   242,   187,   184,   185,   186,   287,   184,   185,   186,
     126,   -74,   150,   187,   -18,   -18,   -39,   187,   -44,   -44,
     197,   -18,   147,   143,   120,   266,    10,   -13,    30,   -61,
     -61,   -61,   183,   -61,   -72,   -74,   110,   188,    92,   -44,
     -61,   -61,   -61,   183,    88,   -41,   176,   183,   188,   189,
     143,   176,   188,   -15,   -15,   -61,   117,    97,    97,    97,
      97,    97,    97,    97,   104,   147,   -30,   172,     1,     2,
     -16,   -16,   -26,   -26,   -26,     3,   -26,   192,   198,   -46,
     -46,   -46,   -37,   -26,   -26,   -26,   -72,   -26,   -26,   172,
     -26,   -26,   -26,   -26,   -26,   143,   -14,   -14,   -26,   -30,
     -46,   -26,   -26,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   222,   143,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   223,   204,   -65,   -65,   -78,   -78,   224,   -25,   -25,
     -25,   -78,   -25,   143,   208,   -39,   -78,   -78,   -78,   -25,
     -25,   -25,   143,   -25,   -25,   227,   -25,   -25,   -25,   -25,
     -25,   220,    80,   -42,   -25,   230,   228,   -25,   -25,   229,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -67,   111,
     232,   -42,   253,   238,   238,   238,   238,   238,   238,   238,
     250,   143,   -55,   172,   144,   -66,   -66,   172,    87,   262,
     262,   262,   262,   262,   262,   262,   274,   172,   254,   172,
     256,   143,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -31,   144,   -72,   -72,   143,   212,   -42,   283,   156,   156,
     156,   156,   156,   156,   156,   156,   -55,   -55,   173,   279,
     219,   -17,   -17,   -17,   -41,   -17,   -42,   -42,   143,    80,
     -43,   288,   -17,   -17,   -17,   281,   -17,   -17,   285,   -17,
     173,   -17,   -17,   -17,   -30,   -30,   144,   -17,   -43,   -31,
     -17,   -17,   172,   214,   -46,   -46,   -46,   172,   -44,   -44,
      81,   196,   -42,   144,   215,   -50,   -50,   -50,   -50,   216,
     217,   143,   286,   144,   290,   -46,   -46,   -44,   291,   -27,
     -27,   -27,   -42,   -27,   144,   156,   292,   -50,   -50,   293,
     -27,   -27,   -27,   144,   -27,   -27,   294,   -27,   -27,   -27,
     -27,   -27,   173,   -31,   -31,   -27,   303,   296,   -27,   -27,
     300,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -41,
     -41,   301,   306,    13,   239,   239,   239,   239,   239,   239,
     239,   239,   144,   -58,   173,   145,   178,    32,   173,   -58,
     263,   263,   263,   263,   263,   263,   263,   263,   173,    77,
     173,     0,   144,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,     0,   145,     0,     0,   144,   212,   -43,   239,   157,
     157,   157,   157,   157,   157,   157,   157,   -58,   -58,   174,
       0,   -58,    36,    37,   128,     0,    38,   -43,   -43,   144,
       0,     0,   263,    39,    40,    41,     0,     1,     2,     0,
      42,   174,    43,    44,   129,     0,     0,   145,    45,     0,
       0,   130,   -20,   173,   -48,   -48,   -48,   -48,   173,   -45,
     -45,    81,   196,   -43,   145,   199,   -50,   -50,   -50,   -50,
     200,   201,   144,     0,   145,     0,   -48,   -48,   -45,     0,
     -28,   -28,   -28,   -43,   -28,   145,   157,     0,   -50,     0,
       0,   -28,   -28,   -28,   145,   -28,   -28,     0,   -28,   -28,
     -28,   -28,   -28,   174,     0,     0,   -28,     0,     0,   -28,
     -28,   -59,   -59,   -59,     0,   -59,     0,     0,   -48,   -48,
     -48,   -48,   -59,   -59,   -59,   240,   240,   240,   240,   240,
     240,   240,   240,   145,     0,   174,   146,   -59,     0,   174,
     -48,   264,   264,   264,   264,   264,   264,   264,   264,   174,
       0,   174,     0,   145,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,     0,   146,     0,     0,   145,     0,     0,   240,
     158,   158,   158,   158,   158,   158,   158,   158,   -55,     0,
     175,     0,   203,   -23,   -23,   -23,     0,   -23,     0,     0,
     145,     0,     0,   264,   -23,   -23,   -23,     0,   -23,   -23,
       0,   -23,   175,   -23,   -23,   -23,     0,     0,   146,   -23,
       0,     0,   -23,   -23,   174,   214,   -47,   -47,   -47,   174,
      82,   -46,   -46,   -46,     0,   146,   -49,   -49,   -49,   -49,
     -45,   -45,   197,   145,     0,   146,     0,   -47,   -47,     0,
     -46,   -29,   -29,   -29,     0,   -29,   146,   158,   -49,   -49,
       0,   -45,   -29,   -29,   -29,   146,   -29,   -29,     0,   -29,
     -29,   -29,   -29,   -29,   175,     0,     0,   -29,     0,     0,
     -29,   -29,   -60,   -60,   -60,     0,   -60,     0,     0,   198,
     -47,   -47,   -47,   -60,   -60,   -60,   241,   241,   241,   241,
     241,   241,   241,   241,   146,     0,   175,   148,   -60,     0,
     175,   -47,   265,   265,   265,   265,   265,   265,   265,   265,
     175,     0,   175,     0,   146,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,     0,   148,     0,     0,   146,     0,     0,
     241,   160,   160,   160,   160,   160,   160,   160,   160,   -58,
       0,   177,     0,   -58,   -26,   -26,   -26,     0,   -26,     0,
       0,   146,     0,     0,   265,   -26,   -26,   -26,     0,   -26,
     -26,     0,   -26,   177,   -26,   -26,   -26,     0,     0,   148,
     -26,     0,     0,   -26,   -26,   175,   -52,   -52,   -52,   -52,
     175,   -48,   -48,   -48,   -48,     0,   148,   -51,   -51,   -51,
     -51,     0,     0,     0,   146,     0,   148,     0,   -52,   -52,
       0,   -48,   -32,   -32,   -32,     0,   -32,   148,   160,   -51,
     -51,     0,     0,   -32,   -32,   -32,   148,   -32,   -32,     0,
     -32,   -32,   -32,   -32,   -32,   177,     0,     0,   -32,     0,
       0,   -32,   -32,   -62,   -62,   -62,     0,   -62,     0,     0,
     -49,   -49,   -49,   -49,   -62,   -62,   -62,   243,   243,   243,
     243,   243,   243,   243,   243,   148,   140,   177,     0,   -62,
       0,   177,   -49,   267,   267,   267,   267,   267,   267,   267,
     267,   177,     0,   177,     0,   148,   -44,   -44,   213,     0,
       0,     0,   135,   140,     0,     0,     0,     0,   148,     0,
       0,   243,     0,   100,     0,   102,   103,   -44,   -44,     0,
     169,   202,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   135,
       0,     0,   148,     0,     0,   267,   -52,   -52,   -52,   -52,
       0,     0,   169,     0,   105,   -53,   106,     0,   140,     0,
       0,   -35,   -35,   -35,     0,   -35,   177,     0,   -52,     0,
       0,   177,   -35,   -35,   -35,   140,   -35,   -35,   115,   -35,
     -35,   -35,   -35,   -35,   135,   148,     0,   -35,     0,     0,
     -35,   -35,    82,   -47,   -47,   -47,   140,     0,   -18,   -18,
     -18,   135,   -18,     0,     0,   140,     0,   142,     0,   -18,
     -18,   -18,   -47,   -18,   -18,     0,   -18,   -18,   -18,   -18,
     -18,     0,   135,     0,   -18,     0,     0,   -18,   -18,     0,
       0,   135,     0,     0,   142,     0,   140,   140,   140,   246,
       0,   248,   249,     0,   140,   101,   169,     0,     0,     0,
     169,   171,   169,   169,   169,   270,     0,   272,   273,     0,
     169,     0,   169,     0,   140,   -51,   -51,   -51,   -51,     0,
     251,     0,   106,   171,     0,     0,   106,   140,     0,   142,
     -49,   -49,   -49,   -49,     0,     0,   275,   -51,   106,     0,
     135,     0,     0,   -33,   -33,   -33,   142,   -33,     0,     0,
     -49,   140,     0,   135,   -33,   -33,   -33,     0,   -33,   -33,
       0,   -33,   302,   -33,   -33,   -33,     0,   142,     0,   -33,
     141,     0,   -33,   -33,     0,   169,   142,   135,     0,     0,
     169,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,
       0,     0,     0,     0,   140,     0,     0,   141,     0,     0,
       0,   106,     0,     0,   -78,   -78,   106,   142,   142,   142,
     142,   247,   142,   142,   170,   142,     0,   171,     0,     0,
     135,   171,     0,   171,   171,   171,   171,   271,   171,   171,
       0,   171,     0,   171,     0,   142,   170,     0,     0,     0,
       0,     0,   141,     0,     0,   -34,   -34,   -34,   142,   -34,
       0,     0,     0,     0,     0,     0,   -34,   -34,   -34,   141,
     -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,     0,     0,
       0,   -34,   142,     0,   -34,   -34,     0,     0,     0,     0,
     141,     0,     0,   139,     0,     0,    36,    37,   128,   141,
      38,   131,   132,   133,     0,    38,   171,    39,    40,    41,
       0,   171,    39,    40,    41,     0,     0,     0,     0,     0,
     139,     0,    45,     0,     0,   142,     0,   134,     0,    99,
     141,   141,   141,   141,     0,   141,   141,   168,   141,   138,
     170,   -45,   -45,   213,   170,     0,   170,   170,   170,   170,
       0,   170,   170,     0,   170,     0,   170,     0,   141,   168,
       0,     0,   -45,   -45,     0,   139,   138,     0,    36,    37,
     128,   141,    38,     0,    98,     0,     0,     0,     0,    39,
      40,    41,   139,   167,     0,     0,   179,     0,   180,   181,
     -52,   -52,   -52,   -52,    45,   141,     0,   182,   -51,   -51,
     -51,   -51,     0,   139,     0,   167,     0,     0,     0,     0,
     -52,   138,   139,     0,     0,     0,     0,     0,   -51,   170,
       0,    36,    37,   128,   170,    38,     0,     0,   138,   137,
       0,     0,    39,    40,    41,     0,     0,     0,   141,    42,
       0,    43,    44,   139,   139,   245,     0,    45,     0,   138,
     130,   139,     0,   168,   136,     0,   137,   168,   138,   168,
     168,   269,     0,    96,     0,     0,     0,   168,     0,   168,
       0,   139,     0,   166,   152,   153,   154,     0,    38,     0,
       0,   136,     0,     0,   139,    39,    40,    41,     0,   138,
     244,     0,     0,     0,     0,   166,     0,   138,   165,   167,
     155,   137,     0,   167,     0,   167,   268,     0,   139,     0,
     161,   162,   163,   167,    38,   167,     0,   138,   137,     0,
     165,    39,    40,    41,     0,     0,   136,     0,     0,     0,
     138,     0,   168,     0,     0,     0,   164,   168,     0,   137,
       0,     0,     0,   136,     0,    36,    37,   128,   137,    38,
       0,   139,     0,     0,   138,     0,    39,    40,    41,     0,
       1,     2,     0,    42,   136,    43,    44,   129,     0,     0,
       0,    45,     0,   136,   130,   -19,     0,     0,   167,   237,
       0,     0,     0,   167,     0,     0,     0,   137,     0,   166,
       0,     0,     0,   166,     0,   261,     0,   138,   233,   234,
     235,     0,    38,   166,     0,   166,     0,   137,     0,    39,
      40,    41,   136,     0,   165,     0,     0,     0,   165,     0,
     137,     0,     0,     0,   236,     0,     0,     0,   165,     0,
     165,     0,   136,     0,     0,   -36,   -36,   -36,     0,   -36,
       0,     0,     0,     0,   137,   136,   -36,   -36,   -36,     0,
     -36,   -36,     0,   -36,   -36,   -36,   -36,   -36,     0,     0,
       0,   -36,     0,     0,   -36,   -36,     0,     0,   166,   136,
     -22,   -22,   -22,   166,   -22,     0,     0,     0,     0,     0,
       0,   -22,   -22,   -22,     0,   -22,   -22,   137,   -22,     0,
     -22,   -22,   -22,   165,     0,     0,   -22,     0,   165,   -22,
     -22,     0,   -24,   -24,   -24,     0,   -24,     0,     0,     0,
       0,     0,   136,   -24,   -24,   -24,     0,   -24,   -24,     0,
     -24,     0,   -24,   -24,   -24,   -25,   -25,   -25,   -24,   -25,
       0,   -24,   -24,     0,     0,     0,   -25,   -25,   -25,     0,
     -25,   -25,     0,   -25,     0,   -25,   -25,   -25,   -27,   -27,
     -27,   -25,   -27,     0,   -25,   -25,     0,     0,     0,   -27,
     -27,   -27,     0,   -27,   -27,     0,   -27,     0,   -27,   -27,
     -27,   -28,   -28,   -28,   -27,   -28,     0,   -27,   -27,     0,
       0,     0,   -28,   -28,   -28,     0,   -28,   -28,     0,   -28,
       0,   -28,   -28,   -28,   -29,   -29,   -29,   -28,   -29,     0,
     -28,   -28,     0,     0,     0,   -29,   -29,   -29,     0,   -29,
     -29,     0,   -29,     0,   -29,   -29,   -29,   -21,   -21,   -21,
     -29,   -21,     0,   -29,   -29,     0,     0,     0,   -21,   -21,
     -21,     0,   -21,   -21,     0,   -21,     0,   -21,   -21,   -21,
     -32,   -32,   -32,   -21,   -32,     0,   -21,   -21,     0,     0,
       0,   -32,   -32,   -32,     0,   -32,   -32,     0,   -32,     0,
     -32,   -32,   -32,   -35,   -35,   -35,   -32,   -35,     0,   -32,
     -32,     0,     0,     0,   -35,   -35,   -35,     0,   -35,   -35,
       0,   -35,     0,   -35,   -35,   -35,   -34,   -34,   -34,   -35,
     -34,     0,   -35,   -35,     0,     0,     0,   -34,   -34,   -34,
       0,   -34,   -34,     0,   -34,     0,   -34,   -34,   -34,   -36,
     -36,   -36,   -34,   -36,     0,   -34,   -34,     0,     0,     0,
     -36,   -36,   -36,     0,   -36,   -36,     0,   -36,     0,   -36,
     -36,   -36,    -7,    -7,    -7,   -36,    -7,     0,   -36,   -36,
       0,     0,     0,    -7,    -7,    -7,     0,    -7,    -7,     0,
      -7,     0,    -7,    -7,    -7,    -8,    -8,    -8,    -7,    -8,
       0,    -7,    -7,     0,     0,     0,    -8,    -8,    -8,     0,
      -8,    -8,     0,    -8,     0,    -8,    -8,    -8,   -18,   -18,
     -18,    -8,   -18,     0,    -8,    -8,     0,     0,     0,   -18,
     -18,   -18,     0,   -18,   -18,     0,   -18,     0,   -18,   -18,
     -18,     0,     0,     0,   -18,     0,     0,   -18,   -18,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,     0,     0,     0,     0,     0,
       0,     0,   -78,   -78,   -78,     0,     0,   -78,     0,     0,
     -77,   -77,   -77,     0,     0,   -77,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,     0,     0,     0,     0,   -72,
     -72,   -72,     0,     0,   -72,     0,     0,   221,   -57,   -57,
       0,     0,   -57,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,
       0,     0,     0,     0,     0,     0,   -63,   -63,   -63,     0,
       0,   -63,     0,     0,   -69,   -69,   -69,     0,     0,   -69,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,     0,     0,     0,     0,
       0,     0,     0,   -70,   -70,   -70,     0,     0,   -70,     0,
       0,   -71,   -71,   -71,     0,     0,   -71,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,     0,     0,     0,     0,     0,     0,     0,
     -64,   -64,   -64,     0,     0,   -64,     0,   -77,   -77,     0,
       0,     0,     0,   -77,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
       0,     0,     0,     0,     0,     0,   -57,    89,     0,     0,
       0,     0,   -57,     0,   -63,   -63,     0,     0,     0,     0,
     -63,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,
       0,     0,     0,   -69,   -69,     0,     0,     0,     0,   -69,
       0,   -70,   -70,     0,     0,     0,     0,   -70,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,     0,     0,     0,     0,     0,     0,
     -71,   -71,     0,     0,     0,     0,   -71,     0,   -64,   -64,
       0,     0,     0,     0,   -64,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,     0,     0,     0,     0,     0,     0,   -72,   -72,     0,
       0,     0,     0,   -72,     0,     0,   -78,   -78,     0,     0,
       0,   -78,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,
       0,     0,     0,     0,     0,   -77,   -77,     0,     0,     0,
     -77,     0,     0,   -72,   -72,     0,     0,     0,   -72,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,     0,     0,     0,     0,     0,
       0,     0,   205,   -57,     0,     0,     0,   -57,     0,     0,
     -63,   -63,     0,     0,     0,   -63,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,     0,     0,     0,     0,     0,     0,     0,   -69,
     -69,     0,     0,     0,   -69,     0,     0,   -70,   -70,     0,
       0,     0,   -70,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,     0,
       0,     0,     0,     0,     0,     0,   -71,   -71,     0,     0,
       0,   -71,     0,     0,   -64,   -64,   257,   258,   259,   -64,
      38,     0,     0,     0,     0,     0,     0,    39,    40,    41,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,
       0,     0,   260,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,   -77,   -77,   -77,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,     0,     0,   -72,   -72,   -72,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,     0,     0,   289,
     -57,   -57,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
       0,     0,   -63,   -63,   -63,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,     0,     0,   -69,   -69,   -69,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,     0,     0,   -70,   -70,
     -70,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,     0,
       0,   -71,   -71,   -71,   218,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,     0,     0,   -64,   -64,   -64,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,     0,     0,     0,   -53,   -53,
     218,   -54,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
       0,   -55,   -55,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,     0,     0,     0,   -54,   -54,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,     0,     0,     0,   -56,   -56,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,     0,
     -58,   -58,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
       0,     0,   -77,   -77,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,   -72,   -72,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,     0,     0,   284,   -57,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,
     -63,   -63,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
       0,     0,   -69,   -69,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,     0,     0,     0,   -70,   -70,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,   -71,   -71,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,
     -64,   -64,   202,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,   -55,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,     0,   -54,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,   -56,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,     0,
       0,   -58,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
       0,   -78,   -78,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,     0,   -77,   -77,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,     0,   -72,   -72,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,     0,     0,     0,   -57,   209,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,   -63,
     -63,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,     0,
       0,     0,   -69,   -69,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,     0,   -70,   -70,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,     0,     0,     0,   -71,   -71,    86,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,     0,   -64,   -64,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,
     -53,    86,   -54,   -54,   -54,   -54,   -54,   -54,   -54,     0,
       0,   -55,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
       0,     0,     0,   -54,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,     0,     0,   -56,    83,   -50,   -50,   -50,   -50,
      84,    85,     0,     0,     0,     0,   -58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -50
};

static const yytype_int16 yycheck[] =
{
       8,     8,    31,   110,   130,   193,     0,    15,    15,     5,
     117,     0,   205,     0,     0,    23,   209,     4,     4,    28,
      44,    45,    30,     5,    18,    19,     0,    30,   221,    18,
      19,    25,   109,    29,    30,     0,    25,    45,   226,   116,
     109,   109,   109,   120,    18,    19,    10,    29,    72,    73,
     109,    25,     1,    18,    19,    28,   182,     3,     4,     5,
      25,     7,    70,    70,    72,    32,    30,    31,    14,    15,
      16,    79,    80,    81,    82,    83,    84,    85,    86,     0,
     109,    89,    30,    29,    30,   109,   110,     0,     3,     4,
       5,   284,     7,   117,    28,    29,   289,    18,    19,    14,
      15,    16,     0,   111,    25,    18,    19,    32,     5,   117,
     134,    10,    25,    28,    29,   123,   123,   224,   126,   126,
      18,    19,    29,    20,    29,     5,   134,    25,    28,    28,
       5,   155,    29,     3,     4,     5,   144,     7,    28,    29,
     164,    10,   150,   150,    14,    15,    16,   155,   156,    29,
      30,     3,     4,     5,    29,     7,   164,   181,     5,    29,
      30,    30,    14,    15,    16,   173,    18,    19,    33,    21,
      22,    23,    24,    25,     5,    28,    29,    29,    28,    29,
      32,    33,    29,    28,    28,   292,    28,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   303,   205,    29,   223,
     224,   209,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   236,   221,   291,   223,     5,    30,     5,    30,
      18,    19,   291,   291,   291,   302,     0,    25,   236,   306,
      30,   239,   291,   302,   302,   302,   260,   306,   306,   306,
      29,     5,    29,   302,    18,    19,    28,   306,     9,    10,
      11,    25,   260,    45,    30,   263,    20,    30,    31,     3,
       4,     5,   291,     7,    30,    29,    28,   291,   292,    30,
      14,    15,    16,   302,    66,    28,   284,   306,   302,   303,
      72,   289,   306,    30,    31,    29,    28,    79,    80,    81,
      82,    83,    84,    85,    86,   303,    30,    89,    18,    19,
      30,    31,     3,     4,     5,    25,     7,     1,     8,     9,
      10,    11,    30,    14,    15,    16,    28,    18,    19,   111,
      21,    22,    23,    24,    25,   117,    30,    31,    29,    28,
      30,    32,    33,     6,     7,     8,     9,    10,    11,    12,
      13,    28,   134,     6,     7,     8,     9,    10,    11,    12,
      13,    29,   144,    30,    31,    28,    29,    29,     3,     4,
       5,    34,     7,   155,   156,    30,    29,    30,    31,    14,
      15,    16,   164,    18,    19,    28,    21,    22,    23,    24,
      25,   173,     9,    10,    29,    28,    30,    32,    33,    30,
       6,     7,     8,     9,    10,    11,    12,    13,    30,    31,
      30,    28,    30,   195,   196,   197,   198,   199,   200,   201,
     202,   203,    28,   205,    45,    30,    31,   209,    34,   211,
     212,   213,   214,   215,   216,   217,   218,   219,    30,   221,
      30,   223,     6,     7,     8,     9,    10,    11,    12,    13,
      30,    72,    30,    31,   236,     9,    10,   239,    79,    80,
      81,    82,    83,    84,    85,    86,    30,    31,    89,    28,
      34,     3,     4,     5,    30,     7,    30,    31,   260,     9,
      10,   263,    14,    15,    16,    33,    18,    19,    30,    21,
     111,    23,    24,    25,    30,    31,   117,    29,    28,    28,
      32,    33,   284,     8,     9,    10,    11,   289,     9,    10,
      11,     9,    10,   134,     7,     8,     9,    10,    11,    12,
      13,   303,    30,   144,    30,    30,    31,    28,    30,     3,
       4,     5,    30,     7,   155,   156,    28,    30,    31,    33,
      14,    15,    16,   164,    18,    19,    30,    21,    22,    23,
      24,    25,   173,    30,    31,    29,    28,    30,    32,    33,
      30,     6,     7,     8,     9,    10,    11,    12,    13,    30,
      31,    30,    30,     4,   195,   196,   197,   198,   199,   200,
     201,   202,   203,    28,   205,    45,    90,    30,   209,    34,
     211,   212,   213,   214,   215,   216,   217,   218,   219,    49,
     221,    -1,   223,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    72,    -1,    -1,   236,     9,    10,   239,    79,
      80,    81,    82,    83,    84,    85,    86,    30,    31,    89,
      -1,    34,     3,     4,     5,    -1,     7,    30,    31,   260,
      -1,    -1,   263,    14,    15,    16,    -1,    18,    19,    -1,
      21,   111,    23,    24,    25,    -1,    -1,   117,    29,    -1,
      -1,    32,    33,   284,     8,     9,    10,    11,   289,     9,
      10,    11,     9,    10,   134,     7,     8,     9,    10,    11,
      12,    13,   303,    -1,   144,    -1,    30,    31,    28,    -1,
       3,     4,     5,    30,     7,   155,   156,    -1,    30,    -1,
      -1,    14,    15,    16,   164,    18,    19,    -1,    21,    22,
      23,    24,    25,   173,    -1,    -1,    29,    -1,    -1,    32,
      33,     3,     4,     5,    -1,     7,    -1,    -1,     8,     9,
      10,    11,    14,    15,    16,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,   205,    45,    29,    -1,   209,
      30,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,   221,    -1,   223,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    72,    -1,    -1,   236,    -1,    -1,   239,
      79,    80,    81,    82,    83,    84,    85,    86,    30,    -1,
      89,    -1,    34,     3,     4,     5,    -1,     7,    -1,    -1,
     260,    -1,    -1,   263,    14,    15,    16,    -1,    18,    19,
      -1,    21,   111,    23,    24,    25,    -1,    -1,   117,    29,
      -1,    -1,    32,    33,   284,     8,     9,    10,    11,   289,
       8,     9,    10,    11,    -1,   134,     8,     9,    10,    11,
       9,    10,    11,   303,    -1,   144,    -1,    30,    31,    -1,
      28,     3,     4,     5,    -1,     7,   155,   156,    30,    31,
      -1,    30,    14,    15,    16,   164,    18,    19,    -1,    21,
      22,    23,    24,    25,   173,    -1,    -1,    29,    -1,    -1,
      32,    33,     3,     4,     5,    -1,     7,    -1,    -1,     8,
       9,    10,    11,    14,    15,    16,   195,   196,   197,   198,
     199,   200,   201,   202,   203,    -1,   205,    45,    29,    -1,
     209,    30,   211,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,   221,    -1,   223,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    72,    -1,    -1,   236,    -1,    -1,
     239,    79,    80,    81,    82,    83,    84,    85,    86,    30,
      -1,    89,    -1,    34,     3,     4,     5,    -1,     7,    -1,
      -1,   260,    -1,    -1,   263,    14,    15,    16,    -1,    18,
      19,    -1,    21,   111,    23,    24,    25,    -1,    -1,   117,
      29,    -1,    -1,    32,    33,   284,     8,     9,    10,    11,
     289,     8,     9,    10,    11,    -1,   134,     8,     9,    10,
      11,    -1,    -1,    -1,   303,    -1,   144,    -1,    30,    31,
      -1,    28,     3,     4,     5,    -1,     7,   155,   156,    30,
      31,    -1,    -1,    14,    15,    16,   164,    18,    19,    -1,
      21,    22,    23,    24,    25,   173,    -1,    -1,    29,    -1,
      -1,    32,    33,     3,     4,     5,    -1,     7,    -1,    -1,
       8,     9,    10,    11,    14,    15,    16,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    45,   205,    -1,    29,
      -1,   209,    30,   211,   212,   213,   214,   215,   216,   217,
     218,   219,    -1,   221,    -1,   223,     9,    10,    11,    -1,
      -1,    -1,    45,    72,    -1,    -1,    -1,    -1,   236,    -1,
      -1,   239,    -1,    82,    -1,    84,    85,    30,    31,    -1,
      89,     6,     7,     8,     9,    10,    11,    12,    13,    72,
      -1,    -1,   260,    -1,    -1,   263,     8,     9,    10,    11,
      -1,    -1,   111,    -1,    87,    30,    89,    -1,   117,    -1,
      -1,     3,     4,     5,    -1,     7,   284,    -1,    30,    -1,
      -1,   289,    14,    15,    16,   134,    18,    19,   111,    21,
      22,    23,    24,    25,   117,   303,    -1,    29,    -1,    -1,
      32,    33,     8,     9,    10,    11,   155,    -1,     3,     4,
       5,   134,     7,    -1,    -1,   164,    -1,    45,    -1,    14,
      15,    16,    28,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,   155,    -1,    29,    -1,    -1,    32,    33,    -1,
      -1,   164,    -1,    -1,    72,    -1,   195,   196,   197,   198,
      -1,   200,   201,    -1,   203,    83,   205,    -1,    -1,    -1,
     209,    89,   211,   212,   213,   214,    -1,   216,   217,    -1,
     219,    -1,   221,    -1,   223,     8,     9,    10,    11,    -1,
     203,    -1,   205,   111,    -1,    -1,   209,   236,    -1,   117,
       8,     9,    10,    11,    -1,    -1,   219,    30,   221,    -1,
     223,    -1,    -1,     3,     4,     5,   134,     7,    -1,    -1,
      28,   260,    -1,   236,    14,    15,    16,    -1,    18,    19,
      -1,    21,    22,    23,    24,    25,    -1,   155,    -1,    29,
      45,    -1,    32,    33,    -1,   284,   164,   260,    -1,    -1,
     289,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,   303,    -1,    -1,    72,    -1,    -1,
      -1,   284,    -1,    -1,    29,    30,   289,   195,   196,   197,
     198,   199,   200,   201,    89,   203,    -1,   205,    -1,    -1,
     303,   209,    -1,   211,   212,   213,   214,   215,   216,   217,
      -1,   219,    -1,   221,    -1,   223,   111,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,     3,     4,     5,   236,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,   134,
      18,    19,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,   260,    -1,    32,    33,    -1,    -1,    -1,    -1,
     155,    -1,    -1,    45,    -1,    -1,     3,     4,     5,   164,
       7,     3,     4,     5,    -1,     7,   284,    14,    15,    16,
      -1,   289,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    29,    -1,    -1,   303,    -1,    29,    -1,    81,
     195,   196,   197,   198,    -1,   200,   201,    89,   203,    45,
     205,     9,    10,    11,   209,    -1,   211,   212,   213,   214,
      -1,   216,   217,    -1,   219,    -1,   221,    -1,   223,   111,
      -1,    -1,    30,    31,    -1,   117,    72,    -1,     3,     4,
       5,   236,     7,    -1,    80,    -1,    -1,    -1,    -1,    14,
      15,    16,   134,    89,    -1,    -1,    21,    -1,    23,    24,
       8,     9,    10,    11,    29,   260,    -1,    32,     8,     9,
      10,    11,    -1,   155,    -1,   111,    -1,    -1,    -1,    -1,
      28,   117,   164,    -1,    -1,    -1,    -1,    -1,    28,   284,
      -1,     3,     4,     5,   289,     7,    -1,    -1,   134,    45,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,   303,    21,
      -1,    23,    24,   195,   196,   197,    -1,    29,    -1,   155,
      32,   203,    -1,   205,    45,    -1,    72,   209,   164,   211,
     212,   213,    -1,    79,    -1,    -1,    -1,   219,    -1,   221,
      -1,   223,    -1,    89,     3,     4,     5,    -1,     7,    -1,
      -1,    72,    -1,    -1,   236,    14,    15,    16,    -1,   195,
     196,    -1,    -1,    -1,    -1,   111,    -1,   203,    89,   205,
      29,   117,    -1,   209,    -1,   211,   212,    -1,   260,    -1,
       3,     4,     5,   219,     7,   221,    -1,   223,   134,    -1,
     111,    14,    15,    16,    -1,    -1,   117,    -1,    -1,    -1,
     236,    -1,   284,    -1,    -1,    -1,    29,   289,    -1,   155,
      -1,    -1,    -1,   134,    -1,     3,     4,     5,   164,     7,
      -1,   303,    -1,    -1,   260,    -1,    14,    15,    16,    -1,
      18,    19,    -1,    21,   155,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,   164,    32,    33,    -1,    -1,   284,   195,
      -1,    -1,    -1,   289,    -1,    -1,    -1,   203,    -1,   205,
      -1,    -1,    -1,   209,    -1,   211,    -1,   303,     3,     4,
       5,    -1,     7,   219,    -1,   221,    -1,   223,    -1,    14,
      15,    16,   203,    -1,   205,    -1,    -1,    -1,   209,    -1,
     236,    -1,    -1,    -1,    29,    -1,    -1,    -1,   219,    -1,
     221,    -1,   223,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    -1,   260,   236,    14,    15,    16,    -1,
      18,    19,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    -1,    -1,   284,   260,
       3,     4,     5,   289,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    16,    -1,    18,    19,   303,    21,    -1,
      23,    24,    25,   284,    -1,    -1,    29,    -1,   289,    32,
      33,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      -1,    -1,   303,    14,    15,    16,    -1,    18,    19,    -1,
      21,    -1,    23,    24,    25,     3,     4,     5,    29,     7,
      -1,    32,    33,    -1,    -1,    -1,    14,    15,    16,    -1,
      18,    19,    -1,    21,    -1,    23,    24,    25,     3,     4,
       5,    29,     7,    -1,    32,    33,    -1,    -1,    -1,    14,
      15,    16,    -1,    18,    19,    -1,    21,    -1,    23,    24,
      25,     3,     4,     5,    29,     7,    -1,    32,    33,    -1,
      -1,    -1,    14,    15,    16,    -1,    18,    19,    -1,    21,
      -1,    23,    24,    25,     3,     4,     5,    29,     7,    -1,
      32,    33,    -1,    -1,    -1,    14,    15,    16,    -1,    18,
      19,    -1,    21,    -1,    23,    24,    25,     3,     4,     5,
      29,     7,    -1,    32,    33,    -1,    -1,    -1,    14,    15,
      16,    -1,    18,    19,    -1,    21,    -1,    23,    24,    25,
       3,     4,     5,    29,     7,    -1,    32,    33,    -1,    -1,
      -1,    14,    15,    16,    -1,    18,    19,    -1,    21,    -1,
      23,    24,    25,     3,     4,     5,    29,     7,    -1,    32,
      33,    -1,    -1,    -1,    14,    15,    16,    -1,    18,    19,
      -1,    21,    -1,    23,    24,    25,     3,     4,     5,    29,
       7,    -1,    32,    33,    -1,    -1,    -1,    14,    15,    16,
      -1,    18,    19,    -1,    21,    -1,    23,    24,    25,     3,
       4,     5,    29,     7,    -1,    32,    33,    -1,    -1,    -1,
      14,    15,    16,    -1,    18,    19,    -1,    21,    -1,    23,
      24,    25,     3,     4,     5,    29,     7,    -1,    32,    33,
      -1,    -1,    -1,    14,    15,    16,    -1,    18,    19,    -1,
      21,    -1,    23,    24,    25,     3,     4,     5,    29,     7,
      -1,    32,    33,    -1,    -1,    -1,    14,    15,    16,    -1,
      18,    19,    -1,    21,    -1,    23,    24,    25,     3,     4,
       5,    29,     7,    -1,    32,    33,    -1,    -1,    -1,    14,
      15,    16,    -1,    18,    19,    -1,    21,    -1,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,     6,
       7,     8,     9,    10,    11,    12,    13,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    34,    -1,    -1,
      29,    30,    31,    -1,    -1,    34,     6,     7,     8,     9,
      10,    11,    12,    13,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    -1,    34,    -1,    -1,    29,    30,    31,
      -1,    -1,    34,     6,     7,     8,     9,    10,    11,    12,
      13,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    34,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
       6,     7,     8,     9,    10,    11,    12,    13,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    29,    30,    31,    -1,    -1,    34,     6,     7,     8,
       9,    10,    11,    12,    13,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    -1,    -1,    34,    -1,    28,    29,    -1,
      -1,    -1,    -1,    34,     6,     7,     8,     9,    10,    11,
      12,    13,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    34,    -1,    28,    29,    -1,    -1,    -1,    -1,
      34,     6,     7,     8,     9,    10,    11,    12,    13,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,     6,     7,
       8,     9,    10,    11,    12,    13,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    34,    -1,    28,    29,
      -1,    -1,    -1,    -1,    34,     6,     7,     8,     9,    10,
      11,    12,    13,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    29,    30,    -1,    -1,
      -1,    34,     6,     7,     8,     9,    10,    11,    12,    13,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      34,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,     6,
       7,     8,     9,    10,    11,    12,    13,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    34,    -1,    -1,
      29,    30,    -1,    -1,    -1,    34,     6,     7,     8,     9,
      10,    11,    12,    13,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    34,    -1,    -1,    29,    30,    -1,
      -1,    -1,    34,     6,     7,     8,     9,    10,    11,    12,
      13,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    34,    -1,    -1,    29,    30,     3,     4,     5,    34,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    29,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    29,    30,    31,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    29,    30,    31,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    29,
      30,    31,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    29,    30,    31,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    29,    30,    31,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    29,    30,
      31,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    29,    30,    31,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    29,    30,    31,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    30,    31,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    30,    31,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    30,    31,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    30,    31,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      30,    31,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    29,    30,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    29,    30,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    29,    30,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      29,    30,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    29,    30,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    29,    30,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    29,    30,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      29,    30,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    30,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    30,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    30,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    30,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    28,    29,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    28,    29,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    28,    29,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    28,    29,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    28,
      29,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    28,    29,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    28,    29,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    28,    29,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    28,    29,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      28,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    28,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    28,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    28,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    19,    25,    36,    37,    38,    40,    74,    20,
      20,     1,     0,    37,     5,    29,    52,    73,    28,    52,
      29,    39,    30,    41,    28,    43,    44,    45,    52,    30,
      31,    42,    45,    32,    46,    47,     3,     4,     7,    14,
      15,    16,    21,    23,    24,    29,    38,    46,    48,    49,
      50,    51,    53,    54,    55,    56,    57,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    72,    73,
      74,    75,    29,    29,    57,    57,    33,    50,    28,    10,
       9,    11,     8,     7,    12,    13,     6,    34,    67,    29,
      52,    57,    57,    58,    28,    30,    61,    67,    62,    63,
      64,    66,    64,    64,    67,    59,    59,    70,    71,    30,
      28,    31,    30,    51,    58,    59,    22,    28,    51,    58,
      30,    51,     5,    29,    73,     5,    29,    73,     5,    25,
      32,     3,     4,     5,    29,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    72,    73,    75,     5,
      29,    73,     3,     4,     5,    29,    68,    69,    72,    73,
      75,     3,     4,     5,    29,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    72,    73,    75,    39,    21,
      23,    24,    32,    46,    53,    54,    55,    56,    57,    57,
      52,    52,     1,    47,    57,    10,     9,    11,     8,     7,
      12,    13,     6,    34,    67,    29,    52,    57,    67,    29,
      57,    10,     9,    11,     8,     7,    12,    13,     6,    34,
      67,    29,    28,    29,    29,    57,    47,    28,    30,    30,
      28,    48,    30,     3,     4,     5,    29,    61,    67,    68,
      69,    72,    73,    75,    62,    63,    64,    66,    64,    64,
      67,    59,    71,    30,    30,    71,    30,     3,     4,     5,
      29,    61,    67,    68,    69,    72,    73,    75,    62,    63,
      64,    66,    64,    64,    67,    59,    71,    57,    58,    28,
      48,    33,    57,    67,    29,    30,    30,    57,    67,    29,
      30,    30,    28,    33,    30,    71,    30,    71,    51,    58,
      30,    30,    22,    28,    51,    58,    30,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    39,    38,    38,    41,
      42,    40,    43,    43,    44,    44,    45,    47,    46,    48,
      48,    49,    49,    50,    50,    51,    51,    51,    51,    51,
      52,    52,    53,    54,    54,    55,    56,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    73,    74,    74,    74,    74,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     4,     3,     0,
       0,     8,     0,     1,     3,     1,     1,     0,     4,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     5,     7,     3,     9,     1,     0,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     4,     1,     3,     1,     0,     1,
       1,     3,     1,     1,     1,     2,     2,     1,     1
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
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
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
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
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

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
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
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_MULT: /* MULT  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1918 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1924 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1930 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1936 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1942 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1948 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1954 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1960 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1966 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1972 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1978 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1984 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1990 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 1996 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2002 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2008 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 59 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2014 "src/bison/grammar.c"
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
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: prog external_declaration  */
#line 62 "src/bison/math.y"
                                { list_push(&root->children, (yyvsp[0].ast)); }
#line 2285 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 63 "src/bison/math.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 2291 "src/bison/grammar.c"
    break;

  case 6: /* @1: %empty  */
#line 70 "src/bison/math.y"
                                  {
        // Symbol *sym = context_has_symbol(current_context, $2->value.symref->symbol);
        // if (sym) {
        //     yyerror(NULL);
        //     CIPL_PERROR_CURSOR("redeclaration of '%s'\n", error_cursor, $2->value.symref->symbol->name);
        //     $$ = NULL;
        // } else {
        //     $$ = ast_symref_init(
        //         symbol_init_copy(context_declare_variable(current_context, $2->value.symref))
        //     );
        // }
        Symbol *declared = context_declare_variable(current_context, (yyvsp[0].ast)->value.symref);
        symbol_update_type(declared, symbol_type_from_str((yyvsp[-1].pchar)));
        (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
        ast_free((yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2313 "src/bison/grammar.c"
    break;

  case 7: /* declaration: type declarator @1 ';'  */
#line 86 "src/bison/math.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 2321 "src/bison/grammar.c"
    break;

  case 8: /* declaration: LET error ';'  */
#line 89 "src/bison/math.y"
                    {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 2332 "src/bison/grammar.c"
    break;

  case 9: /* @2: %empty  */
#line 97 "src/bison/math.y"
                                           {
        if (current_context->current_scope > 1) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("CIPL forbids nested functions\n", error_cursor);
            (yyval.ast) = NULL;
        } else {
            // Symbol *sym = context_has_symbol(current_context, $2->value.symref->symbol);
            // if (sym) {
            //     yyerror(NULL);
            //     CIPL_PERROR_CURSOR("redefinition of '%s'\n", error_cursor, $2->value.symref->symbol->name);
            //     $$ = NULL;
            // } else {
            //     previous_context = current_context;
            //     list_push(&contexts, context_init($2->value.symref->symbol->name));
            //     current_context = list_peek_last(&contexts);
            //     $$ = ast_symref_init(
            //         symbol_init_copy(context_declare_function(previous_context, $2->value.symref))
            //     );
            // }
            previous_context = current_context;
            list_push(&contexts, context_init((yyvsp[-1].ast)->value.symref->symbol->name));
            current_context = list_peek_last(&contexts);
            
            Symbol *declared = context_declare_function(previous_context, (yyvsp[-1].ast)->value.symref);
            symbol_update_type(declared, symbol_type_from_str((yyvsp[-2].pchar)));
            (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
        }
        ast_free((yyvsp[-1].ast));
        free((yyvsp[-2].pchar));
    }
#line 2367 "src/bison/grammar.c"
    break;

  case 10: /* $@3: %empty  */
#line 126 "src/bison/math.y"
                         {
        context_push_scope(current_context);
        LIST_FOR_EACH((yyvsp[-1].list), {
            symbol_update_context(((AST *)__IT__->data)->value.symref->symbol, current_context);
            context_declare_variable(current_context, ((AST *)__IT__->data)->value.symref);
        });
        // hack to save the scope of params and append to the scope of the body
        {
            params_scope = scope_init_copy(stack_peek(&current_context->scopes));
            stack_pop(&current_context->scopes, free_scope_cb);
        }
    }
#line 2384 "src/bison/grammar.c"
    break;

  case 11: /* func_declaration: type declarator '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 137 "src/bison/math.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 2393 "src/bison/grammar.c"
    break;

  case 12: /* param_list.opt: %empty  */
#line 143 "src/bison/math.y"
                       { (yyval.list) = NULL; }
#line 2399 "src/bison/grammar.c"
    break;

  case 14: /* params_list: params_list ',' param_decl  */
#line 147 "src/bison/math.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2405 "src/bison/grammar.c"
    break;

  case 15: /* params_list: param_decl  */
#line 148 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2411 "src/bison/grammar.c"
    break;

  case 17: /* $@4: %empty  */
#line 154 "src/bison/math.y"
                   {
        parent_scope = current_context->current_scope;
        // hack to update the current scope 
        if (params_scope) {
            stack_push(&current_context->scopes, params_scope);
            current_context->current_scope = ((Scope *)stack_peek(&current_context->scopes))->index;
            params_scope = NULL;
        } else {
            context_push_scope(current_context);
        }
    }
#line 2427 "src/bison/grammar.c"
    break;

  case 18: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 164 "src/bison/math.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        current_context->current_scope = parent_scope;
    }
#line 2437 "src/bison/grammar.c"
    break;

  case 19: /* block_item_list.opt: block_item_list  */
#line 171 "src/bison/math.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 2443 "src/bison/grammar.c"
    break;

  case 20: /* block_item_list.opt: %empty  */
#line 172 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2449 "src/bison/grammar.c"
    break;

  case 21: /* block_item_list: block_item_list block_item  */
#line 175 "src/bison/math.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2455 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list: block_item  */
#line 176 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2461 "src/bison/grammar.c"
    break;

  case 31: /* declarator: '(' declarator ')'  */
#line 191 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2467 "src/bison/grammar.c"
    break;

  case 32: /* expr_stmt: expression ';'  */
#line 194 "src/bison/math.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2473 "src/bison/grammar.c"
    break;

  case 33: /* cond_stmt: IF '(' expression ')' statement  */
#line 197 "src/bison/math.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 2481 "src/bison/grammar.c"
    break;

  case 34: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 200 "src/bison/math.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2489 "src/bison/grammar.c"
    break;

  case 35: /* jmp_stmt: RETURN expression ';'  */
#line 205 "src/bison/math.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 2495 "src/bison/grammar.c"
    break;

  case 36: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 208 "src/bison/math.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2503 "src/bison/grammar.c"
    break;

  case 38: /* expression.opt: %empty  */
#line 216 "src/bison/math.y"
                       { (yyval.ast) = NULL; }
#line 2509 "src/bison/grammar.c"
    break;

  case 41: /* assign_expr: unary_expr '=' assign_expr  */
#line 221 "src/bison/math.y"
                                 { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2515 "src/bison/grammar.c"
    break;

  case 43: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 225 "src/bison/math.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2524 "src/bison/grammar.c"
    break;

  case 45: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 232 "src/bison/math.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2533 "src/bison/grammar.c"
    break;

  case 47: /* eq_expr: eq_expr EQ rel_expr  */
#line 239 "src/bison/math.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2542 "src/bison/grammar.c"
    break;

  case 49: /* rel_expr: rel_expr REL dl_dg_expr  */
#line 246 "src/bison/math.y"
                              {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2551 "src/bison/grammar.c"
    break;

  case 51: /* dl_dg_expr: add_expr DL_DG dl_dg_expr  */
#line 253 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2560 "src/bison/grammar.c"
    break;

  case 52: /* dl_dg_expr: add_expr COLON dl_dg_expr  */
#line 257 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2569 "src/bison/grammar.c"
    break;

  case 54: /* add_expr: add_expr ADD mult_expr  */
#line 264 "src/bison/math.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2578 "src/bison/grammar.c"
    break;

  case 56: /* mult_expr: mult_expr MULT unary_expr  */
#line 271 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2587 "src/bison/grammar.c"
    break;

  case 58: /* unary_expr: unary_ops unary_expr  */
#line 278 "src/bison/math.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2596 "src/bison/grammar.c"
    break;

  case 64: /* postfix_expr: postfix_expr '(' arg_expr_list.opt ')'  */
#line 291 "src/bison/math.y"
                                             {
        (yyval.ast) = ast_funcall_init((yyvsp[-3].ast), ast_params_init((yyvsp[-1].list)));
    }
#line 2604 "src/bison/grammar.c"
    break;

  case 65: /* arg_expr_list: assign_expr  */
#line 296 "src/bison/math.y"
                           { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2610 "src/bison/grammar.c"
    break;

  case 66: /* arg_expr_list: arg_expr_list ',' assign_expr  */
#line 297 "src/bison/math.y"
                                    { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2616 "src/bison/grammar.c"
    break;

  case 68: /* arg_expr_list.opt: %empty  */
#line 301 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2622 "src/bison/grammar.c"
    break;

  case 69: /* primary_expr: id  */
#line 304 "src/bison/math.y"
                 {
        // Symbol *sym = context_search_symbol_scopes(current_context, $1->value.symref->symbol);
        // if (!sym) {
        //     yyerror(NULL);
        //     CIPL_PERROR_CURSOR("'%s' undeclared (first use in this function)\n", $1->value.symref->symbol->def_pos, $1->value.symref->symbol->name);
        //     $$ = NULL;
        // } else {
        //     $$ = ast_symref_init(symbol_init_copy(sym));
        // }
        symbol_update_context((yyvsp[0].ast)->value.symref->symbol, current_context);
        (yyval.ast) = ast_symref_init(symbol_init_copy((yyvsp[0].ast)->value.symref->symbol));
        ast_free((yyvsp[0].ast));
    }
#line 2640 "src/bison/grammar.c"
    break;

  case 71: /* primary_expr: '(' expression ')'  */
#line 318 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2646 "src/bison/grammar.c"
    break;

  case 72: /* id: NAME  */
#line 321 "src/bison/math.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 2652 "src/bison/grammar.c"
    break;

  case 75: /* type: INT LIST  */
#line 326 "src/bison/math.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 2664 "src/bison/grammar.c"
    break;

  case 76: /* type: FLOAT LIST  */
#line 333 "src/bison/math.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 2676 "src/bison/grammar.c"
    break;

  case 77: /* constant: NUMBER_REAL  */
#line 342 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 2682 "src/bison/grammar.c"
    break;

  case 78: /* constant: NUMBER_INT  */
#line 343 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 2688 "src/bison/grammar.c"
    break;


#line 2692 "src/bison/grammar.c"

      default: break;
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
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
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
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 346 "src/bison/math.y"


void yyerror(const char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    if (s) CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
    ++errors_count;
}
