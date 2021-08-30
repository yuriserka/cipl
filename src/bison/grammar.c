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
  YYSYMBOL_dl_dg_expr = 58,                /* dl_dg_expr  */
  YYSYMBOL_list_ctr_expr = 59,             /* list_ctr_expr  */
  YYSYMBOL_logical_or_expr = 60,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 61,          /* logical_and_expr  */
  YYSYMBOL_eq_expr = 62,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 63,                  /* rel_expr  */
  YYSYMBOL_add_expr = 64,                  /* add_expr  */
  YYSYMBOL_mult_expr = 65,                 /* mult_expr  */
  YYSYMBOL_unary_expr = 66,                /* unary_expr  */
  YYSYMBOL_unary_ops = 67,                 /* unary_ops  */
  YYSYMBOL_postfix_expr = 68,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 69,             /* arg_expr_list  */
  YYSYMBOL_70_arg_expr_list_opt = 70,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 71,              /* primary_expr  */
  YYSYMBOL_id = 72,                        /* id  */
  YYSYMBOL_constant = 73                   /* constant  */
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
#define YYLAST   3666

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  316

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
     243,   249,   250,   256,   257,   263,   264,   270,   271,   277,
     278,   279,   280,   283,   284,   289,   290,   293,   294,   297,
     310,   311,   314,   315,   318,   319,   320
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
  "expression", "expression.opt", "assign_expr", "dl_dg_expr",
  "list_ctr_expr", "logical_or_expr", "logical_and_expr", "eq_expr",
  "rel_expr", "add_expr", "mult_expr", "unary_expr", "unary_ops",
  "postfix_expr", "arg_expr_list", "arg_expr_list.opt", "primary_expr",
  "id", "constant", YY_NULLPTR
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

#define YYPACT_NINF (-202)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,    15,    12,    38,    75,    85,   -13,    95,   134,     4,
     279,   368,  -202,   109,   110,    -5,    25,     1,   381,    89,
     111,    -3,     5,   126,   373,    10,   163,    57,    43,   112,
     160,   248,  2352,  2979,  2994,  3009,  3024,    88,   113,  3039,
      87,  2379,  3054,   382,   540,    86,   698,   856,  1610,  1930,
    1959,  1988,  2017,   125,   140,   122,    42,   380,   915,   220,
     304,  3619,  3570,    92,  3039,  2387,  2414,  2422,  2449,  3054,
    2803,   147,   158,   121,   146,  2046,  2075,  3069,  3069,  3069,
    3069,  3069,  3069,  3069,  3069,  3039,  1464,  2463,   169,   162,
     189,  2104,  2486,   173,  3578,   696,  1022,   757,   998,  3639,
    3599,  3607,   214,   165,   207,   235,   123,  2803,  3084,  2494,
     317,   245,   344,   347,  2520,  2133,   249,   347,  2162,   257,
     290,     4,   295,   351,   422,  2543,  2551,    43,   299,   301,
     319,     4,   322,  2578,  2586,  2613,  2621,  2648,  3054,   315,
     -10,   143,   260,  1454,   682,   840,  1580,  3328,   461,  3054,
    2656,  2683,  2691,  2718,   333,  3398,  3420,  3428,  3450,  3458,
    3054,  3069,  3480,  3488,  3510,  3518,   987,  1147,  1251,  1354,
    1769,  3054,   164,   329,   298,   255,  1080,   722,   406,  1093,
    2726,  3084,  1870,  2274,  2282,  2309,   337,   339,  3039,    43,
     480,   638,   796,   954,  1023,   357,   345,   360,   160,  2191,
     371,   393,  3099,  3099,  3099,  3099,  3099,  3099,  3099,  3099,
    3054,   619,  2463,  2220,   403,  3628,  2463,   405,  3114,  3114,
    3114,  3114,  3114,  3114,  3114,  3114,  3084,  2753,  2463,  3054,
    2803,   384,   160,  1112,   407,   434,   426,  2761,   513,   671,
     829,  3204,  3212,  3054,   266,  3336,  3099,  3235,  3243,  3266,
    3274,   343,  1475,  1343,  1531,  1720,  3359,  3367,   447,   448,
    3540,   449,  2317,   778,   936,  2825,  2833,  2859,  3054,   522,
    3136,  3114,  2867,  2893,  2901,  2927,   659,   520,  1240,   880,
     564,  3144,  3170,   423,   450,   451,   454,  1211,   460,  2249,
     453,  3390,  2463,  2788,  3548,   469,  3178,  2463,  2344,   123,
    2803,  1314,  3297,   476,  2935,   477,  1421,   482,  3305,  2961,
     123,  2520,  1833,   478,   123,  1901
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
       0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,  -202,   510,    70,   442,  -202,  -202,  -202,   -22,  -126,
    -195,  -202,   470,  -100,    -7,  -202,  -202,   -70,   -64,   -62,
     -61,   -17,   -57,  1597,  1604,  1497,  1459,  1352,  1290,  1187,
    1084,   981,   221,   379,   537,  -202,  -201,   695,    -1,   853
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    43,    17,     5,    19,    27,    44,    30,
      45,    46,    47,    48,    10,    21,    22,    49,    50,    51,
      52,    53,    90,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   104,   105,    66,    67,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,   198,    15,   235,   202,    29,   110,     1,   122,   119,
     120,   259,    12,   115,    14,   261,     6,   118,    23,   -39,
       7,     8,    71,    26,    18,    73,   -30,   284,    20,    24,
      -9,    -9,   121,    72,    25,     1,   191,   288,    -3,   132,
     -10,   152,   192,     9,   193,   194,   -12,   -12,   -12,   -12,
     111,   -12,    88,    89,    -9,    78,   -41,   116,   -12,   -12,
     -12,    -3,   -12,   232,   -12,   -12,   -12,   -12,   152,   -41,
       4,   -12,     4,   -12,   -12,    -5,   164,   164,   164,   164,
     164,   164,   164,   164,   190,    -4,   184,    28,   128,   195,
      89,   303,   129,   130,   123,   124,   305,   196,    -5,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   184,    -4,    -2,
      -8,    -7,   -11,   152,   197,   131,    69,    74,   -29,   -55,
     122,   201,   -72,   -72,   200,    85,    31,    32,   125,   126,
     122,    33,    -2,    -8,    -7,   -11,    77,   152,    34,    35,
      36,    70,   186,   214,   187,   188,   -13,    41,   152,   -39,
      92,    42,    76,   189,   217,   -28,   203,   -41,   -28,   152,
     164,   -73,   -73,    31,    32,   125,   126,   -36,    33,   -13,
     152,   231,   -41,   286,    91,    34,    35,    36,   218,    37,
     184,    38,    39,    40,    41,    -6,    78,   -42,    42,   -38,
     127,   -15,   -27,   -39,   -65,   -27,   -39,   -65,   106,   306,
     -42,   249,   249,   249,   249,   249,   249,   249,   249,   152,
     312,   184,   285,    89,   315,   184,   107,   274,   274,   274,
     274,   274,   274,   274,   274,   184,   290,   184,   152,   191,
     -47,   -47,    81,   -47,   -47,   192,   -67,   193,   194,   108,
     191,   -40,   152,   307,   191,   249,   192,   -47,   193,   194,
     192,   295,   193,   194,   313,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   148,   109,   221,   -45,   152,   -45,   -45,
     274,   204,   114,   -43,   -43,   -75,   -75,   190,   117,   203,
     -42,   -75,   195,    89,   -45,    86,   -72,   -45,   190,   -43,
     148,   184,   190,   195,   196,   -42,   184,   195,    94,    94,
      94,    94,    94,    94,    94,   101,    -6,    16,   180,   220,
     152,   -43,   -43,    82,   -49,   -49,   -49,   -49,   -49,   -73,
     -32,   -32,   -32,   -32,   -25,   -32,   199,   -43,   -72,   180,
     -43,   -49,   -32,   -32,   -32,   148,   -32,   113,   -32,   -32,
     -32,   -32,   219,   -41,   -36,   -32,   -73,   -32,   -32,   -25,
      31,    32,   125,   126,   204,    33,   -44,   -44,   -41,   148,
     213,   -41,    34,    35,    36,   229,    37,   230,    38,    39,
     211,    41,   -44,   -66,   -38,    42,   -66,   127,   123,   124,
     -72,   148,   215,   -72,   233,   -18,   -18,   -18,   -18,   234,
     -18,    79,   148,   -43,   -43,   -25,   -25,   -18,   -18,   -18,
     236,   -18,   227,   -18,   -18,   -18,   -18,   -43,   -26,   -26,
     -18,   287,   -18,   -18,   224,   -51,   -51,   -51,   -51,   -51,
     -51,   149,   237,   245,   245,   245,   245,   245,   245,   245,
     257,   148,   260,   180,   262,   -51,   -26,   180,   -51,   270,
     270,   270,   270,   270,   270,   270,   282,   180,   149,   180,
     148,   -73,   -40,   -26,   -73,   -40,   161,   161,   161,   161,
     161,   161,   161,   161,   148,   289,   181,   291,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -40,   293,   294,   298,
     299,   300,   302,   -21,   -21,   -21,   -21,   181,   -21,   148,
     -55,   301,   296,   149,   210,   -21,   -21,   -21,   304,   -21,
     -21,   -21,   -21,   -21,   -21,   308,   309,   314,   -21,   311,
     -21,   -21,    13,   180,   154,     0,    75,   149,   180,     0,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   149,     0,
     221,   -46,   148,   -46,   -46,   219,   -42,     0,     0,   149,
     161,   -75,   -75,   -21,   -21,   -21,   -21,     0,   -21,   -46,
     149,   -42,   -46,     0,   -42,   -21,   -21,   -21,     0,   -21,
     181,   -21,   -21,   -21,   -21,     0,     0,     0,   -21,     0,
     -21,   -21,   224,   -52,   -52,   -52,   -52,   -52,   -52,   150,
       0,   246,   246,   246,   246,   246,   246,   246,   246,   149,
       0,   181,     0,   -52,     0,   181,   -52,   271,   271,   271,
     271,   271,   271,   271,   271,   181,   150,   181,   149,     0,
       0,     0,     0,     0,   162,   162,   162,   162,   162,   162,
     162,   162,   149,     0,   182,   246,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,     0,
       0,   -20,   -20,   -20,   -20,   182,   -20,   149,   -58,     0,
     271,   150,   -58,   -20,   -20,   -20,     0,   -20,   -20,   -20,
     -20,   -20,   -20,     0,     0,     0,   -20,     0,   -20,   -20,
     220,   181,   -44,   -44,     0,   150,   181,     0,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   150,     0,   -44,     0,
     149,   -44,   -47,   -47,   206,   -47,   -47,   150,   162,   -74,
     -74,    31,    32,   125,   126,     0,    33,    79,   150,   -44,
     -44,   -47,     0,    34,    35,    36,     0,    37,   182,    38,
      39,    40,    41,   -44,     0,     0,    42,     0,   127,   -14,
       0,   223,   -49,   -49,   -49,   -49,   -49,   151,     0,   247,
     247,   247,   247,   247,   247,   247,   247,   150,     0,   182,
       0,   -49,     0,   182,   -49,   272,   272,   272,   272,   272,
     272,   272,   272,   182,   151,   182,   150,   -48,   -48,    81,
     -48,   -48,   163,   163,   163,   163,   163,   163,   163,   163,
     150,     0,   183,   247,   -48,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,     0,     0,     0,     0,     0,     0,   -22,
     -22,   -22,   -22,   183,   -22,   150,   -75,   -75,   272,   151,
     -75,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,
     -22,     0,     0,     0,   -22,     0,   -22,   -22,     0,   182,
       0,     0,     0,   151,   182,     0,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   151,     0,     0,     0,   150,   207,
     -49,   -49,   -49,   -49,   -49,   151,   163,   -72,   -72,   -17,
     -17,   -17,   -17,     0,   -17,     0,   151,     0,     0,   -49,
       0,   -17,   -17,   -17,     0,   -17,   183,   -17,   -17,   -17,
     -17,     0,     0,     0,   -17,     0,   -17,   -17,     0,   223,
     -50,   -50,   -50,   -50,   -50,   153,     0,   248,   248,   248,
     248,   248,   248,   248,   248,   151,     0,   183,     0,   -50,
       0,   183,   -50,   273,   273,   273,   273,   273,   273,   273,
     273,   183,   153,   183,   151,    80,   -45,     0,   -45,   -45,
     165,   165,   165,   165,   165,   165,   165,   165,   151,     0,
     185,   248,   -45,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     0,     0,     0,     0,     0,     0,   -23,   -23,   -23,
     -23,   185,   -23,   151,   -74,   -74,   273,   153,   -74,   -23,
     -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,   -23,     0,
       0,     0,   -23,     0,   -23,   -23,     0,   183,     0,     0,
       0,   153,   183,     0,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   153,     0,     0,     0,   151,    82,   -50,   -50,
     -50,   -50,   -50,   153,   165,   -75,   -75,     0,     0,   -75,
     -75,     0,     0,   147,   153,   -50,   -24,   -24,   -24,   -24,
       0,   -24,    80,   -46,   185,   -46,   -46,     0,   -24,   -24,
     -24,     0,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -46,
     147,   -24,     0,   -24,   -24,   250,   250,   250,   250,   250,
     250,   250,   250,   153,   100,   185,     0,     0,   179,   185,
       0,   275,   275,   275,   275,   275,   275,   275,   275,   185,
       0,   185,   153,     0,     0,     0,     0,     0,     0,   179,
     -47,   -47,   222,   -47,   -47,   147,   153,     0,     0,   250,
     225,   -53,   -53,   -53,   -53,   -53,   -53,   -53,     0,   -47,
       0,     0,   -47,     0,     0,   -31,   -31,   -31,   -31,   147,
     -31,   153,   -53,     0,   275,   -53,   146,   -31,   -31,   -31,
       0,   -31,   -31,   -31,   -31,   -31,   -31,     0,     0,     0,
     -31,   147,   -31,   -31,     0,   185,     0,     0,     0,     0,
     185,     0,   147,   146,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,     0,     0,   153,     0,    99,     0,     0,     0,
       0,   178,     0,     0,     0,   -74,   -74,     0,     0,   -74,
     -74,     0,     0,   147,   147,   147,   147,   147,   147,   256,
       0,   147,   178,   179,     0,     0,     0,   179,   146,   179,
     179,   179,   179,   179,   179,   281,     0,   179,     0,   179,
     147,     0,     0,     0,   -34,   -34,   -34,   -34,     0,   -34,
       0,     0,   146,     0,   147,     0,   -34,   -34,   -34,   145,
     -34,   -34,   -34,   -34,   -34,   -34,     0,     0,     0,   -34,
       0,   -34,   -34,     0,   146,     0,     0,     0,     0,   147,
     -48,   -48,   222,   -48,   -48,   146,   145,     0,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,     0,     0,    98,   -48,
       0,     0,   -48,   179,   177,     0,     0,     0,   179,   -72,
     -72,     0,     0,   -72,   -72,     0,   146,   146,   146,   146,
     146,   255,   147,     0,   146,   177,   178,     0,     0,     0,
     178,   145,   178,   178,   178,   178,   178,   280,     0,     0,
     178,     0,   178,   146,     0,     0,     0,   -13,   -13,   -13,
     -13,     0,   -13,     0,     0,   145,     0,   146,     0,   -13,
     -13,   -13,   144,   -13,   -13,   -13,   -13,   -13,   -13,     0,
       0,     0,   -13,     0,   -13,   -13,     0,   145,     0,     0,
       0,     0,   146,   -48,   -48,   206,   -48,   -48,   145,   144,
       0,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,
      97,     0,   -48,     0,     0,     0,   178,   176,     0,     0,
       0,   178,   -73,   -73,     0,     0,   -73,   -73,     0,   145,
     145,   145,   145,   254,   143,   146,     0,   145,   176,   177,
       0,     0,     0,   177,   144,   177,   177,   177,   177,   279,
       0,     0,     0,   177,     0,   177,   145,     0,     0,     0,
       0,   143,     0,     0,   -32,   -32,   -32,   -32,   144,   -32,
     145,    96,     0,     0,     0,     0,   -32,   -32,   -32,   175,
     -32,   310,   -32,   -32,   -32,   -32,     0,     0,     0,   -32,
     144,   -32,   -32,     0,     0,   145,     0,     0,     0,     0,
     175,   144,     0,     0,   205,   -45,   143,   -45,   -45,     0,
       0,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   177,
       0,     0,     0,   -45,   177,   205,   -46,     0,   -46,   -46,
     143,   -58,   144,   144,   144,   253,     0,   -58,   145,     0,
     144,   142,   176,     0,   -46,     0,   176,     0,   176,   176,
     176,   278,   143,     0,     0,     0,   176,     0,   176,   144,
       0,     0,     0,   143,     0,     0,     0,     0,   142,     0,
       0,     0,     0,   144,     0,     0,     0,    95,     0,   141,
     207,   -50,   -50,   -50,   -50,   -50,   174,     0,     0,     0,
       0,     0,     0,     0,   143,   143,   252,     0,   144,     0,
     -50,     0,   143,     0,   175,     0,   141,   174,   175,     0,
     175,   175,   277,   142,    93,     0,     0,     0,   175,     0,
     175,   143,   176,     0,   173,     0,     0,   176,   208,   -51,
     -51,   -51,   -51,   -51,   -51,   143,     0,   142,     0,     0,
       0,   144,     0,     0,     0,   173,     0,     0,     0,   -51,
       0,   141,     0,   -19,   -19,   -19,   -19,     0,   -19,   142,
     143,     0,     0,     0,     0,   -19,   -19,   -19,     0,   -19,
     142,   -19,   -19,   -19,   -19,   141,     0,     0,   -19,   139,
     -19,   -19,     0,     0,   175,     0,   140,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
       0,   142,   251,   143,     0,     0,   139,     0,   141,   142,
       0,   174,     0,   140,     0,   174,     0,   174,   276,     0,
       0,     0,   102,     0,   103,   174,     0,   174,   142,     0,
       0,   172,     0,     0,     0,     0,     0,     0,     0,   244,
       0,     0,   142,     0,     0,   112,     0,   141,     0,   173,
       0,   139,   172,   173,     0,   269,     0,     0,   140,     0,
       0,     0,     0,   173,     0,   173,   141,   142,   208,   -52,
     -52,   -52,   -52,   -52,   -52,   139,     0,     0,     0,     0,
     141,     0,   140,     0,     0,     0,     0,     0,     0,   -52,
       0,   174,     0,     0,     0,     0,   174,   139,     0,     0,
       0,     0,     0,     0,   140,   141,     0,     0,   139,     0,
     142,     0,     0,     0,     0,   140,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,     0,     0,     0,     0,     0,   173,
       0,     0,     0,     0,   173,     0,     0,   -76,   -76,     0,
       0,   -76,   -76,     0,     0,     0,     0,   258,   141,   103,
       0,     0,     0,   103,   140,     0,   172,     0,     0,     0,
     172,     0,     0,   283,     0,   103,   139,     0,     0,     0,
     172,     0,   172,   140,     0,     0,   -33,   -33,   -33,   -33,
     139,   -33,     0,     0,     0,     0,     0,   140,   -33,   -33,
     -33,     0,   -33,   -33,   -33,   -33,   -33,   -33,     0,     0,
       0,   -33,     0,   -33,   -33,   139,     0,     0,     0,     0,
       0,     0,   140,     0,     0,     0,     0,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,     0,     0,     0,     0,   103,
       0,     0,     0,     0,   103,     0,   172,     0,   228,   -57,
       0,   172,   -57,   -57,   -35,   -35,   -35,   -35,   139,   -35,
       0,     0,     0,     0,     0,   140,   -35,   -35,   -35,     0,
     -35,   -35,   -35,   -35,   -35,   -35,     0,     0,     0,   -35,
       0,   -35,   -35,   -20,   -20,   -20,   -20,     0,   -20,     0,
       0,     0,     0,     0,     0,   -20,   -20,   -20,     0,   -20,
       0,   -20,   -20,   -20,   -20,     0,     0,     0,   -20,     0,
     -20,   -20,   -22,   -22,   -22,   -22,     0,   -22,     0,     0,
       0,     0,     0,     0,   -22,   -22,   -22,     0,   -22,     0,
     -22,   -22,   -22,   -22,     0,     0,     0,   -22,     0,   -22,
     -22,   -23,   -23,   -23,   -23,     0,   -23,     0,     0,     0,
       0,     0,     0,   -23,   -23,   -23,     0,   -23,     0,   -23,
     -23,   -23,   -23,     0,     0,     0,   -23,     0,   -23,   -23,
     -24,   -24,   -24,   -24,     0,   -24,     0,     0,     0,     0,
       0,     0,   -24,   -24,   -24,     0,   -24,     0,   -24,   -24,
     -24,   -24,     0,     0,     0,   -24,     0,   -24,   -24,   -16,
     -16,   -16,   -16,     0,   -16,     0,     0,     0,     0,     0,
       0,   -16,   -16,   -16,     0,   -16,     0,   -16,   -16,   -16,
     -16,     0,     0,     0,   -16,     0,   -16,   -16,   -31,   -31,
     -31,   -31,     0,   -31,     0,     0,     0,     0,     0,     0,
     -31,   -31,   -31,     0,   -31,     0,   -31,   -31,   -31,   -31,
       0,     0,     0,   -31,     0,   -31,   -31,   -34,   -34,   -34,
     -34,     0,   -34,     0,     0,     0,     0,     0,     0,   -34,
     -34,   -34,     0,   -34,     0,   -34,   -34,   -34,   -34,     0,
       0,     0,   -34,     0,   -34,   -34,   -33,   -33,   -33,   -33,
       0,   -33,     0,     0,     0,     0,     0,     0,   -33,   -33,
     -33,     0,   -33,     0,   -33,   -33,   -33,   -33,     0,     0,
       0,   -33,     0,   -33,   -33,   -35,   -35,   -35,   -35,     0,
     -35,     0,     0,     0,     0,     0,     0,   -35,   -35,   -35,
       0,   -35,     0,   -35,   -35,   -35,   -35,     0,     0,     0,
     -35,     0,   -35,   -35,    -8,    -8,    -8,    -8,     0,    -8,
       0,     0,     0,     0,     0,     0,    -8,    -8,    -8,     0,
      -8,     0,    -8,    -8,    -8,    -8,     0,     0,     0,    -8,
       0,    -8,    -8,    -7,    -7,    -7,    -7,     0,    -7,     0,
       0,     0,     0,     0,     0,    -7,    -7,    -7,     0,    -7,
       0,    -7,    -7,    -7,    -7,     0,     0,     0,    -7,     0,
      -7,    -7,   -13,   -13,   -13,   -13,     0,   -13,     0,     0,
       0,     0,     0,     0,   -13,   -13,   -13,     0,   -13,     0,
     -13,   -13,   -13,   -13,     0,     0,     0,   -13,     0,   -13,
     -13,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,
       0,     0,   -63,   -63,     0,     0,   -63,   -63,     0,     0,
     -69,   -69,     0,     0,   -69,   -69,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,     0,     0,     0,     0,     0,   -70,   -70,     0,
       0,   -70,   -70,     0,     0,   -71,   -71,     0,     0,   -71,
     -71,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,     0,
       0,     0,   -64,   -64,     0,     0,   -64,   -64,     0,   -74,
     -74,     0,     0,     0,     0,   -74,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,     0,   -76,   -76,     0,     0,
       0,     0,   -76,     0,   -57,    87,     0,     0,     0,     0,
     -57,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,
       0,   -63,   -63,     0,     0,     0,     0,   -63,     0,   -69,
     -69,     0,     0,     0,     0,   -69,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,     0,     0,   166,   167,   168,   169,
       0,    33,     0,     0,     0,     0,   -70,   -70,    34,    35,
      36,     0,   -70,     0,     0,     0,     0,   170,     0,     0,
       0,   171,   -68,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,     0,
       0,     0,     0,   -71,   -71,     0,     0,     0,     0,   -71,
       0,   -64,   -64,   133,   134,   135,   136,   -64,    33,     0,
       0,     0,     0,     0,     0,    34,    35,    36,     0,     0,
       0,     0,     0,     0,   137,     0,     0,     0,   138,   -37,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,     0,     0,     0,     0,
     -72,   -72,     0,     0,     0,     0,   -72,     0,   -73,   -73,
       0,     0,     0,     0,   -73,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     0,     0,     0,     0,     0,   -75,   -75,     0,     0,
       0,   -75,     0,     0,   -74,   -74,     0,     0,     0,   -74,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,     0,     0,     0,     0,
       0,   -72,   -72,     0,     0,     0,   -72,     0,     0,   -73,
     -73,     0,     0,     0,   -73,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,     0,     0,     0,     0,     0,   -76,   -76,     0,     0,
       0,   -76,     0,     0,   212,   -57,     0,     0,     0,   -57,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,     0,
       0,   -63,   -63,     0,     0,     0,   -63,     0,     0,   -69,
     -69,     0,     0,     0,   -69,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,     0,     0,     0,     0,     0,   -70,   -70,     0,     0,
       0,   -70,     0,     0,     0,   -55,     0,     0,   -55,   226,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,     0,     0,     0,     0,
       0,     0,   -58,     0,     0,   -58,   -58,     0,     0,   -71,
     -71,     0,     0,     0,   -71,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,     0,     0,     0,    31,    32,   125,   126,
       0,    33,     0,     0,     0,     0,   -64,   -64,    34,    35,
      36,   -64,     0,     0,     0,     0,     0,    41,     0,     0,
     -37,    42,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
       0,     0,     0,   -72,   -72,     0,     0,   -72,     0,     0,
       0,   -73,   -73,     0,     0,   -73,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,     0,     0,   -76,   -76,     0,
       0,   -76,     0,     0,     0,   297,   -57,     0,     0,   -57,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,     0,
       0,   -63,   -63,     0,     0,   -63,     0,     0,     0,   -69,
     -69,     0,     0,   -69,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,     0,     0,     0,   -70,   -70,     0,     0,   -70,
       0,     0,     0,   -71,   -71,     0,     0,   -71,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,     0,
       0,     0,   -61,   -61,   -61,   -61,     0,   -61,     0,   -64,
     -64,     0,     0,   -64,   -61,   -61,   -61,   -59,   -59,   -59,
     -59,     0,   -59,   -61,     0,     0,     0,   -61,     0,   -59,
     -59,   -59,   -60,   -60,   -60,   -60,     0,   -60,   -59,     0,
       0,     0,   -59,     0,   -60,   -60,   -60,   -62,   -62,   -62,
     -62,     0,   -62,   -60,     0,     0,     0,   -60,     0,   -62,
     -62,   -62,    31,    32,   125,   126,     0,    33,   -62,     0,
       0,     0,   -62,     0,    34,    35,    36,   133,   134,   135,
     136,     0,    33,    41,     0,     0,     0,    42,     0,    34,
      35,    36,   155,   156,   157,   158,     0,    33,   137,     0,
       0,     0,   138,     0,    34,    35,    36,   166,   167,   168,
     169,     0,    33,   159,     0,     0,     0,   160,     0,    34,
      35,    36,   238,   239,   240,   241,     0,    33,   170,     0,
       0,     0,   171,     0,    34,    35,    36,   263,   264,   265,
     266,     0,    33,   242,     0,     0,     0,   243,     0,    34,
      35,    36,     0,     0,     0,     0,     0,     0,   267,     0,
       0,     0,   268,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   225,   -54,   -54,   -54,   -54,   -54,   -54,   -54,     0,
       0,     0,     0,     0,     0,   -55,     0,     0,   -55,     0,
       0,     0,     0,   -54,     0,     0,   -54,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,     0,     0,     0,   -56,
       0,     0,   -56,     0,     0,     0,     0,   -58,     0,     0,
     -58,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,     0,     0,     0,
       0,     0,   -73,   -73,     0,     0,     0,     0,     0,     0,
     -76,   -76,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,     0,     0,
       0,     0,     0,   292,   -57,     0,     0,     0,     0,     0,
       0,   -63,   -63,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,     0,
       0,     0,     0,     0,   -69,   -69,     0,     0,     0,     0,
       0,     0,   -70,   -70,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
       0,     0,     0,     0,     0,   -71,   -71,     0,     0,     0,
       0,     0,     0,   -64,   -64,   209,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,     0,     0,     0,     0,     0,     0,   -53,     0,     0,
       0,     0,     0,     0,     0,   -55,   209,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,     0,     0,     0,   -54,     0,
       0,     0,     0,     0,     0,     0,   -56,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,     0,     0,     0,     0,     0,     0,   -58,
       0,     0,     0,     0,     0,   -75,   -75,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,     0,   -74,   -74,     0,
       0,     0,     0,     0,     0,   -72,   -72,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,     0,     0,     0,     0,   -73,   -73,     0,
       0,     0,     0,     0,     0,   -76,   -76,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,     0,     0,   -57,   216,     0,
       0,     0,     0,     0,     0,   -63,   -63,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,     0,     0,     0,     0,   -69,   -69,     0,
       0,     0,     0,     0,     0,   -70,   -70,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,     0,     0,     0,     0,   -71,   -71,     0,
       0,     0,     0,     0,     0,   -64,   -64,    84,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,     0,     0,     0,     0,   -53,     0,     0,
       0,     0,     0,     0,     0,   -55,    84,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,     0,   -54,    83,   -51,   -51,
     -51,   -51,   -51,   -51,   -56,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,   -51,    83,   -52,   -52,
     -52,   -52,   -52,   -52,     0,   -58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -52
};

static const yytype_int16 yycheck[] =
{
       1,   127,     9,   198,    14,    27,   106,    23,     9,     5,
       6,   212,     0,   113,    27,   216,     1,   117,    19,    29,
       5,     6,    39,    24,    29,    42,    29,   228,    27,    32,
       5,     6,    28,    40,    29,    23,   106,   232,     0,    40,
      30,    42,   106,    28,   106,   106,     3,     4,     5,     6,
     107,     8,    69,    70,    29,    13,    14,   114,    15,    16,
      17,    23,    19,   189,    21,    22,    23,    24,    69,    27,
       0,    28,     2,    30,    31,     0,    77,    78,    79,    80,
      81,    82,    83,    84,   106,     0,    87,    30,     1,   106,
     107,   292,     5,     6,     5,     6,   297,   114,    23,     7,
       8,     9,    10,    11,    12,    13,    14,   108,    23,     0,
       0,     0,     0,   114,   121,    28,    28,    31,    29,    27,
     121,   138,    27,    28,   131,    33,     3,     4,     5,     6,
     131,     8,    23,    23,    23,    23,    14,   138,    15,    16,
      17,    28,    19,   160,    21,    22,     0,    24,   149,    27,
      29,    28,    27,    30,   171,    29,    13,    14,    32,   160,
     161,    27,    28,     3,     4,     5,     6,    27,     8,    23,
     171,   188,    29,   230,    27,    15,    16,    17,    14,    19,
     181,    21,    22,    23,    24,    27,    13,    14,    28,    27,
      30,    31,    29,    29,    29,    32,    32,    32,    29,   299,
      27,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     310,   212,   229,   230,   314,   216,    27,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   243,   228,   229,   299,
      10,    11,    12,    13,    14,   299,    29,   299,   299,    32,
     310,    27,   243,   300,   314,   246,   310,    27,   310,   310,
     314,   268,   314,   314,   311,     7,     8,     9,    10,    11,
      12,    13,    14,    42,    29,    10,    11,   268,    13,    14,
     271,    11,    27,    13,    14,    27,    28,   299,    29,    13,
      14,    33,   299,   300,    29,    64,    29,    32,   310,    29,
      69,   292,   314,   310,   311,    29,   297,   314,    77,    78,
      79,    80,    81,    82,    83,    84,    27,    28,    87,    11,
     311,    13,    14,     9,    10,    11,    12,    13,    14,    29,
       3,     4,     5,     6,    29,     8,    27,    29,    27,   108,
      32,    27,    15,    16,    17,   114,    19,    20,    21,    22,
      23,    24,    13,    14,    29,    28,    27,    30,    31,    27,
       3,     4,     5,     6,    11,     8,    13,    14,    29,   138,
      27,    32,    15,    16,    17,    28,    19,    28,    21,    22,
     149,    24,    29,    29,    29,    28,    32,    30,     5,     6,
      29,   160,   161,    32,    27,     3,     4,     5,     6,    29,
       8,    11,   171,    13,    14,    27,    28,    15,    16,    17,
      29,    19,   181,    21,    22,    23,    24,    27,    27,    28,
      28,    27,    30,    31,     8,     9,    10,    11,    12,    13,
      14,    42,    29,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    29,   212,    29,    29,    29,   216,    32,   218,
     219,   220,   221,   222,   223,   224,   225,   226,    69,   228,
     229,    29,    29,    27,    32,    32,    77,    78,    79,    80,
      81,    82,    83,    84,   243,    31,    87,   246,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    29,    29,    29,
      29,    27,    29,     3,     4,     5,     6,   108,     8,   268,
      29,    31,   271,   114,    33,    15,    16,    17,    29,    19,
      20,    21,    22,    23,    24,    29,    29,    29,    28,    27,
      30,    31,     2,   292,    72,    -1,    46,   138,   297,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,   149,    -1,
      10,    11,   311,    13,    14,    13,    14,    -1,    -1,   160,
     161,    28,    29,     3,     4,     5,     6,    -1,     8,    29,
     171,    29,    32,    -1,    32,    15,    16,    17,    -1,    19,
     181,    21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,
      30,    31,     8,     9,    10,    11,    12,    13,    14,    42,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,   212,    -1,    29,    -1,   216,    32,   218,   219,   220,
     221,   222,   223,   224,   225,   226,    69,   228,   229,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,   243,    -1,    87,   246,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,   108,     8,   268,    29,    -1,
     271,   114,    33,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,    31,
      11,   292,    13,    14,    -1,   138,   297,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,   149,    -1,    29,    -1,
     311,    32,    10,    11,    12,    13,    14,   160,   161,    28,
      29,     3,     4,     5,     6,    -1,     8,    11,   171,    13,
      14,    29,    -1,    15,    16,    17,    -1,    19,   181,    21,
      22,    23,    24,    27,    -1,    -1,    28,    -1,    30,    31,
      -1,     9,    10,    11,    12,    13,    14,    42,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,   212,
      -1,    29,    -1,   216,    32,   218,   219,   220,   221,   222,
     223,   224,   225,   226,    69,   228,   229,    10,    11,    12,
      13,    14,    77,    78,    79,    80,    81,    82,    83,    84,
     243,    -1,    87,   246,    27,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,   108,     8,   268,    28,    29,   271,   114,
      32,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    -1,    30,    31,    -1,   292,
      -1,    -1,    -1,   138,   297,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,   149,    -1,    -1,    -1,   311,     9,
      10,    11,    12,    13,    14,   160,   161,    28,    29,     3,
       4,     5,     6,    -1,     8,    -1,   171,    -1,    -1,    29,
      -1,    15,    16,    17,    -1,    19,   181,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    -1,    30,    31,    -1,     9,
      10,    11,    12,    13,    14,    42,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,   212,    -1,    29,
      -1,   216,    32,   218,   219,   220,   221,   222,   223,   224,
     225,   226,    69,   228,   229,    10,    11,    -1,    13,    14,
      77,    78,    79,    80,    81,    82,    83,    84,   243,    -1,
      87,   246,    27,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,   108,     8,   268,    28,    29,   271,   114,    32,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    28,    -1,    30,    31,    -1,   292,    -1,    -1,
      -1,   138,   297,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,   149,    -1,    -1,    -1,   311,     9,    10,    11,
      12,    13,    14,   160,   161,    28,    29,    -1,    -1,    32,
      33,    -1,    -1,    42,   171,    27,     3,     4,     5,     6,
      -1,     8,    10,    11,   181,    13,    14,    -1,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    27,
      69,    28,    -1,    30,    31,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    83,   212,    -1,    -1,    87,   216,
      -1,   218,   219,   220,   221,   222,   223,   224,   225,   226,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      10,    11,    12,    13,    14,   114,   243,    -1,    -1,   246,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    29,
      -1,    -1,    32,    -1,    -1,     3,     4,     5,     6,   138,
       8,   268,    29,    -1,   271,    32,    42,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      28,   160,    30,    31,    -1,   292,    -1,    -1,    -1,    -1,
     297,    -1,   171,    69,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,   311,    -1,    82,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
      33,    -1,    -1,   202,   203,   204,   205,   206,   207,   208,
      -1,   210,   108,   212,    -1,    -1,    -1,   216,   114,   218,
     219,   220,   221,   222,   223,   224,    -1,   226,    -1,   228,
     229,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,   138,    -1,   243,    -1,    15,    16,    17,    42,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,    31,    -1,   160,    -1,    -1,    -1,    -1,   268,
      10,    11,    12,    13,    14,   171,    69,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    81,    29,
      -1,    -1,    32,   292,    87,    -1,    -1,    -1,   297,    28,
      29,    -1,    -1,    32,    33,    -1,   202,   203,   204,   205,
     206,   207,   311,    -1,   210,   108,   212,    -1,    -1,    -1,
     216,   114,   218,   219,   220,   221,   222,   223,    -1,    -1,
     226,    -1,   228,   229,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,   138,    -1,   243,    -1,    15,
      16,    17,    42,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    28,    -1,    30,    31,    -1,   160,    -1,    -1,
      -1,    -1,   268,    10,    11,    12,    13,    14,   171,    69,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      80,    -1,    29,    -1,    -1,    -1,   292,    87,    -1,    -1,
      -1,   297,    28,    29,    -1,    -1,    32,    33,    -1,   202,
     203,   204,   205,   206,    42,   311,    -1,   210,   108,   212,
      -1,    -1,    -1,   216,   114,   218,   219,   220,   221,   222,
      -1,    -1,    -1,   226,    -1,   228,   229,    -1,    -1,    -1,
      -1,    69,    -1,    -1,     3,     4,     5,     6,   138,     8,
     243,    79,    -1,    -1,    -1,    -1,    15,    16,    17,    87,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
     160,    30,    31,    -1,    -1,   268,    -1,    -1,    -1,    -1,
     108,   171,    -1,    -1,    10,    11,   114,    13,    14,    -1,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,   292,
      -1,    -1,    -1,    29,   297,    10,    11,    -1,    13,    14,
     138,    27,   202,   203,   204,   205,    -1,    33,   311,    -1,
     210,    42,   212,    -1,    29,    -1,   216,    -1,   218,   219,
     220,   221,   160,    -1,    -1,    -1,   226,    -1,   228,   229,
      -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    78,    -1,    42,
       9,    10,    11,    12,    13,    14,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,    -1,   268,    -1,
      29,    -1,   210,    -1,   212,    -1,    69,   108,   216,    -1,
     218,   219,   220,   114,    77,    -1,    -1,    -1,   226,    -1,
     228,   229,   292,    -1,    87,    -1,    -1,   297,     8,     9,
      10,    11,    12,    13,    14,   243,    -1,   138,    -1,    -1,
      -1,   311,    -1,    -1,    -1,   108,    -1,    -1,    -1,    29,
      -1,   114,    -1,     3,     4,     5,     6,    -1,     8,   160,
     268,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
     171,    21,    22,    23,    24,   138,    -1,    -1,    28,    42,
      30,    31,    -1,    -1,   292,    -1,    42,    -1,    -1,   297,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,
      -1,   202,   203,   311,    -1,    -1,    69,    -1,   171,   210,
      -1,   212,    -1,    69,    -1,   216,    -1,   218,   219,    -1,
      -1,    -1,    85,    -1,    87,   226,    -1,   228,   229,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,    -1,   243,    -1,    -1,   108,    -1,   210,    -1,   212,
      -1,   114,   108,   216,    -1,   218,    -1,    -1,   114,    -1,
      -1,    -1,    -1,   226,    -1,   228,   229,   268,     8,     9,
      10,    11,    12,    13,    14,   138,    -1,    -1,    -1,    -1,
     243,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,   292,    -1,    -1,    -1,    -1,   297,   160,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   268,    -1,    -1,   171,    -1,
     311,    -1,    -1,    -1,    -1,   171,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,   292,
      -1,    -1,    -1,    -1,   297,    -1,    -1,    28,    29,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,   210,   311,   212,
      -1,    -1,    -1,   216,   210,    -1,   212,    -1,    -1,    -1,
     216,    -1,    -1,   226,    -1,   228,   229,    -1,    -1,    -1,
     226,    -1,   228,   229,    -1,    -1,     3,     4,     5,     6,
     243,     8,    -1,    -1,    -1,    -1,    -1,   243,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,    31,   268,    -1,    -1,    -1,    -1,
      -1,    -1,   268,    -1,    -1,    -1,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,   292,
      -1,    -1,    -1,    -1,   297,    -1,   292,    -1,    28,    29,
      -1,   297,    32,    33,     3,     4,     5,     6,   311,     8,
      -1,    -1,    -1,    -1,    -1,   311,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
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
      31,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    -1,    -1,
      28,    29,    -1,    -1,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,    33,    -1,    -1,    28,    29,    -1,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    -1,    27,
      28,    -1,    -1,    -1,    -1,    33,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    33,    -1,    27,    28,    -1,    -1,    -1,    -1,
      33,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    33,    -1,    27,
      28,    -1,    -1,    -1,    -1,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    27,    28,    15,    16,
      17,    -1,    33,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    28,    29,     7,     8,     9,    10,    11,    12,    13,
      14,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    33,
      -1,    27,    28,     3,     4,     5,     6,    33,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    29,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    27,    28,
      -1,    -1,    -1,    -1,    33,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    33,    -1,    -1,    28,    29,    -1,    -1,    -1,    33,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    33,    -1,    -1,    28,
      29,    -1,    -1,    -1,    33,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    33,    -1,    -1,    28,    29,    -1,    -1,    -1,    33,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    33,    -1,    -1,    28,
      29,    -1,    -1,    -1,    33,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,    28,
      29,    -1,    -1,    -1,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    28,    29,    15,    16,
      17,    33,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
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
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    28,
      29,    -1,    -1,    32,    15,    16,    17,     3,     4,     5,
       6,    -1,     8,    24,    -1,    -1,    -1,    28,    -1,    15,
      16,    17,     3,     4,     5,     6,    -1,     8,    24,    -1,
      -1,    -1,    28,    -1,    15,    16,    17,     3,     4,     5,
       6,    -1,     8,    24,    -1,    -1,    -1,    28,    -1,    15,
      16,    17,     3,     4,     5,     6,    -1,     8,    24,    -1,
      -1,    -1,    28,    -1,    15,    16,    17,     3,     4,     5,
       6,    -1,     8,    24,    -1,    -1,    -1,    28,    -1,    15,
      16,    17,     3,     4,     5,     6,    -1,     8,    24,    -1,
      -1,    -1,    28,    -1,    15,    16,    17,     3,     4,     5,
       6,    -1,     8,    24,    -1,    -1,    -1,    28,    -1,    15,
      16,    17,     3,     4,     5,     6,    -1,     8,    24,    -1,
      -1,    -1,    28,    -1,    15,    16,    17,     3,     4,     5,
       6,    -1,     8,    24,    -1,    -1,    -1,    28,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    28,     7,     8,     9,    10,    11,    12,    13,
      14,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,     7,     8,     9,    10,    11,    12,    13,
      14,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    27,    28,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    27,     8,     9,    10,
      11,    12,    13,    14,    27,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    27,     8,     9,    10,
      11,    12,    13,    14,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    35,    36,    37,    39,     1,     5,     6,    28,
      48,    72,     0,    36,    27,    48,    28,    38,    29,    40,
      27,    49,    50,    72,    32,    29,    72,    41,    30,    42,
      43,     3,     4,     8,    15,    16,    17,    19,    21,    22,
      23,    24,    28,    37,    42,    44,    45,    46,    47,    51,
      52,    53,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    71,    72,    73,    28,
      28,    55,    48,    55,    31,    46,    27,    14,    13,    11,
      10,    12,     9,     8,     7,    33,    66,    28,    55,    55,
      56,    27,    29,    59,    66,    60,    61,    62,    63,    64,
      65,    66,    57,    57,    69,    70,    29,    27,    32,    29,
      47,    56,    57,    20,    27,    47,    56,    29,    47,     5,
       6,    28,    72,     5,     6,     5,     6,    30,     1,     5,
       6,    28,    72,     3,     4,     5,     6,    24,    28,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    71,    72,    73,    38,     3,     4,     5,     6,    24,
      28,    67,    68,    71,    72,    73,     3,     4,     5,     6,
      24,    28,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    71,    72,    73,    19,    21,    22,    30,
      42,    51,    52,    53,    54,    55,    55,    48,    43,    27,
      48,    55,    14,    13,    11,    10,    12,     9,     8,     7,
      33,    66,    28,    27,    55,    66,    28,    55,    14,    13,
      11,    10,    12,     9,     8,     7,    33,    66,    28,    28,
      28,    55,    43,    27,    29,    44,    29,    29,     3,     4,
       5,     6,    24,    28,    59,    66,    67,    68,    71,    72,
      73,    60,    61,    62,    63,    64,    65,    66,    57,    70,
      29,    70,    29,     3,     4,     5,     6,    24,    28,    59,
      66,    67,    68,    71,    72,    73,    60,    61,    62,    63,
      64,    65,    66,    57,    70,    55,    56,    27,    44,    31,
      55,    66,    28,    29,    29,    55,    66,    28,    29,    29,
      27,    31,    29,    70,    29,    70,    47,    56,    29,    29,
      20,    27,    47,    56,    29,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    35,    36,    36,    38,    37,    37,    40,
      41,    39,    43,    42,    44,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    52,    52,    53,    54,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    72,    72,    73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     4,     3,     0,
       0,     8,     0,     4,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     0,
       1,     2,     5,     7,     3,     9,     1,     0,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     4,     1,     3,     1,     0,     1,
       1,     3,     1,     1,     1,     1,     1
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
#line 2287 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 61 "src/bison/math.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 2293 "src/bison/grammar.c"
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
#line 2314 "src/bison/grammar.c"
    break;

  case 7: /* declaration: LET declarator @1 ';'  */
#line 83 "src/bison/math.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 2322 "src/bison/grammar.c"
    break;

  case 8: /* declaration: LET error ';'  */
#line 86 "src/bison/math.y"
                    {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 2333 "src/bison/grammar.c"
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
#line 2366 "src/bison/grammar.c"
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
#line 2383 "src/bison/grammar.c"
    break;

  case 11: /* func_declaration: LET declarator '(' @2 id_list.opt ')' $@3 compound_stmt  */
#line 132 "src/bison/math.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 2392 "src/bison/grammar.c"
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
#line 2407 "src/bison/grammar.c"
    break;

  case 13: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 147 "src/bison/math.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
    }
#line 2416 "src/bison/grammar.c"
    break;

  case 14: /* block_item_list.opt: block_item_list  */
#line 153 "src/bison/math.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 2422 "src/bison/grammar.c"
    break;

  case 15: /* block_item_list.opt: %empty  */
#line 154 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2428 "src/bison/grammar.c"
    break;

  case 16: /* block_item_list: block_item_list block_item  */
#line 157 "src/bison/math.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2434 "src/bison/grammar.c"
    break;

  case 17: /* block_item_list: block_item  */
#line 158 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2440 "src/bison/grammar.c"
    break;

  case 26: /* declarator: '(' declarator ')'  */
#line 173 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2446 "src/bison/grammar.c"
    break;

  case 27: /* id_list: id_list ',' id  */
#line 176 "src/bison/math.y"
                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2452 "src/bison/grammar.c"
    break;

  case 28: /* id_list: id  */
#line 177 "src/bison/math.y"
         { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2458 "src/bison/grammar.c"
    break;

  case 29: /* id_list.opt: %empty  */
#line 180 "src/bison/math.y"
                    { (yyval.list) = NULL; }
#line 2464 "src/bison/grammar.c"
    break;

  case 31: /* expr_stmt: expression ';'  */
#line 184 "src/bison/math.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2470 "src/bison/grammar.c"
    break;

  case 32: /* cond_stmt: IF '(' expression ')' statement  */
#line 187 "src/bison/math.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 2478 "src/bison/grammar.c"
    break;

  case 33: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 190 "src/bison/math.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2486 "src/bison/grammar.c"
    break;

  case 34: /* jmp_stmt: RETURN expression ';'  */
#line 195 "src/bison/math.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 2492 "src/bison/grammar.c"
    break;

  case 35: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 198 "src/bison/math.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2500 "src/bison/grammar.c"
    break;

  case 37: /* expression.opt: %empty  */
#line 206 "src/bison/math.y"
                       { (yyval.ast) = NULL; }
#line 2506 "src/bison/grammar.c"
    break;

  case 40: /* assign_expr: unary_expr '=' assign_expr  */
#line 211 "src/bison/math.y"
                                 { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2512 "src/bison/grammar.c"
    break;

  case 42: /* dl_dg_expr: dl_dg_expr DL_DG list_ctr_expr  */
#line 215 "src/bison/math.y"
                                     {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2521 "src/bison/grammar.c"
    break;

  case 44: /* list_ctr_expr: list_ctr_expr COLON logical_or_expr  */
#line 222 "src/bison/math.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2530 "src/bison/grammar.c"
    break;

  case 46: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 229 "src/bison/math.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2539 "src/bison/grammar.c"
    break;

  case 48: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 236 "src/bison/math.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2548 "src/bison/grammar.c"
    break;

  case 50: /* eq_expr: eq_expr EQ rel_expr  */
#line 243 "src/bison/math.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2557 "src/bison/grammar.c"
    break;

  case 52: /* rel_expr: rel_expr REL add_expr  */
#line 250 "src/bison/math.y"
                            {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2566 "src/bison/grammar.c"
    break;

  case 54: /* add_expr: add_expr ADD mult_expr  */
#line 257 "src/bison/math.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2575 "src/bison/grammar.c"
    break;

  case 56: /* mult_expr: mult_expr MULT unary_expr  */
#line 264 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].operator), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2584 "src/bison/grammar.c"
    break;

  case 58: /* unary_expr: unary_ops unary_expr  */
#line 271 "src/bison/math.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].operator), (yyvsp[0].ast));
        free((yyvsp[-1].operator));
    }
#line 2593 "src/bison/grammar.c"
    break;

  case 64: /* postfix_expr: postfix_expr '(' arg_expr_list.opt ')'  */
#line 284 "src/bison/math.y"
                                             {
        (yyval.ast) = NULL;
    }
#line 2601 "src/bison/grammar.c"
    break;

  case 65: /* arg_expr_list: assign_expr  */
#line 289 "src/bison/math.y"
                           { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2607 "src/bison/grammar.c"
    break;

  case 66: /* arg_expr_list: arg_expr_list ',' assign_expr  */
#line 290 "src/bison/math.y"
                                    { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2613 "src/bison/grammar.c"
    break;

  case 68: /* arg_expr_list.opt: %empty  */
#line 294 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2619 "src/bison/grammar.c"
    break;

  case 69: /* primary_expr: id  */
#line 297 "src/bison/math.y"
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
#line 2637 "src/bison/grammar.c"
    break;

  case 71: /* primary_expr: '(' expression ')'  */
#line 311 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2643 "src/bison/grammar.c"
    break;

  case 72: /* id: NAME  */
#line 314 "src/bison/math.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 2649 "src/bison/grammar.c"
    break;

  case 73: /* id: BUILT_IN  */
#line 315 "src/bison/math.y"
               { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 2655 "src/bison/grammar.c"
    break;

  case 74: /* constant: NUMBER_REAL  */
#line 318 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 2661 "src/bison/grammar.c"
    break;

  case 75: /* constant: NUMBER_INT  */
#line 319 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 2667 "src/bison/grammar.c"
    break;

  case 76: /* constant: NIL  */
#line 320 "src/bison/math.y"
          { }
#line 2673 "src/bison/grammar.c"
    break;


#line 2677 "src/bison/grammar.c"

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

#line 323 "src/bison/math.y"


void yyerror(const char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    if (s) CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
    ++errors_count;
}
