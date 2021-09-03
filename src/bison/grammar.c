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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4027

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  331

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
     339,   340,   341,   344,   347,   348,   349,   356,   365,   366,
     367,   370
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
     275,   276,   277,   278,   279,   280,   281,   282,   283,    59,
      40,    41,    44,   123,   125,    61
};
#endif

#define YYPACT_NINF (-218)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-82)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,    -3,    10,    85,   108,   137,   160,    19,    22,    32,
    -218,   178,   -11,   211,    94,   462,    -2,   464,   237,    16,
     203,   239,    43,    27,   113,   242,    36,   274,  2060,   263,
    2092,   550,   724,   898,    59,    67,    53,   386,  1378,  1612,
    1072,   157,   167,  1646,  1714,  2124,  2156,   182,  2188,  2220,
    2252,  2284,  2316,  2348,  2380,  2412,   197,    75,   420,  1356,
     359,   542,  3989,  1292,  1246,  1646,  3038,  3046,  1980,    58,
    3073,  3081,   236,  1714,  1714,   166,   221,   223,   293,  2444,
    2476,  1788,  1788,  1788,  1788,  1788,  1788,  1788,  1788,  1788,
    3108,     4,   246,   234,   255,   272,   265,   284,  2508,  3116,
     467,  1344,  1402,   716,   890,  3824,  1064,  1238,  3832,   107,
     289,   343,   285,   295,   305,    95,   166,  1859,  3143,  2540,
    2572,   333,   313,   363,  1429,   135,  2604,   291,  1429,  2636,
     103,   238,   456,  2766,  2060,  3151,  3178,  3186,  2793,  3213,
    1714,    -1,   370,    80,   334,   366,   943,  3584,  3221,  1714,
    3248,  3256,  2801,  3283,  3291,   315,  2668,   325,  3853,  3861,
    3882,   596,  3890,  1714,  1788,  3911,  3919,   770,  3940,  3948,
    2828,  2836,  2863,   267,  2871,  1714,    23,   119,   161,   537,
     711,   399,   607,  2898,  1859,  2906,  2933,  2758,  2941,  2968,
     335,   332,   338,   357,   387,  1646,  2060,   417,   507,   570,
     681,   744,   855,   371,   395,   261,   412,  2092,   398,  1882,
    1882,  1882,  1882,  1882,  1882,  1882,  1882,  1882,  3318,     4,
     409,  3969,     4,   421,  2008,  2008,  2008,  2008,  2008,  2008,
    2008,  2008,  2008,  2976,     4,  2700,   236,  1714,  1714,   166,
     419,  2092,   918,   431,  3326,  3607,  3615,  3638,  3553,  3646,
    1714,   433,  3669,  1882,  3677,  3700,  3576,  3708,  3731,   277,
    1388,  1398,  3739,  1430,  1518,  3762,   136,   436,  3977,   446,
    3003,   781,   955,  1129,  3361,  1303,  1714,   131,  3393,  2008,
    3417,  3425,  3385,  3449,  3457,  1561,   885,  1059,  3481,  1116,
    1233,  3489,   148,   458,   459,   477,   485,   469,  1029,   484,
    2732,   488,  3770,     4,  3353,  3998,   490,  3513,     4,  3011,
     493,   501,    95,   166,  1092,  3793,   505,  3521,   508,  1203,
    1266,  1461,   509,  3801,  3545,    95,   135,  1946,   511,    95,
    2026
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
       0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -218,  -218,   541,   191,   453,  -218,  -218,  -218,  -218,  -218,
     522,   -25,  -128,  -196,  -218,   524,   -84,   -74,   -73,   -72,
     -65,   -63,    73,  -112,  1766,  1698,  1634,  1528,  1288,  1460,
    1333,   244,   418,   592,  -218,  -217,   766,    -7,    29,   940,
    1114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,    45,    16,     6,    17,    26,    19,    20,
      21,    46,    30,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    97,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   111,   112,    67,    68,    69,    70,
      71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    29,   267,   -74,   122,   269,   207,   170,   171,   172,
     173,   243,   209,   127,    36,    25,   -75,   293,   -73,   -73,
       8,    37,    38,    39,   174,    12,   -74,    18,   -76,     7,
     -38,   121,     7,     9,   175,   -68,   224,   152,   -77,   -75,
     126,   198,   199,   200,   129,   299,    22,    23,    13,   132,
     201,   -76,   202,    22,   -38,   -38,   -61,   -61,   -61,   -61,
     -10,   -77,    92,   -61,   155,    93,   152,   152,   241,    28,
     -61,   -61,   -61,   -61,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   -61,   187,    10,   316,   156,    81,    72,
     197,   318,   -44,   -44,   211,     1,     2,    73,    31,    32,
      33,   133,   191,   192,   -38,    36,     1,     2,    -3,   -74,
     187,   -44,    37,    38,    39,    40,    76,    77,   152,   193,
      81,   194,   195,    -6,    15,    44,   205,   297,   196,    -3,
      -3,   225,   -42,   152,   130,   131,   -39,    -5,   135,   136,
     137,   138,   152,   225,   -43,    36,    94,    95,    96,   209,
     -42,   -42,    37,    38,    39,   139,   152,   167,    -5,    -5,
      -4,   224,   -43,   -43,   110,   140,   -40,   -39,   152,    31,
      32,    33,   133,   -44,   -44,   226,    36,   187,    -2,   -39,
     -39,    -4,    -4,    37,    38,    39,    40,    74,   203,    96,
     123,     5,   -44,   -44,     5,   -40,    44,    75,   204,    -2,
      -2,   322,   256,   256,   256,   256,   256,   256,   256,   256,
     256,    -8,   187,   208,   328,   187,    78,   282,   282,   282,
     282,   282,   282,   282,   282,   282,    80,   187,   321,   294,
     152,   152,    -8,    -8,   -13,    24,   220,    -7,   198,   199,
     200,   327,   157,   152,   -75,   330,   256,   201,   223,   202,
      98,   198,   199,   200,    99,   198,   199,   200,    -7,    -7,
     201,   206,   202,   -11,   201,   113,   202,   -76,   240,   152,
     -15,   -15,   282,   -16,   -16,    -6,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -11,   -11,   114,   197,   148,   -45,
     -45,   211,   110,   -18,   -41,   110,   187,   -73,   -73,   -73,
     197,   187,   -73,   115,   197,   -14,   -14,   110,   -45,    90,
     295,   296,    96,   116,   -18,   -18,   118,   148,   148,   152,
     -65,   -65,   128,   301,   119,   101,   101,   101,   101,   101,
     101,   101,   108,   101,   120,   183,   -34,   -34,   -34,   -34,
     -34,   -34,   125,   -34,   -73,   212,   -46,   -46,   -46,   306,
     -34,   -34,   -34,   -34,   -34,   -34,   -73,   -34,   124,   -34,
     -34,   183,   236,   -34,   235,   -46,   -34,   -34,   237,   148,
      84,   -46,   -46,   -46,   -67,   117,   110,   -48,   -48,   -48,
     -48,   110,   210,   -42,   148,   203,    96,   238,   -46,   -59,
     -59,   -59,   -59,   218,   -66,   -66,   -59,   -48,   203,   204,
     242,   -42,   203,   -59,   -59,   -59,   -59,   148,   221,   228,
     -50,   -50,   -50,   -50,   229,   230,   -59,   239,   -77,   148,
     -26,   -26,   -26,   -26,   -26,   -26,   -41,   -26,   233,   244,
     -50,   -50,    82,   -42,   -26,   -26,   -26,   -26,   -26,   -26,
     268,   -26,   -26,   -26,   -26,   210,   -43,   -26,   298,   -42,
     -26,   -26,   270,   252,   252,   252,   252,   252,   252,   252,
     265,   252,   149,   183,   -43,   300,   183,   304,   278,   278,
     278,   278,   278,   278,   278,   291,   278,   305,   183,    82,
     -43,   148,   148,    -9,    -9,   130,   131,   -73,   -73,   309,
     310,   149,   149,    -9,   148,   -12,   -43,   302,   313,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   311,   184,
     -30,   -30,   -30,   -30,   -30,   -30,   312,   -30,   314,   315,
     148,   317,   319,   307,   -30,   -30,   -30,   -30,   -30,   -30,
     320,   -30,   -30,   -30,   -30,   184,   323,   -30,   326,   324,
     -30,   -30,   329,   149,    11,   190,    27,   183,   227,   -46,
     -46,   -46,   183,   -48,   -48,   -48,   -48,     0,   149,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   149,   -46,   -46,
     148,   -48,    79,   -25,   -25,   -25,   -25,   -25,   -25,   -79,
     -25,   149,   164,     0,     0,   -79,     0,   -25,   -25,   -25,
     -25,   -25,   -25,   149,   -25,   -25,   -25,   -25,     0,     0,
     -25,     0,   184,   -25,   -25,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,     0,     0,     0,   231,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,     0,   -73,   -73,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   150,   184,   -53,   -53,
     184,     0,   279,   279,   279,   279,   279,   279,   279,   279,
     279,     0,   184,     0,     0,   149,   149,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   150,     0,   149,     0,
       0,   253,     0,   165,   165,   165,   165,   165,   165,   165,
     165,   165,     0,   185,   -27,   -27,   -27,   -27,   -27,   -27,
       0,   -27,     0,     0,   149,     0,     0,   279,   -27,   -27,
     -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,   185,
       0,   -27,     0,     0,   -27,   -27,     0,   150,     0,     0,
       0,   184,   -48,   -48,   -48,   -48,   184,    84,   -47,   -47,
     -47,     0,   150,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   150,   -48,   -48,   149,   -47,     0,   -28,   -28,   -28,
     -28,   -28,   -28,   -80,   -28,   150,   165,     0,     0,   -80,
       0,   -28,   -28,   -28,   -28,   -28,   -28,   150,   -28,   -28,
     -28,   -28,     0,     0,   -28,     0,   185,   -28,   -28,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,     0,   -69,
     222,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     151,   185,   -79,   -79,   185,     0,   280,   280,   280,   280,
     280,   280,   280,   280,   280,     0,   185,     0,     0,   150,
     150,     0,     0,     0,     0,     0,     0,     0,     0,   151,
     151,     0,   150,     0,     0,   254,     0,   166,   166,   166,
     166,   166,   166,   166,   166,   166,     0,   186,   -29,   -29,
     -29,   -29,   -29,   -29,     0,   -29,     0,     0,   150,     0,
       0,   280,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,
     -29,   -29,   -29,   186,     0,   -29,     0,     0,   -29,   -29,
       0,   151,     0,     0,     0,   185,   227,   -47,   -47,   -47,
     185,   -49,   -49,   -49,   -49,     0,   151,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   151,   -47,   -47,   150,   -49,
       0,   -33,   -33,   -33,   -33,   -33,   -33,   -78,   -33,   151,
     166,     0,     0,   -78,     0,   -33,   -33,   -33,   -33,   -33,
     -33,   151,   -33,   -33,   -33,   -33,     0,     0,   -33,     0,
     186,   -33,   -33,   213,   -50,   -50,   -50,   -50,   214,   215,
       0,     0,     0,     0,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,     0,     0,   -50,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   153,   186,   -80,   -80,   186,     0,
     281,   281,   281,   281,   281,   281,   281,   281,   281,     0,
     186,     0,     0,   151,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   153,     0,   151,     0,     0,   255,
       0,   168,   168,   168,   168,   168,   168,   168,   168,   168,
       0,   188,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,
       0,     0,   151,     0,     0,   281,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,   -36,   -36,   -36,   188,     0,   -36,
       0,     0,   -36,   -36,     0,   153,     0,     0,     0,   186,
     -49,   -49,   -49,   -49,   186,   -52,   -52,   -52,   -52,     0,
     153,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   153,
     -49,   -49,   151,   -52,     0,   -18,   -18,   -18,   -18,   -18,
     -18,   -81,   -18,   153,   168,     0,     0,   -81,     0,   -18,
     -18,   -18,   -18,   -18,   -18,   153,   -18,   -18,   -18,   -18,
       0,     0,   -18,     0,   188,   -18,   -18,   -52,   -52,   -52,
     -52,     0,     0,     0,     0,     0,     0,     0,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,     0,   -52,   -52,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   154,   188,
     -78,   -78,   188,     0,   283,   283,   283,   283,   283,   283,
     283,   283,   283,     0,   188,     0,     0,   153,   153,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   154,     0,
     153,     0,     0,   257,     0,   169,   169,   169,   169,   169,
     169,   169,   169,   169,     0,   189,   -31,   -31,   -31,   -31,
     -31,   -31,     0,   -31,     0,     0,   153,     0,     0,   283,
     -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,
     -31,   189,     0,   -31,     0,     0,   -31,   -31,     0,   154,
       0,     0,     0,   188,   -51,   -51,   -51,   -51,   188,   -51,
     -51,   -51,   -51,     0,   154,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   154,   -51,   -51,   153,   -51,     0,   -32,
     -32,   -32,   -32,   -32,   -32,   -55,   -32,   154,   169,     0,
       0,    89,     0,   -32,   -32,   -32,   -32,   -32,   -32,   154,
     -32,   -32,   -32,   -32,     0,     0,   -32,     0,   189,   -32,
     -32,    88,   -53,   -53,   -53,   -53,   -53,   -53,   -53,     0,
       0,     0,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
       0,   -53,     0,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   145,   189,   -81,   -81,   189,     0,   284,   284,
     284,   284,   284,   284,   284,   284,   284,     0,   189,     0,
       0,   154,   154,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   145,   145,     0,   154,     0,     0,   258,   -44,   -44,
      83,     0,   104,   -55,   106,   107,     0,   147,     0,   180,
       0,   -60,   -60,   -60,   -60,   -44,     0,     0,   -60,     0,
     154,     0,     0,   284,     0,   -60,   -60,   -60,   -60,   212,
     -47,   -47,   -47,     0,     0,   180,   147,   147,   -60,   -49,
     -49,   -49,   -49,   145,   -45,   -45,    83,   189,   105,   -47,
       0,     0,   189,     0,   182,     0,     0,     0,   145,   -49,
       0,   -45,    31,    32,    33,   133,    34,    35,     0,    36,
     154,   -52,   -52,   -52,   -52,     0,    37,    38,    39,    40,
     182,   145,     0,    41,     0,    42,    43,     0,   147,    44,
       0,   -52,   134,   145,   -34,   -34,   -34,   -34,   -34,   -34,
       0,   -34,     0,   147,     0,     0,     0,     0,   -34,   -34,
     -34,   -34,   -34,   -34,     0,   -34,   325,   -34,   -34,     0,
       0,   -34,     0,     0,   -34,   -34,   147,   145,   145,   145,
     261,     0,   263,   264,   146,   145,     0,   180,   147,     0,
     180,     0,   180,   180,   180,   287,     0,   289,   290,     0,
     180,     0,   180,     0,     0,   145,   145,     0,     0,   -51,
     -51,   -51,   -51,   146,   146,     0,     0,     0,   145,     0,
       0,     0,   147,   147,   147,   147,   262,   147,   147,   -51,
     147,   181,   182,     0,     0,   182,     0,   182,   182,   182,
     182,   288,   182,   182,   145,   182,     0,   182,     0,     0,
     147,   147,   144,   -45,   -45,   226,     0,   181,     0,     0,
       0,     0,     0,   147,     0,   146,     0,     0,     0,     0,
       0,   180,   -45,   -45,     0,     0,   180,     0,     0,     0,
     146,   144,   144,     0,     0,     0,     0,     0,     0,   147,
       0,   103,     0,     0,   145,   -62,   -62,   -62,   -62,   179,
       0,     0,   -62,   146,     0,     0,     0,     0,     0,   -62,
     -62,   -62,   -62,     0,     0,   146,   182,     0,     0,     0,
       0,   182,   -62,     0,     0,   179,     0,     0,     0,    31,
      32,    33,   133,   144,     0,     0,    36,     0,     0,   147,
       0,     0,     0,    37,    38,    39,    40,     0,   144,   146,
     146,   146,   146,     0,   146,   146,    44,   146,   143,   181,
       0,     0,   181,     0,   181,   181,   181,   181,     0,   181,
     181,   144,   181,     0,   181,     0,     0,   146,   146,     0,
       0,     0,     0,   144,     0,     0,     0,   143,   143,     0,
     146,     0,     0,     0,     0,     0,   102,   135,   136,   137,
     138,     0,     0,     0,    36,   178,     0,     0,     0,     0,
       0,    37,    38,    39,   139,     0,   146,   144,   144,   260,
       0,     0,   142,     0,   140,   144,     0,   179,     0,     0,
     179,   178,   179,   179,   286,     0,     0,     0,     0,   143,
     179,     0,   179,   181,     0,   144,   144,     0,   181,     0,
       0,   142,   142,     0,   143,     0,     0,     0,   144,   100,
       0,     0,     0,     0,     0,     0,   146,     0,     0,   177,
       0,   158,   159,   160,   161,     0,     0,   143,    36,     0,
       0,     0,     0,     0,   144,    37,    38,    39,   162,   143,
     141,     0,     0,     0,     0,   177,     0,     0,   163,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   179,     0,     0,     0,     0,   179,     0,   142,   141,
     141,     0,     0,   143,   259,     0,     0,     0,     0,     0,
       0,   143,     0,   178,   144,   109,   178,   176,   178,   285,
       0,   142,   170,   171,   172,   173,   178,     0,   178,    36,
       0,   143,   143,   142,     0,     0,    37,    38,    39,   174,
       0,     0,     0,   176,   143,   245,   246,   247,   248,   175,
       0,   141,    36,     0,     0,     0,     0,     0,     0,    37,
      38,    39,   249,     0,     0,     0,   141,   251,     0,     0,
     143,     0,   250,     0,     0,   142,     0,   177,     0,     0,
     177,     0,   277,     0,     0,     0,     0,     0,     0,   141,
     177,     0,   177,     0,     0,   142,   142,   178,     0,     0,
       0,   141,   178,     0,     0,     0,     0,     0,   142,   -35,
     -35,   -35,   -35,   -35,   -35,     0,   -35,     0,     0,     0,
     143,     0,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
     -35,   -35,   -35,   -35,   142,     0,   -35,     0,     0,   -35,
     -35,     0,     0,   266,     0,   176,     0,     0,   176,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,   292,     0,
     176,   177,     0,   141,   141,     0,   177,     0,     0,   -69,
      91,   271,   272,   273,   274,   -69,   141,     0,    36,     0,
       0,     0,     0,     0,   142,    37,    38,    39,   275,   -37,
     -37,   -37,   -37,   -37,   -37,     0,   -37,     0,   276,     0,
       0,     0,   141,   -37,   -37,   -37,   -37,   -37,   -37,     0,
     -37,   -37,   -37,   -37,     0,     0,   -37,     0,     0,   -37,
     -37,     0,     0,   -17,   -17,   -17,   -17,   -17,   -17,   176,
     -17,     0,     0,     0,   176,     0,     0,   -17,   -17,   -17,
     -17,   -17,   -17,     0,   -17,     0,   -17,   -17,     0,     0,
     -17,     0,   141,   -17,   -17,    31,    32,    33,   133,    34,
      35,     0,    36,     0,     0,     0,     0,     0,     0,    37,
      38,    39,    40,     1,     2,     0,    41,     0,    42,    43,
       0,     0,    44,     0,     0,   134,   -20,   -23,   -23,   -23,
     -23,   -23,   -23,     0,   -23,     0,     0,     0,     0,     0,
       0,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,     0,
     -23,   -23,     0,     0,   -23,     0,     0,   -23,   -23,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,     0,     0,     0,
       0,     0,     0,   -26,   -26,   -26,   -26,   -26,   -26,     0,
     -26,     0,   -26,   -26,     0,     0,   -26,     0,     0,   -26,
     -26,    31,    32,    33,   133,    34,    35,     0,    36,     0,
       0,     0,     0,     0,     0,    37,    38,    39,    40,     1,
       2,     0,    41,     0,    42,    43,     0,     0,    44,     0,
       0,   134,   -19,   -22,   -22,   -22,   -22,   -22,   -22,     0,
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
       0,     0,   -18,     0,     0,   -18,   -18,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,     0,     0,     0,     0,     0,   234,   -69,
     -69,     0,     0,   -69,     0,   -73,   -73,     0,     0,     0,
       0,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,
       0,     0,     0,   -73,   -73,     0,     0,     0,   -73,     0,
       0,   219,   -69,     0,     0,     0,   -69,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,     0,     0,     0,     0,     0,     0,   -79,
     -79,     0,     0,   -79,     0,     0,     0,   -80,   -80,     0,
       0,   -80,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,     0,     0,
       0,     0,     0,     0,   -78,   -78,     0,     0,   -78,     0,
       0,     0,   -81,   -81,     0,     0,   -81,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,     0,     0,     0,     0,     0,     0,   -55,
     -55,     0,     0,   232,     0,     0,     0,   -57,   -57,     0,
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
       0,     0,   -64,   -64,     0,     0,   -64,   -57,   -57,   -57,
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
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,     0,     0,
       0,     0,   -64,     0,     0,     0,     0,     0,   -64,     0,
       0,     0,   -79,     0,     0,     0,   -79,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,     0,     0,     0,     0,     0,     0,   -80,
       0,     0,     0,   -80,     0,     0,     0,   -78,     0,     0,
       0,   -78,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,     0,     0,     0,   -81,     0,     0,     0,   -81,     0,
       0,     0,   -55,     0,     0,     0,   217,   -57,   -57,   -57,
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
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
       0,     0,     0,     0,   -64,     0,     0,     0,   -64,     0,
       0,   -73,   -73,   -73,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,     0,     0,     0,   308,   -69,   -69,     0,     0,
       0,     0,     0,     0,   -55,   -55,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,     0,     0,     0,     0,     0,     0,   -57,   -57,
       0,     0,     0,     0,     0,     0,   -63,   -63,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,     0,     0,     0,     0,     0,     0,
     -70,   -70,     0,     0,     0,     0,     0,     0,   -71,   -71,
     231,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,     0,
       0,     0,   -54,   -54,     0,     0,     0,     0,     0,     0,
     -56,   -56,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,
       0,     0,     0,     0,   -58,   -58,     0,     0,     0,     0,
       0,     0,   -72,   -72,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
       0,     0,     0,     0,     0,     0,   -64,   -64,     0,     0,
       0,     0,     0,   -73,   -73,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,   216,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,     0,     0,     0,     0,     0,   303,   -69,     0,     0,
       0,     0,     0,     0,     0,   -53,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,     0,     0,     0,     0,     0,     0,   -79,     0,
       0,     0,     0,     0,     0,     0,   -80,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,     0,     0,     0,     0,     0,     0,   -78,
       0,     0,     0,     0,     0,     0,     0,   -81,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,     0,     0,     0,     0,     0,     0,
     -55,     0,     0,     0,     0,     0,     0,     0,   -57,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,     0,
       0,   -63,     0,     0,     0,     0,     0,     0,     0,   -70,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   216,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,     0,     0,     0,     0,
       0,     0,   -71,     0,     0,     0,     0,     0,     0,     0,
     -54,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,     0,
       0,     0,     0,   -56,     0,     0,     0,     0,     0,     0,
       0,   -58,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,
       0,     0,     0,     0,   -72,     0,     0,     0,     0,     0,
       0,     0,   -64,    88,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,     0,
       0,     0,     0,   -54,     0,     0,     0,     0,     0,     0,
       0,   -56,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,
       0,     0,   -79,     0,     0,     0,     0,     0,     0,     0,
     -80,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,     0,     0,     0,
       0,   -78,     0,     0,     0,     0,     0,     0,     0,   -81,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,     0,     0,     0,     0,
     -57,     0,     0,     0,     0,     0,     0,     0,   -63,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,     0,     0,     0,     0,   -70,
       0,     0,     0,     0,     0,     0,     0,   -71,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,     0,     0,     0,     0,   -58,    85,
     -50,   -50,   -50,   -50,    86,    87,   -72,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,     0,   -50,     0,
       0,     0,     0,     0,     0,     0,     0,   -64
};

static const yytype_int16 yycheck[] =
{
       7,    26,   219,     6,   116,   222,   134,     3,     4,     5,
       6,   207,    13,   125,    10,    22,     6,   234,    29,    30,
      23,    17,    18,    19,    20,     6,    29,    29,     6,     0,
      31,   115,     3,    23,    30,    31,    13,    44,     6,    29,
     124,   115,   115,   115,   128,   241,    17,    31,    29,     6,
     115,    29,   115,    24,    31,    32,     3,     4,     5,     6,
      33,    29,    69,    10,     6,    72,    73,    74,   196,    33,
      17,    18,    19,    20,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    30,    91,     0,   303,    29,    13,    30,
     115,   308,    12,    13,    14,    21,    22,    30,     3,     4,
       5,     6,     7,     8,    29,    10,    21,    22,     0,     6,
     117,    31,    17,    18,    19,    20,    43,    44,   125,    24,
      13,    26,    27,    29,    30,    30,    23,   239,    33,    21,
      22,    12,    13,   140,    21,    22,    29,     0,     3,     4,
       5,     6,   149,    12,    13,    10,    73,    74,    75,    13,
      31,    32,    17,    18,    19,    20,   163,   164,    21,    22,
       0,    13,    31,    32,    91,    30,    31,    31,   175,     3,
       4,     5,     6,    12,    13,    14,    10,   184,     0,    31,
      32,    21,    22,    17,    18,    19,    20,    30,   115,   116,
     117,     0,    31,    32,     3,    29,    30,    30,   125,    21,
      22,   313,   209,   210,   211,   212,   213,   214,   215,   216,
     217,     0,   219,   140,   326,   222,    34,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    29,   234,   312,   236,
     237,   238,    21,    22,    31,    32,   163,     0,   312,   312,
     312,   325,     6,   250,     6,   329,   253,   312,   175,   312,
      29,   325,   325,   325,    31,   329,   329,   329,    21,    22,
     325,    23,   325,     0,   329,    31,   329,     6,   195,   276,
      31,    32,   279,    31,    32,    29,     9,    10,    11,    12,
      13,    14,    15,    16,    21,    22,    31,   312,    44,    12,
      13,    14,   219,     0,    29,   222,   303,    30,    31,    32,
     325,   308,    35,    31,   329,    31,    32,   234,    31,    65,
     237,   238,   239,    29,    21,    22,    31,    73,    74,   326,
      31,    32,    31,   250,    29,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    29,    91,     3,     4,     5,     6,
       7,     8,    29,    10,    29,    11,    12,    13,    14,   276,
      17,    18,    19,    20,    21,    22,    31,    24,    25,    26,
      27,   117,    30,    30,    29,    31,    33,    34,    30,   125,
      11,    12,    13,    14,    31,    32,   303,    11,    12,    13,
      14,   308,    12,    13,   140,   312,   313,    30,    29,     3,
       4,     5,     6,   149,    31,    32,    10,    31,   325,   326,
      29,    31,   329,    17,    18,    19,    20,   163,   164,    10,
      11,    12,    13,    14,    15,    16,    30,    30,     6,   175,
       3,     4,     5,     6,     7,     8,    31,    10,   184,    31,
      31,    32,    12,    13,    17,    18,    19,    20,    21,    22,
      31,    24,    25,    26,    27,    12,    13,    30,    29,    29,
      33,    34,    31,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    44,   219,    31,    34,   222,    31,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    31,   234,    12,
      13,   237,   238,    21,    22,    21,    22,    31,    32,    31,
      31,    73,    74,    31,   250,    31,    29,   253,    29,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    31,    91,
       3,     4,     5,     6,     7,     8,    31,    10,    34,    31,
     276,    31,    29,   279,    17,    18,    19,    20,    21,    22,
      29,    24,    25,    26,    27,   117,    31,    30,    29,    31,
      33,    34,    31,   125,     3,    92,    24,   303,    11,    12,
      13,    14,   308,    11,    12,    13,    14,    -1,   140,     9,
      10,    11,    12,    13,    14,    15,    16,   149,    31,    32,
     326,    29,    48,     3,     4,     5,     6,     7,     8,    29,
      10,   163,   164,    -1,    -1,    35,    -1,    17,    18,    19,
      20,    21,    22,   175,    24,    25,    26,    27,    -1,    -1,
      30,    -1,   184,    33,    34,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    29,    30,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    44,   219,    31,    32,
     222,    -1,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,    -1,    -1,   237,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,   250,    -1,
      -1,   253,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    91,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,   276,    -1,    -1,   279,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,   117,
      -1,    30,    -1,    -1,    33,    34,    -1,   125,    -1,    -1,
      -1,   303,    11,    12,    13,    14,   308,    11,    12,    13,
      14,    -1,   140,     9,    10,    11,    12,    13,    14,    15,
      16,   149,    31,    32,   326,    29,    -1,     3,     4,     5,
       6,     7,     8,    29,    10,   163,   164,    -1,    -1,    35,
      -1,    17,    18,    19,    20,    21,    22,   175,    24,    25,
      26,    27,    -1,    -1,    30,    -1,   184,    33,    34,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    29,
      30,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      44,   219,    31,    32,   222,    -1,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,   250,    -1,    -1,   253,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    91,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,   276,    -1,
      -1,   279,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,   117,    -1,    30,    -1,    -1,    33,    34,
      -1,   125,    -1,    -1,    -1,   303,    11,    12,    13,    14,
     308,    11,    12,    13,    14,    -1,   140,     9,    10,    11,
      12,    13,    14,    15,    16,   149,    31,    32,   326,    29,
      -1,     3,     4,     5,     6,     7,     8,    29,    10,   163,
     164,    -1,    -1,    35,    -1,    17,    18,    19,    20,    21,
      22,   175,    24,    25,    26,    27,    -1,    -1,    30,    -1,
     184,    33,    34,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    31,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    44,   219,    31,    32,   222,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,   250,    -1,    -1,   253,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    91,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,   276,    -1,    -1,   279,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,   117,    -1,    30,
      -1,    -1,    33,    34,    -1,   125,    -1,    -1,    -1,   303,
      11,    12,    13,    14,   308,    11,    12,    13,    14,    -1,
     140,     9,    10,    11,    12,    13,    14,    15,    16,   149,
      31,    32,   326,    29,    -1,     3,     4,     5,     6,     7,
       8,    29,    10,   163,   164,    -1,    -1,    35,    -1,    17,
      18,    19,    20,    21,    22,   175,    24,    25,    26,    27,
      -1,    -1,    30,    -1,   184,    33,    34,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    31,    32,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    44,   219,
      31,    32,   222,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
     250,    -1,    -1,   253,    -1,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    91,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,   276,    -1,    -1,   279,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,   117,    -1,    30,    -1,    -1,    33,    34,    -1,   125,
      -1,    -1,    -1,   303,    11,    12,    13,    14,   308,    11,
      12,    13,    14,    -1,   140,     9,    10,    11,    12,    13,
      14,    15,    16,   149,    31,    32,   326,    29,    -1,     3,
       4,     5,     6,     7,     8,    29,    10,   163,   164,    -1,
      -1,    35,    -1,    17,    18,    19,    20,    21,    22,   175,
      24,    25,    26,    27,    -1,    -1,    30,    -1,   184,    33,
      34,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    29,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    44,   219,    31,    32,   222,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,   234,    -1,
      -1,   237,   238,     9,    10,    11,    12,    13,    14,    15,
      16,    73,    74,    -1,   250,    -1,    -1,   253,    12,    13,
      14,    -1,    84,    29,    86,    87,    -1,    44,    -1,    91,
      -1,     3,     4,     5,     6,    29,    -1,    -1,    10,    -1,
     276,    -1,    -1,   279,    -1,    17,    18,    19,    20,    11,
      12,    13,    14,    -1,    -1,   117,    73,    74,    30,    11,
      12,    13,    14,   125,    12,    13,    14,   303,    85,    31,
      -1,    -1,   308,    -1,    91,    -1,    -1,    -1,   140,    31,
      -1,    29,     3,     4,     5,     6,     7,     8,    -1,    10,
     326,    11,    12,    13,    14,    -1,    17,    18,    19,    20,
     117,   163,    -1,    24,    -1,    26,    27,    -1,   125,    30,
      -1,    31,    33,   175,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,   140,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,   163,   209,   210,   211,
     212,    -1,   214,   215,    44,   217,    -1,   219,   175,    -1,
     222,    -1,   224,   225,   226,   227,    -1,   229,   230,    -1,
     232,    -1,   234,    -1,    -1,   237,   238,    -1,    -1,    11,
      12,    13,    14,    73,    74,    -1,    -1,    -1,   250,    -1,
      -1,    -1,   209,   210,   211,   212,   213,   214,   215,    31,
     217,    91,   219,    -1,    -1,   222,    -1,   224,   225,   226,
     227,   228,   229,   230,   276,   232,    -1,   234,    -1,    -1,
     237,   238,    44,    12,    13,    14,    -1,   117,    -1,    -1,
      -1,    -1,    -1,   250,    -1,   125,    -1,    -1,    -1,    -1,
      -1,   303,    31,    32,    -1,    -1,   308,    -1,    -1,    -1,
     140,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,   276,
      -1,    83,    -1,    -1,   326,     3,     4,     5,     6,    91,
      -1,    -1,    10,   163,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,    -1,   175,   303,    -1,    -1,    -1,
      -1,   308,    30,    -1,    -1,   117,    -1,    -1,    -1,     3,
       4,     5,     6,   125,    -1,    -1,    10,    -1,    -1,   326,
      -1,    -1,    -1,    17,    18,    19,    20,    -1,   140,   209,
     210,   211,   212,    -1,   214,   215,    30,   217,    44,   219,
      -1,    -1,   222,    -1,   224,   225,   226,   227,    -1,   229,
     230,   163,   232,    -1,   234,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,   175,    -1,    -1,    -1,    73,    74,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    82,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    91,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,   276,   209,   210,   211,
      -1,    -1,    44,    -1,    30,   217,    -1,   219,    -1,    -1,
     222,   117,   224,   225,   226,    -1,    -1,    -1,    -1,   125,
     232,    -1,   234,   303,    -1,   237,   238,    -1,   308,    -1,
      -1,    73,    74,    -1,   140,    -1,    -1,    -1,   250,    81,
      -1,    -1,    -1,    -1,    -1,    -1,   326,    -1,    -1,    91,
      -1,     3,     4,     5,     6,    -1,    -1,   163,    10,    -1,
      -1,    -1,    -1,    -1,   276,    17,    18,    19,    20,   175,
      44,    -1,    -1,    -1,    -1,   117,    -1,    -1,    30,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   303,    -1,    -1,    -1,    -1,   308,    -1,   140,    73,
      74,    -1,    -1,   209,   210,    -1,    -1,    -1,    -1,    -1,
      -1,   217,    -1,   219,   326,    89,   222,    91,   224,   225,
      -1,   163,     3,     4,     5,     6,   232,    -1,   234,    10,
      -1,   237,   238,   175,    -1,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,   117,   250,     3,     4,     5,     6,    30,
      -1,   125,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,   140,   209,    -1,    -1,
     276,    -1,    30,    -1,    -1,   217,    -1,   219,    -1,    -1,
     222,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     232,    -1,   234,    -1,    -1,   237,   238,   303,    -1,    -1,
      -1,   175,   308,    -1,    -1,    -1,    -1,    -1,   250,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
     326,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,   276,    -1,    30,    -1,    -1,    33,
      34,    -1,    -1,   217,    -1,   219,    -1,    -1,   222,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,   232,    -1,
     234,   303,    -1,   237,   238,    -1,   308,    -1,    -1,    29,
      30,     3,     4,     5,     6,    35,   250,    -1,    10,    -1,
      -1,    -1,    -1,    -1,   326,    17,    18,    19,    20,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    30,    -1,
      -1,    -1,   276,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    -1,     3,     4,     5,     6,     7,     8,   303,
      10,    -1,    -1,    -1,   308,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,   326,    33,    34,     3,     4,     5,     6,     7,
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
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    35,    -1,    29,    30,    -1,    -1,    -1,
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
      -1,    -1,    31,    32,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    30,    31,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
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
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,     9,    10,    11,    12,    13,    14,    15,    16,
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
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,    10,
      11,    12,    13,    14,    15,    16,    29,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    22,    37,    38,    39,    41,    74,    23,    23,
       0,    38,     6,    29,    73,    30,    40,    42,    29,    44,
      45,    46,    74,    31,    32,    73,    43,    46,    33,    47,
      48,     3,     4,     5,     7,     8,    10,    17,    18,    19,
      20,    24,    26,    27,    30,    39,    47,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    72,    73,    74,
      75,    76,    30,    30,    30,    30,    58,    58,    34,    51,
      29,    13,    12,    14,    11,    10,    15,    16,     9,    35,
      67,    30,    73,    73,    58,    58,    58,    59,    29,    31,
      61,    67,    62,    63,    64,    66,    64,    64,    67,    60,
      58,    70,    71,    31,    31,    31,    29,    32,    31,    29,
      29,    52,    59,    58,    25,    29,    52,    59,    31,    52,
      21,    22,     6,     6,    33,     3,     4,     5,     6,    20,
      30,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    72,    73,    75,    76,     6,    29,     6,     3,     4,
       5,     6,    20,    30,    68,    69,    72,    73,    75,    76,
       3,     4,     5,     6,    20,    30,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    72,    73,    75,    76,
      40,     7,     8,    24,    26,    27,    33,    47,    53,    54,
      55,    56,    57,    58,    58,    23,    23,    48,    58,    13,
      12,    14,    11,    10,    15,    16,     9,    35,    67,    30,
      58,    67,    30,    58,    13,    12,    14,    11,    10,    15,
      16,     9,    35,    67,    30,    29,    30,    30,    30,    30,
      58,    48,    29,    49,    31,     3,     4,     5,     6,    20,
      30,    61,    67,    68,    69,    72,    73,    75,    76,    62,
      63,    64,    66,    64,    64,    67,    60,    71,    31,    71,
      31,     3,     4,     5,     6,    20,    30,    61,    67,    68,
      69,    72,    73,    75,    76,    62,    63,    64,    66,    64,
      64,    67,    60,    71,    73,    58,    58,    59,    29,    49,
      34,    58,    67,    30,    31,    31,    58,    67,    30,    31,
      31,    31,    31,    29,    34,    31,    71,    31,    71,    29,
      29,    52,    59,    31,    31,    25,    29,    52,    59,    31,
      52
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
      72,    72,    72,    73,    74,    74,    74,    74,    75,    75,
      75,    76
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
#line 69 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2122 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 69 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2128 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 69 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2134 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2140 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2146 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2152 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2158 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2164 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2170 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2176 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2182 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2188 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2194 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2200 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2206 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2212 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2218 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2224 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2230 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2236 "src/bison/grammar.c"
        break;

    case YYSYMBOL_40_1: /* @1  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2242 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2248 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_2: /* @2  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2254 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2260 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2266 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2272 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2278 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2284 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2290 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2296 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2302 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2308 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2314 "src/bison/grammar.c"
        break;

    case YYSYMBOL_59_expression_opt: /* expression.opt  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2320 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2326 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2332 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2338 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2344 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2350 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2356 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2362 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2368 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2374 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2380 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2386 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2392 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 68 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2398 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2404 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 71 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2410 "src/bison/grammar.c"
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
#line 2681 "src/bison/grammar.c"
    break;

  case 3: /* prog: external_declaration  */
#line 75 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 2687 "src/bison/grammar.c"
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
#line 2709 "src/bison/grammar.c"
    break;

  case 7: /* var_declaration: type id @1 ';'  */
#line 98 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 2717 "src/bison/grammar.c"
    break;

  case 8: /* var_declaration: type ';'  */
#line 101 "src/bison/grammar.y"
               {
        yyerror(NULL);
        CIPL_PERROR_CURSOR("useless '%s' in empty declaration\n", error_cursor, (yyvsp[-1].pchar));
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
    }
#line 2728 "src/bison/grammar.c"
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
#line 2759 "src/bison/grammar.c"
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
#line 2774 "src/bison/grammar.c"
    break;

  case 11: /* func_declaration: type id '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 143 "src/bison/grammar.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
    }
#line 2783 "src/bison/grammar.c"
    break;

  case 12: /* param_list.opt: %empty  */
#line 149 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 2789 "src/bison/grammar.c"
    break;

  case 14: /* params_list: params_list ',' param_decl  */
#line 153 "src/bison/grammar.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2795 "src/bison/grammar.c"
    break;

  case 15: /* params_list: param_decl  */
#line 154 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2801 "src/bison/grammar.c"
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
#line 2813 "src/bison/grammar.c"
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
#line 2829 "src/bison/grammar.c"
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
#line 2842 "src/bison/grammar.c"
    break;

  case 19: /* block_item_list.opt: block_item_list  */
#line 186 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 2848 "src/bison/grammar.c"
    break;

  case 20: /* block_item_list.opt: %empty  */
#line 187 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 2854 "src/bison/grammar.c"
    break;

  case 21: /* block_item_list: block_item_list block_item  */
#line 190 "src/bison/grammar.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 2860 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list: block_item  */
#line 191 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 2866 "src/bison/grammar.c"
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
#line 2878 "src/bison/grammar.c"
    break;

  case 32: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 213 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(sym)), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 2888 "src/bison/grammar.c"
    break;

  case 33: /* expr_stmt: expression ';'  */
#line 220 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2894 "src/bison/grammar.c"
    break;

  case 34: /* cond_stmt: IF '(' expression ')' statement  */
#line 223 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 2902 "src/bison/grammar.c"
    break;

  case 35: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 226 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2910 "src/bison/grammar.c"
    break;

  case 36: /* jmp_stmt: RETURN expression ';'  */
#line 231 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 2916 "src/bison/grammar.c"
    break;

  case 37: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 234 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 2924 "src/bison/grammar.c"
    break;

  case 39: /* expression: unary_expr '=' logical_or_expr  */
#line 240 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2930 "src/bison/grammar.c"
    break;

  case 40: /* expression.opt: %empty  */
#line 243 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 2936 "src/bison/grammar.c"
    break;

  case 43: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 248 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2945 "src/bison/grammar.c"
    break;

  case 45: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 255 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2954 "src/bison/grammar.c"
    break;

  case 47: /* eq_expr: eq_expr EQ rel_expr  */
#line 262 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2963 "src/bison/grammar.c"
    break;

  case 49: /* rel_expr: rel_expr REL list_expr  */
#line 269 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2972 "src/bison/grammar.c"
    break;

  case 51: /* list_expr: add_expr DL_DG list_expr  */
#line 276 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2981 "src/bison/grammar.c"
    break;

  case 52: /* list_expr: add_expr COLON list_expr  */
#line 280 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2990 "src/bison/grammar.c"
    break;

  case 54: /* add_expr: add_expr ADD mult_expr  */
#line 287 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 2999 "src/bison/grammar.c"
    break;

  case 56: /* mult_expr: mult_expr MULT unary_expr  */
#line 294 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3008 "src/bison/grammar.c"
    break;

  case 58: /* unary_expr: unary_ops unary_expr  */
#line 301 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3017 "src/bison/grammar.c"
    break;

  case 64: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 314 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_funcall_init((yyvsp[-3].ast), ast_params_init((yyvsp[-1].list)));
    }
#line 3025 "src/bison/grammar.c"
    break;

  case 65: /* arg_expr_list: expression  */
#line 319 "src/bison/grammar.y"
                          { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3031 "src/bison/grammar.c"
    break;

  case 66: /* arg_expr_list: arg_expr_list ',' expression  */
#line 320 "src/bison/grammar.y"
                                   { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3037 "src/bison/grammar.c"
    break;

  case 68: /* arg_expr_list.opt: %empty  */
#line 324 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3043 "src/bison/grammar.c"
    break;

  case 69: /* primary_expr: id  */
#line 327 "src/bison/grammar.y"
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
#line 3060 "src/bison/grammar.c"
    break;

  case 72: /* primary_expr: '(' expression ')'  */
#line 341 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 3066 "src/bison/grammar.c"
    break;

  case 73: /* id: NAME  */
#line 344 "src/bison/grammar.y"
         { (yyval.ast) = ast_symref_init((yyvsp[0].sym)); }
#line 3072 "src/bison/grammar.c"
    break;

  case 76: /* type: INT LIST  */
#line 349 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3084 "src/bison/grammar.c"
    break;

  case 77: /* type: FLOAT LIST  */
#line 356 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3096 "src/bison/grammar.c"
    break;

  case 78: /* constant: NUMBER_REAL  */
#line 365 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 3102 "src/bison/grammar.c"
    break;

  case 79: /* constant: NUMBER_INT  */
#line 366 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3108 "src/bison/grammar.c"
    break;

  case 80: /* constant: NIL  */
#line 367 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3114 "src/bison/grammar.c"
    break;

  case 81: /* string_literal: STR_LITERAL  */
#line 370 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 3123 "src/bison/grammar.c"
    break;


#line 3127 "src/bison/grammar.c"

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

#line 376 "src/bison/grammar.y"


void yyerror(const char *s, ...) {
    /* just save where the error points to */
    error_cursor = cursor;
    if (s) CIPL_PERROR_CURSOR("%s\n", error_cursor, s);
    ++errors_count;
}
