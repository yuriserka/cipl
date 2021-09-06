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
#line 9 "src/bison/grammar.y"

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
    char *last_line_ref;

    void free_scope_cb(StackNode *node) { scope_free(node->data); }

    StackNode *context_get_current_stacknode_ref() {
        LIST_FOR_EACH_REVERSE(current_context->scopes, {
            if (((Scope *)__IT__->data)->index == current_context->current_scope) {
                return __IT__;
            }
        });
        return NULL;
    }

#line 105 "src/bison/grammar.c"

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
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_WRITE = 8,                      /* WRITE  */
  YYSYMBOL_MULT = 9,                       /* MULT  */
  YYSYMBOL_ADD = 10,                       /* ADD  */
  YYSYMBOL_REL = 11,                       /* REL  */
  YYSYMBOL_AND = 12,                       /* AND  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_COLON = 15,                     /* COLON  */
  YYSYMBOL_DL_DG = 16,                     /* DL_DG  */
  YYSYMBOL_EXCLAMATION = 17,               /* EXCLAMATION  */
  YYSYMBOL_PERCENT = 18,                   /* PERCENT  */
  YYSYMBOL_QUESTION = 19,                  /* QUESTION  */
  YYSYMBOL_STR_LITERAL = 20,               /* STR_LITERAL  */
  YYSYMBOL_INT = 21,                       /* INT  */
  YYSYMBOL_FLOAT = 22,                     /* FLOAT  */
  YYSYMBOL_LIST = 23,                      /* LIST  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_THEN = 28,                      /* THEN  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_prog = 37,                      /* prog  */
  YYSYMBOL_external_declaration_list = 38, /* external_declaration_list  */
  YYSYMBOL_external_declaration = 39,      /* external_declaration  */
  YYSYMBOL_var_declaration = 40,           /* var_declaration  */
  YYSYMBOL_41_1 = 41,                      /* @1  */
  YYSYMBOL_func_declaration = 42,          /* func_declaration  */
  YYSYMBOL_43_2 = 43,                      /* @2  */
  YYSYMBOL_44_3 = 44,                      /* $@3  */
  YYSYMBOL_45_param_list_opt = 45,         /* param_list.opt  */
  YYSYMBOL_params_list = 46,               /* params_list  */
  YYSYMBOL_param_decl = 47,                /* param_decl  */
  YYSYMBOL_compound_stmt = 48,             /* compound_stmt  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_50_block_item_list_opt = 50,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 51,           /* block_item_list  */
  YYSYMBOL_block_item = 52,                /* block_item  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_io_stmt = 54,                   /* io_stmt  */
  YYSYMBOL_expr_stmt = 55,                 /* expr_stmt  */
  YYSYMBOL_cond_stmt = 56,                 /* cond_stmt  */
  YYSYMBOL_jmp_stmt = 57,                  /* jmp_stmt  */
  YYSYMBOL_iter_stmt = 58,                 /* iter_stmt  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_60_expression_opt = 60,         /* expression.opt  */
  YYSYMBOL_logical_or_expr = 61,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 62,          /* logical_and_expr  */
  YYSYMBOL_eq_expr = 63,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 64,                  /* rel_expr  */
  YYSYMBOL_list_expr = 65,                 /* list_expr  */
  YYSYMBOL_add_expr = 66,                  /* add_expr  */
  YYSYMBOL_mult_expr = 67,                 /* mult_expr  */
  YYSYMBOL_unary_expr = 68,                /* unary_expr  */
  YYSYMBOL_unary_ops = 69,                 /* unary_ops  */
  YYSYMBOL_postfix_expr = 70,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 71,             /* arg_expr_list  */
  YYSYMBOL_72_arg_expr_list_opt = 72,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 73,              /* primary_expr  */
  YYSYMBOL_id_expr = 74,                   /* id_expr  */
  YYSYMBOL_id = 75,                        /* id  */
  YYSYMBOL_type = 76,                      /* type  */
  YYSYMBOL_constant = 77,                  /* constant  */
  YYSYMBOL_string_literal = 78             /* string_literal  */
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
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   5094

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  371

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      30,    31,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    82,    88,    89,    92,    93,    96,    96,
     122,   130,   160,   130,   180,   181,   184,   185,   188,   197,
     197,   216,   217,   220,   221,   224,   225,   228,   229,   230,
     231,   232,   233,   236,   243,   250,   253,   256,   259,   267,
     268,   276,   281,   282,   283,   292,   293,   296,   297,   301,
     311,   312,   316,   326,   327,   331,   341,   342,   346,   356,
     357,   361,   365,   373,   383,   384,   388,   398,   399,   403,
     413,   414,   420,   421,   422,   423,   426,   427,   432,   433,
     436,   437,   440,   441,   442,   443,   446,   460,   463,   464,
     465,   472,   481,   482,   483,   486
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "NUMBER_INT", "NIL",
  "NUMBER_REAL", "NAME", "READ", "WRITE", "MULT", "ADD", "REL", "AND",
  "OR", "EQ", "COLON", "DL_DG", "EXCLAMATION", "PERCENT", "QUESTION",
  "STR_LITERAL", "INT", "FLOAT", "LIST", "IF", "ELSE", "FOR", "RETURN",
  "THEN", "';'", "'('", "')'", "','", "'{'", "'}'", "'='", "$accept",
  "prog", "external_declaration_list", "external_declaration",
  "var_declaration", "@1", "func_declaration", "@2", "$@3",
  "param_list.opt", "params_list", "param_decl", "compound_stmt", "$@4",
  "block_item_list.opt", "block_item_list", "block_item", "statement",
  "io_stmt", "expr_stmt", "cond_stmt", "jmp_stmt", "iter_stmt",
  "expression", "expression.opt", "logical_or_expr", "logical_and_expr",
  "eq_expr", "rel_expr", "list_expr", "add_expr", "mult_expr",
  "unary_expr", "unary_ops", "postfix_expr", "arg_expr_list",
  "arg_expr_list.opt", "primary_expr", "id_expr", "id", "type", "constant",
  "string_literal", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    59,
      40,    41,    44,   123,   125,    61
};
#endif

#define YYPACT_NINF (-234)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-96)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      90,     5,    29,     2,    99,   113,   116,   136,     4,    41,
      43,  -234,   145,    24,   172,    58,   353,   -24,   388,   175,
     -22,   256,   291,    38,   -19,   169,   372,   -17,   438,  1843,
     184,  1946,    10,  3890,  3898,    16,    18,   197,  3382,  3400,
    3418,  3925,    71,    89,    88,  3436,  2433,  2465,    39,  2497,
    2529,  2561,  2593,  2625,  2657,  2689,  2721,   103,    96,   200,
     320,   731,  1049,  5057,   859,  3933,  3454,  3960,  3968,  1486,
    3583,    45,  3995,  4003,   133,  3436,   123,  3364,   115,   118,
     125,   187,  2753,  2785,   159,   311,   396,   677,   699,   795,
     817,   847,   995,  4030,   347,   132,   142,   164,  2817,   179,
     201,   215,  2849,  2881,  4038,   139,   428,  1177,   636,   369,
     589,  1823,  1868,  1999,  5065,  4863,  2115,  2147,  2179,  2211,
    4871,  4892,   219,   229,   456,   469,   218,   222,   225,   487,
    3364,  3472,  4065,  2913,  2945,   637,   228,   471,   523,  3346,
    2977,   246,   523,  3009,    79,    94,   478,  3610,  1843,  4073,
    4100,  4108,  3618,  4135,  3436,    30,    44,   168,   268,   348,
     467,  1365,  4143,  3436,  4170,  4178,  3645,  3653,  4205,  4213,
     231,  3041,   253,  4900,  4921,  4929,  2067,  4950,  3436,  3490,
    4958,  4979,  4811,  4833,  4987,  5008,  3680,  3688,  3715,  3538,
    3723,  3436,    28,   442,   306,   380,   709,  1929,  4315,  3750,
    3472,  3758,  3785,  3548,  3575,  3793,  3820,   265,   124,   266,
     280,   283,  1017,  1843,   955,  1273,  1554,  1648,  2041,  2081,
     295,   313,   336,   341,  1946,   356,  1113,  1135,  1165,  1313,
    1334,  1428,  1464,  1729,  1987,  4240,   347,   374,  5016,   347,
     376,  3139,  3160,  3181,  3202,  3223,  3244,  3265,  3286,  3307,
    3828,   347,  3073,   133,  3436,  3328,  3364,   389,   398,  1946,
    2113,   342,  4248,    91,  4571,  4594,  4602,   621,  4625,  3436,
     173,  4633,  3508,  4656,  4664,   939,  1257,  4687,  4695,   357,
     554,   818,   411,  1354,  1449,  4840,  4718,  1580,  1744,  1773,
    1787,  4726,  4749,   397,   117,   407,  5037,   421,  3855,   314,
    4339,  4347,  4371,  2024,  4379,  3436,   503,  4403,  3526,  4411,
    4435,  4283,  4307,  4443,  4467,   506,  1314,  1798,   797,   848,
    1027,  4740,  4475,  1115,  1166,  1479,  1630,  4499,  4507,   520,
     323,   436,   444,   454,  2145,   465,   483,  2177,  2209,   498,
    3105,   490,  4772,   347,  4275,  5045,   508,  4531,   347,  3863,
     515,   517,   487,  3364,  2241,  4780,   524,  4539,   526,  2273,
    2305,  2337,   519,  4803,  4563,   487,  3346,  2369,   527,   487,
    2401
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,  -234,   550,     8,   464,  -234,  -234,  -234,  -234,
    -234,   536,   -26,  -144,  -217,  -234,   513,  -102,  -100,   -99,
     -97,   -79,   -74,    20,   -68,  1747,  1677,  1666,  1540,  1297,
    1459,  1378,   217,   345,   535,  -234,  -233,   663,   853,    -8,
      13,   981,  1171
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    46,    17,     7,    18,    27,    20,
      21,    22,    47,    31,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   101,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   125,   126,    68,    69,    70,
      71,    72,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    30,    11,   295,   224,    19,   297,   261,     6,    24,
      13,   -88,     6,     8,   -12,    26,    29,     8,   331,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   135,     9,   215,
     216,    23,   217,    14,   -88,   -89,   140,   167,    23,   -93,
     143,   241,   339,   226,   146,   -93,    74,   -90,    75,   -91,
     218,   170,    10,   -87,   -87,   219,   227,   -47,   -89,   -42,
     -42,   -42,   136,    95,    79,    80,    96,   167,   167,   259,
     -90,   141,   -91,    81,   171,   -47,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   -88,   204,    -8,    16,    78,
      -3,    32,    33,    34,   147,    97,    99,   100,    37,    -2,
     -89,    76,   222,   214,   -49,    38,    39,    40,    41,    84,
     356,     1,     2,    -5,   124,   358,    -7,   223,    45,    77,
       1,     2,   -49,   204,    98,   -42,   149,   150,   151,   152,
     226,   167,    83,    37,    -5,    -5,    -6,    -7,    -7,   172,
      38,    39,    40,   153,   102,    -4,   167,   103,   -43,   220,
     100,   137,   -49,   154,   253,   167,   104,    -6,    -6,   221,
     105,    -8,   173,   174,   175,   176,    -4,    -4,   -49,    37,
     167,   183,   -10,   127,   225,    -9,    38,    39,    40,   177,
     -50,   -50,   228,   167,   -13,   227,   -48,   -20,   336,   178,
     144,   145,   204,   -10,   -10,   128,    -9,    -9,   237,   -50,
     -74,   -74,   -74,   -74,   -48,   -13,   -13,   -74,   -20,   -20,
     129,   240,    85,   -47,   -74,   -74,   -74,   -74,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   -74,   204,   -47,
     -46,   204,   258,   312,   312,   312,   312,   312,   312,   312,
     312,   312,    84,   204,   130,   332,   167,   167,   -44,   132,
     361,   133,   215,   216,   134,   217,   124,   139,   -43,   124,
     -87,   167,   162,   367,   276,   215,   216,   370,   217,   215,
     216,   124,   217,   218,   333,   335,   100,   142,   219,   229,
     -53,   -53,   -53,    93,   -87,   362,   218,   -15,    25,   341,
     218,   219,   162,   162,   252,   219,   254,   167,   368,   -53,
     312,   107,   107,   107,   107,   107,   107,   107,   121,   107,
     255,   199,   108,   256,   173,   174,   175,   176,   -50,   -50,
     243,    37,   -17,   -17,   260,   346,   214,   -49,    38,    39,
      40,   177,   -50,   -50,    86,   204,   241,   -50,   -50,   214,
     204,   178,   -90,   214,   -46,   -49,   -49,   -91,   199,   -50,
     186,   187,   188,   189,   -43,   -43,   162,    37,   167,   -56,
     -56,   -56,   -56,   124,    38,    39,    40,   190,   124,   -52,
     -52,   162,   220,   100,   -11,   -11,   340,   191,   -81,   -56,
     235,   -51,   -51,    86,   -11,   220,   221,   262,   -52,   220,
     163,   244,   -53,   -53,   -53,   162,   238,   110,   -51,   173,
     174,   175,   176,   -18,   -18,   296,    37,   298,   162,   144,
     145,   -53,   -53,    38,    39,    40,   177,   250,   337,   -14,
     163,   163,   229,   -54,   -54,   -54,   178,   338,   -44,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   344,   200,
      85,   -48,   -54,   271,   271,   271,   271,   271,   271,   271,
     292,   271,   345,   199,   242,   -47,   199,   -48,   307,   307,
     307,   307,   307,   307,   307,   328,   307,   349,   199,   -16,
     -16,   162,   162,   -47,   -47,   350,   200,   230,   -59,   -59,
     -59,   -59,   231,   232,   163,   351,   162,   -78,   -78,   342,
      32,    33,    34,   147,   208,   209,   352,    37,   -59,   163,
     -80,   131,   -79,   -79,    38,    39,    40,    41,   163,   -87,
     -87,   210,   353,   211,   212,   242,   -48,    45,   -52,   -52,
     213,   355,   162,   163,   179,   347,    32,    33,    34,   147,
      35,    36,   354,    37,   -48,   -48,   163,   -52,   -52,   357,
      38,    39,    40,    41,   359,   200,   360,    42,   366,    43,
      44,   -44,   -44,    45,    12,   363,   148,   364,   369,   207,
     199,    28,    82,     0,     0,   199,   -51,   -51,   228,     0,
       0,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     164,   200,     0,   162,   200,   -51,   308,   308,   308,   308,
     308,   308,   308,   308,   308,     0,   200,     0,     0,   163,
     163,   -55,   -55,   -55,     0,     0,     0,     0,     0,     0,
     164,   164,     0,     0,   163,     0,     0,   272,   -55,   180,
     180,   180,   180,   180,   180,   180,   180,   180,     0,   201,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,
     -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,   -52,   -52,
     163,   -87,   -87,   308,   -36,   -36,   -36,   -36,   -36,   -36,
       0,   -36,   138,   -36,   -36,   -52,   201,   -36,     0,     0,
     -36,   -36,     0,     0,   164,     0,     0,     0,   112,     0,
     173,   174,   175,   176,     0,     0,     0,    37,   200,   164,
       0,     0,     0,   200,    38,    39,    40,   177,   164,     0,
     114,     0,   173,   174,   175,   176,     0,   178,   165,    37,
       0,   163,     0,   164,   180,     0,    38,    39,    40,   177,
     -56,   -56,   -56,   -56,     0,     0,   164,     0,     0,   178,
       0,     0,     0,     0,     0,   201,     0,     0,   165,   165,
     -56,   -56,    87,   -53,   -53,   -53,     0,   181,   181,   181,
     181,   181,   181,   181,   181,   181,     0,   202,     0,     0,
     -53,   273,   273,   273,   273,   273,   273,   273,   273,   273,
       0,   201,     0,     0,   201,     0,   309,   309,   309,   309,
     309,   309,   309,   309,   309,     0,   201,     0,     0,   164,
     164,     0,     0,     0,   202,     0,   116,     0,   173,   174,
     175,   176,   165,     0,   164,    37,     0,   273,   244,   -54,
     -54,   -54,    38,    39,    40,   177,     0,   165,   118,     0,
     173,   174,   175,   176,     0,   178,   165,    37,   -54,   -54,
     -55,   -55,   -55,     0,    38,    39,    40,   177,     0,     0,
     164,   165,   181,   309,     0,     0,     0,   178,   120,   -55,
     173,   174,   175,   176,   165,     0,     0,    37,     0,   -58,
     -58,   -58,   -58,   202,    38,    39,    40,   177,    91,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,     0,   178,   201,   -58,
     -58,     0,     0,   201,     0,     0,     0,     0,   -64,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   166,   202,
       0,   164,   202,     0,   310,   310,   310,   310,   310,   310,
     310,   310,   310,     0,   202,     0,     0,   165,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,   166,
       0,     0,   165,     0,     0,   274,     0,   182,   182,   182,
     182,   182,   182,   182,   182,   182,     0,   203,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,     0,     0,   -28,   -28,
     -28,   -28,   -28,   -28,     0,   -28,     0,     0,   165,   343,
     -82,   310,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,
     -28,   -28,   -28,     0,   203,   -28,     0,     0,   -28,   -28,
       0,     0,   166,     0,     0,     0,   122,     0,   173,   174,
     175,   176,     0,     0,     0,    37,   202,   166,     0,     0,
       0,   202,    38,    39,    40,   177,   166,     0,   257,     0,
      32,    33,    34,   147,     0,   178,   168,    37,     0,   165,
       0,   166,   182,     0,    38,    39,    40,    41,   -57,   -57,
     -57,   -57,     0,     0,   166,     0,     0,    45,     0,     0,
       0,     0,     0,   203,     0,     0,   168,   168,   -57,   -57,
     -56,   -56,   -56,   -56,     0,   184,   184,   184,   184,   184,
     184,   184,   184,   184,     0,   205,     0,     0,   -56,   275,
     275,   275,   275,   275,   275,   275,   275,   275,     0,   203,
       0,     0,   203,     0,   311,   311,   311,   311,   311,   311,
     311,   311,   311,     0,   203,     0,     0,   166,   166,     0,
       0,     0,   205,     0,   263,     0,   264,   265,   266,   267,
     168,     0,   166,    37,     0,   275,   -63,   -63,   -63,   -63,
      38,    39,    40,   268,     0,   168,   279,     0,   264,   265,
     266,   267,     0,   269,   168,    37,   -63,   -63,     0,     0,
       0,     0,    38,    39,    40,   268,     0,     0,   166,   168,
     184,   311,     0,     0,     0,   269,   281,     0,   264,   265,
     266,   267,   168,     0,     0,    37,     0,   -61,   -61,   -61,
     -61,   205,    38,    39,    40,   268,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,     0,   269,   203,   -61,   -61,     0,
       0,   203,     0,     0,     0,     0,   -67,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   169,   205,     0,   166,
     205,     0,   313,   313,   313,   313,   313,   313,   313,   313,
     313,     0,   205,     0,     0,   168,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   169,     0,     0,
     168,     0,     0,   277,     0,   185,   185,   185,   185,   185,
     185,   185,   185,   185,     0,   206,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,     0,     0,   -32,   -32,   -32,   -32,
     -32,   -32,     0,   -32,     0,     0,   168,   -86,   -86,   313,
     -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,
     -32,     0,   206,   -32,     0,     0,   -32,   -32,     0,     0,
     169,     0,     0,     0,   283,     0,   264,   265,   266,   267,
       0,     0,     0,    37,   205,   169,   -51,   -51,   243,   205,
      38,    39,    40,   268,   169,   285,     0,   264,   265,   266,
     267,     0,   159,   269,    37,   -51,   -51,   168,     0,   169,
     185,    38,    39,    40,   268,     0,     0,     0,     0,     0,
       0,     0,   169,     0,   269,   -58,   -58,   -58,   -58,     0,
       0,   206,   159,   159,   233,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,     0,     0,   113,   -58,   117,   119,     0,     0,
       0,   196,     0,     0,     0,     0,   -64,   278,   278,   278,
     278,   278,   278,   278,   278,   278,     0,   206,     0,     0,
     206,     0,   314,   314,   314,   314,   314,   314,   314,   314,
     314,     0,   206,   161,     0,   169,   169,     0,   196,   287,
       0,   264,   265,   266,   267,     0,   159,     0,    37,     0,
     169,     0,     0,   278,     0,    38,    39,    40,   268,     0,
       0,   159,     0,   161,   161,     0,     0,     0,   269,     0,
     -57,   -57,   -57,   -57,     0,   289,   115,   264,   265,   266,
     267,     0,   198,     0,    37,   159,   169,     0,     0,   314,
     -57,    38,    39,    40,   268,     0,     0,     0,   159,     0,
     -62,   -62,   -62,   -62,   269,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,     0,   160,     0,     0,     0,     0,   198,
     -62,   -62,     0,     0,   206,   -82,    94,   161,     0,   206,
       0,   -82,     0,   159,   159,   159,   284,     0,   288,   290,
       0,   159,   161,   196,   160,   160,   196,   169,   196,   196,
     196,   320,     0,   324,   326,     0,   196,     0,   196,     0,
       0,   159,   159,   197,     0,     0,   161,   -27,   -27,   -27,
     -27,   -27,   -27,     0,   -27,     0,   159,     0,     0,   161,
       0,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,
     -27,   -27,     0,     0,   -27,   158,     0,   -27,   -27,     0,
     197,   -63,   -63,   -63,   -63,     0,     0,     0,   160,     0,
       0,     0,   159,     0,   161,   161,   161,   161,   286,   161,
     161,   -63,   161,   160,   198,   158,   158,   198,     0,   198,
     198,   198,   198,   322,   198,   198,   111,   198,     0,   198,
       0,     0,   161,   161,   195,     0,     0,   160,     0,     0,
     196,   -60,   -60,   -60,   -60,   196,     0,   161,     0,     0,
     160,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,     0,
       0,   -60,   -60,   159,     0,   -29,   -29,   -29,   -29,   -29,
     -29,   195,   -29,   -29,   -29,   -29,     0,     0,   -29,   158,
       0,   -29,   -29,   161,     0,   160,   160,   160,   160,     0,
     160,   160,     0,   160,   158,   197,     0,     0,   197,     0,
     197,   197,   197,   197,     0,   197,   197,     0,   197,     0,
     197,   157,     0,   160,   160,     0,     0,     0,   158,     0,
       0,   198,   156,     0,     0,     0,   198,     0,   160,     0,
     291,   158,   264,   265,   266,   267,     0,     0,     0,    37,
       0,   157,   157,     0,   161,     0,    38,    39,    40,   268,
       0,   109,   156,   156,     0,   -61,   -61,   -61,   -61,   269,
     194,   106,     0,     0,   160,     0,   158,   158,   282,     0,
       0,   193,     0,     0,   158,   -61,   195,     0,     0,   195,
       0,   195,   195,   318,   -62,   -62,   -62,   -62,     0,   195,
       0,   195,   155,     0,   158,   158,     0,   194,   -60,   -60,
     -60,   -60,   197,     0,   -62,   157,     0,   197,   193,   158,
     -55,   -55,   -55,     0,     0,     0,   156,     0,   -60,     0,
     157,     0,   155,   155,     0,   160,     0,     0,     0,   -55,
     -55,   156,     0,     0,    87,   -54,   -54,   -54,     0,   123,
       0,   192,     0,     0,   157,   158,   -19,   -19,   -19,   -19,
     -19,   -19,   -54,   -19,     0,   156,     0,   157,     0,     0,
     -19,   -19,   -19,   -19,   -19,   -19,     0,   -19,   156,   -19,
     -19,     0,     0,   -19,     0,     0,   -19,   -19,   192,   -58,
     -58,   -58,   -58,   195,     0,     0,   155,     0,   195,     0,
       0,     0,   157,   280,     0,     0,     0,   -58,     0,     0,
     157,   155,   194,   270,     0,   194,   158,   194,   316,     0,
       0,   156,     0,   193,     0,   194,   193,   194,   306,     0,
     157,   157,     0,     0,     0,   155,   193,     0,   193,     0,
       0,   156,   156,     0,     0,   157,     0,     0,   155,   245,
     -59,   -59,   -59,   -59,   246,   247,   156,     0,     0,    32,
      33,    34,   147,    35,    36,     0,    37,     0,     0,     0,
     -59,   -59,     0,    38,    39,    40,    41,     1,     2,     0,
      42,   157,    43,    44,     0,     0,    45,     0,     0,   148,
     -22,   294,   156,   192,     0,     0,   192,     0,   293,     0,
     264,   265,   266,   267,     0,     0,   330,    37,   192,     0,
       0,   155,   155,     0,    38,    39,    40,   268,     0,   194,
     -57,   -57,   -57,   -57,   194,     0,   155,   269,     0,     0,
     193,     0,     0,     0,     0,   193,     0,     0,   -57,     0,
       0,     0,   157,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,     0,     0,   156,   -30,   -30,   -30,   -30,   -30,   -30,
       0,   -30,   155,     0,   -87,   -87,   -87,     0,   -30,   -30,
     -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,     0,
       0,   -30,     0,     0,   -30,   -30,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -31,   -31,   -31,   -31,   -31,   -31,
     192,   -31,     0,     0,     0,   192,   -87,   -87,   -31,   -31,
     -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,   -31,     0,
       0,   -31,     0,   155,   -31,   -31,   -35,   -35,   -35,   -35,
     -35,   -35,     0,   -35,     0,     0,   -63,   -63,   -63,   -63,
     -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,   -35,
     -35,     0,     0,   -35,   -63,     0,   -35,   -35,   -38,   -38,
     -38,   -38,   -38,   -38,     0,   -38,     0,     0,   -61,   -61,
     -61,   -61,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,
     -38,   -38,   -38,     0,     0,   -38,   -61,     0,   -38,   -38,
     -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,
     -62,   -62,   -62,   -62,   -40,   -40,   -40,   -40,   -40,   -40,
       0,   -40,   -40,   -40,   -40,     0,     0,   -40,   -62,     0,
     -40,   -40,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,
       0,     0,   -60,   -60,   -60,   -60,   -39,   -39,   -39,   -39,
     -39,   -39,     0,   -39,   -39,   -39,   -39,     0,     0,   -39,
     -60,     0,   -39,   -39,   -20,   -20,   -20,   -20,   -20,   -20,
       0,   -20,     0,     0,     0,     0,     0,     0,   -20,   -20,
     -20,   -20,   -20,   -20,     0,   -20,   -20,   -20,   -20,     0,
       0,   -20,     0,     0,   -20,   -20,   -33,   -33,   -33,   -33,
     -33,   -33,     0,   -33,     0,     0,     0,     0,     0,     0,
     -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,   -33,
     -33,     0,     0,   -33,     0,     0,   -33,   -33,   -34,   -34,
     -34,   -34,   -34,   -34,     0,   -34,     0,     0,     0,     0,
       0,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,
     -34,   -34,   -34,     0,     0,   -34,     0,     0,   -34,   -34,
     -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,     0,     0,
       0,     0,     0,     0,   -36,   -36,   -36,   -36,   -36,   -36,
       0,   -36,   365,   -36,   -36,     0,     0,   -36,     0,     0,
     -36,   -36,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,
       0,     0,     0,     0,     0,     0,   -37,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,   -37,   -37,     0,     0,   -37,
       0,     0,   -37,   -37,   -41,   -41,   -41,   -41,   -41,   -41,
       0,   -41,     0,     0,     0,     0,     0,     0,   -41,   -41,
     -41,   -41,   -41,   -41,     0,   -41,   -41,   -41,   -41,     0,
       0,   -41,     0,     0,   -41,   -41,   -25,   -25,   -25,   -25,
     -25,   -25,     0,   -25,     0,     0,     0,     0,     0,     0,
     -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,     0,   -25,
     -25,     0,     0,   -25,     0,     0,   -25,   -25,   -28,   -28,
     -28,   -28,   -28,   -28,     0,   -28,     0,     0,     0,     0,
       0,     0,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,
       0,   -28,   -28,     0,     0,   -28,     0,     0,   -28,   -28,
      32,    33,    34,   147,    35,    36,     0,    37,     0,     0,
       0,     0,     0,     0,    38,    39,    40,    41,     1,     2,
       0,    42,     0,    43,    44,     0,     0,    45,     0,     0,
     148,   -21,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,
       0,     0,     0,     0,     0,     0,   -24,   -24,   -24,   -24,
     -24,   -24,     0,   -24,     0,   -24,   -24,     0,     0,   -24,
       0,     0,   -24,   -24,   -26,   -26,   -26,   -26,   -26,   -26,
       0,   -26,     0,     0,     0,     0,     0,     0,   -26,   -26,
     -26,   -26,   -26,   -26,     0,   -26,     0,   -26,   -26,     0,
       0,   -26,     0,     0,   -26,   -26,   -32,   -32,   -32,   -32,
     -32,   -32,     0,   -32,     0,     0,     0,     0,     0,     0,
     -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,     0,   -32,
     -32,     0,     0,   -32,     0,     0,   -32,   -32,   -27,   -27,
     -27,   -27,   -27,   -27,     0,   -27,     0,     0,     0,     0,
       0,     0,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,
       0,   -27,   -27,     0,     0,   -27,     0,     0,   -27,   -27,
     -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,     0,     0,
       0,     0,     0,     0,   -29,   -29,   -29,   -29,   -29,   -29,
       0,   -29,     0,   -29,   -29,     0,     0,   -29,     0,     0,
     -29,   -29,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,
       0,     0,     0,     0,     0,     0,   -30,   -30,   -30,   -30,
     -30,   -30,     0,   -30,     0,   -30,   -30,     0,     0,   -30,
       0,     0,   -30,   -30,   -31,   -31,   -31,   -31,   -31,   -31,
       0,   -31,     0,     0,     0,     0,     0,     0,   -31,   -31,
     -31,   -31,   -31,   -31,     0,   -31,     0,   -31,   -31,     0,
       0,   -31,     0,     0,   -31,   -31,   -23,   -23,   -23,   -23,
     -23,   -23,     0,   -23,     0,     0,     0,     0,     0,     0,
     -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,     0,   -23,
     -23,     0,     0,   -23,     0,     0,   -23,   -23,   -35,   -35,
     -35,   -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,
       0,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,
       0,   -35,   -35,     0,     0,   -35,     0,     0,   -35,   -35,
     -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,     0,     0,
       0,     0,     0,     0,   -38,   -38,   -38,   -38,   -38,   -38,
       0,   -38,     0,   -38,   -38,     0,     0,   -38,     0,     0,
     -38,   -38,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,
       0,     0,     0,     0,     0,     0,   -40,   -40,   -40,   -40,
     -40,   -40,     0,   -40,     0,   -40,   -40,     0,     0,   -40,
       0,     0,   -40,   -40,   -39,   -39,   -39,   -39,   -39,   -39,
       0,   -39,     0,     0,     0,     0,     0,     0,   -39,   -39,
     -39,   -39,   -39,   -39,     0,   -39,     0,   -39,   -39,     0,
       0,   -39,     0,     0,   -39,   -39,   -33,   -33,   -33,   -33,
     -33,   -33,     0,   -33,     0,     0,     0,     0,     0,     0,
     -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,     0,   -33,
     -33,     0,     0,   -33,     0,     0,   -33,   -33,   -34,   -34,
     -34,   -34,   -34,   -34,     0,   -34,     0,     0,     0,     0,
       0,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,
       0,   -34,   -34,     0,     0,   -34,     0,     0,   -34,   -34,
     -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,     0,     0,
       0,     0,     0,     0,   -37,   -37,   -37,   -37,   -37,   -37,
       0,   -37,     0,   -37,   -37,     0,     0,   -37,     0,     0,
     -37,   -37,   -41,   -41,   -41,   -41,   -41,   -41,     0,   -41,
       0,     0,     0,     0,     0,     0,   -41,   -41,   -41,   -41,
     -41,   -41,     0,   -41,     0,   -41,   -41,     0,     0,   -41,
       0,     0,   -41,   -41,   -10,   -10,   -10,   -10,   -10,   -10,
       0,   -10,     0,     0,     0,     0,     0,     0,   -10,   -10,
     -10,   -10,   -10,   -10,     0,   -10,     0,   -10,   -10,     0,
       0,   -10,     0,     0,   -10,   -10,    -9,    -9,    -9,    -9,
      -9,    -9,     0,    -9,     0,     0,     0,     0,     0,     0,
      -9,    -9,    -9,    -9,    -9,    -9,     0,    -9,     0,    -9,
      -9,     0,     0,    -9,     0,     0,    -9,    -9,   -20,   -20,
     -20,   -20,   -20,   -20,     0,   -20,     0,     0,     0,     0,
       0,     0,   -20,   -20,   -20,   -20,   -20,   -20,     0,   -20,
       0,   -20,   -20,     0,     0,   -20,     0,     0,   -20,   -20,
     299,     0,   300,   301,   302,   303,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,    38,    39,    40,   304,
       0,   315,     0,   300,   301,   302,   303,     0,     0,   305,
      37,     0,     0,     0,     0,     0,     0,    38,    39,    40,
     304,     0,   317,     0,   300,   301,   302,   303,     0,     0,
     305,    37,     0,     0,     0,     0,     0,     0,    38,    39,
      40,   304,     0,   319,     0,   300,   301,   302,   303,     0,
       0,   305,    37,     0,     0,     0,     0,     0,     0,    38,
      39,    40,   304,     0,   321,     0,   300,   301,   302,   303,
       0,     0,   305,    37,     0,     0,     0,     0,     0,     0,
      38,    39,    40,   304,     0,   323,     0,   300,   301,   302,
     303,     0,     0,   305,    37,     0,     0,     0,     0,     0,
       0,    38,    39,    40,   304,     0,   325,     0,   300,   301,
     302,   303,     0,     0,   305,    37,     0,     0,     0,     0,
       0,     0,    38,    39,    40,   304,     0,   327,     0,   300,
     301,   302,   303,     0,     0,   305,    37,     0,     0,     0,
       0,     0,     0,    38,    39,    40,   304,     0,   329,     0,
     300,   301,   302,   303,     0,     0,   305,    37,     0,     0,
       0,     0,     0,     0,    38,    39,    40,   304,     0,   334,
       0,   149,   150,   151,   152,     0,     0,   305,    37,     0,
       0,     0,     0,     0,     0,    38,    39,    40,   153,   149,
     150,   151,   152,     0,     0,     0,    37,     0,   154,     0,
       0,     0,     0,    38,    39,    40,   153,    32,    33,    34,
     147,     0,     0,     0,    37,     0,   154,   -45,     0,     0,
       0,    38,    39,    40,    41,   -72,   -72,   -72,   -72,     0,
       0,     0,   -72,   -45,    45,     0,     0,     0,     0,   -72,
     -72,   -72,   -72,   -73,   -73,   -73,   -73,     0,     0,     0,
     -73,     0,   -72,     0,     0,     0,     0,   -73,   -73,   -73,
     -73,   -75,   -75,   -75,   -75,     0,     0,     0,   -75,     0,
     -73,     0,     0,     0,     0,   -75,   -75,   -75,   -75,   149,
     150,   151,   152,     0,     0,     0,    37,     0,   -75,     0,
       0,     0,     0,    38,    39,    40,   153,    32,    33,    34,
     147,     0,     0,     0,    37,     0,   154,     0,     0,     0,
       0,    38,    39,    40,    41,   186,   187,   188,   189,     0,
       0,     0,    37,     0,    45,     0,     0,     0,     0,    38,
      39,    40,   190,   173,   174,   175,   176,     0,     0,     0,
      37,     0,   191,     0,     0,     0,     0,    38,    39,    40,
     177,   264,   265,   266,   267,     0,     0,     0,    37,     0,
     178,     0,     0,     0,     0,    38,    39,    40,   268,   300,
     301,   302,   303,     0,     0,     0,    37,     0,   269,     0,
       0,     0,     0,    38,    39,    40,   304,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,     0,   305,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,     0,     0,     0,   -87,   -87,
     -87,     0,     0,   -87,     0,     0,     0,     0,   251,   -82,
     -82,     0,     0,   -82,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
       0,     0,     0,     0,     0,   -86,   -86,   -86,     0,     0,
     -86,     0,   -86,   -86,     0,     0,     0,     0,   -86,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,     0,     0,     0,     0,   -87,
     -87,     0,     0,     0,     0,   -87,     0,     0,   -87,   -87,
       0,     0,     0,   -87,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
       0,     0,     0,     0,     0,   236,   -82,     0,     0,     0,
     -82,     0,     0,   -86,   -86,     0,     0,     0,   -86,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,
       0,   -93,   -93,     0,     0,   -93,     0,     0,     0,   -94,
     -94,     0,     0,   -94,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
       0,     0,     0,     0,     0,     0,   -92,   -92,     0,     0,
     -92,     0,     0,     0,   -95,   -95,     0,     0,   -95,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,     0,
       0,   -67,   -67,     0,     0,   249,     0,     0,     0,   -70,
     -70,     0,     0,   -70,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
       0,     0,     0,     0,     0,     0,   -76,   -76,     0,     0,
     -76,     0,     0,     0,   -83,   -83,     0,     0,   -83,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,     0,     0,     0,     0,     0,
       0,   -84,   -84,     0,     0,   -84,     0,     0,     0,   -71,
     -71,     0,     0,   -71,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
       0,     0,     0,     0,     0,     0,   -85,   -85,     0,     0,
     -85,     0,     0,     0,   -77,   -77,     0,     0,   -77,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,     0,     0,     0,     0,   -94,
       0,     0,     0,     0,     0,   -94,     0,   -92,     0,     0,
       0,     0,     0,   -92,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
       0,     0,     0,     0,   -95,     0,     0,     0,     0,     0,
     -95,     0,   -67,     0,     0,     0,     0,     0,    92,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,     0,     0,     0,     0,   -70,
       0,     0,     0,     0,     0,   -70,     0,   -76,     0,     0,
       0,     0,     0,   -76,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
       0,     0,     0,     0,   -83,     0,     0,     0,     0,     0,
     -83,     0,   -84,     0,     0,     0,     0,     0,   -84,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,     0,     0,     0,     0,   -71,
       0,     0,     0,     0,     0,   -71,     0,   -85,     0,     0,
       0,     0,     0,   -85,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
       0,     0,     0,     0,   -77,     0,     0,     0,     0,     0,
     -77,     0,     0,     0,   -93,     0,     0,     0,   -93,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,     0,     0,     0,     0,     0,
       0,   -94,     0,     0,     0,   -94,     0,     0,     0,   -92,
       0,     0,     0,   -92,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
       0,     0,     0,     0,     0,     0,   -95,     0,     0,     0,
     -95,     0,     0,     0,   -67,     0,     0,     0,   234,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,     0,     0,     0,     0,     0,
       0,   -70,     0,     0,     0,   -70,     0,     0,     0,   -76,
       0,     0,     0,   -76,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
       0,     0,     0,     0,     0,     0,   -83,     0,     0,     0,
     -83,     0,     0,     0,   -84,     0,     0,     0,   -84,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,     0,     0,     0,     0,     0,
       0,   -71,     0,     0,     0,   -71,     0,     0,     0,   -85,
       0,     0,     0,   -85,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
       0,     0,     0,     0,     0,     0,   -77,     0,     0,     0,
     -77,     0,     0,   348,   -82,   -82,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   248,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,     0,     0,     0,     0,     0,   -86,   -86,   -86,
       0,     0,     0,     0,     0,     0,   -64,   -64,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,     0,
     -93,   -93,     0,     0,     0,     0,     0,     0,   -94,   -94,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,     0,     0,     0,     0,
       0,     0,   -92,   -92,     0,     0,     0,     0,     0,     0,
     -95,   -95,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,
       0,     0,     0,     0,   -67,   -67,     0,     0,     0,     0,
       0,     0,   -70,   -70,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
       0,     0,     0,     0,     0,     0,   -76,   -76,     0,     0,
       0,     0,     0,     0,   -83,   -83,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   248,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,     0,     0,     0,     0,     0,     0,   -84,   -84,
       0,     0,     0,     0,     0,     0,   -65,   -65,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,     0,     0,     0,     0,     0,     0,
     -69,   -69,     0,     0,     0,     0,     0,     0,   -68,   -68,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,     0,     0,     0,     0,
       0,     0,   -71,   -71,     0,     0,     0,     0,     0,     0,
     -85,   -85,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,     0,
       0,     0,     0,     0,   -77,   -77,     0,     0,     0,     0,
       0,     0,   -93,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,     0,
       0,     0,     0,     0,     0,   -94,     0,     0,     0,     0,
       0,     0,     0,   -92,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
       0,     0,     0,     0,     0,     0,   -95,     0,     0,     0,
       0,     0,     0,     0,   -67,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,     0,     0,     0,     0,     0,     0,   -70,     0,     0,
       0,     0,     0,     0,     0,   -76,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,     0,     0,     0,     0,     0,     0,   -83,     0,
       0,     0,     0,     0,     0,     0,   -84,   233,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,     0,     0,     0,     0,   -65,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -69,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,     0,     0,     0,     0,
       0,   -66,   -66,     0,     0,     0,     0,     0,     0,     0,
     -68,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,     0,     0,     0,
       0,     0,     0,   -71,     0,     0,     0,     0,     0,     0,
       0,   -85,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,     0,     0,
       0,     0,     0,     0,   -77,     0,     0,     0,     0,     0,
     -82,   239,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,
       0,     0,   -86,   -86,     0,     0,     0,     0,     0,     0,
       0,   -66,    91,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,
       0,     0,   -65,     0,     0,     0,     0,     0,     0,     0,
     -69,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,     0,     0,
       0,   -68,     0,     0,     0,     0,     0,     0,     0,   -93,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,     0,     0,     0,     0,
     -94,     0,     0,     0,     0,     0,     0,     0,   -92,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,   -95,
       0,     0,     0,     0,     0,     0,     0,   -70,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,     0,     0,     0,     0,   -76,     0,
       0,     0,     0,     0,     0,     0,   -83,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,     0,     0,   -84,     0,     0,
       0,     0,     0,     0,     0,   -71,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,     0,     0,     0,     0,   -85,    88,   -59,   -59,
     -59,   -59,    89,    90,   -77,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,     0,     0,     0,     0,   -59,     0,     0,     0,
       0,     0,     0,     0,   -66
};

static const yytype_int16 yycheck[] =
{
       8,    27,     0,   236,   148,    29,   239,   224,     0,    31,
       6,     6,     4,     0,    33,    23,    33,     4,   251,     9,
      10,    11,    12,    13,    14,    15,    16,   129,    23,   129,
     129,    18,   129,    29,    29,     6,   138,    45,    25,    29,
     142,    13,   259,    13,     6,    35,    30,     6,    30,     6,
     129,     6,    23,    29,    30,   129,    12,    13,    29,    31,
      32,    31,   130,    71,    44,    45,    74,    75,    76,   213,
      29,   139,    29,    34,    29,    31,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     6,    94,    29,    30,     1,
       0,     3,     4,     5,     6,    75,    76,    77,    10,     0,
       6,    30,    23,   129,    13,    17,    18,    19,    20,    13,
     343,    21,    22,     0,    94,   348,     0,    23,    30,    30,
      21,    22,    31,   131,     1,    29,     3,     4,     5,     6,
      13,   139,    29,    10,    21,    22,     0,    21,    22,     6,
      17,    18,    19,    20,    29,     0,   154,    29,    31,   129,
     130,   131,    13,    30,    30,   163,    31,    21,    22,   139,
       1,    29,     3,     4,     5,     6,    21,    22,    29,    10,
     178,   179,     0,    31,   154,     0,    17,    18,    19,    20,
      12,    13,    14,   191,     0,    12,    13,     0,   256,    30,
      21,    22,   200,    21,    22,    31,    21,    22,   178,    31,
       3,     4,     5,     6,    31,    21,    22,    10,    21,    22,
      31,   191,    12,    13,    17,    18,    19,    20,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    30,   236,    29,
      29,   239,   212,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    13,   251,    29,   253,   254,   255,    29,    31,
     352,    29,   352,   352,    29,   352,   236,    29,    29,   239,
      29,   269,    45,   365,   272,   365,   365,   369,   365,   369,
     369,   251,   369,   352,   254,   255,   256,    31,   352,    11,
      12,    13,    14,    66,    31,   353,   365,    31,    32,   269,
     369,   365,    75,    76,    29,   369,    30,   305,   366,    31,
     308,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      30,    94,     1,    30,     3,     4,     5,     6,    12,    13,
      14,    10,    31,    32,    29,   305,   352,    13,    17,    18,
      19,    20,    12,    13,    14,   343,    13,    31,    32,   365,
     348,    30,     6,   369,    31,    31,    32,     6,   131,    29,
       3,     4,     5,     6,    31,    32,   139,    10,   366,    11,
      12,    13,    14,   343,    17,    18,    19,    20,   348,    12,
      13,   154,   352,   353,    21,    22,    34,    30,    31,    31,
     163,    12,    13,    14,    31,   365,   366,    31,    31,   369,
      45,    11,    12,    13,    14,   178,   179,     1,    29,     3,
       4,     5,     6,    31,    32,    31,    10,    31,   191,    21,
      22,    31,    32,    17,    18,    19,    20,   200,    29,    31,
      75,    76,    11,    12,    13,    14,    30,    29,    31,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    31,    94,
      12,    13,    31,   226,   227,   228,   229,   230,   231,   232,
     233,   234,    31,   236,    12,    13,   239,    29,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    31,   251,    31,
      32,   254,   255,    31,    32,    31,   131,    10,    11,    12,
      13,    14,    15,    16,   139,    31,   269,    31,    32,   272,
       3,     4,     5,     6,     7,     8,    31,    10,    31,   154,
      31,    32,    31,    32,    17,    18,    19,    20,   163,    31,
      32,    24,    29,    26,    27,    12,    13,    30,    12,    13,
      33,    31,   305,   178,   179,   308,     3,     4,     5,     6,
       7,     8,    34,    10,    31,    32,   191,    31,    32,    31,
      17,    18,    19,    20,    29,   200,    29,    24,    29,    26,
      27,    31,    32,    30,     4,    31,    33,    31,    31,    95,
     343,    25,    49,    -1,    -1,   348,    12,    13,    14,    -1,
      -1,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      45,   236,    -1,   366,   239,    31,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,    -1,    -1,   254,
     255,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    -1,    -1,   269,    -1,    -1,   272,    29,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    12,    13,
     305,    30,    31,   308,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    29,   131,    30,    -1,    -1,
      33,    34,    -1,    -1,   139,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    10,   343,   154,
      -1,    -1,    -1,   348,    17,    18,    19,    20,   163,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    30,    45,    10,
      -1,   366,    -1,   178,   179,    -1,    17,    18,    19,    20,
      11,    12,    13,    14,    -1,    -1,   191,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,    75,    76,
      31,    32,    11,    12,    13,    14,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    -1,    -1,
      29,   226,   227,   228,   229,   230,   231,   232,   233,   234,
      -1,   236,    -1,    -1,   239,    -1,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,    -1,    -1,   254,
     255,    -1,    -1,    -1,   131,    -1,     1,    -1,     3,     4,
       5,     6,   139,    -1,   269,    10,    -1,   272,    11,    12,
      13,    14,    17,    18,    19,    20,    -1,   154,     1,    -1,
       3,     4,     5,     6,    -1,    30,   163,    10,    31,    32,
      12,    13,    14,    -1,    17,    18,    19,    20,    -1,    -1,
     305,   178,   179,   308,    -1,    -1,    -1,    30,     1,    31,
       3,     4,     5,     6,   191,    -1,    -1,    10,    -1,    11,
      12,    13,    14,   200,    17,    18,    19,    20,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    30,   343,    31,
      32,    -1,    -1,   348,    -1,    -1,    -1,    -1,    29,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    45,   236,
      -1,   366,   239,    -1,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,    -1,    -1,   254,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,   269,    -1,    -1,   272,    -1,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,   305,    30,
      31,   308,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    -1,   131,    30,    -1,    -1,    33,    34,
      -1,    -1,   139,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    10,   343,   154,    -1,    -1,
      -1,   348,    17,    18,    19,    20,   163,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    30,    45,    10,    -1,   366,
      -1,   178,   179,    -1,    17,    18,    19,    20,    11,    12,
      13,    14,    -1,    -1,   191,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,   200,    -1,    -1,    75,    76,    31,    32,
      11,    12,    13,    14,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    -1,    -1,    29,   226,
     227,   228,   229,   230,   231,   232,   233,   234,    -1,   236,
      -1,    -1,   239,    -1,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,    -1,    -1,   254,   255,    -1,
      -1,    -1,   131,    -1,     1,    -1,     3,     4,     5,     6,
     139,    -1,   269,    10,    -1,   272,    11,    12,    13,    14,
      17,    18,    19,    20,    -1,   154,     1,    -1,     3,     4,
       5,     6,    -1,    30,   163,    10,    31,    32,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,    -1,   305,   178,
     179,   308,    -1,    -1,    -1,    30,     1,    -1,     3,     4,
       5,     6,   191,    -1,    -1,    10,    -1,    11,    12,    13,
      14,   200,    17,    18,    19,    20,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    30,   343,    31,    32,    -1,
      -1,   348,    -1,    -1,    -1,    -1,    29,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    45,   236,    -1,   366,
     239,    -1,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,    -1,    -1,   254,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,
     269,    -1,    -1,   272,    -1,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,   305,    30,    31,   308,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,   131,    30,    -1,    -1,    33,    34,    -1,    -1,
     139,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    10,   343,   154,    12,    13,    14,   348,
      17,    18,    19,    20,   163,     1,    -1,     3,     4,     5,
       6,    -1,    45,    30,    10,    31,    32,   366,    -1,   178,
     179,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,    -1,    30,    11,    12,    13,    14,    -1,
      -1,   200,    75,    76,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    87,    31,    89,    90,    -1,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    31,   226,   227,   228,
     229,   230,   231,   232,   233,   234,    -1,   236,    -1,    -1,
     239,    -1,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,    45,    -1,   254,   255,    -1,   131,     1,
      -1,     3,     4,     5,     6,    -1,   139,    -1,    10,    -1,
     269,    -1,    -1,   272,    -1,    17,    18,    19,    20,    -1,
      -1,   154,    -1,    75,    76,    -1,    -1,    -1,    30,    -1,
      11,    12,    13,    14,    -1,     1,    88,     3,     4,     5,
       6,    -1,    94,    -1,    10,   178,   305,    -1,    -1,   308,
      31,    17,    18,    19,    20,    -1,    -1,    -1,   191,    -1,
      11,    12,    13,    14,    30,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    45,    -1,    -1,    -1,    -1,   131,
      31,    32,    -1,    -1,   343,    29,    30,   139,    -1,   348,
      -1,    35,    -1,   226,   227,   228,   229,    -1,   231,   232,
      -1,   234,   154,   236,    75,    76,   239,   366,   241,   242,
     243,   244,    -1,   246,   247,    -1,   249,    -1,   251,    -1,
      -1,   254,   255,    94,    -1,    -1,   178,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,   269,    -1,    -1,   191,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    30,    45,    -1,    33,    34,    -1,
     131,    11,    12,    13,    14,    -1,    -1,    -1,   139,    -1,
      -1,    -1,   305,    -1,   226,   227,   228,   229,   230,   231,
     232,    31,   234,   154,   236,    75,    76,   239,    -1,   241,
     242,   243,   244,   245,   246,   247,    86,   249,    -1,   251,
      -1,    -1,   254,   255,    94,    -1,    -1,   178,    -1,    -1,
     343,    11,    12,    13,    14,   348,    -1,   269,    -1,    -1,
     191,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    31,    32,   366,    -1,    17,    18,    19,    20,    21,
      22,   131,    24,    25,    26,    27,    -1,    -1,    30,   139,
      -1,    33,    34,   305,    -1,   226,   227,   228,   229,    -1,
     231,   232,    -1,   234,   154,   236,    -1,    -1,   239,    -1,
     241,   242,   243,   244,    -1,   246,   247,    -1,   249,    -1,
     251,    45,    -1,   254,   255,    -1,    -1,    -1,   178,    -1,
      -1,   343,    45,    -1,    -1,    -1,   348,    -1,   269,    -1,
       1,   191,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    75,    76,    -1,   366,    -1,    17,    18,    19,    20,
      -1,    85,    75,    76,    -1,    11,    12,    13,    14,    30,
      94,    84,    -1,    -1,   305,    -1,   226,   227,   228,    -1,
      -1,    94,    -1,    -1,   234,    31,   236,    -1,    -1,   239,
      -1,   241,   242,   243,    11,    12,    13,    14,    -1,   249,
      -1,   251,    45,    -1,   254,   255,    -1,   131,    11,    12,
      13,    14,   343,    -1,    31,   139,    -1,   348,   131,   269,
      12,    13,    14,    -1,    -1,    -1,   139,    -1,    31,    -1,
     154,    -1,    75,    76,    -1,   366,    -1,    -1,    -1,    31,
      32,   154,    -1,    -1,    11,    12,    13,    14,    -1,    92,
      -1,    94,    -1,    -1,   178,   305,     3,     4,     5,     6,
       7,     8,    29,    10,    -1,   178,    -1,   191,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,   191,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,   131,    11,
      12,    13,    14,   343,    -1,    -1,   139,    -1,   348,    -1,
      -1,    -1,   226,   227,    -1,    -1,    -1,    29,    -1,    -1,
     234,   154,   236,   226,    -1,   239,   366,   241,   242,    -1,
      -1,   234,    -1,   236,    -1,   249,   239,   251,   241,    -1,
     254,   255,    -1,    -1,    -1,   178,   249,    -1,   251,    -1,
      -1,   254,   255,    -1,    -1,   269,    -1,    -1,   191,    10,
      11,    12,    13,    14,    15,    16,   269,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      31,    32,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,   305,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,   234,   305,   236,    -1,    -1,   239,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,   249,    10,   251,    -1,
      -1,   254,   255,    -1,    17,    18,    19,    20,    -1,   343,
      11,    12,    13,    14,   348,    -1,   269,    30,    -1,    -1,
     343,    -1,    -1,    -1,    -1,   348,    -1,    -1,    29,    -1,
      -1,    -1,   366,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,   366,     3,     4,     5,     6,     7,     8,
      -1,    10,   305,    -1,    30,    31,    32,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     9,    10,    11,    12,
      13,    14,    15,    16,     3,     4,     5,     6,     7,     8,
     343,    10,    -1,    -1,    -1,   348,    29,    30,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,   366,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    11,    12,    13,    14,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    30,    29,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    11,    12,
      13,    14,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    -1,    -1,    30,    29,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      11,    12,    13,    14,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    -1,    -1,    30,    29,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    11,    12,    13,    14,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    30,
      29,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,    30,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      30,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    30,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    30,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    -1,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    30,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,     1,    -1,     3,     4,
       5,     6,    -1,    -1,    30,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    30,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    30,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    30,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    -1,    30,    31,    -1,    -1,
      -1,    17,    18,    19,    20,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    29,    30,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    -1,    30,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,     3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,
      30,    -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    -1,    30,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    -1,    30,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    -1,    30,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,     3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,
      30,    -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    30,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    35,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,
      35,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    30,    31,
      -1,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      35,    -1,    -1,    30,    31,    -1,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      35,    -1,    -1,    30,    31,    32,     9,    10,    11,    12,
      13,    14,    15,    16,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
       9,    10,    11,    12,    13,    14,    15,    16,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,     9,    10,    11,    12,
      13,    14,    15,    16,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
       9,    10,    11,    12,    13,    14,    15,    16,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    31,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,     9,    10,    11,    12,
      13,    14,    15,    16,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      10,    11,    12,    13,    14,    15,    16,    31,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      29,    30,     9,    10,    11,    12,    13,    14,    15,    16,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
       9,    10,    11,    12,    13,    14,    15,    16,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,     9,    10,    11,    12,
      13,    14,    15,    16,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    29,    10,    11,    12,
      13,    14,    15,    16,    29,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    22,    37,    38,    39,    40,    42,    76,    23,
      23,     0,    39,     6,    29,    75,    30,    41,    43,    29,
      45,    46,    47,    76,    31,    32,    75,    44,    47,    33,
      48,    49,     3,     4,     5,     7,     8,    10,    17,    18,
      19,    20,    24,    26,    27,    30,    40,    48,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    73,    74,
      75,    76,    77,    78,    30,    30,    30,    30,     1,    59,
      59,    34,    52,    29,    13,    12,    14,    11,    10,    15,
      16,     9,    35,    68,    30,    75,    75,    59,     1,    59,
      59,    60,    29,    29,    31,     1,    62,    68,     1,    63,
       1,    64,     1,    65,     1,    67,     1,    65,     1,    65,
       1,    68,     1,    61,    59,    71,    72,    31,    31,    31,
      29,    32,    31,    29,    29,    53,    60,    59,    25,    29,
      53,    60,    31,    53,    21,    22,     6,     6,    33,     3,
       4,     5,     6,    20,    30,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    73,    74,    75,    77,    78,
       6,    29,     6,     3,     4,     5,     6,    20,    30,    69,
      70,    73,    74,    75,    77,    78,     3,     4,     5,     6,
      20,    30,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    73,    74,    75,    77,    78,    41,     7,     8,
      24,    26,    27,    33,    48,    54,    55,    56,    57,    58,
      59,    59,    23,    23,    49,    59,    13,    12,    14,    11,
      10,    15,    16,     9,    35,    68,    30,    59,    68,    30,
      59,    13,    12,    14,    11,    10,    15,    16,     9,    35,
      68,    30,    29,    30,    30,    30,    30,     1,    59,    49,
      29,    50,    31,     1,     3,     4,     5,     6,    20,    30,
      62,    68,    69,    70,    73,    74,    75,    77,    78,     1,
      63,     1,    64,     1,    65,     1,    67,     1,    65,     1,
      65,     1,    68,     1,    61,    72,    31,    72,    31,     1,
       3,     4,     5,     6,    20,    30,    62,    68,    69,    70,
      73,    74,    75,    77,    78,     1,    63,     1,    64,     1,
      65,     1,    67,     1,    65,     1,    65,     1,    68,     1,
      61,    72,    75,    59,     1,    59,    60,    29,    29,    50,
      34,    59,    68,    30,    31,    31,    59,    68,    30,    31,
      31,    31,    31,    29,    34,    31,    72,    31,    72,    29,
      29,    53,    60,    31,    31,    25,    29,    53,    60,    31,
      53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    41,    40,
      40,    43,    44,    42,    45,    45,    46,    46,    47,    49,
      48,    50,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    56,    56,    56,    57,
      57,    58,    59,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    62,    63,    63,    63,    64,    64,    64,    65,
      65,    65,    65,    65,    66,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    73,    73,    74,    75,    76,    76,
      76,    76,    77,    77,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     0,     4,
       2,     0,     0,     8,     0,     1,     3,     1,     2,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     2,     5,     7,     3,     3,
       3,     9,     1,     3,     3,     0,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     2,     1,     1,     1,     1,     1,     4,     1,     3,
       1,     0,     1,     1,     1,     3,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1
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
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (line, col, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, line, col); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, int line, int col)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (line);
  YY_USE (col);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, int line, int col)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, line, col);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, int line, int col)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), line, col);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, line, col); \
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


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          goto yyexhaustedlab;                                          \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
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

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
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
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
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
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, int line, int col)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (line);
  YY_USE (col);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_NAME: /* NAME  */
#line 77 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2605 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 77 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2611 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 77 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2617 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2623 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2629 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2635 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2641 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2647 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2653 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2659 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2665 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2671 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2677 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2683 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2689 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2695 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2701 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2707 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2713 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2719 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_1: /* @1  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2725 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2731 "src/bison/grammar.c"
        break;

    case YYSYMBOL_43_2: /* @2  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2737 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2743 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2749 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2755 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2761 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2767 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2773 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2779 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2785 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2791 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2797 "src/bison/grammar.c"
        break;

    case YYSYMBOL_60_expression_opt: /* expression.opt  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2803 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2809 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2815 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2821 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2827 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2833 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2839 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2845 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2851 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2857 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2863 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2869 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id_expr: /* id_expr  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2875 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 77 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2881 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 76 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2887 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2893 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 78 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2899 "src/bison/grammar.c"
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (int line, int col)
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 3: /* prog: %empty  */
#line 82 "src/bison/grammar.y"
             {
        yyerror(1, 1, NULL);
        CIPL_PERROR("ISO C-IPL forbids an empty translation unit\n");
    }
#line 3211 "src/bison/grammar.c"
    break;

  case 4: /* external_declaration_list: external_declaration_list external_declaration  */
#line 88 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 3217 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration  */
#line 89 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 3223 "src/bison/grammar.c"
    break;

  case 8: /* @1: %empty  */
#line 96 "src/bison/grammar.y"
                              {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-1].pchar));
        if (sym) {
            if (sym->scope) {
                yyerror((yyloc).last_line, (yyloc).last_column, NULL);
                CIPL_PERROR_CURSOR("redeclaration of '%s'\n", last_line_ref, error_cursor, (yyvsp[0].sym)->name);
            } else if (sym->is_fn) {
                yyerror((yyloc).last_line, (yyloc).last_column, NULL);
                CIPL_PERROR_CURSOR("'%s' redeclared as different kind of symbol\n", last_line_ref, error_cursor, (yyvsp[0].sym)->name);
            } else if (sym->type != decl_type) {
                yyerror((yyloc).last_line, (yyloc).last_column, NULL);
                CIPL_PERROR_CURSOR("conflicting types for '%s'\n", last_line_ref, error_cursor, (yyvsp[0].sym)->name);
            } 
            (yyval.ast) = NULL;
        }
        else {
            Symbol *declared = context_declare_variable(current_context, (yyvsp[0].sym));
            symbol_update_type(declared, decl_type);
            (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 3252 "src/bison/grammar.c"
    break;

  case 9: /* var_declaration: type id @1 ';'  */
#line 119 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 3260 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type ';'  */
#line 122 "src/bison/grammar.y"
               {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("useless '%s' in empty declaration\n", "", error_cursor, (yyvsp[-1].pchar));
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
    }
#line 3271 "src/bison/grammar.c"
    break;

  case 11: /* @2: %empty  */
#line 130 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[-1].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-2].pchar));

        // always push a context for the function even if not valid so is possible to pop later
        previous_context = current_context;
        list_push(&contexts, context_init((yyvsp[-1].sym)->name));
        current_context = list_peek_last(&contexts);

        if (sym) {
            yyerror((yyloc).last_line, (yyloc).last_column, NULL);
            if (!sym->is_fn) {
                CIPL_PERROR_CURSOR("'%s' redeclared as different kind of symbol\n", last_line_ref, error_cursor, (yyvsp[-1].sym)->name);
            } else if (sym->type != decl_type) {
                CIPL_PERROR_CURSOR("conflicting types for '%s'\n", last_line_ref, error_cursor, (yyvsp[-1].sym)->name);
            } else {
                CIPL_PERROR_CURSOR("redefinition of '%s'\n", last_line_ref, error_cursor, (yyvsp[-1].sym)->name);
            }
            (yyval.ast) = NULL;
        } else {
            Symbol *declared = context_declare_function(previous_context, (yyvsp[-1].sym));
            symbol_update_type(declared, decl_type);
            (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 3307 "src/bison/grammar.c"
    break;

  case 12: /* $@3: %empty  */
#line 160 "src/bison/grammar.y"
                         {
        LIST_FOR_EACH((yyvsp[-1].list), {
            SymbolRefAST *symref = ((AST *)__IT__->data)->value.symref;
            Symbol *sym = context_has_symbol(current_context, symref->symbol);
            if (sym) {
                yyerror((yyloc).last_line, (yyloc).last_column, NULL);
                CIPL_PERROR_CURSOR("redefinition of parameter '%s'\n", last_line_ref, error_cursor, symref->symbol->name);
            } else {
                context_declare_variable(current_context, symref->symbol);
            }
        });
        // hack to save the scope of params and append to the scope of the body
        params_scope = scope_init_copy(stack_peek(&current_context->scopes));
        stack_pop(&current_context->scopes, free_scope_cb);
    }
#line 3327 "src/bison/grammar.c"
    break;

  case 13: /* func_declaration: type id '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 174 "src/bison/grammar.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 3336 "src/bison/grammar.c"
    break;

  case 14: /* param_list.opt: %empty  */
#line 180 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 3342 "src/bison/grammar.c"
    break;

  case 16: /* params_list: params_list ',' param_decl  */
#line 184 "src/bison/grammar.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3348 "src/bison/grammar.c"
    break;

  case 17: /* params_list: param_decl  */
#line 185 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3354 "src/bison/grammar.c"
    break;

  case 18: /* param_decl: type id  */
#line 188 "src/bison/grammar.y"
                    {
        symbol_update_context((yyvsp[0].sym), current_context);
        symbol_update_type((yyvsp[0].sym), symbol_type_from_str((yyvsp[-1].pchar)));
        (yyval.ast) = ast_symref_init(symbol_init_copy((yyvsp[0].sym)));
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 3366 "src/bison/grammar.c"
    break;

  case 19: /* $@4: %empty  */
#line 197 "src/bison/grammar.y"
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
#line 3382 "src/bison/grammar.c"
    break;

  case 20: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 207 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 3394 "src/bison/grammar.c"
    break;

  case 21: /* block_item_list.opt: block_item_list  */
#line 216 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 3400 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list.opt: %empty  */
#line 217 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3406 "src/bison/grammar.c"
    break;

  case 23: /* block_item_list: block_item_list block_item  */
#line 220 "src/bison/grammar.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3412 "src/bison/grammar.c"
    break;

  case 24: /* block_item_list: block_item  */
#line 221 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3418 "src/bison/grammar.c"
    break;

  case 33: /* io_stmt: READ '(' id ')' ';'  */
#line 236 "src/bison/grammar.y"
                             {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(func)), ast_symref_init(symbol_init_copy(param)));
        symbol_free((yyvsp[-4].sym));
        symbol_free((yyvsp[-2].sym));
    }
#line 3430 "src/bison/grammar.c"
    break;

  case 34: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 243 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(sym)), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 3440 "src/bison/grammar.c"
    break;

  case 35: /* expr_stmt: expression ';'  */
#line 250 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 3446 "src/bison/grammar.c"
    break;

  case 36: /* cond_stmt: IF '(' expression ')' statement  */
#line 253 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 3454 "src/bison/grammar.c"
    break;

  case 37: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 256 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3462 "src/bison/grammar.c"
    break;

  case 38: /* cond_stmt: IF '(' error  */
#line 259 "src/bison/grammar.y"
                   {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ‘)’ token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 3473 "src/bison/grammar.c"
    break;

  case 39: /* jmp_stmt: RETURN expression ';'  */
#line 267 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 3479 "src/bison/grammar.c"
    break;

  case 40: /* jmp_stmt: RETURN error ';'  */
#line 268 "src/bison/grammar.y"
                       {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("'return' with no value\n", "", error_cursor);
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 3490 "src/bison/grammar.c"
    break;

  case 41: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 276 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3498 "src/bison/grammar.c"
    break;

  case 43: /* expression: unary_expr '=' logical_or_expr  */
#line 282 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3504 "src/bison/grammar.c"
    break;

  case 44: /* expression: unary_expr '=' error  */
#line 283 "src/bison/grammar.y"
                           {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ‘;’ token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3516 "src/bison/grammar.c"
    break;

  case 45: /* expression.opt: %empty  */
#line 292 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 3522 "src/bison/grammar.c"
    break;

  case 48: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 297 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3531 "src/bison/grammar.c"
    break;

  case 49: /* logical_or_expr: logical_or_expr OR error  */
#line 301 "src/bison/grammar.y"
                               {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ';' token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3544 "src/bison/grammar.c"
    break;

  case 51: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 312 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3553 "src/bison/grammar.c"
    break;

  case 52: /* logical_and_expr: logical_and_expr AND error  */
#line 316 "src/bison/grammar.y"
                                 {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ';' token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3566 "src/bison/grammar.c"
    break;

  case 54: /* eq_expr: eq_expr EQ rel_expr  */
#line 327 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3575 "src/bison/grammar.c"
    break;

  case 55: /* eq_expr: eq_expr EQ error  */
#line 331 "src/bison/grammar.y"
                       {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ';' token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3588 "src/bison/grammar.c"
    break;

  case 57: /* rel_expr: rel_expr REL list_expr  */
#line 342 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3597 "src/bison/grammar.c"
    break;

  case 58: /* rel_expr: rel_expr REL error  */
#line 346 "src/bison/grammar.y"
                         {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ';' token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3610 "src/bison/grammar.c"
    break;

  case 60: /* list_expr: add_expr DL_DG list_expr  */
#line 357 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3619 "src/bison/grammar.c"
    break;

  case 61: /* list_expr: add_expr COLON list_expr  */
#line 361 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3628 "src/bison/grammar.c"
    break;

  case 62: /* list_expr: add_expr DL_DG error  */
#line 365 "src/bison/grammar.y"
                           {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ';' token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3641 "src/bison/grammar.c"
    break;

  case 63: /* list_expr: add_expr COLON error  */
#line 373 "src/bison/grammar.y"
                           {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ';' token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3654 "src/bison/grammar.c"
    break;

  case 65: /* add_expr: add_expr ADD mult_expr  */
#line 384 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3663 "src/bison/grammar.c"
    break;

  case 66: /* add_expr: add_expr ADD error  */
#line 388 "src/bison/grammar.y"
                         {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ';' token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3676 "src/bison/grammar.c"
    break;

  case 68: /* mult_expr: mult_expr MULT unary_expr  */
#line 399 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3685 "src/bison/grammar.c"
    break;

  case 69: /* mult_expr: mult_expr MULT error  */
#line 403 "src/bison/grammar.y"
                           {
        yyerror((yyloc).last_line, (yyloc).last_column, NULL);
        CIPL_PERROR_CURSOR("expected expression before ';' token\n", last_line_ref, error_cursor);
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3698 "src/bison/grammar.c"
    break;

  case 71: /* unary_expr: unary_ops unary_expr  */
#line 414 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3707 "src/bison/grammar.c"
    break;

  case 77: /* postfix_expr: id_expr '(' arg_expr_list.opt ')'  */
#line 427 "src/bison/grammar.y"
                                        {
        (yyval.ast) = ast_funcall_init((yyvsp[-3].ast), ast_params_init((yyvsp[-1].list)));
    }
#line 3715 "src/bison/grammar.c"
    break;

  case 78: /* arg_expr_list: expression  */
#line 432 "src/bison/grammar.y"
                          { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3721 "src/bison/grammar.c"
    break;

  case 79: /* arg_expr_list: arg_expr_list ',' expression  */
#line 433 "src/bison/grammar.y"
                                   { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3727 "src/bison/grammar.c"
    break;

  case 81: /* arg_expr_list.opt: %empty  */
#line 437 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3733 "src/bison/grammar.c"
    break;

  case 85: /* primary_expr: '(' expression ')'  */
#line 443 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 3739 "src/bison/grammar.c"
    break;

  case 86: /* id_expr: id  */
#line 446 "src/bison/grammar.y"
            {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[0].sym));
        if (!sym) {
            yyerror((yyloc).last_line, (yyloc).last_column, NULL);
            CIPL_PERROR_CURSOR("'%s' undeclared (first use in this function)\n", last_line_ref, error_cursor, (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        }   else {
            symbol_update_context((yyvsp[0].sym), current_context);
            (yyval.ast) = ast_symref_init(symbol_init_copy(sym ? sym : (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
    }
#line 3756 "src/bison/grammar.c"
    break;

  case 90: /* type: INT LIST  */
#line 465 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3768 "src/bison/grammar.c"
    break;

  case 91: /* type: FLOAT LIST  */
#line 472 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3780 "src/bison/grammar.c"
    break;

  case 92: /* constant: NUMBER_REAL  */
#line 481 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 3786 "src/bison/grammar.c"
    break;

  case 93: /* constant: NUMBER_INT  */
#line 482 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3792 "src/bison/grammar.c"
    break;

  case 94: /* constant: NIL  */
#line 483 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3798 "src/bison/grammar.c"
    break;

  case 95: /* string_literal: STR_LITERAL  */
#line 486 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 3807 "src/bison/grammar.c"
    break;


#line 3811 "src/bison/grammar.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  *++yylsp = yyloc;

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
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
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
        yyerror (line, col, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, line, col);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, line, col);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (line, col, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, line, col);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, line, col);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 492 "src/bison/grammar.y"


void yyerror(int l, int c, const char *s, ...) {
    error_cursor = (cursor_position){.line=l, .col=c};
    last_line_ref = curr_line;
    // enable error print when bison calls yyerror()
    /* if (s) CIPL_PERROR_CURSOR("%s\n", last_line_ref, error_cursor, s); */
    // prevent count up errors when bison calls yyerror()
    if (!s) {
        ++errors_count;
    }
}
