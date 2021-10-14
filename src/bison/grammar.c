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
#define YYLAST   12484

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  780

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
     528,   534,   542,   543,   544,   549,   556,   557,   560,   561,
     565,   570,   577,   578,   582,   587,   594,   595,   599,   604,
     611,   612,   616,   621,   628,   629,   633,   637,   642,   647,
     652,   659,   660,   664,   669,   676,   677,   681,   686,   693,
     694,   700,   701,   702,   703,   706,   707,   727,   728,   729,
     735,   736,   739,   749,   750,   757,   761,   768,   771,   772,
     773,   780,   789,   790,   791,   794
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

#define YYPACT_NINF (-445)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-146)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6016,    18, 11963, 11975, 11987,  3479,   228,   548,  5594,  5615,
      49,    50,     8,    10,    21,    45,  3690,  3961,   618,    40,
    7538,  7570,  7602,  7634,  7666,  7698,  7730,  7762,  7794,  7826,
    7858,   -21,   351,   382,   930,  1537,  1679,  1159,  2775, 11999,
    5895, 12011, 12023,  3944,     6, 12035, 10129,  4165,  4343,  4664,
    4724,  4756,  4343,  4343,  7890,  7922,  7954,  7986,  4797,  8018,
      37,   122,  8050,    92,  8082,   853,  8114,  4803,  8146,  1746,
   12047,    30,   586,   650,    51,   673,  -445, 10112,  8178,  8210,
    5002,  5045,  5140,  5171,  5191,  5222,  5282,  5321,  5355, 12059,
   12071,  1643,   296,   121,  8242,     4,   951, 12155,    89, 12167,
   12178,  1348,  2289,  5399,  1242,  3925,   692,  2620,  2386,  2414,
    2568, 12443,   429,    88,   161, 11001,   167,   193,   216, 11013,
     239,  4543,   231,   269,  8274,  8306, 12083, 12095, 10083,  5422,
     772,   265,  1078,  1188,  1224,  1278,   158, 12190,   867, 12201,
    1304, 12213,  2651, 12224,  2683, 12236, 12247, 12259,  2725, 12270,
    2822, 12282, 12293, 12305,   468,  4355,   387,   553,   270,  8338,
     312,  8370,   148,  8402,   314,   159,   316,     5,   320,    32,
      48,   945,  1388,   903,  8434,  1037,  5422,  1319,  8466,  1441,
     621,  5361, 12107,  8498,   622,   325,   634,   703,   723,   151,
    8530,   148,  8562,  8594,  8626,  8658,  8690,  8722,  8754,  8786,
    5971,  1499,  5971,  1678,  4689,   101, 10779,   232,  1569,   840,
     332,   818,   880,   334,  8818,  5971,  8850,  5971,  2129,  5971,
    2129,  5971,  2615,  5971,   342,   904,   336,  8882,  8914,   346,
    8946,   357,  8978, 11027,   359,  9010,  9042,   342,  5971,  5971,
    5971,  5971,  9074,  9106,  9138,  9170,  9202,  4091, 11039, 11053,
   11065,  2020,  5749,   103,   340,   439,   389,   471,   701,  1842,
   11079, 10158, 11091, 11105,  2506, 11117,   676,   989, 12316, 12328,
   12339,  1256,  5806, 10129, 12351, 12362,  2710, 12374,   424, 10187,
    5826,  5878,  5965,  6090,  6127,  5878,  5878,  9266,   195,   236,
      53,    74,    85,   111,  9272,   618,  1710,  1775,  1872,  1927,
    1985,  2055,   345,  3944, 10266, 10280, 10293,   196,  9290,   274,
      62,   911,   404,   870,  4680, 10428, 10307, 10204, 10320, 10334,
     279, 10347,  2163,  2201,  2261,  2358,  2413, 10141,    84,  2471,
   10221,  9307,  9324,  9341,  9358,  9375,  9324,  9324,  9392,  1043,
     241,   308, 10170,   130,   131,   138,   157,  9409,   618,  2650,
    2682,  2747,  2899,  2957,  3136,   435, 10793, 10805, 10819,   323,
    9426,   238,   377,   488,   413,   503,   833,  1112, 11131, 10831,
   10238, 10845, 10857,   998, 10871,  2541,   465,  5071, 10255,  9443,
    9460,  9477,  9494,  9511,  9460,  9460,  9528, 12143,   441, 11143,
     443,  9545,  9562,  9579,  9596,  9613,  9630,  9647,  9664,  9681,
   11157, 11169,  1643, 11183,   445, 12385, 12397,  1643,  3300,  3786,
    4101,   715,  9698,  4500, 10187,  5472, 11703,  1356, 11715,   485,
   11729, 11741,  1521,   823,  5450,   742,  4841,   478,  3106,   946,
    1023,  1416, 12454,   163,   250,   275,  2844,   176,  3027,  3204,
    3168,  9715,  3233,  3269, 12119,   472,   673,  3330,   775, 11195,
     474,  9732,  9749,  9766,  9783,  9800,  9817,  9834,  9851,  9868,
   10361, 10374,  1643,  3385, 10442, 10455, 10469,   421,  9885, 10482,
   10221, 10496, 10509,   536, 10523,   509, 10536, 10550,  2869,  1038,
    5461,  2115,  4976,   371,  3756,  1144,  1365,  1477, 12462,   427,
     263,   310,  3443,  3622,  3654,  3719,  3871,  4060,   188,  4126,
    3587,  4186,  9902,  4282,  3751, 12131,   489,   673,  4413, 11209,
     492,  9919,  9936,  9953,  9970,  9987, 10004, 10021, 10038, 10055,
   10883, 10897,  1643,  3513, 11221, 11235, 11247,   750, 10072, 11261,
   10255, 11273, 11287,  1813, 11299,   524, 11313, 11325,  3010,  1189,
    5761,   636,  5242,   662,  4004,  1320,  1442,  1711, 12470,   494,
   11339, 11351, 11755,   578, 11767,  1296, 11781,  1902, 11793,  2202,
   11807, 11819, 11833,  2228, 11845,  2239, 11859, 11871, 11885,   327,
     501, 12408, 12420,   507, 11365,   534, 11897, 11911,  1643,   539,
     541, 11377,   543,   549, 11391,   559, 10909,   512,  3816,  4469,
     567,  4514,   611, 10388, 10401, 10563,   497, 10577,  2335, 10590,
    1532, 10604,  1630, 10617, 10631, 10644,  1850, 10658,  1963, 10671,
   10685, 10698,   544,   576, 11403,   582, 10712, 10725,  1643,   588,
     593, 11417,   595,   600, 11429,   638, 10923,   646,  4563,  4869,
     651, 10935, 10949, 11443,  1107, 11455,  1389, 11469,  1806, 11481,
    1928, 11495, 11507, 11521,  2082, 11533,  2164, 11547, 11559, 11573,
     572,   669, 11585,   685, 11599, 11611,  1643, 11625, 12431, 11923,
   11937,   687,   702,   169,   709,   184,   185,  3999,  4231,   903,
    5104,  2305,  5486,  5672, 10415, 10739, 10752,   716,   738,   234,
     743,   248,   249,  4621,  4914,   903,  5917,  2791,  6058, 10961,
   11637, 11651,   751, 11949,  5712,  6147,  6182,  6232,  6267,  6302,
    6337,  6372,  5422,  6407,  5422,  6442,   376, 10975,   415, 10766,
    6478,  6510,  6542,  6574,  6606,  6638,  6670,  6702,  9234,  6734,
    9234,  6766,   574, 10987,   607, 11663,  6798,  5422,  6833,  5422,
    2129,  5422,  2129,  5422,  2989,  5422,  6869,  9234,  6901,  9234,
    2129,  9234,  2129,  9234,  3101,  9234,  6933,  6968,   753,  7003,
     758,  7038, 11677,   761,  7073,  7109,  7141,   769,  7173,   776,
    7205, 11689,   778,  7237,  5422,  5422,  5422,  5422,  9234,  9234,
    9234,  9234,  7269,  7304,  7339,  7374,  7410,  7442,  7474,  7506
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
    -445,  -445,  -445,   792,    97,  -445,  -445,  -445,  -445,  -445,
     623,  -445,   605,   146,  -291,  -444,  -445,   686,    82,   156,
     246,   255,  -445,   319,   390,     0,  -160,  5490,  5385,  5133,
    4882,  4324,  4575,  3943,  1585,  2071,  2557,  -445,  -388,  3043,
    1099,     1,  3529,  -436
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   130,    23,   191,   226,   162,   210,
     185,   186,   187,   296,    75,   131,   132,   133,   134,   297,
     298,   299,   135,   300,   301,   302,   123,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   157,   158,    42,
      72,   136,    45,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    44,   590,   583,   446,   -20,   193,    93,    79,    62,
     -20,    64,   267,   205,   570,   207,    71,    74,    -4,   573,
      31,    44,    66,   -20,   -20,    46,    47,    48,    49,    50,
      51,    52,    53,   196,   194,    94,   -20,    95,  -140,    63,
      76,    65,    54,  -140,    55,    56,    68,    57,    58,   198,
    -138,  -139,    67,    59,   436,  -138,  -139,   507,   229,   125,
     231,   197,   234,   630,   623,   117,  -140,   120,  -140,   122,
      60,    61,   452,   -88,   613,   438,    69,   199,  -138,  -139,
    -138,  -139,    25,   127,   437,   -15,   440,   -15,   -15,   -15,
     -15,   156,   -15,   113,   -88,   -88,    46,    22,   278,   -15,
     -15,   -15,    25,   -15,   -15,   439,   -15,   -15,   -15,   -15,
     -15,   -15,   442,   463,   391,   -15,   441,    22,   -15,   -15,
     166,   -15,   -15,  -141,   -15,   -15,   -15,   -15,  -141,   -15,
     218,   497,   499,   219,   651,   -82,   -15,   -15,   -15,   501,
     -15,   -15,   443,   -15,   -15,   -15,    24,   -15,   -15,   184,
     161,  -141,   -15,  -141,   339,   -15,    26,   339,   503,   328,
     -17,   498,   500,   189,   266,   -17,    24,   340,   341,   502,
     695,   355,   355,   361,   391,   361,    26,   579,   -17,   -17,
     -23,   209,   278,   -29,   -29,   698,   700,   329,   504,   619,
     661,   -17,   189,   167,   278,   -85,  -138,  -137,   696,  -145,
      31,  -138,    31,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,   177,   189,   699,   701,    31,   434,    31,   388,    31,
     388,    31,   388,    31,  -138,   169,  -137,  -137,  -137,  -137,
     677,  -123,  -123,  -123,  -123,   711,  -123,  -139,    31,    31,
      31,    31,  -139,  -123,  -123,  -123,    27,  -138,   170,   714,
     716,  -140,   390,   201,   203,    28,  -140,   435,   208,  -123,
     -87,   222,   490,   712,   223,  -139,    27,   -87,   692,  -140,
     -87,   172,   404,  -138,  -138,    28,  -141,   715,   717,  -140,
     461,  -141,   214,   587,   216,   451,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,   445,  -140,  -140,   227,   175,   228,
     178,   230,   182,   232,  -141,   235,   -82,   -82,   450,  -132,
     462,  -132,  -132,   183,  -139,   190,  -141,   349,   349,    29,
     243,   244,   245,   246,  -137,   159,   160,   350,   350,   491,
    -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,   391,    29,
    -139,  -139,  -141,  -141,   627,   192,    24,   506,    24,   195,
     392,   -88,  -137,  -137,  -137,  -137,    26,   -21,    26,   -83,
     510,    24,    80,    24,   224,    24,   -18,    24,   237,    24,
     236,    26,   -88,    26,   447,    26,    18,    26,   238,    26,
     -82,   452,   -91,   242,    24,    24,    24,    24,   511,   239,
      30,   241,    81,   -88,    26,    26,    26,    26,   394,   -96,
     -96,   -96,   156,   -91,   -91,   730,   -82,   156,   731,   -82,
      30,   -88,   575,   454,   -96,   -96,   -96,   351,   351,  -128,
    -128,   -96,  -137,   -92,   -92,   513,   352,   352,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,   -96,   -96,   451,   582,
      80,   585,   -92,   122,   734,   -92,    27,   735,    27,   -92,
     -92,   393,  -137,  -137,  -137,    28,  -137,    28,   -85,   -85,
     -85,    27,   156,    27,   508,    27,   523,    27,   615,    27,
      28,   -92,    28,   -87,    28,   551,    28,   572,    28,    80,
    -100,  -100,  -100,  -100,    27,    27,    27,    27,   392,   -91,
     353,   353,   279,    28,    28,    28,    28,   -83,   512,   -88,
     622,   589,   625,  -100,   122,   511,   594,   452,   -89,   706,
     -91,   708,   514,   -96,   -96,   -96,   330,   -88,   629,    29,
     -88,    29,   156,   -85,   632,   722,   -85,   724,   653,   -89,
     -89,   378,   -96,   657,    29,   -96,    29,   617,    29,   658,
      29,   671,    29,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -121,  -121,  -121,  -121,   451,  -121,    29,    29,    29,
      29,   354,   354,  -121,  -121,  -121,   660,   618,  -132,  -132,
     748,   662,   750,   663,   753,   665,   -83,   -83,   156,  -121,
     757,   666,   759,   511,   762,  -130,   181,    90,   392,   -89,
      30,   668,    30,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,   -83,   672,   740,   -83,    30,   741,    30,   674,    30,
     -89,    30,   673,    30,   676,  -132,  -132,    91,   156,   -31,
     678,   -31,   -31,   -31,   -31,   679,   -31,   681,    30,    30,
      30,    30,   682,   -31,   -31,   -31,   744,   -31,   -31,   745,
     -31,   -31,   -31,   -31,   -31,   -31,   -95,   -95,   513,   -31,
     375,   376,   -31,   -31,   -27,   -27,   156,   279,   280,   281,
     282,   283,   284,   285,   286,   -95,   -24,   211,   -95,   361,
     684,   361,   512,   -91,   128,   687,     2,     3,     4,     5,
     287,     6,   126,   355,   355,   361,   688,   361,     7,     8,
       9,   -91,   288,   289,   -91,   290,   291,   292,   129,   293,
     294,   689,    81,   -91,    17,  -137,  -137,   295,   -34,   395,
    -104,  -104,  -104,  -104,   396,   397,  -137,   691,   355,   693,
     355,   -91,  -137,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
     388,   694,   388,  -104,   388,   -26,   -26,   355,   697,   355,
     388,   355,   388,   355,   388,   355,  -137,  -137,   709,   703,
     705,  -137,   -95,   -95,   393,   -30,   -30,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,   719,   721,   710,   355,   355,
     355,   355,   713,   -37,   -95,   -37,   -37,   -37,   -37,  -137,
     -37,  -137,  -137,   725,   726,   764,   728,   -37,   -37,   -37,
     765,   -37,   -37,   767,   -37,   -37,   -37,   -37,   -37,   -37,
     736,   768,   738,   -37,   591,   592,   -37,   -37,   769,   746,
     771,   747,    78,   749,   213,   751,   225,   754,   179,   755,
       0,   756,     0,   758,   339,   760,     0,   763,     0,   349,
     349,     0,  -103,  -103,  -103,  -103,     0,   340,   341,   350,
     350,     0,  -100,  -100,  -100,  -100,   772,   773,   774,   775,
     776,   777,   778,   779,   115,  -103,   248,   249,   250,   251,
       0,     6,  -100,     0,   349,  -100,   349,     0,     7,     8,
       9,   116,  -127,  -127,   350,     0,   350,    81,   -89,  -100,
    -100,  -100,  -100,   349,   252,   349,     0,   349,     0,   349,
       0,   349,     0,   350,     0,   350,   -89,   350,     0,   350,
       0,   350,  -100,  -100,   204,     0,   356,   357,   358,   359,
       0,     6,   -28,   -28,   349,   349,   349,   349,     7,     8,
       9,   -92,   -92,   453,   350,   350,   350,   350,     0,   351,
     351,     0,   -86,     0,   360,   -86,   -25,   -25,   352,   352,
     -92,   -92,    82,   -92,   -92,     0,   342,     0,     2,     3,
       4,   247,     0,     6,     0,   394,   -99,   -99,   -99,   -92,
       7,     8,     9,     0,   351,     0,   351,   343,   344,   345,
     200,   346,   347,   352,     0,   352,    17,     0,   -99,   348,
     163,   164,   165,   351,     0,   351,     0,   351,     0,   351,
       0,   351,   352,     0,   352,     0,   352,     0,   352,   521,
     352,     0,   353,   353,     0,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,     0,   351,   351,   351,   351,  -137,  -137,
    -137,     0,     0,   352,   352,   352,   352,  -132,  -132,   522,
    -132,     0,  -110,  -110,  -110,  -110,     0,   353,   206,   353,
     356,   357,   358,   359,     0,     6,     0,  -103,  -103,  -103,
    -103,     0,     7,     8,     9,  -110,   353,     0,   353,     0,
     353,     0,   353,     0,   353,     0,   -86,     0,   360,   -86,
    -103,  -103,     0,   354,   354,  -137,  -137,     0,     0,   128,
       0,     2,     3,     4,     5,     0,     6,   353,   353,   353,
     353,     0,     0,     7,     8,     9,     0,   288,   289,    43,
     290,   291,   292,   129,   293,   294,     0,     0,   354,    17,
     354,     0,   295,   -33,     0,     0,   264,   512,   -89,    43,
     515,  -104,  -104,  -104,  -104,   516,   517,   354,     0,   354,
       0,   354,     0,   354,     0,   354,   -89,     0,     0,   -89,
       0,  -104,    92,    96,  -104,   276,   276,   276,   276,   276,
     276,   276,   276,   454,   -99,   -99,   -99,   276,   354,   354,
     354,   354,   114,     0,   264,     0,   264,    84,  -104,  -104,
    -104,  -104,    85,    86,   303,     0,   -99,   -99,     0,   276,
     276,   276,   276,   276,   276,   276,   276,   276,  -104,   -36,
     320,   -36,   -36,   -36,   -36,     0,   -36,     0,  -103,  -103,
    -103,  -103,     0,   -36,   -36,   -36,     0,   -36,   -36,     0,
     -36,   -36,   -36,   -36,   -36,   -36,     0,     0,  -103,   -36,
       0,  -103,   -36,   -36,     0,   -38,     0,   -38,   -38,   -38,
     -38,   303,   -38,     0,     0,   180,     0,     0,     0,   -38,
     -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,   -38,
     -38,   -38,   -95,   -95,    82,   -38,     0,  -137,   -38,   -38,
       0,   188,     0,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,   -95,   373,     0,   373,     0,     0,     0,     0,   -39,
     320,   -39,   -39,   -39,   -39,  -137,   -39,  -137,   212,     0,
     188,     0,     0,   -39,   -39,   -39,     0,   -39,   -39,     0,
     -39,   -39,   -39,   -39,   -39,   -39,   -93,   -93,   393,   -39,
     188,     0,   -39,   -39,   -93,   -93,    82,   264,     0,   264,
     -69,   264,   -69,   -69,   -69,   -69,     0,   -69,   -93,   514,
     -99,   -99,   -99,   -93,   -69,   -69,   -69,     0,   -69,   -69,
       0,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,   -99,
     -69,   264,   -99,   -69,   -69,    46,    47,   577,     0,     0,
     264,    52,    53,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,   264,   276,     0,  -110,  -110,  -110,  -110,   417,   417,
     417,   417,   417,   417,   417,   417,   417,   578,  -132,   342,
       0,     2,     3,     4,   247,     0,     6,  -110,  -110,   -93,
     -93,   513,   448,     7,     8,     9,     0,   264,     0,     0,
     343,   344,   345,   202,   346,   347,   320,     0,   -93,    17,
       0,   -93,   348,     0,     0,  -109,  -109,  -109,  -109,   473,
     473,   473,   473,   473,   473,   473,   473,   473,     0,     0,
       0,     0,   -35,     0,   -35,   -35,   -35,   -35,  -109,   -35,
       0,  -110,  -110,  -110,  -110,     0,   -35,   -35,   -35,   264,
     -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,   373,
       0,  -110,   -35,     0,  -110,   -35,   -35,   533,   533,   533,
     533,   533,   533,   533,   533,   533,  -109,  -109,  -109,  -109,
     417,   417,   417,   417,   417,   417,   417,   417,   417,   -65,
     -65,   320,   -65,   -65,   -65,   -65,   320,   -65,     0,  -109,
    -109,   264,     0,   417,   -65,   -65,   -65,     0,   -65,   -65,
       0,   -65,   -65,   -65,   215,   -65,   -65,     0,   279,   280,
     -65,     0,     0,   -65,   285,   286,   580,     0,   264,     0,
     264,   454,   -97,   -97,   -97,   303,    83,   -96,   -96,   -96,
     473,   473,   473,   473,   473,   473,   473,   473,   473,     0,
       0,   320,     0,     0,   -97,   -97,   -96,   264,     0,   473,
     -70,     0,   -70,   -70,   -70,   -70,     0,   -70,     0,     0,
       0,     0,     0,     0,   -70,   -70,   -70,     0,   -70,   -70,
       0,   -70,   -70,   -70,   -70,   -70,   -70,   620,     0,   264,
     -70,   264,   260,   -70,   -70,     0,   303,     0,     0,     0,
     533,   533,   533,   533,   533,   533,   533,   533,   533,     0,
       0,   320,     0,     0,     0,    89,     0,   264,     0,   533,
       0,    97,   100,   100,   100,   100,   100,   100,   100,  -101,
    -101,  -101,  -101,   100,   155,     0,   304,   305,   306,   307,
     260,     6,   260,     0,     0,     0,     0,     0,     7,     8,
       9,     0,  -101,  -101,     0,   100,   100,   100,   100,   100,
     100,   100,   152,   100,   308,  -131,   316,   320,   -62,   -62,
       0,   -62,   -62,   -62,   -62,     0,   -62,     0,  -100,  -100,
    -100,  -100,     0,   -62,   -62,   -62,     0,   -62,   -62,     0,
     -62,   -62,   -62,   217,   -62,   -62,     0,     0,  -100,   -62,
       0,   -41,   -62,   -41,   -41,   -41,   -41,   320,   -41,     0,
    -109,  -109,  -109,  -109,     0,   -41,   -41,   -41,     0,   -41,
     -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,     0,
    -109,   -41,     0,  -109,   -41,   -41,     0,   121,     0,     2,
       3,     4,   247,     0,     6,   320,     0,     0,   369,     0,
     369,     7,     8,     9,     0,     0,   316,     0,   373,     0,
     373,     0,     0,     0,     0,   -86,   -45,    17,   -45,   -45,
     -45,   -45,     0,   -45,   373,     0,   373,     0,     0,     0,
     -45,   -45,   -45,     0,   -45,   -45,     0,   -45,   -45,   -45,
     -45,   -45,   -45,   260,     0,   260,   -45,   260,     0,   -45,
     -45,     0,     0,     0,   655,   514,   -97,   -97,   -97,     0,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,     0,   264,
       0,   264,     0,   264,     0,   -97,     0,   260,   -97,   264,
       0,   264,  -132,   264,   656,  -132,   400,     0,     0,   398,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,   260,   405,  -106,
    -106,  -106,  -106,     0,   413,   421,   421,   421,   421,   421,
     421,   421,   421,   -40,  -111,   -40,   -40,   -40,   -40,     0,
     -40,     0,  -106,  -106,     0,     0,     0,   -40,   -40,   -40,
       0,   -40,   -40,   260,   -40,   -40,   -40,   -40,   -40,   -40,
       0,     0,   460,   -40,     0,     0,   -40,   -40,     0,     0,
       0,   394,   -97,   -97,   -97,   469,   477,   477,   477,   477,
     477,   477,   477,   477,     0,     0,     0,     0,   -42,     0,
     -42,   -42,   -42,   -42,   -97,   -42,     0,  -101,  -101,  -101,
    -101,     0,   -42,   -42,   -42,   260,   -42,   -42,     0,   -42,
     -42,   -42,   -42,   -42,   -42,   520,     0,  -101,   -42,     0,
    -101,   -42,   -42,   529,   537,   537,   537,   537,   537,   537,
     537,   537,  -105,  -105,  -105,  -105,   421,   421,   421,   421,
     421,   421,   421,   567,   421,     0,   -43,   316,   -43,   -43,
     -43,   -43,   316,   -43,     0,  -105,  -105,   260,     0,   576,
     -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,   -43,
     -43,   -43,   -43,     0,     0,     0,   -43,     0,     0,   -43,
     -43,  -137,     0,     0,   260,     0,   260,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,     0,   477,   477,   477,   477,
     477,   477,   477,   610,   477,     0,     0,   316,     0,     0,
    -137,  -137,  -137,   260,     0,   616,   -44,     0,   -44,   -44,
     -44,   -44,     0,   -44,     0,     0,     0,     0,     0,     0,
     -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,   -44,
     -44,   -44,   -44,     0,     0,   260,   -44,   260,   261,   -44,
     -44,  -106,  -106,  -106,  -106,     0,   537,   537,   537,   537,
     537,   537,   537,   648,   537,     0,     0,   316,     0,     0,
       0,  -106,     0,   260,  -106,   654,     0,   273,   273,   273,
     273,   273,   273,   273,   273,   -95,   -95,   453,     0,   273,
     387,     0,   248,   249,   250,   251,   261,     6,   261,     0,
       0,     0,     0,     0,     7,     8,     9,   -95,   -95,     0,
       0,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     252,   -86,   317,   316,   -60,     0,   -60,   -60,   -60,   -60,
       0,   -60,     0,  -105,  -105,  -105,  -105,     0,   -60,   -60,
     -60,     0,   -60,   -60,     0,   -60,   -60,   -60,   -60,   -60,
     -60,     0,     0,  -105,   -60,     0,  -105,   -60,   -60,     0,
       0,     0,   -59,   316,   -59,   -59,   -59,   -59,     0,   -59,
       0,  -101,  -101,  -101,  -101,     0,   -59,   -59,   -59,     0,
     -59,   -59,     0,   -59,   -59,   -59,   -59,   -59,   -59,     0,
       0,     0,   -59,     0,  -101,   -59,   -59,  -106,  -106,  -106,
    -106,   316,     0,     0,   370,     0,   370,     0,  -105,  -105,
    -105,  -105,   317,     0,   369,     0,   369,     0,     0,     0,
    -106,     0,   -61,     0,   -61,   -61,   -61,   -61,     0,   -61,
     369,  -105,   369,     0,     0,     0,   -61,   -61,   -61,     0,
     -61,   -61,     0,   -61,   -61,   -61,   -61,   -61,   -61,   261,
       0,   261,   -61,   261,     0,   -61,   -61,     0,  -103,  -103,
    -103,  -103,     0,     0,     0,     0,   707,     0,   356,   357,
     358,   359,     0,     6,     0,   260,     0,   260,  -103,   260,
       7,     8,     9,   261,     0,   260,     0,   260,     0,   260,
       0,     0,   261,     0,   -86,     0,   360,   -86,     0,     0,
       0,     0,     0,   261,   273,   -93,   -93,   453,     0,     0,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   -57,
       0,   -57,   -57,   -57,   -57,     0,   -57,   -93,   -93,     0,
       0,     0,     0,   -57,   -57,   -57,     0,   -57,   -57,   261,
     -57,   -57,   -57,   -57,   -57,   -57,     0,     0,   317,   -57,
       0,     0,   -57,   -57,     0,    83,   -99,   -99,   -99,     0,
       0,   470,   470,   470,   470,   470,   470,   470,   470,   470,
       0,     0,     0,     0,   -58,   -99,   -58,   -58,   -58,   -58,
       0,   -58,     0,  -110,  -110,  -110,  -110,     0,   -58,   -58,
     -58,   261,   -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,
     -58,   370,     0,  -110,   -58,     0,     0,   -58,   -58,   530,
     530,   530,   530,   530,   530,   530,   530,   530,     0,     0,
       0,     0,   414,   414,   414,   414,   414,   414,   414,   414,
     414,     0,   -11,   317,   -11,   -11,   -11,   -11,   317,   -11,
       0,     0,     0,   261,     0,   414,   -11,   -11,   -11,     0,
     -11,   -11,     0,   -11,   -11,   -11,   -11,   -11,   -11,     0,
       0,     0,   -11,     0,     0,   -11,   -11,   401,     0,     0,
     261,     0,   261,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,     0,   470,   470,   470,   470,   470,   470,   470,   470,
     470,     0,     0,   317,     0,     0,  -132,   402,  -132,   261,
       0,   470,   -10,     0,   -10,   -10,   -10,   -10,     0,   -10,
       0,     0,     0,     0,     0,     0,   -10,   -10,   -10,     0,
     -10,   -10,     0,   -10,   -10,   -10,   -10,   -10,   -10,     0,
       0,   261,   -10,   261,   262,   -10,   -10,  -109,  -109,  -109,
    -109,     0,   530,   530,   530,   530,   530,   530,   530,   530,
     530,     0,     0,   317,     0,     0,     0,  -109,     0,   261,
       0,   530,     0,   274,   274,   274,   274,   274,   274,   274,
     274,     0,     0,     0,     0,   274,   233,     0,   248,   249,
     250,   251,   262,     6,   262,     0,     0,    46,    47,    48,
       7,     8,     9,    52,    53,     0,     0,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   252,   -86,   318,   317,
     -41,   -41,     0,   -41,   -41,   -41,   -41,     0,   -41,     0,
      83,   -97,   -97,   -97,     0,   -41,   -41,   -41,     0,   -41,
     -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,     0,
     -97,   -41,   -45,   -45,   -41,   -45,   -45,   -45,   -45,   317,
     -45,     0,  -101,  -101,  -101,  -101,     0,   -45,   -45,   -45,
       0,   -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,
       0,   406,  -101,   -45,     0,     0,   -45,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,     0,     0,   317,     0,     0,
     371,     0,   371,     0,  -106,  -106,  -106,  -106,   318,  -132,
     370,   407,   370,     0,     0,     0,     0,   -40,   -40,     0,
     -40,   -40,   -40,   -40,  -106,   -40,   370,     0,   370,     0,
       0,     0,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,
     -40,   -40,   -40,   -40,   -40,   262,     0,   262,   -40,   262,
       0,   -40,    87,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
       0,     0,   723,     0,   356,   357,   358,   359,     0,     6,
       0,   261,     0,   261,  -111,   261,     7,     8,     9,   262,
       0,   261,     0,   261,     0,   261,     0,     0,   262,     0,
     -86,     0,   360,   -86,     0,     0,     0,     0,     0,   262,
     274,  -105,  -105,  -105,  -105,     0,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   -55,     0,   -55,   -55,   -55,
     -55,  -105,   -55,     0,     0,     0,     0,     0,     0,   -55,
     -55,   -55,     0,   -55,   -55,   262,   -55,   -55,   -55,   -55,
     -55,   -55,     0,     0,   318,   -55,   330,   331,   -55,   -55,
       0,     0,   336,   337,     0,     0,     0,   471,   471,   471,
     471,   471,   471,   471,   471,   471,     0,     0,     0,   -42,
     -42,     0,   -42,   -42,   -42,   -42,     0,   -42,     0,     0,
       0,     0,     0,     0,   -42,   -42,   -42,   262,   -42,   -42,
       0,   -42,   -42,   -42,   -42,   -42,   -42,   371,     0,     0,
     -42,     0,     0,   -42,     0,   531,   531,   531,   531,   531,
     531,   531,   531,   531,     0,     0,     0,     0,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   -43,   -43,   318,
     -43,   -43,   -43,   -43,   318,   -43,     0,     0,     0,   262,
       0,   415,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,
     -43,   -43,   -43,   -43,   -43,     0,     0,     0,   -43,     0,
     752,   -43,   248,   249,   250,   251,   262,     6,   262,     0,
       0,     0,     0,     0,     7,     8,     9,     0,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   378,   379,   318,
     252,   -86,     0,   384,   385,   262,     0,   471,   -54,     0,
     -54,   -54,   -54,   -54,     0,   -54,     0,     0,     0,     0,
       0,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,   262,   -54,   262,
     263,   -54,   -54,     0,     0,     0,     0,     0,   531,   531,
     531,   531,   531,   531,   531,   531,   531,     0,     0,   318,
       0,     0,     0,     0,     0,   262,     0,   531,     0,   275,
     275,   275,   275,   275,   275,   275,   275,     0,     0,     0,
       0,   275,   761,     0,   248,   249,   250,   251,   263,     6,
     263,     0,     0,   279,   280,   281,     7,     8,     9,   285,
     286,     0,     0,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   252,   -86,   319,   318,   -44,   -44,     0,   -44,
     -44,   -44,   -44,     0,   -44,     0,     0,     0,     0,     0,
       0,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,
     -44,   -44,   -44,   -44,     0,     0,     0,   -44,     0,   -68,
     -44,   -68,   -68,   -68,   -68,   318,   -68,     0,     0,     0,
       0,     0,     0,   -68,   -68,   -68,     0,   -68,   -68,     0,
     -68,   -68,   -68,   -68,   -68,   -68,     0,     0,     0,   -68,
       0,     0,   -68,   -68,     0,   581,     0,   248,   249,   250,
     251,     0,     6,   318,     0,     0,   372,     0,   372,     7,
       8,     9,   116,     0,   319,     0,   371,     0,   371,     0,
       0,     0,     0,     0,   -78,   252,   -78,   -78,   -78,   -78,
       0,   -78,   371,     0,   371,     0,     0,     0,   -78,   -78,
     -78,     0,   -78,   -78,     0,   -78,   -78,   -78,   -78,   -78,
     -78,   263,     0,   263,   -78,   263,     0,   -78,   -78,     0,
     586,     0,     2,     3,     4,   247,     0,     6,     0,     0,
       0,     0,     0,     0,     7,     8,     9,   262,     0,   262,
       0,   262,     0,     0,     0,   263,     0,   262,   -86,   262,
      17,   262,     0,     0,   263,     0,     0,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,   263,   275,     0,     0,     0,
       0,     0,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   -56,  -143,   -56,   -56,   -56,   -56,     0,   -56,     0,
       0,     0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,
     -56,   263,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
     319,   -56,     0,     0,   -56,   -56,     0,     0,     0,     0,
       0,     0,     0,   472,   472,   472,   472,   472,   472,   472,
     472,   472,     0,     0,     0,     0,   -16,     0,   -16,   -16,
     -16,   -16,     0,   -16,     0,     0,     0,     0,     0,     0,
     -16,   -16,   -16,   263,   -16,   -16,     0,   -16,   -16,   -16,
     -16,   -16,   -16,   372,     0,     0,   -16,     0,     0,   -16,
     -16,   532,   532,   532,   532,   532,   532,   532,   532,   532,
       0,     0,     0,     0,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   -60,   -60,   319,   -60,   -60,   -60,   -60,
     319,   -60,     0,     0,     0,   263,     0,   416,   -60,   -60,
     -60,     0,   -60,   -60,     0,   -60,   -60,   -60,   -60,   -60,
     -60,     0,     0,     0,   -60,     0,     0,   -60,     0,     0,
    -137,     0,   263,     0,   263,  -137,  -137,  -137,  -137,  -137,
    -137,  -137,  -137,  -137,   472,   472,   472,   472,   472,   472,
     472,   472,   472,     0,     0,   319,     0,     0,  -137,  -137,
    -137,   263,     0,   472,   -12,     0,   -12,   -12,   -12,   -12,
       0,   -12,     0,     0,     0,     0,     0,     0,   -12,   -12,
     -12,     0,   -12,   -12,     0,   -12,   -12,   -12,   -12,   -12,
     -12,     0,     0,   263,   -12,   263,   265,   -12,   -12,     0,
       0,     0,     0,     0,   532,   532,   532,   532,   532,   532,
     532,   532,   532,     0,     0,   319,     0,     0,     0,     0,
       0,   263,     0,   532,     0,   277,   277,   277,   277,   277,
     277,   277,   277,     0,     0,     0,     0,   277,   621,     0,
     248,   249,   250,   251,   265,     6,   265,     0,     0,     0,
       0,     0,     7,     8,     9,   116,     0,     0,     0,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   252,     0,
     321,   319,   -59,   -59,     0,   -59,   -59,   -59,   -59,     0,
     -59,     0,     0,     0,     0,     0,     0,   -59,   -59,   -59,
       0,   -59,   -59,     0,   -59,   -59,   -59,   -59,   -59,   -59,
       0,     0,     0,   -59,   -61,   -61,   -59,   -61,   -61,   -61,
     -61,   319,   -61,     0,     0,     0,     0,     0,     0,   -61,
     -61,   -61,     0,   -61,   -61,     0,   -61,   -61,   -61,   -61,
     -61,   -61,     0,     0,     0,   -61,     0,     0,   -61,     0,
       0,    70,     0,     2,     3,     4,   247,     0,     6,   319,
       0,     0,   374,     0,   374,     7,     8,     9,     0,     0,
     321,     0,   372,     0,   372,     0,     0,     0,     0,   -57,
     -57,    17,   -57,   -57,   -57,   -57,     0,   -57,   372,     0,
     372,     0,     0,     0,   -57,   -57,   -57,     0,   -57,   -57,
       0,   -57,   -57,   -57,   -57,   -57,   -57,   265,     0,   265,
     -57,   265,   626,   -57,     2,     3,     4,   247,     0,     6,
       0,     0,     0,   330,   331,   332,     7,     8,     9,   336,
     337,     0,     0,   263,     0,   263,     0,   263,     0,     0,
     -86,   265,    17,   263,     0,   263,     0,   263,     0,     0,
     265,     0,     0,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,   265,   277,     0,     0,     0,     0,     0,   418,   418,
     418,   418,   418,   418,   418,   418,   418,   -72,  -144,   -72,
     -72,   -72,   -72,     0,   -72,     0,     0,     0,     0,     0,
       0,   -72,   -72,   -72,     0,   -72,   -72,   265,   -72,   -72,
     -72,   -72,   -72,   -72,     0,     0,   321,   -72,     0,     0,
     -72,   -72,     0,     0,     0,     0,     0,     0,     0,   474,
     474,   474,   474,   474,   474,   474,   474,   474,     0,     0,
       0,   -58,   -58,     0,   -58,   -58,   -58,   -58,     0,   -58,
       0,     0,     0,     0,     0,     0,   -58,   -58,   -58,   265,
     -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,   -58,   374,
       0,     0,   -58,     0,     0,   -58,     0,   534,   534,   534,
     534,   534,   534,   534,   534,   534,     0,     0,     0,     0,
     418,   418,   418,   418,   418,   418,   418,   418,   418,     0,
       0,   321,    46,    47,    48,    49,   321,    51,    52,    53,
       0,   265,     0,   418,     0,    90,     0,     0,     0,     0,
     266,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,     0,
     259,     0,    73,     0,   248,   249,   250,   251,   265,     6,
     265,     0,     0,  -132,  -132,    91,     7,     8,     9,     0,
     474,   474,   474,   474,   474,   474,   474,   474,   474,     0,
      99,   321,   252,     0,     0,     0,     0,   265,     0,   474,
     327,     0,     2,     3,     4,   247,     0,     6,   259,     0,
     259,   378,   379,   380,     7,     8,     9,   384,   385,     0,
       0,   290,   291,   292,   702,   293,   294,   146,     0,   265,
      17,   265,     0,   295,   315,     0,     0,     0,     0,     0,
     534,   534,   534,   534,   534,   534,   534,   534,   534,     0,
       0,   321,     0,     0,     0,     0,     0,   265,     0,   534,
     -55,   -55,     0,   -55,   -55,   -55,   -55,     0,   -55,     0,
       0,     0,     0,     0,     0,   -55,   -55,   -55,     0,   -55,
     -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   -55,  -137,     0,   -55,     0,     0,     0,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,  -137,     0,   321,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,   368,     0,   368,     0,
    -137,  -137,  -137,     0,   315,     0,   -54,   -54,     0,   -54,
     -54,   -54,   -54,  -142,   -54,     0,     0,     0,     0,     0,
       0,   -54,   -54,   -54,     0,   -54,   -54,   321,   -54,   -54,
     -54,   -54,   -54,   -54,     0,     0,     0,   -54,     0,     0,
     -54,   259,     0,   259,     0,   259,    98,     0,   268,   269,
     270,   271,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,     0,   321,   -68,   -68,     0,   -68,
     -68,   -68,   -68,     0,   -68,   259,   272,     0,   374,     0,
     374,   -68,   -68,   -68,     0,   -68,   -68,     0,   -68,   -68,
     -68,   -68,   -68,   -68,   374,   259,   374,   -68,     0,     0,
     -68,     0,     0,   420,   259,   259,   259,   259,   259,   259,
     259,     0,   327,     0,     2,     3,     4,   247,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,   259,     0,   290,   291,   292,   704,   293,   294,   265,
       0,   265,    17,   265,     0,   295,     0,     0,     0,   265,
       0,   265,     0,   265,   476,   315,   315,   315,   315,   315,
     315,   315,   -78,   -78,     0,   -78,   -78,   -78,   -78,     0,
     -78,     0,     0,     0,     0,     0,     0,   -78,   -78,   -78,
       0,   -78,   -78,   259,   -78,   -78,   -78,   -78,   -78,   -78,
       0,     0,     0,   -78,     0,     0,   -78,     0,     0,     0,
       0,     0,   536,   368,   368,   368,   368,   368,   368,   368,
       0,     0,     0,     0,   259,   259,   259,   259,   561,   259,
     259,   257,   259,     0,   101,   315,   268,   269,   270,   271,
     315,     6,     0,     0,     0,   259,     0,     0,     7,     8,
       9,     0,   330,   331,   332,   333,   334,   335,   336,   337,
       0,     0,   102,     0,   272,     0,   109,   110,     0,     0,
       0,     0,   259,     0,   259,   338,     0,  -129,  -129,   257,
       0,   257,     0,     0,   315,   315,   315,   315,   604,   315,
     315,     0,   315,     0,     0,   315,     0,   144,     0,   148,
     150,   259,     0,   -56,   -56,   313,   -56,   -56,   -56,   -56,
       0,   -56,     0,     0,     0,     0,     0,     0,   -56,   -56,
     -56,     0,   -56,   -56,     0,   -56,   -56,   -56,   -56,   -56,
     -56,     0,     0,   259,   -56,   259,     0,   -56,     0,     0,
       0,     0,     0,     0,   368,   368,   368,   368,   642,   368,
     368,     0,   368,     0,     0,   315,     0,     0,     0,     0,
     -71,   259,   -71,   -71,   -71,   -71,     0,   -71,     0,     0,
       0,     0,     0,     0,   -71,   -71,   -71,     0,   -71,   -71,
       0,   -71,   -71,   -71,   -71,   -71,   -71,   366,     0,   366,
     -71,     0,     0,   -71,   -71,   313,     0,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,   -14,     0,   -14,   -14,   -14,
     -14,   315,   -14,     0,     0,     0,     0,     0,     0,   -14,
     -14,   -14,  -118,   -14,   -14,     0,   -14,   -14,   -14,   -14,
     -14,   -14,   257,     0,   257,   -14,   257,     0,   -14,   -14,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,   315,     0,   -72,   -72,     0,   -72,   -72,   -72,   -72,
       0,   -72,   173,    58,     0,   174,   257,     0,   -72,   -72,
     -72,     0,   -72,   -72,     0,   -72,   -72,   -72,   -72,   -72,
     -72,     0,   258,     0,   -72,     0,   257,   -72,     0,   315,
       0,     0,     0,     0,     0,   423,   257,   257,   257,   430,
     431,   257,   368,     0,   368,     0,     0,     0,     0,     0,
       0,     0,   342,     0,     2,     3,     4,   247,   368,     6,
     368,     0,   257,     0,     0,     0,     7,     8,     9,     0,
     258,     0,   258,   343,   344,   345,   718,   346,   347,     0,
       0,     0,    17,     0,     0,   348,   479,   313,   313,   313,
     486,   487,   313,     0,     0,   103,   314,   268,   269,   270,
     271,     0,     6,   259,     0,   259,     0,   259,     0,     7,
       8,     9,     0,   259,   257,   259,     0,   259,   455,  -104,
    -104,  -104,  -104,   456,   457,   272,   378,   379,   380,   381,
     382,   383,   384,   385,   539,   366,   366,   366,   546,   547,
     366,     0,  -104,  -104,     0,   257,   257,   257,   559,   386,
     563,   565,     0,   257,     0,   105,   313,   268,   269,   270,
     271,   313,     6,     0,     0,     0,   257,     0,     0,     7,
       8,     9,     0,     0,     0,     0,     0,     0,   367,     0,
     367,     0,     0,     0,     0,   272,   314,   107,     0,   268,
     269,   270,   271,   257,     6,   257,     0,     0,     0,     0,
       0,     7,     8,     9,     0,   313,   313,   313,   602,     0,
     606,   608,     0,   313,     0,     0,   313,   272,     0,     0,
       0,     0,   257,   258,     0,   258,     0,   258,   111,     0,
     268,   269,   270,   271,   119,     6,   248,   249,   250,   251,
       0,     6,     7,     8,     9,     0,     0,     0,     7,     8,
       9,     0,     0,     0,   257,     0,   257,   258,   272,     0,
       0,     0,     0,     0,   252,   366,   366,   366,   640,     0,
     644,   646,     0,   366,     0,     0,   313,   258,   279,   280,
     281,   282,   257,   284,   285,   286,   258,   258,   258,   258,
     258,   258,   258,     0,     0,     0,     0,     0,     0,   -71,
     -71,     0,   -71,   -71,   -71,   -71,     0,   -71,     0,     0,
       0,     0,     0,   258,   -71,   -71,   -71,     0,   -71,   -71,
       0,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,   256,
     -71,     0,   313,   -71,     0,     0,     0,   314,   314,   314,
     314,   314,   314,   314,     0,   342,     0,     2,     3,     4,
     247,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,   108,     0,   258,   343,   344,   345,   720,
     346,   347,   313,     0,     0,    17,     0,   256,   348,   256,
       0,     0,     0,     0,     0,   367,   367,   367,   367,   367,
     367,   367,     0,     0,   142,     0,   258,   258,   258,   258,
       0,   258,   258,   312,   258,     0,     0,   314,     0,     0,
     313,     0,   314,   330,   331,   332,   333,   258,   335,   336,
     337,     0,     0,   366,     0,   366,     0,     0,     0,     0,
       0,     0,     0,   137,     0,   268,   269,   270,   271,   366,
       6,   366,     0,     0,   258,     0,   258,     7,     8,     9,
       0,     0,     0,     0,     0,     0,   314,   314,   314,   314,
       0,   314,   314,   272,   314,     0,     0,   314,     0,     0,
       0,     0,     0,   258,     0,     0,   139,     0,   268,   269,
     270,   271,     0,     6,   257,   365,   257,   365,   257,     0,
       7,     8,     9,   312,   257,     0,   257,     0,   257,     0,
       0,     0,     0,     0,     0,   258,   272,   258,   330,   331,
     332,   333,   334,   335,   336,   337,   367,   367,   367,   367,
       0,   367,   367,     0,   367,     0,     0,   314,     0,     0,
     256,   338,   256,   258,   256,   -77,     0,   -77,   -77,   -77,
     -77,     0,   -77,     0,     0,     0,     0,     0,     0,   -77,
     -77,   -77,     0,   -77,   -77,     0,   -77,   -77,   -77,   -77,
     -77,   -77,     0,     0,   256,   -77,     0,     0,   -77,   -77,
       0,   141,     0,   268,   269,   270,   271,     0,     6,     0,
     255,     0,     0,   314,   256,     7,     8,     9,     0,     0,
       0,     0,     0,     0,   256,   256,   429,     0,     0,   256,
       0,   272,   143,     0,   268,   269,   270,   271,     0,     6,
       0,     0,   104,     0,     0,     0,     7,     8,     9,     0,
     256,     0,   145,   314,   268,   269,   270,   271,   255,     6,
     255,     0,   272,     0,     0,     0,     7,     8,     9,     0,
       0,     0,     0,     0,   140,   312,   312,   485,     0,     0,
     312,     0,   272,   147,   311,   268,   269,   270,   271,     0,
       6,   314,     0,     0,     0,     0,     0,     7,     8,     9,
       0,     0,   256,     0,   367,     0,   367,     0,     0,   378,
     379,   380,   381,   272,   383,   384,   385,     0,     0,     0,
     367,     0,   367,   365,   365,   545,     0,     0,   365,     0,
       0,     0,     0,   256,   256,   557,     0,     0,     0,     0,
       0,   256,     0,   149,   312,   268,   269,   270,   271,   312,
       6,     0,     0,     0,   256,     0,     0,     7,     8,     9,
       0,     0,     0,     0,     0,   258,   364,   258,   364,   258,
       0,     0,     0,   272,   311,   258,     0,   258,     0,   258,
       0,   256,   151,   256,   268,   269,   270,   271,     0,     6,
       0,     0,     0,   312,   312,   600,     7,     8,     9,     0,
       0,   312,     0,     0,   312,     0,     0,     0,     0,     0,
     256,   255,   272,   255,     0,   255,   153,     0,   268,   269,
     270,   271,   377,     6,   304,   305,   306,   307,     0,     6,
       7,     8,     9,     0,     0,     0,     7,     8,     9,     0,
       0,     0,   256,     0,   256,   255,   272,     0,     0,     0,
       0,     0,   308,   365,   365,   638,     0,     0,     0,     0,
       0,   365,   254,     0,   312,   255,    46,    47,    48,     0,
     256,    51,    52,    53,     0,   425,   255,     0,     0,     0,
     255,     0,     0,   327,     0,     2,     3,     4,   247,     0,
       6,     0,     0,     0,     0,   106,     0,     7,     8,     9,
       0,   255,     0,     0,   290,   291,   292,     0,   293,   294,
     254,     0,   254,    17,     0,     0,   295,   279,   280,   281,
     312,     0,   284,   285,   286,   138,   481,   311,   330,   331,
     332,   311,     0,   335,   336,   337,   310,     0,     0,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,   -32,     0,   -32,
     -32,   -32,   -32,   255,   -32,     0,     0,     0,     0,     0,
     312,   -32,   -32,   -32,  -119,   -32,   -32,   253,   -32,   -32,
     -32,   -32,   -32,   -32,   541,   364,     0,   -32,     0,   364,
     -32,   -32,     0,     0,   255,   555,     0,     0,     0,     0,
       0,     0,   255,     0,     0,   311,     0,     0,   312,     0,
     311,     0,     0,     0,     0,   255,     0,     0,   112,     0,
       0,   365,     0,   365,     0,   253,     0,   253,   363,     0,
     363,     0,     0,     0,     0,     0,   310,   365,     0,   365,
       0,     0,   255,     0,   255,     0,     0,     0,   154,     0,
       0,   309,     0,     0,   311,   598,     0,     0,     0,     0,
       0,     0,   311,     0,     0,   311,     0,  -122,  -122,  -122,
    -122,   255,  -122,   254,     0,   254,     0,   254,     0,  -122,
    -122,  -122,   256,     0,   256,     0,   256,     0,  -124,  -124,
    -124,  -124,   256,  -124,   256,  -122,   256,     0,     0,     0,
    -124,  -124,  -124,   255,     0,   255,     0,   254,     0,     0,
       0,     0,     0,     0,   364,   636,  -124,     0,     0,     0,
       0,     0,   364,     0,     0,   311,     0,   254,     0,     0,
       0,   255,     0,   362,     0,   362,     0,     0,   427,     0,
       0,   309,   254,   -13,     0,   -13,   -13,   -13,   -13,     0,
     -13,     0,     0,     0,     0,     0,     0,   -13,   -13,   -13,
       0,   -13,   -13,   254,   -13,   -13,   -13,   -13,   -13,   -13,
       0,     0,     0,   -13,     0,     0,   -13,   -13,   253,     0,
     253,   311,   253,   -50,     0,   -50,   -50,   -50,   -50,   483,
     -50,     0,     0,   310,     0,     0,     0,   -50,   -50,   -50,
       0,   -50,   -50,     0,   -50,   -50,   -50,   -50,   -50,   -50,
       0,     0,   253,   -50,     0,   254,   -50,   -50,     0,     0,
     389,   311,   248,   249,   250,   251,     0,     6,     0,     0,
       0,     0,   253,     0,     7,     8,     9,   543,   378,   379,
     380,   363,     0,   383,   384,   385,   553,   433,     0,     0,
     252,     0,     0,     0,   254,     0,     0,   310,     0,   311,
       0,     0,   310,     0,     0,     0,     0,   254,   253,     0,
       0,     0,   364,     0,   364,     0,     0,   403,     0,   248,
     249,   250,   251,     0,     6,     0,     0,     0,   364,     0,
     364,     7,     8,     9,   254,     0,   254,   419,   489,   408,
     409,   410,   411,     0,     6,     0,   596,   252,     0,     0,
       0,     7,     8,     9,   310,     0,     0,   310,     0,     0,
     253,     0,     0,   254,     0,     0,     0,   412,     0,     0,
       0,     0,     0,   255,     0,   255,     0,   255,     0,     0,
       0,     0,     0,   255,     0,   255,   549,   255,     0,   422,
       0,   408,   409,   410,   411,   254,     6,   254,     0,   569,
       0,     0,   309,     7,     8,     9,   634,   309,     2,     3,
       4,   247,   253,     6,   363,     0,     0,   310,     0,   412,
       7,     8,     9,   254,     0,     0,     0,   -77,   -77,     0,
     -77,   -77,   -77,   -77,     0,   -77,    17,     0,     0,   253,
       0,   253,   -77,   -77,   -77,     0,   -77,   -77,     0,   -77,
     -77,   -77,   -77,   -77,   -77,     0,     0,     0,   -77,   612,
       0,   -77,   309,     0,     0,     0,     0,     0,   253,     0,
       0,     0,     0,   310,     0,     0,   424,     0,   408,   409,
     410,   411,    77,     6,     2,     3,     4,   247,     0,     6,
       7,     8,     9,     0,     0,     0,     7,     8,     9,     0,
     253,     0,   253,    12,    13,    14,   412,    15,    16,     0,
       0,     0,    17,   310,     0,    18,     0,     0,     0,   650,
       0,     0,   309,     0,     0,     0,    -3,     1,   253,     2,
       3,     4,     5,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,    10,    11,     0,    12,    13,
      14,   310,    15,    16,     0,     0,     0,    17,     0,     0,
      18,     0,     0,     0,   363,     0,   363,     0,   -32,   -32,
       0,   -32,   -32,   -32,   -32,     0,   -32,     0,   309,     0,
     363,     0,   363,   -32,   -32,   -32,     0,   -32,   -32,     0,
     -32,   -32,   -32,   -32,   -32,   -32,     0,     0,     0,   -32,
       0,   426,   -32,   408,   409,   410,   411,     0,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     9,   309,     0,
       0,     0,     0,     0,     0,   254,     0,   254,     0,   254,
       0,   412,     0,     0,     0,   254,     0,   254,   428,   254,
     408,   409,   410,   411,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,   309,     0,   -51,     0,
     -51,   -51,   -51,   -51,     0,   -51,     0,     0,   412,   362,
       0,   362,   -51,   -51,   -51,     0,   -51,   -51,     0,   -51,
     -51,   -51,   -51,   -51,   -51,   362,     0,   362,   -51,     0,
       0,   -51,   -51,   -46,     0,   -46,   -46,   -46,   -46,     0,
     -46,     0,     0,     0,     0,     0,     0,   -46,   -46,   -46,
       0,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,
       0,     0,     0,   -46,     0,     0,   -46,   -46,     0,     0,
     253,     0,   253,     0,   253,     0,     0,     0,     0,     0,
     253,     0,   253,   -49,   253,   -49,   -49,   -49,   -49,     0,
     -49,     0,     0,     0,     0,     0,     0,   -49,   -49,   -49,
       0,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,     0,   -49,     0,     0,   -49,   -49,   -52,     0,
     -52,   -52,   -52,   -52,     0,   -52,     0,     0,     0,     0,
       0,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,   -52,
     -52,   -52,   -52,   -52,   -52,     0,     0,     0,   -52,     0,
       0,   -52,   -52,   -47,     0,   -47,   -47,   -47,   -47,     0,
     -47,     0,     0,     0,     0,     0,     0,   -47,   -47,   -47,
       0,   -47,   -47,     0,   -47,   -47,   -47,   -47,   -47,   -47,
       0,     0,     0,   -47,     0,     0,   -47,   -47,   -53,     0,
     -53,   -53,   -53,   -53,     0,   -53,     0,     0,     0,     0,
       0,     0,   -53,   -53,   -53,     0,   -53,   -53,     0,   -53,
     -53,   -53,   -53,   -53,   -53,     0,     0,     0,   -53,     0,
       0,   -53,   -53,   -48,     0,   -48,   -48,   -48,   -48,     0,
     -48,     0,     0,     0,     0,     0,     0,   -48,   -48,   -48,
       0,   -48,   -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,
       0,     0,     0,   -48,     0,     0,   -48,   -48,   -65,     0,
     -65,   -65,   -65,   -65,     0,   -65,     0,     0,     0,     0,
       0,     0,   -65,   -65,   -65,     0,   -65,   -65,     0,   -65,
     -65,   -65,   727,   -65,   -65,     0,     0,     0,   -65,     0,
       0,   -65,   -65,   -62,     0,   -62,   -62,   -62,   -62,     0,
     -62,     0,     0,     0,     0,     0,     0,   -62,   -62,   -62,
       0,   -62,   -62,     0,   -62,   -62,   -62,   729,   -62,   -62,
       0,     0,     0,   -62,     0,     0,   -62,   -62,   -50,   -50,
       0,   -50,   -50,   -50,   -50,     0,   -50,     0,     0,     0,
       0,     0,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,
     -50,   -50,   -50,   -50,   -50,   -50,     0,     0,     0,   -50,
     -51,   -51,   -50,   -51,   -51,   -51,   -51,     0,   -51,     0,
       0,     0,     0,     0,     0,   -51,   -51,   -51,     0,   -51,
     -51,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,
       0,   -51,   -46,   -46,   -51,   -46,   -46,   -46,   -46,     0,
     -46,     0,     0,     0,     0,     0,     0,   -46,   -46,   -46,
       0,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,
       0,     0,     0,   -46,   -49,   -49,   -46,   -49,   -49,   -49,
     -49,     0,   -49,     0,     0,     0,     0,     0,     0,   -49,
     -49,   -49,     0,   -49,   -49,     0,   -49,   -49,   -49,   -49,
     -49,   -49,     0,     0,     0,   -49,   -52,   -52,   -49,   -52,
     -52,   -52,   -52,     0,   -52,     0,     0,     0,     0,     0,
       0,   -52,   -52,   -52,     0,   -52,   -52,     0,   -52,   -52,
     -52,   -52,   -52,   -52,     0,     0,     0,   -52,   -47,   -47,
     -52,   -47,   -47,   -47,   -47,     0,   -47,     0,     0,     0,
       0,     0,     0,   -47,   -47,   -47,     0,   -47,   -47,     0,
     -47,   -47,   -47,   -47,   -47,   -47,     0,     0,     0,   -47,
     -53,   -53,   -47,   -53,   -53,   -53,   -53,     0,   -53,     0,
       0,     0,     0,     0,     0,   -53,   -53,   -53,     0,   -53,
     -53,     0,   -53,   -53,   -53,   -53,   -53,   -53,     0,     0,
       0,   -53,   -48,   -48,   -53,   -48,   -48,   -48,   -48,     0,
     -48,     0,     0,     0,     0,     0,     0,   -48,   -48,   -48,
       0,   -48,   -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,
       0,     0,     0,   -48,   -65,   -65,   -48,   -65,   -65,   -65,
     -65,     0,   -65,     0,     0,     0,     0,     0,     0,   -65,
     -65,   -65,     0,   -65,   -65,     0,   -65,   -65,   -65,   737,
     -65,   -65,     0,     0,     0,   -65,   -62,   -62,   -65,   -62,
     -62,   -62,   -62,     0,   -62,     0,     0,     0,     0,     0,
       0,   -62,   -62,   -62,     0,   -62,   -62,     0,   -62,   -62,
     -62,   739,   -62,   -62,     0,     0,     0,   -62,     0,   -67,
     -62,   -67,   -67,   -67,   -67,     0,   -67,     0,     0,     0,
       0,     0,     0,   -67,   -67,   -67,     0,   -67,   -67,     0,
     -67,   -67,   -67,   -67,   -67,   -67,     0,     0,     0,   -67,
       0,     0,   -67,   -67,   -64,     0,   -64,   -64,   -64,   -64,
       0,   -64,     0,     0,     0,     0,     0,     0,   -64,   -64,
     -64,     0,   -64,   -64,     0,   -64,   -64,   -64,   -64,   -64,
     -64,     0,     0,     0,   -64,     0,     0,   -64,   -64,   -67,
     -67,     0,   -67,   -67,   -67,   -67,     0,   -67,     0,     0,
       0,     0,     0,     0,   -67,   -67,   -67,     0,   -67,   -67,
       0,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,     0,
     -67,   -64,   -64,   -67,   -64,   -64,   -64,   -64,     0,   -64,
       0,     0,     0,     0,     0,     0,   -64,   -64,   -64,     0,
     -64,   -64,     0,   -64,   -64,   -64,   -64,   -64,   -64,     0,
       0,     0,   -64,     0,   -66,   -64,   -66,   -66,   -66,   -66,
       0,   -66,     0,     0,     0,     0,     0,     0,   -66,   -66,
     -66,     0,   -66,   -66,     0,   -66,   -66,   -66,   -66,   -66,
     -66,     0,     0,     0,   -66,     0,     0,   -66,   -66,   -63,
       0,   -63,   -63,   -63,   -63,     0,   -63,     0,     0,     0,
       0,     0,     0,   -63,   -63,   -63,     0,   -63,   -63,     0,
     -63,   -63,   -63,   -63,   -63,   -63,     0,     0,     0,   -63,
       0,     0,   -63,   -63,   -80,     0,   -80,   -80,   -80,   -80,
       0,   -80,     0,     0,     0,     0,     0,     0,   -80,   -80,
     -80,     0,   -80,   -80,     0,   -80,   -80,   -80,   -80,   -80,
     -80,     0,     0,     0,   -80,     0,     0,   -80,   -80,   -81,
       0,   -81,   -81,   -81,   -81,     0,   -81,     0,     0,     0,
       0,     0,     0,   -81,   -81,   -81,     0,   -81,   -81,     0,
     -81,   -81,   -81,   -81,   -81,   -81,     0,     0,     0,   -81,
       0,     0,   -81,   -81,   -79,     0,   -79,   -79,   -79,   -79,
       0,   -79,     0,     0,     0,     0,     0,     0,   -79,   -79,
     -79,     0,   -79,   -79,     0,   -79,   -79,   -79,   -79,   -79,
     -79,     0,     0,     0,   -79,     0,     0,   -79,   -79,   -66,
     -66,     0,   -66,   -66,   -66,   -66,     0,   -66,     0,     0,
       0,     0,     0,     0,   -66,   -66,   -66,     0,   -66,   -66,
       0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,
     -66,   -63,   -63,   -66,   -63,   -63,   -63,   -63,     0,   -63,
       0,     0,     0,     0,     0,     0,   -63,   -63,   -63,     0,
     -63,   -63,     0,   -63,   -63,   -63,   -63,   -63,   -63,     0,
       0,     0,   -63,   -80,   -80,   -63,   -80,   -80,   -80,   -80,
       0,   -80,     0,     0,     0,     0,     0,     0,   -80,   -80,
     -80,     0,   -80,   -80,     0,   -80,   -80,   -80,   -80,   -80,
     -80,     0,     0,     0,   -80,   -81,   -81,   -80,   -81,   -81,
     -81,   -81,     0,   -81,     0,     0,     0,     0,     0,     0,
     -81,   -81,   -81,     0,   -81,   -81,     0,   -81,   -81,   -81,
     -81,   -81,   -81,     0,     0,     0,   -81,   -79,   -79,   -81,
     -79,   -79,   -79,   -79,     0,   -79,     0,     0,     0,     0,
       0,     0,   -79,   -79,   -79,     0,   -79,   -79,     0,   -79,
     -79,   -79,   -79,   -79,   -79,     0,     0,     0,   -79,     0,
     -74,   -79,   -74,   -74,   -74,   -74,     0,   -74,     0,     0,
       0,     0,     0,     0,   -74,   -74,   -74,     0,   -74,   -74,
       0,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,     0,
     -74,     0,     0,   -74,   -74,   -75,     0,   -75,   -75,   -75,
     -75,     0,   -75,     0,     0,     0,     0,     0,     0,   -75,
     -75,   -75,     0,   -75,   -75,     0,   -75,   -75,   -75,   -75,
     -75,   -75,     0,     0,     0,   -75,     0,     0,   -75,   -75,
     -76,     0,   -76,   -76,   -76,   -76,     0,   -76,     0,     0,
       0,     0,     0,     0,   -76,   -76,   -76,     0,   -76,   -76,
       0,   -76,   -76,   -76,   -76,   -76,   -76,     0,     0,     0,
     -76,     0,     0,   -76,   -76,   -73,     0,   -73,   -73,   -73,
     -73,     0,   -73,     0,     0,     0,     0,     0,     0,   -73,
     -73,   -73,     0,   -73,   -73,     0,   -73,   -73,   -73,   -73,
     -73,   -73,     0,     0,     0,   -73,     0,     0,   -73,   -73,
     -74,   -74,     0,   -74,   -74,   -74,   -74,     0,   -74,     0,
       0,     0,     0,     0,     0,   -74,   -74,   -74,     0,   -74,
     -74,     0,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,
       0,   -74,   -75,   -75,   -74,   -75,   -75,   -75,   -75,     0,
     -75,     0,     0,     0,     0,     0,     0,   -75,   -75,   -75,
       0,   -75,   -75,     0,   -75,   -75,   -75,   -75,   -75,   -75,
       0,     0,     0,   -75,   -76,   -76,   -75,   -76,   -76,   -76,
     -76,     0,   -76,     0,     0,     0,     0,     0,     0,   -76,
     -76,   -76,     0,   -76,   -76,     0,   -76,   -76,   -76,   -76,
     -76,   -76,     0,     0,     0,   -76,   -73,   -73,   -76,   -73,
     -73,   -73,   -73,     0,   -73,     0,     0,     0,     0,     0,
       0,   -73,   -73,   -73,     0,   -73,   -73,     0,   -73,   -73,
     -73,   -73,   -73,   -73,     0,     0,     0,   -73,    -2,    77,
     -73,     2,     3,     4,     5,     0,     6,     0,     0,     0,
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
      -7,    -7,     0,     0,     0,    -7,   -41,   -41,    -7,   -41,
     -41,   -41,   -41,     0,   -41,     0,     0,     0,     0,     0,
       0,   -41,   -41,   -41,     0,   -41,   -41,     0,   -41,   -41,
     -41,     0,   -41,   -41,     0,     0,     0,   -41,    -9,    -9,
     -41,    -9,    -9,    -9,    -9,     0,    -9,     0,     0,     0,
       0,     0,     0,    -9,    -9,    -9,     0,    -9,    -9,     0,
      -9,    -9,    -9,     0,    -9,    -9,     0,     0,     0,    -9,
     -45,   -45,    -9,   -45,   -45,   -45,   -45,     0,   -45,     0,
       0,     0,     0,     0,     0,   -45,   -45,   -45,     0,   -45,
     -45,     0,   -45,   -45,   -45,     0,   -45,   -45,     0,     0,
       0,   -45,   -40,   -40,   -45,   -40,   -40,   -40,   -40,     0,
     -40,     0,     0,     0,     0,     0,     0,   -40,   -40,   -40,
       0,   -40,   -40,     0,   -40,   -40,   -40,     0,   -40,   -40,
       0,     0,     0,   -40,   -42,   -42,   -40,   -42,   -42,   -42,
     -42,     0,   -42,     0,     0,     0,     0,     0,     0,   -42,
     -42,   -42,     0,   -42,   -42,     0,   -42,   -42,   -42,     0,
     -42,   -42,     0,     0,     0,   -42,   -43,   -43,   -42,   -43,
     -43,   -43,   -43,     0,   -43,     0,     0,     0,     0,     0,
       0,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,
     -43,     0,   -43,   -43,     0,     0,     0,   -43,   -44,   -44,
     -43,   -44,   -44,   -44,   -44,     0,   -44,     0,     0,     0,
       0,     0,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,
     -44,   -44,   -44,     0,   -44,   -44,     0,     0,     0,   -44,
     -60,   -60,   -44,   -60,   -60,   -60,   -60,     0,   -60,     0,
       0,     0,     0,     0,     0,   -60,   -60,   -60,     0,   -60,
     -60,     0,   -60,   -60,   -60,     0,   -60,   -60,     0,     0,
       0,   -60,   -59,   -59,   -60,   -59,   -59,   -59,   -59,     0,
     -59,     0,     0,     0,     0,     0,     0,   -59,   -59,   -59,
       0,   -59,   -59,     0,   -59,   -59,   -59,     0,   -59,   -59,
       0,     0,     0,   -59,   -61,   -61,   -59,   -61,   -61,   -61,
     -61,     0,   -61,     0,     0,     0,     0,     0,     0,   -61,
     -61,   -61,     0,   -61,   -61,     0,   -61,   -61,   -61,     0,
     -61,   -61,     0,     0,     0,   -61,   -57,   -57,   -61,   -57,
     -57,   -57,   -57,     0,   -57,     0,     0,     0,     0,     0,
       0,   -57,   -57,   -57,     0,   -57,   -57,     0,   -57,   -57,
     -57,     0,   -57,   -57,     0,     0,     0,   -57,   -58,   -58,
     -57,   -58,   -58,   -58,   -58,     0,   -58,     0,     0,     0,
       0,     0,     0,   -58,   -58,   -58,     0,   -58,   -58,     0,
     -58,   -58,   -58,     0,   -58,   -58,     0,     0,     0,   -58,
     -55,   -55,   -58,   -55,   -55,   -55,   -55,     0,   -55,     0,
       0,     0,     0,     0,     0,   -55,   -55,   -55,     0,   -55,
     -55,     0,   -55,   -55,   -55,     0,   -55,   -55,     0,     0,
       0,   -55,   -54,   -54,   -55,   -54,   -54,   -54,   -54,     0,
     -54,     0,     0,     0,     0,     0,     0,   -54,   -54,   -54,
       0,   -54,   -54,     0,   -54,   -54,   -54,     0,   -54,   -54,
       0,     0,     0,   -54,   -68,   -68,   -54,   -68,   -68,   -68,
     -68,     0,   -68,     0,     0,     0,     0,     0,     0,   -68,
     -68,   -68,     0,   -68,   -68,     0,   -68,   -68,   -68,     0,
     -68,   -68,     0,     0,     0,   -68,   -78,   -78,   -68,   -78,
     -78,   -78,   -78,     0,   -78,     0,     0,     0,     0,     0,
       0,   -78,   -78,   -78,     0,   -78,   -78,     0,   -78,   -78,
     -78,     0,   -78,   -78,     0,     0,     0,   -78,    -5,    -5,
     -78,    -5,    -5,    -5,    -5,     0,    -5,     0,     0,     0,
       0,     0,     0,    -5,    -5,    -5,     0,    -5,    -5,     0,
      -5,    -5,    -5,     0,    -5,    -5,     0,     0,     0,    -5,
     -56,   -56,    -5,   -56,   -56,   -56,   -56,     0,   -56,     0,
       0,     0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,
     -56,     0,   -56,   -56,   -56,     0,   -56,   -56,     0,     0,
       0,   -56,   -11,   -11,   -56,   -11,   -11,   -11,   -11,     0,
     -11,     0,     0,     0,     0,     0,     0,   -11,   -11,   -11,
       0,   -11,   -11,     0,   -11,   -11,   -11,     0,   -11,   -11,
       0,     0,     0,   -11,   -72,   -72,   -11,   -72,   -72,   -72,
     -72,     0,   -72,     0,     0,     0,     0,     0,     0,   -72,
     -72,   -72,     0,   -72,   -72,     0,   -72,   -72,   -72,     0,
     -72,   -72,     0,     0,     0,   -72,   -71,   -71,   -72,   -71,
     -71,   -71,   -71,     0,   -71,     0,     0,     0,     0,     0,
       0,   -71,   -71,   -71,     0,   -71,   -71,     0,   -71,   -71,
     -71,     0,   -71,   -71,     0,     0,     0,   -71,   -14,   -14,
     -71,   -14,   -14,   -14,   -14,     0,   -14,     0,     0,     0,
       0,     0,     0,   -14,   -14,   -14,     0,   -14,   -14,     0,
     -14,   -14,   -14,     0,   -14,   -14,     0,     0,     0,   -14,
     -16,   -16,   -14,   -16,   -16,   -16,   -16,     0,   -16,     0,
       0,     0,     0,     0,     0,   -16,   -16,   -16,     0,   -16,
     -16,     0,   -16,   -16,   -16,     0,   -16,   -16,     0,     0,
       0,   -16,   -10,   -10,   -16,   -10,   -10,   -10,   -10,     0,
     -10,     0,     0,     0,     0,     0,     0,   -10,   -10,   -10,
       0,   -10,   -10,     0,   -10,   -10,   -10,     0,   -10,   -10,
       0,     0,     0,   -10,   -77,   -77,   -10,   -77,   -77,   -77,
     -77,     0,   -77,     0,     0,     0,     0,     0,     0,   -77,
     -77,   -77,     0,   -77,   -77,     0,   -77,   -77,   -77,     0,
     -77,   -77,     0,     0,     0,   -77,   -32,   -32,   -77,   -32,
     -32,   -32,   -32,     0,   -32,     0,     0,     0,     0,     0,
       0,   -32,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,
     -32,     0,   -32,   -32,     0,     0,     0,   -32,   -13,   -13,
     -32,   -13,   -13,   -13,   -13,     0,   -13,     0,     0,     0,
       0,     0,     0,   -13,   -13,   -13,     0,   -13,   -13,     0,
     -13,   -13,   -13,     0,   -13,   -13,     0,     0,     0,   -13,
     -12,   -12,   -13,   -12,   -12,   -12,   -12,     0,   -12,     0,
       0,     0,     0,     0,     0,   -12,   -12,   -12,     0,   -12,
     -12,     0,   -12,   -12,   -12,     0,   -12,   -12,     0,     0,
       0,   -12,   -50,   -50,   -12,   -50,   -50,   -50,   -50,     0,
     -50,     0,     0,     0,     0,     0,     0,   -50,   -50,   -50,
       0,   -50,   -50,     0,   -50,   -50,   -50,     0,   -50,   -50,
       0,     0,     0,   -50,   -51,   -51,   -50,   -51,   -51,   -51,
     -51,     0,   -51,     0,     0,     0,     0,     0,     0,   -51,
     -51,   -51,     0,   -51,   -51,     0,   -51,   -51,   -51,     0,
     -51,   -51,     0,     0,     0,   -51,   -46,   -46,   -51,   -46,
     -46,   -46,   -46,     0,   -46,     0,     0,     0,     0,     0,
       0,   -46,   -46,   -46,     0,   -46,   -46,     0,   -46,   -46,
     -46,     0,   -46,   -46,     0,     0,     0,   -46,   -49,   -49,
     -46,   -49,   -49,   -49,   -49,     0,   -49,     0,     0,     0,
       0,     0,     0,   -49,   -49,   -49,     0,   -49,   -49,     0,
     -49,   -49,   -49,     0,   -49,   -49,     0,     0,     0,   -49,
     -52,   -52,   -49,   -52,   -52,   -52,   -52,     0,   -52,     0,
       0,     0,     0,     0,     0,   -52,   -52,   -52,     0,   -52,
     -52,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,     0,
       0,   -52,   -47,   -47,   -52,   -47,   -47,   -47,   -47,     0,
     -47,     0,     0,     0,     0,     0,     0,   -47,   -47,   -47,
       0,   -47,   -47,     0,   -47,   -47,   -47,     0,   -47,   -47,
       0,     0,     0,   -47,   -53,   -53,   -47,   -53,   -53,   -53,
     -53,     0,   -53,     0,     0,     0,     0,     0,     0,   -53,
     -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,     0,
     -53,   -53,     0,     0,     0,   -53,   -48,   -48,   -53,   -48,
     -48,   -48,   -48,     0,   -48,     0,     0,     0,     0,     0,
       0,   -48,   -48,   -48,     0,   -48,   -48,     0,   -48,   -48,
     -48,     0,   -48,   -48,     0,     0,     0,   -48,   -67,   -67,
     -48,   -67,   -67,   -67,   -67,     0,   -67,     0,     0,     0,
       0,     0,     0,   -67,   -67,   -67,     0,   -67,   -67,     0,
     -67,   -67,   -67,     0,   -67,   -67,     0,     0,     0,   -67,
     -64,   -64,   -67,   -64,   -64,   -64,   -64,     0,   -64,     0,
       0,     0,     0,     0,     0,   -64,   -64,   -64,     0,   -64,
     -64,     0,   -64,   -64,   -64,     0,   -64,   -64,     0,     0,
       0,   -64,   -66,   -66,   -64,   -66,   -66,   -66,   -66,     0,
     -66,     0,     0,     0,     0,     0,     0,   -66,   -66,   -66,
       0,   -66,   -66,     0,   -66,   -66,   -66,     0,   -66,   -66,
       0,     0,     0,   -66,   -63,   -63,   -66,   -63,   -63,   -63,
     -63,     0,   -63,     0,     0,     0,     0,     0,     0,   -63,
     -63,   -63,     0,   -63,   -63,     0,   -63,   -63,   -63,     0,
     -63,   -63,     0,     0,     0,   -63,   -80,   -80,   -63,   -80,
     -80,   -80,   -80,     0,   -80,     0,     0,     0,     0,     0,
       0,   -80,   -80,   -80,     0,   -80,   -80,     0,   -80,   -80,
     -80,     0,   -80,   -80,     0,     0,     0,   -80,   -81,   -81,
     -80,   -81,   -81,   -81,   -81,     0,   -81,     0,     0,     0,
       0,     0,     0,   -81,   -81,   -81,     0,   -81,   -81,     0,
     -81,   -81,   -81,     0,   -81,   -81,     0,     0,     0,   -81,
     -79,   -79,   -81,   -79,   -79,   -79,   -79,     0,   -79,     0,
       0,     0,     0,     0,     0,   -79,   -79,   -79,     0,   -79,
     -79,     0,   -79,   -79,   -79,     0,   -79,   -79,     0,     0,
       0,   -79,   -22,   -22,   -79,   -22,   -22,   -22,   -22,     0,
     -22,     0,     0,     0,     0,     0,     0,   -22,   -22,   -22,
       0,   -22,   -22,     0,   -22,   -22,   -22,     0,   -22,   -22,
       0,     0,     0,   -22,   -19,   -19,   -22,   -19,   -19,   -19,
     -19,     0,   -19,     0,     0,     0,     0,     0,     0,   -19,
     -19,   -19,     0,   -19,   -19,     0,   -19,   -19,   -19,     0,
     -19,   -19,     0,     0,     0,   -19,   -74,   -74,   -19,   -74,
     -74,   -74,   -74,     0,   -74,     0,     0,     0,     0,     0,
       0,   -74,   -74,   -74,     0,   -74,   -74,     0,   -74,   -74,
     -74,     0,   -74,   -74,     0,     0,     0,   -74,   -75,   -75,
     -74,   -75,   -75,   -75,   -75,     0,   -75,     0,     0,     0,
       0,     0,     0,   -75,   -75,   -75,     0,   -75,   -75,     0,
     -75,   -75,   -75,     0,   -75,   -75,     0,     0,     0,   -75,
     -76,   -76,   -75,   -76,   -76,   -76,   -76,     0,   -76,     0,
       0,     0,     0,     0,     0,   -76,   -76,   -76,     0,   -76,
     -76,     0,   -76,   -76,   -76,     0,   -76,   -76,     0,     0,
       0,   -76,   -73,   -73,   -76,   -73,   -73,   -73,   -73,     0,
     -73,     0,     0,     0,     0,     0,     0,   -73,   -73,   -73,
       0,   -73,   -73,     0,   -73,   -73,   -73,     0,   -73,   -73,
       0,     0,     0,   -73,     0,   342,   -73,     2,     3,     4,
     247,     0,     6,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,   343,   344,   345,     0,
     346,   347,     0,     0,     0,    17,     0,   432,   348,   408,
     409,   410,   411,   444,     6,     2,     3,     4,   247,     0,
       6,     7,     8,     9,     0,     0,     0,     7,     8,     9,
       0,   449,     0,   248,   249,   250,   251,   412,     6,     0,
       0,     0,     0,    17,     0,     7,     8,     9,   475,     0,
     464,   465,   466,   467,     0,     6,     0,     0,     0,     0,
       0,   252,     7,     8,     9,   478,     0,   464,   465,   466,
     467,     0,     6,     0,     0,     0,     0,     0,   468,     7,
       8,     9,   480,     0,   464,   465,   466,   467,     0,     6,
       0,     0,     0,     0,     0,   468,     7,     8,     9,   482,
       0,   464,   465,   466,   467,     0,     6,     0,     0,     0,
       0,     0,   468,     7,     8,     9,   484,     0,   464,   465,
     466,   467,     0,     6,     0,     0,     0,     0,     0,   468,
       7,     8,     9,   488,     0,   464,   465,   466,   467,     0,
       6,     0,     0,     0,     0,     0,   468,     7,     8,     9,
     505,     0,     2,     3,     4,   247,     0,     6,     0,     0,
       0,     0,     0,   468,     7,     8,     9,   509,     0,   248,
     249,   250,   251,     0,     6,     0,     0,     0,     0,     0,
      17,     7,     8,     9,   535,     0,   524,   525,   526,   527,
       0,     6,     0,     0,     0,     0,     0,   252,     7,     8,
       9,   538,     0,   524,   525,   526,   527,     0,     6,     0,
       0,     0,     0,     0,   528,     7,     8,     9,   540,     0,
     524,   525,   526,   527,     0,     6,     0,     0,     0,     0,
       0,   528,     7,     8,     9,   542,     0,   524,   525,   526,
     527,     0,     6,     0,     0,     0,     0,     0,   528,     7,
       8,     9,   544,     0,   524,   525,   526,   527,     0,     6,
       0,     0,     0,     0,     0,   528,     7,     8,     9,   548,
       0,   524,   525,   526,   527,     0,     6,     0,     0,     0,
       0,     0,   528,     7,     8,     9,   552,     0,   408,   409,
     410,   411,     0,     6,     0,     0,     0,     0,     0,   528,
       7,     8,     9,   554,     0,   408,   409,   410,   411,     0,
       6,     0,     0,     0,     0,     0,   412,     7,     8,     9,
     556,     0,   408,   409,   410,   411,     0,     6,     0,     0,
       0,     0,     0,   412,     7,     8,     9,   558,     0,   408,
     409,   410,   411,     0,     6,     0,     0,     0,     0,     0,
     412,     7,     8,     9,   560,     0,   408,   409,   410,   411,
       0,     6,     0,     0,     0,     0,     0,   412,     7,     8,
       9,   562,     0,   408,   409,   410,   411,     0,     6,     0,
       0,     0,     0,     0,   412,     7,     8,     9,   564,     0,
     408,   409,   410,   411,     0,     6,     0,     0,     0,     0,
       0,   412,     7,     8,     9,   566,     0,   408,   409,   410,
     411,     0,     6,     0,     0,     0,     0,     0,   412,     7,
       8,     9,   568,     0,   408,   409,   410,   411,     0,     6,
       0,     0,     0,     0,     0,   412,     7,     8,     9,   574,
       0,   248,   249,   250,   251,     0,     6,     0,     0,     0,
       0,     0,   412,     7,     8,     9,   584,     0,   248,   249,
     250,   251,     0,     6,     0,     0,     0,     0,     0,   252,
       7,     8,     9,   595,     0,   464,   465,   466,   467,     0,
       6,     0,     0,     0,     0,     0,   252,     7,     8,     9,
     597,     0,   464,   465,   466,   467,     0,     6,     0,     0,
       0,     0,     0,   468,     7,     8,     9,   599,     0,   464,
     465,   466,   467,     0,     6,     0,     0,     0,     0,     0,
     468,     7,     8,     9,   601,     0,   464,   465,   466,   467,
       0,     6,     0,     0,     0,     0,     0,   468,     7,     8,
       9,   603,     0,   464,   465,   466,   467,     0,     6,     0,
       0,     0,     0,     0,   468,     7,     8,     9,   605,     0,
     464,   465,   466,   467,     0,     6,     0,     0,     0,     0,
       0,   468,     7,     8,     9,   607,     0,   464,   465,   466,
     467,     0,     6,     0,     0,     0,     0,     0,   468,     7,
       8,     9,   609,     0,   464,   465,   466,   467,     0,     6,
       0,     0,     0,     0,     0,   468,     7,     8,     9,   611,
       0,   464,   465,   466,   467,     0,     6,     0,     0,     0,
       0,     0,   468,     7,     8,     9,   614,     0,   248,   249,
     250,   251,     0,     6,     0,     0,     0,     0,     0,   468,
       7,     8,     9,   624,     0,   248,   249,   250,   251,     0,
       6,     0,     0,     0,     0,     0,   252,     7,     8,     9,
     633,     0,   524,   525,   526,   527,     0,     6,     0,     0,
       0,     0,     0,   252,     7,     8,     9,   635,     0,   524,
     525,   526,   527,     0,     6,     0,     0,     0,     0,     0,
     528,     7,     8,     9,   637,     0,   524,   525,   526,   527,
       0,     6,     0,     0,     0,     0,     0,   528,     7,     8,
       9,   639,     0,   524,   525,   526,   527,     0,     6,     0,
       0,     0,     0,     0,   528,     7,     8,     9,   641,     0,
     524,   525,   526,   527,     0,     6,     0,     0,     0,     0,
       0,   528,     7,     8,     9,   643,     0,   524,   525,   526,
     527,     0,     6,     0,     0,     0,     0,     0,   528,     7,
       8,     9,   645,     0,   524,   525,   526,   527,     0,     6,
       0,     0,     0,     0,     0,   528,     7,     8,     9,   647,
       0,   524,   525,   526,   527,     0,     6,     0,     0,     0,
       0,     0,   528,     7,     8,     9,   649,     0,   524,   525,
     526,   527,     0,     6,     0,     0,     0,     0,     0,   528,
       7,     8,     9,   652,     0,   248,   249,   250,   251,     0,
       6,     0,     0,     0,     0,     0,   528,     7,     8,     9,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,   252,     0,     0,     0,   322,   176,   323,
     324,     0,   325,    58,     0,     0,     0,     0,   326,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,     0,
       0,     0,   268,   269,   270,   271,    54,     6,    55,    56,
       0,    57,    58,     0,     7,     8,     9,    59,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
     272,   248,   249,   250,   251,   322,     6,   323,   324,     0,
     325,    58,     0,     7,     8,     9,   326,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,   252,
     408,   409,   410,   411,   492,     6,   493,   494,     0,   495,
      58,     0,     7,     8,     9,   496,     0,   304,   305,   306,
     307,     0,     6,     0,     0,     0,     0,     0,   412,     7,
       8,     9,     0,     0,   464,   465,   466,   467,     0,     6,
       0,     0,     0,     0,     0,   308,     7,     8,     9,     0,
       0,   356,   357,   358,   359,     0,     6,     0,     0,     0,
       0,     0,   468,     7,     8,     9,     0,     0,   524,   525,
     526,   527,     0,     6,     0,     0,     0,     0,     0,   360,
       7,     8,     9,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,     0,     0,     0,     0,     0,   528,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,     0,  -143,     0,  -143,  -143,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,     0,     0,
    -144,     0,  -144,  -144,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,     0,  -142,     0,  -142,  -142,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,     0,     0,   459,     0,  -115,
    -115,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,     0,
    -119,     0,  -119,  -119,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,     0,     0,  -125,     0,  -125,  -125,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,     0,  -133,     0,  -133,
    -133,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,     0,
       0,  -120,     0,  -120,  -120,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,     0,  -136,     0,  -136,  -136,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,     0,     0,  -135,     0,
    -135,  -135,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
       0,  -134,     0,  -134,  -134,   458,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,     0,     0,  -126,     0,  -126,  -126,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,     0,     0,     0,
    -111,  -111,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
       0,     0,     0,     0,  -143,  -143,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,     0,     0,     0,  -144,  -144,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,     0,     0,     0,
       0,  -142,  -142,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,     0,     0,     0,  -118,  -118,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,     0,     0,     0,     0,  -119,  -119,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,     0,     0,
       0,  -125,  -125,   458,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,     0,     0,     0,     0,  -133,  -133,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,     0,     0,     0,  -114,  -114,
     330,   331,   332,   333,   -90,   335,   336,   337,     0,     0,
       0,     0,  -115,  -115,   330,   331,   332,   -94,   -94,   335,
     336,   337,     0,     0,     0,   -90,   -90,   330,   331,   332,
     -98,   -98,   -98,   336,   337,     0,     0,     0,     0,   -94,
     -94,   330,   331,  -102,  -102,  -102,  -102,   336,   337,     0,
       0,     0,   -98,   -98,   330,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,     0,     0,     0,     0,  -102,  -102,   458,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,     0,     0,     0,  -113,
    -113,   330,   331,  -108,  -108,  -108,  -108,   336,   337,     0,
       0,     0,     0,  -112,  -112,   330,   331,  -107,  -107,  -107,
    -107,   336,   337,     0,     0,     0,  -108,  -108,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,     0,     0,     0,     0,
    -107,  -107,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
       0,     0,     0,  -117,  -117,   330,   331,   332,   333,   334,
     335,   336,   337,     0,     0,     0,     0,  -116,  -116,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,     0,     0,     0,
     -84,   -84,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
       0,     0,     0,     0,  -120,  -120,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,     0,     0,     0,  -136,  -136,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,     0,     0,     0,
       0,  -135,  -135,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,     0,     0,     0,  -134,  -134,   378,   379,   380,   381,
     382,   383,   384,   385,     0,     0,     0,     0,  -126,  -126,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,   220,   386,
       0,   221,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
       0,     0,  -143,  -143,     0,  -143,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -144,  -144,     0,  -144,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,     0,     0,  -142,  -142,
       0,  -142,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -115,   519,     0,  -115,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,     0,     0,  -119,  -119,     0,  -119,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -125,  -125,     0,  -125,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,     0,     0,
    -133,  -133,     0,  -133,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -120,  -120,     0,  -120,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,  -136,  -136,     0,  -136,
      46,    47,    48,    49,    50,    51,    52,    53,   669,    58,
       0,   670,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
       0,     0,   685,    58,     0,   686,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -135,  -135,     0,  -135,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,     0,     0,  -134,  -134,
       0,  -134,   378,   379,   380,   381,   382,   383,   384,   385,
    -126,  -126,     0,  -126,   378,   379,   380,   381,   382,   383,
     384,   385,     0,     0,   732,   386,     0,   733,   279,   280,
     281,   282,   283,   284,   285,   286,   742,   386,     0,   743,
     279,   280,   281,   282,   283,   284,   285,   286,     0,     0,
       0,   287,     0,   168,   279,   280,   281,   282,   283,   284,
     285,   286,     0,   287,     0,   171,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,     0,     0,     0,   287,     0,   240,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,     0,  -143,
       0,  -143,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
       0,     0,     0,  -144,     0,  -144,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,     0,  -142,     0,  -142,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,     0,     0,     0,   399,
       0,  -115,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
       0,  -119,     0,  -119,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,     0,     0,     0,  -125,     0,  -125,   518,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,     0,  -133,     0,  -133,
     279,   280,   281,   282,   283,   284,   285,   286,     0,     0,
    -111,     0,     0,  -111,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,     0,   287,     0,   550,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,     0,     0,     0,  -120,     0,  -120,
     279,   280,   281,   282,   283,   284,   285,   286,     0,  -136,
       0,  -136,   279,   280,   281,   282,   283,   284,   285,   286,
       0,     0,     0,   287,     0,   571,   279,   280,   281,   282,
     283,   284,   285,   286,     0,   287,     0,   593,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,     0,     0,     0,   287,
       0,   631,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -143,     0,     0,  -143,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,     0,     0,  -144,     0,     0,  -144,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -142,     0,     0,  -142,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,     0,     0,
    -118,     0,     0,  -118,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -119,     0,     0,  -119,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,     0,     0,  -125,     0,     0,  -125,
     518,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -133,     0,
       0,  -133,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
       0,     0,  -114,     0,     0,  -114,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -115,     0,     0,  -115,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,     0,     0,     0,  -135,
       0,  -135,   279,   280,   281,   282,   283,   284,   285,   286,
       0,  -134,     0,  -134,   279,   280,   281,   282,   283,   284,
     285,   286,     0,     0,     0,   287,     0,   659,   279,   280,
     281,   282,   283,   284,   285,   286,     0,   287,     0,   664,
     279,   280,   281,   282,   283,   284,   285,   286,     0,     0,
       0,   287,     0,   667,   279,   280,   281,   282,   283,   284,
     285,   286,     0,   287,     0,   675,   279,   280,   281,   282,
     283,   284,   285,   286,     0,     0,     0,   287,     0,   680,
     378,   379,   380,   381,   -90,   383,   384,   385,     0,   287,
       0,   683,   378,   379,   380,   -94,   -94,   383,   384,   385,
       0,     0,   -90,     0,     0,   -90,   378,   379,   380,   -98,
     -98,   -98,   384,   385,   -94,     0,     0,   -94,   378,   379,
    -102,  -102,  -102,  -102,   384,   385,     0,     0,   -98,     0,
       0,   -98,   378,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
    -102,     0,     0,  -102,   518,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,     0,     0,  -113,     0,     0,  -113,   378,   379,
    -108,  -108,  -108,  -108,   384,   385,  -112,     0,     0,  -112,
     378,   379,  -107,  -107,  -107,  -107,   384,   385,     0,     0,
    -108,     0,     0,  -108,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -107,     0,     0,  -107,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,     0,     0,  -117,     0,     0,  -117,
     378,   379,   380,   381,   382,   383,   384,   385,  -116,     0,
       0,  -116,   279,   280,   281,   282,   283,   284,   285,   286,
       0,     0,   -84,     0,     0,   -84,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,     0,   287,     0,   690,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,     0,     0,  -120,     0,
       0,  -120,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -136,     0,     0,  -136,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,     0,     0,     0,  -126,     0,  -126,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -135,     0,     0,  -135,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,     0,     0,
    -134,     0,     0,  -134,   279,   280,   281,   282,   283,   284,
     285,   286,  -126,     0,     0,  -126,   279,   280,   281,   282,
     283,   284,   285,   286,     0,     0,     0,   287,     0,   766,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,     0,   287,
       0,   770,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
       0,     0,     0,     0,     0,  -125,   398,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,     0,     0,     0,  -133,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,     0,     0,     0,     0,
       0,  -114,   279,   280,   281,   282,   -90,   284,   285,   286,
       0,     0,     0,  -115,   279,   280,   281,   -94,   -94,   284,
     285,   286,     0,     0,     0,     0,     0,   -90,   279,   280,
     281,   -98,   -98,   -98,   285,   286,     0,     0,     0,   -94,
     279,   280,  -102,  -102,  -102,  -102,   285,   286,     0,     0,
       0,     0,     0,   -98,   279,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,     0,     0,     0,  -102,   398,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,     0,     0,     0,     0,     0,  -113,
     279,   280,  -108,  -108,  -108,  -108,   285,   286,     0,     0,
       0,  -112,   279,   280,  -107,  -107,  -107,  -107,   285,   286,
       0,     0,     0,     0,     0,  -108,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,     0,     0,     0,  -107,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,     0,     0,     0,     0,
       0,  -117,   279,   280,   281,   282,   283,   284,   285,   286,
       0,     0,     0,  -116,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,     0,     0,     0,     0,     0,   -84,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,     0,     0,     0,  -120,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,     0,     0,
       0,     0,     0,  -136,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,     0,     0,     0,  -135,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,     0,     0,     0,     0,     0,  -134,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,     0,     0,
       0,  -126,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
       0,     0,  -143,  -143,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,     0,     0,  -144,  -144,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,     0,     0,  -142,  -142,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,     0,     0,  -115,    88,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,     0,     0,
    -119,  -119,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
       0,     0,  -125,  -125,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,  -133,  -133,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,     0,     0,   124,    58,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,     0,     0,  -120,  -120,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,     0,     0,
    -136,  -136,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
       0,     0,  -135,  -135,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,     0,     0,  -134,  -134,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,  -126,  -126,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,   588,    58,
     279,   280,   281,   282,   283,   284,   285,   286,     0,     0,
     628,    58,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
       0,     0,     0,   287,    87,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,     0,     0,  -118,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,     0,     0,     0,  -114,    46,    47,    48,
      49,   -90,    51,    52,    53,     0,     0,  -115,    46,    47,
      48,   -94,   -94,    51,    52,    53,     0,     0,     0,   -90,
      46,    47,    48,   -98,   -98,   -98,    52,    53,     0,     0,
     -94,    46,    47,  -102,  -102,  -102,  -102,    52,    53,     0,
       0,     0,   -98,    46,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,     0,     0,  -102,    87,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,     0,     0,     0,  -113,    46,    47,  -108,  -108,
    -108,  -108,    52,    53,     0,     0,  -112,    46,    47,  -107,
    -107,  -107,  -107,    52,    53,     0,     0,     0,  -108,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,     0,     0,  -107,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,     0,     0,
       0,  -117,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,  -116,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,     0,     0,     0,   -84,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,     0,     0,  -143,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,     0,     0,     0,  -144,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,     0,     0,  -142,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,     0,     0,     0,
    -119,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,     0,
       0,  -125,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
       0,     0,     0,  -133,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,     0,     0,  -120,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,     0,     0,     0,  -136,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,     0,     0,  -135,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,     0,     0,     0,  -134,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
    -126,   279,   280,   281,   282,   283,   284,   285,   286,   330,
     331,   332,   333,   334,   335,   336,   337,   378,   379,   380,
     381,   382,   383,   384,   385
};

static const yytype_int16 yycheck[] =
{
       0,     0,   446,   439,   295,     1,     1,     1,    29,     1,
       6,     1,     6,   173,   402,   175,    16,    17,     0,   407,
      20,    20,     1,    19,    20,     7,     8,     9,    10,    11,
      12,    13,    14,     1,    29,    29,    32,    31,     1,    31,
       0,    31,    24,     6,    26,    27,     1,    29,    30,     1,
       1,     1,    31,    35,     1,     6,     6,   348,   218,    29,
     220,    29,   222,   507,   500,    65,    29,    67,    31,    69,
      21,    21,    10,    11,   462,     1,    31,    29,    29,    29,
      31,    31,     0,    32,    31,     1,     1,     3,     4,     5,
       6,    91,     8,     1,    32,    33,     7,     0,     6,    15,
      16,    17,    20,    19,    20,    31,    22,    23,    24,    25,
      26,    27,     1,    29,    11,    31,    31,    20,    34,    35,
      32,     0,     1,     1,     3,     4,     5,     6,     6,     8,
      29,     1,     1,    32,   522,    32,    15,    16,    17,     1,
      19,    20,    31,    22,    23,    24,     0,    26,    27,     1,
      29,    29,    31,    31,     6,    34,     0,     6,     1,     1,
       1,    31,    31,   162,     6,     6,    20,    19,    20,    31,
       1,   171,   172,   173,    11,   175,    20,     1,    19,    20,
      32,   181,     6,    32,    33,     1,     1,    29,    31,     1,
     578,    32,   191,    32,     6,    32,     1,     1,    29,    32,
     200,     6,   202,     7,     8,     9,    10,    11,    12,    13,
      14,   129,   211,    29,    29,   215,    21,   217,   218,   219,
     220,   221,   222,   223,    29,    32,    30,    31,    32,    33,
     618,     3,     4,     5,     6,     1,     8,     1,   238,   239,
     240,   241,     6,    15,    16,    17,     0,     6,    32,     1,
       1,     1,   252,   171,   172,     0,     6,    21,   176,    31,
      29,    29,    21,    29,    32,    29,    20,    29,   656,     6,
      32,    32,   272,    32,    33,    20,     1,    29,    29,    29,
       1,     6,   200,   443,   202,    11,     7,     8,     9,    10,
      11,    12,    13,    14,   294,    32,    33,   215,    29,   217,
      35,   219,    32,   221,    29,   223,    32,    33,   308,    30,
      31,    32,    33,     1,     6,     1,     6,   171,   172,     0,
     238,   239,   240,   241,     1,    29,    30,   171,   172,    21,
       7,     8,     9,    10,    11,    12,    13,    14,    11,    20,
      32,    33,    32,    33,   504,    29,   200,   347,   202,    29,
      10,    11,    29,    30,    31,    32,   200,    32,   202,    32,
     360,   215,    11,   217,    32,   219,    32,   221,    32,   223,
     224,   215,    32,   217,    29,   219,    34,   221,    32,   223,
      29,    10,    11,   237,   238,   239,   240,   241,    11,    32,
       0,    32,    10,    11,   238,   239,   240,   241,     9,    10,
      11,    12,   402,    32,    33,    29,    29,   407,    32,    32,
      20,    29,   412,     9,    10,    11,    12,   171,   172,    32,
      33,    32,     1,    10,    11,    12,   171,   172,     7,     8,
       9,    10,    11,    12,    13,    14,    32,    33,    11,   439,
      11,   441,    29,   443,    29,    32,   200,    32,   202,    10,
      11,    12,    31,    32,    33,   200,    32,   202,    29,    32,
      33,   215,   462,   217,    29,   219,     1,   221,   468,   223,
     215,    32,   217,    32,   219,    32,   221,    32,   223,    11,
       9,    10,    11,    12,   238,   239,   240,   241,    10,    11,
     171,   172,     7,   238,   239,   240,   241,    29,    10,    11,
     500,    29,   502,    32,   504,    11,    32,    10,    11,   669,
      32,   671,     9,    10,    11,    12,     7,    29,    29,   200,
      32,   202,   522,    29,    32,   685,    32,   687,   528,    32,
      33,     7,    29,    32,   215,    32,   217,     1,   219,    32,
     221,    29,   223,     7,     8,     9,    10,    11,    12,    13,
      14,     3,     4,     5,     6,    11,     8,   238,   239,   240,
     241,   171,   172,    15,    16,    17,    32,    31,    32,    33,
     730,    32,   732,    32,   734,    32,    32,    33,   578,    31,
     740,    32,   742,    11,   744,    32,    33,     1,    10,    11,
     200,    32,   202,     7,     8,     9,    10,    11,    12,    13,
      14,    29,    35,    29,    32,   215,    32,   217,    32,   219,
      32,   221,     1,   223,    32,    29,    30,    31,   618,     1,
      32,     3,     4,     5,     6,    32,     8,    32,   238,   239,
     240,   241,    32,    15,    16,    17,    29,    19,    20,    32,
      22,    23,    24,    25,    26,    27,    10,    11,    12,    31,
      29,    30,    34,    35,    32,    33,   656,     7,     8,     9,
      10,    11,    12,    13,    14,    29,    32,    33,    32,   669,
      32,   671,    10,    11,     1,    29,     3,     4,     5,     6,
      30,     8,    32,   683,   684,   685,    35,   687,    15,    16,
      17,    29,    19,    20,    32,    22,    23,    24,    25,    26,
      27,    32,    10,    11,    31,    29,    30,    34,    35,     8,
       9,    10,    11,    12,    13,    14,     1,    32,   718,    32,
     720,    29,     7,     8,     9,    10,    11,    12,    13,    14,
     730,    29,   732,    32,   734,    32,    33,   737,    29,   739,
     740,   741,   742,   743,   744,   745,    31,    32,    32,   667,
     668,     1,    10,    11,    12,    32,    33,     7,     8,     9,
      10,    11,    12,    13,    14,   683,   684,    29,   768,   769,
     770,   771,    29,     1,    32,     3,     4,     5,     6,    29,
       8,    31,    32,    32,   702,    32,   704,    15,    16,    17,
      32,    19,    20,    32,    22,    23,    24,    25,    26,    27,
     718,    32,   720,    31,    29,    30,    34,    35,    32,   727,
      32,   729,    20,   731,   191,   733,   211,   735,   132,   737,
      -1,   739,    -1,   741,     6,   743,    -1,   745,    -1,   683,
     684,    -1,     9,    10,    11,    12,    -1,    19,    20,   683,
     684,    -1,     9,    10,    11,    12,   764,   765,   766,   767,
     768,   769,   770,   771,     1,    32,     3,     4,     5,     6,
      -1,     8,    29,    -1,   718,    32,   720,    -1,    15,    16,
      17,    18,    32,    33,   718,    -1,   720,    10,    11,     9,
      10,    11,    12,   737,    31,   739,    -1,   741,    -1,   743,
      -1,   745,    -1,   737,    -1,   739,    29,   741,    -1,   743,
      -1,   745,    32,    33,     1,    -1,     3,     4,     5,     6,
      -1,     8,    32,    33,   768,   769,   770,   771,    15,    16,
      17,    10,    11,    12,   768,   769,   770,   771,    -1,   683,
     684,    -1,    29,    -1,    31,    32,    32,    33,   683,   684,
      10,    11,    12,    32,    33,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,     9,    10,    11,    12,    29,
      15,    16,    17,    -1,   718,    -1,   720,    22,    23,    24,
      25,    26,    27,   718,    -1,   720,    31,    -1,    32,    34,
      29,    30,    31,   737,    -1,   739,    -1,   741,    -1,   743,
      -1,   745,   737,    -1,   739,    -1,   741,    -1,   743,     1,
     745,    -1,   683,   684,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,   768,   769,   770,   771,    29,    30,
      31,    -1,    -1,   768,   769,   770,   771,    29,    30,    31,
      32,    -1,     9,    10,    11,    12,    -1,   718,     1,   720,
       3,     4,     5,     6,    -1,     8,    -1,     9,    10,    11,
      12,    -1,    15,    16,    17,    32,   737,    -1,   739,    -1,
     741,    -1,   743,    -1,   745,    -1,    29,    -1,    31,    32,
      32,    33,    -1,   683,   684,    32,    33,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,   768,   769,   770,
     771,    -1,    -1,    15,    16,    17,    -1,    19,    20,     0,
      22,    23,    24,    25,    26,    27,    -1,    -1,   718,    31,
     720,    -1,    34,    35,    -1,    -1,    17,    10,    11,    20,
       8,     9,    10,    11,    12,    13,    14,   737,    -1,   739,
      -1,   741,    -1,   743,    -1,   745,    29,    -1,    -1,    32,
      -1,    29,    43,    44,    32,    46,    47,    48,    49,    50,
      51,    52,    53,     9,    10,    11,    12,    58,   768,   769,
     770,   771,    63,    -1,    65,    -1,    67,     8,     9,    10,
      11,    12,    13,    14,    75,    -1,    32,    33,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    29,     1,
      91,     3,     4,     5,     6,    -1,     8,    -1,     9,    10,
      11,    12,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    29,    31,
      -1,    32,    34,    35,    -1,     1,    -1,     3,     4,     5,
       6,   132,     8,    -1,    -1,   136,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    10,    11,    12,    31,    -1,     1,    34,    35,
      -1,   162,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    29,   173,    -1,   175,    -1,    -1,    -1,    -1,     1,
     181,     3,     4,     5,     6,    29,     8,    31,   189,    -1,
     191,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    10,    11,    12,    31,
     211,    -1,    34,    35,    10,    11,    12,   218,    -1,   220,
       1,   222,     3,     4,     5,     6,    -1,     8,    32,     9,
      10,    11,    12,    29,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    29,
      31,   252,    32,    34,    35,     7,     8,     1,    -1,    -1,
     261,    13,    14,     7,     8,     9,    10,    11,    12,    13,
      14,   272,   273,    -1,     9,    10,    11,    12,   279,   280,
     281,   282,   283,   284,   285,   286,   287,    31,    32,     1,
      -1,     3,     4,     5,     6,    -1,     8,    32,    33,    10,
      11,    12,   303,    15,    16,    17,    -1,   308,    -1,    -1,
      22,    23,    24,    25,    26,    27,   317,    -1,    29,    31,
      -1,    32,    34,    -1,    -1,     9,    10,    11,    12,   330,
     331,   332,   333,   334,   335,   336,   337,   338,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    32,     8,
      -1,     9,    10,    11,    12,    -1,    15,    16,    17,   360,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,   370,
      -1,    29,    31,    -1,    32,    34,    35,   378,   379,   380,
     381,   382,   383,   384,   385,   386,     9,    10,    11,    12,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       1,   402,     3,     4,     5,     6,   407,     8,    -1,    32,
      33,   412,    -1,   414,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,     7,     8,
      31,    -1,    -1,    34,    13,    14,   437,    -1,   439,    -1,
     441,     9,    10,    11,    12,   446,     9,    10,    11,    12,
     451,   452,   453,   454,   455,   456,   457,   458,   459,    -1,
      -1,   462,    -1,    -1,    32,    33,    29,   468,    -1,   470,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,   498,    -1,   500,
      31,   502,    17,    34,    35,    -1,   507,    -1,    -1,    -1,
     511,   512,   513,   514,   515,   516,   517,   518,   519,    -1,
      -1,   522,    -1,    -1,    -1,    40,    -1,   528,    -1,   530,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,     9,
      10,    11,    12,    58,     1,    -1,     3,     4,     5,     6,
      65,     8,    67,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    32,    33,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    31,    32,    91,   578,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,     9,    10,
      11,    12,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    29,    31,
      -1,     1,    34,     3,     4,     5,     6,   618,     8,    -1,
       9,    10,    11,    12,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      29,    31,    -1,    32,    34,    35,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,   656,    -1,    -1,   173,    -1,
     175,    15,    16,    17,    -1,    -1,   181,    -1,   669,    -1,
     671,    -1,    -1,    -1,    -1,    29,     1,    31,     3,     4,
       5,     6,    -1,     8,   685,    -1,   687,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,   218,    -1,   220,    31,   222,    -1,    34,
      35,    -1,    -1,    -1,     1,     9,    10,    11,    12,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,   730,
      -1,   732,    -1,   734,    -1,    29,    -1,   252,    32,   740,
      -1,   742,    29,   744,    31,    32,   261,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,   272,   273,     9,
      10,    11,    12,    -1,   279,   280,   281,   282,   283,   284,
     285,   286,   287,     1,    32,     3,     4,     5,     6,    -1,
       8,    -1,    32,    33,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,   308,    22,    23,    24,    25,    26,    27,
      -1,    -1,   317,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,     9,    10,    11,    12,   330,   331,   332,   333,   334,
     335,   336,   337,   338,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    32,     8,    -1,     9,    10,    11,
      12,    -1,    15,    16,    17,   360,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   370,    -1,    29,    31,    -1,
      32,    34,    35,   378,   379,   380,   381,   382,   383,   384,
     385,   386,     9,    10,    11,    12,   391,   392,   393,   394,
     395,   396,   397,   398,   399,    -1,     1,   402,     3,     4,
       5,     6,   407,     8,    -1,    32,    33,   412,    -1,   414,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     1,    -1,    -1,   439,    -1,   441,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,   451,   452,   453,   454,
     455,   456,   457,   458,   459,    -1,    -1,   462,    -1,    -1,
      30,    31,    32,   468,    -1,   470,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,   500,    31,   502,    17,    34,
      35,     9,    10,    11,    12,    -1,   511,   512,   513,   514,
     515,   516,   517,   518,   519,    -1,    -1,   522,    -1,    -1,
      -1,    29,    -1,   528,    32,   530,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    10,    11,    12,    -1,    58,
       1,    -1,     3,     4,     5,     6,    65,     8,    67,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    32,    33,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      31,    32,    91,   578,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    29,    31,    -1,    32,    34,    35,    -1,
      -1,    -1,     1,   618,     3,     4,     5,     6,    -1,     8,
      -1,     9,    10,    11,    12,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    32,    34,    35,     9,    10,    11,
      12,   656,    -1,    -1,   173,    -1,   175,    -1,     9,    10,
      11,    12,   181,    -1,   669,    -1,   671,    -1,    -1,    -1,
      32,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
     685,    32,   687,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,   218,
      -1,   220,    31,   222,    -1,    34,    35,    -1,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,   730,    -1,   732,    29,   734,
      15,    16,    17,   252,    -1,   740,    -1,   742,    -1,   744,
      -1,    -1,   261,    -1,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,   272,   273,    10,    11,    12,    -1,    -1,
     279,   280,   281,   282,   283,   284,   285,   286,   287,     1,
      -1,     3,     4,     5,     6,    -1,     8,    32,    33,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,   308,
      22,    23,    24,    25,    26,    27,    -1,    -1,   317,    31,
      -1,    -1,    34,    35,    -1,     9,    10,    11,    12,    -1,
      -1,   330,   331,   332,   333,   334,   335,   336,   337,   338,
      -1,    -1,    -1,    -1,     1,    29,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,   360,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,   370,    -1,    29,    31,    -1,    -1,    34,    35,   378,
     379,   380,   381,   382,   383,   384,   385,   386,    -1,    -1,
      -1,    -1,   391,   392,   393,   394,   395,   396,   397,   398,
     399,    -1,     1,   402,     3,     4,     5,     6,   407,     8,
      -1,    -1,    -1,   412,    -1,   414,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,    -1,
     439,    -1,   441,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,   451,   452,   453,   454,   455,   456,   457,   458,
     459,    -1,    -1,   462,    -1,    -1,    30,    31,    32,   468,
      -1,   470,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,   500,    31,   502,    17,    34,    35,     9,    10,    11,
      12,    -1,   511,   512,   513,   514,   515,   516,   517,   518,
     519,    -1,    -1,   522,    -1,    -1,    -1,    29,    -1,   528,
      -1,   530,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,     1,    -1,     3,     4,
       5,     6,    65,     8,    67,    -1,    -1,     7,     8,     9,
      15,    16,    17,    13,    14,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    31,    32,    91,   578,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
       9,    10,    11,    12,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      29,    31,     0,     1,    34,     3,     4,     5,     6,   618,
       8,    -1,     9,    10,    11,    12,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,     1,    29,    31,    -1,    -1,    34,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,   656,    -1,    -1,
     173,    -1,   175,    -1,     9,    10,    11,    12,   181,    29,
     669,    31,   671,    -1,    -1,    -1,    -1,     0,     1,    -1,
       3,     4,     5,     6,    29,     8,   685,    -1,   687,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   218,    -1,   220,    31,   222,
      -1,    34,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,   730,    -1,   732,    29,   734,    15,    16,    17,   252,
      -1,   740,    -1,   742,    -1,   744,    -1,    -1,   261,    -1,
      29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,   272,
     273,     9,    10,    11,    12,    -1,   279,   280,   281,   282,
     283,   284,   285,   286,   287,     1,    -1,     3,     4,     5,
       6,    29,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,   308,    22,    23,    24,    25,
      26,    27,    -1,    -1,   317,    31,     7,     8,    34,    35,
      -1,    -1,    13,    14,    -1,    -1,    -1,   330,   331,   332,
     333,   334,   335,   336,   337,   338,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,   360,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,   370,    -1,    -1,
      31,    -1,    -1,    34,    -1,   378,   379,   380,   381,   382,
     383,   384,   385,   386,    -1,    -1,    -1,    -1,   391,   392,
     393,   394,   395,   396,   397,   398,   399,     0,     1,   402,
       3,     4,     5,     6,   407,     8,    -1,    -1,    -1,   412,
      -1,   414,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,     3,     4,     5,     6,   439,     8,   441,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,   451,   452,
     453,   454,   455,   456,   457,   458,   459,     7,     8,   462,
      31,    32,    -1,    13,    14,   468,    -1,   470,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,   500,    31,   502,
      17,    34,    35,    -1,    -1,    -1,    -1,    -1,   511,   512,
     513,   514,   515,   516,   517,   518,   519,    -1,    -1,   522,
      -1,    -1,    -1,    -1,    -1,   528,    -1,   530,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    58,     1,    -1,     3,     4,     5,     6,    65,     8,
      67,    -1,    -1,     7,     8,     9,    15,    16,    17,    13,
      14,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    31,    32,    91,   578,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,
      34,     3,     4,     5,     6,   618,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,   656,    -1,    -1,   173,    -1,   175,    15,
      16,    17,    18,    -1,   181,    -1,   669,    -1,   671,    -1,
      -1,    -1,    -1,    -1,     1,    31,     3,     4,     5,     6,
      -1,     8,   685,    -1,   687,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,   218,    -1,   220,    31,   222,    -1,    34,    35,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,   730,    -1,   732,
      -1,   734,    -1,    -1,    -1,   252,    -1,   740,    29,   742,
      31,   744,    -1,    -1,   261,    -1,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,   272,   273,    -1,    -1,    -1,
      -1,    -1,   279,   280,   281,   282,   283,   284,   285,   286,
     287,     1,    32,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,   308,    22,    23,    24,    25,    26,    27,    -1,    -1,
     317,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   330,   331,   332,   333,   334,   335,   336,
     337,   338,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,   360,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,   370,    -1,    -1,    31,    -1,    -1,    34,
      35,   378,   379,   380,   381,   382,   383,   384,   385,   386,
      -1,    -1,    -1,    -1,   391,   392,   393,   394,   395,   396,
     397,   398,   399,     0,     1,   402,     3,     4,     5,     6,
     407,     8,    -1,    -1,    -1,   412,    -1,   414,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
       1,    -1,   439,    -1,   441,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   451,   452,   453,   454,   455,   456,
     457,   458,   459,    -1,    -1,   462,    -1,    -1,    29,    30,
      31,   468,    -1,   470,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,   500,    31,   502,    17,    34,    35,    -1,
      -1,    -1,    -1,    -1,   511,   512,   513,   514,   515,   516,
     517,   518,   519,    -1,    -1,   522,    -1,    -1,    -1,    -1,
      -1,   528,    -1,   530,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    58,     1,    -1,
       3,     4,     5,     6,    65,     8,    67,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    31,    -1,
      91,   578,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,   618,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,   656,
      -1,    -1,   173,    -1,   175,    15,    16,    17,    -1,    -1,
     181,    -1,   669,    -1,   671,    -1,    -1,    -1,    -1,     0,
       1,    31,     3,     4,     5,     6,    -1,     8,   685,    -1,
     687,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,   218,    -1,   220,
      31,   222,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,     7,     8,     9,    15,    16,    17,    13,
      14,    -1,    -1,   730,    -1,   732,    -1,   734,    -1,    -1,
      29,   252,    31,   740,    -1,   742,    -1,   744,    -1,    -1,
     261,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,   272,   273,    -1,    -1,    -1,    -1,    -1,   279,   280,
     281,   282,   283,   284,   285,   286,   287,     1,    32,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,   308,    22,    23,
      24,    25,    26,    27,    -1,    -1,   317,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,
     331,   332,   333,   334,   335,   336,   337,   338,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,   360,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,   370,
      -1,    -1,    31,    -1,    -1,    34,    -1,   378,   379,   380,
     381,   382,   383,   384,   385,   386,    -1,    -1,    -1,    -1,
     391,   392,   393,   394,   395,   396,   397,   398,   399,    -1,
      -1,   402,     7,     8,     9,    10,   407,    12,    13,    14,
      -1,   412,    -1,   414,    -1,     1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      17,    -1,     1,    -1,     3,     4,     5,     6,   439,     8,
     441,    -1,    -1,    29,    30,    31,    15,    16,    17,    -1,
     451,   452,   453,   454,   455,   456,   457,   458,   459,    -1,
      47,   462,    31,    -1,    -1,    -1,    -1,   468,    -1,   470,
       1,    -1,     3,     4,     5,     6,    -1,     8,    65,    -1,
      67,     7,     8,     9,    15,    16,    17,    13,    14,    -1,
      -1,    22,    23,    24,    25,    26,    27,    84,    -1,   500,
      31,   502,    -1,    34,    91,    -1,    -1,    -1,    -1,    -1,
     511,   512,   513,   514,   515,   516,   517,   518,   519,    -1,
      -1,   522,    -1,    -1,    -1,    -1,    -1,   528,    -1,   530,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,     1,    -1,    34,    -1,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,   578,     7,     8,
       9,    10,    11,    12,    13,    14,   173,    -1,   175,    -1,
      29,    30,    31,    -1,   181,    -1,     0,     1,    -1,     3,
       4,     5,     6,    32,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,   618,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,   218,    -1,   220,    -1,   222,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,   656,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,   252,    31,    -1,   669,    -1,
     671,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,   685,   272,   687,    31,    -1,    -1,
      34,    -1,    -1,   280,   281,   282,   283,   284,   285,   286,
     287,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,   308,    -1,    22,    23,    24,    25,    26,    27,   730,
      -1,   732,    31,   734,    -1,    34,    -1,    -1,    -1,   740,
      -1,   742,    -1,   744,   331,   332,   333,   334,   335,   336,
     337,   338,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,   360,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,   379,   380,   381,   382,   383,   384,   385,   386,
      -1,    -1,    -1,    -1,   391,   392,   393,   394,   395,   396,
     397,    17,   399,    -1,     1,   402,     3,     4,     5,     6,
     407,     8,    -1,    -1,    -1,   412,    -1,    -1,    15,    16,
      17,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    48,    -1,    31,    -1,    52,    53,    -1,    -1,
      -1,    -1,   439,    -1,   441,    30,    -1,    32,    33,    65,
      -1,    67,    -1,    -1,   451,   452,   453,   454,   455,   456,
     457,    -1,   459,    -1,    -1,   462,    -1,    83,    -1,    85,
      86,   468,    -1,     0,     1,    91,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,   500,    31,   502,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,   511,   512,   513,   514,   515,   516,
     517,    -1,   519,    -1,    -1,   522,    -1,    -1,    -1,    -1,
       1,   528,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,   173,    -1,   175,
      31,    -1,    -1,    34,    35,   181,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,     1,    -1,     3,     4,     5,
       6,   578,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    32,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,   218,    -1,   220,    31,   222,    -1,    34,    35,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,   618,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    29,    30,    -1,    32,   252,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    17,    -1,    31,    -1,   272,    34,    -1,   656,
      -1,    -1,    -1,    -1,    -1,   281,   282,   283,   284,   285,
     286,   287,   669,    -1,   671,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,   685,     8,
     687,    -1,   308,    -1,    -1,    -1,    15,    16,    17,    -1,
      65,    -1,    67,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,   332,   333,   334,   335,
     336,   337,   338,    -1,    -1,     1,    91,     3,     4,     5,
       6,    -1,     8,   730,    -1,   732,    -1,   734,    -1,    15,
      16,    17,    -1,   740,   360,   742,    -1,   744,     8,     9,
      10,    11,    12,    13,    14,    31,     7,     8,     9,    10,
      11,    12,    13,    14,   380,   381,   382,   383,   384,   385,
     386,    -1,    32,    33,    -1,   391,   392,   393,   394,    30,
     396,   397,    -1,   399,    -1,     1,   402,     3,     4,     5,
       6,   407,     8,    -1,    -1,    -1,   412,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,   173,    -1,
     175,    -1,    -1,    -1,    -1,    31,   181,     1,    -1,     3,
       4,     5,     6,   439,     8,   441,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,   451,   452,   453,   454,    -1,
     456,   457,    -1,   459,    -1,    -1,   462,    31,    -1,    -1,
      -1,    -1,   468,   218,    -1,   220,    -1,   222,     1,    -1,
       3,     4,     5,     6,     1,     8,     3,     4,     5,     6,
      -1,     8,    15,    16,    17,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,   500,    -1,   502,   252,    31,    -1,
      -1,    -1,    -1,    -1,    31,   511,   512,   513,   514,    -1,
     516,   517,    -1,   519,    -1,    -1,   522,   272,     7,     8,
       9,    10,   528,    12,    13,    14,   281,   282,   283,   284,
     285,   286,   287,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,   308,    15,    16,    17,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    17,
      31,    -1,   578,    34,    -1,    -1,    -1,   332,   333,   334,
     335,   336,   337,   338,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    51,    -1,   360,    22,    23,    24,    25,
      26,    27,   618,    -1,    -1,    31,    -1,    65,    34,    67,
      -1,    -1,    -1,    -1,    -1,   380,   381,   382,   383,   384,
     385,   386,    -1,    -1,    82,    -1,   391,   392,   393,   394,
      -1,   396,   397,    91,   399,    -1,    -1,   402,    -1,    -1,
     656,    -1,   407,     7,     8,     9,    10,   412,    12,    13,
      14,    -1,    -1,   669,    -1,   671,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,   685,
       8,   687,    -1,    -1,   439,    -1,   441,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,   451,   452,   453,   454,
      -1,   456,   457,    31,   459,    -1,    -1,   462,    -1,    -1,
      -1,    -1,    -1,   468,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    -1,     8,   730,   173,   732,   175,   734,    -1,
      15,    16,    17,   181,   740,    -1,   742,    -1,   744,    -1,
      -1,    -1,    -1,    -1,    -1,   500,    31,   502,     7,     8,
       9,    10,    11,    12,    13,    14,   511,   512,   513,   514,
      -1,   516,   517,    -1,   519,    -1,    -1,   522,    -1,    -1,
     218,    30,   220,   528,   222,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,   252,    31,    -1,    -1,    34,    35,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      17,    -1,    -1,   578,   272,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,   282,   283,   284,    -1,    -1,   287,
      -1,    31,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    49,    -1,    -1,    -1,    15,    16,    17,    -1,
     308,    -1,     1,   618,     3,     4,     5,     6,    65,     8,
      67,    -1,    31,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    81,   333,   334,   335,    -1,    -1,
     338,    -1,    31,     1,    91,     3,     4,     5,     6,    -1,
       8,   656,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,   360,    -1,   669,    -1,   671,    -1,    -1,     7,
       8,     9,    10,    31,    12,    13,    14,    -1,    -1,    -1,
     685,    -1,   687,   381,   382,   383,    -1,    -1,   386,    -1,
      -1,    -1,    -1,   391,   392,   393,    -1,    -1,    -1,    -1,
      -1,   399,    -1,     1,   402,     3,     4,     5,     6,   407,
       8,    -1,    -1,    -1,   412,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,   730,   173,   732,   175,   734,
      -1,    -1,    -1,    31,   181,   740,    -1,   742,    -1,   744,
      -1,   439,     1,   441,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,   451,   452,   453,    15,    16,    17,    -1,
      -1,   459,    -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,
     468,   218,    31,   220,    -1,   222,     1,    -1,     3,     4,
       5,     6,     1,     8,     3,     4,     5,     6,    -1,     8,
      15,    16,    17,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,   500,    -1,   502,   252,    31,    -1,    -1,    -1,
      -1,    -1,    31,   511,   512,   513,    -1,    -1,    -1,    -1,
      -1,   519,    17,    -1,   522,   272,     7,     8,     9,    -1,
     528,    12,    13,    14,    -1,   282,   283,    -1,    -1,    -1,
     287,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    50,    -1,    15,    16,    17,
      -1,   308,    -1,    -1,    22,    23,    24,    -1,    26,    27,
      65,    -1,    67,    31,    -1,    -1,    34,     7,     8,     9,
     578,    -1,    12,    13,    14,    80,   333,   334,     7,     8,
       9,   338,    -1,    12,    13,    14,    91,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,     1,    -1,     3,
       4,     5,     6,   360,     8,    -1,    -1,    -1,    -1,    -1,
     618,    15,    16,    17,    32,    19,    20,    17,    22,    23,
      24,    25,    26,    27,   381,   382,    -1,    31,    -1,   386,
      34,    35,    -1,    -1,   391,   392,    -1,    -1,    -1,    -1,
      -1,    -1,   399,    -1,    -1,   402,    -1,    -1,   656,    -1,
     407,    -1,    -1,    -1,    -1,   412,    -1,    -1,    58,    -1,
      -1,   669,    -1,   671,    -1,    65,    -1,    67,   173,    -1,
     175,    -1,    -1,    -1,    -1,    -1,   181,   685,    -1,   687,
      -1,    -1,   439,    -1,   441,    -1,    -1,    -1,    88,    -1,
      -1,    91,    -1,    -1,   451,   452,    -1,    -1,    -1,    -1,
      -1,    -1,   459,    -1,    -1,   462,    -1,     3,     4,     5,
       6,   468,     8,   218,    -1,   220,    -1,   222,    -1,    15,
      16,    17,   730,    -1,   732,    -1,   734,    -1,     3,     4,
       5,     6,   740,     8,   742,    31,   744,    -1,    -1,    -1,
      15,    16,    17,   500,    -1,   502,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,   511,   512,    31,    -1,    -1,    -1,
      -1,    -1,   519,    -1,    -1,   522,    -1,   272,    -1,    -1,
      -1,   528,    -1,   173,    -1,   175,    -1,    -1,   283,    -1,
      -1,   181,   287,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,   308,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,   218,    -1,
     220,   578,   222,     1,    -1,     3,     4,     5,     6,   334,
       8,    -1,    -1,   338,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,   252,    31,    -1,   360,    34,    35,    -1,    -1,
       1,   618,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,   272,    -1,    15,    16,    17,   382,     7,     8,
       9,   386,    -1,    12,    13,    14,   391,   287,    -1,    -1,
      31,    -1,    -1,    -1,   399,    -1,    -1,   402,    -1,   656,
      -1,    -1,   407,    -1,    -1,    -1,    -1,   412,   308,    -1,
      -1,    -1,   669,    -1,   671,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,   685,    -1,
     687,    15,    16,    17,   439,    -1,   441,     1,   338,     3,
       4,     5,     6,    -1,     8,    -1,   451,    31,    -1,    -1,
      -1,    15,    16,    17,   459,    -1,    -1,   462,    -1,    -1,
     360,    -1,    -1,   468,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,   730,    -1,   732,    -1,   734,    -1,    -1,
      -1,    -1,    -1,   740,    -1,   742,   386,   744,    -1,     1,
      -1,     3,     4,     5,     6,   500,     8,   502,    -1,   399,
      -1,    -1,   402,    15,    16,    17,   511,   407,     3,     4,
       5,     6,   412,     8,   519,    -1,    -1,   522,    -1,    31,
      15,    16,    17,   528,    -1,    -1,    -1,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    31,    -1,    -1,   439,
      -1,   441,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,   459,
      -1,    34,   462,    -1,    -1,    -1,    -1,    -1,   468,    -1,
      -1,    -1,    -1,   578,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     1,     8,     3,     4,     5,     6,    -1,     8,
      15,    16,    17,    -1,    -1,    -1,    15,    16,    17,    -1,
     500,    -1,   502,    22,    23,    24,    31,    26,    27,    -1,
      -1,    -1,    31,   618,    -1,    34,    -1,    -1,    -1,   519,
      -1,    -1,   522,    -1,    -1,    -1,     0,     1,   528,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,   656,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,    -1,    -1,   669,    -1,   671,    -1,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,   578,    -1,
     685,    -1,   687,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,   618,    -1,
      -1,    -1,    -1,    -1,    -1,   730,    -1,   732,    -1,   734,
      -1,    31,    -1,    -1,    -1,   740,    -1,   742,     1,   744,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,   656,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    31,   669,
      -1,   671,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,   685,    -1,   687,    31,    -1,
      -1,    34,    35,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
     730,    -1,   732,    -1,   734,    -1,    -1,    -1,    -1,    -1,
     740,    -1,   742,     1,   744,     3,     4,     5,     6,    -1,
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
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    24,     8,    26,    27,
      -1,    29,    30,    -1,    15,    16,    17,    35,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      31,     3,     4,     5,     6,    24,     8,    26,    27,    -1,
      29,    30,    -1,    15,    16,    17,    35,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    31,
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
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    32,    33,
       7,     8,     9,    10,    11,    12,    13,    14,    29,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    29,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    29,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      29,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    29,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      29,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    29,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    29,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    29,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    29,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    29,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      29,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    29,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    29,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    29,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    29,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    29,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    29,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    29,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    30,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    30,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    30,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    29,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    29,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    29,    -1,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    29,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    29,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    29,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    29,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,    -1,
      -1,    32,     7,     8,     9,    10,    11,    12,    13,    14,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    30,    -1,    32,     7,     8,
       9,    10,    11,    12,    13,    14,    29,    -1,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      29,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    29,    -1,    -1,    32,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    30,    -1,    32,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    30,
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
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    29,    30,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    29,    30,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      29,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    30,     7,     8,     9,    10,    11,    12,
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
      29,     7,     8,     9,    10,    11,    12,    13,    14,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     8,     9,
      10,    11,    12,    13,    14
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
      11,    10,    12,     9,     8,    13,    14,     7,    30,    70,
       1,    31,    76,     1,    29,    31,    76,    70,     1,    69,
      70,     1,    67,     1,    65,     1,    64,     1,    66,    67,
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
      70,    71,    72,    75,    76,    78,     6,     6,     3,     4,
       5,     6,    31,    71,    72,    75,    76,    78,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    30,    19,    20,
      22,    23,    24,    26,    27,    34,    49,    55,    56,    57,
      59,    60,    61,    76,     3,     4,     5,     6,    31,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    75,
      76,    78,    24,    26,    27,    29,    35,     1,     1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    30,     6,
      19,    20,     1,    22,    23,    24,    26,    27,    34,    49,
      55,    56,    57,    59,    60,    61,     3,     4,     5,     6,
      31,    61,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    75,    76,    78,    29,    30,     1,     7,     8,
       9,    10,    11,    12,    13,    14,    30,     1,    61,     1,
      61,    11,    10,    12,     9,     8,    13,    14,     7,    30,
      70,     1,    31,     1,    61,    70,     1,    31,     3,     4,
       5,     6,    31,    70,    71,    72,    75,    76,    78,     1,
      69,    70,     1,    67,     1,    65,     1,    64,     1,    66,
      67,    67,     1,    63,    21,    21,     1,    31,     1,    31,
       1,    31,     1,    31,     1,    61,    50,    29,    76,     1,
      61,    11,    10,    12,     9,     8,    13,    14,     7,    30,
      70,     1,    31,    29,     3,     4,     5,     6,    31,    70,
      71,    72,    75,    76,    78,     1,    69,    70,     1,    67,
       1,    65,     1,    64,     1,    66,    67,    67,     1,    63,
      21,    21,    24,    26,    27,    29,    35,     1,    31,     1,
      31,     1,    31,     1,    31,     1,    61,    50,    29,     1,
      61,    11,    10,    12,     9,     8,    13,    14,     7,    30,
      70,     1,    31,     1,     3,     4,     5,     6,    31,    70,
      71,    72,    75,    76,    78,     1,    69,    70,     1,    67,
       1,    65,     1,    64,     1,    66,    67,    67,     1,    63,
      32,    32,     1,    64,     1,    65,     1,    66,     1,    67,
       1,    69,     1,    67,     1,    67,     1,    70,     1,    63,
      74,    32,    32,    74,     1,    61,    70,     1,    31,     1,
      76,     1,    61,    79,     1,    61,     1,    62,    29,    29,
      51,    29,    30,    32,    32,     1,    64,     1,    65,     1,
      66,     1,    67,     1,    69,     1,    67,     1,    67,     1,
      70,     1,    63,    74,     1,    61,    70,     1,    31,     1,
      76,     1,    61,    79,     1,    61,     1,    62,    29,    29,
      51,    32,    32,     1,    64,     1,    65,     1,    66,     1,
      67,     1,    69,     1,    67,     1,    67,     1,    70,     1,
      63,    74,     1,    61,    70,     1,    31,    32,    32,    32,
      32,    74,    32,    32,    32,    32,    32,    32,    32,    29,
      32,    29,    35,     1,    32,    32,    32,    74,    32,    32,
      32,    32,    32,    32,    32,    29,    32,    29,    35,    32,
      32,    32,    74,    32,    29,     1,    29,    29,     1,    29,
       1,    29,    25,    54,    25,    54,    62,     1,    62,    32,
      29,     1,    29,    29,     1,    29,     1,    29,    25,    54,
      25,    54,    62,     1,    62,    32,    54,    25,    54,    25,
      29,    32,    29,    32,    29,    32,    54,    25,    54,    25,
      29,    32,    29,    32,    29,    32,    54,    54,    62,    54,
      62,    54,     1,    62,    54,    54,    54,    62,    54,    62,
      54,     1,    62,    54,    32,    32,    32,    32,    32,    32,
      32,    32,    54,    54,    54,    54,    54,    54,    54,    54
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
#line 4272 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4278 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4284 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4290 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4296 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4302 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4308 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4314 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4320 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4326 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4332 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4338 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4344 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4350 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4356 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4362 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4368 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4374 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4380 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4386 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4392 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_1: /* @1  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4398 "src/bison/grammar.c"
        break;

    case YYSYMBOL_46_param_list_opt: /* param_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4404 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4410 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4416 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4422 "src/bison/grammar.c"
        break;

    case YYSYMBOL_51_block_item_list_opt: /* block_item_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4428 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4434 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4440 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4446 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4452 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4458 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4464 "src/bison/grammar.c"
        break;

    case YYSYMBOL_else_error: /* else_error  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4470 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4476 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4482 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4488 "src/bison/grammar.c"
        break;

    case YYSYMBOL_62_expression_opt: /* expression.opt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4494 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4500 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4506 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4512 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4518 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4524 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4530 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4536 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4542 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4548 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4554 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4560 "src/bison/grammar.c"
        break;

    case YYSYMBOL_74_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4566 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4572 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 130 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 4578 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4584 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4590 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4596 "src/bison/grammar.c"
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
#line 4905 "src/bison/grammar.c"
    break;

  case 4: /* prog: error  */
#line 137 "src/bison/grammar.y"
            {
        // idk if this is the best solution
        // actually dont work properly
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
    }
#line 4915 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration_list external_declaration  */
#line 144 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4921 "src/bison/grammar.c"
    break;

  case 6: /* external_declaration_list: external_declaration  */
#line 145 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4927 "src/bison/grammar.c"
    break;

  case 9: /* external_declaration: statement  */
#line 150 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4937 "src/bison/grammar.c"
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
#line 4966 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 181 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4976 "src/bison/grammar.c"
    break;

  case 12: /* var_declaration: type id '=' error  */
#line 186 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4987 "src/bison/grammar.c"
    break;

  case 13: /* var_declaration: id id '=' error  */
#line 192 "src/bison/grammar.y"
                      {
        show_error_range((yylsp[-3]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-3].sym)->name);
        symbol_free((yyvsp[-3].sym));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4998 "src/bison/grammar.c"
    break;

  case 14: /* var_declaration: id id ';'  */
#line 198 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-2]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-2].sym)->name);
        symbol_free((yyvsp[-2].sym));
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 5009 "src/bison/grammar.c"
    break;

  case 15: /* var_declaration: type error  */
#line 204 "src/bison/grammar.y"
                 {
        show_error_range((yylsp[-1]), "expected identifier after " BGRN "'%s'" RESET "\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 5019 "src/bison/grammar.c"
    break;

  case 16: /* var_declaration: type error ';'  */
#line 209 "src/bison/grammar.y"
                     {
        show_error_range((yylsp[-2]), "expected expression before " WHT "';'" RESET "\n");
        free((yyvsp[-2].pchar));
        (yyval.ast) = NULL;
    }
#line 5029 "src/bison/grammar.c"
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
#line 5073 "src/bison/grammar.c"
    break;

  case 18: /* $@2: %empty  */
#line 254 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 5079 "src/bison/grammar.c"
    break;

  case 19: /* func_declaration: type id '(' @1 param_list.opt $@2 ')' compound_stmt  */
#line 254 "src/bison/grammar.y"
                                                              {
        (yyval.ast) = ast_userfunc_init((yyloc), current_context, (yyvsp[-4].ast), ast_params_init((yylsp[-3]), (yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 5089 "src/bison/grammar.c"
    break;

  case 20: /* $@3: %empty  */
#line 259 "src/bison/grammar.y"
               {
        previous_context = current_context;
        list_push(&contexts, context_init("unnamed-func"));
        current_context = list_peek_last(&contexts);
        context_push_scope(current_context);
    }
#line 5100 "src/bison/grammar.c"
    break;

  case 21: /* $@4: %empty  */
#line 264 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 5106 "src/bison/grammar.c"
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
#line 5119 "src/bison/grammar.c"
    break;

  case 23: /* param_list.opt: %empty  */
#line 274 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 5125 "src/bison/grammar.c"
    break;

  case 25: /* params_list: params_list ',' param_decl  */
#line 278 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5131 "src/bison/grammar.c"
    break;

  case 26: /* params_list: param_decl  */
#line 279 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5137 "src/bison/grammar.c"
    break;

  case 27: /* params_list: error  */
#line 280 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 5146 "src/bison/grammar.c"
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
#line 5165 "src/bison/grammar.c"
    break;

  case 29: /* param_decl: type  */
#line 300 "src/bison/grammar.y"
           {
        show_error_range((yylsp[0]), "expected identifier after " BGRN "'%s'" RESET "\n", (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
        (yyval.ast) = NULL;
    }
#line 5175 "src/bison/grammar.c"
    break;

  case 30: /* param_decl: id  */
#line 305 "src/bison/grammar.y"
         {
        show_error_range((yylsp[0]), "unknown type name for " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
        symbol_free((yyvsp[0].sym));
        (yyval.ast) = NULL;
    }
#line 5185 "src/bison/grammar.c"
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
#line 5203 "src/bison/grammar.c"
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
#line 5215 "src/bison/grammar.c"
    break;

  case 33: /* block_item_list.opt: block_item_list  */
#line 333 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 5221 "src/bison/grammar.c"
    break;

  case 34: /* block_item_list.opt: %empty  */
#line 334 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5227 "src/bison/grammar.c"
    break;

  case 35: /* block_item_list: block_item_list block_item  */
#line 337 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 5233 "src/bison/grammar.c"
    break;

  case 36: /* block_item_list: block_item  */
#line 338 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5239 "src/bison/grammar.c"
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
#line 5255 "src/bison/grammar.c"
    break;

  case 47: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 365 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 5264 "src/bison/grammar.c"
    break;

  case 48: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 369 "src/bison/grammar.y"
                                       {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 5273 "src/bison/grammar.c"
    break;

  case 49: /* io_stmt: WRITE '(' error ')' ';'  */
#line 373 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 5283 "src/bison/grammar.c"
    break;

  case 50: /* io_stmt: READ '(' error ')' ';'  */
#line 378 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected identifier before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 5293 "src/bison/grammar.c"
    break;

  case 51: /* io_stmt: READ '(' id ')' error  */
#line 383 "src/bison/grammar.y"
                            {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 5304 "src/bison/grammar.c"
    break;

  case 52: /* io_stmt: WRITE '(' expression ')' error  */
#line 389 "src/bison/grammar.y"
                                     {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5315 "src/bison/grammar.c"
    break;

  case 53: /* io_stmt: WRITE '(' string_literal ')' error  */
#line 395 "src/bison/grammar.y"
                                         {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5326 "src/bison/grammar.c"
    break;

  case 54: /* io_stmt: WRITE error  */
#line 401 "src/bison/grammar.y"
                  {
        show_error_range((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 5336 "src/bison/grammar.c"
    break;

  case 55: /* io_stmt: READ error  */
#line 406 "src/bison/grammar.y"
                 {
        show_error_range((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 5346 "src/bison/grammar.c"
    break;

  case 56: /* expr_stmt: expression ';'  */
#line 413 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 5352 "src/bison/grammar.c"
    break;

  case 57: /* expr_stmt: error ';'  */
#line 414 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5361 "src/bison/grammar.c"
    break;

  case 58: /* expr_stmt: error '}'  */
#line 418 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'}'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5370 "src/bison/grammar.c"
    break;

  case 59: /* expr_stmt: error FOR  */
#line 422 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'for'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5379 "src/bison/grammar.c"
    break;

  case 60: /* expr_stmt: error IF  */
#line 426 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'if'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5388 "src/bison/grammar.c"
    break;

  case 61: /* expr_stmt: error RETURN  */
#line 430 "src/bison/grammar.y"
                   {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'return'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 5397 "src/bison/grammar.c"
    break;

  case 62: /* cond_stmt: IF '(' expression ')' statement  */
#line 436 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 5405 "src/bison/grammar.c"
    break;

  case 63: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 439 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 5413 "src/bison/grammar.c"
    break;

  case 64: /* cond_stmt: IF '(' expression ')' ELSE statement  */
#line 442 "src/bison/grammar.y"
                                           {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-3].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5424 "src/bison/grammar.c"
    break;

  case 65: /* cond_stmt: IF '(' error ')' statement  */
#line 448 "src/bison/grammar.y"
                                            {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5434 "src/bison/grammar.c"
    break;

  case 66: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 453 "src/bison/grammar.y"
                                                {
        show_error_range((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5445 "src/bison/grammar.c"
    break;

  case 67: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 459 "src/bison/grammar.y"
                                      {
        show_error_range((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5455 "src/bison/grammar.c"
    break;

  case 68: /* cond_stmt: IF error  */
#line 464 "src/bison/grammar.y"
               {
        show_error((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5464 "src/bison/grammar.c"
    break;

  case 69: /* else_error: ELSE statement  */
#line 470 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5474 "src/bison/grammar.c"
    break;

  case 70: /* else_error: error ELSE statement  */
#line 475 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5484 "src/bison/grammar.c"
    break;

  case 71: /* jmp_stmt: RETURN expression ';'  */
#line 482 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyloc), (yyvsp[-1].ast)); }
#line 5490 "src/bison/grammar.c"
    break;

  case 72: /* jmp_stmt: RETURN error ';'  */
#line 483 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5499 "src/bison/grammar.c"
    break;

  case 73: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 489 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init((yyloc), current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 5507 "src/bison/grammar.c"
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
#line 5519 "src/bison/grammar.c"
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
#line 5531 "src/bison/grammar.c"
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
#line 5543 "src/bison/grammar.c"
    break;

  case 77: /* iter_stmt: FOR '(' error ')'  */
#line 513 "src/bison/grammar.y"
                        {
        show_error((yylsp[0]), "expected " WHT "';'" RESET " before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5552 "src/bison/grammar.c"
    break;

  case 78: /* iter_stmt: FOR error  */
#line 517 "src/bison/grammar.y"
                {
        show_error((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5561 "src/bison/grammar.c"
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
#line 5573 "src/bison/grammar.c"
    break;

  case 80: /* iter_stmt: FOR '(' error ';' expression.opt ')' statement  */
#line 528 "src/bison/grammar.y"
                                                     {
        show_error((yylsp[-1]), "expected expression before " WHT "')'" RESET "token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5584 "src/bison/grammar.c"
    break;

  case 81: /* iter_stmt: FOR '(' expression.opt ';' error ')' statement  */
#line 534 "src/bison/grammar.y"
                                                     {
        show_error((yylsp[-1]), "expected expression before " WHT "')'" RESET "token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5595 "src/bison/grammar.c"
    break;

  case 83: /* expression: unary_expr '=' logical_or_expr  */
#line 543 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyloc), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 5601 "src/bison/grammar.c"
    break;

  case 84: /* expression: unary_expr '=' error  */
#line 544 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5611 "src/bison/grammar.c"
    break;

  case 85: /* expression: error '=' logical_or_expr  */
#line 549 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-2]), "expected expression before " WHT "'='" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5621 "src/bison/grammar.c"
    break;

  case 86: /* expression.opt: %empty  */
#line 556 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 5627 "src/bison/grammar.c"
    break;

  case 89: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 561 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5636 "src/bison/grammar.c"
    break;

  case 90: /* logical_or_expr: logical_or_expr OR error  */
#line 565 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5646 "src/bison/grammar.c"
    break;

  case 91: /* logical_or_expr: error OR logical_and_expr  */
#line 570 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5656 "src/bison/grammar.c"
    break;

  case 93: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 578 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5665 "src/bison/grammar.c"
    break;

  case 94: /* logical_and_expr: logical_and_expr AND error  */
#line 582 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5675 "src/bison/grammar.c"
    break;

  case 95: /* logical_and_expr: error AND eq_expr  */
#line 587 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5685 "src/bison/grammar.c"
    break;

  case 97: /* eq_expr: eq_expr EQ rel_expr  */
#line 595 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5694 "src/bison/grammar.c"
    break;

  case 98: /* eq_expr: eq_expr EQ error  */
#line 599 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5704 "src/bison/grammar.c"
    break;

  case 99: /* eq_expr: error EQ rel_expr  */
#line 604 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5714 "src/bison/grammar.c"
    break;

  case 101: /* rel_expr: rel_expr REL list_expr  */
#line 612 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5723 "src/bison/grammar.c"
    break;

  case 102: /* rel_expr: rel_expr REL error  */
#line 616 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5733 "src/bison/grammar.c"
    break;

  case 103: /* rel_expr: error REL list_expr  */
#line 621 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5743 "src/bison/grammar.c"
    break;

  case 105: /* list_expr: add_expr DL_DG list_expr  */
#line 629 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5752 "src/bison/grammar.c"
    break;

  case 106: /* list_expr: add_expr COLON list_expr  */
#line 633 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5761 "src/bison/grammar.c"
    break;

  case 107: /* list_expr: add_expr DL_DG error  */
#line 637 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5771 "src/bison/grammar.c"
    break;

  case 108: /* list_expr: add_expr COLON error  */
#line 642 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5781 "src/bison/grammar.c"
    break;

  case 109: /* list_expr: error DL_DG list_expr  */
#line 647 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5791 "src/bison/grammar.c"
    break;

  case 110: /* list_expr: error COLON list_expr  */
#line 652 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5801 "src/bison/grammar.c"
    break;

  case 112: /* add_expr: add_expr ADD mult_expr  */
#line 660 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5810 "src/bison/grammar.c"
    break;

  case 113: /* add_expr: add_expr ADD error  */
#line 664 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5820 "src/bison/grammar.c"
    break;

  case 114: /* add_expr: error ADD mult_expr  */
#line 669 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5830 "src/bison/grammar.c"
    break;

  case 116: /* mult_expr: mult_expr MULT unary_expr  */
#line 677 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5839 "src/bison/grammar.c"
    break;

  case 117: /* mult_expr: mult_expr MULT error  */
#line 681 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5849 "src/bison/grammar.c"
    break;

  case 118: /* mult_expr: error MULT unary_expr  */
#line 686 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5859 "src/bison/grammar.c"
    break;

  case 120: /* unary_expr: unary_ops unary_expr  */
#line 694 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5868 "src/bison/grammar.c"
    break;

  case 126: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 707 "src/bison/grammar.y"
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
#line 5891 "src/bison/grammar.c"
    break;

  case 127: /* arg_expr_list: arg_expr_list ',' expression  */
#line 727 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5897 "src/bison/grammar.c"
    break;

  case 128: /* arg_expr_list: expression  */
#line 728 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5903 "src/bison/grammar.c"
    break;

  case 129: /* arg_expr_list: error  */
#line 729 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5912 "src/bison/grammar.c"
    break;

  case 131: /* arg_expr_list.opt: %empty  */
#line 736 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5918 "src/bison/grammar.c"
    break;

  case 132: /* primary_expr: id  */
#line 739 "src/bison/grammar.y"
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
#line 5933 "src/bison/grammar.c"
    break;

  case 134: /* primary_expr: '(' expression ')'  */
#line 750 "src/bison/grammar.y"
                         {
        if ((yyvsp[-1].ast)) {
            --(yyvsp[-1].ast)->rule_pos.first_column;
            ++(yyvsp[-1].ast)->rule_pos.last_column;
        }
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 5945 "src/bison/grammar.c"
    break;

  case 135: /* primary_expr: '(' error ')'  */
#line 757 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5954 "src/bison/grammar.c"
    break;

  case 136: /* primary_expr: id error  */
#line 761 "src/bison/grammar.y"
               {
        show_error_range((yylsp[0]), "expected " WHT "';'" RESET "\n");
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 5964 "src/bison/grammar.c"
    break;

  case 140: /* type: INT LIST  */
#line 773 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5976 "src/bison/grammar.c"
    break;

  case 141: /* type: FLOAT LIST  */
#line 780 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5988 "src/bison/grammar.c"
    break;

  case 142: /* constant: NUMBER_REAL  */
#line 789 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init((yyloc), K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5994 "src/bison/grammar.c"
    break;

  case 143: /* constant: NUMBER_INT  */
#line 790 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init((yyloc), K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 6000 "src/bison/grammar.c"
    break;

  case 144: /* constant: NIL  */
#line 791 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init((yyloc), K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 6006 "src/bison/grammar.c"
    break;

  case 145: /* string_literal: STR_LITERAL  */
#line 794 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyloc), (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 6015 "src/bison/grammar.c"
    break;


#line 6019 "src/bison/grammar.c"

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

#line 800 "src/bison/grammar.y"


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
