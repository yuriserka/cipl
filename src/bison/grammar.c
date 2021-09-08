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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6823

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  447

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
     478,   484,   485,   486,   487,   490,   491,   496,   497,   500,
     501,   504,   505,   506,   507,   510,   523,   526,   527,   528,
     535,   544,   545,   546,   549
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

#define YYPACT_NINF (-257)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-105)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     924,  1414,   242,   541,   840,  2321,   -21,   -18,  4834,  4852,
    4870,  4888,  1139,    10,    25,   -16,   -11,   409,   450,   964,
      60,  1041,  1080,  1223,  1267,  1340,  1379,  1522,  1566,  1639,
    1678,  1821,    50,    22,   174,   624,  1269,  1308,  2585,  6417,
    1438,  4906,  1737,  2360,  5045,  5053,     9,  2618,  5298,  4924,
     708,  1007,  1306,  1605,  2204,  1007,  1007,    63,   450,    14,
      30,  2309,   187,  6425,    59,    87,  1861,  -257,  1977,  2120,
    2771,  2831,  2940,  2997,  3157,  3245,  4123,  4144,  4165,  5325,
      72,  2237,    20,  6446,   115,  6454,  6475,   688,  1363,  2539,
     741,  1899,   520,   901,  1486,  1506,  1568,   100,   114,  5961,
     122,   155,   170,  2278,  2440,  5333,  2471,    47,  2559,  2693,
    2731,    38,  6483,   605,  6504,   923,  6512,  1607,  6533,  1662,
    6541,  6562,  6570,  1785,  6591,  1805,  6599,  6620,   110,   130,
     164,   171,   135,   198,   202,   239,   237,   237,   187,  3112,
    3275,   251,  4186,  5360,   208,  3318,  3352,  3390,   370,   625,
     272,   177,   203,   205,   310,   232,   274,   274,   116,   276,
     377,   402,  3421,  3452,   284,   274,   416,   329,  3483,  3514,
    1713,  2870,  5368,  5395,  3138,  5403,   450,    34,    40,   138,
     300,   371,  2530,  5984,  5430,  4942,  5438,  5465,  5080,  5088,
    5473,  5500,   429,  6628,  6649,  6657,  3301,  6678,   450,  4924,
    6686,  6707,  6387,  6395,  6715,  6736,   287,   295,   308,   313,
     321,  4207,   964,  3545,  3579,  3613,  3647,  3681,  3715,   325,
    2012,  2100,  5115,  5123,  1932,  5150,   450,    32,   128,   418,
      73,   169,   209,  1404,  5158,  4960,  5185,  5193,  5008,  5018,
    5220,  5228,  4978,  4228,  4249,  4270,  4291,  4312,  4249,  4249,
     338,  3749,   964,   340,   106,   131,   440,   298,   341,  4333,
    4354,  4375,  4396,  4417,  4438,  4459,  4480,  4501,  5508,    72,
     350,  6744,    72,    63,   450,  4522,   187,  6765,   357,  1861,
    3783,  4996,  4543,  4564,  4585,  4606,  4627,  4564,  4564,   362,
    4648,  4669,  4690,  4711,  4732,  4753,  4774,  4795,  4816,  5255,
      72,  5992,  6015,  6023,  5922,  6046,   450,  6054,  4978,  6077,
    6085,  5930,  5953,  6108,  6116,   392,  6139,  6147,  1013,   465,
    2601,   610,  2002,    43,  1200,   475,   670,   766,  1861,  3817,
     398,   405,  5535,  6170,    94,  6178,   649,  6201,   817,  6209,
    1065,  6232,  6240,  6263,  1116,  6271,  1187,  6294,  6302,    70,
     385,  6773,   389,   411,   421,  6325,   443,   379,  3851,  3885,
     406,  1703,  1944,  5570,    84,  5578,   450,  5602,  4996,  5610,
    5634,   807,  1105,  5642,  5666,   427,  5674,  5698,  1286,   201,
    2921,   948,  2853,   332,  1890,   291,   451,   480,  5263,  5706,
     393,  5730,  1207,  5738,   589,  5762,   710,  5770,  5794,  5802,
     888,  5826,   989,  5834,  5858,    96,   454,   464,  6333,    72,
     447,  5543,  6794,   470,   479,   476,   476,   187,  3919,   482,
    5866,    72,  5290,  6356,   489,   669,  3953,  3987,   964,   497,
     742,   499,  5890,   495,  6364,  1861,   496,   496,   116,  5898,
     501,  4021,  4055,   505,   781,  2505,  4089
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
       0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -257,  -257,  -257,   516,    13,   397,  -257,  -257,  -257,  -257,
    -257,   380,     7,  -210,  -256,  -257,   431,     1,     3,     4,
       6,     8,    11,  1907,  -128,    52,  2968,  2911,  2533,  2376,
    2798,  2628,  2118,   299,   598,  -257,  -232,   897,  1196,     0,
       5,  1495,  1794
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    20,    21,    22,   106,   133,    24,   144,   165,   152,
     153,   154,   213,    66,   107,   108,   109,   110,   214,   215,
     216,   217,   218,   129,   102,    33,    34,    35,    36,    37,
      38,    39,    40,   199,   200,   130,   131,   201,   202,   203,
     111,   204,   205
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    26,   279,    27,    28,    46,    29,    25,    30,    57,
     150,    31,    58,    23,    61,   192,   -97,    45,   189,    62,
     -99,    45,    26,   360,    27,    28,    46,    29,    25,    30,
     164,   -98,    31,    59,    23,    70,  -100,   350,    81,   -97,
     352,    45,   328,   -99,   250,   290,    82,   259,    60,    -9,
     132,   -44,   260,   -48,   -98,   260,   -51,    97,   189,  -100,
      67,   189,    45,   -44,   -44,   -44,    45,   251,   406,   206,
     177,   -48,   410,   220,   -51,   221,   222,   223,   224,    69,
     239,   139,     8,   259,   293,   -56,   -56,   -56,   104,     9,
      10,    11,   225,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -45,   226,   -90,   -56,   -56,   260,   -49,    45,   290,
     177,   141,   -97,   177,   -96,   -96,   -96,   170,   105,   171,
     172,   173,   174,    70,    49,   -49,     8,   -45,   -45,   330,
     128,   134,   227,     9,    10,    11,   175,   -98,    45,   -45,
     291,   -48,   239,   148,   149,   135,   176,   -46,   357,   155,
     -52,   -52,   261,   137,   331,   161,   -12,   -12,   189,   -48,
     -48,   -87,   -87,   162,   163,   155,   -12,    45,   169,   -52,
      27,    28,   168,    29,    25,    30,   189,   424,    31,   440,
     -60,   -60,   -60,   -60,   -47,   189,    71,   -48,     1,   433,
       2,     3,     4,     5,   227,   -89,   142,     8,   189,   138,
     -60,   -60,   143,   -48,     9,    10,    11,    12,   -88,   -88,
     177,    45,   -63,   -63,   -63,   -63,   -46,    18,   435,   294,
     -64,   -64,   -64,   -64,   295,   296,   189,   145,   177,   254,
     255,   146,   -63,   -63,   159,   239,   -16,   160,   256,   -15,
     -64,   -64,   312,   312,   312,   312,   312,   312,   312,   312,
     177,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   147,   239,
     252,  -102,   239,   353,   189,   189,    45,  -102,   177,    45,
      -9,   372,   372,   372,   372,   372,   372,   372,   372,   431,
     372,   372,   372,   372,   372,   372,   372,   372,   372,    41,
     239,   158,   293,   -59,   -59,   -59,   189,    19,   312,   -13,
     443,   262,   -56,   -56,   -56,   167,    41,   185,   -96,   349,
      41,   227,   -59,   -59,   227,   273,   177,   177,    45,   -47,
       1,   -56,     2,     3,     4,     5,     6,     7,   274,     8,
      41,   -18,   -18,   275,   291,   -51,     9,    10,    11,    12,
     405,   276,   227,    15,   280,    16,    17,   185,   177,    18,
     185,    41,    19,   -51,   -51,    41,   189,   -96,   372,   329,
     -39,   -39,   332,   -39,   -39,   -39,   -39,   -39,   -39,   235,
     -39,   351,   -60,   -60,   -60,   -60,   359,   -39,   -39,   -39,
     -39,   -39,   -39,   388,   -39,   156,   -39,   -39,   254,   255,
     -39,   242,   -60,   -39,   -99,   291,   -49,    41,   417,   239,
      63,  -100,     2,     3,     4,     5,   411,    45,   177,     8,
     412,   239,   429,   430,   -49,   -49,     9,    10,    11,    12,
     -52,   -52,   292,   -19,   -19,    45,   281,    41,   189,    18,
     418,   235,   413,   441,   442,    45,   446,   -17,   -17,   -52,
     -52,   170,   414,   171,   172,   173,   174,   185,   -96,   -96,
       8,   227,   -70,   -70,   -70,   -70,    41,     9,    10,    11,
     175,   -96,   -96,   227,   416,   185,   -63,   -63,   -63,   -63,
     176,   425,   -70,   -70,   185,   422,   262,   -59,   -59,   -59,
     177,   -69,   -69,   -69,   -69,   423,   -63,   185,   -39,   426,
     -39,   -39,   -39,   -39,   -39,   -39,   -59,   -39,   427,   428,
      41,   -69,   -69,   432,   -39,   -39,   -39,   -39,   -39,   -39,
     434,   -39,   436,   -39,   -39,   185,   439,   -39,   438,   212,
     -39,   -39,    71,   -51,   235,   444,   445,    68,   253,   140,
     166,   308,   308,   308,   308,   308,   308,   308,   308,   -51,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,   308,   308,
     308,   308,   308,   308,   308,   308,   308,     0,   235,     0,
    -103,   235,     0,   185,   185,    41,  -103,     0,    41,     0,
     368,   368,   368,   368,   368,   368,   368,   368,     0,   368,
     368,   368,   368,   368,   368,   368,   368,   368,    42,   235,
     293,   -57,   -57,   -57,     0,   185,     0,   308,     0,     0,
       0,     0,     0,     0,     0,    42,   186,    71,   -49,    42,
     -57,   -57,   -55,   -55,   261,   -37,   -37,    41,   -37,   -37,
     -37,   -37,   -37,   -37,   -49,   -37,   -52,   -52,    72,    42,
       0,   -55,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,
     157,   -37,   -37,   -52,     0,   -37,   186,     0,   -37,   186,
      42,   -53,   -53,   261,    42,   185,     0,   368,     0,   -21,
     -21,     0,   -21,   -21,   -21,   -21,   -21,   -21,   236,   -21,
     -53,   -70,   -70,   -70,   -70,     0,   -21,   -21,   -21,   -21,
     -21,   -21,     0,   -21,   -21,   -21,   -21,    49,    50,   -21,
       0,   -70,   -21,    55,    56,     0,    42,     0,   235,    84,
       0,   193,   194,   195,   196,     0,    41,     0,     8,     0,
     235,   -61,   -61,   -61,   -61,     9,    10,    11,   197,     0,
       0,     0,     0,     0,    41,     0,    42,   185,   198,     0,
     236,   -61,   -61,   -37,    41,   -37,   -37,   -37,   -37,   -37,
     -37,     0,   -37,   -55,   -55,    72,   186,     0,     0,   -37,
     -37,   -37,   -37,   -37,   -37,    42,   -37,   437,   -37,   -37,
     -55,     0,   -37,     0,   186,   -37,   -37,   -69,   -69,   -69,
     -69,     0,   -21,   186,   -21,   -21,   -21,   -21,   -21,   -21,
       0,   -21,     0,     0,     0,     0,   186,   -69,   -21,   -21,
     -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,   -21,    42,
       0,   -21,     0,     0,   -21,   -21,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   186,     0,     0,     0,   262,   -57,
     -57,   -57,     0,   236,     0,     0,     0,   421,   -91,   -91,
     309,   309,   309,   309,   309,   309,   309,   309,   -57,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,   309,   309,   309,
     309,   309,   309,   309,   309,   309,     0,   236,     0,  -101,
     236,     0,   186,   186,    42,  -101,     0,    42,     0,   369,
     369,   369,   369,   369,   369,   369,   369,     0,   369,   369,
     369,   369,   369,   369,   369,   369,   369,    43,   236,   -66,
     -66,   -66,   -66,     0,   186,     0,   309,     0,     0,     0,
      49,    50,    51,     0,    43,   187,    55,    56,    43,   -66,
     -66,     0,     0,     0,    -3,     1,    42,     2,     3,     4,
       5,     6,     7,     0,     8,   -53,   -53,    72,    43,     0,
       0,     9,    10,    11,    12,    13,    14,     0,    15,     0,
      16,    17,   -53,     0,    18,   187,     0,    19,   187,    43,
     -55,   -55,   292,    43,   186,   -20,   369,   -20,   -20,   -20,
     -20,   -20,   -20,     0,   -20,     0,     0,   237,     0,   -55,
     -55,   -20,   -20,   -20,   -20,   -20,   -20,     0,   -20,     0,
     -20,   -20,     0,     0,   -20,     0,     0,   -20,   -20,     0,
     -65,   -65,   -65,   -65,     0,    43,     0,   236,    87,     0,
     193,   194,   195,   196,     0,    42,     0,     8,     0,   236,
     -65,   -65,   242,   243,     9,    10,    11,   197,   248,   249,
       0,     0,     0,    42,     0,    43,   186,   198,     0,   237,
       0,    -2,     1,    42,     2,     3,     4,     5,     6,     7,
       0,     8,     0,     0,     0,   187,     0,     0,     9,    10,
      11,    12,    13,    14,    43,    15,     0,    16,    17,     0,
       0,    18,     0,   187,    19,     0,   -61,   -61,   -61,   -61,
      -5,    -5,   187,    -5,    -5,    -5,    -5,    -5,    -5,     0,
      -5,     0,     0,     0,     0,   187,   -61,    -5,    -5,    -5,
      -5,    -5,    -5,     0,    -5,     0,    -5,    -5,    43,     0,
      -5,     0,     0,    -5,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,     0,   187,     0,     0,     0,   -66,   -66,   -66,
     -66,     0,   237,     0,     0,   -95,   -95,   -95,     0,   310,
     310,   310,   310,   310,   310,   310,   310,   -66,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,   310,   310,   310,   310,
     310,   310,   310,   310,   310,     0,   237,     0,  -104,   237,
       0,   187,   187,    43,  -104,     0,    43,     0,   370,   370,
     370,   370,   370,   370,   370,   370,     0,   370,   370,   370,
     370,   370,   370,   370,   370,   370,    44,   237,   -65,   -65,
     -65,   -65,     0,   187,     0,   310,     0,     0,     0,   242,
     243,   244,     0,    44,   188,   248,   249,    44,   -65,   -53,
     -53,   292,     0,    -7,    -7,    43,    -7,    -7,    -7,    -7,
      -7,    -7,     0,    -7,     0,     0,     0,    44,   -53,   -53,
      -7,    -7,    -7,    -7,    -7,    -7,     0,    -7,     0,    -7,
      -7,     0,     0,    -7,   188,     0,    -7,   188,    44,     0,
       0,     0,    44,   187,     0,   370,     0,    -6,    -6,     0,
      -6,    -6,    -6,    -6,    -6,    -6,   238,    -6,     0,     0,
      73,   -56,   -56,   -56,    -6,    -6,    -6,    -6,    -6,    -6,
       0,    -6,     0,    -6,    -6,   281,   282,    -6,   -56,     0,
      -6,   287,   288,     0,    44,     0,   237,    89,     0,   193,
     194,   195,   196,     0,    43,     0,     8,     0,   237,   -60,
     -60,   -60,   -60,     9,    10,    11,   197,     0,     0,     0,
       0,     0,    43,     0,    44,   187,   198,   -60,   238,     0,
     -29,   -29,    43,   -29,   -29,   -29,   -29,   -29,   -29,     0,
     -29,     0,     0,     0,   188,     0,     0,   -29,   -29,   -29,
     -29,   -29,   -29,    44,   -29,     0,   -29,   -29,     0,     0,
     -29,     0,   188,   -29,   -63,   -63,   -63,   -63,     0,    -8,
      -8,   188,    -8,    -8,    -8,    -8,    -8,    -8,     0,    -8,
       0,     0,   -63,     0,   188,     0,    -8,    -8,    -8,    -8,
      -8,    -8,     0,    -8,     0,    -8,    -8,    44,     0,    -8,
       0,     0,    -8,   297,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,     0,   188,    49,    50,    51,    52,    53,    54,    55,
      56,   238,     0,     0,     0,   -71,   -71,     0,   311,   311,
     311,   311,   311,   311,   311,   311,     0,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   311,   311,   311,   311,   311,
     311,   311,   311,   311,     0,   238,     0,   -75,   238,     0,
     188,   188,    44,    78,     0,    44,     0,   371,   371,   371,
     371,   371,   371,   371,   371,     0,   371,   371,   371,   371,
     371,   371,   371,   371,   371,    47,   238,    73,   -59,   -59,
     -59,     0,   188,     0,   311,     0,     0,     0,     0,     0,
       0,     0,    47,   190,     0,   -59,    47,   -70,   -70,   -70,
     -70,     0,   -33,   -33,    44,   -33,   -33,   -33,   -33,   -33,
     -33,     0,   -33,     0,     0,   -70,    47,     0,     0,   -33,
     -33,   -33,   -33,   -33,   -33,     0,   -33,     0,   -33,   -33,
       0,     0,   -33,   190,     0,   -33,   190,    47,     0,     0,
       0,    47,   188,     0,   371,     0,   -28,   -28,     0,   -28,
     -28,   -28,   -28,   -28,   -28,   240,   -28,     0,     0,   -69,
     -69,   -69,   -69,   -28,   -28,   -28,   -28,   -28,   -28,     0,
     -28,     0,   -28,   -28,     0,     0,   -28,   -69,     0,   -28,
       0,     0,     0,    47,     0,   238,    91,     0,   193,   194,
     195,   196,     0,    44,     0,     8,     0,   238,    73,   -57,
     -57,   -57,     9,    10,    11,   197,     0,     0,     0,     0,
       0,    44,     0,    47,   188,   198,   -57,   240,     0,   -30,
     -30,    44,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,
       0,     0,     0,   190,     0,     0,   -30,   -30,   -30,   -30,
     -30,   -30,    47,   -30,     0,   -30,   -30,     0,     0,   -30,
       0,   190,   -30,   -61,   -61,   -61,   -61,     0,   -31,   -31,
     190,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,     0,
       0,   -61,     0,   190,     0,   -31,   -31,   -31,   -31,   -31,
     -31,     0,   -31,     0,   -31,   -31,    47,     0,   -31,     0,
       0,   -31,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
       0,   190,   242,   243,   244,   245,   246,   247,   248,   249,
     240,     0,     0,     0,  -102,  -102,     0,   313,   313,   313,
     313,   313,   313,   313,   313,     0,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   313,   313,   313,   313,   313,   313,
     313,   313,   313,     0,   240,     0,   -79,   240,     0,   190,
     190,    47,   -79,     0,    47,     0,   373,   373,   373,   373,
     373,   373,   373,   373,     0,   373,   373,   373,   373,   373,
     373,   373,   373,   373,    48,   240,   -66,   -66,   -66,   -66,
       0,   190,     0,   313,     0,     0,     0,     0,     0,     0,
       0,    48,   191,     0,   -66,    48,   -65,   -65,   -65,   -65,
       0,   -32,   -32,    47,   -32,   -32,   -32,   -32,   -32,   -32,
       0,   -32,     0,     0,   -65,    48,     0,     0,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,     0,   -32,   -32,     0,
       0,   -32,   191,     0,   -32,   191,    48,     0,     0,     0,
      48,   190,     1,   373,     2,     3,     4,     5,   207,   208,
       0,     8,     0,     0,   241,     0,     0,     0,     9,    10,
      11,    12,    13,    14,     0,   209,     0,   210,   211,     0,
       0,    18,     0,     0,   212,   -23,     0,     0,     0,   281,
     282,   283,    48,     0,   240,   287,   288,    32,    49,    50,
      51,    52,    47,    54,    55,    56,   240,     0,     0,     0,
       0,     0,     0,     0,    64,    65,     0,     0,    32,     0,
      47,     0,    48,   190,     0,     0,   241,     0,     0,     0,
      47,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,
       0,     0,   191,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,    48,   -96,   -96,   -96,    98,     0,   -96,   100,   101,
     191,     0,     0,   219,     0,  -103,  -103,    -4,    -4,   191,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,     0,
       0,     0,   191,     0,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,     0,    -4,    -4,    48,     0,    -4,     0,     0,
      -4,   242,   243,   244,   245,   219,   247,   248,   249,     0,
     191,   281,   282,   283,   284,   285,   286,   287,   288,   241,
       0,     0,     0,     0,     0,     0,   314,   314,   314,   314,
     314,   314,   314,   314,     0,   101,     0,     0,     0,   151,
       0,     0,     0,   314,   314,   314,   314,   314,   314,   314,
     314,   314,     0,   241,     0,   257,   241,     0,   191,   191,
      48,     0,     0,    48,    32,   374,   374,   374,   374,   374,
     374,   374,   374,   258,   374,   374,   374,   374,   374,   374,
     374,   374,   374,     0,   241,     0,     0,     0,     0,     0,
     191,     0,   314,     0,     0,   270,     0,     0,     0,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,   278,     0,
     -36,   -36,    48,   -36,   -36,   -36,   -36,   -36,   -36,     0,
     -36,  -102,  -102,   289,     0,  -102,   184,   -36,   -36,   -36,
     -36,   -36,   -36,     0,   -36,     0,   -36,   -36,     0,     0,
     -36,     0,     0,   -36,     0,     0,     0,     0,     0,    79,
     191,     0,   374,     0,     0,     0,     0,    83,    86,    86,
      86,    86,    86,    86,    86,     0,   184,     0,     0,   184,
       0,   354,   356,   101,     0,     0,   219,     0,    86,    86,
      86,    86,    86,    86,    86,   127,    86,     0,   234,     0,
       0,     0,     0,   241,     0,    93,     0,   193,   194,   195,
     196,    48,     0,   407,     8,   241,     0,     0,     0,     0,
       0,     9,    10,    11,   197,     0,     0,     0,     0,    48,
       0,     0,   191,     0,   198,   219,     0,   -11,   -11,    48,
     -11,   -11,   -11,   -11,   -11,   -11,     0,   -11,     0,     0,
       0,     0,     0,     0,   -11,   -11,   -11,   -11,   -11,   -11,
     234,   -11,     0,   -11,   -11,     0,     0,   -11,     0,     0,
     -11,     0,     0,   419,     0,     0,   184,     0,   -42,   -42,
       0,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,     0,
       0,     0,     0,     0,   184,   -42,   -42,   -42,   -42,   -42,
     -42,     0,   -42,   268,   -42,   -42,     0,     0,   -42,     0,
      99,   -42,   171,   172,   173,   174,   184,   271,     0,     8,
       0,     0,     0,     0,   101,     0,     9,    10,    11,   175,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,   176,
       0,     0,   219,     0,   184,   257,     0,     0,     0,     0,
     -96,   -96,   219,   299,     0,     0,   -96,     0,     0,     0,
     307,   317,   317,   317,   317,   317,   317,   317,     0,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   317,   317,   317,
     317,   317,   317,   317,   348,   317,     0,   234,     0,   -85,
     234,     0,   184,   184,   181,   -85,     0,     0,     0,   367,
     377,   377,   377,   377,   377,   377,   377,     0,   377,   377,
     377,   377,   377,   377,   377,   404,   377,     0,   234,     0,
       0,     0,     0,     0,   184,     0,   408,    88,     0,     0,
       0,    95,    96,     0,   181,     0,     0,   181,     0,     0,
     -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,   119,
     -41,   123,   125,     0,     0,     0,   231,   -41,   -41,   -41,
     -41,   -41,   -41,     0,   -41,     0,   -41,   -41,     0,     0,
     -41,     0,   -26,   -41,   -26,   -26,   -26,   -26,   -26,   -26,
       0,   -26,     0,     0,   184,     0,   420,     0,   -26,   -26,
     -26,   -26,   -26,   -26,     0,   -26,     0,   -26,   -26,     0,
       0,   -26,     0,     0,   -26,   -26,     1,     0,     2,     3,
       4,     5,   207,   208,     0,     8,     0,     0,   231,     0,
       0,     0,     9,    10,    11,    12,     0,   234,     0,   209,
       0,   210,   211,     0,   181,    18,     0,     0,   212,   234,
     263,   -64,   -64,   -64,   -64,   264,   265,     0,    49,    50,
      51,   180,   181,    54,    55,    56,   184,     0,     0,     0,
       1,   -64,     2,     3,     4,     5,   207,   208,     0,     8,
       0,     0,     0,     0,   181,     0,     9,    10,    11,    12,
      13,    14,     0,   209,     0,   210,   211,    94,     0,    18,
       0,   180,   212,   -22,   180,    74,   -64,   -64,   -64,   -64,
      75,    76,   181,     0,     0,   117,     0,     0,     0,     0,
     242,   243,   244,   230,   -64,   247,   248,   249,     0,     0,
     319,   181,   181,   181,   326,   327,     0,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   181,   181,   181,   340,     0,
     344,   346,     0,   181,     0,   231,   183,   -92,   231,     0,
     181,   181,     0,   -92,     0,     0,     0,     0,     0,   379,
     231,   231,   231,   386,   387,     0,   231,   231,   231,   396,
       0,   400,   402,     0,   231,   230,   231,     0,    85,     0,
       0,     0,   181,     0,     0,     0,   183,     0,     0,   183,
       0,   180,     0,     0,   -25,     0,   -25,   -25,   -25,   -25,
     -25,   -25,   121,   -25,     0,     0,     0,     0,   233,   180,
     -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,     0,   -25,
     -25,     0,     0,   -25,     0,     0,   -25,   -25,     0,     0,
       0,   180,   -27,     0,   -27,   -27,   -27,   -27,   -27,   -27,
       0,   -27,   181,     0,     0,     0,     0,     0,   -27,   -27,
     -27,   -27,   -27,   -27,     0,   -27,     0,   -27,   -27,   180,
       0,   -27,     0,     0,   -27,   -27,     0,     0,     0,     0,
     233,     0,   112,     0,   193,   194,   195,   196,   180,   180,
     325,     8,     0,     0,     0,   231,   183,     0,     9,    10,
      11,   197,   180,   180,   338,     0,     0,   231,     0,     0,
     180,   198,   230,     0,   183,   230,     0,   180,   180,     0,
       0,     0,     0,     0,   181,     0,   182,   230,   230,   385,
       0,     0,     0,   230,   230,   394,   183,     0,     0,     0,
       0,   230,   114,   230,   193,   194,   195,   196,     0,   180,
       0,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   197,     0,     0,   183,     0,   182,     0,     0,   182,
       0,   198,   281,   282,   283,   284,     0,   286,   287,   288,
       0,   316,   183,   183,   183,   183,   183,   183,   232,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,   183,   183,   183,
     183,   342,   183,   183,     0,   183,     0,   233,     0,   180,
     233,  -102,   183,   183,     0,  -102,     0,     0,     0,     0,
     376,   233,   233,   233,   233,   233,   233,     0,   233,   233,
     233,   233,   398,   233,   233,     0,   233,     0,   233,   179,
     281,   282,   283,     0,   183,   286,   287,   288,     0,     0,
     232,   116,   230,   193,   194,   195,   196,     0,     0,     0,
       8,     0,     0,     0,   230,     0,   182,     9,    10,    11,
     197,     0,     0,    90,     0,     0,     0,     0,     0,   179,
     198,   180,   179,     0,   182,     0,     0,     0,     0,     0,
       0,     0,   115,     0,     0,     0,   178,     0,     0,     0,
       0,   229,     0,     0,   183,     0,   182,     0,   118,     0,
     193,   194,   195,   196,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   197,     0,     0,
       0,    92,     0,     0,   182,     0,   178,   198,     0,   178,
       0,     0,     0,     0,     0,     0,     0,   233,   113,     0,
       0,     0,   182,   182,   182,   182,   182,   182,   228,   233,
       0,     0,     0,   229,     0,     0,     0,   182,   182,   182,
     182,     0,   182,   182,     0,   182,   183,   232,     0,   179,
     232,     0,   182,   182,     0,     0,     0,     0,     0,     0,
       0,   232,   232,   232,   232,   232,   232,   179,   232,   232,
     232,   232,     0,   232,   232,     0,   232,     0,   232,     0,
       0,     0,     0,     0,   182,     0,     0,     0,     0,   179,
     228,     0,   -21,   -21,     0,   -21,   -21,   -21,   -21,   -21,
     -21,     0,   -21,     0,     0,     0,   178,     0,     0,   -21,
     -21,   -21,   -21,   -21,   -21,     0,   -21,   179,   -21,   -21,
       0,     0,   -21,     0,   178,   -21,     0,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,     0,   321,   179,   120,     0,
     193,   194,   195,   196,   182,     0,   178,     8,   -96,   -96,
     179,   336,     0,   -96,     9,    10,    11,   197,   179,     0,
     229,     0,     0,   229,     0,   179,   179,   198,     0,     0,
       0,     0,     0,     0,   178,   381,   229,     0,     0,     0,
       0,   229,   392,     0,     0,     0,     0,   232,     0,   229,
       0,   229,     0,     0,   323,     0,     0,   179,     0,   232,
       0,     0,     0,     0,     0,     0,     0,   334,     0,     0,
       0,     0,     0,     0,     0,   178,   182,   228,     0,     0,
     228,     0,   178,   178,     0,     0,   122,     0,   193,   194,
     195,   196,     0,   383,     0,     8,     0,     0,   390,     0,
       0,     0,     9,    10,    11,   197,   228,     0,   228,     0,
       0,     0,     0,     0,   178,   198,   -24,   179,   -24,   -24,
     -24,   -24,   -24,   -24,     0,   -24,     0,     0,     0,     0,
       0,     0,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,
       0,   -24,   -24,     0,     0,   -24,     0,     0,   -24,   -24,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -10,   -10,
     229,   -10,   -10,   -10,   -10,   -10,   -10,     0,   -10,     0,
     -96,   -96,   229,     0,   178,   -10,   -10,   -10,   -10,   -10,
     -10,     0,   -10,     0,   -10,   -10,     0,     0,   -10,   179,
       0,   -10,   -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,
     -34,     0,   -34,     0,     0,     0,     0,     0,     0,   -34,
     -34,   -34,   -34,   -34,   -34,     0,   -34,   228,   -34,   -34,
       0,     0,   -34,     0,     0,   -34,     0,     0,     0,   228,
     -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
     -35,     0,     0,     0,     0,     0,   178,   -35,   -35,   -35,
     -35,   -35,   -35,     0,   -35,     0,   -35,   -35,     0,     0,
     -35,   -40,   -40,   -35,   -40,   -40,   -40,   -40,   -40,   -40,
       0,   -40,     0,     0,     0,     0,     0,     0,   -40,   -40,
     -40,   -40,   -40,   -40,     0,   -40,     0,   -40,   -40,     0,
       0,   -40,   -38,   -38,   -40,   -38,   -38,   -38,   -38,   -38,
     -38,     0,   -38,     0,     0,     0,     0,     0,     0,   -38,
     -38,   -38,   -38,   -38,   -38,     0,   -38,     0,   -38,   -38,
       0,     0,   -38,   -14,   -14,   -38,   -14,   -14,   -14,   -14,
     -14,   -14,     0,   -14,     0,     0,     0,     0,     0,     0,
     -14,   -14,   -14,   -14,   -14,   -14,     0,   -14,     0,   -14,
     -14,     0,     0,   -14,   -43,   -43,   -14,   -43,   -43,   -43,
     -43,   -43,   -43,     0,   -43,     0,     0,     0,     0,     0,
       0,   -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,     0,
     -43,   -43,     0,     0,   -43,     0,   -29,   -43,   -29,   -29,
     -29,   -29,   -29,   -29,     0,   -29,     0,     0,     0,     0,
       0,     0,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,
       0,   -29,   -29,     0,     0,   -29,     0,     0,   -29,   -29,
     -33,     0,   -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,
       0,     0,     0,     0,     0,     0,   -33,   -33,   -33,   -33,
     -33,   -33,     0,   -33,     0,   -33,   -33,     0,     0,   -33,
       0,     0,   -33,   -33,   -28,     0,   -28,   -28,   -28,   -28,
     -28,   -28,     0,   -28,     0,     0,     0,     0,     0,     0,
     -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,     0,   -28,
     -28,     0,     0,   -28,     0,     0,   -28,   -28,   -30,     0,
     -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,     0,     0,
       0,     0,     0,     0,   -30,   -30,   -30,   -30,   -30,   -30,
       0,   -30,     0,   -30,   -30,     0,     0,   -30,     0,     0,
     -30,   -30,   -31,     0,   -31,   -31,   -31,   -31,   -31,   -31,
       0,   -31,     0,     0,     0,     0,     0,     0,   -31,   -31,
     -31,   -31,   -31,   -31,     0,   -31,     0,   -31,   -31,     0,
       0,   -31,     0,     0,   -31,   -31,   -32,     0,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,     0,     0,     0,     0,
       0,     0,   -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,
       0,   -32,   -32,     0,     0,   -32,     0,     0,   -32,   -32,
     -11,     0,   -11,   -11,   -11,   -11,   -11,   -11,     0,   -11,
       0,     0,     0,     0,     0,     0,   -11,   -11,   -11,   -11,
     -11,   -11,     0,   -11,     0,   -11,   -11,     0,     0,   -11,
       0,     0,   -11,   -11,   -36,     0,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,     0,     0,     0,     0,     0,     0,
     -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,     0,   -36,
     -36,     0,     0,   -36,     0,     0,   -36,   -36,   -10,     0,
     -10,   -10,   -10,   -10,   -10,   -10,     0,   -10,     0,     0,
       0,     0,     0,     0,   -10,   -10,   -10,   -10,   -10,   -10,
       0,   -10,     0,   -10,   -10,     0,     0,   -10,     0,     0,
     -10,   -10,   -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,
       0,   -42,     0,     0,     0,     0,     0,     0,   -42,   -42,
     -42,   -42,   -42,   -42,     0,   -42,     0,   -42,   -42,     0,
       0,   -42,     0,     0,   -42,   -42,   -41,     0,   -41,   -41,
     -41,   -41,   -41,   -41,     0,   -41,     0,     0,     0,     0,
       0,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,   -41,
       0,   -41,   -41,     0,     0,   -41,     0,     0,   -41,   -41,
     -21,     0,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,
       0,     0,     0,     0,     0,     0,   -21,   -21,   -21,   -21,
     -21,   -21,     0,   -21,     0,   -21,   -21,     0,     0,   -21,
       0,     0,   -21,   -21,   -34,     0,   -34,   -34,   -34,   -34,
     -34,   -34,     0,   -34,     0,     0,     0,     0,     0,     0,
     -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,     0,   -34,
     -34,     0,     0,   -34,     0,     0,   -34,   -34,   -35,     0,
     -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,     0,     0,
       0,     0,     0,     0,   -35,   -35,   -35,   -35,   -35,   -35,
       0,   -35,     0,   -35,   -35,     0,     0,   -35,     0,     0,
     -35,   -35,   -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,
       0,   -40,     0,     0,     0,     0,     0,     0,   -40,   -40,
     -40,   -40,   -40,   -40,     0,   -40,     0,   -40,   -40,     0,
       0,   -40,     0,     0,   -40,   -40,   -38,     0,   -38,   -38,
     -38,   -38,   -38,   -38,     0,   -38,     0,     0,     0,     0,
       0,     0,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,
       0,   -38,   -38,     0,     0,   -38,     0,     0,   -38,   -38,
     -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,
       0,     0,     0,     0,     0,     0,   -43,   -43,   -43,   -43,
     -43,   -43,     0,   -43,     0,   -43,   -43,     0,     0,   -43,
       0,     0,   -43,   -43,   124,     0,   193,   194,   195,   196,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   197,     0,   126,     0,   193,   194,   195,
     196,     0,     0,   198,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   197,     0,     1,     0,   193,   194,
     195,   196,     0,     0,   198,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   197,     0,   220,     0,   221,
     222,   223,   224,     0,     0,   198,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   225,     0,   277,     0,
       2,     3,     4,     5,     0,     0,   226,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,    12,     0,   315,
       0,   301,   302,   303,   304,     0,     0,    18,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   305,     0,
     318,     0,   301,   302,   303,   304,     0,     0,   306,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   305,
       0,   320,     0,   301,   302,   303,   304,     0,     0,   306,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     305,     0,   322,     0,   301,   302,   303,   304,     0,     0,
     306,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   305,     0,   324,     0,   301,   302,   303,   304,     0,
       0,   306,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   305,     0,   333,     0,   301,   302,   303,   304,
       0,     0,   306,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   305,     0,   335,     0,   301,   302,   303,
     304,     0,     0,   306,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   305,     0,   337,     0,   301,   302,
     303,   304,     0,     0,   306,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   305,     0,   339,     0,   301,
     302,   303,   304,     0,     0,   306,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   305,     0,   341,     0,
     301,   302,   303,   304,     0,     0,   306,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   305,     0,   343,
       0,   301,   302,   303,   304,     0,     0,   306,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   305,     0,
     345,     0,   301,   302,   303,   304,     0,     0,   306,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   305,
       0,   347,     0,   301,   302,   303,   304,     0,     0,   306,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     305,     0,   170,     0,   301,   302,   303,   304,     0,     0,
     306,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   305,     0,   355,     0,   171,   172,   173,   174,     0,
       0,   306,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   175,     0,   375,     0,   361,   362,   363,   364,
       0,     0,   176,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   365,     0,   378,     0,   361,   362,   363,
     364,     0,     0,   366,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   365,     0,   380,     0,   361,   362,
     363,   364,     0,     0,   366,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   365,     0,   382,     0,   361,
     362,   363,   364,     0,     0,   366,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   365,     0,   384,     0,
     361,   362,   363,   364,     0,     0,   366,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   365,     0,   389,
       0,   361,   362,   363,   364,     0,     0,   366,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   365,     0,
     391,     0,   361,   362,   363,   364,     0,     0,   366,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   365,
       0,   393,     0,   361,   362,   363,   364,     0,     0,   366,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     365,     0,   395,     0,   361,   362,   363,   364,     0,     0,
     366,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   365,     0,   397,     0,   361,   362,   363,   364,     0,
       0,   366,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   365,     0,   399,     0,   361,   362,   363,   364,
       0,     0,   366,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   365,     0,   401,     0,   361,   362,   363,
     364,     0,     0,   366,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   365,     0,   403,     0,   361,   362,
     363,   364,     0,     0,   366,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   365,     0,   220,     0,   361,
     362,   363,   364,     0,     0,   366,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   365,   -83,   -83,   -83,
     -83,     0,     0,     0,   -83,     0,   366,     0,     0,     0,
       0,   -83,   -83,   -83,   -83,   -81,   -81,   -81,   -81,     0,
       0,     0,   -81,     0,   -83,     0,     0,     0,     0,   -81,
     -81,   -81,   -81,   -82,   -82,   -82,   -82,     0,     0,     0,
     -82,     0,   -81,     0,     0,     0,     0,   -82,   -82,   -82,
     -82,   -84,   -84,   -84,   -84,     0,     0,     0,   -84,     0,
     -82,     0,     0,     0,     0,   -84,   -84,   -84,   -84,     2,
       3,     4,     5,     0,     0,     0,     8,     0,   -84,     0,
       0,     0,     0,     9,    10,    11,    12,   193,   194,   195,
     196,     0,     0,     0,     8,     0,    18,     0,     0,     0,
       0,     9,    10,    11,   197,   171,   172,   173,   174,     0,
       0,     0,     8,     0,   198,     0,     0,     0,     0,     9,
      10,    11,   175,   221,   222,   223,   224,     0,     0,     0,
       8,     0,   176,     0,     0,     0,     0,     9,    10,    11,
     225,   301,   302,   303,   304,     0,     0,     0,     8,     0,
     226,     0,     0,     0,     0,     9,    10,    11,   305,   361,
     362,   363,   364,     0,     0,     0,     8,     0,   306,     0,
       0,     0,     0,     9,    10,    11,   365,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,     0,   366,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,     0,     0,     0,   300,   -91,
     -91,     0,     0,   -91,     0,     0,     0,     0,   -95,   -95,
     -95,     0,     0,   -95,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
       0,     0,     0,     0,   -91,    80,     0,     0,     0,     0,
     -91,     0,   -95,   -95,     0,     0,     0,     0,   -95,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,     0,     0,     0,     0,     0,
     269,   -91,     0,     0,     0,   -91,     0,     0,   -95,   -95,
       0,     0,     0,   -95,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
       0,     0,     0,     0,     0,     0,  -103,  -103,     0,     0,
    -103,     0,     0,     0,  -101,  -101,     0,     0,  -101,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,     0,     0,     0,     0,     0,
       0,  -104,  -104,     0,     0,  -104,     0,     0,     0,   -75,
     -75,     0,     0,   298,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
       0,     0,     0,     0,     0,     0,   -79,   -79,     0,     0,
     -79,     0,     0,     0,   -85,   -85,     0,     0,   -85,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,     0,     0,     0,     0,     0,
       0,   -92,   -92,     0,     0,   -92,     0,     0,     0,   -93,
     -93,     0,     0,   -93,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
       0,     0,     0,     0,     0,     0,   -80,   -80,     0,     0,
     -80,     0,     0,     0,   -94,   -94,     0,     0,   -94,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,     0,     0,     0,     0,     0,
       0,   -86,   -86,     0,     0,   -86,     0,   -93,     0,     0,
       0,     0,     0,   -93,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
       0,     0,     0,     0,   -80,     0,     0,     0,     0,     0,
     -80,     0,   -94,     0,     0,     0,     0,     0,   -94,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,     0,     0,     0,     0,   -86,
       0,     0,     0,     0,     0,   -86,     0,     0,     0,  -103,
       0,     0,     0,  -103,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
       0,     0,     0,     0,     0,     0,  -101,     0,     0,     0,
    -101,     0,     0,     0,  -104,     0,     0,     0,  -104,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,     0,     0,     0,     0,     0,
       0,   -75,     0,     0,     0,   267,     0,     0,     0,   -79,
       0,     0,     0,   -79,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
       0,     0,     0,     0,     0,     0,   -85,     0,     0,     0,
     -85,     0,     0,     0,   -92,     0,     0,     0,   -92,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,     0,     0,     0,     0,     0,
       0,   -93,     0,     0,     0,   -93,     0,     0,     0,   -80,
       0,     0,     0,   -80,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
       0,     0,     0,     0,     0,     0,   -94,     0,     0,     0,
     -94,     0,     0,     0,   -86,     0,     0,     0,   -86,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,     0,     0,     0,     0,     0,
       0,  -101,  -101,     0,     0,     0,     0,     0,     0,  -104,
    -104,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,
       0,     0,     0,   -78,   -78,     0,     0,     0,     0,     0,
       0,   -79,   -79,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,     0,
       0,     0,     0,     0,     0,   -85,   -85,     0,     0,     0,
       0,     0,     0,   -92,   -92,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   297,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     0,     0,     0,     0,     0,     0,   -93,   -93,     0,
       0,     0,     0,     0,     0,   -74,   -74,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   281,   282,   283,   284,   -50,
     286,   287,   288,     0,     0,     0,     0,     0,     0,   -75,
     -75,     0,     0,     0,     0,     0,     0,   -50,   -50,   281,
     282,   283,   -54,   -54,   286,   287,   288,   281,   282,   283,
     -58,   -58,   -58,   287,   288,     0,     0,     0,     0,     0,
       0,   -54,   -54,     0,     0,     0,     0,     0,     0,   -58,
     -58,   281,   282,   -62,   -62,   -62,   -62,   287,   288,   281,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,     0,
       0,     0,     0,   -62,   -62,     0,     0,     0,     0,     0,
       0,   -73,   -73,   297,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   281,   282,   -68,   -68,   -68,   -68,   287,   288,     0,
       0,     0,     0,     0,     0,   -72,   -72,     0,     0,     0,
       0,     0,     0,   -68,   -68,   281,   282,   -67,   -67,   -67,
     -67,   287,   288,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,     0,     0,     0,     0,     0,     0,   -67,   -67,     0,
       0,     0,     0,     0,     0,   -77,   -77,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,     0,     0,     0,     0,     0,     0,   -76,
     -76,     0,     0,     0,     0,     0,     0,   -80,   -80,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,     0,     0,     0,     0,     0,
       0,   -94,   -94,     0,     0,     0,     0,     0,     0,   -86,
     -86,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,     0,     0,     0,
       0,     0,   -96,   -96,     0,     0,     0,     0,     0,     0,
     409,   -91,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,   -95,   -95,     0,     0,     0,     0,     0,
       0,     0,   136,   266,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,
       0,     0,     0,     0,     0,   -71,     0,     0,     0,     0,
       0,     0,     0,  -102,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
       0,     0,     0,     0,     0,     0,  -103,     0,     0,     0,
       0,     0,     0,     0,  -101,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,     0,     0,     0,     0,     0,     0,  -104,     0,     0,
       0,     0,     0,     0,     0,   -78,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,     0,     0,     0,     0,     0,     0,   -79,     0,
       0,     0,     0,     0,     0,     0,   -85,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,     0,     0,     0,     0,     0,     0,   -92,
       0,     0,     0,     0,     0,     0,     0,   -93,   266,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,     0,     0,     0,     0,     0,     0,
     -74,     0,     0,     0,     0,     0,     0,     0,   -75,   242,
     243,   244,   245,   -50,   247,   248,   249,   242,   243,   244,
     -54,   -54,   247,   248,   249,     0,     0,     0,     0,     0,
       0,   -50,     0,     0,     0,     0,     0,     0,     0,   -54,
     242,   243,   244,   -58,   -58,   -58,   248,   249,   242,   243,
     -62,   -62,   -62,   -62,   248,   249,     0,     0,     0,     0,
       0,     0,   -58,     0,     0,     0,     0,     0,     0,     0,
     -62,   242,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   266,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,
       0,     0,     0,   -73,     0,     0,     0,     0,     0,     0,
       0,   -72,   242,   243,   -68,   -68,   -68,   -68,   248,   249,
     242,   243,   -67,   -67,   -67,   -67,   248,   249,     0,     0,
       0,     0,     0,     0,   -68,     0,     0,     0,     0,     0,
       0,     0,   -67,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,     0,
       0,     0,     0,     0,     0,   -77,     0,     0,     0,     0,
       0,     0,     0,   -76,   242,   243,   244,   245,   246,   247,
     248,   249,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
       0,     0,     0,     0,     0,     0,   415,     0,     0,     0,
       0,     0,     0,     0,   -80,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,     0,     0,     0,     0,     0,     0,   -94,     0,     0,
       0,     0,     0,     0,     0,   -86,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,     0,     0,     0,     0,   -91,   272,     0,     0,
       0,     0,     0,     0,   -95,   -95,    77,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,   -71,     0,     0,     0,
       0,     0,     0,     0,   103,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,    77,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     0,     0,     0,     0,   -78,     0,     0,     0,     0,
       0,     0,     0,   -74,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,    49,    50,    51,    52,   -50,    54,    55,    56,
       0,     0,     0,     0,   -75,     0,     0,     0,     0,     0,
       0,     0,   -50,    49,    50,    51,   -54,   -54,    54,    55,
      56,    49,    50,    51,   -58,   -58,   -58,    55,    56,     0,
       0,     0,     0,   -54,     0,     0,     0,     0,     0,     0,
       0,   -58,    49,    50,   -62,   -62,   -62,   -62,    55,    56,
      49,   -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
       0,     0,   -62,     0,     0,     0,     0,     0,     0,     0,
     -73,    77,   -72,   -72,   -72,   -72,   -72,   -72,   -72,    49,
      50,   -68,   -68,   -68,   -68,    55,    56,     0,     0,     0,
       0,   -72,     0,     0,     0,     0,     0,     0,     0,   -68,
      49,    50,   -67,   -67,   -67,   -67,    55,    56,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,     0,     0,     0,     0,
     -67,     0,     0,     0,     0,     0,     0,     0,   -77,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,     0,     0,     0,     0,   -76,
       0,     0,     0,     0,     0,     0,     0,  -102,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,     0,     0,     0,     0,  -103,     0,
       0,     0,     0,     0,     0,     0,  -101,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,     0,     0,     0,     0,  -104,     0,     0,
       0,     0,     0,     0,     0,   -79,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,     0,     0,     0,     0,   -85,     0,     0,     0,
       0,     0,     0,     0,   -92,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,     0,     0,     0,     0,   -93,     0,     0,     0,     0,
       0,     0,     0,   -80,    49,    50,    51,    52,    53,    54,
      55,    56,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
       0,     0,     0,     0,   358,     0,     0,     0,     0,     0,
       0,     0,   -94,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -86
};

static const yytype_int16 yycheck[] =
{
       0,     0,   212,     0,     0,     0,     0,     0,     0,    30,
     138,     0,    30,     0,    30,     6,     6,    17,    18,    30,
       6,    21,    21,   279,    21,    21,    21,    21,    21,    21,
     158,     6,    21,    23,    21,    13,     6,   269,    29,    29,
     272,    41,   252,    29,     6,    13,    46,    13,    23,    29,
      30,    29,    12,    13,    29,    12,    13,    57,    58,    29,
       0,    61,    62,    31,    32,    31,    66,    29,   300,     6,
      18,    31,   328,     1,    31,     3,     4,     5,     6,    29,
      80,    34,    10,    13,    11,    12,    13,    14,    29,    17,
      18,    19,    20,     9,    10,    11,    12,    13,    14,    15,
      16,    31,    30,    31,    31,    32,    12,    13,   108,    13,
      58,   111,     6,    61,    30,    31,    32,     1,    31,     3,
       4,     5,     6,    13,     9,    31,    10,    31,    32,    23,
      78,    31,    80,    17,    18,    19,    20,     6,   138,    29,
      12,    13,   142,   136,   137,    31,    30,    31,   276,   144,
      12,    13,    14,    31,    23,   155,    21,    22,   158,    31,
      32,    31,    32,   156,   157,   160,    31,   167,   167,    31,
     167,   167,   165,   167,   167,   167,   176,   409,   167,   435,
      11,    12,    13,    14,    29,   185,    12,    13,     1,   421,
       3,     4,     5,     6,   142,    31,    32,    10,   198,    29,
      31,    32,    31,    29,    17,    18,    19,    20,    31,    32,
     158,   211,    11,    12,    13,    14,    29,    30,   428,    10,
      11,    12,    13,    14,    15,    16,   226,    29,   176,    21,
      22,    29,    31,    32,    31,   235,    31,    32,     6,    31,
      31,    32,   242,   243,   244,   245,   246,   247,   248,   249,
     198,     9,    10,    11,    12,    13,    14,    15,    16,   259,
     260,   261,   262,   263,   264,   265,   266,   267,    29,   269,
      33,    29,   272,   273,   274,   275,   276,    35,   226,   279,
      29,   281,   282,   283,   284,   285,   286,   287,   288,   417,
     290,   291,   292,   293,   294,   295,   296,   297,   298,     0,
     300,    29,    11,    12,    13,    14,   306,    33,   308,    33,
     438,    11,    12,    13,    14,    31,    17,    18,    31,   267,
      21,   269,    31,    32,   272,    30,   274,   275,   328,    31,
       1,    31,     3,     4,     5,     6,     7,     8,    30,    10,
      41,    31,    32,    30,    12,    13,    17,    18,    19,    20,
     298,    30,   300,    24,    29,    26,    27,    58,   306,    30,
      61,    62,    33,    31,    32,    66,   366,    29,   368,    29,
       0,     1,    31,     3,     4,     5,     6,     7,     8,    80,
      10,    31,    11,    12,    13,    14,    29,    17,    18,    19,
      20,    21,    22,    31,    24,    25,    26,    27,    21,    22,
      30,     9,    31,    33,     6,    12,    13,   108,    29,   409,
       1,     6,     3,     4,     5,     6,    31,   417,   366,    10,
      31,   421,   415,   416,    31,    32,    17,    18,    19,    20,
      12,    13,    14,    31,    32,   435,     9,   138,   438,    30,
      34,   142,    31,   436,   437,   445,   445,    31,    32,    31,
      32,     1,    31,     3,     4,     5,     6,   158,    29,    30,
      10,   409,    11,    12,    13,    14,   167,    17,    18,    19,
      20,    31,    32,   421,    31,   176,    11,    12,    13,    14,
      30,    34,    31,    32,   185,    31,    11,    12,    13,    14,
     438,    11,    12,    13,    14,    31,    31,   198,     1,    29,
       3,     4,     5,     6,     7,     8,    31,    10,    29,    33,
     211,    31,    32,    31,    17,    18,    19,    20,    21,    22,
      31,    24,    25,    26,    27,   226,    31,    30,    29,    33,
      33,    34,    12,    13,   235,    34,    31,    21,   141,   108,
     160,   242,   243,   244,   245,   246,   247,   248,   249,    29,
       9,    10,    11,    12,    13,    14,    15,    16,   259,   260,
     261,   262,   263,   264,   265,   266,   267,    -1,   269,    -1,
      29,   272,    -1,   274,   275,   276,    35,    -1,   279,    -1,
     281,   282,   283,   284,   285,   286,   287,   288,    -1,   290,
     291,   292,   293,   294,   295,   296,   297,   298,     0,   300,
      11,    12,    13,    14,    -1,   306,    -1,   308,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    12,    13,    21,
      31,    32,    12,    13,    14,     0,     1,   328,     3,     4,
       5,     6,     7,     8,    29,    10,    12,    13,    14,    41,
      -1,    31,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    29,    -1,    30,    58,    -1,    33,    61,
      62,    12,    13,    14,    66,   366,    -1,   368,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    80,    10,
      31,    11,    12,    13,    14,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,     9,    10,    30,
      -1,    31,    33,    15,    16,    -1,   108,    -1,   409,     1,
      -1,     3,     4,     5,     6,    -1,   417,    -1,    10,    -1,
     421,    11,    12,    13,    14,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,   435,    -1,   138,   438,    30,    -1,
     142,    31,    32,     1,   445,     3,     4,     5,     6,     7,
       8,    -1,    10,    12,    13,    14,   158,    -1,    -1,    17,
      18,    19,    20,    21,    22,   167,    24,    25,    26,    27,
      29,    -1,    30,    -1,   176,    33,    34,    11,    12,    13,
      14,    -1,     1,   185,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,   198,    31,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,   211,
      -1,    30,    -1,    -1,    33,    34,     9,    10,    11,    12,
      13,    14,    15,    16,   226,    -1,    -1,    -1,    11,    12,
      13,    14,    -1,   235,    -1,    -1,    -1,    30,    31,    32,
     242,   243,   244,   245,   246,   247,   248,   249,    31,     9,
      10,    11,    12,    13,    14,    15,    16,   259,   260,   261,
     262,   263,   264,   265,   266,   267,    -1,   269,    -1,    29,
     272,    -1,   274,   275,   276,    35,    -1,   279,    -1,   281,
     282,   283,   284,   285,   286,   287,   288,    -1,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,   300,    11,
      12,    13,    14,    -1,   306,    -1,   308,    -1,    -1,    -1,
       9,    10,    11,    -1,    17,    18,    15,    16,    21,    31,
      32,    -1,    -1,    -1,     0,     1,   328,     3,     4,     5,
       6,     7,     8,    -1,    10,    12,    13,    14,    41,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    29,    -1,    30,    58,    -1,    33,    61,    62,
      12,    13,    14,    66,   366,     1,   368,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    80,    -1,    31,
      32,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      11,    12,    13,    14,    -1,   108,    -1,   409,     1,    -1,
       3,     4,     5,     6,    -1,   417,    -1,    10,    -1,   421,
      31,    32,     9,    10,    17,    18,    19,    20,    15,    16,
      -1,    -1,    -1,   435,    -1,   138,   438,    30,    -1,   142,
      -1,     0,     1,   445,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,   158,    -1,    -1,    17,    18,
      19,    20,    21,    22,   167,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,   176,    33,    -1,    11,    12,    13,    14,
       0,     1,   185,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,   198,    31,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,   211,    -1,
      30,    -1,    -1,    33,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,   226,    -1,    -1,    -1,    11,    12,    13,
      14,    -1,   235,    -1,    -1,    30,    31,    32,    -1,   242,
     243,   244,   245,   246,   247,   248,   249,    31,     9,    10,
      11,    12,    13,    14,    15,    16,   259,   260,   261,   262,
     263,   264,   265,   266,   267,    -1,   269,    -1,    29,   272,
      -1,   274,   275,   276,    35,    -1,   279,    -1,   281,   282,
     283,   284,   285,   286,   287,   288,    -1,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     0,   300,    11,    12,
      13,    14,    -1,   306,    -1,   308,    -1,    -1,    -1,     9,
      10,    11,    -1,    17,    18,    15,    16,    21,    31,    12,
      13,    14,    -1,     0,     1,   328,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    41,    31,    32,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    58,    -1,    33,    61,    62,    -1,
      -1,    -1,    66,   366,    -1,   368,    -1,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,    80,    10,    -1,    -1,
      11,    12,    13,    14,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,     9,    10,    30,    29,    -1,
      33,    15,    16,    -1,   108,    -1,   409,     1,    -1,     3,
       4,     5,     6,    -1,   417,    -1,    10,    -1,   421,    11,
      12,    13,    14,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,   435,    -1,   138,   438,    30,    29,   142,    -1,
       0,     1,   445,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,   158,    -1,    -1,    17,    18,    19,
      20,    21,    22,   167,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,   176,    33,    11,    12,    13,    14,    -1,     0,
       1,   185,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    29,    -1,   198,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,   211,    -1,    30,
      -1,    -1,    33,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,   226,     9,    10,    11,    12,    13,    14,    15,
      16,   235,    -1,    -1,    -1,    31,    32,    -1,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,   259,   260,   261,   262,   263,
     264,   265,   266,   267,    -1,   269,    -1,    29,   272,    -1,
     274,   275,   276,    35,    -1,   279,    -1,   281,   282,   283,
     284,   285,   286,   287,   288,    -1,   290,   291,   292,   293,
     294,   295,   296,   297,   298,     0,   300,    11,    12,    13,
      14,    -1,   306,    -1,   308,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    29,    21,    11,    12,    13,
      14,    -1,     0,     1,   328,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    29,    41,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    58,    -1,    33,    61,    62,    -1,    -1,
      -1,    66,   366,    -1,   368,    -1,     0,     1,    -1,     3,
       4,     5,     6,     7,     8,    80,    10,    -1,    -1,    11,
      12,    13,    14,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    29,    -1,    33,
      -1,    -1,    -1,   108,    -1,   409,     1,    -1,     3,     4,
       5,     6,    -1,   417,    -1,    10,    -1,   421,    11,    12,
      13,    14,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,   435,    -1,   138,   438,    30,    29,   142,    -1,     0,
       1,   445,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,   158,    -1,    -1,    17,    18,    19,    20,
      21,    22,   167,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,   176,    33,    11,    12,    13,    14,    -1,     0,     1,
     185,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    29,    -1,   198,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,   211,    -1,    30,    -1,
      -1,    33,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,   226,     9,    10,    11,    12,    13,    14,    15,    16,
     235,    -1,    -1,    -1,    31,    32,    -1,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    -1,   269,    -1,    29,   272,    -1,   274,
     275,   276,    35,    -1,   279,    -1,   281,   282,   283,   284,
     285,   286,   287,   288,    -1,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,   300,    11,    12,    13,    14,
      -1,   306,    -1,   308,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    29,    21,    11,    12,    13,    14,
      -1,     0,     1,   328,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    29,    41,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    58,    -1,    33,    61,    62,    -1,    -1,    -1,
      66,   366,     1,   368,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    80,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,     9,
      10,    11,   108,    -1,   409,    15,    16,     0,     9,    10,
      11,    12,   417,    14,    15,    16,   421,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    -1,
     435,    -1,   138,   438,    -1,    -1,   142,    -1,    -1,    -1,
     445,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,   158,     9,    10,    11,    12,    13,    14,    15,
      16,   167,    30,    31,    32,    58,    -1,    35,    61,    62,
     176,    -1,    -1,    66,    -1,    31,    32,     0,     1,   185,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,   198,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,   211,    -1,    30,    -1,    -1,
      33,     9,    10,    11,    12,   108,    14,    15,    16,    -1,
     226,     9,    10,    11,    12,    13,    14,    15,    16,   235,
      -1,    -1,    -1,    -1,    -1,    -1,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   138,    -1,    -1,    -1,   142,
      -1,    -1,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,    -1,   269,    -1,   158,   272,    -1,   274,   275,
     276,    -1,    -1,   279,   167,   281,   282,   283,   284,   285,
     286,   287,   288,   176,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,   300,    -1,    -1,    -1,    -1,    -1,
     306,    -1,   308,    -1,    -1,   198,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,   211,    -1,
       0,     1,   328,     3,     4,     5,     6,     7,     8,    -1,
      10,    31,    32,   226,    -1,    35,    18,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    41,
     366,    -1,   368,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    -1,    -1,    61,
      -1,   274,   275,   276,    -1,    -1,   279,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    -1,
      -1,    -1,    -1,   409,    -1,     1,    -1,     3,     4,     5,
       6,   417,    -1,   306,    10,   421,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,   435,
      -1,    -1,   438,    -1,    30,   328,    -1,     0,     1,   445,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
     142,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,   366,    -1,    -1,   158,    -1,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,   176,    17,    18,    19,    20,    21,
      22,    -1,    24,   185,    26,    27,    -1,    -1,    30,    -1,
       1,    33,     3,     4,     5,     6,   198,   199,    -1,    10,
      -1,    -1,    -1,    -1,   417,    -1,    17,    18,    19,    20,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    30,
      -1,    -1,   435,    -1,   226,   438,    -1,    -1,    -1,    -1,
      29,    30,   445,   235,    -1,    -1,    35,    -1,    -1,    -1,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,   259,   260,   261,
     262,   263,   264,   265,   266,   267,    -1,   269,    -1,    29,
     272,    -1,   274,   275,    18,    35,    -1,    -1,    -1,   281,
     282,   283,   284,   285,   286,   287,   288,    -1,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    -1,   300,    -1,
      -1,    -1,    -1,    -1,   306,    -1,   308,    51,    -1,    -1,
      -1,    55,    56,    -1,    58,    -1,    -1,    61,    -1,    -1,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,    73,
      10,    75,    76,    -1,    -1,    -1,    80,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,     1,    33,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,   366,    -1,   368,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,   142,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,   409,    -1,    24,
      -1,    26,    27,    -1,   158,    30,    -1,    -1,    33,   421,
      10,    11,    12,    13,    14,    15,    16,    -1,     9,    10,
      11,    18,   176,    14,    15,    16,   438,    -1,    -1,    -1,
       1,    31,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,   198,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    54,    -1,    30,
      -1,    58,    33,    34,    61,    10,    11,    12,    13,    14,
      15,    16,   226,    -1,    -1,    72,    -1,    -1,    -1,    -1,
       9,    10,    11,    80,    29,    14,    15,    16,    -1,    -1,
     244,   245,   246,   247,   248,   249,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,   259,   260,   261,   262,    -1,
     264,   265,    -1,   267,    -1,   269,    18,    29,   272,    -1,
     274,   275,    -1,    35,    -1,    -1,    -1,    -1,    -1,   283,
     284,   285,   286,   287,   288,    -1,   290,   291,   292,   293,
      -1,   295,   296,    -1,   298,   142,   300,    -1,    50,    -1,
      -1,    -1,   306,    -1,    -1,    -1,    58,    -1,    -1,    61,
      -1,   158,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,    74,    10,    -1,    -1,    -1,    -1,    80,   176,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,
      -1,   198,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,   366,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,   226,
      -1,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,
     142,    -1,     1,    -1,     3,     4,     5,     6,   245,   246,
     247,    10,    -1,    -1,    -1,   409,   158,    -1,    17,    18,
      19,    20,   259,   260,   261,    -1,    -1,   421,    -1,    -1,
     267,    30,   269,    -1,   176,   272,    -1,   274,   275,    -1,
      -1,    -1,    -1,    -1,   438,    -1,    18,   284,   285,   286,
      -1,    -1,    -1,   290,   291,   292,   198,    -1,    -1,    -1,
      -1,   298,     1,   300,     3,     4,     5,     6,    -1,   306,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,    -1,   226,    -1,    58,    -1,    -1,    61,
      -1,    30,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,   243,   244,   245,   246,   247,   248,   249,    80,     9,
      10,    11,    12,    13,    14,    15,    16,   259,   260,   261,
     262,   263,   264,   265,    -1,   267,    -1,   269,    -1,   366,
     272,    31,   274,   275,    -1,    35,    -1,    -1,    -1,    -1,
     282,   283,   284,   285,   286,   287,   288,    -1,   290,   291,
     292,   293,   294,   295,   296,    -1,   298,    -1,   300,    18,
       9,    10,    11,    -1,   306,    14,    15,    16,    -1,    -1,
     142,     1,   409,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    -1,    -1,    -1,   421,    -1,   158,    17,    18,    19,
      20,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    58,
      30,   438,    61,    -1,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    80,    -1,    -1,   366,    -1,   198,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
      -1,    53,    -1,    -1,   226,    -1,    58,    30,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,    70,    -1,
      -1,    -1,   244,   245,   246,   247,   248,   249,    80,   421,
      -1,    -1,    -1,   142,    -1,    -1,    -1,   259,   260,   261,
     262,    -1,   264,   265,    -1,   267,   438,   269,    -1,   158,
     272,    -1,   274,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   283,   284,   285,   286,   287,   288,   176,   290,   291,
     292,   293,    -1,   295,   296,    -1,   298,    -1,   300,    -1,
      -1,    -1,    -1,    -1,   306,    -1,    -1,    -1,    -1,   198,
     142,    -1,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,   158,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,   226,    26,    27,
      -1,    -1,    30,    -1,   176,    33,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,   245,   246,     1,    -1,
       3,     4,     5,     6,   366,    -1,   198,    10,    30,    31,
     259,   260,    -1,    35,    17,    18,    19,    20,   267,    -1,
     269,    -1,    -1,   272,    -1,   274,   275,    30,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   284,   285,    -1,    -1,    -1,
      -1,   290,   291,    -1,    -1,    -1,    -1,   409,    -1,   298,
      -1,   300,    -1,    -1,   246,    -1,    -1,   306,    -1,   421,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,   438,   269,    -1,    -1,
     272,    -1,   274,   275,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,   285,    -1,    10,    -1,    -1,   290,    -1,
      -1,    -1,    17,    18,    19,    20,   298,    -1,   300,    -1,
      -1,    -1,    -1,    -1,   306,    30,     1,   366,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     1,
     409,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      29,    30,   421,    -1,   366,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,   438,
      -1,    33,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,   409,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,   421,
       0,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,   438,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,     0,     1,    33,     3,     4,     5,     6,     7,     8,
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
      26,    27,    -1,    -1,    30,    -1,     1,    33,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    17,    18,    19,    20,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    -1,    30,    -1,    -1,    -1,
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
      20,     3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,
      30,    -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    30,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    35,    -1,    -1,    -1,    -1,    30,    31,
      32,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    35,    -1,    -1,    30,    31,
      -1,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
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
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    31,
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
      35,    -1,    -1,    -1,    31,    -1,    -1,    -1,    35,     9,
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
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
      15,    16,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,     9,    10,    11,    12,
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
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    10,    17,
      18,    19,    20,    21,    22,    24,    26,    27,    30,    33,
      37,    38,    39,    40,    42,    48,    53,    54,    55,    56,
      57,    58,    59,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    73,    74,    75,    76,    77,    78,     9,
      10,    11,    12,    13,    14,    15,    16,    30,    30,    23,
      23,    30,    30,     1,    59,    59,    49,     0,    39,    29,
      13,    12,    14,    11,    10,    15,    16,     9,    35,    68,
      30,    29,    75,    68,     1,    67,    68,     1,    65,     1,
      63,     1,    62,     1,    64,    65,    65,    75,    59,     1,
      59,    59,    60,    29,    29,    31,    40,    50,    51,    52,
      53,    76,     1,    62,     1,    63,     1,    64,     1,    65,
       1,    67,     1,    65,     1,    65,     1,    68,    61,    59,
      71,    72,    30,    41,    31,    31,    31,    31,    29,    34,
      52,    75,    32,    31,    43,    29,    29,    29,    48,    48,
      60,    59,    45,    46,    47,    76,    25,    25,    29,    31,
      32,    75,    48,    48,    60,    44,    47,    31,    48,    53,
       1,     3,     4,     5,     6,    20,    30,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    73,    74,    75,
      77,    78,     6,     3,     4,     5,     6,    20,    30,    69,
      70,    73,    74,    75,    77,    78,     6,     7,     8,    24,
      26,    27,    33,    48,    54,    55,    56,    57,    58,    59,
       1,     3,     4,     5,     6,    20,    30,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    73,    74,    75,
      77,    78,     9,    10,    11,    12,    13,    14,    15,    16,
       6,    29,    33,    41,    21,    22,     6,    59,    59,    13,
      12,    14,    11,    10,    15,    16,     9,    35,    68,    30,
      59,    68,    30,    30,    30,    30,    30,     1,    59,    49,
      29,     9,    10,    11,    12,    13,    14,    15,    16,    59,
      13,    12,    14,    11,    10,    15,    16,     9,    35,    68,
      30,     3,     4,     5,     6,    20,    30,    68,    69,    70,
      73,    74,    75,    77,    78,     1,    67,    68,     1,    65,
       1,    63,     1,    62,     1,    64,    65,    65,    49,    29,
      23,    23,    31,     1,    62,     1,    63,     1,    64,     1,
      65,     1,    67,     1,    65,     1,    65,     1,    68,    61,
      72,    31,    72,    75,    59,     1,    59,    60,    29,    29,
      50,     3,     4,     5,     6,    20,    30,    68,    69,    70,
      73,    74,    75,    77,    78,     1,    67,    68,     1,    65,
       1,    63,     1,    62,     1,    64,    65,    65,    31,     1,
      62,     1,    63,     1,    64,     1,    65,     1,    67,     1,
      65,     1,    65,     1,    68,    61,    72,    59,    68,    30,
      50,    31,    31,    31,    31,    31,    31,    29,    34,    59,
      68,    30,    31,    31,    72,    34,    29,    29,    33,    48,
      48,    60,    31,    72,    31,    49,    25,    25,    29,    31,
      50,    48,    48,    60,    34,    31,    53
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
      72,    73,    73,    73,    73,    74,    75,    76,    76,    76,
      76,    77,    77,    77,    78
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
#line 3023 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3029 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3035 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3041 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3047 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3053 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3059 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3065 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3071 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3077 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3083 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3089 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3095 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3101 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3107 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3113 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3119 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3125 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3131 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3137 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_1: /* @1  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3143 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3149 "src/bison/grammar.c"
        break;

    case YYSYMBOL_43_2: /* @2  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3155 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3161 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3167 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3173 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3179 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3185 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3191 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3197 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3203 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3209 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3215 "src/bison/grammar.c"
        break;

    case YYSYMBOL_60_expression_opt: /* expression.opt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3221 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3227 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3233 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3239 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3245 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3251 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3257 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3263 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3269 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3275 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3281 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3287 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id_expr: /* id_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3293 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3299 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3305 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3311 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3317 "src/bison/grammar.c"
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
#line 3626 "src/bison/grammar.c"
    break;

  case 4: /* external_declaration_list: external_declaration_list external_declaration  */
#line 133 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 3632 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration  */
#line 134 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 3638 "src/bison/grammar.c"
    break;

  case 8: /* external_declaration: statement  */
#line 139 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[0].ast));
    }
#line 3648 "src/bison/grammar.c"
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
#line 3674 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type id @1 ';'  */
#line 166 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 3682 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 169 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
    }
#line 3692 "src/bison/grammar.c"
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
#line 3733 "src/bison/grammar.c"
    break;

  case 13: /* $@3: %empty  */
#line 211 "src/bison/grammar.y"
                         {
        // hack to save the scope of params and append to the scope of the body
        params_scope = scope_init_copy(stack_peek(&current_context->scopes));
        stack_pop(&current_context->scopes, free_scope_cb);
    }
#line 3743 "src/bison/grammar.c"
    break;

  case 14: /* func_declaration: type id '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 215 "src/bison/grammar.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = 1;
    }
#line 3753 "src/bison/grammar.c"
    break;

  case 15: /* param_list.opt: %empty  */
#line 222 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 3759 "src/bison/grammar.c"
    break;

  case 17: /* params_list: params_list ',' param_decl  */
#line 226 "src/bison/grammar.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3765 "src/bison/grammar.c"
    break;

  case 18: /* params_list: param_decl  */
#line 227 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3771 "src/bison/grammar.c"
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
#line 3790 "src/bison/grammar.c"
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
#line 3806 "src/bison/grammar.c"
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
#line 3818 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list.opt: block_item_list  */
#line 265 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 3824 "src/bison/grammar.c"
    break;

  case 23: /* block_item_list.opt: %empty  */
#line 266 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3830 "src/bison/grammar.c"
    break;

  case 24: /* block_item_list: block_item_list block_item  */
#line 269 "src/bison/grammar.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3836 "src/bison/grammar.c"
    break;

  case 25: /* block_item_list: block_item  */
#line 270 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3842 "src/bison/grammar.c"
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
#line 3854 "src/bison/grammar.c"
    break;

  case 35: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 292 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(sym)), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 3864 "src/bison/grammar.c"
    break;

  case 36: /* expr_stmt: expression ';'  */
#line 299 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 3870 "src/bison/grammar.c"
    break;

  case 37: /* cond_stmt: IF '(' expression ')' compound_stmt  */
#line 302 "src/bison/grammar.y"
                                                          {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 3878 "src/bison/grammar.c"
    break;

  case 38: /* cond_stmt: IF '(' expression ')' compound_stmt ELSE compound_stmt  */
#line 305 "src/bison/grammar.y"
                                                             {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3886 "src/bison/grammar.c"
    break;

  case 39: /* cond_stmt: IF '(' error ')' compound_stmt  */
#line 308 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[0].ast));
        yyerrok;
    }
#line 3897 "src/bison/grammar.c"
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
#line 3909 "src/bison/grammar.c"
    break;

  case 41: /* jmp_stmt: RETURN expression ';'  */
#line 323 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 3915 "src/bison/grammar.c"
    break;

  case 42: /* jmp_stmt: RETURN error ';'  */
#line 324 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-2]), WHT "'return'" RESET " with no value\n");
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 3925 "src/bison/grammar.c"
    break;

  case 43: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 331 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3933 "src/bison/grammar.c"
    break;

  case 45: /* expression: unary_expr '=' logical_or_expr  */
#line 337 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3939 "src/bison/grammar.c"
    break;

  case 46: /* expression.opt: %empty  */
#line 340 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 3945 "src/bison/grammar.c"
    break;

  case 49: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 345 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3954 "src/bison/grammar.c"
    break;

  case 50: /* logical_or_expr: logical_or_expr OR error  */
#line 349 "src/bison/grammar.y"
                               {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 3964 "src/bison/grammar.c"
    break;

  case 51: /* logical_or_expr: error OR logical_and_expr  */
#line 354 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 3974 "src/bison/grammar.c"
    break;

  case 53: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 362 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3983 "src/bison/grammar.c"
    break;

  case 54: /* logical_and_expr: logical_and_expr AND error  */
#line 366 "src/bison/grammar.y"
                                 {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 3993 "src/bison/grammar.c"
    break;

  case 55: /* logical_and_expr: error AND eq_expr  */
#line 371 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4003 "src/bison/grammar.c"
    break;

  case 57: /* eq_expr: eq_expr EQ rel_expr  */
#line 379 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4012 "src/bison/grammar.c"
    break;

  case 58: /* eq_expr: eq_expr EQ error  */
#line 383 "src/bison/grammar.y"
                       {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4022 "src/bison/grammar.c"
    break;

  case 59: /* eq_expr: error EQ rel_expr  */
#line 388 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4032 "src/bison/grammar.c"
    break;

  case 61: /* rel_expr: rel_expr REL list_expr  */
#line 396 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4041 "src/bison/grammar.c"
    break;

  case 62: /* rel_expr: rel_expr REL error  */
#line 400 "src/bison/grammar.y"
                         {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4051 "src/bison/grammar.c"
    break;

  case 63: /* rel_expr: error REL list_expr  */
#line 405 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4061 "src/bison/grammar.c"
    break;

  case 65: /* list_expr: add_expr DL_DG list_expr  */
#line 413 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4070 "src/bison/grammar.c"
    break;

  case 66: /* list_expr: add_expr COLON list_expr  */
#line 417 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4079 "src/bison/grammar.c"
    break;

  case 67: /* list_expr: add_expr DL_DG error  */
#line 421 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4089 "src/bison/grammar.c"
    break;

  case 68: /* list_expr: add_expr COLON error  */
#line 426 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4099 "src/bison/grammar.c"
    break;

  case 69: /* list_expr: error DL_DG list_expr  */
#line 431 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4109 "src/bison/grammar.c"
    break;

  case 70: /* list_expr: error COLON list_expr  */
#line 436 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4119 "src/bison/grammar.c"
    break;

  case 72: /* add_expr: add_expr ADD mult_expr  */
#line 444 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4128 "src/bison/grammar.c"
    break;

  case 73: /* add_expr: add_expr ADD error  */
#line 448 "src/bison/grammar.y"
                         {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4138 "src/bison/grammar.c"
    break;

  case 74: /* add_expr: error ADD mult_expr  */
#line 453 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4148 "src/bison/grammar.c"
    break;

  case 76: /* mult_expr: mult_expr MULT unary_expr  */
#line 461 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4157 "src/bison/grammar.c"
    break;

  case 77: /* mult_expr: mult_expr MULT error  */
#line 465 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4167 "src/bison/grammar.c"
    break;

  case 78: /* mult_expr: error MULT unary_expr  */
#line 470 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4177 "src/bison/grammar.c"
    break;

  case 80: /* unary_expr: unary_ops unary_expr  */
#line 478 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4186 "src/bison/grammar.c"
    break;

  case 86: /* postfix_expr: id_expr '(' arg_expr_list.opt ')'  */
#line 491 "src/bison/grammar.y"
                                        {
        (yyval.ast) = ast_funcall_init((yyvsp[-3].ast), ast_params_init((yyvsp[-1].list)));
    }
#line 4194 "src/bison/grammar.c"
    break;

  case 87: /* arg_expr_list: expression  */
#line 496 "src/bison/grammar.y"
                          { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4200 "src/bison/grammar.c"
    break;

  case 88: /* arg_expr_list: arg_expr_list ',' expression  */
#line 497 "src/bison/grammar.y"
                                   { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 4206 "src/bison/grammar.c"
    break;

  case 90: /* arg_expr_list.opt: %empty  */
#line 501 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4212 "src/bison/grammar.c"
    break;

  case 94: /* primary_expr: '(' expression ')'  */
#line 507 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 4218 "src/bison/grammar.c"
    break;

  case 95: /* id_expr: id  */
#line 510 "src/bison/grammar.y"
            {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[0].sym));
        if (!sym) {
            show_error((yyloc), BCYN "'%s'" RESET " undeclared (first use in this function)\n", (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        }   else {
            symbol_update_context((yyvsp[0].sym), current_context);
            (yyval.ast) = ast_symref_init(symbol_init_copy(sym ? sym : (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
    }
#line 4234 "src/bison/grammar.c"
    break;

  case 99: /* type: INT LIST  */
#line 528 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 4246 "src/bison/grammar.c"
    break;

  case 100: /* type: FLOAT LIST  */
#line 535 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 4258 "src/bison/grammar.c"
    break;

  case 101: /* constant: NUMBER_REAL  */
#line 544 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 4264 "src/bison/grammar.c"
    break;

  case 102: /* constant: NUMBER_INT  */
#line 545 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 4270 "src/bison/grammar.c"
    break;

  case 103: /* constant: NIL  */
#line 546 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 4276 "src/bison/grammar.c"
    break;

  case 104: /* string_literal: STR_LITERAL  */
#line 549 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 4285 "src/bison/grammar.c"
    break;


#line 4289 "src/bison/grammar.c"

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

#line 555 "src/bison/grammar.y"


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
