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
    StackNode *parent_stacknode_ref;

    void free_scope_cb(StackNode *node) { scope_free(node->data); }

    StackNode *context_get_current_stacknode_ref() {
        LIST_FOR_EACH_REVERSE(current_context->scopes, {
            if (((Scope *)__IT__->data)->index == current_context->current_scope) {
                return __IT__;
            }
        });
        return NULL;
    }

#line 104 "src/bison/grammar.c"

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
  YYSYMBOL_NIL = 4,                        /* NIL  */
  YYSYMBOL_NUMBER_REAL = 5,                /* NUMBER_REAL  */
  YYSYMBOL_NAME = 6,                       /* NAME  */
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
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_FLOAT = 20,                     /* FLOAT  */
  YYSYMBOL_LIST = 21,                      /* LIST  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_LET = 26,                       /* LET  */
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
#define YYLAST   3588

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  315

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
       0,    74,    74,    75,    78,    79,    82,    82,   101,   109,
     138,   109,   155,   156,   159,   160,   163,   172,   172,   192,
     193,   196,   197,   200,   201,   204,   205,   206,   207,   208,
     211,   212,   215,   218,   221,   226,   229,   234,   237,   238,
     241,   242,   245,   246,   252,   253,   259,   260,   266,   267,
     273,   274,   278,   284,   285,   291,   292,   298,   299,   305,
     306,   307,   308,   311,   312,   317,   318,   321,   322,   325,
     338,   339,   342,   345,   346,   347,   354,   363,   364,   365
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER_INT", "NIL",
  "NUMBER_REAL", "NAME", "MULT", "ADD", "REL", "AND", "OR", "EQ", "COLON",
  "DL_DG", "EXCLAMATION", "PERCENT", "QUESTION", "STR_LITERAL", "INT",
  "FLOAT", "LIST", "IF", "ELSE", "FOR", "RETURN", "LET", "THEN", "';'",
  "'('", "')'", "','", "'{'", "'}'", "'='", "$accept", "prog",
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

#define YYPACT_NINF (-206)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     396,    11,    39,    15,    31,   112,   134,   137,    19,    52,
      56,   -10,  -206,   147,     0,    66,    68,    81,   149,    17,
     161,    -2,   198,   288,   159,    23,    63,   110,   129,    35,
     241,   321,    70,   340,  1846,   164,  1877,   114,  1139,  1433,
       7,  1187,  1359,  1666,    30,    69,  1717,  1733,  1908,  1939,
      85,  1970,  2001,  2032,  2063,  2094,  2125,  2156,    78,   102,
      27,   311,   363,   177,  1236,   351,  3500,   575,  1717,  1626,
    2539,  2547,   201,  2575,  1733,  1365,   108,   116,   203,  2187,
    2218,  2831,  2831,  2831,  2831,  2831,  2831,  2831,  2831,  1717,
     740,    84,   122,   132,   144,   146,  2249,  2583,   367,  3522,
     400,  1302,  1475,  3530,  1500,  1508,  3552,   148,   383,   428,
     171,   377,  1365,  2837,  2611,   486,   207,   439,  1321,  1071,
    2280,   210,  1321,  2311,   215,    66,   223,   442,    66,   467,
    2619,   263,  1846,  2647,  2655,  2683,  2691,  1733,   238,     3,
     245,   357,   408,   855,   323,  3273,   783,  1733,  2719,  2727,
    2755,  2763,   246,    66,   251,  3345,  3368,  3376,  3399,  1733,
    2831,  3407,  3430,  3438,  3461,   316,  1444,  1564,  1697,  1733,
      73,   247,   393,   261,   512,  1110,   948,   453,  2837,  2431,
    2439,  2467,  2475,   259,   264,   267,  1717,  1846,   542,   651,
     707,   816,   872,   262,   268,   270,   274,   291,  1877,   313,
    2853,  2853,  2853,  2853,  2853,  2853,  2853,  2853,  1733,   903,
      84,   319,   325,  3560,    84,   327,  2859,  2859,  2859,  2859,
    2859,  2859,  2859,  2859,  2837,   618,    84,  2342,  1733,  1365,
     356,  1877,   981,   360,   496,  2373,   308,  2791,  3113,  3121,
    3145,  3153,  1733,   271,  3281,  2853,  3177,  3185,  3209,  3217,
    1166,   909,  1007,  3305,  1020,  1072,  3313,   366,   370,   358,
    3469,   378,  2503,  2882,  2890,  2915,  2923,  1733,   255,  3047,
    2859,  2948,  2956,  2981,  2989,  1151,   525,   677,  3055,   690,
     842,  3080,   498,   395,   397,   414,  1037,   411,  2404,   424,
    3337,    84,  2799,  3492,   426,  3088,    84,  2511,   377,  1365,
    1209,  3241,   456,  3014,   458,  1748,   465,  3249,  3022,   377,
    1071,  1784,   470,   377,  1815
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
       0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,   491,    65,   412,  -206,  -206,  -206,  -206,  -206,
     484,   -29,  -131,  -196,  -206,   466,   -81,    -9,   -67,   -65,
     -62,   -59,    -4,   -58,   130,  1488,  1451,  1389,  1313,  1051,
    1197,  1081,   229,   394,   559,  -206,  -205,   724,    -8,     4,
     889
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,    48,    21,     7,    23,    32,    25,    26,
      27,    49,    36,    50,    51,    52,    53,    16,    54,    55,
      56,    57,    58,    95,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,   109,   110,    70,    71,    72,
      73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,   198,   236,    35,     8,   258,    19,   126,     8,   261,
     -61,   -61,   -61,   -61,   200,   -61,    11,   -73,    18,    31,
     129,   283,   -61,   -61,   -61,    14,    24,    28,   -72,   -72,
     115,    12,     9,   -40,    28,   287,   -61,   120,    81,   150,
     -73,   123,    76,    77,   189,   -74,   190,    22,    15,   191,
       1,     2,   192,    29,   116,   -40,   231,     3,   -75,    74,
      10,   121,   -76,    92,   154,     6,   150,   -10,   -74,     6,
      93,    94,   124,   163,   163,   163,   163,   163,   163,   163,
     163,   -75,   188,   181,   216,   -76,   302,   165,   166,   167,
     168,   304,    40,   -13,    30,   125,    -6,    20,    75,    41,
      42,    43,    34,   -40,   -40,   181,    80,   193,    94,   -30,
     -30,   150,    -3,   169,   -68,   194,   195,   126,    78,   196,
     126,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   150,
     -37,    -3,    -3,   199,    -5,   127,    96,    -4,    -3,   150,
     -15,   -15,   -78,   -78,   211,   126,    97,    -2,   -78,    -8,
      -6,   150,   163,    -5,    -5,   212,    -4,    -4,   128,    -7,
      -5,   150,   111,    -4,   -11,   215,    -2,    -2,    -8,    -8,
     181,   285,   -39,    -2,   112,    -8,   -41,   138,    -7,    -7,
      -9,    -9,   230,   -11,   -11,    -7,    84,   -46,   -46,   -46,
     -11,    -9,   248,   248,   248,   248,   248,   248,   248,   248,
     150,   114,   181,   -18,   138,   -46,   181,   152,   273,   273,
     273,   273,   273,   273,   273,   273,   181,   305,   181,   107,
     150,   108,   -18,   -18,   284,    94,   -31,   -31,   311,   -18,
     153,   189,   314,   190,   150,   119,   191,   248,   289,   192,
     122,   306,   189,   117,   190,   -72,   189,   191,   190,   138,
     192,   191,   312,   -30,   192,   201,   -42,   217,   -42,   150,
       1,     2,   273,   294,   197,   217,   -43,   138,   -37,   188,
     219,   -46,   -46,   -46,   -72,   -42,   146,   -42,   -42,   -30,
     188,   201,   -43,   181,   188,   -43,   -43,   227,   181,   138,
     232,   -46,   -46,   228,   193,    94,   229,    90,   -39,   138,
     233,   -43,   150,   146,   234,   193,   194,     1,     2,   193,
      99,    99,    99,    99,    99,    99,    99,   106,   -12,   235,
     177,    82,   -42,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   204,   -50,   -50,   -50,   -50,   205,   206,   257,   -42,
     108,   288,   177,   237,   108,   -78,   -78,   -78,   146,   259,
     -78,   -16,   -16,   -50,   282,   260,   108,   262,   138,    85,
     -50,   -50,   -50,   -50,    86,    87,   146,   -44,   -44,   202,
     -14,   -14,   138,   -44,   -44,    83,   209,    82,   -43,   -50,
      37,    38,    39,   130,   286,    40,   -31,   -44,   146,   213,
     -31,   -44,    41,    42,    43,   -43,   -41,   138,   146,   184,
     292,   185,   186,   -44,   -44,   218,    47,   225,   293,   187,
     -45,   -45,    83,   -65,   -65,     1,     2,   203,   -46,   -46,
     -46,   108,     3,   -44,   -44,   297,   108,   298,   -45,   244,
     244,   244,   244,   244,   244,   244,   256,   146,   -46,   177,
     138,   147,   299,   177,   300,   269,   269,   269,   269,   269,
     269,   269,   281,   177,   301,   177,   303,   146,   -67,   113,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   147,   -66,
     -66,   146,   -72,   -72,   290,   160,   160,   160,   160,   160,
     160,   160,   160,   -55,   -55,   178,   307,   224,   308,   -33,
     -33,   -33,   -33,   310,   -33,    13,   146,   -30,   -30,   295,
     313,   -33,   -33,   -33,   183,   -33,   -33,   178,   -33,   118,
     -33,   -33,   -33,   147,    33,   -33,     0,    79,   -33,   -33,
     177,   -48,   -48,   -48,   -48,   177,   -31,   -31,   -41,   -41,
       0,   147,     0,     0,   219,   -47,   -47,   -47,     0,   146,
       0,   147,   -48,   -48,     0,   -26,   -26,   -26,   -26,     0,
     -26,     0,     0,   147,   160,   -47,   -47,   -26,   -26,   -26,
       0,   -26,   -26,   147,   -26,   -26,   -26,   -26,   -26,     0,
       0,   -26,   178,     0,   -26,   -26,     0,     0,     0,     0,
       0,     0,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,     0,     0,   245,   245,   245,   245,   245,   245,
     245,   245,   147,   -55,   178,     0,   148,     0,   178,    89,
     270,   270,   270,   270,   270,   270,   270,   270,   178,     0,
     178,     0,   147,     0,     0,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   148,     0,     0,   147,     0,     0,   245,
     161,   161,   161,   161,   161,   161,   161,   161,   -58,   -58,
     179,     0,   -58,     0,   -25,   -25,   -25,   -25,     0,   -25,
       0,   147,     0,     0,   270,     0,   -25,   -25,   -25,     0,
     -25,   -25,   179,   -25,   -25,   -25,   -25,   -25,   148,     0,
     -25,     0,     0,   -25,   -25,   178,   -49,   -49,   -49,   -49,
     178,     0,     0,     0,     0,     0,   148,     0,     0,   -52,
     -52,   -52,   -52,     0,   147,     0,   148,   -49,   -49,     0,
     -27,   -27,   -27,   -27,     0,   -27,     0,     0,   148,   161,
     -52,   -52,   -27,   -27,   -27,     0,   -27,   -27,   148,   -27,
     -27,   -27,   -27,   -27,     0,     0,   -27,   179,     0,   -27,
     -27,     0,     0,     0,     0,     0,     0,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,   246,
     246,   246,   246,   246,   246,   246,   246,   148,   -58,   179,
       0,   149,     0,   179,   -58,   271,   271,   271,   271,   271,
     271,   271,   271,   179,     0,   179,     0,   148,     0,     0,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   149,     0,
       0,   148,     0,     0,   246,   162,   162,   162,   162,   162,
     162,   162,   162,   -55,     0,   180,     0,   208,     0,   -28,
     -28,   -28,   -28,     0,   -28,     0,   148,     0,     0,   271,
       0,   -28,   -28,   -28,     0,   -28,   -28,   180,   -28,   -28,
     -28,   -28,   -28,   149,     0,   -28,     0,     0,   -28,   -28,
     179,   -51,   -51,   -51,   -51,   179,     0,     0,     0,     0,
       0,   149,     0,     0,   -48,   -48,   -48,   -48,     0,   148,
       0,   149,   -51,   -51,     0,   -29,   -29,   -29,   -29,     0,
     -29,     0,     0,   149,   162,   -48,     0,   -29,   -29,   -29,
       0,   -29,   -29,   149,   -29,   -29,   -29,   -29,   -29,     0,
       0,   -29,   180,     0,   -29,   -29,     0,     0,     0,     0,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   203,   -47,
     -47,   -47,     0,     0,   247,   247,   247,   247,   247,   247,
     247,   247,   149,   -58,   180,     0,   151,   -58,   180,   -47,
     272,   272,   272,   272,   272,   272,   272,   272,   180,     0,
     180,     0,   149,     0,     0,   223,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   151,     0,     0,   149,     0,     0,   247,
     164,   164,   164,   164,   164,   164,   164,   164,   -53,   -53,
     182,     0,     0,     0,   -32,   -32,   -32,   -32,     0,   -32,
       0,   149,     0,     0,   272,     0,   -32,   -32,   -32,     0,
     -32,   -32,   182,   -32,   -32,   -32,   -32,   -32,   151,     0,
     -32,     0,     0,   -32,   -32,   180,   -49,   -49,   -49,   -49,
     180,     0,     0,     0,     0,     0,   151,     0,     0,   -52,
     -52,   -52,   -52,     0,   149,     0,   151,   -49,     0,     0,
     -35,   -35,   -35,   -35,     0,   -35,     0,     0,   151,   164,
     -52,     0,   -35,   -35,   -35,     0,   -35,   -35,   151,   -35,
     -35,   -35,   -35,   -35,     0,     0,   -35,   182,     0,   -35,
     -35,     0,     0,     0,   133,   134,   135,   136,     0,    40,
       0,   -51,   -51,   -51,   -51,     0,    41,    42,    43,   249,
     249,   249,   249,   249,   249,   249,   249,   151,   143,   182,
     137,   -38,   -51,   182,     0,   274,   274,   274,   274,   274,
     274,   274,   274,   182,     0,   182,     0,   151,   220,   -50,
     -50,   -50,   -50,   221,   222,   143,     0,     0,   145,     0,
       0,   151,     0,     0,   249,   102,     0,   104,   105,     0,
     -50,   -50,   174,     0,     0,     0,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,     0,   145,   151,     0,     0,   274,
       0,   -45,   -45,   218,   174,     0,   103,   -79,   -79,     0,
     143,     0,   176,   -79,     0,     0,   -45,   -45,   202,     0,
     182,   -45,   -45,     0,     0,   182,     0,     0,   143,     0,
     -59,   -59,   -59,   -59,   176,   -59,   -45,     0,     0,   151,
     145,     0,   -59,   -59,   -59,     0,     0,     0,     0,     0,
     143,     0,   -18,   -18,   -18,   -18,   -59,   -18,   145,     0,
     143,     0,     0,     0,   -18,   -18,   -18,     0,   -18,   -18,
       0,   -18,   -18,   -18,   -18,   -18,     0,     0,   -18,     0,
     145,   -18,   -18,     0,   144,   -48,   -48,   -48,   -48,     0,
     145,   143,   143,   143,   252,     0,   254,   255,     0,   143,
       0,   174,     0,     0,   -48,   174,     0,   174,   174,   174,
     277,   144,   279,   280,     0,   174,     0,   174,     0,   143,
       0,   145,   145,   145,   145,   253,   145,   145,   175,   145,
       0,   176,     0,   143,     0,   176,     0,   176,   176,   176,
     176,   278,   176,   176,     0,   176,     0,   176,     0,   145,
     175,    84,   -47,   -47,   -47,     0,   144,     0,   143,     0,
       0,     0,     0,   145,    37,    38,    39,   130,     0,    40,
     -47,     0,     0,     0,   144,     0,    41,    42,    43,     0,
       0,     0,   174,    44,     0,    45,    46,   174,   145,     0,
      47,     0,     0,   132,     0,     0,   144,     0,     0,     0,
     142,   143,   -60,   -60,   -60,   -60,   144,   -60,    37,    38,
      39,   130,   176,    40,   -60,   -60,   -60,   176,     0,     0,
      41,    42,    43,     0,     0,     0,     0,   142,   -60,     0,
       0,   145,     0,   -38,    47,     0,   101,   144,   144,   144,
     144,     0,   144,   144,   173,   144,     0,   175,     0,     0,
       0,   175,     0,   175,   175,   175,   175,     0,   175,   175,
       0,   175,     0,   175,     0,   144,   173,     0,     0,     0,
       0,     0,   142,     0,     0,     0,   141,     0,     0,   144,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,
     142,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,     0,
       0,   -77,   -77,   141,   144,     0,     0,   -77,     0,     0,
       0,   100,   142,   -79,   -79,   -79,     0,     0,   -79,     0,
     172,     0,   142,     0,   -49,   -49,   -49,   -49,   175,     0,
       0,     0,     0,   175,     0,     0,     0,     0,   140,     0,
       0,     0,   172,   -49,     0,     0,     0,   144,   141,   -52,
     -52,   -52,   -52,   142,   142,   251,     0,   -51,   -51,   -51,
     -51,   142,     0,   173,     0,   140,   141,   173,   -52,   173,
     173,   276,    98,     0,     0,   139,   -51,   173,     0,   173,
       0,   142,   171,     0,     0,     0,     0,     0,   141,     0,
       0,     0,     0,     0,     0,   142,     0,     0,   141,     0,
       0,     0,   139,     0,   171,     0,     0,     0,     0,     0,
     140,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   170,
     142,     0,     0,     0,     0,     0,     0,     0,   140,   141,
     250,     0,     0,   -77,   -77,   -77,     0,   141,   -77,   172,
       0,   170,     0,   172,   173,   172,   275,   139,     0,   173,
     140,     0,     0,   172,     0,   172,     0,   141,     0,     0,
     140,     0,     0,   142,     0,   139,     0,     0,     0,     0,
       0,   141,     0,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,     0,     0,     0,     0,     0,     0,   139,     0,     0,
       0,   243,     0,     0,   -57,    91,   141,   139,     0,   140,
     -57,   171,     0,     0,     0,   171,     0,   268,     0,   -62,
     -62,   -62,   -62,     0,   -62,   171,     0,   171,     0,   140,
     172,   -62,   -62,   -62,     0,   172,     0,     0,     0,     0,
       0,     0,     0,   140,     0,   -62,   139,     0,   170,   141,
       0,     0,   170,     0,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   170,     0,   170,     0,   139,     0,   140,     0,
      37,    38,    39,   130,     0,    40,   -72,   -72,   -72,     0,
     139,   -72,    41,    42,    43,     0,   133,   134,   135,   136,
       0,    40,   171,     0,     0,     0,    47,   171,    41,    42,
      43,   -33,   -33,   -33,   -33,   139,   -33,     0,     0,     0,
       0,   140,   137,   -33,   -33,   -33,     0,   -33,   -33,     0,
     -33,   309,   -33,   -33,   -33,     0,     0,   -33,     0,   170,
     -33,   -33,     0,     0,   170,     0,     0,   -34,   -34,   -34,
     -34,     0,   -34,     0,     0,     0,     0,     0,   139,   -34,
     -34,   -34,     0,   -34,   -34,     0,   -34,   -34,   -34,   -34,
     -34,     0,     0,   -34,     0,     0,   -34,   -34,   -36,   -36,
     -36,   -36,     0,   -36,     0,     0,     0,     0,     0,     0,
     -36,   -36,   -36,     0,   -36,   -36,     0,   -36,   -36,   -36,
     -36,   -36,     0,     0,   -36,     0,     0,   -36,   -36,   -17,
     -17,   -17,   -17,     0,   -17,     0,     0,     0,     0,     0,
       0,   -17,   -17,   -17,     0,   -17,   -17,     0,   -17,     0,
     -17,   -17,   -17,     0,     0,   -17,     0,     0,   -17,   -17,
      37,    38,    39,   130,     0,    40,     0,     0,     0,     0,
       0,     0,    41,    42,    43,     0,     1,     2,     0,    44,
       0,    45,    46,   131,     0,     0,    47,     0,     0,   132,
     -20,   -23,   -23,   -23,   -23,     0,   -23,     0,     0,     0,
       0,     0,     0,   -23,   -23,   -23,     0,   -23,   -23,     0,
     -23,     0,   -23,   -23,   -23,     0,     0,   -23,     0,     0,
     -23,   -23,   -26,   -26,   -26,   -26,     0,   -26,     0,     0,
       0,     0,     0,     0,   -26,   -26,   -26,     0,   -26,   -26,
       0,   -26,     0,   -26,   -26,   -26,     0,     0,   -26,     0,
       0,   -26,   -26,    37,    38,    39,   130,     0,    40,     0,
       0,     0,     0,     0,     0,    41,    42,    43,     0,     1,
       2,     0,    44,     0,    45,    46,   131,     0,     0,    47,
       0,     0,   132,   -19,   -22,   -22,   -22,   -22,     0,   -22,
       0,     0,     0,     0,     0,     0,   -22,   -22,   -22,     0,
     -22,   -22,     0,   -22,     0,   -22,   -22,   -22,     0,     0,
     -22,     0,     0,   -22,   -22,   -24,   -24,   -24,   -24,     0,
     -24,     0,     0,     0,     0,     0,     0,   -24,   -24,   -24,
       0,   -24,   -24,     0,   -24,     0,   -24,   -24,   -24,     0,
       0,   -24,     0,     0,   -24,   -24,   -25,   -25,   -25,   -25,
       0,   -25,     0,     0,     0,     0,     0,     0,   -25,   -25,
     -25,     0,   -25,   -25,     0,   -25,     0,   -25,   -25,   -25,
       0,     0,   -25,     0,     0,   -25,   -25,   -27,   -27,   -27,
     -27,     0,   -27,     0,     0,     0,     0,     0,     0,   -27,
     -27,   -27,     0,   -27,   -27,     0,   -27,     0,   -27,   -27,
     -27,     0,     0,   -27,     0,     0,   -27,   -27,   -28,   -28,
     -28,   -28,     0,   -28,     0,     0,     0,     0,     0,     0,
     -28,   -28,   -28,     0,   -28,   -28,     0,   -28,     0,   -28,
     -28,   -28,     0,     0,   -28,     0,     0,   -28,   -28,   -29,
     -29,   -29,   -29,     0,   -29,     0,     0,     0,     0,     0,
       0,   -29,   -29,   -29,     0,   -29,   -29,     0,   -29,     0,
     -29,   -29,   -29,     0,     0,   -29,     0,     0,   -29,   -29,
     -21,   -21,   -21,   -21,     0,   -21,     0,     0,     0,     0,
       0,     0,   -21,   -21,   -21,     0,   -21,   -21,     0,   -21,
       0,   -21,   -21,   -21,     0,     0,   -21,     0,     0,   -21,
     -21,   -32,   -32,   -32,   -32,     0,   -32,     0,     0,     0,
       0,     0,     0,   -32,   -32,   -32,     0,   -32,   -32,     0,
     -32,     0,   -32,   -32,   -32,     0,     0,   -32,     0,     0,
     -32,   -32,   -35,   -35,   -35,   -35,     0,   -35,     0,     0,
       0,     0,     0,     0,   -35,   -35,   -35,     0,   -35,   -35,
       0,   -35,     0,   -35,   -35,   -35,     0,     0,   -35,     0,
       0,   -35,   -35,   -34,   -34,   -34,   -34,     0,   -34,     0,
       0,     0,     0,     0,     0,   -34,   -34,   -34,     0,   -34,
     -34,     0,   -34,     0,   -34,   -34,   -34,     0,     0,   -34,
       0,     0,   -34,   -34,   -36,   -36,   -36,   -36,     0,   -36,
       0,     0,     0,     0,     0,     0,   -36,   -36,   -36,     0,
     -36,   -36,     0,   -36,     0,   -36,   -36,   -36,     0,     0,
     -36,     0,     0,   -36,   -36,    -7,    -7,    -7,    -7,     0,
      -7,     0,     0,     0,     0,     0,     0,    -7,    -7,    -7,
       0,    -7,    -7,     0,    -7,     0,    -7,    -7,    -7,     0,
       0,    -7,     0,     0,    -7,    -7,    -8,    -8,    -8,    -8,
       0,    -8,     0,     0,     0,     0,     0,     0,    -8,    -8,
      -8,     0,    -8,    -8,     0,    -8,     0,    -8,    -8,    -8,
       0,     0,    -8,     0,     0,    -8,    -8,   -18,   -18,   -18,
     -18,     0,   -18,     0,     0,     0,     0,     0,     0,   -18,
     -18,   -18,     0,   -18,   -18,     0,   -18,     0,   -18,   -18,
     -18,     0,     0,   -18,     0,     0,   -18,   -18,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,     0,     0,     0,     0,     0,     0,
     226,   -57,   -57,     0,     0,   -57,     0,     0,   -63,   -63,
     -63,     0,     0,   -63,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
       0,     0,     0,     0,     0,     0,   -69,   -69,   -69,     0,
       0,   -69,     0,     0,   -70,   -70,   -70,     0,     0,   -70,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,     0,
       0,     0,   -71,   -71,   -71,     0,     0,   -71,     0,     0,
     -64,   -64,   -64,     0,     0,   -64,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,     0,     0,     0,     0,     0,   -63,   -63,     0,
       0,     0,     0,   -63,     0,   -69,   -69,     0,     0,     0,
       0,   -69,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,
       0,     0,     0,   -70,   -70,     0,     0,     0,     0,   -70,
       0,   -71,   -71,     0,     0,     0,     0,   -71,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,     0,     0,     0,     0,     0,   -64,
     -64,     0,     0,     0,     0,   -64,     0,   -72,   -72,     0,
       0,     0,     0,   -72,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
       0,     0,     0,     0,     0,     0,   -78,   -78,     0,     0,
       0,   -78,     0,     0,   -79,   -79,     0,     0,     0,   -79,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,     0,
       0,     0,   -77,   -77,     0,     0,     0,   -77,     0,     0,
     -72,   -72,     0,     0,     0,   -72,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,     0,     0,     0,     0,     0,     0,   210,   -57,
       0,     0,     0,   -57,     0,     0,   -63,   -63,     0,     0,
       0,   -63,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,
       0,     0,     0,     0,   -69,   -69,     0,     0,     0,   -69,
       0,     0,   -70,   -70,     0,     0,     0,   -70,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,     0,     0,     0,     0,     0,     0,
     -71,   -71,     0,     0,     0,   -71,     0,     0,   -64,   -64,
       0,     0,     0,   -64,   155,   156,   157,   158,     0,    40,
     165,   166,   167,   168,     0,    40,    41,    42,    43,     0,
       0,     0,    41,    42,    43,     0,   238,   239,   240,   241,
     159,    40,   263,   264,   265,   266,   169,    40,    41,    42,
      43,     0,     0,     0,    41,    42,    43,     0,     0,     0,
       0,     0,   242,     0,     0,     0,     0,     0,   267,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,     0,     0,     0,     0,     0,
       0,   -78,   -78,   -78,     0,     0,     0,     0,     0,   -79,
     -79,   -79,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,
       0,     0,     0,     0,   -77,   -77,   -77,     0,     0,     0,
       0,     0,   -72,   -72,   -72,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,     0,     0,     0,     0,     0,     0,   296,   -57,   -57,
       0,     0,     0,     0,     0,   -63,   -63,   -63,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,     0,     0,     0,     0,     0,     0,
     -69,   -69,   -69,     0,     0,     0,     0,     0,   -70,   -70,
     -70,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,
       0,     0,     0,   -71,   -71,   -71,     0,     0,     0,     0,
       0,   -64,   -64,   -64,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   223,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,     0,     0,     0,     0,   -55,   -55,     0,
       0,     0,     0,     0,     0,   -54,   -54,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,     0,     0,     0,     0,
     -56,   -56,     0,     0,     0,     0,     0,     0,   -58,   -58,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,     0,
       0,     0,   -78,   -78,     0,     0,     0,     0,     0,     0,
     -79,   -79,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,
       0,     0,     0,     0,   -77,   -77,     0,     0,     0,     0,
       0,     0,   -72,   -72,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
       0,     0,     0,     0,     0,     0,   291,   -57,     0,     0,
       0,     0,     0,     0,   -63,   -63,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,     0,     0,     0,     0,     0,     0,   -69,   -69,
       0,     0,     0,     0,     0,     0,   -70,   -70,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,     0,     0,     0,     0,     0,     0,
     -71,   -71,     0,     0,     0,     0,     0,     0,   -64,   -64,
     207,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,     0,
       0,     0,     0,   -53,     0,     0,     0,     0,     0,     0,
       0,   -55,   207,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
       0,     0,     0,     0,     0,   -54,     0,     0,     0,     0,
       0,     0,     0,   -56,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
       0,     0,     0,     0,     0,     0,     0,   -58,     0,     0,
       0,     0,     0,   -78,   -78,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,     0,     0,     0,     0,     0,   -79,   -79,     0,     0,
       0,     0,     0,     0,   -77,   -77,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,     0,     0,   -72,   -72,     0,
       0,     0,     0,     0,     0,   -57,   214,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,     0,     0,     0,   -63,   -63,
       0,     0,     0,     0,     0,     0,   -69,   -69,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,     0,     0,     0,     0,     0,   -70,
     -70,     0,     0,     0,     0,     0,     0,   -71,   -71,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,    88,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,     0,     0,     0,     0,     0,
     -64,   -64,     0,     0,     0,     0,     0,     0,   -53,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,    88,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,     0,     0,     0,
     -55,     0,     0,     0,     0,     0,     0,     0,   -54,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,
     -56,     0,     0,     0,     0,     0,     0,     0,   -58
};

static const yytype_int16 yycheck[] =
{
       8,   132,   198,    32,     0,   210,    15,    15,     4,   214,
       3,     4,     5,     6,    11,     8,     1,     6,    28,    28,
      28,   226,    15,    16,    17,     6,    28,    23,    28,    29,
     111,     0,    21,    30,    30,   231,    29,   118,    11,    47,
      29,   122,    46,    47,   111,     6,   111,    30,    29,   111,
      19,    20,   111,    30,   112,    28,   187,    26,     6,    29,
      21,   119,     6,    72,    72,     0,    74,    32,    29,     4,
      74,    75,     6,    81,    82,    83,    84,    85,    86,    87,
      88,    29,   111,    91,    11,    29,   291,     3,     4,     5,
       6,   296,     8,    30,    31,    29,    28,    29,    29,    15,
      16,    17,    32,    30,    31,   113,    28,   111,   112,    28,
      29,   119,     0,    29,    30,   119,   125,   125,    33,   128,
     128,     7,     8,     9,    10,    11,    12,    13,    14,   137,
      28,    19,    20,   137,     0,     6,    28,     0,    26,   147,
      30,    31,    28,    29,   153,   153,    30,     0,    34,     0,
      28,   159,   160,    19,    20,   159,    19,    20,    29,     0,
      26,   169,    30,    26,     0,   169,    19,    20,    19,    20,
     178,   229,    28,    26,    28,    26,    28,    47,    19,    20,
      19,    20,   186,    19,    20,    26,     9,    10,    11,    12,
      26,    30,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    30,   210,     0,    74,    28,   214,     6,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   298,   226,    89,
     228,    91,    19,    20,   228,   229,    28,    29,   309,    26,
      29,   298,   313,   298,   242,    28,   298,   245,   242,   298,
      30,   299,   309,   113,   309,    30,   313,   309,   313,   119,
     309,   313,   310,    30,   313,    10,    11,    10,    11,   267,
      19,    20,   270,   267,     1,    10,    11,   137,    30,   298,
       9,    10,    11,    12,    28,    30,    47,    30,    31,    28,
     309,    10,    11,   291,   313,    30,    31,    28,   296,   159,
      28,    30,    31,    29,   298,   299,    29,    68,    30,   169,
      30,    30,   310,    74,    30,   309,   310,    19,    20,   313,
      81,    82,    83,    84,    85,    86,    87,    88,    30,    28,
      91,    10,    11,     7,     8,     9,    10,    11,    12,    13,
      14,     8,     9,    10,    11,    12,    13,    14,   208,    28,
     210,    33,   113,    30,   214,    29,    30,    31,   119,    30,
      34,    30,    31,    30,   224,    30,   226,    30,   228,     8,
       9,    10,    11,    12,    13,    14,   137,    10,    11,    12,
      30,    31,   242,    10,    11,    12,   147,    10,    11,    28,
       3,     4,     5,     6,    28,     8,    28,    30,   159,   160,
      30,    28,    15,    16,    17,    28,    30,   267,   169,    22,
      30,    24,    25,    10,    11,    12,    29,   178,    30,    32,
      10,    11,    12,    30,    31,    19,    20,     9,    10,    11,
      12,   291,    26,    30,    31,    30,   296,    30,    28,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    30,   210,
     310,    47,    28,   214,    33,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    30,   226,    30,   228,    30,    31,
       7,     8,     9,    10,    11,    12,    13,    14,    74,    30,
      31,   242,    30,    31,   245,    81,    82,    83,    84,    85,
      86,    87,    88,    30,    31,    91,    30,    34,    30,     3,
       4,     5,     6,    28,     8,     4,   267,    30,    31,   270,
      30,    15,    16,    17,    92,    19,    20,   113,    22,    23,
      24,    25,    26,   119,    30,    29,    -1,    51,    32,    33,
     291,     9,    10,    11,    12,   296,    30,    31,    30,    31,
      -1,   137,    -1,    -1,     9,    10,    11,    12,    -1,   310,
      -1,   147,    30,    31,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,   159,   160,    30,    31,    15,    16,    17,
      -1,    19,    20,   169,    22,    23,    24,    25,    26,    -1,
      -1,    29,   178,    -1,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    28,   210,    -1,    47,    -1,   214,    34,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
     226,    -1,   228,    -1,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    74,    -1,    -1,   242,    -1,    -1,   245,
      81,    82,    83,    84,    85,    86,    87,    88,    30,    31,
      91,    -1,    34,    -1,     3,     4,     5,     6,    -1,     8,
      -1,   267,    -1,    -1,   270,    -1,    15,    16,    17,    -1,
      19,    20,   113,    22,    23,    24,    25,    26,   119,    -1,
      29,    -1,    -1,    32,    33,   291,     9,    10,    11,    12,
     296,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,     9,
      10,    11,    12,    -1,   310,    -1,   147,    30,    31,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,   159,   160,
      30,    31,    15,    16,    17,    -1,    19,    20,   169,    22,
      23,    24,    25,    26,    -1,    -1,    29,   178,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    28,   210,
      -1,    47,    -1,   214,    34,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,   226,    -1,   228,    -1,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    74,    -1,
      -1,   242,    -1,    -1,   245,    81,    82,    83,    84,    85,
      86,    87,    88,    30,    -1,    91,    -1,    34,    -1,     3,
       4,     5,     6,    -1,     8,    -1,   267,    -1,    -1,   270,
      -1,    15,    16,    17,    -1,    19,    20,   113,    22,    23,
      24,    25,    26,   119,    -1,    29,    -1,    -1,    32,    33,
     291,     9,    10,    11,    12,   296,    -1,    -1,    -1,    -1,
      -1,   137,    -1,    -1,     9,    10,    11,    12,    -1,   310,
      -1,   147,    30,    31,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,   159,   160,    30,    -1,    15,    16,    17,
      -1,    19,    20,   169,    22,    23,    24,    25,    26,    -1,
      -1,    29,   178,    -1,    32,    33,    -1,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,     9,    10,
      11,    12,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    30,   210,    -1,    47,    34,   214,    30,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
     226,    -1,   228,    -1,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    74,    -1,    -1,   242,    -1,    -1,   245,
      81,    82,    83,    84,    85,    86,    87,    88,    30,    31,
      91,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,   267,    -1,    -1,   270,    -1,    15,    16,    17,    -1,
      19,    20,   113,    22,    23,    24,    25,    26,   119,    -1,
      29,    -1,    -1,    32,    33,   291,     9,    10,    11,    12,
     296,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,     9,
      10,    11,    12,    -1,   310,    -1,   147,    30,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,   159,   160,
      30,    -1,    15,    16,    17,    -1,    19,    20,   169,    22,
      23,    24,    25,    26,    -1,    -1,    29,   178,    -1,    32,
      33,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,     9,    10,    11,    12,    -1,    15,    16,    17,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    47,   210,
      29,    30,    30,   214,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,   226,    -1,   228,     8,     9,
      10,    11,    12,    13,    14,    74,    -1,    -1,    47,    -1,
      -1,   242,    -1,    -1,   245,    84,    -1,    86,    87,    -1,
      30,    31,    91,    -1,    -1,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    74,   267,    -1,    -1,   270,
      -1,    10,    11,    12,   113,    -1,    85,    28,    29,    -1,
     119,    -1,    91,    34,    -1,    -1,    10,    11,    12,    -1,
     291,    30,    31,    -1,    -1,   296,    -1,    -1,   137,    -1,
       3,     4,     5,     6,   113,     8,    30,    -1,    -1,   310,
     119,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
     159,    -1,     3,     4,     5,     6,    29,     8,   137,    -1,
     169,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    -1,    -1,    29,    -1,
     159,    32,    33,    -1,    47,     9,    10,    11,    12,    -1,
     169,   200,   201,   202,   203,    -1,   205,   206,    -1,   208,
      -1,   210,    -1,    -1,    28,   214,    -1,   216,   217,   218,
     219,    74,   221,   222,    -1,   224,    -1,   226,    -1,   228,
      -1,   200,   201,   202,   203,   204,   205,   206,    91,   208,
      -1,   210,    -1,   242,    -1,   214,    -1,   216,   217,   218,
     219,   220,   221,   222,    -1,   224,    -1,   226,    -1,   228,
     113,     9,    10,    11,    12,    -1,   119,    -1,   267,    -1,
      -1,    -1,    -1,   242,     3,     4,     5,     6,    -1,     8,
      28,    -1,    -1,    -1,   137,    -1,    15,    16,    17,    -1,
      -1,    -1,   291,    22,    -1,    24,    25,   296,   267,    -1,
      29,    -1,    -1,    32,    -1,    -1,   159,    -1,    -1,    -1,
      47,   310,     3,     4,     5,     6,   169,     8,     3,     4,
       5,     6,   291,     8,    15,    16,    17,   296,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,    74,    29,    -1,
      -1,   310,    -1,    28,    29,    -1,    83,   200,   201,   202,
     203,    -1,   205,   206,    91,   208,    -1,   210,    -1,    -1,
      -1,   214,    -1,   216,   217,   218,   219,    -1,   221,   222,
      -1,   224,    -1,   226,    -1,   228,   113,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    47,    -1,    -1,   242,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
     137,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    28,    29,    74,   267,    -1,    -1,    34,    -1,    -1,
      -1,    82,   159,    29,    30,    31,    -1,    -1,    34,    -1,
      91,    -1,   169,    -1,     9,    10,    11,    12,   291,    -1,
      -1,    -1,    -1,   296,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,   113,    28,    -1,    -1,    -1,   310,   119,     9,
      10,    11,    12,   200,   201,   202,    -1,     9,    10,    11,
      12,   208,    -1,   210,    -1,    74,   137,   214,    28,   216,
     217,   218,    81,    -1,    -1,    47,    28,   224,    -1,   226,
      -1,   228,    91,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    -1,   169,    -1,
      -1,    -1,    74,    -1,   113,    -1,    -1,    -1,    -1,    -1,
     119,     7,     8,     9,    10,    11,    12,    13,    14,    91,
     267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   200,
     201,    -1,    -1,    29,    30,    31,    -1,   208,    34,   210,
      -1,   113,    -1,   214,   291,   216,   217,   119,    -1,   296,
     159,    -1,    -1,   224,    -1,   226,    -1,   228,    -1,    -1,
     169,    -1,    -1,   310,    -1,   137,    -1,    -1,    -1,    -1,
      -1,   242,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,   200,    -1,    -1,    28,    29,   267,   169,    -1,   208,
      34,   210,    -1,    -1,    -1,   214,    -1,   216,    -1,     3,
       4,     5,     6,    -1,     8,   224,    -1,   226,    -1,   228,
     291,    15,    16,    17,    -1,   296,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   242,    -1,    29,   208,    -1,   210,   310,
      -1,    -1,   214,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,   224,    -1,   226,    -1,   228,    -1,   267,    -1,
       3,     4,     5,     6,    -1,     8,    29,    30,    31,    -1,
     242,    34,    15,    16,    17,    -1,     3,     4,     5,     6,
      -1,     8,   291,    -1,    -1,    -1,    29,   296,    15,    16,
      17,     3,     4,     5,     6,   267,     8,    -1,    -1,    -1,
      -1,   310,    29,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,   291,
      32,    33,    -1,    -1,   296,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,   310,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    -1,    32,    33,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    -1,    32,    33,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    -1,
      24,    25,    26,    -1,    -1,    29,    -1,    -1,    32,    33,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      -1,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    32,
      33,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    -1,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
      32,    33,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    -1,    24,    25,    26,    -1,    -1,    29,    -1,
      -1,    32,    33,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,    29,
      -1,    -1,    32,    33,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,
      29,    -1,    -1,    32,    33,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    -1,    24,    25,    26,    -1,
      -1,    29,    -1,    -1,    32,    33,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    -1,    24,    25,    26,
      -1,    -1,    29,    -1,    -1,    32,    33,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    29,    -1,    -1,    32,    33,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    -1,    24,
      25,    26,    -1,    -1,    29,    -1,    -1,    32,    33,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    -1,
      24,    25,    26,    -1,    -1,    29,    -1,    -1,    32,    33,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      -1,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    32,
      33,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    -1,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
      32,    33,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    -1,    24,    25,    26,    -1,    -1,    29,    -1,
      -1,    32,    33,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,    29,
      -1,    -1,    32,    33,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,
      29,    -1,    -1,    32,    33,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    -1,    24,    25,    26,    -1,
      -1,    29,    -1,    -1,    32,    33,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    -1,    24,    25,    26,
      -1,    -1,    29,    -1,    -1,    32,    33,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    29,    -1,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    -1,    -1,    34,    -1,    -1,    29,    30,
      31,    -1,    -1,    34,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    34,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    34,    -1,    -1,
      29,    30,    31,    -1,    -1,    34,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    28,    29,    -1,    -1,    -1,
      -1,    34,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    34,    -1,    28,    29,    -1,
      -1,    -1,    -1,    34,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    34,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    34,    -1,    -1,
      29,    30,    -1,    -1,    -1,    34,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    34,    -1,    -1,    29,    30,    -1,    -1,
      -1,    34,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,
      -1,    -1,    29,    30,    -1,    -1,    -1,    34,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    34,    -1,    -1,    29,    30,
      -1,    -1,    -1,    34,     3,     4,     5,     6,    -1,     8,
       3,     4,     5,     6,    -1,     8,    15,    16,    17,    -1,
      -1,    -1,    15,    16,    17,    -1,     3,     4,     5,     6,
      29,     8,     3,     4,     5,     6,    29,     8,    15,    16,
      17,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    28,    29,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    28,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    20,    26,    36,    37,    38,    40,    74,    21,
      21,     1,     0,    37,     6,    29,    52,    73,    28,    52,
      29,    39,    30,    41,    28,    43,    44,    45,    74,    30,
      31,    52,    42,    45,    32,    46,    47,     3,     4,     5,
       8,    15,    16,    17,    22,    24,    25,    29,    38,    46,
      48,    49,    50,    51,    53,    54,    55,    56,    57,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      72,    73,    74,    75,    29,    29,    57,    57,    33,    50,
      28,    11,    10,    12,     9,     8,    13,    14,     7,    34,
      67,    29,    52,    57,    57,    58,    28,    30,    61,    67,
      62,    63,    64,    66,    64,    64,    67,    59,    59,    70,
      71,    30,    28,    31,    30,    51,    58,    59,    23,    28,
      51,    58,    30,    51,     6,    29,    73,     6,    29,    73,
       6,    26,    32,     3,     4,     5,     6,    29,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    72,
      73,    75,     6,    29,    73,     3,     4,     5,     6,    29,
      68,    69,    72,    73,    75,     3,     4,     5,     6,    29,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      72,    73,    75,    39,    22,    24,    25,    32,    46,    53,
      54,    55,    56,    57,    57,    52,    52,     1,    47,    57,
      11,    10,    12,     9,     8,    13,    14,     7,    34,    67,
      29,    52,    57,    67,    29,    57,    11,    10,    12,     9,
       8,    13,    14,     7,    34,    67,    29,    28,    29,    29,
      57,    47,    28,    30,    30,    28,    48,    30,     3,     4,
       5,     6,    29,    61,    67,    68,    69,    72,    73,    75,
      62,    63,    64,    66,    64,    64,    67,    59,    71,    30,
      30,    71,    30,     3,     4,     5,     6,    29,    61,    67,
      68,    69,    72,    73,    75,    62,    63,    64,    66,    64,
      64,    67,    59,    71,    57,    58,    28,    48,    33,    57,
      67,    29,    30,    30,    57,    67,    29,    30,    30,    28,
      33,    30,    71,    30,    71,    51,    58,    30,    30,    23,
      28,    51,    58,    30,    51
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
      72,    72,    73,    74,    74,    74,    74,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     4,     3,     0,
       0,     8,     0,     1,     3,     1,     2,     0,     4,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     5,     7,     3,     9,     1,     0,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     4,     1,     3,     1,     0,     1,
       1,     3,     1,     1,     1,     2,     2,     1,     1,     1
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
    case YYSYMBOL_NAME: /* NAME  */
#line 69 "src/bison/math.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2024 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2030 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2036 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2042 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2048 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2054 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2060 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2066 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2072 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2078 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2084 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2090 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2096 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2102 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2108 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2114 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2120 "src/bison/grammar.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2126 "src/bison/grammar.c"
        break;

    case YYSYMBOL_39_1: /* @1  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2132 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2138 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_2: /* @2  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2144 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2150 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2156 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2162 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2168 "src/bison/grammar.c"
        break;

    case YYSYMBOL_declarator: /* declarator  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2174 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2180 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2186 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2192 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2198 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2204 "src/bison/grammar.c"
        break;

    case YYSYMBOL_58_expression_opt: /* expression.opt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2210 "src/bison/grammar.c"
        break;

    case YYSYMBOL_assign_expr: /* assign_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2216 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2222 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2228 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2234 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2240 "src/bison/grammar.c"
        break;

    case YYSYMBOL_dl_dg_expr: /* dl_dg_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2246 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2252 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2258 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2264 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2270 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2276 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2282 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2288 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2294 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2300 "src/bison/grammar.c"
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
#line 74 "src/bison/math.y"
                                { list_push(&root->children, (yyvsp[0].ast)); }
#line 2571 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 75 "src/bison/math.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 2577 "src/bison/grammar.c"
    break;

  case 6: /* @1: %empty  */
#line 82 "src/bison/math.y"
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
#line 2599 "src/bison/grammar.c"
    break;

  case 7: /* declaration: type declarator @1 ';'  */
#line 98 "src/bison/math.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 2607 "src/bison/grammar.c"
    break;

  case 8: /* declaration: LET error ';'  */
#line 101 "src/bison/math.y"
                    {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 2618 "src/bison/grammar.c"
    break;

  case 9: /* @2: %empty  */
#line 109 "src/bison/math.y"
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
#line 2653 "src/bison/grammar.c"
    break;

  case 10: /* $@3: %empty  */
#line 138 "src/bison/math.y"
                         {
        context_push_scope(current_context);
        LIST_FOR_EACH((yyvsp[-1].list), {
            // symbol_update_context(((AST *)__IT__->data)->value.symref->symbol, current_context);
            context_declare_variable(current_context, ((AST *)__IT__->data)->value.symref);
        });
        // hack to save the scope of params and append to the scope of the body
        {
            params_scope = scope_init_copy(stack_peek(&current_context->scopes));
            stack_pop(&current_context->scopes, free_scope_cb);
        }
    }
#line 2670 "src/bison/grammar.c"
    break;

  case 11: /* func_declaration: type declarator '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 149 "src/bison/math.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 2679 "src/bison/grammar.c"
    break;

  case 12: /* param_list.opt: %empty  */
#line 155 "src/bison/math.y"
                       { (yyval.list) = NULL; }
#line 2685 "src/bison/grammar.c"
    break;

  case 14: /* params_list: params_list ',' param_decl  */
#line 159 "src/bison/math.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2691 "src/bison/grammar.c"
    break;

  case 15: /* params_list: param_decl  */
#line 160 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2697 "src/bison/grammar.c"
    break;

  case 16: /* param_decl: type declarator  */
#line 163 "src/bison/math.y"
                            {
        symbol_update_context((yyvsp[0].ast)->value.symref->symbol, current_context);
        symbol_update_type((yyvsp[0].ast)->value.symref->symbol, symbol_type_from_str((yyvsp[-1].pchar)));
        (yyval.ast) = ast_symref_init(symbol_init_copy((yyvsp[0].ast)->value.symref->symbol));
        ast_free((yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2709 "src/bison/grammar.c"
    break;

  case 17: /* $@4: %empty  */
#line 172 "src/bison/math.y"
                   {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        // hack to update the current scope 
        if (params_scope) {
            stack_push(&current_context->scopes, params_scope);
            current_context->current_scope = ((Scope *)stack_peek(&current_context->scopes))->index;
            params_scope = NULL;
        } else {
            context_push_scope(current_context);
        }
    }
#line 2725 "src/bison/grammar.c"
    break;

  case 18: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 182 "src/bison/math.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            current_context->current_scope = ((Scope *)parent_stacknode_ref->data)->index;
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 2738 "src/bison/grammar.c"
    break;

  case 19: /* block_item_list.opt: block_item_list  */
#line 192 "src/bison/math.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 2744 "src/bison/grammar.c"
    break;

  case 20: /* block_item_list.opt: %empty  */
#line 193 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2750 "src/bison/grammar.c"
    break;

  case 21: /* block_item_list: block_item_list block_item  */
#line 196 "src/bison/math.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2756 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list: block_item  */
#line 197 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2762 "src/bison/grammar.c"
    break;

  case 31: /* declarator: '(' declarator ')'  */
#line 212 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2768 "src/bison/grammar.c"
    break;

  case 32: /* expr_stmt: expression ';'  */
#line 215 "src/bison/math.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2774 "src/bison/grammar.c"
    break;

  case 33: /* cond_stmt: IF '(' expression ')' statement  */
#line 218 "src/bison/math.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 2782 "src/bison/grammar.c"
    break;

  case 34: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 221 "src/bison/math.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2790 "src/bison/grammar.c"
    break;

  case 35: /* jmp_stmt: RETURN expression ';'  */
#line 226 "src/bison/math.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 2796 "src/bison/grammar.c"
    break;

  case 36: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 229 "src/bison/math.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2804 "src/bison/grammar.c"
    break;

  case 38: /* expression.opt: %empty  */
#line 237 "src/bison/math.y"
                       { (yyval.ast) = NULL; }
#line 2810 "src/bison/grammar.c"
    break;

  case 41: /* assign_expr: unary_expr '=' assign_expr  */
#line 242 "src/bison/math.y"
                                 { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2816 "src/bison/grammar.c"
    break;

  case 43: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 246 "src/bison/math.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2825 "src/bison/grammar.c"
    break;

  case 45: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 253 "src/bison/math.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2834 "src/bison/grammar.c"
    break;

  case 47: /* eq_expr: eq_expr EQ rel_expr  */
#line 260 "src/bison/math.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2843 "src/bison/grammar.c"
    break;

  case 49: /* rel_expr: rel_expr REL dl_dg_expr  */
#line 267 "src/bison/math.y"
                              {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2852 "src/bison/grammar.c"
    break;

  case 51: /* dl_dg_expr: add_expr DL_DG dl_dg_expr  */
#line 274 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2861 "src/bison/grammar.c"
    break;

  case 52: /* dl_dg_expr: add_expr COLON dl_dg_expr  */
#line 278 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2870 "src/bison/grammar.c"
    break;

  case 54: /* add_expr: add_expr ADD mult_expr  */
#line 285 "src/bison/math.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2879 "src/bison/grammar.c"
    break;

  case 56: /* mult_expr: mult_expr MULT unary_expr  */
#line 292 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2888 "src/bison/grammar.c"
    break;

  case 58: /* unary_expr: unary_ops unary_expr  */
#line 299 "src/bison/math.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2897 "src/bison/grammar.c"
    break;

  case 64: /* postfix_expr: postfix_expr '(' arg_expr_list.opt ')'  */
#line 312 "src/bison/math.y"
                                             {
        (yyval.ast) = ast_funcall_init((yyvsp[-3].ast), ast_params_init((yyvsp[-1].list)));
    }
#line 2905 "src/bison/grammar.c"
    break;

  case 65: /* arg_expr_list: assign_expr  */
#line 317 "src/bison/math.y"
                           { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2911 "src/bison/grammar.c"
    break;

  case 66: /* arg_expr_list: arg_expr_list ',' assign_expr  */
#line 318 "src/bison/math.y"
                                    { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2917 "src/bison/grammar.c"
    break;

  case 68: /* arg_expr_list.opt: %empty  */
#line 322 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2923 "src/bison/grammar.c"
    break;

  case 69: /* primary_expr: id  */
#line 325 "src/bison/math.y"
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
#line 2941 "src/bison/grammar.c"
    break;

  case 71: /* primary_expr: '(' expression ')'  */
#line 339 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2947 "src/bison/grammar.c"
    break;

  case 72: /* id: NAME  */
#line 342 "src/bison/math.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 2953 "src/bison/grammar.c"
    break;

  case 75: /* type: INT LIST  */
#line 347 "src/bison/math.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 2965 "src/bison/grammar.c"
    break;

  case 76: /* type: FLOAT LIST  */
#line 354 "src/bison/math.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 2977 "src/bison/grammar.c"
    break;

  case 77: /* constant: NUMBER_REAL  */
#line 363 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 2983 "src/bison/grammar.c"
    break;

  case 78: /* constant: NUMBER_INT  */
#line 364 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 2989 "src/bison/grammar.c"
    break;

  case 79: /* constant: NIL  */
#line 365 "src/bison/math.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 2995 "src/bison/grammar.c"
    break;


#line 2999 "src/bison/grammar.c"

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

#line 368 "src/bison/math.y"


void yyerror(const char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    if (s) CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
    ++errors_count;
}
