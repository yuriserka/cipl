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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9873

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  638

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
     157,   180,   185,   191,   197,   205,   240,   205,   245,   250,
     245,   260,   261,   264,   265,   266,   272,   285,   290,   297,
     297,   318,   319,   322,   323,   326,   327,   328,   331,   332,
     333,   334,   335,   336,   339,   350,   354,   358,   363,   368,
     374,   380,   386,   391,   398,   399,   405,   408,   411,   417,
     422,   428,   435,   440,   446,   447,   453,   456,   463,   470,
     479,   480,   481,   486,   493,   494,   497,   498,   502,   507,
     514,   515,   519,   524,   531,   532,   536,   541,   548,   549,
     553,   558,   565,   566,   570,   574,   579,   584,   589,   596,
     597,   601,   606,   613,   614,   618,   623,   630,   631,   637,
     638,   639,   640,   643,   644,   664,   665,   666,   672,   673,
     676,   686,   687,   694,   698,   705,   708,   709,   710,   717,
     726,   727,   728,   731
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

#define YYPACT_NINF (-395)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-134)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    5749,  3313,   611,  2613,  9267,  2489,   453,  2922,  4121,  4218,
     191,   235,     8,    11,   -23,   -17,  4042,  4097,    90,    25,
    5781,  5813,  5845,  5877,  5909,  5941,  5973,  6005,  6037,  6069,
    6101,    -7,    49,   127,   170,   454,   849,  1559,  9555,  9280,
    8127,  9291,  9304,  2866,   222,  9315,  8144,  4143,  4249,  4416,
    4471,  7253,  4249,  4249,  6133,  7259,   246,   253,  6165,     9,
    6197,  1116,  7277,  3365,  9328,    41,  3041,  2532,    43,   126,
    -395,  9339,  6229,  6261,  7294,  7311,  7328,  7345,  7362,  7379,
    7396,  7413,  7430,  9352,  9363,   526,    37,  6293,    18,   405,
    9568,    75,  9578,  9591,  1229,  1328,  2352,   648,  2992,   408,
    2306,  1603,  1637,  1674,  2245,   337,    88,    94,  8669,   135,
     144,   182,  8682,   189,  9376,   205,   209,  6325,  6357,  9387,
    9400,  2237,  7157,   488,   183,   878,   913,   965,  1011,    -1,
    9601,   491,  9614,   692,  9624,  1782,  9637,  1934,  9647,  9660,
    9670,  1979,  9683,  2013,  9693,  9706,  9716,   357,  1757,   153,
     212,   226,  6389,   259,    39,  6421,   272,   249,   225,    12,
     254,    68,    73,   548,  1069,  3505,  3598,  7157,  1147,  6453,
    1258,   219,  7447,  9411,  6485,   287,   262,   467,   503,   512,
     169,  6517,    39,  6549,  6581,  6613,  6645,  6677,  6709,  6741,
    6773,  7189,  1295,  7189,  1327,  3442,   257,  9424,   286,  1445,
     536,   278,   382,   544,   312,  6805,  7189,  6837,  7189,   649,
     649,  1359,   315,   554,   321,  6869,  6901,   344,   349,  8695,
     355,  6933,   315,  7189,  7189,  7189,  7189,  6965,  6997,  7029,
    7061,  7093,  3160,  8708,  8721,  8734,   721,  7464,    54,   112,
     573,   319,   331,   808,  1415,  8747,  8161,  8760,  8773,   761,
    8786,   551,   495,  9729,  9739,  9752,   945,  7481,  8144,  9762,
    9775,  3659,  9785,   362,  8178,  7498,  7515,  7532,  7549,  7566,
    7515,  7515,  7583,   295,   340,    17,    45,   368,   383,  7600,
      90,  1525,  1636,  1673,  1708,  1821,  1901,   387,  2866,  2133,
    3232,  3321,   325,  7617,   229,   932,   465,   363,   411,  3243,
    8318,  3779,  8195,  4325,  8223,   396,  8237,  2012,  9435,  2049,
    8212,  7634,  7651,  7668,  7685,  7702,  7651,  7651,  7719,   616,
     156,   163,  9448,    46,    50,   407,   410,  7736,    90,  2085,
    2277,  2388,  2425,  2460,  2653,   431,  2197,   461,  9531,  9544,
     435,  8799,   439,  7753,  7770,  7787,  7804,  7821,  7838,  7855,
    7872,  7889,  8812,  8825,   526,  8838,   450,  9798,  9808,   526,
    1791,  2167,  2543,   793,  7906,  2908,  8178,  4482,  9007,  1404,
    9020,   481,  9033,  9046,  1500,   583,  2360,   997,  3639,   289,
    2332,   727,   951,  1012,  2621,    69,    20,   129,  2573,    67,
    2764,  1494,  7923,  3727,  9459,   466,   126,  2801,   661,  8851,
     458,  7940,  7957,  7974,  7991,  8008,  8025,  8042,  8059,  8076,
    8250,  8264,   526,  8331,  8345,  8358,    22,  8093,  8372,  8212,
    8385,  8399,   441,  8412,   499,  8426,  8439,  1876,   714,  2728,
     506,  3807,  1276,  2500,   745,   819,   856,  3049,   279,   172,
     184,  2837,  3087,   186,  3125,  1870,  8110,  3821,  9472,   480,
     126,  3180,  3403,  8864,  8877,  9059,   379,  9072,  1070,  9085,
    1039,  9098,  1259,  9111,  9124,  9137,  1368,  9150,  1376,  9163,
    9176,  9189,   256,   496,  9821,  9831,   501,  8890,   505,  9202,
    9215,   526,   508,   516,  8903,   518,   523,  8916,   546,  9483,
     559,  3458,  3903,   555,  4179,   596,  8277,  8291,  8453,  1388,
    8466,  1104,  8480,  1046,  8493,  1183,  8507,  8520,  8534,  1199,
    8547,  1360,  8561,  8574,  8588,   281,   567,  8929,   571,  8601,
    8615,   526,   578,   580,  8942,   582,   598,  8955,   605,  9496,
     615,  4296,  4346,   621,  8968,  9844,  9228,  9241,   614,   622,
      89,   633,    99,   107,  2951,  3679,  3505,  3864,  4378,  4436,
    8304,  8628,  8642,   635,   644,   110,   646,   118,   139,  3980,
    7125,  3505,  3948,  4507,  9254,  4539,  4574,  4609,  4644,  4679,
    4714,  4749,  4784,  7157,  4819,  7157,  4854,   650,  9507,   653,
    8655,  4890,  4922,  4954,  4986,  5018,  5050,  5082,  5114,  7221,
    5146,  7221,  5178,   655,  9520,   657,  5210,  7157,  5245,  7157,
     649,   649,  1746,  5281,  7221,  5313,  7221,   649,   649,  2122,
    5345,  5380,   656,   660,  8981,   683,  5416,  5448,   684,   685,
    8994,   688,  7157,  7157,  7157,  7157,  7221,  7221,  7221,  7221,
    5480,  5515,  5550,  5585,  5621,  5653,  5685,  5717
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
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
    -395,  -395,  -395,   673,    84,  -395,  -395,  -395,  -395,  -395,
     545,  -395,   538,     7,  -276,  -394,  -395,   617,    72,    79,
      83,   154,  -395,   159,   207,     0,  -122,  3176,  3897,  3827,
    3676,  2955,  3454,  3233,  1173,  1549,  1925,  -395,  -348,  2301,
     795,     1,  2677,  -388
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   123,    23,   182,   214,   154,   201,
     176,   177,   178,   281,    69,   124,   125,   126,   127,   282,
     283,   284,   128,   285,   286,   287,   116,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   150,   151,    42,
      66,   129,    45,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    44,   493,   486,   396,   251,   473,    24,    62,    58,
     106,   476,    60,   184,    63,   263,    65,    68,   388,   -18,
      31,    44,    73,  -125,   -18,    70,  -128,    24,   309,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,   -18,   -18,    59,
     175,   185,    61,   196,   198,   319,   390,   442,   389,  -128,
     -18,   444,   450,  -125,  -125,  -125,   533,   526,   320,   321,
      74,   110,   113,   115,   516,   343,   152,   153,   482,   187,
     118,   -21,    25,   263,   189,   120,   391,   443,   -70,    26,
     343,   445,    46,    27,    22,   149,   -70,   217,   218,   220,
     566,   -29,    25,   -29,   -29,   -29,   -29,   188,   -29,    26,
     569,   -73,   190,    27,    22,   -29,   -29,   -29,   571,   -29,
     -29,   582,   -29,   -29,   -29,   -29,   -29,   -29,   567,   585,
     158,   -29,   344,   -76,   -29,   -29,   159,   121,   570,     2,
       3,     4,     5,   538,     6,  -129,   572,    75,   -76,   583,
     587,     7,     8,     9,   -76,   273,   274,   586,   275,   276,
     277,   122,   278,   279,    28,   180,   -76,    17,  -129,    29,
     280,   -32,  -126,   335,   335,   115,   115,  -133,   588,  -127,
     329,   329,   200,   553,    28,   319,   161,   439,  -128,    29,
     -80,   -80,    76,   180,   440,  -116,  -116,   522,  -126,  -126,
    -129,    31,   263,    31,   168,  -127,  -127,  -126,    24,   -80,
      24,   -27,   -27,   180,  -128,  -128,    31,    30,    31,   340,
     340,   340,    56,    24,   162,    24,  -129,  -129,   169,   221,
    -126,   164,  -126,    31,    31,    31,    31,    30,   252,   227,
      24,    24,    24,    24,   -75,   192,   194,   342,   166,   199,
     401,  -127,   330,   330,  -118,   172,   331,   331,   336,   337,
     -15,    87,  -128,    88,   183,   -15,    57,   356,   173,  -129,
     174,   -70,   -70,   205,  -127,   207,  -127,   343,   -15,   -15,
      26,   490,    26,   181,    27,  -128,    27,  -128,   215,   395,
     216,   -15,  -129,   186,  -129,    26,   209,    26,   -71,    27,
     401,    27,   401,   400,   -19,   228,   229,   230,   231,   344,
     -79,  -126,    26,    26,    26,    26,    27,    27,    27,    27,
     212,   -73,   -73,   -71,   -71,   211,   386,   332,   332,   -25,
     -25,   -79,   333,   333,  -126,   530,  -125,   449,   346,   -84,
     -84,   -84,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
     -88,   -88,   -88,   -88,   -16,    28,  -127,    28,    74,    18,
      29,   -84,    29,   222,   149,  -125,  -125,  -125,  -125,   149,
      28,   387,    28,   -88,   478,    29,   -73,    29,    74,  -127,
     334,   334,   404,   -84,   -84,   -84,   223,    28,    28,    28,
      28,   224,    29,    29,    29,    29,   -71,   226,   319,   344,
     -77,   485,   488,   115,  -125,   -84,   -84,   411,    30,   392,
      30,   320,   321,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,   -77,   149,    30,   393,    30,   397,   518,    75,   -79,
     -88,   -88,   -88,   -88,   577,   579,  -120,   412,  -120,  -120,
      30,    30,    30,    30,   155,   156,   157,   -79,   446,   593,
     595,   447,   520,   -88,   -88,   525,   528,   115,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -111,  -111,  -111,  -111,
     451,  -111,   452,    77,   -84,   -84,   -84,   -75,  -111,  -111,
    -111,   454,   521,  -120,  -120,   -80,   -80,   403,   612,   613,
     615,   149,   475,   -84,  -111,   618,   619,   621,   264,   -35,
     497,   -35,   -35,   -35,   -35,   492,   -35,   -80,   -80,   -22,
     202,    75,   -77,   -35,   -35,   -35,   310,   -35,   -35,   532,
     -35,   -35,   -35,   -35,   -35,   -35,   -83,   -83,   403,   -35,
     -77,   149,   -35,   -35,  -125,  -125,  -125,   148,   534,   289,
     290,   291,   292,   535,     6,   -24,   -24,   537,   -83,   -83,
     539,     7,     8,     9,   -28,   -28,   115,   115,   540,   322,
     542,     2,     3,     4,   232,   543,     6,   293,  -119,   335,
     335,   115,   115,     7,     8,     9,   329,   329,  -115,  -115,
     323,   324,   325,   191,   326,   327,   -26,   -26,   545,    17,
    -125,  -125,   328,   -80,   -80,   345,   -23,   -23,   547,   335,
     548,   335,   -91,   -91,   -91,   -91,   329,   549,   329,   550,
     340,   340,   340,   552,   335,   -80,   335,   340,   340,   340,
     554,   329,   555,   329,   557,   -91,   574,   576,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,   335,   335,   335,   335,
     558,   590,   592,   329,   329,   329,   329,   560,   330,   330,
    -131,  -131,   331,   331,   562,   596,   564,   598,  -125,  -125,
     339,   565,   233,   234,   235,   236,   563,     6,   -83,   -83,
      76,   603,   568,   605,     7,     8,     9,   580,   330,   610,
     330,   611,   331,   581,   331,   584,   616,   -83,   617,   600,
     237,   -74,   602,   330,   607,   330,   609,   331,   622,   331,
     494,   495,   623,    72,   630,   631,   632,   633,   634,   635,
     636,   637,   -81,   -81,    76,   330,   330,   330,   330,   331,
     331,   331,   331,   332,   332,   625,   626,   627,   333,   333,
     629,   -81,  -125,   -91,   -91,   -91,   -91,   204,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,   346,   -87,   -87,   -87,
     213,     0,   170,   332,     0,   332,   -91,   -91,   333,     0,
     333,  -125,  -125,  -125,   404,   -87,   -87,   -87,   332,   -87,
     332,     0,   353,   333,     0,   333,   334,   334,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,     0,   -87,   -87,     0,
     332,   332,   332,   332,     0,   333,   333,   333,   333,     0,
       0,  -120,   354,  -120,  -125,    43,   334,     0,   334,     0,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,     0,     0,
       0,   334,   249,   334,     0,    43,   347,   -92,   -92,   -92,
     -92,   348,   349,     0,  -125,  -125,     0,     0,   -98,   -98,
     -98,   -98,     0,   334,   334,   334,   334,     0,    86,    89,
     -92,   261,   261,   261,   261,   261,   261,   261,   261,     0,
     261,   -98,   -98,     0,   107,     0,   249,   249,   -88,   -88,
     -88,   -88,     0,     0,   288,   -97,   -97,   -97,   -97,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   -88,   121,
     305,     2,     3,     4,     5,     0,     6,     0,   -97,   -97,
       0,     0,     0,     7,     8,     9,     0,   273,   274,     0,
     275,   276,   277,   122,   278,   279,     0,     0,     0,    17,
       0,     0,   280,   -31,   -34,     0,   -34,   -34,   -34,   -34,
     288,   -34,     0,     0,   171,     0,     0,     0,   -34,   -34,
     -34,     0,   -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,
     -34,     0,   402,   -76,   -34,     0,  -125,   -34,   -34,   179,
       0,     0,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
     -98,   -98,   -98,   -98,   -76,   -76,   -36,   305,   -36,   -36,
     -36,   -36,     0,   -36,  -125,   203,  -125,   179,     0,     0,
     -36,   -36,   -36,   -98,   -36,   -36,     0,   -36,   -36,   -36,
     -36,   -36,   -36,     0,     0,     0,   -36,   179,     0,   -36,
     -36,     0,     0,     0,   249,   249,   249,   -83,   -83,   345,
       0,     0,   -37,     0,   -37,   -37,   -37,   -37,     0,   -37,
       0,   -97,   -97,   -97,   -97,     0,   -37,   -37,   -37,   -83,
     -37,   -37,   249,   -37,   -37,   -37,   -37,   -37,   -37,     0,
       0,   249,   -37,     0,   -97,   -37,   -37,     0,   346,   -85,
     -85,   -85,   249,   261,     0,   404,   -85,   -85,   -85,   369,
     369,   369,   369,   369,   369,   369,   369,   369,     0,     0,
     322,   -85,     2,     3,     4,   232,     0,     6,   -85,   -85,
     -81,   -81,   345,   398,     7,     8,     9,     0,   249,     0,
       0,   323,   324,   325,   193,   326,   327,   305,     0,     0,
      17,     0,   -81,   328,     0,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   -81,   -81,   403,   108,     0,   233,
     234,   235,   236,     0,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     9,   109,     0,   -81,   -81,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   237,   -62,   305,
     -62,   -62,   -62,   -62,   305,   -62,     0,     0,     0,   249,
       0,   369,   -62,   -62,   -62,     0,   -62,   -62,     0,   -62,
     -62,   -62,   -62,   -62,   -62,     0,     0,     0,   -62,     0,
       0,   -62,   -62,     0,   483,     0,   249,   249,     0,     0,
     245,   288,   -89,   -89,   -89,   -89,   422,   422,   422,   422,
     422,   422,   422,   422,   422,     0,     0,   305,   -94,   -94,
     -94,   -94,   249,    83,   422,   -89,   -89,     0,     0,    90,
      93,    93,    93,    93,    93,    93,    93,     0,    93,     0,
       0,   -94,   -94,     0,   245,   245,    46,    47,   523,     0,
     249,   249,    52,    53,     0,   288,     0,    93,    93,    93,
      93,    93,    93,    93,   145,    93,     0,     0,   301,   -33,
       0,   -33,   -33,   -33,   -33,     0,   -33,     0,   -89,   -89,
     -89,   -89,     0,   -33,   -33,   -33,   305,   -33,   -33,     0,
     -33,   -33,   -33,   -33,   -33,   -33,   402,   -79,     0,   -33,
       0,   -89,   -33,   -33,     0,   -59,   -59,     0,   -59,   -59,
     -59,   -59,     0,   -59,     0,     0,     0,     0,   -79,   -79,
     -59,   -59,   -59,     0,   -59,   -59,   305,   -59,   -59,   -59,
     206,   -59,   -59,     0,     0,     0,   -59,   -56,   -56,   -59,
     -56,   -56,   -56,   -56,     0,   -56,     0,   -91,   -91,   -91,
     -91,     0,   -56,   -56,   -56,   301,   -56,   -56,     0,   -56,
     -56,   -56,   208,   -56,   -56,     0,     0,   -91,   -56,     0,
     219,   -56,   233,   234,   235,   236,     0,     6,     0,   -93,
     -93,   -93,   -93,     0,     7,     8,     9,   -94,   -94,   -94,
     -94,     0,   245,   245,   245,   -93,   -93,   -93,   -93,     0,
     237,   -74,   -93,   -93,     0,   249,   249,   249,   402,   -77,
     -94,     0,   249,   249,   249,   480,     0,     0,   -93,     0,
     245,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,   352,
     -77,   -77,   350,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     245,   357,     0,     0,     0,   481,  -120,   365,   373,   373,
     373,   373,   373,   373,   373,   373,   -63,   -99,   -63,   -63,
     -63,   -63,     0,   -63,     0,     0,     0,     0,     0,     0,
     -63,   -63,   -63,     0,   -63,   -63,   245,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,   410,   -63,     0,     0,   -63,
     -63,     0,     0,   418,   426,   426,   426,   426,   426,   426,
     426,   426,     0,     0,     0,   484,     0,   233,   234,   235,
     236,     0,     6,     0,     0,     0,     0,   264,   265,     7,
       8,     9,   109,   270,   271,     0,   373,   373,   373,   373,
     373,   373,   373,   470,   373,   237,   -39,   301,   -39,   -39,
     -39,   -39,   301,   -39,     0,     0,     0,   245,     0,   479,
     -39,   -39,   -39,     0,   -39,   -39,     0,   -39,   -39,   -39,
     -39,   -39,   -39,     0,     0,     0,   -39,     0,     0,   -39,
     -39,     0,     0,     0,   245,   245,   246,    78,   -92,   -92,
     -92,   -92,    79,    80,   426,   426,   426,   426,   426,   426,
     426,   513,   426,     0,     0,   301,     0,     0,   -92,     0,
     245,     0,   519,     0,     0,   258,   258,   258,   258,   258,
     258,   258,   258,     0,   258,     0,     0,     0,     0,     0,
     246,   246,    77,   -87,   -87,   -87,     0,     0,   245,   245,
       0,     0,     0,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   -87,     0,   302,     0,     0,   -43,     0,   -43,
     -43,   -43,   -43,     0,   -43,     0,   -98,   -98,   -98,   -98,
       0,   -43,   -43,   -43,   301,   -43,   -43,     0,   -43,   -43,
     -43,   -43,   -43,   -43,     0,     0,   -98,   -43,     0,     0,
     -43,   -43,     0,     0,   -38,     0,   -38,   -38,   -38,   -38,
       0,   -38,     0,   -97,   -97,   -97,   -97,     0,   -38,   -38,
     -38,     0,   -38,   -38,   301,   -38,   -38,   -38,   -38,   -38,
     -38,     0,     0,   -97,   -38,     0,     0,   -38,   -38,   -40,
       0,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,     0,
       0,   302,     0,   -40,   -40,   -40,     0,   -40,   -40,     0,
     -40,   -40,   -40,   -40,   -40,   -40,     0,     0,     0,   -40,
       0,     0,   -40,   -40,     0,     0,     0,   614,     0,   233,
     234,   235,   236,     0,     6,     0,     0,     0,   246,   246,
     246,     7,     8,     9,   310,   311,   312,   313,   314,   315,
     316,   317,     0,   245,   245,   245,     0,   237,   -74,     0,
     245,   245,   245,     0,     0,     0,   246,   318,     0,  -117,
    -117,    77,   -85,   -85,   -85,   246,     0,     0,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,   246,   258,     0,     0,
       0,   -85,     0,   366,   366,   366,   366,   366,   366,   366,
     366,   366,   -41,  -131,   -41,   -41,   -41,   -41,     0,   -41,
       0,     0,     0,     0,     0,     0,   -41,   -41,   -41,     0,
     -41,   -41,   246,   -41,   -41,   -41,   -41,   -41,   -41,     0,
       0,   302,   -41,     0,     0,   -41,   -41,     0,     0,   419,
     419,   419,   419,   419,   419,   419,   419,   419,     0,     0,
       0,   524,     0,   233,   234,   235,   236,     0,     6,     0,
       0,     0,     0,   310,   311,     7,     8,     9,   109,   316,
     317,     0,   366,   366,   366,   366,   366,   366,   366,   366,
     366,   237,   -42,   302,   -42,   -42,   -42,   -42,   302,   -42,
       0,     0,     0,   246,     0,   366,   -42,   -42,   -42,     0,
     -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,     0,
       0,     0,   -42,     0,     0,   -42,   -42,     0,     0,     0,
     246,   246,   247,   -89,   -89,   -89,   -89,     0,     0,     0,
     419,   419,   419,   419,   419,   419,   419,   419,   419,     0,
       0,   302,     0,   -89,     0,     0,   246,     0,   419,     0,
       0,   259,   259,   259,   259,   259,   259,   259,   259,     0,
     259,     0,     0,     0,     0,     0,   247,   247,   -94,   -94,
     -94,   -94,     0,     0,   246,   246,     0,     0,     0,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   -94,     0,
     303,     0,     0,   -55,     0,   -55,   -55,   -55,   -55,     0,
     -55,     0,   -93,   -93,   -93,   -93,     0,   -55,   -55,   -55,
     302,   -55,   -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,   -93,   -55,     0,     0,   -55,   -55,     0,     0,
     -11,     0,   -11,   -11,   -11,   -11,     0,   -11,     0,     0,
       0,     0,     0,     0,   -11,   -11,   -11,     0,   -11,   -11,
     302,   -11,   -11,   -11,   -11,   -11,   -11,     0,     0,     0,
     -11,     0,     0,   -11,   -11,   -39,   -39,     0,   -39,   -39,
     -39,   -39,     0,   -39,     0,     0,     0,   303,     0,     0,
     -39,   -39,   -39,     0,   -39,   -39,     0,   -39,   -39,   -39,
     -39,   -39,   -39,     0,     0,     0,   -39,     0,     0,   -39,
       0,     0,     0,   620,     0,   233,   234,   235,   236,     0,
       6,     0,     0,     0,   247,   247,   247,     7,     8,     9,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,     0,   246,
     246,   246,     0,   237,   -74,     0,   246,   246,   246,     0,
       0,     0,   247,  -131,     0,  -131,  -131,     0,     0,     0,
       0,   247,     0,     0,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,   247,   259,     0,     0,     0,     0,     0,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   -10,  -132,
     -10,   -10,   -10,   -10,     0,   -10,     0,     0,     0,     0,
       0,     0,   -10,   -10,   -10,     0,   -10,   -10,   247,   -10,
     -10,   -10,   -10,   -10,   -10,     0,     0,   303,   -10,     0,
       0,   -10,   -10,     0,     0,   420,   420,   420,   420,   420,
     420,   420,   420,   420,    46,    47,    48,    49,    50,    51,
      52,    53,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,   167,     0,     0,     0,   307,    55,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   -43,   -43,   303,
     -43,   -43,   -43,   -43,   303,   -43,     0,     0,     0,   247,
       0,   367,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,
     -43,   -43,   -43,   -43,   -43,     0,     0,     0,   -43,     0,
       0,   -43,     0,    46,    47,    48,   247,   247,   248,    52,
      53,     0,     0,     0,     0,     0,   420,   420,   420,   420,
     420,   420,   420,   420,   420,     0,     0,   303,     0,   264,
     265,   266,   247,     0,   420,   270,   271,   260,   260,   260,
     260,   260,   260,   260,   260,     0,   260,     0,     0,    46,
      47,    48,   248,   248,    51,    52,    53,   264,   265,   266,
     247,   247,   269,   270,   271,   260,   260,   260,   260,   260,
     260,   260,   260,   260,     0,     0,   304,     0,   -38,   -38,
       0,   -38,   -38,   -38,   -38,     0,   -38,     0,     0,     0,
       0,     0,     0,   -38,   -38,   -38,   303,   -38,   -38,     0,
     -38,   -38,   -38,   -38,   -38,   -38,     0,     0,     0,   -38,
       0,     0,   -38,     0,     0,   -40,   -40,     0,   -40,   -40,
     -40,   -40,     0,   -40,     0,     0,     0,     0,     0,     0,
     -40,   -40,   -40,     0,   -40,   -40,   303,   -40,   -40,   -40,
     -40,   -40,   -40,     0,     0,     0,   -40,     0,     0,   -40,
     -41,   -41,     0,   -41,   -41,   -41,   -41,     0,   -41,     0,
       0,     0,     0,   304,     0,   -41,   -41,   -41,     0,   -41,
     -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,     0,
    -125,   -41,     0,     0,   -41,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,     0,     0,     0,   310,   311,   312,
     248,   248,   248,   316,   317,     0,     0,     0,  -125,  -125,
    -125,     0,     0,     0,     0,   247,   247,   247,     0,     0,
       0,     0,   247,   247,   247,     0,     0,     0,   248,   264,
     265,   266,   267,   268,   269,   270,   271,   248,     0,     0,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,   248,   260,
       0,     0,   272,     0,   119,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   -53,  -130,   -53,   -53,   -53,   -53,
       0,   -53,     0,     0,     0,     0,     0,     0,   -53,   -53,
     -53,     0,   -53,   -53,   248,   -53,   -53,   -53,   -53,   -53,
     -53,     0,     0,   304,   -53,     0,     0,   -53,   -53,     0,
       0,   421,   421,   421,   421,   421,   421,   421,   421,   421,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   264,   265,
     266,   267,   268,   269,   270,   271,     0,     0,     0,     0,
       0,     0,  -132,  -132,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   -42,   -42,   304,   -42,   -42,   -42,   -42,
     304,   -42,     0,     0,     0,   248,     0,   368,   -42,   -42,
     -42,     0,   -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,
     -42,     0,     0,     0,   -42,     0,     0,   -42,     0,     0,
       0,     0,   248,   248,   250,     0,     0,     0,     0,     0,
       0,     0,   421,   421,   421,   421,   421,   421,   421,   421,
     421,     0,     0,   304,     0,     0,     0,     0,   248,     0,
     421,     0,     0,   262,   262,   262,   262,   262,   262,   262,
     262,     0,   262,     0,     0,   310,   311,   312,   250,   250,
     315,   316,   317,     0,     0,     0,   248,   248,     0,     0,
       0,   262,   262,   262,   262,   262,   262,   262,   262,   262,
       0,     0,   306,     0,     0,   -52,     0,   -52,   -52,   -52,
     -52,     0,   -52,     0,     0,     0,     0,     0,     0,   -52,
     -52,   -52,   304,   -52,   -52,     0,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,     0,   -52,     0,     0,   -52,   -52,
       0,     0,   -54,     0,   -54,   -54,   -54,   -54,     0,   -54,
       0,     0,     0,     0,     0,     0,   -54,   -54,   -54,     0,
     -54,   -54,   304,   -54,   -54,   -54,   -54,   -54,   -54,     0,
       0,     0,   -54,     0,     0,   -54,   -54,   -55,   -55,     0,
     -55,   -55,   -55,   -55,     0,   -55,     0,     0,     0,   306,
       0,     0,   -55,   -55,   -55,     0,   -55,   -55,     0,   -55,
     -55,   -55,   -55,   -55,   -55,     0,     0,    84,   -55,     0,
       0,   -55,   251,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,     0,     0,     0,     0,     0,   250,   250,   250,     0,
       0,     0,     0,     0,     0,  -120,  -120,    85,     0,     0,
       0,   248,   248,   248,     0,     0,     0,     0,   248,   248,
     248,     0,     0,     0,   250,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,   250,     0,  -109,  -109,  -109,  -109,     0,
    -109,     0,     0,     0,   250,   262,     0,  -109,  -109,  -109,
    -106,   370,   370,   370,   370,   370,   370,   370,   370,   370,
       0,     0,   308,  -109,     2,     3,     4,   232,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
     250,     0,   242,   275,   276,   277,   573,   278,   279,   306,
       0,     0,    17,     0,     0,   280,     0,   423,   423,   423,
     423,   423,   423,   423,   423,   423,     0,     0,     0,    46,
      47,    48,    49,    95,    51,    52,    53,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   242,   242,     0,     0,
     370,   370,   370,   370,   370,   370,   370,   370,   370,     0,
       0,   306,   137,     0,   141,   143,   306,     0,     0,     0,
     298,   250,    84,   370,     0,     0,     0,     0,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,   310,   311,   312,   313,
     314,   315,   316,   317,     0,     0,     0,     0,   250,   250,
    -120,  -120,    85,     0,     0,     0,     0,     0,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   -53,   -53,   306,
     -53,   -53,   -53,   -53,   250,   -53,   423,     0,     0,     0,
       0,     0,   -53,   -53,   -53,     0,   -53,   -53,     0,   -53,
     -53,   -53,   -53,   -53,   -53,     0,     0,     0,   -53,     0,
       0,   -53,   250,   250,     0,   -52,   -52,   298,   -52,   -52,
     -52,   -52,     0,   -52,     0,     0,     0,     0,     0,     0,
     -52,   -52,   -52,     0,   -52,   -52,     0,   -52,   -52,   -52,
     -52,   -52,   -52,     0,     0,     0,   -52,     0,   306,   -52,
       0,  -125,     0,     0,   242,   242,   242,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,     0,     0,     0,     0,     0,
     -54,   -54,     0,   -54,   -54,   -54,   -54,     0,   -54,  -125,
    -125,  -125,   242,   238,     0,   -54,   -54,   -54,   306,   -54,
     -54,     0,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
       0,   -54,   242,     0,   -54,     0,     0,     0,     0,     0,
       0,   375,   242,   242,   242,   382,   383,   242,     0,     0,
       0,   105,     0,     0,     0,     0,     0,   238,   238,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,     0,   242,     0,
     244,   405,   -92,   -92,   -92,   -92,   406,   407,   147,     0,
       0,   294,  -132,     0,  -132,  -132,     0,   428,   298,   298,
     298,   435,   436,   298,     0,   -92,   -92,   250,   250,   250,
      92,     0,     0,     0,   250,   250,   250,     0,     0,     0,
       0,     0,     0,     0,   244,   244,     0,     0,   242,   242,
     242,   462,     0,   466,   468,     0,   242,     0,     0,   298,
       0,   139,     0,    -4,   298,     0,     0,     0,   300,   242,
      46,    47,    48,    49,    50,    51,    52,    53,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,     0,     0,     0,     0,
       0,     0,    54,    55,     0,     0,   242,   242,   294,     0,
       0,  -130,     0,  -130,  -130,     0,   298,   298,   298,   505,
       0,   509,   511,     0,   298,     0,   114,   298,     2,     3,
       4,   232,   242,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,     0,   238,   238,   238,     0,     0,
       0,     0,     0,     0,   -74,     0,    17,     0,     0,     0,
     242,   242,     0,     0,   -12,   300,   -12,   -12,   -12,   -12,
       0,   -12,     0,   238,     0,     0,     0,     0,   -12,   -12,
     -12,     0,   -12,   -12,     0,   -12,   -12,   -12,   -12,   -12,
     -12,     0,     0,   238,   -12,     0,   298,   -12,   -12,     0,
       0,     0,   244,   244,   244,     0,     0,     0,   385,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,   -65,
       0,   -65,   -65,   -65,   -65,     0,   -65,     0,     0,   238,
     244,   243,    55,   -65,   -65,   -65,   298,   -65,   -65,     0,
     -65,   -65,   -65,   -65,   -65,   -65,     0,     0,     0,   -65,
     244,     0,   -65,   -65,   438,     0,     0,     0,   372,   244,
     244,   244,   244,   244,   244,   244,   195,     0,     2,     3,
       4,   232,     0,     6,     0,   243,   243,     0,     0,     0,
       7,     8,     9,     0,     0,     0,   244,   472,     0,     0,
     294,     0,     0,     0,   -74,   294,    17,     0,     0,   299,
     238,     0,     0,     0,   425,   300,   300,   300,   300,   300,
     300,   300,     0,     0,     0,   242,   242,   242,     0,     0,
       0,     0,   242,   242,   242,     0,     0,   238,   238,     0,
       0,     0,     0,     0,     0,     0,   244,   244,   244,   244,
     464,   244,   244,     0,   244,   515,     0,   300,   294,     0,
       0,     0,   300,   238,     0,     0,     0,   244,     0,   197,
       0,     2,     3,     4,   232,     0,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
       0,   238,   238,     0,   244,   244,   299,   -74,     0,    17,
       0,     0,     0,     0,   300,   300,   300,   300,   507,   300,
     300,     0,   300,     0,     0,   300,   264,   265,   266,   267,
     244,   269,   270,   271,     0,     0,     0,   294,     0,     0,
     358,     0,     0,   243,   243,   243,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,     0,     0,     0,     0,   244,   244,
     308,     0,     2,     3,     4,   232,     0,     6,  -120,     0,
     359,   243,     0,   241,     7,     8,     9,   294,     0,     0,
       0,   275,   276,   277,   575,   278,   279,     0,     0,     0,
      17,   243,     0,   280,   300,     0,     0,     0,     0,     0,
     243,   243,   243,   243,   243,   243,   243,   101,   489,     0,
       2,     3,     4,   232,     0,     6,     0,   241,   241,     0,
       0,     0,     7,     8,     9,     0,     0,   243,     0,     0,
       0,     0,   135,     0,   300,     0,   -74,     0,    17,     0,
       0,   297,     0,     0,     0,     0,   299,   299,   299,   299,
     299,   299,   299,     0,     0,     0,   238,   238,   238,     0,
       0,     0,     0,   238,   238,   238,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,     0,     0,     0,   243,   243,   243,
     243,     0,   243,   243,     0,   243,     0,     0,   299,   409,
       0,  -103,  -103,   299,   310,   311,   312,   313,   243,   315,
     316,   317,   529,     0,     2,     3,     4,   232,     0,     6,
       0,     0,     0,   244,   244,   244,     7,     8,     9,     0,
     244,   244,   244,     0,   240,   243,   243,     0,   297,     0,
     -74,     0,    17,     0,     0,   299,   299,   299,   299,     0,
     299,   299,     0,   299,     0,   578,   299,     2,     3,     4,
     232,   243,     6,     0,     0,     0,    97,     0,     0,     7,
       8,     9,     0,     0,     0,   241,   241,   241,   240,   240,
       0,     0,     0,   -74,     0,    17,     0,     0,     0,   243,
     243,     0,   133,     0,   -64,     0,   -64,   -64,   -64,   -64,
       0,   -64,   296,   241,   239,     0,     0,     0,   -64,   -64,
     -64,     0,   -64,   -64,     0,   -64,   -64,   -64,   -64,   -64,
     -64,     0,     0,   241,   -64,   299,     0,   -64,   -64,     0,
       0,     0,     0,   241,   241,   381,     0,    99,   241,   594,
       0,     2,     3,     4,   232,     0,     6,     0,   239,   239,
       0,     0,     0,     7,     8,     9,     0,     0,     0,   241,
       0,   131,     0,     0,     0,   299,     0,   -74,     0,    17,
       0,   322,   295,     2,     3,     4,   232,     0,     6,   297,
     297,   434,     0,     0,   297,     7,     8,     9,     0,   296,
       0,     0,   323,   324,   325,   589,   326,   327,     0,     0,
       0,    17,     0,     0,   328,     0,     0,     0,     0,   241,
     241,   460,     0,     0,     0,     0,     0,   241,     0,     0,
     297,     0,     0,     0,     0,   297,   240,   240,   240,     0,
     241,     0,     0,    64,     0,     2,     3,     4,   232,     0,
       6,     0,     0,     0,   243,   243,   243,     7,     8,     9,
       0,   243,   243,   243,   240,     0,     0,   241,   241,   295,
       0,     0,     0,    17,     0,     0,     0,   297,   297,   503,
       0,     0,     0,     0,   240,   297,     0,     0,   297,     0,
       0,     0,     0,   241,   377,   240,     0,     0,    67,   240,
     233,   234,   235,   236,     0,     6,   239,   239,   239,     0,
       0,     0,     7,     8,     9,     0,     0,     0,     0,     0,
     240,   241,   241,     0,  -110,  -110,  -110,  -110,   237,  -110,
       0,     0,     0,     0,   239,     0,  -110,  -110,  -110,     0,
     430,   296,     0,     0,    91,   296,   253,   254,   255,   256,
       0,     6,  -110,     0,   239,     0,     0,   297,     7,     8,
       9,     0,     0,     0,     0,   379,     0,     0,     0,   239,
     240,   458,     0,     0,   257,     0,     0,     0,   240,     0,
     -14,   296,   -14,   -14,   -14,   -14,   296,   -14,     0,     0,
     239,   240,     0,     0,   -14,   -14,   -14,   297,   -14,   -14,
       0,   -14,   -14,   -14,   -14,   -14,   -14,     0,     0,     0,
     -14,   432,     0,   -14,   -14,   295,     0,     0,   240,   240,
       0,  -112,  -112,  -112,  -112,     0,  -112,     0,   296,   501,
       0,     0,     0,  -112,  -112,  -112,   296,     0,     0,   296,
     456,     0,     0,     0,   240,     0,     0,     0,   239,  -112,
      94,   295,   253,   254,   255,   256,   295,     6,     0,     0,
       0,   239,     0,     0,     7,     8,     9,     0,     0,     0,
       0,     0,   240,   240,     0,     0,   241,   241,   241,     0,
     257,     0,     0,   241,   241,   241,     0,     0,   239,   239,
       0,     0,     0,     0,     0,     0,   -65,   -65,   499,   -65,
     -65,   -65,   -65,     0,   -65,     0,   295,     0,   296,   295,
       0,   -65,   -65,   -65,   239,   -65,   -65,     0,   -65,   -65,
     -65,   -65,   -65,   -65,     0,     0,     0,   -65,     0,     0,
     -65,     0,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
       0,     0,   239,   239,     0,     0,   -64,   -64,   296,   -64,
     -64,   -64,   -64,     0,   -64,  -107,     0,  -107,  -107,     0,
       0,   -64,   -64,   -64,     0,   -64,   -64,     0,   -64,   -64,
     -64,   -64,   -64,   -64,     0,     0,     0,   -64,   295,   -30,
     -64,   -30,   -30,   -30,   -30,     0,   -30,     0,     0,     0,
       0,     0,     0,   -30,   -30,   -30,     0,   -30,   -30,     0,
     -30,   -30,   -30,   -30,   -30,   -30,     0,     0,     0,   -30,
       0,     0,   -30,   -30,     0,     0,     0,    96,   295,   253,
     254,   255,   256,     0,     6,     0,     0,   240,   240,   240,
       0,     7,     8,     9,   240,   240,   240,   -13,     0,   -13,
     -13,   -13,   -13,     0,   -13,     0,     0,   257,     0,     0,
       0,   -13,   -13,   -13,     0,   -13,   -13,     0,   -13,   -13,
     -13,   -13,   -13,   -13,     0,     0,     0,   -13,     0,     0,
     -13,   -13,    98,     0,   253,   254,   255,   256,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,   239,   239,   239,
       0,     0,   257,     0,   239,   239,   239,   -30,   -30,     0,
     -30,   -30,   -30,   -30,  -107,   -30,     0,     0,     0,     0,
       0,     0,   -30,   -30,   -30,     0,   -30,   -30,     0,   -30,
     -30,   -30,   -30,   -30,   -30,     0,     0,     0,   -30,     0,
     -48,   -30,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,
       0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,   -48,
       0,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,     0,
     -48,     0,     0,   -48,   -48,   -49,     0,   -49,   -49,   -49,
     -49,     0,   -49,     0,     0,     0,     0,     0,     0,   -49,
     -49,   -49,     0,   -49,   -49,     0,   -49,   -49,   -49,   -49,
     -49,   -49,     0,     0,     0,   -49,     0,     0,   -49,   -49,
     -44,     0,   -44,   -44,   -44,   -44,     0,   -44,     0,     0,
       0,     0,     0,     0,   -44,   -44,   -44,     0,   -44,   -44,
       0,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,
     -44,     0,     0,   -44,   -44,   -47,     0,   -47,   -47,   -47,
     -47,     0,   -47,     0,     0,     0,     0,     0,     0,   -47,
     -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,   -47,
     -47,   -47,     0,     0,     0,   -47,     0,     0,   -47,   -47,
     -50,     0,   -50,   -50,   -50,   -50,     0,   -50,     0,     0,
       0,     0,     0,     0,   -50,   -50,   -50,     0,   -50,   -50,
       0,   -50,   -50,   -50,   -50,   -50,   -50,     0,     0,     0,
     -50,     0,     0,   -50,   -50,   -45,     0,   -45,   -45,   -45,
     -45,     0,   -45,     0,     0,     0,     0,     0,     0,   -45,
     -45,   -45,     0,   -45,   -45,     0,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,     0,   -45,     0,     0,   -45,   -45,
     -51,     0,   -51,   -51,   -51,   -51,     0,   -51,     0,     0,
       0,     0,     0,     0,   -51,   -51,   -51,     0,   -51,   -51,
       0,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,
     -51,     0,     0,   -51,   -51,   -46,     0,   -46,   -46,   -46,
     -46,     0,   -46,     0,     0,     0,     0,     0,     0,   -46,
     -46,   -46,     0,   -46,   -46,     0,   -46,   -46,   -46,   -46,
     -46,   -46,     0,     0,     0,   -46,     0,     0,   -46,   -46,
     -59,     0,   -59,   -59,   -59,   -59,     0,   -59,     0,     0,
       0,     0,     0,     0,   -59,   -59,   -59,     0,   -59,   -59,
       0,   -59,   -59,   -59,   597,   -59,   -59,     0,     0,     0,
     -59,     0,     0,   -59,   -59,   -56,     0,   -56,   -56,   -56,
     -56,     0,   -56,     0,     0,     0,     0,     0,     0,   -56,
     -56,   -56,     0,   -56,   -56,     0,   -56,   -56,   -56,   599,
     -56,   -56,     0,     0,     0,   -56,     0,     0,   -56,   -56,
     -48,   -48,     0,   -48,   -48,   -48,   -48,     0,   -48,     0,
       0,     0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,
     -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,
       0,   -48,   -49,   -49,   -48,   -49,   -49,   -49,   -49,     0,
     -49,     0,     0,     0,     0,     0,     0,   -49,   -49,   -49,
       0,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,     0,   -49,   -44,   -44,   -49,   -44,   -44,   -44,
     -44,     0,   -44,     0,     0,     0,     0,     0,     0,   -44,
     -44,   -44,     0,   -44,   -44,     0,   -44,   -44,   -44,   -44,
     -44,   -44,     0,     0,     0,   -44,   -47,   -47,   -44,   -47,
     -47,   -47,   -47,     0,   -47,     0,     0,     0,     0,     0,
       0,   -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,
     -47,   -47,   -47,   -47,     0,     0,     0,   -47,   -50,   -50,
     -47,   -50,   -50,   -50,   -50,     0,   -50,     0,     0,     0,
       0,     0,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,
     -50,   -50,   -50,   -50,   -50,   -50,     0,     0,     0,   -50,
     -45,   -45,   -50,   -45,   -45,   -45,   -45,     0,   -45,     0,
       0,     0,     0,     0,     0,   -45,   -45,   -45,     0,   -45,
     -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
       0,   -45,   -51,   -51,   -45,   -51,   -51,   -51,   -51,     0,
     -51,     0,     0,     0,     0,     0,     0,   -51,   -51,   -51,
       0,   -51,   -51,     0,   -51,   -51,   -51,   -51,   -51,   -51,
       0,     0,     0,   -51,   -46,   -46,   -51,   -46,   -46,   -46,
     -46,     0,   -46,     0,     0,     0,     0,     0,     0,   -46,
     -46,   -46,     0,   -46,   -46,     0,   -46,   -46,   -46,   -46,
     -46,   -46,     0,     0,     0,   -46,   -59,   -59,   -46,   -59,
     -59,   -59,   -59,     0,   -59,     0,     0,     0,     0,     0,
       0,   -59,   -59,   -59,     0,   -59,   -59,     0,   -59,   -59,
     -59,   604,   -59,   -59,     0,     0,     0,   -59,   -56,   -56,
     -59,   -56,   -56,   -56,   -56,     0,   -56,     0,     0,     0,
       0,     0,     0,   -56,   -56,   -56,     0,   -56,   -56,     0,
     -56,   -56,   -56,   606,   -56,   -56,     0,     0,     0,   -56,
       0,   -61,   -56,   -61,   -61,   -61,   -61,     0,   -61,     0,
       0,     0,     0,     0,     0,   -61,   -61,   -61,     0,   -61,
     -61,     0,   -61,   -61,   -61,   -61,   -61,   -61,     0,     0,
       0,   -61,     0,     0,   -61,   -61,   -58,     0,   -58,   -58,
     -58,   -58,     0,   -58,     0,     0,     0,     0,     0,     0,
     -58,   -58,   -58,     0,   -58,   -58,     0,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,   -58,     0,     0,   -58,
     -58,   -61,   -61,     0,   -61,   -61,   -61,   -61,     0,   -61,
       0,     0,     0,     0,     0,     0,   -61,   -61,   -61,     0,
     -61,   -61,     0,   -61,   -61,   -61,   -61,   -61,   -61,     0,
       0,     0,   -61,   -58,   -58,   -61,   -58,   -58,   -58,   -58,
       0,   -58,     0,     0,     0,     0,     0,     0,   -58,   -58,
     -58,     0,   -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,
     -58,     0,     0,     0,   -58,     0,   -60,   -58,   -60,   -60,
     -60,   -60,     0,   -60,     0,     0,     0,     0,     0,     0,
     -60,   -60,   -60,     0,   -60,   -60,     0,   -60,   -60,   -60,
     -60,   -60,   -60,     0,     0,     0,   -60,     0,     0,   -60,
     -60,   -57,     0,   -57,   -57,   -57,   -57,     0,   -57,     0,
       0,     0,     0,     0,     0,   -57,   -57,   -57,     0,   -57,
     -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,   -57,     0,     0,   -57,   -57,   -60,   -60,     0,   -60,
     -60,   -60,   -60,     0,   -60,     0,     0,     0,     0,     0,
       0,   -60,   -60,   -60,     0,   -60,   -60,     0,   -60,   -60,
     -60,   -60,   -60,   -60,     0,     0,     0,   -60,   -57,   -57,
     -60,   -57,   -57,   -57,   -57,     0,   -57,     0,     0,     0,
       0,     0,     0,   -57,   -57,   -57,     0,   -57,   -57,     0,
     -57,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,   -57,
       0,   -67,   -57,   -67,   -67,   -67,   -67,     0,   -67,     0,
       0,     0,     0,     0,     0,   -67,   -67,   -67,     0,   -67,
     -67,     0,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,
       0,   -67,     0,     0,   -67,   -67,   -68,     0,   -68,   -68,
     -68,   -68,     0,   -68,     0,     0,     0,     0,     0,     0,
     -68,   -68,   -68,     0,   -68,   -68,     0,   -68,   -68,   -68,
     -68,   -68,   -68,     0,     0,     0,   -68,     0,     0,   -68,
     -68,   -69,     0,   -69,   -69,   -69,   -69,     0,   -69,     0,
       0,     0,     0,     0,     0,   -69,   -69,   -69,     0,   -69,
     -69,     0,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,
       0,   -69,     0,     0,   -69,   -69,   -66,     0,   -66,   -66,
     -66,   -66,     0,   -66,     0,     0,     0,     0,     0,     0,
     -66,   -66,   -66,     0,   -66,   -66,     0,   -66,   -66,   -66,
     -66,   -66,   -66,     0,     0,     0,   -66,     0,     0,   -66,
     -66,   -67,   -67,     0,   -67,   -67,   -67,   -67,     0,   -67,
       0,     0,     0,     0,     0,     0,   -67,   -67,   -67,     0,
     -67,   -67,     0,   -67,   -67,   -67,   -67,   -67,   -67,     0,
       0,     0,   -67,   -68,   -68,   -67,   -68,   -68,   -68,   -68,
       0,   -68,     0,     0,     0,     0,     0,     0,   -68,   -68,
     -68,     0,   -68,   -68,     0,   -68,   -68,   -68,   -68,   -68,
     -68,     0,     0,     0,   -68,   -69,   -69,   -68,   -69,   -69,
     -69,   -69,     0,   -69,     0,     0,     0,     0,     0,     0,
     -69,   -69,   -69,     0,   -69,   -69,     0,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,     0,   -69,   -66,   -66,   -69,
     -66,   -66,   -66,   -66,     0,   -66,     0,     0,     0,     0,
       0,     0,   -66,   -66,   -66,     0,   -66,   -66,     0,   -66,
     -66,   -66,   -66,   -66,   -66,     0,     0,     0,   -66,    -3,
       1,   -66,     2,     3,     4,     5,     0,     6,     0,     0,
       0,     0,     0,     0,     7,     8,     9,     0,    10,    11,
       0,    12,    13,    14,     0,    15,    16,     0,     0,     0,
      17,    -2,    71,    18,     2,     3,     4,     5,     0,     6,
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
      -7,    -7,     0,    -7,    -7,     0,     0,     0,    -7,   -39,
     -39,    -7,   -39,   -39,   -39,   -39,     0,   -39,     0,     0,
       0,     0,     0,     0,   -39,   -39,   -39,     0,   -39,   -39,
       0,   -39,   -39,   -39,     0,   -39,   -39,     0,     0,     0,
     -39,    -9,    -9,   -39,    -9,    -9,    -9,    -9,     0,    -9,
       0,     0,     0,     0,     0,     0,    -9,    -9,    -9,     0,
      -9,    -9,     0,    -9,    -9,    -9,     0,    -9,    -9,     0,
       0,     0,    -9,   -43,   -43,    -9,   -43,   -43,   -43,   -43,
       0,   -43,     0,     0,     0,     0,     0,     0,   -43,   -43,
     -43,     0,   -43,   -43,     0,   -43,   -43,   -43,     0,   -43,
     -43,     0,     0,     0,   -43,   -38,   -38,   -43,   -38,   -38,
     -38,   -38,     0,   -38,     0,     0,     0,     0,     0,     0,
     -38,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,
       0,   -38,   -38,     0,     0,     0,   -38,   -40,   -40,   -38,
     -40,   -40,   -40,   -40,     0,   -40,     0,     0,     0,     0,
       0,     0,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,
     -40,   -40,     0,   -40,   -40,     0,     0,     0,   -40,   -41,
     -41,   -40,   -41,   -41,   -41,   -41,     0,   -41,     0,     0,
       0,     0,     0,     0,   -41,   -41,   -41,     0,   -41,   -41,
       0,   -41,   -41,   -41,     0,   -41,   -41,     0,     0,     0,
     -41,   -42,   -42,   -41,   -42,   -42,   -42,   -42,     0,   -42,
       0,     0,     0,     0,     0,     0,   -42,   -42,   -42,     0,
     -42,   -42,     0,   -42,   -42,   -42,     0,   -42,   -42,     0,
       0,     0,   -42,   -55,   -55,   -42,   -55,   -55,   -55,   -55,
       0,   -55,     0,     0,     0,     0,     0,     0,   -55,   -55,
     -55,     0,   -55,   -55,     0,   -55,   -55,   -55,     0,   -55,
     -55,     0,     0,     0,   -55,   -53,   -53,   -55,   -53,   -53,
     -53,   -53,     0,   -53,     0,     0,     0,     0,     0,     0,
     -53,   -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,
       0,   -53,   -53,     0,     0,     0,   -53,   -52,   -52,   -53,
     -52,   -52,   -52,   -52,     0,   -52,     0,     0,     0,     0,
       0,     0,   -52,   -52,   -52,     0,   -52,   -52,     0,   -52,
     -52,   -52,     0,   -52,   -52,     0,     0,     0,   -52,    -5,
      -5,   -52,    -5,    -5,    -5,    -5,     0,    -5,     0,     0,
       0,     0,     0,     0,    -5,    -5,    -5,     0,    -5,    -5,
       0,    -5,    -5,    -5,     0,    -5,    -5,     0,     0,     0,
      -5,   -54,   -54,    -5,   -54,   -54,   -54,   -54,     0,   -54,
       0,     0,     0,     0,     0,     0,   -54,   -54,   -54,     0,
     -54,   -54,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,
       0,     0,   -54,   -11,   -11,   -54,   -11,   -11,   -11,   -11,
       0,   -11,     0,     0,     0,     0,     0,     0,   -11,   -11,
     -11,     0,   -11,   -11,     0,   -11,   -11,   -11,     0,   -11,
     -11,     0,     0,     0,   -11,   -65,   -65,   -11,   -65,   -65,
     -65,   -65,     0,   -65,     0,     0,     0,     0,     0,     0,
     -65,   -65,   -65,     0,   -65,   -65,     0,   -65,   -65,   -65,
       0,   -65,   -65,     0,     0,     0,   -65,   -64,   -64,   -65,
     -64,   -64,   -64,   -64,     0,   -64,     0,     0,     0,     0,
       0,     0,   -64,   -64,   -64,     0,   -64,   -64,     0,   -64,
     -64,   -64,     0,   -64,   -64,     0,     0,     0,   -64,   -14,
     -14,   -64,   -14,   -14,   -14,   -14,     0,   -14,     0,     0,
       0,     0,     0,     0,   -14,   -14,   -14,     0,   -14,   -14,
       0,   -14,   -14,   -14,     0,   -14,   -14,     0,     0,     0,
     -14,   -10,   -10,   -14,   -10,   -10,   -10,   -10,     0,   -10,
       0,     0,     0,     0,     0,     0,   -10,   -10,   -10,     0,
     -10,   -10,     0,   -10,   -10,   -10,     0,   -10,   -10,     0,
       0,     0,   -10,   -30,   -30,   -10,   -30,   -30,   -30,   -30,
       0,   -30,     0,     0,     0,     0,     0,     0,   -30,   -30,
     -30,     0,   -30,   -30,     0,   -30,   -30,   -30,     0,   -30,
     -30,     0,     0,     0,   -30,   -13,   -13,   -30,   -13,   -13,
     -13,   -13,     0,   -13,     0,     0,     0,     0,     0,     0,
     -13,   -13,   -13,     0,   -13,   -13,     0,   -13,   -13,   -13,
       0,   -13,   -13,     0,     0,     0,   -13,   -12,   -12,   -13,
     -12,   -12,   -12,   -12,     0,   -12,     0,     0,     0,     0,
       0,     0,   -12,   -12,   -12,     0,   -12,   -12,     0,   -12,
     -12,   -12,     0,   -12,   -12,     0,     0,     0,   -12,   -48,
     -48,   -12,   -48,   -48,   -48,   -48,     0,   -48,     0,     0,
       0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,   -48,
       0,   -48,   -48,   -48,     0,   -48,   -48,     0,     0,     0,
     -48,   -49,   -49,   -48,   -49,   -49,   -49,   -49,     0,   -49,
       0,     0,     0,     0,     0,     0,   -49,   -49,   -49,     0,
     -49,   -49,     0,   -49,   -49,   -49,     0,   -49,   -49,     0,
       0,     0,   -49,   -44,   -44,   -49,   -44,   -44,   -44,   -44,
       0,   -44,     0,     0,     0,     0,     0,     0,   -44,   -44,
     -44,     0,   -44,   -44,     0,   -44,   -44,   -44,     0,   -44,
     -44,     0,     0,     0,   -44,   -47,   -47,   -44,   -47,   -47,
     -47,   -47,     0,   -47,     0,     0,     0,     0,     0,     0,
     -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,
       0,   -47,   -47,     0,     0,     0,   -47,   -50,   -50,   -47,
     -50,   -50,   -50,   -50,     0,   -50,     0,     0,     0,     0,
       0,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,   -50,
     -50,   -50,     0,   -50,   -50,     0,     0,     0,   -50,   -45,
     -45,   -50,   -45,   -45,   -45,   -45,     0,   -45,     0,     0,
       0,     0,     0,     0,   -45,   -45,   -45,     0,   -45,   -45,
       0,   -45,   -45,   -45,     0,   -45,   -45,     0,     0,     0,
     -45,   -51,   -51,   -45,   -51,   -51,   -51,   -51,     0,   -51,
       0,     0,     0,     0,     0,     0,   -51,   -51,   -51,     0,
     -51,   -51,     0,   -51,   -51,   -51,     0,   -51,   -51,     0,
       0,     0,   -51,   -46,   -46,   -51,   -46,   -46,   -46,   -46,
       0,   -46,     0,     0,     0,     0,     0,     0,   -46,   -46,
     -46,     0,   -46,   -46,     0,   -46,   -46,   -46,     0,   -46,
     -46,     0,     0,     0,   -46,   -61,   -61,   -46,   -61,   -61,
     -61,   -61,     0,   -61,     0,     0,     0,     0,     0,     0,
     -61,   -61,   -61,     0,   -61,   -61,     0,   -61,   -61,   -61,
       0,   -61,   -61,     0,     0,     0,   -61,   -58,   -58,   -61,
     -58,   -58,   -58,   -58,     0,   -58,     0,     0,     0,     0,
       0,     0,   -58,   -58,   -58,     0,   -58,   -58,     0,   -58,
     -58,   -58,     0,   -58,   -58,     0,     0,     0,   -58,   -60,
     -60,   -58,   -60,   -60,   -60,   -60,     0,   -60,     0,     0,
       0,     0,     0,     0,   -60,   -60,   -60,     0,   -60,   -60,
       0,   -60,   -60,   -60,     0,   -60,   -60,     0,     0,     0,
     -60,   -57,   -57,   -60,   -57,   -57,   -57,   -57,     0,   -57,
       0,     0,     0,     0,     0,     0,   -57,   -57,   -57,     0,
     -57,   -57,     0,   -57,   -57,   -57,     0,   -57,   -57,     0,
       0,     0,   -57,   -20,   -20,   -57,   -20,   -20,   -20,   -20,
       0,   -20,     0,     0,     0,     0,     0,     0,   -20,   -20,
     -20,     0,   -20,   -20,     0,   -20,   -20,   -20,     0,   -20,
     -20,     0,     0,     0,   -20,   -17,   -17,   -20,   -17,   -17,
     -17,   -17,     0,   -17,     0,     0,     0,     0,     0,     0,
     -17,   -17,   -17,     0,   -17,   -17,     0,   -17,   -17,   -17,
       0,   -17,   -17,     0,     0,     0,   -17,   -67,   -67,   -17,
     -67,   -67,   -67,   -67,     0,   -67,     0,     0,     0,     0,
       0,     0,   -67,   -67,   -67,     0,   -67,   -67,     0,   -67,
     -67,   -67,     0,   -67,   -67,     0,     0,     0,   -67,   -68,
     -68,   -67,   -68,   -68,   -68,   -68,     0,   -68,     0,     0,
       0,     0,     0,     0,   -68,   -68,   -68,     0,   -68,   -68,
       0,   -68,   -68,   -68,     0,   -68,   -68,     0,     0,     0,
     -68,   -69,   -69,   -68,   -69,   -69,   -69,   -69,     0,   -69,
       0,     0,     0,     0,     0,     0,   -69,   -69,   -69,     0,
     -69,   -69,     0,   -69,   -69,   -69,     0,   -69,   -69,     0,
       0,     0,   -69,   -66,   -66,   -69,   -66,   -66,   -66,   -66,
       0,   -66,     0,     0,     0,     0,     0,     0,   -66,   -66,
     -66,     0,   -66,   -66,     0,   -66,   -66,   -66,     0,   -66,
     -66,     0,     0,     0,   -66,     0,   322,   -66,     2,     3,
       4,   232,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,     0,     0,     0,   323,   324,   325,
     591,   326,   327,     0,     0,     0,    17,     0,   308,   328,
       2,     3,     4,   232,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,     0,     0,     0,   275,
     276,   277,     0,   278,   279,     0,     0,     0,    17,     0,
      71,   280,     2,     3,     4,   232,     0,     6,     0,     0,
       0,     0,     0,     0,     7,     8,     9,     0,     0,     0,
       0,    12,    13,    14,     0,    15,    16,     0,     0,     0,
      17,     0,   322,    18,     2,     3,     4,   232,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,     0,     0,   323,   324,   325,     0,   326,   327,     0,
       0,     0,    17,     0,   100,   328,   253,   254,   255,   256,
     104,     6,   253,   254,   255,   256,     0,     6,     7,     8,
       9,     0,     0,     0,     7,     8,     9,     0,   112,     0,
     233,   234,   235,   236,   257,     6,     0,     0,     0,     0,
     257,     0,     7,     8,     9,   130,     0,   253,   254,   255,
     256,     0,     6,     0,     0,     0,     0,     0,   237,     7,
       8,     9,   132,     0,   253,   254,   255,   256,     0,     6,
       0,     0,     0,     0,     0,   257,     7,     8,     9,   134,
       0,   253,   254,   255,   256,     0,     6,     0,     0,     0,
       0,     0,   257,     7,     8,     9,   136,     0,   253,   254,
     255,   256,     0,     6,     0,     0,     0,     0,     0,   257,
       7,     8,     9,   138,     0,   253,   254,   255,   256,     0,
       6,     0,     0,     0,     0,     0,   257,     7,     8,     9,
     140,     0,   253,   254,   255,   256,     0,     6,     0,     0,
       0,     0,     0,   257,     7,     8,     9,   142,     0,   253,
     254,   255,   256,     0,     6,     0,     0,     0,     0,     0,
     257,     7,     8,     9,   144,     0,   253,   254,   255,   256,
       0,     6,     0,     0,     0,     0,     0,   257,     7,     8,
       9,   146,     0,   253,   254,   255,   256,     0,     6,     0,
       0,     0,     0,     0,   257,     7,     8,     9,   338,     0,
     289,   290,   291,   292,     0,     6,     0,     0,     0,     0,
       0,   257,     7,     8,     9,   341,     0,   233,   234,   235,
     236,     0,     6,     0,     0,     0,     0,     0,   293,     7,
       8,     9,   355,     0,   233,   234,   235,   236,     0,     6,
       0,     0,     0,     0,     0,   237,     7,     8,     9,   371,
       0,   360,   361,   362,   363,     0,     6,     0,     0,     0,
       0,     0,   237,     7,     8,     9,   374,     0,   360,   361,
     362,   363,     0,     6,     0,     0,     0,     0,     0,   364,
       7,     8,     9,   376,     0,   360,   361,   362,   363,     0,
       6,     0,     0,     0,     0,     0,   364,     7,     8,     9,
     378,     0,   360,   361,   362,   363,     0,     6,     0,     0,
       0,     0,     0,   364,     7,     8,     9,   380,     0,   360,
     361,   362,   363,     0,     6,     0,     0,     0,     0,     0,
     364,     7,     8,     9,   384,     0,   360,   361,   362,   363,
       0,     6,     0,     0,     0,     0,     0,   364,     7,     8,
       9,   394,     0,     2,     3,     4,   232,     0,     6,     0,
       0,     0,     0,     0,   364,     7,     8,     9,   399,     0,
     233,   234,   235,   236,     0,     6,     0,     0,     0,     0,
       0,    17,     7,     8,     9,   424,     0,   413,   414,   415,
     416,     0,     6,     0,     0,     0,     0,     0,   237,     7,
       8,     9,   427,     0,   413,   414,   415,   416,     0,     6,
       0,     0,     0,     0,     0,   417,     7,     8,     9,   429,
       0,   413,   414,   415,   416,     0,     6,     0,     0,     0,
       0,     0,   417,     7,     8,     9,   431,     0,   413,   414,
     415,   416,     0,     6,     0,     0,     0,     0,     0,   417,
       7,     8,     9,   433,     0,   413,   414,   415,   416,     0,
       6,     0,     0,     0,     0,     0,   417,     7,     8,     9,
     437,     0,   413,   414,   415,   416,     0,     6,     0,     0,
       0,     0,     0,   417,     7,     8,     9,   448,     0,     2,
       3,     4,   232,     0,     6,     0,     0,     0,     0,     0,
     417,     7,     8,     9,   455,     0,   360,   361,   362,   363,
       0,     6,     0,     0,     0,     0,     0,    17,     7,     8,
       9,   457,     0,   360,   361,   362,   363,     0,     6,     0,
       0,     0,     0,     0,   364,     7,     8,     9,   459,     0,
     360,   361,   362,   363,     0,     6,     0,     0,     0,     0,
       0,   364,     7,     8,     9,   461,     0,   360,   361,   362,
     363,     0,     6,     0,     0,     0,     0,     0,   364,     7,
       8,     9,   463,     0,   360,   361,   362,   363,     0,     6,
       0,     0,     0,     0,     0,   364,     7,     8,     9,   465,
       0,   360,   361,   362,   363,     0,     6,     0,     0,     0,
       0,     0,   364,     7,     8,     9,   467,     0,   360,   361,
     362,   363,     0,     6,     0,     0,     0,     0,     0,   364,
       7,     8,     9,   469,     0,   360,   361,   362,   363,     0,
       6,     0,     0,     0,     0,     0,   364,     7,     8,     9,
     471,     0,   360,   361,   362,   363,     0,     6,     0,     0,
       0,     0,     0,   364,     7,     8,     9,   477,     0,   233,
     234,   235,   236,     0,     6,     0,     0,     0,     0,     0,
     364,     7,     8,     9,   487,     0,   233,   234,   235,   236,
       0,     6,     0,     0,     0,     0,     0,   237,     7,     8,
       9,   498,     0,   413,   414,   415,   416,     0,     6,     0,
       0,     0,     0,     0,   237,     7,     8,     9,   500,     0,
     413,   414,   415,   416,     0,     6,     0,     0,     0,     0,
       0,   417,     7,     8,     9,   502,     0,   413,   414,   415,
     416,     0,     6,     0,     0,     0,     0,     0,   417,     7,
       8,     9,   504,     0,   413,   414,   415,   416,     0,     6,
       0,     0,     0,     0,     0,   417,     7,     8,     9,   506,
       0,   413,   414,   415,   416,     0,     6,     0,     0,     0,
       0,     0,   417,     7,     8,     9,   508,     0,   413,   414,
     415,   416,     0,     6,     0,     0,     0,     0,     0,   417,
       7,     8,     9,   510,     0,   413,   414,   415,   416,     0,
       6,     0,     0,     0,     0,     0,   417,     7,     8,     9,
     512,     0,   413,   414,   415,   416,     0,     6,     0,     0,
       0,     0,     0,   417,     7,     8,     9,   514,     0,   413,
     414,   415,   416,     0,     6,     0,     0,     0,     0,     0,
     417,     7,     8,     9,   517,     0,   233,   234,   235,   236,
       0,     6,     0,     0,     0,     0,     0,   417,     7,     8,
       9,   527,     0,   233,   234,   235,   236,     0,     6,     0,
       0,     0,     0,     0,   237,     7,     8,     9,     0,     0,
       2,     3,     4,   232,     0,     6,     0,     0,     0,     0,
       0,   237,     7,     8,     9,     0,     0,   253,   254,   255,
     256,     0,     6,     0,     0,     0,     0,     0,    17,     7,
       8,     9,     0,     0,   233,   234,   235,   236,     0,     6,
       0,     0,     0,     0,     0,   257,     7,     8,     9,     0,
       0,   360,   361,   362,   363,     0,     6,     0,     0,     0,
       0,     0,   237,     7,     8,     9,     0,     0,   289,   290,
     291,   292,     0,     6,     0,     0,     0,     0,     0,   364,
       7,     8,     9,     0,     0,   413,   414,   415,   416,     0,
       6,     0,     0,     0,     0,     0,   293,     7,     8,     9,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,     0,
       0,     0,     0,   417,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,     0,  -113,     0,  -113,  -113,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,     0,     0,  -121,     0,  -121,
    -121,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,     0,
    -108,     0,  -108,  -108,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,     0,     0,  -124,     0,  -124,  -124,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,     0,  -123,     0,  -123,
    -123,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,     0,
       0,  -122,     0,  -122,  -122,   408,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,     0,  -114,     0,  -114,  -114,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,     0,     0,     0,     0,
     -99,   -99,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
       0,     0,     0,  -131,  -131,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,     0,     0,     0,     0,  -132,  -132,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,     0,     0,     0,
    -130,  -130,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
       0,     0,     0,     0,  -106,  -106,  -113,  -113,  -113,  -113,
    -113,  -113,  -113,  -113,     0,     0,     0,  -107,  -107,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,     0,     0,     0,
       0,  -113,  -113,   408,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,     0,     0,     0,  -121,  -121,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,     0,     0,     0,     0,  -102,  -102,
     310,   311,   312,   313,   -78,   315,   316,   317,     0,     0,
       0,  -103,  -103,   310,   311,   312,   -82,   -82,   315,   316,
     317,     0,     0,     0,     0,   -78,   -78,   310,   311,   312,
     -86,   -86,   -86,   316,   317,     0,     0,     0,   -82,   -82,
     310,   311,   -90,   -90,   -90,   -90,   316,   317,     0,     0,
       0,     0,   -86,   -86,   310,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,     0,     0,     0,   -90,   -90,   408,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,     0,     0,     0,     0,  -101,
    -101,   310,   311,   -96,   -96,   -96,   -96,   316,   317,     0,
       0,     0,  -100,  -100,   310,   311,   -95,   -95,   -95,   -95,
     316,   317,     0,     0,     0,     0,   -96,   -96,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,     0,     0,     0,   -95,
     -95,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,     0,
       0,     0,     0,  -105,  -105,   310,   311,   312,   313,   314,
     315,   316,   317,     0,     0,     0,  -104,  -104,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,     0,     0,     0,     0,
     -72,   -72,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
       0,     0,     0,  -108,  -108,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,     0,     0,     0,     0,  -124,  -124,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,     0,
    -123,  -123,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
       0,     0,     0,     0,  -122,  -122,   264,   265,   266,   267,
     268,   269,   270,   271,     0,     0,     0,  -114,  -114,   264,
     265,   266,   267,   268,   269,   270,   271,     0,     0,   272,
       0,   160,   264,   265,   266,   267,   268,   269,   270,   271,
       0,     0,   272,     0,   163,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,     0,     0,   272,     0,   225,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,     0,     0,  -131,     0,
    -131,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,     0,
       0,  -132,     0,  -132,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,     0,     0,  -130,     0,  -130,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,     0,     0,   351,     0,  -103,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,     0,
    -107,     0,  -107,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,     0,     0,  -113,     0,  -113,   264,   265,   266,   267,
     268,   269,   270,   271,     0,     0,  -121,     0,  -121,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,     0,     0,   272,
       0,   453,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
       0,     0,  -108,     0,  -108,   264,   265,   266,   267,   268,
     269,   270,   271,     0,     0,  -124,     0,  -124,   264,   265,
     266,   267,   268,   269,   270,   271,     0,     0,   272,     0,
     474,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,     0,
       0,   272,     0,   496,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,     0,     0,  -123,     0,  -123,   264,   265,   266,
     267,   268,   269,   270,   271,     0,     0,  -122,     0,  -122,
     264,   265,   266,   267,   268,   269,   270,   271,     0,     0,
     272,     0,   536,   264,   265,   266,   267,   268,   269,   270,
     271,     0,     0,   272,     0,   541,   264,   265,   266,   267,
     268,   269,   270,   271,     0,     0,   272,     0,   544,   264,
     265,   266,   267,   268,   269,   270,   271,     0,     0,   272,
       0,   551,   264,   265,   266,   267,   268,   269,   270,   271,
       0,     0,   272,     0,   556,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,     0,     0,   272,     0,   559,   264,   265,
     266,   267,   268,   269,   270,   271,     0,     0,  -114,     0,
    -114,   264,   265,   266,   267,   268,   269,   270,   271,     0,
       0,   272,     0,   624,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,     0,     0,   272,     0,   628,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,     0,     0,     0,     0,  -113,
     350,  -102,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,
       0,     0,  -121,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,     0,     0,     0,     0,  -102,   264,   265,   266,   267,
     -78,   269,   270,   271,     0,     0,     0,     0,  -103,   264,
     265,   266,   -82,   -82,   269,   270,   271,     0,     0,     0,
       0,   -78,   264,   265,   266,   -86,   -86,   -86,   270,   271,
       0,     0,     0,     0,   -82,   264,   265,   -90,   -90,   -90,
     -90,   270,   271,     0,     0,     0,     0,   -86,   264,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,     0,     0,     0,     0,
     -90,   350,  -100,  -100,  -100,  -100,  -100,  -100,  -100,     0,
       0,     0,     0,  -101,   264,   265,   -96,   -96,   -96,   -96,
     270,   271,     0,     0,     0,     0,  -100,   264,   265,   -95,
     -95,   -95,   -95,   270,   271,     0,     0,     0,     0,   -96,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,     0,     0,
       0,     0,   -95,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,     0,     0,     0,     0,  -105,   264,   265,   266,   267,
     268,   269,   270,   271,     0,     0,     0,     0,  -104,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,     0,     0,     0,
       0,   -72,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
       0,     0,     0,     0,  -108,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,     0,     0,     0,     0,  -124,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,     0,     0,     0,     0,
    -123,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,     0,
       0,     0,     0,  -122,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,     0,     0,     0,     0,  -114,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,     0,  -130,  -130,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,     0,     0,     0,  -103,
      82,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,
    -107,  -107,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
       0,     0,     0,  -113,  -113,    46,    47,    48,    49,    50,
      51,    52,    53,     0,  -121,  -121,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,   117,    55,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,     0,    54,    55,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,     0,     0,
       0,  -108,  -108,    46,    47,    48,    49,    50,    51,    52,
      53,     0,  -124,  -124,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,     0,     0,     0,   165,    55,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,     0,  -123,  -123,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,     0,     0,     0,  -122,
    -122,    46,    47,    48,    49,    50,    51,    52,    53,     0,
    -114,  -114,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,     0,   210,    55,    46,    47,    48,    49,    50,
      51,    52,    53,     0,   307,    55,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,     0,   441,    55,    46,
      47,    48,    49,    50,    51,    52,    53,     0,   491,    55,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
       0,   531,    55,    46,    47,    48,    49,    50,    51,    52,
      53,     0,   546,    55,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,   561,    55,    46,    47,    48,
      49,    50,    51,    52,    53,     0,   601,    55,   310,   311,
     312,   313,   314,   315,   316,   317,     0,     0,     0,   608,
      55,   264,   265,   266,   267,   268,   269,   270,   271,     0,
       0,   318,    81,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
       0,     0,     0,     0,   272,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,     0,   -99,    81,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,     0,     0,     0,     0,  -106,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,     0,  -102,    46,    47,
      48,    49,   -78,    51,    52,    53,     0,     0,     0,     0,
    -103,    46,    47,    48,   -82,   -82,    51,    52,    53,     0,
     -78,    46,    47,    48,   -86,   -86,   -86,    52,    53,     0,
       0,     0,     0,   -82,    46,    47,   -90,   -90,   -90,   -90,
      52,    53,     0,   -86,    46,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,     0,     0,     0,     0,   -90,    81,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,     0,  -101,    46,    47,   -96,
     -96,   -96,   -96,    52,    53,     0,     0,     0,     0,  -100,
      46,    47,   -95,   -95,   -95,   -95,    52,    53,     0,   -96,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,     0,     0,
       0,     0,   -95,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,     0,  -105,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,  -104,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,     0,   -72,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,     0,     0,     0,     0,  -131,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,     0,  -132,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,     0,     0,     0,
       0,  -130,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
       0,  -107,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
       0,     0,     0,     0,  -113,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,     0,  -121,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,     0,     0,     0,     0,  -108,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,     0,  -124,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,     0,     0,     0,     0,
    -123,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,     0,
    -122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -114
};

static const yytype_int16 yycheck[] =
{
       0,     0,   396,   391,   280,     6,   354,     0,    31,     1,
       1,   359,     1,     1,    31,     6,    16,    17,     1,     1,
      20,    20,    29,     1,     6,     0,     6,    20,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    19,    20,    31,
       1,    29,    31,   165,   166,     6,     1,     1,    31,    29,
      32,     1,   328,    31,    32,    33,   450,   445,    19,    20,
      11,    61,    62,    63,   412,    11,    29,    30,     1,     1,
      29,    32,     0,     6,     1,    32,    31,    31,    29,     0,
      11,    31,     7,     0,     0,    85,    32,   209,   210,   211,
       1,     1,    20,     3,     4,     5,     6,    29,     8,    20,
       1,    32,    29,    20,    20,    15,    16,    17,     1,    19,
      20,     1,    22,    23,    24,    25,    26,    27,    29,     1,
      32,    31,    10,    11,    34,    35,    32,     1,    29,     3,
       4,     5,     6,   481,     8,     6,    29,    10,    11,    29,
       1,    15,    16,    17,    32,    19,    20,    29,    22,    23,
      24,    25,    26,    27,     0,   154,    29,    31,    29,     0,
      34,    35,     6,   163,   164,   165,   166,    32,    29,     6,
     163,   164,   172,   521,    20,     6,    32,    21,     6,    20,
      10,    11,    12,   182,    21,    32,    33,     1,    32,    33,
       6,   191,     6,   193,   122,    32,    33,     6,   191,    29,
     193,    32,    33,   202,    32,    33,   206,     0,   208,   209,
     210,   211,    21,   206,    32,   208,    32,    33,    35,   212,
      29,    32,    31,   223,   224,   225,   226,    20,     6,   222,
     223,   224,   225,   226,    29,   163,   164,   237,    29,   167,
      11,     6,   163,   164,    32,    33,   163,   164,    29,    30,
       1,    29,     6,    31,    29,     6,    21,   257,    32,     6,
       1,    32,    33,   191,    29,   193,    31,    11,    19,    20,
     191,   393,   193,     1,   191,    29,   193,    31,   206,   279,
     208,    32,    29,    29,    31,   206,    29,   208,    32,   206,
      11,   208,    11,   293,    32,   223,   224,   225,   226,    10,
      11,     6,   223,   224,   225,   226,   223,   224,   225,   226,
      32,    32,    33,    32,    33,    29,    21,   163,   164,    32,
      33,    32,   163,   164,    29,   447,     1,   327,     9,    10,
      11,    12,     7,     8,     9,    10,    11,    12,    13,    14,
       9,    10,    11,    12,    32,   191,     6,   193,    11,    34,
     191,    32,   193,    32,   354,    30,    31,    32,    33,   359,
     206,    21,   208,    32,   364,   206,    29,   208,    11,    29,
     163,   164,     9,    10,    11,    12,    32,   223,   224,   225,
     226,    32,   223,   224,   225,   226,    29,    32,     6,    10,
      11,   391,   392,   393,    32,    32,    33,     1,   191,    31,
     193,    19,    20,     7,     8,     9,    10,    11,    12,    13,
      14,    32,   412,   206,    31,   208,    29,   417,    10,    11,
       9,    10,    11,    12,   546,   547,    30,    31,    32,    33,
     223,   224,   225,   226,    29,    30,    31,    29,    31,   561,
     562,    31,     1,    32,    33,   445,   446,   447,     7,     8,
       9,    10,    11,    12,    13,    14,     3,     4,     5,     6,
      29,     8,     1,     9,    10,    11,    12,    32,    15,    16,
      17,    32,    31,    32,    33,    10,    11,    12,   600,   601,
     602,   481,    32,    29,    31,   607,   608,   609,     7,     1,
      32,     3,     4,     5,     6,    29,     8,    32,    33,    32,
      33,    10,    11,    15,    16,    17,     7,    19,    20,    29,
      22,    23,    24,    25,    26,    27,    10,    11,    12,    31,
      29,   521,    34,    35,    29,    30,    31,     1,    32,     3,
       4,     5,     6,    32,     8,    32,    33,    32,    32,    33,
      32,    15,    16,    17,    32,    33,   546,   547,    32,     1,
      32,     3,     4,     5,     6,    32,     8,    31,    32,   559,
     560,   561,   562,    15,    16,    17,   559,   560,    32,    33,
      22,    23,    24,    25,    26,    27,    32,    33,    32,    31,
      29,    30,    34,    10,    11,    12,    32,    33,    29,   589,
      35,   591,     9,    10,    11,    12,   589,     1,   591,    32,
     600,   601,   602,    32,   604,    32,   606,   607,   608,   609,
      32,   604,    32,   606,    32,    32,   544,   545,     7,     8,
       9,    10,    11,    12,    13,    14,   626,   627,   628,   629,
      32,   559,   560,   626,   627,   628,   629,    32,   559,   560,
      29,    30,   559,   560,    29,   573,    32,   575,    32,    33,
       1,    29,     3,     4,     5,     6,    35,     8,    10,    11,
      12,   589,    29,   591,    15,    16,    17,    32,   589,   597,
     591,   599,   589,    29,   591,    29,   604,    29,   606,    29,
      31,    32,    29,   604,    29,   606,    29,   604,    32,   606,
      29,    30,    32,    20,   622,   623,   624,   625,   626,   627,
     628,   629,    10,    11,    12,   626,   627,   628,   629,   626,
     627,   628,   629,   559,   560,    32,    32,    32,   559,   560,
      32,    29,     1,     9,    10,    11,    12,   182,     7,     8,
       9,    10,    11,    12,    13,    14,     9,    10,    11,    12,
     202,    -1,   125,   589,    -1,   591,    32,    33,   589,    -1,
     591,    30,    31,    32,     9,    10,    11,    12,   604,    32,
     606,    -1,     1,   604,    -1,   606,   559,   560,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    32,    33,    -1,
     626,   627,   628,   629,    -1,   626,   627,   628,   629,    -1,
      -1,    30,    31,    32,     1,     0,   589,    -1,   591,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,   604,    17,   606,    -1,    20,     8,     9,    10,    11,
      12,    13,    14,    -1,    31,    32,    -1,    -1,     9,    10,
      11,    12,    -1,   626,   627,   628,   629,    -1,    43,    44,
      32,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    32,    33,    -1,    59,    -1,    61,    62,     9,    10,
      11,    12,    -1,    -1,    69,     9,    10,    11,    12,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    29,     1,
      85,     3,     4,     5,     6,    -1,     8,    -1,    32,    33,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,     1,    -1,     3,     4,     5,     6,
     125,     8,    -1,    -1,   129,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    10,    11,    31,    -1,     1,    34,    35,   154,
      -1,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
       9,    10,    11,    12,    32,    33,     1,   172,     3,     4,
       5,     6,    -1,     8,    29,   180,    31,   182,    -1,    -1,
      15,    16,    17,    32,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,   202,    -1,    34,
      35,    -1,    -1,    -1,   209,   210,   211,    10,    11,    12,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,     9,    10,    11,    12,    -1,    15,    16,    17,    32,
      19,    20,   237,    22,    23,    24,    25,    26,    27,    -1,
      -1,   246,    31,    -1,    32,    34,    35,    -1,     9,    10,
      11,    12,   257,   258,    -1,     9,    10,    11,    12,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    -1,    -1,
       1,    32,     3,     4,     5,     6,    -1,     8,    32,    33,
      10,    11,    12,   288,    15,    16,    17,    -1,   293,    -1,
      -1,    22,    23,    24,    25,    26,    27,   302,    -1,    -1,
      31,    -1,    32,    34,    -1,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    10,    11,    12,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    -1,    32,    33,   343,   344,
     345,   346,   347,   348,   349,   350,   351,    31,     1,   354,
       3,     4,     5,     6,   359,     8,    -1,    -1,    -1,   364,
      -1,   366,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,   389,    -1,   391,   392,    -1,    -1,
      17,   396,     9,    10,    11,    12,   401,   402,   403,   404,
     405,   406,   407,   408,   409,    -1,    -1,   412,     9,    10,
      11,    12,   417,    40,   419,    32,    33,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      -1,    32,    33,    -1,    61,    62,     7,     8,   443,    -1,
     445,   446,    13,    14,    -1,   450,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,     9,    10,
      11,    12,    -1,    15,    16,    17,   481,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    10,    11,    -1,    31,
      -1,    32,    34,    35,    -1,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    32,    33,
      15,    16,    17,    -1,    19,    20,   521,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,     0,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,     9,    10,    11,
      12,    -1,    15,    16,    17,   172,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    29,    31,    -1,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,     9,
      10,    11,    12,    -1,    15,    16,    17,     9,    10,    11,
      12,    -1,   209,   210,   211,     9,    10,    11,    12,    -1,
      31,    32,    32,    33,    -1,   600,   601,   602,    10,    11,
      32,    -1,   607,   608,   609,     1,    -1,    -1,    32,    -1,
     237,     7,     8,     9,    10,    11,    12,    13,    14,   246,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
     257,   258,    -1,    -1,    -1,    31,    32,   264,   265,   266,
     267,   268,   269,   270,   271,   272,     1,    32,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,   293,    22,    23,    24,
      25,    26,    27,    -1,    -1,   302,    31,    -1,    -1,    34,
      35,    -1,    -1,   310,   311,   312,   313,   314,   315,   316,
     317,   318,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,     7,     8,    15,
      16,    17,    18,    13,    14,    -1,   343,   344,   345,   346,
     347,   348,   349,   350,   351,    31,     1,   354,     3,     4,
       5,     6,   359,     8,    -1,    -1,    -1,   364,    -1,   366,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    -1,    -1,   391,   392,    17,     8,     9,    10,
      11,    12,    13,    14,   401,   402,   403,   404,   405,   406,
     407,   408,   409,    -1,    -1,   412,    -1,    -1,    29,    -1,
     417,    -1,   419,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,    62,     9,    10,    11,    12,    -1,    -1,   445,   446,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    29,    -1,    85,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,     9,    10,    11,    12,
      -1,    15,    16,    17,   481,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    29,    31,    -1,    -1,
      34,    35,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    19,    20,   521,    22,    23,    24,    25,    26,
      27,    -1,    -1,    29,    31,    -1,    -1,    34,    35,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,   172,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,   209,   210,
     211,    15,    16,    17,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,   600,   601,   602,    -1,    31,    32,    -1,
     607,   608,   609,    -1,    -1,    -1,   237,    30,    -1,    32,
      33,     9,    10,    11,    12,   246,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,   257,   258,    -1,    -1,
      -1,    29,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,     1,    32,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   293,    22,    23,    24,    25,    26,    27,    -1,
      -1,   302,    31,    -1,    -1,    34,    35,    -1,    -1,   310,
     311,   312,   313,   314,   315,   316,   317,   318,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,     7,     8,    15,    16,    17,    18,    13,
      14,    -1,   343,   344,   345,   346,   347,   348,   349,   350,
     351,    31,     1,   354,     3,     4,     5,     6,   359,     8,
      -1,    -1,    -1,   364,    -1,   366,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
     391,   392,    17,     9,    10,    11,    12,    -1,    -1,    -1,
     401,   402,   403,   404,   405,   406,   407,   408,   409,    -1,
      -1,   412,    -1,    29,    -1,    -1,   417,    -1,   419,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    61,    62,     9,    10,
      11,    12,    -1,    -1,   445,   446,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    29,    -1,
      85,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,     9,    10,    11,    12,    -1,    15,    16,    17,
     481,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    29,    31,    -1,    -1,    34,    35,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
     521,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,   172,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,   209,   210,   211,    15,    16,    17,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,   600,
     601,   602,    -1,    31,    32,    -1,   607,   608,   609,    -1,
      -1,    -1,   237,    30,    -1,    32,    33,    -1,    -1,    -1,
      -1,   246,    -1,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,   257,   258,    -1,    -1,    -1,    -1,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,     1,    32,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,   293,    22,
      23,    24,    25,    26,    27,    -1,    -1,   302,    31,    -1,
      -1,    34,    35,    -1,    -1,   310,   311,   312,   313,   314,
     315,   316,   317,   318,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,   343,   344,
     345,   346,   347,   348,   349,   350,   351,     0,     1,   354,
       3,     4,     5,     6,   359,     8,    -1,    -1,    -1,   364,
      -1,   366,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    -1,     7,     8,     9,   391,   392,    17,    13,
      14,    -1,    -1,    -1,    -1,    -1,   401,   402,   403,   404,
     405,   406,   407,   408,   409,    -1,    -1,   412,    -1,     7,
       8,     9,   417,    -1,   419,    13,    14,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    -1,     7,
       8,     9,    61,    62,    12,    13,    14,     7,     8,     9,
     445,   446,    12,    13,    14,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    -1,     0,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,   481,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    -1,    -1,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,   521,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,   172,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
       1,    31,    -1,    -1,    34,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,     7,     8,     9,
     209,   210,   211,    13,    14,    -1,    -1,    -1,    29,    30,
      31,    -1,    -1,    -1,    -1,   600,   601,   602,    -1,    -1,
      -1,    -1,   607,   608,   609,    -1,    -1,    -1,   237,     7,
       8,     9,    10,    11,    12,    13,    14,   246,    -1,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,   257,   258,
      -1,    -1,    30,    -1,    32,   264,   265,   266,   267,   268,
     269,   270,   271,   272,     1,    32,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,   293,    22,    23,    24,    25,    26,
      27,    -1,    -1,   302,    31,    -1,    -1,    34,    35,    -1,
      -1,   310,   311,   312,   313,   314,   315,   316,   317,   318,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,   343,   344,   345,   346,   347,   348,
     349,   350,   351,     0,     1,   354,     3,     4,     5,     6,
     359,     8,    -1,    -1,    -1,   364,    -1,   366,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,   391,   392,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   401,   402,   403,   404,   405,   406,   407,   408,
     409,    -1,    -1,   412,    -1,    -1,    -1,    -1,   417,    -1,
     419,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    -1,    -1,     7,     8,     9,    61,    62,
      12,    13,    14,    -1,    -1,    -1,   445,   446,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    85,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,   481,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   521,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     0,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,   172,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,     1,    31,    -1,
      -1,    34,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,   209,   210,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,
      -1,   600,   601,   602,    -1,    -1,    -1,    -1,   607,   608,
     609,    -1,    -1,    -1,   237,     7,     8,     9,    10,    11,
      12,    13,    14,   246,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,   257,   258,    -1,    15,    16,    17,
      32,   264,   265,   266,   267,   268,   269,   270,   271,   272,
      -1,    -1,     1,    31,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
     293,    -1,    17,    22,    23,    24,    25,    26,    27,   302,
      -1,    -1,    31,    -1,    -1,    34,    -1,   310,   311,   312,
     313,   314,   315,   316,   317,   318,    -1,    -1,    -1,     7,
       8,     9,    10,    48,    12,    13,    14,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
     343,   344,   345,   346,   347,   348,   349,   350,   351,    -1,
      -1,   354,    77,    -1,    79,    80,   359,    -1,    -1,    -1,
      85,   364,     1,   366,    -1,    -1,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,   391,   392,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,   401,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     1,   412,
       3,     4,     5,     6,   417,     8,   419,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,   445,   446,    -1,     0,     1,   172,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,   481,    34,
      -1,     1,    -1,    -1,   209,   210,   211,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    29,
      30,    31,   237,    17,    -1,    15,    16,    17,   521,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,   257,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,   266,   267,   268,   269,   270,   271,   272,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    62,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,   293,    -1,
      17,     8,     9,    10,    11,    12,    13,    14,    82,    -1,
      -1,    85,    30,    -1,    32,    33,    -1,   312,   313,   314,
     315,   316,   317,   318,    -1,    32,    33,   600,   601,   602,
      47,    -1,    -1,    -1,   607,   608,   609,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,   343,   344,
     345,   346,    -1,   348,   349,    -1,   351,    -1,    -1,   354,
      -1,    78,    -1,     0,   359,    -1,    -1,    -1,    85,   364,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,   391,   392,   172,    -1,
      -1,    30,    -1,    32,    33,    -1,   401,   402,   403,   404,
      -1,   406,   407,    -1,   409,    -1,     1,   412,     3,     4,
       5,     6,   417,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,   209,   210,   211,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
     445,   446,    -1,    -1,     1,   172,     3,     4,     5,     6,
      -1,     8,    -1,   237,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,   257,    31,    -1,   481,    34,    35,    -1,
      -1,    -1,   209,   210,   211,    -1,    -1,    -1,   272,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,   293,
     237,    17,    30,    15,    16,    17,   521,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
     257,    -1,    34,    35,   318,    -1,    -1,    -1,   265,   266,
     267,   268,   269,   270,   271,   272,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    61,    62,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,   293,   351,    -1,    -1,
     354,    -1,    -1,    -1,    29,   359,    31,    -1,    -1,    85,
     364,    -1,    -1,    -1,   311,   312,   313,   314,   315,   316,
     317,   318,    -1,    -1,    -1,   600,   601,   602,    -1,    -1,
      -1,    -1,   607,   608,   609,    -1,    -1,   391,   392,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   343,   344,   345,   346,
     347,   348,   349,    -1,   351,   409,    -1,   354,   412,    -1,
      -1,    -1,   359,   417,    -1,    -1,    -1,   364,    -1,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,   445,   446,    -1,   391,   392,   172,    29,    -1,    31,
      -1,    -1,    -1,    -1,   401,   402,   403,   404,   405,   406,
     407,    -1,   409,    -1,    -1,   412,     7,     8,     9,    10,
     417,    12,    13,    14,    -1,    -1,    -1,   481,    -1,    -1,
       1,    -1,    -1,   209,   210,   211,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,   445,   446,
       1,    -1,     3,     4,     5,     6,    -1,     8,    29,    -1,
      31,   237,    -1,    17,    15,    16,    17,   521,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,   257,    -1,    34,   481,    -1,    -1,    -1,    -1,    -1,
     266,   267,   268,   269,   270,   271,   272,    51,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    61,    62,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,   293,    -1,    -1,
      -1,    -1,    76,    -1,   521,    -1,    29,    -1,    31,    -1,
      -1,    85,    -1,    -1,    -1,    -1,   312,   313,   314,   315,
     316,   317,   318,    -1,    -1,    -1,   600,   601,   602,    -1,
      -1,    -1,    -1,   607,   608,   609,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,   343,   344,   345,
     346,    -1,   348,   349,    -1,   351,    -1,    -1,   354,    30,
      -1,    32,    33,   359,     7,     8,     9,    10,   364,    12,
      13,    14,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,   600,   601,   602,    15,    16,    17,    -1,
     607,   608,   609,    -1,    17,   391,   392,    -1,   172,    -1,
      29,    -1,    31,    -1,    -1,   401,   402,   403,   404,    -1,
     406,   407,    -1,   409,    -1,     1,   412,     3,     4,     5,
       6,   417,     8,    -1,    -1,    -1,    49,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,   209,   210,   211,    61,    62,
      -1,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,   445,
     446,    -1,    75,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    85,   237,    17,    -1,    -1,    -1,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,   257,    31,   481,    -1,    34,    35,    -1,
      -1,    -1,    -1,   267,   268,   269,    -1,    50,   272,     1,
      -1,     3,     4,     5,     6,    -1,     8,    -1,    61,    62,
      -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,   293,
      -1,    74,    -1,    -1,    -1,   521,    -1,    29,    -1,    31,
      -1,     1,    85,     3,     4,     5,     6,    -1,     8,   313,
     314,   315,    -1,    -1,   318,    15,    16,    17,    -1,   172,
      -1,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,   343,
     344,   345,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,
     354,    -1,    -1,    -1,    -1,   359,   209,   210,   211,    -1,
     364,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,   600,   601,   602,    15,    16,    17,
      -1,   607,   608,   609,   237,    -1,    -1,   391,   392,   172,
      -1,    -1,    -1,    31,    -1,    -1,    -1,   401,   402,   403,
      -1,    -1,    -1,    -1,   257,   409,    -1,    -1,   412,    -1,
      -1,    -1,    -1,   417,   267,   268,    -1,    -1,     1,   272,
       3,     4,     5,     6,    -1,     8,   209,   210,   211,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
     293,   445,   446,    -1,     3,     4,     5,     6,    31,     8,
      -1,    -1,    -1,    -1,   237,    -1,    15,    16,    17,    -1,
     313,   314,    -1,    -1,     1,   318,     3,     4,     5,     6,
      -1,     8,    31,    -1,   257,    -1,    -1,   481,    15,    16,
      17,    -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,   272,
     343,   344,    -1,    -1,    31,    -1,    -1,    -1,   351,    -1,
       1,   354,     3,     4,     5,     6,   359,     8,    -1,    -1,
     293,   364,    -1,    -1,    15,    16,    17,   521,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,   314,    -1,    34,    35,   318,    -1,    -1,   391,   392,
      -1,     3,     4,     5,     6,    -1,     8,    -1,   401,   402,
      -1,    -1,    -1,    15,    16,    17,   409,    -1,    -1,   412,
     343,    -1,    -1,    -1,   417,    -1,    -1,    -1,   351,    31,
       1,   354,     3,     4,     5,     6,   359,     8,    -1,    -1,
      -1,   364,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,   445,   446,    -1,    -1,   600,   601,   602,    -1,
      31,    -1,    -1,   607,   608,   609,    -1,    -1,   391,   392,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,   401,     3,
       4,     5,     6,    -1,     8,    -1,   409,    -1,   481,   412,
      -1,    15,    16,    17,   417,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,   445,   446,    -1,    -1,     0,     1,   521,     3,
       4,     5,     6,    -1,     8,    30,    -1,    32,    33,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,   481,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,     1,   521,     3,
       4,     5,     6,    -1,     8,    -1,    -1,   600,   601,   602,
      -1,    15,    16,    17,   607,   608,   609,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    31,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,     7,
       8,     9,    10,    11,    12,    13,    14,   600,   601,   602,
      -1,    -1,    31,    -1,   607,   608,   609,     0,     1,    -1,
       3,     4,     5,     6,    32,     8,    -1,    -1,    -1,    -1,
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
      -1,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
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
      -1,    31,    -1,    -1,    34,    35,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,     0,     1,
      34,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,     1,    34,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
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
      35,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
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
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      31,    -1,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
       1,     8,     3,     4,     5,     6,    -1,     8,    15,    16,
      17,    -1,    -1,    -1,    15,    16,    17,    -1,     1,    -1,
       3,     4,     5,     6,    31,     8,    -1,    -1,    -1,    -1,
      31,    -1,    15,    16,    17,     1,    -1,     3,     4,     5,
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
      -1,    -1,    -1,    -1,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    32,    33,     7,
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
      -1,    -1,    -1,    32,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    32,     7,     8,     9,
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
      11,    12,    13,    14,    -1,    -1,    -1,    29,    30,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    29,    30,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    29,    30,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    29,    30,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    29,
      30,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    30,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    30,     7,     8,     9,    10,    11,
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
      12,    13,    14,    -1,    -1,    -1,    -1,    29,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    29,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      29,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29
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
       1,    31,    31,    31,     1,    61,    76,     1,    61,    50,
       0,     1,    39,    29,    11,    10,    12,     9,     8,    13,
      14,     7,    30,    70,     1,    31,    76,    29,    31,    76,
      70,     1,    69,    70,     1,    67,     1,    65,     1,    64,
       1,    66,    67,    67,     1,    63,     1,    76,     1,    18,
      61,    79,     1,    61,     1,    61,    62,    29,    29,    32,
      32,     1,    25,    40,    51,    52,    53,    54,    58,    77,
       1,    64,     1,    65,     1,    66,     1,    67,     1,    69,
       1,    67,     1,    67,     1,    70,     1,    63,     1,    61,
      73,    74,    29,    30,    44,    29,    30,    31,    32,    32,
      32,    32,    32,    32,    32,    29,    29,    25,    54,    35,
      53,    76,    33,    32,     1,     1,    46,    47,    48,    76,
      77,     1,    42,    29,     1,    29,    29,     1,    29,     1,
      29,    25,    54,    25,    54,     1,    62,     1,    62,    54,
      61,    45,    33,    76,    46,    54,    25,    54,    25,    29,
      29,    29,    32,    48,    43,    54,    54,    62,    62,     1,
      62,    49,    32,    32,    32,    32,    32,    49,    54,    54,
      54,    54,     6,     3,     4,     5,     6,    31,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    75,    76,
      78,     6,     6,     3,     4,     5,     6,    31,    71,    72,
      75,    76,    78,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    30,    19,    20,    22,    23,    24,    26,    27,
      34,    49,    55,    56,    57,    59,    60,    61,    76,     3,
       4,     5,     6,    31,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    75,    76,    78,    29,     1,    29,
       7,     8,     9,    10,    11,    12,    13,    14,    30,     6,
      19,    20,     1,    22,    23,    24,    26,    27,    34,    49,
      55,    56,    57,    59,    60,    61,    29,    30,     1,     1,
      61,     1,    61,    11,    10,    12,     9,     8,    13,    14,
       7,    30,    70,     1,    31,     1,    61,    70,     1,    31,
       3,     4,     5,     6,    31,    70,    71,    72,    75,    76,
      78,     1,    69,    70,     1,    67,     1,    65,     1,    64,
       1,    66,    67,    67,     1,    63,    21,    21,     1,    31,
       1,    31,    31,    31,     1,    61,    50,    29,    76,     1,
      61,    11,    10,    12,     9,     8,    13,    14,     7,    30,
      70,     1,    31,     3,     4,     5,     6,    31,    70,    71,
      72,    75,    76,    78,     1,    69,    70,     1,    67,     1,
      65,     1,    64,     1,    66,    67,    67,     1,    63,    21,
      21,    29,     1,    31,     1,    31,    31,    31,     1,    61,
      50,    29,     1,    32,    32,     1,    64,     1,    65,     1,
      66,     1,    67,     1,    69,     1,    67,     1,    67,     1,
      70,     1,    63,    74,    32,    32,    74,     1,    61,    70,
       1,    31,     1,    76,     1,    61,    79,     1,    61,     1,
      62,    29,    29,    51,    29,    30,    32,    32,     1,    64,
       1,    65,     1,    66,     1,    67,     1,    69,     1,    67,
       1,    67,     1,    70,     1,    63,    74,     1,    61,    70,
       1,    31,     1,    76,     1,    61,    79,     1,    61,     1,
      62,    29,    29,    51,    32,    32,    32,    32,    74,    32,
      32,    32,    32,    32,    32,    32,    29,    29,    35,     1,
      32,    32,    32,    74,    32,    32,    32,    32,    32,    32,
      32,    29,    29,    35,    32,    29,     1,    29,    29,     1,
      29,     1,    29,    25,    54,    25,    54,    62,     1,    62,
      32,    29,     1,    29,    29,     1,    29,     1,    29,    25,
      54,    25,    54,    62,     1,    62,    54,    25,    54,    25,
      29,    29,    29,    54,    25,    54,    25,    29,    29,    29,
      54,    54,    62,    62,     1,    62,    54,    54,    62,    62,
       1,    62,    32,    32,    32,    32,    32,    32,    32,    32,
      54,    54,    54,    54,    54,    54,    54,    54
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
      57,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      61,    61,    61,    61,    62,    62,    63,    63,    63,    63,
      64,    64,    64,    64,    65,    65,    65,    65,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    72,    72,    73,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    76,    77,    77,    77,    77,
      78,    78,    78,    79
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
       7,     6,     2,     3,     3,     3,     9,     9,     9,     9,
       1,     3,     3,     3,     0,     1,     1,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     2,     1,
       1,     1,     1,     1,     4,     3,     1,     1,     1,     0,
       1,     1,     3,     3,     2,     1,     1,     1,     2,     2,
       1,     1,     1,     1
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
#line 3705 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3711 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3717 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3723 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3729 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3735 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3741 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3747 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3753 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3759 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3765 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3771 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3777 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3783 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3789 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3795 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3801 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3807 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3813 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3819 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3825 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_1: /* @1  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3831 "src/bison/grammar.c"
        break;

    case YYSYMBOL_46_param_list_opt: /* param_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3837 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3843 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3849 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3855 "src/bison/grammar.c"
        break;

    case YYSYMBOL_51_block_item_list_opt: /* block_item_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3861 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3867 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3873 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3879 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3885 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3891 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3897 "src/bison/grammar.c"
        break;

    case YYSYMBOL_else_error: /* else_error  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3903 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3909 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3915 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3921 "src/bison/grammar.c"
        break;

    case YYSYMBOL_62_expression_opt: /* expression.opt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3927 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3933 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3939 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3945 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3951 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3957 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3963 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3969 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3975 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3981 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3987 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3993 "src/bison/grammar.c"
        break;

    case YYSYMBOL_74_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 3999 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4005 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 130 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 4011 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4017 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4023 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4029 "src/bison/grammar.c"
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
#line 4338 "src/bison/grammar.c"
    break;

  case 4: /* prog: error  */
#line 137 "src/bison/grammar.y"
            {
        // idk if this is the best solution
        // actually dont work properly
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
    }
#line 4348 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration_list external_declaration  */
#line 144 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4354 "src/bison/grammar.c"
    break;

  case 6: /* external_declaration_list: external_declaration  */
#line 145 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4360 "src/bison/grammar.c"
    break;

  case 9: /* external_declaration: statement  */
#line 150 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4370 "src/bison/grammar.c"
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
            symbol_update_temp((yyvsp[-1].sym), current_context->t9n->temp++);
            (yyval.ast) = ast_declaration_init((yyloc), 
                ast_symref_init((yylsp[-1]), context_declare_variable(current_context, (yyvsp[-1].sym)))
            );
        }
        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 4398 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 180 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4408 "src/bison/grammar.c"
    break;

  case 12: /* var_declaration: type id '=' error  */
#line 185 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4419 "src/bison/grammar.c"
    break;

  case 13: /* var_declaration: id id '=' error  */
#line 191 "src/bison/grammar.y"
                      {
        show_error_range((yylsp[-3]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-3].sym)->name);
        symbol_free((yyvsp[-3].sym));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4430 "src/bison/grammar.c"
    break;

  case 14: /* var_declaration: id id ';'  */
#line 197 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-2]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-2].sym)->name);
        symbol_free((yyvsp[-2].sym));
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 4441 "src/bison/grammar.c"
    break;

  case 15: /* @1: %empty  */
#line 205 "src/bison/grammar.y"
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
#line 4482 "src/bison/grammar.c"
    break;

  case 16: /* $@2: %empty  */
#line 240 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4488 "src/bison/grammar.c"
    break;

  case 17: /* func_declaration: type id '(' @1 param_list.opt $@2 ')' compound_stmt  */
#line 240 "src/bison/grammar.y"
                                                              {
        (yyval.ast) = ast_userfunc_init((yyloc), current_context, (yyvsp[-4].ast), ast_params_init((yylsp[-3]), (yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4498 "src/bison/grammar.c"
    break;

  case 18: /* $@3: %empty  */
#line 245 "src/bison/grammar.y"
               {
        previous_context = current_context;
        list_push(&contexts, context_init("unnamed-func"));
        current_context = list_peek_last(&contexts);
        context_push_scope(current_context);
    }
#line 4509 "src/bison/grammar.c"
    break;

  case 19: /* $@4: %empty  */
#line 250 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4515 "src/bison/grammar.c"
    break;

  case 20: /* func_declaration: type '(' $@3 param_list.opt $@4 ')' compound_stmt  */
#line 250 "src/bison/grammar.y"
                                                              {
        show_error_range((yylsp[-5]), "expected identifier before " WHT "'('" RESET "\n");
        free((yyvsp[-6].pchar));
        LIST_FREE((yyvsp[-3].list), { ast_free(__IT__->data); });
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
        current_context = previous_context;
    }
#line 4528 "src/bison/grammar.c"
    break;

  case 21: /* param_list.opt: %empty  */
#line 260 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4534 "src/bison/grammar.c"
    break;

  case 23: /* params_list: params_list ',' param_decl  */
#line 264 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4540 "src/bison/grammar.c"
    break;

  case 24: /* params_list: param_decl  */
#line 265 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4546 "src/bison/grammar.c"
    break;

  case 25: /* params_list: error  */
#line 266 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4555 "src/bison/grammar.c"
    break;

  case 26: /* param_decl: type id  */
#line 272 "src/bison/grammar.y"
                    {
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        if (sym) {
            show_error_range((yylsp[0]), "redefinition of parameter " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            symbol_update_type((yyvsp[0].sym), symbol_type_from_str((yyvsp[-1].pchar)));
            symbol_update_temp((yyvsp[0].sym), -(current_context->t9n->temp++));
            (yyval.ast) = ast_symref_init((yyloc), context_declare_variable(current_context, (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 4573 "src/bison/grammar.c"
    break;

  case 27: /* param_decl: type  */
#line 285 "src/bison/grammar.y"
           {
        show_error_range((yylsp[0]), "expected identifier after " BGRN "'%s'" RESET "\n", (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
        (yyval.ast) = NULL;
    }
#line 4583 "src/bison/grammar.c"
    break;

  case 28: /* param_decl: id  */
#line 290 "src/bison/grammar.y"
         {
        show_error_range((yylsp[0]), "unknown type name for " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
        symbol_free((yyvsp[0].sym));
        (yyval.ast) = NULL;
    }
#line 4593 "src/bison/grammar.c"
    break;

  case 29: /* $@5: %empty  */
#line 297 "src/bison/grammar.y"
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
#line 4611 "src/bison/grammar.c"
    break;

  case 30: /* compound_stmt: '{' $@5 block_item_list.opt '}'  */
#line 309 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyloc), (yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 4623 "src/bison/grammar.c"
    break;

  case 31: /* block_item_list.opt: block_item_list  */
#line 318 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4629 "src/bison/grammar.c"
    break;

  case 32: /* block_item_list.opt: %empty  */
#line 319 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4635 "src/bison/grammar.c"
    break;

  case 33: /* block_item_list: block_item_list block_item  */
#line 322 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4641 "src/bison/grammar.c"
    break;

  case 34: /* block_item_list: block_item  */
#line 323 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4647 "src/bison/grammar.c"
    break;

  case 44: /* io_stmt: READ '(' id ')' ';'  */
#line 339 "src/bison/grammar.y"
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
#line 4663 "src/bison/grammar.c"
    break;

  case 45: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 350 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4672 "src/bison/grammar.c"
    break;

  case 46: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 354 "src/bison/grammar.y"
                                       {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4681 "src/bison/grammar.c"
    break;

  case 47: /* io_stmt: WRITE '(' error ')' ';'  */
#line 358 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4691 "src/bison/grammar.c"
    break;

  case 48: /* io_stmt: READ '(' error ')' ';'  */
#line 363 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected identifier before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4701 "src/bison/grammar.c"
    break;

  case 49: /* io_stmt: READ '(' id ')' error  */
#line 368 "src/bison/grammar.y"
                            {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4712 "src/bison/grammar.c"
    break;

  case 50: /* io_stmt: WRITE '(' expression ')' error  */
#line 374 "src/bison/grammar.y"
                                     {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4723 "src/bison/grammar.c"
    break;

  case 51: /* io_stmt: WRITE '(' string_literal ')' error  */
#line 380 "src/bison/grammar.y"
                                         {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4734 "src/bison/grammar.c"
    break;

  case 52: /* io_stmt: WRITE error  */
#line 386 "src/bison/grammar.y"
                  {
        show_error_range((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4744 "src/bison/grammar.c"
    break;

  case 53: /* io_stmt: READ error  */
#line 391 "src/bison/grammar.y"
                 {
        show_error_range((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4754 "src/bison/grammar.c"
    break;

  case 54: /* expr_stmt: expression ';'  */
#line 398 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 4760 "src/bison/grammar.c"
    break;

  case 55: /* expr_stmt: error ';'  */
#line 399 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 4769 "src/bison/grammar.c"
    break;

  case 56: /* cond_stmt: IF '(' expression ')' statement  */
#line 405 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 4777 "src/bison/grammar.c"
    break;

  case 57: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 408 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4785 "src/bison/grammar.c"
    break;

  case 58: /* cond_stmt: IF '(' expression ')' ELSE statement  */
#line 411 "src/bison/grammar.y"
                                           {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-3].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4796 "src/bison/grammar.c"
    break;

  case 59: /* cond_stmt: IF '(' error ')' statement  */
#line 417 "src/bison/grammar.y"
                                            {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4806 "src/bison/grammar.c"
    break;

  case 60: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 422 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4817 "src/bison/grammar.c"
    break;

  case 61: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 428 "src/bison/grammar.y"
                                      {
        show_error((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4827 "src/bison/grammar.c"
    break;

  case 62: /* else_error: ELSE statement  */
#line 435 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4837 "src/bison/grammar.c"
    break;

  case 63: /* else_error: error ELSE statement  */
#line 440 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4847 "src/bison/grammar.c"
    break;

  case 64: /* jmp_stmt: RETURN expression ';'  */
#line 446 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyloc), (yyvsp[-1].ast)); }
#line 4853 "src/bison/grammar.c"
    break;

  case 65: /* jmp_stmt: RETURN error ';'  */
#line 447 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 4862 "src/bison/grammar.c"
    break;

  case 66: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 453 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init((yyloc), current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 4870 "src/bison/grammar.c"
    break;

  case 67: /* iter_stmt: FOR '(' error ';' expression.opt ';' expression.opt ')' statement  */
#line 456 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-6]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4882 "src/bison/grammar.c"
    break;

  case 68: /* iter_stmt: FOR '(' expression.opt ';' error ';' expression.opt ')' statement  */
#line 463 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-4]), "expected expression before " WHT "';'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4894 "src/bison/grammar.c"
    break;

  case 69: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' error ')' statement  */
#line 470 "src/bison/grammar.y"
                                                                        {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-6].ast));
        ast_free((yyvsp[-4].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4906 "src/bison/grammar.c"
    break;

  case 71: /* expression: unary_expr '=' logical_or_expr  */
#line 480 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyloc), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 4912 "src/bison/grammar.c"
    break;

  case 72: /* expression: unary_expr '=' error  */
#line 481 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4922 "src/bison/grammar.c"
    break;

  case 73: /* expression: error '=' logical_or_expr  */
#line 486 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-2]), "expected expression before " WHT "'='" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4932 "src/bison/grammar.c"
    break;

  case 74: /* expression.opt: %empty  */
#line 493 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 4938 "src/bison/grammar.c"
    break;

  case 77: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 498 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4947 "src/bison/grammar.c"
    break;

  case 78: /* logical_or_expr: logical_or_expr OR error  */
#line 502 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4957 "src/bison/grammar.c"
    break;

  case 79: /* logical_or_expr: error OR logical_and_expr  */
#line 507 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4967 "src/bison/grammar.c"
    break;

  case 81: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 515 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 4976 "src/bison/grammar.c"
    break;

  case 82: /* logical_and_expr: logical_and_expr AND error  */
#line 519 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4986 "src/bison/grammar.c"
    break;

  case 83: /* logical_and_expr: error AND eq_expr  */
#line 524 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4996 "src/bison/grammar.c"
    break;

  case 85: /* eq_expr: eq_expr EQ rel_expr  */
#line 532 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5005 "src/bison/grammar.c"
    break;

  case 86: /* eq_expr: eq_expr EQ error  */
#line 536 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5015 "src/bison/grammar.c"
    break;

  case 87: /* eq_expr: error EQ rel_expr  */
#line 541 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5025 "src/bison/grammar.c"
    break;

  case 89: /* rel_expr: rel_expr REL list_expr  */
#line 549 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5034 "src/bison/grammar.c"
    break;

  case 90: /* rel_expr: rel_expr REL error  */
#line 553 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5044 "src/bison/grammar.c"
    break;

  case 91: /* rel_expr: error REL list_expr  */
#line 558 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5054 "src/bison/grammar.c"
    break;

  case 93: /* list_expr: add_expr DL_DG list_expr  */
#line 566 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5063 "src/bison/grammar.c"
    break;

  case 94: /* list_expr: add_expr COLON list_expr  */
#line 570 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5072 "src/bison/grammar.c"
    break;

  case 95: /* list_expr: add_expr DL_DG error  */
#line 574 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5082 "src/bison/grammar.c"
    break;

  case 96: /* list_expr: add_expr COLON error  */
#line 579 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5092 "src/bison/grammar.c"
    break;

  case 97: /* list_expr: error DL_DG list_expr  */
#line 584 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5102 "src/bison/grammar.c"
    break;

  case 98: /* list_expr: error COLON list_expr  */
#line 589 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5112 "src/bison/grammar.c"
    break;

  case 100: /* add_expr: add_expr ADD mult_expr  */
#line 597 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5121 "src/bison/grammar.c"
    break;

  case 101: /* add_expr: add_expr ADD error  */
#line 601 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5131 "src/bison/grammar.c"
    break;

  case 102: /* add_expr: error ADD mult_expr  */
#line 606 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5141 "src/bison/grammar.c"
    break;

  case 104: /* mult_expr: mult_expr MULT unary_expr  */
#line 614 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5150 "src/bison/grammar.c"
    break;

  case 105: /* mult_expr: mult_expr MULT error  */
#line 618 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5160 "src/bison/grammar.c"
    break;

  case 106: /* mult_expr: error MULT unary_expr  */
#line 623 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5170 "src/bison/grammar.c"
    break;

  case 108: /* unary_expr: unary_ops unary_expr  */
#line 631 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5179 "src/bison/grammar.c"
    break;

  case 114: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 644 "src/bison/grammar.y"
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
#line 5202 "src/bison/grammar.c"
    break;

  case 115: /* arg_expr_list: arg_expr_list ',' expression  */
#line 664 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5208 "src/bison/grammar.c"
    break;

  case 116: /* arg_expr_list: expression  */
#line 665 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5214 "src/bison/grammar.c"
    break;

  case 117: /* arg_expr_list: error  */
#line 666 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5223 "src/bison/grammar.c"
    break;

  case 119: /* arg_expr_list.opt: %empty  */
#line 673 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5229 "src/bison/grammar.c"
    break;

  case 120: /* primary_expr: id  */
#line 676 "src/bison/grammar.y"
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
#line 5244 "src/bison/grammar.c"
    break;

  case 122: /* primary_expr: '(' expression ')'  */
#line 687 "src/bison/grammar.y"
                         {
        if ((yyvsp[-1].ast)) {
            --(yyvsp[-1].ast)->rule_pos.first_column;
            ++(yyvsp[-1].ast)->rule_pos.last_column;
        }
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 5256 "src/bison/grammar.c"
    break;

  case 123: /* primary_expr: '(' error ')'  */
#line 694 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5265 "src/bison/grammar.c"
    break;

  case 124: /* primary_expr: id error  */
#line 698 "src/bison/grammar.y"
               {
        show_error_range((yylsp[0]), "expected " WHT "';'" RESET "\n");
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 5275 "src/bison/grammar.c"
    break;

  case 128: /* type: INT LIST  */
#line 710 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5287 "src/bison/grammar.c"
    break;

  case 129: /* type: FLOAT LIST  */
#line 717 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5299 "src/bison/grammar.c"
    break;

  case 130: /* constant: NUMBER_REAL  */
#line 726 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init((yyloc), K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5305 "src/bison/grammar.c"
    break;

  case 131: /* constant: NUMBER_INT  */
#line 727 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init((yyloc), K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5311 "src/bison/grammar.c"
    break;

  case 132: /* constant: NIL  */
#line 728 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init((yyloc), K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5317 "src/bison/grammar.c"
    break;

  case 133: /* string_literal: STR_LITERAL  */
#line 731 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyloc), (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5326 "src/bison/grammar.c"
    break;


#line 5330 "src/bison/grammar.c"

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

#line 737 "src/bison/grammar.y"


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
