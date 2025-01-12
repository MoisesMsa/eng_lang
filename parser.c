/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);
int yyerror(char *s);
extern char * yytext;
extern int yylineno;

#line 82 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUMBER = 4,                     /* NUMBER  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_TYPE = 7,                       /* TYPE  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_IN = 12,                        /* IN  */
  YYSYMBOL_ARROW = 13,                     /* ARROW  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_FUNCTION = 15,                  /* FUNCTION  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_MULT = 18,                      /* MULT  */
  YYSYMBOL_DIVISION = 19,                  /* DIVISION  */
  YYSYMBOL_EXPOENT = 20,                   /* EXPOENT  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_EQUALS = 24,                    /* EQUALS  */
  YYSYMBOL_DIFF = 25,                      /* DIFF  */
  YYSYMBOL_LESS = 26,                      /* LESS  */
  YYSYMBOL_GREATER = 27,                   /* GREATER  */
  YYSYMBOL_LESSEQUALS = 28,                /* LESSEQUALS  */
  YYSYMBOL_GREATEREQUALS = 29,             /* GREATEREQUALS  */
  YYSYMBOL_INCREMENT = 30,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 31,                 /* DECREMENT  */
  YYSYMBOL_INCREMENT_ASSIGN = 32,          /* INCREMENT_ASSIGN  */
  YYSYMBOL_DECREMENT_ASSIGN = 33,          /* DECREMENT_ASSIGN  */
  YYSYMBOL_MATRIX = 34,                    /* MATRIX  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* ':'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_sub_programs = 47,              /* sub_programs  */
  YYSYMBOL_sub_program = 48,               /* sub_program  */
  YYSYMBOL_param_list = 49,                /* param_list  */
  YYSYMBOL_param = 50,                     /* param  */
  YYSYMBOL_block = 51,                     /* block  */
  YYSYMBOL_stmts_list = 52,                /* stmts_list  */
  YYSYMBOL_stmt = 53,                      /* stmt  */
  YYSYMBOL_stmt_array = 54,                /* stmt_array  */
  YYSYMBOL_stmt_matrix = 55,               /* stmt_matrix  */
  YYSYMBOL_matrix_twod = 56,               /* matrix_twod  */
  YYSYMBOL_matrix_acess = 57,              /* matrix_acess  */
  YYSYMBOL_dms_acess = 58,                 /* dms_acess  */
  YYSYMBOL_dms = 59,                       /* dms  */
  YYSYMBOL_condition = 60,                 /* condition  */
  YYSYMBOL_expr = 61,                      /* expr  */
  YYSYMBOL_term = 62,                      /* term  */
  YYSYMBOL_factor = 63,                    /* factor  */
  YYSYMBOL_exp = 64,                       /* exp  */
  YYSYMBOL_expr_list = 65,                 /* expr_list  */
  YYSYMBOL_args = 66                       /* args  */
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
typedef yytype_uint8 yy_state_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      35,    36,     2,     2,    37,    44,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    51,    52,    55,    58,    59,    60,    63,
      64,    65,    66,    69,    72,    73,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    91,
      92,    93,    96,    97,    98,    99,   102,   103,   106,   107,
     109,   110,   112,   113,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   131,   132,   133,   137,   138,   139,   142,
     143,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   164,   165,   168,   169,
     170
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMBER",
  "FLOAT", "STRING", "TYPE", "IF", "ELSE", "WHILE", "FOR", "IN", "ARROW",
  "ASSIGN", "FUNCTION", "PLUS", "MINUS", "MULT", "DIVISION", "EXPOENT",
  "AND", "OR", "NOT", "EQUALS", "DIFF", "LESS", "GREATER", "LESSEQUALS",
  "GREATEREQUALS", "INCREMENT", "DECREMENT", "INCREMENT_ASSIGN",
  "DECREMENT_ASSIGN", "MATRIX", "'('", "')'", "','", "':'", "'{'", "'}'",
  "';'", "'['", "']'", "'-'", "$accept", "program", "sub_programs",
  "sub_program", "param_list", "param", "block", "stmts_list", "stmt",
  "stmt_array", "stmt_matrix", "matrix_twod", "matrix_acess", "dms_acess",
  "dms", "condition", "expr", "term", "factor", "exp", "expr_list", "args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-19)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,    14,    19,    -9,   -58,   -11,   -58,   -58,     2,   -10,
      -1,    42,    23,    75,     2,    48,   -58,    95,   -58,    64,
     -58,    73,    48,    10,   -58,   -58,   140,   -58,   -58,   -58,
      78,    78,   129,   121,    43,   121,   106,   118,   -58,   -58,
     -58,    24,    37,   -58,   142,   125,   -58,   -58,   121,   121,
     121,    58,   100,   147,   150,   152,   162,    78,   116,   186,
     116,   156,    81,   164,   131,    24,   -58,    10,   121,   121,
     121,   121,   121,   121,    24,    24,    24,   169,   158,    -6,
       9,   153,    15,   121,   121,   121,   100,   -58,   -58,   -58,
     -58,    78,    78,   167,   121,   121,   121,   121,   121,   121,
     -58,   180,   -58,   121,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   171,   121,   -58,   121,   182,   121,   121,   121,   121,
     157,    24,    24,    24,    21,   176,   -58,    73,    24,    24,
      24,    24,    24,    24,    73,   -58,   159,   -58,    24,   121,
      24,    26,    98,   102,   105,   -58,   121,   -58,   -58,    24,
     191,   -58,   194,   -58,   134,   136,   121,   121,   174,   -58,
      24,    24,   121,   -58,   141,   174
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     6,     0,
       0,     8,     0,     0,     6,     9,    12,     0,     7,     0,
      10,     0,    42,     0,     5,    43,    63,    64,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      71,    28,    55,    58,    60,     0,    72,    73,     0,     0,
      78,     0,     0,    74,    75,    67,    63,     0,     0,     0,
       0,     0,     0,    76,     0,    62,    13,    14,     0,     0,
       0,     0,     0,     0,    16,    19,    20,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    67,
      50,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      24,     0,    61,     0,    70,    15,    53,    54,    56,    57,
      59,     0,    78,    69,     0,     0,     0,     0,     0,     0,
      40,    34,    35,    31,     0,    51,    52,     0,    48,    49,
      44,    45,    46,    47,     0,    77,    61,    80,    17,     0,
      32,     0,     0,     0,     0,    41,     0,    23,    25,    30,
       0,    37,    68,    36,     0,     0,     0,     0,    38,    68,
      33,    21,     0,    39,     0,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -58,   206,   203,   -58,   -57,   151,   -58,   -58,
     -58,   163,   165,   -22,   -13,   -24,   -23,    31,   119,   -58,
     117,   110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    10,    11,    24,    36,    37,    38,
      39,    53,    54,   145,    40,    58,    59,    42,    43,    44,
      64,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    93,    20,   100,    55,     9,     1,    60,   114,    25,
      62,    63,    65,    26,    27,    28,    29,     5,    30,     6,
      31,    32,    74,   116,     8,    75,    76,    77,    12,    82,
      15,    68,    69,    90,    89,    13,    19,    68,    69,   -11,
      68,    69,    68,    69,    41,    33,    56,    27,    28,    29,
     111,   117,    34,   119,    35,    70,    71,    16,   120,   146,
     121,   122,   123,   124,   120,    79,   115,   125,   126,   150,
     147,   128,   129,   130,   131,   132,   133,   148,    33,    14,
      63,    56,    27,    28,    29,    34,    22,    35,    17,    77,
      19,   138,    80,   140,   141,   142,   143,    68,    69,   106,
     107,    57,    21,    56,    27,    28,    29,    22,    56,    27,
      28,    29,    23,    33,    68,    69,   149,   102,    68,    69,
      34,   154,    35,   155,    56,    27,    28,    29,    56,    27,
      28,    29,    61,   160,   161,    33,   163,    91,    92,   164,
      33,   151,    34,    81,    35,   152,    66,    34,   153,    35,
      68,    69,    68,    69,    45,    23,    33,    68,    69,    67,
      73,    83,    72,    34,    84,    35,    85,    34,   101,    35,
      46,    47,    48,    49,   104,    50,   127,   158,    51,   159,
      68,    69,    52,   134,   165,    68,    69,    68,    69,   108,
     109,   110,    46,    47,   113,   118,   139,    50,    92,   144,
     -18,   103,    68,    69,    86,   156,   112,   136,   157,     7,
      94,    95,    96,    97,    98,    99,   162,    18,   105,    87,
     135,    88,   137
};

static const yytype_uint8 yycheck[] =
{
      23,    58,    15,    60,    26,     3,    15,    31,    14,    22,
      33,    34,    35,     3,     4,     5,     6,     3,     8,     0,
      10,    11,    45,    14,    35,    48,    49,    50,    38,    52,
       7,    16,    17,    57,    56,    36,    42,    16,    17,    37,
      16,    17,    16,    17,    67,    35,     3,     4,     5,     6,
      73,    42,    42,    38,    44,    18,    19,    34,    43,    38,
      83,    84,    85,    86,    43,     7,    79,    91,    92,    43,
     127,    94,    95,    96,    97,    98,    99,   134,    35,    37,
     103,     3,     4,     5,     6,    42,    43,    44,    13,   112,
      42,   114,    34,   116,   117,   118,   119,    16,    17,    68,
      69,    23,     7,     3,     4,     5,     6,    43,     3,     4,
       5,     6,    39,    35,    16,    17,   139,    36,    16,    17,
      42,   144,    44,   146,     3,     4,     5,     6,     3,     4,
       5,     6,     3,   156,   157,    35,   158,    21,    22,   162,
      35,    43,    42,    43,    44,    43,    40,    42,    43,    44,
      16,    17,    16,    17,    14,    39,    35,    16,    17,    41,
      35,    14,    20,    42,    14,    44,    14,    42,    12,    44,
      30,    31,    32,    33,    43,    35,     9,    43,    38,    43,
      16,    17,    42,     3,    43,    16,    17,    16,    17,    70,
      71,    72,    30,    31,    36,    42,    14,    35,    22,    42,
      41,    37,    16,    17,    42,    14,    37,    36,    14,     3,
      24,    25,    26,    27,    28,    29,    42,    14,    67,    56,
     103,    56,   112
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    46,    47,    48,     3,     0,    48,    35,     3,
      49,    50,    38,    36,    37,     7,    34,    13,    49,    42,
      59,     7,    43,    39,    51,    59,     3,     4,     5,     6,
       8,    10,    11,    35,    42,    44,    52,    53,    54,    55,
      59,    61,    62,    63,    64,    14,    30,    31,    32,    33,
      35,    38,    42,    56,    57,    58,     3,    23,    60,    61,
      60,     3,    61,    61,    65,    61,    40,    41,    16,    17,
      18,    19,    20,    35,    61,    61,    61,    61,    66,     7,
      34,    43,    61,    14,    14,    14,    42,    56,    57,    58,
      60,    21,    22,    51,    24,    25,    26,    27,    28,    29,
      51,    12,    36,    37,    43,    52,    62,    62,    63,    63,
      63,    61,    37,    36,    14,    59,    14,    42,    42,    38,
      43,    61,    61,    61,    61,    60,    60,     9,    61,    61,
      61,    61,    61,    61,     3,    65,    36,    66,    61,    14,
      61,    61,    61,    61,    42,    58,    38,    51,    51,    61,
      43,    43,    43,    43,    61,    61,    14,    14,    43,    43,
      61,    61,    42,    58,    61,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    49,    49,    49,    50,
      50,    50,    50,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    54,
      54,    54,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    61,    62,    62,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     8,     0,     3,     1,     3,
       4,     0,     3,     3,     2,     3,     3,     5,     5,     3,
       3,     8,     3,     5,     3,     5,     1,     1,     1,     8,
       6,     4,     5,     8,     4,     4,     5,     5,     6,     7,
       3,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     2,     1,     1,     1,     1,     2,     6,     4,
       3,     1,     2,     2,     2,     2,     1,     3,     0,     1,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
    YYNOMEM;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: sub_programs  */
#line 48 "parser.y"
                       { }
#line 1252 "parser.c"
    break;

  case 3: /* sub_programs: sub_programs sub_program  */
#line 51 "parser.y"
                                        {}
#line 1258 "parser.c"
    break;

  case 4: /* sub_programs: sub_program  */
#line 52 "parser.y"
                           {}
#line 1264 "parser.c"
    break;

  case 5: /* sub_program: FUNCTION ID '(' param_list ')' ARROW TYPE block  */
#line 55 "parser.y"
                                                              {}
#line 1270 "parser.c"
    break;

  case 6: /* param_list: %empty  */
#line 58 "parser.y"
             {}
#line 1276 "parser.c"
    break;

  case 7: /* param_list: param ',' param_list  */
#line 59 "parser.y"
                                  {}
#line 1282 "parser.c"
    break;

  case 8: /* param_list: param  */
#line 60 "parser.y"
                   {}
#line 1288 "parser.c"
    break;

  case 9: /* param: ID ':' TYPE  */
#line 63 "parser.y"
                    {}
#line 1294 "parser.c"
    break;

  case 10: /* param: ID ':' TYPE dms  */
#line 64 "parser.y"
                        {}
#line 1300 "parser.c"
    break;

  case 11: /* param: %empty  */
#line 65 "parser.y"
        {}
#line 1306 "parser.c"
    break;

  case 12: /* param: ID ':' MATRIX  */
#line 66 "parser.y"
                      {}
#line 1312 "parser.c"
    break;

  case 13: /* block: '{' stmts_list '}'  */
#line 69 "parser.y"
                           {}
#line 1318 "parser.c"
    break;

  case 14: /* stmts_list: stmt ';'  */
#line 72 "parser.y"
                      {}
#line 1324 "parser.c"
    break;

  case 16: /* stmt: ID ASSIGN expr  */
#line 76 "parser.y"
                      {}
#line 1330 "parser.c"
    break;

  case 17: /* stmt: ID ':' TYPE ASSIGN expr  */
#line 77 "parser.y"
                               {}
#line 1336 "parser.c"
    break;

  case 18: /* stmt: ID ASSIGN '(' expr ')'  */
#line 78 "parser.y"
                              {}
#line 1342 "parser.c"
    break;

  case 19: /* stmt: ID INCREMENT_ASSIGN expr  */
#line 79 "parser.y"
                                {}
#line 1348 "parser.c"
    break;

  case 20: /* stmt: ID DECREMENT_ASSIGN expr  */
#line 80 "parser.y"
                                {}
#line 1354 "parser.c"
    break;

  case 21: /* stmt: ID '[' expr ':' expr ']' ASSIGN expr  */
#line 81 "parser.y"
                                            {}
#line 1360 "parser.c"
    break;

  case 22: /* stmt: IF condition block  */
#line 82 "parser.y"
                          {}
#line 1366 "parser.c"
    break;

  case 23: /* stmt: IF condition block ELSE block  */
#line 83 "parser.y"
                                     {}
#line 1372 "parser.c"
    break;

  case 24: /* stmt: WHILE condition block  */
#line 84 "parser.y"
                             {}
#line 1378 "parser.c"
    break;

  case 25: /* stmt: FOR ID IN ID block  */
#line 85 "parser.y"
                          {}
#line 1384 "parser.c"
    break;

  case 26: /* stmt: stmt_array  */
#line 86 "parser.y"
                  {}
#line 1390 "parser.c"
    break;

  case 27: /* stmt: stmt_matrix  */
#line 87 "parser.y"
                   {}
#line 1396 "parser.c"
    break;

  case 28: /* stmt: expr  */
#line 88 "parser.y"
            {}
#line 1402 "parser.c"
    break;

  case 29: /* stmt_array: ID '[' expr ':' expr ']' ASSIGN expr  */
#line 91 "parser.y"
                                                  {}
#line 1408 "parser.c"
    break;

  case 30: /* stmt_array: ID ':' TYPE dms ASSIGN expr  */
#line 92 "parser.y"
                                         {}
#line 1414 "parser.c"
    break;

  case 31: /* stmt_array: ID dms_acess ASSIGN expr  */
#line 93 "parser.y"
                                      {}
#line 1420 "parser.c"
    break;

  case 32: /* stmt_matrix: ID ':' MATRIX ASSIGN expr  */
#line 96 "parser.y"
                                        {}
#line 1426 "parser.c"
    break;

  case 33: /* stmt_matrix: ID ':' MATRIX '[' expr ']' ASSIGN expr  */
#line 97 "parser.y"
                                                     {}
#line 1432 "parser.c"
    break;

  case 34: /* stmt_matrix: ID matrix_twod ASSIGN expr  */
#line 98 "parser.y"
                                         {}
#line 1438 "parser.c"
    break;

  case 35: /* stmt_matrix: ID matrix_acess ASSIGN expr  */
#line 99 "parser.y"
                                          {}
#line 1444 "parser.c"
    break;

  case 36: /* matrix_twod: '[' expr ']' '[' ']'  */
#line 102 "parser.y"
                                   {}
#line 1450 "parser.c"
    break;

  case 37: /* matrix_twod: '[' ']' '[' expr ']'  */
#line 103 "parser.y"
                                    {}
#line 1456 "parser.c"
    break;

  case 38: /* matrix_acess: '[' expr ']' '[' expr ']'  */
#line 106 "parser.y"
                                         {}
#line 1462 "parser.c"
    break;

  case 39: /* matrix_acess: '[' expr ']' '[' expr ']' dms_acess  */
#line 107 "parser.y"
                                                   {}
#line 1468 "parser.c"
    break;

  case 40: /* dms_acess: '[' expr ']'  */
#line 109 "parser.y"
                         {}
#line 1474 "parser.c"
    break;

  case 41: /* dms_acess: '[' expr ']' dms_acess  */
#line 110 "parser.y"
                                   {}
#line 1480 "parser.c"
    break;

  case 42: /* dms: '[' ']'  */
#line 112 "parser.y"
              {}
#line 1486 "parser.c"
    break;

  case 43: /* dms: '[' ']' dms  */
#line 113 "parser.y"
                  {}
#line 1492 "parser.c"
    break;

  case 44: /* condition: expr LESS expr  */
#line 116 "parser.y"
                           {}
#line 1498 "parser.c"
    break;

  case 45: /* condition: expr GREATER expr  */
#line 117 "parser.y"
                              {}
#line 1504 "parser.c"
    break;

  case 46: /* condition: expr LESSEQUALS expr  */
#line 118 "parser.y"
                                 {}
#line 1510 "parser.c"
    break;

  case 47: /* condition: expr GREATEREQUALS expr  */
#line 119 "parser.y"
                                    {}
#line 1516 "parser.c"
    break;

  case 48: /* condition: expr EQUALS expr  */
#line 120 "parser.y"
                             {}
#line 1522 "parser.c"
    break;

  case 49: /* condition: expr DIFF expr  */
#line 121 "parser.y"
                           {}
#line 1528 "parser.c"
    break;

  case 50: /* condition: NOT condition  */
#line 122 "parser.y"
                          {}
#line 1534 "parser.c"
    break;

  case 51: /* condition: condition AND condition  */
#line 123 "parser.y"
                                    {}
#line 1540 "parser.c"
    break;

  case 52: /* condition: condition OR condition  */
#line 124 "parser.y"
                                   {}
#line 1546 "parser.c"
    break;

  case 53: /* expr: expr PLUS term  */
#line 131 "parser.y"
                      {}
#line 1552 "parser.c"
    break;

  case 54: /* expr: expr MINUS term  */
#line 132 "parser.y"
                       {}
#line 1558 "parser.c"
    break;

  case 56: /* term: term MULT factor  */
#line 137 "parser.y"
                        {}
#line 1564 "parser.c"
    break;

  case 57: /* term: term DIVISION factor  */
#line 138 "parser.y"
                            {}
#line 1570 "parser.c"
    break;

  case 59: /* factor: exp EXPOENT factor  */
#line 142 "parser.y"
                            {}
#line 1576 "parser.c"
    break;

  case 61: /* exp: '(' expr ')'  */
#line 147 "parser.y"
                   {}
#line 1582 "parser.c"
    break;

  case 62: /* exp: '-' expr  */
#line 148 "parser.y"
               {}
#line 1588 "parser.c"
    break;

  case 63: /* exp: ID  */
#line 149 "parser.y"
         {}
#line 1594 "parser.c"
    break;

  case 64: /* exp: NUMBER  */
#line 150 "parser.y"
             {}
#line 1600 "parser.c"
    break;

  case 65: /* exp: FLOAT  */
#line 151 "parser.y"
            {}
#line 1606 "parser.c"
    break;

  case 66: /* exp: STRING  */
#line 152 "parser.y"
             {}
#line 1612 "parser.c"
    break;

  case 67: /* exp: ID dms_acess  */
#line 153 "parser.y"
                   {}
#line 1618 "parser.c"
    break;

  case 68: /* exp: ID '[' expr ':' expr ']'  */
#line 154 "parser.y"
                                {}
#line 1624 "parser.c"
    break;

  case 69: /* exp: ID '(' args ')'  */
#line 155 "parser.y"
                      {}
#line 1630 "parser.c"
    break;

  case 70: /* exp: '[' expr_list ']'  */
#line 156 "parser.y"
                        {}
#line 1636 "parser.c"
    break;

  case 71: /* exp: dms  */
#line 157 "parser.y"
          {}
#line 1642 "parser.c"
    break;

  case 72: /* exp: ID INCREMENT  */
#line 158 "parser.y"
                   {}
#line 1648 "parser.c"
    break;

  case 73: /* exp: ID DECREMENT  */
#line 159 "parser.y"
                   {}
#line 1654 "parser.c"
    break;

  case 74: /* exp: ID matrix_twod  */
#line 160 "parser.y"
                     {}
#line 1660 "parser.c"
    break;

  case 75: /* exp: ID matrix_acess  */
#line 161 "parser.y"
                      {}
#line 1666 "parser.c"
    break;

  case 76: /* expr_list: expr  */
#line 164 "parser.y"
                 {}
#line 1672 "parser.c"
    break;

  case 77: /* expr_list: expr ',' expr_list  */
#line 165 "parser.y"
                               {}
#line 1678 "parser.c"
    break;

  case 78: /* args: %empty  */
#line 168 "parser.y"
       {}
#line 1684 "parser.c"
    break;

  case 79: /* args: expr  */
#line 169 "parser.y"
            {}
#line 1690 "parser.c"
    break;

  case 80: /* args: expr ',' args  */
#line 170 "parser.y"
                     {}
#line 1696 "parser.c"
    break;


#line 1700 "parser.c"

      default: break;
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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  ++yynerrs;

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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 173 "parser.y"


int main(void) {
     return yyparse();
}

int yyerror(char *msg){
     fprintf(stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
     return 0;
}
