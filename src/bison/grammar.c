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
    Scope *params_scope;
    StackNode *parent_stacknode_ref;
    char *last_line_ref;
    int p_ctx_name = 1;

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
            p_ctx_name = 0;                                                          \
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

#line 149 "src/bison/grammar.c"

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
  YYSYMBOL_id_expr = 74,                   /* id_expr  */
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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5516

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  384

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
       0,   125,   125,   126,   131,   132,   135,   136,   137,   144,
     144,   167,   174,   209,   174,   220,   221,   224,   225,   228,
     244,   244,   263,   264,   267,   268,   271,   272,   275,   276,
     277,   278,   279,   280,   283,   290,   297,   300,   303,   306,
     312,   321,   322,   329,   334,   335,   336,   344,   345,   348,
     349,   353,   362,   363,   367,   376,   377,   381,   390,   391,
     395,   404,   405,   409,   413,   420,   429,   430,   434,   443,
     444,   448,   457,   458,   464,   465,   466,   467,   470,   471,
     476,   477,   480,   481,   484,   485,   486,   487,   490,   503,
     506,   507,   508,   515,   524,   525,   526,   529
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
  "arg_expr_list.opt", "primary_expr", "id_expr", "id", "type", "constant",
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

#define YYPACT_NINF (-231)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-98)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     902,  4266,  4293,  4301,  4021,   -22,    59,   680,  1053,  1426,
    1960,  4328,    12,    13,    94,   101,   168,  3874,  2795,    39,
     945,  1085,  1139,  1275,  1318,  1458,  1512,  1667,  2226,  2265,
    2297,   109,    21,   451,   519,   116,   313,  5467,  1782,  4336,
    3892,  4363,  4371,  4048,  4056,     8,  4398,  4406,    70,  3874,
      17,    27,   340,  2131,   115,   141,   144,  2827,  -231,  2328,
    2359,   396,   803,   989,  1118,  1176,  1362,  1491,  1549,  1706,
    4433,   414,  2390,   -17,   171,   183,   193,   208,   229,   234,
    2421,  2452,  4441,  2859,   275,  2891,  2923,  2955,    32,   231,
     569,  5273,   605,   576,   709,   837,   968,  1141,  5487,  5281,
    1210,  1341,  1397,  1460,  5302,  5310,   239,   366,    34,    55,
     241,   112,   285,   289,   293,   336,   336,  2131,  2483,  2987,
     342,  3910,  4468,   158,  2514,  2545,  2576,   546,   724,   345,
     198,   318,   281,   308,   370,   356,   356,  3856,   363,   178,
     316,  2607,  2638,   362,   356,   320,    64,  2669,  2700,  4476,
    4503,  4511,  4083,  4538,  3874,    62,    42,    31,   243,   398,
     499,  4973,  4546,  3874,  4573,  4581,  4091,  4118,  4608,  4616,
     203,   367,   393,   395,   397,   405,  1736,  2795,  3019,  3051,
    3083,  3115,  3147,  3179,   410,  5331,  5339,  5360,  5221,  5368,
    3874,  3928,  5389,  5397,  5243,  5251,  5418,  5426,    91,   704,
    1597,  3976,  2068,  3874,   238,   184,    46,   181,   615,   151,
     927,  4126,  3910,  4153,  4161,  3986,  4013,  4188,  4196,   421,
    3211,  2795,   426,   130,   230,   376,   425,   429,  1855,  1888,
    1910,  2092,  2165,  3565,  3586,  3607,  3628,  4643,   414,    70,
    3874,  3649,  2131,   433,   438,  2827,  3243,   437,  5447,   414,
     447,  3670,  3691,  3712,  3733,  3754,  3775,  3796,  3817,  3838,
    4223,   414,  2827,  3275,   484,   486,  4651,   233,  4996,  5004,
    5027,  4934,  5035,  3874,    67,  5058,  3946,  5066,  5089,  4942,
    4965,  5097,  5120,   146,   440,   547,   463,   524,   590,   872,
    5128,   651,   751,  1024,  1086,  5151,  5159,   462,   284,   473,
     475,   496,   498,   503,   510,  3307,  3339,   508,  5455,   513,
    4231,   355,  1300,  2115,  4718,  1838,  4742,  3874,   235,  4750,
    3964,  4774,  4782,  4686,  4710,  4806,  4814,   353,   349,   434,
     804,   815,  1177,   279,  4838,  1188,  1245,  1551,  1559,  4846,
    4870,   411,   360,   514,   528,   538,  5182,   414,  4678,   548,
     551,   552,   552,  2131,  3371,  5476,   555,  4878,   414,  4258,
     766,  5190,   560,  3403,  3435,  2795,   201,  2731,   571,  4902,
     581,  5213,  2827,   587,   587,  3856,  4910,   596,  3467,  3499,
     593,  2763,   589,  3531
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
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,   611,    28,   515,  -231,  -231,  -231,  -231,
    -231,   494,     4,  -174,  -230,  -231,   553,     1,     5,     6,
       9,    10,    11,     0,  -110,  1904,   200,  1964,  1815,  1529,
    1758,  1584,   267,   420,   640,  -231,  -198,   793,  1013,    47,
       2,  1166,  1386
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    83,   112,    23,   123,   144,   131,
     132,   133,   178,    57,    84,    85,    86,    87,   179,   180,
     181,   182,   183,   108,    79,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,   109,   110,    42,    43,    44,
      88,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    25,    45,   245,    24,    26,    27,   129,    48,    28,
      29,    30,    -9,   111,   170,   307,    55,    56,   -90,   -91,
      31,    25,    45,   -92,    24,    26,    27,   143,    22,    28,
      29,    30,   344,   -93,    61,    50,    51,    72,   219,    58,
     299,   -90,   -91,   -52,   -52,   230,   -92,   262,    22,    75,
     -44,   309,    77,    78,   229,   -49,   -93,   184,   -52,   -52,
     253,   220,   -52,   343,   167,   -80,   -80,     1,     2,     3,
       4,     5,     6,   -49,     7,   228,   171,   -52,   -52,   229,
     -50,     8,     9,    10,    11,   184,   -82,   121,    14,    49,
      15,    16,    73,   -44,    17,    74,   167,    18,   -50,   167,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   195,   195,
     195,   195,   195,   195,   195,   195,   195,    78,   216,   127,
     128,   130,   -95,   -95,    52,   134,   -95,    64,   -55,   -55,
     -55,    53,   304,   -12,   -12,   120,   -90,   226,    60,   141,
     142,   134,   377,   -12,    80,   -55,    31,   148,   147,   362,
      24,    26,    27,   264,   227,    28,    29,    30,   -54,   -54,
     370,   255,   -61,   -61,   -61,   -61,   256,   257,   216,    54,
      81,     1,     2,     3,     4,    82,   244,   -54,     7,   223,
     224,   140,   -61,   -61,   167,     8,     9,    10,    11,   -15,
     247,   372,   254,   -55,   -55,   -55,   252,   -49,    17,   223,
     224,   167,   113,   250,   -39,   -39,   -39,   -39,   -39,   -39,
     167,   -39,   -55,   -55,   114,   -49,   -49,   156,   -39,   -39,
     -39,   -39,   -39,   -39,   115,   -39,   373,   -39,   -39,   -81,
     -81,   -39,   -89,   -89,   -39,   -39,   -91,   167,   195,   116,
     301,   303,    78,   368,   -51,   184,   -51,   252,   -50,   156,
     167,   251,   156,   265,   231,   -55,   -55,   -55,   -48,   216,
     -51,    90,   184,   117,   -51,   380,   -50,   -50,   -46,   -44,
     -44,   205,   122,   345,   -55,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   162,   216,   300,   167,   167,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   216,   228,   324,   324,
     324,   324,   324,   324,   324,   324,   324,    70,   216,   118,
     -68,   -68,   -16,   139,   124,   -45,   162,   356,   125,   162,
     167,   205,   126,   280,   -58,   -58,   -58,   -58,    91,    91,
      91,    91,    91,    91,    91,   105,    91,   156,   211,   -18,
     -18,    76,   -58,   149,   150,   151,   152,   -19,   -19,   138,
       7,   -17,   -17,    78,   156,   366,   367,     8,     9,    10,
     153,   -53,   -53,   253,   167,   -54,   -54,   324,   -51,   221,
     154,    -9,   184,   251,   137,   226,   225,   378,   379,    61,
     -53,   -53,   184,   383,   -54,   -54,   -51,   -51,   211,    18,
     156,   -45,   -45,   146,   216,   -45,   -13,    89,   -89,   185,
     186,   187,   188,   156,   162,   216,     7,   -89,   -89,   -58,
     -58,   -58,   -58,     8,     9,    10,   189,   198,   199,   200,
     201,   162,   167,   239,     7,   240,   190,   241,   274,   -58,
     237,     8,     9,    10,   202,   242,   156,   163,   205,   246,
     156,   156,   -46,   -46,   203,   -83,   -57,   -57,   -57,   205,
     -89,   318,   -53,   -53,   230,   263,   -48,   162,   248,   205,
     266,   205,   305,    62,   -49,   -57,   -57,   306,   308,   163,
     162,   -53,   163,   156,   231,   -56,   -56,   -56,   310,   260,
     -49,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     -92,   212,   -93,   -46,   -56,   275,   275,   275,   275,   275,
     275,   275,   296,   275,   348,   211,   349,   162,   162,   232,
     -61,   -61,   -61,   -61,   233,   234,   211,   156,   319,   319,
     319,   319,   319,   319,   319,   340,   319,   350,   211,   351,
     -61,   -52,   -52,    63,   352,   -60,   -60,   -60,   -60,   353,
     162,   212,   354,   346,   355,   359,   -39,   205,   -52,   -39,
     -39,   -39,   -39,   -39,   -39,   -60,   -39,   163,   205,   -57,
     -57,   -57,   360,   -39,   -39,   -39,   -39,   -39,   -39,   361,
     -39,   135,   -39,   -39,   163,   156,   -39,   363,   -57,   -39,
     364,    62,   -50,   163,   162,   365,   369,   357,   -53,   -53,
      63,   371,     1,     2,     3,     4,   172,   173,   -50,     7,
     375,   -59,   -59,   -59,   -59,   -53,     8,     9,    10,    11,
     163,   191,   376,   174,   211,   175,   176,   -54,   -54,    17,
     177,   -59,   177,   163,   382,   211,   -58,   -58,   -58,   -58,
     381,    59,   212,   145,   -54,   222,     0,     0,   119,     0,
       0,     0,   162,     0,     0,     0,   -58,   -58,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   164,   212,     0,
     163,   163,   -65,   -65,   -65,   -65,     0,     0,     0,   212,
       0,   320,   320,   320,   320,   320,   320,   320,   320,   320,
       0,   212,   -65,   -76,   -76,   -76,   -76,     0,     0,   164,
     -76,     0,   164,   163,     0,     0,   276,   -76,   -76,   -76,
     -76,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     -76,   213,     0,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -57,   -57,   -57,   -37,     0,     0,   -37,   -37,   -37,
     -37,   -37,   -37,     0,   -37,   -96,   -96,   163,   -57,   -96,
     320,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,   136,
     -37,   -37,     0,     0,   -37,     0,     0,   -37,     0,     0,
       0,   213,   -63,   -63,   -63,   -63,   -21,   212,     0,   -21,
     -21,   -21,   -21,   -21,   -21,     0,   -21,   164,   212,     0,
       0,     0,   -63,   -21,   -21,   -21,   -21,   -21,   -21,     0,
     -21,   -21,   -21,   -21,   164,   163,   -21,     0,     0,   -21,
       0,     0,     0,   164,    92,     0,   185,   186,   187,   188,
     165,     0,     0,     7,     0,   254,   -56,   -56,   -56,     0,
       8,     9,    10,   189,     0,     0,   -60,   -60,   -60,   -60,
     164,   192,     0,   190,     0,   -56,   -56,     0,     0,     0,
       0,     0,   165,   164,     0,   165,   -60,   -60,    64,   -56,
     -56,   -56,   213,     0,   193,   193,   193,   193,   193,   193,
     193,   193,   193,     0,   214,     0,   -56,     0,   277,   277,
     277,   277,   277,   277,   277,   277,   277,     0,   213,     0,
     164,   164,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   213,
       0,   321,   321,   321,   321,   321,   321,   321,   321,   321,
       0,   213,    -3,   -68,     0,     1,     2,     3,     4,     5,
       6,     0,     7,   164,   214,     0,   277,     0,     0,     8,
       9,    10,    11,    12,    13,     0,    14,     0,    15,    16,
     165,     0,    17,     0,     0,    18,   258,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,     0,    -2,     0,   165,     1,     2,
       3,     4,     5,     6,     0,     7,   165,   164,   -66,   -66,
     321,     0,     8,     9,    10,    11,    12,    13,     0,    14,
       0,    15,    16,     0,     0,    17,     0,     0,    18,   -60,
     -60,   -60,   -60,   165,   193,     0,     0,   213,     0,     0,
      94,     0,   185,   186,   187,   188,   165,   -60,   213,     7,
       0,     0,     0,     0,     0,   214,     8,     9,    10,   189,
       0,     0,     0,     0,     0,   164,     0,     0,     0,   190,
       0,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     166,   214,     0,   165,   165,   -64,   -64,   -64,   -64,     0,
       0,     0,   214,     0,   322,   322,   322,   322,   322,   322,
     322,   322,   322,     0,   214,   -64,   -74,   -74,   -74,   -74,
       0,     0,   166,   -74,     0,   166,   165,     0,     0,   278,
     -74,   -74,   -74,   -74,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   -74,   215,    -5,     0,     0,    -5,    -5,
      -5,    -5,    -5,    -5,     0,    -5,     0,   -62,   -62,   -62,
     -62,     0,    -5,    -5,    -5,    -5,    -5,    -5,     0,    -5,
     165,    -5,    -5,   322,     0,    -5,     0,   -62,    -5,    96,
       0,   185,   186,   187,   188,     0,     0,     0,     7,     0,
       0,     0,     0,     0,   215,     8,     9,    10,   189,    -7,
     214,     0,    -7,    -7,    -7,    -7,    -7,    -7,   190,    -7,
     166,   214,   -59,   -59,   -59,   -59,    -7,    -7,    -7,    -7,
      -7,    -7,     0,    -7,     0,    -7,    -7,   166,   165,    -7,
     -59,     0,    -7,     0,     0,     0,   166,    98,     0,   185,
     186,   187,   188,   168,     0,     0,     7,     0,   -59,   -59,
     -59,   -59,     0,     8,     9,    10,   189,     0,     0,   -65,
     -65,   -65,   -65,   166,   194,     0,   190,     0,   -59,   -59,
       0,     0,     0,     0,     0,   168,   166,     0,   168,   -65,
     -65,   -65,   -65,   -65,   -65,   215,     0,   196,   196,   196,
     196,   196,   196,   196,   196,   196,     0,   217,     0,   -65,
       0,   279,   279,   279,   279,   279,   279,   279,   279,   279,
       0,   215,     0,   166,   166,     0,   -63,   -63,   -63,   -63,
       0,     0,   215,     0,   323,   323,   323,   323,   323,   323,
     323,   323,   323,     0,   215,    -6,   -63,   -63,    -6,    -6,
      -6,    -6,    -6,    -6,     0,    -6,   166,   217,     0,   279,
       0,     0,    -6,    -6,    -6,    -6,    -6,    -6,     0,    -6,
       0,    -6,    -6,   168,     0,    -6,     0,     0,    -6,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,     0,   -29,     0,
     168,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   168,
     166,   -95,   -95,   323,     0,   -29,   -29,   -29,   -29,   -29,
     -29,     0,   -29,     0,   -29,   -29,     0,     0,   -29,     0,
       0,   -29,   -63,   -63,   -63,   -63,   168,   196,     0,     0,
     215,     0,     0,   100,     0,   185,   186,   187,   188,   168,
     -63,   215,     7,     0,     0,     0,     0,     0,   217,     8,
       9,    10,   189,     0,     0,     0,     0,     0,   166,     0,
       0,     0,   190,     0,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   169,   217,     0,   168,   168,   -64,   -64,
     -64,   -64,     0,     0,     0,   217,     0,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   -64,   217,     0,   -75,
     -75,   -75,   -75,     0,     0,   169,   -75,     0,   169,   168,
       0,     0,   281,   -75,   -75,   -75,   -75,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   -75,   218,    -8,     0,
       0,    -8,    -8,    -8,    -8,    -8,    -8,     0,    -8,     0,
       0,   -62,   -62,   -62,   -62,    -8,    -8,    -8,    -8,    -8,
      -8,     0,    -8,   168,    -8,    -8,   325,     0,    -8,   -62,
       0,    -8,   102,     0,   185,   186,   187,   188,     0,     0,
       0,     7,     0,     0,     0,     0,     0,   218,     8,     9,
      10,   189,   -33,   217,     0,   -33,   -33,   -33,   -33,   -33,
     -33,   190,   -33,   169,   217,     0,     0,     0,     0,   -33,
     -33,   -33,   -33,   -33,   -33,     0,   -33,     0,   -33,   -33,
     169,   168,   -33,     0,     0,   -33,   159,     0,     0,   169,
     104,     0,   185,   186,   187,   188,     0,     0,     0,     7,
       0,     0,   -64,   -64,   -64,   -64,     8,     9,    10,   189,
     -62,   -62,   -62,   -62,     0,     0,   169,   197,   159,   190,
       0,   159,   -64,   -64,     0,     0,     0,     0,     0,   169,
     -62,   -62,     0,    97,     0,   101,   103,     0,   218,     0,
     208,   161,     0,     0,     0,     0,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   282,   282,   282,   282,   282,   282,
     282,   282,   282,     0,   218,     0,   169,   169,   -94,   -94,
       0,     0,   -94,   161,     0,   218,   161,   326,   326,   326,
     326,   326,   326,   326,   326,   326,     0,   218,     0,    99,
     208,     0,     0,     0,     0,   210,     0,     0,     0,   169,
       0,     0,   282,     0,     0,     0,   159,   -28,     0,     0,
     -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,     0,     0,
       0,     0,     0,   159,   -28,   -28,   -28,   -28,   -28,   -28,
       0,   -28,     0,   -28,   -28,     0,     0,   -28,     0,     0,
     -28,     0,     0,   169,     0,   210,   326,   106,     0,   185,
     186,   187,   188,     0,     0,     0,     7,     0,     0,   159,
       0,   161,     0,     8,     9,    10,   189,     0,     0,     0,
       0,     0,   159,   218,     0,     0,   190,   243,   161,     1,
       2,     3,     4,     0,   218,     0,     7,     0,     0,     0,
       0,     0,     0,     8,     9,    10,    11,   159,   159,   159,
     288,   169,   292,   294,     0,   159,    17,   208,     0,   159,
     159,     0,     0,     0,   161,   160,     0,     0,   208,     0,
     208,   208,   208,   332,     0,   336,   338,   161,   208,     0,
     208,    68,   -66,   -66,   -66,   -66,   -66,   -66,   -66,     0,
       0,     0,   159,     0,     0,     0,     0,   160,     0,     0,
     160,   -66,   161,   161,   161,   161,   290,   161,   161,     0,
     161,     0,   210,     0,   161,   161,     0,     0,     0,   209,
       0,     0,   158,   210,     0,   210,   210,   210,   210,   334,
     210,   210,     0,   210,     0,   210,   159,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,     0,   267,   161,   268,   269,
     270,   271,     0,     0,   158,     7,     0,   158,   -89,   -89,
     -89,     0,     8,     9,    10,   272,   208,     0,    95,   209,
       0,     0,     0,     0,     0,   273,   207,   208,     0,   283,
       0,   268,   269,   270,   271,   160,     0,     0,     7,     0,
       0,   161,     0,     0,   159,     8,     9,    10,   272,     0,
       0,   285,   160,   268,   269,   270,   271,     0,   273,     0,
       7,   155,     0,     0,     0,     0,     0,     8,     9,    10,
     272,   210,     0,     0,     0,     0,   207,     0,     0,     0,
     273,     0,   210,     0,     0,     0,     0,     0,   160,     0,
       0,     0,   158,   155,     0,     0,   155,     0,     0,   161,
       0,   160,     0,   -77,   -77,   -77,   -77,     0,     0,   158,
     -77,     0,     0,   107,     0,   204,     0,   -77,   -77,   -77,
     -77,   157,     0,     0,     0,     0,   160,   160,   160,   160,
     -77,   160,   160,     0,   160,     0,   209,     0,   160,   160,
       0,     0,     0,     0,     0,   158,     0,   209,     0,   209,
     209,   209,   209,   157,   209,   209,   157,   209,   158,   209,
       0,     0,     0,     0,     0,   204,    93,     0,     0,     0,
       0,   160,     0,     0,     0,   206,     0,     0,     0,     0,
       0,   155,     0,   158,   158,   286,     0,     0,     0,     0,
       0,   158,     0,   207,     0,   158,   158,     0,   155,     0,
       0,     0,     0,     0,   207,     0,   207,   207,   330,     0,
       0,     0,     0,     0,   207,   160,   207,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   206,     0,     0,   158,     0,
       0,     0,     0,   287,   155,   268,   269,   270,   271,   -97,
     -97,   157,     7,   -97,     0,   209,     0,   155,     0,     8,
       9,    10,   272,     0,     0,     0,   209,     0,   157,     0,
       0,     0,   273,     0,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   158,   160,     1,     2,     3,     4,     0,     0,
     298,     7,   204,     0,   155,   155,   -96,   -96,     8,     9,
      10,    11,     0,   204,   157,     0,     0,     0,     0,     0,
     -47,    17,   207,   342,     0,   204,   289,   157,   268,   269,
     270,   271,     0,   207,     0,     7,     0,   155,     0,     0,
       0,     0,     8,     9,    10,   272,     0,     0,     0,     0,
     158,     0,   157,   284,     0,   273,     0,     0,     0,     0,
     157,     0,   206,     0,   157,   157,     0,     0,     0,     0,
       0,     0,     0,   206,     0,   206,   328,     0,     0,     0,
       0,   155,     0,   206,     0,   206,   -30,     0,     0,   -30,
     -30,   -30,   -30,   -30,   -30,     0,   -30,   157,     0,     0,
       0,     0,     0,   -30,   -30,   -30,   -30,   -30,   -30,     0,
     -30,   204,   -30,   -30,     0,     0,   -30,     0,     0,   -30,
       0,     0,   204,     0,     0,   -31,     0,     0,   -31,   -31,
     -31,   -31,   -31,   -31,     0,   -31,     0,     0,     0,   155,
       0,   157,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,
       0,   -31,   -31,     0,     0,   -31,     0,   -32,   -31,     0,
     -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,     0,     0,
       0,   206,     0,     0,   -32,   -32,   -32,   -32,   -32,   -32,
       0,   -32,   206,   -32,   -32,     0,     0,   -32,    -4,     0,
     -32,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,   157,
       0,     0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,     0,    -4,    -4,     0,     0,    -4,   -36,
       0,    -4,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,
       0,     0,     0,     0,     0,     0,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,     0,   -36,   -36,     0,     0,   -36,
     -11,     0,   -36,   -11,   -11,   -11,   -11,   -11,   -11,     0,
     -11,     0,     0,     0,     0,     0,     0,   -11,   -11,   -11,
     -11,   -11,   -11,     0,   -11,     0,   -11,   -11,     0,     0,
     -11,   -42,     0,   -11,   -42,   -42,   -42,   -42,   -42,   -42,
       0,   -42,     0,     0,     0,     0,     0,     0,   -42,   -42,
     -42,   -42,   -42,   -42,     0,   -42,     0,   -42,   -42,     0,
       0,   -42,   -41,     0,   -42,   -41,   -41,   -41,   -41,   -41,
     -41,     0,   -41,     0,     0,     0,     0,     0,     0,   -41,
     -41,   -41,   -41,   -41,   -41,     0,   -41,     0,   -41,   -41,
       0,     0,   -41,   -21,     0,   -41,   -21,   -21,   -21,   -21,
     -21,   -21,     0,   -21,     0,     0,     0,     0,     0,     0,
     -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,     0,   -21,
     -21,     0,     0,   -21,   -10,     0,   -21,   -10,   -10,   -10,
     -10,   -10,   -10,     0,   -10,     0,     0,     0,     0,     0,
       0,   -10,   -10,   -10,   -10,   -10,   -10,     0,   -10,     0,
     -10,   -10,     0,     0,   -10,   -34,     0,   -10,   -34,   -34,
     -34,   -34,   -34,   -34,     0,   -34,     0,     0,     0,     0,
       0,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,
       0,   -34,   -34,     0,     0,   -34,   -35,     0,   -34,   -35,
     -35,   -35,   -35,   -35,   -35,     0,   -35,     0,     0,     0,
       0,     0,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
     -35,     0,   -35,   -35,     0,     0,   -35,   -40,     0,   -35,
     -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,
       0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,   -40,
       0,   -40,     0,   -40,   -40,     0,     0,   -40,   -38,     0,
     -40,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,     0,
       0,     0,     0,     0,     0,   -38,   -38,   -38,   -38,   -38,
     -38,     0,   -38,     0,   -38,   -38,     0,     0,   -38,   -14,
       0,   -38,   -14,   -14,   -14,   -14,   -14,   -14,     0,   -14,
       0,     0,     0,     0,     0,     0,   -14,   -14,   -14,   -14,
     -14,   -14,     0,   -14,     0,   -14,   -14,     0,     0,   -14,
     -43,     0,   -14,   -43,   -43,   -43,   -43,   -43,   -43,     0,
     -43,     0,     0,     0,     0,     0,     0,   -43,   -43,   -43,
     -43,   -43,   -43,     0,   -43,     0,   -43,   -43,     0,     0,
     -43,     0,     0,   -43,   -37,   -37,   -37,   -37,   -37,   -37,
       0,   -37,     0,     0,     0,     0,     0,     0,   -37,   -37,
     -37,   -37,   -37,   -37,     0,   -37,   374,   -37,   -37,     0,
       0,   -37,     0,     0,   -37,   -37,   -21,   -21,   -21,   -21,
     -21,   -21,     0,   -21,     0,     0,     0,     0,     0,     0,
     -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,
     -21,     0,     0,   -21,     0,     0,   -21,   -21,   -20,   -20,
     -20,   -20,   -20,   -20,     0,   -20,     0,     0,     0,     0,
       0,     0,   -20,   -20,   -20,   -20,   -20,   -20,     0,   -20,
       0,   -20,   -20,     0,     0,   -20,     0,     0,   -20,   -20,
       1,     2,     3,     4,   172,   173,     0,     7,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
       0,   174,     0,   175,   176,     0,     0,    17,     0,     0,
     177,   -23,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,
       0,     0,     0,     0,     0,     0,   -26,   -26,   -26,   -26,
     -26,   -26,     0,   -26,     0,   -26,   -26,     0,     0,   -26,
       0,     0,   -26,   -26,     1,     2,     3,     4,   172,   173,
       0,     7,     0,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,     0,   174,     0,   175,   176,     0,
       0,    17,     0,     0,   177,   -22,   -25,   -25,   -25,   -25,
     -25,   -25,     0,   -25,     0,     0,     0,     0,     0,     0,
     -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,     0,   -25,
     -25,     0,     0,   -25,     0,     0,   -25,   -25,   -27,   -27,
     -27,   -27,   -27,   -27,     0,   -27,     0,     0,     0,     0,
       0,     0,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,
       0,   -27,   -27,     0,     0,   -27,     0,     0,   -27,   -27,
     -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,     0,     0,
       0,     0,     0,     0,   -24,   -24,   -24,   -24,   -24,   -24,
       0,   -24,     0,   -24,   -24,     0,     0,   -24,     0,     0,
     -24,   -24,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,
       0,     0,     0,     0,     0,     0,   -29,   -29,   -29,   -29,
     -29,   -29,     0,   -29,     0,   -29,   -29,     0,     0,   -29,
       0,     0,   -29,   -29,   -33,   -33,   -33,   -33,   -33,   -33,
       0,   -33,     0,     0,     0,     0,     0,     0,   -33,   -33,
     -33,   -33,   -33,   -33,     0,   -33,     0,   -33,   -33,     0,
       0,   -33,     0,     0,   -33,   -33,   -28,   -28,   -28,   -28,
     -28,   -28,     0,   -28,     0,     0,     0,     0,     0,     0,
     -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,     0,   -28,
     -28,     0,     0,   -28,     0,     0,   -28,   -28,   -30,   -30,
     -30,   -30,   -30,   -30,     0,   -30,     0,     0,     0,     0,
       0,     0,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,
       0,   -30,   -30,     0,     0,   -30,     0,     0,   -30,   -30,
     -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,     0,     0,
       0,     0,     0,     0,   -31,   -31,   -31,   -31,   -31,   -31,
       0,   -31,     0,   -31,   -31,     0,     0,   -31,     0,     0,
     -31,   -31,   -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,
       0,     0,     0,     0,     0,     0,   -32,   -32,   -32,   -32,
     -32,   -32,     0,   -32,     0,   -32,   -32,     0,     0,   -32,
       0,     0,   -32,   -32,   -11,   -11,   -11,   -11,   -11,   -11,
       0,   -11,     0,     0,     0,     0,     0,     0,   -11,   -11,
     -11,   -11,   -11,   -11,     0,   -11,     0,   -11,   -11,     0,
       0,   -11,     0,     0,   -11,   -11,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,     0,     0,     0,     0,     0,     0,
     -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,     0,   -36,
     -36,     0,     0,   -36,     0,     0,   -36,   -36,   -10,   -10,
     -10,   -10,   -10,   -10,     0,   -10,     0,     0,     0,     0,
       0,     0,   -10,   -10,   -10,   -10,   -10,   -10,     0,   -10,
       0,   -10,   -10,     0,     0,   -10,     0,     0,   -10,   -10,
     -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,     0,     0,
       0,     0,     0,     0,   -42,   -42,   -42,   -42,   -42,   -42,
       0,   -42,     0,   -42,   -42,     0,     0,   -42,     0,     0,
     -42,   -42,   -41,   -41,   -41,   -41,   -41,   -41,     0,   -41,
       0,     0,     0,     0,     0,     0,   -41,   -41,   -41,   -41,
     -41,   -41,     0,   -41,     0,   -41,   -41,     0,     0,   -41,
       0,     0,   -41,   -41,   -21,   -21,   -21,   -21,   -21,   -21,
       0,   -21,     0,     0,     0,     0,     0,     0,   -21,   -21,
     -21,   -21,   -21,   -21,     0,   -21,     0,   -21,   -21,     0,
       0,   -21,     0,     0,   -21,   -21,   -34,   -34,   -34,   -34,
     -34,   -34,     0,   -34,     0,     0,     0,     0,     0,     0,
     -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,     0,   -34,
     -34,     0,     0,   -34,     0,     0,   -34,   -34,   -35,   -35,
     -35,   -35,   -35,   -35,     0,   -35,     0,     0,     0,     0,
       0,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,
       0,   -35,   -35,     0,     0,   -35,     0,     0,   -35,   -35,
     -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,     0,     0,
       0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,   -40,
       0,   -40,     0,   -40,   -40,     0,     0,   -40,     0,     0,
     -40,   -40,   -38,   -38,   -38,   -38,   -38,   -38,     0,   -38,
       0,     0,     0,     0,     0,     0,   -38,   -38,   -38,   -38,
     -38,   -38,     0,   -38,     0,   -38,   -38,     0,     0,   -38,
       0,     0,   -38,   -38,   -43,   -43,   -43,   -43,   -43,   -43,
       0,   -43,     0,     0,     0,     0,     0,     0,   -43,   -43,
     -43,   -43,   -43,   -43,     0,   -43,     0,   -43,   -43,     0,
       0,   -43,     0,     0,   -43,   -43,   291,     0,   268,   269,
     270,   271,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     8,     9,    10,   272,     0,   293,     0,   268,
     269,   270,   271,     0,     0,   273,     7,     0,     0,     0,
       0,     0,     0,     8,     9,    10,   272,     0,   295,     0,
     268,   269,   270,   271,     0,     0,   273,     7,     0,     0,
       0,     0,     0,     0,     8,     9,    10,   272,     0,   297,
       0,   268,   269,   270,   271,     0,     0,   273,     7,     0,
       0,     0,     0,     0,     0,     8,     9,    10,   272,     0,
     302,     0,   149,   150,   151,   152,     0,     0,   273,     7,
       0,     0,     0,     0,     0,     0,     8,     9,    10,   153,
       0,   311,     0,   312,   313,   314,   315,     0,     0,   154,
       7,     0,     0,     0,     0,     0,     0,     8,     9,    10,
     316,     0,   327,     0,   312,   313,   314,   315,     0,     0,
     317,     7,     0,     0,     0,     0,     0,     0,     8,     9,
      10,   316,     0,   329,     0,   312,   313,   314,   315,     0,
       0,   317,     7,     0,     0,     0,     0,     0,     0,     8,
       9,    10,   316,     0,   331,     0,   312,   313,   314,   315,
       0,     0,   317,     7,     0,     0,     0,     0,     0,     0,
       8,     9,    10,   316,     0,   333,     0,   312,   313,   314,
     315,     0,     0,   317,     7,     0,     0,     0,     0,     0,
       0,     8,     9,    10,   316,     0,   335,     0,   312,   313,
     314,   315,     0,     0,   317,     7,     0,     0,     0,     0,
       0,     0,     8,     9,    10,   316,     0,   337,     0,   312,
     313,   314,   315,     0,     0,   317,     7,     0,     0,     0,
       0,     0,     0,     8,     9,    10,   316,     0,   339,     0,
     312,   313,   314,   315,     0,     0,   317,     7,     0,     0,
       0,     0,     0,     0,     8,     9,    10,   316,     0,   341,
       0,   312,   313,   314,   315,     0,     0,   317,     7,     0,
       0,     0,     0,     0,     0,     8,     9,    10,   316,   149,
     150,   151,   152,     0,     0,     0,     7,     0,   317,     0,
       0,     0,     0,     8,     9,    10,   153,   149,   150,   151,
     152,     0,     0,     0,     7,     0,   154,   -47,     0,     0,
       0,     8,     9,    10,   153,     1,     2,     3,     4,     0,
       0,     0,     7,     0,   154,     0,     0,     0,     0,     8,
       9,    10,    11,   198,   199,   200,   201,     0,     0,     0,
       7,     0,    17,     0,     0,     0,     0,     8,     9,    10,
     202,   185,   186,   187,   188,     0,     0,     0,     7,     0,
     203,     0,     0,     0,     0,     8,     9,    10,   189,   268,
     269,   270,   271,     0,     0,     0,     7,     0,   190,     0,
       0,     0,     0,     8,     9,    10,   272,   312,   313,   314,
     315,     0,     0,     0,     7,     0,   273,     0,     0,     0,
       0,     8,     9,    10,   316,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,     0,   317,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,     0,     0,     0,   -89,   -89,   -89,     0,
       0,   -89,     0,     0,     0,     0,   261,   -84,   -84,     0,
       0,   -84,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,     0,     0,
       0,     0,     0,   -88,   -88,   -88,     0,     0,   -88,     0,
     -89,   -89,     0,     0,     0,     0,   -89,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,     0,     0,     0,     0,   -84,    71,     0,
       0,     0,     0,   -84,     0,   -88,   -88,     0,     0,     0,
       0,   -88,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,     0,     0,
       0,     0,     0,   -89,   -89,     0,     0,     0,   -89,     0,
       0,   238,   -84,     0,     0,     0,   -84,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,     0,     0,     0,   -88,   -88,
       0,     0,     0,   -88,     0,     0,     0,   -69,   -69,     0,
       0,   259,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
       0,     0,     0,     0,   -72,   -72,     0,     0,   -72,     0,
       0,     0,   -78,   -78,     0,     0,   -78,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,     0,     0,     0,     0,     0,     0,   -85,
     -85,     0,     0,   -85,     0,     0,     0,   -86,   -86,     0,
       0,   -86,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,
       0,     0,     0,     0,   -73,   -73,     0,     0,   -73,     0,
       0,     0,   -87,   -87,     0,     0,   -87,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,     0,     0,     0,     0,     0,     0,   -79,
     -79,     0,     0,   -79,     0,   -95,     0,     0,     0,     0,
       0,   -95,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,     0,     0,
       0,     0,   -96,     0,     0,     0,     0,     0,   -96,     0,
     -94,     0,     0,     0,     0,     0,   -94,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,     0,     0,   -97,     0,     0,
       0,     0,     0,   -97,     0,   -69,     0,     0,     0,     0,
       0,    69,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
       0,     0,   -72,     0,     0,     0,     0,     0,   -72,     0,
     -78,     0,     0,     0,     0,     0,   -78,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,     0,     0,     0,     0,   -85,     0,     0,
       0,     0,     0,   -85,     0,   -86,     0,     0,     0,     0,
       0,   -86,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,
       0,     0,   -73,     0,     0,     0,     0,     0,   -73,     0,
     -87,     0,     0,     0,     0,     0,   -87,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,     0,     0,     0,     0,   -79,     0,     0,
       0,     0,     0,   -79,     0,     0,     0,   -95,     0,     0,
       0,   -95,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,     0,     0,
       0,     0,     0,     0,   -96,     0,     0,     0,   -96,     0,
       0,     0,   -94,     0,     0,     0,   -94,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,     0,     0,     0,     0,   -97,
       0,     0,     0,   -97,     0,     0,     0,   -69,     0,     0,
       0,   236,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
       0,     0,     0,     0,   -72,     0,     0,     0,   -72,     0,
       0,     0,   -78,     0,     0,     0,   -78,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,     0,     0,     0,     0,     0,     0,   -85,
       0,     0,     0,   -85,     0,     0,     0,   -86,     0,     0,
       0,   -86,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,
       0,     0,     0,     0,   -73,     0,     0,     0,   -73,     0,
       0,     0,   -87,     0,     0,     0,   -87,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,     0,     0,     0,     0,     0,     0,   -79,
       0,     0,     0,   -79,     0,     0,   358,   -84,   -84,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,
     -88,   -88,   -88,     0,     0,     0,     0,     0,     0,   -94,
     -94,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,
       0,     0,     0,   -97,   -97,     0,     0,     0,     0,     0,
       0,   -69,   -69,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,
       0,     0,     0,     0,     0,   -72,   -72,     0,     0,     0,
       0,     0,     0,   -78,   -78,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -86,     0,     0,     0,     0,     0,     0,   -85,   -85,     0,
       0,     0,     0,     0,     0,   -86,   -86,   258,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,     0,     0,     0,     0,   -67,
     -67,     0,     0,     0,     0,     0,     0,   -71,   -71,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,     0,     0,     0,     0,     0,
       0,   -70,   -70,     0,     0,     0,     0,     0,     0,   -73,
     -73,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,
       0,     0,     0,   -87,   -87,     0,     0,     0,     0,     0,
       0,   -79,   -79,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,     0,
       0,     0,     0,     0,   -89,   -89,     0,     0,     0,     0,
       0,     0,   347,   -84,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   235,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
       0,     0,     0,     0,     0,   -88,   -88,     0,     0,     0,
       0,     0,     0,     0,   -66,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,     0,     0,     0,     0,     0,     0,   -95,     0,     0,
       0,     0,     0,     0,     0,   -96,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,     0,     0,     0,     0,     0,     0,   -94,     0,
       0,     0,     0,     0,     0,     0,   -97,   -69,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,     0,     0,     0,   -69,
       0,     0,     0,     0,     0,     0,     0,   -72,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,     0,     0,     0,     0,     0,     0,
     -78,     0,     0,     0,     0,     0,     0,     0,   -85,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   235,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,     0,     0,     0,     0,     0,
       0,   -86,     0,     0,     0,     0,     0,     0,     0,   -67,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,
       0,     0,   -71,     0,     0,     0,     0,     0,     0,     0,
     -70,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,     0,
       0,     0,     0,   -73,     0,     0,     0,     0,     0,     0,
       0,   -87,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,     0,     0,
       0,     0,     0,     0,   -79,     0,     0,     0,     0,     0,
     -89,   -89,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,     0,     0,
       0,     0,   -84,   249,     0,     0,     0,     0,     0,     0,
     -88,   -88,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
      68,   -67,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,
       0,     0,   -69,     0,     0,     0,     0,     0,     0,     0,
     -67,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,
       0,   -71,     0,     0,     0,     0,     0,     0,     0,   -70,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,     0,     0,     0,     0,
     -95,     0,     0,     0,     0,     0,     0,     0,   -96,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,     0,     0,     0,     0,   -94,
       0,     0,     0,     0,     0,     0,     0,   -97,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,     0,     0,     0,     0,   -72,     0,
       0,     0,     0,     0,     0,     0,   -78,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,     0,     0,     0,     0,   -85,     0,     0,
       0,     0,     0,     0,     0,   -86,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,     0,     0,     0,     0,   -73,    65,   -61,   -61,
     -61,   -61,    66,    67,   -87,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,     0,     0,     0,   -61,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,     0,   -79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -68
};

static const yytype_int16 yycheck[] =
{
       0,     0,     0,   177,     0,     0,     0,   117,    30,     0,
       0,     0,    29,    30,     6,   245,    16,    17,     6,     6,
      20,    20,    20,     6,    20,    20,    20,   137,     0,    20,
      20,    20,   262,     6,    13,    23,    23,    29,     6,     0,
     238,    29,    29,    12,    13,    14,    29,   221,    20,    49,
      29,   249,    52,    53,    12,    13,    29,    57,    12,    13,
      14,    29,    31,   261,    17,    31,    32,     3,     4,     5,
       6,     7,     8,    31,    10,    13,     6,    31,    32,    12,
      13,    17,    18,    19,    20,    85,    31,    32,    24,    30,
      26,    27,    45,    31,    30,    48,    49,    33,    31,    52,
       9,    10,    11,    12,    13,    14,    15,    16,    61,    62,
      63,    64,    65,    66,    67,    68,    69,   117,    71,   115,
     116,   121,    31,    32,    30,   123,    35,    11,    12,    13,
      14,    30,   242,    21,    22,    88,     6,   137,    29,   135,
     136,   139,   372,    31,    29,    29,   146,   146,   144,   347,
     146,   146,   146,    23,   154,   146,   146,   146,    12,    13,
     358,    10,    11,    12,    13,    14,    15,    16,   121,     1,
      29,     3,     4,     5,     6,    31,   176,    31,    10,    21,
      22,   134,    31,    32,   137,    17,    18,    19,    20,    31,
     190,   365,    11,    12,    13,    14,    12,    13,    30,    21,
      22,   154,    31,   203,     3,     4,     5,     6,     7,     8,
     163,    10,    31,    32,    31,    31,    32,    17,    17,    18,
      19,    20,    21,    22,    31,    24,    25,    26,    27,    31,
      32,    30,    29,    30,    33,    34,     6,   190,   191,    31,
     240,   241,   242,   353,    13,   245,    13,    12,    13,    49,
     203,    13,    52,    23,    11,    12,    13,    14,    29,   212,
      29,    61,   262,    29,    31,   375,    31,    32,    29,    31,
      32,    71,    31,   273,    31,   228,   229,   230,   231,   232,
     233,   234,   235,   236,    17,   238,   239,   240,   241,    10,
      11,    12,    13,    14,    15,    16,   249,    13,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    40,   261,    34,
      31,    32,    31,    32,    29,    31,    49,   317,    29,    52,
     273,   121,    29,   276,    11,    12,    13,    14,    61,    62,
      63,    64,    65,    66,    67,    68,    69,   137,    71,    31,
      32,     1,    29,     3,     4,     5,     6,    31,    32,    31,
      10,    31,    32,   353,   154,   351,   352,    17,    18,    19,
      20,    12,    13,    14,   317,    12,    13,   320,    13,    33,
      30,    29,   372,    13,    29,   375,     6,   373,   374,    13,
      31,    32,   382,   382,    31,    32,    31,    32,   121,    33,
     190,    31,    32,    31,   347,    29,    33,     1,    31,     3,
       4,     5,     6,   203,   137,   358,    10,    31,    32,    11,
      12,    13,    14,    17,    18,    19,    20,     3,     4,     5,
       6,   154,   375,    30,    10,    30,    30,    30,   228,    31,
     163,    17,    18,    19,    20,    30,   236,    17,   238,    29,
     240,   241,    31,    32,    30,    31,    12,    13,    14,   249,
      29,   251,    12,    13,    14,    29,    31,   190,   191,   259,
      31,   261,    29,    12,    13,    31,    32,    29,    31,    49,
     203,    31,    52,   273,    11,    12,    13,    14,    31,   212,
      29,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       6,    71,     6,    31,    31,   228,   229,   230,   231,   232,
     233,   234,   235,   236,    31,   238,    31,   240,   241,    10,
      11,    12,    13,    14,    15,    16,   249,   317,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    31,   261,    31,
      31,    12,    13,    14,    31,    11,    12,    13,    14,    29,
     273,   121,    34,   276,    31,    31,     0,   347,    29,     3,
       4,     5,     6,     7,     8,    31,    10,   137,   358,    12,
      13,    14,    34,    17,    18,    19,    20,    21,    22,    31,
      24,    25,    26,    27,   154,   375,    30,    29,    31,    33,
      29,    12,    13,   163,   317,    33,    31,   320,    12,    13,
      14,    31,     3,     4,     5,     6,     7,     8,    29,    10,
      29,    11,    12,    13,    14,    29,    17,    18,    19,    20,
     190,   191,    31,    24,   347,    26,    27,    12,    13,    30,
      33,    31,    33,   203,    31,   358,    11,    12,    13,    14,
      34,    20,   212,   139,    29,   120,    -1,    -1,    85,    -1,
      -1,    -1,   375,    -1,    -1,    -1,    31,    32,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    17,   238,    -1,
     240,   241,    11,    12,    13,    14,    -1,    -1,    -1,   249,
      -1,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,    31,     3,     4,     5,     6,    -1,    -1,    49,
      10,    -1,    52,   273,    -1,    -1,   276,    17,    18,    19,
      20,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      30,    71,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    12,    13,    14,     0,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    31,    32,   317,    29,    35,
     320,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,   121,    11,    12,    13,    14,     0,   347,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,   137,   358,    -1,
      -1,    -1,    31,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,   154,   375,    30,    -1,    -1,    33,
      -1,    -1,    -1,   163,     1,    -1,     3,     4,     5,     6,
      17,    -1,    -1,    10,    -1,    11,    12,    13,    14,    -1,
      17,    18,    19,    20,    -1,    -1,    11,    12,    13,    14,
     190,   191,    -1,    30,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    49,   203,    -1,    52,    31,    32,    11,    12,
      13,    14,   212,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    -1,    29,    -1,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,   238,    -1,
     240,   241,    10,    11,    12,    13,    14,    15,    16,   249,
      -1,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,     0,    31,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,   273,   121,    -1,   276,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
     137,    -1,    30,    -1,    -1,    33,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,     0,    -1,   154,     3,     4,
       5,     6,     7,     8,    -1,    10,   163,   317,    31,    32,
     320,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    11,
      12,    13,    14,   190,   191,    -1,    -1,   347,    -1,    -1,
       1,    -1,     3,     4,     5,     6,   203,    29,   358,    10,
      -1,    -1,    -1,    -1,    -1,   212,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,   375,    -1,    -1,    -1,    30,
      -1,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      17,   238,    -1,   240,   241,    11,    12,    13,    14,    -1,
      -1,    -1,   249,    -1,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,   261,    31,     3,     4,     5,     6,
      -1,    -1,    49,    10,    -1,    52,   273,    -1,    -1,   276,
      17,    18,    19,    20,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    30,    71,     0,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    11,    12,    13,
      14,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
     317,    26,    27,   320,    -1,    30,    -1,    31,    33,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,   121,    17,    18,    19,    20,     0,
     347,    -1,     3,     4,     5,     6,     7,     8,    30,    10,
     137,   358,    11,    12,    13,    14,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,   154,   375,    30,
      29,    -1,    33,    -1,    -1,    -1,   163,     1,    -1,     3,
       4,     5,     6,    17,    -1,    -1,    10,    -1,    11,    12,
      13,    14,    -1,    17,    18,    19,    20,    -1,    -1,    11,
      12,    13,    14,   190,   191,    -1,    30,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    49,   203,    -1,    52,    31,
      32,    11,    12,    13,    14,   212,    -1,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    -1,    29,
      -1,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,   238,    -1,   240,   241,    -1,    11,    12,    13,    14,
      -1,    -1,   249,    -1,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,   261,     0,    31,    32,     3,     4,
       5,     6,     7,     8,    -1,    10,   273,   121,    -1,   276,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,   137,    -1,    30,    -1,    -1,    33,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,     0,    -1,
     154,     3,     4,     5,     6,     7,     8,    -1,    10,   163,
     317,    31,    32,   320,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    11,    12,    13,    14,   190,   191,    -1,    -1,
     347,    -1,    -1,     1,    -1,     3,     4,     5,     6,   203,
      29,   358,    10,    -1,    -1,    -1,    -1,    -1,   212,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,   375,    -1,
      -1,    -1,    30,    -1,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    17,   238,    -1,   240,   241,    11,    12,
      13,    14,    -1,    -1,    -1,   249,    -1,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    29,   261,    -1,     3,
       4,     5,     6,    -1,    -1,    49,    10,    -1,    52,   273,
      -1,    -1,   276,    17,    18,    19,    20,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    30,    71,     0,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    11,    12,    13,    14,    17,    18,    19,    20,    21,
      22,    -1,    24,   317,    26,    27,   320,    -1,    30,    29,
      -1,    33,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,   121,    17,    18,
      19,    20,     0,   347,    -1,     3,     4,     5,     6,     7,
       8,    30,    10,   137,   358,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
     154,   375,    30,    -1,    -1,    33,    17,    -1,    -1,   163,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    -1,    11,    12,    13,    14,    17,    18,    19,    20,
      11,    12,    13,    14,    -1,    -1,   190,   191,    49,    30,
      -1,    52,    31,    32,    -1,    -1,    -1,    -1,    -1,   203,
      31,    32,    -1,    64,    -1,    66,    67,    -1,   212,    -1,
      71,    17,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,   238,    -1,   240,   241,    31,    32,
      -1,    -1,    35,    49,    -1,   249,    52,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,    -1,    65,
     121,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,   273,
      -1,    -1,   276,    -1,    -1,    -1,   137,     0,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,   154,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,   317,    -1,   121,   320,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    -1,   190,
      -1,   137,    -1,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,   203,   347,    -1,    -1,    30,     1,   154,     3,
       4,     5,     6,    -1,   358,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,   228,   229,   230,
     231,   375,   233,   234,    -1,   236,    30,   238,    -1,   240,
     241,    -1,    -1,    -1,   190,    17,    -1,    -1,   249,    -1,
     251,   252,   253,   254,    -1,   256,   257,   203,   259,    -1,
     261,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,   273,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    29,   228,   229,   230,   231,   232,   233,   234,    -1,
     236,    -1,   238,    -1,   240,   241,    -1,    -1,    -1,    71,
      -1,    -1,    17,   249,    -1,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,    -1,   261,   317,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,     1,   273,     3,     4,
       5,     6,    -1,    -1,    49,    10,    -1,    52,    30,    31,
      32,    -1,    17,    18,    19,    20,   347,    -1,    63,   121,
      -1,    -1,    -1,    -1,    -1,    30,    71,   358,    -1,     1,
      -1,     3,     4,     5,     6,   137,    -1,    -1,    10,    -1,
      -1,   317,    -1,    -1,   375,    17,    18,    19,    20,    -1,
      -1,     1,   154,     3,     4,     5,     6,    -1,    30,    -1,
      10,    17,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,   347,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      30,    -1,   358,    -1,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,   137,    49,    -1,    -1,    52,    -1,    -1,   375,
      -1,   203,    -1,     3,     4,     5,     6,    -1,    -1,   154,
      10,    -1,    -1,    69,    -1,    71,    -1,    17,    18,    19,
      20,    17,    -1,    -1,    -1,    -1,   228,   229,   230,   231,
      30,   233,   234,    -1,   236,    -1,   238,    -1,   240,   241,
      -1,    -1,    -1,    -1,    -1,   190,    -1,   249,    -1,   251,
     252,   253,   254,    49,   256,   257,    52,   259,   203,   261,
      -1,    -1,    -1,    -1,    -1,   121,    62,    -1,    -1,    -1,
      -1,   273,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,   137,    -1,   228,   229,   230,    -1,    -1,    -1,    -1,
      -1,   236,    -1,   238,    -1,   240,   241,    -1,   154,    -1,
      -1,    -1,    -1,    -1,   249,    -1,   251,   252,   253,    -1,
      -1,    -1,    -1,    -1,   259,   317,   261,     9,    10,    11,
      12,    13,    14,    15,    16,   121,    -1,    -1,   273,    -1,
      -1,    -1,    -1,     1,   190,     3,     4,     5,     6,    31,
      32,   137,    10,    35,    -1,   347,    -1,   203,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,   358,    -1,   154,    -1,
      -1,    -1,    30,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,   317,   375,     3,     4,     5,     6,    -1,    -1,
     236,    10,   238,    -1,   240,   241,    31,    32,    17,    18,
      19,    20,    -1,   249,   190,    -1,    -1,    -1,    -1,    -1,
      29,    30,   347,   259,    -1,   261,     1,   203,     3,     4,
       5,     6,    -1,   358,    -1,    10,    -1,   273,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
     375,    -1,   228,   229,    -1,    30,    -1,    -1,    -1,    -1,
     236,    -1,   238,    -1,   240,   241,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,    -1,   251,   252,    -1,    -1,    -1,
      -1,   317,    -1,   259,    -1,   261,     0,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,   273,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,   347,    26,    27,    -1,    -1,    30,    -1,    -1,    33,
      -1,    -1,   358,    -1,    -1,     0,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,   375,
      -1,   317,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,     0,    33,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,   347,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,   358,    26,    27,    -1,    -1,    30,     0,    -1,
      33,     3,     4,     5,     6,     7,     8,    -1,    10,   375,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,     0,
      -1,    33,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
       0,    -1,    33,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,     0,    -1,    33,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,     0,    -1,    33,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    -1,    30,     0,    -1,    33,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,     0,    -1,    33,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    30,     0,    -1,    33,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,     0,    -1,    33,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    -1,    30,     0,    -1,    33,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,     0,    -1,
      33,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,     0,
      -1,    33,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
       0,    -1,    33,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    33,    34,     1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    -1,    30,    31,    -1,    -1,
      -1,    17,    18,    19,    20,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    -1,    30,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    -1,    30,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,     3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,
      30,    -1,    -1,    -1,    -1,    17,    18,    19,    20,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    30,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    -1,    30,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    30,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    30,    31,    32,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    -1,    -1,    35,    -1,
      29,    30,    -1,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    -1,    35,    -1,    29,    30,    -1,    -1,    -1,
      -1,    35,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    35,    -1,
      -1,    30,    31,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    31,    32,    -1,
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
      32,    -1,    -1,    35,    -1,    29,    -1,    -1,    -1,    -1,
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
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    29,    -1,    -1,
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
      -1,    -1,    31,    -1,    -1,    -1,    35,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    30,    31,    32,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,     9,    10,    11,
      12,    13,    14,    15,    16,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,     9,
      10,    11,    12,    13,    14,    15,    16,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,     9,    10,    11,    12,    13,    14,    15,    16,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,     9,    10,    11,    12,    13,    14,    15,
      16,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
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
      29,    30,     9,    10,    11,    12,    13,    14,    15,    16,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,     9,    10,    11,    12,    13,    14,    15,    16,
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
      15,    16,    -1,    -1,    -1,    -1,    29,    10,    11,    12,
      13,    14,    15,    16,    29,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    29,    10,    11,    12,
      13,    14,    15,    16,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    17,    18,
      19,    20,    21,    22,    24,    26,    27,    30,    33,    37,
      38,    39,    40,    42,    48,    53,    54,    55,    56,    57,
      58,    59,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    73,    74,    75,    76,    77,    78,    30,    30,
      23,    23,    30,    30,     1,    59,    59,    49,     0,    39,
      29,    13,    12,    14,    11,    10,    15,    16,     9,    35,
      68,    30,    29,    75,    75,    59,     1,    59,    59,    60,
      29,    29,    31,    40,    50,    51,    52,    53,    76,     1,
      62,    68,     1,    63,     1,    64,     1,    65,     1,    67,
       1,    65,     1,    65,     1,    68,     1,    61,    59,    71,
      72,    30,    41,    31,    31,    31,    31,    29,    34,    52,
      75,    32,    31,    43,    29,    29,    29,    48,    48,    60,
      59,    45,    46,    47,    76,    25,    25,    29,    31,    32,
      75,    48,    48,    60,    44,    47,    31,    48,    53,     3,
       4,     5,     6,    20,    30,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    73,    74,    75,    77,    78,
       6,     6,     7,     8,    24,    26,    27,    33,    48,    54,
      55,    56,    57,    58,    59,     3,     4,     5,     6,    20,
      30,    69,    70,    73,    74,    75,    77,    78,     3,     4,
       5,     6,    20,    30,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    73,    74,    75,    77,    78,     6,
      29,    33,    41,    21,    22,     6,    59,    59,    13,    12,
      14,    11,    10,    15,    16,     9,    35,    68,    30,    30,
      30,    30,    30,     1,    59,    49,    29,    59,    68,    30,
      59,    13,    12,    14,    11,    10,    15,    16,     9,    35,
      68,    30,    49,    29,    23,    23,    31,     1,     3,     4,
       5,     6,    20,    30,    62,    68,    69,    70,    73,    74,
      75,    77,    78,     1,    63,     1,    64,     1,    65,     1,
      67,     1,    65,     1,    65,     1,    68,     1,    61,    72,
      75,    59,     1,    59,    60,    29,    29,    50,    31,    72,
      31,     1,     3,     4,     5,     6,    20,    30,    62,    68,
      69,    70,    73,    74,    75,    77,    78,     1,    63,     1,
      64,     1,    65,     1,    67,     1,    65,     1,    65,     1,
      68,     1,    61,    72,    50,    59,    68,    30,    31,    31,
      31,    31,    31,    29,    34,    31,    59,    68,    30,    31,
      34,    31,    72,    29,    29,    33,    48,    48,    60,    31,
      72,    31,    49,    25,    25,    29,    31,    50,    48,    48,
      60,    34,    31,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    39,    41,
      40,    40,    43,    44,    42,    45,    45,    46,    46,    47,
      49,    48,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    56,    56,    56,
      56,    57,    57,    58,    59,    59,    59,    60,    60,    61,
      61,    61,    62,    62,    62,    63,    63,    63,    64,    64,
      64,    65,    65,    65,    65,    65,    66,    66,    66,    67,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    74,    75,
      76,    76,    76,    76,    77,    77,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     0,
       4,     2,     0,     0,     8,     0,     1,     3,     1,     2,
       0,     4,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     2,     5,     7,     5,
       7,     3,     3,     9,     1,     3,     3,     0,     1,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     4,
       1,     3,     1,     0,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1
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
#line 121 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2736 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 121 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2742 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 121 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 2748 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2754 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2760 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2766 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2772 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2778 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2784 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2790 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2796 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2802 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2808 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2814 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2820 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2826 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2832 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2838 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2844 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2850 "src/bison/grammar.c"
        break;

    case YYSYMBOL_41_1: /* @1  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2856 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2862 "src/bison/grammar.c"
        break;

    case YYSYMBOL_43_2: /* @2  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2868 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2874 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2880 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2886 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2892 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2898 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2904 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2910 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2916 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2922 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2928 "src/bison/grammar.c"
        break;

    case YYSYMBOL_60_expression_opt: /* expression.opt  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2934 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2940 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2946 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2952 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2958 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2964 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2970 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2976 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2982 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 2988 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 2994 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3000 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id_expr: /* id_expr  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3006 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 121 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 3012 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 120 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3018 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3024 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 122 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3030 "src/bison/grammar.c"
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
#line 126 "src/bison/grammar.y"
             {
        show_error((yyloc), "ISO C-IPL forbids an empty translation unit\n");
    }
#line 3341 "src/bison/grammar.c"
    break;

  case 4: /* external_declaration_list: external_declaration_list external_declaration  */
#line 131 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 3347 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration  */
#line 132 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 3353 "src/bison/grammar.c"
    break;

  case 8: /* external_declaration: statement  */
#line 137 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[0].ast));
    }
#line 3363 "src/bison/grammar.c"
    break;

  case 9: /* @1: %empty  */
#line 144 "src/bison/grammar.y"
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
            Symbol *declared = context_declare_variable(current_context, (yyvsp[0].sym));
            symbol_update_type(declared, decl_type);
            (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 3389 "src/bison/grammar.c"
    break;

  case 10: /* var_declaration: type id @1 ';'  */
#line 164 "src/bison/grammar.y"
          {
        (yyval.ast) = (yyvsp[-1].ast) ? ast_declaration_init((yyvsp[-1].ast)) : NULL;
    }
#line 3397 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 167 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
    }
#line 3407 "src/bison/grammar.c"
    break;

  case 12: /* @2: %empty  */
#line 174 "src/bison/grammar.y"
                                   {
        p_ctx_name = 1;
        Symbol *sym = context_has_symbol(current_context, (yyvsp[-1].sym));
        SymbolTypes decl_type = symbol_type_from_str((yyvsp[-2].pchar));

        // always push a context for the function even if not valid so is possible to pop later
        previous_context = current_context;
        list_push(&contexts, context_init((yyvsp[-1].sym)->name));
        current_context = list_peek_last(&contexts);

        if (sym) {
            if (!sym->is_fn) {
                show_error((yyloc), BCYN "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
            } else if (sym->type != decl_type) {
                show_error((yylsp[-2]), "conflicting types for " BBLU "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            } else {
                show_error((yylsp[-1]), "redefinition of " BBLU "'%s'\n" RESET, (yyvsp[-1].sym)->name);
            }
            (yyval.ast) = NULL;
        } else {
            Symbol *declared = context_declare_function(previous_context, (yyvsp[-1].sym));
            if (!declared) {
                show_error((yyloc), BCYN "'%s'" RESET " redeclared as different kind of symbol\n", (yyvsp[-1].sym)->name);
                (yyval.ast) = NULL;
            } else {
                symbol_update_type(declared, decl_type);
                (yyval.ast) = ast_symref_init(symbol_init_copy(declared));
            }
        }

        // push scope for the function s:1
        context_push_scope(current_context);

        symbol_free((yyvsp[-1].sym));
        free((yyvsp[-2].pchar));
    }
#line 3448 "src/bison/grammar.c"
    break;

  case 13: /* $@3: %empty  */
#line 209 "src/bison/grammar.y"
                         {
        // hack to save the scope of params and append to the scope of the body
        params_scope = scope_init_copy(stack_peek(&current_context->scopes));
        stack_pop(&current_context->scopes, free_scope_cb);
    }
#line 3458 "src/bison/grammar.c"
    break;

  case 14: /* func_declaration: type id '(' @2 param_list.opt ')' $@3 compound_stmt  */
#line 213 "src/bison/grammar.y"
                    {
        (yyval.ast) = ast_userfunc_init(current_context, (yyvsp[-4].ast), ast_params_init((yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = 1;
    }
#line 3468 "src/bison/grammar.c"
    break;

  case 15: /* param_list.opt: %empty  */
#line 220 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 3474 "src/bison/grammar.c"
    break;

  case 17: /* params_list: params_list ',' param_decl  */
#line 224 "src/bison/grammar.y"
                                        { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3480 "src/bison/grammar.c"
    break;

  case 18: /* params_list: param_decl  */
#line 225 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3486 "src/bison/grammar.c"
    break;

  case 19: /* param_decl: type id  */
#line 228 "src/bison/grammar.y"
                    {
        symbol_update_context((yyvsp[0].sym), current_context);
        symbol_update_type((yyvsp[0].sym), symbol_type_from_str((yyvsp[-1].pchar)));
        Symbol *sym = context_has_symbol(current_context, (yyvsp[0].sym));
        if (sym) {
            show_error_range((yylsp[0]), "redefinition of parameter " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        } else {
            context_declare_variable(current_context, (yyvsp[0].sym));
            (yyval.ast) = ast_symref_init(symbol_init_copy((yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
        free((yyvsp[-1].pchar));
    }
#line 3505 "src/bison/grammar.c"
    break;

  case 20: /* $@4: %empty  */
#line 244 "src/bison/grammar.y"
                   {
        parent_stacknode_ref = context_get_current_stacknode_ref();
        // hack to update the current scope
        if (params_scope) {
            stack_push(&current_context->scopes, params_scope);
            current_context->current_scope = ((Scope *)stack_peek(&current_context->scopes))->index;
            params_scope = NULL;
        } else {
            context_push_scope(current_context);
        }
    }
#line 3521 "src/bison/grammar.c"
    break;

  case 21: /* compound_stmt: '{' $@4 block_item_list.opt '}'  */
#line 254 "src/bison/grammar.y"
                              {
        (yyval.ast) = ast_blockitems_init((yyvsp[-1].list));
        context_pop_scope(current_context);
        if (parent_stacknode_ref) {
            parent_stacknode_ref = parent_stacknode_ref->parent;
        }
    }
#line 3533 "src/bison/grammar.c"
    break;

  case 22: /* block_item_list.opt: block_item_list  */
#line 263 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 3539 "src/bison/grammar.c"
    break;

  case 23: /* block_item_list.opt: %empty  */
#line 264 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3545 "src/bison/grammar.c"
    break;

  case 24: /* block_item_list: block_item_list block_item  */
#line 267 "src/bison/grammar.y"
                                            { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3551 "src/bison/grammar.c"
    break;

  case 25: /* block_item_list: block_item  */
#line 268 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3557 "src/bison/grammar.c"
    break;

  case 34: /* io_stmt: READ '(' id ')' ';'  */
#line 283 "src/bison/grammar.y"
                             {
        Symbol *func = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        Symbol *param = context_search_symbol_scopes(current_context, (yyvsp[-2].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(func)), ast_symref_init(symbol_init_copy(param)));
        symbol_free((yyvsp[-4].sym));
        symbol_free((yyvsp[-2].sym));
    }
#line 3569 "src/bison/grammar.c"
    break;

  case 35: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 290 "src/bison/grammar.y"
                                   {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[-4].sym));
        (yyval.ast) = ast_builtinfn_init(ast_symref_init(symbol_init_copy(sym)), (yyvsp[-2].ast));
        symbol_free((yyvsp[-4].sym));
    }
#line 3579 "src/bison/grammar.c"
    break;

  case 36: /* expr_stmt: expression ';'  */
#line 297 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 3585 "src/bison/grammar.c"
    break;

  case 37: /* cond_stmt: IF '(' expression ')' compound_stmt  */
#line 300 "src/bison/grammar.y"
                                                          {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 3593 "src/bison/grammar.c"
    break;

  case 38: /* cond_stmt: IF '(' expression ')' compound_stmt ELSE compound_stmt  */
#line 303 "src/bison/grammar.y"
                                                             {
        (yyval.ast) = ast_flow_init(current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3601 "src/bison/grammar.c"
    break;

  case 39: /* cond_stmt: IF '(' error ')' compound_stmt  */
#line 306 "src/bison/grammar.y"
                                                {
        show_error((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[0].ast));
        yyerrok;
    }
#line 3612 "src/bison/grammar.c"
    break;

  case 40: /* cond_stmt: IF '(' error ')' compound_stmt ELSE compound_stmt  */
#line 312 "src/bison/grammar.y"
                                                        {
        show_error((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        yyerrok;
    }
#line 3624 "src/bison/grammar.c"
    break;

  case 41: /* jmp_stmt: RETURN expression ';'  */
#line 321 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyvsp[-1].ast)); }
#line 3630 "src/bison/grammar.c"
    break;

  case 42: /* jmp_stmt: RETURN error ';'  */
#line 322 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-2]), WHT "'return'" RESET " with no value\n");
        (yyval.ast) = NULL;
        yyerrok;
    }
#line 3640 "src/bison/grammar.c"
    break;

  case 43: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 329 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init(current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 3648 "src/bison/grammar.c"
    break;

  case 45: /* expression: unary_expr '=' logical_or_expr  */
#line 335 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 3654 "src/bison/grammar.c"
    break;

  case 46: /* expression: unary_expr '=' error  */
#line 336 "src/bison/grammar.y"
                           {
        show_error((yyloc), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3665 "src/bison/grammar.c"
    break;

  case 47: /* expression.opt: %empty  */
#line 344 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 3671 "src/bison/grammar.c"
    break;

  case 50: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 349 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3680 "src/bison/grammar.c"
    break;

  case 51: /* logical_or_expr: logical_or_expr OR error  */
#line 353 "src/bison/grammar.y"
                               {
        show_error((yylsp[0]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3692 "src/bison/grammar.c"
    break;

  case 53: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 363 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3701 "src/bison/grammar.c"
    break;

  case 54: /* logical_and_expr: logical_and_expr AND error  */
#line 367 "src/bison/grammar.y"
                                 {
        show_error((yylsp[0]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3713 "src/bison/grammar.c"
    break;

  case 56: /* eq_expr: eq_expr EQ rel_expr  */
#line 377 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3722 "src/bison/grammar.c"
    break;

  case 57: /* eq_expr: eq_expr EQ error  */
#line 381 "src/bison/grammar.y"
                       {
        show_error((yylsp[0]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3734 "src/bison/grammar.c"
    break;

  case 59: /* rel_expr: rel_expr REL list_expr  */
#line 391 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3743 "src/bison/grammar.c"
    break;

  case 60: /* rel_expr: rel_expr REL error  */
#line 395 "src/bison/grammar.y"
                         {
        show_error((yylsp[0]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3755 "src/bison/grammar.c"
    break;

  case 62: /* list_expr: add_expr DL_DG list_expr  */
#line 405 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3764 "src/bison/grammar.c"
    break;

  case 63: /* list_expr: add_expr COLON list_expr  */
#line 409 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3773 "src/bison/grammar.c"
    break;

  case 64: /* list_expr: add_expr DL_DG error  */
#line 413 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3785 "src/bison/grammar.c"
    break;

  case 65: /* list_expr: add_expr COLON error  */
#line 420 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3797 "src/bison/grammar.c"
    break;

  case 67: /* add_expr: add_expr ADD mult_expr  */
#line 430 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3806 "src/bison/grammar.c"
    break;

  case 68: /* add_expr: add_expr ADD error  */
#line 434 "src/bison/grammar.y"
                         {
        show_error((yylsp[0]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3818 "src/bison/grammar.c"
    break;

  case 70: /* mult_expr: mult_expr MULT unary_expr  */
#line 444 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3827 "src/bison/grammar.c"
    break;

  case 71: /* mult_expr: mult_expr MULT error  */
#line 448 "src/bison/grammar.y"
                           {
        show_error((yylsp[0]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
        free((yyvsp[-1].pchar));
        ast_free((yyvsp[-2].ast));
        yyerrok;
    }
#line 3839 "src/bison/grammar.c"
    break;

  case 73: /* unary_expr: unary_ops unary_expr  */
#line 458 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 3848 "src/bison/grammar.c"
    break;

  case 79: /* postfix_expr: id_expr '(' arg_expr_list.opt ')'  */
#line 471 "src/bison/grammar.y"
                                        {
        (yyval.ast) = ast_funcall_init((yyvsp[-3].ast), ast_params_init((yyvsp[-1].list)));
    }
#line 3856 "src/bison/grammar.c"
    break;

  case 80: /* arg_expr_list: expression  */
#line 476 "src/bison/grammar.y"
                          { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 3862 "src/bison/grammar.c"
    break;

  case 81: /* arg_expr_list: arg_expr_list ',' expression  */
#line 477 "src/bison/grammar.y"
                                   { list_push(&(yyval.list), (yyvsp[0].ast)); }
#line 3868 "src/bison/grammar.c"
    break;

  case 83: /* arg_expr_list.opt: %empty  */
#line 481 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 3874 "src/bison/grammar.c"
    break;

  case 87: /* primary_expr: '(' expression ')'  */
#line 487 "src/bison/grammar.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 3880 "src/bison/grammar.c"
    break;

  case 88: /* id_expr: id  */
#line 490 "src/bison/grammar.y"
            {
        Symbol *sym = context_search_symbol_scopes(current_context, (yyvsp[0].sym));
        if (!sym) {
            show_error((yyloc), BCYN "'%s'" RESET " undeclared (first use in this function)\n", (yyvsp[0].sym)->name);
            (yyval.ast) = NULL;
        }   else {
            symbol_update_context((yyvsp[0].sym), current_context);
            (yyval.ast) = ast_symref_init(symbol_init_copy(sym ? sym : (yyvsp[0].sym)));
        }
        symbol_free((yyvsp[0].sym));
    }
#line 3896 "src/bison/grammar.c"
    break;

  case 92: /* type: INT LIST  */
#line 508 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3908 "src/bison/grammar.c"
    break;

  case 93: /* type: FLOAT LIST  */
#line 515 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 3920 "src/bison/grammar.c"
    break;

  case 94: /* constant: NUMBER_REAL  */
#line 524 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init(K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 3926 "src/bison/grammar.c"
    break;

  case 95: /* constant: NUMBER_INT  */
#line 525 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init(K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3932 "src/bison/grammar.c"
    break;

  case 96: /* constant: NIL  */
#line 526 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init(K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 3938 "src/bison/grammar.c"
    break;

  case 97: /* string_literal: STR_LITERAL  */
#line 529 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 3947 "src/bison/grammar.c"
    break;


#line 3951 "src/bison/grammar.c"

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

#line 535 "src/bison/grammar.y"


void yyerror(int l, int c, const char *s, ...) {
    error_cursor = (Cursor){.line=l, .col=c};
    last_line_ref = curr_line_buffer;
    // enable error print when bison calls yyerror()
    /* if (s) CIPL_PERROR_CURSOR("%s\n", last_line_ref, error_cursor, s); */
    // prevent count up errors when bison calls yyerror()
    if (!s) {
        ++errors_count;
    }
}
