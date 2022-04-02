/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "semantics.hpp"
#include <string>
using namespace std;

#define pairr pair<vector<Function*> *, SymTab*>

extern FILE *yyin, *yyout;
char *tok_file, *ast_file, *tac_file;
bool show_tokens, show_ast, sa_parse, show_tac, sa_scan;
int yyerror(char*);
int yylex();
FILE *ast_file_desc, *tac_file_desc;

#line 84 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    VOID = 259,
    FLOAT = 260,
    STRING = 261,
    BOOL = 262,
    ASSIGN_OP = 263,
    SEMICOLON = 264,
    LEFT_ROUND_BRACKET = 265,
    RIGHT_ROUND_BRACKET = 266,
    LEFT_CURLY_BRACKET = 267,
    RIGHT_CURLY_BRACKET = 268,
    COMMA = 269,
    WRITE = 270,
    READ = 271,
    PLUS = 272,
    MINUS = 273,
    MULT = 274,
    DIV = 275,
    INT_NUM = 276,
    FLOAT_NUM = 277,
    NAME = 278,
    STR_CONST = 279,
    QUESTION_MARK = 280,
    COLON = 281,
    AND = 282,
    OR = 283,
    NOT = 284,
    LT = 285,
    LE = 286,
    GT = 287,
    GE = 288,
    NE = 289,
    EQ = 290,
    DO = 291,
    WHILE = 292,
    IF = 293,
    ELSE = 294,
    UMINUS = 295
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define VOID 259
#define FLOAT 260
#define STRING 261
#define BOOL 262
#define ASSIGN_OP 263
#define SEMICOLON 264
#define LEFT_ROUND_BRACKET 265
#define RIGHT_ROUND_BRACKET 266
#define LEFT_CURLY_BRACKET 267
#define RIGHT_CURLY_BRACKET 268
#define COMMA 269
#define WRITE 270
#define READ 271
#define PLUS 272
#define MINUS 273
#define MULT 274
#define DIV 275
#define INT_NUM 276
#define FLOAT_NUM 277
#define NAME 278
#define STR_CONST 279
#define QUESTION_MARK 280
#define COLON 281
#define AND 282
#define OR 283
#define NOT 284
#define LT 285
#define LE 286
#define GT 287
#define GE 288
#define NE 289
#define EQ 290
#define DO 291
#define WHILE 292
#define IF 293
#define ELSE 294
#define UMINUS 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "parser.y" /* yacc.c:355  */

    class AST* node;
    class Expression* exp;
    class Statement* stmt;
    class Stmtlist* stmtlist;
    char* str;
    int var_type;
    void* pointer;

#line 214 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   349

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    74,    99,   105,   121,   127,   137,   144,
     155,   167,   188,   204,   212,   223,   235,   236,   237,   238,
     242,   243,   247,   248,   265,   285,   293,   303,   307,   308,
     309,   310,   311,   315,   319,   323,   324,   325,   326,   327,
     328,   329,   333,   341,   345,   346,   350,   354,   358,   362,
     366,   370,   378,   386,   387,   388,   389,   390,   392,   394,
     400,   405,   410,   411,   412,   413,   417,   422,   427,   432,
     437,   442,   449,   450,   451
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "VOID", "FLOAT", "STRING",
  "BOOL", "ASSIGN_OP", "SEMICOLON", "LEFT_ROUND_BRACKET",
  "RIGHT_ROUND_BRACKET", "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET",
  "COMMA", "WRITE", "READ", "PLUS", "MINUS", "MULT", "DIV", "INT_NUM",
  "FLOAT_NUM", "NAME", "STR_CONST", "QUESTION_MARK", "COLON", "AND", "OR",
  "NOT", "LT", "LE", "GT", "GE", "NE", "EQ", "DO", "WHILE", "IF", "ELSE",
  "UMINUS", "$accept", "program", "global_decl_statement_list",
  "func_decl", "func_header", "func_def", "formal_param_list",
  "formal_param", "param_type", "optional_local_var_decl_stmt_list",
  "var_decl_stmt_list", "var_decl_stmt", "var_decl_item_list",
  "var_decl_item", "named_type", "statement_list", "statement",
  "assignment_statement", "if_condition", "if_statement",
  "do_while_statement", "while_statement", "compound_statement",
  "variable_as_operand", "variable_name", "print_statement",
  "read_statement", "expression", "rel_expression", "constant_as_operand", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -11

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-11)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,   -53,   -53,   -53,   -53,   -53,     6,    41,   -53,     2,
     -53,   -53,   -15,   -53,   -53,   -53,   -53,    13,   -53,    -7,
      21,   -53,   -53,   -53,   -53,    61,    85,   -53,   -15,   -53,
     -15,   -53,    41,    88,    60,   -53,   -53,   -53,    41,   -53,
     -15,   -53,    41,   -53,   110,   -53,   -53,   -53,   -53,   -53,
     243,    -6,   -53,    -2,    27,    29,   -53,   -53,   -53,   -53,
     -53,   -53,    56,   -53,   -53,   -53,   115,   127,   243,   243,
     -53,   -53,   -53,   243,   -53,    59,   -53,   -53,    40,    32,
     243,   243,    -2,   243,   -53,   -53,   149,   -53,   295,   -53,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   -53,    65,   174,   199,    42,    86,   -53,
       7,     7,   -53,   -53,   251,   295,   289,   314,   314,   314,
     314,   314,   314,   243,    -2,   -53,    -2,   -53,   243,   224,
     -53,   -53,   270,    62,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    28,    30,    29,    32,    31,     0,     0,     7,     0,
       3,     6,     0,     1,     4,     2,     5,     0,    27,     0,
      26,    16,    17,    19,    18,     0,     0,    14,     0,    24,
       0,     9,    20,     0,     0,    15,    25,    34,    21,    22,
       0,     8,    20,    13,     0,    23,    26,    34,    34,    12,
       0,     0,    50,     0,     0,     0,    33,    35,    38,    39,
      40,    41,     0,    49,    36,    37,     0,     0,     0,     0,
      72,    73,    74,     0,    64,     0,    63,    65,     0,     0,
       0,     0,     0,     0,    11,    48,     0,    57,    62,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,     0,    45,     0,    58,
      53,    54,    55,    56,     0,    60,    61,    66,    67,    68,
      69,    70,    71,     0,     0,    43,     0,    42,     0,     0,
      47,    44,    59,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,    78,   -53,    91,   -53,    73,   -53,    66,
     -53,     4,   -53,   -25,    25,    54,   -52,   -53,   -53,   -53,
     -53,   -53,   -53,   -44,    58,   -53,   -53,   -40,   -53,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    26,    27,    28,    37,
      38,    39,    19,    20,    40,    44,    56,    57,    82,    58,
      59,    60,    61,    74,    63,    64,    65,    75,    76,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    79,    29,    35,    11,    36,    13,    30,    18,    62,
      48,    16,    17,    50,    51,    46,    21,    52,    22,    23,
      24,    52,    62,    62,    25,    12,    92,    93,    86,    87,
     107,   -10,    12,    88,    53,    54,    55,    80,    62,    81,
     105,   106,    45,   108,     1,     2,     3,     4,     5,   103,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    21,    83,    22,    23,    24,    89,   104,
      31,   134,   130,    32,   131,   123,    90,    91,    92,    93,
      62,   126,    62,   129,    94,    14,    95,    96,   132,    97,
      98,    99,   100,   101,   102,   127,    33,    41,    15,    34,
      42,    66,    67,    90,    91,    92,    93,    43,    47,    78,
       0,    94,     0,    95,    96,     0,    97,    98,    99,   100,
     101,   102,    48,    49,     0,    50,    51,    48,    84,     0,
      50,    51,     0,    52,     0,     0,     0,     0,    52,    48,
      85,     0,    50,    51,     0,     0,    53,    54,    55,     0,
      52,    53,    54,    55,     0,     0,     0,     0,     0,     0,
     109,     0,     0,    53,    54,    55,    90,    91,    92,    93,
       0,     0,     0,     0,    94,     0,    95,    96,     0,    97,
      98,    99,   100,   101,   102,   124,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,     0,     0,     0,    94,
       0,    95,    96,     0,    97,    98,    99,   100,   101,   102,
     125,     0,     0,     0,     0,     0,    90,    91,    92,    93,
       0,     0,     0,     0,    94,     0,    95,    96,     0,    97,
      98,    99,   100,   101,   102,   133,     0,     0,     0,     0,
       0,    90,    91,    92,    93,     0,     0,     0,     0,    94,
       0,    95,    96,    68,    97,    98,    99,   100,   101,   102,
       0,    69,     0,     0,    70,    71,    52,    72,    90,    91,
      92,    93,    73,     0,     0,     0,    94,   128,    95,    96,
       0,    97,    98,    99,   100,   101,   102,    90,    91,    92,
      93,     0,     0,     0,     0,    94,     0,    95,    96,     0,
      97,    98,    99,   100,   101,   102,    90,    91,    92,    93,
       0,     0,    90,    91,    92,    93,    95,     0,     0,    97,
      98,    99,   100,   101,   102,    97,    98,    99,   100,   101,
     102,    90,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -11,   -11,   -11,   -11,   -11,   -11
};

static const yytype_int16 yycheck[] =
{
      44,    53,     9,    28,     0,    30,     0,    14,    23,    53,
      12,     7,    10,    15,    16,    40,     3,    23,     5,     6,
       7,    23,    66,    67,    11,     0,    19,    20,    68,    69,
      82,    10,     7,    73,    36,    37,    38,    10,    82,    10,
      80,    81,    38,    83,     3,     4,     5,     6,     7,     9,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     3,     8,     5,     6,     7,     9,    37,
       9,     9,   124,    12,   126,    10,    17,    18,    19,    20,
     124,    39,   126,   123,    25,     7,    27,    28,   128,    30,
      31,    32,    33,    34,    35,     9,    11,     9,     7,    14,
      12,    47,    48,    17,    18,    19,    20,    34,    42,    51,
      -1,    25,    -1,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    12,    13,    -1,    15,    16,    12,    13,    -1,
      15,    16,    -1,    23,    -1,    -1,    -1,    -1,    23,    12,
      13,    -1,    15,    16,    -1,    -1,    36,    37,    38,    -1,
      23,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    36,    37,    38,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      11,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    11,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      -1,    27,    28,    10,    30,    31,    32,    33,    34,    35,
      -1,    18,    -1,    -1,    21,    22,    23,    24,    17,    18,
      19,    20,    29,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    17,    18,    19,    20,
      -1,    -1,    17,    18,    19,    20,    27,    -1,    -1,    30,
      31,    32,    33,    34,    35,    30,    31,    32,    33,    34,
      35,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    42,    43,    44,    45,
      46,    52,    55,     0,    44,    46,    52,    10,    23,    53,
      54,     3,     5,     6,     7,    11,    47,    48,    49,     9,
      14,     9,    12,    11,    14,    54,    54,    50,    51,    52,
      55,     9,    12,    48,    56,    52,    54,    50,    12,    13,
      15,    16,    23,    36,    37,    38,    57,    58,    60,    61,
      62,    63,    64,    65,    66,    67,    56,    56,    10,    18,
      21,    22,    24,    29,    64,    68,    69,    70,    65,    57,
      10,    10,    59,     8,    13,    13,    68,    68,    68,     9,
      17,    18,    19,    20,    25,    27,    28,    30,    31,    32,
      33,    34,    35,     9,    37,    68,    68,    57,    68,    11,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    10,    11,    11,    39,     9,    26,    68,
      57,    57,    68,    11,     9
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    43,    43,    44,    44,
      45,    46,    46,    47,    47,    48,    49,    49,    49,    49,
      50,    50,    51,    51,    52,    53,    53,    54,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    58,    59,    60,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    70,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     1,     5,     4,
       2,     8,     7,     3,     1,     2,     1,     1,     1,     1,
       0,     1,     1,     2,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     5,     3,     7,     5,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     2,     3,     5,
       3,     3,     2,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 50 "parser.y" /* yacc.c:1646  */
    { 
        pairr* K = (pairr *) (yyvsp[-1].pointer);
        auto P = new Program();
        P->Global_Symtab = K->second;
        P->functions = (*(K->first));
        delete K->first;
        delete K;
        P->functions.push_back((Function *)(yyvsp[0].pointer));
        if(!sa_parse){
            P->infer_type();
            P->weird_check_for_A2();
            if(show_ast){
                string k = P->print();
                fprintf(ast_file_desc, k.c_str());
            }

            if(show_tac){
                P->generate_tac();
                fprintf(tac_file_desc, P->print_tac().c_str());
            }
        }
        
        (yyval.pointer) = P;
     }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "parser.y" /* yacc.c:1646  */
    { 
        auto P = new Program();
        P->Global_Symtab = new SymTab();
        P->functions = vector<Function*>();
        P->functions.push_back((Function *)(yyvsp[0].pointer));
        if(!sa_parse){
            P->infer_type();
            P->weird_check_for_A2();
            if(show_ast){
                string k = P->print();
                fprintf(ast_file_desc, k.c_str());
            }

            if(show_tac){
                P->generate_tac();
                fprintf(tac_file_desc, P->print_tac().c_str());
            }
        }
        (yyval.pointer) = P;

        
     }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "parser.y" /* yacc.c:1646  */
    {  
            pairr* K = (pairr *)(yyvsp[-1].pointer);
            K->first->push_back((Function *)(yyvsp[0].pointer));
            (yyval.pointer) = K;
        }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 106 "parser.y" /* yacc.c:1646  */
    {
            pairr* K = (pairr *)(yyvsp[-1].pointer);
            SymTab* X = K->second;
            SymTab* Y = (SymTab *)(yyvsp[0].pointer);

            for(auto vars : *Y){
                auto ret = X->insert(pair<string, int>(vars.first, vars.second));
                if (ret.second == false){
                    //TODO
                    yyerror("Variable declared more than once in the same scope");
                }
            }
            delete Y;
            (yyval.pointer) = K;
        }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 121 "parser.y" /* yacc.c:1646  */
    { 
        auto S = new pair<vector<Function*> *, SymTab*>();
        S->second = (SymTab *)(yyvsp[0].pointer);   
        S->first = new vector<Function*>();
        (yyval.pointer) = S;  
     }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 127 "parser.y" /* yacc.c:1646  */
    {   
        auto S = new pair<vector<Function*> *, SymTab*>();
        S->second = new SymTab();
        S->first = new vector<Function*>();
        S->first->push_back((Function *)(yyvsp[0].pointer));
        (yyval.pointer) = S;
     }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 137 "parser.y" /* yacc.c:1646  */
    {
		Function* func = (Function *)(yyvsp[-4].pointer);
        func->decl_or_def = IS_DECLARATION;	
        vector<pair<string, int>>* params = (vector<pair<string, int>>*)(yyvsp[-2].pointer);
        func->Param_List   = params;
		(yyval.pointer) = func; 
	}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 144 "parser.y" /* yacc.c:1646  */
    {
		
		Function* func = (Function *)(yyvsp[-3].pointer);
        func->decl_or_def = IS_DECLARATION;	
        func->Param_List   = new vector<pair<string, int>>;
		(yyval.pointer) = func; 

	}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "parser.y" /* yacc.c:1646  */
    {
                auto func = new Function(); 
				func->return_type = (yyvsp[-1].var_type);
                string* name = (string*)(yyvsp[0].pointer);
				func->Name = *name;
                delete name;
				(yyval.pointer) = func;
            }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 168 "parser.y" /* yacc.c:1646  */
    {
		
		SymTab* locals = (SymTab *)(yyvsp[-2].pointer);
		vector<pair<string, int>>* params = (vector<pair<string, int>>*)(yyvsp[-5].pointer);
		for(auto vars : *params){
		    auto ret = locals->insert({vars.first, vars.second});
		    if (ret.second == false){
                //TODO
                yyerror("Variable declared more than once in the same scope");
		    }
		}

		Function* func = (Function *)(yyvsp[-7].pointer);
		func->stmtlist = (yyvsp[-1].stmtlist);
		func->Local_Symtab = locals;
		func->Param_List   = params;
        func->decl_or_def = IS_DEFINITION;
		
		(yyval.pointer) = func; 
	}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 189 "parser.y" /* yacc.c:1646  */
    {
		
		SymTab* locals = (SymTab *)(yyvsp[-2].pointer);

		Function* func = (Function *)(yyvsp[-6].pointer);
		func->stmtlist = (yyvsp[-1].stmtlist);
		func->Local_Symtab = locals;
		func->Param_List   = new vector<pair<string, int>>;
        func->decl_or_def = IS_DEFINITION;
		
		(yyval.pointer) = func; 
	}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 205 "parser.y" /* yacc.c:1646  */
    { 
			vector<pair<string, int>>* X = (vector<pair<string, int>>*)(yyvsp[-2].pointer);
			pair<string, int>* Y = (pair<string, int> *)(yyvsp[0].pointer);
			X->push_back({Y->first, Y->second});
			delete Y; 
        	(yyval.pointer) = X;
		}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 213 "parser.y" /* yacc.c:1646  */
    {
            auto ret = new vector<pair<string, int>>;
            pair<string, int>* elem = (pair<string, int>*) (yyvsp[0].pointer);
            ret->push_back({elem->first, elem->second});
            delete elem;
            (yyval.pointer) = ret;
        }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 224 "parser.y" /* yacc.c:1646  */
    { 
            auto ret = new pair<string, int>;
            string* add = (string*)(yyvsp[0].pointer);
            ret->first = *add;
            delete add;
            ret->second = (yyvsp[-1].var_type);
            (yyval.pointer) = ret; 
        }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 235 "parser.y" /* yacc.c:1646  */
    {   (yyval.var_type) = TYPE_INT;    }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 236 "parser.y" /* yacc.c:1646  */
    {   (yyval.var_type) = TYPE_FLOAT;    }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 237 "parser.y" /* yacc.c:1646  */
    {   (yyval.var_type) = TYPE_BOOL;    }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 238 "parser.y" /* yacc.c:1646  */
    {   (yyval.var_type) = TYPE_STRING;    }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 242 "parser.y" /* yacc.c:1646  */
    {    (yyval.pointer) = new SymTab();   }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 243 "parser.y" /* yacc.c:1646  */
    {    (yyval.pointer) = (yyvsp[0].pointer);   }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 247 "parser.y" /* yacc.c:1646  */
    {    (yyval.pointer) = (yyvsp[0].pointer);   }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 248 "parser.y" /* yacc.c:1646  */
    {
        SymTab* X = (SymTab *)(yyvsp[-1].pointer);
        SymTab* Y = (SymTab *)(yyvsp[0].pointer);

        for(auto vars : *Y){
            auto ret = X->insert(pair<string, int>(vars.first, vars.second));
            if (ret.second == false){
                //TODO
                yyerror("Variable declared more than once in the same scope");
            }
        }
        delete Y;
        (yyval.pointer) = X;
    }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 265 "parser.y" /* yacc.c:1646  */
    {
        auto X = new SymTab();
        vector<string>* K = (vector<string>*)(yyvsp[-1].pointer);
        int type = (yyvsp[-2].var_type);
        if(type == TYPE_VOID){
            yyerror("Variable type cannot be void\n");
        }
        for(auto var_name : *K){
            auto ret = X->insert(pair<string, int>(var_name, type));
            if (ret.second == false){
                //TODO
                yyerror("Variable declared more than once in the same scope\n");
            }
        }
        delete K;
        (yyval.pointer) = X;
    }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 286 "parser.y" /* yacc.c:1646  */
    {   
                                    vector<string>* K = (vector<string>*)(yyvsp[-2].pointer);
                                    string* add = (string*)(yyvsp[0].pointer);
                                    K->push_back(*add);
                                    delete add;
                                    (yyval.pointer) = K;
                                }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 293 "parser.y" /* yacc.c:1646  */
    {   
                                    auto K = new vector<string>;
                                    string* add = (string*)(yyvsp[0].pointer);
                                    K->push_back(*add);
                                    delete add;
                                    (yyval.pointer) = K;
                                }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 303 "parser.y" /* yacc.c:1646  */
    {  (yyval.pointer) = new string(yylval.str); }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 307 "parser.y" /* yacc.c:1646  */
    {   (yyval.var_type) = TYPE_INT;    }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 308 "parser.y" /* yacc.c:1646  */
    {   (yyval.var_type) = TYPE_FLOAT;    }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 309 "parser.y" /* yacc.c:1646  */
    {   (yyval.var_type) = TYPE_VOID;    }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 310 "parser.y" /* yacc.c:1646  */
    {   (yyval.var_type) = TYPE_BOOL;    }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 311 "parser.y" /* yacc.c:1646  */
    {   (yyval.var_type) = TYPE_STRING;    }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 315 "parser.y" /* yacc.c:1646  */
    {
                                     (yyval.stmtlist) = (yyvsp[-1].stmtlist);
                                     ((yyval.stmtlist))->statements.push_back((yyvsp[0].stmt));
                                }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 319 "parser.y" /* yacc.c:1646  */
    {    (yyval.stmtlist) = new Stmtlist();    }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 323 "parser.y" /* yacc.c:1646  */
    {    (yyval.stmt) = (yyvsp[0].stmt);    }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 324 "parser.y" /* yacc.c:1646  */
    {    (yyval.stmt) = (yyvsp[0].stmt);    }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 325 "parser.y" /* yacc.c:1646  */
    {    (yyval.stmt) = (yyvsp[0].stmt);    }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 333 "parser.y" /* yacc.c:1646  */
    {    auto As = new Assignment_Stmt();  
                                                                 As->LHS = (yyvsp[-3].exp);
                                                                 As->RHS = (yyvsp[-1].exp);
                                                                 (yyval.stmt) = As;
                                                            }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 362 "parser.y" /* yacc.c:1646  */
    {  (yyval.exp) = (yyvsp[0].exp);     }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 366 "parser.y" /* yacc.c:1646  */
    {  auto i = new Name_Expr();  i->value = string(yylval.str);  (yyval.exp) = i;   }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 371 "parser.y" /* yacc.c:1646  */
    {   auto Ws = new Write_Stmt();
					    Ws->expression = (yyvsp[-1].exp);
					    (yyval.stmt) = Ws;
					}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 379 "parser.y" /* yacc.c:1646  */
    {   auto Rs = new Read_Stmt();
					    Rs->var_name = (yyvsp[-1].exp);
					    (yyval.stmt) = Rs;
					}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 386 "parser.y" /* yacc.c:1646  */
    { auto e = new Plus_Expr()  ; e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); (yyval.exp) = e; }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 387 "parser.y" /* yacc.c:1646  */
    { auto e = new Minus_Expr() ; e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); (yyval.exp) = e; }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 388 "parser.y" /* yacc.c:1646  */
    { auto e = new Mult_Expr()  ; e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); (yyval.exp) = e; }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 389 "parser.y" /* yacc.c:1646  */
    { auto e = new Div_Expr()   ; e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); (yyval.exp) = e; }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 391 "parser.y" /* yacc.c:1646  */
    { auto e = new UMinus_Expr(); e->expression = (yyvsp[0].exp); (yyval.exp) = e; }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 393 "parser.y" /* yacc.c:1646  */
    { (yyval.exp) = (yyvsp[-1].exp); }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 395 "parser.y" /* yacc.c:1646  */
    {
									auto e = new Conditional_Expr(); 
                                    e->expression1 = (yyvsp[-4].exp);   e->expression2 = (yyvsp[-2].exp);   e->expression3 = (yyvsp[0].exp);
                                    (yyval.exp) = e;
								}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 400 "parser.y" /* yacc.c:1646  */
    { 
                                    auto e = new Boolean_Expr(); 
					                e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); e->op = string("AND");
					                (yyval.exp) = e; 
                                }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 405 "parser.y" /* yacc.c:1646  */
    {
                                    auto e = new Boolean_Expr(); 
					                e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); e->op = string("OR");
				                    (yyval.exp) = e; 
					            }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 410 "parser.y" /* yacc.c:1646  */
    { auto e = new Not_Expr(); e->expression = (yyvsp[0].exp); (yyval.exp) = e; }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 411 "parser.y" /* yacc.c:1646  */
    { (yyval.exp) = (yyvsp[0].exp); }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 412 "parser.y" /* yacc.c:1646  */
    { (yyval.exp) = (yyvsp[0].exp); }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 413 "parser.y" /* yacc.c:1646  */
    { (yyval.exp) = (yyvsp[0].exp); }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 418 "parser.y" /* yacc.c:1646  */
    {  auto e = new Relational_Expr(); 
					   e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); e->op = string("LT");
					   (yyval.exp) = e; 
					}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 423 "parser.y" /* yacc.c:1646  */
    {  auto e = new Relational_Expr(); 
					   e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); e->op = string("LE");
					   (yyval.exp) = e; 
					}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 428 "parser.y" /* yacc.c:1646  */
    {  auto e = new Relational_Expr(); 
					   e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); e->op = string("GT");
					   (yyval.exp) = e; 
					}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 433 "parser.y" /* yacc.c:1646  */
    {  auto e = new Relational_Expr(); 
					   e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); e->op = string("GE");
					   (yyval.exp) = e; 
					}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 438 "parser.y" /* yacc.c:1646  */
    {  auto e = new Relational_Expr(); 
					   e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); e->op = string("NE");
					   (yyval.exp) = e; 
					}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 443 "parser.y" /* yacc.c:1646  */
    {  auto e = new Relational_Expr(); 
					   e->left = (yyvsp[-2].exp); e->right = (yyvsp[0].exp); e->op = string("EQ");
					   (yyval.exp) = e; 
					}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 449 "parser.y" /* yacc.c:1646  */
    {  auto i = new Number_Expr_Int();  i->value = string(yylval.str);  (yyval.exp) = i;   }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 450 "parser.y" /* yacc.c:1646  */
    {  auto i = new Number_Expr_Float();  i->value = string(yylval.str);  (yyval.exp) = i;   }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 451 "parser.y" /* yacc.c:1646  */
    {  auto i = new String_Expr();  i->value = string(yylval.str);  (yyval.exp) = i;   }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2051 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 454 "parser.y" /* yacc.c:1906  */


int main(int argc, char* argv[]){
    show_tokens = 0;
    sa_parse = 0;
    show_ast = 0;
    show_tac = 0;
    sa_scan = 0;
    bool file_found = false;
    char* filename = NULL;

    for(int i=1; i<argc; i++){
        if(strcmp("--show-tokens", argv[i]) == 0){
            show_tokens = 1;
        }
        else if(strcmp("--sa-parse", argv[i]) == 0){
            sa_parse = 1;
        }
        else if(strcmp("--show-ast", argv[i]) == 0){
            show_ast = 1;
        }
        else if(strcmp("--show-tac", argv[i]) == 0){
            show_tac = 1;
        }
        else if(strcmp("--sa-scan", argv[i]) == 0){
            sa_scan = 1;
        }
        else{
            if(!file_found){
                filename = argv[i]; 
                file_found = true;    
            }
            else{
                fprintf(stderr, "only one filename allowed\n");
                exit(1);
            }
        }
    }

    if(!filename || filename[strlen(filename)-1] != 'c' || filename[strlen(filename)-2] != '.'){
        fprintf(stderr, "Filename must end in .c\n");
        exit(1);
    }

    if((yyin = fopen(filename, "r"))==0){
        fprintf(stderr, "No such file exists\n");
        exit(1);
    }

    if(show_tokens){
        tok_file = (char*)malloc(strlen(filename)+5+1);
        strncpy(tok_file, filename, strlen(filename));
        strcat(tok_file, ".toks");
        yyout = fopen(tok_file, "w");
    }

    if(show_ast && (!sa_parse) && (!sa_scan)){
        ast_file = (char*)malloc(strlen(filename)+4+1);
        strncpy(ast_file, filename, strlen(filename));
        strcat(ast_file, ".ast");
        ast_file_desc = fopen(ast_file, "w+");
    }

    if(show_tac && (!sa_parse) && (!sa_scan)){
        tac_file = (char*)malloc(strlen(filename)+4+1);
        strncpy(tac_file, filename, strlen(filename));
        strcat(tac_file, ".tac");
        tac_file_desc = fopen(tac_file, "w+");
    }

    if(sa_scan){
        while(yylex());
    }
    else{
        yyparse();
    }

    return 0;
}

int yyerror(char *mesg){
    fprintf(stderr, "%s\n", mesg);
    if(show_tokens){ 
        fclose(yyout); 
        fopen(tok_file, "w");
	}

    if(show_ast && (!sa_parse) && (!sa_scan)){
        fclose(ast_file_desc);
        fopen(ast_file, "w");
    }
    if(show_tac && (!sa_parse) && (!sa_scan)){
        fclose(tac_file_desc);
        fopen(tac_file, "w");
    }
    exit(1);
}


