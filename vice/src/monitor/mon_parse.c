/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mon_parse.y" /* yacc.c:339  */

/* -*- C -*-
 *
 * mon_parse.y - Parser for the VICE built-in monitor.
 *
 * Written by
 *  Daniel Sladic <sladic@eecg.toronto.edu>
 *  Andreas Boose <viceteam@t-online.de>
 *  Thomas Giesel <skoe@directbox.com>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include "vice.h"

#if !defined(__minix_vmd) && !defined(MACOS_COMPILE)
#ifdef __GNUC__
#undef alloca
#ifndef ANDROID_COMPILE
#define        alloca(n)       __builtin_alloca (n)
#endif
#else
#ifdef HAVE_ALLOCA_H
#include <alloca.h>
#else  /* Not HAVE_ALLOCA_H.  */
#if !defined(_AIX) && !defined(WINCE)
#ifndef _MSC_VER
extern char *alloca();
#else
#define alloca(n)   _alloca(n)
#endif  /* MSVC */
#endif /* Not AIX and not WINCE.  */
#endif /* HAVE_ALLOCA_H.  */
#endif /* GCC.  */
#endif /* MINIXVMD */

/* SunOS 4.x specific stuff */
#if defined(sun) || defined(__sun)
#  if !defined(__SVR4) && !defined(__svr4__)
#    ifdef __sparc__
#      define YYFREE
#    endif
#  endif
#endif

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "asm.h"
#include "console.h"
#include "lib.h"
#include "machine.h"
#include "mon_breakpoint.h"
#include "mon_command.h"
#include "mon_disassemble.h"
#include "mon_drive.h"
#include "mon_file.h"
#include "mon_memmap.h"
#include "mon_memory.h"
#include "mon_register.h"
#include "mon_util.h"
#include "montypes.h"
#include "resources.h"
#include "types.h"
#include "uimon.h"


#define join_ints(x,y) (LO16_TO_HI16(x)|y)
#define separate_int1(x) (HI16_TO_LO16(x))
#define separate_int2(x) (LO16(x))

static int yyerror(char *s);
static int temp;
static int resolve_datatype(unsigned guess_type, const char *num);
static int resolve_range(enum t_memspace memspace, MON_ADDR range[2],
                         const char *num);

#ifdef __IBMC__
static void __yy_memcpy (char *to, char *from, int count);
#endif

/* Defined in the lexer */
extern int new_cmd, opt_asm;
extern void free_buffer(void);
extern void make_buffer(char *str);
extern int yylex(void);
extern int cur_len, last_len;

#define ERR_ILLEGAL_INPUT 1     /* Generic error as returned by yacc.  */
#define ERR_RANGE_BAD_START 2
#define ERR_RANGE_BAD_END 3
#define ERR_BAD_CMD 4
#define ERR_EXPECT_CHECKNUM 5
#define ERR_EXPECT_END_CMD 6
#define ERR_MISSING_CLOSE_PAREN 7
#define ERR_INCOMPLETE_COMPARE_OP 8
#define ERR_EXPECT_FILENAME 9
#define ERR_ADDR_TOO_BIG 10
#define ERR_IMM_TOO_BIG 11
#define ERR_EXPECT_STRING 12
#define ERR_UNDEFINED_LABEL 13
#define ERR_EXPECT_DEVICE_NUM 14
#define ERR_EXPECT_ADDRESS 15
#define ERR_INVALID_REGISTER 16

#define BAD_ADDR (new_addr(e_invalid_space, 0))
#define CHECK_ADDR(x) ((x) == addr_mask(x))

#define YYDEBUG 1


#line 197 "mon_parse.c" /* yacc.c:339  */

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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    H_NUMBER = 258,
    D_NUMBER = 259,
    O_NUMBER = 260,
    B_NUMBER = 261,
    CONVERT_OP = 262,
    B_DATA = 263,
    H_RANGE_GUESS = 264,
    D_NUMBER_GUESS = 265,
    O_NUMBER_GUESS = 266,
    B_NUMBER_GUESS = 267,
    BAD_CMD = 268,
    MEM_OP = 269,
    IF = 270,
    MEM_COMP = 271,
    MEM_DISK8 = 272,
    MEM_DISK9 = 273,
    MEM_DISK10 = 274,
    MEM_DISK11 = 275,
    EQUALS = 276,
    TRAIL = 277,
    CMD_SEP = 278,
    LABEL_ASGN_COMMENT = 279,
    CMD_SIDEFX = 280,
    CMD_RETURN = 281,
    CMD_BLOCK_READ = 282,
    CMD_BLOCK_WRITE = 283,
    CMD_UP = 284,
    CMD_DOWN = 285,
    CMD_LOAD = 286,
    CMD_SAVE = 287,
    CMD_VERIFY = 288,
    CMD_IGNORE = 289,
    CMD_HUNT = 290,
    CMD_FILL = 291,
    CMD_MOVE = 292,
    CMD_GOTO = 293,
    CMD_REGISTERS = 294,
    CMD_READSPACE = 295,
    CMD_WRITESPACE = 296,
    CMD_RADIX = 297,
    CMD_MEM_DISPLAY = 298,
    CMD_BREAK = 299,
    CMD_TRACE = 300,
    CMD_IO = 301,
    CMD_BRMON = 302,
    CMD_COMPARE = 303,
    CMD_DUMP = 304,
    CMD_UNDUMP = 305,
    CMD_EXIT = 306,
    CMD_DELETE = 307,
    CMD_CONDITION = 308,
    CMD_COMMAND = 309,
    CMD_ASSEMBLE = 310,
    CMD_DISASSEMBLE = 311,
    CMD_NEXT = 312,
    CMD_STEP = 313,
    CMD_PRINT = 314,
    CMD_DEVICE = 315,
    CMD_HELP = 316,
    CMD_WATCH = 317,
    CMD_DISK = 318,
    CMD_QUIT = 319,
    CMD_CHDIR = 320,
    CMD_BANK = 321,
    CMD_LOAD_LABELS = 322,
    CMD_SAVE_LABELS = 323,
    CMD_ADD_LABEL = 324,
    CMD_DEL_LABEL = 325,
    CMD_SHOW_LABELS = 326,
    CMD_CLEAR_LABELS = 327,
    CMD_RECORD = 328,
    CMD_MON_STOP = 329,
    CMD_PLAYBACK = 330,
    CMD_CHAR_DISPLAY = 331,
    CMD_SPRITE_DISPLAY = 332,
    CMD_TEXT_DISPLAY = 333,
    CMD_SCREENCODE_DISPLAY = 334,
    CMD_ENTER_DATA = 335,
    CMD_ENTER_BIN_DATA = 336,
    CMD_KEYBUF = 337,
    CMD_BLOAD = 338,
    CMD_BSAVE = 339,
    CMD_SCREEN = 340,
    CMD_UNTIL = 341,
    CMD_CPU = 342,
    CMD_YYDEBUG = 343,
    CMD_BACKTRACE = 344,
    CMD_SCREENSHOT = 345,
    CMD_PWD = 346,
    CMD_DIR = 347,
    CMD_RESOURCE_GET = 348,
    CMD_RESOURCE_SET = 349,
    CMD_LOAD_RESOURCES = 350,
    CMD_SAVE_RESOURCES = 351,
    CMD_ATTACH = 352,
    CMD_DETACH = 353,
    CMD_MON_RESET = 354,
    CMD_TAPECTRL = 355,
    CMD_CARTFREEZE = 356,
    CMD_CPUHISTORY = 357,
    CMD_MEMMAPZAP = 358,
    CMD_MEMMAPSHOW = 359,
    CMD_MEMMAPSAVE = 360,
    CMD_COMMENT = 361,
    CMD_LIST = 362,
    CMD_STOPWATCH = 363,
    RESET = 364,
    CMD_EXPORT = 365,
    CMD_AUTOSTART = 366,
    CMD_AUTOLOAD = 367,
    CMD_LABEL_ASGN = 368,
    L_PAREN = 369,
    R_PAREN = 370,
    ARG_IMMEDIATE = 371,
    REG_A = 372,
    REG_X = 373,
    REG_Y = 374,
    COMMA = 375,
    INST_SEP = 376,
    L_BRACKET = 377,
    R_BRACKET = 378,
    LESS_THAN = 379,
    REG_U = 380,
    REG_S = 381,
    REG_PC = 382,
    REG_PCR = 383,
    REG_B = 384,
    REG_C = 385,
    REG_D = 386,
    REG_E = 387,
    REG_H = 388,
    REG_L = 389,
    REG_AF = 390,
    REG_BC = 391,
    REG_DE = 392,
    REG_HL = 393,
    REG_IX = 394,
    REG_IY = 395,
    REG_SP = 396,
    REG_IXH = 397,
    REG_IXL = 398,
    REG_IYH = 399,
    REG_IYL = 400,
    PLUS = 401,
    MINUS = 402,
    STRING = 403,
    FILENAME = 404,
    R_O_L = 405,
    OPCODE = 406,
    LABEL = 407,
    BANKNAME = 408,
    CPUTYPE = 409,
    MON_REGISTER = 410,
    COMPARE_OP = 411,
    RADIX_TYPE = 412,
    INPUT_SPEC = 413,
    CMD_CHECKPT_ON = 414,
    CMD_CHECKPT_OFF = 415,
    TOGGLE = 416,
    MASK = 417
  };
#endif
/* Tokens.  */
#define H_NUMBER 258
#define D_NUMBER 259
#define O_NUMBER 260
#define B_NUMBER 261
#define CONVERT_OP 262
#define B_DATA 263
#define H_RANGE_GUESS 264
#define D_NUMBER_GUESS 265
#define O_NUMBER_GUESS 266
#define B_NUMBER_GUESS 267
#define BAD_CMD 268
#define MEM_OP 269
#define IF 270
#define MEM_COMP 271
#define MEM_DISK8 272
#define MEM_DISK9 273
#define MEM_DISK10 274
#define MEM_DISK11 275
#define EQUALS 276
#define TRAIL 277
#define CMD_SEP 278
#define LABEL_ASGN_COMMENT 279
#define CMD_SIDEFX 280
#define CMD_RETURN 281
#define CMD_BLOCK_READ 282
#define CMD_BLOCK_WRITE 283
#define CMD_UP 284
#define CMD_DOWN 285
#define CMD_LOAD 286
#define CMD_SAVE 287
#define CMD_VERIFY 288
#define CMD_IGNORE 289
#define CMD_HUNT 290
#define CMD_FILL 291
#define CMD_MOVE 292
#define CMD_GOTO 293
#define CMD_REGISTERS 294
#define CMD_READSPACE 295
#define CMD_WRITESPACE 296
#define CMD_RADIX 297
#define CMD_MEM_DISPLAY 298
#define CMD_BREAK 299
#define CMD_TRACE 300
#define CMD_IO 301
#define CMD_BRMON 302
#define CMD_COMPARE 303
#define CMD_DUMP 304
#define CMD_UNDUMP 305
#define CMD_EXIT 306
#define CMD_DELETE 307
#define CMD_CONDITION 308
#define CMD_COMMAND 309
#define CMD_ASSEMBLE 310
#define CMD_DISASSEMBLE 311
#define CMD_NEXT 312
#define CMD_STEP 313
#define CMD_PRINT 314
#define CMD_DEVICE 315
#define CMD_HELP 316
#define CMD_WATCH 317
#define CMD_DISK 318
#define CMD_QUIT 319
#define CMD_CHDIR 320
#define CMD_BANK 321
#define CMD_LOAD_LABELS 322
#define CMD_SAVE_LABELS 323
#define CMD_ADD_LABEL 324
#define CMD_DEL_LABEL 325
#define CMD_SHOW_LABELS 326
#define CMD_CLEAR_LABELS 327
#define CMD_RECORD 328
#define CMD_MON_STOP 329
#define CMD_PLAYBACK 330
#define CMD_CHAR_DISPLAY 331
#define CMD_SPRITE_DISPLAY 332
#define CMD_TEXT_DISPLAY 333
#define CMD_SCREENCODE_DISPLAY 334
#define CMD_ENTER_DATA 335
#define CMD_ENTER_BIN_DATA 336
#define CMD_KEYBUF 337
#define CMD_BLOAD 338
#define CMD_BSAVE 339
#define CMD_SCREEN 340
#define CMD_UNTIL 341
#define CMD_CPU 342
#define CMD_YYDEBUG 343
#define CMD_BACKTRACE 344
#define CMD_SCREENSHOT 345
#define CMD_PWD 346
#define CMD_DIR 347
#define CMD_RESOURCE_GET 348
#define CMD_RESOURCE_SET 349
#define CMD_LOAD_RESOURCES 350
#define CMD_SAVE_RESOURCES 351
#define CMD_ATTACH 352
#define CMD_DETACH 353
#define CMD_MON_RESET 354
#define CMD_TAPECTRL 355
#define CMD_CARTFREEZE 356
#define CMD_CPUHISTORY 357
#define CMD_MEMMAPZAP 358
#define CMD_MEMMAPSHOW 359
#define CMD_MEMMAPSAVE 360
#define CMD_COMMENT 361
#define CMD_LIST 362
#define CMD_STOPWATCH 363
#define RESET 364
#define CMD_EXPORT 365
#define CMD_AUTOSTART 366
#define CMD_AUTOLOAD 367
#define CMD_LABEL_ASGN 368
#define L_PAREN 369
#define R_PAREN 370
#define ARG_IMMEDIATE 371
#define REG_A 372
#define REG_X 373
#define REG_Y 374
#define COMMA 375
#define INST_SEP 376
#define L_BRACKET 377
#define R_BRACKET 378
#define LESS_THAN 379
#define REG_U 380
#define REG_S 381
#define REG_PC 382
#define REG_PCR 383
#define REG_B 384
#define REG_C 385
#define REG_D 386
#define REG_E 387
#define REG_H 388
#define REG_L 389
#define REG_AF 390
#define REG_BC 391
#define REG_DE 392
#define REG_HL 393
#define REG_IX 394
#define REG_IY 395
#define REG_SP 396
#define REG_IXH 397
#define REG_IXL 398
#define REG_IYH 399
#define REG_IYL 400
#define PLUS 401
#define MINUS 402
#define STRING 403
#define FILENAME 404
#define R_O_L 405
#define OPCODE 406
#define LABEL 407
#define BANKNAME 408
#define CPUTYPE 409
#define MON_REGISTER 410
#define COMPARE_OP 411
#define RADIX_TYPE 412
#define INPUT_SPEC 413
#define CMD_CHECKPT_ON 414
#define CMD_CHECKPT_OFF 415
#define TOGGLE 416
#define MASK 417

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 132 "mon_parse.y" /* yacc.c:355  */

    MON_ADDR a;
    MON_ADDR range[2];
    int i;
    REG_ID reg;
    CONDITIONAL cond_op;
    cond_node_t *cond_node;
    RADIXTYPE rt;
    ACTION action;
    char *str;
    asm_mode_addr_info_t mode;

#line 574 "mon_parse.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 589 "mon_parse.c" /* yacc.c:358  */

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
#define YYFINAL  310
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1750

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  313
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  625

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   417

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
     167,   168,   165,   163,     2,   164,     2,   166,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   170,     2,
       2,     2,     2,     2,   169,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   196,   196,   197,   198,   201,   202,   205,   206,   207,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   225,   227,   229,   231,   233,   235,   237,
     239,   241,   243,   245,   247,   249,   251,   253,   255,   257,
     259,   261,   263,   265,   267,   269,   271,   273,   276,   278,
     280,   283,   288,   293,   295,   297,   299,   301,   303,   305,
     307,   309,   311,   315,   322,   321,   324,   326,   328,   332,
     334,   336,   338,   340,   342,   344,   346,   348,   350,   352,
     354,   356,   358,   360,   362,   364,   366,   368,   370,   374,
     383,   386,   390,   393,   402,   405,   414,   419,   421,   423,
     425,   427,   429,   431,   433,   435,   437,   439,   443,   445,
     450,   452,   470,   472,   474,   476,   480,   482,   484,   486,
     488,   490,   492,   494,   496,   498,   500,   502,   504,   506,
     508,   510,   512,   514,   516,   518,   520,   522,   524,   528,
     530,   532,   534,   536,   538,   540,   542,   544,   546,   548,
     550,   552,   554,   556,   558,   560,   562,   564,   568,   570,
     572,   576,   578,   582,   586,   589,   590,   593,   594,   597,
     598,   601,   602,   605,   606,   609,   615,   623,   624,   627,
     631,   632,   635,   636,   639,   640,   642,   646,   647,   650,
     655,   660,   670,   671,   674,   675,   676,   677,   678,   681,
     683,   685,   686,   687,   688,   689,   690,   691,   694,   695,
     697,   702,   704,   706,   708,   712,   718,   724,   732,   733,
     736,   737,   740,   741,   744,   745,   746,   749,   750,   753,
     754,   755,   756,   759,   760,   761,   764,   765,   766,   767,
     768,   771,   772,   773,   776,   786,   787,   790,   797,   808,
     819,   827,   846,   852,   860,   868,   870,   872,   873,   874,
     875,   876,   877,   878,   880,   882,   884,   886,   887,   888,
     889,   890,   891,   892,   893,   894,   895,   896,   897,   898,
     899,   900,   901,   902,   903,   904,   906,   907,   922,   926,
     930,   934,   938,   942,   946,   950,   954,   966,   981,   985,
     989,   993,   997,  1001,  1005,  1009,  1013,  1025,  1030,  1038,
    1039,  1040,  1041,  1045
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "H_NUMBER", "D_NUMBER", "O_NUMBER",
  "B_NUMBER", "CONVERT_OP", "B_DATA", "H_RANGE_GUESS", "D_NUMBER_GUESS",
  "O_NUMBER_GUESS", "B_NUMBER_GUESS", "BAD_CMD", "MEM_OP", "IF",
  "MEM_COMP", "MEM_DISK8", "MEM_DISK9", "MEM_DISK10", "MEM_DISK11",
  "EQUALS", "TRAIL", "CMD_SEP", "LABEL_ASGN_COMMENT", "CMD_SIDEFX",
  "CMD_RETURN", "CMD_BLOCK_READ", "CMD_BLOCK_WRITE", "CMD_UP", "CMD_DOWN",
  "CMD_LOAD", "CMD_SAVE", "CMD_VERIFY", "CMD_IGNORE", "CMD_HUNT",
  "CMD_FILL", "CMD_MOVE", "CMD_GOTO", "CMD_REGISTERS", "CMD_READSPACE",
  "CMD_WRITESPACE", "CMD_RADIX", "CMD_MEM_DISPLAY", "CMD_BREAK",
  "CMD_TRACE", "CMD_IO", "CMD_BRMON", "CMD_COMPARE", "CMD_DUMP",
  "CMD_UNDUMP", "CMD_EXIT", "CMD_DELETE", "CMD_CONDITION", "CMD_COMMAND",
  "CMD_ASSEMBLE", "CMD_DISASSEMBLE", "CMD_NEXT", "CMD_STEP", "CMD_PRINT",
  "CMD_DEVICE", "CMD_HELP", "CMD_WATCH", "CMD_DISK", "CMD_QUIT",
  "CMD_CHDIR", "CMD_BANK", "CMD_LOAD_LABELS", "CMD_SAVE_LABELS",
  "CMD_ADD_LABEL", "CMD_DEL_LABEL", "CMD_SHOW_LABELS", "CMD_CLEAR_LABELS",
  "CMD_RECORD", "CMD_MON_STOP", "CMD_PLAYBACK", "CMD_CHAR_DISPLAY",
  "CMD_SPRITE_DISPLAY", "CMD_TEXT_DISPLAY", "CMD_SCREENCODE_DISPLAY",
  "CMD_ENTER_DATA", "CMD_ENTER_BIN_DATA", "CMD_KEYBUF", "CMD_BLOAD",
  "CMD_BSAVE", "CMD_SCREEN", "CMD_UNTIL", "CMD_CPU", "CMD_YYDEBUG",
  "CMD_BACKTRACE", "CMD_SCREENSHOT", "CMD_PWD", "CMD_DIR",
  "CMD_RESOURCE_GET", "CMD_RESOURCE_SET", "CMD_LOAD_RESOURCES",
  "CMD_SAVE_RESOURCES", "CMD_ATTACH", "CMD_DETACH", "CMD_MON_RESET",
  "CMD_TAPECTRL", "CMD_CARTFREEZE", "CMD_CPUHISTORY", "CMD_MEMMAPZAP",
  "CMD_MEMMAPSHOW", "CMD_MEMMAPSAVE", "CMD_COMMENT", "CMD_LIST",
  "CMD_STOPWATCH", "RESET", "CMD_EXPORT", "CMD_AUTOSTART", "CMD_AUTOLOAD",
  "CMD_LABEL_ASGN", "L_PAREN", "R_PAREN", "ARG_IMMEDIATE", "REG_A",
  "REG_X", "REG_Y", "COMMA", "INST_SEP", "L_BRACKET", "R_BRACKET",
  "LESS_THAN", "REG_U", "REG_S", "REG_PC", "REG_PCR", "REG_B", "REG_C",
  "REG_D", "REG_E", "REG_H", "REG_L", "REG_AF", "REG_BC", "REG_DE",
  "REG_HL", "REG_IX", "REG_IY", "REG_SP", "REG_IXH", "REG_IXL", "REG_IYH",
  "REG_IYL", "PLUS", "MINUS", "STRING", "FILENAME", "R_O_L", "OPCODE",
  "LABEL", "BANKNAME", "CPUTYPE", "MON_REGISTER", "COMPARE_OP",
  "RADIX_TYPE", "INPUT_SPEC", "CMD_CHECKPT_ON", "CMD_CHECKPT_OFF",
  "TOGGLE", "MASK", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'@'", "':'",
  "$accept", "top_level", "command_list", "end_cmd", "command",
  "machine_state_rules", "register_mod", "symbol_table_rules", "asm_rules",
  "$@1", "memory_rules", "checkpoint_rules", "checkpoint_control_rules",
  "monitor_state_rules", "monitor_misc_rules", "disk_rules",
  "cmd_file_rules", "data_entry_rules", "monitor_debug_rules",
  "rest_of_line", "opt_rest_of_line", "filename", "device_num", "mem_op",
  "opt_mem_op", "register", "reg_list", "reg_asgn", "checkpt_num",
  "address_opt_range", "address_range", "opt_address", "address",
  "opt_sep", "memspace", "memloc", "memaddr", "expression",
  "opt_if_cond_expr", "cond_expr", "compare_operand", "data_list",
  "data_element", "hunt_list", "hunt_element", "value", "d_number",
  "guess_default", "number", "assembly_instr_list", "assembly_instruction",
  "post_assemble", "asm_operand_mode", "index_reg", "index_ureg", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,    43,    45,    42,    47,    40,    41,    64,
      58
};
# endif

#define YYPACT_NINF -452

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-452)))

#define YYTABLE_NINF -194

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1215,   871,  -452,  -452,    14,    90,   871,   871,   491,   491,
      15,    15,    15,   665,  1529,  1529,  1529,  1329,   257,    88,
    1081,  1172,  1172,  1329,  1529,    15,    15,    90,  1128,   665,
     665,  1547,  1198,   491,   491,   871,   822,   102,  1172,  -143,
      90,  -143,   365,   450,   450,  1547,   643,   702,   702,    15,
      90,    15,  1198,  1198,  1198,  1198,  1547,    90,  -143,    15,
      15,    90,  1198,    92,    90,    90,    15,    90,   -86,   -64,
     -43,    15,    15,    15,   871,   491,   -69,    90,   491,    90,
     491,    15,   -86,   188,   323,    90,    15,    15,    86,  1571,
    1128,  1128,   118,  1351,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,    97,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,   871,  -452,   -18,    98,  -452,  -452,  -452,  -452,
    -452,  -452,    90,  -452,  -452,   947,   947,  -452,  -452,   871,
    -452,   871,  -452,  -452,   237,   677,   237,  -452,  -452,  -452,
    -452,  -452,   491,  -452,  -452,  -452,   -69,   -69,   -69,  -452,
    -452,  -452,   -69,   -69,  -452,    90,   -69,  -452,   124,   266,
    -452,   195,    90,  -452,   -69,  -452,    90,  -452,   433,  -452,
    -452,   138,  1529,  -452,  1529,  -452,    90,   -69,    90,    90,
    -452,   264,  -452,    90,   142,    19,    65,  -452,    90,  -452,
     871,  -452,   871,    98,    90,  -452,  -452,    90,  -452,  1529,
      90,  -452,    90,    90,  -452,   280,    90,   -69,    90,   -69,
     -69,    90,   -69,  -452,    90,  -452,    90,    90,  -452,    90,
    -452,    90,  -452,    90,  -452,    90,  -452,    90,   848,  -452,
      90,   237,   237,  -452,  -452,    90,    90,  -452,  -452,  -452,
     491,  -452,  -452,    90,    90,    23,    90,    90,   871,    98,
    -452,   871,   871,  -452,  -452,   871,  -452,  -452,   871,   -69,
      90,   312,  -452,    90,   535,    90,  -452,  -452,  1114,  1114,
    1547,  1581,  1142,    56,   192,  1609,  1142,    59,  -452,    68,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,    70,  -452,  -452,    90,  -452,    90,
    -452,  -452,  -452,    18,  -452,   871,   871,   871,   871,  -452,
    -452,    58,  1061,    98,    98,  -452,   282,   518,  1466,  1511,
    -452,   871,    67,  1547,   965,   848,  1547,  -452,  1142,  1142,
     455,  -452,  -452,  -452,  1529,  -452,  -452,   162,   162,  -452,
    1547,  -452,  -452,  -452,   817,    90,    54,  -452,    52,  -452,
      98,    98,  -452,  -452,  -452,   162,  -452,  -452,  -452,  -452,
      61,  -452,    15,  -452,    15,    73,  -452,    76,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,   631,  -452,  -452,
    -452,   282,  1486,  -452,  -452,  -452,   871,  -452,  -452,    90,
    -452,  -452,    98,  -452,    98,    98,    98,   893,   871,  -452,
    -452,  -452,  -452,  1142,  -452,  1142,   347,   116,   119,   135,
     136,   144,   145,    12,  -452,   334,  -452,  -452,  -452,  -452,
     249,    87,  -452,   148,   503,   149,   152,    46,  -452,   334,
     334,  1623,  -452,  -452,  -452,  -452,   -71,   -71,  -452,  -452,
      90,  1547,    90,  -452,  -452,    90,  -452,    90,  -452,    90,
      98,  -452,  -452,   150,  -452,  -452,  -452,  -452,  -452,   631,
      90,  -452,  -452,    90,   817,    90,    90,    90,   817,   125,
    -452,    53,  -452,  -452,  -452,    90,   161,   163,    90,  -452,
    -452,    90,    90,    90,    90,    90,    90,  -452,   848,    90,
    -452,    90,    98,  -452,  -452,  -452,  -452,  -452,  -452,    90,
      98,    90,    90,    90,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,   170,   -22,  -452,   334,  -452,    93,   334,   588,   -99,
     334,   334,   753,   174,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,   160,  -452,  -452,  -452,     7,   151,
     130,  -452,  -452,    52,    52,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,
    -452,   324,   185,   205,  -452,  -452,   200,   334,   203,  -452,
     -97,   208,   221,   231,   241,   209,  -452,  -452,  1547,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,   240,
    -452,   267,  -452,  -452,   278,  -452,  -452,  -452,  -452,  -452,
    -452,   284,  -452,  -452,  -452
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,    22,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,     0,     0,   193,     0,     0,     0,
       0,     0,   166,     0,     0,     0,     0,     0,     0,   267,
       0,     0,     0,     2,     5,    10,    47,    11,    13,    12,
      14,    15,    16,    17,    18,    19,    20,    21,     0,   236,
     237,   238,   239,   235,   234,   233,   194,   195,   196,   197,
     198,   175,     0,   228,     0,     0,   207,   240,   227,     9,
       8,     7,     0,   109,    35,     0,     0,   192,    42,     0,
      44,     0,   168,   167,     0,     0,     0,   181,   229,   232,
     231,   230,     0,   180,   185,   191,   193,   193,   193,   189,
     199,   200,   193,   193,    28,     0,   193,    48,     0,     0,
     178,     0,     0,   111,   193,    75,     0,   182,   193,   172,
      90,   173,     0,    96,     0,    29,     0,   193,     0,     0,
     115,     9,   104,     0,     0,     0,     0,    68,     0,    40,
       0,    38,     0,     0,     0,   164,   118,     0,    94,     0,
       0,   114,     0,     0,    23,     0,     0,   193,     0,   193,
     193,     0,   193,    59,     0,    61,     0,     0,   159,     0,
      77,     0,    79,     0,    81,     0,    83,     0,     0,   162,
       0,     0,     0,    46,    92,     0,     0,    31,   163,   123,
       0,   125,   165,     0,     0,     0,     0,     0,     0,     0,
     132,     0,     0,   135,    33,     0,    84,    85,     0,   193,
       0,     9,   150,     0,   169,     0,   138,   113,     0,     0,
       0,     0,     0,   268,     0,     0,     0,   269,   270,   271,
     272,   273,   276,   279,   280,   281,   282,   283,   284,   285,
     274,   277,   275,   278,   248,   244,    98,     0,   100,     0,
       1,     6,     3,     0,   176,     0,     0,     0,     0,   120,
     108,   193,     0,     0,     0,   170,   193,   142,     0,     0,
     101,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,    50,    49,   110,     0,    74,   171,   209,   209,    30,
       0,    36,    37,   103,     0,     0,     0,    66,     0,    67,
       0,     0,   117,   112,   119,   209,   116,   121,    25,    24,
       0,    52,     0,    54,     0,     0,    56,     0,    58,    60,
     158,   160,    76,    78,    80,    82,   221,     0,   219,   220,
     122,   193,     0,    91,    32,   126,     0,   124,   128,     0,
     130,   131,     0,   153,     0,     0,     0,     0,     0,   136,
     151,   137,   154,     0,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,     0,   309,   310,   313,   312,
       0,   292,   311,     0,     0,     0,     0,     0,   286,     0,
       0,     0,    97,    99,   206,   205,   201,   202,   203,   204,
       0,     0,     0,    43,    45,     0,   143,     0,   147,     0,
       0,   226,   225,     0,   223,   224,   184,   186,   190,     0,
       0,   179,   177,     0,     0,     0,     0,     0,     0,     0,
     215,     0,   214,   216,   107,     0,   246,   245,     0,    41,
      39,     0,     0,     0,     0,     0,     0,   161,     0,     0,
     145,     0,     0,   129,   152,   133,   134,    34,    86,     0,
       0,     0,     0,     0,    62,   257,   258,   259,   260,   261,
     262,   253,     0,   294,     0,   290,   288,     0,     0,     0,
       0,     0,     0,   307,   293,   295,   249,   250,   251,   296,
     252,   287,   148,   187,   149,   139,   141,   146,   102,    72,
     222,    71,    69,    73,   208,    89,    95,    70,     0,     0,
       0,   105,   106,     0,   243,    65,    93,    26,    51,    53,
      55,    57,   218,   140,   144,   127,    87,    88,   155,   157,
      63,     0,     0,     0,   291,   289,     0,     0,     0,   302,
       0,     0,     0,     0,     0,     0,   213,   212,     0,   211,
     210,   241,   242,   263,   256,   264,   265,   266,   254,     0,
     304,     0,   300,   298,     0,   303,   305,   306,   297,   308,
     217,     0,   301,   299,   255
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -452,  -452,  -452,   540,   318,  -452,  -452,  -452,  -452,  -452,
    -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,  -452,   322,
     331,    57,   -83,  -452,    64,   -13,  -452,    75,   460,     3,
      -3,  -301,    29,   262,   -14,  -137,  -452,   667,  -298,  -451,
    -452,    81,   -93,  -452,   -46,  -452,  -452,  -452,    91,  -452,
    -344,  -452,  -452,  -133,    -6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,    93,   133,    94,    95,    96,    97,    98,   358,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   207,
     253,   144,   273,   181,   182,   123,   169,   170,   152,   176,
     177,   450,   178,   451,   124,   159,   160,   274,   475,   481,
     482,   387,   388,   463,   464,   126,   153,   127,   161,   486,
     108,   488,   305,   431,   432
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     158,   158,   158,   166,   171,   168,   158,   205,   596,   166,
     158,   156,   162,   163,   487,   129,   142,   166,   158,   444,
     355,   187,   204,   554,   589,   455,   613,   558,   215,   217,
     219,   166,   222,   224,   226,   198,   130,   131,   158,   158,
     158,   158,   166,   157,   157,   157,   165,   590,   158,   614,
     476,   137,   186,   157,   129,   231,   233,   235,   237,  -188,
     196,   326,   328,   329,   252,   245,   129,   491,   145,   146,
     109,   110,   111,   112,   220,   130,   131,   113,   114,   115,
    -188,  -188,   188,   189,   254,   238,   184,   130,   131,   129,
     499,   129,   128,   129,   317,   318,   582,   128,   128,   129,
     216,   218,   209,   129,   583,   255,   227,   280,   229,   600,
     130,   131,   130,   131,   130,   131,   241,   242,   310,   312,
     130,   131,   597,   250,   130,   131,   128,   521,   256,   257,
     258,   599,   522,   109,   110,   111,   112,   314,   269,   137,
     113,   114,   115,   278,   279,   339,   116,   117,   118,   119,
     120,   129,   346,   109,   110,   111,   112,   354,   391,   392,
     113,   114,   115,   560,   143,   128,   532,  -193,   158,   533,
     158,   399,   130,   131,   128,   132,   425,   474,   137,   439,
     304,   315,   316,   317,   318,   347,   445,   348,   440,   271,
     441,   109,   110,   111,   112,   158,   129,   468,   113,   114,
     115,   468,   485,    89,   116,   117,   118,   119,   120,   560,
     130,   131,   365,   128,   492,   461,   -64,   130,   131,   601,
     602,   315,   316,   317,   318,   495,   128,   128,   496,   462,
     128,   515,   128,   526,   516,   128,   128,   128,   325,   585,
     109,   110,   111,   112,   478,   172,   246,   113,   114,   115,
     517,   518,   205,   116,   117,   118,   119,   120,   129,   519,
     520,   315,   316,   317,   318,  -181,   166,   129,   527,   530,
     139,   141,   531,   116,   117,   118,   119,   120,   559,   130,
     131,   129,   563,  -188,   564,   121,  -181,  -181,   130,   131,
     581,   128,   523,   128,   595,   200,   202,   525,   461,   479,
     608,   529,   130,   131,  -188,  -188,   534,   535,   166,   416,
     426,   427,   462,  -170,   158,   166,   560,   428,   429,   166,
     609,   598,   166,   610,   129,   457,   612,   168,   619,   389,
     158,   615,   128,   128,  -170,  -170,   166,   261,   262,   430,
     265,   480,   268,   121,   616,   130,   131,   473,   129,   128,
     314,   452,   128,   128,   617,   122,   128,   157,   459,   128,
     621,   210,   466,   212,   618,   470,   129,   426,   427,   130,
     131,   513,   423,   424,   428,   429,   437,   438,   158,   477,
     240,   116,   117,   118,   119,   120,   340,   130,   131,   501,
     622,   584,   121,   158,   586,   588,   524,   591,   592,   594,
     137,   623,   137,   624,   122,   572,   128,   128,   128,   128,
     509,   311,   121,   270,   331,   472,   469,   550,   332,   333,
     334,   157,   128,   465,   335,   336,   389,     0,   338,   493,
     471,   494,   275,  -193,  -183,   541,   344,   166,     0,     0,
     333,   603,     0,   604,     0,   483,     0,     0,  -183,   350,
       0,   142,   426,   427,   611,  -183,  -183,   356,     0,   428,
     429,   480,   605,   606,   607,   480,   116,   117,   118,   119,
     120,   116,   117,   118,   119,   120,     0,   370,     0,   372,
     543,   374,   375,     0,   377,     0,     0,   128,   193,   194,
     195,     0,   129,     0,  -193,  -193,  -193,  -193,     0,   128,
       0,  -193,  -193,  -193,   511,     0,   512,  -193,  -193,  -193,
    -193,  -193,   396,   130,   131,     0,     0,     0,   213,  -170,
       0,  -170,  -170,  -170,  -170,     0,     0,  -170,  -170,  -170,
    -170,   408,   540,     0,  -170,  -170,  -170,  -170,  -170,     0,
     413,   415,     0,     0,     0,   134,     0,   480,   138,   140,
     307,   309,     0,   137,   465,     0,     0,   164,   167,   173,
     175,   180,   183,   185,     0,   483,     0,   190,   192,   483,
       0,     0,   197,   199,   201,     0,     0,   206,   208,     0,
     211,     0,   214,     0,   166,     0,     0,   223,   225,   389,
     228,     0,   230,   232,   234,   236,     0,   239,     0,   143,
       0,   243,   244,   247,   248,   249,     0,   251,     0,     0,
     121,   137,     0,     0,     0,   260,     0,   263,   264,   266,
     267,   426,   427,   272,   276,   277,     0,   620,   428,   429,
     306,   308,   129,     0,  -193,  -193,  -193,  -193,     0,     0,
       0,  -193,  -193,  -193,     0,     0,  -193,     0,     0,   498,
     528,   483,     0,   130,   131,     0,     0,     0,  -193,   116,
     117,   118,   119,   120,     0,   319,   147,     0,   125,   148,
    -170,     0,   320,   135,   136,   149,   150,   151,   327,     0,
     109,   110,   111,   112,     0,     0,     0,   113,   114,   115,
       0,     0,   330,   116,   117,   118,   119,   120,   315,   316,
     317,   318,   203,   129,     0,   337,   426,   427,     0,   341,
       0,   342,   343,   428,   429,     0,   345,     0,   116,   117,
     118,   119,   120,     0,   130,   131,   349,     0,   351,   352,
       0,   498,     0,   353,     0,   587,   357,     0,   359,     0,
       0,   259,     0,   362,   363,     0,     0,   364,     0,     0,
     366,   137,   367,   368,     0,   369,   371,     0,   373,     0,
       0,   376,     0,     0,   378,     0,   379,   380,     0,   381,
       0,   382,     0,   383,     0,   384,     0,   385,     0,  -193,
     390,     0,     0,     0,     0,   393,   394,     0,     0,   313,
     395,     0,     0,   397,   398,   221,   400,   401,     0,   403,
       0,     0,   321,   322,     0,     0,   323,     0,   324,     0,
     409,     0,     0,   410,     0,   411,     0,     0,   412,   414,
     109,   110,   111,   112,     0,     0,     0,   113,   114,   115,
       0,     0,   121,   116,   117,   118,   119,   120,   116,   117,
     118,   119,   120,     0,   122,     0,     0,   442,     0,   443,
       0,   109,   110,   111,   112,     0,     0,     0,   113,   114,
     115,     0,     0,   453,   454,     0,     0,   360,     0,   361,
       0,   426,   427,     0,   109,   110,   111,   112,   428,   429,
     593,   113,   114,   115,     0,     0,     0,   116,   117,   118,
     119,   120,     0,     0,   129,   484,   109,   110,   111,   112,
     489,   490,   154,   113,   114,   115,     0,     0,     0,   116,
     117,   118,   119,   120,     0,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,   402,     0,   497,   404,   405,
       0,   478,   406,     0,     0,   407,     0,     0,     0,   503,
       0,     0,   504,     0,   505,   506,   507,   508,     0,     0,
     109,   110,   111,   112,     0,     0,   514,   113,   114,   115,
       0,     0,     0,   116,   117,   118,   119,   120,   109,   110,
     111,   112,   121,     0,   467,   113,   114,   115,     0,     0,
       0,     0,   446,   447,   448,   449,   479,     0,     0,     0,
     542,     0,   544,     0,     0,   545,   386,   546,   460,   547,
     548,     0,     0,   549,     0,     0,     0,     0,     0,   551,
     552,     0,     0,   553,     0,   555,   556,   557,     0,     0,
       0,   561,     0,     0,     0,   562,   121,     0,   565,     0,
       0,   566,   567,   568,   569,   570,   571,     0,   122,   573,
       0,   574,   575,     0,     0,   155,     0,     0,     0,   576,
     577,   578,   579,   580,     0,     0,   315,   316,   317,   318,
       0,     0,     0,   502,   109,   110,   111,   112,     0,     0,
       0,   113,   114,   115,     0,   510,     0,   116,   117,   118,
     119,   120,   129,     0,   109,   110,   111,   112,     0,     0,
     154,   113,   114,   115,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   130,   131,     0,     0,     0,     0,     0,
     315,   316,   317,   318,   122,   129,     0,  -193,  -193,  -193,
    -193,     0,     0,     0,  -193,  -193,  -193,     0,     0,   191,
       0,     0,   148,     0,     0,     0,   130,   131,   149,   150,
     151,     0,     0,     0,     0,   109,   110,   111,   112,     0,
     130,   131,   113,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,     0,  -174,  -174,  -174,  -174,     0,
       0,  -174,  -174,  -174,  -174,     0,   179,     0,  -174,  -174,
    -174,  -174,  -174,     0,   130,   131,     0,     0,     0,   129,
       0,   109,   110,   111,   112,     0,     0,   154,   113,   114,
     115,     0,     0,   155,   116,   117,   118,   119,   120,     0,
     130,   131,     1,     0,   315,   316,   317,   318,     2,     0,
       0,     0,     0,   155,   137,     0,     0,     3,   174,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    21,
      22,    23,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,  -174,    85,    86,    87,    88,     0,
     129,     0,   109,   110,   111,   112,     0,     0,     0,   113,
     114,   115,     0,     0,     0,   116,   117,   118,   119,   120,
     155,   130,   131,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     2,     0,    89,     0,     0,     0,
       0,     0,     0,     0,    90,    91,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,    19,    20,    21,    22,    23,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,    86,    87,    88,     0,     0,   456,     0,   109,
     110,   111,   112,     0,     0,   154,   113,   114,   115,     0,
       0,   155,   116,   117,   118,   119,   120,   500,     0,   109,
     110,   111,   112,     0,     0,   154,   113,   114,   115,     0,
       0,     0,   116,   117,   118,   119,   120,     0,     0,     0,
      90,    91,   458,     0,   109,   110,   111,   112,     0,     0,
       0,   113,   114,   115,     0,     0,     0,   116,   117,   118,
     119,   120,   109,   110,   111,   112,     0,     0,   154,   113,
     114,   115,     0,     0,     0,   116,   117,   118,   119,   120,
     109,   110,   111,   112,     0,     0,     0,   113,   114,   115,
       0,     0,     0,   116,   117,   118,   119,   120,     0,     0,
       0,     0,     0,     0,   109,   110,   111,   112,     0,     0,
       0,   113,   114,   115,   109,   110,   111,   112,     0,     0,
       0,   113,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   111,   112,     0,     0,   155,   113,
     114,   115,     0,     0,     0,     0,   109,   110,   111,   112,
       0,     0,     0,   113,   114,   115,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   155,     0,     0,     0,   281,     0,   282,   283,     0,
       0,   284,     0,   285,     0,   286,     0,     0,     0,   155,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   417,   418,   419,
     420,   421,   422,     0,     0,     0,   433,     0,     0,   434,
       0,     0,     0,     0,     0,     0,     0,     0,   435,     0,
     436,   536,   537,     0,     0,     0,     0,     0,   428,   538,
     539
};

static const yytype_int16 yycheck[] =
{
      14,    15,    16,    17,    18,    18,    20,   150,     1,    23,
      24,    14,    15,    16,   358,     1,     1,    31,    32,     1,
       1,    24,    36,   474,   123,   326,   123,   478,    42,    43,
      44,    45,    46,    47,    48,    32,    22,    23,    52,    53,
      54,    55,    56,    14,    15,    16,    17,   146,    62,   146,
     348,   120,    23,    24,     1,    52,    53,    54,    55,     1,
      31,   144,   145,   146,   150,    62,     1,   365,    11,    12,
       3,     4,     5,     6,    45,    22,    23,    10,    11,    12,
      22,    23,    25,    26,   148,    56,    22,    22,    23,     1,
     391,     1,     1,     1,   165,   166,   118,     6,     7,     1,
      43,    44,    38,     1,   126,   148,    49,    21,    51,   560,
      22,    23,    22,    23,    22,    23,    59,    60,     0,    22,
      22,    23,   115,    66,    22,    23,    35,   115,    71,    72,
      73,     1,   120,     3,     4,     5,     6,   155,    81,   120,
      10,    11,    12,    86,    87,    21,    16,    17,    18,    19,
      20,     1,    14,     3,     4,     5,     6,    15,   241,   242,
      10,    11,    12,   156,   149,    74,   120,   148,   182,   123,
     184,   148,    22,    23,    83,   161,   120,    15,   120,   120,
      89,   163,   164,   165,   166,   182,   168,   184,   120,     1,
     120,     3,     4,     5,     6,   209,     1,   334,    10,    11,
      12,   338,   148,   151,    16,    17,    18,    19,    20,   156,
      22,    23,   209,   122,   153,   148,   151,    22,    23,   563,
     564,   163,   164,   165,   166,   152,   135,   136,   152,   162,
     139,   115,   141,   146,   115,   144,   145,   146,     1,   146,
       3,     4,     5,     6,   114,   157,   154,    10,    11,    12,
     115,   115,   150,    16,    17,    18,    19,    20,     1,   115,
     115,   163,   164,   165,   166,     1,   280,     1,   120,   120,
       8,     9,   120,    16,    17,    18,    19,    20,   153,    22,
      23,     1,   121,     1,   121,   155,    22,    23,    22,    23,
     120,   200,   425,   202,   120,    33,    34,   430,   148,   169,
     115,   434,    22,    23,    22,    23,   439,   440,   322,   280,
     118,   119,   162,     1,   328,   329,   156,   125,   126,   333,
     115,   170,   336,   123,     1,   328,   123,   340,   119,   238,
     344,   123,   241,   242,    22,    23,   350,    75,    76,   147,
      78,   354,    80,   155,   123,    22,    23,   344,     1,   258,
     155,   322,   261,   262,   123,   167,   265,   328,   329,   268,
     120,    39,   333,    41,   123,   336,     1,   118,   119,    22,
      23,    24,   281,   282,   125,   126,   285,   286,   392,   350,
      58,    16,    17,    18,    19,    20,   120,    22,    23,   392,
     123,   524,   155,   407,   527,   528,   147,   530,   531,   532,
     120,   123,   120,   119,   167,   498,   315,   316,   317,   318,
     407,    93,   155,    82,   152,   340,   335,   463,   156,   157,
     158,   392,   331,   332,   162,   163,   335,    -1,   166,   372,
     339,   374,   109,   153,     1,   441,   174,   451,    -1,    -1,
     178,   117,    -1,   119,    -1,   354,    -1,    -1,    15,   187,
      -1,     1,   118,   119,   587,    22,    23,   195,    -1,   125,
     126,   474,   138,   139,   140,   478,    16,    17,    18,    19,
      20,    16,    17,    18,    19,    20,    -1,   215,    -1,   217,
     451,   219,   220,    -1,   222,    -1,    -1,   396,    28,    29,
      30,    -1,     1,    -1,     3,     4,     5,     6,    -1,   408,
      -1,    10,    11,    12,   413,    -1,   415,    16,    17,    18,
      19,    20,   250,    22,    23,    -1,    -1,    -1,   153,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,   269,   441,    -1,    16,    17,    18,    19,    20,    -1,
     278,   279,    -1,    -1,    -1,     5,    -1,   560,     8,     9,
      90,    91,    -1,   120,   463,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    -1,   474,    -1,    27,    28,   478,
      -1,    -1,    32,    33,    34,    -1,    -1,    37,    38,    -1,
      40,    -1,    42,    -1,   598,    -1,    -1,    47,    48,   498,
      50,    -1,    52,    53,    54,    55,    -1,    57,    -1,   149,
      -1,    61,    62,    63,    64,    65,    -1,    67,    -1,    -1,
     155,   120,    -1,    -1,    -1,    75,    -1,    77,    78,    79,
      80,   118,   119,    83,    84,    85,    -1,   598,   125,   126,
      90,    91,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,   155,    -1,    -1,   387,
     147,   560,    -1,    22,    23,    -1,    -1,    -1,   167,    16,
      17,    18,    19,    20,    -1,   125,     1,    -1,     1,     4,
     152,    -1,   132,     6,     7,    10,    11,    12,     1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,   152,    16,    17,    18,    19,    20,   163,   164,
     165,   166,    35,     1,    -1,   165,   118,   119,    -1,   169,
      -1,   171,   172,   125,   126,    -1,   176,    -1,    16,    17,
      18,    19,    20,    -1,    22,    23,   186,    -1,   188,   189,
      -1,   469,    -1,   193,    -1,   147,   196,    -1,   198,    -1,
      -1,    74,    -1,   203,   204,    -1,    -1,   207,    -1,    -1,
     210,   120,   212,   213,    -1,   215,   216,    -1,   218,    -1,
      -1,   221,    -1,    -1,   224,    -1,   226,   227,    -1,   229,
      -1,   231,    -1,   233,    -1,   235,    -1,   237,    -1,   148,
     240,    -1,    -1,    -1,    -1,   245,   246,    -1,    -1,   122,
     250,    -1,    -1,   253,   254,   152,   256,   257,    -1,   259,
      -1,    -1,   135,   136,    -1,    -1,   139,    -1,   141,    -1,
     270,    -1,    -1,   273,    -1,   275,    -1,    -1,   278,   279,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,   155,    16,    17,    18,    19,    20,    16,    17,
      18,    19,    20,    -1,   167,    -1,    -1,   307,    -1,   309,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,   323,   324,    -1,    -1,   200,    -1,   202,
      -1,   118,   119,    -1,     3,     4,     5,     6,   125,   126,
     127,    10,    11,    12,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    -1,    -1,     1,   355,     3,     4,     5,     6,
     360,   361,     9,    10,    11,    12,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   258,    -1,   387,   261,   262,
      -1,   114,   265,    -1,    -1,   268,    -1,    -1,    -1,   399,
      -1,    -1,   402,    -1,   404,   405,   406,   407,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,   416,    10,    11,    12,
      -1,    -1,    -1,    16,    17,    18,    19,    20,     3,     4,
       5,     6,   155,    -1,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,   315,   316,   317,   318,   169,    -1,    -1,    -1,
     450,    -1,   452,    -1,    -1,   455,   148,   457,   331,   459,
     460,    -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,   469,
     470,    -1,    -1,   473,    -1,   475,   476,   477,    -1,    -1,
      -1,   481,    -1,    -1,    -1,   485,   155,    -1,   488,    -1,
      -1,   491,   492,   493,   494,   495,   496,    -1,   167,   499,
      -1,   501,   502,    -1,    -1,   152,    -1,    -1,    -1,   509,
     510,   511,   512,   513,    -1,    -1,   163,   164,   165,   166,
      -1,    -1,    -1,   396,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,   408,    -1,    16,    17,    18,
      19,    20,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    10,    11,    12,    -1,    -1,    -1,    16,    17,    18,
      19,    20,   155,    22,    23,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,     1,
      -1,    -1,     4,    -1,    -1,    -1,    22,    23,    10,    11,
      12,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      22,    23,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    10,    11,    12,    -1,    14,    -1,    16,    17,
      18,    19,    20,    -1,    22,    23,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,    -1,    -1,   152,    16,    17,    18,    19,    20,    -1,
      22,    23,     7,    -1,   163,   164,   165,   166,    13,    -1,
      -1,    -1,    -1,   152,   120,    -1,    -1,    22,   157,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   152,   110,   111,   112,   113,    -1,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    -1,    16,    17,    18,    19,    20,
     152,    22,    23,    -1,    -1,    -1,    -1,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    13,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   111,   112,   113,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    10,    11,    12,    -1,
      -1,   152,    16,    17,    18,    19,    20,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    10,    11,    12,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    -1,    -1,    -1,
     159,   160,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    -1,    16,    17,    18,
      19,    20,     3,     4,     5,     6,    -1,    -1,     9,    10,
      11,    12,    -1,    -1,    -1,    16,    17,    18,    19,    20,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    12,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    -1,   152,    10,
      11,    12,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,   114,    -1,   116,   117,    -1,
      -1,   120,    -1,   122,    -1,   124,    -1,    -1,    -1,   152,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,   117,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
     131,   118,   119,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    13,    22,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    42,
      43,    44,    45,    46,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   110,   111,   112,   113,   151,
     159,   160,   172,   173,   175,   176,   177,   178,   179,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   221,     3,
       4,     5,     6,    10,    11,    12,    16,    17,    18,    19,
      20,   155,   167,   196,   205,   208,   216,   218,   219,     1,
      22,    23,   161,   174,   174,   208,   208,   120,   174,   204,
     174,   204,     1,   149,   192,   192,   192,     1,     4,    10,
      11,    12,   199,   217,     9,   152,   201,   203,   205,   206,
     207,   219,   201,   201,   174,   203,   205,   174,   196,   197,
     198,   205,   157,   174,   157,   174,   200,   201,   203,    14,
     174,   194,   195,   174,   195,   174,   203,   201,   192,   192,
     174,     1,   174,   199,   199,   199,   203,   174,   200,   174,
     204,   174,   204,   208,   205,   150,   174,   190,   174,   195,
     190,   174,   190,   153,   174,   205,   192,   205,   192,   205,
     203,   152,   205,   174,   205,   174,   205,   192,   174,   192,
     174,   200,   174,   200,   174,   200,   174,   200,   203,   174,
     190,   192,   192,   174,   174,   200,   154,   174,   174,   174,
     192,   174,   150,   191,   148,   148,   192,   192,   192,   208,
     174,   204,   204,   174,   174,   204,   174,   174,   204,   192,
     191,     1,   174,   193,   208,   109,   174,   174,   192,   192,
      21,   114,   116,   117,   120,   122,   124,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   219,   223,   174,   199,   174,   199,
       0,   175,    22,   208,   155,   163,   164,   165,   166,   174,
     174,   208,   208,   208,   208,     1,   193,     1,   193,   193,
     174,   204,   204,   204,   204,   204,   204,   174,   204,    21,
     120,   174,   174,   174,   204,   174,    14,   200,   200,   174,
     204,   174,   174,   174,    15,     1,   204,   174,   180,   174,
     208,   208,   174,   174,   174,   200,   174,   174,   174,   174,
     204,   174,   204,   174,   204,   204,   174,   204,   174,   174,
     174,   174,   174,   174,   174,   174,   148,   212,   213,   219,
     174,   193,   193,   174,   174,   174,   204,   174,   174,   148,
     174,   174,   208,   174,   208,   208,   208,   208,   204,   174,
     174,   174,   174,   204,   174,   204,   203,   136,   137,   138,
     139,   140,   141,   219,   219,   120,   118,   119,   125,   126,
     147,   224,   225,   117,   120,   129,   131,   219,   219,   120,
     120,   120,   174,   174,     1,   168,   208,   208,   208,   208,
     202,   204,   203,   174,   174,   202,     1,   201,     1,   203,
     208,   148,   162,   214,   215,   219,   203,     9,   206,   212,
     203,   219,   198,   200,    15,   209,   209,   203,   114,   169,
     196,   210,   211,   219,   174,   148,   220,   221,   222,   174,
     174,   209,   153,   192,   192,   152,   152,   174,   204,   202,
       1,   201,   208,   174,   174,   174,   174,   174,   174,   200,
     208,   219,   219,    24,   174,   115,   115,   115,   115,   115,
     115,   115,   120,   224,   147,   224,   146,   120,   147,   224,
     120,   120,   120,   123,   224,   224,   118,   119,   126,   127,
     219,   225,   174,   203,   174,   174,   174,   174,   174,   174,
     215,   174,   174,   174,   210,   174,   174,   174,   210,   153,
     156,   174,   174,   121,   121,   174,   174,   174,   174,   174,
     174,   174,   213,   174,   174,   174,   174,   174,   174,   174,
     174,   120,   118,   126,   224,   146,   224,   147,   224,   123,
     146,   224,   224,   127,   224,   120,     1,   115,   170,     1,
     210,   221,   221,   117,   119,   138,   139,   140,   115,   115,
     123,   224,   123,   123,   146,   123,   123,   123,   123,   119,
     203,   120,   123,   123,   119
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   171,   172,   172,   172,   173,   173,   174,   174,   174,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   177,   177,
     177,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   180,   179,   179,   179,   179,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   182,
     182,   182,   182,   182,   182,   182,   182,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   184,   184,
     184,   184,   184,   184,   184,   184,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   187,   187,
     187,   188,   188,   189,   190,   191,   191,   192,   192,   193,
     193,   194,   194,   195,   195,   196,   196,   197,   197,   198,
     199,   199,   200,   200,   201,   201,   201,   202,   202,   203,
     203,   203,   204,   204,   205,   205,   205,   205,   205,   206,
     207,   208,   208,   208,   208,   208,   208,   208,   209,   209,
     210,   210,   210,   210,   210,   211,   211,   211,   212,   212,
     213,   213,   214,   214,   215,   215,   215,   216,   216,   217,
     217,   217,   217,   218,   218,   218,   219,   219,   219,   219,
     219,   220,   220,   220,   221,   222,   222,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   224,
     224,   224,   224,   225
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     5,     3,     2,     2,
       3,     2,     3,     2,     4,     2,     3,     3,     2,     4,
       2,     4,     2,     4,     2,     4,     2,     1,     2,     3,
       3,     5,     3,     5,     3,     5,     3,     5,     3,     2,
       3,     2,     4,     5,     0,     5,     3,     3,     2,     5,
       5,     5,     5,     5,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     2,     2,     4,     5,     5,     5,
       2,     3,     2,     5,     2,     5,     2,     3,     2,     3,
       2,     3,     5,     3,     2,     5,     5,     4,     3,     2,
       3,     2,     3,     2,     2,     2,     3,     3,     2,     3,
       3,     3,     3,     2,     3,     2,     3,     5,     3,     4,
       3,     3,     2,     4,     4,     2,     3,     3,     2,     5,
       5,     5,     3,     4,     5,     4,     5,     4,     5,     5,
       2,     3,     4,     3,     3,     5,     3,     5,     3,     2,
       3,     4,     2,     2,     1,     1,     0,     1,     1,     1,
       1,     2,     1,     1,     0,     1,     2,     3,     1,     3,
       1,     1,     1,     1,     3,     1,     3,     2,     0,     1,
       3,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     1,     2,     0,
       3,     3,     3,     3,     1,     1,     1,     4,     3,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     2,     1,     1,     2,     1,     3,
       3,     3,     3,     3,     5,     7,     5,     3,     3,     3,
       3,     3,     3,     5,     5,     5,     5,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     4,
       3,     4,     2,     3,     3,     3,     3,     5,     5,     6,
       5,     6,     4,     5,     5,     5,     5,     3,     5,     1,
       1,     1,     1,     1
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
#line 196 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 2371 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 3:
#line 197 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 2377 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 4:
#line 198 "mon_parse.y" /* yacc.c:1646  */
    { new_cmd = 1; asm_mode = 0;  (yyval.i) = 0; }
#line 2383 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 9:
#line 207 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_END_CMD; }
#line 2389 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 22:
#line 222 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_BAD_CMD; }
#line 2395 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 23:
#line 226 "mon_parse.y" /* yacc.c:1646  */
    { mon_bank(e_default_space, NULL); }
#line 2401 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 24:
#line 228 "mon_parse.y" /* yacc.c:1646  */
    { mon_bank((yyvsp[-1].i), NULL); }
#line 2407 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 25:
#line 230 "mon_parse.y" /* yacc.c:1646  */
    { mon_bank(e_default_space, (yyvsp[-1].str)); }
#line 2413 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 26:
#line 232 "mon_parse.y" /* yacc.c:1646  */
    { mon_bank((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2419 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 27:
#line 234 "mon_parse.y" /* yacc.c:1646  */
    { mon_jump((yyvsp[-1].a)); }
#line 2425 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 28:
#line 236 "mon_parse.y" /* yacc.c:1646  */
    { mon_go(); }
#line 2431 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 29:
#line 238 "mon_parse.y" /* yacc.c:1646  */
    { mon_display_io_regs(0); }
#line 2437 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 30:
#line 240 "mon_parse.y" /* yacc.c:1646  */
    { mon_display_io_regs((yyvsp[-1].a)); }
#line 2443 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 31:
#line 242 "mon_parse.y" /* yacc.c:1646  */
    { monitor_cpu_type_set(""); }
#line 2449 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 32:
#line 244 "mon_parse.y" /* yacc.c:1646  */
    { monitor_cpu_type_set((yyvsp[-1].str)); }
#line 2455 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 33:
#line 246 "mon_parse.y" /* yacc.c:1646  */
    { mon_cpuhistory(-1); }
#line 2461 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 34:
#line 248 "mon_parse.y" /* yacc.c:1646  */
    { mon_cpuhistory((yyvsp[-1].i)); }
#line 2467 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 35:
#line 250 "mon_parse.y" /* yacc.c:1646  */
    { mon_instruction_return(); }
#line 2473 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 36:
#line 252 "mon_parse.y" /* yacc.c:1646  */
    { machine_write_snapshot((yyvsp[-1].str),0,0,0); /* FIXME */ }
#line 2479 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 37:
#line 254 "mon_parse.y" /* yacc.c:1646  */
    { machine_read_snapshot((yyvsp[-1].str), 0); }
#line 2485 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 38:
#line 256 "mon_parse.y" /* yacc.c:1646  */
    { mon_instructions_step(-1); }
#line 2491 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 39:
#line 258 "mon_parse.y" /* yacc.c:1646  */
    { mon_instructions_step((yyvsp[-1].i)); }
#line 2497 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 40:
#line 260 "mon_parse.y" /* yacc.c:1646  */
    { mon_instructions_next(-1); }
#line 2503 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 41:
#line 262 "mon_parse.y" /* yacc.c:1646  */
    { mon_instructions_next((yyvsp[-1].i)); }
#line 2509 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 42:
#line 264 "mon_parse.y" /* yacc.c:1646  */
    { mon_stack_up(-1); }
#line 2515 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 43:
#line 266 "mon_parse.y" /* yacc.c:1646  */
    { mon_stack_up((yyvsp[-1].i)); }
#line 2521 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 44:
#line 268 "mon_parse.y" /* yacc.c:1646  */
    { mon_stack_down(-1); }
#line 2527 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 45:
#line 270 "mon_parse.y" /* yacc.c:1646  */
    { mon_stack_down((yyvsp[-1].i)); }
#line 2533 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 46:
#line 272 "mon_parse.y" /* yacc.c:1646  */
    { mon_display_screen(); }
#line 2539 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 48:
#line 277 "mon_parse.y" /* yacc.c:1646  */
    { (monitor_cpu_for_memspace[default_memspace]->mon_register_print)(default_memspace); }
#line 2545 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 49:
#line 279 "mon_parse.y" /* yacc.c:1646  */
    { (monitor_cpu_for_memspace[(yyvsp[-1].i)]->mon_register_print)((yyvsp[-1].i)); }
#line 2551 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 51:
#line 284 "mon_parse.y" /* yacc.c:1646  */
    {
                        /* What about the memspace? */
                        mon_playback_init((yyvsp[-1].str));
                    }
#line 2560 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 52:
#line 289 "mon_parse.y" /* yacc.c:1646  */
    {
                        /* What about the memspace? */
                        mon_playback_init((yyvsp[-1].str));
                    }
#line 2569 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 53:
#line 294 "mon_parse.y" /* yacc.c:1646  */
    { mon_save_symbols((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2575 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 54:
#line 296 "mon_parse.y" /* yacc.c:1646  */
    { mon_save_symbols(e_default_space, (yyvsp[-1].str)); }
#line 2581 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 55:
#line 298 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_name_to_symbol_table((yyvsp[-3].a), (yyvsp[-1].str)); }
#line 2587 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 56:
#line 300 "mon_parse.y" /* yacc.c:1646  */
    { mon_remove_name_from_symbol_table(e_default_space, (yyvsp[-1].str)); }
#line 2593 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 57:
#line 302 "mon_parse.y" /* yacc.c:1646  */
    { mon_remove_name_from_symbol_table((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2599 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 58:
#line 304 "mon_parse.y" /* yacc.c:1646  */
    { mon_print_symbol_table((yyvsp[-1].i)); }
#line 2605 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 59:
#line 306 "mon_parse.y" /* yacc.c:1646  */
    { mon_print_symbol_table(e_default_space); }
#line 2611 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 60:
#line 308 "mon_parse.y" /* yacc.c:1646  */
    { mon_clear_symbol_table((yyvsp[-1].i)); }
#line 2617 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 61:
#line 310 "mon_parse.y" /* yacc.c:1646  */
    { mon_clear_symbol_table(e_default_space); }
#line 2623 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 62:
#line 312 "mon_parse.y" /* yacc.c:1646  */
    {
                        mon_add_name_to_symbol_table((yyvsp[-1].a), mon_prepend_dot_to_name((yyvsp[-3].str)));
                    }
#line 2631 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 63:
#line 316 "mon_parse.y" /* yacc.c:1646  */
    {
                        mon_add_name_to_symbol_table((yyvsp[-2].a), mon_prepend_dot_to_name((yyvsp[-4].str)));
                    }
#line 2639 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 64:
#line 322 "mon_parse.y" /* yacc.c:1646  */
    { mon_start_assemble_mode((yyvsp[0].a), NULL); }
#line 2645 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 65:
#line 323 "mon_parse.y" /* yacc.c:1646  */
    { }
#line 2651 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 66:
#line 325 "mon_parse.y" /* yacc.c:1646  */
    { mon_start_assemble_mode((yyvsp[-1].a), NULL); }
#line 2657 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 67:
#line 327 "mon_parse.y" /* yacc.c:1646  */
    { mon_disassemble_lines((yyvsp[-1].range)[0], (yyvsp[-1].range)[1]); }
#line 2663 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 68:
#line 329 "mon_parse.y" /* yacc.c:1646  */
    { mon_disassemble_lines(BAD_ADDR, BAD_ADDR); }
#line 2669 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 69:
#line 333 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_move((yyvsp[-3].range)[0], (yyvsp[-3].range)[1], (yyvsp[-1].a)); }
#line 2675 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 70:
#line 335 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_compare((yyvsp[-3].range)[0], (yyvsp[-3].range)[1], (yyvsp[-1].a)); }
#line 2681 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 71:
#line 337 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_fill((yyvsp[-3].range)[0], (yyvsp[-3].range)[1],(unsigned char *)(yyvsp[-1].str)); }
#line 2687 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 72:
#line 339 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_hunt((yyvsp[-3].range)[0], (yyvsp[-3].range)[1],(unsigned char *)(yyvsp[-1].str)); }
#line 2693 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 73:
#line 341 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display((yyvsp[-3].rt), (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_PETSCII); }
#line 2699 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 74:
#line 343 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(default_radix, (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_PETSCII); }
#line 2705 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 75:
#line 345 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(default_radix, BAD_ADDR, BAD_ADDR, DF_PETSCII); }
#line 2711 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 76:
#line 347 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display_data((yyvsp[-1].range)[0], (yyvsp[-1].range)[1], 8, 8); }
#line 2717 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 77:
#line 349 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display_data(BAD_ADDR, BAD_ADDR, 8, 8); }
#line 2723 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 78:
#line 351 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display_data((yyvsp[-1].range)[0], (yyvsp[-1].range)[1], 24, 21); }
#line 2729 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 79:
#line 353 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display_data(BAD_ADDR, BAD_ADDR, 24, 21); }
#line 2735 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 80:
#line 355 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(0, (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_PETSCII); }
#line 2741 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 81:
#line 357 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(0, BAD_ADDR, BAD_ADDR, DF_PETSCII); }
#line 2747 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 82:
#line 359 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(0, (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], DF_SCREEN_CODE); }
#line 2753 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 83:
#line 361 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_display(0, BAD_ADDR, BAD_ADDR, DF_SCREEN_CODE); }
#line 2759 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 84:
#line 363 "mon_parse.y" /* yacc.c:1646  */
    { mon_memmap_zap(); }
#line 2765 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 85:
#line 365 "mon_parse.y" /* yacc.c:1646  */
    { mon_memmap_show(-1,BAD_ADDR,BAD_ADDR); }
#line 2771 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 86:
#line 367 "mon_parse.y" /* yacc.c:1646  */
    { mon_memmap_show((yyvsp[-1].i),BAD_ADDR,BAD_ADDR); }
#line 2777 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 87:
#line 369 "mon_parse.y" /* yacc.c:1646  */
    { mon_memmap_show((yyvsp[-2].i),(yyvsp[-1].range)[0],(yyvsp[-1].range)[1]); }
#line 2783 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 88:
#line 371 "mon_parse.y" /* yacc.c:1646  */
    { mon_memmap_save((yyvsp[-3].str),(yyvsp[-1].i)); }
#line 2789 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 89:
#line 375 "mon_parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-3].i)) {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, (yyvsp[-3].i), FALSE);
                      } else {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, e_exec, FALSE);
                      }
                      mon_breakpoint_set_checkpoint_condition(temp, (yyvsp[-1].cond_node));
                  }
#line 2802 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 90:
#line 384 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_print_checkpoints(); }
#line 2808 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 91:
#line 387 "mon_parse.y" /* yacc.c:1646  */
    {
                      mon_breakpoint_add_checkpoint((yyvsp[-1].range)[0], (yyvsp[-1].range)[1], TRUE, e_exec, TRUE);
                  }
#line 2816 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 92:
#line 391 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_print_checkpoints(); }
#line 2822 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 93:
#line 394 "mon_parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-3].i)) {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, (yyvsp[-3].i), FALSE);
                      } else {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], TRUE, e_load | e_store, FALSE);
                      }
                      mon_breakpoint_set_checkpoint_condition(temp, (yyvsp[-1].cond_node));
                  }
#line 2835 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 94:
#line 403 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_print_checkpoints(); }
#line 2841 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 95:
#line 406 "mon_parse.y" /* yacc.c:1646  */
    {
                      if ((yyvsp[-3].i)) {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], FALSE, (yyvsp[-3].i), FALSE);
                      } else {
                          temp = mon_breakpoint_add_checkpoint((yyvsp[-2].range)[0], (yyvsp[-2].range)[1], FALSE, e_load | e_store, FALSE);
                      }
                      mon_breakpoint_set_checkpoint_condition(temp, (yyvsp[-1].cond_node));
                  }
#line 2854 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 96:
#line 415 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_print_checkpoints(); }
#line 2860 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 97:
#line 420 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_switch_checkpoint(e_ON, (yyvsp[-1].i)); }
#line 2866 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 98:
#line 422 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_switch_checkpoint(e_ON, -1); }
#line 2872 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 99:
#line 424 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_switch_checkpoint(e_OFF, (yyvsp[-1].i)); }
#line 2878 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 100:
#line 426 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_switch_checkpoint(e_OFF, -1); }
#line 2884 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 101:
#line 428 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_set_ignore_count((yyvsp[-1].i), -1); }
#line 2890 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 102:
#line 430 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_set_ignore_count((yyvsp[-3].i), (yyvsp[-1].i)); }
#line 2896 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 103:
#line 432 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_delete_checkpoint((yyvsp[-1].i)); }
#line 2902 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 104:
#line 434 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_delete_checkpoint(-1); }
#line 2908 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 105:
#line 436 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_set_checkpoint_condition((yyvsp[-3].i), (yyvsp[-1].cond_node)); }
#line 2914 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 106:
#line 438 "mon_parse.y" /* yacc.c:1646  */
    { mon_breakpoint_set_checkpoint_command((yyvsp[-3].i), (yyvsp[-1].str)); }
#line 2920 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 107:
#line 440 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_STRING; }
#line 2926 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 108:
#line 444 "mon_parse.y" /* yacc.c:1646  */
    { sidefx = (((yyvsp[-1].action) == e_TOGGLE) ? (sidefx ^ 1) : (yyvsp[-1].action)); }
#line 2932 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 109:
#line 446 "mon_parse.y" /* yacc.c:1646  */
    {
                         mon_out("I/O side effects are %s\n",
                                   sidefx ? "enabled" : "disabled");
                     }
#line 2941 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 110:
#line 451 "mon_parse.y" /* yacc.c:1646  */
    { default_radix = (yyvsp[-1].rt); }
#line 2947 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 111:
#line 453 "mon_parse.y" /* yacc.c:1646  */
    {
                         const char *p;

                         if (default_radix == e_hexadecimal)
                             p = "Hexadecimal";
                         else if (default_radix == e_decimal)
                             p = "Decimal";
                         else if (default_radix == e_octal)
                             p = "Octal";
                         else if (default_radix == e_binary)
                             p = "Binary";
                         else
                             p = "Unknown";

                         mon_out("Default radix is %s\n", p);
                     }
#line 2968 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 112:
#line 471 "mon_parse.y" /* yacc.c:1646  */
    { monitor_change_device((yyvsp[-1].i)); }
#line 2974 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 113:
#line 473 "mon_parse.y" /* yacc.c:1646  */
    { mon_export(); }
#line 2980 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 114:
#line 475 "mon_parse.y" /* yacc.c:1646  */
    { mon_quit(); YYACCEPT; }
#line 2986 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 115:
#line 477 "mon_parse.y" /* yacc.c:1646  */
    { mon_exit(); YYACCEPT; }
#line 2992 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 116:
#line 481 "mon_parse.y" /* yacc.c:1646  */
    { mon_drive_execute_disk_cmd((yyvsp[-1].str)); }
#line 2998 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 117:
#line 483 "mon_parse.y" /* yacc.c:1646  */
    { mon_out("\t%d\n",(yyvsp[-1].i)); }
#line 3004 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 118:
#line 485 "mon_parse.y" /* yacc.c:1646  */
    { mon_command_print_help(NULL); }
#line 3010 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 119:
#line 487 "mon_parse.y" /* yacc.c:1646  */
    { mon_command_print_help((yyvsp[-1].str)); }
#line 3016 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 120:
#line 489 "mon_parse.y" /* yacc.c:1646  */
    { mon_print_convert((yyvsp[-1].i)); }
#line 3022 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 121:
#line 491 "mon_parse.y" /* yacc.c:1646  */
    { mon_change_dir((yyvsp[-1].str)); }
#line 3028 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 122:
#line 493 "mon_parse.y" /* yacc.c:1646  */
    { mon_keyboard_feed((yyvsp[-1].str)); }
#line 3034 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 123:
#line 495 "mon_parse.y" /* yacc.c:1646  */
    { mon_backtrace(); }
#line 3040 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 124:
#line 497 "mon_parse.y" /* yacc.c:1646  */
    { mon_show_dir((yyvsp[-1].str)); }
#line 3046 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 125:
#line 499 "mon_parse.y" /* yacc.c:1646  */
    { mon_show_pwd(); }
#line 3052 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 126:
#line 501 "mon_parse.y" /* yacc.c:1646  */
    { mon_screenshot_save((yyvsp[-1].str),-1); }
#line 3058 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 127:
#line 503 "mon_parse.y" /* yacc.c:1646  */
    { mon_screenshot_save((yyvsp[-3].str),(yyvsp[-1].i)); }
#line 3064 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 128:
#line 505 "mon_parse.y" /* yacc.c:1646  */
    { mon_resource_get((yyvsp[-1].str)); }
#line 3070 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 129:
#line 507 "mon_parse.y" /* yacc.c:1646  */
    { mon_resource_set((yyvsp[-2].str),(yyvsp[-1].str)); }
#line 3076 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 130:
#line 509 "mon_parse.y" /* yacc.c:1646  */
    { resources_load((yyvsp[-1].str)); }
#line 3082 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 131:
#line 511 "mon_parse.y" /* yacc.c:1646  */
    { resources_save((yyvsp[-1].str)); }
#line 3088 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 132:
#line 513 "mon_parse.y" /* yacc.c:1646  */
    { mon_reset_machine(-1); }
#line 3094 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 133:
#line 515 "mon_parse.y" /* yacc.c:1646  */
    { mon_reset_machine((yyvsp[-1].i)); }
#line 3100 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 134:
#line 517 "mon_parse.y" /* yacc.c:1646  */
    { mon_tape_ctrl((yyvsp[-1].i)); }
#line 3106 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 135:
#line 519 "mon_parse.y" /* yacc.c:1646  */
    { mon_cart_freeze(); }
#line 3112 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 136:
#line 521 "mon_parse.y" /* yacc.c:1646  */
    { }
#line 3118 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 137:
#line 523 "mon_parse.y" /* yacc.c:1646  */
    { mon_stopwatch_reset(); }
#line 3124 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 138:
#line 525 "mon_parse.y" /* yacc.c:1646  */
    { mon_stopwatch_show("Stopwatch: ", "\n"); }
#line 3130 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 139:
#line 529 "mon_parse.y" /* yacc.c:1646  */
    { mon_file_load((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].a), FALSE); }
#line 3136 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 140:
#line 531 "mon_parse.y" /* yacc.c:1646  */
    { mon_file_load((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].a), TRUE); }
#line 3142 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 141:
#line 533 "mon_parse.y" /* yacc.c:1646  */
    { mon_file_save((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], FALSE); }
#line 3148 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 142:
#line 535 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_DEVICE_NUM; }
#line 3154 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 143:
#line 537 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_ADDRESS; }
#line 3160 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 144:
#line 539 "mon_parse.y" /* yacc.c:1646  */
    { mon_file_save((yyvsp[-3].str), (yyvsp[-2].i), (yyvsp[-1].range)[0], (yyvsp[-1].range)[1], TRUE); }
#line 3166 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 145:
#line 541 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_ADDRESS; }
#line 3172 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 146:
#line 543 "mon_parse.y" /* yacc.c:1646  */
    { mon_file_verify((yyvsp[-3].str),(yyvsp[-2].i),(yyvsp[-1].a)); }
#line 3178 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 147:
#line 545 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_ADDRESS; }
#line 3184 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 148:
#line 547 "mon_parse.y" /* yacc.c:1646  */
    { mon_drive_block_cmd(0,(yyvsp[-3].i),(yyvsp[-2].i),(yyvsp[-1].a)); }
#line 3190 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 149:
#line 549 "mon_parse.y" /* yacc.c:1646  */
    { mon_drive_block_cmd(1,(yyvsp[-3].i),(yyvsp[-2].i),(yyvsp[-1].a)); }
#line 3196 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 150:
#line 551 "mon_parse.y" /* yacc.c:1646  */
    { mon_drive_list(-1); }
#line 3202 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 151:
#line 553 "mon_parse.y" /* yacc.c:1646  */
    { mon_drive_list((yyvsp[-1].i)); }
#line 3208 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 152:
#line 555 "mon_parse.y" /* yacc.c:1646  */
    { mon_attach((yyvsp[-2].str),(yyvsp[-1].i)); }
#line 3214 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 153:
#line 557 "mon_parse.y" /* yacc.c:1646  */
    { mon_detach((yyvsp[-1].i)); }
#line 3220 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 154:
#line 559 "mon_parse.y" /* yacc.c:1646  */
    { mon_autostart((yyvsp[-1].str),0,1); }
#line 3226 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 155:
#line 561 "mon_parse.y" /* yacc.c:1646  */
    { mon_autostart((yyvsp[-3].str),(yyvsp[-1].i),1); }
#line 3232 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 156:
#line 563 "mon_parse.y" /* yacc.c:1646  */
    { mon_autostart((yyvsp[-1].str),0,0); }
#line 3238 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 157:
#line 565 "mon_parse.y" /* yacc.c:1646  */
    { mon_autostart((yyvsp[-3].str),(yyvsp[-1].i),0); }
#line 3244 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 158:
#line 569 "mon_parse.y" /* yacc.c:1646  */
    { mon_record_commands((yyvsp[-1].str)); }
#line 3250 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 159:
#line 571 "mon_parse.y" /* yacc.c:1646  */
    { mon_end_recording(); }
#line 3256 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 160:
#line 573 "mon_parse.y" /* yacc.c:1646  */
    { mon_playback_init((yyvsp[-1].str)); }
#line 3262 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 161:
#line 577 "mon_parse.y" /* yacc.c:1646  */
    { mon_memory_fill((yyvsp[-2].a), BAD_ADDR, (unsigned char *)(yyvsp[-1].str)); }
#line 3268 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 162:
#line 579 "mon_parse.y" /* yacc.c:1646  */
    { printf("Not yet.\n"); }
#line 3274 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 163:
#line 583 "mon_parse.y" /* yacc.c:1646  */
    { yydebug = 1; }
#line 3280 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 164:
#line 586 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3286 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 165:
#line 589 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 3292 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 166:
#line 590 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.str) = NULL; }
#line 3298 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 168:
#line 594 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_FILENAME; }
#line 3304 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 170:
#line 598 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_DEVICE_NUM; }
#line 3310 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 171:
#line 601 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i) | (yyvsp[0].i); }
#line 3316 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 172:
#line 602 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3322 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 173:
#line 605 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3328 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 174:
#line 606 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 3334 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 175:
#line 609 "mon_parse.y" /* yacc.c:1646  */
    {
                                    if (!mon_register_valid(default_memspace, (yyvsp[0].reg))) {
                                        return ERR_INVALID_REGISTER;
                                    }
                                    (yyval.i) = new_reg(default_memspace, (yyvsp[0].reg));
                                }
#line 3345 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 176:
#line 615 "mon_parse.y" /* yacc.c:1646  */
    {
                                    if (!mon_register_valid((yyvsp[-1].i), (yyvsp[0].reg))) {
                                        return ERR_INVALID_REGISTER;
                                    }
                                    (yyval.i) = new_reg((yyvsp[-1].i), (yyvsp[0].reg));
                                }
#line 3356 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 179:
#line 628 "mon_parse.y" /* yacc.c:1646  */
    { (monitor_cpu_for_memspace[reg_memspace((yyvsp[-2].i))]->mon_register_set_val)(reg_memspace((yyvsp[-2].i)), reg_regid((yyvsp[-2].i)), (WORD) (yyvsp[0].i)); }
#line 3362 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 180:
#line 631 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3368 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 181:
#line 632 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_EXPECT_CHECKNUM; }
#line 3374 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 183:
#line 636 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.range)[0] = (yyvsp[0].a); (yyval.range)[1] = BAD_ADDR; }
#line 3380 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 184:
#line 639 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.range)[0] = (yyvsp[-2].a); (yyval.range)[1] = (yyvsp[0].a); }
#line 3386 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 185:
#line 641 "mon_parse.y" /* yacc.c:1646  */
    { if (resolve_range(e_default_space, (yyval.range), (yyvsp[0].str))) return ERR_ADDR_TOO_BIG; }
#line 3392 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 186:
#line 643 "mon_parse.y" /* yacc.c:1646  */
    { if (resolve_range((yyvsp[-2].i), (yyval.range), (yyvsp[0].str))) return ERR_ADDR_TOO_BIG; }
#line 3398 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 187:
#line 646 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 3404 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 188:
#line 647 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.a) = BAD_ADDR; }
#line 3410 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 189:
#line 651 "mon_parse.y" /* yacc.c:1646  */
    {
             (yyval.a) = new_addr(e_default_space,(yyvsp[0].i));
             if (opt_asm) new_cmd = asm_mode = 1;
         }
#line 3419 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 190:
#line 656 "mon_parse.y" /* yacc.c:1646  */
    {
             (yyval.a) = new_addr((yyvsp[-2].i), (yyvsp[0].i));
             if (opt_asm) new_cmd = asm_mode = 1;
         }
#line 3428 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 191:
#line 661 "mon_parse.y" /* yacc.c:1646  */
    {
             temp = mon_symbol_table_lookup_addr(e_default_space, (yyvsp[0].str));
             if (temp >= 0)
                 (yyval.a) = new_addr(e_default_space, temp);
             else
                 return ERR_UNDEFINED_LABEL;
         }
#line 3440 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 194:
#line 674 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = e_comp_space; }
#line 3446 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 195:
#line 675 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = e_disk8_space; }
#line 3452 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 196:
#line 676 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = e_disk9_space; }
#line 3458 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 197:
#line 677 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = e_disk10_space; }
#line 3464 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 198:
#line 678 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = e_disk11_space; }
#line 3470 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 199:
#line 681 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); if (!CHECK_ADDR((yyvsp[0].i))) return ERR_ADDR_TOO_BIG; }
#line 3476 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 200:
#line 683 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3482 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 201:
#line 685 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-2].i) + (yyvsp[0].i); }
#line 3488 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 202:
#line 686 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-2].i) - (yyvsp[0].i); }
#line 3494 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 203:
#line 687 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-2].i) * (yyvsp[0].i); }
#line 3500 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 204:
#line 688 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = ((yyvsp[0].i)) ? ((yyvsp[-2].i) / (yyvsp[0].i)) : 1; }
#line 3506 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 205:
#line 689 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 3512 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 206:
#line 690 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_MISSING_CLOSE_PAREN; }
#line 3518 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 207:
#line 691 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3524 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 208:
#line 694 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = (yyvsp[0].cond_node); }
#line 3530 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 209:
#line 695 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = 0; }
#line 3536 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 210:
#line 698 "mon_parse.y" /* yacc.c:1646  */
    {
               (yyval.cond_node) = new_cond; (yyval.cond_node)->is_parenthized = FALSE;
               (yyval.cond_node)->child1 = (yyvsp[-2].cond_node); (yyval.cond_node)->child2 = (yyvsp[0].cond_node); (yyval.cond_node)->operation = (yyvsp[-1].cond_op);
           }
#line 3545 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 211:
#line 703 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_INCOMPLETE_COMPARE_OP; }
#line 3551 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 212:
#line 705 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = (yyvsp[-1].cond_node); (yyval.cond_node)->is_parenthized = TRUE; }
#line 3557 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 213:
#line 707 "mon_parse.y" /* yacc.c:1646  */
    { return ERR_MISSING_CLOSE_PAREN; }
#line 3563 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 214:
#line 709 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = (yyvsp[0].cond_node); }
#line 3569 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 215:
#line 712 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = new_cond;
                            (yyval.cond_node)->operation = e_INV;
                            (yyval.cond_node)->is_parenthized = FALSE;
                            (yyval.cond_node)->reg_num = (yyvsp[0].i); (yyval.cond_node)->is_reg = TRUE; (yyval.cond_node)->banknum=-1;
                            (yyval.cond_node)->child1 = NULL; (yyval.cond_node)->child2 = NULL;
                          }
#line 3580 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 216:
#line 718 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.cond_node) = new_cond;
                            (yyval.cond_node)->operation = e_INV;
                            (yyval.cond_node)->is_parenthized = FALSE;
                            (yyval.cond_node)->value = (yyvsp[0].i); (yyval.cond_node)->is_reg = FALSE; (yyval.cond_node)->banknum=-1;
                            (yyval.cond_node)->child1 = NULL; (yyval.cond_node)->child2 = NULL;
                          }
#line 3591 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 217:
#line 724 "mon_parse.y" /* yacc.c:1646  */
    {(yyval.cond_node)=new_cond;
                            (yyval.cond_node)->operation=e_INV;
                            (yyval.cond_node)->is_parenthized = FALSE;
                            (yyval.cond_node)->banknum=mon_banknum_from_bank(e_default_space,(yyvsp[-2].str)); (yyval.cond_node)->value = (yyvsp[0].a); (yyval.cond_node)->is_reg = FALSE;
                            (yyval.cond_node)->child1 = NULL; (yyval.cond_node)->child2 = NULL;  
                        }
#line 3602 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 220:
#line 736 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_number_to_buffer((yyvsp[0].i)); }
#line 3608 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 221:
#line 737 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_string_to_buffer((yyvsp[0].str)); }
#line 3614 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 224:
#line 744 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_number_to_buffer((yyvsp[0].i)); }
#line 3620 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 225:
#line 745 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_number_masked_to_buffer((yyvsp[0].i), 0x00); }
#line 3626 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 226:
#line 746 "mon_parse.y" /* yacc.c:1646  */
    { mon_add_string_to_buffer((yyvsp[0].str)); }
#line 3632 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 227:
#line 749 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3638 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 228:
#line 750 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (monitor_cpu_for_memspace[reg_memspace((yyvsp[0].i))]->mon_register_get_val)(reg_memspace((yyvsp[0].i)), reg_regid((yyvsp[0].i))); }
#line 3644 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 229:
#line 753 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3650 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 230:
#line 754 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = strtol((yyvsp[0].str), NULL, 10); }
#line 3656 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 231:
#line 755 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = strtol((yyvsp[0].str), NULL, 10); }
#line 3662 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 232:
#line 756 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = strtol((yyvsp[0].str), NULL, 10); }
#line 3668 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 233:
#line 759 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = resolve_datatype(B_NUMBER,(yyvsp[0].str)); }
#line 3674 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 234:
#line 760 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = resolve_datatype(O_NUMBER,(yyvsp[0].str)); }
#line 3680 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 235:
#line 761 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = resolve_datatype(D_NUMBER,(yyvsp[0].str)); }
#line 3686 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 236:
#line 764 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3692 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 237:
#line 765 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3698 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 238:
#line 766 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3704 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 239:
#line 767 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3710 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 240:
#line 768 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 3716 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 244:
#line 776 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = 0;
                                                if ((yyvsp[-1].str)) {
                                                    (monitor_cpu_for_memspace[default_memspace]->mon_assemble_instr)((yyvsp[-1].str), (yyvsp[0].mode));
                                                } else {
                                                    new_cmd = 1;
                                                    asm_mode = 0;
                                                }
                                                opt_asm = 0;
                                              }
#line 3730 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 246:
#line 787 "mon_parse.y" /* yacc.c:1646  */
    { asm_mode = 0; }
#line 3736 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 247:
#line 790 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[0].i) > 0xff) {
                          (yyval.mode).addr_mode = ASM_ADDR_MODE_IMMEDIATE_16;
                          (yyval.mode).param = (yyvsp[0].i);
                        } else {
                          (yyval.mode).addr_mode = ASM_ADDR_MODE_IMMEDIATE;
                          (yyval.mode).param = (yyvsp[0].i);
                        } }
#line 3748 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 248:
#line 797 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[0].i) >= 0x10000) {
               (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_LONG;
               (yyval.mode).param = (yyvsp[0].i);
             } else if ((yyvsp[0].i) < 0x100) {
               (yyval.mode).addr_mode = ASM_ADDR_MODE_ZERO_PAGE;
               (yyval.mode).param = (yyvsp[0].i);
             } else {
               (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE;
               (yyval.mode).param = (yyvsp[0].i);
             }
           }
#line 3764 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 249:
#line 808 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].i) >= 0x10000) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_LONG_X;
                            (yyval.mode).param = (yyvsp[-2].i);
                          } else if ((yyvsp[-2].i) < 0x100) { 
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ZERO_PAGE_X;
                            (yyval.mode).param = (yyvsp[-2].i);
                          } else {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_X;
                            (yyval.mode).param = (yyvsp[-2].i);
                          }
                        }
#line 3780 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 250:
#line 819 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].i) < 0x100) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ZERO_PAGE_Y;
                            (yyval.mode).param = (yyvsp[-2].i);
                          } else {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_Y;
                            (yyval.mode).param = (yyvsp[-2].i);
                          }
                        }
#line 3793 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 251:
#line 827 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].i) < 0x100) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_STACK_RELATIVE;
                            (yyval.mode).param = (yyvsp[-2].i);
                          } else { /* 6809 */
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
                            if ((yyvsp[-2].i) >= -16 && (yyvsp[-2].i) < 16) {
                                (yyval.mode).addr_submode = (yyvsp[0].i) | ((yyvsp[-2].i) & 0x1F);
                            } else if ((yyvsp[-2].i) >= -128 && (yyvsp[-2].i) < 128) {
                                (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_OFF8;
                                (yyval.mode).param = (yyvsp[-2].i);
                            } else if ((yyvsp[-2].i) >= -32768 && (yyvsp[-2].i) < 32768) {
                                (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_OFF16;
                                (yyval.mode).param = (yyvsp[-2].i);
                            } else {
                                (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
                                mon_out("offset too large even for 16 bits (signed)\n");
                            }
                          }
                        }
#line 3817 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 252:
#line 846 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].i) < 0x100) {
                            (yyval.mode).addr_mode = ASM_ADDR_MODE_DOUBLE;
                            (yyval.mode).param = (yyvsp[0].i);
                            (yyval.mode).addr_submode = (yyvsp[-2].i);
                          }
                        }
#line 3828 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 253:
#line 852 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].i) < 0x100) {
                               (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT;
                               (yyval.mode).param = (yyvsp[-1].i);
                             } else {
                               (yyval.mode).addr_mode = ASM_ADDR_MODE_ABS_INDIRECT;
                               (yyval.mode).param = (yyvsp[-1].i);
                             }
                           }
#line 3841 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 254:
#line 860 "mon_parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-3].i) < 0x100) {
                                           (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT_X;
                                           (yyval.mode).param = (yyvsp[-3].i);
                                         } else {
                                           (yyval.mode).addr_mode = ASM_ADDR_MODE_ABS_INDIRECT_X;
                                           (yyval.mode).param = (yyvsp[-3].i);
                                         }
                                       }
#line 3854 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 255:
#line 869 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_STACK_RELATIVE_Y; (yyval.mode).param = (yyvsp[-5].i); }
#line 3860 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 256:
#line 871 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT_Y; (yyval.mode).param = (yyvsp[-3].i); }
#line 3866 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 257:
#line 872 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_BC; }
#line 3872 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 258:
#line 873 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_DE; }
#line 3878 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 259:
#line 874 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_HL; }
#line 3884 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 260:
#line 875 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_IX; }
#line 3890 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 261:
#line 876 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_IY; }
#line 3896 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 262:
#line 877 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IND_SP; }
#line 3902 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 263:
#line 879 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_A; (yyval.mode).param = (yyvsp[-3].i); }
#line 3908 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 264:
#line 881 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_HL; (yyval.mode).param = (yyvsp[-3].i); }
#line 3914 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 265:
#line 883 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_IX; (yyval.mode).param = (yyvsp[-3].i); }
#line 3920 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 266:
#line 885 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ABSOLUTE_IY; (yyval.mode).param = (yyvsp[-3].i); }
#line 3926 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 267:
#line 886 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_IMPLIED; }
#line 3932 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 268:
#line 887 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_ACCUMULATOR; }
#line 3938 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 269:
#line 888 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_B; }
#line 3944 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 270:
#line 889 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_C; }
#line 3950 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 271:
#line 890 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_D; }
#line 3956 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 272:
#line 891 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_E; }
#line 3962 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 273:
#line 892 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_H; }
#line 3968 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 274:
#line 893 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IXH; }
#line 3974 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 275:
#line 894 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IYH; }
#line 3980 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 276:
#line 895 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_L; }
#line 3986 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 277:
#line 896 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IXL; }
#line 3992 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 278:
#line 897 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IYL; }
#line 3998 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 279:
#line 898 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_AF; }
#line 4004 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 280:
#line 899 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_BC; }
#line 4010 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 281:
#line 900 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_DE; }
#line 4016 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 282:
#line 901 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_HL; }
#line 4022 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 283:
#line 902 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IX; }
#line 4028 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 284:
#line 903 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_IY; }
#line 4034 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 285:
#line 904 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_REG_SP; }
#line 4040 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 286:
#line 906 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.mode).addr_mode = ASM_ADDR_MODE_DIRECT; (yyval.mode).param = (yyvsp[0].i); }
#line 4046 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 287:
#line 907 "mon_parse.y" /* yacc.c:1646  */
    {    /* Clash with addr,x addr,y addr,s modes! */
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        if ((yyvsp[-2].i) >= -16 && (yyvsp[-2].i) < 16) {
            (yyval.mode).addr_submode = (3 << 5) | ((yyvsp[-2].i) & 0x1F);
        } else if ((yyvsp[-2].i) >= -128 && (yyvsp[-2].i) < 128) {
            (yyval.mode).addr_submode = 0x80 | (3 << 5) | ASM_ADDR_MODE_INDEXED_OFF8;
            (yyval.mode).param = (yyvsp[-2].i);
        } else if ((yyvsp[-2].i) >= -32768 && (yyvsp[-2].i) < 32768) {
            (yyval.mode).addr_submode = 0x80 | (3 << 5) | ASM_ADDR_MODE_INDEXED_OFF16;
            (yyval.mode).param = (yyvsp[-2].i);
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4066 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 288:
#line 922 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_INC1;
        }
#line 4075 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 289:
#line 926 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_INC2;
        }
#line 4084 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 290:
#line 930 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_DEC1;
        }
#line 4093 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 291:
#line 934 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_DEC2;
        }
#line 4102 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 292:
#line 938 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[0].i) | ASM_ADDR_MODE_INDEXED_OFF0;
        }
#line 4111 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 293:
#line 942 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFFB;
        }
#line 4120 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 294:
#line 946 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFFA;
        }
#line 4129 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 295:
#line 950 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFFD;
        }
#line 4138 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 296:
#line 954 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).param = (yyvsp[-2].i);
        if ((yyvsp[-2].i) >= -128 && (yyvsp[-2].i) < 128) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC8;
        } else if ((yyvsp[-2].i) >= -32768 && (yyvsp[-2].i) < 32768) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC16;
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4155 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 297:
#line 966 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        if ((yyvsp[-3].i) >= -16 && (yyvsp[-3].i) < 16) {
            (yyval.mode).addr_submode = (yyvsp[-3].i) & 0x1F;
        } else if ((yyvsp[-4].i) >= -128 && (yyvsp[-4].i) < 128) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFF8;
            (yyval.mode).param = (yyvsp[-3].i);
        } else if ((yyvsp[-3].i) >= -32768 && (yyvsp[-3].i) < 32768) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFF16;
            (yyval.mode).param = (yyvsp[-3].i);
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4175 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 298:
#line 981 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_INC1;
        }
#line 4184 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 299:
#line 985 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-3].i) | ASM_ADDR_MODE_INDEXED_INC2;
        }
#line 4193 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 300:
#line 989 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_DEC1;
        }
#line 4202 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 301:
#line 993 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_DEC2;
        }
#line 4211 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 302:
#line 997 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-1].i) | ASM_ADDR_MODE_INDEXED_OFF0;
        }
#line 4220 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1001 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_OFFB;
        }
#line 4229 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1005 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_OFFA;
        }
#line 4238 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1009 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | (yyvsp[-2].i) | ASM_ADDR_MODE_INDEXED_OFFD;
        }
#line 4247 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1013 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).param = (yyvsp[-3].i);
        if ((yyvsp[-3].i) >= -128 && (yyvsp[-3].i) < 128) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC8_IND;
        } else if ((yyvsp[-3].i) >= -32768 && (yyvsp[-3].i) < 32768) {
            (yyval.mode).addr_submode = ASM_ADDR_MODE_INDEXED_OFFPC16_IND;
        } else {
            (yyval.mode).addr_mode = ASM_ADDR_MODE_ILLEGAL;
            mon_out("offset too large even for 16 bits (signed)\n");
        }
    }
#line 4264 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1025 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDEXED;
        (yyval.mode).addr_submode = 0x80 | ASM_ADDR_MODE_EXTENDED_INDIRECT;
        (yyval.mode).param = (yyvsp[-1].i);
        }
#line 4274 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1030 "mon_parse.y" /* yacc.c:1646  */
    {
        (yyval.mode).addr_mode = ASM_ADDR_MODE_INDIRECT_LONG_Y;
        (yyval.mode).param = (yyvsp[-3].i);
        }
#line 4283 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1038 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (0 << 5); printf("reg_x\n"); }
#line 4289 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1039 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (1 << 5); printf("reg_y\n"); }
#line 4295 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1040 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 4301 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1041 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (3 << 5); printf("reg_s\n"); }
#line 4307 "mon_parse.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1045 "mon_parse.y" /* yacc.c:1646  */
    { (yyval.i) = (2 << 5); printf("reg_u\n"); }
#line 4313 "mon_parse.c" /* yacc.c:1646  */
    break;


#line 4317 "mon_parse.c" /* yacc.c:1646  */
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
#line 1049 "mon_parse.y" /* yacc.c:1906  */


void parse_and_execute_line(char *input)
{
   char *temp_buf;
   int i, rc;

   temp_buf = lib_malloc(strlen(input) + 3);
   strcpy(temp_buf,input);
   i = (int)strlen(input);
   temp_buf[i++] = '\n';
   temp_buf[i++] = '\0';
   temp_buf[i++] = '\0';

   make_buffer(temp_buf);
   mon_clear_buffer();
   if ( (rc =yyparse()) != 0) {
       mon_out("ERROR -- ");
       switch(rc) {
         case ERR_BAD_CMD:
           mon_out("Bad command:\n");
           break;
         case ERR_RANGE_BAD_START:
           mon_out("Bad first address in range:\n");
           break;
         case ERR_RANGE_BAD_END:
           mon_out("Bad second address in range:\n");
           break;
         case ERR_EXPECT_CHECKNUM:
           mon_out("Checkpoint number expected:\n");
           break;
         case ERR_EXPECT_END_CMD:
           mon_out("Unexpected token:\n");
           break;
         case ERR_MISSING_CLOSE_PAREN:
           mon_out("')' expected:\n");
           break;
         case ERR_INCOMPLETE_COMPARE_OP:
           mon_out("Compare operation missing an operand:\n");
           break;
         case ERR_EXPECT_FILENAME:
           mon_out("Expecting a filename:\n");
           break;
         case ERR_ADDR_TOO_BIG:
           mon_out("Address too large:\n");
           break;
         case ERR_IMM_TOO_BIG:
           mon_out("Immediate argument too large:\n");
           break;
         case ERR_EXPECT_STRING:
           mon_out("Expecting a string.\n");
           break;
         case ERR_UNDEFINED_LABEL:
           mon_out("Found an undefined label.\n");
           break;
         case ERR_EXPECT_DEVICE_NUM:
           mon_out("Expecting a device number.\n");
           break;
         case ERR_EXPECT_ADDRESS:
           mon_out("Expecting an address.\n");
           break;
         case ERR_INVALID_REGISTER:
           mon_out("Invalid register.\n");
           break;
         case ERR_ILLEGAL_INPUT:
         default:
           mon_out("Wrong syntax:\n");
       }
       mon_out("  %s\n", input);
       for (i = 0; i < last_len; i++)
           mon_out(" ");
       mon_out("  ^\n");
       asm_mode = 0;
       new_cmd = 1;
   }
   lib_free(temp_buf);
   free_buffer();
}

static int yyerror(char *s)
{
   fprintf(stderr, "ERR:%s\n", s);
   return 0;
}

static int resolve_datatype(unsigned guess_type, const char *num)
{
   /* FIXME: Handle cases when default type is non-numerical */
   if (default_radix == e_hexadecimal) {
       return strtol(num, NULL, 16);
   }

   if ((guess_type == D_NUMBER) || (default_radix == e_decimal)) {
       return strtol(num, NULL, 10);
   }

   if ((guess_type == O_NUMBER) || (default_radix == e_octal)) {
       return strtol(num, NULL, 8);
   }

   return strtol(num, NULL, 2);
}

/*
 * Resolve a character sequence containing 8 hex digits like "08001000".
 * This could be a lazy version of "0800 1000". If the default radix is not
 * hexadecimal, we handle it like a ordinary number, in the latter case there
 * is only one number in the range.
 */
static int resolve_range(enum t_memspace memspace, MON_ADDR range[2],
                         const char *num)
{
    char start[5];
    char end[5];
    long sa;

    range[1] = BAD_ADDR;

    switch (default_radix)
    {
    case e_hexadecimal:
        /* checked twice, but as the code must have exactly 8 digits: */
        if (strlen(num) == 8) {
            memcpy(start, num, 4);
            start[4] = '\0';
            memcpy(end, num + 4, 4);
            end[4] = '\0';
            sa = strtol(start, NULL, 16);
            range[1] = new_addr(memspace, strtol(end, NULL, 16));
        }
        else
            sa = strtol(num, NULL, 16);
        break;

    case e_decimal:
       sa = strtol(num, NULL, 10);
       break;

    case e_octal:
       sa = strtol(num, NULL, 8);
       break;

    default:
       sa = strtol(num, NULL, 2);
    }

    if (!CHECK_ADDR(sa))
        return ERR_ADDR_TOO_BIG;

    range[0] = new_addr(memspace, sa);
    return 0;
}


