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

    void free_scope_cb(StackNode *node) { scope_free(node->data); }

#line 94 "src/bison/grammar.c"

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
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_RETURN = 7,                     /* RETURN  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_LT = 10,                        /* LT  */
  YYSYMBOL_LE = 11,                        /* LE  */
  YYSYMBOL_GT = 12,                        /* GT  */
  YYSYMBOL_GE = 13,                        /* GE  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_NE = 15,                        /* NE  */
  YYSYMBOL_NAME = 16,                      /* NAME  */
  YYSYMBOL_THEN = 17,                      /* THEN  */
  YYSYMBOL_18_ = 18,                       /* ';'  */
  YYSYMBOL_19_ = 19,                       /* '('  */
  YYSYMBOL_20_ = 20,                       /* ')'  */
  YYSYMBOL_21_ = 21,                       /* '{'  */
  YYSYMBOL_22_ = 22,                       /* '}'  */
  YYSYMBOL_23_ = 23,                       /* ','  */
  YYSYMBOL_24_ = 24,                       /* '='  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '*'  */
  YYSYMBOL_28_ = 28,                       /* '/'  */
  YYSYMBOL_29_ = 29,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_prog = 31,                      /* prog  */
  YYSYMBOL_external_declaration = 32,      /* external_declaration  */
  YYSYMBOL_declaration = 33,               /* declaration  */
  YYSYMBOL_34_1 = 34,                      /* @1  */
  YYSYMBOL_func_declaration = 35,          /* func_declaration  */
  YYSYMBOL_36_2 = 36,                      /* @2  */
  YYSYMBOL_37_3 = 37,                      /* $@3  */
  YYSYMBOL_compound_stmt = 38,             /* compound_stmt  */
  YYSYMBOL_39_4 = 39,                      /* $@4  */
  YYSYMBOL_40_block_item_list_opt = 40,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 41,           /* block_item_list  */
  YYSYMBOL_block_item = 42,                /* block_item  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_declarator = 44,                /* declarator  */
  YYSYMBOL_id_list = 45,                   /* id_list  */
  YYSYMBOL_46_id_list_opt = 46,            /* id_list.opt  */
  YYSYMBOL_expr_stmt = 47,                 /* expr_stmt  */
  YYSYMBOL_cond_stmt = 48,                 /* cond_stmt  */
  YYSYMBOL_jmp_stmt = 49,                  /* jmp_stmt  */
  YYSYMBOL_iter_stmt = 50,                 /* iter_stmt  */
  YYSYMBOL_expression = 51,                /* expression  */
  YYSYMBOL_52_expression_opt = 52,         /* expression.opt  */
  YYSYMBOL_assign_expr = 53,               /* assign_expr  */
  YYSYMBOL_eq_expr = 54,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 55,                  /* rel_expr  */
  YYSYMBOL_add_expr = 56,                  /* add_expr  */
  YYSYMBOL_mult_expr = 57,                 /* mult_expr  */
  YYSYMBOL_unary_expr = 58,                /* unary_expr  */
  YYSYMBOL_postfix_expr = 59,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 60,             /* arg_expr_list  */
  YYSYMBOL_61_arg_expr_list_opt = 61,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 62,              /* primary_expr  */
  YYSYMBOL_id = 63,                        /* id  */
  YYSYMBOL_constant = 64                   /* constant  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3654

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   272


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
       2,     2,     2,    29,     2,     2,     2,     2,     2,     2,
      19,    20,    27,    25,    23,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    18,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    22,     2,     2,     2,     2,
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
      15,    16,    17
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    56,    59,    60,    63,    63,    81,    89,
     116,    89,   133,   133,   147,   148,   151,   152,   155,   156,
     159,   160,   161,   162,   163,   166,   167,   170,   171,   174,
     175,   178,   181,   185,   191,   194,   200,   203,   204,   207,
     208,   211,   212,   213,   216,   217,   218,   219,   220,   223,
     224,   225,   228,   229,   230,   233,   234,   235,   238,   239,
     244,   245,   248,   249,   252,   265,   266,   269,   272,   273
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
  "NUMBER_REAL", "LET", "IF", "RETURN", "ELSE", "FOR", "LT", "LE", "GT",
  "GE", "EQ", "NE", "NAME", "THEN", "';'", "'('", "')'", "'{'", "'}'",
  "','", "'='", "'+'", "'-'", "'*'", "'/'", "'!'", "$accept", "prog",
  "external_declaration", "declaration", "@1", "func_declaration", "@2",
  "$@3", "compound_stmt", "$@4", "block_item_list.opt", "block_item_list",
  "block_item", "statement", "declarator", "id_list", "id_list.opt",
  "expr_stmt", "cond_stmt", "jmp_stmt", "iter_stmt", "expression",
  "expression.opt", "assign_expr", "eq_expr", "rel_expr", "add_expr",
  "mult_expr", "unary_expr", "postfix_expr", "arg_expr_list",
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
     265,   266,   267,   268,   269,   270,   271,   272,    59,    40,
      41,   123,   125,    44,    61,    43,    45,    42,    47,    33
};
#endif

#define YYPACT_NINF (-196)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,     4,    32,    48,    56,    57,    73,    49,     9,   124,
     179,  -196,    59,   102,    46,   117,    88,   183,   143,   119,
      27,    96,   148,   107,    -7,   153,   111,   892,   120,  1337,
    1968,  1987,     8,   115,    26,   121,   916,    26,    26,  1364,
    1391,   130,  1418,  1445,  1472,  1499,  1526,  1553,  1580,   142,
     151,    75,   354,  3515,  3146,  2538,  2006,  2025,  2044,  2063,
     185,   916,   199,   146,   198,  2557,  2576,   126,  1607,  1634,
     924,   924,   924,   924,   924,   924,   924,   924,   924,   924,
      26,   270,   200,  1661,   209,   218,  2082,   515,  3165,   677,
    3524,  3533,  3542,  3551,  3184,  3203,  3222,  3241,   221,   154,
     158,   222,   132,   146,  1151,  2101,    92,   223,   159,  1245,
     334,  1688,   224,  1245,  1715,   225,     9,   228,   160,  2120,
     892,   234,   235,     9,   253,  2139,  2158,  2177,   916,   916,
     916,   252,    -2,    72,  3560,  3250,  2595,  2196,  2215,  2234,
    2253,   257,  2614,  2633,  2652,   916,   924,   924,  2671,  2690,
    2709,  2728,  1009,  1816,  1835,   916,  1151,  1151,    -4,   299,
    3430,  2747,  2272,  1854,  1873,  1892,  1911,   147,    26,   258,
     892,   320,   430,   495,   592,   657,   260,   256,   264,  1337,
    1742,   267,   271,  2766,  2785,  1162,  1162,  1162,  1162,  1162,
    1162,  1162,  1162,  1162,  1162,   916,   270,  1769,   275,  3269,
    3288,   270,   277,  2291,  2310,  1168,  1168,  1168,  1168,  1168,
    1168,  1168,  1168,  1168,  1168,  1151,   270,   916,   262,   146,
    1337,   754,   280,   279,   285,  2329,  2804,  2823,  2842,   916,
    1162,  1162,   472,  3297,  2861,  2880,  2899,  2918,   634,  3577,
    3594,  3611,  3628,  3316,  3335,  3354,  3373,   286,   287,  2937,
     295,  1930,  2348,  2367,  2386,   916,  1168,  1168,   452,  2956,
    2405,  2424,  2443,  2462,   614,  3447,  3464,  3481,  3498,  2975,
    2994,  3013,  3032,   176,   300,   301,   819,   312,   309,  1796,
     327,  3392,  3411,   270,  2481,  3051,   328,  3070,  3089,   270,
    1949,   132,   146,  1041,  3108,   331,  2500,   332,  1118,   314,
    3127,  2519,   132,   334,  1234,   335,   132,  1309
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
       0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,   338,    39,   296,  -196,  -196,  -196,   -23,  -116,
    -171,  -196,   315,   -69,    -6,  -196,  -196,   -68,   -59,   -56,
     -21,     2,   -52,  1003,  1072,  1007,   886,   796,   188,   350,
    -196,  -195,   512,    -1,   674
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    39,    16,     5,    18,    26,    40,    29,
      41,    42,    43,    44,     9,    20,    21,    45,    46,    47,
      48,    49,    85,    50,    51,    52,    53,    54,    55,    56,
     100,   101,    57,    58,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,   248,    14,    28,   179,     6,   250,   117,   223,   121,
     205,   206,   185,   186,   -10,     1,   -39,    22,   -39,   -39,
       7,   274,    25,     8,   122,   115,    60,   123,   116,    30,
      31,   124,    11,   106,   172,   139,    62,     1,    64,     4,
     111,     4,   119,   173,   114,    36,   174,   -30,    -3,   278,
      23,   107,    37,    -3,   220,    38,    -5,    -4,   112,    -2,
     139,    -5,    -4,    82,    -2,    84,    17,   -67,   -67,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   171,
     165,   175,   187,   188,   189,   190,   -41,   -41,   295,    70,
      71,    13,   -41,   -39,   297,   -32,   -32,   -32,   -32,   -32,
     109,   -32,    -8,   165,   176,    84,    19,    -8,   -32,   139,
     178,   -32,   177,   -32,   -32,   117,    24,   181,   -32,    -7,
     -11,   -32,   117,   118,    -7,   -11,   -13,   139,   139,   139,
     182,   -13,    27,    -9,    61,    30,    31,    -9,   167,   168,
      63,   169,    -6,    15,   139,   150,   150,   198,   119,    30,
      31,    36,    67,   170,   139,   165,   165,   202,    37,   118,
      69,    38,   119,   -29,   -37,    36,   217,   277,   -28,   -36,
     218,   -28,    37,   -27,   -60,    38,   -27,   -60,   -62,   -61,
     -67,   104,   -61,   -67,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   139,   165,   -40,   -25,   -25,   -40,
     165,   -26,   -26,    -6,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   165,   165,   139,    83,    86,   275,
     102,    84,   298,   172,   136,    65,    66,   -38,   139,   236,
     236,   280,   173,   304,   172,   174,   103,   307,   172,   -40,
     299,   110,   105,   173,   113,   -67,   174,   173,   -25,   136,
     174,   305,   180,   -67,   139,   262,   262,   286,    88,    88,
      88,    88,    88,    88,    88,    88,    96,    97,   171,   162,
     175,   -25,   -36,   152,   153,   197,   -38,   219,   221,   171,
     276,   175,   165,   171,   222,   175,   154,   224,   165,   155,
     -63,   225,   162,   176,    84,   249,   156,   251,   136,   157,
     -26,   279,   139,   -26,   176,   177,   -40,   284,   176,   207,
     208,   209,   210,   -41,   -41,   285,   136,   183,   184,   -41,
     290,   291,   -41,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     292,   293,   303,   136,   199,   200,   -21,   125,   126,   -21,
      12,   -21,   -21,   136,   203,   204,   -21,   294,   296,   -21,
     127,   300,   301,   128,   -37,   306,   141,    68,     0,     0,
     129,     0,     0,   130,    72,    73,    74,    75,   -41,   -41,
       0,     0,   -41,   233,   233,   233,   233,   233,   233,   233,
     233,   245,   246,   136,   162,     0,   137,     0,     0,   162,
       0,     0,     0,   259,   259,   259,   259,   259,   259,   259,
     259,   271,   272,   162,   162,   136,     0,     0,     0,     0,
       0,   137,     0,     0,     0,     0,     0,   136,   281,   282,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
       0,   163,     0,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
       0,     0,     0,   136,   287,   288,   -20,     0,     0,   -20,
       0,   -20,   -20,     0,   163,     0,   -20,     0,     0,   -20,
     137,     0,   207,   208,   209,   210,   -42,   -42,     0,     0,
       0,   162,   -42,     0,     0,   -42,     0,   162,   137,   137,
     137,     0,   187,   188,   189,   190,   -42,   -42,     0,     0,
       0,   136,   -42,     0,     0,   137,   148,   148,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   137,   163,   163,     0,     0,
       0,   -22,     0,     0,   -22,     0,   -22,   -22,     0,     0,
       0,   -22,     0,     0,   -22,    72,    73,    74,    75,   -42,
     -42,     0,     0,   -42,     0,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   137,   163,     0,   138,     0,
       0,   163,     0,     0,     0,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   163,   163,   137,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,   137,
     234,   234,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,     0,   164,     0,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,     0,     0,     0,   137,   260,   260,   -23,     0,
       0,   -23,     0,   -23,   -23,     0,   164,     0,   -23,     0,
       0,   -23,   138,     0,   207,   208,   209,   210,   -43,   -43,
       0,     0,     0,   163,   -43,     0,     0,   -43,     0,   163,
     138,   138,   138,     0,   187,   188,   189,   190,   -43,   -43,
       0,     0,     0,   137,   -43,     0,     0,   138,   149,   149,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   138,   164,   164,
       0,     0,     0,   -24,     0,     0,   -24,     0,   -24,   -24,
       0,     0,     0,   -24,     0,     0,   -24,    72,    73,    74,
      75,   -43,   -43,     0,     0,   -43,     0,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   138,   164,     0,
     140,     0,     0,   164,     0,     0,     0,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   164,   164,   138,
       0,     0,     0,     0,     0,   140,     0,     0,     0,     0,
       0,   138,   235,   235,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,     0,   166,     0,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,     0,     0,     0,   138,   261,   261,
     -31,     0,     0,   -31,     0,   -31,   -31,     0,   166,     0,
     -31,     0,     0,   -31,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,     0,     0,     0,
       0,   164,   140,   140,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,   140,
     151,   151,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   140,
     166,   166,   135,     0,     0,   -34,     0,     0,   -34,     0,
     -34,   -34,     0,     0,     0,   -34,     0,     0,   -34,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   140,
     166,     0,    94,    95,     0,   166,     0,   161,     0,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   166,
     166,   140,     0,     0,     0,   -12,   -12,   -12,   -12,   -12,
     161,   -12,     0,   140,   237,   237,   135,     0,   -12,     0,
       0,   -12,     0,   -12,   -12,     0,     0,     0,   -12,   125,
     126,   -12,   134,     0,   135,     0,     0,   142,   143,   140,
     263,   263,   127,     0,     0,   128,     0,     0,     0,     0,
     144,   135,   129,   145,     0,   130,     0,   134,     0,     0,
     146,   135,     0,   147,     0,     0,     0,   166,    90,    91,
      92,    93,     0,   166,     0,     0,     0,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,     0,     0,
       0,   135,   135,   135,   135,   135,   135,   243,   244,     0,
     160,   135,   161,     0,     0,     0,   134,   161,     0,     0,
       0,   161,   161,   161,   161,   161,   161,   269,   270,     0,
       0,   161,   161,   135,   134,     0,     0,     0,     0,   -69,
     -69,   -69,   -69,   -69,   -69,   135,     0,     0,   -69,   -69,
       0,   134,   -69,   -69,   -69,   -69,   -69,   -69,     0,   131,
       0,   134,     0,   133,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,   135,     0,     0,     0,     0,     0,   -13,     0,     0,
     -13,     0,   -13,   -13,   131,     0,     0,   -13,   133,     0,
     -13,   134,   134,   239,   240,   241,   242,    87,    89,   161,
       0,   134,   160,    98,    99,   161,     0,   160,   159,     0,
       0,   160,   160,   265,   266,   267,   268,     0,     0,   135,
       0,   160,   160,   134,     0,     0,     0,   108,   132,     0,
       0,   159,     0,   131,     0,   134,     0,   133,     0,     0,
       0,   -32,   -32,   -32,   -32,   -32,   302,   -32,     0,     0,
       0,   131,     0,   132,   -32,   133,     0,   -32,     0,   -32,
     -32,   134,     0,     0,   -32,     0,     0,   -32,   131,     0,
       0,     0,   133,   158,   152,   153,     0,     0,   131,     0,
       0,     0,   133,     0,     0,   226,   227,   154,     0,   160,
     155,   252,   253,     0,     0,   160,   158,   156,   228,     0,
     157,   229,   132,     0,   254,     0,     0,   255,   230,   134,
       0,   231,   232,   238,   256,     0,     0,   257,   247,    99,
     132,     0,   133,   159,    99,     0,     0,     0,   159,     0,
       0,     0,   258,   264,     0,     0,     0,   132,   273,    99,
     131,     0,   159,   159,   133,     0,     0,   132,     0,     0,
       0,     0,   131,     0,     0,     0,   133,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,     0,     0,     0,     0,    30,    31,
     -33,    33,    34,   -33,    35,   -33,   -33,     0,   131,     0,
     -33,   119,   133,   -33,    36,     0,   120,   132,   158,     0,
       0,    37,     0,   158,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,   158,   158,   132,
     159,     0,    99,     0,     0,     0,   159,     0,     0,     0,
       0,   132,     0,     0,     0,     0,   131,     0,     0,     0,
     133,     0,   -35,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,     0,     0,     0,     0,   -35,     0,   132,   -35,     0,
     -35,   -35,     0,     0,     0,   -35,     0,     0,   -35,     0,
      30,    31,    32,    33,    34,     0,    35,     0,     0,     0,
       0,     0,     0,   119,     0,   158,    36,     0,   120,   -15,
       0,   158,     0,    37,     0,     0,    38,   -18,   -18,   -18,
     -18,   -18,     0,   -18,     0,   132,     0,     0,     0,     0,
     -18,     0,     0,   -18,     0,   -18,   -18,     0,     0,     0,
     -18,     0,     0,   -18,   -21,   -21,   -21,   -21,   -21,     0,
     -21,     0,     0,     0,     0,     0,     0,   -21,     0,     0,
     -21,     0,   -21,   -21,     0,     0,     0,   -21,     0,     0,
     -21,    30,    31,    32,    33,    34,     0,    35,     0,     0,
       0,     0,     0,     0,   119,     0,     0,    36,     0,   120,
     -14,     0,     0,     0,    37,     0,     0,    38,   -17,   -17,
     -17,   -17,   -17,     0,   -17,     0,     0,     0,     0,     0,
       0,   -17,     0,     0,   -17,     0,   -17,   -17,     0,     0,
       0,   -17,     0,     0,   -17,   -19,   -19,   -19,   -19,   -19,
       0,   -19,     0,     0,     0,     0,     0,     0,   -19,     0,
       0,   -19,     0,   -19,   -19,     0,     0,     0,   -19,     0,
       0,   -19,   -20,   -20,   -20,   -20,   -20,     0,   -20,     0,
       0,     0,     0,     0,     0,   -20,     0,     0,   -20,     0,
     -20,   -20,     0,     0,     0,   -20,     0,     0,   -20,   -22,
     -22,   -22,   -22,   -22,     0,   -22,     0,     0,     0,     0,
       0,     0,   -22,     0,     0,   -22,     0,   -22,   -22,     0,
       0,     0,   -22,     0,     0,   -22,   -23,   -23,   -23,   -23,
     -23,     0,   -23,     0,     0,     0,     0,     0,     0,   -23,
       0,     0,   -23,     0,   -23,   -23,     0,     0,     0,   -23,
       0,     0,   -23,   -24,   -24,   -24,   -24,   -24,     0,   -24,
       0,     0,     0,     0,     0,     0,   -24,     0,     0,   -24,
       0,   -24,   -24,     0,     0,     0,   -24,     0,     0,   -24,
     -16,   -16,   -16,   -16,   -16,     0,   -16,     0,     0,     0,
       0,     0,     0,   -16,     0,     0,   -16,     0,   -16,   -16,
       0,     0,     0,   -16,     0,     0,   -16,   -31,   -31,   -31,
     -31,   -31,     0,   -31,     0,     0,     0,     0,     0,     0,
     -31,     0,     0,   -31,     0,   -31,   -31,     0,     0,     0,
     -31,     0,     0,   -31,   -34,   -34,   -34,   -34,   -34,     0,
     -34,     0,     0,     0,     0,     0,     0,   -34,     0,     0,
     -34,     0,   -34,   -34,     0,     0,     0,   -34,     0,     0,
     -34,   -33,   -33,   -33,   -33,   -33,     0,   -33,     0,     0,
       0,     0,     0,     0,   -33,     0,     0,   -33,     0,   -33,
     -33,     0,     0,     0,   -33,     0,     0,   -33,   -35,   -35,
     -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,     0,
       0,   -35,     0,     0,   -35,     0,   -35,   -35,     0,     0,
       0,   -35,     0,     0,   -35,    -8,    -8,    -8,    -8,    -8,
       0,    -8,     0,     0,     0,     0,     0,     0,    -8,     0,
       0,    -8,     0,    -8,    -8,     0,     0,     0,    -8,     0,
       0,    -8,    -7,    -7,    -7,    -7,    -7,     0,    -7,     0,
       0,     0,     0,     0,     0,    -7,     0,     0,    -7,     0,
      -7,    -7,     0,     0,     0,    -7,     0,     0,    -7,   -13,
     -13,   -13,   -13,   -13,     0,   -13,     0,     0,     0,     0,
       0,     0,   -13,     0,     0,   -13,     0,   -13,   -13,     0,
       0,     0,   -13,     0,     0,   -13,   -68,   -68,   -68,   -68,
     -68,   -68,     0,     0,     0,   -68,   -68,     0,     0,   -68,
     -68,   -68,   -68,   -68,   -68,   -67,   -67,   -67,   -67,   -67,
     -67,     0,     0,     0,   -67,   -67,     0,     0,   -67,   -67,
     -67,   -67,   -67,   -67,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,     0,   216,   -55,     0,     0,   -55,   -55,   -55,
     -55,   -55,   -55,   -58,   -58,   -58,   -58,   -58,   -58,     0,
       0,     0,   -58,   -58,     0,     0,   -58,   -58,   -58,   -58,
     -58,   -58,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,
       0,   -64,   -64,     0,     0,   -64,   -64,   -64,   -64,   -64,
     -64,   -65,   -65,   -65,   -65,   -65,   -65,     0,     0,     0,
     -65,   -65,     0,     0,   -65,   -65,   -65,   -65,   -65,   -65,
     -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,   -66,
     -66,     0,     0,   -66,   -66,   -66,   -66,   -66,   -66,   -59,
     -59,   -59,   -59,   -59,   -59,     0,     0,     0,   -59,   -59,
       0,     0,   -59,   -59,   -59,   -59,   -59,   -59,   -69,   -69,
     -69,   -69,   -69,   -69,     0,     0,   -69,   -69,     0,     0,
       0,     0,   -69,   -69,   -69,   -69,   -69,   -68,   -68,   -68,
     -68,   -68,   -68,     0,     0,   -68,   -68,     0,     0,     0,
       0,   -68,   -68,   -68,   -68,   -68,   -55,   -55,   -55,   -55,
     -55,   -55,     0,     0,   -55,    81,     0,     0,     0,     0,
     -55,   -55,   -55,   -55,   -55,   -58,   -58,   -58,   -58,   -58,
     -58,     0,     0,   -58,   -58,     0,     0,     0,     0,   -58,
     -58,   -58,   -58,   -58,   -64,   -64,   -64,   -64,   -64,   -64,
       0,     0,   -64,   -64,     0,     0,     0,     0,   -64,   -64,
     -64,   -64,   -64,   -65,   -65,   -65,   -65,   -65,   -65,     0,
       0,   -65,   -65,     0,     0,     0,     0,   -65,   -65,   -65,
     -65,   -65,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,
     -66,   -66,     0,     0,     0,     0,   -66,   -66,   -66,   -66,
     -66,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,   -59,
     -59,     0,     0,     0,     0,   -59,   -59,   -59,   -59,   -59,
     -67,   -67,   -67,   -67,   -67,   -67,     0,     0,   -67,   -67,
       0,     0,     0,     0,   -67,   -67,   -67,   -67,   -67,   -69,
     -69,   -69,   -69,   -69,   -69,     0,     0,     0,   -69,   -69,
       0,     0,     0,   -69,   -69,   -69,   -69,   -69,   -68,   -68,
     -68,   -68,   -68,   -68,     0,     0,     0,   -68,   -68,     0,
       0,     0,   -68,   -68,   -68,   -68,   -68,   -67,   -67,   -67,
     -67,   -67,   -67,     0,     0,     0,   -67,   -67,     0,     0,
       0,   -67,   -67,   -67,   -67,   -67,   -55,   -55,   -55,   -55,
     -55,   -55,     0,     0,     0,   196,   -55,     0,     0,     0,
     -55,   -55,   -55,   -55,   -55,   -58,   -58,   -58,   -58,   -58,
     -58,     0,     0,     0,   -58,   -58,     0,     0,     0,   -58,
     -58,   -58,   -58,   -58,   -64,   -64,   -64,   -64,   -64,   -64,
       0,     0,     0,   -64,   -64,     0,     0,     0,   -64,   -64,
     -64,   -64,   -64,   -65,   -65,   -65,   -65,   -65,   -65,     0,
       0,     0,   -65,   -65,     0,     0,     0,   -65,   -65,   -65,
     -65,   -65,   -52,   -52,   -52,   -52,   -52,   -52,     0,     0,
       0,     0,   -52,     0,     0,   -52,   215,   -52,   -52,   -52,
     -52,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,
       0,   -57,     0,     0,   -57,   -57,   -57,   -57,   -57,   -57,
     -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,     0,
     -56,     0,     0,   -56,   -56,   -56,   -56,   -56,   -56,   -66,
     -66,   -66,   -66,   -66,   -66,     0,     0,     0,   -66,   -66,
       0,     0,     0,   -66,   -66,   -66,   -66,   -66,   -69,   -69,
     -69,   -69,   -69,   -69,     0,     0,     0,   -69,   -69,     0,
       0,   -69,     0,   -69,   -69,   -69,   -69,   -68,   -68,   -68,
     -68,   -68,   -68,     0,     0,     0,   -68,   -68,     0,     0,
     -68,     0,   -68,   -68,   -68,   -68,   -67,   -67,   -67,   -67,
     -67,   -67,     0,     0,     0,   -67,   -67,     0,     0,   -67,
       0,   -67,   -67,   -67,   -67,   -55,   -55,   -55,   -55,   -55,
     -55,     0,     0,     0,   289,   -55,     0,     0,   -55,     0,
     -55,   -55,   -55,   -55,   -58,   -58,   -58,   -58,   -58,   -58,
       0,     0,     0,   -58,   -58,     0,     0,   -58,     0,   -58,
     -58,   -58,   -58,   -64,   -64,   -64,   -64,   -64,   -64,     0,
       0,     0,   -64,   -64,     0,     0,   -64,     0,   -64,   -64,
     -64,   -64,   -65,   -65,   -65,   -65,   -65,   -65,     0,     0,
       0,   -65,   -65,     0,     0,   -65,     0,   -65,   -65,   -65,
     -65,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,
     -59,   -59,     0,     0,     0,   -59,   -59,   -59,   -59,   -59,
     -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,   -66,
     -66,     0,     0,   -66,     0,   -66,   -66,   -66,   -66,   -59,
     -59,   -59,   -59,   -59,   -59,     0,     0,     0,   -59,   -59,
       0,     0,   -59,     0,   -59,   -59,   -59,   -59,   -52,   -52,
     -52,   -52,   -52,   -52,     0,     0,   -52,     0,     0,     0,
       0,     0,    80,   -52,   -52,   -52,   -52,   -57,   -57,   -57,
     -57,   -57,   -57,     0,     0,   -57,     0,     0,     0,     0,
       0,   -57,   -57,   -57,   -57,   -57,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,   -56,     0,     0,     0,     0,     0,
     -56,   -56,   -56,   -56,   -56,   -52,   -52,   -52,   -52,   -52,
     -52,     0,     0,     0,     0,   -52,     0,     0,     0,   195,
     -52,   -52,   -52,   -52,   -69,   -69,   -69,   -69,   -69,   -69,
       0,     0,   -69,   -69,     0,     0,     0,     0,     0,   -69,
     -69,   -69,   -69,   -68,   -68,   -68,   -68,   -68,   -68,     0,
       0,   -68,   -68,     0,     0,     0,     0,     0,   -68,   -68,
     -68,   -68,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,
     -67,   -67,     0,     0,     0,     0,     0,   -67,   -67,   -67,
     -67,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,   -55,
     201,     0,     0,     0,     0,     0,   -55,   -55,   -55,   -55,
     -58,   -58,   -58,   -58,   -58,   -58,     0,     0,   -58,   -58,
       0,     0,     0,     0,     0,   -58,   -58,   -58,   -58,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,   -64,   -64,     0,
       0,     0,     0,     0,   -64,   -64,   -64,   -64,   -65,   -65,
     -65,   -65,   -65,   -65,     0,     0,   -65,   -65,     0,     0,
       0,     0,     0,   -65,   -65,   -65,   -65,   -49,   -49,   -49,
     -49,   -49,   -49,     0,     0,     0,     0,   -49,     0,     0,
     -49,     0,   -49,   -49,   213,   214,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,     0,   -57,     0,     0,     0,
     -57,   -57,   -57,   -57,   -57,   -56,   -56,   -56,   -56,   -56,
     -56,     0,     0,     0,     0,   -56,     0,     0,     0,   -56,
     -56,   -56,   -56,   -56,   -69,   -69,   -69,   -69,   -69,   -69,
       0,     0,     0,   -69,   -69,     0,     0,     0,     0,   -69,
     -69,   -69,   -69,   -68,   -68,   -68,   -68,   -68,   -68,     0,
       0,     0,   -68,   -68,     0,     0,     0,     0,   -68,   -68,
     -68,   -68,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,
       0,   -67,   -67,     0,     0,     0,     0,   -67,   -67,   -67,
     -67,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,
     283,   -55,     0,     0,     0,     0,   -55,   -55,   -55,   -55,
     -58,   -58,   -58,   -58,   -58,   -58,     0,     0,     0,   -58,
     -58,     0,     0,     0,     0,   -58,   -58,   -58,   -58,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,     0,   -64,   -64,
       0,     0,     0,     0,   -64,   -64,   -64,   -64,   -65,   -65,
     -65,   -65,   -65,   -65,     0,     0,     0,   -65,   -65,     0,
       0,     0,     0,   -65,   -65,   -65,   -65,   -66,   -66,   -66,
     -66,   -66,   -66,     0,     0,   -66,   -66,     0,     0,     0,
       0,     0,   -66,   -66,   -66,   -66,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,     0,     0,   -52,     0,     0,   -52,
       0,   -52,   -52,   -52,   -52,   -50,   -50,   -50,   -50,   -50,
     -50,     0,     0,     0,     0,   -50,     0,     0,   -50,     0,
     -50,   -50,   213,   214,   -51,   -51,   -51,   -51,   -51,   -51,
       0,     0,     0,     0,   -51,     0,     0,   -51,     0,   -51,
     -51,   213,   214,   -53,   -53,   -53,   -53,   -53,   -53,     0,
       0,     0,     0,   -53,     0,     0,   -53,     0,   -53,   -53,
     -53,   -53,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
       0,     0,   -54,     0,     0,   -54,     0,   -54,   -54,   -54,
     -54,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,   -59,
     -59,     0,     0,     0,     0,     0,   -59,   -59,   -59,   -59,
     -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,     0,
     -57,     0,     0,   -57,     0,   -57,   -57,   -57,   -57,   -56,
     -56,   -56,   -56,   -56,   -56,     0,     0,     0,     0,   -56,
       0,     0,   -56,     0,   -56,   -56,   -56,   -56,   -66,   -66,
     -66,   -66,   -66,   -66,     0,     0,     0,   -66,   -66,     0,
       0,     0,     0,   -66,   -66,   -66,   -66,   -59,   -59,   -59,
     -59,   -59,   -59,     0,     0,     0,   -59,   -59,     0,     0,
       0,     0,   -59,   -59,   -59,   -59,   -49,   -49,   -49,   -49,
     -49,   -49,     0,     0,   -49,     0,     0,     0,     0,     0,
       0,   -49,   -49,    78,    79,   -52,   -52,   -52,   -52,   -52,
     -52,     0,     0,   -52,     0,     0,     0,     0,     0,     0,
     -52,   -52,   -52,   -52,   -50,   -50,   -50,   -50,   -50,   -50,
       0,     0,   -50,     0,     0,     0,     0,     0,     0,   -50,
     -50,    78,    79,   -51,   -51,   -51,   -51,   -51,   -51,     0,
       0,   -51,     0,     0,     0,     0,     0,     0,   -51,   -51,
      78,    79,   -53,   -53,   -53,   -53,   -53,   -53,     0,     0,
     -53,     0,     0,     0,     0,     0,     0,   -53,   -53,   -53,
     -53,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,   -54,
     -49,   -49,   -49,   -49,   -49,   -49,   -54,   -54,   -54,   -54,
     -49,     0,     0,     0,     0,   -49,   -49,   193,   194,   -57,
     -57,   -57,   -57,   -57,   -57,     0,     0,   -57,     0,     0,
       0,     0,     0,     0,   -57,   -57,   -57,   -57,   -56,   -56,
     -56,   -56,   -56,   -56,     0,     0,   -56,   -52,   -52,   -52,
     -52,   -52,   -52,   -56,   -56,   -56,   -56,   -52,     0,     0,
       0,     0,   -52,   -52,   -52,   -52,   -50,   -50,   -50,   -50,
     -50,   -50,     0,     0,     0,     0,   -50,     0,     0,     0,
       0,   -50,   -50,   193,   194,   -51,   -51,   -51,   -51,   -51,
     -51,     0,     0,     0,     0,   -51,     0,     0,     0,     0,
     -51,   -51,   193,   194,   -53,   -53,   -53,   -53,   -53,   -53,
       0,     0,     0,     0,   -53,     0,     0,     0,     0,   -53,
     -53,   -53,   -53,   -54,   -54,   -54,   -54,   -54,   -54,     0,
       0,     0,     0,   -54,     0,     0,     0,     0,   -54,   -54,
     -54,   -54,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,     0,   -57,     0,     0,     0,     0,   -57,   -57,   -57,
     -57,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,
       0,   -56,     0,     0,     0,     0,   -56,   -56,   -56,   -56,
     -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,     0,
     -44,     0,     0,   -44,     0,   211,   212,   -45,   -45,   -45,
     -45,   -45,   -45,     0,     0,     0,     0,   -45,     0,     0,
     -45,     0,   211,   212,   -46,   -46,   -46,   -46,   -46,   -46,
       0,     0,     0,     0,   -46,     0,     0,   -46,     0,   211,
     212,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,     0,
       0,   -47,     0,     0,   -47,     0,   211,   212,   -48,   -48,
     -48,   -48,   -48,   -48,     0,     0,     0,     0,   -48,     0,
       0,   -48,     0,   211,   212,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,   -44,   -45,   -45,   -45,   -45,   -45,   -45,
      76,    77,   -45,   -46,   -46,   -46,   -46,   -46,   -46,    76,
      77,   -46,   -47,   -47,   -47,   -47,   -47,   -47,    76,    77,
     -47,   -48,   -48,   -48,   -48,   -48,   -48,    76,    77,   -48,
     -44,   -44,   -44,   -44,   -44,   -44,    76,    77,     0,     0,
     -44,     0,     0,     0,     0,   191,   192,   -45,   -45,   -45,
     -45,   -45,   -45,     0,     0,     0,     0,   -45,     0,     0,
       0,     0,   191,   192,   -46,   -46,   -46,   -46,   -46,   -46,
       0,     0,     0,     0,   -46,     0,     0,     0,     0,   191,
     192,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,     0,
       0,   -47,     0,     0,     0,     0,   191,   192,   -48,   -48,
     -48,   -48,   -48,   -48,     0,     0,     0,     0,   -48,     0,
       0,     0,     0,   191,   192
};

static const yytype_int16 yycheck[] =
{
       1,   196,     8,    26,   120,     1,   201,     8,   179,     1,
      14,    15,    14,    15,    21,     5,    20,    18,    20,    23,
      16,   216,    23,    19,    16,    16,    32,    19,    19,     3,
       4,    32,     0,   102,   102,    36,    34,     5,    36,     0,
     109,     2,    16,   102,   113,    19,   102,    20,     0,   220,
      23,   103,    26,     5,   170,    29,     0,     0,   110,     0,
      61,     5,     5,    61,     5,    63,    20,    18,    19,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,   102,
      81,   102,    10,    11,    12,    13,    14,    15,   283,    14,
      15,    18,    20,    18,   289,     3,     4,     5,     6,     7,
       8,     9,     0,   104,   102,   103,    18,     5,    16,   110,
     116,    19,   110,    21,    22,   116,    20,   123,    26,     0,
       0,    29,   123,    16,     5,     5,     0,   128,   129,   130,
     128,     5,    21,    16,    19,     3,     4,    20,     6,     7,
      19,     9,    18,    19,   145,   146,   147,   145,    16,     3,
       4,    19,    22,    21,   155,   156,   157,   155,    26,    16,
      18,    29,    16,    20,    18,    19,    19,   219,    20,    18,
     168,    23,    26,    20,    20,    29,    23,    23,    20,    20,
      20,    23,    23,    23,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    20,    18,    19,    23,
     201,    18,    19,    18,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    18,    20,   217,
      20,   219,   291,   291,    36,    37,    38,    18,   229,   230,
     231,   229,   291,   302,   302,   291,    18,   306,   306,    18,
     292,    18,    20,   302,    20,    20,   302,   306,    20,    61,
     306,   303,    18,    18,   255,   256,   257,   255,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,   291,    81,
     291,    18,    20,     3,     4,    18,    20,    19,    18,   302,
      18,   302,   283,   306,    20,   306,    16,    20,   289,    19,
      20,    20,   104,   291,   292,    20,    26,    20,   110,    29,
      20,    22,   303,    18,   302,   303,    20,    20,   306,    10,
      11,    12,    13,    14,    15,    20,   128,   129,   130,    20,
      20,    20,    23,     3,     4,     5,     6,     7,     8,     9,
      18,    22,    18,   145,   146,   147,    16,     3,     4,    19,
       2,    21,    22,   155,   156,   157,    26,    20,    20,    29,
      16,    20,    20,    19,    20,    20,    60,    42,    -1,    -1,
      26,    -1,    -1,    29,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    36,    -1,    -1,   201,
      -1,    -1,    -1,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,   229,   230,   231,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    81,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,   255,   256,   257,    16,    -1,    -1,    19,
      -1,    21,    22,    -1,   104,    -1,    26,    -1,    -1,    29,
     110,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,   283,    20,    -1,    -1,    23,    -1,   289,   128,   129,
     130,    -1,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,   303,    20,    -1,    -1,   145,   146,   147,     3,     4,
       5,     6,     7,     8,     9,   155,   156,   157,    -1,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,
      -1,    26,    -1,    -1,    29,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    -1,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    36,    -1,
      -1,   201,    -1,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,   229,
     230,   231,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    81,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,   255,   256,   257,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,   104,    -1,    26,    -1,
      -1,    29,   110,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,   283,    20,    -1,    -1,    23,    -1,   289,
     128,   129,   130,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,   303,    20,    -1,    -1,   145,   146,   147,
       3,     4,     5,     6,     7,     8,     9,   155,   156,   157,
      -1,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,    22,
      -1,    -1,    -1,    26,    -1,    -1,    29,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    -1,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      36,    -1,    -1,   201,    -1,    -1,    -1,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,   229,   230,   231,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    81,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,   255,   256,   257,
      16,    -1,    -1,    19,    -1,    21,    22,    -1,   104,    -1,
      26,    -1,    -1,    29,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   283,    -1,    -1,    -1,    -1,
      -1,   289,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,   145,
     146,   147,     3,     4,     5,     6,     7,     8,     9,   155,
     156,   157,    36,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    76,    77,    -1,   201,    -1,    81,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,     3,     4,     5,     6,     7,
     104,     9,    -1,   229,   230,   231,   110,    -1,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    26,     3,
       4,    29,    36,    -1,   128,    -1,    -1,     3,     4,   255,
     256,   257,    16,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      16,   145,    26,    19,    -1,    29,    -1,    61,    -1,    -1,
      26,   155,    -1,    29,    -1,    -1,    -1,   283,    72,    73,
      74,    75,    -1,   289,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,
      -1,   185,   186,   187,   188,   189,   190,   191,   192,    -1,
     104,   195,   196,    -1,    -1,    -1,   110,   201,    -1,    -1,
      -1,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,   215,   216,   217,   128,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,   229,    -1,    -1,    19,    20,
      -1,   145,    23,    24,    25,    26,    27,    28,    -1,    36,
      -1,   155,    -1,    36,     3,     4,     5,     6,     7,     8,
       9,   255,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      19,    -1,    21,    22,    61,    -1,    -1,    26,    61,    -1,
      29,   185,   186,   187,   188,   189,   190,    70,    71,   283,
      -1,   195,   196,    80,    81,   289,    -1,   201,    81,    -1,
      -1,   205,   206,   207,   208,   209,   210,    -1,    -1,   303,
      -1,   215,   216,   217,    -1,    -1,    -1,   104,    36,    -1,
      -1,   104,    -1,   110,    -1,   229,    -1,   110,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,   128,    -1,    61,    16,   128,    -1,    19,    -1,    21,
      22,   255,    -1,    -1,    26,    -1,    -1,    29,   145,    -1,
      -1,    -1,   145,    81,     3,     4,    -1,    -1,   155,    -1,
      -1,    -1,   155,    -1,    -1,     3,     4,    16,    -1,   283,
      19,     3,     4,    -1,    -1,   289,   104,    26,    16,    -1,
      29,    19,   110,    -1,    16,    -1,    -1,    19,    26,   303,
      -1,    29,   185,   186,    26,    -1,    -1,    29,   195,   196,
     128,    -1,   195,   196,   201,    -1,    -1,    -1,   201,    -1,
      -1,    -1,   205,   206,    -1,    -1,    -1,   145,   215,   216,
     217,    -1,   215,   216,   217,    -1,    -1,   155,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,   229,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,     3,     4,
      16,     6,     7,    19,     9,    21,    22,    -1,   255,    -1,
      26,    16,   255,    29,    19,    -1,    21,   195,   196,    -1,
      -1,    26,    -1,   201,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   283,   215,   216,   217,
     283,    -1,   289,    -1,    -1,    -1,   289,    -1,    -1,    -1,
      -1,   229,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,
     303,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,   255,    19,    -1,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
       3,     4,     5,     6,     7,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    -1,   283,    19,    -1,    21,    22,
      -1,   289,    -1,    26,    -1,    -1,    29,     3,     4,     5,
       6,     7,    -1,     9,    -1,   303,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,
      26,    -1,    -1,    29,     3,     4,     5,     6,     7,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      19,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,
      29,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    26,    -1,    -1,    29,     3,     4,
       5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,
      -1,    26,    -1,    -1,    29,     3,     4,     5,     6,     7,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,
      -1,    29,     3,     4,     5,     6,     7,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    22,    -1,
      -1,    -1,    26,    -1,    -1,    29,     3,     4,     5,     6,
       7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    26,
      -1,    -1,    29,     3,     4,     5,     6,     7,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,
      -1,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,
       3,     4,     5,     6,     7,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,    22,
      -1,    -1,    -1,    26,    -1,    -1,    29,     3,     4,     5,
       6,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,
      26,    -1,    -1,    29,     3,     4,     5,     6,     7,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      19,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,
      29,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    26,    -1,    -1,    29,     3,     4,
       5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,
      -1,    26,    -1,    -1,    29,     3,     4,     5,     6,     7,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,
      -1,    29,     3,     4,     5,     6,     7,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    19,    -1,    21,    22,    -1,
      -1,    -1,    26,    -1,    -1,    29,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,
      24,    25,    26,    27,    28,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,    24,
      25,    26,    27,    28,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    24,    25,    26,    27,
      28,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    -1,    -1,    23,    24,    25,    26,    27,    28,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,    27,
      28,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    23,    24,    25,    26,    27,    28,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    23,    -1,    25,    26,    27,    28,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,
      23,    -1,    25,    26,    27,    28,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,
      -1,    25,    26,    27,    28,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,
      25,    26,    27,    28,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,    25,
      26,    27,    28,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    -1,    -1,    23,    -1,    25,    26,
      27,    28,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    -1,    25,    26,    27,
      28,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    -1,    -1,    23,    -1,    25,    26,    27,    28,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    23,    -1,    25,    26,    27,    28,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      23,    -1,    25,    26,    27,    28,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    23,
      -1,    25,    26,    27,    28,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    23,    -1,
      25,    26,    27,    28,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    23,    -1,    25,
      26,    27,    28,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    23,    -1,    25,    26,
      27,    28,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    23,    -1,    25,    26,    27,
      28,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    23,    -1,    25,    26,    27,    28,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    23,    -1,    25,    26,    27,    28,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      10,    11,    12,    13,    14,    15,    25,    26,    27,    28,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    10,    11,    12,
      13,    14,    15,    25,    26,    27,    28,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    23,    -1,    25,    26,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      23,    -1,    25,    26,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    23,    -1,    25,
      26,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    23,    -1,    25,    26,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    23,    -1,    25,    26,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    10,    11,    12,    13,    14,    15,
      25,    26,    18,    10,    11,    12,    13,    14,    15,    25,
      26,    18,    10,    11,    12,    13,    14,    15,    25,    26,
      18,    10,    11,    12,    13,    14,    15,    25,    26,    18,
      10,    11,    12,    13,    14,    15,    25,    26,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    31,    32,    33,    35,     1,    16,    19,    44,
      63,     0,    32,    18,    44,    19,    34,    20,    36,    18,
      45,    46,    63,    23,    20,    63,    37,    21,    38,    39,
       3,     4,     5,     6,     7,     9,    19,    26,    29,    33,
      38,    40,    41,    42,    43,    47,    48,    49,    50,    51,
      53,    54,    55,    56,    57,    58,    59,    62,    63,    64,
      44,    19,    51,    19,    51,    58,    58,    22,    42,    18,
      14,    15,    10,    11,    12,    13,    25,    26,    27,    28,
      24,    19,    51,    18,    51,    52,    20,    55,    58,    55,
      56,    56,    56,    56,    57,    57,    58,    58,    53,    53,
      60,    61,    20,    18,    23,    20,    43,    52,    53,     8,
      18,    43,    52,    20,    43,    16,    19,    63,    16,    16,
      21,     1,    16,    19,    63,     3,     4,    16,    19,    26,
      29,    53,    54,    55,    56,    57,    58,    59,    62,    63,
      64,    34,     3,     4,    16,    19,    26,    29,    59,    62,
      63,    64,     3,     4,    16,    19,    26,    29,    54,    55,
      56,    57,    58,    59,    62,    63,    64,     6,     7,     9,
      21,    38,    47,    48,    49,    50,    51,    51,    44,    39,
      18,    44,    51,    58,    58,    14,    15,    10,    11,    12,
      13,    25,    26,    27,    28,    24,    19,    18,    51,    58,
      58,    19,    51,    58,    58,    14,    15,    10,    11,    12,
      13,    25,    26,    27,    28,    24,    19,    19,    51,    19,
      39,    18,    20,    40,    20,    20,     3,     4,    16,    19,
      26,    29,    55,    58,    59,    62,    63,    64,    55,    56,
      56,    56,    56,    57,    57,    58,    58,    53,    61,    20,
      61,    20,     3,     4,    16,    19,    26,    29,    55,    58,
      59,    62,    63,    64,    55,    56,    56,    56,    56,    57,
      57,    58,    58,    53,    61,    51,    18,    52,    40,    22,
      51,    58,    58,    19,    20,    20,    51,    58,    58,    19,
      20,    20,    18,    22,    20,    61,    20,    61,    43,    52,
      20,    20,     8,    18,    43,    52,    20,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    31,    32,    32,    34,    33,    33,    36,
      37,    35,    39,    38,    40,    40,    41,    41,    42,    42,
      43,    43,    43,    43,    43,    44,    44,    45,    45,    46,
      46,    47,    48,    48,    49,    50,    51,    52,    52,    53,
      53,    54,    54,    54,    55,    55,    55,    55,    55,    56,
      56,    56,    57,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     4,     3,     0,
       0,     8,     0,     4,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     0,
       1,     2,     5,     7,     3,     9,     1,     0,     1,     1,
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
#line 55 "src/bison/math.y"
                                { list_push(&root->children, (yyvsp[0].ast)); }
#line 2265 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 56 "src/bison/math.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 2271 "src/bison/grammar.c"
    break;

  case 6: /* @1: %empty  */
#line 63 "src/bison/math.y"
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
        (yyval.ast) = ast_symref_init(
            symbol_init_copy(context_declare_variable(current_context, (yyvsp[0].ast)->value.symref))
        );
        ast_free((yyvsp[0].ast));
    }
#line 2292 "src/bison/grammar.c"
    break;

  case 7: /* declaration: LET declarator @1 ';'  */
#line 78 "src/bison/math.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 2300 "src/bison/grammar.c"
    break;

  case 8: /* declaration: LET error ';'  */
#line 81 "src/bison/math.y"
                    {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 2311 "src/bison/grammar.c"
    break;

  case 9: /* @2: %empty  */
#line 89 "src/bison/math.y"
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
            (yyval.ast) = ast_symref_init(
                symbol_init_copy(context_declare_function(previous_context, (yyvsp[-1].ast)->value.symref))
            );
        }
        ast_free((yyvsp[-1].ast));
    }
#line 2344 "src/bison/grammar.c"
    break;

  case 10: /* $@3: %empty  */
#line 116 "src/bison/math.y"
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
#line 2361 "src/bison/grammar.c"
    break;

  case 11: /* func_declaration: LET declarator '(' @2 id_list.opt ')' $@3 compound_stmt  */
#line 127 "src/bison/math.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 2370 "src/bison/grammar.c"
    break;

  case 12: /* $@4: %empty  */
#line 133 "src/bison/math.y"
                   {
        // hack to update the current scope 
        if (params_scope) {
            stack_push(&current_context->scopes, params_scope);
            current_context->current_scope = ((Scope *)stack_peek(&current_context->scopes))->index;
            params_scope = NULL;
        } else {
            context_push_scope(current_context);
        }
    }
#line 2385 "src/bison/grammar.c"
    break;

  case 13: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 142 "src/bison/math.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
    }
#line 2393 "src/bison/grammar.c"
    break;

  case 14: /* block_item_list.opt: block_item_list  */
#line 147 "src/bison/math.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 2399 "src/bison/grammar.c"
    break;

  case 15: /* block_item_list.opt: %empty  */
#line 148 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2405 "src/bison/grammar.c"
    break;

  case 16: /* block_item_list: block_item_list block_item  */
#line 151 "src/bison/math.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2411 "src/bison/grammar.c"
    break;

  case 17: /* block_item_list: block_item  */
#line 152 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2417 "src/bison/grammar.c"
    break;

  case 26: /* declarator: '(' declarator ')'  */
#line 167 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2423 "src/bison/grammar.c"
    break;

  case 27: /* id_list: id_list ',' id  */
#line 170 "src/bison/math.y"
                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2429 "src/bison/grammar.c"
    break;

  case 28: /* id_list: id  */
#line 171 "src/bison/math.y"
         { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2435 "src/bison/grammar.c"
    break;

  case 29: /* id_list.opt: %empty  */
#line 174 "src/bison/math.y"
                    { (yyval.list) = NULL; }
#line 2441 "src/bison/grammar.c"
    break;

  case 31: /* expr_stmt: expression ';'  */
#line 178 "src/bison/math.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2447 "src/bison/grammar.c"
    break;

  case 32: /* cond_stmt: IF '(' expression ')' statement  */
#line 181 "src/bison/math.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
        context_pop_scope(current_context);
    }
#line 2456 "src/bison/grammar.c"
    break;

  case 33: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 185 "src/bison/math.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
        context_pop_scope(current_context);
    }
#line 2465 "src/bison/grammar.c"
    break;

  case 34: /* jmp_stmt: RETURN expression ';'  */
#line 191 "src/bison/math.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 2471 "src/bison/grammar.c"
    break;

  case 35: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 194 "src/bison/math.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
        context_pop_scope(current_context);
    }
#line 2480 "src/bison/grammar.c"
    break;

  case 37: /* expression.opt: %empty  */
#line 203 "src/bison/math.y"
                       { (yyval.ast) = NULL; }
#line 2486 "src/bison/grammar.c"
    break;

  case 40: /* assign_expr: unary_expr '=' assign_expr  */
#line 208 "src/bison/math.y"
                                 { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2492 "src/bison/grammar.c"
    break;

  case 42: /* eq_expr: eq_expr EQ rel_expr  */
#line 212 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("==", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2498 "src/bison/grammar.c"
    break;

  case 43: /* eq_expr: eq_expr NE rel_expr  */
#line 213 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("!=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2504 "src/bison/grammar.c"
    break;

  case 45: /* rel_expr: rel_expr LT add_expr  */
#line 217 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2510 "src/bison/grammar.c"
    break;

  case 46: /* rel_expr: rel_expr LE add_expr  */
#line 218 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2516 "src/bison/grammar.c"
    break;

  case 47: /* rel_expr: rel_expr GT add_expr  */
#line 219 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2522 "src/bison/grammar.c"
    break;

  case 48: /* rel_expr: rel_expr GE add_expr  */
#line 220 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2528 "src/bison/grammar.c"
    break;

  case 50: /* add_expr: add_expr '+' mult_expr  */
#line 224 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('+', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2534 "src/bison/grammar.c"
    break;

  case 51: /* add_expr: add_expr '-' mult_expr  */
#line 225 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('-', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2540 "src/bison/grammar.c"
    break;

  case 53: /* mult_expr: mult_expr '*' unary_expr  */
#line 229 "src/bison/math.y"
                               { (yyval.ast) = ast_binop_init('*', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2546 "src/bison/grammar.c"
    break;

  case 54: /* mult_expr: mult_expr '/' unary_expr  */
#line 230 "src/bison/math.y"
                               { (yyval.ast) = ast_binop_init('/', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2552 "src/bison/grammar.c"
    break;

  case 56: /* unary_expr: '!' unary_expr  */
#line 234 "src/bison/math.y"
                     { (yyval.ast) = ast_uniop_init('!', (yyvsp[0].ast)); }
#line 2558 "src/bison/grammar.c"
    break;

  case 57: /* unary_expr: '-' unary_expr  */
#line 235 "src/bison/math.y"
                     { (yyval.ast) = ast_uniop_init('-', (yyvsp[0].ast)); }
#line 2564 "src/bison/grammar.c"
    break;

  case 59: /* postfix_expr: postfix_expr '(' arg_expr_list.opt ')'  */
#line 239 "src/bison/math.y"
                                             {
        (yyval.ast) = NULL;
    }
#line 2572 "src/bison/grammar.c"
    break;

  case 60: /* arg_expr_list: assign_expr  */
#line 244 "src/bison/math.y"
                           { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2578 "src/bison/grammar.c"
    break;

  case 61: /* arg_expr_list: arg_expr_list ',' assign_expr  */
#line 245 "src/bison/math.y"
                                    { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2584 "src/bison/grammar.c"
    break;

  case 63: /* arg_expr_list.opt: %empty  */
#line 249 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2590 "src/bison/grammar.c"
    break;

  case 64: /* primary_expr: id  */
#line 252 "src/bison/math.y"
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
#line 2608 "src/bison/grammar.c"
    break;

  case 66: /* primary_expr: '(' expression ')'  */
#line 266 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2614 "src/bison/grammar.c"
    break;

  case 67: /* id: NAME  */
#line 269 "src/bison/math.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 2620 "src/bison/grammar.c"
    break;

  case 68: /* constant: NUMBER_REAL  */
#line 272 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 2626 "src/bison/grammar.c"
    break;

  case 69: /* constant: NUMBER_INT  */
#line 273 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 2632 "src/bison/grammar.c"
    break;


#line 2636 "src/bison/grammar.c"

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

#line 276 "src/bison/math.y"


void yyerror(const char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    if (s) CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
    ++errors_count;
}
