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
#line 4 "src/bison/grammar.y"

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
  YYSYMBOL_external_declaration = 38,      /* external_declaration  */
  YYSYMBOL_var_declaration = 39,           /* var_declaration  */
  YYSYMBOL_40_1 = 40,                      /* @1  */
  YYSYMBOL_func_declaration = 41,          /* func_declaration  */
  YYSYMBOL_42_2 = 42,                      /* @2  */
  YYSYMBOL_43_3 = 43,                      /* $@3  */
  YYSYMBOL_44_param_list_opt = 44,         /* param_list.opt  */
  YYSYMBOL_params_list = 45,               /* params_list  */
  YYSYMBOL_param_decl = 46,                /* param_decl  */
  YYSYMBOL_compound_stmt = 47,             /* compound_stmt  */
  YYSYMBOL_48_4 = 48,                      /* $@4  */
  YYSYMBOL_49_block_item_list_opt = 49,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 50,           /* block_item_list  */
  YYSYMBOL_block_item = 51,                /* block_item  */
  YYSYMBOL_statement = 52,                 /* statement  */
  YYSYMBOL_io_stmt = 53,                   /* io_stmt  */
  YYSYMBOL_expr_stmt = 54,                 /* expr_stmt  */
  YYSYMBOL_cond_stmt = 55,                 /* cond_stmt  */
  YYSYMBOL_jmp_stmt = 56,                  /* jmp_stmt  */
  YYSYMBOL_iter_stmt = 57,                 /* iter_stmt  */
  YYSYMBOL_expression = 58,                /* expression  */
  YYSYMBOL_59_expression_opt = 59,         /* expression.opt  */
  YYSYMBOL_logical_or_expr = 60,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 61,          /* logical_and_expr  */
  YYSYMBOL_eq_expr = 62,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 63,                  /* rel_expr  */
  YYSYMBOL_list_expr = 64,                 /* list_expr  */
  YYSYMBOL_add_expr = 65,                  /* add_expr  */
  YYSYMBOL_mult_expr = 66,                 /* mult_expr  */
  YYSYMBOL_unary_expr = 67,                /* unary_expr  */
  YYSYMBOL_unary_ops = 68,                 /* unary_ops  */
  YYSYMBOL_postfix_expr = 69,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 70,             /* arg_expr_list  */
  YYSYMBOL_71_arg_expr_list_opt = 71,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 72,              /* primary_expr  */
  YYSYMBOL_id_expr = 73,                   /* id_expr  */
  YYSYMBOL_id = 74,                        /* id  */
  YYSYMBOL_type = 75,                      /* type  */
  YYSYMBOL_constant = 76,                  /* constant  */
  YYSYMBOL_string_literal = 77             /* string_literal  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4304

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  337

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
       0,    74,    74,    75,    78,    79,    82,    82,   101,   109,
     134,   109,   149,   150,   153,   154,   157,   166,   166,   186,
     187,   190,   191,   194,   195,   198,   199,   200,   201,   202,
     203,   206,   213,   220,   223,   226,   231,   234,   239,   240,
     243,   244,   247,   248,   254,   255,   261,   262,   268,   269,
     275,   276,   280,   286,   287,   293,   294,   300,   301,   307,
     308,   309,   310,   313,   314,   319,   320,   323,   324,   327,
     328,   329,   330,   333,   347,   350,   351,   352,   359,   368,
     369,   370,   373
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
  "NUMBER_REAL", "NAME", "READ", "WRITE", "MULT", "ADD", "REL", "AND",
  "OR", "EQ", "COLON", "DL_DG", "EXCLAMATION", "PERCENT", "QUESTION",
  "STR_LITERAL", "INT", "FLOAT", "LIST", "IF", "ELSE", "FOR", "RETURN",
  "THEN", "';'", "'('", "')'", "','", "'{'", "'}'", "'='", "$accept",
  "prog", "external_declaration", "var_declaration", "@1",
  "func_declaration", "@2", "$@3", "param_list.opt", "params_list",
  "param_decl", "compound_stmt", "$@4", "block_item_list.opt",
  "block_item_list", "block_item", "statement", "io_stmt", "expr_stmt",
  "cond_stmt", "jmp_stmt", "iter_stmt", "expression", "expression.opt",
  "logical_or_expr", "logical_and_expr", "eq_expr", "rel_expr",
  "list_expr", "add_expr", "mult_expr", "unary_expr", "unary_ops",
  "postfix_expr", "arg_expr_list", "arg_expr_list.opt", "primary_expr",
  "id_expr", "id", "type", "constant", "string_literal", YY_NULLPTR
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
     275,   276,   277,   278,   279,   280,   281,   282,   283,    59,
      40,    41,    44,   123,   125,    61
};
#endif

#define YYPACT_NINF (-221)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-83)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,    -1,     3,    33,    65,    88,   124,     6,    11,    19,
    -221,   135,   103,   141,   168,    -8,   -13,    76,   147,   -10,
     235,   287,    28,    23,   305,   370,    29,   379,  2196,   160,
    2272,  2025,  3218,  3226,    62,    97,    54,   733,   911,  1089,
    3253,   106,   125,  1267,  1445,  2304,  2336,    15,  2368,  2400,
    2432,  2464,  2496,  2528,  2560,  2592,    66,    32,   291,   589,
     330,   383,  4266,  2245,  3261,  1267,  3288,  3296,  1845,  2113,
      21,  3323,  3331,   161,  1445,  1445,   555,   154,   139,   220,
    2624,  2656,  1557,  1557,  1557,  1557,  1557,  1557,  1557,  1557,
    1557,  3358,   134,   165,   170,   174,   199,   215,   225,  2688,
    3366,   395,  4080,   624,  1432,  1460,  4101,  1595,  1605,  4109,
      92,   396,   416,   227,   233,   243,    96,   555,  1585,  3393,
    2720,  2752,   343,   247,   456,   169,   265,  2784,   263,   169,
    2816,   119,   155,   460,  2938,  2196,  3401,  3428,  3436,  2946,
    3463,  1445,    16,   172,    39,   373,   913,  2125,  3802,  3471,
    1445,  3498,  3506,  2973,  2981,  3533,  3541,   272,  2848,   280,
    4130,  4138,  4159,  4042,  4167,  1445,  1557,  4188,  4196,  4050,
    4072,  4217,  4225,  3008,  3016,  3043,  1882,  3051,  1445,    99,
     359,   926,   267,   277,  1800,   441,  3078,  1585,  3086,  3113,
    2053,  2237,  3121,  3148,   285,   234,   294,   299,   309,  1267,
    2196,   412,   516,   590,   694,   768,   872,   292,   314,   346,
     348,  2272,   347,  1633,  1633,  1633,  1633,  1633,  1633,  1633,
    1633,  1633,  3568,   134,   372,  4246,   134,   390,  1779,  1779,
    1779,  1779,  1779,  1779,  1779,  1779,  1779,  3156,   134,  2880,
     161,  1445,  1445,   555,   394,  2272,   946,   391,  3576,  3825,
    3833,  3856,  3763,  3864,  1445,   274,  3887,  1633,  3895,  3918,
    3771,  3794,  3926,  3949,   344,  1091,  1104,  3957,  1269,  1282,
    3980,    77,   413,  4254,   418,  3183,   619,   797,   975,  3611,
    1153,  1445,   428,  1331,  1779,  1509,  1729,  3635,  3643,  1892,
    3667,  1446,   368,   557,  3675,   735,   748,  3699,   205,   427,
     444,   454,   462,   414,  1050,   461,  2912,   463,  3988,   134,
    3603,  4275,   465,  3707,   134,  3191,   468,   469,    96,   555,
    1124,  4011,   472,  3731,   473,  1228,  1302,  1406,   470,  4019,
    3739,    96,   265,  1480,   475,    96,  1661
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
    -221,  -221,   504,    93,   424,  -221,  -221,  -221,  -221,  -221,
     501,   -25,  -131,  -203,  -221,   479,   -86,   -80,   -78,   -75,
     -72,   -70,    74,  -115,  1956,  1931,  1877,  1744,  1494,  1712,
    1536,   248,   426,   604,  -221,  -220,   782,   960,    -7,     7,
    1138,  1316
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,    45,    16,     6,    17,    26,    19,    20,
      21,    46,    30,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    98,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   112,   113,    67,    68,    69,    70,
      71,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    29,   123,   272,   211,   -75,   274,     7,   247,   -76,
       7,   128,    12,    -9,    -9,    25,    18,   -77,   299,     1,
       2,    23,     8,    -9,    22,   -78,     9,   157,   -75,   213,
     122,    22,   -76,    10,   133,    13,   202,   154,   203,   127,
     -77,   204,   305,   130,   205,    82,   206,   -38,   -78,    79,
     158,   -44,   -44,   215,     1,     2,   -10,   -61,   -61,   -61,
     -61,   -38,    28,    93,   -61,    -3,    94,   154,   154,   245,
     -44,   -61,   -61,   -61,   -61,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   -61,   191,    -3,    -3,    -5,   322,
     213,   201,    73,     5,   324,    81,     5,   131,   132,    31,
      32,    33,   134,   195,   196,    82,    36,   -12,   -39,    -5,
      -5,   191,   228,    37,    38,    39,    40,    77,    78,   154,
     197,   -39,   198,   199,    -4,   -75,    44,    74,   303,   200,
     -38,   -38,   -74,   -74,   154,    -2,    75,   173,   174,   175,
     176,    -8,   209,   154,    36,    -4,    -4,    -7,    95,    96,
      97,    37,    38,    39,   177,    76,    -2,    -2,   154,   170,
     -11,   -76,    -8,    -8,   178,   -68,   111,   159,    -7,    -7,
     100,   154,    31,    32,    33,   134,    34,    35,   210,    36,
     191,   -11,   -11,    99,   214,   -42,    37,    38,    39,    40,
     207,    97,   124,    41,    -6,    42,    43,    -6,    15,    44,
     208,   114,   135,   -42,   328,   115,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   212,   191,   334,   228,   191,
     -18,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     116,   191,   327,   300,   154,   154,   -39,   -39,   202,   224,
     203,   -18,   -18,   204,   -41,   333,   205,   154,   206,   336,
     261,   202,   227,   203,   117,   202,   204,   203,   119,   205,
     204,   206,   120,   205,   240,   206,   -13,    24,   136,   137,
     138,   139,   121,   244,   154,    36,   126,   288,   231,   -46,
     -46,   -46,    37,    38,    39,   140,   214,   -43,   -48,   -48,
     -48,   -48,   149,   201,   129,   141,   -40,   111,   -46,   -46,
     111,   -74,   191,    83,   -42,   -43,   201,   191,   -48,   -48,
     201,   -74,   111,    91,   239,   301,   302,    97,   -15,   -15,
     -42,   246,   149,   149,   241,   154,   131,   132,   307,   242,
     102,   102,   102,   102,   102,   102,   102,   109,   102,   243,
     186,    85,   -46,   -46,   -46,   -41,   -34,   -34,   -34,   -34,
     -34,   -34,   -77,   -34,   -78,   312,   -45,   -45,   215,   -46,
     -34,   -34,   -34,   -34,   -34,   -34,   186,   -34,   125,   -34,
     -34,   229,   -42,   -34,   149,   -45,   -34,   -34,   248,   231,
     -47,   -47,   -47,   111,   216,   -46,   -46,   -46,   111,   149,
     -42,   -42,   207,    97,   -48,   -48,   -48,   -48,   222,   -47,
     -47,   -16,   -16,   273,   -46,   207,   208,    83,   -43,   207,
     -14,   -14,   -48,   149,   225,   -26,   -26,   -26,   -26,   -26,
     -26,   275,   -26,   304,   -43,   306,   149,   -65,   -65,   -26,
     -26,   -26,   -26,   -26,   -26,   237,   -26,   -26,   -26,   -26,
     229,   -43,   -26,   319,   310,   -26,   -26,   -67,   118,   311,
     235,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   315,   -43,
     -43,   256,   256,   256,   256,   256,   256,   256,   270,   256,
     150,   186,   -53,   -53,   186,   316,   283,   283,   283,   283,
     283,   283,   283,   297,   283,   317,   186,   -66,   -66,   149,
     149,   -74,   -74,   318,   321,   320,   323,   325,   326,   332,
     150,   150,   149,   329,   330,   308,   335,    11,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   194,   187,   -30,
     -30,   -30,   -30,   -30,   -30,    27,   -30,    80,     0,   149,
       0,     0,   313,   -30,   -30,   -30,   -30,   -30,   -30,     0,
     -30,   -30,   -30,   -30,   187,     0,   -30,     0,     0,   -30,
     -30,     0,   150,     0,     0,     0,     0,   186,    31,    32,
      33,   134,   186,     0,     0,    36,     0,   150,   -49,   -49,
     -49,   -49,    37,    38,    39,    40,   150,     0,     0,     0,
     149,     0,     0,     0,   -40,    44,     0,     0,   -49,   -49,
       0,   150,   166,   -25,   -25,   -25,   -25,   -25,   -25,     0,
     -25,   -44,   -44,    84,   150,     0,     0,   -25,   -25,   -25,
     -25,   -25,   -25,   187,   -25,   -25,   -25,   -25,   -44,     0,
     -25,     0,     0,   -25,   -25,     0,     0,     0,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -45,   -45,    84,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   151,   187,
     -80,   -80,   187,   -45,   284,   284,   284,   284,   284,   284,
     284,   284,   284,     0,   187,     0,     0,   150,   150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,   151,
     150,     0,     0,   257,     0,     0,   167,   167,   167,   167,
     167,   167,   167,   167,   167,     0,   188,   -27,   -27,   -27,
     -27,   -27,   -27,     0,   -27,     0,     0,   150,     0,     0,
     284,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,
     -27,   -27,   188,     0,   -27,     0,     0,   -27,   -27,     0,
     151,     0,     0,     0,     0,   187,   -59,   -59,   -59,   -59,
     187,     0,     0,   -59,     0,   151,   -52,   -52,   -52,   -52,
     -59,   -59,   -59,   -59,   151,     0,     0,     0,   150,   -51,
     -51,   -51,   -51,   -59,     0,     0,   -52,   -52,     0,   151,
     167,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,   -51,
     -51,     0,   151,     0,     0,   -28,   -28,   -28,   -28,   -28,
     -28,   188,   -28,   -28,   -28,   -28,     0,     0,   -28,     0,
       0,   -28,   -28,     0,     0,     0,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,     0,     0,     0,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   152,   188,   -81,   -81,
     188,     0,   285,   285,   285,   285,   285,   285,   285,   285,
     285,     0,   188,     0,     0,   151,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,   152,   151,     0,
       0,   258,     0,     0,   168,   168,   168,   168,   168,   168,
     168,   168,   168,     0,   189,   -29,   -29,   -29,   -29,   -29,
     -29,     0,   -29,     0,     0,   151,     0,     0,   285,   -29,
     -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,   -29,   -29,
     189,     0,   -29,     0,     0,   -29,   -29,     0,   152,     0,
       0,     0,     0,   188,   -60,   -60,   -60,   -60,   188,     0,
       0,   -60,     0,   152,   -48,   -48,   -48,   -48,   -60,   -60,
     -60,   -60,   152,     0,     0,     0,   151,     0,   -44,   -44,
     230,   -60,     0,     0,   -48,     0,     0,   152,   168,   -33,
     -33,   -33,   -33,   -33,   -33,     0,   -33,   -44,   -44,     0,
     152,     0,     0,   -33,   -33,   -33,   -33,   -33,   -33,   189,
     -33,   -33,   -33,   -33,     0,     0,   -33,     0,     0,   -33,
     -33,     0,     0,     0,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,     0,     0,     0,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   153,   189,   -79,   -79,   189,     0,
     286,   286,   286,   286,   286,   286,   286,   286,   286,     0,
     189,     0,     0,   152,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   153,   152,     0,     0,   259,
       0,     0,   169,   169,   169,   169,   169,   169,   169,   169,
     169,     0,   190,   -36,   -36,   -36,   -36,   -36,   -36,     0,
     -36,     0,     0,   152,     0,     0,   286,   -36,   -36,   -36,
     -36,   -36,   -36,     0,   -36,   -36,   -36,   -36,   190,     0,
     -36,     0,     0,   -36,   -36,     0,   153,     0,     0,     0,
       0,   189,   -62,   -62,   -62,   -62,   189,     0,     0,   -62,
       0,   153,   216,   -47,   -47,   -47,   -62,   -62,   -62,   -62,
     153,     0,     0,     0,   152,   -49,   -49,   -49,   -49,   -62,
       0,     0,   -47,     0,     0,   153,   169,   -18,   -18,   -18,
     -18,   -18,   -18,     0,   -18,   -49,     0,     0,   153,     0,
       0,   -18,   -18,   -18,   -18,   -18,   -18,   190,   -18,   -18,
     -18,   -18,     0,     0,   -18,     0,     0,   -18,   -18,     0,
       0,     0,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
       0,     0,     0,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   155,   190,   -82,   -82,   190,     0,   287,   287,
     287,   287,   287,   287,   287,   287,   287,     0,   190,     0,
       0,   153,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   155,   153,     0,     0,   260,     0,     0,
     171,   171,   171,   171,   171,   171,   171,   171,   171,     0,
     192,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,     0,
       0,   153,     0,     0,   287,   -31,   -31,   -31,   -31,   -31,
     -31,     0,   -31,   -31,   -31,   -31,   192,     0,   -31,     0,
       0,   -31,   -31,     0,   155,     0,     0,     0,     0,   190,
      31,    32,    33,   134,   190,     0,     0,    36,     0,   155,
     -52,   -52,   -52,   -52,    37,    38,    39,    40,   155,     0,
       0,     0,   153,   -51,   -51,   -51,   -51,    44,     0,     0,
     -52,     0,     0,   155,   171,   -32,   -32,   -32,   -32,   -32,
     -32,     0,   -32,   -51,     0,     0,   155,     0,     0,   -32,
     -32,   -32,   -32,   -32,   -32,   192,   -32,   -32,   -32,   -32,
       0,     0,   -32,     0,     0,   -32,   -32,     0,     0,     0,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     156,   192,   -55,   -55,   192,     0,   289,   289,   289,   289,
     289,   289,   289,   289,   289,     0,   192,     0,     0,   155,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     156,   156,   155,     0,     0,   262,     0,     0,   172,   172,
     172,   172,   172,   172,   172,   172,   172,     0,   193,   -34,
     -34,   -34,   -34,   -34,   -34,     0,   -34,     0,     0,   155,
       0,     0,   289,   -34,   -34,   -34,   -34,   -34,   -34,     0,
     -34,   331,   -34,   -34,   193,     0,   -34,     0,     0,   -34,
     -34,     0,   156,    85,   -47,   -47,   -47,   192,   136,   137,
     138,   139,   192,     0,     0,    36,     0,   156,   -45,   -45,
     230,   -47,    37,    38,    39,   140,   156,     0,     0,     0,
     155,   -49,   -49,   -49,   -49,   141,     0,   -45,   -45,     0,
       0,   156,   172,   -35,   -35,   -35,   -35,   -35,   -35,   -49,
     -35,     0,     0,     0,   156,     0,     0,   -35,   -35,   -35,
     -35,   -35,   -35,   193,   -35,   -35,   -35,   -35,     0,     0,
     -35,     0,     0,   -35,   -35,     0,     0,     0,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   146,   193,
     -57,   -57,   193,     0,   290,   290,   290,   290,   290,   290,
     290,   290,   290,     0,   193,     0,     0,   156,   156,     0,
     160,   161,   162,   163,     0,     0,     0,    36,   146,   146,
     156,     0,     0,   263,    37,    38,    39,   164,     0,   105,
     148,   107,   108,     0,     0,     0,   183,   165,   173,   174,
     175,   176,     0,     0,     0,    36,     0,   156,     0,     0,
     290,     0,    37,    38,    39,   177,   -52,   -52,   -52,   -52,
     148,   148,   183,     0,     0,   178,   -51,   -51,   -51,   -51,
     146,     0,   106,     0,   -52,   193,     0,     0,   185,     0,
     193,     0,     0,     0,   -51,   146,   249,   250,   251,   252,
       0,     0,     0,    36,     0,     0,     0,     0,   156,     0,
      37,    38,    39,   253,   185,     0,     0,     0,     0,   146,
       0,     0,   148,   254,   -37,   -37,   -37,   -37,   -37,   -37,
       0,   -37,   146,     0,     0,     0,     0,   148,   -37,   -37,
     -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,   -37,     0,
       0,   -37,     0,     0,   -37,   -37,     0,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,   146,   146,   146,
     266,     0,   268,   269,   148,   146,     0,   183,     0,     0,
     183,     0,   183,   183,   183,   293,     0,   295,   296,     0,
     183,     0,   183,     0,     0,   146,   146,     0,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,     0,     0,   146,   148,
     148,   148,   148,   267,   148,   148,   147,   148,     0,   185,
     -63,   -63,   185,     0,   185,   185,   185,   185,   294,   185,
     185,     0,   185,     0,   185,   146,     0,   148,   148,     0,
       0,     0,   276,   277,   278,   279,   147,   147,   145,    36,
     148,     0,     0,     0,     0,     0,    37,    38,    39,   280,
       0,     0,     0,   183,   184,     0,     0,     0,   183,   281,
     232,   -50,   -50,   -50,   -50,   233,   234,   148,   145,   145,
       0,     0,     0,     0,     0,     0,   146,     0,   104,     0,
     184,   -50,   -50,     0,     0,     0,   182,     0,   147,     0,
       0,     0,     0,     0,     0,   185,     0,     0,     0,     0,
     185,     0,     0,   147,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   182,     0,     0,     0,     0,     0,   148,     0,
     145,     0,     0,     0,   -69,    92,     0,   147,     0,     0,
     -69,     0,     0,     0,     0,   145,     0,     0,     0,     0,
     147,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,
       0,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   145,
       0,     0,   -74,   -74,   -74,     0,     0,   -74,     0,     0,
       0,   144,   145,   -70,   -70,   147,   147,   147,   147,     0,
     147,   147,     0,   147,     0,   184,     0,     0,   184,     0,
     184,   184,   184,   184,     0,   184,   184,     0,   184,     0,
     184,   144,   144,   147,   147,     0,     0,   145,   145,   265,
     103,     0,     0,     0,     0,   145,   147,   182,     0,   181,
     182,     0,   182,   182,   292,   143,     0,     0,     0,     0,
     182,     0,   182,     0,     0,   145,   145,     0,     0,     0,
       0,     0,     0,   147,     0,   181,     0,     0,   145,     0,
     142,     0,     0,   144,     0,   143,   143,     0,     0,     0,
       0,     0,     0,   101,     0,     0,     0,     0,   144,     0,
       0,   184,     0,   180,     0,   145,   184,     0,     0,     0,
     142,   142,     0,     0,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   144,     0,   147,     0,   110,     0,   179,   180,
       0,     0,     0,   182,   -80,   144,     0,   143,   182,     0,
     -80,     0,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
       0,     0,   143,     0,   179,     0,   145,     0,     0,     0,
       0,     0,   142,   238,   -69,   -69,     0,     0,   -69,     0,
     144,   264,     0,     0,     0,     0,   143,   142,   144,     0,
     181,     0,     0,   181,     0,   181,   291,     0,     0,   143,
       0,     0,     0,   181,     0,   181,     0,     0,   144,   144,
       0,   142,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
       0,   144,     0,     0,   142,   217,   -50,   -50,   -50,   -50,
     218,   219,   -73,   -73,   255,     0,     0,     0,   -73,     0,
       0,     0,   143,     0,   180,     0,   -50,   180,   144,   282,
       0,     0,     0,     0,     0,     0,     0,   180,     0,   180,
       0,     0,   143,   143,     0,     0,     0,   271,     0,   179,
       0,     0,   179,     0,     0,   143,   181,     0,     0,     0,
       0,   181,   298,     0,   179,     0,     0,   142,   142,   -17,
     -17,   -17,   -17,   -17,   -17,     0,   -17,     0,     0,   144,
     142,     0,   143,   -17,   -17,   -17,   -17,   -17,   -17,     0,
     -17,     0,   -17,   -17,     0,     0,   -17,     0,     0,   -17,
     -17,     0,     0,     0,     0,     0,     0,   142,     0,     0,
     180,     0,     0,     0,     0,   180,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,    89,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,     0,   143,     0,   179,     0,   -73,   -73,   -73,
     179,     0,   -73,     0,   -53,    31,    32,    33,   134,    34,
      35,     0,    36,     0,     0,     0,     0,     0,   142,    37,
      38,    39,    40,     1,     2,     0,    41,     0,    42,    43,
       0,     0,    44,     0,     0,   135,   -20,   -23,   -23,   -23,
     -23,   -23,   -23,     0,   -23,     0,     0,     0,     0,     0,
       0,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,     0,
     -23,   -23,     0,     0,   -23,     0,     0,   -23,   -23,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,     0,     0,     0,
       0,     0,     0,   -26,   -26,   -26,   -26,   -26,   -26,     0,
     -26,     0,   -26,   -26,     0,     0,   -26,     0,     0,   -26,
     -26,    31,    32,    33,   134,    34,    35,     0,    36,     0,
       0,     0,     0,     0,     0,    37,    38,    39,    40,     1,
       2,     0,    41,     0,    42,    43,     0,     0,    44,     0,
       0,   135,   -19,   -22,   -22,   -22,   -22,   -22,   -22,     0,
     -22,     0,     0,     0,     0,     0,     0,   -22,   -22,   -22,
     -22,   -22,   -22,     0,   -22,     0,   -22,   -22,     0,     0,
     -22,     0,     0,   -22,   -22,   -24,   -24,   -24,   -24,   -24,
     -24,     0,   -24,     0,     0,     0,     0,     0,     0,   -24,
     -24,   -24,   -24,   -24,   -24,     0,   -24,     0,   -24,   -24,
       0,     0,   -24,     0,     0,   -24,   -24,   -30,   -30,   -30,
     -30,   -30,   -30,     0,   -30,     0,     0,     0,     0,     0,
       0,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,     0,
     -30,   -30,     0,     0,   -30,     0,     0,   -30,   -30,   -25,
     -25,   -25,   -25,   -25,   -25,     0,   -25,     0,     0,     0,
       0,     0,     0,   -25,   -25,   -25,   -25,   -25,   -25,     0,
     -25,     0,   -25,   -25,     0,     0,   -25,     0,     0,   -25,
     -25,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,     0,
       0,     0,     0,     0,     0,   -27,   -27,   -27,   -27,   -27,
     -27,     0,   -27,     0,   -27,   -27,     0,     0,   -27,     0,
       0,   -27,   -27,   -28,   -28,   -28,   -28,   -28,   -28,     0,
     -28,     0,     0,     0,     0,     0,     0,   -28,   -28,   -28,
     -28,   -28,   -28,     0,   -28,     0,   -28,   -28,     0,     0,
     -28,     0,     0,   -28,   -28,   -29,   -29,   -29,   -29,   -29,
     -29,     0,   -29,     0,     0,     0,     0,     0,     0,   -29,
     -29,   -29,   -29,   -29,   -29,     0,   -29,     0,   -29,   -29,
       0,     0,   -29,     0,     0,   -29,   -29,   -21,   -21,   -21,
     -21,   -21,   -21,     0,   -21,     0,     0,     0,     0,     0,
       0,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,     0,
     -21,   -21,     0,     0,   -21,     0,     0,   -21,   -21,   -33,
     -33,   -33,   -33,   -33,   -33,     0,   -33,     0,     0,     0,
       0,     0,     0,   -33,   -33,   -33,   -33,   -33,   -33,     0,
     -33,     0,   -33,   -33,     0,     0,   -33,     0,     0,   -33,
     -33,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,     0,
       0,     0,     0,     0,     0,   -36,   -36,   -36,   -36,   -36,
     -36,     0,   -36,     0,   -36,   -36,     0,     0,   -36,     0,
       0,   -36,   -36,   -31,   -31,   -31,   -31,   -31,   -31,     0,
     -31,     0,     0,     0,     0,     0,     0,   -31,   -31,   -31,
     -31,   -31,   -31,     0,   -31,     0,   -31,   -31,     0,     0,
     -31,     0,     0,   -31,   -31,   -32,   -32,   -32,   -32,   -32,
     -32,     0,   -32,     0,     0,     0,     0,     0,     0,   -32,
     -32,   -32,   -32,   -32,   -32,     0,   -32,     0,   -32,   -32,
       0,     0,   -32,     0,     0,   -32,   -32,   -35,   -35,   -35,
     -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,     0,
       0,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,     0,
     -35,   -35,     0,     0,   -35,     0,     0,   -35,   -35,   -37,
     -37,   -37,   -37,   -37,   -37,     0,   -37,     0,     0,     0,
       0,     0,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,
     -37,     0,   -37,   -37,     0,     0,   -37,     0,     0,   -37,
     -37,    -8,    -8,    -8,    -8,    -8,    -8,     0,    -8,     0,
       0,     0,     0,     0,     0,    -8,    -8,    -8,    -8,    -8,
      -8,     0,    -8,     0,    -8,    -8,     0,     0,    -8,     0,
       0,    -8,    -8,    -7,    -7,    -7,    -7,    -7,    -7,     0,
      -7,     0,     0,     0,     0,     0,     0,    -7,    -7,    -7,
      -7,    -7,    -7,     0,    -7,     0,    -7,    -7,     0,     0,
      -7,     0,     0,    -7,    -7,   -18,   -18,   -18,   -18,   -18,
     -18,     0,   -18,     0,     0,     0,     0,     0,     0,   -18,
     -18,   -18,   -18,   -18,   -18,     0,   -18,     0,   -18,   -18,
       0,     0,   -18,     0,     0,   -18,   -18,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,     0,     0,     0,     0,   -74,   -74,     0,
       0,     0,     0,   -74,     0,     0,   -74,   -74,     0,     0,
       0,   -74,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
       0,     0,     0,   223,   -69,     0,     0,     0,   -69,     0,
       0,   -73,   -73,     0,     0,     0,   -73,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,     0,     0,     0,     0,     0,     0,   -80,
     -80,     0,     0,   -80,     0,     0,     0,   -81,   -81,     0,
       0,   -81,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,     0,     0,
       0,     0,     0,     0,   -79,   -79,     0,     0,   -79,     0,
       0,     0,   -82,   -82,     0,     0,   -82,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,     0,     0,     0,     0,     0,     0,   -55,
     -55,     0,     0,   236,     0,     0,     0,   -57,   -57,     0,
       0,   -57,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,
       0,     0,     0,     0,   -63,   -63,     0,     0,   -63,     0,
       0,     0,   -70,   -70,     0,     0,   -70,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,     0,     0,     0,   -71,
     -71,     0,     0,   -71,     0,     0,     0,   -58,   -58,     0,
       0,   -58,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,
       0,     0,     0,     0,   -72,   -72,     0,     0,   -72,     0,
       0,     0,   -64,   -64,     0,     0,   -64,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,     0,     0,     0,     0,   -81,     0,     0,
       0,     0,     0,   -81,     0,   -79,     0,     0,     0,     0,
       0,   -79,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,     0,   -82,     0,     0,     0,     0,     0,   -82,     0,
     -55,     0,     0,     0,     0,     0,    90,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,     0,     0,   -57,     0,     0,
       0,     0,     0,   -57,     0,   -63,     0,     0,     0,     0,
       0,   -63,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,
       0,     0,   -70,     0,     0,     0,     0,     0,   -70,     0,
     -71,     0,     0,     0,     0,     0,   -71,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,     0,   -58,     0,     0,
       0,     0,     0,   -58,     0,   -72,     0,     0,     0,     0,
       0,   -72,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,
       0,     0,   -64,     0,     0,     0,     0,     0,   -64,     0,
       0,     0,   -80,     0,     0,     0,   -80,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,     0,     0,     0,     0,     0,     0,   -81,
       0,     0,     0,   -81,     0,     0,     0,   -79,     0,     0,
       0,   -79,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,     0,     0,     0,   -82,     0,     0,     0,   -82,     0,
       0,     0,   -55,     0,     0,     0,   221,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,     0,     0,     0,     0,   -57,
       0,     0,     0,   -57,     0,     0,     0,   -63,     0,     0,
       0,   -63,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,
       0,     0,     0,     0,   -70,     0,     0,     0,   -70,     0,
       0,     0,   -71,     0,     0,     0,   -71,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,     0,     0,     0,   -58,
       0,     0,     0,   -58,     0,     0,     0,   -72,     0,     0,
       0,   -72,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,
       0,     0,     0,     0,   -64,     0,     0,     0,   -64,     0,
       0,   -74,   -74,   -74,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
       0,     0,     0,     0,     0,   314,   -69,   -69,     0,     0,
       0,     0,     0,   -73,   -73,   -73,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   235,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,     0,     0,     0,     0,     0,     0,   -71,   -71,
       0,     0,     0,     0,     0,     0,   -54,   -54,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,     0,
     -56,   -56,     0,     0,     0,     0,     0,     0,   -58,   -58,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,     0,
       0,     0,   -72,   -72,     0,     0,     0,     0,     0,     0,
     -64,   -64,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,
       0,     0,     0,   -74,   -74,     0,     0,     0,     0,     0,
       0,   309,   -69,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   220,   -53,   -53,   -53,   -53,   -53,   -53,   -53,     0,
       0,     0,     0,     0,   -73,   -73,     0,     0,     0,     0,
       0,     0,     0,   -53,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
       0,     0,     0,     0,     0,     0,   -80,     0,     0,     0,
       0,     0,     0,     0,   -81,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,     0,     0,     0,     0,     0,     0,   -79,     0,     0,
       0,     0,     0,     0,     0,   -82,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,     0,     0,     0,   -55,     0,
       0,     0,     0,     0,     0,     0,   -57,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,     0,     0,     0,     0,     0,     0,   -63,
       0,     0,     0,     0,     0,     0,     0,   -70,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   220,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,     0,     0,     0,     0,     0,     0,
     -71,     0,     0,     0,     0,     0,     0,     0,   -54,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,
       0,   -56,     0,     0,     0,     0,     0,     0,     0,   -58,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,     0,
       0,     0,   -72,     0,     0,     0,     0,     0,     0,     0,
     -64,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,
       0,   -74,   -74,     0,     0,     0,     0,     0,     0,   -69,
     226,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,
       0,   -73,   -73,     0,     0,     0,     0,     0,     0,   -55,
      89,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,     0,
     -54,     0,     0,     0,     0,     0,     0,     0,   -56,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,     0,     0,     0,     0,   -80,
       0,     0,     0,     0,     0,     0,     0,   -81,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,     0,     0,     0,     0,   -79,     0,
       0,     0,     0,     0,     0,     0,   -82,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,     0,     0,   -57,     0,     0,
       0,     0,     0,     0,     0,   -63,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,     0,     0,     0,     0,   -70,     0,     0,     0,
       0,     0,     0,     0,   -71,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,     0,     0,   -58,    86,   -50,   -50,   -50,
     -50,    87,    88,   -72,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,     0,     0,     0,   -50,     0,     0,     0,     0,
       0,     0,     0,     0,   -64
};

static const yytype_int16 yycheck[] =
{
       7,    26,   117,   223,   135,     6,   226,     0,   211,     6,
       3,   126,     6,    21,    22,    22,    29,     6,   238,    21,
      22,    31,    23,    31,    17,     6,    23,     6,    29,    13,
     116,    24,    29,     0,     6,    29,   116,    44,   116,   125,
      29,   116,   245,   129,   116,    13,   116,    31,    29,    34,
      29,    12,    13,    14,    21,    22,    33,     3,     4,     5,
       6,    29,    33,    70,    10,     0,    73,    74,    75,   200,
      31,    17,    18,    19,    20,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    30,    92,    21,    22,     0,   309,
      13,   116,    30,     0,   314,    29,     3,    21,    22,     3,
       4,     5,     6,     7,     8,    13,    10,    31,    31,    21,
      22,   118,    13,    17,    18,    19,    20,    43,    44,   126,
      24,    29,    26,    27,     0,     6,    30,    30,   243,    33,
      31,    32,    29,    30,   141,     0,    30,     3,     4,     5,
       6,     0,    23,   150,    10,    21,    22,     0,    74,    75,
      76,    17,    18,    19,    20,    30,    21,    22,   165,   166,
       0,     6,    21,    22,    30,    31,    92,     6,    21,    22,
      31,   178,     3,     4,     5,     6,     7,     8,    23,    10,
     187,    21,    22,    29,    12,    13,    17,    18,    19,    20,
     116,   117,   118,    24,    29,    26,    27,    29,    30,    30,
     126,    31,    33,    31,   319,    31,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   141,   223,   332,    13,   226,
       0,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      31,   238,   318,   240,   241,   242,    31,    32,   318,   165,
     318,    21,    22,   318,    29,   331,   318,   254,   318,   335,
     257,   331,   178,   331,    29,   335,   331,   335,    31,   331,
     335,   331,    29,   335,    30,   335,    31,    32,     3,     4,
       5,     6,    29,   199,   281,    10,    29,   284,    11,    12,
      13,    14,    17,    18,    19,    20,    12,    13,    11,    12,
      13,    14,    44,   318,    31,    30,    31,   223,    31,    32,
     226,    29,   309,    12,    13,    31,   331,   314,    31,    32,
     335,    31,   238,    65,    29,   241,   242,   243,    31,    32,
      29,    29,    74,    75,    30,   332,    21,    22,   254,    30,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    30,
      92,    11,    12,    13,    14,    31,     3,     4,     5,     6,
       7,     8,     6,    10,     6,   281,    12,    13,    14,    29,
      17,    18,    19,    20,    21,    22,   118,    24,    25,    26,
      27,    12,    13,    30,   126,    31,    33,    34,    31,    11,
      12,    13,    14,   309,    11,    12,    13,    14,   314,   141,
      31,    32,   318,   319,    11,    12,    13,    14,   150,    31,
      32,    31,    32,    31,    31,   331,   332,    12,    13,   335,
      31,    32,    29,   165,   166,     3,     4,     5,     6,     7,
       8,    31,    10,    29,    29,    34,   178,    31,    32,    17,
      18,    19,    20,    21,    22,   187,    24,    25,    26,    27,
      12,    13,    30,    29,    31,    33,    34,    31,    32,    31,
       9,    10,    11,    12,    13,    14,    15,    16,    31,    31,
      32,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      44,   223,    31,    32,   226,    31,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    31,   238,    31,    32,   241,
     242,    31,    32,    31,    31,    34,    31,    29,    29,    29,
      74,    75,   254,    31,    31,   257,    31,     3,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    93,    92,     3,
       4,     5,     6,     7,     8,    24,    10,    48,    -1,   281,
      -1,    -1,   284,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,   118,    -1,    30,    -1,    -1,    33,
      34,    -1,   126,    -1,    -1,    -1,    -1,   309,     3,     4,
       5,     6,   314,    -1,    -1,    10,    -1,   141,    11,    12,
      13,    14,    17,    18,    19,    20,   150,    -1,    -1,    -1,
     332,    -1,    -1,    -1,    29,    30,    -1,    -1,    31,    32,
      -1,   165,   166,     3,     4,     5,     6,     7,     8,    -1,
      10,    12,    13,    14,   178,    -1,    -1,    17,    18,    19,
      20,    21,    22,   187,    24,    25,    26,    27,    29,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    12,    13,    14,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    44,   223,
      31,    32,   226,    29,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,   238,    -1,    -1,   241,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
     254,    -1,    -1,   257,    -1,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,   281,    -1,    -1,
     284,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,   118,    -1,    30,    -1,    -1,    33,    34,    -1,
     126,    -1,    -1,    -1,    -1,   309,     3,     4,     5,     6,
     314,    -1,    -1,    10,    -1,   141,    11,    12,    13,    14,
      17,    18,    19,    20,   150,    -1,    -1,    -1,   332,    11,
      12,    13,    14,    30,    -1,    -1,    31,    32,    -1,   165,
     166,     3,     4,     5,     6,     7,     8,    -1,    10,    31,
      32,    -1,   178,    -1,    -1,    17,    18,    19,    20,    21,
      22,   187,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    44,   223,    31,    32,
     226,    -1,   228,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,   238,    -1,    -1,   241,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,   254,    -1,
      -1,   257,    -1,    -1,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    92,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,   281,    -1,    -1,   284,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
     118,    -1,    30,    -1,    -1,    33,    34,    -1,   126,    -1,
      -1,    -1,    -1,   309,     3,     4,     5,     6,   314,    -1,
      -1,    10,    -1,   141,    11,    12,    13,    14,    17,    18,
      19,    20,   150,    -1,    -1,    -1,   332,    -1,    12,    13,
      14,    30,    -1,    -1,    31,    -1,    -1,   165,   166,     3,
       4,     5,     6,     7,     8,    -1,    10,    31,    32,    -1,
     178,    -1,    -1,    17,    18,    19,    20,    21,    22,   187,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    44,   223,    31,    32,   226,    -1,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
     238,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,   254,    -1,    -1,   257,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,   281,    -1,    -1,   284,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,   118,    -1,
      30,    -1,    -1,    33,    34,    -1,   126,    -1,    -1,    -1,
      -1,   309,     3,     4,     5,     6,   314,    -1,    -1,    10,
      -1,   141,    11,    12,    13,    14,    17,    18,    19,    20,
     150,    -1,    -1,    -1,   332,    11,    12,    13,    14,    30,
      -1,    -1,    31,    -1,    -1,   165,   166,     3,     4,     5,
       6,     7,     8,    -1,    10,    31,    -1,    -1,   178,    -1,
      -1,    17,    18,    19,    20,    21,    22,   187,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,    44,   223,    31,    32,   226,    -1,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,   238,    -1,
      -1,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,   254,    -1,    -1,   257,    -1,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,   281,    -1,    -1,   284,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,   118,    -1,    30,    -1,
      -1,    33,    34,    -1,   126,    -1,    -1,    -1,    -1,   309,
       3,     4,     5,     6,   314,    -1,    -1,    10,    -1,   141,
      11,    12,    13,    14,    17,    18,    19,    20,   150,    -1,
      -1,    -1,   332,    11,    12,    13,    14,    30,    -1,    -1,
      31,    -1,    -1,   165,   166,     3,     4,     5,     6,     7,
       8,    -1,    10,    31,    -1,    -1,   178,    -1,    -1,    17,
      18,    19,    20,    21,    22,   187,    24,    25,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,   221,
      44,   223,    31,    32,   226,    -1,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,   238,    -1,    -1,   241,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,   254,    -1,    -1,   257,    -1,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    92,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,   281,
      -1,    -1,   284,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,   118,    -1,    30,    -1,    -1,    33,
      34,    -1,   126,    11,    12,    13,    14,   309,     3,     4,
       5,     6,   314,    -1,    -1,    10,    -1,   141,    12,    13,
      14,    29,    17,    18,    19,    20,   150,    -1,    -1,    -1,
     332,    11,    12,    13,    14,    30,    -1,    31,    32,    -1,
      -1,   165,   166,     3,     4,     5,     6,     7,     8,    29,
      10,    -1,    -1,    -1,   178,    -1,    -1,    17,    18,    19,
      20,    21,    22,   187,    24,    25,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    44,   223,
      31,    32,   226,    -1,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,   238,    -1,    -1,   241,   242,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    74,    75,
     254,    -1,    -1,   257,    17,    18,    19,    20,    -1,    85,
      44,    87,    88,    -1,    -1,    -1,    92,    30,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,   281,    -1,    -1,
     284,    -1,    17,    18,    19,    20,    11,    12,    13,    14,
      74,    75,   118,    -1,    -1,    30,    11,    12,    13,    14,
     126,    -1,    86,    -1,    29,   309,    -1,    -1,    92,    -1,
     314,    -1,    -1,    -1,    29,   141,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,   332,    -1,
      17,    18,    19,    20,   118,    -1,    -1,    -1,    -1,   165,
      -1,    -1,   126,    30,     3,     4,     5,     6,     7,     8,
      -1,    10,   178,    -1,    -1,    -1,    -1,   141,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,
      -1,   165,    -1,    -1,    -1,    -1,    -1,   213,   214,   215,
     216,    -1,   218,   219,   178,   221,    -1,   223,    -1,    -1,
     226,    -1,   228,   229,   230,   231,    -1,   233,   234,    -1,
     236,    -1,   238,    -1,    -1,   241,   242,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,   254,   213,
     214,   215,   216,   217,   218,   219,    44,   221,    -1,   223,
      31,    32,   226,    -1,   228,   229,   230,   231,   232,   233,
     234,    -1,   236,    -1,   238,   281,    -1,   241,   242,    -1,
      -1,    -1,     3,     4,     5,     6,    74,    75,    44,    10,
     254,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,   309,    92,    -1,    -1,    -1,   314,    30,
      10,    11,    12,    13,    14,    15,    16,   281,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,    84,    -1,
     118,    31,    32,    -1,    -1,    -1,    92,    -1,   126,    -1,
      -1,    -1,    -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,
     314,    -1,    -1,   141,     9,    10,    11,    12,    13,    14,
      15,    16,   118,    -1,    -1,    -1,    -1,    -1,   332,    -1,
     126,    -1,    -1,    -1,    29,    30,    -1,   165,    -1,    -1,
      35,    -1,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,
     178,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,   165,
      -1,    -1,    30,    31,    32,    -1,    -1,    35,    -1,    -1,
      -1,    44,   178,    31,    32,   213,   214,   215,   216,    -1,
     218,   219,    -1,   221,    -1,   223,    -1,    -1,   226,    -1,
     228,   229,   230,   231,    -1,   233,   234,    -1,   236,    -1,
     238,    74,    75,   241,   242,    -1,    -1,   213,   214,   215,
      83,    -1,    -1,    -1,    -1,   221,   254,   223,    -1,    92,
     226,    -1,   228,   229,   230,    44,    -1,    -1,    -1,    -1,
     236,    -1,   238,    -1,    -1,   241,   242,    -1,    -1,    -1,
      -1,    -1,    -1,   281,    -1,   118,    -1,    -1,   254,    -1,
      44,    -1,    -1,   126,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,   141,    -1,
      -1,   309,    -1,    92,    -1,   281,   314,    -1,    -1,    -1,
      74,    75,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,   165,    -1,   332,    -1,    90,    -1,    92,   118,
      -1,    -1,    -1,   309,    29,   178,    -1,   126,   314,    -1,
      35,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,   141,    -1,   118,    -1,   332,    -1,    -1,    -1,
      -1,    -1,   126,    30,    31,    32,    -1,    -1,    35,    -1,
     213,   214,    -1,    -1,    -1,    -1,   165,   141,   221,    -1,
     223,    -1,    -1,   226,    -1,   228,   229,    -1,    -1,   178,
      -1,    -1,    -1,   236,    -1,   238,    -1,    -1,   241,   242,
      -1,   165,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,   254,    -1,    -1,   178,    10,    11,    12,    13,    14,
      15,    16,    29,    30,   213,    -1,    -1,    -1,    35,    -1,
      -1,    -1,   221,    -1,   223,    -1,    31,   226,   281,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,   238,
      -1,    -1,   241,   242,    -1,    -1,    -1,   221,    -1,   223,
      -1,    -1,   226,    -1,    -1,   254,   309,    -1,    -1,    -1,
      -1,   314,   236,    -1,   238,    -1,    -1,   241,   242,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,   332,
     254,    -1,   281,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,   281,    -1,    -1,
     309,    -1,    -1,    -1,    -1,   314,     9,    10,    11,    12,
      13,    14,    15,    16,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,   332,    -1,   309,    -1,    30,    31,    32,
     314,    -1,    35,    -1,    29,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,   332,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    30,    31,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    35,    -1,
      -1,    30,    31,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    -1,
      -1,    30,    31,    32,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,     9,    10,    11,    12,
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
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
       9,    10,    11,    12,    13,    14,    15,    16,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    29,
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
      15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    29,    10,    11,    12,    13,
      14,    15,    16,    29,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    22,    37,    38,    39,    41,    75,    23,    23,
       0,    38,     6,    29,    74,    30,    40,    42,    29,    44,
      45,    46,    75,    31,    32,    74,    43,    46,    33,    47,
      48,     3,     4,     5,     7,     8,    10,    17,    18,    19,
      20,    24,    26,    27,    30,    39,    47,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    72,    73,    74,
      75,    76,    77,    30,    30,    30,    30,    58,    58,    34,
      51,    29,    13,    12,    14,    11,    10,    15,    16,     9,
      35,    67,    30,    74,    74,    58,    58,    58,    59,    29,
      31,    61,    67,    62,    63,    64,    66,    64,    64,    67,
      60,    58,    70,    71,    31,    31,    31,    29,    32,    31,
      29,    29,    52,    59,    58,    25,    29,    52,    59,    31,
      52,    21,    22,     6,     6,    33,     3,     4,     5,     6,
      20,    30,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    72,    73,    74,    76,    77,     6,    29,     6,
       3,     4,     5,     6,    20,    30,    68,    69,    72,    73,
      74,    76,    77,     3,     4,     5,     6,    20,    30,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    72,
      73,    74,    76,    77,    40,     7,     8,    24,    26,    27,
      33,    47,    53,    54,    55,    56,    57,    58,    58,    23,
      23,    48,    58,    13,    12,    14,    11,    10,    15,    16,
       9,    35,    67,    30,    58,    67,    30,    58,    13,    12,
      14,    11,    10,    15,    16,     9,    35,    67,    30,    29,
      30,    30,    30,    30,    58,    48,    29,    49,    31,     3,
       4,     5,     6,    20,    30,    61,    67,    68,    69,    72,
      73,    74,    76,    77,    62,    63,    64,    66,    64,    64,
      67,    60,    71,    31,    71,    31,     3,     4,     5,     6,
      20,    30,    61,    67,    68,    69,    72,    73,    74,    76,
      77,    62,    63,    64,    66,    64,    64,    67,    60,    71,
      74,    58,    58,    59,    29,    49,    34,    58,    67,    30,
      31,    31,    58,    67,    30,    31,    31,    31,    31,    29,
      34,    31,    71,    31,    71,    29,    29,    52,    59,    31,
      31,    25,    29,    52,    59,    31,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    40,    39,    39,    42,
      43,    41,    44,    44,    45,    45,    46,    48,    47,    49,
      49,    50,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    53,    53,    54,    55,    55,    56,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    72,    72,    73,    74,    75,    75,    75,    75,    76,
      76,    76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     4,     2,     0,
       0,     8,     0,     1,     3,     1,     2,     0,     4,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     2,     5,     7,     3,     9,     1,     3,
       0,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     4,     1,     3,     1,     0,     1,
       1,     1,     3,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1
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
#line 69 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2179 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 69 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2185 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 69 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2191 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2197 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2203 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2209 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2215 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2221 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2227 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2233 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2239 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2245 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2251 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2257 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2263 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2269 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2275 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2281 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2287 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2293 "src/bison/grammar.c"
        break;

    case YYSYMBOL_40_1: /* @1  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2299 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2305 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_2: /* @2  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2311 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2317 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2323 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2329 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2335 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2341 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2347 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2353 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2359 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2365 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2371 "src/bison/grammar.c"
        break;

    case YYSYMBOL_59_expression_opt: /* expression.opt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2377 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2383 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2389 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2395 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2401 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2407 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2413 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2419 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2425 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2431 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2437 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2443 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id_expr: /* id_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2449 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2455 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2461 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2467 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2473 "src/bison/grammar.c"
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
#line 74 "src/bison/grammar.y"
                                { list_push(&root->children, (yyvsp[0].ast)); }
#line 2744 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 75 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 2750 "src/bison/grammar.c"
    break;

  case 6: /* @1: %empty  */
#line 82 "src/bison/grammar.y"
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
#line 2772 "src/bison/grammar.c"
    break;

  case 7: /* var_declaration: type id @1 ';'  */
#line 98 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 2780 "src/bison/grammar.c"
    break;

  case 8: /* var_declaration: type ';'  */
#line 101 "src/bison/grammar.y"
               {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("useless '%s' in empty declaration\n", error_cursor, (yyvsp[-1].pchar));
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
    }
#line 2791 "src/bison/grammar.c"
    break;

  case 9: /* @2: %empty  */
#line 109 "src/bison/grammar.y"
                                   {
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

        ast_free((yyvsp[-1].ast));
        free((yyvsp[-2].pchar));
        context_push_scope(current_context);
    }
#line 2822 "src/bison/grammar.c"
    break;

  case 10: /* $@3: %empty  */
#line 134 "src/bison/grammar.y"
                         {
        LIST_FOR_EACH((yyvsp[-1].list), {
            context_declare_variable(current_context, ((AST *)__IT__->data)->value.symref);
        });
        // hack to save the scope of params and append to the scope of the body
        {
            params_scope = scope_init_copy(stack_peek(&current_context->scopes));
            stack_pop(&current_context->scopes, free_scope_cb);
        }
    }
#line 2837 "src/bison/grammar.c"
    break;

  case 11: /* func_declaration: type id '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 143 "src/bison/grammar.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 2846 "src/bison/grammar.c"
    break;

  case 12: /* param_list.opt: %empty  */
#line 149 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 2852 "src/bison/grammar.c"
    break;

  case 14: /* params_list: params_list ',' param_decl  */
#line 153 "src/bison/grammar.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2858 "src/bison/grammar.c"
    break;

  case 15: /* params_list: param_decl  */
#line 154 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2864 "src/bison/grammar.c"
    break;

  case 16: /* param_decl: type id  */
#line 157 "src/bison/grammar.y"
                    {
        symbol_update_context((yyvsp[0].ast)->value.symref->symbol, current_context);
        symbol_update_type((yyvsp[0].ast)->value.symref->symbol, symbol_type_from_str((yyvsp[-1].pchar)));
        (yyval.ast) = ast_symref_init(symbol_init_copy((yyvsp[0].ast)->value.symref->symbol));
        ast_free((yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2876 "src/bison/grammar.c"
    break;

  case 17: /* $@4: %empty  */
#line 166 "src/bison/grammar.y"
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
#line 2892 "src/bison/grammar.c"
    break;

  case 18: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 176 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            current_context->current_scope = ((Scope *)parent_stacknode_ref->data)->index;
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 2905 "src/bison/grammar.c"
    break;

  case 19: /* block_item_list.opt: block_item_list  */
#line 186 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 2911 "src/bison/grammar.c"
    break;

  case 20: /* block_item_list.opt: %empty  */
#line 187 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 2917 "src/bison/grammar.c"
    break;

  case 21: /* block_item_list: block_item_list block_item  */
#line 190 "src/bison/grammar.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2923 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list: block_item  */
#line 191 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2929 "src/bison/grammar.c"
    break;

  case 31: /* io_stmt: READ '(' id ')' ';'  */
#line 206 "src/bison/grammar.y"
                             {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].ast)->value.symref->symbol);
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(func)), ast_symref_init(symbol_init_copy(param)));
        symbol_free((yyvsp[-4].sym));
        ast_free((yyvsp[-2].ast));
    }
#line 2941 "src/bison/grammar.c"
    break;

  case 32: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 213 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(sym)), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 2951 "src/bison/grammar.c"
    break;

  case 33: /* expr_stmt: expression ';'  */
#line 220 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2957 "src/bison/grammar.c"
    break;

  case 34: /* cond_stmt: IF '(' expression ')' statement  */
#line 223 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 2965 "src/bison/grammar.c"
    break;

  case 35: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 226 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2973 "src/bison/grammar.c"
    break;

  case 36: /* jmp_stmt: RETURN expression ';'  */
#line 231 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 2979 "src/bison/grammar.c"
    break;

  case 37: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 234 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2987 "src/bison/grammar.c"
    break;

  case 39: /* expression: unary_expr '=' logical_or_expr  */
#line 240 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2993 "src/bison/grammar.c"
    break;

  case 40: /* expression.opt: %empty  */
#line 243 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 2999 "src/bison/grammar.c"
    break;

  case 43: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 248 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3008 "src/bison/grammar.c"
    break;

  case 45: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 255 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3017 "src/bison/grammar.c"
    break;

  case 47: /* eq_expr: eq_expr EQ rel_expr  */
#line 262 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3026 "src/bison/grammar.c"
    break;

  case 49: /* rel_expr: rel_expr REL list_expr  */
#line 269 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3035 "src/bison/grammar.c"
    break;

  case 51: /* list_expr: add_expr DL_DG list_expr  */
#line 276 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3044 "src/bison/grammar.c"
    break;

  case 52: /* list_expr: add_expr COLON list_expr  */
#line 280 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3053 "src/bison/grammar.c"
    break;

  case 54: /* add_expr: add_expr ADD mult_expr  */
#line 287 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3062 "src/bison/grammar.c"
    break;

  case 56: /* mult_expr: mult_expr MULT unary_expr  */
#line 294 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3071 "src/bison/grammar.c"
    break;

  case 58: /* unary_expr: unary_ops unary_expr  */
#line 301 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3080 "src/bison/grammar.c"
    break;

  case 64: /* postfix_expr: id_expr '(' arg_expr_list.opt ')'  */
#line 314 "src/bison/grammar.y"
                                        {
        (yyval.ast) = ast_funcall_init((yyvsp[-3].ast), ast_params_init((yyvsp[-1].list)));
    }
#line 3088 "src/bison/grammar.c"
    break;

  case 65: /* arg_expr_list: expression  */
#line 319 "src/bison/grammar.y"
                          { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3094 "src/bison/grammar.c"
    break;

  case 66: /* arg_expr_list: arg_expr_list ',' expression  */
#line 320 "src/bison/grammar.y"
                                   { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3100 "src/bison/grammar.c"
    break;

  case 68: /* arg_expr_list.opt: %empty  */
#line 324 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3106 "src/bison/grammar.c"
    break;

  case 72: /* primary_expr: '(' expression ')'  */
#line 330 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 3112 "src/bison/grammar.c"
    break;

  case 73: /* id_expr: id  */
#line 333 "src/bison/grammar.y"
            {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[0].ast)->value.symref->symbol);
        if (!sym) {
            yyerror(NULL);
            CIPL_PERROR_CURSOR("'%s' undeclared (first use in this function)", error_cursor, (yyvsp[0].ast)->value.symref->symbol->name);
            (yyval.ast) = NULL;
        }   else {
            symbol_update_context((yyvsp[0].ast)->value.symref->symbol, current_context);
            (yyval.ast) = ast_symref_init(symbol_init_copy(sym ? sym : (yyvsp[0].ast)->value.symref->symbol));
        }
        ast_free((yyvsp[0].ast));
    }
#line 3129 "src/bison/grammar.c"
    break;

  case 74: /* id: NAME  */
#line 347 "src/bison/grammar.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 3135 "src/bison/grammar.c"
    break;

  case 77: /* type: INT LIST  */
#line 352 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3147 "src/bison/grammar.c"
    break;

  case 78: /* type: FLOAT LIST  */
#line 359 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3159 "src/bison/grammar.c"
    break;

  case 79: /* constant: NUMBER_REAL  */
#line 368 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 3165 "src/bison/grammar.c"
    break;

  case 80: /* constant: NUMBER_INT  */
#line 369 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3171 "src/bison/grammar.c"
    break;

  case 81: /* constant: NIL  */
#line 370 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3177 "src/bison/grammar.c"
    break;

  case 82: /* string_literal: STR_LITERAL  */
#line 373 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 3186 "src/bison/grammar.c"
    break;


#line 3190 "src/bison/grammar.c"

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

#line 379 "src/bison/grammar.y"


void yyerror(const char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    if (s) CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
    ++errors_count;
}
