// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hh"

// User implementation prologue.

#line 51 "parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 20 "parser.yy" // lalr1.cc:413

#include "driver.h"
#include <iostream>
#include "methods.cpp"

#line 59 "parser.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.yy" // lalr1.cc:479
namespace yy {
#line 145 "parser.tab.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  analizer_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  analizer_parser::analizer_parser (analizer_driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  analizer_parser::~analizer_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  analizer_parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  analizer_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  analizer_parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  analizer_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  analizer_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  analizer_parser::symbol_number_type
  analizer_parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  analizer_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  analizer_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 20: // unitl
      case 23: // typep
        value.move< char > (that.value);
        break;

      case 3: // size
      case 4: // fit
      case 5: // unit
      case 6: // path
      case 7: // mkdisk
      case 8: // rmdisk
      case 9: // mount
      case 10: // unmount
      case 11: // id
      case 12: // fdisk
      case 13: // deleter
      case 14: // add
      case 15: // rep
      case 16: // name
      case 17: // exec
      case 18: // typer
      case 19: // pather
      case 21: // assign
      case 22: // adj
      case 24: // idvda
      case 25: // tpdelete
      case 26: // minus
      case 27: // npart
      case 28: // fs
      case 29: // mkfs
      case 30: // usr
      case 31: // pwd
      case 32: // mkgrp
      case 33: // grp
      case 34: // typartition
      case 35: // login
      case 36: // logout
      case 37: // rmgrp
      case 38: // mkusr
      case 39: // rmusr
      case 40: // chmod
      case 41: // recursive
      case 42: // ugo
      case 43: // mkFile
      case 44: // parametro
      case 45: // cont
      case 46: // cat
      case 47: // file
      case 48: // mkdir
      case 49: // loss
      case 50: // pause
      case 51: // rem
      case 52: // mv
      case 53: // dest
      case 54: // recovery
      case 55: // edit
      case 56: // ren
      case 57: // cp
      case 58: // find
      case 59: // chown
      case 60: // chgrp
      case 61: // ruta
      case 63: // INICIO
      case 64: // ADMINIST
      case 65: // MKPARM
      case 66: // FDISK
      case 67: // SIMBOL
      case 68: // DMOUNT
      case 69: // DREP
      case 70: // MKFS
      case 71: // LOGIN
      case 72: // MKUSR
      case 73: // CHMOD
      case 74: // MKFILE
      case 75: // MKDIR
      case 76: // MV
      case 77: // EDIT
      case 78: // REN
      case 79: // CHOWN
      case 80: // CHGRP
        value.move< string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  analizer_parser::stack_symbol_type&
  analizer_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 20: // unitl
      case 23: // typep
        value.copy< char > (that.value);
        break;

      case 3: // size
      case 4: // fit
      case 5: // unit
      case 6: // path
      case 7: // mkdisk
      case 8: // rmdisk
      case 9: // mount
      case 10: // unmount
      case 11: // id
      case 12: // fdisk
      case 13: // deleter
      case 14: // add
      case 15: // rep
      case 16: // name
      case 17: // exec
      case 18: // typer
      case 19: // pather
      case 21: // assign
      case 22: // adj
      case 24: // idvda
      case 25: // tpdelete
      case 26: // minus
      case 27: // npart
      case 28: // fs
      case 29: // mkfs
      case 30: // usr
      case 31: // pwd
      case 32: // mkgrp
      case 33: // grp
      case 34: // typartition
      case 35: // login
      case 36: // logout
      case 37: // rmgrp
      case 38: // mkusr
      case 39: // rmusr
      case 40: // chmod
      case 41: // recursive
      case 42: // ugo
      case 43: // mkFile
      case 44: // parametro
      case 45: // cont
      case 46: // cat
      case 47: // file
      case 48: // mkdir
      case 49: // loss
      case 50: // pause
      case 51: // rem
      case 52: // mv
      case 53: // dest
      case 54: // recovery
      case 55: // edit
      case 56: // ren
      case 57: // cp
      case 58: // find
      case 59: // chown
      case 60: // chgrp
      case 61: // ruta
      case 63: // INICIO
      case 64: // ADMINIST
      case 65: // MKPARM
      case 66: // FDISK
      case 67: // SIMBOL
      case 68: // DMOUNT
      case 69: // DREP
      case 70: // MKFS
      case 71: // LOGIN
      case 72: // MKUSR
      case 73: // CHMOD
      case 74: // MKFILE
      case 75: // MKDIR
      case 76: // MV
      case 77: // EDIT
      case 78: // REN
      case 79: // CHOWN
      case 80: // CHGRP
        value.copy< string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  analizer_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  analizer_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 3: // size

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 478 "parser.tab.cc" // lalr1.cc:636
        break;

      case 4: // fit

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 485 "parser.tab.cc" // lalr1.cc:636
        break;

      case 5: // unit

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 492 "parser.tab.cc" // lalr1.cc:636
        break;

      case 6: // path

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 499 "parser.tab.cc" // lalr1.cc:636
        break;

      case 7: // mkdisk

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 506 "parser.tab.cc" // lalr1.cc:636
        break;

      case 8: // rmdisk

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 513 "parser.tab.cc" // lalr1.cc:636
        break;

      case 9: // mount

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 520 "parser.tab.cc" // lalr1.cc:636
        break;

      case 10: // unmount

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 527 "parser.tab.cc" // lalr1.cc:636
        break;

      case 11: // id

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 534 "parser.tab.cc" // lalr1.cc:636
        break;

      case 12: // fdisk

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 541 "parser.tab.cc" // lalr1.cc:636
        break;

      case 13: // deleter

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 548 "parser.tab.cc" // lalr1.cc:636
        break;

      case 14: // add

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 555 "parser.tab.cc" // lalr1.cc:636
        break;

      case 15: // rep

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 562 "parser.tab.cc" // lalr1.cc:636
        break;

      case 16: // name

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 569 "parser.tab.cc" // lalr1.cc:636
        break;

      case 17: // exec

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 576 "parser.tab.cc" // lalr1.cc:636
        break;

      case 18: // typer

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 583 "parser.tab.cc" // lalr1.cc:636
        break;

      case 19: // pather

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 590 "parser.tab.cc" // lalr1.cc:636
        break;

      case 20: // unitl

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< char > (); }
#line 597 "parser.tab.cc" // lalr1.cc:636
        break;

      case 21: // assign

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 604 "parser.tab.cc" // lalr1.cc:636
        break;

      case 22: // adj

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 611 "parser.tab.cc" // lalr1.cc:636
        break;

      case 23: // typep

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< char > (); }
#line 618 "parser.tab.cc" // lalr1.cc:636
        break;

      case 24: // idvda

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 625 "parser.tab.cc" // lalr1.cc:636
        break;

      case 25: // tpdelete

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 632 "parser.tab.cc" // lalr1.cc:636
        break;

      case 26: // minus

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 639 "parser.tab.cc" // lalr1.cc:636
        break;

      case 27: // npart

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 646 "parser.tab.cc" // lalr1.cc:636
        break;

      case 28: // fs

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 653 "parser.tab.cc" // lalr1.cc:636
        break;

      case 29: // mkfs

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 660 "parser.tab.cc" // lalr1.cc:636
        break;

      case 30: // usr

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 667 "parser.tab.cc" // lalr1.cc:636
        break;

      case 31: // pwd

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 674 "parser.tab.cc" // lalr1.cc:636
        break;

      case 32: // mkgrp

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 681 "parser.tab.cc" // lalr1.cc:636
        break;

      case 33: // grp

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 688 "parser.tab.cc" // lalr1.cc:636
        break;

      case 34: // typartition

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 695 "parser.tab.cc" // lalr1.cc:636
        break;

      case 35: // login

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 702 "parser.tab.cc" // lalr1.cc:636
        break;

      case 36: // logout

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 709 "parser.tab.cc" // lalr1.cc:636
        break;

      case 37: // rmgrp

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 716 "parser.tab.cc" // lalr1.cc:636
        break;

      case 38: // mkusr

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 723 "parser.tab.cc" // lalr1.cc:636
        break;

      case 39: // rmusr

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 730 "parser.tab.cc" // lalr1.cc:636
        break;

      case 40: // chmod

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 737 "parser.tab.cc" // lalr1.cc:636
        break;

      case 41: // recursive

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 744 "parser.tab.cc" // lalr1.cc:636
        break;

      case 42: // ugo

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 751 "parser.tab.cc" // lalr1.cc:636
        break;

      case 43: // mkFile

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 758 "parser.tab.cc" // lalr1.cc:636
        break;

      case 44: // parametro

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 765 "parser.tab.cc" // lalr1.cc:636
        break;

      case 45: // cont

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 772 "parser.tab.cc" // lalr1.cc:636
        break;

      case 46: // cat

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 779 "parser.tab.cc" // lalr1.cc:636
        break;

      case 47: // file

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 786 "parser.tab.cc" // lalr1.cc:636
        break;

      case 48: // mkdir

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 793 "parser.tab.cc" // lalr1.cc:636
        break;

      case 49: // loss

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 800 "parser.tab.cc" // lalr1.cc:636
        break;

      case 50: // pause

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 807 "parser.tab.cc" // lalr1.cc:636
        break;

      case 51: // rem

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 814 "parser.tab.cc" // lalr1.cc:636
        break;

      case 52: // mv

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 821 "parser.tab.cc" // lalr1.cc:636
        break;

      case 53: // dest

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 828 "parser.tab.cc" // lalr1.cc:636
        break;

      case 54: // recovery

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 835 "parser.tab.cc" // lalr1.cc:636
        break;

      case 55: // edit

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 842 "parser.tab.cc" // lalr1.cc:636
        break;

      case 56: // ren

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 849 "parser.tab.cc" // lalr1.cc:636
        break;

      case 57: // cp

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 856 "parser.tab.cc" // lalr1.cc:636
        break;

      case 58: // find

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 863 "parser.tab.cc" // lalr1.cc:636
        break;

      case 59: // chown

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 870 "parser.tab.cc" // lalr1.cc:636
        break;

      case 60: // chgrp

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 877 "parser.tab.cc" // lalr1.cc:636
        break;

      case 61: // ruta

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 884 "parser.tab.cc" // lalr1.cc:636
        break;

      case 63: // INICIO

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 891 "parser.tab.cc" // lalr1.cc:636
        break;

      case 64: // ADMINIST

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 898 "parser.tab.cc" // lalr1.cc:636
        break;

      case 65: // MKPARM

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 905 "parser.tab.cc" // lalr1.cc:636
        break;

      case 66: // FDISK

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 912 "parser.tab.cc" // lalr1.cc:636
        break;

      case 67: // SIMBOL

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 919 "parser.tab.cc" // lalr1.cc:636
        break;

      case 68: // DMOUNT

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 926 "parser.tab.cc" // lalr1.cc:636
        break;

      case 69: // DREP

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 933 "parser.tab.cc" // lalr1.cc:636
        break;

      case 70: // MKFS

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 940 "parser.tab.cc" // lalr1.cc:636
        break;

      case 71: // LOGIN

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 947 "parser.tab.cc" // lalr1.cc:636
        break;

      case 72: // MKUSR

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 954 "parser.tab.cc" // lalr1.cc:636
        break;

      case 73: // CHMOD

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 961 "parser.tab.cc" // lalr1.cc:636
        break;

      case 74: // MKFILE

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 968 "parser.tab.cc" // lalr1.cc:636
        break;

      case 75: // MKDIR

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 975 "parser.tab.cc" // lalr1.cc:636
        break;

      case 76: // MV

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 982 "parser.tab.cc" // lalr1.cc:636
        break;

      case 77: // EDIT

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 989 "parser.tab.cc" // lalr1.cc:636
        break;

      case 78: // REN

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 996 "parser.tab.cc" // lalr1.cc:636
        break;

      case 79: // CHOWN

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 1003 "parser.tab.cc" // lalr1.cc:636
        break;

      case 80: // CHGRP

#line 114 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 1010 "parser.tab.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  analizer_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  analizer_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  analizer_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  analizer_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  analizer_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  analizer_parser::debug_level_type
  analizer_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  analizer_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline analizer_parser::state_type
  analizer_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  analizer_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  analizer_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  analizer_parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 20: // unitl
      case 23: // typep
        yylhs.value.build< char > ();
        break;

      case 3: // size
      case 4: // fit
      case 5: // unit
      case 6: // path
      case 7: // mkdisk
      case 8: // rmdisk
      case 9: // mount
      case 10: // unmount
      case 11: // id
      case 12: // fdisk
      case 13: // deleter
      case 14: // add
      case 15: // rep
      case 16: // name
      case 17: // exec
      case 18: // typer
      case 19: // pather
      case 21: // assign
      case 22: // adj
      case 24: // idvda
      case 25: // tpdelete
      case 26: // minus
      case 27: // npart
      case 28: // fs
      case 29: // mkfs
      case 30: // usr
      case 31: // pwd
      case 32: // mkgrp
      case 33: // grp
      case 34: // typartition
      case 35: // login
      case 36: // logout
      case 37: // rmgrp
      case 38: // mkusr
      case 39: // rmusr
      case 40: // chmod
      case 41: // recursive
      case 42: // ugo
      case 43: // mkFile
      case 44: // parametro
      case 45: // cont
      case 46: // cat
      case 47: // file
      case 48: // mkdir
      case 49: // loss
      case 50: // pause
      case 51: // rem
      case 52: // mv
      case 53: // dest
      case 54: // recovery
      case 55: // edit
      case 56: // ren
      case 57: // cp
      case 58: // find
      case 59: // chown
      case 60: // chgrp
      case 61: // ruta
      case 63: // INICIO
      case 64: // ADMINIST
      case 65: // MKPARM
      case 66: // FDISK
      case 67: // SIMBOL
      case 68: // DMOUNT
      case 69: // DREP
      case 70: // MKFS
      case 71: // LOGIN
      case 72: // MKUSR
      case 73: // CHMOD
      case 74: // MKFILE
      case 75: // MKDIR
      case 76: // MV
      case 77: // EDIT
      case 78: // REN
      case 79: // CHOWN
      case 80: // CHGRP
        yylhs.value.build< string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 118 "parser.yy" // lalr1.cc:859
    {}
#line 1313 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 120 "parser.yy" // lalr1.cc:859
    { mkdisk();}
#line 1319 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 121 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path); rmdisk();}
#line 1325 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 122 "parser.yy" // lalr1.cc:859
    { fdisk();}
#line 1331 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 123 "parser.yy" // lalr1.cc:859
    { mount();}
#line 1337 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 124 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > (); unmount();}
#line 1343 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 125 "parser.yy" // lalr1.cc:859
    { rep();}
#line 1349 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 126 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path); exec = true;}
#line 1355 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 127 "parser.yy" // lalr1.cc:859
    { mkfs();}
#line 1361 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 128 "parser.yy" // lalr1.cc:859
    { login();}
#line 1367 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 129 "parser.yy" // lalr1.cc:859
    { logout();}
#line 1373 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 130 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name); mkgrp();}
#line 1379 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 131 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name); rmgrp();}
#line 1385 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 132 "parser.yy" // lalr1.cc:859
    { mkusr();}
#line 1391 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 133 "parser.yy" // lalr1.cc:859
    { usr = yystack_[0].value.as< string > (); verificar_comillas(usr); rmusr(); }
#line 1397 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 134 "parser.yy" // lalr1.cc:859
    { mkfile();}
#line 1403 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 135 "parser.yy" // lalr1.cc:859
    { file = yystack_[0].value.as< string > (); verificar_comillas(file); cat();}
#line 1409 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 136 "parser.yy" // lalr1.cc:859
    { mkdir();}
#line 1415 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 137 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > (); loss();}
#line 1421 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 138 "parser.yy" // lalr1.cc:859
    { pause();}
#line 1427 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 139 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path); remover();}
#line 1433 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 140 "parser.yy" // lalr1.cc:859
    { mover();}
#line 1439 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 141 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > (); recovery();}
#line 1445 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 142 "parser.yy" // lalr1.cc:859
    { ren(); }
#line 1451 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 143 "parser.yy" // lalr1.cc:859
    { find(); }
#line 1457 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 144 "parser.yy" // lalr1.cc:859
    { printf("\nNo hay metodo definido\n\n"); }
#line 1463 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 145 "parser.yy" // lalr1.cc:859
    { printf("\nNo hay metodo definido\n\n"); }
#line 1469 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 146 "parser.yy" // lalr1.cc:859
    { printf("\nNo hay metodo definido\n\n"); }
#line 1475 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 147 "parser.yy" // lalr1.cc:859
    { printf("\nNo hay metodo definido\n\n"); }
#line 1481 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 148 "parser.yy" // lalr1.cc:859
    { printf("\nNo hay metodo definido\n\n"); }
#line 1487 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 150 "parser.yy" // lalr1.cc:859
    { size = verificate_string(yystack_[0].value.as< string > ()); /* size = $3; */ }
#line 1493 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 151 "parser.yy" // lalr1.cc:859
    { fit = yystack_[0].value.as< string > ();}
#line 1499 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 152 "parser.yy" // lalr1.cc:859
    { unit = yystack_[0].value.as< char > ();}
#line 1505 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 153 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1511 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 154 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< string > () = "empty";}
#line 1517 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 157 "parser.yy" // lalr1.cc:859
    { type = yystack_[0].value.as< char > ();}
#line 1523 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 158 "parser.yy" // lalr1.cc:859
    { tdelete = yystack_[0].value.as< string > ();  }
#line 1529 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 159 "parser.yy" // lalr1.cc:859
    { add = verificate_string(yystack_[0].value.as< string > ());/* add = $4; */ }
#line 1535 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 160 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name);}
#line 1541 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 163 "parser.yy" // lalr1.cc:859
    { sign = "menos";}
#line 1547 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 164 "parser.yy" // lalr1.cc:859
    { sign = "mas";}
#line 1553 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 166 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1559 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 167 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name);}
#line 1565 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 169 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1571 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 170 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name);}
#line 1577 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 171 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > ();}
#line 1583 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 172 "parser.yy" // lalr1.cc:859
    { ruta = yystack_[0].value.as< string > (); verificar_comillas(ruta);}
#line 1589 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 173 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< string > () = "empty";}
#line 1595 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 175 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > ();}
#line 1601 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 176 "parser.yy" // lalr1.cc:859
    { tdelete = yystack_[0].value.as< string > ();}
#line 1607 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 177 "parser.yy" // lalr1.cc:859
    { set_fs_char(yystack_[0].value.as< string > ());}
#line 1613 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 178 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< string > () = "empty";}
#line 1619 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 180 "parser.yy" // lalr1.cc:859
    { usr = yystack_[0].value.as< string > (); verificar_comillas(usr);}
#line 1625 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 181 "parser.yy" // lalr1.cc:859
    { pwd = yystack_[0].value.as< string > (); verificar_comillas(pwd);}
#line 1631 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 182 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > ();}
#line 1637 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 184 "parser.yy" // lalr1.cc:859
    { usr = yystack_[0].value.as< string > (); verificar_comillas(usr);}
#line 1643 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 185 "parser.yy" // lalr1.cc:859
    { pwd = yystack_[0].value.as< string > (); verificar_comillas(pwd);}
#line 1649 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 186 "parser.yy" // lalr1.cc:859
    { grp = yystack_[0].value.as< string > (); verificar_comillas(grp);}
#line 1655 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 188 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1661 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 189 "parser.yy" // lalr1.cc:859
    {}
#line 1667 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 190 "parser.yy" // lalr1.cc:859
    {}
#line 1673 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 191 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< string > () = "empty";}
#line 1679 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 193 "parser.yy" // lalr1.cc:859
    { size = verificate_string(yystack_[0].value.as< string > ()); /* size = $3; */ }
#line 1685 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 194 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1691 "parser.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 195 "parser.yy" // lalr1.cc:859
    { atribp = 's';}
#line 1697 "parser.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 196 "parser.yy" // lalr1.cc:859
    { cont = yystack_[0].value.as< string > (); verificar_comillas(cont);}
#line 1703 "parser.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 197 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< string > () = "empty";}
#line 1709 "parser.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 199 "parser.yy" // lalr1.cc:859
    { atribp = 's';}
#line 1715 "parser.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 200 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > ();}
#line 1721 "parser.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 201 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1727 "parser.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 202 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< string > () = "empty";}
#line 1733 "parser.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 204 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1739 "parser.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 205 "parser.yy" // lalr1.cc:859
    { dest = yystack_[0].value.as< string > (); verificar_comillas(dest);}
#line 1745 "parser.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 208 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1751 "parser.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 209 "parser.yy" // lalr1.cc:859
    { cont = yystack_[0].value.as< string > (); verificar_comillas(cont);}
#line 1757 "parser.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 211 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1763 "parser.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 212 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name);}
#line 1769 "parser.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 214 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1775 "parser.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 216 "parser.yy" // lalr1.cc:859
    { usr = yystack_[0].value.as< string > (); verificar_comillas(usr);}
#line 1781 "parser.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 218 "parser.yy" // lalr1.cc:859
    { usr = yystack_[0].value.as< string > (); verificar_comillas(usr);}
#line 1787 "parser.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 219 "parser.yy" // lalr1.cc:859
    { grp = yystack_[0].value.as< string > (); verificar_comillas(grp);}
#line 1793 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1797 "parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  analizer_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  analizer_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char analizer_parser::yypact_ninf_ = -85;

  const signed char analizer_parser::yytable_ninf_ = -1;

  const short int
  analizer_parser::yypact_[] =
  {
      78,    38,    21,    18,    22,   139,     4,    26,    12,    29,
       8,   -85,    33,    -2,     7,     5,    15,    10,    11,    40,
     -85,    46,     1,    47,     3,    19,     1,    19,    20,    23,
      62,   -85,    42,    43,    45,    48,    38,    49,    50,    68,
      18,    70,    71,    73,    75,    76,   -85,   139,    77,    79,
      80,    81,     4,    82,    83,    84,    85,    12,    87,    90,
      91,    98,     8,    99,   101,   102,   104,    -2,   110,   125,
     -85,   126,     5,   127,   128,   -85,   129,    15,   130,   133,
     135,   -85,    11,   137,   138,   140,   141,     1,   142,   143,
     144,     3,   145,   146,    19,     1,    19,   147,   148,   -85,
      20,   149,   150,    23,   -85,    41,   151,   152,   155,    38,
     156,   158,    72,   -85,   136,   153,   154,   157,    44,   139,
     160,   159,   162,   163,     4,   166,   169,   161,   164,    12,
     167,   171,   170,   172,     8,   173,   174,   175,   176,    -2,
     177,   168,   178,     5,   179,   188,   189,    15,   190,   191,
     187,    11,   192,   193,   194,   195,   -85,   196,   198,   197,
     -85,   199,   200,   -85,   -85,   -85,   202,   201,    20,   203,
     204,   -85,   -85,   -85,   -85,   -85,    38,   -85,   -85,   -85,
     -85,   -85,   -85,   205,   -85,   -85,   139,   -85,   -85,   -85,
     -85,     4,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,    15,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   139,   -85,   -85,   139,   139,
     -85
  };

  const unsigned char
  analizer_parser::yydefact_[] =
  {
       0,    36,     0,     0,     0,    36,    50,     0,    54,     0,
       0,    12,     0,     0,     0,    64,    69,     0,    73,     0,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    36,     0,     0,
       0,     0,    50,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,    64,     0,     0,    67,     0,    69,     0,     0,
       0,    70,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     1,     0,     0,     0,     0,    36,
       0,     0,     0,     6,     0,     0,    43,     0,     0,    36,
       0,     0,     0,     0,    50,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,     0,     0,     0,    69,     0,     0,
       0,    73,     0,     0,     0,     0,    23,     0,     0,     0,
      27,     0,     0,    25,    28,    26,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,     4,    44,    45,
       7,    39,    42,     0,    41,    38,    36,    46,    48,    47,
      49,    50,     9,    51,    52,    53,    10,    13,    57,    55,
      56,    11,    14,    58,    59,    60,    15,    16,    61,    62,
      29,    65,    66,    68,    69,    18,    72,    71,    19,    20,
      22,    74,    75,    24,    76,    77,    78,    79,    80,    82,
      30,    83,    84,     3,    40,    36,     8,    17,    36,    36,
       5
  };

  const short int
  analizer_parser::yypgoto_[] =
  {
     -85,   -85,   -85,     0,   -47,   -85,   182,   -50,   -53,   -57,
     -61,   -64,   -74,   -70,   -12,   105,   -14,   -84,   112
  };

  const short int
  analizer_parser::yydefgoto_[] =
  {
      -1,    30,    31,    46,    47,   183,    40,    52,    57,    62,
      67,    72,    77,    82,    87,    91,    94,   100,   103
  };

  const unsigned char
  analizer_parser::yytable_[] =
  {
     119,    36,   124,   147,   129,   134,   139,    85,   143,    89,
      48,    69,   151,    96,    95,    49,   168,    79,    73,    59,
      50,    74,    80,    54,    38,    92,    97,    37,    64,    65,
      55,    66,    53,    41,    39,    93,   109,    68,    60,    61,
      56,    32,    33,    34,    35,    58,    70,    71,    90,    63,
      98,    83,    84,   101,    86,    81,   102,    78,    88,    75,
      76,    99,   104,   105,   106,    51,   107,   185,   172,   108,
     110,   111,   186,   214,   191,   156,   196,   201,   206,   210,
     163,   218,   165,   164,   230,     1,     2,     3,     4,   112,
       5,   114,   115,     6,   116,     7,   117,   118,   120,   179,
     121,   122,   123,   125,   126,   127,   128,     8,   130,   176,
       9,   131,   132,    10,    11,    12,    13,    14,    15,   133,
     135,    16,   136,   137,    17,   138,    18,    19,    20,    21,
      22,   140,    23,    24,    25,    26,    27,    28,    29,   235,
     237,   236,    32,    33,    34,    35,   141,   142,   144,   145,
     146,   148,    42,    43,   149,    44,   150,    45,   152,   153,
     180,   154,   155,   157,   158,   159,   161,   162,   166,   167,
     169,   170,   174,   173,   175,   177,   233,   178,   181,   187,
     182,     0,   190,   188,   184,   192,   194,   208,   238,   189,
       0,   239,   240,   193,   197,   198,   160,   199,   195,   200,
     202,   203,   204,   205,   207,   209,   211,   212,   213,   215,
     216,   217,   220,   221,   222,   171,   219,   224,   226,     0,
     223,   228,   113,     0,   225,     0,     0,   227,   229,     0,
     231,   232,   234
  };

  const short int
  analizer_parser::yycheck_[] =
  {
      47,     1,    52,    77,    57,    62,    67,     6,    72,     6,
       6,     6,    82,    27,    26,    11,   100,     6,     3,    11,
      16,     6,    11,    11,     6,     6,     6,     6,    30,    31,
      18,    33,     6,    11,    16,    16,    36,    30,    30,    31,
      28,     3,     4,     5,     6,    16,    41,    42,    45,    16,
      30,    11,     6,    30,    53,    44,    33,    47,    11,    44,
      45,    41,     0,    21,    21,    61,    21,    23,    27,    21,
      21,    21,   119,   147,   124,    87,   129,   134,   139,   143,
      94,   151,    96,    95,   168,     7,     8,     9,    10,    21,
      12,    21,    21,    15,    21,    17,    21,    21,    21,    27,
      21,    21,    21,    21,    21,    21,    21,    29,    21,   109,
      32,    21,    21,    35,    36,    37,    38,    39,    40,    21,
      21,    43,    21,    21,    46,    21,    48,    49,    50,    51,
      52,    21,    54,    55,    56,    57,    58,    59,    60,   186,
     214,   191,     3,     4,     5,     6,    21,    21,    21,    21,
      21,    21,    13,    14,    21,    16,    21,    18,    21,    21,
      24,    21,    21,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    20,    22,    19,    19,   176,    19,    25,    19,
      26,    -1,    19,    24,    27,    19,    25,    19,   235,    27,
      -1,   238,   239,    24,    27,    24,    91,    27,    34,    27,
      27,    27,    27,    27,    27,    27,    27,    19,    19,    19,
      19,    24,    19,    19,    19,   103,    24,    19,    19,    -1,
      24,    19,    40,    -1,    27,    -1,    -1,    27,    27,    -1,
      27,    27,    27
  };

  const unsigned char
  analizer_parser::yystos_[] =
  {
       0,     7,     8,     9,    10,    12,    15,    17,    29,    32,
      35,    36,    37,    38,    39,    40,    43,    46,    48,    49,
      50,    51,    52,    54,    55,    56,    57,    58,    59,    60,
      63,    64,     3,     4,     5,     6,    65,     6,     6,    16,
      68,    11,    13,    14,    16,    18,    65,    66,     6,    11,
      16,    61,    69,     6,    11,    18,    28,    70,    16,    11,
      30,    31,    71,    16,    30,    31,    33,    72,    30,     6,
      41,    42,    73,     3,     6,    44,    45,    74,    47,     6,
      11,    44,    75,    11,     6,     6,    53,    76,    11,     6,
      45,    77,     6,    16,    78,    76,    78,     6,    30,    41,
      79,    30,    33,    80,     0,    21,    21,    21,    21,    65,
      21,    21,    21,    68,    21,    21,    21,    21,    21,    66,
      21,    21,    21,    21,    69,    21,    21,    21,    21,    70,
      21,    21,    21,    21,    71,    21,    21,    21,    21,    72,
      21,    21,    21,    73,    21,    21,    21,    74,    21,    21,
      21,    75,    21,    21,    21,    21,    76,    21,    21,    21,
      77,    21,    21,    78,    76,    78,    21,    21,    79,    21,
      21,    80,    27,    22,    20,    19,    65,    19,    19,    27,
      24,    25,    26,    67,    27,    23,    66,    19,    24,    27,
      19,    69,    19,    24,    25,    34,    70,    27,    24,    27,
      27,    71,    27,    27,    27,    27,    72,    27,    19,    27,
      73,    27,    19,    19,    74,    19,    19,    24,    75,    24,
      19,    19,    19,    24,    19,    27,    19,    27,    19,    27,
      79,    27,    27,    65,    27,    66,    69,    74,    66,    66,
      66
  };

  const unsigned char
  analizer_parser::yyr1_[] =
  {
       0,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    71,    71,    71,    72,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    79,    79,    80,    80
  };

  const unsigned char
  analizer_parser::yyr2_[] =
  {
       0,     2,     1,     5,     4,     8,     3,     4,     5,     4,
       4,     4,     1,     4,     4,     4,     4,     5,     4,     4,
       4,     1,     4,     3,     4,     3,     3,     3,     3,     4,
       4,     3,     3,     3,     3,     3,     0,     1,     3,     3,
       4,     3,     1,     0,     3,     3,     3,     3,     3,     3,
       0,     3,     3,     3,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     0,     3,     3,     1,     3,     0,
       1,     3,     3,     0,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const analizer_parser::yytname_[] =
  {
  "\"eof\"", "error", "$undefined", "size", "fit", "unit", "path",
  "mkdisk", "rmdisk", "mount", "unmount", "id", "fdisk", "deleter", "add",
  "rep", "name", "exec", "typer", "pather", "unitl", "assign", "adj",
  "typep", "idvda", "tpdelete", "minus", "npart", "fs", "mkfs", "usr",
  "pwd", "mkgrp", "grp", "typartition", "login", "logout", "rmgrp",
  "mkusr", "rmusr", "chmod", "recursive", "ugo", "mkFile", "parametro",
  "cont", "cat", "file", "mkdir", "loss", "pause", "rem", "mv", "dest",
  "recovery", "edit", "ren", "cp", "find", "chown", "chgrp", "ruta",
  "$accept", "INICIO", "ADMINIST", "MKPARM", "FDISK", "SIMBOL", "DMOUNT",
  "DREP", "MKFS", "LOGIN", "MKUSR", "CHMOD", "MKFILE", "MKDIR", "MV",
  "EDIT", "REN", "CHOWN", "CHGRP", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  analizer_parser::yyrline_[] =
  {
       0,   118,   118,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   150,   151,   152,   153,   154,   156,   157,   158,
     159,   160,   163,   164,   166,   167,   169,   170,   171,   172,
     173,   175,   176,   177,   178,   180,   181,   182,   184,   185,
     186,   188,   189,   190,   191,   193,   194,   195,   196,   197,
     199,   200,   201,   202,   204,   205,   208,   209,   211,   212,
     214,   215,   216,   218,   219
  };

  // Print the state stack on the debug stream.
  void
  analizer_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  analizer_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 5 "parser.yy" // lalr1.cc:1167
} // yy
#line 2313 "parser.tab.cc" // lalr1.cc:1167
#line 223 "parser.yy" // lalr1.cc:1168


void yy::analizer_parser::error(const location_type& lugar, const std::string& lexema)
{
  std::cout << "Error Sintactico " << lexema << " var " << std::endl;
}

void analizer_driver::init_mount()
{
    init_mounts();
}

bool analizer_driver::get_bool_exec()
{
    if(exec == true)
        return true;
    else
        return false;
}

string analizer_driver::get_path()
{
    if(path.compare("") != 0)
        return path;
    else
        return "notdefined";
}

void analizer_driver::set_exec_bool()
{
    exec = false;
}

void analizer_driver::set_default_vars_methods()
{
    default_vars();
}


