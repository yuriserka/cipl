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

    #define show_error_end(__R__, __FMT__, ...) {                  \
        p_error_ctx_info;                                          \
        Cursor beg = (Cursor){                                     \
            .line=__R__.first_line,                                \
            .col=__R__.last_column                                 \
        };                                                         \
        yyerror(beg.line, beg.col, NULL);                          \
        beg.line = (beg.line - 1) > 0 ? (beg.line - 1) : beg.line; \
        LineInfo *li = list_peek(&lines, beg.line - 1);            \
        li = li ? li : curr_line_info;                             \
        beg.col = strlen(li->text) + 1;                            \
        CIPL_PERROR_CURSOR(                                        \
            __FMT__,                                               \
            li->text,                                              \
            beg,                                                   \
            ##__VA_ARGS__                                          \
        );                                                         \
        yyerrok;                                                   \
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


#line 173 "src/bison/grammar.c"

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
  YYSYMBOL_READ = 22,                      /* READ  */
  YYSYMBOL_WRITE = 23,                     /* WRITE  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_THEN = 28,                      /* THEN  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_prog = 37,                      /* prog  */
  YYSYMBOL_external_declaration_list = 38, /* external_declaration_list  */
  YYSYMBOL_external_declaration = 39,      /* external_declaration  */
  YYSYMBOL_var_declaration = 40,           /* var_declaration  */
  YYSYMBOL_func_declaration = 41,          /* func_declaration  */
  YYSYMBOL_42_1 = 42,                      /* @1  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_44_3 = 44,                      /* $@3  */
  YYSYMBOL_45_4 = 45,                      /* $@4  */
  YYSYMBOL_46_param_list_opt = 46,         /* param_list.opt  */
  YYSYMBOL_params_list = 47,               /* params_list  */
  YYSYMBOL_param_decl = 48,                /* param_decl  */
  YYSYMBOL_compound_stmt = 49,             /* compound_stmt  */
  YYSYMBOL_50_5 = 50,                      /* $@5  */
  YYSYMBOL_51_block_item_list_opt = 51,    /* block_item_list.opt  */
  YYSYMBOL_block_item_list = 52,           /* block_item_list  */
  YYSYMBOL_block_item = 53,                /* block_item  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_io_stmt = 55,                   /* io_stmt  */
  YYSYMBOL_expr_stmt = 56,                 /* expr_stmt  */
  YYSYMBOL_cond_stmt = 57,                 /* cond_stmt  */
  YYSYMBOL_jmp_stmt = 58,                  /* jmp_stmt  */
  YYSYMBOL_iter_stmt = 59,                 /* iter_stmt  */
  YYSYMBOL_expression = 60,                /* expression  */
  YYSYMBOL_61_expression_opt = 61,         /* expression.opt  */
  YYSYMBOL_logical_or_expr = 62,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 63,          /* logical_and_expr  */
  YYSYMBOL_eq_expr = 64,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 65,                  /* rel_expr  */
  YYSYMBOL_list_expr = 66,                 /* list_expr  */
  YYSYMBOL_add_expr = 67,                  /* add_expr  */
  YYSYMBOL_mult_expr = 68,                 /* mult_expr  */
  YYSYMBOL_unary_expr = 69,                /* unary_expr  */
  YYSYMBOL_unary_ops = 70,                 /* unary_ops  */
  YYSYMBOL_postfix_expr = 71,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 72,             /* arg_expr_list  */
  YYSYMBOL_73_arg_expr_list_opt = 73,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 74,              /* primary_expr  */
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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   10897

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  701

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
      31,    32,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
       0,   150,   150,   151,   152,   159,   160,   163,   164,   165,
     172,   194,   199,   205,   213,   248,   213,   253,   257,   253,
     267,   268,   271,   272,   273,   279,   293,   293,   313,   314,
     317,   318,   321,   322,   325,   326,   327,   328,   329,   330,
     333,   344,   348,   352,   357,   362,   368,   374,   382,   383,
     389,   392,   395,   400,   405,   411,   418,   419,   425,   428,
     435,   442,   451,   452,   453,   458,   465,   466,   469,   470,
     474,   479,   486,   487,   491,   496,   503,   504,   508,   513,
     520,   521,   525,   530,   537,   538,   542,   546,   551,   556,
     561,   568,   569,   573,   578,   585,   586,   590,   595,   602,
     603,   609,   610,   611,   612,   615,   616,   636,   637,   638,
     644,   645,   648,   658,   659,   660,   664,   671,   674,   675,
     676,   683,   692,   693,   694,   697
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
  "NUMBER_REAL", "NAME", "MULT", "ADD", "REL", "AND", "OR", "EQ", "COLON",
  "DL_DG", "EXCLAMATION", "PERCENT", "QUESTION", "STR_LITERAL", "INT",
  "FLOAT", "LIST", "READ", "WRITE", "IF", "ELSE", "FOR", "RETURN", "THEN",
  "';'", "'='", "'('", "')'", "','", "'{'", "'}'", "$accept", "prog",
  "external_declaration_list", "external_declaration", "var_declaration",
  "func_declaration", "@1", "$@2", "$@3", "$@4", "param_list.opt",
  "params_list", "param_decl", "compound_stmt", "$@5",
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
      61,    40,    41,    44,   123,   125
};
#endif

#define YYPACT_NINF (-383)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-126)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    5367,  1251,   932,  1570,  2340,  3484,   574,   768,  4053,  4313,
     132,   196,   -12,    35,    54,    76,  3797,  4619,  5399,    93,
    5435,  5467,  5499,  5531,  5563,  5595,  5627,  5659,  5691,  5723,
    5755,    26,    -3,   145,   452,   478,   690,  2049, 10582,  2704,
    4468, 10280, 10294,  3640,   199, 10304,  9147,  4762,  5031,  8205,
    8211,  8229,  5031,  5031,  5787,  8246,   243,   295,     5,  1393,
    8263,  1502, 10318,   123,   136,  3448,    87,  5819,  -383, 10328,
    5855,  5887,  8280,  8297,  8314,  8331,  8348,  8365,  8382,  8399,
    8416, 10342, 10352,    33,   227,  5919,     8,   556, 10592,   155,
   10605, 10615,   469,  1054,  2088,   536,  3435,   149,   841,  1097,
    1154,  1321,  1578,   318,   143,   216,  4021,   228,   244,   249,
    9604,   256, 10366,   298,   301,  5951,  5983, 10376, 10390,  6015,
     268,  6050,  6085,  6120,    15, 10628,   532, 10638,   652, 10651,
    1374, 10661,  1661, 10674, 10684, 10697,  1762, 10707,  1797, 10720,
   10730, 10743,   372,   503,   -20,   159,   291,   343,    13,  6156,
     354,    85,   345,     6,   381,    14,    17,   948,  1533,  3529,
    3898,  6188,  6220,   238,  8433, 10400,  6256,   460,   384,   517,
     569,   435,  6288,    13,  6320,  6352,  6384,  6416,  6448,  6480,
    6512,  6544,  1680,    72,  6576,   108,  3780,   423, 10414,   426,
     598,   473,   687,   676,   496,  6608,  1680,  1680,   274,   274,
    1199,   432,   747,   502,  6640,  6672,   509,   526,  9618,   549,
    6704,   432,  1680,  1680,  1680,  1680,  6736,  6768,  6800,  6832,
    6864,   720,  9630,  9644,  9656,   357,  8450,   104,    90,   330,
     612,   729,  1488,  1984,  9670,  9164,  9682,  9696,   793,  9708,
     538,   587, 10753, 10766, 10776,  1730,  8467,  9147, 10789, 10799,
    1937, 10812,   551,  9181,  8484,  8501,  8518,  8535,  8552,  8501,
    8501,  8569, 10424,   316,   325,   561,   565,   568,   588,  8586,
    5399,  6896,  6931,  6966,  7001,  7036,  7071,   596,  3640,  1293,
    3743,  4123,   176,  8603,   218,   365,   637,   161,   275,   820,
     859,  4200,  9198,  4531,  9226,   490,  9240,   761,  7106,  9215,
    8620,  8637,  8654,  8671,  8688,  8637,  8637,  8705,   210,   217,
   10438,   601,   627,   634,   640,  8722,  5399,   239,   294,   434,
     996,  1028,  1071,   614,  7141,   626,  4858,   852, 10568,   648,
    9722,   655,  8739,  8756,  8773,  8790,  8807,  8824,  8841,  8858,
    8875,  9734,  9748,    33,  9760,   671, 10822, 10835,    33,  4700,
    9968,  9982,   412,  8892,  9994,  9181, 10008, 10020,   900, 10034,
     707, 10046, 10060,   752,   885,  2096,   349,  3626,   200,  1872,
    1029,  1102,  1181,  1992,   192,  7176,    52,    55,    62,  3077,
    8909,  3952, 10448,   691,  5819,  7211,   694,  9774,   703,  8926,
    8943,  8960,  8977,  8994,  9011,  9028,  9045,  9062,  9253,  9267,
      33,   977,  1265,  3669,   562,  9079,  3938,  9215,  9321,  9334,
     628,  9348,   741,  9361,  9375,  1230,   324,  2452,  1207,  3650,
     375,  1976,   340,   463,   680,  4282,   260,   736,   750,  1116,
     398,  4089,  9096,  4095, 10462,   746,  5819,  1153,  7246,  9786,
    9800, 10072,   401, 10086,   527, 10098,  1215, 10112,  1403, 10124,
   10138, 10150,  1534, 10164,  1645, 10176, 10190, 10202,   209,   732,
   10845, 10858,   738,  9812,   749, 10216, 10228,    33,   763,   766,
    9826,   776,   779,  9838,   788, 10472,   814,  7281,  7316,   787,
     845,  9280,  9294,  9388,   521,  9402,  1238,  9415,   735,  9429,
     777,  9442,  9456,  9469,   807,  9483,   850,  9496,  9510,  9523,
     395,   819,  9852,   826,  9537,  9550,    33,   833,   854,  9864,
     861,   866,  9878,   870, 10486,   874,  1422,  1457,   869,  9890,
   10868, 10242, 10254,   886,   877,    23,   892,    24,    28,  4146,
    7981,  3529,  4236,  7351,  7386,  9307,  9564,  9577,   890,   896,
      50,   901,    73,    81,  8013,  8045,  3529,  4296,  1610, 10268,
    7421,  7456,  7491,  7526,  7561,  7596,  7631,  7666, 10496,   902,
     903,   916,  4886,   917,  9113,  5399,  1761,  1796,  1889,  2016,
    2124,  2160,  2196,   921,  7701,  2244,   926, 10510,   930,  9591,
    1837,  2301,  2380,  2488,  2524,  2556,  2591,  2665,  8141,  2744,
    2852,  2888,   931, 10520,   947,  2920,   408,  4451,  9130,  7736,
    4518, 10534,   951,  5819,  4886,  2955,  4886,   274,   274,  1350,
    3029,  8141,  8141,   274,   274,  1356,   945,   949,  9904,   960,
     961,  9916,   966, 10544,   954,  3108,  3216,   968,  7771,  7806,
     982,   985,  9930,   992,  3252,  3284,   993,   994,  9942,  1003,
    1008,    89,  1013,   125,   140,  8077,  8109,  3529,  4590,  3318,
    4886,  4886,  4886,  4886,  8141,  8141,  8141,  8141,  3393,  3549,
    3584,  3691,  3847,  3988,  4406,  4714,  8173,  4795,  4921,  4956,
    1017, 10558,  1020,  7841,  7876,  7911,  7946,  4354,  4652,  4992,
    5060,  5116,  8173,  8173,   274,   274,  1956,  5156,  5191,  1024,
    1025,  9956,  1026,  8173,  8173,  8173,  8173,  5226,  5261,  5296,
    5331
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
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
    -383,  -383,  -383,  1040,   120,  -383,  -383,  -383,  -383,  -383,
     894,  -383,   876,   181,  -269,  -382,  -383,   952,    22,   233,
     312,   540,   600,   723,     0,  -129,  4500,  4444,  4249,  4003,
    3429,  3883,  3585,  1675,  2039,  2403,  -383,  -338,  2767,  1269,
       3,  3131,  -375
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   119,    23,   173,   203,   148,   191,
     168,   169,   170,   271,    67,   120,   121,   122,   123,   272,
     273,   274,   275,   276,   113,   114,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   145,   146,    42,    64,
     124,    45,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   384,   479,    44,   472,   459,   104,   175,    72,   -17,
     462,   252,  -108,  -108,   167,   178,    63,    66,   180,    58,
      31,   297,    25,    44,   551,   554,   -62,   -17,   -17,   556,
     187,   189,   308,   309,   143,   176,   279,   280,   281,   282,
     -17,     6,    25,   179,   298,   -20,   181,   436,     7,     8,
       9,   581,   552,   555,   518,    71,   511,   557,  -120,   108,
     111,  -121,   501,   468,   283,  -111,    59,   277,   252,   206,
     207,   209,   -53,   -53,   584,   -53,   -53,   -53,   -53,   582,
     -53,  -120,   586,   144,  -121,    60,   -14,   -53,   -53,   -53,
     659,   -53,   -53,    68,   -53,   -53,   -53,   196,   -53,   -53,
     333,   -68,   585,   -53,   -14,   -14,   -53,    61,   -50,   -50,
     587,   -50,   -50,   -50,   -50,   332,   -50,   -14,   660,   118,
      22,   277,   -68,   -50,   -50,   -50,   662,   -50,   -50,   523,
     -50,   -50,   -50,   197,   -50,   -50,   -62,    82,  -118,   -50,
      22,   664,   -50,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,   171,   116,    56,   663,    73,   -68,   323,   323,    73,
     -71,  -118,    46,  -118,   190,  -112,  -112,    83,   538,   665,
     392,   -76,   -76,   -76,   -68,   152,   171,  -117,   -71,   183,
     185,    24,    31,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -110,   164,   -76,   -76,   171,    31,    31,   329,   329,
     329,    24,  -119,   332,   195,   241,  -117,  -117,  -117,  -117,
     333,   -71,    31,    31,    31,    31,  -118,    57,   204,   205,
     332,   627,   620,  -119,   -65,  -119,   331,  -119,    85,   389,
      86,   427,   -71,    26,   217,   218,   219,   220,   428,   -35,
     -35,   -63,   -35,   -35,   -35,   -35,   345,   -35,   153,  -120,
     -62,   -62,   476,    26,   -35,   -35,   -35,   147,   -35,   -35,
    -125,   -35,   -35,   -35,   -35,   -35,   -35,   324,   325,   383,
     -35,   389,  -120,   -35,  -120,   328,   155,   222,   223,   224,
     225,   156,     6,   388,   -80,   -80,   -80,   -80,   158,     7,
       8,     9,   -65,   -65,   -39,   -39,   603,   -39,   -39,   -39,
     -39,  -121,   -39,   161,   515,   226,   -66,   -80,   -80,   -39,
     -39,   -39,    27,   -39,   -39,   435,   -39,   -39,   -39,   -39,
     -39,   -39,  -118,   165,  -121,   -39,  -121,   -67,   -39,    72,
     160,  -119,    27,   -83,   -83,   -83,   -83,   376,   317,   317,
     -72,   -72,   334,   144,   166,  -118,   377,   -65,   144,   392,
     -79,   -79,   -79,   464,  -119,   172,   -83,   -83,  -117,   -75,
     -75,   334,   -72,    24,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,   -79,   -79,   174,   390,   -68,    24,    24,   471,
     474,   -75,   210,    72,   277,   390,   -71,  -117,  -117,  -117,
     318,   318,   216,    24,    24,    24,    24,   -68,   -68,   507,
     144,   -63,   576,   578,   252,   503,   389,   -71,   -71,   616,
     177,   333,   -69,  -117,   252,    26,   -18,   592,   594,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,   -63,   -63,    26,
      26,   510,   513,   -69,   -34,   -34,   277,   -34,   -34,   -34,
     -34,   327,   -34,  -117,  -117,    26,    26,    26,    26,   -34,
     -34,   -34,   198,   -34,   -34,   200,   -34,   -34,   -34,   -34,
     -34,   -34,   -72,   -72,    74,   -34,    18,   144,   -34,   319,
     319,   624,   -90,   -90,   -90,   -90,    46,    47,   630,   631,
     633,   -72,    52,    53,   636,   637,   639,    75,   -76,   -76,
     -76,   399,   -24,   -24,    27,   -90,   -90,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,   201,   144,   -76,    27,    27,
     299,   300,   301,   302,   303,   304,   305,   306,   670,   672,
    -112,   400,  -112,  -112,    27,    27,    27,    27,   -15,   573,
     573,   390,   -69,   307,   211,  -109,  -109,   -73,   -73,   334,
      28,   212,    73,   -69,   323,   323,   -75,   -75,    74,   -21,
     192,   567,   575,   -69,   -69,   689,   690,   692,   213,   -73,
      28,   -69,   277,  -117,   602,   -75,   589,   591,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -103,  -103,  -103,
    -103,   215,  -103,  -117,   599,   149,   150,   151,   323,  -103,
    -103,  -103,   378,  -117,  -117,  -117,   379,   619,   622,   380,
      29,   -23,   -23,   277,   277,  -103,   277,   329,   329,   329,
     610,   323,   323,   329,   329,   329,  -117,  -117,  -117,   381,
      29,   335,   -76,   -76,   -76,   385,   628,   438,   629,   505,
    -107,  -107,   430,   634,   635,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,   437,   -76,   573,   573,   -72,   -72,   391,
     277,   277,   277,   277,   323,   323,   323,   323,   431,   506,
    -112,  -112,   -73,   -73,    74,   432,   573,   667,   669,   -72,
     -72,   433,   673,   674,   675,   676,   677,   678,   679,   680,
     -67,   -73,   573,   573,   329,   329,   329,   440,   681,   -89,
     -89,   -89,   -89,   573,   573,   573,   573,   320,   320,   -80,
     -80,   -80,   -80,   461,   687,   688,   308,   309,   -25,   -25,
     566,   566,   -89,   -89,   253,   697,   698,   699,   700,   -80,
     478,  -117,    28,    30,   480,   317,   317,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,   482,    28,    28,   -80,   -80,
     -80,   -80,  -120,    30,   392,   -77,   -77,   -77,   299,  -117,
    -117,  -117,    28,    28,    28,    28,  -121,   321,   321,   253,
     254,   -80,   568,   568,   519,   259,   260,   -77,   -77,   317,
     520,  -101,  -101,  -101,  -101,   517,  -101,   318,   318,   -22,
     -22,   522,    29,  -101,  -101,  -101,   -81,   -81,   -81,   -81,
    -117,  -117,   317,   317,   342,   524,    29,    29,   525,  -101,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,   527,   -81,
     -81,   528,    29,    29,    29,    29,   -86,   -86,   -86,   -86,
     530,   318,   533,  -112,   343,  -112,   566,   566,   393,   -84,
     -84,   -84,   -84,   394,   395,   317,   317,   317,   317,   -86,
     -86,   569,   569,   532,   318,   318,   534,   566,    46,    47,
      48,   535,   -84,   -84,    52,    53,   319,   319,   537,   -85,
     -85,   -85,   -85,   566,   566,   539,   396,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   566,   566,   566,   566,   568,   568,
     322,   322,   -85,   -85,  -117,  -117,   540,   318,   318,   318,
     318,   -91,   -91,   542,   -83,   -83,   -83,   -83,   543,   568,
     319,   466,   545,   547,   548,    30,   550,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,   568,   568,   -83,   549,    30,
      30,   553,   579,   319,   319,   580,   568,   568,   568,   568,
     583,   467,  -112,   596,   597,    30,    30,    30,    30,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,   598,   600,   310,
     605,     2,     3,     4,   221,   607,     6,   569,   569,   609,
     613,  -123,  -123,     7,     8,     9,   319,   319,   319,   319,
     311,   312,   313,   182,   314,   315,   615,   640,   569,    17,
     626,   641,   316,   648,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,   643,   644,   569,   569,   -36,   -36,   646,   -36,
     -36,   -36,   -36,   649,   -36,   569,   569,   569,   569,  -123,
    -123,   -36,   -36,   -36,   650,   -36,   -36,   651,   -36,   -36,
     -36,   -36,   -36,   -36,   653,   654,   655,   -36,   -37,   -37,
     -36,   -37,   -37,   -37,   -37,   657,   -37,   658,   335,   -79,
     -79,   -79,   661,   -37,   -37,   -37,   684,   -37,   -37,   686,
     -37,   -37,   -37,   -37,   -37,   -37,   693,   694,   696,   -37,
      70,   -79,   -37,   -83,   -83,   -83,   -83,   194,   202,   570,
     570,   -38,   -38,   162,   -38,   -38,   -38,   -38,     0,   -38,
       0,     0,     0,   -83,   320,   320,   -38,   -38,   -38,     0,
     -38,   -38,     0,   -38,   -38,   -38,   -38,   -38,   -38,     0,
       0,     0,   -38,     0,     0,   -38,    75,   -79,   -79,   -79,
       0,   -90,   -90,   -90,   -90,     0,   -49,   -49,     0,   -49,
     -49,   -49,   -49,     0,   -49,     0,   -79,     0,   320,   571,
     571,   -49,   -49,   -49,   -90,   -49,   -49,     0,   -49,   -49,
     -49,   -49,   -49,   -49,   321,   321,     0,   -49,     0,     0,
     -49,   320,   320,   -48,   -48,     0,   -48,   -48,   -48,   -48,
       0,   -48,     0,   -90,   -90,   -90,   -90,     0,   -48,   -48,
     -48,     0,   -48,   -48,     0,   -48,   -48,   -48,   -48,   -48,
     -48,     0,     0,   -90,   -48,   570,   570,   -48,   321,     0,
     -89,   -89,   -89,   -89,   320,   320,   320,   320,     0,     0,
     208,     0,   222,   223,   224,   225,   570,     6,     0,     0,
       0,   321,   321,   -89,     7,     8,     9,   -75,   -75,   391,
       0,     0,   570,   570,   335,   -77,   -77,   -77,     0,     0,
     226,   -66,     0,   570,   570,   570,   570,   299,   300,   -75,
     -75,     0,     0,   305,   306,   571,   571,   -77,   -73,   -73,
     391,    -4,   572,   572,   321,   321,   321,   321,    46,    47,
      48,    49,    50,    51,    52,    53,   571,   322,   322,    43,
     -73,   -73,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
      54,    55,   571,   571,     0,     0,   238,     0,     0,    43,
       0,     0,     0,   571,   571,   571,   571,  -124,  -124,     0,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,     0,     0,
       0,   322,    84,    87,     0,   250,   250,   250,   250,   250,
     250,   250,   250,  -123,   250,  -123,  -123,   105,   238,   238,
     -89,   -89,   -89,   -89,   322,   322,   278,     0,     0,     0,
       0,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     -89,   632,   295,   222,   223,   224,   225,   638,     6,   222,
     223,   224,   225,     0,     6,     7,     8,     9,   572,   572,
       0,     7,     8,     9,     0,     0,     0,   322,   322,   322,
     322,   226,   -66,    75,   -77,   -77,   -77,   226,   -66,   572,
     278,     0,     0,   163,   106,     0,   222,   223,   224,   225,
       0,     6,     0,   -77,     0,   572,   572,     0,     7,     8,
       9,   107,   -81,   -81,   -81,   -81,   572,   572,   572,   572,
       0,     0,   -57,   -57,   226,   -57,   -57,   -57,   -57,     0,
     -57,     0,     0,   295,     0,   -81,     0,   -57,   -57,   -57,
     193,   -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,
       0,     0,     0,   -57,     0,     0,   -57,   -56,   -56,     0,
     -56,   -56,   -56,   -56,     0,   -56,     0,   238,   238,   238,
       0,     0,   -56,   -56,   -56,     0,   -56,   -56,     0,   -56,
     -56,   -56,   -56,   -56,   -56,     0,     0,     0,   -56,     0,
       0,   -56,     0,     0,     0,   238,   336,   -84,   -84,   -84,
     -84,   337,   338,   112,   238,     2,     3,     4,   221,     0,
       6,     0,     0,     0,     0,   238,   250,     7,     8,     9,
     -84,     0,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   -66,     0,    17,   310,     0,     2,     3,     4,   221,
       0,     6,     0,   -86,   -86,   -86,   -86,   386,     7,     8,
       9,     0,   238,     0,     0,   311,   312,   313,   184,   314,
     315,   295,     0,     0,    17,     0,   -86,   316,   410,   410,
     410,   410,   410,   410,   410,   410,   410,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,     0,  -124,
    -124,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     -27,   -27,   295,   -27,   -27,   -27,   -27,   295,   -27,     0,
       0,     0,   238,     0,   358,   -27,   -27,   -27,     0,   -27,
     -27,     0,   -27,   -27,   -27,   -27,   -27,   -27,     0,     0,
       0,   -27,     0,     0,   -27,     0,     0,   469,   238,   238,
       0,     0,     0,   278,   -85,   -85,   -85,   -85,   410,   410,
     410,   410,   410,   410,   410,   410,   410,     0,     0,   295,
     -81,   -81,   -81,   -81,   238,     0,   410,   -85,     0,     0,
       0,    69,     0,     2,     3,     4,   221,     0,     6,     0,
     -81,     0,   234,     0,     0,     7,     8,     9,     0,   508,
     238,   238,    12,    13,    14,   278,    15,    16,     0,     0,
       0,    17,     0,     0,    18,    81,     0,     0,     0,     0,
       0,    88,    91,    91,    91,    91,    91,    91,    91,     0,
      91,  -117,     0,     0,   234,   234,   295,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,     0,     0,    91,    91,    91,
      91,    91,    91,    91,   140,    91,     0,     0,   291,  -117,
       0,  -117,   -35,     0,   -35,   -35,   -35,   -35,     0,   -35,
       0,   -86,   -86,   -86,   -86,   295,   -35,   -35,   -35,     0,
     -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,   -86,   -35,     0,     0,   -35,   -35,   -53,     0,   -53,
     -53,   -53,   -53,     0,   -53,     0,   -85,   -85,   -85,   -85,
       0,   -53,   -53,   -53,     0,   -53,   -53,     0,   -53,   -53,
     -53,   604,   -53,   -53,     0,     0,   -85,   -53,     0,     0,
     -53,   -53,     0,     0,     0,     0,     0,   -44,   -44,   291,
     -44,   -44,   -44,   -44,     0,   -44,     0,     0,     0,     0,
       0,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,
     -44,   -44,   -44,   -44,   -44,   617,   238,   238,   -44,     0,
       0,   -44,   278,   234,   234,   234,   238,   238,   238,   253,
     254,   255,   238,   238,   238,   259,   260,     0,     0,     0,
     -39,     0,   -39,   -39,   -39,   -39,     0,   -39,     0,     0,
       0,   234,     0,     0,   -39,   -39,   -39,     0,   -39,   -39,
     341,   -39,   -39,   -39,   -39,   -39,   -39,     0,     0,     0,
     -39,   234,   346,   -39,   -39,     0,     0,     0,   354,   362,
     362,   362,   362,   362,   362,   362,   362,     0,   347,     0,
       0,     0,     0,     0,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,     0,   238,   238,   238,     0,   691,   234,   222,
     223,   224,   225,     0,     6,     0,  -112,   398,   348,     0,
       0,     7,     8,     9,   406,   414,   414,   414,   414,   414,
     414,   414,   414,   299,   300,   301,     0,   226,   -66,   305,
     306,   339,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   253,
     254,   255,   256,   257,   258,   259,   260,   362,   362,   362,
     362,   362,   362,   362,   456,   362,   -91,   -34,   291,   -34,
     -34,   -34,   -34,   291,   -34,     0,     0,     0,   234,     0,
     465,   -34,   -34,   -34,     0,   -34,   -34,     0,   -34,   -34,
     -34,   -34,   -34,   -34,     0,     0,     0,   -34,     0,     0,
     -34,   -34,     0,     0,   234,   234,   235,    76,   -84,   -84,
     -84,   -84,    77,    78,   414,   414,   414,   414,   414,   414,
     414,   498,   414,     0,     0,   291,     0,     0,   -84,     0,
     234,     0,   504,     0,     0,   247,   247,   247,   247,   247,
     247,   247,   247,     0,   247,    46,    47,    48,   235,   235,
      51,    52,    53,   253,   254,   255,   234,   234,   258,   259,
     260,   247,   247,   247,   247,   247,   247,   247,   247,   247,
       0,     0,   292,     0,     0,   -36,     0,   -36,   -36,   -36,
     -36,     0,   -36,     0,     0,     0,     0,     0,     0,   -36,
     -36,   -36,   291,   -36,   -36,     0,   -36,   -36,   -36,   -36,
     -36,   -36,     0,     0,     0,   -36,     0,     0,   -36,   -36,
       0,   -37,     0,   -37,   -37,   -37,   -37,     0,   -37,     0,
       0,     0,     0,     0,     0,   -37,   -37,   -37,     0,   -37,
     -37,   291,   -37,   -37,   -37,   -37,   -37,   -37,     0,     0,
       0,   -37,     0,     0,   -37,   -37,     0,   -38,     0,   -38,
     -38,   -38,   -38,   292,   -38,     0,     0,     0,     0,     0,
       0,   -38,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,
     -38,   -38,   -38,   -38,     0,     0,     0,   -38,     0,     0,
     -38,   -38,     0,     0,     0,     0,     0,   235,   235,   235,
       0,     0,     0,     0,     0,   -50,     0,   -50,   -50,   -50,
     -50,     0,   -50,     0,     0,     0,     0,     0,     0,   -50,
     -50,   -50,     0,   -50,   -50,   235,   -50,   -50,   -50,   606,
     -50,   -50,   234,   234,   235,   -50,     0,     0,   -50,   -50,
       0,     0,   234,   234,   234,   235,   247,     0,   234,   234,
     234,     0,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   -45,   -45,     0,   -45,   -45,   -45,   -45,     0,   -45,
       0,     0,     0,     0,     0,     0,   -45,   -45,   -45,     0,
     -45,   -45,   235,   -45,   -45,   -45,   -45,   -45,   -45,     0,
       0,   292,   -45,     0,     0,   -45,     0,     0,   407,   407,
     407,   407,   407,   407,   407,   407,   407,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,     0,     0,     0,     0,   234,
     234,   234,     0,     0,     0,     0,     0,     0,     0,  -122,
    -122,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     -40,   -40,   292,   -40,   -40,   -40,   -40,   292,   -40,     0,
       0,     0,   235,     0,   355,   -40,   -40,   -40,     0,   -40,
     -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,     0,     0,
       0,   -40,     0,     0,   -40,     0,     0,     0,   235,   235,
     236,     0,     0,     0,     0,     0,     0,     0,   407,   407,
     407,   407,   407,   407,   407,   407,   407,     0,     0,   292,
       0,     0,     0,     0,   235,     0,   407,     0,     0,   248,
     248,   248,   248,   248,   248,   248,   248,     0,   248,   299,
     300,   301,   236,   236,   304,   305,   306,     0,     0,     0,
     235,   235,     0,     0,     0,   248,   248,   248,   248,   248,
     248,   248,   248,   248,     0,     0,   293,     0,   -43,   -43,
       0,   -43,   -43,   -43,   -43,     0,   -43,     0,     0,     0,
       0,     0,     0,   -43,   -43,   -43,   292,   -43,   -43,     0,
     -43,   -43,   -43,   -43,   -43,   -43,     0,     0,     0,   -43,
       0,     0,   -43,     0,   -46,   -46,     0,   -46,   -46,   -46,
     -46,     0,   -46,     0,     0,     0,     0,     0,     0,   -46,
     -46,   -46,     0,   -46,   -46,   292,   -46,   -46,   -46,   -46,
     -46,   -46,     0,     0,     0,   -46,   -41,   -41,   -46,   -41,
     -41,   -41,   -41,     0,   -41,     0,     0,   293,     0,     0,
       0,   -41,   -41,   -41,     0,   -41,   -41,     0,   -41,   -41,
     -41,   -41,   -41,   -41,     0,     0,     0,   -41,     0,     0,
     -41,   -47,   -47,     0,   -47,   -47,   -47,   -47,     0,   -47,
       0,   236,   236,   236,     0,     0,   -47,   -47,   -47,     0,
     -47,   -47,     0,   -47,   -47,   -47,   -47,   -47,   -47,     0,
       0,     0,   -47,     0,     0,   -47,     0,     0,     0,   236,
       0,     0,     0,     0,     0,     0,   235,   235,   236,     0,
       0,     0,     0,     0,     0,     0,   235,   235,   235,   236,
     248,     0,   235,   235,   235,     0,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   -42,   -42,     0,   -42,   -42,
     -42,   -42,     0,   -42,     0,     0,     0,     0,     0,     0,
     -42,   -42,   -42,     0,   -42,   -42,   236,   -42,   -42,   -42,
     -42,   -42,   -42,     0,     0,   293,   -42,     0,     0,   -42,
       0,     0,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,     0,
       0,     0,     0,   235,   235,   235,     0,     0,     0,     0,
       0,     0,     0,   -95,    80,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   -53,   -53,   293,   -53,   -53,   -53,
     -53,   293,   -53,     0,     0,     0,   236,     0,   356,   -53,
     -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,   611,
     -53,   -53,     0,     0,     0,   -53,     0,     0,   -53,     0,
       0,     0,   236,   236,   237,     0,     0,     0,     0,     0,
       0,     0,   408,   408,   408,   408,   408,   408,   408,   408,
     408,     0,     0,   293,     0,     0,     0,     0,   236,     0,
     408,     0,     0,   249,   249,   249,   249,   249,   249,   249,
     249,     0,   249,     0,     0,     0,   237,   237,     0,     0,
       0,     0,     0,     0,   236,   236,     0,     0,     0,   249,
     249,   249,   249,   249,   249,   249,   249,   249,     0,     0,
     294,     0,   -52,   -52,     0,   -52,   -52,   -52,   -52,     0,
     -52,     0,     0,     0,     0,     0,     0,   -52,   -52,   -52,
     293,   -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,
       0,     0,     0,   -52,     0,     0,   -52,     0,   -50,   -50,
       0,   -50,   -50,   -50,   -50,     0,   -50,     0,     0,     0,
       0,     0,     0,   -50,   -50,   -50,     0,   -50,   -50,   293,
     -50,   -50,   -50,   612,   -50,   -50,     0,     0,     0,   -50,
       0,   -49,   -50,   -49,   -49,   -49,   -49,     0,   -49,     0,
       0,   294,     0,     0,     0,   -49,   -49,   -49,     0,   -49,
     -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,
       0,   -49,     0,     0,   -49,   -49,   -48,     0,   -48,   -48,
     -48,   -48,     0,   -48,     0,   237,   237,   237,     0,     0,
     -48,   -48,   -48,     0,   -48,   -48,     0,   -48,   -48,   -48,
     -48,   -48,   -48,     0,     0,     0,   -48,     0,     0,   -48,
     -48,     0,     0,   237,     0,     0,     0,     0,     0,     0,
     236,   236,   237,     0,     0,     0,     0,     0,     0,     0,
     236,   236,   236,   237,   249,     0,   236,   236,   236,     0,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   -55,
     -55,     0,   -55,   -55,   -55,   -55,     0,   -55,     0,     0,
       0,     0,     0,     0,   -55,   -55,   -55,     0,   -55,   -55,
     237,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,   294,
     -55,     0,     0,   -55,     0,     0,   409,   409,   409,   409,
     409,   409,   409,   409,   409,     0,     0,     0,   470,     0,
     222,   223,   224,   225,     0,     6,     0,   236,   236,   236,
       0,     0,     7,     8,     9,   107,     0,     0,     0,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   226,   -57,
     294,   -57,   -57,   -57,   -57,   294,   -57,     0,     0,     0,
     237,     0,   357,   -57,   -57,   -57,     0,   -57,   -57,     0,
     -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,   -57,
       0,     0,   -57,   -57,     0,     0,   237,   237,   239,     0,
       0,     0,     0,     0,     0,     0,   409,   409,   409,   409,
     409,   409,   409,   409,   409,     0,     0,   294,     0,     0,
       0,     0,   237,     0,   409,     0,     0,   251,   251,   251,
     251,   251,   251,   251,   251,     0,   251,     0,     0,     0,
     239,   239,     0,     0,     0,     0,     0,     0,   237,   237,
       0,     0,     0,   251,   251,   251,   251,   251,   251,   251,
     251,   251,     0,     0,   296,     0,     0,   -56,     0,   -56,
     -56,   -56,   -56,     0,   -56,     0,     0,     0,     0,     0,
       0,   -56,   -56,   -56,   294,   -56,   -56,     0,   -56,   -56,
     -56,   -56,   -56,   -56,     0,     0,     0,   -56,     0,     0,
     -56,   -56,   -54,   -54,     0,   -54,   -54,   -54,   -54,     0,
     -54,     0,     0,     0,     0,     0,     0,   -54,   -54,   -54,
       0,   -54,   -54,   294,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,   -54,   -51,   -51,   -54,   -51,   -51,   -51,
     -51,     0,   -51,     0,     0,   296,     0,     0,     0,   -51,
     -51,   -51,     0,   -51,   -51,     0,   -51,   -51,   -51,   -51,
     -51,   -51,     0,     0,     0,   -51,     0,     0,   -51,   -27,
       0,   -27,   -27,   -27,   -27,     0,   -27,     0,     0,   239,
     239,   239,     0,   -27,   -27,   -27,     0,   -27,   -27,     0,
     -27,   -27,   -27,   -27,   -27,   -27,     0,     0,     0,   -27,
       0,     0,   -27,   -27,     0,     0,     0,   239,     0,     0,
       0,     0,     0,     0,   237,   237,   239,     0,     0,     0,
       0,     0,     0,     0,   237,   237,   237,   239,   251,     0,
     237,   237,   237,     0,   359,   359,   359,   359,   359,   359,
     359,   359,   359,     0,   -44,     0,   -44,   -44,   -44,   -44,
       0,   -44,     0,     0,     0,     0,     0,     0,   -44,   -44,
     -44,     0,   -44,   -44,   239,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,   296,   -44,     0,     0,   -44,   -44,     0,
     411,   411,   411,   411,   411,   411,   411,   411,   411,     0,
       0,     0,    46,    47,    48,    49,   231,    51,    52,    53,
       0,   237,   237,   237,     0,   253,   254,   255,   256,   257,
     258,   259,   260,   359,   359,   359,   359,   359,   359,   359,
     359,   359,     0,     0,   296,     0,     0,    93,   261,   296,
     117,   100,   101,     0,   239,  -117,   359,     0,   231,   231,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,     0,
       0,     0,     0,     0,   132,     0,   136,   138,     0,     0,
     239,   239,   288,  -117,  -117,  -117,     0,     0,     0,     0,
     411,   411,   411,   411,   411,   411,   411,   411,   411,     0,
     186,   296,     2,     3,     4,   221,   239,     6,   411,     0,
       0,     0,     0,     0,     7,     8,     9,     0,     0,     0,
     -45,     0,   -45,   -45,   -45,   -45,     0,   -45,   -66,     0,
      17,     0,   239,   239,   -45,   -45,   -45,     0,   -45,   -45,
       0,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,     0,
     -45,     0,     0,   -45,   -45,   -40,     0,   -40,   -40,   -40,
     -40,     0,   -40,   288,     0,     0,     0,     0,   296,   -40,
     -40,   -40,   233,   -40,   -40,     0,   -40,   -40,   -40,   -40,
     -40,   -40,     0,     0,     0,   -40,     0,     0,   -40,   -40,
       0,     0,     0,     0,     0,     0,     0,   231,   231,   231,
       0,     0,    90,   253,   254,   255,   256,   296,   258,   259,
     260,    82,     0,     0,   233,   233,   240,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,   231,     0,   299,   300,   301,
     302,   134,   304,   305,   306,     0,     0,     0,   290,  -112,
    -112,    83,     0,     0,     0,   231,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,   364,   231,   231,   231,   371,   372,
     231,     0,   -43,     0,   -43,   -43,   -43,   -43,     0,   -43,
       0,  -122,  -122,     0,     0,     0,   -43,   -43,   -43,     0,
     -43,   -43,   231,   -43,   -43,   -43,   -43,   -43,   -43,     0,
       0,     0,   -43,     0,     0,   -43,   -43,     0,   239,   239,
     416,   288,   288,   288,   423,   424,   288,     0,   239,   239,
     239,     0,     0,     0,   239,   239,   239,     0,     0,   290,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,     0,     0,
       0,   231,   231,   231,   448,     0,   452,   454,     0,   231,
       0,     0,   288,  -124,     0,  -124,  -124,   288,     0,     0,
       0,     0,   231,   233,   233,   233,     0,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,    62,     0,
       2,     3,     4,   221,     0,     6,     0,     0,   231,   231,
      55,   233,     7,     8,     9,   239,   239,   239,   288,   288,
     288,   490,     0,   494,   496,     0,   288,     0,    17,   288,
       0,   233,     0,     0,   231,     0,     0,     0,     0,   361,
     233,   233,   233,   233,   233,   233,   233,     0,   -46,     0,
     -46,   -46,   -46,   -46,     0,   -46,     0,     0,     0,     0,
     231,   231,   -46,   -46,   -46,     0,   -46,   -46,   233,   -46,
     -46,   -46,   -46,   -46,   -46,     0,     0,     0,   -46,     0,
       0,   -46,   -46,     0,     0,   413,   290,   290,   290,   290,
     290,   290,   290,     0,     0,     0,   288,     0,     0,   188,
     232,     2,     3,     4,   221,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,   233,   233,   233,
     233,   450,   233,   233,     0,   233,     0,   -66,   290,    17,
       0,     0,     0,   290,     0,   288,     0,     0,   233,     0,
       0,     0,   232,   232,     0,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   475,     0,     2,     3,     4,   221,     0,
       6,     0,     0,     0,   233,   233,   289,     7,     8,     9,
     -98,   -98,     0,     0,   290,   290,   290,   290,   492,   290,
     290,   -66,   290,    17,     0,   290,     0,     0,     0,   -41,
     233,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,     0,
       0,     0,     0,   -41,   -41,   -41,     0,   -41,   -41,     0,
     -41,   -41,   -41,   -41,   -41,   -41,   233,   233,     0,   -41,
     230,     0,   -41,   -41,     0,     0,   231,   231,   253,   254,
     255,   256,   257,   258,   259,   260,   231,   231,   231,     0,
       0,     0,   231,   231,   231,     0,     0,   289,     0,     0,
       0,   261,   290,   154,    99,     0,  -102,  -102,  -102,  -102,
       0,  -102,   230,   230,     0,     0,     0,     0,  -102,  -102,
    -102,     0,     0,     0,     0,     0,     0,   130,     0,     0,
       0,   232,   232,   232,  -102,     0,   287,     0,     0,     0,
     509,   290,   222,   223,   224,   225,   514,     6,     2,     3,
       4,   221,     0,     6,     7,     8,     9,   107,     0,   232,
       7,     8,     9,   231,   231,   231,     0,     0,     0,     0,
     226,     0,     0,     0,   -66,     0,    17,     0,     0,   232,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   232,   232,
     232,   232,   232,   232,   232,     0,     0,   558,     0,     2,
       3,     4,   221,  -122,     6,  -122,  -122,     0,     0,     0,
       0,     7,     8,     9,     0,     0,   232,   287,   559,   560,
     561,   562,   563,   564,     0,     0,     0,    17,     0,     0,
     565,     0,   233,   233,   289,   289,   289,   289,   289,   289,
     289,     0,   233,   233,   233,     0,     0,     0,   233,   233,
     233,   230,   230,   230,     0,     0,     0,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   232,   232,   232,   232,     0,
     232,   232,     0,   232,     0,     0,   289,     0,     0,   230,
     397,   289,   -95,   -95,     0,     0,   232,   577,     0,     2,
       3,     4,   221,     0,     6,     0,     0,     0,     0,   230,
       0,     7,     8,     9,     0,     0,     0,     0,     0,   230,
     230,   370,   232,   232,   230,   -66,   229,    17,     0,   233,
     233,   233,   289,   289,   289,   289,     0,   289,   289,     0,
     289,     0,     0,   289,     0,     0,   230,     0,   232,   299,
     300,   301,   302,   303,   304,   305,   306,   593,    95,     2,
       3,     4,   221,     0,     6,   287,   287,   422,   229,   229,
     287,     7,     8,     9,   232,   232,  -104,  -104,  -104,  -104,
       0,  -104,   128,     0,     0,   -66,     0,    17,  -104,  -104,
    -104,     0,   286,     0,     0,   230,   230,   446,     0,     0,
       0,     0,     0,   230,  -104,     0,   287,     0,     0,     0,
     289,   287,     0,     0,   -59,   -59,   230,   -59,   -59,   -59,
     -59,     0,   -59,     0,     0,     0,     0,     0,     0,   -59,
     -59,   -59,     0,   -59,   -59,     0,   -59,   -59,   -59,   -59,
     -59,   -59,   230,   230,     0,   -59,     0,     0,   -59,   289,
       0,     0,   287,   287,   488,     0,     0,     0,     0,     0,
     287,     0,     0,   287,     0,     0,     0,   -47,   230,   -47,
     -47,   -47,   -47,   286,   -47,     0,     0,     0,     0,     0,
       0,   -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,
     -47,   -47,   -47,   -47,   230,   230,     0,   -47,     0,     0,
     -47,   -47,     0,     0,     0,     0,     0,   229,   229,   229,
       0,     0,   618,     0,   222,   223,   224,   225,     0,     6,
       0,   228,     0,     0,     0,     0,     7,     8,     9,   107,
     287,     2,     3,     4,   221,   229,     6,     0,     0,     0,
     232,   232,   226,     7,     8,     9,     0,     0,     0,     0,
     232,   232,   232,     0,    97,   229,   232,   232,   232,    17,
       0,     0,     0,   228,   228,   366,   229,     0,     0,   287,
     229,     0,     0,     0,     0,     0,   126,   227,     0,   623,
       0,     2,     3,     4,   221,     0,     6,   285,     0,     0,
       0,     0,   229,     7,     8,     9,     0,     0,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,     0,   -66,     0,    17,
       0,   418,   286,     0,     0,   103,   286,     0,     0,   227,
     227,   -99,     0,   -99,   -99,     0,     0,   232,   232,   232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   229,   444,   284,     0,     0,     0,     0,     0,   229,
       0,   671,   286,     2,     3,     4,   221,   286,     6,     0,
     230,   230,   229,     0,     0,     7,     8,     9,   285,     0,
     230,   230,   230,     0,     0,     0,   230,   230,   230,   -66,
      65,    17,   222,   223,   224,   225,     0,     6,   229,   229,
       0,     0,     0,     0,     7,     8,     9,     0,   286,   486,
       0,     0,   228,   228,   228,     0,   286,     0,     0,   286,
     226,     0,   -60,   -60,   229,   -60,   -60,   -60,   -60,     0,
     -60,     0,     0,     0,   284,     0,     0,   -60,   -60,   -60,
     228,   -60,   -60,     0,   -60,   -60,   -60,   -60,   -60,   -60,
     229,   229,     0,   -60,     0,     0,   -60,   230,   230,   230,
     228,     0,     0,     0,     0,     0,     0,     0,   227,   227,
     227,   368,     0,     0,     0,   228,     0,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,   -42,   286,   -42,   -42,   -42,
     -42,     0,   -42,     0,     0,     0,   227,   228,     0,   -42,
     -42,   -42,  -123,   -42,   -42,     0,   -42,   -42,   -42,   -42,
     -42,   -42,     0,     0,     0,   -42,   227,   420,   -42,   -42,
       0,   285,     0,     0,     0,   286,     0,     0,     0,     0,
       0,   374,     0,    89,     0,   242,   243,   244,   245,     0,
       6,     0,     0,     0,     0,     0,   442,     7,     8,     9,
       0,     0,     0,   227,   228,     0,     0,   285,     0,     0,
       0,     0,   285,   246,     0,     0,   -53,   228,   -53,   -53,
     -53,   -53,     0,   -53,     0,     0,     0,   426,     0,     0,
     -53,   -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,
     682,   -53,   -53,   228,   228,     0,   -53,     0,     0,   -53,
     -53,     0,     0,   484,     0,     0,     0,     0,     0,     0,
     458,   285,     0,   284,   285,     0,   229,   229,   284,   228,
       0,     0,     0,   227,     0,     0,   229,   229,   229,     0,
       0,     0,   229,   229,   229,   299,   300,   301,   302,   303,
     304,   305,   306,     0,     0,   228,   228,     0,     0,   227,
     227,     0,     0,     0,     0,     0,     0,   262,   307,     2,
       3,     4,   221,     0,     6,     0,     0,   500,     0,     0,
     284,     7,     8,     9,     0,   227,     0,     0,   265,   266,
     267,   285,   268,   269,     0,     0,     0,    17,     0,     0,
     270,     0,   -52,     0,   -52,   -52,   -52,   -52,     0,   -52,
       0,   227,   227,   229,   229,   229,   -52,   -52,   -52,     0,
     -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,     0,
     285,     0,   -52,     0,     0,   -52,   -52,   -50,     0,   -50,
     -50,   -50,   -50,     0,   -50,     0,     0,   284,     0,     0,
       0,   -50,   -50,   -50,     0,   -50,   -50,     0,   -50,   -50,
     -50,   683,   -50,   -50,     0,     0,     0,   -50,     0,     0,
     -50,   -50,   -61,   -61,     0,   -61,   -61,   -61,   -61,     0,
     -61,     0,     0,     0,     0,     0,   284,   -61,   -61,   -61,
       0,   -61,   -61,     0,   -61,   -61,   -61,   -61,   -61,   -61,
       0,     0,     0,   -61,     0,     0,   -61,     0,     0,     0,
       0,     0,    92,     0,   242,   243,   244,   245,     0,     6,
       0,   228,   228,     0,     0,     0,     7,     8,     9,     0,
       0,   228,   228,   228,     0,     0,     0,   228,   228,   228,
     -58,   -58,   246,   -58,   -58,   -58,   -58,     0,   -58,     0,
       0,     0,     0,     0,     0,   -58,   -58,   -58,     0,   -58,
     -58,     0,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,
       0,   -58,     0,     0,   -58,     0,     0,   227,   227,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   227,   227,
       0,     0,     0,   227,   227,   227,     0,   -55,     0,   -55,
     -55,   -55,   -55,     0,   -55,     0,     0,     0,   228,   228,
     228,   -55,   -55,   -55,     0,   -55,   -55,     0,   -55,   -55,
     -55,   -55,   -55,   -55,     0,     0,     0,   -55,     0,     0,
     -55,   -55,     0,     0,     0,     0,     0,   -54,     0,   -54,
     -54,   -54,   -54,     0,   -54,     0,     0,     0,     0,     0,
       0,   -54,   -54,   -54,     0,   -54,   -54,     0,   -54,   -54,
     -54,   -54,   -54,   -54,   227,   227,   227,   -54,     0,     0,
     -54,   -54,   -51,     0,   -51,   -51,   -51,   -51,     0,   -51,
       0,     0,     0,     0,     0,     0,   -51,   -51,   -51,     0,
     -51,   -51,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,
       0,     0,   -51,     0,     0,   -51,   -51,   -59,     0,   -59,
     -59,   -59,   -59,     0,   -59,     0,     0,     0,     0,     0,
       0,   -59,   -59,   -59,     0,   -59,   -59,     0,   -59,   -59,
     -59,   -59,   -59,   -59,     0,     0,     0,   -59,     0,     0,
     -59,   -59,   -60,     0,   -60,   -60,   -60,   -60,     0,   -60,
       0,     0,     0,     0,     0,     0,   -60,   -60,   -60,     0,
     -60,   -60,     0,   -60,   -60,   -60,   -60,   -60,   -60,     0,
       0,     0,   -60,     0,     0,   -60,   -60,   -61,     0,   -61,
     -61,   -61,   -61,     0,   -61,     0,     0,     0,     0,     0,
       0,   -61,   -61,   -61,     0,   -61,   -61,     0,   -61,   -61,
     -61,   -61,   -61,   -61,     0,     0,     0,   -61,     0,     0,
     -61,   -61,   -58,     0,   -58,   -58,   -58,   -58,     0,   -58,
       0,     0,     0,     0,     0,     0,   -58,   -58,   -58,     0,
     -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,   -58,     0,
       0,     0,   -58,     0,     0,   -58,   -58,    -3,     1,     0,
       2,     3,     4,     5,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,    10,    11,     0,    12,
      13,    14,     0,    15,    16,     0,     0,     0,    17,     0,
     -26,    18,   -26,   -26,   -26,   -26,     0,   -26,     0,     0,
       0,     0,     0,     0,   -26,   -26,   -26,     0,   -26,   -26,
       0,   -26,   -26,   -26,     0,   -26,   -26,     0,     0,     0,
     -26,     0,     0,   -26,   -26,    -2,    69,     0,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,    10,    11,     0,    12,    13,    14,
       0,    15,    16,     0,     0,     0,    17,    -6,    -6,    18,
      -6,    -6,    -6,    -6,     0,    -6,     0,     0,     0,     0,
       0,     0,    -6,    -6,    -6,     0,    -6,    -6,     0,    -6,
      -6,    -6,     0,    -6,    -6,     0,     0,     0,    -6,    -8,
      -8,    -6,    -8,    -8,    -8,    -8,     0,    -8,     0,     0,
       0,     0,     0,     0,    -8,    -8,    -8,     0,    -8,    -8,
       0,    -8,    -8,    -8,     0,    -8,    -8,     0,     0,     0,
      -8,    -7,    -7,    -8,    -7,    -7,    -7,    -7,     0,    -7,
       0,     0,     0,     0,     0,     0,    -7,    -7,    -7,     0,
      -7,    -7,     0,    -7,    -7,    -7,     0,    -7,    -7,     0,
       0,     0,    -7,   -35,   -35,    -7,   -35,   -35,   -35,   -35,
       0,   -35,     0,     0,     0,     0,     0,     0,   -35,   -35,
     -35,     0,   -35,   -35,     0,   -35,   -35,   -35,     0,   -35,
     -35,     0,     0,     0,   -35,    -9,    -9,   -35,    -9,    -9,
      -9,    -9,     0,    -9,     0,     0,     0,     0,     0,     0,
      -9,    -9,    -9,     0,    -9,    -9,     0,    -9,    -9,    -9,
       0,    -9,    -9,     0,     0,     0,    -9,   -39,   -39,    -9,
     -39,   -39,   -39,   -39,     0,   -39,     0,     0,     0,     0,
       0,     0,   -39,   -39,   -39,     0,   -39,   -39,     0,   -39,
     -39,   -39,     0,   -39,   -39,     0,     0,     0,   -39,   -34,
     -34,   -39,   -34,   -34,   -34,   -34,     0,   -34,     0,     0,
       0,     0,     0,     0,   -34,   -34,   -34,     0,   -34,   -34,
       0,   -34,   -34,   -34,     0,   -34,   -34,     0,     0,     0,
     -34,   -36,   -36,   -34,   -36,   -36,   -36,   -36,     0,   -36,
       0,     0,     0,     0,     0,     0,   -36,   -36,   -36,     0,
     -36,   -36,     0,   -36,   -36,   -36,     0,   -36,   -36,     0,
       0,     0,   -36,   -37,   -37,   -36,   -37,   -37,   -37,   -37,
       0,   -37,     0,     0,     0,     0,     0,     0,   -37,   -37,
     -37,     0,   -37,   -37,     0,   -37,   -37,   -37,     0,   -37,
     -37,     0,     0,     0,   -37,   -38,   -38,   -37,   -38,   -38,
     -38,   -38,     0,   -38,     0,     0,     0,     0,     0,     0,
     -38,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,
       0,   -38,   -38,     0,     0,     0,   -38,   -49,   -49,   -38,
     -49,   -49,   -49,   -49,     0,   -49,     0,     0,     0,     0,
       0,     0,   -49,   -49,   -49,     0,   -49,   -49,     0,   -49,
     -49,   -49,     0,   -49,   -49,     0,     0,     0,   -49,     0,
     262,   -49,     2,     3,     4,     5,     0,     6,     0,     0,
       0,     0,     0,     0,     7,     8,     9,     0,   263,   264,
       0,   265,   266,   267,     0,   268,   269,     0,     0,     0,
      17,     0,     0,   270,   -29,    -5,    -5,     0,    -5,    -5,
      -5,    -5,     0,    -5,     0,     0,     0,     0,     0,     0,
      -5,    -5,    -5,     0,    -5,    -5,     0,    -5,    -5,    -5,
       0,    -5,    -5,     0,     0,     0,    -5,   -48,   -48,    -5,
     -48,   -48,   -48,   -48,     0,   -48,     0,     0,     0,     0,
       0,     0,   -48,   -48,   -48,     0,   -48,   -48,     0,   -48,
     -48,   -48,     0,   -48,   -48,     0,     0,     0,   -48,   -11,
     -11,   -48,   -11,   -11,   -11,   -11,     0,   -11,     0,     0,
       0,     0,     0,     0,   -11,   -11,   -11,     0,   -11,   -11,
       0,   -11,   -11,   -11,     0,   -11,   -11,     0,     0,     0,
     -11,   -57,   -57,   -11,   -57,   -57,   -57,   -57,     0,   -57,
       0,     0,     0,     0,     0,     0,   -57,   -57,   -57,     0,
     -57,   -57,     0,   -57,   -57,   -57,     0,   -57,   -57,     0,
       0,     0,   -57,   -56,   -56,   -57,   -56,   -56,   -56,   -56,
       0,   -56,     0,     0,     0,     0,     0,     0,   -56,   -56,
     -56,     0,   -56,   -56,     0,   -56,   -56,   -56,     0,   -56,
     -56,     0,     0,     0,   -56,     0,   -32,   -56,   -32,   -32,
     -32,   -32,     0,   -32,     0,     0,     0,     0,     0,     0,
     -32,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,   -32,
       0,   -32,   -32,     0,     0,     0,   -32,     0,     0,   -32,
     -32,   262,     0,     2,     3,     4,     5,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,   263,
     264,     0,   265,   266,   267,     0,   268,   269,     0,     0,
       0,    17,     0,     0,   270,   -28,   -31,     0,   -31,   -31,
     -31,   -31,     0,   -31,     0,     0,     0,     0,     0,     0,
     -31,   -31,   -31,     0,   -31,   -31,     0,   -31,   -31,   -31,
       0,   -31,   -31,     0,     0,     0,   -31,     0,     0,   -31,
     -31,   -33,     0,   -33,   -33,   -33,   -33,     0,   -33,     0,
       0,     0,     0,     0,     0,   -33,   -33,   -33,     0,   -33,
     -33,     0,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,
       0,   -33,     0,     0,   -33,   -33,   -10,   -10,     0,   -10,
     -10,   -10,   -10,     0,   -10,     0,     0,     0,     0,     0,
       0,   -10,   -10,   -10,     0,   -10,   -10,     0,   -10,   -10,
     -10,     0,   -10,   -10,     0,     0,     0,   -10,   -27,   -27,
     -10,   -27,   -27,   -27,   -27,     0,   -27,     0,     0,     0,
       0,     0,     0,   -27,   -27,   -27,     0,   -27,   -27,     0,
     -27,   -27,   -27,     0,   -27,   -27,     0,     0,     0,   -27,
       0,   -30,   -27,   -30,   -30,   -30,   -30,     0,   -30,     0,
       0,     0,     0,     0,     0,   -30,   -30,   -30,     0,   -30,
     -30,     0,   -30,   -30,   -30,     0,   -30,   -30,     0,     0,
       0,   -30,     0,     0,   -30,   -30,   -13,   -13,     0,   -13,
     -13,   -13,   -13,     0,   -13,     0,     0,     0,     0,     0,
       0,   -13,   -13,   -13,     0,   -13,   -13,     0,   -13,   -13,
     -13,     0,   -13,   -13,     0,     0,     0,   -13,   -12,   -12,
     -13,   -12,   -12,   -12,   -12,     0,   -12,     0,     0,     0,
       0,     0,     0,   -12,   -12,   -12,     0,   -12,   -12,     0,
     -12,   -12,   -12,     0,   -12,   -12,     0,     0,     0,   -12,
     -44,   -44,   -12,   -44,   -44,   -44,   -44,     0,   -44,     0,
       0,     0,     0,     0,     0,   -44,   -44,   -44,     0,   -44,
     -44,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,     0,
       0,   -44,   -45,   -45,   -44,   -45,   -45,   -45,   -45,     0,
     -45,     0,     0,     0,     0,     0,     0,   -45,   -45,   -45,
       0,   -45,   -45,     0,   -45,   -45,   -45,     0,   -45,   -45,
       0,     0,     0,   -45,   -40,   -40,   -45,   -40,   -40,   -40,
     -40,     0,   -40,     0,     0,     0,     0,     0,     0,   -40,
     -40,   -40,     0,   -40,   -40,     0,   -40,   -40,   -40,     0,
     -40,   -40,     0,     0,     0,   -40,   -43,   -43,   -40,   -43,
     -43,   -43,   -43,     0,   -43,     0,     0,     0,     0,     0,
       0,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,
     -43,     0,   -43,   -43,     0,     0,     0,   -43,   -46,   -46,
     -43,   -46,   -46,   -46,   -46,     0,   -46,     0,     0,     0,
       0,     0,     0,   -46,   -46,   -46,     0,   -46,   -46,     0,
     -46,   -46,   -46,     0,   -46,   -46,     0,     0,     0,   -46,
     -41,   -41,   -46,   -41,   -41,   -41,   -41,     0,   -41,     0,
       0,     0,     0,     0,     0,   -41,   -41,   -41,     0,   -41,
     -41,     0,   -41,   -41,   -41,     0,   -41,   -41,     0,     0,
       0,   -41,   -47,   -47,   -41,   -47,   -47,   -47,   -47,     0,
     -47,     0,     0,     0,     0,     0,     0,   -47,   -47,   -47,
       0,   -47,   -47,     0,   -47,   -47,   -47,     0,   -47,   -47,
       0,     0,     0,   -47,   -42,   -42,   -47,   -42,   -42,   -42,
     -42,     0,   -42,     0,     0,     0,     0,     0,     0,   -42,
     -42,   -42,     0,   -42,   -42,     0,   -42,   -42,   -42,     0,
     -42,   -42,     0,     0,     0,   -42,   -52,   -52,   -42,   -52,
     -52,   -52,   -52,     0,   -52,     0,     0,     0,     0,     0,
       0,   -52,   -52,   -52,     0,   -52,   -52,     0,   -52,   -52,
     -52,     0,   -52,   -52,     0,     0,     0,   -52,   -55,   -55,
     -52,   -55,   -55,   -55,   -55,     0,   -55,     0,     0,     0,
       0,     0,     0,   -55,   -55,   -55,     0,   -55,   -55,     0,
     -55,   -55,   -55,     0,   -55,   -55,     0,     0,     0,   -55,
     -54,   -54,   -55,   -54,   -54,   -54,   -54,     0,   -54,     0,
       0,     0,     0,     0,     0,   -54,   -54,   -54,     0,   -54,
     -54,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,     0,
       0,   -54,   -51,   -51,   -54,   -51,   -51,   -51,   -51,     0,
     -51,     0,     0,     0,     0,     0,     0,   -51,   -51,   -51,
       0,   -51,   -51,     0,   -51,   -51,   -51,     0,   -51,   -51,
       0,     0,     0,   -51,   -19,   -19,   -51,   -19,   -19,   -19,
     -19,     0,   -19,     0,     0,     0,     0,     0,     0,   -19,
     -19,   -19,     0,   -19,   -19,     0,   -19,   -19,   -19,     0,
     -19,   -19,     0,     0,     0,   -19,   -16,   -16,   -19,   -16,
     -16,   -16,   -16,     0,   -16,     0,     0,     0,     0,     0,
       0,   -16,   -16,   -16,     0,   -16,   -16,     0,   -16,   -16,
     -16,     0,   -16,   -16,     0,     0,     0,   -16,   -59,   -59,
     -16,   -59,   -59,   -59,   -59,     0,   -59,     0,     0,     0,
       0,     0,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,
     -59,   -59,   -59,     0,   -59,   -59,     0,     0,     0,   -59,
     -60,   -60,   -59,   -60,   -60,   -60,   -60,     0,   -60,     0,
       0,     0,     0,     0,     0,   -60,   -60,   -60,     0,   -60,
     -60,     0,   -60,   -60,   -60,     0,   -60,   -60,     0,     0,
       0,   -60,   -61,   -61,   -60,   -61,   -61,   -61,   -61,     0,
     -61,     0,     0,     0,     0,     0,     0,   -61,   -61,   -61,
       0,   -61,   -61,     0,   -61,   -61,   -61,     0,   -61,   -61,
       0,     0,     0,   -61,   -58,   -58,   -61,   -58,   -58,   -58,
     -58,     0,   -58,     0,     0,     0,     0,     0,     0,   -58,
     -58,   -58,     0,   -58,   -58,     0,   -58,   -58,   -58,     0,
     -58,   -58,     0,     0,     0,   -58,     0,   -35,   -58,   -35,
     -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,     0,
       0,   -35,   -35,   -35,     0,   -35,   -35,     0,   -35,   -35,
     -35,     0,   -35,   -35,     0,     0,     0,   -35,     0,     0,
     -35,   -35,   -39,     0,   -39,   -39,   -39,   -39,     0,   -39,
       0,     0,     0,     0,     0,     0,   -39,   -39,   -39,     0,
     -39,   -39,     0,   -39,   -39,   -39,     0,   -39,   -39,     0,
       0,     0,   -39,     0,     0,   -39,   -39,   -34,     0,   -34,
     -34,   -34,   -34,     0,   -34,     0,     0,     0,     0,     0,
       0,   -34,   -34,   -34,     0,   -34,   -34,     0,   -34,   -34,
     -34,     0,   -34,   -34,     0,     0,     0,   -34,     0,     0,
     -34,   -34,   -36,     0,   -36,   -36,   -36,   -36,     0,   -36,
       0,     0,     0,     0,     0,     0,   -36,   -36,   -36,     0,
     -36,   -36,     0,   -36,   -36,   -36,     0,   -36,   -36,     0,
       0,     0,   -36,     0,     0,   -36,   -36,   -37,     0,   -37,
     -37,   -37,   -37,     0,   -37,     0,     0,     0,     0,     0,
       0,   -37,   -37,   -37,     0,   -37,   -37,     0,   -37,   -37,
     -37,     0,   -37,   -37,     0,     0,     0,   -37,     0,     0,
     -37,   -37,   -38,     0,   -38,   -38,   -38,   -38,     0,   -38,
       0,     0,     0,     0,     0,     0,   -38,   -38,   -38,     0,
     -38,   -38,     0,   -38,   -38,   -38,     0,   -38,   -38,     0,
       0,     0,   -38,     0,     0,   -38,   -38,   -11,     0,   -11,
     -11,   -11,   -11,     0,   -11,     0,     0,     0,     0,     0,
       0,   -11,   -11,   -11,     0,   -11,   -11,     0,   -11,   -11,
     -11,     0,   -11,   -11,     0,     0,     0,   -11,     0,     0,
     -11,   -11,   -10,     0,   -10,   -10,   -10,   -10,     0,   -10,
       0,     0,     0,     0,     0,     0,   -10,   -10,   -10,     0,
     -10,   -10,     0,   -10,   -10,   -10,     0,   -10,   -10,     0,
       0,     0,   -10,     0,     0,   -10,   -10,   -49,     0,   -49,
     -49,   -49,   -49,     0,   -49,     0,     0,     0,     0,     0,
       0,   -49,   -49,   -49,     0,   -49,   -49,     0,   -49,   -49,
     -49,     0,   -49,   -49,     0,     0,     0,   -49,     0,     0,
     -49,   -49,   -48,     0,   -48,   -48,   -48,   -48,     0,   -48,
       0,     0,     0,     0,     0,     0,   -48,   -48,   -48,     0,
     -48,   -48,     0,   -48,   -48,   -48,     0,   -48,   -48,     0,
       0,     0,   -48,     0,     0,   -48,   -48,   -12,     0,   -12,
     -12,   -12,   -12,     0,   -12,     0,     0,     0,     0,     0,
       0,   -12,   -12,   -12,     0,   -12,   -12,     0,   -12,   -12,
     -12,     0,   -12,   -12,     0,     0,     0,   -12,     0,     0,
     -12,   -12,   -57,     0,   -57,   -57,   -57,   -57,     0,   -57,
       0,     0,     0,     0,     0,     0,   -57,   -57,   -57,     0,
     -57,   -57,     0,   -57,   -57,   -57,     0,   -57,   -57,     0,
       0,     0,   -57,     0,     0,   -57,   -57,   -56,     0,   -56,
     -56,   -56,   -56,     0,   -56,     0,     0,     0,     0,     0,
       0,   -56,   -56,   -56,     0,   -56,   -56,     0,   -56,   -56,
     -56,     0,   -56,   -56,     0,     0,     0,   -56,     0,     0,
     -56,   -56,   -27,     0,   -27,   -27,   -27,   -27,     0,   -27,
       0,     0,     0,     0,     0,     0,   -27,   -27,   -27,     0,
     -27,   -27,     0,   -27,   -27,   -27,     0,   -27,   -27,     0,
       0,     0,   -27,     0,     0,   -27,   -27,   -13,     0,   -13,
     -13,   -13,   -13,     0,   -13,     0,     0,     0,     0,     0,
       0,   -13,   -13,   -13,     0,   -13,   -13,     0,   -13,   -13,
     -13,     0,   -13,   -13,     0,     0,     0,   -13,     0,     0,
     -13,   -13,   -44,     0,   -44,   -44,   -44,   -44,     0,   -44,
       0,     0,     0,     0,     0,     0,   -44,   -44,   -44,     0,
     -44,   -44,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,
       0,     0,   -44,     0,     0,   -44,   -44,   -45,     0,   -45,
     -45,   -45,   -45,     0,   -45,     0,     0,     0,     0,     0,
       0,   -45,   -45,   -45,     0,   -45,   -45,     0,   -45,   -45,
     -45,     0,   -45,   -45,     0,     0,     0,   -45,     0,     0,
     -45,   -45,   -40,     0,   -40,   -40,   -40,   -40,     0,   -40,
       0,     0,     0,     0,     0,     0,   -40,   -40,   -40,     0,
     -40,   -40,     0,   -40,   -40,   -40,     0,   -40,   -40,     0,
       0,     0,   -40,     0,     0,   -40,   -40,   -43,     0,   -43,
     -43,   -43,   -43,     0,   -43,     0,     0,     0,     0,     0,
       0,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,
     -43,     0,   -43,   -43,     0,     0,     0,   -43,     0,     0,
     -43,   -43,   -46,     0,   -46,   -46,   -46,   -46,     0,   -46,
       0,     0,     0,     0,     0,     0,   -46,   -46,   -46,     0,
     -46,   -46,     0,   -46,   -46,   -46,     0,   -46,   -46,     0,
       0,     0,   -46,     0,     0,   -46,   -46,   -41,     0,   -41,
     -41,   -41,   -41,     0,   -41,     0,     0,     0,     0,     0,
       0,   -41,   -41,   -41,     0,   -41,   -41,     0,   -41,   -41,
     -41,     0,   -41,   -41,     0,     0,     0,   -41,     0,     0,
     -41,   -41,   -47,     0,   -47,   -47,   -47,   -47,     0,   -47,
       0,     0,     0,     0,     0,     0,   -47,   -47,   -47,     0,
     -47,   -47,     0,   -47,   -47,   -47,     0,   -47,   -47,     0,
       0,     0,   -47,     0,     0,   -47,   -47,   -42,     0,   -42,
     -42,   -42,   -42,     0,   -42,     0,     0,     0,     0,     0,
       0,   -42,   -42,   -42,     0,   -42,   -42,     0,   -42,   -42,
     -42,     0,   -42,   -42,     0,     0,     0,   -42,     0,     0,
     -42,   -42,   -52,     0,   -52,   -52,   -52,   -52,     0,   -52,
       0,     0,     0,     0,     0,     0,   -52,   -52,   -52,     0,
     -52,   -52,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,
       0,     0,   -52,     0,     0,   -52,   -52,   -55,     0,   -55,
     -55,   -55,   -55,     0,   -55,     0,     0,     0,     0,     0,
       0,   -55,   -55,   -55,     0,   -55,   -55,     0,   -55,   -55,
     -55,     0,   -55,   -55,     0,     0,     0,   -55,     0,     0,
     -55,   -55,   -54,     0,   -54,   -54,   -54,   -54,     0,   -54,
       0,     0,     0,     0,     0,     0,   -54,   -54,   -54,     0,
     -54,   -54,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,
       0,     0,   -54,     0,     0,   -54,   -54,   -51,     0,   -51,
     -51,   -51,   -51,     0,   -51,     0,     0,     0,     0,     0,
       0,   -51,   -51,   -51,     0,   -51,   -51,     0,   -51,   -51,
     -51,     0,   -51,   -51,     0,     0,     0,   -51,     0,     0,
     -51,   -51,   -59,     0,   -59,   -59,   -59,   -59,     0,   -59,
       0,     0,     0,     0,     0,     0,   -59,   -59,   -59,     0,
     -59,   -59,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,
       0,     0,   -59,     0,     0,   -59,   -59,   -60,     0,   -60,
     -60,   -60,   -60,     0,   -60,     0,     0,     0,     0,     0,
       0,   -60,   -60,   -60,     0,   -60,   -60,     0,   -60,   -60,
     -60,     0,   -60,   -60,     0,     0,     0,   -60,     0,     0,
     -60,   -60,   -61,     0,   -61,   -61,   -61,   -61,     0,   -61,
       0,     0,     0,     0,     0,     0,   -61,   -61,   -61,     0,
     -61,   -61,     0,   -61,   -61,   -61,     0,   -61,   -61,     0,
       0,     0,   -61,     0,     0,   -61,   -61,   -58,     0,   -58,
     -58,   -58,   -58,     0,   -58,     0,     0,     0,     0,     0,
       0,   -58,   -58,   -58,     0,   -58,   -58,     0,   -58,   -58,
     -58,     0,   -58,   -58,     0,     0,     0,   -58,     0,     0,
     -58,   -58,   558,     0,     2,     3,     4,   221,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,     0,     0,   559,   560,   561,   574,   563,   564,     0,
       0,     0,    17,     0,   310,   565,     2,     3,     4,   221,
       0,     6,     0,     0,     0,     0,     0,     0,     7,     8,
       9,     0,     0,     0,     0,   311,   312,   313,   588,   314,
     315,     0,     0,     0,    17,     0,   310,   316,     2,     3,
       4,   221,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,     0,     0,     0,   311,   312,   313,
     590,   314,   315,     0,     0,     0,    17,     0,   558,   316,
       2,     3,     4,   221,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,     0,     0,     0,   559,
     560,   561,   666,   563,   564,     0,     0,     0,    17,     0,
     558,   565,     2,     3,     4,   221,     0,     6,     0,     0,
       0,     0,     0,     0,     7,     8,     9,     0,     0,     0,
       0,   559,   560,   561,   668,   563,   564,     0,     0,     0,
      17,     0,   310,   565,     2,     3,     4,   221,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,     0,     0,   311,   312,   313,     0,   314,   315,     0,
       0,     0,    17,     0,   558,   316,     2,     3,     4,   221,
       0,     6,     0,     0,     0,     0,     0,     0,     7,     8,
       9,     0,     0,     0,     0,   559,   560,   561,     0,   563,
     564,     0,     0,     0,    17,     0,    94,   565,   242,   243,
     244,   245,    96,     6,   242,   243,   244,   245,     0,     6,
       7,     8,     9,     0,     0,     0,     7,     8,     9,     0,
      98,     0,   242,   243,   244,   245,   246,     6,     0,     0,
       0,     0,   246,     0,     7,     8,     9,   102,     0,   242,
     243,   244,   245,     0,     6,     0,     0,     0,     0,     0,
     246,     7,     8,     9,   110,     0,   222,   223,   224,   225,
       0,     6,     0,     0,     0,     0,     0,   246,     7,     8,
       9,   125,     0,   242,   243,   244,   245,     0,     6,     0,
       0,     0,     0,     0,   226,     7,     8,     9,   127,     0,
     242,   243,   244,   245,     0,     6,     0,     0,     0,     0,
       0,   246,     7,     8,     9,   129,     0,   242,   243,   244,
     245,     0,     6,     0,     0,     0,     0,     0,   246,     7,
       8,     9,   131,     0,   242,   243,   244,   245,     0,     6,
       0,     0,     0,     0,     0,   246,     7,     8,     9,   133,
       0,   242,   243,   244,   245,     0,     6,     0,     0,     0,
       0,     0,   246,     7,     8,     9,   135,     0,   242,   243,
     244,   245,     0,     6,     0,     0,     0,     0,     0,   246,
       7,     8,     9,   137,     0,   242,   243,   244,   245,     0,
       6,     0,     0,     0,     0,     0,   246,     7,     8,     9,
     139,     0,   242,   243,   244,   245,     0,     6,     0,     0,
       0,     0,     0,   246,     7,     8,     9,   141,     0,   242,
     243,   244,   245,     0,     6,     0,     0,     0,     0,     0,
     246,     7,     8,     9,   326,     0,   279,   280,   281,   282,
       0,     6,     0,     0,     0,     0,     0,   246,     7,     8,
       9,   330,     0,   222,   223,   224,   225,     0,     6,     0,
       0,     0,     0,     0,   283,     7,     8,     9,   344,     0,
     222,   223,   224,   225,     0,     6,     0,     0,     0,     0,
       0,   226,     7,     8,     9,   360,     0,   349,   350,   351,
     352,     0,     6,     0,     0,     0,     0,     0,   226,     7,
       8,     9,   363,     0,   349,   350,   351,   352,     0,     6,
       0,     0,     0,     0,     0,   353,     7,     8,     9,   365,
       0,   349,   350,   351,   352,     0,     6,     0,     0,     0,
       0,     0,   353,     7,     8,     9,   367,     0,   349,   350,
     351,   352,     0,     6,     0,     0,     0,     0,     0,   353,
       7,     8,     9,   369,     0,   349,   350,   351,   352,     0,
       6,     0,     0,     0,     0,     0,   353,     7,     8,     9,
     373,     0,   349,   350,   351,   352,     0,     6,     0,     0,
       0,     0,     0,   353,     7,     8,     9,   382,     0,     2,
       3,     4,   221,     0,     6,     0,     0,     0,     0,     0,
     353,     7,     8,     9,   387,     0,   222,   223,   224,   225,
       0,     6,     0,     0,     0,     0,     0,    17,     7,     8,
       9,   412,     0,   401,   402,   403,   404,     0,     6,     0,
       0,     0,     0,     0,   226,     7,     8,     9,   415,     0,
     401,   402,   403,   404,     0,     6,     0,     0,     0,     0,
       0,   405,     7,     8,     9,   417,     0,   401,   402,   403,
     404,     0,     6,     0,     0,     0,     0,     0,   405,     7,
       8,     9,   419,     0,   401,   402,   403,   404,     0,     6,
       0,     0,     0,     0,     0,   405,     7,     8,     9,   421,
       0,   401,   402,   403,   404,     0,     6,     0,     0,     0,
       0,     0,   405,     7,     8,     9,   425,     0,   401,   402,
     403,   404,     0,     6,     0,     0,     0,     0,     0,   405,
       7,     8,     9,   434,     0,     2,     3,     4,   221,     0,
       6,     0,     0,     0,     0,     0,   405,     7,     8,     9,
     441,     0,   349,   350,   351,   352,     0,     6,     0,     0,
       0,     0,     0,    17,     7,     8,     9,   443,     0,   349,
     350,   351,   352,     0,     6,     0,     0,     0,     0,     0,
     353,     7,     8,     9,   445,     0,   349,   350,   351,   352,
       0,     6,     0,     0,     0,     0,     0,   353,     7,     8,
       9,   447,     0,   349,   350,   351,   352,     0,     6,     0,
       0,     0,     0,     0,   353,     7,     8,     9,   449,     0,
     349,   350,   351,   352,     0,     6,     0,     0,     0,     0,
       0,   353,     7,     8,     9,   451,     0,   349,   350,   351,
     352,     0,     6,     0,     0,     0,     0,     0,   353,     7,
       8,     9,   453,     0,   349,   350,   351,   352,     0,     6,
       0,     0,     0,     0,     0,   353,     7,     8,     9,   455,
       0,   349,   350,   351,   352,     0,     6,     0,     0,     0,
       0,     0,   353,     7,     8,     9,   457,     0,   349,   350,
     351,   352,     0,     6,     0,     0,     0,     0,     0,   353,
       7,     8,     9,   463,     0,   222,   223,   224,   225,     0,
       6,     0,     0,     0,     0,     0,   353,     7,     8,     9,
     473,     0,   222,   223,   224,   225,     0,     6,     0,     0,
       0,     0,     0,   226,     7,     8,     9,   483,     0,   401,
     402,   403,   404,     0,     6,     0,     0,     0,     0,     0,
     226,     7,     8,     9,   485,     0,   401,   402,   403,   404,
       0,     6,     0,     0,     0,     0,     0,   405,     7,     8,
       9,   487,     0,   401,   402,   403,   404,     0,     6,     0,
       0,     0,     0,     0,   405,     7,     8,     9,   489,     0,
     401,   402,   403,   404,     0,     6,     0,     0,     0,     0,
       0,   405,     7,     8,     9,   491,     0,   401,   402,   403,
     404,     0,     6,     0,     0,     0,     0,     0,   405,     7,
       8,     9,   493,     0,   401,   402,   403,   404,     0,     6,
       0,     0,     0,     0,     0,   405,     7,     8,     9,   495,
       0,   401,   402,   403,   404,     0,     6,     0,     0,     0,
       0,     0,   405,     7,     8,     9,   497,     0,   401,   402,
     403,   404,     0,     6,     0,     0,     0,     0,     0,   405,
       7,     8,     9,   499,     0,   401,   402,   403,   404,     0,
       6,     0,     0,     0,     0,     0,   405,     7,     8,     9,
     502,     0,   222,   223,   224,   225,     0,     6,     0,     0,
       0,     0,     0,   405,     7,     8,     9,   512,     0,   222,
     223,   224,   225,     0,     6,     0,     0,     0,     0,     0,
     226,     7,     8,     9,   601,     0,     2,     3,     4,   221,
       0,     6,     0,     0,     0,     0,     0,   226,     7,     8,
       9,   621,     0,   222,   223,   224,   225,     0,     6,     0,
       0,     0,     0,     0,    17,     7,     8,     9,     0,     0,
     242,   243,   244,   245,     0,     6,     0,     0,     0,     0,
       0,   226,     7,     8,     9,     0,     0,   222,   223,   224,
     225,     0,     6,     0,     0,     0,     0,     0,   246,     7,
       8,     9,     0,     0,   349,   350,   351,   352,     0,     6,
       0,     0,     0,     0,     0,   226,     7,     8,     9,     0,
       0,   279,   280,   281,   282,     0,     6,     0,     0,     0,
       0,     0,   353,     7,     8,     9,     0,     0,   401,   402,
     403,   404,     0,     6,     0,     0,     0,     0,     0,   283,
       7,     8,     9,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,     0,     0,     0,     0,     0,   405,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,     0,  -105,     0,  -105,  -105,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,     0,     0,
    -113,     0,  -113,  -113,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,     0,  -100,     0,  -100,  -100,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,     0,     0,  -116,     0,  -116,
    -116,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,     0,
    -115,     0,  -115,  -115,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,     0,     0,  -114,     0,  -114,  -114,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,     0,  -106,     0,  -106,
    -106,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,     0,
       0,     0,     0,   -99,   -99,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,     0,     0,     0,  -105,  -105,   396,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,     0,     0,     0,     0,
    -113,  -113,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
       0,     0,     0,   -94,   -94,   299,   300,   301,   302,   -70,
     304,   305,   306,     0,     0,     0,     0,   -95,   -95,   299,
     300,   301,   -74,   -74,   304,   305,   306,     0,     0,     0,
     -70,   -70,   299,   300,   301,   -78,   -78,   -78,   305,   306,
       0,     0,     0,     0,   -74,   -74,   299,   300,   -82,   -82,
     -82,   -82,   305,   306,     0,     0,     0,   -78,   -78,   299,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,     0,     0,
       0,   -82,   -82,   396,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,     0,     0,     0,   -93,   -93,   299,   300,   -88,   -88,
     -88,   -88,   305,   306,     0,     0,     0,     0,   -92,   -92,
     299,   300,   -87,   -87,   -87,   -87,   305,   306,     0,     0,
       0,   -88,   -88,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,     0,     0,     0,     0,   -87,   -87,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,     0,     0,     0,   -97,   -97,
     299,   300,   301,   302,   303,   304,   305,   306,     0,     0,
       0,     0,   -96,   -96,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,     0,     0,     0,   -64,   -64,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,     0,     0,     0,     0,  -100,
    -100,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,     0,
       0,     0,  -116,  -116,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,     0,     0,     0,     0,  -115,  -115,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,     0,     0,     0,  -114,
    -114,   253,   254,   255,   256,   257,   258,   259,   260,     0,
       0,     0,     0,  -106,  -106,   253,   254,   255,   256,   257,
     258,   259,   260,     0,   261,     0,   157,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,     0,     0,     0,   261,     0,
     214,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,     0,
    -123,     0,  -123,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,     0,     0,     0,  -124,     0,  -124,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,     0,  -122,     0,  -122,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,     0,     0,     0,
     340,     0,   -95,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,     0,   -99,     0,   -99,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,     0,     0,     0,  -105,     0,  -105,   253,
     254,   255,   256,   257,   258,   259,   260,     0,  -113,     0,
    -113,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,     0,
       0,     0,   261,     0,   439,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,     0,  -100,     0,  -100,   253,   254,   255,
     256,   257,   258,   259,   260,     0,     0,     0,  -116,     0,
    -116,   253,   254,   255,   256,   257,   258,   259,   260,     0,
     261,     0,   460,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,     0,     0,     0,   261,     0,   481,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,     0,  -115,     0,  -115,   253,
     254,   255,   256,   257,   258,   259,   260,     0,     0,     0,
    -114,     0,  -114,   253,   254,   255,   256,   257,   258,   259,
     260,     0,   261,     0,   521,   253,   254,   255,   256,   257,
     258,   259,   260,     0,     0,     0,   261,     0,   526,   253,
     254,   255,   256,   257,   258,   259,   260,     0,   261,     0,
     529,   253,   254,   255,   256,   257,   258,   259,   260,     0,
       0,     0,   261,     0,   536,   253,   254,   255,   256,   257,
     258,   259,   260,     0,   261,     0,   541,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,     0,     0,     0,   261,     0,
     544,   253,   254,   255,   256,   257,   258,   259,   260,     0,
    -106,     0,  -106,   253,   254,   255,   256,   257,   258,   259,
     260,     0,     0,     0,   261,     0,   642,   253,   254,   255,
     256,   257,   258,   259,   260,     0,   261,     0,   645,   253,
     254,   255,   256,   257,   258,   259,   260,     0,     0,     0,
     261,     0,   652,   253,   254,   255,   256,   257,   258,   259,
     260,     0,   261,     0,   656,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,     0,     0,     0,   261,     0,   695,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,     0,
    -124,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,     0,
       0,     0,     0,     0,  -122,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,     0,     0,     0,   -98,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,     0,     0,     0,     0,     0,
     -99,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,
       0,     0,  -105,   339,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,     0,     0,     0,     0,     0,  -113,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,     0,     0,     0,   -94,   253,
     254,   255,   256,   -70,   258,   259,   260,     0,     0,     0,
       0,     0,   -95,   253,   254,   255,   -74,   -74,   258,   259,
     260,     0,     0,     0,   -70,   253,   254,   255,   -78,   -78,
     -78,   259,   260,     0,     0,     0,     0,     0,   -74,   253,
     254,   -82,   -82,   -82,   -82,   259,   260,     0,     0,     0,
     -78,   253,   -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,
       0,     0,     0,     0,   -82,   339,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,     0,     0,     0,   -93,   253,   254,   -88,
     -88,   -88,   -88,   259,   260,     0,     0,     0,     0,     0,
     -92,   253,   254,   -87,   -87,   -87,   -87,   259,   260,     0,
       0,     0,   -88,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,     0,     0,     0,     0,     0,   -87,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,     0,     0,     0,   -97,   253,
     254,   255,   256,   257,   258,   259,   260,     0,     0,     0,
       0,     0,   -96,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,     0,     0,     0,   -64,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,     0,     0,     0,     0,     0,  -100,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,     0,     0,     0,
    -116,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,     0,
       0,     0,     0,     0,  -115,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,     0,     0,     0,  -114,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,     0,     0,     0,     0,     0,
    -106,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   -99,
     -99,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,
       0,     0,     0,  -105,  -105,    46,    47,    48,    49,    50,
      51,    52,    53,  -113,  -113,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,   115,    55,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,    54,    55,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,     0,     0,     0,
       0,  -100,  -100,    46,    47,    48,    49,    50,    51,    52,
      53,  -116,  -116,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,     0,     0,     0,     0,   159,    55,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -115,  -115,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,     0,     0,     0,     0,  -114,
    -114,    46,    47,    48,    49,    50,    51,    52,    53,  -106,
    -106,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,   199,    55,    46,    47,    48,    49,    50,
      51,    52,    53,   375,    55,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,   429,    55,    46,
      47,    48,    49,    50,    51,    52,    53,   477,    55,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,   516,    55,    46,    47,    48,    49,    50,    51,    52,
      53,   531,    55,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,   546,    55,    46,    47,    48,
      49,    50,    51,    52,    53,   595,    55,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,   608,
      55,    46,    47,    48,    49,    50,    51,    52,    53,   614,
      55,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,     0,   625,    55,    46,    47,    48,    49,    50,
      51,    52,    53,   647,    55,   253,   254,   255,   256,   257,
     258,   259,   260,     0,     0,     0,     0,   685,    55,    79,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,     0,   261,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -98,     0,     0,     0,
       0,   -91,    79,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
       0,   -98,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
       0,     0,     0,     0,   -94,    46,    47,    48,    49,   -70,
      51,    52,    53,     0,   -95,    46,    47,    48,   -74,   -74,
      51,    52,    53,     0,     0,     0,     0,   -70,    46,    47,
      48,   -78,   -78,   -78,    52,    53,     0,   -74,    46,    47,
     -82,   -82,   -82,   -82,    52,    53,     0,     0,     0,     0,
     -78,    46,   -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,
     -82,    79,   -92,   -92,   -92,   -92,   -92,   -92,   -92,     0,
       0,     0,     0,   -93,    46,    47,   -88,   -88,   -88,   -88,
      52,    53,     0,   -92,    46,    47,   -87,   -87,   -87,   -87,
      52,    53,     0,     0,     0,     0,   -88,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,     0,   -87,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,     0,     0,     0,     0,   -97,
      46,    47,    48,    49,    50,    51,    52,    53,     0,   -96,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,     0,     0,
       0,     0,   -64,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,     0,  -123,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,     0,     0,     0,     0,  -124,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,     0,  -122,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,     0,     0,     0,     0,   -99,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,  -105,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,     0,     0,     0,
       0,  -113,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
       0,  -100,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
       0,     0,     0,     0,  -116,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,     0,  -115,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,     0,     0,     0,     0,  -114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -106
};

static const yytype_int16 yycheck[] =
{
       0,   270,   384,     0,   379,   343,     1,     1,    11,     1,
     348,     6,    32,    33,     1,     1,    16,    17,     1,    31,
      20,     6,     0,    20,     1,     1,    29,    19,    20,     1,
     159,   160,    19,    20,     1,    29,     3,     4,     5,     6,
      32,     8,    20,    29,    29,    32,    29,   316,    15,    16,
      17,     1,    29,    29,   436,    29,   431,    29,     6,    59,
      60,     6,   400,     1,    31,    32,    31,    67,     6,   198,
     199,   200,     0,     1,     1,     3,     4,     5,     6,    29,
       8,    29,     1,    83,    29,    31,     1,    15,    16,    17,
       1,    19,    20,     0,    22,    23,    24,    25,    26,    27,
      10,    11,    29,    31,    19,    20,    34,    31,     0,     1,
      29,     3,     4,     5,     6,    11,     8,    32,    29,    32,
       0,   121,    32,    15,    16,    17,     1,    19,    20,   467,
      22,    23,    24,    25,    26,    27,    32,     1,     6,    31,
      20,     1,    34,     7,     8,     9,    10,    11,    12,    13,
      14,   148,    29,    21,    29,    10,    11,   157,   158,    10,
      11,    29,     7,    31,   164,    29,    30,    31,   506,    29,
       9,    10,    11,    12,    29,    32,   173,     1,    29,   157,
     158,     0,   182,     7,     8,     9,    10,    11,    12,    13,
      14,    32,    33,    32,    33,   192,   196,   197,   198,   199,
     200,    20,     6,    11,   182,     6,    30,    31,    32,    33,
      10,    11,   212,   213,   214,   215,     6,    21,   196,   197,
      11,   603,   597,     6,    32,    29,   226,    31,    29,    11,
      31,    21,    32,     0,   212,   213,   214,   215,    21,     0,
       1,    32,     3,     4,     5,     6,   246,     8,    32,     6,
      32,    33,   381,    20,    15,    16,    17,    30,    19,    20,
      32,    22,    23,    24,    25,    26,    27,    29,    30,   269,
      31,    11,    29,    34,    31,     1,    32,     3,     4,     5,
       6,    32,     8,   283,     9,    10,    11,    12,    32,    15,
      16,    17,    32,    33,     0,     1,   565,     3,     4,     5,
       6,     6,     8,    35,   433,    31,    32,    32,    33,    15,
      16,    17,     0,    19,    20,   315,    22,    23,    24,    25,
      26,    27,     6,    32,    29,    31,    31,    29,    34,    11,
      29,     6,    20,     9,    10,    11,    12,    21,   157,   158,
      10,    11,    12,   343,     1,    29,    21,    29,   348,     9,
      10,    11,    12,   353,    29,     1,    32,    33,     1,    10,
      11,    12,    32,   182,     7,     8,     9,    10,    11,    12,
      13,    14,    32,    33,    29,    10,    11,   196,   197,   379,
     380,    32,   201,    11,   384,    10,    11,    30,    31,    32,
     157,   158,   211,   212,   213,   214,   215,    32,    33,     1,
     400,    29,   531,   532,     6,   405,    11,    32,    33,     1,
      29,    10,    11,     1,     6,   182,    32,   546,   547,     7,
       8,     9,    10,    11,    12,    13,    14,    32,    33,   196,
     197,   431,   432,    32,     0,     1,   436,     3,     4,     5,
       6,     6,     8,    31,    32,   212,   213,   214,   215,    15,
      16,    17,    29,    19,    20,    29,    22,    23,    24,    25,
      26,    27,    10,    11,    12,    31,    34,   467,    34,   157,
     158,   600,     9,    10,    11,    12,     7,     8,   607,   608,
     609,    29,    13,    14,   613,   614,   615,     9,    10,    11,
      12,     1,    32,    33,   182,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    32,   506,    29,   196,   197,
       7,     8,     9,    10,    11,    12,    13,    14,   647,   648,
      30,    31,    32,    33,   212,   213,   214,   215,    32,   529,
     530,    10,    11,    30,    32,    32,    33,    10,    11,    12,
       0,    32,    10,    11,   544,   545,    10,    11,    12,    32,
      33,   529,   530,    32,    33,   684,   685,   686,    32,    32,
      20,    29,   562,     1,   564,    29,   544,   545,    30,     7,
       8,     9,    10,    11,    12,    13,    14,     3,     4,     5,
       6,    32,     8,    32,   562,    29,    30,    31,   588,    15,
      16,    17,    31,    31,    32,    33,    31,   597,   598,    31,
       0,    32,    33,   603,   604,    31,   606,   607,   608,   609,
     588,   611,   612,   613,   614,   615,    29,    30,    31,    31,
      20,     9,    10,    11,    12,    29,   604,     1,   606,     1,
      32,    33,    31,   611,   612,     7,     8,     9,    10,    11,
      12,    13,    14,    29,    32,   645,   646,    10,    11,    12,
     650,   651,   652,   653,   654,   655,   656,   657,    31,    31,
      32,    33,    10,    11,    12,    31,   666,   645,   646,    32,
      33,    31,   650,   651,   652,   653,   654,   655,   656,   657,
      32,    29,   682,   683,   684,   685,   686,    32,   666,     9,
      10,    11,    12,   693,   694,   695,   696,   157,   158,     9,
      10,    11,    12,    32,   682,   683,    19,    20,    32,    33,
     529,   530,    32,    33,     7,   693,   694,   695,   696,    29,
      29,     1,   182,     0,    30,   544,   545,     7,     8,     9,
      10,    11,    12,    13,    14,    32,   196,   197,     9,    10,
      11,    12,     6,    20,     9,    10,    11,    12,     7,    29,
      30,    31,   212,   213,   214,   215,     6,   157,   158,     7,
       8,    32,   529,   530,    32,    13,    14,    32,    33,   588,
      32,     3,     4,     5,     6,    29,     8,   544,   545,    32,
      33,    32,   182,    15,    16,    17,     9,    10,    11,    12,
      29,    30,   611,   612,     1,    32,   196,   197,    32,    31,
       7,     8,     9,    10,    11,    12,    13,    14,    32,    32,
      33,    32,   212,   213,   214,   215,     9,    10,    11,    12,
      32,   588,    35,    30,    31,    32,   645,   646,     8,     9,
      10,    11,    12,    13,    14,   654,   655,   656,   657,    32,
      33,   529,   530,    29,   611,   612,     1,   666,     7,     8,
       9,    32,    32,    33,    13,    14,   544,   545,    32,     9,
      10,    11,    12,   682,   683,    32,     7,     8,     9,    10,
      11,    12,    13,    14,   693,   694,   695,   696,   645,   646,
     157,   158,    32,    33,    32,    33,    32,   654,   655,   656,
     657,    32,    33,    32,     9,    10,    11,    12,    32,   666,
     588,     1,    32,    29,    35,   182,    29,     7,     8,     9,
      10,    11,    12,    13,    14,   682,   683,    32,    32,   196,
     197,    29,    32,   611,   612,    29,   693,   694,   695,   696,
      29,    31,    32,    31,    31,   212,   213,   214,   215,     7,
       8,     9,    10,    11,    12,    13,    14,    31,    31,     1,
      29,     3,     4,     5,     6,    29,     8,   645,   646,    29,
      29,    29,    30,    15,    16,    17,   654,   655,   656,   657,
      22,    23,    24,    25,    26,    27,    29,    32,   666,    31,
      29,    32,    34,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    32,    32,   682,   683,     0,     1,    32,     3,
       4,     5,     6,    35,     8,   693,   694,   695,   696,    32,
      33,    15,    16,    17,    32,    19,    20,    32,    22,    23,
      24,    25,    26,    27,    32,    32,    32,    31,     0,     1,
      34,     3,     4,     5,     6,    32,     8,    29,     9,    10,
      11,    12,    29,    15,    16,    17,    29,    19,    20,    29,
      22,    23,    24,    25,    26,    27,    32,    32,    32,    31,
      20,    32,    34,     9,    10,    11,    12,   173,   192,   529,
     530,     0,     1,   121,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    29,   544,   545,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,     9,    10,    11,    12,
      -1,     9,    10,    11,    12,    -1,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    29,    -1,   588,   529,
     530,    15,    16,    17,    32,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,   544,   545,    -1,    31,    -1,    -1,
      34,   611,   612,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    29,    31,   645,   646,    34,   588,    -1,
       9,    10,    11,    12,   654,   655,   656,   657,    -1,    -1,
       1,    -1,     3,     4,     5,     6,   666,     8,    -1,    -1,
      -1,   611,   612,    32,    15,    16,    17,    10,    11,    12,
      -1,    -1,   682,   683,     9,    10,    11,    12,    -1,    -1,
      31,    32,    -1,   693,   694,   695,   696,     7,     8,    32,
      33,    -1,    -1,    13,    14,   645,   646,    32,    10,    11,
      12,     0,   529,   530,   654,   655,   656,   657,     7,     8,
       9,    10,    11,    12,    13,    14,   666,   544,   545,     0,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      29,    30,   682,   683,    -1,    -1,    17,    -1,    -1,    20,
      -1,    -1,    -1,   693,   694,   695,   696,    32,    33,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,   588,    43,    44,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    30,    55,    32,    33,    58,    59,    60,
       9,    10,    11,    12,   611,   612,    67,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      29,     1,    83,     3,     4,     5,     6,     1,     8,     3,
       4,     5,     6,    -1,     8,    15,    16,    17,   645,   646,
      -1,    15,    16,    17,    -1,    -1,    -1,   654,   655,   656,
     657,    31,    32,     9,    10,    11,    12,    31,    32,   666,
     121,    -1,    -1,   124,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    29,    -1,   682,   683,    -1,    15,    16,
      17,    18,     9,    10,    11,    12,   693,   694,   695,   696,
      -1,    -1,     0,     1,    31,     3,     4,     5,     6,    -1,
       8,    -1,    -1,   164,    -1,    32,    -1,    15,    16,    17,
     171,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,   198,   199,   200,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    -1,    -1,    -1,   226,     8,     9,    10,    11,
      12,    13,    14,     1,   235,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,   246,   247,    15,    16,    17,
      32,    -1,   253,   254,   255,   256,   257,   258,   259,   260,
     261,    29,    -1,    31,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,   278,    15,    16,
      17,    -1,   283,    -1,    -1,    22,    23,    24,    25,    26,
      27,   292,    -1,    -1,    31,    -1,    32,    34,   299,   300,
     301,   302,   303,   304,   305,   306,   307,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,   332,   333,   334,   335,   336,   337,   338,   339,   340,
       0,     1,   343,     3,     4,     5,     6,   348,     8,    -1,
      -1,    -1,   353,    -1,   355,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    -1,   378,   379,   380,
      -1,    -1,    -1,   384,     9,    10,    11,    12,   389,   390,
     391,   392,   393,   394,   395,   396,   397,    -1,    -1,   400,
       9,    10,    11,    12,   405,    -1,   407,    32,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      29,    -1,    17,    -1,    -1,    15,    16,    17,    -1,   430,
     431,   432,    22,    23,    24,   436,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    40,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,     1,    -1,    -1,    59,    60,   467,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    83,    29,
      -1,    31,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,     9,    10,    11,    12,   506,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    29,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,     9,    10,    11,    12,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    29,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,     0,     1,   164,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   596,   597,   598,    31,    -1,
      -1,    34,   603,   198,   199,   200,   607,   608,   609,     7,
       8,     9,   613,   614,   615,    13,    14,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,   226,    -1,    -1,    15,    16,    17,    -1,    19,    20,
     235,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,   246,   247,    34,    35,    -1,    -1,    -1,   253,   254,
     255,   256,   257,   258,   259,   260,   261,    -1,     1,    -1,
      -1,    -1,    -1,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,   684,   685,   686,    -1,     1,   283,     3,
       4,     5,     6,    -1,     8,    -1,    29,   292,    31,    -1,
      -1,    15,    16,    17,   299,   300,   301,   302,   303,   304,
     305,   306,   307,     7,     8,     9,    -1,    31,    32,    13,
      14,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,   332,   333,   334,
     335,   336,   337,   338,   339,   340,    32,     1,   343,     3,
       4,     5,     6,   348,     8,    -1,    -1,    -1,   353,    -1,
     355,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,   379,   380,    17,     8,     9,    10,
      11,    12,    13,    14,   389,   390,   391,   392,   393,   394,
     395,   396,   397,    -1,    -1,   400,    -1,    -1,    29,    -1,
     405,    -1,   407,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,     7,     8,     9,    59,    60,
      12,    13,    14,     7,     8,     9,   431,   432,    12,    13,
      14,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    83,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,   467,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,   506,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,     1,    -1,     3,
       4,     5,     6,   164,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,   198,   199,   200,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,   226,    22,    23,    24,    25,
      26,    27,   597,   598,   235,    31,    -1,    -1,    34,    35,
      -1,    -1,   607,   608,   609,   246,   247,    -1,   613,   614,
     615,    -1,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   283,    22,    23,    24,    25,    26,    27,    -1,
      -1,   292,    31,    -1,    -1,    34,    -1,    -1,   299,   300,
     301,   302,   303,   304,   305,   306,   307,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,   684,
     685,   686,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,   332,   333,   334,   335,   336,   337,   338,   339,   340,
       0,     1,   343,     3,     4,     5,     6,   348,     8,    -1,
      -1,    -1,   353,    -1,   355,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    -1,    -1,   379,   380,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   389,   390,
     391,   392,   393,   394,   395,   396,   397,    -1,    -1,   400,
      -1,    -1,    -1,    -1,   405,    -1,   407,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,     7,
       8,     9,    59,    60,    12,    13,    14,    -1,    -1,    -1,
     431,   432,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    83,    -1,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,   467,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    -1,     0,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,   506,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,   164,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,   198,   199,   200,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,   597,   598,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   607,   608,   609,   246,
     247,    -1,   613,   614,   615,    -1,   253,   254,   255,   256,
     257,   258,   259,   260,   261,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,   283,    22,    23,    24,
      25,    26,    27,    -1,    -1,   292,    31,    -1,    -1,    34,
      -1,    -1,   299,   300,   301,   302,   303,   304,   305,   306,
     307,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,   684,   685,   686,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,   332,   333,   334,   335,   336,
     337,   338,   339,   340,     0,     1,   343,     3,     4,     5,
       6,   348,     8,    -1,    -1,    -1,   353,    -1,   355,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    -1,   379,   380,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   389,   390,   391,   392,   393,   394,   395,   396,
     397,    -1,    -1,   400,    -1,    -1,    -1,    -1,   405,    -1,
     407,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,   431,   432,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      83,    -1,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
     467,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    -1,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,   506,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,   164,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,   198,   199,   200,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
     597,   598,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     607,   608,   609,   246,   247,    -1,   613,   614,   615,    -1,
     253,   254,   255,   256,   257,   258,   259,   260,   261,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
     283,    22,    23,    24,    25,    26,    27,    -1,    -1,   292,
      31,    -1,    -1,    34,    -1,    -1,   299,   300,   301,   302,
     303,   304,   305,   306,   307,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,   684,   685,   686,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    -1,   332,
     333,   334,   335,   336,   337,   338,   339,   340,    31,     1,
     343,     3,     4,     5,     6,   348,     8,    -1,    -1,    -1,
     353,    -1,   355,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,   379,   380,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   389,   390,   391,   392,
     393,   394,   395,   396,   397,    -1,    -1,   400,    -1,    -1,
      -1,    -1,   405,    -1,   407,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,   431,   432,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    83,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,   467,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,   506,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,   164,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,   198,
     199,   200,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,   597,   598,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   607,   608,   609,   246,   247,    -1,
     613,   614,   615,    -1,   253,   254,   255,   256,   257,   258,
     259,   260,   261,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,   283,    22,    23,    24,    25,    26,
      27,    -1,    -1,   292,    31,    -1,    -1,    34,    35,    -1,
     299,   300,   301,   302,   303,   304,   305,   306,   307,    -1,
      -1,    -1,     7,     8,     9,    10,    17,    12,    13,    14,
      -1,   684,   685,   686,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,   332,   333,   334,   335,   336,   337,   338,
     339,   340,    -1,    -1,   343,    -1,    -1,    48,    30,   348,
      32,    52,    53,    -1,   353,     1,   355,    -1,    59,    60,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    77,    78,    -1,    -1,
     379,   380,    83,    29,    30,    31,    -1,    -1,    -1,    -1,
     389,   390,   391,   392,   393,   394,   395,   396,   397,    -1,
       1,   400,     3,     4,     5,     6,   405,     8,   407,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    29,    -1,
      31,    -1,   431,   432,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,   164,    -1,    -1,    -1,    -1,   467,    15,
      16,    17,    17,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,   199,   200,
      -1,    -1,    47,     7,     8,     9,    10,   506,    12,    13,
      14,     1,    -1,    -1,    59,    60,     6,     7,     8,     9,
      10,    11,    12,    13,    14,   226,    -1,     7,     8,     9,
      10,    76,    12,    13,    14,    -1,    -1,    -1,    83,    29,
      30,    31,    -1,    -1,    -1,   246,     7,     8,     9,    10,
      11,    12,    13,    14,   255,   256,   257,   258,   259,   260,
     261,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    32,    33,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   283,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,   597,   598,
     301,   302,   303,   304,   305,   306,   307,    -1,   607,   608,
     609,    -1,    -1,    -1,   613,   614,   615,    -1,    -1,   164,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,   332,   333,   334,   335,    -1,   337,   338,    -1,   340,
      -1,    -1,   343,    30,    -1,    32,    33,   348,    -1,    -1,
      -1,    -1,   353,   198,   199,   200,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,   379,   380,
      30,   226,    15,    16,    17,   684,   685,   686,   389,   390,
     391,   392,    -1,   394,   395,    -1,   397,    -1,    31,   400,
      -1,   246,    -1,    -1,   405,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
     431,   432,    15,    16,    17,    -1,    19,    20,   283,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,    -1,   300,   301,   302,   303,   304,
     305,   306,   307,    -1,    -1,    -1,   467,    -1,    -1,     1,
      17,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,   332,   333,   334,
     335,   336,   337,   338,    -1,   340,    -1,    29,   343,    31,
      -1,    -1,    -1,   348,    -1,   506,    -1,    -1,   353,    -1,
      -1,    -1,    59,    60,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,   379,   380,    83,    15,    16,    17,
      32,    33,    -1,    -1,   389,   390,   391,   392,   393,   394,
     395,    29,   397,    31,    -1,   400,    -1,    -1,    -1,     1,
     405,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,   431,   432,    -1,    31,
      17,    -1,    34,    35,    -1,    -1,   597,   598,     7,     8,
       9,    10,    11,    12,    13,    14,   607,   608,   609,    -1,
      -1,    -1,   613,   614,   615,    -1,    -1,   164,    -1,    -1,
      -1,    30,   467,    32,    51,    -1,     3,     4,     5,     6,
      -1,     8,    59,    60,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,   198,   199,   200,    31,    -1,    83,    -1,    -1,    -1,
       1,   506,     3,     4,     5,     6,     1,     8,     3,     4,
       5,     6,    -1,     8,    15,    16,    17,    18,    -1,   226,
      15,    16,    17,   684,   685,   686,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    29,    -1,    31,    -1,    -1,   246,
       7,     8,     9,    10,    11,    12,    13,    14,   255,   256,
     257,   258,   259,   260,   261,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    30,     8,    32,    33,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    -1,   283,   164,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,   597,   598,   301,   302,   303,   304,   305,   306,
     307,    -1,   607,   608,   609,    -1,    -1,    -1,   613,   614,
     615,   198,   199,   200,    -1,    -1,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,   332,   333,   334,   335,    -1,
     337,   338,    -1,   340,    -1,    -1,   343,    -1,    -1,   226,
      30,   348,    32,    33,    -1,    -1,   353,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,   246,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,   256,
     257,   258,   379,   380,   261,    29,    17,    31,    -1,   684,
     685,   686,   389,   390,   391,   392,    -1,   394,   395,    -1,
     397,    -1,    -1,   400,    -1,    -1,   283,    -1,   405,     7,
       8,     9,    10,    11,    12,    13,    14,     1,    49,     3,
       4,     5,     6,    -1,     8,   302,   303,   304,    59,    60,
     307,    15,    16,    17,   431,   432,     3,     4,     5,     6,
      -1,     8,    73,    -1,    -1,    29,    -1,    31,    15,    16,
      17,    -1,    83,    -1,    -1,   332,   333,   334,    -1,    -1,
      -1,    -1,    -1,   340,    31,    -1,   343,    -1,    -1,    -1,
     467,   348,    -1,    -1,     0,     1,   353,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,   379,   380,    -1,    31,    -1,    -1,    34,   506,
      -1,    -1,   389,   390,   391,    -1,    -1,    -1,    -1,    -1,
     397,    -1,    -1,   400,    -1,    -1,    -1,     1,   405,     3,
       4,     5,     6,   164,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,   431,   432,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,   198,   199,   200,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    17,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
     467,     3,     4,     5,     6,   226,     8,    -1,    -1,    -1,
     597,   598,    31,    15,    16,    17,    -1,    -1,    -1,    -1,
     607,   608,   609,    -1,    50,   246,   613,   614,   615,    31,
      -1,    -1,    -1,    59,    60,   256,   257,    -1,    -1,   506,
     261,    -1,    -1,    -1,    -1,    -1,    72,    17,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    83,    -1,    -1,
      -1,    -1,   283,    15,    16,    17,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    29,    -1,    31,
      -1,   302,   303,    -1,    -1,    55,   307,    -1,    -1,    59,
      60,    30,    -1,    32,    33,    -1,    -1,   684,   685,   686,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,   332,   333,    83,    -1,    -1,    -1,    -1,    -1,   340,
      -1,     1,   343,     3,     4,     5,     6,   348,     8,    -1,
     597,   598,   353,    -1,    -1,    15,    16,    17,   164,    -1,
     607,   608,   609,    -1,    -1,    -1,   613,   614,   615,    29,
       1,    31,     3,     4,     5,     6,    -1,     8,   379,   380,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,   389,   390,
      -1,    -1,   198,   199,   200,    -1,   397,    -1,    -1,   400,
      31,    -1,     0,     1,   405,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,   164,    -1,    -1,    15,    16,    17,
     226,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
     431,   432,    -1,    31,    -1,    -1,    34,   684,   685,   686,
     246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,   199,
     200,   257,    -1,    -1,    -1,   261,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,     1,   467,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,   226,   283,    -1,    15,
      16,    17,    32,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,   246,   303,    34,    35,
      -1,   307,    -1,    -1,    -1,   506,    -1,    -1,    -1,    -1,
      -1,   261,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,   332,    15,    16,    17,
      -1,    -1,    -1,   283,   340,    -1,    -1,   343,    -1,    -1,
      -1,    -1,   348,    31,    -1,    -1,     1,   353,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,   307,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,   379,   380,    -1,    31,    -1,    -1,    34,
      35,    -1,    -1,   389,    -1,    -1,    -1,    -1,    -1,    -1,
     340,   397,    -1,   343,   400,    -1,   597,   598,   348,   405,
      -1,    -1,    -1,   353,    -1,    -1,   607,   608,   609,    -1,
      -1,    -1,   613,   614,   615,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,   431,   432,    -1,    -1,   379,
     380,    -1,    -1,    -1,    -1,    -1,    -1,     1,    30,     3,
       4,     5,     6,    -1,     8,    -1,    -1,   397,    -1,    -1,
     400,    15,    16,    17,    -1,   405,    -1,    -1,    22,    23,
      24,   467,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,   431,   432,   684,   685,   686,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
     506,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,   467,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,   506,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,   597,   598,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,   607,   608,   609,    -1,    -1,    -1,   613,   614,   615,
       0,     1,    31,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    -1,   597,   598,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   607,   608,   609,
      -1,    -1,    -1,   613,   614,   615,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,   684,   685,
     686,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,   684,   685,   686,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,     0,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,     0,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,     0,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,     0,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,     0,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,     0,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,     0,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,     0,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,     1,     8,     3,     4,     5,     6,    -1,     8,
      15,    16,    17,    -1,    -1,    -1,    15,    16,    17,    -1,
       1,    -1,     3,     4,     5,     6,    31,     8,    -1,    -1,
      -1,    -1,    31,    -1,    15,    16,    17,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      31,    15,    16,    17,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,
      17,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    31,    15,    16,    17,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    31,    15,    16,    17,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,
      16,    17,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    31,    15,    16,    17,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,
      15,    16,    17,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    31,    15,    16,    17,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      31,    15,    16,    17,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,
      17,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    31,    15,    16,    17,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    31,    15,    16,    17,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,
      16,    17,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    31,    15,    16,    17,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,
      15,    16,    17,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    31,    15,    16,    17,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      31,    15,    16,    17,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,
      17,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    31,    15,    16,    17,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    31,    15,    16,    17,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,
      16,    17,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    31,    15,    16,    17,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,
      15,    16,    17,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    31,    15,    16,    17,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      31,    15,    16,    17,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,
      17,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    31,    15,    16,    17,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    31,    15,    16,    17,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,
      16,    17,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    31,    15,    16,    17,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,
      15,    16,    17,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    31,    15,    16,    17,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      31,    15,    16,    17,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,
      17,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    31,    15,    16,    17,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    31,    15,    16,    17,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,
      16,    17,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    31,    15,    16,    17,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,
      15,    16,    17,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    31,    15,    16,    17,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      31,    15,    16,    17,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,
      17,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    31,    15,    16,    17,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    31,    15,    16,    17,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,
      16,    17,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,    -1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    31,    15,    16,    17,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,
      15,    16,    17,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    31,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    30,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      30,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    30,    -1,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    30,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      30,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    30,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    30,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    30,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    30,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    30,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    30,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    30,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    30,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    30,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    30,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    30,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    30,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    30,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    30,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    30,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    30,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    30,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    30,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    30,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    30,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    30,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    30,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    30,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    30,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    29,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    29,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    29,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    29,    30,     7,     8,     9,
      10,    11,    12,    13,    14,    29,    30,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    29,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    29,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    29,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    29,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    29,    30,     7,     8,     9,
      10,    11,    12,    13,    14,    29,    30,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    29,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    29,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    29,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    29,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    29,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      29,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      29,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    29,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    29,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,    15,    16,    17,
      19,    20,    22,    23,    24,    26,    27,    31,    34,    37,
      38,    39,    40,    41,    49,    54,    55,    56,    57,    58,
      59,    60,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    74,    75,    76,    77,     7,     8,     9,    10,
      11,    12,    13,    14,    29,    30,    21,    21,    31,    31,
      31,    31,     1,    60,    75,     1,    60,    50,     0,     1,
      39,    29,    11,    10,    12,     9,     8,    13,    14,     7,
      30,    69,     1,    31,    75,    29,    31,    75,    69,     1,
      68,    69,     1,    66,     1,    64,     1,    63,     1,    65,
      66,    66,     1,    62,     1,    75,     1,    18,    60,    78,
       1,    60,     1,    60,    61,    29,    29,    32,    32,    40,
      51,    52,    53,    54,    76,     1,    63,     1,    64,     1,
      65,     1,    66,     1,    68,     1,    66,     1,    66,     1,
      69,     1,    62,     1,    60,    72,    73,    30,    44,    29,
      30,    31,    32,    32,    32,    32,    32,    32,    32,    29,
      29,    35,    53,    75,    33,    32,     1,     1,    46,    47,
      48,    76,     1,    42,    29,     1,    29,    29,     1,    29,
       1,    29,    25,    54,    25,    54,     1,    61,     1,    61,
      60,    45,    33,    75,    46,    54,    25,    25,    29,    29,
      29,    32,    48,    43,    54,    54,    61,    61,     1,    61,
      49,    32,    32,    32,    32,    32,    49,    54,    54,    54,
      54,     6,     3,     4,     5,     6,    31,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    74,    75,    77,
       6,     6,     3,     4,     5,     6,    31,    70,    71,    74,
      75,    77,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    30,     1,    19,    20,    22,    23,    24,    26,    27,
      34,    49,    55,    56,    57,    58,    59,    60,    75,     3,
       4,     5,     6,    31,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    74,    75,    77,     6,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    30,    19,    20,
       1,    22,    23,    24,    26,    27,    34,    49,    55,    56,
      57,    58,    59,    60,    29,    30,     1,     6,     1,    60,
       1,    60,    11,    10,    12,     9,     8,    13,    14,     7,
      30,    69,     1,    31,     1,    60,    69,     1,    31,     3,
       4,     5,     6,    31,    69,    70,    71,    74,    75,    77,
       1,    68,    69,     1,    66,     1,    64,     1,    63,     1,
      65,    66,    66,     1,    62,    29,    21,    21,    31,    31,
      31,    31,     1,    60,    50,    29,    75,     1,    60,    11,
      10,    12,     9,     8,    13,    14,     7,    30,    69,     1,
      31,     3,     4,     5,     6,    31,    69,    70,    71,    74,
      75,    77,     1,    68,    69,     1,    66,     1,    64,     1,
      63,     1,    65,    66,    66,     1,    62,    21,    21,    29,
      31,    31,    31,    31,     1,    60,    50,    29,     1,    32,
      32,     1,    63,     1,    64,     1,    65,     1,    66,     1,
      68,     1,    66,     1,    66,     1,    69,     1,    62,    73,
      32,    32,    73,     1,    60,    69,     1,    31,     1,    75,
       1,    60,    78,     1,    60,     1,    61,    29,    29,    51,
      30,    32,    32,     1,    63,     1,    64,     1,    65,     1,
      66,     1,    68,     1,    66,     1,    66,     1,    69,     1,
      62,    73,     1,    60,    69,     1,    31,     1,    75,     1,
      60,    78,     1,    60,     1,    61,    29,    29,    51,    32,
      32,    32,    32,    73,    32,    32,    32,    32,    32,    32,
      32,    29,    29,    35,     1,    32,    32,    32,    73,    32,
      32,    32,    32,    32,    32,    32,    29,    29,    35,    32,
      29,     1,    29,    29,     1,    29,     1,    29,     1,    22,
      23,    24,    25,    26,    27,    34,    49,    54,    55,    56,
      57,    58,    59,    60,    25,    54,    61,     1,    61,    32,
      29,     1,    29,    29,     1,    29,     1,    29,    25,    54,
      25,    54,    61,     1,    61,    29,    31,    31,    31,    54,
      31,     1,    60,    50,    25,    29,    25,    29,    29,    29,
      54,    25,    25,    29,    29,    29,     1,    75,     1,    60,
      78,     1,    60,     1,    61,    29,    29,    51,    54,    54,
      61,    61,     1,    61,    54,    54,    61,    61,     1,    61,
      32,    32,    32,    32,    32,    32,    32,    29,    29,    35,
      32,    32,    32,    32,    32,    32,    32,    32,    29,     1,
      29,    29,     1,    29,     1,    29,    25,    54,    25,    54,
      61,     1,    61,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    25,    25,    29,    29,    29,    54,    54,    61,
      61,     1,    61,    32,    32,    32,    32,    54,    54,    54,
      54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    38,    38,    39,    39,    39,
      40,    40,    40,    40,    42,    43,    41,    44,    45,    41,
      46,    46,    47,    47,    47,    48,    50,    49,    51,    51,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    57,    58,    58,    59,    59,
      59,    59,    60,    60,    60,    60,    61,    61,    62,    62,
      62,    62,    63,    63,    63,    63,    64,    64,    64,    64,
      65,    65,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    68,    68,    68,    68,    69,
      69,    70,    70,    70,    70,    71,    71,    72,    72,    72,
      73,    73,    74,    74,    74,    74,    74,    75,    76,    76,
      76,    76,    77,    77,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       3,     2,     4,     4,     0,     0,     8,     0,     0,     7,
       0,     1,     3,     1,     1,     2,     0,     4,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     5,     5,     5,     5,     2,     2,
       5,     7,     5,     5,     7,     6,     3,     3,     9,     9,
       9,     9,     1,     3,     3,     3,     0,     1,     1,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     1,
       2,     1,     1,     1,     1,     1,     4,     3,     1,     1,
       1,     0,     1,     1,     3,     3,     2,     1,     1,     1,
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
#line 145 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3941 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3947 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3953 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3959 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3965 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3971 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3977 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3983 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3989 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3995 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4001 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4007 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4013 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4019 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4025 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4031 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4037 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4043 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4049 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4055 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4061 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_1: /* @1  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4067 "src/bison/grammar.c"
        break;

    case YYSYMBOL_46_param_list_opt: /* param_list.opt  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4073 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4079 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4085 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4091 "src/bison/grammar.c"
        break;

    case YYSYMBOL_51_block_item_list_opt: /* block_item_list.opt  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4097 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4103 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4109 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4115 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4121 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4127 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4133 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4139 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4145 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4151 "src/bison/grammar.c"
        break;

    case YYSYMBOL_61_expression_opt: /* expression.opt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4157 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4163 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4169 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4175 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4181 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4187 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4193 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4199 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4205 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4211 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4217 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4223 "src/bison/grammar.c"
        break;

    case YYSYMBOL_73_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4229 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4235 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 145 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 4241 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4247 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4253 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4259 "src/bison/grammar.c"
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
#line 151 "src/bison/grammar.y"
             { show_error((yyloc), "ISO C-IPL forbids an empty translation unit\n"); }
#line 4568 "src/bison/grammar.c"
    break;

  case 4: /* prog: error  */
#line 152 "src/bison/grammar.y"
            {
        // idk if this is the best solution
        // actually dont work properly
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
    }
#line 4578 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration_list external_declaration  */
#line 159 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4584 "src/bison/grammar.c"
    break;

  case 6: /* external_declaration_list: external_declaration  */
#line 160 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4590 "src/bison/grammar.c"
    break;

  case 9: /* external_declaration: statement  */
#line 165 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4600 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type id ';'  */
#line 172 "src/bison/grammar.y"
                             {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[-1].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-2].pchar));
        if (sym) {
            if (sym->scope) {
                show_error_range((yylsp[-1]), "redeclaration of " BCYN "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            } else if (sym->is_fn) {
                show_error_range((yylsp[-1]), BBLU "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
            } else if (sym->type != decl_type) {
                show_error_range((yylsp[-2]), "conflicting types for " BCYN "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            }
            (yyval.ast) = NULL;
        }
        else {
            symbol_update_type((yyvsp[-1].sym), decl_type);
            (yyval.ast) = ast_declaration_init(
                ast_symref_init(context_declare_variable(current_context, (yyvsp[-1].sym)))
            );
        }
        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 4627 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 194 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4637 "src/bison/grammar.c"
    break;

  case 12: /* var_declaration: type id '=' error  */
#line 199 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4648 "src/bison/grammar.c"
    break;

  case 13: /* var_declaration: id id '=' error  */
#line 205 "src/bison/grammar.y"
                      {
        show_error_range((yylsp[-3]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-3].sym)->name);
        symbol_free((yyvsp[-3].sym));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4659 "src/bison/grammar.c"
    break;

  case 14: /* @1: %empty  */
#line 213 "src/bison/grammar.y"
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
#line 4700 "src/bison/grammar.c"
    break;

  case 15: /* $@2: %empty  */
#line 248 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4706 "src/bison/grammar.c"
    break;

  case 16: /* func_declaration: type id '(' @1 param_list.opt $@2 ')' compound_stmt  */
#line 248 "src/bison/grammar.y"
                                                              {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4716 "src/bison/grammar.c"
    break;

  case 17: /* $@3: %empty  */
#line 253 "src/bison/grammar.y"
               {
        previous_context = current_context;
        list_push(&contexts, context_init("invalid"));
        current_context = list_peek_last(&contexts);
    }
#line 4726 "src/bison/grammar.c"
    break;

  case 18: /* $@4: %empty  */
#line 257 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4732 "src/bison/grammar.c"
    break;

  case 19: /* func_declaration: type '(' $@3 param_list.opt $@4 ')' compound_stmt  */
#line 257 "src/bison/grammar.y"
                                                              {
        show_error_range((yylsp[-5]), "expected identifier before " WHT "'('" RESET "\n");
        free((yyvsp[-6].pchar));
        LIST_FREE((yyvsp[-3].list), { ast_free(__IT__->data); });
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
        current_context = previous_context;
    }
#line 4745 "src/bison/grammar.c"
    break;

  case 20: /* param_list.opt: %empty  */
#line 267 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4751 "src/bison/grammar.c"
    break;

  case 22: /* params_list: params_list ',' param_decl  */
#line 271 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4757 "src/bison/grammar.c"
    break;

  case 23: /* params_list: param_decl  */
#line 272 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4763 "src/bison/grammar.c"
    break;

  case 24: /* params_list: error  */
#line 273 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4772 "src/bison/grammar.c"
    break;

  case 25: /* param_decl: type id  */
#line 279 "src/bison/grammar.y"
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
#line 4789 "src/bison/grammar.c"
    break;

  case 26: /* $@5: %empty  */
#line 293 "src/bison/grammar.y"
                   {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        if (!is_fn_blck) {
            context_push_scope(current_context);
        } else {
            scope_fill(
                list_peek_reverse(&current_context->scopes, 1),
                stack_peek(&previous_context->scopes)
            );
        }
        is_fn_blck = false;
    }
#line 4806 "src/bison/grammar.c"
    break;

  case 27: /* compound_stmt: '{' $@5 block_item_list.opt '}'  */
#line 304 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 4818 "src/bison/grammar.c"
    break;

  case 28: /* block_item_list.opt: block_item_list  */
#line 313 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4824 "src/bison/grammar.c"
    break;

  case 29: /* block_item_list.opt: %empty  */
#line 314 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4830 "src/bison/grammar.c"
    break;

  case 30: /* block_item_list: block_item_list block_item  */
#line 317 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4836 "src/bison/grammar.c"
    break;

  case 31: /* block_item_list: block_item  */
#line 318 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4842 "src/bison/grammar.c"
    break;

  case 40: /* io_stmt: READ '(' id ')' ';'  */
#line 333 "src/bison/grammar.y"
                             {
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].sym));
        if (!param) {
            show_error_range((yylsp[-2]), BCYN "'%s'" RESET " undeclared (first use in this function)\n", (yyvsp[-2].sym)->name);
            (yyval.ast) = NULL;
        } else {
            (yyval.ast) = ast_builtinfn_init((yyvsp[-4].pchar), ast_symref_init(param));
        }
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
    }
#line 4858 "src/bison/grammar.c"
    break;

  case 41: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 344 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_builtinfn_init((yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4867 "src/bison/grammar.c"
    break;

  case 42: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 348 "src/bison/grammar.y"
                                       {
        (yyval.ast) = ast_builtinfn_init((yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4876 "src/bison/grammar.c"
    break;

  case 43: /* io_stmt: WRITE '(' error ')' ';'  */
#line 352 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4886 "src/bison/grammar.c"
    break;

  case 44: /* io_stmt: READ '(' error ')' ';'  */
#line 357 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4896 "src/bison/grammar.c"
    break;

  case 45: /* io_stmt: READ '(' id ')' error  */
#line 362 "src/bison/grammar.y"
                            {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4907 "src/bison/grammar.c"
    break;

  case 46: /* io_stmt: WRITE '(' expression ')' error  */
#line 368 "src/bison/grammar.y"
                                     {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4918 "src/bison/grammar.c"
    break;

  case 47: /* io_stmt: WRITE '(' string_literal ')' error  */
#line 374 "src/bison/grammar.y"
                                         {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4929 "src/bison/grammar.c"
    break;

  case 48: /* expr_stmt: expression ';'  */
#line 382 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 4935 "src/bison/grammar.c"
    break;

  case 49: /* expr_stmt: error ';'  */
#line 383 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 4944 "src/bison/grammar.c"
    break;

  case 50: /* cond_stmt: IF '(' expression ')' statement  */
#line 389 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 4952 "src/bison/grammar.c"
    break;

  case 51: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 392 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4960 "src/bison/grammar.c"
    break;

  case 52: /* cond_stmt: IF '(' expression ')' ELSE  */
#line 395 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4970 "src/bison/grammar.c"
    break;

  case 53: /* cond_stmt: IF '(' error ')' statement  */
#line 400 "src/bison/grammar.y"
                                            {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4980 "src/bison/grammar.c"
    break;

  case 54: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 405 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4991 "src/bison/grammar.c"
    break;

  case 55: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 411 "src/bison/grammar.y"
                                      {
        show_error((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5001 "src/bison/grammar.c"
    break;

  case 56: /* jmp_stmt: RETURN expression ';'  */
#line 418 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 5007 "src/bison/grammar.c"
    break;

  case 57: /* jmp_stmt: RETURN error ';'  */
#line 419 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5016 "src/bison/grammar.c"
    break;

  case 58: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 425 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 5024 "src/bison/grammar.c"
    break;

  case 59: /* iter_stmt: FOR '(' error ';' expression.opt ';' expression.opt ')' statement  */
#line 428 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-6]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5036 "src/bison/grammar.c"
    break;

  case 60: /* iter_stmt: FOR '(' expression.opt ';' error ';' expression.opt ')' statement  */
#line 435 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-4]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5048 "src/bison/grammar.c"
    break;

  case 61: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' error ')' statement  */
#line 442 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5060 "src/bison/grammar.c"
    break;

  case 63: /* expression: unary_expr '=' logical_or_expr  */
#line 452 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 5066 "src/bison/grammar.c"
    break;

  case 64: /* expression: unary_expr '=' error  */
#line 453 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5076 "src/bison/grammar.c"
    break;

  case 65: /* expression: error '=' logical_or_expr  */
#line 458 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-2]), "expected expression before " WHT "'='" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5086 "src/bison/grammar.c"
    break;

  case 66: /* expression.opt: %empty  */
#line 465 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 5092 "src/bison/grammar.c"
    break;

  case 69: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 470 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5101 "src/bison/grammar.c"
    break;

  case 70: /* logical_or_expr: logical_or_expr OR error  */
#line 474 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5111 "src/bison/grammar.c"
    break;

  case 71: /* logical_or_expr: error OR logical_and_expr  */
#line 479 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5121 "src/bison/grammar.c"
    break;

  case 73: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 487 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5130 "src/bison/grammar.c"
    break;

  case 74: /* logical_and_expr: logical_and_expr AND error  */
#line 491 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5140 "src/bison/grammar.c"
    break;

  case 75: /* logical_and_expr: error AND eq_expr  */
#line 496 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5150 "src/bison/grammar.c"
    break;

  case 77: /* eq_expr: eq_expr EQ rel_expr  */
#line 504 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5159 "src/bison/grammar.c"
    break;

  case 78: /* eq_expr: eq_expr EQ error  */
#line 508 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5169 "src/bison/grammar.c"
    break;

  case 79: /* eq_expr: error EQ rel_expr  */
#line 513 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5179 "src/bison/grammar.c"
    break;

  case 81: /* rel_expr: rel_expr REL list_expr  */
#line 521 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5188 "src/bison/grammar.c"
    break;

  case 82: /* rel_expr: rel_expr REL error  */
#line 525 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5198 "src/bison/grammar.c"
    break;

  case 83: /* rel_expr: error REL list_expr  */
#line 530 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5208 "src/bison/grammar.c"
    break;

  case 85: /* list_expr: add_expr DL_DG list_expr  */
#line 538 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5217 "src/bison/grammar.c"
    break;

  case 86: /* list_expr: add_expr COLON list_expr  */
#line 542 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5226 "src/bison/grammar.c"
    break;

  case 87: /* list_expr: add_expr DL_DG error  */
#line 546 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5236 "src/bison/grammar.c"
    break;

  case 88: /* list_expr: add_expr COLON error  */
#line 551 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5246 "src/bison/grammar.c"
    break;

  case 89: /* list_expr: error DL_DG list_expr  */
#line 556 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5256 "src/bison/grammar.c"
    break;

  case 90: /* list_expr: error COLON list_expr  */
#line 561 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5266 "src/bison/grammar.c"
    break;

  case 92: /* add_expr: add_expr ADD mult_expr  */
#line 569 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5275 "src/bison/grammar.c"
    break;

  case 93: /* add_expr: add_expr ADD error  */
#line 573 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5285 "src/bison/grammar.c"
    break;

  case 94: /* add_expr: error ADD mult_expr  */
#line 578 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5295 "src/bison/grammar.c"
    break;

  case 96: /* mult_expr: mult_expr MULT unary_expr  */
#line 586 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5304 "src/bison/grammar.c"
    break;

  case 97: /* mult_expr: mult_expr MULT error  */
#line 590 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5314 "src/bison/grammar.c"
    break;

  case 98: /* mult_expr: error MULT unary_expr  */
#line 595 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5324 "src/bison/grammar.c"
    break;

  case 100: /* unary_expr: unary_ops unary_expr  */
#line 603 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5333 "src/bison/grammar.c"
    break;

  case 106: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 616 "src/bison/grammar.y"
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
#line 5356 "src/bison/grammar.c"
    break;

  case 107: /* arg_expr_list: arg_expr_list ',' expression  */
#line 636 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5362 "src/bison/grammar.c"
    break;

  case 108: /* arg_expr_list: expression  */
#line 637 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5368 "src/bison/grammar.c"
    break;

  case 109: /* arg_expr_list: error  */
#line 638 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5377 "src/bison/grammar.c"
    break;

  case 111: /* arg_expr_list.opt: %empty  */
#line 645 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5383 "src/bison/grammar.c"
    break;

  case 112: /* primary_expr: id  */
#line 648 "src/bison/grammar.y"
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
#line 5398 "src/bison/grammar.c"
    break;

  case 114: /* primary_expr: '(' expression ')'  */
#line 659 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 5404 "src/bison/grammar.c"
    break;

  case 115: /* primary_expr: '(' error ')'  */
#line 660 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5413 "src/bison/grammar.c"
    break;

  case 116: /* primary_expr: id error  */
#line 664 "src/bison/grammar.y"
               {
        show_error_range((yylsp[0]), "expected " WHT "';'" RESET "\n");
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 5423 "src/bison/grammar.c"
    break;

  case 120: /* type: INT LIST  */
#line 676 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5435 "src/bison/grammar.c"
    break;

  case 121: /* type: FLOAT LIST  */
#line 683 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5447 "src/bison/grammar.c"
    break;

  case 122: /* constant: NUMBER_REAL  */
#line 692 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5453 "src/bison/grammar.c"
    break;

  case 123: /* constant: NUMBER_INT  */
#line 693 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5459 "src/bison/grammar.c"
    break;

  case 124: /* constant: NIL  */
#line 694 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5465 "src/bison/grammar.c"
    break;

  case 125: /* string_literal: STR_LITERAL  */
#line 697 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5474 "src/bison/grammar.c"
    break;


#line 5478 "src/bison/grammar.c"

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

#line 703 "src/bison/grammar.y"


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
