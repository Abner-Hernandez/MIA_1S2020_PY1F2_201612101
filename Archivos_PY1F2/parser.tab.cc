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
      case 56: // INICIO
      case 57: // ADMINIST
      case 58: // MKPARM
      case 59: // FDISK
      case 60: // SIMBOL
      case 61: // DMOUNT
      case 62: // DREP
      case 63: // MKFS
      case 64: // LOGIN
      case 65: // MKUSR
      case 66: // CHMOD
      case 67: // MKFILE
      case 68: // MKDIR
      case 69: // MV
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
      case 56: // INICIO
      case 57: // ADMINIST
      case 58: // MKPARM
      case 59: // FDISK
      case 60: // SIMBOL
      case 61: // DMOUNT
      case 62: // DREP
      case 63: // MKFS
      case 64: // LOGIN
      case 65: // MKUSR
      case 66: // CHMOD
      case 67: // MKFILE
      case 68: // MKDIR
      case 69: // MV
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

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 456 "parser.tab.cc" // lalr1.cc:636
        break;

      case 4: // fit

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 463 "parser.tab.cc" // lalr1.cc:636
        break;

      case 5: // unit

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 470 "parser.tab.cc" // lalr1.cc:636
        break;

      case 6: // path

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 477 "parser.tab.cc" // lalr1.cc:636
        break;

      case 7: // mkdisk

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 484 "parser.tab.cc" // lalr1.cc:636
        break;

      case 8: // rmdisk

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 491 "parser.tab.cc" // lalr1.cc:636
        break;

      case 9: // mount

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 498 "parser.tab.cc" // lalr1.cc:636
        break;

      case 10: // unmount

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 505 "parser.tab.cc" // lalr1.cc:636
        break;

      case 11: // id

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 512 "parser.tab.cc" // lalr1.cc:636
        break;

      case 12: // fdisk

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 519 "parser.tab.cc" // lalr1.cc:636
        break;

      case 13: // deleter

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 526 "parser.tab.cc" // lalr1.cc:636
        break;

      case 14: // add

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 533 "parser.tab.cc" // lalr1.cc:636
        break;

      case 15: // rep

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 540 "parser.tab.cc" // lalr1.cc:636
        break;

      case 16: // name

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 547 "parser.tab.cc" // lalr1.cc:636
        break;

      case 17: // exec

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 554 "parser.tab.cc" // lalr1.cc:636
        break;

      case 18: // typer

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 561 "parser.tab.cc" // lalr1.cc:636
        break;

      case 19: // pather

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 568 "parser.tab.cc" // lalr1.cc:636
        break;

      case 20: // unitl

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< char > (); }
#line 575 "parser.tab.cc" // lalr1.cc:636
        break;

      case 21: // assign

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 582 "parser.tab.cc" // lalr1.cc:636
        break;

      case 22: // adj

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 589 "parser.tab.cc" // lalr1.cc:636
        break;

      case 23: // typep

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< char > (); }
#line 596 "parser.tab.cc" // lalr1.cc:636
        break;

      case 24: // idvda

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 603 "parser.tab.cc" // lalr1.cc:636
        break;

      case 25: // tpdelete

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 610 "parser.tab.cc" // lalr1.cc:636
        break;

      case 26: // minus

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 617 "parser.tab.cc" // lalr1.cc:636
        break;

      case 27: // npart

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 624 "parser.tab.cc" // lalr1.cc:636
        break;

      case 28: // fs

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 631 "parser.tab.cc" // lalr1.cc:636
        break;

      case 29: // mkfs

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 638 "parser.tab.cc" // lalr1.cc:636
        break;

      case 30: // usr

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 645 "parser.tab.cc" // lalr1.cc:636
        break;

      case 31: // pwd

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 652 "parser.tab.cc" // lalr1.cc:636
        break;

      case 32: // mkgrp

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 659 "parser.tab.cc" // lalr1.cc:636
        break;

      case 33: // grp

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 666 "parser.tab.cc" // lalr1.cc:636
        break;

      case 34: // typartition

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 673 "parser.tab.cc" // lalr1.cc:636
        break;

      case 35: // login

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 680 "parser.tab.cc" // lalr1.cc:636
        break;

      case 36: // logout

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 687 "parser.tab.cc" // lalr1.cc:636
        break;

      case 37: // rmgrp

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 694 "parser.tab.cc" // lalr1.cc:636
        break;

      case 38: // mkusr

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 701 "parser.tab.cc" // lalr1.cc:636
        break;

      case 39: // rmusr

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 708 "parser.tab.cc" // lalr1.cc:636
        break;

      case 40: // chmod

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 715 "parser.tab.cc" // lalr1.cc:636
        break;

      case 41: // recursive

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 722 "parser.tab.cc" // lalr1.cc:636
        break;

      case 42: // ugo

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 729 "parser.tab.cc" // lalr1.cc:636
        break;

      case 43: // mkFile

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 736 "parser.tab.cc" // lalr1.cc:636
        break;

      case 44: // parametro

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 743 "parser.tab.cc" // lalr1.cc:636
        break;

      case 45: // cont

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 750 "parser.tab.cc" // lalr1.cc:636
        break;

      case 46: // cat

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 757 "parser.tab.cc" // lalr1.cc:636
        break;

      case 47: // file

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 764 "parser.tab.cc" // lalr1.cc:636
        break;

      case 48: // mkdir

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 771 "parser.tab.cc" // lalr1.cc:636
        break;

      case 49: // loss

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 778 "parser.tab.cc" // lalr1.cc:636
        break;

      case 50: // pause

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 785 "parser.tab.cc" // lalr1.cc:636
        break;

      case 51: // rem

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 792 "parser.tab.cc" // lalr1.cc:636
        break;

      case 52: // mv

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 799 "parser.tab.cc" // lalr1.cc:636
        break;

      case 53: // dest

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 806 "parser.tab.cc" // lalr1.cc:636
        break;

      case 54: // recovery

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 813 "parser.tab.cc" // lalr1.cc:636
        break;

      case 56: // INICIO

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 820 "parser.tab.cc" // lalr1.cc:636
        break;

      case 57: // ADMINIST

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 827 "parser.tab.cc" // lalr1.cc:636
        break;

      case 58: // MKPARM

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 834 "parser.tab.cc" // lalr1.cc:636
        break;

      case 59: // FDISK

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 841 "parser.tab.cc" // lalr1.cc:636
        break;

      case 60: // SIMBOL

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 848 "parser.tab.cc" // lalr1.cc:636
        break;

      case 61: // DMOUNT

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 855 "parser.tab.cc" // lalr1.cc:636
        break;

      case 62: // DREP

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 862 "parser.tab.cc" // lalr1.cc:636
        break;

      case 63: // MKFS

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 869 "parser.tab.cc" // lalr1.cc:636
        break;

      case 64: // LOGIN

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 876 "parser.tab.cc" // lalr1.cc:636
        break;

      case 65: // MKUSR

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 883 "parser.tab.cc" // lalr1.cc:636
        break;

      case 66: // CHMOD

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 890 "parser.tab.cc" // lalr1.cc:636
        break;

      case 67: // MKFILE

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 897 "parser.tab.cc" // lalr1.cc:636
        break;

      case 68: // MKDIR

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 904 "parser.tab.cc" // lalr1.cc:636
        break;

      case 69: // MV

#line 100 "parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< string > (); }
#line 911 "parser.tab.cc" // lalr1.cc:636
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
      case 56: // INICIO
      case 57: // ADMINIST
      case 58: // MKPARM
      case 59: // FDISK
      case 60: // SIMBOL
      case 61: // DMOUNT
      case 62: // DREP
      case 63: // MKFS
      case 64: // LOGIN
      case 65: // MKUSR
      case 66: // CHMOD
      case 67: // MKFILE
      case 68: // MKDIR
      case 69: // MV
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
#line 104 "parser.yy" // lalr1.cc:859
    {}
#line 1203 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 106 "parser.yy" // lalr1.cc:859
    { mkdisk();}
#line 1209 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 107 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path); rmdisk();}
#line 1215 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 108 "parser.yy" // lalr1.cc:859
    { fdisk();}
#line 1221 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 109 "parser.yy" // lalr1.cc:859
    { mount();}
#line 1227 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 110 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > (); unmount();}
#line 1233 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 111 "parser.yy" // lalr1.cc:859
    { rep();}
#line 1239 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 112 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path); exec = true;}
#line 1245 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 113 "parser.yy" // lalr1.cc:859
    { mkfs();}
#line 1251 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 114 "parser.yy" // lalr1.cc:859
    { login();}
#line 1257 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 115 "parser.yy" // lalr1.cc:859
    { logout();}
#line 1263 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 116 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name); mkgrp();}
#line 1269 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 117 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name); rmgrp();}
#line 1275 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 118 "parser.yy" // lalr1.cc:859
    { mkusr();}
#line 1281 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 119 "parser.yy" // lalr1.cc:859
    { usr = yystack_[0].value.as< string > (); verificar_comillas(usr); rmusr(); }
#line 1287 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 120 "parser.yy" // lalr1.cc:859
    { }
#line 1293 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 121 "parser.yy" // lalr1.cc:859
    { mkfile();}
#line 1299 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 122 "parser.yy" // lalr1.cc:859
    { file = yystack_[0].value.as< string > (); verificar_comillas(file); cat();}
#line 1305 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 123 "parser.yy" // lalr1.cc:859
    { mkdir();}
#line 1311 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 124 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > (); loss();}
#line 1317 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 125 "parser.yy" // lalr1.cc:859
    { pause();}
#line 1323 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 126 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path); remover();}
#line 1329 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 127 "parser.yy" // lalr1.cc:859
    { mover();}
#line 1335 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 128 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > ();}
#line 1341 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 130 "parser.yy" // lalr1.cc:859
    { size = verificate_string(yystack_[0].value.as< string > ()); /* size = $3; */ }
#line 1347 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 131 "parser.yy" // lalr1.cc:859
    { fit = yystack_[0].value.as< string > ();}
#line 1353 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 132 "parser.yy" // lalr1.cc:859
    { unit = yystack_[0].value.as< char > ();}
#line 1359 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 133 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1365 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 134 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< string > () = "empty";}
#line 1371 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 137 "parser.yy" // lalr1.cc:859
    { type = yystack_[0].value.as< char > ();}
#line 1377 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 138 "parser.yy" // lalr1.cc:859
    { tdelete = yystack_[0].value.as< string > ();  }
#line 1383 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 139 "parser.yy" // lalr1.cc:859
    { add = verificate_string(yystack_[0].value.as< string > ());/* add = $4; */ }
#line 1389 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 140 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name);}
#line 1395 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 143 "parser.yy" // lalr1.cc:859
    { sign = "menos";}
#line 1401 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 144 "parser.yy" // lalr1.cc:859
    { sign = "mas";}
#line 1407 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 146 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1413 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 147 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name);}
#line 1419 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 149 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1425 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 150 "parser.yy" // lalr1.cc:859
    { name = yystack_[0].value.as< string > (); verificar_comillas(name);}
#line 1431 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 151 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > ();}
#line 1437 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 153 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > ();}
#line 1443 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 154 "parser.yy" // lalr1.cc:859
    { tdelete = yystack_[0].value.as< string > ();}
#line 1449 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 155 "parser.yy" // lalr1.cc:859
    { set_fs_char(yystack_[0].value.as< string > ());}
#line 1455 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 156 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< string > () = "empty";}
#line 1461 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 158 "parser.yy" // lalr1.cc:859
    { usr = yystack_[0].value.as< string > (); verificar_comillas(usr);}
#line 1467 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 159 "parser.yy" // lalr1.cc:859
    { pwd = yystack_[0].value.as< string > (); verificar_comillas(pwd);}
#line 1473 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 160 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > ();}
#line 1479 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 162 "parser.yy" // lalr1.cc:859
    { usr = yystack_[0].value.as< string > (); verificar_comillas(usr);}
#line 1485 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 163 "parser.yy" // lalr1.cc:859
    { pwd = yystack_[0].value.as< string > (); verificar_comillas(pwd);}
#line 1491 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 164 "parser.yy" // lalr1.cc:859
    { grp = yystack_[0].value.as< string > (); verificar_comillas(grp);}
#line 1497 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 166 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1503 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 169 "parser.yy" // lalr1.cc:859
    { size = verificate_string(yystack_[0].value.as< string > ()); /* size = $3; */ }
#line 1509 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 170 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1515 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 171 "parser.yy" // lalr1.cc:859
    { atribp = 's';}
#line 1521 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 172 "parser.yy" // lalr1.cc:859
    { cont = yystack_[0].value.as< string > (); verificar_comillas(cont);}
#line 1527 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 173 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< string > () = "empty";}
#line 1533 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 175 "parser.yy" // lalr1.cc:859
    { atribp = 's';}
#line 1539 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 176 "parser.yy" // lalr1.cc:859
    { id = yystack_[0].value.as< string > ();}
#line 1545 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 177 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1551 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 178 "parser.yy" // lalr1.cc:859
    { yylhs.value.as< string > () = "empty";}
#line 1557 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 180 "parser.yy" // lalr1.cc:859
    { path = yystack_[0].value.as< string > (); verificar_comillas(path);}
#line 1563 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 181 "parser.yy" // lalr1.cc:859
    { dest = yystack_[0].value.as< string > (); verificar_comillas(dest);}
#line 1569 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1573 "parser.tab.cc" // lalr1.cc:859
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


  const signed char analizer_parser::yypact_ninf_ = -73;

  const signed char analizer_parser::yytable_ninf_ = -1;

  const short int
  analizer_parser::yypact_[] =
  {
      62,    38,     8,    13,     9,    22,     7,    15,     6,    17,
       1,   -73,    21,    33,    -8,    10,     5,    -2,     4,    28,
     -73,    40,     3,    26,    51,   -73,    32,    44,    46,    47,
      38,    52,    54,    55,    13,    57,    59,    60,    61,    63,
     -73,    22,    64,    66,    67,     7,    68,    69,    71,    72,
       6,    74,    75,    82,    83,     1,    88,    94,    96,    97,
      33,    98,    99,   -73,    10,   100,   101,   -73,   102,     5,
     103,   104,   105,   -73,     4,   106,   107,   108,   109,     3,
      35,   -73,    56,   110,   111,   114,    38,   115,   116,   112,
     -73,   117,   113,   120,   121,   124,    22,   130,   119,   123,
       7,   132,   128,   129,   122,     6,   126,   131,   133,   134,
       1,   135,   136,   137,   138,    33,   139,   140,   -73,   141,
     148,   150,     5,   151,   152,   149,     4,   153,   155,   156,
     157,   -73,   -73,   -73,   -73,   -73,   -73,    38,   -73,   -73,
     -73,   -73,   -73,   -73,   145,   -73,   -73,    22,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,     5,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,    22,   -73,    22,    22,   -73
  };

  const unsigned char
  analizer_parser::yydefact_[] =
  {
       0,    30,     0,     0,     0,    30,     0,     0,    46,     0,
       0,    12,     0,     0,     0,     0,    59,     0,    63,     0,
      22,     0,     0,     0,     0,     2,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    30,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,    57,     0,    59,
       0,     0,     0,    60,    63,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,    30,     0,     0,     0,
       6,     0,     0,    37,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     0,    59,     0,     0,     0,    63,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,    30,     4,    38,
      39,     7,    33,    36,     0,    35,    32,    30,    40,    42,
      41,     8,     9,    43,    44,    45,    10,    13,    49,    47,
      48,    11,    14,    50,    51,    52,    15,    16,    53,    55,
      56,    58,    59,    19,    62,    61,    20,    21,    23,    64,
      65,     3,    34,    30,    18,    30,    30,     5
  };

  const short int
  analizer_parser::yypgoto_[] =
  {
     -73,   -73,   -73,     0,   -41,   -73,   144,   -42,   -45,   -49,
     -53,    76,   -65,   -72,    78
  };

  const short int
  analizer_parser::yydefgoto_[] =
  {
      -1,    24,    25,    40,    41,   144,    34,    45,    50,    55,
      60,    64,    69,    74,    79
  };

  const unsigned char
  analizer_parser::yytable_[] =
  {
      96,    30,   126,   100,   122,   105,   110,   115,    65,    77,
      71,    66,    52,    42,    31,    72,    62,    47,    43,    32,
      35,    46,    61,    44,    48,    26,    27,    28,    29,    33,
      86,    53,    54,    51,    49,    36,    37,    56,    38,    75,
      39,    26,    27,    28,    29,    70,    76,    80,    73,    67,
      68,    81,    63,    82,   176,   147,    78,   172,   151,   132,
     156,   161,   166,    57,    58,    83,    59,    84,    85,     1,
       2,     3,     4,    87,     5,    88,    89,     6,    91,     7,
      92,    93,    94,   133,    95,    97,   137,    98,    99,   101,
     102,     8,   103,   104,     9,   106,   107,    10,    11,    12,
      13,    14,    15,   108,   109,    16,   183,   184,    17,   111,
      18,    19,    20,    21,    22,   112,    23,   113,   114,   116,
     117,   119,   120,   121,   123,   124,   125,   127,   128,   129,
     130,   135,   134,   136,   138,   139,     0,   181,   142,   140,
     118,   141,   185,   149,   186,   187,   143,   146,   145,   148,
     150,   152,   153,   157,   154,   158,   155,   131,     0,   168,
     159,   160,   162,   163,   164,   165,   167,   170,   169,   171,
     173,   174,   182,   175,   178,   179,   180,   177,    90
  };

  const short int
  analizer_parser::yycheck_[] =
  {
      41,     1,    74,    45,    69,    50,    55,    60,     3,     6,
       6,     6,    11,     6,     6,    11,     6,    11,    11,     6,
      11,     6,    30,    16,    18,     3,     4,     5,     6,    16,
      30,    30,    31,    16,    28,    13,    14,    16,    16,    11,
      18,     3,     4,     5,     6,    47,     6,    21,    44,    44,
      45,     0,    42,    21,   126,    96,    53,   122,   100,    24,
     105,   110,   115,    30,    31,    21,    33,    21,    21,     7,
       8,     9,    10,    21,    12,    21,    21,    15,    21,    17,
      21,    21,    21,    27,    21,    21,    86,    21,    21,    21,
      21,    29,    21,    21,    32,    21,    21,    35,    36,    37,
      38,    39,    40,    21,    21,    43,   147,   172,    46,    21,
      48,    49,    50,    51,    52,    21,    54,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
      21,    20,    22,    19,    19,    19,    -1,   137,    25,    27,
      64,    24,   183,    24,   185,   186,    26,    23,    27,    19,
      27,    19,    24,    27,    25,    24,    34,    79,    -1,    19,
      27,    27,    27,    27,    27,    27,    27,    19,    27,    19,
      19,    19,    27,    24,    19,    19,    19,    24,    34
  };

  const unsigned char
  analizer_parser::yystos_[] =
  {
       0,     7,     8,     9,    10,    12,    15,    17,    29,    32,
      35,    36,    37,    38,    39,    40,    43,    46,    48,    49,
      50,    51,    52,    54,    56,    57,     3,     4,     5,     6,
      58,     6,     6,    16,    61,    11,    13,    14,    16,    18,
      58,    59,     6,    11,    16,    62,     6,    11,    18,    28,
      63,    16,    11,    30,    31,    64,    16,    30,    31,    33,
      65,    30,     6,    42,    66,     3,     6,    44,    45,    67,
      47,     6,    11,    44,    68,    11,     6,     6,    53,    69,
      21,     0,    21,    21,    21,    21,    58,    21,    21,    21,
      61,    21,    21,    21,    21,    21,    59,    21,    21,    21,
      62,    21,    21,    21,    21,    63,    21,    21,    21,    21,
      64,    21,    21,    21,    21,    65,    21,    21,    66,    21,
      21,    21,    67,    21,    21,    21,    68,    21,    21,    21,
      21,    69,    24,    27,    22,    20,    19,    58,    19,    19,
      27,    24,    25,    26,    60,    27,    23,    59,    19,    24,
      27,    62,    19,    24,    25,    34,    63,    27,    24,    27,
      27,    64,    27,    27,    27,    27,    65,    27,    19,    27,
      19,    19,    67,    19,    19,    24,    68,    24,    19,    19,
      19,    58,    27,    59,    67,    59,    59,    59
  };

  const unsigned char
  analizer_parser::yyr1_[] =
  {
       0,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    63,    63,    63,    63,    64,    64,    64,
      65,    65,    65,    66,    66,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    69,    69
  };

  const unsigned char
  analizer_parser::yyr2_[] =
  {
       0,     2,     1,     5,     4,     8,     3,     4,     4,     4,
       4,     4,     1,     4,     4,     4,     4,     3,     5,     4,
       4,     4,     1,     4,     3,     3,     3,     3,     3,     3,
       0,     1,     3,     3,     4,     3,     1,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     0,
       1,     3,     3,     0,     3,     3
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
  "recovery", "$accept", "INICIO", "ADMINIST", "MKPARM", "FDISK", "SIMBOL",
  "DMOUNT", "DREP", "MKFS", "LOGIN", "MKUSR", "CHMOD", "MKFILE", "MKDIR",
  "MV", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  analizer_parser::yyrline_[] =
  {
       0,   104,   104,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   130,   131,   132,   133,
     134,   136,   137,   138,   139,   140,   143,   144,   146,   147,
     149,   150,   151,   153,   154,   155,   156,   158,   159,   160,
     162,   163,   164,   166,   167,   169,   170,   171,   172,   173,
     175,   176,   177,   178,   180,   181
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
#line 2052 "parser.tab.cc" // lalr1.cc:1167
#line 185 "parser.yy" // lalr1.cc:1168


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


