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
#define YYLAST   10644

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  663

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
     475,   482,   483,   489,   492,   499,   506,   513,   517,   523,
     524,   525,   530,   537,   538,   541,   542,   546,   551,   558,
     559,   563,   568,   575,   576,   580,   585,   592,   593,   597,
     602,   609,   610,   614,   618,   623,   628,   633,   640,   641,
     645,   650,   657,   658,   662,   667,   674,   675,   681,   682,
     683,   684,   687,   688,   708,   709,   710,   716,   717,   720,
     730,   731,   738,   742,   749,   752,   753,   754,   761,   770,
     771,   772,   775
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

#define YYPACT_NINF (-411)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-143)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6165,    24,  3527,  4165, 10123,  3423,   398,  3105,  3453,  3634,
     246,   255,     9,    11,    14,    18,  2323,  3206,   127,    23,
    6197,  6229,  6261,  6293,  6325,  6357,  6389,  6421,  6453,  6485,
    6517,   -18,    51,   584,   461,  1256,  1514,   868,  3010, 10136,
    8904, 10147, 10160,  3774,    12, 10171,  8933,  3278,  3921,  4065,
    4272,  4343,  3921,  3921,  6549,  6581,  6613,  6645,  7995,  6677,
     262,   272,  6709,   327,  6741,  1143,  6773,  8024,  6805,  3684,
   10184,   -15,  1608,  3171,    -7,   490,  -411,  4114,  6837,  6869,
    8030,  8048,  8065,  8082,  8099,  8116,  8133,  8150,  8167, 10195,
   10208,   182,   140,   526,  6901,    38,   715, 10339,    20, 10352,
   10362,  1714,  1642,   789,   551,  2426,   654,  1016,  1647,  1657,
    1690,  2715,    57,    90,   113,  9512,   125,   133,   150,  9525,
     157,  1837,    17,    49,  6933,  6965, 10219, 10232,  8858,  7893,
     897,   158,   933,   987,  1033,  1174,    81, 10375,   663, 10385,
     607, 10398,  1730, 10408,  1765, 10421, 10431, 10444,  1905, 10454,
    2033, 10467, 10477, 10490,   145,  9012,   310,   403,   179,  6997,
     206,  7029,    70,  7061,   223,   190,   199,    59,   220,   100,
     112,  1091,  1405,  3733,  7093,  3835,  7893,  1298,  7125,  1334,
     360,  8184, 10243,  7157,   535,   230,   549,   579,   609,   162,
    7189,    70,  7221,  7253,  7285,  7317,  7349,  7381,  7413,  7445,
    7925,  1373,  7925,  1443,  2705,   236, 10256,   240,  1487,   652,
     239,   318,   708,   258,  7477,  7925,  7509,  7925,   674,   674,
     818,   265,   759,   287,  7541,  7573,   294,   297,  9538,   325,
    7605,   265,  7925,  7925,  7925,  7925,  7637,  7669,  7701,  7733,
    7765,  1999,  9551,  9564,  9577,  3052,  8201,    73,    -3,   248,
     491,   527,   757,   973,  9590,  8950,  9603,  9616,  3331,  9629,
     776,   880, 10500, 10513, 10523,   965,  8218,  8933, 10536, 10546,
    2390, 10559,   335,  8967,  8235,  8252,  8269,  8286,  8303,  8252,
    8252,  8320,   224,   333,    21,    46,    54,    93,  8337,   127,
    1572,  1689,  1729,  1764,  1878,  1963,   346,  3774,  9026,  9039,
    9053,   339,  8354,   312,  1465,   717,   411,   451,  2688,   636,
    9066,  8984,  9080,  9093,   445,  9107,  2080,  2120,  2155,  2269,
    2354,  8887,    92,  2471,  9001,  8371,  8388,  8405,  8422,  8439,
    8388,  8388,  8456,   832,   289,   379,  8916,   103,   105,   124,
     136,  8473,   127,  1803,  2194,  2511,  2546,  2585,  2745,   348,
    2660,   383, 10315, 10328,   354,  9642,   363,  8490,  8507,  8524,
    8541,  8558,  8575,  8592,  8609,  8626,  9655,  9668,   182,  9681,
     376, 10569, 10582,   182,  1848,  2239,  2630,   592,  8643,  4329,
    8967,  9850,  9863,  3359,  9876,   373,  9889,  9902,  1828,   598,
    3401,   508,  2817,   454,  2043,   775,  1034,  1061,  3535,   128,
     291,   326,  2862,   357,  2902,  1541,  2937,  8660,  3136,  3958,
   10267,   381,   490,  3227,   900,  9694,   387,  8677,  8694,  8711,
    8728,  8745,  8762,  8779,  8796,  8813,  9120,  9134,   182,  3302,
     830,  9188,  9201,   565,  8830,  9215,  9001,  9228,  9242,   750,
    9255,   418,  9269,  9282,  1938,   706,  3650,  1131,  3263,  1518,
    2434,   744,   875,  1068, 10628,   406,   276,   350,  2976,  3490,
    3567,  3854,  4184,  4301,   359,  4367,  1932,  4414,  8847,  4502,
    3964, 10280,   401,   490,  4534,  4571,  9707,  9720,  9915,   554,
    9928,   915,  9941,  1118,  9954,  1238,  9967,  9980,  9993,  1268,
   10006,  1299, 10019, 10032, 10045,   194,   395, 10592, 10605,   400,
    9733,   405, 10058, 10071,   182,   409,   413,  9746,   415,   435,
    9759,   437,  2228,   450,  4606,  4682,   439,  4717,   484,  9147,
    9161,  9296,  1529,  9309,  1352,  9323,  1207,  9336,  1251,  9350,
    9363,  9377,  2332,  9390,  2722,  9404,  9417,  9431,   559,   460,
    9772,   465,  9444,  9458,   182,   467,   476,  9785,   479,   496,
    9798,   501,  2619,   493,  4645,  4753,   500,  9811, 10615, 10084,
   10097,   515,   522,   119,   525,   137,   175,  4462,  7797,  3733,
    4785,  4009,  4820,  4855,  9174,  9471,  9485,   524,   529,   202,
     586,   228,   241,  7829,  7861,  3733,  4891,  7989,  4923, 10110,
    4955,  4990,  5025,  5060,  5095,  5130,  5165,  5200,  7893,  5235,
    7893,  5270,   599, 10291,   632,  9498,  5306,  5338,  5370,  5402,
    5434,  5466,  5498,  5530,  7957,  5562,  7957,  5594,   642, 10304,
     647,  5626,  7893,  5661,  7893,   674,   674,  2777,  5697,  7957,
    5729,  7957,   674,   674,  3025,  5761,  5796,   556,   589,  9824,
     606,  5832,  5864,   649,   655,  9837,   666,  7893,  7893,  7893,
    7893,  7957,  7957,  7957,  7957,  5896,  5931,  5966,  6001,  6037,
    6069,  6101,  6133
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
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -411,  -411,  -411,   680,    61,  -411,  -411,  -411,  -411,  -411,
     511,  -411,   498,     6,  -286,  -410,  -411,   572,    72,    79,
      83,   159,  -411,   164,   216,     0,  -145,  4048,  3865,  3730,
    3626,  3021,  3395,  3201,  1206,  1597,  1988,  -411,  -364,  2379,
     808,     1,  2770,  -400
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,   130,    23,   191,   223,   162,   210,
     185,   186,   187,   290,    75,   131,   132,   133,   134,   291,
     292,   293,   135,   294,   295,   296,   123,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   157,   158,    42,
      72,   136,    45,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    44,   516,   412,   496,   509,    24,   358,   -85,   499,
      62,    79,    64,    93,   125,    66,    71,    74,   261,    68,
      31,    44,   402,    76,    -4,   127,    24,    46,   205,   -85,
     207,    46,    47,    48,    49,    50,    51,    52,    53,   -20,
      63,    94,    65,    95,   -20,    67,   -84,   404,    54,    69,
      55,    56,   403,    57,    58,   406,   473,   -20,   -20,    59,
     193,    22,    80,   556,   539,   117,   549,   120,    80,   122,
     -20,   184,    25,   226,   227,   229,   333,   405,   175,    26,
     -79,    22,   322,    27,   357,   407,   -82,   260,   194,   334,
     335,   156,    25,   -15,   408,   -15,   -15,   -15,   -15,    26,
     -15,   196,   -23,    27,   463,   -79,   465,   -15,   -15,   -15,
     323,   -15,   -15,   198,   -15,   -15,   -15,   -15,   -15,   -15,
     591,   429,   166,   -15,   409,   467,   -15,   -15,   -31,   197,
     -31,   -31,   -31,   -31,   464,   -31,   466,   469,   594,   357,
     561,   199,   -31,   -31,   -31,   167,   -31,   -31,   592,   -31,
     -31,   -31,   -31,   -31,   -31,   468,    80,  -142,   -31,    28,
     -82,   -31,   -31,   189,    29,   169,   595,   470,   333,   159,
     160,   349,   349,   122,   -80,   122,   596,   343,   343,    28,
     577,   209,   170,   155,    29,   298,   299,   300,   301,   172,
       6,   -17,   189,   178,   -29,   -29,   -17,     7,     8,     9,
      31,   177,    31,   607,   597,   357,    24,   183,    24,   -17,
     -17,   182,   189,   302,  -128,    31,    30,    31,   354,   354,
     354,    24,   -17,    24,   190,  -135,   -80,   230,   192,   610,
    -135,   608,    31,    31,    31,    31,    30,   236,    24,    24,
      24,    24,   612,   201,   203,   400,   356,  -135,   208,   195,
     344,   344,  -135,  -135,   345,   345,  -136,   611,   -89,   -89,
     359,  -136,   -21,  -137,   513,   218,   370,    60,  -137,   220,
     613,   221,   214,  -138,   216,  -135,    61,  -135,  -138,    26,
     -89,    26,  -137,    27,  -136,    27,  -136,   224,   411,   225,
     -18,  -137,  -137,  -137,    26,  -135,    26,  -137,    27,    18,
      27,  -138,   416,  -138,   237,   238,   239,   240,  -137,  -137,
     456,    26,    26,    26,    26,    27,    27,    27,    27,   231,
    -137,  -135,  -135,   417,   333,   553,   232,  -138,   113,   233,
     346,   346,  -138,   272,  -136,   347,   347,   334,   335,  -136,
    -134,   472,  -125,  -125,   -79,   -79,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,   401,  -138,  -138,   235,   505,    28,
     545,    28,  -136,   272,    29,   272,    29,  -134,   156,  -134,
    -134,  -134,  -134,   156,    28,   413,    28,   474,   501,    29,
     273,    29,  -138,  -138,   475,  -136,   -84,   348,   348,   350,
     351,    28,    28,    28,    28,   477,    29,    29,    29,    29,
     457,  -120,  -120,  -120,  -120,   508,  -120,   511,   498,   122,
     515,  -136,  -136,  -120,  -120,  -120,    30,   417,    30,   520,
     420,   -93,   -93,   -93,   602,   324,   604,   557,   156,  -120,
     555,    30,   558,    30,   541,  -127,   181,   560,   -82,   -82,
     618,   562,   620,   -93,   -93,   563,   427,   565,    30,    30,
      30,    30,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
     -97,   -97,   -97,   -97,   358,   -88,   548,   566,   551,   568,
     122,   -89,   -89,    82,   572,  -129,   428,  -129,  -129,   571,
     637,   638,   640,   -97,   -97,   573,   -88,   643,   644,   646,
     -89,   128,   574,     2,     3,     4,     5,   576,     6,   578,
     360,   -93,   -93,   -93,   156,     7,     8,     9,   579,   282,
     283,   581,   284,   285,   286,   129,   287,   288,   -92,   -92,
     359,    17,   587,   -93,   289,   -34,   -15,   -15,   582,   -15,
     -15,   -15,   -15,   584,   -15,   588,   -97,   -97,   -97,   -97,
     -92,   -15,   -15,   -15,   156,   -15,   -15,   589,   -15,   -15,
     -15,   590,   -15,   -15,   593,   161,   605,   -15,   606,   -97,
     -15,   -92,   -92,    82,   358,   -86,  -134,   -27,   -27,   122,
     417,   122,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
     -92,   -24,   211,   349,   349,   122,   -86,   122,   647,   343,
     343,   -80,   -80,  -134,    81,   -85,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -100,  -100,  -100,
    -100,   -26,   -26,   -85,   349,   609,   349,   -90,   -90,    82,
     343,   648,   343,  -134,  -134,   354,   354,   354,   625,   349,
    -100,   349,   354,   354,   354,   343,   -90,   343,   650,   599,
     601,   -30,   -30,   424,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,   349,   349,   349,   349,   615,   617,   343,   343,   343,
     343,   627,   344,   344,    81,   -88,   345,   345,  -108,  -108,
     621,   632,   623,    81,   -86,   353,   634,   242,   243,   244,
     245,   651,     6,   -88,  -124,  -124,   628,   652,   630,     7,
       8,     9,   -86,   344,   635,   344,   636,   345,   654,   345,
      78,   641,   213,   642,   179,   246,   -83,     0,   344,   222,
     344,     0,   345,     0,   345,  -100,  -100,  -100,  -100,   655,
     656,   657,   658,   659,   660,   661,   662,   -89,   -89,   419,
     344,   344,   344,   344,   345,   345,   345,   345,  -100,  -100,
     -28,   -28,   346,   346,   163,   164,   165,   347,   347,   -89,
     -89,   543,     0,   420,   -96,   -96,   -96,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,   361,  -101,  -101,  -101,  -101,
     362,   363,     0,   346,     0,   346,   -96,   -96,   347,     0,
     347,   544,  -129,  -129,   360,   -96,   -96,   -96,   346,  -101,
     346,   -25,   -25,   347,     0,   347,    46,    47,    48,   348,
     348,    51,    52,    53,     0,  -134,  -134,   -96,    43,     0,
     346,   346,   346,   346,     0,   347,   347,   347,   347,   228,
       0,   242,   243,   244,   245,   258,     6,     0,    43,     0,
     348,     0,   348,     7,     8,     9,     0,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,   348,     0,   348,     0,   246,
     -83,    92,    96,     0,   270,   270,   270,   270,   270,   270,
     270,   270,  -140,  -140,  -134,  -134,   270,   348,   348,   348,
     348,   114,     0,   258,     0,   258,    84,  -101,  -101,  -101,
    -101,    85,    86,   297,  -107,  -107,  -107,  -107,   270,   270,
     270,   270,   270,   270,   270,   270,   270,  -101,   -37,   314,
     -37,   -37,   -37,   -37,     0,   -37,     0,  -107,  -107,  -134,
    -134,  -134,   -37,   -37,   -37,     0,   -37,   -37,     0,   -37,
     -37,   -37,   -37,   -37,   -37,   -90,   -90,   359,   -37,   517,
     518,   -37,   -37,     0,   128,     0,     2,     3,     4,     5,
     297,     6,     0,     0,   180,     0,     0,   -90,     7,     8,
       9,     0,   282,   283,     0,   284,   285,   286,   129,   287,
     288,     0,     0,     0,    17,     0,  -134,   289,   -33,     0,
     188,     0,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
     364,  -108,  -108,  -108,  -108,  -108,  -108,  -108,   -36,   314,
     -36,   -36,   -36,   -36,  -134,   -36,  -134,   212,     0,   188,
       0,     0,   -36,   -36,   -36,  -108,   -36,   -36,     0,   -36,
     -36,   -36,   -36,   -36,   -36,     0,     0,     0,   -36,   188,
       0,   -36,   -36,    46,    47,    48,   258,   258,   258,    52,
      53,     0,     0,     0,   -38,     0,   -38,   -38,   -38,   -38,
       0,   -38,     0,  -107,  -107,  -107,  -107,     0,   -38,   -38,
     -38,     0,   -38,   -38,   258,   -38,   -38,   -38,   -38,   -38,
     -38,     0,     0,   258,   -38,     0,  -107,   -38,   -38,     0,
    -106,  -106,  -106,  -106,   258,   270,     0,  -106,  -106,  -106,
    -106,   383,   383,   383,   383,   383,   383,   383,   383,   383,
       0,     0,   336,  -106,     2,     3,     4,   241,     0,     6,
    -106,  -106,     0,     0,     0,   414,     7,     8,     9,     0,
     258,     0,     0,   337,   338,   339,   200,   340,   341,   314,
       0,     0,    17,     0,     0,   342,     0,   360,   -94,   -94,
     -94,     0,   439,   439,   439,   439,   439,   439,   439,   439,
     439,   -92,   -92,   419,   115,     0,   242,   243,   244,   245,
     -94,     6,     0,     0,     0,     0,     0,     0,     7,     8,
       9,   116,     0,   -92,   -92,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   246,   -39,   314,   -39,   -39,   -39,
     -39,   314,   -39,     0,     0,     0,   258,     0,   383,   -39,
     -39,   -39,     0,   -39,   -39,     0,   -39,   -39,   -39,   -39,
     -39,   -39,     0,     0,     0,   -39,     0,     0,   -39,   -39,
       0,   506,     0,   258,     0,   258,   420,   -94,   -94,   -94,
     297,     0,     0,   254,     0,   439,   439,   439,   439,   439,
     439,   439,   439,   439,     0,     0,   314,     0,     0,   -94,
     -94,     0,   258,     0,   439,     0,    89,   -98,   -98,   -98,
     -98,     0,    97,   100,   100,   100,   100,   100,   100,   100,
     -98,   -98,   -98,   -98,   100,    83,   -93,   -93,   -93,     0,
     -98,   254,   546,   254,   258,     0,   258,  -103,  -103,  -103,
    -103,   297,     0,   -98,   -98,   -93,   100,   100,   100,   100,
     100,   100,   100,   152,   100,     0,     0,   310,     0,   -69,
    -103,   -69,   -69,   -69,   -69,     0,   -69,     0,  -102,  -102,
    -102,  -102,   314,   -69,   -69,   -69,     0,   -69,   -69,     0,
     -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,   -69,
       0,  -102,   -69,   -69,     0,   -35,     0,   -35,   -35,   -35,
     -35,     0,   -35,     0,     0,     0,     0,     0,     0,   -35,
     -35,   -35,   314,   -35,   -35,     0,   -35,   -35,   -35,   -35,
     -35,   -35,   -90,   -90,   419,   -35,     0,     0,   -35,   -35,
       0,     0,     0,   -65,   -65,     0,   -65,   -65,   -65,   -65,
       0,   -65,     0,     0,   -90,   -90,     0,   310,   -65,   -65,
     -65,     0,   -65,   -65,     0,   -65,   -65,   -65,   215,   -65,
     -65,     0,     0,     0,   -65,     0,   336,   -65,     2,     3,
       4,   241,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,   254,   254,   254,   337,   338,   339,
     202,   340,   341,   258,   258,   258,    17,     0,     0,   342,
     258,   258,   258,   -62,   -62,     0,   -62,   -62,   -62,   -62,
       0,   -62,   254,     0,     0,     0,     0,     0,   -62,   -62,
     -62,   366,   -62,   -62,     0,   -62,   -62,   -62,   217,   -62,
     -62,     0,   254,   371,   -62,   418,   -85,   -62,     0,   379,
     387,   387,   387,   387,   387,   387,   387,   387,   -70,     0,
     -70,   -70,   -70,   -70,     0,   -70,     0,   -85,   -85,     0,
       0,     0,   -70,   -70,   -70,     0,   -70,   -70,   254,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,   426,   -70,     0,
       0,   -70,   -70,   -97,   -97,   -97,   -97,     0,   418,   -88,
     435,   443,   443,   443,   443,   443,   443,   443,   443,   418,
     -86,     0,   507,   -97,   242,   243,   244,   245,     0,     6,
     -88,   -88,     0,     0,     0,     0,     7,     8,     9,   116,
       0,   -86,   -86,   387,   387,   387,   387,   387,   387,   387,
     493,   387,   246,   -41,   310,   -41,   -41,   -41,   -41,   310,
     -41,     0,     0,     0,   254,     0,   502,   -41,   -41,   -41,
       0,   -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,
       0,     0,     0,   -41,     0,     0,   -41,   -41,     0,    90,
       0,   254,     0,   254,   255,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,   443,   443,   443,   443,   443,   443,   443,
     536,   443,     0,     0,   310,     0,     0,  -129,  -129,    91,
     254,     0,   542,   267,   267,   267,   267,   267,   267,   267,
     267,  -100,  -100,  -100,  -100,   267,    83,   -96,   -96,   -96,
       0,     0,   255,     0,   255,     0,  -107,  -107,  -107,  -107,
       0,  -100,   254,     0,   254,     0,   -96,   267,   267,   267,
     267,   267,   267,   267,   267,   267,  -107,     0,   311,     0,
     -45,     0,   -45,   -45,   -45,   -45,     0,   -45,     0,  -106,
    -106,  -106,  -106,     0,   -45,   -45,   -45,     0,   -45,   -45,
     310,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,  -106,
     -45,    46,    47,   -45,   -45,     0,     0,    52,    53,     0,
     -40,     0,   -40,   -40,   -40,   -40,     0,   -40,     0,    83,
     -94,   -94,   -94,     0,   -40,   -40,   -40,     0,   -40,   -40,
     310,   -40,   -40,   -40,   -40,   -40,   -40,     0,     0,   -94,
     -40,     0,     0,   -40,   -40,   -42,     0,   -42,   -42,   -42,
     -42,     0,   -42,     0,   -98,   -98,   -98,   -98,   311,   -42,
     -42,   -42,     0,   -42,   -42,     0,   -42,   -42,   -42,   -42,
     -42,   -42,     0,     0,   -98,   -42,     0,     0,   -42,   -42,
       0,     0,     0,   -41,   -41,     0,   -41,   -41,   -41,   -41,
       0,   -41,     0,     0,     0,   255,   255,   255,   -41,   -41,
     -41,     0,   -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,
     -41,   254,   254,   254,   -41,   273,   274,   -41,   254,   254,
     254,   279,   280,   255,    46,    47,    48,    49,    50,    51,
      52,    53,   255,     0,     0,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,   255,   267,     0,   173,    58,     0,   174,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   -43,
    -140,   -43,   -43,   -43,   -43,     0,   -43,     0,     0,     0,
       0,     0,     0,   -43,   -43,   -43,     0,   -43,   -43,   255,
     -43,   -43,   -43,   -43,   -43,   -43,     0,     0,   311,   -43,
       0,     0,   -43,   -43,  -103,  -103,  -103,  -103,     0,     0,
       0,   436,   436,   436,   436,   436,   436,   436,   436,   436,
       0,     0,     0,   547,  -103,   242,   243,   244,   245,     0,
       6,     0,     0,     0,     0,   324,   325,     7,     8,     9,
     116,   330,   331,     0,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   246,   -44,   311,   -44,   -44,   -44,   -44,
     311,   -44,     0,     0,     0,   255,     0,   380,   -44,   -44,
     -44,     0,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,     0,   -44,     0,     0,   -44,   -44,     0,
    -134,     0,   255,     0,   255,   256,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,   436,   436,   436,   436,   436,   436,
     436,   436,   436,     0,     0,   311,     0,     0,  -134,  -134,
    -134,   255,     0,   436,   268,   268,   268,   268,   268,   268,
     268,   268,  -102,  -102,  -102,  -102,   268,     0,     0,     0,
     273,   274,   275,   256,     0,   256,   279,   280,     0,     0,
       0,     0,  -102,   255,     0,   255,     0,     0,   268,   268,
     268,   268,   268,   268,   268,   268,   268,     0,     0,   312,
       0,   -60,     0,   -60,   -60,   -60,   -60,     0,   -60,     0,
       0,     0,     0,     0,     0,   -60,   -60,   -60,     0,   -60,
     -60,   311,   -60,   -60,   -60,   -60,   -60,   -60,     0,     0,
       0,   -60,     0,     0,   -60,   -60,     0,     0,     0,     0,
       0,   -59,     0,   -59,   -59,   -59,   -59,     0,   -59,     0,
       0,     0,     0,     0,     0,   -59,   -59,   -59,     0,   -59,
     -59,   311,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,
       0,   -59,     0,     0,   -59,   -59,   -61,     0,   -61,   -61,
     -61,   -61,     0,   -61,     0,     0,     0,     0,     0,   312,
     -61,   -61,   -61,     0,   -61,   -61,     0,   -61,   -61,   -61,
     -61,   -61,   -61,     0,     0,     0,   -61,     0,     0,   -61,
     -61,     0,     0,     0,   -45,   -45,     0,   -45,   -45,   -45,
     -45,     0,   -45,     0,     0,     0,   256,   256,   256,   -45,
     -45,   -45,     0,   -45,   -45,     0,   -45,   -45,   -45,   -45,
     -45,   -45,   255,   255,   255,   -45,     0,     0,   -45,   255,
     255,   255,     0,     0,   256,    46,    47,    48,    49,    50,
      51,    52,    53,   256,     0,     0,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,   256,   268,     0,   569,    58,     0,
     570,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     -57,  -141,   -57,   -57,   -57,   -57,     0,   -57,     0,     0,
       0,     0,     0,     0,   -57,   -57,   -57,     0,   -57,   -57,
     256,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,   312,
     -57,     0,     0,   -57,   -57,     0,     0,     0,     0,     0,
       0,     0,   437,   437,   437,   437,   437,   437,   437,   437,
     437,     0,     0,     0,    70,     0,     2,     3,     4,   241,
       0,     6,     0,     0,     0,     0,     0,     0,     7,     8,
       9,  -103,  -103,  -103,  -103,   381,   381,   381,   381,   381,
     381,   381,   381,   381,    17,   -58,   312,   -58,   -58,   -58,
     -58,   312,   -58,     0,  -103,  -103,   256,     0,   381,   -58,
     -58,   -58,     0,   -58,   -58,     0,   -58,   -58,   -58,   -58,
     -58,   -58,     0,     0,     0,   -58,     0,     0,   -58,   -58,
       0,   372,     0,   256,     0,   256,   257,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,   437,   437,   437,   437,   437,
     437,   437,   437,   437,     0,     0,   312,     0,     0,  -129,
       0,   373,   256,     0,   437,   269,   269,   269,   269,   269,
     269,   269,   269,    46,    47,    48,    49,   269,    51,    52,
      53,   324,   325,   326,   257,     0,   257,   330,   331,     0,
       0,     0,     0,     0,   256,     0,   256,     0,     0,   269,
     269,   269,   269,   269,   269,   269,   269,   269,     0,     0,
     313,     0,   -11,     0,   -11,   -11,   -11,   -11,     0,   -11,
       0,     0,     0,     0,     0,     0,   -11,   -11,   -11,     0,
     -11,   -11,   312,   -11,   -11,   -11,   -11,   -11,   -11,     0,
       0,     0,   -11,     0,     0,   -11,   -11,     0,     0,     0,
       0,   -40,   -40,     0,   -40,   -40,   -40,   -40,     0,   -40,
       0,     0,     0,     0,     0,     0,   -40,   -40,   -40,     0,
     -40,   -40,   312,   -40,   -40,   -40,   -40,   -40,   -40,     0,
       0,     0,   -40,     0,     0,   -40,   -42,   -42,     0,   -42,
     -42,   -42,   -42,     0,   -42,     0,     0,     0,     0,     0,
     313,   -42,   -42,   -42,     0,   -42,   -42,     0,   -42,   -42,
     -42,   -42,   -42,   -42,     0,     0,     0,   -42,     0,     0,
     -42,     0,     0,     0,     0,   -43,   -43,     0,   -43,   -43,
     -43,   -43,     0,   -43,     0,     0,     0,   257,   257,   257,
     -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,   -43,
     -43,   -43,   -43,   256,   256,   256,   -43,     0,     0,   -43,
     256,   256,   256,     0,     0,   257,    46,    47,    48,    49,
      50,    51,    52,    53,   257,     0,     0,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,   257,   269,     0,   585,    58,
       0,   586,   382,   382,   382,   382,   382,   382,   382,   382,
     382,   -10,  -139,   -10,   -10,   -10,   -10,     0,   -10,     0,
       0,     0,     0,     0,     0,   -10,   -10,   -10,     0,   -10,
     -10,   257,   -10,   -10,   -10,   -10,   -10,   -10,     0,     0,
     313,   -10,     0,     0,   -10,   -10,   421,  -101,  -101,  -101,
    -101,   422,   423,   438,   438,   438,   438,   438,   438,   438,
     438,   438,    46,    47,    48,    49,    50,    51,    52,    53,
    -101,  -101,    46,    47,    48,    49,    50,    51,    52,    53,
       0,  -102,  -102,  -102,  -102,    58,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   -44,   -44,   313,   -44,   -44,
     -44,   -44,   313,   -44,  -102,  -102,     0,   257,     0,   382,
     -44,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,   -44,
     -44,   -44,   -44,     0,     0,     0,   -44,     0,   639,   -44,
     242,   243,   244,   245,   257,     6,   257,   259,     0,     0,
       0,     0,     7,     8,     9,     0,   438,   438,   438,   438,
     438,   438,   438,   438,   438,     0,     0,   313,   246,   -83,
       0,     0,     0,   257,     0,   438,   271,   271,   271,   271,
     271,   271,   271,   271,   273,   274,   275,   276,   271,   278,
     279,   280,     0,     0,     0,   259,     0,   259,     0,     0,
       0,     0,     0,     0,     0,   257,     0,   257,     0,     0,
     271,   271,   271,   271,   271,   271,   271,   271,   271,     0,
       0,   315,     0,   -55,     0,   -55,   -55,   -55,   -55,     0,
     -55,     0,     0,     0,     0,     0,     0,   -55,   -55,   -55,
       0,   -55,   -55,   313,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,     0,   -55,     0,     0,   -55,   -55,     0,     0,
       0,     0,     0,   -54,     0,   -54,   -54,   -54,   -54,     0,
     -54,     0,     0,     0,     0,     0,     0,   -54,   -54,   -54,
       0,   -54,   -54,   313,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,   -54,     0,     0,   -54,   -54,   -68,     0,
     -68,   -68,   -68,   -68,     0,   -68,     0,     0,     0,     0,
       0,   315,   -68,   -68,   -68,     0,   -68,   -68,     0,   -68,
     -68,   -68,   -68,   -68,   -68,     0,     0,     0,   -68,     0,
       0,   -68,   -68,     0,     0,     0,   -60,   -60,     0,   -60,
     -60,   -60,   -60,     0,   -60,     0,     0,     0,   259,   259,
     259,   -60,   -60,   -60,     0,   -60,   -60,     0,   -60,   -60,
     -60,   -60,   -60,   -60,   257,   257,   257,   -60,     0,     0,
     -60,   257,   257,   257,     0,     0,   259,    87,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,   259,   645,     0,   242,   243,
     244,   245,     0,     6,     0,     0,   259,   271,   251,  -108,
       7,     8,     9,   384,   384,   384,   384,   384,   384,   384,
     384,   384,     0,  -134,     0,     0,   246,   -83,     0,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,     0,     0,   102,
       0,     0,   259,   109,   110,     0,     0,     0,     0,     0,
       0,   315,  -134,  -134,  -134,     0,   251,     0,   251,     0,
       0,     0,     0,     0,   440,   440,   440,   440,   440,   440,
     440,   440,   440,     0,   144,     0,   148,   150,  -118,  -118,
    -118,  -118,   307,  -118,     0,     0,     0,     0,     0,     0,
    -118,  -118,  -118,     0,     0,     0,     0,   384,   384,   384,
     384,   384,   384,   384,   384,   384,  -118,   -78,   315,   -78,
     -78,   -78,   -78,   315,   -78,     0,     0,     0,   259,     0,
     384,   -78,   -78,   -78,     0,   -78,   -78,     0,   -78,   -78,
     -78,   -78,   -78,   -78,     0,     0,     0,   -78,     0,     0,
     -78,   -78,     0,     0,     0,   259,     0,   259,   273,   274,
     275,   276,   277,   278,   279,   280,     0,   440,   440,   440,
     440,   440,   440,   440,   440,   440,     0,     0,   315,     0,
       0,   281,   307,   126,   259,     0,   440,    73,     0,   242,
     243,   244,   245,     0,     6,     0,     0,     0,   253,     0,
       0,     7,     8,     9,     0,     0,     0,     0,   -56,     0,
     -56,   -56,   -56,   -56,     0,   -56,   259,   246,   259,   251,
     251,   251,   -56,   -56,   -56,     0,   -56,   -56,    99,   -56,
     -56,   -56,   -56,   -56,   -56,     0,     0,     0,   -56,     0,
       0,   -56,   -56,     0,     0,     0,   253,   251,   253,     0,
     324,   325,   326,   327,   315,   329,   330,   331,     0,    98,
       0,   262,   263,   264,   265,   146,     6,   251,     0,     0,
       0,     0,   309,     7,     8,     9,   389,   251,   251,   251,
     396,   397,   251,   -16,     0,   -16,   -16,   -16,   -16,   266,
     -16,     0,     0,     0,   315,     0,     0,   -16,   -16,   -16,
       0,   -16,   -16,   251,   -16,   -16,   -16,   -16,   -16,   -16,
       0,     0,   367,   -16,     0,     0,   -16,   -16,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,     0,   445,   307,   307,
     307,   452,   453,   307,     0,     0,     0,     0,     0,     0,
     503,  -129,   368,  -129,     0,     0,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,     0,     0,     0,     0,   251,   251,
     251,   485,   309,   489,   491,     0,   251,     0,     0,   307,
     504,  -129,     0,     0,   307,   259,   259,   259,     0,   251,
       0,     0,   259,   259,   259,     0,     0,     0,   273,   274,
     275,     0,   252,   278,   279,   280,     0,     0,     0,   253,
     253,   253,     0,     0,  -134,     0,   251,     0,   251,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   307,   307,
     307,   528,     0,   532,   534,     0,   307,   253,     0,   307,
       0,     0,  -134,  -134,  -134,   251,  -119,  -119,  -119,  -119,
     252,  -119,   252,     0,     0,     0,     0,   253,  -119,  -119,
    -119,     0,     0,     0,     0,   386,   253,   253,   253,   253,
     253,   253,   253,     0,  -119,     0,   308,   251,     0,   251,
     -59,   -59,     0,   -59,   -59,   -59,   -59,     0,   -59,     0,
       0,     0,     0,   253,     0,   -59,   -59,   -59,     0,   -59,
     -59,     0,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,
       0,   -59,     0,     0,   -59,   307,   442,   309,   309,   309,
     309,   309,   309,   309,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,   273,   274,   275,   276,   277,   278,   279,   280,
       0,     0,     0,     0,     0,     0,  -140,  -140,   253,   253,
     253,   253,   487,   253,   253,   307,   253,   -61,   -61,   309,
     -61,   -61,   -61,   -61,   309,   -61,   308,     0,     0,   253,
       0,     0,   -61,   -61,   -61,     0,   -61,   -61,     0,   -61,
     -61,   -61,   -61,   -61,   -61,     0,     0,     0,   -61,     0,
       0,   -61,     0,     0,     0,     0,   253,     0,   253,     0,
       0,     0,     0,   252,   252,   252,     0,     0,   309,   309,
     309,   309,   530,   309,   309,     0,   309,     0,     0,   309,
       0,     0,     0,     0,     0,   253,     0,  -121,  -121,  -121,
    -121,   252,  -121,   250,     0,     0,   251,   251,   251,  -121,
    -121,  -121,     0,   251,   251,   251,     0,   324,   325,   326,
       0,   252,   329,   330,   331,  -121,     0,   253,     0,   253,
     252,   252,   252,   252,   252,   252,   252,   108,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     2,     3,     4,
     241,   250,     6,   250,     0,     0,     0,   252,     0,     7,
       8,     9,     0,     0,     0,   309,     0,     0,   142,     0,
       0,     0,     0,   -83,     0,    17,     0,   306,     0,     0,
       0,   308,   308,   308,   308,   308,   308,   308,     0,     0,
       0,     0,     0,     0,   204,     0,     2,     3,     4,   241,
       0,     6,     0,     0,     0,   309,     0,   249,     7,     8,
       9,     0,   252,   252,   252,   252,     0,   252,   252,     0,
     252,     0,   -83,   308,    17,     0,     0,     0,   308,     0,
       0,     0,     0,   252,     0,    90,     0,     0,     0,   104,
     260,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,     0,
       0,     0,     0,     0,     0,   249,     0,   249,     0,     0,
     252,     0,   252,  -129,  -129,    91,     0,   306,     0,     0,
       0,   140,   308,   308,   308,   308,     0,   308,   308,     0,
     308,   305,     0,   308,     0,     0,   253,   253,   253,   252,
       0,     0,     0,   253,   253,   253,   206,     0,     2,     3,
       4,   241,     0,     6,   250,   250,   250,     0,     0,     0,
       7,     8,     9,     0,   -57,   -57,     0,   -57,   -57,   -57,
     -57,   252,   -57,   252,   -83,     0,    17,     0,     0,   -57,
     -57,   -57,   250,   -57,   -57,     0,   -57,   -57,   -57,   -57,
     -57,   -57,   248,     0,     0,   -57,     0,     0,   -57,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,   308,
       0,     0,   250,   250,   395,     0,     0,   250,     0,     0,
       0,   305,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,   101,     0,   262,   263,   264,   265,   250,     6,
     248,     0,   248,     0,     0,     0,     7,     8,     9,   308,
       0,     0,     0,     0,     0,   138,     0,     0,   249,   249,
     249,     0,   266,   306,   306,   451,   304,     0,   306,   512,
       0,     2,     3,     4,   241,   552,     6,     2,     3,     4,
     241,     0,     6,     7,     8,     9,   249,     0,     0,     7,
       8,     9,     0,   250,   250,   483,     0,   -83,     0,    17,
       0,   250,     0,   -83,   306,    17,   249,     0,     0,   306,
       0,     0,     0,     0,   250,     0,   391,   249,     0,     0,
     603,   249,     2,     3,     4,   241,     0,     6,     0,     0,
     252,   252,   252,     0,     7,     8,     9,   252,   252,   252,
       0,   250,   249,   250,     0,     0,     0,     0,   -83,     0,
      17,     0,     0,   306,   306,   526,   304,     0,     0,     0,
       0,   306,     0,     0,   306,     0,     0,   447,   305,     0,
     250,     0,   305,     0,     0,   247,   103,     0,   262,   263,
     264,   265,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,   248,   248,   248,     0,   249,   481,     0,
       0,     0,   250,     0,   250,   249,   266,     0,   305,     0,
       0,     0,     0,   305,     0,     0,   112,     0,   249,     0,
       0,   248,     0,   247,     0,   247,     0,     0,     0,     0,
       0,    46,    47,    48,    49,    50,    51,    52,    53,     0,
     306,   248,     0,     0,     0,   249,   154,   249,    54,   303,
      55,    56,   393,    57,    58,     0,   248,   305,   524,    59,
       0,     0,     0,     0,     0,   305,     0,     0,   305,     0,
       0,     0,     0,     0,   249,     0,     0,   248,     0,     0,
     306,     0,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
       0,     0,     0,     0,   -58,   -58,     0,   -58,   -58,   -58,
     -58,     0,   -58,   449,  -141,  -141,   249,   304,   249,   -58,
     -58,   -58,     0,   -58,   -58,     0,   -58,   -58,   -58,   -58,
     -58,   -58,     0,     0,     0,   -58,     0,     0,   -58,     0,
       0,     0,   479,     0,     0,     0,     0,     0,     0,   303,
     248,     0,     0,   304,   305,     0,     0,     0,   304,     0,
       0,     0,     0,   248,     0,     0,     0,     0,     0,     0,
       0,   250,   250,   250,     0,     0,     0,     0,   250,   250,
     250,     0,     0,     0,     0,     0,   247,   247,   247,     0,
     248,     0,   248,   105,   305,   262,   263,   264,   265,     0,
       6,     0,   522,     0,     0,     0,     0,     7,     8,     9,
     304,     0,     0,   304,   247,     0,     0,     0,     0,   248,
       0,   -55,   -55,   266,   -55,   -55,   -55,   -55,     0,   -55,
       0,     0,     0,     0,   247,     0,   -55,   -55,   -55,     0,
     -55,   -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,   399,
       0,   248,   -55,   248,     0,   -55,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,   107,     0,   262,   263,   264,   265,
     247,     6,     0,     0,     0,   249,   249,   249,     7,     8,
       9,  -115,   249,   249,   249,     0,     0,   -54,   -54,   304,
     -54,   -54,   -54,   -54,   266,   -54,     0,     0,     0,     0,
     455,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,     0,   -54,     0,
       0,   -54,     0,     0,     0,     0,     0,     0,     0,   304,
       0,     0,     0,   495,   -68,   -68,   303,   -68,   -68,   -68,
     -68,   303,   -68,     0,     0,     0,   247,     0,     0,   -68,
     -68,   -68,     0,   -68,   -68,     0,   -68,   -68,   -68,   -68,
     -68,   -68,     0,     0,     0,   -68,     0,     0,   -68,     0,
       0,     0,     0,   247,     0,   247,     0,     0,     0,     0,
       0,     0,     0,   321,     0,     2,     3,     4,   241,     0,
       6,     0,     0,   538,     0,     0,   303,     7,     8,     9,
       0,     0,   247,     0,   284,   285,   286,   598,   287,   288,
     248,   248,   248,    17,     0,     0,   289,   248,   248,   248,
       0,     0,   -78,   -78,     0,   -78,   -78,   -78,   -78,     0,
     -78,     0,     0,     0,   247,     0,   247,   -78,   -78,   -78,
       0,   -78,   -78,     0,   -78,   -78,   -78,   -78,   -78,   -78,
       0,     0,     0,   -78,   -56,   -56,   -78,   -56,   -56,   -56,
     -56,     0,   -56,     0,     0,     0,     0,     0,     0,   -56,
     -56,   -56,   303,   -56,   -56,     0,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,   -56,     0,     0,   -56,     0,
       0,     0,   -12,     0,   -12,   -12,   -12,   -12,     0,   -12,
       0,     0,     0,     0,     0,     0,   -12,   -12,   -12,     0,
     -12,   -12,   303,   -12,   -12,   -12,   -12,   -12,   -12,     0,
       0,     0,   -12,     0,     0,   -12,   -12,   -72,     0,   -72,
     -72,   -72,   -72,     0,   -72,     0,     0,     0,     0,     0,
       0,   -72,   -72,   -72,     0,   -72,   -72,     0,   -72,   -72,
     -72,   -72,   -72,   -72,     0,     0,     0,   -72,     0,     0,
     -72,   -72,     0,     0,     0,   -72,   -72,     0,   -72,   -72,
     -72,   -72,     0,   -72,     0,     0,     0,     0,     0,     0,
     -72,   -72,   -72,     0,   -72,   -72,     0,   -72,   -72,   -72,
     -72,   -72,   -72,   247,   247,   247,   -72,     0,     0,   -72,
     247,   247,   247,   -71,     0,   -71,   -71,   -71,   -71,     0,
     -71,     0,     0,     0,     0,     0,     0,   -71,   -71,   -71,
       0,   -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,     0,   -71,     0,     0,   -71,   -71,   -14,     0,
     -14,   -14,   -14,   -14,     0,   -14,     0,     0,     0,     0,
       0,     0,   -14,   -14,   -14,     0,   -14,   -14,     0,   -14,
     -14,   -14,   -14,   -14,   -14,     0,     0,     0,   -14,     0,
       0,   -14,   -14,   -71,   -71,     0,   -71,   -71,   -71,   -71,
       0,   -71,     0,     0,     0,     0,     0,     0,   -71,   -71,
     -71,     0,   -71,   -71,     0,   -71,   -71,   -71,   -71,   -71,
     -71,     0,     0,     0,   -71,     0,   -77,   -71,   -77,   -77,
     -77,   -77,     0,   -77,     0,     0,     0,     0,     0,     0,
     -77,   -77,   -77,     0,   -77,   -77,     0,   -77,   -77,   -77,
     -77,   -77,   -77,     0,     0,     0,   -77,     0,     0,   -77,
     -77,   -32,     0,   -32,   -32,   -32,   -32,     0,   -32,     0,
       0,     0,     0,     0,     0,   -32,   -32,   -32,     0,   -32,
     -32,     0,   -32,   -32,   -32,   -32,   -32,   -32,     0,     0,
       0,   -32,     0,     0,   -32,   -32,   -13,     0,   -13,   -13,
     -13,   -13,     0,   -13,     0,     0,     0,     0,     0,     0,
     -13,   -13,   -13,     0,   -13,   -13,     0,   -13,   -13,   -13,
     -13,   -13,   -13,     0,     0,     0,   -13,     0,     0,   -13,
     -13,   -77,   -77,     0,   -77,   -77,   -77,   -77,     0,   -77,
       0,     0,     0,     0,     0,     0,   -77,   -77,   -77,     0,
     -77,   -77,     0,   -77,   -77,   -77,   -77,   -77,   -77,     0,
       0,     0,   -77,   -32,   -32,   -77,   -32,   -32,   -32,   -32,
       0,   -32,     0,     0,     0,     0,     0,     0,   -32,   -32,
     -32,     0,   -32,   -32,     0,   -32,   -32,   -32,   -32,   -32,
     -32,     0,     0,     0,   -32,     0,   -50,   -32,   -50,   -50,
     -50,   -50,     0,   -50,     0,     0,     0,     0,     0,     0,
     -50,   -50,   -50,     0,   -50,   -50,     0,   -50,   -50,   -50,
     -50,   -50,   -50,     0,     0,     0,   -50,     0,     0,   -50,
     -50,   -51,     0,   -51,   -51,   -51,   -51,     0,   -51,     0,
       0,     0,     0,     0,     0,   -51,   -51,   -51,     0,   -51,
     -51,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,
       0,   -51,     0,     0,   -51,   -51,   -46,     0,   -46,   -46,
     -46,   -46,     0,   -46,     0,     0,     0,     0,     0,     0,
     -46,   -46,   -46,     0,   -46,   -46,     0,   -46,   -46,   -46,
     -46,   -46,   -46,     0,     0,     0,   -46,     0,     0,   -46,
     -46,   -49,     0,   -49,   -49,   -49,   -49,     0,   -49,     0,
       0,     0,     0,     0,     0,   -49,   -49,   -49,     0,   -49,
     -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,
       0,   -49,     0,     0,   -49,   -49,   -52,     0,   -52,   -52,
     -52,   -52,     0,   -52,     0,     0,     0,     0,     0,     0,
     -52,   -52,   -52,     0,   -52,   -52,     0,   -52,   -52,   -52,
     -52,   -52,   -52,     0,     0,     0,   -52,     0,     0,   -52,
     -52,   -47,     0,   -47,   -47,   -47,   -47,     0,   -47,     0,
       0,     0,     0,     0,     0,   -47,   -47,   -47,     0,   -47,
     -47,     0,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,
       0,   -47,     0,     0,   -47,   -47,   -53,     0,   -53,   -53,
     -53,   -53,     0,   -53,     0,     0,     0,     0,     0,     0,
     -53,   -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,
     -53,   -53,   -53,     0,     0,     0,   -53,     0,     0,   -53,
     -53,   -48,     0,   -48,   -48,   -48,   -48,     0,   -48,     0,
       0,     0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,
     -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,
       0,   -48,     0,     0,   -48,   -48,   -65,     0,   -65,   -65,
     -65,   -65,     0,   -65,     0,     0,     0,     0,     0,     0,
     -65,   -65,   -65,     0,   -65,   -65,     0,   -65,   -65,   -65,
     622,   -65,   -65,     0,     0,     0,   -65,     0,     0,   -65,
     -65,   -62,     0,   -62,   -62,   -62,   -62,     0,   -62,     0,
       0,     0,     0,     0,     0,   -62,   -62,   -62,     0,   -62,
     -62,     0,   -62,   -62,   -62,   624,   -62,   -62,     0,     0,
       0,   -62,     0,     0,   -62,   -62,   -50,   -50,     0,   -50,
     -50,   -50,   -50,     0,   -50,     0,     0,     0,     0,     0,
       0,   -50,   -50,   -50,     0,   -50,   -50,     0,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,     0,   -50,   -51,   -51,
     -50,   -51,   -51,   -51,   -51,     0,   -51,     0,     0,     0,
       0,     0,     0,   -51,   -51,   -51,     0,   -51,   -51,     0,
     -51,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,   -51,
     -46,   -46,   -51,   -46,   -46,   -46,   -46,     0,   -46,     0,
       0,     0,     0,     0,     0,   -46,   -46,   -46,     0,   -46,
     -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,     0,     0,
       0,   -46,   -49,   -49,   -46,   -49,   -49,   -49,   -49,     0,
     -49,     0,     0,     0,     0,     0,     0,   -49,   -49,   -49,
       0,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,     0,   -49,   -52,   -52,   -49,   -52,   -52,   -52,
     -52,     0,   -52,     0,     0,     0,     0,     0,     0,   -52,
     -52,   -52,     0,   -52,   -52,     0,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,     0,   -52,   -47,   -47,   -52,   -47,
     -47,   -47,   -47,     0,   -47,     0,     0,     0,     0,     0,
       0,   -47,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,
     -47,   -47,   -47,   -47,     0,     0,     0,   -47,   -53,   -53,
     -47,   -53,   -53,   -53,   -53,     0,   -53,     0,     0,     0,
       0,     0,     0,   -53,   -53,   -53,     0,   -53,   -53,     0,
     -53,   -53,   -53,   -53,   -53,   -53,     0,     0,     0,   -53,
     -48,   -48,   -53,   -48,   -48,   -48,   -48,     0,   -48,     0,
       0,     0,     0,     0,     0,   -48,   -48,   -48,     0,   -48,
     -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,
       0,   -48,   -65,   -65,   -48,   -65,   -65,   -65,   -65,     0,
     -65,     0,     0,     0,     0,     0,     0,   -65,   -65,   -65,
       0,   -65,   -65,     0,   -65,   -65,   -65,   629,   -65,   -65,
       0,     0,     0,   -65,   -62,   -62,   -65,   -62,   -62,   -62,
     -62,     0,   -62,     0,     0,     0,     0,     0,     0,   -62,
     -62,   -62,     0,   -62,   -62,     0,   -62,   -62,   -62,   631,
     -62,   -62,     0,     0,     0,   -62,     0,   -67,   -62,   -67,
     -67,   -67,   -67,     0,   -67,     0,     0,     0,     0,     0,
       0,   -67,   -67,   -67,     0,   -67,   -67,     0,   -67,   -67,
     -67,   -67,   -67,   -67,     0,     0,     0,   -67,     0,     0,
     -67,   -67,   -64,     0,   -64,   -64,   -64,   -64,     0,   -64,
       0,     0,     0,     0,     0,     0,   -64,   -64,   -64,     0,
     -64,   -64,     0,   -64,   -64,   -64,   -64,   -64,   -64,     0,
       0,     0,   -64,     0,     0,   -64,   -64,   -67,   -67,     0,
     -67,   -67,   -67,   -67,     0,   -67,     0,     0,     0,     0,
       0,     0,   -67,   -67,   -67,     0,   -67,   -67,     0,   -67,
     -67,   -67,   -67,   -67,   -67,     0,     0,     0,   -67,   -64,
     -64,   -67,   -64,   -64,   -64,   -64,     0,   -64,     0,     0,
       0,     0,     0,     0,   -64,   -64,   -64,     0,   -64,   -64,
       0,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,
     -64,     0,   -66,   -64,   -66,   -66,   -66,   -66,     0,   -66,
       0,     0,     0,     0,     0,     0,   -66,   -66,   -66,     0,
     -66,   -66,     0,   -66,   -66,   -66,   -66,   -66,   -66,     0,
       0,     0,   -66,     0,     0,   -66,   -66,   -63,     0,   -63,
     -63,   -63,   -63,     0,   -63,     0,     0,     0,     0,     0,
       0,   -63,   -63,   -63,     0,   -63,   -63,     0,   -63,   -63,
     -63,   -63,   -63,   -63,     0,     0,     0,   -63,     0,     0,
     -63,   -63,   -66,   -66,     0,   -66,   -66,   -66,   -66,     0,
     -66,     0,     0,     0,     0,     0,     0,   -66,   -66,   -66,
       0,   -66,   -66,     0,   -66,   -66,   -66,   -66,   -66,   -66,
       0,     0,     0,   -66,   -63,   -63,   -66,   -63,   -63,   -63,
     -63,     0,   -63,     0,     0,     0,     0,     0,     0,   -63,
     -63,   -63,     0,   -63,   -63,     0,   -63,   -63,   -63,   -63,
     -63,   -63,     0,     0,     0,   -63,     0,   -74,   -63,   -74,
     -74,   -74,   -74,     0,   -74,     0,     0,     0,     0,     0,
       0,   -74,   -74,   -74,     0,   -74,   -74,     0,   -74,   -74,
     -74,   -74,   -74,   -74,     0,     0,     0,   -74,     0,     0,
     -74,   -74,   -75,     0,   -75,   -75,   -75,   -75,     0,   -75,
       0,     0,     0,     0,     0,     0,   -75,   -75,   -75,     0,
     -75,   -75,     0,   -75,   -75,   -75,   -75,   -75,   -75,     0,
       0,     0,   -75,     0,     0,   -75,   -75,   -76,     0,   -76,
     -76,   -76,   -76,     0,   -76,     0,     0,     0,     0,     0,
       0,   -76,   -76,   -76,     0,   -76,   -76,     0,   -76,   -76,
     -76,   -76,   -76,   -76,     0,     0,     0,   -76,     0,     0,
     -76,   -76,   -73,     0,   -73,   -73,   -73,   -73,     0,   -73,
       0,     0,     0,     0,     0,     0,   -73,   -73,   -73,     0,
     -73,   -73,     0,   -73,   -73,   -73,   -73,   -73,   -73,     0,
       0,     0,   -73,     0,     0,   -73,   -73,   -74,   -74,     0,
     -74,   -74,   -74,   -74,     0,   -74,     0,     0,     0,     0,
       0,     0,   -74,   -74,   -74,     0,   -74,   -74,     0,   -74,
     -74,   -74,   -74,   -74,   -74,     0,     0,     0,   -74,   -75,
     -75,   -74,   -75,   -75,   -75,   -75,     0,   -75,     0,     0,
       0,     0,     0,     0,   -75,   -75,   -75,     0,   -75,   -75,
       0,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,
     -75,   -76,   -76,   -75,   -76,   -76,   -76,   -76,     0,   -76,
       0,     0,     0,     0,     0,     0,   -76,   -76,   -76,     0,
     -76,   -76,     0,   -76,   -76,   -76,   -76,   -76,   -76,     0,
       0,     0,   -76,   -73,   -73,   -76,   -73,   -73,   -73,   -73,
       0,   -73,     0,     0,     0,     0,     0,     0,   -73,   -73,
     -73,     0,   -73,   -73,     0,   -73,   -73,   -73,   -73,   -73,
     -73,     0,     0,     0,   -73,    -3,     1,   -73,     2,     3,
       4,     5,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,    10,    11,     0,    12,    13,    14,
       0,    15,    16,     0,     0,     0,    17,    -2,    77,    18,
       2,     3,     4,     5,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,    10,    11,     0,    12,
      13,    14,     0,    15,    16,     0,     0,     0,    17,    -6,
      -6,    18,    -6,    -6,    -6,    -6,     0,    -6,     0,     0,
       0,     0,     0,     0,    -6,    -6,    -6,     0,    -6,    -6,
       0,    -6,    -6,    -6,     0,    -6,    -6,     0,     0,     0,
      -6,    -8,    -8,    -6,    -8,    -8,    -8,    -8,     0,    -8,
       0,     0,     0,     0,     0,     0,    -8,    -8,    -8,     0,
      -8,    -8,     0,    -8,    -8,    -8,     0,    -8,    -8,     0,
       0,     0,    -8,    -7,    -7,    -8,    -7,    -7,    -7,    -7,
       0,    -7,     0,     0,     0,     0,     0,     0,    -7,    -7,
      -7,     0,    -7,    -7,     0,    -7,    -7,    -7,     0,    -7,
      -7,     0,     0,     0,    -7,   -41,   -41,    -7,   -41,   -41,
     -41,   -41,     0,   -41,     0,     0,     0,     0,     0,     0,
     -41,   -41,   -41,     0,   -41,   -41,     0,   -41,   -41,   -41,
       0,   -41,   -41,     0,     0,     0,   -41,    -9,    -9,   -41,
      -9,    -9,    -9,    -9,     0,    -9,     0,     0,     0,     0,
       0,     0,    -9,    -9,    -9,     0,    -9,    -9,     0,    -9,
      -9,    -9,     0,    -9,    -9,     0,     0,     0,    -9,   -45,
     -45,    -9,   -45,   -45,   -45,   -45,     0,   -45,     0,     0,
       0,     0,     0,     0,   -45,   -45,   -45,     0,   -45,   -45,
       0,   -45,   -45,   -45,     0,   -45,   -45,     0,     0,     0,
     -45,   -40,   -40,   -45,   -40,   -40,   -40,   -40,     0,   -40,
       0,     0,     0,     0,     0,     0,   -40,   -40,   -40,     0,
     -40,   -40,     0,   -40,   -40,   -40,     0,   -40,   -40,     0,
       0,     0,   -40,   -42,   -42,   -40,   -42,   -42,   -42,   -42,
       0,   -42,     0,     0,     0,     0,     0,     0,   -42,   -42,
     -42,     0,   -42,   -42,     0,   -42,   -42,   -42,     0,   -42,
     -42,     0,     0,     0,   -42,   -43,   -43,   -42,   -43,   -43,
     -43,   -43,     0,   -43,     0,     0,     0,     0,     0,     0,
     -43,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,   -43,
       0,   -43,   -43,     0,     0,     0,   -43,   -44,   -44,   -43,
     -44,   -44,   -44,   -44,     0,   -44,     0,     0,     0,     0,
       0,     0,   -44,   -44,   -44,     0,   -44,   -44,     0,   -44,
     -44,   -44,     0,   -44,   -44,     0,     0,     0,   -44,   -60,
     -60,   -44,   -60,   -60,   -60,   -60,     0,   -60,     0,     0,
       0,     0,     0,     0,   -60,   -60,   -60,     0,   -60,   -60,
       0,   -60,   -60,   -60,     0,   -60,   -60,     0,     0,     0,
     -60,   -59,   -59,   -60,   -59,   -59,   -59,   -59,     0,   -59,
       0,     0,     0,     0,     0,     0,   -59,   -59,   -59,     0,
     -59,   -59,     0,   -59,   -59,   -59,     0,   -59,   -59,     0,
       0,     0,   -59,   -61,   -61,   -59,   -61,   -61,   -61,   -61,
       0,   -61,     0,     0,     0,     0,     0,     0,   -61,   -61,
     -61,     0,   -61,   -61,     0,   -61,   -61,   -61,     0,   -61,
     -61,     0,     0,     0,   -61,   -57,   -57,   -61,   -57,   -57,
     -57,   -57,     0,   -57,     0,     0,     0,     0,     0,     0,
     -57,   -57,   -57,     0,   -57,   -57,     0,   -57,   -57,   -57,
       0,   -57,   -57,     0,     0,     0,   -57,   -58,   -58,   -57,
     -58,   -58,   -58,   -58,     0,   -58,     0,     0,     0,     0,
       0,     0,   -58,   -58,   -58,     0,   -58,   -58,     0,   -58,
     -58,   -58,     0,   -58,   -58,     0,     0,     0,   -58,   -55,
     -55,   -58,   -55,   -55,   -55,   -55,     0,   -55,     0,     0,
       0,     0,     0,     0,   -55,   -55,   -55,     0,   -55,   -55,
       0,   -55,   -55,   -55,     0,   -55,   -55,     0,     0,     0,
     -55,   -54,   -54,   -55,   -54,   -54,   -54,   -54,     0,   -54,
       0,     0,     0,     0,     0,     0,   -54,   -54,   -54,     0,
     -54,   -54,     0,   -54,   -54,   -54,     0,   -54,   -54,     0,
       0,     0,   -54,   -68,   -68,   -54,   -68,   -68,   -68,   -68,
       0,   -68,     0,     0,     0,     0,     0,     0,   -68,   -68,
     -68,     0,   -68,   -68,     0,   -68,   -68,   -68,     0,   -68,
     -68,     0,     0,     0,   -68,   -78,   -78,   -68,   -78,   -78,
     -78,   -78,     0,   -78,     0,     0,     0,     0,     0,     0,
     -78,   -78,   -78,     0,   -78,   -78,     0,   -78,   -78,   -78,
       0,   -78,   -78,     0,     0,     0,   -78,    -5,    -5,   -78,
      -5,    -5,    -5,    -5,     0,    -5,     0,     0,     0,     0,
       0,     0,    -5,    -5,    -5,     0,    -5,    -5,     0,    -5,
      -5,    -5,     0,    -5,    -5,     0,     0,     0,    -5,   -56,
     -56,    -5,   -56,   -56,   -56,   -56,     0,   -56,     0,     0,
       0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,   -56,
       0,   -56,   -56,   -56,     0,   -56,   -56,     0,     0,     0,
     -56,   -11,   -11,   -56,   -11,   -11,   -11,   -11,     0,   -11,
       0,     0,     0,     0,     0,     0,   -11,   -11,   -11,     0,
     -11,   -11,     0,   -11,   -11,   -11,     0,   -11,   -11,     0,
       0,     0,   -11,   -72,   -72,   -11,   -72,   -72,   -72,   -72,
       0,   -72,     0,     0,     0,     0,     0,     0,   -72,   -72,
     -72,     0,   -72,   -72,     0,   -72,   -72,   -72,     0,   -72,
     -72,     0,     0,     0,   -72,   -71,   -71,   -72,   -71,   -71,
     -71,   -71,     0,   -71,     0,     0,     0,     0,     0,     0,
     -71,   -71,   -71,     0,   -71,   -71,     0,   -71,   -71,   -71,
       0,   -71,   -71,     0,     0,     0,   -71,   -14,   -14,   -71,
     -14,   -14,   -14,   -14,     0,   -14,     0,     0,     0,     0,
       0,     0,   -14,   -14,   -14,     0,   -14,   -14,     0,   -14,
     -14,   -14,     0,   -14,   -14,     0,     0,     0,   -14,   -16,
     -16,   -14,   -16,   -16,   -16,   -16,     0,   -16,     0,     0,
       0,     0,     0,     0,   -16,   -16,   -16,     0,   -16,   -16,
       0,   -16,   -16,   -16,     0,   -16,   -16,     0,     0,     0,
     -16,   -10,   -10,   -16,   -10,   -10,   -10,   -10,     0,   -10,
       0,     0,     0,     0,     0,     0,   -10,   -10,   -10,     0,
     -10,   -10,     0,   -10,   -10,   -10,     0,   -10,   -10,     0,
       0,     0,   -10,   -77,   -77,   -10,   -77,   -77,   -77,   -77,
       0,   -77,     0,     0,     0,     0,     0,     0,   -77,   -77,
     -77,     0,   -77,   -77,     0,   -77,   -77,   -77,     0,   -77,
     -77,     0,     0,     0,   -77,   -32,   -32,   -77,   -32,   -32,
     -32,   -32,     0,   -32,     0,     0,     0,     0,     0,     0,
     -32,   -32,   -32,     0,   -32,   -32,     0,   -32,   -32,   -32,
       0,   -32,   -32,     0,     0,     0,   -32,   -13,   -13,   -32,
     -13,   -13,   -13,   -13,     0,   -13,     0,     0,     0,     0,
       0,     0,   -13,   -13,   -13,     0,   -13,   -13,     0,   -13,
     -13,   -13,     0,   -13,   -13,     0,     0,     0,   -13,   -12,
     -12,   -13,   -12,   -12,   -12,   -12,     0,   -12,     0,     0,
       0,     0,     0,     0,   -12,   -12,   -12,     0,   -12,   -12,
       0,   -12,   -12,   -12,     0,   -12,   -12,     0,     0,     0,
     -12,   -50,   -50,   -12,   -50,   -50,   -50,   -50,     0,   -50,
       0,     0,     0,     0,     0,     0,   -50,   -50,   -50,     0,
     -50,   -50,     0,   -50,   -50,   -50,     0,   -50,   -50,     0,
       0,     0,   -50,   -51,   -51,   -50,   -51,   -51,   -51,   -51,
       0,   -51,     0,     0,     0,     0,     0,     0,   -51,   -51,
     -51,     0,   -51,   -51,     0,   -51,   -51,   -51,     0,   -51,
     -51,     0,     0,     0,   -51,   -46,   -46,   -51,   -46,   -46,
     -46,   -46,     0,   -46,     0,     0,     0,     0,     0,     0,
     -46,   -46,   -46,     0,   -46,   -46,     0,   -46,   -46,   -46,
       0,   -46,   -46,     0,     0,     0,   -46,   -49,   -49,   -46,
     -49,   -49,   -49,   -49,     0,   -49,     0,     0,     0,     0,
       0,     0,   -49,   -49,   -49,     0,   -49,   -49,     0,   -49,
     -49,   -49,     0,   -49,   -49,     0,     0,     0,   -49,   -52,
     -52,   -49,   -52,   -52,   -52,   -52,     0,   -52,     0,     0,
       0,     0,     0,     0,   -52,   -52,   -52,     0,   -52,   -52,
       0,   -52,   -52,   -52,     0,   -52,   -52,     0,     0,     0,
     -52,   -47,   -47,   -52,   -47,   -47,   -47,   -47,     0,   -47,
       0,     0,     0,     0,     0,     0,   -47,   -47,   -47,     0,
     -47,   -47,     0,   -47,   -47,   -47,     0,   -47,   -47,     0,
       0,     0,   -47,   -53,   -53,   -47,   -53,   -53,   -53,   -53,
       0,   -53,     0,     0,     0,     0,     0,     0,   -53,   -53,
     -53,     0,   -53,   -53,     0,   -53,   -53,   -53,     0,   -53,
     -53,     0,     0,     0,   -53,   -48,   -48,   -53,   -48,   -48,
     -48,   -48,     0,   -48,     0,     0,     0,     0,     0,     0,
     -48,   -48,   -48,     0,   -48,   -48,     0,   -48,   -48,   -48,
       0,   -48,   -48,     0,     0,     0,   -48,   -67,   -67,   -48,
     -67,   -67,   -67,   -67,     0,   -67,     0,     0,     0,     0,
       0,     0,   -67,   -67,   -67,     0,   -67,   -67,     0,   -67,
     -67,   -67,     0,   -67,   -67,     0,     0,     0,   -67,   -64,
     -64,   -67,   -64,   -64,   -64,   -64,     0,   -64,     0,     0,
       0,     0,     0,     0,   -64,   -64,   -64,     0,   -64,   -64,
       0,   -64,   -64,   -64,     0,   -64,   -64,     0,     0,     0,
     -64,   -66,   -66,   -64,   -66,   -66,   -66,   -66,     0,   -66,
       0,     0,     0,     0,     0,     0,   -66,   -66,   -66,     0,
     -66,   -66,     0,   -66,   -66,   -66,     0,   -66,   -66,     0,
       0,     0,   -66,   -63,   -63,   -66,   -63,   -63,   -63,   -63,
       0,   -63,     0,     0,     0,     0,     0,     0,   -63,   -63,
     -63,     0,   -63,   -63,     0,   -63,   -63,   -63,     0,   -63,
     -63,     0,     0,     0,   -63,   -22,   -22,   -63,   -22,   -22,
     -22,   -22,     0,   -22,     0,     0,     0,     0,     0,     0,
     -22,   -22,   -22,     0,   -22,   -22,     0,   -22,   -22,   -22,
       0,   -22,   -22,     0,     0,     0,   -22,   -19,   -19,   -22,
     -19,   -19,   -19,   -19,     0,   -19,     0,     0,     0,     0,
       0,     0,   -19,   -19,   -19,     0,   -19,   -19,     0,   -19,
     -19,   -19,     0,   -19,   -19,     0,     0,     0,   -19,   -74,
     -74,   -19,   -74,   -74,   -74,   -74,     0,   -74,     0,     0,
       0,     0,     0,     0,   -74,   -74,   -74,     0,   -74,   -74,
       0,   -74,   -74,   -74,     0,   -74,   -74,     0,     0,     0,
     -74,   -75,   -75,   -74,   -75,   -75,   -75,   -75,     0,   -75,
       0,     0,     0,     0,     0,     0,   -75,   -75,   -75,     0,
     -75,   -75,     0,   -75,   -75,   -75,     0,   -75,   -75,     0,
       0,     0,   -75,   -76,   -76,   -75,   -76,   -76,   -76,   -76,
       0,   -76,     0,     0,     0,     0,     0,     0,   -76,   -76,
     -76,     0,   -76,   -76,     0,   -76,   -76,   -76,     0,   -76,
     -76,     0,     0,     0,   -76,   -73,   -73,   -76,   -73,   -73,
     -73,   -73,     0,   -73,     0,     0,     0,     0,     0,     0,
     -73,   -73,   -73,     0,   -73,   -73,     0,   -73,   -73,   -73,
       0,   -73,   -73,     0,     0,     0,   -73,     0,   321,   -73,
       2,     3,     4,   241,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,     0,     0,     0,   284,
     285,   286,   600,   287,   288,     0,     0,     0,    17,     0,
     336,   289,     2,     3,     4,   241,     0,     6,     0,     0,
       0,     0,     0,     0,     7,     8,     9,     0,     0,     0,
       0,   337,   338,   339,   614,   340,   341,     0,     0,     0,
      17,     0,   336,   342,     2,     3,     4,   241,     0,     6,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,     0,     0,   337,   338,   339,   616,   340,   341,     0,
       0,     0,    17,     0,   321,   342,     2,     3,     4,   241,
       0,     6,     0,     0,     0,     0,     0,     0,     7,     8,
       9,     0,     0,     0,     0,   284,   285,   286,     0,   287,
     288,     0,     0,     0,    17,     0,    77,   289,     2,     3,
       4,   241,     0,     6,     0,     0,     0,     0,     0,     0,
       7,     8,     9,     0,     0,     0,     0,    12,    13,    14,
       0,    15,    16,     0,     0,     0,    17,     0,   336,    18,
       2,     3,     4,   241,     0,     6,     0,     0,     0,     0,
       0,     0,     7,     8,     9,     0,     0,     0,     0,   337,
     338,   339,     0,   340,   341,     0,     0,     0,    17,     0,
     619,   342,     2,     3,     4,   241,   111,     6,   262,   263,
     264,   265,     0,     6,     7,     8,     9,     0,     0,     0,
       7,     8,     9,     0,     0,     0,     0,     0,   -83,     0,
      17,     0,     0,     0,     0,   119,   266,   242,   243,   244,
     245,   137,     6,   262,   263,   264,   265,     0,     6,     7,
       8,     9,     0,     0,     0,     7,     8,     9,     0,   139,
       0,   262,   263,   264,   265,   246,     6,     0,     0,     0,
       0,   266,     0,     7,     8,     9,   141,     0,   262,   263,
     264,   265,     0,     6,     0,     0,     0,     0,     0,   266,
       7,     8,     9,   143,     0,   262,   263,   264,   265,     0,
       6,     0,     0,     0,     0,     0,   266,     7,     8,     9,
     145,     0,   262,   263,   264,   265,     0,     6,     0,     0,
       0,     0,     0,   266,     7,     8,     9,   147,     0,   262,
     263,   264,   265,     0,     6,     0,     0,     0,     0,     0,
     266,     7,     8,     9,   149,     0,   262,   263,   264,   265,
       0,     6,     0,     0,     0,     0,     0,   266,     7,     8,
       9,   151,     0,   262,   263,   264,   265,     0,     6,     0,
       0,     0,     0,     0,   266,     7,     8,     9,   153,     0,
     262,   263,   264,   265,     0,     6,     0,     0,     0,     0,
       0,   266,     7,     8,     9,   352,     0,   298,   299,   300,
     301,     0,     6,     0,     0,     0,     0,     0,   266,     7,
       8,     9,   355,     0,   242,   243,   244,   245,     0,     6,
       0,     0,     0,     0,     0,   302,     7,     8,     9,   369,
       0,   242,   243,   244,   245,     0,     6,     0,     0,     0,
       0,     0,   246,     7,     8,     9,   385,     0,   374,   375,
     376,   377,     0,     6,     0,     0,     0,     0,     0,   246,
       7,     8,     9,   388,     0,   374,   375,   376,   377,     0,
       6,     0,     0,     0,     0,     0,   378,     7,     8,     9,
     390,     0,   374,   375,   376,   377,     0,     6,     0,     0,
       0,     0,     0,   378,     7,     8,     9,   392,     0,   374,
     375,   376,   377,     0,     6,     0,     0,     0,     0,     0,
     378,     7,     8,     9,   394,     0,   374,   375,   376,   377,
       0,     6,     0,     0,     0,     0,     0,   378,     7,     8,
       9,   398,     0,   374,   375,   376,   377,     0,     6,     0,
       0,     0,     0,     0,   378,     7,     8,     9,   410,     0,
       2,     3,     4,   241,     0,     6,     0,     0,     0,     0,
       0,   378,     7,     8,     9,   415,     0,   242,   243,   244,
     245,     0,     6,     0,     0,     0,     0,     0,    17,     7,
       8,     9,   441,     0,   430,   431,   432,   433,     0,     6,
       0,     0,     0,     0,     0,   246,     7,     8,     9,   444,
       0,   430,   431,   432,   433,     0,     6,     0,     0,     0,
       0,     0,   434,     7,     8,     9,   446,     0,   430,   431,
     432,   433,     0,     6,     0,     0,     0,     0,     0,   434,
       7,     8,     9,   448,     0,   430,   431,   432,   433,     0,
       6,     0,     0,     0,     0,     0,   434,     7,     8,     9,
     450,     0,   430,   431,   432,   433,     0,     6,     0,     0,
       0,     0,     0,   434,     7,     8,     9,   454,     0,   430,
     431,   432,   433,     0,     6,     0,     0,     0,     0,     0,
     434,     7,     8,     9,   471,     0,     2,     3,     4,   241,
       0,     6,     0,     0,     0,     0,     0,   434,     7,     8,
       9,   478,     0,   374,   375,   376,   377,     0,     6,     0,
       0,     0,     0,     0,    17,     7,     8,     9,   480,     0,
     374,   375,   376,   377,     0,     6,     0,     0,     0,     0,
       0,   378,     7,     8,     9,   482,     0,   374,   375,   376,
     377,     0,     6,     0,     0,     0,     0,     0,   378,     7,
       8,     9,   484,     0,   374,   375,   376,   377,     0,     6,
       0,     0,     0,     0,     0,   378,     7,     8,     9,   486,
       0,   374,   375,   376,   377,     0,     6,     0,     0,     0,
       0,     0,   378,     7,     8,     9,   488,     0,   374,   375,
     376,   377,     0,     6,     0,     0,     0,     0,     0,   378,
       7,     8,     9,   490,     0,   374,   375,   376,   377,     0,
       6,     0,     0,     0,     0,     0,   378,     7,     8,     9,
     492,     0,   374,   375,   376,   377,     0,     6,     0,     0,
       0,     0,     0,   378,     7,     8,     9,   494,     0,   374,
     375,   376,   377,     0,     6,     0,     0,     0,     0,     0,
     378,     7,     8,     9,   500,     0,   242,   243,   244,   245,
       0,     6,     0,     0,     0,     0,     0,   378,     7,     8,
       9,   510,     0,   242,   243,   244,   245,     0,     6,     0,
       0,     0,     0,     0,   246,     7,     8,     9,   521,     0,
     430,   431,   432,   433,     0,     6,     0,     0,     0,     0,
       0,   246,     7,     8,     9,   523,     0,   430,   431,   432,
     433,     0,     6,     0,     0,     0,     0,     0,   434,     7,
       8,     9,   525,     0,   430,   431,   432,   433,     0,     6,
       0,     0,     0,     0,     0,   434,     7,     8,     9,   527,
       0,   430,   431,   432,   433,     0,     6,     0,     0,     0,
       0,     0,   434,     7,     8,     9,   529,     0,   430,   431,
     432,   433,     0,     6,     0,     0,     0,     0,     0,   434,
       7,     8,     9,   531,     0,   430,   431,   432,   433,     0,
       6,     0,     0,     0,     0,     0,   434,     7,     8,     9,
     533,     0,   430,   431,   432,   433,     0,     6,     0,     0,
       0,     0,     0,   434,     7,     8,     9,   535,     0,   430,
     431,   432,   433,     0,     6,     0,     0,     0,     0,     0,
     434,     7,     8,     9,   537,     0,   430,   431,   432,   433,
       0,     6,     0,     0,     0,     0,     0,   434,     7,     8,
       9,   540,     0,   242,   243,   244,   245,     0,     6,     0,
       0,     0,     0,     0,   434,     7,     8,     9,   550,     0,
     242,   243,   244,   245,     0,     6,     0,     0,     0,     0,
       0,   246,     7,     8,     9,    46,    47,    48,    49,    50,
      51,    52,    53,     0,     0,     0,     0,     0,   246,     0,
       0,     0,   316,   176,   317,   318,     0,   319,    58,     0,
       0,     0,     0,   320,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,     0,     0,     2,     3,     4,
     241,   316,     6,   317,   318,     0,   319,    58,     0,     7,
       8,     9,   320,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,    17,   262,   263,   264,   265,
     458,     6,   459,   460,     0,   461,    58,     0,     7,     8,
       9,   462,     0,   242,   243,   244,   245,     0,     6,     0,
       0,     0,     0,     0,   266,     7,     8,     9,     0,     0,
     374,   375,   376,   377,     0,     6,     0,     0,     0,     0,
       0,   246,     7,     8,     9,     0,     0,   298,   299,   300,
     301,     0,     6,     0,     0,     0,     0,     0,   378,     7,
       8,     9,     0,     0,   430,   431,   432,   433,     0,     6,
       0,     0,     0,     0,     0,   302,     7,     8,     9,   324,
     325,   326,   327,   328,   329,   330,   331,     0,     0,     0,
       0,     0,   434,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,     0,   332,     0,  -126,  -126,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,     0,     0,  -140,     0,  -140,  -140,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,     0,  -141,
       0,  -141,  -141,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,     0,     0,  -139,     0,  -139,  -139,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,     0,   425,     0,  -112,  -112,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,
    -116,     0,  -116,  -116,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,     0,  -122,     0,  -122,  -122,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,  -117,     0,     0,  -130,     0,  -130,
    -130,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,     0,
    -117,     0,  -117,  -117,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,     0,     0,  -133,     0,  -133,  -133,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,     0,  -132,     0,  -132,
    -132,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,     0,
       0,  -131,     0,  -131,  -131,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,     0,  -123,     0,  -123,  -123,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,     0,     0,     0,     0,
    -141,  -141,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
       0,     0,     0,  -139,  -139,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,     0,     0,     0,     0,  -115,  -115,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,     0,
    -116,  -116,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
       0,     0,     0,     0,  -122,  -122,   424,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,     0,     0,     0,  -130,  -130,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,     0,     0,     0,
       0,  -111,  -111,   324,   325,   326,   327,   -87,   329,   330,
     331,     0,     0,     0,  -112,  -112,   324,   325,   326,   -91,
     -91,   329,   330,   331,     0,     0,     0,     0,   -87,   -87,
     324,   325,   326,   -95,   -95,   -95,   330,   331,     0,     0,
       0,   -91,   -91,   324,   325,   -99,   -99,   -99,   -99,   330,
     331,     0,     0,     0,     0,   -95,   -95,   324,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,     0,     0,     0,   -99,   -99,
     424,  -109,  -109,  -109,  -109,  -109,  -109,  -109,     0,     0,
       0,     0,  -110,  -110,   324,   325,  -105,  -105,  -105,  -105,
     330,   331,     0,     0,     0,  -109,  -109,   324,   325,  -104,
    -104,  -104,  -104,   330,   331,     0,     0,     0,     0,  -105,
    -105,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,     0,
       0,     0,  -104,  -104,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,     0,     0,     0,     0,  -114,  -114,   324,   325,
     326,   327,   328,   329,   330,   331,     0,     0,     0,  -113,
    -113,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,     0,
       0,     0,     0,   -81,   -81,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,     0,     0,     0,  -117,  -117,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,     0,     0,     0,     0,
    -133,  -133,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
       0,     0,     0,  -132,  -132,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,     0,     0,     0,     0,  -131,  -131,   273,
     274,   275,   276,   277,   278,   279,   280,     0,     0,     0,
    -123,  -123,   273,   274,   275,   276,   277,   278,   279,   280,
       0,     0,   281,     0,   168,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     0,   281,     0,   171,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,     0,     0,   281,     0,
     234,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,     0,
       0,  -140,     0,  -140,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,     0,     0,  -141,     0,  -141,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,     0,     0,  -139,     0,  -139,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,     0,     0,
     365,     0,  -112,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,     0,     0,  -116,     0,  -116,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,     0,     0,  -122,     0,  -122,   273,
     274,   275,   276,   277,   278,   279,   280,     0,     0,  -130,
       0,  -130,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
       0,     0,   281,     0,   476,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,     0,     0,  -117,     0,  -117,   273,   274,
     275,   276,   277,   278,   279,   280,     0,     0,  -133,     0,
    -133,   273,   274,   275,   276,   277,   278,   279,   280,     0,
       0,   281,     0,   497,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,     0,     0,   281,     0,   519,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,     0,     0,  -132,     0,  -132,
     273,   274,   275,   276,   277,   278,   279,   280,     0,     0,
    -131,     0,  -131,   273,   274,   275,   276,   277,   278,   279,
     280,     0,     0,   281,     0,   559,   273,   274,   275,   276,
     277,   278,   279,   280,     0,     0,   281,     0,   564,   273,
     274,   275,   276,   277,   278,   279,   280,     0,     0,   281,
       0,   567,   273,   274,   275,   276,   277,   278,   279,   280,
       0,     0,   281,     0,   575,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     0,   281,     0,   580,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,     0,     0,   281,     0,
     583,   273,   274,   275,   276,   277,   278,   279,   280,     0,
       0,  -123,     0,  -123,   273,   274,   275,   276,   277,   278,
     279,   280,     0,     0,   281,     0,   649,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,     0,     0,   281,     0,   653,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,
       0,     0,  -116,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,     0,     0,     0,     0,  -122,   364,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,     0,     0,     0,     0,  -130,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,     0,     0,     0,
       0,  -111,   273,   274,   275,   276,   -87,   278,   279,   280,
       0,     0,     0,     0,  -112,   273,   274,   275,   -91,   -91,
     278,   279,   280,     0,     0,     0,     0,   -87,   273,   274,
     275,   -95,   -95,   -95,   279,   280,     0,     0,     0,     0,
     -91,   273,   274,   -99,   -99,   -99,   -99,   279,   280,     0,
       0,     0,     0,   -95,   273,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,     0,     0,     0,     0,   -99,   364,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,     0,     0,     0,     0,  -110,
     273,   274,  -105,  -105,  -105,  -105,   279,   280,     0,     0,
       0,     0,  -109,   273,   274,  -104,  -104,  -104,  -104,   279,
     280,     0,     0,     0,     0,  -105,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,     0,     0,     0,     0,  -104,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,     0,     0,     0,
       0,  -114,   273,   274,   275,   276,   277,   278,   279,   280,
       0,     0,     0,     0,  -113,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,     0,     0,     0,     0,   -81,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,     0,     0,     0,     0,
    -117,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,     0,
       0,     0,     0,  -133,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,     0,     0,     0,     0,  -132,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,     0,     0,     0,     0,  -131,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,     0,     0,
       0,     0,  -123,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,     0,  -139,  -139,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,     0,     0,     0,  -112,    88,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,     0,  -116,  -116,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,     0,     0,     0,  -122,
    -122,    46,    47,    48,    49,    50,    51,    52,    53,     0,
    -130,  -130,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
       0,     0,     0,   124,    58,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,     0,  -117,  -117,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,     0,     0,     0,  -133,  -133,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,     0,  -132,  -132,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,     0,     0,
       0,  -131,  -131,    46,    47,    48,    49,    50,    51,    52,
      53,     0,  -123,  -123,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,     0,   219,    58,    46,    47,    48,
      49,    50,    51,    52,    53,     0,   514,    58,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,     0,   554,
      58,    46,    47,    48,    49,    50,    51,    52,    53,     0,
     626,    58,   324,   325,   326,   327,   328,   329,   330,   331,
       0,     0,     0,   633,    58,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     0,   332,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,     0,     0,     0,     0,   281,    87,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,     0,  -115,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,     0,     0,     0,
       0,  -111,    46,    47,    48,    49,   -87,    51,    52,    53,
       0,  -112,    46,    47,    48,   -91,   -91,    51,    52,    53,
       0,     0,     0,     0,   -87,    46,    47,    48,   -95,   -95,
     -95,    52,    53,     0,   -91,    46,    47,   -99,   -99,   -99,
     -99,    52,    53,     0,     0,     0,     0,   -95,    46,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,     0,   -99,    87,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,     0,     0,     0,     0,
    -110,    46,    47,  -105,  -105,  -105,  -105,    52,    53,     0,
    -109,    46,    47,  -104,  -104,  -104,  -104,    52,    53,     0,
       0,     0,     0,  -105,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,     0,  -104,  -113,  -113,  -113,  -113,  -113,  -113,
    -113,  -113,     0,     0,     0,     0,  -114,    46,    47,    48,
      49,    50,    51,    52,    53,     0,  -113,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,     0,     0,     0,     0,   -81,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,     0,  -140,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,     0,     0,
       0,     0,  -141,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,     0,  -139,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,     0,     0,     0,     0,  -116,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,     0,  -122,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,  -117,     0,     0,     0,     0,  -130,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,     0,  -117,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,     0,     0,     0,
       0,  -133,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
       0,  -132,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
       0,     0,     0,     0,  -131,   324,   325,   326,   327,   328,
     329,   330,   331,     0,  -123
};

static const yytype_int16 yycheck[] =
{
       0,     0,   412,   289,   368,   405,     0,    10,    11,   373,
       1,    29,     1,     1,    29,     1,    16,    17,     6,     1,
      20,    20,     1,     0,     0,    32,    20,     7,   173,    32,
     175,     7,     8,     9,    10,    11,    12,    13,    14,     1,
      31,    29,    31,    31,     6,    31,    29,     1,    24,    31,
      26,    27,    31,    29,    30,     1,   342,    19,    20,    35,
       1,     0,    11,   473,   428,    65,   466,    67,    11,    69,
      32,     1,     0,   218,   219,   220,     6,    31,    29,     0,
      29,    20,     1,     0,    11,    31,    29,     6,    29,    19,
      20,    91,    20,     1,     1,     3,     4,     5,     6,    20,
       8,     1,    32,    20,     1,    32,     1,    15,    16,    17,
      29,    19,    20,     1,    22,    23,    24,    25,    26,    27,
       1,    29,    32,    31,    31,     1,    34,    35,     1,    29,
       3,     4,     5,     6,    31,     8,    31,     1,     1,    11,
     504,    29,    15,    16,    17,    32,    19,    20,    29,    22,
      23,    24,    25,    26,    27,    31,    11,    32,    31,     0,
      32,    34,    35,   162,     0,    32,    29,    31,     6,    29,
      30,   171,   172,   173,    29,   175,     1,   171,   172,    20,
     544,   181,    32,     1,    20,     3,     4,     5,     6,    32,
       8,     1,   191,    35,    32,    33,     6,    15,    16,    17,
     200,   129,   202,     1,    29,    11,   200,     1,   202,    19,
      20,    32,   211,    31,    32,   215,     0,   217,   218,   219,
     220,   215,    32,   217,     1,     1,    32,   221,    29,     1,
       6,    29,   232,   233,   234,   235,    20,   231,   232,   233,
     234,   235,     1,   171,   172,    21,   246,     1,   176,    29,
     171,   172,     6,    29,   171,   172,     1,    29,    10,    11,
      12,     6,    32,     1,   409,    29,   266,    21,     6,    29,
      29,    32,   200,     1,   202,    29,    21,    31,     6,   200,
      32,   202,     6,   200,    29,   202,    31,   215,   288,   217,
      32,    29,     1,    31,   215,     6,   217,     6,   215,    34,
     217,    29,   302,    31,   232,   233,   234,   235,    32,    33,
      21,   232,   233,   234,   235,   232,   233,   234,   235,    32,
      29,    32,    33,    11,     6,   470,    32,     1,     1,    32,
     171,   172,     6,     6,     1,   171,   172,    19,    20,     6,
       1,   341,    32,    33,    32,    33,     7,     8,     9,    10,
      11,    12,    13,    14,    21,    29,     6,    32,     1,   200,
       1,   202,    29,     6,   200,     6,   202,    32,   368,    30,
      31,    32,    33,   373,   215,    29,   217,    29,   378,   215,
       7,   217,    32,    33,     1,     6,    32,   171,   172,    29,
      30,   232,   233,   234,   235,    32,   232,   233,   234,   235,
      21,     3,     4,     5,     6,   405,     8,   407,    32,   409,
      29,    32,    33,    15,    16,    17,   200,    11,   202,    32,
       9,    10,    11,    12,   569,     7,   571,    32,   428,    31,
      29,   215,    32,   217,   434,    32,    33,    32,    32,    33,
     585,    32,   587,    32,    33,    32,     1,    32,   232,   233,
     234,   235,     7,     8,     9,    10,    11,    12,    13,    14,
       9,    10,    11,    12,    10,    11,   466,    32,   468,    32,
     470,    10,    11,    12,    35,    30,    31,    32,    33,    29,
     625,   626,   627,    32,    33,     1,    32,   632,   633,   634,
      29,     1,    32,     3,     4,     5,     6,    32,     8,    32,
       9,    10,    11,    12,   504,    15,    16,    17,    32,    19,
      20,    32,    22,    23,    24,    25,    26,    27,    10,    11,
      12,    31,    29,    32,    34,    35,     0,     1,    32,     3,
       4,     5,     6,    32,     8,    35,     9,    10,    11,    12,
      32,    15,    16,    17,   544,    19,    20,    32,    22,    23,
      24,    29,    26,    27,    29,    29,    32,    31,    29,    32,
      34,    10,    11,    12,    10,    11,     1,    32,    33,   569,
      11,   571,     7,     8,     9,    10,    11,    12,    13,    14,
      29,    32,    33,   583,   584,   585,    32,   587,    32,   583,
     584,    32,    33,     1,    10,    11,    31,    32,    33,     7,
       8,     9,    10,    11,    12,    13,    14,     9,    10,    11,
      12,    32,    33,    29,   614,    29,   616,    10,    11,    12,
     614,    32,   616,    31,    32,   625,   626,   627,    29,   629,
      32,   631,   632,   633,   634,   629,    29,   631,    32,   567,
     568,    32,    33,     7,     8,     9,    10,    11,    12,    13,
      14,   651,   652,   653,   654,   583,   584,   651,   652,   653,
     654,    29,   583,   584,    10,    11,   583,   584,    32,    33,
     598,    29,   600,    10,    11,     1,    29,     3,     4,     5,
       6,    32,     8,    29,    32,    33,   614,    32,   616,    15,
      16,    17,    29,   614,   622,   616,   624,   614,    32,   616,
      20,   629,   191,   631,   132,    31,    32,    -1,   629,   211,
     631,    -1,   629,    -1,   631,     9,    10,    11,    12,   647,
     648,   649,   650,   651,   652,   653,   654,    10,    11,    12,
     651,   652,   653,   654,   651,   652,   653,   654,    32,    33,
      32,    33,   583,   584,    29,    30,    31,   583,   584,    32,
      33,     1,    -1,     9,    10,    11,    12,     7,     8,     9,
      10,    11,    12,    13,    14,     8,     9,    10,    11,    12,
      13,    14,    -1,   614,    -1,   616,    32,    33,   614,    -1,
     616,    31,    32,    33,     9,    10,    11,    12,   629,    32,
     631,    32,    33,   629,    -1,   631,     7,     8,     9,   583,
     584,    12,    13,    14,    -1,    29,    30,    32,     0,    -1,
     651,   652,   653,   654,    -1,   651,   652,   653,   654,     1,
      -1,     3,     4,     5,     6,    17,     8,    -1,    20,    -1,
     614,    -1,   616,    15,    16,    17,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,   629,    -1,   631,    -1,    31,
      32,    43,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    32,    33,    32,    33,    58,   651,   652,   653,
     654,    63,    -1,    65,    -1,    67,     8,     9,    10,    11,
      12,    13,    14,    75,     9,    10,    11,    12,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    29,     1,    91,
       3,     4,     5,     6,    -1,     8,    -1,    32,    33,    29,
      30,    31,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    10,    11,    12,    31,    29,
      30,    34,    35,    -1,     1,    -1,     3,     4,     5,     6,
     132,     8,    -1,    -1,   136,    -1,    -1,    32,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,    35,    -1,
     162,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
       7,     8,     9,    10,    11,    12,    13,    14,     1,   181,
       3,     4,     5,     6,    29,     8,    31,   189,    -1,   191,
      -1,    -1,    15,    16,    17,    32,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,   211,
      -1,    34,    35,     7,     8,     9,   218,   219,   220,    13,
      14,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,     9,    10,    11,    12,    -1,    15,    16,
      17,    -1,    19,    20,   246,    22,    23,    24,    25,    26,
      27,    -1,    -1,   255,    31,    -1,    32,    34,    35,    -1,
       9,    10,    11,    12,   266,   267,    -1,     9,    10,    11,
      12,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      -1,    -1,     1,    32,     3,     4,     5,     6,    -1,     8,
      32,    33,    -1,    -1,    -1,   297,    15,    16,    17,    -1,
     302,    -1,    -1,    22,    23,    24,    25,    26,    27,   311,
      -1,    -1,    31,    -1,    -1,    34,    -1,     9,    10,    11,
      12,    -1,   324,   325,   326,   327,   328,   329,   330,   331,
     332,    10,    11,    12,     1,    -1,     3,     4,     5,     6,
      32,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    -1,    32,    33,   357,   358,   359,   360,   361,
     362,   363,   364,   365,    31,     1,   368,     3,     4,     5,
       6,   373,     8,    -1,    -1,    -1,   378,    -1,   380,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      -1,   403,    -1,   405,    -1,   407,     9,    10,    11,    12,
     412,    -1,    -1,    17,    -1,   417,   418,   419,   420,   421,
     422,   423,   424,   425,    -1,    -1,   428,    -1,    -1,    32,
      33,    -1,   434,    -1,   436,    -1,    40,     9,    10,    11,
      12,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
       9,    10,    11,    12,    58,     9,    10,    11,    12,    -1,
      32,    65,   464,    67,   466,    -1,   468,     9,    10,    11,
      12,   473,    -1,    32,    33,    29,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    -1,    -1,    91,    -1,     1,
      32,     3,     4,     5,     6,    -1,     8,    -1,     9,    10,
      11,    12,   504,    15,    16,    17,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    32,    34,    35,    -1,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,   544,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    10,    11,    12,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    32,    33,    -1,   181,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,   218,   219,   220,    22,    23,    24,
      25,    26,    27,   625,   626,   627,    31,    -1,    -1,    34,
     632,   633,   634,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,   246,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,   255,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,   266,   267,    31,    10,    11,    34,    -1,   273,
     274,   275,   276,   277,   278,   279,   280,   281,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    32,    33,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,   302,    22,
      23,    24,    25,    26,    27,    -1,    -1,   311,    31,    -1,
      -1,    34,    35,     9,    10,    11,    12,    -1,    10,    11,
     324,   325,   326,   327,   328,   329,   330,   331,   332,    10,
      11,    -1,     1,    29,     3,     4,     5,     6,    -1,     8,
      32,    33,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      -1,    32,    33,   357,   358,   359,   360,   361,   362,   363,
     364,   365,    31,     1,   368,     3,     4,     5,     6,   373,
       8,    -1,    -1,    -1,   378,    -1,   380,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,     1,
      -1,   405,    -1,   407,    17,     7,     8,     9,    10,    11,
      12,    13,    14,   417,   418,   419,   420,   421,   422,   423,
     424,   425,    -1,    -1,   428,    -1,    -1,    29,    30,    31,
     434,    -1,   436,    46,    47,    48,    49,    50,    51,    52,
      53,     9,    10,    11,    12,    58,     9,    10,    11,    12,
      -1,    -1,    65,    -1,    67,    -1,     9,    10,    11,    12,
      -1,    29,   466,    -1,   468,    -1,    29,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    29,    -1,    91,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,     9,
      10,    11,    12,    -1,    15,    16,    17,    -1,    19,    20,
     504,    22,    23,    24,    25,    26,    27,    -1,    -1,    29,
      31,     7,     8,    34,    35,    -1,    -1,    13,    14,    -1,
       1,    -1,     3,     4,     5,     6,    -1,     8,    -1,     9,
      10,    11,    12,    -1,    15,    16,    17,    -1,    19,    20,
     544,    22,    23,    24,    25,    26,    27,    -1,    -1,    29,
      31,    -1,    -1,    34,    35,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,     9,    10,    11,    12,   181,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    29,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,   218,   219,   220,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,   625,   626,   627,    31,     7,     8,    34,   632,   633,
     634,    13,    14,   246,     7,     8,     9,    10,    11,    12,
      13,    14,   255,    -1,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,   266,   267,    -1,    29,    30,    -1,    32,
     273,   274,   275,   276,   277,   278,   279,   280,   281,     1,
      32,     3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,   302,
      22,    23,    24,    25,    26,    27,    -1,    -1,   311,    31,
      -1,    -1,    34,    35,     9,    10,    11,    12,    -1,    -1,
      -1,   324,   325,   326,   327,   328,   329,   330,   331,   332,
      -1,    -1,    -1,     1,    29,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,     7,     8,    15,    16,    17,
      18,    13,    14,    -1,   357,   358,   359,   360,   361,   362,
     363,   364,   365,    31,     1,   368,     3,     4,     5,     6,
     373,     8,    -1,    -1,    -1,   378,    -1,   380,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,
       1,    -1,   405,    -1,   407,    17,     7,     8,     9,    10,
      11,    12,    13,    14,   417,   418,   419,   420,   421,   422,
     423,   424,   425,    -1,    -1,   428,    -1,    -1,    29,    30,
      31,   434,    -1,   436,    46,    47,    48,    49,    50,    51,
      52,    53,     9,    10,    11,    12,    58,    -1,    -1,    -1,
       7,     8,     9,    65,    -1,    67,    13,    14,    -1,    -1,
      -1,    -1,    29,   466,    -1,   468,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    91,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,   504,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,   544,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,   181,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,   218,   219,   220,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,   625,   626,   627,    31,    -1,    -1,    34,   632,
     633,   634,    -1,    -1,   246,     7,     8,     9,    10,    11,
      12,    13,    14,   255,    -1,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,   266,   267,    -1,    29,    30,    -1,
      32,   273,   274,   275,   276,   277,   278,   279,   280,   281,
       1,    32,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,    20,
     302,    22,    23,    24,    25,    26,    27,    -1,    -1,   311,
      31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,   325,   326,   327,   328,   329,   330,   331,
     332,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,     9,    10,    11,    12,   357,   358,   359,   360,   361,
     362,   363,   364,   365,    31,     1,   368,     3,     4,     5,
       6,   373,     8,    -1,    32,    33,   378,    -1,   380,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      -1,     1,    -1,   405,    -1,   407,    17,     7,     8,     9,
      10,    11,    12,    13,    14,   417,   418,   419,   420,   421,
     422,   423,   424,   425,    -1,    -1,   428,    -1,    -1,    29,
      -1,    31,   434,    -1,   436,    46,    47,    48,    49,    50,
      51,    52,    53,     7,     8,     9,    10,    58,    12,    13,
      14,     7,     8,     9,    65,    -1,    67,    13,    14,    -1,
      -1,    -1,    -1,    -1,   466,    -1,   468,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    -1,    -1,
      91,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   504,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   544,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
     181,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,   218,   219,   220,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,   625,   626,   627,    31,    -1,    -1,    34,
     632,   633,   634,    -1,    -1,   246,     7,     8,     9,    10,
      11,    12,    13,    14,   255,    -1,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,   266,   267,    -1,    29,    30,
      -1,    32,   273,   274,   275,   276,   277,   278,   279,   280,
     281,     1,    32,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    19,
      20,   302,    22,    23,    24,    25,    26,    27,    -1,    -1,
     311,    31,    -1,    -1,    34,    35,     8,     9,    10,    11,
      12,    13,    14,   324,   325,   326,   327,   328,   329,   330,
     331,   332,     7,     8,     9,    10,    11,    12,    13,    14,
      32,    33,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,     9,    10,    11,    12,    30,   357,   358,   359,   360,
     361,   362,   363,   364,   365,     0,     1,   368,     3,     4,
       5,     6,   373,     8,    32,    33,    -1,   378,    -1,   380,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
       3,     4,     5,     6,   405,     8,   407,    17,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,   417,   418,   419,   420,
     421,   422,   423,   424,   425,    -1,    -1,   428,    31,    32,
      -1,    -1,    -1,   434,    -1,   436,    46,    47,    48,    49,
      50,    51,    52,    53,     7,     8,     9,    10,    58,    12,
      13,    14,    -1,    -1,    -1,    65,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   466,    -1,   468,    -1,    -1,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    91,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,   504,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,   544,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,   181,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,   218,   219,
     220,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,   625,   626,   627,    31,    -1,    -1,
      34,   632,   633,   634,    -1,    -1,   246,     7,     8,     9,
      10,    11,    12,    13,    14,   255,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,   266,   267,    17,    29,
      15,    16,    17,   273,   274,   275,   276,   277,   278,   279,
     280,   281,    -1,     1,    -1,    -1,    31,    32,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    48,
      -1,    -1,   302,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,   311,    30,    31,    32,    -1,    65,    -1,    67,    -1,
      -1,    -1,    -1,    -1,   324,   325,   326,   327,   328,   329,
     330,   331,   332,    -1,    83,    -1,    85,    86,     3,     4,
       5,     6,    91,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,   357,   358,   359,
     360,   361,   362,   363,   364,   365,    31,     1,   368,     3,
       4,     5,     6,   373,     8,    -1,    -1,    -1,   378,    -1,
     380,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,   405,    -1,   407,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,   417,   418,   419,
     420,   421,   422,   423,   424,   425,    -1,    -1,   428,    -1,
      -1,    30,   181,    32,   434,    -1,   436,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    17,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    -1,     8,   466,    31,   468,   218,
     219,   220,    15,    16,    17,    -1,    19,    20,    47,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,    65,   246,    67,    -1,
       7,     8,     9,    10,   504,    12,    13,    14,    -1,     1,
      -1,     3,     4,     5,     6,    84,     8,   266,    -1,    -1,
      -1,    -1,    91,    15,    16,    17,   275,   276,   277,   278,
     279,   280,   281,     1,    -1,     3,     4,     5,     6,    31,
       8,    -1,    -1,    -1,   544,    -1,    -1,    15,    16,    17,
      -1,    19,    20,   302,    22,    23,    24,    25,    26,    27,
      -1,    -1,     1,    31,    -1,    -1,    34,    35,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,   326,   327,   328,
     329,   330,   331,   332,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    30,    31,    32,    -1,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,   357,   358,
     359,   360,   181,   362,   363,    -1,   365,    -1,    -1,   368,
      31,    32,    -1,    -1,   373,   625,   626,   627,    -1,   378,
      -1,    -1,   632,   633,   634,    -1,    -1,    -1,     7,     8,
       9,    -1,    17,    12,    13,    14,    -1,    -1,    -1,   218,
     219,   220,    -1,    -1,     1,    -1,   405,    -1,   407,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   417,   418,
     419,   420,    -1,   422,   423,    -1,   425,   246,    -1,   428,
      -1,    -1,    29,    30,    31,   434,     3,     4,     5,     6,
      65,     8,    67,    -1,    -1,    -1,    -1,   266,    15,    16,
      17,    -1,    -1,    -1,    -1,   274,   275,   276,   277,   278,
     279,   280,   281,    -1,    31,    -1,    91,   466,    -1,   468,
       0,     1,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,   302,    -1,    15,    16,    17,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,   504,   325,   326,   327,   328,
     329,   330,   331,   332,     7,     8,     9,    10,    11,    12,
      13,    14,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,   357,   358,
     359,   360,   361,   362,   363,   544,   365,     0,     1,   368,
       3,     4,     5,     6,   373,     8,   181,    -1,    -1,   378,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,   405,    -1,   407,    -1,
      -1,    -1,    -1,   218,   219,   220,    -1,    -1,   417,   418,
     419,   420,   421,   422,   423,    -1,   425,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,   434,    -1,     3,     4,     5,
       6,   246,     8,    17,    -1,    -1,   625,   626,   627,    15,
      16,    17,    -1,   632,   633,   634,    -1,     7,     8,     9,
      -1,   266,    12,    13,    14,    31,    -1,   466,    -1,   468,
     275,   276,   277,   278,   279,   280,   281,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    65,     8,    67,    -1,    -1,    -1,   302,    -1,    15,
      16,    17,    -1,    -1,    -1,   504,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    29,    -1,    31,    -1,    91,    -1,    -1,
      -1,   326,   327,   328,   329,   330,   331,   332,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,   544,    -1,    17,    15,    16,
      17,    -1,   357,   358,   359,   360,    -1,   362,   363,    -1,
     365,    -1,    29,   368,    31,    -1,    -1,    -1,   373,    -1,
      -1,    -1,    -1,   378,    -1,     1,    -1,    -1,    -1,    49,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    67,    -1,    -1,
     405,    -1,   407,    29,    30,    31,    -1,   181,    -1,    -1,
      -1,    81,   417,   418,   419,   420,    -1,   422,   423,    -1,
     425,    91,    -1,   428,    -1,    -1,   625,   626,   627,   434,
      -1,    -1,    -1,   632,   633,   634,     1,    -1,     3,     4,
       5,     6,    -1,     8,   218,   219,   220,    -1,    -1,    -1,
      15,    16,    17,    -1,     0,     1,    -1,     3,     4,     5,
       6,   466,     8,   468,    29,    -1,    31,    -1,    -1,    15,
      16,    17,   246,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    17,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,   504,
      -1,    -1,   276,   277,   278,    -1,    -1,   281,    -1,    -1,
      -1,   181,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,   302,     8,
      65,    -1,    67,    -1,    -1,    -1,    15,    16,    17,   544,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,   218,   219,
     220,    -1,    31,   327,   328,   329,    91,    -1,   332,     1,
      -1,     3,     4,     5,     6,     1,     8,     3,     4,     5,
       6,    -1,     8,    15,    16,    17,   246,    -1,    -1,    15,
      16,    17,    -1,   357,   358,   359,    -1,    29,    -1,    31,
      -1,   365,    -1,    29,   368,    31,   266,    -1,    -1,   373,
      -1,    -1,    -1,    -1,   378,    -1,   276,   277,    -1,    -1,
       1,   281,     3,     4,     5,     6,    -1,     8,    -1,    -1,
     625,   626,   627,    -1,    15,    16,    17,   632,   633,   634,
      -1,   405,   302,   407,    -1,    -1,    -1,    -1,    29,    -1,
      31,    -1,    -1,   417,   418,   419,   181,    -1,    -1,    -1,
      -1,   425,    -1,    -1,   428,    -1,    -1,   327,   328,    -1,
     434,    -1,   332,    -1,    -1,    17,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,   218,   219,   220,    -1,   357,   358,    -1,
      -1,    -1,   466,    -1,   468,   365,    31,    -1,   368,    -1,
      -1,    -1,    -1,   373,    -1,    -1,    58,    -1,   378,    -1,
      -1,   246,    -1,    65,    -1,    67,    -1,    -1,    -1,    -1,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
     504,   266,    -1,    -1,    -1,   405,    88,   407,    24,    91,
      26,    27,   277,    29,    30,    -1,   281,   417,   418,    35,
      -1,    -1,    -1,    -1,    -1,   425,    -1,    -1,   428,    -1,
      -1,    -1,    -1,    -1,   434,    -1,    -1,   302,    -1,    -1,
     544,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,    -1,     8,   328,    29,    30,   466,   332,   468,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     365,    -1,    -1,   368,   504,    -1,    -1,    -1,   373,    -1,
      -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   625,   626,   627,    -1,    -1,    -1,    -1,   632,   633,
     634,    -1,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,
     405,    -1,   407,     1,   544,     3,     4,     5,     6,    -1,
       8,    -1,   417,    -1,    -1,    -1,    -1,    15,    16,    17,
     425,    -1,    -1,   428,   246,    -1,    -1,    -1,    -1,   434,
      -1,     0,     1,    31,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,   266,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,   281,
      -1,   466,    31,   468,    -1,    34,     7,     8,     9,    10,
      11,    12,    13,    14,     1,    -1,     3,     4,     5,     6,
     302,     8,    -1,    -1,    -1,   625,   626,   627,    15,    16,
      17,    32,   632,   633,   634,    -1,    -1,     0,     1,   504,
       3,     4,     5,     6,    31,     8,    -1,    -1,    -1,    -1,
     332,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   544,
      -1,    -1,    -1,   365,     0,     1,   368,     3,     4,     5,
       6,   373,     8,    -1,    -1,    -1,   378,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    -1,    -1,   405,    -1,   407,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,   425,    -1,    -1,   428,    15,    16,    17,
      -1,    -1,   434,    -1,    22,    23,    24,    25,    26,    27,
     625,   626,   627,    31,    -1,    -1,    34,   632,   633,   634,
      -1,    -1,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,   466,    -1,   468,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,   504,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,   544,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,     0,     1,    -1,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,   625,   626,   627,    31,    -1,    -1,    34,
     632,   633,   634,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,     0,     1,    -1,     3,     4,     5,     6,
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
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
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
      31,    -1,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,     0,     1,    -1,     3,     4,     5,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,     0,     1,    34,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,
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
      -1,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,     3,     4,     5,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    -1,     1,    34,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,     1,    34,     3,     4,     5,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,     1,    34,     3,     4,
       5,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,    -1,     1,    34,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    31,    -1,
       1,    34,     3,     4,     5,     6,     1,     8,     3,     4,
       5,     6,    -1,     8,    15,    16,    17,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    -1,     1,    31,     3,     4,     5,
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
      -1,    31,    15,    16,    17,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    35,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    24,     8,    26,    27,    -1,    29,    30,    -1,    15,
      16,    17,    35,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    31,     3,     4,     5,     6,
      24,     8,    26,    27,    -1,    29,    30,    -1,    15,    16,
      17,    35,    -1,     3,     4,     5,     6,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    31,    15,    16,    17,    -1,    -1,
       3,     4,     5,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    31,    15,    16,    17,    -1,    -1,     3,     4,     5,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    31,    15,
      16,    17,    -1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    31,    15,    16,    17,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    31,     7,     8,     9,    10,    11,    12,    13,
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
      12,    13,    14,    -1,    -1,    30,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    30,     7,
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
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    29,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    29
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
      45,    33,    76,    46,    54,    25,    54,    25,    29,    29,
      29,    32,    48,    43,    54,    54,    62,    62,     1,    62,
      49,    32,    32,    32,    32,    32,    49,    54,    54,    54,
      54,     6,     3,     4,     5,     6,    31,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    75,    76,    78,
       6,     6,     3,     4,     5,     6,    31,    71,    72,    75,
      76,    78,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    30,    19,    20,    22,    23,    24,    26,    27,    34,
      49,    55,    56,    57,    59,    60,    61,    76,     3,     4,
       5,     6,    31,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    75,    76,    78,    24,    26,    27,    29,
      35,     1,     1,    29,     7,     8,     9,    10,    11,    12,
      13,    14,    30,     6,    19,    20,     1,    22,    23,    24,
      26,    27,    34,    49,    55,    56,    57,    59,    60,    61,
      29,    30,     1,     1,    61,     1,    61,    11,    10,    12,
       9,     8,    13,    14,     7,    30,    70,     1,    31,     1,
      61,    70,     1,    31,     3,     4,     5,     6,    31,    70,
      71,    72,    75,    76,    78,     1,    69,    70,     1,    67,
       1,    65,     1,    64,     1,    66,    67,    67,     1,    63,
      21,    21,     1,    31,     1,    31,     1,    31,     1,    31,
       1,    61,    50,    29,    76,     1,    61,    11,    10,    12,
       9,     8,    13,    14,     7,    30,    70,     1,    31,    29,
       3,     4,     5,     6,    31,    70,    71,    72,    75,    76,
      78,     1,    69,    70,     1,    67,     1,    65,     1,    64,
       1,    66,    67,    67,     1,    63,    21,    21,    24,    26,
      27,    29,    35,     1,    31,     1,    31,     1,    31,     1,
      31,     1,    61,    50,    29,     1,    32,    32,     1,    64,
       1,    65,     1,    66,     1,    67,     1,    69,     1,    67,
       1,    67,     1,    70,     1,    63,    74,    32,    32,    74,
       1,    61,    70,     1,    31,     1,    76,     1,    61,    79,
       1,    61,     1,    62,    29,    29,    51,    29,    30,    32,
      32,     1,    64,     1,    65,     1,    66,     1,    67,     1,
      69,     1,    67,     1,    67,     1,    70,     1,    63,    74,
       1,    61,    70,     1,    31,     1,    76,     1,    61,    79,
       1,    61,     1,    62,    29,    29,    51,    32,    32,    32,
      32,    74,    32,    32,    32,    32,    32,    32,    32,    29,
      32,    29,    35,     1,    32,    32,    32,    74,    32,    32,
      32,    32,    32,    32,    32,    29,    32,    29,    35,    32,
      29,     1,    29,    29,     1,    29,     1,    29,    25,    54,
      25,    54,    62,     1,    62,    32,    29,     1,    29,    29,
       1,    29,     1,    29,    25,    54,    25,    54,    62,     1,
      62,    54,    25,    54,    25,    29,    29,    29,    54,    25,
      54,    25,    29,    29,    29,    54,    54,    62,    62,     1,
      62,    54,    54,    62,    62,     1,    62,    32,    32,    32,
      32,    32,    32,    32,    32,    54,    54,    54,    54,    54,
      54,    54,    54
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
      58,    59,    59,    60,    60,    60,    60,    60,    60,    61,
      61,    61,    61,    62,    62,    63,    63,    63,    63,    64,
      64,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    68,    69,    69,    69,    69,    70,    70,    71,    71,
      71,    71,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    76,    77,    77,    77,    77,    78,
      78,    78,    79
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
       3,     3,     3,     9,     9,     9,     9,     4,     2,     1,
       3,     3,     3,     0,     1,     1,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     1,     2,     1,     1,
       1,     1,     1,     4,     3,     1,     1,     1,     0,     1,
       1,     3,     3,     2,     1,     1,     1,     2,     2,     1,
       1,     1,     1
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
#line 3871 "src/bison/grammar.c"
        break;

    case YYSYMBOL_MULT: /* MULT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3877 "src/bison/grammar.c"
        break;

    case YYSYMBOL_ADD: /* ADD  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3883 "src/bison/grammar.c"
        break;

    case YYSYMBOL_REL: /* REL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3889 "src/bison/grammar.c"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3895 "src/bison/grammar.c"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3901 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EQ: /* EQ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3907 "src/bison/grammar.c"
        break;

    case YYSYMBOL_COLON: /* COLON  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3913 "src/bison/grammar.c"
        break;

    case YYSYMBOL_DL_DG: /* DL_DG  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3919 "src/bison/grammar.c"
        break;

    case YYSYMBOL_EXCLAMATION: /* EXCLAMATION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3925 "src/bison/grammar.c"
        break;

    case YYSYMBOL_PERCENT: /* PERCENT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3931 "src/bison/grammar.c"
        break;

    case YYSYMBOL_QUESTION: /* QUESTION  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3937 "src/bison/grammar.c"
        break;

    case YYSYMBOL_STR_LITERAL: /* STR_LITERAL  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3943 "src/bison/grammar.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3949 "src/bison/grammar.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3955 "src/bison/grammar.c"
        break;

    case YYSYMBOL_LIST: /* LIST  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3961 "src/bison/grammar.c"
        break;

    case YYSYMBOL_READ: /* READ  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3967 "src/bison/grammar.c"
        break;

    case YYSYMBOL_WRITE: /* WRITE  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 3973 "src/bison/grammar.c"
        break;

    case YYSYMBOL_external_declaration: /* external_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3979 "src/bison/grammar.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3985 "src/bison/grammar.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3991 "src/bison/grammar.c"
        break;

    case YYSYMBOL_42_1: /* @1  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 3997 "src/bison/grammar.c"
        break;

    case YYSYMBOL_46_param_list_opt: /* param_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4003 "src/bison/grammar.c"
        break;

    case YYSYMBOL_params_list: /* params_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4009 "src/bison/grammar.c"
        break;

    case YYSYMBOL_param_decl: /* param_decl  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4015 "src/bison/grammar.c"
        break;

    case YYSYMBOL_compound_stmt: /* compound_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4021 "src/bison/grammar.c"
        break;

    case YYSYMBOL_51_block_item_list_opt: /* block_item_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4027 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item_list: /* block_item_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4033 "src/bison/grammar.c"
        break;

    case YYSYMBOL_block_item: /* block_item  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4039 "src/bison/grammar.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4045 "src/bison/grammar.c"
        break;

    case YYSYMBOL_io_stmt: /* io_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4051 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expr_stmt: /* expr_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4057 "src/bison/grammar.c"
        break;

    case YYSYMBOL_cond_stmt: /* cond_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4063 "src/bison/grammar.c"
        break;

    case YYSYMBOL_else_error: /* else_error  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4069 "src/bison/grammar.c"
        break;

    case YYSYMBOL_jmp_stmt: /* jmp_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4075 "src/bison/grammar.c"
        break;

    case YYSYMBOL_iter_stmt: /* iter_stmt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4081 "src/bison/grammar.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4087 "src/bison/grammar.c"
        break;

    case YYSYMBOL_62_expression_opt: /* expression.opt  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4093 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_or_expr: /* logical_or_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4099 "src/bison/grammar.c"
        break;

    case YYSYMBOL_logical_and_expr: /* logical_and_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4105 "src/bison/grammar.c"
        break;

    case YYSYMBOL_eq_expr: /* eq_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4111 "src/bison/grammar.c"
        break;

    case YYSYMBOL_rel_expr: /* rel_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4117 "src/bison/grammar.c"
        break;

    case YYSYMBOL_list_expr: /* list_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4123 "src/bison/grammar.c"
        break;

    case YYSYMBOL_add_expr: /* add_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4129 "src/bison/grammar.c"
        break;

    case YYSYMBOL_mult_expr: /* mult_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4135 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_expr: /* unary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4141 "src/bison/grammar.c"
        break;

    case YYSYMBOL_unary_ops: /* unary_ops  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4147 "src/bison/grammar.c"
        break;

    case YYSYMBOL_postfix_expr: /* postfix_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4153 "src/bison/grammar.c"
        break;

    case YYSYMBOL_arg_expr_list: /* arg_expr_list  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4159 "src/bison/grammar.c"
        break;

    case YYSYMBOL_74_arg_expr_list_opt: /* arg_expr_list.opt  */
#line 132 "src/bison/grammar.y"
            { LIST_FREE(((*yyvaluep).list), { ast_free(__IT__->data); });  }
#line 4165 "src/bison/grammar.c"
        break;

    case YYSYMBOL_primary_expr: /* primary_expr  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4171 "src/bison/grammar.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 130 "src/bison/grammar.y"
            { symbol_free(((*yyvaluep).sym)); }
#line 4177 "src/bison/grammar.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 129 "src/bison/grammar.y"
            { free(((*yyvaluep).pchar)); }
#line 4183 "src/bison/grammar.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4189 "src/bison/grammar.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 131 "src/bison/grammar.y"
            { ast_free(((*yyvaluep).ast)); }
#line 4195 "src/bison/grammar.c"
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
#line 4504 "src/bison/grammar.c"
    break;

  case 4: /* prog: error  */
#line 137 "src/bison/grammar.y"
            {
        // idk if this is the best solution
        // actually dont work properly
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
    }
#line 4514 "src/bison/grammar.c"
    break;

  case 5: /* external_declaration_list: external_declaration_list external_declaration  */
#line 144 "src/bison/grammar.y"
                                                                          { list_push(&root->children, (yyvsp[0].ast)); }
#line 4520 "src/bison/grammar.c"
    break;

  case 6: /* external_declaration_list: external_declaration  */
#line 145 "src/bison/grammar.y"
                           { list_push(&root->children, (yyvsp[0].ast)); }
#line 4526 "src/bison/grammar.c"
    break;

  case 9: /* external_declaration: statement  */
#line 150 "src/bison/grammar.y"
                {
        show_error_range((yyloc), "statements are not allowed at top level\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 4536 "src/bison/grammar.c"
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
#line 4565 "src/bison/grammar.c"
    break;

  case 11: /* var_declaration: type ';'  */
#line 181 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "useless " BGRN "'%s'" RESET " in empty declaration\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4575 "src/bison/grammar.c"
    break;

  case 12: /* var_declaration: type id '=' error  */
#line 186 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected " WHT "';'" RESET "\n");
        free((yyvsp[-3].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4586 "src/bison/grammar.c"
    break;

  case 13: /* var_declaration: id id '=' error  */
#line 192 "src/bison/grammar.y"
                      {
        show_error_range((yylsp[-3]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-3].sym)->name);
        symbol_free((yyvsp[-3].sym));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4597 "src/bison/grammar.c"
    break;

  case 14: /* var_declaration: id id ';'  */
#line 198 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-2]), "unknown type name " BGRN "'%s'" RESET "\n", (yyvsp[-2].sym)->name);
        symbol_free((yyvsp[-2].sym));
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 4608 "src/bison/grammar.c"
    break;

  case 15: /* var_declaration: type error  */
#line 204 "src/bison/grammar.y"
                 {
        show_error_range((yylsp[-1]), "expected identifier after " BGRN "'%s'" RESET "\n", (yyvsp[-1].pchar));
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4618 "src/bison/grammar.c"
    break;

  case 16: /* var_declaration: type error ';'  */
#line 209 "src/bison/grammar.y"
                     {
        show_error_range((yylsp[-2]), "expected expression before " WHT "';'" RESET "\n");
        free((yyvsp[-2].pchar));
        (yyval.ast) = NULL;
    }
#line 4628 "src/bison/grammar.c"
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
#line 4672 "src/bison/grammar.c"
    break;

  case 18: /* $@2: %empty  */
#line 254 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4678 "src/bison/grammar.c"
    break;

  case 19: /* func_declaration: type id '(' @1 param_list.opt $@2 ')' compound_stmt  */
#line 254 "src/bison/grammar.y"
                                                              {
        (yyval.ast) = ast_userfunc_init((yyloc), current_context, (yyvsp[-4].ast), ast_params_init((yylsp[-3]), (yyvsp[-3].list)), (yyvsp[0].ast));
        current_context = previous_context;
        p_ctx_name = true;
    }
#line 4688 "src/bison/grammar.c"
    break;

  case 20: /* $@3: %empty  */
#line 259 "src/bison/grammar.y"
               {
        previous_context = current_context;
        list_push(&contexts, context_init("unnamed-func"));
        current_context = list_peek_last(&contexts);
        context_push_scope(current_context);
    }
#line 4699 "src/bison/grammar.c"
    break;

  case 21: /* $@4: %empty  */
#line 264 "src/bison/grammar.y"
                     { is_fn_blck = true; }
#line 4705 "src/bison/grammar.c"
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
#line 4718 "src/bison/grammar.c"
    break;

  case 23: /* param_list.opt: %empty  */
#line 274 "src/bison/grammar.y"
                       { (yyval.list) = NULL; }
#line 4724 "src/bison/grammar.c"
    break;

  case 25: /* params_list: params_list ',' param_decl  */
#line 278 "src/bison/grammar.y"
                                        { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 4730 "src/bison/grammar.c"
    break;

  case 26: /* params_list: param_decl  */
#line 279 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4736 "src/bison/grammar.c"
    break;

  case 27: /* params_list: error  */
#line 280 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of parameters\n");
        (yyval.list) = NULL;
    }
#line 4745 "src/bison/grammar.c"
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
#line 4764 "src/bison/grammar.c"
    break;

  case 29: /* param_decl: type  */
#line 300 "src/bison/grammar.y"
           {
        show_error_range((yylsp[0]), "expected identifier after " BGRN "'%s'" RESET "\n", (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
        (yyval.ast) = NULL;
    }
#line 4774 "src/bison/grammar.c"
    break;

  case 30: /* param_decl: id  */
#line 305 "src/bison/grammar.y"
         {
        show_error_range((yylsp[0]), "unknown type name for " BCYN "'%s'\n" RESET , (yyvsp[0].sym)->name);
        symbol_free((yyvsp[0].sym));
        (yyval.ast) = NULL;
    }
#line 4784 "src/bison/grammar.c"
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
#line 4802 "src/bison/grammar.c"
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
#line 4814 "src/bison/grammar.c"
    break;

  case 33: /* block_item_list.opt: block_item_list  */
#line 333 "src/bison/grammar.y"
                                     { (yyval.list) = (yyvsp[0].list); }
#line 4820 "src/bison/grammar.c"
    break;

  case 34: /* block_item_list.opt: %empty  */
#line 334 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 4826 "src/bison/grammar.c"
    break;

  case 35: /* block_item_list: block_item_list block_item  */
#line 337 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-1].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-1].list); }
#line 4832 "src/bison/grammar.c"
    break;

  case 36: /* block_item_list: block_item  */
#line 338 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 4838 "src/bison/grammar.c"
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
#line 4854 "src/bison/grammar.c"
    break;

  case 47: /* io_stmt: WRITE '(' expression ')' ';'  */
#line 365 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4863 "src/bison/grammar.c"
    break;

  case 48: /* io_stmt: WRITE '(' string_literal ')' ';'  */
#line 369 "src/bison/grammar.y"
                                       {
        (yyval.ast) = ast_builtinfn_init((yyloc), (yyvsp[-4].pchar), (yyvsp[-2].ast));
        free((yyvsp[-4].pchar));
    }
#line 4872 "src/bison/grammar.c"
    break;

  case 49: /* io_stmt: WRITE '(' error ')' ';'  */
#line 373 "src/bison/grammar.y"
                              {
        show_error_range((yylsp[-1]), "expected expression before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4882 "src/bison/grammar.c"
    break;

  case 50: /* io_stmt: READ '(' error ')' ';'  */
#line 378 "src/bison/grammar.y"
                             {
        show_error_range((yylsp[-1]), "expected identifier before " WHT "')'" RESET " token\n");
        free((yyvsp[-4].pchar));
        (yyval.ast) = NULL;
    }
#line 4892 "src/bison/grammar.c"
    break;

  case 51: /* io_stmt: READ '(' id ')' error  */
#line 383 "src/bison/grammar.y"
                            {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        symbol_free((yyvsp[-2].sym));
        (yyval.ast) = NULL;
    }
#line 4903 "src/bison/grammar.c"
    break;

  case 52: /* io_stmt: WRITE '(' expression ')' error  */
#line 389 "src/bison/grammar.y"
                                     {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4914 "src/bison/grammar.c"
    break;

  case 53: /* io_stmt: WRITE '(' string_literal ')' error  */
#line 395 "src/bison/grammar.y"
                                         {
        show_error_end((yylsp[0]), "expected " WHT "';'" RESET " \n");
        free((yyvsp[-4].pchar));
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 4925 "src/bison/grammar.c"
    break;

  case 54: /* io_stmt: WRITE error  */
#line 401 "src/bison/grammar.y"
                  {
        show_error_range((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4935 "src/bison/grammar.c"
    break;

  case 55: /* io_stmt: READ error  */
#line 406 "src/bison/grammar.y"
                 {
        show_error_range((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        free((yyvsp[-1].pchar));
        (yyval.ast) = NULL;
    }
#line 4945 "src/bison/grammar.c"
    break;

  case 56: /* expr_stmt: expression ';'  */
#line 413 "src/bison/grammar.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 4951 "src/bison/grammar.c"
    break;

  case 57: /* expr_stmt: error ';'  */
#line 414 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 4960 "src/bison/grammar.c"
    break;

  case 58: /* expr_stmt: error '}'  */
#line 418 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'}'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 4969 "src/bison/grammar.c"
    break;

  case 59: /* expr_stmt: error FOR  */
#line 422 "src/bison/grammar.y"
                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'for'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 4978 "src/bison/grammar.c"
    break;

  case 60: /* expr_stmt: error IF  */
#line 426 "src/bison/grammar.y"
               {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'if'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 4987 "src/bison/grammar.c"
    break;

  case 61: /* expr_stmt: error RETURN  */
#line 430 "src/bison/grammar.y"
                   {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'return'" RESET "\n");
        (yyval.ast) = NULL;
    }
#line 4996 "src/bison/grammar.c"
    break;

  case 62: /* cond_stmt: IF '(' expression ')' statement  */
#line 436 "src/bison/grammar.y"
                                                      {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-2].ast), (yyvsp[0].ast), NULL);
    }
#line 5004 "src/bison/grammar.c"
    break;

  case 63: /* cond_stmt: IF '(' expression ')' statement ELSE statement  */
#line 439 "src/bison/grammar.y"
                                                     {
        (yyval.ast) = ast_flow_init((yyloc), current_context, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 5012 "src/bison/grammar.c"
    break;

  case 64: /* cond_stmt: IF '(' expression ')' ELSE statement  */
#line 442 "src/bison/grammar.y"
                                           {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'else'" RESET "\n");
        ast_free((yyvsp[-3].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5023 "src/bison/grammar.c"
    break;

  case 65: /* cond_stmt: IF '(' error ')' statement  */
#line 448 "src/bison/grammar.y"
                                            {
        show_error_range((yylsp[-2]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5033 "src/bison/grammar.c"
    break;

  case 66: /* cond_stmt: IF '(' error ')' statement ELSE statement  */
#line 453 "src/bison/grammar.y"
                                                {
        show_error_range((yylsp[-4]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[-2].ast));
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5044 "src/bison/grammar.c"
    break;

  case 67: /* cond_stmt: IF '(' error ')' ELSE statement  */
#line 459 "src/bison/grammar.y"
                                      {
        show_error_range((yylsp[-3]), "expected expression before " WHT "')'" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5054 "src/bison/grammar.c"
    break;

  case 68: /* cond_stmt: IF error  */
#line 464 "src/bison/grammar.y"
               {
        show_error((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5063 "src/bison/grammar.c"
    break;

  case 69: /* else_error: ELSE statement  */
#line 470 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5073 "src/bison/grammar.c"
    break;

  case 70: /* else_error: error ELSE statement  */
#line 475 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[-1]), WHT "'else' " RESET " without a previous " WHT "'if'" RESET "\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5083 "src/bison/grammar.c"
    break;

  case 71: /* jmp_stmt: RETURN expression ';'  */
#line 482 "src/bison/grammar.y"
                                { (yyval.ast) = ast_jmp_init((yyloc), (yyvsp[-1].ast)); }
#line 5089 "src/bison/grammar.c"
    break;

  case 72: /* jmp_stmt: RETURN error ';'  */
#line 483 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[-1]), "expected expression before " WHT "';'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5098 "src/bison/grammar.c"
    break;

  case 73: /* iter_stmt: FOR '(' expression.opt ';' expression.opt ';' expression.opt ')' statement  */
#line 489 "src/bison/grammar.y"
                                                                                      {
        (yyval.ast) = ast_iter_init((yyloc), current_context, (yyvsp[-6].ast), (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast));
    }
#line 5106 "src/bison/grammar.c"
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
#line 5118 "src/bison/grammar.c"
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
#line 5130 "src/bison/grammar.c"
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
#line 5142 "src/bison/grammar.c"
    break;

  case 77: /* iter_stmt: FOR '(' error ')'  */
#line 513 "src/bison/grammar.y"
                        {
        show_error((yylsp[0]), "expected " WHT "';'" RESET " before " WHT "')'" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5151 "src/bison/grammar.c"
    break;

  case 78: /* iter_stmt: FOR error  */
#line 517 "src/bison/grammar.y"
                {
        show_error((yylsp[0]), "expected " WHT "'('" RESET " token\n");
        (yyval.ast) = NULL;
    }
#line 5160 "src/bison/grammar.c"
    break;

  case 80: /* expression: unary_expr '=' logical_or_expr  */
#line 524 "src/bison/grammar.y"
                                     { (yyval.ast) = ast_assign_init((yyloc), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 5166 "src/bison/grammar.c"
    break;

  case 81: /* expression: unary_expr '=' error  */
#line 525 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        ast_free((yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5176 "src/bison/grammar.c"
    break;

  case 82: /* expression: error '=' logical_or_expr  */
#line 530 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-2]), "expected expression before " WHT "'='" RESET " token\n");
        ast_free((yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5186 "src/bison/grammar.c"
    break;

  case 83: /* expression.opt: %empty  */
#line 537 "src/bison/grammar.y"
                       { (yyval.ast) = NULL; }
#line 5192 "src/bison/grammar.c"
    break;

  case 86: /* logical_or_expr: logical_or_expr OR logical_and_expr  */
#line 542 "src/bison/grammar.y"
                                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5201 "src/bison/grammar.c"
    break;

  case 87: /* logical_or_expr: logical_or_expr OR error  */
#line 546 "src/bison/grammar.y"
                               {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5211 "src/bison/grammar.c"
    break;

  case 88: /* logical_or_expr: error OR logical_and_expr  */
#line 551 "src/bison/grammar.y"
                                {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5221 "src/bison/grammar.c"
    break;

  case 90: /* logical_and_expr: logical_and_expr AND eq_expr  */
#line 559 "src/bison/grammar.y"
                                   {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5230 "src/bison/grammar.c"
    break;

  case 91: /* logical_and_expr: logical_and_expr AND error  */
#line 563 "src/bison/grammar.y"
                                 {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5240 "src/bison/grammar.c"
    break;

  case 92: /* logical_and_expr: error AND eq_expr  */
#line 568 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5250 "src/bison/grammar.c"
    break;

  case 94: /* eq_expr: eq_expr EQ rel_expr  */
#line 576 "src/bison/grammar.y"
                          {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5259 "src/bison/grammar.c"
    break;

  case 95: /* eq_expr: eq_expr EQ error  */
#line 580 "src/bison/grammar.y"
                       {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5269 "src/bison/grammar.c"
    break;

  case 96: /* eq_expr: error EQ rel_expr  */
#line 585 "src/bison/grammar.y"
                        {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5279 "src/bison/grammar.c"
    break;

  case 98: /* rel_expr: rel_expr REL list_expr  */
#line 593 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5288 "src/bison/grammar.c"
    break;

  case 99: /* rel_expr: rel_expr REL error  */
#line 597 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5298 "src/bison/grammar.c"
    break;

  case 100: /* rel_expr: error REL list_expr  */
#line 602 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5308 "src/bison/grammar.c"
    break;

  case 102: /* list_expr: add_expr DL_DG list_expr  */
#line 610 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5317 "src/bison/grammar.c"
    break;

  case 103: /* list_expr: add_expr COLON list_expr  */
#line 614 "src/bison/grammar.y"
                               {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5326 "src/bison/grammar.c"
    break;

  case 104: /* list_expr: add_expr DL_DG error  */
#line 618 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5336 "src/bison/grammar.c"
    break;

  case 105: /* list_expr: add_expr COLON error  */
#line 623 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5346 "src/bison/grammar.c"
    break;

  case 106: /* list_expr: error DL_DG list_expr  */
#line 628 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5356 "src/bison/grammar.c"
    break;

  case 107: /* list_expr: error COLON list_expr  */
#line 633 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5366 "src/bison/grammar.c"
    break;

  case 109: /* add_expr: add_expr ADD mult_expr  */
#line 641 "src/bison/grammar.y"
                             {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5375 "src/bison/grammar.c"
    break;

  case 110: /* add_expr: add_expr ADD error  */
#line 645 "src/bison/grammar.y"
                         {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5385 "src/bison/grammar.c"
    break;

  case 111: /* add_expr: error ADD mult_expr  */
#line 650 "src/bison/grammar.y"
                          {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5395 "src/bison/grammar.c"
    break;

  case 113: /* mult_expr: mult_expr MULT unary_expr  */
#line 658 "src/bison/grammar.y"
                                {
        (yyval.ast) = ast_binop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[-2].ast), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5404 "src/bison/grammar.c"
    break;

  case 114: /* mult_expr: mult_expr MULT error  */
#line 662 "src/bison/grammar.y"
                           {
        show_error_range((yylsp[0]), "expected expression before " WHT "'%c'" RESET " token\n", yychar);
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[-2].ast));
        (yyval.ast) = NULL;
    }
#line 5414 "src/bison/grammar.c"
    break;

  case 115: /* mult_expr: error MULT unary_expr  */
#line 667 "src/bison/grammar.y"
                            {
        show_error_range((yylsp[-1]), "expected expression before " WHT "'%s'" RESET " token\n", (yyvsp[-1].pchar));
        cleanup_expr_err((yyvsp[-1].pchar), (yyvsp[0].ast));
        (yyval.ast) = NULL;
    }
#line 5424 "src/bison/grammar.c"
    break;

  case 117: /* unary_expr: unary_ops unary_expr  */
#line 675 "src/bison/grammar.y"
                           {
        (yyval.ast) = ast_uniop_init((yyloc), (yyvsp[-1].pchar), (yyvsp[0].ast));
        free((yyvsp[-1].pchar));
    }
#line 5433 "src/bison/grammar.c"
    break;

  case 123: /* postfix_expr: id '(' arg_expr_list.opt ')'  */
#line 688 "src/bison/grammar.y"
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
#line 5456 "src/bison/grammar.c"
    break;

  case 124: /* arg_expr_list: arg_expr_list ',' expression  */
#line 708 "src/bison/grammar.y"
                                            { list_push(&(yyvsp[-2].list), (yyvsp[0].ast)); (yyval.list) = (yyvsp[-2].list); }
#line 5462 "src/bison/grammar.c"
    break;

  case 125: /* arg_expr_list: expression  */
#line 709 "src/bison/grammar.y"
                 { (yyval.list) = list_node_init((yyvsp[0].ast)); }
#line 5468 "src/bison/grammar.c"
    break;

  case 126: /* arg_expr_list: error  */
#line 710 "src/bison/grammar.y"
            {
        show_error_range((yylsp[0]), "invalid list of arguments\n");
        (yyval.list) = NULL;
    }
#line 5477 "src/bison/grammar.c"
    break;

  case 128: /* arg_expr_list.opt: %empty  */
#line 717 "src/bison/grammar.y"
             { (yyval.list) = NULL; }
#line 5483 "src/bison/grammar.c"
    break;

  case 129: /* primary_expr: id  */
#line 720 "src/bison/grammar.y"
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
#line 5498 "src/bison/grammar.c"
    break;

  case 131: /* primary_expr: '(' expression ')'  */
#line 731 "src/bison/grammar.y"
                         {
        if ((yyvsp[-1].ast)) {
            --(yyvsp[-1].ast)->rule_pos.first_column;
            ++(yyvsp[-1].ast)->rule_pos.last_column;
        }
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 5510 "src/bison/grammar.c"
    break;

  case 132: /* primary_expr: '(' error ')'  */
#line 738 "src/bison/grammar.y"
                    {
        show_error_range((yylsp[-1]), "expected expression\n");
        (yyval.ast) = NULL;
    }
#line 5519 "src/bison/grammar.c"
    break;

  case 133: /* primary_expr: id error  */
#line 742 "src/bison/grammar.y"
               {
        show_error_range((yylsp[0]), "expected " WHT "';'" RESET "\n");
        symbol_free((yyvsp[-1].sym));
        (yyval.ast) = NULL;
    }
#line 5529 "src/bison/grammar.c"
    break;

  case 137: /* type: INT LIST  */
#line 754 "src/bison/grammar.y"
               {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5541 "src/bison/grammar.c"
    break;

  case 138: /* type: FLOAT LIST  */
#line 761 "src/bison/grammar.y"
                 {
        char *type = calloc(strlen((yyvsp[-1].pchar)) + strlen((yyvsp[0].pchar)) + 2, sizeof(char));
        sprintf(type, "%s %s", (yyvsp[-1].pchar), (yyvsp[0].pchar));
        free((yyvsp[-1].pchar));
        free((yyvsp[0].pchar));
        (yyval.pchar) = type;
    }
#line 5553 "src/bison/grammar.c"
    break;

  case 139: /* constant: NUMBER_REAL  */
#line 770 "src/bison/grammar.y"
                      { (yyval.ast) = ast_number_init((yyloc), K_REAL, (NumberValue){ .real=(yyvsp[0].real) }); }
#line 5559 "src/bison/grammar.c"
    break;

  case 140: /* constant: NUMBER_INT  */
#line 771 "src/bison/grammar.y"
                 { (yyval.ast) = ast_number_init((yyloc), K_INTEGER, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5565 "src/bison/grammar.c"
    break;

  case 141: /* constant: NIL  */
#line 772 "src/bison/grammar.y"
          { (yyval.ast) = ast_number_init((yyloc), K_NIL, (NumberValue){ .integer=(yyvsp[0].integer) }); }
#line 5571 "src/bison/grammar.c"
    break;

  case 142: /* string_literal: STR_LITERAL  */
#line 775 "src/bison/grammar.y"
                            {
        (yyval.ast) = ast_str_init((yyloc), (yyvsp[0].pchar));
        free((yyvsp[0].pchar));
    }
#line 5580 "src/bison/grammar.c"
    break;


#line 5584 "src/bison/grammar.c"

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

#line 781 "src/bison/grammar.y"


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
