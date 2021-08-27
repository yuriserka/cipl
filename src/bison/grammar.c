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
#line 3 "src/bison/math.y"

    #include <stdarg.h>
	#include <stdio.h>

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
    Scope *current_scope;
    Scope *previous_scope;
    Context *current_context;
    Context *previous_context;

#line 92 "src/bison/grammar.c"

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
  YYSYMBOL_LET = 5,                        /* LET  */
  YYSYMBOL_LT = 6,                         /* LT  */
  YYSYMBOL_LE = 7,                         /* LE  */
  YYSYMBOL_GT = 8,                         /* GT  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_NE = 11,                        /* NE  */
  YYSYMBOL_NAME = 12,                      /* NAME  */
  YYSYMBOL_13_ = 13,                       /* '!'  */
  YYSYMBOL_14_ = 14,                       /* '='  */
  YYSYMBOL_15_ = 15,                       /* '+'  */
  YYSYMBOL_16_ = 16,                       /* '-'  */
  YYSYMBOL_17_ = 17,                       /* '*'  */
  YYSYMBOL_18_ = 18,                       /* '/'  */
  YYSYMBOL_19_ = 19,                       /* ';'  */
  YYSYMBOL_20_ = 20,                       /* '('  */
  YYSYMBOL_21_ = 21,                       /* ')'  */
  YYSYMBOL_22_ = 22,                       /* '{'  */
  YYSYMBOL_23_ = 23,                       /* '}'  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_YYACCEPT = 25,                  /* $accept  */
  YYSYMBOL_prog = 26,                      /* prog  */
  YYSYMBOL_external_declaration = 27,      /* external_declaration  */
  YYSYMBOL_declaration = 28,               /* declaration  */
  YYSYMBOL_29_1 = 29,                      /* $@1  */
  YYSYMBOL_func_declaration = 30,          /* func_declaration  */
  YYSYMBOL_31_2 = 31,                      /* @2  */
  YYSYMBOL_32_3 = 32,                      /* $@3  */
  YYSYMBOL_compound_stmt = 33,             /* compound_stmt  */
  YYSYMBOL_34_4 = 34,                      /* $@4  */
  YYSYMBOL_35_block_item_list_opt = 35,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 36,           /* block_item_list  */
  YYSYMBOL_block_item = 37,                /* block_item  */
  YYSYMBOL_statement = 38,                 /* statement  */
  YYSYMBOL_declarator = 39,                /* declarator  */
  YYSYMBOL_id_list = 40,                   /* id_list  */
  YYSYMBOL_41_id_list_opt = 41,            /* id_list.opt  */
  YYSYMBOL_expr_stmt = 42,                 /* expr_stmt  */
  YYSYMBOL_expression = 43,                /* expression  */
  YYSYMBOL_assign_expr = 44,               /* assign_expr  */
  YYSYMBOL_eq_expr = 45,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 46,                  /* rel_expr  */
  YYSYMBOL_add_expr = 47,                  /* add_expr  */
  YYSYMBOL_mult_expr = 48,                 /* mult_expr  */
  YYSYMBOL_cast_expr = 49,                 /* cast_expr  */
  YYSYMBOL_postfix_expr = 50,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 51,             /* arg_expr_list  */
  YYSYMBOL_52_arg_expr_list_opt = 52,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 53,              /* primary_expr  */
  YYSYMBOL_id = 54,                        /* id  */
  YYSYMBOL_constant = 55                   /* constant  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2595

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   267


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
       2,     2,     2,    13,     2,     2,     2,     2,     2,     2,
      20,    21,    17,    15,    24,    16,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    19,
       2,    14,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    54,    57,    58,    61,    61,    71,    78,
      88,    78,   105,   105,   117,   118,   121,   122,   125,   126,
     129,   130,   133,   134,   137,   138,   141,   142,   145,   148,
     151,   152,   158,   159,   160,   163,   164,   165,   166,   167,
     170,   171,   172,   175,   176,   177,   180,   181,   182,   185,
     186,   189,   190,   193,   194,   197,   208,   209,   212,   215,
     216
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER_INT",
  "NUMBER_REAL", "LET", "LT", "LE", "GT", "GE", "EQ", "NE", "NAME", "'!'",
  "'='", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'", "'{'", "'}'",
  "','", "$accept", "prog", "external_declaration", "declaration", "$@1",
  "func_declaration", "@2", "$@3", "compound_stmt", "$@4",
  "block_item_list.opt", "block_item_list", "block_item", "statement",
  "declarator", "id_list", "id_list.opt", "expr_stmt", "expression",
  "assign_expr", "eq_expr", "rel_expr", "add_expr", "mult_expr",
  "cast_expr", "postfix_expr", "arg_expr_list", "arg_expr_list.opt",
  "primary_expr", "id", "constant", YY_NULLPTR
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
     265,   266,   267,    33,    61,    43,    45,    42,    47,    59,
      40,    41,   123,   125,    44
};
#endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,     0,    62,    79,   104,   117,   -10,    61,    16,   164,
     166,  -150,   125,   131,     4,     2,    21,   180,    39,   135,
     -18,    45,    26,    60,    65,    44,    75,    41,  2076,  2091,
       7,   107,   107,   193,   222,   236,   257,    98,   342,   369,
     454,   481,   126,   128,    82,   749,  2500,  2388,  2346,  2106,
    2121,  2136,  2151,   144,  2360,  2374,   181,    41,   137,   566,
     593,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   107,   880,  2166,   178,  2570,  2402,  2576,  2514,  2528,
    2542,  2556,  2416,  2430,  2444,  2458,   184,    94,   120,   183,
     620,   495,  2181,   122,   186,    16,   189,   141,  2196,   192,
     205,    16,   209,  1534,  1550,  1566,   193,   193,   193,   191,
      48,  2046,   281,  1870,  1678,  1582,  1598,  1614,  1630,   227,
    2211,  2226,  2241,   383,   383,   193,  2256,  2271,  2286,  2301,
     900,   926,   945,   495,   495,   193,    31,   212,    67,  1287,
    1078,   964,   983,  1002,  1021,   226,   676,   229,  1694,  1710,
     232,   690,   690,   690,   690,   690,   690,   690,   690,   690,
     690,   193,   880,   784,  2472,  2486,   233,   880,  1097,  1116,
     234,   750,   750,   750,   750,   750,   750,   750,   750,   750,
     750,   495,   880,   242,   238,  1646,  1726,  1742,  1758,   690,
     690,   193,  2052,  1886,  1774,  1790,  1806,  1822,  2068,   817,
    1998,  2014,  2030,  1902,  1918,  1934,  1950,   243,   244,  2316,
     250,  1040,   835,  1135,  1154,   750,   750,   193,   870,  1306,
    1173,  1192,  1211,  1230,  1515,  1439,  1458,  1477,  1496,  1325,
    1344,  1363,  1382,   143,   251,  1966,  1982,   253,   880,  1662,
    2331,  1401,  1420,   254,   880,  1059,  1838,   255,  1249,   260,
    1854,  1268
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
       0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,   276,    96,   245,  -150,  -150,  -150,  -150,  -150,
     225,  -150,   248,  -150,    13,  -150,  -150,  -150,    -9,   714,
     -22,   -23,   712,   657,   160,   272,  -150,  -149,   384,    -1,
     496
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    35,    16,     5,    18,    26,    36,    57,
      37,    38,    39,    40,     9,    20,    21,    41,    42,    87,
     136,   137,   138,   139,    76,   126,    88,    89,   127,   128,
     129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,     6,     1,   -27,    45,    44,    23,    96,    99,    13,
     111,   110,     7,   208,    -9,    45,    44,    22,   210,   100,
       8,    14,    25,    -9,    56,    17,    51,   101,    94,   102,
      51,    51,   117,   234,    45,    44,    95,    51,    75,    77,
      19,   171,   172,    53,    28,    29,    30,   -25,    45,    44,
     -25,    97,   -30,    98,    31,   -30,    51,    32,   151,   152,
     -26,    33,    11,    34,   -15,   -24,    24,     1,   -24,   -30,
      51,   143,    97,   -35,   -35,   -35,   -35,   -35,   -35,    -3,
     -58,   -58,   177,   178,    -3,   111,   110,   -10,   -35,   247,
     143,   -35,    61,    62,    96,   249,     4,    27,     4,   150,
      96,   -30,   111,   110,    -5,   117,   117,   117,   145,    -5,
      28,    29,   111,   110,   147,   -51,   166,    -4,   -51,    98,
      31,    58,    -4,    32,   117,    -2,   170,    33,   192,   198,
      -2,    -8,   143,   143,   117,    -7,    -8,   -11,   111,   110,
      -7,   -53,   -11,   -52,    91,    60,   -52,   -29,   218,   224,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     117,   143,   -58,    -6,   -31,   -58,   143,   -31,   111,   110,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     143,   143,   237,    -6,    15,   -22,   -22,    48,   196,   196,
     117,    54,    55,   114,   111,   110,   103,   104,    48,   -23,
     -23,    90,    73,   -31,    92,   105,   106,   -58,   243,   107,
     -22,   146,   -29,   108,   222,   222,   117,    48,   173,   174,
     175,   176,   -32,   -32,   -58,   -12,   -12,   -12,   -22,    84,
      85,    48,   140,   -32,   -12,   -12,   -32,   143,   -12,   -18,
     -18,   -18,   -12,   143,   -12,   -12,   163,   183,   -18,   -18,
     184,   140,   -18,   185,   209,   211,   -18,   -23,   -18,   -18,
     -21,   -21,   -21,   -23,   -31,   239,   148,   149,   114,   -21,
     -21,   240,   245,   -21,   246,   248,   250,   -21,    12,   -21,
     -21,   251,    74,   164,   165,   114,    59,   -35,   -35,   -35,
     -35,   -35,   -35,   168,   169,   114,   157,   158,   119,    49,
       0,     0,   -35,    49,    49,   115,     0,     0,     0,     0,
      49,   193,   193,   193,   193,   193,   193,   193,   193,   205,
     206,   114,   140,     0,     0,     0,     0,   140,     0,    49,
       0,   219,   219,   219,   219,   219,   219,   219,   219,   231,
     232,   140,   140,    49,   141,    28,    29,    30,     0,   235,
     236,   114,     0,     0,    98,    31,     0,     0,    32,     0,
       0,     0,    33,   141,    34,   -14,     0,     0,     0,     0,
       0,     0,   -17,   -17,   -17,   241,   242,   114,   115,   115,
     115,   -17,   -17,     0,     0,   -17,   120,   121,     0,   -17,
       0,   -17,   -17,     0,     0,   122,   123,   115,   140,   124,
       0,     0,     0,   125,   140,   141,   141,   115,     0,     0,
       0,    50,     0,     0,     0,    50,    50,   116,     0,     0,
       0,     0,    50,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   115,   141,     0,     0,     0,     0,   141,
       0,    50,     0,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   141,   141,    50,   142,   -19,   -19,   -19,
       0,   194,   194,   115,     0,     0,   -19,   -19,     0,     0,
     -19,     0,     0,     0,   -19,   142,   -19,   -19,     0,     0,
       0,     0,     0,     0,   -20,   -20,   -20,   220,   220,   115,
     116,   116,   116,   -20,   -20,     0,     0,   -20,   130,   131,
       0,   -20,     0,   -20,   -20,     0,     0,   132,   133,   116,
     141,   134,     0,     0,     0,   135,   141,   142,   142,   116,
       0,     0,     0,    52,     0,     0,     0,    52,    52,   118,
       0,     0,     0,     0,    52,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   116,   142,     0,     0,     0,
       0,   142,     0,    52,     0,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   142,   142,    52,   144,   -16,
     -16,   -16,     0,   195,   195,   116,     0,     0,   -16,   -16,
       0,     0,   -16,     0,     0,     0,   -16,   144,   -16,   -16,
       0,     0,     0,     0,     0,     0,   -28,   -28,   -28,   221,
     221,   116,   118,   118,   118,   -28,   -28,     0,     0,   -28,
       0,     0,     0,   -28,     0,   -28,   -28,     0,     0,     0,
       0,   118,   142,   -13,   -13,   -13,     0,     0,   142,   144,
     144,   118,   -13,   -13,     0,     0,   -13,     0,     0,     0,
     -13,     0,   -13,   -13,     0,     0,     0,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   118,   144,     0,
       0,     0,     0,   144,     0,     0,     0,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   144,   144,    -8,
      -8,    -8,     0,     0,    47,   197,   197,   118,    -8,    -8,
     113,     0,    -8,   186,   187,    47,    -8,     0,    -8,    -8,
       0,     0,   188,   189,     0,     0,   190,     0,     0,     0,
     191,   223,   223,   118,    47,     0,     0,     0,    47,    47,
      47,    47,    47,    47,    82,    83,     0,     0,    47,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,    46,
     144,    43,     0,     0,     0,   112,     0,   109,     0,     0,
      46,     0,    43,   212,   213,    63,    64,    65,    66,   -32,
     -32,     0,   214,   215,     0,   113,   216,     0,   -32,    46,
     217,    43,     0,    46,    46,    78,    79,    80,    81,     0,
       0,     0,   113,    46,     0,    86,     0,    -7,    -7,    -7,
       0,     0,   113,     0,     0,     0,    -7,    -7,     0,     0,
      -7,     0,     0,     0,    -7,    93,    -7,    -7,   113,   113,
     113,   113,   113,   113,   203,   204,     0,     0,   113,     0,
     112,     0,   109,   -36,   -36,   -36,   -36,   -36,   -36,     0,
       0,     0,   157,   158,   229,   230,     0,   112,   -36,   109,
       0,   -60,   -60,   -60,   -60,   -60,   -60,   112,   113,   109,
     -60,   -60,   -60,   -60,     0,   -60,   -60,     0,     0,   -60,
       0,     0,     0,   112,   112,   199,   200,   201,   202,     0,
       0,     0,     0,   112,   113,   207,   173,   174,   175,   176,
     -33,   -33,     0,   130,   131,   225,   226,   227,   228,     0,
       0,   -33,   132,   133,   -33,   233,   134,     0,     0,     0,
     135,   -54,     0,   112,     0,   109,   -60,   -60,   -60,   -60,
     -60,   -60,     0,     0,   -60,   -60,   -60,   -60,   -60,     0,
     -60,   -60,     0,     0,   -60,     0,     0,     0,     0,   112,
       0,   109,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,
     -59,   -59,   -59,   -59,   -59,     0,   -59,   -59,     0,     0,
     -59,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,   -58,
     -58,   -58,   -58,   -58,     0,   -58,   -58,     0,     0,   -58,
     -46,   -46,   -46,   -46,   -46,   -46,     0,     0,   -46,   -46,
     -46,   -46,   -46,     0,   182,   -46,     0,     0,   -46,   -49,
     -49,   -49,   -49,   -49,   -49,     0,     0,   -49,   -49,   -49,
     -49,   -49,     0,   -49,   -49,     0,     0,   -49,   -55,   -55,
     -55,   -55,   -55,   -55,     0,     0,   -55,   -55,   -55,   -55,
     -55,     0,   -55,   -55,     0,     0,   -55,   -56,   -56,   -56,
     -56,   -56,   -56,     0,     0,   -56,   -56,   -56,   -56,   -56,
       0,   -56,   -56,     0,     0,   -56,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,   -57,   -57,   -57,   -57,   -57,     0,
     -57,   -57,     0,     0,   -57,   -50,   -50,   -50,   -50,   -50,
     -50,     0,     0,   -50,   -50,   -50,   -50,   -50,     0,   -50,
     -50,     0,     0,   -50,   -43,   -43,   -43,   -43,   -43,   -43,
       0,     0,   181,   -43,   -43,   -43,   -43,     0,     0,   -43,
       0,     0,   -43,   -47,   -47,   -47,   -47,   -47,   -47,     0,
       0,   -47,   -47,   -47,   -47,   -47,     0,     0,   -47,     0,
       0,   -47,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,
     -48,   -48,   -48,   -48,   -48,     0,     0,   -48,     0,     0,
     -48,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,
     -59,   -59,   -59,   -59,     0,   -59,   -59,     0,     0,   -59,
     -58,   -58,   -58,   -58,   -58,   -58,     0,     0,     0,   -58,
     -58,   -58,   -58,     0,   -58,   -58,     0,     0,   -58,   -46,
     -46,   -46,   -46,   -46,   -46,     0,     0,     0,   -46,   -46,
     -46,   -46,     0,   244,   -46,     0,     0,   -46,   -49,   -49,
     -49,   -49,   -49,   -49,     0,     0,     0,   -49,   -49,   -49,
     -49,     0,   -49,   -49,     0,     0,   -49,   -55,   -55,   -55,
     -55,   -55,   -55,     0,     0,     0,   -55,   -55,   -55,   -55,
       0,   -55,   -55,     0,     0,   -55,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,   -56,   -56,   -56,   -56,     0,
     -56,   -56,     0,     0,   -56,   -57,   -57,   -57,   -57,   -57,
     -57,     0,     0,     0,   -57,   -57,   -57,   -57,     0,   -57,
     -57,     0,     0,   -57,   -50,   -50,   -50,   -50,   -50,   -50,
       0,     0,     0,   -50,   -50,   -50,   -50,     0,   -50,   -50,
       0,     0,   -50,   -40,   -40,   -40,   -40,   -40,   -40,     0,
       0,     0,   -40,   -40,   179,   180,     0,     0,   -40,     0,
       0,   -40,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,
       0,   -43,   -43,   -43,   -43,     0,     0,   -43,     0,     0,
     -43,   -41,   -41,   -41,   -41,   -41,   -41,     0,     0,     0,
     -41,   -41,   179,   180,     0,     0,   -41,     0,     0,   -41,
     -42,   -42,   -42,   -42,   -42,   -42,     0,     0,     0,   -42,
     -42,   179,   180,     0,     0,   -42,     0,     0,   -42,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,   -44,
     -44,   -44,     0,     0,   -44,     0,     0,   -44,   -45,   -45,
     -45,   -45,   -45,   -45,     0,     0,     0,   -45,   -45,   -45,
     -45,     0,     0,   -45,     0,     0,   -45,   -47,   -47,   -47,
     -47,   -47,   -47,     0,     0,     0,   -47,   -47,   -47,   -47,
       0,     0,   -47,     0,     0,   -47,   -48,   -48,   -48,   -48,
     -48,   -48,     0,     0,     0,   -48,   -48,   -48,   -48,     0,
       0,   -48,     0,     0,   -48,   -36,   -36,   -36,   -36,   -36,
     -36,     0,     0,     0,   177,   178,     0,     0,     0,     0,
     -36,     0,     0,   -36,   -37,   -37,   -37,   -37,   -37,   -37,
       0,     0,     0,   177,   178,     0,     0,     0,     0,   -37,
       0,     0,   -37,   -38,   -38,   -38,   -38,   -38,   -38,     0,
       0,     0,   177,   178,     0,     0,     0,     0,   -38,     0,
       0,   -38,   -39,   -39,   -39,   -39,   -39,   -39,     0,     0,
       0,   177,   178,     0,     0,     0,     0,   -39,     0,     0,
     -39,   173,   174,   175,   176,   -34,   -34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -34,     0,     0,   -34,
     -60,   -60,   -60,   -60,   -60,   -60,     0,     0,   -60,   -60,
     -60,   -60,   -60,     0,   -60,   -60,   -59,   -59,   -59,   -59,
     -59,   -59,     0,     0,   -59,   -59,   -59,   -59,   -59,     0,
     -59,   -59,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,
     -58,   -58,   -58,   -58,   -58,     0,   -58,   -58,   -46,   -46,
     -46,   -46,   -46,   -46,     0,     0,   -46,   -46,   -46,   -46,
     -46,     0,   162,   -46,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,   -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,
     -55,   -55,   -55,   -55,   -55,   -55,     0,     0,   -55,   -55,
     -55,   -55,   -55,     0,   -55,   -55,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,   -56,   -56,   -56,   -56,   -56,     0,
     -56,   -56,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
     -57,   -57,   -57,   -57,   -57,     0,   -57,   -57,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,   -50,   -50,   -50,   -50,
     -50,     0,   -50,   -50,   -43,   -43,   -43,   -43,   -43,   -43,
       0,     0,   161,   -43,   -43,   -43,   -43,     0,     0,   -43,
     -47,   -47,   -47,   -47,   -47,   -47,     0,     0,   -47,   -47,
     -47,   -47,   -47,     0,     0,   -47,   -48,   -48,   -48,   -48,
     -48,   -48,     0,     0,   -48,   -48,   -48,   -48,   -48,     0,
       0,   -48,   -60,   -60,   -60,   -60,   -60,   -60,     0,     0,
       0,   -60,   -60,   -60,   -60,     0,   -60,   -60,   -59,   -59,
     -59,   -59,   -59,   -59,     0,     0,     0,   -59,   -59,   -59,
     -59,     0,   -59,   -59,   -58,   -58,   -58,   -58,   -58,   -58,
       0,     0,     0,   -58,   -58,   -58,   -58,     0,   -58,   -58,
     -46,   -46,   -46,   -46,   -46,   -46,     0,     0,     0,   -46,
     -46,   -46,   -46,     0,   238,   -46,   -49,   -49,   -49,   -49,
     -49,   -49,     0,     0,     0,   -49,   -49,   -49,   -49,     0,
     -49,   -49,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   -55,   -55,   -55,   -55,     0,   -55,   -55,   -56,   -56,
     -56,   -56,   -56,   -56,     0,     0,     0,   -56,   -56,   -56,
     -56,     0,   -56,   -56,   -57,   -57,   -57,   -57,   -57,   -57,
       0,     0,     0,   -57,   -57,   -57,   -57,     0,   -57,   -57,
     -50,   -50,   -50,   -50,   -50,   -50,     0,     0,     0,   -50,
     -50,   -50,   -50,     0,   -50,   -50,   -40,   -40,   -40,   -40,
     -40,   -40,     0,     0,     0,   -40,   -40,   159,   160,     0,
       0,   -40,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,
       0,   -43,   -43,   -43,   -43,     0,     0,   -43,   -41,   -41,
     -41,   -41,   -41,   -41,     0,     0,     0,   -41,   -41,   159,
     160,     0,     0,   -41,   -42,   -42,   -42,   -42,   -42,   -42,
       0,     0,     0,   -42,   -42,   159,   160,     0,     0,   -42,
     -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,
     -44,   -44,   -44,     0,     0,   -44,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,     0,   -45,   -45,   -45,   -45,     0,
       0,   -45,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,
       0,   -47,   -47,   -47,   -47,     0,     0,   -47,   -48,   -48,
     -48,   -48,   -48,   -48,     0,     0,     0,   -48,   -48,   -48,
     -48,     0,     0,   -48,   -37,   -37,   -37,   -37,   -37,   -37,
       0,     0,     0,   157,   158,     0,     0,     0,     0,   -37,
     -38,   -38,   -38,   -38,   -38,   -38,     0,     0,     0,   157,
     158,     0,     0,     0,     0,   -38,   -39,   -39,   -39,   -39,
     -39,   -39,     0,     0,     0,   157,   158,     0,     0,     0,
       0,   -39,   153,   154,   155,   156,   -32,   -32,   153,   154,
     155,   156,   -33,   -33,     0,     0,     0,   -32,     0,     0,
       0,     0,     0,   -33,   153,   154,   155,   156,   -34,   -34,
       0,     0,   -60,   -60,   -60,   -60,   -60,   -60,     0,   -34,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -59,   -59,   -59,
     -59,   -59,   -59,     0,     0,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -46,   -46,   -46,   -46,   -46,   -46,     0,     0,
     -46,   -46,   -46,   -46,   -46,   -46,    72,   -49,   -49,   -49,
     -49,   -49,   -49,     0,     0,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -56,   -56,   -56,
     -56,   -56,   -56,     0,     0,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -50,   -50,   -50,
     -50,   -50,   -50,     0,     0,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -60,   -60,   -60,
     -60,   -60,   -60,     0,     0,     0,   -60,   -60,   -60,   -60,
     -60,   -60,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,
       0,   -59,   -59,   -59,   -59,   -59,   -59,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,   -58,   -58,   -58,   -58,
     -58,   -58,   -46,   -46,   -46,   -46,   -46,   -46,     0,     0,
       0,   -46,   -46,   -46,   -46,   -46,   167,   -49,   -49,   -49,
     -49,   -49,   -49,     0,     0,     0,   -49,   -49,   -49,   -49,
     -49,   -49,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   -55,   -55,   -55,   -55,   -55,   -55,   -56,   -56,   -56,
     -56,   -56,   -56,     0,     0,     0,   -56,   -56,   -56,   -56,
     -56,   -56,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,   -57,   -57,   -57,   -57,   -57,   -57,   -50,   -50,   -50,
     -50,   -50,   -50,     0,     0,     0,   -50,   -50,   -50,   -50,
     -50,   -50,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,
      71,   -43,   -43,   -43,   -43,   -43,   -47,   -47,   -47,   -47,
     -47,   -47,     0,     0,   -47,   -47,   -47,   -47,   -47,   -47,
     -48,   -48,   -48,   -48,   -48,   -48,     0,     0,   -48,   -48,
     -48,   -48,   -48,   -48,   -40,   -40,   -40,   -40,   -40,   -40,
       0,     0,     0,   -40,   -40,    69,    70,   -40,   -43,   -43,
     -43,   -43,   -43,   -43,     0,     0,     0,   -43,   -43,   -43,
     -43,   -43,   -41,   -41,   -41,   -41,   -41,   -41,     0,     0,
       0,   -41,   -41,    69,    70,   -41,   -42,   -42,   -42,   -42,
     -42,   -42,     0,     0,     0,   -42,   -42,    69,    70,   -42,
     -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,
     -44,   -44,   -44,   -44,   -45,   -45,   -45,   -45,   -45,   -45,
       0,     0,     0,   -45,   -45,   -45,   -45,   -45,   -47,   -47,
     -47,   -47,   -47,   -47,     0,     0,     0,   -47,   -47,   -47,
     -47,   -47,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,
       0,   -48,   -48,   -48,   -48,   -48,   -35,   -35,   -35,   -35,
     -35,   -35,     0,     0,     0,    67,    68,     0,     0,   -35,
     -36,   -36,   -36,   -36,   -36,   -36,     0,     0,     0,    67,
      68,     0,     0,   -36,   -37,   -37,   -37,   -37,   -37,   -37,
       0,     0,     0,    67,    68,     0,     0,   -37,   -38,   -38,
     -38,   -38,   -38,   -38,     0,     0,     0,    67,    68,     0,
       0,   -38,   -39,   -39,   -39,   -39,   -39,   -39,     0,     0,
       0,    67,    68,     0,     0,   -39,    63,    64,    65,    66,
     -33,   -33,    63,    64,    65,    66,   -34,   -34,     0,   -33,
       0,     0,     0,     0,     0,   -34
};

static const yytype_int16 yycheck[] =
{
       1,     1,     5,    21,    27,    27,    24,     8,     1,    19,
      33,    33,    12,   162,    12,    38,    38,    18,   167,    12,
      20,     8,    23,    21,    33,    21,    27,    20,    12,    30,
      31,    32,    33,   182,    57,    57,    20,    38,    61,    62,
      19,    10,    11,    30,     3,     4,     5,    21,    71,    71,
      24,    12,    21,    12,    13,    24,    57,    16,    10,    11,
      21,    20,     0,    22,    23,    21,    21,     5,    24,    21,
      71,    72,    12,     6,     7,     8,     9,    10,    11,     0,
      19,    20,    15,    16,     5,   108,   108,    22,    21,   238,
      91,    24,    10,    11,    95,   244,     0,    22,     2,   108,
     101,    19,   125,   125,     0,   106,   107,   108,    95,     5,
       3,     4,   135,   135,   101,    21,   125,     0,    24,    12,
      13,    23,     5,    16,   125,     0,   135,    20,   151,   152,
       5,     0,   133,   134,   135,     0,     5,     0,   161,   161,
       5,    21,     5,    21,    24,    19,    24,    19,   171,   172,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,    21,    19,    21,    24,   167,    24,   191,   191,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   191,    19,    20,    19,    20,    27,   189,   190,
     191,    31,    32,    33,   217,   217,     3,     4,    38,    19,
      20,    23,    21,    19,    21,    12,    13,    21,   217,    16,
      21,    19,    21,    20,   215,   216,   217,    57,     6,     7,
       8,     9,    10,    11,    19,     3,     4,     5,    19,    69,
      70,    71,    72,    21,    12,    13,    24,   238,    16,     3,
       4,     5,    20,   244,    22,    23,    19,    21,    12,    13,
      21,    91,    16,    21,    21,    21,    20,    19,    22,    23,
       3,     4,     5,    21,    21,    21,   106,   107,   108,    12,
      13,    21,    21,    16,    21,    21,    21,    20,     2,    22,
      23,    21,    57,   123,   124,   125,    38,     6,     7,     8,
       9,    10,    11,   133,   134,   135,    15,    16,    53,    27,
      -1,    -1,    21,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,    -1,    57,
      -1,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    71,    72,     3,     4,     5,    -1,   189,
     190,   191,    -1,    -1,    12,    13,    -1,    -1,    16,    -1,
      -1,    -1,    20,    91,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,   215,   216,   217,   106,   107,
     108,    12,    13,    -1,    -1,    16,     3,     4,    -1,    20,
      -1,    22,    23,    -1,    -1,    12,    13,   125,   238,    16,
      -1,    -1,    -1,    20,   244,   133,   134,   135,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
      -1,    57,    -1,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    71,    72,     3,     4,     5,
      -1,   189,   190,   191,    -1,    -1,    12,    13,    -1,    -1,
      16,    -1,    -1,    -1,    20,    91,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,   215,   216,   217,
     106,   107,   108,    12,    13,    -1,    -1,    16,     3,     4,
      -1,    20,    -1,    22,    23,    -1,    -1,    12,    13,   125,
     238,    16,    -1,    -1,    -1,    20,   244,   133,   134,   135,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,    -1,    57,    -1,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,    71,    72,     3,
       4,     5,    -1,   189,   190,   191,    -1,    -1,    12,    13,
      -1,    -1,    16,    -1,    -1,    -1,    20,    91,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,   215,
     216,   217,   106,   107,   108,    12,    13,    -1,    -1,    16,
      -1,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,
      -1,   125,   238,     3,     4,     5,    -1,    -1,   244,   133,
     134,   135,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,
      20,    -1,    22,    23,    -1,    -1,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,    -1,    -1,    -1,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,     3,
       4,     5,    -1,    -1,    27,   189,   190,   191,    12,    13,
      33,    -1,    16,     3,     4,    38,    20,    -1,    22,    23,
      -1,    -1,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,
      20,   215,   216,   217,    57,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,    27,
     244,    27,    -1,    -1,    -1,    33,    -1,    33,    -1,    -1,
      38,    -1,    38,     3,     4,     6,     7,     8,     9,    10,
      11,    -1,    12,    13,    -1,   108,    16,    -1,    19,    57,
      20,    57,    -1,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,   125,    71,    -1,    71,    -1,     3,     4,     5,
      -1,    -1,   135,    -1,    -1,    -1,    12,    13,    -1,    -1,
      16,    -1,    -1,    -1,    20,    91,    22,    23,   151,   152,
     153,   154,   155,   156,   157,   158,    -1,    -1,   161,    -1,
     108,    -1,   108,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,   177,   178,    -1,   125,    21,   125,
      -1,     6,     7,     8,     9,    10,    11,   135,   191,   135,
      15,    16,    17,    18,    -1,    20,    21,    -1,    -1,    24,
      -1,    -1,    -1,   151,   152,   153,   154,   155,   156,    -1,
      -1,    -1,    -1,   161,   217,   161,     6,     7,     8,     9,
      10,    11,    -1,     3,     4,   173,   174,   175,   176,    -1,
      -1,    21,    12,    13,    24,   181,    16,    -1,    -1,    -1,
      20,    21,    -1,   191,    -1,   191,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,   217,
      -1,   217,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    20,    21,    -1,    -1,
      24,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    20,    21,    -1,    -1,    24,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    20,    21,    -1,    -1,    24,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    20,    21,    -1,    -1,    24,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    20,    21,    -1,    -1,    24,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      -1,    20,    21,    -1,    -1,    24,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      20,    21,    -1,    -1,    24,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    -1,    20,
      21,    -1,    -1,    24,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    -1,    24,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    24,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      24,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    20,    21,    -1,    -1,    24,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,    -1,    -1,    24,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    20,    21,    -1,    -1,    24,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    21,    -1,    -1,    24,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    20,    21,    -1,    -1,    24,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      20,    21,    -1,    -1,    24,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,
      21,    -1,    -1,    24,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,    21,
      -1,    -1,    24,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    24,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      24,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,    24,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    -1,    24,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    -1,    21,    -1,    -1,    24,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    24,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    21,    -1,    -1,    24,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      -1,    21,    -1,    -1,    24,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    24,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    24,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    24,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      24,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    24,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    20,    21,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      20,    21,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    20,    21,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    20,    21,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    20,    21,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    20,    21,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      20,    21,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    20,    21,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    20,    21,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,    21,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    21,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      -1,    21,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    21,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    21,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,    21,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      20,    21,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    21,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    21,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,    21,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      -1,    21,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    21,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    -1,    21,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    21,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      -1,    21,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    21,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    -1,    21,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    21,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,
      -1,    21,     6,     7,     8,     9,    10,    11,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    21,     6,     7,     8,     9,    10,    11,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    21,
      14,    15,    16,    17,    18,    19,    20,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    19,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,    19,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    -1,    -1,    19,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    -1,    -1,    19,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    -1,
      -1,    19,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    -1,    -1,    19,     6,     7,     8,     9,
      10,    11,     6,     7,     8,     9,    10,    11,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    26,    27,    28,    30,     1,    12,    20,    39,
      54,     0,    27,    19,    39,    20,    29,    21,    31,    19,
      40,    41,    54,    24,    21,    54,    32,    22,     3,     4,
       5,    13,    16,    20,    22,    28,    33,    35,    36,    37,
      38,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      53,    54,    55,    39,    49,    49,    43,    34,    23,    37,
      19,    10,    11,     6,     7,     8,     9,    15,    16,    17,
      18,    14,    20,    21,    35,    46,    49,    46,    47,    47,
      47,    47,    48,    48,    49,    49,    44,    44,    51,    52,
      23,    24,    21,    44,    12,    20,    54,    12,    12,     1,
      12,    20,    54,     3,     4,    12,    13,    16,    20,    44,
      45,    46,    47,    48,    49,    50,    53,    54,    55,    29,
       3,     4,    12,    13,    16,    20,    50,    53,    54,    55,
       3,     4,    12,    13,    16,    20,    45,    46,    47,    48,
      49,    50,    53,    54,    55,    39,    19,    39,    49,    49,
      43,    10,    11,     6,     7,     8,     9,    15,    16,    17,
      18,    14,    20,    19,    49,    49,    43,    20,    49,    49,
      43,    10,    11,     6,     7,     8,     9,    15,    16,    17,
      18,    14,    20,    21,    21,    21,     3,     4,    12,    13,
      16,    20,    46,    49,    50,    53,    54,    55,    46,    47,
      47,    47,    47,    48,    48,    49,    49,    44,    52,    21,
      52,    21,     3,     4,    12,    13,    16,    20,    46,    49,
      50,    53,    54,    55,    46,    47,    47,    47,    47,    48,
      48,    49,    49,    44,    52,    49,    49,    43,    20,    21,
      21,    49,    49,    43,    20,    21,    21,    52,    21,    52,
      21,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    26,    26,    27,    27,    29,    28,    28,    31,
      32,    30,    34,    33,    35,    35,    36,    36,    37,    37,
      38,    38,    39,    39,    40,    40,    41,    41,    42,    43,
      44,    44,    45,    45,    45,    46,    46,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    49,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    54,    55,
      55
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     4,     3,     0,
       0,    10,     0,     4,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     0,     1,     2,     1,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     2,     2,     1,
       4,     1,     3,     1,     0,     1,     1,     3,     1,     1,
       1
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
  YY_USE (yykind);
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
#line 53 "src/bison/math.y"
                                { list_push(&root->children, (yyvsp[0].ast)); }
#line 1755 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 54 "src/bison/math.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 1761 "src/bison/grammar.c"
    break;

  case 6: /* $@1: %empty  */
#line 61 "src/bison/math.y"
                            {
        Symbol *sym = symbol_table_insert(current_scope->symbol_table, (yyvsp[0].ast));
        if (!sym) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("redeclaration of '%s'\n", error_cursor, (yyvsp[0].ast)->value.symref->symbol->name);
        }
    }
#line 1773 "src/bison/grammar.c"
    break;

  case 7: /* declaration: LET declarator $@1 ';'  */
#line 67 "src/bison/math.y"
          {
        // the best we can do is show the error, but still push to AST
        (yyval.ast) = ast_declaration_init((yyvsp[-2].ast));
    }
#line 1782 "src/bison/grammar.c"
    break;

  case 8: /* declaration: LET error ';'  */
#line 71 "src/bison/math.y"
                    {
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 1792 "src/bison/grammar.c"
    break;

  case 9: /* @2: %empty  */
#line 78 "src/bison/math.y"
                                     {
        if (current_scope->index) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("CIPL forbids nested functions\n", error_cursor);
            (yyval.ast) = NULL;
            yyerrok;
        }
        symbol_table_insert(current_scope->symbol_table, (yyvsp[-1].ast));
        previous_scope = current_scope;
        current_scope = scope_add(previous_scope);
    }
#line 1808 "src/bison/grammar.c"
    break;

  case 10: /* $@3: %empty  */
#line 88 "src/bison/math.y"
                      {
        LIST_FOR_EACH((yyvsp[-1].list), {
            symbol_table_insert(current_scope->symbol_table, __MAP_IT__->data);
        });
    }
#line 1818 "src/bison/grammar.c"
    break;

  case 11: /* func_declaration: LET declarator '(' @2 id_list.opt ')' $@3 '{' block_item_list.opt '}'  */
#line 92 "src/bison/math.y"
                                  {
        // printf("found a function\n");
        (yyval.ast) = ast_userfunc_init(current_scope, (yyvsp[-8].ast), ast_params_init((yyvsp[-5].list)), ast_blockitems_init((yyvsp[-1].list)));
        current_scope = previous_scope;
    }
#line 1828 "src/bison/grammar.c"
    break;

  case 12: /* $@4: %empty  */
#line 105 "src/bison/math.y"
                   {
        // printf("found a code block on line:%d\n", cursor.line);
        previous_scope = current_scope;
        current_scope = scope_add(previous_scope);
        // printf("starting scope: %d\n", current_scope->index);
    }
#line 1839 "src/bison/grammar.c"
    break;

  case 13: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 110 "src/bison/math.y"
                              {
        // printf("leaving scope: %d on line:%d\n", current_scope->index, cursor.line);
        current_scope = previous_scope;
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
    }
#line 1849 "src/bison/grammar.c"
    break;

  case 14: /* block_item_list.opt: block_item_list  */
#line 117 "src/bison/math.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 1855 "src/bison/grammar.c"
    break;

  case 15: /* block_item_list.opt: %empty  */
#line 118 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 1861 "src/bison/grammar.c"
    break;

  case 16: /* block_item_list: block_item_list block_item  */
#line 121 "src/bison/math.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 1867 "src/bison/grammar.c"
    break;

  case 17: /* block_item_list: block_item  */
#line 122 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 1873 "src/bison/grammar.c"
    break;

  case 23: /* declarator: '(' declarator ')'  */
#line 134 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 1879 "src/bison/grammar.c"
    break;

  case 24: /* id_list: id_list ',' id  */
#line 137 "src/bison/math.y"
                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 1885 "src/bison/grammar.c"
    break;

  case 25: /* id_list: id  */
#line 138 "src/bison/math.y"
         { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 1891 "src/bison/grammar.c"
    break;

  case 26: /* id_list.opt: %empty  */
#line 141 "src/bison/math.y"
                    { (yyval.list) = NULL; }
#line 1897 "src/bison/grammar.c"
    break;

  case 28: /* expr_stmt: expression ';'  */
#line 145 "src/bison/math.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 1903 "src/bison/grammar.c"
    break;

  case 31: /* assign_expr: cast_expr '=' assign_expr  */
#line 152 "src/bison/math.y"
                                {
        // printf("found an assignment\n");
        (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1912 "src/bison/grammar.c"
    break;

  case 33: /* eq_expr: eq_expr EQ rel_expr  */
#line 159 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("==", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1918 "src/bison/grammar.c"
    break;

  case 34: /* eq_expr: eq_expr NE rel_expr  */
#line 160 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("!=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1924 "src/bison/grammar.c"
    break;

  case 36: /* rel_expr: rel_expr LT add_expr  */
#line 164 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1930 "src/bison/grammar.c"
    break;

  case 37: /* rel_expr: rel_expr LE add_expr  */
#line 165 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1936 "src/bison/grammar.c"
    break;

  case 38: /* rel_expr: rel_expr GT add_expr  */
#line 166 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1942 "src/bison/grammar.c"
    break;

  case 39: /* rel_expr: rel_expr GE add_expr  */
#line 167 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1948 "src/bison/grammar.c"
    break;

  case 41: /* add_expr: add_expr '+' mult_expr  */
#line 171 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('+', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1954 "src/bison/grammar.c"
    break;

  case 42: /* add_expr: add_expr '-' mult_expr  */
#line 172 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('-', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1960 "src/bison/grammar.c"
    break;

  case 44: /* mult_expr: mult_expr '*' cast_expr  */
#line 176 "src/bison/math.y"
                              { (yyval.ast) = ast_binop_init('*', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1966 "src/bison/grammar.c"
    break;

  case 45: /* mult_expr: mult_expr '/' cast_expr  */
#line 177 "src/bison/math.y"
                              { (yyval.ast) = ast_binop_init('/', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1972 "src/bison/grammar.c"
    break;

  case 47: /* cast_expr: '!' cast_expr  */
#line 181 "src/bison/math.y"
                    { (yyval.ast) = ast_uniop_init('!', (yyvsp[0].ast)); }
#line 1978 "src/bison/grammar.c"
    break;

  case 48: /* cast_expr: '-' cast_expr  */
#line 182 "src/bison/math.y"
                    { (yyval.ast) = ast_uniop_init('-', (yyvsp[0].ast)); }
#line 1984 "src/bison/grammar.c"
    break;

  case 54: /* arg_expr_list.opt: %empty  */
#line 194 "src/bison/math.y"
             { (yyval.ast) = NULL; }
#line 1990 "src/bison/grammar.c"
    break;

  case 55: /* primary_expr: id  */
#line 197 "src/bison/math.y"
                 {
        Symbol *sym = (yyvsp[0].ast)->value.symref->symbol;
        Symbol *definedSym = scope_lookup(sym->name);
        if (!definedSym) {
            yyerror(NULL);
            CIPL_PERROR("'%s' undeclared (first use in this function)\n", sym->name);
        }
        (yyvsp[0].ast)->value.symref->symbol = symbol_init_copy(definedSym ? definedSym : sym);
        symbol_free(sym);
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2006 "src/bison/grammar.c"
    break;

  case 57: /* primary_expr: '(' expression ')'  */
#line 209 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2012 "src/bison/grammar.c"
    break;

  case 58: /* id: NAME  */
#line 212 "src/bison/math.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 2018 "src/bison/grammar.c"
    break;

  case 59: /* constant: NUMBER_REAL  */
#line 215 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 2024 "src/bison/grammar.c"
    break;

  case 60: /* constant: NUMBER_INT  */
#line 216 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 2030 "src/bison/grammar.c"
    break;


#line 2034 "src/bison/grammar.c"

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
      yyerror (YY_("syntax error"));
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


#if !defined yyoverflow
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

  return yyresult;
}

#line 219 "src/bison/math.y"


void yyerror(char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    /* CIPL_PERROR_CURSOR("%s\n", error_cursor, s); */
}
