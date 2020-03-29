%skeleton "lalr1.cc" /* -*- C++ -*- */
%defines
%define parser_class_name {analizer_parser}
%define api.token.constructor
%define api.namespace {yy}
%define api.value.type variant
%define parse.assert
%code requires
{
#include <string>
#include <stdio.h>
using namespace std;
class analizer_driver;
}
%param { analizer_driver& driver }
%locations
%define parse.trace
%define parse.error verbose
%code
{
#include "driver.h"
#include <iostream>
#include "methods.cpp"
}
%define api.token.prefix {TOK_}

//Listadode Terminales
%token <string> size
%token <string> fit
%token <string> unit
%token <string> path
%token <string> mkdisk
%token <string> rmdisk
%token <string> mount
%token <string> unmount
%token <string> id
%token <string> fdisk
%token <string> deleter
%token <string> add
%token <string> rep
%token <string> name
%token <string> exec
%token <string> typer
%token <string> pather
%token <char> unitl
%token <string> assign
%token <string> adj
%token <char> typep
%token <string> idvda
%token <string> tpdelete
%token <string> minus
%token <string> npart
%token <string> fs
%token <string> mkfs
%token <string> usr
%token <string> pwd
%token <string> mkgrp
%token <string> grp
%token <string> typartition
%token <string> login
%token <string> logout
%token <string> rmgrp
%token <string> mkusr
%token <string> rmusr
%token <string> chmod
%token <string> recursive
%token <string> ugo
%token <string> mkFile
%token <string> parametro
%token <string> cont
%token <string> cat
%token <string> file
%token <string> mkdir
%token <string> loss
%token <string> pause
%token <string> rem
%token <string> mv
%token <string> dest
%token <string> recovery
%token <string> edit
%token <string> ren
%token <string> cp
%token <string> find
%token <string> chown
%token <string> chgrp
%token <string> ruta


//%token <float> numero
%token FIN 0 "eof"

//Listado de No Terminales
%type <string> INICIO
%type <string> ADMINIST
%type <string> MKPARM
%type <string> FDISK
%type <string> DMOUNT
%type <string> DREP
%type <string> SIMBOL
%type <string> MKFS
%type <string> LOGIN
%type <string> MKUSR
%type <string> MKFILE
%type <string> CHMOD
%type <string> MKDIR
%type <string> MV
%type <string> EDIT
%type <string> REN
%type <string> CHOWN
%type <string> CHGRP



%printer { yyoutput << $$; } <*>;
%%
%start INICIO;

INICIO : ADMINIST {};

ADMINIST :  mkdisk MKPARM MKPARM MKPARM MKPARM                          { mkdisk();}
            |rmdisk path assign pather                                  { path = $4; verificar_comillas(path); rmdisk();}
            |fdisk FDISK FDISK FDISK FDISK FDISK FDISK FDISK            { fdisk();}
            |mount DMOUNT DMOUNT                                        { mount();}
            |unmount id assign idvda                                    { id = $4; unmount();}
            |rep DREP DREP DREP DREP                                    { rep();}
            |exec path assign pather                                    { path = $4; verificar_comillas(path); exec = true;}
            |mkfs MKFS MKFS MKFS                                        { mkfs();}
            |login LOGIN LOGIN LOGIN                                    { login();}
            |logout                                                     { logout();}
            |mkgrp name assign npart                                    { name = $4; verificar_comillas(name); mkgrp();}
            |rmgrp name assign npart                                    { name = $4; verificar_comillas(name); rmgrp();}
            |mkusr MKUSR MKUSR MKUSR                                    { mkusr();}
            |rmusr usr assign npart                                     { usr = $4; verificar_comillas(usr); rmusr(); }
            |mkFile MKFILE MKFILE MKFILE MKFILE                         { mkfile();}
            |cat file assign pather                                     { file = $4; verificar_comillas(file); cat();}
            |mkdir MKDIR MKDIR MKDIR                                    { mkdir();}
            |loss id assign idvda                                       { id = $4; loss();}
            |pause                                                      { pause();}
            |rem path assign pather                                     { path = $4; verificar_comillas(path); remover();}
            |mv MV MV                                                   { mover();}
            |recovery id assign idvda                                   { id = $4; recovery();}
            |ren REN REN                                                { ren(); }
            |find REN REN                                               { find(); }
            |edit EDIT EDIT                                             { printf("\nNo hay metodo definido\n\n"); }
            |cp MV MV                                                   { printf("\nNo hay metodo definido\n\n"); }
            |chmod CHMOD CHMOD CHMOD                                    { printf("\nNo hay metodo definido\n\n"); }
            |chown CHOWN CHOWN CHOWN                                    { printf("\nNo hay metodo definido\n\n"); }
            |chgrp CHGRP CHGRP                                          { printf("\nNo hay metodo definido\n\n"); };

MKPARM :    size assign npart                                           { size = verificate_string($3); /* size = $3; */ }
            |fit assign adj                                             { fit = $3;}
            |unit assign unitl                                          { unit = $3;}
            |path assign pather                                         { path = $3; verificar_comillas(path);}
            |%empty                                                     { $$ = "empty";};

FDISK :     MKPARM
            |typer assign typep                                         { type = $3;}
            |deleter assign tpdelete                                    { tdelete = $3;  }
            |add assign SIMBOL npart                                    { add = verificate_string($4);/* add = $4; */ }
            |name assign npart                                          { name = $3; verificar_comillas(name);};


SIMBOL :    minus                                                       { sign = "menos";}
            |%empty                                                     { sign = "mas";};

DMOUNT :    path assign pather                                          { path = $3; verificar_comillas(path);}
            |name assign npart                                          { name = $3; verificar_comillas(name);};

DREP :      path assign pather                                          { path = $3; verificar_comillas(path);}
            |name assign npart                                          { name = $3; verificar_comillas(name);}
            |id assign idvda                                            { id = $3;}
            |ruta assign pather                                         { ruta = $3; verificar_comillas(ruta);}
            |%empty                                                     { $$ = "empty";};

MKFS :      id assign idvda                                             { id = $3;}
            |typer assign tpdelete                                      { tdelete = $3;}
            |fs assign typartition                                      { set_fs_char($3);}
            |%empty                                                     { $$ = "empty";};

LOGIN :     usr assign npart                                            { usr = $3; verificar_comillas(usr);}
            |pwd assign npart                                           { pwd = $3; verificar_comillas(pwd);}
            |id assign idvda                                            { id = $3;};

MKUSR :     usr assign npart                                            { usr = $3; verificar_comillas(usr);}
            |pwd assign npart                                           { pwd = $3; verificar_comillas(pwd);}
            |grp assign npart                                           { grp = $3; verificar_comillas(grp);};

CHMOD :     path assign pather                                          { path = $3; verificar_comillas(path);}
            |ugo assign npart                                           {}
            |recursive                                                  {}
            |%empty                                                     { $$ = "empty";};

MKFILE :    size assign npart                                           { size = verificate_string($3); /* size = $3; */ }
            |path assign pather                                         { path = $3; verificar_comillas(path);}
            |parametro                                                  { atribp = 's';}
            |cont assign pather                                         { cont = $3; verificar_comillas(cont);}
            |%empty                                                     { $$ = "empty";};

MKDIR :     parametro                                                   { atribp = 's';}
            |id assign idvda                                            { id = $3;}
            |path assign pather                                         { path = $3; verificar_comillas(path);}
            |%empty                                                     { $$ = "empty";};

MV :        path assign pather                                          { path = $3; verificar_comillas(path);}
            |dest assign pather                                         { dest = $3; verificar_comillas(dest);};


EDIT :      path assign pather                                          { path = $3; verificar_comillas(path);}
            |cont assign npart                                          { cont = $3; verificar_comillas(cont);};

REN :       path assign pather                                          { path = $3; verificar_comillas(path);}
            |name assign npart                                          { name = $3; verificar_comillas(name);};

CHOWN :     path assign pather                                          { path = $3; verificar_comillas(path);}
            |recursive
            |usr assign npart                                           { usr = $3; verificar_comillas(usr);};

CHGRP :     usr assign npart                                            { usr = $3; verificar_comillas(usr);}
            |grp assign npart                                           { grp = $3; verificar_comillas(grp);};



%%

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


