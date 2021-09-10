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
#define YYLAST   9829

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  590

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
       0,   130,   130,   131,   134,   135,   138,   139,   140,   147,
     147,   169,   176,   211,   176,   218,   227,   228,   231,   232,
     233,   239,   253,   253,   266,   267,   270,   271,   274,   275,
     278,   279,   280,   281,   282,   283,   286,   293,   298,   303,
     310,   313,   316,   319,   324,   329,   335,   342,   343,   349,
     354,   355,   356,   363,   364,   367,   368,   372,   377,   384,
     385,   389,   394,   401,   402,   406,   411,   418,   419,   423,
     428,   435,   436,   440,   444,   449,   454,   459,   466,   467,
     471,   476,   483,   484,   488,   493,   500,   501,   507,   508,
     509,   510,   513,   514,   534,   535,   536,   542,   543,   546,
     556,   557,   558,   559,   565,   568,   569,   570,   577,   586,
     587,   588,   591
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

#define YYPACT_NINF (-343)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-113)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1029,  3420,   474,   538,  7821,    53,   -22,   -14,  3057,  3323,
    3374,  3456,  7848,    14,    47,    12,    19,   204,   273,  3940,
      51,  4833,  4864,  4895,  4926,  4957,  4988,  5019,  5050,  5081,
    5112,  5143,    56,    96,   320,   182,  1096,  1338,  1266,  3529,
    7856,  3505,  7883,  7891,   397,    16,  7918,  7926,  3900,   752,
     995,  1071,  1112,  1353,   995,   995,   303,  1395,    42,    44,
    1436,   169,  3913,    73,   848,   100,  5174,  -343,  5209,  5240,
    1634,  1677,  1719,  1760,  1958,  2001,  2043,  2084,  2282,  7953,
       9,  5271,     3,   161,  9394,   113,  9402,  9423,   462,  1373,
    1069,   203,  2604,   331,  1172,  1420,  1471,  1494,   103,   121,
    8744,   128,  8752,   130,   138,   140,  5302,  5333,  7961,  7988,
    5364,   137,  5398,  5432,  5466,     1,  9431,   359,  9452,   617,
    9460,  1601,  9481,  1662,  9489,  9510,  9518,  1697,  9539,  1744,
    9547,  9568,  9576,   152,  8273,   226,   233,   149,   283,   181,
     354,   361,   194,    10,   214,   224,   232,   243,   251,  3281,
    3556,   169,  5501,  5532,   253,  2325,  7996,   200,   401,   475,
       3,  5567,  5598,  5629,  5660,  5691,  6746,    86,  5722,   443,
     288,   544,  5753,   547,   298,  5784,  6746,  6746,   123,   306,
    5815,  5846,   316,   200,  6746,  5877,  5908,  8023,  8031,  8058,
    7566,  8066,  2367,    68,   206,   213,   274,   444,   342,  8775,
    8093,  4126,  8101,  8128,  7576,  8136,  8163,   496,  9597,  9605,
    9626,  9364,  9634,  2408,  3900,  9655,  9663,  9372,  9684,  9692,
     319,  7518,  2649,  2691,  2732,  2973,  3015,  2691,  2691,   338,
     340,    72,    91,   369,   375,  3247,  3940,  5939,  5973,  6007,
    6041,  6075,  6109,   353,  7603,  7611,  7638,   365,  7646,  3788,
     104,   125,   132,   228,   287,   601,  8297,  7673,  7536,  7681,
    7708,  3841,  7716,  7743,    32,   109,   390,  6143,  7554,  3882,
    4050,  6870,  6891,  6912,  4050,  4050,   554,   395,   411,   422,
     424,  6933,  3940,   494,   780,   877,   915,   959,  1204,   404,
     437,  3468,  3833,   451,  8783,   465,  6954,  6975,  6996,  7017,
    7038,  7059,  7080,  7101,  7122,  8171,     9,  8806,   477,  9713,
       9,  8814,  8837,  8845,  3101,  8868,  7143,  8876,  7518,  8899,
    8907,  8721,  8930,  8938,   501,  8961,  8969,   584,   638,  1632,
     711,  2928,   235,  1321,   682,   691,   706,   436,  7164,    30,
      92,  7185,   169,  9721,   445,  5174,  6177,  8992,   497,  7206,
    7227,  7248,  7269,  7290,  7311,  7332,  7353,  7374,  7751,     9,
     525,   534,  8305,  8329,  8337,  8241,  8361,  7395,  8369,  7554,
    8393,  8401,  8265,  8425,  8433,   535,  8457,  8465,   815,   314,
    1821,   308,  3996,   170,  1366,   352,   403,   524,   439,  7416,
    7437,   169,  9742,   539,  5174,  1239,  6211,  8198,  8206,  9000,
     299,  9023,   900,  9031,   878,  9054,   916,  9062,  9085,  9093,
     941,  9116,  1030,  9124,  9147,  9155,   117,   541,  9750,  9771,
     556,  9178,   558,  9186,     9,   560,   570,  9209,   572,  9217,
     577,   605,  6245,  6279,   606,  7778,  7786,  8489,   238,  8497,
     659,  8521,   549,  8529,   593,  8553,  8561,  8585,   643,  8593,
     667,  8617,  8625,  8649,   276,   604,  9240,   614,  8657,     9,
     616,   627,  9248,   632,  9271,   635,   639,  1283,  1528,   650,
    8233,  9779,  9279,  9302,   654,   657,   668,   678,   680,  3638,
    4085,   169,  6313,  7813,  8681,  8689,   679,   685,   686,   699,
     707,  4184,  6653,   169,  1563,  9310,  6347,  6381,  6415,  6449,
     708,   709,   710,  6777,   717,  7458,  3940,  1599,  1852,  1887,
    1923,  2176,  2211,  2247,   712,  6483,  2500,   719,  8713,  2535,
    2579,  2824,  2859,  6808,  2903,  3133,  3167,   722,   516,  7479,
    7500,  6517,   169,  9800,   723,  5174,  6777,  3212,  6777,   123,
    4232,  6808,  6808,   123,   729,   730,  9333,   732,  9341,   733,
     736,  3591,  4267,   740,  6551,  6585,   735,  4302,  4358,   745,
     749,   750,   760,   762,  6684,  6715,   169,  4392,  6777,  6808,
    4426,  4460,  4494,  4528,  6839,  4562,  4596,  4630,   763,  6619,
    4665,  4696,  6839,  6839,   123,  4730,  4764,   772,  6839,  4798
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -343,  -343,  -343,   787,    35,   655,  -343,  -343,  -343,   651,
    -343,   662,    79,  -235,  -342,  -343,   700,    54,   118,   147,
     185,   252,   254,     0,  -145,  3817,  3810,  3683,  3474,  3048,
    3410,  3147,  1120,  1444,  1768,  -343,  -301,  2092,   796,     2,
    2416,  2740
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    20,    21,    22,   110,   144,    24,   160,   179,   139,
     140,   141,   237,    66,   111,   112,   113,   114,   238,   239,
     240,   241,   242,   243,   105,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   136,   137,    43,    44,   115,
      46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   345,    45,   434,   138,   417,   170,   266,    56,   420,
     134,   -12,   244,   245,   246,   247,    57,    63,    65,     8,
    -105,    32,   207,    45,   264,   265,     9,    10,    11,   248,
     267,   -12,   -12,   182,   -16,    23,  -107,    58,  -105,   249,
     -98,   -12,    60,  -105,  -105,    81,    82,   394,  -107,    61,
    -108,    67,   469,  -106,    26,   360,    23,   101,   455,  -107,
     103,   104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
      59,  -107,  -107,  -108,  -108,    26,  -106,  -106,  -105,    25,
     135,   296,  -104,  -104,   142,    69,   -44,   -44,  -104,   -44,
     -44,   -44,   -44,   -44,   -44,   339,   -44,  -106,  -108,   -50,
      25,  -105,   107,   -44,   -44,   -44,   -44,   -44,   -44,    70,
     -44,   176,   -44,   -44,   340,  -106,   -44,   349,    27,   -44,
    -106,  -108,    48,   474,   292,   -50,   187,   188,   189,   190,
     296,   109,   361,     8,   145,   -50,   -50,   350,   -55,    27,
       9,    10,    11,   191,   -59,   -59,   351,    28,   -51,   289,
     289,   104,   146,   192,   -53,   171,   -55,   -55,   486,   148,
     142,   150,   142,   -59,   -59,    70,    32,   -54,    28,   151,
       1,   152,     2,     3,     4,     5,    32,    32,   293,     8,
     156,   -51,   350,   -58,    32,    29,     9,    10,    11,    12,
      -9,   143,   295,   553,   -59,   -59,    72,   431,   -53,    18,
     276,   -58,   -58,   167,   169,    62,    29,     2,     3,     4,
       5,   -59,   157,   308,     8,   -62,   -62,    72,   297,   -55,
     175,     9,    10,    11,    12,   -59,   -59,   298,   283,   283,
     180,   181,   -62,    19,    18,   344,   172,   -55,   186,   352,
     -63,   -63,   -63,   161,   -59,    25,   466,   297,   -58,   348,
     350,   -56,    30,   162,    31,    25,    25,   -95,   -95,   -63,
     -63,   163,   185,    25,   -97,   155,   -58,   284,   284,   -56,
     -56,   535,   164,    30,    64,    31,   187,   188,   189,   190,
     165,   393,    -9,     8,    27,   299,   -63,   -63,   -63,   349,
       9,    10,    11,   191,    27,    27,   285,   285,   -67,   -67,
     -67,   -67,    27,   192,    98,   -63,   135,   -51,   -51,   220,
     135,   297,   -56,    28,   -20,   -20,   422,   178,   -67,   -67,
     -62,   -62,   351,    28,    28,   -70,   -70,   -70,   -70,   -13,
     -56,    28,    71,   -55,   286,   286,   517,   183,   428,   -62,
     -62,   430,   104,    71,   -58,   -70,   -70,   184,   527,   -55,
    -104,    29,   300,   -71,   -71,   -71,   -71,   301,   302,   135,
     -58,    29,    29,   352,   -66,   -66,   -66,   457,   337,    29,
     338,    71,   -56,   -71,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,   346,   -66,   -66,   -17,   158,   550,   -56,   463,
     465,   104,   -19,   -19,   556,  -104,  -104,  -104,   559,   341,
    -104,   287,   287,   288,   288,   342,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -77,   -77,   -77,   -77,    30,  -104,
      31,   578,   264,   265,   135,   388,   -99,    80,    30,    30,
      31,    31,   -99,   395,   -77,   -77,    30,   425,    31,   587,
     460,   389,   220,   -41,   -41,   220,   -41,   -41,   -41,   -41,
     -41,   -41,   390,   -41,   391,   -67,   -67,   -67,   -67,   135,
     -41,   -41,   -41,   -41,   -41,   -41,   396,   -41,   177,   -41,
     -41,    48,    49,   -41,   433,   -67,   -41,    54,    55,   514,
     514,   104,   -54,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,   289,   289,   104,   -31,   -31,   398,   -31,   -31,   -31,
     -31,   -31,   -31,  -110,   -31,   534,   -21,   -21,   419,  -110,
     221,   -31,   -31,   -31,   -31,   -31,   -31,   544,   -31,   -31,
     -31,   -31,   220,   289,   -31,  -104,  -104,   -31,   436,   547,
     549,  -107,   104,   508,   516,   -76,   -76,   -76,   -76,   293,
    -108,   289,   289,   293,   268,   524,   526,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,   -76,   -76,   531,   507,   507,
     352,   -64,   -64,   -64,   514,   514,   104,  -111,   468,   289,
     283,   283,   470,  -111,   514,   -94,   -94,   540,   -18,   -18,
     -64,   -64,   514,   514,   293,  -104,  -104,   471,   514,   473,
     554,   475,   555,   221,   222,   557,   558,   509,   509,   227,
     228,   476,   283,   478,   -68,   -68,   -68,   -68,   480,   284,
     284,   353,   -71,   -71,   -71,   -71,   354,   355,   575,   577,
     283,   283,   579,   580,   -68,   -68,   510,   510,   581,   -60,
     -60,    72,   -71,   -71,   481,   483,   585,   586,   285,   285,
     482,   284,   589,   507,   507,   485,   -60,   487,   283,   -70,
     -70,   -70,   -70,   507,   -73,   -73,   -73,   -73,   488,   284,
     284,   507,   507,   490,   511,   511,   492,   507,   493,   -70,
     285,   -60,   -60,   351,   -73,   -73,   286,   286,   -72,   -72,
     -72,   -72,   509,   509,   494,   495,   496,   284,   285,   285,
     -60,   -60,   509,   299,   -66,   -66,   -66,   497,   -72,   -72,
     509,   509,   -77,   -77,   -77,   -77,   509,   498,   286,   499,
     518,   510,   510,   -66,   519,   520,   285,   -76,   -76,   -76,
     -76,   510,   -77,   -62,   -62,   298,   286,   286,   521,   510,
     510,   512,   512,   513,   513,   510,   522,   -76,   528,   529,
     530,   537,   -62,   287,   287,   288,   288,   532,   539,   511,
     511,   543,   552,    85,   286,   208,   209,   210,   211,   511,
     560,   561,     8,   563,   565,   566,   568,   511,   511,     9,
      10,    11,   212,   511,   567,   287,   569,   288,   570,   571,
     -35,   -35,   213,   -35,   -35,   -35,   -35,   -35,   -35,   572,
     -35,   573,   584,   287,   287,   288,   288,   -35,   -35,   -35,
     -35,   -35,   -35,   588,   -35,   -35,   -35,   -35,    68,   290,
     -35,   174,   153,   -35,   204,     0,   512,   512,   513,   513,
     173,   287,     0,   288,   268,   269,   512,     0,   513,     0,
     274,   275,     0,     0,   512,   512,   513,   513,     0,     0,
     512,    83,   513,     0,   217,   217,   217,   217,   217,   217,
     217,   217,    99,   204,     0,     0,   204,   221,   222,   223,
     224,   225,   226,   227,   228,     0,   217,   217,   217,   217,
     217,   217,   217,   217,   217,     0,   261,   -30,   -30,   108,
     -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,     0,   299,
     -64,   -64,   -64,     0,   -30,   -30,   -30,   -30,   -30,   -30,
       0,   -30,   -30,   -30,   -30,     0,     0,   -30,     0,   -64,
     -30,   154,   -60,   -60,   298,   -32,   -32,     0,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,     0,   -68,   -68,   -68,
     -68,   -60,   -32,   -32,   -32,   -32,   -32,   -32,   159,   -32,
     -32,   -32,   -32,     0,     0,   -32,     0,   -68,   -32,     0,
       0,   261,   -73,   -73,   -73,   -73,     0,     0,     0,   -33,
     -33,     0,   -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,
       0,     0,   -73,     0,   204,     0,   -33,   -33,   -33,   -33,
     -33,   -33,     0,   -33,   -33,   -33,   -33,     0,   204,   -33,
       0,     0,   -33,     0,     0,     0,    88,   204,   208,   209,
     210,   211,     0,     0,     0,     8,     0,     0,     0,   204,
     217,     0,     9,    10,    11,   212,     0,   321,   321,   321,
     321,   321,   321,   321,   321,   213,     0,     0,     0,    -3,
       1,     0,     2,     3,     4,     5,     6,     7,     0,     8,
       0,   -72,   -72,   -72,   -72,   204,     9,    10,    11,    12,
      13,    14,     0,    15,   261,    16,    17,     0,     0,    18,
       0,   -72,    19,     0,   372,   372,   372,   372,   372,   372,
     372,   372,    90,     0,   208,   209,   210,   211,    48,    49,
      50,     8,     0,    53,    54,    55,     0,     0,     9,    10,
      11,   212,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   213,   261,     0,     0,     0,   261,    73,   -63,   -63,
     -63,     0,   204,    92,   321,   208,   209,   210,   211,     0,
       0,     0,     8,     0,     0,   -63,     0,     0,     0,     9,
      10,    11,   212,   426,   204,     0,     0,   204,   200,     0,
       0,     0,   213,     0,     0,   372,   372,   372,   372,   372,
     372,   372,   372,   372,     0,   261,     0,     0,     0,     0,
       0,    79,     0,   204,     0,   372,     0,     0,    84,    87,
      87,    87,    87,    87,    87,    87,     0,   200,     0,     0,
     200,    48,    49,    50,   461,   204,   204,    54,    55,     0,
      87,    87,    87,    87,    87,    87,    87,   131,    87,     0,
     257,     0,     0,     0,   -34,   -34,     0,   -34,   -34,   -34,
     -34,   -34,   -34,     0,   -34,     0,     0,     0,     0,     0,
     261,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,   -34,
     -34,   -34,     0,     0,   -34,     0,     0,   -34,     0,   -40,
     -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,
       0,     0,     0,     0,     0,   261,   -40,   -40,   -40,   -40,
     -40,   -40,     0,   -40,   -40,   -40,   -40,     0,     0,   -40,
       0,     0,   -40,     0,     0,   257,    74,   -71,   -71,   -71,
     -71,    75,    76,   -48,   -48,     0,   -48,   -48,   -48,   -48,
     -48,   -48,     0,   -48,     0,   -71,     0,     0,   200,     0,
     -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,   -48,
     -48,     0,   200,   -48,     0,     0,   -48,     0,     0,     0,
       0,   305,     0,     0,   545,   204,   204,     0,     0,     0,
     221,   222,   223,   200,   309,   204,   227,   228,     0,   204,
       0,   317,   326,   326,   326,   326,   326,   326,   326,   -67,
     -67,   -67,   -67,     0,    94,     0,   208,   209,   210,   211,
       0,     0,     0,     8,     0,     0,     0,   -67,     0,   200,
       9,    10,    11,   212,     0,   268,   269,   270,   358,     0,
     204,   274,   275,   213,   -70,   -70,   -70,   -70,   368,   377,
     377,   377,   377,   377,   377,   377,   100,     0,   187,   188,
     189,   190,   -70,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   191,   326,   326,   326,   326,
     326,   326,   326,   414,   326,   192,   257,     0,     0,     0,
     257,    73,   -66,   -66,   -66,     0,   200,   102,   423,   187,
     188,   189,   190,     0,     0,     0,     8,     0,     0,   -66,
       0,     0,     0,     9,    10,    11,   191,     0,   200,     0,
       0,   200,   201,     0,     0,     0,   192,     0,     0,   377,
     377,   377,   377,   377,   377,   377,   452,   377,     0,   257,
       0,     0,   -77,   -77,   -77,   -77,     0,   200,     0,   458,
       0,     0,   214,   214,   214,   214,   214,   214,   214,   214,
     -77,   201,     0,     0,   201,   -76,   -76,   -76,   -76,   200,
     200,     0,     0,     0,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   -76,   258,     0,     0,     0,   -47,   -47,
       0,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,     0,
       0,     0,     0,     0,   257,   -47,   -47,   -47,   -47,   -47,
     -47,     0,   -47,   -47,   -47,   -47,     0,     0,   -47,     0,
       0,   -47,     0,   -23,   -23,     0,   -23,   -23,   -23,   -23,
     -23,   -23,     0,   -23,     0,     0,     0,     0,     0,   257,
     -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,
     -23,     0,     0,   -23,     0,     0,   -23,     0,     0,   258,
     -31,     0,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,
       0,     0,    73,   -64,   -64,   -64,   -31,   -31,   -31,   -31,
     -31,   -31,   201,   -31,   -31,   -31,   -31,     0,     0,   -31,
     -64,     0,   -31,   -31,     0,   116,   201,   208,   209,   210,
     211,   221,   222,   223,     8,   201,   226,   227,   228,   200,
     200,     9,    10,    11,   212,     0,     0,   201,   214,   200,
       0,     0,     0,   200,   213,   318,   318,   318,   318,   318,
     318,   318,   318,   -68,   -68,   -68,   -68,     0,   118,     0,
     208,   209,   210,   211,     0,     0,     0,     8,     0,     0,
       0,   -68,     0,   201,     9,    10,    11,   212,     0,     0,
       0,     0,   258,     0,   200,     0,     0,   213,   -73,   -73,
     -73,   -73,   369,   369,   369,   369,   369,   369,   369,   369,
     120,     0,   208,   209,   210,   211,   -73,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   212,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   213,
     258,     0,     0,     0,   258,   -72,   -72,   -72,   -72,     0,
     201,   122,   318,   208,   209,   210,   211,     0,     0,     0,
       8,     0,     0,   -72,     0,     0,     0,     9,    10,    11,
     212,     0,   201,     0,     0,   201,   202,     0,     0,     0,
     213,     0,     0,   369,   369,   369,   369,   369,   369,   369,
     369,   369,     0,   258,     0,     0,     0,     0,     0,     0,
       0,   201,     0,   369,     0,     0,   215,   215,   215,   215,
     215,   215,   215,   215,     0,   202,     0,     0,   202,     0,
     268,   269,   270,   201,   201,   273,   274,   275,   215,   215,
     215,   215,   215,   215,   215,   215,   215,     0,   259,     0,
       0,     0,     0,   -44,     0,   -44,   -44,   -44,   -44,   -44,
     -44,     0,   -44,     0,     0,     0,     0,     0,   258,   -44,
     -44,   -44,   -44,   -44,   -44,     0,   -44,   536,   -44,   -44,
       0,     0,   -44,     0,     0,   -44,   -44,     0,   -35,     0,
     -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,     0,     0,
       0,     0,     0,   258,   -35,   -35,   -35,   -35,   -35,   -35,
       0,   -35,   -35,   -35,   -35,     0,     0,   -35,     0,     0,
     -35,   -35,     0,   259,   -30,     0,   -30,   -30,   -30,   -30,
     -30,   -30,     0,   -30,     0,     0,     0,     0,     0,     0,
     -30,   -30,   -30,   -30,   -30,   -30,   202,   -30,   -30,   -30,
     -30,     0,     0,   -30,     0,     0,   -30,   -30,     0,   124,
     202,   208,   209,   210,   211,     0,     0,     0,     8,   202,
       0,     0,     0,   201,   201,     9,    10,    11,   212,     0,
       0,   202,   215,   201,     0,     0,     0,   201,   213,   319,
     319,   319,   319,   319,   319,   319,   319,     0,     0,     0,
       0,     0,   126,     0,   208,   209,   210,   211,     0,     0,
       0,     8,     0,     0,     0,     0,     0,   202,     9,    10,
      11,   212,     0,     0,     0,     0,   259,     0,   201,     0,
       0,   213,     0,     0,     0,     0,   370,   370,   370,   370,
     370,   370,   370,   370,   128,     0,   208,   209,   210,   211,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   212,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   213,   259,     0,     0,     0,   259,     0,
       0,     0,     0,     0,   202,   130,   319,   208,   209,   210,
     211,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   212,     0,   202,     0,     0,   202,
     203,     0,     0,     0,   213,     0,     0,   370,   370,   370,
     370,   370,   370,   370,   370,   370,     0,   259,     0,     0,
       0,     0,     0,     0,     0,   202,     0,   370,     0,     0,
     216,   216,   216,   216,   216,   216,   216,   216,     0,   203,
       0,     0,   203,     0,     0,     0,     0,   202,   202,     0,
       0,     0,   216,   216,   216,   216,   216,   216,   216,   216,
     216,     0,   260,     0,     0,     0,     0,   -32,     0,   -32,
     -32,   -32,   -32,   -32,   -32,     0,   -32,     0,     0,     0,
       0,     0,   259,   -32,   -32,   -32,   -32,   -32,   -32,     0,
     -32,   -32,   -32,   -32,     0,     0,   -32,     0,     0,   -32,
     -32,     0,   -33,     0,   -33,   -33,   -33,   -33,   -33,   -33,
       0,   -33,     0,     0,     0,     0,     0,   259,   -33,   -33,
     -33,   -33,   -33,   -33,     0,   -33,   -33,   -33,   -33,     0,
       0,   -33,     0,     0,   -33,   -33,     0,   260,   -34,     0,
     -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,     0,     0,
       0,     0,     0,     0,   -34,   -34,   -34,   -34,   -34,   -34,
     203,   -34,   -34,   -34,   -34,     0,     0,   -34,     0,     0,
     -34,   -34,     0,   132,   203,   208,   209,   210,   211,     0,
       0,     0,     8,   203,     0,     0,     0,   202,   202,     9,
      10,    11,   212,     0,     0,   203,   216,   202,     0,     0,
       0,   202,   213,   320,   320,   320,   320,   320,   320,   320,
     320,     0,     0,     0,     0,     0,   291,     0,   244,   245,
     246,   247,     0,     0,     0,     8,     0,     0,     0,     0,
       0,   203,     9,    10,    11,   248,     0,     0,     0,     0,
     260,     0,   202,     0,     0,   249,     0,     0,     0,     0,
     371,   371,   371,   371,   371,   371,   371,   371,   294,     0,
     187,   188,   189,   190,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   191,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   192,   260,     0,
       0,     0,   260,     0,     0,     0,     0,     0,   203,   307,
     320,   187,   188,   189,   190,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   191,     0,
     203,     0,     0,   203,   205,     0,     0,     0,   192,     0,
       0,   371,   371,   371,   371,   371,   371,   371,   371,   371,
       0,   260,     0,     0,     0,     0,     0,     0,     0,   203,
       0,   371,     0,     0,   218,   218,   218,   218,   218,   218,
     218,   218,     0,   205,     0,     0,   205,     0,     0,     0,
       0,   203,   203,     0,     0,     0,   218,   218,   218,   218,
     218,   218,   218,   218,   218,     0,   262,     0,     0,     0,
       0,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,
     -41,     0,     0,     0,     0,     0,   260,   -41,   -41,   -41,
     -41,   -41,   -41,     0,   -41,   538,   -41,   -41,     0,     0,
     -41,     0,     0,   -41,   -41,   -39,   -39,     0,   -39,   -39,
     -39,   -39,   -39,   -39,     0,   -39,     0,     0,     0,     0,
       0,   260,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,
     -39,   -39,   -39,     0,     0,   -39,     0,     0,   -39,     0,
       0,   262,     0,     0,     0,     0,     0,     0,     0,   -36,
     -36,     0,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,
       0,     0,     0,     0,   205,     0,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,   -36,   -36,   -36,     0,   205,   -36,
       0,     0,   -36,    48,    49,    50,    51,   205,    53,    54,
      55,   203,   203,     0,     0,     0,     0,     0,     0,   205,
     218,   203,     0,     0,     0,   203,     0,   322,   322,   322,
     322,   322,   322,   322,   322,     0,     0,     0,     0,     0,
     324,     0,   311,   312,   313,   314,     0,     0,     0,     8,
       0,     0,     0,     0,     0,   205,     9,    10,    11,   315,
       0,     0,     0,     0,   262,     0,   203,     0,     0,   316,
       0,     0,     0,     0,   373,   373,   373,   373,   373,   373,
     373,   373,   327,     0,   311,   312,   313,   314,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   315,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   316,   262,     0,     0,     0,   262,     0,     0,     0,
       0,     0,   205,   329,   322,   311,   312,   313,   314,     0,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   315,     0,   205,     0,     0,   205,   206,     0,
       0,     0,   316,     0,     0,   373,   373,   373,   373,   373,
     373,   373,   373,   373,     0,   262,     0,     0,     0,     0,
       0,     0,     0,   205,     0,   373,     0,     0,   219,   219,
     219,   219,   219,   219,   219,   219,     0,   206,     0,     0,
     206,     0,     0,     0,     0,   205,   205,     0,     0,     0,
     219,   219,   219,   219,   219,   219,   219,   219,   219,     0,
     263,     0,     0,     0,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,     0,     0,     0,     0,     0,
     262,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,   -38,
     -38,   -38,     0,     0,   -38,     0,     0,   -38,     0,   -37,
     -37,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,
       0,     0,     0,     0,     0,   262,   -37,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,   -37,   -37,     0,     0,   -37,
       0,     0,   -37,     0,     0,   263,     0,     0,     0,     0,
       0,     0,     0,   -44,   -44,     0,   -44,   -44,   -44,   -44,
     -44,   -44,     0,   -44,     0,     0,     0,     0,   206,     0,
     -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,   541,   -44,
     -44,     0,   206,   -44,     0,     0,   -44,   221,   222,   223,
     224,   206,   226,   227,   228,   205,   205,     0,     0,     0,
       0,     0,     0,   206,   219,   205,     0,     0,     0,   205,
       0,   323,   323,   323,   323,   323,   323,   323,   323,     0,
       0,     0,     0,     0,   331,     0,   311,   312,   313,   314,
       0,     0,     0,     8,     0,     0,     0,     0,     0,   206,
       9,    10,    11,   315,     0,     0,     0,     0,   263,     0,
     205,     0,     0,   316,     0,     0,     0,     0,   374,   374,
     374,   374,   374,   374,   374,   374,   333,     0,   311,   312,
     313,   314,     0,     0,     0,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   315,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   316,   263,     0,     0,     0,
     263,     0,     0,     0,     0,     0,   206,     0,   323,     0,
     -90,   -90,   -90,   -90,     0,     0,   197,   -90,     0,     0,
       0,     0,     0,     0,   -90,   -90,   -90,   -90,   206,     0,
       0,   206,     0,     0,     0,     0,     0,   -90,     0,   374,
     374,   374,   374,   374,   374,   374,   374,   374,    89,   263,
       0,     0,    96,    97,     0,   197,     0,   206,   197,   374,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,     0,     0,
       0,   123,     0,   127,   129,     0,     0,     0,   254,   206,
     206,  -104,  -104,   -43,   -43,     0,   -43,   -43,   -43,   -43,
     -43,   -43,     0,   -43,     0,     0,     0,     0,     0,     0,
     -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,
     -43,     0,     0,   -43,   263,   199,   -43,   -41,   -41,     0,
     -41,   -41,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,
       0,     0,     0,     0,   -41,   -41,   -41,   -41,   -41,   -41,
       0,   -41,   542,   -41,   -41,     0,    86,   -41,     0,   263,
     -41,     0,     0,   254,   199,     0,     0,   199,     0,     0,
       0,     0,     0,   -40,     0,   -40,   -40,   -40,   -40,   -40,
     -40,   125,   -40,     0,     0,     0,   197,   256,     0,   -40,
     -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,   -40,
     197,     0,   -40,     0,     0,   -40,   -40,     0,   343,     0,
       2,     3,     4,     5,     0,     0,     0,     8,     0,     0,
       0,   197,     0,     0,     9,    10,    11,    12,     0,   206,
     206,   328,   197,   197,   197,   335,   336,    18,     0,   206,
       0,     0,     1,   206,     2,     3,     4,     5,   277,   278,
       0,     8,     0,     0,     0,     0,     0,   197,     9,    10,
      11,    12,   256,     0,     0,   279,   166,   280,   281,     0,
       0,    18,     0,     0,   282,     0,     0,     0,   379,   254,
     254,   254,   386,   387,   206,   199,   -88,   -88,   -88,   -88,
       0,     0,     0,   -88,     0,     0,     0,     0,     0,   199,
     -88,   -88,   -88,   -88,   197,   197,   197,   406,     0,   410,
     412,     0,   197,   -88,   254,     0,     0,     0,   254,     0,
     199,     0,     0,     0,   197,     0,     0,     0,     0,   325,
     199,   199,   199,   199,   199,   199,     0,   -89,   -89,   -89,
     -89,     0,     0,     0,   -89,     0,   197,     0,     0,   197,
       0,   -89,   -89,   -89,   -89,     0,   199,   254,   254,   254,
     444,     0,   448,   450,   -89,   254,     0,   254,     0,     0,
       0,     0,     0,     0,     0,   197,   376,   256,   256,   256,
     256,   256,   256,     0,     0,     0,     0,     0,   198,    48,
      49,    50,    51,    52,    53,    54,    55,   197,   197,     0,
       0,     0,     0,   199,   199,   199,   199,   408,   199,   199,
       0,   199,     0,   256,     0,     0,     0,   256,     0,   -91,
     -91,   -91,   -91,   199,     0,     0,   -91,   198,     0,     0,
     198,     0,   254,   -91,   -91,   -91,   -91,   268,   269,   270,
     271,   272,   273,   274,   275,   199,   -91,     0,   199,     0,
     255,     0,   196,     0,     0,     0,   256,   256,   256,   256,
     446,   256,   256,     0,   256,     0,   256,   254,     2,     3,
       4,     5,     0,     0,   199,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,    12,     0,    95,     0,     0,
       0,   196,     0,     0,   196,    18,   199,   199,    77,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   121,     0,     0,     0,
       0,     0,     0,     0,   253,     0,     0,     1,   -78,     2,
       3,     4,     5,   277,   278,   255,     8,     0,     0,     0,
       0,   256,     0,     9,    10,    11,    12,   197,   197,     0,
     279,   168,   280,   281,     0,     0,    18,   197,   198,   282,
       0,   197,   -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,
       0,   -48,   198,     0,     0,     0,   256,     0,   -48,   -48,
     -48,   -48,   -48,   -48,     0,   -48,   -48,   -48,   -48,     0,
       0,   -48,     0,   198,   -48,   -48,     0,     0,     0,   253,
       0,     0,   197,   198,   198,   198,   198,   198,   198,     1,
       0,     2,     3,     4,     5,   500,   501,     0,     8,     0,
       0,     0,   196,     0,     0,     9,    10,    11,    12,   198,
       0,     0,   502,   503,   504,   505,   196,     0,    18,     0,
       0,   506,     0,     0,     0,     0,   199,   199,     0,     0,
     255,   255,   255,   255,   255,   255,   199,   196,     0,     0,
     199,     0,     0,     0,     0,     0,     0,     0,   196,   196,
     334,   195,     0,     0,     0,     0,   198,   198,   198,   198,
       0,   198,   198,     0,   198,     0,   255,     0,     0,     0,
     255,     0,     0,   196,     0,     0,   198,     0,     0,     0,
       0,   199,     0,     0,    91,     0,     0,     0,     0,     0,
     195,     0,     0,   195,     0,   253,   253,   385,   198,     0,
       0,   198,     0,     0,   119,     0,     0,     0,     0,   255,
     255,   255,   255,   252,   255,   255,     0,   255,     0,   255,
     196,   196,   404,     0,     0,     0,     0,   198,   196,     0,
     253,     0,     0,     0,   253,     0,     0,     0,     0,   347,
     196,   187,   188,   189,   190,     0,     0,     0,     8,   198,
     198,     0,     0,     0,     0,     9,    10,    11,   191,     0,
       0,     0,   196,     0,     0,   196,     0,     0,   192,     0,
       0,     0,     0,   253,   253,   442,     0,     0,   194,     0,
       0,   253,     0,   253,   255,   193,     0,     0,   252,     0,
       0,   196,   221,   222,   223,   224,   225,   226,   227,   228,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,     0,     0,
       0,   195,    93,   196,   196,     0,     0,   194,     0,   255,
     194,   359,   -99,   -99,   193,   195,   -99,   193,     0,     0,
     117,     0,     0,   375,     0,   362,   363,   364,   365,     0,
     251,     0,     8,     0,     0,   133,   195,   250,   253,     9,
      10,    11,   366,   208,   209,   210,   211,   330,   195,     0,
       8,     0,   367,     0,     0,     0,     0,     9,    10,    11,
     212,     0,    48,    49,    50,    51,    52,    53,    54,    55,
     213,     0,   195,   253,     0,     0,     0,     0,     0,   198,
     198,   -22,   106,   -22,   -22,   -22,   -22,   -22,   -22,   198,
     -22,     0,     0,   198,   381,   252,     0,   -22,   -22,   -22,
     -22,   -22,   -22,     0,   -22,   251,   -22,   -22,     0,     0,
     -22,     0,   250,   -22,   -22,     0,     0,     0,     0,   195,
     402,     0,     0,     0,     0,     0,     0,   195,   194,   252,
       0,     0,     0,   252,   198,   193,     0,     0,     0,   195,
       0,     0,   194,   196,   196,   268,   269,   270,   271,   193,
     273,   274,   275,   196,     0,     0,     0,   196,     0,     0,
       0,   195,     0,   194,   195,     0,     0,     0,     0,     0,
     193,     0,   252,   440,     0,   332,     0,     0,     0,     0,
     252,     0,   252,     0,     0,     0,     0,     0,     0,     0,
     195,   378,     0,   362,   363,   364,   365,     0,   196,   194,
       8,     0,     0,     0,     0,     0,   193,     9,    10,    11,
     366,     0,   195,   195,     0,     0,     0,     0,     0,     0,
     367,     0,   383,     0,     0,     0,     1,     0,     2,     3,
       4,     5,   500,   501,     0,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,    12,   400,   252,     0,   502,
     515,   504,   505,     0,   194,    18,   251,     0,   506,     0,
     251,   416,     0,   250,     0,     0,   194,   250,     0,   187,
     188,   189,   190,   193,     0,     0,     8,     0,     0,     0,
       0,     0,   252,     9,    10,    11,   191,     0,   194,     0,
       0,   194,     0,     0,     0,   193,   192,     0,   193,   438,
       0,     0,     0,     0,     0,     0,     0,   251,     0,   251,
       0,     0,     0,     0,   454,     0,   250,   194,     0,     0,
       0,     0,     0,     0,   193,     1,     0,     2,     3,     4,
       5,   277,   278,     0,     8,     0,     0,     0,     0,   194,
     194,     9,    10,    11,    12,     0,   193,   193,   279,   523,
     280,   281,   195,   195,    18,     0,     0,   282,     0,     0,
       0,     0,   195,     0,     0,     0,   195,     0,     0,     0,
       0,     0,   -46,   -46,   251,   -46,   -46,   -46,   -46,   -46,
     -46,   250,   -46,     0,     0,     0,     0,     0,     0,   -46,
     -46,   -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,
       0,     0,   -46,     0,     0,   -46,     0,   195,   -47,   251,
     -47,   -47,   -47,   -47,   -47,   -47,   250,   -47,     0,     0,
       0,     0,     0,     0,   -47,   -47,   -47,   -47,   -47,   -47,
       0,   -47,   -47,   -47,   -47,     0,     0,   -47,     0,     0,
     -47,   -47,   -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,
     -45,     0,   -45,     0,     0,     0,     0,     0,     0,   -45,
     -45,   -45,   -45,   -45,   -45,     0,   -45,   -45,   -45,   -45,
       0,     0,   -45,     0,     0,   -45,     0,     0,     0,   194,
     194,     0,     0,     0,     0,     0,   193,   193,     0,   194,
       0,     0,     0,   194,     0,     0,   193,     0,   -42,   -42,
     193,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,     0,
       0,     0,     0,     0,     0,   -42,   -42,   -42,   -42,   -42,
     -42,     0,   -42,   -42,   -42,   -42,     0,     0,   -42,     0,
       0,   -42,     0,   -23,   194,   -23,   -23,   -23,   -23,   -23,
     -23,   193,   -23,     0,     0,     0,     0,     0,     0,   -23,
     -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,
       0,     0,   -23,     0,     0,   -23,   -23,   -39,     0,   -39,
     -39,   -39,   -39,   -39,   -39,     0,   -39,     0,     0,     0,
       0,     0,     0,   -39,   -39,   -39,   -39,   -39,   -39,     0,
     -39,   -39,   -39,   -39,     0,     0,   -39,     0,     0,   -39,
     -39,   -36,     0,   -36,   -36,   -36,   -36,   -36,   -36,     0,
     -36,     0,     0,     0,     0,     0,     0,   -36,   -36,   -36,
     -36,   -36,   -36,     0,   -36,   -36,   -36,   -36,     0,     0,
     -36,     0,     0,   -36,   -36,   -38,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,     0,     0,     0,     0,     0,
       0,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,   -38,
     -38,   -38,     0,     0,   -38,     0,     0,   -38,   -38,   -37,
       0,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,     0,
       0,     0,     0,     0,     0,   -37,   -37,   -37,   -37,   -37,
     -37,     0,   -37,   -37,   -37,   -37,     0,     0,   -37,     0,
       0,   -37,   -37,   -44,     0,   -44,   -44,   -44,   -44,   -44,
     -44,     0,   -44,     0,     0,     0,     0,     0,     0,   -44,
     -44,   -44,   -44,   -44,   -44,     0,   -44,   582,   -44,   -44,
       0,     0,   -44,     0,     0,   -44,   -44,   -43,     0,   -43,
     -43,   -43,   -43,   -43,   -43,     0,   -43,     0,     0,     0,
       0,     0,     0,   -43,   -43,   -43,   -43,   -43,   -43,     0,
     -43,   -43,   -43,   -43,     0,     0,   -43,     0,     0,   -43,
     -43,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,
     -41,     0,     0,     0,     0,     0,     0,   -41,   -41,   -41,
     -41,   -41,   -41,     0,   -41,   583,   -41,   -41,     0,     0,
     -41,     0,     0,   -41,   -41,   -49,   -49,     0,   -49,   -49,
     -49,   -49,   -49,   -49,     0,   -49,     0,     0,     0,     0,
       0,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,   -49,
     -49,   -49,   -49,     0,     0,   -49,     0,   -46,   -49,   -46,
     -46,   -46,   -46,   -46,   -46,     0,   -46,     0,     0,     0,
       0,     0,     0,   -46,   -46,   -46,   -46,   -46,   -46,     0,
     -46,   -46,   -46,   -46,     0,     0,   -46,     0,     0,   -46,
     -46,   -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,
     -45,     0,     0,     0,     0,     0,     0,   -45,   -45,   -45,
     -45,   -45,   -45,     0,   -45,   -45,   -45,   -45,     0,     0,
     -45,     0,     0,   -45,   -45,   -42,     0,   -42,   -42,   -42,
     -42,   -42,   -42,     0,   -42,     0,     0,     0,     0,     0,
       0,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,
     -42,   -42,     0,     0,   -42,     0,     0,   -42,   -42,   -49,
       0,   -49,   -49,   -49,   -49,   -49,   -49,     0,   -49,     0,
       0,     0,     0,     0,     0,   -49,   -49,   -49,   -49,   -49,
     -49,     0,   -49,   -49,   -49,   -49,     0,     0,   -49,     0,
       0,   -49,   -49,    -2,     1,     0,     2,     3,     4,     5,
       6,     7,     0,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,    12,    13,    14,     0,    15,     0,    16,
      17,     0,     0,    18,    -5,    -5,    19,    -5,    -5,    -5,
      -5,    -5,    -5,     0,    -5,     0,     0,     0,     0,     0,
       0,    -5,    -5,    -5,    -5,    -5,    -5,     0,    -5,     0,
      -5,    -5,     0,     0,    -5,    -7,    -7,    -5,    -7,    -7,
      -7,    -7,    -7,    -7,     0,    -7,     0,     0,     0,     0,
       0,     0,    -7,    -7,    -7,    -7,    -7,    -7,     0,    -7,
       0,    -7,    -7,     0,     0,    -7,    -6,    -6,    -7,    -6,
      -6,    -6,    -6,    -6,    -6,     0,    -6,     0,     0,     0,
       0,     0,     0,    -6,    -6,    -6,    -6,    -6,    -6,     0,
      -6,     0,    -6,    -6,     0,     0,    -6,   -31,   -31,    -6,
     -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,     0,     0,
       0,     0,     0,     0,   -31,   -31,   -31,   -31,   -31,   -31,
       0,   -31,     0,   -31,   -31,     0,     0,   -31,    -8,    -8,
     -31,    -8,    -8,    -8,    -8,    -8,    -8,     0,    -8,     0,
       0,     0,     0,     0,     0,    -8,    -8,    -8,    -8,    -8,
      -8,     0,    -8,     0,    -8,    -8,     0,     0,    -8,   -35,
     -35,    -8,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,
       0,     0,     0,     0,     0,     0,   -35,   -35,   -35,   -35,
     -35,   -35,     0,   -35,     0,   -35,   -35,     0,     0,   -35,
     -30,   -30,   -35,   -30,   -30,   -30,   -30,   -30,   -30,     0,
     -30,     0,     0,     0,     0,     0,     0,   -30,   -30,   -30,
     -30,   -30,   -30,     0,   -30,     0,   -30,   -30,     0,     0,
     -30,   -32,   -32,   -30,   -32,   -32,   -32,   -32,   -32,   -32,
       0,   -32,     0,     0,     0,     0,     0,     0,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,     0,   -32,   -32,     0,
       0,   -32,   -33,   -33,   -32,   -33,   -33,   -33,   -33,   -33,
     -33,     0,   -33,     0,     0,     0,     0,     0,     0,   -33,
     -33,   -33,   -33,   -33,   -33,     0,   -33,     0,   -33,   -33,
       0,     0,   -33,   -34,   -34,   -33,   -34,   -34,   -34,   -34,
     -34,   -34,     0,   -34,     0,     0,     0,     0,     0,     0,
     -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,     0,   -34,
     -34,     0,     0,   -34,     0,     1,   -34,     2,     3,     4,
       5,   229,   230,     0,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,    12,   231,   232,     0,   233,     0,
     234,   235,     0,     0,    18,     0,     0,   236,   -25,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
       0,     0,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,     0,    -4,    -4,     0,     0,    -4,
     -40,   -40,    -4,   -40,   -40,   -40,   -40,   -40,   -40,     0,
     -40,     0,     0,     0,     0,     0,     0,   -40,   -40,   -40,
     -40,   -40,   -40,     0,   -40,     0,   -40,   -40,     0,     0,
     -40,   -11,   -11,   -40,   -11,   -11,   -11,   -11,   -11,   -11,
       0,   -11,     0,     0,     0,     0,     0,     0,   -11,   -11,
     -11,   -11,   -11,   -11,     0,   -11,     0,   -11,   -11,     0,
       0,   -11,   -48,   -48,   -11,   -48,   -48,   -48,   -48,   -48,
     -48,     0,   -48,     0,     0,     0,     0,     0,     0,   -48,
     -48,   -48,   -48,   -48,   -48,     0,   -48,     0,   -48,   -48,
       0,     0,   -48,   -47,   -47,   -48,   -47,   -47,   -47,   -47,
     -47,   -47,     0,   -47,     0,     0,     0,     0,     0,     0,
     -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,     0,   -47,
     -47,     0,     0,   -47,     0,   -28,   -47,   -28,   -28,   -28,
     -28,   -28,   -28,     0,   -28,     0,     0,     0,     0,     0,
       0,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,     0,
     -28,   -28,     0,     0,   -28,     0,     0,   -28,   -28,     1,
       0,     2,     3,     4,     5,   229,   230,     0,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,    12,   231,
     232,     0,   233,     0,   234,   235,     0,     0,    18,     0,
       0,   236,   -24,   -27,     0,   -27,   -27,   -27,   -27,   -27,
     -27,     0,   -27,     0,     0,     0,     0,     0,     0,   -27,
     -27,   -27,   -27,   -27,   -27,     0,   -27,     0,   -27,   -27,
       0,     0,   -27,     0,     0,   -27,   -27,   -29,     0,   -29,
     -29,   -29,   -29,   -29,   -29,     0,   -29,     0,     0,     0,
       0,     0,     0,   -29,   -29,   -29,   -29,   -29,   -29,     0,
     -29,     0,   -29,   -29,     0,     0,   -29,     0,     0,   -29,
     -29,   -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,   -23,
       0,   -23,     0,     0,     0,     0,     0,     0,   -23,   -23,
     -23,   -23,   -23,   -23,     0,   -23,     0,   -23,   -23,     0,
       0,   -23,     0,   -26,   -23,   -26,   -26,   -26,   -26,   -26,
     -26,     0,   -26,     0,     0,     0,     0,     0,     0,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,     0,   -26,   -26,
       0,     0,   -26,     0,     0,   -26,   -26,   -10,   -10,     0,
     -10,   -10,   -10,   -10,   -10,   -10,     0,   -10,     0,     0,
       0,     0,     0,     0,   -10,   -10,   -10,   -10,   -10,   -10,
       0,   -10,     0,   -10,   -10,     0,     0,   -10,   -39,   -39,
     -10,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,     0,
       0,     0,     0,     0,     0,   -39,   -39,   -39,   -39,   -39,
     -39,     0,   -39,     0,   -39,   -39,     0,     0,   -39,   -36,
     -36,   -39,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,
       0,     0,     0,     0,     0,     0,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,     0,   -36,   -36,     0,     0,   -36,
     -38,   -38,   -36,   -38,   -38,   -38,   -38,   -38,   -38,     0,
     -38,     0,     0,     0,     0,     0,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,     0,   -38,   -38,     0,     0,
     -38,   -37,   -37,   -38,   -37,   -37,   -37,   -37,   -37,   -37,
       0,   -37,     0,     0,     0,     0,     0,     0,   -37,   -37,
     -37,   -37,   -37,   -37,     0,   -37,     0,   -37,   -37,     0,
       0,   -37,   -43,   -43,   -37,   -43,   -43,   -43,   -43,   -43,
     -43,     0,   -43,     0,     0,     0,     0,     0,     0,   -43,
     -43,   -43,   -43,   -43,   -43,     0,   -43,     0,   -43,   -43,
       0,     0,   -43,   -15,   -15,   -43,   -15,   -15,   -15,   -15,
     -15,   -15,     0,   -15,     0,     0,     0,     0,     0,     0,
     -15,   -15,   -15,   -15,   -15,   -15,     0,   -15,     0,   -15,
     -15,     0,     0,   -15,   -46,   -46,   -15,   -46,   -46,   -46,
     -46,   -46,   -46,     0,   -46,     0,     0,     0,     0,     0,
       0,   -46,   -46,   -46,   -46,   -46,   -46,     0,   -46,     0,
     -46,   -46,     0,     0,   -46,   -45,   -45,   -46,   -45,   -45,
     -45,   -45,   -45,   -45,     0,   -45,     0,     0,     0,     0,
       0,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,   -45,
       0,   -45,   -45,     0,     0,   -45,   -42,   -42,   -45,   -42,
     -42,   -42,   -42,   -42,   -42,     0,   -42,     0,     0,     0,
       0,     0,     0,   -42,   -42,   -42,   -42,   -42,   -42,     0,
     -42,     0,   -42,   -42,     0,     0,   -42,   -14,   -14,   -42,
     -14,   -14,   -14,   -14,   -14,   -14,     0,   -14,     0,     0,
       0,     0,     0,     0,   -14,   -14,   -14,   -14,   -14,   -14,
       0,   -14,     0,   -14,   -14,     0,     0,   -14,   -49,   -49,
     -14,   -49,   -49,   -49,   -49,   -49,   -49,     0,   -49,     0,
       0,     0,     0,     0,     0,   -49,   -49,   -49,   -49,   -49,
     -49,     0,   -49,     0,   -49,   -49,     0,     0,   -49,     0,
     -31,   -49,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,
       0,     0,     0,     0,     0,     0,   -31,   -31,   -31,   -31,
     -31,   -31,     0,   -31,     0,   -31,   -31,     0,     0,   -31,
       0,     0,   -31,   -31,   -35,     0,   -35,   -35,   -35,   -35,
     -35,   -35,     0,   -35,     0,     0,     0,     0,     0,     0,
     -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,     0,   -35,
     -35,     0,     0,   -35,     0,     0,   -35,   -35,   -30,     0,
     -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,     0,     0,
       0,     0,     0,     0,   -30,   -30,   -30,   -30,   -30,   -30,
       0,   -30,     0,   -30,   -30,     0,     0,   -30,     0,     0,
     -30,   -30,   -32,     0,   -32,   -32,   -32,   -32,   -32,   -32,
       0,   -32,     0,     0,     0,     0,     0,     0,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,     0,   -32,   -32,     0,
       0,   -32,     0,     0,   -32,   -32,   -33,     0,   -33,   -33,
     -33,   -33,   -33,   -33,     0,   -33,     0,     0,     0,     0,
       0,     0,   -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,
       0,   -33,   -33,     0,     0,   -33,     0,     0,   -33,   -33,
     -34,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,
       0,     0,     0,     0,     0,     0,   -34,   -34,   -34,   -34,
     -34,   -34,     0,   -34,     0,   -34,   -34,     0,     0,   -34,
       0,     0,   -34,   -34,   -11,     0,   -11,   -11,   -11,   -11,
     -11,   -11,     0,   -11,     0,     0,     0,     0,     0,     0,
     -11,   -11,   -11,   -11,   -11,   -11,     0,   -11,     0,   -11,
     -11,     0,     0,   -11,     0,     0,   -11,   -11,   -40,     0,
     -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,
       0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,   -40,
       0,   -40,     0,   -40,   -40,     0,     0,   -40,     0,     0,
     -40,   -40,   -10,     0,   -10,   -10,   -10,   -10,   -10,   -10,
       0,   -10,     0,     0,     0,     0,     0,     0,   -10,   -10,
     -10,   -10,   -10,   -10,     0,   -10,     0,   -10,   -10,     0,
       0,   -10,     0,     0,   -10,   -10,   -48,     0,   -48,   -48,
     -48,   -48,   -48,   -48,     0,   -48,     0,     0,     0,     0,
       0,     0,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,
       0,   -48,   -48,     0,     0,   -48,     0,     0,   -48,   -48,
     -47,     0,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,
       0,     0,     0,     0,     0,     0,   -47,   -47,   -47,   -47,
     -47,   -47,     0,   -47,     0,   -47,   -47,     0,     0,   -47,
       0,     0,   -47,   -47,   -23,     0,   -23,   -23,   -23,   -23,
     -23,   -23,     0,   -23,     0,     0,     0,     0,     0,     0,
     -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,     0,   -23,
     -23,     0,     0,   -23,     0,     0,   -23,   -23,   -39,     0,
     -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,     0,     0,
       0,     0,     0,     0,   -39,   -39,   -39,   -39,   -39,   -39,
       0,   -39,     0,   -39,   -39,     0,     0,   -39,     0,     0,
     -39,   -39,   -36,     0,   -36,   -36,   -36,   -36,   -36,   -36,
       0,   -36,     0,     0,     0,     0,     0,     0,   -36,   -36,
     -36,   -36,   -36,   -36,     0,   -36,     0,   -36,   -36,     0,
       0,   -36,     0,     0,   -36,   -36,   -38,     0,   -38,   -38,
     -38,   -38,   -38,   -38,     0,   -38,     0,     0,     0,     0,
       0,     0,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,
       0,   -38,   -38,     0,     0,   -38,     0,     0,   -38,   -38,
     -37,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,
       0,     0,     0,     0,     0,     0,   -37,   -37,   -37,   -37,
     -37,   -37,     0,   -37,     0,   -37,   -37,     0,     0,   -37,
       0,     0,   -37,   -37,   -43,     0,   -43,   -43,   -43,   -43,
     -43,   -43,     0,   -43,     0,     0,     0,     0,     0,     0,
     -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,     0,   -43,
     -43,     0,     0,   -43,     0,     0,   -43,   -43,   -46,     0,
     -46,   -46,   -46,   -46,   -46,   -46,     0,   -46,     0,     0,
       0,     0,     0,     0,   -46,   -46,   -46,   -46,   -46,   -46,
       0,   -46,     0,   -46,   -46,     0,     0,   -46,     0,     0,
     -46,   -46,   -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,
       0,   -45,     0,     0,     0,     0,     0,     0,   -45,   -45,
     -45,   -45,   -45,   -45,     0,   -45,     0,   -45,   -45,     0,
       0,   -45,     0,     0,   -45,   -45,   -42,     0,   -42,   -42,
     -42,   -42,   -42,   -42,     0,   -42,     0,     0,     0,     0,
       0,     0,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,
       0,   -42,   -42,     0,     0,   -42,     0,     0,   -42,   -42,
     -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,   -49,
       0,     0,     0,     0,     0,     0,   -49,   -49,   -49,   -49,
     -49,   -49,     0,   -49,     0,   -49,   -49,     0,     0,   -49,
       0,     0,   -49,   -49,     1,     0,     2,     3,     4,     5,
     277,   278,     0,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,    12,     0,     0,     0,   279,   525,   280,
     281,     0,     0,    18,     0,     1,   282,     2,     3,     4,
       5,   500,   501,     0,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,    12,     0,     0,     0,   502,   574,
     504,   505,     0,     0,    18,     0,     1,   506,     2,     3,
       4,     5,   500,   501,     0,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,    12,     0,     0,     0,   502,
     576,   504,   505,     0,     0,    18,     0,     1,   506,     2,
       3,     4,     5,     6,     7,     0,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,     0,     0,     0,
      15,     0,    16,    17,     0,     0,    18,     0,     1,    19,
       2,     3,     4,     5,   229,   230,     0,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,    12,     0,     0,
       0,   233,     0,   234,   235,     0,     0,    18,     0,     1,
     236,     2,     3,     4,     5,   277,   278,     0,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,    12,     0,
       0,     0,   279,     0,   280,   281,     0,     0,    18,     0,
       1,   282,     2,     3,     4,     5,   500,   501,     0,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,    12,
       0,     0,     0,   502,     0,   504,   505,     0,     0,    18,
       0,   380,   506,   362,   363,   364,   365,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     366,     0,   382,     0,   362,   363,   364,   365,     0,     0,
     367,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   366,     0,   384,     0,   362,   363,   364,   365,     0,
       0,   367,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   366,     0,   392,     0,     2,     3,     4,     5,
       0,     0,   367,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,    12,     0,   399,     0,   311,   312,   313,
     314,     0,     0,    18,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   315,     0,   401,     0,   311,   312,
     313,   314,     0,     0,   316,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   315,     0,   403,     0,   311,
     312,   313,   314,     0,     0,   316,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   315,     0,   405,     0,
     311,   312,   313,   314,     0,     0,   316,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   315,     0,   407,
       0,   311,   312,   313,   314,     0,     0,   316,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   315,     0,
     409,     0,   311,   312,   313,   314,     0,     0,   316,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   315,
       0,   411,     0,   311,   312,   313,   314,     0,     0,   316,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     315,     0,   413,     0,   311,   312,   313,   314,     0,     0,
     316,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   315,     0,   415,     0,   311,   312,   313,   314,     0,
       0,   316,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   315,     0,   421,     0,   187,   188,   189,   190,
       0,     0,   316,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   191,     0,   427,     0,   187,   188,   189,
     190,     0,     0,   192,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   191,     0,   429,     0,   187,   188,
     189,   190,     0,     0,   192,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   191,     0,   437,     0,   362,
     363,   364,   365,     0,     0,   192,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   366,     0,   439,     0,
     362,   363,   364,   365,     0,     0,   367,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   366,     0,   441,
       0,   362,   363,   364,   365,     0,     0,   367,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,   366,     0,
     443,     0,   362,   363,   364,   365,     0,     0,   367,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   366,
       0,   445,     0,   362,   363,   364,   365,     0,     0,   367,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     366,     0,   447,     0,   362,   363,   364,   365,     0,     0,
     367,     8,     0,     0,     0,     0,     0,     0,     9,    10,
      11,   366,     0,   449,     0,   362,   363,   364,   365,     0,
       0,   367,     8,     0,     0,     0,     0,     0,     0,     9,
      10,    11,   366,     0,   451,     0,   362,   363,   364,   365,
       0,     0,   367,     8,     0,     0,     0,     0,     0,     0,
       9,    10,    11,   366,     0,   453,     0,   362,   363,   364,
     365,     0,     0,   367,     8,     0,     0,     0,     0,     0,
       0,     9,    10,    11,   366,     0,   456,     0,   187,   188,
     189,   190,     0,     0,   367,     8,     0,     0,     0,     0,
       0,     0,     9,    10,    11,   191,     0,   462,     0,   187,
     188,   189,   190,     0,     0,   192,     8,     0,     0,     0,
       0,     0,     0,     9,    10,    11,   191,     0,   464,     0,
     187,   188,   189,   190,     0,     0,   192,     8,     0,     0,
       0,     0,     0,     0,     9,    10,    11,   191,     0,   533,
       0,     2,     3,     4,     5,     0,     0,   192,     8,     0,
       0,     0,     0,     0,     0,     9,    10,    11,    12,     0,
     546,     0,   187,   188,   189,   190,     0,     0,    18,     8,
       0,     0,     0,     0,     0,     0,     9,    10,    11,   191,
       0,   548,     0,   187,   188,   189,   190,     0,     0,   192,
       8,     0,     0,     0,     0,     0,     0,     9,    10,    11,
     191,   311,   312,   313,   314,     0,     0,     0,     8,     0,
     192,     0,     0,     0,     0,     9,    10,    11,   315,   244,
     245,   246,   247,     0,     0,     0,     8,     0,   316,     0,
       0,     0,     0,     9,    10,    11,   248,   362,   363,   364,
     365,     0,     0,     0,     8,     0,   249,     0,     0,     0,
       0,     9,    10,    11,   366,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,     0,   367,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,     0,     0,     0,  -104,  -104,     0,     0,
       0,  -104,     0,     0,     0,     0,   306,   -99,     0,     0,
       0,   -99,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,     0,     0,
       0,     0,     0,     0,  -110,  -110,     0,     0,  -110,     0,
       0,     0,  -111,  -111,     0,     0,  -111,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,     0,     0,     0,     0,     0,     0,  -109,
    -109,     0,     0,  -109,     0,     0,     0,  -112,  -112,     0,
       0,  -112,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,     0,     0,
       0,     0,     0,     0,   -82,   -82,     0,     0,   357,     0,
       0,     0,   -86,   -86,     0,     0,   -86,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,     0,     0,     0,     0,     0,     0,   -92,
     -92,     0,     0,   -92,     0,     0,     0,  -100,  -100,     0,
       0,  -100,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,
       0,     0,     0,     0,  -101,  -101,     0,     0,  -101,     0,
       0,     0,   -87,   -87,     0,     0,   -87,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,     0,     0,     0,     0,     0,     0,  -103,
    -103,     0,     0,  -103,     0,     0,     0,  -102,  -102,     0,
       0,  -102,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,     0,     0,
       0,     0,     0,     0,   -93,   -93,     0,     0,   -93,     0,
    -109,     0,     0,     0,     0,     0,  -109,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,     0,     0,     0,     0,  -112,     0,     0,
       0,     0,     0,  -112,     0,   -82,     0,     0,     0,     0,
       0,    78,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,     0,     0,
       0,     0,   -86,     0,     0,     0,     0,     0,   -86,     0,
     -92,     0,     0,     0,     0,     0,   -92,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,     0,     0,     0,     0,  -100,     0,     0,
       0,     0,     0,  -100,     0,  -101,     0,     0,     0,     0,
       0,  -101,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,     0,     0,
       0,     0,   -87,     0,     0,     0,     0,     0,   -87,     0,
    -103,     0,     0,     0,     0,     0,  -103,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,     0,     0,     0,     0,  -102,     0,     0,
       0,     0,     0,  -102,     0,   -93,     0,     0,     0,     0,
       0,   -93,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,     0,     0,
       0,     0,     0,     0,  -110,     0,     0,     0,  -110,     0,
       0,     0,  -111,     0,     0,     0,  -111,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,     0,     0,     0,     0,     0,     0,  -109,
       0,     0,     0,  -109,     0,     0,     0,  -112,     0,     0,
       0,  -112,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,     0,     0,
       0,     0,     0,     0,   -82,     0,     0,     0,   304,     0,
       0,     0,   -86,     0,     0,     0,   -86,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,     0,     0,     0,     0,     0,     0,   -92,
       0,     0,     0,   -92,     0,     0,     0,  -100,     0,     0,
       0,  -100,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,
       0,     0,     0,     0,  -101,     0,     0,     0,  -101,     0,
       0,     0,   -87,     0,     0,     0,   -87,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,     0,     0,     0,     0,     0,     0,  -103,
       0,     0,     0,  -103,     0,     0,     0,  -102,     0,     0,
       0,  -102,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,     0,     0,
       0,     0,     0,     0,   -93,     0,     0,     0,   -93,     0,
       0,  -104,  -104,  -104,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   268,   269,   270,   271,   272,   273,   274,   275,
       0,     0,     0,     0,     0,   459,   -99,   -99,     0,     0,
       0,     0,     0,     0,   -96,   -96,   356,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,     0,     0,     0,     0,     0,     0,   -78,   -78,
       0,     0,     0,     0,     0,     0,  -110,  -110,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,     0,     0,     0,     0,     0,     0,
    -111,  -111,     0,     0,     0,     0,     0,     0,  -109,  -109,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,     0,     0,     0,     0,
       0,     0,  -112,  -112,     0,     0,     0,     0,     0,     0,
     -85,   -85,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,     0,     0,
       0,     0,     0,     0,   -86,   -86,     0,     0,     0,     0,
       0,     0,   -92,   -92,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
       0,     0,     0,     0,     0,     0,  -100,  -100,     0,     0,
       0,     0,     0,     0,  -101,  -101,   356,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,     0,     0,     0,     0,     0,     0,   -81,   -81,
       0,     0,     0,     0,     0,     0,   -82,   -82,   268,   269,
     270,   271,   -57,   273,   274,   275,   268,   269,   270,   -61,
     -61,   273,   274,   275,     0,     0,     0,     0,     0,     0,
     -57,   -57,     0,     0,     0,     0,     0,     0,   -61,   -61,
     268,   269,   270,   -65,   -65,   -65,   274,   275,   268,   269,
     -69,   -69,   -69,   -69,   274,   275,     0,     0,     0,     0,
       0,     0,   -65,   -65,     0,     0,     0,     0,     0,     0,
     -69,   -69,   268,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     356,   -79,   -79,   -79,   -79,   -79,   -79,   -79,     0,     0,
       0,     0,     0,     0,   -80,   -80,     0,     0,     0,     0,
       0,     0,   -79,   -79,   268,   269,   -75,   -75,   -75,   -75,
     274,   275,   268,   269,   -74,   -74,   -74,   -74,   274,   275,
       0,     0,     0,     0,     0,     0,   -75,   -75,     0,     0,
       0,     0,     0,     0,   -74,   -74,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,     0,     0,     0,     0,     0,     0,   -84,   -84,
       0,     0,     0,     0,     0,     0,   -83,   -83,   268,   269,
     270,   271,   272,   273,   274,   275,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,     0,     0,     0,     0,     0,     0,
     -52,   -52,     0,     0,     0,     0,     0,     0,   -87,   -87,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,     0,
       0,     0,  -103,  -103,     0,     0,     0,     0,     0,     0,
    -102,  -102,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,     0,     0,
       0,     0,     0,     0,   -93,   -93,     0,     0,     0,     0,
       0,   424,   -99,   221,   222,   223,   224,   225,   226,   227,
     228,   221,   222,   223,   224,   225,   226,   227,   228,     0,
       0,     0,     0,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,   149,   303,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   221,   222,   223,   224,   225,   226,   227,   228,
       0,     0,     0,     0,     0,     0,   -78,     0,     0,     0,
       0,     0,     0,     0,   397,   221,   222,   223,   224,   225,
     226,   227,   228,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,     0,     0,     0,     0,     0,     0,   418,     0,     0,
       0,     0,     0,     0,     0,  -110,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,     0,     0,     0,     0,     0,     0,  -111,     0,
       0,     0,     0,     0,     0,     0,  -109,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,     0,     0,     0,     0,     0,     0,  -112,
       0,     0,     0,     0,     0,     0,     0,   -85,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,     0,     0,     0,     0,     0,     0,
     -86,     0,     0,     0,     0,     0,     0,     0,   -92,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,     0,     0,     0,     0,     0,
       0,  -100,     0,     0,     0,     0,     0,     0,     0,  -101,
     303,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,     0,     0,     0,     0,
       0,     0,   -81,     0,     0,     0,     0,     0,     0,     0,
     -82,   221,   222,   223,   224,   225,   226,   227,   228,   221,
     222,   223,   224,   -57,   226,   227,   228,     0,     0,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,   -57,   221,   222,   223,   -61,   -61,   226,   227,   228,
     221,   222,   223,   -65,   -65,   -65,   227,   228,     0,     0,
       0,     0,     0,     0,   -61,     0,     0,     0,     0,     0,
       0,     0,   -65,   221,   222,   -69,   -69,   -69,   -69,   227,
     228,   221,   -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,
       0,     0,     0,     0,     0,   -69,     0,     0,     0,     0,
       0,     0,     0,   -80,   303,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   221,   222,   -75,   -75,   -75,   -75,   227,   228,
       0,     0,     0,     0,     0,     0,   -79,     0,     0,     0,
       0,     0,     0,     0,   -75,   221,   222,   -74,   -74,   -74,
     -74,   227,   228,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,     0,     0,     0,     0,     0,     0,   -74,     0,     0,
       0,     0,     0,     0,     0,   -84,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   221,   222,   223,   224,   225,   226,
     227,   228,     0,     0,     0,     0,     0,     0,   -83,     0,
       0,     0,     0,     0,     0,     0,   -52,   221,   222,   223,
     224,   225,   226,   227,   228,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,     0,     0,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,     0,   -87,   221,   222,
     223,   224,   225,   226,   227,   228,   221,   222,   223,   224,
     225,   226,   227,   228,     0,     0,     0,     0,     0,     0,
     477,     0,     0,     0,     0,     0,     0,     0,   479,   221,
     222,   223,   224,   225,   226,   227,   228,   221,   222,   223,
     224,   225,   226,   227,   228,     0,     0,     0,     0,     0,
       0,   484,     0,     0,     0,     0,     0,     0,     0,   489,
     221,   222,   223,   224,   225,   226,   227,   228,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,     0,     0,     0,     0,
       0,     0,   491,     0,     0,     0,     0,     0,     0,     0,
    -103,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,     0,     0,
       0,     0,     0,  -102,     0,     0,     0,     0,     0,     0,
       0,   -93,   221,   222,   223,   224,   225,   226,   227,   228,
     221,   222,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,     0,   562,     0,     0,     0,     0,     0,
       0,     0,   564,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,     0,
       0,     0,     0,  -104,  -104,     0,     0,     0,     0,     0,
       0,   -99,   310,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,    77,   -81,   -81,   -81,   -81,   -81,   -81,   -81,     0,
       0,     0,     0,   -85,     0,     0,     0,     0,     0,     0,
       0,   -81,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
      48,    49,    50,    51,   -57,    53,    54,    55,     0,     0,
       0,     0,   -82,     0,     0,     0,     0,     0,     0,     0,
     -57,    48,    49,    50,   -61,   -61,    53,    54,    55,    48,
      49,    50,   -65,   -65,   -65,    54,    55,     0,     0,     0,
       0,   -61,     0,     0,     0,     0,     0,     0,     0,   -65,
      48,    49,   -69,   -69,   -69,   -69,    54,    55,    48,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,     0,
     -69,     0,     0,     0,     0,     0,     0,     0,   -80,    77,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,    48,    49,   -75,
     -75,   -75,   -75,    54,    55,     0,     0,     0,     0,   -79,
       0,     0,     0,     0,     0,     0,     0,   -75,    48,    49,
     -74,   -74,   -74,   -74,    54,    55,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,     0,     0,     0,     0,   -74,     0,
       0,     0,     0,     0,     0,     0,   -84,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,    48,    49,    50,    51,    52,
      53,    54,    55,     0,     0,     0,     0,   -83,     0,     0,
       0,     0,     0,     0,     0,   -52,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,     0,     0,     0,     0,  -110,     0,     0,     0,
       0,     0,     0,     0,  -111,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,     0,     0,     0,     0,  -109,     0,     0,     0,     0,
       0,     0,     0,  -112,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
       0,     0,     0,     0,   -86,     0,     0,     0,     0,     0,
       0,     0,   -92,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,     0,
       0,     0,     0,  -100,     0,     0,     0,     0,     0,     0,
       0,  -101,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
      48,    49,    50,    51,    52,    53,    54,    55,     0,     0,
       0,     0,   -87,     0,     0,     0,     0,     0,     0,     0,
     432,    48,    49,    50,    51,    52,    53,    54,    55,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,     0,     0,     0,
       0,   467,     0,     0,     0,     0,     0,     0,     0,  -103,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,     0,     0,     0,     0,
    -102,     0,     0,     0,     0,     0,     0,     0,   -93,    48,
      49,    50,    51,    52,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   551
};

static const yytype_int16 yycheck[] =
{
       0,   236,     0,   345,     1,   306,   151,     6,    30,   310,
       1,     1,     3,     4,     5,     6,    30,    17,    18,    10,
       6,    21,     6,    21,    21,    22,    17,    18,    19,    20,
      29,    21,    22,   178,    31,     0,     6,    23,     6,    30,
      31,    31,    30,    29,    30,    29,    30,   282,     6,    30,
       6,     0,   394,     6,     0,    23,    21,    57,   359,    29,
      60,    61,     9,    10,    11,    12,    13,    14,    15,    16,
      23,    29,    30,    29,    30,    21,    29,    30,     6,     0,
      80,    13,    29,    30,    82,    29,     0,     1,    35,     3,
       4,     5,     6,     7,     8,    23,    10,     6,     6,    31,
      21,    29,    29,    17,    18,    19,    20,    21,    22,    13,
      24,    25,    26,    27,    23,     6,    30,    13,     0,    33,
      29,    29,     9,   424,     1,    29,     3,     4,     5,     6,
      13,    31,    23,    10,    31,    31,    32,    12,    13,    21,
      17,    18,    19,    20,    12,    13,    14,     0,    31,   149,
     150,   151,    31,    30,    31,   155,    31,    32,   459,    31,
     158,    31,   160,    31,    32,    13,   166,    29,    21,    29,
       1,    34,     3,     4,     5,     6,   176,   177,   178,    10,
      31,    29,    12,    13,   184,     0,    17,    18,    19,    20,
      29,    30,   192,   535,    12,    13,    14,   342,    29,    30,
       6,    31,    32,   149,   150,     1,    21,     3,     4,     5,
       6,    29,    31,   213,    10,    12,    13,    14,    12,    13,
     166,    17,    18,    19,    20,    12,    13,    14,   149,   150,
     176,   177,    29,    33,    30,   235,   157,    31,   184,    11,
      12,    13,    14,    29,    31,   166,   391,    12,    13,   249,
      12,    13,     0,    29,     0,   176,   177,    31,    32,    31,
      32,    29,   183,   184,    31,    32,    31,   149,   150,    31,
      32,   506,    29,    21,     1,    21,     3,     4,     5,     6,
      29,   281,    29,    10,   166,    11,    12,    13,    14,    13,
      17,    18,    19,    20,   176,   177,   149,   150,    11,    12,
      13,    14,   184,    30,     1,    31,   306,    31,    32,     6,
     310,    12,    13,   166,    31,    32,   316,    29,    31,    32,
      12,    13,    14,   176,   177,    11,    12,    13,    14,    31,
      31,   184,    12,    13,   149,   150,   481,    31,   338,    31,
      32,   341,   342,    12,    13,    31,    32,    31,   493,    29,
      31,   166,    10,    11,    12,    13,    14,    15,    16,   359,
      29,   176,   177,    11,    12,    13,    14,   367,    30,   184,
      30,    12,    13,    31,     9,    10,    11,    12,    13,    14,
      15,    16,    29,    31,    32,    31,    32,   532,    29,   389,
     390,   391,    31,    32,   539,    30,    31,    32,   543,    30,
      35,   149,   150,   149,   150,    30,     9,    10,    11,    12,
      13,    14,    15,    16,    11,    12,    13,    14,   166,    29,
     166,   566,    21,    22,   424,    30,    29,    30,   176,   177,
     176,   177,    35,    29,    31,    32,   184,     1,   184,   584,
       1,    30,     6,     0,     1,     6,     3,     4,     5,     6,
       7,     8,    30,    10,    30,    11,    12,    13,    14,   459,
      17,    18,    19,    20,    21,    22,    29,    24,    25,    26,
      27,     9,    10,    30,    29,    31,    33,    15,    16,   479,
     480,   481,    31,     9,    10,    11,    12,    13,    14,    15,
      16,   491,   492,   493,     0,     1,    31,     3,     4,     5,
       6,     7,     8,    29,    10,   505,    31,    32,    31,    35,
       9,    17,    18,    19,    20,    21,    22,     1,    24,    25,
      26,    27,     6,   523,    30,    29,    30,    33,    31,   529,
     530,     6,   532,   479,   480,    11,    12,    13,    14,   539,
       6,   541,   542,   543,     9,   491,   492,     9,    10,    11,
      12,    13,    14,    15,    16,    31,    32,   503,   479,   480,
      11,    12,    13,    14,   564,   565,   566,    29,    29,   569,
     491,   492,    31,    35,   574,    31,    32,   523,    31,    32,
      31,    32,   582,   583,   584,    31,    32,    31,   588,    31,
     536,    31,   538,     9,    10,   541,   542,   479,   480,    15,
      16,    31,   523,    31,    11,    12,    13,    14,    31,   491,
     492,    10,    11,    12,    13,    14,    15,    16,   564,   565,
     541,   542,   568,   569,    31,    32,   479,   480,   574,    12,
      13,    14,    31,    32,    29,    31,   582,   583,   491,   492,
      34,   523,   588,   564,   565,    31,    29,    31,   569,    11,
      12,    13,    14,   574,    11,    12,    13,    14,    31,   541,
     542,   582,   583,    31,   479,   480,    31,   588,    29,    31,
     523,    12,    13,    14,    31,    32,   491,   492,    11,    12,
      13,    14,   564,   565,    34,    31,    29,   569,   541,   542,
      31,    32,   574,    11,    12,    13,    14,    29,    31,    32,
     582,   583,    11,    12,    13,    14,   588,    29,   523,    29,
      31,   564,   565,    31,    29,    29,   569,    11,    12,    13,
      14,   574,    31,    12,    13,    14,   541,   542,    29,   582,
     583,   479,   480,   479,   480,   588,    29,    31,    30,    30,
      30,    29,    31,   491,   492,   491,   492,    30,    29,   564,
     565,    29,    29,     1,   569,     3,     4,     5,     6,   574,
      31,    31,    10,    31,    31,    29,    31,   582,   583,    17,
      18,    19,    20,   588,    34,   523,    31,   523,    29,    29,
       0,     1,    30,     3,     4,     5,     6,     7,     8,    29,
      10,    29,    29,   541,   542,   541,   542,    17,    18,    19,
      20,    21,    22,    31,    24,    25,    26,    27,    21,   154,
      30,   160,   112,    33,    18,    -1,   564,   565,   564,   565,
     158,   569,    -1,   569,     9,    10,   574,    -1,   574,    -1,
      15,    16,    -1,    -1,   582,   583,   582,   583,    -1,    -1,
     588,    45,   588,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,     0,     1,    31,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    11,
      12,    13,    14,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    -1,    -1,    30,    -1,    31,
      33,   115,    12,    13,    14,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    11,    12,    13,
      14,    31,    17,    18,    19,    20,    21,    22,   142,    24,
      25,    26,    27,    -1,    -1,    30,    -1,    31,    33,    -1,
      -1,   155,    11,    12,    13,    14,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    31,    -1,   178,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    -1,   192,    30,
      -1,    -1,    33,    -1,    -1,    -1,     1,   201,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    -1,    -1,   213,
     214,    -1,    17,    18,    19,    20,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,    30,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    11,    12,    13,    14,   249,    17,    18,    19,    20,
      21,    22,    -1,    24,   258,    26,    27,    -1,    -1,    30,
      -1,    31,    33,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,     1,    -1,     3,     4,     5,     6,     9,    10,
      11,    10,    -1,    14,    15,    16,    -1,    -1,    17,    18,
      19,    20,   296,   297,   298,   299,   300,   301,   302,   303,
     304,    30,   306,    -1,    -1,    -1,   310,    11,    12,    13,
      14,    -1,   316,     1,   318,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    -1,    -1,    29,    -1,    -1,    -1,    17,
      18,    19,    20,   337,   338,    -1,    -1,   341,    18,    -1,
      -1,    -1,    30,    -1,    -1,   349,   350,   351,   352,   353,
     354,   355,   356,   357,    -1,   359,    -1,    -1,    -1,    -1,
      -1,    41,    -1,   367,    -1,   369,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    -1,    -1,
      60,     9,    10,    11,   388,   389,   390,    15,    16,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
     424,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,   459,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,   155,    10,    11,    12,    13,
      14,    15,    16,     0,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    29,    -1,    -1,   178,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,   192,    30,    -1,    -1,    33,    -1,    -1,    -1,
      -1,   201,    -1,    -1,   528,   529,   530,    -1,    -1,    -1,
       9,    10,    11,   213,   214,   539,    15,    16,    -1,   543,
      -1,   221,   222,   223,   224,   225,   226,   227,   228,    11,
      12,    13,    14,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    29,    -1,   249,
      17,    18,    19,    20,    -1,     9,    10,    11,   258,    -1,
     584,    15,    16,    30,    11,    12,    13,    14,   268,   269,
     270,   271,   272,   273,   274,   275,     1,    -1,     3,     4,
       5,     6,    29,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,   296,   297,   298,   299,
     300,   301,   302,   303,   304,    30,   306,    -1,    -1,    -1,
     310,    11,    12,    13,    14,    -1,   316,     1,   318,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    -1,    29,
      -1,    -1,    -1,    17,    18,    19,    20,    -1,   338,    -1,
      -1,   341,    18,    -1,    -1,    -1,    30,    -1,    -1,   349,
     350,   351,   352,   353,   354,   355,   356,   357,    -1,   359,
      -1,    -1,    11,    12,    13,    14,    -1,   367,    -1,   369,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      29,    57,    -1,    -1,    60,    11,    12,    13,    14,   389,
     390,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    29,    80,    -1,    -1,    -1,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,   424,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    -1,     0,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,   459,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,   155,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    11,    12,    13,    14,    17,    18,    19,    20,
      21,    22,   178,    24,    25,    26,    27,    -1,    -1,    30,
      29,    -1,    33,    34,    -1,     1,   192,     3,     4,     5,
       6,     9,    10,    11,    10,   201,    14,    15,    16,   529,
     530,    17,    18,    19,    20,    -1,    -1,   213,   214,   539,
      -1,    -1,    -1,   543,    30,   221,   222,   223,   224,   225,
     226,   227,   228,    11,    12,    13,    14,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    29,    -1,   249,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,   258,    -1,   584,    -1,    -1,    30,    11,    12,
      13,    14,   268,   269,   270,   271,   272,   273,   274,   275,
       1,    -1,     3,     4,     5,     6,    29,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
     296,   297,   298,   299,   300,   301,   302,   303,   304,    30,
     306,    -1,    -1,    -1,   310,    11,    12,    13,    14,    -1,
     316,     1,   318,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    -1,    -1,    29,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,   338,    -1,    -1,   341,    18,    -1,    -1,    -1,
      30,    -1,    -1,   349,   350,   351,   352,   353,   354,   355,
     356,   357,    -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   367,    -1,   369,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    -1,    -1,    60,    -1,
       9,    10,    11,   389,   390,    14,    15,    16,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,   424,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,   459,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,   155,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,   178,    24,    25,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,     1,
     192,     3,     4,     5,     6,    -1,    -1,    -1,    10,   201,
      -1,    -1,    -1,   529,   530,    17,    18,    19,    20,    -1,
      -1,   213,   214,   539,    -1,    -1,    -1,   543,    30,   221,
     222,   223,   224,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,   249,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,   258,    -1,   584,    -1,
      -1,    30,    -1,    -1,    -1,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,   296,   297,   298,   299,   300,   301,
     302,   303,   304,    30,   306,    -1,    -1,    -1,   310,    -1,
      -1,    -1,    -1,    -1,   316,     1,   318,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,   338,    -1,    -1,   341,
      18,    -1,    -1,    -1,    30,    -1,    -1,   349,   350,   351,
     352,   353,   354,   355,   356,   357,    -1,   359,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   367,    -1,   369,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      -1,    -1,    60,    -1,    -1,    -1,    -1,   389,   390,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,   424,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,   459,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,   155,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
     178,    24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,     1,   192,     3,     4,     5,     6,    -1,
      -1,    -1,    10,   201,    -1,    -1,    -1,   529,   530,    17,
      18,    19,    20,    -1,    -1,   213,   214,   539,    -1,    -1,
      -1,   543,    30,   221,   222,   223,   224,   225,   226,   227,
     228,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,   249,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
     258,    -1,   584,    -1,    -1,    30,    -1,    -1,    -1,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,   296,   297,
     298,   299,   300,   301,   302,   303,   304,    30,   306,    -1,
      -1,    -1,   310,    -1,    -1,    -1,    -1,    -1,   316,     1,
     318,     3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
     338,    -1,    -1,   341,    18,    -1,    -1,    -1,    30,    -1,
      -1,   349,   350,   351,   352,   353,   354,   355,   356,   357,
      -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,
      -1,   369,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    -1,    -1,    60,    -1,    -1,    -1,
      -1,   389,   390,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,   424,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,   459,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    -1,
      -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,   178,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    -1,   192,    30,
      -1,    -1,    33,     9,    10,    11,    12,   201,    14,    15,
      16,   529,   530,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     214,   539,    -1,    -1,    -1,   543,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,   249,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,   258,    -1,   584,    -1,    -1,    30,
      -1,    -1,    -1,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,   296,   297,   298,   299,   300,   301,   302,   303,
     304,    30,   306,    -1,    -1,    -1,   310,    -1,    -1,    -1,
      -1,    -1,   316,     1,   318,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,   338,    -1,    -1,   341,    18,    -1,
      -1,    -1,    30,    -1,    -1,   349,   350,   351,   352,   353,
     354,   355,   356,   357,    -1,   359,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   367,    -1,   369,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    -1,    -1,
      60,    -1,    -1,    -1,    -1,   389,   390,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
     424,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    -1,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,   459,    17,    18,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,   178,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,   192,    30,    -1,    -1,    33,     9,    10,    11,
      12,   201,    14,    15,    16,   529,   530,    -1,    -1,    -1,
      -1,    -1,    -1,   213,   214,   539,    -1,    -1,    -1,   543,
      -1,   221,   222,   223,   224,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,   249,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,   258,    -1,
     584,    -1,    -1,    30,    -1,    -1,    -1,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,     1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,   296,   297,   298,   299,
     300,   301,   302,   303,   304,    30,   306,    -1,    -1,    -1,
     310,    -1,    -1,    -1,    -1,    -1,   316,    -1,   318,    -1,
       3,     4,     5,     6,    -1,    -1,    18,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,   338,    -1,
      -1,   341,    -1,    -1,    -1,    -1,    -1,    30,    -1,   349,
     350,   351,   352,   353,   354,   355,   356,   357,    50,   359,
      -1,    -1,    54,    55,    -1,    57,    -1,   367,    60,   369,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    73,    -1,    75,    76,    -1,    -1,    -1,    80,   389,
     390,    30,    31,     0,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    30,   424,    18,    33,     0,     1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    -1,    49,    30,    -1,   459,
      33,    -1,    -1,   155,    57,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,    74,    10,    -1,    -1,    -1,   178,    80,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
     192,    -1,    30,    -1,    -1,    33,    34,    -1,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    -1,
      -1,   213,    -1,    -1,    17,    18,    19,    20,    -1,   529,
     530,   223,   224,   225,   226,   227,   228,    30,    -1,   539,
      -1,    -1,     1,   543,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,   249,    17,    18,
      19,    20,   155,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    -1,    -1,    -1,   270,   271,
     272,   273,   274,   275,   584,   178,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,   192,
      17,    18,    19,    20,   296,   297,   298,   299,    -1,   301,
     302,    -1,   304,    30,   306,    -1,    -1,    -1,   310,    -1,
     213,    -1,    -1,    -1,   316,    -1,    -1,    -1,    -1,   222,
     223,   224,   225,   226,   227,   228,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    -1,   338,    -1,    -1,   341,
      -1,    17,    18,    19,    20,    -1,   249,   349,   350,   351,
     352,    -1,   354,   355,    30,   357,    -1,   359,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   367,   269,   270,   271,   272,
     273,   274,   275,    -1,    -1,    -1,    -1,    -1,    18,     9,
      10,    11,    12,    13,    14,    15,    16,   389,   390,    -1,
      -1,    -1,    -1,   296,   297,   298,   299,   300,   301,   302,
      -1,   304,    -1,   306,    -1,    -1,    -1,   310,    -1,     3,
       4,     5,     6,   316,    -1,    -1,    10,    57,    -1,    -1,
      60,    -1,   424,    17,    18,    19,    20,     9,    10,    11,
      12,    13,    14,    15,    16,   338,    30,    -1,   341,    -1,
      80,    -1,    18,    -1,    -1,    -1,   349,   350,   351,   352,
     353,   354,   355,    -1,   357,    -1,   359,   459,     3,     4,
       5,     6,    -1,    -1,   367,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,    53,    -1,    -1,
      -1,    57,    -1,    -1,    60,    30,   389,   390,     9,    10,
      11,    12,    13,    14,    15,    16,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,     1,    29,     3,
       4,     5,     6,     7,     8,   155,    10,    -1,    -1,    -1,
      -1,   424,    -1,    17,    18,    19,    20,   529,   530,    -1,
      24,    25,    26,    27,    -1,    -1,    30,   539,   178,    33,
      -1,   543,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,   192,    -1,    -1,    -1,   459,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,   213,    33,    34,    -1,    -1,    -1,   155,
      -1,    -1,   584,   223,   224,   225,   226,   227,   228,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,   178,    -1,    -1,    17,    18,    19,    20,   249,
      -1,    -1,    24,    25,    26,    27,   192,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,   529,   530,    -1,    -1,
     270,   271,   272,   273,   274,   275,   539,   213,    -1,    -1,
     543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   225,
     226,    18,    -1,    -1,    -1,    -1,   296,   297,   298,   299,
      -1,   301,   302,    -1,   304,    -1,   306,    -1,    -1,    -1,
     310,    -1,    -1,   249,    -1,    -1,   316,    -1,    -1,    -1,
      -1,   584,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    60,    -1,   271,   272,   273,   338,    -1,
      -1,   341,    -1,    -1,    71,    -1,    -1,    -1,    -1,   349,
     350,   351,   352,    80,   354,   355,    -1,   357,    -1,   359,
     296,   297,   298,    -1,    -1,    -1,    -1,   367,   304,    -1,
     306,    -1,    -1,    -1,   310,    -1,    -1,    -1,    -1,     1,
     316,     3,     4,     5,     6,    -1,    -1,    -1,    10,   389,
     390,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
      -1,    -1,   338,    -1,    -1,   341,    -1,    -1,    30,    -1,
      -1,    -1,    -1,   349,   350,   351,    -1,    -1,    18,    -1,
      -1,   357,    -1,   359,   424,    18,    -1,    -1,   155,    -1,
      -1,   367,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,   178,    52,   389,   390,    -1,    -1,    57,    -1,   459,
      60,    30,    31,    32,    57,   192,    35,    60,    -1,    -1,
      70,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      80,    -1,    10,    -1,    -1,    78,   213,    80,   424,    17,
      18,    19,    20,     3,     4,     5,     6,   224,   225,    -1,
      10,    -1,    30,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      30,    -1,   249,   459,    -1,    -1,    -1,    -1,    -1,   529,
     530,     1,    29,     3,     4,     5,     6,     7,     8,   539,
      10,    -1,    -1,   543,   271,   272,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,   155,    26,    27,    -1,    -1,
      30,    -1,   155,    33,    34,    -1,    -1,    -1,    -1,   296,
     297,    -1,    -1,    -1,    -1,    -1,    -1,   304,   178,   306,
      -1,    -1,    -1,   310,   584,   178,    -1,    -1,    -1,   316,
      -1,    -1,   192,   529,   530,     9,    10,    11,    12,   192,
      14,    15,    16,   539,    -1,    -1,    -1,   543,    -1,    -1,
      -1,   338,    -1,   213,   341,    -1,    -1,    -1,    -1,    -1,
     213,    -1,   349,   350,    -1,   225,    -1,    -1,    -1,    -1,
     357,    -1,   359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     367,     1,    -1,     3,     4,     5,     6,    -1,   584,   249,
      10,    -1,    -1,    -1,    -1,    -1,   249,    17,    18,    19,
      20,    -1,   389,   390,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,   272,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,   296,   424,    -1,    24,
      25,    26,    27,    -1,   304,    30,   306,    -1,    33,    -1,
     310,   304,    -1,   306,    -1,    -1,   316,   310,    -1,     3,
       4,     5,     6,   316,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,   459,    17,    18,    19,    20,    -1,   338,    -1,
      -1,   341,    -1,    -1,    -1,   338,    30,    -1,   341,   349,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,   359,
      -1,    -1,    -1,    -1,   357,    -1,   359,   367,    -1,    -1,
      -1,    -1,    -1,    -1,   367,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,   389,
     390,    17,    18,    19,    20,    -1,   389,   390,    24,    25,
      26,    27,   529,   530,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,   539,    -1,    -1,    -1,   543,    -1,    -1,    -1,
      -1,    -1,     0,     1,   424,     3,     4,     5,     6,     7,
       8,   424,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    -1,   584,     1,   459,
       3,     4,     5,     6,     7,     8,   459,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,   529,
     530,    -1,    -1,    -1,    -1,    -1,   529,   530,    -1,   539,
      -1,    -1,    -1,   543,    -1,    -1,   539,    -1,     0,     1,
     543,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    -1,     1,   584,     3,     4,     5,     6,     7,
       8,   584,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     0,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    -1,    -1,    30,    -1,     1,    33,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,     0,     1,    -1,     3,     4,     5,     6,
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
       0,     1,    33,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
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
      27,    -1,    -1,    30,    -1,     1,    33,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,     0,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
       0,     1,    33,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
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
      27,    -1,    -1,    30,    -1,     1,    33,     3,     4,     5,
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
      34,     0,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,     1,    33,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,     0,     1,    -1,
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
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
       1,    33,     3,     4,     5,     6,     7,     8,    -1,    10,
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
      17,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    30,    -1,     1,    33,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    30,    -1,     1,    33,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    30,    -1,     1,    33,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,    -1,     1,    33,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,     1,
      33,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
      -1,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
       1,    33,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,     1,    33,     3,     4,     5,     6,    -1,    -1,    -1,
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
      20,     3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,
      30,    -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    -1,    30,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    30,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
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
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,
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
      29,    -1,    -1,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,    -1,
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
      -1,    30,    31,     9,    10,    11,    12,    13,    14,    15,
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
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,     9,    10,    11,    12,    13,    14,    15,
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
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29
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
      30,    29,    30,    74,    68,     1,    67,    68,     1,    65,
       1,    63,     1,    62,     1,    64,    65,    65,     1,    74,
       1,    59,     1,    59,    59,    60,    29,    29,    31,    31,
      40,    50,    51,    52,    53,    75,     1,    62,     1,    63,
       1,    64,     1,    65,     1,    67,     1,    65,     1,    65,
       1,    68,     1,    61,     1,    59,    71,    72,     1,    45,
      46,    47,    75,    30,    41,    31,    31,    31,    31,    31,
      31,    29,    34,    52,    74,    32,    31,    31,    32,    74,
      43,    29,    29,    29,    29,    29,    25,    53,    25,    53,
      60,    59,    48,    47,    45,    53,    25,    25,    29,    44,
      53,    53,    60,    31,    31,    48,    53,     3,     4,     5,
       6,    20,    30,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    73,    74,    76,    77,     6,     3,     4,
       5,     6,    20,    30,    69,    70,    73,    74,    76,    77,
       6,     9,    10,    11,    12,    13,    14,    15,    16,     7,
       8,    21,    22,    24,    26,    27,    33,    48,    54,    55,
      56,    57,    58,    59,     3,     4,     5,     6,    20,    30,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      73,    74,    76,    77,    21,    22,     6,    29,     9,    10,
      11,    12,    13,    14,    15,    16,     6,     7,     8,    24,
      26,    27,    33,    48,    54,    55,    56,    57,    58,    59,
      41,     1,     1,    59,     1,    59,    13,    12,    14,    11,
      10,    15,    16,     9,    35,    68,    30,     1,    59,    68,
      30,     3,     4,     5,     6,    20,    30,    68,    69,    70,
      73,    74,    76,    77,     1,    67,    68,     1,    65,     1,
      63,     1,    62,     1,    64,    65,    65,    30,    30,    23,
      23,    30,    30,     1,    59,    49,    29,     1,    59,    13,
      12,    14,    11,    10,    15,    16,     9,    35,    68,    30,
      23,    23,     3,     4,     5,     6,    20,    30,    68,    69,
      70,    73,    74,    76,    77,     1,    67,    68,     1,    65,
       1,    63,     1,    62,     1,    64,    65,    65,    30,    30,
      30,    30,     1,    59,    49,    29,    29,    31,    31,     1,
      62,     1,    63,     1,    64,     1,    65,     1,    67,     1,
      65,     1,    65,     1,    68,     1,    61,    72,    31,    31,
      72,     1,    59,    68,    30,     1,    74,     1,    59,     1,
      59,    60,    29,    29,    50,    31,    31,     1,    62,     1,
      63,     1,    64,     1,    65,     1,    67,     1,    65,     1,
      65,     1,    68,     1,    61,    72,     1,    59,    68,    30,
       1,    74,     1,    59,     1,    59,    60,    29,    29,    50,
      31,    31,    31,    31,    72,    31,    31,    31,    31,    31,
      31,    29,    34,    31,    31,    31,    72,    31,    31,    31,
      31,    31,    31,    29,    34,    31,    29,    29,    29,    29,
       7,     8,    24,    25,    26,    27,    33,    48,    53,    54,
      55,    56,    57,    58,    59,    25,    53,    60,    31,    29,
      29,    29,    29,    25,    53,    25,    53,    60,    30,    30,
      30,    53,    30,     1,    59,    49,    25,    29,    25,    29,
      53,    25,    25,    29,     1,    74,     1,    59,     1,    59,
      60,    29,    29,    50,    53,    53,    60,    53,    53,    60,
      31,    31,    31,    31,    31,    31,    29,    34,    31,    31,
      29,    29,    29,    29,    25,    53,    25,    53,    60,    53,
      53,    53,    25,    25,    29,    53,    53,    60,    31,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    39,    41,
      40,    40,    43,    44,    42,    42,    45,    45,    46,    46,
      46,    47,    49,    48,    50,    50,    51,    51,    52,    52,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      55,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    62,
      62,    62,    62,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    66,    66,
      66,    66,    67,    67,    67,    67,    68,    68,    69,    69,
      69,    69,    70,    70,    71,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    74,    75,    75,    75,    75,    76,
      76,    76,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     0,
       4,     2,     0,     0,     8,     5,     0,     1,     3,     1,
       1,     2,     0,     4,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     5,
       2,     5,     7,     5,     5,     7,     6,     3,     3,     9,
       1,     3,     3,     0,     1,     1,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     1,     2,     1,     1,
       1,     1,     1,     4,     3,     1,     1,     1,     0,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     2,     1,
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
#line 3667 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3673 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3679 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3685 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3691 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3697 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3703 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3709 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3715 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3721 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3727 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3733 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3739 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3745 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3751 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3757 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3763 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3769 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3775 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3781 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_1: /* @1  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3787 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3793 "src/bison/grammar.c"
        break;

    case YYSYMBOL_43_2: /* @2  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3799 "src/bison/grammar.c"
        break;

    case YYSYMBOL_45_param_list_opt: /* param_list.opt  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3805 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3811 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3817 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3823 "src/bison/grammar.c"
        break;

    case YYSYMBOL_50_block_item_list_opt: /* block_item_list.opt  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3829 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3835 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3841 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3847 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3853 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3859 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3865 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3871 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3877 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3883 "src/bison/grammar.c"
        break;

    case YYSYMBOL_60_expression_opt: /* expression.opt  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3889 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3895 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3901 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3907 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3913 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3919 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3925 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3931 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3937 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3943 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3949 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3955 "src/bison/grammar.c"
        break;

    case YYSYMBOL_72_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 127 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3961 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3967 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 125 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3973 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 124 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3979 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3985 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 126 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3991 "src/bison/grammar.c"
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
#line 131 "src/bison/grammar.y"
             { show_error((yyloc), "ISO C-IPL forbids an empty translation unit\n"); }
#line 4300 "src/bison/grammar.c"
    break;

  case 4: /* external_declaration_list: external_declaration_list external_declaration  */
#line 134 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4306 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration  */
#line 135 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4312 "src/bison/grammar.c"
    break;

  case 8: /* external_declaration: statement  */
#line 140 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4322 "src/bison/grammar.c"
    break;

  case 9: /* @1: %empty  */
#line 147 "src/bison/grammar.y"
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
#line 4347 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type id @1 ';'  */
#line 166 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 4355 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 169 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4365 "src/bison/grammar.c"
    break;

  case 12: /* @2: %empty  */
#line 176 "src/bison/grammar.y"
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
#line 4406 "src/bison/grammar.c"
    break;

  case 13: /* $@3: %empty  */
#line 211 "src/bison/grammar.y"
                     {
        is_fn_blck = true;
    }
#line 4414 "src/bison/grammar.c"
    break;

  case 14: /* func_declaration: type id '(' @2 param_list.opt $@3 ')' compound_stmt  */
#line 213 "src/bison/grammar.y"
                        {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4424 "src/bison/grammar.c"
    break;

  case 15: /* func_declaration: type '(' param_list.opt ')' compound_stmt  */
#line 218 "src/bison/grammar.y"
                                                {
        show_error_range((yylsp[-3]), "expected identifier before " WHT "')'" RESET "\n");
        free((yyvsp[-4].pchar));
        LIST_FREE((yyvsp[-2].list), { ast_free(__IT__->data); });
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4436 "src/bison/grammar.c"
    break;

  case 16: /* param_list.opt: %empty  */
#line 227 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4442 "src/bison/grammar.c"
    break;

  case 18: /* params_list: params_list ',' param_decl  */
#line 231 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4448 "src/bison/grammar.c"
    break;

  case 19: /* params_list: param_decl  */
#line 232 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4454 "src/bison/grammar.c"
    break;

  case 20: /* params_list: error  */
#line 233 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4463 "src/bison/grammar.c"
    break;

  case 21: /* param_decl: type id  */
#line 239 "src/bison/grammar.y"
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
#line 4480 "src/bison/grammar.c"
    break;

  case 22: /* $@4: %empty  */
#line 253 "src/bison/grammar.y"
                   {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        if (!is_fn_blck) context_push_scope(current_context);
        is_fn_blck = false;
    }
#line 4490 "src/bison/grammar.c"
    break;

  case 23: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 257 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 4502 "src/bison/grammar.c"
    break;

  case 24: /* block_item_list.opt: block_item_list  */
#line 266 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4508 "src/bison/grammar.c"
    break;

  case 25: /* block_item_list.opt: %empty  */
#line 267 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4514 "src/bison/grammar.c"
    break;

  case 26: /* block_item_list: block_item_list block_item  */
#line 270 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4520 "src/bison/grammar.c"
    break;

  case 27: /* block_item_list: block_item  */
#line 271 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4526 "src/bison/grammar.c"
    break;

  case 36: /* io_stmt: READ '(' id ')' ';'  */
#line 286 "src/bison/grammar.y"
                             {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(func), ast_symref_init(param));
        symbol_free((yyvsp[-4].sym));
        symbol_free((yyvsp[-2].sym));
    }
#line 4538 "src/bison/grammar.c"
    break;

  case 37: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 293 "src/bison/grammar.y"
                                   {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(func), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 4548 "src/bison/grammar.c"
    break;

  case 38: /* io_stmt: WRITE '(' error ')' ';'  */
#line 298 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        symbol_free((yyvsp[-4].sym));
        (yyval.ast) = NULL;
    }
#line 4558 "src/bison/grammar.c"
    break;

  case 39: /* io_stmt: READ '(' error ')' ';'  */
#line 303 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        symbol_free((yyvsp[-4].sym));
        (yyval.ast) = NULL;
    }
#line 4568 "src/bison/grammar.c"
    break;

  case 40: /* expr_stmt: expression ';'  */
#line 310 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 4574 "src/bison/grammar.c"
    break;

  case 41: /* cond_stmt: IF '(' expression ')' statement  */
#line 313 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 4582 "src/bison/grammar.c"
    break;

  case 42: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 316 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4590 "src/bison/grammar.c"
    break;

  case 43: /* cond_stmt: IF '(' expression ')' ELSE  */
#line 319 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4600 "src/bison/grammar.c"
    break;

  case 44: /* cond_stmt: IF '(' error ')' statement  */
#line 324 "src/bison/grammar.y"
                                            {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4610 "src/bison/grammar.c"
    break;

  case 45: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 329 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4621 "src/bison/grammar.c"
    break;

  case 46: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 335 "src/bison/grammar.y"
                                      {
        show_error((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4631 "src/bison/grammar.c"
    break;

  case 47: /* jmp_stmt: RETURN expression ';'  */
#line 342 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 4637 "src/bison/grammar.c"
    break;

  case 48: /* jmp_stmt: RETURN error ';'  */
#line 343 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 4646 "src/bison/grammar.c"
    break;

  case 49: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 349 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4654 "src/bison/grammar.c"
    break;

  case 51: /* expression: unary_expr '=' logical_or_expr  */
#line 355 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 4660 "src/bison/grammar.c"
    break;

  case 52: /* expression: unary_expr '=' error  */
#line 356 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4670 "src/bison/grammar.c"
    break;

  case 53: /* expression.opt: %empty  */
#line 363 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 4676 "src/bison/grammar.c"
    break;

  case 56: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 368 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4685 "src/bison/grammar.c"
    break;

  case 57: /* logical_or_expr: logical_or_expr OR error  */
#line 372 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4695 "src/bison/grammar.c"
    break;

  case 58: /* logical_or_expr: error OR logical_and_expr  */
#line 377 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4705 "src/bison/grammar.c"
    break;

  case 60: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 385 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4714 "src/bison/grammar.c"
    break;

  case 61: /* logical_and_expr: logical_and_expr AND error  */
#line 389 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4724 "src/bison/grammar.c"
    break;

  case 62: /* logical_and_expr: error AND eq_expr  */
#line 394 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4734 "src/bison/grammar.c"
    break;

  case 64: /* eq_expr: eq_expr EQ rel_expr  */
#line 402 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4743 "src/bison/grammar.c"
    break;

  case 65: /* eq_expr: eq_expr EQ error  */
#line 406 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4753 "src/bison/grammar.c"
    break;

  case 66: /* eq_expr: error EQ rel_expr  */
#line 411 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4763 "src/bison/grammar.c"
    break;

  case 68: /* rel_expr: rel_expr REL list_expr  */
#line 419 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4772 "src/bison/grammar.c"
    break;

  case 69: /* rel_expr: rel_expr REL error  */
#line 423 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4782 "src/bison/grammar.c"
    break;

  case 70: /* rel_expr: error REL list_expr  */
#line 428 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4792 "src/bison/grammar.c"
    break;

  case 72: /* list_expr: add_expr DL_DG list_expr  */
#line 436 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4801 "src/bison/grammar.c"
    break;

  case 73: /* list_expr: add_expr COLON list_expr  */
#line 440 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4810 "src/bison/grammar.c"
    break;

  case 74: /* list_expr: add_expr DL_DG error  */
#line 444 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4820 "src/bison/grammar.c"
    break;

  case 75: /* list_expr: add_expr COLON error  */
#line 449 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4830 "src/bison/grammar.c"
    break;

  case 76: /* list_expr: error DL_DG list_expr  */
#line 454 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4840 "src/bison/grammar.c"
    break;

  case 77: /* list_expr: error COLON list_expr  */
#line 459 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4850 "src/bison/grammar.c"
    break;

  case 79: /* add_expr: add_expr ADD mult_expr  */
#line 467 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4859 "src/bison/grammar.c"
    break;

  case 80: /* add_expr: add_expr ADD error  */
#line 471 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4869 "src/bison/grammar.c"
    break;

  case 81: /* add_expr: error ADD mult_expr  */
#line 476 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4879 "src/bison/grammar.c"
    break;

  case 83: /* mult_expr: mult_expr MULT unary_expr  */
#line 484 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4888 "src/bison/grammar.c"
    break;

  case 84: /* mult_expr: mult_expr MULT error  */
#line 488 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4898 "src/bison/grammar.c"
    break;

  case 85: /* mult_expr: error MULT unary_expr  */
#line 493 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4908 "src/bison/grammar.c"
    break;

  case 87: /* unary_expr: unary_ops unary_expr  */
#line 501 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4917 "src/bison/grammar.c"
    break;

  case 93: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 514 "src/bison/grammar.y"
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
#line 4940 "src/bison/grammar.c"
    break;

  case 94: /* arg_expr_list: arg_expr_list ',' expression  */
#line 534 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4946 "src/bison/grammar.c"
    break;

  case 95: /* arg_expr_list: expression  */
#line 535 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4952 "src/bison/grammar.c"
    break;

  case 96: /* arg_expr_list: error  */
#line 536 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 4961 "src/bison/grammar.c"
    break;

  case 98: /* arg_expr_list.opt: %empty  */
#line 543 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4967 "src/bison/grammar.c"
    break;

  case 99: /* primary_expr: id  */
#line 546 "src/bison/grammar.y"
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
#line 4982 "src/bison/grammar.c"
    break;

  case 102: /* primary_expr: '(' expression ')'  */
#line 558 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 4988 "src/bison/grammar.c"
    break;

  case 103: /* primary_expr: '(' error ')'  */
#line 559 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 4997 "src/bison/grammar.c"
    break;

  case 107: /* type: INT LIST  */
#line 570 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5009 "src/bison/grammar.c"
    break;

  case 108: /* type: FLOAT LIST  */
#line 577 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5021 "src/bison/grammar.c"
    break;

  case 109: /* constant: NUMBER_REAL  */
#line 586 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5027 "src/bison/grammar.c"
    break;

  case 110: /* constant: NUMBER_INT  */
#line 587 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5033 "src/bison/grammar.c"
    break;

  case 111: /* constant: NIL  */
#line 588 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5039 "src/bison/grammar.c"
    break;

  case 112: /* string_literal: STR_LITERAL  */
#line 591 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5048 "src/bison/grammar.c"
    break;


#line 5052 "src/bison/grammar.c"

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

#line 597 "src/bison/grammar.y"


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
