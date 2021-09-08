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
    Cursor error_cursor;
    Context *current_context;
    Context *previous_context;
    Scope *params_scope;
    StackNode *parent_stacknode_ref;
    char *last_line_ref;
    int p_ctx_name = 1;

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
            p_ctx_name = 0;                                                          \
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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6528

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  441

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
     146,   169,   176,   211,   176,   222,   223,   226,   227,   230,
     246,   246,   265,   266,   269,   270,   273,   274,   277,   278,
     279,   280,   281,   282,   285,   292,   299,   302,   305,   308,
     314,   323,   324,   331,   336,   337,   340,   341,   344,   345,
     349,   354,   361,   362,   366,   371,   378,   379,   383,   388,
     395,   396,   400,   405,   412,   413,   417,   421,   426,   431,
     436,   443,   444,   448,   453,   460,   461,   465,   470,   477,
     478,   484,   485,   486,   487,   490,   491,   508,   509,   512,
     513,   516,   527,   528,   529,   532,   535,   536,   537,   544,
     553,   554,   555,   558
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

#define YYPACT_NINF (-266)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-104)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     623,  1916,   832,  1129,  1426,  2899,   -16,   -11,   700,   997,
    1294,  1591,  1723,     9,    10,    16,    48,   810,  1107,   660,
      37,   737,   779,   920,   958,  1034,  1076,  1217,  1255,  1331,
    1373,  1514,    88,    62,    93,   238,   299,   710,  2874,   593,
    5022,  4665,  5049,  5057,  4767,    14,  5084,  5092,  4683,  1404,
    1855,  2055,  2076,  2282,  1855,  1855,   117,  1107,    18,    24,
    2526,  1684,   890,    99,   107,  1551,  -266,  1811,  1976,  2554,
    2741,  3870,  3891,  3912,  3933,  3954,  3975,  3996,  5119,   216,
    2017,    47,  1187,   144,  1484,  1781,   809,   881,  1696,   662,
    1944,    96,    39,   960,  1007,  1178,   125,   129,  5747,   134,
     147,   149,  2328,  2586,  5127,  2779,   153,  2830,  2936,  2972,
      30,  6188,   312,  6209,   720,  6217,  1257,  6238,  1304,  6246,
    6267,  6275,  1475,  6296,  1772,  6304,  6325,   113,   166,   182,
     163,   406,   170,   198,   208,   231,   231,  1684,  3007,  3040,
     237,  4017,  5154,   434,  3075,  3106,  3137,    63,    94,   247,
     193,   264,   222,   242,   310,   268,   268,   513,   270,   353,
     346,  3168,  3199,   274,   268,   399,  1629,  3230,  3261,  2805,
    2306,  5162,  5189,  4777,  5197,  1107,    31,   127,   286,   448,
     471,   535,  5755,  5224,  4701,  5232,  5259,  4804,  5267,  5294,
     412,  6333,  6354,  6362,  6158,  6383,  1107,  4683,  6391,  6412,
    6180,  6420,  6441,   304,   307,   319,   325,   335,  4038,   660,
    3292,  3326,  3360,  3394,  3428,  3462,   313,  6507,  4812,  4839,
    4847,   120,  4874,  1107,   378,   131,  1060,   169,   217,   761,
    2444,  4882,  4719,  4909,  4917,  2088,  4944,  4952,  4737,  4059,
    4080,  4101,  4122,  4143,  4080,  4080,   343,  3496,   660,   350,
      29,    80,   426,   355,   361,  4164,  4185,  4206,  4227,  4248,
    4269,  4290,  4311,  4332,  5302,   216,   381,  6449,   216,   117,
    1107,  4353,  1684,  6470,   395,  1551,  3530,  4755,  4374,  4395,
    4416,  4437,  4458,  4395,  4395,   402,  4479,  4500,  4521,  4542,
    4563,  4584,  4605,  4626,  4647,  4979,   216,  5778,  5786,  5809,
     497,  5817,  1107,  5840,  4737,  5848,  5871,  5724,  5879,  5902,
     444,  5910,  5933,  1015,  1199,  2098,   295,  2567,   551,  1603,
    1278,  1354,  1496,  1551,  3564,   458,   463,  5329,  5941,   626,
    5964,   583,  5972,  1575,  5995,  1664,  6003,  6026,  6034,  1685,
    6057,  1793,  6065,  6088,    61,   439,  6478,   455,   467,   468,
    6096,   484,   472,  3598,  3632,   487,  2688,  5364,  5372,   436,
    5396,  1107,  5404,  4755,  5428,  5436,  2364,  5460,  5468,   515,
    5492,  5500,  1106,   308,  2215,  1357,  2858,   382,  1882,   387,
     394,   605,  4987,  5524,   404,  5532,  1838,  5556,   684,  5564,
     902,  5588,  5596,  5620,   981,  5628,  1057,  5652,  5660,   389,
     491,   494,  6119,   216,   492,  5337,  6499,   505,   532,   537,
     537,  1684,  3666,   540,  5684,   216,  5014,  6127,   542,   185,
    3700,  3734,   660,   326,   363,   563,  5692,   567,  6150,  1551,
     577,   577,   513,  5716,   566,  3768,  3802,   582,   470,  2242,
    3836
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
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
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
       0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -266,  -266,  -266,   600,    51,   485,  -266,  -266,  -266,  -266,
    -266,   473,    13,  -206,  -265,  -266,   527,     1,     4,     5,
       6,     7,     8,  1782,  -126,  1969,  1613,  2636,  2468,  2148,
    2392,  2224,  1892,   297,   594,  -266,  -256,   891,     0,     2,
    1188,  1485
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    20,    21,    22,   105,   132,    24,   143,   164,   151,
     152,   153,   210,    65,   106,   107,   108,   109,   211,   212,
     213,   214,   215,   128,   101,    33,    34,    35,    36,    37,
      38,    39,    40,   197,   198,   129,   130,   199,   200,   110,
     201,   202
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    26,    45,   275,    27,    28,    29,    30,    31,   345,
     355,   149,   347,    25,    56,   -96,   -97,    44,   187,    57,
     190,    44,    26,    45,   -98,    27,    28,    29,    30,    31,
     -99,   163,    58,    59,    25,   -96,   246,    66,   -96,   -97,
     400,    44,   323,    80,   255,    81,    60,   -98,    48,    49,
      50,    23,   325,   -99,    54,    55,    96,   187,   404,   247,
     187,    44,   -44,   -39,   -39,    44,   -39,   -39,   -39,   -39,
     -39,   -39,    23,   -39,   255,    69,    -9,   131,    61,   235,
     -39,   -39,   -39,   -39,   -39,   -39,   -97,   -39,   155,   -39,
     -39,   -44,   -45,   -39,   -37,   -37,   -39,   -37,   -37,   -37,
     -37,   -37,   -37,   326,   -37,    70,   -48,    44,    70,   -51,
     140,   -37,   -37,   -37,   -37,   -37,   -37,    68,   -37,   156,
     -37,   -37,   -48,   203,   -37,   -51,    69,   -37,   103,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,    44,   104,   256,
     -48,   235,   -45,   287,   -48,   154,   352,   418,   147,   148,
     -95,   -95,   -95,    48,   160,   -95,   133,   187,   -48,   427,
     134,   154,   -48,   -48,   434,   136,    44,   168,   161,   162,
      27,    28,    29,    30,    31,   187,   -47,   167,   137,    25,
     289,   -56,   -56,   -56,   187,   -21,   -21,   138,   -21,   -21,
     -21,   -21,   -21,   -21,   142,   -21,   187,   -87,   -87,   144,
     -56,   -56,   -21,   -21,   -21,   -21,   -21,   -21,    44,   -21,
     -21,   -21,   -21,   -89,   141,   -21,   429,   217,   -21,   218,
     219,   220,   221,   187,   -88,   -88,     8,   145,   -60,   -60,
     -60,   -60,   235,     9,    10,    11,   222,   146,   307,   307,
     307,   307,   307,   307,   307,   307,   223,   -90,   -60,   -60,
     -52,   -52,    71,   -16,   159,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   248,   235,    -9,   -52,   235,   348,
     187,   187,    44,   -18,   -18,    44,   157,   366,   366,   366,
     366,   366,   366,   366,   366,   425,   366,   366,   366,   366,
     366,   366,   366,   366,   366,   158,   235,    41,   -52,   -52,
     257,    19,   187,   -13,   307,   166,   437,   -55,   -55,   257,
      72,   -56,   -56,   -56,    41,   184,   252,   -52,    41,   -63,
     -63,   -63,   -63,    44,    70,   -49,   -55,   -39,   -56,   -39,
     -39,   -39,   -39,   -39,   -39,   -95,   -39,   269,    41,   -63,
     -63,   -49,   276,   -39,   -39,   -39,   -39,   -39,   -39,   270,
     -39,   430,   -39,   -39,   184,   271,   -39,   184,    41,   -39,
     -39,   187,    41,   366,   -37,   272,   -37,   -37,   -37,   -37,
     -37,   -37,   -95,   -37,   250,   251,   232,   -19,   -19,   324,
     -37,   -37,   -37,   -37,   -37,   -37,   -47,   -37,   431,   -37,
     -37,   286,   327,   -37,   287,   -51,   -37,   -37,   289,   -59,
     -59,   -59,   286,   235,    41,   -70,   -70,   -70,   -70,   -44,
     -44,    44,   346,   -51,   -51,   235,   287,   -49,   -59,   -59,
     -45,   -45,   423,   424,   354,   -70,   -70,   -12,   -12,    44,
     -17,   -17,   187,   382,    41,   -49,   -49,   -12,   232,    44,
     440,   -95,   -95,   435,   436,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   238,   184,   250,   251,   -95,   -95,   258,
     -56,   -56,   -56,    41,   -98,   -15,   -95,   -95,   -95,   -99,
     405,   -21,   184,   -21,   -21,   -21,   -21,   -21,   -21,   -56,
     -21,   184,   -60,   -60,   -60,   -60,   406,   -21,   -21,   -21,
     -21,   -21,   -21,   184,   -21,   -21,   -21,   -21,   407,   408,
     -21,   411,   -60,   -21,   -21,    41,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   169,   410,   170,   171,   172,   173,
     184,   412,   416,     8,   277,   417,   419,   -95,   -95,   232,
       9,    10,    11,   174,   420,   304,   304,   304,   304,   304,
     304,   304,   304,   175,   -46,   259,   -64,   -64,   -64,   -64,
     260,   261,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   421,   232,   256,   -51,   232,   -64,   184,   184,    41,
     422,   426,    41,   428,   363,   363,   363,   363,   363,   363,
     363,   363,   -51,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   432,   232,    42,   -53,   -53,   257,   433,   184,
     438,   304,    76,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     209,    42,   185,   439,   -53,    42,   -69,   -69,   -69,   -69,
      41,    67,   -71,    -3,     1,   249,     2,     3,     4,     5,
       6,     7,   165,     8,   139,    42,   -69,   -69,   256,   -49,
       9,    10,    11,    12,    13,    14,     0,    15,     0,    16,
      17,   185,     0,    18,   185,    42,    19,   -49,   184,    42,
     363,   -20,     0,   -20,   -20,   -20,   -20,   -20,   -20,     0,
     -20,     0,     0,   233,   -55,   -55,    71,   -20,   -20,   -20,
     -20,   -20,   -20,     0,   -20,     0,   -20,   -20,     0,     0,
     -20,   -55,     0,   -20,   -20,   289,   -57,   -57,   -57,     0,
     232,    42,     0,   -83,   -83,   -83,   -83,     0,    41,     0,
     -83,     0,   232,     0,     0,   -57,   -57,   -83,   -83,   -83,
     -83,   -60,   -60,   -60,   -60,     0,    41,     0,     0,   184,
     -83,    42,   -53,   -53,    71,   233,    41,    -2,     1,   -60,
       2,     3,     4,     5,     6,     7,     0,     8,     0,   -53,
       0,   185,     0,     0,     9,    10,    11,    12,    13,    14,
      42,    15,     0,    16,    17,     0,     0,    18,     0,   185,
      19,   290,   -64,   -64,   -64,   -64,   291,   292,   185,    -5,
      -5,     0,    -5,    -5,    -5,    -5,    -5,    -5,     0,    -5,
     185,     0,   -64,   -64,     0,     0,    -5,    -5,    -5,    -5,
      -5,    -5,    42,    -5,     0,    -5,    -5,     0,     0,    -5,
       0,    62,    -5,     2,     3,     4,     5,   185,    48,    49,
       8,     0,     0,     0,    54,    55,   233,     9,    10,    11,
      12,     0,   305,   305,   305,   305,   305,   305,   305,   305,
      18,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,   305,
     305,   305,   305,   305,   305,   305,   305,   305,     0,   233,
       0,  -101,   233,     0,   185,   185,    42,  -101,     0,    42,
       0,   364,   364,   364,   364,   364,   364,   364,   364,     0,
     364,   364,   364,   364,   364,   364,   364,   364,   364,     0,
     233,    43,   -63,   -63,   -63,   -63,   185,     0,   305,    48,
      49,    50,    51,    52,    53,    54,    55,     0,    43,   186,
     -63,     0,    43,   -61,   -61,   -61,   -61,    42,     0,   102,
      -7,    -7,     0,    -7,    -7,    -7,    -7,    -7,    -7,     0,
      -7,     0,    43,   -61,   -61,     0,     0,    -7,    -7,    -7,
      -7,    -7,    -7,     0,    -7,     0,    -7,    -7,   186,     0,
      -7,   186,    43,    -7,     0,   185,    43,   364,    -6,    -6,
       0,    -6,    -6,    -6,    -6,    -6,    -6,     0,    -6,     0,
     234,    72,   -59,   -59,   -59,    -6,    -6,    -6,    -6,    -6,
      -6,     0,    -6,     0,    -6,    -6,     0,     0,    -6,   -59,
       0,    -6,   -66,   -66,   -66,   -66,     0,   233,    43,     0,
     -81,   -81,   -81,   -81,     0,    42,     0,   -81,     0,   233,
       0,     0,   -66,   -66,   -81,   -81,   -81,   -81,   -70,   -70,
     -70,   -70,     0,    42,   238,   239,   185,   -81,    43,     0,
     244,   245,   234,    42,   -29,   -29,   -70,   -29,   -29,   -29,
     -29,   -29,   -29,     0,   -29,     0,     0,     0,   186,     0,
       0,   -29,   -29,   -29,   -29,   -29,   -29,    43,   -29,     0,
     -29,   -29,     0,     0,   -29,     0,   186,   -29,   -65,   -65,
     -65,   -65,   -52,   -52,   288,   186,    -8,    -8,     0,    -8,
      -8,    -8,    -8,    -8,    -8,     0,    -8,   186,   -65,   -65,
       0,   -52,   -52,    -8,    -8,    -8,    -8,    -8,    -8,    43,
      -8,     0,    -8,    -8,     0,     0,    -8,     0,   169,    -8,
     170,   171,   172,   173,   186,   277,   278,     8,     0,     0,
       0,   283,   284,   234,     9,    10,    11,   174,     0,   306,
     306,   306,   306,   306,   306,   306,   306,   175,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,   306,   306,   306,   306,
     306,   306,   306,   306,   306,     0,   234,     0,  -102,   234,
       0,   186,   186,    43,  -102,     0,    43,     0,   365,   365,
     365,   365,   365,   365,   365,   365,     0,   365,   365,   365,
     365,   365,   365,   365,   365,   365,     0,   234,    46,   -69,
     -69,   -69,   -69,   186,     0,   306,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,     0,    46,   188,   -69,     0,    46,
     -63,   -63,   -63,   -63,    43,     0,   -78,   -33,   -33,     0,
     -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,     0,    46,
     -63,     0,     0,     0,   -33,   -33,   -33,   -33,   -33,   -33,
       0,   -33,     0,   -33,   -33,   188,     0,   -33,   188,    46,
     -33,     0,   186,    46,   365,   -28,   -28,     0,   -28,   -28,
     -28,   -28,   -28,   -28,     0,   -28,     0,   236,    72,   -57,
     -57,   -57,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,
       0,   -28,   -28,     0,     0,   -28,   -57,     0,   -28,   258,
     -59,   -59,   -59,     0,   234,    46,     0,   -82,   -82,   -82,
     -82,     0,    43,     0,   -82,     0,   234,     0,     0,   -59,
       0,   -82,   -82,   -82,   -82,   -61,   -61,   -61,   -61,     0,
      43,     0,     0,   186,   -82,    46,     0,     0,     0,   236,
      43,   -30,   -30,   -61,   -30,   -30,   -30,   -30,   -30,   -30,
       0,   -30,     0,     0,     0,   188,     0,     0,   -30,   -30,
     -30,   -30,   -30,   -30,    46,   -30,     0,   -30,   -30,     0,
       0,   -30,     0,   188,   -30,   -70,   -70,   -70,   -70,   -55,
     -55,   288,   188,   -31,   -31,     0,   -31,   -31,   -31,   -31,
     -31,   -31,     0,   -31,   188,   -70,     0,     0,   -55,   -55,
     -31,   -31,   -31,   -31,   -31,   -31,    46,   -31,     0,   -31,
     -31,     0,     0,   -31,     0,    83,   -31,   191,   192,   193,
     194,   188,     0,     0,     8,     0,     0,     0,     0,     0,
     236,     9,    10,    11,   195,     0,   308,   308,   308,   308,
     308,   308,   308,   308,   196,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,   308,   308,   308,   308,   308,   308,   308,
     308,   308,     0,   236,     0,  -100,   236,     0,   188,   188,
      46,  -100,     0,    46,     0,   367,   367,   367,   367,   367,
     367,   367,   367,     0,   367,   367,   367,   367,   367,   367,
     367,   367,   367,     0,   236,    47,   -66,   -66,   -66,   -66,
     188,     0,   308,    76,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     0,    47,   189,   -66,     0,    47,   -69,   -69,   -69,
     -69,    46,     0,   -74,   -32,   -32,     0,   -32,   -32,   -32,
     -32,   -32,   -32,     0,   -32,     0,    47,   -69,     0,     0,
       0,   -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,     0,
     -32,   -32,   189,     0,   -32,   189,    47,   -32,     0,   188,
      47,   367,     1,     0,     2,     3,     4,     5,   204,   205,
       0,     8,     0,     0,   237,     0,     0,     0,     9,    10,
      11,    12,    13,    14,     0,   206,     0,   207,   208,     0,
       0,    18,     0,     0,   209,   -23,   258,   -57,   -57,   -57,
       0,   236,    47,     0,   -84,   -84,   -84,   -84,     0,    46,
       0,   -84,     0,   236,     0,     0,   -57,     0,   -84,   -84,
     -84,   -84,   238,   239,   240,     0,     0,    46,   244,   245,
     188,   -84,    47,     0,     0,     0,   237,    46,     0,     0,
       1,   177,     2,     3,     4,     5,     6,     7,     0,     8,
       0,     0,   189,     0,     0,     0,     9,    10,    11,    12,
       0,    47,     0,    15,     0,    16,    17,     0,     0,    18,
     189,     0,    19,     0,     0,    91,     0,     0,     0,   189,
     177,     0,     0,   177,     0,   -61,   -61,   -61,   -61,     0,
       0,   189,   112,     0,     0,     1,     0,     2,     3,     4,
       5,     0,   225,    47,     8,   -61,   -66,   -66,   -66,   -66,
       0,     9,    10,    11,    12,    48,    49,    50,   189,     0,
      53,    54,    55,   -46,    18,     0,   -66,   237,     0,     0,
       0,     0,     0,   309,   309,   309,   309,   309,   309,   309,
     309,     0,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
     309,   309,   309,   309,   309,   309,   309,   309,   309,     0,
     237,     0,  -103,   237,   225,   189,   189,    47,  -103,     0,
      47,     0,   368,   368,   368,   368,   368,   368,   368,   368,
     177,   368,   368,   368,   368,   368,   368,   368,   368,   368,
       0,   237,    32,   -65,   -65,   -65,   -65,   189,   177,   309,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,    63,
      64,   -65,     0,    32,   -65,   -65,   -65,   -65,    47,   177,
     -75,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,     0,     0,   -65,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,   177,    -4,    -4,    97,
       0,    -4,    99,   100,    -4,     0,   189,   216,   368,     0,
     -53,   -53,   288,     0,     0,   318,    86,     0,   191,   192,
     193,   194,     0,     0,     0,     8,     0,     0,   329,   -53,
     -53,     0,     9,    10,    11,   195,   177,     0,   225,     0,
       0,   225,     0,   177,   177,   196,     0,     0,   237,   216,
       0,   277,   278,   279,   377,     0,    47,   283,   284,   384,
     237,     0,     0,     0,     0,     0,     0,   225,     0,   225,
     183,     0,     0,     0,    47,   177,     0,   189,     0,   100,
       0,     0,     0,   150,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    78,     0,     0,     0,     0,     0,   253,
      82,    85,    85,    85,    85,    85,    85,    85,    32,   183,
       0,     0,   183,    48,    49,    50,    51,   254,    53,    54,
      55,    85,    85,    85,    85,    85,    85,    85,   126,    85,
       0,   231,     0,     0,   177,     0,   -36,   -36,   266,   -36,
     -36,   -36,   -36,   -36,   -36,     0,   -36,   176,     0,     0,
     274,     0,     0,   -36,   -36,   -36,   -36,   -36,   -36,     0,
     -36,     0,   -36,   -36,     0,   285,   -36,     0,     0,   -36,
       0,     0,     0,     0,     0,     0,   225,   -11,   -11,     0,
     -11,   -11,   -11,   -11,   -11,   -11,   176,   -11,   225,   176,
       0,     0,     0,   231,   -11,   -11,   -11,   -11,   -11,   -11,
       0,   -11,     0,   -11,   -11,   177,   127,   -11,   224,   183,
     -11,     0,   349,   351,   100,     0,    88,   216,   191,   192,
     193,   194,     0,     0,     0,     8,     0,   183,     0,     0,
       0,     0,     9,    10,    11,   195,   264,    90,     0,   191,
     192,   193,   194,     0,   401,   196,     8,     0,   183,   267,
       0,     0,     0,     9,    10,    11,   195,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   216,   196,   238,   239,   240,
     224,     0,   243,   244,   245,   183,     0,     0,   296,   -91,
     -91,     0,     0,   -91,   295,     0,   176,     0,     0,     0,
     303,   312,   312,   312,   312,   312,   312,   312,     0,     0,
       0,     0,     0,   413,   176,     0,     0,   312,   312,   312,
     312,   312,   312,   312,   343,   312,     0,   231,     0,     0,
     231,     0,   183,   183,     0,   176,   180,     0,     0,   362,
     371,   371,   371,   371,   371,   371,   371,     0,   371,   371,
     371,   371,   371,   371,   371,   398,   371,     0,   231,     0,
       0,     0,   176,   100,   183,     0,   402,     0,    87,     0,
       0,     0,    94,    95,     0,   180,     0,     0,   180,     0,
       0,   216,     0,     0,   253,     0,     0,     0,     0,     0,
     118,   216,   122,   124,   277,   278,   279,   228,     0,   282,
     283,   284,   344,     0,   224,     0,     0,   224,     0,   176,
     176,     0,   182,     1,     0,     2,     3,     4,     5,   204,
     205,     0,     8,   183,     0,   414,     0,     0,     0,     9,
      10,    11,    12,   399,     0,   224,   206,     0,   207,   208,
       0,   176,    18,    84,     0,   209,     0,     0,     0,     0,
       0,   182,     0,    92,   182,   191,   192,   193,   194,   228,
       0,     0,     8,     0,     0,   231,     0,   120,     0,     9,
      10,    11,   195,   230,     0,   180,     0,   231,     0,     0,
       0,     0,   196,     0,     0,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,   180,   183,     0,     0,     0,   -42,   -42,
     176,   -42,   -42,   -42,   -42,   -42,   -42,  -101,   -42,     0,
       0,  -101,     0,     0,   180,   -42,   -42,   -42,   -42,   -42,
     -42,     0,   -42,     0,   -42,   -42,     0,     0,   -42,     0,
       0,   -42,     0,     0,     0,   230,     0,     0,     0,     0,
       0,   180,   224,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   182,     0,     0,   224,     0,     0,     0,   314,   180,
     180,   180,   321,   322,   415,   -91,   -91,     0,     0,   182,
       0,   176,     0,   180,   180,   180,   335,     0,   339,   341,
     181,   180,     0,   228,     0,     0,   228,     0,   180,   180,
     182,     0,     0,     0,     0,     0,     0,   373,   228,   228,
     228,   380,   381,     0,   228,   228,   228,   390,     0,   394,
     396,     0,   228,     0,   228,     0,     0,   182,     0,   181,
     180,     0,   181,   293,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,     0,     0,   311,   182,   182,   182,   182,   182,   182,
       0,   229,     0,     0,     0,   -71,   -71,     0,     0,   182,
     182,   182,   182,   337,   182,   182,   179,   182,     0,   230,
       0,     0,   230,     0,   182,   182,     0,     0,     0,     0,
       0,     0,   370,   230,   230,   230,   230,   230,   230,   180,
     230,   230,   230,   230,   392,   230,   230,     0,   230,     0,
     230,    93,     0,     0,     0,   179,   182,    98,   179,   170,
     171,   172,   173,   229,     0,     0,     8,     0,     0,   116,
       0,     0,     0,     9,    10,    11,   174,   227,     0,   181,
       0,   228,     0,     0,     0,   111,   175,   191,   192,   193,
     194,     0,     0,   228,     8,     0,     0,   181,     0,     0,
       0,     9,    10,    11,   195,     0,   238,   239,   240,   241,
     180,   243,   244,   245,   196,   182,   -41,   -41,   181,   -41,
     -41,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,     0,
       0,     0,     0,   -41,   -41,   -41,   -41,   -41,   -41,   227,
     -41,     0,   -41,   -41,     0,   181,   -41,     0,     0,   -41,
       0,     0,     0,     0,     0,   179,     0,   230,     0,     0,
       0,     0,   181,   181,   181,   181,   181,   181,     0,   230,
       0,     0,     0,   179,     0,     0,     0,   181,   181,   181,
     181,     0,   181,   181,   178,   181,   182,   229,     0,     0,
     229,     0,   181,   181,   179,     0,     0,     0,     0,     0,
       0,   229,   229,   229,   229,   229,   229,     0,   229,   229,
     229,   229,     0,   229,   229,     0,   229,    89,   229,     0,
       0,   179,     0,   178,   181,     0,   178,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,     0,   114,     0,     0,   179,
     179,   320,     0,     0,     0,   226,     0,     0,     0,  -101,
    -101,     0,     0,   179,   179,   333,     0,     0,     0,     0,
       0,   179,     0,   227,     0,     0,   227,     0,   179,   179,
       0,     0,   113,     0,   191,   192,   193,   194,   227,   227,
     379,     8,     0,   181,   227,   227,   388,     0,     9,    10,
      11,   195,   227,     0,   227,     0,     0,     0,     0,     0,
     179,   196,     0,     0,     0,     0,     0,   226,     0,     0,
     -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,
       0,     0,     0,   178,     0,   229,   -26,   -26,   -26,   -26,
     -26,   -26,     0,   -26,     0,   -26,   -26,   229,     0,   -26,
       0,   178,   -26,   -26,   238,   239,   240,   241,   242,   243,
     244,   245,     0,     0,   181,     0,     0,     0,     0,   179,
       0,     1,   178,     2,     3,     4,     5,   204,   205,     0,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
      12,    13,    14,     0,   206,     0,   207,   208,     0,   178,
      18,     0,     0,   209,   -22,     0,     0,   277,   278,   279,
     280,   227,   282,   283,   284,     0,     0,   316,   178,     0,
       0,     0,     0,   227,    73,   -64,   -64,   -64,   -64,    74,
      75,   178,   331,     0,     0,     0,     0,     0,     0,   178,
     179,   226,     0,   -64,   226,     0,   178,   178,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   375,   226,     0,     0,
       0,     0,   226,   386,     0,     0,     0,     0,   -95,   -95,
     226,     0,   226,     0,   -95,     0,     0,   -25,   178,   -25,
     -25,   -25,   -25,   -25,   -25,     0,   -25,     0,     0,     0,
       0,     0,     0,   -25,   -25,   -25,   -25,   -25,   -25,     0,
     -25,     0,   -25,   -25,     0,     0,   -25,     0,     0,   -25,
     -25,     0,     0,   -27,     0,   -27,   -27,   -27,   -27,   -27,
     -27,     0,   -27,     0,     0,     0,     0,     0,     0,   -27,
     -27,   -27,   -27,   -27,   -27,     0,   -27,   178,   -27,   -27,
       0,     0,   -27,     0,     0,   -27,   -27,   -21,   -21,     0,
     -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,     0,     0,
       0,     0,     0,     0,   -21,   -21,   -21,   -21,   -21,   -21,
       0,   -21,     0,   -21,   -21,     0,     0,   -21,     0,   226,
     -21,   -24,     0,   -24,   -24,   -24,   -24,   -24,   -24,     0,
     -24,   226,     0,     0,     0,     0,     0,   -24,   -24,   -24,
     -24,   -24,   -24,     0,   -24,     0,   -24,   -24,   178,     0,
     -24,     0,     0,   -24,   -24,   -10,   -10,     0,   -10,   -10,
     -10,   -10,   -10,   -10,     0,   -10,     0,     0,     0,     0,
       0,     0,   -10,   -10,   -10,   -10,   -10,   -10,     0,   -10,
       0,   -10,   -10,     0,     0,   -10,   -34,   -34,   -10,   -34,
     -34,   -34,   -34,   -34,   -34,     0,   -34,     0,     0,     0,
       0,     0,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,
     -34,     0,   -34,   -34,     0,     0,   -34,   -35,   -35,   -34,
     -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,     0,     0,
       0,     0,     0,     0,   -35,   -35,   -35,   -35,   -35,   -35,
       0,   -35,     0,   -35,   -35,     0,     0,   -35,   -40,   -40,
     -35,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,
       0,     0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,
     -40,     0,   -40,     0,   -40,   -40,     0,     0,   -40,   -38,
     -38,   -40,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,
       0,     0,     0,     0,     0,     0,   -38,   -38,   -38,   -38,
     -38,   -38,     0,   -38,     0,   -38,   -38,     0,     0,   -38,
     -14,   -14,   -38,   -14,   -14,   -14,   -14,   -14,   -14,     0,
     -14,     0,     0,     0,     0,     0,     0,   -14,   -14,   -14,
     -14,   -14,   -14,     0,   -14,     0,   -14,   -14,     0,     0,
     -14,   -43,   -43,   -14,   -43,   -43,   -43,   -43,   -43,   -43,
       0,   -43,     0,     0,     0,     0,     0,     0,   -43,   -43,
     -43,   -43,   -43,   -43,     0,   -43,     0,   -43,   -43,     0,
       0,   -43,     0,   -29,   -43,   -29,   -29,   -29,   -29,   -29,
     -29,     0,   -29,     0,     0,     0,     0,     0,     0,   -29,
     -29,   -29,   -29,   -29,   -29,     0,   -29,     0,   -29,   -29,
       0,     0,   -29,     0,     0,   -29,   -29,   -33,     0,   -33,
     -33,   -33,   -33,   -33,   -33,     0,   -33,     0,     0,     0,
       0,     0,     0,   -33,   -33,   -33,   -33,   -33,   -33,     0,
     -33,     0,   -33,   -33,     0,     0,   -33,     0,     0,   -33,
     -33,   -28,     0,   -28,   -28,   -28,   -28,   -28,   -28,     0,
     -28,     0,     0,     0,     0,     0,     0,   -28,   -28,   -28,
     -28,   -28,   -28,     0,   -28,     0,   -28,   -28,     0,     0,
     -28,     0,     0,   -28,   -28,   -30,     0,   -30,   -30,   -30,
     -30,   -30,   -30,     0,   -30,     0,     0,     0,     0,     0,
       0,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,     0,
     -30,   -30,     0,     0,   -30,     0,     0,   -30,   -30,   -31,
       0,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,     0,
       0,     0,     0,     0,     0,   -31,   -31,   -31,   -31,   -31,
     -31,     0,   -31,     0,   -31,   -31,     0,     0,   -31,     0,
       0,   -31,   -31,   -32,     0,   -32,   -32,   -32,   -32,   -32,
     -32,     0,   -32,     0,     0,     0,     0,     0,     0,   -32,
     -32,   -32,   -32,   -32,   -32,     0,   -32,     0,   -32,   -32,
       0,     0,   -32,     0,     0,   -32,   -32,   -11,     0,   -11,
     -11,   -11,   -11,   -11,   -11,     0,   -11,     0,     0,     0,
       0,     0,     0,   -11,   -11,   -11,   -11,   -11,   -11,     0,
     -11,     0,   -11,   -11,     0,     0,   -11,     0,     0,   -11,
     -11,   -36,     0,   -36,   -36,   -36,   -36,   -36,   -36,     0,
     -36,     0,     0,     0,     0,     0,     0,   -36,   -36,   -36,
     -36,   -36,   -36,     0,   -36,     0,   -36,   -36,     0,     0,
     -36,     0,     0,   -36,   -36,   -10,     0,   -10,   -10,   -10,
     -10,   -10,   -10,     0,   -10,     0,     0,     0,     0,     0,
       0,   -10,   -10,   -10,   -10,   -10,   -10,     0,   -10,     0,
     -10,   -10,     0,     0,   -10,     0,     0,   -10,   -10,   -42,
       0,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,     0,
       0,     0,     0,     0,     0,   -42,   -42,   -42,   -42,   -42,
     -42,     0,   -42,     0,   -42,   -42,     0,     0,   -42,     0,
       0,   -42,   -42,   -41,     0,   -41,   -41,   -41,   -41,   -41,
     -41,     0,   -41,     0,     0,     0,     0,     0,     0,   -41,
     -41,   -41,   -41,   -41,   -41,     0,   -41,     0,   -41,   -41,
       0,     0,   -41,     0,     0,   -41,   -41,   -21,     0,   -21,
     -21,   -21,   -21,   -21,   -21,     0,   -21,     0,     0,     0,
       0,     0,     0,   -21,   -21,   -21,   -21,   -21,   -21,     0,
     -21,     0,   -21,   -21,     0,     0,   -21,     0,     0,   -21,
     -21,   -34,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,
     -34,     0,     0,     0,     0,     0,     0,   -34,   -34,   -34,
     -34,   -34,   -34,     0,   -34,     0,   -34,   -34,     0,     0,
     -34,     0,     0,   -34,   -34,   -35,     0,   -35,   -35,   -35,
     -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,     0,
       0,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,     0,
     -35,   -35,     0,     0,   -35,     0,     0,   -35,   -35,   -40,
       0,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,
       0,     0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,
     -40,     0,   -40,     0,   -40,   -40,     0,     0,   -40,     0,
       0,   -40,   -40,   -38,     0,   -38,   -38,   -38,   -38,   -38,
     -38,     0,   -38,     0,     0,     0,     0,     0,     0,   -38,
     -38,   -38,   -38,   -38,   -38,     0,   -38,     0,   -38,   -38,
       0,     0,   -38,     0,     0,   -38,   -38,   -43,     0,   -43,
     -43,   -43,   -43,   -43,   -43,     0,   -43,     0,     0,     0,
       0,     0,     0,   -43,   -43,   -43,   -43,   -43,   -43,     0,
     -43,     0,   -43,   -43,     0,     0,   -43,     0,     0,   -43,
     -43,   115,     0,   191,   192,   193,   194,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     195,     0,   117,     0,   191,   192,   193,   194,     0,     0,
     196,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   195,     0,   119,     0,   191,   192,   193,   194,     0,
       0,   196,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   195,     0,   121,     0,   191,   192,   193,   194,
       0,     0,   196,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   195,     0,   123,     0,   191,   192,   193,
     194,     0,     0,   196,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   195,     0,   125,     0,   191,   192,
     193,   194,     0,     0,   196,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   195,     0,     1,     0,   191,
     192,   193,   194,     0,     0,   196,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   195,     0,   217,     0,
     218,   219,   220,   221,     0,     0,   196,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   222,     0,   273,
       0,     2,     3,     4,     5,     0,     0,   223,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,    12,     0,
     310,     0,   297,   298,   299,   300,     0,     0,    18,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   301,
       0,   313,     0,   297,   298,   299,   300,     0,     0,   302,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     301,     0,   315,     0,   297,   298,   299,   300,     0,     0,
     302,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   301,     0,   317,     0,   297,   298,   299,   300,     0,
       0,   302,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   301,     0,   319,     0,   297,   298,   299,   300,
       0,     0,   302,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   301,     0,   328,     0,   297,   298,   299,
     300,     0,     0,   302,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   301,     0,   330,     0,   297,   298,
     299,   300,     0,     0,   302,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   301,     0,   332,     0,   297,
     298,   299,   300,     0,     0,   302,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   301,     0,   334,     0,
     297,   298,   299,   300,     0,     0,   302,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   301,     0,   336,
       0,   297,   298,   299,   300,     0,     0,   302,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   301,     0,
     338,     0,   297,   298,   299,   300,     0,     0,   302,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   301,
       0,   340,     0,   297,   298,   299,   300,     0,     0,   302,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     301,     0,   342,     0,   297,   298,   299,   300,     0,     0,
     302,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   301,     0,   169,     0,   297,   298,   299,   300,     0,
       0,   302,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   301,     0,   350,     0,   170,   171,   172,   173,
       0,     0,   302,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   174,     0,   369,     0,   356,   357,   358,
     359,     0,     0,   175,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   360,     0,   372,     0,   356,   357,
     358,   359,     0,     0,   361,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   360,     0,   374,     0,   356,
     357,   358,   359,     0,     0,   361,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   360,     0,   376,     0,
     356,   357,   358,   359,     0,     0,   361,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   360,     0,   378,
       0,   356,   357,   358,   359,     0,     0,   361,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   360,     0,
     383,     0,   356,   357,   358,   359,     0,     0,   361,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   360,
       0,   385,     0,   356,   357,   358,   359,     0,     0,   361,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     360,     0,   387,     0,   356,   357,   358,   359,     0,     0,
     361,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   360,     0,   389,     0,   356,   357,   358,   359,     0,
       0,   361,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   360,     0,   391,     0,   356,   357,   358,   359,
       0,     0,   361,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   360,     0,   393,     0,   356,   357,   358,
     359,     0,     0,   361,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   360,     0,   395,     0,   356,   357,
     358,   359,     0,     0,   361,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   360,     0,   397,     0,   356,
     357,   358,   359,     0,     0,   361,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   360,     0,   217,     0,
     356,   357,   358,   359,     0,     0,   361,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   360,     2,     3,
       4,     5,     0,     0,     0,     8,     0,   361,     0,     0,
       0,     0,     9,    10,    11,    12,   191,   192,   193,   194,
       0,     0,     0,     8,     0,    18,     0,     0,     0,     0,
       9,    10,    11,   195,   170,   171,   172,   173,     0,     0,
       0,     8,     0,   196,     0,     0,     0,     0,     9,    10,
      11,   174,   218,   219,   220,   221,     0,     0,     0,     8,
       0,   175,     0,     0,     0,     0,     9,    10,    11,   222,
     297,   298,   299,   300,     0,     0,     0,     8,     0,   223,
       0,     0,     0,     0,     9,    10,    11,   301,   356,   357,
     358,   359,     0,     0,     0,     8,     0,   302,     0,     0,
       0,     0,     9,    10,    11,   360,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,     0,   361,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,     0,     0,   -91,    79,     0,     0,
       0,     0,   -91,     0,     0,     0,     0,   -95,   -95,     0,
       0,     0,   -95,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,     0,
       0,     0,     0,     0,   265,   -91,     0,     0,     0,   -91,
       0,     0,     0,  -101,  -101,     0,     0,  -101,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,     0,     0,     0,     0,     0,     0,
    -102,  -102,     0,     0,  -102,     0,     0,     0,  -100,  -100,
       0,     0,  -100,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,
       0,     0,     0,     0,     0,  -103,  -103,     0,     0,  -103,
       0,     0,     0,   -75,   -75,     0,     0,   294,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,     0,     0,     0,     0,     0,     0,
     -79,   -79,     0,     0,   -79,     0,     0,     0,   -85,   -85,
       0,     0,   -85,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,
       0,     0,     0,     0,     0,   -92,   -92,     0,     0,   -92,
       0,     0,     0,   -93,   -93,     0,     0,   -93,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,     0,
     -80,   -80,     0,     0,   -80,     0,     0,     0,   -94,   -94,
       0,     0,   -94,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,
       0,     0,     0,     0,     0,   -86,   -86,     0,     0,   -86,
       0,   -75,     0,     0,     0,     0,     0,    77,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,     0,     0,     0,     0,   -79,     0,
       0,     0,     0,     0,   -79,     0,   -85,     0,     0,     0,
       0,     0,   -85,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,
       0,     0,     0,   -92,     0,     0,     0,     0,     0,   -92,
       0,   -93,     0,     0,     0,     0,     0,   -93,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,     0,     0,     0,     0,   -80,     0,
       0,     0,     0,     0,   -80,     0,   -94,     0,     0,     0,
       0,     0,   -94,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,
       0,     0,     0,   -86,     0,     0,     0,     0,     0,   -86,
       0,     0,     0,  -102,     0,     0,     0,  -102,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,     0,     0,     0,     0,     0,     0,
    -100,     0,     0,     0,  -100,     0,     0,     0,  -103,     0,
       0,     0,  -103,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,     0,
       0,     0,     0,     0,     0,   -75,     0,     0,     0,   263,
       0,     0,     0,   -79,     0,     0,     0,   -79,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,     0,     0,     0,     0,     0,     0,
     -85,     0,     0,     0,   -85,     0,     0,     0,   -92,     0,
       0,     0,   -92,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,
       0,     0,     0,     0,     0,   -93,     0,     0,     0,   -93,
       0,     0,     0,   -80,     0,     0,     0,   -80,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,     0,     0,     0,     0,     0,     0,
     -94,     0,     0,     0,   -94,     0,     0,     0,   -86,     0,
       0,     0,   -86,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,     0,
       0,     0,     0,     0,     0,  -102,  -102,     0,     0,     0,
       0,     0,     0,  -100,  -100,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,     0,     0,     0,     0,     0,     0,  -103,  -103,     0,
       0,     0,     0,     0,     0,   -78,   -78,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,     0,     0,     0,     0,     0,     0,   -79,
     -79,     0,     0,     0,     0,     0,     0,   -85,   -85,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,     0,     0,     0,     0,     0,
       0,   -92,   -92,     0,     0,     0,     0,     0,     0,   -93,
     -93,   293,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,
       0,     0,     0,   -74,   -74,     0,     0,     0,     0,     0,
       0,   -75,   -75,   277,   278,   279,   280,   -50,   282,   283,
     284,   277,   278,   279,   -54,   -54,   282,   283,   284,     0,
       0,     0,     0,     0,     0,   -50,   -50,     0,     0,     0,
       0,     0,     0,   -54,   -54,   277,   278,   279,   -58,   -58,
     -58,   283,   284,   277,   278,   -62,   -62,   -62,   -62,   283,
     284,     0,     0,     0,     0,     0,     0,   -58,   -58,     0,
       0,     0,     0,     0,     0,   -62,   -62,   277,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   293,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,     0,     0,     0,   -73,
     -73,     0,     0,     0,     0,     0,     0,   -72,   -72,   277,
     278,   -68,   -68,   -68,   -68,   283,   284,   277,   278,   -67,
     -67,   -67,   -67,   283,   284,     0,     0,     0,     0,     0,
       0,   -68,   -68,     0,     0,     0,     0,     0,     0,   -67,
     -67,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,     0,     0,     0,
       0,     0,     0,   -77,   -77,     0,     0,     0,     0,     0,
       0,   -76,   -76,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,     0,
       0,     0,     0,     0,     0,   -80,   -80,     0,     0,     0,
       0,     0,     0,   -94,   -94,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,     0,     0,     0,     0,     0,     0,   -86,   -86,     0,
       0,     0,     0,     0,   403,   -91,   238,   239,   240,   241,
     242,   243,   244,   245,   262,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,     0,     0,     0,     0,     0,     0,   135,     0,
       0,     0,     0,     0,     0,     0,   -71,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,     0,     0,     0,     0,     0,     0,  -101,
       0,     0,     0,     0,     0,     0,     0,  -102,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,     0,     0,     0,     0,     0,     0,
    -100,     0,     0,     0,     0,     0,     0,     0,  -103,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,     0,     0,     0,     0,     0,
       0,   -78,     0,     0,     0,     0,     0,     0,     0,   -79,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,     0,     0,     0,     0,
       0,     0,   -85,     0,     0,     0,     0,     0,     0,     0,
     -92,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   262,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,     0,
       0,     0,     0,   -93,     0,     0,     0,     0,     0,     0,
       0,   -74,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     238,   239,   240,   241,   -50,   243,   244,   245,     0,     0,
       0,     0,     0,     0,   -75,     0,     0,     0,     0,     0,
       0,     0,   -50,   238,   239,   240,   -54,   -54,   243,   244,
     245,   238,   239,   240,   -58,   -58,   -58,   244,   245,     0,
       0,     0,     0,     0,     0,   -54,     0,     0,     0,     0,
       0,     0,     0,   -58,   238,   239,   -62,   -62,   -62,   -62,
     244,   245,   238,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
       0,     0,     0,     0,     0,     0,   -62,     0,     0,     0,
       0,     0,     0,     0,   -73,   262,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   238,   239,   -68,   -68,   -68,   -68,   244,
     245,     0,     0,     0,     0,     0,     0,   -72,     0,     0,
       0,     0,     0,     0,     0,   -68,   238,   239,   -67,   -67,
     -67,   -67,   244,   245,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,     0,     0,     0,     0,     0,     0,   -67,     0,
       0,     0,     0,     0,     0,     0,   -77,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   238,   239,   240,   241,   242,
     243,   244,   245,     0,     0,     0,     0,     0,     0,   -76,
       0,     0,     0,     0,     0,     0,     0,   409,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,     0,
     -80,     0,     0,     0,     0,     0,     0,     0,   -94,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,     0,     0,     0,     0,     0,
       0,   -86,     0,     0,     0,     0,     0,   -95,   -95,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,    48,    49,    50,
      51,   -50,    53,    54,    55,     0,     0,     0,     0,   -91,
     268,     0,     0,     0,     0,     0,     0,   -50,    48,    49,
      50,   -54,   -54,    53,    54,    55,    48,    49,    50,   -58,
     -58,   -58,    54,    55,     0,     0,     0,     0,   -54,     0,
       0,     0,     0,     0,     0,     0,   -58,    48,    49,   -62,
     -62,   -62,   -62,    54,    55,    48,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,     0,     0,     0,     0,   -62,     0,     0,
       0,     0,     0,     0,     0,   -73,    76,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,    48,    49,   -68,   -68,   -68,   -68,
      54,    55,     0,     0,     0,     0,   -72,     0,     0,     0,
       0,     0,     0,     0,   -68,    48,    49,   -67,   -67,   -67,
     -67,    54,    55,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,     0,     0,     0,     0,   -67,     0,     0,     0,     0,
       0,     0,     0,   -77,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
       0,     0,     0,     0,   -76,     0,     0,     0,     0,     0,
       0,     0,  -101,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,     0,
       0,     0,     0,  -102,     0,     0,     0,     0,     0,     0,
       0,  -100,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,     0,     0,
       0,     0,  -103,     0,     0,     0,     0,     0,     0,     0,
     -79,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,     0,     0,     0,
       0,   -85,     0,     0,     0,     0,     0,     0,     0,   -92,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,     0,
     -93,     0,     0,     0,     0,     0,     0,     0,   -80,    48,
      49,    50,    51,    52,    53,    54,    55,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,     0,     0,     0,     0,   353,
       0,     0,     0,     0,     0,     0,     0,   -94,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   277,   278,   279,   280,
     281,   282,   283,   284,     0,     0,     0,     0,   -86
};

static const yytype_int16 yycheck[] =
{
       0,     0,     0,   209,     0,     0,     0,     0,     0,   265,
     275,   137,   268,     0,    30,     6,     6,    17,    18,    30,
       6,    21,    21,    21,     6,    21,    21,    21,    21,    21,
       6,   157,    23,    23,    21,     6,     6,     0,    29,    29,
     296,    41,   248,    29,    13,    45,    30,    29,     9,    10,
      11,     0,    23,    29,    15,    16,    56,    57,   323,    29,
      60,    61,    31,     0,     1,    65,     3,     4,     5,     6,
       7,     8,    21,    10,    13,    13,    29,    30,    30,    79,
      17,    18,    19,    20,    21,    22,     6,    24,    25,    26,
      27,    29,    31,    30,     0,     1,    33,     3,     4,     5,
       6,     7,     8,    23,    10,    12,    13,   107,    12,    13,
     110,    17,    18,    19,    20,    21,    22,    29,    24,    25,
      26,    27,    29,     6,    30,    29,    13,    33,    29,     9,
      10,    11,    12,    13,    14,    15,    16,   137,    31,    12,
      13,   141,    29,    12,    13,   143,   272,   403,   135,   136,
      30,    31,    32,     9,   154,    35,    31,   157,    31,   415,
      31,   159,    31,    32,   429,    31,   166,   166,   155,   156,
     166,   166,   166,   166,   166,   175,    29,   164,    29,   166,
      11,    12,    13,    14,   184,     0,     1,    34,     3,     4,
       5,     6,     7,     8,    31,    10,   196,    31,    32,    29,
      31,    32,    17,    18,    19,    20,    21,    22,   208,    24,
      25,    26,    27,    31,    32,    30,   422,     1,    33,     3,
       4,     5,     6,   223,    31,    32,    10,    29,    11,    12,
      13,    14,   232,    17,    18,    19,    20,    29,   238,   239,
     240,   241,   242,   243,   244,   245,    30,    31,    31,    32,
      12,    13,    14,    31,    32,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    33,   265,    29,    29,   268,   269,
     270,   271,   272,    31,    32,   275,    29,   277,   278,   279,
     280,   281,   282,   283,   284,   411,   286,   287,   288,   289,
     290,   291,   292,   293,   294,    31,   296,     0,    12,    13,
      14,    33,   302,    33,   304,    31,   432,    12,    13,    14,
      11,    12,    13,    14,    17,    18,     6,    31,    21,    11,
      12,    13,    14,   323,    12,    13,    31,     1,    29,     3,
       4,     5,     6,     7,     8,    31,    10,    30,    41,    31,
      32,    29,    29,    17,    18,    19,    20,    21,    22,    30,
      24,    25,    26,    27,    57,    30,    30,    60,    61,    33,
      34,   361,    65,   363,     1,    30,     3,     4,     5,     6,
       7,     8,    29,    10,    21,    22,    79,    31,    32,    29,
      17,    18,    19,    20,    21,    22,    31,    24,    25,    26,
      27,    13,    31,    30,    12,    13,    33,    34,    11,    12,
      13,    14,    13,   403,   107,    11,    12,    13,    14,    31,
      32,   411,    31,    31,    32,   415,    12,    13,    31,    32,
      31,    32,   409,   410,    29,    31,    32,    21,    22,   429,
      31,    32,   432,    31,   137,    31,    32,    31,   141,   439,
     439,    29,    30,   430,   431,     9,    10,    11,    12,    13,
      14,    15,    16,     9,   157,    21,    22,    31,    32,    11,
      12,    13,    14,   166,     6,    31,    30,    31,    32,     6,
      31,     1,   175,     3,     4,     5,     6,     7,     8,    31,
      10,   184,    11,    12,    13,    14,    31,    17,    18,    19,
      20,    21,    22,   196,    24,    25,    26,    27,    31,    31,
      30,    29,    31,    33,    34,   208,     9,    10,    11,    12,
      13,    14,    15,    16,     1,    31,     3,     4,     5,     6,
     223,    34,    31,    10,     9,    31,    34,    30,    31,   232,
      17,    18,    19,    20,    29,   238,   239,   240,   241,   242,
     243,   244,   245,    30,    31,    10,    11,    12,    13,    14,
      15,    16,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    29,   265,    12,    13,   268,    31,   270,   271,   272,
      33,    31,   275,    31,   277,   278,   279,   280,   281,   282,
     283,   284,    31,   286,   287,   288,   289,   290,   291,   292,
     293,   294,    29,   296,     0,    12,    13,    14,    31,   302,
      34,   304,     9,    10,    11,    12,    13,    14,    15,    16,
      33,    17,    18,    31,    31,    21,    11,    12,    13,    14,
     323,    21,    29,     0,     1,   140,     3,     4,     5,     6,
       7,     8,   159,    10,   107,    41,    31,    32,    12,    13,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    57,    -1,    30,    60,    61,    33,    31,   361,    65,
     363,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    79,    12,    13,    14,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    29,    -1,    33,    34,    11,    12,    13,    14,    -1,
     403,   107,    -1,     3,     4,     5,     6,    -1,   411,    -1,
      10,    -1,   415,    -1,    -1,    31,    32,    17,    18,    19,
      20,    11,    12,    13,    14,    -1,   429,    -1,    -1,   432,
      30,   137,    12,    13,    14,   141,   439,     0,     1,    29,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    29,
      -1,   157,    -1,    -1,    17,    18,    19,    20,    21,    22,
     166,    24,    -1,    26,    27,    -1,    -1,    30,    -1,   175,
      33,    10,    11,    12,    13,    14,    15,    16,   184,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
     196,    -1,    31,    32,    -1,    -1,    17,    18,    19,    20,
      21,    22,   208,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,     1,    33,     3,     4,     5,     6,   223,     9,    10,
      10,    -1,    -1,    -1,    15,    16,   232,    17,    18,    19,
      20,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
      30,     9,    10,    11,    12,    13,    14,    15,    16,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
      -1,    29,   268,    -1,   270,   271,   272,    35,    -1,   275,
      -1,   277,   278,   279,   280,   281,   282,   283,   284,    -1,
     286,   287,   288,   289,   290,   291,   292,   293,   294,    -1,
     296,     0,    11,    12,    13,    14,   302,    -1,   304,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    17,    18,
      29,    -1,    21,    11,    12,    13,    14,   323,    -1,    29,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    41,    31,    32,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    57,    -1,
      30,    60,    61,    33,    -1,   361,    65,   363,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      79,    11,    12,    13,    14,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    29,
      -1,    33,    11,    12,    13,    14,    -1,   403,   107,    -1,
       3,     4,     5,     6,    -1,   411,    -1,    10,    -1,   415,
      -1,    -1,    31,    32,    17,    18,    19,    20,    11,    12,
      13,    14,    -1,   429,     9,    10,   432,    30,   137,    -1,
      15,    16,   141,   439,     0,     1,    29,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,   157,    -1,
      -1,    17,    18,    19,    20,    21,    22,   166,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,   175,    33,    11,    12,
      13,    14,    12,    13,    14,   184,     0,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,   196,    31,    32,
      -1,    31,    32,    17,    18,    19,    20,    21,    22,   208,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,     1,    33,
       3,     4,     5,     6,   223,     9,    10,    10,    -1,    -1,
      -1,    15,    16,   232,    17,    18,    19,    20,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,    30,     9,    10,
      11,    12,    13,    14,    15,    16,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,    -1,    29,   268,
      -1,   270,   271,   272,    35,    -1,   275,    -1,   277,   278,
     279,   280,   281,   282,   283,   284,    -1,   286,   287,   288,
     289,   290,   291,   292,   293,   294,    -1,   296,     0,    11,
      12,    13,    14,   302,    -1,   304,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    17,    18,    29,    -1,    21,
      11,    12,    13,    14,   323,    -1,    29,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    41,
      31,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    57,    -1,    30,    60,    61,
      33,    -1,   361,    65,   363,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    79,    11,    12,
      13,    14,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    29,    -1,    33,    11,
      12,    13,    14,    -1,   403,   107,    -1,     3,     4,     5,
       6,    -1,   411,    -1,    10,    -1,   415,    -1,    -1,    31,
      -1,    17,    18,    19,    20,    11,    12,    13,    14,    -1,
     429,    -1,    -1,   432,    30,   137,    -1,    -1,    -1,   141,
     439,     0,     1,    29,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,   157,    -1,    -1,    17,    18,
      19,    20,    21,    22,   166,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,   175,    33,    11,    12,    13,    14,    12,
      13,    14,   184,     0,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,   196,    31,    -1,    -1,    31,    32,
      17,    18,    19,    20,    21,    22,   208,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,     1,    33,     3,     4,     5,
       6,   223,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
     232,    17,    18,    19,    20,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,    30,     9,    10,    11,    12,    13,
      14,    15,    16,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,    -1,    29,   268,    -1,   270,   271,
     272,    35,    -1,   275,    -1,   277,   278,   279,   280,   281,
     282,   283,   284,    -1,   286,   287,   288,   289,   290,   291,
     292,   293,   294,    -1,   296,     0,    11,    12,    13,    14,
     302,    -1,   304,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    17,    18,    29,    -1,    21,    11,    12,    13,
      14,   323,    -1,    29,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    41,    31,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    57,    -1,    30,    60,    61,    33,    -1,   361,
      65,   363,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    79,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,    11,    12,    13,    14,
      -1,   403,   107,    -1,     3,     4,     5,     6,    -1,   411,
      -1,    10,    -1,   415,    -1,    -1,    31,    -1,    17,    18,
      19,    20,     9,    10,    11,    -1,    -1,   429,    15,    16,
     432,    30,   137,    -1,    -1,    -1,   141,   439,    -1,    -1,
       1,    18,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,   157,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,   166,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
     175,    -1,    33,    -1,    -1,    52,    -1,    -1,    -1,   184,
      57,    -1,    -1,    60,    -1,    11,    12,    13,    14,    -1,
      -1,   196,    69,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,    79,   208,    10,    31,    11,    12,    13,    14,
      -1,    17,    18,    19,    20,     9,    10,    11,   223,    -1,
      14,    15,    16,    29,    30,    -1,    31,   232,    -1,    -1,
      -1,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,    -1,    29,   268,   141,   270,   271,   272,    35,    -1,
     275,    -1,   277,   278,   279,   280,   281,   282,   283,   284,
     157,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      -1,   296,     0,    11,    12,    13,    14,   302,   175,   304,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    17,
      18,    29,    -1,    21,    11,    12,    13,    14,   323,   196,
      29,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    31,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,   223,    26,    27,    57,
      -1,    30,    60,    61,    33,    -1,   361,    65,   363,    -1,
      12,    13,    14,    -1,    -1,   242,     1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    -1,   255,    31,
      32,    -1,    17,    18,    19,    20,   263,    -1,   265,    -1,
      -1,   268,    -1,   270,   271,    30,    -1,    -1,   403,   107,
      -1,     9,    10,    11,   281,    -1,   411,    15,    16,   286,
     415,    -1,    -1,    -1,    -1,    -1,    -1,   294,    -1,   296,
      18,    -1,    -1,    -1,   429,   302,    -1,   432,    -1,   137,
      -1,    -1,    -1,   141,   439,     9,    10,    11,    12,    13,
      14,    15,    16,    41,    -1,    -1,    -1,    -1,    -1,   157,
      48,    49,    50,    51,    52,    53,    54,    55,   166,    57,
      -1,    -1,    60,     9,    10,    11,    12,   175,    14,    15,
      16,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    79,    -1,    -1,   361,    -1,     0,     1,   196,     3,
       4,     5,     6,     7,     8,    -1,    10,    18,    -1,    -1,
     208,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,   223,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,   403,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,    57,    10,   415,    60,
      -1,    -1,    -1,   141,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,   432,    77,    30,    79,   157,
      33,    -1,   270,   271,   272,    -1,     1,   275,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,   175,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,   184,     1,    -1,     3,
       4,     5,     6,    -1,   302,    30,    10,    -1,   196,   197,
      -1,    -1,    -1,    17,    18,    19,    20,     9,    10,    11,
      12,    13,    14,    15,    16,   323,    30,     9,    10,    11,
     141,    -1,    14,    15,    16,   223,    -1,    -1,    30,    31,
      32,    -1,    -1,    35,   232,    -1,   157,    -1,    -1,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,    -1,   361,   175,    -1,    -1,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,    -1,    -1,
     268,    -1,   270,   271,    -1,   196,    18,    -1,    -1,   277,
     278,   279,   280,   281,   282,   283,   284,    -1,   286,   287,
     288,   289,   290,   291,   292,   293,   294,    -1,   296,    -1,
      -1,    -1,   223,   411,   302,    -1,   304,    -1,    50,    -1,
      -1,    -1,    54,    55,    -1,    57,    -1,    -1,    60,    -1,
      -1,   429,    -1,    -1,   432,    -1,    -1,    -1,    -1,    -1,
      72,   439,    74,    75,     9,    10,    11,    79,    -1,    14,
      15,    16,   263,    -1,   265,    -1,    -1,   268,    -1,   270,
     271,    -1,    18,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,   361,    -1,   363,    -1,    -1,    -1,    17,
      18,    19,    20,   294,    -1,   296,    24,    -1,    26,    27,
      -1,   302,    30,    49,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    57,    -1,     1,    60,     3,     4,     5,     6,   141,
      -1,    -1,    10,    -1,    -1,   403,    -1,    73,    -1,    17,
      18,    19,    20,    79,    -1,   157,    -1,   415,    -1,    -1,
      -1,    -1,    30,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,   175,   432,    -1,    -1,    -1,     0,     1,
     361,     3,     4,     5,     6,     7,     8,    31,    10,    -1,
      -1,    35,    -1,    -1,   196,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,
      -1,   223,   403,     9,    10,    11,    12,    13,    14,    15,
      16,   157,    -1,    -1,   415,    -1,    -1,    -1,   240,   241,
     242,   243,   244,   245,    30,    31,    32,    -1,    -1,   175,
      -1,   432,    -1,   255,   256,   257,   258,    -1,   260,   261,
      18,   263,    -1,   265,    -1,    -1,   268,    -1,   270,   271,
     196,    -1,    -1,    -1,    -1,    -1,    -1,   279,   280,   281,
     282,   283,   284,    -1,   286,   287,   288,   289,    -1,   291,
     292,    -1,   294,    -1,   296,    -1,    -1,   223,    -1,    57,
     302,    -1,    60,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    79,    -1,    -1,    -1,    31,    32,    -1,    -1,   255,
     256,   257,   258,   259,   260,   261,    18,   263,    -1,   265,
      -1,    -1,   268,    -1,   270,   271,    -1,    -1,    -1,    -1,
      -1,    -1,   278,   279,   280,   281,   282,   283,   284,   361,
     286,   287,   288,   289,   290,   291,   292,    -1,   294,    -1,
     296,    53,    -1,    -1,    -1,    57,   302,     1,    60,     3,
       4,     5,     6,   141,    -1,    -1,    10,    -1,    -1,    71,
      -1,    -1,    -1,    17,    18,    19,    20,    79,    -1,   157,
      -1,   403,    -1,    -1,    -1,     1,    30,     3,     4,     5,
       6,    -1,    -1,   415,    10,    -1,    -1,   175,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,     9,    10,    11,    12,
     432,    14,    15,    16,    30,   361,     0,     1,   196,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,   141,
      24,    -1,    26,    27,    -1,   223,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,   157,    -1,   403,    -1,    -1,
      -1,    -1,   240,   241,   242,   243,   244,   245,    -1,   415,
      -1,    -1,    -1,   175,    -1,    -1,    -1,   255,   256,   257,
     258,    -1,   260,   261,    18,   263,   432,   265,    -1,    -1,
     268,    -1,   270,   271,   196,    -1,    -1,    -1,    -1,    -1,
      -1,   279,   280,   281,   282,   283,   284,    -1,   286,   287,
     288,   289,    -1,   291,   292,    -1,   294,    51,   296,    -1,
      -1,   223,    -1,    57,   302,    -1,    60,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    70,    -1,    -1,   241,
     242,   243,    -1,    -1,    -1,    79,    -1,    -1,    -1,    31,
      32,    -1,    -1,   255,   256,   257,    -1,    -1,    -1,    -1,
      -1,   263,    -1,   265,    -1,    -1,   268,    -1,   270,   271,
      -1,    -1,     1,    -1,     3,     4,     5,     6,   280,   281,
     282,    10,    -1,   361,   286,   287,   288,    -1,    17,    18,
      19,    20,   294,    -1,   296,    -1,    -1,    -1,    -1,    -1,
     302,    30,    -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,   157,    -1,   403,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,   415,    -1,    30,
      -1,   175,    33,    34,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,   432,    -1,    -1,    -1,    -1,   361,
      -1,     1,   196,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,   223,
      30,    -1,    -1,    33,    34,    -1,    -1,     9,    10,    11,
      12,   403,    14,    15,    16,    -1,    -1,   241,   242,    -1,
      -1,    -1,    -1,   415,    10,    11,    12,    13,    14,    15,
      16,   255,   256,    -1,    -1,    -1,    -1,    -1,    -1,   263,
     432,   265,    -1,    29,   268,    -1,   270,   271,     9,    10,
      11,    12,    13,    14,    15,    16,   280,   281,    -1,    -1,
      -1,    -1,   286,   287,    -1,    -1,    -1,    -1,    29,    30,
     294,    -1,   296,    -1,    35,    -1,    -1,     1,   302,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,   361,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,   403,
      33,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,   415,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,   432,    -1,
      30,    -1,    -1,    33,    34,     0,     1,    -1,     3,     4,
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
       0,     1,    33,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,     0,     1,    33,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,     1,    33,     3,     4,     5,     6,     7,
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
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
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
      -1,    17,    18,    19,    20,    -1,     1,    -1,     3,     4,
       5,     6,    -1,    -1,    30,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    30,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    30,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    30,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    30,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    30,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    30,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    30,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    35,
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
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
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
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,
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
      -1,    -1,    -1,    -1,    30,    31,     9,    10,    11,    12,
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
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    29,    30,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    29,     9,    10,
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
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    29
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
      30,    30,     1,    59,    59,    49,     0,    39,    29,    13,
      12,    14,    11,    10,    15,    16,     9,    35,    68,    30,
      29,    74,    68,     1,    67,    68,     1,    65,     1,    63,
       1,    62,     1,    64,    65,    65,    74,    59,     1,    59,
      59,    60,    29,    29,    31,    40,    50,    51,    52,    53,
      75,     1,    62,     1,    63,     1,    64,     1,    65,     1,
      67,     1,    65,     1,    65,     1,    68,    61,    59,    71,
      72,    30,    41,    31,    31,    31,    31,    29,    34,    52,
      74,    32,    31,    43,    29,    29,    29,    48,    48,    60,
      59,    45,    46,    47,    75,    25,    25,    29,    31,    32,
      74,    48,    48,    60,    44,    47,    31,    48,    53,     1,
       3,     4,     5,     6,    20,    30,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    73,    74,    76,    77,
       6,     3,     4,     5,     6,    20,    30,    69,    70,    73,
      74,    76,    77,     6,     7,     8,    24,    26,    27,    33,
      48,    54,    55,    56,    57,    58,    59,     1,     3,     4,
       5,     6,    20,    30,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    73,    74,    76,    77,     9,    10,
      11,    12,    13,    14,    15,    16,     6,    29,    33,    41,
      21,    22,     6,    59,    59,    13,    12,    14,    11,    10,
      15,    16,     9,    35,    68,    30,    59,    68,    30,    30,
      30,    30,    30,     1,    59,    49,    29,     9,    10,    11,
      12,    13,    14,    15,    16,    59,    13,    12,    14,    11,
      10,    15,    16,     9,    35,    68,    30,     3,     4,     5,
       6,    20,    30,    68,    69,    70,    73,    74,    76,    77,
       1,    67,    68,     1,    65,     1,    63,     1,    62,     1,
      64,    65,    65,    49,    29,    23,    23,    31,     1,    62,
       1,    63,     1,    64,     1,    65,     1,    67,     1,    65,
       1,    65,     1,    68,    61,    72,    31,    72,    74,    59,
       1,    59,    60,    29,    29,    50,     3,     4,     5,     6,
      20,    30,    68,    69,    70,    73,    74,    76,    77,     1,
      67,    68,     1,    65,     1,    63,     1,    62,     1,    64,
      65,    65,    31,     1,    62,     1,    63,     1,    64,     1,
      65,     1,    67,     1,    65,     1,    65,     1,    68,    61,
      72,    59,    68,    30,    50,    31,    31,    31,    31,    31,
      31,    29,    34,    59,    68,    30,    31,    31,    72,    34,
      29,    29,    33,    48,    48,    60,    31,    72,    31,    49,
      25,    25,    29,    31,    50,    48,    48,    60,    34,    31,
      53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    39,    41,
      40,    40,    43,    44,    42,    45,    45,    46,    46,    47,
      49,    48,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    56,    56,    56,
      56,    57,    57,    58,    59,    59,    60,    60,    61,    61,
      61,    61,    62,    62,    62,    62,    63,    63,    63,    63,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    66,    66,    67,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    74,    75,    75,    75,    75,
      76,    76,    76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     0,
       4,     2,     0,     0,     8,     0,     1,     3,     1,     2,
       0,     4,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     2,     5,     7,     5,
       7,     3,     3,     9,     1,     3,     0,     1,     1,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     1,
       2,     1,     1,     1,     1,     1,     4,     1,     3,     1,
       0,     1,     1,     1,     3,     1,     1,     1,     2,     2,
       1,     1,     1,     1
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
#line 2962 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2968 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2974 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2980 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2986 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2992 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2998 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3004 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3010 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3016 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3022 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3028 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3034 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3040 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3046 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3052 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3058 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3064 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3070 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3076 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_1: /* @1  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3082 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3088 "src/bison/grammar.c"
        break;

    case YYSYMBOL_43_2: /* @2  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3094 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3100 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3106 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3112 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3118 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3124 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3130 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3136 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3142 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3148 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3154 "src/bison/grammar.c"
        break;

    case YYSYMBOL_60_expression_opt: /* expression.opt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3160 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3166 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3172 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3178 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3184 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3190 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3196 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3202 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3208 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3214 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3220 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3226 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3232 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3238 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3244 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3250 "src/bison/grammar.c"
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
#line 3559 "src/bison/grammar.c"
    break;

  case 4: /* external_declaration_list: external_declaration_list external_declaration  */
#line 133 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 3565 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration  */
#line 134 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 3571 "src/bison/grammar.c"
    break;

  case 8: /* external_declaration: statement  */
#line 139 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[0].ast));
    }
#line 3581 "src/bison/grammar.c"
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
            Symbol *declared = context_declare_variable(current_context, (yyvsp[0].sym));
            symbol_update_type(declared, decl_type);
            (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 3607 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type id @1 ';'  */
#line 166 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 3615 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 169 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
    }
#line 3625 "src/bison/grammar.c"
    break;

  case 12: /* @2: %empty  */
#line 176 "src/bison/grammar.y"
                                   {
        p_ctx_name = 1;
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
            Symbol *declared = context_declare_function(previous_context, (yyvsp[-1].sym));
            if (!declared) {
                show_error((yylsp[-1]), BCYN "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
                (yyval.ast) = NULL;
            } else {
                symbol_update_type(declared, decl_type);
                (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
            }
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 3666 "src/bison/grammar.c"
    break;

  case 13: /* $@3: %empty  */
#line 211 "src/bison/grammar.y"
                         {
        // hack to save the scope of params and append to the scope of the body
        params_scope = scope_init_copy(stack_peek(&current_context->scopes));
        stack_pop(&current_context->scopes, free_scope_cb);
    }
#line 3676 "src/bison/grammar.c"
    break;

  case 14: /* func_declaration: type id '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 215 "src/bison/grammar.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = 1;
    }
#line 3686 "src/bison/grammar.c"
    break;

  case 15: /* param_list.opt: %empty  */
#line 222 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 3692 "src/bison/grammar.c"
    break;

  case 17: /* params_list: params_list ',' param_decl  */
#line 226 "src/bison/grammar.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3698 "src/bison/grammar.c"
    break;

  case 18: /* params_list: param_decl  */
#line 227 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3704 "src/bison/grammar.c"
    break;

  case 19: /* param_decl: type id  */
#line 230 "src/bison/grammar.y"
                    {
        symbol_update_context((yyvsp[0].sym), current_context);
        symbol_update_type((yyvsp[0].sym), symbol_type_from_str((yyvsp[-1].pchar)));
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        if (sym) {
            show_error_range((yylsp[0]), "redefinition of parameter " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            context_declare_variable(current_context, (yyvsp[0].sym));
            (yyval.ast) = ast_symref_init(symbol_init_copy((yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 3723 "src/bison/grammar.c"
    break;

  case 20: /* $@4: %empty  */
#line 246 "src/bison/grammar.y"
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
#line 3739 "src/bison/grammar.c"
    break;

  case 21: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 256 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 3751 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list.opt: block_item_list  */
#line 265 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 3757 "src/bison/grammar.c"
    break;

  case 23: /* block_item_list.opt: %empty  */
#line 266 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3763 "src/bison/grammar.c"
    break;

  case 24: /* block_item_list: block_item_list block_item  */
#line 269 "src/bison/grammar.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3769 "src/bison/grammar.c"
    break;

  case 25: /* block_item_list: block_item  */
#line 270 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3775 "src/bison/grammar.c"
    break;

  case 34: /* io_stmt: READ '(' id ')' ';'  */
#line 285 "src/bison/grammar.y"
                             {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(func)), ast_symref_init(symbol_init_copy(param)));
        symbol_free((yyvsp[-4].sym));
        symbol_free((yyvsp[-2].sym));
    }
#line 3787 "src/bison/grammar.c"
    break;

  case 35: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 292 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(sym)), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 3797 "src/bison/grammar.c"
    break;

  case 36: /* expr_stmt: expression ';'  */
#line 299 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 3803 "src/bison/grammar.c"
    break;

  case 37: /* cond_stmt: IF '(' expression ')' compound_stmt  */
#line 302 "src/bison/grammar.y"
                                                          {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 3811 "src/bison/grammar.c"
    break;

  case 38: /* cond_stmt: IF '(' expression ')' compound_stmt ELSE compound_stmt  */
#line 305 "src/bison/grammar.y"
                                                             {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3819 "src/bison/grammar.c"
    break;

  case 39: /* cond_stmt: IF '(' error ')' compound_stmt  */
#line 308 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[0].ast));
        yyerrok;
    }
#line 3830 "src/bison/grammar.c"
    break;

  case 40: /* cond_stmt: IF '(' error ')' compound_stmt ELSE compound_stmt  */
#line 314 "src/bison/grammar.y"
                                                        {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        yyerrok;
    }
#line 3842 "src/bison/grammar.c"
    break;

  case 41: /* jmp_stmt: RETURN expression ';'  */
#line 323 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 3848 "src/bison/grammar.c"
    break;

  case 42: /* jmp_stmt: RETURN error ';'  */
#line 324 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-2]), WHT "'return'" RESET " with no value\n");
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 3858 "src/bison/grammar.c"
    break;

  case 43: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 331 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3866 "src/bison/grammar.c"
    break;

  case 45: /* expression: unary_expr '=' logical_or_expr  */
#line 337 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3872 "src/bison/grammar.c"
    break;

  case 46: /* expression.opt: %empty  */
#line 340 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 3878 "src/bison/grammar.c"
    break;

  case 49: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 345 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3887 "src/bison/grammar.c"
    break;

  case 50: /* logical_or_expr: logical_or_expr OR error  */
#line 349 "src/bison/grammar.y"
                               {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 3897 "src/bison/grammar.c"
    break;

  case 51: /* logical_or_expr: error OR logical_and_expr  */
#line 354 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 3907 "src/bison/grammar.c"
    break;

  case 53: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 362 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3916 "src/bison/grammar.c"
    break;

  case 54: /* logical_and_expr: logical_and_expr AND error  */
#line 366 "src/bison/grammar.y"
                                 {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 3926 "src/bison/grammar.c"
    break;

  case 55: /* logical_and_expr: error AND eq_expr  */
#line 371 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 3936 "src/bison/grammar.c"
    break;

  case 57: /* eq_expr: eq_expr EQ rel_expr  */
#line 379 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3945 "src/bison/grammar.c"
    break;

  case 58: /* eq_expr: eq_expr EQ error  */
#line 383 "src/bison/grammar.y"
                       {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 3955 "src/bison/grammar.c"
    break;

  case 59: /* eq_expr: error EQ rel_expr  */
#line 388 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 3965 "src/bison/grammar.c"
    break;

  case 61: /* rel_expr: rel_expr REL list_expr  */
#line 396 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3974 "src/bison/grammar.c"
    break;

  case 62: /* rel_expr: rel_expr REL error  */
#line 400 "src/bison/grammar.y"
                         {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 3984 "src/bison/grammar.c"
    break;

  case 63: /* rel_expr: error REL list_expr  */
#line 405 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 3994 "src/bison/grammar.c"
    break;

  case 65: /* list_expr: add_expr DL_DG list_expr  */
#line 413 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4003 "src/bison/grammar.c"
    break;

  case 66: /* list_expr: add_expr COLON list_expr  */
#line 417 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4012 "src/bison/grammar.c"
    break;

  case 67: /* list_expr: add_expr DL_DG error  */
#line 421 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4022 "src/bison/grammar.c"
    break;

  case 68: /* list_expr: add_expr COLON error  */
#line 426 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4032 "src/bison/grammar.c"
    break;

  case 69: /* list_expr: error DL_DG list_expr  */
#line 431 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4042 "src/bison/grammar.c"
    break;

  case 70: /* list_expr: error COLON list_expr  */
#line 436 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4052 "src/bison/grammar.c"
    break;

  case 72: /* add_expr: add_expr ADD mult_expr  */
#line 444 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4061 "src/bison/grammar.c"
    break;

  case 73: /* add_expr: add_expr ADD error  */
#line 448 "src/bison/grammar.y"
                         {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4071 "src/bison/grammar.c"
    break;

  case 74: /* add_expr: error ADD mult_expr  */
#line 453 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4081 "src/bison/grammar.c"
    break;

  case 76: /* mult_expr: mult_expr MULT unary_expr  */
#line 461 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4090 "src/bison/grammar.c"
    break;

  case 77: /* mult_expr: mult_expr MULT error  */
#line 465 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4100 "src/bison/grammar.c"
    break;

  case 78: /* mult_expr: error MULT unary_expr  */
#line 470 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4110 "src/bison/grammar.c"
    break;

  case 80: /* unary_expr: unary_ops unary_expr  */
#line 478 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4119 "src/bison/grammar.c"
    break;

  case 86: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 491 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-3].sym));
        if (!sym) {
            show_error_range((yylsp[-3]), "implicit declaration of function " BBLU "'%s'\n" RESET, (yyvsp[-3].sym)->name);
            (yyval.ast) = NULL;
        } else {
            if (!sym->is_fn) {
                show_error_range((yylsp[-3]), "called object " BCYN "'%s'" RESET " is not a function\n", sym->name);
                (yyval.ast) = NULL;
            } else {
                (yyval.ast) = ast_funcall_init(ast_symref_init(symbol_init_copy(sym)), ast_params_init((yyvsp[-1].list)));
            }
        }
        symbol_free((yyvsp[-3].sym));
    }
#line 4139 "src/bison/grammar.c"
    break;

  case 87: /* arg_expr_list: expression  */
#line 508 "src/bison/grammar.y"
                          { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4145 "src/bison/grammar.c"
    break;

  case 88: /* arg_expr_list: arg_expr_list ',' expression  */
#line 509 "src/bison/grammar.y"
                                   { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 4151 "src/bison/grammar.c"
    break;

  case 90: /* arg_expr_list.opt: %empty  */
#line 513 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4157 "src/bison/grammar.c"
    break;

  case 91: /* primary_expr: id  */
#line 516 "src/bison/grammar.y"
                 {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[0].sym));
        if (!sym) {
            show_error_range((yylsp[0]), BCYN "'%s'" RESET " undeclared (first use in this function)\n", (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            symbol_update_context((yyvsp[0].sym), current_context);
            (yyval.ast) = ast_symref_init(symbol_init_copy(sym ? sym : (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
    }
#line 4173 "src/bison/grammar.c"
    break;

  case 94: /* primary_expr: '(' expression ')'  */
#line 529 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 4179 "src/bison/grammar.c"
    break;

  case 98: /* type: INT LIST  */
#line 537 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 4191 "src/bison/grammar.c"
    break;

  case 99: /* type: FLOAT LIST  */
#line 544 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 4203 "src/bison/grammar.c"
    break;

  case 100: /* constant: NUMBER_REAL  */
#line 553 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 4209 "src/bison/grammar.c"
    break;

  case 101: /* constant: NUMBER_INT  */
#line 554 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 4215 "src/bison/grammar.c"
    break;

  case 102: /* constant: NIL  */
#line 555 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 4221 "src/bison/grammar.c"
    break;

  case 103: /* string_literal: STR_LITERAL  */
#line 558 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 4230 "src/bison/grammar.c"
    break;


#line 4234 "src/bison/grammar.c"

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

#line 564 "src/bison/grammar.y"


void yyerror(int l, int c, const char *s, ...) {
    error_cursor = (Cursor){.line=l, .col=c};
    last_line_ref = curr_line_buffer;
    // enable error print when bison calls yyerror()
    /* if (s) CIPL_PERROR_CURSOR("%s\n", last_line_ref, error_cursor, s); */
    // prevent count up errors when bison calls yyerror()
    if (!s) {
        ++errors_count;
    }
}
