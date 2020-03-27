%{
# include <cerrno>
#include <stdio.h>
#include <string>
#include "driver.h"
#include "parser.tab.hh"
#undef yywrap
#define yywrap() 1
static yy::location loc;
%}
%option case-insensitive
%option noyywrap nounput batch debug noinput
%option outfile="scanner.cpp"
LETRA [a-zñA-ZÑ]+
DIGITO [0-9]
UNITD ("m"|"k")
ADJ ("BF"|"FF"|"WF")
TYPEP ("P"|"E"|"L")
TPDELETE ("FAST"|"FULL")
TYPARTITION ("2fs"|"3fs")

PATHER1 ([/][^/" "]+)+
PATHER2 [\"]([/][^/\"]+)+[\"]
PATHER ({PATHER1}|{PATHER2})

VDA ["vd"]{LETRA}{DIGITO}
CAD [\"][^/\"]+[\"]
cad2 ({LETRA}|{DIGITO}|"_")+
PARTNAME ({CAD}|{cad2})
COMENTARIOM "/*"[^'*']*"*/"
COMENTARIOL "#"[^*\n]*
COMENTARIOLL "//"[^*\n]*

DELIMITADOR [ \t\r\f\n]+
%%

"-ruta"         {return yy::analizer_parser::make_ruta(yytext, loc);}
"chgrp"         {return yy::analizer_parser::make_chgrp(yytext, loc);}
"chown"         {return yy::analizer_parser::make_chown(yytext, loc);}
"find"          {return yy::analizer_parser::make_find(yytext, loc);}
"cp"            {return yy::analizer_parser::make_cp(yytext, loc);}
"edit"          {return yy::analizer_parser::make_edit(yytext, loc);}
"ren"           {return yy::analizer_parser::make_ren(yytext, loc);}
"recovery"      {return yy::analizer_parser::make_recovery(yytext, loc);}
"-dest"         {return yy::analizer_parser::make_dest(yytext, loc);}
"mv"            {return yy::analizer_parser::make_mv(yytext, loc);}
"rem"           {return yy::analizer_parser::make_rem(yytext, loc);}
"pause"         {return yy::analizer_parser::make_pause(yytext, loc);}
"Loss"          {return yy::analizer_parser::make_loss(yytext, loc);}
"Mkdir"         {return yy::analizer_parser::make_mkdir(yytext, loc);}
"-file"         {return yy::analizer_parser::make_file(yytext, loc);}
"Cat"           {return yy::analizer_parser::make_cat(yytext, loc);}
"-cont"         {return yy::analizer_parser::make_cont(yytext, loc);}
"-p"            {return yy::analizer_parser::make_parametro(yytext, loc);}
"mkFile"        {return yy::analizer_parser::make_mkFile(yytext, loc);}
"-r"            {return yy::analizer_parser::make_recursive(yytext, loc);}
"-ugo"          {return yy::analizer_parser::make_ugo(yytext, loc);}
"chmod"         {return yy::analizer_parser::make_chmod(yytext, loc);}
"rmusr"         {return yy::analizer_parser::make_rmusr(yytext, loc);}
"mkusr"         {return yy::analizer_parser::make_mkusr(yytext, loc);}
"rmgrp"         {return yy::analizer_parser::make_rmgrp(yytext, loc);}
"mkgrp"         {return yy::analizer_parser::make_mkgrp(yytext, loc);}
"Logout"        {return yy::analizer_parser::make_logout(yytext, loc);}
"login"         {return yy::analizer_parser::make_login(yytext, loc);}
"-grp"          {return yy::analizer_parser::make_grp(yytext, loc);}
"-pwd"          {return yy::analizer_parser::make_pwd(yytext, loc);}
"-usr"          {return yy::analizer_parser::make_usr(yytext, loc);}
"mkfs"          {return yy::analizer_parser::make_mkfs(yytext, loc);}
"-fs"           {return yy::analizer_parser::make_fs(yytext, loc);}
"-size"         {return yy::analizer_parser::make_size(yytext, loc);}
"-fit"          {return yy::analizer_parser::make_fit(yytext, loc);}
"-unit"         {return yy::analizer_parser::make_unit(yytext, loc);}
"-path"         {return yy::analizer_parser::make_path(yytext, loc);}
"MKDISK"	{return yy::analizer_parser::make_mkdisk(yytext, loc);}
"RMDISK"	{return yy::analizer_parser::make_rmdisk(yytext, loc);}
"MOUNT"         {return yy::analizer_parser::make_mount(yytext, loc);}
"UNMOUNT"       {return yy::analizer_parser::make_unmount(yytext, loc);}
"-id"           {return yy::analizer_parser::make_id(yytext, loc);}
"FDISK"         {return yy::analizer_parser::make_fdisk(yytext, loc);}
"-delete"	{return yy::analizer_parser::make_deleter(yytext, loc);}
"-name"         {return yy::analizer_parser::make_name(yytext, loc);}
"-add"          {return yy::analizer_parser::make_add(yytext, loc);}
"-type"         {return yy::analizer_parser::make_typer(yytext, loc);}
"="             {return yy::analizer_parser::make_assign(yytext, loc);}
"-"             {return yy::analizer_parser::make_minus(yytext, loc);}
"REP"           {return yy::analizer_parser::make_rep(yytext, loc);}
"EXEC"          {return yy::analizer_parser::make_exec(yytext, loc);}
{PATHER}        {return yy::analizer_parser::make_pather(yytext, loc);}
{UNITD}         {return yy::analizer_parser::make_unitl(yytext[0], loc);}
{ADJ}           {return yy::analizer_parser::make_adj(yytext, loc);}
{TYPEP}         {return yy::analizer_parser::make_typep(yytext[0], loc);}
{VDA}           {return yy::analizer_parser::make_idvda(yytext, loc);}
{TPDELETE}      {return yy::analizer_parser::make_tpdelete(yytext, loc);}
{TYPARTITION}   {return yy::analizer_parser::make_typartition(yytext, loc);}
{PARTNAME}      {return yy::analizer_parser::make_npart(yytext, loc);}

{DELIMITADOR}   {}
{COMENTARIOM}   {}
{COMENTARIOL}   {}
{COMENTARIOLL}   {}

.               {printf("ERROR LEXICO %s\n",yytext);}
<<EOF>>		{return yy::analizer_parser::make_FIN(loc);}
%%
void analizer_driver::iniciarScanner()
{

    yy_scan_string(file.c_str());
/*
    yy_flex_debug = false;
    if(file.empty() || file == "-"){
      std::cout << "No se encuentra el archivo de entrada \n";
      exit(1);
    }else{
      yyin = fopen (file.c_str (), "r");
    }

*/
}

void analizer_driver::terminarScanner()
{
    fclose(yyin);
}
