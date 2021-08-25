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
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"

    AST *root;
    Scope *current_scope;
    cursor_position error_cursor;
    StackNode *scopes;

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
  YYSYMBOL_22_ = 22,                       /* '{'  */
  YYSYMBOL_23_ = 23,                       /* '}'  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_YYACCEPT = 25,                  /* $accept  */
  YYSYMBOL_prog = 26,                      /* prog  */
  YYSYMBOL_external_declaration = 27,      /* external_declaration  */
  YYSYMBOL_declaration = 28,               /* declaration  */
  YYSYMBOL_func_declaration = 29,          /* func_declaration  */
  YYSYMBOL_compound_stmt = 30,             /* compound_stmt  */
  YYSYMBOL_31_block_item_list_opt = 31,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 32,           /* block_item_list  */
  YYSYMBOL_block_item = 33,                /* block_item  */
  YYSYMBOL_statement = 34,                 /* statement  */
  YYSYMBOL_declarator = 35,                /* declarator  */
  YYSYMBOL_id_list = 36,                   /* id_list  */
  YYSYMBOL_37_id_list_opt = 37,            /* id_list.opt  */
  YYSYMBOL_expression_stmt = 38,           /* expression_stmt  */
  YYSYMBOL_expression = 39,                /* expression  */
  YYSYMBOL_assign_expr = 40,               /* assign_expr  */
  YYSYMBOL_eq_expr = 41,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 42,                  /* rel_expr  */
  YYSYMBOL_add_expr = 43,                  /* add_expr  */
  YYSYMBOL_mult_expr = 44,                 /* mult_expr  */
  YYSYMBOL_cast_expr = 45,                 /* cast_expr  */
  YYSYMBOL_postfix_expr = 46,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 47,             /* arg_expr_list  */
  YYSYMBOL_48_arg_expr_list_opt = 48,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 49,              /* primary_expr  */
  YYSYMBOL_id = 50,                        /* id  */
  YYSYMBOL_constant = 51                   /* constant  */
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
#define YYLAST   2550

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

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
       0,    48,    48,    49,    52,    53,    56,    67,    81,    84,
      85,    88,    89,    92,    93,    96,    99,   100,   103,   104,
     107,   108,   111,   114,   117,   118,   124,   125,   126,   129,
     130,   131,   132,   133,   136,   137,   138,   141,   142,   143,
     146,   147,   148,   151,   152,   155,   156,   159,   160,   163,
     164,   165,   168,   175,   176
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
  "func_declaration", "compound_stmt", "block_item_list.opt",
  "block_item_list", "block_item", "statement", "declarator", "id_list",
  "id_list.opt", "expression_stmt", "expression", "assign_expr", "eq_expr",
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

#define YYPACT_NINF (-133)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,     4,     5,    48,    50,    56,    17,    27,    52,   100,
    -133,    60,    25,    68,    23,   118,    67,    33,    80,     8,
      40,    81,    29,    75,  2017,  2032,    31,    95,    95,   373,
      54,    46,   113,   185,   206,   240,    65,    73,    -2,  2511,
    2441,  2329,  2287,  2047,  2062,  2077,  2092,    93,  2301,  2315,
     130,    78,   266,   338,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,    95,   332,  2107,  2517,  2343,  2531,
    2455,  2469,  2483,  2497,  2357,  2371,  2385,  2399,   115,    85,
      89,   131,   422,  2122,   106,   132,    27,   135,   107,  2137,
     151,    27,   154,  1481,  1497,  1513,   373,   373,   373,   150,
      19,   389,  1929,  1801,  1625,  1529,  1545,  1561,  1577,   359,
    2152,  2167,  2182,   420,   420,   373,  2197,  2212,  2227,  2242,
     398,   518,   551,   422,   422,   373,    -9,   690,   995,  1253,
    1063,   671,   786,   895,   976,   164,   165,  1641,  1657,   166,
     573,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     373,   332,  2413,  2427,   170,   332,  1082,  1101,   171,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   422,
     332,   172,   156,  1593,   712,  1673,  1689,   573,   573,   373,
     542,  1817,  1705,  1721,  1737,  1753,  2009,  1945,  1961,  1977,
    1993,  1833,  1849,  1865,  1881,   173,   174,  2257,   175,  1019,
     496,   649,  1120,   575,   575,   373,   812,  1272,  1139,  1158,
    1177,  1196,   851,  1405,  1424,  1443,  1462,  1291,  1310,  1329,
    1348,   111,   178,  1897,  1913,   179,   332,  1609,  2272,  1367,
    1386,   191,   332,  1038,  1769,   192,  1215,   199,  1785,  1234
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,   204,   -18,  -133,  -133,  -133,  -133,   189,  -133,
      -4,  -133,  -133,  -133,   -22,   863,    57,   816,   810,   684,
     152,   305,  -133,  -132,   458,    -1,   611
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    23,    31,    32,    33,    34,
       8,    16,    17,    35,    36,    79,   126,   127,   128,   129,
      68,   116,    80,    81,   117,   118,   119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,   159,   160,    12,    30,    10,    87,    50,    54,    55,
       1,     1,   -24,    18,    30,   -24,     6,   -24,    21,   196,
      88,    45,    47,   198,     7,    92,    45,    45,   107,   140,
     141,    45,    24,    25,    26,    88,   -52,   -52,   222,    85,
     -24,    89,    27,    90,   -20,    28,    15,    86,    -3,    29,
      -5,    91,   -10,    -3,    20,    -5,    -4,   -13,   -13,   -13,
      -2,    -4,    22,    45,   133,    -2,   -13,   -13,    -6,    51,
     -13,    13,    14,    -6,   -13,    -7,   139,   -13,    -8,    38,
      -7,   133,   135,    -8,    53,    87,   100,   136,   -21,    38,
      87,    19,   -23,   154,   235,   107,   107,   107,    24,    25,
     237,   -19,   -18,   158,   -19,   -18,   -45,    89,    27,   -45,
     -47,    28,   109,    82,   107,    29,    24,    25,    26,   -16,
     -16,    38,   133,   133,   107,    89,    27,   -46,   -52,    28,
     -46,   -52,   -25,    29,   -25,   -25,    -9,   -17,   -17,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   107,
     133,    66,    83,   -52,   133,   100,   -16,   225,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   133,   133,
     -52,   -23,   100,   -16,    42,   -17,   184,   184,   107,    48,
      49,   104,   100,   231,    42,   171,   172,   173,   -12,   -12,
     -12,   197,   199,   -17,   -25,   227,   228,   -12,   -12,   233,
     234,   -12,   210,   210,   107,   -12,    11,   100,   -12,   -14,
     -14,   -14,   236,   238,    76,    77,    42,   130,   -14,   -14,
     239,    52,   -14,     0,     0,   133,   -14,     0,     0,   -14,
       0,   133,     0,     0,   130,     0,   100,     0,     0,     0,
       0,     0,     0,   -15,   -15,   -15,     0,     0,   137,   138,
     104,     0,   -15,   -15,     0,     0,   -15,     0,     0,     0,
     -15,     0,   100,   -15,     0,   152,   153,   104,     0,   -11,
     -11,   -11,     0,     0,     0,   156,   157,   104,   -11,   -11,
       0,     0,   -11,     0,     0,     0,   -11,     0,     0,   -11,
       0,     0,   181,   181,   181,   181,   181,   181,   181,   181,
     193,   194,   104,   130,     0,     0,     0,   130,     0,     0,
       0,   207,   207,   207,   207,   207,   207,   207,   207,   219,
     220,   130,   130,     0,     0,     0,     0,    43,     0,   223,
     224,   104,    43,    43,   105,   120,   121,    43,     0,     0,
       0,   -22,   -22,   -22,   122,   123,     0,     0,   124,     0,
     -22,   -22,   125,   -48,   -22,   229,   230,   104,   -22,     0,
       0,   -22,    -6,    -6,    -6,     0,     0,     0,     0,    43,
     131,    -6,    -6,     0,     0,    -6,    93,    94,   130,    -6,
       0,     0,    -6,     0,   130,    95,    96,   131,     0,    97,
       0,     0,     0,    98,     0,   142,   143,   144,   145,   -26,
     -26,   105,   105,   105,   -54,   -54,   -54,   -54,   -54,   -54,
     -26,     0,   -54,   -54,   -54,   -54,   -54,     0,   -54,   -54,
     105,     0,   -54,   110,   111,   120,   121,     0,   131,   131,
     105,     0,   112,   113,   122,   123,   114,     0,   124,     0,
     115,     0,   125,     0,     0,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   105,   131,     0,     0,     0,
     131,     0,     0,     0,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   131,   131,     0,     0,     0,     0,
      44,     0,   182,   182,   105,    44,    44,   106,     0,     0,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -54,   -54,   -54,   -54,   -54,   -54,   208,   208,
     105,   -54,   -54,   -54,   -54,     0,   -54,   -54,     0,     0,
     -54,     0,    44,   132,   -53,   -53,   -53,   -53,   -53,   -53,
       0,   131,   -53,   -53,   -53,   -53,   -53,   131,   -53,   -53,
     132,     0,   -53,     0,     0,     0,     0,     0,   142,   143,
     144,   145,   -27,   -27,   106,   106,   106,   -52,   -52,   -52,
     -52,   -52,   -52,   -27,     0,   -52,   -52,   -52,   -52,   -52,
       0,   -52,   -52,   106,     0,   -52,   174,   175,   200,   201,
       0,   132,   132,   106,     0,   176,   177,   202,   203,   178,
       0,   204,     0,   179,     0,   205,     0,     0,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   106,   132,
       0,     0,     0,   132,     0,     0,     0,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   132,   132,     0,
       0,     0,     0,    46,     0,   183,   183,   106,    46,    46,
     108,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -53,   -53,   -53,   -53,   -53,
     -53,   209,   209,   106,   -53,   -53,   -53,   -53,     0,   -53,
     -53,     0,     0,   -53,     0,    46,   134,   -40,   -40,   -40,
     -40,   -40,   -40,     0,   132,   -40,   -40,   -40,   -40,   -40,
     132,   170,   -40,   134,     0,   -40,   161,   162,   163,   164,
     -26,   -26,     0,     0,     0,     0,    41,   108,   108,   108,
       0,   -26,     0,   103,   -26,     0,    41,     0,   -54,   -54,
     -54,   -54,   -54,   -54,     0,     0,   108,   -54,   -54,   -54,
     -54,     0,   -54,   -54,   134,   134,   108,     0,    41,    41,
      41,    41,    41,    41,    74,    75,     0,     0,    41,     0,
       0,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   108,   134,     0,     0,     0,   134,     0,     0,     0,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     134,   134,   103,     0,     0,     0,     0,     0,   185,   185,
     108,     0,   -43,   -43,   -43,   -43,   -43,   -43,     0,   103,
     -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,     0,   103,
     -43,     0,     0,     0,   211,   211,   108,     0,   161,   162,
     163,   164,   -27,   -27,   103,   103,   103,   103,   103,   103,
     191,   192,    40,   -27,   103,     0,   -27,   134,    39,   102,
       0,     0,    40,   134,     0,   101,     0,     0,    39,   217,
     218,     0,     0,     0,     0,     0,     0,   161,   162,   163,
     164,   -28,   -28,   103,    40,    40,    70,    71,    72,    73,
      67,    69,   -28,     0,    40,   -28,     0,     0,     0,     0,
      39,     0,     0,     0,     0,    37,     0,     0,     0,   103,
       0,     0,    99,     0,     0,    37,     0,     0,     0,     0,
       0,   -49,   -49,   -49,   -49,   -49,   -49,     0,   102,   -49,
     -49,   -49,   -49,   -49,   101,   -49,   -49,     0,     0,   -49,
       0,     0,     0,     0,     0,   102,     0,    78,     0,     0,
       0,   101,     0,     0,     0,   102,     0,     0,     0,     0,
       0,   101,     0,     0,     0,    84,     0,     0,     0,     0,
     102,   102,   187,   188,   189,   190,   180,   186,     0,     0,
     102,    99,     0,     0,     0,     0,   101,     0,     0,     0,
       0,   213,   214,   215,   216,   206,   212,     0,    99,     0,
       0,     0,   -50,   -50,   -50,   -50,   -50,   -50,    99,   102,
     -50,   -50,   -50,   -50,   -50,   101,   -50,   -50,     0,     0,
     -50,   -29,   -29,   -29,   -29,   -29,   -29,     0,     0,     0,
     165,   166,     0,   195,     0,   102,   -29,     0,     0,   -29,
       0,   101,     0,     0,     0,   -51,   -51,   -51,   -51,   -51,
     -51,     0,   221,   -51,   -51,   -51,   -51,   -51,     0,   -51,
     -51,     0,    99,   -51,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,   -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,
       0,     0,   -44,     0,     0,     0,     0,     0,    99,   -37,
     -37,   -37,   -37,   -37,   -37,     0,     0,   169,   -37,   -37,
     -37,   -37,     0,     0,   -37,     0,     0,   -37,   -41,   -41,
     -41,   -41,   -41,   -41,     0,     0,   -41,   -41,   -41,   -41,
     -41,     0,     0,   -41,     0,     0,   -41,   -42,   -42,   -42,
     -42,   -42,   -42,     0,     0,   -42,   -42,   -42,   -42,   -42,
       0,     0,   -42,     0,     0,   -42,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,     0,   -52,   -52,   -52,   -52,     0,
     -52,   -52,     0,     0,   -52,   -40,   -40,   -40,   -40,   -40,
     -40,     0,     0,     0,   -40,   -40,   -40,   -40,     0,   232,
     -40,     0,     0,   -40,   -43,   -43,   -43,   -43,   -43,   -43,
       0,     0,     0,   -43,   -43,   -43,   -43,     0,   -43,   -43,
       0,     0,   -43,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,     0,   -49,   -49,   -49,   -49,     0,   -49,   -49,     0,
       0,   -49,   -50,   -50,   -50,   -50,   -50,   -50,     0,     0,
       0,   -50,   -50,   -50,   -50,     0,   -50,   -50,     0,     0,
     -50,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,
     -51,   -51,   -51,   -51,     0,   -51,   -51,     0,     0,   -51,
     -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,
     -44,   -44,   -44,     0,   -44,   -44,     0,     0,   -44,   -34,
     -34,   -34,   -34,   -34,   -34,     0,     0,     0,   -34,   -34,
     167,   168,     0,     0,   -34,     0,     0,   -34,   -37,   -37,
     -37,   -37,   -37,   -37,     0,     0,     0,   -37,   -37,   -37,
     -37,     0,     0,   -37,     0,     0,   -37,   -35,   -35,   -35,
     -35,   -35,   -35,     0,     0,     0,   -35,   -35,   167,   168,
       0,     0,   -35,     0,     0,   -35,   -36,   -36,   -36,   -36,
     -36,   -36,     0,     0,     0,   -36,   -36,   167,   168,     0,
       0,   -36,     0,     0,   -36,   -38,   -38,   -38,   -38,   -38,
     -38,     0,     0,     0,   -38,   -38,   -38,   -38,     0,     0,
     -38,     0,     0,   -38,   -39,   -39,   -39,   -39,   -39,   -39,
       0,     0,     0,   -39,   -39,   -39,   -39,     0,     0,   -39,
       0,     0,   -39,   -41,   -41,   -41,   -41,   -41,   -41,     0,
       0,     0,   -41,   -41,   -41,   -41,     0,     0,   -41,     0,
       0,   -41,   -42,   -42,   -42,   -42,   -42,   -42,     0,     0,
       0,   -42,   -42,   -42,   -42,     0,     0,   -42,     0,     0,
     -42,   -30,   -30,   -30,   -30,   -30,   -30,     0,     0,     0,
     165,   166,     0,     0,     0,     0,   -30,     0,     0,   -30,
     -31,   -31,   -31,   -31,   -31,   -31,     0,     0,     0,   165,
     166,     0,     0,     0,     0,   -31,     0,     0,   -31,   -32,
     -32,   -32,   -32,   -32,   -32,     0,     0,     0,   165,   166,
       0,     0,     0,     0,   -32,     0,     0,   -32,   -33,   -33,
     -33,   -33,   -33,   -33,     0,     0,     0,   165,   166,     0,
       0,     0,     0,   -33,     0,     0,   -33,   -54,   -54,   -54,
     -54,   -54,   -54,     0,     0,   -54,   -54,   -54,   -54,   -54,
       0,   -54,   -54,   -53,   -53,   -53,   -53,   -53,   -53,     0,
       0,   -53,   -53,   -53,   -53,   -53,     0,   -53,   -53,   -52,
     -52,   -52,   -52,   -52,   -52,     0,     0,   -52,   -52,   -52,
     -52,   -52,     0,   -52,   -52,   -40,   -40,   -40,   -40,   -40,
     -40,     0,     0,   -40,   -40,   -40,   -40,   -40,     0,   151,
     -40,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,   -43,
     -43,   -43,   -43,   -43,     0,   -43,   -43,   -49,   -49,   -49,
     -49,   -49,   -49,     0,     0,   -49,   -49,   -49,   -49,   -49,
       0,   -49,   -49,   -50,   -50,   -50,   -50,   -50,   -50,     0,
       0,   -50,   -50,   -50,   -50,   -50,     0,   -50,   -50,   -51,
     -51,   -51,   -51,   -51,   -51,     0,     0,   -51,   -51,   -51,
     -51,   -51,     0,   -51,   -51,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,   -44,   -44,   -44,   -44,   -44,     0,   -44,
     -44,   -37,   -37,   -37,   -37,   -37,   -37,     0,     0,   150,
     -37,   -37,   -37,   -37,     0,     0,   -37,   -41,   -41,   -41,
     -41,   -41,   -41,     0,     0,   -41,   -41,   -41,   -41,   -41,
       0,     0,   -41,   -42,   -42,   -42,   -42,   -42,   -42,     0,
       0,   -42,   -42,   -42,   -42,   -42,     0,     0,   -42,   -53,
     -53,   -53,   -53,   -53,   -53,     0,     0,     0,   -53,   -53,
     -53,   -53,     0,   -53,   -53,   -52,   -52,   -52,   -52,   -52,
     -52,     0,     0,     0,   -52,   -52,   -52,   -52,     0,   -52,
     -52,   -40,   -40,   -40,   -40,   -40,   -40,     0,     0,     0,
     -40,   -40,   -40,   -40,     0,   226,   -40,   -43,   -43,   -43,
     -43,   -43,   -43,     0,     0,     0,   -43,   -43,   -43,   -43,
       0,   -43,   -43,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,     0,   -49,   -49,   -49,   -49,     0,   -49,   -49,   -50,
     -50,   -50,   -50,   -50,   -50,     0,     0,     0,   -50,   -50,
     -50,   -50,     0,   -50,   -50,   -51,   -51,   -51,   -51,   -51,
     -51,     0,     0,     0,   -51,   -51,   -51,   -51,     0,   -51,
     -51,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,
     -44,   -44,   -44,   -44,     0,   -44,   -44,   -34,   -34,   -34,
     -34,   -34,   -34,     0,     0,     0,   -34,   -34,   148,   149,
       0,     0,   -34,   -37,   -37,   -37,   -37,   -37,   -37,     0,
       0,     0,   -37,   -37,   -37,   -37,     0,     0,   -37,   -35,
     -35,   -35,   -35,   -35,   -35,     0,     0,     0,   -35,   -35,
     148,   149,     0,     0,   -35,   -36,   -36,   -36,   -36,   -36,
     -36,     0,     0,     0,   -36,   -36,   148,   149,     0,     0,
     -36,   -38,   -38,   -38,   -38,   -38,   -38,     0,     0,     0,
     -38,   -38,   -38,   -38,     0,     0,   -38,   -39,   -39,   -39,
     -39,   -39,   -39,     0,     0,     0,   -39,   -39,   -39,   -39,
       0,     0,   -39,   -41,   -41,   -41,   -41,   -41,   -41,     0,
       0,     0,   -41,   -41,   -41,   -41,     0,     0,   -41,   -42,
     -42,   -42,   -42,   -42,   -42,     0,     0,     0,   -42,   -42,
     -42,   -42,     0,     0,   -42,   -29,   -29,   -29,   -29,   -29,
     -29,     0,     0,     0,   146,   147,     0,     0,     0,     0,
     -29,   -30,   -30,   -30,   -30,   -30,   -30,     0,     0,     0,
     146,   147,     0,     0,     0,     0,   -30,   -31,   -31,   -31,
     -31,   -31,   -31,     0,     0,     0,   146,   147,     0,     0,
       0,     0,   -31,   -32,   -32,   -32,   -32,   -32,   -32,     0,
       0,     0,   146,   147,     0,     0,     0,     0,   -32,   -33,
     -33,   -33,   -33,   -33,   -33,     0,     0,     0,   146,   147,
       0,     0,     0,     0,   -33,   142,   143,   144,   145,   -28,
     -28,     0,     0,   -54,   -54,   -54,   -54,   -54,   -54,     0,
     -28,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -53,   -53,
     -53,   -53,   -53,   -53,     0,     0,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -40,   -40,   -40,   -40,   -40,   -40,     0,
       0,   -40,   -40,   -40,   -40,   -40,   -40,    65,   -43,   -43,
     -43,   -43,   -43,   -43,     0,     0,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -51,   -51,   -51,   -51,   -51,   -51,     0,
       0,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -44,   -44,
     -44,   -44,   -44,   -44,     0,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -52,   -52,   -52,   -52,   -52,   -52,     0,
       0,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -54,   -54,
     -54,   -54,   -54,   -54,     0,     0,     0,   -54,   -54,   -54,
     -54,   -54,   -54,   -53,   -53,   -53,   -53,   -53,   -53,     0,
       0,     0,   -53,   -53,   -53,   -53,   -53,   -53,   -52,   -52,
     -52,   -52,   -52,   -52,     0,     0,     0,   -52,   -52,   -52,
     -52,   -52,   -52,   -40,   -40,   -40,   -40,   -40,   -40,     0,
       0,     0,   -40,   -40,   -40,   -40,   -40,   155,   -43,   -43,
     -43,   -43,   -43,   -43,     0,     0,     0,   -43,   -43,   -43,
     -43,   -43,   -43,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,     0,   -49,   -49,   -49,   -49,   -49,   -49,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,     0,   -50,   -50,   -50,
     -50,   -50,   -50,   -51,   -51,   -51,   -51,   -51,   -51,     0,
       0,     0,   -51,   -51,   -51,   -51,   -51,   -51,   -44,   -44,
     -44,   -44,   -44,   -44,     0,     0,     0,   -44,   -44,   -44,
     -44,   -44,   -44,   -37,   -37,   -37,   -37,   -37,   -37,     0,
       0,    64,   -37,   -37,   -37,   -37,   -37,   -41,   -41,   -41,
     -41,   -41,   -41,     0,     0,   -41,   -41,   -41,   -41,   -41,
     -41,   -42,   -42,   -42,   -42,   -42,   -42,     0,     0,   -42,
     -42,   -42,   -42,   -42,   -42,   -34,   -34,   -34,   -34,   -34,
     -34,     0,     0,     0,   -34,   -34,    62,    63,   -34,   -37,
     -37,   -37,   -37,   -37,   -37,     0,     0,     0,   -37,   -37,
     -37,   -37,   -37,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,     0,   -35,   -35,    62,    63,   -35,   -36,   -36,   -36,
     -36,   -36,   -36,     0,     0,     0,   -36,   -36,    62,    63,
     -36,   -38,   -38,   -38,   -38,   -38,   -38,     0,     0,     0,
     -38,   -38,   -38,   -38,   -38,   -39,   -39,   -39,   -39,   -39,
     -39,     0,     0,     0,   -39,   -39,   -39,   -39,   -39,   -41,
     -41,   -41,   -41,   -41,   -41,     0,     0,     0,   -41,   -41,
     -41,   -41,   -41,   -42,   -42,   -42,   -42,   -42,   -42,     0,
       0,     0,   -42,   -42,   -42,   -42,   -42,   -29,   -29,   -29,
     -29,   -29,   -29,     0,     0,     0,    60,    61,     0,     0,
     -29,   -30,   -30,   -30,   -30,   -30,   -30,     0,     0,     0,
      60,    61,     0,     0,   -30,   -31,   -31,   -31,   -31,   -31,
     -31,     0,     0,     0,    60,    61,     0,     0,   -31,   -32,
     -32,   -32,   -32,   -32,   -32,     0,     0,     0,    60,    61,
       0,     0,   -32,   -33,   -33,   -33,   -33,   -33,   -33,     0,
       0,     0,    60,    61,     0,     0,   -33,    56,    57,    58,
      59,   -26,   -26,    56,    57,    58,    59,   -27,   -27,     0,
     -26,     0,     0,     0,     0,     0,   -27,    56,    57,    58,
      59,   -28,   -28,     0,     0,     0,     0,     0,     0,     0,
     -28
};

static const yytype_int16 yycheck[] =
{
       1,    10,    11,     7,    22,     0,     7,    29,    10,    11,
       5,     5,    21,    14,    32,    24,    12,    19,    19,   151,
      12,    22,    26,   155,    20,    26,    27,    28,    29,    10,
      11,    32,     3,     4,     5,    12,    19,    20,   170,    12,
      21,    12,    13,    12,    21,    16,    21,    20,     0,    20,
       0,    20,    23,     5,    21,     5,     0,     3,     4,     5,
       0,     5,    22,    64,    65,     5,    12,    13,     0,    23,
      16,    19,    20,     5,    20,     0,    98,    23,     0,    22,
       5,    82,    86,     5,    19,    86,    29,    91,    21,    32,
      91,    24,    19,   115,   226,    96,    97,    98,     3,     4,
     232,    21,    21,   125,    24,    24,    21,    12,    13,    24,
      21,    16,    19,    24,   115,    20,     3,     4,     5,    19,
      20,    64,   123,   124,   125,    12,    13,    21,    21,    16,
      24,    24,    21,    20,    19,    24,    23,    19,    20,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,    21,    21,    21,   155,    98,    21,   179,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      19,    21,   115,    19,    22,    19,   177,   178,   179,    27,
      28,    29,   125,   205,    32,    21,    21,    21,     3,     4,
       5,    21,    21,    21,    21,    21,    21,    12,    13,    21,
      21,    16,   203,   204,   205,    20,     2,   150,    23,     3,
       4,     5,    21,    21,    62,    63,    64,    65,    12,    13,
      21,    32,    16,    -1,    -1,   226,    20,    -1,    -1,    23,
      -1,   232,    -1,    -1,    82,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    96,    97,
      98,    -1,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,
      20,    -1,   205,    23,    -1,   113,   114,   115,    -1,     3,
       4,     5,    -1,    -1,    -1,   123,   124,   125,    12,    13,
      -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    -1,    23,
      -1,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,
      -1,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    -1,    -1,    -1,    22,    -1,   177,
     178,   179,    27,    28,    29,     3,     4,    32,    -1,    -1,
      -1,     3,     4,     5,    12,    13,    -1,    -1,    16,    -1,
      12,    13,    20,    21,    16,   203,   204,   205,    20,    -1,
      -1,    23,     3,     4,     5,    -1,    -1,    -1,    -1,    64,
      65,    12,    13,    -1,    -1,    16,     3,     4,   226,    20,
      -1,    -1,    23,    -1,   232,    12,    13,    82,    -1,    16,
      -1,    -1,    -1,    20,    -1,     6,     7,     8,     9,    10,
      11,    96,    97,    98,     6,     7,     8,     9,    10,    11,
      21,    -1,    14,    15,    16,    17,    18,    -1,    20,    21,
     115,    -1,    24,     3,     4,     3,     4,    -1,   123,   124,
     125,    -1,    12,    13,    12,    13,    16,    -1,    16,    -1,
      20,    -1,    20,    -1,    -1,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
     155,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,    -1,    -1,    -1,
      22,    -1,   177,   178,   179,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,   203,   204,
     205,    15,    16,    17,    18,    -1,    20,    21,    -1,    -1,
      24,    -1,    64,    65,     6,     7,     8,     9,    10,    11,
      -1,   226,    14,    15,    16,    17,    18,   232,    20,    21,
      82,    -1,    24,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    96,    97,    98,     6,     7,     8,
       9,    10,    11,    21,    -1,    14,    15,    16,    17,    18,
      -1,    20,    21,   115,    -1,    24,     3,     4,     3,     4,
      -1,   123,   124,   125,    -1,    12,    13,    12,    13,    16,
      -1,    16,    -1,    20,    -1,    20,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      -1,    -1,    -1,   155,    -1,    -1,    -1,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,    22,    -1,   177,   178,   179,    27,    28,
      29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,   203,   204,   205,    15,    16,    17,    18,    -1,    20,
      21,    -1,    -1,    24,    -1,    64,    65,     6,     7,     8,
       9,    10,    11,    -1,   226,    14,    15,    16,    17,    18,
     232,    20,    21,    82,    -1,    24,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    22,    96,    97,    98,
      -1,    21,    -1,    29,    24,    -1,    32,    -1,     6,     7,
       8,     9,    10,    11,    -1,    -1,   115,    15,    16,    17,
      18,    -1,    20,    21,   123,   124,   125,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    64,    -1,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,   155,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    98,    -1,    -1,    -1,    -1,    -1,   177,   178,
     179,    -1,     6,     7,     8,     9,    10,    11,    -1,   115,
      14,    15,    16,    17,    18,    -1,    20,    21,    -1,   125,
      24,    -1,    -1,    -1,   203,   204,   205,    -1,     6,     7,
       8,     9,    10,    11,   140,   141,   142,   143,   144,   145,
     146,   147,    22,    21,   150,    -1,    24,   226,    22,    29,
      -1,    -1,    32,   232,    -1,    29,    -1,    -1,    32,   165,
     166,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,   179,    54,    55,    56,    57,    58,    59,
      54,    55,    21,    -1,    64,    24,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,   205,
      -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    98,    14,
      15,    16,    17,    18,    98,    20,    21,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    64,    -1,    -1,
      -1,   115,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,   125,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
     140,   141,   142,   143,   144,   145,   140,   141,    -1,    -1,
     150,    98,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,   161,   162,   163,   164,   159,   160,    -1,   115,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,   125,   179,
      14,    15,    16,    17,    18,   179,    20,    21,    -1,    -1,
      24,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    -1,   150,    -1,   205,    21,    -1,    -1,    24,
      -1,   205,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,   169,    14,    15,    16,    17,    18,    -1,    20,
      21,    -1,   179,    24,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,   205,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    21,    -1,    -1,    24,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    -1,    24,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      -1,    -1,    21,    -1,    -1,    24,     6,     7,     8,     9,
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
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    24,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    24,     6,     7,     8,
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
      -1,    -1,    21,     6,     7,     8,     9,    10,    11,    -1,
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
      11,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      21,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    21,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    21,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    21,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    21,     6,     7,     8,     9,    10,
      11,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      21,    14,    15,    16,    17,    18,    19,    20,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,     6,     7,
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
      18,    19,    20,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    15,    16,    17,    18,    19,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    15,    16,    17,    18,
      19,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      15,    16,    17,    18,    19,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    18,    19,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    -1,    -1,
      19,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    -1,    -1,    19,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    -1,    -1,    19,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      -1,    -1,    19,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    -1,    -1,    19,     6,     7,     8,
       9,    10,    11,     6,     7,     8,     9,    10,    11,    -1,
      19,    -1,    -1,    -1,    -1,    -1,    19,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    26,    27,    28,    29,    12,    20,    35,    50,
       0,    27,    35,    19,    20,    21,    36,    37,    50,    24,
      21,    50,    22,    30,     3,     4,     5,    13,    16,    20,
      28,    31,    32,    33,    34,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    49,    50,    51,    35,    45,    45,
      39,    23,    33,    19,    10,    11,     6,     7,     8,     9,
      15,    16,    17,    18,    14,    20,    21,    42,    45,    42,
      43,    43,    43,    43,    44,    44,    45,    45,    40,    40,
      47,    48,    24,    21,    40,    12,    20,    50,    12,    12,
      12,    20,    50,     3,     4,    12,    13,    16,    20,    40,
      41,    42,    43,    44,    45,    46,    49,    50,    51,    19,
       3,     4,    12,    13,    16,    20,    46,    49,    50,    51,
       3,     4,    12,    13,    16,    20,    41,    42,    43,    44,
      45,    46,    49,    50,    51,    35,    35,    45,    45,    39,
      10,    11,     6,     7,     8,     9,    15,    16,    17,    18,
      14,    20,    45,    45,    39,    20,    45,    45,    39,    10,
      11,     6,     7,     8,     9,    15,    16,    17,    18,    14,
      20,    21,    21,    21,     3,     4,    12,    13,    16,    20,
      42,    45,    46,    49,    50,    51,    42,    43,    43,    43,
      43,    44,    44,    45,    45,    40,    48,    21,    48,    21,
       3,     4,    12,    13,    16,    20,    42,    45,    46,    49,
      50,    51,    42,    43,    43,    43,    43,    44,    44,    45,
      45,    40,    48,    45,    45,    39,    20,    21,    21,    45,
      45,    39,    20,    21,    21,    48,    21,    48,    21,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    25,    26,    26,    27,    27,    28,    29,    30,    31,
      31,    32,    32,    33,    33,    34,    35,    35,    36,    36,
      37,    37,    38,    39,    40,    40,    41,    41,    41,    42,
      42,    42,    42,    42,    43,    43,    43,    44,    44,    44,
      45,    45,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    49,    50,    51,    51
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     3,     6,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     3,     3,     1,
       0,     1,     2,     1,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     2,     2,     1,     4,     1,     3,     1,     0,     1,
       1,     3,     1,     1,     1
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
#line 48 "src/bison/math.y"
                                { list_push(&root->children, (yyvsp[0].ast)); }
#line 1726 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 49 "src/bison/math.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 1732 "src/bison/grammar.c"
    break;

  case 6: /* declaration: LET declarator ';'  */
#line 56 "src/bison/math.y"
                                {
        printf("found a variable\n");
        (yyval.ast) = ast_declaration_init((yyvsp[-1].ast));
    }
#line 1741 "src/bison/grammar.c"
    break;

  case 7: /* func_declaration: LET declarator '(' id_list.opt ')' compound_stmt  */
#line 67 "src/bison/math.y"
                                                                   {
        printf("found a function\n");
        Scope *parent_scope = stack_peek(&scopes);
        symbol_table_insert(parent_scope->symbol_table, (yyvsp[-4].ast)->value.symref->symbol->name);
        (yyval.ast) = ast_userfunc_init(scope_add(parent_scope), (yyvsp[-4].ast), ast_params_init((yyvsp[-2].list)), (yyvsp[0].ast));
    }
#line 1752 "src/bison/grammar.c"
    break;

  case 8: /* compound_stmt: '{' block_item_list.opt '}'  */
#line 81 "src/bison/math.y"
                                           { (yyval.ast) = ast_blockitems_init((yyvsp[-1].list)); }
#line 1758 "src/bison/grammar.c"
    break;

  case 9: /* block_item_list.opt: block_item_list  */
#line 84 "src/bison/math.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 1764 "src/bison/grammar.c"
    break;

  case 10: /* block_item_list.opt: %empty  */
#line 85 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 1770 "src/bison/grammar.c"
    break;

  case 11: /* block_item_list: block_item_list block_item  */
#line 88 "src/bison/math.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 1776 "src/bison/grammar.c"
    break;

  case 12: /* block_item_list: block_item  */
#line 89 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 1782 "src/bison/grammar.c"
    break;

  case 13: /* block_item: declaration  */
#line 92 "src/bison/math.y"
                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1788 "src/bison/grammar.c"
    break;

  case 17: /* declarator: '(' declarator ')'  */
#line 100 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 1794 "src/bison/grammar.c"
    break;

  case 18: /* id_list: id_list ',' id  */
#line 103 "src/bison/math.y"
                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 1800 "src/bison/grammar.c"
    break;

  case 19: /* id_list: id  */
#line 104 "src/bison/math.y"
         { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 1806 "src/bison/grammar.c"
    break;

  case 20: /* id_list.opt: %empty  */
#line 107 "src/bison/math.y"
                    { (yyval.list) = NULL; }
#line 1812 "src/bison/grammar.c"
    break;

  case 25: /* assign_expr: cast_expr '=' assign_expr  */
#line 118 "src/bison/math.y"
                                {
        printf("found assignment\n");
        (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 1821 "src/bison/grammar.c"
    break;

  case 27: /* eq_expr: eq_expr EQ rel_expr  */
#line 125 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("==", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1827 "src/bison/grammar.c"
    break;

  case 28: /* eq_expr: eq_expr NE rel_expr  */
#line 126 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("!=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1833 "src/bison/grammar.c"
    break;

  case 30: /* rel_expr: rel_expr LT add_expr  */
#line 130 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1839 "src/bison/grammar.c"
    break;

  case 31: /* rel_expr: rel_expr LE add_expr  */
#line 131 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1845 "src/bison/grammar.c"
    break;

  case 32: /* rel_expr: rel_expr GT add_expr  */
#line 132 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1851 "src/bison/grammar.c"
    break;

  case 33: /* rel_expr: rel_expr GE add_expr  */
#line 133 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1857 "src/bison/grammar.c"
    break;

  case 35: /* add_expr: add_expr '+' mult_expr  */
#line 137 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('+', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1863 "src/bison/grammar.c"
    break;

  case 36: /* add_expr: add_expr '-' mult_expr  */
#line 138 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('-', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1869 "src/bison/grammar.c"
    break;

  case 38: /* mult_expr: mult_expr '*' cast_expr  */
#line 142 "src/bison/math.y"
                              { (yyval.ast) = ast_binop_init('*', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1875 "src/bison/grammar.c"
    break;

  case 39: /* mult_expr: mult_expr '/' cast_expr  */
#line 143 "src/bison/math.y"
                              { (yyval.ast) = ast_binop_init('/', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1881 "src/bison/grammar.c"
    break;

  case 41: /* cast_expr: '!' cast_expr  */
#line 147 "src/bison/math.y"
                    { (yyval.ast) = ast_uniop_init('!', (yyvsp[0].ast)); }
#line 1887 "src/bison/grammar.c"
    break;

  case 42: /* cast_expr: '-' cast_expr  */
#line 148 "src/bison/math.y"
                    { (yyval.ast) = ast_uniop_init('-', (yyvsp[0].ast)); }
#line 1893 "src/bison/grammar.c"
    break;

  case 48: /* arg_expr_list.opt: %empty  */
#line 160 "src/bison/math.y"
             { (yyval.ast) = NULL; }
#line 1899 "src/bison/grammar.c"
    break;

  case 51: /* primary_expr: '(' expression ')'  */
#line 165 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 1905 "src/bison/grammar.c"
    break;

  case 52: /* id: NAME  */
#line 168 "src/bison/math.y"
         {
        Scope *scope = stack_peek(&scopes);
        (yyval.ast) = ast_symref_init(symbol_init((yyvsp[0].identifier), scope->index, cursor));
        free((yyvsp[0].identifier));
    }
#line 1915 "src/bison/grammar.c"
    break;

  case 53: /* constant: NUMBER_REAL  */
#line 175 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 1921 "src/bison/grammar.c"
    break;

  case 54: /* constant: NUMBER_INT  */
#line 176 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 1927 "src/bison/grammar.c"
    break;


#line 1931 "src/bison/grammar.c"

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

#line 179 "src/bison/math.y"


void yyerror(char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    CIPL_PERROR("%s\n", s);
}
