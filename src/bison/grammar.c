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
#define YYLAST   11171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  703

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
     295,   316,   317,   320,   321,   324,   325,   328,   329,   330,
     331,   332,   333,   336,   347,   351,   355,   360,   365,   371,
     377,   385,   386,   392,   395,   398,   403,   408,   414,   421,
     422,   428,   431,   438,   445,   454,   455,   456,   461,   468,
     469,   472,   473,   477,   482,   489,   490,   494,   499,   506,
     507,   511,   516,   523,   524,   528,   533,   540,   541,   545,
     549,   554,   559,   564,   571,   572,   576,   581,   588,   589,
     593,   598,   605,   606,   612,   613,   614,   615,   618,   619,
     639,   640,   641,   647,   648,   651,   661,   662,   667,   671,
     678,   681,   682,   683,   690,   699,   700,   701,   704
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

#define YYTABLE_NINF (-129)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    5433,   530,  2535,  2900,  3793,   385,  3451,  4715,  9293,  9310,
     271,   322,   -24,   -17,    35,    74,  1181,  4365,  5465,    49,
    5501,  5533,  5565,  5597,  5629,  5661,  5693,  5725,  5757,  5789,
    5821,    85,   138,    90,   654,   729,   946,  2243, 10854, 10518,
    9327, 10530, 10542,  1057,   216, 10554,  9344,  4408,  4518,  4539,
    4637,  4709,  4518,  4518,  5853,  8402,   244,   287,    80,  1363,
    8408,  1496, 10566,    91,  2064,  3577,   121,  5885,  -383, 10578,
    5921,  5953,  8426,  8443,  8460,  8477,  8494,  8511,  8528,  8545,
    8562, 10590, 10602,   139,   -19,  5985,   234,    87, 10866,   150,
   10877, 10889,   581,   980,  1472,   952,  1509,   245,  1685,  1205,
    1215,  1277,  1406,   290,   134,   137,  9828,   151,   171,   175,
    9842,   181, 10614,   217,   220,  6017,  6049, 10626, 10638,  6081,
     228,  6116,  6151,  6186,    -1, 10900,   402, 10912,  1400, 10923,
    1332, 10935,  1364, 10946, 10958, 10969,  1497, 10981,  1535, 10992,
   11004, 11015,   396,  1376,   161,   273,   246,  6222,   251,   336,
    6254,   313,   339,   296,    11,   310,    12,    14,  1251,  3683,
    2435,  3362,  6286,  6318,   440,  8579, 10650,  6354,   449,   318,
     473,   569,   586,   103,  6386,   336,  6418,  6450,  6482,  6514,
    6546,  6578,  6610,  6642,  4600,    72,  6674,   107, 10818,   334,
   10662,   343,   600,   368,   453,   659,   377,  6706,  4600,  4600,
     226,   226,   847,   332,   667,   392,  6738,  6770,   432,   462,
    9854,   475,  6802,   332,  4600,  4600,  4600,  4600,  6834,  6866,
    6898,  6930,  6962,  2078,  9868,  9880,  9894,   435,  8596,    93,
     194,   451,   250,   418,  1878,  1559,  9906,  9361,  9920,  9932,
     771,  9946,   672,   390, 11027, 11038, 11050,  1767,  8613,  9344,
   11061, 11073,  3280, 11084,   519,  9378,  8630,  8647,  8664,  8681,
    8698,  8647,  8647,  8715, 10674,     2,   736,   527,   536,   546,
     554,  8732,  5465,  6994,  7029,  7064,  7099,  7134,  7169,   532,
    1057,  3316,  3835,  9423,   178,  8749,    52,   186,   639,   378,
     517,  1781,   444,  9437,  9395,  9450,  9464,   503,  9477,  7204,
    9412,  8766,  8783,  8800,  8817,  8834,  8783,  8783,  8851,   716,
     131,   140, 10686,   556,   567,   576,   598,  8868,  5465,   264,
     307,   979,  1103,  1304,  1439,   562,  7239,   602, 10830, 10842,
     628,  9958,   635,  8885,  8902,  8919,  8936,  8953,  8970,  8987,
    9004,  9021,  9972,  9984,   139,  9998,   641, 11096, 11107,   139,
    4847, 10206, 10218,    25,  9038, 10232,  9378, 10244, 10258,   785,
   10270,   627, 10284, 10296,  1225,   817,  1917,   477,  1816,   325,
    1702,   822,   833,   865,  1414,   128,  7274,    21,    39,   293,
    2179,  9055,  3609, 10698,   653,  5885,  7309,   734, 10010,   657,
    9072,  9089,  9106,  9123,  9140,  9157,  9174,  9191,  9208,  9491,
    9504,   139,   488,   613,  1528,   630,  9225,  3923,  9412,  4839,
    9558,   714,  9572,   698,  9585,  9599,  1461,   564,  1925,   702,
    2815,   337,  1899,   721,   779,   936,  1808,   341,   142,   145,
    1584,   303,  2441,  9242,  3824, 10710,   687,  5885,  1616,  7344,
   10024, 10036, 10310,   394, 10322,   572, 10336,   875, 10348,  1005,
   10362, 10374, 10388,  1084, 10400,  1151, 10414, 10426, 10440,   201,
     705, 11119, 11130,   741, 10050,   742, 10452, 10466,   139,   745,
     755, 10062,   768,   772, 10076,   773, 10722,   777,  7379,  7414,
     778,  7449,   814,  9518,  9531,  9612,   560,  9626,  1121,  9639,
    1024,  9653,  1041,  9666,  9680,  9693,  1069,  9707,  1283,  9720,
    9734,  9747,   492,   792, 10088,   793,  9761,  9774,   139,   803,
     804, 10102,   807,   808, 10114,   809, 10734,   827,  1654,  1719,
     826, 10128, 11142, 10478, 10492,   835,   839,    17,   840,    18,
      23,  8114,  8146,  2435,  3891,  7484,  7519,  9545,  9788,  9801,
     838,   844,    24,   859,    50,    53,  8178,  8210,  2435,  3970,
    1845, 10504,  7554,  7589,  7624,  7659,  7694,  7729,  7764,  7799,
   10746,   860,   862,   863,  8306,   868,  9259,  5465,  1953,  1990,
    2026,  2132,  2210,  2318,  2355,   877,  7834,  2391,   886, 10758,
     887,  9815,  2497,  2575,  2683,  2720,  2752,  2787,  2862,  2940,
    8338,  3048,  3085,  3117,   888, 10770,   889,  3151,   361,  4008,
    9276,  7869,  4069, 10782,   896,  5885,  8306,  3227,  8306,   226,
     226,   897,  3382,  8338,  8338,   226,   226,   935,   872,   894,
   10140,   895,   898, 10154,   899, 10794,   908,  3417,  3480,   907,
    7904,  7939,   917,   921, 10166,   927,  3526,  3760,   933,   938,
   10180,   944,   957,    61,   959,    64,    73,  8242,  8274,  2435,
    4205,  4112,  8306,  8306,  8306,  8306,  8338,  8338,  8338,  8338,
    4314,  4454,  4674,  4750,  4809,  4861,  4896,  4932,  8370,  4979,
    5020,  5055,   964, 10806,   968,  7974,  8009,  8044,  8079,  4169,
    5091,  5123,  5155,  5187,  8370,  8370,   226,   226,  1023,  5222,
    5257,   975,   976, 10192,   986,  8370,  8370,  8370,  8370,  5292,
    5327,  5362,  5397
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
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -383,  -383,  -383,   999,    44,  -383,  -383,  -383,  -383,  -383,
     825,  -383,   831,   162,  -270,  -382,  -383,   909,    22,   224,
     276,   364,   545,   552,     0,  -131,  4362,  4187,  4050,  3894,
    3262,  3656,  3418,  1503,  1868,  2233,  -383,  -340,  2598,  1097,
       1,  2963,  -374
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   119,    23,   175,   205,   149,   193,
     169,   170,   171,   273,    67,   120,   121,   122,   123,   274,
     275,   276,   277,   278,   113,   114,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   145,   146,    42,    64,
     124,    45,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    44,   385,   480,   460,   242,   473,    58,  -121,   463,
     147,   148,   177,   180,    59,   182,    63,    66,   553,   556,
      31,    44,    25,   377,   558,   583,  -120,  -123,   299,   189,
     191,  -121,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
     178,   181,    25,   183,    22,  -124,   554,   557,   437,    68,
    -123,   586,   559,   584,   588,   520,  -120,  -120,   513,   108,
     111,   503,   661,   390,    22,   664,    60,   279,  -124,   208,
     209,   211,   -56,   -56,   666,   -56,   -56,   -56,   -56,   587,
     -56,   104,   589,   144,   -65,   -65,   254,   -56,   -56,   -56,
     662,   -56,   -56,   665,   -56,   -56,   -56,   198,   -56,   -56,
      73,   -71,   667,   -56,   333,    61,   -56,   -53,   -53,   309,
     -53,   -53,   -53,   -53,    71,   -53,   150,   151,   152,   -71,
     116,   279,   -53,   -53,   -53,   -65,   -53,   -53,   525,   -53,
     -53,   -53,   199,   -53,   -53,   -27,   -27,  -121,   -53,   333,
     143,   -53,   281,   282,   283,   284,  -122,     6,  -123,    72,
     173,  -124,   428,   118,     7,     8,     9,    46,   325,   325,
     -68,   429,    24,  -121,  -121,   192,   153,   -65,   540,   154,
     285,  -114,  -122,  -122,  -123,  -123,   173,  -124,  -124,  -120,
     185,   187,    24,  -128,    31,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -111,  -111,   173,   391,   -71,    31,    31,
     330,   330,   330,   156,   334,   -71,   197,   157,  -120,  -120,
    -120,  -120,   333,   159,    31,    31,    31,    31,   -71,   -71,
     206,   207,   243,   629,    26,   622,   -71,   329,   332,   224,
     225,   226,   227,   -66,     6,   -18,   219,   220,   221,   222,
     -18,     7,     8,     9,    26,    85,   -70,    86,   346,   161,
    -123,   477,   167,   -18,   -18,    73,   -74,   228,   -69,   336,
     -79,   -79,   -79,   162,   -38,   -38,   -18,   -38,   -38,   -38,
     -38,   384,   -38,  -123,   -74,  -123,    27,  -121,   166,   -38,
     -38,   -38,   -79,   -38,   -38,   389,   -38,   -38,   -38,   -38,
     -38,   -38,    56,  -124,   469,   -38,    27,   605,   -38,   254,
    -121,    72,  -121,   517,   509,  -113,   165,   -42,   -42,   254,
     -42,   -42,   -42,   -42,   174,   -42,  -124,   436,  -124,   -68,
     319,   319,   -42,   -42,   -42,   176,   -42,   -42,  -122,   -42,
     -42,   -42,   -42,   -42,   -42,   334,   -74,   168,   -42,   179,
     -15,   -42,   309,    57,   144,   -15,    24,   391,   -74,   144,
     -19,  -122,   390,  -122,   465,   310,   311,   -74,   -15,   -15,
      24,    24,   618,   200,    28,   212,    18,   254,   -21,   -74,
     -74,   -15,   202,   -68,   -68,   218,    24,    24,    24,    24,
     472,   475,   320,   320,    28,   279,  -120,   393,   -79,   -79,
     -79,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
     203,   144,   578,   580,   334,   -72,   505,    72,    26,   -16,
     -79,   -79,    73,   -72,  -120,  -120,  -120,   594,   596,  -120,
    -120,  -120,    26,    26,   213,   -66,   -72,   -83,   -83,   -83,
     -83,   -72,   512,   515,   321,   321,  -120,   279,    26,    26,
      26,    26,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
     -83,   397,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   309,
      27,   -75,   -75,   335,   214,  -120,  -120,  -120,   144,   326,
     327,   626,   310,   311,    27,    27,   -94,   -94,   632,   633,
     635,   -25,   -25,   -75,   638,   639,   641,   -78,   -78,   335,
      27,    27,    27,    27,   215,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,   390,   400,   -22,   194,   217,   144,   -78,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,   672,   674,
    -126,  -126,   322,   322,   -66,   -66,   -83,   -83,   -83,   -83,
      -4,   575,   575,  -115,   401,  -115,  -115,    46,    47,    48,
      49,    50,    51,    52,    53,    29,   325,   325,    28,   -83,
     -83,  -120,    30,   569,   577,   691,   692,   694,   379,    54,
      55,   386,    28,    28,   279,    29,   604,   380,   591,   593,
     391,   -72,    30,   -86,   -86,   -86,   -86,   381,    28,    28,
      28,    28,   -76,   -76,   335,   382,   601,   431,    46,    47,
     325,   438,   -72,   -72,    52,    53,   -86,   -86,   432,   621,
     624,   -24,   -24,   439,   -76,   279,   279,   433,   279,   330,
     330,   330,   612,   325,   325,   330,   330,   330,   -28,   -28,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,   630,   434,
     631,  -120,  -110,  -110,   255,   636,   637,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -127,  -127,   575,   575,   -75,
     -75,   392,   279,   279,   279,   279,   325,   325,   325,   325,
     -70,  -120,  -120,  -120,   -75,   -75,    74,   441,   575,   669,
     671,   -75,   -75,   462,   675,   676,   677,   678,   679,   680,
     681,   682,   479,   -75,   575,   575,   330,   330,   330,   484,
     683,   -26,   -26,   568,   568,   575,   575,   575,   575,   -23,
     -23,  -120,  -120,   323,   323,   300,   689,   690,   319,   319,
     324,   324,   -78,   -78,   392,   507,   519,   699,   700,   701,
     702,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,    29,
     393,   -82,   -82,   -82,   -78,   -78,    30,   521,    75,   -79,
     -79,   -79,  -122,    29,    29,   508,  -115,  -115,  -120,  -120,
      30,    30,   319,   -82,   -82,   570,   570,   378,   -79,    29,
      29,    29,    29,   481,   482,  -122,    30,    30,    30,    30,
     320,   320,   343,   522,   524,   319,   319,   526,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,   467,   527,   -93,   -93,
     -93,   -93,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
     529,  -115,   344,  -115,   530,   532,   534,   571,   571,   568,
     568,   -93,   -93,   535,   320,   536,   468,  -115,   319,   319,
     319,   319,   321,   321,   537,   539,   -86,   -86,   -86,   -86,
     568,   336,   -82,   -82,   -82,   541,   542,   320,   320,   544,
     545,   547,   -93,   -93,   -93,   -93,   568,   568,   210,   -86,
     224,   225,   226,   227,   -82,     6,   549,   568,   568,   568,
     568,   550,     7,     8,     9,   -93,   321,   551,   552,   555,
     581,   570,   570,   582,   -92,   -92,   -92,   -92,   228,   -69,
     320,   320,   320,   320,   336,   -80,   -80,   -80,   585,   321,
     321,   598,   570,   599,   600,   572,   572,   -92,   634,   602,
     224,   225,   226,   227,   642,     6,   607,   -80,   570,   570,
     322,   322,     7,     8,     9,   609,   611,   615,   617,   570,
     570,   570,   570,   571,   571,   628,   643,   645,   228,   -69,
     646,   648,   321,   321,   321,   321,   640,   650,   224,   225,
     226,   227,   651,     6,   571,   -92,   -92,   -92,   -92,   652,
       7,     8,     9,   653,   322,   -83,   -83,   -83,   -83,   655,
     571,   571,   -78,   -78,    74,   656,   228,   -69,   -92,   -92,
     657,   571,   571,   571,   571,   -83,   659,   322,   322,   -37,
     -37,   -78,   -37,   -37,   -37,   -37,   660,   -37,   663,   -86,
     -86,   -86,   -86,   686,   -37,   -37,   -37,   688,   -37,   -37,
     196,   -37,   -37,   -37,   -37,   -37,   -37,   695,   696,   -86,
     -37,   572,   572,   -37,   -84,   -84,   -84,   -84,   698,    70,
     322,   322,   322,   322,   693,   204,   224,   225,   226,   227,
     163,     6,   572,   393,   -80,   -80,   -80,   -84,     7,     8,
       9,     0,     0,     0,     0,     0,     0,     0,   572,   572,
     -84,   -84,   -84,   -84,   228,   -69,   -80,   -80,    82,   572,
     572,   572,   572,   242,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,     0,   -84,   -84,     0,   573,   573,   -89,   -89,
     -89,   -89,     0,   574,   574,     0,  -115,  -115,    83,     0,
       0,   323,   323,   -89,   -89,   -89,   -89,    43,   324,   324,
       0,   -89,   -89,   -39,   -39,     0,   -39,   -39,   -39,   -39,
       0,   -39,     0,     0,   240,     0,   -89,    43,   -39,   -39,
     -39,     0,   -39,   -39,     0,   -39,   -39,   -39,   -39,   -39,
     -39,   -76,   -76,   392,   -39,   323,     0,   -39,     0,     0,
      84,    87,   324,   252,   252,   252,   252,   252,   252,   252,
     252,     0,   252,   -76,   -76,   105,   240,   240,   323,   323,
     -88,   -88,   -88,   -88,   280,   324,   324,     0,     0,   252,
     252,   252,   252,   252,   252,   252,   252,   252,     0,     0,
     297,     0,    62,   -88,     2,     3,     4,   223,     0,     6,
       0,     0,   573,   573,     0,     0,     7,     8,     9,   574,
     574,   323,   323,   323,   323,     0,     0,     0,   324,   324,
     324,   324,    17,   573,    75,   -82,   -82,   -82,   280,     0,
     574,   164,     0,     0,   -93,   -93,   -93,   -93,     0,   573,
     573,     0,   255,   256,   -82,     0,   574,   574,   261,   262,
     573,   573,   573,   573,   -93,     0,   172,   574,   574,   574,
     574,     0,   312,     0,     2,     3,     4,   223,     0,     6,
       0,     0,   297,     0,     0,     0,     7,     8,     9,     0,
     195,     0,   172,   313,   314,   315,   184,   316,   317,     0,
       0,     0,    17,     0,     0,   318,   -92,   -92,   -92,   -92,
       0,   172,   -88,   -88,   -88,   -88,     0,   240,   240,   240,
       0,     0,     0,     0,   -40,   -40,   -92,   -40,   -40,   -40,
     -40,     0,   -40,     0,     0,   -88,   -88,     0,     0,   -40,
     -40,   -40,     0,   -40,   -40,   240,   -40,   -40,   -40,   -40,
     -40,   -40,     0,     0,   240,   -40,     0,     0,   -40,     0,
       0,    75,   -80,   -80,   -80,   240,   252,     0,     0,     0,
       0,     0,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   -80,     0,     0,   106,     0,   224,   225,   226,   227,
       0,     6,     0,   -84,   -84,   -84,   -84,   387,     7,     8,
       9,   107,   240,   300,   301,   302,   303,   304,   305,   306,
     307,   297,     0,   -84,   228,     0,     0,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   308,     0,  -112,  -112,
     -76,   -76,    74,    46,    47,    48,    49,    50,    51,    52,
      53,   255,   256,   257,   258,   259,   260,   261,   262,   -76,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   -41,
     -41,   297,   -41,   -41,   -41,   -41,   297,   -41,     0,     0,
       0,   240,     0,   359,   -41,   -41,   -41,     0,   -41,   -41,
       0,   -41,   -41,   -41,   -41,   -41,   -41,     0,   300,   301,
     -41,     0,     0,   -41,   306,   307,   470,   240,   240,    46,
      47,    48,   280,     0,    51,    52,    53,   411,   411,   411,
     411,   411,   411,   411,   411,   411,     0,   112,   297,     2,
       3,     4,   223,   240,     6,   411,   -89,   -89,   -89,   -89,
       0,     7,     8,     9,     0,     0,    46,    47,    48,    49,
     236,    51,    52,    53,     0,   -69,   -89,    17,   510,   240,
     240,     0,     0,     0,   280,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,    81,   -88,   -88,   -88,   -88,     0,    88,
      91,    91,    91,    91,    91,    91,    91,     0,    91,     0,
    -125,  -125,   236,   236,   -88,   297,   340,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,     0,    91,    91,    91,    91,    91,
      91,    91,   140,    91,   -52,   -52,   293,   -52,   -52,   -52,
     -52,   -94,   -52,     0,     0,     0,     0,     0,     0,   -52,
     -52,   -52,     0,   -52,   -52,   297,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,     0,   -52,   -51,   -51,   -52,   -51,
     -51,   -51,   -51,     0,   -51,     0,     0,     0,     0,     0,
       0,   -51,   -51,   -51,     0,   -51,   -51,     0,   -51,   -51,
     -51,   -51,   -51,   -51,     0,     0,     0,   -51,     0,     0,
     -51,     0,     0,     0,   -60,   -60,     0,   -60,   -60,   -60,
     -60,     0,   -60,     0,     0,     0,     0,     0,   293,   -60,
     -60,   -60,     0,   -60,   -60,     0,   -60,   -60,   -60,   -60,
     -60,   -60,     0,     0,     0,   -60,     0,     0,   -60,     0,
       0,     0,    46,    47,    48,   619,   240,   240,    52,    53,
       0,     0,   280,   236,   236,   236,   240,   240,   240,   255,
     256,   257,   240,   240,   240,   261,   262,     0,     0,   -59,
     -59,     0,   -59,   -59,   -59,   -59,     0,   -59,     0,     0,
       0,   236,     0,     0,   -59,   -59,   -59,     0,   -59,   -59,
     342,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,
     -59,   236,   347,   -59,     0,     0,     0,     0,   355,   363,
     363,   363,   363,   363,   363,   363,   363,     0,  -120,     0,
       0,     0,     0,     0,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,     0,   240,   240,   240,     0,     0,   236,   394,
     -87,   -87,   -87,   -87,   395,   396,  -120,   399,  -120,     0,
       0,     0,     0,   407,   415,   415,   415,   415,   415,   415,
     415,   415,     0,   -87,   -87,   300,   301,   302,   303,   304,
     305,   306,   307,   255,   256,   257,   258,     0,   260,   261,
     262,     0,     0,     0,     0,     0,   363,   363,   363,   363,
     363,   363,   363,   457,   363,   -30,   -30,   293,   -30,   -30,
     -30,   -30,   293,   -30,     0,     0,     0,   236,     0,   466,
     -30,   -30,   -30,     0,   -30,   -30,     0,   -30,   -30,   -30,
     -30,   -30,   -30,     0,     0,     0,   -30,     0,     0,   -30,
       0,     0,     0,   236,   236,   237,   337,   -87,   -87,   -87,
     -87,   338,   339,   415,   415,   415,   415,   415,   415,   415,
     500,   415,     0,     0,   293,     0,   300,   301,   302,   236,
     -87,   506,   306,   307,   249,   249,   249,   249,   249,   249,
     249,   249,     0,   249,   255,   256,   257,   237,   237,   260,
     261,   262,   300,   301,   302,   236,   236,   305,   306,   307,
     249,   249,   249,   249,   249,   249,   249,   249,   249,     0,
       0,   294,     0,     0,   -38,     0,   -38,   -38,   -38,   -38,
       0,   -38,     0,     0,     0,     0,     0,     0,   -38,   -38,
     -38,   293,   -38,   -38,     0,   -38,   -38,   -38,   -38,   -38,
     -38,     0,     0,     0,   -38,     0,     0,   -38,   -38,     0,
       0,   -56,     0,   -56,   -56,   -56,   -56,     0,   -56,     0,
       0,     0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,
     -56,   293,   -56,   -56,   -56,   606,   -56,   -56,     0,     0,
       0,   -56,     0,     0,   -56,   -56,     0,   -42,     0,   -42,
     -42,   -42,   -42,   294,   -42,     0,     0,     0,     0,     0,
       0,   -42,   -42,   -42,     0,   -42,   -42,     0,   -42,   -42,
     -42,   -42,   -42,   -42,     0,     0,     0,   -42,     0,     0,
     -42,   -42,     0,     0,     0,    82,     0,     0,   237,   237,
     237,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -120,
       0,     0,     0,     0,     0,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -115,  -115,    83,   237,     0,     0,     0,
       0,     0,   236,   236,     0,   237,     0,  -120,  -120,  -120,
       0,     0,   236,   236,   236,     0,   237,   249,   236,   236,
     236,     0,     0,   356,   356,   356,   356,   356,   356,   356,
     356,   356,     0,   -37,     0,   -37,   -37,   -37,   -37,     0,
     -37,     0,     0,     0,     0,     0,     0,   -37,   -37,   -37,
       0,   -37,   -37,   237,   -37,   -37,   -37,   -37,   -37,   -37,
       0,     0,   294,   -37,     0,     0,   -37,   -37,   408,   408,
     408,   408,   408,   408,   408,   408,   408,     0,     0,     0,
     471,     0,   224,   225,   226,   227,     0,     6,     0,   236,
     236,   236,     0,     0,     7,     8,     9,   107,     0,     0,
       0,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     228,   -39,   294,   -39,   -39,   -39,   -39,   294,   -39,     0,
       0,     0,   237,     0,   356,   -39,   -39,   -39,     0,   -39,
     -39,     0,   -39,   -39,   -39,   -39,   -39,   -39,     0,     0,
       0,   -39,     0,     0,   -39,   -39,     0,     0,   237,   237,
     238,    76,   -87,   -87,   -87,   -87,    77,    78,   408,   408,
     408,   408,   408,   408,   408,   408,   408,     0,     0,   294,
       0,     0,   -87,     0,   237,     0,   408,     0,     0,   250,
     250,   250,   250,   250,   250,   250,   250,     0,   250,     0,
       0,     0,   238,   238,     0,     0,     0,     0,     0,     0,
     237,   237,     0,     0,     0,   250,   250,   250,   250,   250,
     250,   250,   250,   250,     0,     0,   295,     0,     0,   -40,
       0,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,     0,
       0,     0,     0,   -40,   -40,   -40,   294,   -40,   -40,     0,
     -40,   -40,   -40,   -40,   -40,   -40,     0,     0,     0,   -40,
       0,     0,   -40,   -40,     0,     0,   -41,     0,   -41,   -41,
     -41,   -41,     0,   -41,     0,     0,     0,     0,     0,     0,
     -41,   -41,   -41,     0,   -41,   -41,   294,   -41,   -41,   -41,
     -41,   -41,   -41,     0,     0,     0,   -41,     0,     0,   -41,
     -41,     0,   -53,     0,   -53,   -53,   -53,   -53,   295,   -53,
       0,     0,     0,     0,     0,     0,   -53,   -53,   -53,     0,
     -53,   -53,     0,   -53,   -53,   -53,   608,   -53,   -53,     0,
       0,     0,   -53,     0,     0,   -53,   -53,     0,     0,     0,
       0,     0,     0,   238,   238,   238,   188,     0,     2,     3,
       4,   223,   511,     6,   224,   225,   226,   227,     0,     6,
       7,     8,     9,     0,     0,     0,     7,     8,     9,   107,
       0,   238,     0,     0,   -69,     0,    17,   237,   237,     0,
     238,     0,   228,     0,     0,     0,     0,   237,   237,   237,
       0,   238,   250,   237,   237,   237,     0,     0,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   -47,   -47,     0,
     -47,   -47,   -47,   -47,     0,   -47,     0,     0,     0,     0,
       0,     0,   -47,   -47,   -47,     0,   -47,   -47,   238,   -47,
     -47,   -47,   -47,   -47,   -47,     0,     0,   295,   -47,     0,
       0,   -47,     0,   409,   409,   409,   409,   409,   409,   409,
     409,   409,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
       0,     0,     0,     0,   237,   237,   237,     0,     0,     0,
       0,     0,     0,     0,  -126,  -126,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   -48,   -48,   295,   -48,   -48,
     -48,   -48,   295,   -48,     0,     0,     0,   238,     0,   357,
     -48,   -48,   -48,     0,   -48,   -48,     0,   -48,   -48,   -48,
     -48,   -48,   -48,     0,     0,     0,   -48,     0,     0,   -48,
       0,     0,     0,   238,   238,   239,     0,     0,     0,     0,
       0,     0,     0,   409,   409,   409,   409,   409,   409,   409,
     409,   409,     0,     0,   295,     0,     0,     0,     0,   238,
       0,   409,     0,     0,   251,   251,   251,   251,   251,   251,
     251,   251,     0,   251,     0,     0,     0,   239,   239,     0,
       0,     0,     0,     0,     0,   238,   238,     0,     0,     0,
     251,   251,   251,   251,   251,   251,   251,   251,   251,     0,
       0,   296,     0,   -43,   -43,     0,   -43,   -43,   -43,   -43,
       0,   -43,     0,     0,     0,     0,     0,     0,   -43,   -43,
     -43,   295,   -43,   -43,     0,   -43,   -43,   -43,   -43,   -43,
     -43,     0,     0,     0,   -43,     0,     0,   -43,     0,     0,
     -46,   -46,     0,   -46,   -46,   -46,   -46,     0,   -46,     0,
       0,     0,     0,     0,     0,   -46,   -46,   -46,     0,   -46,
     -46,   295,   -46,   -46,   -46,   -46,   -46,   -46,     0,     0,
       0,   -46,   -49,   -49,   -46,   -49,   -49,   -49,   -49,     0,
     -49,     0,     0,   296,     0,     0,     0,   -49,   -49,   -49,
       0,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,     0,   -49,     0,     0,   -49,   -44,   -44,     0,
     -44,   -44,   -44,   -44,     0,   -44,     0,     0,   239,   239,
     239,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,     0,
       0,   -44,   300,   301,   302,   303,   239,   305,   306,   307,
       0,     0,   238,   238,     0,   239,     0,     0,     0,     0,
       0,     0,   238,   238,   238,     0,   239,   251,   238,   238,
     238,     0,     0,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   -50,   -50,     0,   -50,   -50,   -50,   -50,     0,
     -50,     0,     0,     0,     0,     0,     0,   -50,   -50,   -50,
       0,   -50,   -50,   239,   -50,   -50,   -50,   -50,   -50,   -50,
       0,     0,   296,   -50,     0,     0,   -50,     0,   410,   410,
     410,   410,   410,   410,   410,   410,   410,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,     0,     0,     0,     0,   238,
     238,   238,     0,     0,     0,     0,     0,     0,     0,  -127,
    -127,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     -45,   -45,   296,   -45,   -45,   -45,   -45,   296,   -45,     0,
       0,     0,   239,     0,   358,   -45,   -45,   -45,     0,   -45,
     -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
       0,   -45,     0,     0,   -45,     0,     0,     0,   239,   239,
     241,     0,     0,     0,     0,     0,     0,     0,   410,   410,
     410,   410,   410,   410,   410,   410,   410,     0,     0,   296,
       0,     0,     0,     0,   239,     0,   410,     0,     0,   253,
     253,   253,   253,   253,   253,   253,   253,     0,   253,     0,
       0,     0,   241,   241,     0,     0,     0,     0,     0,     0,
     239,   239,     0,     0,     0,   253,   253,   253,   253,   253,
     253,   253,   253,   253,     0,     0,   298,     0,   -56,   -56,
       0,   -56,   -56,   -56,   -56,     0,   -56,     0,     0,     0,
       0,     0,     0,   -56,   -56,   -56,   296,   -56,   -56,     0,
     -56,   -56,   -56,   613,   -56,   -56,     0,     0,     0,   -56,
       0,     0,   -56,     0,     0,   -55,   -55,     0,   -55,   -55,
     -55,   -55,     0,   -55,     0,     0,     0,     0,     0,     0,
     -55,   -55,   -55,     0,   -55,   -55,   296,   -55,   -55,   -55,
     -55,   -55,   -55,     0,     0,     0,   -55,   -53,   -53,   -55,
     -53,   -53,   -53,   -53,     0,   -53,     0,     0,   298,     0,
       0,     0,   -53,   -53,   -53,     0,   -53,   -53,     0,   -53,
     -53,   -53,   614,   -53,   -53,     0,     0,     0,   -53,     0,
       0,   -53,   -52,     0,   -52,   -52,   -52,   -52,     0,   -52,
       0,     0,     0,   241,   241,   241,   -52,   -52,   -52,     0,
     -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,     0,
       0,     0,   -52,     0,     0,   -52,   -52,     0,     0,     0,
       0,   241,     0,     0,     0,     0,     0,   239,   239,     0,
     241,     0,     0,     0,     0,     0,     0,   239,   239,   239,
       0,   241,   253,   239,   239,   239,     0,     0,   360,   360,
     360,   360,   360,   360,   360,   360,   360,     0,   -51,     0,
     -51,   -51,   -51,   -51,     0,   -51,     0,     0,     0,     0,
       0,     0,   -51,   -51,   -51,     0,   -51,   -51,   241,   -51,
     -51,   -51,   -51,   -51,   -51,     0,     0,   298,   -51,     0,
       0,   -51,   -51,   412,   412,   412,   412,   412,   412,   412,
     412,   412,     0,     0,     0,     0,     0,     0,     0,   233,
       0,   348,     0,     0,   239,   239,   239,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,     0,   360,   360,   360,   360,
     360,   360,   360,   360,   360,     0,     0,   298,     0,  -115,
      93,   349,   298,     0,   100,   101,     0,   241,     0,   360,
       0,   233,   233,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,     0,     0,     0,     0,     0,     0,   132,     0,   136,
     138,     0,     0,   241,   241,   290,  -126,     0,  -126,  -126,
       0,     0,     0,   412,   412,   412,   412,   412,   412,   412,
     412,   412,     0,   190,   298,     2,     3,     4,   223,   241,
       6,   412,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,   -58,   -58,     0,   -58,   -58,   -58,   -58,     0,
     -58,   -69,     0,    17,     0,   241,   241,   -58,   -58,   -58,
       0,   -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,   -58,
       0,     0,     0,   -58,     0,     0,   -58,     0,   -60,     0,
     -60,   -60,   -60,   -60,     0,   -60,     0,   290,     0,     0,
       0,   298,   -60,   -60,   -60,   235,   -60,   -60,     0,   -60,
     -60,   -60,   -60,   -60,   -60,     0,     0,     0,   -60,     0,
       0,   -60,   -60,     0,  -106,  -106,  -106,  -106,     0,  -106,
       0,     0,   233,   233,   233,    90,  -106,  -106,  -106,     0,
       0,   298,     0,     0,     0,     0,     0,   235,   235,     0,
       0,   -59,  -106,   -59,   -59,   -59,   -59,     0,   -59,     0,
     233,     0,     0,     0,   134,   -59,   -59,   -59,     0,   -59,
     -59,   292,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,
     233,   -59,     0,     0,   -59,   -59,     0,     0,     0,   365,
     233,   233,   233,   372,   373,   233,   -57,   -57,     0,   -57,
     -57,   -57,   -57,     0,   -57,     0,     0,     0,     0,     0,
       0,   -57,   -57,   -57,     0,   -57,   -57,   233,   -57,   -57,
     -57,   -57,   -57,   -57,     0,     0,     0,   -57,     0,     0,
     -57,     0,   241,   241,   417,   290,   290,   290,   424,   425,
     290,     0,   241,   241,   241,     0,     0,     0,   241,   241,
     241,     0,     0,   292,   255,   256,   257,   258,   259,   260,
     261,   262,     0,     0,     0,   233,   233,   233,   449,     0,
     453,   455,     0,   233,     0,     0,   290,   263,     0,   117,
     476,   290,     2,     3,     4,   223,   233,     6,   235,   235,
     235,     0,     0,     0,     7,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -69,     0,
      17,     0,   233,   233,     0,     0,   235,     0,     0,   241,
     241,   241,   290,   290,   290,   492,     0,   496,   498,     0,
     290,     0,     0,   290,     0,     0,   235,     0,   233,     0,
       0,     0,     0,   234,   362,   235,   235,   235,   235,   235,
     235,   235,     0,     0,   312,     0,     2,     3,     4,   223,
       0,     6,     0,     0,   233,   233,     0,     0,     7,     8,
       9,     0,     0,   235,     0,   313,   314,   315,   186,   316,
     317,     0,     0,     0,    17,   234,   234,   318,     0,   414,
     292,   292,   292,   292,   292,   292,   292,     0,     0,     0,
     290,     0,     0,     0,     0,     0,     0,     0,     0,   291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   235,   235,   235,   235,   451,   235,   235,     0,   235,
     -54,   -54,   292,   -54,   -54,   -54,   -54,   292,   -54,     0,
     290,     0,   235,     0,     0,   -54,   -54,   -54,     0,   -54,
     -54,     0,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
       0,   -54,     0,     0,   -54,     0,     0,     0,   235,   235,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,   292,   292,
     292,   292,   494,   292,   292,     0,   292,     0,     0,   292,
       0,   291,  -125,  -125,   235,   516,     0,     2,     3,     4,
     223,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
     235,   235,     0,   -69,     0,    17,   234,   234,   234,     0,
       0,   233,   233,     0,     0,  -127,     0,  -127,  -127,     0,
       0,   233,   233,   233,     0,     0,     0,   233,   233,   233,
       0,     0,     0,     0,   234,     0,   292,     0,     0,     0,
       0,     0,   579,     0,     2,     3,     4,   223,     0,     6,
       0,     0,     0,     0,   234,     0,     7,     8,     9,     0,
       0,   232,     0,   234,   234,   234,   234,   234,   234,   234,
     -69,     0,    17,     0,     0,     0,   292,     0,     0,     0,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,     0,     0,
       0,   234,     0,     0,     0,    99,     0,     0,   233,   233,
     233,     0,     0,   232,   232,  -101,  -101,     0,   291,   291,
     291,   291,   291,   291,   291,     0,     0,     0,   130,     0,
       0,   595,     0,     2,     3,     4,   223,   289,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,   234,
     234,   234,   234,     0,   234,   234,     0,   234,     0,   -69,
     291,    17,     0,     0,     0,   291,     0,     0,     0,   620,
     234,   224,   225,   226,   227,     0,     6,   235,   235,     0,
       0,     0,     0,     7,     8,     9,   107,   235,   235,   235,
       0,     0,     0,   235,   235,   235,   234,   234,     0,   228,
       0,     0,     0,     0,     0,     0,   291,   291,   291,   291,
       0,   291,   291,     0,   291,     0,     0,   291,     0,   289,
       0,     0,   234,     0,     0,     0,     0,   231,     0,     0,
     625,     0,     2,     3,     4,   223,     0,     6,     0,     0,
       0,     0,     0,     0,     7,     8,     9,     0,   234,   234,
       0,     0,     0,     0,   232,   232,   232,     0,   -69,    95,
      17,     0,     0,     0,   235,   235,   235,     0,     0,   231,
     231,     0,     0,   -30,     0,   -30,   -30,   -30,   -30,     0,
     -30,     0,   232,   128,   291,     0,     0,   -30,   -30,   -30,
       0,   -30,   -30,   288,   -30,   -30,   -30,   -30,   -30,   -30,
       0,     0,   232,   -30,     0,     0,   -30,   -30,     0,     0,
       0,     0,   232,   232,   371,     0,     0,   232,     0,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,   -62,
     -62,     0,   -62,   -62,   -62,   -62,     0,   -62,     0,   232,
       0,     0,     0,     0,   -62,   -62,   -62,     0,   -62,   -62,
       0,   -62,   -62,   -62,   -62,   -62,   -62,   289,   289,   423,
     -62,     0,   289,   -62,   230,     0,   673,     0,     2,     3,
       4,   223,     0,     6,     0,   288,     0,     0,     0,     0,
       7,     8,     9,     0,     0,     0,     0,   232,   232,   447,
       0,     0,     0,     0,   -69,   232,    17,    97,   289,     0,
       0,     0,     0,   289,     0,     0,   230,   230,   232,     0,
     231,   231,   231,     0,     0,   234,   234,     0,     0,   126,
       0,     0,     0,     0,     0,   234,   234,   234,     0,     0,
     287,   234,   234,   234,   232,   232,     0,     0,   231,     0,
       0,     0,     0,     0,   289,   289,   490,     0,     0,     0,
       0,     0,   289,     0,     0,   289,     0,     0,   231,     0,
     232,     0,     0,     0,     0,     0,     0,     0,   367,   231,
       0,     0,     0,   231,     0,   -47,     0,   -47,   -47,   -47,
     -47,     0,   -47,     0,     0,     0,   232,   232,     0,   -47,
     -47,   -47,     0,   -47,   -47,   231,   -47,   -47,   -47,   -47,
     -47,   -47,   234,   234,   234,   -47,     0,     0,   -47,   -47,
       0,     0,   287,   419,   288,     0,     0,     0,   288,     0,
       0,     0,   289,     0,     0,     0,    65,     0,   224,   225,
     226,   227,     0,     6,     0,     0,     0,     0,     0,   229,
       7,     8,     9,   231,   445,     0,     0,   230,   230,   230,
       0,   231,     0,     0,   288,     0,   228,     0,     0,   288,
       0,     0,   289,     0,   231,     0,     0,     0,     0,    89,
       0,   244,   245,   246,   247,   230,     6,   103,     0,     0,
       0,   229,   229,     7,     8,     9,     0,     0,     0,     0,
     231,   231,     0,     0,     0,   230,     0,     0,     0,   248,
     288,   488,   142,     0,     0,   286,   369,     0,   288,     0,
     230,   288,     0,     0,     0,   -48,   231,   -48,   -48,   -48,
     -48,     0,   -48,     0,     0,     0,     0,     0,     0,   -48,
     -48,   -48,   230,   -48,   -48,     0,   -48,   -48,   -48,   -48,
     -48,   -48,   231,   231,     0,   -48,     0,     0,   -48,   -48,
       0,   421,     0,   232,   232,   287,     0,     0,     0,     0,
       0,     0,     0,   232,   232,   232,     0,     0,     0,   232,
     232,   232,     0,     0,     0,     0,     0,     0,   288,    92,
     443,   244,   245,   246,   247,     0,     6,   286,   230,     0,
       0,   287,     0,     7,     8,     9,   287,     0,     0,     0,
      94,   230,   244,   245,   246,   247,     0,     6,     0,   248,
       0,     0,     0,     0,     7,     8,     9,     0,   288,     0,
       0,     0,   229,   229,   229,     0,     0,   230,   230,     0,
     248,     0,     0,     0,     0,     0,     0,   486,     0,     0,
     232,   232,   232,     0,     0,   287,     0,     0,   287,     0,
     229,     0,     0,   230,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     2,     3,     4,   223,     0,     6,     0,
     229,     0,     0,     0,     0,     7,     8,     9,     0,   230,
     230,     0,    12,    13,    14,   375,    15,    16,     0,     0,
       0,    17,     0,     0,    18,     0,     0,     0,    96,     0,
     244,   245,   246,   247,     0,     6,     0,   229,     0,   231,
     231,     0,     7,     8,     9,   287,     0,     0,     0,   231,
     231,   231,     0,     0,     0,   231,   231,   231,   248,     0,
     427,     0,     0,     0,     0,   -43,     0,   -43,   -43,   -43,
     -43,     0,   -43,     0,     0,     0,     0,     0,     0,   -43,
     -43,   -43,     0,   -43,   -43,   287,   -43,   -43,   -43,   -43,
     -43,   -43,     0,   459,     0,   -43,   286,     0,   -43,   -43,
      98,   286,   244,   245,   246,   247,   229,     6,  -104,  -104,
    -104,  -104,     0,  -104,     7,     8,     9,     0,     0,     0,
    -104,  -104,  -104,     0,     0,     0,   231,   231,   231,     0,
     248,     0,   229,   229,     0,     0,  -104,     0,     0,     0,
       0,   -46,     0,   -46,   -46,   -46,   -46,     0,   -46,     0,
     502,     0,     0,   286,     0,   -46,   -46,   -46,   229,   -46,
     -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,     0,     0,
       0,   -46,     0,     0,   -46,   -46,   230,   230,     0,     0,
       0,     0,     0,     0,   229,   229,   230,   230,   230,     0,
       0,     0,   230,   230,   230,     0,     0,     0,     0,     0,
     -49,     0,   -49,   -49,   -49,   -49,     0,   -49,     0,     0,
       0,     0,     0,     0,   -49,   -49,   -49,     0,   -49,   -49,
     286,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,
     -49,     0,     0,   -49,   -49,     0,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,   -44,     0,   -44,   -44,   -44,   -44,     0,   -44,
     286,  -102,  -102,   230,   230,   230,   -44,   -44,   -44,  -126,
     -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,     0,
       0,     0,   -44,     0,     0,   -44,   -44,   -50,     0,   -50,
     -50,   -50,   -50,     0,   -50,     0,     0,     0,     0,     0,
       0,   -50,   -50,   -50,     0,   -50,   -50,     0,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,     0,   -50,     0,     0,
     -50,   -50,     0,   -45,     0,   -45,   -45,   -45,   -45,     0,
     -45,     0,     0,     0,     0,     0,     0,   -45,   -45,   -45,
       0,   -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,
       0,   229,   229,   -45,     0,     0,   -45,   -45,     0,     0,
       0,   229,   229,   229,     0,     0,     0,   229,   229,   229,
     -56,     0,   -56,   -56,   -56,   -56,     0,   -56,     0,     0,
       0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,   -56,
       0,   -56,   -56,   -56,   684,   -56,   -56,     0,     0,     0,
     -56,     0,     0,   -56,   -56,     0,     0,     0,     0,     0,
       0,   -55,     0,   -55,   -55,   -55,   -55,     0,   -55,     0,
       0,     0,     0,     0,     0,   -55,   -55,   -55,     0,   -55,
     -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,   229,   229,
     229,   -55,     0,     0,   -55,   -55,   -53,     0,   -53,   -53,
     -53,   -53,     0,   -53,     0,     0,     0,     0,     0,     0,
     -53,   -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,
     685,   -53,   -53,     0,     0,     0,   -53,     0,     0,   -53,
     -53,   -63,   -63,     0,   -63,   -63,   -63,   -63,     0,   -63,
       0,     0,     0,     0,     0,     0,   -63,   -63,   -63,     0,
     -63,   -63,     0,   -63,   -63,   -63,   -63,   -63,   -63,     0,
       0,     0,   -63,   -64,   -64,   -63,   -64,   -64,   -64,   -64,
       0,   -64,     0,     0,     0,     0,     0,     0,   -64,   -64,
     -64,     0,   -64,   -64,     0,   -64,   -64,   -64,   -64,   -64,
     -64,     0,     0,     0,   -64,   -61,   -61,   -64,   -61,   -61,
     -61,   -61,     0,   -61,     0,     0,     0,     0,     0,     0,
     -61,   -61,   -61,     0,   -61,   -61,     0,   -61,   -61,   -61,
     -61,   -61,   -61,     0,     0,     0,   -61,     0,   -58,   -61,
     -58,   -58,   -58,   -58,     0,   -58,     0,     0,     0,     0,
       0,     0,   -58,   -58,   -58,     0,   -58,   -58,     0,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,   -58,     0,
       0,   -58,   -58,   -57,     0,   -57,   -57,   -57,   -57,     0,
     -57,     0,     0,     0,     0,     0,     0,   -57,   -57,   -57,
       0,   -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,
       0,     0,     0,   -57,     0,     0,   -57,   -57,   -54,     0,
     -54,   -54,   -54,   -54,     0,   -54,     0,     0,     0,     0,
       0,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,     0,   -54,     0,
       0,   -54,   -54,   -62,     0,   -62,   -62,   -62,   -62,     0,
     -62,     0,     0,     0,     0,     0,     0,   -62,   -62,   -62,
       0,   -62,   -62,     0,   -62,   -62,   -62,   -62,   -62,   -62,
       0,     0,     0,   -62,     0,     0,   -62,   -62,   -63,     0,
     -63,   -63,   -63,   -63,     0,   -63,     0,     0,     0,     0,
       0,     0,   -63,   -63,   -63,     0,   -63,   -63,     0,   -63,
     -63,   -63,   -63,   -63,   -63,     0,     0,     0,   -63,     0,
       0,   -63,   -63,   -64,     0,   -64,   -64,   -64,   -64,     0,
     -64,     0,     0,     0,     0,     0,     0,   -64,   -64,   -64,
       0,   -64,   -64,     0,   -64,   -64,   -64,   -64,   -64,   -64,
       0,     0,     0,   -64,     0,     0,   -64,   -64,   -61,     0,
     -61,   -61,   -61,   -61,     0,   -61,     0,     0,     0,     0,
       0,     0,   -61,   -61,   -61,     0,   -61,   -61,     0,   -61,
     -61,   -61,   -61,   -61,   -61,     0,     0,     0,   -61,     0,
       0,   -61,   -61,    -3,     1,     0,     2,     3,     4,     5,
       0,     6,     0,     0,     0,     0,     0,     0,     7,     8,
       9,     0,    10,    11,     0,    12,    13,    14,     0,    15,
      16,     0,     0,     0,    17,     0,   -29,    18,   -29,   -29,
     -29,   -29,     0,   -29,     0,     0,     0,     0,     0,     0,
     -29,   -29,   -29,     0,   -29,   -29,     0,   -29,   -29,   -29,
       0,   -29,   -29,     0,     0,     0,   -29,     0,     0,   -29,
     -29,    -2,    69,     0,     2,     3,     4,     5,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
      10,    11,     0,    12,    13,    14,     0,    15,    16,     0,
       0,     0,    17,    -6,    -6,    18,    -6,    -6,    -6,    -6,
       0,    -6,     0,     0,     0,     0,     0,     0,    -6,    -6,
      -6,     0,    -6,    -6,     0,    -6,    -6,    -6,     0,    -6,
      -6,     0,     0,     0,    -6,    -8,    -8,    -6,    -8,    -8,
      -8,    -8,     0,    -8,     0,     0,     0,     0,     0,     0,
      -8,    -8,    -8,     0,    -8,    -8,     0,    -8,    -8,    -8,
       0,    -8,    -8,     0,     0,     0,    -8,    -7,    -7,    -8,
      -7,    -7,    -7,    -7,     0,    -7,     0,     0,     0,     0,
       0,     0,    -7,    -7,    -7,     0,    -7,    -7,     0,    -7,
      -7,    -7,     0,    -7,    -7,     0,     0,     0,    -7,   -38,
     -38,    -7,   -38,   -38,   -38,   -38,     0,   -38,     0,     0,
       0,     0,     0,     0,   -38,   -38,   -38,     0,   -38,   -38,
       0,   -38,   -38,   -38,     0,   -38,   -38,     0,     0,     0,
     -38,    -9,    -9,   -38,    -9,    -9,    -9,    -9,     0,    -9,
       0,     0,     0,     0,     0,     0,    -9,    -9,    -9,     0,
      -9,    -9,     0,    -9,    -9,    -9,     0,    -9,    -9,     0,
       0,     0,    -9,   -42,   -42,    -9,   -42,   -42,   -42,   -42,
       0,   -42,     0,     0,     0,     0,     0,     0,   -42,   -42,
     -42,     0,   -42,   -42,     0,   -42,   -42,   -42,     0,   -42,
     -42,     0,     0,     0,   -42,   -37,   -37,   -42,   -37,   -37,
     -37,   -37,     0,   -37,     0,     0,     0,     0,     0,     0,
     -37,   -37,   -37,     0,   -37,   -37,     0,   -37,   -37,   -37,
       0,   -37,   -37,     0,     0,     0,   -37,   -39,   -39,   -37,
     -39,   -39,   -39,   -39,     0,   -39,     0,     0,     0,     0,
       0,     0,   -39,   -39,   -39,     0,   -39,   -39,     0,   -39,
     -39,   -39,     0,   -39,   -39,     0,     0,     0,   -39,   -40,
     -40,   -39,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,
       0,     0,     0,     0,   -40,   -40,   -40,     0,   -40,   -40,
       0,   -40,   -40,   -40,     0,   -40,   -40,     0,     0,     0,
     -40,   -41,   -41,   -40,   -41,   -41,   -41,   -41,     0,   -41,
       0,     0,     0,     0,     0,     0,   -41,   -41,   -41,     0,
     -41,   -41,     0,   -41,   -41,   -41,     0,   -41,   -41,     0,
       0,     0,   -41,   -52,   -52,   -41,   -52,   -52,   -52,   -52,
       0,   -52,     0,     0,     0,     0,     0,     0,   -52,   -52,
     -52,     0,   -52,   -52,     0,   -52,   -52,   -52,     0,   -52,
     -52,     0,     0,     0,   -52,     0,   264,   -52,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,   265,   266,     0,   267,   268,   269,
       0,   270,   271,     0,     0,     0,    17,     0,     0,   272,
     -32,    -5,    -5,     0,    -5,    -5,    -5,    -5,     0,    -5,
       0,     0,     0,     0,     0,     0,    -5,    -5,    -5,     0,
      -5,    -5,     0,    -5,    -5,    -5,     0,    -5,    -5,     0,
       0,     0,    -5,   -51,   -51,    -5,   -51,   -51,   -51,   -51,
       0,   -51,     0,     0,     0,     0,     0,     0,   -51,   -51,
     -51,     0,   -51,   -51,     0,   -51,   -51,   -51,     0,   -51,
     -51,     0,     0,     0,   -51,   -11,   -11,   -51,   -11,   -11,
     -11,   -11,     0,   -11,     0,     0,     0,     0,     0,     0,
     -11,   -11,   -11,     0,   -11,   -11,     0,   -11,   -11,   -11,
       0,   -11,   -11,     0,     0,     0,   -11,   -60,   -60,   -11,
     -60,   -60,   -60,   -60,     0,   -60,     0,     0,     0,     0,
       0,     0,   -60,   -60,   -60,     0,   -60,   -60,     0,   -60,
     -60,   -60,     0,   -60,   -60,     0,     0,     0,   -60,   -59,
     -59,   -60,   -59,   -59,   -59,   -59,     0,   -59,     0,     0,
       0,     0,     0,     0,   -59,   -59,   -59,     0,   -59,   -59,
       0,   -59,   -59,   -59,     0,   -59,   -59,     0,     0,     0,
     -59,     0,   -35,   -59,   -35,   -35,   -35,   -35,     0,   -35,
       0,     0,     0,     0,     0,     0,   -35,   -35,   -35,     0,
     -35,   -35,     0,   -35,   -35,   -35,     0,   -35,   -35,     0,
       0,     0,   -35,     0,     0,   -35,   -35,   264,     0,     2,
       3,     4,     5,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,   265,   266,     0,   267,   268,
     269,     0,   270,   271,     0,     0,     0,    17,     0,     0,
     272,   -31,   -34,     0,   -34,   -34,   -34,   -34,     0,   -34,
       0,     0,     0,     0,     0,     0,   -34,   -34,   -34,     0,
     -34,   -34,     0,   -34,   -34,   -34,     0,   -34,   -34,     0,
       0,     0,   -34,     0,     0,   -34,   -34,   -36,     0,   -36,
     -36,   -36,   -36,     0,   -36,     0,     0,     0,     0,     0,
       0,   -36,   -36,   -36,     0,   -36,   -36,     0,   -36,   -36,
     -36,     0,   -36,   -36,     0,     0,     0,   -36,     0,     0,
     -36,   -36,   -14,   -14,     0,   -14,   -14,   -14,   -14,     0,
     -14,     0,     0,     0,     0,     0,     0,   -14,   -14,   -14,
       0,   -14,   -14,     0,   -14,   -14,   -14,     0,   -14,   -14,
       0,     0,     0,   -14,   -10,   -10,   -14,   -10,   -10,   -10,
     -10,     0,   -10,     0,     0,     0,     0,     0,     0,   -10,
     -10,   -10,     0,   -10,   -10,     0,   -10,   -10,   -10,     0,
     -10,   -10,     0,     0,     0,   -10,   -30,   -30,   -10,   -30,
     -30,   -30,   -30,     0,   -30,     0,     0,     0,     0,     0,
       0,   -30,   -30,   -30,     0,   -30,   -30,     0,   -30,   -30,
     -30,     0,   -30,   -30,     0,     0,     0,   -30,     0,   -33,
     -30,   -33,   -33,   -33,   -33,     0,   -33,     0,     0,     0,
       0,     0,     0,   -33,   -33,   -33,     0,   -33,   -33,     0,
     -33,   -33,   -33,     0,   -33,   -33,     0,     0,     0,   -33,
       0,     0,   -33,   -33,   -13,   -13,     0,   -13,   -13,   -13,
     -13,     0,   -13,     0,     0,     0,     0,     0,     0,   -13,
     -13,   -13,     0,   -13,   -13,     0,   -13,   -13,   -13,     0,
     -13,   -13,     0,     0,     0,   -13,   -12,   -12,   -13,   -12,
     -12,   -12,   -12,     0,   -12,     0,     0,     0,     0,     0,
       0,   -12,   -12,   -12,     0,   -12,   -12,     0,   -12,   -12,
     -12,     0,   -12,   -12,     0,     0,     0,   -12,   -47,   -47,
     -12,   -47,   -47,   -47,   -47,     0,   -47,     0,     0,     0,
       0,     0,     0,   -47,   -47,   -47,     0,   -47,   -47,     0,
     -47,   -47,   -47,     0,   -47,   -47,     0,     0,     0,   -47,
     -48,   -48,   -47,   -48,   -48,   -48,   -48,     0,   -48,     0,
       0,     0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,
     -48,     0,   -48,   -48,   -48,     0,   -48,   -48,     0,     0,
       0,   -48,   -43,   -43,   -48,   -43,   -43,   -43,   -43,     0,
     -43,     0,     0,     0,     0,     0,     0,   -43,   -43,   -43,
       0,   -43,   -43,     0,   -43,   -43,   -43,     0,   -43,   -43,
       0,     0,     0,   -43,   -46,   -46,   -43,   -46,   -46,   -46,
     -46,     0,   -46,     0,     0,     0,     0,     0,     0,   -46,
     -46,   -46,     0,   -46,   -46,     0,   -46,   -46,   -46,     0,
     -46,   -46,     0,     0,     0,   -46,   -49,   -49,   -46,   -49,
     -49,   -49,   -49,     0,   -49,     0,     0,     0,     0,     0,
       0,   -49,   -49,   -49,     0,   -49,   -49,     0,   -49,   -49,
     -49,     0,   -49,   -49,     0,     0,     0,   -49,   -44,   -44,
     -49,   -44,   -44,   -44,   -44,     0,   -44,     0,     0,     0,
       0,     0,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,
     -44,   -44,   -44,     0,   -44,   -44,     0,     0,     0,   -44,
     -50,   -50,   -44,   -50,   -50,   -50,   -50,     0,   -50,     0,
       0,     0,     0,     0,     0,   -50,   -50,   -50,     0,   -50,
     -50,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,     0,
       0,   -50,   -45,   -45,   -50,   -45,   -45,   -45,   -45,     0,
     -45,     0,     0,     0,     0,     0,     0,   -45,   -45,   -45,
       0,   -45,   -45,     0,   -45,   -45,   -45,     0,   -45,   -45,
       0,     0,     0,   -45,   -55,   -55,   -45,   -55,   -55,   -55,
     -55,     0,   -55,     0,     0,     0,     0,     0,     0,   -55,
     -55,   -55,     0,   -55,   -55,     0,   -55,   -55,   -55,     0,
     -55,   -55,     0,     0,     0,   -55,   -58,   -58,   -55,   -58,
     -58,   -58,   -58,     0,   -58,     0,     0,     0,     0,     0,
       0,   -58,   -58,   -58,     0,   -58,   -58,     0,   -58,   -58,
     -58,     0,   -58,   -58,     0,     0,     0,   -58,   -57,   -57,
     -58,   -57,   -57,   -57,   -57,     0,   -57,     0,     0,     0,
       0,     0,     0,   -57,   -57,   -57,     0,   -57,   -57,     0,
     -57,   -57,   -57,     0,   -57,   -57,     0,     0,     0,   -57,
     -54,   -54,   -57,   -54,   -54,   -54,   -54,     0,   -54,     0,
       0,     0,     0,     0,     0,   -54,   -54,   -54,     0,   -54,
     -54,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,     0,
       0,   -54,   -20,   -20,   -54,   -20,   -20,   -20,   -20,     0,
     -20,     0,     0,     0,     0,     0,     0,   -20,   -20,   -20,
       0,   -20,   -20,     0,   -20,   -20,   -20,     0,   -20,   -20,
       0,     0,     0,   -20,   -17,   -17,   -20,   -17,   -17,   -17,
     -17,     0,   -17,     0,     0,     0,     0,     0,     0,   -17,
     -17,   -17,     0,   -17,   -17,     0,   -17,   -17,   -17,     0,
     -17,   -17,     0,     0,     0,   -17,   -62,   -62,   -17,   -62,
     -62,   -62,   -62,     0,   -62,     0,     0,     0,     0,     0,
       0,   -62,   -62,   -62,     0,   -62,   -62,     0,   -62,   -62,
     -62,     0,   -62,   -62,     0,     0,     0,   -62,   -63,   -63,
     -62,   -63,   -63,   -63,   -63,     0,   -63,     0,     0,     0,
       0,     0,     0,   -63,   -63,   -63,     0,   -63,   -63,     0,
     -63,   -63,   -63,     0,   -63,   -63,     0,     0,     0,   -63,
     -64,   -64,   -63,   -64,   -64,   -64,   -64,     0,   -64,     0,
       0,     0,     0,     0,     0,   -64,   -64,   -64,     0,   -64,
     -64,     0,   -64,   -64,   -64,     0,   -64,   -64,     0,     0,
       0,   -64,   -61,   -61,   -64,   -61,   -61,   -61,   -61,     0,
     -61,     0,     0,     0,     0,     0,     0,   -61,   -61,   -61,
       0,   -61,   -61,     0,   -61,   -61,   -61,     0,   -61,   -61,
       0,     0,     0,   -61,     0,   -38,   -61,   -38,   -38,   -38,
     -38,     0,   -38,     0,     0,     0,     0,     0,     0,   -38,
     -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,     0,
     -38,   -38,     0,     0,     0,   -38,     0,     0,   -38,   -38,
     -42,     0,   -42,   -42,   -42,   -42,     0,   -42,     0,     0,
       0,     0,     0,     0,   -42,   -42,   -42,     0,   -42,   -42,
       0,   -42,   -42,   -42,     0,   -42,   -42,     0,     0,     0,
     -42,     0,     0,   -42,   -42,   -37,     0,   -37,   -37,   -37,
     -37,     0,   -37,     0,     0,     0,     0,     0,     0,   -37,
     -37,   -37,     0,   -37,   -37,     0,   -37,   -37,   -37,     0,
     -37,   -37,     0,     0,     0,   -37,     0,     0,   -37,   -37,
     -39,     0,   -39,   -39,   -39,   -39,     0,   -39,     0,     0,
       0,     0,     0,     0,   -39,   -39,   -39,     0,   -39,   -39,
       0,   -39,   -39,   -39,     0,   -39,   -39,     0,     0,     0,
     -39,     0,     0,   -39,   -39,   -40,     0,   -40,   -40,   -40,
     -40,     0,   -40,     0,     0,     0,     0,     0,     0,   -40,
     -40,   -40,     0,   -40,   -40,     0,   -40,   -40,   -40,     0,
     -40,   -40,     0,     0,     0,   -40,     0,     0,   -40,   -40,
     -41,     0,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,
       0,     0,     0,     0,   -41,   -41,   -41,     0,   -41,   -41,
       0,   -41,   -41,   -41,     0,   -41,   -41,     0,     0,     0,
     -41,     0,     0,   -41,   -41,   -11,     0,   -11,   -11,   -11,
     -11,     0,   -11,     0,     0,     0,     0,     0,     0,   -11,
     -11,   -11,     0,   -11,   -11,     0,   -11,   -11,   -11,     0,
     -11,   -11,     0,     0,     0,   -11,     0,     0,   -11,   -11,
     -10,     0,   -10,   -10,   -10,   -10,     0,   -10,     0,     0,
       0,     0,     0,     0,   -10,   -10,   -10,     0,   -10,   -10,
       0,   -10,   -10,   -10,     0,   -10,   -10,     0,     0,     0,
     -10,     0,     0,   -10,   -10,   -52,     0,   -52,   -52,   -52,
     -52,     0,   -52,     0,     0,     0,     0,     0,     0,   -52,
     -52,   -52,     0,   -52,   -52,     0,   -52,   -52,   -52,     0,
     -52,   -52,     0,     0,     0,   -52,     0,     0,   -52,   -52,
     -51,     0,   -51,   -51,   -51,   -51,     0,   -51,     0,     0,
       0,     0,     0,     0,   -51,   -51,   -51,     0,   -51,   -51,
       0,   -51,   -51,   -51,     0,   -51,   -51,     0,     0,     0,
     -51,     0,     0,   -51,   -51,   -12,     0,   -12,   -12,   -12,
     -12,     0,   -12,     0,     0,     0,     0,     0,     0,   -12,
     -12,   -12,     0,   -12,   -12,     0,   -12,   -12,   -12,     0,
     -12,   -12,     0,     0,     0,   -12,     0,     0,   -12,   -12,
     -60,     0,   -60,   -60,   -60,   -60,     0,   -60,     0,     0,
       0,     0,     0,     0,   -60,   -60,   -60,     0,   -60,   -60,
       0,   -60,   -60,   -60,     0,   -60,   -60,     0,     0,     0,
     -60,     0,     0,   -60,   -60,   -59,     0,   -59,   -59,   -59,
     -59,     0,   -59,     0,     0,     0,     0,     0,     0,   -59,
     -59,   -59,     0,   -59,   -59,     0,   -59,   -59,   -59,     0,
     -59,   -59,     0,     0,     0,   -59,     0,     0,   -59,   -59,
     -14,     0,   -14,   -14,   -14,   -14,     0,   -14,     0,     0,
       0,     0,     0,     0,   -14,   -14,   -14,     0,   -14,   -14,
       0,   -14,   -14,   -14,     0,   -14,   -14,     0,     0,     0,
     -14,     0,     0,   -14,   -14,   -30,     0,   -30,   -30,   -30,
     -30,     0,   -30,     0,     0,     0,     0,     0,     0,   -30,
     -30,   -30,     0,   -30,   -30,     0,   -30,   -30,   -30,     0,
     -30,   -30,     0,     0,     0,   -30,     0,     0,   -30,   -30,
     -13,     0,   -13,   -13,   -13,   -13,     0,   -13,     0,     0,
       0,     0,     0,     0,   -13,   -13,   -13,     0,   -13,   -13,
       0,   -13,   -13,   -13,     0,   -13,   -13,     0,     0,     0,
     -13,     0,     0,   -13,   -13,   -47,     0,   -47,   -47,   -47,
     -47,     0,   -47,     0,     0,     0,     0,     0,     0,   -47,
     -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,     0,
     -47,   -47,     0,     0,     0,   -47,     0,     0,   -47,   -47,
     -48,     0,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,
       0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,   -48,
       0,   -48,   -48,   -48,     0,   -48,   -48,     0,     0,     0,
     -48,     0,     0,   -48,   -48,   -43,     0,   -43,   -43,   -43,
     -43,     0,   -43,     0,     0,     0,     0,     0,     0,   -43,
     -43,   -43,     0,   -43,   -43,     0,   -43,   -43,   -43,     0,
     -43,   -43,     0,     0,     0,   -43,     0,     0,   -43,   -43,
     -46,     0,   -46,   -46,   -46,   -46,     0,   -46,     0,     0,
       0,     0,     0,     0,   -46,   -46,   -46,     0,   -46,   -46,
       0,   -46,   -46,   -46,     0,   -46,   -46,     0,     0,     0,
     -46,     0,     0,   -46,   -46,   -49,     0,   -49,   -49,   -49,
     -49,     0,   -49,     0,     0,     0,     0,     0,     0,   -49,
     -49,   -49,     0,   -49,   -49,     0,   -49,   -49,   -49,     0,
     -49,   -49,     0,     0,     0,   -49,     0,     0,   -49,   -49,
     -44,     0,   -44,   -44,   -44,   -44,     0,   -44,     0,     0,
       0,     0,     0,     0,   -44,   -44,   -44,     0,   -44,   -44,
       0,   -44,   -44,   -44,     0,   -44,   -44,     0,     0,     0,
     -44,     0,     0,   -44,   -44,   -50,     0,   -50,   -50,   -50,
     -50,     0,   -50,     0,     0,     0,     0,     0,     0,   -50,
     -50,   -50,     0,   -50,   -50,     0,   -50,   -50,   -50,     0,
     -50,   -50,     0,     0,     0,   -50,     0,     0,   -50,   -50,
     -45,     0,   -45,   -45,   -45,   -45,     0,   -45,     0,     0,
       0,     0,     0,     0,   -45,   -45,   -45,     0,   -45,   -45,
       0,   -45,   -45,   -45,     0,   -45,   -45,     0,     0,     0,
     -45,     0,     0,   -45,   -45,   -55,     0,   -55,   -55,   -55,
     -55,     0,   -55,     0,     0,     0,     0,     0,     0,   -55,
     -55,   -55,     0,   -55,   -55,     0,   -55,   -55,   -55,     0,
     -55,   -55,     0,     0,     0,   -55,     0,     0,   -55,   -55,
     -58,     0,   -58,   -58,   -58,   -58,     0,   -58,     0,     0,
       0,     0,     0,     0,   -58,   -58,   -58,     0,   -58,   -58,
       0,   -58,   -58,   -58,     0,   -58,   -58,     0,     0,     0,
     -58,     0,     0,   -58,   -58,   -57,     0,   -57,   -57,   -57,
     -57,     0,   -57,     0,     0,     0,     0,     0,     0,   -57,
     -57,   -57,     0,   -57,   -57,     0,   -57,   -57,   -57,     0,
     -57,   -57,     0,     0,     0,   -57,     0,     0,   -57,   -57,
     -54,     0,   -54,   -54,   -54,   -54,     0,   -54,     0,     0,
       0,     0,     0,     0,   -54,   -54,   -54,     0,   -54,   -54,
       0,   -54,   -54,   -54,     0,   -54,   -54,     0,     0,     0,
     -54,     0,     0,   -54,   -54,   -62,     0,   -62,   -62,   -62,
     -62,     0,   -62,     0,     0,     0,     0,     0,     0,   -62,
     -62,   -62,     0,   -62,   -62,     0,   -62,   -62,   -62,     0,
     -62,   -62,     0,     0,     0,   -62,     0,     0,   -62,   -62,
     -63,     0,   -63,   -63,   -63,   -63,     0,   -63,     0,     0,
       0,     0,     0,     0,   -63,   -63,   -63,     0,   -63,   -63,
       0,   -63,   -63,   -63,     0,   -63,   -63,     0,     0,     0,
     -63,     0,     0,   -63,   -63,   -64,     0,   -64,   -64,   -64,
     -64,     0,   -64,     0,     0,     0,     0,     0,     0,   -64,
     -64,   -64,     0,   -64,   -64,     0,   -64,   -64,   -64,     0,
     -64,   -64,     0,     0,     0,   -64,     0,     0,   -64,   -64,
     -61,     0,   -61,   -61,   -61,   -61,     0,   -61,     0,     0,
       0,     0,     0,     0,   -61,   -61,   -61,     0,   -61,   -61,
       0,   -61,   -61,   -61,     0,   -61,   -61,     0,     0,     0,
     -61,     0,     0,   -61,   -61,   560,     0,     2,     3,     4,
     223,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,   561,   562,   563,   564,
     565,   566,     0,     0,     0,    17,     0,   560,   567,     2,
       3,     4,   223,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,     0,     0,     0,   561,   562,
     563,   576,   565,   566,     0,     0,     0,    17,     0,   312,
     567,     2,     3,     4,   223,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
     313,   314,   315,   590,   316,   317,     0,     0,     0,    17,
       0,   312,   318,     2,     3,     4,   223,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
       0,     0,   313,   314,   315,   592,   316,   317,     0,     0,
       0,    17,     0,   560,   318,     2,     3,     4,   223,     0,
       6,     0,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,     0,     0,   561,   562,   563,   668,   565,   566,
       0,     0,     0,    17,     0,   560,   567,     2,     3,     4,
     223,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,   561,   562,   563,   670,
     565,   566,     0,     0,     0,    17,     0,   264,   567,     2,
       3,     4,   223,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,     0,     0,     0,   267,   268,
     269,     0,   270,   271,     0,     0,     0,    17,     0,   312,
     272,     2,     3,     4,   223,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
     313,   314,   315,     0,   316,   317,     0,     0,     0,    17,
       0,   560,   318,     2,     3,     4,   223,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
       0,     0,   561,   562,   563,     0,   565,   566,     0,     0,
       0,    17,     0,   102,   567,   244,   245,   246,   247,   110,
       6,   224,   225,   226,   227,     0,     6,     7,     8,     9,
       0,     0,     0,     7,     8,     9,     0,   125,     0,   244,
     245,   246,   247,   248,     6,     0,     0,     0,     0,   228,
       0,     7,     8,     9,   127,     0,   244,   245,   246,   247,
       0,     6,     0,     0,     0,     0,     0,   248,     7,     8,
       9,   129,     0,   244,   245,   246,   247,     0,     6,     0,
       0,     0,     0,     0,   248,     7,     8,     9,   131,     0,
     244,   245,   246,   247,     0,     6,     0,     0,     0,     0,
       0,   248,     7,     8,     9,   133,     0,   244,   245,   246,
     247,     0,     6,     0,     0,     0,     0,     0,   248,     7,
       8,     9,   135,     0,   244,   245,   246,   247,     0,     6,
       0,     0,     0,     0,     0,   248,     7,     8,     9,   137,
       0,   244,   245,   246,   247,     0,     6,     0,     0,     0,
       0,     0,   248,     7,     8,     9,   139,     0,   244,   245,
     246,   247,     0,     6,     0,     0,     0,     0,     0,   248,
       7,     8,     9,   141,     0,   244,   245,   246,   247,     0,
       6,     0,     0,     0,     0,     0,   248,     7,     8,     9,
     328,     0,   281,   282,   283,   284,     0,     6,     0,     0,
       0,     0,     0,   248,     7,     8,     9,   331,     0,   224,
     225,   226,   227,     0,     6,     0,     0,     0,     0,     0,
     285,     7,     8,     9,   345,     0,   224,   225,   226,   227,
       0,     6,     0,     0,     0,     0,     0,   228,     7,     8,
       9,   361,     0,   350,   351,   352,   353,     0,     6,     0,
       0,     0,     0,     0,   228,     7,     8,     9,   364,     0,
     350,   351,   352,   353,     0,     6,     0,     0,     0,     0,
       0,   354,     7,     8,     9,   366,     0,   350,   351,   352,
     353,     0,     6,     0,     0,     0,     0,     0,   354,     7,
       8,     9,   368,     0,   350,   351,   352,   353,     0,     6,
       0,     0,     0,     0,     0,   354,     7,     8,     9,   370,
       0,   350,   351,   352,   353,     0,     6,     0,     0,     0,
       0,     0,   354,     7,     8,     9,   374,     0,   350,   351,
     352,   353,     0,     6,     0,     0,     0,     0,     0,   354,
       7,     8,     9,   383,     0,     2,     3,     4,   223,     0,
       6,     0,     0,     0,     0,     0,   354,     7,     8,     9,
     388,     0,   224,   225,   226,   227,     0,     6,     0,     0,
       0,     0,     0,    17,     7,     8,     9,   413,     0,   402,
     403,   404,   405,     0,     6,     0,     0,     0,     0,     0,
     228,     7,     8,     9,   416,     0,   402,   403,   404,   405,
       0,     6,     0,     0,     0,     0,     0,   406,     7,     8,
       9,   418,     0,   402,   403,   404,   405,     0,     6,     0,
       0,     0,     0,     0,   406,     7,     8,     9,   420,     0,
     402,   403,   404,   405,     0,     6,     0,     0,     0,     0,
       0,   406,     7,     8,     9,   422,     0,   402,   403,   404,
     405,     0,     6,     0,     0,     0,     0,     0,   406,     7,
       8,     9,   426,     0,   402,   403,   404,   405,     0,     6,
       0,     0,     0,     0,     0,   406,     7,     8,     9,   435,
       0,     2,     3,     4,   223,     0,     6,     0,     0,     0,
       0,     0,   406,     7,     8,     9,   442,     0,   350,   351,
     352,   353,     0,     6,     0,     0,     0,     0,     0,    17,
       7,     8,     9,   444,     0,   350,   351,   352,   353,     0,
       6,     0,     0,     0,     0,     0,   354,     7,     8,     9,
     446,     0,   350,   351,   352,   353,     0,     6,     0,     0,
       0,     0,     0,   354,     7,     8,     9,   448,     0,   350,
     351,   352,   353,     0,     6,     0,     0,     0,     0,     0,
     354,     7,     8,     9,   450,     0,   350,   351,   352,   353,
       0,     6,     0,     0,     0,     0,     0,   354,     7,     8,
       9,   452,     0,   350,   351,   352,   353,     0,     6,     0,
       0,     0,     0,     0,   354,     7,     8,     9,   454,     0,
     350,   351,   352,   353,     0,     6,     0,     0,     0,     0,
       0,   354,     7,     8,     9,   456,     0,   350,   351,   352,
     353,     0,     6,     0,     0,     0,     0,     0,   354,     7,
       8,     9,   458,     0,   350,   351,   352,   353,     0,     6,
       0,     0,     0,     0,     0,   354,     7,     8,     9,   464,
       0,   224,   225,   226,   227,     0,     6,     0,     0,     0,
       0,     0,   354,     7,     8,     9,   474,     0,   224,   225,
     226,   227,     0,     6,     0,     0,     0,     0,     0,   228,
       7,     8,     9,   485,     0,   402,   403,   404,   405,     0,
       6,     0,     0,     0,     0,     0,   228,     7,     8,     9,
     487,     0,   402,   403,   404,   405,     0,     6,     0,     0,
       0,     0,     0,   406,     7,     8,     9,   489,     0,   402,
     403,   404,   405,     0,     6,     0,     0,     0,     0,     0,
     406,     7,     8,     9,   491,     0,   402,   403,   404,   405,
       0,     6,     0,     0,     0,     0,     0,   406,     7,     8,
       9,   493,     0,   402,   403,   404,   405,     0,     6,     0,
       0,     0,     0,     0,   406,     7,     8,     9,   495,     0,
     402,   403,   404,   405,     0,     6,     0,     0,     0,     0,
       0,   406,     7,     8,     9,   497,     0,   402,   403,   404,
     405,     0,     6,     0,     0,     0,     0,     0,   406,     7,
       8,     9,   499,     0,   402,   403,   404,   405,     0,     6,
       0,     0,     0,     0,     0,   406,     7,     8,     9,   501,
       0,   402,   403,   404,   405,     0,     6,     0,     0,     0,
       0,     0,   406,     7,     8,     9,   504,     0,   224,   225,
     226,   227,     0,     6,     0,     0,     0,     0,     0,   406,
       7,     8,     9,   514,     0,   224,   225,   226,   227,     0,
       6,     0,     0,     0,     0,     0,   228,     7,     8,     9,
     603,     0,     2,     3,     4,   223,     0,     6,     0,     0,
       0,     0,     0,   228,     7,     8,     9,   623,     0,   224,
     225,   226,   227,     0,     6,     0,     0,     0,     0,     0,
      17,     7,     8,     9,     0,     0,  -105,  -105,  -105,  -105,
       0,  -105,     0,     0,     0,     0,     0,   228,  -105,  -105,
    -105,     0,     0,  -107,  -107,  -107,  -107,     0,  -107,     0,
       0,     0,     0,     0,  -105,  -107,  -107,  -107,     0,     0,
       2,     3,     4,   223,     0,     6,     0,     0,     0,     0,
       0,  -107,     7,     8,     9,     0,     0,   244,   245,   246,
     247,     0,     6,     0,     0,     0,     0,     0,    17,     7,
       8,     9,     0,     0,   224,   225,   226,   227,     0,     6,
       0,     0,     0,     0,     0,   248,     7,     8,     9,     0,
       0,   350,   351,   352,   353,     0,     6,     0,     0,     0,
       0,     0,   228,     7,     8,     9,     0,     0,   281,   282,
     283,   284,     0,     6,     0,     0,     0,     0,     0,   354,
       7,     8,     9,     0,     0,   402,   403,   404,   405,     0,
       6,     0,     0,     0,     0,     0,   285,     7,     8,     9,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,     0,     0,
       0,     0,     0,   406,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,     0,  -125,     0,  -125,  -125,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,     0,     0,   398,     0,   -98,
     -98,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,     0,
    -102,     0,  -102,  -102,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,     0,     0,  -108,     0,  -108,  -108,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,     0,  -116,     0,  -116,
    -116,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,
       0,  -103,     0,  -103,  -103,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,     0,  -119,     0,  -119,  -119,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,     0,     0,  -118,     0,
    -118,  -118,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
       0,  -117,     0,  -117,  -117,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,     0,     0,  -109,     0,  -109,  -109,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,     0,     0,     0,
    -108,  -108,   397,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
       0,     0,     0,     0,  -116,  -116,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,     0,     0,     0,   -97,   -97,   300,
     301,   302,   303,   -73,   305,   306,   307,     0,     0,     0,
       0,   -98,   -98,   300,   301,   302,   -77,   -77,   305,   306,
     307,     0,     0,     0,   -73,   -73,   300,   301,   302,   -81,
     -81,   -81,   306,   307,     0,     0,     0,     0,   -77,   -77,
     300,   301,   -85,   -85,   -85,   -85,   306,   307,     0,     0,
       0,   -81,   -81,   300,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,     0,     0,     0,     0,   -85,   -85,   397,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,     0,     0,     0,   -96,   -96,
     300,   301,   -91,   -91,   -91,   -91,   306,   307,     0,     0,
       0,     0,   -95,   -95,   300,   301,   -90,   -90,   -90,   -90,
     306,   307,     0,     0,     0,   -91,   -91,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,     0,     0,     0,     0,   -90,
     -90,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,     0,
       0,     0,  -100,  -100,   300,   301,   302,   303,   304,   305,
     306,   307,     0,     0,     0,     0,   -99,   -99,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,     0,     0,     0,   -67,
     -67,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,
       0,     0,     0,  -103,  -103,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,     0,     0,     0,  -119,  -119,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,     0,     0,     0,     0,
    -118,  -118,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
       0,     0,     0,  -117,  -117,   255,   256,   257,   258,   259,
     260,   261,   262,     0,     0,     0,     0,  -109,  -109,   255,
     256,   257,   258,   259,   260,   261,   262,     0,   263,     0,
     155,   255,   256,   257,   258,   259,   260,   261,   262,     0,
       0,     0,   263,     0,   158,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,     0,   263,     0,   216,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,     0,     0,     0,  -126,     0,
    -126,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,     0,
    -127,     0,  -127,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,     0,     0,     0,  -125,     0,  -125,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,     0,   341,     0,   -98,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,     0,     0,     0,
    -102,     0,  -102,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,     0,  -108,     0,  -108,   255,   256,   257,   258,   259,
     260,   261,   262,     0,     0,     0,  -116,     0,  -116,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,     0,   263,     0,
     440,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,
       0,     0,  -103,     0,  -103,   255,   256,   257,   258,   259,
     260,   261,   262,     0,  -119,     0,  -119,   255,   256,   257,
     258,   259,   260,   261,   262,     0,     0,     0,   263,     0,
     461,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,     0,
     263,     0,   483,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,     0,     0,     0,  -118,     0,  -118,   255,   256,   257,
     258,   259,   260,   261,   262,     0,  -117,     0,  -117,   255,
     256,   257,   258,   259,   260,   261,   262,     0,     0,     0,
     263,     0,   523,   255,   256,   257,   258,   259,   260,   261,
     262,     0,   263,     0,   528,   255,   256,   257,   258,   259,
     260,   261,   262,     0,     0,     0,   263,     0,   531,   255,
     256,   257,   258,   259,   260,   261,   262,     0,   263,     0,
     538,   255,   256,   257,   258,   259,   260,   261,   262,     0,
       0,     0,   263,     0,   543,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,     0,   263,     0,   546,   255,   256,   257,
     258,   259,   260,   261,   262,     0,     0,     0,  -109,     0,
    -109,   255,   256,   257,   258,   259,   260,   261,   262,     0,
     263,     0,   644,   255,   256,   257,   258,   259,   260,   261,
     262,     0,     0,     0,   263,     0,   647,   255,   256,   257,
     258,   259,   260,   261,   262,     0,   263,     0,   654,   255,
     256,   257,   258,   259,   260,   261,   262,     0,     0,     0,
     263,     0,   658,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,     0,   263,     0,   697,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,     0,     0,     0,     0,     0,  -127,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,     0,     0,     0,
    -125,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,
       0,     0,     0,     0,  -101,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,     0,     0,     0,  -102,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,     0,     0,     0,     0,     0,
    -108,   340,   -97,   -97,   -97,   -97,   -97,   -97,   -97,     0,
       0,     0,  -116,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,     0,     0,     0,     0,     0,   -97,   255,   256,   257,
     258,   -73,   260,   261,   262,     0,     0,     0,   -98,   255,
     256,   257,   -77,   -77,   260,   261,   262,     0,     0,     0,
       0,     0,   -73,   255,   256,   257,   -81,   -81,   -81,   261,
     262,     0,     0,     0,   -77,   255,   256,   -85,   -85,   -85,
     -85,   261,   262,     0,     0,     0,     0,     0,   -81,   255,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,     0,     0,     0,
     -85,   340,   -95,   -95,   -95,   -95,   -95,   -95,   -95,     0,
       0,     0,     0,     0,   -96,   255,   256,   -91,   -91,   -91,
     -91,   261,   262,     0,     0,     0,   -95,   255,   256,   -90,
     -90,   -90,   -90,   261,   262,     0,     0,     0,     0,     0,
     -91,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,     0,
       0,     0,   -90,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,     0,     0,     0,     0,     0,  -100,   255,   256,   257,
     258,   259,   260,   261,   262,     0,     0,     0,   -99,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,     0,     0,     0,
       0,     0,   -67,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,     0,     0,     0,  -103,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,     0,     0,     0,     0,     0,  -119,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,     0,     0,     0,
    -118,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,     0,
       0,     0,     0,     0,  -117,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,     0,     0,     0,  -109,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,     0,     0,   -98,    80,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,     0,     0,  -102,
    -102,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,     0,
       0,  -108,  -108,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,  -116,  -116,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,   115,    55,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,     0,     0,    54,    55,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,     0,  -103,
    -103,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,  -119,  -119,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,     0,     0,   160,    55,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,     0,     0,  -118,  -118,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,     0,     0,  -117,  -117,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,  -109,
    -109,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,   201,    55,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,   376,    55,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,   430,    55,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,   478,    55,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,   518,
      55,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,   533,    55,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,   548,    55,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,   597,    55,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,   610,    55,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,   616,
      55,    46,    47,    48,    49,    50,    51,    52,    53,     0,
       0,   627,    55,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,   649,    55,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,   687,    55,   300,   301,   302,
     303,   304,   305,   306,   307,     0,     0,     0,    55,   255,
     256,   257,   258,   259,   260,   261,   262,     0,     0,     0,
     308,    79,   -94,   -94,   -94,   -94,   -94,   -94,   -94,     0,
       0,     0,   263,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,     0,     0,   -94,    79,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,     0,     0,     0,  -101,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,     0,     0,   -97,    46,    47,    48,
      49,   -73,    51,    52,    53,     0,     0,     0,   -98,    46,
      47,    48,   -77,   -77,    51,    52,    53,     0,     0,   -73,
      46,    47,    48,   -81,   -81,   -81,    52,    53,     0,     0,
       0,   -77,    46,    47,   -85,   -85,   -85,   -85,    52,    53,
       0,     0,   -81,    46,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,     0,     0,     0,   -85,    79,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,     0,     0,   -96,    46,    47,   -91,   -91,
     -91,   -91,    52,    53,     0,     0,     0,   -95,    46,    47,
     -90,   -90,   -90,   -90,    52,    53,     0,     0,   -91,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,     0,     0,     0,
     -90,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,     0,
       0,  -100,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,   -99,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,     0,     0,   -67,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,     0,     0,     0,  -126,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,     0,     0,  -127,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,  -125,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,     0,     0,
    -102,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,     0,
       0,     0,  -108,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,     0,     0,  -116,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,     0,     0,     0,  -103,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,     0,     0,  -119,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,     0,     0,     0,  -118,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,     0,     0,  -117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -109
};

static const yytype_int16 yycheck[] =
{
       0,     0,   272,   385,   344,     6,   380,    31,     6,   349,
      29,    30,     1,     1,    31,     1,    16,    17,     1,     1,
      20,    20,     0,    21,     1,     1,     1,     6,    29,   160,
     161,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      29,    29,    20,    29,     0,     6,    29,    29,   318,     0,
      29,     1,    29,    29,     1,   437,    31,    32,   432,    59,
      60,   401,     1,    11,    20,     1,    31,    67,    29,   200,
     201,   202,     0,     1,     1,     3,     4,     5,     6,    29,
       8,     1,    29,    83,    32,    33,     6,    15,    16,    17,
      29,    19,    20,    29,    22,    23,    24,    25,    26,    27,
      10,    11,    29,    31,    11,    31,    34,     0,     1,     6,
       3,     4,     5,     6,    29,     8,    29,    30,    31,    29,
      29,   121,    15,    16,    17,    32,    19,    20,   468,    22,
      23,    24,    25,    26,    27,    32,    33,     6,    31,    11,
       1,    34,     3,     4,     5,     6,     6,     8,     6,    11,
     149,     6,    21,    32,    15,    16,    17,     7,   158,   159,
      32,    21,     0,    32,    33,   165,    32,    29,   508,    32,
      31,    32,    32,    33,    32,    33,   175,    32,    33,     1,
     158,   159,    20,    32,   184,     7,     8,     9,    10,    11,
      12,    13,    14,    32,    33,   194,    10,    11,   198,   199,
     200,   201,   202,    32,    10,    11,   184,    32,    30,    31,
      32,    33,    11,    32,   214,   215,   216,   217,    32,    33,
     198,   199,     6,   605,     0,   599,    32,     1,   228,     3,
       4,     5,     6,    32,     8,     1,   214,   215,   216,   217,
       6,    15,    16,    17,    20,    29,    29,    31,   248,    29,
       6,   382,     1,    19,    20,    10,    11,    31,    32,     9,
      10,    11,    12,    35,     0,     1,    32,     3,     4,     5,
       6,   271,     8,    29,    29,    31,     0,     6,    32,    15,
      16,    17,    32,    19,    20,   285,    22,    23,    24,    25,
      26,    27,    21,     6,     1,    31,    20,   567,    34,     6,
      29,    11,    31,   434,     1,    32,    33,     0,     1,     6,
       3,     4,     5,     6,     1,     8,    29,   317,    31,    29,
     158,   159,    15,    16,    17,    29,    19,    20,     6,    22,
      23,    24,    25,    26,    27,    10,    11,     1,    31,    29,
       1,    34,     6,    21,   344,     6,   184,    10,    11,   349,
      32,    29,    11,    31,   354,    19,    20,    32,    19,    20,
     198,   199,     1,    29,     0,   203,    34,     6,    32,    32,
      33,    32,    29,    32,    33,   213,   214,   215,   216,   217,
     380,   381,   158,   159,    20,   385,     1,     9,    10,    11,
      12,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      32,   401,   533,   534,    10,    11,   406,    11,   184,    32,
      32,    33,    10,    11,    29,    30,    31,   548,   549,    29,
      30,    31,   198,   199,    32,    29,    32,     9,    10,    11,
      12,    29,   432,   433,   158,   159,     1,   437,   214,   215,
     216,   217,     7,     8,     9,    10,    11,    12,    13,    14,
      32,     7,     8,     9,    10,    11,    12,    13,    14,     6,
     184,    10,    11,    12,    32,    30,    31,    32,   468,    29,
      30,   602,    19,    20,   198,   199,    32,    33,   609,   610,
     611,    32,    33,    32,   615,   616,   617,    10,    11,    12,
     214,   215,   216,   217,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    11,     1,    32,    33,    32,   508,    32,
       7,     8,     9,    10,    11,    12,    13,    14,   649,   650,
      32,    33,   158,   159,    32,    33,     9,    10,    11,    12,
       0,   531,   532,    30,    31,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,     0,   546,   547,   184,    32,
      33,    32,     0,   531,   532,   686,   687,   688,    31,    29,
      30,    29,   198,   199,   564,    20,   566,    31,   546,   547,
      10,    11,    20,     9,    10,    11,    12,    31,   214,   215,
     216,   217,    10,    11,    12,    31,   564,    31,     7,     8,
     590,    29,    32,    33,    13,    14,    32,    33,    31,   599,
     600,    32,    33,     1,    32,   605,   606,    31,   608,   609,
     610,   611,   590,   613,   614,   615,   616,   617,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,   606,    31,
     608,     1,    32,    33,     7,   613,   614,     7,     8,     9,
      10,    11,    12,    13,    14,    32,    33,   647,   648,    10,
      11,    12,   652,   653,   654,   655,   656,   657,   658,   659,
      32,    31,    32,    33,    10,    11,    12,    32,   668,   647,
     648,    32,    33,    32,   652,   653,   654,   655,   656,   657,
     658,   659,    29,    29,   684,   685,   686,   687,   688,    32,
     668,    32,    33,   531,   532,   695,   696,   697,   698,    32,
      33,    29,    30,   158,   159,     7,   684,   685,   546,   547,
     158,   159,    10,    11,    12,     1,    29,   695,   696,   697,
     698,     7,     8,     9,    10,    11,    12,    13,    14,   184,
       9,    10,    11,    12,    32,    33,   184,    32,     9,    10,
      11,    12,     6,   198,   199,    31,    32,    33,    32,    33,
     198,   199,   590,    32,    33,   531,   532,    21,    29,   214,
     215,   216,   217,    29,    30,    29,   214,   215,   216,   217,
     546,   547,     1,    32,    32,   613,   614,    32,     7,     8,
       9,    10,    11,    12,    13,    14,     1,    32,     9,    10,
      11,    12,     7,     8,     9,    10,    11,    12,    13,    14,
      32,    30,    31,    32,    32,    32,    29,   531,   532,   647,
     648,    32,    33,    35,   590,     1,    31,    32,   656,   657,
     658,   659,   546,   547,    32,    32,     9,    10,    11,    12,
     668,     9,    10,    11,    12,    32,    32,   613,   614,    32,
      32,    32,     9,    10,    11,    12,   684,   685,     1,    32,
       3,     4,     5,     6,    32,     8,    29,   695,   696,   697,
     698,    35,    15,    16,    17,    32,   590,    32,    29,    29,
      32,   647,   648,    29,     9,    10,    11,    12,    31,    32,
     656,   657,   658,   659,     9,    10,    11,    12,    29,   613,
     614,    31,   668,    31,    31,   531,   532,    32,     1,    31,
       3,     4,     5,     6,    32,     8,    29,    32,   684,   685,
     546,   547,    15,    16,    17,    29,    29,    29,    29,   695,
     696,   697,   698,   647,   648,    29,    32,    32,    31,    32,
      32,    32,   656,   657,   658,   659,     1,    29,     3,     4,
       5,     6,    35,     8,   668,     9,    10,    11,    12,    32,
      15,    16,    17,    32,   590,     9,    10,    11,    12,    32,
     684,   685,    10,    11,    12,    32,    31,    32,    32,    33,
      32,   695,   696,   697,   698,    29,    32,   613,   614,     0,
       1,    29,     3,     4,     5,     6,    29,     8,    29,     9,
      10,    11,    12,    29,    15,    16,    17,    29,    19,    20,
     175,    22,    23,    24,    25,    26,    27,    32,    32,    29,
      31,   647,   648,    34,     9,    10,    11,    12,    32,    20,
     656,   657,   658,   659,     1,   194,     3,     4,     5,     6,
     121,     8,   668,     9,    10,    11,    12,    32,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,   685,
       9,    10,    11,    12,    31,    32,    32,    33,     1,   695,
     696,   697,   698,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    32,    33,    -1,   531,   532,     9,    10,
      11,    12,    -1,   531,   532,    -1,    29,    30,    31,    -1,
      -1,   546,   547,     9,    10,    11,    12,     0,   546,   547,
      -1,    32,    33,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    17,    -1,    32,    20,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    10,    11,    12,    31,   590,    -1,    34,    -1,    -1,
      43,    44,   590,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    32,    33,    58,    59,    60,   613,   614,
       9,    10,    11,    12,    67,   613,   614,    -1,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      83,    -1,     1,    32,     3,     4,     5,     6,    -1,     8,
      -1,    -1,   647,   648,    -1,    -1,    15,    16,    17,   647,
     648,   656,   657,   658,   659,    -1,    -1,    -1,   656,   657,
     658,   659,    31,   668,     9,    10,    11,    12,   121,    -1,
     668,   124,    -1,    -1,     9,    10,    11,    12,    -1,   684,
     685,    -1,     7,     8,    29,    -1,   684,   685,    13,    14,
     695,   696,   697,   698,    29,    -1,   149,   695,   696,   697,
     698,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,   165,    -1,    -1,    -1,    15,    16,    17,    -1,
     173,    -1,   175,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,     9,    10,    11,    12,
      -1,   194,     9,    10,    11,    12,    -1,   200,   201,   202,
      -1,    -1,    -1,    -1,     0,     1,    29,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    32,    33,    -1,    -1,    15,
      16,    17,    -1,    19,    20,   228,    22,    23,    24,    25,
      26,    27,    -1,    -1,   237,    31,    -1,    -1,    34,    -1,
      -1,     9,    10,    11,    12,   248,   249,    -1,    -1,    -1,
      -1,    -1,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    29,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,   280,    15,    16,
      17,    18,   285,     7,     8,     9,    10,    11,    12,    13,
      14,   294,    -1,    29,    31,    -1,    -1,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    30,    -1,    32,    33,
      10,    11,    12,     7,     8,     9,    10,    11,    12,    13,
      14,     7,     8,     9,    10,    11,    12,    13,    14,    29,
     333,   334,   335,   336,   337,   338,   339,   340,   341,     0,
       1,   344,     3,     4,     5,     6,   349,     8,    -1,    -1,
      -1,   354,    -1,   356,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,     7,     8,
      31,    -1,    -1,    34,    13,    14,   379,   380,   381,     7,
       8,     9,   385,    -1,    12,    13,    14,   390,   391,   392,
     393,   394,   395,   396,   397,   398,    -1,     1,   401,     3,
       4,     5,     6,   406,     8,   408,     9,    10,    11,    12,
      -1,    15,    16,    17,    -1,    -1,     7,     8,     9,    10,
      17,    12,    13,    14,    -1,    29,    29,    31,   431,   432,
     433,    -1,    -1,    -1,   437,     7,     8,     9,    10,    11,
      12,    13,    14,    40,     9,    10,    11,    12,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      32,    33,    59,    60,    29,   468,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,     1,    83,     3,     4,     5,
       6,    32,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,   508,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,     0,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,   165,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    -1,     7,     8,     9,   598,   599,   600,    13,    14,
      -1,    -1,   605,   200,   201,   202,   609,   610,   611,     7,
       8,     9,   615,   616,   617,    13,    14,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,   228,    -1,    -1,    15,    16,    17,    -1,    19,    20,
     237,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,   248,   249,    34,    -1,    -1,    -1,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,     1,    -1,
      -1,    -1,    -1,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,   686,   687,   688,    -1,    -1,   285,     8,
       9,    10,    11,    12,    13,    14,    29,   294,    31,    -1,
      -1,    -1,    -1,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,   333,   334,   335,   336,
     337,   338,   339,   340,   341,     0,     1,   344,     3,     4,
       5,     6,   349,     8,    -1,    -1,    -1,   354,    -1,   356,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      -1,    -1,    -1,   380,   381,    17,     8,     9,    10,    11,
      12,    13,    14,   390,   391,   392,   393,   394,   395,   396,
     397,   398,    -1,    -1,   401,    -1,     7,     8,     9,   406,
      32,   408,    13,    14,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,     7,     8,     9,    59,    60,    12,
      13,    14,     7,     8,     9,   432,   433,    12,    13,    14,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    83,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,   468,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,   508,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,     1,    -1,     3,
       4,     5,     6,   165,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,     1,    -1,    -1,   200,   201,
     202,     7,     8,     9,    10,    11,    12,    13,    14,     1,
      -1,    -1,    -1,    -1,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    29,    30,    31,   228,    -1,    -1,    -1,
      -1,    -1,   599,   600,    -1,   237,    -1,    29,    30,    31,
      -1,    -1,   609,   610,   611,    -1,   248,   249,   615,   616,
     617,    -1,    -1,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,   285,    22,    23,    24,    25,    26,    27,
      -1,    -1,   294,    31,    -1,    -1,    34,    35,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,   686,
     687,   688,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,   333,   334,   335,   336,   337,   338,   339,   340,   341,
      31,     1,   344,     3,     4,     5,     6,   349,     8,    -1,
      -1,    -1,   354,    -1,   356,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    -1,   380,   381,
      17,     8,     9,    10,    11,    12,    13,    14,   390,   391,
     392,   393,   394,   395,   396,   397,   398,    -1,    -1,   401,
      -1,    -1,    29,    -1,   406,    -1,   408,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
     432,   433,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    83,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,   468,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,   508,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,     1,    -1,     3,     4,     5,     6,   165,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   201,   202,     1,    -1,     3,     4,
       5,     6,     1,     8,     3,     4,     5,     6,    -1,     8,
      15,    16,    17,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,   228,    -1,    -1,    29,    -1,    31,   599,   600,    -1,
     237,    -1,    31,    -1,    -1,    -1,    -1,   609,   610,   611,
      -1,   248,   249,   615,   616,   617,    -1,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,   285,    22,
      23,    24,    25,    26,    27,    -1,    -1,   294,    31,    -1,
      -1,    34,    -1,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,   686,   687,   688,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,   333,   334,   335,   336,
     337,   338,   339,   340,   341,     0,     1,   344,     3,     4,
       5,     6,   349,     8,    -1,    -1,    -1,   354,    -1,   356,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      -1,    -1,    -1,   380,   381,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   390,   391,   392,   393,   394,   395,   396,
     397,   398,    -1,    -1,   401,    -1,    -1,    -1,    -1,   406,
      -1,   408,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,   432,   433,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    83,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,   468,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,   508,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,     0,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,   165,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,   200,   201,
     202,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,     7,     8,     9,    10,   228,    12,    13,    14,
      -1,    -1,   599,   600,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,   609,   610,   611,    -1,   248,   249,   615,   616,
     617,    -1,    -1,   255,   256,   257,   258,   259,   260,   261,
     262,   263,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,   285,    22,    23,    24,    25,    26,    27,
      -1,    -1,   294,    31,    -1,    -1,    34,    -1,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,   686,
     687,   688,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,   333,   334,   335,   336,   337,   338,   339,   340,   341,
       0,     1,   344,     3,     4,     5,     6,   349,     8,    -1,
      -1,    -1,   354,    -1,   356,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    -1,    -1,   380,   381,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,   391,
     392,   393,   394,   395,   396,   397,   398,    -1,    -1,   401,
      -1,    -1,    -1,    -1,   406,    -1,   408,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
     432,   433,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    83,    -1,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,   468,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    -1,    -1,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,   508,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,   165,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,   200,   201,   202,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,   599,   600,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,   609,   610,   611,
      -1,   248,   249,   615,   616,   617,    -1,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,   285,    22,
      23,    24,    25,    26,    27,    -1,    -1,   294,    31,    -1,
      -1,    34,    35,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,     1,    -1,    -1,   686,   687,   688,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,   333,   334,   335,   336,
     337,   338,   339,   340,   341,    -1,    -1,   344,    -1,    29,
      48,    31,   349,    -1,    52,    53,    -1,   354,    -1,   356,
      -1,    59,    60,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    77,
      78,    -1,    -1,   380,   381,    83,    30,    -1,    32,    33,
      -1,    -1,    -1,   390,   391,   392,   393,   394,   395,   396,
     397,   398,    -1,     1,   401,     3,     4,     5,     6,   406,
       8,   408,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    29,    -1,    31,    -1,   432,   433,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,   165,    -1,    -1,
      -1,   468,    15,    16,    17,    17,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,   200,   201,   202,    47,    15,    16,    17,    -1,
      -1,   508,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,     1,    31,     3,     4,     5,     6,    -1,     8,    -1,
     228,    -1,    -1,    -1,    76,    15,    16,    17,    -1,    19,
      20,    83,    22,    23,    24,    25,    26,    27,    -1,    -1,
     248,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,   257,
     258,   259,   260,   261,   262,   263,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,   285,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,   599,   600,   302,   303,   304,   305,   306,   307,
     308,    -1,   609,   610,   611,    -1,    -1,    -1,   615,   616,
     617,    -1,    -1,   165,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,   333,   334,   335,   336,    -1,
     338,   339,    -1,   341,    -1,    -1,   344,    30,    -1,    32,
       1,   349,     3,     4,     5,     6,   354,     8,   200,   201,
     202,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    -1,   380,   381,    -1,    -1,   228,    -1,    -1,   686,
     687,   688,   390,   391,   392,   393,    -1,   395,   396,    -1,
     398,    -1,    -1,   401,    -1,    -1,   248,    -1,   406,    -1,
      -1,    -1,    -1,    17,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,   432,   433,    -1,    -1,    15,    16,
      17,    -1,    -1,   285,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    59,    60,    34,    -1,   301,
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    -1,
     468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   333,   334,   335,   336,   337,   338,   339,    -1,   341,
       0,     1,   344,     3,     4,     5,     6,   349,     8,    -1,
     508,    -1,   354,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    -1,    -1,   380,   381,
       7,     8,     9,    10,    11,    12,    13,    14,   390,   391,
     392,   393,   394,   395,   396,    -1,   398,    -1,    -1,   401,
      -1,   165,    29,    30,   406,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,     7,     8,     9,    10,    11,    12,    13,    14,
     432,   433,    -1,    29,    -1,    31,   200,   201,   202,    -1,
      -1,   599,   600,    -1,    -1,    30,    -1,    32,    33,    -1,
      -1,   609,   610,   611,    -1,    -1,    -1,   615,   616,   617,
      -1,    -1,    -1,    -1,   228,    -1,   468,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,   248,    -1,    15,    16,    17,    -1,
      -1,    17,    -1,   257,   258,   259,   260,   261,   262,   263,
      29,    -1,    31,    -1,    -1,    -1,   508,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,   285,    -1,    -1,    -1,    51,    -1,    -1,   686,   687,
     688,    -1,    -1,    59,    60,    32,    33,    -1,   302,   303,
     304,   305,   306,   307,   308,    -1,    -1,    -1,    74,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    83,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,   333,
     334,   335,   336,    -1,   338,   339,    -1,   341,    -1,    29,
     344,    31,    -1,    -1,    -1,   349,    -1,    -1,    -1,     1,
     354,     3,     4,     5,     6,    -1,     8,   599,   600,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,   609,   610,   611,
      -1,    -1,    -1,   615,   616,   617,   380,   381,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,   390,   391,   392,   393,
      -1,   395,   396,    -1,   398,    -1,    -1,   401,    -1,   165,
      -1,    -1,   406,    -1,    -1,    -1,    -1,    17,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,   432,   433,
      -1,    -1,    -1,    -1,   200,   201,   202,    -1,    29,    49,
      31,    -1,    -1,    -1,   686,   687,   688,    -1,    -1,    59,
      60,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,   228,    73,   468,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    83,    22,    23,    24,    25,    26,    27,
      -1,    -1,   248,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,   258,   259,   260,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,   508,    -1,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,   285,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,   303,   304,   305,
      31,    -1,   308,    34,    17,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,   165,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,   333,   334,   335,
      -1,    -1,    -1,    -1,    29,   341,    31,    50,   344,    -1,
      -1,    -1,    -1,   349,    -1,    -1,    59,    60,   354,    -1,
     200,   201,   202,    -1,    -1,   599,   600,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,   609,   610,   611,    -1,    -1,
      83,   615,   616,   617,   380,   381,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,   390,   391,   392,    -1,    -1,    -1,
      -1,    -1,   398,    -1,    -1,   401,    -1,    -1,   248,    -1,
     406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,   259,
      -1,    -1,    -1,   263,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,   432,   433,    -1,    15,
      16,    17,    -1,    19,    20,   285,    22,    23,    24,    25,
      26,    27,   686,   687,   688,    31,    -1,    -1,    34,    35,
      -1,    -1,   165,   303,   304,    -1,    -1,    -1,   308,    -1,
      -1,    -1,   468,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    17,
      15,    16,    17,   333,   334,    -1,    -1,   200,   201,   202,
      -1,   341,    -1,    -1,   344,    -1,    31,    -1,    -1,   349,
      -1,    -1,   508,    -1,   354,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,   228,     8,    55,    -1,    -1,
      -1,    59,    60,    15,    16,    17,    -1,    -1,    -1,    -1,
     380,   381,    -1,    -1,    -1,   248,    -1,    -1,    -1,    31,
     390,   391,    80,    -1,    -1,    83,   259,    -1,   398,    -1,
     263,   401,    -1,    -1,    -1,     1,   406,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,   285,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,   432,   433,    -1,    31,    -1,    -1,    34,    35,
      -1,   304,    -1,   599,   600,   308,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   609,   610,   611,    -1,    -1,    -1,   615,
     616,   617,    -1,    -1,    -1,    -1,    -1,    -1,   468,     1,
     333,     3,     4,     5,     6,    -1,     8,   165,   341,    -1,
      -1,   344,    -1,    15,    16,    17,   349,    -1,    -1,    -1,
       1,   354,     3,     4,     5,     6,    -1,     8,    -1,    31,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,   508,    -1,
      -1,    -1,   200,   201,   202,    -1,    -1,   380,   381,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,   390,    -1,    -1,
     686,   687,   688,    -1,    -1,   398,    -1,    -1,   401,    -1,
     228,    -1,    -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
     248,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,   432,
     433,    -1,    22,    23,    24,   263,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,   285,    -1,   599,
     600,    -1,    15,    16,    17,   468,    -1,    -1,    -1,   609,
     610,   611,    -1,    -1,    -1,   615,   616,   617,    31,    -1,
     308,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,   508,    22,    23,    24,    25,
      26,    27,    -1,   341,    -1,    31,   344,    -1,    34,    35,
       1,   349,     3,     4,     5,     6,   354,     8,     3,     4,
       5,     6,    -1,     8,    15,    16,    17,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,   686,   687,   688,    -1,
      31,    -1,   380,   381,    -1,    -1,    31,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
     398,    -1,    -1,   401,    -1,    15,    16,    17,   406,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,   599,   600,    -1,    -1,
      -1,    -1,    -1,    -1,   432,   433,   609,   610,   611,    -1,
      -1,    -1,   615,   616,   617,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
     468,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,     1,    -1,     3,     4,     5,     6,    -1,     8,
     508,    32,    33,   686,   687,   688,    15,    16,    17,    32,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,   599,   600,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,   609,   610,   611,    -1,    -1,    -1,   615,   616,   617,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,   686,   687,
     688,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
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
      31,    -1,     1,    34,     3,     4,     5,     6,    -1,     8,
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
      34,    35,     0,     1,    -1,     3,     4,     5,     6,    -1,
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
      -1,    31,     0,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,     5,
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
      -1,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,     1,    34,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,
      -1,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    31,    -1,     1,    34,     3,     4,     5,     6,     1,
       8,     3,     4,     5,     6,    -1,     8,    15,    16,    17,
      -1,    -1,    -1,    15,    16,    17,    -1,     1,    -1,     3,
       4,     5,     6,    31,     8,    -1,    -1,    -1,    -1,    31,
      -1,    15,    16,    17,     1,    -1,     3,     4,     5,     6,
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
      15,    16,    17,    -1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    31,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    30,    -1,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    30,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      30,    -1,    32,    33,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    30,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    30,    -1,    32,
      33,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    30,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    30,    -1,    32,    33,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    30,    -1,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    30,    -1,    32,    33,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    30,    -1,    32,    33,     7,
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
      10,    11,    12,    13,    14,    -1,    -1,    29,    30,     7,
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
      30,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    29,    30,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    29,    30,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    30,     7,     8,     9,    10,    11,    12,    13,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29
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
      69,     1,    62,     1,    60,    72,    73,    29,    30,    44,
      29,    30,    31,    32,    32,    32,    32,    32,    32,    32,
      29,    29,    35,    53,    75,    33,    32,     1,     1,    46,
      47,    48,    75,    76,     1,    42,    29,     1,    29,    29,
       1,    29,     1,    29,    25,    54,    25,    54,     1,    61,
       1,    61,    60,    45,    33,    75,    46,    54,    25,    25,
      29,    29,    29,    32,    48,    43,    54,    54,    61,    61,
       1,    61,    49,    32,    32,    32,    32,    32,    49,    54,
      54,    54,    54,     6,     3,     4,     5,     6,    31,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    74,
      75,    77,     6,     6,     3,     4,     5,     6,    31,    70,
      71,    74,    75,    77,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    30,     1,    19,    20,    22,    23,    24,
      26,    27,    34,    49,    55,    56,    57,    58,    59,    60,
      75,     3,     4,     5,     6,    31,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    74,    75,    77,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    30,     6,
      19,    20,     1,    22,    23,    24,    26,    27,    34,    49,
      55,    56,    57,    58,    59,    60,    29,    30,     1,     1,
      60,     1,    60,    11,    10,    12,     9,     8,    13,    14,
       7,    30,    69,     1,    31,     1,    60,    69,     1,    31,
       3,     4,     5,     6,    31,    69,    70,    71,    74,    75,
      77,     1,    68,    69,     1,    66,     1,    64,     1,    63,
       1,    65,    66,    66,     1,    62,    29,    21,    21,    31,
      31,    31,    31,     1,    60,    50,    29,    75,     1,    60,
      11,    10,    12,     9,     8,    13,    14,     7,    30,    69,
       1,    31,     3,     4,     5,     6,    31,    69,    70,    71,
      74,    75,    77,     1,    68,    69,     1,    66,     1,    64,
       1,    63,     1,    65,    66,    66,     1,    62,    21,    21,
      29,    31,    31,    31,    31,     1,    60,    50,    29,     1,
      32,    32,     1,    63,     1,    64,     1,    65,     1,    66,
       1,    68,     1,    66,     1,    66,     1,    69,     1,    62,
      73,    32,    32,    73,     1,    60,    69,     1,    31,     1,
      75,     1,    60,    78,     1,    60,     1,    61,    29,    29,
      51,    29,    30,    32,    32,     1,    63,     1,    64,     1,
      65,     1,    66,     1,    68,     1,    66,     1,    66,     1,
      69,     1,    62,    73,     1,    60,    69,     1,    31,     1,
      75,     1,    60,    78,     1,    60,     1,    61,    29,    29,
      51,    32,    32,    32,    32,    73,    32,    32,    32,    32,
      32,    32,    32,    29,    29,    35,     1,    32,    32,    32,
      73,    32,    32,    32,    32,    32,    32,    32,    29,    29,
      35,    32,    29,     1,    29,    29,     1,    29,     1,    29,
       1,    22,    23,    24,    25,    26,    27,    34,    49,    54,
      55,    56,    57,    58,    59,    60,    25,    54,    61,     1,
      61,    32,    29,     1,    29,    29,     1,    29,     1,    29,
      25,    54,    25,    54,    61,     1,    61,    29,    31,    31,
      31,    54,    31,     1,    60,    50,    25,    29,    25,    29,
      29,    29,    54,    25,    25,    29,    29,    29,     1,    75,
       1,    60,    78,     1,    60,     1,    61,    29,    29,    51,
      54,    54,    61,    61,     1,    61,    54,    54,    61,    61,
       1,    61,    32,    32,    32,    32,    32,    32,    32,    29,
      29,    35,    32,    32,    32,    32,    32,    32,    32,    32,
      29,     1,    29,    29,     1,    29,     1,    29,    25,    54,
      25,    54,    61,     1,    61,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    25,    25,    29,    29,    29,    54,
      54,    61,    61,     1,    61,    32,    32,    32,    32,    54,
      54,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    37,    38,    38,    39,    39,    39,
      40,    40,    40,    40,    40,    42,    43,    41,    44,    45,
      41,    46,    46,    47,    47,    47,    48,    48,    48,    50,
      49,    51,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    59,    59,    60,    60,    60,    60,    61,
      61,    62,    62,    62,    62,    63,    63,    63,    63,    64,
      64,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    67,    68,    68,
      68,    68,    69,    69,    70,    70,    70,    70,    71,    71,
      72,    72,    72,    73,    73,    74,    74,    74,    74,    74,
      75,    76,    76,    76,    76,    77,    77,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     1,
       3,     2,     4,     4,     3,     0,     0,     8,     0,     0,
       7,     0,     1,     3,     1,     1,     2,     1,     1,     0,
       4,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     5,     5,     5,     5,     5,
       5,     2,     2,     5,     7,     5,     5,     7,     6,     3,
       3,     9,     9,     9,     9,     1,     3,     3,     3,     0,
       1,     1,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     4,
       3,     1,     1,     1,     0,     1,     1,     3,     3,     2,
       1,     1,     1,     2,     2,     1,     1,     1,     1
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
#line 3982 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3988 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3994 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4000 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4006 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4012 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4018 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4024 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4030 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4036 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4042 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4048 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4054 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4060 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4066 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4072 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4078 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4084 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4090 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4096 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4102 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_1: /* @1  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4108 "src/bison/grammar.c"
        break;

    case YYSYMBOL_46_param_list_opt: /* param_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4114 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4120 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4126 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4132 "src/bison/grammar.c"
        break;

    case YYSYMBOL_51_block_item_list_opt: /* block_item_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4138 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4144 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4150 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4156 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4162 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4168 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4174 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4180 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4186 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4192 "src/bison/grammar.c"
        break;

    case YYSYMBOL_61_expression_opt: /* expression.opt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4198 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4204 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4210 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4216 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4222 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4228 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4234 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4240 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4246 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4252 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4258 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4264 "src/bison/grammar.c"
        break;

    case YYSYMBOL_73_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4270 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4276 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 130 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 4282 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4288 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4294 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4300 "src/bison/grammar.c"
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
#line 4609 "src/bison/grammar.c"
    break;

  case 4: /* prog: error  */
#line 137 "src/bison/grammar.y"
            {
        // idk if this is the best solution
        // actually dont work properly
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
    }
#line 4619 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration_list external_declaration  */
#line 144 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4625 "src/bison/grammar.c"
    break;

  case 6: /* external_declaration_list: external_declaration  */
#line 145 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4631 "src/bison/grammar.c"
    break;

  case 9: /* external_declaration: statement  */
#line 150 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4641 "src/bison/grammar.c"
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
#line 4668 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 179 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4678 "src/bison/grammar.c"
    break;

  case 12: /* var_declaration: type id '=' error  */
#line 184 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4689 "src/bison/grammar.c"
    break;

  case 13: /* var_declaration: id id '=' error  */
#line 190 "src/bison/grammar.y"
                      {
        show_error_range((yylsp[-3]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-3].sym)->name);
        symbol_free((yyvsp[-3].sym));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4700 "src/bison/grammar.c"
    break;

  case 14: /* var_declaration: id id ';'  */
#line 196 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-2]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-2].sym)->name);
        symbol_free((yyvsp[-2].sym));
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 4711 "src/bison/grammar.c"
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
#line 4752 "src/bison/grammar.c"
    break;

  case 16: /* $@2: %empty  */
#line 239 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4758 "src/bison/grammar.c"
    break;

  case 17: /* func_declaration: type id '(' @1 param_list.opt $@2 ')' compound_stmt  */
#line 239 "src/bison/grammar.y"
                                                              {
        (yyval.ast) = ast_userfunc_init((yyloc), current_context, (yyvsp[-4].ast), ast_params_init((yylsp[-3]), (yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4768 "src/bison/grammar.c"
    break;

  case 18: /* $@3: %empty  */
#line 244 "src/bison/grammar.y"
               {
        previous_context = current_context;
        list_push(&contexts, context_init("unnamed-func"));
        current_context = list_peek_last(&contexts);
        context_push_scope(current_context);
    }
#line 4779 "src/bison/grammar.c"
    break;

  case 19: /* $@4: %empty  */
#line 249 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4785 "src/bison/grammar.c"
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
#line 4798 "src/bison/grammar.c"
    break;

  case 21: /* param_list.opt: %empty  */
#line 259 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4804 "src/bison/grammar.c"
    break;

  case 23: /* params_list: params_list ',' param_decl  */
#line 263 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4810 "src/bison/grammar.c"
    break;

  case 24: /* params_list: param_decl  */
#line 264 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4816 "src/bison/grammar.c"
    break;

  case 25: /* params_list: error  */
#line 265 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4825 "src/bison/grammar.c"
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
#line 4842 "src/bison/grammar.c"
    break;

  case 27: /* param_decl: type  */
#line 283 "src/bison/grammar.y"
           {
        show_error_range((yylsp[0]), "expected identifier after " BGRN "'%s'" RESET "\n", (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
        (yyval.ast) = NULL;
    }
#line 4852 "src/bison/grammar.c"
    break;

  case 28: /* param_decl: id  */
#line 288 "src/bison/grammar.y"
         {
        show_error_range((yylsp[0]), "unknown type name for " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
        symbol_free((yyvsp[0].sym));
        (yyval.ast) = NULL;
    }
#line 4862 "src/bison/grammar.c"
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
#line 4880 "src/bison/grammar.c"
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
#line 4892 "src/bison/grammar.c"
    break;

  case 31: /* block_item_list.opt: block_item_list  */
#line 316 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4898 "src/bison/grammar.c"
    break;

  case 32: /* block_item_list.opt: %empty  */
#line 317 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4904 "src/bison/grammar.c"
    break;

  case 33: /* block_item_list: block_item_list block_item  */
#line 320 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4910 "src/bison/grammar.c"
    break;

  case 34: /* block_item_list: block_item  */
#line 321 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4916 "src/bison/grammar.c"
    break;

  case 43: /* io_stmt: READ '(' id ')' ';'  */
#line 336 "src/bison/grammar.y"
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
#line 4932 "src/bison/grammar.c"
    break;

  case 44: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 347 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4941 "src/bison/grammar.c"
    break;

  case 45: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 351 "src/bison/grammar.y"
                                       {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4950 "src/bison/grammar.c"
    break;

  case 46: /* io_stmt: WRITE '(' error ')' ';'  */
#line 355 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4960 "src/bison/grammar.c"
    break;

  case 47: /* io_stmt: READ '(' error ')' ';'  */
#line 360 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected identifier before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4970 "src/bison/grammar.c"
    break;

  case 48: /* io_stmt: READ '(' id ')' error  */
#line 365 "src/bison/grammar.y"
                            {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4981 "src/bison/grammar.c"
    break;

  case 49: /* io_stmt: WRITE '(' expression ')' error  */
#line 371 "src/bison/grammar.y"
                                     {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4992 "src/bison/grammar.c"
    break;

  case 50: /* io_stmt: WRITE '(' string_literal ')' error  */
#line 377 "src/bison/grammar.y"
                                         {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5003 "src/bison/grammar.c"
    break;

  case 51: /* expr_stmt: expression ';'  */
#line 385 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 5009 "src/bison/grammar.c"
    break;

  case 52: /* expr_stmt: error ';'  */
#line 386 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5018 "src/bison/grammar.c"
    break;

  case 53: /* cond_stmt: IF '(' expression ')' statement  */
#line 392 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 5026 "src/bison/grammar.c"
    break;

  case 54: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 395 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 5034 "src/bison/grammar.c"
    break;

  case 55: /* cond_stmt: IF '(' expression ')' ELSE  */
#line 398 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5044 "src/bison/grammar.c"
    break;

  case 56: /* cond_stmt: IF '(' error ')' statement  */
#line 403 "src/bison/grammar.y"
                                            {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5054 "src/bison/grammar.c"
    break;

  case 57: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 408 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5065 "src/bison/grammar.c"
    break;

  case 58: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 414 "src/bison/grammar.y"
                                      {
        show_error((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5075 "src/bison/grammar.c"
    break;

  case 59: /* jmp_stmt: RETURN expression ';'  */
#line 421 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyloc), (yyvsp[-1].ast)); }
#line 5081 "src/bison/grammar.c"
    break;

  case 60: /* jmp_stmt: RETURN error ';'  */
#line 422 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5090 "src/bison/grammar.c"
    break;

  case 61: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 428 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init((yyloc), current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 5098 "src/bison/grammar.c"
    break;

  case 62: /* iter_stmt: FOR '(' error ';' expression.opt ';' expression.opt ')' statement  */
#line 431 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-6]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5110 "src/bison/grammar.c"
    break;

  case 63: /* iter_stmt: FOR '(' expression.opt ';' error ';' expression.opt ')' statement  */
#line 438 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-4]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5122 "src/bison/grammar.c"
    break;

  case 64: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' error ')' statement  */
#line 445 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5134 "src/bison/grammar.c"
    break;

  case 66: /* expression: unary_expr '=' logical_or_expr  */
#line 455 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyloc), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 5140 "src/bison/grammar.c"
    break;

  case 67: /* expression: unary_expr '=' error  */
#line 456 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5150 "src/bison/grammar.c"
    break;

  case 68: /* expression: error '=' logical_or_expr  */
#line 461 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-2]), "expected expression before " WHT "'='" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5160 "src/bison/grammar.c"
    break;

  case 69: /* expression.opt: %empty  */
#line 468 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 5166 "src/bison/grammar.c"
    break;

  case 72: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 473 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5175 "src/bison/grammar.c"
    break;

  case 73: /* logical_or_expr: logical_or_expr OR error  */
#line 477 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5185 "src/bison/grammar.c"
    break;

  case 74: /* logical_or_expr: error OR logical_and_expr  */
#line 482 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5195 "src/bison/grammar.c"
    break;

  case 76: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 490 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5204 "src/bison/grammar.c"
    break;

  case 77: /* logical_and_expr: logical_and_expr AND error  */
#line 494 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5214 "src/bison/grammar.c"
    break;

  case 78: /* logical_and_expr: error AND eq_expr  */
#line 499 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5224 "src/bison/grammar.c"
    break;

  case 80: /* eq_expr: eq_expr EQ rel_expr  */
#line 507 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5233 "src/bison/grammar.c"
    break;

  case 81: /* eq_expr: eq_expr EQ error  */
#line 511 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5243 "src/bison/grammar.c"
    break;

  case 82: /* eq_expr: error EQ rel_expr  */
#line 516 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5253 "src/bison/grammar.c"
    break;

  case 84: /* rel_expr: rel_expr REL list_expr  */
#line 524 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5262 "src/bison/grammar.c"
    break;

  case 85: /* rel_expr: rel_expr REL error  */
#line 528 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5272 "src/bison/grammar.c"
    break;

  case 86: /* rel_expr: error REL list_expr  */
#line 533 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5282 "src/bison/grammar.c"
    break;

  case 88: /* list_expr: add_expr DL_DG list_expr  */
#line 541 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5291 "src/bison/grammar.c"
    break;

  case 89: /* list_expr: add_expr COLON list_expr  */
#line 545 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5300 "src/bison/grammar.c"
    break;

  case 90: /* list_expr: add_expr DL_DG error  */
#line 549 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5310 "src/bison/grammar.c"
    break;

  case 91: /* list_expr: add_expr COLON error  */
#line 554 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5320 "src/bison/grammar.c"
    break;

  case 92: /* list_expr: error DL_DG list_expr  */
#line 559 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5330 "src/bison/grammar.c"
    break;

  case 93: /* list_expr: error COLON list_expr  */
#line 564 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5340 "src/bison/grammar.c"
    break;

  case 95: /* add_expr: add_expr ADD mult_expr  */
#line 572 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5349 "src/bison/grammar.c"
    break;

  case 96: /* add_expr: add_expr ADD error  */
#line 576 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5359 "src/bison/grammar.c"
    break;

  case 97: /* add_expr: error ADD mult_expr  */
#line 581 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5369 "src/bison/grammar.c"
    break;

  case 99: /* mult_expr: mult_expr MULT unary_expr  */
#line 589 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5378 "src/bison/grammar.c"
    break;

  case 100: /* mult_expr: mult_expr MULT error  */
#line 593 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5388 "src/bison/grammar.c"
    break;

  case 101: /* mult_expr: error MULT unary_expr  */
#line 598 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5398 "src/bison/grammar.c"
    break;

  case 103: /* unary_expr: unary_ops unary_expr  */
#line 606 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5407 "src/bison/grammar.c"
    break;

  case 109: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 619 "src/bison/grammar.y"
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
#line 5430 "src/bison/grammar.c"
    break;

  case 110: /* arg_expr_list: arg_expr_list ',' expression  */
#line 639 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5436 "src/bison/grammar.c"
    break;

  case 111: /* arg_expr_list: expression  */
#line 640 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5442 "src/bison/grammar.c"
    break;

  case 112: /* arg_expr_list: error  */
#line 641 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5451 "src/bison/grammar.c"
    break;

  case 114: /* arg_expr_list.opt: %empty  */
#line 648 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5457 "src/bison/grammar.c"
    break;

  case 115: /* primary_expr: id  */
#line 651 "src/bison/grammar.y"
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
#line 5472 "src/bison/grammar.c"
    break;

  case 117: /* primary_expr: '(' expression ')'  */
#line 662 "src/bison/grammar.y"
                         {
        --(yyvsp[-1].ast)->rule_pos.first_column;
        ++(yyvsp[-1].ast)->rule_pos.last_column;
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 5482 "src/bison/grammar.c"
    break;

  case 118: /* primary_expr: '(' error ')'  */
#line 667 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5491 "src/bison/grammar.c"
    break;

  case 119: /* primary_expr: id error  */
#line 671 "src/bison/grammar.y"
               {
        show_error_range((yylsp[0]), "expected " WHT "';'" RESET "\n");
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 5501 "src/bison/grammar.c"
    break;

  case 123: /* type: INT LIST  */
#line 683 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5513 "src/bison/grammar.c"
    break;

  case 124: /* type: FLOAT LIST  */
#line 690 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5525 "src/bison/grammar.c"
    break;

  case 125: /* constant: NUMBER_REAL  */
#line 699 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init((yyloc), K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5531 "src/bison/grammar.c"
    break;

  case 126: /* constant: NUMBER_INT  */
#line 700 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init((yyloc), K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5537 "src/bison/grammar.c"
    break;

  case 127: /* constant: NIL  */
#line 701 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init((yyloc), K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5543 "src/bison/grammar.c"
    break;

  case 128: /* string_literal: STR_LITERAL  */
#line 704 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyloc), (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5552 "src/bison/grammar.c"
    break;


#line 5556 "src/bison/grammar.c"

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

#line 710 "src/bison/grammar.y"


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
