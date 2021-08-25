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

	#include <stdio.h>

    #include "data-structures/ast/ast.h"
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"

    AST *root;

#line 82 "src/bison/grammar.c"

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
  YYSYMBOL_22_ = 22,                       /* ','  */
  YYSYMBOL_YYACCEPT = 23,                  /* $accept  */
  YYSYMBOL_prog = 24,                      /* prog  */
  YYSYMBOL_declarations = 25,              /* declarations  */
  YYSYMBOL_external_declaration = 26,      /* external_declaration  */
  YYSYMBOL_declaration = 27,               /* declaration  */
  YYSYMBOL_declarator = 28,                /* declarator  */
  YYSYMBOL_expression = 29,                /* expression  */
  YYSYMBOL_assign_expr = 30,               /* assign_expr  */
  YYSYMBOL_eq_expr = 31,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 32,                  /* rel_expr  */
  YYSYMBOL_add_expr = 33,                  /* add_expr  */
  YYSYMBOL_mult_expr = 34,                 /* mult_expr  */
  YYSYMBOL_cast_expr = 35,                 /* cast_expr  */
  YYSYMBOL_postfix_expr = 36,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 37,             /* arg_expr_list  */
  YYSYMBOL_38_arg_expr_list_opt = 38,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 39,              /* primary_expr  */
  YYSYMBOL_id = 40,                        /* id  */
  YYSYMBOL_constant = 41                   /* constant  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2059

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  186

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
      20,    21,    17,    15,    22,    16,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    19,
       2,    14,     2,     2,     2,     2,     2,     2,     2,     2,
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
static const yytype_int8 yyrline[] =
{
       0,    38,    38,    41,    42,    45,    48,    51,    57,    60,
      63,    64,    67,    68,    69,    72,    73,    74,    75,    76,
      79,    80,    81,    84,    85,    86,    89,    90,    91,    94,
      95,    98,    99,   102,   103,   106,   107,   108,   111,   114,
     115
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
  "'='", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'", "','", "$accept",
  "prog", "declarations", "external_declaration", "declaration",
  "declarator", "expression", "assign_expr", "eq_expr", "rel_expr",
  "add_expr", "mult_expr", "cast_expr", "postfix_expr", "arg_expr_list",
  "arg_expr_list.opt", "primary_expr", "id", "constant", YY_NULLPTR
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
      40,    41,    44
};
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,    -8,     7,    21,     8,    17,     9,    16,    18,   -99,
      34,    23,    19,  1717,  1732,   160,   160,   267,    -9,  2020,
    1950,   591,  1852,  1747,  1762,  1777,  1792,    47,  1866,  1880,
      41,    56,     4,  1295,   160,   160,    53,   160,   160,   160,
     160,   160,   160,   160,   160,    51,  1807,   267,  2026,  2040,
    1964,  1978,  1992,  2006,  1894,  1908,  1922,  1936,    -2,    28,
      68,    69,   358,  1822,    35,  1837,  1151,  1167,  1183,   267,
     267,   267,   614,  1615,  1487,  1199,  1215,  1231,  1247,   449,
     449,   574,   632,   656,   358,   358,   267,    65,   255,   234,
     981,   777,   675,   692,   709,   726,  1311,  1327,    70,   449,
     449,   449,   449,   449,   449,   449,   449,    51,  1343,  1359,
    1375,   449,   449,   267,  1695,  1503,  1391,  1407,  1423,  1439,
    1701,   794,   811,    71,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   358,    51,  1263,  1631,  1647,  1663,
    1679,  1519,  1535,  1551,  1567,    73,  1583,  1599,    74,    51,
     743,   828,   845,   862,   519,   519,   267,   346,   998,   879,
     896,   913,   930,   437,   325,   416,  1117,  1134,  1015,  1032,
    1049,  1066,    38,    75,  1279,  1455,    76,  1083,  1100,    88,
      51,   760,  1471,   947,    95,   964
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
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
       0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,    36,   -99,   -99,   -99,   -68,   -14,    -5,    -6,
     532,   474,    98,   189,   -99,   -98,   280,    -1,   371
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,     7,    30,    31,    87,    88,
      89,    90,    22,    23,    59,    60,    24,    25,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       8,    34,    35,    98,     6,    19,    18,     9,    -4,   145,
      36,    72,    32,     1,    79,    80,    77,    -5,   123,   -31,
     -31,    -2,    -5,   -38,    12,   -10,    13,    14,    48,    49,
      11,    58,    -8,    61,    -3,    65,    15,   173,    27,    16,
      10,    72,    32,    17,    94,   148,    77,    -7,    64,   -33,
      62,   176,    -7,    -6,    81,    82,   -32,   -32,    -6,   -11,
     -11,    94,    46,    83,    84,    72,    32,    85,    77,    77,
      77,    86,   -34,   114,   120,   124,   125,    -9,   118,   118,
      72,    32,   184,    94,    94,    77,   -10,   -10,   179,    63,
     -11,   136,   150,    58,   174,   175,   181,   182,   118,   118,
     118,   118,   118,   118,   118,   118,    94,    72,    32,   183,
     118,   118,    77,    28,    29,    33,   185,     0,   157,   163,
     172,    58,     0,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,    94,    94,    58,     0,     0,     0,     0,
       0,    56,    57,    91,     0,    33,     0,     0,    94,     0,
      72,    32,     0,   161,   161,    77,     0,     0,     0,     0,
      91,     0,     0,    13,    14,     0,    58,    96,    97,    33,
       0,     0,    65,    15,     0,     0,    16,   115,   115,    94,
      17,     0,   121,   122,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   115,   115,
     115,   115,   115,   143,   144,    91,    75,     0,     0,   146,
     147,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   158,   158,   158,   158,   158,   158,   158,   158,
     170,   171,    91,    91,    92,     0,    75,     0,     0,     0,
     -15,   -15,   -15,   -15,   -15,   -15,     0,    91,     0,   130,
     131,    92,   177,   178,    33,   -15,   -15,     0,    75,    75,
      75,   126,   127,   128,   129,   -12,   -12,     0,   116,   116,
      66,    67,     0,    92,    92,    75,   -12,   -12,    91,    68,
      69,     0,     0,    70,     0,     0,     0,    71,   116,   116,
     116,   116,   116,   116,   116,   116,    92,    76,     0,     0,
     116,   116,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,    92,    92,    93,     0,    76,     0,     0,
       0,   -16,   -16,   -16,   -16,   -16,   -16,     0,    92,     0,
     130,   131,    93,   159,   159,    75,   -16,   -16,     0,    76,
      76,    76,   126,   127,   128,   129,   -13,   -13,     0,   117,
     117,    81,    82,     0,    93,    93,    76,   -13,   -13,    92,
      83,    84,     0,     0,    85,     0,     0,     0,    86,   117,
     117,   117,   117,   117,   117,   117,   117,    93,    78,     0,
       0,   117,   117,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,    93,    93,    95,     0,    78,     0,
       0,     0,   -17,   -17,   -17,   -17,   -17,   -17,     0,    93,
       0,   130,   131,    95,   160,   160,    76,   -17,   -17,     0,
      78,    78,    78,   126,   127,   128,   129,   -14,   -14,     0,
     119,   119,   108,   109,     0,    95,    95,    78,   -14,   -14,
      93,   110,   111,     0,     0,   112,     0,     0,     0,   113,
     119,   119,   119,   119,   119,   119,   119,   119,    95,     0,
       0,     0,   119,   119,    78,    21,     0,     0,     0,     0,
       0,    74,     0,     0,     0,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,    95,    95,     0,    21,    21,
       0,    21,    21,    21,    21,    54,    55,     0,     0,     0,
      95,    74,   151,   152,     0,   162,   162,    78,     0,     0,
       0,   153,   154,     0,     0,   155,     0,     0,     0,   156,
       0,     0,     0,    20,     0,    74,     0,     0,     0,    73,
       0,    95,     0,    74,    74,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,    20,    20,     0,    50,
      51,    52,    53,    74,    74,    74,    74,   141,   142,    73,
     -40,   -40,   -40,   -40,   -40,   -40,     0,    74,   -40,   -40,
     -40,   -40,   -40,     0,   -40,   -40,   -40,   -20,   -20,   -20,
     -20,   -20,   -20,    73,   168,   169,   -20,   -20,    43,    44,
     -20,    73,    73,     0,     0,     0,     0,     0,    73,     0,
      99,   100,   101,   102,   -12,   -12,     0,     0,     0,     0,
      74,   137,   138,   139,   140,   -12,     0,     0,   -39,   -39,
     -39,   -39,   -39,   -39,     0,    73,   -39,   -39,   -39,   -39,
     -39,     0,   -39,   -39,   -39,     0,     0,     0,   164,   165,
     166,   167,   -38,   -38,   -38,   -38,   -38,   -38,     0,     0,
     -38,   -38,   -38,   -38,   -38,     0,   -38,   -38,   -38,     0,
       0,   -26,   -26,   -26,   -26,   -26,   -26,     0,    73,   -26,
     -26,   -26,   -26,   -26,     0,   135,   -26,   -26,   -29,   -29,
     -29,   -29,   -29,   -29,     0,     0,   -29,   -29,   -29,   -29,
     -29,     0,   -29,   -29,   -29,   -35,   -35,   -35,   -35,   -35,
     -35,     0,     0,   -35,   -35,   -35,   -35,   -35,     0,   -35,
     -35,   -35,   -36,   -36,   -36,   -36,   -36,   -36,     0,     0,
     -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,   -37,
     -37,   -37,   -37,   -37,   -37,     0,     0,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,   -37,   -30,   -30,   -30,   -30,
     -30,   -30,     0,     0,   -30,   -30,   -30,   -30,   -30,     0,
     -30,   -30,   -30,   -23,   -23,   -23,   -23,   -23,   -23,     0,
       0,   134,   -23,   -23,   -23,   -23,     0,     0,   -23,   -23,
     -27,   -27,   -27,   -27,   -27,   -27,     0,     0,   -27,   -27,
     -27,   -27,   -27,     0,     0,   -27,   -27,   -28,   -28,   -28,
     -28,   -28,   -28,     0,     0,   -28,   -28,   -28,   -28,   -28,
       0,     0,   -28,   -28,   -40,   -40,   -40,   -40,   -40,   -40,
       0,     0,     0,   -40,   -40,   -40,   -40,     0,   -40,   -40,
     -40,   -39,   -39,   -39,   -39,   -39,   -39,     0,     0,     0,
     -39,   -39,   -39,   -39,     0,   -39,   -39,   -39,   -38,   -38,
     -38,   -38,   -38,   -38,     0,     0,     0,   -38,   -38,   -38,
     -38,     0,   -38,   -38,   -38,   -26,   -26,   -26,   -26,   -26,
     -26,     0,     0,     0,   -26,   -26,   -26,   -26,     0,   180,
     -26,   -26,   -29,   -29,   -29,   -29,   -29,   -29,     0,     0,
       0,   -29,   -29,   -29,   -29,     0,   -29,   -29,   -29,   -35,
     -35,   -35,   -35,   -35,   -35,     0,     0,     0,   -35,   -35,
     -35,   -35,     0,   -35,   -35,   -35,   -36,   -36,   -36,   -36,
     -36,   -36,     0,     0,     0,   -36,   -36,   -36,   -36,     0,
     -36,   -36,   -36,   -37,   -37,   -37,   -37,   -37,   -37,     0,
       0,     0,   -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,
     -30,   -30,   -30,   -30,   -30,   -30,     0,     0,     0,   -30,
     -30,   -30,   -30,     0,   -30,   -30,   -30,   -20,   -20,   -20,
     -20,   -20,   -20,     0,     0,     0,   -20,   -20,   132,   133,
       0,     0,   -20,   -20,   -23,   -23,   -23,   -23,   -23,   -23,
       0,     0,     0,   -23,   -23,   -23,   -23,     0,     0,   -23,
     -23,   -21,   -21,   -21,   -21,   -21,   -21,     0,     0,     0,
     -21,   -21,   132,   133,     0,     0,   -21,   -21,   -22,   -22,
     -22,   -22,   -22,   -22,     0,     0,     0,   -22,   -22,   132,
     133,     0,     0,   -22,   -22,   -24,   -24,   -24,   -24,   -24,
     -24,     0,     0,     0,   -24,   -24,   -24,   -24,     0,     0,
     -24,   -24,   -25,   -25,   -25,   -25,   -25,   -25,     0,     0,
       0,   -25,   -25,   -25,   -25,     0,     0,   -25,   -25,   -27,
     -27,   -27,   -27,   -27,   -27,     0,     0,     0,   -27,   -27,
     -27,   -27,     0,     0,   -27,   -27,   -28,   -28,   -28,   -28,
     -28,   -28,     0,     0,     0,   -28,   -28,   -28,   -28,     0,
       0,   -28,   -28,   -18,   -18,   -18,   -18,   -18,   -18,     0,
       0,     0,   130,   131,     0,     0,     0,     0,   -18,   -18,
     -19,   -19,   -19,   -19,   -19,   -19,     0,     0,     0,   130,
     131,     0,     0,     0,     0,   -19,   -19,   -40,   -40,   -40,
     -40,   -40,   -40,     0,     0,   -40,   -40,   -40,   -40,   -40,
       0,   -40,   -40,   -39,   -39,   -39,   -39,   -39,   -39,     0,
       0,   -39,   -39,   -39,   -39,   -39,     0,   -39,   -39,   -38,
     -38,   -38,   -38,   -38,   -38,     0,     0,   -38,   -38,   -38,
     -38,   -38,     0,   -38,   -38,   -26,   -26,   -26,   -26,   -26,
     -26,     0,     0,   -26,   -26,   -26,   -26,   -26,     0,   107,
     -26,   -29,   -29,   -29,   -29,   -29,   -29,     0,     0,   -29,
     -29,   -29,   -29,   -29,     0,   -29,   -29,   -35,   -35,   -35,
     -35,   -35,   -35,     0,     0,   -35,   -35,   -35,   -35,   -35,
       0,   -35,   -35,   -36,   -36,   -36,   -36,   -36,   -36,     0,
       0,   -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,   -37,
     -37,   -37,   -37,   -37,   -37,     0,     0,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,   -30,   -30,   -30,   -30,   -30,
     -30,     0,     0,   -30,   -30,   -30,   -30,   -30,     0,   -30,
     -30,   -23,   -23,   -23,   -23,   -23,   -23,     0,     0,    47,
     -23,   -23,   -23,   -23,     0,     0,   -23,   -27,   -27,   -27,
     -27,   -27,   -27,     0,     0,   -27,   -27,   -27,   -27,   -27,
       0,     0,   -27,   -28,   -28,   -28,   -28,   -28,   -28,     0,
       0,   -28,   -28,   -28,   -28,   -28,     0,     0,   -28,   -40,
     -40,   -40,   -40,   -40,   -40,     0,     0,     0,   -40,   -40,
     -40,   -40,     0,   -40,   -40,   -39,   -39,   -39,   -39,   -39,
     -39,     0,     0,     0,   -39,   -39,   -39,   -39,     0,   -39,
     -39,   -38,   -38,   -38,   -38,   -38,   -38,     0,     0,     0,
     -38,   -38,   -38,   -38,     0,   -38,   -38,   -26,   -26,   -26,
     -26,   -26,   -26,     0,     0,     0,   -26,   -26,   -26,   -26,
       0,   149,   -26,   -29,   -29,   -29,   -29,   -29,   -29,     0,
       0,     0,   -29,   -29,   -29,   -29,     0,   -29,   -29,   -35,
     -35,   -35,   -35,   -35,   -35,     0,     0,     0,   -35,   -35,
     -35,   -35,     0,   -35,   -35,   -36,   -36,   -36,   -36,   -36,
     -36,     0,     0,     0,   -36,   -36,   -36,   -36,     0,   -36,
     -36,   -37,   -37,   -37,   -37,   -37,   -37,     0,     0,     0,
     -37,   -37,   -37,   -37,     0,   -37,   -37,   -30,   -30,   -30,
     -30,   -30,   -30,     0,     0,     0,   -30,   -30,   -30,   -30,
       0,   -30,   -30,   -20,   -20,   -20,   -20,   -20,   -20,     0,
       0,     0,   -20,   -20,   105,   106,     0,     0,   -20,   -23,
     -23,   -23,   -23,   -23,   -23,     0,     0,     0,   -23,   -23,
     -23,   -23,     0,     0,   -23,   -21,   -21,   -21,   -21,   -21,
     -21,     0,     0,     0,   -21,   -21,   105,   106,     0,     0,
     -21,   -22,   -22,   -22,   -22,   -22,   -22,     0,     0,     0,
     -22,   -22,   105,   106,     0,     0,   -22,   -24,   -24,   -24,
     -24,   -24,   -24,     0,     0,     0,   -24,   -24,   -24,   -24,
       0,     0,   -24,   -25,   -25,   -25,   -25,   -25,   -25,     0,
       0,     0,   -25,   -25,   -25,   -25,     0,     0,   -25,   -27,
     -27,   -27,   -27,   -27,   -27,     0,     0,     0,   -27,   -27,
     -27,   -27,     0,     0,   -27,   -28,   -28,   -28,   -28,   -28,
     -28,     0,     0,     0,   -28,   -28,   -28,   -28,     0,     0,
     -28,   -15,   -15,   -15,   -15,   -15,   -15,     0,     0,     0,
     103,   104,     0,     0,     0,     0,   -15,   -16,   -16,   -16,
     -16,   -16,   -16,     0,     0,     0,   103,   104,     0,     0,
       0,     0,   -16,   -17,   -17,   -17,   -17,   -17,   -17,     0,
       0,     0,   103,   104,     0,     0,     0,     0,   -17,   -18,
     -18,   -18,   -18,   -18,   -18,     0,     0,     0,   103,   104,
       0,     0,     0,     0,   -18,   -19,   -19,   -19,   -19,   -19,
     -19,     0,     0,     0,   103,   104,     0,     0,     0,     0,
     -19,    99,   100,   101,   102,   -13,   -13,    99,   100,   101,
     102,   -14,   -14,     0,     0,     0,   -13,     0,     0,     0,
       0,     0,   -14,   -40,   -40,   -40,   -40,   -40,   -40,     0,
       0,     0,   -40,   -40,   -40,   -40,   -40,   -40,   -39,   -39,
     -39,   -39,   -39,   -39,     0,     0,     0,   -39,   -39,   -39,
     -39,   -39,   -39,   -26,   -26,   -26,   -26,   -26,   -26,     0,
       0,     0,   -26,   -26,   -26,   -26,   -26,    45,   -29,   -29,
     -29,   -29,   -29,   -29,     0,     0,     0,   -29,   -29,   -29,
     -29,   -29,   -29,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,     0,   -35,   -35,   -35,   -35,   -35,   -35,   -36,   -36,
     -36,   -36,   -36,   -36,     0,     0,     0,   -36,   -36,   -36,
     -36,   -36,   -36,   -37,   -37,   -37,   -37,   -37,   -37,     0,
       0,     0,   -37,   -37,   -37,   -37,   -37,   -37,   -30,   -30,
     -30,   -30,   -30,   -30,     0,     0,     0,   -30,   -30,   -30,
     -30,   -30,   -30,   -38,   -38,   -38,   -38,   -38,   -38,     0,
       0,     0,   -38,   -38,   -38,   -38,   -38,   -38,   -23,   -23,
     -23,   -23,   -23,   -23,     0,     0,     0,   -23,   -23,   -23,
     -23,   -23,   -27,   -27,   -27,   -27,   -27,   -27,     0,     0,
       0,   -27,   -27,   -27,   -27,   -27,   -28,   -28,   -28,   -28,
     -28,   -28,     0,     0,     0,   -28,   -28,   -28,   -28,   -28,
     -21,   -21,   -21,   -21,   -21,   -21,     0,     0,     0,   -21,
     -21,    43,    44,   -21,   -22,   -22,   -22,   -22,   -22,   -22,
       0,     0,     0,   -22,   -22,    43,    44,   -22,   -24,   -24,
     -24,   -24,   -24,   -24,     0,     0,     0,   -24,   -24,   -24,
     -24,   -24,   -25,   -25,   -25,   -25,   -25,   -25,     0,     0,
       0,   -25,   -25,   -25,   -25,   -25,   -15,   -15,   -15,   -15,
     -15,   -15,     0,     0,     0,    41,    42,     0,     0,   -15,
     -16,   -16,   -16,   -16,   -16,   -16,     0,     0,     0,    41,
      42,     0,     0,   -16,   -17,   -17,   -17,   -17,   -17,   -17,
       0,     0,     0,    41,    42,     0,     0,   -17,   -18,   -18,
     -18,   -18,   -18,   -18,     0,     0,     0,    41,    42,     0,
       0,   -18,   -19,   -19,   -19,   -19,   -19,   -19,     0,     0,
       0,    41,    42,     0,     0,   -19,    37,    38,    39,    40,
     -12,   -12,    37,    38,    39,    40,   -13,   -13,     0,   -12,
       0,     0,     0,     0,     0,   -13,    37,    38,    39,    40,
     -14,   -14,     0,     0,     0,     0,     0,     0,     0,   -14
};

static const yytype_int16 yycheck[] =
{
       1,    10,    11,    71,    12,    11,    11,     0,     0,   107,
      19,    17,    17,     5,    10,    11,    17,     0,    86,    21,
      22,     0,     5,    14,     1,    21,     3,     4,    34,    35,
      14,    45,    14,    47,     0,    12,    13,   135,    19,    16,
       4,    47,    47,    20,    45,   113,    47,     0,    62,    21,
      22,   149,     5,     0,     3,     4,    21,    22,     5,    21,
      22,    62,    21,    12,    13,    71,    71,    16,    69,    70,
      71,    20,    21,    79,    80,    10,    11,    21,    79,    80,
      86,    86,   180,    84,    85,    86,    21,    22,   156,    21,
      21,    21,    21,   107,    21,    21,    21,    21,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   113,   113,    21,
     111,   112,   113,    15,    16,    17,    21,    -1,   124,   125,
     134,   135,    -1,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   149,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    47,    -1,    -1,   149,    -1,
     156,   156,    -1,   154,   155,   156,    -1,    -1,    -1,    -1,
      62,    -1,    -1,     3,     4,    -1,   180,    69,    70,    71,
      -1,    -1,    12,    13,    -1,    -1,    16,    79,    80,   180,
      20,    -1,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    17,    -1,    -1,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    45,    -1,    47,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,   149,    -1,    15,
      16,    62,   154,   155,   156,    21,    22,    -1,    69,    70,
      71,     6,     7,     8,     9,    10,    11,    -1,    79,    80,
       3,     4,    -1,    84,    85,    86,    21,    22,   180,    12,
      13,    -1,    -1,    16,    -1,    -1,    -1,    20,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    17,    -1,    -1,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    45,    -1,    47,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,   149,    -1,
      15,    16,    62,   154,   155,   156,    21,    22,    -1,    69,
      70,    71,     6,     7,     8,     9,    10,    11,    -1,    79,
      80,     3,     4,    -1,    84,    85,    86,    21,    22,   180,
      12,    13,    -1,    -1,    16,    -1,    -1,    -1,    20,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    17,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    45,    -1,    47,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,   149,
      -1,    15,    16,    62,   154,   155,   156,    21,    22,    -1,
      69,    70,    71,     6,     7,     8,     9,    10,    11,    -1,
      79,    80,     3,     4,    -1,    84,    85,    86,    21,    22,
     180,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,    20,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,   111,   112,   113,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
     149,    47,     3,     4,    -1,   154,   155,   156,    -1,    -1,
      -1,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    11,    -1,    71,    -1,    -1,    -1,    17,
      -1,   180,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    99,   100,   101,   102,   103,   104,    47,
       6,     7,     8,     9,    10,    11,    -1,   113,    14,    15,
      16,    17,    18,    -1,    20,    21,    22,     6,     7,     8,
       9,    10,    11,    71,   130,   131,    15,    16,    17,    18,
      19,    79,    80,    -1,    -1,    -1,    -1,    -1,    86,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
     156,    99,   100,   101,   102,    21,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,   113,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    -1,    -1,   126,   127,
     128,   129,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    20,    21,    22,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,   156,    14,
      15,    16,    17,    18,    -1,    20,    21,    22,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    -1,    20,
      21,    22,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    20,    21,    22,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    20,    21,    22,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      20,    21,    22,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      -1,    -1,    21,    22,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,    21,
      22,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      20,    21,    22,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    21,    22,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,
      22,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    -1,    21,    22,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,    -1,    21,    22,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      21,    22,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    21,    22,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    -1,    21,    22,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      -1,    21,    22,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    21,    22,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      -1,    20,    21,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    20,    21,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    20,    21,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    -1,    20,
      21,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    20,    21,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      -1,    20,    21,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    20,    21,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    20,    21,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    -1,    20,
      21,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    -1,    21,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      -1,    -1,    21,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    -1,    21,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    20,    21,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,
      21,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    20,    21,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    20,    21,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    20,    21,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    20,    21,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,
      21,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    20,    21,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    20,    21,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    -1,    21,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      21,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    -1,    21,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    -1,    21,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    -1,    21,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      21,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    21,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    21,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    21,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      21,     6,     7,     8,     9,    10,    11,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    21,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,     6,     7,
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
       0,     5,    24,    25,    26,    27,    12,    28,    40,     0,
      25,    14,     1,     3,     4,    13,    16,    20,    31,    32,
      33,    34,    35,    36,    39,    40,    41,    19,    35,    35,
      29,    30,    31,    35,    10,    11,    19,     6,     7,     8,
       9,    15,    16,    17,    18,    20,    21,    14,    32,    32,
      33,    33,    33,    33,    34,    34,    35,    35,    30,    37,
      38,    30,    22,    21,    30,    12,     3,     4,    12,    13,
      16,    20,    32,    33,    34,    36,    39,    40,    41,    10,
      11,     3,     4,    12,    13,    16,    20,    31,    32,    33,
      34,    35,    36,    39,    40,    41,    35,    35,    29,     6,
       7,     8,     9,    15,    16,    17,    18,    20,     3,     4,
      12,    13,    16,    20,    32,    35,    36,    39,    40,    41,
      32,    35,    35,    29,    10,    11,     6,     7,     8,     9,
      15,    16,    17,    18,    14,    20,    21,    33,    33,    33,
      33,    34,    34,    35,    35,    38,    35,    35,    29,    20,
      21,     3,     4,    12,    13,    16,    20,    32,    35,    36,
      39,    40,    41,    32,    33,    33,    33,    33,    34,    34,
      35,    35,    30,    38,    21,    21,    38,    35,    35,    29,
      20,    21,    21,    21,    38,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    23,    24,    25,    25,    26,    27,    27,    28,    29,
      30,    30,    31,    31,    31,    32,    32,    32,    32,    32,
      33,    33,    33,    34,    34,    34,    35,    35,    35,    36,
      36,    37,    37,    38,    38,    39,    39,    39,    40,    41,
      41
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     5,     5,     1,     1,
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
  case 6: /* declaration: LET declarator '=' eq_expr ';'  */
#line 48 "src/bison/math.y"
                                            {
        list_push(&root->children, ast_assign_init((yyvsp[-3].ast), (yyvsp[-1].ast)));
    }
#line 1591 "src/bison/grammar.c"
    break;

  case 7: /* declaration: LET declarator '=' error ';'  */
#line 51 "src/bison/math.y"
                                   {
        cipl_perror("expected expression before ‘;’ token");
        yyerrok;
    }
#line 1600 "src/bison/grammar.c"
    break;

  case 13: /* eq_expr: eq_expr EQ rel_expr  */
#line 68 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("==", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1606 "src/bison/grammar.c"
    break;

  case 14: /* eq_expr: eq_expr NE rel_expr  */
#line 69 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("!=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1612 "src/bison/grammar.c"
    break;

  case 16: /* rel_expr: rel_expr LT add_expr  */
#line 73 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1618 "src/bison/grammar.c"
    break;

  case 17: /* rel_expr: rel_expr LE add_expr  */
#line 74 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1624 "src/bison/grammar.c"
    break;

  case 18: /* rel_expr: rel_expr GT add_expr  */
#line 75 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1630 "src/bison/grammar.c"
    break;

  case 19: /* rel_expr: rel_expr GE add_expr  */
#line 76 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1636 "src/bison/grammar.c"
    break;

  case 21: /* add_expr: add_expr '+' mult_expr  */
#line 80 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('+', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1642 "src/bison/grammar.c"
    break;

  case 22: /* add_expr: add_expr '-' mult_expr  */
#line 81 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('-', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1648 "src/bison/grammar.c"
    break;

  case 24: /* mult_expr: mult_expr '*' cast_expr  */
#line 85 "src/bison/math.y"
                              { (yyval.ast) = ast_binop_init('*', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1654 "src/bison/grammar.c"
    break;

  case 25: /* mult_expr: mult_expr '/' cast_expr  */
#line 86 "src/bison/math.y"
                              { (yyval.ast) = ast_binop_init('/', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1660 "src/bison/grammar.c"
    break;

  case 27: /* cast_expr: '!' cast_expr  */
#line 90 "src/bison/math.y"
                    { (yyval.ast) = ast_uniop_init('!', (yyvsp[0].ast)); }
#line 1666 "src/bison/grammar.c"
    break;

  case 28: /* cast_expr: '-' cast_expr  */
#line 91 "src/bison/math.y"
                    { (yyval.ast) = ast_uniop_init('-', (yyvsp[0].ast)); }
#line 1672 "src/bison/grammar.c"
    break;

  case 34: /* arg_expr_list.opt: %empty  */
#line 103 "src/bison/math.y"
             { (yyval.ast) = NULL; }
#line 1678 "src/bison/grammar.c"
    break;

  case 37: /* primary_expr: '(' expression ')'  */
#line 108 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 1684 "src/bison/grammar.c"
    break;

  case 38: /* id: NAME  */
#line 111 "src/bison/math.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 1690 "src/bison/grammar.c"
    break;

  case 39: /* constant: NUMBER_REAL  */
#line 114 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 1696 "src/bison/grammar.c"
    break;

  case 40: /* constant: NUMBER_INT  */
#line 115 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 1702 "src/bison/grammar.c"
    break;


#line 1706 "src/bison/grammar.c"

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

#line 118 "src/bison/math.y"


void yyerror(char *s) {
 	cipl_perror("sintatic error: %s\n", s);
 	++errors_count;
}
