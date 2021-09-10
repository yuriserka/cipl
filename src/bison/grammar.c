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
    #include <stdbool.h>

    #include "data-structures/ast/ast.h"
    #include "data-structures/stack.h"
    #include "data-structures/context.h"
    #include "data-structures/symbol-table/symbol-table.h"
    #include "utils/io.h"
    #include "core/globals.h"

    AST *root;
    StackNode *scopes;
    ListNode *contexts;
    Cursor error_cursor;
    Context *current_context;
    Context *previous_context;
    StackNode *parent_stacknode_ref;
    char *last_line_ref;
    bool p_ctx_name = true, is_fn_blck = false;

    void free_scope_cb(StackNode *node) { scope_free(node->data); }

    StackNode *context_get_current_stacknode_ref() {
        LIST_FOR_EACH_REVERSE(current_context->scopes, {
            if (((Scope *)__IT__->data)->index == current_context->current_scope) {
                return __IT__;
            }
        });
        return NULL;
    }

    #define p_error_ctx_info {                                                       \
        if (p_ctx_name) {                                                            \
            if (current_context->current_scope) {                                    \
                CIPL_PRINTF(WHT "%s:" RESET " In function " BBLU "'%s'" RESET ":\n", \
                            filename, current_context->name);                        \
            } else {                                                                 \
                CIPL_PRINTF(WHT "%s:" RESET " At top level:\n", filename);           \
            }                                                                        \
            p_ctx_name = false;                                                      \
        }                                                                            \
    }

    #define show_error_range(__R__, __FMT__, ...) {                             \
        p_error_ctx_info;                                                       \
        Cursor beg = (Cursor){.line=__R__.first_line, .col=__R__.first_column}; \
        Cursor end = (Cursor){.line=__R__.last_line, .col=__R__.last_column};   \
        yyerror(end.line, end.col, NULL);                                       \
        LineInfo *li = list_peek(&lines, beg.line - 1);                         \
        li = li ? li : curr_line_info;                                          \
        CIPL_PERROR_CURSOR_RANGE(                                               \
            __FMT__,                                                            \
            li->text,                                                           \
            beg,                                                                \
            end,                                                                \
            ##__VA_ARGS__                                                       \
        );                                                                      \
        yyerrok;                                                                \
    }

    #define show_error(__R__, __FMT__, ...) {                  \
        p_error_ctx_info;                                      \
        yyerror(__R__.last_line, __R__.last_column, NULL);     \
        LineInfo *li = list_peek(&lines, __R__.last_line - 1); \
        li = li ? li : curr_line_info;                         \
        CIPL_PERROR_CURSOR(                                    \
            __FMT__,                                           \
            li->text,                                          \
            error_cursor,                                      \
            ##__VA_ARGS__                                      \
        );                                                     \
        yyerrok;                                               \
    }

    #define cleanup_expr_err(__OP__, __AST__) \
        { free(__OP__); ast_free(__AST__); }


#line 153 "src/bison/grammar.c"

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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7154

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  468

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
       0,   129,   129,   130,   133,   134,   137,   138,   139,   146,
     146,   168,   175,   210,   175,   219,   220,   223,   224,   227,
     241,   241,   255,   256,   259,   260,   263,   264,   267,   268,
     269,   270,   271,   272,   275,   282,   287,   292,   299,   302,
     305,   308,   314,   323,   324,   331,   336,   337,   338,   345,
     346,   349,   350,   354,   359,   366,   367,   371,   376,   383,
     384,   388,   393,   400,   401,   405,   410,   417,   418,   422,
     426,   431,   436,   441,   448,   449,   453,   458,   465,   466,
     470,   475,   482,   483,   489,   490,   491,   492,   495,   496,
     516,   517,   520,   521,   524,   534,   535,   536,   537,   543,
     546,   547,   548,   555,   564,   565,   566,   569
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
  "arg_expr_list.opt", "primary_expr", "id", "type", "constant",
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

#define YYPACT_NINF (-304)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-108)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1398,   464,  1510,  1969,  2056,   481,   -19,   -14,   691,  2486,
    2776,  5002,  5299,    13,    14,    20,    25,   924,   972,  1604,
      79,  1660,  1802,  1837,  1872,  1944,  2089,  2171,  2231,  2450,
    2507,  2740,    17,   132,   276,   384,   335,   415,  2531,  6719,
    5307,  5020,  5334,  5342,   763,     9,  5369,  5377,  5038,  1182,
    1220,  1255,  1365,  1431,  1220,  1220,   112,  1487,    29,    33,
    1911,   350,  6727,    62,  6131,    73,  2846,  -304,  2881,  2912,
    2013,  2129,  2363,  2417,  2576,  2623,  2682,  2797,  4207,  5404,
     226,  2955,   -16,  6748,   108,  6756,  6777,   282,   738,   984,
     517,  1686,   388,  2555,   856,  1168,  1445,    94,   120,  6139,
     129,  6162,   133,   164,   169,  2986,  3017,  5412,  5439,  3048,
     188,  3082,  3116,  3150,    34,  6785,   526,  6806,   783,  6814,
    1590,  6835,  1640,  6843,  6864,  6872,  1694,  6893,  1771,  6901,
    6922,  6930,   141,    22,   165,   194,   134,   206,   220,   229,
     235,   257,   222,   222,   350,  3185,  3216,   271,  4228,  5447,
     216,  3251,  3282,  3313,  3344,  3375,    68,   102,   304,   272,
     319,   279,   340,   346,   328,   328,   615,   332,   352,   399,
    3406,  3437,   345,   328,   401,  1708,  3468,  3499,  5474,  5482,
    5509,   642,  5517,  4249,    46,    69,   228,   197,   409,   512,
    6170,  5544,  5056,  5552,  5579,  1277,  5587,  5614,   405,  6951,
    6959,  6980,  2200,  6988,  4270,  5038,  7009,  7017,  6697,  7038,
    7046,   347,  5074,  4291,  4312,  4333,  4354,  4375,  4312,  4312,
     353,   357,   364,   394,  4396,  1604,  3530,  3564,  3598,  3632,
    3666,  3700,   425,   746,   842,  1378,  2721,   127,  5122,  4417,
      16,    52,   264,   175,   189,  2153,   327,  5132,  5092,  5159,
    5167,   994,  5194,  5202,   426,  3734,  1604,   429,    28,   161,
     411,  2293,   383,  6193,   453,  4438,  4459,  4480,  4501,  4522,
    4543,  4564,  4585,  4606,  5622,   226,  6201,   454,  7067,   226,
    6224,  6232,  6255,  6100,  6263,  4627,  6286,  5074,  6294,  6317,
    6108,  6325,  6348,   477,  6356,  6379,   588,   580,  2660,   456,
    2276,   121,  2710,  1086,  1140,  1204,   193,  4648,  4669,   350,
    7075,   431,  2846,  3768,  5110,  4690,  4711,  4732,  4753,  4774,
    4711,  4711,  6387,   458,  4795,  4816,  4837,  4858,  4879,  4900,
    4921,  4942,  4963,  5229,   226,  2846,  3802,   501,   507,  5649,
    5657,  6410,   159,  6418,   596,  6441,  1321,  6449,  1366,  6472,
    6480,  6503,  1554,  6511,  1628,  6534,  6542,  6565,   192,   483,
    7096,  7104,   486,  6573,   488,  6596,   226,   503,   504,  6604,
     506,  6627,   535,   540,  3836,  3870,   537,  1027,  1542,  5716,
    1735,  5724,  4984,  5748,  5110,  5756,  5780,  5692,  5788,  5812,
     564,  5820,  5844,   902,   249,  2699,   270,  2652,    84,  2823,
     575,   629,   671,  5237,  5264,  5852,   118,  5876,   451,  5884,
     711,  5908,   806,  5916,  5940,  5948,  1081,  5972,  1197,  5980,
    6004,  6012,   221,   543,   545,  5684,  7125,  6635,  6658,   546,
     553,   554,   556,   567,   568,   568,   350,  3904,  6666,   569,
    6036,   226,  5272,   883,  6689,  3938,  3972,  4006,  4040,  1604,
     385,  1101,   573,  6044,  6068,   583,  2846,   589,   589,   615,
    6076,   590,  4074,  4108,   597,  1139,  4176,  4142
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -304,  -304,  -304,   609,    49,   484,  -304,  -304,  -304,  -304,
    -304,   468,     4,  -223,  -303,  -304,   527,     1,     3,     5,
       6,     7,    10,  1452,  -114,   587,   305,  2512,  2372,  2004,
    2283,  2080,  1721,   233,   515,  -304,  -267,   748,     0,    23,
    1030,  1263
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    20,    21,    22,   109,   137,    24,   150,   167,   160,
     161,   162,   226,    66,   110,   111,   112,   113,   227,   228,
     229,   230,   231,   133,   104,    33,    34,    35,    36,    37,
      38,    39,    40,   205,   206,   134,   135,   207,   208,   114,
     209,   210
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    26,   312,    27,    25,    28,    29,    30,   359,   376,
      31,    56,   362,    -9,   136,   198,    57,    44,   195,  -100,
    -101,    44,    26,    45,    27,    25,    28,    29,    30,   324,
     158,    31,   424,   335,  -100,  -102,    58,    59,    81,  -103,
     254,    44,  -100,  -101,    45,    82,    69,   -46,   -46,    23,
      60,   337,   172,   -90,   -90,    61,    98,   195,  -102,   265,
     195,    44,  -103,   255,   325,   -51,    44,   423,   -41,   -41,
      23,   -41,   -41,   -41,   -41,   -41,   -41,   -46,   -41,    67,
     251,   266,   -51,   -51,   -51,   -41,   -41,   -41,   -41,   -41,
     -41,   106,   -41,   164,   -41,   -41,   325,   -54,   -41,   429,
     -51,   -41,   -39,   -39,   108,   -39,   -39,   -39,   -39,   -39,
     -39,    44,   -39,    97,   147,   -54,   -54,    48,   211,   -39,
     -39,   -39,   -39,   -39,   -39,   138,   -39,   165,   -39,   -39,
     325,   -52,   -39,   266,   -54,   -39,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,    44,    70,   156,   157,   251,   -52,
     -52,   139,   -54,   461,    70,   -12,   -12,   -99,   -99,   -99,
     141,   -46,   -99,   169,   143,   -12,   195,  -101,   170,   171,
     -47,   266,   -52,   163,   455,    44,   177,   176,    27,    25,
      28,    29,    30,   195,   338,    31,   327,   -59,   -59,   -59,
     -52,   163,   195,   -50,   367,   373,   -92,   148,   144,   211,
     -63,   -63,   -63,   -63,   195,   265,   -59,   -59,   268,   -59,
     -59,   -59,   290,   290,   290,   290,   290,   290,   290,   290,
     -63,   -63,   145,   -47,    44,   149,   456,   233,   -59,   234,
     235,   236,   237,    41,   324,   151,     8,   258,   259,   195,
     -55,   -55,   267,     9,    10,    11,   238,   -15,   251,   152,
      41,   192,   -47,   -47,    41,   256,   239,   -93,   153,   -55,
     -66,   -66,   -66,   -66,   154,   290,   290,   290,   290,   290,
     290,   290,   290,   290,    41,   251,   -55,   -55,   326,   251,
     -66,   -66,   -58,   -58,   326,   195,   155,   290,    71,   -51,
     192,    48,    49,   192,    41,   -55,   -55,    54,    55,    41,
      -9,   -58,   -58,   -91,   -91,   -51,   368,   195,   195,    44,
     -16,   168,    44,   248,   387,   387,   387,   387,   387,   387,
     387,   387,   452,   185,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   166,   251,    44,   331,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,    41,   464,    73,   -59,   -59,   -59,
     -13,     1,   260,     2,     3,     4,     5,    92,   -74,   -74,
       8,    19,   185,   173,   -59,   185,   251,     9,    10,    11,
      12,   -18,   -18,   258,   259,   116,   175,    41,   -99,   -49,
      18,   248,   195,   306,   387,   241,   -41,   307,   -41,   -41,
     -41,   -41,   -41,   -41,   308,   -41,   -55,   -55,    72,   192,
      71,   -54,   -41,   -41,   -41,   -41,   -41,   -41,    41,   -41,
     457,   -41,   -41,   -55,   -50,   -41,   192,   -54,   -41,   -41,
     -63,   -63,   -63,   -63,   309,   192,   -63,   -63,   -63,   -63,
     -19,   -19,   -17,   -17,   -99,   -99,    44,   192,   450,   451,
     -63,   251,   -99,   -99,   -63,   287,   287,   287,   287,   287,
     287,   287,   287,   241,   313,   -99,    44,    41,   336,   195,
     375,   462,   463,   -56,   -56,   326,    44,   467,   -58,   -58,
     267,   185,   192,    48,    49,    50,    51,    52,    53,    54,
      55,   248,   -56,   -56,   340,   361,   212,   -58,   185,   404,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   287,   287,
     287,   287,   287,   287,   287,   287,   287,  -102,   248,   185,
     -99,   -99,   248,  -103,   425,    42,   -99,   426,   192,   428,
     287,   301,   269,   -67,   -67,   -67,   -67,   270,   271,   -58,
     -58,    72,    42,   193,   430,   431,    42,   433,    71,   -52,
     192,   192,    41,   -67,   185,    41,   -58,   384,   384,   384,
     384,   384,   384,   384,   384,   -52,    42,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   435,   248,    41,   436,
     342,   437,   193,   314,   442,   193,    42,   444,   185,   443,
     241,    42,   445,   446,   241,   447,   327,   -62,   -62,   -62,
     185,   -66,   -66,   -66,   -66,   249,   448,   212,   213,   248,
     454,   449,   459,   218,   219,   184,   -62,   -62,   -56,   -56,
     267,   -66,   185,   185,   460,   192,   261,   384,   178,   179,
     180,   181,   225,   398,   465,     8,    42,   -56,   466,   406,
      68,   257,     9,    10,    11,   182,   174,   241,   146,   241,
     -73,   -73,   -73,   -73,   184,   183,   -49,   184,     0,     0,
       0,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    42,
     -73,   -73,     0,   249,     0,   132,     0,   240,     0,    41,
       0,   241,   -99,   -99,   248,     0,     0,   -99,     0,     0,
       0,   193,   -72,   -72,   -72,   -72,     0,   185,     0,    41,
      42,     0,   192,     0,   -86,   -86,   -86,   -86,   193,    41,
       0,   -86,   -72,   -72,     0,     0,     0,   193,   -86,   -86,
     -86,   -86,     0,     0,     0,     0,     0,     0,     0,   193,
       0,   -86,   327,   -60,   -60,   -60,     0,   288,   288,   288,
     288,   288,   288,   288,   288,   240,     0,     0,     0,    42,
       0,     0,   -60,   -60,     0,     0,   241,     0,    43,   -66,
     -66,   -66,   -66,   184,   193,   314,   315,   316,   317,   318,
     319,   320,   321,   249,   185,    43,   194,   -66,     0,    43,
     184,     0,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     288,   288,   288,   288,   288,   288,   288,   288,   288,    43,
     249,   184,   -94,    80,   249,   -56,   -56,    72,   -94,     0,
     193,     0,   288,     0,     0,   194,     0,     0,   194,    43,
       0,     0,   -56,     0,    43,     0,     0,   -64,   -64,   -64,
     -64,     0,   193,   193,    42,     0,   184,    42,   250,   385,
     385,   385,   385,   385,   385,   385,   385,   -64,   -64,   385,
     385,   385,   385,   385,   385,   385,   385,   385,     0,   249,
      42,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,    43,
     358,     0,   240,     0,     0,     0,   240,    73,   -62,   -62,
     -62,     0,   184,  -105,  -105,     0,     0,  -105,     0,     0,
       0,   249,     0,   -21,   -21,   -62,   -21,   -21,   -21,   -21,
     -21,   -21,    43,   -21,   184,   184,   250,   193,     0,   385,
     -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,
     -21,   314,   315,   -21,   194,     0,   -21,   320,   321,   422,
       0,   240,     0,    43,     0,    62,     0,     2,     3,     4,
       5,   194,     0,     0,     8,     0,     0,     0,     0,     0,
     194,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,    42,   194,   240,    18,     0,   249,     0,     0,     0,
     289,   289,   289,   289,   289,   289,   289,   289,     0,   184,
       0,    42,    43,    64,   193,   178,   179,   180,   181,     0,
       0,    42,     8,     0,     0,     0,     0,   194,     0,     9,
      10,    11,   182,    48,    49,    50,   250,     0,    53,    54,
      55,     0,   183,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,     0,     0,   289,   289,   289,   289,   289,   289,   289,
     289,   289,     0,   250,   334,   -94,   -94,   250,   240,   -94,
      46,     0,     0,   194,     0,   289,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,     0,     0,   184,    46,   196,     0,
       0,    46,     0,     0,     0,   194,   194,    43,  -105,  -105,
      43,     0,   386,   386,   386,   386,   386,   386,   386,   386,
       0,    46,   386,   386,   386,   386,   386,   386,   386,   386,
     386,     0,   250,    43,     0,     0,     0,   196,     0,     0,
     196,    46,   -69,   -69,   -69,   -69,    46,   268,   -62,   -62,
     -62,     0,   -39,     0,   -39,   -39,   -39,   -39,   -39,   -39,
     252,   -39,   -69,   -69,   250,     0,     0,   -62,   -39,   -39,
     -39,   -39,   -39,   -39,     0,   -39,   458,   -39,   -39,     0,
     194,   -39,   386,     0,   -39,   -39,     0,     0,     0,     0,
     -21,    46,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,
       0,   -73,   -73,   -73,   -73,     0,   -21,   -21,   -21,   -21,
     -21,   -21,     0,   -21,   -21,   -21,   -21,     0,     0,   -21,
       0,   -73,   -21,   -21,    46,     0,     0,     0,   252,   -73,
     -73,   -73,   -73,    84,    43,   199,   200,   201,   202,   250,
       0,     0,     8,     0,     0,     0,   196,   -73,     0,     9,
      10,    11,   203,     0,    43,    46,     0,   194,   -68,   -68,
     -68,   -68,   204,   196,    43,   -72,   -72,   -72,   -72,     0,
       0,    87,   196,   199,   200,   201,   202,     0,   -68,   -68,
       8,     0,     0,     0,   196,   -72,     0,     9,    10,    11,
     203,     0,   291,   291,   291,   291,   291,   291,   291,   291,
     204,     0,     0,     0,    46,     0,    89,     0,   199,   200,
     201,   202,     0,    47,     0,     8,     0,     0,     0,   196,
       0,     0,     9,    10,    11,   203,     0,     0,   252,     0,
      47,   197,     0,     0,    47,   204,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,     0,   291,   291,   291,   291,   291,
     291,   291,   291,   291,    47,   252,     0,   275,   -94,   252,
       0,     0,   -94,     0,     0,   196,     0,   291,     0,     0,
     197,     0,     0,   197,    47,     0,     0,     0,     0,    47,
       0,     0,   268,   -60,   -60,   -60,     0,   196,   196,    46,
       0,     0,    46,   253,   388,   388,   388,   388,   388,   388,
     388,   388,   -60,     0,   388,   388,   388,   388,   388,   388,
     388,   388,   388,     0,   252,    46,    91,     0,   199,   200,
     201,   202,     0,     0,    47,     8,     0,   -64,   -64,   -64,
     -64,     0,     9,    10,    11,   203,     0,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,   204,   252,   -64,    -3,     1,
       0,     2,     3,     4,     5,     6,     7,    47,     8,  -106,
    -106,   253,   196,  -106,   388,     9,    10,    11,    12,    13,
      14,     0,    15,     0,    16,    17,     0,     0,    18,   197,
       0,    19,    93,     0,   199,   200,   201,   202,    47,     0,
       0,     8,     0,     0,     0,     0,   197,     0,     9,    10,
      11,   203,    32,     0,     0,   197,   -72,   -72,   -72,   -72,
       0,   204,     0,     0,     0,     0,    46,   197,     0,    63,
      65,   252,     0,    32,   -72,   292,   292,   292,   292,   292,
     292,   292,   292,     0,     0,     0,    46,    47,    99,   196,
     178,   179,   180,   181,     0,     0,    46,     8,     0,     0,
       0,     0,   197,     0,     9,    10,    11,   182,     0,   100,
       0,   253,   102,   103,     0,     0,     0,   183,   232,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,     0,   292,   292,
     292,   292,   292,   292,   292,   292,   292,     0,   253,  -105,
       0,     0,   253,     0,     0,  -105,     0,     0,   197,     0,
     292,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,     0,
       0,     0,     0,   232,     0,   -69,   -69,   -69,   -69,     0,
     197,   197,    47,  -106,  -106,    47,     0,   389,   389,   389,
     389,   389,   389,   389,   389,   -69,     0,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   103,   253,    47,     0,
     159,    73,   -60,   -60,   -60,   -20,     0,   -20,   -20,   -20,
     -20,   -20,   -20,     0,   -20,     0,     0,     0,   262,   -60,
       0,   -20,   -20,   -20,   -20,   -20,   -20,    32,   -20,   253,
     -20,   -20,     0,     0,   -20,   264,     0,   -20,   -20,   -68,
     -68,   -68,   -68,     0,     0,   197,     0,   389,     0,     0,
       0,   -64,   -64,   -64,   -64,     0,   277,     0,     0,   -68,
      -2,     1,     0,     2,     3,     4,     5,     6,     7,   -64,
       8,     0,     0,     0,     0,     0,   311,     9,    10,    11,
      12,    13,    14,     0,    15,     0,    16,    17,     0,     0,
      18,   323,     0,    19,     0,    48,    49,    50,    51,    47,
      53,    54,    55,     0,   253,   -69,   -69,   -69,   -69,     1,
       0,     2,     3,     4,     5,     6,     7,     0,     8,    47,
       0,     0,   197,   -69,     0,     9,    10,    11,    12,    47,
       0,     0,    15,     0,    16,    17,     0,   364,    18,   191,
       0,    19,     0,     0,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,     0,     0,     0,     0,     0,     0,     0,   370,
     372,   103,    79,     0,   232,   -99,   -99,   -99,     0,    83,
      86,    86,    86,    86,    86,    86,    86,     0,   191,     0,
       0,   191,   -68,   -68,   -68,   -68,     0,   232,     0,     0,
       0,    86,    86,    86,    86,    86,    86,    86,   130,    86,
     -68,   247,    -5,    -5,     0,    -5,    -5,    -5,    -5,    -5,
      -5,     0,    -5,     0,     0,     0,     0,     0,     0,    -5,
      -5,    -5,    -5,    -5,    -5,     0,    -5,     0,    -5,    -5,
       0,     0,    -5,     0,   439,    -5,     0,    -7,    -7,     0,
      -7,    -7,    -7,    -7,    -7,    -7,     0,    -7,     0,     0,
       0,     0,     0,     0,    -7,    -7,    -7,    -7,    -7,    -7,
       0,    -7,     0,    -7,    -7,     0,     0,    -7,     0,   247,
      -7,     0,    -6,    -6,     0,    -6,    -6,    -6,    -6,    -6,
      -6,     0,    -6,     0,     0,     0,     0,   191,   103,    -6,
      -6,    -6,    -6,    -6,    -6,     0,    -6,     0,    -6,    -6,
       0,     0,    -6,     0,   191,    -6,     0,     0,   232,     0,
       0,   262,   101,   274,   178,   179,   180,   181,   232,     0,
       0,     8,     0,     0,     0,   191,   278,     0,     9,    10,
      11,   182,     0,   286,   295,   295,   295,   295,   295,   295,
     295,   183,     0,     0,   -29,   -29,     0,   -29,   -29,   -29,
     -29,   -29,   -29,     0,   -29,     0,     0,     0,     0,     0,
     191,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   333,
     -29,   -29,     0,     0,   -29,     0,     0,   -29,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,   295,   295,   295,   295,
     295,   295,   295,   356,   295,     0,   247,     0,  -106,     0,
     247,     0,     0,     0,  -106,     0,   191,     0,   365,     0,
       0,     0,     0,     0,   115,     0,   199,   200,   201,   202,
       0,     0,   188,     8,     0,     0,     0,     0,   191,   191,
       9,    10,    11,   203,     0,   383,   392,   392,   392,   392,
     392,   392,   392,   204,     0,   392,   392,   392,   392,   392,
     392,   392,   420,   392,    88,   247,     0,     0,    95,    96,
       0,   188,     0,     0,   188,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,     0,     0,     0,     0,   122,     0,   126,
     128,     0,     0,     0,   244,  -104,     0,   247,     0,    -8,
      -8,  -104,    -8,    -8,    -8,    -8,    -8,    -8,   190,    -8,
       0,     0,     0,   191,     0,   440,    -8,    -8,    -8,    -8,
      -8,    -8,     0,    -8,     0,    -8,    -8,     0,     0,    -8,
       0,     0,    -8,     0,     0,     0,     0,     0,     0,    85,
     117,     0,   199,   200,   201,   202,     0,   190,     0,     8,
     190,     0,     0,     0,     0,     0,     9,    10,    11,   203,
       0,     0,   244,     0,   124,     0,     0,     0,     0,   204,
     246,     0,   247,   328,   -67,   -67,   -67,   -67,   329,   330,
     188,   -33,   -33,     0,   -33,   -33,   -33,   -33,   -33,   -33,
     191,   -33,     0,     0,   -67,   -67,     0,   188,   -33,   -33,
     -33,   -33,   -33,   -33,     0,   -33,     0,   -33,   -33,     0,
       0,   -33,     0,     0,   -33,     0,     0,     0,   188,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,     0,   297,   188,
     188,   188,   304,   305,     0,     0,     0,     0,   246,   -99,
     -99,   -28,   -28,     0,   -28,   -28,   -28,   -28,   -28,   -28,
       0,   -28,     0,   188,     0,     0,   190,     0,   -28,   -28,
     -28,   -28,   -28,   -28,     0,   -28,     0,   -28,   -28,     0,
       0,   -28,     0,   190,   -28,     0,     0,     0,     0,   188,
     188,   188,   348,     0,   352,   354,     0,   188,     0,   244,
       0,     0,     0,   244,   190,   212,   213,   214,   215,   188,
     217,   218,   219,   294,   190,   190,   190,   190,   190,   190,
       0,   189,   212,   213,   214,   215,   216,   217,   218,   219,
       0,   188,   188,     0,     0,     0,     0,     0,     0,   190,
     394,   244,   244,   244,   401,   402,     0,     0,   244,   244,
     244,   412,     0,   416,   418,     0,   244,     0,   244,     0,
     189,     0,     0,   189,     0,   190,   190,   190,   190,   350,
     190,   190,     0,   190,     0,   246,     0,     0,     0,   246,
       0,     0,     0,   245,   119,   190,   199,   200,   201,   202,
     244,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   203,     0,     0,   188,   190,   190,     0,
     187,     0,     0,   204,     0,   391,   246,   246,   246,   246,
     246,   246,     0,     0,   246,   246,   246,   246,   414,   246,
     246,     0,   246,     0,   246,     0,     0,     0,   121,     0,
     199,   200,   201,   202,     0,    94,     0,     8,     0,   187,
       0,   245,   187,     0,     9,    10,    11,   203,     0,     0,
       0,     0,     0,     0,   120,   244,   246,   204,     0,   189,
     -30,   -30,   243,   -30,   -30,   -30,   -30,   -30,   -30,     0,
     -30,     0,   190,   188,     0,     0,   189,   -30,   -30,   -30,
     -30,   -30,   -30,     0,   -30,     0,   -30,   -30,     0,     0,
     -30,     0,     0,   -30,     0,     0,     0,   189,     0,   -84,
     -84,   -84,   -84,     0,     0,     0,   -84,   189,   189,   189,
     189,   189,   189,   -84,   -84,   -84,   -84,   -31,   -31,     0,
     -31,   -31,   -31,   -31,   -31,   -31,   -84,   -31,     0,     0,
     243,   246,   189,     0,   -31,   -31,   -31,   -31,   -31,   -31,
     186,   -31,     0,   -31,   -31,     0,     0,   -31,   187,   190,
     -31,    74,   -67,   -67,   -67,   -67,    75,    76,   189,   189,
     189,   189,     0,   189,   189,   187,   189,     0,   245,     0,
     -67,     0,   245,    90,    48,    49,    50,     0,   189,   186,
      54,    55,   186,     0,     0,     0,   187,   123,     0,   199,
     200,   201,   202,   118,     0,     0,     8,   187,   187,   303,
     189,   189,   242,     9,    10,    11,   203,     0,     0,   245,
     245,   245,   245,   245,   245,     0,   204,   245,   245,   245,
     245,   187,   245,   245,     0,   245,     0,   245,     0,     0,
       0,     0,     0,     0,   125,     0,   199,   200,   201,   202,
       0,     0,     0,     8,     0,     0,     0,   187,   187,   346,
       9,    10,    11,   203,     0,   187,     0,   243,     0,   245,
       0,   243,     0,   204,     0,     0,     0,   187,     0,     0,
     242,   314,   315,   316,   317,   189,   319,   320,   321,   212,
     213,   214,     0,     0,   217,   218,   219,     0,   186,   187,
     187,     0,     0,   127,     0,   199,   200,   201,   202,   243,
     243,   400,     8,     0,     0,   186,   243,   243,   410,     9,
      10,    11,   203,     0,   243,     0,   243,     0,   314,   315,
     316,     0,   204,   319,   320,   321,   186,     0,     0,   212,
     213,   214,     0,     0,   245,   218,   219,   299,   186,     0,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,   243,     0,
     -32,   -32,   189,   -32,   -32,   -32,   -32,   -32,   -32,     0,
     -32,   186,  -104,  -104,   187,     0,  -104,   -32,   -32,   -32,
     -32,   -32,   -32,     0,   -32,     0,   -32,   -32,     0,     0,
     -32,     0,     0,   -32,     0,     0,     0,   186,   344,   -85,
     -85,   -85,   -85,     0,     0,   186,   -85,   242,     0,     0,
       0,   242,     0,   -85,   -85,   -85,   -85,   186,   129,     0,
     199,   200,   201,   202,     0,     0,   -85,     8,     0,     0,
       0,     0,     0,   243,     9,    10,    11,   203,     0,   186,
     186,     0,     0,     0,     0,     0,     0,   204,     0,   396,
     242,   187,   314,   315,   316,     0,   242,   408,   320,   321,
       0,     0,     0,     0,   242,     0,   242,     1,     0,     2,
       3,     4,     5,   220,   221,     0,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,     0,
     222,     0,   223,   224,     0,     0,    18,     0,   242,   225,
     -23,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,     0,     0,   186,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,     0,    -4,    -4,     0,
       0,    -4,   -38,   -38,    -4,   -38,   -38,   -38,   -38,   -38,
     -38,     0,   -38,     0,     0,     0,     0,     0,     0,   -38,
     -38,   -38,   -38,   -38,   -38,     0,   -38,     0,   -38,   -38,
       0,     0,   -38,     0,     0,   -38,     0,     0,     0,     0,
       0,     0,     0,   242,     0,   -11,   -11,     0,   -11,   -11,
     -11,   -11,   -11,   -11,     0,   -11,     0,     0,     0,     0,
       0,   186,   -11,   -11,   -11,   -11,   -11,   -11,     0,   -11,
       0,   -11,   -11,     0,     0,   -11,   -44,   -44,   -11,   -44,
     -44,   -44,   -44,   -44,   -44,     0,   -44,     0,     0,     0,
       0,     0,     0,   -44,   -44,   -44,   -44,   -44,   -44,     0,
     -44,     0,   -44,   -44,     0,     0,   -44,   -43,   -43,   -44,
     -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,     0,     0,
       0,     0,     0,     0,   -43,   -43,   -43,   -43,   -43,   -43,
       0,   -43,     0,   -43,   -43,     0,     0,   -43,     0,   -26,
     -43,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,     0,
       0,     0,     0,     0,     0,   -26,   -26,   -26,   -26,   -26,
     -26,     0,   -26,     0,   -26,   -26,     0,     0,   -26,     0,
       0,   -26,   -26,     1,     0,     2,     3,     4,     5,   220,
     221,     0,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,     0,   222,     0,   223,   224,
       0,     0,    18,     0,     0,   225,   -22,   -25,     0,   -25,
     -25,   -25,   -25,   -25,   -25,     0,   -25,     0,     0,     0,
       0,     0,     0,   -25,   -25,   -25,   -25,   -25,   -25,     0,
     -25,     0,   -25,   -25,     0,     0,   -25,     0,     0,   -25,
     -25,   -27,     0,   -27,   -27,   -27,   -27,   -27,   -27,     0,
     -27,     0,     0,     0,     0,     0,     0,   -27,   -27,   -27,
     -27,   -27,   -27,     0,   -27,     0,   -27,   -27,     0,     0,
     -27,     0,     0,   -27,   -27,   -21,   -21,     0,   -21,   -21,
     -21,   -21,   -21,   -21,     0,   -21,     0,     0,     0,     0,
       0,     0,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,
       0,   -21,   -21,     0,     0,   -21,     0,   -24,   -21,   -24,
     -24,   -24,   -24,   -24,   -24,     0,   -24,     0,     0,     0,
       0,     0,     0,   -24,   -24,   -24,   -24,   -24,   -24,     0,
     -24,     0,   -24,   -24,     0,     0,   -24,     0,     0,   -24,
     -24,   -10,   -10,     0,   -10,   -10,   -10,   -10,   -10,   -10,
       0,   -10,     0,     0,     0,     0,     0,     0,   -10,   -10,
     -10,   -10,   -10,   -10,     0,   -10,     0,   -10,   -10,     0,
       0,   -10,   -37,   -37,   -10,   -37,   -37,   -37,   -37,   -37,
     -37,     0,   -37,     0,     0,     0,     0,     0,     0,   -37,
     -37,   -37,   -37,   -37,   -37,     0,   -37,     0,   -37,   -37,
       0,     0,   -37,   -34,   -34,   -37,   -34,   -34,   -34,   -34,
     -34,   -34,     0,   -34,     0,     0,     0,     0,     0,     0,
     -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,     0,   -34,
     -34,     0,     0,   -34,   -36,   -36,   -34,   -36,   -36,   -36,
     -36,   -36,   -36,     0,   -36,     0,     0,     0,     0,     0,
       0,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,     0,
     -36,   -36,     0,     0,   -36,   -35,   -35,   -36,   -35,   -35,
     -35,   -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,
       0,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,
       0,   -35,   -35,     0,     0,   -35,   -42,   -42,   -35,   -42,
     -42,   -42,   -42,   -42,   -42,     0,   -42,     0,     0,     0,
       0,     0,     0,   -42,   -42,   -42,   -42,   -42,   -42,     0,
     -42,     0,   -42,   -42,     0,     0,   -42,   -40,   -40,   -42,
     -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,
       0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,   -40,
       0,   -40,     0,   -40,   -40,     0,     0,   -40,   -14,   -14,
     -40,   -14,   -14,   -14,   -14,   -14,   -14,     0,   -14,     0,
       0,     0,     0,     0,     0,   -14,   -14,   -14,   -14,   -14,
     -14,     0,   -14,     0,   -14,   -14,     0,     0,   -14,   -45,
     -45,   -14,   -45,   -45,   -45,   -45,   -45,   -45,     0,   -45,
       0,     0,     0,     0,     0,     0,   -45,   -45,   -45,   -45,
     -45,   -45,     0,   -45,     0,   -45,   -45,     0,     0,   -45,
       0,   -29,   -45,   -29,   -29,   -29,   -29,   -29,   -29,     0,
     -29,     0,     0,     0,     0,     0,     0,   -29,   -29,   -29,
     -29,   -29,   -29,     0,   -29,     0,   -29,   -29,     0,     0,
     -29,     0,     0,   -29,   -29,   -33,     0,   -33,   -33,   -33,
     -33,   -33,   -33,     0,   -33,     0,     0,     0,     0,     0,
       0,   -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,     0,
     -33,   -33,     0,     0,   -33,     0,     0,   -33,   -33,   -28,
       0,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,     0,
       0,     0,     0,     0,     0,   -28,   -28,   -28,   -28,   -28,
     -28,     0,   -28,     0,   -28,   -28,     0,     0,   -28,     0,
       0,   -28,   -28,   -30,     0,   -30,   -30,   -30,   -30,   -30,
     -30,     0,   -30,     0,     0,     0,     0,     0,     0,   -30,
     -30,   -30,   -30,   -30,   -30,     0,   -30,     0,   -30,   -30,
       0,     0,   -30,     0,     0,   -30,   -30,   -31,     0,   -31,
     -31,   -31,   -31,   -31,   -31,     0,   -31,     0,     0,     0,
       0,     0,     0,   -31,   -31,   -31,   -31,   -31,   -31,     0,
     -31,     0,   -31,   -31,     0,     0,   -31,     0,     0,   -31,
     -31,   -32,     0,   -32,   -32,   -32,   -32,   -32,   -32,     0,
     -32,     0,     0,     0,     0,     0,     0,   -32,   -32,   -32,
     -32,   -32,   -32,     0,   -32,     0,   -32,   -32,     0,     0,
     -32,     0,     0,   -32,   -32,   -11,     0,   -11,   -11,   -11,
     -11,   -11,   -11,     0,   -11,     0,     0,     0,     0,     0,
       0,   -11,   -11,   -11,   -11,   -11,   -11,     0,   -11,     0,
     -11,   -11,     0,     0,   -11,     0,     0,   -11,   -11,   -38,
       0,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,     0,
       0,     0,     0,     0,     0,   -38,   -38,   -38,   -38,   -38,
     -38,     0,   -38,     0,   -38,   -38,     0,     0,   -38,     0,
       0,   -38,   -38,   -10,     0,   -10,   -10,   -10,   -10,   -10,
     -10,     0,   -10,     0,     0,     0,     0,     0,     0,   -10,
     -10,   -10,   -10,   -10,   -10,     0,   -10,     0,   -10,   -10,
       0,     0,   -10,     0,     0,   -10,   -10,   -44,     0,   -44,
     -44,   -44,   -44,   -44,   -44,     0,   -44,     0,     0,     0,
       0,     0,     0,   -44,   -44,   -44,   -44,   -44,   -44,     0,
     -44,     0,   -44,   -44,     0,     0,   -44,     0,     0,   -44,
     -44,   -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,     0,
     -43,     0,     0,     0,     0,     0,     0,   -43,   -43,   -43,
     -43,   -43,   -43,     0,   -43,     0,   -43,   -43,     0,     0,
     -43,     0,     0,   -43,   -43,   -21,     0,   -21,   -21,   -21,
     -21,   -21,   -21,     0,   -21,     0,     0,     0,     0,     0,
       0,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,     0,
     -21,   -21,     0,     0,   -21,     0,     0,   -21,   -21,   -37,
       0,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,     0,
       0,     0,     0,     0,     0,   -37,   -37,   -37,   -37,   -37,
     -37,     0,   -37,     0,   -37,   -37,     0,     0,   -37,     0,
       0,   -37,   -37,   -34,     0,   -34,   -34,   -34,   -34,   -34,
     -34,     0,   -34,     0,     0,     0,     0,     0,     0,   -34,
     -34,   -34,   -34,   -34,   -34,     0,   -34,     0,   -34,   -34,
       0,     0,   -34,     0,     0,   -34,   -34,   -36,     0,   -36,
     -36,   -36,   -36,   -36,   -36,     0,   -36,     0,     0,     0,
       0,     0,     0,   -36,   -36,   -36,   -36,   -36,   -36,     0,
     -36,     0,   -36,   -36,     0,     0,   -36,     0,     0,   -36,
     -36,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
     -35,     0,     0,     0,     0,     0,     0,   -35,   -35,   -35,
     -35,   -35,   -35,     0,   -35,     0,   -35,   -35,     0,     0,
     -35,     0,     0,   -35,   -35,   -42,     0,   -42,   -42,   -42,
     -42,   -42,   -42,     0,   -42,     0,     0,     0,     0,     0,
       0,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,     0,
     -42,   -42,     0,     0,   -42,     0,     0,   -42,   -42,   -40,
       0,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,
       0,     0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,
     -40,     0,   -40,     0,   -40,   -40,     0,     0,   -40,     0,
       0,   -40,   -40,   -45,     0,   -45,   -45,   -45,   -45,   -45,
     -45,     0,   -45,     0,     0,     0,     0,     0,     0,   -45,
     -45,   -45,   -45,   -45,   -45,     0,   -45,     0,   -45,   -45,
       0,     0,   -45,     0,     0,   -45,   -45,     1,     0,     2,
       3,     4,     5,   220,   221,     0,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,     0,     0,     0,
     222,     0,   223,   224,     0,     0,    18,     0,   131,   225,
     199,   200,   201,   202,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   203,     0,   233,
       0,   234,   235,   236,   237,     0,     0,   204,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   238,     0,
     263,     0,   178,   179,   180,   181,     0,     0,   239,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   182,
       0,   276,     0,   178,   179,   180,   181,     0,     0,   183,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     182,     0,   293,     0,   280,   281,   282,   283,     0,     0,
     183,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   284,     0,   296,     0,   280,   281,   282,   283,     0,
       0,   285,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   284,     0,   298,     0,   280,   281,   282,   283,
       0,     0,   285,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   284,     0,   300,     0,   280,   281,   282,
     283,     0,     0,   285,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   284,     0,   302,     0,   280,   281,
     282,   283,     0,     0,   285,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   284,     0,   310,     0,     2,
       3,     4,     5,     0,     0,   285,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,     0,   322,     0,
     178,   179,   180,   181,     0,     0,    18,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   182,     0,   341,
       0,   280,   281,   282,   283,     0,     0,   183,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   284,     0,
     343,     0,   280,   281,   282,   283,     0,     0,   285,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   284,
       0,   345,     0,   280,   281,   282,   283,     0,     0,   285,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     284,     0,   347,     0,   280,   281,   282,   283,     0,     0,
     285,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   284,     0,   349,     0,   280,   281,   282,   283,     0,
       0,   285,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   284,     0,   351,     0,   280,   281,   282,   283,
       0,     0,   285,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   284,     0,   353,     0,   280,   281,   282,
     283,     0,     0,   285,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   284,     0,   355,     0,   280,   281,
     282,   283,     0,     0,   285,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   284,     0,   357,     0,   280,
     281,   282,   283,     0,     0,   285,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   284,     0,   363,     0,
     178,   179,   180,   181,     0,     0,   285,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   182,     0,   369,
       0,   178,   179,   180,   181,     0,     0,   183,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   182,     0,
     371,     0,   178,   179,   180,   181,     0,     0,   183,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   182,
       0,   390,     0,   377,   378,   379,   380,     0,     0,   183,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     381,     0,   393,     0,   377,   378,   379,   380,     0,     0,
     382,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   381,     0,   395,     0,   377,   378,   379,   380,     0,
       0,   382,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   381,     0,   397,     0,   377,   378,   379,   380,
       0,     0,   382,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   381,     0,   399,     0,   377,   378,   379,
     380,     0,     0,   382,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   381,     0,   405,     0,   377,   378,
     379,   380,     0,     0,   382,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   381,     0,   407,     0,   377,
     378,   379,   380,     0,     0,   382,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   381,     0,   409,     0,
     377,   378,   379,   380,     0,     0,   382,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   381,     0,   411,
       0,   377,   378,   379,   380,     0,     0,   382,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   381,     0,
     413,     0,   377,   378,   379,   380,     0,     0,   382,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   381,
       0,   415,     0,   377,   378,   379,   380,     0,     0,   382,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     381,     0,   417,     0,   377,   378,   379,   380,     0,     0,
     382,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   381,     0,   419,     0,   377,   378,   379,   380,     0,
       0,   382,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   381,     0,   421,     0,   377,   378,   379,   380,
       0,     0,   382,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   381,     0,   438,     0,   178,   179,   180,
     181,     0,     0,   382,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   182,   -87,   -87,   -87,   -87,     0,
       0,     0,   -87,     0,   183,     0,     0,     0,     0,   -87,
     -87,   -87,   -87,     2,     3,     4,     5,     0,     0,     0,
       8,     0,   -87,     0,     0,     0,     0,     9,    10,    11,
      12,   199,   200,   201,   202,     0,     0,     0,     8,     0,
      18,     0,     0,     0,     0,     9,    10,    11,   203,   178,
     179,   180,   181,     0,     0,     0,     8,     0,   204,     0,
       0,     0,     0,     9,    10,    11,   182,   280,   281,   282,
     283,     0,     0,     0,     8,     0,   183,     0,     0,     0,
       0,     9,    10,    11,   284,   234,   235,   236,   237,     0,
       0,     0,     8,     0,   285,     0,     0,     0,     0,     9,
      10,    11,   238,   377,   378,   379,   380,     0,     0,     0,
       8,     0,   239,     0,     0,     0,     0,     9,    10,    11,
     381,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,     0,
     382,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,
       0,     0,     0,  -107,  -107,     0,     0,  -107,     0,     0,
       0,     0,     0,   -78,   -78,     0,     0,   332,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,     0,     0,     0,     0,     0,     0,
     -82,   -82,     0,     0,   -82,     0,     0,     0,   -88,   -88,
       0,     0,   -88,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,
       0,     0,     0,     0,     0,   -95,   -95,     0,     0,   -95,
       0,     0,     0,   -96,   -96,     0,     0,   -96,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,     0,     0,     0,     0,     0,     0,
     -83,   -83,     0,     0,   -83,     0,     0,     0,   -98,   -98,
       0,     0,   -98,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,     0,
       0,     0,     0,     0,     0,   -97,   -97,     0,     0,   -97,
       0,     0,     0,   -89,   -89,     0,     0,   -89,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,     0,     0,     0,     0,  -107,     0,
       0,     0,     0,     0,  -107,     0,   -78,     0,     0,     0,
       0,     0,    78,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,     0,
       0,     0,     0,   -82,     0,     0,     0,     0,     0,   -82,
       0,   -88,     0,     0,     0,     0,     0,   -88,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,     0,     0,     0,     0,   -95,     0,
       0,     0,     0,     0,   -95,     0,   -96,     0,     0,     0,
       0,     0,   -96,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,     0,
       0,     0,     0,   -83,     0,     0,     0,     0,     0,   -83,
       0,   -98,     0,     0,     0,     0,     0,   -98,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,     0,     0,     0,     0,   -97,     0,
       0,     0,     0,     0,   -97,     0,   -89,     0,     0,     0,
       0,     0,   -89,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,     0,
       0,     0,     0,     0,     0,  -105,     0,     0,     0,  -105,
       0,     0,     0,  -106,     0,     0,     0,  -106,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,     0,     0,     0,     0,     0,     0,
    -104,     0,     0,     0,  -104,     0,     0,     0,  -107,     0,
       0,     0,  -107,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,     0,
       0,     0,     0,     0,     0,   -78,     0,     0,     0,   273,
       0,     0,     0,   -82,     0,     0,     0,   -82,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,     0,     0,     0,     0,     0,     0,
     -88,     0,     0,     0,   -88,     0,     0,     0,   -95,     0,
       0,     0,   -95,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,     0,
       0,     0,     0,     0,     0,   -96,     0,     0,     0,   -96,
       0,     0,     0,   -83,     0,     0,     0,   -83,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,     0,     0,     0,     0,     0,     0,
     -98,     0,     0,     0,   -98,     0,     0,     0,   -97,     0,
       0,     0,   -97,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,     0,
       0,     0,     0,     0,     0,   -89,     0,     0,     0,   -89,
       0,     0,   441,   -94,   -94,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,     0,     0,     0,     0,     0,     0,  -104,  -104,     0,
       0,     0,     0,     0,     0,  -107,  -107,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,     0,     0,     0,     0,     0,     0,   -81,
     -81,     0,     0,     0,     0,     0,     0,   -82,   -82,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,     0,     0,     0,     0,     0,
       0,   -88,   -88,     0,     0,     0,     0,     0,     0,   -95,
     -95,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   331,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,     0,
       0,     0,     0,   -96,   -96,     0,     0,     0,     0,     0,
       0,   -77,   -77,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   314,   315,   316,   317,   -53,   319,   320,   321,     0,
       0,     0,     0,     0,     0,   -78,   -78,     0,     0,     0,
       0,     0,     0,   -53,   -53,   314,   315,   316,   -57,   -57,
     319,   320,   321,   314,   315,   316,   -61,   -61,   -61,   320,
     321,     0,     0,     0,     0,     0,     0,   -57,   -57,     0,
       0,     0,     0,     0,     0,   -61,   -61,   314,   315,   -65,
     -65,   -65,   -65,   320,   321,   314,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,     0,     0,     0,     0,     0,     0,   -65,
     -65,     0,     0,     0,     0,     0,     0,   -76,   -76,   331,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   314,   315,   -71,
     -71,   -71,   -71,   320,   321,     0,     0,     0,     0,     0,
       0,   -75,   -75,     0,     0,     0,     0,     0,     0,   -71,
     -71,   314,   315,   -70,   -70,   -70,   -70,   320,   321,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,
       0,     0,     0,   -70,   -70,     0,     0,     0,     0,     0,
       0,   -80,   -80,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   314,   315,   316,   317,   318,   319,   320,   321,     0,
       0,     0,     0,     0,     0,   -79,   -79,     0,     0,     0,
       0,     0,     0,   -48,   -48,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,     0,     0,     0,     0,     0,     0,   -83,   -83,     0,
       0,     0,     0,     0,     0,   -98,   -98,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,     0,     0,     0,     0,     0,     0,   -97,
     -97,     0,     0,     0,     0,     0,     0,   -89,   -89,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,
     -99,   -99,     0,     0,     0,     0,     0,     0,   366,   -94,
     212,   213,   214,   215,   216,   217,   218,   219,   212,   213,
     214,   215,   216,   217,   218,   219,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
     140,   212,   213,   214,   215,   216,   217,   218,   219,   272,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   -74,   212,   213,   214,   215,   216,   217,   218,   219,
     212,   213,   214,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,   339,     0,     0,     0,     0,     0,
       0,     0,   360,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,     0,
       0,     0,     0,     0,     0,  -105,     0,     0,     0,     0,
       0,     0,     0,  -106,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
       0,     0,     0,     0,     0,     0,  -104,     0,     0,     0,
       0,     0,     0,     0,  -107,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,     0,     0,     0,     0,     0,     0,   -81,     0,     0,
       0,     0,     0,     0,     0,   -82,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,     0,     0,     0,     0,     0,     0,   -88,     0,
       0,     0,     0,     0,     0,     0,   -95,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   272,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,     0,     0,     0,     0,     0,     0,   -96,
       0,     0,     0,     0,     0,     0,     0,   -77,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   212,   213,   214,   215,
     216,   217,   218,   219,     0,     0,     0,     0,     0,     0,
     -78,     0,     0,     0,     0,     0,     0,     0,   403,   212,
     213,   214,   215,   -53,   217,   218,   219,   212,   213,   214,
     -57,   -57,   217,   218,   219,     0,     0,     0,     0,     0,
       0,   -53,     0,     0,     0,     0,     0,     0,     0,   -57,
     212,   213,   214,   -61,   -61,   -61,   218,   219,   212,   213,
     -65,   -65,   -65,   -65,   218,   219,     0,     0,     0,     0,
       0,     0,   -61,     0,     0,     0,     0,     0,     0,     0,
     -65,   212,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   272,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,
       0,     0,     0,   -76,     0,     0,     0,     0,     0,     0,
       0,   -75,   212,   213,   -71,   -71,   -71,   -71,   218,   219,
     212,   213,   -70,   -70,   -70,   -70,   218,   219,     0,     0,
       0,     0,     0,     0,   -71,     0,     0,     0,     0,     0,
       0,     0,   -70,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,     0,
       0,     0,     0,     0,     0,   -80,     0,     0,     0,     0,
       0,     0,     0,   -79,   212,   213,   214,   215,   216,   217,
     218,   219,   212,   213,   214,   215,   216,   217,   218,   219,
       0,     0,     0,     0,     0,     0,   -48,     0,     0,     0,
       0,     0,     0,     0,   427,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   212,   213,   214,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,   -83,     0,     0,
       0,     0,     0,     0,     0,   432,   212,   213,   214,   215,
     216,   217,   218,   219,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,     0,     0,     0,     0,     0,     0,   434,     0,
       0,     0,     0,     0,     0,     0,   -98,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   212,   213,   214,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,   -97,
       0,     0,     0,     0,     0,     0,     0,   453,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,     0,
     -89,     0,     0,     0,     0,     0,   -94,   279,    77,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,    48,    49,    50,    51,
      52,    53,    54,    55,     0,     0,     0,     0,   -74,     0,
       0,     0,     0,     0,     0,     0,   105,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,    77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,     0,     0,     0,     0,   -81,     0,     0,
       0,     0,     0,     0,     0,   -77,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,    48,    49,    50,    51,   -53,    53,
      54,    55,     0,     0,     0,     0,   -78,     0,     0,     0,
       0,     0,     0,     0,   -53,    48,    49,    50,   -57,   -57,
      53,    54,    55,    48,    49,    50,   -61,   -61,   -61,    54,
      55,     0,     0,     0,     0,   -57,     0,     0,     0,     0,
       0,     0,     0,   -61,    48,    49,   -65,   -65,   -65,   -65,
      54,    55,    48,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
       0,     0,     0,     0,   -65,     0,     0,     0,     0,     0,
       0,     0,   -76,    77,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,    48,    49,   -71,   -71,   -71,   -71,    54,    55,     0,
       0,     0,     0,   -75,     0,     0,     0,     0,     0,     0,
       0,   -71,    48,    49,   -70,   -70,   -70,   -70,    54,    55,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,
       0,     0,   -70,     0,     0,     0,     0,     0,     0,     0,
     -80,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,    48,
      49,    50,    51,    52,    53,    54,    55,     0,     0,     0,
       0,   -79,     0,     0,     0,     0,     0,     0,     0,   -48,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,     0,     0,     0,     0,
    -105,     0,     0,     0,     0,     0,     0,     0,  -106,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,     0,     0,     0,     0,  -104,
       0,     0,     0,     0,     0,     0,     0,  -107,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,     0,     0,     0,     0,   -82,     0,
       0,     0,     0,     0,     0,     0,   -88,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,     0,     0,     0,     0,   -95,     0,     0,
       0,     0,     0,     0,     0,   -96,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,    48,    49,    50,    51,    52,    53,
      54,    55,     0,     0,     0,     0,   -83,     0,     0,     0,
       0,     0,     0,     0,   374,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,     0,     0,     0,     0,   -98,     0,     0,     0,     0,
       0,     0,     0,   -97,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -89
};

static const yytype_int16 yycheck[] =
{
       0,     0,   225,     0,     0,     0,     0,     0,   275,   312,
       0,    30,   279,    29,    30,     6,    30,    17,    18,     6,
       6,    21,    21,     0,    21,    21,    21,    21,    21,    13,
     144,    21,   335,   256,     6,     6,    23,    23,    29,     6,
       6,    41,    29,    29,    21,    45,    29,    31,    32,     0,
      30,    23,   166,    31,    32,    30,    56,    57,    29,    13,
      60,    61,    29,    29,    12,    13,    66,   334,     0,     1,
      21,     3,     4,     5,     6,     7,     8,    31,    10,     0,
      80,    12,    13,    31,    32,    17,    18,    19,    20,    21,
      22,    29,    24,    25,    26,    27,    12,    13,    30,   366,
      31,    33,     0,     1,    31,     3,     4,     5,     6,     7,
       8,   111,    10,     1,   114,    31,    32,     9,     6,    17,
      18,    19,    20,    21,    22,    31,    24,    25,    26,    27,
      12,    13,    30,    12,    13,    33,     9,    10,    11,    12,
      13,    14,    15,    16,   144,    13,   142,   143,   148,    31,
      32,    31,    31,   456,    13,    21,    22,    30,    31,    32,
      31,    29,    35,   163,    31,    31,   166,     6,   164,   165,
      29,    12,    13,   150,   441,   175,   175,   173,   175,   175,
     175,   175,   175,   183,    23,   175,    11,    12,    13,    14,
      31,   168,   192,    29,     1,   309,    31,    32,    29,     6,
      11,    12,    13,    14,   204,    13,    31,    32,    11,    12,
      13,    14,   212,   213,   214,   215,   216,   217,   218,   219,
      31,    32,    34,    31,   224,    31,   449,     1,    31,     3,
       4,     5,     6,     0,    13,    29,    10,    21,    22,   239,
      12,    13,    14,    17,    18,    19,    20,    31,   248,    29,
      17,    18,    31,    32,    21,    33,    30,    31,    29,    31,
      11,    12,    13,    14,    29,   265,   266,   267,   268,   269,
     270,   271,   272,   273,    41,   275,    12,    13,    14,   279,
      31,    32,    12,    13,    14,   285,    29,   287,    12,    13,
      57,     9,    10,    60,    61,    31,    32,    15,    16,    66,
      29,    31,    32,    31,    32,    29,   306,   307,   308,   309,
      31,    32,   312,    80,   314,   315,   316,   317,   318,   319,
     320,   321,   436,    18,   324,   325,   326,   327,   328,   329,
     330,   331,   332,    29,   334,   335,     9,    10,    11,    12,
      13,    14,    15,    16,   111,   459,    11,    12,    13,    14,
      31,     1,     6,     3,     4,     5,     6,    52,    31,    32,
      10,    33,    57,    31,    29,    60,   366,    17,    18,    19,
      20,    31,    32,    21,    22,    70,    31,   144,    31,    29,
      30,   148,   382,    30,   384,    80,     1,    30,     3,     4,
       5,     6,     7,     8,    30,    10,    12,    13,    14,   166,
      12,    13,    17,    18,    19,    20,    21,    22,   175,    24,
      25,    26,    27,    29,    31,    30,   183,    29,    33,    34,
      11,    12,    13,    14,    30,   192,    11,    12,    13,    14,
      31,    32,    31,    32,    29,    30,   436,   204,   434,   435,
      31,   441,    31,    32,    29,   212,   213,   214,   215,   216,
     217,   218,   219,   148,    29,    29,   456,   224,    29,   459,
      29,   457,   458,    12,    13,    14,   466,   466,    12,    13,
      14,   166,   239,     9,    10,    11,    12,    13,    14,    15,
      16,   248,    31,    32,    31,    31,     9,    31,   183,    31,
       9,    10,    11,    12,    13,    14,    15,    16,   265,   266,
     267,   268,   269,   270,   271,   272,   273,     6,   275,   204,
      29,    30,   279,     6,    31,     0,    35,    31,   285,    31,
     287,   216,    10,    11,    12,    13,    14,    15,    16,    12,
      13,    14,    17,    18,    31,    31,    21,    31,    12,    13,
     307,   308,   309,    31,   239,   312,    29,   314,   315,   316,
     317,   318,   319,   320,   321,    29,    41,   324,   325,   326,
     327,   328,   329,   330,   331,   332,    31,   334,   335,    29,
     265,    34,    57,     9,    31,    60,    61,    31,   273,    34,
     275,    66,    29,    29,   279,    29,    11,    12,    13,    14,
     285,    11,    12,    13,    14,    80,    29,     9,    10,   366,
      31,    33,    29,    15,    16,    18,    31,    32,    12,    13,
      14,    31,   307,   308,    31,   382,     1,   384,     3,     4,
       5,     6,    33,   318,    34,    10,   111,    31,    31,   324,
      21,   147,    17,    18,    19,    20,   168,   332,   111,   334,
      11,    12,    13,    14,    57,    30,    31,    60,    -1,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,   144,
      31,    32,    -1,   148,    -1,    78,    -1,    80,    -1,   436,
      -1,   366,    30,    31,   441,    -1,    -1,    35,    -1,    -1,
      -1,   166,    11,    12,    13,    14,    -1,   382,    -1,   456,
     175,    -1,   459,    -1,     3,     4,     5,     6,   183,   466,
      -1,    10,    31,    32,    -1,    -1,    -1,   192,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    30,    11,    12,    13,    14,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   148,    -1,    -1,    -1,   224,
      -1,    -1,    31,    32,    -1,    -1,   441,    -1,     0,    11,
      12,    13,    14,   166,   239,     9,    10,    11,    12,    13,
      14,    15,    16,   248,   459,    17,    18,    29,    -1,    21,
     183,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    41,
     275,   204,    29,    30,   279,    12,    13,    14,    35,    -1,
     285,    -1,   287,    -1,    -1,    57,    -1,    -1,    60,    61,
      -1,    -1,    29,    -1,    66,    -1,    -1,    11,    12,    13,
      14,    -1,   307,   308,   309,    -1,   239,   312,    80,   314,
     315,   316,   317,   318,   319,   320,   321,    31,    32,   324,
     325,   326,   327,   328,   329,   330,   331,   332,    -1,   334,
     335,     9,    10,    11,    12,    13,    14,    15,    16,   111,
     273,    -1,   275,    -1,    -1,    -1,   279,    11,    12,    13,
      14,    -1,   285,    31,    32,    -1,    -1,    35,    -1,    -1,
      -1,   366,    -1,     0,     1,    29,     3,     4,     5,     6,
       7,     8,   144,    10,   307,   308,   148,   382,    -1,   384,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,     9,    10,    30,   166,    -1,    33,    15,    16,   332,
      -1,   334,    -1,   175,    -1,     1,    -1,     3,     4,     5,
       6,   183,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
     192,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,   436,   204,   366,    30,    -1,   441,    -1,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,   382,
      -1,   456,   224,     1,   459,     3,     4,     5,     6,    -1,
      -1,   466,    10,    -1,    -1,    -1,    -1,   239,    -1,    17,
      18,    19,    20,     9,    10,    11,   248,    -1,    14,    15,
      16,    -1,    30,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,    -1,   275,    30,    31,    32,   279,   441,    35,
       0,    -1,    -1,   285,    -1,   287,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,   459,    17,    18,    -1,
      -1,    21,    -1,    -1,    -1,   307,   308,   309,    31,    32,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,   321,
      -1,    41,   324,   325,   326,   327,   328,   329,   330,   331,
     332,    -1,   334,   335,    -1,    -1,    -1,    57,    -1,    -1,
      60,    61,    11,    12,    13,    14,    66,    11,    12,    13,
      14,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
      80,    10,    31,    32,   366,    -1,    -1,    31,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
     382,    30,   384,    -1,    33,    34,    -1,    -1,    -1,    -1,
       1,   111,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    11,    12,    13,    14,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    30,
      -1,    31,    33,    34,   144,    -1,    -1,    -1,   148,    11,
      12,    13,    14,     1,   436,     3,     4,     5,     6,   441,
      -1,    -1,    10,    -1,    -1,    -1,   166,    29,    -1,    17,
      18,    19,    20,    -1,   456,   175,    -1,   459,    11,    12,
      13,    14,    30,   183,   466,    11,    12,    13,    14,    -1,
      -1,     1,   192,     3,     4,     5,     6,    -1,    31,    32,
      10,    -1,    -1,    -1,   204,    31,    -1,    17,    18,    19,
      20,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
      30,    -1,    -1,    -1,   224,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     0,    -1,    10,    -1,    -1,    -1,   239,
      -1,    -1,    17,    18,    19,    20,    -1,    -1,   248,    -1,
      17,    18,    -1,    -1,    21,    30,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,    41,   275,    -1,    30,    31,   279,
      -1,    -1,    35,    -1,    -1,   285,    -1,   287,    -1,    -1,
      57,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    11,    12,    13,    14,    -1,   307,   308,   309,
      -1,    -1,   312,    80,   314,   315,   316,   317,   318,   319,
     320,   321,    31,    -1,   324,   325,   326,   327,   328,   329,
     330,   331,   332,    -1,   334,   335,     1,    -1,     3,     4,
       5,     6,    -1,    -1,   111,    10,    -1,    11,    12,    13,
      14,    -1,    17,    18,    19,    20,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    30,   366,    31,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,   144,    10,    31,
      32,   148,   382,    35,   384,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,   166,
      -1,    33,     1,    -1,     3,     4,     5,     6,   175,    -1,
      -1,    10,    -1,    -1,    -1,    -1,   183,    -1,    17,    18,
      19,    20,     0,    -1,    -1,   192,    11,    12,    13,    14,
      -1,    30,    -1,    -1,    -1,    -1,   436,   204,    -1,    17,
      18,   441,    -1,    21,    29,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,    -1,    -1,   456,   224,     1,   459,
       3,     4,     5,     6,    -1,    -1,   466,    10,    -1,    -1,
      -1,    -1,   239,    -1,    17,    18,    19,    20,    -1,    57,
      -1,   248,    60,    61,    -1,    -1,    -1,    30,    66,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,   265,   266,
     267,   268,   269,   270,   271,   272,   273,    -1,   275,    29,
      -1,    -1,   279,    -1,    -1,    35,    -1,    -1,   285,    -1,
     287,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,   111,    -1,    11,    12,    13,    14,    -1,
     307,   308,   309,    31,    32,   312,    -1,   314,   315,   316,
     317,   318,   319,   320,   321,    31,    -1,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   144,   334,   335,    -1,
     148,    11,    12,    13,    14,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,   166,    29,
      -1,    17,    18,    19,    20,    21,    22,   175,    24,   366,
      26,    27,    -1,    -1,    30,   183,    -1,    33,    34,    11,
      12,    13,    14,    -1,    -1,   382,    -1,   384,    -1,    -1,
      -1,    11,    12,    13,    14,    -1,   204,    -1,    -1,    31,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,    29,
      10,    -1,    -1,    -1,    -1,    -1,   224,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,   239,    -1,    33,    -1,     9,    10,    11,    12,   436,
      14,    15,    16,    -1,   441,    11,    12,    13,    14,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,   456,
      -1,    -1,   459,    29,    -1,    17,    18,    19,    20,   466,
      -1,    -1,    24,    -1,    26,    27,    -1,   285,    30,    18,
      -1,    33,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,
     308,   309,    41,    -1,   312,    30,    31,    32,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    -1,
      -1,    60,    11,    12,    13,    14,    -1,   335,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      29,    80,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,   382,    33,    -1,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,   148,
      33,    -1,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,   166,   436,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,   183,    33,    -1,    -1,   456,    -1,
      -1,   459,     1,   192,     3,     4,     5,     6,   466,    -1,
      -1,    10,    -1,    -1,    -1,   204,   205,    -1,    17,    18,
      19,    20,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,    30,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
     239,    17,    18,    19,    20,    21,    22,    -1,    24,   248,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,     9,    10,
      11,    12,    13,    14,    15,    16,   265,   266,   267,   268,
     269,   270,   271,   272,   273,    -1,   275,    -1,    29,    -1,
     279,    -1,    -1,    -1,    35,    -1,   285,    -1,   287,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    18,    10,    -1,    -1,    -1,    -1,   307,   308,
      17,    18,    19,    20,    -1,   314,   315,   316,   317,   318,
     319,   320,   321,    30,    -1,   324,   325,   326,   327,   328,
     329,   330,   331,   332,    50,   334,    -1,    -1,    54,    55,
      -1,    57,    -1,    -1,    60,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    73,    -1,    75,
      76,    -1,    -1,    -1,    80,    29,    -1,   366,    -1,     0,
       1,    35,     3,     4,     5,     6,     7,     8,    18,    10,
      -1,    -1,    -1,   382,    -1,   384,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    49,
       1,    -1,     3,     4,     5,     6,    -1,    57,    -1,    10,
      60,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,    -1,   148,    -1,    74,    -1,    -1,    -1,    -1,    30,
      80,    -1,   441,    10,    11,    12,    13,    14,    15,    16,
     166,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
     459,    10,    -1,    -1,    31,    32,    -1,   183,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    -1,    -1,    -1,   204,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   148,    29,
      30,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,   239,    -1,    -1,   166,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,   183,    33,    -1,    -1,    -1,    -1,   265,
     266,   267,   268,    -1,   270,   271,    -1,   273,    -1,   275,
      -1,    -1,    -1,   279,   204,     9,    10,    11,    12,   285,
      14,    15,    16,   213,   214,   215,   216,   217,   218,   219,
      -1,    18,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,   307,   308,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     316,   317,   318,   319,   320,   321,    -1,    -1,   324,   325,
     326,   327,    -1,   329,   330,    -1,   332,    -1,   334,    -1,
      57,    -1,    -1,    60,    -1,   265,   266,   267,   268,   269,
     270,   271,    -1,   273,    -1,   275,    -1,    -1,    -1,   279,
      -1,    -1,    -1,    80,     1,   285,     3,     4,     5,     6,
     366,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    -1,    -1,   382,   307,   308,    -1,
      18,    -1,    -1,    30,    -1,   315,   316,   317,   318,   319,
     320,   321,    -1,    -1,   324,   325,   326,   327,   328,   329,
     330,    -1,   332,    -1,   334,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    53,    -1,    10,    -1,    57,
      -1,   148,    60,    -1,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    72,   441,   366,    30,    -1,   166,
       0,     1,    80,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,   382,   459,    -1,    -1,   183,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,   204,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    10,   214,   215,   216,
     217,   218,   219,    17,    18,    19,    20,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,    30,    10,    -1,    -1,
     148,   441,   239,    -1,    17,    18,    19,    20,    21,    22,
      18,    24,    -1,    26,    27,    -1,    -1,    30,   166,   459,
      33,    10,    11,    12,    13,    14,    15,    16,   265,   266,
     267,   268,    -1,   270,   271,   183,   273,    -1,   275,    -1,
      29,    -1,   279,    51,     9,    10,    11,    -1,   285,    57,
      15,    16,    60,    -1,    -1,    -1,   204,     1,    -1,     3,
       4,     5,     6,    71,    -1,    -1,    10,   215,   216,   217,
     307,   308,    80,    17,    18,    19,    20,    -1,    -1,   316,
     317,   318,   319,   320,   321,    -1,    30,   324,   325,   326,
     327,   239,   329,   330,    -1,   332,    -1,   334,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    -1,   265,   266,   267,
      17,    18,    19,    20,    -1,   273,    -1,   275,    -1,   366,
      -1,   279,    -1,    30,    -1,    -1,    -1,   285,    -1,    -1,
     148,     9,    10,    11,    12,   382,    14,    15,    16,     9,
      10,    11,    -1,    -1,    14,    15,    16,    -1,   166,   307,
     308,    -1,    -1,     1,    -1,     3,     4,     5,     6,   317,
     318,   319,    10,    -1,    -1,   183,   324,   325,   326,    17,
      18,    19,    20,    -1,   332,    -1,   334,    -1,     9,    10,
      11,    -1,    30,    14,    15,    16,   204,    -1,    -1,     9,
      10,    11,    -1,    -1,   441,    15,    16,   215,   216,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,   366,    -1,
       0,     1,   459,     3,     4,     5,     6,     7,     8,    -1,
      10,   239,    31,    32,   382,    -1,    35,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,   265,   266,     3,
       4,     5,     6,    -1,    -1,   273,    10,   275,    -1,    -1,
      -1,   279,    -1,    17,    18,    19,    20,   285,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    30,    10,    -1,    -1,
      -1,    -1,    -1,   441,    17,    18,    19,    20,    -1,   307,
     308,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,   317,
     318,   459,     9,    10,    11,    -1,   324,   325,    15,    16,
      -1,    -1,    -1,    -1,   332,    -1,   334,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,   366,    33,
      34,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,   382,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,     0,     1,    33,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   441,    -1,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,   459,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,     0,     1,    33,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,     0,     1,    33,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,     1,
      33,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,     1,    33,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,     0,     1,    33,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,     0,     1,    33,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,     0,     1,    33,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,     0,     1,    33,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,     0,     1,    33,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,     0,     1,    33,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,     0,     1,
      33,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,     0,
       1,    33,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,     1,    33,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,     1,    33,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    30,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    30,    10,
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
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    30,    10,
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
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    30,    10,
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
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    30,    10,
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
      -1,    17,    18,    19,    20,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    -1,    30,    -1,    -1,    -1,    -1,    17,
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
      20,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      30,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    35,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    35,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    35,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    35,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    35,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,
      -1,    -1,    30,    31,    32,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,     9,    10,
      11,    12,    13,    14,    15,    16,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    29,    30,     9,    10,
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
      16,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,     9,    10,    11,    12,    13,    14,    15,
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
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,     9,    10,    11,    12,
      13,    14,    15,    16,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    10,    17,
      18,    19,    20,    21,    22,    24,    26,    27,    30,    33,
      37,    38,    39,    40,    42,    48,    53,    54,    55,    56,
      57,    58,    59,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    73,    74,    75,    76,    77,     9,    10,
      11,    12,    13,    14,    15,    16,    30,    30,    23,    23,
      30,    30,     1,    59,     1,    59,    49,     0,    39,    29,
      13,    12,    14,    11,    10,    15,    16,     9,    35,    68,
      30,    29,    74,    68,     1,    67,    68,     1,    65,     1,
      63,     1,    62,     1,    64,    65,    65,     1,    74,     1,
      59,     1,    59,    59,    60,    29,    29,    31,    31,    40,
      50,    51,    52,    53,    75,     1,    62,     1,    63,     1,
      64,     1,    65,     1,    67,     1,    65,     1,    65,     1,
      68,     1,    61,    59,    71,    72,    30,    41,    31,    31,
      31,    31,    31,    31,    29,    34,    52,    74,    32,    31,
      43,    29,    29,    29,    29,    29,    48,    48,    60,    59,
      45,    46,    47,    75,    25,    25,    29,    44,    32,    74,
      48,    48,    60,    31,    47,    31,    48,    53,     3,     4,
       5,     6,    20,    30,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    73,    74,    76,    77,     6,     3,
       4,     5,     6,    20,    30,    69,    70,    73,    74,    76,
      77,     6,     9,    10,    11,    12,    13,    14,    15,    16,
       7,     8,    24,    26,    27,    33,    48,    54,    55,    56,
      57,    58,    59,     1,     3,     4,     5,     6,    20,    30,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      73,    74,    76,    77,     6,    29,    33,    41,    21,    22,
       6,     1,    59,     1,    59,    13,    12,    14,    11,    10,
      15,    16,     9,    35,    68,    30,     1,    59,    68,    30,
       3,     4,     5,     6,    20,    30,    68,    69,    70,    73,
      74,    76,    77,     1,    67,    68,     1,    65,     1,    63,
       1,    62,     1,    64,    65,    65,    30,    30,    30,    30,
       1,    59,    49,    29,     9,    10,    11,    12,    13,    14,
      15,    16,     1,    59,    13,    12,    14,    11,    10,    15,
      16,     9,    35,    68,    30,    49,    29,    23,    23,    31,
      31,     1,    62,     1,    63,     1,    64,     1,    65,     1,
      67,     1,    65,     1,    65,     1,    68,     1,    61,    72,
      31,    31,    72,     1,    59,    68,    30,     1,    74,     1,
      59,     1,    59,    60,    29,    29,    50,     3,     4,     5,
       6,    20,    30,    68,    69,    70,    73,    74,    76,    77,
       1,    67,    68,     1,    65,     1,    63,     1,    62,     1,
      64,    65,    65,    31,    31,     1,    62,     1,    63,     1,
      64,     1,    65,     1,    67,     1,    65,     1,    65,     1,
      68,     1,    61,    72,    50,    31,    31,    31,    31,    72,
      31,    31,    31,    31,    31,    31,    29,    34,     1,    59,
      68,    30,    31,    34,    31,    29,    29,    29,    29,    33,
      48,    48,    60,    31,    31,    72,    49,    25,    25,    29,
      31,    50,    48,    48,    60,    34,    31,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    39,    41,
      40,    40,    43,    44,    42,    45,    45,    46,    46,    47,
      49,    48,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    55,    56,
      56,    56,    56,    57,    57,    58,    59,    59,    59,    60,
      60,    61,    61,    61,    61,    62,    62,    62,    62,    63,
      63,    63,    63,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    66,    66,    66,    66,    67,    67,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    73,    74,
      75,    75,    75,    75,    76,    76,    76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     0,
       4,     2,     0,     0,     8,     0,     1,     3,     1,     2,
       0,     4,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     5,     5,     2,     5,
       7,     5,     7,     3,     3,     9,     1,     3,     3,     0,
       1,     1,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     4,
       1,     3,     1,     0,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     2,     1,     1,     1,     1
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
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3094 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3100 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3106 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3112 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3118 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3124 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3130 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3136 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3142 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3148 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3154 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3160 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3166 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3172 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3178 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3184 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3190 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3196 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3202 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3208 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_1: /* @1  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3214 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3220 "src/bison/grammar.c"
        break;

    case YYSYMBOL_43_2: /* @2  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3226 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3232 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3238 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3244 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3250 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3256 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3262 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3268 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3274 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3280 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3286 "src/bison/grammar.c"
        break;

    case YYSYMBOL_60_expression_opt: /* expression.opt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3292 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3298 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3304 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3310 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3316 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3322 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3328 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3334 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3340 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3346 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3352 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3358 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3364 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3370 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3376 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3382 "src/bison/grammar.c"
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
#line 130 "src/bison/grammar.y"
             { show_error((yyloc), "ISO C-IPL forbids an empty translation unit\n"); }
#line 3691 "src/bison/grammar.c"
    break;

  case 4: /* external_declaration_list: external_declaration_list external_declaration  */
#line 133 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 3697 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration  */
#line 134 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 3703 "src/bison/grammar.c"
    break;

  case 8: /* external_declaration: statement  */
#line 139 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[0].ast));
    }
#line 3713 "src/bison/grammar.c"
    break;

  case 9: /* @1: %empty  */
#line 146 "src/bison/grammar.y"
                              {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-1].pchar));
        if (sym) {
            if (sym->scope) {
                show_error_range((yylsp[0]), "redeclaration of " BCYN "'%s'\n" RESET, (yyvsp[0].sym)->name);
            } else if (sym->is_fn) {
                show_error_range((yylsp[0]), BBLU "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[0].sym)->name);
            } else if (sym->type != decl_type) {
                show_error_range((yylsp[-1]), "conflicting types for " BCYN "'%s'\n" RESET, (yyvsp[0].sym)->name);
            }
            (yyval.ast) = NULL;
        }
        else {
            symbol_update_type((yyvsp[0].sym), decl_type);
            (yyval.ast) = ast_symref_init(context_declare_variable(current_context, (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 3738 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type id @1 ';'  */
#line 165 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 3746 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 168 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
    }
#line 3756 "src/bison/grammar.c"
    break;

  case 12: /* @2: %empty  */
#line 175 "src/bison/grammar.y"
                                   {
        p_ctx_name = true;
        Symbol *sym = context_has_symbol(current_context, (yyvsp[-1].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-2].pchar));

        // always push a context for the function even if not valid so is possible to pop later
        previous_context = current_context;
        list_push(&contexts, context_init((yyvsp[-1].sym)->name));
        current_context = list_peek_last(&contexts);

        if (sym) {
            if (!sym->is_fn) {
                show_error((yylsp[-1]), BCYN "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
            } else if (sym->type != decl_type) {
                show_error((yylsp[-2]), "conflicting types for " BBLU "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            } else {
                show_error((yylsp[-1]), "redefinition of " BBLU "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            }
            (yyval.ast) = NULL;
        } else {
            symbol_update_type((yyvsp[-1].sym), decl_type);
            Symbol *declared = context_declare_function(previous_context, (yyvsp[-1].sym));
            if (!declared) {
                show_error((yylsp[-1]), BCYN "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
                (yyval.ast) = NULL;
            } else {
                (yyval.ast) = ast_symref_init(declared);
            }
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 3797 "src/bison/grammar.c"
    break;

  case 13: /* $@3: %empty  */
#line 210 "src/bison/grammar.y"
                     {
        is_fn_blck = true;
    }
#line 3805 "src/bison/grammar.c"
    break;

  case 14: /* func_declaration: type id '(' @2 param_list.opt $@3 ')' compound_stmt  */
#line 212 "src/bison/grammar.y"
                        {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 3815 "src/bison/grammar.c"
    break;

  case 15: /* param_list.opt: %empty  */
#line 219 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 3821 "src/bison/grammar.c"
    break;

  case 17: /* params_list: params_list ',' param_decl  */
#line 223 "src/bison/grammar.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3827 "src/bison/grammar.c"
    break;

  case 18: /* params_list: param_decl  */
#line 224 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3833 "src/bison/grammar.c"
    break;

  case 19: /* param_decl: type id  */
#line 227 "src/bison/grammar.y"
                    {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        if (sym) {
            show_error_range((yylsp[0]), "redefinition of parameter " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            symbol_update_type((yyvsp[0].sym), symbol_type_from_str((yyvsp[-1].pchar)));
            (yyval.ast) = ast_symref_init(context_declare_variable(current_context, (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 3850 "src/bison/grammar.c"
    break;

  case 20: /* $@4: %empty  */
#line 241 "src/bison/grammar.y"
                   {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        // hack to update the current scope
        if (!is_fn_blck) context_push_scope(current_context);
        is_fn_blck = false;
    }
#line 3861 "src/bison/grammar.c"
    break;

  case 21: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 246 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 3873 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list.opt: block_item_list  */
#line 255 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 3879 "src/bison/grammar.c"
    break;

  case 23: /* block_item_list.opt: %empty  */
#line 256 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3885 "src/bison/grammar.c"
    break;

  case 24: /* block_item_list: block_item_list block_item  */
#line 259 "src/bison/grammar.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3891 "src/bison/grammar.c"
    break;

  case 25: /* block_item_list: block_item  */
#line 260 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3897 "src/bison/grammar.c"
    break;

  case 34: /* io_stmt: READ '(' id ')' ';'  */
#line 275 "src/bison/grammar.y"
                             {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(func), ast_symref_init(param));
        symbol_free((yyvsp[-4].sym));
        symbol_free((yyvsp[-2].sym));
    }
#line 3909 "src/bison/grammar.c"
    break;

  case 35: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 282 "src/bison/grammar.y"
                                   {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(func), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 3919 "src/bison/grammar.c"
    break;

  case 36: /* io_stmt: WRITE '(' error ')' ';'  */
#line 287 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
        symbol_free((yyvsp[-4].sym));
    }
#line 3929 "src/bison/grammar.c"
    break;

  case 37: /* io_stmt: READ '(' error ')' ';'  */
#line 292 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
        symbol_free((yyvsp[-4].sym));
    }
#line 3939 "src/bison/grammar.c"
    break;

  case 38: /* expr_stmt: expression ';'  */
#line 299 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 3945 "src/bison/grammar.c"
    break;

  case 39: /* cond_stmt: IF '(' expression ')' compound_stmt  */
#line 302 "src/bison/grammar.y"
                                                          {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 3953 "src/bison/grammar.c"
    break;

  case 40: /* cond_stmt: IF '(' expression ')' compound_stmt ELSE compound_stmt  */
#line 305 "src/bison/grammar.y"
                                                             {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3961 "src/bison/grammar.c"
    break;

  case 41: /* cond_stmt: IF '(' error ')' compound_stmt  */
#line 308 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[0].ast));
        yyerrok;
    }
#line 3972 "src/bison/grammar.c"
    break;

  case 42: /* cond_stmt: IF '(' error ')' compound_stmt ELSE compound_stmt  */
#line 314 "src/bison/grammar.y"
                                                        {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        yyerrok;
    }
#line 3984 "src/bison/grammar.c"
    break;

  case 43: /* jmp_stmt: RETURN expression ';'  */
#line 323 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 3990 "src/bison/grammar.c"
    break;

  case 44: /* jmp_stmt: RETURN error ';'  */
#line 324 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-2]), WHT "'return'" RESET " with no value\n");
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 4000 "src/bison/grammar.c"
    break;

  case 45: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 331 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4008 "src/bison/grammar.c"
    break;

  case 47: /* expression: unary_expr '=' logical_or_expr  */
#line 337 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 4014 "src/bison/grammar.c"
    break;

  case 48: /* expression: unary_expr '=' error  */
#line 338 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4024 "src/bison/grammar.c"
    break;

  case 49: /* expression.opt: %empty  */
#line 345 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 4030 "src/bison/grammar.c"
    break;

  case 52: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 350 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4039 "src/bison/grammar.c"
    break;

  case 53: /* logical_or_expr: logical_or_expr OR error  */
#line 354 "src/bison/grammar.y"
                               {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4049 "src/bison/grammar.c"
    break;

  case 54: /* logical_or_expr: error OR logical_and_expr  */
#line 359 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4059 "src/bison/grammar.c"
    break;

  case 56: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 367 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4068 "src/bison/grammar.c"
    break;

  case 57: /* logical_and_expr: logical_and_expr AND error  */
#line 371 "src/bison/grammar.y"
                                 {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4078 "src/bison/grammar.c"
    break;

  case 58: /* logical_and_expr: error AND eq_expr  */
#line 376 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4088 "src/bison/grammar.c"
    break;

  case 60: /* eq_expr: eq_expr EQ rel_expr  */
#line 384 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4097 "src/bison/grammar.c"
    break;

  case 61: /* eq_expr: eq_expr EQ error  */
#line 388 "src/bison/grammar.y"
                       {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4107 "src/bison/grammar.c"
    break;

  case 62: /* eq_expr: error EQ rel_expr  */
#line 393 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4117 "src/bison/grammar.c"
    break;

  case 64: /* rel_expr: rel_expr REL list_expr  */
#line 401 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4126 "src/bison/grammar.c"
    break;

  case 65: /* rel_expr: rel_expr REL error  */
#line 405 "src/bison/grammar.y"
                         {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4136 "src/bison/grammar.c"
    break;

  case 66: /* rel_expr: error REL list_expr  */
#line 410 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4146 "src/bison/grammar.c"
    break;

  case 68: /* list_expr: add_expr DL_DG list_expr  */
#line 418 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4155 "src/bison/grammar.c"
    break;

  case 69: /* list_expr: add_expr COLON list_expr  */
#line 422 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4164 "src/bison/grammar.c"
    break;

  case 70: /* list_expr: add_expr DL_DG error  */
#line 426 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4174 "src/bison/grammar.c"
    break;

  case 71: /* list_expr: add_expr COLON error  */
#line 431 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4184 "src/bison/grammar.c"
    break;

  case 72: /* list_expr: error DL_DG list_expr  */
#line 436 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4194 "src/bison/grammar.c"
    break;

  case 73: /* list_expr: error COLON list_expr  */
#line 441 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4204 "src/bison/grammar.c"
    break;

  case 75: /* add_expr: add_expr ADD mult_expr  */
#line 449 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4213 "src/bison/grammar.c"
    break;

  case 76: /* add_expr: add_expr ADD error  */
#line 453 "src/bison/grammar.y"
                         {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4223 "src/bison/grammar.c"
    break;

  case 77: /* add_expr: error ADD mult_expr  */
#line 458 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4233 "src/bison/grammar.c"
    break;

  case 79: /* mult_expr: mult_expr MULT unary_expr  */
#line 466 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4242 "src/bison/grammar.c"
    break;

  case 80: /* mult_expr: mult_expr MULT error  */
#line 470 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4252 "src/bison/grammar.c"
    break;

  case 81: /* mult_expr: error MULT unary_expr  */
#line 475 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4262 "src/bison/grammar.c"
    break;

  case 83: /* unary_expr: unary_ops unary_expr  */
#line 483 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4271 "src/bison/grammar.c"
    break;

  case 89: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 496 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-3].sym));
        AST *params = ast_params_init((yyvsp[-1].list));
        if (!sym) {
            show_error_range((yylsp[-3]), "implicit declaration of function " BBLU "'%s'\n" RESET, (yyvsp[-3].sym)->name);
            (yyval.ast) = NULL;
            ast_free(params);
        } else {
            if (!sym->is_fn) {
                show_error_range((yylsp[-3]), "called object " BCYN "'%s'" RESET " is not a function\n", sym->name);
                (yyval.ast) = NULL;
                ast_free(params);
            } else {
                (yyval.ast) = ast_funcall_init(ast_symref_init(sym), params);
            }
        }
        symbol_free((yyvsp[-3].sym));
    }
#line 4294 "src/bison/grammar.c"
    break;

  case 90: /* arg_expr_list: expression  */
#line 516 "src/bison/grammar.y"
                          { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4300 "src/bison/grammar.c"
    break;

  case 91: /* arg_expr_list: arg_expr_list ',' expression  */
#line 517 "src/bison/grammar.y"
                                   { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 4306 "src/bison/grammar.c"
    break;

  case 93: /* arg_expr_list.opt: %empty  */
#line 521 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4312 "src/bison/grammar.c"
    break;

  case 94: /* primary_expr: id  */
#line 524 "src/bison/grammar.y"
                 {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[0].sym));
        if (!sym) {
            show_error_range((yylsp[0]), BCYN "'%s'" RESET " undeclared (first use in this function)\n", (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            (yyval.ast) = ast_symref_init(sym);
        }
        symbol_free((yyvsp[0].sym));
    }
#line 4327 "src/bison/grammar.c"
    break;

  case 97: /* primary_expr: '(' expression ')'  */
#line 536 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 4333 "src/bison/grammar.c"
    break;

  case 98: /* primary_expr: '(' error ')'  */
#line 537 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 4342 "src/bison/grammar.c"
    break;

  case 102: /* type: INT LIST  */
#line 548 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 4354 "src/bison/grammar.c"
    break;

  case 103: /* type: FLOAT LIST  */
#line 555 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 4366 "src/bison/grammar.c"
    break;

  case 104: /* constant: NUMBER_REAL  */
#line 564 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 4372 "src/bison/grammar.c"
    break;

  case 105: /* constant: NUMBER_INT  */
#line 565 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 4378 "src/bison/grammar.c"
    break;

  case 106: /* constant: NIL  */
#line 566 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 4384 "src/bison/grammar.c"
    break;

  case 107: /* string_literal: STR_LITERAL  */
#line 569 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 4393 "src/bison/grammar.c"
    break;


#line 4397 "src/bison/grammar.c"

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

#line 575 "src/bison/grammar.y"


void yyerror(int l, int c, const char *s, ...) {
    error_cursor = (Cursor){.line=l, .col=c};
    last_line_ref = curr_line_buffer;
    // enable error print when bison calls yyerror()
    /* if (s) {
        CIPL_PRINTF_COLOR(BRED, "%s\n", s);
        CIPL_PRINTF_COLOR(BYEL, "%d:%d: at line: %s\n", error_cursor.line, error_cursor.col, last_line_ref);
    } */
    // prevent count up errors when bison calls yyerror()
    if (!s) {
        ++errors_count;
    }
}
