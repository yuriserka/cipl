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

    #define show_error_end(__R__, __FMT__, ...) {       \
        p_error_ctx_info;                               \
        Cursor beg = (Cursor){                          \
            .line=__R__.last_line - 1,                  \
            .col=__R__.last_column                      \
        };                                              \
        yyerror(beg.line, beg.col, NULL);               \
        LineInfo *li = list_peek(&lines, beg.line - 1); \
        li = li ? li : curr_line_info;                  \
        beg.col = strlen(li->text) + 1;                 \
        CIPL_PERROR_CURSOR(                             \
            __FMT__,                                    \
            li->text,                                   \
            beg,                                        \
            ##__VA_ARGS__                               \
        );                                              \
        yyerrok;                                        \
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


#line 172 "src/bison/grammar.c"

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
#define YYLAST   10521

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  667

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
       0,   149,   149,   150,   153,   154,   157,   158,   159,   166,
     188,   193,   201,   236,   201,   243,   247,   243,   259,   260,
     263,   264,   265,   271,   285,   285,   298,   299,   302,   303,
     306,   307,   310,   311,   312,   313,   314,   315,   318,   329,
     333,   337,   342,   347,   353,   359,   367,   370,   373,   376,
     381,   386,   392,   399,   400,   406,   409,   416,   423,   432,
     433,   434,   441,   442,   445,   446,   450,   455,   462,   463,
     467,   472,   479,   480,   484,   489,   496,   497,   501,   506,
     513,   514,   518,   522,   527,   532,   537,   544,   545,   549,
     554,   561,   562,   566,   571,   578,   579,   585,   586,   587,
     588,   591,   592,   612,   613,   614,   620,   621,   624,   634,
     635,   636,   642,   645,   646,   647,   654,   663,   664,   665,
     668
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

#define YYPACT_NINF (-360)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    5634,  4249,   859,  9950,  9962,  9900,   277,   501,   877,  3350,
     122,   148,   -23,   -10,    19,    79,  2455,  2556,  5666,   118,
    5702,  5734,  5766,  5798,  5830,  5862,  5894,  5926,  5958,  5990,
    6022,   102,   186,   202,   481,   300,   530,  3820, 10070,  9974,
    4386,  9986,  9998,  9912,    48, 10010,  8699,  2594,  2798,  2899,
    2937,  3138,  2798,  2798,   103,   121,     9,   190,  3242,   804,
   10082,   106,   252,   135,  6054,  -360,  6090,  6122,  3280,  3329,
    3481,  3585,  3623,  3890,  3972,  4099,  4218, 10022,    21,  6154,
      11,   557, 10093,   166, 10105, 10116,   670,   721,   382,   715,
    3150,   411,  1230,  1192,  1353,  1419,   158,   197,   582,   211,
     223,   225,  1245,   254, 10128,   267,   285,  6186,  6218, 10034,
   10046,  6250,   301,  6285,  6320,  6355,    34, 10139,   815, 10151,
    1016, 10162,  1480, 10174,  1567, 10185, 10197, 10208,  1674, 10220,
    1781, 10231, 10243, 10254,   239,   293,   -14,    28,   295,    13,
    6391,   346,    27,   325,     5,   364,     6,    10,    99,   950,
    1177,  1211,  6423,  6455,   247,  4302, 10058,   330,   373,   393,
     416,   450,  6491,    13,  6523,  6555,  6587,  6619,  6651,  6683,
    6715,  6747,  1479,    65,  6779,   222,   430, 10266,   437,   482,
     454,   563,   641,   468,  6811,  1479,  1479,   366,   366,   438,
     469,   684,   476,  6843,  6875,   479,   487,  9380,   498,  6907,
     469,  1479,  1479,  1479,  1479,  6939,  6971,  7003,  7035,  7067,
    9210,  9224,  9236,  1404,  4476,   109,   136,   525,   208,   341,
     680,  9392,  9250,  8716,  9262,  9276,  1907,  9288,   766, 10277,
   10289, 10300,  9925,  4581,  8699, 10312, 10323,  9937, 10335,   511,
    8733,  4691,  4827,  8114,  8120,  8138,  4827,  4827,   203,   337,
     517,   523,   534,   540,  8155,  5666,  7099,  7134,  7169,  7204,
    7239,  7274,   527,   595,  1561,  4009,   150,  8172,    61,   241,
     425,   367,   462,   401,   979,  4172,  8750,  4525,  8778,   514,
    8792,   690,  7309,  8767,  8189,  8206,  8223,  8240,  8257,  8206,
    8206,   292,   338,   545,   566,   579,   593,  8274,  5666,   315,
     998,  1038,  1075,  1311,  1352,   597,  7344,   639, 10496,   727,
   10507,   610,  9406,   615,  8291,  8308,  8325,  8342,  8359,  8376,
    8393,  8410,  8427,  9302,    21,  9418,   625, 10346,    21,  9432,
    9444,  9458,  9314,  8444,  9470,  8733,  9484,  9496,  9328,  9510,
     675,  9522,  9536,  1060,   375,   622,   726,  3493,   160,  1827,
     420,   634,   772,    68,    69,   316,  1116,  8461,  1393, 10358,
     642,  6054,  7379,  9548,   653,  8478,  8495,  8512,  8529,  8546,
    8563,  8580,  8597,  8614,  8805,    21,  8886,  8900,  8913,  8819,
    8631,  8927,  8767,  8940,  8954,  8832,  8967,   704,  8981,  8994,
    1122,   757,  3636,   643,  4137,   452,  1945,   791,  1254,  1259,
     707,   737,   354,  1524,  8648,  1659, 10369,   728,  6054,  1437,
    7414,  9340,  9354,  9562,   259,  9574,   932,  9588,   831,  9600,
    1076,  9614,  9626,  9640,  1286,  9652,  1312,  9666,  9678,  9692,
     133,   723, 10381, 10392,   738,  9704,   740,  9718,    21,   743,
     744,  9730,   754,   774,  9744,   779, 10404,   784,  7449,  7484,
     783,  8846,  8859,  9008,   457,  9021,   689,  9035,  1608,  9048,
    1646,  9062,  9075,  9089,  1722,  9102,  1769,  9116,  9129,  9143,
     167,   790,  9756,   797,  9156,    21,   799,   800,  9770,   813,
     817,  9782,   818, 10415,   822,  1694,  2002,   819,  9366, 10427,
    9796,  9808,   823,   829,    12,   830,    47,    54,  1140,  1734,
    1177,  1768,  7519,  8873,  9170,  9183,   842,   833,    66,   850,
     100,   107,  1822,  2165,  1177,  1871,  2037,  9822,  7554,  7589,
    7624,  7659,  7694,  7729,  7764,  7799,   853,   873,   874,  3194,
     875,  8665,  5666,  2077,  2342,  2379,  2420,  2685,  2722,  2763,
     880,  7834,  3028,   881, 10438,   883,  9197,  3065,  3106,  3371,
    3408,  3449,  3539,  3680,  3716,  4044,  3753,  3790,  4265,   884,
   10450,   885,   444,  2112,  8682,  7869,  2214, 10461,   887,  6054,
    3194,  4353,  3194,   366,   366,   664,  4544,  4044,  4044,   366,
     366,   748,   889,   900,  9834,   901,   915,  9848,   916, 10473,
     920,  4602,  4653,   917,  7904,  7939,   918,   925,  9860,   929,
    4723,  4760,   930,   931,  9874,   946,   953,   110,   954,   111,
     116,  2508,  2851,  1177,  2251,  4792,  3194,  3194,  3194,  3194,
    4044,  4044,  4044,  4044,  4868,  4909,  4944,  4979,  5014,  5049,
    5084,  5119,  4406,  5154,  5189,  5224,   956, 10484,   965,  7974,
    8009,  8044,  8079,  5260,  5292,  5324,  5356,  5388,  4406,  4406,
     366,   366,   914,  5423,  5458,   947,   963,  9886,   968,  4406,
    4406,  4406,  4406,  5493,  5528,  5563,  5598
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
       0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -360,  -360,  -360,   985,    42,  -360,  -360,  -360,  -360,  -360,
     856,  -360,   835,   216,  -254,  -359,  -360,   921,    86,   275,
     279,   348,   538,   613,     0,   -13,  1349,  4287,  4138,  3875,
    3290,  3768,  3594,  1575,  1918,  2261,  -360,  -319,  2604,  1232,
       3,  2947,  -352
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   111,    23,   163,   192,   139,   180,
     158,   159,   160,   256,    64,   112,   113,   114,   115,   257,
     258,   259,   260,   261,   105,   106,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   137,   138,    42,    43,
     116,    45,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   361,   450,    44,   443,   431,   165,   168,    56,   434,
      96,   170,   -15,   519,   157,   239,    61,    63,  -104,  -104,
      31,    57,   135,    44,   263,   264,   265,   266,   -12,     6,
     -15,   -15,   291,   292,   166,   169,     7,     8,     9,   171,
     281,   520,    22,   -15,   408,   -18,   -12,   -12,   522,   487,
      58,   480,   267,  -107,   228,   524,   471,   100,   103,   -12,
    -106,   155,    22,   282,   262,   -50,   -50,   548,   -50,   -50,
     -50,   -50,   365,   -50,  -115,  -116,   523,    79,   136,    80,
     -50,   -50,   -50,   525,   -50,   -50,    25,   -50,   -50,   -50,
     185,   -50,   -50,   -59,   -59,   549,   -50,  -115,  -116,   -50,
       1,   551,     2,     3,     4,     5,    25,     6,   553,  -115,
      59,   625,   628,   262,     7,     8,     9,   630,    65,   492,
     314,   293,   294,   295,   172,   296,   297,  -116,  -113,   552,
      17,    67,  -115,   298,  -115,   108,   554,   176,   178,   626,
     629,   -59,   161,    54,   314,   631,   315,   -64,   305,   305,
    -116,  -113,  -116,  -113,  -114,   179,   506,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,   -60,   161,   110,   -64,    55,
     315,   -67,    31,    46,   195,   196,   198,  -114,   365,  -114,
    -112,  -112,  -112,  -112,   161,    31,    31,   311,   311,   311,
     143,    98,   -67,   210,   211,   212,   213,    68,     6,   -60,
     -60,    31,    31,    31,    31,     7,     8,     9,    99,  -113,
     593,   586,    69,   -64,   313,   -59,    24,   317,   -72,   -72,
     -72,   214,   -47,   -47,   353,   -47,   -47,   -47,   -47,   144,
     -47,   -64,  -113,   326,   173,   175,    24,   -47,   -47,   -47,
     -72,   -47,   -47,  -120,   -47,   -47,   -47,   186,   -47,   -47,
      68,   366,   -64,   -47,   360,   146,   -47,   147,   184,   240,
     241,   242,   243,   244,   245,   246,   247,   364,   -60,   315,
     -65,   193,   194,   -64,   -64,    26,   306,   307,   569,    27,
     -99,   -99,   -99,   -99,   109,   -99,   149,   206,   207,   208,
     209,   -65,   -99,   -99,   -99,    26,   -63,   407,  -113,    27,
     283,   284,   285,   286,   287,   288,   289,   290,   -99,    71,
     -72,   -72,   -72,   400,   151,   -33,   -33,   439,   -33,   -33,
     -33,   -33,   239,   -33,   136,  -105,  -105,   156,   136,   -72,
     -33,   -33,   -33,   436,   -33,   -33,   152,   -33,   -33,   -33,
     -33,   -33,   -33,  -114,  -114,   447,   -33,   162,    28,   -33,
     -76,   -76,   -76,   -76,   164,   476,   442,   445,   354,   401,
     239,   262,   -22,   -22,   299,   299,  -114,   310,    28,   210,
     211,   212,   213,   -76,     6,   136,   368,   -72,   -72,   -72,
     473,     7,     8,     9,   -79,   -79,   -79,   -79,    24,    46,
      47,    48,   484,   167,    51,    52,    53,   214,   -62,   -72,
     -72,    24,    24,   479,   482,   -16,   199,   -79,   262,   369,
     -80,   -80,   -80,   -80,   370,   371,   205,    24,    24,    24,
      24,    69,   -67,   300,   300,   -19,   181,   301,   301,   317,
     -75,   -75,   -75,   -80,   -80,   -68,   -68,   367,   136,   197,
     -67,   210,   211,   212,   213,   582,     6,    26,   -21,   -21,
     239,    27,   -75,     7,     8,     9,   309,   -68,   -68,   187,
      26,    26,   366,   -67,    27,    27,   189,   366,   -65,   214,
     -62,   -76,   -76,   -76,   -76,   136,    26,    26,    26,    26,
      27,    27,    27,    27,   -67,   -67,   190,   543,   545,   -65,
     -65,   -68,   -68,    70,   -76,   -76,   302,   302,   540,   540,
     -13,   559,   561,    18,   -97,   -97,   -97,   -97,   200,   -97,
     -68,   201,   305,   305,  -103,  -103,   -97,   -97,   -97,   202,
      28,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,   262,
     204,   568,   -97,    28,    28,   -68,   -68,   316,    29,   -76,
     -76,   -76,   -76,  -112,  -108,   375,  -108,  -108,   355,    28,
      28,    28,    28,   590,   356,   305,   362,   -68,    29,   -76,
     596,   597,   599,   585,   588,   357,   602,   603,   605,   262,
     262,   358,   262,   311,   311,   311,   402,   305,   305,   311,
     311,   311,   291,   292,   534,   542,   140,   141,   142,   240,
     241,   242,   243,   244,   245,   246,   247,   403,   556,   558,
     636,   638,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
     404,   540,   540,    30,   145,   565,   262,   262,   262,   262,
     305,   305,   305,   305,   405,  -118,   409,  -118,  -118,   240,
     241,   242,   540,    30,   245,   246,   247,   655,   656,   658,
     410,   576,   -63,   -86,   -86,   -86,   -86,   412,   540,   540,
     311,   311,   311,   -71,   -71,   367,   594,   433,   595,   540,
     540,   540,   540,   600,   601,   598,   -86,   210,   211,   212,
     213,   449,     6,   -23,   -23,   -71,   -71,    46,    47,     7,
       8,     9,   240,    52,    53,   452,   303,   303,   318,   -80,
     -80,   -80,   -80,   319,   320,   214,   -62,   633,   635,   -69,
     -69,   367,   639,   640,   641,   642,   643,   644,   645,   646,
      29,   283,   -80,  -115,   533,   533,   -20,   -20,   647,  -112,
    -112,   -69,   -69,    29,    29,   -71,   -71,    70,   299,   299,
     -79,   -79,   -79,   -79,   653,   654,   -71,   -71,   316,    29,
      29,    29,    29,  -116,   -71,   663,   664,   665,   666,   604,
     -79,   210,   211,   212,   213,   488,     6,   486,   -71,  -112,
    -112,   304,   304,     7,     8,     9,   -79,   -79,   -79,   -79,
     489,   299,   491,   535,   535,   493,   494,   536,   536,   214,
     -62,   -85,   -85,   -85,   -85,    30,   496,   300,   300,   -79,
     -79,   301,   301,   299,   299,  -112,  -112,  -112,    30,    30,
     368,   -75,   -75,   -75,   -85,   104,   497,     2,     3,     4,
       5,   499,     6,   501,    30,    30,    30,    30,   502,     7,
       8,     9,   503,   -75,   -75,    69,   -65,   533,   533,   505,
     300,   507,   508,   -62,   301,    17,   299,   299,   299,   299,
     317,   -73,   -73,   -73,   -65,   510,   537,   537,   533,   511,
     513,   515,   300,   300,   516,   517,   301,   301,   518,   521,
     302,   302,   547,   -73,   533,   533,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,   546,   533,   533,   533,   533,   550,
     -98,   -98,   -98,   -98,   562,   -98,   535,   535,  -118,  -118,
     536,   536,   -98,   -98,   -98,   300,   300,   300,   300,   301,
     301,   301,   301,   302,   563,   564,   566,   535,   -98,   571,
     573,   536,   575,   579,   581,   657,   592,   210,   211,   212,
     213,   606,     6,   535,   535,   302,   302,   536,   536,     7,
       8,     9,   607,   609,   535,   535,   535,   535,   536,   536,
     536,   536,   -69,   -69,   316,   214,   -62,   610,   612,   614,
     616,     1,   615,     2,     3,     4,     5,   617,     6,   537,
     537,   619,   620,   621,   -69,     7,     8,     9,   302,   302,
     302,   302,   293,   294,   295,   174,   296,   297,   623,   659,
     537,    17,   624,   627,   298,   650,   372,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   652,   660,   537,   537,   -37,   -37,
     662,   -37,   -37,   -37,   -37,    66,   -37,   537,   537,   537,
     537,   -87,   -87,   -37,   -37,   -37,   191,   -37,   -37,   183,
     -37,   -37,   -37,   -37,   -37,   -37,   -69,   -69,    70,   -37,
       0,     0,   -37,     0,   153,     0,   538,   538,   -32,   -32,
       0,   -32,   -32,   -32,   -32,   -69,   -32,     0,     0,     0,
     303,   303,     0,   -32,   -32,   -32,     0,   -32,   -32,     0,
     -32,   -32,   -32,   -32,   -32,   -32,     0,   240,   241,   -32,
       0,     0,   -32,   246,   247,   -34,   -34,     0,   -34,   -34,
     -34,   -34,     0,   -34,     0,   -77,   -77,   -77,   -77,     0,
     -34,   -34,   -34,   303,   -34,   -34,     0,   -34,   -34,   -34,
     -34,   -34,   -34,     0,     0,     0,   -34,     0,   -77,   -34,
       0,   539,   539,     0,     0,   303,   303,   441,     0,   210,
     211,   212,   213,     0,     6,   304,   304,     0,     0,   283,
     284,     7,     8,     9,    99,   289,   290,     0,     0,     0,
       0,     1,     0,     2,     3,     4,     5,   214,     6,   538,
     538,     0,     0,     0,     0,     7,     8,     9,   303,   303,
     303,   303,   526,   527,   528,   529,   530,   531,   304,     0,
     538,    17,     0,     0,   532,     0,     0,     0,     1,     0,
       2,     3,     4,     5,     0,     6,   538,   538,     0,     0,
     304,   304,     7,     8,     9,     0,     0,   538,   538,   538,
     538,    71,   -75,   -75,   -75,     0,   -62,     0,    17,     0,
       0,     0,   177,     0,     2,     3,     4,     5,     0,     6,
       0,   -75,     0,     0,   539,   539,     7,     8,     9,     0,
       0,     0,     0,   304,   304,   304,   304,    46,    47,    48,
     -62,     0,    17,    52,    53,   539,     0,     0,     0,   226,
       0,     0,   240,   241,   242,   243,   244,   245,   246,   247,
       0,   539,   539,   -86,   -86,   -86,   -86,     0,   -85,   -85,
     -85,   -85,   539,   539,   539,   539,    81,   148,   237,   237,
     237,   237,   237,   237,   237,   237,   -86,   -86,    97,   226,
     226,   -85,   -85,     0,     0,   -82,   -82,   -82,   -82,     0,
     237,   237,   237,   237,   237,   237,   237,   237,   237,     0,
     279,   -35,   -35,     0,   -35,   -35,   -35,   -35,   -82,   -35,
       0,   -81,   -81,   -81,   -81,     0,   -35,   -35,   -35,     0,
     -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,     0,   -35,     0,   -81,   -35,     0,     0,   154,     0,
       0,     0,   -36,   -36,     0,   -36,   -36,   -36,   -36,     0,
     -36,     0,   -86,   -86,   -86,   -86,   215,   -36,   -36,   -36,
       0,   -36,   -36,     0,   -36,   -36,   -36,   -36,   -36,   -36,
       0,     0,   -86,   -36,     0,     0,   -36,   279,     0,     0,
       0,     0,     0,   182,   446,     0,     2,     3,     4,     5,
       0,     6,     0,     0,     0,     0,   215,   215,     7,     8,
       9,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,   226,
     226,   226,   -62,     0,    17,   134,     0,   268,   -85,   -85,
     -85,   -85,     0,     0,  -112,  -112,  -112,   -46,   -46,     0,
     -46,   -46,   -46,   -46,     0,   -46,   226,     0,   -85,     0,
       0,     0,   -46,   -46,   -46,   226,   -46,   -46,     0,   -46,
     -46,   -46,   -46,   -46,   -46,   226,   237,     0,   -46,     0,
       0,   -46,   338,   338,   338,   338,   338,   338,   338,   338,
       1,     0,     2,     3,     4,     5,     0,     6,     0,    71,
     -73,   -73,   -73,     0,     7,     8,     9,     0,     0,   226,
       0,    12,    13,    14,   268,    15,    16,     0,   279,   -73,
      17,     0,     0,    18,     0,   385,   385,   385,   385,   385,
     385,   385,   385,     0,     0,   478,     0,   210,   211,   212,
     213,     0,     6,     0,     0,     0,   215,   215,   215,     7,
       8,     9,    99,     0,     0,     0,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   214,   279,     0,     0,     0,
     279,     0,     0,   215,     0,   226,     0,   338,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,   -77,   -77,   -77,   -77,
       0,     0,   215,     0,     0,     0,     0,   440,   226,   226,
       0,  -119,   222,  -119,  -119,     0,   -77,   385,   385,   385,
     385,   385,   385,   385,   385,   385,     0,   279,     0,     0,
       0,     0,   226,     0,   385,    77,   215,   368,   -73,   -73,
     -73,    82,    85,    85,    85,    85,    85,    85,    85,     0,
       0,     0,   222,   222,   477,   226,   226,     0,     0,     0,
     -73,   -73,     0,    85,    85,    85,    85,    85,    85,    85,
     132,    85,     0,   275,     0,   -77,   -77,   -77,   -77,     0,
     483,     0,     2,     3,     4,     5,     0,     6,     0,     0,
     279,   430,     0,   268,     7,     8,     9,   268,   -77,   -77,
       0,     0,   215,   -82,   -82,   -82,   -82,     0,   -62,     0,
      17,     0,     0,     0,   -54,   -54,     0,   -54,   -54,   -54,
     -54,     0,   -54,   -82,     0,   215,   215,   279,     0,   -54,
     -54,   -54,     0,   -54,   -54,     0,   -54,   -54,   -54,   -54,
     -54,   -54,   470,     0,   268,   -54,     0,     0,   -54,   215,
     275,   -82,   -82,   -82,   -82,     1,     0,     2,     3,     4,
       5,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,   215,   215,   -82,   -82,   526,   527,   528,   541,
     530,   531,   222,   222,   222,    17,     0,     0,   532,   544,
       0,     2,     3,     4,     5,     0,     6,     0,   -81,   -81,
     -81,   -81,     0,     7,     8,     9,     0,   268,     0,   222,
     -81,   -81,   -81,   -81,   583,   226,   226,   -62,   323,    17,
       0,   -81,   -81,     0,     0,   226,   226,   226,   222,   327,
     -81,   226,   226,   226,     0,   334,   342,   342,   342,   342,
     342,   342,   342,     1,   268,     2,     3,     4,     5,     0,
       6,     0,     0,     0,   240,   241,   242,     7,     8,     9,
     246,   247,   222,     0,   293,   294,   295,   555,   296,   297,
       0,   374,     0,    17,     0,     0,   298,     0,   381,   389,
     389,   389,   389,   389,   389,   389,     0,     0,     0,     0,
       0,     0,   560,     0,     2,     3,     4,     5,     0,     6,
       0,     0,   226,   226,   226,     0,     7,     8,     9,   342,
     342,   342,   342,   342,   342,   342,   428,   342,     0,   275,
     -62,     0,    17,   275,     0,     0,     0,     0,   222,     0,
     437,     0,   215,   215,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,   215,   215,   215,     0,     0,     0,   215,   215,
     215,   222,   222,     0,     0,   223,     0,  -108,   324,  -108,
     389,   389,   389,   389,   389,   389,   389,   468,   389,     0,
     275,     0,   283,   284,   285,   222,     0,   474,   289,   290,
       0,     0,     0,     0,   234,   234,   234,   234,   234,   234,
     234,   234,     0,     0,     0,   223,   223,     0,   222,   222,
       0,     0,     0,     0,     0,     0,   234,   234,   234,   234,
     234,   234,   234,   234,   234,     0,   276,     0,     0,   215,
     215,   215,   -53,   -53,     0,   -53,   -53,   -53,   -53,     0,
     -53,     0,     0,   275,     0,     0,     0,   -53,   -53,   -53,
       0,   -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,   -53,
       0,     0,     0,   -53,     0,     0,   -53,   -25,   -25,     0,
     -25,   -25,   -25,   -25,     0,   -25,     0,     0,     0,     0,
     275,     0,   -25,   -25,   -25,     0,   -25,   -25,     0,   -25,
     -25,   -25,   -25,   -25,   -25,     0,     0,     0,   -25,     0,
       0,   -25,     0,   276,     0,     0,     0,     0,   -33,     0,
     -33,   -33,   -33,   -33,     0,   -33,     0,     0,     0,     0,
       0,     0,   -33,   -33,   -33,     0,   -33,   -33,     0,   -33,
     -33,   -33,   -33,   -33,   -33,   223,   223,   223,   -33,     0,
       0,   -33,   -33,   584,     0,   210,   211,   212,   213,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
      99,     0,   223,     0,     0,     0,     0,     0,   222,   222,
       0,   223,     0,   214,     0,     0,     0,     0,   222,   222,
     222,   223,   234,     0,   222,   222,   222,     0,   335,   335,
     335,   335,   335,   335,   335,   335,     1,     0,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,     0,   223,     0,   293,   294,   295,
     557,   296,   297,     0,   276,     0,    17,     0,     0,   298,
       0,   382,   382,   382,   382,   382,   382,   382,   382,     0,
       0,     0,     0,     0,     0,   589,     0,     2,     3,     4,
       5,     0,     6,     0,     0,   222,   222,   222,     0,     7,
       8,     9,   335,   335,   335,   335,   335,   335,   335,   335,
     335,     0,   276,   -62,     0,    17,   276,     0,     0,     0,
       0,   223,   637,   335,     2,     3,     4,     5,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,     0,     0,     0,   223,   223,     0,     0,   224,     0,
     -62,     0,    17,   382,   382,   382,   382,   382,   382,   382,
     382,   382,     0,   276,     0,     0,     0,     0,   223,     0,
     382,     0,     0,     0,     0,     0,     0,   235,   235,   235,
     235,   235,   235,   235,   235,     0,     0,     0,   224,   224,
       0,   223,   223,     0,     0,     0,     0,     0,     0,   235,
     235,   235,   235,   235,   235,   235,   235,   235,     0,   277,
       0,     0,     0,   -50,     0,   -50,   -50,   -50,   -50,     0,
     -50,     0,     0,     0,     0,     0,   276,   -50,   -50,   -50,
       0,   -50,   -50,     0,   -50,   -50,   -50,   570,   -50,   -50,
       0,     0,     0,   -50,     0,     0,   -50,   -50,     0,     0,
     -37,     0,   -37,   -37,   -37,   -37,     0,   -37,     0,     0,
       0,     0,     0,   276,   -37,   -37,   -37,     0,   -37,   -37,
       0,   -37,   -37,   -37,   -37,   -37,   -37,     0,     0,     0,
     -37,     0,     0,   -37,   -37,     0,   277,     0,     0,     0,
       0,   -32,     0,   -32,   -32,   -32,   -32,     0,   -32,     0,
       0,     0,     0,     0,     0,   -32,   -32,   -32,     0,   -32,
     -32,     0,   -32,   -32,   -32,   -32,   -32,   -32,   224,   224,
     224,   -32,     0,     0,   -32,   -32,    60,     0,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,     0,   224,     0,     0,     0,     0,
       0,   223,   223,     0,   224,     0,    17,     0,     0,     0,
       0,   223,   223,   223,   224,   235,     0,   223,   223,   223,
       0,   336,   336,   336,   336,   336,   336,   336,   336,     1,
       0,     2,     3,     4,     5,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,   224,     0,
     526,   527,   528,   632,   530,   531,     0,   277,     0,    17,
       0,     0,   532,     0,   383,   383,   383,   383,   383,   383,
     383,   383,     0,     0,     0,     0,     0,    62,     0,   210,
     211,   212,   213,     0,     6,     0,     0,     0,   223,   223,
     223,     7,     8,     9,     0,   336,   336,   336,   336,   336,
     336,   336,   336,   336,     0,   277,     0,   214,     0,   277,
       0,     0,     0,     0,   224,    83,   336,   229,   230,   231,
     232,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,     0,   224,   224,     0,
       0,   225,     0,     0,     0,   233,   383,   383,   383,   383,
     383,   383,   383,   383,   383,     0,   277,     0,     0,     0,
       0,   224,     0,   383,     0,     0,     0,     0,     0,     0,
     236,   236,   236,   236,   236,   236,   236,   236,     0,     0,
       0,   225,   225,     0,   224,   224,     0,     0,     0,     0,
       0,     0,   236,   236,   236,   236,   236,   236,   236,   236,
     236,     0,   278,     0,     0,     0,   -34,     0,   -34,   -34,
     -34,   -34,     0,   -34,     0,     0,     0,     0,     0,   277,
     -34,   -34,   -34,     0,   -34,   -34,     0,   -34,   -34,   -34,
     -34,   -34,   -34,     0,     0,     0,   -34,     0,     0,   -34,
     -34,     0,     0,   -35,     0,   -35,   -35,   -35,   -35,     0,
     -35,     0,     0,     0,     0,     0,   277,   -35,   -35,   -35,
       0,   -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,
       0,     0,     0,   -35,     0,     0,   -35,   -35,     0,   278,
       0,     0,     0,     0,   -36,     0,   -36,   -36,   -36,   -36,
       0,   -36,     0,     0,     0,     0,     0,     0,   -36,   -36,
     -36,     0,   -36,   -36,     0,   -36,   -36,   -36,   -36,   -36,
     -36,   225,   225,   225,   -36,     0,     0,   -36,   -36,    86,
       0,   229,   230,   231,   232,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,   225,     0,
       0,     0,     0,     0,   224,   224,     0,   225,     0,   233,
       0,     0,     0,     0,   224,   224,   224,   225,   236,     0,
     224,   224,   224,     0,   337,   337,   337,   337,   337,   337,
     337,   337,     1,     0,     2,     3,     4,     5,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,   225,     0,   526,   527,   528,   634,   530,   531,     0,
     278,     0,    17,     0,     0,   532,     0,   384,   384,   384,
     384,   384,   384,   384,   384,     0,     0,     0,     0,     0,
      88,     0,   229,   230,   231,   232,     0,     6,     0,     0,
       0,   224,   224,   224,     7,     8,     9,     0,   337,   337,
     337,   337,   337,   337,   337,   337,   337,     0,   278,     0,
     233,     0,   278,     0,     0,     0,     0,   225,    90,   337,
     229,   230,   231,   232,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,     0,     0,     0,     0,
     225,   225,     0,     0,   227,     0,     0,     0,   233,   384,
     384,   384,   384,   384,   384,   384,   384,   384,     0,   278,
       0,     0,     0,     0,   225,     0,   384,     0,     0,     0,
       0,     0,     0,   238,   238,   238,   238,   238,   238,   238,
     238,     0,     0,     0,   227,   227,     0,   225,   225,     0,
       0,     0,     0,     0,     0,   238,   238,   238,   238,   238,
     238,   238,   238,   238,     0,   280,     0,     0,     0,   -47,
       0,   -47,   -47,   -47,   -47,     0,   -47,     0,     0,     0,
       0,     0,   278,   -47,   -47,   -47,     0,   -47,   -47,     0,
     -47,   -47,   -47,   572,   -47,   -47,     0,     0,     0,   -47,
       0,     0,   -47,   -47,     0,   -42,   -42,     0,   -42,   -42,
     -42,   -42,     0,   -42,     0,     0,     0,     0,     0,   278,
     -42,   -42,   -42,     0,   -42,   -42,     0,   -42,   -42,   -42,
     -42,   -42,   -42,     0,     0,     0,   -42,     0,     0,   -42,
       0,     0,   280,     0,     0,     0,   -43,   -43,     0,   -43,
     -43,   -43,   -43,     0,   -43,     0,     0,     0,     0,     0,
       0,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,
     -43,   -43,   -43,   -43,   227,   227,   227,   -43,     0,    92,
     -43,   229,   230,   231,   232,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,    46,    47,    48,
      49,   227,    51,    52,    53,     0,     0,   225,   225,   233,
     227,     0,     0,     0,     0,     0,     0,   225,   225,   225,
     227,   238,     0,   225,   225,   225,     0,   339,   339,   339,
     339,   339,   339,   339,   339,     1,     0,     2,     3,     4,
       5,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,   227,     0,   250,   251,   252,     0,
     253,   254,     0,   280,     0,    17,     0,     0,   255,     0,
     386,   386,   386,   386,   386,   386,   386,   386,     0,     0,
       0,     0,     0,   102,     0,   210,   211,   212,   213,     0,
       6,     0,     0,     0,   225,   225,   225,     7,     8,     9,
       0,   339,   339,   339,   339,   339,   339,   339,   339,   339,
       0,   280,     0,   214,     0,   280,     0,     0,     0,     0,
     227,   117,   339,   229,   230,   231,   232,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
       0,     0,     0,   227,   227,     0,     0,   219,     0,     0,
       0,   233,   386,   386,   386,   386,   386,   386,   386,   386,
     386,     0,   280,     0,     0,     0,     0,   227,     0,   386,
     119,     0,   229,   230,   231,   232,     0,     6,    87,     0,
       0,     0,    94,    95,     7,     8,     9,   219,   219,     0,
     227,   227,     0,  -100,  -100,  -100,  -100,     0,  -100,     0,
     233,   124,     0,   128,   130,  -100,  -100,  -100,   272,     0,
       0,   -38,   -38,     0,   -38,   -38,   -38,   -38,     0,   -38,
       0,  -100,     0,     0,     0,   280,   -38,   -38,   -38,     0,
     -38,   -38,     0,   -38,   -38,   -38,   -38,   -38,   -38,     0,
       0,     0,   -38,     0,     0,   -38,     0,     0,   -41,   -41,
       0,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,     0,
       0,     0,   280,   -41,   -41,   -41,     0,   -41,   -41,     0,
     -41,   -41,   -41,   -41,   -41,   -41,     0,     0,     0,   -41,
       0,     0,   -41,     0,     0,   272,     0,     0,     0,   -44,
     -44,     0,   -44,   -44,   -44,   -44,     0,   -44,     0,     0,
       0,     0,     0,     0,   -44,   -44,   -44,     0,   -44,   -44,
       0,   -44,   -44,   -44,   -44,   -44,   -44,   219,   219,   219,
     -44,     0,   121,   -44,   229,   230,   231,   232,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
     240,   241,   242,   243,   219,   245,   246,   247,     0,     0,
     227,   227,   233,     0,     0,     0,     0,     0,     0,     0,
     227,   227,   227,   219,     0,     0,   227,   227,   227,     0,
       0,     0,   344,   219,   219,   219,   351,   352,     0,   -39,
     -39,     0,   -39,   -39,   -39,   -39,     0,   -39,     0,     0,
       0,     0,     0,     0,   -39,   -39,   -39,   219,   -39,   -39,
       0,   -39,   -39,   -39,   -39,   -39,   -39,     0,     0,     0,
     -39,     0,     0,   -39,     0,   391,   272,   272,   272,   398,
     399,     0,     0,     0,     0,     0,   123,     0,   229,   230,
     231,   232,     0,     6,     0,     0,     0,   227,   227,   227,
       7,     8,     9,     0,   219,   219,   219,   420,     0,   424,
     426,   221,   219,     0,   272,     0,   233,     0,   272,     0,
       0,     0,     0,   219,   125,     0,   229,   230,   231,   232,
       0,     6,     0,     0,     0,     0,     0,     0,     7,     8,
       9,    84,     0,   283,   284,   285,   219,   219,   288,   289,
     290,   221,   221,     0,   233,   272,   272,   272,   460,     0,
     464,   466,     0,   272,     0,   272,   126,     0,     0,     0,
     219,     0,   274,     0,     0,     0,     0,     0,     0,     0,
     -45,   -45,     0,   -45,   -45,   -45,   -45,     0,   -45,     0,
       0,     0,     0,   219,   219,   -45,   -45,   -45,     0,   -45,
     -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
       0,   -45,     0,     0,   -45,     0,   -40,   -40,     0,   -40,
     -40,   -40,   -40,     0,   -40,     0,     0,     0,   272,     0,
       0,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,   -40,
     -40,   -40,   -40,   -40,     0,     0,     0,   -40,     0,   274,
     -40,     0,     0,   -50,   -50,     0,   -50,   -50,   -50,   -50,
       0,   -50,     0,     0,     0,   272,     0,     0,   -50,   -50,
     -50,     0,   -50,   -50,     0,   -50,   -50,   -50,   577,   -50,
     -50,   221,   221,   221,   -50,   220,     0,   -50,     0,     0,
     -49,   -49,     0,   -49,   -49,   -49,   -49,     0,   -49,     0,
       0,     0,     0,     0,     0,   -49,   -49,   -49,   221,   -49,
     -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,
       0,   -49,     0,     0,   -49,   220,   220,   221,    72,   -80,
     -80,   -80,   -80,    73,    74,   341,   221,   221,   221,   221,
     221,   221,     0,     0,     0,     0,   273,     0,     0,   -80,
       0,     0,     0,   219,   219,     0,     0,     0,     0,     0,
       0,   221,     0,   219,   219,   219,     0,     0,     0,   219,
     219,   219,     0,     0,     0,     0,     0,     0,   388,   274,
     274,   274,   274,   274,   274,     0,     0,     0,     0,     0,
       0,   127,   218,   229,   230,   231,   232,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,   221,   221,
     221,   221,   422,   221,   221,     0,   221,     0,   274,     0,
       0,   233,   274,   273,     0,     0,    93,   221,     0,     0,
       0,     0,   218,   218,     0,     0,     0,     0,     0,     0,
     219,   219,   219,     0,     0,   122,     0,     0,     0,     0,
     221,   221,     0,   271,     0,   220,   220,   220,     0,   274,
     274,   274,   274,   462,   274,   274,     0,   274,     0,   274,
       0,     0,     0,   129,   221,   229,   230,   231,   232,     0,
       6,     0,   220,     0,     0,     0,     0,     7,     8,     9,
       0,     0,     0,     0,     0,     0,     0,   221,   221,     0,
       0,   220,     0,   233,     0,     0,     0,     0,     0,     0,
     220,   220,   220,   220,   220,   220,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,     0,     0,     0,     0,     0,     0,
     271,     0,   274,     0,     0,   220,     0,     0,     0,  -117,
       0,  -117,  -117,     0,     0,     1,     0,     2,     3,     4,
       5,     0,     6,   273,   273,   273,   273,   273,   273,     7,
       8,     9,   218,   218,   218,     0,   293,   294,   295,   274,
     296,   297,     0,     0,     0,    17,     0,     0,   298,     0,
       0,     0,   220,   220,   220,   220,     0,   220,   220,   218,
     220,     0,   273,     0,     0,     0,   273,     0,     0,     0,
     131,   220,   229,   230,   231,   232,     0,     6,   218,     0,
       0,     0,     0,     0,     7,     8,     9,     0,   218,   218,
     350,     0,     0,     0,   220,   220,     0,     0,     0,     0,
     233,     0,     0,   273,   273,   273,   273,     0,   273,   273,
       0,   273,   218,   273,   283,   284,   285,   286,   220,   288,
     289,   290,     0,     0,     0,   217,     0,   221,   221,     0,
       0,   271,   271,   397,     0,     0,     0,   221,   221,   221,
       0,   220,   220,   221,   221,   221,     0,     0,     0,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,    89,     0,   218,
     218,   418,     0,     0,     0,   217,   217,   218,     0,   271,
       0,     0,   373,   271,   -91,   -91,   273,   120,   218,     0,
       0,     0,     0,     0,     0,     0,   270,     0,     0,   133,
       0,   229,   230,   231,   232,     0,     6,     0,     0,     0,
       0,   218,   218,     7,     8,     9,     0,     0,     0,     0,
     271,   271,   458,   273,   221,   221,   221,     0,   271,   233,
     271,     0,     0,     0,     0,   218,    46,    47,    48,    49,
      50,    51,    52,    53,     0,   -47,   -47,     0,   -47,   -47,
     -47,   -47,     0,   -47,     0,     0,     0,     0,   218,   218,
     -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,
     578,   -47,   -47,   270,     0,     0,   -47,     0,     0,   -47,
       0,     0,     0,   308,   216,   263,   264,   265,   266,     0,
       6,     0,     0,   271,     0,     0,     0,     7,     8,     9,
       0,     0,     0,     0,     0,   217,   217,   217,     0,     0,
       0,   220,   220,   267,     0,     0,     0,    91,     0,     0,
       0,   220,   220,   220,   216,   216,     0,   220,   220,   220,
     271,     0,   217,     0,   -46,   118,   -46,   -46,   -46,   -46,
       0,   -46,     0,     0,     0,   269,     0,     0,   -46,   -46,
     -46,   217,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,
     -46,   346,   217,     0,   -46,     0,     0,   -46,   -46,     2,
       3,     4,     5,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,   217,     0,     1,     0,     2,
       3,     4,     5,     0,     6,     0,     0,    17,   220,   220,
     220,     7,     8,     9,   393,   270,     0,     0,   526,   527,
     528,     0,   530,   531,     0,     0,     0,    17,   218,   218,
     532,     0,   269,     0,     0,     0,     0,     0,   218,   218,
     218,     0,   217,   416,   218,   218,   218,     0,     0,     0,
     217,     0,   270,     0,     0,     0,   270,     0,     0,     0,
       0,   217,     0,     0,   216,   216,   216,   312,     0,   210,
     211,   212,   213,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,   217,   217,     0,     0,     0,     0,
       0,   216,     0,   270,   456,     0,     0,   214,     0,     0,
       0,   270,     0,   270,     0,     0,     0,     0,   217,     0,
     216,     0,     0,     0,     0,   218,   218,   218,     0,     0,
       0,   348,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
       0,   217,   217,     0,   -52,   -52,     0,   -52,   -52,   -52,
     -52,     0,   -52,     0,   216,   -95,     0,   -95,   -95,   -52,
     -52,   -52,     0,   -52,   -52,     0,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,   395,   -52,   270,     0,   -52,     0,
       0,     0,   325,     0,   210,   211,   212,   213,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,   414,     0,   -54,     0,   -54,   -54,   -54,   -54,   216,
     -54,   269,   214,   270,     0,   269,     0,   -54,   -54,   -54,
     216,   -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,   -54,     0,     0,   -54,   -54,     0,     0,
       0,     0,     0,   216,   216,     0,     0,     0,     0,     0,
       0,     0,   454,     0,   -53,     0,   -53,   -53,   -53,   -53,
     269,   -53,   269,     0,     0,     0,     0,   216,   -53,   -53,
     -53,     0,   -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,
     -53,     0,     0,     0,   -53,     0,     0,   -53,   -53,     0,
     216,   216,   340,     0,   329,   330,   331,   332,     0,     6,
       0,   217,   217,     0,     0,     0,     7,     8,     9,     0,
       0,   217,   217,   217,     0,     0,     0,   217,   217,   217,
       0,     0,   333,   -51,   -51,   269,   -51,   -51,   -51,   -51,
       0,   -51,     0,     0,     0,     0,     0,     0,   -51,   -51,
     -51,     0,   -51,   -51,     0,   -51,   -51,   -51,   -51,   -51,
     -51,     0,     0,     0,   -51,     0,     0,   -51,     0,     0,
     -48,   -48,   269,   -48,   -48,   -48,   -48,     0,   -48,     0,
       0,     0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,
     -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,   217,   217,
     217,   -48,     0,   -25,   -48,   -25,   -25,   -25,   -25,     0,
     -25,     0,     0,     0,     0,     0,     0,   -25,   -25,   -25,
       0,   -25,   -25,     0,   -25,   -25,   -25,   -25,   -25,   -25,
       0,     0,     0,   -25,     0,     0,   -25,   -25,   343,     0,
     329,   330,   331,   332,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,     0,     0,     0,     0,
     216,   216,     0,     0,     0,     0,     0,     0,   333,     0,
     216,   216,   216,     0,     0,     0,   216,   216,   216,   -42,
       0,   -42,   -42,   -42,   -42,     0,   -42,     0,     0,     0,
       0,     0,     0,   -42,   -42,   -42,     0,   -42,   -42,     0,
     -42,   -42,   -42,   -42,   -42,   -42,     0,     0,     0,   -42,
       0,     0,   -42,   -42,     0,     0,     0,     0,     0,     0,
     -43,     0,   -43,   -43,   -43,   -43,     0,   -43,     0,     0,
       0,     0,     0,     0,   -43,   -43,   -43,     0,   -43,   -43,
       0,   -43,   -43,   -43,   -43,   -43,   -43,   216,   216,   216,
     -43,     0,     0,   -43,   -43,   -38,     0,   -38,   -38,   -38,
     -38,     0,   -38,     0,     0,     0,     0,     0,     0,   -38,
     -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,   -38,
     -38,   -38,     0,     0,     0,   -38,     0,     0,   -38,   -38,
     -41,     0,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,
       0,     0,     0,     0,   -41,   -41,   -41,     0,   -41,   -41,
       0,   -41,   -41,   -41,   -41,   -41,   -41,     0,     0,     0,
     -41,     0,     0,   -41,   -41,   -44,     0,   -44,   -44,   -44,
     -44,     0,   -44,     0,     0,     0,     0,     0,     0,   -44,
     -44,   -44,     0,   -44,   -44,     0,   -44,   -44,   -44,   -44,
     -44,   -44,     0,     0,     0,   -44,     0,     0,   -44,   -44,
     -39,     0,   -39,   -39,   -39,   -39,     0,   -39,     0,     0,
       0,     0,     0,     0,   -39,   -39,   -39,     0,   -39,   -39,
       0,   -39,   -39,   -39,   -39,   -39,   -39,     0,     0,     0,
     -39,     0,     0,   -39,   -39,   -45,     0,   -45,   -45,   -45,
     -45,     0,   -45,     0,     0,     0,     0,     0,     0,   -45,
     -45,   -45,     0,   -45,   -45,     0,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,     0,   -45,     0,     0,   -45,   -45,
     -40,     0,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,
       0,     0,     0,     0,   -40,   -40,   -40,     0,   -40,   -40,
       0,   -40,   -40,   -40,   -40,   -40,   -40,     0,     0,     0,
     -40,     0,     0,   -40,   -40,   -50,     0,   -50,   -50,   -50,
     -50,     0,   -50,     0,     0,     0,     0,     0,     0,   -50,
     -50,   -50,     0,   -50,   -50,     0,   -50,   -50,   -50,   648,
     -50,   -50,     0,     0,     0,   -50,     0,     0,   -50,   -50,
     -49,     0,   -49,   -49,   -49,   -49,     0,   -49,     0,     0,
       0,     0,     0,     0,   -49,   -49,   -49,     0,   -49,   -49,
       0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,
     -49,     0,     0,   -49,   -49,   -47,     0,   -47,   -47,   -47,
     -47,     0,   -47,     0,     0,     0,     0,     0,     0,   -47,
     -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,   649,
     -47,   -47,     0,     0,     0,   -47,     0,     0,   -47,   -47,
     -56,   -56,     0,   -56,   -56,   -56,   -56,     0,   -56,     0,
       0,     0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,
     -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
       0,   -56,   -57,   -57,   -56,   -57,   -57,   -57,   -57,     0,
     -57,     0,     0,     0,     0,     0,     0,   -57,   -57,   -57,
       0,   -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,
       0,     0,     0,   -57,   -58,   -58,   -57,   -58,   -58,   -58,
     -58,     0,   -58,     0,     0,     0,     0,     0,     0,   -58,
     -58,   -58,     0,   -58,   -58,     0,   -58,   -58,   -58,   -58,
     -58,   -58,     0,     0,     0,   -58,   -55,   -55,   -58,   -55,
     -55,   -55,   -55,     0,   -55,     0,     0,     0,     0,     0,
       0,   -55,   -55,   -55,     0,   -55,   -55,     0,   -55,   -55,
     -55,   -55,   -55,   -55,     0,     0,     0,   -55,     0,   -52,
     -55,   -52,   -52,   -52,   -52,     0,   -52,     0,     0,     0,
       0,     0,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,
     -52,   -52,   -52,   -52,   -52,   -52,     0,     0,     0,   -52,
       0,     0,   -52,   -52,   -51,     0,   -51,   -51,   -51,   -51,
       0,   -51,     0,     0,     0,     0,     0,     0,   -51,   -51,
     -51,     0,   -51,   -51,     0,   -51,   -51,   -51,   -51,   -51,
     -51,     0,     0,     0,   -51,     0,     0,   -51,   -51,   -48,
       0,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,     0,
       0,     0,     0,   -48,   -48,   -48,     0,   -48,   -48,     0,
     -48,   -48,   -48,   -48,   -48,   -48,     0,     0,     0,   -48,
       0,     0,   -48,   -48,   -56,     0,   -56,   -56,   -56,   -56,
       0,   -56,     0,     0,     0,     0,     0,     0,   -56,   -56,
     -56,     0,   -56,   -56,     0,   -56,   -56,   -56,   -56,   -56,
     -56,     0,     0,     0,   -56,     0,     0,   -56,   -56,   -57,
       0,   -57,   -57,   -57,   -57,     0,   -57,     0,     0,     0,
       0,     0,     0,   -57,   -57,   -57,     0,   -57,   -57,     0,
     -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,   -57,
       0,     0,   -57,   -57,   -58,     0,   -58,   -58,   -58,   -58,
       0,   -58,     0,     0,     0,     0,     0,     0,   -58,   -58,
     -58,     0,   -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,
     -58,     0,     0,     0,   -58,     0,     0,   -58,   -58,   -55,
       0,   -55,   -55,   -55,   -55,     0,   -55,     0,     0,     0,
       0,     0,     0,   -55,   -55,   -55,     0,   -55,   -55,     0,
     -55,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,   -55,
       0,     0,   -55,   -55,    -3,     1,     0,     2,     3,     4,
       5,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,    10,    11,     0,    12,    13,    14,     0,
      15,    16,     0,     0,     0,    17,     0,   -24,    18,   -24,
     -24,   -24,   -24,     0,   -24,     0,     0,     0,     0,     0,
       0,   -24,   -24,   -24,     0,   -24,   -24,     0,   -24,   -24,
     -24,     0,   -24,   -24,     0,     0,     0,   -24,     0,     0,
     -24,   -24,    -2,     1,     0,     2,     3,     4,     5,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,    10,    11,     0,    12,    13,    14,     0,    15,    16,
       0,     0,     0,    17,    -5,    -5,    18,    -5,    -5,    -5,
      -5,     0,    -5,     0,     0,     0,     0,     0,     0,    -5,
      -5,    -5,     0,    -5,    -5,     0,    -5,    -5,    -5,     0,
      -5,    -5,     0,     0,     0,    -5,    -7,    -7,    -5,    -7,
      -7,    -7,    -7,     0,    -7,     0,     0,     0,     0,     0,
       0,    -7,    -7,    -7,     0,    -7,    -7,     0,    -7,    -7,
      -7,     0,    -7,    -7,     0,     0,     0,    -7,    -6,    -6,
      -7,    -6,    -6,    -6,    -6,     0,    -6,     0,     0,     0,
       0,     0,     0,    -6,    -6,    -6,     0,    -6,    -6,     0,
      -6,    -6,    -6,     0,    -6,    -6,     0,     0,     0,    -6,
     -33,   -33,    -6,   -33,   -33,   -33,   -33,     0,   -33,     0,
       0,     0,     0,     0,     0,   -33,   -33,   -33,     0,   -33,
     -33,     0,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,
       0,   -33,    -8,    -8,   -33,    -8,    -8,    -8,    -8,     0,
      -8,     0,     0,     0,     0,     0,     0,    -8,    -8,    -8,
       0,    -8,    -8,     0,    -8,    -8,    -8,     0,    -8,    -8,
       0,     0,     0,    -8,   -37,   -37,    -8,   -37,   -37,   -37,
     -37,     0,   -37,     0,     0,     0,     0,     0,     0,   -37,
     -37,   -37,     0,   -37,   -37,     0,   -37,   -37,   -37,     0,
     -37,   -37,     0,     0,     0,   -37,   -32,   -32,   -37,   -32,
     -32,   -32,   -32,     0,   -32,     0,     0,     0,     0,     0,
       0,   -32,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,
     -32,     0,   -32,   -32,     0,     0,     0,   -32,   -34,   -34,
     -32,   -34,   -34,   -34,   -34,     0,   -34,     0,     0,     0,
       0,     0,     0,   -34,   -34,   -34,     0,   -34,   -34,     0,
     -34,   -34,   -34,     0,   -34,   -34,     0,     0,     0,   -34,
     -35,   -35,   -34,   -35,   -35,   -35,   -35,     0,   -35,     0,
       0,     0,     0,     0,     0,   -35,   -35,   -35,     0,   -35,
     -35,     0,   -35,   -35,   -35,     0,   -35,   -35,     0,     0,
       0,   -35,   -36,   -36,   -35,   -36,   -36,   -36,   -36,     0,
     -36,     0,     0,     0,     0,     0,     0,   -36,   -36,   -36,
       0,   -36,   -36,     0,   -36,   -36,   -36,     0,   -36,   -36,
       0,     0,     0,   -36,     0,     1,   -36,     2,     3,     4,
       5,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,   248,   249,     0,   250,   251,   252,     0,
     253,   254,     0,     0,     0,    17,     0,     0,   255,   -27,
      -4,    -4,     0,    -4,    -4,    -4,    -4,     0,    -4,     0,
       0,     0,     0,     0,     0,    -4,    -4,    -4,     0,    -4,
      -4,     0,    -4,    -4,    -4,     0,    -4,    -4,     0,     0,
       0,    -4,   -46,   -46,    -4,   -46,   -46,   -46,   -46,     0,
     -46,     0,     0,     0,     0,     0,     0,   -46,   -46,   -46,
       0,   -46,   -46,     0,   -46,   -46,   -46,     0,   -46,   -46,
       0,     0,     0,   -46,   -10,   -10,   -46,   -10,   -10,   -10,
     -10,     0,   -10,     0,     0,     0,     0,     0,     0,   -10,
     -10,   -10,     0,   -10,   -10,     0,   -10,   -10,   -10,     0,
     -10,   -10,     0,     0,     0,   -10,   -54,   -54,   -10,   -54,
     -54,   -54,   -54,     0,   -54,     0,     0,     0,     0,     0,
       0,   -54,   -54,   -54,     0,   -54,   -54,     0,   -54,   -54,
     -54,     0,   -54,   -54,     0,     0,     0,   -54,   -53,   -53,
     -54,   -53,   -53,   -53,   -53,     0,   -53,     0,     0,     0,
       0,     0,     0,   -53,   -53,   -53,     0,   -53,   -53,     0,
     -53,   -53,   -53,     0,   -53,   -53,     0,     0,     0,   -53,
       0,   -30,   -53,   -30,   -30,   -30,   -30,     0,   -30,     0,
       0,     0,     0,     0,     0,   -30,   -30,   -30,     0,   -30,
     -30,     0,   -30,   -30,   -30,     0,   -30,   -30,     0,     0,
       0,   -30,     0,     0,   -30,   -30,     1,     0,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,   248,   249,     0,   250,   251,   252,
       0,   253,   254,     0,     0,     0,    17,     0,     0,   255,
     -26,   -29,     0,   -29,   -29,   -29,   -29,     0,   -29,     0,
       0,     0,     0,     0,     0,   -29,   -29,   -29,     0,   -29,
     -29,     0,   -29,   -29,   -29,     0,   -29,   -29,     0,     0,
       0,   -29,     0,     0,   -29,   -29,   -31,     0,   -31,   -31,
     -31,   -31,     0,   -31,     0,     0,     0,     0,     0,     0,
     -31,   -31,   -31,     0,   -31,   -31,     0,   -31,   -31,   -31,
       0,   -31,   -31,     0,     0,     0,   -31,     0,     0,   -31,
     -31,    -9,    -9,     0,    -9,    -9,    -9,    -9,     0,    -9,
       0,     0,     0,     0,     0,     0,    -9,    -9,    -9,     0,
      -9,    -9,     0,    -9,    -9,    -9,     0,    -9,    -9,     0,
       0,     0,    -9,   -25,   -25,    -9,   -25,   -25,   -25,   -25,
       0,   -25,     0,     0,     0,     0,     0,     0,   -25,   -25,
     -25,     0,   -25,   -25,     0,   -25,   -25,   -25,     0,   -25,
     -25,     0,     0,     0,   -25,     0,   -28,   -25,   -28,   -28,
     -28,   -28,     0,   -28,     0,     0,     0,     0,     0,     0,
     -28,   -28,   -28,     0,   -28,   -28,     0,   -28,   -28,   -28,
       0,   -28,   -28,     0,     0,     0,   -28,     0,     0,   -28,
     -28,   -11,   -11,     0,   -11,   -11,   -11,   -11,     0,   -11,
       0,     0,     0,     0,     0,     0,   -11,   -11,   -11,     0,
     -11,   -11,     0,   -11,   -11,   -11,     0,   -11,   -11,     0,
       0,     0,   -11,   -42,   -42,   -11,   -42,   -42,   -42,   -42,
       0,   -42,     0,     0,     0,     0,     0,     0,   -42,   -42,
     -42,     0,   -42,   -42,     0,   -42,   -42,   -42,     0,   -42,
     -42,     0,     0,     0,   -42,   -43,   -43,   -42,   -43,   -43,
     -43,   -43,     0,   -43,     0,     0,     0,     0,     0,     0,
     -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,   -43,
       0,   -43,   -43,     0,     0,     0,   -43,   -38,   -38,   -43,
     -38,   -38,   -38,   -38,     0,   -38,     0,     0,     0,     0,
       0,     0,   -38,   -38,   -38,     0,   -38,   -38,     0,   -38,
     -38,   -38,     0,   -38,   -38,     0,     0,     0,   -38,   -41,
     -41,   -38,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,
       0,     0,     0,     0,   -41,   -41,   -41,     0,   -41,   -41,
       0,   -41,   -41,   -41,     0,   -41,   -41,     0,     0,     0,
     -41,   -44,   -44,   -41,   -44,   -44,   -44,   -44,     0,   -44,
       0,     0,     0,     0,     0,     0,   -44,   -44,   -44,     0,
     -44,   -44,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,
       0,     0,   -44,   -39,   -39,   -44,   -39,   -39,   -39,   -39,
       0,   -39,     0,     0,     0,     0,     0,     0,   -39,   -39,
     -39,     0,   -39,   -39,     0,   -39,   -39,   -39,     0,   -39,
     -39,     0,     0,     0,   -39,   -45,   -45,   -39,   -45,   -45,
     -45,   -45,     0,   -45,     0,     0,     0,     0,     0,     0,
     -45,   -45,   -45,     0,   -45,   -45,     0,   -45,   -45,   -45,
       0,   -45,   -45,     0,     0,     0,   -45,   -40,   -40,   -45,
     -40,   -40,   -40,   -40,     0,   -40,     0,     0,     0,     0,
       0,     0,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,
     -40,   -40,     0,   -40,   -40,     0,     0,     0,   -40,   -49,
     -49,   -40,   -49,   -49,   -49,   -49,     0,   -49,     0,     0,
       0,     0,     0,     0,   -49,   -49,   -49,     0,   -49,   -49,
       0,   -49,   -49,   -49,     0,   -49,   -49,     0,     0,     0,
     -49,   -52,   -52,   -49,   -52,   -52,   -52,   -52,     0,   -52,
       0,     0,     0,     0,     0,     0,   -52,   -52,   -52,     0,
     -52,   -52,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,
       0,     0,   -52,   -51,   -51,   -52,   -51,   -51,   -51,   -51,
       0,   -51,     0,     0,     0,     0,     0,     0,   -51,   -51,
     -51,     0,   -51,   -51,     0,   -51,   -51,   -51,     0,   -51,
     -51,     0,     0,     0,   -51,   -48,   -48,   -51,   -48,   -48,
     -48,   -48,     0,   -48,     0,     0,     0,     0,     0,     0,
     -48,   -48,   -48,     0,   -48,   -48,     0,   -48,   -48,   -48,
       0,   -48,   -48,     0,     0,     0,   -48,   -17,   -17,   -48,
     -17,   -17,   -17,   -17,     0,   -17,     0,     0,     0,     0,
       0,     0,   -17,   -17,   -17,     0,   -17,   -17,     0,   -17,
     -17,   -17,     0,   -17,   -17,     0,     0,     0,   -17,   -14,
     -14,   -17,   -14,   -14,   -14,   -14,     0,   -14,     0,     0,
       0,     0,     0,     0,   -14,   -14,   -14,     0,   -14,   -14,
       0,   -14,   -14,   -14,     0,   -14,   -14,     0,     0,     0,
     -14,   -56,   -56,   -14,   -56,   -56,   -56,   -56,     0,   -56,
       0,     0,     0,     0,     0,     0,   -56,   -56,   -56,     0,
     -56,   -56,     0,   -56,   -56,   -56,     0,   -56,   -56,     0,
       0,     0,   -56,   -57,   -57,   -56,   -57,   -57,   -57,   -57,
       0,   -57,     0,     0,     0,     0,     0,     0,   -57,   -57,
     -57,     0,   -57,   -57,     0,   -57,   -57,   -57,     0,   -57,
     -57,     0,     0,     0,   -57,   -58,   -58,   -57,   -58,   -58,
     -58,   -58,     0,   -58,     0,     0,     0,     0,     0,     0,
     -58,   -58,   -58,     0,   -58,   -58,     0,   -58,   -58,   -58,
       0,   -58,   -58,     0,     0,     0,   -58,   -55,   -55,   -58,
     -55,   -55,   -55,   -55,     0,   -55,     0,     0,     0,     0,
       0,     0,   -55,   -55,   -55,     0,   -55,   -55,     0,   -55,
     -55,   -55,     0,   -55,   -55,     0,     0,     0,   -55,     0,
     -33,   -55,   -33,   -33,   -33,   -33,     0,   -33,     0,     0,
       0,     0,     0,     0,   -33,   -33,   -33,     0,   -33,   -33,
       0,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,     0,
     -33,     0,     0,   -33,   -33,   -37,     0,   -37,   -37,   -37,
     -37,     0,   -37,     0,     0,     0,     0,     0,     0,   -37,
     -37,   -37,     0,   -37,   -37,     0,   -37,   -37,   -37,     0,
     -37,   -37,     0,     0,     0,   -37,     0,     0,   -37,   -37,
     -32,     0,   -32,   -32,   -32,   -32,     0,   -32,     0,     0,
       0,     0,     0,     0,   -32,   -32,   -32,     0,   -32,   -32,
       0,   -32,   -32,   -32,     0,   -32,   -32,     0,     0,     0,
     -32,     0,     0,   -32,   -32,   -34,     0,   -34,   -34,   -34,
     -34,     0,   -34,     0,     0,     0,     0,     0,     0,   -34,
     -34,   -34,     0,   -34,   -34,     0,   -34,   -34,   -34,     0,
     -34,   -34,     0,     0,     0,   -34,     0,     0,   -34,   -34,
     -35,     0,   -35,   -35,   -35,   -35,     0,   -35,     0,     0,
       0,     0,     0,     0,   -35,   -35,   -35,     0,   -35,   -35,
       0,   -35,   -35,   -35,     0,   -35,   -35,     0,     0,     0,
     -35,     0,     0,   -35,   -35,   -36,     0,   -36,   -36,   -36,
     -36,     0,   -36,     0,     0,     0,     0,     0,     0,   -36,
     -36,   -36,     0,   -36,   -36,     0,   -36,   -36,   -36,     0,
     -36,   -36,     0,     0,     0,   -36,     0,     0,   -36,   -36,
     -10,     0,   -10,   -10,   -10,   -10,     0,   -10,     0,     0,
       0,     0,     0,     0,   -10,   -10,   -10,     0,   -10,   -10,
       0,   -10,   -10,   -10,     0,   -10,   -10,     0,     0,     0,
     -10,     0,     0,   -10,   -10,    -9,     0,    -9,    -9,    -9,
      -9,     0,    -9,     0,     0,     0,     0,     0,     0,    -9,
      -9,    -9,     0,    -9,    -9,     0,    -9,    -9,    -9,     0,
      -9,    -9,     0,     0,     0,    -9,     0,     0,    -9,    -9,
     -46,     0,   -46,   -46,   -46,   -46,     0,   -46,     0,     0,
       0,     0,     0,     0,   -46,   -46,   -46,     0,   -46,   -46,
       0,   -46,   -46,   -46,     0,   -46,   -46,     0,     0,     0,
     -46,     0,     0,   -46,   -46,   -11,     0,   -11,   -11,   -11,
     -11,     0,   -11,     0,     0,     0,     0,     0,     0,   -11,
     -11,   -11,     0,   -11,   -11,     0,   -11,   -11,   -11,     0,
     -11,   -11,     0,     0,     0,   -11,     0,     0,   -11,   -11,
     -54,     0,   -54,   -54,   -54,   -54,     0,   -54,     0,     0,
       0,     0,     0,     0,   -54,   -54,   -54,     0,   -54,   -54,
       0,   -54,   -54,   -54,     0,   -54,   -54,     0,     0,     0,
     -54,     0,     0,   -54,   -54,   -53,     0,   -53,   -53,   -53,
     -53,     0,   -53,     0,     0,     0,     0,     0,     0,   -53,
     -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,     0,
     -53,   -53,     0,     0,     0,   -53,     0,     0,   -53,   -53,
     -25,     0,   -25,   -25,   -25,   -25,     0,   -25,     0,     0,
       0,     0,     0,     0,   -25,   -25,   -25,     0,   -25,   -25,
       0,   -25,   -25,   -25,     0,   -25,   -25,     0,     0,     0,
     -25,     0,     0,   -25,   -25,   -42,     0,   -42,   -42,   -42,
     -42,     0,   -42,     0,     0,     0,     0,     0,     0,   -42,
     -42,   -42,     0,   -42,   -42,     0,   -42,   -42,   -42,     0,
     -42,   -42,     0,     0,     0,   -42,     0,     0,   -42,   -42,
     -43,     0,   -43,   -43,   -43,   -43,     0,   -43,     0,     0,
       0,     0,     0,     0,   -43,   -43,   -43,     0,   -43,   -43,
       0,   -43,   -43,   -43,     0,   -43,   -43,     0,     0,     0,
     -43,     0,     0,   -43,   -43,   -38,     0,   -38,   -38,   -38,
     -38,     0,   -38,     0,     0,     0,     0,     0,     0,   -38,
     -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,     0,
     -38,   -38,     0,     0,     0,   -38,     0,     0,   -38,   -38,
     -41,     0,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,
       0,     0,     0,     0,   -41,   -41,   -41,     0,   -41,   -41,
       0,   -41,   -41,   -41,     0,   -41,   -41,     0,     0,     0,
     -41,     0,     0,   -41,   -41,   -44,     0,   -44,   -44,   -44,
     -44,     0,   -44,     0,     0,     0,     0,     0,     0,   -44,
     -44,   -44,     0,   -44,   -44,     0,   -44,   -44,   -44,     0,
     -44,   -44,     0,     0,     0,   -44,     0,     0,   -44,   -44,
     -39,     0,   -39,   -39,   -39,   -39,     0,   -39,     0,     0,
       0,     0,     0,     0,   -39,   -39,   -39,     0,   -39,   -39,
       0,   -39,   -39,   -39,     0,   -39,   -39,     0,     0,     0,
     -39,     0,     0,   -39,   -39,   -45,     0,   -45,   -45,   -45,
     -45,     0,   -45,     0,     0,     0,     0,     0,     0,   -45,
     -45,   -45,     0,   -45,   -45,     0,   -45,   -45,   -45,     0,
     -45,   -45,     0,     0,     0,   -45,     0,     0,   -45,   -45,
     -40,     0,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,
       0,     0,     0,     0,   -40,   -40,   -40,     0,   -40,   -40,
       0,   -40,   -40,   -40,     0,   -40,   -40,     0,     0,     0,
     -40,     0,     0,   -40,   -40,   -49,     0,   -49,   -49,   -49,
     -49,     0,   -49,     0,     0,     0,     0,     0,     0,   -49,
     -49,   -49,     0,   -49,   -49,     0,   -49,   -49,   -49,     0,
     -49,   -49,     0,     0,     0,   -49,     0,     0,   -49,   -49,
     -52,     0,   -52,   -52,   -52,   -52,     0,   -52,     0,     0,
       0,     0,     0,     0,   -52,   -52,   -52,     0,   -52,   -52,
       0,   -52,   -52,   -52,     0,   -52,   -52,     0,     0,     0,
     -52,     0,     0,   -52,   -52,   -51,     0,   -51,   -51,   -51,
     -51,     0,   -51,     0,     0,     0,     0,     0,     0,   -51,
     -51,   -51,     0,   -51,   -51,     0,   -51,   -51,   -51,     0,
     -51,   -51,     0,     0,     0,   -51,     0,     0,   -51,   -51,
     -48,     0,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,
       0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,   -48,
       0,   -48,   -48,   -48,     0,   -48,   -48,     0,     0,     0,
     -48,     0,     0,   -48,   -48,   -56,     0,   -56,   -56,   -56,
     -56,     0,   -56,     0,     0,     0,     0,     0,     0,   -56,
     -56,   -56,     0,   -56,   -56,     0,   -56,   -56,   -56,     0,
     -56,   -56,     0,     0,     0,   -56,     0,     0,   -56,   -56,
     -57,     0,   -57,   -57,   -57,   -57,     0,   -57,     0,     0,
       0,     0,     0,     0,   -57,   -57,   -57,     0,   -57,   -57,
       0,   -57,   -57,   -57,     0,   -57,   -57,     0,     0,     0,
     -57,     0,     0,   -57,   -57,   -58,     0,   -58,   -58,   -58,
     -58,     0,   -58,     0,     0,     0,     0,     0,     0,   -58,
     -58,   -58,     0,   -58,   -58,     0,   -58,   -58,   -58,     0,
     -58,   -58,     0,     0,     0,   -58,     0,     0,   -58,   -58,
     -55,     0,   -55,   -55,   -55,   -55,     0,   -55,     0,     0,
       0,     0,     0,     0,   -55,   -55,   -55,     0,   -55,   -55,
       0,   -55,   -55,   -55,     0,   -55,   -55,     0,     0,     0,
     -55,     0,     0,   -55,   -55,   345,     0,   329,   330,   331,
     332,   347,     6,   329,   330,   331,   332,     0,     6,     7,
       8,     9,     0,     0,     0,     7,     8,     9,     0,   349,
       0,   329,   330,   331,   332,   333,     6,     0,     0,     0,
       0,   333,     0,     7,     8,     9,   359,     0,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,   333,
       7,     8,     9,   363,     0,   210,   211,   212,   213,     0,
       6,     0,     0,     0,     0,     0,    17,     7,     8,     9,
     387,     0,   376,   377,   378,   379,     0,     6,     0,     0,
       0,     0,     0,   214,     7,     8,     9,   390,     0,   376,
     377,   378,   379,     0,     6,     0,     0,     0,     0,     0,
     380,     7,     8,     9,   392,     0,   376,   377,   378,   379,
       0,     6,     0,     0,     0,     0,     0,   380,     7,     8,
       9,   394,     0,   376,   377,   378,   379,     0,     6,     0,
       0,     0,     0,     0,   380,     7,     8,     9,   396,     0,
     376,   377,   378,   379,     0,     6,     0,     0,     0,     0,
       0,   380,     7,     8,     9,   406,     0,     2,     3,     4,
       5,     0,     6,     0,     0,     0,     0,     0,   380,     7,
       8,     9,   413,     0,   329,   330,   331,   332,     0,     6,
       0,     0,     0,     0,     0,    17,     7,     8,     9,   415,
       0,   329,   330,   331,   332,     0,     6,     0,     0,     0,
       0,     0,   333,     7,     8,     9,   417,     0,   329,   330,
     331,   332,     0,     6,     0,     0,     0,     0,     0,   333,
       7,     8,     9,   419,     0,   329,   330,   331,   332,     0,
       6,     0,     0,     0,     0,     0,   333,     7,     8,     9,
     421,     0,   329,   330,   331,   332,     0,     6,     0,     0,
       0,     0,     0,   333,     7,     8,     9,   423,     0,   329,
     330,   331,   332,     0,     6,     0,     0,     0,     0,     0,
     333,     7,     8,     9,   425,     0,   329,   330,   331,   332,
       0,     6,     0,     0,     0,     0,     0,   333,     7,     8,
       9,   427,     0,   329,   330,   331,   332,     0,     6,     0,
       0,     0,     0,     0,   333,     7,     8,     9,   429,     0,
     329,   330,   331,   332,     0,     6,     0,     0,     0,     0,
       0,   333,     7,     8,     9,   435,     0,   210,   211,   212,
     213,     0,     6,     0,     0,     0,     0,     0,   333,     7,
       8,     9,   444,     0,   210,   211,   212,   213,     0,     6,
       0,     0,     0,     0,     0,   214,     7,     8,     9,   453,
       0,   376,   377,   378,   379,     0,     6,     0,     0,     0,
       0,     0,   214,     7,     8,     9,   455,     0,   376,   377,
     378,   379,     0,     6,     0,     0,     0,     0,     0,   380,
       7,     8,     9,   457,     0,   376,   377,   378,   379,     0,
       6,     0,     0,     0,     0,     0,   380,     7,     8,     9,
     459,     0,   376,   377,   378,   379,     0,     6,     0,     0,
       0,     0,     0,   380,     7,     8,     9,   461,     0,   376,
     377,   378,   379,     0,     6,     0,     0,     0,     0,     0,
     380,     7,     8,     9,   463,     0,   376,   377,   378,   379,
       0,     6,     0,     0,     0,     0,     0,   380,     7,     8,
       9,   465,     0,   376,   377,   378,   379,     0,     6,     0,
       0,     0,     0,     0,   380,     7,     8,     9,   467,     0,
     376,   377,   378,   379,     0,     6,     0,     0,     0,     0,
       0,   380,     7,     8,     9,   469,     0,   376,   377,   378,
     379,     0,     6,     0,     0,     0,     0,     0,   380,     7,
       8,     9,   472,     0,   210,   211,   212,   213,     0,     6,
       0,     0,     0,     0,     0,   380,     7,     8,     9,   481,
       0,   210,   211,   212,   213,     0,     6,     0,     0,     0,
       0,     0,   214,     7,     8,     9,   567,     0,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,   214,
       7,     8,     9,   587,     0,   210,   211,   212,   213,     0,
       6,     0,     0,     0,     0,     0,    17,     7,     8,     9,
       0,     0,   229,   230,   231,   232,     0,     6,     0,     0,
       0,     0,     0,   214,     7,     8,     9,     0,     0,   210,
     211,   212,   213,     0,     6,     0,     0,     0,     0,     0,
     233,     7,     8,     9,     0,     0,   329,   330,   331,   332,
       0,     6,     0,     0,     0,     0,     0,   214,     7,     8,
       9,     0,     0,   263,   264,   265,   266,     0,     6,     0,
       0,     0,     0,     0,   333,     7,     8,     9,     0,     0,
     376,   377,   378,   379,     0,     6,     0,     0,     0,     0,
       0,   267,     7,     8,     9,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,     0,     0,     0,     0,     0,   380,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,     0,  -101,     0,
    -101,  -101,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
       0,     0,  -109,     0,  -109,  -109,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,     0,   -96,     0,   -96,   -96,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,     0,     0,     0,
    -112,  -112,  -112,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,     0,     0,   475,  -108,  -108,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,     0,     0,  -111,     0,  -111,  -111,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,  -110,
       0,  -110,  -110,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,     0,     0,  -102,     0,  -102,  -102,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,     0,     0,     0,  -118,  -118,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,     0,     0,
       0,     0,  -119,  -119,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,     0,     0,     0,  -117,  -117,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,     0,     0,     0,     0,   -94,
     -94,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,     0,
       0,     0,   -95,   -95,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,     0,     0,     0,     0,  -101,  -101,   372,   -90,
     -90,   -90,   -90,   -90,   -90,   -90,     0,     0,     0,  -109,
    -109,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,     0,
       0,     0,     0,   -90,   -90,   283,   284,   285,   286,   -66,
     288,   289,   290,     0,     0,     0,   -91,   -91,   283,   284,
     285,   -70,   -70,   288,   289,   290,     0,     0,     0,     0,
     -66,   -66,   283,   284,   285,   -74,   -74,   -74,   289,   290,
       0,     0,     0,   -70,   -70,   283,   284,   -78,   -78,   -78,
     -78,   289,   290,     0,     0,     0,     0,   -74,   -74,   283,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,     0,     0,     0,
     -78,   -78,   372,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
       0,     0,     0,     0,   -89,   -89,   283,   284,   -84,   -84,
     -84,   -84,   289,   290,     0,     0,     0,   -88,   -88,   283,
     284,   -83,   -83,   -83,   -83,   289,   290,     0,     0,     0,
       0,   -84,   -84,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,     0,     0,     0,   -83,   -83,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,     0,     0,     0,     0,   -93,   -93,
     283,   284,   285,   286,   287,   288,   289,   290,     0,     0,
       0,   -92,   -92,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,     0,     0,     0,     0,   -61,   -61,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,     0,     0,     0,   -96,   -96,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,
       0,     0,  -111,  -111,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,     0,     0,     0,  -110,  -110,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,     0,     0,     0,     0,  -102,
    -102,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,
    -118,     0,  -118,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,     0,     0,     0,  -119,     0,  -119,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,     0,  -117,     0,  -117,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,     0,     0,     0,
     322,     0,   -91,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,     0,   -95,     0,   -95,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,     0,     0,     0,  -101,     0,  -101,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,  -109,     0,
    -109,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,     0,
       0,     0,   -96,     0,   -96,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,     0,     0,  -112,  -112,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,     0,     0,     0,     0,   438,
    -108,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,     0,
    -111,     0,  -111,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,     0,     0,     0,  -110,     0,  -110,   240,   241,   242,
     243,   244,   245,   246,   247,     0,  -102,     0,  -102,   321,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,     0,
       0,     0,   203,   240,   241,   242,   243,   244,   245,   246,
     247,     0,     0,     0,   -87,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,   411,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,     0,     0,     0,
     432,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,
       0,     0,     0,     0,  -118,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,     0,     0,     0,  -119,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,
    -117,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,     0,
       0,     0,   -94,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,     0,     0,     0,     0,     0,   -95,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,     0,     0,     0,  -101,   321,
     -90,   -90,   -90,   -90,   -90,   -90,   -90,     0,     0,     0,
       0,     0,  -109,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,     0,     0,     0,   -90,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,   -91,   240,
     241,   242,   243,   -66,   245,   246,   247,     0,     0,     0,
     451,   240,   241,   242,   -70,   -70,   245,   246,   247,     0,
       0,     0,     0,     0,   -66,   240,   241,   242,   -74,   -74,
     -74,   246,   247,     0,     0,     0,   -70,   240,   241,   -78,
     -78,   -78,   -78,   246,   247,     0,     0,     0,     0,     0,
     -74,   240,   -89,   -89,   -89,   -89,   -89,   -89,   -89,     0,
       0,     0,   -78,   321,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,     0,     0,     0,     0,     0,   -89,   240,   241,   -84,
     -84,   -84,   -84,   246,   247,     0,     0,     0,   -88,   240,
     241,   -83,   -83,   -83,   -83,   246,   247,     0,     0,     0,
       0,     0,   -84,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,     0,     0,     0,   -83,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,     0,     0,     0,     0,     0,   -93,   240,
     241,   242,   243,   244,   245,   246,   247,     0,     0,     0,
     -92,   240,   241,   242,   243,   244,   245,   246,   247,     0,
       0,     0,     0,     0,   -61,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,     0,     0,     0,   490,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
     -96,   240,   241,   242,   243,   244,   245,   246,   247,     0,
       0,     0,   495,   240,   241,   242,   243,   244,   245,   246,
     247,     0,     0,     0,     0,     0,   498,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,   504,   240,
     241,   242,   243,   244,   245,   246,   247,     0,     0,     0,
       0,     0,   509,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,     0,     0,     0,   512,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,     0,     0,     0,     0,     0,  -111,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,
    -110,   240,   241,   242,   243,   244,   245,   246,   247,     0,
       0,     0,     0,     0,  -102,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,   608,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
     611,   240,   241,   242,   243,   244,   245,   246,   247,     0,
       0,     0,   618,   240,   241,   242,   243,   244,   245,   246,
     247,     0,     0,     0,     0,     0,   622,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,     0,     0,     0,   661,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,     0,     0,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
       0,  -108,  -108,    78,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,     0,     0,  -112,     0,  -112,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,     0,  -108,     0,   328,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,     0,     0,  -119,
    -119,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,     0,
       0,  -117,  -117,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,     0,     0,   -91,    76,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -101,     0,     0,   -95,   -95,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,     0,     0,  -101,  -101,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,     0,  -109,
    -109,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,     0,
       0,   -96,   -96,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,     0,     0,  -111,  -111,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,     0,     0,  -110,  -110,    75,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,     0,     0,  -102,  -102,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,   -87,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,     0,     0,
       0,   107,    75,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
       0,     0,   -94,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,     0,     0,     0,   -90,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,   -91,    46,    47,    48,    49,
     -66,    51,    52,    53,     0,     0,     0,   150,    46,    47,
      48,   -70,   -70,    51,    52,    53,     0,     0,   -66,    46,
      47,    48,   -74,   -74,   -74,    52,    53,     0,     0,     0,
     -70,    46,    47,   -78,   -78,   -78,   -78,    52,    53,     0,
       0,   -74,    46,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
       0,     0,     0,   -78,    75,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,     0,     0,   -89,    46,    47,   -84,   -84,   -84,
     -84,    52,    53,     0,     0,     0,   -88,    46,    47,   -83,
     -83,   -83,   -83,    52,    53,     0,     0,   -84,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,     0,     0,     0,   -83,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,     0,     0,
     -93,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,   -92,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,   -61,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,     0,     0,     0,   188,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,     0,     0,  -118,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,     0,     0,     0,  -119,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,     0,     0,  -117,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,     0,     0,
       0,   -95,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
       0,     0,  -101,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,     0,     0,     0,  -109,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,   -96,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,   448,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,     0,     0,   485,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,     0,
    -111,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,  -110,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,   500,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,     0,     0,   514,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,  -102,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,   574,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,   580,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
     591,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,     0,   613,   283,   284,   285,   286,   287,   288,   289,
     290,     0,     0,   651,   240,   241,   242,   243,   244,   245,
     246,   247
};

static const yytype_int16 yycheck[] =
{
       0,   255,   361,     0,   356,   324,     1,     1,    31,   328,
       1,     1,     1,     1,     1,     6,    16,    17,    32,    33,
      20,    31,     1,    20,     3,     4,     5,     6,     1,     8,
      19,    20,    19,    20,    29,    29,    15,    16,    17,    29,
       6,    29,     0,    32,   298,    32,    19,    20,     1,   408,
      31,   403,    31,    32,     6,     1,   375,    57,    58,    32,
      32,    33,    20,    29,    64,     0,     1,     1,     3,     4,
       5,     6,    11,     8,     6,     6,    29,    29,    78,    31,
      15,    16,    17,    29,    19,    20,     0,    22,    23,    24,
      25,    26,    27,    32,    33,    29,    31,    29,    29,    34,
       1,     1,     3,     4,     5,     6,    20,     8,     1,     6,
      31,     1,     1,   113,    15,    16,    17,     1,     0,   438,
      11,    22,    23,    24,    25,    26,    27,     6,     6,    29,
      31,    29,    29,    34,    31,    29,    29,   150,   151,    29,
      29,    32,   139,    21,    11,    29,    10,    11,   148,   149,
      29,    29,    31,    31,     6,   155,   475,     7,     8,     9,
      10,    11,    12,    13,    14,    32,   163,    32,    32,    21,
      10,    11,   172,     7,   187,   188,   189,    29,    11,    31,
      30,    31,    32,    33,   181,   185,   186,   187,   188,   189,
      32,     1,    32,     3,     4,     5,     6,    11,     8,    32,
      33,   201,   202,   203,   204,    15,    16,    17,    18,     6,
     569,   563,    10,    11,   214,    29,     0,     9,    10,    11,
      12,    31,     0,     1,    21,     3,     4,     5,     6,    32,
       8,    29,    29,   233,   148,   149,    20,    15,    16,    17,
      32,    19,    20,    32,    22,    23,    24,    25,    26,    27,
      11,    10,    11,    31,   254,    32,    34,    32,   172,     7,
       8,     9,    10,    11,    12,    13,    14,   267,    29,    10,
      11,   185,   186,    32,    33,     0,    29,    30,   532,     0,
       3,     4,     5,     6,    32,     8,    32,   201,   202,   203,
     204,    32,    15,    16,    17,    20,    29,   297,     6,    20,
       7,     8,     9,    10,    11,    12,    13,    14,    31,     9,
      10,    11,    12,    21,    29,     0,     1,     1,     3,     4,
       5,     6,     6,     8,   324,    32,    33,    32,   328,    29,
      15,    16,    17,   333,    19,    20,    35,    22,    23,    24,
      25,    26,    27,     6,     6,   358,    31,     1,     0,    34,
       9,    10,    11,    12,    29,     1,   356,   357,    21,    21,
       6,   361,    32,    33,   148,   149,    29,     1,    20,     3,
       4,     5,     6,    32,     8,   375,     9,    10,    11,    12,
     380,    15,    16,    17,     9,    10,    11,    12,   172,     7,
       8,     9,   405,    29,    12,    13,    14,    31,    32,    32,
      33,   185,   186,   403,   404,    32,   190,    32,   408,     8,
       9,    10,    11,    12,    13,    14,   200,   201,   202,   203,
     204,    10,    11,   148,   149,    32,    33,   148,   149,     9,
      10,    11,    12,    32,    33,    10,    11,    12,   438,     1,
      29,     3,     4,     5,     6,     1,     8,   172,    32,    33,
       6,   172,    32,    15,    16,    17,     6,    32,    33,    29,
     185,   186,    10,    11,   185,   186,    29,    10,    11,    31,
      32,     9,    10,    11,    12,   475,   201,   202,   203,   204,
     201,   202,   203,   204,    32,    33,    32,   500,   501,    32,
      33,    10,    11,    12,    32,    33,   148,   149,   498,   499,
      32,   514,   515,    34,     3,     4,     5,     6,    32,     8,
      29,    32,   512,   513,    32,    33,    15,    16,    17,    32,
     172,     7,     8,     9,    10,    11,    12,    13,    14,   529,
      32,   531,    31,   185,   186,    10,    11,    12,     0,     9,
      10,    11,    12,    32,    30,    31,    32,    33,    31,   201,
     202,   203,   204,   566,    31,   555,    29,    32,    20,    29,
     573,   574,   575,   563,   564,    31,   579,   580,   581,   569,
     570,    31,   572,   573,   574,   575,    31,   577,   578,   579,
     580,   581,    19,    20,   498,   499,    29,    30,    31,     7,
       8,     9,    10,    11,    12,    13,    14,    31,   512,   513,
     613,   614,     7,     8,     9,    10,    11,    12,    13,    14,
      31,   611,   612,     0,    32,   529,   616,   617,   618,   619,
     620,   621,   622,   623,    31,    30,    29,    32,    33,     7,
       8,     9,   632,    20,    12,    13,    14,   650,   651,   652,
       1,   555,    32,     9,    10,    11,    12,    32,   648,   649,
     650,   651,   652,    10,    11,    12,   570,    32,   572,   659,
     660,   661,   662,   577,   578,     1,    32,     3,     4,     5,
       6,    29,     8,    32,    33,    32,    33,     7,     8,    15,
      16,    17,     7,    13,    14,    32,   148,   149,     8,     9,
      10,    11,    12,    13,    14,    31,    32,   611,   612,    10,
      11,    12,   616,   617,   618,   619,   620,   621,   622,   623,
     172,     7,    32,     6,   498,   499,    32,    33,   632,    29,
      30,    32,    33,   185,   186,    10,    11,    12,   512,   513,
       9,    10,    11,    12,   648,   649,    10,    11,    12,   201,
     202,   203,   204,     6,    29,   659,   660,   661,   662,     1,
      29,     3,     4,     5,     6,    32,     8,    29,    32,    32,
      33,   148,   149,    15,    16,    17,     9,    10,    11,    12,
      32,   555,    32,   498,   499,    32,    32,   498,   499,    31,
      32,     9,    10,    11,    12,   172,    32,   512,   513,    32,
      33,   512,   513,   577,   578,    29,    30,    31,   185,   186,
       9,    10,    11,    12,    32,     1,    32,     3,     4,     5,
       6,    32,     8,    29,   201,   202,   203,   204,    35,    15,
      16,    17,    32,    32,    33,    10,    11,   611,   612,    32,
     555,    32,    32,    29,   555,    31,   620,   621,   622,   623,
       9,    10,    11,    12,    29,    32,   498,   499,   632,    32,
      32,    29,   577,   578,    35,    32,   577,   578,    29,    29,
     512,   513,    29,    32,   648,   649,     7,     8,     9,    10,
      11,    12,    13,    14,    32,   659,   660,   661,   662,    29,
       3,     4,     5,     6,    31,     8,   611,   612,    29,    30,
     611,   612,    15,    16,    17,   620,   621,   622,   623,   620,
     621,   622,   623,   555,    31,    31,    31,   632,    31,    29,
      29,   632,    29,    29,    29,     1,    29,     3,     4,     5,
       6,    32,     8,   648,   649,   577,   578,   648,   649,    15,
      16,    17,    32,    32,   659,   660,   661,   662,   659,   660,
     661,   662,    10,    11,    12,    31,    32,    32,    32,    29,
      32,     1,    35,     3,     4,     5,     6,    32,     8,   611,
     612,    32,    32,    32,    32,    15,    16,    17,   620,   621,
     622,   623,    22,    23,    24,    25,    26,    27,    32,    32,
     632,    31,    29,    29,    34,    29,     7,     8,     9,    10,
      11,    12,    13,    14,    29,    32,   648,   649,     0,     1,
      32,     3,     4,     5,     6,    20,     8,   659,   660,   661,
     662,    32,    33,    15,    16,    17,   181,    19,    20,   163,
      22,    23,    24,    25,    26,    27,    10,    11,    12,    31,
      -1,    -1,    34,    -1,   113,    -1,   498,   499,     0,     1,
      -1,     3,     4,     5,     6,    29,     8,    -1,    -1,    -1,
     512,   513,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,     7,     8,    31,
      -1,    -1,    34,    13,    14,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,     9,    10,    11,    12,    -1,
      15,    16,    17,   555,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    32,    34,
      -1,   498,   499,    -1,    -1,   577,   578,     1,    -1,     3,
       4,     5,     6,    -1,     8,   512,   513,    -1,    -1,     7,
       8,    15,    16,    17,    18,    13,    14,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    31,     8,   611,
     612,    -1,    -1,    -1,    -1,    15,    16,    17,   620,   621,
     622,   623,    22,    23,    24,    25,    26,    27,   555,    -1,
     632,    31,    -1,    -1,    34,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,   648,   649,    -1,    -1,
     577,   578,    15,    16,    17,    -1,    -1,   659,   660,   661,
     662,     9,    10,    11,    12,    -1,    29,    -1,    31,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    29,    -1,    -1,   611,   612,    15,    16,    17,    -1,
      -1,    -1,    -1,   620,   621,   622,   623,     7,     8,     9,
      29,    -1,    31,    13,    14,   632,    -1,    -1,    -1,    17,
      -1,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,   648,   649,     9,    10,    11,    12,    -1,     9,    10,
      11,    12,   659,   660,   661,   662,    44,    32,    46,    47,
      48,    49,    50,    51,    52,    53,    32,    33,    56,    57,
      58,    32,    33,    -1,    -1,     9,    10,    11,    12,    -1,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,     0,     1,    -1,     3,     4,     5,     6,    32,     8,
      -1,     9,    10,    11,    12,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    32,    34,    -1,    -1,   116,    -1,
      -1,    -1,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,     9,    10,    11,    12,    17,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    29,    31,    -1,    -1,    34,   155,    -1,    -1,
      -1,    -1,    -1,   161,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    57,    58,    15,    16,
      17,     7,     8,     9,    10,    11,    12,    13,    14,   187,
     188,   189,    29,    -1,    31,    76,    -1,    78,     9,    10,
      11,    12,    -1,    -1,    30,    31,    32,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,   214,    -1,    29,    -1,
      -1,    -1,    15,    16,    17,   223,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   233,   234,    -1,    31,    -1,
      -1,    34,   240,   241,   242,   243,   244,   245,   246,   247,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,     9,
      10,    11,    12,    -1,    15,    16,    17,    -1,    -1,   267,
      -1,    22,    23,    24,   155,    26,    27,    -1,   276,    29,
      31,    -1,    -1,    34,    -1,   283,   284,   285,   286,   287,
     288,   289,   290,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,   187,   188,   189,    15,
      16,    17,    18,    -1,    -1,    -1,   314,   315,   316,   317,
     318,   319,   320,   321,   322,    31,   324,    -1,    -1,    -1,
     328,    -1,    -1,   214,    -1,   333,    -1,   335,     7,     8,
       9,    10,    11,    12,    13,    14,     9,    10,    11,    12,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   355,   356,   357,
      -1,    30,    17,    32,    33,    -1,    29,   365,   366,   367,
     368,   369,   370,   371,   372,   373,    -1,   375,    -1,    -1,
      -1,    -1,   380,    -1,   382,    40,   267,     9,    10,    11,
      12,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    57,    58,   402,   403,   404,    -1,    -1,    -1,
      32,    33,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    -1,     9,    10,    11,    12,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
     438,   322,    -1,   324,    15,    16,    17,   328,    32,    33,
      -1,    -1,   333,     9,    10,    11,    12,    -1,    29,    -1,
      31,    -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,    -1,     8,    29,    -1,   356,   357,   475,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,   373,    -1,   375,    31,    -1,    -1,    34,   380,
     155,     9,    10,    11,    12,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,   403,   404,    32,    33,    22,    23,    24,    25,
      26,    27,   187,   188,   189,    31,    -1,    -1,    34,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,     9,    10,
      11,    12,    -1,    15,    16,    17,    -1,   438,    -1,   214,
       9,    10,    11,    12,   562,   563,   564,    29,   223,    31,
      -1,    32,    33,    -1,    -1,   573,   574,   575,   233,   234,
      29,   579,   580,   581,    -1,   240,   241,   242,   243,   244,
     245,   246,   247,     1,   475,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,     7,     8,     9,    15,    16,    17,
      13,    14,   267,    -1,    22,    23,    24,    25,    26,    27,
      -1,   276,    -1,    31,    -1,    -1,    34,    -1,   283,   284,
     285,   286,   287,   288,   289,   290,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,   650,   651,   652,    -1,    15,    16,    17,   314,
     315,   316,   317,   318,   319,   320,   321,   322,    -1,   324,
      29,    -1,    31,   328,    -1,    -1,    -1,    -1,   333,    -1,
     335,    -1,   563,   564,     7,     8,     9,    10,    11,    12,
      13,    14,   573,   574,   575,    -1,    -1,    -1,   579,   580,
     581,   356,   357,    -1,    -1,    17,    -1,    30,    31,    32,
     365,   366,   367,   368,   369,   370,   371,   372,   373,    -1,
     375,    -1,     7,     8,     9,   380,    -1,   382,    13,    14,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    -1,   403,   404,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    78,    -1,    -1,   650,
     651,   652,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,   438,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
     475,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    -1,   155,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   187,   188,   189,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    -1,   214,    -1,    -1,    -1,    -1,    -1,   563,   564,
      -1,   223,    -1,    31,    -1,    -1,    -1,    -1,   573,   574,
     575,   233,   234,    -1,   579,   580,   581,    -1,   240,   241,
     242,   243,   244,   245,   246,   247,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,   267,    -1,    22,    23,    24,
      25,    26,    27,    -1,   276,    -1,    31,    -1,    -1,    34,
      -1,   283,   284,   285,   286,   287,   288,   289,   290,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,   650,   651,   652,    -1,    15,
      16,    17,   314,   315,   316,   317,   318,   319,   320,   321,
     322,    -1,   324,    29,    -1,    31,   328,    -1,    -1,    -1,
      -1,   333,     1,   335,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,   356,   357,    -1,    -1,    17,    -1,
      29,    -1,    31,   365,   366,   367,   368,   369,   370,   371,
     372,   373,    -1,   375,    -1,    -1,    -1,    -1,   380,    -1,
     382,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      -1,   403,   404,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    78,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,   438,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,   475,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    -1,   155,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,   187,   188,
     189,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,   214,    -1,    -1,    -1,    -1,
      -1,   563,   564,    -1,   223,    -1,    31,    -1,    -1,    -1,
      -1,   573,   574,   575,   233,   234,    -1,   579,   580,   581,
      -1,   240,   241,   242,   243,   244,   245,   246,   247,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,   267,    -1,
      22,    23,    24,    25,    26,    27,    -1,   276,    -1,    31,
      -1,    -1,    34,    -1,   283,   284,   285,   286,   287,   288,
     289,   290,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,   650,   651,
     652,    15,    16,    17,    -1,   314,   315,   316,   317,   318,
     319,   320,   321,   322,    -1,   324,    -1,    31,    -1,   328,
      -1,    -1,    -1,    -1,   333,     1,   335,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,   356,   357,    -1,
      -1,    17,    -1,    -1,    -1,    31,   365,   366,   367,   368,
     369,   370,   371,   372,   373,    -1,   375,    -1,    -1,    -1,
      -1,   380,    -1,   382,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    57,    58,    -1,   403,   404,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,   438,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,   475,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,   155,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,   187,   188,   189,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,   214,    -1,
      -1,    -1,    -1,    -1,   563,   564,    -1,   223,    -1,    31,
      -1,    -1,    -1,    -1,   573,   574,   575,   233,   234,    -1,
     579,   580,   581,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,   267,    -1,    22,    23,    24,    25,    26,    27,    -1,
     276,    -1,    31,    -1,    -1,    34,    -1,   283,   284,   285,
     286,   287,   288,   289,   290,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,   650,   651,   652,    15,    16,    17,    -1,   314,   315,
     316,   317,   318,   319,   320,   321,   322,    -1,   324,    -1,
      31,    -1,   328,    -1,    -1,    -1,    -1,   333,     1,   335,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
     356,   357,    -1,    -1,    17,    -1,    -1,    -1,    31,   365,
     366,   367,   368,   369,   370,   371,   372,   373,    -1,   375,
      -1,    -1,    -1,    -1,   380,    -1,   382,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    -1,   403,   404,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    78,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,   438,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,   475,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      -1,    -1,   155,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,   187,   188,   189,    31,    -1,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,     7,     8,     9,
      10,   214,    12,    13,    14,    -1,    -1,   563,   564,    31,
     223,    -1,    -1,    -1,    -1,    -1,    -1,   573,   574,   575,
     233,   234,    -1,   579,   580,   581,    -1,   240,   241,   242,
     243,   244,   245,   246,   247,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,   267,    -1,    22,    23,    24,    -1,
      26,    27,    -1,   276,    -1,    31,    -1,    -1,    34,    -1,
     283,   284,   285,   286,   287,   288,   289,   290,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,   650,   651,   652,    15,    16,    17,
      -1,   314,   315,   316,   317,   318,   319,   320,   321,   322,
      -1,   324,    -1,    31,    -1,   328,    -1,    -1,    -1,    -1,
     333,     1,   335,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,   356,   357,    -1,    -1,    17,    -1,    -1,
      -1,    31,   365,   366,   367,   368,   369,   370,   371,   372,
     373,    -1,   375,    -1,    -1,    -1,    -1,   380,    -1,   382,
       1,    -1,     3,     4,     5,     6,    -1,     8,    48,    -1,
      -1,    -1,    52,    53,    15,    16,    17,    57,    58,    -1,
     403,   404,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      31,    71,    -1,    73,    74,    15,    16,    17,    78,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    31,    -1,    -1,    -1,   438,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    -1,    -1,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,   475,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    -1,    -1,   155,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,   187,   188,   189,
      31,    -1,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
       7,     8,     9,    10,   214,    12,    13,    14,    -1,    -1,
     563,   564,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     573,   574,   575,   233,    -1,    -1,   579,   580,   581,    -1,
      -1,    -1,   242,   243,   244,   245,   246,   247,    -1,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,   267,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    -1,   285,   286,   287,   288,   289,
     290,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,   650,   651,   652,
      15,    16,    17,    -1,   314,   315,   316,   317,    -1,   319,
     320,    17,   322,    -1,   324,    -1,    31,    -1,   328,    -1,
      -1,    -1,    -1,   333,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    47,    -1,     7,     8,     9,   356,   357,    12,    13,
      14,    57,    58,    -1,    31,   365,   366,   367,   368,    -1,
     370,   371,    -1,   373,    -1,   375,    72,    -1,    -1,    -1,
     380,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,   403,   404,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,   438,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,   155,
      34,    -1,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,   475,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,   187,   188,   189,    31,    17,    -1,    34,    -1,    -1,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,   214,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    57,    58,   233,     8,     9,
      10,    11,    12,    13,    14,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,    78,    -1,    -1,    29,
      -1,    -1,    -1,   563,   564,    -1,    -1,    -1,    -1,    -1,
      -1,   267,    -1,   573,   574,   575,    -1,    -1,    -1,   579,
     580,   581,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,
     286,   287,   288,   289,   290,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    17,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,   314,   315,
     316,   317,   318,   319,   320,    -1,   322,    -1,   324,    -1,
      -1,    31,   328,   155,    -1,    -1,    51,   333,    -1,    -1,
      -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
     650,   651,   652,    -1,    -1,    70,    -1,    -1,    -1,    -1,
     356,   357,    -1,    78,    -1,   187,   188,   189,    -1,   365,
     366,   367,   368,   369,   370,   371,    -1,   373,    -1,   375,
      -1,    -1,    -1,     1,   380,     3,     4,     5,     6,    -1,
       8,    -1,   214,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   403,   404,    -1,
      -1,   233,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
     242,   243,   244,   245,   246,   247,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,   438,    -1,    -1,   267,    -1,    -1,    -1,    30,
      -1,    32,    33,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,   285,   286,   287,   288,   289,   290,    15,
      16,    17,   187,   188,   189,    -1,    22,    23,    24,   475,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    -1,   314,   315,   316,   317,    -1,   319,   320,   214,
     322,    -1,   324,    -1,    -1,    -1,   328,    -1,    -1,    -1,
       1,   333,     3,     4,     5,     6,    -1,     8,   233,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,   243,   244,
     245,    -1,    -1,    -1,   356,   357,    -1,    -1,    -1,    -1,
      31,    -1,    -1,   365,   366,   367,   368,    -1,   370,   371,
      -1,   373,   267,   375,     7,     8,     9,    10,   380,    12,
      13,    14,    -1,    -1,    -1,    17,    -1,   563,   564,    -1,
      -1,   286,   287,   288,    -1,    -1,    -1,   573,   574,   575,
      -1,   403,   404,   579,   580,   581,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    49,    -1,   314,
     315,   316,    -1,    -1,    -1,    57,    58,   322,    -1,   324,
      -1,    -1,    30,   328,    32,    33,   438,    69,   333,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,   356,   357,    15,    16,    17,    -1,    -1,    -1,    -1,
     365,   366,   367,   475,   650,   651,   652,    -1,   373,    31,
     375,    -1,    -1,    -1,    -1,   380,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,   403,   404,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,   155,    -1,    -1,    31,    -1,    -1,    34,
      -1,    -1,    -1,     1,    17,     3,     4,     5,     6,    -1,
       8,    -1,    -1,   438,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,    -1,
      -1,   563,   564,    31,    -1,    -1,    -1,    50,    -1,    -1,
      -1,   573,   574,   575,    57,    58,    -1,   579,   580,   581,
     475,    -1,   214,    -1,     1,    68,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    78,    -1,    -1,    15,    16,
      17,   233,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,   243,   244,    -1,    31,    -1,    -1,    34,    35,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,   267,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    31,   650,   651,
     652,    15,    16,    17,   286,   287,    -1,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,   563,   564,
      34,    -1,   155,    -1,    -1,    -1,    -1,    -1,   573,   574,
     575,    -1,   314,   315,   579,   580,   581,    -1,    -1,    -1,
     322,    -1,   324,    -1,    -1,    -1,   328,    -1,    -1,    -1,
      -1,   333,    -1,    -1,   187,   188,   189,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,   356,   357,    -1,    -1,    -1,    -1,
      -1,   214,    -1,   365,   366,    -1,    -1,    31,    -1,    -1,
      -1,   373,    -1,   375,    -1,    -1,    -1,    -1,   380,    -1,
     233,    -1,    -1,    -1,    -1,   650,   651,   652,    -1,    -1,
      -1,   244,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,   403,   404,    -1,     0,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,   267,    30,    -1,    32,    33,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,   287,    31,   438,    -1,    34,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,   314,    -1,     1,    -1,     3,     4,     5,     6,   322,
       8,   324,    31,   475,    -1,   328,    -1,    15,    16,    17,
     333,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,   356,   357,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   365,    -1,     1,    -1,     3,     4,     5,     6,
     373,     8,   375,    -1,    -1,    -1,    -1,   380,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,
     403,   404,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,   563,   564,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,   573,   574,   575,    -1,    -1,    -1,   579,   580,   581,
      -1,    -1,    31,     0,     1,   438,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
       0,     1,   475,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,   650,   651,
     652,    31,    -1,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
     563,   564,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
     573,   574,   575,    -1,    -1,    -1,   579,   580,   581,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,   650,   651,   652,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     0,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     0,     1,    -1,     3,     4,     5,     6,    -1,
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
      -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
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
      -1,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
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
      35,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,     0,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
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
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,     1,     8,     3,     4,     5,     6,    -1,     8,    15,
      16,    17,    -1,    -1,    -1,    15,    16,    17,    -1,     1,
      -1,     3,     4,     5,     6,    31,     8,    -1,    -1,    -1,
      -1,    31,    -1,    15,    16,    17,     1,    -1,     3,     4,
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
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    31,    15,    16,    17,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      31,    15,    16,    17,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,
      17,    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    31,    15,    16,    17,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    31,    15,    16,    17,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    31,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    30,    -1,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    30,    -1,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    30,    -1,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      31,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    31,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    30,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    30,
      -1,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    30,    -1,    32,    33,     7,     8,     9,
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
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
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
      12,    13,    14,    -1,    -1,    31,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    31,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    30,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    30,    -1,    32,     7,
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
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    29,
      30,    31,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    29,    30,    31,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    29,    -1,    31,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    29,    -1,    31,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    29,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    29,    30,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    29,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    29,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    29,    30,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    29,    30,     7,
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
      13,    14
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
       1,    60,     1,    60,    50,     0,    39,    29,    11,    10,
      12,     9,     8,    13,    14,     7,    30,    69,    31,    29,
      31,    75,    69,     1,    68,    69,     1,    66,     1,    64,
       1,    63,     1,    65,    66,    66,     1,    75,     1,    18,
      60,    78,     1,    60,     1,    60,    61,    29,    29,    32,
      32,    40,    51,    52,    53,    54,    76,     1,    63,     1,
      64,     1,    65,     1,    66,     1,    68,     1,    66,     1,
      66,     1,    69,     1,    62,     1,    60,    72,    73,    44,
      29,    30,    31,    32,    32,    32,    32,    32,    32,    32,
      29,    29,    35,    53,    75,    33,    32,     1,    46,    47,
      48,    76,     1,    42,    29,     1,    29,    29,     1,    29,
       1,    29,    25,    54,    25,    54,    61,     1,    61,    60,
      45,    33,    75,    46,    54,    25,    25,    29,    29,    29,
      32,    48,    43,    54,    54,    61,    61,     1,    61,    49,
      32,    32,    32,    32,    32,    49,    54,    54,    54,    54,
       3,     4,     5,     6,    31,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    74,    75,    77,     6,     3,
       4,     5,     6,    31,    70,    71,    74,    75,    77,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    19,    20,
      22,    23,    24,    26,    27,    34,    49,    55,    56,    57,
      58,    59,    60,     3,     4,     5,     6,    31,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    74,    75,
      77,     6,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    19,    20,    22,    23,    24,    26,    27,    34,    49,
      55,    56,    57,    58,    59,    60,    29,    30,     1,     6,
       1,    60,     1,    60,    11,    10,    12,     9,     8,    13,
      14,     7,    30,    69,    31,     1,    60,    69,    31,     3,
       4,     5,     6,    31,    69,    70,    71,    74,    75,    77,
       1,    68,    69,     1,    66,     1,    64,     1,    63,     1,
      65,    66,    66,    21,    21,    31,    31,    31,    31,     1,
      60,    50,    29,     1,    60,    11,    10,    12,     9,     8,
      13,    14,     7,    30,    69,    31,     3,     4,     5,     6,
      31,    69,    70,    71,    74,    75,    77,     1,    68,    69,
       1,    66,     1,    64,     1,    63,     1,    65,    66,    66,
      21,    21,    31,    31,    31,    31,     1,    60,    50,    29,
       1,    32,    32,     1,    63,     1,    64,     1,    65,     1,
      66,     1,    68,     1,    66,     1,    66,     1,    69,     1,
      62,    73,    32,    32,    73,     1,    60,    69,    31,     1,
      75,     1,    60,    78,     1,    60,     1,    61,    29,    29,
      51,    32,    32,     1,    63,     1,    64,     1,    65,     1,
      66,     1,    68,     1,    66,     1,    66,     1,    69,     1,
      62,    73,     1,    60,    69,    31,     1,    75,     1,    60,
      78,     1,    60,     1,    61,    29,    29,    51,    32,    32,
      32,    32,    73,    32,    32,    32,    32,    32,    32,    32,
      29,    29,    35,    32,    32,    32,    73,    32,    32,    32,
      32,    32,    32,    32,    29,    29,    35,    32,    29,     1,
      29,    29,     1,    29,     1,    29,    22,    23,    24,    25,
      26,    27,    34,    49,    54,    55,    56,    57,    58,    59,
      60,    25,    54,    61,     1,    61,    32,    29,     1,    29,
      29,     1,    29,     1,    29,    25,    54,    25,    54,    61,
       1,    61,    31,    31,    31,    54,    31,     1,    60,    50,
      25,    29,    25,    29,    29,    29,    54,    25,    25,    29,
      29,    29,     1,    75,     1,    60,    78,     1,    60,     1,
      61,    29,    29,    51,    54,    54,    61,    61,     1,    61,
      54,    54,    61,    61,     1,    61,    32,    32,    32,    32,
      32,    32,    32,    29,    29,    35,    32,    32,    32,    32,
      32,    32,    32,    32,    29,     1,    29,    29,     1,    29,
       1,    29,    25,    54,    25,    54,    61,     1,    61,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    25,    25,
      29,    29,    29,    54,    54,    61,    61,     1,    61,    32,
      32,    32,    32,    54,    54,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    39,    40,
      40,    40,    42,    43,    41,    44,    45,    41,    46,    46,
      47,    47,    47,    48,    50,    49,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    59,    59,    59,    60,
      60,    60,    61,    61,    62,    62,    62,    62,    63,    63,
      63,    63,    64,    64,    64,    64,    65,    65,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    70,
      70,    71,    71,    72,    72,    72,    73,    73,    74,    74,
      74,    74,    75,    76,    76,    76,    76,    77,    77,    77,
      78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     3,
       2,     4,     0,     0,     8,     0,     0,     7,     0,     1,
       3,     1,     1,     2,     0,     4,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     5,     5,     5,     5,     5,     2,     5,     7,     5,
       5,     7,     6,     3,     3,     9,     9,     9,     9,     1,
       3,     3,     0,     1,     1,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     1,     2,     1,     1,     1,
       1,     1,     4,     3,     1,     1,     1,     0,     1,     1,
       3,     3,     1,     1,     1,     2,     2,     1,     1,     1,
       1
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
#line 144 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3854 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3860 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3866 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3872 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3878 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3884 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3890 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3896 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3902 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3908 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3914 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3920 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3926 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3932 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3938 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3944 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3950 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3956 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3962 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3968 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3974 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_1: /* @1  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3980 "src/bison/grammar.c"
        break;

    case YYSYMBOL_46_param_list_opt: /* param_list.opt  */
#line 146 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3986 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 146 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3992 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3998 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4004 "src/bison/grammar.c"
        break;

    case YYSYMBOL_51_block_item_list_opt: /* block_item_list.opt  */
#line 146 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4010 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 146 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4016 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4022 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4028 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4034 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4040 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4046 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4052 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4058 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4064 "src/bison/grammar.c"
        break;

    case YYSYMBOL_61_expression_opt: /* expression.opt  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4070 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4076 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4082 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4088 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4094 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4100 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4106 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4112 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4118 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4124 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4130 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 146 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4136 "src/bison/grammar.c"
        break;

    case YYSYMBOL_73_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 146 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4142 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4148 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 144 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 4154 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 143 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4160 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4166 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 145 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4172 "src/bison/grammar.c"
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
#line 150 "src/bison/grammar.y"
             { show_error((yyloc), "ISO C-IPL forbids an empty translation unit\n"); }
#line 4481 "src/bison/grammar.c"
    break;

  case 4: /* external_declaration_list: external_declaration_list external_declaration  */
#line 153 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4487 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration  */
#line 154 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4493 "src/bison/grammar.c"
    break;

  case 8: /* external_declaration: statement  */
#line 159 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4503 "src/bison/grammar.c"
    break;

  case 9: /* var_declaration: type id ';'  */
#line 166 "src/bison/grammar.y"
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
#line 4530 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type ';'  */
#line 188 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4540 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type id '=' error  */
#line 193 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4551 "src/bison/grammar.c"
    break;

  case 12: /* @1: %empty  */
#line 201 "src/bison/grammar.y"
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
#line 4592 "src/bison/grammar.c"
    break;

  case 13: /* $@2: %empty  */
#line 236 "src/bison/grammar.y"
                     {
        is_fn_blck = true;
    }
#line 4600 "src/bison/grammar.c"
    break;

  case 14: /* func_declaration: type id '(' @1 param_list.opt $@2 ')' compound_stmt  */
#line 238 "src/bison/grammar.y"
                        {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4610 "src/bison/grammar.c"
    break;

  case 15: /* $@3: %empty  */
#line 243 "src/bison/grammar.y"
               {
        previous_context = current_context;
        list_push(&contexts, context_init("invalid"));
        current_context = list_peek_last(&contexts);
    }
#line 4620 "src/bison/grammar.c"
    break;

  case 16: /* $@4: %empty  */
#line 247 "src/bison/grammar.y"
                     {
        is_fn_blck = true;
    }
#line 4628 "src/bison/grammar.c"
    break;

  case 17: /* func_declaration: type '(' $@3 param_list.opt $@4 ')' compound_stmt  */
#line 249 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-5]), "expected identifier before " WHT "'('" RESET "\n");
        free((yyvsp[-6].pchar));
        LIST_FREE((yyvsp[-3].list), { ast_free(__IT__->data); });
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
        current_context = previous_context;
    }
#line 4641 "src/bison/grammar.c"
    break;

  case 18: /* param_list.opt: %empty  */
#line 259 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4647 "src/bison/grammar.c"
    break;

  case 20: /* params_list: params_list ',' param_decl  */
#line 263 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4653 "src/bison/grammar.c"
    break;

  case 21: /* params_list: param_decl  */
#line 264 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4659 "src/bison/grammar.c"
    break;

  case 22: /* params_list: error  */
#line 265 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4668 "src/bison/grammar.c"
    break;

  case 23: /* param_decl: type id  */
#line 271 "src/bison/grammar.y"
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
#line 4685 "src/bison/grammar.c"
    break;

  case 24: /* $@5: %empty  */
#line 285 "src/bison/grammar.y"
                   {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        if (!is_fn_blck) context_push_scope(current_context);
        is_fn_blck = false;
    }
#line 4695 "src/bison/grammar.c"
    break;

  case 25: /* compound_stmt: '{' $@5 block_item_list.opt '}'  */
#line 289 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 4707 "src/bison/grammar.c"
    break;

  case 26: /* block_item_list.opt: block_item_list  */
#line 298 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4713 "src/bison/grammar.c"
    break;

  case 27: /* block_item_list.opt: %empty  */
#line 299 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4719 "src/bison/grammar.c"
    break;

  case 28: /* block_item_list: block_item_list block_item  */
#line 302 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4725 "src/bison/grammar.c"
    break;

  case 29: /* block_item_list: block_item  */
#line 303 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4731 "src/bison/grammar.c"
    break;

  case 38: /* io_stmt: READ '(' id ')' ';'  */
#line 318 "src/bison/grammar.y"
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
#line 4747 "src/bison/grammar.c"
    break;

  case 39: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 329 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_builtinfn_init((yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4756 "src/bison/grammar.c"
    break;

  case 40: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 333 "src/bison/grammar.y"
                                       {
        (yyval.ast) = ast_builtinfn_init((yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4765 "src/bison/grammar.c"
    break;

  case 41: /* io_stmt: WRITE '(' error ')' ';'  */
#line 337 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4775 "src/bison/grammar.c"
    break;

  case 42: /* io_stmt: READ '(' error ')' ';'  */
#line 342 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4785 "src/bison/grammar.c"
    break;

  case 43: /* io_stmt: READ '(' id ')' error  */
#line 347 "src/bison/grammar.y"
                            {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4796 "src/bison/grammar.c"
    break;

  case 44: /* io_stmt: WRITE '(' expression ')' error  */
#line 353 "src/bison/grammar.y"
                                     {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4807 "src/bison/grammar.c"
    break;

  case 45: /* io_stmt: WRITE '(' string_literal ')' error  */
#line 359 "src/bison/grammar.y"
                                         {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4818 "src/bison/grammar.c"
    break;

  case 46: /* expr_stmt: expression ';'  */
#line 367 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 4824 "src/bison/grammar.c"
    break;

  case 47: /* cond_stmt: IF '(' expression ')' statement  */
#line 370 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 4832 "src/bison/grammar.c"
    break;

  case 48: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 373 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4840 "src/bison/grammar.c"
    break;

  case 49: /* cond_stmt: IF '(' expression ')' ELSE  */
#line 376 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4850 "src/bison/grammar.c"
    break;

  case 50: /* cond_stmt: IF '(' error ')' statement  */
#line 381 "src/bison/grammar.y"
                                            {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4860 "src/bison/grammar.c"
    break;

  case 51: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 386 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4871 "src/bison/grammar.c"
    break;

  case 52: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 392 "src/bison/grammar.y"
                                      {
        show_error((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4881 "src/bison/grammar.c"
    break;

  case 53: /* jmp_stmt: RETURN expression ';'  */
#line 399 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 4887 "src/bison/grammar.c"
    break;

  case 54: /* jmp_stmt: RETURN error ';'  */
#line 400 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 4896 "src/bison/grammar.c"
    break;

  case 55: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 406 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4904 "src/bison/grammar.c"
    break;

  case 56: /* iter_stmt: FOR '(' error ';' expression.opt ';' expression.opt ')' statement  */
#line 409 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-6]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4916 "src/bison/grammar.c"
    break;

  case 57: /* iter_stmt: FOR '(' expression.opt ';' error ';' expression.opt ')' statement  */
#line 416 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-4]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4928 "src/bison/grammar.c"
    break;

  case 58: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' error ')' statement  */
#line 423 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4940 "src/bison/grammar.c"
    break;

  case 60: /* expression: unary_expr '=' logical_or_expr  */
#line 433 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 4946 "src/bison/grammar.c"
    break;

  case 61: /* expression: unary_expr '=' error  */
#line 434 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4956 "src/bison/grammar.c"
    break;

  case 62: /* expression.opt: %empty  */
#line 441 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 4962 "src/bison/grammar.c"
    break;

  case 65: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 446 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4971 "src/bison/grammar.c"
    break;

  case 66: /* logical_or_expr: logical_or_expr OR error  */
#line 450 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4981 "src/bison/grammar.c"
    break;

  case 67: /* logical_or_expr: error OR logical_and_expr  */
#line 455 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4991 "src/bison/grammar.c"
    break;

  case 69: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 463 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5000 "src/bison/grammar.c"
    break;

  case 70: /* logical_and_expr: logical_and_expr AND error  */
#line 467 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5010 "src/bison/grammar.c"
    break;

  case 71: /* logical_and_expr: error AND eq_expr  */
#line 472 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5020 "src/bison/grammar.c"
    break;

  case 73: /* eq_expr: eq_expr EQ rel_expr  */
#line 480 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5029 "src/bison/grammar.c"
    break;

  case 74: /* eq_expr: eq_expr EQ error  */
#line 484 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5039 "src/bison/grammar.c"
    break;

  case 75: /* eq_expr: error EQ rel_expr  */
#line 489 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5049 "src/bison/grammar.c"
    break;

  case 77: /* rel_expr: rel_expr REL list_expr  */
#line 497 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5058 "src/bison/grammar.c"
    break;

  case 78: /* rel_expr: rel_expr REL error  */
#line 501 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5068 "src/bison/grammar.c"
    break;

  case 79: /* rel_expr: error REL list_expr  */
#line 506 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5078 "src/bison/grammar.c"
    break;

  case 81: /* list_expr: add_expr DL_DG list_expr  */
#line 514 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5087 "src/bison/grammar.c"
    break;

  case 82: /* list_expr: add_expr COLON list_expr  */
#line 518 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5096 "src/bison/grammar.c"
    break;

  case 83: /* list_expr: add_expr DL_DG error  */
#line 522 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5106 "src/bison/grammar.c"
    break;

  case 84: /* list_expr: add_expr COLON error  */
#line 527 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5116 "src/bison/grammar.c"
    break;

  case 85: /* list_expr: error DL_DG list_expr  */
#line 532 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5126 "src/bison/grammar.c"
    break;

  case 86: /* list_expr: error COLON list_expr  */
#line 537 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5136 "src/bison/grammar.c"
    break;

  case 88: /* add_expr: add_expr ADD mult_expr  */
#line 545 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5145 "src/bison/grammar.c"
    break;

  case 89: /* add_expr: add_expr ADD error  */
#line 549 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5155 "src/bison/grammar.c"
    break;

  case 90: /* add_expr: error ADD mult_expr  */
#line 554 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5165 "src/bison/grammar.c"
    break;

  case 92: /* mult_expr: mult_expr MULT unary_expr  */
#line 562 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5174 "src/bison/grammar.c"
    break;

  case 93: /* mult_expr: mult_expr MULT error  */
#line 566 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5184 "src/bison/grammar.c"
    break;

  case 94: /* mult_expr: error MULT unary_expr  */
#line 571 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5194 "src/bison/grammar.c"
    break;

  case 96: /* unary_expr: unary_ops unary_expr  */
#line 579 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5203 "src/bison/grammar.c"
    break;

  case 102: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 592 "src/bison/grammar.y"
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
#line 5226 "src/bison/grammar.c"
    break;

  case 103: /* arg_expr_list: arg_expr_list ',' expression  */
#line 612 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5232 "src/bison/grammar.c"
    break;

  case 104: /* arg_expr_list: expression  */
#line 613 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5238 "src/bison/grammar.c"
    break;

  case 105: /* arg_expr_list: error  */
#line 614 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5247 "src/bison/grammar.c"
    break;

  case 107: /* arg_expr_list.opt: %empty  */
#line 621 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5253 "src/bison/grammar.c"
    break;

  case 108: /* primary_expr: id  */
#line 624 "src/bison/grammar.y"
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
#line 5268 "src/bison/grammar.c"
    break;

  case 110: /* primary_expr: '(' expression ')'  */
#line 635 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 5274 "src/bison/grammar.c"
    break;

  case 111: /* primary_expr: '(' error ')'  */
#line 636 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5283 "src/bison/grammar.c"
    break;

  case 115: /* type: INT LIST  */
#line 647 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5295 "src/bison/grammar.c"
    break;

  case 116: /* type: FLOAT LIST  */
#line 654 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5307 "src/bison/grammar.c"
    break;

  case 117: /* constant: NUMBER_REAL  */
#line 663 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5313 "src/bison/grammar.c"
    break;

  case 118: /* constant: NUMBER_INT  */
#line 664 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5319 "src/bison/grammar.c"
    break;

  case 119: /* constant: NIL  */
#line 665 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5325 "src/bison/grammar.c"
    break;

  case 120: /* string_literal: STR_LITERAL  */
#line 668 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5334 "src/bison/grammar.c"
    break;


#line 5338 "src/bison/grammar.c"

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

#line 674 "src/bison/grammar.y"


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
