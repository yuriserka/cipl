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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9598

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  632

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
     157,   179,   184,   190,   196,   204,   239,   204,   244,   249,
     244,   259,   260,   263,   264,   265,   271,   283,   288,   295,
     295,   316,   317,   320,   321,   324,   325,   326,   329,   330,
     331,   332,   333,   334,   337,   348,   352,   356,   361,   366,
     372,   378,   386,   387,   393,   396,   399,   405,   410,   416,
     423,   428,   434,   435,   441,   444,   451,   458,   467,   468,
     469,   474,   481,   482,   485,   486,   490,   495,   502,   503,
     507,   512,   519,   520,   524,   529,   536,   537,   541,   546,
     553,   554,   558,   562,   567,   572,   577,   584,   585,   589,
     594,   601,   602,   606,   611,   618,   619,   625,   626,   627,
     628,   631,   632,   652,   653,   654,   660,   661,   664,   674,
     675,   682,   686,   693,   696,   697,   698,   705,   714,   715,
     716,   719
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

#define YYPACT_NINF (-391)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-132)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    5476,  2434,  2541,  8991,  9004,  2790,  2846,  3854,  7856,  7873,
     166,   236,   -12,    -8,    42,    49,  3170,  4230,    90,    31,
    5508,  5540,  5572,  5604,  5636,  5668,  5700,  5732,  5764,  5796,
    5828,    10,    60,   209,   388,   793,  1268,  1869,  3012,  9015,
    7890,  9028,  9039,  2963,   123,  9052,  7907,  4236,  4342,  6948,
    6954,  6972,  4342,  4342,  5860,  6989,   154,   174,     8,  1060,
    7006,  2981,  9063,    61,   605,   567,    65,   473,  -391,  9076,
    5892,  5924,  7023,  7040,  7057,  7074,  7091,  7108,  7125,  7142,
    7159,  9087,  9100,   389,   257,  5956,     5,   355,  3631,   142,
    9303,  9316,   673,  1515,   755,   491,  2916,   215,  1169,  1573,
    1610,  1679,  2177,   119,   141,   156,  1716,   158,   178,   211,
    2460,   230,  9111,   157,   237,  5988,  6020,  9124,  9135,  2169,
    3985,   508,   239,   822,   857,   909,   955,    82,  9326,   632,
    9339,   642,  9349,  1690,  9362,  1703,  9372,  9385,  9395,  1911,
    9408,  1945,  9418,  9431,  9441,   173,  2065,   108,   279,   248,
    6052,   288,     9,  6084,   314,    50,   280,    11,   318,    21,
      29,  1013,  2875,  3029,  3241,  3985,  1091,  6116,  1198,   293,
    7176,  9148,  6148,   379,   319,   382,   390,   394,    95,  6180,
       9,  6212,  6244,  6276,  6308,  6340,  6372,  6404,  6436,  6884,
    1235,  6884,  1267,  9268,   329,  9159,   343,  1385,   421,   364,
     278,   489,   370,  6468,  6884,  6500,  6884,   643,   643,  1299,
     341,   556,   375,  6532,  6564,   387,   400,  8432,   406,  6596,
     341,  6884,  6884,  6884,  6884,  6628,  6660,  6692,  6724,  6756,
    3153,  8445,  8458,  8471,   537,  7193,    -6,    76,   204,   317,
     359,   722,   240,  8484,  7924,  8497,  8510,   715,  8523,   579,
     488,  9454,  9464,  9477,   889,  7210,  7907,  9487,  9500,  3201,
    9510,   410,  7941,  7227,  7244,  7261,  7278,  7295,  7244,  7244,
    7312,   145,   250,   435,   442,   451,   456,  7329,    90,  1465,
    1572,  1609,  1644,  1757,  1837,   462,  2963,  3318,  3389,  3480,
      35,  7346,   167,   249,   686,   419,   554,  3763,  3084,  7986,
    7958,  8000,  8013,   323,  8027,  1944,  9172,  1981,  7975,  7363,
    7380,  7397,  7414,  7431,  7380,  7380,  7448,   678,   144,   161,
    9183,   463,   479,   495,   498,  7465,    90,  2017,  2209,  2316,
    2353,  2388,  2581,   476,  2129,   551,  9279,  9292,   525,  8536,
     530,  7482,  7499,  7516,  7533,  7550,  7567,  7584,  7601,  7618,
    8549,  8562,   389,  8575,   550,  9523,  9533,   389,   448,  1355,
    1727,  1344,  7635,  2099,  7941,  2471,  2832,  1673,  8744,   577,
    8757,  8770,   707,   474,  2280,   941,  3444,   328,  2262,   561,
     895,   956,  2549,   111,    94,   113,   263,  1434,  7652,  3307,
    9196,   562,   473,  2501,   744,  8588,   572,  7669,  7686,  7703,
    7720,  7737,  7754,  7771,  7788,  7805,  8040,  8054,   389,  3698,
    8108,  8121,   125,  7822,  8135,  7975,  8148,  8162,   436,  8175,
     617,  8189,  8202,  1440,   739,  2288,  1048,  3454,   308,  2634,
     990,  1125,  1300,  9579,   281,   112,   114,  2688,   298,  1806,
    7839,  3739,  9207,   602,   473,  2725,  2759,  8601,  8614,  8783,
     332,  8796,  1014,  8809,   983,  8822,  1141,  8835,  8848,  8861,
    1199,  8874,  1386,  8887,  8900,  8913,   207,   608,  9546,  9556,
     613,  8627,   618,  8926,  8939,   389,   624,   634,  8640,   636,
     641,  8653,   644,  9220,   649,  3049,  3104,   648,  3543,   684,
    8067,  8081,  8216,   526,  8229,  1216,  8243,  1308,  8256,  1316,
    8270,  8283,  8297,  1499,  8310,  1539,  8324,  8337,  8351,   334,
     671,  8666,   685,  8364,  8378,   389,   705,   711,  8679,   720,
     724,  8692,   728,  9231,   710,  3580,  3646,   735,  8705,  9569,
    8952,  8965,   751,   757,    33,   769,    34,    52,  4088,  6788,
    3029,  3940,  3894,  4123,  8094,  8391,  8405,   774,   778,    56,
     780,    73,    74,  6820,  6852,  3029,  4024,  4163,  8978,  4195,
    4272,  4307,  4371,  4406,  4441,  4476,  4511,  3985,  4546,  3985,
    4581,   782,  9244,   800,  8418,  4617,  4649,  4681,  4713,  4745,
    4777,  4809,  4841,  6916,  4873,  6916,  4905,   802,  9255,   807,
    4937,  3985,  4972,  3985,   643,   643,  2054,  5008,  6916,  5040,
    6916,   643,   643,  2420,  5072,  5107,   808,   811,  8718,   818,
    5143,  5175,   819,   820,  8731,   823,  3985,  3985,  3985,  3985,
    6916,  6916,  6916,  6916,  5207,  5242,  5277,  5312,  5348,  5380,
    5412,  5444
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
       0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -391,  -391,  -391,   834,    18,  -391,  -391,  -391,  -391,  -391,
     679,  -391,   666,     7,  -274,  -390,  -391,   746,    72,    79,
      84,   155,  -391,   159,   212,     0,  -131,  3768,  3669,  3467,
    3448,  2879,  3098,  3030,  1115,  1487,  1859,  -391,  -344,  2231,
     741,     1,  2603,  -384
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   121,    23,   180,   212,   152,   199,
     174,   175,   176,   279,    67,   122,   123,   124,   125,   280,
     281,   282,   126,   283,   284,   285,   114,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   148,   149,    42,
      64,   127,    45,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    44,   487,   480,   392,   341,   -18,    24,   467,   104,
     173,   -18,   182,   470,   261,   317,    63,    66,    22,    58,
      31,    44,   185,    59,   -18,   -18,   -68,    24,   318,   319,
     187,    68,   194,   196,   560,   563,  -123,   -18,    22,    71,
     183,   -21,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
     186,   -15,   444,   565,   527,   520,   -15,   576,   188,   108,
     111,   113,   561,   564,   510,  -123,  -123,  -123,  -123,   -15,
     -15,    72,    25,    60,   579,   581,   215,   216,   218,    26,
      61,   566,   -15,   147,    27,   577,   342,   -74,   249,   -68,
     116,   -29,    25,   -29,   -29,   -29,   -29,   118,   -29,    26,
    -126,   317,   580,   582,    27,   -29,   -29,   -29,   -74,   -29,
     -29,   307,   -29,   -29,   -29,   -29,   -29,   -29,  -126,  -127,
    -127,   -29,   341,  -126,   -29,   -29,  -123,   -27,   -27,   250,
      72,   532,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -114,  -114,  -127,   -71,  -126,  -126,  -127,  -127,   -71,    46,
    -124,  -124,    85,   178,    86,    28,  -123,  -123,  -123,    29,
    -126,   333,   333,   113,   113,   435,   384,  -125,   327,   327,
     198,   547,  -124,   156,  -124,    28,  -124,  -124,   397,    29,
    -127,   178,   436,  -126,    72,  -126,   -73,    56,   157,    31,
    -131,    31,   166,  -125,  -125,  -124,    24,  -124,    24,   -68,
     -68,   178,   -69,  -127,    31,  -127,    31,   338,   338,   338,
     159,    24,    30,    24,   -78,   -78,   343,   219,   341,    73,
     -74,    31,    31,    31,    31,    73,   -77,   225,    24,    24,
      24,    24,    30,   190,   192,   340,   -78,   197,   -74,   -69,
     328,   328,  -125,   160,   -77,   329,   329,   348,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   354,  -125,    57,   484,   398,
     -74,   203,   162,   205,   476,  -125,   164,  -125,    26,   261,
      26,   385,   -97,    27,   167,    27,   213,   391,   214,  -125,
     171,   -74,   -74,    26,   317,    26,   150,   151,    27,   172,
      27,   396,   397,   226,   227,   228,   229,   318,   319,   516,
      26,    26,    26,    26,   261,    27,    27,    27,    27,   181,
     524,  -116,   170,   -71,   -71,   179,   330,   330,   398,   -77,
     331,   331,   334,   335,   407,   443,   344,   -82,   -82,   -82,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,   342,   -77,
     -77,   -77,   342,   -75,    28,   397,    28,   184,    29,   -82,
      29,   -19,   147,  -118,   408,  -118,  -118,   147,   207,    28,
     -77,    28,   472,    29,   -75,    29,   -69,   -69,   -86,   -86,
     -86,   -86,   209,   332,   332,    18,    28,    28,    28,    28,
      29,    29,    29,    29,   153,   154,   155,   479,   482,   113,
     146,   -86,   287,   288,   289,   290,   210,     6,   -78,   -78,
      74,    30,   -16,    30,     7,     8,     9,   220,   147,   571,
     573,   -25,   -25,   512,   -22,   200,    30,   -78,    30,   221,
     291,  -117,   -24,   -24,   587,   589,   -28,   -28,   400,   -82,
     -82,   -82,   222,    30,    30,    30,    30,   514,   224,   519,
     522,   113,  -123,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,   -82,   -82,  -113,  -113,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,   606,   607,   609,   386,   515,  -118,  -118,
     612,   613,   615,   387,   119,   147,     2,     3,     4,     5,
    -129,     6,   388,   -89,   -89,   -89,   -89,   389,     7,     8,
       9,   393,   271,   272,   438,   273,   274,   275,   120,   276,
     277,   -81,   -81,    74,    17,   445,   -89,   278,   -32,   -35,
     439,   -35,   -35,   -35,   -35,   147,   -35,  -123,  -123,  -123,
     -81,   -26,   -26,   -35,   -35,   -35,   440,   -35,   -35,   441,
     -35,   -35,   -35,   -35,   -35,   -35,   398,   -75,  -123,   -35,
     113,   113,   -35,   -35,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,   446,   333,   333,   113,   113,   -73,   -75,   -75,
     327,   327,   448,   -86,   -86,   -86,   -86,  -123,  -123,  -123,
     344,   -85,   -85,   -85,   262,   263,   264,   265,   266,   267,
     268,   269,   469,   333,   262,   333,   -86,   -86,   -23,   -23,
     327,   486,   327,   -85,   338,   338,   338,   270,   333,   117,
     333,   338,   338,   338,   491,   327,    82,   327,  -123,  -123,
     568,   570,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
     333,   333,   333,   333,   308,   584,   586,   327,   327,   327,
     327,   526,   328,   328,  -118,  -118,    83,   329,   329,   590,
     528,   592,    73,   -75,   337,   529,   231,   232,   233,   234,
     531,     6,   -79,   -79,    74,   597,   533,   599,     7,     8,
       9,   -75,   328,   604,   328,   605,   534,   329,   536,   329,
     610,   -79,   611,   537,   235,   -72,   539,   328,   541,   328,
      46,    47,   329,   542,   329,   543,    52,    53,   624,   625,
     626,   627,   628,   629,   630,   631,   -78,   -78,   399,   328,
     328,   328,   328,   544,   329,   329,   329,   329,   330,   330,
    -123,  -123,   331,   331,   262,   263,   351,   546,   -78,   -78,
     268,   269,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
     345,   -90,   -90,   -90,   -90,   346,   347,   548,   330,   556,
     330,    43,   331,   549,   331,  -118,   352,  -118,   -89,   -89,
     -89,   -89,   551,   330,   -90,   330,   552,   331,   247,   331,
     554,    43,    46,    47,    48,   332,   332,    51,    52,    53,
     557,   -89,   -89,   488,   489,   330,   330,   330,   330,   331,
     331,   331,   331,   558,    84,    87,   559,   259,   259,   259,
     259,   259,   259,   259,   259,   332,   259,   332,   562,   105,
     247,   247,    75,   -82,   -82,   -82,   574,   575,   286,   578,
     332,   594,   332,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   -82,   119,   303,     2,     3,     4,     5,   596,
       6,   601,   332,   332,   332,   332,   603,     7,     8,     9,
     616,   271,   272,   617,   273,   274,   275,   120,   276,   277,
     619,   620,   621,    17,    70,   623,   278,   -31,   -34,   202,
     -34,   -34,   -34,   -34,   286,   -34,   211,     0,   169,   168,
       0,     0,   -34,   -34,   -34,     0,   -34,   -34,     0,   -34,
     -34,   -34,   -34,   -34,   -34,     0,     0,     0,   -34,     0,
    -123,   -34,   -34,   177,     0,     0,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,   -96,   -96,   -96,   -96,     0,     0,
     -36,   303,   -36,   -36,   -36,   -36,     0,   -36,  -123,   201,
    -123,   177,     0,     0,   -36,   -36,   -36,   -96,   -36,   -36,
       0,   -36,   -36,   -36,   -36,   -36,   -36,     0,     0,     0,
     -36,   177,     0,   -36,   -36,     0,     0,     0,   247,   247,
     247,   -81,   -81,   343,     0,     0,   -37,     0,   -37,   -37,
     -37,   -37,     0,   -37,     0,   -95,   -95,   -95,   -95,     0,
     -37,   -37,   -37,   -81,   -37,   -37,   247,   -37,   -37,   -37,
     -37,   -37,   -37,     0,     0,   247,   -37,     0,   -95,   -37,
     -37,     0,   344,   -83,   -83,   -83,   247,   259,     0,   400,
     -85,   -85,   -85,   367,   367,   367,   367,   367,   367,   367,
     367,   367,     0,     0,   320,   -83,     2,     3,     4,   230,
       0,     6,   -85,   -85,   -79,   -79,   343,   394,     7,     8,
       9,     0,   247,     0,     0,   321,   322,   323,   189,   324,
     325,   303,     0,     0,    17,     0,   -79,   326,     0,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   -81,   -81,
     399,   106,     0,   231,   232,   233,   234,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,   107,     0,
     -81,   -81,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   235,   -60,   303,   -60,   -60,   -60,   -60,   303,   -60,
       0,     0,     0,   247,     0,   367,   -60,   -60,   -60,     0,
     -60,   -60,     0,   -60,   -60,   -60,   -60,   -60,   -60,     0,
       0,     0,   -60,     0,     0,   -60,   -60,   477,   247,   247,
       0,     0,   243,   286,   -96,   -96,   -96,   -96,   418,   418,
     418,   418,   418,   418,   418,   418,   418,     0,     0,   303,
     -87,   -87,   -87,   -87,   247,    81,   418,   -96,   -96,     0,
       0,    88,    91,    91,    91,    91,    91,    91,    91,     0,
      91,     0,     0,   -87,   243,   243,    46,    47,    48,   517,
     247,   247,    52,    53,     0,   286,     0,    91,    91,    91,
      91,    91,    91,    91,   143,    91,     0,     0,   299,   -33,
       0,   -33,   -33,   -33,   -33,     0,   -33,     0,   -92,   -92,
     -92,   -92,     0,   -33,   -33,   -33,   303,   -33,   -33,     0,
     -33,   -33,   -33,   -33,   -33,   -33,   -79,   -79,   399,   -33,
       0,   -92,   -33,   -33,     0,   -57,   -57,     0,   -57,   -57,
     -57,   -57,     0,   -57,     0,     0,     0,     0,   -79,   -79,
     -57,   -57,   -57,     0,   -57,   -57,   303,   -57,   -57,   -57,
     204,   -57,   -57,     0,     0,     0,   -57,   -54,   -54,   -57,
     -54,   -54,   -54,   -54,     0,   -54,     0,   -86,   -86,   -86,
     -86,     0,   -54,   -54,   -54,   299,   -54,   -54,     0,   -54,
     -54,   -54,   206,   -54,   -54,     0,     0,   -86,   -54,     0,
     217,   -54,   231,   232,   233,   234,     0,     6,     0,   -95,
     -95,   -95,   -95,     0,     7,     8,     9,   400,   -83,   -83,
     -83,     0,   243,   243,   243,   -87,   -87,   -87,   -87,     0,
     235,   -72,   -95,   -95,     0,   247,   247,   247,     0,     0,
     -83,   -83,   247,   247,   247,  -123,     0,     0,   -87,   -87,
     243,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   350,
       0,     0,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
     243,   355,     0,     0,     0,  -123,  -123,   363,   371,   371,
     371,   371,   371,   371,   371,   371,   -61,  -130,   -61,   -61,
     -61,   -61,     0,   -61,     0,   -91,   -91,   -91,   -91,     0,
     -61,   -61,   -61,     0,   -61,   -61,   243,   -61,   -61,   -61,
     -61,   -61,   -61,     0,     0,   406,   -61,     0,   -91,   -61,
     -61,     0,     0,   414,   422,   422,   422,   422,   422,   422,
     422,   422,     0,     0,     0,   478,     0,   231,   232,   233,
     234,     0,     6,     0,     0,     0,     0,   308,   309,     7,
       8,     9,   107,   314,   315,     0,   371,   371,   371,   371,
     371,   371,   371,   464,   371,   235,   -39,   299,   -39,   -39,
     -39,   -39,   299,   -39,     0,     0,     0,   243,     0,   473,
     -39,   -39,   -39,     0,   -39,   -39,     0,   -39,   -39,   -39,
     -39,   -39,   -39,     0,     0,     0,   -39,     0,     0,   -39,
     -39,     0,   243,   243,   244,     0,     0,     0,   -92,   -92,
     -92,   -92,   422,   422,   422,   422,   422,   422,   422,   507,
     422,     0,     0,   299,   -89,   -89,   -89,   -89,   243,     0,
     513,   -92,   -92,   256,   256,   256,   256,   256,   256,   256,
     256,     0,   256,     0,   -89,     0,   244,   244,   -91,   -91,
     -91,   -91,     0,     0,   243,   243,     0,     0,     0,   256,
     256,   256,   256,   256,   256,   256,   256,   256,     0,     0,
     300,   -91,   -91,   -43,     0,   -43,   -43,   -43,   -43,     0,
     -43,     0,    75,   -85,   -85,   -85,     0,   -43,   -43,   -43,
     299,   -43,   -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,
       0,     0,   -85,   -43,     0,     0,   -43,   -43,     0,     0,
     -38,     0,   -38,   -38,   -38,   -38,     0,   -38,     0,   -96,
     -96,   -96,   -96,     0,   -38,   -38,   -38,     0,   -38,   -38,
     299,   -38,   -38,   -38,   -38,   -38,   -38,     0,     0,   -96,
     -38,     0,     0,   -38,   -38,   -40,     0,   -40,   -40,   -40,
     -40,     0,   -40,     0,     0,     0,     0,   300,     0,   -40,
     -40,   -40,     0,   -40,   -40,     0,   -40,   -40,   -40,   -40,
     -40,   -40,     0,     0,   474,   -40,     0,     0,   -40,   -40,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,   -95,   -95,
     -95,   -95,     0,     0,   244,   244,   244,     0,     0,    75,
     -83,   -83,   -83,     0,   475,  -118,     0,     0,   -95,   243,
     243,   243,   -87,   -87,   -87,   -87,   243,   243,   243,   -83,
       0,     0,   244,   262,   263,   264,   265,   266,   267,   268,
     269,   244,   -87,     0,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,   244,   256,     0,     0,   270,     0,   158,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   -41,  -128,
     -41,   -41,   -41,   -41,     0,   -41,     0,     0,     0,     0,
       0,     0,   -41,   -41,   -41,     0,   -41,   -41,   244,   -41,
     -41,   -41,   -41,   -41,   -41,     0,     0,   300,   -41,     0,
       0,   -41,   -41,     0,     0,   415,   415,   415,   415,   415,
     415,   415,   415,   415,     0,     0,     0,   518,     0,   231,
     232,   233,   234,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,   107,     0,     0,     0,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   235,   -42,   300,
     -42,   -42,   -42,   -42,   300,   -42,     0,     0,     0,   244,
       0,   364,   -42,   -42,   -42,     0,   -42,   -42,     0,   -42,
     -42,   -42,   -42,   -42,   -42,     0,     0,     0,   -42,     0,
       0,   -42,   -42,     0,   244,   244,   245,    76,   -90,   -90,
     -90,   -90,    77,    78,   415,   415,   415,   415,   415,   415,
     415,   415,   415,     0,     0,   300,     0,     0,   -90,     0,
     244,     0,   415,     0,     0,   257,   257,   257,   257,   257,
     257,   257,   257,     0,   257,     0,     0,     0,   245,   245,
     -92,   -92,   -92,   -92,     0,     0,   244,   244,     0,     0,
       0,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     -92,     0,   301,     0,     0,   -53,     0,   -53,   -53,   -53,
     -53,     0,   -53,     0,   -91,   -91,   -91,   -91,     0,   -53,
     -53,   -53,   300,   -53,   -53,     0,   -53,   -53,   -53,   -53,
     -53,   -53,     0,     0,   -91,   -53,     0,     0,   -53,   -53,
       0,     0,   -11,     0,   -11,   -11,   -11,   -11,     0,   -11,
       0,     0,     0,     0,     0,     0,   -11,   -11,   -11,     0,
     -11,   -11,   300,   -11,   -11,   -11,   -11,   -11,   -11,     0,
       0,     0,   -11,     0,     0,   -11,   -11,   -39,   -39,     0,
     -39,   -39,   -39,   -39,     0,   -39,     0,     0,     0,   301,
       0,     0,   -39,   -39,   -39,     0,   -39,   -39,     0,   -39,
     -39,   -39,   -39,   -39,   -39,     0,     0,     0,   -39,     0,
       0,   -39,     0,     0,     0,   608,     0,   231,   232,   233,
     234,     0,     6,     0,     0,     0,   245,   245,   245,     7,
       8,     9,   308,   309,   310,   311,   312,   313,   314,   315,
       0,   244,   244,   244,     0,   235,   -72,     0,   244,   244,
     244,     0,     0,     0,   245,   316,     0,  -115,  -115,     0,
       0,     0,     0,   245,     0,     0,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,   245,   257,     0,     0,     0,     0,
       0,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     -10,  -104,   -10,   -10,   -10,   -10,     0,   -10,     0,     0,
       0,     0,     0,     0,   -10,   -10,   -10,     0,   -10,   -10,
     245,   -10,   -10,   -10,   -10,   -10,   -10,     0,     0,   301,
     -10,     0,     0,   -10,   -10,     0,     0,   416,   416,   416,
     416,   416,   416,   416,   416,   416,    46,    47,    48,    49,
      50,    51,    52,    53,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,   165,     0,     0,     0,   305,    55,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   -43,
     -43,   301,   -43,   -43,   -43,   -43,   301,   -43,     0,     0,
       0,   245,     0,   365,   -43,   -43,   -43,     0,   -43,   -43,
       0,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,     0,
     -43,     0,     0,   -43,     0,     0,   245,   245,   246,     0,
       0,     0,     0,     0,     0,     0,   416,   416,   416,   416,
     416,   416,   416,   416,   416,     0,     0,   301,     0,   262,
     263,   264,   245,     0,   416,   268,   269,   258,   258,   258,
     258,   258,   258,   258,   258,     0,   258,   262,   263,   264,
     246,   246,   267,   268,   269,   308,   309,   310,   245,   245,
     313,   314,   315,   258,   258,   258,   258,   258,   258,   258,
     258,   258,     0,     0,   302,     0,   -38,   -38,     0,   -38,
     -38,   -38,   -38,     0,   -38,     0,     0,     0,     0,     0,
       0,   -38,   -38,   -38,   301,   -38,   -38,     0,   -38,   -38,
     -38,   -38,   -38,   -38,     0,     0,     0,   -38,     0,     0,
     -38,     0,     0,   -40,   -40,     0,   -40,   -40,   -40,   -40,
       0,   -40,     0,     0,     0,     0,     0,     0,   -40,   -40,
     -40,     0,   -40,   -40,   301,   -40,   -40,   -40,   -40,   -40,
     -40,     0,     0,     0,   -40,     0,     0,   -40,   -41,   -41,
       0,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,     0,
       0,   302,     0,   -41,   -41,   -41,     0,   -41,   -41,     0,
     -41,   -41,   -41,   -41,   -41,   -41,     0,     0,     0,   -41,
       0,   614,   -41,   231,   232,   233,   234,     0,     6,     0,
       0,     0,     0,     0,    -4,     7,     8,     9,   246,   246,
     246,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,   235,   -72,   245,   245,   245,     0,     0,     0,     0,
     245,   245,   245,    54,    55,     0,   246,   262,   263,   264,
     265,   266,   267,   268,   269,   246,     0,     0,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,   246,   258,     0,     0,
     270,     0,   161,   366,   366,   366,   366,   366,   366,   366,
     366,   366,   -52,  -105,   -52,   -52,   -52,   -52,     0,   -52,
       0,     0,     0,     0,     0,     0,   -52,   -52,   -52,     0,
     -52,   -52,   246,   -52,   -52,   -52,   -52,   -52,   -52,     0,
       0,   302,   -52,     0,     0,   -52,   -52,     0,     0,   417,
     417,   417,   417,   417,   417,   417,   417,   417,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,   262,   263,   264,   265,
     266,   267,   268,   269,     0,     0,     0,     0,     0,     0,
    -129,  -129,   366,   366,   366,   366,   366,   366,   366,   366,
     366,   -42,   -42,   302,   -42,   -42,   -42,   -42,   302,   -42,
       0,     0,     0,   246,     0,   366,   -42,   -42,   -42,     0,
     -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,     0,
       0,     0,   -42,     0,     0,   -42,     0,     0,   246,   246,
     248,     0,     0,     0,     0,     0,     0,     0,   417,   417,
     417,   417,   417,   417,   417,   417,   417,     0,     0,   302,
       0,   308,   309,   310,   246,     0,   417,   314,   315,   260,
     260,   260,   260,   260,   260,   260,   260,     0,   260,     0,
       0,     0,   248,   248,     0,     0,     0,     0,     0,     0,
     246,   246,     0,     0,     0,   260,   260,   260,   260,   260,
     260,   260,   260,   260,     0,     0,   304,     0,   -53,   -53,
       0,   -53,   -53,   -53,   -53,     0,   -53,     0,     0,     0,
       0,     0,     0,   -53,   -53,   -53,   302,   -53,   -53,     0,
     -53,   -53,   -53,   -53,   -53,   -53,     0,     0,     0,   -53,
       0,     0,   -53,     0,     0,   -52,   -52,     0,   -52,   -52,
     -52,   -52,     0,   -52,     0,     0,     0,     0,     0,     0,
     -52,   -52,   -52,     0,   -52,   -52,   302,   -52,   -52,   -52,
     -52,   -52,   -52,     0,     0,     0,   -52,     0,     0,   -52,
     -12,     0,   -12,   -12,   -12,   -12,     0,   -12,     0,     0,
       0,     0,     0,   304,   -12,   -12,   -12,     0,   -12,   -12,
       0,   -12,   -12,   -12,   -12,   -12,   -12,     0,     0,     0,
     -12,  -123,     0,   -12,   -12,     0,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,     0,     0,     0,     0,     0,
     248,   248,   248,     0,     0,     0,     0,     0,     0,  -123,
    -123,  -123,     0,     0,     0,   246,   246,   246,     0,     0,
       0,     0,   246,   246,   246,     0,     0,     0,   248,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,   248,     0,  -109,
    -109,  -109,  -109,     0,  -109,     0,     0,     0,   248,   260,
       0,  -109,  -109,  -109,  -111,   368,   368,   368,   368,   368,
     368,   368,   368,   368,     0,     0,   320,  -109,     2,     3,
       4,   230,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,   248,     0,   240,   321,   322,   323,
     191,   324,   325,   304,     0,     0,    17,     0,     0,   326,
       0,   419,   419,   419,   419,   419,   419,   419,   419,   419,
       0,     0,     0,    46,    47,    48,    49,    93,    51,    52,
      53,   100,   101,     0,     0,     0,     0,     0,   240,   240,
       0,     0,     0,     0,   368,   368,   368,   368,   368,   368,
     368,   368,   368,     0,   135,   304,   139,   141,     0,     0,
     304,     0,   296,     0,    82,   248,     0,   368,     0,   249,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,     0,     0,
       0,     0,   112,     0,     2,     3,     4,   230,     0,     6,
     248,   248,  -118,  -118,    83,     0,     7,     8,     9,     0,
     419,   419,   419,   419,   419,   419,   419,   419,   419,     0,
     -72,   304,    17,     0,     0,     0,   248,     0,   419,    79,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,     0,     0,     0,
     193,     0,     2,     3,     4,   230,     0,     6,     0,     0,
       0,   -97,   248,   248,     7,     8,     9,   242,     0,   296,
     -63,     0,   -63,   -63,   -63,   -63,     0,   -63,   -72,     0,
      17,     0,     0,     0,   -63,   -63,   -63,     0,   -63,   -63,
       0,   -63,   -63,   -63,   -63,   -63,   -63,    90,   304,     0,
     -63,     0,     0,   -63,   -63,     0,   240,   240,   240,   242,
     242,   404,   -97,   -97,   -97,   -97,   -97,   -97,   -97,     0,
       0,     0,     0,     0,     0,   -62,   137,   -62,   -62,   -62,
     -62,     0,   -62,   298,   240,   241,   -97,   -97,   304,   -62,
     -62,   -62,     0,   -62,   -62,     0,   -62,   -62,   -62,   -62,
     -62,   -62,     0,     0,   240,   -62,     0,     0,   -62,   -62,
       0,     0,     0,   373,   240,   240,   240,   380,   381,   240,
       0,     0,     0,     0,  -123,     0,     0,   241,   241,     0,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,     0,     0,
     240,    62,     0,     2,     3,     4,   230,     0,     6,     0,
       0,   297,  -123,  -123,  -123,     7,     8,     9,     0,   424,
     296,   296,   296,   431,   432,   296,     0,   248,   248,   248,
     298,    17,   356,     0,   248,   248,   248,     0,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,     0,     0,     0,     0,
     240,   240,   240,   456,     0,   460,   462,     0,   240,     0,
    -118,   296,   357,     0,     0,     0,   296,   242,   242,   242,
       0,   240,   195,     0,     2,     3,     4,   230,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,     0,     0,     0,     0,   242,   240,   240,   297,     0,
     -72,     0,    17,     0,     0,     0,   296,   296,   296,   499,
       0,   503,   505,     0,   296,   242,     0,   296,     0,     0,
       0,     0,   240,   370,   242,   242,   242,   242,   242,   242,
     242,     0,     0,     0,     0,   241,   241,   241,   483,     0,
       2,     3,     4,   230,     0,     6,     0,     0,   240,   240,
       0,   242,     7,     8,     9,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,   241,     0,     0,   -72,     0,    17,   421,
     298,   298,   298,   298,   298,   298,   298,     0,  -129,     0,
    -129,  -129,     0,   241,   296,     0,     0,     0,     0,     0,
       0,     0,   241,   241,   241,   241,   241,   241,   241,     0,
       0,   242,   242,   242,   242,   458,   242,   242,     0,   242,
       0,     0,   298,     0,     0,     0,     0,   298,     0,   241,
       0,     0,   242,     0,   296,     0,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,     0,     0,     0,     0,   297,   297,
     297,   297,   297,   297,   297,     0,     0,   242,   242,  -130,
       0,  -130,  -130,     0,     0,     0,     0,   298,   298,   298,
     298,   501,   298,   298,     0,   298,     0,     0,   298,   241,
     241,   241,   241,   242,   241,   241,     0,   241,     0,     0,
     297,   262,   263,   264,   265,   297,   267,   268,   269,     0,
     241,   308,   309,   310,   311,   239,   313,   314,   315,   242,
     242,     0,     0,   240,   240,   240,     0,     0,     0,     0,
     240,   240,   240,     0,   238,   241,   241,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,   297,   297,   297,   297,    99,
     297,   297,     0,   297,     0,   298,   297,   239,   239,     0,
    -128,   241,  -128,  -128,     0,     0,    95,     0,     0,     0,
       0,     0,   133,     0,     0,     0,   238,   238,     0,     0,
       0,   295,     0,     0,     0,     0,     0,   241,   241,     0,
     131,     0,     0,     0,   -14,   298,   -14,   -14,   -14,   -14,
     294,   -14,     0,     0,     0,     0,     0,     0,   -14,   -14,
     -14,     0,   -14,   -14,     0,   -14,   -14,   -14,   -14,   -14,
     -14,     0,     0,   297,   -14,     0,     0,   -14,   -14,     0,
     -63,   -63,     0,   -63,   -63,   -63,   -63,     0,   -63,     0,
       0,     0,     0,     0,     0,   -63,   -63,   -63,     0,   -63,
     -63,     0,   -63,   -63,   -63,   -63,   -63,   -63,     0,     0,
       0,   -63,     0,   297,   -63,     0,     0,     0,   295,     0,
       0,     0,     0,     0,   242,   242,   242,     0,     0,     0,
       0,   242,   242,   242,     0,     0,     0,   294,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,   -62,   -62,     0,   -62,
     -62,   -62,   -62,     0,   -62,   239,   239,   239,     0,     0,
    -104,   -62,   -62,   -62,     0,   -62,   -62,     0,   -62,   -62,
     -62,   -62,   -62,   -62,   238,   238,   238,   -62,     0,     0,
     -62,     0,     0,   239,     0,     0,   237,     0,     0,     0,
       0,     0,   241,   241,   241,     0,     0,     0,     0,   241,
     241,   241,   238,   239,     0,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,   239,   239,   379,     0,     0,   239,    97,
       0,     0,   238,     0,     0,     0,     0,     0,   237,   237,
    -129,  -129,   375,   238,     0,     0,     0,   238,     0,   239,
     523,   129,     2,     3,     4,   230,     0,     6,     0,     0,
       0,     0,   293,     0,     7,     8,     9,     0,   238,   295,
     295,   430,     0,     0,   295,     0,     0,     0,   -72,     0,
      17,   401,   -90,   -90,   -90,   -90,   402,   403,   426,   294,
       0,     0,     0,   294,     0,   236,     0,     0,     0,   239,
     239,   454,     0,     0,     0,   -90,   -90,   239,     0,     0,
     295,     0,     0,     0,     0,   295,     0,     0,   238,   452,
     239,     0,     0,     0,     0,     0,   238,     0,     0,   294,
       0,     0,     0,   103,   294,     0,     0,   236,   236,   238,
       0,     0,     0,     0,     0,   239,   239,     0,     0,   293,
       0,     0,     0,     0,     0,   295,   295,   497,   145,     0,
       0,   292,     0,   295,   238,   238,   295,  -107,  -107,  -107,
    -107,   239,  -107,     0,   294,   495,     0,     0,     0,  -107,
    -107,  -107,   294,     0,     0,   294,   237,   237,   237,     0,
     238,     0,     0,     0,     0,  -107,     0,   239,   239,     0,
       0,     0,     0,     0,     0,   -30,     0,   -30,   -30,   -30,
     -30,     0,   -30,     0,   237,     0,   238,   238,     0,   -30,
     -30,   -30,     0,   -30,   -30,     0,   -30,   -30,   -30,   -30,
     -30,   -30,     0,   295,   237,   -30,     0,     0,   -30,   -30,
       0,     0,     0,     0,     0,   377,     0,     0,   292,   237,
       0,   572,   294,     2,     3,     4,   230,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
     237,     0,     0,   295,     0,     0,     0,     0,     0,   -72,
       0,    17,     0,     0,     0,   236,   236,   236,     0,     0,
       0,   428,   294,     0,     0,   293,   306,     0,     2,     3,
       4,   230,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,   236,     0,     0,     0,   273,   274,   275,
     450,   276,   277,     0,     0,     0,    17,     0,   237,   278,
       0,   293,     0,   236,     0,   588,   293,     2,     3,     4,
     230,   237,     6,     0,     0,     0,     0,     0,   383,     7,
       8,     9,   239,   239,   239,     0,     0,     0,     0,   239,
     239,   239,     0,   -72,     0,    17,   237,   237,     0,   236,
       0,   238,   238,   238,     0,     0,   493,     0,   238,   238,
     238,     0,     0,     0,   293,     0,     0,   293,     0,     0,
       0,     0,   237,     0,   434,     0,     0,     0,     0,   306,
       0,     2,     3,     4,   230,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,   237,   237,
     273,   274,   275,   567,   276,   277,     0,   466,     0,    17,
     292,     0,   278,     0,   -13,   292,   -13,   -13,   -13,   -13,
     236,   -13,     0,     0,     0,     0,     0,     0,   -13,   -13,
     -13,     0,   -13,   -13,   293,   -13,   -13,   -13,   -13,   -13,
     -13,     0,     0,     0,   -13,   236,   236,   -13,   -13,     0,
       0,     0,     0,   -30,   -30,     0,   -30,   -30,   -30,   -30,
       0,   -30,     0,   509,     0,     0,   292,     0,   -30,   -30,
     -30,   236,   -30,   -30,   293,   -30,   -30,   -30,   -30,   -30,
     -30,     0,     0,     0,   -30,     0,   -48,   -30,   -48,   -48,
     -48,   -48,     0,   -48,     0,     0,     0,   236,   236,     0,
     -48,   -48,   -48,     0,   -48,   -48,     0,   -48,   -48,   -48,
     -48,   -48,   -48,     0,     0,     0,   -48,     0,     0,   -48,
     -48,    65,     0,   231,   232,   233,   234,    89,     6,   251,
     252,   253,   254,   292,     6,     7,     8,     9,     0,     0,
       0,     7,     8,     9,     0,     0,     0,     0,     0,     0,
       0,   235,     0,   237,   237,   237,     0,   255,     0,     0,
     237,   237,   237,   -49,     0,   -49,   -49,   -49,   -49,     0,
     -49,     0,     0,   292,     0,     0,     0,   -49,   -49,   -49,
       0,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,     0,   -49,     0,     0,   -49,   -49,   -44,     0,
     -44,   -44,   -44,   -44,     0,   -44,     0,     0,     0,     0,
       0,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,     0,
       0,   -44,   -44,    92,     0,   251,   252,   253,   254,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,   236,   236,   236,     0,     0,     0,     0,   236,
     236,   236,   -47,   255,   -47,   -47,   -47,   -47,     0,   -47,
       0,     0,     0,     0,     0,     0,   -47,   -47,   -47,     0,
     -47,   -47,     0,   -47,   -47,   -47,   -47,   -47,   -47,     0,
       0,     0,   -47,     0,     0,   -47,   -47,   -50,     0,   -50,
     -50,   -50,   -50,     0,   -50,     0,     0,     0,     0,     0,
       0,   -50,   -50,   -50,     0,   -50,   -50,     0,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,     0,   -50,     0,     0,
     -50,   -50,   -45,     0,   -45,   -45,   -45,   -45,     0,   -45,
       0,     0,     0,     0,     0,     0,   -45,   -45,   -45,     0,
     -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,
       0,     0,   -45,     0,     0,   -45,   -45,   -51,     0,   -51,
     -51,   -51,   -51,     0,   -51,     0,     0,     0,     0,     0,
       0,   -51,   -51,   -51,     0,   -51,   -51,     0,   -51,   -51,
     -51,   -51,   -51,   -51,     0,     0,     0,   -51,     0,     0,
     -51,   -51,   -46,     0,   -46,   -46,   -46,   -46,     0,   -46,
       0,     0,     0,     0,     0,     0,   -46,   -46,   -46,     0,
     -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,     0,
       0,     0,   -46,     0,     0,   -46,   -46,   -57,     0,   -57,
     -57,   -57,   -57,     0,   -57,     0,     0,     0,     0,     0,
       0,   -57,   -57,   -57,     0,   -57,   -57,     0,   -57,   -57,
     -57,   591,   -57,   -57,     0,     0,     0,   -57,     0,     0,
     -57,   -57,   -54,     0,   -54,   -54,   -54,   -54,     0,   -54,
       0,     0,     0,     0,     0,     0,   -54,   -54,   -54,     0,
     -54,   -54,     0,   -54,   -54,   -54,   593,   -54,   -54,     0,
       0,     0,   -54,     0,     0,   -54,   -54,   -48,   -48,     0,
     -48,   -48,   -48,   -48,     0,   -48,     0,     0,     0,     0,
       0,     0,   -48,   -48,   -48,     0,   -48,   -48,     0,   -48,
     -48,   -48,   -48,   -48,   -48,     0,     0,     0,   -48,   -49,
     -49,   -48,   -49,   -49,   -49,   -49,     0,   -49,     0,     0,
       0,     0,     0,     0,   -49,   -49,   -49,     0,   -49,   -49,
       0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,
     -49,   -44,   -44,   -49,   -44,   -44,   -44,   -44,     0,   -44,
       0,     0,     0,     0,     0,     0,   -44,   -44,   -44,     0,
     -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,     0,
       0,     0,   -44,   -47,   -47,   -44,   -47,   -47,   -47,   -47,
       0,   -47,     0,     0,     0,     0,     0,     0,   -47,   -47,
     -47,     0,   -47,   -47,     0,   -47,   -47,   -47,   -47,   -47,
     -47,     0,     0,     0,   -47,   -50,   -50,   -47,   -50,   -50,
     -50,   -50,     0,   -50,     0,     0,     0,     0,     0,     0,
     -50,   -50,   -50,     0,   -50,   -50,     0,   -50,   -50,   -50,
     -50,   -50,   -50,     0,     0,     0,   -50,   -45,   -45,   -50,
     -45,   -45,   -45,   -45,     0,   -45,     0,     0,     0,     0,
       0,     0,   -45,   -45,   -45,     0,   -45,   -45,     0,   -45,
     -45,   -45,   -45,   -45,   -45,     0,     0,     0,   -45,   -51,
     -51,   -45,   -51,   -51,   -51,   -51,     0,   -51,     0,     0,
       0,     0,     0,     0,   -51,   -51,   -51,     0,   -51,   -51,
       0,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,
     -51,   -46,   -46,   -51,   -46,   -46,   -46,   -46,     0,   -46,
       0,     0,     0,     0,     0,     0,   -46,   -46,   -46,     0,
     -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,     0,
       0,     0,   -46,   -57,   -57,   -46,   -57,   -57,   -57,   -57,
       0,   -57,     0,     0,     0,     0,     0,     0,   -57,   -57,
     -57,     0,   -57,   -57,     0,   -57,   -57,   -57,   598,   -57,
     -57,     0,     0,     0,   -57,   -54,   -54,   -57,   -54,   -54,
     -54,   -54,     0,   -54,     0,     0,     0,     0,     0,     0,
     -54,   -54,   -54,     0,   -54,   -54,     0,   -54,   -54,   -54,
     600,   -54,   -54,     0,     0,     0,   -54,     0,   -59,   -54,
     -59,   -59,   -59,   -59,     0,   -59,     0,     0,     0,     0,
       0,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,   -59,
     -59,   -59,   -59,   -59,   -59,     0,     0,     0,   -59,     0,
       0,   -59,   -59,   -56,     0,   -56,   -56,   -56,   -56,     0,
     -56,     0,     0,     0,     0,     0,     0,   -56,   -56,   -56,
       0,   -56,   -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,
       0,     0,     0,   -56,     0,     0,   -56,   -56,   -59,   -59,
       0,   -59,   -59,   -59,   -59,     0,   -59,     0,     0,     0,
       0,     0,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,
     -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,   -59,
     -56,   -56,   -59,   -56,   -56,   -56,   -56,     0,   -56,     0,
       0,     0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,
     -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
       0,   -56,     0,   -58,   -56,   -58,   -58,   -58,   -58,     0,
     -58,     0,     0,     0,     0,     0,     0,   -58,   -58,   -58,
       0,   -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,   -58,
       0,     0,     0,   -58,     0,     0,   -58,   -58,   -55,     0,
     -55,   -55,   -55,   -55,     0,   -55,     0,     0,     0,     0,
       0,     0,   -55,   -55,   -55,     0,   -55,   -55,     0,   -55,
     -55,   -55,   -55,   -55,   -55,     0,     0,     0,   -55,     0,
       0,   -55,   -55,   -58,   -58,     0,   -58,   -58,   -58,   -58,
       0,   -58,     0,     0,     0,     0,     0,     0,   -58,   -58,
     -58,     0,   -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,
     -58,     0,     0,     0,   -58,   -55,   -55,   -58,   -55,   -55,
     -55,   -55,     0,   -55,     0,     0,     0,     0,     0,     0,
     -55,   -55,   -55,     0,   -55,   -55,     0,   -55,   -55,   -55,
     -55,   -55,   -55,     0,     0,     0,   -55,     0,   -65,   -55,
     -65,   -65,   -65,   -65,     0,   -65,     0,     0,     0,     0,
       0,     0,   -65,   -65,   -65,     0,   -65,   -65,     0,   -65,
     -65,   -65,   -65,   -65,   -65,     0,     0,     0,   -65,     0,
       0,   -65,   -65,   -66,     0,   -66,   -66,   -66,   -66,     0,
     -66,     0,     0,     0,     0,     0,     0,   -66,   -66,   -66,
       0,   -66,   -66,     0,   -66,   -66,   -66,   -66,   -66,   -66,
       0,     0,     0,   -66,     0,     0,   -66,   -66,   -67,     0,
     -67,   -67,   -67,   -67,     0,   -67,     0,     0,     0,     0,
       0,     0,   -67,   -67,   -67,     0,   -67,   -67,     0,   -67,
     -67,   -67,   -67,   -67,   -67,     0,     0,     0,   -67,     0,
       0,   -67,   -67,   -64,     0,   -64,   -64,   -64,   -64,     0,
     -64,     0,     0,     0,     0,     0,     0,   -64,   -64,   -64,
       0,   -64,   -64,     0,   -64,   -64,   -64,   -64,   -64,   -64,
       0,     0,     0,   -64,     0,     0,   -64,   -64,   -65,   -65,
       0,   -65,   -65,   -65,   -65,     0,   -65,     0,     0,     0,
       0,     0,     0,   -65,   -65,   -65,     0,   -65,   -65,     0,
     -65,   -65,   -65,   -65,   -65,   -65,     0,     0,     0,   -65,
     -66,   -66,   -65,   -66,   -66,   -66,   -66,     0,   -66,     0,
       0,     0,     0,     0,     0,   -66,   -66,   -66,     0,   -66,
     -66,     0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,
       0,   -66,   -67,   -67,   -66,   -67,   -67,   -67,   -67,     0,
     -67,     0,     0,     0,     0,     0,     0,   -67,   -67,   -67,
       0,   -67,   -67,     0,   -67,   -67,   -67,   -67,   -67,   -67,
       0,     0,     0,   -67,   -64,   -64,   -67,   -64,   -64,   -64,
     -64,     0,   -64,     0,     0,     0,     0,     0,     0,   -64,
     -64,   -64,     0,   -64,   -64,     0,   -64,   -64,   -64,   -64,
     -64,   -64,     0,     0,     0,   -64,    -3,     1,   -64,     2,
       3,     4,     5,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,    10,    11,     0,    12,    13,
      14,     0,    15,    16,     0,     0,     0,    17,    -2,    69,
      18,     2,     3,     4,     5,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,    10,    11,     0,
      12,    13,    14,     0,    15,    16,     0,     0,     0,    17,
      -6,    -6,    18,    -6,    -6,    -6,    -6,     0,    -6,     0,
       0,     0,     0,     0,     0,    -6,    -6,    -6,     0,    -6,
      -6,     0,    -6,    -6,    -6,     0,    -6,    -6,     0,     0,
       0,    -6,    -8,    -8,    -6,    -8,    -8,    -8,    -8,     0,
      -8,     0,     0,     0,     0,     0,     0,    -8,    -8,    -8,
       0,    -8,    -8,     0,    -8,    -8,    -8,     0,    -8,    -8,
       0,     0,     0,    -8,    -7,    -7,    -8,    -7,    -7,    -7,
      -7,     0,    -7,     0,     0,     0,     0,     0,     0,    -7,
      -7,    -7,     0,    -7,    -7,     0,    -7,    -7,    -7,     0,
      -7,    -7,     0,     0,     0,    -7,   -39,   -39,    -7,   -39,
     -39,   -39,   -39,     0,   -39,     0,     0,     0,     0,     0,
       0,   -39,   -39,   -39,     0,   -39,   -39,     0,   -39,   -39,
     -39,     0,   -39,   -39,     0,     0,     0,   -39,    -9,    -9,
     -39,    -9,    -9,    -9,    -9,     0,    -9,     0,     0,     0,
       0,     0,     0,    -9,    -9,    -9,     0,    -9,    -9,     0,
      -9,    -9,    -9,     0,    -9,    -9,     0,     0,     0,    -9,
     -43,   -43,    -9,   -43,   -43,   -43,   -43,     0,   -43,     0,
       0,     0,     0,     0,     0,   -43,   -43,   -43,     0,   -43,
     -43,     0,   -43,   -43,   -43,     0,   -43,   -43,     0,     0,
       0,   -43,   -38,   -38,   -43,   -38,   -38,   -38,   -38,     0,
     -38,     0,     0,     0,     0,     0,     0,   -38,   -38,   -38,
       0,   -38,   -38,     0,   -38,   -38,   -38,     0,   -38,   -38,
       0,     0,     0,   -38,   -40,   -40,   -38,   -40,   -40,   -40,
     -40,     0,   -40,     0,     0,     0,     0,     0,     0,   -40,
     -40,   -40,     0,   -40,   -40,     0,   -40,   -40,   -40,     0,
     -40,   -40,     0,     0,     0,   -40,   -41,   -41,   -40,   -41,
     -41,   -41,   -41,     0,   -41,     0,     0,     0,     0,     0,
       0,   -41,   -41,   -41,     0,   -41,   -41,     0,   -41,   -41,
     -41,     0,   -41,   -41,     0,     0,     0,   -41,   -42,   -42,
     -41,   -42,   -42,   -42,   -42,     0,   -42,     0,     0,     0,
       0,     0,     0,   -42,   -42,   -42,     0,   -42,   -42,     0,
     -42,   -42,   -42,     0,   -42,   -42,     0,     0,     0,   -42,
     -53,   -53,   -42,   -53,   -53,   -53,   -53,     0,   -53,     0,
       0,     0,     0,     0,     0,   -53,   -53,   -53,     0,   -53,
     -53,     0,   -53,   -53,   -53,     0,   -53,   -53,     0,     0,
       0,   -53,    -5,    -5,   -53,    -5,    -5,    -5,    -5,     0,
      -5,     0,     0,     0,     0,     0,     0,    -5,    -5,    -5,
       0,    -5,    -5,     0,    -5,    -5,    -5,     0,    -5,    -5,
       0,     0,     0,    -5,   -52,   -52,    -5,   -52,   -52,   -52,
     -52,     0,   -52,     0,     0,     0,     0,     0,     0,   -52,
     -52,   -52,     0,   -52,   -52,     0,   -52,   -52,   -52,     0,
     -52,   -52,     0,     0,     0,   -52,   -11,   -11,   -52,   -11,
     -11,   -11,   -11,     0,   -11,     0,     0,     0,     0,     0,
       0,   -11,   -11,   -11,     0,   -11,   -11,     0,   -11,   -11,
     -11,     0,   -11,   -11,     0,     0,     0,   -11,   -63,   -63,
     -11,   -63,   -63,   -63,   -63,     0,   -63,     0,     0,     0,
       0,     0,     0,   -63,   -63,   -63,     0,   -63,   -63,     0,
     -63,   -63,   -63,     0,   -63,   -63,     0,     0,     0,   -63,
     -62,   -62,   -63,   -62,   -62,   -62,   -62,     0,   -62,     0,
       0,     0,     0,     0,     0,   -62,   -62,   -62,     0,   -62,
     -62,     0,   -62,   -62,   -62,     0,   -62,   -62,     0,     0,
       0,   -62,   -14,   -14,   -62,   -14,   -14,   -14,   -14,     0,
     -14,     0,     0,     0,     0,     0,     0,   -14,   -14,   -14,
       0,   -14,   -14,     0,   -14,   -14,   -14,     0,   -14,   -14,
       0,     0,     0,   -14,   -10,   -10,   -14,   -10,   -10,   -10,
     -10,     0,   -10,     0,     0,     0,     0,     0,     0,   -10,
     -10,   -10,     0,   -10,   -10,     0,   -10,   -10,   -10,     0,
     -10,   -10,     0,     0,     0,   -10,   -30,   -30,   -10,   -30,
     -30,   -30,   -30,     0,   -30,     0,     0,     0,     0,     0,
       0,   -30,   -30,   -30,     0,   -30,   -30,     0,   -30,   -30,
     -30,     0,   -30,   -30,     0,     0,     0,   -30,   -13,   -13,
     -30,   -13,   -13,   -13,   -13,     0,   -13,     0,     0,     0,
       0,     0,     0,   -13,   -13,   -13,     0,   -13,   -13,     0,
     -13,   -13,   -13,     0,   -13,   -13,     0,     0,     0,   -13,
     -12,   -12,   -13,   -12,   -12,   -12,   -12,     0,   -12,     0,
       0,     0,     0,     0,     0,   -12,   -12,   -12,     0,   -12,
     -12,     0,   -12,   -12,   -12,     0,   -12,   -12,     0,     0,
       0,   -12,   -48,   -48,   -12,   -48,   -48,   -48,   -48,     0,
     -48,     0,     0,     0,     0,     0,     0,   -48,   -48,   -48,
       0,   -48,   -48,     0,   -48,   -48,   -48,     0,   -48,   -48,
       0,     0,     0,   -48,   -49,   -49,   -48,   -49,   -49,   -49,
     -49,     0,   -49,     0,     0,     0,     0,     0,     0,   -49,
     -49,   -49,     0,   -49,   -49,     0,   -49,   -49,   -49,     0,
     -49,   -49,     0,     0,     0,   -49,   -44,   -44,   -49,   -44,
     -44,   -44,   -44,     0,   -44,     0,     0,     0,     0,     0,
       0,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,
     -44,     0,   -44,   -44,     0,     0,     0,   -44,   -47,   -47,
     -44,   -47,   -47,   -47,   -47,     0,   -47,     0,     0,     0,
       0,     0,     0,   -47,   -47,   -47,     0,   -47,   -47,     0,
     -47,   -47,   -47,     0,   -47,   -47,     0,     0,     0,   -47,
     -50,   -50,   -47,   -50,   -50,   -50,   -50,     0,   -50,     0,
       0,     0,     0,     0,     0,   -50,   -50,   -50,     0,   -50,
     -50,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,     0,
       0,   -50,   -45,   -45,   -50,   -45,   -45,   -45,   -45,     0,
     -45,     0,     0,     0,     0,     0,     0,   -45,   -45,   -45,
       0,   -45,   -45,     0,   -45,   -45,   -45,     0,   -45,   -45,
       0,     0,     0,   -45,   -51,   -51,   -45,   -51,   -51,   -51,
     -51,     0,   -51,     0,     0,     0,     0,     0,     0,   -51,
     -51,   -51,     0,   -51,   -51,     0,   -51,   -51,   -51,     0,
     -51,   -51,     0,     0,     0,   -51,   -46,   -46,   -51,   -46,
     -46,   -46,   -46,     0,   -46,     0,     0,     0,     0,     0,
       0,   -46,   -46,   -46,     0,   -46,   -46,     0,   -46,   -46,
     -46,     0,   -46,   -46,     0,     0,     0,   -46,   -59,   -59,
     -46,   -59,   -59,   -59,   -59,     0,   -59,     0,     0,     0,
       0,     0,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,
     -59,   -59,   -59,     0,   -59,   -59,     0,     0,     0,   -59,
     -56,   -56,   -59,   -56,   -56,   -56,   -56,     0,   -56,     0,
       0,     0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,
     -56,     0,   -56,   -56,   -56,     0,   -56,   -56,     0,     0,
       0,   -56,   -58,   -58,   -56,   -58,   -58,   -58,   -58,     0,
     -58,     0,     0,     0,     0,     0,     0,   -58,   -58,   -58,
       0,   -58,   -58,     0,   -58,   -58,   -58,     0,   -58,   -58,
       0,     0,     0,   -58,   -55,   -55,   -58,   -55,   -55,   -55,
     -55,     0,   -55,     0,     0,     0,     0,     0,     0,   -55,
     -55,   -55,     0,   -55,   -55,     0,   -55,   -55,   -55,     0,
     -55,   -55,     0,     0,     0,   -55,   -20,   -20,   -55,   -20,
     -20,   -20,   -20,     0,   -20,     0,     0,     0,     0,     0,
       0,   -20,   -20,   -20,     0,   -20,   -20,     0,   -20,   -20,
     -20,     0,   -20,   -20,     0,     0,     0,   -20,   -17,   -17,
     -20,   -17,   -17,   -17,   -17,     0,   -17,     0,     0,     0,
       0,     0,     0,   -17,   -17,   -17,     0,   -17,   -17,     0,
     -17,   -17,   -17,     0,   -17,   -17,     0,     0,     0,   -17,
     -65,   -65,   -17,   -65,   -65,   -65,   -65,     0,   -65,     0,
       0,     0,     0,     0,     0,   -65,   -65,   -65,     0,   -65,
     -65,     0,   -65,   -65,   -65,     0,   -65,   -65,     0,     0,
       0,   -65,   -66,   -66,   -65,   -66,   -66,   -66,   -66,     0,
     -66,     0,     0,     0,     0,     0,     0,   -66,   -66,   -66,
       0,   -66,   -66,     0,   -66,   -66,   -66,     0,   -66,   -66,
       0,     0,     0,   -66,   -67,   -67,   -66,   -67,   -67,   -67,
     -67,     0,   -67,     0,     0,     0,     0,     0,     0,   -67,
     -67,   -67,     0,   -67,   -67,     0,   -67,   -67,   -67,     0,
     -67,   -67,     0,     0,     0,   -67,   -64,   -64,   -67,   -64,
     -64,   -64,   -64,     0,   -64,     0,     0,     0,     0,     0,
       0,   -64,   -64,   -64,     0,   -64,   -64,     0,   -64,   -64,
     -64,     0,   -64,   -64,     0,     0,     0,   -64,     0,   306,
     -64,     2,     3,     4,   230,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
     273,   274,   275,   569,   276,   277,     0,     0,     0,    17,
       0,   320,   278,     2,     3,     4,   230,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
       0,     0,   321,   322,   323,   583,   324,   325,     0,     0,
       0,    17,     0,   320,   326,     2,     3,     4,   230,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,     0,     0,   321,   322,   323,   585,   324,   325,
       0,     0,     0,    17,     0,    69,   326,     2,     3,     4,
     230,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,    12,    13,    14,     0,
      15,    16,     0,     0,     0,    17,     0,   320,    18,     2,
       3,     4,   230,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,     0,     0,     0,   321,   322,
     323,     0,   324,   325,     0,     0,     0,    17,     0,    94,
     326,   251,   252,   253,   254,    96,     6,   251,   252,   253,
     254,     0,     6,     7,     8,     9,     0,     0,     0,     7,
       8,     9,     0,    98,     0,   251,   252,   253,   254,   255,
       6,     0,     0,     0,     0,   255,     0,     7,     8,     9,
     102,     0,   251,   252,   253,   254,     0,     6,     0,     0,
       0,     0,     0,   255,     7,     8,     9,   110,     0,   231,
     232,   233,   234,     0,     6,     0,     0,     0,     0,     0,
     255,     7,     8,     9,   128,     0,   251,   252,   253,   254,
       0,     6,     0,     0,     0,     0,     0,   235,     7,     8,
       9,   130,     0,   251,   252,   253,   254,     0,     6,     0,
       0,     0,     0,     0,   255,     7,     8,     9,   132,     0,
     251,   252,   253,   254,     0,     6,     0,     0,     0,     0,
       0,   255,     7,     8,     9,   134,     0,   251,   252,   253,
     254,     0,     6,     0,     0,     0,     0,     0,   255,     7,
       8,     9,   136,     0,   251,   252,   253,   254,     0,     6,
       0,     0,     0,     0,     0,   255,     7,     8,     9,   138,
       0,   251,   252,   253,   254,     0,     6,     0,     0,     0,
       0,     0,   255,     7,     8,     9,   140,     0,   251,   252,
     253,   254,     0,     6,     0,     0,     0,     0,     0,   255,
       7,     8,     9,   142,     0,   251,   252,   253,   254,     0,
       6,     0,     0,     0,     0,     0,   255,     7,     8,     9,
     144,     0,   251,   252,   253,   254,     0,     6,     0,     0,
       0,     0,     0,   255,     7,     8,     9,   336,     0,   287,
     288,   289,   290,     0,     6,     0,     0,     0,     0,     0,
     255,     7,     8,     9,   339,     0,   231,   232,   233,   234,
       0,     6,     0,     0,     0,     0,     0,   291,     7,     8,
       9,   353,     0,   231,   232,   233,   234,     0,     6,     0,
       0,     0,     0,     0,   235,     7,     8,     9,   369,     0,
     358,   359,   360,   361,     0,     6,     0,     0,     0,     0,
       0,   235,     7,     8,     9,   372,     0,   358,   359,   360,
     361,     0,     6,     0,     0,     0,     0,     0,   362,     7,
       8,     9,   374,     0,   358,   359,   360,   361,     0,     6,
       0,     0,     0,     0,     0,   362,     7,     8,     9,   376,
       0,   358,   359,   360,   361,     0,     6,     0,     0,     0,
       0,     0,   362,     7,     8,     9,   378,     0,   358,   359,
     360,   361,     0,     6,     0,     0,     0,     0,     0,   362,
       7,     8,     9,   382,     0,   358,   359,   360,   361,     0,
       6,     0,     0,     0,     0,     0,   362,     7,     8,     9,
     390,     0,     2,     3,     4,   230,     0,     6,     0,     0,
       0,     0,     0,   362,     7,     8,     9,   395,     0,   231,
     232,   233,   234,     0,     6,     0,     0,     0,     0,     0,
      17,     7,     8,     9,   420,     0,   409,   410,   411,   412,
       0,     6,     0,     0,     0,     0,     0,   235,     7,     8,
       9,   423,     0,   409,   410,   411,   412,     0,     6,     0,
       0,     0,     0,     0,   413,     7,     8,     9,   425,     0,
     409,   410,   411,   412,     0,     6,     0,     0,     0,     0,
       0,   413,     7,     8,     9,   427,     0,   409,   410,   411,
     412,     0,     6,     0,     0,     0,     0,     0,   413,     7,
       8,     9,   429,     0,   409,   410,   411,   412,     0,     6,
       0,     0,     0,     0,     0,   413,     7,     8,     9,   433,
       0,   409,   410,   411,   412,     0,     6,     0,     0,     0,
       0,     0,   413,     7,     8,     9,   442,     0,     2,     3,
       4,   230,     0,     6,     0,     0,     0,     0,     0,   413,
       7,     8,     9,   449,     0,   358,   359,   360,   361,     0,
       6,     0,     0,     0,     0,     0,    17,     7,     8,     9,
     451,     0,   358,   359,   360,   361,     0,     6,     0,     0,
       0,     0,     0,   362,     7,     8,     9,   453,     0,   358,
     359,   360,   361,     0,     6,     0,     0,     0,     0,     0,
     362,     7,     8,     9,   455,     0,   358,   359,   360,   361,
       0,     6,     0,     0,     0,     0,     0,   362,     7,     8,
       9,   457,     0,   358,   359,   360,   361,     0,     6,     0,
       0,     0,     0,     0,   362,     7,     8,     9,   459,     0,
     358,   359,   360,   361,     0,     6,     0,     0,     0,     0,
       0,   362,     7,     8,     9,   461,     0,   358,   359,   360,
     361,     0,     6,     0,     0,     0,     0,     0,   362,     7,
       8,     9,   463,     0,   358,   359,   360,   361,     0,     6,
       0,     0,     0,     0,     0,   362,     7,     8,     9,   465,
       0,   358,   359,   360,   361,     0,     6,     0,     0,     0,
       0,     0,   362,     7,     8,     9,   471,     0,   231,   232,
     233,   234,     0,     6,     0,     0,     0,     0,     0,   362,
       7,     8,     9,   481,     0,   231,   232,   233,   234,     0,
       6,     0,     0,     0,     0,     0,   235,     7,     8,     9,
     492,     0,   409,   410,   411,   412,     0,     6,     0,     0,
       0,     0,     0,   235,     7,     8,     9,   494,     0,   409,
     410,   411,   412,     0,     6,     0,     0,     0,     0,     0,
     413,     7,     8,     9,   496,     0,   409,   410,   411,   412,
       0,     6,     0,     0,     0,     0,     0,   413,     7,     8,
       9,   498,     0,   409,   410,   411,   412,     0,     6,     0,
       0,     0,     0,     0,   413,     7,     8,     9,   500,     0,
     409,   410,   411,   412,     0,     6,     0,     0,     0,     0,
       0,   413,     7,     8,     9,   502,     0,   409,   410,   411,
     412,     0,     6,     0,     0,     0,     0,     0,   413,     7,
       8,     9,   504,     0,   409,   410,   411,   412,     0,     6,
       0,     0,     0,     0,     0,   413,     7,     8,     9,   506,
       0,   409,   410,   411,   412,     0,     6,     0,     0,     0,
       0,     0,   413,     7,     8,     9,   508,     0,   409,   410,
     411,   412,     0,     6,     0,     0,     0,     0,     0,   413,
       7,     8,     9,   511,     0,   231,   232,   233,   234,     0,
       6,     0,     0,     0,     0,     0,   413,     7,     8,     9,
     521,     0,   231,   232,   233,   234,     0,     6,     0,     0,
       0,     0,     0,   235,     7,     8,     9,     0,     0,  -108,
    -108,  -108,  -108,     0,  -108,     0,     0,     0,     0,     0,
     235,  -108,  -108,  -108,     0,     0,  -110,  -110,  -110,  -110,
       0,  -110,     0,     0,     0,     0,     0,  -108,  -110,  -110,
    -110,     0,     0,     2,     3,     4,   230,     0,     6,     0,
       0,     0,     0,     0,  -110,     7,     8,     9,     0,     0,
     251,   252,   253,   254,     0,     6,     0,     0,     0,     0,
       0,    17,     7,     8,     9,     0,     0,   231,   232,   233,
     234,     0,     6,     0,     0,     0,     0,     0,   255,     7,
       8,     9,     0,     0,   358,   359,   360,   361,     0,     6,
       0,     0,     0,     0,     0,   235,     7,     8,     9,     0,
       0,   287,   288,   289,   290,     0,     6,     0,     0,     0,
       0,     0,   362,     7,     8,     9,     0,     0,   409,   410,
     411,   412,     0,     6,     0,     0,     0,     0,     0,   291,
       7,     8,     9,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,     0,     0,     0,     0,     0,   413,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,     0,   405,     0,  -101,  -101,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,     0,     0,
    -105,     0,  -105,  -105,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,     0,  -111,     0,  -111,  -111,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,     0,     0,  -119,     0,  -119,
    -119,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,     0,
    -106,     0,  -106,  -106,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,     0,     0,  -122,     0,  -122,  -122,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,     0,  -121,     0,  -121,
    -121,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,     0,
       0,  -120,     0,  -120,  -120,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,     0,  -112,     0,  -112,  -112,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,     0,     0,     0,     0,
    -130,  -130,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
       0,     0,     0,  -128,  -128,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,     0,     0,     0,     0,  -104,  -104,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,     0,     0,     0,
    -105,  -105,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
       0,     0,     0,     0,  -111,  -111,   404,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,     0,     0,     0,  -119,  -119,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,     0,     0,     0,
       0,  -100,  -100,   308,   309,   310,   311,   -76,   313,   314,
     315,     0,     0,     0,  -101,  -101,   308,   309,   310,   -80,
     -80,   313,   314,   315,     0,     0,     0,     0,   -76,   -76,
     308,   309,   310,   -84,   -84,   -84,   314,   315,     0,     0,
       0,   -80,   -80,   308,   309,   -88,   -88,   -88,   -88,   314,
     315,     0,     0,     0,     0,   -84,   -84,   308,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,     0,     0,     0,   -88,   -88,
     404,   -98,   -98,   -98,   -98,   -98,   -98,   -98,     0,     0,
       0,     0,   -99,   -99,   308,   309,   -94,   -94,   -94,   -94,
     314,   315,     0,     0,     0,   -98,   -98,   308,   309,   -93,
     -93,   -93,   -93,   314,   315,     0,     0,     0,     0,   -94,
     -94,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,     0,
       0,     0,   -93,   -93,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,     0,     0,     0,     0,  -103,  -103,   308,   309,
     310,   311,   312,   313,   314,   315,     0,     0,     0,  -102,
    -102,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,     0,
       0,     0,     0,   -70,   -70,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,     0,     0,     0,  -106,  -106,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,     0,     0,     0,     0,
    -122,  -122,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
       0,     0,     0,  -121,  -121,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,     0,     0,     0,     0,  -120,  -120,   262,
     263,   264,   265,   266,   267,   268,   269,     0,     0,     0,
    -112,  -112,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
       0,     0,   270,     0,   223,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,     0,     0,  -129,     0,  -129,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,     0,     0,  -130,     0,
    -130,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,     0,
       0,  -128,     0,  -128,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,     0,     0,   349,     0,  -101,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,     0,     0,  -105,     0,  -105,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,     0,
    -111,     0,  -111,   262,   263,   264,   265,   266,   267,   268,
     269,     0,     0,  -119,     0,  -119,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,     0,     0,   270,     0,   447,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,  -106,
       0,  -106,   262,   263,   264,   265,   266,   267,   268,   269,
       0,     0,  -122,     0,  -122,   262,   263,   264,   265,   266,
     267,   268,   269,     0,     0,   270,     0,   468,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,     0,     0,   270,     0,
     490,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,     0,
       0,  -121,     0,  -121,   262,   263,   264,   265,   266,   267,
     268,   269,     0,     0,  -120,     0,  -120,   262,   263,   264,
     265,   266,   267,   268,   269,     0,     0,   270,     0,   530,
     262,   263,   264,   265,   266,   267,   268,   269,     0,     0,
     270,     0,   535,   262,   263,   264,   265,   266,   267,   268,
     269,     0,     0,   270,     0,   538,   262,   263,   264,   265,
     266,   267,   268,   269,     0,     0,   270,     0,   545,   262,
     263,   264,   265,   266,   267,   268,   269,     0,     0,   270,
       0,   550,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
       0,     0,   270,     0,   553,   262,   263,   264,   265,   266,
     267,   268,   269,     0,     0,  -112,     0,  -112,   262,   263,
     264,   265,   266,   267,   268,   269,     0,     0,   270,     0,
     618,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,
       0,   270,     0,   622,   348,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,     0,     0,     0,     0,  -119,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,     0,     0,     0,     0,  -100,
     262,   263,   264,   265,   -76,   267,   268,   269,     0,     0,
       0,     0,  -101,   262,   263,   264,   -80,   -80,   267,   268,
     269,     0,     0,     0,     0,   -76,   262,   263,   264,   -84,
     -84,   -84,   268,   269,     0,     0,     0,     0,   -80,   262,
     263,   -88,   -88,   -88,   -88,   268,   269,     0,     0,     0,
       0,   -84,   262,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
       0,     0,     0,     0,   -88,   348,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,     0,     0,     0,     0,   -99,   262,   263,
     -94,   -94,   -94,   -94,   268,   269,     0,     0,     0,     0,
     -98,   262,   263,   -93,   -93,   -93,   -93,   268,   269,     0,
       0,     0,     0,   -94,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,     0,     0,     0,     0,   -93,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,     0,     0,     0,     0,  -103,
     262,   263,   264,   265,   266,   267,   268,   269,     0,     0,
       0,     0,  -102,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,     0,     0,     0,     0,   -70,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,     0,     0,     0,     0,  -106,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,     0,     0,     0,
       0,  -122,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
       0,     0,     0,     0,  -121,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,     0,     0,     0,     0,  -120,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,     0,     0,     0,     0,
    -112,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,     0,
    -130,  -130,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
       0,     0,     0,  -128,  -128,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,     0,  -101,    80,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,     0,     0,     0,  -105,  -105,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,  -111,  -111,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,  -119,  -119,    46,    47,    48,    49,    50,    51,    52,
      53,     0,   115,    55,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,     0,     0,     0,    54,    55,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,     0,  -106,  -106,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,  -122,
    -122,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,     0,
     163,    55,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
       0,     0,     0,  -121,  -121,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,     0,  -120,  -120,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,  -112,  -112,    46,
      47,    48,    49,    50,    51,    52,    53,     0,   208,    55,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,   305,    55,    46,    47,    48,    49,    50,    51,    52,
      53,     0,   437,    55,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,   485,    55,    46,    47,    48,
      49,    50,    51,    52,    53,     0,   525,    55,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,   540,
      55,    46,    47,    48,    49,    50,    51,    52,    53,     0,
     555,    55,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,   595,    55,    46,    47,    48,    49,    50,
      51,    52,    53,     0,   602,    55,   308,   309,   310,   311,
     312,   313,   314,   315,     0,     0,     0,     0,    55,   262,
     263,   264,   265,   266,   267,   268,   269,     0,     0,   316,
      79,  -100,  -100,  -100,  -100,  -100,  -100,  -100,     0,     0,
       0,     0,   270,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,     0,  -100,    46,    47,    48,    49,   -76,    51,    52,
      53,     0,     0,     0,     0,  -101,    46,    47,    48,   -80,
     -80,    51,    52,    53,     0,   -76,    46,    47,    48,   -84,
     -84,   -84,    52,    53,     0,     0,     0,     0,   -80,    46,
      47,   -88,   -88,   -88,   -88,    52,    53,     0,   -84,    46,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,     0,     0,     0,
       0,   -88,    79,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
       0,   -99,    46,    47,   -94,   -94,   -94,   -94,    52,    53,
       0,     0,     0,     0,   -98,    46,    47,   -93,   -93,   -93,
     -93,    52,    53,     0,   -94,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,     0,     0,     0,     0,   -93,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,     0,  -103,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
    -102,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,     0,
     -70,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,     0,
       0,     0,     0,  -129,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,     0,  -130,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,     0,     0,     0,     0,  -128,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,     0,  -105,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,     0,     0,     0,     0,  -111,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,     0,  -119,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,
       0,     0,  -106,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,     0,  -122,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,     0,     0,     0,     0,  -121,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,     0,  -120,   308,   309,   310,   311,
     312,   313,   314,   315,     0,     0,     0,     0,  -112
};

static const yytype_int16 yycheck[] =
{
       0,     0,   392,   387,   278,    11,     1,     0,   352,     1,
       1,     6,     1,   357,     6,     6,    16,    17,     0,    31,
      20,    20,     1,    31,    19,    20,    32,    20,    19,    20,
       1,     0,   163,   164,     1,     1,     1,    32,    20,    29,
      29,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      29,     1,   326,     1,   444,   439,     6,     1,    29,    59,
      60,    61,    29,    29,   408,    30,    31,    32,    33,    19,
      20,    11,     0,    31,     1,     1,   207,   208,   209,     0,
      31,    29,    32,    83,     0,    29,    10,    11,     6,    29,
      29,     1,    20,     3,     4,     5,     6,    32,     8,    20,
       6,     6,    29,    29,    20,    15,    16,    17,    32,    19,
      20,    29,    22,    23,    24,    25,    26,    27,     6,     6,
       6,    31,    11,    29,    34,    35,     1,    32,    33,     6,
      11,   475,     7,     8,     9,    10,    11,    12,    13,    14,
      32,    33,    29,    32,    32,    33,    32,    33,    29,     7,
       6,     6,    29,   152,    31,     0,    31,    32,    33,     0,
       6,   161,   162,   163,   164,    21,    21,     6,   161,   162,
     170,   515,     6,    32,    29,    20,    32,    33,    11,    20,
       6,   180,    21,    29,    11,    31,    29,    21,    32,   189,
      32,   191,   120,    32,    33,    29,   189,    31,   191,    32,
      33,   200,    29,    29,   204,    31,   206,   207,   208,   209,
      32,   204,     0,   206,    10,    11,    12,   210,    11,    10,
      11,   221,   222,   223,   224,    10,    11,   220,   221,   222,
     223,   224,    20,   161,   162,   235,    32,   165,    29,    32,
     161,   162,     6,    32,    29,   161,   162,     7,     8,     9,
      10,    11,    12,    13,    14,   255,     6,    21,   389,    10,
      11,   189,    32,   191,     1,    29,    29,    31,   189,     6,
     191,    21,    32,   189,    35,   191,   204,   277,   206,    29,
      32,    32,    33,   204,     6,   206,    29,    30,   204,     1,
     206,   291,    11,   221,   222,   223,   224,    19,    20,     1,
     221,   222,   223,   224,     6,   221,   222,   223,   224,    29,
     441,    32,    33,    32,    33,     1,   161,   162,    10,    11,
     161,   162,    29,    30,     1,   325,     9,    10,    11,    12,
       7,     8,     9,    10,    11,    12,    13,    14,    10,    11,
      32,    33,    10,    11,   189,    11,   191,    29,   189,    32,
     191,    32,   352,    30,    31,    32,    33,   357,    29,   204,
      32,   206,   362,   204,    32,   206,    32,    33,     9,    10,
      11,    12,    29,   161,   162,    34,   221,   222,   223,   224,
     221,   222,   223,   224,    29,    30,    31,   387,   388,   389,
       1,    32,     3,     4,     5,     6,    32,     8,    10,    11,
      12,   189,    32,   191,    15,    16,    17,    32,   408,   540,
     541,    32,    33,   413,    32,    33,   204,    29,   206,    32,
      31,    32,    32,    33,   555,   556,    32,    33,     9,    10,
      11,    12,    32,   221,   222,   223,   224,     1,    32,   439,
     440,   441,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    32,    33,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,   594,   595,   596,    31,    31,    32,    33,
     601,   602,   603,    31,     1,   475,     3,     4,     5,     6,
      32,     8,    31,     9,    10,    11,    12,    31,    15,    16,
      17,    29,    19,    20,    31,    22,    23,    24,    25,    26,
      27,    10,    11,    12,    31,    29,    32,    34,    35,     1,
      31,     3,     4,     5,     6,   515,     8,    29,    30,    31,
      29,    32,    33,    15,    16,    17,    31,    19,    20,    31,
      22,    23,    24,    25,    26,    27,    10,    11,     1,    31,
     540,   541,    34,    35,     7,     8,     9,    10,    11,    12,
      13,    14,     1,   553,   554,   555,   556,    32,    32,    33,
     553,   554,    32,     9,    10,    11,    12,    30,    31,    32,
       9,    10,    11,    12,     7,     8,     9,    10,    11,    12,
      13,    14,    32,   583,     7,   585,    32,    33,    32,    33,
     583,    29,   585,    32,   594,   595,   596,    30,   598,    32,
     600,   601,   602,   603,    32,   598,     1,   600,    29,    30,
     538,   539,     7,     8,     9,    10,    11,    12,    13,    14,
     620,   621,   622,   623,     7,   553,   554,   620,   621,   622,
     623,    29,   553,   554,    29,    30,    31,   553,   554,   567,
      32,   569,    10,    11,     1,    32,     3,     4,     5,     6,
      32,     8,    10,    11,    12,   583,    32,   585,    15,    16,
      17,    29,   583,   591,   585,   593,    32,   583,    32,   585,
     598,    29,   600,    32,    31,    32,    32,   598,    29,   600,
       7,     8,   598,    35,   600,     1,    13,    14,   616,   617,
     618,   619,   620,   621,   622,   623,    10,    11,    12,   620,
     621,   622,   623,    32,   620,   621,   622,   623,   553,   554,
      32,    33,   553,   554,     7,     8,     1,    32,    32,    33,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
       8,     9,    10,    11,    12,    13,    14,    32,   583,    29,
     585,     0,   583,    32,   585,    30,    31,    32,     9,    10,
      11,    12,    32,   598,    32,   600,    32,   598,    17,   600,
      32,    20,     7,     8,     9,   553,   554,    12,    13,    14,
      35,    32,    33,    29,    30,   620,   621,   622,   623,   620,
     621,   622,   623,    32,    43,    44,    29,    46,    47,    48,
      49,    50,    51,    52,    53,   583,    55,   585,    29,    58,
      59,    60,     9,    10,    11,    12,    32,    29,    67,    29,
     598,    29,   600,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    29,     1,    83,     3,     4,     5,     6,    29,
       8,    29,   620,   621,   622,   623,    29,    15,    16,    17,
      32,    19,    20,    32,    22,    23,    24,    25,    26,    27,
      32,    32,    32,    31,    20,    32,    34,    35,     1,   180,
       3,     4,     5,     6,   123,     8,   200,    -1,   127,   123,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,    35,   152,    -1,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,     9,    10,    11,    12,    -1,    -1,
       1,   170,     3,     4,     5,     6,    -1,     8,    29,   178,
      31,   180,    -1,    -1,    15,    16,    17,    32,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,   200,    -1,    34,    35,    -1,    -1,    -1,   207,   208,
     209,    10,    11,    12,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,     9,    10,    11,    12,    -1,
      15,    16,    17,    32,    19,    20,   235,    22,    23,    24,
      25,    26,    27,    -1,    -1,   244,    31,    -1,    32,    34,
      35,    -1,     9,    10,    11,    12,   255,   256,    -1,     9,
      10,    11,    12,   262,   263,   264,   265,   266,   267,   268,
     269,   270,    -1,    -1,     1,    32,     3,     4,     5,     6,
      -1,     8,    32,    33,    10,    11,    12,   286,    15,    16,
      17,    -1,   291,    -1,    -1,    22,    23,    24,    25,    26,
      27,   300,    -1,    -1,    31,    -1,    32,    34,    -1,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    10,    11,
      12,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      32,    33,   341,   342,   343,   344,   345,   346,   347,   348,
     349,    31,     1,   352,     3,     4,     5,     6,   357,     8,
      -1,    -1,    -1,   362,    -1,   364,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,   386,   387,   388,
      -1,    -1,    17,   392,     9,    10,    11,    12,   397,   398,
     399,   400,   401,   402,   403,   404,   405,    -1,    -1,   408,
       9,    10,    11,    12,   413,    40,   415,    32,    33,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    -1,    -1,    32,    59,    60,     7,     8,     9,   438,
     439,   440,    13,    14,    -1,   444,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    83,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,     9,    10,
      11,    12,    -1,    15,    16,    17,   475,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    10,    11,    12,    31,
      -1,    32,    34,    35,    -1,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    32,    33,
      15,    16,    17,    -1,    19,    20,   515,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,     9,    10,    11,
      12,    -1,    15,    16,    17,   170,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    29,    31,    -1,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,     9,
      10,    11,    12,    -1,    15,    16,    17,     9,    10,    11,
      12,    -1,   207,   208,   209,     9,    10,    11,    12,    -1,
      31,    32,    32,    33,    -1,   594,   595,   596,    -1,    -1,
      32,    33,   601,   602,   603,     1,    -1,    -1,    32,    33,
     235,     7,     8,     9,    10,    11,    12,    13,    14,   244,
      -1,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
     255,   256,    -1,    -1,    -1,    31,    32,   262,   263,   264,
     265,   266,   267,   268,   269,   270,     1,    32,     3,     4,
       5,     6,    -1,     8,    -1,     9,    10,    11,    12,    -1,
      15,    16,    17,    -1,    19,    20,   291,    22,    23,    24,
      25,    26,    27,    -1,    -1,   300,    31,    -1,    32,    34,
      35,    -1,    -1,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,     7,     8,    15,
      16,    17,    18,    13,    14,    -1,   341,   342,   343,   344,
     345,   346,   347,   348,   349,    31,     1,   352,     3,     4,
       5,     6,   357,     8,    -1,    -1,    -1,   362,    -1,   364,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,   387,   388,    17,    -1,    -1,    -1,     9,    10,
      11,    12,   397,   398,   399,   400,   401,   402,   403,   404,
     405,    -1,    -1,   408,     9,    10,    11,    12,   413,    -1,
     415,    32,    33,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    -1,    29,    -1,    59,    60,     9,    10,
      11,    12,    -1,    -1,   439,   440,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      83,    32,    33,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,     9,    10,    11,    12,    -1,    15,    16,    17,
     475,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    29,    31,    -1,    -1,    34,    35,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,     9,
      10,    11,    12,    -1,    15,    16,    17,    -1,    19,    20,
     515,    22,    23,    24,    25,    26,    27,    -1,    -1,    29,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,   170,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,     1,    31,    -1,    -1,    34,    35,
       7,     8,     9,    10,    11,    12,    13,    14,     9,    10,
      11,    12,    -1,    -1,   207,   208,   209,    -1,    -1,     9,
      10,    11,    12,    -1,    31,    32,    -1,    -1,    29,   594,
     595,   596,     9,    10,    11,    12,   601,   602,   603,    29,
      -1,    -1,   235,     7,     8,     9,    10,    11,    12,    13,
      14,   244,    29,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,   255,   256,    -1,    -1,    30,    -1,    32,   262,
     263,   264,   265,   266,   267,   268,   269,   270,     1,    32,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,   291,    22,
      23,    24,    25,    26,    27,    -1,    -1,   300,    31,    -1,
      -1,    34,    35,    -1,    -1,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    -1,    -1,   341,   342,
     343,   344,   345,   346,   347,   348,   349,    31,     1,   352,
       3,     4,     5,     6,   357,     8,    -1,    -1,    -1,   362,
      -1,   364,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,   387,   388,    17,     8,     9,    10,
      11,    12,    13,    14,   397,   398,   399,   400,   401,   402,
     403,   404,   405,    -1,    -1,   408,    -1,    -1,    29,    -1,
     413,    -1,   415,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    -1,    -1,    -1,    59,    60,
       9,    10,    11,    12,    -1,    -1,   439,   440,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      29,    -1,    83,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,     9,    10,    11,    12,    -1,    15,
      16,    17,   475,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    29,    31,    -1,    -1,    34,    35,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   515,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,   170,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,   207,   208,   209,    15,
      16,    17,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,   594,   595,   596,    -1,    31,    32,    -1,   601,   602,
     603,    -1,    -1,    -1,   235,    30,    -1,    32,    33,    -1,
      -1,    -1,    -1,   244,    -1,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,   255,   256,    -1,    -1,    -1,    -1,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
       1,    32,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
     291,    22,    23,    24,    25,    26,    27,    -1,    -1,   300,
      31,    -1,    -1,    34,    35,    -1,    -1,   308,   309,   310,
     311,   312,   313,   314,   315,   316,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,
     341,   342,   343,   344,   345,   346,   347,   348,   349,     0,
       1,   352,     3,     4,     5,     6,   357,     8,    -1,    -1,
      -1,   362,    -1,   364,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    -1,    -1,   387,   388,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   397,   398,   399,   400,
     401,   402,   403,   404,   405,    -1,    -1,   408,    -1,     7,
       8,     9,   413,    -1,   415,    13,    14,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,     7,     8,     9,
      59,    60,    12,    13,    14,     7,     8,     9,   439,   440,
      12,    13,    14,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    83,    -1,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,   475,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,   515,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,   170,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,     0,    15,    16,    17,   207,   208,
     209,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    31,    32,   594,   595,   596,    -1,    -1,    -1,    -1,
     601,   602,   603,    29,    30,    -1,   235,     7,     8,     9,
      10,    11,    12,    13,    14,   244,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,   255,   256,    -1,    -1,
      30,    -1,    32,   262,   263,   264,   265,   266,   267,   268,
     269,   270,     1,    32,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   291,    22,    23,    24,    25,    26,    27,    -1,
      -1,   300,    31,    -1,    -1,    34,    35,    -1,    -1,   308,
     309,   310,   311,   312,   313,   314,   315,   316,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,   341,   342,   343,   344,   345,   346,   347,   348,
     349,     0,     1,   352,     3,     4,     5,     6,   357,     8,
      -1,    -1,    -1,   362,    -1,   364,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    -1,    -1,   387,   388,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,   398,
     399,   400,   401,   402,   403,   404,   405,    -1,    -1,   408,
      -1,     7,     8,     9,   413,    -1,   415,    13,    14,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
     439,   440,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    83,    -1,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,   475,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    -1,    -1,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,   515,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,   170,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,     1,    -1,    34,    35,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
     207,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    -1,    -1,   594,   595,   596,    -1,    -1,
      -1,    -1,   601,   602,   603,    -1,    -1,    -1,   235,     7,
       8,     9,    10,    11,    12,    13,    14,   244,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,   255,   256,
      -1,    15,    16,    17,    32,   262,   263,   264,   265,   266,
     267,   268,   269,   270,    -1,    -1,     1,    31,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,   291,    -1,    17,    22,    23,    24,
      25,    26,    27,   300,    -1,    -1,    31,    -1,    -1,    34,
      -1,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,    -1,    -1,     7,     8,     9,    10,    48,    12,    13,
      14,    52,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,   341,   342,   343,   344,   345,   346,
     347,   348,   349,    -1,    75,   352,    77,    78,    -1,    -1,
     357,    -1,    83,    -1,     1,   362,    -1,   364,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
     387,   388,    29,    30,    31,    -1,    15,    16,    17,    -1,
     397,   398,   399,   400,   401,   402,   403,   404,   405,    -1,
      29,   408,    31,    -1,    -1,    -1,   413,    -1,   415,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    29,   439,   440,    15,    16,    17,    17,    -1,   170,
       1,    -1,     3,     4,     5,     6,    -1,     8,    29,    -1,
      31,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    47,   475,    -1,
      31,    -1,    -1,    34,    35,    -1,   207,   208,   209,    59,
      60,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    76,     3,     4,     5,
       6,    -1,     8,    83,   235,    17,    32,    33,   515,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,   255,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,   264,   265,   266,   267,   268,   269,   270,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    59,    60,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
     291,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    83,    29,    30,    31,    15,    16,    17,    -1,   310,
     311,   312,   313,   314,   315,   316,    -1,   594,   595,   596,
     170,    31,     1,    -1,   601,   602,   603,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
     341,   342,   343,   344,    -1,   346,   347,    -1,   349,    -1,
      29,   352,    31,    -1,    -1,    -1,   357,   207,   208,   209,
      -1,   362,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   387,   388,   170,    -1,
      29,    -1,    31,    -1,    -1,    -1,   397,   398,   399,   400,
      -1,   402,   403,    -1,   405,   255,    -1,   408,    -1,    -1,
      -1,    -1,   413,   263,   264,   265,   266,   267,   268,   269,
     270,    -1,    -1,    -1,    -1,   207,   208,   209,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,   439,   440,
      -1,   291,    15,    16,    17,     7,     8,     9,    10,    11,
      12,    13,    14,   235,    -1,    -1,    29,    -1,    31,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,    30,    -1,
      32,    33,    -1,   255,   475,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   265,   266,   267,   268,   269,   270,    -1,
      -1,   341,   342,   343,   344,   345,   346,   347,    -1,   349,
      -1,    -1,   352,    -1,    -1,    -1,    -1,   357,    -1,   291,
      -1,    -1,   362,    -1,   515,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,   310,   311,
     312,   313,   314,   315,   316,    -1,    -1,   387,   388,    30,
      -1,    32,    33,    -1,    -1,    -1,    -1,   397,   398,   399,
     400,   401,   402,   403,    -1,   405,    -1,    -1,   408,   341,
     342,   343,   344,   413,   346,   347,    -1,   349,    -1,    -1,
     352,     7,     8,     9,    10,   357,    12,    13,    14,    -1,
     362,     7,     8,     9,    10,    17,    12,    13,    14,   439,
     440,    -1,    -1,   594,   595,   596,    -1,    -1,    -1,    -1,
     601,   602,   603,    -1,    17,   387,   388,     7,     8,     9,
      10,    11,    12,    13,    14,   397,   398,   399,   400,    51,
     402,   403,    -1,   405,    -1,   475,   408,    59,    60,    -1,
      30,   413,    32,    33,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,   439,   440,    -1,
      73,    -1,    -1,    -1,     1,   515,     3,     4,     5,     6,
      83,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,   475,    31,    -1,    -1,    34,    35,    -1,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,   515,    34,    -1,    -1,    -1,   170,    -1,
      -1,    -1,    -1,    -1,   594,   595,   596,    -1,    -1,    -1,
      -1,   601,   602,   603,    -1,    -1,    -1,   170,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,   207,   208,   209,    -1,    -1,
      29,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,   207,   208,   209,    31,    -1,    -1,
      34,    -1,    -1,   235,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,   594,   595,   596,    -1,    -1,    -1,    -1,   601,
     602,   603,   235,   255,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,   265,   266,   267,    -1,    -1,   270,    50,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    59,    60,
      32,    33,   265,   266,    -1,    -1,    -1,   270,    -1,   291,
       1,    72,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    83,    -1,    15,    16,    17,    -1,   291,   311,
     312,   313,    -1,    -1,   316,    -1,    -1,    -1,    29,    -1,
      31,     8,     9,    10,    11,    12,    13,    14,   311,   312,
      -1,    -1,    -1,   316,    -1,    17,    -1,    -1,    -1,   341,
     342,   343,    -1,    -1,    -1,    32,    33,   349,    -1,    -1,
     352,    -1,    -1,    -1,    -1,   357,    -1,    -1,   341,   342,
     362,    -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,   352,
      -1,    -1,    -1,    55,   357,    -1,    -1,    59,    60,   362,
      -1,    -1,    -1,    -1,    -1,   387,   388,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,   397,   398,   399,    80,    -1,
      -1,    83,    -1,   405,   387,   388,   408,     3,     4,     5,
       6,   413,     8,    -1,   397,   398,    -1,    -1,    -1,    15,
      16,    17,   405,    -1,    -1,   408,   207,   208,   209,    -1,
     413,    -1,    -1,    -1,    -1,    31,    -1,   439,   440,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,   235,    -1,   439,   440,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,   475,   255,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,   170,   270,
      -1,     1,   475,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
     291,    -1,    -1,   515,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    31,    -1,    -1,    -1,   207,   208,   209,    -1,    -1,
      -1,   312,   515,    -1,    -1,   316,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,   235,    -1,    -1,    -1,    22,    23,    24,
     341,    26,    27,    -1,    -1,    -1,    31,    -1,   349,    34,
      -1,   352,    -1,   255,    -1,     1,   357,     3,     4,     5,
       6,   362,     8,    -1,    -1,    -1,    -1,    -1,   270,    15,
      16,    17,   594,   595,   596,    -1,    -1,    -1,    -1,   601,
     602,   603,    -1,    29,    -1,    31,   387,   388,    -1,   291,
      -1,   594,   595,   596,    -1,    -1,   397,    -1,   601,   602,
     603,    -1,    -1,    -1,   405,    -1,    -1,   408,    -1,    -1,
      -1,    -1,   413,    -1,   316,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,   439,   440,
      22,    23,    24,    25,    26,    27,    -1,   349,    -1,    31,
     352,    -1,    34,    -1,     1,   357,     3,     4,     5,     6,
     362,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,   475,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,   387,   388,    34,    35,    -1,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,   405,    -1,    -1,   408,    -1,    15,    16,
      17,   413,    19,    20,   515,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,   439,   440,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     1,    -1,     3,     4,     5,     6,     1,     8,     3,
       4,     5,     6,   475,     8,    15,    16,    17,    -1,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,   594,   595,   596,    -1,    31,    -1,    -1,
     601,   602,   603,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,   515,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,   594,   595,   596,    -1,    -1,    -1,    -1,   601,
     602,   603,     1,    31,     3,     4,     5,     6,    -1,     8,
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
      31,     0,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,     0,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,     0,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
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
      -1,    31,    -1,     1,    34,     3,     4,     5,     6,    -1,
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
      25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
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
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,     1,
      34,     3,     4,     5,     6,     1,     8,     3,     4,     5,
       6,    -1,     8,    15,    16,    17,    -1,    -1,    -1,    15,
      16,    17,    -1,     1,    -1,     3,     4,     5,     6,    31,
       8,    -1,    -1,    -1,    -1,    31,    -1,    15,    16,    17,
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
      -1,    -1,    -1,    31,    15,    16,    17,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      31,    15,    16,    17,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,
      17,    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
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
      -1,    30,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    30,    -1,    32,    33,     7,     8,
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
      12,    13,    14,    -1,    -1,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    30,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    30,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    30,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    30,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    30,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    30,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    30,    -1,    32,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      30,    -1,    32,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    30,    -1,    32,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    30,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    30,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
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
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      32,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    29,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    29,    30,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    29,    30,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    29,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    29,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    29,    30,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    29,    30,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    29,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    30,     7,     8,     9,    10,    11,    12,    13,
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
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    29
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
      11,    12,    13,    14,    29,    30,    21,    21,    31,    31,
      31,    31,     1,    61,    76,     1,    61,    50,     0,     1,
      39,    29,    11,    10,    12,     9,     8,    13,    14,     7,
      30,    70,     1,    31,    76,    29,    31,    76,    70,     1,
      69,    70,     1,    67,     1,    65,     1,    64,     1,    66,
      67,    67,     1,    63,     1,    76,     1,    18,    61,    79,
       1,    61,     1,    61,    62,    29,    29,    32,    32,     1,
      25,    40,    51,    52,    53,    54,    58,    77,     1,    64,
       1,    65,     1,    66,     1,    67,     1,    69,     1,    67,
       1,    67,     1,    70,     1,    63,     1,    61,    73,    74,
      29,    30,    44,    29,    30,    31,    32,    32,    32,    32,
      32,    32,    32,    29,    29,    25,    54,    35,    53,    76,
      33,    32,     1,     1,    46,    47,    48,    76,    77,     1,
      42,    29,     1,    29,    29,     1,    29,     1,    29,    25,
      54,    25,    54,     1,    62,     1,    62,    54,    61,    45,
      33,    76,    46,    54,    25,    54,    25,    29,    29,    29,
      32,    48,    43,    54,    54,    62,    62,     1,    62,    49,
      32,    32,    32,    32,    32,    49,    54,    54,    54,    54,
       6,     3,     4,     5,     6,    31,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    75,    76,    78,     6,
       6,     3,     4,     5,     6,    31,    71,    72,    75,    76,
      78,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      30,    19,    20,    22,    23,    24,    26,    27,    34,    49,
      55,    56,    57,    59,    60,    61,    76,     3,     4,     5,
       6,    31,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    75,    76,    78,    29,     1,    29,     7,     8,
       9,    10,    11,    12,    13,    14,    30,     6,    19,    20,
       1,    22,    23,    24,    26,    27,    34,    49,    55,    56,
      57,    59,    60,    61,    29,    30,     1,     1,    61,     1,
      61,    11,    10,    12,     9,     8,    13,    14,     7,    30,
      70,     1,    31,     1,    61,    70,     1,    31,     3,     4,
       5,     6,    31,    70,    71,    72,    75,    76,    78,     1,
      69,    70,     1,    67,     1,    65,     1,    64,     1,    66,
      67,    67,     1,    63,    21,    21,    31,    31,    31,    31,
       1,    61,    50,    29,    76,     1,    61,    11,    10,    12,
       9,     8,    13,    14,     7,    30,    70,     1,    31,     3,
       4,     5,     6,    31,    70,    71,    72,    75,    76,    78,
       1,    69,    70,     1,    67,     1,    65,     1,    64,     1,
      66,    67,    67,     1,    63,    21,    21,    29,    31,    31,
      31,    31,     1,    61,    50,    29,     1,    32,    32,     1,
      64,     1,    65,     1,    66,     1,    67,     1,    69,     1,
      67,     1,    67,     1,    70,     1,    63,    74,    32,    32,
      74,     1,    61,    70,     1,    31,     1,    76,     1,    61,
      79,     1,    61,     1,    62,    29,    29,    51,    29,    30,
      32,    32,     1,    64,     1,    65,     1,    66,     1,    67,
       1,    69,     1,    67,     1,    67,     1,    70,     1,    63,
      74,     1,    61,    70,     1,    31,     1,    76,     1,    61,
      79,     1,    61,     1,    62,    29,    29,    51,    32,    32,
      32,    32,    74,    32,    32,    32,    32,    32,    32,    32,
      29,    29,    35,     1,    32,    32,    32,    74,    32,    32,
      32,    32,    32,    32,    32,    29,    29,    35,    32,    29,
       1,    29,    29,     1,    29,     1,    29,    25,    54,    25,
      54,    62,     1,    62,    32,    29,     1,    29,    29,     1,
      29,     1,    29,    25,    54,    25,    54,    62,     1,    62,
      54,    25,    54,    25,    29,    29,    29,    54,    25,    54,
      25,    29,    29,    29,    54,    54,    62,    62,     1,    62,
      54,    54,    62,    62,     1,    62,    32,    32,    32,    32,
      32,    32,    32,    32,    54,    54,    54,    54,    54,    54,
      54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    38,    38,    39,    39,    39,
      40,    40,    40,    40,    40,    42,    43,    41,    44,    45,
      41,    46,    46,    47,    47,    47,    48,    48,    48,    50,
      49,    51,    51,    52,    52,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    57,    57,    57,    57,
      58,    58,    59,    59,    60,    60,    60,    60,    61,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    64,    64,
      64,    64,    65,    65,    65,    65,    66,    66,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    68,
      68,    69,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    74,    74,    75,    75,
      75,    75,    75,    76,    77,    77,    77,    77,    78,    78,
      78,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       3,     2,     4,     4,     3,     0,     0,     8,     0,     0,
       7,     0,     1,     3,     1,     1,     2,     1,     1,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     5,     5,     5,     5,
       5,     5,     2,     2,     5,     7,     6,     5,     7,     6,
       2,     3,     3,     3,     9,     9,     9,     9,     1,     3,
       3,     3,     0,     1,     1,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     1,     2,     1,     1,     1,
       1,     1,     4,     3,     1,     1,     1,     0,     1,     1,
       3,     3,     2,     1,     1,     1,     2,     2,     1,     1,
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
#line 130 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3649 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3655 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3661 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3667 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3673 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3679 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3685 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3691 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3697 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3703 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3709 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3715 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3721 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3727 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3733 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3739 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3745 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3751 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3757 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3763 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3769 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_1: /* @1  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3775 "src/bison/grammar.c"
        break;

    case YYSYMBOL_46_param_list_opt: /* param_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3781 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3787 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3793 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3799 "src/bison/grammar.c"
        break;

    case YYSYMBOL_51_block_item_list_opt: /* block_item_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3805 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3811 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3817 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3823 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3829 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3835 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3841 "src/bison/grammar.c"
        break;

    case YYSYMBOL_else_error: /* else_error  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3847 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3853 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3859 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3865 "src/bison/grammar.c"
        break;

    case YYSYMBOL_62_expression_opt: /* expression.opt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3871 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3877 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3883 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3889 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3895 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3901 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3907 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3913 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3919 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3925 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3931 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3937 "src/bison/grammar.c"
        break;

    case YYSYMBOL_74_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3943 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3949 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 130 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3955 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3961 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3967 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3973 "src/bison/grammar.c"
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
#line 4282 "src/bison/grammar.c"
    break;

  case 4: /* prog: error  */
#line 137 "src/bison/grammar.y"
            {
        // idk if this is the best solution
        // actually dont work properly
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
    }
#line 4292 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration_list external_declaration  */
#line 144 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4298 "src/bison/grammar.c"
    break;

  case 6: /* external_declaration_list: external_declaration  */
#line 145 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4304 "src/bison/grammar.c"
    break;

  case 9: /* external_declaration: statement  */
#line 150 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4314 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type id ';'  */
#line 157 "src/bison/grammar.y"
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
            (yyval.ast) = ast_declaration_init((yyloc), 
                ast_symref_init((yylsp[-1]), context_declare_variable(current_context, (yyvsp[-1].sym)))
            );
        }
        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 4341 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 179 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4351 "src/bison/grammar.c"
    break;

  case 12: /* var_declaration: type id '=' error  */
#line 184 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4362 "src/bison/grammar.c"
    break;

  case 13: /* var_declaration: id id '=' error  */
#line 190 "src/bison/grammar.y"
                      {
        show_error_range((yylsp[-3]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-3].sym)->name);
        symbol_free((yyvsp[-3].sym));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4373 "src/bison/grammar.c"
    break;

  case 14: /* var_declaration: id id ';'  */
#line 196 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-2]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-2].sym)->name);
        symbol_free((yyvsp[-2].sym));
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 4384 "src/bison/grammar.c"
    break;

  case 15: /* @1: %empty  */
#line 204 "src/bison/grammar.y"
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
                (yyval.ast) = ast_symref_init((yylsp[-1]), declared);
            }
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 4425 "src/bison/grammar.c"
    break;

  case 16: /* $@2: %empty  */
#line 239 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4431 "src/bison/grammar.c"
    break;

  case 17: /* func_declaration: type id '(' @1 param_list.opt $@2 ')' compound_stmt  */
#line 239 "src/bison/grammar.y"
                                                              {
        (yyval.ast) = ast_userfunc_init((yyloc), current_context, (yyvsp[-4].ast), ast_params_init((yylsp[-3]), (yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4441 "src/bison/grammar.c"
    break;

  case 18: /* $@3: %empty  */
#line 244 "src/bison/grammar.y"
               {
        previous_context = current_context;
        list_push(&contexts, context_init("unnamed-func"));
        current_context = list_peek_last(&contexts);
        context_push_scope(current_context);
    }
#line 4452 "src/bison/grammar.c"
    break;

  case 19: /* $@4: %empty  */
#line 249 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4458 "src/bison/grammar.c"
    break;

  case 20: /* func_declaration: type '(' $@3 param_list.opt $@4 ')' compound_stmt  */
#line 249 "src/bison/grammar.y"
                                                              {
        show_error_range((yylsp[-5]), "expected identifier before " WHT "'('" RESET "\n");
        free((yyvsp[-6].pchar));
        LIST_FREE((yyvsp[-3].list), { ast_free(__IT__->data); });
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
        current_context = previous_context;
    }
#line 4471 "src/bison/grammar.c"
    break;

  case 21: /* param_list.opt: %empty  */
#line 259 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4477 "src/bison/grammar.c"
    break;

  case 23: /* params_list: params_list ',' param_decl  */
#line 263 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4483 "src/bison/grammar.c"
    break;

  case 24: /* params_list: param_decl  */
#line 264 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4489 "src/bison/grammar.c"
    break;

  case 25: /* params_list: error  */
#line 265 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4498 "src/bison/grammar.c"
    break;

  case 26: /* param_decl: type id  */
#line 271 "src/bison/grammar.y"
                    {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        if (sym) {
            show_error_range((yylsp[0]), "redefinition of parameter " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            symbol_update_type((yyvsp[0].sym), symbol_type_from_str((yyvsp[-1].pchar)));
            (yyval.ast) = ast_symref_init((yyloc), context_declare_variable(current_context, (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 4515 "src/bison/grammar.c"
    break;

  case 27: /* param_decl: type  */
#line 283 "src/bison/grammar.y"
           {
        show_error_range((yylsp[0]), "expected identifier after " BGRN "'%s'" RESET "\n", (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
        (yyval.ast) = NULL;
    }
#line 4525 "src/bison/grammar.c"
    break;

  case 28: /* param_decl: id  */
#line 288 "src/bison/grammar.y"
         {
        show_error_range((yylsp[0]), "unknown type name for " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
        symbol_free((yyvsp[0].sym));
        (yyval.ast) = NULL;
    }
#line 4535 "src/bison/grammar.c"
    break;

  case 29: /* $@5: %empty  */
#line 295 "src/bison/grammar.y"
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
#line 4553 "src/bison/grammar.c"
    break;

  case 30: /* compound_stmt: '{' $@5 block_item_list.opt '}'  */
#line 307 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyloc), (yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 4565 "src/bison/grammar.c"
    break;

  case 31: /* block_item_list.opt: block_item_list  */
#line 316 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4571 "src/bison/grammar.c"
    break;

  case 32: /* block_item_list.opt: %empty  */
#line 317 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4577 "src/bison/grammar.c"
    break;

  case 33: /* block_item_list: block_item_list block_item  */
#line 320 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4583 "src/bison/grammar.c"
    break;

  case 34: /* block_item_list: block_item  */
#line 321 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4589 "src/bison/grammar.c"
    break;

  case 44: /* io_stmt: READ '(' id ')' ';'  */
#line 337 "src/bison/grammar.y"
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
#line 4605 "src/bison/grammar.c"
    break;

  case 45: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 348 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4614 "src/bison/grammar.c"
    break;

  case 46: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 352 "src/bison/grammar.y"
                                       {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4623 "src/bison/grammar.c"
    break;

  case 47: /* io_stmt: WRITE '(' error ')' ';'  */
#line 356 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4633 "src/bison/grammar.c"
    break;

  case 48: /* io_stmt: READ '(' error ')' ';'  */
#line 361 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected identifier before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4643 "src/bison/grammar.c"
    break;

  case 49: /* io_stmt: READ '(' id ')' error  */
#line 366 "src/bison/grammar.y"
                            {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4654 "src/bison/grammar.c"
    break;

  case 50: /* io_stmt: WRITE '(' expression ')' error  */
#line 372 "src/bison/grammar.y"
                                     {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4665 "src/bison/grammar.c"
    break;

  case 51: /* io_stmt: WRITE '(' string_literal ')' error  */
#line 378 "src/bison/grammar.y"
                                         {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4676 "src/bison/grammar.c"
    break;

  case 52: /* expr_stmt: expression ';'  */
#line 386 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 4682 "src/bison/grammar.c"
    break;

  case 53: /* expr_stmt: error ';'  */
#line 387 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 4691 "src/bison/grammar.c"
    break;

  case 54: /* cond_stmt: IF '(' expression ')' statement  */
#line 393 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 4699 "src/bison/grammar.c"
    break;

  case 55: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 396 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4707 "src/bison/grammar.c"
    break;

  case 56: /* cond_stmt: IF '(' expression ')' ELSE statement  */
#line 399 "src/bison/grammar.y"
                                           {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-3].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4718 "src/bison/grammar.c"
    break;

  case 57: /* cond_stmt: IF '(' error ')' statement  */
#line 405 "src/bison/grammar.y"
                                            {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4728 "src/bison/grammar.c"
    break;

  case 58: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 410 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4739 "src/bison/grammar.c"
    break;

  case 59: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 416 "src/bison/grammar.y"
                                      {
        show_error((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4749 "src/bison/grammar.c"
    break;

  case 60: /* else_error: ELSE statement  */
#line 423 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4759 "src/bison/grammar.c"
    break;

  case 61: /* else_error: error ELSE statement  */
#line 428 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4769 "src/bison/grammar.c"
    break;

  case 62: /* jmp_stmt: RETURN expression ';'  */
#line 434 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyloc), (yyvsp[-1].ast)); }
#line 4775 "src/bison/grammar.c"
    break;

  case 63: /* jmp_stmt: RETURN error ';'  */
#line 435 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 4784 "src/bison/grammar.c"
    break;

  case 64: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 441 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init((yyloc), current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4792 "src/bison/grammar.c"
    break;

  case 65: /* iter_stmt: FOR '(' error ';' expression.opt ';' expression.opt ')' statement  */
#line 444 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-6]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4804 "src/bison/grammar.c"
    break;

  case 66: /* iter_stmt: FOR '(' expression.opt ';' error ';' expression.opt ')' statement  */
#line 451 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-4]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4816 "src/bison/grammar.c"
    break;

  case 67: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' error ')' statement  */
#line 458 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4828 "src/bison/grammar.c"
    break;

  case 69: /* expression: unary_expr '=' logical_or_expr  */
#line 468 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyloc), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 4834 "src/bison/grammar.c"
    break;

  case 70: /* expression: unary_expr '=' error  */
#line 469 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4844 "src/bison/grammar.c"
    break;

  case 71: /* expression: error '=' logical_or_expr  */
#line 474 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-2]), "expected expression before " WHT "'='" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4854 "src/bison/grammar.c"
    break;

  case 72: /* expression.opt: %empty  */
#line 481 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 4860 "src/bison/grammar.c"
    break;

  case 75: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 486 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4869 "src/bison/grammar.c"
    break;

  case 76: /* logical_or_expr: logical_or_expr OR error  */
#line 490 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4879 "src/bison/grammar.c"
    break;

  case 77: /* logical_or_expr: error OR logical_and_expr  */
#line 495 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4889 "src/bison/grammar.c"
    break;

  case 79: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 503 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4898 "src/bison/grammar.c"
    break;

  case 80: /* logical_and_expr: logical_and_expr AND error  */
#line 507 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4908 "src/bison/grammar.c"
    break;

  case 81: /* logical_and_expr: error AND eq_expr  */
#line 512 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4918 "src/bison/grammar.c"
    break;

  case 83: /* eq_expr: eq_expr EQ rel_expr  */
#line 520 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4927 "src/bison/grammar.c"
    break;

  case 84: /* eq_expr: eq_expr EQ error  */
#line 524 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4937 "src/bison/grammar.c"
    break;

  case 85: /* eq_expr: error EQ rel_expr  */
#line 529 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4947 "src/bison/grammar.c"
    break;

  case 87: /* rel_expr: rel_expr REL list_expr  */
#line 537 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4956 "src/bison/grammar.c"
    break;

  case 88: /* rel_expr: rel_expr REL error  */
#line 541 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4966 "src/bison/grammar.c"
    break;

  case 89: /* rel_expr: error REL list_expr  */
#line 546 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4976 "src/bison/grammar.c"
    break;

  case 91: /* list_expr: add_expr DL_DG list_expr  */
#line 554 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4985 "src/bison/grammar.c"
    break;

  case 92: /* list_expr: add_expr COLON list_expr  */
#line 558 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4994 "src/bison/grammar.c"
    break;

  case 93: /* list_expr: add_expr DL_DG error  */
#line 562 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5004 "src/bison/grammar.c"
    break;

  case 94: /* list_expr: add_expr COLON error  */
#line 567 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5014 "src/bison/grammar.c"
    break;

  case 95: /* list_expr: error DL_DG list_expr  */
#line 572 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5024 "src/bison/grammar.c"
    break;

  case 96: /* list_expr: error COLON list_expr  */
#line 577 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5034 "src/bison/grammar.c"
    break;

  case 98: /* add_expr: add_expr ADD mult_expr  */
#line 585 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5043 "src/bison/grammar.c"
    break;

  case 99: /* add_expr: add_expr ADD error  */
#line 589 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5053 "src/bison/grammar.c"
    break;

  case 100: /* add_expr: error ADD mult_expr  */
#line 594 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5063 "src/bison/grammar.c"
    break;

  case 102: /* mult_expr: mult_expr MULT unary_expr  */
#line 602 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5072 "src/bison/grammar.c"
    break;

  case 103: /* mult_expr: mult_expr MULT error  */
#line 606 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5082 "src/bison/grammar.c"
    break;

  case 104: /* mult_expr: error MULT unary_expr  */
#line 611 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5092 "src/bison/grammar.c"
    break;

  case 106: /* unary_expr: unary_ops unary_expr  */
#line 619 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5101 "src/bison/grammar.c"
    break;

  case 112: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 632 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-3].sym));
        AST *params = ast_params_init((yylsp[-1]), (yyvsp[-1].list));
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
                (yyval.ast) = ast_funcall_init((yyloc), ast_symref_init((yylsp[-3]), sym), params);
            }
        }
        symbol_free((yyvsp[-3].sym));
    }
#line 5124 "src/bison/grammar.c"
    break;

  case 113: /* arg_expr_list: arg_expr_list ',' expression  */
#line 652 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5130 "src/bison/grammar.c"
    break;

  case 114: /* arg_expr_list: expression  */
#line 653 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5136 "src/bison/grammar.c"
    break;

  case 115: /* arg_expr_list: error  */
#line 654 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5145 "src/bison/grammar.c"
    break;

  case 117: /* arg_expr_list.opt: %empty  */
#line 661 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5151 "src/bison/grammar.c"
    break;

  case 118: /* primary_expr: id  */
#line 664 "src/bison/grammar.y"
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
#line 5166 "src/bison/grammar.c"
    break;

  case 120: /* primary_expr: '(' expression ')'  */
#line 675 "src/bison/grammar.y"
                         {
        if ((yyvsp[-1].ast)) {
            --(yyvsp[-1].ast)->rule_pos.first_column;
            ++(yyvsp[-1].ast)->rule_pos.last_column;
        }
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 5178 "src/bison/grammar.c"
    break;

  case 121: /* primary_expr: '(' error ')'  */
#line 682 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5187 "src/bison/grammar.c"
    break;

  case 122: /* primary_expr: id error  */
#line 686 "src/bison/grammar.y"
               {
        show_error_range((yylsp[0]), "expected " WHT "';'" RESET "\n");
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 5197 "src/bison/grammar.c"
    break;

  case 126: /* type: INT LIST  */
#line 698 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5209 "src/bison/grammar.c"
    break;

  case 127: /* type: FLOAT LIST  */
#line 705 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5221 "src/bison/grammar.c"
    break;

  case 128: /* constant: NUMBER_REAL  */
#line 714 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init((yyloc), K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5227 "src/bison/grammar.c"
    break;

  case 129: /* constant: NUMBER_INT  */
#line 715 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init((yyloc), K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5233 "src/bison/grammar.c"
    break;

  case 130: /* constant: NIL  */
#line 716 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init((yyloc), K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5239 "src/bison/grammar.c"
    break;

  case 131: /* string_literal: STR_LITERAL  */
#line 719 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyloc), (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5248 "src/bison/grammar.c"
    break;


#line 5252 "src/bison/grammar.c"

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

#line 725 "src/bison/grammar.y"


void yyerror(int l, int c, const char *s, ...) {
    error_cursor = (Cursor){.line=l, .col=c};
    last_line_ref = curr_line_buffer;
    // enable error print when bison calls yyerror()
    /* if (s) {
        CIPL_PRINTF_COLOR(BRED, "%s\n" BYEL "%s:%d:%d: at line: %s\n",
                          s, filename, cursor.line, cursor.col, last_line_ref);
    }  */
    
    // prevent count up errors when bison calls yyerror()
    if (!s) {
        ++errors_count;
    }
}
