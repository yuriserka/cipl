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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   10216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  647

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
     157,   181,   186,   192,   198,   206,   242,   206,   247,   252,
     247,   262,   263,   266,   267,   268,   274,   288,   293,   300,
     300,   321,   322,   325,   326,   329,   330,   331,   334,   335,
     336,   337,   338,   339,   342,   353,   357,   361,   366,   371,
     377,   383,   389,   394,   401,   402,   408,   411,   414,   420,
     425,   431,   436,   442,   447,   454,   455,   461,   464,   471,
     478,   485,   489,   495,   496,   497,   502,   509,   510,   513,
     514,   518,   523,   530,   531,   535,   540,   547,   548,   552,
     557,   564,   565,   569,   574,   581,   582,   586,   590,   595,
     600,   605,   612,   613,   617,   622,   629,   630,   634,   639,
     646,   647,   653,   654,   655,   656,   659,   660,   680,   681,
     682,   688,   689,   692,   702,   703,   710,   714,   721,   724,
     725,   726,   733,   742,   743,   744,   747
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

#define YYPACT_NINF (-399)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-137)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    4173,   315,  9455,  9463,  9487,  3854,   663,  2938,  3357,  3976,
     164,   310,     8,     9,    10,    11,  1920,  2680,    85,    75,
    5868,  5900,  5932,  5964,  5996,  6028,  6060,  6092,  6124,  6156,
    6188,   -21,    -5,   289,   745,   636,  1652,   889,  3632,  9495,
    8289,  9519,  9527,  3901,   192,  9551,  8306,  3196,  3325,  3735,
    4130,  4154,  3325,  3325,  6220,  4254,   238,   327,  6252,   116,
    6284,   258,  6316,  4260,  6348,  3174,  9559,   101,  3107,  1987,
      60,   478,  -399,  9583,  6380,  6412,  4342,  4383,  7500,  7506,
    7524,  7541,  7558,  7575,  7592,  9591,  9615,    63,    52,  6444,
     112,   556,  9815,   107,  9838,  9846,   729,  1684,  3720,   936,
    3087,   358,   814,  1724,  2032,  2064,  2299,   214,   136,   140,
    2210,   152,   178,   184,  2590,   187,  1450,   228,   242,  6476,
    6508,  9623,  9647,  9431,  7404,   514,   212,   557,   918,   953,
    1006,   174,  9869,   541,  9877,  1032,  9900,  2104,  9908,  2412,
    9931,  9939,  9962,  2447,  9970,  2484,  9993, 10001, 10024,   309,
    3605,   351,   379,   249,  6540,   283,   170,  6572,   296,   198,
     284,    22,   306,    69,    98,  1110,  3375,  3286,  6604,  3469,
    7404,  1052,  6636,  1188,    55,  7609,  9655,  6668,   411,   305,
     416,   423,   428,    91,  6700,   170,  6732,  6764,  6796,  6828,
    6860,  6892,  6924,  6956,  7436,  1307,  7436,  1343,  2291,   326,
    9679,   337,  1377,   459,   340,   653,   564,   342,  6988,  7436,
    7020,  7436,   147,   147,   794,   355,   601,   344,  7052,  7084,
     359,   361,  2747,   363,  7116,   355,  7436,  7436,  7436,  7436,
    7148,  7180,  7212,  7244,  7276,  3562,  8885,  8898,  8911,   757,
    7626,   115,   464,   338,   414,   515,   855,   692,  8924,  8323,
    8937,  8950,   830,  8963,   560,   656, 10032, 10055, 10063,   594,
    7643,  8306, 10086, 10094,   984, 10117,   365,  8340,  7660,  7677,
    7694,  7711,  7728,  7677,  7677,  7745,   272,   311,    12,    13,
      14,    17,  7762,    85,  1491,  1571,  1683,  1723,  1758,  1871,
     370,  3901,  3864,  8385,  8399,    24,  7779,   440,   457,   349,
     409,   620,  1413,  8534,  8412,  8357,  8426,  8439,   128,  8453,
    1951,  9687,  2063,  8374,  7796,  7813,  7830,  7847,  7864,  7813,
    7813,  7881,   683,   218,   274,  9711,    18,    21,    27,    46,
    7898,    85,  1797,  2103,  2138,  2177,  2331,  2446,   385,  2251,
     415,  9783,  9807,   396,  8976,   421,  7915,  7932,  7949,  7966,
    7983,  8000,  8017,  8034,  8051,  8989,  9002,    63,  9015,   434,
   10125, 10148,    63,   992,  1461,  1841,  1406,  8068,  2221,  8340,
    2601,  2981,  2926,  9184,   473,  9197,  9210,  1708,   610,  3819,
     353,  3593,   500,  2685,   645,   846,  1053,  3115,   176,   209,
     239,  2483,   182,  2518,  1157,  2631,  8085,  2711,  3529,  9719,
     458,   478,  2823,   697,  9028,   467,  8102,  8119,  8136,  8153,
    8170,  8187,  8204,  8221,  8238,  8466,  8480,    63,  8547,  8561,
    8574,   426,  8255,  8588,  8374,  8601,  8615,   721,  8628,   501,
    8642,  8655,  2088,   773,  3944,  1145,  3834,   740,  2787,   896,
    1087,  1226,  3226,   474,   199,   201,  2557,  2863,   282,  2898,
    1540,  3254,  8272,  3663,  3695,  9743,   485,   478,  3764,  3011,
    9041,  9054,  9223,   532,  9236,   368,  9249,  1080,  9262,  1277,
    9275,  9288,  9301,  1308,  9314,  1344,  9327,  9340,  9353,   254,
     484, 10156, 10179,   489,  9067,   491,  9366,  9379,    63,   512,
     518,  9080,   522,   527,  9093,   534,  1607,   517,  3420,  4065,
     540,  4216,   577,  8493,  8507,  8669,   797,  8682,  1528,  8696,
    1242,  8709,  1422,  8723,  8736,  8750,  1929,  8763,  2308,  8777,
    8790,  8804,   524,   567,  9106,   580,  8817,  8831,    63,   582,
     608,  9119,   617,   638,  9132,   643,  1830,   659,  4019,  4422,
     655,  9145, 10187,  9392,  9405,   665,   666,   105,   688,   114,
     120,  4303,  7308,  3286,  4460,  3808,  4495,  4547,  8520,  8844,
    8858,   707,   712,   127,   717,   145,   153,  7340,  7372,  3286,
    4583,  3958,  4621,  9418,  4658,  4693,  4728,  4763,  4798,  4833,
    4868,  4903,  7404,  4938,  7404,  4973,   718,  9751,   730,  8871,
    5009,  5041,  5073,  5105,  5137,  5169,  5201,  5233,  7468,  5265,
    7468,  5297,   747,  9775,   749,  5329,  7404,  5364,  7404,   147,
     147,  2363,  5400,  7468,  5432,  7468,   147,   147,  3060,  5464,
    5499,   748,   754,  9158,   759,  5535,  5567,   761,   769,  9171,
     788,  7404,  7404,  7404,  7404,  7468,  7468,  7468,  7468,  5599,
    5634,  5669,  5704,  5740,  5772,  5804,  5836
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
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
    -399,  -399,  -399,   804,    30,  -399,  -399,  -399,  -399,  -399,
     647,  -399,   630,    83,  -278,  -398,  -399,   719,    76,    26,
     125,   177,  -399,   181,   236,     0,  -140,  4040,  3927,  3758,
    3533,  2899,  3308,  3145,  1216,  1596,  1976,  -399,  -355,  2356,
     833,     1,  2736,  -390
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   125,    23,   185,   217,   156,   204,
     179,   180,   181,   284,    71,   126,   127,   128,   129,   285,
     286,   287,   130,   288,   289,   290,   118,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   152,   153,    42,
      68,   131,    45,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    44,   480,   500,   493,   401,    76,   483,    75,    58,
      60,    62,    64,   391,   393,   395,    67,    70,   397,   447,
      31,    44,   449,   187,   -73,  -128,    26,   199,   451,   201,
      22,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,    59,
      61,    63,    65,   392,   394,   396,    26,   453,   398,   448,
      22,   188,   450,   457,  -128,  -128,  -128,  -128,   452,   540,
     533,   112,   523,   115,   150,   117,   292,   293,   294,   295,
     190,     6,   220,   221,   223,    72,    25,   454,     7,     8,
       9,   154,   155,    24,   339,   340,   -29,   151,   -29,   -29,
     -29,   -29,   122,   -29,   296,  -122,    25,   322,   191,   192,
     -29,   -29,   -29,    24,   -29,   -29,   575,   -29,   -29,   -29,
     -29,   -29,   -29,   -18,    46,   578,   -29,   108,   -18,   -29,
     -29,   580,   266,   -27,   -27,    27,   346,   193,   591,   416,
     120,   -18,   -18,   545,   576,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,   579,   -18,    27,   594,   -73,   342,   581,
     236,   237,   238,   239,   596,     6,   592,   183,  -123,   417,
    -123,  -123,     7,     8,     9,   338,   338,   117,   160,   117,
    -129,   178,   161,   561,   595,   203,   322,    28,   240,   -77,
     254,    29,   597,   489,  -136,    56,   183,   346,   266,   323,
     324,   333,   333,  -129,    31,  -129,    31,    28,   255,   -15,
     171,    29,   -21,   312,   -15,  -131,   183,  -132,   -76,    31,
     163,    31,   343,   343,   343,  -131,   164,   -15,   -15,   166,
      26,    89,    26,    90,  -129,    76,    31,    31,    31,    31,
     -15,  -131,  -131,  -132,  -132,    26,    30,    26,  -131,   444,
     345,   195,   197,   -76,  -131,  -132,   202,   172,   332,   332,
    -129,  -129,    26,    26,    26,    26,    30,   -78,   497,   110,
     359,   236,   237,   238,   239,   346,     6,  -131,  -132,  -131,
     208,   169,   210,     7,     8,     9,   111,    24,  -129,    24,
    -130,   176,   400,   529,   177,   218,   -74,   219,   266,   240,
     334,   334,    24,   389,    24,   445,   405,   184,   224,    77,
     -79,  -129,   231,   232,   233,   234,  -130,  -130,   230,    24,
      24,    24,    24,   186,   537,    -4,  -130,  -130,   -79,    27,
      76,    27,    46,    47,    48,    49,    50,    51,    52,    53,
     456,    57,   390,  -132,    27,   189,    27,   -19,   -74,  -130,
    -130,  -130,   335,   335,    54,    55,   336,   336,   -83,   -83,
     348,    27,    27,    27,    27,   212,  -132,   151,  -132,   -83,
     -83,   408,   151,   -86,   -86,   348,   214,   485,    77,   -82,
     -83,    28,   215,    28,   -16,    29,   225,    29,   -84,   -84,
     348,   -83,   -83,  -119,  -119,   -86,    28,   -82,    28,    18,
      29,   226,    29,   227,   492,   229,   495,  -128,   117,   402,
     -84,   337,   337,    28,    28,    28,    28,    29,    29,    29,
      29,  -121,   175,   586,   458,   588,   459,   151,   409,   -87,
     -87,   -87,   525,   349,   -87,   -87,   -87,  -128,   -78,   602,
      30,   604,    30,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,   -87,   -87,   -25,   -25,    30,   -87,    30,   -22,   205,
     532,   406,   535,   461,   117,   -24,   -24,  -128,  -128,  -128,
     -28,   -28,    30,    30,    30,    30,   482,   407,   -79,   621,
     622,   624,   -73,   -73,   347,   -79,   627,   628,   630,   123,
     267,     2,     3,     4,     5,   406,     6,   499,   151,   -79,
     -79,  -118,  -118,     7,     8,     9,   -79,   276,   277,   504,
     278,   279,   280,   124,   281,   282,   -76,   -76,   313,    17,
     347,   -82,   283,   -32,   539,   -35,   541,   -35,   -35,   -35,
     -35,   542,   -35,   544,   -91,   -91,   -91,   -91,   151,   -35,
     -35,   -35,   -82,   -35,   -35,   406,   -35,   -35,   -35,   -35,
     -35,   -35,   347,   -80,   546,   -35,   555,   -91,   -35,   -35,
     547,    77,   -80,   117,   549,   117,   -74,   -74,   123,   550,
       2,     3,     4,     5,   -80,     6,   552,   338,   338,   117,
     -80,   117,     7,     8,     9,   556,   276,   277,   557,   278,
     279,   280,   124,   281,   282,   157,   158,   159,    17,  -128,
    -128,   283,   -31,   333,   333,  -128,   -26,   -26,   338,   558,
     338,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,   343,
     343,   343,   560,   338,   562,   338,   343,   343,   343,   -94,
     -94,   -94,   -94,  -128,   333,  -128,   333,   583,   585,   -91,
     -91,   -91,   -91,   -23,   -23,   338,   338,   338,   338,   333,
     563,   333,   -94,   599,   601,    79,   -87,   -87,   -87,   565,
     332,   332,   -91,   -91,   349,   -90,   -90,   -90,   605,   322,
     607,   333,   333,   333,   333,   -87,  -114,  -114,  -114,  -114,
     566,  -114,   323,   324,   612,   568,   614,   -90,  -114,  -114,
    -114,   332,   619,   332,   620,  -128,  -128,  -128,   571,   625,
     572,   626,   334,   334,  -114,   574,   332,   573,   332,   353,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,   639,   640,   641,
     642,   643,   644,   645,   646,  -128,  -128,   577,   332,   332,
     332,   332,   527,   334,  -102,   334,   501,   502,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,    46,    47,   334,   589,
     334,   590,    52,    53,   335,   335,   593,   609,   336,   336,
     407,   -82,   528,  -123,  -123,   -83,   -83,    78,  -128,   611,
     334,   334,   334,   334,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,   -82,   -82,   -83,   335,   616,   335,   618,   336,
     631,   336,   -94,   -94,   -94,   -94,   632,  -128,  -128,  -128,
     335,   634,   335,   635,   336,   222,   336,   236,   237,   238,
     239,   636,     6,   337,   337,   -94,   -94,   407,   -80,     7,
       8,     9,   335,   335,   335,   335,   336,   336,   336,   336,
     638,    46,    47,    48,    74,   240,   -77,    52,    53,   -80,
     -80,   356,   207,    43,   337,   216,   337,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,     0,   173,     0,     0,   337,
     252,   337,     0,    43,     0,  -101,  -101,  -101,  -101,     0,
    -123,   357,  -123,   350,   -95,   -95,   -95,   -95,   351,   352,
       0,   337,   337,   337,   337,     0,    88,    91,  -101,   264,
     264,   264,   264,   264,   264,   264,   264,   -95,   264,     0,
       0,     0,   109,     0,   252,     0,   252,    80,   -95,   -95,
     -95,   -95,    81,    82,   291,   409,   -90,   -90,   -90,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   -95,   -34,
     308,   -34,   -34,   -34,   -34,     0,   -34,     0,   -90,   -90,
       0,     0,     0,   -34,   -34,   -34,     0,   -34,   -34,     0,
     -34,   -34,   -34,   -34,   -34,   -34,   -86,   -86,    78,   -34,
       0,     0,   -34,   -34,   -36,     0,   -36,   -36,   -36,   -36,
     291,   -36,     0,     0,   174,   -86,     0,     0,   -36,   -36,
     -36,     0,   -36,   -36,     0,   -36,   -36,   -36,   -36,   -36,
     -36,     0,     0,     0,   -36,   361,     0,   -36,   -36,   182,
       0,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,   -37,   308,   -37,
     -37,   -37,   -37,  -123,   -37,   362,   206,     0,   182,     0,
       0,   -37,   -37,   -37,  -134,   -37,   -37,     0,   -37,   -37,
     -37,   -37,   -37,   -37,     0,     0,     0,   -37,   182,     0,
     -37,   -37,   -84,   -84,    78,   252,   252,   252,     0,     0,
       0,     0,     0,   -63,     0,   -63,   -63,   -63,   -63,     0,
     -63,   -84,  -100,  -100,  -100,  -100,     0,   -63,   -63,   -63,
       0,   -63,   -63,   252,   -63,   -63,   -63,   -63,   -63,   -63,
       0,     0,   252,   -63,     0,  -100,   -63,   -63,     0,   349,
     -88,   -88,   -88,   252,   264,     0,  -101,  -101,  -101,  -101,
     372,   372,   372,   372,   372,   372,   372,   372,   372,     0,
       0,   325,   -88,     2,     3,     4,   235,     0,     6,  -101,
    -101,     0,     0,     0,   403,     7,     8,     9,     0,   252,
       0,     0,   326,   327,   328,   194,   329,   330,   308,     0,
       0,    17,     0,     0,   331,     0,   427,   427,   427,   427,
     427,   427,   427,   427,   427,   -86,   -86,   408,   491,     0,
     236,   237,   238,   239,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,   111,     0,   -86,   -86,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   240,   -33,
     308,   -33,   -33,   -33,   -33,   308,   -33,     0,     0,     0,
     252,     0,   372,   -33,   -33,   -33,     0,   -33,   -33,     0,
     -33,   -33,   -33,   -33,   -33,   -33,     0,     0,     0,   -33,
       0,     0,   -33,   -33,     0,   490,     0,   252,     0,   252,
       0,     0,     0,   248,   291,  -100,  -100,  -100,  -100,   427,
     427,   427,   427,   427,   427,   427,   427,   427,     0,     0,
     308,   409,   -88,   -88,   -88,   252,    85,   427,  -100,  -100,
       0,     0,    92,    95,    95,    95,    95,    95,    95,    95,
       0,    95,     0,     0,   -88,   -88,     0,   248,     0,   248,
       0,   530,     0,   252,     0,   252,   -92,   -92,   -92,   -92,
     291,     0,    95,    95,    95,    95,    95,    95,    95,   147,
      95,     0,     0,   304,     0,     0,     0,   -59,   -59,   -92,
     -59,   -59,   -59,   -59,     0,   -59,     0,   -97,   -97,   -97,
     -97,   308,   -59,   -59,   -59,     0,   -59,   -59,     0,   -59,
     -59,   -59,   209,   -59,   -59,     0,     0,     0,   -59,     0,
     -97,   -59,     0,   -56,   -56,     0,   -56,   -56,   -56,   -56,
       0,   -56,     0,   -96,   -96,   -96,   -96,     0,   -56,   -56,
     -56,   308,   -56,   -56,     0,   -56,   -56,   -56,   211,   -56,
     -56,     0,     0,     0,   -56,     0,   -96,   -56,   -64,     0,
     -64,   -64,   -64,   -64,     0,   -64,     0,     0,     0,     0,
       0,   304,   -64,   -64,   -64,     0,   -64,   -64,     0,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,  -128,   -64,     0,
       0,   -64,   -64,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,   410,   -95,   -95,   -95,   -95,   411,   412,   248,   248,
     248,   -92,   -92,   -92,   -92,     0,     0,  -128,  -128,     0,
       0,     0,   252,   252,   252,   -95,   -95,     0,     0,   252,
     252,   252,     0,     0,   -92,   -92,   248,    46,    47,    48,
      49,    50,    51,    52,    53,   355,     0,     0,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,   248,   360,     0,   167,
      55,     0,   168,   368,   376,   376,   376,   376,   376,   376,
     376,   376,   -39,  -135,   -39,   -39,   -39,   -39,     0,   -39,
       0,     0,     0,     0,     0,     0,   -39,   -39,   -39,     0,
     -39,   -39,   248,   -39,   -39,   -39,   -39,   -39,   -39,     0,
       0,   415,   -39,     0,     0,   -39,   -39,     0,     0,   423,
     431,   431,   431,   431,   431,   431,   431,   431,   -84,   -84,
     408,   531,     0,   236,   237,   238,   239,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,   111,     0,
     -84,   -84,   376,   376,   376,   376,   376,   376,   376,   477,
     376,   240,   -43,   304,   -43,   -43,   -43,   -43,   304,   -43,
       0,     0,     0,   248,     0,   486,   -43,   -43,   -43,     0,
     -43,   -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,     0,
       0,     0,   -43,     0,     0,   -43,   -43,     0,     0,     0,
     248,     0,   248,   249,    46,    47,    48,    49,    50,    51,
      52,    53,   431,   431,   431,   431,   431,   431,   431,   520,
     431,     0,     0,   304,     0,     0,   553,    55,   248,   554,
     526,     0,   261,   261,   261,   261,   261,   261,   261,   261,
       0,   261,     0,     0,     0,     0,     0,   249,     0,   249,
       0,   -91,   -91,   -91,   -91,     0,   248,     0,   248,     0,
       0,     0,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   -91,     0,   305,   -38,     0,   -38,   -38,   -38,   -38,
       0,   -38,     0,   -94,   -94,   -94,   -94,     0,   -38,   -38,
     -38,     0,   -38,   -38,   304,   -38,   -38,   -38,   -38,   -38,
     -38,     0,     0,   -94,   -38,   267,   268,   -38,   -38,     0,
       0,   273,   274,     0,   -40,     0,   -40,   -40,   -40,   -40,
       0,   -40,     0,    79,   -90,   -90,   -90,     0,   -40,   -40,
     -40,     0,   -40,   -40,   304,   -40,   -40,   -40,   -40,   -40,
     -40,     0,     0,   -90,   -40,     0,     0,   -40,   -40,   -41,
       0,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,     0,
       0,   305,     0,   -41,   -41,   -41,     0,   -41,   -41,     0,
     -41,   -41,   -41,   -41,   -41,   -41,     0,     0,     0,   -41,
       0,     0,   -41,   -41,     0,     0,     0,   -39,   -39,     0,
     -39,   -39,   -39,   -39,     0,   -39,     0,     0,   249,   249,
     249,     0,   -39,   -39,   -39,     0,   -39,   -39,     0,   -39,
     -39,   -39,   -39,   -39,   -39,   248,   248,   248,   -39,     0,
       0,   -39,   248,   248,   248,     0,   249,    46,    47,    48,
      49,    50,    51,    52,    53,   249,     0,     0,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,   249,   261,     0,   569,
      55,     0,   570,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   -42,  -133,   -42,   -42,   -42,   -42,     0,   -42,
       0,     0,     0,     0,     0,     0,   -42,   -42,   -42,     0,
     -42,   -42,   249,   -42,   -42,   -42,   -42,   -42,   -42,     0,
       0,   305,   -42,     0,     0,   -42,   -42,     0,     0,   424,
     424,   424,   424,   424,   424,   424,   424,   424,     0,     0,
       0,    66,     0,     2,     3,     4,   235,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,   -97,   -97,
     -97,   -97,   369,   369,   369,   369,   369,   369,   369,   369,
     369,    17,   -55,   305,   -55,   -55,   -55,   -55,   305,   -55,
       0,   -97,   -97,   249,     0,   369,   -55,   -55,   -55,     0,
     -55,   -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,     0,
       0,     0,   -55,     0,     0,   -55,   -55,     0,     0,     0,
     249,     0,   249,   250,   267,   268,   269,   270,   271,   272,
     273,   274,   424,   424,   424,   424,   424,   424,   424,   424,
     424,     0,     0,   305,     0,     0,     0,   275,   249,   121,
     424,     0,   262,   262,   262,   262,   262,   262,   262,   262,
       0,   262,     0,     0,     0,     0,     0,   250,     0,   250,
       0,  -101,  -101,  -101,  -101,     0,   249,     0,   249,     0,
       0,     0,   262,   262,   262,   262,   262,   262,   262,   262,
     262,  -101,     0,   306,   -11,     0,   -11,   -11,   -11,   -11,
       0,   -11,     0,  -100,  -100,  -100,  -100,     0,   -11,   -11,
     -11,     0,   -11,   -11,   305,   -11,   -11,   -11,   -11,   -11,
     -11,     0,     0,  -100,   -11,   313,   314,   -11,   -11,     0,
       0,   319,   320,   -43,   -43,     0,   -43,   -43,   -43,   -43,
       0,   -43,     0,    79,   -88,   -88,   -88,     0,   -43,   -43,
     -43,     0,   -43,   -43,   305,   -43,   -43,   -43,   -43,   -43,
     -43,     0,     0,   -88,   -43,     0,     0,   -43,   -38,   -38,
       0,   -38,   -38,   -38,   -38,     0,   -38,     0,     0,     0,
       0,   306,     0,   -38,   -38,   -38,     0,   -38,   -38,     0,
     -38,   -38,   -38,   -38,   -38,   -38,     0,     0,     0,   -38,
       0,     0,   -38,     0,     0,     0,     0,   -40,   -40,     0,
     -40,   -40,   -40,   -40,     0,   -40,     0,     0,   250,   250,
     250,     0,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,
     -40,   -40,   -40,   -40,   -40,   249,   249,   249,   -40,     0,
       0,   -40,   249,   249,   249,     0,   250,   267,   268,   269,
     270,   271,   272,   273,   274,   250,     0,     0,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,   250,   262,     0,     0,
     275,     0,   162,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   -10,  -109,   -10,   -10,   -10,   -10,     0,   -10,
       0,     0,     0,     0,     0,     0,   -10,   -10,   -10,     0,
     -10,   -10,   250,   -10,   -10,   -10,   -10,   -10,   -10,     0,
       0,   306,   -10,     0,     0,   -10,   -10,     0,     0,   425,
     425,   425,   425,   425,   425,   425,   425,   425,    46,    47,
      48,    49,    50,    51,    52,    53,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,   -96,   -96,   -96,
     -96,    55,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   -41,   -41,   306,   -41,   -41,   -41,   -41,   306,   -41,
     -96,   -96,     0,   250,     0,   370,   -41,   -41,   -41,     0,
     -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,
       0,     0,   -41,     0,   623,   -41,   236,   237,   238,   239,
     250,     6,   250,   251,     0,     0,     0,     0,     7,     8,
       9,     0,   425,   425,   425,   425,   425,   425,   425,   425,
     425,     0,     0,   306,   240,   -77,     0,     0,   250,     0,
     425,     0,   263,   263,   263,   263,   263,   263,   263,   263,
       0,   263,     0,     0,     0,     0,     0,   251,     0,   251,
       0,   -92,   -92,   -92,   -92,     0,   250,     0,   250,     0,
       0,     0,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   -92,     0,   307,     0,     0,   -42,   -42,     0,   -42,
     -42,   -42,   -42,     0,   -42,     0,   -97,   -97,   -97,   -97,
       0,   -42,   -42,   -42,   306,   -42,   -42,     0,   -42,   -42,
     -42,   -42,   -42,   -42,     0,     0,   -97,   -42,     0,     0,
     -42,     0,     0,     0,   -53,     0,   -53,   -53,   -53,   -53,
       0,   -53,     0,   -96,   -96,   -96,   -96,     0,   -53,   -53,
     -53,     0,   -53,   -53,   306,   -53,   -53,   -53,   -53,   -53,
     -53,     0,     0,   -96,   -53,     0,     0,   -53,   -53,   -52,
       0,   -52,   -52,   -52,   -52,     0,   -52,     0,     0,     0,
       0,   307,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,
     -52,   -52,   -52,   -52,   -52,   -52,     0,     0,     0,   -52,
       0,     0,   -52,   -52,     0,     0,     0,   -55,   -55,     0,
     -55,   -55,   -55,   -55,     0,   -55,     0,     0,   251,   251,
     251,     0,   -55,   -55,   -55,     0,   -55,   -55,     0,   -55,
     -55,   -55,   -55,   -55,   -55,   250,   250,   250,   -55,     0,
       0,   -55,   250,   250,   250,     0,   251,   267,   268,   269,
     270,   271,   272,   273,   274,   251,     0,     0,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,   251,   263,     0,     0,
     275,     0,   165,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   -62,  -110,   -62,   -62,   -62,   -62,     0,   -62,
       0,     0,     0,     0,     0,     0,   -62,   -62,   -62,     0,
     -62,   -62,   251,   -62,   -62,   -62,   -62,   -62,   -62,     0,
       0,   307,   -62,     0,     0,   -62,   -62,     0,     0,   426,
     426,   426,   426,   426,   426,   426,   426,   426,     0,     0,
       0,    69,     0,   236,   237,   238,   239,     0,     6,     0,
       0,     0,   267,   268,   269,     7,     8,     9,   273,   274,
       0,     0,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   240,   -72,   307,   -72,   -72,   -72,   -72,   307,   -72,
       0,     0,     0,   251,     0,   371,   -72,   -72,   -72,     0,
     -72,   -72,     0,   -72,   -72,   -72,   -72,   -72,   -72,     0,
       0,     0,   -72,     0,     0,   -72,   -72,     0,     0,     0,
     251,     0,   251,   253,   267,   268,   269,   270,   271,   272,
     273,   274,   426,   426,   426,   426,   426,   426,   426,   426,
     426,     0,     0,   307,     0,     0,     0,   275,   251,   228,
     426,     0,   265,   265,   265,   265,   265,   265,   265,   265,
       0,   265,     0,     0,   313,   314,   315,   253,     0,   253,
     319,   320,     0,     0,     0,     0,   251,     0,   251,     0,
       0,     0,   265,   265,   265,   265,   265,   265,   265,   265,
     265,     0,     0,   309,   -54,     0,   -54,   -54,   -54,   -54,
       0,   -54,     0,     0,     0,     0,     0,     0,   -54,   -54,
     -54,     0,   -54,   -54,   307,   -54,   -54,   -54,   -54,   -54,
     -54,     0,     0,     0,   -54,     0,     0,   -54,   -54,     0,
       0,     0,     0,   -53,   -53,     0,   -53,   -53,   -53,   -53,
       0,   -53,     0,     0,     0,     0,     0,     0,   -53,   -53,
     -53,     0,   -53,   -53,   307,   -53,   -53,   -53,   -53,   -53,
     -53,     0,     0,     0,   -53,     0,     0,   -53,   -52,   -52,
       0,   -52,   -52,   -52,   -52,     0,   -52,     0,     0,     0,
       0,   309,     0,   -52,   -52,   -52,   245,   -52,   -52,     0,
     -52,   -52,   -52,   -52,   -52,   -52,     0,   487,     0,   -52,
       0,     0,   -52,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -112,  -112,  -112,  -112,     0,  -112,    97,   253,   253,
     253,   104,   105,  -112,  -112,  -112,     0,   488,  -123,     0,
     245,     0,   245,     0,     0,   251,   251,   251,     0,  -112,
       0,     0,   251,   251,   251,     0,   253,     0,   139,     0,
     143,   145,     0,     0,     0,   253,   301,     0,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,   253,   265,     0,     0,
       0,     0,     0,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   -12,  -116,   -12,   -12,   -12,   -12,     0,   -12,
       0,     0,     0,     0,     0,     0,   -12,   -12,   -12,     0,
     -12,   -12,   253,   -12,   -12,   -12,   -12,   -12,   -12,     0,
       0,   309,   -12,     0,     0,   -12,   -12,     0,     0,   428,
     428,   428,   428,   428,   428,   428,   428,   428,     0,     0,
       0,   629,     0,   236,   237,   238,   239,     0,     6,     0,
       0,     0,     0,     0,   301,     7,     8,     9,     0,     0,
       0,     0,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   240,   -77,   309,    46,    47,    48,    49,   309,    51,
      52,    53,     0,   253,     0,   373,     0,     0,    86,     0,
       0,   245,   245,   245,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,   267,   268,   269,   270,   271,   272,   273,   274,
     253,     0,   253,     0,     0,     0,  -123,  -123,    87,   245,
       0,     0,   428,   428,   428,   428,   428,   428,   428,   428,
     428,     0,     0,   309,     0,     0,     0,     0,   253,   245,
     428,     0,   247,     0,     0,     0,     0,     0,   378,   245,
     245,   245,   385,   386,   245,   116,     0,     2,     3,     4,
     235,     0,     6,     0,     0,     0,   253,     0,   253,     7,
       8,     9,    94,     0,     0,   245,     0,    93,     0,   256,
     257,   258,   259,   -77,     6,    17,   247,     0,   247,     0,
       0,     7,     8,     9,   433,   301,   301,   301,   440,   441,
     301,     0,     0,     0,   309,   141,     0,   260,     0,     0,
       0,     0,   303,   313,   314,   315,   316,   317,   318,   319,
     320,     0,     0,     0,     0,   245,   245,   245,   469,     0,
     473,   475,     0,   245,   -62,   -62,   301,   -62,   -62,   -62,
     -62,   301,   -62,     0,   309,     0,   245,     0,     0,   -62,
     -62,   -62,     0,   -62,   -62,     0,   -62,   -62,   -62,   -62,
     -62,   -62,     0,     0,     0,   -62,     0,   198,   -62,     2,
       3,     4,   235,   245,     6,   245,     0,     0,     0,     0,
       0,     7,     8,     9,     0,   301,   301,   301,   512,     0,
     516,   518,     0,   301,     0,   -77,   301,    17,     0,     0,
     303,   245,     0,     0,     0,   246,    96,     0,   256,   257,
     258,   259,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,     0,   253,   253,   253,     0,   245,
       0,   245,   253,   253,   253,     0,   260,   247,   247,   247,
    -113,  -113,  -113,  -113,     0,  -113,     0,     0,     0,   246,
       0,   246,  -113,  -113,  -113,     0,   325,     0,     2,     3,
       4,   235,     0,     6,     0,   247,     0,   301,  -113,     0,
       7,     8,     9,     0,     0,   302,     0,   326,   327,   328,
     196,   329,   330,     0,     0,   247,    17,     0,     0,   331,
       0,     0,     0,   375,   247,   247,   247,   247,   247,   247,
     247,   -66,     0,   -66,   -66,   -66,   -66,   301,   -66,     0,
       0,     0,     0,     0,     0,   -66,   -66,   -66,     0,   -66,
     -66,   247,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,
       0,   -66,     0,     0,   -66,   -66,     0,     0,     0,   430,
     303,   303,   303,   303,   303,   303,   303,     0,     0,     0,
     200,     0,     2,     3,     4,   235,     0,     6,     0,     0,
       0,     0,     0,   302,     7,     8,     9,     0,     0,     0,
       0,   247,   247,   247,   247,   471,   247,   247,   -77,   247,
      17,     0,   303,     0,     0,     0,     0,   303,   245,   245,
     245,     0,   247,     0,     0,   245,   245,   245,     0,     0,
     246,   246,   246,     0,     0,     0,     0,     0,     0,     0,
     496,     0,     2,     3,     4,   235,     0,     6,     0,   247,
       0,   247,     0,     0,     7,     8,     9,     0,   246,     0,
     244,   303,   303,   303,   303,   514,   303,   303,   -77,   303,
      17,     0,   303,  -128,     0,     0,     0,   247,   246,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,   246,   246,   246,
     246,   246,   246,   246,   103,     0,     0,     0,     0,     0,
       0,  -128,  -128,  -128,   244,   247,   244,   247,     0,     0,
     267,   268,   269,   270,   246,   272,   273,   274,     0,     0,
       0,   137,   313,   314,   315,   316,   317,   318,   319,   320,
     300,     0,     0,   302,   302,   302,   302,   302,   302,   302,
       0,     0,     0,   303,     0,   321,     0,  -120,  -120,    83,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,
       0,     0,     0,     0,   246,   246,   246,   246,     0,   246,
     246,  -102,   246,   -72,   -72,   302,   -72,   -72,   -72,   -72,
     302,   -72,     0,   303,     0,   246,     0,     0,   -72,   -72,
     -72,     0,   -72,   -72,     0,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,     0,   -72,     0,   536,   -72,     2,     3,
       4,   235,   246,     6,   246,     0,     0,     0,   300,     0,
       7,     8,     9,     0,   302,   302,   302,   302,     0,   302,
     302,     0,   302,     0,   -77,   302,    17,    46,    47,    48,
     246,     0,    51,    52,    53,     0,    98,     0,   256,   257,
     258,   259,     0,     6,     0,   244,   244,   244,     0,     0,
       7,     8,     9,     0,   247,   247,   247,     0,   246,     0,
     246,   247,   247,   247,   -54,   -54,   260,   -54,   -54,   -54,
     -54,     0,   -54,   244,     0,   243,     0,     0,     0,   -54,
     -54,   -54,     0,   -54,   -54,     0,   -54,   -54,   -54,   -54,
     -54,   -54,     0,   244,     0,   -54,   302,     0,   -54,     0,
       0,     0,     0,   244,   244,   384,     0,    99,   244,   587,
       0,     2,     3,     4,   235,     0,     6,     0,     0,   243,
       0,   243,     0,     7,     8,     9,   267,   268,   269,   244,
       0,   272,   273,   274,     0,   135,   302,   -77,     0,    17,
       0,   313,   314,   315,   316,   299,   318,   319,   320,   300,
     300,   439,     0,     0,   300,  -128,     0,     0,     0,     0,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,     0,
       0,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   244,
     244,   467,     0,  -128,  -128,  -128,     0,   244,     0,     0,
     300,     0,     0,     0,  -134,   300,  -134,  -134,     0,     0,
     244,     0,    86,     0,     0,     0,     0,   254,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,     0,   246,   246,   246,
       0,     0,     0,     0,   246,   246,   246,   244,     0,   244,
    -123,  -123,    87,   299,     0,     0,     0,     0,     0,   300,
     300,   510,     0,     0,   242,     0,     0,   300,     0,     0,
     300,   313,   314,   315,     0,   244,   318,   319,   320,   603,
       0,     2,     3,     4,   235,     0,     6,     0,     0,     0,
     243,   243,   243,     7,     8,     9,     0,   101,     0,  -115,
    -115,  -115,  -115,   244,  -115,   244,     0,   -77,   242,    17,
     242,  -115,  -115,  -115,     0,     0,     0,     0,   243,     0,
       0,     0,     0,   133,     0,     0,     0,  -115,     0,     0,
       0,     0,     0,     0,   298,     0,     0,     0,   243,   -66,
     -66,   300,   -66,   -66,   -66,   -66,     0,   -66,   380,   243,
       0,     0,     0,   243,   -66,   -66,   -66,     0,   -66,   -66,
       0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,
     -66,     0,     0,   -66,   243,     0,     0,   241,     0,     0,
       0,   300,     0,     0,     0,     0,   -65,     0,   -65,   -65,
     -65,   -65,     0,   -65,   435,   299,     0,     0,     0,   299,
     -65,   -65,   -65,     0,   -65,   -65,     0,   -65,   -65,   -65,
     -65,   -65,   -65,     0,     0,   107,   -65,     0,     0,   -65,
     -65,   241,   298,   241,   243,   465,     0,     0,     0,     0,
       0,     0,   243,     0,     0,   299,     0,     0,     0,     0,
     299,     0,     0,     0,   149,   243,     0,   297,     0,     0,
       0,   100,     0,   256,   257,   258,   259,     0,     6,   242,
     242,   242,   244,   244,   244,     7,     8,     9,     0,   244,
     244,   244,   243,     0,   243,   102,     0,   256,   257,   258,
     259,   260,     6,     0,   299,   508,     0,   242,     0,     7,
       8,     9,   299,    -3,     1,   299,     2,     3,     4,     5,
     243,     6,     0,     0,     0,   260,     0,   242,     7,     8,
       9,     0,    10,    11,     0,    12,    13,    14,   382,    15,
      16,     0,   242,     0,    17,     0,     0,    18,   243,     0,
     243,     0,     0,     0,     0,   297,     0,   -14,     0,   -14,
     -14,   -14,   -14,   242,   -14,     0,     0,     0,     0,     0,
       0,   -14,   -14,   -14,     0,   -14,   -14,     0,   -14,   -14,
     -14,   -14,   -14,   -14,   437,     0,   299,   -14,   298,     0,
     -14,   -14,   241,   241,   241,   106,     0,   256,   257,   258,
     259,   114,     6,   236,   237,   238,   239,     0,     6,     7,
       8,     9,     0,   463,     0,     7,     8,     9,     0,     0,
     241,   242,     0,     0,   298,   260,   299,     0,     0,   298,
       0,   240,     0,     0,   242,     0,     0,     0,     0,     0,
     241,     0,     0,     0,   311,     0,     2,     3,     4,   235,
       0,     6,     0,     0,     0,   388,     0,     0,     7,     8,
       9,   242,     0,   242,     0,   278,   279,   280,   582,   281,
     282,     0,     0,   506,    17,     0,   241,   283,     0,     0,
       0,   298,     0,   132,   298,   256,   257,   258,   259,   242,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,   443,     0,     0,     0,     0,     0,   243,   243,   243,
       0,     0,     0,   260,   243,   243,   243,   242,     0,   242,
       0,     0,     0,     0,   134,     0,   256,   257,   258,   259,
       0,     6,     0,     0,   479,     0,     0,   297,     7,     8,
       9,     0,   297,     0,     0,     0,     0,   241,     0,     0,
       0,     0,     0,     0,   260,   298,     0,     0,     0,     0,
       0,     0,   -65,   -65,     0,   -65,   -65,   -65,   -65,     0,
     -65,     0,     0,     0,   241,     0,   241,   -65,   -65,   -65,
       0,   -65,   -65,     0,   -65,   -65,   -65,   -65,   -65,   -65,
       0,     0,     0,   -65,   522,   298,   -65,   297,     0,     0,
       0,   -71,   241,   -71,   -71,   -71,   -71,     0,   -71,     0,
       0,     0,     0,     0,     0,   -71,   -71,   -71,     0,   -71,
     -71,     0,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,
     241,   -71,   241,     0,   -71,   -71,   -30,     0,   -30,   -30,
     -30,   -30,     0,   -30,     0,     0,     0,     0,     0,     0,
     -30,   -30,   -30,     0,   -30,   -30,     0,   -30,   -30,   -30,
     -30,   -30,   -30,     0,     0,     0,   -30,     0,   297,   -30,
     -30,     0,     0,     0,     0,     0,   242,   242,   242,     0,
       0,     0,     0,   242,   242,   242,     0,     0,   -13,     0,
     -13,   -13,   -13,   -13,     0,   -13,     0,     0,     0,     0,
       0,     0,   -13,   -13,   -13,     0,   -13,   -13,   297,   -13,
     -13,   -13,   -13,   -13,   -13,     0,     0,     0,   -13,     0,
       0,   -13,   -13,   -71,   -71,     0,   -71,   -71,   -71,   -71,
       0,   -71,     0,     0,     0,     0,     0,     0,   -71,   -71,
     -71,     0,   -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,
     -71,     0,     0,     0,   -71,     0,     0,   -71,     0,     0,
       0,   -30,   -30,     0,   -30,   -30,   -30,   -30,     0,   -30,
       0,     0,     0,     0,     0,     0,   -30,   -30,   -30,     0,
     -30,   -30,     0,   -30,   -30,   -30,   -30,   -30,   -30,   241,
     241,   241,   -30,     0,     0,   -30,   241,   241,   241,   -48,
       0,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,     0,
       0,     0,     0,   -48,   -48,   -48,     0,   -48,   -48,     0,
     -48,   -48,   -48,   -48,   -48,   -48,     0,     0,     0,   -48,
       0,     0,   -48,   -48,   -49,     0,   -49,   -49,   -49,   -49,
       0,   -49,     0,     0,     0,     0,     0,     0,   -49,   -49,
     -49,     0,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,
     -49,     0,     0,     0,   -49,     0,     0,   -49,   -49,   -44,
       0,   -44,   -44,   -44,   -44,     0,   -44,     0,     0,     0,
       0,     0,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,
     -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,
       0,     0,   -44,   -44,   -47,     0,   -47,   -47,   -47,   -47,
       0,   -47,     0,     0,     0,     0,     0,     0,   -47,   -47,
     -47,     0,   -47,   -47,     0,   -47,   -47,   -47,   -47,   -47,
     -47,     0,     0,     0,   -47,     0,     0,   -47,   -47,   -50,
       0,   -50,   -50,   -50,   -50,     0,   -50,     0,     0,     0,
       0,     0,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,
     -50,   -50,   -50,   -50,   -50,   -50,     0,     0,     0,   -50,
       0,     0,   -50,   -50,   -45,     0,   -45,   -45,   -45,   -45,
       0,   -45,     0,     0,     0,     0,     0,     0,   -45,   -45,
     -45,     0,   -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,
     -45,     0,     0,     0,   -45,     0,     0,   -45,   -45,   -51,
       0,   -51,   -51,   -51,   -51,     0,   -51,     0,     0,     0,
       0,     0,     0,   -51,   -51,   -51,     0,   -51,   -51,     0,
     -51,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,   -51,
       0,     0,   -51,   -51,   -46,     0,   -46,   -46,   -46,   -46,
       0,   -46,     0,     0,     0,     0,     0,     0,   -46,   -46,
     -46,     0,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,
     -46,     0,     0,     0,   -46,     0,     0,   -46,   -46,   -59,
       0,   -59,   -59,   -59,   -59,     0,   -59,     0,     0,     0,
       0,     0,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,
     -59,   -59,   -59,   606,   -59,   -59,     0,     0,     0,   -59,
       0,     0,   -59,   -59,   -56,     0,   -56,   -56,   -56,   -56,
       0,   -56,     0,     0,     0,     0,     0,     0,   -56,   -56,
     -56,     0,   -56,   -56,     0,   -56,   -56,   -56,   608,   -56,
     -56,     0,     0,     0,   -56,     0,     0,   -56,   -56,   -48,
     -48,     0,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,
       0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,   -48,
       0,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,     0,
     -48,   -49,   -49,   -48,   -49,   -49,   -49,   -49,     0,   -49,
       0,     0,     0,     0,     0,     0,   -49,   -49,   -49,     0,
     -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,     0,   -49,   -44,   -44,   -49,   -44,   -44,   -44,   -44,
       0,   -44,     0,     0,     0,     0,     0,     0,   -44,   -44,
     -44,     0,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,     0,   -44,   -47,   -47,   -44,   -47,   -47,
     -47,   -47,     0,   -47,     0,     0,     0,     0,     0,     0,
     -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,
     -47,   -47,   -47,     0,     0,     0,   -47,   -50,   -50,   -47,
     -50,   -50,   -50,   -50,     0,   -50,     0,     0,     0,     0,
       0,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,   -50,
     -50,   -50,   -50,   -50,   -50,     0,     0,     0,   -50,   -45,
     -45,   -50,   -45,   -45,   -45,   -45,     0,   -45,     0,     0,
       0,     0,     0,     0,   -45,   -45,   -45,     0,   -45,   -45,
       0,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,     0,
     -45,   -51,   -51,   -45,   -51,   -51,   -51,   -51,     0,   -51,
       0,     0,     0,     0,     0,     0,   -51,   -51,   -51,     0,
     -51,   -51,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,
       0,     0,   -51,   -46,   -46,   -51,   -46,   -46,   -46,   -46,
       0,   -46,     0,     0,     0,     0,     0,     0,   -46,   -46,
     -46,     0,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,
     -46,     0,     0,     0,   -46,   -59,   -59,   -46,   -59,   -59,
     -59,   -59,     0,   -59,     0,     0,     0,     0,     0,     0,
     -59,   -59,   -59,     0,   -59,   -59,     0,   -59,   -59,   -59,
     613,   -59,   -59,     0,     0,     0,   -59,   -56,   -56,   -59,
     -56,   -56,   -56,   -56,     0,   -56,     0,     0,     0,     0,
       0,     0,   -56,   -56,   -56,     0,   -56,   -56,     0,   -56,
     -56,   -56,   615,   -56,   -56,     0,     0,     0,   -56,     0,
     -61,   -56,   -61,   -61,   -61,   -61,     0,   -61,     0,     0,
       0,     0,     0,     0,   -61,   -61,   -61,     0,   -61,   -61,
       0,   -61,   -61,   -61,   -61,   -61,   -61,     0,     0,     0,
     -61,     0,     0,   -61,   -61,   -58,     0,   -58,   -58,   -58,
     -58,     0,   -58,     0,     0,     0,     0,     0,     0,   -58,
     -58,   -58,     0,   -58,   -58,     0,   -58,   -58,   -58,   -58,
     -58,   -58,     0,     0,     0,   -58,     0,     0,   -58,   -58,
     -61,   -61,     0,   -61,   -61,   -61,   -61,     0,   -61,     0,
       0,     0,     0,     0,     0,   -61,   -61,   -61,     0,   -61,
     -61,     0,   -61,   -61,   -61,   -61,   -61,   -61,     0,     0,
       0,   -61,   -58,   -58,   -61,   -58,   -58,   -58,   -58,     0,
     -58,     0,     0,     0,     0,     0,     0,   -58,   -58,   -58,
       0,   -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,   -58,
       0,     0,     0,   -58,     0,   -60,   -58,   -60,   -60,   -60,
     -60,     0,   -60,     0,     0,     0,     0,     0,     0,   -60,
     -60,   -60,     0,   -60,   -60,     0,   -60,   -60,   -60,   -60,
     -60,   -60,     0,     0,     0,   -60,     0,     0,   -60,   -60,
     -57,     0,   -57,   -57,   -57,   -57,     0,   -57,     0,     0,
       0,     0,     0,     0,   -57,   -57,   -57,     0,   -57,   -57,
       0,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,
     -57,     0,     0,   -57,   -57,   -60,   -60,     0,   -60,   -60,
     -60,   -60,     0,   -60,     0,     0,     0,     0,     0,     0,
     -60,   -60,   -60,     0,   -60,   -60,     0,   -60,   -60,   -60,
     -60,   -60,   -60,     0,     0,     0,   -60,   -57,   -57,   -60,
     -57,   -57,   -57,   -57,     0,   -57,     0,     0,     0,     0,
       0,     0,   -57,   -57,   -57,     0,   -57,   -57,     0,   -57,
     -57,   -57,   -57,   -57,   -57,     0,     0,     0,   -57,     0,
     -68,   -57,   -68,   -68,   -68,   -68,     0,   -68,     0,     0,
       0,     0,     0,     0,   -68,   -68,   -68,     0,   -68,   -68,
       0,   -68,   -68,   -68,   -68,   -68,   -68,     0,     0,     0,
     -68,     0,     0,   -68,   -68,   -69,     0,   -69,   -69,   -69,
     -69,     0,   -69,     0,     0,     0,     0,     0,     0,   -69,
     -69,   -69,     0,   -69,   -69,     0,   -69,   -69,   -69,   -69,
     -69,   -69,     0,     0,     0,   -69,     0,     0,   -69,   -69,
     -70,     0,   -70,   -70,   -70,   -70,     0,   -70,     0,     0,
       0,     0,     0,     0,   -70,   -70,   -70,     0,   -70,   -70,
       0,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,
     -70,     0,     0,   -70,   -70,   -67,     0,   -67,   -67,   -67,
     -67,     0,   -67,     0,     0,     0,     0,     0,     0,   -67,
     -67,   -67,     0,   -67,   -67,     0,   -67,   -67,   -67,   -67,
     -67,   -67,     0,     0,     0,   -67,     0,     0,   -67,   -67,
     -68,   -68,     0,   -68,   -68,   -68,   -68,     0,   -68,     0,
       0,     0,     0,     0,     0,   -68,   -68,   -68,     0,   -68,
     -68,     0,   -68,   -68,   -68,   -68,   -68,   -68,     0,     0,
       0,   -68,   -69,   -69,   -68,   -69,   -69,   -69,   -69,     0,
     -69,     0,     0,     0,     0,     0,     0,   -69,   -69,   -69,
       0,   -69,   -69,     0,   -69,   -69,   -69,   -69,   -69,   -69,
       0,     0,     0,   -69,   -70,   -70,   -69,   -70,   -70,   -70,
     -70,     0,   -70,     0,     0,     0,     0,     0,     0,   -70,
     -70,   -70,     0,   -70,   -70,     0,   -70,   -70,   -70,   -70,
     -70,   -70,     0,     0,     0,   -70,   -67,   -67,   -70,   -67,
     -67,   -67,   -67,     0,   -67,     0,     0,     0,     0,     0,
       0,   -67,   -67,   -67,     0,   -67,   -67,     0,   -67,   -67,
     -67,   -67,   -67,   -67,     0,     0,     0,   -67,    -2,    73,
     -67,     2,     3,     4,     5,     0,     6,     0,     0,     0,
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
     -55,   -55,   -42,   -55,   -55,   -55,   -55,     0,   -55,     0,
       0,     0,     0,     0,     0,   -55,   -55,   -55,     0,   -55,
     -55,     0,   -55,   -55,   -55,     0,   -55,   -55,     0,     0,
       0,   -55,   -53,   -53,   -55,   -53,   -53,   -53,   -53,     0,
     -53,     0,     0,     0,     0,     0,     0,   -53,   -53,   -53,
       0,   -53,   -53,     0,   -53,   -53,   -53,     0,   -53,   -53,
       0,     0,     0,   -53,   -52,   -52,   -53,   -52,   -52,   -52,
     -52,     0,   -52,     0,     0,     0,     0,     0,     0,   -52,
     -52,   -52,     0,   -52,   -52,     0,   -52,   -52,   -52,     0,
     -52,   -52,     0,     0,     0,   -52,   -62,   -62,   -52,   -62,
     -62,   -62,   -62,     0,   -62,     0,     0,     0,     0,     0,
       0,   -62,   -62,   -62,     0,   -62,   -62,     0,   -62,   -62,
     -62,     0,   -62,   -62,     0,     0,     0,   -62,   -72,   -72,
     -62,   -72,   -72,   -72,   -72,     0,   -72,     0,     0,     0,
       0,     0,     0,   -72,   -72,   -72,     0,   -72,   -72,     0,
     -72,   -72,   -72,     0,   -72,   -72,     0,     0,     0,   -72,
      -5,    -5,   -72,    -5,    -5,    -5,    -5,     0,    -5,     0,
       0,     0,     0,     0,     0,    -5,    -5,    -5,     0,    -5,
      -5,     0,    -5,    -5,    -5,     0,    -5,    -5,     0,     0,
       0,    -5,   -54,   -54,    -5,   -54,   -54,   -54,   -54,     0,
     -54,     0,     0,     0,     0,     0,     0,   -54,   -54,   -54,
       0,   -54,   -54,     0,   -54,   -54,   -54,     0,   -54,   -54,
       0,     0,     0,   -54,   -11,   -11,   -54,   -11,   -11,   -11,
     -11,     0,   -11,     0,     0,     0,     0,     0,     0,   -11,
     -11,   -11,     0,   -11,   -11,     0,   -11,   -11,   -11,     0,
     -11,   -11,     0,     0,     0,   -11,   -66,   -66,   -11,   -66,
     -66,   -66,   -66,     0,   -66,     0,     0,     0,     0,     0,
       0,   -66,   -66,   -66,     0,   -66,   -66,     0,   -66,   -66,
     -66,     0,   -66,   -66,     0,     0,     0,   -66,   -65,   -65,
     -66,   -65,   -65,   -65,   -65,     0,   -65,     0,     0,     0,
       0,     0,     0,   -65,   -65,   -65,     0,   -65,   -65,     0,
     -65,   -65,   -65,     0,   -65,   -65,     0,     0,     0,   -65,
     -14,   -14,   -65,   -14,   -14,   -14,   -14,     0,   -14,     0,
       0,     0,     0,     0,     0,   -14,   -14,   -14,     0,   -14,
     -14,     0,   -14,   -14,   -14,     0,   -14,   -14,     0,     0,
       0,   -14,   -10,   -10,   -14,   -10,   -10,   -10,   -10,     0,
     -10,     0,     0,     0,     0,     0,     0,   -10,   -10,   -10,
       0,   -10,   -10,     0,   -10,   -10,   -10,     0,   -10,   -10,
       0,     0,     0,   -10,   -71,   -71,   -10,   -71,   -71,   -71,
     -71,     0,   -71,     0,     0,     0,     0,     0,     0,   -71,
     -71,   -71,     0,   -71,   -71,     0,   -71,   -71,   -71,     0,
     -71,   -71,     0,     0,     0,   -71,   -30,   -30,   -71,   -30,
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
     -46,     0,   -46,   -46,     0,     0,     0,   -46,   -61,   -61,
     -46,   -61,   -61,   -61,   -61,     0,   -61,     0,     0,     0,
       0,     0,     0,   -61,   -61,   -61,     0,   -61,   -61,     0,
     -61,   -61,   -61,     0,   -61,   -61,     0,     0,     0,   -61,
     -58,   -58,   -61,   -58,   -58,   -58,   -58,     0,   -58,     0,
       0,     0,     0,     0,     0,   -58,   -58,   -58,     0,   -58,
     -58,     0,   -58,   -58,   -58,     0,   -58,   -58,     0,     0,
       0,   -58,   -60,   -60,   -58,   -60,   -60,   -60,   -60,     0,
     -60,     0,     0,     0,     0,     0,     0,   -60,   -60,   -60,
       0,   -60,   -60,     0,   -60,   -60,   -60,     0,   -60,   -60,
       0,     0,     0,   -60,   -57,   -57,   -60,   -57,   -57,   -57,
     -57,     0,   -57,     0,     0,     0,     0,     0,     0,   -57,
     -57,   -57,     0,   -57,   -57,     0,   -57,   -57,   -57,     0,
     -57,   -57,     0,     0,     0,   -57,   -20,   -20,   -57,   -20,
     -20,   -20,   -20,     0,   -20,     0,     0,     0,     0,     0,
       0,   -20,   -20,   -20,     0,   -20,   -20,     0,   -20,   -20,
     -20,     0,   -20,   -20,     0,     0,     0,   -20,   -17,   -17,
     -20,   -17,   -17,   -17,   -17,     0,   -17,     0,     0,     0,
       0,     0,     0,   -17,   -17,   -17,     0,   -17,   -17,     0,
     -17,   -17,   -17,     0,   -17,   -17,     0,     0,     0,   -17,
     -68,   -68,   -17,   -68,   -68,   -68,   -68,     0,   -68,     0,
       0,     0,     0,     0,     0,   -68,   -68,   -68,     0,   -68,
     -68,     0,   -68,   -68,   -68,     0,   -68,   -68,     0,     0,
       0,   -68,   -69,   -69,   -68,   -69,   -69,   -69,   -69,     0,
     -69,     0,     0,     0,     0,     0,     0,   -69,   -69,   -69,
       0,   -69,   -69,     0,   -69,   -69,   -69,     0,   -69,   -69,
       0,     0,     0,   -69,   -70,   -70,   -69,   -70,   -70,   -70,
     -70,     0,   -70,     0,     0,     0,     0,     0,     0,   -70,
     -70,   -70,     0,   -70,   -70,     0,   -70,   -70,   -70,     0,
     -70,   -70,     0,     0,     0,   -70,   -67,   -67,   -70,   -67,
     -67,   -67,   -67,     0,   -67,     0,     0,     0,     0,     0,
       0,   -67,   -67,   -67,     0,   -67,   -67,     0,   -67,   -67,
     -67,     0,   -67,   -67,     0,     0,     0,   -67,     0,   311,
     -67,     2,     3,     4,   235,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
     278,   279,   280,   584,   281,   282,     0,     0,     0,    17,
       0,   325,   283,     2,     3,     4,   235,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
       0,     0,   326,   327,   328,   598,   329,   330,     0,     0,
       0,    17,     0,   325,   331,     2,     3,     4,   235,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,     0,     0,   326,   327,   328,   600,   329,   330,
       0,     0,     0,    17,     0,   311,   331,     2,     3,     4,
     235,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,   278,   279,   280,     0,
     281,   282,     0,     0,     0,    17,     0,    73,   283,     2,
       3,     4,   235,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,     0,     0,     0,    12,    13,
      14,     0,    15,    16,     0,     0,     0,    17,     0,   325,
      18,     2,     3,     4,   235,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
     326,   327,   328,     0,   329,   330,     0,     0,     0,    17,
       0,   136,   331,   256,   257,   258,   259,   138,     6,   256,
     257,   258,   259,     0,     6,     7,     8,     9,     0,     0,
       0,     7,     8,     9,     0,   140,     0,   256,   257,   258,
     259,   260,     6,     0,     0,     0,     0,   260,     0,     7,
       8,     9,   142,     0,   256,   257,   258,   259,     0,     6,
       0,     0,     0,     0,     0,   260,     7,     8,     9,   144,
       0,   256,   257,   258,   259,     0,     6,     0,     0,     0,
       0,     0,   260,     7,     8,     9,   146,     0,   256,   257,
     258,   259,     0,     6,     0,     0,     0,     0,     0,   260,
       7,     8,     9,   148,     0,   256,   257,   258,   259,     0,
       6,     0,     0,     0,     0,     0,   260,     7,     8,     9,
     341,     0,   292,   293,   294,   295,     0,     6,     0,     0,
       0,     0,     0,   260,     7,     8,     9,   344,     0,   236,
     237,   238,   239,     0,     6,     0,     0,     0,     0,     0,
     296,     7,     8,     9,   358,     0,   236,   237,   238,   239,
       0,     6,     0,     0,     0,     0,     0,   240,     7,     8,
       9,   374,     0,   363,   364,   365,   366,     0,     6,     0,
       0,     0,     0,     0,   240,     7,     8,     9,   377,     0,
     363,   364,   365,   366,     0,     6,     0,     0,     0,     0,
       0,   367,     7,     8,     9,   379,     0,   363,   364,   365,
     366,     0,     6,     0,     0,     0,     0,     0,   367,     7,
       8,     9,   381,     0,   363,   364,   365,   366,     0,     6,
       0,     0,     0,     0,     0,   367,     7,     8,     9,   383,
       0,   363,   364,   365,   366,     0,     6,     0,     0,     0,
       0,     0,   367,     7,     8,     9,   387,     0,   363,   364,
     365,   366,     0,     6,     0,     0,     0,     0,     0,   367,
       7,     8,     9,   399,     0,     2,     3,     4,   235,     0,
       6,     0,     0,     0,     0,     0,   367,     7,     8,     9,
     404,     0,   236,   237,   238,   239,     0,     6,     0,     0,
       0,     0,     0,    17,     7,     8,     9,   429,     0,   418,
     419,   420,   421,     0,     6,     0,     0,     0,     0,     0,
     240,     7,     8,     9,   432,     0,   418,   419,   420,   421,
       0,     6,     0,     0,     0,     0,     0,   422,     7,     8,
       9,   434,     0,   418,   419,   420,   421,     0,     6,     0,
       0,     0,     0,     0,   422,     7,     8,     9,   436,     0,
     418,   419,   420,   421,     0,     6,     0,     0,     0,     0,
       0,   422,     7,     8,     9,   438,     0,   418,   419,   420,
     421,     0,     6,     0,     0,     0,     0,     0,   422,     7,
       8,     9,   442,     0,   418,   419,   420,   421,     0,     6,
       0,     0,     0,     0,     0,   422,     7,     8,     9,   455,
       0,     2,     3,     4,   235,     0,     6,     0,     0,     0,
       0,     0,   422,     7,     8,     9,   462,     0,   363,   364,
     365,   366,     0,     6,     0,     0,     0,     0,     0,    17,
       7,     8,     9,   464,     0,   363,   364,   365,   366,     0,
       6,     0,     0,     0,     0,     0,   367,     7,     8,     9,
     466,     0,   363,   364,   365,   366,     0,     6,     0,     0,
       0,     0,     0,   367,     7,     8,     9,   468,     0,   363,
     364,   365,   366,     0,     6,     0,     0,     0,     0,     0,
     367,     7,     8,     9,   470,     0,   363,   364,   365,   366,
       0,     6,     0,     0,     0,     0,     0,   367,     7,     8,
       9,   472,     0,   363,   364,   365,   366,     0,     6,     0,
       0,     0,     0,     0,   367,     7,     8,     9,   474,     0,
     363,   364,   365,   366,     0,     6,     0,     0,     0,     0,
       0,   367,     7,     8,     9,   476,     0,   363,   364,   365,
     366,     0,     6,     0,     0,     0,     0,     0,   367,     7,
       8,     9,   478,     0,   363,   364,   365,   366,     0,     6,
       0,     0,     0,     0,     0,   367,     7,     8,     9,   484,
       0,   236,   237,   238,   239,     0,     6,     0,     0,     0,
       0,     0,   367,     7,     8,     9,   494,     0,   236,   237,
     238,   239,     0,     6,     0,     0,     0,     0,     0,   240,
       7,     8,     9,   505,     0,   418,   419,   420,   421,     0,
       6,     0,     0,     0,     0,     0,   240,     7,     8,     9,
     507,     0,   418,   419,   420,   421,     0,     6,     0,     0,
       0,     0,     0,   422,     7,     8,     9,   509,     0,   418,
     419,   420,   421,     0,     6,     0,     0,     0,     0,     0,
     422,     7,     8,     9,   511,     0,   418,   419,   420,   421,
       0,     6,     0,     0,     0,     0,     0,   422,     7,     8,
       9,   513,     0,   418,   419,   420,   421,     0,     6,     0,
       0,     0,     0,     0,   422,     7,     8,     9,   515,     0,
     418,   419,   420,   421,     0,     6,     0,     0,     0,     0,
       0,   422,     7,     8,     9,   517,     0,   418,   419,   420,
     421,     0,     6,     0,     0,     0,     0,     0,   422,     7,
       8,     9,   519,     0,   418,   419,   420,   421,     0,     6,
       0,     0,     0,     0,     0,   422,     7,     8,     9,   521,
       0,   418,   419,   420,   421,     0,     6,     0,     0,     0,
       0,     0,   422,     7,     8,     9,   524,     0,   236,   237,
     238,   239,     0,     6,     0,     0,     0,     0,     0,   422,
       7,     8,     9,   534,     0,   236,   237,   238,   239,     0,
       6,     0,     0,     0,     0,     0,   240,     7,     8,     9,
       0,     0,     2,     3,     4,   235,     0,     6,     0,     0,
       0,     0,     0,   240,     7,     8,     9,     0,     0,   256,
     257,   258,   259,     0,     6,     0,     0,     0,     0,     0,
      17,     7,     8,     9,     0,     0,   236,   237,   238,   239,
       0,     6,     0,     0,     0,     0,     0,   260,     7,     8,
       9,     0,     0,   363,   364,   365,   366,     0,     6,     0,
       0,     0,     0,     0,   240,     7,     8,     9,     0,     0,
     292,   293,   294,   295,     0,     6,     0,     0,     0,     0,
       0,   367,     7,     8,     9,     0,     0,   418,   419,   420,
     421,     0,     6,     0,     0,     0,     0,     0,   296,     7,
       8,     9,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
       0,     0,     0,     0,     0,   422,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,     0,  -135,     0,  -135,  -135,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,     0,     0,  -133,
       0,  -133,  -133,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,     0,   414,     0,  -106,  -106,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,     0,     0,  -110,     0,  -110,  -110,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,     0,  -116,
       0,  -116,  -116,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,     0,     0,  -124,     0,  -124,  -124,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,     0,  -111,     0,  -111,  -111,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,     0,     0,
    -127,     0,  -127,  -127,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,     0,  -126,     0,  -126,  -126,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,     0,     0,  -125,     0,  -125,
    -125,   413,  -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,
    -117,     0,  -117,  -117,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,     0,     0,     0,     0,  -102,  -102,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,     0,     0,     0,  -134,
    -134,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,     0,
       0,     0,     0,  -135,  -135,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,     0,     0,     0,  -133,  -133,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,     0,     0,     0,     0,
    -109,  -109,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
       0,     0,     0,  -110,  -110,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,     0,     0,     0,     0,  -116,  -116,   413,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,     0,     0,     0,
    -124,  -124,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
       0,     0,     0,     0,  -105,  -105,   313,   314,   315,   316,
     -81,   318,   319,   320,     0,     0,     0,  -106,  -106,   313,
     314,   315,   -85,   -85,   318,   319,   320,     0,     0,     0,
       0,   -81,   -81,   313,   314,   315,   -89,   -89,   -89,   319,
     320,     0,     0,     0,   -85,   -85,   313,   314,   -93,   -93,
     -93,   -93,   319,   320,     0,     0,     0,     0,   -89,   -89,
     313,  -104,  -104,  -104,  -104,  -104,  -104,  -104,     0,     0,
       0,   -93,   -93,   413,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,     0,     0,     0,     0,  -104,  -104,   313,   314,   -99,
     -99,   -99,   -99,   319,   320,     0,     0,     0,  -103,  -103,
     313,   314,   -98,   -98,   -98,   -98,   319,   320,     0,     0,
       0,     0,   -99,   -99,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,     0,     0,     0,   -98,   -98,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,     0,     0,     0,     0,  -108,
    -108,   313,   314,   315,   316,   317,   318,   319,   320,     0,
       0,     0,  -107,  -107,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,     0,     0,     0,     0,   -75,   -75,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,     0,     0,     0,  -111,
    -111,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,     0,
       0,     0,     0,  -127,  -127,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,     0,     0,     0,  -126,  -126,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,     0,     0,     0,     0,
    -125,  -125,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
       0,     0,     0,  -117,  -117,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,     0,     0,  -134,     0,  -134,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,     0,     0,  -135,     0,
    -135,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,     0,
       0,  -133,     0,  -133,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,     0,     0,   354,     0,  -106,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,     0,     0,  -110,     0,  -110,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,     0,     0,
    -116,     0,  -116,   267,   268,   269,   270,   271,   272,   273,
     274,     0,     0,  -124,     0,  -124,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,     0,     0,   275,     0,   460,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,     0,     0,  -111,
       0,  -111,   267,   268,   269,   270,   271,   272,   273,   274,
       0,     0,  -127,     0,  -127,   267,   268,   269,   270,   271,
     272,   273,   274,     0,     0,   275,     0,   481,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,     0,     0,   275,     0,
     503,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,     0,
       0,  -126,     0,  -126,   267,   268,   269,   270,   271,   272,
     273,   274,     0,     0,  -125,     0,  -125,   267,   268,   269,
     270,   271,   272,   273,   274,     0,     0,   275,     0,   543,
     267,   268,   269,   270,   271,   272,   273,   274,     0,     0,
     275,     0,   548,   267,   268,   269,   270,   271,   272,   273,
     274,     0,     0,   275,     0,   551,   267,   268,   269,   270,
     271,   272,   273,   274,     0,     0,   275,     0,   559,   267,
     268,   269,   270,   271,   272,   273,   274,     0,     0,   275,
       0,   564,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
       0,     0,   275,     0,   567,   267,   268,   269,   270,   271,
     272,   273,   274,     0,     0,  -117,     0,  -117,   267,   268,
     269,   270,   271,   272,   273,   274,     0,     0,   275,     0,
     633,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,     0,
       0,   275,     0,   637,   353,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,     0,     0,     0,     0,  -124,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,     0,     0,     0,     0,  -105,
     267,   268,   269,   270,   -81,   272,   273,   274,     0,     0,
       0,     0,  -106,   267,   268,   269,   -85,   -85,   272,   273,
     274,     0,     0,     0,     0,   -81,   267,   268,   269,   -89,
     -89,   -89,   273,   274,     0,     0,     0,     0,   -85,   267,
     268,   -93,   -93,   -93,   -93,   273,   274,     0,     0,     0,
       0,   -89,   267,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
       0,     0,     0,     0,   -93,   353,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,     0,     0,     0,     0,  -104,   267,   268,
     -99,   -99,   -99,   -99,   273,   274,     0,     0,     0,     0,
    -103,   267,   268,   -98,   -98,   -98,   -98,   273,   274,     0,
       0,     0,     0,   -99,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,     0,     0,     0,     0,   -98,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,     0,     0,     0,     0,  -108,
     267,   268,   269,   270,   271,   272,   273,   274,     0,     0,
       0,     0,  -107,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,     0,     0,     0,     0,   -75,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,     0,     0,     0,     0,  -111,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,     0,     0,     0,
       0,  -127,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
       0,     0,     0,     0,  -126,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,     0,     0,     0,     0,  -125,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
    -117,     0,     0,     0,     0,     0,   170,     0,     0,     0,
     310,    55,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,     0,     0,
       0,     0,     0,     0,  -134,  -134,     0,     0,     0,     0,
       0,     0,  -135,  -135,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
       0,     0,     0,     0,     0,     0,  -133,  -133,     0,     0,
       0,     0,     0,     0,  -106,    84,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,     0,     0,     0,     0,     0,     0,  -110,  -110,
       0,     0,     0,     0,     0,     0,  -116,  -116,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
    -124,  -124,     0,     0,     0,     0,     0,     0,   119,    55,
      46,    47,    48,    49,    50,    51,    52,    53,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,     0,     0,     0,     0,
       0,     0,    54,    55,     0,     0,     0,     0,     0,     0,
    -111,  -111,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,     0,     0,
       0,     0,     0,     0,  -127,  -127,     0,     0,     0,     0,
       0,     0,  -126,  -126,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
       0,     0,     0,     0,     0,     0,  -125,  -125,     0,     0,
       0,     0,     0,     0,  -117,  -117,    46,    47,    48,    49,
      50,    51,    52,    53,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     0,   213,    55,
       0,     0,     0,     0,     0,     0,   310,    55,    46,    47,
      48,    49,    50,    51,    52,    53,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,     0,     0,     0,
     446,    55,     0,     0,     0,     0,     0,     0,   498,    55,
      46,    47,    48,    49,    50,    51,    52,    53,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
       0,     0,   538,    55,     0,     0,     0,     0,     0,     0,
     610,    55,    46,    47,    48,    49,    50,    51,    52,    53,
     313,   314,   315,   316,   317,   318,   319,   320,     0,     0,
       0,     0,     0,     0,   617,    55,     0,     0,     0,     0,
       0,     0,     0,   321,   267,   268,   269,   270,   271,   272,
     273,   274,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
       0,     0,     0,     0,     0,     0,     0,   275,     0,     0,
       0,     0,     0,     0,  -109,    83,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,     0,     0,     0,     0,     0,     0,  -105,     0,     0,
       0,     0,     0,     0,     0,  -106,    46,    47,    48,    49,
     -81,    51,    52,    53,    46,    47,    48,   -85,   -85,    51,
      52,    53,     0,     0,     0,     0,     0,     0,   -81,     0,
       0,     0,     0,     0,     0,     0,   -85,    46,    47,    48,
     -89,   -89,   -89,    52,    53,    46,    47,   -93,   -93,   -93,
     -93,    52,    53,     0,     0,     0,     0,     0,     0,   -89,
       0,     0,     0,     0,     0,     0,     0,   -93,    46,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,    83,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,     0,     0,     0,     0,     0,     0,
    -104,     0,     0,     0,     0,     0,     0,     0,  -103,    46,
      47,   -99,   -99,   -99,   -99,    52,    53,    46,    47,   -98,
     -98,   -98,   -98,    52,    53,     0,     0,     0,     0,     0,
       0,   -99,     0,     0,     0,     0,     0,     0,     0,   -98,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,     0,     0,     0,     0,
       0,     0,  -108,     0,     0,     0,     0,     0,     0,     0,
    -107,    46,    47,    48,    49,    50,    51,    52,    53,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,     0,     0,     0,
       0,     0,     0,   -75,     0,     0,     0,     0,     0,     0,
       0,  -134,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,     0,     0,
       0,     0,     0,     0,  -135,     0,     0,     0,     0,     0,
       0,     0,  -133,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,     0,
       0,     0,     0,     0,     0,  -110,     0,     0,     0,     0,
       0,     0,     0,  -116,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
       0,     0,     0,     0,     0,     0,  -124,     0,     0,     0,
       0,     0,     0,     0,  -111,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,     0,     0,     0,     0,     0,     0,  -127,     0,     0,
       0,     0,     0,     0,     0,  -126,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,     0,     0,     0,     0,     0,     0,  -125,     0,
       0,     0,     0,     0,     0,     0,  -117
};

static const yytype_int16 yycheck[] =
{
       0,     0,   357,   401,   394,   283,    11,   362,    29,     1,
       1,     1,     1,     1,     1,     1,    16,    17,     1,     1,
      20,    20,     1,     1,    29,     1,     0,   167,     1,   169,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    31,
      31,    31,    31,    31,    31,    31,    20,     1,    31,    31,
      20,    29,    31,   331,    30,    31,    32,    33,    31,   457,
     450,    61,   417,    63,     1,    65,     3,     4,     5,     6,
       1,     8,   212,   213,   214,     0,     0,    31,    15,    16,
      17,    29,    30,     0,    29,    30,     1,    87,     3,     4,
       5,     6,    32,     8,    31,    32,    20,     6,    29,     1,
      15,    16,    17,    20,    19,    20,     1,    22,    23,    24,
      25,    26,    27,     1,     7,     1,    31,     1,     6,    34,
      35,     1,     6,    32,    33,     0,    11,    29,     1,     1,
      29,    19,    20,   488,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    29,    32,    20,     1,    32,     1,    29,
       3,     4,     5,     6,     1,     8,    29,   156,    30,    31,
      32,    33,    15,    16,    17,   165,   166,   167,    32,   169,
       6,     1,    32,   528,    29,   175,     6,     0,    31,    32,
       6,     0,    29,     1,    32,    21,   185,    11,     6,    19,
      20,   165,   166,    29,   194,    31,   196,    20,     6,     1,
     124,    20,    32,    29,     6,     6,   205,     6,    32,   209,
      32,   211,   212,   213,   214,     6,    32,    19,    20,    32,
     194,    29,   196,    31,     6,    11,   226,   227,   228,   229,
      32,    32,    33,    32,    33,   209,     0,   211,    29,    21,
     240,   165,   166,    29,     6,     6,   170,    35,   165,   166,
      32,    33,   226,   227,   228,   229,    20,    29,   398,     1,
     260,     3,     4,     5,     6,    11,     8,    29,    29,    31,
     194,    29,   196,    15,    16,    17,    18,   194,     6,   196,
       6,    32,   282,     1,     1,   209,    32,   211,     6,    31,
     165,   166,   209,    21,   211,    21,   296,     1,   215,    10,
      11,    29,   226,   227,   228,   229,    32,    33,   225,   226,
     227,   228,   229,    29,   454,     0,     6,     6,    29,   194,
      11,   196,     7,     8,     9,    10,    11,    12,    13,    14,
     330,    21,    21,     6,   209,    29,   211,    32,    29,    29,
      29,    31,   165,   166,    29,    30,   165,   166,    10,    11,
      12,   226,   227,   228,   229,    29,    29,   357,    31,    10,
      11,    12,   362,    10,    11,    12,    29,   367,    10,    11,
      32,   194,    32,   196,    32,   194,    32,   196,    10,    11,
      12,    32,    33,    32,    33,    32,   209,    29,   211,    34,
     209,    32,   211,    32,   394,    32,   396,    32,   398,    29,
      32,   165,   166,   226,   227,   228,   229,   226,   227,   228,
     229,    32,    33,   553,    29,   555,     1,   417,     9,    10,
      11,    12,   422,     9,    10,    11,    12,     1,    32,   569,
     194,   571,   196,     7,     8,     9,    10,    11,    12,    13,
      14,    32,    33,    32,    33,   209,    32,   211,    32,    33,
     450,    11,   452,    32,   454,    32,    33,    31,    32,    33,
      32,    33,   226,   227,   228,   229,    32,    10,    11,   609,
     610,   611,    32,    33,    10,    11,   616,   617,   618,     1,
       7,     3,     4,     5,     6,    11,     8,    29,   488,    32,
      33,    32,    33,    15,    16,    17,    32,    19,    20,    32,
      22,    23,    24,    25,    26,    27,    32,    33,     7,    31,
      10,    11,    34,    35,    29,     1,    32,     3,     4,     5,
       6,    32,     8,    32,     9,    10,    11,    12,   528,    15,
      16,    17,    32,    19,    20,    11,    22,    23,    24,    25,
      26,    27,    10,    11,    32,    31,    29,    32,    34,    35,
      32,    10,    11,   553,    32,   555,    32,    33,     1,    32,
       3,     4,     5,     6,    32,     8,    32,   567,   568,   569,
      29,   571,    15,    16,    17,    35,    19,    20,     1,    22,
      23,    24,    25,    26,    27,    29,    30,    31,    31,    29,
      30,    34,    35,   567,   568,     1,    32,    33,   598,    32,
     600,     7,     8,     9,    10,    11,    12,    13,    14,   609,
     610,   611,    32,   613,    32,   615,   616,   617,   618,     9,
      10,    11,    12,    29,   598,    31,   600,   551,   552,     9,
      10,    11,    12,    32,    33,   635,   636,   637,   638,   613,
      32,   615,    32,   567,   568,     9,    10,    11,    12,    32,
     567,   568,    32,    33,     9,    10,    11,    12,   582,     6,
     584,   635,   636,   637,   638,    29,     3,     4,     5,     6,
      32,     8,    19,    20,   598,    32,   600,    32,    15,    16,
      17,   598,   606,   600,   608,    29,    30,    31,    29,   613,
      35,   615,   567,   568,    31,    29,   613,    32,   615,     7,
       8,     9,    10,    11,    12,    13,    14,   631,   632,   633,
     634,   635,   636,   637,   638,    32,    33,    29,   635,   636,
     637,   638,     1,   598,    32,   600,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,   613,    32,
     615,    29,    13,    14,   567,   568,    29,    29,   567,   568,
      10,    11,    31,    32,    33,    10,    11,    12,     1,    29,
     635,   636,   637,   638,     7,     8,     9,    10,    11,    12,
      13,    14,    32,    33,    29,   598,    29,   600,    29,   598,
      32,   600,     9,    10,    11,    12,    32,    30,    31,    32,
     613,    32,   615,    32,   613,     1,   615,     3,     4,     5,
       6,    32,     8,   567,   568,    32,    33,    10,    11,    15,
      16,    17,   635,   636,   637,   638,   635,   636,   637,   638,
      32,     7,     8,     9,    20,    31,    32,    13,    14,    32,
      33,     1,   185,     0,   598,   205,   600,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,   127,    -1,    -1,   613,
      17,   615,    -1,    20,    -1,     9,    10,    11,    12,    -1,
      30,    31,    32,     8,     9,    10,    11,    12,    13,    14,
      -1,   635,   636,   637,   638,    -1,    43,    44,    32,    46,
      47,    48,    49,    50,    51,    52,    53,    32,    55,    -1,
      -1,    -1,    59,    -1,    61,    -1,    63,     8,     9,    10,
      11,    12,    13,    14,    71,     9,    10,    11,    12,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    29,     1,
      87,     3,     4,     5,     6,    -1,     8,    -1,    32,    33,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    10,    11,    12,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
     127,     8,    -1,    -1,   131,    29,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,     1,    -1,    34,    35,   156,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,     1,   175,     3,
       4,     5,     6,    29,     8,    31,   183,    -1,   185,    -1,
      -1,    15,    16,    17,    32,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,   205,    -1,
      34,    35,    10,    11,    12,   212,   213,   214,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    29,     9,    10,    11,    12,    -1,    15,    16,    17,
      -1,    19,    20,   240,    22,    23,    24,    25,    26,    27,
      -1,    -1,   249,    31,    -1,    32,    34,    35,    -1,     9,
      10,    11,    12,   260,   261,    -1,     9,    10,    11,    12,
     267,   268,   269,   270,   271,   272,   273,   274,   275,    -1,
      -1,     1,    32,     3,     4,     5,     6,    -1,     8,    32,
      33,    -1,    -1,    -1,   291,    15,    16,    17,    -1,   296,
      -1,    -1,    22,    23,    24,    25,    26,    27,   305,    -1,
      -1,    31,    -1,    -1,    34,    -1,   313,   314,   315,   316,
     317,   318,   319,   320,   321,    10,    11,    12,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    32,    33,   346,
     347,   348,   349,   350,   351,   352,   353,   354,    31,     1,
     357,     3,     4,     5,     6,   362,     8,    -1,    -1,    -1,
     367,    -1,   369,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,   392,    -1,   394,    -1,   396,
      -1,    -1,    -1,    17,   401,     9,    10,    11,    12,   406,
     407,   408,   409,   410,   411,   412,   413,   414,    -1,    -1,
     417,     9,    10,    11,    12,   422,    40,   424,    32,    33,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    -1,    32,    33,    -1,    61,    -1,    63,
      -1,   448,    -1,   450,    -1,   452,     9,    10,    11,    12,
     457,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,    -1,    -1,    -1,     0,     1,    32,
       3,     4,     5,     6,    -1,     8,    -1,     9,    10,    11,
      12,   488,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      32,    34,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,   528,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    32,    34,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,   175,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,     1,    31,    -1,
      -1,    34,    35,     7,     8,     9,    10,    11,    12,    13,
      14,     8,     9,    10,    11,    12,    13,    14,   212,   213,
     214,     9,    10,    11,    12,    -1,    -1,    31,    32,    -1,
      -1,    -1,   609,   610,   611,    32,    33,    -1,    -1,   616,
     617,   618,    -1,    -1,    32,    33,   240,     7,     8,     9,
      10,    11,    12,    13,    14,   249,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,   260,   261,    -1,    29,
      30,    -1,    32,   267,   268,   269,   270,   271,   272,   273,
     274,   275,     1,    32,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   296,    22,    23,    24,    25,    26,    27,    -1,
      -1,   305,    31,    -1,    -1,    34,    35,    -1,    -1,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    10,    11,
      12,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      32,    33,   346,   347,   348,   349,   350,   351,   352,   353,
     354,    31,     1,   357,     3,     4,     5,     6,   362,     8,
      -1,    -1,    -1,   367,    -1,   369,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
     394,    -1,   396,    17,     7,     8,     9,    10,    11,    12,
      13,    14,   406,   407,   408,   409,   410,   411,   412,   413,
     414,    -1,    -1,   417,    -1,    -1,    29,    30,   422,    32,
     424,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,
      -1,     9,    10,    11,    12,    -1,   450,    -1,   452,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    29,    -1,    87,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    19,    20,   488,    22,    23,    24,    25,    26,
      27,    -1,    -1,    29,    31,     7,     8,    34,    35,    -1,
      -1,    13,    14,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    19,    20,   528,    22,    23,    24,    25,    26,
      27,    -1,    -1,    29,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,   175,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,   212,   213,
     214,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   609,   610,   611,    31,    -1,
      -1,    34,   616,   617,   618,    -1,   240,     7,     8,     9,
      10,    11,    12,    13,    14,   249,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,   260,   261,    -1,    29,
      30,    -1,    32,   267,   268,   269,   270,   271,   272,   273,
     274,   275,     1,    32,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   296,    22,    23,    24,    25,    26,    27,    -1,
      -1,   305,    31,    -1,    -1,    34,    35,    -1,    -1,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,     9,    10,
      11,    12,   346,   347,   348,   349,   350,   351,   352,   353,
     354,    31,     1,   357,     3,     4,     5,     6,   362,     8,
      -1,    32,    33,   367,    -1,   369,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
     394,    -1,   396,    17,     7,     8,     9,    10,    11,    12,
      13,    14,   406,   407,   408,   409,   410,   411,   412,   413,
     414,    -1,    -1,   417,    -1,    -1,    -1,    30,   422,    32,
     424,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,
      -1,     9,    10,    11,    12,    -1,   450,    -1,   452,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    29,    -1,    87,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    19,    20,   488,    22,    23,    24,    25,    26,
      27,    -1,    -1,    29,    31,     7,     8,    34,    35,    -1,
      -1,    13,    14,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    19,    20,   528,    22,    23,    24,    25,    26,
      27,    -1,    -1,    29,    31,    -1,    -1,    34,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,   175,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    -1,    -1,    -1,    -1,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,   212,   213,
     214,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   609,   610,   611,    31,    -1,
      -1,    34,   616,   617,   618,    -1,   240,     7,     8,     9,
      10,    11,    12,    13,    14,   249,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,   260,   261,    -1,    -1,
      30,    -1,    32,   267,   268,   269,   270,   271,   272,   273,
     274,   275,     1,    32,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   296,    22,    23,    24,    25,    26,    27,    -1,
      -1,   305,    31,    -1,    -1,    34,    35,    -1,    -1,   313,
     314,   315,   316,   317,   318,   319,   320,   321,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,     9,    10,    11,
      12,    30,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     0,     1,   357,     3,     4,     5,     6,   362,     8,
      32,    33,    -1,   367,    -1,   369,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
     394,     8,   396,    17,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
     414,    -1,    -1,   417,    31,    32,    -1,    -1,   422,    -1,
     424,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,
      -1,     9,    10,    11,    12,    -1,   450,    -1,   452,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    29,    -1,    87,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,     9,    10,    11,    12,
      -1,    15,    16,    17,   488,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    29,    31,    -1,    -1,
      34,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    19,    20,   528,    22,    23,    24,    25,    26,
      27,    -1,    -1,    29,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,   175,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,   212,   213,
     214,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   609,   610,   611,    31,    -1,
      -1,    34,   616,   617,   618,    -1,   240,     7,     8,     9,
      10,    11,    12,    13,    14,   249,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,   260,   261,    -1,    -1,
      30,    -1,    32,   267,   268,   269,   270,   271,   272,   273,
     274,   275,     1,    32,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   296,    22,    23,    24,    25,    26,    27,    -1,
      -1,   305,    31,    -1,    -1,    34,    35,    -1,    -1,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,     7,     8,     9,    15,    16,    17,    13,    14,
      -1,    -1,   346,   347,   348,   349,   350,   351,   352,   353,
     354,    31,     1,   357,     3,     4,     5,     6,   362,     8,
      -1,    -1,    -1,   367,    -1,   369,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
     394,    -1,   396,    17,     7,     8,     9,    10,    11,    12,
      13,    14,   406,   407,   408,   409,   410,   411,   412,   413,
     414,    -1,    -1,   417,    -1,    -1,    -1,    30,   422,    32,
     424,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    -1,     7,     8,     9,    61,    -1,    63,
      13,    14,    -1,    -1,    -1,    -1,   450,    -1,   452,    -1,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,   488,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,   528,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,   175,    -1,    15,    16,    17,    17,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,     1,    -1,    31,
      -1,    -1,    34,     7,     8,     9,    10,    11,    12,    13,
      14,     3,     4,     5,     6,    -1,     8,    48,   212,   213,
     214,    52,    53,    15,    16,    17,    -1,    31,    32,    -1,
      61,    -1,    63,    -1,    -1,   609,   610,   611,    -1,    31,
      -1,    -1,   616,   617,   618,    -1,   240,    -1,    79,    -1,
      81,    82,    -1,    -1,    -1,   249,    87,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,   260,   261,    -1,    -1,
      -1,    -1,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,     1,    32,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   296,    22,    23,    24,    25,    26,    27,    -1,
      -1,   305,    31,    -1,    -1,    34,    35,    -1,    -1,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,   175,    15,    16,    17,    -1,    -1,
      -1,    -1,   346,   347,   348,   349,   350,   351,   352,   353,
     354,    31,    32,   357,     7,     8,     9,    10,   362,    12,
      13,    14,    -1,   367,    -1,   369,    -1,    -1,     1,    -1,
      -1,   212,   213,   214,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
     394,    -1,   396,    -1,    -1,    -1,    29,    30,    31,   240,
      -1,    -1,   406,   407,   408,   409,   410,   411,   412,   413,
     414,    -1,    -1,   417,    -1,    -1,    -1,    -1,   422,   260,
     424,    -1,    17,    -1,    -1,    -1,    -1,    -1,   269,   270,
     271,   272,   273,   274,   275,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,   450,    -1,   452,    15,
      16,    17,    47,    -1,    -1,   296,    -1,     1,    -1,     3,
       4,     5,     6,    29,     8,    31,    61,    -1,    63,    -1,
      -1,    15,    16,    17,   315,   316,   317,   318,   319,   320,
     321,    -1,    -1,    -1,   488,    80,    -1,    31,    -1,    -1,
      -1,    -1,    87,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,   346,   347,   348,   349,    -1,
     351,   352,    -1,   354,     0,     1,   357,     3,     4,     5,
       6,   362,     8,    -1,   528,    -1,   367,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
       4,     5,     6,   394,     8,   396,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,   406,   407,   408,   409,    -1,
     411,   412,    -1,   414,    -1,    29,   417,    31,    -1,    -1,
     175,   422,    -1,    -1,    -1,    17,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,   609,   610,   611,    -1,   450,
      -1,   452,   616,   617,   618,    -1,    31,   212,   213,   214,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    61,
      -1,    63,    15,    16,    17,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,   240,    -1,   488,    31,    -1,
      15,    16,    17,    -1,    -1,    87,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,   260,    31,    -1,    -1,    34,
      -1,    -1,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,     1,    -1,     3,     4,     5,     6,   528,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,   296,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,   314,
     315,   316,   317,   318,   319,   320,   321,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,   175,    15,    16,    17,    -1,    -1,    -1,
      -1,   346,   347,   348,   349,   350,   351,   352,    29,   354,
      31,    -1,   357,    -1,    -1,    -1,    -1,   362,   609,   610,
     611,    -1,   367,    -1,    -1,   616,   617,   618,    -1,    -1,
     212,   213,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,   394,
      -1,   396,    -1,    -1,    15,    16,    17,    -1,   240,    -1,
      17,   406,   407,   408,   409,   410,   411,   412,    29,   414,
      31,    -1,   417,     1,    -1,    -1,    -1,   422,   260,     7,
       8,     9,    10,    11,    12,    13,    14,   269,   270,   271,
     272,   273,   274,   275,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    61,   450,    63,   452,    -1,    -1,
       7,     8,     9,    10,   296,    12,    13,    14,    -1,    -1,
      -1,    78,     7,     8,     9,    10,    11,    12,    13,    14,
      87,    -1,    -1,   315,   316,   317,   318,   319,   320,   321,
      -1,    -1,    -1,   488,    -1,    30,    -1,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   346,   347,   348,   349,    -1,   351,
     352,    29,   354,     0,     1,   357,     3,     4,     5,     6,
     362,     8,    -1,   528,    -1,   367,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,   394,     8,   396,    -1,    -1,    -1,   175,    -1,
      15,    16,    17,    -1,   406,   407,   408,   409,    -1,   411,
     412,    -1,   414,    -1,    29,   417,    31,     7,     8,     9,
     422,    -1,    12,    13,    14,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,   212,   213,   214,    -1,    -1,
      15,    16,    17,    -1,   609,   610,   611,    -1,   450,    -1,
     452,   616,   617,   618,     0,     1,    31,     3,     4,     5,
       6,    -1,     8,   240,    -1,    17,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,   260,    -1,    31,   488,    -1,    34,    -1,
      -1,    -1,    -1,   270,   271,   272,    -1,    49,   275,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    61,
      -1,    63,    -1,    15,    16,    17,     7,     8,     9,   296,
      -1,    12,    13,    14,    -1,    77,   528,    29,    -1,    31,
      -1,     7,     8,     9,    10,    87,    12,    13,    14,   316,
     317,   318,    -1,    -1,   321,     1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,   346,
     347,   348,    -1,    29,    30,    31,    -1,   354,    -1,    -1,
     357,    -1,    -1,    -1,    30,   362,    32,    33,    -1,    -1,
     367,    -1,     1,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,   609,   610,   611,
      -1,    -1,    -1,    -1,   616,   617,   618,   394,    -1,   396,
      29,    30,    31,   175,    -1,    -1,    -1,    -1,    -1,   406,
     407,   408,    -1,    -1,    17,    -1,    -1,   414,    -1,    -1,
     417,     7,     8,     9,    -1,   422,    12,    13,    14,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
     212,   213,   214,    15,    16,    17,    -1,    50,    -1,     3,
       4,     5,     6,   450,     8,   452,    -1,    29,    61,    31,
      63,    15,    16,    17,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,   260,     0,
       1,   488,     3,     4,     5,     6,    -1,     8,   270,   271,
      -1,    -1,    -1,   275,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,   296,    -1,    -1,    17,    -1,    -1,
      -1,   528,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,   316,   317,    -1,    -1,    -1,   321,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    55,    31,    -1,    -1,    34,
      35,    61,   175,    63,   346,   347,    -1,    -1,    -1,    -1,
      -1,    -1,   354,    -1,    -1,   357,    -1,    -1,    -1,    -1,
     362,    -1,    -1,    -1,    84,   367,    -1,    87,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,   212,
     213,   214,   609,   610,   611,    15,    16,    17,    -1,   616,
     617,   618,   394,    -1,   396,     1,    -1,     3,     4,     5,
       6,    31,     8,    -1,   406,   407,    -1,   240,    -1,    15,
      16,    17,   414,     0,     1,   417,     3,     4,     5,     6,
     422,     8,    -1,    -1,    -1,    31,    -1,   260,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,   271,    26,
      27,    -1,   275,    -1,    31,    -1,    -1,    34,   450,    -1,
     452,    -1,    -1,    -1,    -1,   175,    -1,     1,    -1,     3,
       4,     5,     6,   296,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,   317,    -1,   488,    31,   321,    -1,
      34,    35,   212,   213,   214,     1,    -1,     3,     4,     5,
       6,     1,     8,     3,     4,     5,     6,    -1,     8,    15,
      16,    17,    -1,   346,    -1,    15,    16,    17,    -1,    -1,
     240,   354,    -1,    -1,   357,    31,   528,    -1,    -1,   362,
      -1,    31,    -1,    -1,   367,    -1,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,   275,    -1,    -1,    15,    16,
      17,   394,    -1,   396,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,   406,    31,    -1,   296,    34,    -1,    -1,
      -1,   414,    -1,     1,   417,     3,     4,     5,     6,   422,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,   321,    -1,    -1,    -1,    -1,    -1,   609,   610,   611,
      -1,    -1,    -1,    31,   616,   617,   618,   450,    -1,   452,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,   354,    -1,    -1,   357,    15,    16,
      17,    -1,   362,    -1,    -1,    -1,    -1,   367,    -1,    -1,
      -1,    -1,    -1,    -1,    31,   488,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,   394,    -1,   396,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,   414,   528,    34,   417,    -1,    -1,
      -1,     1,   422,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
     450,    31,   452,    -1,    34,    35,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,   488,    34,
      35,    -1,    -1,    -1,    -1,    -1,   609,   610,   611,    -1,
      -1,    -1,    -1,   616,   617,   618,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,   528,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,   609,
     610,   611,    31,    -1,    -1,    34,   616,   617,   618,     1,
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
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
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
      24,    25,    26,    27,    -1,    -1,    -1,    31,     0,     1,
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
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,     1,    34,     3,     4,     5,     6,     1,     8,     3,
       4,     5,     6,    -1,     8,    15,    16,    17,    -1,    -1,
      -1,    15,    16,    17,    -1,     1,    -1,     3,     4,     5,
       6,    31,     8,    -1,    -1,    -1,    -1,    31,    -1,    15,
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
      -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    31,    15,    16,    17,    -1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      31,    15,    16,    17,    -1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,
      17,    -1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    31,    15,    16,    17,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    31,    15,    16,    17,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,
      16,    17,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    31,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    30,    -1,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    30,
      -1,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    30,    -1,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    30,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    30,
      -1,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    30,    -1,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    30,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      30,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    30,    -1,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    30,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      30,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
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
      -1,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    32,    33,     7,     8,     9,    10,    11,
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
      32,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    29,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,     7,     8,     9,
      10,    11,    12,    13,    14,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,     7,     8,     9,    10,    11,    12,    13,
      14,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29
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
      11,    12,    13,    14,    29,    30,    21,    21,     1,    31,
       1,    31,     1,    31,     1,    31,     1,    61,    76,     1,
      61,    50,     0,     1,    39,    29,    11,    10,    12,     9,
       8,    13,    14,     7,    30,    70,     1,    31,    76,    29,
      31,    76,    70,     1,    69,    70,     1,    67,     1,    65,
       1,    64,     1,    66,    67,    67,     1,    63,     1,    76,
       1,    18,    61,    79,     1,    61,     1,    61,    62,    29,
      29,    32,    32,     1,    25,    40,    51,    52,    53,    54,
      58,    77,     1,    64,     1,    65,     1,    66,     1,    67,
       1,    69,     1,    67,     1,    67,     1,    70,     1,    63,
       1,    61,    73,    74,    29,    30,    44,    29,    30,    31,
      32,    32,    32,    32,    32,    32,    32,    29,    32,    29,
      25,    54,    35,    53,    76,    33,    32,     1,     1,    46,
      47,    48,    76,    77,     1,    42,    29,     1,    29,    29,
       1,    29,     1,    29,    25,    54,    25,    54,     1,    62,
       1,    62,    54,    61,    45,    33,    76,    46,    54,    25,
      54,    25,    29,    29,    29,    32,    48,    43,    54,    54,
      62,    62,     1,    62,    49,    32,    32,    32,    32,    32,
      49,    54,    54,    54,    54,     6,     3,     4,     5,     6,
      31,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    75,    76,    78,     6,     6,     3,     4,     5,     6,
      31,    71,    72,    75,    76,    78,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    30,    19,    20,    22,    23,
      24,    26,    27,    34,    49,    55,    56,    57,    59,    60,
      61,    76,     3,     4,     5,     6,    31,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    75,    76,    78,
      29,     1,    29,     7,     8,     9,    10,    11,    12,    13,
      14,    30,     6,    19,    20,     1,    22,    23,    24,    26,
      27,    34,    49,    55,    56,    57,    59,    60,    61,    29,
      30,     1,     1,    61,     1,    61,    11,    10,    12,     9,
       8,    13,    14,     7,    30,    70,     1,    31,     1,    61,
      70,     1,    31,     3,     4,     5,     6,    31,    70,    71,
      72,    75,    76,    78,     1,    69,    70,     1,    67,     1,
      65,     1,    64,     1,    66,    67,    67,     1,    63,    21,
      21,     1,    31,     1,    31,     1,    31,     1,    31,     1,
      61,    50,    29,    76,     1,    61,    11,    10,    12,     9,
       8,    13,    14,     7,    30,    70,     1,    31,     3,     4,
       5,     6,    31,    70,    71,    72,    75,    76,    78,     1,
      69,    70,     1,    67,     1,    65,     1,    64,     1,    66,
      67,    67,     1,    63,    21,    21,    29,     1,    31,     1,
      31,     1,    31,     1,    31,     1,    61,    50,    29,     1,
      32,    32,     1,    64,     1,    65,     1,    66,     1,    67,
       1,    69,     1,    67,     1,    67,     1,    70,     1,    63,
      74,    32,    32,    74,     1,    61,    70,     1,    31,     1,
      76,     1,    61,    79,     1,    61,     1,    62,    29,    29,
      51,    29,    30,    32,    32,     1,    64,     1,    65,     1,
      66,     1,    67,     1,    69,     1,    67,     1,    67,     1,
      70,     1,    63,    74,     1,    61,    70,     1,    31,     1,
      76,     1,    61,    79,     1,    61,     1,    62,    29,    29,
      51,    32,    32,    32,    32,    74,    32,    32,    32,    32,
      32,    32,    32,    29,    32,    29,    35,     1,    32,    32,
      32,    74,    32,    32,    32,    32,    32,    32,    32,    29,
      32,    29,    35,    32,    29,     1,    29,    29,     1,    29,
       1,    29,    25,    54,    25,    54,    62,     1,    62,    32,
      29,     1,    29,    29,     1,    29,     1,    29,    25,    54,
      25,    54,    62,     1,    62,    54,    25,    54,    25,    29,
      29,    29,    54,    25,    54,    25,    29,    29,    29,    54,
      54,    62,    62,     1,    62,    54,    54,    62,    62,     1,
      62,    32,    32,    32,    32,    32,    32,    32,    32,    54,
      54,    54,    54,    54,    54,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    38,    38,    39,    39,    39,
      40,    40,    40,    40,    40,    42,    43,    41,    44,    45,
      41,    46,    46,    47,    47,    47,    48,    48,    48,    50,
      49,    51,    51,    52,    52,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    61,    61,    61,    61,    62,    62,    63,
      63,    63,    63,    64,    64,    64,    64,    65,    65,    65,
      65,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    68,    69,    69,    69,    69,
      70,    70,    71,    71,    71,    71,    72,    72,    73,    73,
      73,    74,    74,    75,    75,    75,    75,    75,    76,    77,
      77,    77,    77,    78,    78,    78,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       3,     2,     4,     4,     3,     0,     0,     8,     0,     0,
       7,     0,     1,     3,     1,     1,     2,     1,     1,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     5,     5,     5,     5,
       5,     5,     2,     2,     2,     2,     5,     7,     6,     5,
       7,     6,     2,     2,     3,     3,     3,     9,     9,     9,
       9,     4,     2,     1,     3,     3,     3,     0,     1,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       1,     2,     1,     1,     1,     1,     1,     4,     3,     1,
       1,     1,     0,     1,     1,     3,     3,     2,     1,     1,
       1,     2,     2,     1,     1,     1,     1
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
#line 3776 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3782 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3788 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3794 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3800 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3806 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3812 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3818 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3824 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3830 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3836 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3842 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3848 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3854 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3860 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3866 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3872 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3878 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3884 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3890 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3896 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_1: /* @1  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3902 "src/bison/grammar.c"
        break;

    case YYSYMBOL_46_param_list_opt: /* param_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3908 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3914 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3920 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3926 "src/bison/grammar.c"
        break;

    case YYSYMBOL_51_block_item_list_opt: /* block_item_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3932 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3938 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3944 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3950 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3956 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3962 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3968 "src/bison/grammar.c"
        break;

    case YYSYMBOL_else_error: /* else_error  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3974 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3980 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3986 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3992 "src/bison/grammar.c"
        break;

    case YYSYMBOL_62_expression_opt: /* expression.opt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3998 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4004 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4010 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4016 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4022 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4028 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4034 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4040 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4046 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4052 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4058 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4064 "src/bison/grammar.c"
        break;

    case YYSYMBOL_74_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4070 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4076 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 130 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 4082 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4088 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4094 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4100 "src/bison/grammar.c"
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
#line 4409 "src/bison/grammar.c"
    break;

  case 4: /* prog: error  */
#line 137 "src/bison/grammar.y"
            {
        // idk if this is the best solution
        // actually dont work properly
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
    }
#line 4419 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration_list external_declaration  */
#line 144 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4425 "src/bison/grammar.c"
    break;

  case 6: /* external_declaration_list: external_declaration  */
#line 145 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4431 "src/bison/grammar.c"
    break;

  case 9: /* external_declaration: statement  */
#line 150 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4441 "src/bison/grammar.c"
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
#line 4470 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 181 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4480 "src/bison/grammar.c"
    break;

  case 12: /* var_declaration: type id '=' error  */
#line 186 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4491 "src/bison/grammar.c"
    break;

  case 13: /* var_declaration: id id '=' error  */
#line 192 "src/bison/grammar.y"
                      {
        show_error_range((yylsp[-3]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-3].sym)->name);
        symbol_free((yyvsp[-3].sym));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4502 "src/bison/grammar.c"
    break;

  case 14: /* var_declaration: id id ';'  */
#line 198 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-2]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-2].sym)->name);
        symbol_free((yyvsp[-2].sym));
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 4513 "src/bison/grammar.c"
    break;

  case 15: /* @1: %empty  */
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
    }
#line 4555 "src/bison/grammar.c"
    break;

  case 16: /* $@2: %empty  */
#line 242 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4561 "src/bison/grammar.c"
    break;

  case 17: /* func_declaration: type id '(' @1 param_list.opt $@2 ')' compound_stmt  */
#line 242 "src/bison/grammar.y"
                                                              {
        (yyval.ast) = ast_userfunc_init((yyloc), current_context, (yyvsp[-4].ast), ast_params_init((yylsp[-3]), (yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4571 "src/bison/grammar.c"
    break;

  case 18: /* $@3: %empty  */
#line 247 "src/bison/grammar.y"
               {
        previous_context = current_context;
        list_push(&contexts, context_init("unnamed-func"));
        current_context = list_peek_last(&contexts);
        context_push_scope(current_context);
    }
#line 4582 "src/bison/grammar.c"
    break;

  case 19: /* $@4: %empty  */
#line 252 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4588 "src/bison/grammar.c"
    break;

  case 20: /* func_declaration: type '(' $@3 param_list.opt $@4 ')' compound_stmt  */
#line 252 "src/bison/grammar.y"
                                                              {
        show_error_range((yylsp[-5]), "expected identifier before " WHT "'('" RESET "\n");
        free((yyvsp[-6].pchar));
        LIST_FREE((yyvsp[-3].list), { ast_free(__IT__->data); });
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
        current_context = previous_context;
    }
#line 4601 "src/bison/grammar.c"
    break;

  case 21: /* param_list.opt: %empty  */
#line 262 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4607 "src/bison/grammar.c"
    break;

  case 23: /* params_list: params_list ',' param_decl  */
#line 266 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4613 "src/bison/grammar.c"
    break;

  case 24: /* params_list: param_decl  */
#line 267 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4619 "src/bison/grammar.c"
    break;

  case 25: /* params_list: error  */
#line 268 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4628 "src/bison/grammar.c"
    break;

  case 26: /* param_decl: type id  */
#line 274 "src/bison/grammar.y"
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
#line 4647 "src/bison/grammar.c"
    break;

  case 27: /* param_decl: type  */
#line 288 "src/bison/grammar.y"
           {
        show_error_range((yylsp[0]), "expected identifier after " BGRN "'%s'" RESET "\n", (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
        (yyval.ast) = NULL;
    }
#line 4657 "src/bison/grammar.c"
    break;

  case 28: /* param_decl: id  */
#line 293 "src/bison/grammar.y"
         {
        show_error_range((yylsp[0]), "unknown type name for " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
        symbol_free((yyvsp[0].sym));
        (yyval.ast) = NULL;
    }
#line 4667 "src/bison/grammar.c"
    break;

  case 29: /* $@5: %empty  */
#line 300 "src/bison/grammar.y"
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
#line 4685 "src/bison/grammar.c"
    break;

  case 30: /* compound_stmt: '{' $@5 block_item_list.opt '}'  */
#line 312 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyloc), (yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 4697 "src/bison/grammar.c"
    break;

  case 31: /* block_item_list.opt: block_item_list  */
#line 321 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4703 "src/bison/grammar.c"
    break;

  case 32: /* block_item_list.opt: %empty  */
#line 322 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4709 "src/bison/grammar.c"
    break;

  case 33: /* block_item_list: block_item_list block_item  */
#line 325 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4715 "src/bison/grammar.c"
    break;

  case 34: /* block_item_list: block_item  */
#line 326 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4721 "src/bison/grammar.c"
    break;

  case 44: /* io_stmt: READ '(' id ')' ';'  */
#line 342 "src/bison/grammar.y"
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
#line 4737 "src/bison/grammar.c"
    break;

  case 45: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 353 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4746 "src/bison/grammar.c"
    break;

  case 46: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 357 "src/bison/grammar.y"
                                       {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4755 "src/bison/grammar.c"
    break;

  case 47: /* io_stmt: WRITE '(' error ')' ';'  */
#line 361 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4765 "src/bison/grammar.c"
    break;

  case 48: /* io_stmt: READ '(' error ')' ';'  */
#line 366 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected identifier before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4775 "src/bison/grammar.c"
    break;

  case 49: /* io_stmt: READ '(' id ')' error  */
#line 371 "src/bison/grammar.y"
                            {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4786 "src/bison/grammar.c"
    break;

  case 50: /* io_stmt: WRITE '(' expression ')' error  */
#line 377 "src/bison/grammar.y"
                                     {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4797 "src/bison/grammar.c"
    break;

  case 51: /* io_stmt: WRITE '(' string_literal ')' error  */
#line 383 "src/bison/grammar.y"
                                         {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4808 "src/bison/grammar.c"
    break;

  case 52: /* io_stmt: WRITE error  */
#line 389 "src/bison/grammar.y"
                  {
        show_error_range((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4818 "src/bison/grammar.c"
    break;

  case 53: /* io_stmt: READ error  */
#line 394 "src/bison/grammar.y"
                 {
        show_error_range((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4828 "src/bison/grammar.c"
    break;

  case 54: /* expr_stmt: expression ';'  */
#line 401 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 4834 "src/bison/grammar.c"
    break;

  case 55: /* expr_stmt: error ';'  */
#line 402 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 4843 "src/bison/grammar.c"
    break;

  case 56: /* cond_stmt: IF '(' expression ')' statement  */
#line 408 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 4851 "src/bison/grammar.c"
    break;

  case 57: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 411 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4859 "src/bison/grammar.c"
    break;

  case 58: /* cond_stmt: IF '(' expression ')' ELSE statement  */
#line 414 "src/bison/grammar.y"
                                           {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-3].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4870 "src/bison/grammar.c"
    break;

  case 59: /* cond_stmt: IF '(' error ')' statement  */
#line 420 "src/bison/grammar.y"
                                            {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4880 "src/bison/grammar.c"
    break;

  case 60: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 425 "src/bison/grammar.y"
                                                {
        show_error_range((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4891 "src/bison/grammar.c"
    break;

  case 61: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 431 "src/bison/grammar.y"
                                      {
        show_error_range((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4901 "src/bison/grammar.c"
    break;

  case 62: /* cond_stmt: IF error  */
#line 436 "src/bison/grammar.y"
               {
        show_error((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 4910 "src/bison/grammar.c"
    break;

  case 63: /* else_error: ELSE statement  */
#line 442 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4920 "src/bison/grammar.c"
    break;

  case 64: /* else_error: error ELSE statement  */
#line 447 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4930 "src/bison/grammar.c"
    break;

  case 65: /* jmp_stmt: RETURN expression ';'  */
#line 454 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyloc), (yyvsp[-1].ast)); }
#line 4936 "src/bison/grammar.c"
    break;

  case 66: /* jmp_stmt: RETURN error ';'  */
#line 455 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 4945 "src/bison/grammar.c"
    break;

  case 67: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 461 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init((yyloc), current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4953 "src/bison/grammar.c"
    break;

  case 68: /* iter_stmt: FOR '(' error ';' expression.opt ';' expression.opt ')' statement  */
#line 464 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-6]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4965 "src/bison/grammar.c"
    break;

  case 69: /* iter_stmt: FOR '(' expression.opt ';' error ';' expression.opt ')' statement  */
#line 471 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-4]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4977 "src/bison/grammar.c"
    break;

  case 70: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' error ')' statement  */
#line 478 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4989 "src/bison/grammar.c"
    break;

  case 71: /* iter_stmt: FOR '(' error ')'  */
#line 485 "src/bison/grammar.y"
                        {
        show_error((yylsp[0]), "expected " WHT "';'" RESET " before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 4998 "src/bison/grammar.c"
    break;

  case 72: /* iter_stmt: FOR error  */
#line 489 "src/bison/grammar.y"
                {
        show_error((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5007 "src/bison/grammar.c"
    break;

  case 74: /* expression: unary_expr '=' logical_or_expr  */
#line 496 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyloc), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 5013 "src/bison/grammar.c"
    break;

  case 75: /* expression: unary_expr '=' error  */
#line 497 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5023 "src/bison/grammar.c"
    break;

  case 76: /* expression: error '=' logical_or_expr  */
#line 502 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-2]), "expected expression before " WHT "'='" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5033 "src/bison/grammar.c"
    break;

  case 77: /* expression.opt: %empty  */
#line 509 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 5039 "src/bison/grammar.c"
    break;

  case 80: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 514 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5048 "src/bison/grammar.c"
    break;

  case 81: /* logical_or_expr: logical_or_expr OR error  */
#line 518 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5058 "src/bison/grammar.c"
    break;

  case 82: /* logical_or_expr: error OR logical_and_expr  */
#line 523 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5068 "src/bison/grammar.c"
    break;

  case 84: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 531 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5077 "src/bison/grammar.c"
    break;

  case 85: /* logical_and_expr: logical_and_expr AND error  */
#line 535 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5087 "src/bison/grammar.c"
    break;

  case 86: /* logical_and_expr: error AND eq_expr  */
#line 540 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5097 "src/bison/grammar.c"
    break;

  case 88: /* eq_expr: eq_expr EQ rel_expr  */
#line 548 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5106 "src/bison/grammar.c"
    break;

  case 89: /* eq_expr: eq_expr EQ error  */
#line 552 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5116 "src/bison/grammar.c"
    break;

  case 90: /* eq_expr: error EQ rel_expr  */
#line 557 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5126 "src/bison/grammar.c"
    break;

  case 92: /* rel_expr: rel_expr REL list_expr  */
#line 565 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5135 "src/bison/grammar.c"
    break;

  case 93: /* rel_expr: rel_expr REL error  */
#line 569 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5145 "src/bison/grammar.c"
    break;

  case 94: /* rel_expr: error REL list_expr  */
#line 574 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5155 "src/bison/grammar.c"
    break;

  case 96: /* list_expr: add_expr DL_DG list_expr  */
#line 582 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5164 "src/bison/grammar.c"
    break;

  case 97: /* list_expr: add_expr COLON list_expr  */
#line 586 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5173 "src/bison/grammar.c"
    break;

  case 98: /* list_expr: add_expr DL_DG error  */
#line 590 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5183 "src/bison/grammar.c"
    break;

  case 99: /* list_expr: add_expr COLON error  */
#line 595 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5193 "src/bison/grammar.c"
    break;

  case 100: /* list_expr: error DL_DG list_expr  */
#line 600 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5203 "src/bison/grammar.c"
    break;

  case 101: /* list_expr: error COLON list_expr  */
#line 605 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5213 "src/bison/grammar.c"
    break;

  case 103: /* add_expr: add_expr ADD mult_expr  */
#line 613 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5222 "src/bison/grammar.c"
    break;

  case 104: /* add_expr: add_expr ADD error  */
#line 617 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5232 "src/bison/grammar.c"
    break;

  case 105: /* add_expr: error ADD mult_expr  */
#line 622 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5242 "src/bison/grammar.c"
    break;

  case 107: /* mult_expr: mult_expr MULT unary_expr  */
#line 630 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5251 "src/bison/grammar.c"
    break;

  case 108: /* mult_expr: mult_expr MULT error  */
#line 634 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5261 "src/bison/grammar.c"
    break;

  case 109: /* mult_expr: error MULT unary_expr  */
#line 639 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5271 "src/bison/grammar.c"
    break;

  case 111: /* unary_expr: unary_ops unary_expr  */
#line 647 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5280 "src/bison/grammar.c"
    break;

  case 117: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 660 "src/bison/grammar.y"
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
#line 5303 "src/bison/grammar.c"
    break;

  case 118: /* arg_expr_list: arg_expr_list ',' expression  */
#line 680 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5309 "src/bison/grammar.c"
    break;

  case 119: /* arg_expr_list: expression  */
#line 681 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5315 "src/bison/grammar.c"
    break;

  case 120: /* arg_expr_list: error  */
#line 682 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5324 "src/bison/grammar.c"
    break;

  case 122: /* arg_expr_list.opt: %empty  */
#line 689 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5330 "src/bison/grammar.c"
    break;

  case 123: /* primary_expr: id  */
#line 692 "src/bison/grammar.y"
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
#line 5345 "src/bison/grammar.c"
    break;

  case 125: /* primary_expr: '(' expression ')'  */
#line 703 "src/bison/grammar.y"
                         {
        if ((yyvsp[-1].ast)) {
            --(yyvsp[-1].ast)->rule_pos.first_column;
            ++(yyvsp[-1].ast)->rule_pos.last_column;
        }
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 5357 "src/bison/grammar.c"
    break;

  case 126: /* primary_expr: '(' error ')'  */
#line 710 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5366 "src/bison/grammar.c"
    break;

  case 127: /* primary_expr: id error  */
#line 714 "src/bison/grammar.y"
               {
        show_error_range((yylsp[0]), "expected " WHT "';'" RESET "\n");
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 5376 "src/bison/grammar.c"
    break;

  case 131: /* type: INT LIST  */
#line 726 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5388 "src/bison/grammar.c"
    break;

  case 132: /* type: FLOAT LIST  */
#line 733 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5400 "src/bison/grammar.c"
    break;

  case 133: /* constant: NUMBER_REAL  */
#line 742 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init((yyloc), K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5406 "src/bison/grammar.c"
    break;

  case 134: /* constant: NUMBER_INT  */
#line 743 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init((yyloc), K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5412 "src/bison/grammar.c"
    break;

  case 135: /* constant: NIL  */
#line 744 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init((yyloc), K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5418 "src/bison/grammar.c"
    break;

  case 136: /* string_literal: STR_LITERAL  */
#line 747 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyloc), (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5427 "src/bison/grammar.c"
    break;


#line 5431 "src/bison/grammar.c"

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

#line 753 "src/bison/grammar.y"


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
