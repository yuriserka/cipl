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

#line 91 "src/bison/grammar.c"

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
  YYSYMBOL_17_ = 17,                       /* '!'  */
  YYSYMBOL_18_ = 18,                       /* '='  */
  YYSYMBOL_19_ = 19,                       /* '+'  */
  YYSYMBOL_20_ = 20,                       /* '-'  */
  YYSYMBOL_21_ = 21,                       /* '*'  */
  YYSYMBOL_22_ = 22,                       /* '/'  */
  YYSYMBOL_THEN = 23,                      /* THEN  */
  YYSYMBOL_24_ = 24,                       /* ';'  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* '{'  */
  YYSYMBOL_28_ = 28,                       /* '}'  */
  YYSYMBOL_29_ = 29,                       /* ','  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_prog = 31,                      /* prog  */
  YYSYMBOL_external_declaration = 32,      /* external_declaration  */
  YYSYMBOL_declaration = 33,               /* declaration  */
  YYSYMBOL_34_1 = 34,                      /* @1  */
  YYSYMBOL_func_declaration = 35,          /* func_declaration  */
  YYSYMBOL_36_2 = 36,                      /* @2  */
  YYSYMBOL_37_3 = 37,                      /* $@3  */
  YYSYMBOL_compound_stmt = 38,             /* compound_stmt  */
  YYSYMBOL_39_block_item_list_opt = 39,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 40,           /* block_item_list  */
  YYSYMBOL_block_item = 41,                /* block_item  */
  YYSYMBOL_statement = 42,                 /* statement  */
  YYSYMBOL_declarator = 43,                /* declarator  */
  YYSYMBOL_id_list = 44,                   /* id_list  */
  YYSYMBOL_45_id_list_opt = 45,            /* id_list.opt  */
  YYSYMBOL_expr_stmt = 46,                 /* expr_stmt  */
  YYSYMBOL_cond_stmt = 47,                 /* cond_stmt  */
  YYSYMBOL_jmp_stmt = 48,                  /* jmp_stmt  */
  YYSYMBOL_iter_stmt = 49,                 /* iter_stmt  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_51_expression_opt = 51,         /* expression.opt  */
  YYSYMBOL_assign_expr = 52,               /* assign_expr  */
  YYSYMBOL_eq_expr = 53,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 54,                  /* rel_expr  */
  YYSYMBOL_add_expr = 55,                  /* add_expr  */
  YYSYMBOL_mult_expr = 56,                 /* mult_expr  */
  YYSYMBOL_unary_expr = 57,                /* unary_expr  */
  YYSYMBOL_postfix_expr = 58,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 59,             /* arg_expr_list  */
  YYSYMBOL_60_arg_expr_list_opt = 60,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 61,              /* primary_expr  */
  YYSYMBOL_id = 62,                        /* id  */
  YYSYMBOL_constant = 63                   /* constant  */
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
#define YYLAST   3565

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  304

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
       2,     2,     2,    17,     2,     2,     2,     2,     2,     2,
      25,    26,    21,    19,    29,    20,     2,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
       2,    18,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
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
      15,    16,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    56,    59,    60,    63,    63,    78,    85,
     107,    85,   124,   131,   132,   135,   136,   139,   140,   143,
     144,   145,   146,   147,   150,   151,   154,   155,   158,   159,
     162,   165,   168,   173,   176,   181,   184,   185,   188,   189,
     192,   193,   194,   197,   198,   199,   200,   201,   204,   205,
     206,   209,   210,   211,   214,   215,   216,   219,   220,   226,
     227,   230,   231,   234,   246,   247,   250,   253,   254
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
  "NUMBER_REAL", "LET", "IF", "RETURN", "ELSE", "FOR", "LT", "LE", "GT",
  "GE", "EQ", "NE", "NAME", "'!'", "'='", "'+'", "'-'", "'*'", "'/'",
  "THEN", "';'", "'('", "')'", "'{'", "'}'", "','", "$accept", "prog",
  "external_declaration", "declaration", "@1", "func_declaration", "@2",
  "$@3", "compound_stmt", "block_item_list.opt", "block_item_list",
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
     265,   266,   267,   268,   269,   270,   271,    33,    61,    43,
      45,    42,    47,   272,    59,    40,    41,   123,   125,    44
};
#endif

#define YYPACT_NINF (-193)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,     3,    20,    39,    60,    90,   -19,   118,    -7,   133,
     143,  -193,    92,    93,     1,    26,     9,   172,    63,   107,
     104,    15,   136,    47,    57,   137,    69,   925,  3013,  3029,
       5,    42,   272,   101,   272,   272,   604,   925,  1226,  1284,
     103,  1310,  1348,  1378,  1404,  1430,  1456,  1482,   111,   156,
      67,  1018,  3466,  3346,  3301,  3045,  3061,  3077,  3093,   176,
     604,   177,    33,  3316,  3331,   146,   174,   120,  1508,  1534,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     272,    83,   190,  1560,   193,   195,  3109,  1586,  1064,  3361,
    3541,  3481,  3496,  3511,  3526,  3376,  3391,  3406,  3421,   197,
     147,   148,   203,   144,    33,   764,  3125,   303,   208,   152,
     463,    98,  1612,   210,   463,  1638,   211,    -7,   212,   153,
    3141,   218,   221,    -7,   225,  2435,  2452,  2469,   604,   604,
     604,   224,    40,     0,  2928,  2792,  2588,  2486,  2503,  2520,
    2537,   247,  3157,  3173,  3189,   623,   623,   604,  3205,  3221,
    3237,  3253,  1709,  1729,  1749,   764,   764,   604,    17,  2389,
    2289,  2129,  1889,  1769,  1789,  1809,  1829,   209,   272,   248,
     925,   333,   429,   493,   589,   653,   250,   246,   251,  1664,
     255,  2605,  2622,   257,   783,   783,   783,   783,   783,   783,
     783,   783,   783,   783,   604,    83,  1690,  3436,  3451,   260,
      83,  1909,  1929,   261,   943,   943,   943,   943,   943,   943,
     943,   943,   943,   943,   764,    83,   604,   270,    33,   267,
     749,   276,   279,  2554,  2639,  2656,  2673,   783,   783,   604,
     126,  2809,  2690,  2707,  2724,  2741,   975,  2945,  2962,  2979,
    2996,  2826,  2843,  2860,  2877,   287,   288,  3269,   289,  1849,
    1949,  1969,  1989,   943,   943,   604,  2395,  2149,  2009,  2029,
    2049,  2069,  2415,  2309,  2329,  2349,  2369,  2169,  2189,  2209,
    2229,   169,   295,   296,   813,   281,   899,  2894,  2911,   298,
      83,  2571,  3285,  2249,  2269,   299,    83,  1869,   144,    33,
    2758,   300,  2089,   301,  1043,   305,  2775,  2109,   144,    98,
    1130,   306,   144,  1199
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
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,   294,   119,   292,  -193,  -193,  -193,   -58,   -36,
    -193,   307,   -63,    -6,  -193,  -193,   -55,   -47,   -20,   -18,
       2,   -43,  1063,  1081,   985,   897,   809,   188,   348,  -193,
    -192,   508,    -1,   668
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    38,    16,     5,    18,    26,    39,    40,
      41,    42,    43,     9,    20,    21,    44,    45,    46,    47,
      48,    85,    49,    50,    51,    52,    53,    54,    55,   101,
     102,    56,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    66,    14,   246,     6,    13,   121,   118,   248,   116,
     186,   187,   188,   189,   -40,   -40,     1,    22,   117,     7,
      11,   122,    25,   272,    59,     1,   -40,    17,     8,   124,
     123,   204,   205,    19,    61,   139,    28,    29,    65,    -3,
     107,    24,    -9,   -38,    -3,   171,   -38,   112,   172,   120,
      34,   115,    -9,    35,   184,   185,   173,   -36,    36,   139,
      -5,   108,    82,   119,    84,    -5,   -38,    60,   113,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   119,
     165,    70,    71,   174,   -10,   175,   152,   153,   291,   -28,
      -4,   -38,    -2,    -8,   293,    -4,    27,    -2,    -8,   154,
     155,   125,   126,   156,   165,   176,    84,    -7,   157,   -62,
     139,   178,    -7,   177,   127,   128,   118,   180,   129,     4,
     -11,     4,   118,   130,   -36,   -11,    62,   139,   139,   139,
     -29,    67,   183,    23,   219,    69,   186,   187,   188,   189,
     -41,   -41,   -66,   -66,   150,   150,   139,    28,    29,   199,
     167,   168,   -41,   169,   165,   165,   139,    -6,    15,   203,
     120,    34,   -27,   -26,    35,   -27,   -26,   -24,   -24,    36,
     217,   170,    86,   -59,   -61,   275,   -59,   105,   -60,   -66,
     -35,   -60,   -66,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   139,   165,   -39,   -25,   -25,   -39,   165,
      -6,    83,    87,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   165,   165,   139,   103,   -37,   273,   104,
      84,   -39,    63,    64,   136,   294,   234,   234,   139,   106,
     171,   279,   111,   172,   216,   300,   114,   -66,   -24,   303,
     171,   173,   179,   172,   171,   -66,   295,   172,   136,   -24,
     -35,   173,   260,   260,   139,   173,   301,   285,    89,    89,
      89,    89,    89,    89,    89,    89,    97,    98,   174,   162,
     175,   196,   -37,   218,   220,    28,    29,   221,   174,   165,
     175,   222,   174,   223,   175,   165,   247,   249,   120,    34,
     176,    84,    35,   162,   274,   276,    12,    36,   139,   136,
     176,   177,   -25,   -25,   176,   289,   -31,   -31,   -31,   -31,
     -31,   110,   -31,   -39,   281,   282,   181,   182,   136,   -31,
     -31,   287,   288,   -31,   290,   292,   296,   297,   -31,   299,
     -31,   -31,   302,   197,   198,   136,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   201,   202,   136,     0,     0,    68,   -20,
     -20,   141,     0,   -20,     0,     0,     0,     0,   -20,     0,
     -20,   -20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   231,   231,   231,   231,   231,   231,   231,
     243,   244,   136,   162,   137,     0,     0,     0,   162,     0,
       0,     0,   257,   257,   257,   257,   257,   257,   257,   257,
     269,   270,   162,   162,   136,     0,     0,     0,   137,     0,
       0,     0,     0,     0,     0,   277,   278,   136,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,     0,   163,
       0,     0,   -19,   -19,   -19,   -19,   -19,   -19,   -19,     0,
       0,   283,   284,   136,     0,   -19,   -19,     0,     0,   -19,
       0,     0,     0,   163,   -19,     0,   -19,   -19,     0,   137,
       0,     0,     0,     0,     0,     0,    28,    29,   162,    31,
      32,     0,    33,     0,   162,     0,   137,   137,   137,   120,
      34,     0,     0,    35,     0,     0,     0,   136,    36,     0,
      37,     0,     0,   148,   148,   137,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   163,   163,   137,     0,     0,     0,   -21,
     -21,     0,     0,   -21,     0,     0,     0,     0,   -21,     0,
     -21,   -21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   137,   163,   138,     0,     0,     0,   163,     0,
       0,     0,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   163,   163,   137,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,   232,   232,   137,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,     0,   164,
       0,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,     0,
       0,   258,   258,   137,     0,   -22,   -22,   125,   126,   -22,
       0,     0,     0,   164,   -22,     0,   -22,   -22,     0,   138,
     127,   128,     0,     0,   129,     0,   142,   143,   163,   130,
       0,     0,     0,     0,   163,     0,   138,   138,   138,   144,
     145,     0,     0,   146,     0,     0,     0,   137,   147,     0,
       0,     0,     0,   149,   149,   138,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   164,   164,   138,     0,     0,     0,   -23,
     -23,     0,     0,   -23,     0,     0,     0,     0,   -23,     0,
     -23,   -23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   138,   164,   140,     0,     0,     0,   164,     0,
       0,     0,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   164,   164,   138,     0,     0,     0,   140,     0,
       0,     0,     0,     0,     0,   233,   233,   138,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,     0,   166,
       0,     0,   -30,   -30,   -30,   -30,   -30,   -30,   -30,     0,
       0,   259,   259,   138,     0,   -30,   -30,   152,   153,   -30,
       0,     0,     0,   166,   -30,     0,   -30,   -30,     0,   140,
     154,   155,     0,     0,   156,     0,   224,   225,   164,   157,
       0,     0,     0,     0,   164,     0,   140,   140,   140,   226,
     227,     0,     0,   228,     0,     0,     0,   138,   229,     0,
       0,     0,     0,   151,   151,   140,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   166,   166,   140,     0,     0,     0,   -33,
     -33,     0,     0,   -33,     0,     0,     0,     0,   -33,     0,
     -33,   -33,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   140,   166,     0,     0,     0,     0,   166,   135,
       0,     0,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   166,   166,   140,    95,    96,     0,     0,     0,
     161,     0,     0,     0,     0,   235,   235,   140,     0,     0,
       0,     0,   -12,   -12,   -12,   -12,   -12,   -12,   -12,     0,
       0,     0,     0,     0,   161,   -12,   -12,     0,     0,   -12,
     135,   261,   261,   140,   -12,     0,   -12,   -12,    28,    29,
      30,    31,    32,   134,    33,     0,     0,     0,     0,   135,
       0,   120,    34,     0,     0,    35,   250,   251,   166,     0,
      36,     0,    37,   -14,   166,     0,   135,   134,     0,   252,
     253,     0,     0,   254,     0,     0,   135,   140,   255,    91,
      92,    93,    94,     0,     0,     0,     0,     0,   160,     0,
       0,     0,     0,     0,     0,   186,   187,   188,   189,   -42,
     -42,     0,     0,   135,   135,   135,   135,   135,   135,   241,
     242,   -42,   160,   135,   161,     0,     0,     0,   134,   161,
       0,     0,     0,   161,   161,   161,   161,   161,   161,   267,
     268,   133,     0,   161,   161,   135,     0,   134,    72,    73,
      74,    75,   -40,   -40,     0,     0,     0,     0,   135,     0,
       0,     0,   -40,     0,   134,   133,   -31,   -31,   -31,   -31,
     -31,   298,   -31,     0,   134,    88,    90,     0,     0,   -31,
     -31,     0,     0,   -31,   135,     0,   159,     0,   -31,     0,
     -31,   -31,     0,     0,    72,    73,    74,    75,   -41,   -41,
       0,   134,   134,   237,   238,   239,   240,     0,   -41,   161,
     159,   134,   160,     0,     0,   161,   133,   160,     0,   131,
       0,   160,   160,   263,   264,   265,   266,     0,   135,     0,
       0,   160,   160,   134,     0,   133,     0,   132,     0,     0,
       0,     0,     0,   131,     0,     0,   134,     0,     0,     0,
       0,     0,   133,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
       0,   132,   133,    99,   100,     0,   -32,   -32,     0,     0,
     -32,     0,   134,     0,     0,   -32,     0,   -32,   -32,     0,
       0,     0,   158,     0,     0,     0,     0,     0,   109,   230,
     236,     0,     0,     0,   131,     0,     0,   160,     0,   133,
     159,     0,     0,   160,     0,   159,   158,     0,     0,   256,
     262,     0,   132,   131,     0,     0,   134,     0,     0,   159,
     159,   133,   -34,   -34,   -34,   -34,   -34,   -34,   -34,     0,
     131,   132,     0,     0,   133,   -34,   -34,     0,     0,   -34,
     131,     0,     0,     0,   -34,     0,   -34,   -34,   132,   -17,
     -17,   -17,   -17,   -17,     0,   -17,     0,     0,   132,     0,
     133,     0,   -17,   -17,     0,     0,   -17,     0,     0,     0,
       0,   -17,     0,   -17,   -17,     0,     0,   245,   100,     0,
       0,     0,     0,   100,     0,   159,     0,     0,     0,     0,
       0,   159,     0,     0,     0,   132,   158,   271,   100,   131,
       0,   158,     0,     0,   133,     0,     0,   -20,   -20,   -20,
     -20,   -20,   131,   -20,     0,   158,   158,   132,     0,     0,
     -20,   -20,     0,     0,   -20,     0,     0,     0,     0,   -20,
     132,   -20,   -20,    28,    29,    30,    31,    32,   131,    33,
       0,     0,     0,     0,     0,     0,   120,    34,     0,     0,
      35,     0,     0,     0,     0,    36,   132,    37,   -13,     0,
       0,     0,     0,   100,     0,     0,     0,     0,     0,   100,
       0,   -16,   -16,   -16,   -16,   -16,     0,   -16,     0,     0,
       0,   158,   131,     0,   -16,   -16,     0,   158,   -16,     0,
       0,     0,     0,   -16,     0,   -16,   -16,     0,     0,     0,
     132,   -18,   -18,   -18,   -18,   -18,     0,   -18,     0,     0,
       0,     0,     0,     0,   -18,   -18,     0,     0,   -18,     0,
       0,     0,     0,   -18,     0,   -18,   -18,   -19,   -19,   -19,
     -19,   -19,     0,   -19,     0,     0,     0,     0,     0,     0,
     -19,   -19,     0,     0,   -19,     0,     0,     0,     0,   -19,
       0,   -19,   -19,   -21,   -21,   -21,   -21,   -21,     0,   -21,
       0,     0,     0,     0,     0,     0,   -21,   -21,     0,     0,
     -21,     0,     0,     0,     0,   -21,     0,   -21,   -21,   -22,
     -22,   -22,   -22,   -22,     0,   -22,     0,     0,     0,     0,
       0,     0,   -22,   -22,     0,     0,   -22,     0,     0,     0,
       0,   -22,     0,   -22,   -22,   -23,   -23,   -23,   -23,   -23,
       0,   -23,     0,     0,     0,     0,     0,     0,   -23,   -23,
       0,     0,   -23,     0,     0,     0,     0,   -23,     0,   -23,
     -23,   -15,   -15,   -15,   -15,   -15,     0,   -15,     0,     0,
       0,     0,     0,     0,   -15,   -15,     0,     0,   -15,     0,
       0,     0,     0,   -15,     0,   -15,   -15,   -30,   -30,   -30,
     -30,   -30,     0,   -30,     0,     0,     0,     0,     0,     0,
     -30,   -30,     0,     0,   -30,     0,     0,     0,     0,   -30,
       0,   -30,   -30,   -33,   -33,   -33,   -33,   -33,     0,   -33,
       0,     0,     0,     0,     0,     0,   -33,   -33,     0,     0,
     -33,     0,     0,     0,     0,   -33,     0,   -33,   -33,   -12,
     -12,   -12,   -12,   -12,     0,   -12,     0,     0,     0,     0,
       0,     0,   -12,   -12,     0,     0,   -12,     0,     0,     0,
       0,   -12,     0,   -12,   -12,   -32,   -32,   -32,   -32,   -32,
       0,   -32,     0,     0,     0,     0,     0,     0,   -32,   -32,
       0,     0,   -32,     0,     0,     0,     0,   -32,     0,   -32,
     -32,   -34,   -34,   -34,   -34,   -34,     0,   -34,     0,     0,
       0,     0,     0,     0,   -34,   -34,     0,     0,   -34,     0,
       0,     0,     0,   -34,     0,   -34,   -34,    -8,    -8,    -8,
      -8,    -8,     0,    -8,     0,     0,     0,     0,     0,     0,
      -8,    -8,     0,     0,    -8,     0,     0,     0,     0,    -8,
       0,    -8,    -8,    -7,    -7,    -7,    -7,    -7,     0,    -7,
       0,     0,     0,     0,     0,     0,    -7,    -7,     0,     0,
      -7,     0,     0,     0,     0,    -7,     0,    -7,    -7,   -68,
     -68,   -68,   -68,   -68,   -68,     0,     0,   -68,   -68,   -68,
     -68,   -68,     0,     0,   -68,   -68,     0,     0,   -68,   -67,
     -67,   -67,   -67,   -67,   -67,     0,     0,   -67,   -67,   -67,
     -67,   -67,     0,     0,   -67,   -67,     0,     0,   -67,   -66,
     -66,   -66,   -66,   -66,   -66,     0,     0,   -66,   -66,   -66,
     -66,   -66,     0,     0,   -66,   -66,     0,     0,   -66,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,   -54,   -54,   -54,
     -54,   -54,     0,     0,   215,   -54,     0,     0,   -54,   -57,
     -57,   -57,   -57,   -57,   -57,     0,     0,   -57,   -57,   -57,
     -57,   -57,     0,     0,   -57,   -57,     0,     0,   -57,   -63,
     -63,   -63,   -63,   -63,   -63,     0,     0,   -63,   -63,   -63,
     -63,   -63,     0,     0,   -63,   -63,     0,     0,   -63,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,   -64,   -64,   -64,
     -64,   -64,     0,     0,   -64,   -64,     0,     0,   -64,   -65,
     -65,   -65,   -65,   -65,   -65,     0,     0,   -65,   -65,   -65,
     -65,   -65,     0,     0,   -65,   -65,     0,     0,   -65,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,   -58,   -58,   -58,
     -58,   -58,     0,     0,   -58,   -58,     0,     0,   -58,   -51,
     -51,   -51,   -51,   -51,   -51,     0,     0,   214,   -51,   -51,
     -51,   -51,     0,     0,     0,   -51,     0,     0,   -51,   -55,
     -55,   -55,   -55,   -55,   -55,     0,     0,   -55,   -55,   -55,
     -55,   -55,     0,     0,     0,   -55,     0,     0,   -55,   -56,
     -56,   -56,   -56,   -56,   -56,     0,     0,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,   -56,     0,     0,   -56,   -68,
     -68,   -68,   -68,   -68,   -68,     0,     0,     0,   -68,   -68,
     -68,   -68,     0,     0,   -68,   -68,     0,     0,   -68,   -67,
     -67,   -67,   -67,   -67,   -67,     0,     0,     0,   -67,   -67,
     -67,   -67,     0,     0,   -67,   -67,     0,     0,   -67,   -66,
     -66,   -66,   -66,   -66,   -66,     0,     0,     0,   -66,   -66,
     -66,   -66,     0,     0,   -66,   -66,     0,     0,   -66,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,     0,   -54,   -54,
     -54,   -54,     0,     0,   286,   -54,     0,     0,   -54,   -57,
     -57,   -57,   -57,   -57,   -57,     0,     0,     0,   -57,   -57,
     -57,   -57,     0,     0,   -57,   -57,     0,     0,   -57,   -63,
     -63,   -63,   -63,   -63,   -63,     0,     0,     0,   -63,   -63,
     -63,   -63,     0,     0,   -63,   -63,     0,     0,   -63,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,     0,   -64,   -64,
     -64,   -64,     0,     0,   -64,   -64,     0,     0,   -64,   -65,
     -65,   -65,   -65,   -65,   -65,     0,     0,     0,   -65,   -65,
     -65,   -65,     0,     0,   -65,   -65,     0,     0,   -65,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,   -58,   -58,
     -58,   -58,     0,     0,   -58,   -58,     0,     0,   -58,   -48,
     -48,   -48,   -48,   -48,   -48,     0,     0,     0,   -48,   -48,
     212,   213,     0,     0,     0,   -48,     0,     0,   -48,   -51,
     -51,   -51,   -51,   -51,   -51,     0,     0,     0,   -51,   -51,
     -51,   -51,     0,     0,     0,   -51,     0,     0,   -51,   -49,
     -49,   -49,   -49,   -49,   -49,     0,     0,     0,   -49,   -49,
     212,   213,     0,     0,     0,   -49,     0,     0,   -49,   -50,
     -50,   -50,   -50,   -50,   -50,     0,     0,     0,   -50,   -50,
     212,   213,     0,     0,     0,   -50,     0,     0,   -50,   -52,
     -52,   -52,   -52,   -52,   -52,     0,     0,     0,   -52,   -52,
     -52,   -52,     0,     0,     0,   -52,     0,     0,   -52,   -53,
     -53,   -53,   -53,   -53,   -53,     0,     0,     0,   -53,   -53,
     -53,   -53,     0,     0,     0,   -53,     0,     0,   -53,   -55,
     -55,   -55,   -55,   -55,   -55,     0,     0,     0,   -55,   -55,
     -55,   -55,     0,     0,     0,   -55,     0,     0,   -55,   -56,
     -56,   -56,   -56,   -56,   -56,     0,     0,     0,   -56,   -56,
     -56,   -56,     0,     0,     0,   -56,     0,     0,   -56,   -43,
     -43,   -43,   -43,   -43,   -43,     0,     0,     0,   210,   211,
       0,     0,     0,     0,     0,   -43,     0,     0,   -43,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,     0,   210,   211,
       0,     0,     0,     0,     0,   -44,     0,     0,   -44,   -45,
     -45,   -45,   -45,   -45,   -45,     0,     0,     0,   210,   211,
       0,     0,     0,     0,     0,   -45,     0,     0,   -45,   -46,
     -46,   -46,   -46,   -46,   -46,     0,     0,     0,   210,   211,
       0,     0,     0,     0,     0,   -46,     0,     0,   -46,   -47,
     -47,   -47,   -47,   -47,   -47,     0,     0,     0,   210,   211,
       0,     0,     0,     0,     0,   -47,     0,     0,   -47,   206,
     207,   208,   209,   -40,   -40,   206,   207,   208,   209,   -41,
     -41,     0,     0,     0,     0,   -40,     0,     0,   -40,     0,
       0,   -41,     0,     0,   -41,   206,   207,   208,   209,   -42,
     -42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -42,     0,     0,   -42,   -68,   -68,   -68,   -68,   -68,
     -68,     0,     0,   -68,   -68,   -68,   -68,   -68,     0,     0,
     -68,   -68,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,
     -67,   -67,   -67,   -67,   -67,     0,     0,   -67,   -67,   -66,
     -66,   -66,   -66,   -66,   -66,     0,     0,   -66,   -66,   -66,
     -66,   -66,     0,     0,   -66,   -66,   -54,   -54,   -54,   -54,
     -54,   -54,     0,     0,   -54,   -54,   -54,   -54,   -54,     0,
       0,   195,   -54,   -57,   -57,   -57,   -57,   -57,   -57,     0,
       0,   -57,   -57,   -57,   -57,   -57,     0,     0,   -57,   -57,
     -63,   -63,   -63,   -63,   -63,   -63,     0,     0,   -63,   -63,
     -63,   -63,   -63,     0,     0,   -63,   -63,   -64,   -64,   -64,
     -64,   -64,   -64,     0,     0,   -64,   -64,   -64,   -64,   -64,
       0,     0,   -64,   -64,   -65,   -65,   -65,   -65,   -65,   -65,
       0,     0,   -65,   -65,   -65,   -65,   -65,     0,     0,   -65,
     -65,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,   -58,
     -58,   -58,   -58,   -58,     0,     0,   -58,   -58,   -51,   -51,
     -51,   -51,   -51,   -51,     0,     0,   194,   -51,   -51,   -51,
     -51,     0,     0,     0,   -51,   -55,   -55,   -55,   -55,   -55,
     -55,     0,     0,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   -55,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
     -56,   -56,   -56,   -56,   -56,     0,     0,     0,   -56,   -68,
     -68,   -68,   -68,   -68,   -68,     0,     0,     0,   -68,   -68,
     -68,   -68,     0,     0,   -68,   -68,   -67,   -67,   -67,   -67,
     -67,   -67,     0,     0,     0,   -67,   -67,   -67,   -67,     0,
       0,   -67,   -67,   -66,   -66,   -66,   -66,   -66,   -66,     0,
       0,     0,   -66,   -66,   -66,   -66,     0,     0,   -66,   -66,
     -54,   -54,   -54,   -54,   -54,   -54,     0,     0,     0,   -54,
     -54,   -54,   -54,     0,     0,   280,   -54,   -57,   -57,   -57,
     -57,   -57,   -57,     0,     0,     0,   -57,   -57,   -57,   -57,
       0,     0,   -57,   -57,   -63,   -63,   -63,   -63,   -63,   -63,
       0,     0,     0,   -63,   -63,   -63,   -63,     0,     0,   -63,
     -63,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,
     -64,   -64,   -64,   -64,     0,     0,   -64,   -64,   -65,   -65,
     -65,   -65,   -65,   -65,     0,     0,     0,   -65,   -65,   -65,
     -65,     0,     0,   -65,   -65,   -58,   -58,   -58,   -58,   -58,
     -58,     0,     0,     0,   -58,   -58,   -58,   -58,     0,     0,
     -58,   -58,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,
       0,   -48,   -48,   192,   193,     0,     0,     0,   -48,   -51,
     -51,   -51,   -51,   -51,   -51,     0,     0,     0,   -51,   -51,
     -51,   -51,     0,     0,     0,   -51,   -49,   -49,   -49,   -49,
     -49,   -49,     0,     0,     0,   -49,   -49,   192,   193,     0,
       0,     0,   -49,   -50,   -50,   -50,   -50,   -50,   -50,     0,
       0,     0,   -50,   -50,   192,   193,     0,     0,     0,   -50,
     -52,   -52,   -52,   -52,   -52,   -52,     0,     0,     0,   -52,
     -52,   -52,   -52,     0,     0,     0,   -52,   -53,   -53,   -53,
     -53,   -53,   -53,     0,     0,     0,   -53,   -53,   -53,   -53,
       0,     0,     0,   -53,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,     0,   -55,   -55,   -55,   -55,     0,     0,     0,
     -55,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,
     -56,   -56,   -56,   -56,     0,     0,     0,   -56,   -43,   -43,
     -43,   -43,   -43,   -43,     0,     0,     0,   190,   191,     0,
       0,     0,     0,     0,   -43,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,     0,   190,   191,     0,     0,     0,     0,
       0,   -44,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
       0,   190,   191,     0,     0,     0,     0,     0,   -45,   -46,
     -46,   -46,   -46,   -46,   -46,     0,     0,     0,   190,   191,
       0,     0,     0,     0,     0,   -46,   -47,   -47,   -47,   -47,
     -47,   -47,     0,     0,     0,   190,   191,     0,     0,     0,
       0,     0,   -47,   -68,   -68,   -68,   -68,   -68,   -68,     0,
       0,   -68,   -68,   -68,   -68,   -68,     0,   -68,   -68,   -67,
     -67,   -67,   -67,   -67,   -67,     0,     0,   -67,   -67,   -67,
     -67,   -67,     0,   -67,   -67,   -54,   -54,   -54,   -54,   -54,
     -54,     0,     0,   -54,   -54,   -54,   -54,   -54,     0,   -54,
      81,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,   -57,
     -57,   -57,   -57,   -57,     0,   -57,   -57,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,   -63,   -63,   -63,   -63,   -63,
       0,   -63,   -63,   -64,   -64,   -64,   -64,   -64,   -64,     0,
       0,   -64,   -64,   -64,   -64,   -64,     0,   -64,   -64,   -65,
     -65,   -65,   -65,   -65,   -65,     0,     0,   -65,   -65,   -65,
     -65,   -65,     0,   -65,   -65,   -58,   -58,   -58,   -58,   -58,
     -58,     0,     0,   -58,   -58,   -58,   -58,   -58,     0,   -58,
     -58,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,   -66,
     -66,   -66,   -66,   -66,     0,   -66,   -66,   -68,   -68,   -68,
     -68,   -68,   -68,     0,     0,     0,   -68,   -68,   -68,   -68,
       0,   -68,   -68,   -67,   -67,   -67,   -67,   -67,   -67,     0,
       0,     0,   -67,   -67,   -67,   -67,     0,   -67,   -67,   -66,
     -66,   -66,   -66,   -66,   -66,     0,     0,     0,   -66,   -66,
     -66,   -66,     0,   -66,   -66,   -54,   -54,   -54,   -54,   -54,
     -54,     0,     0,     0,   -54,   -54,   -54,   -54,     0,   -54,
     200,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,
     -57,   -57,   -57,   -57,     0,   -57,   -57,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,     0,   -63,   -63,   -63,   -63,
       0,   -63,   -63,   -64,   -64,   -64,   -64,   -64,   -64,     0,
       0,     0,   -64,   -64,   -64,   -64,     0,   -64,   -64,   -65,
     -65,   -65,   -65,   -65,   -65,     0,     0,     0,   -65,   -65,
     -65,   -65,     0,   -65,   -65,   -58,   -58,   -58,   -58,   -58,
     -58,     0,     0,     0,   -58,   -58,   -58,   -58,     0,   -58,
     -58,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,    80,
     -51,   -51,   -51,   -51,     0,   -51,   -55,   -55,   -55,   -55,
     -55,   -55,     0,     0,   -55,   -55,   -55,   -55,   -55,     0,
     -55,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,   -56,
     -56,   -56,   -56,   -56,     0,   -56,   -48,   -48,   -48,   -48,
     -48,   -48,     0,     0,     0,   -48,   -48,    78,    79,     0,
     -48,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,
     -51,   -51,   -51,   -51,     0,   -51,   -49,   -49,   -49,   -49,
     -49,   -49,     0,     0,     0,   -49,   -49,    78,    79,     0,
     -49,   -50,   -50,   -50,   -50,   -50,   -50,     0,     0,     0,
     -50,   -50,    78,    79,     0,   -50,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,     0,   -52,   -52,   -52,   -52,     0,
     -52,   -53,   -53,   -53,   -53,   -53,   -53,     0,     0,     0,
     -53,   -53,   -53,   -53,     0,   -53,   -55,   -55,   -55,   -55,
     -55,   -55,     0,     0,     0,   -55,   -55,   -55,   -55,     0,
     -55,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,
     -56,   -56,   -56,   -56,     0,   -56,   -43,   -43,   -43,   -43,
     -43,   -43,     0,     0,     0,    76,    77,     0,     0,     0,
     -43,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,
      76,    77,     0,     0,     0,   -44,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,     0,    76,    77,     0,     0,     0,
     -45,   -46,   -46,   -46,   -46,   -46,   -46,     0,     0,     0,
      76,    77,     0,     0,     0,   -46,   -47,   -47,   -47,   -47,
     -47,   -47,     0,     0,     0,    76,    77,     0,     0,     0,
     -47,    72,    73,    74,    75,   -42,   -42,     0,     0,     0,
       0,     0,     0,     0,     0,   -42
};

static const yytype_int16 yycheck[] =
{
       1,    37,     8,   195,     1,    24,     1,     8,   200,    16,
      10,    11,    12,    13,    14,    15,     5,    18,    25,    16,
       0,    16,    23,   215,    30,     5,    26,    26,    25,    30,
      25,    14,    15,    24,    32,    36,     3,     4,    36,     0,
     103,    26,    16,    26,     5,   103,    29,   110,   103,    16,
      17,   114,    26,    20,    14,    15,   103,    24,    25,    60,
       0,   104,    60,    16,    62,     5,    26,    25,   111,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    16,
      81,    14,    15,   103,    27,   103,     3,     4,   280,    26,
       0,    24,     0,     0,   286,     5,    27,     5,     5,    16,
      17,     3,     4,    20,   105,   103,   104,     0,    25,    26,
     111,   117,     5,   111,    16,    17,   117,   123,    20,     0,
       0,     2,   123,    25,    26,     5,    25,   128,   129,   130,
      26,    28,   130,    29,   170,    24,    10,    11,    12,    13,
      14,    15,    24,    25,   145,   146,   147,     3,     4,   147,
       6,     7,    26,     9,   155,   156,   157,    24,    25,   157,
      16,    17,    26,    26,    20,    29,    29,    24,    25,    25,
     168,    27,    26,    26,    26,   218,    29,    29,    26,    26,
      24,    29,    29,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,    26,    24,    25,    29,   200,
      24,    24,    28,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    26,    24,   216,    24,
     218,    24,    34,    35,    36,   288,   227,   228,   229,    26,
     288,   229,    24,   288,    25,   298,    26,    26,    26,   302,
     298,   288,    24,   298,   302,    24,   289,   302,    60,    24,
      26,   298,   253,   254,   255,   302,   299,   255,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,   288,    81,
     288,    24,    26,    25,    24,     3,     4,    26,   298,   280,
     298,    26,   302,    26,   302,   286,    26,    26,    16,    17,
     288,   289,    20,   105,    24,    28,     2,    25,   299,   111,
     298,   299,    26,    24,   302,    24,     3,     4,     5,     6,
       7,     8,     9,    26,    26,    26,   128,   129,   130,    16,
      17,    26,    26,    20,    26,    26,    26,    26,    25,    24,
      27,    28,    26,   145,   146,   147,     3,     4,     5,     6,
       7,     8,     9,   155,   156,   157,    -1,    -1,    41,    16,
      17,    59,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,    36,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,   229,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,   253,   254,   255,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    -1,   105,    25,    -1,    27,    28,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,   280,     6,
       7,    -1,     9,    -1,   286,    -1,   128,   129,   130,    16,
      17,    -1,    -1,    20,    -1,    -1,    -1,   299,    25,    -1,
      27,    -1,    -1,   145,   146,   147,     3,     4,     5,     6,
       7,     8,     9,   155,   156,   157,    -1,    -1,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,    36,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,   229,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,   253,   254,   255,    -1,    16,    17,     3,     4,    20,
      -1,    -1,    -1,   105,    25,    -1,    27,    28,    -1,   111,
      16,    17,    -1,    -1,    20,    -1,     3,     4,   280,    25,
      -1,    -1,    -1,    -1,   286,    -1,   128,   129,   130,    16,
      17,    -1,    -1,    20,    -1,    -1,    -1,   299,    25,    -1,
      -1,    -1,    -1,   145,   146,   147,     3,     4,     5,     6,
       7,     8,     9,   155,   156,   157,    -1,    -1,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,    36,    -1,    -1,    -1,   200,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,   227,   228,   229,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    81,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,   253,   254,   255,    -1,    16,    17,     3,     4,    20,
      -1,    -1,    -1,   105,    25,    -1,    27,    28,    -1,   111,
      16,    17,    -1,    -1,    20,    -1,     3,     4,   280,    25,
      -1,    -1,    -1,    -1,   286,    -1,   128,   129,   130,    16,
      17,    -1,    -1,    20,    -1,    -1,    -1,   299,    25,    -1,
      -1,    -1,    -1,   145,   146,   147,     3,     4,     5,     6,
       7,     8,     9,   155,   156,   157,    -1,    -1,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,    -1,    -1,    -1,    -1,   200,    60,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    76,    77,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,   227,   228,   229,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,   105,    16,    17,    -1,    -1,    20,
     111,   253,   254,   255,    25,    -1,    27,    28,     3,     4,
       5,     6,     7,    36,     9,    -1,    -1,    -1,    -1,   130,
      -1,    16,    17,    -1,    -1,    20,     3,     4,   280,    -1,
      25,    -1,    27,    28,   286,    -1,   147,    60,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,   157,   299,    25,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,   184,   185,   186,   187,   188,   189,   190,
     191,    26,   105,   194,   195,    -1,    -1,    -1,   111,   200,
      -1,    -1,    -1,   204,   205,   206,   207,   208,   209,   210,
     211,    36,    -1,   214,   215,   216,    -1,   130,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,    24,    -1,   147,    60,     3,     4,     5,     6,
       7,     8,     9,    -1,   157,    70,    71,    -1,    -1,    16,
      17,    -1,    -1,    20,   255,    -1,    81,    -1,    25,    -1,
      27,    28,    -1,    -1,    10,    11,    12,    13,    14,    15,
      -1,   184,   185,   186,   187,   188,   189,    -1,    24,   280,
     105,   194,   195,    -1,    -1,   286,   111,   200,    -1,    36,
      -1,   204,   205,   206,   207,   208,   209,    -1,   299,    -1,
      -1,   214,   215,   216,    -1,   130,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,   147,     3,     4,     5,     6,     7,     8,     9,
      -1,    60,   157,    80,    81,    -1,    16,    17,    -1,    -1,
      20,    -1,   255,    -1,    -1,    25,    -1,    27,    28,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,   105,   184,
     185,    -1,    -1,    -1,   111,    -1,    -1,   280,    -1,   194,
     195,    -1,    -1,   286,    -1,   200,   105,    -1,    -1,   204,
     205,    -1,   111,   130,    -1,    -1,   299,    -1,    -1,   214,
     215,   216,     3,     4,     5,     6,     7,     8,     9,    -1,
     147,   130,    -1,    -1,   229,    16,    17,    -1,    -1,    20,
     157,    -1,    -1,    -1,    25,    -1,    27,    28,   147,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,   157,    -1,
     255,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,    -1,    -1,   194,   195,    -1,
      -1,    -1,    -1,   200,    -1,   280,    -1,    -1,    -1,    -1,
      -1,   286,    -1,    -1,    -1,   194,   195,   214,   215,   216,
      -1,   200,    -1,    -1,   299,    -1,    -1,     3,     4,     5,
       6,     7,   229,     9,    -1,   214,   215,   216,    -1,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,
     229,    27,    28,     3,     4,     5,     6,     7,   255,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    25,   255,    27,    28,    -1,
      -1,    -1,    -1,   280,    -1,    -1,    -1,    -1,    -1,   286,
      -1,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
      -1,   280,   299,    -1,    16,    17,    -1,   286,    20,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    -1,    -1,    -1,
     299,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,     3,     4,     5,
       6,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,     3,     4,     5,     6,     7,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,     3,     4,     5,     6,     7,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,    27,
      28,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,     3,     4,     5,
       6,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,     3,     4,     5,     6,     7,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,     3,     4,     5,     6,     7,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,    27,
      28,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,     3,     4,     5,
       6,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,     3,     4,     5,     6,     7,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,
      -1,    26,    -1,    -1,    29,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    -1,    29,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    26,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    26,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    26,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    25,    26,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,    26,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    -1,    25,    26,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      -1,    -1,    25,    26,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,
      26,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    -1,    25,    26,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    25,    26,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,    -1,
      25,    26,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    22,    -1,    -1,    -1,    26,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    -1,    26,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    -1,    -1,    -1,    26,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    -1,    -1,    26,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      -1,    -1,    -1,    26,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    -1,    -1,    -1,
      26,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    -1,    -1,    26,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    -1,    26,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    26,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    24,    25,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    24,    25,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    24,
      25,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    24,    25,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    24,    25,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    20,    21,    22,    -1,    24,    25,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    24,    25,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    24,
      25,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    24,    25,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      -1,    24,    25,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    -1,    24,    25,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,    24,
      25,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    25,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      -1,    24,    25,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    -1,    24,    25,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,    24,
      25,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    24,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      24,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    24,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      24,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      24,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      24,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      24,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      24,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    24,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      24,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    24,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      24,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    31,    32,    33,    35,     1,    16,    25,    43,
      62,     0,    32,    24,    43,    25,    34,    26,    36,    24,
      44,    45,    62,    29,    26,    62,    37,    27,     3,     4,
       5,     6,     7,     9,    17,    20,    25,    27,    33,    38,
      39,    40,    41,    42,    46,    47,    48,    49,    50,    52,
      53,    54,    55,    56,    57,    58,    61,    62,    63,    43,
      25,    50,    25,    57,    57,    50,    39,    28,    41,    24,
      14,    15,    10,    11,    12,    13,    19,    20,    21,    22,
      18,    25,    50,    24,    50,    51,    26,    28,    54,    57,
      54,    55,    55,    55,    55,    56,    56,    57,    57,    52,
      52,    59,    60,    26,    24,    29,    26,    42,    51,    52,
       8,    24,    42,    51,    26,    42,    16,    25,    62,    16,
      16,     1,    16,    25,    62,     3,     4,    16,    17,    20,
      25,    52,    53,    54,    55,    56,    57,    58,    61,    62,
      63,    34,     3,     4,    16,    17,    20,    25,    58,    61,
      62,    63,     3,     4,    16,    17,    20,    25,    53,    54,
      55,    56,    57,    58,    61,    62,    63,     6,     7,     9,
      27,    38,    46,    47,    48,    49,    50,    50,    43,    24,
      43,    57,    57,    50,    14,    15,    10,    11,    12,    13,
      19,    20,    21,    22,    18,    25,    24,    57,    57,    50,
      25,    57,    57,    50,    14,    15,    10,    11,    12,    13,
      19,    20,    21,    22,    18,    25,    25,    50,    25,    39,
      24,    26,    26,    26,     3,     4,    16,    17,    20,    25,
      54,    57,    58,    61,    62,    63,    54,    55,    55,    55,
      55,    56,    56,    57,    57,    52,    60,    26,    60,    26,
       3,     4,    16,    17,    20,    25,    54,    57,    58,    61,
      62,    63,    54,    55,    55,    55,    55,    56,    56,    57,
      57,    52,    60,    50,    24,    51,    28,    57,    57,    50,
      25,    26,    26,    57,    57,    50,    25,    26,    26,    24,
      26,    60,    26,    60,    42,    51,    26,    26,     8,    24,
      42,    51,    26,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    31,    32,    32,    34,    33,    33,    36,
      37,    35,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    42,    42,    42,    43,    43,    44,    44,    45,    45,
      46,    47,    47,    48,    49,    50,    51,    51,    52,    52,
      53,    53,    53,    54,    54,    54,    54,    54,    55,    55,
      55,    56,    56,    56,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     4,     3,     0,
       0,    10,     3,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     0,     1,
       2,     5,     7,     3,     9,     1,     0,     1,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     2,     2,     1,     4,     1,
       3,     1,     0,     1,     1,     3,     1,     1,     1
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
#line 55 "src/bison/math.y"
                                { list_push(&root->children, (yyvsp[0].ast)); }
#line 1973 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 56 "src/bison/math.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 1979 "src/bison/grammar.c"
    break;

  case 6: /* @1: %empty  */
#line 63 "src/bison/math.y"
                                 {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].ast)->value.symref->symbol);
        if (sym) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("redeclaration of '%s'\n", error_cursor, (yyvsp[0].ast)->value.symref->symbol->name);
            (yyval.ast) = NULL;
        } else {
            (yyval.ast) = ast_symref_init(
                symbol_init_copy(context_declare_variable(current_context, (yyvsp[0].ast)->value.symref))
            );
        }
        ast_free((yyvsp[0].ast));
    }
#line 1997 "src/bison/grammar.c"
    break;

  case 7: /* declaration: LET declarator @1 ';'  */
#line 75 "src/bison/math.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 2005 "src/bison/grammar.c"
    break;

  case 8: /* declaration: LET error ';'  */
#line 78 "src/bison/math.y"
                    {
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 2015 "src/bison/grammar.c"
    break;

  case 9: /* @2: %empty  */
#line 85 "src/bison/math.y"
                                          {
        if (current_context->current_scope > 1) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("CIPL forbids nested functions\n", error_cursor);
            (yyval.ast) = NULL;
        } else {
            Symbol *sym = context_has_symbol(current_context, (yyvsp[-1].ast)->value.symref->symbol);
            if (sym) {
                yyerror(NULL);
                CIPL_PERROR_CURSOR("redefinition of '%s'\n", error_cursor, (yyvsp[-1].ast)->value.symref->symbol->name);
                (yyval.ast) = NULL;
            } else {
                previous_context = current_context;
                list_push(&contexts, context_init((yyvsp[-1].ast)->value.symref->symbol->name));
                current_context = list_peek_last(&contexts);
                printf("context scope: %d\n", current_context->current_scope);
                (yyval.ast) = ast_symref_init(
                    symbol_init_copy(context_declare_function(previous_context, (yyvsp[-1].ast)->value.symref))
                );
            }
        }
        ast_free((yyvsp[-1].ast));
    }
#line 2043 "src/bison/grammar.c"
    break;

  case 10: /* $@3: %empty  */
#line 107 "src/bison/math.y"
                      {
        LIST_FOR_EACH((yyvsp[-1].list), {
            context_declare_variable(current_context, ((AST *)__IT__->data)->value.symref);
        });
    }
#line 2053 "src/bison/grammar.c"
    break;

  case 11: /* func_declaration: LET declarator '(' @2 id_list.opt ')' $@3 '{' block_item_list.opt '}'  */
#line 111 "src/bison/math.y"
                                  {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-6].ast), ast_params_init((yyvsp[-5].list)), ast_blockitems_init((yyvsp[-1].list)));
        current_context = list_peek(&contexts, 0);
    }
#line 2062 "src/bison/grammar.c"
    break;

  case 12: /* compound_stmt: '{' block_item_list.opt '}'  */
#line 124 "src/bison/math.y"
                                           {
        printf("dei match aqui?\n");
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        current_context = list_peek(&contexts, current_context->current_scope - 1);
    }
#line 2072 "src/bison/grammar.c"
    break;

  case 13: /* block_item_list.opt: block_item_list  */
#line 131 "src/bison/math.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 2078 "src/bison/grammar.c"
    break;

  case 14: /* block_item_list.opt: %empty  */
#line 132 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2084 "src/bison/grammar.c"
    break;

  case 15: /* block_item_list: block_item_list block_item  */
#line 135 "src/bison/math.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2090 "src/bison/grammar.c"
    break;

  case 16: /* block_item_list: block_item  */
#line 136 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2096 "src/bison/grammar.c"
    break;

  case 25: /* declarator: '(' declarator ')'  */
#line 151 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2102 "src/bison/grammar.c"
    break;

  case 26: /* id_list: id_list ',' id  */
#line 154 "src/bison/math.y"
                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2108 "src/bison/grammar.c"
    break;

  case 27: /* id_list: id  */
#line 155 "src/bison/math.y"
         { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2114 "src/bison/grammar.c"
    break;

  case 28: /* id_list.opt: %empty  */
#line 158 "src/bison/math.y"
                    { (yyval.list) = NULL; }
#line 2120 "src/bison/grammar.c"
    break;

  case 30: /* expr_stmt: expression ';'  */
#line 162 "src/bison/math.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2126 "src/bison/grammar.c"
    break;

  case 31: /* cond_stmt: IF '(' expression ')' statement  */
#line 165 "src/bison/math.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 2134 "src/bison/grammar.c"
    break;

  case 32: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 168 "src/bison/math.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2142 "src/bison/grammar.c"
    break;

  case 33: /* jmp_stmt: RETURN expression ';'  */
#line 173 "src/bison/math.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 2148 "src/bison/grammar.c"
    break;

  case 34: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 176 "src/bison/math.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2156 "src/bison/grammar.c"
    break;

  case 36: /* expression.opt: %empty  */
#line 184 "src/bison/math.y"
                       { (yyval.ast) = NULL; }
#line 2162 "src/bison/grammar.c"
    break;

  case 39: /* assign_expr: unary_expr '=' assign_expr  */
#line 189 "src/bison/math.y"
                                 { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2168 "src/bison/grammar.c"
    break;

  case 41: /* eq_expr: eq_expr EQ rel_expr  */
#line 193 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("==", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2174 "src/bison/grammar.c"
    break;

  case 42: /* eq_expr: eq_expr NE rel_expr  */
#line 194 "src/bison/math.y"
                          { (yyval.ast) = ast_cmpop_init("!=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2180 "src/bison/grammar.c"
    break;

  case 44: /* rel_expr: rel_expr LT add_expr  */
#line 198 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2186 "src/bison/grammar.c"
    break;

  case 45: /* rel_expr: rel_expr LE add_expr  */
#line 199 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init("<=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2192 "src/bison/grammar.c"
    break;

  case 46: /* rel_expr: rel_expr GT add_expr  */
#line 200 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2198 "src/bison/grammar.c"
    break;

  case 47: /* rel_expr: rel_expr GE add_expr  */
#line 201 "src/bison/math.y"
                           { (yyval.ast) = ast_cmpop_init(">=", (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2204 "src/bison/grammar.c"
    break;

  case 49: /* add_expr: add_expr '+' mult_expr  */
#line 205 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('+', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2210 "src/bison/grammar.c"
    break;

  case 50: /* add_expr: add_expr '-' mult_expr  */
#line 206 "src/bison/math.y"
                             { (yyval.ast) = ast_binop_init('-', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2216 "src/bison/grammar.c"
    break;

  case 52: /* mult_expr: mult_expr '*' unary_expr  */
#line 210 "src/bison/math.y"
                               { (yyval.ast) = ast_binop_init('*', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2222 "src/bison/grammar.c"
    break;

  case 53: /* mult_expr: mult_expr '/' unary_expr  */
#line 211 "src/bison/math.y"
                               { (yyval.ast) = ast_binop_init('/', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2228 "src/bison/grammar.c"
    break;

  case 55: /* unary_expr: '!' unary_expr  */
#line 215 "src/bison/math.y"
                     { (yyval.ast) = ast_uniop_init('!', (yyvsp[0].ast)); }
#line 2234 "src/bison/grammar.c"
    break;

  case 56: /* unary_expr: '-' unary_expr  */
#line 216 "src/bison/math.y"
                     { (yyval.ast) = ast_uniop_init('-', (yyvsp[0].ast)); }
#line 2240 "src/bison/grammar.c"
    break;

  case 58: /* postfix_expr: postfix_expr '(' arg_expr_list.opt ')'  */
#line 220 "src/bison/math.y"
                                             {
        printf("function call!\n");
        (yyval.ast) = NULL;
    }
#line 2249 "src/bison/grammar.c"
    break;

  case 59: /* arg_expr_list: assign_expr  */
#line 226 "src/bison/math.y"
                           { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2255 "src/bison/grammar.c"
    break;

  case 60: /* arg_expr_list: arg_expr_list ',' assign_expr  */
#line 227 "src/bison/math.y"
                                    { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2261 "src/bison/grammar.c"
    break;

  case 62: /* arg_expr_list.opt: %empty  */
#line 231 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2267 "src/bison/grammar.c"
    break;

  case 63: /* primary_expr: id  */
#line 234 "src/bison/math.y"
                 {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].ast)->value.symref->symbol);
        if (!sym) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("'%s' undeclared (first use in this function)\n", (yyvsp[0].ast)->value.symref->symbol->def_pos, (yyvsp[0].ast)->value.symref->symbol->name);
            // $$ Cant be NULL because crash everything up, the solution is push to AST an undeclared variable
            (yyval.ast) = ast_symref_init(symbol_init_copy((yyvsp[0].ast)->value.symref->symbol)); // NULL
        } else {
            (yyval.ast) = ast_symref_init(symbol_init_copy(sym));
        }
        ast_free((yyvsp[0].ast));
    }
#line 2284 "src/bison/grammar.c"
    break;

  case 65: /* primary_expr: '(' expression ')'  */
#line 247 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2290 "src/bison/grammar.c"
    break;

  case 66: /* id: NAME  */
#line 250 "src/bison/math.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 2296 "src/bison/grammar.c"
    break;

  case 67: /* constant: NUMBER_REAL  */
#line 253 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 2302 "src/bison/grammar.c"
    break;

  case 68: /* constant: NUMBER_INT  */
#line 254 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 2308 "src/bison/grammar.c"
    break;


#line 2312 "src/bison/grammar.c"

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

#line 257 "src/bison/math.y"


void yyerror(char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
}
