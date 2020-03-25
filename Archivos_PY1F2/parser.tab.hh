// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
// //                    "%code requires" blocks.
#line 9 "parser.yy" // lalr1.cc:377

#include <string>
#include <stdio.h>
using namespace std;
class analizer_driver;

#line 51 "parser.tab.hh" // lalr1.cc:377

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 5 "parser.yy" // lalr1.cc:377
namespace yy {
#line 128 "parser.tab.hh" // lalr1.cc:377



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class analizer_parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // unitl
      // typep
      char dummy1[sizeof(char)];

      // size
      // fit
      // unit
      // path
      // mkdisk
      // rmdisk
      // mount
      // unmount
      // id
      // fdisk
      // deleter
      // add
      // rep
      // name
      // exec
      // typer
      // pather
      // assign
      // adj
      // idvda
      // tpdelete
      // minus
      // npart
      // fs
      // mkfs
      // usr
      // pwd
      // mkgrp
      // grp
      // typartition
      // login
      // logout
      // rmgrp
      // mkusr
      // rmusr
      // chmod
      // recursive
      // ugo
      // mkFile
      // parametro
      // cont
      // cat
      // file
      // mkdir
      // loss
      // pause
      // rem
      // mv
      // dest
      // recovery
      // INICIO
      // ADMINIST
      // MKPARM
      // FDISK
      // SIMBOL
      // DMOUNT
      // DREP
      // MKFS
      // LOGIN
      // MKUSR
      // CHMOD
      // MKFILE
      // MKDIR
      // MV
      char dummy2[sizeof(string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_FIN = 0,
        TOK_size = 258,
        TOK_fit = 259,
        TOK_unit = 260,
        TOK_path = 261,
        TOK_mkdisk = 262,
        TOK_rmdisk = 263,
        TOK_mount = 264,
        TOK_unmount = 265,
        TOK_id = 266,
        TOK_fdisk = 267,
        TOK_deleter = 268,
        TOK_add = 269,
        TOK_rep = 270,
        TOK_name = 271,
        TOK_exec = 272,
        TOK_typer = 273,
        TOK_pather = 274,
        TOK_unitl = 275,
        TOK_assign = 276,
        TOK_adj = 277,
        TOK_typep = 278,
        TOK_idvda = 279,
        TOK_tpdelete = 280,
        TOK_minus = 281,
        TOK_npart = 282,
        TOK_fs = 283,
        TOK_mkfs = 284,
        TOK_usr = 285,
        TOK_pwd = 286,
        TOK_mkgrp = 287,
        TOK_grp = 288,
        TOK_typartition = 289,
        TOK_login = 290,
        TOK_logout = 291,
        TOK_rmgrp = 292,
        TOK_mkusr = 293,
        TOK_rmusr = 294,
        TOK_chmod = 295,
        TOK_recursive = 296,
        TOK_ugo = 297,
        TOK_mkFile = 298,
        TOK_parametro = 299,
        TOK_cont = 300,
        TOK_cat = 301,
        TOK_file = 302,
        TOK_mkdir = 303,
        TOK_loss = 304,
        TOK_pause = 305,
        TOK_rem = 306,
        TOK_mv = 307,
        TOK_dest = 308,
        TOK_recovery = 309
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const char v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const string v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_FIN (const location_type& l);

    static inline
    symbol_type
    make_size (const string& v, const location_type& l);

    static inline
    symbol_type
    make_fit (const string& v, const location_type& l);

    static inline
    symbol_type
    make_unit (const string& v, const location_type& l);

    static inline
    symbol_type
    make_path (const string& v, const location_type& l);

    static inline
    symbol_type
    make_mkdisk (const string& v, const location_type& l);

    static inline
    symbol_type
    make_rmdisk (const string& v, const location_type& l);

    static inline
    symbol_type
    make_mount (const string& v, const location_type& l);

    static inline
    symbol_type
    make_unmount (const string& v, const location_type& l);

    static inline
    symbol_type
    make_id (const string& v, const location_type& l);

    static inline
    symbol_type
    make_fdisk (const string& v, const location_type& l);

    static inline
    symbol_type
    make_deleter (const string& v, const location_type& l);

    static inline
    symbol_type
    make_add (const string& v, const location_type& l);

    static inline
    symbol_type
    make_rep (const string& v, const location_type& l);

    static inline
    symbol_type
    make_name (const string& v, const location_type& l);

    static inline
    symbol_type
    make_exec (const string& v, const location_type& l);

    static inline
    symbol_type
    make_typer (const string& v, const location_type& l);

    static inline
    symbol_type
    make_pather (const string& v, const location_type& l);

    static inline
    symbol_type
    make_unitl (const char& v, const location_type& l);

    static inline
    symbol_type
    make_assign (const string& v, const location_type& l);

    static inline
    symbol_type
    make_adj (const string& v, const location_type& l);

    static inline
    symbol_type
    make_typep (const char& v, const location_type& l);

    static inline
    symbol_type
    make_idvda (const string& v, const location_type& l);

    static inline
    symbol_type
    make_tpdelete (const string& v, const location_type& l);

    static inline
    symbol_type
    make_minus (const string& v, const location_type& l);

    static inline
    symbol_type
    make_npart (const string& v, const location_type& l);

    static inline
    symbol_type
    make_fs (const string& v, const location_type& l);

    static inline
    symbol_type
    make_mkfs (const string& v, const location_type& l);

    static inline
    symbol_type
    make_usr (const string& v, const location_type& l);

    static inline
    symbol_type
    make_pwd (const string& v, const location_type& l);

    static inline
    symbol_type
    make_mkgrp (const string& v, const location_type& l);

    static inline
    symbol_type
    make_grp (const string& v, const location_type& l);

    static inline
    symbol_type
    make_typartition (const string& v, const location_type& l);

    static inline
    symbol_type
    make_login (const string& v, const location_type& l);

    static inline
    symbol_type
    make_logout (const string& v, const location_type& l);

    static inline
    symbol_type
    make_rmgrp (const string& v, const location_type& l);

    static inline
    symbol_type
    make_mkusr (const string& v, const location_type& l);

    static inline
    symbol_type
    make_rmusr (const string& v, const location_type& l);

    static inline
    symbol_type
    make_chmod (const string& v, const location_type& l);

    static inline
    symbol_type
    make_recursive (const string& v, const location_type& l);

    static inline
    symbol_type
    make_ugo (const string& v, const location_type& l);

    static inline
    symbol_type
    make_mkFile (const string& v, const location_type& l);

    static inline
    symbol_type
    make_parametro (const string& v, const location_type& l);

    static inline
    symbol_type
    make_cont (const string& v, const location_type& l);

    static inline
    symbol_type
    make_cat (const string& v, const location_type& l);

    static inline
    symbol_type
    make_file (const string& v, const location_type& l);

    static inline
    symbol_type
    make_mkdir (const string& v, const location_type& l);

    static inline
    symbol_type
    make_loss (const string& v, const location_type& l);

    static inline
    symbol_type
    make_pause (const string& v, const location_type& l);

    static inline
    symbol_type
    make_rem (const string& v, const location_type& l);

    static inline
    symbol_type
    make_mv (const string& v, const location_type& l);

    static inline
    symbol_type
    make_dest (const string& v, const location_type& l);

    static inline
    symbol_type
    make_recovery (const string& v, const location_type& l);


    /// Build a parser object.
    analizer_parser (analizer_driver& driver_yyarg);
    virtual ~analizer_parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    analizer_parser (const analizer_parser&);
    analizer_parser& operator= (const analizer_parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const unsigned char yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 178,     ///< Last index in yytable_.
      yynnts_ = 15,  ///< Number of nonterminal symbols.
      yyfinal_ = 81, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 55  ///< Number of tokens.
    };


    // User arguments.
    analizer_driver& driver;
  };

  // Symbol number corresponding to token number t.
  inline
  analizer_parser::token_number_type
  analizer_parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
    };
    const unsigned int user_token_number_max_ = 309;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  analizer_parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  analizer_parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  analizer_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 20: // unitl
      case 23: // typep
        value.copy< char > (other.value);
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
        value.copy< string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  analizer_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 20: // unitl
      case 23: // typep
        value.copy< char > (v);
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
        value.copy< string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  analizer_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  analizer_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const char v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  analizer_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  analizer_parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  analizer_parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 20: // unitl
      case 23: // typep
        value.template destroy< char > ();
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
        value.template destroy< string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  analizer_parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  analizer_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 20: // unitl
      case 23: // typep
        value.move< char > (s.value);
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
        value.move< string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  analizer_parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  analizer_parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  analizer_parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  analizer_parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  analizer_parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  analizer_parser::by_type::type_get () const
  {
    return type;
  }

  inline
  analizer_parser::token_type
  analizer_parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  analizer_parser::symbol_type
  analizer_parser::make_FIN (const location_type& l)
  {
    return symbol_type (token::TOK_FIN, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_size (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_size, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_fit (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_fit, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_unit (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_unit, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_path (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_path, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_mkdisk (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_mkdisk, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_rmdisk (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_rmdisk, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_mount (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_mount, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_unmount (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_unmount, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_id (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_id, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_fdisk (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_fdisk, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_deleter (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_deleter, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_add (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_add, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_rep (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_rep, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_name (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_name, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_exec (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_exec, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_typer (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_typer, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_pather (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_pather, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_unitl (const char& v, const location_type& l)
  {
    return symbol_type (token::TOK_unitl, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_assign (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_assign, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_adj (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_adj, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_typep (const char& v, const location_type& l)
  {
    return symbol_type (token::TOK_typep, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_idvda (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_idvda, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_tpdelete (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_tpdelete, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_minus (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_minus, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_npart (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_npart, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_fs (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_fs, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_mkfs (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_mkfs, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_usr (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_usr, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_pwd (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_pwd, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_mkgrp (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_mkgrp, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_grp (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_grp, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_typartition (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_typartition, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_login (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_login, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_logout (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_logout, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_rmgrp (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_rmgrp, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_mkusr (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_mkusr, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_rmusr (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_rmusr, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_chmod (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_chmod, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_recursive (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_recursive, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_ugo (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_ugo, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_mkFile (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_mkFile, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_parametro (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_parametro, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_cont (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_cont, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_cat (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_cat, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_file (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_file, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_mkdir (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_mkdir, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_loss (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_loss, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_pause (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_pause, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_rem (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_rem, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_mv (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_mv, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_dest (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_dest, v, l);
  }

  analizer_parser::symbol_type
  analizer_parser::make_recovery (const string& v, const location_type& l)
  {
    return symbol_type (token::TOK_recovery, v, l);
  }


#line 5 "parser.yy" // lalr1.cc:377
} // yy
#line 1820 "parser.tab.hh" // lalr1.cc:377




#endif // !YY_YY_PARSER_TAB_HH_INCLUDED
