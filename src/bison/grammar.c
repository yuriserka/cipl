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
    #include "data-structures/scope.h"
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"

    AST *root;
    Scope *current_scope;
    cursor_position error_cursor;
    ListNode *scopes;

#line 87 "src/bison/grammar.c"

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
  YYSYMBOL_func_declaration = 28,          /* func_declaration  */
  YYSYMBOL_declarator = 29,                /* declarator  */
  YYSYMBOL_id_list = 30,                   /* id_list  */
  YYSYMBOL_31_id_list_opt = 31,            /* id_list.opt  */
  YYSYMBOL_expression = 32,                /* expression  */
  YYSYMBOL_assign_expr = 33,               /* assign_expr  */
  YYSYMBOL_eq_expr = 34,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 35,                  /* rel_expr  */
  YYSYMBOL_add_expr = 36,                  /* add_expr  */
  YYSYMBOL_mult_expr = 37,                 /* mult_expr  */
  YYSYMBOL_cast_expr = 38,                 /* cast_expr  */
  YYSYMBOL_postfix_expr = 39,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 40,             /* arg_expr_list  */
  YYSYMBOL_41_arg_expr_list_opt = 41,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 42,              /* primary_expr  */
  YYSYMBOL_id = 43,                        /* id  */
  YYSYMBOL_constant = 44                   /* constant  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

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
static const yytype_uint8 yyrline[] =
{
       0,    46,    46,    49,    50,    53,    54,    57,    60,    67,
      74,    82,    85,    86,    89,    90,    93,    96,    97,   100,
     101,   102,   105,   106,   107,   108,   109,   112,   113,   114,
     117,   118,   119,   122,   123,   124,   127,   128,   131,   132,
     135,   136,   139,   140,   141,   144,   147,   148
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
  "func_declaration", "declarator", "id_list", "id_list.opt", "expression",
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
      40,    41,    44
};
#endif

#define YYPACT_NINF (-120)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,    16,     6,    59,    67,   103,   105,   -11,    -7,    15,
    -120,    69,     7,     5,    23,  1763,  1778,    48,    48,   161,
      28,  2080,  2010,  1898,  1912,  1793,  1808,  1823,  1838,    10,
      27,    73,   106,  1926,  1940,    52,    64,    -6,   517,    48,
      48,   127,    48,    48,    48,    48,    48,    48,    48,    48,
      42,    76,    82,  1853,   161,  2086,  2100,  2024,  2038,  2052,
    2066,  1954,  1968,  1982,  1996,   129,   134,    83,   138,    21,
      88,   179,  1868,   111,    55,   149,   128,   131,  1883,   157,
    1228,  1244,  1260,   161,   161,   161,    70,  1676,  1548,  1276,
    1292,  1308,  1324,   544,   544,   635,   667,   684,   179,   179,
     161,    79,   205,  1143,  1007,   803,   701,   718,   735,   752,
    1372,  1388,   136,   544,   544,   544,   544,   544,   544,   544,
     544,    42,  1404,  1420,  1436,   544,   544,   161,   418,  1564,
    1452,  1468,  1484,  1500,  1756,   820,   837,   140,   580,   580,
     580,   580,   580,   580,   580,   580,   580,   580,   179,    42,
    1340,  1692,  1708,  1724,  1740,  1580,  1596,  1612,  1628,   142,
    1644,  1660,   145,    42,   769,   854,   871,   888,   580,   580,
     161,   254,  1024,   905,   922,   939,   956,   336,  1160,  1177,
    1194,  1211,  1041,  1058,  1075,  1092,   163,   155,  1356,  1516,
     165,  1109,  1126,   169,    42,   786,  1532,   973,   173,   990
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,   192,  -120,  -120,  -120,  -120,  -120,  -120,   -84,
     -14,     2,   533,   497,   461,   104,   186,  -120,  -119,   268,
      -1,   350
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,     6,     8,    29,    30,    35,
      36,   101,   102,   103,   104,    24,    25,    66,    67,    26,
      27,    28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,   112,   159,   -45,    93,    94,    10,    12,    14,   -45,
      15,    16,    31,    13,    20,   -17,   137,    79,    91,    78,
      17,    37,    73,    18,    15,    16,   -14,    19,     7,   -11,
     187,   -15,    51,    78,    17,   -11,    65,    18,    39,    40,
      70,    19,    32,   162,   190,    95,    96,    41,    52,   108,
      68,    15,    16,    91,    97,    98,    37,    75,    99,    -2,
      78,    17,   100,   -41,    18,    39,    40,    -4,    19,    -3,
     108,    74,     1,    53,    77,   198,   113,   114,   115,   116,
     -19,   -19,    91,    91,    91,   -16,   193,    37,    79,   138,
     139,   -19,   132,   132,   -13,   -13,    69,   108,   108,    91,
     -17,   -17,    37,    -5,    72,    -6,    -8,    65,    -5,   -18,
      -6,    -8,   132,   132,   132,   132,   132,   132,   132,   132,
     108,    33,    34,    38,   132,   132,    91,    -7,   -10,    37,
      76,    -9,    -7,   -10,   186,    65,    -9,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   108,   108,    65,
     -38,   -38,    63,    64,   105,   -40,    71,   150,    38,   -12,
     -12,   164,   108,   188,    80,    81,   189,   175,   175,    91,
     -39,   -39,    37,    82,    83,   105,   195,    84,   -45,   -45,
      65,    85,    95,    96,   -18,   -18,   196,   110,   111,    38,
     197,    97,    98,   108,   199,    99,    11,   129,   129,   100,
       0,     0,   135,   136,    38,    89,     0,     0,     0,     0,
       0,   140,   141,   142,   143,   -19,   -19,   129,   129,   129,
     129,   129,   129,   157,   158,   105,   -19,   -19,     0,   160,
     161,    38,     0,     0,     0,     0,   106,     0,     0,     0,
      89,     0,   172,   172,   172,   172,   172,   172,   172,   172,
     184,   185,   105,   105,     0,     0,     0,   106,     0,     0,
     140,   141,   142,   143,   -20,   -20,     0,   105,     0,    89,
      89,    89,   191,   192,    38,   -20,   -20,     0,     0,   130,
     130,     0,     0,     0,   106,   106,    89,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   130,
     130,   130,   130,   130,   130,   130,   130,   106,     0,     0,
       0,   130,   130,    89,     0,     0,     0,     0,   107,     0,
       0,     0,    90,     0,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   106,   106,     0,     0,     0,   107,
       0,     0,   140,   141,   142,   143,   -21,   -21,     0,   106,
       0,    90,    90,    90,   173,   173,    89,   -21,   -21,     0,
       0,   131,   131,     0,     0,     0,   107,   107,    90,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   131,   131,   131,   131,   131,   131,   131,   131,   107,
       0,     0,     0,   131,   131,    90,     0,     0,     0,     0,
     109,     0,     0,     0,    92,     0,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   107,   107,     0,     0,
       0,   109,     0,     0,   113,   114,   115,   116,   -20,   -20,
       0,   107,     0,    92,    92,    92,   174,   174,    90,   -20,
       0,     0,     0,   133,   133,     0,     0,     0,   109,   109,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   133,   133,   133,   133,   133,   133,   133,
     133,   109,     0,    23,     0,   133,   133,    92,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   109,   109,
      23,    23,     0,    23,    23,    23,    23,    61,    62,    22,
       0,     0,     0,   109,     0,    88,    87,     0,   176,   176,
      92,     0,     0,   -30,   -30,   -30,   -30,   -30,   -30,     0,
      23,    54,   -30,   -30,   -30,   -30,    22,    22,   -30,    57,
      58,    59,    60,     0,   109,    21,    88,   122,   123,     0,
       0,    87,    86,     0,    88,    88,   124,   125,     0,     0,
     126,    88,     0,     0,   127,     0,    22,     0,     0,     0,
       0,     0,    55,    56,    88,    88,    88,    88,   155,   156,
       0,     0,    87,   165,   166,     0,     0,    86,    88,     0,
      87,    87,   167,   168,     0,     0,   169,    87,     0,     0,
     170,     0,    21,     0,     0,   182,   183,     0,     0,     0,
     151,   152,   153,   154,     0,     0,     0,     0,    86,     0,
       0,     0,     0,     0,    87,     0,   128,   134,     0,     0,
       0,    88,     0,    86,     0,     0,     0,   178,   179,   180,
     181,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,   -47,
     -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,     0,     0,
      86,     0,     0,     0,     0,     0,     0,    87,     0,     0,
       0,   171,   177,   -46,   -46,   -46,   -46,   -46,   -46,     0,
       0,   -46,   -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,
     -45,   -45,   -45,   -45,   -45,   -45,     0,     0,   -45,   -45,
     -45,   -45,   -45,    86,   -45,   -45,   -45,   -33,   -33,   -33,
     -33,   -33,   -33,     0,     0,   -33,   -33,   -33,   -33,   -33,
       0,   149,   -33,   -33,   -36,   -36,   -36,   -36,   -36,   -36,
       0,     0,   -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,
     -36,   -42,   -42,   -42,   -42,   -42,   -42,     0,     0,   -42,
     -42,   -42,   -42,   -42,     0,   -42,   -42,   -42,   -43,   -43,
     -43,   -43,   -43,   -43,     0,     0,   -43,   -43,   -43,   -43,
     -43,     0,   -43,   -43,   -43,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,   -44,   -44,   -44,   -44,   -44,     0,   -44,
     -44,   -44,   -37,   -37,   -37,   -37,   -37,   -37,     0,     0,
     -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,   -30,
     -30,   -30,   -30,   -30,   -30,     0,     0,   148,   -30,   -30,
     -30,   -30,     0,     0,   -30,   -30,   -34,   -34,   -34,   -34,
     -34,   -34,     0,     0,   -34,   -34,   -34,   -34,   -34,     0,
       0,   -34,   -34,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,   -35,   -35,   -35,   -35,   -35,     0,     0,   -35,   -35,
     -47,   -47,   -47,   -47,   -47,   -47,     0,     0,     0,   -47,
     -47,   -47,   -47,     0,   -47,   -47,   -47,   -46,   -46,   -46,
     -46,   -46,   -46,     0,     0,     0,   -46,   -46,   -46,   -46,
       0,   -46,   -46,   -46,   -45,   -45,   -45,   -45,   -45,   -45,
       0,     0,     0,   -45,   -45,   -45,   -45,     0,   -45,   -45,
     -45,   -33,   -33,   -33,   -33,   -33,   -33,     0,     0,     0,
     -33,   -33,   -33,   -33,     0,   194,   -33,   -33,   -36,   -36,
     -36,   -36,   -36,   -36,     0,     0,     0,   -36,   -36,   -36,
     -36,     0,   -36,   -36,   -36,   -42,   -42,   -42,   -42,   -42,
     -42,     0,     0,     0,   -42,   -42,   -42,   -42,     0,   -42,
     -42,   -42,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,
       0,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,   -44,
     -44,   -44,     0,   -44,   -44,   -44,   -37,   -37,   -37,   -37,
     -37,   -37,     0,     0,     0,   -37,   -37,   -37,   -37,     0,
     -37,   -37,   -37,   -27,   -27,   -27,   -27,   -27,   -27,     0,
       0,     0,   -27,   -27,   146,   147,     0,     0,   -27,   -27,
     -30,   -30,   -30,   -30,   -30,   -30,     0,     0,     0,   -30,
     -30,   -30,   -30,     0,     0,   -30,   -30,   -28,   -28,   -28,
     -28,   -28,   -28,     0,     0,     0,   -28,   -28,   146,   147,
       0,     0,   -28,   -28,   -29,   -29,   -29,   -29,   -29,   -29,
       0,     0,     0,   -29,   -29,   146,   147,     0,     0,   -29,
     -29,   -31,   -31,   -31,   -31,   -31,   -31,     0,     0,     0,
     -31,   -31,   -31,   -31,     0,     0,   -31,   -31,   -32,   -32,
     -32,   -32,   -32,   -32,     0,     0,     0,   -32,   -32,   -32,
     -32,     0,     0,   -32,   -32,   -34,   -34,   -34,   -34,   -34,
     -34,     0,     0,     0,   -34,   -34,   -34,   -34,     0,     0,
     -34,   -34,   -35,   -35,   -35,   -35,   -35,   -35,     0,     0,
       0,   -35,   -35,   -35,   -35,     0,     0,   -35,   -35,   -22,
     -22,   -22,   -22,   -22,   -22,     0,     0,     0,   144,   145,
       0,     0,     0,     0,   -22,   -22,   -23,   -23,   -23,   -23,
     -23,   -23,     0,     0,     0,   144,   145,     0,     0,     0,
       0,   -23,   -23,   -24,   -24,   -24,   -24,   -24,   -24,     0,
       0,     0,   144,   145,     0,     0,     0,     0,   -24,   -24,
     -25,   -25,   -25,   -25,   -25,   -25,     0,     0,     0,   144,
     145,     0,     0,     0,     0,   -25,   -25,   -26,   -26,   -26,
     -26,   -26,   -26,     0,     0,     0,   144,   145,     0,     0,
       0,     0,   -26,   -26,   -47,   -47,   -47,   -47,   -47,   -47,
       0,     0,   -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,
     -46,   -46,   -46,   -46,   -46,   -46,     0,     0,   -46,   -46,
     -46,   -46,   -46,     0,   -46,   -46,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,   -45,   -45,   -45,   -45,   -45,     0,
     -45,   -45,   -33,   -33,   -33,   -33,   -33,   -33,     0,     0,
     -33,   -33,   -33,   -33,   -33,     0,   121,   -33,   -36,   -36,
     -36,   -36,   -36,   -36,     0,     0,   -36,   -36,   -36,   -36,
     -36,     0,   -36,   -36,   -42,   -42,   -42,   -42,   -42,   -42,
       0,     0,   -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,
     -43,   -43,   -43,   -43,   -43,   -43,     0,     0,   -43,   -43,
     -43,   -43,   -43,     0,   -43,   -43,   -44,   -44,   -44,   -44,
     -44,   -44,     0,     0,   -44,   -44,   -44,   -44,   -44,     0,
     -44,   -44,   -37,   -37,   -37,   -37,   -37,   -37,     0,     0,
     -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,   -34,   -34,
     -34,   -34,   -34,   -34,     0,     0,   -34,   -34,   -34,   -34,
     -34,     0,     0,   -34,   -35,   -35,   -35,   -35,   -35,   -35,
       0,     0,   -35,   -35,   -35,   -35,   -35,     0,     0,   -35,
     -47,   -47,   -47,   -47,   -47,   -47,     0,     0,     0,   -47,
     -47,   -47,   -47,     0,   -47,   -47,   -46,   -46,   -46,   -46,
     -46,   -46,     0,     0,     0,   -46,   -46,   -46,   -46,     0,
     -46,   -46,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
       0,   -45,   -45,   -45,   -45,     0,   -45,   -45,   -33,   -33,
     -33,   -33,   -33,   -33,     0,     0,     0,   -33,   -33,   -33,
     -33,     0,   163,   -33,   -36,   -36,   -36,   -36,   -36,   -36,
       0,     0,     0,   -36,   -36,   -36,   -36,     0,   -36,   -36,
     -42,   -42,   -42,   -42,   -42,   -42,     0,     0,     0,   -42,
     -42,   -42,   -42,     0,   -42,   -42,   -43,   -43,   -43,   -43,
     -43,   -43,     0,     0,     0,   -43,   -43,   -43,   -43,     0,
     -43,   -43,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,
       0,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -37,   -37,
     -37,   -37,   -37,   -37,     0,     0,     0,   -37,   -37,   -37,
     -37,     0,   -37,   -37,   -27,   -27,   -27,   -27,   -27,   -27,
       0,     0,     0,   -27,   -27,   119,   120,     0,     0,   -27,
     -30,   -30,   -30,   -30,   -30,   -30,     0,     0,     0,   -30,
     -30,   -30,   -30,     0,     0,   -30,   -28,   -28,   -28,   -28,
     -28,   -28,     0,     0,     0,   -28,   -28,   119,   120,     0,
       0,   -28,   -29,   -29,   -29,   -29,   -29,   -29,     0,     0,
       0,   -29,   -29,   119,   120,     0,     0,   -29,   -31,   -31,
     -31,   -31,   -31,   -31,     0,     0,     0,   -31,   -31,   -31,
     -31,     0,     0,   -31,   -32,   -32,   -32,   -32,   -32,   -32,
       0,     0,     0,   -32,   -32,   -32,   -32,     0,     0,   -32,
     -34,   -34,   -34,   -34,   -34,   -34,     0,     0,     0,   -34,
     -34,   -34,   -34,     0,     0,   -34,   -35,   -35,   -35,   -35,
     -35,   -35,     0,     0,     0,   -35,   -35,   -35,   -35,     0,
       0,   -35,   -22,   -22,   -22,   -22,   -22,   -22,     0,     0,
       0,   117,   118,     0,     0,     0,     0,   -22,   -23,   -23,
     -23,   -23,   -23,   -23,     0,     0,     0,   117,   118,     0,
       0,     0,     0,   -23,   -24,   -24,   -24,   -24,   -24,   -24,
       0,     0,     0,   117,   118,     0,     0,     0,     0,   -24,
     -25,   -25,   -25,   -25,   -25,   -25,     0,     0,     0,   117,
     118,     0,     0,     0,     0,   -25,   -26,   -26,   -26,   -26,
     -26,   -26,     0,     0,     0,   117,   118,     0,     0,     0,
       0,   -26,   113,   114,   115,   116,   -21,   -21,     0,   -47,
     -47,   -47,   -47,   -47,   -47,     0,     0,   -21,   -47,   -47,
     -47,   -47,   -47,   -47,   -46,   -46,   -46,   -46,   -46,   -46,
       0,     0,     0,   -46,   -46,   -46,   -46,   -46,   -46,   -33,
     -33,   -33,   -33,   -33,   -33,     0,     0,     0,   -33,   -33,
     -33,   -33,   -33,    50,   -36,   -36,   -36,   -36,   -36,   -36,
       0,     0,     0,   -36,   -36,   -36,   -36,   -36,   -36,   -42,
     -42,   -42,   -42,   -42,   -42,     0,     0,     0,   -42,   -42,
     -42,   -42,   -42,   -42,   -43,   -43,   -43,   -43,   -43,   -43,
       0,     0,     0,   -43,   -43,   -43,   -43,   -43,   -43,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,   -44,
     -44,   -44,   -44,   -44,   -37,   -37,   -37,   -37,   -37,   -37,
       0,     0,     0,   -37,   -37,   -37,   -37,   -37,   -37,   -45,
     -45,   -45,   -45,   -45,   -45,     0,     0,     0,   -45,   -45,
     -45,   -45,   -45,   -45,   -27,   -27,   -27,   -27,   -27,   -27,
       0,     0,     0,   -27,   -27,    48,    49,   -27,   -30,   -30,
     -30,   -30,   -30,   -30,     0,     0,     0,   -30,   -30,   -30,
     -30,   -30,   -34,   -34,   -34,   -34,   -34,   -34,     0,     0,
       0,   -34,   -34,   -34,   -34,   -34,   -35,   -35,   -35,   -35,
     -35,   -35,     0,     0,     0,   -35,   -35,   -35,   -35,   -35,
     -28,   -28,   -28,   -28,   -28,   -28,     0,     0,     0,   -28,
     -28,    48,    49,   -28,   -29,   -29,   -29,   -29,   -29,   -29,
       0,     0,     0,   -29,   -29,    48,    49,   -29,   -31,   -31,
     -31,   -31,   -31,   -31,     0,     0,     0,   -31,   -31,   -31,
     -31,   -31,   -32,   -32,   -32,   -32,   -32,   -32,     0,     0,
       0,   -32,   -32,   -32,   -32,   -32,   -22,   -22,   -22,   -22,
     -22,   -22,     0,     0,     0,    46,    47,     0,     0,   -22,
     -23,   -23,   -23,   -23,   -23,   -23,     0,     0,     0,    46,
      47,     0,     0,   -23,   -24,   -24,   -24,   -24,   -24,   -24,
       0,     0,     0,    46,    47,     0,     0,   -24,   -25,   -25,
     -25,   -25,   -25,   -25,     0,     0,     0,    46,    47,     0,
       0,   -25,   -26,   -26,   -26,   -26,   -26,   -26,     0,     0,
       0,    46,    47,     0,     0,   -26,    42,    43,    44,    45,
     -19,   -19,    42,    43,    44,    45,   -20,   -20,     0,   -19,
       0,     0,     0,     0,     0,   -20,    42,    43,    44,    45,
     -21,   -21,     0,     0,     0,     0,     0,     0,     0,   -21
};

static const yytype_int16 yycheck[] =
{
       1,    85,   121,    14,    10,    11,     0,    14,     1,    20,
       3,     4,    13,    20,    12,    21,   100,    12,    19,    12,
      13,    19,     1,    16,     3,     4,    21,    20,    12,    14,
     149,    21,    22,    12,    13,    20,    50,    16,    10,    11,
      54,    20,    19,   127,   163,     3,     4,    19,    21,    50,
      51,     3,     4,    54,    12,    13,    54,    71,    16,     0,
      12,    13,    20,    21,    16,    10,    11,     0,    20,     0,
      71,    69,     5,    21,    19,   194,     6,     7,     8,     9,
      10,    11,    83,    84,    85,    21,   170,    85,    12,    10,
      11,    21,    93,    94,    21,    22,    14,    98,    99,   100,
      21,    22,   100,     0,    21,     0,     0,   121,     5,    21,
       5,     5,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    17,    18,    19,   125,   126,   127,     0,     0,   127,
      19,     0,     5,     5,   148,   149,     5,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   163,
      21,    22,    48,    49,    50,    21,    22,    21,    54,    21,
      22,    21,   163,    21,     3,     4,    21,   168,   169,   170,
      21,    22,   170,    12,    13,    71,    21,    16,    21,    22,
     194,    20,     3,     4,    21,    22,    21,    83,    84,    85,
      21,    12,    13,   194,    21,    16,     4,    93,    94,    20,
      -1,    -1,    98,    99,   100,    19,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    21,    22,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      54,    -1,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    71,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,   163,    -1,    83,
      84,    85,   168,   169,   170,    21,    22,    -1,    -1,    93,
      94,    -1,    -1,    -1,    98,    99,   100,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    54,    -1,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    71,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,   163,
      -1,    83,    84,    85,   168,   169,   170,    21,    22,    -1,
      -1,    93,    94,    -1,    -1,    -1,    98,    99,   100,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    54,    -1,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    71,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,   163,    -1,    83,    84,    85,   168,   169,   170,    21,
      -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    98,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    12,    -1,   125,   126,   127,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    12,
      -1,    -1,    -1,   163,    -1,    54,    19,    -1,   168,   169,
     170,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      69,    14,    15,    16,    17,    18,    39,    40,    21,    42,
      43,    44,    45,    -1,   194,    12,    85,     3,     4,    -1,
      -1,    54,    19,    -1,    93,    94,    12,    13,    -1,    -1,
      16,   100,    -1,    -1,    20,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    39,    40,   113,   114,   115,   116,   117,   118,
      -1,    -1,    85,     3,     4,    -1,    -1,    54,   127,    -1,
      93,    94,    12,    13,    -1,    -1,    16,   100,    -1,    -1,
      20,    -1,    69,    -1,    -1,   144,   145,    -1,    -1,    -1,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,   127,    -1,    93,    94,    -1,    -1,
      -1,   170,    -1,   100,    -1,    -1,    -1,   140,   141,   142,
     143,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    20,    21,    22,    -1,    -1,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   138,   139,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    20,    21,    22,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    17,    18,   170,    20,    21,    22,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      -1,    20,    21,    22,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    20,    21,
      22,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    -1,    20,    21,    22,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    16,    17,    18,    -1,    20,
      21,    22,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    17,    18,    -1,    20,    21,    22,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    21,    22,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,     6,     7,     8,     9,    10,    11,
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
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    21,    22,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    21,    22,     6,     7,     8,
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
      -1,    -1,    -1,    -1,    21,    22,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,
      -1,    21,    22,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    21,    22,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    21,    22,     6,     7,     8,     9,    10,    11,
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
      14,    15,    16,    17,    18,    -1,    20,    21,     6,     7,
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
      -1,    21,     6,     7,     8,     9,    10,    11,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    21,    15,    16,
      17,    18,    19,    20,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,     6,     7,     8,     9,    10,    11,
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
       0,     5,    24,    25,    26,    27,    28,    12,    29,    43,
       0,    25,    14,    20,     1,     3,     4,    13,    16,    20,
      34,    35,    36,    37,    38,    39,    42,    43,    44,    30,
      31,    43,    19,    38,    38,    32,    33,    34,    38,    10,
      11,    19,     6,     7,     8,     9,    15,    16,    17,    18,
      20,    22,    21,    21,    14,    35,    35,    36,    36,    36,
      36,    37,    37,    38,    38,    33,    40,    41,    43,    14,
      33,    22,    21,     1,    34,    33,    19,    19,    12,    12,
       3,     4,    12,    13,    16,    20,    35,    36,    37,    39,
      42,    43,    44,    10,    11,     3,     4,    12,    13,    16,
      20,    34,    35,    36,    37,    38,    39,    42,    43,    44,
      38,    38,    32,     6,     7,     8,     9,    15,    16,    17,
      18,    20,     3,     4,    12,    13,    16,    20,    35,    38,
      39,    42,    43,    44,    35,    38,    38,    32,    10,    11,
       6,     7,     8,     9,    15,    16,    17,    18,    14,    20,
      21,    36,    36,    36,    36,    37,    37,    38,    38,    41,
      38,    38,    32,    20,    21,     3,     4,    12,    13,    16,
      20,    35,    38,    39,    42,    43,    44,    35,    36,    36,
      36,    36,    37,    37,    38,    38,    33,    41,    21,    21,
      41,    38,    38,    32,    20,    21,    21,    21,    41,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    23,    24,    25,    25,    26,    26,    27,    27,    28,
      28,    29,    30,    30,    31,    31,    32,    33,    33,    34,
      34,    34,    35,    35,    35,    35,    35,    36,    36,    36,
      37,    37,    37,    38,    38,    38,    39,    39,    40,    40,
      41,    41,    42,    42,    42,    43,    44,    44
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     5,     5,     8,
       8,     1,     3,     1,     0,     1,     1,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     2,     2,     1,     4,     1,     3,
       1,     0,     1,     1,     3,     1,     1,     1
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
  case 7: /* declaration: LET declarator '=' eq_expr ';'  */
#line 57 "src/bison/math.y"
                                            {
        list_push(&root->children, ast_assign_init((yyvsp[-3].ast), (yyvsp[-1].ast)));
    }
#line 1617 "src/bison/grammar.c"
    break;

  case 8: /* declaration: LET declarator '=' error ';'  */
#line 60 "src/bison/math.y"
                                   {
        CIPL_PERROR_CURSOR("expected expression before ‘;’ token\n", error_cursor);
        yyerrok;
        ast_free((yyvsp[-3].ast));
    }
#line 1627 "src/bison/grammar.c"
    break;

  case 9: /* func_declaration: LET declarator '(' id_list.opt ')' '=' eq_expr ';'  */
#line 67 "src/bison/math.y"
                                                                     {
        Scope *func_scope = scope_init();
        scope_add_child(current_scope, func_scope);
        list_push(&scopes, func_scope);
        AST *func = ast_userfunc_init(func_scope, (yyvsp[-6].ast), ast_params_init((yyvsp[-4].list)));
        list_push(&root->children, ast_assign_init(func, (yyvsp[-1].ast)));
    }
#line 1639 "src/bison/grammar.c"
    break;

  case 10: /* func_declaration: LET declarator '(' id_list.opt ')' '=' error ';'  */
#line 74 "src/bison/math.y"
                                                       {
        CIPL_PERROR_CURSOR("expected expression before ‘;’ token\n", error_cursor);
        yyerrok;
        ast_free((yyvsp[-6].ast));
        list_free((yyvsp[-4].list), ast_child_free);
    }
#line 1650 "src/bison/grammar.c"
    break;

  case 12: /* id_list: id_list ',' id  */
#line 85 "src/bison/math.y"
                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 1656 "src/bison/grammar.c"
    break;

  case 13: /* id_list: id  */
#line 86 "src/bison/math.y"
         { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 1662 "src/bison/grammar.c"
    break;

  case 14: /* id_list.opt: %empty  */
#line 89 "src/bison/math.y"
                    { }
#line 1668 "src/bison/grammar.c"
    break;

  case 20: /* eq_expr: eq_expr EQ rel_expr  */
#line 101 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("==", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1674 "src/bison/grammar.c"
    break;

  case 21: /* eq_expr: eq_expr NE rel_expr  */
#line 102 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("!=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1680 "src/bison/grammar.c"
    break;

  case 23: /* rel_expr: rel_expr LT add_expr  */
#line 106 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1686 "src/bison/grammar.c"
    break;

  case 24: /* rel_expr: rel_expr LE add_expr  */
#line 107 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1692 "src/bison/grammar.c"
    break;

  case 25: /* rel_expr: rel_expr GT add_expr  */
#line 108 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1698 "src/bison/grammar.c"
    break;

  case 26: /* rel_expr: rel_expr GE add_expr  */
#line 109 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1704 "src/bison/grammar.c"
    break;

  case 28: /* add_expr: add_expr '+' mult_expr  */
#line 113 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('+', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1710 "src/bison/grammar.c"
    break;

  case 29: /* add_expr: add_expr '-' mult_expr  */
#line 114 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('-', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1716 "src/bison/grammar.c"
    break;

  case 31: /* mult_expr: mult_expr '*' cast_expr  */
#line 118 "src/bison/math.y"
                              { (yyval.ast) = ast_binop_init('*', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1722 "src/bison/grammar.c"
    break;

  case 32: /* mult_expr: mult_expr '/' cast_expr  */
#line 119 "src/bison/math.y"
                              { (yyval.ast) = ast_binop_init('/', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1728 "src/bison/grammar.c"
    break;

  case 34: /* cast_expr: '!' cast_expr  */
#line 123 "src/bison/math.y"
                    { (yyval.ast) = ast_uniop_init('!', (yyvsp[0].ast)); }
#line 1734 "src/bison/grammar.c"
    break;

  case 35: /* cast_expr: '-' cast_expr  */
#line 124 "src/bison/math.y"
                    { (yyval.ast) = ast_uniop_init('-', (yyvsp[0].ast)); }
#line 1740 "src/bison/grammar.c"
    break;

  case 41: /* arg_expr_list.opt: %empty  */
#line 136 "src/bison/math.y"
             { (yyval.ast) = NULL; }
#line 1746 "src/bison/grammar.c"
    break;

  case 44: /* primary_expr: '(' expression ')'  */
#line 141 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 1752 "src/bison/grammar.c"
    break;

  case 45: /* id: NAME  */
#line 144 "src/bison/math.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 1758 "src/bison/grammar.c"
    break;

  case 46: /* constant: NUMBER_REAL  */
#line 147 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 1764 "src/bison/grammar.c"
    break;

  case 47: /* constant: NUMBER_INT  */
#line 148 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 1770 "src/bison/grammar.c"
    break;


#line 1774 "src/bison/grammar.c"

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

#line 151 "src/bison/math.y"


void yyerror(char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    /* CIPL_PERROR("%s\n", s); */
}
