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
#define YYLAST   4304

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  338

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
       0,    74,    74,    75,    81,    82,    85,    86,    89,    89,
     115,   123,   153,   123,   173,   174,   177,   178,   181,   190,
     190,   209,   210,   213,   214,   217,   218,   221,   222,   223,
     224,   225,   226,   229,   236,   243,   246,   249,   254,   257,
     262,   263,   266,   267,   270,   271,   277,   278,   284,   285,
     291,   292,   298,   299,   303,   309,   310,   316,   317,   323,
     324,   330,   331,   332,   333,   336,   337,   342,   343,   346,
     347,   350,   351,   352,   353,   356,   370,   373,   374,   375,
     382,   391,   392,   393,   396
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

#define YYPACT_NINF (-222)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-85)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,    -1,     6,    21,    65,    88,   124,   135,     4,    11,
      18,  -222,   141,    20,   147,    26,    74,   -10,    76,   160,
      -5,    61,   101,    45,    28,   176,   235,    94,   267,  2196,
     220,  2272,  2025,  3218,  3226,    91,   106,    54,   733,   911,
    1089,  3253,   125,   131,  1267,  1445,  2304,  2336,   133,  2368,
    2400,  2432,  2464,  2496,  2528,  2560,  2592,   149,    -6,   291,
     589,   330,   383,  4266,  2245,  3261,  1267,  3288,  3296,  1845,
    2113,    19,  3323,  3331,   164,  1445,  1445,   555,   154,   163,
     258,  2624,  2656,  1557,  1557,  1557,  1557,  1557,  1557,  1557,
    1557,  1557,  3358,   134,   201,   170,   174,   213,   225,   233,
    2688,  3366,   395,  4080,   624,  1076,  1595,  4101,  1605,  1644,
    4109,    41,   287,   295,   241,   249,   252,    96,   555,  1585,
    3393,  2720,  2752,   343,   272,   370,   169,   265,  2784,   245,
     169,  2816,    39,   119,   379,  2938,  2196,  3401,  3428,  3436,
    2946,  3463,  1445,     1,   172,   344,   373,   926,  2125,  3802,
    3471,  1445,  3498,  3506,  2973,  2981,  3533,  3541,   282,  2848,
     263,  4130,  4138,  4159,  4042,  4167,  1445,  1557,  4188,  4196,
    4050,  4072,  4217,  4225,  3008,  3016,  3043,  1882,  3051,  1445,
      99,   359,  1090,   277,   368,  1800,   441,  3078,  1585,  3086,
    3113,  2053,  2237,  3121,  3148,   285,   234,   294,   299,   309,
    1267,  2196,   412,   516,   590,   694,   768,   872,   292,   314,
     346,   348,  2272,   347,  1633,  1633,  1633,  1633,  1633,  1633,
    1633,  1633,  1633,  3568,   134,   372,  4246,   134,   390,  1779,
    1779,  1779,  1779,  1779,  1779,  1779,  1779,  1779,  3156,   134,
    2880,   164,  1445,  1445,   555,   394,  2272,   946,   391,  3576,
    3825,  3833,  3856,  3763,  3864,  1445,   274,  3887,  1633,  3895,
    3918,  3771,  3794,  3926,  3949,  1552,  1104,  1269,  3957,  1282,
    1447,  3980,    77,   396,  4254,   397,  3183,   619,   797,   975,
    3611,  1153,  1445,   428,  1331,  1779,  1509,  1729,  3635,  3643,
    1892,  3667,  1460,   557,   735,  3675,   748,   913,  3699,   205,
     413,   416,   417,   418,   414,  1050,   424,  2912,   444,  3988,
     134,  3603,  4275,   454,  3707,   134,  3191,   458,   459,    96,
     555,  1124,  4011,   460,  3731,   461,  1228,  1302,  1406,   464,
    4019,  3739,    96,   265,  1480,   463,    96,  1661
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
       0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,  -222,   491,    16,   402,  -222,  -222,  -222,  -222,
    -222,   472,   -26,  -132,  -204,  -222,   449,   -87,   -81,   -79,
     -76,   -73,   -71,    73,  -116,  1955,  1930,  1876,  1743,  1493,
    1711,  1535,   247,   425,   603,  -222,  -221,   781,   959,    -8,
       9,  1137,  1315
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    46,    17,     7,    18,    27,    20,
      21,    22,    47,    31,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    99,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   113,   114,    68,    69,    70,
      71,    72,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    30,   124,   273,   212,   -77,   275,    83,   248,     8,
      13,   129,   -78,     8,   214,    26,     6,   -79,   300,    19,
       6,    11,     9,   -40,   -80,   158,    24,    23,   -77,    10,
     123,    -3,   -40,    14,    23,   -78,   203,   155,   204,   128,
     -79,   205,   306,   131,   206,   -77,   207,   -80,   159,   -76,
     -76,   134,     1,     2,    83,    -8,    16,   -63,   -63,   -63,
     -63,   -12,   210,    94,   -63,    -2,    95,   155,   155,   246,
     -41,   -63,   -63,   -63,   -63,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   -63,   192,     1,     2,    -5,   323,
     214,   202,   -15,    25,   325,   -11,   -11,   132,   133,    32,
      33,    34,   135,   196,   197,   -11,    37,   -14,   -41,    -5,
      -5,   192,   229,    38,    39,    40,    41,    78,    79,   155,
     198,    74,   199,   200,    -7,   -78,    45,    29,   304,   201,
     -40,   -40,   -17,   -17,   155,    -6,    75,   174,   175,   176,
     177,    -4,   211,   155,    37,    -7,    -7,   -10,    96,    97,
      98,    38,    39,    40,   178,    76,    -6,    -6,   155,   171,
      -9,    77,    -4,    -4,   179,   -70,   112,    80,   -10,   -10,
     160,   155,    32,    33,    34,   135,    35,    36,    82,    37,
     192,    -9,    -9,   100,   215,   -44,    38,    39,    40,    41,
     208,    98,   125,    42,   101,    43,    44,   132,   133,    45,
     209,   115,   136,   -44,   329,   116,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   213,   192,   335,   229,   192,
     -13,   289,   289,   289,   289,   289,   289,   289,   289,   289,
      -8,   192,   328,   301,   155,   155,   -41,   -41,   203,   225,
     204,   -13,   -13,   205,   117,   334,   206,   155,   207,   337,
     262,   203,   228,   204,   -43,   203,   205,   204,   -20,   206,
     205,   207,   118,   206,   241,   207,   -18,   -18,   137,   138,
     139,   140,   120,   245,   155,    37,   130,   289,   121,   -20,
     -20,   122,    38,    39,    40,   141,   215,   -45,   232,   -48,
     -48,   -48,   150,   202,   -76,   142,   -42,   112,   -16,   -16,
     112,   127,   192,    84,   -44,   -45,   202,   192,   -48,   -48,
     202,   -76,   112,    92,   240,   302,   303,    98,   -67,   -67,
     -44,   247,   150,   150,   242,   155,   -69,   119,   308,   243,
     103,   103,   103,   103,   103,   103,   103,   110,   103,   244,
     187,    86,   -48,   -48,   -48,   -43,   -36,   -36,   -36,   -36,
     -36,   -36,   -79,   -36,   -80,   313,   -46,   -46,   216,   -48,
     -36,   -36,   -36,   -36,   -36,   -36,   187,   -36,   126,   -36,
     -36,   230,   -44,   -36,   150,   -46,   -36,   -36,   249,   -50,
     -50,   -50,   -50,   112,   217,   -48,   -48,   -48,   112,   150,
     -44,   -44,   208,    98,   -50,   -50,   -50,   -50,   223,   -50,
     -50,   -68,   -68,   274,   -48,   208,   209,    84,   -45,   208,
     -76,   -76,   -50,   150,   226,   -28,   -28,   -28,   -28,   -28,
     -28,   276,   -28,   305,   -45,   307,   150,   311,   312,   -28,
     -28,   -28,   -28,   -28,   -28,   238,   -28,   -28,   -28,   -28,
     230,   -45,   -28,   320,   316,   -28,   -28,   317,   318,   319,
     236,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   321,   -45,
     -45,   257,   257,   257,   257,   257,   257,   257,   271,   257,
     151,   187,   -55,   -55,   187,   322,   284,   284,   284,   284,
     284,   284,   284,   298,   284,   324,   187,   326,   327,   150,
     150,   330,   331,   333,   336,    12,   195,    28,    81,     0,
     151,   151,   150,     0,     0,   309,     0,     0,   167,   167,
     167,   167,   167,   167,   167,   167,   167,     0,   188,   -32,
     -32,   -32,   -32,   -32,   -32,     0,   -32,     0,     0,   150,
       0,     0,   314,   -32,   -32,   -32,   -32,   -32,   -32,     0,
     -32,   -32,   -32,   -32,   188,     0,   -32,     0,     0,   -32,
     -32,     0,   151,     0,     0,     0,     0,   187,    32,    33,
      34,   135,   187,     0,     0,    37,     0,   151,   232,   -49,
     -49,   -49,    38,    39,    40,    41,   151,     0,     0,     0,
     150,     0,     0,     0,   -42,    45,     0,     0,   -49,   -49,
       0,   151,   167,   -27,   -27,   -27,   -27,   -27,   -27,     0,
     -27,   -46,   -46,    85,   151,     0,     0,   -27,   -27,   -27,
     -27,   -27,   -27,   188,   -27,   -27,   -27,   -27,   -46,     0,
     -27,     0,     0,   -27,   -27,     0,     0,     0,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -47,   -47,    85,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   152,   188,
     -82,   -82,   188,   -47,   285,   285,   285,   285,   285,   285,
     285,   285,   285,     0,   188,     0,     0,   151,   151,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   152,
     151,     0,     0,   258,     0,     0,   168,   168,   168,   168,
     168,   168,   168,   168,   168,     0,   189,   -29,   -29,   -29,
     -29,   -29,   -29,     0,   -29,     0,     0,   151,     0,     0,
     285,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,
     -29,   -29,   189,     0,   -29,     0,     0,   -29,   -29,     0,
     152,     0,     0,     0,     0,   188,   -61,   -61,   -61,   -61,
     188,     0,     0,   -61,     0,   152,   -51,   -51,   -51,   -51,
     -61,   -61,   -61,   -61,   152,     0,     0,     0,   151,   -54,
     -54,   -54,   -54,   -61,     0,     0,   -51,   -51,     0,   152,
     168,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,   -54,
     -54,     0,   152,     0,     0,   -30,   -30,   -30,   -30,   -30,
     -30,   189,   -30,   -30,   -30,   -30,     0,     0,   -30,     0,
       0,   -30,   -30,     0,     0,     0,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,     0,     0,     0,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   153,   189,   -83,   -83,
     189,     0,   286,   286,   286,   286,   286,   286,   286,   286,
     286,     0,   189,     0,     0,   152,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,   153,   152,     0,
       0,   259,     0,     0,   169,   169,   169,   169,   169,   169,
     169,   169,   169,     0,   190,   -31,   -31,   -31,   -31,   -31,
     -31,     0,   -31,     0,     0,   152,     0,     0,   286,   -31,
     -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,   -31,
     190,     0,   -31,     0,     0,   -31,   -31,     0,   153,     0,
       0,     0,     0,   189,   -62,   -62,   -62,   -62,   189,     0,
       0,   -62,     0,   153,   -53,   -53,   -53,   -53,   -62,   -62,
     -62,   -62,   153,     0,     0,     0,   152,   -50,   -50,   -50,
     -50,   -62,     0,     0,   -53,   -53,     0,   153,   169,   -35,
     -35,   -35,   -35,   -35,   -35,     0,   -35,   -50,     0,     0,
     153,     0,     0,   -35,   -35,   -35,   -35,   -35,   -35,   190,
     -35,   -35,   -35,   -35,     0,     0,   -35,     0,     0,   -35,
     -35,     0,     0,     0,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,     0,     0,     0,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   154,   190,   -81,   -81,   190,     0,
     287,   287,   287,   287,   287,   287,   287,   287,   287,     0,
     190,     0,     0,   153,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,   154,   153,     0,     0,   260,
       0,     0,   170,   170,   170,   170,   170,   170,   170,   170,
     170,     0,   191,   -38,   -38,   -38,   -38,   -38,   -38,     0,
     -38,     0,     0,   153,     0,     0,   287,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,   -38,   -38,   191,     0,
     -38,     0,     0,   -38,   -38,     0,   154,    86,   -49,   -49,
     -49,   190,   -64,   -64,   -64,   -64,   190,     0,     0,   -64,
       0,   154,   -46,   -46,   231,   -49,   -64,   -64,   -64,   -64,
     154,     0,     0,     0,   153,   217,   -49,   -49,   -49,   -64,
       0,   -46,   -46,     0,     0,   154,   170,   -20,   -20,   -20,
     -20,   -20,   -20,     0,   -20,   -49,     0,     0,   154,     0,
       0,   -20,   -20,   -20,   -20,   -20,   -20,   191,   -20,   -20,
     -20,   -20,     0,     0,   -20,     0,     0,   -20,   -20,     0,
       0,     0,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
       0,     0,     0,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   156,   191,   -84,   -84,   191,     0,   288,   288,
     288,   288,   288,   288,   288,   288,   288,     0,   191,     0,
       0,   154,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   156,   154,     0,     0,   261,     0,     0,
     172,   172,   172,   172,   172,   172,   172,   172,   172,     0,
     193,   -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,     0,
       0,   154,     0,     0,   288,   -33,   -33,   -33,   -33,   -33,
     -33,     0,   -33,   -33,   -33,   -33,   193,     0,   -33,     0,
       0,   -33,   -33,     0,   156,     0,     0,     0,     0,   191,
      32,    33,    34,   135,   191,     0,     0,    37,     0,   156,
     -51,   -51,   -51,   -51,    38,    39,    40,    41,   156,     0,
       0,     0,   154,   -54,   -54,   -54,   -54,    45,     0,     0,
     -51,     0,     0,   156,   172,   -34,   -34,   -34,   -34,   -34,
     -34,     0,   -34,   -54,     0,     0,   156,     0,     0,   -34,
     -34,   -34,   -34,   -34,   -34,   193,   -34,   -34,   -34,   -34,
       0,     0,   -34,     0,     0,   -34,   -34,     0,     0,     0,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     157,   193,   -57,   -57,   193,     0,   290,   290,   290,   290,
     290,   290,   290,   290,   290,     0,   193,     0,     0,   156,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   157,   156,     0,     0,   263,     0,     0,   173,   173,
     173,   173,   173,   173,   173,   173,   173,     0,   194,   -36,
     -36,   -36,   -36,   -36,   -36,     0,   -36,     0,     0,   156,
       0,     0,   290,   -36,   -36,   -36,   -36,   -36,   -36,     0,
     -36,   332,   -36,   -36,   194,     0,   -36,     0,     0,   -36,
     -36,     0,   157,     0,     0,     0,     0,   193,   137,   138,
     139,   140,   193,     0,     0,    37,     0,   157,   -53,   -53,
     -53,   -53,    38,    39,    40,   141,   157,     0,     0,     0,
     156,     0,   -47,   -47,   231,   142,     0,     0,   -53,     0,
       0,   157,   173,   -37,   -37,   -37,   -37,   -37,   -37,     0,
     -37,   -47,   -47,     0,   157,     0,     0,   -37,   -37,   -37,
     -37,   -37,   -37,   194,   -37,   -37,   -37,   -37,     0,     0,
     -37,     0,     0,   -37,   -37,     0,     0,     0,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   147,   194,
     -59,   -59,   194,     0,   291,   291,   291,   291,   291,   291,
     291,   291,   291,     0,   194,     0,     0,   157,   157,     0,
     161,   162,   163,   164,   -47,   -47,   216,    37,   147,   147,
     157,     0,     0,   264,    38,    39,    40,   165,     0,   106,
     149,   108,   109,   -47,     0,     0,   184,   166,   174,   175,
     176,   177,     0,     0,     0,    37,     0,   157,     0,     0,
     291,     0,    38,    39,    40,   178,   -51,   -51,   -51,   -51,
     149,   149,   184,     0,     0,   179,   -54,   -54,   -54,   -54,
     147,     0,   107,     0,   -51,   194,     0,     0,   186,     0,
     194,     0,     0,     0,   -54,   147,   250,   251,   252,   253,
       0,     0,     0,    37,     0,     0,     0,     0,   157,     0,
      38,    39,    40,   254,   186,   -53,   -53,   -53,   -53,   147,
       0,     0,   149,   255,   -39,   -39,   -39,   -39,   -39,   -39,
       0,   -39,   147,   -53,     0,     0,     0,   149,   -39,   -39,
     -39,   -39,   -39,   -39,     0,   -39,   -39,   -39,   -39,     0,
       0,   -39,     0,     0,   -39,   -39,     0,     0,     0,     0,
       0,   149,     0,     0,     0,     0,     0,   147,   147,   147,
     267,     0,   269,   270,   149,   147,     0,   184,     0,     0,
     184,     0,   184,   184,   184,   294,     0,   296,   297,     0,
     184,     0,   184,     0,     0,   147,   147,     0,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,     0,     0,   147,   149,
     149,   149,   149,   268,   149,   149,   148,   149,     0,   186,
     -65,   -65,   186,     0,   186,   186,   186,   186,   295,   186,
     186,     0,   186,     0,   186,   147,     0,   149,   149,     0,
       0,     0,   277,   278,   279,   280,   148,   148,   146,    37,
     149,     0,     0,     0,     0,     0,    38,    39,    40,   281,
       0,     0,     0,   184,   185,     0,     0,     0,   184,   282,
     233,   -52,   -52,   -52,   -52,   234,   235,   149,   146,   146,
       0,     0,     0,     0,     0,     0,   147,     0,   105,     0,
     185,   -52,   -52,     0,     0,     0,   183,     0,   148,     0,
       0,     0,     0,     0,     0,   186,     0,     0,     0,     0,
     186,     0,     0,   148,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   183,     0,     0,     0,     0,     0,   149,     0,
     146,     0,     0,     0,   -71,    93,     0,   148,     0,     0,
     -71,     0,     0,     0,     0,   146,     0,     0,     0,     0,
     148,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,     0,
       0,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   146,
       0,     0,   -76,   -76,   -76,     0,     0,   -76,     0,     0,
       0,   145,   146,   -72,   -72,   148,   148,   148,   148,     0,
     148,   148,     0,   148,     0,   185,     0,     0,   185,     0,
     185,   185,   185,   185,     0,   185,   185,     0,   185,     0,
     185,   145,   145,   148,   148,     0,     0,   146,   146,   266,
     104,     0,     0,     0,     0,   146,   148,   183,     0,   182,
     183,     0,   183,   183,   293,   144,     0,     0,     0,     0,
     183,     0,   183,     0,     0,   146,   146,     0,     0,     0,
       0,     0,     0,   148,     0,   182,     0,     0,   146,     0,
     143,     0,     0,   145,     0,   144,   144,     0,     0,     0,
       0,     0,     0,   102,     0,     0,     0,     0,   145,     0,
       0,   185,     0,   181,     0,   146,   185,     0,     0,     0,
     143,   143,     0,     0,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   145,     0,   148,     0,   111,     0,   180,   181,
       0,     0,     0,   183,   -82,   145,     0,   144,   183,     0,
     -82,     0,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,   144,     0,   180,     0,   146,     0,     0,     0,
       0,     0,   143,   239,   -71,   -71,     0,     0,   -71,     0,
     145,   265,     0,     0,     0,     0,   144,   143,   145,     0,
     182,     0,     0,   182,     0,   182,   292,     0,     0,   144,
       0,     0,     0,   182,     0,   182,     0,     0,   145,   145,
       0,   143,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
       0,   145,     0,     0,   143,   218,   -52,   -52,   -52,   -52,
     219,   220,   -75,   -75,   256,     0,     0,     0,   -75,     0,
       0,     0,   144,     0,   181,     0,   -52,   181,   145,   283,
       0,     0,     0,     0,     0,     0,     0,   181,     0,   181,
       0,     0,   144,   144,     0,     0,     0,   272,     0,   180,
       0,     0,   180,     0,     0,   144,   182,     0,     0,     0,
       0,   182,   299,     0,   180,     0,     0,   143,   143,   -19,
     -19,   -19,   -19,   -19,   -19,     0,   -19,     0,     0,   145,
     143,     0,   144,   -19,   -19,   -19,   -19,   -19,   -19,     0,
     -19,     0,   -19,   -19,     0,     0,   -19,     0,     0,   -19,
     -19,     0,     0,     0,     0,     0,     0,   143,     0,     0,
     181,     0,     0,     0,     0,   181,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,    90,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,     0,   144,     0,   180,     0,   -75,   -75,   -75,
     180,     0,   -75,     0,   -55,    32,    33,    34,   135,    35,
      36,     0,    37,     0,     0,     0,     0,     0,   143,    38,
      39,    40,    41,     1,     2,     0,    42,     0,    43,    44,
       0,     0,    45,     0,     0,   136,   -22,   -25,   -25,   -25,
     -25,   -25,   -25,     0,   -25,     0,     0,     0,     0,     0,
       0,   -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,     0,
     -25,   -25,     0,     0,   -25,     0,     0,   -25,   -25,   -28,
     -28,   -28,   -28,   -28,   -28,     0,   -28,     0,     0,     0,
       0,     0,     0,   -28,   -28,   -28,   -28,   -28,   -28,     0,
     -28,     0,   -28,   -28,     0,     0,   -28,     0,     0,   -28,
     -28,    32,    33,    34,   135,    35,    36,     0,    37,     0,
       0,     0,     0,     0,     0,    38,    39,    40,    41,     1,
       2,     0,    42,     0,    43,    44,     0,     0,    45,     0,
       0,   136,   -21,   -24,   -24,   -24,   -24,   -24,   -24,     0,
     -24,     0,     0,     0,     0,     0,     0,   -24,   -24,   -24,
     -24,   -24,   -24,     0,   -24,     0,   -24,   -24,     0,     0,
     -24,     0,     0,   -24,   -24,   -26,   -26,   -26,   -26,   -26,
     -26,     0,   -26,     0,     0,     0,     0,     0,     0,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,     0,   -26,   -26,
       0,     0,   -26,     0,     0,   -26,   -26,   -32,   -32,   -32,
     -32,   -32,   -32,     0,   -32,     0,     0,     0,     0,     0,
       0,   -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,     0,
     -32,   -32,     0,     0,   -32,     0,     0,   -32,   -32,   -27,
     -27,   -27,   -27,   -27,   -27,     0,   -27,     0,     0,     0,
       0,     0,     0,   -27,   -27,   -27,   -27,   -27,   -27,     0,
     -27,     0,   -27,   -27,     0,     0,   -27,     0,     0,   -27,
     -27,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,     0,
       0,     0,     0,     0,     0,   -29,   -29,   -29,   -29,   -29,
     -29,     0,   -29,     0,   -29,   -29,     0,     0,   -29,     0,
       0,   -29,   -29,   -30,   -30,   -30,   -30,   -30,   -30,     0,
     -30,     0,     0,     0,     0,     0,     0,   -30,   -30,   -30,
     -30,   -30,   -30,     0,   -30,     0,   -30,   -30,     0,     0,
     -30,     0,     0,   -30,   -30,   -31,   -31,   -31,   -31,   -31,
     -31,     0,   -31,     0,     0,     0,     0,     0,     0,   -31,
     -31,   -31,   -31,   -31,   -31,     0,   -31,     0,   -31,   -31,
       0,     0,   -31,     0,     0,   -31,   -31,   -23,   -23,   -23,
     -23,   -23,   -23,     0,   -23,     0,     0,     0,     0,     0,
       0,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,     0,
     -23,   -23,     0,     0,   -23,     0,     0,   -23,   -23,   -35,
     -35,   -35,   -35,   -35,   -35,     0,   -35,     0,     0,     0,
       0,     0,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
     -35,     0,   -35,   -35,     0,     0,   -35,     0,     0,   -35,
     -35,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,     0,
       0,     0,     0,     0,     0,   -38,   -38,   -38,   -38,   -38,
     -38,     0,   -38,     0,   -38,   -38,     0,     0,   -38,     0,
       0,   -38,   -38,   -33,   -33,   -33,   -33,   -33,   -33,     0,
     -33,     0,     0,     0,     0,     0,     0,   -33,   -33,   -33,
     -33,   -33,   -33,     0,   -33,     0,   -33,   -33,     0,     0,
     -33,     0,     0,   -33,   -33,   -34,   -34,   -34,   -34,   -34,
     -34,     0,   -34,     0,     0,     0,     0,     0,     0,   -34,
     -34,   -34,   -34,   -34,   -34,     0,   -34,     0,   -34,   -34,
       0,     0,   -34,     0,     0,   -34,   -34,   -37,   -37,   -37,
     -37,   -37,   -37,     0,   -37,     0,     0,     0,     0,     0,
       0,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,     0,
     -37,   -37,     0,     0,   -37,     0,     0,   -37,   -37,   -39,
     -39,   -39,   -39,   -39,   -39,     0,   -39,     0,     0,     0,
       0,     0,     0,   -39,   -39,   -39,   -39,   -39,   -39,     0,
     -39,     0,   -39,   -39,     0,     0,   -39,     0,     0,   -39,
     -39,   -10,   -10,   -10,   -10,   -10,   -10,     0,   -10,     0,
       0,     0,     0,     0,     0,   -10,   -10,   -10,   -10,   -10,
     -10,     0,   -10,     0,   -10,   -10,     0,     0,   -10,     0,
       0,   -10,   -10,    -9,    -9,    -9,    -9,    -9,    -9,     0,
      -9,     0,     0,     0,     0,     0,     0,    -9,    -9,    -9,
      -9,    -9,    -9,     0,    -9,     0,    -9,    -9,     0,     0,
      -9,     0,     0,    -9,    -9,   -20,   -20,   -20,   -20,   -20,
     -20,     0,   -20,     0,     0,     0,     0,     0,     0,   -20,
     -20,   -20,   -20,   -20,   -20,     0,   -20,     0,   -20,   -20,
       0,     0,   -20,     0,     0,   -20,   -20,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,     0,     0,     0,     0,   -76,   -76,     0,
       0,     0,     0,   -76,     0,     0,   -76,   -76,     0,     0,
       0,   -76,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,
       0,     0,     0,   224,   -71,     0,     0,     0,   -71,     0,
       0,   -75,   -75,     0,     0,     0,   -75,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,     0,     0,     0,     0,     0,     0,   -82,
     -82,     0,     0,   -82,     0,     0,     0,   -83,   -83,     0,
       0,   -83,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,     0,     0,
       0,     0,     0,     0,   -81,   -81,     0,     0,   -81,     0,
       0,     0,   -84,   -84,     0,     0,   -84,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,     0,     0,     0,     0,     0,     0,   -57,
     -57,     0,     0,   237,     0,     0,     0,   -59,   -59,     0,
       0,   -59,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,
       0,     0,     0,     0,   -65,   -65,     0,     0,   -65,     0,
       0,     0,   -72,   -72,     0,     0,   -72,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,     0,     0,     0,     0,     0,     0,   -73,
     -73,     0,     0,   -73,     0,     0,     0,   -60,   -60,     0,
       0,   -60,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,
       0,     0,     0,     0,   -74,   -74,     0,     0,   -74,     0,
       0,     0,   -66,   -66,     0,     0,   -66,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,     0,     0,     0,     0,   -83,     0,     0,
       0,     0,     0,   -83,     0,   -81,     0,     0,     0,     0,
       0,   -81,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,     0,   -84,     0,     0,     0,     0,     0,   -84,     0,
     -57,     0,     0,     0,     0,     0,    91,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,     0,     0,     0,     0,   -59,     0,     0,
       0,     0,     0,   -59,     0,   -65,     0,     0,     0,     0,
       0,   -65,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
       0,     0,   -72,     0,     0,     0,     0,     0,   -72,     0,
     -73,     0,     0,     0,     0,     0,   -73,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,     0,     0,     0,     0,   -60,     0,     0,
       0,     0,     0,   -60,     0,   -74,     0,     0,     0,     0,
       0,   -74,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,     0,     0,
       0,     0,   -66,     0,     0,     0,     0,     0,   -66,     0,
       0,     0,   -82,     0,     0,     0,   -82,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,     0,     0,     0,     0,     0,     0,   -83,
       0,     0,     0,   -83,     0,     0,     0,   -81,     0,     0,
       0,   -81,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,     0,     0,     0,   -84,     0,     0,     0,   -84,     0,
       0,     0,   -57,     0,     0,     0,   222,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,     0,     0,     0,     0,     0,     0,   -59,
       0,     0,     0,   -59,     0,     0,     0,   -65,     0,     0,
       0,   -65,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
       0,     0,     0,     0,   -72,     0,     0,     0,   -72,     0,
       0,     0,   -73,     0,     0,     0,   -73,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,     0,     0,     0,     0,     0,     0,   -60,
       0,     0,     0,   -60,     0,     0,     0,   -74,     0,     0,
       0,   -74,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,     0,     0,
       0,     0,     0,     0,   -66,     0,     0,     0,   -66,     0,
       0,   -76,   -76,   -76,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
       0,     0,     0,     0,     0,   315,   -71,   -71,     0,     0,
       0,     0,     0,   -75,   -75,   -75,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   236,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,     0,     0,     0,   -73,   -73,
       0,     0,     0,     0,     0,     0,   -56,   -56,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,     0,     0,     0,     0,     0,     0,
     -58,   -58,     0,     0,     0,     0,     0,     0,   -60,   -60,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,     0,
       0,     0,   -74,   -74,     0,     0,     0,     0,     0,     0,
     -66,   -66,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,
       0,     0,     0,   -76,   -76,     0,     0,     0,     0,     0,
       0,   310,   -71,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   221,   -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,
       0,     0,     0,     0,   -75,   -75,     0,     0,     0,     0,
       0,     0,     0,   -55,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
       0,     0,     0,     0,     0,     0,   -82,     0,     0,     0,
       0,     0,     0,     0,   -83,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,     0,     0,     0,     0,     0,     0,   -81,     0,     0,
       0,     0,     0,     0,     0,   -84,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,     0,     0,     0,     0,     0,     0,   -57,     0,
       0,     0,     0,     0,     0,     0,   -59,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,     0,     0,     0,   -65,
       0,     0,     0,     0,     0,     0,     0,   -72,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   221,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,     0,     0,     0,     0,     0,     0,
     -73,     0,     0,     0,     0,     0,     0,     0,   -56,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,     0,     0,     0,     0,     0,
       0,   -58,     0,     0,     0,     0,     0,     0,     0,   -60,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,     0,
       0,     0,   -74,     0,     0,     0,     0,     0,     0,     0,
     -66,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,     0,
       0,   -76,   -76,     0,     0,     0,     0,     0,     0,   -71,
     227,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,
       0,   -75,   -75,     0,     0,     0,     0,     0,     0,   -57,
      90,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,
     -56,     0,     0,     0,     0,     0,     0,     0,   -58,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,     0,     0,     0,     0,   -82,
       0,     0,     0,     0,     0,     0,     0,   -83,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,     0,     0,     0,     0,   -81,     0,
       0,     0,     0,     0,     0,     0,   -84,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,     0,     0,     0,     0,   -59,     0,     0,
       0,     0,     0,     0,     0,   -65,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,     0,     0,     0,     0,   -72,     0,     0,     0,
       0,     0,     0,     0,   -73,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     0,     0,     0,     0,   -60,    87,   -52,   -52,   -52,
     -52,    88,    89,   -74,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,     0,     0,     0,   -52,     0,     0,     0,     0,
       0,     0,     0,     0,   -66
};

static const yytype_int16 yycheck[] =
{
       8,    27,   118,   224,   136,     6,   227,    13,   212,     0,
       6,   127,     6,     4,    13,    23,     0,     6,   239,    29,
       4,     0,    23,    29,     6,     6,    31,    18,    29,    23,
     117,     0,    31,    29,    25,    29,   117,    45,   117,   126,
      29,   117,   246,   130,   117,     6,   117,    29,    29,    29,
      30,     6,    21,    22,    13,    29,    30,     3,     4,     5,
       6,    33,    23,    71,    10,     0,    74,    75,    76,   201,
      29,    17,    18,    19,    20,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    30,    93,    21,    22,     0,   310,
      13,   117,    31,    32,   315,    21,    22,    21,    22,     3,
       4,     5,     6,     7,     8,    31,    10,    31,    31,    21,
      22,   119,    13,    17,    18,    19,    20,    44,    45,   127,
      24,    30,    26,    27,     0,     6,    30,    33,   244,    33,
      31,    32,    31,    32,   142,     0,    30,     3,     4,     5,
       6,     0,    23,   151,    10,    21,    22,     0,    75,    76,
      77,    17,    18,    19,    20,    30,    21,    22,   166,   167,
       0,    30,    21,    22,    30,    31,    93,    34,    21,    22,
       6,   179,     3,     4,     5,     6,     7,     8,    29,    10,
     188,    21,    22,    29,    12,    13,    17,    18,    19,    20,
     117,   118,   119,    24,    31,    26,    27,    21,    22,    30,
     127,    31,    33,    31,   320,    31,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   142,   224,   333,    13,   227,
       0,   229,   230,   231,   232,   233,   234,   235,   236,   237,
      29,   239,   319,   241,   242,   243,    31,    32,   319,   166,
     319,    21,    22,   319,    31,   332,   319,   255,   319,   336,
     258,   332,   179,   332,    29,   336,   332,   336,     0,   332,
     336,   332,    29,   336,    30,   336,    31,    32,     3,     4,
       5,     6,    31,   200,   282,    10,    31,   285,    29,    21,
      22,    29,    17,    18,    19,    20,    12,    13,    11,    12,
      13,    14,    45,   319,    31,    30,    31,   224,    31,    32,
     227,    29,   310,    12,    13,    31,   332,   315,    31,    32,
     336,    29,   239,    66,    29,   242,   243,   244,    31,    32,
      29,    29,    75,    76,    30,   333,    31,    32,   255,    30,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    30,
      93,    11,    12,    13,    14,    31,     3,     4,     5,     6,
       7,     8,     6,    10,     6,   282,    12,    13,    14,    29,
      17,    18,    19,    20,    21,    22,   119,    24,    25,    26,
      27,    12,    13,    30,   127,    31,    33,    34,    31,    11,
      12,    13,    14,   310,    11,    12,    13,    14,   315,   142,
      31,    32,   319,   320,    11,    12,    13,    14,   151,    31,
      32,    31,    32,    31,    31,   332,   333,    12,    13,   336,
      31,    32,    29,   166,   167,     3,     4,     5,     6,     7,
       8,    31,    10,    29,    29,    34,   179,    31,    31,    17,
      18,    19,    20,    21,    22,   188,    24,    25,    26,    27,
      12,    13,    30,    29,    31,    33,    34,    31,    31,    31,
       9,    10,    11,    12,    13,    14,    15,    16,    34,    31,
      32,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      45,   224,    31,    32,   227,    31,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    31,   239,    29,    29,   242,
     243,    31,    31,    29,    31,     4,    94,    25,    49,    -1,
      75,    76,   255,    -1,    -1,   258,    -1,    -1,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,   282,
      -1,    -1,   285,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,   119,    -1,    30,    -1,    -1,    33,
      34,    -1,   127,    -1,    -1,    -1,    -1,   310,     3,     4,
       5,     6,   315,    -1,    -1,    10,    -1,   142,    11,    12,
      13,    14,    17,    18,    19,    20,   151,    -1,    -1,    -1,
     333,    -1,    -1,    -1,    29,    30,    -1,    -1,    31,    32,
      -1,   166,   167,     3,     4,     5,     6,     7,     8,    -1,
      10,    12,    13,    14,   179,    -1,    -1,    17,    18,    19,
      20,    21,    22,   188,    24,    25,    26,    27,    29,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    12,    13,    14,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    45,   224,
      31,    32,   227,    29,   229,   230,   231,   232,   233,   234,
     235,   236,   237,    -1,   239,    -1,    -1,   242,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
     255,    -1,    -1,   258,    -1,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,   282,    -1,    -1,
     285,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,   119,    -1,    30,    -1,    -1,    33,    34,    -1,
     127,    -1,    -1,    -1,    -1,   310,     3,     4,     5,     6,
     315,    -1,    -1,    10,    -1,   142,    11,    12,    13,    14,
      17,    18,    19,    20,   151,    -1,    -1,    -1,   333,    11,
      12,    13,    14,    30,    -1,    -1,    31,    32,    -1,   166,
     167,     3,     4,     5,     6,     7,     8,    -1,    10,    31,
      32,    -1,   179,    -1,    -1,    17,    18,    19,    20,    21,
      22,   188,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    45,   224,    31,    32,
     227,    -1,   229,   230,   231,   232,   233,   234,   235,   236,
     237,    -1,   239,    -1,    -1,   242,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,   255,    -1,
      -1,   258,    -1,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    93,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,   282,    -1,    -1,   285,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
     119,    -1,    30,    -1,    -1,    33,    34,    -1,   127,    -1,
      -1,    -1,    -1,   310,     3,     4,     5,     6,   315,    -1,
      -1,    10,    -1,   142,    11,    12,    13,    14,    17,    18,
      19,    20,   151,    -1,    -1,    -1,   333,    11,    12,    13,
      14,    30,    -1,    -1,    31,    32,    -1,   166,   167,     3,
       4,     5,     6,     7,     8,    -1,    10,    31,    -1,    -1,
     179,    -1,    -1,    17,    18,    19,    20,    21,    22,   188,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    45,   224,    31,    32,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,   236,   237,    -1,
     239,    -1,    -1,   242,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,   255,    -1,    -1,   258,
      -1,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,   282,    -1,    -1,   285,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,   119,    -1,
      30,    -1,    -1,    33,    34,    -1,   127,    11,    12,    13,
      14,   310,     3,     4,     5,     6,   315,    -1,    -1,    10,
      -1,   142,    12,    13,    14,    29,    17,    18,    19,    20,
     151,    -1,    -1,    -1,   333,    11,    12,    13,    14,    30,
      -1,    31,    32,    -1,    -1,   166,   167,     3,     4,     5,
       6,     7,     8,    -1,    10,    31,    -1,    -1,   179,    -1,
      -1,    17,    18,    19,    20,    21,    22,   188,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    45,   224,    31,    32,   227,    -1,   229,   230,
     231,   232,   233,   234,   235,   236,   237,    -1,   239,    -1,
      -1,   242,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,   255,    -1,    -1,   258,    -1,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,   282,    -1,    -1,   285,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,   119,    -1,    30,    -1,
      -1,    33,    34,    -1,   127,    -1,    -1,    -1,    -1,   310,
       3,     4,     5,     6,   315,    -1,    -1,    10,    -1,   142,
      11,    12,    13,    14,    17,    18,    19,    20,   151,    -1,
      -1,    -1,   333,    11,    12,    13,    14,    30,    -1,    -1,
      31,    -1,    -1,   166,   167,     3,     4,     5,     6,     7,
       8,    -1,    10,    31,    -1,    -1,   179,    -1,    -1,    17,
      18,    19,    20,    21,    22,   188,    24,    25,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      45,   224,    31,    32,   227,    -1,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,    -1,    -1,   242,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,   255,    -1,    -1,   258,    -1,    -1,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,   282,
      -1,    -1,   285,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,   119,    -1,    30,    -1,    -1,    33,
      34,    -1,   127,    -1,    -1,    -1,    -1,   310,     3,     4,
       5,     6,   315,    -1,    -1,    10,    -1,   142,    11,    12,
      13,    14,    17,    18,    19,    20,   151,    -1,    -1,    -1,
     333,    -1,    12,    13,    14,    30,    -1,    -1,    31,    -1,
      -1,   166,   167,     3,     4,     5,     6,     7,     8,    -1,
      10,    31,    32,    -1,   179,    -1,    -1,    17,    18,    19,
      20,    21,    22,   188,    24,    25,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    45,   224,
      31,    32,   227,    -1,   229,   230,   231,   232,   233,   234,
     235,   236,   237,    -1,   239,    -1,    -1,   242,   243,    -1,
       3,     4,     5,     6,    12,    13,    14,    10,    75,    76,
     255,    -1,    -1,   258,    17,    18,    19,    20,    -1,    86,
      45,    88,    89,    31,    -1,    -1,    93,    30,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,   282,    -1,    -1,
     285,    -1,    17,    18,    19,    20,    11,    12,    13,    14,
      75,    76,   119,    -1,    -1,    30,    11,    12,    13,    14,
     127,    -1,    87,    -1,    29,   310,    -1,    -1,    93,    -1,
     315,    -1,    -1,    -1,    29,   142,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,   333,    -1,
      17,    18,    19,    20,   119,    11,    12,    13,    14,   166,
      -1,    -1,   127,    30,     3,     4,     5,     6,     7,     8,
      -1,    10,   179,    29,    -1,    -1,    -1,   142,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,    -1,   219,   220,   179,   222,    -1,   224,    -1,    -1,
     227,    -1,   229,   230,   231,   232,    -1,   234,   235,    -1,
     237,    -1,   239,    -1,    -1,   242,   243,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,   255,   214,
     215,   216,   217,   218,   219,   220,    45,   222,    -1,   224,
      31,    32,   227,    -1,   229,   230,   231,   232,   233,   234,
     235,    -1,   237,    -1,   239,   282,    -1,   242,   243,    -1,
      -1,    -1,     3,     4,     5,     6,    75,    76,    45,    10,
     255,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,   310,    93,    -1,    -1,    -1,   315,    30,
      10,    11,    12,    13,    14,    15,    16,   282,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,   333,    -1,    85,    -1,
     119,    31,    32,    -1,    -1,    -1,    93,    -1,   127,    -1,
      -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,    -1,
     315,    -1,    -1,   142,     9,    10,    11,    12,    13,    14,
      15,    16,   119,    -1,    -1,    -1,    -1,    -1,   333,    -1,
     127,    -1,    -1,    -1,    29,    30,    -1,   166,    -1,    -1,
      35,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
     179,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,   166,
      -1,    -1,    30,    31,    32,    -1,    -1,    35,    -1,    -1,
      -1,    45,   179,    31,    32,   214,   215,   216,   217,    -1,
     219,   220,    -1,   222,    -1,   224,    -1,    -1,   227,    -1,
     229,   230,   231,   232,    -1,   234,   235,    -1,   237,    -1,
     239,    75,    76,   242,   243,    -1,    -1,   214,   215,   216,
      84,    -1,    -1,    -1,    -1,   222,   255,   224,    -1,    93,
     227,    -1,   229,   230,   231,    45,    -1,    -1,    -1,    -1,
     237,    -1,   239,    -1,    -1,   242,   243,    -1,    -1,    -1,
      -1,    -1,    -1,   282,    -1,   119,    -1,    -1,   255,    -1,
      45,    -1,    -1,   127,    -1,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,   142,    -1,
      -1,   310,    -1,    93,    -1,   282,   315,    -1,    -1,    -1,
      75,    76,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,   166,    -1,   333,    -1,    91,    -1,    93,   119,
      -1,    -1,    -1,   310,    29,   179,    -1,   127,   315,    -1,
      35,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,   142,    -1,   119,    -1,   333,    -1,    -1,    -1,
      -1,    -1,   127,    30,    31,    32,    -1,    -1,    35,    -1,
     214,   215,    -1,    -1,    -1,    -1,   166,   142,   222,    -1,
     224,    -1,    -1,   227,    -1,   229,   230,    -1,    -1,   179,
      -1,    -1,    -1,   237,    -1,   239,    -1,    -1,   242,   243,
      -1,   166,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,   255,    -1,    -1,   179,    10,    11,    12,    13,    14,
      15,    16,    29,    30,   214,    -1,    -1,    -1,    35,    -1,
      -1,    -1,   222,    -1,   224,    -1,    31,   227,   282,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,    -1,   239,
      -1,    -1,   242,   243,    -1,    -1,    -1,   222,    -1,   224,
      -1,    -1,   227,    -1,    -1,   255,   310,    -1,    -1,    -1,
      -1,   315,   237,    -1,   239,    -1,    -1,   242,   243,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,   333,
     255,    -1,   282,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,   282,    -1,    -1,
     310,    -1,    -1,    -1,    -1,   315,     9,    10,    11,    12,
      13,    14,    15,    16,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,   333,    -1,   310,    -1,    30,    31,    32,
     315,    -1,    35,    -1,    29,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,   333,    17,
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
       0,    21,    22,    37,    38,    39,    40,    42,    76,    23,
      23,     0,    39,     6,    29,    75,    30,    41,    43,    29,
      45,    46,    47,    76,    31,    32,    75,    44,    47,    33,
      48,    49,     3,     4,     5,     7,     8,    10,    17,    18,
      19,    20,    24,    26,    27,    30,    40,    48,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    73,    74,
      75,    76,    77,    78,    30,    30,    30,    30,    59,    59,
      34,    52,    29,    13,    12,    14,    11,    10,    15,    16,
       9,    35,    68,    30,    75,    75,    59,    59,    59,    60,
      29,    31,    62,    68,    63,    64,    65,    67,    65,    65,
      68,    61,    59,    71,    72,    31,    31,    31,    29,    32,
      31,    29,    29,    53,    60,    59,    25,    29,    53,    60,
      31,    53,    21,    22,     6,     6,    33,     3,     4,     5,
       6,    20,    30,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    73,    74,    75,    77,    78,     6,    29,
       6,     3,     4,     5,     6,    20,    30,    69,    70,    73,
      74,    75,    77,    78,     3,     4,     5,     6,    20,    30,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      73,    74,    75,    77,    78,    41,     7,     8,    24,    26,
      27,    33,    48,    54,    55,    56,    57,    58,    59,    59,
      23,    23,    49,    59,    13,    12,    14,    11,    10,    15,
      16,     9,    35,    68,    30,    59,    68,    30,    59,    13,
      12,    14,    11,    10,    15,    16,     9,    35,    68,    30,
      29,    30,    30,    30,    30,    59,    49,    29,    50,    31,
       3,     4,     5,     6,    20,    30,    62,    68,    69,    70,
      73,    74,    75,    77,    78,    63,    64,    65,    67,    65,
      65,    68,    61,    72,    31,    72,    31,     3,     4,     5,
       6,    20,    30,    62,    68,    69,    70,    73,    74,    75,
      77,    78,    63,    64,    65,    67,    65,    65,    68,    61,
      72,    75,    59,    59,    60,    29,    50,    34,    59,    68,
      30,    31,    31,    59,    68,    30,    31,    31,    31,    31,
      29,    34,    31,    72,    31,    72,    29,    29,    53,    60,
      31,    31,    25,    29,    53,    60,    31,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    41,    40,
      40,    43,    44,    42,    45,    45,    46,    46,    47,    49,
      48,    50,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    56,    56,    57,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    74,    75,    76,    76,    76,
      76,    77,    77,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     0,     4,
       2,     0,     0,     8,     0,     1,     3,     1,     2,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     2,     5,     7,     3,     9,
       1,     3,     0,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     4,     1,     3,     1,
       0,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1
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
#line 2181 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 69 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2187 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 69 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2193 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2199 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2205 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2211 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2217 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2223 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2229 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2235 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2241 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2247 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2253 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2259 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2265 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2271 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2277 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2283 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2289 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2295 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_1: /* @1  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2301 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2307 "src/bison/grammar.c"
        break;

    case YYSYMBOL_43_2: /* @2  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2313 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2319 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2325 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2331 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2337 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2343 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2349 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2355 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2361 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2367 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2373 "src/bison/grammar.c"
        break;

    case YYSYMBOL_60_expression_opt: /* expression.opt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2379 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2385 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2391 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2397 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2403 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2409 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2415 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2421 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2427 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2433 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2439 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2445 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id_expr: /* id_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2451 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2457 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2463 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2469 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2475 "src/bison/grammar.c"
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
  case 3: /* prog: %empty  */
#line 75 "src/bison/grammar.y"
             {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("ISO C-IPL forbids an empty translation unit\n", error_cursor);
    }
#line 2749 "src/bison/grammar.c"
    break;

  case 4: /* external_declaration_list: external_declaration_list external_declaration  */
#line 81 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 2755 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration  */
#line 82 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 2761 "src/bison/grammar.c"
    break;

  case 8: /* @1: %empty  */
#line 89 "src/bison/grammar.y"
                              {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].ast)->value.symref->symbol);
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-1].pchar));
        if (sym) {
            if (sym->scope) {
                yyerror(NULL);
                CIPL_PERROR_CURSOR("redeclaration of '%s'\n", error_cursor, (yyvsp[0].ast)->value.symref->symbol->name);
            } else if (sym->is_fn) {
                yyerror(NULL);
                CIPL_PERROR_CURSOR("'%s' redeclared as different kind of symbol\n", error_cursor, (yyvsp[0].ast)->value.symref->symbol->name);
            } else if (sym->type != decl_type) {
                yyerror(NULL);
                CIPL_PERROR_CURSOR("conflicting types for '%s'\n", error_cursor, (yyvsp[0].ast)->value.symref->symbol->name);
            } 
            (yyval.ast) = NULL;
        }
        else {
            Symbol *declared = context_declare_variable(current_context, (yyvsp[0].ast)->value.symref);
            symbol_update_type(declared, decl_type);
            (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
        }
        ast_free((yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2790 "src/bison/grammar.c"
    break;

  case 9: /* var_declaration: type id @1 ';'  */
#line 112 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 2798 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type ';'  */
#line 115 "src/bison/grammar.y"
               {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("useless '%s' in empty declaration\n", error_cursor, (yyvsp[-1].pchar));
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
    }
#line 2809 "src/bison/grammar.c"
    break;

  case 11: /* @2: %empty  */
#line 123 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[-1].ast)->value.symref->symbol);
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-2].pchar));

        // always push a context for the function even if not valid so is possible to pop later
        previous_context = current_context;
        list_push(&contexts, context_init((yyvsp[-1].ast)->value.symref->symbol->name));
        current_context = list_peek_last(&contexts);

        if (sym) {
            yyerror(NULL);
            if (!sym->is_fn) {
                CIPL_PERROR_CURSOR("'%s' redeclared as different kind of symbol\n", error_cursor, (yyvsp[-1].ast)->value.symref->symbol->name);
            } else if (sym->type != decl_type) {
                CIPL_PERROR_CURSOR("conflicting types for '%s'\n", error_cursor, (yyvsp[-1].ast)->value.symref->symbol->name);
            } else {
                CIPL_PERROR_CURSOR("redefinition of '%s'\n", error_cursor, (yyvsp[-1].ast)->value.symref->symbol->name);
            }
            (yyval.ast) = NULL;
        } else {
            Symbol *declared = context_declare_function(previous_context, (yyvsp[-1].ast)->value.symref);
            symbol_update_type(declared, decl_type);
            (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        ast_free((yyvsp[-1].ast));
        free((yyvsp[-2].pchar));
    }
#line 2845 "src/bison/grammar.c"
    break;

  case 12: /* $@3: %empty  */
#line 153 "src/bison/grammar.y"
                         {
        LIST_FOR_EACH((yyvsp[-1].list), {
            SymbolRefAST *symref = ((AST *)__IT__->data)->value.symref;
            Symbol *sym = context_has_symbol(current_context, symref->symbol);
            if (sym) {
                yyerror(NULL);
                CIPL_PERROR_CURSOR("redefinition of parameter '%s'\n", error_cursor, symref->symbol->name);
            } else {
                context_declare_variable(current_context, symref);
            }
        });
        // hack to save the scope of params and append to the scope of the body
        params_scope = scope_init_copy(stack_peek(&current_context->scopes));
        stack_pop(&current_context->scopes, free_scope_cb);
    }
#line 2865 "src/bison/grammar.c"
    break;

  case 13: /* func_declaration: type id '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 167 "src/bison/grammar.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 2874 "src/bison/grammar.c"
    break;

  case 14: /* param_list.opt: %empty  */
#line 173 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 2880 "src/bison/grammar.c"
    break;

  case 16: /* params_list: params_list ',' param_decl  */
#line 177 "src/bison/grammar.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2886 "src/bison/grammar.c"
    break;

  case 17: /* params_list: param_decl  */
#line 178 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2892 "src/bison/grammar.c"
    break;

  case 18: /* param_decl: type id  */
#line 181 "src/bison/grammar.y"
                    {
        symbol_update_context((yyvsp[0].ast)->value.symref->symbol, current_context);
        symbol_update_type((yyvsp[0].ast)->value.symref->symbol, symbol_type_from_str((yyvsp[-1].pchar)));
        (yyval.ast) = ast_symref_init(symbol_init_copy((yyvsp[0].ast)->value.symref->symbol));
        ast_free((yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2904 "src/bison/grammar.c"
    break;

  case 19: /* $@4: %empty  */
#line 190 "src/bison/grammar.y"
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
#line 2920 "src/bison/grammar.c"
    break;

  case 20: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 200 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 2932 "src/bison/grammar.c"
    break;

  case 21: /* block_item_list.opt: block_item_list  */
#line 209 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 2938 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list.opt: %empty  */
#line 210 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 2944 "src/bison/grammar.c"
    break;

  case 23: /* block_item_list: block_item_list block_item  */
#line 213 "src/bison/grammar.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2950 "src/bison/grammar.c"
    break;

  case 24: /* block_item_list: block_item  */
#line 214 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2956 "src/bison/grammar.c"
    break;

  case 33: /* io_stmt: READ '(' id ')' ';'  */
#line 229 "src/bison/grammar.y"
                             {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].ast)->value.symref->symbol);
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(func)), ast_symref_init(symbol_init_copy(param)));
        symbol_free((yyvsp[-4].sym));
        ast_free((yyvsp[-2].ast));
    }
#line 2968 "src/bison/grammar.c"
    break;

  case 34: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 236 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(sym)), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 2978 "src/bison/grammar.c"
    break;

  case 35: /* expr_stmt: expression ';'  */
#line 243 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2984 "src/bison/grammar.c"
    break;

  case 36: /* cond_stmt: IF '(' expression ')' statement  */
#line 246 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 2992 "src/bison/grammar.c"
    break;

  case 37: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 249 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3000 "src/bison/grammar.c"
    break;

  case 38: /* jmp_stmt: RETURN expression ';'  */
#line 254 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 3006 "src/bison/grammar.c"
    break;

  case 39: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 257 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3014 "src/bison/grammar.c"
    break;

  case 41: /* expression: unary_expr '=' logical_or_expr  */
#line 263 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3020 "src/bison/grammar.c"
    break;

  case 42: /* expression.opt: %empty  */
#line 266 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 3026 "src/bison/grammar.c"
    break;

  case 45: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 271 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3035 "src/bison/grammar.c"
    break;

  case 47: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 278 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3044 "src/bison/grammar.c"
    break;

  case 49: /* eq_expr: eq_expr EQ rel_expr  */
#line 285 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3053 "src/bison/grammar.c"
    break;

  case 51: /* rel_expr: rel_expr REL list_expr  */
#line 292 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3062 "src/bison/grammar.c"
    break;

  case 53: /* list_expr: add_expr DL_DG list_expr  */
#line 299 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3071 "src/bison/grammar.c"
    break;

  case 54: /* list_expr: add_expr COLON list_expr  */
#line 303 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3080 "src/bison/grammar.c"
    break;

  case 56: /* add_expr: add_expr ADD mult_expr  */
#line 310 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3089 "src/bison/grammar.c"
    break;

  case 58: /* mult_expr: mult_expr MULT unary_expr  */
#line 317 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3098 "src/bison/grammar.c"
    break;

  case 60: /* unary_expr: unary_ops unary_expr  */
#line 324 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3107 "src/bison/grammar.c"
    break;

  case 66: /* postfix_expr: id_expr '(' arg_expr_list.opt ')'  */
#line 337 "src/bison/grammar.y"
                                        {
        (yyval.ast) = ast_funcall_init((yyvsp[-3].ast), ast_params_init((yyvsp[-1].list)));
    }
#line 3115 "src/bison/grammar.c"
    break;

  case 67: /* arg_expr_list: expression  */
#line 342 "src/bison/grammar.y"
                          { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3121 "src/bison/grammar.c"
    break;

  case 68: /* arg_expr_list: arg_expr_list ',' expression  */
#line 343 "src/bison/grammar.y"
                                   { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3127 "src/bison/grammar.c"
    break;

  case 70: /* arg_expr_list.opt: %empty  */
#line 347 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3133 "src/bison/grammar.c"
    break;

  case 74: /* primary_expr: '(' expression ')'  */
#line 353 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 3139 "src/bison/grammar.c"
    break;

  case 75: /* id_expr: id  */
#line 356 "src/bison/grammar.y"
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
#line 3156 "src/bison/grammar.c"
    break;

  case 76: /* id: NAME  */
#line 370 "src/bison/grammar.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 3162 "src/bison/grammar.c"
    break;

  case 79: /* type: INT LIST  */
#line 375 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3174 "src/bison/grammar.c"
    break;

  case 80: /* type: FLOAT LIST  */
#line 382 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3186 "src/bison/grammar.c"
    break;

  case 81: /* constant: NUMBER_REAL  */
#line 391 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 3192 "src/bison/grammar.c"
    break;

  case 82: /* constant: NUMBER_INT  */
#line 392 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3198 "src/bison/grammar.c"
    break;

  case 83: /* constant: NIL  */
#line 393 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3204 "src/bison/grammar.c"
    break;

  case 84: /* string_literal: STR_LITERAL  */
#line 396 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 3213 "src/bison/grammar.c"
    break;


#line 3217 "src/bison/grammar.c"

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

#line 402 "src/bison/grammar.y"


void yyerror(const char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    if (s) CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
    ++errors_count;
}
