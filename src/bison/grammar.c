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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   10489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  668

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
       0,   150,   150,   151,   152,   158,   159,   162,   163,   164,
     171,   193,   198,   206,   241,   206,   246,   250,   246,   260,
     261,   264,   265,   266,   272,   286,   286,   299,   300,   303,
     304,   307,   308,   311,   312,   313,   314,   315,   316,   319,
     330,   334,   338,   343,   348,   354,   360,   368,   371,   374,
     377,   382,   387,   393,   400,   401,   407,   410,   417,   424,
     433,   434,   435,   442,   443,   446,   447,   451,   456,   463,
     464,   468,   473,   480,   481,   485,   490,   497,   498,   502,
     507,   514,   515,   519,   523,   528,   533,   538,   545,   546,
     550,   555,   562,   563,   567,   572,   579,   580,   586,   587,
     588,   589,   592,   593,   613,   614,   615,   621,   622,   625,
     635,   636,   637,   643,   646,   647,   648,   655,   664,   665,
     666,   669
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

#define YYPACT_NINF (-361)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-122)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    5617, 10467,  9909,  9921,  9933,  9859,   538,   947,  1334,  3139,
      89,   109,   -10,    24,    34,    40,  2748,  2952,  5649,    75,
    5685,  5717,  5749,  5781,  5813,  5845,  5877,  5909,  5941,  5973,
    6005,    92,   102,   405,   787,   673,   716,   870,  3844,  9945,
    3161,  9957,  9969,  9871,    78,  9981,  3702,  3005,  3023,  3054,
    3091,  3292,  3023,  3023,   113,   135,     4,   191,  3396,   344,
   10041,    94,   594,   140,  6037,  -361,  4061,  6073,  6105,  3434,
    3625,  3696,  3784,  3833,  3911,  4030,  4114,  4218,  9993,    21,
    6137,    13,   310, 10053,   156, 10064, 10076,   862,   762,  3304,
     900,  1932,   548,  1241,   970,  1013,  1262,   152,   161,  1206,
     168,   192,   201,  4163,   213, 10087,   184,   214,  6169,  6201,
   10005, 10017,  6233,   212,  6268,  6303,  6338,    25, 10099,   664,
   10110,  1027, 10122,  1504, 10133,  1634, 10145, 10156, 10168,  1720,
   10179,  1753, 10191, 10202, 10214,   116,  1159,   119,   237,   218,
      41,  6374,   295,    97,   280,     5,   297,     6,    10,  1130,
    1236,  1680,  1719,  6406,  6438,   252,  4293, 10029,   253,   300,
     331,   347,   330,  6474,    41,  6506,  6538,  6570,  6602,  6634,
    6666,  6698,  6730,   131,    77,  6762,   455,   314, 10225,   317,
     379,   319,   257,   421,   321,  6794,   131,   131,   296,   296,
     624,   340,   469,   371,  6826,  6858,   382,   397,  4231,   400,
    6890,   340,   131,   131,   131,   131,  6922,  6954,  6986,  7018,
    7050,  9183,  9195,  9209,  2404,  4395,    -2,   425,   255,   159,
     216,   166,  9339,  9221,  3874,  9235,  9247,  9169,  9261,   393,
   10237, 10248, 10260,  9884,  4447,  3702, 10271, 10283,  9896, 10294,
     418,  4287,  4504,  4568,  8097,  8103,  8121,  4568,  4568,   404,
     528,   433,   438,   442,   452,  8138,  5649,  7082,  7117,  7152,
    7187,  7222,  7257,   458,  2059,  3559,  4658,   388,  8155,   305,
     150,   251,   242,   551,  9350,  8832,  8710,  8682,  8724,  8737,
     659,  8751,   499,  7292,  8699,  8172,  8189,  8206,  8223,  8240,
    8189,  8189,   208,   250,   460,   465,   467,   478,  8257,  5649,
     761,   915,   986,  1028,  1466,  1503,   486,  7327,   518,  4338,
     503, 10475,   494,  9365,   501,  8274,  8291,  8308,  8325,  8342,
    8359,  8376,  8393,  8410,  9273,    21,  9377,   516, 10306,    21,
    9391,  9403,  9417,   583,  8427,  9429,  4287,  9443,  9455,  9287,
    9469,   524,  9481,  9495,   953,   312,  3447,   396,  2068,   430,
    1360,   456,   626,   706,    60,    99,    66,   302,  8444,  1882,
   10317,   523,  6037,  7362,  9507,   534,  8461,  8478,  8495,  8512,
    8529,  8546,  8563,  8580,  8597,  8764,    21,  8845,  8859,  8872,
    3981,  8614,  8886,  8699,  8899,  8913,  8778,  8926,   560,  8940,
    8953,  1114,   800,  3610,   282,  2168,   247,  1594,   827,  1091,
    1214,   562,   566,    68,   489,  8631,  2156, 10329,   569,  6037,
    1545,  7397,  9299,  9313,  9521,   599,  9533,   513,  9547,   815,
    9559,   961,  9573,  9585,  9599,  1369,  9611,  1467,  9625,  9637,
    9651,   101,   579, 10340, 10352,   602,  9663,   611,  9677,    21,
     612,   613,  9689,   614,   615,  9703,   616, 10363,   625,  7432,
    7467,   643,  8791,  8805,  8967,   355,  8980,   359,  8994,  1417,
    9007,  1580,  9021,  9034,  9048,  1706,  9061,  1760,  9075,  9088,
    9102,   345,   647,  9715,   654,  9115,    21,   655,   656,  9729,
     665,   669,  9741,   679, 10375,   667,  1810,  1848,   677,  9325,
   10386,  9755,  9767,   688,   692,    12,   694,    14,    17,  1289,
    1633,  1680,  2265,  7502,  8818,  9129,  9142,   701,   695,    18,
     705,    27,    39,  1904,  2231,  1680,  2368,  2191,  9781,  7537,
    7572,  7607,  7642,  7677,  7712,  7747,  7782,   710,   719,   720,
     215,   721,  8648,  5649,  2498,  2533,  2574,  2839,  2876,  2917,
    3182,   726,  7817,  3219,   727, 10398,   734,  9156,  3260,  3350,
    3491,  3526,  3582,  4077,  4181,  4355,  1178,  4415,  4466,  4536,
     739, 10409,   741,   211,  2024,  8665,  7852,  2610, 10421,   746,
    6037,   215,  4588,   215,   296,   296,  1064,  4624,  1178,  1178,
     296,   296,  1388,   747,   750,  9793,   757,   758,  9807,   769,
   10432,   777,  4681,  4722,   772,  7887,  7922,   776,   781,  9819,
     783,  4758,  4790,   785,   788,  9833,   789,   799,    47,   811,
      61,    62,  2319,  2662,  1680,  2711,  4822,   215,   215,   215,
     215,  1178,  1178,  1178,  1178,  4857,  4892,  4927,  4962,  4997,
    5032,  5067,  5102,  1976,  5137,  5172,  5207,   816, 10444,   817,
    7957,  7992,  8027,  8062,  5243,  5275,  5307,  5339,  5371,  1976,
    1976,   296,   296,  1579,  5406,  5441,   797,   818,  9845,   819,
    1976,  1976,  1976,  1976,  5476,  5511,  5546,  5581
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
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
    -361,  -361,  -361,   834,    50,  -361,  -361,  -361,  -361,  -361,
     691,  -361,   676,   181,  -255,  -360,  -361,   760,    86,   240,
     244,   335,   527,   722,     0,   -64,  1845,  4099,  3949,  3686,
    3100,  3579,  3405,  1385,  1728,  2071,  -361,  -317,  2414,  1041,
       3,  2757,  -353
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   112,    23,   164,   193,   140,   181,
     159,   160,   161,   257,    64,   113,   114,   115,   116,   258,
     259,   260,   261,   262,   106,   107,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   138,   139,    42,    43,
     117,    45,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   362,   451,    44,   444,    97,   166,   169,   432,   315,
     240,   171,   435,   520,   -16,   523,    61,    63,   525,   549,
      31,    56,   136,    44,   264,   265,   266,   267,   552,     6,
     -60,   282,   -16,   -16,   167,   170,     7,     8,     9,   172,
     554,   521,   158,   524,   409,   -16,   526,   550,   626,   488,
      22,   481,   268,  -108,   283,    57,   553,   101,   104,   472,
     292,   293,   629,   631,   263,    58,  -116,   440,   555,   477,
      22,    59,   240,   -19,   240,    65,   627,   -51,   -51,   137,
     -51,   -51,   -51,   -51,   229,   -51,    25,   177,   179,  -116,
     630,   632,   -51,   -51,   -51,  -114,   -51,   -51,   -13,   -51,
     -51,   -51,   186,   -51,   -51,  -117,    25,    80,   -51,    81,
      54,   -51,   315,    69,   263,  -115,   -13,   -13,  -114,  -116,
    -114,    68,   493,   109,   196,   197,   199,    69,  -117,   -13,
      55,   -60,    66,   -61,     2,     3,     4,     5,  -115,     6,
    -115,  -117,  -116,   162,  -116,   -61,     7,     8,     9,   306,
     306,  -105,  -105,    12,    13,    14,   180,    15,    16,   507,
     367,   -65,    17,    46,  -117,    18,  -117,   162,   318,   -73,
     -73,   -73,   111,    31,   319,   -81,   -81,   -81,   -81,   320,
     321,    24,   -65,   -65,   144,   162,    31,    31,   312,   312,
     312,   -73,    99,   145,   211,   212,   213,   214,   -81,     6,
    -121,    24,    31,    31,    31,    31,     7,     8,     9,   100,
     594,   587,   583,   -64,  -114,   314,    66,   240,     2,     3,
       4,     5,   215,     6,   147,   -77,   -77,   -77,   -77,   401,
       7,     8,     9,   148,   327,   174,   176,   251,   252,   253,
      26,   254,   255,   152,    27,   150,    17,   153,   -77,   256,
     157,   369,   -73,   -73,   -73,   361,  -115,   367,   -68,   185,
      26,   -69,   -69,   368,    27,   -69,   -69,   317,   365,  -107,
     156,   402,   194,   195,   -73,   -73,   292,   293,   570,   -68,
     -68,   307,   308,   -69,   -69,   -23,   -23,   -69,   207,   208,
     209,   210,   -72,   -72,   368,   448,   163,   311,   408,   211,
     212,   213,   214,   442,     6,   211,   212,   213,   214,   165,
       6,     7,     8,     9,   -72,   -72,   366,     7,     8,     9,
     100,   -80,   -80,   -80,   -80,   137,   168,   215,   -63,   137,
     300,   300,   -17,   215,   437,    28,   310,   -60,   -60,   141,
     142,   143,   485,   188,   -80,   105,   190,     2,     3,     4,
       5,   191,     6,   -14,    24,    28,   366,   443,   446,     7,
       8,     9,   263,   -20,   182,   367,   -66,    24,    24,   -70,
     -70,   368,   200,   -63,    18,    17,   137,   -61,   -61,   -22,
     -22,   474,   206,    24,    24,    24,    24,   -66,   -66,   301,
     301,   -70,   -70,   302,   302,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,   201,   480,   483,   -72,   -72,   317,   263,
    -114,  -104,  -104,    26,   202,    70,   -65,    27,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,   354,    26,    26,   -72,   203,
      27,    27,   205,  -114,   -65,   316,   -65,   544,   546,   137,
     316,   -68,    26,    26,    26,    26,    27,    27,    27,    27,
    -113,   560,   562,   -24,   -24,   -48,   -48,   -65,   -48,   -48,
     -48,   -48,   -68,   -48,   356,   318,   -76,   -76,   -76,   357,
     -48,   -48,   -48,   358,   -48,   -48,   137,   -48,   -48,   -48,
     187,   -48,   -48,   359,   303,   303,   -48,   363,   -76,   -48,
     479,   403,   211,   212,   213,   214,   404,     6,   405,   541,
     541,   -21,   -21,   591,     7,     8,     9,   100,    28,   406,
     597,   598,   600,   306,   306,   410,   603,   604,   606,   411,
     215,    28,    28,   -70,   -70,   317,   -64,    29,  -113,  -113,
     263,   241,   569,   413,  -115,  -113,  -113,    28,    28,    28,
      28,  -100,  -100,  -100,  -100,   -70,  -100,    29,   434,   355,
     637,   639,   450,  -100,  -100,  -100,   306,  -115,    70,   -68,
     -77,   -77,   -77,   -77,   586,   589,   453,   284,  -116,  -100,
     263,   263,  -117,   263,   312,   312,   312,   -68,   306,   306,
     312,   312,   312,   -77,   -77,   535,   543,   656,   657,   659,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,   487,   557,
     559,   241,   242,   243,   244,   245,   246,   247,   248,   316,
     -66,   489,   541,   541,  -113,  -113,   566,   263,   263,   263,
     263,   306,   306,   306,   306,   198,   110,   211,   212,   213,
     214,   -66,     6,   541,   490,   -87,   -87,   -87,   -87,     7,
       8,     9,   577,   492,   494,   495,   497,   498,   500,   541,
     541,   312,   312,   312,   502,   215,   -63,   595,   -87,   596,
     541,   541,   541,   541,   601,   602,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,    70,   -66,   304,   304,   503,   504,
     534,   534,    72,   -73,   -73,   -73,   506,   508,   509,  -109,
     376,  -109,  -109,   -66,   300,   300,   516,   511,   634,   636,
      29,   512,   -73,   640,   641,   642,   643,   644,   645,   646,
     647,   514,   517,    29,    29,   -86,   -86,   -86,   -86,   648,
     518,   519,    30,   522,   548,   -77,   -77,   -77,   -77,    29,
      29,    29,    29,   547,   551,   654,   655,   300,   -86,   536,
     536,   563,    30,   537,   537,   -77,   664,   665,   666,   667,
     564,   565,   567,   301,   301,   572,   574,   302,   302,   300,
     300,   -34,   -34,   576,   -34,   -34,   -34,   -34,   580,   -34,
     582,   -80,   -80,   -80,   -80,   593,   -34,   -34,   -34,   607,
     -34,   -34,   608,   -34,   -34,   -34,   -34,   -34,   -34,   610,
     611,   -80,   -34,   534,   534,   -34,   301,   -69,   -69,    71,
     302,   613,   300,   300,   300,   300,   615,   616,   617,   -80,
     -80,   -80,   -80,   618,   534,   620,   -69,   621,   301,   301,
     622,   624,   302,   302,   318,   -74,   -74,   -74,   625,   660,
     534,   534,   -80,   -80,   538,   538,   369,   -76,   -76,   -76,
     628,   534,   534,   534,   534,   651,   653,   -74,   303,   303,
     661,   663,   536,   536,    67,   184,   537,   537,   192,   -76,
     -76,   301,   301,   301,   301,   302,   302,   302,   302,    46,
      47,   305,   305,   536,   154,    52,    53,   537,    73,   -81,
     -81,   -81,   -81,    74,    75,     0,     0,     0,     0,   536,
     536,   303,     0,   537,   537,    30,     0,     0,     0,   -81,
     536,   536,   536,   536,   537,   537,   537,   537,    30,    30,
     -72,   -72,    71,   303,   303,   -38,   -38,     0,   -38,   -38,
     -38,   -38,     0,   -38,    30,    30,    30,    30,     0,   -72,
     -38,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,     0,     0,   -38,   538,   538,   -38,
     -98,   -98,   -98,   -98,     0,   -98,   303,   303,   303,   303,
     241,   242,   -98,   -98,   -98,     0,   247,   248,   538,     0,
     -78,   -78,   -78,   -78,     0,     0,     0,     0,   -98,    72,
     -76,   -76,   -76,     0,   538,   538,   -33,   -33,     0,   -33,
     -33,   -33,   -33,   -78,   -33,   538,   538,   538,   538,   -76,
       0,   -33,   -33,   -33,     0,   -33,   -33,     0,   -33,   -33,
     -33,   -33,   -33,   -33,     0,     0,     0,   -33,     0,     0,
     -33,     0,   -87,   -87,   -87,   -87,   539,   539,   -35,   -35,
       0,   -35,   -35,   -35,   -35,     0,   -35,   -70,   -70,    71,
     304,   304,   -87,   -35,   -35,   -35,     0,   -35,   -35,     0,
     -35,   -35,   -35,   -35,   -35,   -35,   -70,     0,   227,   -35,
       0,     0,   -35,     0,     0,   599,     0,   211,   212,   213,
     214,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,   304,     0,    82,     0,   238,   238,   238,
     238,   238,   238,   238,   238,   215,   -63,    98,   227,   227,
     -87,   -87,   -87,   -87,     0,   304,   304,     0,     0,     0,
     238,   238,   238,   238,   238,   238,   238,   238,   238,     0,
     280,   284,   285,   -87,   -87,     0,     0,   290,   291,     0,
       0,    66,     0,     2,     3,     4,     5,     0,     6,   539,
     539,     0,     0,     0,     0,     7,     8,     9,   304,   304,
     304,   304,   294,   295,   296,   173,   297,   298,   155,     0,
     539,    17,     0,     0,   299,     0,   284,   285,   286,   287,
     288,   289,   290,   291,     0,     0,   539,   539,     0,    66,
       0,     2,     3,     4,     5,     0,     6,   539,   539,   539,
     539,  -106,  -106,     7,     8,     9,     0,   280,     0,     0,
     294,   295,   296,   183,   297,   298,     0,     0,     0,    17,
       0,     0,   299,   241,   242,   243,   244,   245,   246,   247,
     248,   540,   540,   -86,   -86,   -86,   -86,     0,     0,   227,
     227,   227,     0,     0,     0,   305,   305,    66,   146,     2,
       3,     4,     5,     0,     6,     0,   -86,   -86,    46,    47,
      48,     7,     8,     9,    52,    53,   227,     0,   294,   295,
     296,   175,   297,   298,     0,   227,     0,    17,     0,     0,
     299,   -86,   -86,   -86,   -86,   227,   238,     0,   305,     0,
       0,     0,   339,   339,   339,   339,   339,   339,   339,   339,
      66,   -86,     2,     3,     4,     5,     0,     6,     0,     0,
     305,   305,     0,     0,     7,     8,     9,     0,     0,   227,
       0,   527,   528,   529,   530,   531,   532,     0,   280,     0,
      17,     0,     0,   533,     0,   386,   386,   386,   386,   386,
     386,   386,   386,     0,   540,   540,     0,   -99,   -99,   -99,
     -99,     0,   -99,   305,   305,   305,   305,     0,     0,   -99,
     -99,   -99,     0,     0,     0,   540,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   -99,   280,   241,   242,   243,
     280,   540,   540,   247,   248,   227,     0,   339,   -83,   -83,
     -83,   -83,   540,   540,   540,   540,     0,     0,     0,   605,
       0,   211,   212,   213,   214,     0,     6,   441,   227,   227,
       0,   -83,   223,     7,     8,     9,     0,   386,   386,   386,
     386,   386,   386,   386,   386,   386,     0,   280,     0,   215,
     -63,     0,   227,     0,   386,    78,   369,   -74,   -74,   -74,
       0,    83,    86,    86,    86,    86,    86,    86,    86,     0,
       0,     0,   223,   223,   478,   227,   227,     0,     0,   -74,
     -74,     0,     0,     0,    86,    86,    86,    86,    86,    86,
      86,   133,    86,     0,   276,     0,   -36,   -36,     0,   -36,
     -36,   -36,   -36,     0,   -36,     0,   -82,   -82,   -82,   -82,
     280,   -36,   -36,   -36,     0,   -36,   -36,     0,   -36,   -36,
     -36,   -36,   -36,   -36,     0,     0,     0,   -36,     0,   -82,
     -36,     0,     0,   -37,   -37,     0,   -37,   -37,   -37,   -37,
       0,   -37,     0,    72,   -74,   -74,   -74,   280,   -37,   -37,
     -37,     0,   -37,   -37,     0,   -37,   -37,   -37,   -37,   -37,
     -37,     0,     0,   -74,   -37,     0,     0,   -37,     0,     0,
       0,   276,     0,     0,     0,   -47,   -47,     0,   -47,   -47,
     -47,   -47,     0,   -47,     0,     0,     0,     0,     0,     0,
     -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,
     -47,   -47,   -47,   223,   223,   223,   -47,     0,     0,   -47,
     658,     0,   211,   212,   213,   214,     0,     6,     0,   -78,
     -78,   -78,   -78,     0,     7,     8,     9,     0,     0,     0,
     223,   284,   285,   286,   584,   227,   227,   290,   291,   324,
     215,   -63,   -78,   -78,     0,   227,   227,   227,     0,   223,
     328,   227,   227,   227,     0,     0,   335,   343,   343,   343,
     343,   343,   343,   343,    66,     0,     2,     3,     4,     5,
       0,     6,     0,   -78,   -78,   -78,   -78,     0,     7,     8,
       9,     0,     0,   223,     0,   527,   528,   529,   542,   531,
     532,     0,   375,   -78,    17,     0,     0,   533,     0,   382,
     390,   390,   390,   390,   390,   390,   390,     0,     0,     0,
       0,    66,     0,     2,     3,     4,     5,     0,     6,     0,
       0,     0,   227,   227,   227,     7,     8,     9,     0,     0,
     343,   343,   343,   343,   343,   343,   343,   429,   343,   -63,
     276,    17,     0,     0,   276,   -83,   -83,   -83,   -83,   223,
     178,   438,     2,     3,     4,     5,     0,     6,     0,   -83,
     -83,   -83,   -83,     0,     7,     8,     9,     0,   -83,   -83,
       0,     0,   223,   223,     0,   224,     0,     0,   -63,   -83,
      17,   390,   390,   390,   390,   390,   390,   390,   469,   390,
       0,   276,   -82,   -82,   -82,   -82,   223,     0,   475,   -82,
     -82,   -82,   -82,     0,   235,   235,   235,   235,   235,   235,
     235,   235,   -82,     0,     0,   224,   224,     0,     0,   223,
     223,     0,   -82,   -82,     0,     0,     0,   235,   235,   235,
     235,   235,   235,   235,   235,   235,     0,   277,     0,     0,
     -55,   -55,     0,   -55,   -55,   -55,   -55,     0,   -55,     0,
       0,     0,     0,     0,   276,   -55,   -55,   -55,     0,   -55,
     -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   -55,     0,     0,   -55,     0,     0,     0,   -54,   -54,
       0,   -54,   -54,   -54,   -54,     0,   -54,     0,     0,     0,
       0,   276,   216,   -54,   -54,   -54,     0,   -54,   -54,     0,
     -54,   -54,   -54,   -54,   -54,   -54,     0,     0,     0,   -54,
       0,     0,   -54,   447,   277,     2,     3,     4,     5,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,   216,   216,     0,    66,     0,     2,     3,     4,
       5,   -63,     6,    17,     0,     0,   224,   224,   224,     7,
       8,     9,   135,     0,   269,     0,   294,   295,   296,   556,
     297,   298,     0,     0,     0,    17,     0,     0,   299,    46,
      47,    48,    49,   224,    51,    52,    53,     0,     0,   223,
     223,     0,   224,     0,     0,     0,     0,     0,     0,   223,
     223,   223,   224,   235,     0,   223,   223,   223,     0,   336,
     336,   336,   336,   336,   336,   336,   336,    66,     0,     2,
       3,     4,     5,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,     0,   224,     0,   527,   528,
     529,   269,   531,   532,     0,   277,     0,    17,     0,     0,
     533,     0,   383,   383,   383,   383,   383,   383,   383,   383,
       0,     0,     0,     0,     0,   585,     0,   211,   212,   213,
     214,     0,     6,   216,   216,   216,   223,   223,   223,     7,
       8,     9,   100,   336,   336,   336,   336,   336,   336,   336,
     336,   336,     0,   277,     0,   215,     0,   277,     0,     0,
     216,     0,   224,     0,   336,     0,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,     0,   241,   242,   243,   244,   216,
     246,   247,   248,     0,     0,   224,   224,     0,   225,  -119,
       0,  -119,  -119,     0,   383,   383,   383,   383,   383,   383,
     383,   383,   383,     0,   277,     0,     0,     0,     0,   224,
       0,   383,     0,   216,     0,     0,     0,   236,   236,   236,
     236,   236,   236,   236,   236,     0,     0,     0,   225,   225,
       0,     0,   224,   224,     0,     0,     0,     0,     0,     0,
     236,   236,   236,   236,   236,   236,   236,   236,   236,     0,
     278,     0,     0,     0,     0,     0,     0,   484,     0,     2,
       3,     4,     5,     0,     6,     0,     0,   277,   431,     0,
     269,     7,     8,     9,   269,   284,   285,   286,   287,   216,
     289,   290,   291,     0,     0,   -63,     0,    17,     0,     0,
       0,   -26,   -26,     0,   -26,   -26,   -26,   -26,     0,   -26,
       0,     0,   216,   216,   277,     0,   -26,   -26,   -26,     0,
     -26,   -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,   471,
       0,   269,   -26,     0,     0,   -26,   216,   278,     0,     0,
       0,     0,    66,     0,     2,     3,     4,     5,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,   216,
     216,     0,     0,   294,   295,   296,   558,   297,   298,   225,
     225,   225,    17,     0,     0,   299,   545,     0,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,   269,     0,   225,     0,     0,     0,
       0,     0,   224,   224,   -63,   225,    17,     0,     0,     0,
       0,     0,   224,   224,   224,   225,   236,     0,   224,   224,
     224,     0,   337,   337,   337,   337,   337,   337,   337,   337,
      66,   269,     2,     3,     4,     5,     0,     6,     0,     0,
       0,     0,     0,     0,     7,     8,     9,     0,     0,   225,
       0,   527,   528,   529,   633,   531,   532,     0,   278,     0,
      17,     0,     0,   533,     0,   384,   384,   384,   384,   384,
     384,   384,   384,     0,     0,     0,     0,     0,     0,   561,
       0,     2,     3,     4,     5,     0,     6,     0,     0,   224,
     224,   224,     0,     7,     8,     9,   337,   337,   337,   337,
     337,   337,   337,   337,   337,     0,   278,   -63,     0,    17,
     278,     0,     0,     0,     0,   225,     0,   337,     0,   216,
     216,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,   216,
     216,   216,     0,     0,     0,   216,   216,   216,   225,   225,
       0,   226,     0,     0,  -113,  -113,  -113,   384,   384,   384,
     384,   384,   384,   384,   384,   384,     0,   278,     0,     0,
       0,     0,   225,     0,   384,     0,     0,     0,     0,     0,
     237,   237,   237,   237,   237,   237,   237,   237,     0,     0,
       0,   226,   226,     0,     0,   225,   225,     0,     0,     0,
       0,     0,     0,   237,   237,   237,   237,   237,   237,   237,
     237,   237,     0,   279,     0,     0,   216,   216,   216,   -34,
       0,   -34,   -34,   -34,   -34,     0,   -34,     0,     0,     0,
     278,     0,     0,   -34,   -34,   -34,     0,   -34,   -34,     0,
     -34,   -34,   -34,   -34,   -34,   -34,     0,     0,     0,   -34,
       0,     0,   -34,   -34,   -51,     0,   -51,   -51,   -51,   -51,
       0,   -51,     0,     0,     0,     0,     0,   278,   -51,   -51,
     -51,     0,   -51,   -51,     0,   -51,   -51,   -51,   571,   -51,
     -51,     0,     0,     0,   -51,     0,     0,   -51,   -51,     0,
     279,     0,     0,     0,     0,   -38,     0,   -38,   -38,   -38,
     -38,     0,   -38,     0,     0,     0,     0,     0,     0,   -38,
     -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,   -38,
     -38,   -38,   226,   226,   226,   -38,     0,     0,   -38,   -38,
       0,   590,     0,     2,     3,     4,     5,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,   226,
       0,     0,     0,     0,     0,   225,   225,     0,   226,   -63,
       0,    17,     0,     0,     0,   225,   225,   225,   226,   237,
       0,   225,   225,   225,     0,   338,   338,   338,   338,   338,
     338,   338,   338,    66,     0,     2,     3,     4,     5,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,   226,     0,   527,   528,   529,   635,   531,   532,
       0,   279,     0,    17,     0,     0,   533,     0,   385,   385,
     385,   385,   385,   385,   385,   385,     0,     0,     0,     0,
       0,     0,   638,     0,     2,     3,     4,     5,     0,     6,
       0,     0,   225,   225,   225,     0,     7,     8,     9,   338,
     338,   338,   338,   338,   338,   338,   338,   338,     0,   279,
     -63,     0,    17,   279,     0,     0,     0,     0,   226,    60,
     338,     2,     3,     4,     5,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
       0,   226,   226,     0,   228,     0,     0,     0,     0,    17,
     385,   385,   385,   385,   385,   385,   385,   385,   385,     0,
     279,     0,     0,     0,     0,   226,     0,   385,     0,     0,
       0,     0,     0,   239,   239,   239,   239,   239,   239,   239,
     239,     0,     0,     0,   228,   228,     0,     0,   226,   226,
       0,     0,     0,     0,     0,     0,   239,   239,   239,   239,
     239,   239,   239,   239,   239,     0,   281,     0,     0,     0,
     -33,     0,   -33,   -33,   -33,   -33,     0,   -33,     0,     0,
       0,     0,     0,   279,   -33,   -33,   -33,     0,   -33,   -33,
       0,   -33,   -33,   -33,   -33,   -33,   -33,     0,     0,     0,
     -33,     0,     0,   -33,   -33,     0,     0,   -35,     0,   -35,
     -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,     0,
     279,   -35,   -35,   -35,     0,   -35,   -35,     0,   -35,   -35,
     -35,   -35,   -35,   -35,     0,     0,     0,   -35,     0,     0,
     -35,   -35,     0,   281,     0,     0,     0,     0,   -36,     0,
     -36,   -36,   -36,   -36,     0,   -36,     0,     0,     0,     0,
       0,     0,   -36,   -36,   -36,     0,   -36,   -36,     0,   -36,
     -36,   -36,   -36,   -36,   -36,   228,   228,   228,   -36,     0,
       0,   -36,   -36,    62,     0,   211,   212,   213,   214,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,   228,     0,     0,     0,     0,     0,   226,   226,
       0,   228,     0,   215,     0,     0,     0,     0,   226,   226,
     226,   228,   239,     0,   226,   226,   226,     0,   340,   340,
     340,   340,   340,   340,   340,   340,    84,     0,   230,   231,
     232,   233,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,    87,   228,   230,   231,   232,   233,
       0,     6,     0,     0,   281,     0,   234,     0,     7,     8,
       9,   387,   387,   387,   387,   387,   387,   387,   387,     0,
       0,     0,     0,     0,   234,    89,     0,   230,   231,   232,
     233,     0,     6,     0,     0,   226,   226,   226,     0,     7,
       8,     9,   340,   340,   340,   340,   340,   340,   340,   340,
     340,     0,   281,     0,     0,   234,   281,     0,     0,     0,
       0,   228,    91,   340,   230,   231,   232,   233,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,     0,     0,     0,   228,   228,     0,   220,     0,     0,
       0,     0,   234,   387,   387,   387,   387,   387,   387,   387,
     387,   387,     0,   281,     0,     0,     0,     0,   228,     0,
     387,     0,  -101,  -101,  -101,  -101,     0,  -101,    88,     0,
       0,     0,    95,    96,  -101,  -101,  -101,   220,   220,     0,
       0,   228,   228,     0,     2,     3,     4,     5,     0,     6,
    -101,     0,   125,     0,   129,   131,     7,     8,     9,   273,
       0,     0,     0,   -37,     0,   -37,   -37,   -37,   -37,     0,
     -37,     0,    17,     0,     0,     0,   281,   -37,   -37,   -37,
       0,   -37,   -37,     0,   -37,   -37,   -37,   -37,   -37,   -37,
       0,     0,     0,   -37,     0,     0,   -37,   -37,     0,     0,
     -48,     0,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,
       0,     0,     0,   281,   -48,   -48,   -48,     0,   -48,   -48,
       0,   -48,   -48,   -48,   573,   -48,   -48,     0,     0,     0,
     -48,     0,     0,   -48,   -48,     0,   273,     0,     0,     0,
     -43,   -43,     0,   -43,   -43,   -43,   -43,     0,   -43,     0,
       0,     0,     0,     0,     0,   -43,   -43,   -43,     0,   -43,
     -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,   220,   220,
     220,   -43,     0,    93,   -43,   230,   231,   232,   233,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,    46,    47,    48,     0,   220,    51,    52,    53,     0,
       0,   228,   228,   234,     0,     0,     0,     0,     0,     0,
       0,   228,   228,   228,   220,     0,     0,   228,   228,   228,
       0,     0,     0,   345,   220,   220,   220,   352,   353,     0,
     -44,   -44,     0,   -44,   -44,   -44,   -44,     0,   -44,     0,
       0,     0,     0,     0,     0,   -44,   -44,   -44,   220,   -44,
     -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,
       0,   -44,     0,     0,   -44,     0,   392,   273,   273,   273,
     399,   400,     0,     0,     0,     0,     0,   103,     0,   211,
     212,   213,   214,     0,     6,     0,     0,     0,   228,   228,
     228,     7,     8,     9,     0,   220,   220,   220,   421,     0,
     425,   427,   222,   220,     0,   273,     0,   215,     0,   273,
       0,     0,     0,     0,   220,   118,     0,   230,   231,   232,
     233,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,    85,     0,   241,   242,   243,   220,   220,   246,
     247,   248,   222,   222,     0,   234,   273,   273,   273,   461,
       0,   465,   467,     0,   273,     0,   273,     0,   127,     0,
       0,   220,     0,     0,   275,     0,     0,     0,     0,     0,
       0,   -39,   -39,     0,   -39,   -39,   -39,   -39,     0,   -39,
       0,     0,     0,     0,   220,   220,   -39,   -39,   -39,     0,
     -39,   -39,     0,   -39,   -39,   -39,   -39,   -39,   -39,     0,
       0,     0,   -39,     0,     0,   -39,   -42,   -42,     0,   -42,
     -42,   -42,   -42,     0,   -42,     0,     0,     0,     0,   273,
       0,   -42,   -42,   -42,     0,   -42,   -42,     0,   -42,   -42,
     -42,   -42,   -42,   -42,     0,     0,     0,   -42,     0,     0,
     -42,   275,     0,     0,     0,     0,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,     0,     0,   273,     0,     0,     0,
       0,     0,   -45,   -45,     0,   -45,   -45,   -45,   -45,  -120,
     -45,  -120,  -120,   222,   222,   222,   221,   -45,   -45,   -45,
       0,   -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,
       0,     0,     0,   -45,     0,     0,   -45,   284,   285,   286,
     222,     0,   289,   290,   291,     0,   120,     0,   230,   231,
     232,   233,     0,     6,     0,     0,   221,   221,     0,   222,
       7,     8,     9,     0,     0,     0,     0,   342,   222,   222,
     222,   222,   222,   222,     0,     0,   234,     0,   274,     0,
       0,     0,     0,     0,   220,   220,     0,     0,     0,     0,
       0,     0,     0,   222,   220,   220,   220,     0,     0,     0,
     220,   220,   220,     0,     0,     0,     0,     0,     0,     0,
     389,   275,   275,   275,   275,   275,   275,   122,     0,   230,
     231,   232,   233,   219,     6,   230,   231,   232,   233,     0,
       6,     7,     8,     9,     0,     0,     0,     7,     8,     9,
     222,   222,   222,   222,   423,   222,   222,   234,   222,     0,
     275,     0,     0,   234,   275,   274,     0,    94,     0,   222,
       0,     0,     0,   219,   219,     0,     0,     0,     0,     0,
       0,   220,   220,   220,     0,     0,     0,   123,     0,     0,
       0,     0,   222,   222,     0,   272,     0,   221,   221,   221,
       0,   275,   275,   275,   275,   463,   275,   275,     0,   275,
       0,   275,     0,     0,     0,   124,   222,   230,   231,   232,
     233,     0,     6,     0,   221,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,     0,     0,     0,   222,
     222,     0,     0,   221,     0,   234,     0,     0,     0,     0,
       0,     0,   221,   221,   221,   221,   221,   221,     0,     0,
       0,     0,     0,     0,   126,     0,   230,   231,   232,   233,
       0,     6,   272,     0,   275,     0,     0,   221,     7,     8,
       9,    76,   -88,   -88,   -88,   -88,   -88,   -88,   -88,     0,
       0,     0,     0,     0,   234,   274,   274,   274,   274,   274,
     274,     0,     0,   -88,   219,   219,   219,   211,   212,   213,
     214,   275,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,   221,   221,   221,   221,     0,   221,
     221,   219,   221,     0,   274,   215,     0,     0,   274,     0,
       0,     0,   128,   221,   230,   231,   232,   233,     0,     6,
     219,     0,     0,     0,     0,     0,     7,     8,     9,     0,
     219,   219,   351,     0,     0,     0,   221,   221,     0,     0,
       0,     0,   234,     0,     0,   274,   274,   274,   274,     0,
     274,   274,     0,   274,   219,   274,     0,     0,     0,     0,
     221,     0,     0,     0,     0,     0,   218,     0,     0,   222,
     222,     0,     0,   272,   272,   398,     0,     0,     0,   222,
     222,   222,     0,   221,   221,   222,   222,   222,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,     0,     0,    90,     0,
       0,   219,   219,   419,     0,     0,   218,   218,     0,   219,
       0,   272,  -113,  -113,  -113,   272,     0,     0,   274,   121,
     219,     0,     0,     0,     0,     0,     0,     0,   271,     0,
       0,   130,     0,   230,   231,   232,   233,     0,     6,     0,
       0,     0,     0,   219,   219,     7,     8,     9,     0,     0,
       0,     0,   272,   272,   459,   274,   222,   222,   222,     0,
     272,   234,   272,     0,     0,     0,     0,   219,    46,    47,
      48,    49,    50,    51,    52,    53,     0,   -40,   -40,     0,
     -40,   -40,   -40,   -40,     0,   -40,     0,     0,     0,     0,
     219,   219,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,
     -40,   -40,   -40,   -40,   -40,   271,     0,     0,   -40,     0,
       0,   -40,     0,     0,     0,   132,   217,   230,   231,   232,
     233,     0,     6,     0,     0,   272,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,     0,   218,   218,   218,
       0,     0,     0,   221,   221,   234,     0,     0,     0,    92,
       0,     0,     0,   221,   221,   221,   217,   217,     0,   221,
     221,   221,   272,     0,   218,     0,     0,     0,   119,     0,
     241,   242,   243,   244,   245,   246,   247,   248,   270,     0,
       0,   -46,   -46,   218,   -46,   -46,   -46,   -46,     0,   -46,
       0,     0,     0,   347,   218,   149,   -46,   -46,   -46,     0,
     -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,     0,
       0,     0,   -46,     0,     0,   -46,     0,   218,     0,   134,
       0,   230,   231,   232,   233,     0,     6,     0,     0,     0,
     221,   221,   221,     7,     8,     9,   394,   271,   241,   242,
     243,   244,   245,   246,   247,   248,     0,     0,     0,   234,
     219,   219,     0,     0,     0,   270,     0,     0,     0,     0,
     219,   219,   219,   204,   218,   417,   219,   219,   219,     0,
       0,     0,   218,     0,   271,     0,     0,     0,   271,     0,
       0,     0,     0,   218,     0,     0,     0,   217,   217,   217,
     330,   331,   332,   333,   309,     6,   264,   265,   266,   267,
       0,     6,     7,     8,     9,     0,   218,   218,     7,     8,
       9,     0,     0,     0,   217,   271,   457,     0,   334,     0,
       0,     0,     0,   271,   268,   271,     0,     0,     0,     0,
     218,     0,     0,   217,     0,     0,     0,   219,   219,   219,
       0,     0,     0,     0,   349,   284,   285,   286,   287,   288,
     289,   290,   291,   218,   218,   -41,   -41,     0,   -41,   -41,
     -41,   -41,     0,   -41,     0,     0,     0,   217,     0,     0,
     -41,   -41,   -41,     0,   -41,   -41,     0,   -41,   -41,   -41,
     -41,   -41,   -41,     0,     0,     0,   -41,   396,   271,   -41,
       0,     0,     0,     0,     0,     0,   313,     0,   211,   212,
     213,   214,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,   415,   -51,   -51,     0,   -51,   -51,
     -51,   -51,   217,   -51,   270,   271,   215,     0,   270,     0,
     -51,   -51,   -51,   217,   -51,   -51,     0,   -51,   -51,   -51,
     578,   -51,   -51,     0,     0,     0,   -51,     0,   326,   -51,
     211,   212,   213,   214,     0,     6,   217,   217,     0,     0,
       0,     0,     7,     8,     9,   455,   -50,   -50,     0,   -50,
     -50,   -50,   -50,   270,   -50,   270,     0,     0,   215,     0,
     217,   -50,   -50,   -50,     0,   -50,   -50,     0,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,     0,   -50,     0,     0,
     -50,     0,     0,   217,   217,   341,     0,   330,   331,   332,
     333,     0,     6,   218,   218,     0,     0,     0,     0,     7,
       8,     9,     0,   218,   218,   218,     0,     0,     0,   218,
     218,   218,     0,     0,     0,   334,   -48,   -48,   270,   -48,
     -48,   -48,   -48,     0,   -48,     0,     0,     0,     0,     0,
       0,   -48,   -48,   -48,     0,   -48,   -48,     0,   -48,   -48,
     -48,   579,   -48,   -48,     0,     0,     0,   -48,     0,   344,
     -48,   330,   331,   332,   333,   270,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,   -47,
       0,   -47,   -47,   -47,   -47,     0,   -47,     0,     0,   334,
     218,   218,   218,   -47,   -47,   -47,     0,   -47,   -47,     0,
     -47,   -47,   -47,   -47,   -47,   -47,     0,     0,     0,   -47,
       0,     0,   -47,   -47,   -53,   -53,     0,   -53,   -53,   -53,
     -53,     0,   -53,     0,     0,     0,     0,     0,     0,   -53,
     -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,   -53,
     -53,   -53,     0,     0,     0,   -53,     0,     0,   -53,     0,
       0,     0,     0,   217,   217,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,   217,   217,   217,     0,     0,     0,   217,
     217,   217,   -55,     0,   -55,   -55,   -55,   -55,  -118,   -55,
    -118,  -118,     0,     0,     0,     0,   -55,   -55,   -55,     0,
     -55,   -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,     0,
       0,     0,   -55,     0,     0,   -55,   -55,     0,     0,     0,
       0,     0,     0,   -54,     0,   -54,   -54,   -54,   -54,     0,
     -54,     0,     0,     0,     0,     0,     0,   -54,   -54,   -54,
       0,   -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,   -54,
     217,   217,   217,   -54,     0,     0,   -54,   -54,   -52,   -52,
       0,   -52,   -52,   -52,   -52,     0,   -52,     0,     0,     0,
       0,     0,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,
     -52,   -52,   -52,   -52,   -52,   -52,     0,     0,     0,   -52,
     -49,   -49,   -52,   -49,   -49,   -49,   -49,     0,   -49,     0,
       0,     0,     0,     0,     0,   -49,   -49,   -49,     0,   -49,
     -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,
       0,   -49,     0,   -26,   -49,   -26,   -26,   -26,   -26,     0,
     -26,     0,     0,     0,     0,     0,     0,   -26,   -26,   -26,
       0,   -26,   -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,
       0,     0,     0,   -26,     0,     0,   -26,   -26,   -43,     0,
     -43,   -43,   -43,   -43,     0,   -43,     0,     0,     0,     0,
       0,     0,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,
     -43,   -43,   -43,   -43,   -43,     0,     0,     0,   -43,     0,
       0,   -43,   -43,   -44,     0,   -44,   -44,   -44,   -44,     0,
     -44,     0,     0,     0,     0,     0,     0,   -44,   -44,   -44,
       0,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,     0,   -44,     0,     0,   -44,   -44,   -39,     0,
     -39,   -39,   -39,   -39,     0,   -39,     0,     0,     0,     0,
       0,     0,   -39,   -39,   -39,     0,   -39,   -39,     0,   -39,
     -39,   -39,   -39,   -39,   -39,     0,     0,     0,   -39,     0,
       0,   -39,   -39,   -42,     0,   -42,   -42,   -42,   -42,     0,
     -42,     0,     0,     0,     0,     0,     0,   -42,   -42,   -42,
       0,   -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,
       0,     0,     0,   -42,     0,     0,   -42,   -42,   -45,     0,
     -45,   -45,   -45,   -45,     0,   -45,     0,     0,     0,     0,
       0,     0,   -45,   -45,   -45,     0,   -45,   -45,     0,   -45,
     -45,   -45,   -45,   -45,   -45,     0,     0,     0,   -45,     0,
       0,   -45,   -45,   -40,     0,   -40,   -40,   -40,   -40,     0,
     -40,     0,     0,     0,     0,     0,     0,   -40,   -40,   -40,
       0,   -40,   -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,
       0,     0,     0,   -40,     0,     0,   -40,   -40,   -46,     0,
     -46,   -46,   -46,   -46,     0,   -46,     0,     0,     0,     0,
       0,     0,   -46,   -46,   -46,     0,   -46,   -46,     0,   -46,
     -46,   -46,   -46,   -46,   -46,     0,     0,     0,   -46,     0,
       0,   -46,   -46,   -41,     0,   -41,   -41,   -41,   -41,     0,
     -41,     0,     0,     0,     0,     0,     0,   -41,   -41,   -41,
       0,   -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,
       0,     0,     0,   -41,     0,     0,   -41,   -41,   -51,     0,
     -51,   -51,   -51,   -51,     0,   -51,     0,     0,     0,     0,
       0,     0,   -51,   -51,   -51,     0,   -51,   -51,     0,   -51,
     -51,   -51,   649,   -51,   -51,     0,     0,     0,   -51,     0,
       0,   -51,   -51,   -50,     0,   -50,   -50,   -50,   -50,     0,
     -50,     0,     0,     0,     0,     0,     0,   -50,   -50,   -50,
       0,   -50,   -50,     0,   -50,   -50,   -50,   -50,   -50,   -50,
       0,     0,     0,   -50,     0,     0,   -50,   -50,   -48,     0,
     -48,   -48,   -48,   -48,     0,   -48,     0,     0,     0,     0,
       0,     0,   -48,   -48,   -48,     0,   -48,   -48,     0,   -48,
     -48,   -48,   650,   -48,   -48,     0,     0,     0,   -48,     0,
       0,   -48,   -48,   -57,   -57,     0,   -57,   -57,   -57,   -57,
       0,   -57,     0,     0,     0,     0,     0,     0,   -57,   -57,
     -57,     0,   -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,
     -57,     0,     0,     0,   -57,   -58,   -58,   -57,   -58,   -58,
     -58,   -58,     0,   -58,     0,     0,     0,     0,     0,     0,
     -58,   -58,   -58,     0,   -58,   -58,     0,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,   -58,   -59,   -59,   -58,
     -59,   -59,   -59,   -59,     0,   -59,     0,     0,     0,     0,
       0,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,   -59,
     -59,   -59,   -59,   -59,   -59,     0,     0,     0,   -59,   -56,
     -56,   -59,   -56,   -56,   -56,   -56,     0,   -56,     0,     0,
       0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,   -56,
       0,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,
     -56,     0,   -53,   -56,   -53,   -53,   -53,   -53,     0,   -53,
       0,     0,     0,     0,     0,     0,   -53,   -53,   -53,     0,
     -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,   -53,     0,
       0,     0,   -53,     0,     0,   -53,   -53,   -52,     0,   -52,
     -52,   -52,   -52,     0,   -52,     0,     0,     0,     0,     0,
       0,   -52,   -52,   -52,     0,   -52,   -52,     0,   -52,   -52,
     -52,   -52,   -52,   -52,     0,     0,     0,   -52,     0,     0,
     -52,   -52,   -49,     0,   -49,   -49,   -49,   -49,     0,   -49,
       0,     0,     0,     0,     0,     0,   -49,   -49,   -49,     0,
     -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,     0,   -49,     0,     0,   -49,   -49,   -57,     0,   -57,
     -57,   -57,   -57,     0,   -57,     0,     0,     0,     0,     0,
       0,   -57,   -57,   -57,     0,   -57,   -57,     0,   -57,   -57,
     -57,   -57,   -57,   -57,     0,     0,     0,   -57,     0,     0,
     -57,   -57,   -58,     0,   -58,   -58,   -58,   -58,     0,   -58,
       0,     0,     0,     0,     0,     0,   -58,   -58,   -58,     0,
     -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,   -58,     0,
       0,     0,   -58,     0,     0,   -58,   -58,   -59,     0,   -59,
     -59,   -59,   -59,     0,   -59,     0,     0,     0,     0,     0,
       0,   -59,   -59,   -59,     0,   -59,   -59,     0,   -59,   -59,
     -59,   -59,   -59,   -59,     0,     0,     0,   -59,     0,     0,
     -59,   -59,   -56,     0,   -56,   -56,   -56,   -56,     0,   -56,
       0,     0,     0,     0,     0,     0,   -56,   -56,   -56,     0,
     -56,   -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,
       0,     0,   -56,     0,     0,   -56,   -56,    -3,     1,     0,
       2,     3,     4,     5,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,    10,    11,     0,    12,
      13,    14,     0,    15,    16,     0,     0,     0,    17,     0,
     -25,    18,   -25,   -25,   -25,   -25,     0,   -25,     0,     0,
       0,     0,     0,     0,   -25,   -25,   -25,     0,   -25,   -25,
       0,   -25,   -25,   -25,     0,   -25,   -25,     0,     0,     0,
     -25,     0,     0,   -25,   -25,    -2,    66,     0,     2,     3,
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
       0,     0,    -7,   -34,   -34,    -7,   -34,   -34,   -34,   -34,
       0,   -34,     0,     0,     0,     0,     0,     0,   -34,   -34,
     -34,     0,   -34,   -34,     0,   -34,   -34,   -34,     0,   -34,
     -34,     0,     0,     0,   -34,    -9,    -9,   -34,    -9,    -9,
      -9,    -9,     0,    -9,     0,     0,     0,     0,     0,     0,
      -9,    -9,    -9,     0,    -9,    -9,     0,    -9,    -9,    -9,
       0,    -9,    -9,     0,     0,     0,    -9,   -38,   -38,    -9,
     -38,   -38,   -38,   -38,     0,   -38,     0,     0,     0,     0,
       0,     0,   -38,   -38,   -38,     0,   -38,   -38,     0,   -38,
     -38,   -38,     0,   -38,   -38,     0,     0,     0,   -38,   -33,
     -33,   -38,   -33,   -33,   -33,   -33,     0,   -33,     0,     0,
       0,     0,     0,     0,   -33,   -33,   -33,     0,   -33,   -33,
       0,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,     0,
     -33,   -35,   -35,   -33,   -35,   -35,   -35,   -35,     0,   -35,
       0,     0,     0,     0,     0,     0,   -35,   -35,   -35,     0,
     -35,   -35,     0,   -35,   -35,   -35,     0,   -35,   -35,     0,
       0,     0,   -35,   -36,   -36,   -35,   -36,   -36,   -36,   -36,
       0,   -36,     0,     0,     0,     0,     0,     0,   -36,   -36,
     -36,     0,   -36,   -36,     0,   -36,   -36,   -36,     0,   -36,
     -36,     0,     0,     0,   -36,   -37,   -37,   -36,   -37,   -37,
     -37,   -37,     0,   -37,     0,     0,     0,     0,     0,     0,
     -37,   -37,   -37,     0,   -37,   -37,     0,   -37,   -37,   -37,
       0,   -37,   -37,     0,     0,     0,   -37,     0,    66,   -37,
       2,     3,     4,     5,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,   249,   250,     0,   251,
     252,   253,     0,   254,   255,     0,     0,     0,    17,     0,
       0,   256,   -28,    -5,    -5,     0,    -5,    -5,    -5,    -5,
       0,    -5,     0,     0,     0,     0,     0,     0,    -5,    -5,
      -5,     0,    -5,    -5,     0,    -5,    -5,    -5,     0,    -5,
      -5,     0,     0,     0,    -5,   -47,   -47,    -5,   -47,   -47,
     -47,   -47,     0,   -47,     0,     0,     0,     0,     0,     0,
     -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,
       0,   -47,   -47,     0,     0,     0,   -47,   -11,   -11,   -47,
     -11,   -11,   -11,   -11,     0,   -11,     0,     0,     0,     0,
       0,     0,   -11,   -11,   -11,     0,   -11,   -11,     0,   -11,
     -11,   -11,     0,   -11,   -11,     0,     0,     0,   -11,   -55,
     -55,   -11,   -55,   -55,   -55,   -55,     0,   -55,     0,     0,
       0,     0,     0,     0,   -55,   -55,   -55,     0,   -55,   -55,
       0,   -55,   -55,   -55,     0,   -55,   -55,     0,     0,     0,
     -55,   -54,   -54,   -55,   -54,   -54,   -54,   -54,     0,   -54,
       0,     0,     0,     0,     0,     0,   -54,   -54,   -54,     0,
     -54,   -54,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,
       0,     0,   -54,     0,   -31,   -54,   -31,   -31,   -31,   -31,
       0,   -31,     0,     0,     0,     0,     0,     0,   -31,   -31,
     -31,     0,   -31,   -31,     0,   -31,   -31,   -31,     0,   -31,
     -31,     0,     0,     0,   -31,     0,     0,   -31,   -31,    66,
       0,     2,     3,     4,     5,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,   249,   250,     0,
     251,   252,   253,     0,   254,   255,     0,     0,     0,    17,
       0,     0,   256,   -27,   -30,     0,   -30,   -30,   -30,   -30,
       0,   -30,     0,     0,     0,     0,     0,     0,   -30,   -30,
     -30,     0,   -30,   -30,     0,   -30,   -30,   -30,     0,   -30,
     -30,     0,     0,     0,   -30,     0,     0,   -30,   -30,   -32,
       0,   -32,   -32,   -32,   -32,     0,   -32,     0,     0,     0,
       0,     0,     0,   -32,   -32,   -32,     0,   -32,   -32,     0,
     -32,   -32,   -32,     0,   -32,   -32,     0,     0,     0,   -32,
       0,     0,   -32,   -32,   -10,   -10,     0,   -10,   -10,   -10,
     -10,     0,   -10,     0,     0,     0,     0,     0,     0,   -10,
     -10,   -10,     0,   -10,   -10,     0,   -10,   -10,   -10,     0,
     -10,   -10,     0,     0,     0,   -10,   -26,   -26,   -10,   -26,
     -26,   -26,   -26,     0,   -26,     0,     0,     0,     0,     0,
       0,   -26,   -26,   -26,     0,   -26,   -26,     0,   -26,   -26,
     -26,     0,   -26,   -26,     0,     0,     0,   -26,     0,   -29,
     -26,   -29,   -29,   -29,   -29,     0,   -29,     0,     0,     0,
       0,     0,     0,   -29,   -29,   -29,     0,   -29,   -29,     0,
     -29,   -29,   -29,     0,   -29,   -29,     0,     0,     0,   -29,
       0,     0,   -29,   -29,   -12,   -12,     0,   -12,   -12,   -12,
     -12,     0,   -12,     0,     0,     0,     0,     0,     0,   -12,
     -12,   -12,     0,   -12,   -12,     0,   -12,   -12,   -12,     0,
     -12,   -12,     0,     0,     0,   -12,   -43,   -43,   -12,   -43,
     -43,   -43,   -43,     0,   -43,     0,     0,     0,     0,     0,
       0,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,
     -43,     0,   -43,   -43,     0,     0,     0,   -43,   -44,   -44,
     -43,   -44,   -44,   -44,   -44,     0,   -44,     0,     0,     0,
       0,     0,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,
     -44,   -44,   -44,     0,   -44,   -44,     0,     0,     0,   -44,
     -39,   -39,   -44,   -39,   -39,   -39,   -39,     0,   -39,     0,
       0,     0,     0,     0,     0,   -39,   -39,   -39,     0,   -39,
     -39,     0,   -39,   -39,   -39,     0,   -39,   -39,     0,     0,
       0,   -39,   -42,   -42,   -39,   -42,   -42,   -42,   -42,     0,
     -42,     0,     0,     0,     0,     0,     0,   -42,   -42,   -42,
       0,   -42,   -42,     0,   -42,   -42,   -42,     0,   -42,   -42,
       0,     0,     0,   -42,   -45,   -45,   -42,   -45,   -45,   -45,
     -45,     0,   -45,     0,     0,     0,     0,     0,     0,   -45,
     -45,   -45,     0,   -45,   -45,     0,   -45,   -45,   -45,     0,
     -45,   -45,     0,     0,     0,   -45,   -40,   -40,   -45,   -40,
     -40,   -40,   -40,     0,   -40,     0,     0,     0,     0,     0,
       0,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,   -40,
     -40,     0,   -40,   -40,     0,     0,     0,   -40,   -46,   -46,
     -40,   -46,   -46,   -46,   -46,     0,   -46,     0,     0,     0,
       0,     0,     0,   -46,   -46,   -46,     0,   -46,   -46,     0,
     -46,   -46,   -46,     0,   -46,   -46,     0,     0,     0,   -46,
     -41,   -41,   -46,   -41,   -41,   -41,   -41,     0,   -41,     0,
       0,     0,     0,     0,     0,   -41,   -41,   -41,     0,   -41,
     -41,     0,   -41,   -41,   -41,     0,   -41,   -41,     0,     0,
       0,   -41,   -50,   -50,   -41,   -50,   -50,   -50,   -50,     0,
     -50,     0,     0,     0,     0,     0,     0,   -50,   -50,   -50,
       0,   -50,   -50,     0,   -50,   -50,   -50,     0,   -50,   -50,
       0,     0,     0,   -50,   -53,   -53,   -50,   -53,   -53,   -53,
     -53,     0,   -53,     0,     0,     0,     0,     0,     0,   -53,
     -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,     0,
     -53,   -53,     0,     0,     0,   -53,   -52,   -52,   -53,   -52,
     -52,   -52,   -52,     0,   -52,     0,     0,     0,     0,     0,
       0,   -52,   -52,   -52,     0,   -52,   -52,     0,   -52,   -52,
     -52,     0,   -52,   -52,     0,     0,     0,   -52,   -49,   -49,
     -52,   -49,   -49,   -49,   -49,     0,   -49,     0,     0,     0,
       0,     0,     0,   -49,   -49,   -49,     0,   -49,   -49,     0,
     -49,   -49,   -49,     0,   -49,   -49,     0,     0,     0,   -49,
     -18,   -18,   -49,   -18,   -18,   -18,   -18,     0,   -18,     0,
       0,     0,     0,     0,     0,   -18,   -18,   -18,     0,   -18,
     -18,     0,   -18,   -18,   -18,     0,   -18,   -18,     0,     0,
       0,   -18,   -15,   -15,   -18,   -15,   -15,   -15,   -15,     0,
     -15,     0,     0,     0,     0,     0,     0,   -15,   -15,   -15,
       0,   -15,   -15,     0,   -15,   -15,   -15,     0,   -15,   -15,
       0,     0,     0,   -15,   -57,   -57,   -15,   -57,   -57,   -57,
     -57,     0,   -57,     0,     0,     0,     0,     0,     0,   -57,
     -57,   -57,     0,   -57,   -57,     0,   -57,   -57,   -57,     0,
     -57,   -57,     0,     0,     0,   -57,   -58,   -58,   -57,   -58,
     -58,   -58,   -58,     0,   -58,     0,     0,     0,     0,     0,
       0,   -58,   -58,   -58,     0,   -58,   -58,     0,   -58,   -58,
     -58,     0,   -58,   -58,     0,     0,     0,   -58,   -59,   -59,
     -58,   -59,   -59,   -59,   -59,     0,   -59,     0,     0,     0,
       0,     0,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,
     -59,   -59,   -59,     0,   -59,   -59,     0,     0,     0,   -59,
     -56,   -56,   -59,   -56,   -56,   -56,   -56,     0,   -56,     0,
       0,     0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,
     -56,     0,   -56,   -56,   -56,     0,   -56,   -56,     0,     0,
       0,   -56,     0,   -34,   -56,   -34,   -34,   -34,   -34,     0,
     -34,     0,     0,     0,     0,     0,     0,   -34,   -34,   -34,
       0,   -34,   -34,     0,   -34,   -34,   -34,     0,   -34,   -34,
       0,     0,     0,   -34,     0,     0,   -34,   -34,   -38,     0,
     -38,   -38,   -38,   -38,     0,   -38,     0,     0,     0,     0,
       0,     0,   -38,   -38,   -38,     0,   -38,   -38,     0,   -38,
     -38,   -38,     0,   -38,   -38,     0,     0,     0,   -38,     0,
       0,   -38,   -38,   -33,     0,   -33,   -33,   -33,   -33,     0,
     -33,     0,     0,     0,     0,     0,     0,   -33,   -33,   -33,
       0,   -33,   -33,     0,   -33,   -33,   -33,     0,   -33,   -33,
       0,     0,     0,   -33,     0,     0,   -33,   -33,   -35,     0,
     -35,   -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,
       0,     0,   -35,   -35,   -35,     0,   -35,   -35,     0,   -35,
     -35,   -35,     0,   -35,   -35,     0,     0,     0,   -35,     0,
       0,   -35,   -35,   -36,     0,   -36,   -36,   -36,   -36,     0,
     -36,     0,     0,     0,     0,     0,     0,   -36,   -36,   -36,
       0,   -36,   -36,     0,   -36,   -36,   -36,     0,   -36,   -36,
       0,     0,     0,   -36,     0,     0,   -36,   -36,   -37,     0,
     -37,   -37,   -37,   -37,     0,   -37,     0,     0,     0,     0,
       0,     0,   -37,   -37,   -37,     0,   -37,   -37,     0,   -37,
     -37,   -37,     0,   -37,   -37,     0,     0,     0,   -37,     0,
       0,   -37,   -37,   -11,     0,   -11,   -11,   -11,   -11,     0,
     -11,     0,     0,     0,     0,     0,     0,   -11,   -11,   -11,
       0,   -11,   -11,     0,   -11,   -11,   -11,     0,   -11,   -11,
       0,     0,     0,   -11,     0,     0,   -11,   -11,   -10,     0,
     -10,   -10,   -10,   -10,     0,   -10,     0,     0,     0,     0,
       0,     0,   -10,   -10,   -10,     0,   -10,   -10,     0,   -10,
     -10,   -10,     0,   -10,   -10,     0,     0,     0,   -10,     0,
       0,   -10,   -10,   -47,     0,   -47,   -47,   -47,   -47,     0,
     -47,     0,     0,     0,     0,     0,     0,   -47,   -47,   -47,
       0,   -47,   -47,     0,   -47,   -47,   -47,     0,   -47,   -47,
       0,     0,     0,   -47,     0,     0,   -47,   -47,   -12,     0,
     -12,   -12,   -12,   -12,     0,   -12,     0,     0,     0,     0,
       0,     0,   -12,   -12,   -12,     0,   -12,   -12,     0,   -12,
     -12,   -12,     0,   -12,   -12,     0,     0,     0,   -12,     0,
       0,   -12,   -12,   -55,     0,   -55,   -55,   -55,   -55,     0,
     -55,     0,     0,     0,     0,     0,     0,   -55,   -55,   -55,
       0,   -55,   -55,     0,   -55,   -55,   -55,     0,   -55,   -55,
       0,     0,     0,   -55,     0,     0,   -55,   -55,   -54,     0,
     -54,   -54,   -54,   -54,     0,   -54,     0,     0,     0,     0,
       0,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,   -54,
     -54,   -54,     0,   -54,   -54,     0,     0,     0,   -54,     0,
       0,   -54,   -54,   -26,     0,   -26,   -26,   -26,   -26,     0,
     -26,     0,     0,     0,     0,     0,     0,   -26,   -26,   -26,
       0,   -26,   -26,     0,   -26,   -26,   -26,     0,   -26,   -26,
       0,     0,     0,   -26,     0,     0,   -26,   -26,   -43,     0,
     -43,   -43,   -43,   -43,     0,   -43,     0,     0,     0,     0,
       0,     0,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,
     -43,   -43,     0,   -43,   -43,     0,     0,     0,   -43,     0,
       0,   -43,   -43,   -44,     0,   -44,   -44,   -44,   -44,     0,
     -44,     0,     0,     0,     0,     0,     0,   -44,   -44,   -44,
       0,   -44,   -44,     0,   -44,   -44,   -44,     0,   -44,   -44,
       0,     0,     0,   -44,     0,     0,   -44,   -44,   -39,     0,
     -39,   -39,   -39,   -39,     0,   -39,     0,     0,     0,     0,
       0,     0,   -39,   -39,   -39,     0,   -39,   -39,     0,   -39,
     -39,   -39,     0,   -39,   -39,     0,     0,     0,   -39,     0,
       0,   -39,   -39,   -42,     0,   -42,   -42,   -42,   -42,     0,
     -42,     0,     0,     0,     0,     0,     0,   -42,   -42,   -42,
       0,   -42,   -42,     0,   -42,   -42,   -42,     0,   -42,   -42,
       0,     0,     0,   -42,     0,     0,   -42,   -42,   -45,     0,
     -45,   -45,   -45,   -45,     0,   -45,     0,     0,     0,     0,
       0,     0,   -45,   -45,   -45,     0,   -45,   -45,     0,   -45,
     -45,   -45,     0,   -45,   -45,     0,     0,     0,   -45,     0,
       0,   -45,   -45,   -40,     0,   -40,   -40,   -40,   -40,     0,
     -40,     0,     0,     0,     0,     0,     0,   -40,   -40,   -40,
       0,   -40,   -40,     0,   -40,   -40,   -40,     0,   -40,   -40,
       0,     0,     0,   -40,     0,     0,   -40,   -40,   -46,     0,
     -46,   -46,   -46,   -46,     0,   -46,     0,     0,     0,     0,
       0,     0,   -46,   -46,   -46,     0,   -46,   -46,     0,   -46,
     -46,   -46,     0,   -46,   -46,     0,     0,     0,   -46,     0,
       0,   -46,   -46,   -41,     0,   -41,   -41,   -41,   -41,     0,
     -41,     0,     0,     0,     0,     0,     0,   -41,   -41,   -41,
       0,   -41,   -41,     0,   -41,   -41,   -41,     0,   -41,   -41,
       0,     0,     0,   -41,     0,     0,   -41,   -41,   -50,     0,
     -50,   -50,   -50,   -50,     0,   -50,     0,     0,     0,     0,
       0,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,   -50,
     -50,   -50,     0,   -50,   -50,     0,     0,     0,   -50,     0,
       0,   -50,   -50,   -53,     0,   -53,   -53,   -53,   -53,     0,
     -53,     0,     0,     0,     0,     0,     0,   -53,   -53,   -53,
       0,   -53,   -53,     0,   -53,   -53,   -53,     0,   -53,   -53,
       0,     0,     0,   -53,     0,     0,   -53,   -53,   -52,     0,
     -52,   -52,   -52,   -52,     0,   -52,     0,     0,     0,     0,
       0,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,   -52,
     -52,   -52,     0,   -52,   -52,     0,     0,     0,   -52,     0,
       0,   -52,   -52,   -49,     0,   -49,   -49,   -49,   -49,     0,
     -49,     0,     0,     0,     0,     0,     0,   -49,   -49,   -49,
       0,   -49,   -49,     0,   -49,   -49,   -49,     0,   -49,   -49,
       0,     0,     0,   -49,     0,     0,   -49,   -49,   -57,     0,
     -57,   -57,   -57,   -57,     0,   -57,     0,     0,     0,     0,
       0,     0,   -57,   -57,   -57,     0,   -57,   -57,     0,   -57,
     -57,   -57,     0,   -57,   -57,     0,     0,     0,   -57,     0,
       0,   -57,   -57,   -58,     0,   -58,   -58,   -58,   -58,     0,
     -58,     0,     0,     0,     0,     0,     0,   -58,   -58,   -58,
       0,   -58,   -58,     0,   -58,   -58,   -58,     0,   -58,   -58,
       0,     0,     0,   -58,     0,     0,   -58,   -58,   -59,     0,
     -59,   -59,   -59,   -59,     0,   -59,     0,     0,     0,     0,
       0,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,   -59,
     -59,   -59,     0,   -59,   -59,     0,     0,     0,   -59,     0,
       0,   -59,   -59,   -56,     0,   -56,   -56,   -56,   -56,     0,
     -56,     0,     0,     0,     0,     0,     0,   -56,   -56,   -56,
       0,   -56,   -56,     0,   -56,   -56,   -56,     0,   -56,   -56,
       0,     0,     0,   -56,     0,     0,   -56,   -56,   346,     0,
     330,   331,   332,   333,   348,     6,   330,   331,   332,   333,
       0,     6,     7,     8,     9,     0,     0,     0,     7,     8,
       9,     0,   350,     0,   330,   331,   332,   333,   334,     6,
       0,     0,     0,     0,   334,     0,     7,     8,     9,   360,
       0,     2,     3,     4,     5,     0,     6,     0,     0,     0,
       0,     0,   334,     7,     8,     9,   364,     0,   211,   212,
     213,   214,     0,     6,     0,     0,     0,     0,     0,    17,
       7,     8,     9,   388,     0,   377,   378,   379,   380,     0,
       6,     0,     0,     0,     0,     0,   215,     7,     8,     9,
     391,     0,   377,   378,   379,   380,     0,     6,     0,     0,
       0,     0,     0,   381,     7,     8,     9,   393,     0,   377,
     378,   379,   380,     0,     6,     0,     0,     0,     0,     0,
     381,     7,     8,     9,   395,     0,   377,   378,   379,   380,
       0,     6,     0,     0,     0,     0,     0,   381,     7,     8,
       9,   397,     0,   377,   378,   379,   380,     0,     6,     0,
       0,     0,     0,     0,   381,     7,     8,     9,   407,     0,
       2,     3,     4,     5,     0,     6,     0,     0,     0,     0,
       0,   381,     7,     8,     9,   414,     0,   330,   331,   332,
     333,     0,     6,     0,     0,     0,     0,     0,    17,     7,
       8,     9,   416,     0,   330,   331,   332,   333,     0,     6,
       0,     0,     0,     0,     0,   334,     7,     8,     9,   418,
       0,   330,   331,   332,   333,     0,     6,     0,     0,     0,
       0,     0,   334,     7,     8,     9,   420,     0,   330,   331,
     332,   333,     0,     6,     0,     0,     0,     0,     0,   334,
       7,     8,     9,   422,     0,   330,   331,   332,   333,     0,
       6,     0,     0,     0,     0,     0,   334,     7,     8,     9,
     424,     0,   330,   331,   332,   333,     0,     6,     0,     0,
       0,     0,     0,   334,     7,     8,     9,   426,     0,   330,
     331,   332,   333,     0,     6,     0,     0,     0,     0,     0,
     334,     7,     8,     9,   428,     0,   330,   331,   332,   333,
       0,     6,     0,     0,     0,     0,     0,   334,     7,     8,
       9,   430,     0,   330,   331,   332,   333,     0,     6,     0,
       0,     0,     0,     0,   334,     7,     8,     9,   436,     0,
     211,   212,   213,   214,     0,     6,     0,     0,     0,     0,
       0,   334,     7,     8,     9,   445,     0,   211,   212,   213,
     214,     0,     6,     0,     0,     0,     0,     0,   215,     7,
       8,     9,   454,     0,   377,   378,   379,   380,     0,     6,
       0,     0,     0,     0,     0,   215,     7,     8,     9,   456,
       0,   377,   378,   379,   380,     0,     6,     0,     0,     0,
       0,     0,   381,     7,     8,     9,   458,     0,   377,   378,
     379,   380,     0,     6,     0,     0,     0,     0,     0,   381,
       7,     8,     9,   460,     0,   377,   378,   379,   380,     0,
       6,     0,     0,     0,     0,     0,   381,     7,     8,     9,
     462,     0,   377,   378,   379,   380,     0,     6,     0,     0,
       0,     0,     0,   381,     7,     8,     9,   464,     0,   377,
     378,   379,   380,     0,     6,     0,     0,     0,     0,     0,
     381,     7,     8,     9,   466,     0,   377,   378,   379,   380,
       0,     6,     0,     0,     0,     0,     0,   381,     7,     8,
       9,   468,     0,   377,   378,   379,   380,     0,     6,     0,
       0,     0,     0,     0,   381,     7,     8,     9,   470,     0,
     377,   378,   379,   380,     0,     6,     0,     0,     0,     0,
       0,   381,     7,     8,     9,   473,     0,   211,   212,   213,
     214,     0,     6,     0,     0,     0,     0,     0,   381,     7,
       8,     9,   482,     0,   211,   212,   213,   214,     0,     6,
       0,     0,     0,     0,     0,   215,     7,     8,     9,   568,
       0,     2,     3,     4,     5,     0,     6,     0,     0,     0,
       0,     0,   215,     7,     8,     9,   588,     0,   211,   212,
     213,   214,     0,     6,     0,     0,     0,     0,     0,    17,
       7,     8,     9,     0,     0,   264,   265,   266,   267,     0,
       6,     0,     0,     0,     0,     0,   215,     7,     8,     9,
       0,     0,   377,   378,   379,   380,     0,     6,     0,     0,
       0,     0,     0,   268,     7,     8,     9,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,     0,     0,     0,     0,     0,
     381,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,
     374,     0,   -92,   -92,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,     0,     0,   -96,     0,   -96,   -96,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,     0,  -102,     0,  -102,
    -102,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,     0,
       0,  -110,     0,  -110,  -110,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,     0,   -97,     0,   -97,   -97,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,     0,     0,     0,   476,
    -109,  -109,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
       0,  -112,     0,  -112,  -112,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,     0,     0,  -111,     0,  -111,  -111,   373,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,     0,  -103,     0,
    -103,  -103,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
       0,     0,     0,     0,   -88,   -88,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,     0,     0,     0,  -119,  -119,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,     0,     0,     0,
       0,  -120,  -120,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,     0,     0,     0,  -118,  -118,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,     0,     0,     0,     0,   -95,   -95,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,
       0,   -96,   -96,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,     0,     0,     0,     0,  -102,  -102,   373,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,     0,     0,     0,  -110,  -110,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,     0,     0,
       0,     0,   -91,   -91,   284,   285,   286,   287,   -67,   289,
     290,   291,     0,     0,     0,   -92,   -92,   284,   285,   286,
     -71,   -71,   289,   290,   291,     0,     0,     0,     0,   -67,
     -67,   284,   285,   286,   -75,   -75,   -75,   290,   291,     0,
       0,     0,   -71,   -71,   284,   285,   -79,   -79,   -79,   -79,
     290,   291,     0,     0,     0,     0,   -75,   -75,   284,   -90,
     -90,   -90,   -90,   -90,   -90,   -90,     0,     0,     0,   -79,
     -79,   373,   -89,   -89,   -89,   -89,   -89,   -89,   -89,     0,
       0,     0,     0,   -90,   -90,   284,   285,   -85,   -85,   -85,
     -85,   290,   291,     0,     0,     0,   -89,   -89,   284,   285,
     -84,   -84,   -84,   -84,   290,   291,     0,     0,     0,     0,
     -85,   -85,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
       0,     0,     0,   -84,   -84,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,     0,     0,     0,     0,   -94,   -94,   284,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
     -93,   -93,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
       0,     0,     0,     0,   -62,   -62,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,     0,     0,     0,   -97,   -97,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,     0,     0,     0,
       0,  -112,  -112,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,     0,     0,     0,  -111,  -111,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,     0,     0,     0,     0,  -103,  -103,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,  -109,
     325,  -109,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
       0,     0,     0,  -119,     0,  -119,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,     0,  -120,     0,  -120,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,     0,     0,     0,  -118,
       0,  -118,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
       0,   323,     0,   -92,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,     0,     0,     0,   -96,     0,   -96,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,     0,  -102,     0,  -102,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,     0,     0,
       0,  -110,     0,  -110,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,     0,   -97,     0,   -97,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,     0,     0,     0,     0,   439,  -109,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,     0,  -112,
       0,  -112,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
       0,     0,     0,  -111,     0,  -111,   322,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,     0,  -103,     0,  -103,   370,   -81,
     -81,   -81,   -81,   371,   372,     0,     0,     0,     0,     0,
       0,   -88,   241,   242,   243,   244,   245,   246,   247,   248,
       0,     0,   -81,   -81,   241,   242,   243,   244,   245,   246,
     247,   248,     0,     0,     0,     0,     0,   412,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,     0,     0,     0,   433,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,     0,     0,
       0,     0,     0,  -119,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,     0,     0,     0,  -120,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,     0,     0,     0,     0,     0,  -118,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,     0,
       0,   -95,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
       0,     0,     0,     0,     0,   -96,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,     0,     0,     0,  -102,   322,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,     0,     0,     0,     0,
       0,  -110,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
       0,     0,     0,   -91,   241,   242,   243,   244,   245,   246,
     247,   248,     0,     0,     0,     0,     0,   -92,   241,   242,
     243,   244,   -67,   246,   247,   248,     0,     0,     0,   452,
     241,   242,   243,   -71,   -71,   246,   247,   248,     0,     0,
       0,     0,     0,   -67,   241,   242,   243,   -75,   -75,   -75,
     247,   248,     0,     0,     0,   -71,   241,   242,   -79,   -79,
     -79,   -79,   247,   248,     0,     0,     0,     0,     0,   -75,
     241,   -90,   -90,   -90,   -90,   -90,   -90,   -90,     0,     0,
       0,   -79,   322,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
       0,     0,     0,     0,     0,   -90,   241,   242,   -85,   -85,
     -85,   -85,   247,   248,     0,     0,     0,   -89,   241,   242,
     -84,   -84,   -84,   -84,   247,   248,     0,     0,     0,     0,
       0,   -85,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
       0,     0,     0,   -84,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,     0,     0,     0,     0,     0,   -94,   241,   242,
     243,   244,   245,   246,   247,   248,     0,     0,     0,   -93,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,   -62,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,     0,     0,     0,   491,   241,   242,   243,   244,
     245,   246,   247,   248,     0,     0,     0,     0,     0,   -97,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,   496,   241,   242,   243,   244,   245,   246,   247,   248,
       0,     0,     0,     0,     0,   499,   241,   242,   243,   244,
     245,   246,   247,   248,     0,     0,     0,   505,   241,   242,
     243,   244,   245,   246,   247,   248,     0,     0,     0,     0,
       0,   510,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
       0,     0,     0,   513,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,     0,     0,     0,     0,     0,  -112,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,     0,     0,     0,  -111,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,  -103,   241,   242,   243,   244,   245,   246,
     247,   248,     0,     0,     0,   609,   241,   242,   243,   244,
     245,   246,   247,   248,     0,     0,     0,     0,     0,   612,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,   619,   241,   242,   243,   244,   245,   246,   247,   248,
       0,     0,     0,     0,     0,   623,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,     0,     0,     0,   662,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,     0,     0,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,
    -109,  -109,    79,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,     0,     0,  -113,     0,  -113,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,     0,  -109,     0,   329,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,     0,     0,  -119,  -119,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,     0,     0,
    -120,  -120,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
       0,     0,  -118,  -118,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,     0,     0,   -92,    77,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,     0,     0,   -96,   -96,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,     0,     0,  -102,  -102,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,     0,     0,
    -110,  -110,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
       0,     0,   -97,   -97,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,     0,     0,  -112,  -112,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,     0,     0,  -111,  -111,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,  -103,  -103,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,     0,     0,
     108,    76,   -91,   -91,   -91,   -91,   -91,   -91,   -91,     0,
       0,     0,   -95,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,     0,     0,   -91,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,   -92,    46,    47,    48,    49,
     -67,    51,    52,    53,     0,     0,   151,    46,    47,    48,
     -71,   -71,    51,    52,    53,     0,     0,     0,   -67,    46,
      47,    48,   -75,   -75,   -75,    52,    53,     0,     0,   -71,
      46,    47,   -79,   -79,   -79,   -79,    52,    53,     0,     0,
       0,   -75,    46,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
       0,     0,   -79,    76,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,     0,     0,     0,   -90,    46,    47,   -85,   -85,   -85,
     -85,    52,    53,     0,     0,   -89,    46,    47,   -84,   -84,
     -84,   -84,    52,    53,     0,     0,     0,   -85,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,     0,     0,   -84,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,     0,     0,     0,
     -94,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,   -93,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,   -62,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,     0,     0,   189,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,     0,     0,     0,  -119,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,     0,     0,  -120,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,     0,     0,     0,  -118,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,
     -96,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,     0,
       0,     0,  -102,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,     0,     0,  -110,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,   -97,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,   449,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,     0,     0,     0,   486,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,     0,     0,  -112,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,  -111,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,   501,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,     0,     0,     0,   515,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,  -103,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,   575,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,   581,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,     0,
     592,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,   614,     0,     0,     0,     0,     0,    -4,     0,     0,
       0,     0,     0,   652,    46,    47,    48,    49,    50,    51,
      52,    53,   241,   242,   243,   244,   245,   246,   247,   248
};

static const yytype_int16 yycheck[] =
{
       0,   256,   362,     0,   357,     1,     1,     1,   325,    11,
       6,     1,   329,     1,     1,     1,    16,    17,     1,     1,
      20,    31,     1,    20,     3,     4,     5,     6,     1,     8,
      32,     6,    19,    20,    29,    29,    15,    16,    17,    29,
       1,    29,     1,    29,   299,    32,    29,    29,     1,   409,
       0,   404,    31,    32,    29,    31,    29,    57,    58,   376,
      19,    20,     1,     1,    64,    31,     6,     1,    29,     1,
      20,    31,     6,    32,     6,     0,    29,     0,     1,    79,
       3,     4,     5,     6,     6,     8,     0,   151,   152,    29,
      29,    29,    15,    16,    17,     6,    19,    20,     1,    22,
      23,    24,    25,    26,    27,     6,    20,    29,    31,    31,
      21,    34,    11,    11,   114,     6,    19,    20,    29,     6,
      31,    29,   439,    29,   188,   189,   190,    11,    29,    32,
      21,    29,     1,    32,     3,     4,     5,     6,    29,     8,
      31,     6,    29,   140,    31,    29,    15,    16,    17,   149,
     150,    32,    33,    22,    23,    24,   156,    26,    27,   476,
      10,    11,    31,     7,    29,    34,    31,   164,     9,    10,
      11,    12,    32,   173,     8,     9,    10,    11,    12,    13,
      14,     0,    32,    33,    32,   182,   186,   187,   188,   189,
     190,    32,     1,    32,     3,     4,     5,     6,    32,     8,
      32,    20,   202,   203,   204,   205,    15,    16,    17,    18,
     570,   564,     1,    29,     6,   215,     1,     6,     3,     4,
       5,     6,    31,     8,    32,     9,    10,    11,    12,    21,
      15,    16,    17,    32,   234,   149,   150,    22,    23,    24,
       0,    26,    27,    29,     0,    32,    31,    35,    32,    34,
      32,     9,    10,    11,    12,   255,     6,    10,    11,   173,
      20,    10,    11,    12,    20,    10,    11,    12,   268,    32,
      33,    21,   186,   187,    32,    33,    19,    20,   533,    32,
      33,    29,    30,    32,    33,    32,    33,    32,   202,   203,
     204,   205,    10,    11,    12,   359,     1,     1,   298,     3,
       4,     5,     6,     1,     8,     3,     4,     5,     6,    29,
       8,    15,    16,    17,    32,    33,    11,    15,    16,    17,
      18,     9,    10,    11,    12,   325,    29,    31,    32,   329,
     149,   150,    32,    31,   334,     0,     6,    32,    33,    29,
      30,    31,   406,    29,    32,     1,    29,     3,     4,     5,
       6,    32,     8,    32,   173,    20,    11,   357,   358,    15,
      16,    17,   362,    32,    33,    10,    11,   186,   187,    10,
      11,    12,   191,    29,    34,    31,   376,    32,    33,    32,
      33,   381,   201,   202,   203,   204,   205,    32,    33,   149,
     150,    32,    33,   149,   150,     7,     8,     9,    10,    11,
      12,    13,    14,    32,   404,   405,    10,    11,    12,   409,
       6,    32,    33,   173,    32,    10,    11,   173,    30,    31,
      32,    33,    29,    30,    31,    21,   186,   187,    32,    32,
     186,   187,    32,    29,    29,    10,    11,   501,   502,   439,
      10,    11,   202,   203,   204,   205,   202,   203,   204,   205,
      32,   515,   516,    32,    33,     0,     1,    32,     3,     4,
       5,     6,    32,     8,    31,     9,    10,    11,    12,    31,
      15,    16,    17,    31,    19,    20,   476,    22,    23,    24,
      25,    26,    27,    31,   149,   150,    31,    29,    32,    34,
       1,    31,     3,     4,     5,     6,    31,     8,    31,   499,
     500,    32,    33,   567,    15,    16,    17,    18,   173,    31,
     574,   575,   576,   513,   514,    29,   580,   581,   582,     1,
      31,   186,   187,    10,    11,    12,    32,     0,    29,    30,
     530,     7,   532,    32,     6,    32,    33,   202,   203,   204,
     205,     3,     4,     5,     6,    32,     8,    20,    32,    21,
     614,   615,    29,    15,    16,    17,   556,    29,    10,    11,
       9,    10,    11,    12,   564,   565,    32,     7,     6,    31,
     570,   571,     6,   573,   574,   575,   576,    29,   578,   579,
     580,   581,   582,    32,    33,   499,   500,   651,   652,   653,
       7,     8,     9,    10,    11,    12,    13,    14,    29,   513,
     514,     7,     8,     9,    10,    11,    12,    13,    14,    10,
      11,    32,   612,   613,    31,    32,   530,   617,   618,   619,
     620,   621,   622,   623,   624,     1,    32,     3,     4,     5,
       6,    32,     8,   633,    32,     9,    10,    11,    12,    15,
      16,    17,   556,    32,    32,    32,    32,    32,    32,   649,
     650,   651,   652,   653,    29,    31,    32,   571,    32,   573,
     660,   661,   662,   663,   578,   579,     7,     8,     9,    10,
      11,    12,    13,    14,    10,    11,   149,   150,    35,    32,
     499,   500,     9,    10,    11,    12,    32,    32,    32,    30,
      31,    32,    33,    29,   513,   514,    29,    32,   612,   613,
     173,    32,    29,   617,   618,   619,   620,   621,   622,   623,
     624,    32,    35,   186,   187,     9,    10,    11,    12,   633,
      32,    29,     0,    29,    29,     9,    10,    11,    12,   202,
     203,   204,   205,    32,    29,   649,   650,   556,    32,   499,
     500,    31,    20,   499,   500,    29,   660,   661,   662,   663,
      31,    31,    31,   513,   514,    29,    29,   513,   514,   578,
     579,     0,     1,    29,     3,     4,     5,     6,    29,     8,
      29,     9,    10,    11,    12,    29,    15,    16,    17,    32,
      19,    20,    32,    22,    23,    24,    25,    26,    27,    32,
      32,    29,    31,   612,   613,    34,   556,    10,    11,    12,
     556,    32,   621,   622,   623,   624,    29,    35,    32,     9,
      10,    11,    12,    32,   633,    32,    29,    32,   578,   579,
      32,    32,   578,   579,     9,    10,    11,    12,    29,    32,
     649,   650,    32,    33,   499,   500,     9,    10,    11,    12,
      29,   660,   661,   662,   663,    29,    29,    32,   513,   514,
      32,    32,   612,   613,    20,   164,   612,   613,   182,    32,
      33,   621,   622,   623,   624,   621,   622,   623,   624,     7,
       8,   149,   150,   633,   114,    13,    14,   633,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,   649,
     650,   556,    -1,   649,   650,   173,    -1,    -1,    -1,    29,
     660,   661,   662,   663,   660,   661,   662,   663,   186,   187,
      10,    11,    12,   578,   579,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,   202,   203,   204,   205,    -1,    29,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,   612,   613,    34,
       3,     4,     5,     6,    -1,     8,   621,   622,   623,   624,
       7,     8,    15,    16,    17,    -1,    13,    14,   633,    -1,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    31,     9,
      10,    11,    12,    -1,   649,   650,     0,     1,    -1,     3,
       4,     5,     6,    32,     8,   660,   661,   662,   663,    29,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,     9,    10,    11,    12,   499,   500,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    10,    11,    12,
     513,   514,    29,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    29,    -1,    17,    31,
      -1,    -1,    34,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,   556,    -1,    44,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    31,    32,    56,    57,    58,
       9,    10,    11,    12,    -1,   578,   579,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      79,     7,     8,    32,    33,    -1,    -1,    13,    14,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,   612,
     613,    -1,    -1,    -1,    -1,    15,    16,    17,   621,   622,
     623,   624,    22,    23,    24,    25,    26,    27,   117,    -1,
     633,    31,    -1,    -1,    34,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,   649,   650,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,   660,   661,   662,
     663,    32,    33,    15,    16,    17,    -1,   156,    -1,    -1,
      22,    23,    24,   162,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,     7,     8,     9,    10,    11,    12,    13,
      14,   499,   500,     9,    10,    11,    12,    -1,    -1,   188,
     189,   190,    -1,    -1,    -1,   513,   514,     1,    32,     3,
       4,     5,     6,    -1,     8,    -1,    32,    33,     7,     8,
       9,    15,    16,    17,    13,    14,   215,    -1,    22,    23,
      24,    25,    26,    27,    -1,   224,    -1,    31,    -1,    -1,
      34,     9,    10,    11,    12,   234,   235,    -1,   556,    -1,
      -1,    -1,   241,   242,   243,   244,   245,   246,   247,   248,
       1,    29,     3,     4,     5,     6,    -1,     8,    -1,    -1,
     578,   579,    -1,    -1,    15,    16,    17,    -1,    -1,   268,
      -1,    22,    23,    24,    25,    26,    27,    -1,   277,    -1,
      31,    -1,    -1,    34,    -1,   284,   285,   286,   287,   288,
     289,   290,   291,    -1,   612,   613,    -1,     3,     4,     5,
       6,    -1,     8,   621,   622,   623,   624,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,   633,   315,   316,   317,   318,
     319,   320,   321,   322,   323,    31,   325,     7,     8,     9,
     329,   649,   650,    13,    14,   334,    -1,   336,     9,    10,
      11,    12,   660,   661,   662,   663,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,   356,   357,   358,
      -1,    32,    17,    15,    16,    17,    -1,   366,   367,   368,
     369,   370,   371,   372,   373,   374,    -1,   376,    -1,    31,
      32,    -1,   381,    -1,   383,    40,     9,    10,    11,    12,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    57,    58,   403,   404,   405,    -1,    -1,    32,
      33,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    79,    -1,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,     9,    10,    11,    12,
     439,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    32,
      34,    -1,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,   476,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    29,    31,    -1,    -1,    34,    -1,    -1,
      -1,   156,    -1,    -1,    -1,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,   188,   189,   190,    31,    -1,    -1,    34,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,     9,
      10,    11,    12,    -1,    15,    16,    17,    -1,    -1,    -1,
     215,     7,     8,     9,   563,   564,   565,    13,    14,   224,
      31,    32,    32,    33,    -1,   574,   575,   576,    -1,   234,
     235,   580,   581,   582,    -1,    -1,   241,   242,   243,   244,
     245,   246,   247,   248,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    -1,   268,    -1,    22,    23,    24,    25,    26,
      27,    -1,   277,    29,    31,    -1,    -1,    34,    -1,   284,
     285,   286,   287,   288,   289,   290,   291,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,   651,   652,   653,    15,    16,    17,    -1,    -1,
     315,   316,   317,   318,   319,   320,   321,   322,   323,    29,
     325,    31,    -1,    -1,   329,     9,    10,    11,    12,   334,
       1,   336,     3,     4,     5,     6,    -1,     8,    -1,     9,
      10,    11,    12,    -1,    15,    16,    17,    -1,    32,    33,
      -1,    -1,   357,   358,    -1,    17,    -1,    -1,    29,    29,
      31,   366,   367,   368,   369,   370,   371,   372,   373,   374,
      -1,   376,     9,    10,    11,    12,   381,    -1,   383,     9,
      10,    11,    12,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    29,    -1,    -1,    57,    58,    -1,    -1,   404,
     405,    -1,    32,    33,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    79,    -1,    -1,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,   439,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    -1,    -1,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,   476,    17,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,     1,   156,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    57,    58,    -1,     1,    -1,     3,     4,     5,
       6,    29,     8,    31,    -1,    -1,   188,   189,   190,    15,
      16,    17,    77,    -1,    79,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,     7,
       8,     9,    10,   215,    12,    13,    14,    -1,    -1,   564,
     565,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   574,
     575,   576,   234,   235,    -1,   580,   581,   582,    -1,   241,
     242,   243,   244,   245,   246,   247,   248,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    -1,   268,    -1,    22,    23,
      24,   156,    26,    27,    -1,   277,    -1,    31,    -1,    -1,
      34,    -1,   284,   285,   286,   287,   288,   289,   290,   291,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,   188,   189,   190,   651,   652,   653,    15,
      16,    17,    18,   315,   316,   317,   318,   319,   320,   321,
     322,   323,    -1,   325,    -1,    31,    -1,   329,    -1,    -1,
     215,    -1,   334,    -1,   336,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,     7,     8,     9,    10,   234,
      12,    13,    14,    -1,    -1,   357,   358,    -1,    17,    30,
      -1,    32,    33,    -1,   366,   367,   368,   369,   370,   371,
     372,   373,   374,    -1,   376,    -1,    -1,    -1,    -1,   381,
      -1,   383,    -1,   268,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      -1,    -1,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,   439,   323,    -1,
     325,    15,    16,    17,   329,     7,     8,     9,    10,   334,
      12,    13,    14,    -1,    -1,    29,    -1,    31,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,   357,   358,   476,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,   374,
      -1,   376,    31,    -1,    -1,    34,   381,   156,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,   404,
     405,    -1,    -1,    22,    23,    24,    25,    26,    27,   188,
     189,   190,    31,    -1,    -1,    34,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,   439,    -1,   215,    -1,    -1,    -1,
      -1,    -1,   564,   565,    29,   224,    31,    -1,    -1,    -1,
      -1,    -1,   574,   575,   576,   234,   235,    -1,   580,   581,
     582,    -1,   241,   242,   243,   244,   245,   246,   247,   248,
       1,   476,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,   268,
      -1,    22,    23,    24,    25,    26,    27,    -1,   277,    -1,
      31,    -1,    -1,    34,    -1,   284,   285,   286,   287,   288,
     289,   290,   291,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,   651,
     652,   653,    -1,    15,    16,    17,   315,   316,   317,   318,
     319,   320,   321,   322,   323,    -1,   325,    29,    -1,    31,
     329,    -1,    -1,    -1,    -1,   334,    -1,   336,    -1,   564,
     565,     7,     8,     9,    10,    11,    12,    13,    14,   574,
     575,   576,    -1,    -1,    -1,   580,   581,   582,   357,   358,
      -1,    17,    -1,    -1,    30,    31,    32,   366,   367,   368,
     369,   370,   371,   372,   373,   374,    -1,   376,    -1,    -1,
      -1,    -1,   381,    -1,   383,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    57,    58,    -1,    -1,   404,   405,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    79,    -1,    -1,   651,   652,   653,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
     439,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,   476,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,
     156,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,   188,   189,   190,    31,    -1,    -1,    34,    35,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,   215,
      -1,    -1,    -1,    -1,    -1,   564,   565,    -1,   224,    29,
      -1,    31,    -1,    -1,    -1,   574,   575,   576,   234,   235,
      -1,   580,   581,   582,    -1,   241,   242,   243,   244,   245,
     246,   247,   248,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,   268,    -1,    22,    23,    24,    25,    26,    27,
      -1,   277,    -1,    31,    -1,    -1,    34,    -1,   284,   285,
     286,   287,   288,   289,   290,   291,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,   651,   652,   653,    -1,    15,    16,    17,   315,
     316,   317,   318,   319,   320,   321,   322,   323,    -1,   325,
      29,    -1,    31,   329,    -1,    -1,    -1,    -1,   334,     1,
     336,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,   357,   358,    -1,    17,    -1,    -1,    -1,    -1,    31,
     366,   367,   368,   369,   370,   371,   372,   373,   374,    -1,
     376,    -1,    -1,    -1,    -1,   381,    -1,   383,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    -1,    -1,   404,   405,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,   439,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
     476,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,   156,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   188,   189,   190,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,   564,   565,
      -1,   224,    -1,    31,    -1,    -1,    -1,    -1,   574,   575,
     576,   234,   235,    -1,   580,   581,   582,    -1,   241,   242,
     243,   244,   245,   246,   247,   248,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,     1,   268,     3,     4,     5,     6,
      -1,     8,    -1,    -1,   277,    -1,    31,    -1,    15,    16,
      17,   284,   285,   286,   287,   288,   289,   290,   291,    -1,
      -1,    -1,    -1,    -1,    31,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,   651,   652,   653,    -1,    15,
      16,    17,   315,   316,   317,   318,   319,   320,   321,   322,
     323,    -1,   325,    -1,    -1,    31,   329,    -1,    -1,    -1,
      -1,   334,     1,   336,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,   357,   358,    -1,    17,    -1,    -1,
      -1,    -1,    31,   366,   367,   368,   369,   370,   371,   372,
     373,   374,    -1,   376,    -1,    -1,    -1,    -1,   381,    -1,
     383,    -1,     3,     4,     5,     6,    -1,     8,    48,    -1,
      -1,    -1,    52,    53,    15,    16,    17,    57,    58,    -1,
      -1,   404,   405,    -1,     3,     4,     5,     6,    -1,     8,
      31,    -1,    72,    -1,    74,    75,    15,    16,    17,    79,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    31,    -1,    -1,    -1,   439,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,   476,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    -1,   156,    -1,    -1,    -1,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,   188,   189,
     190,    31,    -1,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,     7,     8,     9,    -1,   215,    12,    13,    14,    -1,
      -1,   564,   565,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   574,   575,   576,   234,    -1,    -1,   580,   581,   582,
      -1,    -1,    -1,   243,   244,   245,   246,   247,   248,    -1,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,   268,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,   286,   287,   288,   289,
     290,   291,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,   651,   652,
     653,    15,    16,    17,    -1,   315,   316,   317,   318,    -1,
     320,   321,    17,   323,    -1,   325,    -1,    31,    -1,   329,
      -1,    -1,    -1,    -1,   334,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    47,    -1,     7,     8,     9,   357,   358,    12,
      13,    14,    57,    58,    -1,    31,   366,   367,   368,   369,
      -1,   371,   372,    -1,   374,    -1,   376,    -1,    73,    -1,
      -1,   381,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,   404,   405,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,   439,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,   156,    -1,    -1,    -1,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,   476,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,     3,     4,     5,     6,    30,
       8,    32,    33,   188,   189,   190,    17,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,     7,     8,     9,
     215,    -1,    12,    13,    14,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    57,    58,    -1,   234,
      15,    16,    17,    -1,    -1,    -1,    -1,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    31,    -1,    79,    -1,
      -1,    -1,    -1,    -1,   564,   565,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   268,   574,   575,   576,    -1,    -1,    -1,
     580,   581,   582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     285,   286,   287,   288,   289,   290,   291,     1,    -1,     3,
       4,     5,     6,    17,     8,     3,     4,     5,     6,    -1,
       8,    15,    16,    17,    -1,    -1,    -1,    15,    16,    17,
     315,   316,   317,   318,   319,   320,   321,    31,   323,    -1,
     325,    -1,    -1,    31,   329,   156,    -1,    51,    -1,   334,
      -1,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,   651,   652,   653,    -1,    -1,    -1,    71,    -1,    -1,
      -1,    -1,   357,   358,    -1,    79,    -1,   188,   189,   190,
      -1,   366,   367,   368,   369,   370,   371,   372,    -1,   374,
      -1,   376,    -1,    -1,    -1,     1,   381,     3,     4,     5,
       6,    -1,     8,    -1,   215,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,
     405,    -1,    -1,   234,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,   156,    -1,   439,    -1,    -1,   268,    15,    16,
      17,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    31,   286,   287,   288,   289,   290,
     291,    -1,    -1,    29,   188,   189,   190,     3,     4,     5,
       6,   476,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,   315,   316,   317,   318,    -1,   320,
     321,   215,   323,    -1,   325,    31,    -1,    -1,   329,    -1,
      -1,    -1,     1,   334,     3,     4,     5,     6,    -1,     8,
     234,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
     244,   245,   246,    -1,    -1,    -1,   357,   358,    -1,    -1,
      -1,    -1,    31,    -1,    -1,   366,   367,   368,   369,    -1,
     371,   372,    -1,   374,   268,   376,    -1,    -1,    -1,    -1,
     381,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,   564,
     565,    -1,    -1,   287,   288,   289,    -1,    -1,    -1,   574,
     575,   576,    -1,   404,   405,   580,   581,   582,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    49,    -1,
      -1,   315,   316,   317,    -1,    -1,    57,    58,    -1,   323,
      -1,   325,    31,    32,    33,   329,    -1,    -1,   439,    70,
     334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,   357,   358,    15,    16,    17,    -1,    -1,
      -1,    -1,   366,   367,   368,   476,   651,   652,   653,    -1,
     374,    31,   376,    -1,    -1,    -1,    -1,   381,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
     404,   405,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   156,    -1,    -1,    31,    -1,
      -1,    34,    -1,    -1,    -1,     1,    17,     3,     4,     5,
       6,    -1,     8,    -1,    -1,   439,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,
      -1,    -1,    -1,   564,   565,    31,    -1,    -1,    -1,    50,
      -1,    -1,    -1,   574,   575,   576,    57,    58,    -1,   580,
     581,   582,   476,    -1,   215,    -1,    -1,    -1,    69,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    79,    -1,
      -1,     0,     1,   234,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,   244,   245,    32,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    -1,   268,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
     651,   652,   653,    15,    16,    17,   287,   288,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    31,
     564,   565,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
     574,   575,   576,    32,   315,   316,   580,   581,   582,    -1,
      -1,    -1,   323,    -1,   325,    -1,    -1,    -1,   329,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,   188,   189,   190,
       3,     4,     5,     6,     1,     8,     3,     4,     5,     6,
      -1,     8,    15,    16,    17,    -1,   357,   358,    15,    16,
      17,    -1,    -1,    -1,   215,   366,   367,    -1,    31,    -1,
      -1,    -1,    -1,   374,    31,   376,    -1,    -1,    -1,    -1,
     381,    -1,    -1,   234,    -1,    -1,    -1,   651,   652,   653,
      -1,    -1,    -1,    -1,   245,     7,     8,     9,    10,    11,
      12,    13,    14,   404,   405,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,   268,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,   288,   439,    34,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,   315,     0,     1,    -1,     3,     4,
       5,     6,   323,     8,   325,   476,    31,    -1,   329,    -1,
      15,    16,    17,   334,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
       3,     4,     5,     6,    -1,     8,   357,   358,    -1,    -1,
      -1,    -1,    15,    16,    17,   366,     0,     1,    -1,     3,
       4,     5,     6,   374,     8,   376,    -1,    -1,    31,    -1,
     381,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,    -1,   404,   405,     1,    -1,     3,     4,     5,
       6,    -1,     8,   564,   565,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,   574,   575,   576,    -1,    -1,    -1,   580,
     581,   582,    -1,    -1,    -1,    31,     0,     1,   439,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,
      34,     3,     4,     5,     6,   476,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    31,
     651,   652,   653,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     0,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    -1,    -1,   564,   565,     7,     8,     9,    10,    11,
      12,    13,    14,   574,   575,   576,    -1,    -1,    -1,   580,
     581,   582,     1,    -1,     3,     4,     5,     6,    30,     8,
      32,    33,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
     651,   652,   653,    31,    -1,    -1,    34,    35,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,     0,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,     0,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,     1,    34,     3,     4,     5,     6,    -1,     8,
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
      -1,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     0,     1,    -1,     3,     4,     5,     6,
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
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     0,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     0,     1,    -1,     3,     4,     5,
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
      -1,    31,    -1,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,     1,     8,     3,     4,     5,     6,
      -1,     8,    15,    16,    17,    -1,    -1,    -1,    15,    16,
      17,    -1,     1,    -1,     3,     4,     5,     6,    31,     8,
      -1,    -1,    -1,    -1,    31,    -1,    15,    16,    17,     1,
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
      15,    16,    17,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    31,    15,    16,    17,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      31,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      30,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    30,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    30,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    30,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    30,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    31,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    30,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    30,    -1,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    30,    -1,
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
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    30,
      31,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    31,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    30,    -1,    32,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,    30,
      31,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      29,    30,    31,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    29,    -1,    31,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    29,    -1,    31,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    29,    30,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    29,    30,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      29,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    29,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    29,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      29,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    29,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    29,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      29,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    29,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    29,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      29,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,
      -1,    -1,    -1,    29,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14
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
      11,    12,    13,    14,    21,    21,    31,    31,    31,    31,
       1,    60,     1,    60,    50,     0,     1,    39,    29,    11,
      10,    12,     9,     8,    13,    14,     7,    30,    69,    31,
      29,    31,    75,    69,     1,    68,    69,     1,    66,     1,
      64,     1,    63,     1,    65,    66,    66,     1,    75,     1,
      18,    60,    78,     1,    60,     1,    60,    61,    29,    29,
      32,    32,    40,    51,    52,    53,    54,    76,     1,    63,
       1,    64,     1,    65,     1,    66,     1,    68,     1,    66,
       1,    66,     1,    69,     1,    62,     1,    60,    72,    73,
      44,    29,    30,    31,    32,    32,    32,    32,    32,    32,
      32,    29,    29,    35,    53,    75,    33,    32,     1,    46,
      47,    48,    76,     1,    42,    29,     1,    29,    29,     1,
      29,     1,    29,    25,    54,    25,    54,    61,     1,    61,
      60,    45,    33,    75,    46,    54,    25,    25,    29,    29,
      29,    32,    48,    43,    54,    54,    61,    61,     1,    61,
      49,    32,    32,    32,    32,    32,    49,    54,    54,    54,
      54,     3,     4,     5,     6,    31,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    74,    75,    77,     6,
       3,     4,     5,     6,    31,    70,    71,    74,    75,    77,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    19,
      20,    22,    23,    24,    26,    27,    34,    49,    55,    56,
      57,    58,    59,    60,     3,     4,     5,     6,    31,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    74,
      75,    77,     6,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    19,    20,    22,    23,    24,    26,    27,    34,
      49,    55,    56,    57,    58,    59,    60,    29,    30,     1,
       6,     1,    60,     1,    60,    11,    10,    12,     9,     8,
      13,    14,     7,    30,    69,    31,     1,    60,    69,    31,
       3,     4,     5,     6,    31,    69,    70,    71,    74,    75,
      77,     1,    68,    69,     1,    66,     1,    64,     1,    63,
       1,    65,    66,    66,    21,    21,    31,    31,    31,    31,
       1,    60,    50,    29,     1,    60,    11,    10,    12,     9,
       8,    13,    14,     7,    30,    69,    31,     3,     4,     5,
       6,    31,    69,    70,    71,    74,    75,    77,     1,    68,
      69,     1,    66,     1,    64,     1,    63,     1,    65,    66,
      66,    21,    21,    31,    31,    31,    31,     1,    60,    50,
      29,     1,    32,    32,     1,    63,     1,    64,     1,    65,
       1,    66,     1,    68,     1,    66,     1,    66,     1,    69,
       1,    62,    73,    32,    32,    73,     1,    60,    69,    31,
       1,    75,     1,    60,    78,     1,    60,     1,    61,    29,
      29,    51,    32,    32,     1,    63,     1,    64,     1,    65,
       1,    66,     1,    68,     1,    66,     1,    66,     1,    69,
       1,    62,    73,     1,    60,    69,    31,     1,    75,     1,
      60,    78,     1,    60,     1,    61,    29,    29,    51,    32,
      32,    32,    32,    73,    32,    32,    32,    32,    32,    32,
      32,    29,    29,    35,    32,    32,    32,    73,    32,    32,
      32,    32,    32,    32,    32,    29,    29,    35,    32,    29,
       1,    29,    29,     1,    29,     1,    29,    22,    23,    24,
      25,    26,    27,    34,    49,    54,    55,    56,    57,    58,
      59,    60,    25,    54,    61,     1,    61,    32,    29,     1,
      29,    29,     1,    29,     1,    29,    25,    54,    25,    54,
      61,     1,    61,    31,    31,    31,    54,    31,     1,    60,
      50,    25,    29,    25,    29,    29,    29,    54,    25,    25,
      29,    29,    29,     1,    75,     1,    60,    78,     1,    60,
       1,    61,    29,    29,    51,    54,    54,    61,    61,     1,
      61,    54,    54,    61,    61,     1,    61,    32,    32,    32,
      32,    32,    32,    32,    29,    29,    35,    32,    32,    32,
      32,    32,    32,    32,    32,    29,     1,    29,    29,     1,
      29,     1,    29,    25,    54,    25,    54,    61,     1,    61,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    25,
      25,    29,    29,    29,    54,    54,    61,    61,     1,    61,
      32,    32,    32,    32,    54,    54,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    38,    38,    39,    39,    39,
      40,    40,    40,    42,    43,    41,    44,    45,    41,    46,
      46,    47,    47,    47,    48,    50,    49,    51,    51,    52,
      52,    53,    53,    54,    54,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    57,    57,
      57,    57,    57,    57,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    61,    61,    62,    62,    62,    62,    63,
      63,    63,    63,    64,    64,    64,    64,    65,    65,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    67,    68,    68,    68,    68,    69,    69,    70,    70,
      70,    70,    71,    71,    72,    72,    72,    73,    73,    74,
      74,    74,    74,    75,    76,    76,    76,    76,    77,    77,
      77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       3,     2,     4,     0,     0,     8,     0,     0,     7,     0,
       1,     3,     1,     1,     2,     0,     4,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     5,     5,     5,     5,     5,     5,     2,     5,     7,
       5,     5,     7,     6,     3,     3,     9,     9,     9,     9,
       1,     3,     3,     0,     1,     1,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     1,     2,     1,     1,
       1,     1,     1,     4,     3,     1,     1,     1,     0,     1,
       1,     3,     3,     1,     1,     1,     2,     2,     1,     1,
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
#line 3847 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3853 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3859 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3865 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3871 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3877 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3883 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3889 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3895 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3901 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3907 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3913 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3919 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3925 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3931 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3937 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3943 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3949 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3955 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3961 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3967 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_1: /* @1  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3973 "src/bison/grammar.c"
        break;

    case YYSYMBOL_46_param_list_opt: /* param_list.opt  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3979 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3985 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3991 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3997 "src/bison/grammar.c"
        break;

    case YYSYMBOL_51_block_item_list_opt: /* block_item_list.opt  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4003 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4009 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4015 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4021 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4027 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4033 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4039 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4045 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4051 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4057 "src/bison/grammar.c"
        break;

    case YYSYMBOL_61_expression_opt: /* expression.opt  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4063 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4069 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4075 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4081 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4087 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4093 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4099 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4105 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4111 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4117 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4123 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4129 "src/bison/grammar.c"
        break;

    case YYSYMBOL_73_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 147 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4135 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4141 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 145 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 4147 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 144 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4153 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4159 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 146 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4165 "src/bison/grammar.c"
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
#line 4474 "src/bison/grammar.c"
    break;

  case 4: /* prog: error  */
#line 152 "src/bison/grammar.y"
            {
        // idk if this is the best solution
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
    }
#line 4483 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration_list external_declaration  */
#line 158 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4489 "src/bison/grammar.c"
    break;

  case 6: /* external_declaration_list: external_declaration  */
#line 159 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4495 "src/bison/grammar.c"
    break;

  case 9: /* external_declaration: statement  */
#line 164 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4505 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type id ';'  */
#line 171 "src/bison/grammar.y"
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
#line 4532 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 193 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4542 "src/bison/grammar.c"
    break;

  case 12: /* var_declaration: type id '=' error  */
#line 198 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4553 "src/bison/grammar.c"
    break;

  case 13: /* @1: %empty  */
#line 206 "src/bison/grammar.y"
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
#line 4594 "src/bison/grammar.c"
    break;

  case 14: /* $@2: %empty  */
#line 241 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4600 "src/bison/grammar.c"
    break;

  case 15: /* func_declaration: type id '(' @1 param_list.opt $@2 ')' compound_stmt  */
#line 241 "src/bison/grammar.y"
                                                              {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4610 "src/bison/grammar.c"
    break;

  case 16: /* $@3: %empty  */
#line 246 "src/bison/grammar.y"
               {
        previous_context = current_context;
        list_push(&contexts, context_init("invalid"));
        current_context = list_peek_last(&contexts);
        }
#line 4620 "src/bison/grammar.c"
    break;

  case 17: /* $@4: %empty  */
#line 250 "src/bison/grammar.y"
                         { is_fn_blck = true; }
#line 4626 "src/bison/grammar.c"
    break;

  case 18: /* func_declaration: type '(' $@3 param_list.opt $@4 ')' compound_stmt  */
#line 250 "src/bison/grammar.y"
                                                                  {
        show_error_range((yylsp[-5]), "expected identifier before " WHT "'('" RESET "\n");
        free((yyvsp[-6].pchar));
        LIST_FREE((yyvsp[-3].list), { ast_free(__IT__->data); });
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
        current_context = previous_context;
    }
#line 4639 "src/bison/grammar.c"
    break;

  case 19: /* param_list.opt: %empty  */
#line 260 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4645 "src/bison/grammar.c"
    break;

  case 21: /* params_list: params_list ',' param_decl  */
#line 264 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4651 "src/bison/grammar.c"
    break;

  case 22: /* params_list: param_decl  */
#line 265 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4657 "src/bison/grammar.c"
    break;

  case 23: /* params_list: error  */
#line 266 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4666 "src/bison/grammar.c"
    break;

  case 24: /* param_decl: type id  */
#line 272 "src/bison/grammar.y"
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
#line 4683 "src/bison/grammar.c"
    break;

  case 25: /* $@5: %empty  */
#line 286 "src/bison/grammar.y"
                   {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        if (!is_fn_blck) context_push_scope(current_context);
        is_fn_blck = false;
    }
#line 4693 "src/bison/grammar.c"
    break;

  case 26: /* compound_stmt: '{' $@5 block_item_list.opt '}'  */
#line 290 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 4705 "src/bison/grammar.c"
    break;

  case 27: /* block_item_list.opt: block_item_list  */
#line 299 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4711 "src/bison/grammar.c"
    break;

  case 28: /* block_item_list.opt: %empty  */
#line 300 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4717 "src/bison/grammar.c"
    break;

  case 29: /* block_item_list: block_item_list block_item  */
#line 303 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4723 "src/bison/grammar.c"
    break;

  case 30: /* block_item_list: block_item  */
#line 304 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4729 "src/bison/grammar.c"
    break;

  case 39: /* io_stmt: READ '(' id ')' ';'  */
#line 319 "src/bison/grammar.y"
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
#line 4745 "src/bison/grammar.c"
    break;

  case 40: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 330 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_builtinfn_init((yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4754 "src/bison/grammar.c"
    break;

  case 41: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 334 "src/bison/grammar.y"
                                       {
        (yyval.ast) = ast_builtinfn_init((yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4763 "src/bison/grammar.c"
    break;

  case 42: /* io_stmt: WRITE '(' error ')' ';'  */
#line 338 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4773 "src/bison/grammar.c"
    break;

  case 43: /* io_stmt: READ '(' error ')' ';'  */
#line 343 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4783 "src/bison/grammar.c"
    break;

  case 44: /* io_stmt: READ '(' id ')' error  */
#line 348 "src/bison/grammar.y"
                            {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4794 "src/bison/grammar.c"
    break;

  case 45: /* io_stmt: WRITE '(' expression ')' error  */
#line 354 "src/bison/grammar.y"
                                     {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4805 "src/bison/grammar.c"
    break;

  case 46: /* io_stmt: WRITE '(' string_literal ')' error  */
#line 360 "src/bison/grammar.y"
                                         {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4816 "src/bison/grammar.c"
    break;

  case 47: /* expr_stmt: expression ';'  */
#line 368 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 4822 "src/bison/grammar.c"
    break;

  case 48: /* cond_stmt: IF '(' expression ')' statement  */
#line 371 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 4830 "src/bison/grammar.c"
    break;

  case 49: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 374 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4838 "src/bison/grammar.c"
    break;

  case 50: /* cond_stmt: IF '(' expression ')' ELSE  */
#line 377 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4848 "src/bison/grammar.c"
    break;

  case 51: /* cond_stmt: IF '(' error ')' statement  */
#line 382 "src/bison/grammar.y"
                                            {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4858 "src/bison/grammar.c"
    break;

  case 52: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 387 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4869 "src/bison/grammar.c"
    break;

  case 53: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 393 "src/bison/grammar.y"
                                      {
        show_error((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4879 "src/bison/grammar.c"
    break;

  case 54: /* jmp_stmt: RETURN expression ';'  */
#line 400 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 4885 "src/bison/grammar.c"
    break;

  case 55: /* jmp_stmt: RETURN error ';'  */
#line 401 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 4894 "src/bison/grammar.c"
    break;

  case 56: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 407 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4902 "src/bison/grammar.c"
    break;

  case 57: /* iter_stmt: FOR '(' error ';' expression.opt ';' expression.opt ')' statement  */
#line 410 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-6]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4914 "src/bison/grammar.c"
    break;

  case 58: /* iter_stmt: FOR '(' expression.opt ';' error ';' expression.opt ')' statement  */
#line 417 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-4]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4926 "src/bison/grammar.c"
    break;

  case 59: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' error ')' statement  */
#line 424 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4938 "src/bison/grammar.c"
    break;

  case 61: /* expression: unary_expr '=' logical_or_expr  */
#line 434 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 4944 "src/bison/grammar.c"
    break;

  case 62: /* expression: unary_expr '=' error  */
#line 435 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4954 "src/bison/grammar.c"
    break;

  case 63: /* expression.opt: %empty  */
#line 442 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 4960 "src/bison/grammar.c"
    break;

  case 66: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 447 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4969 "src/bison/grammar.c"
    break;

  case 67: /* logical_or_expr: logical_or_expr OR error  */
#line 451 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4979 "src/bison/grammar.c"
    break;

  case 68: /* logical_or_expr: error OR logical_and_expr  */
#line 456 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4989 "src/bison/grammar.c"
    break;

  case 70: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 464 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4998 "src/bison/grammar.c"
    break;

  case 71: /* logical_and_expr: logical_and_expr AND error  */
#line 468 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5008 "src/bison/grammar.c"
    break;

  case 72: /* logical_and_expr: error AND eq_expr  */
#line 473 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5018 "src/bison/grammar.c"
    break;

  case 74: /* eq_expr: eq_expr EQ rel_expr  */
#line 481 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5027 "src/bison/grammar.c"
    break;

  case 75: /* eq_expr: eq_expr EQ error  */
#line 485 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5037 "src/bison/grammar.c"
    break;

  case 76: /* eq_expr: error EQ rel_expr  */
#line 490 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5047 "src/bison/grammar.c"
    break;

  case 78: /* rel_expr: rel_expr REL list_expr  */
#line 498 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5056 "src/bison/grammar.c"
    break;

  case 79: /* rel_expr: rel_expr REL error  */
#line 502 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5066 "src/bison/grammar.c"
    break;

  case 80: /* rel_expr: error REL list_expr  */
#line 507 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5076 "src/bison/grammar.c"
    break;

  case 82: /* list_expr: add_expr DL_DG list_expr  */
#line 515 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5085 "src/bison/grammar.c"
    break;

  case 83: /* list_expr: add_expr COLON list_expr  */
#line 519 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5094 "src/bison/grammar.c"
    break;

  case 84: /* list_expr: add_expr DL_DG error  */
#line 523 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5104 "src/bison/grammar.c"
    break;

  case 85: /* list_expr: add_expr COLON error  */
#line 528 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5114 "src/bison/grammar.c"
    break;

  case 86: /* list_expr: error DL_DG list_expr  */
#line 533 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5124 "src/bison/grammar.c"
    break;

  case 87: /* list_expr: error COLON list_expr  */
#line 538 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5134 "src/bison/grammar.c"
    break;

  case 89: /* add_expr: add_expr ADD mult_expr  */
#line 546 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5143 "src/bison/grammar.c"
    break;

  case 90: /* add_expr: add_expr ADD error  */
#line 550 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5153 "src/bison/grammar.c"
    break;

  case 91: /* add_expr: error ADD mult_expr  */
#line 555 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5163 "src/bison/grammar.c"
    break;

  case 93: /* mult_expr: mult_expr MULT unary_expr  */
#line 563 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5172 "src/bison/grammar.c"
    break;

  case 94: /* mult_expr: mult_expr MULT error  */
#line 567 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5182 "src/bison/grammar.c"
    break;

  case 95: /* mult_expr: error MULT unary_expr  */
#line 572 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5192 "src/bison/grammar.c"
    break;

  case 97: /* unary_expr: unary_ops unary_expr  */
#line 580 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5201 "src/bison/grammar.c"
    break;

  case 103: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 593 "src/bison/grammar.y"
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
#line 5224 "src/bison/grammar.c"
    break;

  case 104: /* arg_expr_list: arg_expr_list ',' expression  */
#line 613 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5230 "src/bison/grammar.c"
    break;

  case 105: /* arg_expr_list: expression  */
#line 614 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5236 "src/bison/grammar.c"
    break;

  case 106: /* arg_expr_list: error  */
#line 615 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5245 "src/bison/grammar.c"
    break;

  case 108: /* arg_expr_list.opt: %empty  */
#line 622 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5251 "src/bison/grammar.c"
    break;

  case 109: /* primary_expr: id  */
#line 625 "src/bison/grammar.y"
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
#line 5266 "src/bison/grammar.c"
    break;

  case 111: /* primary_expr: '(' expression ')'  */
#line 636 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 5272 "src/bison/grammar.c"
    break;

  case 112: /* primary_expr: '(' error ')'  */
#line 637 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5281 "src/bison/grammar.c"
    break;

  case 116: /* type: INT LIST  */
#line 648 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5293 "src/bison/grammar.c"
    break;

  case 117: /* type: FLOAT LIST  */
#line 655 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5305 "src/bison/grammar.c"
    break;

  case 118: /* constant: NUMBER_REAL  */
#line 664 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5311 "src/bison/grammar.c"
    break;

  case 119: /* constant: NUMBER_INT  */
#line 665 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5317 "src/bison/grammar.c"
    break;

  case 120: /* constant: NIL  */
#line 666 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5323 "src/bison/grammar.c"
    break;

  case 121: /* string_literal: STR_LITERAL  */
#line 669 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5332 "src/bison/grammar.c"
    break;


#line 5336 "src/bison/grammar.c"

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

#line 675 "src/bison/grammar.y"


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
