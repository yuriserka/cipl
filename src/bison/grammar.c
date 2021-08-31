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
  YYSYMBOL_constant = 75,                  /* constant  */
  YYSYMBOL_string_literal = 76             /* string_literal  */
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
#define YYLAST   3651

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  327

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
     338,   339,   340,   343,   346,   347,   348,   355,   364,   365,
     366,   369
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
  "id", "type", "constant", "string_literal", YY_NULLPTR
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

#define YYPACT_NINF (-213)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     164,     5,   112,     8,    12,    29,    43,    67,    13,    41,
      65,    17,  -213,   108,   -12,    66,   227,   243,   110,    24,
     135,    31,   278,   264,   167,    34,   295,   332,    82,    51,
     296,   334,    77,   342,  1864,   231,  1902,    92,  1356,  1571,
    2980,  2996,  3002,  3018,  2500,    32,    44,  3024,  3040,  1933,
    1964,    79,  1995,  2026,  2057,  2088,  2119,  2150,  2181,    70,
      95,     2,   224,    46,  1019,  1098,  1708,  3579,  1756,  3024,
    2528,  2536,  2564,    86,  2572,  2600,  3040,  1637,    97,   105,
     285,  2212,  2243,  3046,  3046,  3046,  3046,  3046,  3046,  3046,
    3046,  3024,  2924,   260,   109,   113,   125,   141,  2274,  2608,
     302,  3589,   365,  1118,  1302,  3601,  1385,  1418,  3611,   171,
     360,   377,   133,   523,  1637,  3062,  2636,   156,   201,   381,
     682,  1845,  2305,   202,   682,  2336,   207,    66,   209,   395,
      66,   476,  2644,   241,  1864,  2672,  2680,  2708,  2716,  2744,
    3040,   237,    16,   128,   524,   136,   185,  1368,  3379,  2932,
    3040,  2752,  2780,  2788,  2816,  2824,   246,    66,   263,  3441,
    3451,  3464,  3474,  3487,  3040,  3046,  3497,  3510,  3520,  3533,
    3543,   487,   646,   805,   833,   964,  3040,   120,   298,   249,
     462,   493,  1529,  3246,  2852,  3062,   992,  1124,  1152,  1392,
    2456,   265,   240,   259,  3024,  1864,   328,   363,   398,   557,
     716,   271,   272,   305,   307,   314,  1902,   326,  3068,  3068,
    3068,  3068,  3068,  3068,  3068,  3068,  3040,  2960,   260,   340,
     364,  3623,   260,   367,  3084,  3084,  3084,  3084,  3084,  3084,
    3084,  3084,  3062,  2860,   260,  2367,  3040,  1637,   330,  1902,
     875,   370,   489,  2398,   372,  2888,   425,   584,   743,   902,
    1061,  3040,   181,  3393,  3068,  1459,  3307,  3321,  3331,  3345,
     638,   329,   847,  3403,   859,  1006,  3417,   379,   399,   400,
    3556,   410,  2464,  3096,  3107,  3121,  3132,  3146,  3040,   540,
    3257,  3084,  3157,  3171,  3182,  3196,  3207,   479,   621,   652,
    3271,   780,   939,  3282,   536,   421,   423,   429,  1034,   434,
    2429,   445,  3427,   260,  2896,  3566,   454,  3296,   260,  2492,
     523,  1637,  1203,  3355,   457,  3221,   481,  1271,   485,  3369,
    3232,   523,  1845,  1432,   492,   523,  1804
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,   521,    14,   436,  -213,  -213,  -213,  -213,  -213,
     502,   -29,  -129,  -202,  -213,   494,   -85,   -13,   -80,   -77,
     -72,   -63,   -24,  -113,  1510,  1622,  1563,  1472,  1451,  1109,
    1299,  1268,   234,   393,   552,  -213,  -212,   711,    -8,    21,
     870,  1029
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,    49,    21,     7,    23,    32,    25,    26,
      27,    50,    36,    51,    52,    53,    54,    16,    55,    56,
      57,    58,    59,    97,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,   111,   112,    71,    72,    73,
      74,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,   118,    19,    35,   244,   206,   268,   128,   123,    11,
     271,   -74,    12,    83,     6,    31,   -73,   -73,     6,    14,
     131,     8,   295,    78,    79,     8,     9,   208,   117,    -3,
     -40,     1,     2,   197,   -74,   122,   198,   299,     3,   125,
     153,   199,    15,    -5,    28,    18,   -40,   -76,    -3,    -3,
     200,    28,    95,    96,    22,    -3,   -44,   -44,    85,    24,
      94,    76,    -5,    -5,    29,   158,   239,    -4,   153,    -5,
     -76,   -77,   126,    77,   -44,   168,   168,   168,   168,   168,
     168,   168,   168,   -10,   196,   188,    -4,    -4,   129,   201,
      96,   314,   156,    -4,   -77,   127,   316,   202,    82,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   188,    -2,    34,
      -8,   130,    80,   153,   203,   157,   207,   204,   -75,   128,
     -79,   -79,   128,   -37,   297,    98,   -79,    -2,    -2,    -8,
      -8,   224,   153,    10,    -2,    99,    -8,    -6,   209,   -42,
     220,   -75,   153,   113,   219,   211,   -46,   -46,   -46,   128,
     -40,   -40,   223,   -39,    -9,    -9,   153,   168,   -42,   -33,
     -33,   -33,   -33,   116,   -33,    -9,   -46,    -7,   153,   114,
     238,   -33,   -33,   -33,   -33,   -33,   -33,   188,   -33,   120,
     -33,   -33,   -33,     1,     2,   -33,    -7,    -7,   -33,   -33,
       3,   209,   -43,    -7,   -48,   -48,   -48,   -48,   318,   -41,
     257,   257,   257,   257,   257,   257,   257,   257,   153,   324,
     188,   -43,   296,    96,   188,   -48,   284,   284,   284,   284,
     284,   284,   284,   284,   188,   317,   188,   301,   153,   121,
     197,   -11,   124,   198,    84,   -42,   323,   -73,   199,   -30,
     326,   197,   205,   153,   198,   197,   257,   200,   198,   199,
     -11,   -11,   -42,   199,   306,    -6,    20,   -11,   200,   -44,
     -44,   226,   200,   171,   172,   173,   174,   -37,    40,   236,
     153,   -30,   -30,   284,   -73,    41,    42,    43,   175,   -44,
     -44,   196,   149,     1,     2,   -18,   201,    96,   237,   176,
     -68,   -30,   196,   235,   -12,   188,   196,   201,   202,   240,
     188,   201,   -39,    92,   -18,   -18,   -31,   -31,   225,   -42,
     149,   -18,    84,   -43,   153,     1,     2,   101,   101,   101,
     101,   101,   101,   101,   108,   -13,    30,   184,   -42,   -42,
     -43,   -26,   -26,   -26,   -26,   241,   -26,   242,   211,   -47,
     -47,   -47,   243,   -26,   -26,   -26,   -26,   -26,   -26,   184,
     -26,   -26,   -26,   -26,   -26,   149,   245,   -26,   298,   -47,
     -26,   -26,   -15,   -15,   -16,   -16,   -25,   -25,   -25,   -25,
     269,   -25,   -14,   -14,   149,   -45,   -45,    85,   -25,   -25,
     -25,   -25,   -25,   -25,   217,   -25,   -25,   -25,   -25,   -25,
     -65,   -65,   -25,   -45,   270,   -25,   -25,   272,   149,   221,
     -31,   -27,   -27,   -27,   -27,   300,   -27,   -67,   115,   -41,
     149,   -66,   -66,   -27,   -27,   -27,   -27,   -27,   -27,   233,
     -27,   -27,   -27,   -27,   -27,   -73,   -73,   -27,   -31,   304,
     -27,   -27,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     305,   150,   253,   253,   253,   253,   253,   253,   253,   266,
     149,   309,   184,   310,   -79,   -79,   184,   311,   280,   280,
     280,   280,   280,   280,   280,   293,   184,   312,   184,   150,
     149,   227,   -46,   -46,   -46,   313,   165,   165,   165,   165,
     165,   165,   165,   165,   315,   149,   185,   319,   302,   -45,
     -45,   226,   -46,   -46,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -48,   -48,   -48,   -48,   -30,   -30,   185,   -45,
     -45,   320,   149,   322,   150,   307,   -79,   -79,   -79,   -31,
     -31,   -79,   325,   -48,   -48,    13,    37,    38,    39,   132,
     191,    40,    33,   150,   -44,   -44,   210,   184,    41,    42,
      43,    44,   184,   150,     0,   192,    81,   193,   194,     0,
     225,   -43,    48,     0,   -44,   195,   149,   150,   165,     0,
     -28,   -28,   -28,   -28,     0,   -28,   -41,   -41,     0,   150,
     -43,   -43,   -28,   -28,   -28,   -28,   -28,   -28,   185,   -28,
     -28,   -28,   -28,   -28,     0,     0,   -28,     0,     0,   -28,
     -28,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,
     151,   254,   254,   254,   254,   254,   254,   254,   254,   150,
       0,   185,     0,   -80,   -80,   185,     0,   281,   281,   281,
     281,   281,   281,   281,   281,   185,     0,   185,   151,   150,
     227,   -47,   -47,   -47,     0,   166,   166,   166,   166,   166,
     166,   166,   166,     0,   150,   186,     0,   254,   -45,   -45,
     210,   -47,   -47,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -49,   -49,   -49,   -49,     0,     0,   186,   -45,     0,
       0,   150,     0,   151,   281,   -80,   -80,   -80,     0,     0,
     -80,     0,   -49,   -49,     0,    37,    38,    39,   132,     0,
      40,     0,   151,     0,     0,     0,   185,    41,    42,    43,
      44,   185,   151,     0,    45,     0,    46,    47,     0,     0,
       0,    48,     0,     0,   134,   150,   151,   166,     0,   -29,
     -29,   -29,   -29,     0,   -29,     0,     0,     0,   151,     0,
       0,   -29,   -29,   -29,   -29,   -29,   -29,   186,   -29,   -29,
     -29,   -29,   -29,     0,     0,   -29,     0,     0,   -29,   -29,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,   152,
     255,   255,   255,   255,   255,   255,   255,   255,   151,     0,
     186,     0,   -78,   -78,   186,     0,   282,   282,   282,   282,
     282,   282,   282,   282,   186,     0,   186,   152,   151,   -52,
     -52,   -52,   -52,     0,   167,   167,   167,   167,   167,   167,
     167,   167,     0,   151,   187,     0,   255,     0,     0,     0,
     -52,   -52,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
       0,     0,     0,     0,     0,     0,   187,     0,     0,     0,
     151,     0,   152,   282,   -78,   -78,   -78,     0,     0,   -78,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
       0,   152,     0,     0,     0,   186,   -49,   -49,   -49,   -49,
     186,   152,   -73,   -73,   -73,     0,     0,   -73,   -52,   -52,
     -52,   -52,     0,     0,   151,   152,   167,   -49,   -32,   -32,
     -32,   -32,     0,   -32,     0,     0,     0,   152,     0,   -52,
     -32,   -32,   -32,   -32,   -32,   -32,   187,   -32,   -32,   -32,
     -32,   -32,     0,     0,   -32,     0,     0,   -32,   -32,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,   154,   256,
     256,   256,   256,   256,   256,   256,   256,   152,     0,   187,
       0,   -73,   -73,   187,     0,   283,   283,   283,   283,   283,
     283,   283,   283,   187,     0,   187,   154,   152,   -51,   -51,
     -51,   -51,     0,   169,   169,   169,   169,   169,   169,   169,
     169,     0,   152,   189,     0,   256,     0,     0,     0,   -51,
     -51,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,     0,
       0,     0,     0,     0,     0,   189,     0,     0,     0,   152,
       0,   154,   283,   -81,   -81,   -81,     0,     0,   -81,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,
     154,     0,     0,     0,   187,   -51,   -51,   -51,   -51,   187,
     154,   234,   -57,   -57,     0,     0,   -57,     0,    86,   -46,
     -46,   -46,     0,   152,   154,   169,   -51,   -35,   -35,   -35,
     -35,     0,   -35,     0,     0,     0,   154,   -46,     0,   -35,
     -35,   -35,   -35,   -35,   -35,   189,   -35,   -35,   -35,   -35,
     -35,     0,     0,   -35,     0,     0,   -35,   -35,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,     0,   155,   258,   258,
     258,   258,   258,   258,   258,   258,   154,     0,   189,     0,
     -81,   -81,   189,     0,   285,   285,   285,   285,   285,   285,
     285,   285,   189,     0,   189,   155,   154,   -48,   -48,   -48,
     -48,     0,   170,   170,   170,   170,   170,   170,   170,   170,
       0,   154,   190,     0,   258,     0,   -48,    86,   -47,   -47,
     -47,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,     0,
       0,     0,     0,     0,   190,     0,   -47,     0,   154,     0,
     155,   285,     0,   -63,   -63,   -63,     0,   146,   -63,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,   155,
       0,     0,     0,   189,     0,     0,     0,     0,   189,   155,
       0,   -69,   -69,   -69,     0,   146,   -69,     0,     0,     0,
       0,     0,   154,   155,   170,   104,     0,   106,   107,     0,
       0,     0,   181,     0,     0,   155,   -18,   -18,   -18,   -18,
       0,   -18,     0,     0,   190,     0,     0,     0,   -18,   -18,
     -18,   -18,   -18,   -18,   181,   -18,   -18,   -18,   -18,   -18,
     146,     0,   -18,     0,     0,   -18,   -18,   259,   259,   259,
     259,   259,   259,   259,   259,   155,     0,   190,     0,   146,
       0,   190,     0,   286,   286,   286,   286,   286,   286,   286,
     286,   190,     0,   190,     0,   155,     0,     0,     0,     0,
       0,     0,     0,   146,   -33,   -33,   -33,   -33,     0,   -33,
     155,     0,     0,   259,     0,   146,   -33,   -33,   -33,   -33,
     -33,   -33,     0,   -33,   321,   -33,   -33,   -33,     0,     0,
     -33,     0,     0,   -33,   -33,     0,     0,   155,     0,     0,
     286,   -49,   -49,   -49,   -49,     0,   148,   146,   146,   146,
     262,     0,   264,   265,     0,   146,     0,   181,     0,     0,
     -49,   181,   190,   181,   181,   181,   289,   190,   291,   292,
       0,   181,     0,   181,   148,   146,     0,   147,     0,     0,
       0,   155,     0,     0,     0,   105,     0,     0,     0,     0,
     146,   183,     0,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,     0,     0,     0,     0,   147,   212,   -50,   -50,   -50,
     -50,   213,   214,   183,   -80,   -80,     0,   146,     0,   148,
     -80,     0,   182,     0,   -52,   -52,   -52,   -52,   -50,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,     0,   148,     0,
       0,     0,   181,   -52,   182,     0,     0,   181,     0,     0,
     147,   -70,   -70,   -70,     0,     0,   -70,   -51,   -51,   -51,
     -51,   146,   148,     0,     0,   -34,   -34,   -34,   -34,   147,
     -34,     0,     0,     0,   148,     0,   -51,   -34,   -34,   -34,
     -34,   -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,     0,
       0,   -34,     0,   147,   -34,   -34,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,     0,   147,   148,   148,   148,   148,
     263,   148,   148,     0,   148,     0,   183,     0,   303,   -57,
     183,     0,   183,   183,   183,   183,   290,   183,   183,   145,
     183,     0,   183,     0,   148,     0,     0,   147,   147,   147,
     147,     0,   147,   147,     0,   147,     0,   182,     0,   148,
     144,   182,     0,   182,   182,   182,   182,   145,   182,   182,
       0,   182,     0,   182,     0,   147,   103,   228,   -50,   -50,
     -50,   -50,   229,   230,   180,     0,   148,     0,   144,     0,
     147,     0,     0,     0,     0,     0,   102,     0,   141,   -50,
     -50,     0,     0,     0,     0,   179,   180,     0,     0,     0,
       0,   183,   145,     0,     0,     0,   183,   147,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   141,   179,     0,     0,
     148,   145,     0,   144,     0,     0,     0,     0,     0,   -78,
     -78,   109,   182,   110,     0,   -78,     0,   182,     0,     0,
       0,   143,   144,     0,     0,   145,     0,     0,     0,     0,
       0,   147,     0,     0,     0,   119,     0,   145,     0,     0,
       0,   141,     0,     0,     0,     0,   144,     0,     0,   143,
      37,    38,    39,   132,     0,    40,   100,     0,   144,     0,
     141,     0,    41,    42,    43,    44,   178,     0,     0,   145,
     145,   261,     0,     0,     0,   -38,    48,   145,     0,   180,
     142,     0,     0,   180,   141,   180,   180,   288,   178,     0,
     144,   260,     0,   180,   143,   180,   141,   145,   144,     0,
     179,     0,     0,     0,   179,     0,   179,   287,   142,     0,
       0,     0,   145,   143,   179,     0,   179,     0,   144,     0,
       0,     0,     0,     0,     0,   177,    87,   -50,   -50,   -50,
     -50,    88,    89,   144,     0,     0,   267,   143,   110,   145,
       0,     0,   110,     0,     0,     0,   -50,   177,     0,   143,
       0,     0,   294,   142,   110,     0,   141,     0,     0,     0,
     144,     0,     0,     0,   180,     0,     0,     0,     0,   180,
       0,   141,   142,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   252,     0,   145,     0,   179,     0,     0,     0,   143,
     179,   178,     0,     0,   -55,   178,   142,   279,   141,     0,
      91,     0,     0,     0,   144,   178,     0,   178,   142,   143,
       0,     0,     0,     0,     0,     0,     0,   -36,   -36,   -36,
     -36,     0,   -36,   110,   143,     0,     0,     0,   110,   -36,
     -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,   -36,
     -36,     0,   141,   -36,     0,     0,   -36,   -36,   142,     0,
     177,   143,     0,     0,   177,     0,     0,     0,   135,   136,
     137,   138,     0,    40,   177,     0,   177,     0,   142,     0,
      41,    42,    43,   139,     0,     0,   178,   -17,   -17,   -17,
     -17,   178,   -17,   142,   140,   -38,     0,     0,     0,   -17,
     -17,   -17,   -17,   -17,   -17,   143,   -17,     0,   -17,   -17,
     -17,     0,     0,   -17,     0,     0,   -17,   -17,     0,     0,
     142,     0,     0,     0,     0,    37,    38,    39,   132,     0,
      40,     0,     0,     0,     0,     0,     0,    41,    42,    43,
      44,     1,     2,     0,    45,   177,    46,    47,   133,     0,
     177,    48,     0,     0,   134,   -20,   -23,   -23,   -23,   -23,
       0,   -23,     0,     0,   142,     0,     0,     0,   -23,   -23,
     -23,   -23,   -23,   -23,     0,   -23,     0,   -23,   -23,   -23,
       0,     0,   -23,     0,     0,   -23,   -23,   -26,   -26,   -26,
     -26,     0,   -26,     0,     0,     0,     0,     0,     0,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,     0,   -26,   -26,
     -26,     0,     0,   -26,     0,     0,   -26,   -26,    37,    38,
      39,   132,     0,    40,     0,     0,     0,     0,     0,     0,
      41,    42,    43,    44,     1,     2,     0,    45,     0,    46,
      47,   133,     0,     0,    48,     0,     0,   134,   -19,   -22,
     -22,   -22,   -22,     0,   -22,     0,     0,     0,     0,     0,
       0,   -22,   -22,   -22,   -22,   -22,   -22,     0,   -22,     0,
     -22,   -22,   -22,     0,     0,   -22,     0,     0,   -22,   -22,
     -24,   -24,   -24,   -24,     0,   -24,     0,     0,     0,     0,
       0,     0,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,
       0,   -24,   -24,   -24,     0,     0,   -24,     0,     0,   -24,
     -24,   -25,   -25,   -25,   -25,     0,   -25,     0,     0,     0,
       0,     0,     0,   -25,   -25,   -25,   -25,   -25,   -25,     0,
     -25,     0,   -25,   -25,   -25,     0,     0,   -25,     0,     0,
     -25,   -25,   -27,   -27,   -27,   -27,     0,   -27,     0,     0,
       0,     0,     0,     0,   -27,   -27,   -27,   -27,   -27,   -27,
       0,   -27,     0,   -27,   -27,   -27,     0,     0,   -27,     0,
       0,   -27,   -27,   -28,   -28,   -28,   -28,     0,   -28,     0,
       0,     0,     0,     0,     0,   -28,   -28,   -28,   -28,   -28,
     -28,     0,   -28,     0,   -28,   -28,   -28,     0,     0,   -28,
       0,     0,   -28,   -28,   -29,   -29,   -29,   -29,     0,   -29,
       0,     0,     0,     0,     0,     0,   -29,   -29,   -29,   -29,
     -29,   -29,     0,   -29,     0,   -29,   -29,   -29,     0,     0,
     -29,     0,     0,   -29,   -29,   -21,   -21,   -21,   -21,     0,
     -21,     0,     0,     0,     0,     0,     0,   -21,   -21,   -21,
     -21,   -21,   -21,     0,   -21,     0,   -21,   -21,   -21,     0,
       0,   -21,     0,     0,   -21,   -21,   -32,   -32,   -32,   -32,
       0,   -32,     0,     0,     0,     0,     0,     0,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,     0,   -32,   -32,   -32,
       0,     0,   -32,     0,     0,   -32,   -32,   -35,   -35,   -35,
     -35,     0,   -35,     0,     0,     0,     0,     0,     0,   -35,
     -35,   -35,   -35,   -35,   -35,     0,   -35,     0,   -35,   -35,
     -35,     0,     0,   -35,     0,     0,   -35,   -35,   -34,   -34,
     -34,   -34,     0,   -34,     0,     0,     0,     0,     0,     0,
     -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,     0,   -34,
     -34,   -34,     0,     0,   -34,     0,     0,   -34,   -34,   -36,
     -36,   -36,   -36,     0,   -36,     0,     0,     0,     0,     0,
       0,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,     0,
     -36,   -36,   -36,     0,     0,   -36,     0,     0,   -36,   -36,
      -7,    -7,    -7,    -7,     0,    -7,     0,     0,     0,     0,
       0,     0,    -7,    -7,    -7,    -7,    -7,    -7,     0,    -7,
       0,    -7,    -7,    -7,     0,     0,    -7,     0,     0,    -7,
      -7,    -8,    -8,    -8,    -8,     0,    -8,     0,     0,     0,
       0,     0,     0,    -8,    -8,    -8,    -8,    -8,    -8,     0,
      -8,     0,    -8,    -8,    -8,     0,     0,    -8,     0,     0,
      -8,    -8,   -18,   -18,   -18,   -18,     0,   -18,     0,     0,
       0,     0,     0,     0,   -18,   -18,   -18,   -18,   -18,   -18,
       0,   -18,     0,   -18,   -18,   -18,     0,     0,   -18,     0,
       0,   -18,   -18,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,
       0,     0,     0,     0,     0,   -71,   -71,   -71,     0,     0,
     -71,     0,     0,   -72,   -72,   -72,     0,     0,   -72,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,     0,     0,     0,     0,     0,
       0,   -64,   -64,   -64,     0,     0,   -64,     0,   -81,   -81,
       0,     0,     0,     0,   -81,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,     0,     0,     0,     0,     0,   -57,    93,     0,     0,
       0,     0,   -57,     0,   -63,   -63,     0,     0,     0,     0,
     -63,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,
       0,     0,   -69,   -69,     0,     0,     0,     0,   -69,     0,
     -70,   -70,     0,     0,     0,     0,   -70,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,     0,     0,   -71,   -71,
       0,     0,     0,     0,   -71,     0,   -72,   -72,     0,     0,
       0,     0,   -72,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,
       0,     0,     0,     0,   -64,   -64,     0,     0,     0,     0,
     -64,     0,   -73,   -73,     0,     0,     0,     0,   -73,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,     0,     0,     0,     0,     0,
       0,   -79,   -79,     0,     0,     0,   -79,     0,     0,   -80,
     -80,     0,     0,     0,   -80,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,     0,     0,     0,     0,     0,     0,   -78,   -78,     0,
       0,     0,   -78,     0,     0,   -73,   -73,     0,     0,     0,
     -73,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,
       0,     0,     0,   -81,   -81,     0,     0,     0,   -81,     0,
       0,   218,   -57,     0,     0,     0,   -57,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,     0,     0,     0,     0,   -63,
     -63,     0,     0,     0,   -63,     0,     0,   -69,   -69,     0,
       0,     0,   -69,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,
       0,     0,     0,     0,     0,   -70,   -70,     0,     0,     0,
     -70,     0,     0,   -71,   -71,     0,     0,     0,   -71,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,
       0,     0,   -55,   -55,     0,     0,   232,     0,     0,     0,
     -58,   -58,     0,     0,   -58,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,     0,     0,     0,     0,     0,     0,   -72,   -72,     0,
       0,     0,   -72,     0,     0,   -64,   -64,     0,     0,     0,
     -64,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,
       0,     0,   -58,     0,     0,     0,     0,     0,   -58,     0,
       0,     0,   -55,     0,     0,     0,   216,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,
       0,     0,     0,   -61,   -61,   -61,   -61,     0,   -61,     0,
     -58,     0,     0,     0,   -58,   -61,   -61,   -61,   -61,   -59,
     -59,   -59,   -59,     0,   -59,   -60,   -60,   -60,   -60,   -61,
     -60,   -59,   -59,   -59,   -59,     0,     0,   -60,   -60,   -60,
     -60,   -62,   -62,   -62,   -62,   -59,   -62,    37,    38,    39,
     132,   -60,    40,   -62,   -62,   -62,   -62,     0,     0,    41,
      42,    43,    44,   135,   136,   137,   138,   -62,    40,   159,
     160,   161,   162,    48,    40,    41,    42,    43,   139,     0,
       0,    41,    42,    43,   163,   171,   172,   173,   174,   140,
      40,   246,   247,   248,   249,   164,    40,    41,    42,    43,
     175,     0,     0,    41,    42,    43,   250,   273,   274,   275,
     276,   176,    40,     0,     0,     0,     0,   251,     0,    41,
      42,    43,   277,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,     0,     0,   278,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,     0,     0,     0,   -79,   -79,   -79,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -80,   -80,   -80,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,     0,
     -78,   -78,   -78,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -73,   -73,   -73,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,   -81,   -81,   -81,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   308,   -57,   -57,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,
     -63,   -63,   -63,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -69,   -69,   -69,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,     0,     0,     0,   -70,   -70,   -70,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -71,   -71,   -71,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,
     -72,   -72,   -72,   231,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -64,   -64,   -64,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,     0,     0,     0,     0,   -53,   -53,   231,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,     0,   -55,   -55,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,
       0,   -54,   -54,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,     0,   -56,   -56,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,     0,     0,     0,     0,   -58,   -58,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -63,   -63,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,
     -69,   -69,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -70,   -70,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
       0,     0,     0,     0,   -71,   -71,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -72,   -72,   215,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,     0,     0,     0,     0,   -64,   -64,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,   -53,
     215,   -54,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
       0,     0,     0,   -55,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,     0,   -54,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,     0,     0,     0,     0,     0,   -56,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,     0,   -58,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,   -79,
     -79,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -80,
     -80,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,
       0,     0,   -78,   -78,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -73,   -73,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,   -81,   -81,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -57,   222,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,     0,     0,     0,   -63,   -63,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -69,   -69,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,
       0,   -70,   -70,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -71,   -71,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,     0,     0,     0,   -72,   -72,    90,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -64,   -64,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,     0,     0,     0,   -53,    90,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,     0,   -55,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,   -54,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,     0,   -56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -58
};

static const yytype_int16 yycheck[] =
{
       8,   114,    15,    32,   206,   134,   218,    15,   121,     1,
     222,     6,     0,    11,     0,    28,    28,    29,     4,     6,
      28,     0,   234,    47,    48,     4,    21,    11,   113,     0,
      28,    19,    20,   113,    29,   120,   113,   239,    26,   124,
      48,   113,    29,     0,    23,    28,    30,     6,    19,    20,
     113,    30,    76,    77,    30,    26,    10,    11,    12,    28,
      73,    29,    19,    20,    30,    73,   195,     0,    76,    26,
      29,     6,     6,    29,    28,    83,    84,    85,    86,    87,
      88,    89,    90,    32,   113,    93,    19,    20,     6,   113,
     114,   303,     6,    26,    29,    29,   308,   121,    28,     7,
       8,     9,    10,    11,    12,    13,    14,   115,     0,    32,
       0,    29,    33,   121,   127,    29,   140,   130,     6,   127,
      28,    29,   130,    28,   237,    28,    34,    19,    20,    19,
      20,    11,   140,    21,    26,    30,    26,    28,    10,    11,
     164,    29,   150,    30,   157,     9,    10,    11,    12,   157,
      30,    31,   176,    28,    19,    20,   164,   165,    30,     3,
       4,     5,     6,    30,     8,    30,    30,     0,   176,    28,
     194,    15,    16,    17,    18,    19,    20,   185,    22,    23,
      24,    25,    26,    19,    20,    29,    19,    20,    32,    33,
      26,    10,    11,    26,     9,    10,    11,    12,   311,    28,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   322,
     218,    30,   236,   237,   222,    30,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   310,   234,   251,   236,    28,
     310,     0,    30,   310,    10,    11,   321,    30,   310,    30,
     325,   321,     1,   251,   321,   325,   254,   310,   325,   321,
      19,    20,    28,   325,   278,    28,    29,    26,   321,    10,
      11,    12,   325,     3,     4,     5,     6,    30,     8,    29,
     278,    28,    29,   281,    28,    15,    16,    17,    18,    30,
      31,   310,    48,    19,    20,     0,   310,   311,    29,    29,
      30,    28,   321,    28,    30,   303,   325,   321,   322,    28,
     308,   325,    30,    69,    19,    20,    28,    29,    10,    11,
      76,    26,    10,    11,   322,    19,    20,    83,    84,    85,
      86,    87,    88,    89,    90,    30,    31,    93,    30,    31,
      28,     3,     4,     5,     6,    30,     8,    30,     9,    10,
      11,    12,    28,    15,    16,    17,    18,    19,    20,   115,
      22,    23,    24,    25,    26,   121,    30,    29,    28,    30,
      32,    33,    30,    31,    30,    31,     3,     4,     5,     6,
      30,     8,    30,    31,   140,    10,    11,    12,    15,    16,
      17,    18,    19,    20,   150,    22,    23,    24,    25,    26,
      30,    31,    29,    28,    30,    32,    33,    30,   164,   165,
      30,     3,     4,     5,     6,    33,     8,    30,    31,    30,
     176,    30,    31,    15,    16,    17,    18,    19,    20,   185,
      22,    23,    24,    25,    26,    30,    31,    29,    28,    30,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      30,    48,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    30,   218,    30,    29,    30,   222,    28,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    33,   234,    76,
     236,     9,    10,    11,    12,    30,    83,    84,    85,    86,
      87,    88,    89,    90,    30,   251,    93,    30,   254,    10,
      11,    12,    30,    31,     7,     8,     9,    10,    11,    12,
      13,    14,     9,    10,    11,    12,    30,    31,   115,    30,
      31,    30,   278,    28,   121,   281,    29,    30,    31,    30,
      31,    34,    30,    30,    31,     4,     3,     4,     5,     6,
      94,     8,    30,   140,    10,    11,    12,   303,    15,    16,
      17,    18,   308,   150,    -1,    22,    52,    24,    25,    -1,
      10,    11,    29,    -1,    30,    32,   322,   164,   165,    -1,
       3,     4,     5,     6,    -1,     8,    30,    31,    -1,   176,
      30,    31,    15,    16,    17,    18,    19,    20,   185,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      48,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,   218,    -1,    29,    30,   222,    -1,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   234,    76,   236,
       9,    10,    11,    12,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,   251,    93,    -1,   254,    10,    11,
      12,    30,    31,     7,     8,     9,    10,    11,    12,    13,
      14,     9,    10,    11,    12,    -1,    -1,   115,    30,    -1,
      -1,   278,    -1,   121,   281,    29,    30,    31,    -1,    -1,
      34,    -1,    30,    31,    -1,     3,     4,     5,     6,    -1,
       8,    -1,   140,    -1,    -1,    -1,   303,    15,    16,    17,
      18,   308,   150,    -1,    22,    -1,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    32,   322,   164,   165,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,   176,    -1,
      -1,    15,    16,    17,    18,    19,    20,   185,    22,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    48,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     218,    -1,    29,    30,   222,    -1,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,    76,   236,     9,
      10,    11,    12,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,   251,    93,    -1,   254,    -1,    -1,    -1,
      30,    31,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
     278,    -1,   121,   281,    29,    30,    31,    -1,    -1,    34,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,   140,    -1,    -1,    -1,   303,     9,    10,    11,    12,
     308,   150,    29,    30,    31,    -1,    -1,    34,     9,    10,
      11,    12,    -1,    -1,   322,   164,   165,    30,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,   176,    -1,    30,
      15,    16,    17,    18,    19,    20,   185,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    -1,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    48,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,   218,
      -1,    29,    30,   222,    -1,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,    76,   236,     9,    10,
      11,    12,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,   251,    93,    -1,   254,    -1,    -1,    -1,    30,
      31,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,   278,
      -1,   121,   281,    29,    30,    31,    -1,    -1,    34,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
     140,    -1,    -1,    -1,   303,     9,    10,    11,    12,   308,
     150,    29,    30,    31,    -1,    -1,    34,    -1,     9,    10,
      11,    12,    -1,   322,   164,   165,    30,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,   176,    28,    -1,    15,
      16,    17,    18,    19,    20,   185,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    48,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   218,    -1,
      29,    30,   222,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,    76,   236,     9,    10,    11,
      12,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,   251,    93,    -1,   254,    -1,    28,     9,    10,    11,
      12,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    28,    -1,   278,    -1,
     121,   281,    -1,    29,    30,    31,    -1,    48,    34,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,   140,
      -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,   308,   150,
      -1,    29,    30,    31,    -1,    76,    34,    -1,    -1,    -1,
      -1,    -1,   322,   164,   165,    86,    -1,    88,    89,    -1,
      -1,    -1,    93,    -1,    -1,   176,     3,     4,     5,     6,
      -1,     8,    -1,    -1,   185,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,   115,    22,    23,    24,    25,    26,
     121,    -1,    29,    -1,    -1,    32,    33,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,   218,    -1,   140,
      -1,   222,    -1,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   234,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,     3,     4,     5,     6,    -1,     8,
     251,    -1,    -1,   254,    -1,   176,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    -1,    -1,
      29,    -1,    -1,    32,    33,    -1,    -1,   278,    -1,    -1,
     281,     9,    10,    11,    12,    -1,    48,   208,   209,   210,
     211,    -1,   213,   214,    -1,   216,    -1,   218,    -1,    -1,
      28,   222,   303,   224,   225,   226,   227,   308,   229,   230,
      -1,   232,    -1,   234,    76,   236,    -1,    48,    -1,    -1,
      -1,   322,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
     251,    93,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    76,     8,     9,    10,    11,
      12,    13,    14,   115,    28,    29,    -1,   278,    -1,   121,
      34,    -1,    93,    -1,     9,    10,    11,    12,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,   140,    -1,
      -1,    -1,   303,    28,   115,    -1,    -1,   308,    -1,    -1,
     121,    29,    30,    31,    -1,    -1,    34,     9,    10,    11,
      12,   322,   164,    -1,    -1,     3,     4,     5,     6,   140,
       8,    -1,    -1,    -1,   176,    -1,    28,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    -1,
      -1,    29,    -1,   164,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,   176,   208,   209,   210,   211,
     212,   213,   214,    -1,   216,    -1,   218,    -1,    29,    30,
     222,    -1,   224,   225,   226,   227,   228,   229,   230,    48,
     232,    -1,   234,    -1,   236,    -1,    -1,   208,   209,   210,
     211,    -1,   213,   214,    -1,   216,    -1,   218,    -1,   251,
      48,   222,    -1,   224,   225,   226,   227,    76,   229,   230,
      -1,   232,    -1,   234,    -1,   236,    85,     8,     9,    10,
      11,    12,    13,    14,    93,    -1,   278,    -1,    76,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    84,    -1,    48,    30,
      31,    -1,    -1,    -1,    -1,    93,   115,    -1,    -1,    -1,
      -1,   303,   121,    -1,    -1,    -1,   308,   278,     7,     8,
       9,    10,    11,    12,    13,    14,    76,   115,    -1,    -1,
     322,   140,    -1,   121,    -1,    -1,    -1,    -1,    -1,    28,
      29,    91,   303,    93,    -1,    34,    -1,   308,    -1,    -1,
      -1,    48,   140,    -1,    -1,   164,    -1,    -1,    -1,    -1,
      -1,   322,    -1,    -1,    -1,   115,    -1,   176,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,   164,    -1,    -1,    76,
       3,     4,     5,     6,    -1,     8,    83,    -1,   176,    -1,
     140,    -1,    15,    16,    17,    18,    93,    -1,    -1,   208,
     209,   210,    -1,    -1,    -1,    28,    29,   216,    -1,   218,
      48,    -1,    -1,   222,   164,   224,   225,   226,   115,    -1,
     208,   209,    -1,   232,   121,   234,   176,   236,   216,    -1,
     218,    -1,    -1,    -1,   222,    -1,   224,   225,    76,    -1,
      -1,    -1,   251,   140,   232,    -1,   234,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    93,     8,     9,    10,    11,
      12,    13,    14,   251,    -1,    -1,   216,   164,   218,   278,
      -1,    -1,   222,    -1,    -1,    -1,    28,   115,    -1,   176,
      -1,    -1,   232,   121,   234,    -1,   236,    -1,    -1,    -1,
     278,    -1,    -1,    -1,   303,    -1,    -1,    -1,    -1,   308,
      -1,   251,   140,     7,     8,     9,    10,    11,    12,    13,
      14,   208,    -1,   322,    -1,   303,    -1,    -1,    -1,   216,
     308,   218,    -1,    -1,    28,   222,   164,   224,   278,    -1,
      34,    -1,    -1,    -1,   322,   232,    -1,   234,   176,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,   303,   251,    -1,    -1,    -1,   308,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      26,    -1,   322,    29,    -1,    -1,    32,    33,   216,    -1,
     218,   278,    -1,    -1,   222,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,   232,    -1,   234,    -1,   236,    -1,
      15,    16,    17,    18,    -1,    -1,   303,     3,     4,     5,
       6,   308,     8,   251,    29,    30,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,   322,    22,    -1,    24,    25,
      26,    -1,    -1,    29,    -1,    -1,    32,    33,    -1,    -1,
     278,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,   303,    24,    25,    26,    -1,
     308,    29,    -1,    -1,    32,    33,     3,     4,     5,     6,
      -1,     8,    -1,    -1,   322,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    22,    -1,    24,    25,    26,
      -1,    -1,    29,    -1,    -1,    32,    33,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    29,    -1,    -1,    32,    33,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    22,    -1,    24,
      25,    26,    -1,    -1,    29,    -1,    -1,    32,    33,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    22,    -1,
      24,    25,    26,    -1,    -1,    29,    -1,    -1,    32,    33,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    22,
      -1,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    32,
      33,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    -1,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
      32,    33,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    22,    -1,    24,    25,    26,    -1,    -1,    29,    -1,
      -1,    32,    33,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,    29,
      -1,    -1,    32,    33,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    -1,    22,    -1,    24,    25,    26,    -1,    -1,
      29,    -1,    -1,    32,    33,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    22,    -1,    24,    25,    26,    -1,
      -1,    29,    -1,    -1,    32,    33,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    22,    -1,    24,    25,    26,
      -1,    -1,    29,    -1,    -1,    32,    33,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    29,    -1,    -1,    32,    33,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    22,    -1,    24,
      25,    26,    -1,    -1,    29,    -1,    -1,    32,    33,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    -1,    22,    -1,
      24,    25,    26,    -1,    -1,    29,    -1,    -1,    32,    33,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    22,
      -1,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    32,
      33,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    -1,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
      32,    33,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    22,    -1,    24,    25,    26,    -1,    -1,    29,    -1,
      -1,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,
      34,    -1,    -1,    29,    30,    31,    -1,    -1,    34,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    -1,    34,    -1,    28,    29,
      -1,    -1,    -1,    -1,    34,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    34,    -1,    28,    29,    -1,    -1,    -1,    -1,
      34,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,    -1,
      28,    29,    -1,    -1,    -1,    -1,    34,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    -1,    -1,    34,    -1,    28,    29,    -1,    -1,
      -1,    -1,    34,     7,     8,     9,    10,    11,    12,    13,
      14,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      34,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    34,    -1,    -1,    29,
      30,    -1,    -1,    -1,    34,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    34,    -1,    -1,    29,    30,    -1,    -1,    -1,
      34,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,    -1,
      -1,    29,    30,    -1,    -1,    -1,    34,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    34,    -1,    -1,    29,    30,    -1,
      -1,    -1,    34,     7,     8,     9,    10,    11,    12,    13,
      14,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      34,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    34,    -1,    -1,    29,    30,    -1,    -1,    -1,
      34,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      30,    -1,    -1,    -1,    34,    15,    16,    17,    18,     3,
       4,     5,     6,    -1,     8,     3,     4,     5,     6,    29,
       8,    15,    16,    17,    18,    -1,    -1,    15,    16,    17,
      18,     3,     4,     5,     6,    29,     8,     3,     4,     5,
       6,    29,     8,    15,    16,    17,    18,    -1,    -1,    15,
      16,    17,    18,     3,     4,     5,     6,    29,     8,     3,
       4,     5,     6,    29,     8,    15,    16,    17,    18,    -1,
      -1,    15,    16,    17,    18,     3,     4,     5,     6,    29,
       8,     3,     4,     5,     6,    29,     8,    15,    16,    17,
      18,    -1,    -1,    15,    16,    17,    18,     3,     4,     5,
       6,    29,     8,    -1,    -1,    -1,    -1,    29,    -1,    15,
      16,    17,    18,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    29,    30,    31,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    30,    31,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      29,    30,    31,     7,     8,     9,    10,    11,    12,    13,
      14,    29,    30,    31,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    29,    30,    31,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    30,    31,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      29,    30,    31,     7,     8,     9,    10,    11,    12,    13,
      14,    29,    30,    31,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    29,    30,    31,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    30,    31,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      29,    30,    31,     7,     8,     9,    10,    11,    12,    13,
      14,    29,    30,    31,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    30,    31,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    30,    31,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    30,    31,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    30,    31,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    30,    31,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    30,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    30,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    30,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    30,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    28,
      29,     7,     8,     9,    10,    11,    12,    13,    14,    28,
      29,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    28,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    28,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    28,    29,     7,     8,     9,
      10,    11,    12,    13,    14,    28,    29,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    28,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    28,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    28,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    28,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    28,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    28,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    28,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    28,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    28,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    20,    26,    36,    37,    38,    40,    74,    21,
      21,     1,     0,    37,     6,    29,    52,    73,    28,    52,
      29,    39,    30,    41,    28,    43,    44,    45,    74,    30,
      31,    52,    42,    45,    32,    46,    47,     3,     4,     5,
       8,    15,    16,    17,    18,    22,    24,    25,    29,    38,
      46,    48,    49,    50,    51,    53,    54,    55,    56,    57,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    72,    73,    74,    75,    76,    29,    29,    57,    57,
      33,    50,    28,    11,    10,    12,     9,     8,    13,    14,
       7,    34,    67,    29,    52,    57,    57,    58,    28,    30,
      61,    67,    62,    63,    64,    66,    64,    64,    67,    59,
      59,    70,    71,    30,    28,    31,    30,    51,    58,    59,
      23,    28,    51,    58,    30,    51,     6,    29,    73,     6,
      29,    73,     6,    26,    32,     3,     4,     5,     6,    18,
      29,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    72,    73,    75,    76,     6,    29,    73,     3,
       4,     5,     6,    18,    29,    68,    69,    72,    73,    75,
      76,     3,     4,     5,     6,    18,    29,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    72,    73,    75,
      76,    39,    22,    24,    25,    32,    46,    53,    54,    55,
      56,    57,    57,    52,    52,     1,    47,    57,    11,    10,
      12,     9,     8,    13,    14,     7,    34,    67,    29,    52,
      57,    67,    29,    57,    11,    10,    12,     9,     8,    13,
      14,     7,    34,    67,    29,    28,    29,    29,    57,    47,
      28,    30,    30,    28,    48,    30,     3,     4,     5,     6,
      18,    29,    61,    67,    68,    69,    72,    73,    75,    76,
      62,    63,    64,    66,    64,    64,    67,    59,    71,    30,
      30,    71,    30,     3,     4,     5,     6,    18,    29,    61,
      67,    68,    69,    72,    73,    75,    76,    62,    63,    64,
      66,    64,    64,    67,    59,    71,    57,    58,    28,    48,
      33,    57,    67,    29,    30,    30,    57,    67,    29,    30,
      30,    28,    33,    30,    71,    30,    71,    51,    58,    30,
      30,    23,    28,    51,    58,    30,    51
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
      72,    72,    72,    73,    74,    74,    74,    74,    75,    75,
      75,    76
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
       1,     1,     3,     1,     1,     1,     2,     2,     1,     1,
       1,     1
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
#line 2045 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2051 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2057 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2063 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2069 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2075 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2081 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2087 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2093 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2099 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2105 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2111 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2117 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2123 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2129 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2135 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2141 "src/bison/grammar.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2147 "src/bison/grammar.c"
        break;

    case YYSYMBOL_39_1: /* @1  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2153 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2159 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_2: /* @2  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2165 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2171 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2177 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2183 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2189 "src/bison/grammar.c"
        break;

    case YYSYMBOL_declarator: /* declarator  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2195 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2201 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2207 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2213 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2219 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2225 "src/bison/grammar.c"
        break;

    case YYSYMBOL_58_expression_opt: /* expression.opt  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2231 "src/bison/grammar.c"
        break;

    case YYSYMBOL_assign_expr: /* assign_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2237 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2243 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2249 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2255 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2261 "src/bison/grammar.c"
        break;

    case YYSYMBOL_dl_dg_expr: /* dl_dg_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2267 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2273 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2279 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2285 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2291 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2297 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2303 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2309 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 68 "src/bison/math.y"
            { free(((*yyvaluep).pchar)); }
#line 2315 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2321 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 71 "src/bison/math.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2327 "src/bison/grammar.c"
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
#line 2598 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 75 "src/bison/math.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 2604 "src/bison/grammar.c"
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
#line 2626 "src/bison/grammar.c"
    break;

  case 7: /* declaration: type declarator @1 ';'  */
#line 98 "src/bison/math.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 2634 "src/bison/grammar.c"
    break;

  case 8: /* declaration: LET error ';'  */
#line 101 "src/bison/math.y"
                    {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("useless let in empty declaration\n", error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 2645 "src/bison/grammar.c"
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
#line 2680 "src/bison/grammar.c"
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
#line 2697 "src/bison/grammar.c"
    break;

  case 11: /* func_declaration: type declarator '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 149 "src/bison/math.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 2706 "src/bison/grammar.c"
    break;

  case 12: /* param_list.opt: %empty  */
#line 155 "src/bison/math.y"
                       { (yyval.list) = NULL; }
#line 2712 "src/bison/grammar.c"
    break;

  case 14: /* params_list: params_list ',' param_decl  */
#line 159 "src/bison/math.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2718 "src/bison/grammar.c"
    break;

  case 15: /* params_list: param_decl  */
#line 160 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2724 "src/bison/grammar.c"
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
#line 2736 "src/bison/grammar.c"
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
#line 2752 "src/bison/grammar.c"
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
#line 2765 "src/bison/grammar.c"
    break;

  case 19: /* block_item_list.opt: block_item_list  */
#line 192 "src/bison/math.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 2771 "src/bison/grammar.c"
    break;

  case 20: /* block_item_list.opt: %empty  */
#line 193 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2777 "src/bison/grammar.c"
    break;

  case 21: /* block_item_list: block_item_list block_item  */
#line 196 "src/bison/math.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2783 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list: block_item  */
#line 197 "src/bison/math.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2789 "src/bison/grammar.c"
    break;

  case 31: /* declarator: '(' declarator ')'  */
#line 212 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2795 "src/bison/grammar.c"
    break;

  case 32: /* expr_stmt: expression ';'  */
#line 215 "src/bison/math.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2801 "src/bison/grammar.c"
    break;

  case 33: /* cond_stmt: IF '(' expression ')' statement  */
#line 218 "src/bison/math.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 2809 "src/bison/grammar.c"
    break;

  case 34: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 221 "src/bison/math.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2817 "src/bison/grammar.c"
    break;

  case 35: /* jmp_stmt: RETURN expression ';'  */
#line 226 "src/bison/math.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 2823 "src/bison/grammar.c"
    break;

  case 36: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 229 "src/bison/math.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2831 "src/bison/grammar.c"
    break;

  case 38: /* expression.opt: %empty  */
#line 237 "src/bison/math.y"
                       { (yyval.ast) = NULL; }
#line 2837 "src/bison/grammar.c"
    break;

  case 41: /* assign_expr: unary_expr '=' assign_expr  */
#line 242 "src/bison/math.y"
                                 { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2843 "src/bison/grammar.c"
    break;

  case 43: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 246 "src/bison/math.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2852 "src/bison/grammar.c"
    break;

  case 45: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 253 "src/bison/math.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2861 "src/bison/grammar.c"
    break;

  case 47: /* eq_expr: eq_expr EQ rel_expr  */
#line 260 "src/bison/math.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2870 "src/bison/grammar.c"
    break;

  case 49: /* rel_expr: rel_expr REL dl_dg_expr  */
#line 267 "src/bison/math.y"
                              {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2879 "src/bison/grammar.c"
    break;

  case 51: /* dl_dg_expr: add_expr DL_DG dl_dg_expr  */
#line 274 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2888 "src/bison/grammar.c"
    break;

  case 52: /* dl_dg_expr: add_expr COLON dl_dg_expr  */
#line 278 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2897 "src/bison/grammar.c"
    break;

  case 54: /* add_expr: add_expr ADD mult_expr  */
#line 285 "src/bison/math.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2906 "src/bison/grammar.c"
    break;

  case 56: /* mult_expr: mult_expr MULT unary_expr  */
#line 292 "src/bison/math.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2915 "src/bison/grammar.c"
    break;

  case 58: /* unary_expr: unary_ops unary_expr  */
#line 299 "src/bison/math.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2924 "src/bison/grammar.c"
    break;

  case 64: /* postfix_expr: postfix_expr '(' arg_expr_list.opt ')'  */
#line 312 "src/bison/math.y"
                                             {
        (yyval.ast) = ast_funcall_init((yyvsp[-3].ast), ast_params_init((yyvsp[-1].list)));
    }
#line 2932 "src/bison/grammar.c"
    break;

  case 65: /* arg_expr_list: assign_expr  */
#line 317 "src/bison/math.y"
                           { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2938 "src/bison/grammar.c"
    break;

  case 66: /* arg_expr_list: arg_expr_list ',' assign_expr  */
#line 318 "src/bison/math.y"
                                    { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2944 "src/bison/grammar.c"
    break;

  case 68: /* arg_expr_list.opt: %empty  */
#line 322 "src/bison/math.y"
             { (yyval.list) = NULL; }
#line 2950 "src/bison/grammar.c"
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
#line 2968 "src/bison/grammar.c"
    break;

  case 72: /* primary_expr: '(' expression ')'  */
#line 340 "src/bison/math.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 2974 "src/bison/grammar.c"
    break;

  case 73: /* id: NAME  */
#line 343 "src/bison/math.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 2980 "src/bison/grammar.c"
    break;

  case 76: /* type: INT LIST  */
#line 348 "src/bison/math.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 2992 "src/bison/grammar.c"
    break;

  case 77: /* type: FLOAT LIST  */
#line 355 "src/bison/math.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3004 "src/bison/grammar.c"
    break;

  case 78: /* constant: NUMBER_REAL  */
#line 364 "src/bison/math.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 3010 "src/bison/grammar.c"
    break;

  case 79: /* constant: NUMBER_INT  */
#line 365 "src/bison/math.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3016 "src/bison/grammar.c"
    break;

  case 80: /* constant: NIL  */
#line 366 "src/bison/math.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3022 "src/bison/grammar.c"
    break;

  case 81: /* string_literal: STR_LITERAL  */
#line 369 "src/bison/math.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 3031 "src/bison/grammar.c"
    break;


#line 3035 "src/bison/grammar.c"

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

#line 375 "src/bison/math.y"


void yyerror(const char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    if (s) CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
    ++errors_count;
}
