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
  YYSYMBOL_NAME = 5,                       /* NAME  */
  YYSYMBOL_BUILT_IN = 6,                   /* BUILT_IN  */
  YYSYMBOL_MULT = 7,                       /* MULT  */
  YYSYMBOL_ADD = 8,                        /* ADD  */
  YYSYMBOL_REL = 9,                        /* REL  */
  YYSYMBOL_AND = 10,                       /* AND  */
  YYSYMBOL_OR = 11,                        /* OR  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_COLON = 13,                     /* COLON  */
  YYSYMBOL_DL_DG = 14,                     /* DL_DG  */
  YYSYMBOL_EXCLAMATION = 15,               /* EXCLAMATION  */
  YYSYMBOL_PERCENT = 16,                   /* PERCENT  */
  YYSYMBOL_QUESTION = 17,                  /* QUESTION  */
  YYSYMBOL_STR_LITERAL = 18,               /* STR_LITERAL  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_LET = 23,                       /* LET  */
  YYSYMBOL_NIL = 24,                       /* NIL  */
  YYSYMBOL_TYPE = 25,                      /* TYPE  */
  YYSYMBOL_THEN = 26,                      /* THEN  */
  YYSYMBOL_27_ = 27,                       /* ';'  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_prog = 35,                      /* prog  */
  YYSYMBOL_external_declaration = 36,      /* external_declaration  */
  YYSYMBOL_declaration = 37,               /* declaration  */
  YYSYMBOL_38_1 = 38,                      /* @1  */
  YYSYMBOL_func_declaration = 39,          /* func_declaration  */
  YYSYMBOL_40_2 = 40,                      /* @2  */
  YYSYMBOL_41_3 = 41,                      /* $@3  */
  YYSYMBOL_compound_stmt = 42,             /* compound_stmt  */
  YYSYMBOL_43_4 = 43,                      /* $@4  */
  YYSYMBOL_44_block_item_list_opt = 44,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 45,           /* block_item_list  */
  YYSYMBOL_block_item = 46,                /* block_item  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_declarator = 48,                /* declarator  */
  YYSYMBOL_id_list = 49,                   /* id_list  */
  YYSYMBOL_50_id_list_opt = 50,            /* id_list.opt  */
  YYSYMBOL_expr_stmt = 51,                 /* expr_stmt  */
  YYSYMBOL_cond_stmt = 52,                 /* cond_stmt  */
  YYSYMBOL_jmp_stmt = 53,                  /* jmp_stmt  */
  YYSYMBOL_iter_stmt = 54,                 /* iter_stmt  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_56_expression_opt = 56,         /* expression.opt  */
  YYSYMBOL_assign_expr = 57,               /* assign_expr  */
  YYSYMBOL_logical_or_expr = 58,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 59,          /* logical_and_expr  */
  YYSYMBOL_eq_expr = 60,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 61,                  /* rel_expr  */
  YYSYMBOL_dl_dg_expr = 62,                /* dl_dg_expr  */
  YYSYMBOL_add_expr = 63,                  /* add_expr  */
  YYSYMBOL_mult_expr = 64,                 /* mult_expr  */
  YYSYMBOL_unary_expr = 65,                /* unary_expr  */
  YYSYMBOL_unary_ops = 66,                 /* unary_ops  */
  YYSYMBOL_postfix_expr = 67,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 68,             /* arg_expr_list  */
  YYSYMBOL_69_arg_expr_list_opt = 69,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 70,              /* primary_expr  */
  YYSYMBOL_id = 71,                        /* id  */
  YYSYMBOL_constant = 72                   /* constant  */
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
#define YYLAST   3597

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  313

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


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
      28,    29,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    61,    64,    65,    68,    68,    86,    94,
     121,    94,   138,   138,   153,   154,   157,   158,   161,   162,
     165,   166,   167,   168,   169,   172,   173,   176,   177,   180,
     181,   184,   187,   190,   195,   198,   203,   206,   207,   210,
     211,   214,   215,   221,   222,   228,   229,   235,   236,   242,
     243,   247,   253,   254,   260,   261,   267,   268,   274,   275,
     276,   277,   280,   281,   286,   287,   290,   291,   294,   307,
     308,   311,   312,   315,   316,   317
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
  "NUMBER_REAL", "NAME", "BUILT_IN", "MULT", "ADD", "REL", "AND", "OR",
  "EQ", "COLON", "DL_DG", "EXCLAMATION", "PERCENT", "QUESTION",
  "STR_LITERAL", "IF", "ELSE", "FOR", "RETURN", "LET", "NIL", "TYPE",
  "THEN", "';'", "'('", "')'", "'{'", "'}'", "','", "'='", "$accept",
  "prog", "external_declaration", "declaration", "@1", "func_declaration",
  "@2", "$@3", "compound_stmt", "$@4", "block_item_list.opt",
  "block_item_list", "block_item", "statement", "declarator", "id_list",
  "id_list.opt", "expr_stmt", "cond_stmt", "jmp_stmt", "iter_stmt",
  "expression", "expression.opt", "assign_expr", "logical_or_expr",
  "logical_and_expr", "eq_expr", "rel_expr", "dl_dg_expr", "add_expr",
  "mult_expr", "unary_expr", "unary_ops", "postfix_expr", "arg_expr_list",
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
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    59,    40,    41,
     123,   125,    44,    61
};
#endif

#define YYPACT_NINF (-204)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,     6,    21,    51,    66,    69,   -12,    67,   199,    32,
     259,   264,  -204,    87,   111,    19,    11,    25,   302,    14,
     115,    30,    29,    61,   334,    54,   141,    75,  1512,   124,
    1715,  2276,  2303,  1451,  2919,  2925,  2951,   157,   167,  2957,
       8,  2311,  2983,  1744,  1773,   108,  1802,  1831,  1860,  1889,
    1918,  1947,  1976,   180,   206,    93,   139,   285,   663,   780,
     946,  1499,  2683,  2957,  2338,  2346,  2373,  2381,  2983,  2723,
     226,   236,   140,   137,  2005,  2034,  2989,  2989,  2989,  2989,
    2989,  2989,  2989,  2989,  2957,  2710,   127,   240,   244,   246,
    2063,  2408,   186,  3533,   353,   819,  1010,  3541,  1100,  1167,
    3562,   251,   203,   208,   273,   960,  2723,  3015,  2416,   159,
     281,   233,  1098,  2442,  2092,   284,  1098,  2121,   295,   306,
      32,   326,   274,   296,  2465,  2473,  1512,   349,   351,   368,
      32,   369,  1538,  2500,  2508,  2535,  2543,  2983,   370,   130,
     468,   142,    44,   182,  3510,  3268,   405,  2983,  2570,  2578,
    2605,  2613,   371,  3353,  3361,  3383,  3391,  3413,  2983,  2989,
    3421,  3443,  3451,  3473,    89,   874,   882,   909,  1126,  2983,
      36,   448,   272,   116,   248,  3136,    17,   309,  3015,  1276,
    1306,  1626,  2233,   181,   381,  2957,  1512,   328,   424,   484,
     580,   640,   393,   392,   397,  1715,  2150,   406,   420,  3021,
    3021,  3021,  3021,  3021,  3021,  3021,  3021,  2983,   561,   127,
    2179,   421,  3570,   127,   422,  3047,  3047,  3047,  3047,  3047,
    3047,  3047,  3047,  3015,  2640,   127,  2983,  2723,   426,  1715,
     736,   427,   322,   433,  2648,   456,   612,   768,  3144,  3167,
    2983,   524,  3291,  3021,  3175,  3198,  3206,  3229,   618,   413,
     507,  3299,   569,   624,  3322,   445,   446,  3481,   452,  2241,
     718,  2745,  2753,  2779,  2787,  2983,   462,  3069,  3047,  2813,
    2821,  2847,  2855,   350,  1136,  1202,  3077,  1216,  1318,  3103,
     325,   457,   466,   469,   796,   366,  2208,   481,  3330,   127,
    2675,  3503,   482,  3111,   127,  2268,   960,  2723,  1025,  3237,
     491,  2881,   492,  1589,   471,  3260,  2889,   960,  2442,  1657,
     503,   960,  1686
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -204,  -204,   511,   184,   438,  -204,  -204,  -204,   -22,  -123,
    -194,  -204,   505,   -55,    -7,  -204,  -204,   -73,   -41,   -35,
     -17,     3,     1,  1356,  1363,  1265,  1188,  1154,   867,  1037,
     984,   168,   324,   480,  -204,  -203,   636,    -1,   792
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    43,    17,     5,    19,    27,    44,    30,
      45,    46,    47,    48,    10,    21,    22,    49,    50,    51,
      52,    53,    89,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   103,   104,    65,    66,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,   232,    15,   195,     1,    29,   256,     6,   121,   127,
     258,     7,     8,   128,   129,    14,    -9,    -9,    23,   122,
     123,    12,   281,    26,   222,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   188,    71,     9,   285,   130,   118,   119,   131,
      -9,   150,    70,   -29,     1,    72,   -52,   215,    18,   -52,
     109,    -3,    20,   202,   -45,   -45,   -45,   114,    25,   -30,
     120,   117,    24,   229,   189,   -39,    -5,   150,   -39,    -4,
     190,    87,    88,   -45,    -3,   162,   162,   162,   162,   162,
     162,   162,   162,   187,   -10,   181,   300,    -2,   191,    -5,
     -28,   302,    -4,   -28,   -71,   -71,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,    76,    28,   181,   110,   192,    88,
      -2,    -8,   150,   194,   115,    -7,   193,   -74,   -74,   121,
     -39,   -74,   -74,   197,   -11,   218,   -45,   -45,   -45,   121,
     164,   165,   166,   167,    -8,    33,   150,   -13,    -7,    73,
     198,   199,    34,    35,    36,   -45,   150,   -11,   -45,    77,
     -41,   168,   -43,   -43,   201,   169,   -67,   150,   162,   -39,
     -13,   211,   -32,   -32,   -32,   -32,   -41,   -32,   150,    91,
     -27,   -43,   214,   -27,   -32,   -32,   -32,   181,   -32,   112,
     -32,   -32,   -32,   -32,     4,    68,     4,   -32,   228,   -32,
     -32,   -47,   -47,   -47,   -47,    69,    77,   -42,   246,   246,
     246,   246,   246,   246,   246,   246,   150,    75,   181,   226,
     146,   -47,   181,   -42,   271,   271,   271,   271,   271,   271,
     271,   271,   181,   188,   181,   150,   -72,   -72,   283,   282,
      88,    85,   -64,   -36,   188,   -64,   146,   -66,   188,   150,
     107,   303,   246,   287,    93,    93,    93,    93,    93,    93,
      93,   100,   309,    90,   177,   189,   312,   -47,   -47,   -47,
     -47,   190,   -65,    -6,   150,   -65,   189,   271,   292,   105,
     189,   -38,   190,   106,   187,   177,   190,   -47,   -40,   191,
     -47,   146,   -43,   -43,   217,   187,    -6,    16,   181,   187,
     191,   -25,   -25,   181,   191,   -43,   -43,    78,   304,   192,
      88,   -43,   108,   -71,   -43,   146,   -71,   150,   113,   310,
     192,   193,   -43,   116,   192,   208,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -71,   -72,   146,   212,   -72,   -26,
     -26,   -21,   -21,   -21,   -21,   -72,   -21,   146,   -54,   122,
     123,   -54,   223,   -21,   -21,   -21,   224,   -21,   -21,   -21,
     -21,   -21,   -21,   286,   -40,   -25,   -21,   -40,   -21,   -21,
     -44,   -44,   217,   -44,   -44,    78,   147,   242,   242,   242,
     242,   242,   242,   242,   254,   146,   196,   177,   -71,   -44,
     -44,   177,   -44,   267,   267,   267,   267,   267,   267,   267,
     279,   177,   147,   177,   146,   -72,   -25,   298,   210,   -36,
     159,   159,   159,   159,   159,   159,   159,   159,   146,   227,
     178,   288,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     230,   -38,   202,   -46,   -46,   -46,   231,   -20,   -20,   -20,
     -20,   178,   -20,   146,   -54,   233,   293,   147,   207,   -20,
     -20,   -20,   -46,   -20,   -20,   -20,   -20,   -20,   -20,   234,
     257,   259,   -20,   284,   -20,   -20,   -26,   177,   216,   -41,
     -26,   147,   177,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   147,   216,   -42,   -40,   290,   146,   -41,   200,   -41,
     -41,   291,   147,   159,   -74,   -74,   295,   -22,   -22,   -22,
     -22,   -42,   -22,   147,   -42,   296,   297,   -41,   308,   -22,
     -22,   -22,   178,   -22,   -22,   -22,   -22,   -22,   -22,   152,
     299,   301,   -22,    13,   -22,   -22,   -48,   -48,   -48,   -48,
     305,   306,   148,   243,   243,   243,   243,   243,   243,   243,
     243,   147,   311,   178,   200,   -42,   -48,   178,     0,   268,
     268,   268,   268,   268,   268,   268,   268,   178,   148,   178,
     147,    74,     0,   -42,     0,     0,   160,   160,   160,   160,
     160,   160,   160,   160,   147,     0,   179,   243,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,     0,     0,   -51,   -51,
     -51,   -51,     0,   -23,   -23,   -23,   -23,   179,   -23,   147,
     -57,     0,   268,   148,   -57,   -23,   -23,   -23,   -51,   -23,
     -23,   -23,   -23,   -23,   -23,     0,     0,     0,   -23,     0,
     -23,   -23,     0,   178,     0,     0,     0,   148,   178,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   148,   -44,   -44,
     201,     0,   147,   -50,   -50,   -50,   -50,     0,   148,   160,
     -73,   -73,     0,   -24,   -24,   -24,   -24,   -44,   -24,   148,
       0,     0,     0,   -50,     0,   -24,   -24,   -24,   179,   -24,
     -24,   -24,   -24,   -24,   -24,     0,     0,     0,   -24,     0,
     -24,   -24,    79,   -45,   -45,   -45,     0,     0,   149,   244,
     244,   244,   244,   244,   244,   244,   244,   148,     0,   179,
     -45,     0,     0,   179,     0,   269,   269,   269,   269,   269,
     269,   269,   269,   179,   149,   179,   148,     0,     0,     0,
       0,     0,   161,   161,   161,   161,   161,   161,   161,   161,
     148,     0,   180,   244,     0,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,     0,     0,     0,     0,     0,     0,   -31,
     -31,   -31,   -31,   180,   -31,   148,   -74,   -74,   269,   149,
     -74,   -31,   -31,   -31,     0,   -31,   -31,   -31,   -31,   -31,
     -31,     0,     0,     0,   -31,     0,   -31,   -31,     0,   179,
       0,     0,     0,   149,   179,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   149,     0,     0,     0,     0,   148,   -47,
     -47,   -47,   -47,     0,   149,   161,   -71,   -71,     0,   -34,
     -34,   -34,   -34,     0,   -34,   149,     0,   -47,     0,     0,
       0,   -34,   -34,   -34,   180,   -34,   -34,   -34,   -34,   -34,
     -34,     0,     0,     0,   -34,     0,   -34,   -34,    79,   -46,
     -46,   -46,     0,     0,   151,   245,   245,   245,   245,   245,
     245,   245,   245,   149,     0,   180,   -46,     0,     0,   180,
       0,   270,   270,   270,   270,   270,   270,   270,   270,   180,
     151,   180,   149,     0,     0,     0,     0,     0,   163,   163,
     163,   163,   163,   163,   163,   163,   149,     0,   182,   245,
       0,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,   182,
       0,   149,   -73,   -73,   270,   151,   -73,   -73,     0,   143,
     -71,   -71,     0,     0,   -71,   -71,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,     0,   180,     0,     0,     0,   151,
     180,     0,     0,     0,     0,   143,     0,   -72,   -72,   151,
       0,   -72,   -72,     0,   149,     0,    96,     0,    98,    99,
     151,   163,     0,   174,    80,   -49,   -49,   -49,   -49,    81,
      82,   151,     0,    31,    32,   124,   125,     0,    33,     0,
     182,     0,     0,   -49,   174,    34,    35,    36,     0,   183,
     143,   184,   185,     0,    41,     0,     0,     0,    42,     0,
     186,   247,   247,   247,   247,   247,   247,   247,   247,   151,
       0,   182,     0,     0,   143,   182,     0,   272,   272,   272,
     272,   272,   272,   272,   272,   182,     0,   182,   151,   -48,
     -48,   -48,   -48,     0,     0,   143,   145,     0,   -13,   -13,
     -13,   -13,   151,   -13,     0,   247,   143,   -48,     0,     0,
     -13,   -13,   -13,     0,   -13,   -13,   -13,   -13,   -13,   -13,
       0,     0,   145,   -13,     0,   -13,   -13,   151,     0,     0,
     272,     0,     0,     0,    97,     0,   143,   143,   143,   250,
     176,   252,   253,     0,   143,     0,   174,     0,     0,   144,
     174,   182,   174,   174,   174,   275,   182,   277,   278,     0,
     174,   176,   174,   143,     0,     0,     0,   145,     0,     0,
     151,    31,    32,   124,   125,   144,    33,   143,     0,   -51,
     -51,   -51,   -51,    34,    35,    36,     0,    37,     0,    38,
      39,   145,    41,   175,     0,     0,    42,   -51,   126,     0,
       0,     0,   143,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,     0,   145,     0,   175,   218,   -46,   -46,   -46,     0,
     144,     0,     0,   145,   -75,   -75,   174,     0,   -75,   -75,
       0,   174,     0,     0,     0,   -46,     0,     0,   -46,     0,
       0,     0,     0,     0,   144,   143,   -50,   -50,   -50,   -50,
       0,     0,     0,   145,   145,   145,   145,   251,   145,   145,
       0,   145,     0,   176,   -50,   144,   142,   176,     0,   176,
     176,   176,   176,   276,   176,   176,   144,   176,     0,   176,
     145,   -48,   -48,   -48,   -48,     0,     0,     0,     0,     0,
       0,     0,   142,     0,   145,   -51,   -51,   -51,   -51,     0,
     141,   -48,    95,     0,   -48,     0,   144,   144,   144,   144,
     173,   144,   144,     0,   144,   -51,   175,     0,   -51,   145,
     175,     0,   175,   175,   175,   175,   141,   175,   175,     0,
     175,   173,   175,   144,     0,    94,     0,   142,     0,     0,
       0,     0,     0,   176,   172,     0,     0,   144,   176,     0,
       0,     0,     0,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   142,   145,     0,     0,   172,     0,     0,     0,     0,
       0,   141,   144,     0,   225,   -56,     0,   140,   -56,   -56,
       0,     0,   142,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,     0,     0,   142,     0,   141,   175,   -50,   -50,   -50,
     -50,   175,     0,   140,   -62,   -62,     0,     0,   -62,   -62,
       0,    92,     0,     0,     0,   144,   141,   -50,     0,     0,
     -50,   171,     0,   142,   142,   249,     0,   141,     0,     0,
       0,   142,     0,   173,     0,     0,     0,   173,     0,   173,
     173,   274,   171,     0,     0,     0,     0,   173,   140,   173,
     142,     0,     0,     0,     0,     0,     0,   141,   248,     0,
       0,     0,     0,     0,   142,   141,     0,   172,   138,     0,
       0,   172,   140,   172,   273,   139,     0,     0,     0,     0,
       0,   172,     0,   172,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   140,   138,     0,     0,     0,   141,     0,
       0,   139,     0,     0,   140,     0,     0,     0,     0,     0,
     101,     0,   102,   173,     0,     0,     0,     0,   173,   170,
       0,     0,     0,   141,   -60,   -60,   -60,   -60,     0,   -60,
       0,     0,   142,   111,   241,     0,   -60,   -60,   -60,   138,
     170,     0,   140,     0,   171,   -60,   139,   172,   171,   -60,
     266,     0,   172,     0,     0,     0,     0,     0,   171,     0,
     171,   140,     0,   138,     0,     0,   141,     0,     0,     0,
     139,     0,     0,     0,     0,   140,    83,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   138,   -12,   -12,   -12,   -12,     0,
     -12,   139,     0,     0,     0,   138,   -52,   -12,   -12,   -12,
     140,   -12,   139,   -12,   -12,   -12,   -12,     0,     0,     0,
     -12,     0,   -12,   -12,     0,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,     0,   171,     0,     0,     0,     0,   171,
       0,     0,     0,   255,     0,   102,   -74,   -74,     0,   102,
     139,   -74,   170,   140,     0,     0,   170,     0,     0,   280,
       0,   102,   138,     0,     0,     0,   170,     0,   170,   139,
       0,     0,   -32,   -32,   -32,   -32,   138,   -32,     0,     0,
       0,     0,     0,   139,   -32,   -32,   -32,     0,   -32,   307,
     -32,   -32,   -32,   -32,     0,     0,     0,   -32,     0,   -32,
     -32,   138,     0,     0,     0,     0,     0,     0,   139,     0,
       0,     0,     0,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,     0,     0,     0,     0,   102,     0,     0,     0,     0,
     102,     0,   170,     0,   -68,   -68,     0,   170,   -68,   -68,
     -33,   -33,   -33,   -33,   138,   -33,     0,     0,     0,     0,
       0,   139,   -33,   -33,   -33,     0,   -33,   -33,   -33,   -33,
     -33,   -33,     0,     0,     0,   -33,     0,   -33,   -33,   -35,
     -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,     0,
       0,   -35,   -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,
     -35,     0,     0,     0,   -35,     0,   -35,   -35,    31,    32,
     124,   125,     0,    33,     0,     0,     0,     0,     0,     0,
      34,    35,    36,     0,    37,     0,    38,    39,    40,    41,
       0,     0,     0,    42,     0,   126,   -15,   -18,   -18,   -18,
     -18,     0,   -18,     0,     0,     0,     0,     0,     0,   -18,
     -18,   -18,     0,   -18,     0,   -18,   -18,   -18,   -18,     0,
       0,     0,   -18,     0,   -18,   -18,   -21,   -21,   -21,   -21,
       0,   -21,     0,     0,     0,     0,     0,     0,   -21,   -21,
     -21,     0,   -21,     0,   -21,   -21,   -21,   -21,     0,     0,
       0,   -21,     0,   -21,   -21,    31,    32,   124,   125,     0,
      33,     0,     0,     0,     0,     0,     0,    34,    35,    36,
       0,    37,     0,    38,    39,    40,    41,     0,     0,     0,
      42,     0,   126,   -14,   -17,   -17,   -17,   -17,     0,   -17,
       0,     0,     0,     0,     0,     0,   -17,   -17,   -17,     0,
     -17,     0,   -17,   -17,   -17,   -17,     0,     0,     0,   -17,
       0,   -17,   -17,   -19,   -19,   -19,   -19,     0,   -19,     0,
       0,     0,     0,     0,     0,   -19,   -19,   -19,     0,   -19,
       0,   -19,   -19,   -19,   -19,     0,     0,     0,   -19,     0,
     -19,   -19,   -20,   -20,   -20,   -20,     0,   -20,     0,     0,
       0,     0,     0,     0,   -20,   -20,   -20,     0,   -20,     0,
     -20,   -20,   -20,   -20,     0,     0,     0,   -20,     0,   -20,
     -20,   -22,   -22,   -22,   -22,     0,   -22,     0,     0,     0,
       0,     0,     0,   -22,   -22,   -22,     0,   -22,     0,   -22,
     -22,   -22,   -22,     0,     0,     0,   -22,     0,   -22,   -22,
     -23,   -23,   -23,   -23,     0,   -23,     0,     0,     0,     0,
       0,     0,   -23,   -23,   -23,     0,   -23,     0,   -23,   -23,
     -23,   -23,     0,     0,     0,   -23,     0,   -23,   -23,   -24,
     -24,   -24,   -24,     0,   -24,     0,     0,     0,     0,     0,
       0,   -24,   -24,   -24,     0,   -24,     0,   -24,   -24,   -24,
     -24,     0,     0,     0,   -24,     0,   -24,   -24,   -16,   -16,
     -16,   -16,     0,   -16,     0,     0,     0,     0,     0,     0,
     -16,   -16,   -16,     0,   -16,     0,   -16,   -16,   -16,   -16,
       0,     0,     0,   -16,     0,   -16,   -16,   -31,   -31,   -31,
     -31,     0,   -31,     0,     0,     0,     0,     0,     0,   -31,
     -31,   -31,     0,   -31,     0,   -31,   -31,   -31,   -31,     0,
       0,     0,   -31,     0,   -31,   -31,   -34,   -34,   -34,   -34,
       0,   -34,     0,     0,     0,     0,     0,     0,   -34,   -34,
     -34,     0,   -34,     0,   -34,   -34,   -34,   -34,     0,     0,
       0,   -34,     0,   -34,   -34,   -33,   -33,   -33,   -33,     0,
     -33,     0,     0,     0,     0,     0,     0,   -33,   -33,   -33,
       0,   -33,     0,   -33,   -33,   -33,   -33,     0,     0,     0,
     -33,     0,   -33,   -33,   -35,   -35,   -35,   -35,     0,   -35,
       0,     0,     0,     0,     0,     0,   -35,   -35,   -35,     0,
     -35,     0,   -35,   -35,   -35,   -35,     0,     0,     0,   -35,
       0,   -35,   -35,    -8,    -8,    -8,    -8,     0,    -8,     0,
       0,     0,     0,     0,     0,    -8,    -8,    -8,     0,    -8,
       0,    -8,    -8,    -8,    -8,     0,     0,     0,    -8,     0,
      -8,    -8,    -7,    -7,    -7,    -7,     0,    -7,     0,     0,
       0,     0,     0,     0,    -7,    -7,    -7,     0,    -7,     0,
      -7,    -7,    -7,    -7,     0,     0,     0,    -7,     0,    -7,
      -7,   -13,   -13,   -13,   -13,     0,   -13,     0,     0,     0,
       0,     0,     0,   -13,   -13,   -13,     0,   -13,     0,   -13,
     -13,   -13,   -13,     0,     0,     0,   -13,     0,   -13,   -13,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,
       0,   -69,   -69,     0,     0,   -69,   -69,     0,     0,   -70,
     -70,     0,     0,   -70,   -70,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     0,     0,     0,     0,     0,   -63,   -63,     0,     0,
     -63,   -63,     0,   -74,   -74,     0,     0,     0,     0,   -74,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,     0,
     -73,   -73,     0,     0,     0,     0,   -73,     0,   -75,   -75,
       0,     0,     0,     0,   -75,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,     0,     0,     0,     0,   -56,    86,     0,     0,     0,
       0,   -56,     0,   -62,   -62,     0,     0,     0,     0,   -62,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,     0,
     -68,   -68,     0,     0,     0,     0,   -68,     0,   -69,   -69,
       0,     0,     0,     0,   -69,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,     0,     0,     0,     0,   -70,   -70,     0,     0,     0,
       0,   -70,     0,   -63,   -63,   132,   133,   134,   135,   -63,
      33,     0,     0,     0,     0,     0,     0,    34,    35,    36,
       0,     0,     0,     0,     0,     0,   136,     0,     0,     0,
     137,   -37,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,
       0,     0,   -71,   -71,     0,     0,     0,     0,   -71,     0,
     -72,   -72,     0,     0,     0,     0,   -72,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,     0,     0,     0,   -73,   -73,
       0,     0,     0,   -73,     0,     0,   -71,   -71,     0,     0,
       0,   -71,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,
       0,     0,     0,   -72,   -72,     0,     0,     0,   -72,     0,
       0,   -75,   -75,     0,     0,     0,   -75,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,     0,     0,     0,     0,     0,   209,   -56,
       0,     0,     0,   -56,     0,     0,   -62,   -62,     0,     0,
       0,   -62,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,
       0,     0,     0,   -68,   -68,     0,     0,     0,   -68,     0,
       0,   -69,   -69,     0,     0,     0,   -69,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,     0,     0,     0,     0,     0,     0,   -57,
       0,     0,   -57,   -57,     0,     0,   -70,   -70,     0,     0,
       0,   -70,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
       0,     0,     0,   -63,   -63,     0,     0,     0,   -63,     0,
     -54,     0,     0,     0,     0,     0,    84,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,     0,    31,    32,   124,   125,
       0,    33,     0,     0,     0,     0,     0,   -57,    34,    35,
      36,     0,     0,   -57,     0,     0,     0,    41,     0,     0,
     -37,    42,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,
       0,     0,     0,   -73,   -73,     0,     0,   -73,     0,     0,
       0,   -71,   -71,     0,     0,   -71,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,     0,     0,     0,     0,     0,   -72,   -72,     0,
       0,   -72,     0,     0,     0,   -75,   -75,     0,     0,   -75,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,     0,     0,     0,     0,
       0,   294,   -56,     0,     0,   -56,     0,     0,     0,   -62,
     -62,     0,     0,   -62,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
       0,     0,     0,     0,     0,   -68,   -68,     0,     0,   -68,
       0,     0,     0,   -69,   -69,     0,     0,   -69,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,     0,     0,     0,     0,     0,   -70,
     -70,     0,     0,   -70,     0,     0,     0,   -63,   -63,     0,
       0,   -63,   -58,   -58,   -58,   -58,     0,   -58,   -59,   -59,
     -59,   -59,     0,   -59,   -58,   -58,   -58,     0,     0,     0,
     -59,   -59,   -59,   -58,     0,     0,     0,   -58,     0,   -59,
       0,     0,     0,   -59,   -61,   -61,   -61,   -61,     0,   -61,
      31,    32,   124,   125,     0,    33,   -61,   -61,   -61,     0,
       0,     0,    34,    35,    36,   -61,     0,     0,     0,   -61,
       0,    41,     0,     0,     0,    42,   132,   133,   134,   135,
       0,    33,   153,   154,   155,   156,     0,    33,    34,    35,
      36,     0,     0,     0,    34,    35,    36,   136,     0,     0,
       0,   137,     0,   157,     0,     0,     0,   158,   164,   165,
     166,   167,     0,    33,   235,   236,   237,   238,     0,    33,
      34,    35,    36,     0,     0,     0,    34,    35,    36,   168,
       0,     0,     0,   169,     0,   239,     0,     0,     0,   240,
     260,   261,   262,   263,     0,    33,     0,     0,     0,     0,
       0,     0,    34,    35,    36,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,   265,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   222,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,     0,     0,     0,     0,     0,     0,   -54,     0,
       0,   -54,     0,     0,     0,     0,   -53,     0,     0,   -53,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,     0,
       0,     0,   -55,     0,     0,   -55,     0,     0,     0,     0,
     -57,     0,     0,   -57,   219,   -49,   -49,   -49,   -49,   220,
     221,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,
       0,     0,     0,     0,     0,   -49,     0,     0,   -49,     0,
       0,     0,   -72,   -72,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
       0,     0,     0,     0,     0,   -75,   -75,     0,     0,     0,
       0,     0,     0,   289,   -56,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,     0,     0,     0,     0,     0,   -62,   -62,     0,     0,
       0,     0,     0,     0,   -68,   -68,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,     0,     0,     0,     0,     0,   -69,   -69,     0,
       0,     0,     0,     0,     0,   -70,   -70,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   206,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,     0,     0,     0,     0,     0,   -63,   -63,
       0,     0,     0,     0,     0,     0,     0,   -52,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   206,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,     0,     0,     0,     0,     0,     0,
     -54,     0,     0,     0,     0,     0,     0,     0,   -53,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,     0,     0,     0,     0,     0,
       0,   -55,     0,     0,     0,     0,     0,     0,     0,   -57,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,     0,     0,     0,     0,
     -74,   -74,     0,     0,     0,     0,     0,     0,   -73,   -73,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,     0,
     -71,   -71,     0,     0,     0,     0,     0,     0,   -72,   -72,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,     0,
     -75,   -75,     0,     0,     0,     0,     0,     0,   -56,   213,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,     0,     0,     0,     0,
     -62,   -62,     0,     0,     0,     0,     0,     0,   -68,   -68,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,
     -69,   -69,     0,     0,     0,     0,     0,     0,   -70,   -70,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   203,   -49,
     -49,   -49,   -49,   204,   205,     0,     0,     0,     0,     0,
     -63,   -63,     0,     0,     0,     0,     0,     0,     0,   -49,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,    83,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,     0,     0,     0,     0,
     -54,     0,     0,     0,     0,     0,     0,     0,   -53,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,     0,     0,     0,     0,   -55,
       0,     0,     0,     0,     0,     0,     0,   -57
};

static const yytype_int16 yycheck[] =
{
       1,   195,     9,   126,    23,    27,   209,     1,     9,     1,
     213,     5,     6,     5,     6,    27,     5,     6,    19,     5,
       6,     0,   225,    24,     7,     8,     9,    10,    11,    12,
      13,    14,   105,    40,    28,   229,    28,     5,     6,    40,
      29,    42,    39,    29,    23,    42,    29,    11,    29,    32,
     105,     0,    27,     9,    10,    11,    12,   112,    29,    29,
      28,   116,    32,   186,   105,    29,     0,    68,    32,     0,
     105,    68,    69,    29,    23,    76,    77,    78,    79,    80,
      81,    82,    83,   105,    30,    86,   289,     0,   105,    23,
      29,   294,    23,    32,    27,    28,     7,     8,     9,    10,
      11,    12,    13,    14,    11,    30,   107,   106,   105,   106,
      23,     0,   113,   120,   113,     0,   113,    28,    29,   120,
      27,    32,    33,   130,     0,     9,    10,    11,    12,   130,
       3,     4,     5,     6,    23,     8,   137,     0,    23,    31,
     137,    11,    15,    16,    17,    29,   147,    23,    32,    10,
      11,    24,    10,    11,    12,    28,    29,   158,   159,    29,
      23,   158,     3,     4,     5,     6,    27,     8,   169,    29,
      29,    29,   169,    32,    15,    16,    17,   178,    19,    20,
      21,    22,    23,    24,     0,    28,     2,    28,   185,    30,
      31,     9,    10,    11,    12,    28,    10,    11,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    27,   209,    28,
      42,    29,   213,    27,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   296,   225,   226,    27,    28,   227,   226,
     227,    63,    29,    27,   307,    32,    68,    29,   311,   240,
      32,   296,   243,   240,    76,    77,    78,    79,    80,    81,
      82,    83,   307,    27,    86,   296,   311,     9,    10,    11,
      12,   296,    29,    27,   265,    32,   307,   268,   265,    29,
     311,    27,   307,    27,   296,   107,   311,    29,    27,   296,
      32,   113,    10,    11,    12,   307,    27,    28,   289,   311,
     307,    27,    28,   294,   311,    10,    11,    12,   297,   296,
     297,    29,    29,    29,    32,   137,    32,   308,    27,   308,
     307,   308,    27,    29,   311,   147,     7,     8,     9,    10,
      11,    12,    13,    14,    29,    29,   158,   159,    32,    27,
      28,     3,     4,     5,     6,    29,     8,   169,    29,     5,
       6,    32,    33,    15,    16,    17,   178,    19,    20,    21,
      22,    23,    24,    31,    29,    29,    28,    32,    30,    31,
      10,    11,    12,    10,    11,    12,    42,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    27,   209,    27,    29,
      27,   213,    32,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    68,   225,   226,    27,    27,    31,    27,    29,
      76,    77,    78,    79,    80,    81,    82,    83,   240,    28,
      86,   243,     7,     8,     9,    10,    11,    12,    13,    14,
      27,    29,     9,    10,    11,    12,    29,     3,     4,     5,
       6,   107,     8,   265,    29,    29,   268,   113,    33,    15,
      16,    17,    29,    19,    20,    21,    22,    23,    24,    29,
      29,    29,    28,    27,    30,    31,    29,   289,    10,    11,
      27,   137,   294,     7,     8,     9,    10,    11,    12,    13,
      14,   147,    10,    11,    29,    29,   308,    29,    10,    11,
      32,    29,   158,   159,    28,    29,    29,     3,     4,     5,
       6,    29,     8,   169,    32,    29,    27,    29,    27,    15,
      16,    17,   178,    19,    20,    21,    22,    23,    24,    71,
      29,    29,    28,     2,    30,    31,     9,    10,    11,    12,
      29,    29,    42,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    29,   209,    10,    11,    29,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    68,   225,
     226,    46,    -1,    29,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,   240,    -1,    86,   243,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,     9,    10,
      11,    12,    -1,     3,     4,     5,     6,   107,     8,   265,
      29,    -1,   268,   113,    33,    15,    16,    17,    29,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,
      30,    31,    -1,   289,    -1,    -1,    -1,   137,   294,     7,
       8,     9,    10,    11,    12,    13,    14,   147,    10,    11,
      12,    -1,   308,     9,    10,    11,    12,    -1,   158,   159,
      28,    29,    -1,     3,     4,     5,     6,    29,     8,   169,
      -1,    -1,    -1,    29,    -1,    15,    16,    17,   178,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,
      30,    31,     9,    10,    11,    12,    -1,    -1,    42,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,   209,
      27,    -1,    -1,   213,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    68,   225,   226,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
     240,    -1,    86,   243,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,   107,     8,   265,    28,    29,   268,   113,
      32,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    -1,    30,    31,    -1,   289,
      -1,    -1,    -1,   137,   294,     7,     8,     9,    10,    11,
      12,    13,    14,   147,    -1,    -1,    -1,    -1,   308,     9,
      10,    11,    12,    -1,   158,   159,    28,    29,    -1,     3,
       4,     5,     6,    -1,     8,   169,    -1,    27,    -1,    -1,
      -1,    15,    16,    17,   178,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    -1,    30,    31,     9,    10,
      11,    12,    -1,    -1,    42,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,   209,    27,    -1,    -1,   213,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      68,   225,   226,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,   240,    -1,    86,   243,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,   107,
      -1,   265,    28,    29,   268,   113,    32,    33,    -1,    42,
      28,    29,    -1,    -1,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,   289,    -1,    -1,    -1,   137,
     294,    -1,    -1,    -1,    -1,    68,    -1,    28,    29,   147,
      -1,    32,    33,    -1,   308,    -1,    79,    -1,    81,    82,
     158,   159,    -1,    86,     8,     9,    10,    11,    12,    13,
      14,   169,    -1,     3,     4,     5,     6,    -1,     8,    -1,
     178,    -1,    -1,    27,   107,    15,    16,    17,    -1,    19,
     113,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    -1,
      30,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,   209,    -1,    -1,   137,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,   225,   226,     9,
      10,    11,    12,    -1,    -1,   158,    42,    -1,     3,     4,
       5,     6,   240,     8,    -1,   243,   169,    27,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    68,    28,    -1,    30,    31,   265,    -1,    -1,
     268,    -1,    -1,    -1,    80,    -1,   199,   200,   201,   202,
      86,   204,   205,    -1,   207,    -1,   209,    -1,    -1,    42,
     213,   289,   215,   216,   217,   218,   294,   220,   221,    -1,
     223,   107,   225,   226,    -1,    -1,    -1,   113,    -1,    -1,
     308,     3,     4,     5,     6,    68,     8,   240,    -1,     9,
      10,    11,    12,    15,    16,    17,    -1,    19,    -1,    21,
      22,   137,    24,    86,    -1,    -1,    28,    27,    30,    -1,
      -1,    -1,   265,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,   158,    -1,   107,     9,    10,    11,    12,    -1,
     113,    -1,    -1,   169,    28,    29,   289,    -1,    32,    33,
      -1,   294,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,   137,   308,     9,    10,    11,    12,
      -1,    -1,    -1,   199,   200,   201,   202,   203,   204,   205,
      -1,   207,    -1,   209,    27,   158,    42,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   169,   223,    -1,   225,
     226,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,   240,     9,    10,    11,    12,    -1,
      42,    29,    78,    -1,    32,    -1,   199,   200,   201,   202,
      86,   204,   205,    -1,   207,    29,   209,    -1,    32,   265,
     213,    -1,   215,   216,   217,   218,    68,   220,   221,    -1,
     223,   107,   225,   226,    -1,    77,    -1,   113,    -1,    -1,
      -1,    -1,    -1,   289,    86,    -1,    -1,   240,   294,    -1,
      -1,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,   137,   308,    -1,    -1,   107,    -1,    -1,    -1,    -1,
      -1,   113,   265,    -1,    28,    29,    -1,    42,    32,    33,
      -1,    -1,   158,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,   169,    -1,   137,   289,     9,    10,    11,
      12,   294,    -1,    68,    28,    29,    -1,    -1,    32,    33,
      -1,    76,    -1,    -1,    -1,   308,   158,    29,    -1,    -1,
      32,    86,    -1,   199,   200,   201,    -1,   169,    -1,    -1,
      -1,   207,    -1,   209,    -1,    -1,    -1,   213,    -1,   215,
     216,   217,   107,    -1,    -1,    -1,    -1,   223,   113,   225,
     226,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,    -1,
      -1,    -1,    -1,    -1,   240,   207,    -1,   209,    42,    -1,
      -1,   213,   137,   215,   216,    42,    -1,    -1,    -1,    -1,
      -1,   223,    -1,   225,   226,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,   158,    68,    -1,    -1,    -1,   240,    -1,
      -1,    68,    -1,    -1,   169,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    86,   289,    -1,    -1,    -1,    -1,   294,    86,
      -1,    -1,    -1,   265,     3,     4,     5,     6,    -1,     8,
      -1,    -1,   308,   107,   199,    -1,    15,    16,    17,   113,
     107,    -1,   207,    -1,   209,    24,   113,   289,   213,    28,
     215,    -1,   294,    -1,    -1,    -1,    -1,    -1,   223,    -1,
     225,   226,    -1,   137,    -1,    -1,   308,    -1,    -1,    -1,
     137,    -1,    -1,    -1,    -1,   240,     7,     8,     9,    10,
      11,    12,    13,    14,   158,     3,     4,     5,     6,    -1,
       8,   158,    -1,    -1,    -1,   169,    27,    15,    16,    17,
     265,    19,   169,    21,    22,    23,    24,    -1,    -1,    -1,
      28,    -1,    30,    31,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,   289,    -1,    -1,    -1,    -1,   294,
      -1,    -1,    -1,   207,    -1,   209,    28,    29,    -1,   213,
     207,    33,   209,   308,    -1,    -1,   213,    -1,    -1,   223,
      -1,   225,   226,    -1,    -1,    -1,   223,    -1,   225,   226,
      -1,    -1,     3,     4,     5,     6,   240,     8,    -1,    -1,
      -1,    -1,    -1,   240,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
      31,   265,    -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,    -1,
     294,    -1,   289,    -1,    28,    29,    -1,   294,    32,    33,
       3,     4,     5,     6,   308,     8,    -1,    -1,    -1,    -1,
      -1,   308,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    31,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    -1,    30,    31,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    -1,    30,    31,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    28,    -1,    30,    31,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,    31,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      28,    -1,    30,    31,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,    31,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,
      30,    31,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
      31,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    -1,    21,
      22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,    31,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    -1,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,    31,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    -1,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    -1,    30,    31,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    -1,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    -1,    30,    31,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    -1,    21,    22,    23,    24,    -1,
      -1,    -1,    28,    -1,    30,    31,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,    31,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      28,    -1,    30,    31,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,    31,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,
      30,    31,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    -1,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
      31,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    -1,    21,
      22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,    31,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    33,    -1,    -1,    28,
      29,    -1,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    -1,    27,    28,    -1,    -1,    -1,    -1,    33,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    27,    28,
      -1,    -1,    -1,    -1,    33,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    33,    -1,    27,    28,    -1,    -1,    -1,    -1,    33,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    27,    28,
      -1,    -1,    -1,    -1,    33,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    33,    -1,    27,    28,     3,     4,     5,     6,    33,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      28,    29,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    33,    -1,
      27,    28,    -1,    -1,    -1,    -1,    33,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    -1,    33,    -1,    -1,    28,    29,    -1,    -1,
      -1,    33,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    33,    -1,
      -1,    28,    29,    -1,    -1,    -1,    33,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    -1,    33,    -1,    -1,    28,    29,    -1,    -1,
      -1,    33,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    33,    -1,
      -1,    28,    29,    -1,    -1,    -1,    33,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    -1,    -1,    28,    29,    -1,    -1,
      -1,    33,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    33,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    27,    15,    16,
      17,    -1,    -1,    33,    -1,    -1,    -1,    24,    -1,    -1,
      27,    28,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,     3,     4,     5,     6,    -1,     8,     3,     4,
       5,     6,    -1,     8,    15,    16,    17,    -1,    -1,    -1,
      15,    16,    17,    24,    -1,    -1,    -1,    28,    -1,    24,
      -1,    -1,    -1,    28,     3,     4,     5,     6,    -1,     8,
       3,     4,     5,     6,    -1,     8,    15,    16,    17,    -1,
      -1,    -1,    15,    16,    17,    24,    -1,    -1,    -1,    28,
      -1,    24,    -1,    -1,    -1,    28,     3,     4,     5,     6,
      -1,     8,     3,     4,     5,     6,    -1,     8,    15,    16,
      17,    -1,    -1,    -1,    15,    16,    17,    24,    -1,    -1,
      -1,    28,    -1,    24,    -1,    -1,    -1,    28,     3,     4,
       5,     6,    -1,     8,     3,     4,     5,     6,    -1,     8,
      15,    16,    17,    -1,    -1,    -1,    15,    16,    17,    24,
      -1,    -1,    -1,    28,    -1,    24,    -1,    -1,    -1,    28,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    28,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    32,     8,     9,    10,    11,    12,    13,
      14,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    -1,    28,    29,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
       7,     8,     9,    10,    11,    12,    13,    14,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    35,    36,    37,    39,     1,     5,     6,    28,
      48,    71,     0,    36,    27,    48,    28,    38,    29,    40,
      27,    49,    50,    71,    32,    29,    71,    41,    30,    42,
      43,     3,     4,     8,    15,    16,    17,    19,    21,    22,
      23,    24,    28,    37,    42,    44,    45,    46,    47,    51,
      52,    53,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    70,    71,    72,    28,    28,
      55,    48,    55,    31,    46,    27,    11,    10,    12,     9,
       8,    13,    14,     7,    33,    65,    28,    55,    55,    56,
      27,    29,    59,    65,    60,    61,    62,    64,    62,    62,
      65,    57,    57,    68,    69,    29,    27,    32,    29,    47,
      56,    57,    20,    27,    47,    56,    29,    47,     5,     6,
      28,    71,     5,     6,     5,     6,    30,     1,     5,     6,
      28,    71,     3,     4,     5,     6,    24,    28,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    70,
      71,    72,    38,     3,     4,     5,     6,    24,    28,    66,
      67,    70,    71,    72,     3,     4,     5,     6,    24,    28,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      70,    71,    72,    19,    21,    22,    30,    42,    51,    52,
      53,    54,    55,    55,    48,    43,    27,    48,    55,    11,
      10,    12,     9,     8,    13,    14,     7,    33,    65,    28,
      27,    55,    65,    28,    55,    11,    10,    12,     9,     8,
      13,    14,     7,    33,    65,    28,    28,    28,    55,    43,
      27,    29,    44,    29,    29,     3,     4,     5,     6,    24,
      28,    59,    65,    66,    67,    70,    71,    72,    60,    61,
      62,    64,    62,    62,    65,    57,    69,    29,    69,    29,
       3,     4,     5,     6,    24,    28,    59,    65,    66,    67,
      70,    71,    72,    60,    61,    62,    64,    62,    62,    65,
      57,    69,    55,    56,    27,    44,    31,    55,    65,    28,
      29,    29,    55,    65,    28,    29,    29,    27,    31,    29,
      69,    29,    69,    47,    56,    29,    29,    20,    27,    47,
      56,    29,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    35,    36,    36,    38,    37,    37,    40,
      41,    39,    43,    42,    44,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    52,    52,    53,    54,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    71,    71,    72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     4,     3,     0,
       0,     8,     0,     4,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     0,
       1,     2,     5,     7,     3,     9,     1,     0,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     4,     1,     3,     1,     0,     1,     1,
       3,     1,     1,     1,     1,     1
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
#line 60 "src/bison/math.y"
                                { list_push(&root->children, (yyvsp[0].ast)); }
#line 2271 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 61 "src/bison/math.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 2277 "src/bison/grammar.c"
    break;

  case 6: /* @1: %empty  */
#line 68 "src/bison/math.y"
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
#line 2298 "src/bison/grammar.c"
    break;

  case 7: /* declaration: LET declarator @1 ';'  */
#line 83 "src/bison/math.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 2306 "src/bison/grammar.c"
    break;

  case 8: /* declaration: LET error ';'  */
#line 86 "src/bison/math.y"
                    {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 2317 "src/bison/grammar.c"
    break;

  case 9: /* @2: %empty  */
#line 94 "src/bison/math.y"
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
#line 2350 "src/bison/grammar.c"
    break;

  case 10: /* $@3: %empty  */
#line 121 "src/bison/math.y"
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
#line 2367 "src/bison/grammar.c"
    break;

  case 11: /* func_declaration: LET declarator '(' @2 id_list.opt ')' $@3 compound_stmt  */
#line 132 "src/bison/math.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 2376 "src/bison/grammar.c"
    break;

  case 12: /* $@4: %empty  */
#line 138 "src/bison/math.y"
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
#line 2391 "src/bison/grammar.c"
    break;

  case 13: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 147 "src/bison/math.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
    }
#line 2400 "src/bison/grammar.c"
    break;

  case 14: /* block_item_list.opt: block_item_list  */
#line 153 "src/bison/math.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 2406 "src/bison/grammar.c"
    break;

  case 15: /* block_item_list.opt: %empty  */
#line 154 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2412 "src/bison/grammar.c"
    break;

  case 16: /* block_item_list: block_item_list block_item  */
#line 157 "src/bison/math.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2418 "src/bison/grammar.c"
    break;

  case 17: /* block_item_list: block_item  */
#line 158 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2424 "src/bison/grammar.c"
    break;

  case 26: /* declarator: '(' declarator ')'  */
#line 173 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2430 "src/bison/grammar.c"
    break;

  case 27: /* id_list: id_list ',' id  */
#line 176 "src/bison/math.y"
                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2436 "src/bison/grammar.c"
    break;

  case 28: /* id_list: id  */
#line 177 "src/bison/math.y"
         { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2442 "src/bison/grammar.c"
    break;

  case 29: /* id_list.opt: %empty  */
#line 180 "src/bison/math.y"
                    { (yyval.list) = NULL; }
#line 2448 "src/bison/grammar.c"
    break;

  case 31: /* expr_stmt: expression ';'  */
#line 184 "src/bison/math.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2454 "src/bison/grammar.c"
    break;

  case 32: /* cond_stmt: IF '(' expression ')' statement  */
#line 187 "src/bison/math.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 2462 "src/bison/grammar.c"
    break;

  case 33: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 190 "src/bison/math.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2470 "src/bison/grammar.c"
    break;

  case 34: /* jmp_stmt: RETURN expression ';'  */
#line 195 "src/bison/math.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 2476 "src/bison/grammar.c"
    break;

  case 35: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 198 "src/bison/math.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2484 "src/bison/grammar.c"
    break;

  case 37: /* expression.opt: %empty  */
#line 206 "src/bison/math.y"
                       { (yyval.ast) = NULL; }
#line 2490 "src/bison/grammar.c"
    break;

  case 40: /* assign_expr: unary_expr '=' assign_expr  */
#line 211 "src/bison/math.y"
                                 { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2496 "src/bison/grammar.c"
    break;

  case 42: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 215 "src/bison/math.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2505 "src/bison/grammar.c"
    break;

  case 44: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 222 "src/bison/math.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2514 "src/bison/grammar.c"
    break;

  case 46: /* eq_expr: eq_expr EQ rel_expr  */
#line 229 "src/bison/math.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2523 "src/bison/grammar.c"
    break;

  case 48: /* rel_expr: rel_expr REL dl_dg_expr  */
#line 236 "src/bison/math.y"
                              {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2532 "src/bison/grammar.c"
    break;

  case 50: /* dl_dg_expr: add_expr DL_DG dl_dg_expr  */
#line 243 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2541 "src/bison/grammar.c"
    break;

  case 51: /* dl_dg_expr: add_expr COLON dl_dg_expr  */
#line 247 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2550 "src/bison/grammar.c"
    break;

  case 53: /* add_expr: add_expr ADD mult_expr  */
#line 254 "src/bison/math.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2559 "src/bison/grammar.c"
    break;

  case 55: /* mult_expr: mult_expr MULT unary_expr  */
#line 261 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2568 "src/bison/grammar.c"
    break;

  case 57: /* unary_expr: unary_ops unary_expr  */
#line 268 "src/bison/math.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].operator), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2577 "src/bison/grammar.c"
    break;

  case 63: /* postfix_expr: postfix_expr '(' arg_expr_list.opt ')'  */
#line 281 "src/bison/math.y"
                                             {
        (yyval.ast) = NULL;
    }
#line 2585 "src/bison/grammar.c"
    break;

  case 64: /* arg_expr_list: assign_expr  */
#line 286 "src/bison/math.y"
                           { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2591 "src/bison/grammar.c"
    break;

  case 65: /* arg_expr_list: arg_expr_list ',' assign_expr  */
#line 287 "src/bison/math.y"
                                    { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2597 "src/bison/grammar.c"
    break;

  case 67: /* arg_expr_list.opt: %empty  */
#line 291 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2603 "src/bison/grammar.c"
    break;

  case 68: /* primary_expr: id  */
#line 294 "src/bison/math.y"
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
#line 2621 "src/bison/grammar.c"
    break;

  case 70: /* primary_expr: '(' expression ')'  */
#line 308 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2627 "src/bison/grammar.c"
    break;

  case 71: /* id: NAME  */
#line 311 "src/bison/math.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 2633 "src/bison/grammar.c"
    break;

  case 72: /* id: BUILT_IN  */
#line 312 "src/bison/math.y"
               { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 2639 "src/bison/grammar.c"
    break;

  case 73: /* constant: NUMBER_REAL  */
#line 315 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 2645 "src/bison/grammar.c"
    break;

  case 74: /* constant: NUMBER_INT  */
#line 316 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 2651 "src/bison/grammar.c"
    break;

  case 75: /* constant: NIL  */
#line 317 "src/bison/math.y"
          { }
#line 2657 "src/bison/grammar.c"
    break;


#line 2661 "src/bison/grammar.c"

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

#line 320 "src/bison/math.y"


void yyerror(const char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    if (s) CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
    ++errors_count;
}
