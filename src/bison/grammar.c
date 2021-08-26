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
    #include <string.h>
	#include <stdio.h>

    #include "data-structures/ast/ast.h"
    #include "data-structures/stack.h"
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"

    AST *root;
    Scope *current_scope;
    Scope *previous_scope;
    int reading_args = 0;
    cursor_position error_cursor;
    StackNode *scopes;

#line 90 "src/bison/grammar.c"

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
  YYSYMBOL_func_declaration = 29,          /* func_declaration  */
  YYSYMBOL_30_1 = 30,                      /* $@1  */
  YYSYMBOL_compound_stmt = 31,             /* compound_stmt  */
  YYSYMBOL_32_2 = 32,                      /* $@2  */
  YYSYMBOL_33_block_item_list_opt = 33,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 34,           /* block_item_list  */
  YYSYMBOL_block_item = 35,                /* block_item  */
  YYSYMBOL_statement = 36,                 /* statement  */
  YYSYMBOL_declarator = 37,                /* declarator  */
  YYSYMBOL_id_list = 38,                   /* id_list  */
  YYSYMBOL_39_id_list_opt = 39,            /* id_list.opt  */
  YYSYMBOL_expr_stmt = 40,                 /* expr_stmt  */
  YYSYMBOL_expression = 41,                /* expression  */
  YYSYMBOL_assign_expr = 42,               /* assign_expr  */
  YYSYMBOL_eq_expr = 43,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 44,                  /* rel_expr  */
  YYSYMBOL_add_expr = 45,                  /* add_expr  */
  YYSYMBOL_mult_expr = 46,                 /* mult_expr  */
  YYSYMBOL_cast_expr = 47,                 /* cast_expr  */
  YYSYMBOL_postfix_expr = 48,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 49,             /* arg_expr_list  */
  YYSYMBOL_50_arg_expr_list_opt = 50,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 51,              /* primary_expr  */
  YYSYMBOL_id = 52,                        /* id  */
  YYSYMBOL_constant = 53                   /* constant  */
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
#define YYLAST   2659

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
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
       0,    51,    51,    52,    55,    56,    59,    65,    72,    72,
      80,    88,    88,   100,   101,   104,   105,   108,   109,   112,
     113,   116,   117,   120,   121,   124,   125,   128,   131,   134,
     135,   141,   142,   143,   146,   147,   148,   149,   150,   153,
     154,   155,   158,   159,   160,   163,   164,   165,   168,   169,
     172,   173,   176,   177,   180,   181,   182,   185,   192,   193
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
  "','", "$accept", "prog", "external_declaration", "declaration",
  "func_declaration", "$@1", "compound_stmt", "$@2", "block_item_list.opt",
  "block_item_list", "block_item", "statement", "declarator", "id_list",
  "id_list.opt", "expr_stmt", "expression", "assign_expr", "eq_expr",
  "rel_expr", "add_expr", "mult_expr", "cast_expr", "postfix_expr",
  "arg_expr_list", "arg_expr_list.opt", "primary_expr", "id", "constant", YY_NULLPTR
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

#define YYPACT_NINF (-159)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    11,    46,    55,    94,    98,    65,    95,    -9,   105,
     130,  -159,   104,   108,    25,    -3,   117,   -11,  2126,  2141,
      13,   205,   205,   709,    49,    54,   107,     9,   226,   248,
     269,   352,    15,    17,    71,  2620,  2550,  2438,  2396,  2156,
    2171,  2186,  2201,   193,    14,    23,    37,  2410,  2424,    47,
      25,   128,   387,   471,  1513,  1513,  1513,  1513,  1513,  1513,
    1513,  1513,  1513,  1513,   205,   183,   119,    52,   123,  2216,
      60,  2626,  2452,  2640,  2564,  2578,  2592,  2606,  2466,  2480,
    2494,  2508,    56,   124,   143,    74,    89,    96,   506,  1518,
    2231,   173,    25,   181,    93,   137,   142,    -9,   144,  2246,
     120,    -9,   150,  1552,  1568,  1584,   709,   709,   709,   162,
      29,  2096,  2016,  1888,  1696,  1600,  1616,  1632,  1648,   198,
     590,   625,  2261,  2276,  2291,  1513,  1513,   709,  2306,  2321,
    2336,  2351,   776,   970,   989,  1518,  1518,   709,    68,   861,
     724,  1313,   944,  1009,  1028,  1047,  1066,   179,   180,  1712,
    1728,   185,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,   709,   183,  2522,  2536,   202,   183,  1123,  1142,
     207,  1537,  1537,  1537,  1537,  1537,  1537,  1537,  1537,  1537,
    1537,  1518,   183,   215,   221,  1664,  1744,  1760,  1776,  1532,
    1532,   709,  2102,  1904,  1792,  1808,  1824,  1840,  2118,  2032,
    2048,  2064,  2080,  1920,  1936,  1952,  1968,   220,   223,  2366,
     229,  1085,   650,  1161,  1180,  1537,  1537,   709,   891,  1332,
    1199,  1218,  1237,  1256,   923,   821,  1465,  1484,  1503,  1351,
    1370,  1389,  1408,   203,   233,  1984,  2000,   235,   183,  1680,
    2381,  1427,  1446,   236,   183,  1104,  1856,   237,  1275,   242,
    1872,  1294
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
    -159,  -159,   136,     6,  -159,  -159,  -159,  -159,   -48,  -159,
     219,  -159,    -4,  -159,  -159,  -159,    -6,   118,   749,   811,
     752,   696,   170,   289,  -159,  -158,   408,    -1,   527
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    25,     5,    44,    26,    50,    27,    28,
      29,    30,     9,    66,    67,    31,    32,    83,   138,   139,
     140,   141,    72,   128,    84,    85,   129,   130,   131
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    -8,    70,    96,    15,   208,     4,    98,     4,   210,
      -8,    97,     6,    41,    45,     1,    46,    49,    43,   102,
      41,    41,   117,     7,   234,   100,   119,    41,    18,    19,
      20,     8,    51,   101,    53,   -25,   -28,    99,    21,   152,
     153,    22,   120,    68,    94,    23,    11,    24,   -14,    41,
     -29,     1,   -11,   -11,   -11,    -3,   121,   -17,   -17,   -17,
      -3,   -11,   -11,    41,   145,   -11,   -17,   -17,    69,   -11,
     -17,   -11,   -11,    87,   -17,   -30,   -17,   -17,   171,   172,
     247,    54,    55,    88,    13,    91,   249,    14,   145,   -29,
     -29,    41,   -29,   147,    -5,    90,    98,   148,    -4,    -5,
      98,   119,   151,    -4,    -2,   117,   117,   117,    -7,    -2,
     -20,   -20,   -20,    -7,   -57,   -57,    95,    -6,    92,   -20,
     -20,   166,    -6,   -20,    16,    17,   117,   -20,   -10,   -20,
     -20,   170,    33,   -10,   145,   145,   117,    -9,    12,   -57,
     -26,   109,    -9,    86,   -24,   -50,    33,   -24,   -50,   -21,
     -21,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   117,   145,   -57,   -52,   -21,   145,    89,    33,   -21,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     145,   145,    82,   -28,    38,   237,   132,   133,   196,   196,
     117,    47,    48,   114,   -23,   134,   135,   -23,    38,   136,
     183,   184,   -51,   137,   -53,   -51,   185,    93,    18,    19,
      33,   243,   -22,   -22,   222,   222,   117,    99,    21,   -57,
      38,    22,   -57,   209,   -30,    23,   109,   -30,   211,    18,
      19,    20,    80,    81,    38,   142,   -22,   145,    99,    21,
     -22,   -30,    22,   145,   239,   109,    23,    52,    24,   -13,
     240,   -16,   -16,   -16,   245,   109,   246,   248,   250,   142,
     -16,   -16,    38,   251,   -16,     0,     0,     0,   -16,     0,
     -16,   -16,   -18,   -18,   -18,     0,   149,   150,   114,     0,
     207,   -18,   -18,     0,     0,   -18,     0,     0,     0,   -18,
       0,   -18,   -18,     0,     0,   164,   165,   114,     0,   233,
       0,     0,     0,    39,     0,   168,   169,   114,     0,   109,
      39,    39,   115,     0,     0,     0,     0,    39,     0,     0,
       0,     0,   193,   193,   193,   193,   193,   193,   193,   193,
     205,   206,   114,   142,     0,   109,     0,   142,     0,    39,
       0,   219,   219,   219,   219,   219,   219,   219,   219,   231,
     232,   142,   142,    39,   143,   -19,   -19,   -19,     0,   235,
     236,   114,     0,     0,   -19,   -19,     0,     0,   -19,     0,
       0,     0,   -19,     0,   -19,   -19,     0,     0,   143,     0,
       0,    39,     0,     0,     0,   241,   242,   114,     0,     0,
     -15,   -15,   -15,     0,     0,   115,   115,   115,     0,   -15,
     -15,     0,     0,   -15,     0,     0,     0,   -15,   142,   -15,
     -15,     0,     0,     0,   142,     0,   115,     0,     0,     0,
       0,     0,    40,     0,   143,   143,   115,     0,     0,    40,
      40,   116,     0,     0,     0,     0,    40,     0,     0,     0,
       0,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   115,   143,     0,     0,     0,   143,     0,    40,     0,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     143,   143,    40,   144,   -27,   -27,   -27,     0,   194,   194,
     115,     0,     0,   -27,   -27,     0,     0,   -27,     0,     0,
       0,   -27,     0,   -27,   -27,     0,     0,   144,     0,     0,
      40,     0,     0,     0,   220,   220,   115,     0,     0,   -12,
     -12,   -12,     0,     0,   116,   116,   116,     0,   -12,   -12,
       0,     0,   -12,     0,     0,     0,   -12,   143,   -12,   -12,
       0,     0,     0,   143,     0,   116,     0,     0,     0,     0,
       0,    42,     0,   144,   144,   116,     0,     0,    42,    42,
     118,     0,     0,     0,     0,    42,     0,     0,     0,     0,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     116,   144,     0,     0,     0,   144,     0,    42,     0,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   144,
     144,    42,   146,    -7,    -7,    -7,     0,   195,   195,   116,
       0,     0,    -7,    -7,     0,     0,    -7,     0,     0,     0,
      -7,     0,    -7,    -7,     0,     0,   146,     0,     0,    42,
       0,     0,     0,   221,   221,   116,     0,     0,    -6,    -6,
      -6,     0,     0,   118,   118,   118,     0,    -6,    -6,     0,
       0,    -6,     0,     0,     0,    -6,   144,    -6,    -6,     0,
       0,     0,   144,     0,   118,     0,   -59,   -59,   -59,   -59,
     -59,   -59,   146,   146,   118,   -59,   -59,   -59,   -59,     0,
     -59,   -59,     0,     0,   -59,     0,     0,     0,     0,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   118,
     146,     0,     0,     0,   146,     0,     0,     0,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   146,   146,
      37,     0,   103,   104,     0,     0,   197,   197,   118,   113,
       0,   105,   106,     0,    37,   107,     0,     0,     0,   108,
     -34,   -34,   -34,   -34,   -34,   -34,     0,     0,     0,   177,
     178,     0,   223,   223,   118,   -34,    37,     0,   -34,     0,
      37,    37,    37,    37,    37,    37,    78,    79,     0,     0,
      37,     0,     0,    34,     0,   146,    36,     0,     0,     0,
       0,   146,   110,     0,     0,   112,     0,    34,     0,     0,
      36,     0,   -59,   -59,   -59,   -59,   -59,   -59,    37,     0,
     -59,   -59,   -59,   -59,   -59,     0,   -59,   -59,     0,    34,
     -59,     0,    36,     0,   113,     0,    36,    36,    74,    75,
      76,    77,     0,    34,     0,     0,    36,     0,     0,     0,
       0,     0,     0,   113,     0,    35,     0,   -35,   -35,   -35,
     -35,   -35,   -35,   113,   111,     0,   177,   178,     0,    35,
       0,    34,   -35,     0,    36,   -35,     0,     0,   113,   113,
     113,   113,   113,   113,   203,   204,     0,   110,   113,     0,
     112,    35,     0,     0,     0,    71,    73,   173,   174,   175,
     176,   -31,   -31,   229,   230,    35,   110,     0,     0,   112,
       0,     0,   -31,     0,     0,   -31,   110,   113,     0,   112,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   -32,   -32,    35,   112,   112,   199,   200,   201,   202,
       0,   110,   -32,   113,   112,   -32,     0,     0,     0,   111,
       0,     0,     0,     0,     0,   225,   226,   227,   228,   173,
     174,   175,   176,   -33,   -33,     0,     0,     0,   111,     0,
     110,     0,     0,   112,   -33,     0,     0,   -33,   111,     0,
     -42,   -42,   -42,   -42,   -42,   -42,     0,     0,   181,   -42,
     -42,   -42,   -42,   192,   198,   -42,   110,     0,   -42,   112,
       0,     0,     0,   111,     0,     0,   -58,   -58,   -58,   -58,
     -58,   -58,   218,   224,   -58,   -58,   -58,   -58,   -58,     0,
     -58,   -58,     0,     0,   -58,   -57,   -57,   -57,   -57,   -57,
     -57,     0,   111,   -57,   -57,   -57,   -57,   -57,     0,   -57,
     -57,     0,     0,   -57,     0,   -45,   -45,   -45,   -45,   -45,
     -45,     0,     0,   -45,   -45,   -45,   -45,   -45,   111,   182,
     -45,     0,     0,   -45,   -48,   -48,   -48,   -48,   -48,   -48,
       0,     0,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,
       0,     0,   -48,   -54,   -54,   -54,   -54,   -54,   -54,     0,
       0,   -54,   -54,   -54,   -54,   -54,     0,   -54,   -54,     0,
       0,   -54,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
     -55,   -55,   -55,   -55,   -55,     0,   -55,   -55,     0,     0,
     -55,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,   -56,
     -56,   -56,   -56,   -56,     0,   -56,   -56,     0,     0,   -56,
     -49,   -49,   -49,   -49,   -49,   -49,     0,     0,   -49,   -49,
     -49,   -49,   -49,     0,   -49,   -49,     0,     0,   -49,   -46,
     -46,   -46,   -46,   -46,   -46,     0,     0,   -46,   -46,   -46,
     -46,   -46,     0,     0,   -46,     0,     0,   -46,   -47,   -47,
     -47,   -47,   -47,   -47,     0,     0,   -47,   -47,   -47,   -47,
     -47,     0,     0,   -47,     0,     0,   -47,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,   -58,   -58,   -58,   -58,
       0,   -58,   -58,     0,     0,   -58,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,   -57,   -57,   -57,   -57,     0,
     -57,   -57,     0,     0,   -57,   -45,   -45,   -45,   -45,   -45,
     -45,     0,     0,     0,   -45,   -45,   -45,   -45,     0,   244,
     -45,     0,     0,   -45,   -48,   -48,   -48,   -48,   -48,   -48,
       0,     0,     0,   -48,   -48,   -48,   -48,     0,   -48,   -48,
       0,     0,   -48,   -54,   -54,   -54,   -54,   -54,   -54,     0,
       0,     0,   -54,   -54,   -54,   -54,     0,   -54,   -54,     0,
       0,   -54,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   -55,   -55,   -55,   -55,     0,   -55,   -55,     0,     0,
     -55,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,
     -56,   -56,   -56,   -56,     0,   -56,   -56,     0,     0,   -56,
     -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,   -49,
     -49,   -49,   -49,     0,   -49,   -49,     0,     0,   -49,   -39,
     -39,   -39,   -39,   -39,   -39,     0,     0,     0,   -39,   -39,
     179,   180,     0,     0,   -39,     0,     0,   -39,   -42,   -42,
     -42,   -42,   -42,   -42,     0,     0,     0,   -42,   -42,   -42,
     -42,     0,     0,   -42,     0,     0,   -42,   -40,   -40,   -40,
     -40,   -40,   -40,     0,     0,     0,   -40,   -40,   179,   180,
       0,     0,   -40,     0,     0,   -40,   -41,   -41,   -41,   -41,
     -41,   -41,     0,     0,     0,   -41,   -41,   179,   180,     0,
       0,   -41,     0,     0,   -41,   -43,   -43,   -43,   -43,   -43,
     -43,     0,     0,     0,   -43,   -43,   -43,   -43,     0,     0,
     -43,     0,     0,   -43,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,     0,   -44,   -44,   -44,   -44,     0,     0,   -44,
       0,     0,   -44,   -46,   -46,   -46,   -46,   -46,   -46,     0,
       0,     0,   -46,   -46,   -46,   -46,     0,     0,   -46,     0,
       0,   -46,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,
       0,   -47,   -47,   -47,   -47,     0,     0,   -47,     0,     0,
     -47,   -36,   -36,   -36,   -36,   -36,   -36,     0,     0,     0,
     177,   178,     0,     0,     0,     0,   -36,     0,     0,   -36,
     -37,   -37,   -37,   -37,   -37,   -37,     0,     0,     0,   177,
     178,     0,     0,     0,     0,   -37,     0,     0,   -37,   -38,
     -38,   -38,   -38,   -38,   -38,     0,   122,   123,   177,   178,
       0,   132,   133,     0,   -38,   124,   125,   -38,     0,   126,
     134,   135,     0,   127,   136,   186,   187,     0,   137,     0,
     212,   213,     0,     0,   188,   189,     0,     0,   190,   214,
     215,     0,   191,   216,     0,     0,     0,   217,   -59,   -59,
     -59,   -59,   -59,   -59,     0,     0,   -59,   -59,   -59,   -59,
     -59,     0,   -59,   -59,   -58,   -58,   -58,   -58,   -58,   -58,
       0,     0,   -58,   -58,   -58,   -58,   -58,     0,   -58,   -58,
     -57,   -57,   -57,   -57,   -57,   -57,     0,     0,   -57,   -57,
     -57,   -57,   -57,     0,   -57,   -57,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,   -45,   -45,   -45,   -45,   -45,     0,
     163,   -45,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,
     -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,   -54,   -54,
     -54,   -54,   -54,   -54,     0,     0,   -54,   -54,   -54,   -54,
     -54,     0,   -54,   -54,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,   -55,   -55,   -55,   -55,   -55,     0,   -55,   -55,
     -56,   -56,   -56,   -56,   -56,   -56,     0,     0,   -56,   -56,
     -56,   -56,   -56,     0,   -56,   -56,   -49,   -49,   -49,   -49,
     -49,   -49,     0,     0,   -49,   -49,   -49,   -49,   -49,     0,
     -49,   -49,   -42,   -42,   -42,   -42,   -42,   -42,     0,     0,
     162,   -42,   -42,   -42,   -42,     0,     0,   -42,   -46,   -46,
     -46,   -46,   -46,   -46,     0,     0,   -46,   -46,   -46,   -46,
     -46,     0,     0,   -46,   -47,   -47,   -47,   -47,   -47,   -47,
       0,     0,   -47,   -47,   -47,   -47,   -47,     0,     0,   -47,
     -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,   -59,
     -59,   -59,   -59,     0,   -59,   -59,   -58,   -58,   -58,   -58,
     -58,   -58,     0,     0,     0,   -58,   -58,   -58,   -58,     0,
     -58,   -58,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,   -57,   -57,   -57,   -57,     0,   -57,   -57,   -45,   -45,
     -45,   -45,   -45,   -45,     0,     0,     0,   -45,   -45,   -45,
     -45,     0,   238,   -45,   -48,   -48,   -48,   -48,   -48,   -48,
       0,     0,     0,   -48,   -48,   -48,   -48,     0,   -48,   -48,
     -54,   -54,   -54,   -54,   -54,   -54,     0,     0,     0,   -54,
     -54,   -54,   -54,     0,   -54,   -54,   -55,   -55,   -55,   -55,
     -55,   -55,     0,     0,     0,   -55,   -55,   -55,   -55,     0,
     -55,   -55,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
       0,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -49,   -49,
     -49,   -49,   -49,   -49,     0,     0,     0,   -49,   -49,   -49,
     -49,     0,   -49,   -49,   -39,   -39,   -39,   -39,   -39,   -39,
       0,     0,     0,   -39,   -39,   160,   161,     0,     0,   -39,
     -42,   -42,   -42,   -42,   -42,   -42,     0,     0,     0,   -42,
     -42,   -42,   -42,     0,     0,   -42,   -40,   -40,   -40,   -40,
     -40,   -40,     0,     0,     0,   -40,   -40,   160,   161,     0,
       0,   -40,   -41,   -41,   -41,   -41,   -41,   -41,     0,     0,
       0,   -41,   -41,   160,   161,     0,     0,   -41,   -43,   -43,
     -43,   -43,   -43,   -43,     0,     0,     0,   -43,   -43,   -43,
     -43,     0,     0,   -43,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,     0,   -44,   -44,   -44,   -44,     0,     0,   -44,
     -46,   -46,   -46,   -46,   -46,   -46,     0,     0,     0,   -46,
     -46,   -46,   -46,     0,     0,   -46,   -47,   -47,   -47,   -47,
     -47,   -47,     0,     0,     0,   -47,   -47,   -47,   -47,     0,
       0,   -47,   -34,   -34,   -34,   -34,   -34,   -34,     0,     0,
       0,   158,   159,     0,     0,     0,     0,   -34,   -35,   -35,
     -35,   -35,   -35,   -35,     0,     0,     0,   158,   159,     0,
       0,     0,     0,   -35,   -36,   -36,   -36,   -36,   -36,   -36,
       0,     0,     0,   158,   159,     0,     0,     0,     0,   -36,
     -37,   -37,   -37,   -37,   -37,   -37,     0,     0,     0,   158,
     159,     0,     0,     0,     0,   -37,   -38,   -38,   -38,   -38,
     -38,   -38,     0,     0,     0,   158,   159,     0,     0,     0,
       0,   -38,   154,   155,   156,   157,   -31,   -31,   154,   155,
     156,   157,   -32,   -32,     0,     0,     0,   -31,     0,     0,
       0,     0,     0,   -32,   154,   155,   156,   157,   -33,   -33,
       0,     0,   -59,   -59,   -59,   -59,   -59,   -59,     0,   -33,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
     -45,   -45,   -45,   -45,   -45,   -45,    65,   -48,   -48,   -48,
     -48,   -48,   -48,     0,     0,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -55,   -55,   -55,
     -55,   -55,   -55,     0,     0,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -49,   -49,   -49,
     -49,   -49,   -49,     0,     0,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -59,   -59,   -59,
     -59,   -59,   -59,     0,     0,     0,   -59,   -59,   -59,   -59,
     -59,   -59,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,
       0,   -58,   -58,   -58,   -58,   -58,   -58,   -57,   -57,   -57,
     -57,   -57,   -57,     0,     0,     0,   -57,   -57,   -57,   -57,
     -57,   -57,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
       0,   -45,   -45,   -45,   -45,   -45,   167,   -48,   -48,   -48,
     -48,   -48,   -48,     0,     0,     0,   -48,   -48,   -48,   -48,
     -48,   -48,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
       0,   -54,   -54,   -54,   -54,   -54,   -54,   -55,   -55,   -55,
     -55,   -55,   -55,     0,     0,     0,   -55,   -55,   -55,   -55,
     -55,   -55,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
       0,   -56,   -56,   -56,   -56,   -56,   -56,   -49,   -49,   -49,
     -49,   -49,   -49,     0,     0,     0,   -49,   -49,   -49,   -49,
     -49,   -49,   -42,   -42,   -42,   -42,   -42,   -42,     0,     0,
      64,   -42,   -42,   -42,   -42,   -42,   -46,   -46,   -46,   -46,
     -46,   -46,     0,     0,   -46,   -46,   -46,   -46,   -46,   -46,
     -47,   -47,   -47,   -47,   -47,   -47,     0,     0,   -47,   -47,
     -47,   -47,   -47,   -47,   -39,   -39,   -39,   -39,   -39,   -39,
       0,     0,     0,   -39,   -39,    62,    63,   -39,   -42,   -42,
     -42,   -42,   -42,   -42,     0,     0,     0,   -42,   -42,   -42,
     -42,   -42,   -40,   -40,   -40,   -40,   -40,   -40,     0,     0,
       0,   -40,   -40,    62,    63,   -40,   -41,   -41,   -41,   -41,
     -41,   -41,     0,     0,     0,   -41,   -41,    62,    63,   -41,
     -43,   -43,   -43,   -43,   -43,   -43,     0,     0,     0,   -43,
     -43,   -43,   -43,   -43,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,     0,   -44,   -44,   -44,   -44,   -44,   -46,   -46,
     -46,   -46,   -46,   -46,     0,     0,     0,   -46,   -46,   -46,
     -46,   -46,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,
       0,   -47,   -47,   -47,   -47,   -47,   -34,   -34,   -34,   -34,
     -34,   -34,     0,     0,     0,    60,    61,     0,     0,   -34,
     -35,   -35,   -35,   -35,   -35,   -35,     0,     0,     0,    60,
      61,     0,     0,   -35,   -36,   -36,   -36,   -36,   -36,   -36,
       0,     0,     0,    60,    61,     0,     0,   -36,   -37,   -37,
     -37,   -37,   -37,   -37,     0,     0,     0,    60,    61,     0,
       0,   -37,   -38,   -38,   -38,   -38,   -38,   -38,     0,     0,
       0,    60,    61,     0,     0,   -38,    56,    57,    58,    59,
     -31,   -31,    56,    57,    58,    59,   -32,   -32,     0,   -31,
       0,     0,     0,     0,     0,   -32,    56,    57,    58,    59,
     -33,   -33,     0,     0,     0,     0,     0,     0,     0,   -33
};

static const yytype_int16 yycheck[] =
{
       1,    12,    50,    12,     8,   163,     0,     8,     2,   167,
      21,    20,     1,    14,     1,     5,    20,    23,    21,    20,
      21,    22,    23,    12,   182,    12,    12,    28,     3,     4,
       5,    20,    23,    20,    19,    21,    19,    12,    13,    10,
      11,    16,    19,    44,    92,    20,     0,    22,    23,    50,
      21,     5,     3,     4,     5,     0,    19,     3,     4,     5,
       5,    12,    13,    64,    65,    16,    12,    13,    21,    20,
      16,    22,    23,    21,    20,    19,    22,    23,    10,    11,
     238,    10,    11,    23,    19,    86,   244,    22,    89,    21,
      19,    92,    24,    97,     0,    21,    97,   101,     0,     5,
     101,    12,   108,     5,     0,   106,   107,   108,     0,     5,
       3,     4,     5,     5,    19,    20,    23,     0,    22,    12,
      13,   127,     5,    16,    19,    20,   127,    20,     0,    22,
      23,   137,    14,     5,   135,   136,   137,     0,     2,    19,
      21,    23,     5,    24,    21,    21,    28,    24,    24,    19,
      20,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    21,    21,    21,   167,    24,    50,    19,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    64,    21,    14,   191,     3,     4,   189,   190,
     191,    21,    22,    23,    21,    12,    13,    24,    28,    16,
      21,    21,    21,    20,    21,    24,    21,    89,     3,     4,
      92,   217,    19,    20,   215,   216,   217,    12,    13,    21,
      50,    16,    24,    21,    21,    20,   108,    24,    21,     3,
       4,     5,    62,    63,    64,    65,    21,   238,    12,    13,
      19,    21,    16,   244,    21,   127,    20,    28,    22,    23,
      21,     3,     4,     5,    21,   137,    21,    21,    21,    89,
      12,    13,    92,    21,    16,    -1,    -1,    -1,    20,    -1,
      22,    23,     3,     4,     5,    -1,   106,   107,   108,    -1,
     162,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,    20,
      -1,    22,    23,    -1,    -1,   125,   126,   127,    -1,   181,
      -1,    -1,    -1,    14,    -1,   135,   136,   137,    -1,   191,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    -1,   217,    -1,   167,    -1,    50,
      -1,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,    64,    65,     3,     4,     5,    -1,   189,
     190,   191,    -1,    -1,    12,    13,    -1,    -1,    16,    -1,
      -1,    -1,    20,    -1,    22,    23,    -1,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,   215,   216,   217,    -1,    -1,
       3,     4,     5,    -1,    -1,   106,   107,   108,    -1,    12,
      13,    -1,    -1,    16,    -1,    -1,    -1,    20,   238,    22,
      23,    -1,    -1,    -1,   244,    -1,   127,    -1,    -1,    -1,
      -1,    -1,    14,    -1,   135,   136,   137,    -1,    -1,    21,
      22,    23,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,   167,    -1,    50,    -1,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,    64,    65,     3,     4,     5,    -1,   189,   190,
     191,    -1,    -1,    12,    13,    -1,    -1,    16,    -1,    -1,
      -1,    20,    -1,    22,    23,    -1,    -1,    89,    -1,    -1,
      92,    -1,    -1,    -1,   215,   216,   217,    -1,    -1,     3,
       4,     5,    -1,    -1,   106,   107,   108,    -1,    12,    13,
      -1,    -1,    16,    -1,    -1,    -1,    20,   238,    22,    23,
      -1,    -1,    -1,   244,    -1,   127,    -1,    -1,    -1,    -1,
      -1,    14,    -1,   135,   136,   137,    -1,    -1,    21,    22,
      23,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,   167,    -1,    50,    -1,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,    64,    65,     3,     4,     5,    -1,   189,   190,   191,
      -1,    -1,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,
      20,    -1,    22,    23,    -1,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,   215,   216,   217,    -1,    -1,     3,     4,
       5,    -1,    -1,   106,   107,   108,    -1,    12,    13,    -1,
      -1,    16,    -1,    -1,    -1,    20,   238,    22,    23,    -1,
      -1,    -1,   244,    -1,   127,    -1,     6,     7,     8,     9,
      10,    11,   135,   136,   137,    15,    16,    17,    18,    -1,
      20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,   167,    -1,    -1,    -1,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
      14,    -1,     3,     4,    -1,    -1,   189,   190,   191,    23,
      -1,    12,    13,    -1,    28,    16,    -1,    -1,    -1,    20,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    -1,   215,   216,   217,    21,    50,    -1,    24,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      64,    -1,    -1,    14,    -1,   238,    14,    -1,    -1,    -1,
      -1,   244,    23,    -1,    -1,    23,    -1,    28,    -1,    -1,
      28,    -1,     6,     7,     8,     9,    10,    11,    92,    -1,
      14,    15,    16,    17,    18,    -1,    20,    21,    -1,    50,
      24,    -1,    50,    -1,   108,    -1,    54,    55,    56,    57,
      58,    59,    -1,    64,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,    14,    -1,     6,     7,     8,
       9,    10,    11,   137,    23,    -1,    15,    16,    -1,    28,
      -1,    92,    21,    -1,    92,    24,    -1,    -1,   152,   153,
     154,   155,   156,   157,   158,   159,    -1,   108,   162,    -1,
     108,    50,    -1,    -1,    -1,    54,    55,     6,     7,     8,
       9,    10,    11,   177,   178,    64,   127,    -1,    -1,   127,
      -1,    -1,    21,    -1,    -1,    24,   137,   191,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    92,   152,   153,   154,   155,   156,   157,
      -1,   162,    21,   217,   162,    24,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,    -1,   173,   174,   175,   176,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,   127,    -1,
     191,    -1,    -1,   191,    21,    -1,    -1,    24,   137,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,   152,   153,    21,   217,    -1,    24,   217,
      -1,    -1,    -1,   162,    -1,    -1,     6,     7,     8,     9,
      10,    11,   171,   172,    14,    15,    16,    17,    18,    -1,
      20,    21,    -1,    -1,    24,     6,     7,     8,     9,    10,
      11,    -1,   191,    14,    15,    16,    17,    18,    -1,    20,
      21,    -1,    -1,    24,    -1,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,   217,    20,
      21,    -1,    -1,    24,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    20,    21,
      -1,    -1,    24,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    20,    21,    -1,
      -1,    24,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    20,    21,    -1,    -1,
      24,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    20,    21,    -1,    -1,    24,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    20,    21,    -1,    -1,    24,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    21,    -1,    -1,    24,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    24,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    20,    21,    -1,    -1,    24,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      20,    21,    -1,    -1,    24,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,
      21,    -1,    -1,    24,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,    21,
      -1,    -1,    24,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    20,    21,    -1,
      -1,    24,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    21,    -1,    -1,
      24,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    20,    21,    -1,    -1,    24,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,    -1,    -1,    24,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    -1,    21,    -1,    -1,    24,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    24,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    21,    -1,    -1,    24,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      -1,    21,    -1,    -1,    24,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      21,    -1,    -1,    24,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,
      -1,    -1,    24,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      -1,    24,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    21,    -1,    -1,
      24,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    21,    -1,    -1,    24,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    21,    -1,    -1,    24,     6,
       7,     8,     9,    10,    11,    -1,     3,     4,    15,    16,
      -1,     3,     4,    -1,    21,    12,    13,    24,    -1,    16,
      12,    13,    -1,    20,    16,     3,     4,    -1,    20,    -1,
       3,     4,    -1,    -1,    12,    13,    -1,    -1,    16,    12,
      13,    -1,    20,    16,    -1,    -1,    -1,    20,     6,     7,
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
      -1,    -1,    14,    15,    16,    17,    18,    -1,    20,    21,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    20,    21,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      20,    21,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    21,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    21,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    -1,    21,
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
      20,    21,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    21,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    21,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    21,     6,     7,     8,     9,
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
      -1,    15,    16,    -1,    -1,    -1,    -1,    21,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    -1,
      -1,    -1,    -1,    21,     6,     7,     8,     9,    10,    11,
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
      -1,    -1,    -1,    -1,    -1,    19,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    26,    27,    28,    29,     1,    12,    20,    37,
      52,     0,    27,    19,    22,    37,    19,    20,     3,     4,
       5,    13,    16,    20,    22,    28,    31,    33,    34,    35,
      36,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      51,    52,    53,    21,    30,     1,    37,    47,    47,    41,
      32,    23,    35,    19,    10,    11,     6,     7,     8,     9,
      15,    16,    17,    18,    14,    20,    38,    39,    52,    21,
      33,    44,    47,    44,    45,    45,    45,    45,    46,    46,
      47,    47,    42,    42,    49,    50,    24,    21,    23,    24,
      21,    52,    22,    42,    33,    23,    12,    20,    52,    12,
      12,    20,    52,     3,     4,    12,    13,    16,    20,    42,
      43,    44,    45,    46,    47,    48,    51,    52,    53,    12,
      19,    19,     3,     4,    12,    13,    16,    20,    48,    51,
      52,    53,     3,     4,    12,    13,    16,    20,    43,    44,
      45,    46,    47,    48,    51,    52,    53,    37,    37,    47,
      47,    41,    10,    11,     6,     7,     8,     9,    15,    16,
      17,    18,    14,    20,    47,    47,    41,    20,    47,    47,
      41,    10,    11,     6,     7,     8,     9,    15,    16,    17,
      18,    14,    20,    21,    21,    21,     3,     4,    12,    13,
      16,    20,    44,    47,    48,    51,    52,    53,    44,    45,
      45,    45,    45,    46,    46,    47,    47,    42,    50,    21,
      50,    21,     3,     4,    12,    13,    16,    20,    44,    47,
      48,    51,    52,    53,    44,    45,    45,    45,    45,    46,
      46,    47,    47,    42,    50,    47,    47,    41,    20,    21,
      21,    47,    47,    41,    20,    21,    21,    50,    21,    50,
      21,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    26,    26,    27,    27,    28,    28,    30,    29,
      29,    32,    31,    33,    33,    34,    34,    35,    35,    36,
      36,    37,    37,    38,    38,    39,    39,    40,    41,    42,
      42,    43,    43,    43,    44,    44,    44,    44,    44,    45,
      45,    45,    46,    46,    46,    47,    47,    47,    48,    48,
      49,    49,    50,    50,    51,    51,    51,    52,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     3,     3,     0,     9,
       5,     0,     4,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     0,     1,     2,     1,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     2,     2,     1,     4,
       1,     3,     1,     0,     1,     1,     3,     1,     1,     1
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
#line 51 "src/bison/math.y"
                                { list_push(&root->children, (yyvsp[0].ast)); }
#line 1757 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 52 "src/bison/math.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 1763 "src/bison/grammar.c"
    break;

  case 6: /* declaration: LET declarator ';'  */
#line 59 "src/bison/math.y"
                                {
        /*Symbol *sym = */symbol_table_insert(current_scope->symbol_table, (yyvsp[-1].ast)->value.symref->symbol->name);
        // printf("declared variable '%s' at scope: %d\n", sym->name, current_scope->index);
        (yyval.ast) = ast_declaration_init((yyvsp[-1].ast));
        
    }
#line 1774 "src/bison/grammar.c"
    break;

  case 7: /* declaration: LET error ';'  */
#line 65 "src/bison/math.y"
                    {
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 1784 "src/bison/grammar.c"
    break;

  case 8: /* $@1: %empty  */
#line 72 "src/bison/math.y"
                                     {
        previous_scope = current_scope;
        current_scope = scope_add(previous_scope);
    }
#line 1793 "src/bison/grammar.c"
    break;

  case 9: /* func_declaration: LET declarator '(' $@1 id_list.opt ')' '{' block_item_list.opt '}'  */
#line 75 "src/bison/math.y"
                                                  {
        // printf("found a function\n");
        symbol_table_insert(previous_scope->symbol_table, (yyvsp[-7].ast)->value.symref->symbol->name);
        (yyval.ast) = ast_userfunc_init(current_scope, (yyvsp[-7].ast), ast_params_init((yyvsp[-4].list)), ast_blockitems_init((yyvsp[-1].list)));
    }
#line 1803 "src/bison/grammar.c"
    break;

  case 10: /* func_declaration: LET error '{' block_item_list.opt '}'  */
#line 80 "src/bison/math.y"
                                            {
        CIPL_PERROR_CURSOR("expected identifier before '(' token\n", error_cursor);
        list_free((yyvsp[-1].list), ast_child_free);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 1814 "src/bison/grammar.c"
    break;

  case 11: /* $@2: %empty  */
#line 88 "src/bison/math.y"
                   {
        // printf("found a code block on line:%d\n", cursor.line);
        previous_scope = current_scope;
        current_scope = scope_add(previous_scope);
        // printf("starting scope: %d\n", current_scope->index);
    }
#line 1825 "src/bison/grammar.c"
    break;

  case 12: /* compound_stmt: '{' $@2 block_item_list.opt '}'  */
#line 93 "src/bison/math.y"
                              {
        // printf("leaving scope: %d on line:%d\n", current_scope->index, cursor.line);
        current_scope = previous_scope;
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
    }
#line 1835 "src/bison/grammar.c"
    break;

  case 13: /* block_item_list.opt: block_item_list  */
#line 100 "src/bison/math.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 1841 "src/bison/grammar.c"
    break;

  case 14: /* block_item_list.opt: %empty  */
#line 101 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 1847 "src/bison/grammar.c"
    break;

  case 15: /* block_item_list: block_item_list block_item  */
#line 104 "src/bison/math.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 1853 "src/bison/grammar.c"
    break;

  case 16: /* block_item_list: block_item  */
#line 105 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 1859 "src/bison/grammar.c"
    break;

  case 17: /* block_item: declaration  */
#line 108 "src/bison/math.y"
                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1865 "src/bison/grammar.c"
    break;

  case 22: /* declarator: '(' declarator ')'  */
#line 117 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 1871 "src/bison/grammar.c"
    break;

  case 23: /* id_list: id_list ',' id  */
#line 120 "src/bison/math.y"
                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 1877 "src/bison/grammar.c"
    break;

  case 24: /* id_list: id  */
#line 121 "src/bison/math.y"
         { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 1883 "src/bison/grammar.c"
    break;

  case 25: /* id_list.opt: %empty  */
#line 124 "src/bison/math.y"
                    { (yyval.list) = NULL; }
#line 1889 "src/bison/grammar.c"
    break;

  case 27: /* expr_stmt: expression ';'  */
#line 128 "src/bison/math.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 1895 "src/bison/grammar.c"
    break;

  case 30: /* assign_expr: cast_expr '=' assign_expr  */
#line 135 "src/bison/math.y"
                                {
        // printf("found an assignment\n");
        (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1904 "src/bison/grammar.c"
    break;

  case 32: /* eq_expr: eq_expr EQ rel_expr  */
#line 142 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("==", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1910 "src/bison/grammar.c"
    break;

  case 33: /* eq_expr: eq_expr NE rel_expr  */
#line 143 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("!=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1916 "src/bison/grammar.c"
    break;

  case 35: /* rel_expr: rel_expr LT add_expr  */
#line 147 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1922 "src/bison/grammar.c"
    break;

  case 36: /* rel_expr: rel_expr LE add_expr  */
#line 148 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1928 "src/bison/grammar.c"
    break;

  case 37: /* rel_expr: rel_expr GT add_expr  */
#line 149 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1934 "src/bison/grammar.c"
    break;

  case 38: /* rel_expr: rel_expr GE add_expr  */
#line 150 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1940 "src/bison/grammar.c"
    break;

  case 40: /* add_expr: add_expr '+' mult_expr  */
#line 154 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('+', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1946 "src/bison/grammar.c"
    break;

  case 41: /* add_expr: add_expr '-' mult_expr  */
#line 155 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('-', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1952 "src/bison/grammar.c"
    break;

  case 43: /* mult_expr: mult_expr '*' cast_expr  */
#line 159 "src/bison/math.y"
                              { (yyval.ast) = ast_binop_init('*', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1958 "src/bison/grammar.c"
    break;

  case 44: /* mult_expr: mult_expr '/' cast_expr  */
#line 160 "src/bison/math.y"
                              { (yyval.ast) = ast_binop_init('/', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1964 "src/bison/grammar.c"
    break;

  case 46: /* cast_expr: '!' cast_expr  */
#line 164 "src/bison/math.y"
                    { (yyval.ast) = ast_uniop_init('!', (yyvsp[0].ast)); }
#line 1970 "src/bison/grammar.c"
    break;

  case 47: /* cast_expr: '-' cast_expr  */
#line 165 "src/bison/math.y"
                    { (yyval.ast) = ast_uniop_init('-', (yyvsp[0].ast)); }
#line 1976 "src/bison/grammar.c"
    break;

  case 53: /* arg_expr_list.opt: %empty  */
#line 177 "src/bison/math.y"
             { (yyval.ast) = NULL; }
#line 1982 "src/bison/grammar.c"
    break;

  case 56: /* primary_expr: '(' expression ')'  */
#line 182 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 1988 "src/bison/grammar.c"
    break;

  case 57: /* id: NAME  */
#line 185 "src/bison/math.y"
         {
        Symbol *sym = symbol_init((yyvsp[0].identifier), current_scope->index, cursor);
        (yyval.ast) = ast_symref_init(sym);
        free((yyvsp[0].identifier));
    }
#line 1998 "src/bison/grammar.c"
    break;

  case 58: /* constant: NUMBER_REAL  */
#line 192 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 2004 "src/bison/grammar.c"
    break;

  case 59: /* constant: NUMBER_INT  */
#line 193 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 2010 "src/bison/grammar.c"
    break;


#line 2014 "src/bison/grammar.c"

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

#line 196 "src/bison/math.y"


void yyerror(char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    /* CIPL_PERROR_CURSOR("%s\n", error_cursor, s); */
}
