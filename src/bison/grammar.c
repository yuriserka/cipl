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
        STACK_FOR_EACH(current_context->scopes, {
            if (((Scope *)__IT__->data)->index == current_context->current_scope) {
                return __IT__;
            }
        });
        return NULL;
    }

    #define show_error_end(__R__, __FMT__, ...) {                  \
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


#line 158 "src/bison/grammar.c"

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
  YYSYMBOL_else_error = 58,                /* else_error  */
  YYSYMBOL_jmp_stmt = 59,                  /* jmp_stmt  */
  YYSYMBOL_iter_stmt = 60,                 /* iter_stmt  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_62_expression_opt = 62,         /* expression.opt  */
  YYSYMBOL_logical_or_expr = 63,           /* logical_or_expr  */
  YYSYMBOL_logical_and_expr = 64,          /* logical_and_expr  */
  YYSYMBOL_eq_expr = 65,                   /* eq_expr  */
  YYSYMBOL_rel_expr = 66,                  /* rel_expr  */
  YYSYMBOL_list_expr = 67,                 /* list_expr  */
  YYSYMBOL_add_expr = 68,                  /* add_expr  */
  YYSYMBOL_mult_expr = 69,                 /* mult_expr  */
  YYSYMBOL_unary_expr = 70,                /* unary_expr  */
  YYSYMBOL_unary_ops = 71,                 /* unary_ops  */
  YYSYMBOL_postfix_expr = 72,              /* postfix_expr  */
  YYSYMBOL_arg_expr_list = 73,             /* arg_expr_list  */
  YYSYMBOL_74_arg_expr_list_opt = 74,      /* arg_expr_list.opt  */
  YYSYMBOL_primary_expr = 75,              /* primary_expr  */
  YYSYMBOL_id = 76,                        /* id  */
  YYSYMBOL_type = 77,                      /* type  */
  YYSYMBOL_constant = 78,                  /* constant  */
  YYSYMBOL_string_literal = 79             /* string_literal  */
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
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11396

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  708

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
       0,   135,   135,   136,   137,   144,   145,   148,   149,   150,
     157,   181,   186,   192,   198,   204,   209,   216,   254,   216,
     259,   264,   259,   274,   275,   278,   279,   280,   286,   300,
     305,   312,   312,   333,   334,   337,   338,   341,   342,   343,
     346,   347,   348,   349,   350,   351,   354,   365,   369,   373,
     378,   383,   389,   395,   401,   406,   413,   414,   418,   422,
     426,   430,   436,   439,   442,   448,   453,   459,   464,   470,
     475,   482,   483,   489,   492,   499,   506,   513,   517,   521,
     528,   534,   542,   543,   554,   559,   566,   567,   570,   571,
     575,   580,   587,   588,   592,   597,   604,   605,   609,   614,
     621,   622,   626,   631,   638,   639,   643,   647,   652,   657,
     662,   669,   670,   674,   679,   686,   687,   691,   696,   703,
     704,   710,   711,   712,   713,   716,   717,   737,   738,   739,
     745,   746,   749,   759,   760,   767,   771,   778,   781,   782,
     783,   790,   799,   800,   801,   804
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
  "io_stmt", "expr_stmt", "cond_stmt", "else_error", "jmp_stmt",
  "iter_stmt", "expression", "expression.opt", "logical_or_expr",
  "logical_and_expr", "eq_expr", "rel_expr", "list_expr", "add_expr",
  "mult_expr", "unary_expr", "unary_ops", "postfix_expr", "arg_expr_list",
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

#define YYPACT_NINF (-419)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-146)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    7124,    15, 11056, 11067, 11079,  2187,  1336,  3037,  4553,  9837,
     318,   339,     6,    12,    18,    29,  2605,  2655,   117,    10,
    7156,  7188,  7220,  7252,  7284,  7316,  7348,  7380,  7412,  7444,
    7476,   -17,    44,   630,   593,  1061,  1250,  4309, 11090, 11102,
    9854, 11113, 11125,  2501,    30, 11136,  9854,  2908,  2956,  3090,
    3191,  3296,  2956,  2956,  7508,  7540,  7572,  7604,  3332,  7636,
     164,   168,  7668,     3,  7700,   252,  7732,  3338,  7764,   388,
    4465,   -15,  2453,  3453,   -14,   532,  -419,  3690,  7796,  7828,
    3485,  3600,  3645,  3651,  3786,  3896,  3902,  3947, 11148,   676,
   11159,  3992,  1663,   413,   568,  7860,    32,   664, 11171,    73,
   11182,  1287,  1750,  2487,  1147,  3461,   635,  2166,  1980,  2157,
    2294, 11355,    84,    38,    99,  4762,   106,   132,   147, 10278,
     162, 10200,    49,   169,  7892,  7924, 11194, 11205,  2818,  8980,
     608,   178,   910,  1034,  1076,  1121,   176, 11217,   936, 11228,
    1696, 11240,  2378, 11251,  2419, 11263, 11274, 11286,  2469, 11297,
    2692, 11309, 11320, 11332,   225,   887,   466,   481,   205,  7956,
     258,  7988,    34,  8020,   272,   148,   259,    46,   263,    61,
      90,  1222,  4202,   458,  8052,   480,  8980,  1162,  8084,  1435,
     512,  4035, 11343,  8116,   718,   249,   748,   819,   931,   347,
    8148,    34,  8180,  8212,  8244,  8276,  8308,  8340,  8372,  8404,
    9012,  1479,  9012,  1749,  3560,   -21, 10213,    39,  1781,   947,
     296,   806,   998,   300,  8436,  9012,  8468,  9012,  1855,  9012,
    1855,  9012,  1965,  9012,   302,  1030,   311,  8500,  8532,   327,
    8564,   332,  8596, 10291,   334,  8628,  8660,   302,  9012,  9012,
    9012,  9012,  8692,  8724,  8756,  8788,  8820,  2588,   706,  1197,
    2767,  1558,  4147,    77,   151,   550,   390,   491,   827, 10720,
   10733,  9871, 10746, 10759,  1645, 10772,  2633,   535,   909,   340,
    9871,  4153,  4325,  4401,  4531,  4591,  4325,  4325,  4630,   195,
     243,    45,    71,   116,   125,  4751,   117,  2063,  2104,  2377,
    2418,  2691,  2732,   352,  2501,  1897,  2641,  3532,   177,  4820,
     309,   483,   764,   692,   745,  4059,  3845,  4096,  9888,  9916,
    9930,   855,  9943,  3004,  3054,  3122,  3224,  3383,  9791,    81,
    3424,  9888,  9076,  9082,  9100,  9117,  9134,  9082,  9082,  9151,
    1086,   290,   403,  9820,   126,   127,   128,   129,  9168,   117,
    3736,  4254,  4436,  4483,  4652,  4684,   361,  1584,  2212,  2526,
    1384,  9185,   121,    82,  1065,   298,   428,   569,  1871, 10304,
   10317,  9905, 10330, 10343,  1511, 10356,  4716,   411,  4373,  9905,
    9202,  9219,  9236,  9253,  9270,  9219,  9219,  9287, 11043,   399,
   10369,   416,  9304,  9321,  9338,  9355,  9372,  9389,  9406,  9423,
    2005, 10785,  2139, 10798,  9440,  1663, 10811,   451, 10824,  1806,
     838,  4235,  1000,  3806,   219,  2284,   880,   939,  1004, 11366,
     113,   242,   315,  4780,   226,  4842,  1713,  4877,  9457,  4912,
    2331, 11019,   440,   532,  4947,  1161, 10382,   447,  9474,  9491,
    9508,  9525,  9542,  9559,  9576,  9593,   643,  9957,  1273,  9970,
    9610,  1663,  4982,  9984,   475,  9997,  2864,   987,  4283,  1102,
    3959,   716,  2336,  1189,  1266,  1369, 11374,   422,   365,   382,
    5018,  5050,  5082,  5114,  5146,  5178,   356,  5210,  2027,  5242,
    9627,  5274,  2792, 11032,   477,   532,  5306, 10395,   472,  9644,
    9661,  9678,  9695,  9712,  9729,  9746,  9763,   778, 10408,  1691,
   10421,  9780,  1663,  5338, 10434,   501, 10447,  2941,  1035,  4293,
    1278,  4046,  1110,  2913,  1077,  1163,  1223, 11382,   521, 10837,
   10850, 10863,   323, 10876,  1139, 10889,  1323, 10902,  1352, 10915,
   10928, 10941,  1526, 10954,  2014, 10967, 10980, 10993,   266,   478,
     486,   493, 10460,   498,   502, 10473,   507, 10226,   541,  5373,
    5408,   542,  5443,   585, 10011, 10024, 10038,   788, 10051,  1822,
   10065,  1542, 10078,  1700, 10092, 10105, 10119,  1856, 10132,  1951,
   10146, 10159, 10173,   604,   557,   575,   578, 10486,   588,   594,
   10499,   597, 10239,   571,  5479,  5511,   603, 10512, 10525, 10538,
    2153, 10551,  1461, 10564,  1377, 10577,  1436, 10590, 10603, 10616,
    2064, 10629,  2105, 10642, 10655, 10668,   564,   616, 11006,   632,
     175,   634,   213,   232,  8852,  8884,   458,  5543,   952,  5578,
    5613, 10186,   637,   246,   653,   261,   265,  8916,  8948,   458,
    5649,  1820,  5681, 10681,  5713,  5748,  5783,  5818,  5853,  5888,
    5923,  5958,  8980,  5993,  8980,  6028,   196, 10252,   297,  6064,
    6096,  6128,  6160,  6192,  6224,  6256,  6288,  9044,  6320,  9044,
    6352,   378, 10265,   424,  6384,  8980,  6419,  8980,  1855,  8980,
    1855,  8980,  2279,  8980,  6455,  9044,  6487,  9044,  1855,  9044,
    1855,  9044,  2325,  9044,  6519,  6554,   668,  6589,   677,  6624,
   10694,   679,  6659,  6695,  6727,   690,  6759,   708,  6791, 10707,
     710,  6823,  8980,  8980,  8980,  8980,  9044,  9044,  9044,  9044,
    6855,  6890,  6925,  6960,  6996,  7028,  7060,  7092
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
    -419,  -419,  -419,   724,   471,  -419,  -419,  -419,  -419,  -419,
     555,  -419,   547,    63,  -283,  -418,  -419,   633,    74,   135,
     146,   206,  -419,   211,   305,     0,  -141,  3957,  4172,  3921,
    3706,  3204,  3455,  2891,  1256,  1570,  1884,  -419,  -393,  2198,
     942,     1,  2512,  -410
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   130,    23,   191,   226,   162,   210,
     185,   186,   187,   287,    75,   131,   132,   133,   134,   288,
     289,   290,   135,   291,   292,   293,   123,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   157,   158,    42,
      72,   136,    45,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    44,   529,   423,   113,   541,   534,    62,   218,   269,
      76,   219,    79,    64,   125,    -4,    71,    74,   127,    66,
      31,    44,    46,    47,    48,    49,    50,    51,    52,    53,
      68,    94,   205,   -20,   207,   184,   268,    63,   -20,    54,
     330,    55,    56,    65,    57,    58,   413,   193,   564,    67,
      59,   -20,   -20,   331,   332,    80,   475,   576,   569,    95,
      69,    96,   196,    24,   -20,   117,   -23,   120,   222,   122,
     166,   223,   415,   -82,    25,   194,   414,   229,   -87,   231,
      46,   234,   -15,    24,   -15,   -15,   -15,   -15,   382,   -15,
     197,   198,   156,   479,    25,    80,   -15,   -15,   -15,   597,
     -15,   -15,   416,   -15,   -15,   -15,   -15,   -15,   -15,   -82,
     442,   -82,   -15,   -85,   -82,   -15,   -15,   417,   -31,   199,
     -31,   -31,   -31,   -31,   382,   -31,   419,   465,   467,   469,
     471,   167,   -31,   -31,   -31,    26,   -31,   -31,  -145,   -31,
     -31,   -31,   -31,   -31,   -31,   -85,    27,   418,   -31,   -17,
     -87,   -31,   -31,   -87,   -17,    26,   420,   466,   468,   470,
     472,   383,   -88,   189,   169,  -140,    27,   -17,   -17,  -141,
    -140,   346,   346,   352,  -141,   352,   625,   319,  -137,   170,
     -17,   209,   267,   -88,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,   189,  -140,   172,  -140,  -138,  -141,   175,  -141,
      31,  -138,    31,   177,   626,   320,    28,  -137,  -137,  -137,
    -137,    29,   189,   178,   628,    31,   411,    31,   379,    31,
     379,    31,   379,    31,  -138,   658,    28,   530,   659,   383,
     -91,    29,   269,   630,   340,   340,    80,   182,    31,    31,
      31,    31,   629,  -140,  -139,   201,   203,   640,  -140,  -139,
     208,   -91,   381,   115,   -83,   248,   249,   250,   251,   183,
       6,   631,   643,    24,   412,    24,   645,     7,     8,     9,
     116,  -140,  -139,   190,   214,   641,   216,   382,    24,   538,
      24,   -21,    24,   252,    24,   422,    24,   236,   192,   227,
     644,   228,   195,   230,   646,   232,  -138,   235,   -83,   427,
     242,    24,    24,    24,    24,    30,   341,   341,   -92,   -92,
     481,   458,   243,   244,   245,   246,  -141,   342,   342,  -138,
     428,  -141,  -138,  -138,  -138,    30,   662,   -92,   224,   663,
     -92,   573,   -18,   383,   -89,    26,    18,    26,   474,    60,
    -139,   -82,   -82,   237,  -141,  -139,    27,  -138,    27,  -138,
      26,   478,    26,   330,    26,   -89,    26,   565,    26,   238,
      61,    27,   269,    27,   239,    27,   241,    27,  -139,    27,
    -139,  -140,  -137,    26,    26,    26,    26,   343,   343,   -29,
     -29,   424,   344,   344,    27,    27,    27,    27,  -141,   121,
     476,     2,     3,     4,   247,   156,     6,  -140,  -140,   385,
     -96,   -96,   -96,     7,     8,     9,    28,   668,    28,  -139,
     669,    29,   493,    29,  -141,  -141,   533,   -86,   536,    17,
     122,    28,   -96,    28,   459,    28,    29,    28,    29,    28,
      29,   -87,    29,   428,    29,  -139,  -139,   482,   -96,   -96,
     -96,   156,   159,   160,    28,    28,    28,    28,   510,    29,
      29,    29,    29,   672,   -85,   -85,   673,   -96,   270,   204,
     -96,   347,   348,   349,   350,   636,     6,   638,   568,   540,
     571,    22,   122,     7,     8,     9,   345,   345,   651,   545,
     653,   206,   321,   347,   348,   349,   350,   -86,     6,   351,
     -86,    22,   156,   429,   -88,     7,     8,     9,  -128,  -128,
    -100,  -100,  -100,  -100,   578,    30,   575,    30,   369,   -86,
     598,   351,   -86,  -130,   181,   -88,   -88,   676,   599,   678,
      30,   681,    30,  -100,    30,   600,    30,   685,    30,   687,
     602,   690,   479,   128,   603,     2,     3,     4,     5,   605,
       6,   366,   367,    30,    30,    30,    30,     7,     8,     9,
     -85,   279,   280,   -85,   281,   282,   283,   129,   284,   285,
     -92,   -92,   384,    17,  -137,  -137,   286,   -34,   -15,   -15,
     608,   -15,   -15,   -15,   -15,   479,   -15,   609,  -100,  -100,
    -100,  -100,   -92,   -15,   -15,   -15,   610,   -15,   -15,   611,
     -15,   -15,   -15,   -83,   -15,   -15,   -83,   161,  -100,   -15,
     621,  -100,   -15,   -92,   -92,    82,   352,   612,   352,   -37,
     613,   -37,   -37,   -37,   -37,   428,   -37,   346,   346,   352,
     615,   352,   -92,   -37,   -37,   -37,   616,   -37,   -37,   618,
     -37,   -37,   -37,   -37,   -37,   -37,   -83,   -83,   622,   -37,
      81,   -88,   -37,   -37,  -137,    81,   -91,   346,   623,   346,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,   379,   -88,
     379,   624,   379,   627,   -91,   346,   639,   346,   379,   346,
     379,   346,   379,   346,  -137,  -137,  -137,    90,   633,   635,
     340,   340,   642,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,   648,   650,   163,   164,   165,   346,   346,   346,   346,
     692,   431,   -96,   -96,   -96,  -132,   654,    92,   656,   693,
     340,   695,   340,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,   664,   696,   666,   -96,   -96,   429,   -91,   340,   674,
     340,   675,   340,   677,   340,   679,   340,   682,  -143,   683,
     697,   684,   699,   686,    78,   688,   213,   691,   -91,   -91,
     -27,   -27,   341,   341,  -100,  -100,  -100,  -100,   225,   340,
     340,   340,   340,   342,   342,   179,   700,   701,   702,   703,
     704,   705,   706,   707,   -92,   -92,   430,  -100,  -100,  -137,
     -24,   211,   341,     0,   341,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,   342,     0,   342,   -92,   -92,   429,   -89,
     341,     0,   341,     0,   341,     0,   341,  -137,   341,  -137,
    -137,   342,   330,   342,     0,   342,     0,   342,     0,   342,
     -89,   -89,     0,   343,   343,   331,   332,     0,   344,   344,
       0,   341,   341,   341,   341,   386,  -104,  -104,  -104,  -104,
     387,   388,   342,   342,   342,   342,     0,  -103,  -103,  -103,
    -103,   -26,   -26,   343,     0,   343,   439,     0,   344,  -104,
     344,     0,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -103,   343,     0,   343,     0,   343,   344,   343,   344,   343,
     344,     0,   344,     0,   344,   440,   441,  -132,  -132,   385,
     -99,   -99,   -99,     0,   321,   322,   323,   324,   325,   326,
     327,   328,   343,   343,   343,   343,     0,   344,   344,   344,
     344,   128,   -99,     2,     3,     4,     5,   329,     6,  -129,
    -129,     0,   345,   345,     0,     7,     8,     9,     0,   279,
     280,     0,   281,   282,   283,   129,   284,   285,  -137,  -137,
    -137,    17,    43,     0,   286,   -33,    81,   -89,  -110,  -110,
    -110,  -110,   345,   637,   345,   347,   348,   349,   350,   264,
       6,     0,    43,   -30,   -30,   -89,     0,     7,     8,     9,
     345,  -110,   345,     0,   345,     0,   345,     0,   345,  -127,
    -127,   -86,    89,   351,   -86,    93,    97,     0,    89,    89,
      89,    89,    89,    89,    89,    89,  -103,  -103,  -103,  -103,
      89,   345,   345,   345,   345,   114,     0,   264,     0,   264,
     -95,   -95,   384,  -109,  -109,  -109,  -109,   294,     0,  -103,
    -103,     0,    89,    89,    89,    89,    89,    89,    89,    89,
     -28,   -28,   -95,    89,   311,   -36,  -109,   -36,   -36,   -36,
     -36,     0,   -36,     0,  -103,  -103,  -103,  -103,     0,   -36,
     -36,   -36,     0,   -36,   -36,     0,   -36,   -36,   -36,   -36,
     -36,   -36,   -25,   -25,  -103,   -36,     0,  -103,   -36,   -36,
      83,   -96,   -96,   -96,   294,   480,   -88,   -38,   180,   -38,
     -38,   -38,   -38,     0,   -38,     0,   482,   -99,   -99,   -99,
     -96,   -38,   -38,   -38,   -88,   -38,   -38,   -88,   -38,   -38,
     -38,   -38,   -38,   -38,   188,     0,   -99,   -38,     0,   -99,
     -38,   -38,   -95,   -95,   430,   364,     0,   364,  -137,  -137,
     480,   -91,   -39,   311,   -39,   -39,   -39,   -39,     0,   -39,
       0,   212,     0,   188,   -95,   -95,   -39,   -39,   -39,   -91,
     -39,   -39,   -91,   -39,   -39,   -39,   -39,   -39,   -39,   -93,
     -93,   384,   -39,   188,     0,   -39,   -39,   -95,   -95,    82,
     264,     0,   264,   -69,   264,   -69,   -69,   -69,   -69,     0,
     -69,   -93,  -110,  -110,  -110,  -110,   -95,   -69,   -69,   -69,
       0,   -69,   -69,     0,   -69,   -69,   -69,   -69,   -69,   -69,
     542,   543,  -110,   -69,   264,  -110,   -69,   -69,   431,   -99,
     -99,   -99,     0,   392,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,   392,   392,   392,   392,   392,   392,   392,   392,
     392,   -99,   -99,   333,     0,     2,     3,     4,   247,  -144,
       6,     0,  -109,  -109,  -109,  -109,   425,     7,     8,     9,
       0,   264,     0,     0,   334,   335,   336,   200,   337,   338,
     438,     0,  -109,    17,     0,  -109,   339,     0,     0,  -100,
    -100,  -100,  -100,   438,   438,   438,   438,   438,   438,   438,
     438,   438,     0,   260,   439,  -110,  -110,  -110,  -110,  -100,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   -95,   -95,
     481,     0,     0,   264,    46,    47,    88,     0,  -110,  -110,
      52,    53,    98,   489,   441,  -132,  -132,   -95,     0,     0,
     -95,   489,   489,   489,   489,   489,   489,   489,   489,   489,
       0,   260,     0,   260,   392,   392,   392,   392,   392,   392,
     392,   392,   385,   -97,   -97,   -97,   392,   311,     0,  -123,
    -123,  -123,  -123,   152,  -123,     0,     0,     0,   307,     0,
       0,  -123,  -123,  -123,     0,   -97,   531,     0,   264,     0,
     264,  -101,  -101,  -101,  -101,   294,     0,  -123,     0,     0,
     438,   438,   438,   438,   438,   438,   438,   438,  -109,  -109,
    -109,  -109,   438,   311,  -101,  -137,   482,   -97,   -97,   -97,
       0,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,     0,
       0,  -109,  -109,     0,     0,     0,   -97,     0,   566,   -97,
     264,     0,   264,  -137,  -137,  -137,  -137,   294,     0,     0,
       0,   489,   489,   489,   489,   489,   489,   489,   489,   360,
       0,   360,     0,   489,   311,     0,   -35,   307,   -35,   -35,
     -35,   -35,     0,   -35,     0,  -101,  -101,  -101,  -101,     0,
     -35,   -35,   -35,     0,   -35,   -35,     0,   -35,   -35,   -35,
     -35,   -35,   -35,     0,     0,  -101,   -35,     0,  -101,   -35,
     -35,   -93,   -93,   481,   260,     0,   260,     0,   260,   -65,
     -65,     0,   -65,   -65,   -65,   -65,     0,   -65,     0,     0,
     -93,     0,     0,   -93,   -65,   -65,   -65,     0,   -65,   -65,
       0,   -65,   -65,   -65,   215,   -65,   -65,     0,   260,     0,
     -65,     0,   490,   -65,     0,     0,     0,   391,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,   396,   260,   260,   260,
     260,   260,   260,   260,   260,  -106,  -106,  -106,  -106,     0,
    -132,   491,   492,  -132,     0,     0,     0,     0,   364,     0,
     364,   431,   -97,   -97,   -97,   260,     0,     0,  -106,  -137,
       0,   364,     0,   364,   437,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,     0,   -97,   -97,     0,   443,   307,   307,
     307,   307,   307,   307,   307,   307,     0,   261,  -137,  -137,
    -137,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,     0,
     264,     0,   264,     0,   264,     0,     0,   260,     0,     0,
     264,     0,   264,  -143,   264,     0,  -143,   488,     0,     0,
       0,     0,     0,     0,     0,   494,   360,   360,   360,   360,
     360,   360,   360,   360,     0,   261,     0,   261,   260,   260,
     260,   260,   260,   260,   260,   526,   393,     0,     0,     0,
     260,   307,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
       0,     0,   308,     0,   155,     0,   295,   296,   297,   298,
       0,     6,   260,     0,   260,   394,   395,  -132,     7,     8,
       9,     0,     0,     0,   307,   307,   307,   307,   307,   307,
     307,   561,   490,     0,   299,  -131,   307,   307,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,   -93,   -93,    82,  -101,
    -101,  -101,  -101,     0,   532,     0,   248,   249,   250,   251,
    -132,     6,   492,  -132,   260,   -93,   260,     0,     7,     8,
       9,   116,  -101,  -101,     0,   360,   360,   360,   360,   360,
     360,   360,   594,   361,   252,   361,     0,   360,   307,   -62,
     -62,   308,   -62,   -62,   -62,   -62,     0,   -62,     0,  -103,
    -103,  -103,  -103,     0,   -62,   -62,   -62,     0,   -62,   -62,
       0,   -62,   -62,   -62,   217,   -62,   -62,     0,     0,  -103,
     -62,     0,   -70,   -62,   -70,   -70,   -70,   -70,   261,   -70,
     261,     0,   261,     0,     0,     0,   -70,   -70,   -70,     0,
     -70,   -70,     0,   -70,   -70,   -70,   -70,   -70,   -70,     0,
       0,     0,   -70,   270,   271,   -70,   -70,     0,     0,   276,
     277,   652,   261,   347,   348,   349,   350,     0,     6,     0,
       0,   261,   -93,   -93,   430,     7,     8,     9,     0,     0,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   -86,
       0,   351,   -86,     0,   -93,   -93,   378,     0,   248,   249,
     250,   251,   360,     6,   360,  -106,  -106,  -106,  -106,   261,
       7,     8,     9,     0,     0,   360,     0,   360,   308,   483,
    -104,  -104,  -104,  -104,   484,   485,   252,   -86,  -106,  -106,
       0,   308,   308,   308,   308,   308,   308,   308,   308,   308,
    -104,   262,     0,  -104,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,     0,     0,   260,     0,   260,     0,   260,     0,
       0,   261,     0,     0,   260,     0,   260,     0,   260,  -143,
    -143,   361,     0,     0,     0,     0,     0,     0,     0,   361,
     361,   361,   361,   361,   361,   361,   361,   361,     0,   262,
       0,   262,   261,   261,   261,   261,   261,   261,   261,   261,
    -105,  -105,  -105,  -105,   261,   308,   233,     0,   248,   249,
     250,   251,     0,     6,     0,     0,   309,     0,     0,     0,
       7,     8,     9,  -105,  -105,     0,   261,     0,   261,    83,
     -99,   -99,   -99,     0,     0,     0,   252,   -86,   308,   308,
     308,   308,   308,   308,   308,   308,  -137,     0,     0,   -99,
     308,   308,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
       0,     0,     0,  -105,  -105,  -105,  -105,     0,   567,     0,
     248,   249,   250,   251,     0,     6,  -137,  -137,   261,     0,
     261,     0,     7,     8,     9,   116,  -105,     0,     0,   361,
     361,   361,   361,   361,   361,   361,   361,   362,   252,   362,
       0,   361,   308,     0,   -41,   309,   -41,   -41,   -41,   -41,
       0,   -41,     0,  -106,  -106,  -106,  -106,     0,   -41,   -41,
     -41,     0,   -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,
     -41,     0,     0,  -106,   -41,     0,  -106,   -41,   -41,     0,
       0,     0,   262,     0,   262,   -45,   262,   -45,   -45,   -45,
     -45,     0,   -45,     0,  -105,  -105,  -105,  -105,     0,   -45,
     -45,   -45,     0,   -45,   -45,     0,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,  -105,   -45,   262,  -105,   -45,   -45,
     393,     0,     0,     0,     0,   262,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   480,   -89,     0,  -110,  -110,  -110,  -110,
     395,  -132,     0,    46,    47,    48,   361,     0,   361,    52,
      53,     0,   -89,   262,     0,   -89,  -110,     0,  -137,   361,
       0,   361,   309,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,     0,     0,     0,   309,   309,   309,   309,   309,
     309,   309,   309,   309,     0,   263,  -137,  -137,  -137,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,     0,   261,     0,
     261,     0,   261,     0,     0,   262,     0,     0,   261,     0,
     261,  -144,   261,     0,  -144,   362,     0,     0,     0,     0,
       0,     0,     0,   362,   362,   362,   362,   362,   362,   362,
     362,   362,     0,   263,     0,   263,   262,   262,   262,   262,
     262,   262,   262,   262,     0,     0,     0,     0,   262,   309,
     680,     0,   248,   249,   250,   251,     0,     6,     0,     0,
     310,   270,   271,   272,     7,     8,     9,   276,   277,     0,
     262,     0,   262,  -109,  -109,  -109,  -109,     0,     0,     0,
     252,   -86,   309,   309,   309,   309,   309,   309,   309,   309,
       0,     0,     0,  -109,   309,   309,   689,     0,   248,   249,
     250,   251,   537,     6,     2,     3,     4,   247,     0,     6,
       7,     8,     9,   321,   322,   323,     7,     8,     9,   327,
     328,     0,   262,     0,   262,     0,   252,   -86,     0,     0,
     -86,     0,    17,   362,   362,   362,   362,   362,   362,   362,
     362,   363,     0,   363,     0,   362,   309,     0,   -40,   310,
     -40,   -40,   -40,   -40,     0,   -40,     0,    83,   -97,   -97,
     -97,     0,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,
     -40,   -40,   -40,   -40,   -40,     0,     0,   -97,   -40,     0,
       0,   -40,   -40,     0,     0,     0,   263,     0,   263,   -42,
     263,   -42,   -42,   -42,   -42,     0,   -42,     0,  -101,  -101,
    -101,  -101,     0,   -42,   -42,   -42,     0,   -42,   -42,     0,
     -42,   -42,   -42,   -42,   -42,   -42,     0,     0,  -101,   -42,
     263,     0,   -42,   -42,    90,     0,     0,     0,     0,   263,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   263,   263,
     263,   263,   263,   263,   263,   263,   263,     0,  -106,  -106,
    -106,  -106,  -132,    91,    92,     0,     0,     0,     0,     0,
     362,     0,   362,     0,    46,    47,    48,   263,  -106,    51,
      52,    53,    90,   362,     0,   362,   310,   267,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,     0,     0,     0,   310,
     310,   310,   310,   310,   310,   310,   310,   310,     0,   265,
    -132,    91,    92,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,     0,   262,     0,   262,     0,   262,     0,     0,   263,
       0,     0,   262,     0,   262,  -142,   262,     0,  -142,   363,
       0,     0,     0,     0,     0,     0,     0,   363,   363,   363,
     363,   363,   363,   363,   363,   363,     0,   265,     0,   265,
     263,   263,   263,   263,   263,   263,   263,   263,     0,  -137,
       0,     0,   263,   310,     0,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,     0,   312,     0,    70,     0,     2,     3,
       4,   247,     0,     6,   263,     0,   263,  -137,  -137,  -137,
       7,     8,     9,     0,     0,     0,   310,   310,   310,   310,
     310,   310,   310,   310,  -137,     0,    17,     0,   310,   310,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,    73,     0,   248,   249,
     250,   251,  -137,     6,  -137,     0,   263,     0,   263,     0,
       7,     8,     9,  -144,  -144,     0,     0,   363,   363,   363,
     363,   363,   363,   363,   363,   365,   252,   365,     0,   363,
     310,     0,   -43,   312,   -43,   -43,   -43,   -43,     0,   -43,
       0,  -105,  -105,  -105,  -105,     0,   -43,   -43,   -43,     0,
     -43,   -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,     0,
       0,  -105,   -43,     0,     0,   -43,   -43,     0,     0,     0,
     265,     0,   265,   -44,   265,   -44,   -44,   -44,   -44,     0,
     -44,     0,     0,     0,     0,     0,     0,   -44,   -44,   -44,
       0,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,     0,   -44,   265,     0,   -44,   -44,     0,     0,
       0,     0,     0,   265,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,   265,   265,   265,   265,   265,   265,   265,   265,
     265,     0,     0,   572,     0,     2,     3,     4,   247,  -142,
       6,     0,     0,     0,   363,     0,   363,     7,     8,     9,
       0,   265,     0,     0,     0,     0,     0,   363,     0,   363,
     312,   -86,     0,    17,     0,    46,    47,    48,    49,    50,
      51,    52,    53,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   313,   176,   314,   315,     0,   316,    58,     0,
       0,     0,     0,   317,     0,     0,   263,     0,   263,     0,
     263,     0,     0,   265,     0,     0,   263,     0,   263,     0,
     263,   321,   322,   365,     0,     0,     0,   327,   328,     0,
       0,   365,   365,   365,   365,   365,   365,   365,   365,   365,
       0,     0,     0,     0,   265,   265,   265,   265,   265,   265,
     265,   265,     0,     0,     0,     0,   265,   312,   259,    99,
       0,     2,     3,     4,   266,     0,     6,     0,     0,     0,
     369,   370,   371,     7,     8,     9,   375,   376,   265,     0,
     265,     0,     0,     0,     0,     0,     0,     0,   100,    17,
     312,   312,   312,   312,   312,   312,   312,   312,   369,   370,
       0,     0,   312,   312,   375,   376,   259,   101,   259,     2,
       3,     4,   266,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,   146,     0,     0,     0,     0,
     265,     0,   265,   306,     0,     0,     0,    17,     0,     0,
       0,   365,   365,   365,   365,   365,   365,   365,   365,     0,
       0,     0,     0,   365,   312,   -60,     0,   -60,   -60,   -60,
     -60,     0,   -60,     0,     0,     0,     0,     0,     0,   -60,
     -60,   -60,     0,   -60,   -60,     0,   -60,   -60,   -60,   -60,
     -60,   -60,     0,     0,     0,   -60,     0,     0,   -60,   -60,
    -121,  -121,  -121,  -121,     0,  -121,     0,     0,     0,     0,
       0,     0,  -121,  -121,  -121,   -59,     0,   -59,   -59,   -59,
     -59,     0,   -59,     0,   359,     0,   359,     0,  -121,   -59,
     -59,   -59,   306,   -59,   -59,     0,   -59,   -59,   -59,   -59,
     -59,   -59,     0,     0,     0,   -59,     0,     0,   -59,   -59,
       0,   103,     0,     2,     3,     4,   266,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,   259,
       0,   259,     0,   259,     0,     0,     0,     0,   365,     0,
     365,    17,     0,   -61,     0,   -61,   -61,   -61,   -61,     0,
     -61,   365,     0,   365,     0,     0,     0,   -61,   -61,   -61,
       0,   -61,   -61,   259,   -61,   -61,   -61,   -61,   -61,   -61,
       0,     0,     0,   -61,     0,     0,   -61,   -61,     0,     0,
       0,     0,   398,   259,   259,   259,   259,   259,   259,   259,
     265,     0,   265,     0,   265,     0,     0,     0,     0,     0,
     265,     0,   265,     0,   265,     0,     0,     0,     0,     0,
     259,     0,   105,     0,     2,     3,     4,   266,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,     0,     0,   445,   306,   306,   306,   306,   306,   306,
     306,   257,    17,     0,     0,   -57,     0,   -57,   -57,   -57,
     -57,     0,   -57,     0,     0,     0,     0,     0,     0,   -57,
     -57,   -57,   259,   -57,   -57,     0,   -57,   -57,   -57,   -57,
     -57,   -57,   102,     0,     0,   -57,   109,   110,   -57,   -57,
       0,   496,   359,   359,   359,   359,   359,   359,   359,   257,
       0,   257,     0,   259,   259,   259,   259,   520,   259,   259,
       0,     0,     0,     0,     0,   259,   306,   144,     0,   148,
     150,     0,     0,     0,     0,     0,   304,   107,     0,     2,
       3,     4,   266,     0,     6,     0,     0,   259,     0,   259,
       0,     7,     8,     9,     0,     0,     0,     0,     0,   306,
     306,   306,   306,   555,   306,   306,     0,    17,     0,     0,
       0,   306,   306,   111,     0,     2,     3,     4,   266,   119,
       6,   248,   249,   250,   251,     0,     6,     7,     8,     9,
       0,     0,     0,     7,     8,     9,     0,     0,     0,   259,
       0,   259,     0,    17,     0,     0,     0,     0,     0,   252,
     359,   359,   359,   359,   588,   359,   359,   357,     0,   357,
       0,     0,   359,   306,   -58,   304,   -58,   -58,   -58,   -58,
       0,   -58,     0,     0,     0,     0,     0,     0,   -58,   -58,
     -58,     0,   -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,
     -58,     0,     0,     0,   -58,     0,     0,   -58,   -58,     0,
       0,     0,   257,     0,   257,   -11,   257,   -11,   -11,   -11,
     -11,     0,   -11,     0,     0,     0,     0,     0,     0,   -11,
     -11,   -11,     0,   -11,   -11,     0,   -11,   -11,   -11,   -11,
     -11,   -11,     0,     0,     0,   -11,   257,     0,   -11,   -11,
     270,   271,   272,   273,   274,   275,   276,   277,    46,    47,
      48,    49,   258,    51,    52,    53,   400,   257,   257,   257,
     407,   408,   257,   278,     0,   126,   137,     0,     2,     3,
       4,   266,     0,     6,     0,     0,     0,   359,     0,   359,
       7,     8,     9,   257,     0,     0,     0,     0,     0,     0,
     359,     0,   359,     0,     0,     0,    17,     0,     0,     0,
     258,     0,   258,     0,     0,     0,     0,   447,   304,   304,
     304,   454,   455,   304,     0,     0,     0,     0,     0,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,   305,     0,   259,
       0,   259,     0,   259,     0,   257,     0,     0,     0,   259,
       0,   259,     0,   259,  -142,  -142,     0,   369,   370,   371,
     372,   373,   374,   375,   376,   498,   357,   357,   357,   505,
     506,   357,     0,     0,     0,     0,   257,   257,   257,   518,
     377,   522,   524,     0,     0,     0,     0,     0,   257,   304,
       0,   139,     0,     2,     3,     4,   266,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
     257,     0,   257,     0,     0,     0,     0,     0,   358,     0,
     358,    17,   304,   304,   304,   553,   305,   557,   559,     0,
       0,     0,     0,     0,   304,   304,   141,     0,     2,     3,
       4,   266,   143,     6,     2,     3,     4,   266,     0,     6,
       7,     8,     9,     0,     0,     0,     7,     8,     9,     0,
       0,     0,   257,   258,   257,   258,    17,   258,     0,     0,
       0,     0,    17,   357,   357,   357,   586,     0,   590,   592,
       0,     0,     0,     0,     0,   357,   304,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,   258,     0,     0,
       0,     0,     0,     0,    54,     0,    55,    56,     0,    57,
      58,     0,     0,   256,     0,    59,     0,   258,   258,   258,
     258,   258,   258,   258,     0,     0,   -41,   -41,     0,   -41,
     -41,   -41,   -41,     0,   -41,     0,     0,     0,     0,     0,
       0,   -41,   -41,   -41,   258,   -41,   -41,   108,   -41,   -41,
     -41,   -41,   -41,   -41,     0,     0,     0,   -41,     0,     0,
     -41,   256,     0,   256,     0,     0,     0,     0,   305,   305,
     305,   305,   305,   305,   305,     0,     0,   145,   142,     2,
       3,     4,   266,     0,     6,     0,     0,     0,   303,     0,
       0,     7,     8,     9,     0,     0,   258,     0,     0,     0,
     357,     0,   357,   270,   271,   272,   273,    17,   275,   276,
     277,     0,     0,   357,     0,   357,   358,   358,   358,   358,
     358,   358,   358,     0,     0,     0,     0,   258,   258,   258,
     258,     0,   258,   258,     0,     0,     0,     0,     0,   258,
     305,     0,   435,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
       0,     0,   257,     0,   257,     0,   257,     0,     0,     0,
       0,   258,   257,   258,   257,     0,   257,  -111,  -111,   356,
       0,   356,     0,   305,   305,   305,   305,   303,   305,   305,
       0,     0,     0,     0,     0,   305,   305,   147,     0,     2,
       3,     4,   266,   149,     6,     2,     3,     4,   266,     0,
       6,     7,     8,     9,     0,     0,     0,     7,     8,     9,
       0,     0,     0,   258,   256,   258,   256,    17,   256,     0,
       0,     0,     0,    17,   358,   358,   358,   358,   255,   358,
     358,     0,     0,     0,     0,     0,   358,   305,   151,     0,
       2,     3,     4,   266,     0,     6,     0,     0,   256,     0,
       0,     0,     7,     8,     9,     0,   321,   322,   323,   324,
     104,   326,   327,   328,   253,     0,     0,     0,    17,   256,
     256,   406,     0,     0,   256,     0,   255,     0,   255,     0,
       0,     0,     0,   153,     0,     2,     3,     4,   266,     0,
       6,     0,   140,     0,     0,   256,     0,     7,     8,     9,
       0,     0,     0,   302,     0,   112,     0,     0,     0,     0,
       0,     0,   253,    17,   253,     0,     0,     0,     0,     0,
     303,   303,   453,     0,     0,   303,   368,     0,   295,   296,
     297,   298,     0,     6,     0,     0,     0,     0,   154,   300,
       7,     8,     9,   369,   370,   371,   372,   256,   374,   375,
     376,   358,     0,   358,     0,     0,   299,   432,  -104,  -104,
    -104,  -104,   433,   434,   358,     0,   358,     0,   356,   356,
     504,     0,     0,   356,     0,     0,     0,     0,   256,   256,
     516,  -104,  -104,     0,   355,     0,   355,     0,     0,     0,
     256,   303,   302,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,     0,     0,   258,     0,   258,     0,   258,     0,     0,
       0,     0,   256,   258,   256,   258,     0,   258,  -115,  -115,
     353,     0,   353,     0,   303,   303,   551,     0,   300,   255,
       0,   255,     0,   255,     0,     0,   303,   303,   380,     0,
     248,   249,   250,   251,   397,     6,   248,   249,   250,   390,
       0,     6,     7,     8,     9,     0,     0,     0,     7,     8,
       9,     0,     0,   255,   256,   253,   256,   253,   252,   253,
       0,     0,     0,     0,   252,   356,   356,   584,     0,   254,
       0,     0,     0,     0,   402,   255,     0,   356,   303,   255,
       0,     0,     0,   333,     0,     2,     3,     4,   247,   253,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
     255,     0,   106,     0,   334,   335,   336,   202,   337,   338,
       0,     0,     0,    17,     0,   410,   339,   254,     0,   254,
       0,     0,   270,   271,   272,   449,   302,   275,   276,   277,
     302,     0,   138,     0,   -45,   -45,   253,   -45,   -45,   -45,
     -45,     0,   -45,     0,   301,     0,     0,     0,     0,   -45,
     -45,   -45,   255,   -45,   -45,     0,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,     0,   -45,   457,     0,   -45,     0,
     321,   322,   323,   500,   355,   326,   327,   328,   355,     0,
     369,   370,   371,   255,   514,   374,   375,   376,   253,     0,
       0,     0,   356,     0,   356,   255,   302,    84,  -104,  -104,
    -104,  -104,    85,    86,     0,   356,   399,   356,   248,   249,
     250,   390,     0,     6,   508,     0,     0,   255,  -104,   255,
       7,     8,     9,     0,     0,   354,     0,   354,     0,   302,
     549,   528,   300,   301,     0,     0,   252,     0,     0,     0,
       0,   302,   302,     0,   256,     0,   256,     0,   256,     0,
       0,     0,     0,   253,   256,   253,   256,     0,   256,     0,
     321,   322,   323,   324,   325,   326,   327,   328,     0,   255,
     254,   255,   254,     0,   254,     0,     0,   563,   300,     0,
     355,   582,   401,   329,   248,   249,   250,   390,     0,     6,
       0,     0,   355,   302,     0,     0,     7,     8,     9,     0,
       0,     0,     0,     0,   254,   253,     0,   253,     0,     0,
       0,     0,   252,     0,     0,     0,   -40,   -40,     0,   -40,
     -40,   -40,   -40,     0,   -40,     0,   404,     0,   596,   300,
     254,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,   -40,
     -40,   -40,   -40,   -40,     0,     0,     0,   -40,     0,     0,
     -40,   254,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,   -42,   -42,     0,   -42,   -42,   -42,   -42,
       0,   -42,     0,     0,   124,    58,     0,   451,   -42,   -42,
     -42,   301,   -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,
     -42,     0,     0,     0,   -42,     0,     0,   -42,     0,     0,
       0,     0,     0,   254,     0,     0,     0,   355,     0,   355,
       0,     0,   403,     0,   248,   249,   250,   390,     0,     6,
     355,     0,   355,     0,     0,   502,     7,     8,     9,   354,
       0,     0,     0,     0,   512,     0,  -122,  -122,  -122,  -122,
       0,  -122,   252,   353,     0,   353,   254,   301,  -122,  -122,
    -122,     0,     0,     0,     0,     0,   353,     0,   353,   255,
       0,   255,     0,   255,  -122,     0,     0,     0,   254,   255,
     254,   255,   405,   255,   248,   249,   250,   390,     0,     6,
     547,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,     0,   301,   301,     0,   253,     0,   253,     0,   253,
       0,     0,   252,     0,     0,   253,     0,   253,     0,   253,
       0,   409,     0,   248,   249,   250,   390,     0,     6,     0,
     254,     0,   254,     0,     0,     7,     8,     9,     0,     0,
       0,   580,   -43,   -43,     0,   -43,   -43,   -43,   -43,     0,
     -43,   252,     0,   354,   301,     0,     0,   -43,   -43,   -43,
       0,   -43,   -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,
       0,     0,     0,   -43,   -44,   -44,   -43,   -44,   -44,   -44,
     -44,     0,   -44,     0,     0,     0,     0,     0,     0,   -44,
     -44,   -44,     0,   -44,   -44,     0,   -44,   -44,   -44,   -44,
     -44,   -44,     0,     0,     0,   -44,     0,   -10,   -44,   -10,
     -10,   -10,   -10,     0,   -10,     0,     0,     0,     0,     0,
       0,   -10,   -10,   -10,     0,   -10,   -10,     0,   -10,   -10,
     -10,   -10,   -10,   -10,     0,     0,     0,   -10,     0,     0,
     -10,   -10,   421,     0,     2,     3,     4,   247,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,   270,
     271,   272,   273,   274,   275,   276,   277,     0,   354,     0,
     354,   -55,    17,   -55,   -55,   -55,   -55,     0,   -55,     0,
       0,   354,   278,   354,   168,   -55,   -55,   -55,     0,   -55,
     -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   -55,     0,     0,   -55,   -55,     0,     0,     0,     0,
       0,   426,     0,   248,   249,   250,   251,     0,     6,     0,
     254,     0,   254,     0,   254,     7,     8,     9,     0,     0,
     254,     0,   254,   -54,   254,   -54,   -54,   -54,   -54,     0,
     -54,   252,     0,     0,     0,     0,     0,   -54,   -54,   -54,
       0,   -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,   -54,     0,     0,   -54,   -54,   -68,     0,
     -68,   -68,   -68,   -68,     0,   -68,     0,     0,     0,     0,
       0,     0,   -68,   -68,   -68,     0,   -68,   -68,     0,   -68,
     -68,   -68,   -68,   -68,   -68,     0,     0,     0,   -68,     0,
       0,   -68,   -68,   -78,     0,   -78,   -78,   -78,   -78,     0,
     -78,     0,     0,     0,     0,     0,     0,   -78,   -78,   -78,
       0,   -78,   -78,     0,   -78,   -78,   -78,   -78,   -78,   -78,
       0,     0,     0,   -78,     0,     0,   -78,   -78,   -56,     0,
     -56,   -56,   -56,   -56,     0,   -56,     0,     0,     0,     0,
       0,     0,   -56,   -56,   -56,     0,   -56,   -56,     0,   -56,
     -56,   -56,   -56,   -56,   -56,     0,     0,     0,   -56,     0,
       0,   -56,   -56,   -16,     0,   -16,   -16,   -16,   -16,     0,
     -16,     0,     0,     0,     0,     0,     0,   -16,   -16,   -16,
       0,   -16,   -16,     0,   -16,   -16,   -16,   -16,   -16,   -16,
       0,     0,     0,   -16,     0,     0,   -16,   -16,   -60,   -60,
       0,   -60,   -60,   -60,   -60,     0,   -60,     0,     0,     0,
       0,     0,     0,   -60,   -60,   -60,     0,   -60,   -60,     0,
     -60,   -60,   -60,   -60,   -60,   -60,     0,     0,     0,   -60,
     -59,   -59,   -60,   -59,   -59,   -59,   -59,     0,   -59,     0,
       0,     0,     0,     0,     0,   -59,   -59,   -59,     0,   -59,
     -59,     0,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,
       0,   -59,   -61,   -61,   -59,   -61,   -61,   -61,   -61,     0,
     -61,     0,     0,     0,     0,     0,     0,   -61,   -61,   -61,
       0,   -61,   -61,     0,   -61,   -61,   -61,   -61,   -61,   -61,
       0,     0,     0,   -61,   -57,   -57,   -61,   -57,   -57,   -57,
     -57,     0,   -57,     0,     0,     0,     0,     0,     0,   -57,
     -57,   -57,     0,   -57,   -57,     0,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,   -57,   -58,   -58,   -57,   -58,
     -58,   -58,   -58,     0,   -58,     0,     0,     0,     0,     0,
       0,   -58,   -58,   -58,     0,   -58,   -58,     0,   -58,   -58,
     -58,   -58,   -58,   -58,     0,     0,     0,   -58,   -55,   -55,
     -58,   -55,   -55,   -55,   -55,     0,   -55,     0,     0,     0,
       0,     0,     0,   -55,   -55,   -55,     0,   -55,   -55,     0,
     -55,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,   -55,
     -54,   -54,   -55,   -54,   -54,   -54,   -54,     0,   -54,     0,
       0,     0,     0,     0,     0,   -54,   -54,   -54,     0,   -54,
     -54,     0,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
       0,   -54,   -68,   -68,   -54,   -68,   -68,   -68,   -68,     0,
     -68,     0,     0,     0,     0,     0,     0,   -68,   -68,   -68,
       0,   -68,   -68,     0,   -68,   -68,   -68,   -68,   -68,   -68,
       0,     0,     0,   -68,   -78,   -78,   -68,   -78,   -78,   -78,
     -78,     0,   -78,     0,     0,     0,     0,     0,     0,   -78,
     -78,   -78,     0,   -78,   -78,     0,   -78,   -78,   -78,   -78,
     -78,   -78,     0,     0,     0,   -78,   -56,   -56,   -78,   -56,
     -56,   -56,   -56,     0,   -56,     0,     0,     0,     0,     0,
       0,   -56,   -56,   -56,     0,   -56,   -56,     0,   -56,   -56,
     -56,   -56,   -56,   -56,     0,     0,     0,   -56,     0,   -12,
     -56,   -12,   -12,   -12,   -12,     0,   -12,     0,     0,     0,
       0,     0,     0,   -12,   -12,   -12,     0,   -12,   -12,     0,
     -12,   -12,   -12,   -12,   -12,   -12,     0,     0,     0,   -12,
       0,     0,   -12,   -12,   -72,     0,   -72,   -72,   -72,   -72,
       0,   -72,     0,     0,     0,     0,     0,     0,   -72,   -72,
     -72,     0,   -72,   -72,     0,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,     0,   -72,     0,     0,   -72,   -72,   -71,
       0,   -71,   -71,   -71,   -71,     0,   -71,     0,     0,     0,
       0,     0,     0,   -71,   -71,   -71,     0,   -71,   -71,     0,
     -71,   -71,   -71,   -71,   -71,   -71,     0,     0,     0,   -71,
       0,     0,   -71,   -71,   -14,     0,   -14,   -14,   -14,   -14,
       0,   -14,     0,     0,     0,     0,     0,     0,   -14,   -14,
     -14,     0,   -14,   -14,     0,   -14,   -14,   -14,   -14,   -14,
     -14,     0,     0,     0,   -14,     0,     0,   -14,   -14,   -72,
     -72,     0,   -72,   -72,   -72,   -72,     0,   -72,     0,     0,
       0,     0,     0,     0,   -72,   -72,   -72,     0,   -72,   -72,
       0,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,
     -72,   -71,   -71,   -72,   -71,   -71,   -71,   -71,     0,   -71,
       0,     0,     0,     0,     0,     0,   -71,   -71,   -71,     0,
     -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,   -71,     0,
       0,     0,   -71,     0,   -77,   -71,   -77,   -77,   -77,   -77,
       0,   -77,     0,     0,     0,     0,     0,     0,   -77,   -77,
     -77,     0,   -77,   -77,     0,   -77,   -77,   -77,   -77,   -77,
     -77,     0,     0,     0,   -77,     0,     0,   -77,   -77,   -32,
       0,   -32,   -32,   -32,   -32,     0,   -32,     0,     0,     0,
       0,     0,     0,   -32,   -32,   -32,     0,   -32,   -32,     0,
     -32,   -32,   -32,   -32,   -32,   -32,     0,     0,     0,   -32,
       0,     0,   -32,   -32,   -13,     0,   -13,   -13,   -13,   -13,
       0,   -13,     0,     0,     0,     0,     0,     0,   -13,   -13,
     -13,     0,   -13,   -13,     0,   -13,   -13,   -13,   -13,   -13,
     -13,     0,     0,     0,   -13,     0,     0,   -13,   -13,   -77,
     -77,     0,   -77,   -77,   -77,   -77,     0,   -77,     0,     0,
       0,     0,     0,     0,   -77,   -77,   -77,     0,   -77,   -77,
       0,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,     0,
     -77,   -32,   -32,   -77,   -32,   -32,   -32,   -32,     0,   -32,
       0,     0,     0,     0,     0,     0,   -32,   -32,   -32,     0,
     -32,   -32,     0,   -32,   -32,   -32,   -32,   -32,   -32,     0,
       0,     0,   -32,     0,   -50,   -32,   -50,   -50,   -50,   -50,
       0,   -50,     0,     0,     0,     0,     0,     0,   -50,   -50,
     -50,     0,   -50,   -50,     0,   -50,   -50,   -50,   -50,   -50,
     -50,     0,     0,     0,   -50,     0,     0,   -50,   -50,   -51,
       0,   -51,   -51,   -51,   -51,     0,   -51,     0,     0,     0,
       0,     0,     0,   -51,   -51,   -51,     0,   -51,   -51,     0,
     -51,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,   -51,
       0,     0,   -51,   -51,   -46,     0,   -46,   -46,   -46,   -46,
       0,   -46,     0,     0,     0,     0,     0,     0,   -46,   -46,
     -46,     0,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,
     -46,     0,     0,     0,   -46,     0,     0,   -46,   -46,   -49,
       0,   -49,   -49,   -49,   -49,     0,   -49,     0,     0,     0,
       0,     0,     0,   -49,   -49,   -49,     0,   -49,   -49,     0,
     -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,   -49,
       0,     0,   -49,   -49,   -52,     0,   -52,   -52,   -52,   -52,
       0,   -52,     0,     0,     0,     0,     0,     0,   -52,   -52,
     -52,     0,   -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,
     -52,     0,     0,     0,   -52,     0,     0,   -52,   -52,   -47,
       0,   -47,   -47,   -47,   -47,     0,   -47,     0,     0,     0,
       0,     0,     0,   -47,   -47,   -47,     0,   -47,   -47,     0,
     -47,   -47,   -47,   -47,   -47,   -47,     0,     0,     0,   -47,
       0,     0,   -47,   -47,   -53,     0,   -53,   -53,   -53,   -53,
       0,   -53,     0,     0,     0,     0,     0,     0,   -53,   -53,
     -53,     0,   -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,
     -53,     0,     0,     0,   -53,     0,     0,   -53,   -53,   -48,
       0,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,     0,
       0,     0,     0,   -48,   -48,   -48,     0,   -48,   -48,     0,
     -48,   -48,   -48,   -48,   -48,   -48,     0,     0,     0,   -48,
       0,     0,   -48,   -48,   -65,     0,   -65,   -65,   -65,   -65,
       0,   -65,     0,     0,     0,     0,     0,     0,   -65,   -65,
     -65,     0,   -65,   -65,     0,   -65,   -65,   -65,   655,   -65,
     -65,     0,     0,     0,   -65,     0,     0,   -65,   -65,   -62,
       0,   -62,   -62,   -62,   -62,     0,   -62,     0,     0,     0,
       0,     0,     0,   -62,   -62,   -62,     0,   -62,   -62,     0,
     -62,   -62,   -62,   657,   -62,   -62,     0,     0,     0,   -62,
       0,     0,   -62,   -62,   -50,   -50,     0,   -50,   -50,   -50,
     -50,     0,   -50,     0,     0,     0,     0,     0,     0,   -50,
     -50,   -50,     0,   -50,   -50,     0,   -50,   -50,   -50,   -50,
     -50,   -50,     0,     0,     0,   -50,   -51,   -51,   -50,   -51,
     -51,   -51,   -51,     0,   -51,     0,     0,     0,     0,     0,
       0,   -51,   -51,   -51,     0,   -51,   -51,     0,   -51,   -51,
     -51,   -51,   -51,   -51,     0,     0,     0,   -51,   -46,   -46,
     -51,   -46,   -46,   -46,   -46,     0,   -46,     0,     0,     0,
       0,     0,     0,   -46,   -46,   -46,     0,   -46,   -46,     0,
     -46,   -46,   -46,   -46,   -46,   -46,     0,     0,     0,   -46,
     -49,   -49,   -46,   -49,   -49,   -49,   -49,     0,   -49,     0,
       0,     0,     0,     0,     0,   -49,   -49,   -49,     0,   -49,
     -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,
       0,   -49,   -52,   -52,   -49,   -52,   -52,   -52,   -52,     0,
     -52,     0,     0,     0,     0,     0,     0,   -52,   -52,   -52,
       0,   -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,
       0,     0,     0,   -52,   -47,   -47,   -52,   -47,   -47,   -47,
     -47,     0,   -47,     0,     0,     0,     0,     0,     0,   -47,
     -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,   -47,
     -47,   -47,     0,     0,     0,   -47,   -53,   -53,   -47,   -53,
     -53,   -53,   -53,     0,   -53,     0,     0,     0,     0,     0,
       0,   -53,   -53,   -53,     0,   -53,   -53,     0,   -53,   -53,
     -53,   -53,   -53,   -53,     0,     0,     0,   -53,   -48,   -48,
     -53,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,     0,
       0,     0,     0,   -48,   -48,   -48,     0,   -48,   -48,     0,
     -48,   -48,   -48,   -48,   -48,   -48,     0,     0,     0,   -48,
     -65,   -65,   -48,   -65,   -65,   -65,   -65,     0,   -65,     0,
       0,     0,     0,     0,     0,   -65,   -65,   -65,     0,   -65,
     -65,     0,   -65,   -65,   -65,   665,   -65,   -65,     0,     0,
       0,   -65,   -62,   -62,   -65,   -62,   -62,   -62,   -62,     0,
     -62,     0,     0,     0,     0,     0,     0,   -62,   -62,   -62,
       0,   -62,   -62,     0,   -62,   -62,   -62,   667,   -62,   -62,
       0,     0,     0,   -62,     0,   -67,   -62,   -67,   -67,   -67,
     -67,     0,   -67,     0,     0,     0,     0,     0,     0,   -67,
     -67,   -67,     0,   -67,   -67,     0,   -67,   -67,   -67,   -67,
     -67,   -67,     0,     0,     0,   -67,     0,     0,   -67,   -67,
     -64,     0,   -64,   -64,   -64,   -64,     0,   -64,     0,     0,
       0,     0,     0,     0,   -64,   -64,   -64,     0,   -64,   -64,
       0,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,
     -64,     0,     0,   -64,   -64,   -67,   -67,     0,   -67,   -67,
     -67,   -67,     0,   -67,     0,     0,     0,     0,     0,     0,
     -67,   -67,   -67,     0,   -67,   -67,     0,   -67,   -67,   -67,
     -67,   -67,   -67,     0,     0,     0,   -67,   -64,   -64,   -67,
     -64,   -64,   -64,   -64,     0,   -64,     0,     0,     0,     0,
       0,     0,   -64,   -64,   -64,     0,   -64,   -64,     0,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,     0,   -64,     0,
     -66,   -64,   -66,   -66,   -66,   -66,     0,   -66,     0,     0,
       0,     0,     0,     0,   -66,   -66,   -66,     0,   -66,   -66,
       0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,
     -66,     0,     0,   -66,   -66,   -63,     0,   -63,   -63,   -63,
     -63,     0,   -63,     0,     0,     0,     0,     0,     0,   -63,
     -63,   -63,     0,   -63,   -63,     0,   -63,   -63,   -63,   -63,
     -63,   -63,     0,     0,     0,   -63,     0,     0,   -63,   -63,
     -80,     0,   -80,   -80,   -80,   -80,     0,   -80,     0,     0,
       0,     0,     0,     0,   -80,   -80,   -80,     0,   -80,   -80,
       0,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,
     -80,     0,     0,   -80,   -80,   -81,     0,   -81,   -81,   -81,
     -81,     0,   -81,     0,     0,     0,     0,     0,     0,   -81,
     -81,   -81,     0,   -81,   -81,     0,   -81,   -81,   -81,   -81,
     -81,   -81,     0,     0,     0,   -81,     0,     0,   -81,   -81,
     -79,     0,   -79,   -79,   -79,   -79,     0,   -79,     0,     0,
       0,     0,     0,     0,   -79,   -79,   -79,     0,   -79,   -79,
       0,   -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,
     -79,     0,     0,   -79,   -79,   -66,   -66,     0,   -66,   -66,
     -66,   -66,     0,   -66,     0,     0,     0,     0,     0,     0,
     -66,   -66,   -66,     0,   -66,   -66,     0,   -66,   -66,   -66,
     -66,   -66,   -66,     0,     0,     0,   -66,   -63,   -63,   -66,
     -63,   -63,   -63,   -63,     0,   -63,     0,     0,     0,     0,
       0,     0,   -63,   -63,   -63,     0,   -63,   -63,     0,   -63,
     -63,   -63,   -63,   -63,   -63,     0,     0,     0,   -63,   -80,
     -80,   -63,   -80,   -80,   -80,   -80,     0,   -80,     0,     0,
       0,     0,     0,     0,   -80,   -80,   -80,     0,   -80,   -80,
       0,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,
     -80,   -81,   -81,   -80,   -81,   -81,   -81,   -81,     0,   -81,
       0,     0,     0,     0,     0,     0,   -81,   -81,   -81,     0,
     -81,   -81,     0,   -81,   -81,   -81,   -81,   -81,   -81,     0,
       0,     0,   -81,   -79,   -79,   -81,   -79,   -79,   -79,   -79,
       0,   -79,     0,     0,     0,     0,     0,     0,   -79,   -79,
     -79,     0,   -79,   -79,     0,   -79,   -79,   -79,   -79,   -79,
     -79,     0,     0,     0,   -79,     0,   -74,   -79,   -74,   -74,
     -74,   -74,     0,   -74,     0,     0,     0,     0,     0,     0,
     -74,   -74,   -74,     0,   -74,   -74,     0,   -74,   -74,   -74,
     -74,   -74,   -74,     0,     0,     0,   -74,     0,     0,   -74,
     -74,   -75,     0,   -75,   -75,   -75,   -75,     0,   -75,     0,
       0,     0,     0,     0,     0,   -75,   -75,   -75,     0,   -75,
     -75,     0,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,
       0,   -75,     0,     0,   -75,   -75,   -76,     0,   -76,   -76,
     -76,   -76,     0,   -76,     0,     0,     0,     0,     0,     0,
     -76,   -76,   -76,     0,   -76,   -76,     0,   -76,   -76,   -76,
     -76,   -76,   -76,     0,     0,     0,   -76,     0,     0,   -76,
     -76,   -73,     0,   -73,   -73,   -73,   -73,     0,   -73,     0,
       0,     0,     0,     0,     0,   -73,   -73,   -73,     0,   -73,
     -73,     0,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
       0,   -73,     0,     0,   -73,   -73,   -74,   -74,     0,   -74,
     -74,   -74,   -74,     0,   -74,     0,     0,     0,     0,     0,
       0,   -74,   -74,   -74,     0,   -74,   -74,     0,   -74,   -74,
     -74,   -74,   -74,   -74,     0,     0,     0,   -74,   -75,   -75,
     -74,   -75,   -75,   -75,   -75,     0,   -75,     0,     0,     0,
       0,     0,     0,   -75,   -75,   -75,     0,   -75,   -75,     0,
     -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,   -75,
     -76,   -76,   -75,   -76,   -76,   -76,   -76,     0,   -76,     0,
       0,     0,     0,     0,     0,   -76,   -76,   -76,     0,   -76,
     -76,     0,   -76,   -76,   -76,   -76,   -76,   -76,     0,     0,
       0,   -76,   -73,   -73,   -76,   -73,   -73,   -73,   -73,     0,
     -73,     0,     0,     0,     0,     0,     0,   -73,   -73,   -73,
       0,   -73,   -73,     0,   -73,   -73,   -73,   -73,   -73,   -73,
       0,     0,     0,   -73,    -3,     1,   -73,     2,     3,     4,
       5,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,    10,    11,     0,    12,    13,    14,     0,
      15,    16,     0,     0,     0,    17,    -2,    77,    18,     2,
       3,     4,     5,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,    10,    11,     0,    12,    13,
      14,     0,    15,    16,     0,     0,     0,    17,    -6,    -6,
      18,    -6,    -6,    -6,    -6,     0,    -6,     0,     0,     0,
       0,     0,     0,    -6,    -6,    -6,     0,    -6,    -6,     0,
      -6,    -6,    -6,     0,    -6,    -6,     0,     0,     0,    -6,
      -8,    -8,    -6,    -8,    -8,    -8,    -8,     0,    -8,     0,
       0,     0,     0,     0,     0,    -8,    -8,    -8,     0,    -8,
      -8,     0,    -8,    -8,    -8,     0,    -8,    -8,     0,     0,
       0,    -8,    -7,    -7,    -8,    -7,    -7,    -7,    -7,     0,
      -7,     0,     0,     0,     0,     0,     0,    -7,    -7,    -7,
       0,    -7,    -7,     0,    -7,    -7,    -7,     0,    -7,    -7,
       0,     0,     0,    -7,   -41,   -41,    -7,   -41,   -41,   -41,
     -41,     0,   -41,     0,     0,     0,     0,     0,     0,   -41,
     -41,   -41,     0,   -41,   -41,     0,   -41,   -41,   -41,     0,
     -41,   -41,     0,     0,     0,   -41,    -9,    -9,   -41,    -9,
      -9,    -9,    -9,     0,    -9,     0,     0,     0,     0,     0,
       0,    -9,    -9,    -9,     0,    -9,    -9,     0,    -9,    -9,
      -9,     0,    -9,    -9,     0,     0,     0,    -9,   -45,   -45,
      -9,   -45,   -45,   -45,   -45,     0,   -45,     0,     0,     0,
       0,     0,     0,   -45,   -45,   -45,     0,   -45,   -45,     0,
     -45,   -45,   -45,     0,   -45,   -45,     0,     0,     0,   -45,
     -40,   -40,   -45,   -40,   -40,   -40,   -40,     0,   -40,     0,
       0,     0,     0,     0,     0,   -40,   -40,   -40,     0,   -40,
     -40,     0,   -40,   -40,   -40,     0,   -40,   -40,     0,     0,
       0,   -40,   -42,   -42,   -40,   -42,   -42,   -42,   -42,     0,
     -42,     0,     0,     0,     0,     0,     0,   -42,   -42,   -42,
       0,   -42,   -42,     0,   -42,   -42,   -42,     0,   -42,   -42,
       0,     0,     0,   -42,   -43,   -43,   -42,   -43,   -43,   -43,
     -43,     0,   -43,     0,     0,     0,     0,     0,     0,   -43,
     -43,   -43,     0,   -43,   -43,     0,   -43,   -43,   -43,     0,
     -43,   -43,     0,     0,     0,   -43,   -44,   -44,   -43,   -44,
     -44,   -44,   -44,     0,   -44,     0,     0,     0,     0,     0,
       0,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,
     -44,     0,   -44,   -44,     0,     0,     0,   -44,   -60,   -60,
     -44,   -60,   -60,   -60,   -60,     0,   -60,     0,     0,     0,
       0,     0,     0,   -60,   -60,   -60,     0,   -60,   -60,     0,
     -60,   -60,   -60,     0,   -60,   -60,     0,     0,     0,   -60,
     -59,   -59,   -60,   -59,   -59,   -59,   -59,     0,   -59,     0,
       0,     0,     0,     0,     0,   -59,   -59,   -59,     0,   -59,
     -59,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,     0,
       0,   -59,   -61,   -61,   -59,   -61,   -61,   -61,   -61,     0,
     -61,     0,     0,     0,     0,     0,     0,   -61,   -61,   -61,
       0,   -61,   -61,     0,   -61,   -61,   -61,     0,   -61,   -61,
       0,     0,     0,   -61,   -57,   -57,   -61,   -57,   -57,   -57,
     -57,     0,   -57,     0,     0,     0,     0,     0,     0,   -57,
     -57,   -57,     0,   -57,   -57,     0,   -57,   -57,   -57,     0,
     -57,   -57,     0,     0,     0,   -57,   -58,   -58,   -57,   -58,
     -58,   -58,   -58,     0,   -58,     0,     0,     0,     0,     0,
       0,   -58,   -58,   -58,     0,   -58,   -58,     0,   -58,   -58,
     -58,     0,   -58,   -58,     0,     0,     0,   -58,   -55,   -55,
     -58,   -55,   -55,   -55,   -55,     0,   -55,     0,     0,     0,
       0,     0,     0,   -55,   -55,   -55,     0,   -55,   -55,     0,
     -55,   -55,   -55,     0,   -55,   -55,     0,     0,     0,   -55,
     -54,   -54,   -55,   -54,   -54,   -54,   -54,     0,   -54,     0,
       0,     0,     0,     0,     0,   -54,   -54,   -54,     0,   -54,
     -54,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,     0,
       0,   -54,   -68,   -68,   -54,   -68,   -68,   -68,   -68,     0,
     -68,     0,     0,     0,     0,     0,     0,   -68,   -68,   -68,
       0,   -68,   -68,     0,   -68,   -68,   -68,     0,   -68,   -68,
       0,     0,     0,   -68,   -78,   -78,   -68,   -78,   -78,   -78,
     -78,     0,   -78,     0,     0,     0,     0,     0,     0,   -78,
     -78,   -78,     0,   -78,   -78,     0,   -78,   -78,   -78,     0,
     -78,   -78,     0,     0,     0,   -78,    -5,    -5,   -78,    -5,
      -5,    -5,    -5,     0,    -5,     0,     0,     0,     0,     0,
       0,    -5,    -5,    -5,     0,    -5,    -5,     0,    -5,    -5,
      -5,     0,    -5,    -5,     0,     0,     0,    -5,   -56,   -56,
      -5,   -56,   -56,   -56,   -56,     0,   -56,     0,     0,     0,
       0,     0,     0,   -56,   -56,   -56,     0,   -56,   -56,     0,
     -56,   -56,   -56,     0,   -56,   -56,     0,     0,     0,   -56,
     -11,   -11,   -56,   -11,   -11,   -11,   -11,     0,   -11,     0,
       0,     0,     0,     0,     0,   -11,   -11,   -11,     0,   -11,
     -11,     0,   -11,   -11,   -11,     0,   -11,   -11,     0,     0,
       0,   -11,   -72,   -72,   -11,   -72,   -72,   -72,   -72,     0,
     -72,     0,     0,     0,     0,     0,     0,   -72,   -72,   -72,
       0,   -72,   -72,     0,   -72,   -72,   -72,     0,   -72,   -72,
       0,     0,     0,   -72,   -71,   -71,   -72,   -71,   -71,   -71,
     -71,     0,   -71,     0,     0,     0,     0,     0,     0,   -71,
     -71,   -71,     0,   -71,   -71,     0,   -71,   -71,   -71,     0,
     -71,   -71,     0,     0,     0,   -71,   -14,   -14,   -71,   -14,
     -14,   -14,   -14,     0,   -14,     0,     0,     0,     0,     0,
       0,   -14,   -14,   -14,     0,   -14,   -14,     0,   -14,   -14,
     -14,     0,   -14,   -14,     0,     0,     0,   -14,   -16,   -16,
     -14,   -16,   -16,   -16,   -16,     0,   -16,     0,     0,     0,
       0,     0,     0,   -16,   -16,   -16,     0,   -16,   -16,     0,
     -16,   -16,   -16,     0,   -16,   -16,     0,     0,     0,   -16,
     -10,   -10,   -16,   -10,   -10,   -10,   -10,     0,   -10,     0,
       0,     0,     0,     0,     0,   -10,   -10,   -10,     0,   -10,
     -10,     0,   -10,   -10,   -10,     0,   -10,   -10,     0,     0,
       0,   -10,   -77,   -77,   -10,   -77,   -77,   -77,   -77,     0,
     -77,     0,     0,     0,     0,     0,     0,   -77,   -77,   -77,
       0,   -77,   -77,     0,   -77,   -77,   -77,     0,   -77,   -77,
       0,     0,     0,   -77,   -32,   -32,   -77,   -32,   -32,   -32,
     -32,     0,   -32,     0,     0,     0,     0,     0,     0,   -32,
     -32,   -32,     0,   -32,   -32,     0,   -32,   -32,   -32,     0,
     -32,   -32,     0,     0,     0,   -32,   -13,   -13,   -32,   -13,
     -13,   -13,   -13,     0,   -13,     0,     0,     0,     0,     0,
       0,   -13,   -13,   -13,     0,   -13,   -13,     0,   -13,   -13,
     -13,     0,   -13,   -13,     0,     0,     0,   -13,   -12,   -12,
     -13,   -12,   -12,   -12,   -12,     0,   -12,     0,     0,     0,
       0,     0,     0,   -12,   -12,   -12,     0,   -12,   -12,     0,
     -12,   -12,   -12,     0,   -12,   -12,     0,     0,     0,   -12,
     -50,   -50,   -12,   -50,   -50,   -50,   -50,     0,   -50,     0,
       0,     0,     0,     0,     0,   -50,   -50,   -50,     0,   -50,
     -50,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,     0,
       0,   -50,   -51,   -51,   -50,   -51,   -51,   -51,   -51,     0,
     -51,     0,     0,     0,     0,     0,     0,   -51,   -51,   -51,
       0,   -51,   -51,     0,   -51,   -51,   -51,     0,   -51,   -51,
       0,     0,     0,   -51,   -46,   -46,   -51,   -46,   -46,   -46,
     -46,     0,   -46,     0,     0,     0,     0,     0,     0,   -46,
     -46,   -46,     0,   -46,   -46,     0,   -46,   -46,   -46,     0,
     -46,   -46,     0,     0,     0,   -46,   -49,   -49,   -46,   -49,
     -49,   -49,   -49,     0,   -49,     0,     0,     0,     0,     0,
       0,   -49,   -49,   -49,     0,   -49,   -49,     0,   -49,   -49,
     -49,     0,   -49,   -49,     0,     0,     0,   -49,   -52,   -52,
     -49,   -52,   -52,   -52,   -52,     0,   -52,     0,     0,     0,
       0,     0,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,
     -52,   -52,   -52,     0,   -52,   -52,     0,     0,     0,   -52,
     -47,   -47,   -52,   -47,   -47,   -47,   -47,     0,   -47,     0,
       0,     0,     0,     0,     0,   -47,   -47,   -47,     0,   -47,
     -47,     0,   -47,   -47,   -47,     0,   -47,   -47,     0,     0,
       0,   -47,   -53,   -53,   -47,   -53,   -53,   -53,   -53,     0,
     -53,     0,     0,     0,     0,     0,     0,   -53,   -53,   -53,
       0,   -53,   -53,     0,   -53,   -53,   -53,     0,   -53,   -53,
       0,     0,     0,   -53,   -48,   -48,   -53,   -48,   -48,   -48,
     -48,     0,   -48,     0,     0,     0,     0,     0,     0,   -48,
     -48,   -48,     0,   -48,   -48,     0,   -48,   -48,   -48,     0,
     -48,   -48,     0,     0,     0,   -48,   -67,   -67,   -48,   -67,
     -67,   -67,   -67,     0,   -67,     0,     0,     0,     0,     0,
       0,   -67,   -67,   -67,     0,   -67,   -67,     0,   -67,   -67,
     -67,     0,   -67,   -67,     0,     0,     0,   -67,   -64,   -64,
     -67,   -64,   -64,   -64,   -64,     0,   -64,     0,     0,     0,
       0,     0,     0,   -64,   -64,   -64,     0,   -64,   -64,     0,
     -64,   -64,   -64,     0,   -64,   -64,     0,     0,     0,   -64,
     -66,   -66,   -64,   -66,   -66,   -66,   -66,     0,   -66,     0,
       0,     0,     0,     0,     0,   -66,   -66,   -66,     0,   -66,
     -66,     0,   -66,   -66,   -66,     0,   -66,   -66,     0,     0,
       0,   -66,   -63,   -63,   -66,   -63,   -63,   -63,   -63,     0,
     -63,     0,     0,     0,     0,     0,     0,   -63,   -63,   -63,
       0,   -63,   -63,     0,   -63,   -63,   -63,     0,   -63,   -63,
       0,     0,     0,   -63,   -80,   -80,   -63,   -80,   -80,   -80,
     -80,     0,   -80,     0,     0,     0,     0,     0,     0,   -80,
     -80,   -80,     0,   -80,   -80,     0,   -80,   -80,   -80,     0,
     -80,   -80,     0,     0,     0,   -80,   -81,   -81,   -80,   -81,
     -81,   -81,   -81,     0,   -81,     0,     0,     0,     0,     0,
       0,   -81,   -81,   -81,     0,   -81,   -81,     0,   -81,   -81,
     -81,     0,   -81,   -81,     0,     0,     0,   -81,   -79,   -79,
     -81,   -79,   -79,   -79,   -79,     0,   -79,     0,     0,     0,
       0,     0,     0,   -79,   -79,   -79,     0,   -79,   -79,     0,
     -79,   -79,   -79,     0,   -79,   -79,     0,     0,     0,   -79,
     -22,   -22,   -79,   -22,   -22,   -22,   -22,     0,   -22,     0,
       0,     0,     0,     0,     0,   -22,   -22,   -22,     0,   -22,
     -22,     0,   -22,   -22,   -22,     0,   -22,   -22,     0,     0,
       0,   -22,   -19,   -19,   -22,   -19,   -19,   -19,   -19,     0,
     -19,     0,     0,     0,     0,     0,     0,   -19,   -19,   -19,
       0,   -19,   -19,     0,   -19,   -19,   -19,     0,   -19,   -19,
       0,     0,     0,   -19,   -74,   -74,   -19,   -74,   -74,   -74,
     -74,     0,   -74,     0,     0,     0,     0,     0,     0,   -74,
     -74,   -74,     0,   -74,   -74,     0,   -74,   -74,   -74,     0,
     -74,   -74,     0,     0,     0,   -74,   -75,   -75,   -74,   -75,
     -75,   -75,   -75,     0,   -75,     0,     0,     0,     0,     0,
       0,   -75,   -75,   -75,     0,   -75,   -75,     0,   -75,   -75,
     -75,     0,   -75,   -75,     0,     0,     0,   -75,   -76,   -76,
     -75,   -76,   -76,   -76,   -76,     0,   -76,     0,     0,     0,
       0,     0,     0,   -76,   -76,   -76,     0,   -76,   -76,     0,
     -76,   -76,   -76,     0,   -76,   -76,     0,     0,     0,   -76,
     -73,   -73,   -76,   -73,   -73,   -73,   -73,     0,   -73,     0,
       0,     0,     0,     0,     0,   -73,   -73,   -73,     0,   -73,
     -73,     0,   -73,   -73,   -73,     0,   -73,   -73,     0,     0,
       0,   -73,     0,   318,   -73,     2,     3,     4,   247,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,     0,     0,   281,   282,   283,   632,   284,   285,
       0,     0,     0,    17,     0,   318,   286,     2,     3,     4,
     247,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,   281,   282,   283,   634,
     284,   285,     0,     0,     0,    17,     0,   333,   286,     2,
       3,     4,   247,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,     0,     0,     0,   334,   335,
     336,   647,   337,   338,     0,     0,     0,    17,     0,   333,
     339,     2,     3,     4,   247,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
     334,   335,   336,   649,   337,   338,     0,     0,     0,    17,
       0,   318,   339,     2,     3,     4,   247,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
       0,     0,   281,   282,   283,     0,   284,   285,     0,     0,
       0,    17,     0,    77,   286,     2,     3,     4,   247,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,     0,     0,    12,    13,    14,     0,    15,    16,
       0,     0,     0,    17,     0,   333,    18,     2,     3,     4,
     247,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,   334,   335,   336,     0,
     337,   338,     0,     0,     0,    17,     0,   444,   339,   295,
     296,   297,   436,   446,     6,   295,   296,   297,   436,     0,
       6,     7,     8,     9,     0,     0,     0,     7,     8,     9,
       0,   448,     0,   295,   296,   297,   436,   299,     6,     0,
       0,     0,     0,   299,     0,     7,     8,     9,   450,     0,
     295,   296,   297,   436,     0,     6,     0,     0,     0,     0,
       0,   299,     7,     8,     9,   452,     0,   295,   296,   297,
     436,     0,     6,     0,     0,     0,     0,     0,   299,     7,
       8,     9,   456,     0,   295,   296,   297,   436,     0,     6,
       0,     0,     0,     0,     0,   299,     7,     8,     9,   473,
       0,     2,     3,     4,   247,     0,     6,     0,     0,     0,
       0,     0,   299,     7,     8,     9,   477,     0,   248,   249,
     250,   251,     0,     6,     0,     0,     0,     0,     0,    17,
       7,     8,     9,   495,     0,   347,   348,   349,   487,     0,
       6,     0,     0,     0,     0,     0,   252,     7,     8,     9,
     497,     0,   347,   348,   349,   487,     0,     6,     0,     0,
       0,     0,     0,   351,     7,     8,     9,   499,     0,   347,
     348,   349,   487,     0,     6,     0,     0,     0,     0,     0,
     351,     7,     8,     9,   501,     0,   347,   348,   349,   487,
       0,     6,     0,     0,     0,     0,     0,   351,     7,     8,
       9,   503,     0,   347,   348,   349,   487,     0,     6,     0,
       0,     0,     0,     0,   351,     7,     8,     9,   507,     0,
     347,   348,   349,   487,     0,     6,     0,     0,     0,     0,
       0,   351,     7,     8,     9,   511,     0,   248,   249,   250,
     390,     0,     6,     0,     0,     0,     0,     0,   351,     7,
       8,     9,   513,     0,   248,   249,   250,   390,     0,     6,
       0,     0,     0,     0,     0,   252,     7,     8,     9,   515,
       0,   248,   249,   250,   390,     0,     6,     0,     0,     0,
       0,     0,   252,     7,     8,     9,   517,     0,   248,   249,
     250,   390,     0,     6,     0,     0,     0,     0,     0,   252,
       7,     8,     9,   519,     0,   248,   249,   250,   390,     0,
       6,     0,     0,     0,     0,     0,   252,     7,     8,     9,
     521,     0,   248,   249,   250,   390,     0,     6,     0,     0,
       0,     0,     0,   252,     7,     8,     9,   523,     0,   248,
     249,   250,   390,     0,     6,     0,     0,     0,     0,     0,
     252,     7,     8,     9,   525,     0,   248,   249,   250,   390,
       0,     6,     0,     0,     0,     0,     0,   252,     7,     8,
       9,   527,     0,   248,   249,   250,   390,     0,     6,     0,
       0,     0,     0,     0,   252,     7,     8,     9,   535,     0,
     248,   249,   250,   251,     0,     6,     0,     0,     0,     0,
       0,   252,     7,     8,     9,   546,     0,   295,   296,   297,
     436,     0,     6,     0,     0,     0,     0,     0,   252,     7,
       8,     9,   548,     0,   295,   296,   297,   436,     0,     6,
       0,     0,     0,     0,     0,   299,     7,     8,     9,   550,
       0,   295,   296,   297,   436,     0,     6,     0,     0,     0,
       0,     0,   299,     7,     8,     9,   552,     0,   295,   296,
     297,   436,     0,     6,     0,     0,     0,     0,     0,   299,
       7,     8,     9,   554,     0,   295,   296,   297,   436,     0,
       6,     0,     0,     0,     0,     0,   299,     7,     8,     9,
     556,     0,   295,   296,   297,   436,     0,     6,     0,     0,
       0,     0,     0,   299,     7,     8,     9,   558,     0,   295,
     296,   297,   436,     0,     6,     0,     0,     0,     0,     0,
     299,     7,     8,     9,   560,     0,   295,   296,   297,   436,
       0,     6,     0,     0,     0,     0,     0,   299,     7,     8,
       9,   562,     0,   295,   296,   297,   436,     0,     6,     0,
       0,     0,     0,     0,   299,     7,     8,     9,   570,     0,
     248,   249,   250,   251,     0,     6,     0,     0,     0,     0,
       0,   299,     7,     8,     9,   579,     0,   347,   348,   349,
     487,     0,     6,     0,     0,     0,     0,     0,   252,     7,
       8,     9,   581,     0,   347,   348,   349,   487,     0,     6,
       0,     0,     0,     0,     0,   351,     7,     8,     9,   583,
       0,   347,   348,   349,   487,     0,     6,     0,     0,     0,
       0,     0,   351,     7,     8,     9,   585,     0,   347,   348,
     349,   487,     0,     6,     0,     0,     0,     0,     0,   351,
       7,     8,     9,   587,     0,   347,   348,   349,   487,     0,
       6,     0,     0,     0,     0,     0,   351,     7,     8,     9,
     589,     0,   347,   348,   349,   487,     0,     6,     0,     0,
       0,     0,     0,   351,     7,     8,     9,   591,     0,   347,
     348,   349,   487,     0,     6,     0,     0,     0,     0,     0,
     351,     7,     8,     9,   593,     0,   347,   348,   349,   487,
       0,     6,     0,     0,     0,     0,     0,   351,     7,     8,
       9,   595,     0,   347,   348,   349,   487,     0,     6,     0,
       0,     0,     0,     0,   351,     7,     8,     9,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,   351,     0,     0,     0,   313,     0,   314,   315,     0,
     316,    58,     0,     0,     0,     0,   317,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
    -124,  -124,  -124,  -124,   460,  -124,   461,   462,     0,   463,
      58,     0,  -124,  -124,  -124,   464,     0,     2,     3,     4,
     266,     0,     6,     0,     0,     0,     0,     0,  -124,     7,
       8,     9,     0,     0,   248,   249,   250,   390,     0,     6,
       0,     0,     0,     0,     0,    17,     7,     8,     9,     0,
       0,   295,   296,   297,   436,     0,     6,     0,     0,     0,
       0,     0,   252,     7,     8,     9,     0,     0,   347,   348,
     349,   487,     0,     6,     0,     0,     0,     0,     0,   299,
       7,     8,     9,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,     0,     0,     0,     0,     0,   351,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,     0,     0,     0,  -119,  -119,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,     0,     0,
       0,     0,  -125,  -125,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,     0,     0,     0,  -133,  -133,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,     0,     0,     0,     0,  -120,
    -120,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,     0,
       0,     0,  -136,  -136,   435,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,     0,     0,     0,     0,  -118,  -118,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,     0,     0,     0,  -114,
    -114,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,     0,
       0,     0,     0,  -135,  -135,   321,   322,   323,   324,   -90,
     326,   327,   328,     0,     0,     0,  -134,  -134,   321,   322,
     323,   -94,   -94,   326,   327,   328,     0,     0,     0,     0,
     -90,   -90,   321,   322,   323,   -98,   -98,   -98,   327,   328,
       0,     0,     0,   -94,   -94,   321,   322,  -102,  -102,  -102,
    -102,   327,   328,     0,     0,     0,     0,   -98,   -98,   321,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,     0,     0,
    -102,  -102,   435,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
       0,     0,     0,     0,  -113,  -113,   321,   322,  -108,  -108,
    -108,  -108,   327,   328,     0,     0,     0,  -112,  -112,   321,
     322,  -107,  -107,  -107,  -107,   327,   328,     0,     0,     0,
       0,  -108,  -108,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,     0,     0,     0,  -107,  -107,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,     0,     0,     0,     0,  -117,  -117,
     321,   322,   323,   324,   325,   326,   327,   328,     0,     0,
       0,  -116,  -116,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,     0,     0,     0,     0,   -84,   -84,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,  -126,  -126,
     369,   370,   371,   372,   373,   374,   375,   376,     0,   173,
      58,     0,   174,    46,    47,    48,    49,    50,    51,    52,
      53,     0,   220,   377,     0,   221,    46,    47,    48,    49,
      50,    51,    52,    53,     0,   606,    58,     0,   607,   369,
     370,   371,   372,   373,   374,   375,   376,     0,   619,    58,
       0,   620,   369,   370,   371,   372,   373,   374,   375,   376,
       0,   660,   377,     0,   661,   270,   271,   272,   273,   274,
     275,   276,   277,     0,   670,   377,     0,   671,   270,   271,
     272,   273,   274,   275,   276,   277,     0,     0,   278,     0,
     171,   486,  -111,  -111,  -111,  -111,  -111,  -111,  -111,     0,
       0,   278,     0,   240,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,     0,  -111,     0,     0,  -111,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,     0,  -115,     0,     0,  -115,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,     0,  -119,
       0,     0,  -119,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,     0,  -125,     0,     0,  -125,   270,   271,   272,   273,
     274,   275,   276,   277,     0,  -133,     0,     0,  -133,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,   278,
       0,   509,   270,   271,   272,   273,   274,   275,   276,   277,
       0,     0,   278,     0,   544,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,     0,     0,   278,     0,   577,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,     0,  -120,     0,     0,
    -120,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,     0,
    -136,     0,     0,  -136,   486,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,     0,  -118,     0,     0,  -118,   270,   271,   272,
     273,   274,   275,   276,   277,     0,  -114,     0,     0,  -114,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
     278,     0,   601,   270,   271,   272,   273,   274,   275,   276,
     277,     0,     0,   278,     0,   604,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,   278,     0,   614,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,     0,     0,   278,
       0,   617,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
       0,  -135,     0,     0,  -135,   369,   370,   371,   372,   -90,
     374,   375,   376,     0,  -134,     0,     0,  -134,   369,   370,
     371,   -94,   -94,   374,   375,   376,     0,   -90,     0,     0,
     -90,   369,   370,   371,   -98,   -98,   -98,   375,   376,     0,
     -94,     0,     0,   -94,   369,   370,  -102,  -102,  -102,  -102,
     375,   376,     0,   -98,     0,     0,   -98,   369,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,     0,  -102,     0,     0,  -102,
     486,  -112,  -112,  -112,  -112,  -112,  -112,  -112,     0,  -113,
       0,     0,  -113,   369,   370,  -108,  -108,  -108,  -108,   375,
     376,     0,  -112,     0,     0,  -112,   369,   370,  -107,  -107,
    -107,  -107,   375,   376,     0,  -108,     0,     0,  -108,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,     0,  -107,     0,
       0,  -107,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
       0,  -117,     0,     0,  -117,   369,   370,   371,   372,   373,
     374,   375,   376,     0,  -116,     0,     0,  -116,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,     0,   -84,     0,     0,
     -84,   270,   271,   272,   273,   274,   275,   276,   277,     0,
    -126,     0,     0,  -126,   270,   271,   272,   273,   274,   275,
     276,   277,     0,     0,   278,     0,   694,   389,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,     0,     0,   278,     0,   698,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,     0,     0,
       0,     0,  -111,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,     0,     0,     0,     0,  -115,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,     0,     0,     0,     0,  -119,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,     0,     0,     0,
       0,  -125,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
       0,     0,     0,     0,  -133,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,     0,     0,     0,     0,  -120,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,     0,     0,     0,     0,
    -136,   389,  -114,  -114,  -114,  -114,  -114,  -114,  -114,     0,
       0,     0,     0,  -118,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,     0,     0,     0,     0,  -114,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,     0,     0,     0,     0,  -135,
     270,   271,   272,   273,   -90,   275,   276,   277,     0,     0,
       0,     0,  -134,   270,   271,   272,   -94,   -94,   275,   276,
     277,     0,     0,     0,     0,   -90,   270,   271,   272,   -98,
     -98,   -98,   276,   277,     0,     0,     0,     0,   -94,   270,
     271,  -102,  -102,  -102,  -102,   276,   277,     0,     0,     0,
       0,   -98,   270,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
       0,     0,     0,     0,  -102,   389,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,     0,     0,     0,     0,  -113,   270,   271,
    -108,  -108,  -108,  -108,   276,   277,     0,     0,     0,     0,
    -112,   270,   271,  -107,  -107,  -107,  -107,   276,   277,     0,
       0,     0,     0,  -108,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,     0,     0,     0,     0,  -107,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,     0,     0,     0,     0,  -117,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,  -116,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,     0,     0,     0,     0,   -84,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,  -126,    46,
      47,    48,    49,    50,    51,    52,    53,     0,   539,    58,
     270,   271,   272,   273,   274,   275,   276,   277,     0,     0,
       0,   574,    58,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,     0,     0,   278,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,     0,     0,     0,  -143,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,     0,     0,  -144,    87,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,     0,     0,     0,  -142,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,     0,     0,  -111,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,     0,
       0,  -115,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
       0,     0,  -119,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,     0,     0,     0,  -125,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,     0,     0,  -133,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,     0,     0,     0,  -120,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,     0,     0,  -136,    87,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,     0,     0,     0,
    -118,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,     0,
       0,  -114,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
       0,     0,     0,  -135,    46,    47,    48,    49,   -90,    51,
      52,    53,     0,     0,  -134,    46,    47,    48,   -94,   -94,
      51,    52,    53,     0,     0,     0,   -90,    46,    47,    48,
     -98,   -98,   -98,    52,    53,     0,     0,   -94,    46,    47,
    -102,  -102,  -102,  -102,    52,    53,     0,     0,     0,   -98,
      46,  -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,     0,
    -102,    87,  -112,  -112,  -112,  -112,  -112,  -112,  -112,     0,
       0,     0,  -113,    46,    47,  -108,  -108,  -108,  -108,    52,
      53,     0,     0,  -112,    46,    47,  -107,  -107,  -107,  -107,
      52,    53,     0,     0,     0,  -108,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,     0,     0,  -107,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,     0,     0,     0,  -117,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,  -116,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,     0,     0,
       0,   -84,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,  -126,   270,   271,   272,   273,   274,   275,   276,
     277,   321,   322,   323,   324,   325,   326,   327,   328,   369,
     370,   371,   372,   373,   374,   375,   376
};

static const yytype_int16 yycheck[] =
{
       0,     0,   395,   286,     1,   423,   416,     1,    29,     6,
       0,    32,    29,     1,    29,     0,    16,    17,    32,     1,
      20,    20,     7,     8,     9,    10,    11,    12,    13,    14,
       1,     1,   173,     1,   175,     1,     6,    31,     6,    24,
       6,    26,    27,    31,    29,    30,     1,     1,   441,    31,
      35,    19,    20,    19,    20,    11,   339,   475,   468,    29,
      31,    31,     1,     0,    32,    65,    32,    67,    29,    69,
      32,    32,     1,    29,     0,    29,    31,   218,    29,   220,
       7,   222,     1,    20,     3,     4,     5,     6,    11,     8,
      29,     1,    92,    11,    20,    11,    15,    16,    17,   492,
      19,    20,    31,    22,    23,    24,    25,    26,    27,    32,
      29,    29,    31,    29,    32,    34,    35,     1,     1,    29,
       3,     4,     5,     6,    11,     8,     1,     1,     1,     1,
       1,    32,    15,    16,    17,     0,    19,    20,    32,    22,
      23,    24,    25,    26,    27,    32,     0,    31,    31,     1,
      29,    34,    35,    32,     6,    20,    31,    31,    31,    31,
      31,    10,    11,   162,    32,     1,    20,    19,    20,     1,
       6,   171,   172,   173,     6,   175,     1,     1,     1,    32,
      32,   181,     6,    32,     7,     8,     9,    10,    11,    12,
      13,    14,   191,    29,    32,    31,     1,    29,    29,    31,
     200,     6,   202,   129,    29,    29,     0,    30,    31,    32,
      33,     0,   211,    35,     1,   215,    21,   217,   218,   219,
     220,   221,   222,   223,    29,    29,    20,     1,    32,    10,
      11,    20,     6,     1,   171,   172,    11,    32,   238,   239,
     240,   241,    29,     1,     1,   171,   172,     1,     6,     6,
     176,    32,   252,     1,    29,     3,     4,     5,     6,     1,
       8,    29,     1,   200,    21,   202,     1,    15,    16,    17,
      18,    29,    29,     1,   200,    29,   202,    11,   215,   420,
     217,    32,   219,    31,   221,   285,   223,   224,    29,   215,
      29,   217,    29,   219,    29,   221,     6,   223,    32,   299,
     237,   238,   239,   240,   241,     0,   171,   172,    10,    11,
      12,    21,   238,   239,   240,   241,     1,   171,   172,     1,
      11,     6,    32,    33,     6,    20,    29,    29,    32,    32,
      32,   472,    32,    10,    11,   200,    34,   202,   338,    21,
       1,    32,    33,    32,    29,     6,   200,    29,   202,    31,
     215,   351,   217,     6,   219,    32,   221,     1,   223,    32,
      21,   215,     6,   217,    32,   219,    32,   221,    29,   223,
      31,     6,    32,   238,   239,   240,   241,   171,   172,    32,
      33,    29,   171,   172,   238,   239,   240,   241,     6,     1,
      29,     3,     4,     5,     6,   395,     8,    32,    33,     9,
      10,    11,    12,    15,    16,    17,   200,    29,   202,     6,
      32,   200,     1,   202,    32,    33,   416,    29,   418,    31,
     420,   215,    32,   217,    21,   219,   215,   221,   217,   223,
     219,    32,   221,    11,   223,    32,    33,     9,    10,    11,
      12,   441,    29,    30,   238,   239,   240,   241,    32,   238,
     239,   240,   241,    29,    32,    33,    32,    29,     7,     1,
      32,     3,     4,     5,     6,   606,     8,   608,   468,    29,
     470,     0,   472,    15,    16,    17,   171,   172,   619,    32,
     621,     1,     7,     3,     4,     5,     6,    29,     8,    31,
      32,    20,   492,    10,    11,    15,    16,    17,    32,    33,
       9,    10,    11,    12,    32,   200,    29,   202,     7,    29,
      32,    31,    32,    32,    33,    32,    33,   658,    32,   660,
     215,   662,   217,    32,   219,    32,   221,   668,   223,   670,
      32,   672,    11,     1,    32,     3,     4,     5,     6,    32,
       8,    29,    30,   238,   239,   240,   241,    15,    16,    17,
      29,    19,    20,    32,    22,    23,    24,    25,    26,    27,
      10,    11,    12,    31,    29,    30,    34,    35,     0,     1,
      29,     3,     4,     5,     6,    11,     8,    35,     9,    10,
      11,    12,    32,    15,    16,    17,     1,    19,    20,    32,
      22,    23,    24,    29,    26,    27,    32,    29,    29,    31,
      29,    32,    34,    10,    11,    12,   606,    32,   608,     1,
      32,     3,     4,     5,     6,    11,     8,   617,   618,   619,
      32,   621,    29,    15,    16,    17,    32,    19,    20,    32,
      22,    23,    24,    25,    26,    27,    32,    33,    35,    31,
      10,    11,    34,    35,     1,    10,    11,   647,    32,   649,
       7,     8,     9,    10,    11,    12,    13,    14,   658,    29,
     660,    29,   662,    29,    29,   665,    29,   667,   668,   669,
     670,   671,   672,   673,    31,    32,    33,     1,   604,   605,
     617,   618,    29,     7,     8,     9,    10,    11,    12,    13,
      14,   617,   618,    29,    30,    31,   696,   697,   698,   699,
      32,     9,    10,    11,    12,    29,   632,    31,   634,    32,
     647,    32,   649,     7,     8,     9,    10,    11,    12,    13,
      14,   647,    32,   649,    32,    33,    10,    11,   665,   655,
     667,   657,   669,   659,   671,   661,   673,   663,    32,   665,
      32,   667,    32,   669,    20,   671,   191,   673,    32,    33,
      32,    33,   617,   618,     9,    10,    11,    12,   211,   696,
     697,   698,   699,   617,   618,   132,   692,   693,   694,   695,
     696,   697,   698,   699,    10,    11,    12,    32,    33,     1,
      32,    33,   647,    -1,   649,     7,     8,     9,    10,    11,
      12,    13,    14,   647,    -1,   649,    32,    33,    10,    11,
     665,    -1,   667,    -1,   669,    -1,   671,    29,   673,    31,
      32,   665,     6,   667,    -1,   669,    -1,   671,    -1,   673,
      32,    33,    -1,   617,   618,    19,    20,    -1,   617,   618,
      -1,   696,   697,   698,   699,     8,     9,    10,    11,    12,
      13,    14,   696,   697,   698,   699,    -1,     9,    10,    11,
      12,    32,    33,   647,    -1,   649,     1,    -1,   647,    32,
     649,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      32,   665,    -1,   667,    -1,   669,   665,   671,   667,   673,
     669,    -1,   671,    -1,   673,    30,    31,    32,    33,     9,
      10,    11,    12,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,   696,   697,   698,   699,    -1,   696,   697,   698,
     699,     1,    32,     3,     4,     5,     6,    30,     8,    32,
      33,    -1,   617,   618,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    29,    30,
      31,    31,     0,    -1,    34,    35,    10,    11,     9,    10,
      11,    12,   647,     1,   649,     3,     4,     5,     6,    17,
       8,    -1,    20,    32,    33,    29,    -1,    15,    16,    17,
     665,    32,   667,    -1,   669,    -1,   671,    -1,   673,    32,
      33,    29,    40,    31,    32,    43,    44,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,     9,    10,    11,    12,
      58,   696,   697,   698,   699,    63,    -1,    65,    -1,    67,
      10,    11,    12,     9,    10,    11,    12,    75,    -1,    32,
      33,    -1,    80,    81,    82,    83,    84,    85,    86,    87,
      32,    33,    32,    91,    92,     1,    32,     3,     4,     5,
       6,    -1,     8,    -1,     9,    10,    11,    12,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    32,    33,    29,    31,    -1,    32,    34,    35,
       9,    10,    11,    12,   132,    10,    11,     1,   136,     3,
       4,     5,     6,    -1,     8,    -1,     9,    10,    11,    12,
      29,    15,    16,    17,    29,    19,    20,    32,    22,    23,
      24,    25,    26,    27,   162,    -1,    29,    31,    -1,    32,
      34,    35,    10,    11,    12,   173,    -1,   175,    32,    33,
      10,    11,     1,   181,     3,     4,     5,     6,    -1,     8,
      -1,   189,    -1,   191,    32,    33,    15,    16,    17,    29,
      19,    20,    32,    22,    23,    24,    25,    26,    27,    10,
      11,    12,    31,   211,    -1,    34,    35,    10,    11,    12,
     218,    -1,   220,     1,   222,     3,     4,     5,     6,    -1,
       8,    32,     9,    10,    11,    12,    29,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      29,    30,    29,    31,   252,    32,    34,    35,     9,    10,
      11,    12,    -1,   261,     7,     8,     9,    10,    11,    12,
      13,    14,   270,   271,   272,   273,   274,   275,   276,   277,
     278,    32,    33,     1,    -1,     3,     4,     5,     6,    32,
       8,    -1,     9,    10,    11,    12,   294,    15,    16,    17,
      -1,   299,    -1,    -1,    22,    23,    24,    25,    26,    27,
     308,    -1,    29,    31,    -1,    32,    34,    -1,    -1,     9,
      10,    11,    12,   321,   322,   323,   324,   325,   326,   327,
     328,   329,    -1,    17,     1,     9,    10,    11,    12,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    10,    11,
      12,    -1,    -1,   351,     7,     8,    40,    -1,    32,    33,
      13,    14,    46,   361,    31,    32,    33,    29,    -1,    -1,
      32,   369,   370,   371,   372,   373,   374,   375,   376,   377,
      -1,    65,    -1,    67,   382,   383,   384,   385,   386,   387,
     388,   389,     9,    10,    11,    12,   394,   395,    -1,     3,
       4,     5,     6,    87,     8,    -1,    -1,    -1,    92,    -1,
      -1,    15,    16,    17,    -1,    32,   414,    -1,   416,    -1,
     418,     9,    10,    11,    12,   423,    -1,    31,    -1,    -1,
     428,   429,   430,   431,   432,   433,   434,   435,     9,    10,
      11,    12,   440,   441,    32,     1,     9,    10,    11,    12,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    32,    33,    -1,    -1,    -1,    29,    -1,   466,    32,
     468,    -1,   470,    29,    30,    31,    32,   475,    -1,    -1,
      -1,   479,   480,   481,   482,   483,   484,   485,   486,   173,
      -1,   175,    -1,   491,   492,    -1,     1,   181,     3,     4,
       5,     6,    -1,     8,    -1,     9,    10,    11,    12,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    29,    31,    -1,    32,    34,
      35,    10,    11,    12,   218,    -1,   220,    -1,   222,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      29,    -1,    -1,    32,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,   252,    -1,
      31,    -1,     1,    34,    -1,    -1,    -1,   261,     7,     8,
       9,    10,    11,    12,    13,    14,   270,   271,   272,   273,
     274,   275,   276,   277,   278,     9,    10,    11,    12,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,   606,    -1,
     608,     9,    10,    11,    12,   299,    -1,    -1,    32,     1,
      -1,   619,    -1,   621,   308,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    32,    33,    -1,   321,   322,   323,
     324,   325,   326,   327,   328,   329,    -1,    17,    30,    31,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
     658,    -1,   660,    -1,   662,    -1,    -1,   351,    -1,    -1,
     668,    -1,   670,    29,   672,    -1,    32,   361,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   369,   370,   371,   372,   373,
     374,   375,   376,   377,    -1,    65,    -1,    67,   382,   383,
     384,   385,   386,   387,   388,   389,     1,    -1,    -1,    -1,
     394,   395,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    92,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,   416,    -1,   418,    30,    31,    32,    15,    16,
      17,    -1,    -1,    -1,   428,   429,   430,   431,   432,   433,
     434,   435,     1,    -1,    31,    32,   440,   441,     7,     8,
       9,    10,    11,    12,    13,    14,    10,    11,    12,     9,
      10,    11,    12,    -1,     1,    -1,     3,     4,     5,     6,
      29,     8,    31,    32,   468,    29,   470,    -1,    15,    16,
      17,    18,    32,    33,    -1,   479,   480,   481,   482,   483,
     484,   485,   486,   173,    31,   175,    -1,   491,   492,     0,
       1,   181,     3,     4,     5,     6,    -1,     8,    -1,     9,
      10,    11,    12,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    29,
      31,    -1,     1,    34,     3,     4,     5,     6,   218,     8,
     220,    -1,   222,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,     7,     8,    34,    35,    -1,    -1,    13,
      14,     1,   252,     3,     4,     5,     6,    -1,     8,    -1,
      -1,   261,    10,    11,    12,    15,    16,    17,    -1,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,    29,
      -1,    31,    32,    -1,    32,    33,     1,    -1,     3,     4,
       5,     6,   606,     8,   608,     9,    10,    11,    12,   299,
      15,    16,    17,    -1,    -1,   619,    -1,   621,   308,     8,
       9,    10,    11,    12,    13,    14,    31,    32,    32,    33,
      -1,   321,   322,   323,   324,   325,   326,   327,   328,   329,
      29,    17,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,   658,    -1,   660,    -1,   662,    -1,
      -1,   351,    -1,    -1,   668,    -1,   670,    -1,   672,    32,
      33,   361,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,
     370,   371,   372,   373,   374,   375,   376,   377,    -1,    65,
      -1,    67,   382,   383,   384,   385,   386,   387,   388,   389,
       9,    10,    11,    12,   394,   395,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    92,    -1,    -1,    -1,
      15,    16,    17,    32,    33,    -1,   416,    -1,   418,     9,
      10,    11,    12,    -1,    -1,    -1,    31,    32,   428,   429,
     430,   431,   432,   433,   434,   435,     1,    -1,    -1,    29,
     440,   441,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,     9,    10,    11,    12,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    31,    32,   468,    -1,
     470,    -1,    15,    16,    17,    18,    32,    -1,    -1,   479,
     480,   481,   482,   483,   484,   485,   486,   173,    31,   175,
      -1,   491,   492,    -1,     1,   181,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    29,    31,    -1,    32,    34,    35,    -1,
      -1,    -1,   218,    -1,   220,     1,   222,     3,     4,     5,
       6,    -1,     8,    -1,     9,    10,    11,    12,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    29,    31,   252,    32,    34,    35,
       1,    -1,    -1,    -1,    -1,   261,     7,     8,     9,    10,
      11,    12,    13,    14,   270,   271,   272,   273,   274,   275,
     276,   277,   278,    10,    11,    -1,     9,    10,    11,    12,
      31,    32,    -1,     7,     8,     9,   606,    -1,   608,    13,
      14,    -1,    29,   299,    -1,    32,    29,    -1,     1,   619,
      -1,   621,   308,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,   321,   322,   323,   324,   325,
     326,   327,   328,   329,    -1,    17,    29,    30,    31,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,   658,    -1,
     660,    -1,   662,    -1,    -1,   351,    -1,    -1,   668,    -1,
     670,    29,   672,    -1,    32,   361,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   369,   370,   371,   372,   373,   374,   375,
     376,   377,    -1,    65,    -1,    67,   382,   383,   384,   385,
     386,   387,   388,   389,    -1,    -1,    -1,    -1,   394,   395,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      92,     7,     8,     9,    15,    16,    17,    13,    14,    -1,
     416,    -1,   418,     9,    10,    11,    12,    -1,    -1,    -1,
      31,    32,   428,   429,   430,   431,   432,   433,   434,   435,
      -1,    -1,    -1,    29,   440,   441,     1,    -1,     3,     4,
       5,     6,     1,     8,     3,     4,     5,     6,    -1,     8,
      15,    16,    17,     7,     8,     9,    15,    16,    17,    13,
      14,    -1,   468,    -1,   470,    -1,    31,    32,    -1,    -1,
      29,    -1,    31,   479,   480,   481,   482,   483,   484,   485,
     486,   173,    -1,   175,    -1,   491,   492,    -1,     1,   181,
       3,     4,     5,     6,    -1,     8,    -1,     9,    10,    11,
      12,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    29,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,   218,    -1,   220,     1,
     222,     3,     4,     5,     6,    -1,     8,    -1,     9,    10,
      11,    12,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    29,    31,
     252,    -1,    34,    35,     1,    -1,    -1,    -1,    -1,   261,
       7,     8,     9,    10,    11,    12,    13,    14,   270,   271,
     272,   273,   274,   275,   276,   277,   278,    -1,     9,    10,
      11,    12,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
     606,    -1,   608,    -1,     7,     8,     9,   299,    29,    12,
      13,    14,     1,   619,    -1,   621,   308,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,   321,
     322,   323,   324,   325,   326,   327,   328,   329,    -1,    17,
      29,    30,    31,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,   658,    -1,   660,    -1,   662,    -1,    -1,   351,
      -1,    -1,   668,    -1,   670,    29,   672,    -1,    32,   361,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   369,   370,   371,
     372,   373,   374,   375,   376,   377,    -1,    65,    -1,    67,
     382,   383,   384,   385,   386,   387,   388,   389,    -1,     1,
      -1,    -1,   394,   395,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    92,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,   416,    -1,   418,    29,    30,    31,
      15,    16,    17,    -1,    -1,    -1,   428,   429,   430,   431,
     432,   433,   434,   435,     1,    -1,    31,    -1,   440,   441,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,     1,    -1,     3,     4,
       5,     6,    29,     8,    31,    -1,   468,    -1,   470,    -1,
      15,    16,    17,    32,    33,    -1,    -1,   479,   480,   481,
     482,   483,   484,   485,   486,   173,    31,   175,    -1,   491,
     492,    -1,     1,   181,     3,     4,     5,     6,    -1,     8,
      -1,     9,    10,    11,    12,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    29,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
     218,    -1,   220,     1,   222,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,   252,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,   261,     7,     8,     9,    10,    11,    12,
      13,    14,   270,   271,   272,   273,   274,   275,   276,   277,
     278,    -1,    -1,     1,    -1,     3,     4,     5,     6,    32,
       8,    -1,    -1,    -1,   606,    -1,   608,    15,    16,    17,
      -1,   299,    -1,    -1,    -1,    -1,    -1,   619,    -1,   621,
     308,    29,    -1,    31,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,   321,   322,   323,   324,   325,   326,   327,
     328,   329,    24,    25,    26,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    35,    -1,    -1,   658,    -1,   660,    -1,
     662,    -1,    -1,   351,    -1,    -1,   668,    -1,   670,    -1,
     672,     7,     8,   361,    -1,    -1,    -1,    13,    14,    -1,
      -1,   369,   370,   371,   372,   373,   374,   375,   376,   377,
      -1,    -1,    -1,    -1,   382,   383,   384,   385,   386,   387,
     388,   389,    -1,    -1,    -1,    -1,   394,   395,    17,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
       7,     8,     9,    15,    16,    17,    13,    14,   416,    -1,
     418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    31,
     428,   429,   430,   431,   432,   433,   434,   435,     7,     8,
      -1,    -1,   440,   441,    13,    14,    65,     1,    67,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    84,    -1,    -1,    -1,    -1,
     468,    -1,   470,    92,    -1,    -1,    -1,    31,    -1,    -1,
      -1,   479,   480,   481,   482,   483,   484,   485,   486,    -1,
      -1,    -1,    -1,   491,   492,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,   173,    -1,   175,    -1,    31,    15,
      16,    17,   181,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,   218,
      -1,   220,    -1,   222,    -1,    -1,    -1,    -1,   606,    -1,
     608,    31,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,   619,    -1,   621,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,   252,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,   271,   272,   273,   274,   275,   276,   277,   278,
     658,    -1,   660,    -1,   662,    -1,    -1,    -1,    -1,    -1,
     668,    -1,   670,    -1,   672,    -1,    -1,    -1,    -1,    -1,
     299,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,   322,   323,   324,   325,   326,   327,   328,
     329,    17,    31,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,   351,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    48,    -1,    -1,    31,    52,    53,    34,    35,
      -1,   370,   371,   372,   373,   374,   375,   376,   377,    65,
      -1,    67,    -1,   382,   383,   384,   385,   386,   387,   388,
      -1,    -1,    -1,    -1,    -1,   394,   395,    83,    -1,    85,
      86,    -1,    -1,    -1,    -1,    -1,    92,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,   416,    -1,   418,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,   428,
     429,   430,   431,   432,   433,   434,    -1,    31,    -1,    -1,
      -1,   440,   441,     1,    -1,     3,     4,     5,     6,     1,
       8,     3,     4,     5,     6,    -1,     8,    15,    16,    17,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,   468,
      -1,   470,    -1,    31,    -1,    -1,    -1,    -1,    -1,    31,
     479,   480,   481,   482,   483,   484,   485,   173,    -1,   175,
      -1,    -1,   491,   492,     1,   181,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,
      -1,    -1,   218,    -1,   220,     1,   222,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,   252,    -1,    34,    35,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    17,    12,    13,    14,   272,   273,   274,   275,
     276,   277,   278,    30,    -1,    32,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,   606,    -1,   608,
      15,    16,    17,   299,    -1,    -1,    -1,    -1,    -1,    -1,
     619,    -1,   621,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      65,    -1,    67,    -1,    -1,    -1,    -1,   323,   324,   325,
     326,   327,   328,   329,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    92,    -1,   658,
      -1,   660,    -1,   662,    -1,   351,    -1,    -1,    -1,   668,
      -1,   670,    -1,   672,    32,    33,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,   371,   372,   373,   374,   375,
     376,   377,    -1,    -1,    -1,    -1,   382,   383,   384,   385,
      30,   387,   388,    -1,    -1,    -1,    -1,    -1,   394,   395,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
     416,    -1,   418,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,    31,   428,   429,   430,   431,   181,   433,   434,    -1,
      -1,    -1,    -1,    -1,   440,   441,     1,    -1,     3,     4,
       5,     6,     1,     8,     3,     4,     5,     6,    -1,     8,
      15,    16,    17,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,   468,   218,   470,   220,    31,   222,    -1,    -1,
      -1,    -1,    31,   479,   480,   481,   482,    -1,   484,   485,
      -1,    -1,    -1,    -1,    -1,   491,   492,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    26,    27,    -1,    29,
      30,    -1,    -1,    17,    -1,    35,    -1,   272,   273,   274,
     275,   276,   277,   278,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,   299,    19,    20,    51,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    65,    -1,    67,    -1,    -1,    -1,    -1,   323,   324,
     325,   326,   327,   328,   329,    -1,    -1,     1,    82,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    92,    -1,
      -1,    15,    16,    17,    -1,    -1,   351,    -1,    -1,    -1,
     606,    -1,   608,     7,     8,     9,    10,    31,    12,    13,
      14,    -1,    -1,   619,    -1,   621,   371,   372,   373,   374,
     375,   376,   377,    -1,    -1,    -1,    -1,   382,   383,   384,
     385,    -1,   387,   388,    -1,    -1,    -1,    -1,    -1,   394,
     395,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,   658,    -1,   660,    -1,   662,    -1,    -1,    -1,
      -1,   416,   668,   418,   670,    -1,   672,    32,    33,   173,
      -1,   175,    -1,   428,   429,   430,   431,   181,   433,   434,
      -1,    -1,    -1,    -1,    -1,   440,   441,     1,    -1,     3,
       4,     5,     6,     1,     8,     3,     4,     5,     6,    -1,
       8,    15,    16,    17,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,   468,   218,   470,   220,    31,   222,    -1,
      -1,    -1,    -1,    31,   479,   480,   481,   482,    17,   484,
     485,    -1,    -1,    -1,    -1,    -1,   491,   492,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,   252,    -1,
      -1,    -1,    15,    16,    17,    -1,     7,     8,     9,    10,
      49,    12,    13,    14,    17,    -1,    -1,    -1,    31,   273,
     274,   275,    -1,    -1,   278,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    81,    -1,    -1,   299,    -1,    15,    16,    17,
      -1,    -1,    -1,    92,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    31,    67,    -1,    -1,    -1,    -1,    -1,
     324,   325,   326,    -1,    -1,   329,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    91,    92,
      15,    16,    17,     7,     8,     9,    10,   351,    12,    13,
      14,   606,    -1,   608,    -1,    -1,    31,     8,     9,    10,
      11,    12,    13,    14,   619,    -1,   621,    -1,   372,   373,
     374,    -1,    -1,   377,    -1,    -1,    -1,    -1,   382,   383,
     384,    32,    33,    -1,   173,    -1,   175,    -1,    -1,    -1,
     394,   395,   181,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,   658,    -1,   660,    -1,   662,    -1,    -1,
      -1,    -1,   416,   668,   418,   670,    -1,   672,    32,    33,
     173,    -1,   175,    -1,   428,   429,   430,    -1,   181,   218,
      -1,   220,    -1,   222,    -1,    -1,   440,   441,     1,    -1,
       3,     4,     5,     6,     1,     8,     3,     4,     5,     6,
      -1,     8,    15,    16,    17,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,   252,   468,   218,   470,   220,    31,   222,
      -1,    -1,    -1,    -1,    31,   479,   480,   481,    -1,    17,
      -1,    -1,    -1,    -1,   273,   274,    -1,   491,   492,   278,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,   252,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
     299,    -1,    50,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,   278,    34,    65,    -1,    67,
      -1,    -1,     7,     8,     9,   324,   325,    12,    13,    14,
     329,    -1,    80,    -1,     0,     1,   299,     3,     4,     5,
       6,    -1,     8,    -1,    92,    -1,    -1,    -1,    -1,    15,
      16,    17,   351,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,   329,    -1,    34,    -1,
       7,     8,     9,   372,   373,    12,    13,    14,   377,    -1,
       7,     8,     9,   382,   383,    12,    13,    14,   351,    -1,
      -1,    -1,   606,    -1,   608,   394,   395,     8,     9,    10,
      11,    12,    13,    14,    -1,   619,     1,   621,     3,     4,
       5,     6,    -1,     8,   377,    -1,    -1,   416,    29,   418,
      15,    16,    17,    -1,    -1,   173,    -1,   175,    -1,   428,
     429,   394,   395,   181,    -1,    -1,    31,    -1,    -1,    -1,
      -1,   440,   441,    -1,   658,    -1,   660,    -1,   662,    -1,
      -1,    -1,    -1,   416,   668,   418,   670,    -1,   672,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,   468,
     218,   470,   220,    -1,   222,    -1,    -1,   440,   441,    -1,
     479,   480,     1,    30,     3,     4,     5,     6,    -1,     8,
      -1,    -1,   491,   492,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,   252,   468,    -1,   470,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,   274,    -1,   491,   492,
     278,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,   299,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    29,    30,    -1,   325,    15,    16,
      17,   329,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,   351,    -1,    -1,    -1,   606,    -1,   608,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
     619,    -1,   621,    -1,    -1,   373,    15,    16,    17,   377,
      -1,    -1,    -1,    -1,   382,    -1,     3,     4,     5,     6,
      -1,     8,    31,   606,    -1,   608,   394,   395,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,   619,    -1,   621,   658,
      -1,   660,    -1,   662,    31,    -1,    -1,    -1,   416,   668,
     418,   670,     1,   672,     3,     4,     5,     6,    -1,     8,
     428,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,   440,   441,    -1,   658,    -1,   660,    -1,   662,
      -1,    -1,    31,    -1,    -1,   668,    -1,   670,    -1,   672,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
     468,    -1,   470,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,   479,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    31,    -1,   491,   492,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,   606,    -1,
     608,     1,    31,     3,     4,     5,     6,    -1,     8,    -1,
      -1,   619,    30,   621,    32,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
     658,    -1,   660,    -1,   662,    15,    16,    17,    -1,    -1,
     668,    -1,   670,     1,   672,     3,     4,     5,     6,    -1,
       8,    31,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
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
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
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
      24,    25,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
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
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,     0,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,     0,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
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
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
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
      24,    25,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
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
      31,    -1,    -1,    34,    35,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,     0,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,     0,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,     0,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
       0,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
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
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,    -1,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
       4,     5,     6,     1,     8,     3,     4,     5,     6,    -1,
       8,    15,    16,    17,    -1,    -1,    -1,    15,    16,    17,
      -1,     1,    -1,     3,     4,     5,     6,    31,     8,    -1,
      -1,    -1,    -1,    31,    -1,    15,    16,    17,     1,    -1,
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
      -1,    -1,    -1,    -1,    31,    15,    16,    17,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    24,    -1,    26,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    35,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    24,     8,    26,    27,    -1,    29,
      30,    -1,    15,    16,    17,    35,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,
      16,    17,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,    -1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    31,    15,    16,    17,    -1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,
      15,    16,    17,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    31,     7,     8,     9,
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
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    29,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    29,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    29,    30,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    29,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    29,    30,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    29,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    30,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    29,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    29,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    29,
      -1,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    29,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    29,    -1,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    30,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    29,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    29,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    29,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    30,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    29,    -1,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    29,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    29,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    29,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    29,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    29,
      -1,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    29,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    29,    -1,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    29,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    29,    -1,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    29,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    29,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    30,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    30,     7,     8,     9,    10,    11,    12,
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
      14,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,    15,    16,    17,
      19,    20,    22,    23,    24,    26,    27,    31,    34,    37,
      38,    39,    40,    41,    49,    54,    55,    56,    57,    59,
      60,    61,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    75,    76,    77,    78,     7,     8,     9,    10,
      11,    12,    13,    14,    24,    26,    27,    29,    30,    35,
      21,    21,     1,    31,     1,    31,     1,    31,     1,    31,
       1,    61,    76,     1,    61,    50,     0,     1,    39,    29,
      11,    10,    12,     9,     8,    13,    14,     7,    70,    76,
       1,    30,    31,    76,     1,    29,    31,    76,    70,     1,
      69,     1,    67,     1,    65,     1,    64,     1,    66,    67,
      67,     1,    63,     1,    76,     1,    18,    61,    79,     1,
      61,     1,    61,    62,    29,    29,    32,    32,     1,    25,
      40,    51,    52,    53,    54,    58,    77,     1,    64,     1,
      65,     1,    66,     1,    67,     1,    69,     1,    67,     1,
      67,     1,    70,     1,    63,     1,    61,    73,    74,    29,
      30,    29,    44,    29,    30,    31,    32,    32,    32,    32,
      32,    32,    32,    29,    32,    29,    25,    54,    35,    53,
      76,    33,    32,     1,     1,    46,    47,    48,    76,    77,
       1,    42,    29,     1,    29,    29,     1,    29,     1,    29,
      25,    54,    25,    54,     1,    62,     1,    62,    54,    61,
      45,    33,    76,    46,    54,    25,    54,    25,    29,    32,
      29,    32,    29,    32,    32,    48,    43,    54,    54,    62,
      54,    62,    54,     1,    62,    54,    49,    32,    32,    32,
      32,    32,    49,    54,    54,    54,    54,     6,     3,     4,
       5,     6,    31,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    75,    76,    78,     6,     6,     6,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    30,    19,
      20,    22,    23,    24,    26,    27,    34,    49,    55,    56,
      57,    59,    60,    61,    76,     3,     4,     5,     6,    31,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      75,    76,    78,    24,    26,    27,    29,    35,     1,     1,
      29,     7,     8,     9,    10,    11,    12,    13,    14,    30,
       6,    19,    20,     1,    22,    23,    24,    26,    27,    34,
      49,    55,    56,    57,    59,    60,    61,     3,     4,     5,
       6,    31,    61,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    75,    76,    78,    29,    30,     1,     7,
       8,     9,    10,    11,    12,    13,    14,    30,     1,    61,
       1,    61,    11,    10,    12,     9,     8,    13,    14,     7,
       6,    70,    76,     1,    30,    31,    70,     1,    69,     1,
      67,     1,    65,     1,    64,     1,    66,    67,    67,     1,
      63,    21,    21,     1,    31,     1,    31,     1,    31,     1,
      31,     1,    61,    50,    29,    76,     1,    61,    11,    10,
      12,     9,     8,    13,    14,     7,     6,    70,    76,     1,
      30,    31,    29,    70,     1,    69,     1,    67,     1,    65,
       1,    64,     1,    66,    67,    67,     1,    63,    21,    21,
      24,    26,    27,    29,    35,     1,    31,     1,    31,     1,
      31,     1,    31,     1,    61,    50,    29,     1,    61,    11,
      10,    12,     9,     8,    13,    14,     7,     6,    70,    76,
       1,    30,    31,     1,    70,     1,    69,     1,    67,     1,
      65,     1,    64,     1,    66,    67,    67,     1,    63,    32,
      32,     1,    64,     1,    65,     1,    66,     1,    67,     1,
      69,     1,    67,     1,    67,     1,    70,     1,    63,    74,
       1,    76,     1,    61,    79,     1,    61,     1,    62,    29,
      29,    51,    29,    30,    32,    32,     1,    64,     1,    65,
       1,    66,     1,    67,     1,    69,     1,    67,     1,    67,
       1,    70,     1,    63,    74,     1,    76,     1,    61,    79,
       1,    61,     1,    62,    29,    29,    51,    32,    32,     1,
      64,     1,    65,     1,    66,     1,    67,     1,    69,     1,
      67,     1,    67,     1,    70,     1,    63,    74,    32,    32,
      32,    32,    32,    32,    32,    32,    29,    32,    29,    35,
       1,    32,    32,    32,    32,    32,    32,    32,    32,    29,
      32,    29,    35,    32,    29,     1,    29,    29,     1,    29,
       1,    29,    25,    54,    25,    54,    62,     1,    62,    29,
       1,    29,    29,     1,    29,     1,    29,    25,    54,    25,
      54,    62,     1,    62,    54,    25,    54,    25,    29,    32,
      29,    32,    29,    32,    54,    25,    54,    25,    29,    32,
      29,    32,    29,    32,    54,    54,    62,    54,    62,    54,
       1,    62,    54,    54,    54,    62,    54,    62,    54,     1,
      62,    54,    32,    32,    32,    32,    32,    32,    32,    32,
      54,    54,    54,    54,    54,    54,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    38,    38,    39,    39,    39,
      40,    40,    40,    40,    40,    40,    40,    42,    43,    41,
      44,    45,    41,    46,    46,    47,    47,    47,    48,    48,
      48,    50,    49,    51,    51,    52,    52,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    61,    62,    62,    63,    63,
      63,    63,    64,    64,    64,    64,    65,    65,    65,    65,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    69,    69,    70,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    76,    77,    77,
      77,    77,    78,    78,    78,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       3,     2,     4,     4,     3,     2,     3,     0,     0,     8,
       0,     0,     7,     0,     1,     3,     1,     1,     2,     1,
       1,     0,     4,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     5,
       5,     5,     5,     5,     2,     2,     2,     2,     2,     2,
       2,     2,     5,     7,     6,     5,     7,     6,     2,     2,
       3,     3,     3,     9,     9,     9,     9,     4,     2,     7,
       7,     7,     1,     3,     3,     3,     0,     1,     1,     3,
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
#line 130 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 4033 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4039 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4045 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4051 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4057 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4063 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4069 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4075 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4081 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4087 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4093 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4099 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4105 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4111 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4117 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4123 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4129 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4135 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4141 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4147 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4153 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_1: /* @1  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4159 "src/bison/grammar.c"
        break;

    case YYSYMBOL_46_param_list_opt: /* param_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4165 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4171 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4177 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4183 "src/bison/grammar.c"
        break;

    case YYSYMBOL_51_block_item_list_opt: /* block_item_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4189 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4195 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4201 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4207 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4213 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4219 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4225 "src/bison/grammar.c"
        break;

    case YYSYMBOL_else_error: /* else_error  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4231 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4237 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4243 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4249 "src/bison/grammar.c"
        break;

    case YYSYMBOL_62_expression_opt: /* expression.opt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4255 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4261 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4267 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4273 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4279 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4285 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4291 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4297 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4303 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4309 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4315 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4321 "src/bison/grammar.c"
        break;

    case YYSYMBOL_74_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4327 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4333 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 130 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 4339 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4345 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4351 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4357 "src/bison/grammar.c"
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
#line 136 "src/bison/grammar.y"
             { show_error((yyloc), "ISO C-IPL forbids an empty translation unit\n"); }
#line 4666 "src/bison/grammar.c"
    break;

  case 4: /* prog: error  */
#line 137 "src/bison/grammar.y"
            {
        // idk if this is the best solution
        // actually dont work properly
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
    }
#line 4676 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration_list external_declaration  */
#line 144 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4682 "src/bison/grammar.c"
    break;

  case 6: /* external_declaration_list: external_declaration  */
#line 145 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4688 "src/bison/grammar.c"
    break;

  case 9: /* external_declaration: statement  */
#line 150 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4698 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type id ';'  */
#line 157 "src/bison/grammar.y"
                             {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[-1].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-2].pchar));
        if (sym) {
            if (sym->scope) {
                show_error_range((yylsp[-1]), "redeclaration of " BCYN "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            } else if (sym->kind == FUNC) {
                show_error_range((yylsp[-1]), BBLU "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
            } else if (sym->type != decl_type) {
                show_error_range((yylsp[-2]), "conflicting types for " BCYN "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            }
            (yyval.ast) = NULL;
        }
        else {
            symbol_update_type((yyvsp[-1].sym), decl_type);
            symbol_update_temp((yyvsp[-1].sym), current_context->t9n->temp++);
            (yyvsp[-1].sym)->kind = VAR;
            (yyval.ast) = ast_declaration_init((yyloc), 
                ast_symref_init((yylsp[-1]), context_declare_variable(current_context, (yyvsp[-1].sym)))
            );
        }
        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 4727 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 181 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4737 "src/bison/grammar.c"
    break;

  case 12: /* var_declaration: type id '=' error  */
#line 186 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4748 "src/bison/grammar.c"
    break;

  case 13: /* var_declaration: id id '=' error  */
#line 192 "src/bison/grammar.y"
                      {
        show_error_range((yylsp[-3]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-3].sym)->name);
        symbol_free((yyvsp[-3].sym));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4759 "src/bison/grammar.c"
    break;

  case 14: /* var_declaration: id id ';'  */
#line 198 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-2]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-2].sym)->name);
        symbol_free((yyvsp[-2].sym));
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 4770 "src/bison/grammar.c"
    break;

  case 15: /* var_declaration: type error  */
#line 204 "src/bison/grammar.y"
                 {
        show_error_range((yylsp[-1]), "expected identifier after " BGRN "'%s'" RESET "\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4780 "src/bison/grammar.c"
    break;

  case 16: /* var_declaration: type error ';'  */
#line 209 "src/bison/grammar.y"
                     {
        show_error_range((yylsp[-2]), "expected expression before " WHT "';'" RESET "\n");
        free((yyvsp[-2].pchar));
        (yyval.ast) = NULL;
    }
#line 4790 "src/bison/grammar.c"
    break;

  case 17: /* @1: %empty  */
#line 216 "src/bison/grammar.y"
                                   {
        p_ctx_name = true;
        Symbol *sym = context_has_symbol(current_context, (yyvsp[-1].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-2].pchar));

        // always push a context for the function even if not valid so is possible to pop later
        previous_context = current_context;
        list_push(&contexts, context_init((yyvsp[-1].sym)->name));
        current_context = list_peek_last(&contexts);

        if (sym) {
            if (!sym->kind == FUNC) {
                show_error((yylsp[-1]), BCYN "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
            } else if (sym->type != decl_type) {
                show_error((yylsp[-2]), "conflicting types for " BBLU "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            } else {
                show_error((yylsp[-1]), "redefinition of " BBLU "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            }
            (yyval.ast) = NULL;
        } else {
            symbol_update_type((yyvsp[-1].sym), decl_type);
            (yyvsp[-1].sym)->kind = FUNC;
            Symbol *declared = context_declare_variable(previous_context, (yyvsp[-1].sym));
            if (!declared) {
                show_error((yylsp[-1]), BCYN "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
                (yyval.ast) = NULL;
            } else {
                (yyval.ast) = ast_symref_init((yylsp[-1]), declared);
            }
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
        (yyvsp[-2].pchar) = NULL;
        (yyvsp[-1].sym) = NULL;
    }
#line 4834 "src/bison/grammar.c"
    break;

  case 18: /* $@2: %empty  */
#line 254 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4840 "src/bison/grammar.c"
    break;

  case 19: /* func_declaration: type id '(' @1 param_list.opt $@2 ')' compound_stmt  */
#line 254 "src/bison/grammar.y"
                                                              {
        (yyval.ast) = ast_userfunc_init((yyloc), current_context, (yyvsp[-4].ast), ast_params_init((yylsp[-3]), (yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4850 "src/bison/grammar.c"
    break;

  case 20: /* $@3: %empty  */
#line 259 "src/bison/grammar.y"
               {
        previous_context = current_context;
        list_push(&contexts, context_init("unnamed-func"));
        current_context = list_peek_last(&contexts);
        context_push_scope(current_context);
    }
#line 4861 "src/bison/grammar.c"
    break;

  case 21: /* $@4: %empty  */
#line 264 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4867 "src/bison/grammar.c"
    break;

  case 22: /* func_declaration: type '(' $@3 param_list.opt $@4 ')' compound_stmt  */
#line 264 "src/bison/grammar.y"
                                                              {
        show_error_range((yylsp[-5]), "expected identifier before " WHT "'('" RESET "\n");
        free((yyvsp[-6].pchar));
        LIST_FREE((yyvsp[-3].list), { ast_free(__IT__->data); });
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
        current_context = previous_context;
    }
#line 4880 "src/bison/grammar.c"
    break;

  case 23: /* param_list.opt: %empty  */
#line 274 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4886 "src/bison/grammar.c"
    break;

  case 25: /* params_list: params_list ',' param_decl  */
#line 278 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4892 "src/bison/grammar.c"
    break;

  case 26: /* params_list: param_decl  */
#line 279 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4898 "src/bison/grammar.c"
    break;

  case 27: /* params_list: error  */
#line 280 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4907 "src/bison/grammar.c"
    break;

  case 28: /* param_decl: type id  */
#line 286 "src/bison/grammar.y"
                    {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        if (sym) {
            show_error_range((yylsp[0]), "redefinition of parameter " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            symbol_update_type((yyvsp[0].sym), symbol_type_from_str((yyvsp[-1].pchar)));
            symbol_update_temp((yyvsp[0].sym), current_context->t9n->param++);
            (yyvsp[0].sym)->kind = PARAM;
            (yyval.ast) = ast_symref_init((yyloc), context_declare_variable(current_context, (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 4926 "src/bison/grammar.c"
    break;

  case 29: /* param_decl: type  */
#line 300 "src/bison/grammar.y"
           {
        show_error_range((yylsp[0]), "expected identifier after " BGRN "'%s'" RESET "\n", (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
        (yyval.ast) = NULL;
    }
#line 4936 "src/bison/grammar.c"
    break;

  case 30: /* param_decl: id  */
#line 305 "src/bison/grammar.y"
         {
        show_error_range((yylsp[0]), "unknown type name for " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
        symbol_free((yyvsp[0].sym));
        (yyval.ast) = NULL;
    }
#line 4946 "src/bison/grammar.c"
    break;

  case 31: /* $@5: %empty  */
#line 312 "src/bison/grammar.y"
                   {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        if (!is_fn_blck) {
            context_push_scope(current_context);
        } else {
            Scope *fn_scope = list_peek_reverse(&current_context->scopes, 1);
            scope_fill(
                fn_scope,
                context_found_scope(previous_context, fn_scope->last_parent)
            );
        }
        is_fn_blck = false;
    }
#line 4964 "src/bison/grammar.c"
    break;

  case 32: /* compound_stmt: '{' $@5 block_item_list.opt '}'  */
#line 324 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyloc), (yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 4976 "src/bison/grammar.c"
    break;

  case 33: /* block_item_list.opt: block_item_list  */
#line 333 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4982 "src/bison/grammar.c"
    break;

  case 34: /* block_item_list.opt: %empty  */
#line 334 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4988 "src/bison/grammar.c"
    break;

  case 35: /* block_item_list: block_item_list block_item  */
#line 337 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4994 "src/bison/grammar.c"
    break;

  case 36: /* block_item_list: block_item  */
#line 338 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5000 "src/bison/grammar.c"
    break;

  case 46: /* io_stmt: READ '(' id ')' ';'  */
#line 354 "src/bison/grammar.y"
                             {
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].sym));
        if (!param) {
            show_error_range((yylsp[-2]), BCYN "'%s'" RESET " undeclared (first use in this function)\n", (yyvsp[-2].sym)->name);
            (yyval.ast) = NULL;
        } else {
            (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), ast_symref_init((yylsp[-2]), param));
        }
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
    }
#line 5016 "src/bison/grammar.c"
    break;

  case 47: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 365 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 5025 "src/bison/grammar.c"
    break;

  case 48: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 369 "src/bison/grammar.y"
                                       {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 5034 "src/bison/grammar.c"
    break;

  case 49: /* io_stmt: WRITE '(' error ')' ';'  */
#line 373 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 5044 "src/bison/grammar.c"
    break;

  case 50: /* io_stmt: READ '(' error ')' ';'  */
#line 378 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected identifier before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 5054 "src/bison/grammar.c"
    break;

  case 51: /* io_stmt: READ '(' id ')' error  */
#line 383 "src/bison/grammar.y"
                            {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 5065 "src/bison/grammar.c"
    break;

  case 52: /* io_stmt: WRITE '(' expression ')' error  */
#line 389 "src/bison/grammar.y"
                                     {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5076 "src/bison/grammar.c"
    break;

  case 53: /* io_stmt: WRITE '(' string_literal ')' error  */
#line 395 "src/bison/grammar.y"
                                         {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5087 "src/bison/grammar.c"
    break;

  case 54: /* io_stmt: WRITE error  */
#line 401 "src/bison/grammar.y"
                  {
        show_error_range((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 5097 "src/bison/grammar.c"
    break;

  case 55: /* io_stmt: READ error  */
#line 406 "src/bison/grammar.y"
                 {
        show_error_range((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 5107 "src/bison/grammar.c"
    break;

  case 56: /* expr_stmt: expression ';'  */
#line 413 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 5113 "src/bison/grammar.c"
    break;

  case 57: /* expr_stmt: error ';'  */
#line 414 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5122 "src/bison/grammar.c"
    break;

  case 58: /* expr_stmt: error '}'  */
#line 418 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'}'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5131 "src/bison/grammar.c"
    break;

  case 59: /* expr_stmt: error FOR  */
#line 422 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'for'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5140 "src/bison/grammar.c"
    break;

  case 60: /* expr_stmt: error IF  */
#line 426 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'if'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5149 "src/bison/grammar.c"
    break;

  case 61: /* expr_stmt: error RETURN  */
#line 430 "src/bison/grammar.y"
                   {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'return'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5158 "src/bison/grammar.c"
    break;

  case 62: /* cond_stmt: IF '(' expression ')' statement  */
#line 436 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 5166 "src/bison/grammar.c"
    break;

  case 63: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 439 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 5174 "src/bison/grammar.c"
    break;

  case 64: /* cond_stmt: IF '(' expression ')' ELSE statement  */
#line 442 "src/bison/grammar.y"
                                           {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-3].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5185 "src/bison/grammar.c"
    break;

  case 65: /* cond_stmt: IF '(' error ')' statement  */
#line 448 "src/bison/grammar.y"
                                            {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5195 "src/bison/grammar.c"
    break;

  case 66: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 453 "src/bison/grammar.y"
                                                {
        show_error_range((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5206 "src/bison/grammar.c"
    break;

  case 67: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 459 "src/bison/grammar.y"
                                      {
        show_error_range((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5216 "src/bison/grammar.c"
    break;

  case 68: /* cond_stmt: IF error  */
#line 464 "src/bison/grammar.y"
               {
        show_error((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5225 "src/bison/grammar.c"
    break;

  case 69: /* else_error: ELSE statement  */
#line 470 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5235 "src/bison/grammar.c"
    break;

  case 70: /* else_error: error ELSE statement  */
#line 475 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5245 "src/bison/grammar.c"
    break;

  case 71: /* jmp_stmt: RETURN expression ';'  */
#line 482 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyloc), (yyvsp[-1].ast)); }
#line 5251 "src/bison/grammar.c"
    break;

  case 72: /* jmp_stmt: RETURN error ';'  */
#line 483 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5260 "src/bison/grammar.c"
    break;

  case 73: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 489 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init((yyloc), current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 5268 "src/bison/grammar.c"
    break;

  case 74: /* iter_stmt: FOR '(' error ';' expression.opt ';' expression.opt ')' statement  */
#line 492 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-6]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5280 "src/bison/grammar.c"
    break;

  case 75: /* iter_stmt: FOR '(' expression.opt ';' error ';' expression.opt ')' statement  */
#line 499 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-4]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5292 "src/bison/grammar.c"
    break;

  case 76: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' error ')' statement  */
#line 506 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5304 "src/bison/grammar.c"
    break;

  case 77: /* iter_stmt: FOR '(' error ')'  */
#line 513 "src/bison/grammar.y"
                        {
        show_error((yylsp[0]), "expected " WHT "';'" RESET " before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5313 "src/bison/grammar.c"
    break;

  case 78: /* iter_stmt: FOR error  */
#line 517 "src/bison/grammar.y"
                {
        show_error((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5322 "src/bison/grammar.c"
    break;

  case 79: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ')' statement  */
#line 521 "src/bison/grammar.y"
                                                              {
        show_error((yylsp[-1]), "expected expression before " WHT "')'" RESET "token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5334 "src/bison/grammar.c"
    break;

  case 80: /* iter_stmt: FOR '(' error ';' expression.opt ')' statement  */
#line 528 "src/bison/grammar.y"
                                                     {
        show_error((yylsp[-1]), "expected expression before " WHT "')'" RESET "token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5345 "src/bison/grammar.c"
    break;

  case 81: /* iter_stmt: FOR '(' expression.opt ';' error ')' statement  */
#line 534 "src/bison/grammar.y"
                                                     {
        show_error((yylsp[-1]), "expected expression before " WHT "')'" RESET "token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5356 "src/bison/grammar.c"
    break;

  case 83: /* expression: id '=' logical_or_expr  */
#line 543 "src/bison/grammar.y"
                             {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-2].sym));
        if (!sym) {
            show_error_range((yylsp[-2]), BCYN "'%s'" RESET " undeclared (first use in this function)\n", (yyvsp[-2].sym)->name);
            (yyval.ast) = NULL;
            ast_free((yyvsp[0].ast));
        } else {
            (yyval.ast) = ast_assign_init((yyloc), ast_symref_init((yylsp[-2]), sym), (yyvsp[0].ast));
        }
        symbol_free((yyvsp[-2].sym));
    }
#line 5372 "src/bison/grammar.c"
    break;

  case 84: /* expression: id '=' error  */
#line 554 "src/bison/grammar.y"
                   {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 5382 "src/bison/grammar.c"
    break;

  case 85: /* expression: error '=' logical_or_expr  */
#line 559 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-2]), "expected identifier before " WHT "'='" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5392 "src/bison/grammar.c"
    break;

  case 86: /* expression.opt: %empty  */
#line 566 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 5398 "src/bison/grammar.c"
    break;

  case 89: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 571 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5407 "src/bison/grammar.c"
    break;

  case 90: /* logical_or_expr: logical_or_expr OR error  */
#line 575 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5417 "src/bison/grammar.c"
    break;

  case 91: /* logical_or_expr: error OR logical_and_expr  */
#line 580 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5427 "src/bison/grammar.c"
    break;

  case 93: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 588 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5436 "src/bison/grammar.c"
    break;

  case 94: /* logical_and_expr: logical_and_expr AND error  */
#line 592 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5446 "src/bison/grammar.c"
    break;

  case 95: /* logical_and_expr: error AND eq_expr  */
#line 597 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5456 "src/bison/grammar.c"
    break;

  case 97: /* eq_expr: eq_expr EQ rel_expr  */
#line 605 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5465 "src/bison/grammar.c"
    break;

  case 98: /* eq_expr: eq_expr EQ error  */
#line 609 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5475 "src/bison/grammar.c"
    break;

  case 99: /* eq_expr: error EQ rel_expr  */
#line 614 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5485 "src/bison/grammar.c"
    break;

  case 101: /* rel_expr: rel_expr REL list_expr  */
#line 622 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5494 "src/bison/grammar.c"
    break;

  case 102: /* rel_expr: rel_expr REL error  */
#line 626 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5504 "src/bison/grammar.c"
    break;

  case 103: /* rel_expr: error REL list_expr  */
#line 631 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5514 "src/bison/grammar.c"
    break;

  case 105: /* list_expr: add_expr DL_DG list_expr  */
#line 639 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5523 "src/bison/grammar.c"
    break;

  case 106: /* list_expr: add_expr COLON list_expr  */
#line 643 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5532 "src/bison/grammar.c"
    break;

  case 107: /* list_expr: add_expr DL_DG error  */
#line 647 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5542 "src/bison/grammar.c"
    break;

  case 108: /* list_expr: add_expr COLON error  */
#line 652 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5552 "src/bison/grammar.c"
    break;

  case 109: /* list_expr: error DL_DG list_expr  */
#line 657 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5562 "src/bison/grammar.c"
    break;

  case 110: /* list_expr: error COLON list_expr  */
#line 662 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5572 "src/bison/grammar.c"
    break;

  case 112: /* add_expr: add_expr ADD mult_expr  */
#line 670 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5581 "src/bison/grammar.c"
    break;

  case 113: /* add_expr: add_expr ADD error  */
#line 674 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5591 "src/bison/grammar.c"
    break;

  case 114: /* add_expr: error ADD mult_expr  */
#line 679 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5601 "src/bison/grammar.c"
    break;

  case 116: /* mult_expr: mult_expr MULT unary_expr  */
#line 687 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5610 "src/bison/grammar.c"
    break;

  case 117: /* mult_expr: mult_expr MULT error  */
#line 691 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5620 "src/bison/grammar.c"
    break;

  case 118: /* mult_expr: error MULT unary_expr  */
#line 696 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5630 "src/bison/grammar.c"
    break;

  case 120: /* unary_expr: unary_ops unary_expr  */
#line 704 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5639 "src/bison/grammar.c"
    break;

  case 126: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 717 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-3].sym));
        AST *params = ast_params_init((yylsp[-1]), (yyvsp[-1].list));
        if (!sym) {
            show_error_range((yylsp[-3]), "implicit declaration of function " BBLU "'%s'\n" RESET, (yyvsp[-3].sym)->name);
            (yyval.ast) = NULL;
            ast_free(params);
        } else {
            if (!sym->kind == FUNC) {
                show_error_range((yylsp[-3]), "called object " BCYN "'%s'" RESET " is not a function\n", sym->name);
                (yyval.ast) = NULL;
                ast_free(params);
            } else {
                (yyval.ast) = ast_funcall_init((yyloc), ast_symref_init((yylsp[-3]), sym), params);
            }
        }
        symbol_free((yyvsp[-3].sym));
    }
#line 5662 "src/bison/grammar.c"
    break;

  case 127: /* arg_expr_list: arg_expr_list ',' expression  */
#line 737 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5668 "src/bison/grammar.c"
    break;

  case 128: /* arg_expr_list: expression  */
#line 738 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5674 "src/bison/grammar.c"
    break;

  case 129: /* arg_expr_list: error  */
#line 739 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5683 "src/bison/grammar.c"
    break;

  case 131: /* arg_expr_list.opt: %empty  */
#line 746 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5689 "src/bison/grammar.c"
    break;

  case 132: /* primary_expr: id  */
#line 749 "src/bison/grammar.y"
                 {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[0].sym));
        if (!sym) {
            show_error_range((yylsp[0]), BCYN "'%s'" RESET " undeclared (first use in this function)\n", (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            (yyval.ast) = ast_symref_init((yyloc), sym);
        }
        symbol_free((yyvsp[0].sym));
    }
#line 5704 "src/bison/grammar.c"
    break;

  case 134: /* primary_expr: '(' expression ')'  */
#line 760 "src/bison/grammar.y"
                         {
        if ((yyvsp[-1].ast)) {
            --(yyvsp[-1].ast)->rule_pos.first_column;
            ++(yyvsp[-1].ast)->rule_pos.last_column;
        }
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 5716 "src/bison/grammar.c"
    break;

  case 135: /* primary_expr: '(' error ')'  */
#line 767 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5725 "src/bison/grammar.c"
    break;

  case 136: /* primary_expr: id error  */
#line 771 "src/bison/grammar.y"
               {
        show_error_range((yylsp[0]), "expected " WHT "';'" RESET "\n");
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 5735 "src/bison/grammar.c"
    break;

  case 140: /* type: INT LIST  */
#line 783 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5747 "src/bison/grammar.c"
    break;

  case 141: /* type: FLOAT LIST  */
#line 790 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5759 "src/bison/grammar.c"
    break;

  case 142: /* constant: NUMBER_REAL  */
#line 799 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init((yyloc), K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5765 "src/bison/grammar.c"
    break;

  case 143: /* constant: NUMBER_INT  */
#line 800 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init((yyloc), K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5771 "src/bison/grammar.c"
    break;

  case 144: /* constant: NIL  */
#line 801 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init((yyloc), K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5777 "src/bison/grammar.c"
    break;

  case 145: /* string_literal: STR_LITERAL  */
#line 804 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyloc), (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5786 "src/bison/grammar.c"
    break;


#line 5790 "src/bison/grammar.c"

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

#line 810 "src/bison/grammar.y"


void yyerror(int l, int c, const char *s, ...) {
    error_cursor = (Cursor){.line=l, .col=c};
    last_line_ref = curr_line_buffer;
    // enable error print when bison calls yyerror()
    /* if (s) {
        CIPL_PRINTF_COLOR(BRED, "%s\n" BYEL "%s:%d:%d: at line: %s" RESET "\n",
                          s, filename, cursor.line, cursor.col, last_line_ref);
    } */
    
    // prevent count up errors when bison calls yyerror()
    if (!s) {
        ++errors_count;
    }
}
