#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <cstring>
#include <bits/stdc++.h>

using namespace  std;

typedef struct
{
    char part_status;
    char part_type;
    char part_fit;
    int part_start;
    int part_size;
    char part_name[16];
}Particion;

typedef struct
{
    int mbr_tam;
    char mbr_fecha_creacion[18];
    int mbr_disk_signature;
    char disk_fit;
    Particion mbr_particion[4];
}MBR;

typedef struct
{
    char part_status;
    char part_fit;
    int part_start;
    int part_size;
    int part_next;
    char part_name[16];
}EBR;

typedef struct
{
    string id;
    string name;
    int montadas;
    int part_size;
    char type;
    int direccion;
    string path;
}PM;

PM mounts[26][26];
int maxd = 26, maxp = 26;


string fit = "";
char unit = '*';
string path = "";
string path_copy = "";
char type = '*';
string del = "";
string name = "";
string id = "";
string sign = "";
string tdelete = "";
FILE *f;
FILE *f_copy;
int add = 0;
int size = 0;
int number = 0;
bool exec;

// define vars second fase
int idusuarioactual = -1;
int idgrupoactual = -1;
string idactual = "";
string repfile = "";
bool refil = false;
char fs = '*';
string pwd = "";
string usr = "";
string grp = "";
string cont = "";
string dest = "";
string ruta = "";
string file = "";
int inodomkfj = -1;
int inodon = -1;
int inodop = 0;
int inodos = 0;
char atribp = '*';

// aux vars second fase
char aux_atribp = '*';
string aux_cont = "";
int aux_size = 0;

//Structs Second Fase
typedef struct
{
   int s_filesystem_type;
   int s_inodes_count;
   int s_blocks_count;
   int s_free_blocks_count;
   int s_free_inodes_count;
   char s_mtime[16];
   char s_umtime[16];
   int s_mnt_count;
   int s_magic;
   int s_inode_size;
   int s_block_size;
   int s_first_ino;
   int s_first_blo;
   int s_bm_inode_start;
   int s_bm_block_start;
   int s_inode_start;
   int s_block_start;
}SB;

typedef struct
{
    int i_uid;
    int I_gid;
    int i_size;
    char i_atime[16];
    char i_ctime[16];
    char i_mtime[16];
    int i_block[15];
    char i_type;
    int i_perm;
}INODO;

typedef struct
{
    char b_name[12];
    int b_inode;
}CONTENT;

typedef struct
{
    CONTENT b_content[4];
}BCARPETA;

typedef struct
{
    char b_content[64];
}BARCHIVO;

typedef struct
{
    int b_pointers[16];
}BAPUNTADOR;

typedef struct
{
    char j_time[16];
    int type_trans;
    int type;
    char name[12];
    int propietario;
    int grupo;
    int ipadre;
    char contenido[100];
    int permiso;
}JOURNAL;

//Structs Second Fase

void mkdisk();
void clean_char(char cad[], int tam);
void default_vars();
void unmount_partitions();
void rmdik();
void get_path_copy();
void agregarAparticion(string path);
void sort_array(Particion n[]);
void setEBR(EBR& val);
void setEBR2(EBR& val,int start);
void mount();
void unmount();
void unmount2();
void eliminarParticion(string path);
void setParticion(Particion& val,int start);
void insertaParticion(string path);
void insertaParticionMejor(string path);
void insertaParticionPeor(string path);
void mbr_graph();
void crear_imagen();
void crear_folder();
void disk_graph();
void insertarEBR(EBR& part);
int existepart(int fil);
int existepath();
int pathvacio();
void insertarP(Particion& part);
void init_mounts();

//Methods Second Fase
void mkfs();
void ext(int i, int j);
void fecha(char* fet);
int buscarlibre(char vec[],int tam);
vector<string> split(string input, char separator);
int buscarusuario(string fil);
int buscargrupo(string fil, string grp);
int existegrp(string fil,string grp);
int idgrp(string fil);
void mkgrp();
int guardarCadenaUsers(string fil, FILE* f, SB sb, int dirsb,INODO aux);
void rmgrp();
void copiarS(char destino[],string origen, int caracteres);
void copiar(char destino[],char origen[], int caracteres);
void copiarsinEspacios(char destino[],char origen[], int caracteres);
int buscarvaciojournal(JOURNAL jo[],int tam_jou);
string eliminarUsrGrp(string fil,string usr, char t);
void login();
void logout();
string remplazar(string cad);
void rmgrp();
void mkusr();
int idusr(string fil);
int existeusr(string fil,string usr);
void rmusr();
PM buscarmontada(string idac);;
int loopruta(vector<string> ruta, int posr, int inodoa,SB& sb,FILE* f, char tipo);
void mkdir();
void syncronice();
int crearAC(char tipo,SB& sb, int inodoa,FILE* f,string nombre);
void cat();
void loss();
void recovery();
void syncronice();
void pause();
void setINODO(INODO& ino, char tipoi,int perm);
void setBLOQUEC(BCARPETA& bc, int ipad, int ipro);
void setBLOQUEC2(BCARPETA& bc);
void setBLOQUEA(BARCHIVO& bc);
void setBAPUNTADOR(BAPUNTADOR& ba);
void copy_vars();
void looptree(FILE* f, FILE* file,int nume, int numf,SB sb, INODO in, BARCHIVO ba, BCARPETA bc, BAPUNTADOR bap, int& numtree);
void tree();
void repinodo();
void repbloque();
void repbminodo();
void repbmblock();
void repsb();
void repjournal();
int looprutals(vector<string> ruta, int posr, int inodoa,SB& sb,FILE* f);
int tienepermisolectura(int per, int gid, int uid);
int tienepermisoescritura(int per, int gid, int uid);
int tienepermisoejecucion(int per, int gid, int uid);
void verificarpermisos(char cper[],SB sb,int ia,FILE* f);
void cadpermisos(char cad[],char per);
void buscaruid(char nombre[],int id, int ti, FILE* f, SB sb);
void repls();
int buscarcarpeta(char nombre[], int inodoactual,SB* sb, FILE* f);
int reminodo(int ino, FILE* f,SB sb);
int remblock(int blo, FILE* f,SB sb);
int reminodo2(char* ti, char* tb,int ino, FILE* f,SB sb);
int remblock2(char* ti, char* tb,int blo, FILE* f,SB sb);
int reminodo3(char* ti, char* tb,int ino, FILE* f,SB sb);
int remblock3(char* ti, char* tb,int blo, FILE* f,SB sb);
int buscar_rename(char nombre[], int inodoactual,SB* sb, FILE* f, char nombre_new[]);
bool verificar_carpeta(char name[], int size);
void ren();


void verificar_comillas(string &cadena)
{
    if(cadena.at(0) == '"' )
        cadena = cadena.substr(1, cadena.size() -2);
}

float verificate_string(string numero)
{
    try {
        return stof(numero);
    } catch (exception e) {
        return 0.00;
    }
}

void default_vars()
{
    fit = "";
    unit = '*';
    path = "";
    path_copy = "";
    type = '*';
    del = "";
    name = "";
    id = "";
    sign = "";
    tdelete = "";
    add = 0;
    size = 0;
    number = 0;
    repfile = "";
    fs = '*';
    pwd = "";
    usr = "";
    grp = "";
    cont = "";
    dest = "";
    ruta = "";
    file = "";
    inodomkfj = -1;
    inodon = -1;
    inodop = 0;
    inodos = 0;
    atribp = '*';
    aux_atribp = '*';
    aux_cont = "";
    aux_size = 0;

}

void init_mounts(){
    idusuarioactual = -1;
    idgrupoactual = -1;
    idactual = "";

    exec = false;
    char h[2] = {'a','\0'};
    char s[3] = {'\0','\0','\0'};
    for(int i = 0; i<maxd ; i++)
    {
        for(int j = 0; j<maxp ; j++)
        {
            mounts[i][j].direccion = -1;
            mounts[i][j].montadas = 0;
            mounts[i][j].part_size = 0;
            mounts[i][j].type = '*';
            mounts[i][j].id = "";
            mounts[i][j].name = "";
            h[0] = char(i+97);
            sprintf(s,"%i",j);
            mounts[i][j].id += "vd";
            mounts[i][j].id += h;
            mounts[i][j].id += s;
            mounts[i][j].path = "";
        }
    }
}

void crear_folder()
{
    for (unsigned i = 2; i < path.size()  ; i++) {
        if(path.at(i) == '/')
        {
            FILE *f = fopen(path.substr(0, i).c_str(), "rb");
            if(f == NULL)
            {
                string folder = "mkdir '" + path.substr(0, i) + "'";
                system(folder.c_str());
            }
        }
    }
}

void mkdisk()   // Crear discos
{

    if(path.compare("") != 0 && size > 0)
    {

        crear_folder();
        f = fopen(path.c_str(), "w+b");

        get_path_copy();
        f_copy = fopen(path_copy.c_str(), "w+b");

        if(f == NULL)
            printf("\nNo se pudo crear el archivo\n\n");
        else
        {
            int tam = 0;
            if(unit == '*' || tolower(unit)  == 'm')
                tam = 1024*1024;
            else
                tam = 1024;
            char t[tam];
            for(int i = 0; i < tam; i++)
            {
                t[i] = '\0';
            }

            fseek(f,0,SEEK_SET);
            for(int j = 0; j < size; j++)
            {
                fwrite(&t,sizeof(t),1,f);
            }

            fseek(f_copy,0,SEEK_SET);
            for(int j = 0; j < size; j++)
            {
                fwrite(&t,sizeof(t),1,f_copy);
            }

            MBR att;
            for(int i = 0; i< 4; i++)
            {
                att.mbr_particion[i].part_fit = '*';
                att.mbr_particion[i].part_size = -1;
                att.mbr_particion[i].part_start = 2147483647;
                att.mbr_particion[i].part_status = '*';
                att.mbr_particion[i].part_type = '*';
                clean_char(att.mbr_particion[i].part_name, 16);
            }
            att.mbr_tam = size*tam;
            time_t tiempo = time(0);
            struct tm *tiem = localtime(&tiempo);
            strftime(att.mbr_fecha_creacion, 18, "%d/%m/%Y %H:%M", tiem);

            att.mbr_disk_signature = rand();;
            if(fit.compare("") == 0)
                att.disk_fit = 'f';
            else
                att.disk_fit = tolower(fit.at(0));

            fseek(f,0,SEEK_SET);
            fwrite(&att,sizeof(att),1,f);

            fclose(f);

            fseek(f_copy,0,SEEK_SET);
            att.mbr_disk_signature = rand();;
            fwrite(&att,sizeof(att),1,f_copy);

            fclose(f_copy);
            printf("\nSe creo correctamete el disco en la ruta %s\n\n",path.c_str());
        }
    }else
    {
        printf("\nFaltan campos obligatorios\n\n");
    }
}

void rmdisk()
{
    if(path.compare(""))
    {
        printf("\nDesea Eliminar el Disco %s\n Ingrese [s/n] :  ", path.c_str());
        char confirm = '*';
        while(1)
        {
            confirm = char(getchar());
            if(tolower(confirm) == 's')
                break;
            if(tolower(confirm) == 'n')
                return;
        }
        unmount_partitions();
        int rm = remove(path.c_str());
        if(rm == 0)
        {
            printf("\nSe elimino correctamente el disco ubicado en %s\n\n",path.c_str());
        }else
        {
            printf("\nNo se pudo eliminar correctamente el disco ubicado en %s\n\n",path.c_str());
        }
        path = "";
    }
}

void fdisk()
{
    if(path != "" && name != "")
    {
        if(sign.compare("menos"))
            add = add*-1;

        if(unit == '*' || tolower(unit) == 'k')
        {
            size = size*1024;
            add = add*1024;
        }else if(tolower(unit) == 'm')
        {
            size = size*1024*1024;
            add = add*1024*1024;
        }
        if(type == '*')
            type = 'p';

        type = tolower(type);

        if(fit.compare("") == 0)
            fit = 'w';


        FILE* f = fopen(path.c_str(),"r+b");
        get_path_copy();            
        if(f == NULL)
        {
            printf("\nNo se encontro el disco para su modificacion\n\n");
            return;
        }
        if(tdelete.compare("") != 0)
        {
            printf("\nDesea Eliminar la particion %s en el disco %s\n Ingrese [s/n] :  ", name.c_str(),path.c_str());
            char confirm = '*';
            while(1)
            {
                confirm = char(getchar());
                if(tolower(confirm) == 's')
                    break;
                if(tolower(confirm) == 'n')
                    return;
            }
            eliminarParticion(path);
            if(path_copy.compare("") != 0)
                eliminarParticion(path_copy);
            return;
        }
        if(add != 0)
        {
            agregarAparticion(path);
            if(path_copy.compare("") != 0)
                agregarAparticion(path_copy);
        }
        if(size > 0)
        {
            MBR arr;
            fread(&arr,sizeof(arr),1,f);
            if(type != 'l')
            {
                if(arr.disk_fit == 'f')
                {
                    insertaParticion(path);
                    if(path_copy.compare("") != 0)
                        insertaParticion(path_copy);
                }else if(arr.disk_fit == 'b')
                {
                    insertaParticionMejor(path);
                    if(path_copy.compare("") != 0)
                        insertaParticionMejor(path_copy);
                }else if(arr.disk_fit == 'w')
                {
                    insertaParticionPeor(path);
                    if(path_copy.compare("") != 0)
                        insertaParticionPeor(path_copy);
                }
            }else
            {
                char tp = '*';
                for(int ty = 0; ty <4; ty++)
                {
                    if(arr.mbr_particion[ty].part_type == 'e')
                    {
                        tp = arr.mbr_particion[ty].part_fit;
                        tp = tolower(tp);
                    }
                }
                if(tp == 'f')
                {
                    insertaParticion(path);
                    if(path_copy.compare("") != 0)
                        insertaParticion(path_copy);
                }else if(tp == 'b')
                {
                    insertaParticionMejor(path);
                    if(path_copy.compare("") != 0)
                        insertaParticionMejor(path_copy);
                }else if(tp == 'w')
                {
                    insertaParticionPeor(path);
                    if(path_copy.compare("") != 0)
                        insertaParticionPeor(path_copy);
                }else
                {
                    printf("\nNo se puede agregar la particion logica por que no hay una extendida\n\n");
                }
            }
        }
    }else
    {
        cout << "\nHace falta un parametro obligatorio para poder usar la funcion fdisk\n\n";
    }
}

void clean_char(char cad[], int tam){
    for(int i = 0; i< tam; i++){
        cad[i] = '\0';
    }
}

void get_path_copy()
{
    for (int i = path.size()-1; i > 0  ; i--) {

        if(path.substr(i,i+4).compare("copy") == 0)
        {
            return;
        }else if(path.substr(i,i+5) == ".disk")
        {
            path_copy = path.substr(0,i) + "_ra1.disk";
            break;
        }
    }
}

void agregarAparticion(string path)
{
    FILE* f = fopen(path.c_str(),"rb+");
    char exit = '*';
    if(f == NULL)
    {
        printf("\nError, la ruta del disco a añadir es invalida para la particion %s\n\n",name.c_str());
    }else
    {
        MBR att;
        fread(&att,sizeof(att),1,f);
        sort_array(att.mbr_particion);
        int i = 0;
        for(i = 0; i<4; i++)
        {
            if(strcmp(name.c_str(),att.mbr_particion[i].part_name) == 0)
            {
                if(i<3)
                {
                    if(add > 0)
                    {
                        if(fabs(att.mbr_particion[i+1].part_start-(att.mbr_particion[i].part_start+att.mbr_particion[i].part_size))>=fabs(add))
                        {
                            att.mbr_particion[i].part_size = att.mbr_particion[i].part_size + add;
                            printf("\nSe aumento el tamaño de la particio %s\n\n", name.c_str());
                            break;
                        }else
                        {
                            printf("\nNo se puede modificar el tamaño de la particion %s no se puede expandir, espacio insuficiente\n\n", name.c_str());
                        }
                    }else
                    {
                        if(att.mbr_particion[i].part_size-fabs(add)>0)
                        {
                            att.mbr_particion[i].part_size = att.mbr_particion[i].part_size + add;
                            printf("\nSe disminuyo el tamaño de la particion %s\n\n", name.c_str());
                            break;
                        }
                        else
                        {
                            printf("\nNo se puede modificar el tamaño de la particion %s no se puede reducir, tamaño demasiado grande\n\n",name.c_str());
                        }
                    }

                }else
                {
                    if(add > 0)
                    {
                        if((att.mbr_particion[i].part_start+att.mbr_particion[i].part_size+add)<=fabs(att.mbr_tam))
                        {
                            att.mbr_particion[i].part_size = att.mbr_particion[i].part_size + add;
                            printf("\nSe aumento el tamaño de la particio %s\n\n", name.c_str());
                            break;
                        }else
                        {
                            printf("\nNo se puede modificar el tamaño de la particion %s no se puede expandir, espacio en disco insuficiente\n\n", name.c_str());
                        }
                    }else
                    {
                        if(att.mbr_particion[i].part_size-fabs(add)>0)
                        {
                            att.mbr_particion[i].part_size = att.mbr_particion[i].part_size + add;
                            printf("\nSe aumento el tamaño de la particio %s\n\n", name.c_str());
                            break;
                        }
                        else
                        {
                            printf("No se puede modificar el tamaño de la particion %s no se puede reducir, tamaño demasiado grande\n\n", name.c_str());
                        }
                    }
                }
            }
        }

        if(i != 4)
            exit = 's';
        if(exit == '*')
        {
            for(int j = 0; j < 4 ; j++)
            {
                if(att.mbr_particion[j].part_type == 'e')
                {
                    EBR auxE;
                    fseek(f,att.mbr_particion[j].part_start,SEEK_SET);
                    fread(&auxE,sizeof(auxE),1,f);
                    while(auxE.part_next != -1)
                    {
                        if(strcmp(auxE.part_name,name.c_str()) == 0)
                        {
                            break;
                        }
                        fseek(f,auxE.part_next,SEEK_SET);
                        fread(&auxE,sizeof(auxE),1,f);
                    }

                    if(strcmp(auxE.part_name, name.c_str()) != 0)
                    {
                        printf("\nNo se pudo modificar la particion %s debido a que no se encuentra una con ese nombre\n\n", name.c_str());
                        fclose(f);
                        return;
                    }

                    if(add >0)
                    {
                        if(auxE.part_next != -1)
                        {
                            EBR auxEE;
                            fseek(f,auxE.part_next,SEEK_SET);
                            fread(&auxEE,sizeof(auxEE),1,f);
                            if(auxE.part_start+auxE.part_size+ add < auxEE.part_start)
                            {
                                auxE.part_size = auxE.part_size + add;
                                fseek(f,auxE.part_start,SEEK_SET);
                                fwrite(&auxE,sizeof(auxE),1,f);
                                fclose(f);
                                return;
                            }else
                            {
                                printf("\nNo se puede aumentar el tamaño de la particion %s debido a que no hay espacio libre\n\n", name.c_str());
                                fclose(f);
                                return;
                            }
                        }else
                        {

                            if((auxE.part_start+auxE.part_size+ add) < (att.mbr_particion[j].part_start +att.mbr_particion[j].part_size))
                            {
                                auxE.part_size = auxE.part_size + add;
                                fseek(f,auxE.part_start,SEEK_SET);
                                fwrite(&auxE,sizeof(auxE),1,f);
                                fclose(f);
                                return;
                            }else
                            {
                                printf("\nNo se puede aumentar el tamaño de la particion %s debido a que no hay espacio libre\n\n", name.c_str());
                                fclose(f);
                                return;
                            }
                        }

                    }else
                    {
                        if(auxE.part_size + add > 0)
                        {
                            auxE.part_size = auxE.part_size + add;
                            fseek(f,auxE.part_start,SEEK_SET);
                            fwrite(&auxE,sizeof(auxE),1,f);
                            fclose(f);
                            return;

                        }else
                        {
                            printf("\nError no se puede reducir tanto espacio a la particion\n\n");
                            fclose(f);
                            return;
                        }
                    }
                }

            }
        }

        if(exit == '*')
        {
            printf("\nNo se encontro la particion %s para su modificacion\n\n",name.c_str());
        }
        sort_array(att.mbr_particion);
        fseek(f,0,SEEK_SET);
        fwrite(&att,sizeof(att),1,f);
        fclose(f);
    }

}

void sort_array(Particion n[])
{
    Particion aux;
    for(int i=1; i<4; i++)
    {
        for(int j=0; j<4-i; j++)
        {
            if(n[j].part_start > n[j+1].part_start)
            {
                aux    = n[j+1];
                n[j+1] = n[j];
                n[j]   = aux;
            }
        }
    }
}

void eliminarParticion(string path)
{

    FILE* f = fopen(path.c_str(),"rb+");
    char exit = '*';
    if(f == NULL)
    {
        printf("\nError, la ruta para eliminar la particion %s es invalida\n\n",name.c_str());
    }else
    {
        MBR att;
        fread(&att,sizeof(att),1,f);
        sort_array(att.mbr_particion);
        for(int i = 0; i<4; i++)
        {
            if(strcmp(name.c_str(),att.mbr_particion[i].part_name) == 0)
            {
                char fr = '\0';
                if(tdelete.compare("full"))
                {
                    for(int ty = 0; ty< att.mbr_particion[i].part_size; ty++)
                    {
                        fseek(f,att.mbr_particion[i].part_start+ty,SEEK_SET);
                        fwrite(&fr,sizeof(fr),1,f);
                    }
                }
                unmount2();
                att.mbr_particion[i].part_fit = ' ';
                clean_char(att.mbr_particion[i].part_name,16);
                att.mbr_particion[i].part_size = -1;
                att.mbr_particion[i].part_start = 2147483647;
                att.mbr_particion[i].part_status = 'n';
                att.mbr_particion[i].part_type = 'v';
                printf("\nparticion Eliminada: %s\n\n",name.c_str());
                exit = 's';

            }
        }
        if(exit == '*')
            for(int i = 0; i < 4; i++)
            {
                if(att.mbr_particion[i].part_type == 'e')
                {
                    EBR aux, aux2;
                    fseek(f,att.mbr_particion[i].part_start,SEEK_SET);
                    fread(&aux2,sizeof(aux2),1,f);
                    setEBR(aux);
                    if(aux2.part_next != -1 && strcmp(aux2.part_name,name.c_str()) != 0)
                    {
                        aux = aux2;
                        fseek(f,aux2.part_next,SEEK_SET);
                        fread(&aux2,sizeof(aux2),1,f);
                    }
                    while(aux2.part_next != -1)
                    {
                        if(strcmp(aux2.part_name,name.c_str()) == 0)
                        {
                            break;
                        }
                        aux = aux2;
                        fseek(f,aux2.part_next,SEEK_SET);
                        fread(&aux2,sizeof(aux2),1,f);
                    }
                    if(strcmp(aux2.part_name,name.c_str()) == 0)
                    {
                        if(aux.part_size != -1)
                        {
                            aux.part_next = aux2.part_next;
                            unmount2();
                            fseek(f,aux.part_start,SEEK_SET);
                            fwrite(&aux,sizeof(aux),1,f);

                            fseek(f,aux2.part_start,SEEK_SET);
                            if(tdelete.compare("full"))
                            {
                                int ggg = sizeof(aux2);

                                for(int n = 0; n<ggg ; n++)
                                {
                                    fwrite("\0",sizeof(char),1,f);
                                }
                            }

                            printf("\nparticion Eliminada: %s\n\n",name.c_str());
                            exit = 's';
                        }else
                        {
                            unmount2();
                            int nexxt = aux2.part_next;
                            fseek(f,aux2.part_start,SEEK_SET);
                            setEBR(aux2);
                            aux2.part_next = nexxt;
                            fwrite(&aux2,sizeof(aux2),1,f);
                            printf("\nparticion Eliminada: %s\n\n",name.c_str());
                            exit = 's';

                        }
                    }


                }
            }
        if(exit == '*')
        {
            printf("\nLa particion %s no se encontro para su eliminacion, nombre invalido.\n\n",name.c_str());
        }
        sort_array(att.mbr_particion);
        fseek(f,0,SEEK_SET);
        fwrite(&att,sizeof(att),1,f);
        fclose(f);
    }
}

void setEBR(EBR& val)
{
    val.part_status = '*';
    val.part_fit = '*';
    val.part_start = -1;
    val.part_size = -1;
    val.part_next = -1;
    clean_char(val.part_name,16);
}

void setEBR2(EBR& val,int start)
{
    val.part_status = 'n';
    val.part_fit = fit.at(0);
    val.part_start = start;
    val.part_size = size;
    val.part_next = -1;
    clean_char(val.part_name,16);
    strcat(val.part_name,name.c_str());
}

void mount()
{
    if(path.compare("") == 0 || name.compare("") == 0)
    {
        printf("\nUn campo obligatorio para usar la funcion mount no a sido definido\n\n");
        return;
    }

    FILE* f = fopen(path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nNo se encontro el disco en la ruta %s para montar la particion %s\n\n", path.c_str(), name.c_str());

    }else
    {
        fseek(f,0,SEEK_SET);
        MBR aux;
        EBR auxE;
        fread(&aux,sizeof(aux),1,f);
        int t = 0,ext = -1;
        char rtr[16];
        for(t = 0; t<4 ; t++)
        {
            if(aux.mbr_particion[t].part_type == 'e')
            {
                ext = t;
            }
            clean_char(rtr,16);
            strcat(rtr,aux.mbr_particion[t].part_name);
            if(strcmp(aux.mbr_particion[t].part_name,name.c_str()) == 0)
            {
                break;
            }
        }
        if(t == 4)
        {
            if(ext == -1)
            {
                printf("\nError no se encontro la particion %s para montarla\n\n",name.c_str());
                fclose(f);
                return;
            }
            fseek(f,aux.mbr_particion[ext].part_start,SEEK_SET);
            fread(&auxE,sizeof(auxE),1,f);
            while(auxE.part_next != -1)
            {
                if(strcmp(auxE.part_name,name.c_str()) == 0)
                {
                    break;
                }
                fseek(f,auxE.part_next,SEEK_SET);
                fread(&auxE,sizeof(auxE),1,f);
            }

            if(strcmp(auxE.part_name,name.c_str()) != 0)
            {
                printf("\nError no se encontro la particion %s para montarla\n\n",name.c_str());
                fclose(f);
                return;
            }
            insertarEBR(auxE);

            auxE.part_status = 'm';
            fseek(f,auxE.part_start,SEEK_SET);
            fwrite(&auxE,sizeof(auxE),1,f);

            fclose(f);
            return;
        }else
        {
            insertarP(aux.mbr_particion[t]);

            aux.mbr_particion[t].part_status = 'm';
            fseek(f,0,SEEK_SET);
            fwrite(&aux,sizeof(aux),1,f);

            fclose(f);
            return;
        }
    }
}

void insertarEBR(EBR& part)
{
    int e = existepath();
    int v = 0;
    if(e == -1)
    {
        v = pathvacio();
        if(v == -1)
        {
            printf("\nError no se pueden agregar nuevas particiones\n\n");
            return;
        }
        int l = existepart(v);
        if(l != -1)
        {
            mounts[v][l].direccion = part.part_start;
            mounts[v][l].part_size = part.part_size;
            mounts[v][l].name = name;
            if(strcmp(mounts[v][l].path.c_str(),"") == 0)
            {
                mounts[v][l].path = path;
            }
            if(strcmp(mounts[v][0].path.c_str(),"") == 0)
            {
                mounts[v][0].path = path;
            }
            mounts[v][l].type = 'l';
            mounts[v][0].montadas = mounts[v][0].montadas + 1;
            printf("\nSe monto la particion correctamente\n\n");
            return;
        }

    }else
    {
        int l = existepart(e);
        if(l != -1)
        {
            mounts[e][l].direccion = part.part_start;
            mounts[e][l].part_size = part.part_size;
            mounts[e][l].name = name;
            if(strcmp(mounts[e][l].path.c_str(),"") == 0)
            {
                mounts[e][l].path = path;
            }
            mounts[e][l].type = 'l';
            mounts[e][0].montadas = mounts[e][0].montadas + 1;
            printf("\nSe monto la particion %s correctamente\n\n",name.c_str());
            return;
        }
    }

}

void insertarP(Particion& part)
{
    int e = existepath();
    int v = 0;
    if(e == -1)
    {
        v = pathvacio();
        if(v == -1)
        {
            printf("\nError no se pueden agregar nuevas particiones\n\n");
            return;
        }
        int l = existepart(v);
        if(l != -1)
        {
            mounts[v][l].direccion = part.part_start;
            mounts[v][l].part_size = part.part_size;
            mounts[v][l].name = name;
            if(strcmp(mounts[v][l].path.c_str(),"") == 0)
            {
                mounts[v][l].path = path;
            }
            if(strcmp(mounts[v][0].path.c_str(),"") == 0)
            {
                mounts[v][0].path = path;
            }
            mounts[v][l].type = part.part_type;
            mounts[v][0].montadas = mounts[v][0].montadas + 1;
            printf("\nSe monto la particion correctamente\n\n");
            return;
        }

    }else
    {
        int l = existepart(e);
        if(l != -1)
        {
            mounts[e][l].direccion = part.part_start;
            mounts[e][l].part_size = part.part_size;
            mounts[e][l].name = name;
            if(strcmp(mounts[e][l].path.c_str(),"") == 0)
            {
                mounts[e][l].path = path;
            }
            mounts[e][l].type = part.part_type;
            mounts[e][0].montadas = mounts[e][0].montadas + 1;
            printf("\nSe monto la particion correctamente\n\n");
            return;
        }
    }

}

int existepart(int fil)
{
    for(int j = 1; j<maxp ; j++)
    {
        if(name.compare(mounts[fil][j].name) == 0)
        {
            printf("\nLa particion %s ya fue montada anteriormente\n\n",name.c_str());
            return -1;
        }
    }
    for(int j = 1; j<maxp ; j++)
    {
        if(mounts[fil][j].direccion == -1)
        {
            return j;
        }
    }
    printf("\nError no se pueden agregar nuevas particiones\n\n");
    return -1;
}

int existepath()
{
    for(int i = 0; i<maxd ; i++)
    {
        if(path.compare(mounts[i][0].path) == 0)
        {
            return i;
        }
    }
    return -1;
}

int pathvacio()
{
    for(int i = 0; i<maxd ; i++)
    {
        if(mounts[i][0].path.compare("") == 0)
        {
            return i;
        }
    }
    return -1;
}

void unmount()
{
    int i = 0;
    int j = 0;
    if(id[0] != 'v' || id[1] != 'd')
    {
        printf("\nEl id de la particion montada es invalido\n\n");
        return;
    }
    for(i = 0; i<maxd ; i++)
    {
        for(j = 0; j<maxp ; j++)
        {
            if(mounts[i][j].id == id)
            {
                if(mounts[i][j].direccion == -1)
                {
                    printf("\nNo se puede demontar la particion %s por que aun no ha sido montada\n\n",id.c_str());
                    return;
                }
                if(mounts[i][j].type == 'l')
                {
                    EBR eb;
                    FILE* f = fopen(mounts[i][j].path.c_str(),"r+b");
                    fseek(f,mounts[i][j].direccion,SEEK_SET);
                    fread(&eb,sizeof(eb),1,f);
                    eb.part_status = 'n';
                    fseek(f,mounts[i][j].direccion,SEEK_SET);
                    fwrite(&eb,sizeof(eb),1,f);
                    fclose(f);
                }else
                    if(mounts[i][j].type == 'p')
                    {
                        MBR eb;
                        FILE* f = fopen(mounts[i][j].path.c_str(),"r+b");
                        fseek(f,0,SEEK_SET);
                        fread(&eb,sizeof(eb),1,f);
                        for(int ty = 0; ty<4 ; ty++)
                        {
                            if(strcmp(mounts[i][j].name.c_str(),eb.mbr_particion[ty].part_name) == 0)
                            {
                                eb.mbr_particion[ty].part_status = 'n';
                            }
                        }

                        fseek(f,0,SEEK_SET);
                        fwrite(&eb,sizeof(eb),1,f);
                        fclose(f);
                    }
                mounts[i][j].direccion = -1;
                mounts[i][j].name = "";
                if(j != 0)
                {
                    mounts[i][j].path = "";

                }

                mounts[i][0].montadas--;
                if(mounts[i][0].montadas == 0)
                {
                    mounts[i][0].path = "";

                }
                printf("\nSe desmonto correctamente la particion %s\n\n",id.c_str());
                return;
            }
        }
    }
    if(j == maxp && i == maxd)
    {
        printf("\nNo se pudo desmontar la particion %s no se encontro la particion\n\n",name.c_str());
    }
}

void unmount2()
{
    for(int i = 0; i<maxd ; i++)
    {
        if(strcmp(path.c_str(),mounts[i][0].path.c_str()) == 0)
        {
            for(int j = 0; j<maxp ; j++)
            {
                if(strcmp(mounts[i][j].name.c_str(), name.c_str()) == 0)
                {
                    mounts[i][j].direccion = -1;
                    mounts[i][j].part_size = 0;
                    mounts[i][j].type = '*';
                    mounts[i][j].name = "";
                    if(j != 0)
                        mounts[i][j].path = "";
                    mounts[i][0].montadas--;
                    if(mounts[i][0].montadas == 0)
                        mounts[i][0].path = "";
                    printf("\nSe desmonto correctamente la particion %s\n\n",name.c_str());
                    return;
                }
            }
        }
    }
}

void unmount_partitions()
{
    for(int i = 0 ; i < maxd ; i++)
    {
        if(path == mounts[i][0].path)
        {
            for(int j = 0; j < maxp ; j++)
            {
                mounts[i][j].direccion = -1;
                mounts[i][j].montadas = 0;
                mounts[i][j].part_size = 0;
                mounts[i][j].type = '*';
                mounts[i][j].name = "";
                mounts[i][j].path = "";
            }
            printf("\nSe desmontaron con exito todas las particiones\n\n");
            break;
        }
    }
}

void insertaParticion(string path)
{
    FILE* f = fopen(path.c_str(),"r+b");
    int result = 0;
    if(f == NULL)
    {
        printf("\nNo se encontro el disco para su modificacion\n\n");

    }else
    {
        MBR arr;
        EBR aux;
        fread(&arr,sizeof(arr),1,f);
        sort_array(arr.mbr_particion);
        int c = 0;
        int v = 0;
        int e = 0;
        for(int i = 0; i<4; i++)
        {
            if(strcmp(arr.mbr_particion[i].part_name,name.c_str()) == 0)
            {
                printf("\nNo se pudo crear la particion %s debido a que ya se encuentra una con ese nombre\n\n",name.c_str());
                fclose(f);
                return;
            }
        }
        for(int i = 0; i<4;i++)
        {
            if(arr.mbr_particion[i].part_start != 2147483647)
            {
                c = c + 1;
            }else
            {
                v = v + 1;
            }
            if(arr.mbr_particion[i].part_type == 'e')
            {
                e = e +1;
            }
        }
        if(e > 0 && type == 'e')
        {
            printf("\nYa exite una particion extendida no se pueden crear mas, no se creo %s\n\n",name.c_str());
        }else if(type == 'l')
        {
            int m = -1;
            for(m = 0; m<4; m++)
            {
                if(arr.mbr_particion[m].part_type == 'e')
                {
                    break;
                }
            }
            if(m != 4)
            {
                fseek(f,arr.mbr_particion[m].part_start,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);
                int start_aux = aux.part_start;
                start_aux = aux.part_next;
                int ant = aux.part_size+aux.part_start;
                int an = aux.part_start;

                EBR  auxx;
                fseek(f,arr.mbr_particion[m].part_start,SEEK_SET);
                fread(&auxx,sizeof(auxx),1,f);
                while(auxx.part_next != -1)
                {
                    if(strcmp(auxx.part_name,name.c_str()) == 0)
                    {
                        printf("\nNo se pudo crear la particion logica %s debido a que ya se encuentra una con ese nombre\n\n",name.c_str());
                        fclose(f);
                        return;
                    }
                    fseek(f,auxx.part_next,SEEK_SET);
                    fread(&auxx,sizeof(auxx),1,f);
                }
                while(start_aux != -1)
                {
                    if(aux.part_size == -1)
                    {
                        if(aux.part_next != -1 && aux.part_size == -1)
                        {
                            int rrr = aux.part_next;
                            fseek(f,arr.mbr_particion[m].part_start,SEEK_SET);
                            setEBR2(aux,arr.mbr_particion[m].part_start);
                            aux.part_next = rrr;
                            fwrite(&aux,sizeof(aux),1,f);
                            fclose(f);
                            printf("\nSe agrego la particion logica %s\n\n",name.c_str());
                            return;
                        }
                    }
                    if(ant != -2 && aux.part_start-ant >= size)
                    {
                        fseek(f,an,SEEK_SET);
                        fread(&aux,sizeof(aux),1,f);
                        aux.part_next = ant;
                        fwrite(&aux,sizeof(aux),1,f);
                        setEBR2(aux,ant);
                        fseek(f,ant,SEEK_SET);
                        fwrite(&aux,sizeof(aux),1,f);
                        fclose(f);
                        printf("\nSe agrego la particion logica %s\n\n",name.c_str());
                        return;
                    }
                    ant = aux.part_size+aux.part_start;
                    an = aux.part_start;
                    fseek(f,aux.part_next,SEEK_SET);
                    fread(&aux,sizeof(aux),1,f);
                    start_aux = aux.part_next;
                }
                if(strcmp(aux.part_name,name.c_str()) == 0)
                {
                    printf("\nNo se pudo crear la particion logica %s debido a que ya se encuentra una con ese nombre\n\n",name.c_str());
                    fclose(f);
                    return;
                }

                if(ant != -2 && aux.part_start-ant >= size)
                {
                    int nexxt = aux.part_start;

                    fseek(f,an,SEEK_SET);
                    fread(&aux,sizeof(aux),1,f);

                    aux.part_next = ant;

                    fseek(f,an,SEEK_SET);
                    fwrite(&aux,sizeof(aux),1,f);

                    setEBR2(aux,ant);
                    aux.part_next = nexxt;

                    fseek(f,ant,SEEK_SET);
                    fwrite(&aux,sizeof(aux),1,f);

                    fclose(f);
                    printf("\nSe agrego la particion logica %s\n\n",name.c_str());
                    return;
                }
                if(aux.part_size != -1)
                {
                    result = arr.mbr_particion[m].part_start+arr.mbr_particion[m].part_size-aux.part_start-aux.part_size;
                    if( result < size)
                    {
                        printf("\nNo se pudo agregar la particion logica %s por que ya no hay espacio en la extendida\n\n",name.c_str());
                        return;
                    }

                    int next = aux.part_start+aux.part_size;
                    int start = aux.part_start;
                    aux.part_next = next;
                    fseek(f,start,SEEK_SET);
                    fwrite(&aux,sizeof(aux),1,f);
                    EBR aux2;
                    setEBR2(aux2,next);
                    fseek(f,next,SEEK_SET);
                    fwrite(&aux2,sizeof(aux2),1,f);
                    fclose(f);
                }else
                {
                    int sss = arr.mbr_particion[m].part_start;
                    setEBR2(aux,sss);

                    fseek(f,sss,SEEK_SET);
                    fwrite(&aux,sizeof(aux),1,f);
                    fclose(f);
                }

                printf("\nSe agrego la particion logica %s\n\n",name.c_str());
            }else
            {
                printf("\nError no hay una particion extendida para crear la particion logica %s\n\n",name.c_str());
            }
        }else
        {
            if(c == 4)
            {
                printf("\nNo se pueden crear mas particiones primarias o extendidas, no se creo %s\n\n",name.c_str());
            }else
            {
                if(v == 4)
                {
                    int jj = arr.mbr_tam-sizeof(arr);
                    if(jj >= size)
                    {
                        setParticion(arr.mbr_particion[0],sizeof(arr));
                        if(type == 'e')
                        {

                            setEBR(aux);
                            fseek(f,sizeof(arr),SEEK_SET);
                            fwrite(&aux,sizeof(aux),1,f);
                        }
                        cout << "\nparticion ingresada: " << arr.mbr_particion[0].part_name << "\n\n";
                    }else
                    {
                        cout << "\nEl espacio libre es insuficiente para agregar la particion " << name.c_str() << "\n\n";
                        return;
                    }

                }else
                {

                    for(int i = 0; i< 4; i++)
                    {
                        if(arr.mbr_particion[i].part_start != 2147483647)
                        {
                            if(i == 0)
                            {
                                if(arr.mbr_particion[i].part_start-sizeof(arr) >= unsigned(size))
                                {
                                    for(int j = i+1; j< 4;j++)
                                    {
                                        if(arr.mbr_particion[j].part_start == 2147483647)
                                        {
                                            setParticion(arr.mbr_particion[j],sizeof(arr));
                                            if(type == 'e')
                                            {
                                                setEBR(aux);
                                                fseek(f,sizeof(arr),SEEK_SET);
                                                fwrite(&aux,sizeof(aux),1,f);
                                            }
                                            sort_array(arr.mbr_particion);
                                            cout << "\nparticion ingresada: " << arr.mbr_particion[j].part_name << "\n\n";
                                            fseek(f,0,SEEK_SET);
                                            fwrite(&arr,sizeof(arr),1,f);
                                            fclose(f);
                                            return;
                                        }
                                    }
                                }

                            }else if(i == 3)
                            {
                                if(arr.mbr_tam-(arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size)>=size)
                                {
                                    setParticion(arr.mbr_particion[i],arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size);
                                    if(type == 'e')
                                    {
                                        setEBR(aux);
                                        fseek(f,arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size,SEEK_SET);
                                        fwrite(&aux,sizeof(aux),1,f);
                                    }
                                    sort_array(arr.mbr_particion);
                                    cout << "\nparticion ingresada: " << arr.mbr_particion[i].part_name << "\n\n";
                                    fseek(f,0,SEEK_SET);
                                    fwrite(&arr,sizeof(arr),1,f);
                                    fclose(f);
                                    return;
                                }
                            }else
                            {
                                if(arr.mbr_particion[i].part_start-(arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size)>=size)
                                {
                                    for(int j = i+1; j< 4;j++)
                                    {
                                        if(arr.mbr_particion[j].part_start == 2147483647)
                                        {
                                            setParticion(arr.mbr_particion[j],arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size);
                                            if(type == 'e')
                                            {
                                                setEBR(aux);
                                                fseek(f,arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size,SEEK_SET);
                                                fwrite(&aux,sizeof(aux),1,f);
                                            }
                                            sort_array(arr.mbr_particion);
                                            cout << "\nparticion ingresada: " << arr.mbr_particion[j].part_name << "\n\n";
                                            fseek(f,0,SEEK_SET);
                                            fwrite(&arr,sizeof(arr),1,f);
                                            fclose(f);
                                            return;
                                        }
                                    }
                                }
                            }
                        }else
                        {
                            if(arr.mbr_tam-(arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size)>=size)
                            {
                                setParticion(arr.mbr_particion[i],arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size);
                                if(type == 'e')
                                {
                                    setEBR(aux);
                                    fseek(f,arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size,SEEK_SET);
                                    fwrite(&aux,sizeof(aux),1,f);
                                }
                                sort_array(arr.mbr_particion);
                                cout << "\nparticion ingresada: " << arr.mbr_particion[i].part_name << "\n\n";
                                fseek(f,0,SEEK_SET);
                                fwrite(&arr,sizeof(arr),1,f);
                                fclose(f);
                                return;
                            }
                        }
                    }
                }

            }
            fseek(f,0,SEEK_SET);
            fwrite(&arr,sizeof(arr),1,f);
            fclose(f);

        }

    }

}

void insertaParticionMejor(string path)
{
    FILE* f = fopen(path.c_str(),"r+b");
    int tam = 2147483647;
    int propuesta = -1;
    if(f == NULL)
    {
        printf("\nNo se encontro el disco para su modificacion\n");

    }else
    {
        MBR arr;
        EBR aux;
        fread(&arr,sizeof(arr),1,f);
        sort_array(arr.mbr_particion);

        if(type == 'e' || type == 'p')
        {
            for(int i = 0; i<4 ; i++)
            {
                if(arr.mbr_particion[i].part_type == 'e' && type == 'e')
                {
                    printf("\nError ya no se pueden agragar mas particiones extendidas\n\n");
                    fclose(f);
                    return;
                }
            }

            for(int i = 0; i<4 ; i++)
            {
                if(strcmp(arr.mbr_particion[i].part_name,name.c_str()) == 0)
                {
                    printf("\nError la particion ya existe no se puede crear nuevamente\n\n");
                    fclose(f);
                    return;
                }
            }
            int i = 0;
            for(i = 0; i<4 ; i++)
            {
                if(arr.mbr_particion[i].part_size == -1)
                {
                    break;
                }
            }

            if(i == 4)
            {
                printf("\nError ya no se pueden agragar mas particiones\n\n");
                fclose(f);
                return;
            }



            for(i = 0; i<4; i++)
            {
                if(i == 0)
                {
                    if(arr.mbr_particion[i].part_start != 2147483647)
                    {
                        if(arr.mbr_particion[i].part_start - sizeof(arr) >= unsigned(size))
                        {
                            tam = arr.mbr_particion[i].part_start - sizeof(arr);
                            propuesta = sizeof(arr);
                        }
                    }else
                    {
                        if(unsigned(size) > arr.mbr_tam - sizeof(arr))
                        {
                            printf("\nError, tamaño de la particion: %s nueva no valida, no se inserto la particion.\n\n",name.c_str());
                            return;
                        }
                        setParticion(arr.mbr_particion[i],sizeof(arr));
                        printf("\nSe inserto correctamente la particion %s\n\n",name.c_str());
                        if(type == 'e')
                        {

                            setEBR(aux);
                            fseek(f,sizeof(arr),SEEK_SET);
                            fwrite(&aux,sizeof(aux),1,f);
                        }
                        sort_array(arr.mbr_particion);
                        fseek(f,0,SEEK_SET);
                        fwrite(&arr,sizeof(arr),1,f);
                        fclose(f);
                        return;
                        break;
                    }
                }else if(i == 3)
                {
                    if(arr.mbr_particion[i].part_start == 2147483647)
                    {

                        break;
                    }else
                    {
                        printf("\nNo se pueden agregar mas particiones primarias o extendidas.\n\n");
                        return;
                    }
                }else
                {
                    if(arr.mbr_particion[i].part_start != 2147483647)
                    {
                        if(arr.mbr_particion[i].part_start - (arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size) >= size)
                        {
                            if(arr.mbr_particion[i].part_start - (arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size) < tam)
                            {
                                tam = arr.mbr_particion[i].part_start - (arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size);
                                propuesta = arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size;
                            }

                        }
                    }else
                    {

                        break;
                    }
                }
            }
            if(size > arr.mbr_tam - (arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size))
            {
                printf("\nError, tamaño de la particion: %s nueva no valida, no se inserto la particion.\n\n",name.c_str());
                return;
            }
            if(arr.mbr_tam -(arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size) < tam)
            {
                tam = arr.mbr_tam -(arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size);
                propuesta = arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size;
            }
            setParticion(arr.mbr_particion[i],propuesta);
            printf("\nSe inserto correctamente la particion %s\n\n",name.c_str());
            if(type == 'e')
            {

                setEBR(aux);
                fseek(f,propuesta,SEEK_SET);
                fwrite(&aux,sizeof(aux),1,f);
            }
            sort_array(arr.mbr_particion);
            fseek(f,0,SEEK_SET);
            fwrite(&arr,sizeof(arr),1,f);
            fclose(f);
            return;
        }else
        {
            int i = 0;
            for(i = 0; i<4 ; i++)
            {
                if(arr.mbr_particion[i].part_type == 'e')
                {
                    break;
                }
            }

            if(i == 4)
            {
                printf("\nError no se puede agregar la particion logica %s por que no hay una extendida\n\n",name.c_str());
                fclose(f);
                return;
            }
            EBR aux2;
            EBR aux3;
            fseek(f,arr.mbr_particion[i].part_start,SEEK_SET);
            fread(&aux,sizeof(aux),1,f);
            char ii = '*';
            while(aux.part_next != -1)
            {
                if(strcmp(name.c_str(),aux.part_name) == 0)
                {
                    printf("\nNo se puede insertar la particion, ya existe\n\n");
                    return;
                }
                fseek(f,aux.part_next,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);
            }
            if(strcmp(name.c_str(),aux.part_name) == 0)
            {
                printf("\nNo se puede insertar la particion, ya existe\n\n");
                return;
            }
            fseek(f,arr.mbr_particion[i].part_start,SEEK_SET);
            fread(&aux,sizeof(aux),1,f);
            if(aux.part_size == -1 && aux.part_next != -1)
            {
                fseek(f,aux.part_next,SEEK_SET);
                fread(&aux2,sizeof(aux2),1,f);
                if(aux2.part_start-(arr.mbr_particion[i].part_start) >= size)
                {
                    if(aux2.part_start-(arr.mbr_particion[i].part_start) < tam)
                    {
                        tam = aux2.part_start-(arr.mbr_particion[i].part_start);
                        propuesta = arr.mbr_particion[i].part_start;
                    }

                }
            }
            if(aux.part_size != -1 && aux.part_next == -1)
            {
                fseek(f,aux.part_start+aux.part_size,SEEK_SET);
                setEBR2(aux2,aux.part_start+aux.part_size);
                fwrite(&aux2,sizeof(aux2),1,f);
                aux.part_next = aux2.part_start;
                fseek(f,aux.part_start,SEEK_SET);
                fwrite(&aux,sizeof(aux),1,f);
                ii = 'S';
            }
            if(aux.part_size == -1 && aux.part_next == -1)
            {
                fseek(f,arr.mbr_particion[i].part_start,SEEK_SET);
                setEBR2(aux,arr.mbr_particion[i].part_start);
                fwrite(&aux,sizeof(aux),1,f);
                ii = 'S';
            }
            if(ii == '*')
            {
                while(aux.part_next != -1)
                {
                    if(aux.part_next != -1)
                    {
                        fseek(f,aux.part_next,SEEK_SET);
                        fread(&aux2,sizeof(aux2),1,f);
                        if(aux.part_size == -1 && aux.part_start == -1)
                        {
                            if(aux2.part_start-arr.mbr_particion[i].part_start >= size)
                            {
                                if(aux2.part_start-arr.mbr_particion[i].part_start < tam)
                                {
                                    tam = aux2.part_start-arr.mbr_particion[i].part_start;
                                    propuesta = arr.mbr_particion[i].part_start;
                                }
                            }
                        }else
                            if(aux2.part_start-(aux.part_start+aux.part_size) >= size)
                            {
                                if(aux2.part_start-(aux.part_start+aux.part_size) < tam)
                                {
                                    tam = aux2.part_start-(aux.part_start+aux.part_size);
                                    propuesta = aux.part_start;
                                }

                            }
                    }else
                    {
                        fseek(f,aux.part_next,SEEK_SET);
                        fread(&aux,sizeof(aux),1,f);
                        break;
                    }
                    fseek(f,aux.part_next,SEEK_SET);
                    fread(&aux,sizeof(aux),1,f);
                }
            }

            if(aux.part_size != -1 && ii == '*')
            {
                if((arr.mbr_particion[i].part_size+arr.mbr_particion[i].part_start)-(aux.part_start+aux.part_size) >= size)
                {
                    if( (arr.mbr_particion[i].part_size+arr.mbr_particion[i].part_start)-(aux.part_start+aux.part_size) < tam)
                    {
                        tam = (arr.mbr_particion[i].part_size+arr.mbr_particion[i].part_start)-(aux.part_start+aux.part_size);
                        propuesta = aux.part_start;
                    }

                }
            }

            if(propuesta != -1 && ii == '*')
            {
                fseek(f,propuesta,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);
                if(aux.part_next != -1 && aux.part_size != -1)
                {
                    fseek(f,aux.part_next,SEEK_SET);
                    fread(&aux2,sizeof(aux2),1,f);
                    setEBR2(aux3,aux.part_size+aux.part_start);
                    aux3.part_next = aux.part_next;
                    aux.part_next = aux3.part_start;

                    fseek(f,aux.part_start,SEEK_SET);
                    fwrite(&aux,sizeof(aux),1,f);

                    fseek(f,aux2.part_start,SEEK_SET);
                    fwrite(&aux2,sizeof(aux2),1,f);

                    fseek(f,aux3.part_start,SEEK_SET);
                    fwrite(&aux3,sizeof(aux3),1,f);

                    fseek(f,propuesta,SEEK_SET);
                    fread(&aux,sizeof(aux),1,f);

                }else if(aux.part_next != -1 && aux.part_start == -1)
                {
                    int t = aux.part_next;
                    setEBR2(aux,propuesta);
                    fseek(f,propuesta,SEEK_SET);
                    aux.part_next = t;
                    fwrite(&aux,sizeof(aux),1,f);
                }else
                {
                    setEBR2(aux2,aux.part_start+aux.part_size);
                    aux.part_next = aux2.part_start;

                    fseek(f,aux2.part_start,SEEK_SET);
                    fwrite(&aux2,sizeof(aux2),1,f);

                    fseek(f,aux.part_start,SEEK_SET);
                    fwrite(&aux,sizeof(aux),1,f);
                }
                ii = 'S';
            }
            if(ii != '*')
            {
                printf("Se inserto correctamente la particion logica %s\n",name.c_str());
                fclose(f);
                return;
            }

        }
    }
}

void insertaParticionPeor(string path)
{
    FILE* f = fopen(path.c_str(),"r+b");
    int tam = 0;
    int propuesta = -1;
    if(f == NULL)
    {
        printf("\nNo se encontro el disco para su modificacion\n");

    }else
    {
        MBR arr;
        EBR aux;
        fread(&arr,sizeof(arr),1,f);
        sort_array(arr.mbr_particion);
        if(type == 'e' || type == 'p')
        {
            for(int i = 0; i<4 ; i++)
            {
                if(arr.mbr_particion[i].part_type == 'e' && type == 'e')
                {
                    printf("\nError ya no se pueden agragar mas particiones extendidas\n\n");
                    fclose(f);
                    return;
                }
            }

            for(int i = 0; i<4 ; i++)
            {
                if(strcmp(arr.mbr_particion[i].part_name,name.c_str()) == 0)
                {
                    printf("\nError la particion ya existe no se puede crear nuevamente\n\n");
                    fclose(f);
                    return;
                }
            }
            int i = 0;
            for(i = 0; i<4 ; i++)
            {
                if(arr.mbr_particion[i].part_size == -1)
                {
                    break;
                }
            }

            if(i == 4)
            {
                printf("\nError ya no se pueden agragar mas particiones\n\n");
                fclose(f);
                return;
            }



            for(i = 0; i<4; i++)
            {
                if(i == 0)
                {
                    if(arr.mbr_particion[i].part_start != 2147483647)
                    {
                        if(arr.mbr_particion[i].part_start - sizeof(arr) >= unsigned(size))
                        {
                            if((arr.mbr_particion[i].part_start - sizeof(arr)) > unsigned(tam))
                            {
                                tam = arr.mbr_particion[i].part_start - sizeof(arr);
                                propuesta = sizeof(arr);
                            }

                        }
                    }else
                    {
                        if(unsigned(size) > arr.mbr_tam - sizeof(arr))
                        {
                            printf("\nError, tamaño de la particion: %s nueva no valida, no se inserto la particion.\n\n",name.c_str());
                            return;
                        }
                        setParticion(arr.mbr_particion[i],sizeof(arr));
                        printf("\nSe inserto correctamente la particion %s\n\n",name.c_str());
                        if(type == 'e')
                        {

                            setEBR(aux);
                            fseek(f,sizeof(arr),SEEK_SET);
                            fwrite(&aux,sizeof(aux),1,f);
                        }
                        sort_array(arr.mbr_particion);
                        fseek(f,0,SEEK_SET);
                        fwrite(&arr,sizeof(arr),1,f);
                        fclose(f);
                        return;
                        break;
                    }
                }else if(i == 3)
                {
                    if(arr.mbr_particion[i].part_start == 2147483647)
                    {

                        break;
                    }else
                    {
                        printf("\nNo se pueden agregar mas particiones primarias o extendidas.\n\n");
                        return;
                    }
                }else
                {
                    if(arr.mbr_particion[i].part_start != 2147483647)
                    {
                        if(arr.mbr_particion[i].part_start - (arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size) >= size)
                        {
                            if(arr.mbr_particion[i].part_start - (arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size) > tam)
                            {
                                tam = arr.mbr_particion[i].part_start - (arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size);
                                propuesta = arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size;
                            }

                        }
                    }else
                    {

                        break;
                    }
                }
            }
            if(size > arr.mbr_tam - (arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size))
            {
                printf("\nError, tamaño de la particion: %s nueva no valida, no se inserto la particion.\n\n",name.c_str());
                return;
            }
            if(arr.mbr_tam -(arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size) > tam)
            {
                tam = arr.mbr_tam -(arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size);
                propuesta = arr.mbr_particion[i-1].part_start+arr.mbr_particion[i-1].part_size;
            }
            setParticion(arr.mbr_particion[i],propuesta);
            printf("\nSe inserto correctamente la particion %s\n\n",name.c_str());
            if(type == 'e')
            {

                setEBR(aux);
                fseek(f,propuesta,SEEK_SET);
                fwrite(&aux,sizeof(aux),1,f);
            }
            sort_array(arr.mbr_particion);
            fseek(f,0,SEEK_SET);
            fwrite(&arr,sizeof(arr),1,f);
            fclose(f);
            return;
        }else
        {
            int i = 0;
            for(i = 0; i<4 ; i++)
            {
                if(arr.mbr_particion[i].part_type == 'e')
                {
                    break;
                }
            }

            if(i == 4)
            {
                printf("\nError no se puede agregar la particion logica %s por que no hay una extendida\n\n",name.c_str());
                fclose(f);
                return;
            }
            EBR aux2;
            EBR aux3;
            fseek(f,arr.mbr_particion[i].part_start,SEEK_SET);
            fread(&aux,sizeof(aux),1,f);
            char ii = '*';
            while(aux.part_next != -1)
            {
                if(strcmp(name.c_str(),aux.part_name) == 0)
                {
                    printf("\nNo se puede insertar la particion, ya existe\n\n");
                    return;
                }
                fseek(f,aux.part_next,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);
            }
            if(strcmp(name.c_str(),aux.part_name) == 0)
            {
                printf("\nNo se puede insertar la particion, ya existe\n\n");
                return;
            }
            fseek(f,arr.mbr_particion[i].part_start,SEEK_SET);
            fread(&aux,sizeof(aux),1,f);
            if(aux.part_size == -1 && aux.part_next != -1)
            {
                fseek(f,aux.part_next,SEEK_SET);
                fread(&aux2,sizeof(aux2),1,f);
                if(aux2.part_start-(arr.mbr_particion[i].part_start+sizeof(arr)) >= unsigned(size))
                {
                    if(aux2.part_start-(arr.mbr_particion[i].part_start+sizeof(arr)) > unsigned(tam))
                    {
                        tam = aux2.part_start-(arr.mbr_particion[i].part_start+sizeof(arr));
                        propuesta = arr.mbr_particion[i].part_start;
                    }

                }
            }
            if(aux.part_size != -1 && aux.part_next == -1)
            {
                fseek(f,aux.part_start+aux.part_size,SEEK_SET);
                setEBR2(aux2,aux.part_start+aux.part_size);
                fwrite(&aux2,sizeof(aux2),1,f);
                aux.part_next = aux2.part_start;
                fseek(f,aux.part_start,SEEK_SET);
                fwrite(&aux,sizeof(aux),1,f);
                ii = 'S';
            }
            if(aux.part_size == -1 && aux.part_next == -1)
            {
                fseek(f,arr.mbr_particion[i].part_start,SEEK_SET);
                setEBR2(aux,arr.mbr_particion[i].part_start);
                fwrite(&aux,sizeof(aux),1,f);
                ii = 'S';
            }
            if(ii == '*')
            {
                while(aux.part_next != -1)
                {
                    if(aux.part_next != -1)
                    {
                        fseek(f,aux.part_next,SEEK_SET);
                        fread(&aux2,sizeof(aux2),1,f);
                        if(aux.part_size == -1 && aux.part_start == -1)
                        {
                            if(aux2.part_start-arr.mbr_particion[i].part_start >= size)
                            {
                                if(aux2.part_start-arr.mbr_particion[i].part_start > tam)
                                {
                                    tam = aux2.part_start-arr.mbr_particion[i].part_start;
                                    propuesta = arr.mbr_particion[i].part_start;
                                }
                            }
                        }else
                            if(aux2.part_start-(aux.part_start+aux.part_size) >= size)
                            {
                                if(aux2.part_start-(aux.part_start+aux.part_size) > tam)
                                {
                                    tam = aux2.part_start-(aux.part_start+aux.part_size);
                                    propuesta = aux.part_start;
                                }

                            }
                    }else
                    {
                        fseek(f,aux.part_next,SEEK_SET);
                        fread(&aux,sizeof(aux),1,f);
                        break;
                    }
                    fseek(f,aux.part_next,SEEK_SET);
                    fread(&aux,sizeof(aux),1,f);
                }
            }

            if(aux.part_size != -1 && ii == '*')
            {
                if((arr.mbr_particion[i].part_size+arr.mbr_particion[i].part_start)-(aux.part_start+aux.part_size) >= size)
                {
                    if( (arr.mbr_particion[i].part_size+arr.mbr_particion[i].part_start)-(aux.part_start+aux.part_size) > tam)
                    {
                        tam = (arr.mbr_particion[i].part_size+arr.mbr_particion[i].part_start)-(aux.part_start+aux.part_size);
                        propuesta = aux.part_start;
                    }

                }
            }

            if(propuesta != -1 && ii == '*')
            {
                fseek(f,propuesta,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);
                if(aux.part_next != -1 && aux.part_size != -1)
                {
                    fseek(f,aux.part_next,SEEK_SET);
                    fread(&aux2,sizeof(aux2),1,f);
                    setEBR2(aux3,aux.part_size+aux.part_start);
                    aux3.part_next = aux.part_next;
                    aux.part_next = aux3.part_start;

                    fseek(f,aux.part_start,SEEK_SET);
                    fwrite(&aux,sizeof(aux),1,f);

                    fseek(f,aux2.part_start,SEEK_SET);
                    fwrite(&aux2,sizeof(aux2),1,f);

                    fseek(f,aux3.part_start,SEEK_SET);
                    fwrite(&aux3,sizeof(aux3),1,f);

                    fseek(f,propuesta,SEEK_SET);
                    fread(&aux,sizeof(aux),1,f);

                }else if(aux.part_next != -1 && aux.part_start == -1)
                {
                    int t = aux.part_next;
                    setEBR2(aux,propuesta);
                    fseek(f,propuesta,SEEK_SET);
                    aux.part_next = t;
                    fwrite(&aux,sizeof(aux),1,f);
                }else
                {
                    setEBR2(aux2,aux.part_start+aux.part_size);
                    aux.part_next = aux2.part_start;

                    fseek(f,aux2.part_start,SEEK_SET);
                    fwrite(&aux2,sizeof(aux2),1,f);

                    fseek(f,aux.part_start,SEEK_SET);
                    fwrite(&aux,sizeof(aux),1,f);
                }
                ii = 'S';
            }
            if(ii != '*')
            {
                printf("\nSe inserto correctamente la particion logica %s\n\n",name.c_str());
                fclose(f);
                return;
            }

        }
    }
}

void setParticion(Particion& val,int start)
{
    val.part_fit = fit.at(0);
    clean_char(val.part_name,16);
    strcat(val.part_name,name.c_str());
    val.part_size = size;
    val.part_start = start;
    val.part_status = 'n';
    val.part_type = type;
}

void rep()
{
    if(path.compare("") == 0 || name.compare("") == 0 || id.compare("") == 0)
    {
        printf("\nUn campo obligatorio para usar la funcion mount no a sido definido\n\n");
        return;
    }

    if(name.compare("mbr") == 0)
    {
        mbr_graph();
    }
    else if(name.compare("disk") == 0)
    {
        disk_graph();
    }else if(name.compare("tree") == 0 )//------------------------Fase 2
    {
        tree();
    }else if(name.compare("inode") == 0)
    {
        repinodo();
    }else if(name.compare("block") == 0)
    {
        repbloque();
    }else if(name.compare("bm_inode") == 0)
    {
        repbminodo();
    }else if(name.compare("bm_block") == 0)
    {
        repbmblock();
    }else if(name.compare("sb") == 0)
    {
        repsb();
    }else if(name.compare("journaling") == 0)
    {
        repjournal();
    }else if(name.compare("file") == 0)
    {
        refil = true;
        file = ruta;
        string idacc = idactual;
        idactual = id;
        repfile = "";
        cat();
        if(repfile == ""){
            printf("\nNo se encontro el archivo para el reporte file\n\n");
            return;
        }
        FILE* fi = fopen(path.c_str(),"w+t");

        if(fi == NULL)
        {
            printf("\nError no se pudo crear el archivo del reporte\n\n");
        }
        fprintf(fi,"%s",repfile.c_str());

        fclose(fi);

        idactual = idacc;
        file = "";
        refil = false;
    }else if(name.compare("ls") == 0)
    {
        repls();
    }else
    {
        printf("\nError nombre del tipo de reporte no valido\n\n");
    }
}

void mbr_graph()
{

    FILE* f = fopen("./Images/grafo.dot","w");

    if(f == NULL)
    {
        printf("\nError no se pudo crear el grafo\n\n");
        return;
    }else
    {
        string txt_file = "";
        for(int i = 0; i<maxd ; i++)
        {
            for(int j = 0; j<maxp ; j++)
            {
                if(mounts[i][j].id == id)
                {
                    if(mounts[i][j].direccion == -1)
                    {
                        printf("\nError particion no montada para el id %s\n\n",id.c_str());
                        return;
                    }
                    FILE* file = fopen(mounts[i][j].path.c_str(),"r+b");
                    MBR auxM;
                    fseek(file,0,SEEK_SET);
                    fread(&auxM,sizeof(auxM),1,file);
                    txt_file += "digraph G {\r\n node[shape = \"textplain\" ]; \r\n s[ label=<<table border=\"0\" cellborder=\"1\" cellspacing=\"0\"><tr><td colspan= '2'><b>Tabla de MBR</b></td></tr>\r\n<tr><td><b>Nombre</b></td><td>Valor</td></tr>\r\n";
                    txt_file += "<tr><td><b>mbr_fit</b></td><td>" + string(1,auxM.disk_fit) + "</td></tr>\r\n";
                    txt_file += "<tr><td><b>mbr_disk_signature</b></td><td>" + to_string(auxM.mbr_disk_signature) + "</td></tr>\r\n";
                    txt_file += "<tr><td><b>mbr_fecha_creacion</b></td><td>" + string(auxM.mbr_fecha_creacion) + "</td></tr>\r\n";
                    txt_file += "<tr><td><b>mbr_tamanio</b></td><td>" + to_string(auxM.mbr_tam) + "</td></tr>\r\n";
                    for(int ss = 0; ss<4 ; ss++)
                    {
                        if(auxM.mbr_particion[ss].part_size != -1)
                        {
                            txt_file += "<tr><td colspan= '2'><b>Particion " +to_string(ss+1) + "</b></td></tr>\r\n";
                            txt_file += "<tr><td><b>part_fit</b></td><td>" + string(1, auxM.mbr_particion[ss].part_fit) + "</td></tr>\r\n";
                            txt_file += "<tr><td><b>part_name</b></td><td>" + string(auxM.mbr_particion[ss].part_name) + "</td></tr>\r\n";
                            txt_file += "<tr><td><b>part_size</b></td><td>" + to_string(auxM.mbr_particion[ss].part_size) + "</td></tr>\r\n";
                            txt_file += "<tr><td><b>part_start</b></td><td>" + to_string(auxM.mbr_particion[ss].part_start) + "</td></tr>\r\n";
                            txt_file += "<tr><td><b>part_status</b></td><td>" + string(1, auxM.mbr_particion[ss].part_status) + "</td></tr>\r\n";
                            txt_file += "<tr><td><b>part_type</b></td><td>" + string(1, auxM.mbr_particion[ss].part_type) + "</td></tr>\r\n";
                        }

                    }
                    EBR auxE;
                    int nn = 0;
                    for(int ss = 0; ss<4 ; ss++)
                    {
                        if(auxM.mbr_particion[ss].part_type == 'e')
                        {
                            fseek(file,auxM.mbr_particion[ss].part_start,SEEK_SET);
                            fread(&auxE,sizeof(auxE),1,file);
                            while(auxE.part_next != -1)
                            {
                                nn++;
                                txt_file += "<tr><td colspan= '2'><b>Particion logica " + to_string(nn) + "</b></td></tr>\r\n";
                                txt_file += "<tr><td><b>part_fit</b></td><td>" + string(1, auxE.part_fit) + "</td></tr>\r\n";
                                txt_file += "<tr><td><b>part_name</b></td><td>" + string(auxE.part_name) + "</td></tr>\r\n";
                                txt_file += "<tr><td><b>part_size</b></td><td>" + to_string(auxE.part_size) + "</td></tr>\r\n";
                                txt_file += "<tr><td><b>part_start</b></td><td>" + to_string(auxE.part_start) + "</td></tr>\r\n";
                                txt_file += "<tr><td><b>part_status</b></td><td>" + string(1, auxE.part_status) + "</td></tr>\r\n";
                                txt_file += "<tr><td><b>part_next</b></td><td>" + to_string(auxE.part_next) + "</td></tr>\r\n";
                                fseek(file,auxE.part_next,SEEK_SET);
                                fread(&auxE,sizeof(auxE),1,file);
                            }
                            if(auxE.part_size != -1)
                            {
                                nn++;
                                txt_file += "<tr><td colspan= '2'><b>Particion logica " + to_string(nn +1) + "</b></td></tr>\r\n";
                                txt_file += "<tr><td><b>part_fit</b></td><td>" + string(1, auxE.part_fit) + "</td></tr>\r\n";
                                txt_file += "<tr><td><b>part_name</b></td><td>" + string(auxE.part_name) + "</td></tr>\r\n";
                                txt_file += "<tr><td><b>part_size</b></td><td>" + to_string(auxE.part_size) + "</td></tr>\r\n";
                                txt_file += "<tr><td><b>part_start</b></td><td>" + to_string(auxE.part_start) + "</td></tr>\r\n";
                                txt_file += "<tr><td><b>part_status</b></td><td>" + string(1, auxE.part_status) + "</td></tr>\r\n";
                                txt_file += "<tr><td><b>part_next</b></td><td>" + to_string(auxE.part_next) + "</td></tr>\r\n";
                            }
                        }
                    }
                    txt_file += "</table>>];}";
                    fprintf(f,"%s", txt_file.c_str());
                    fclose(f);
                    crear_imagen();
                    return;
                }
            }
        }
    }
}

void disk_graph()
{
    FILE* f = fopen("./Images/grafo.dot","w");
    float result = 0;
    char cmd[300];
    if(f == NULL)
    {
        printf("\nError no se pudo crear el grafo\n\n");
        return;
    }else
    {
        string txt_file = "";
        for(int i = 0; i<maxd ; i++)
        {
            for(int j = 0; j<maxp ; j++)
            {
                if(mounts[i][j].id == id)
                {
                    if(mounts[i][j].direccion == -1)
                    {
                        printf("\nError particion no montada para el id %s\n\n", id.c_str());
                        return;
                    }

                    EBR auxE;
                    int ant = 0,si =0;

                    FILE* file = fopen(mounts[i][j].path.c_str(),"r+b");
                    MBR auxM;
                    fseek(file,0,SEEK_SET);
                    fread(&auxM,sizeof(auxM),1,file);
                    for(int rr = 0; rr < 4 ; rr++)
                    {
                        printf("nombre: %s, tipo: %c \n",auxM.mbr_particion[rr].part_name,auxM.mbr_particion[rr].part_type);
                    }
                    txt_file += "digraph G {\r\n node[shape = \"textplain\" ]; \r\n s[ label=<<table border=\"0\" cellborder=\"1\" cellspacing=\"0\"><tr>\r\n";
                    txt_file += "<td colspan= \"100\">  MBR  <br></br>Tamaño: " + to_string(auxM.mbr_tam) + "</td>";
                    int ss = 0;
                    for(ss = 0; ss<4 ; ss++)
                    {
                        if(ss == 0)
                        {
                            if(auxM.mbr_particion[ss].part_type == 'e')
                            {
                                if(auxM.mbr_particion[ss].part_start - sizeof(auxM) > 0)
                                {
                                    result = (float) ((auxM.mbr_particion[ss].part_start - sizeof(auxM))*100)/ (float) auxM.mbr_tam;
                                    int tmAux = auxM.mbr_particion[ss].part_start - sizeof(auxM);
                                    txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100)  + " %% libre<br></br> " + to_string(tmAux) + " Bytes</td>";
                                }
                                fseek(file,auxM.mbr_particion[ss].part_start,SEEK_SET);
                                fread(&auxE,sizeof(auxE),1,file);
                                ant = auxM.mbr_particion[ss].part_start;
                                txt_file += "<td><table border=\"0\" cellborder=\"1\" cellspacing=\"0\"><tr>\r\n";
                                txt_file += "<td colspan= \"100\">  Extendida  " + string(auxM.mbr_particion[ss].part_name) + "</td></tr><tr>";
                                while(auxE.part_next != -1)
                                {
                                    if(auxE.part_size != -1)
                                    {
                                        if(auxE.part_start -(ant+si) >0)
                                        {
                                            result = (float)((auxE.part_start -(ant+si))*100)/ (float)auxM.mbr_tam;
                                            txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string(auxE.part_start -(ant+si))+ "Bytes</td>";
                                        }
                                        txt_file += "<td colspan= \"100\">EBR</td>";
                                        result = (float) ((auxE.part_size)*100)/ (float) auxM.mbr_tam;
                                        txt_file += "<td colspan= \"100\">Logica " +string(auxE.part_name) + "<br></br>" + to_string(floorf(result * 100) / 100) + " %% ocupado<br></br> " + to_string(auxE.part_size) + " Bytes</td>";
                                        ant = auxE.part_start;
                                        si = auxE.part_size;
                                    }

                                    fseek(file,auxE.part_next,SEEK_SET);
                                    fread(&auxE,sizeof(auxE),1,file);
                                }
                                if(auxE.part_size != -1)
                                {
                                    if(auxE.part_start -(ant+si) >0)
                                    {
                                        result = (float)((auxE.part_start -(ant+si))*100)/ (float)auxM.mbr_tam;
                                        txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string(auxE.part_start -(ant+si)) + " Bytes</td>";
                                    }
                                    txt_file += "<td colspan= \"100\">EBR</td>";
                                    result = (float) ((auxE.part_size)*100)/ (float) auxM.mbr_tam;
                                    txt_file += "<td colspan= \"100\">Logica " + string(auxE.part_name) + "<br></br>%" + to_string(floorf(result * 100) / 100) + "%% ocupado<br></br> " + to_string(auxE.part_size) + " Bytes</td>";
                                }
                                if(auxE.part_size == -1 && auxE.part_start == -1)
                                {
                                    result = (float) (((auxM.mbr_particion[ss].part_size))*100)/ (float) auxM.mbr_tam;
                                    txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string(auxM.mbr_particion[ss].part_size) + " Bytes</td>";
                                }else
                                {
                                    if((auxM.mbr_particion[ss].part_start+auxM.mbr_particion[ss].part_size) - (auxE.part_start+auxE.part_size) >0)
                                    {
                                        result = (float) (((auxM.mbr_particion[ss].part_start+auxM.mbr_particion[ss].part_size) - (auxE.part_start+auxE.part_size))*100)/ (float) auxM.mbr_tam;
                                        txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string((auxM.mbr_particion[ss].part_start+auxM.mbr_particion[ss].part_size) - (auxE.part_start+auxE.part_size)) +" Bytes</td>";
                                    }
                                }
                                txt_file += "</tr></table></td>";
                                continue;
                            }
                            else if(auxM.mbr_particion[ss].part_start == 2147483647)
                            {
                                txt_file += "<td colspan= \"100\">No hay particiones<br></br>100 %%libre</td>";
                                txt_file += "</tr></table>>];}";
                                fprintf(f,"%s", txt_file.c_str());
                                fclose(f);
                                clean_char(cmd,300);

                                char *path_dot = realpath("./Images/grafo.dot", NULL);
                                sprintf(cmd,"dot -Tjpg %s -o %s", path_dot, path.c_str());

                                system(cmd);
                                clean_char(cmd,300);
                                return;
                            }
                            else
                            {
                                if(auxM.mbr_particion[ss].part_start - sizeof(auxM) > 0)
                                {
                                    int tmAux = auxM.mbr_particion[ss].part_start - sizeof(auxM);
                                    result = (float) ((auxM.mbr_particion[ss].part_start - sizeof(auxM))*100)/ (float) auxM.mbr_tam;
                                    txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string(tmAux) + " Bytes</td>";
                                }
                                if(auxM.mbr_particion[ss].part_size != 2147483647)
                                {
                                    txt_file += "<td colspan= \"100\">";
                                    if(auxM.mbr_particion[ss].part_type == 'p')
                                    {
                                        txt_file += "Primaria " + string(auxM.mbr_particion[ss].part_name);
                                    }else if(auxM.mbr_particion[ss].part_type == 'e')
                                    {
                                        txt_file += "Extendida " + string(auxM.mbr_particion[ss].part_name);
                                    }
                                    result = (float) ((auxM.mbr_particion[ss].part_size)*100)/ (float) auxM.mbr_tam;
                                    txt_file += "<br></br>" + to_string(floorf(result * 100) / 100) + " %% ocupado<br></br> " + to_string(auxM.mbr_particion[ss].part_size) + " Bytes</td>";
                                }
                            }
                        }else
                        {
                            if(auxM.mbr_particion[ss].part_size == -1)
                            {
                                break;
                            }
                            if(auxM.mbr_particion[ss].part_type == 'e')
                            {
                                if(auxM.mbr_particion[ss].part_start - (auxM.mbr_particion[ss-1].part_start +auxM.mbr_particion[ss-1].part_size) > 0)
                                {
                                    result = (float) ((auxM.mbr_particion[ss].part_start - (auxM.mbr_particion[ss-1].part_start +auxM.mbr_particion[ss-1].part_size))*100)/ (float) auxM.mbr_tam;
                                    txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string(auxM.mbr_particion[ss].part_start - (auxM.mbr_particion[ss-1].part_start +auxM.mbr_particion[ss-1].part_size)) +" Bytes</td>";
                                }
                                fseek(file,auxM.mbr_particion[ss].part_start,SEEK_SET);
                                fread(&auxE,sizeof(auxE),1,file);
                                ant = auxM.mbr_particion[ss].part_start;
                                txt_file += "<td><table border=\"0\" cellborder=\"1\" cellspacing=\"0\"><tr>\r\n";
                                txt_file += "<td colspan= \"100\">  Extendida " + string(auxM.mbr_particion[ss].part_name) + "</td></tr><tr>";
                                while(auxE.part_next != -1)
                                {
                                    if(auxE.part_size != -1)
                                    {
                                        if(auxE.part_start -(ant+si) >0)
                                        {
                                            result = (float)((auxE.part_start -(ant+si))*100)/ (float)auxM.mbr_tam;
                                            txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string(auxE.part_start -(ant+si)) + " Bytes</td>";
                                        }
                                        txt_file += "<td colspan= \"100\">EBR</td>";
                                        result = (float) ((auxE.part_size)*100)/ (float) auxM.mbr_tam;
                                        txt_file += "<td colspan= \"100\">Logica " + string(auxE.part_name) + "<br></br>" + to_string(floorf(result * 100) / 100) +" %% ocupado<br></br> " + to_string(auxE.part_size) +" Bytes</td>";
                                        ant = auxE.part_start;
                                        si = auxE.part_size;
                                    }

                                    fseek(file,auxE.part_next,SEEK_SET);
                                    fread(&auxE,sizeof(auxE),1,file);
                                }
                                if(auxE.part_size != -1)
                                {
                                    if(auxE.part_start -(ant+si) >0)
                                    {
                                        result = (float)((auxE.part_start -(ant+si))*100)/ (float)auxM.mbr_tam;
                                        txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string(auxE.part_start -(ant+si)) + " Bytes</td>";
                                    }
                                    txt_file += "<td colspan= \"100\">EBR</td>";
                                    result = (float) ((auxE.part_size)*100)/ (float) auxM.mbr_tam;
                                    txt_file += "<td colspan= \"100\">Logica " + string(auxE.part_name) +"<br></br>" + to_string(floorf(result * 100) / 100) +" %% ocupado<br></br> " + to_string(auxE.part_size) + " Bytes</td>";
                                }
                                if(auxE.part_size == -1 && auxE.part_start == -1)
                                {
                                    result = (float) (((auxM.mbr_particion[ss].part_size))*100)/ (float) auxM.mbr_tam;
                                    txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(result) + " libre<br></br> " + to_string(auxM.mbr_particion[ss].part_size) + " Bytes</td>";
                                }else
                                {
                                    if((auxM.mbr_particion[ss].part_start+auxM.mbr_particion[ss].part_size) - (auxE.part_start+auxE.part_size) >0)
                                    {
                                        result = (float) (((auxM.mbr_particion[ss].part_start+auxM.mbr_particion[ss].part_size) - (auxE.part_start+auxE.part_size))*100)/ (float) auxM.mbr_tam;
                                        txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string(auxM.mbr_particion[ss].part_start+(auxM.mbr_particion[ss].part_start+auxM.mbr_particion[ss].part_size) - (auxE.part_start+auxE.part_size)) + " Bytes</td>";
                                    }
                                }

                                txt_file += "</tr></table></td>";
                                continue;
                            }
                            if(auxM.mbr_particion[ss].part_start - (auxM.mbr_particion[ss-1].part_start + auxM.mbr_particion[ss-1].part_size) > 0)
                            {
                                result = (float) ((auxM.mbr_particion[ss].part_start - (auxM.mbr_particion[ss-1].part_start + auxM.mbr_particion[ss-1].part_size))*100)/ (float) auxM.mbr_tam;
                                txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string(auxM.mbr_particion[ss].part_start - (auxM.mbr_particion[ss-1].part_start + auxM.mbr_particion[ss-1].part_size)) + " Bytes</td>";
                            }
                            if(auxM.mbr_particion[ss].part_size != 2147483647)
                            {
                                txt_file += "<td colspan= \"100\">";
                                if(auxM.mbr_particion[ss].part_type == 'p')
                                {
                                    txt_file += "Primaria " + string(auxM.mbr_particion[ss].part_name);
                                }else if(auxM.mbr_particion[ss].part_type == 'e')
                                {
                                    txt_file += "Extendida %s" + string(auxM.mbr_particion[ss].part_name);
                                }
                                result = (float) ((auxM.mbr_particion[ss].part_size)*100)/ (float) auxM.mbr_tam;
                                 txt_file += "<br></br>" + to_string(floorf(result * 100) / 100) + " %% ocupado<br></br> " + to_string(auxM.mbr_particion[ss].part_size) + " Bytes</td>";
                            }
                        }
                    }

                    if(auxM.mbr_tam - (auxM.mbr_particion[ss-1].part_start+auxM.mbr_particion[ss-1].part_size) >0)
                    {
                        result = (float) auxM.mbr_tam - (auxM.mbr_particion[ss-1].part_start+auxM.mbr_particion[ss-1].part_size);
                        result = (float) result * 100;
                        result = (float) result/ (float) auxM.mbr_tam;
                        txt_file += "<td colspan= \"100\">Libre<br></br>" + to_string(floorf(result * 100) / 100) + " %% libre<br></br> " + to_string(auxM.mbr_tam - (auxM.mbr_particion[ss-1].part_start+auxM.mbr_particion[ss-1].part_size)) + " Bytes</td>";
                    }

                    txt_file += "</tr></table>>];}";
                    fprintf(f,"%s", txt_file.c_str());
                    fclose(f);
                    crear_imagen();
                    return;
                }
            }
        }
    }
}

void crear_imagen()
{
    crear_folder();
    char *path_dot = realpath("./Images/grafo.dot", NULL);
    string extension;
    for(int i = path.size(); i >= 0  ; i--)
    {
        if(path[i] == char('.'))
        {
            extension = path.substr(i+1, path.length()-1);
            break;
        }
    }
    string comand = "dot -T" + extension + " " + path_dot + " -o " + path;
    system(comand.c_str());
    printf("\nSe Creo correctamente la imagen\n\n");
}

// Second Fase *******************************************************************************************************************************************************

void set_fs_char(string data)
{
    if(data.compare("2fs") == 0)
        fs = '2';
    else if(data.compare("3fs") == 0)
        fs = '3';
}

void copiarS(char destino[],string origen, int caracteres)
{
    for(int i = 0; i<caracteres; i++)
    {
        destino[i] = origen[i];
    }
}

void copiar(char destino[], char origen[], int caracteres)
{
    for(int i = 0; i<caracteres; i++)
    {
        destino[i] = origen[i];
    }
}

void copiarsinEspacios(char destino[],char origen[], int caracteres)
{
    for(int i = 0; i<caracteres; i++)
    {
        if(origen[i] == '\n')
        {
            destino[i] = '/';
        }else
        {
            destino[i] = origen[i];
        }
    }
}

void mkfs()
{
    if(id.compare("") == 0)
    {
        printf("\nSe necesita un id para el comando mkfs\n\n");
        return;
    }
    if(tdelete.compare("") == 0)
    {
        tdelete = "full";
    }
    if(fs == '*')
    {
        fs = '2';
    }
    for(int i = 0; i< maxd; i++)
    {
        for(int j = 0; j< maxp; j++)
        {
            if(id.compare(mounts[i][j].id) == 0)
            {
                if(mounts[i][j].direccion == -1)
                {
                    cout << "\nLa particion " << id <<" no esta montada, para formatearla\n\n";
                    return;
                }
                int iuf= idusuarioactual;
                int igg = idgrupoactual;
                idusuarioactual = 1;
                idgrupoactual = 1;
                ext(i,j);
                idusuarioactual = iuf;
                idgrupoactual = igg;
                return;
            }
        }
    }

    printf("\nError id no valido para una particion montada\n\n");
}

void ext(int i, int j)
{
    SB nuevo;
    EBR auxE;
    Particion auxP;
    FILE* file = fopen(mounts[i][j].path.c_str(),"r+b");

    if(file == NULL)
    {
        printf("\nNo se pudo acceder al disco para su formateo\n\n");
        fclose(file);
        return;
    }
    int sizeparticion =0, sizestruct = 0;
    fseek(file,mounts[i][j].direccion,SEEK_SET);
    if(mounts[i][j].type == 'l')
    {
        fread(&auxE,sizeof(auxE),1,file);
        sizeparticion = auxE.part_size;
        sizestruct = sizeof(auxE);
    }else if(mounts[i][j].type == 'p')
    {
        fread(&auxP,sizeof(auxP),1,file);
        sizeparticion = mounts[i][j].part_size;
        sizestruct = 0;
    }

    //-----------SET SUPER BLOQUE

    int inode = 0;
    if(fs == '2')
    {
        inode = floor(((sizeparticion-sizestruct)-sizeof(SB))/(4+sizeof(INODO)+3*sizeof(BCARPETA)));
    }else
    {
        inode = floor(((sizeparticion-sizestruct)-sizeof(SB))/(sizeof(JOURNAL)+4+sizeof(INODO)+3*sizeof(BCARPETA)));
    }

    JOURNAL jou[inode];


    nuevo.s_blocks_count = 3*inode;int buscarlibre(char vec[],int tam);
    nuevo.s_block_size = sizeof(BCARPETA);

    if(fs == '2')
    {
        nuevo.s_block_start = mounts[i][j].direccion + sizestruct + sizeof(SB)+sizeof(char[inode])+sizeof(char[3*inode])+inode*sizeof(INODO);
        nuevo.s_bm_block_start = mounts[i][j].direccion + sizestruct + sizeof(SB)+sizeof(char[inode]);
        nuevo.s_inode_start = mounts[i][j].direccion + sizestruct + sizeof(SB)+sizeof(char[inode])+sizeof(char[3*inode]);
        nuevo.s_bm_inode_start = mounts[i][j].direccion + sizestruct + sizeof(SB);
    }else
    {
        nuevo.s_block_start = mounts[i][j].direccion + sizestruct + sizeof(SB)+sizeof(jou)+sizeof(char[inode])+sizeof(char[3*inode])+inode*sizeof(INODO);
        nuevo.s_bm_block_start = mounts[i][j].direccion + sizestruct + sizeof(SB)+sizeof(jou)+sizeof(char[inode]);
        nuevo.s_inode_start = mounts[i][j].direccion + sizestruct + sizeof(SB)+sizeof(jou)+sizeof(char[inode])+sizeof(char[3*inode]);
        nuevo.s_bm_inode_start = mounts[i][j].direccion + sizestruct + sizeof(SB)+sizeof(jou);
    }

    nuevo.s_filesystem_type = fs -48;
    nuevo.s_first_blo = 0; //sizeof(SB)+sizeof(char[inode])+sizeof(char[3*inode])+inode*sizeof(INODO);
    nuevo.s_first_ino = 0; //sizeof(SB)+sizeof(char[inode])+sizeof(char[3*inode]);
    nuevo.s_free_blocks_count = 3*inode;
    nuevo.s_free_inodes_count = inode;
    nuevo.s_inodes_count = inode;
    nuevo.s_inode_size = sizeof(INODO);
    nuevo.s_magic = 0xEF53;
    nuevo.s_mnt_count = 1;
    fecha(nuevo.s_mtime);
    clean_char(nuevo.s_umtime,16);

    //-----------SET BITMAPS INODO Y BLOQUES

    char temp_bm_inodos[inode];
    char temp_bm_blocks[3*inode];

    for(int to = 0; to < inode ; to++)
    {
        temp_bm_inodos[to] = '0';
    }

    for(int to = 0; to < 3*inode ; to++)
    {
        temp_bm_blocks[to] = '0';
    }



    //-----------SET INODO Y BLOQUE PARA RAIZ

    temp_bm_inodos[0] = '1';
    temp_bm_blocks[0] = '1';

    INODO tinodo;
    BCARPETA tcarpeta;

    tinodo.I_gid = idgrupoactual;
    tinodo.i_perm = 664;
    tinodo.i_size = 52;
    tinodo.i_type = '0';
    tinodo.i_uid = idusuarioactual;
    fecha(tinodo.i_atime);
    fecha(tinodo.i_mtime);
    fecha(tinodo.i_ctime);

    for(int tb = 0; tb < 15; tb++)
    {
        tinodo.i_block[tb] = -1;
    }

    for(int ti = 0; ti < 4 ; ti++)
    {
        tcarpeta.b_content[ti].b_inode = -1;
        for(int tic = 0; tic < 12 ; tic++)
        {
            tcarpeta.b_content[ti].b_name[tic] = '\0';
        }
    }

    strcat(tcarpeta.b_content[0].b_name,".");
    tcarpeta.b_content[0].b_inode = 0;

    strcat(tcarpeta.b_content[1].b_name,"..");
    tcarpeta.b_content[1].b_inode = 0;

    tinodo.i_block[0] = 0;

    //strcat(tcarpeta.b_content[2].b_name,"/");
    //tcarpeta.b_content[2].b_inode = -1;


    //-------------SET INODO Y BLOQUE PARA EL ARCHIVO USERS
    temp_bm_inodos[1] = '1';
    temp_bm_blocks[1] = '1';

    INODO tarchivo;
    BARCHIVO barchivo;

    tarchivo.I_gid = idgrupoactual;
    tarchivo.i_perm = 664;
    tarchivo.i_size = 52;
    tarchivo.i_type = '1'; // 0 = carpeta, 1 = archivo
    tarchivo.i_uid = idusuarioactual;
    fecha(tarchivo.i_atime);
    fecha(tarchivo.i_mtime);
    fecha(tarchivo.i_ctime);



    for(int tb = 0; tb < 15; tb++)
    {
        tarchivo.i_block[tb] = -1;
    }

    for(int ti = 0; ti < 64 ; ti++)
    {
        barchivo.b_content[ti] = '\0';
    }

    tarchivo.i_block[0] = 1;

    strcat(barchivo.b_content,"1,G,root      \n1,U,root      ,root      ,123       \n");


    strcat(tcarpeta.b_content[2].b_name,"users.txt");
    tcarpeta.b_content[2].b_inode = 1;



    if(fs == '3')
    {
        for(int y = 0; y<inode; y++)
        {
            jou[y].permiso = -1;
            jou[y].type = -1;
            jou[y].type_trans = -1;
            for(int g =0; g<10; g++)
            {
                jou[y].j_time[g] = '\0';
                jou[y].name[g] = '\0';
            }
            jou[y].propietario = -1;
            jou[y].grupo = -1;
            clean_char(jou[y].contenido,64);
        }

        jou[0].permiso = 664;
        jou[0].type = 1;
        jou[0].type_trans = 1;
        strcat(jou[0].name,"/");
        jou[0].propietario = 1;
        jou[0].grupo = 1;
        fecha(jou[0].j_time);

        fseek(file,mounts[i][j].direccion+sizestruct+sizeof(nuevo),SEEK_SET);
        fwrite(&jou,sizeof(jou),1,file);
    }

    nuevo.s_free_blocks_count = nuevo.s_free_blocks_count - 2;
    nuevo.s_free_inodes_count = nuevo.s_free_inodes_count - 2;

    nuevo.s_first_blo = buscarlibre(temp_bm_blocks,nuevo.s_blocks_count);
    nuevo.s_first_ino = buscarlibre(temp_bm_inodos,nuevo.s_inodes_count);

    fseek(file,nuevo.s_inode_start,SEEK_SET);
    fwrite(&tinodo,sizeof(tinodo),1,file);

    fseek(file,nuevo.s_block_start,SEEK_SET);
    fwrite(&tcarpeta,sizeof(tcarpeta),1,file);

    fseek(file,nuevo.s_inode_start + nuevo.s_inode_size,SEEK_SET);
    fwrite(&tarchivo,sizeof(tarchivo),1,file);

    fseek(file,nuevo.s_block_start + nuevo.s_block_size,SEEK_SET);
    fwrite(&barchivo,sizeof(barchivo),1,file);

    fseek(file,mounts[i][j].direccion+sizestruct,SEEK_SET);
    fwrite(&nuevo,sizeof(nuevo),1,file);

    fseek(file,nuevo.s_bm_inode_start,SEEK_SET);
    fwrite(&temp_bm_inodos,sizeof(temp_bm_inodos),1,file);

    fseek(file,nuevo.s_bm_block_start,SEEK_SET);
    fwrite(&temp_bm_blocks,sizeof(temp_bm_blocks),1,file);

    printf("\nSe formateo correctamente la particion %s\n\n",mounts[i][j].name.c_str());

    fclose(file);
}

vector<string> split(string input, char separator){
    vector<string> aux;
    string temp = "";
    for (int i = 0; i<int(input.length()) ; i++ ) {
        if(char(input[i]) == separator){
            aux.push_back(temp);
            temp = "";
            continue;
        }
        temp += input[i];
    }
    if(temp != ""){
        aux.push_back(temp);
        temp = "";
    }
    return aux;
}

void fecha(char* fet)
{
    char fec[18];
    time_t tiempo = time(0);
    struct tm *tiem = localtime(&tiempo);
    clean_char(fec,18);
    strftime(fec, 18, "%d/%m/%Y %H:%M", tiem);

    for(int r = 0; r<16; r++)
    {
        fet[r] = fec[r];
    }
}

int buscarlibre(char vec[],int tam)
{
    for(int i = 0; i< tam ; i++)
    {
        if(vec[i] == '0')
        {
            return i;
        }
    }
    return -1;
}

int buscarvaciojournal(JOURNAL jo[],int tam_jou)
{
    for(int i = 0; i<tam_jou ; i++)
    {
        if(jo[i].type_trans == -1)
        {
            return i;
        }
    }
    return -1;
}

void login()
{
    if(id == "")
    {
        printf("\nError, se necesita un id de particion montada\n\n");
        return;
    }
    if(pwd == "")
    {
        printf("\nError, se necesita una contraseña valida\n\n");
        return;
    }
    if(usr == "")
    {
        printf("\nError, se necesita un usuario valido\n\n");
        return;
    }

    if(idusuarioactual != -1)
    {
        printf("\nError ya existe una sesion iniciada\n\n");
        return;
    }

    for(int i = 0; i<maxd ; i++)
    {
        for(int j = 0; j<maxp; j++)
        {
            if(mounts[i][j].id .compare(id) == 0)
            {
                if(mounts[i][j].direccion == -1)
                {
                    printf("\nError, particion %s no montada\n\n",id.c_str());
                    return;
                }

                FILE* f = fopen(mounts[i][j].path.c_str(),"r+b");
                SB sb;
                int dirsb = -1;
                if(mounts[i][j].type == 'p')
                {
                    fseek(f,mounts[i][j].direccion,SEEK_SET);
                    dirsb = mounts[i][j].direccion;
                }else
                {
                    fseek(f,mounts[i][j].direccion + sizeof(EBR),SEEK_SET);
                    dirsb = mounts[i][j].direccion + sizeof(EBR);
                }
                fread(&sb,sizeof(sb),1,f);
                INODO aux;
                BARCHIVO archi;
                fseek(f,sb.s_inode_start+1*sb.s_inode_size,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);

                string cadtemp = "";

                for(int r = 0; r<12; r++)
                {
                    if(aux.i_block[r] != -1)
                    {
                        fseek(f,sb.s_block_start+aux.i_block[r]*sb.s_block_size,SEEK_SET);
                        fread(&archi,sizeof(archi),1,f);
                        for(int nn= 0; nn<64; nn++){
                          cadtemp += archi.b_content[nn];
                        }
                        //cadtemp += string(archi.b_content);
                    }
                }

                int ggg = buscarusuario(cadtemp);
                if(ggg == 1)
                {
                    idactual = id;
                    printf("\nSe inicio sesion correctamente\n\n");
                }else if(ggg == -1)
                {
                    idusuarioactual = -1;
                    idgrupoactual = -1;
                    idactual = "";
                    printf("\nError no se pudo iniciar sesion, no se encontro el usario especificado\n\n");
                }else if(ggg == -2)
                {
                    idusuarioactual = -1;
                    idgrupoactual = -1;
                    idactual = "";
                    printf("\nError la contraseña no coincide, no se inicio sesion\n\n");
                }



            }
        }
    }


}

void logout()
{
    if(idusuarioactual == -1)
    {
        printf("\nError debe existir una sesion activa\n\n");
        return;
    }
    idusuarioactual = -1;
    idgrupoactual = -1;
    idactual = "";
}

string remplazar(string cad){
    for(int i = cad.length(); i<10;i++){
        cad+= " ";
    }
    return cad;
}

int buscarusuario(string fil)
{
    vector<string> auxline = split(fil,'\n');
    vector<string> auxparamet;
    for (unsigned int i = 0; i< auxline.size(); i++)
    {
        auxparamet = split(auxline[i],',');
        if(auxparamet.size() < 2)
            continue;
        if(auxparamet[1].compare("U") == 0)
        {
            if(auxparamet[3].compare(remplazar(usr)) == 0)
            {
                if(auxparamet[4].compare(remplazar(pwd)) == 0)
                {
                    int g = buscargrupo(fil,auxparamet[2]);
                    if(g > 0)
                    {
                        idusuarioactual = atoi(auxparamet[0].c_str());
                        idgrupoactual = g;
                        return 1;
                    }
                    return -3;
                }
                return -2;
            }

        }
    }

    return -1;
}

int buscargrupo(string fil, string grp)
{
    vector<string> auxline = split(fil,'\n');
    vector<string> auxparamet;
    for (unsigned int i = 0; i < auxline.size(); i++) {
        auxparamet = split(auxline[i],',');
        if(auxparamet.size() < 2)
            continue;
        if(auxparamet[1] == "G"){
            if(auxparamet[2] == grp){
                return atoi(auxparamet[0].c_str());
            }

        }
    }
    return -1;
}

int existegrp(string fil,string grp)
{
    vector<string> auxline = split(fil,'\n');
    vector<string> auxparamet;
    for (unsigned int i = 0; i< auxline.size(); i++) {
        auxparamet = split(auxline[i],',');
        if(auxparamet[1] == "G"){
            if(auxparamet[2] == grp && auxparamet[0] != "0"){
                return atoi(auxparamet[0].c_str());
            }

        }
    }
    return -1;
}

int idgrp(string fil)
{
    vector<string> auxline = split(fil,'\n');
    vector<string> auxparamet;
    vector<string> auxgrp;
    for (unsigned int i = 0; i< auxline.size(); i++) {
        auxparamet = split(auxline[i],',');
        if(auxparamet[1] == "G"){
            auxgrp.push_back(auxline[i]);
        }
    }
    if(auxgrp.size()>0){
        vector<string> auxid = split(auxgrp[auxgrp.size()-1],',');
        return atoi(auxid[0].c_str())+1;
    }
    return -1;
}

void mkgrp()
{
    if(name.compare("") == 0)
    {
        printf("\nError, necesita ingresar un nombre valido\n\n");
        return;
    }

    if(name.length() > 10){
        printf("\nError, el tamaño del nombre debe ser menor o igual a 10\n\n");
        return;
    }

    if(idusuarioactual != 1)
    {
        printf("\nError el usuario actual no puede usar el comando mkgrp permiso denegado\n\n");
        return;
    }

    for(int i = 0; i<maxd ; i++)
    {
        for(int j = 0; j<maxp; j++)
        {
            if(mounts[i][j].id == idactual)
            {
                if(mounts[i][j].direccion == -1)
                {
                    printf("\nError, particion %s no montada\n\n",id.c_str());
                    return;
                }

                FILE* f = fopen(mounts[i][j].path.c_str(),"r+b");
                SB sb;
                int dirsb = -1;
                if(mounts[i][j].type == 'p')
                {
                    fseek(f,mounts[i][j].direccion,SEEK_SET);
                    dirsb = mounts[i][j].direccion;
                }else
                {
                    fseek(f,mounts[i][j].direccion + sizeof(EBR),SEEK_SET);
                    dirsb = mounts[i][j].direccion + sizeof(EBR);
                }
                fread(&sb,sizeof(sb),1,f);
                INODO aux;
                BARCHIVO archi;
                fseek(f,sb.s_inode_start+1*sb.s_inode_size,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);

                string fil = "";
                for(int r = 0; r<12; r++)
                {
                    if(aux.i_block[r] != -1)
                    {
                        fseek(f,sb.s_block_start+aux.i_block[r]*sb.s_block_size,SEEK_SET);
                        clean_char(archi.b_content,64);
                        fread(&archi,sizeof(archi),1,f);
                        for (int gggg = 0; gggg < 64; gggg++) {
                            if(archi.b_content[gggg] == '\0'){
                                break;
                            }
                            fil += archi.b_content[gggg];
                        }
                    }
                }

                int ggg = existegrp(fil,remplazar(name));
                if(ggg != -1)
                {
                    printf("\nNo se puede crear el grupo %s por que ya existe\n\n",name.c_str());

                    fclose(f);
                    return;
                }

                int ur = idgrp(fil);
                if(ur == -1)
                {
                    printf("\nError ya no se pueden agregar mas grupos\n\n");
                    fclose(f);
                    return;
                }



                string nuevacad = "";
                nuevacad += to_string(ur);
                nuevacad += ',';
                nuevacad += 'G';
                nuevacad += ',';
                nuevacad += name;
                for(int re = name.length(); re <10; re++)
                {
                    nuevacad += " ";
                }
                nuevacad += '\n';

                fil += nuevacad;

                int ptee = guardarCadenaUsers(fil,f,sb,dirsb,aux);
                if(ptee == 1){
                    printf("\nSe creo correctamente el grupo\n\n");
                    if(sb.s_filesystem_type == 3)
                    {
                        JOURNAL jou[sb.s_inodes_count];
                        fseek(f,dirsb+sizeof(sb),SEEK_SET);
                        fread(&jou,sizeof(jou),1,f);
                        int posj = buscarvaciojournal(jou,sb.s_inodes_count);
                        jou[posj].type_trans = 2;
                        jou[posj].type = 0;
                        jou[posj].grupo = 0;
                        jou[posj].permiso = 0;
                        jou[posj].propietario = 0;
                        jou[posj].ipadre = 0;
                        copiarS(jou[posj].name,name,name.length());

                        fecha(jou[posj].j_time);
                        fseek(f,dirsb+sizeof(sb),SEEK_SET);
                        fwrite(&jou,sizeof(jou),1,f);

                    }
                }else{
                    printf("\nNo se pudo crear el grupo\n\n");
                }
                fclose(f);
            }
        }
    }
}

int guardarCadenaUsers(string fil, FILE* f, SB sb, int dirsb,INODO aux)
{

    BARCHIVO temparch;
    unsigned int puntero = 0, puntero2 = 0;

    for(int yy = 0; yy < 12; yy++)
    {
        if(aux.i_block[yy] != -1)
        {
            fseek(f,sb.s_block_start+aux.i_block[yy]*sb.s_block_size,SEEK_SET);
            fread(&temparch,sizeof(temparch),1,f);
            clean_char(temparch.b_content,64);
            for(puntero = 0; puntero <64; puntero++){
                //if(puntero2*64+puntero>=fil.length()){
                //    break;
                //}
                if(puntero2>=fil.length()){
                    break;
                }
                temparch.b_content[puntero] = fil[puntero2];
                puntero2++;
            }

            fseek(f,sb.s_block_start+aux.i_block[yy]*sb.s_block_size,SEEK_SET);
            fwrite(&temparch,sizeof(temparch),1,f);
            if(puntero2 >= fil.length()){
                return 1;
            }
            puntero = 0;

        }else{
            if(fil.length()>puntero2)
            {
                char tempb[sb.s_blocks_count];
                clean_char(tempb,sb.s_blocks_count);

                fseek(f,sb.s_bm_block_start,SEEK_SET);
                fread(&tempb,sizeof(tempb),1,f);

                int nuevobloque = buscarlibre(tempb,sb.s_blocks_count);
                sb.s_free_blocks_count = sb.s_free_blocks_count-1;

                if(nuevobloque == -1)
                    return -1;

                tempb[nuevobloque] = '1';

                BARCHIVO nuevbloq;
                clean_char(nuevbloq.b_content,64);
                for(puntero = 0; puntero < 64; puntero++)
                {
                    if(puntero2 >= fil.length())
                        break;
                    nuevbloq.b_content[puntero] = fil[puntero2];
                    puntero2++;

                }

                aux.i_block[yy] = nuevobloque;
                fseek(f,sb.s_block_start+aux.i_block[yy]*sb.s_block_size,SEEK_SET);
                fwrite(&nuevbloq,sizeof(nuevbloq),1,f);

                fseek(f,sb.s_bm_block_start,SEEK_SET);
                fwrite(&tempb,sizeof(tempb),1,f);

                fseek(f,sb.s_inode_start+sb.s_inode_size,SEEK_SET);
                fwrite(&aux,sizeof(aux),1,f);

                fseek(f,dirsb,SEEK_SET);
                fwrite(&sb,sizeof(sb),1,f);
                if(puntero2 >= fil.length())
                    return 1;
            }
        }
        if(puntero2 >= fil.length())
            return 1;
    }
    return -1;

}

void rmgrp()
{
    if(name == "")
    {
        printf("\nError, necesita ingresar un nombre valido\n\n");
        return;
    }

    if(name.length() > 10){
        printf("\nError, el tamaño del grupo debe ser menor o igual a 10\n\n");
        return;
    }

    if(idusuarioactual != 1)
    {
        printf("\nError el usuario actual no puede usar el comando mkgrp permiso denegado\n\n");
        return;
    }

    for(int i = 0; i<maxd ; i++)
    {
        for(int j = 0; j<maxp; j++)
        {
            if(mounts[i][j].id == idactual)
            {
                if(mounts[i][j].direccion == -1)
                {
                    printf("\nError, particion %s no montada\n\n",id.c_str());
                    return;
                }

                FILE* f = fopen(mounts[i][j].path.c_str(),"r+b");
                SB sb;
                int dirsb = -1;
                if(mounts[i][j].type == 'p')
                {
                    fseek(f,mounts[i][j].direccion,SEEK_SET);
                    dirsb = mounts[i][j].direccion;
                }else
                {
                    fseek(f,mounts[i][j].direccion + sizeof(EBR),SEEK_SET);
                    dirsb = mounts[i][j].direccion + sizeof(EBR);
                }
                fread(&sb,sizeof(sb),1,f);
                INODO aux;
                BARCHIVO archi;
                fseek(f,sb.s_inode_start+1*sb.s_inode_size,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);

                string fil = "";
                for(int r = 0; r<12; r++)
                {
                    if(aux.i_block[r] != -1)
                    {
                        fseek(f,sb.s_block_start+aux.i_block[r]*sb.s_block_size,SEEK_SET);
                        clean_char(archi.b_content,64);
                        fread(&archi,sizeof(archi),1,f);
                        for (int gggg = 0; gggg < 64; gggg++) {
                            if(archi.b_content[gggg] == '\0'){
                                break;
                            }
                            fil += archi.b_content[gggg];
                        }
                    }
                }

                int ggg = existegrp(fil,remplazar(name));
                if(ggg == -1)
                {
                    printf("\nNo se puede eliminar el grupo %s por que no existe el grupo %s\n\n",usr.c_str(),grp.c_str());
                    fclose(f);
                    return;
                }

                string ptgt = eliminarUsrGrp(fil,remplazar(name),'g');
                if(ptgt != ""){
                    guardarCadenaUsers(ptgt,f,sb,dirsb,aux);
                    printf("\nSe elimino el grupo con Exito\n\n");
                    if(sb.s_filesystem_type == 3)
                    {
                        JOURNAL jou[sb.s_inodes_count];
                        fseek(f,dirsb+sizeof(sb),SEEK_SET);
                        fread(&jou,sizeof(jou),1,f);
                        int posj = buscarvaciojournal(jou,sb.s_inodes_count);
                        jou[posj].type_trans = 4;
                        jou[posj].type = 0;
                        jou[posj].grupo = 0;
                        jou[posj].permiso = 0;
                        jou[posj].propietario = 0;
                        jou[posj].ipadre = 0;
                        copiarS(jou[posj].name,name,name.length());

                        fecha(jou[posj].j_time);
                        fseek(f,dirsb+sizeof(sb),SEEK_SET);
                        fwrite(&jou,sizeof(jou),1,f);

                    }
                }else{
                    printf("\nNo se pudo eliminar el grupo\n\n");

                }
                fclose(f);
            }
        }
    }
}

string eliminarUsrGrp(string fil,string usr, char t)
{
    string ret = "";
    vector<string> auxline = split(fil,'\n');
    vector<string> auxparamet;
    for (unsigned int i = 0; i< auxline.size(); i++) {
        auxparamet = split(auxline[i],',');
        if(t == 'u'){
            if(auxparamet[1] == "U"){
                if(auxparamet[3] == usr && auxparamet[0] != "0"){
                    auxparamet[0] = "0";
                    ret += auxparamet[0]+","+auxparamet[1]+","+auxparamet[2]+","+auxparamet[3]+","+auxparamet[4]+"\n";
                    continue;
                }

            }
        }else if(t == 'g'){
            if(auxparamet[1] == "G"){
                if(auxparamet[2] == usr && auxparamet[0] != "0"){
                    auxparamet[0] = "0";
                    ret += auxparamet[0]+","+auxparamet[1]+","+auxparamet[2]+"\n";
                    continue;
                }

            }

        }
        ret += auxline[i]+"\n";

    }
    return ret;
}

int existeusr(string fil,string usr)
{
    vector<string> auxline = split(fil,'\n');
    vector<string> auxparamet;
    for (unsigned int i = 0; i< auxline.size(); i++) {
        auxparamet = split(auxline[i],',');
        if(auxparamet[1] == "U"){
            if(auxparamet[3] == usr && auxparamet[0] != "0"){

                return atoi(auxparamet[0].c_str());
            }

        }
    }
    return -1;
}

int idusr(string fil)
{
    vector<string> auxline = split(fil,'\n');
    vector<string> auxparamet;
    vector<string> auxgrp;
    for (unsigned int i = 0; i< auxline.size(); i++) {
        auxparamet = split(auxline[i],',');
        if(auxparamet[1] == "U"){
            auxgrp.push_back(auxline[i]);
        }
    }
    if(auxgrp.size()>0){
        vector<string> auxid = split(auxgrp[auxgrp.size()-1],',');
        return atoi(auxid[0].c_str())+1;
    }
    return -1;
}

void mkusr()
{
    if(usr == "")
    {
        printf("\nError, necesita ingresar un nombre valido\n\n");
        return;
    }

    if(pwd == "")
    {
        printf("\nError, necesita ingresar un nombre valido\n\n");
        return;
    }

    if(grp == "")
    {
        printf("\nError, necesita ingresar un nombre valido\n\n");
        return;
    }

    if(usr.length() > 10){
        printf("\nError, el tamaño del nombre debe ser menor o igual a 10\n\n");
        return;
    }

    if(pwd.length() > 10){
        printf("\nError, el tamaño de la contraseña debe ser menor o igual a 10\n\n");
        return;
    }

    if(grp.length() > 10){
        printf("\nError, el tamaño del grupo debe ser menor o igual a 10\n\n");
        return;
    }

    if(idusuarioactual != 1)
    {
        printf("\nError el usuario actual no puede usar el comando mkgrp permiso denegado\n\n");
        return;
    }

    for(int i = 0; i<maxd ; i++)
    {
        for(int j = 0; j<maxp; j++)
        {
            if(mounts[i][j].id == idactual)
            {
                if(mounts[i][j].direccion == -1)
                {
                    printf("\nError, particion %s no montada\n\n",id.c_str());
                    return;
                }

                FILE* f = fopen(mounts[i][j].path.c_str(),"r+b");
                SB sb;
                int dirsb = -1;
                if(mounts[i][j].type == 'p')
                {
                    fseek(f,mounts[i][j].direccion,SEEK_SET);
                    dirsb = mounts[i][j].direccion;
                }else
                {
                    fseek(f,mounts[i][j].direccion + sizeof(EBR),SEEK_SET);
                    dirsb = mounts[i][j].direccion + sizeof(EBR);
                }
                fread(&sb,sizeof(sb),1,f);
                INODO aux;
                BARCHIVO archi;
                fseek(f,sb.s_inode_start+1*sb.s_inode_size,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);

                string fil = "";
                for(int r = 0; r<12; r++)
                {
                    if(aux.i_block[r] != -1)
                    {
                        fseek(f,sb.s_block_start+aux.i_block[r]*sb.s_block_size,SEEK_SET);
                        clean_char(archi.b_content,64);
                        fread(&archi,sizeof(archi),1,f);
                        for (int gggg = 0; gggg < 64; gggg++) {
                            if(archi.b_content[gggg] == '\0'){
                                break;
                            }
                            fil += archi.b_content[gggg];
                        }
                    }
                }

                int ggg = existegrp(fil,remplazar(grp));
                if(ggg == -1)
                {
                    printf("\nNo se puede crear el usuario %s por que no existe el grupo %s\n\n",usr.c_str(),grp.c_str());
                    fclose(f);
                    return;
                }

                int gggt = existeusr(fil,remplazar(usr));
                if(gggt != -1)
                {
                    printf("\nNo se puede crear el usuario %s por que ya existe\n\n",usr.c_str());
                    fclose(f);
                    return;
                }

                int ur = idusr(fil);
                if(ur == -1)
                {
                    printf("\nError ya no se pueden agregar mas grupos\n\n");
                    fclose(f);
                    return;
                }



                string nuevacad = "";
                nuevacad += to_string(ur);
                nuevacad += ',';
                nuevacad += 'U';
                nuevacad += ',';
                nuevacad += grp;
                for(int re = grp.length(); re <10; re++)
                {
                    nuevacad += " ";
                }
                nuevacad += ',';
                nuevacad += usr;
                for(int re = usr.length(); re <10; re++)
                {
                    nuevacad += " ";
                }
                nuevacad += ',';
                nuevacad += pwd;
                for(int re = pwd.length(); re <10; re++)
                {
                    nuevacad += ' ';
                }
                nuevacad += '\n';

                fil += nuevacad;

                int ptee = guardarCadenaUsers(fil,f,sb,dirsb,aux);
                if(ptee == 1){
                    printf("\nSe creo correctamente el usuario\n\n");
                    if(sb.s_filesystem_type == 3)
                    {
                        JOURNAL jou[sb.s_inodes_count];
                        fseek(f,dirsb+sizeof(sb),SEEK_SET);
                        fread(&jou,sizeof(jou),1,f);
                        int posj = buscarvaciojournal(jou,sb.s_inodes_count);
                        jou[posj].type_trans = 3;
                        jou[posj].type = 0;
                        jou[posj].grupo = 0;
                        jou[posj].permiso = 0;
                        jou[posj].propietario = 0;
                        jou[posj].ipadre = 0;
                        copiarS(jou[posj].name,usr,usr.length());
                        strcat(jou[posj].contenido,pwd.c_str());
                        strcat(jou[posj].contenido,",");
                        strcat(jou[posj].contenido,grp.c_str());

                        fecha(jou[posj].j_time);
                        fseek(f,dirsb+sizeof(sb),SEEK_SET);
                        fwrite(&jou,sizeof(jou),1,f);

                    }
                }else{
                    printf("\nNo se pudo crear el usuario\n\n");

                }
                fclose(f);
            }
        }
    }
}

void rmusr()
{
    if(usr == "")
    {
        printf("\nError, necesita ingresar un nombre valido\n\n");
        return;
    }

    if(usr.length() > 10){
        printf("\nError, el tamaño del nombre debe ser menor o igual a 10\n\n");
        return;
    }

    if(idusuarioactual != 1)
    {
        printf("\nError el usuario actual no puede usar el comando mkgrp permiso denegado\n\n");
        return;
    }

    for(int i = 0; i<maxd ; i++)
    {
        for(int j = 0; j<maxp; j++)
        {
            if(mounts[i][j].id == idactual)
            {
                if(mounts[i][j].direccion == -1)
                {
                    printf("\nError, particion %s no montada\n\n",id.c_str());
                    return;
                }

                FILE* f = fopen(mounts[i][j].path.c_str(),"r+b");
                SB sb;
                int dirsb = -1;
                if(mounts[i][j].type == 'p')
                {
                    fseek(f,mounts[i][j].direccion,SEEK_SET);
                    dirsb = mounts[i][j].direccion;
                }else
                {
                    fseek(f,mounts[i][j].direccion + sizeof(EBR),SEEK_SET);
                    dirsb = mounts[i][j].direccion + sizeof(EBR);
                }
                fread(&sb,sizeof(sb),1,f);
                INODO aux;
                BARCHIVO archi;
                fseek(f,sb.s_inode_start+1*sb.s_inode_size,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);

                string fil = "";
                for(int r = 0; r<12; r++)
                {
                    if(aux.i_block[r] != -1)
                    {
                        fseek(f,sb.s_block_start+aux.i_block[r]*sb.s_block_size,SEEK_SET);
                        clean_char(archi.b_content,64);
                        fread(&archi,sizeof(archi),1,f);
                        for (int gggg = 0; gggg < 64; gggg++) {
                            if(archi.b_content[gggg] == '\0'){
                                break;
                            }
                            fil += archi.b_content[gggg];
                        }
                    }
                }

                int gggt = existeusr(fil,remplazar(usr));
                if(gggt == -1)
                {
                    printf("\nNo se puede Eliminar el usuario %s por que no existe\n\n",usr.c_str());
                    fclose(f);
                    return;
                }

                string ptgt = eliminarUsrGrp(fil,remplazar(usr),'u');
                cout << ptgt.c_str();
                if(ptgt != ""){
                    guardarCadenaUsers(ptgt,f,sb,dirsb,aux);
                    printf("\nSe elimino el usuario con Exito\n\n");
                    if(sb.s_filesystem_type == 3)
                    {
                        JOURNAL jou[sb.s_inodes_count];
                        fseek(f,dirsb+sizeof(sb),SEEK_SET);
                        fread(&jou,sizeof(jou),1,f);
                        int posj = buscarvaciojournal(jou,sb.s_inodes_count);
                        jou[posj].type_trans = 5;
                        jou[posj].type = 0;
                        jou[posj].grupo = 0;
                        jou[posj].permiso = 0;
                        jou[posj].propietario = 0;
                        jou[posj].ipadre = 0;
                        copiarS(jou[posj].name,usr,usr.length());


                        fecha(jou[posj].j_time);
                        fseek(f,dirsb+sizeof(sb),SEEK_SET);
                        fwrite(&jou,sizeof(jou),1,f);

                    }
                }else{
                    printf("\nNo se pudo eliminar el usuario\n\n");

                }
                fclose(f);
            }
        }
    }
}

void mkfile()
{
    inodon = -1;
    inodop = 0;
    inodos = 0;
    if(path == ""){
        printf("\nError se necesita ingresar una ruta valida\n\n");
        return;
    }
    if(idactual == ""){
        printf("\nError se necesita una sesion activa para este comando\n\n");
        return;
    }
    PM part = buscarmontada(idactual);
    if(part.direccion == -1)
    {
        printf("\nError no se encontro la particion para realizar el comando\n\n");
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }

    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    if(path[0] != '/')
    {
        printf("\nError ruta no valida para la creacion del archivo\n\n");
        fclose(f);
        return;
    }
    int ds = 0;
    vector<string> ruta = split(path,'/');
    copy_vars();

    ds = loopruta(ruta,1,0,sb,f,'a');

    if(ds > -1){
        if(sb.s_filesystem_type == 3)
        {
            JOURNAL jou[sb.s_inodes_count];
            fseek(f,isb+sizeof(sb),SEEK_SET);
            fread(&jou,sizeof(jou),1,f);
            int posj = buscarvaciojournal(jou,sb.s_inodes_count);
            jou[posj].type_trans = 7;
            jou[posj].type = 1;
            jou[posj].grupo = idgrupoactual;
            jou[posj].permiso = 664;
            jou[posj].propietario = idusuarioactual;
            jou[posj].ipadre = inodop;
            copiarS(jou[posj].name,ruta[ruta.size()-1],12);
            char tipp ='*';
            if(cont == "")
            {
                tipp = 's';
            }else
            {
                tipp = 'r';

            }
            if(tipp == 'r')
            {
                //copiarS(jou[posj].contenido,cont,100);
                sprintf(jou[posj].contenido,"%s,%s",cont.c_str(),path.c_str());
            }else if(tipp == 's')
            {
                sprintf(jou[posj].contenido,"%i,%s",size,path.c_str());
            }

            fecha(jou[posj].j_time);
            fseek(f,isb+sizeof(sb),SEEK_SET);
            fwrite(&jou,sizeof(jou),1,f);

        }
        printf("\nSe creo con exito la carpeta o Archivo\n\n");
    }else{
        printf("\nNo se pudo crear El Archivo o carpeta\n\n");
    }
    fseek(f,isb,SEEK_SET);
    fwrite(&sb,sizeof(sb),1,f);
    fclose(f);
}

PM buscarmontada(string idac)
{
    PM ret;
    ret.direccion = -2;
    for(int i=0; i< maxd; i++)
    {
        for(int j = 0; j<maxp ; j++)
        {
            if(idac == mounts[i][j].id)
            {
                if(mounts[i][j].direccion == -1)
                {
                    printf("\nError particion no montada para el id %s\n\n",idac.c_str());
                    return ret;

                }
                else
                {

                    return mounts[i][j];
                }
            }
        }
    }
    return ret;

}

int loopruta(vector<string> ruta, int posr, int inodoa,SB& sb,FILE* f, char tipo){

    INODO act;
    fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
    fread(&act,sizeof(act),1,f);
    BCARPETA bact;
    int tam = 0;
    for(int i = 0; i<12;i++){
        if(act.i_block[i] != -1){
            fseek(f,sb.s_block_start+act.i_block[i]*sb.s_block_size,SEEK_SET);
            fread(&bact,sizeof(bact),1,f);
            for (int j = 0; j< 4; j++) {
                if(string(bact.b_content[j].b_name).compare(ruta[posr]) == 0)
                {
                    if(unsigned(posr) == ruta.size()-1)
                    {
                        printf("\nYa existe \n\n");
                        return -1;
                    }
                    inodop = inodos;
                    inodos = inodoa;
                    tam = loopruta(ruta,posr+1,bact.b_content[j].b_inode,sb,f,tipo);
                    if(tam > -1){
                        fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
                        fread(&act,sizeof(act),1,f);
                        act.i_size += tam;
                        fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
                        fwrite(&act,sizeof(act),1,f);
                    }
                    return tam;
                }
            }
        }
    }

    if(act.i_block[12] != -1){
        BAPUNTADOR bap;
        fseek(f,sb.s_block_start+act.i_block[13]*sb.s_block_size,SEEK_SET);
        fread(&bap,sizeof(bap),1,f);
        for(int in = 0; in<16; in++){
            if(bap.b_pointers[in] != -1){
                fseek(f,sb.s_block_start+bap.b_pointers[in]*sb.s_block_size,SEEK_SET);
                fread(&bact,sizeof(bact),1,f);
                for (int j = 0; j< 4; j++) {
                    if(string(bact.b_content[j].b_name) == ruta[posr]){
                        if(unsigned(posr) == ruta.size()-1){
                            printf("\nYa existe \n\n");
                            return -1;
                        }
                        inodop = inodos;
                        inodos = inodoa;
                        tam = loopruta(ruta,posr+1,bact.b_content[j].b_inode,sb,f,tipo);
                        if(tam > -1){
                            fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
                            fread(&act,sizeof(act),1,f);
                            act.i_size += tam;
                            fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
                            fwrite(&act,sizeof(act),1,f);
                        }
                        return tam;
                    }
                }
            }
        }
    }

    if(aux_atribp == 's' && unsigned(posr) != ruta.size()-1){
        //llamar a crear
        int t = crearAC('c',sb,inodoa,f,ruta[posr]);
        //llamar recursivo con posr +1
        inodop = inodos;
        inodos = inodoa;
        tam = loopruta(ruta,posr+1,inodon,sb,f,tipo);
        if(tam > -1){
            fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
            fread(&act,sizeof(act),1,f);
            act.i_size += tam;
            fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
            fwrite(&act,sizeof(act),1,f);
        }
        return tam;
    }

    if(unsigned(posr) == ruta.size()-1){
        tam = crearAC(tipo,sb,inodoa,f,ruta[ruta.size()-1]);
        if(tam > -1){
            fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
            fread(&act,sizeof(act),1,f);
            act.i_size += tam;
            fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
            fwrite(&act,sizeof(act),1,f);
        }
        return tam;
    }

    return -1;
}

int crearAC(char tipo,SB& sb, int inodoa,FILE* f,string nombre)
{
    INODO p;
    fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
    fread(&p,sizeof(p),1,f);
    BCARPETA c;
    char tempb[sb.s_blocks_count];
    char tempi[sb.s_inodes_count];
    fseek(f,sb.s_bm_block_start,SEEK_SET);
    fread(&tempb,sizeof(tempb),1,f);
    fseek(f,sb.s_bm_inode_start,SEEK_SET);
    fread(&tempi,sizeof(tempi),1,f);

    for(int i = 0; i< 12; i++){
        if(p.i_block[i] != -1){
            fseek(f,sb.s_block_start+p.i_block[i]*sb.s_block_size,SEEK_SET);
            fread(&c,sizeof(c),1,f);
            for(int j = 0; j<4; j++){
                if(c.b_content[j].b_inode == -1){
                    if(tipo == 'c'){
                        //char tempb[sb.s_blocks_count];
                        //char tempi[sb.s_inodes_count];
                        //fseek(f,sb.s_bm_block_start,SEEK_SET);
                        //fread(&tempb,sizeof(tempb),1,f);
                        //fseek(f,sb.s_bm_inode_start,SEEK_SET);
                        //fread(&tempi,sizeof(tempi),1,f);

                        int ni = buscarlibre(tempi,sb.s_inodes_count);
                        sb.s_free_inodes_count = sb.s_free_inodes_count-1;
                        int nb = buscarlibre(tempb,sb.s_blocks_count);
                        sb.s_free_blocks_count = sb.s_free_blocks_count-1;

                        inodon = ni;

                        tempi[ni] = '1';
                        tempb[nb] = '1';

                        INODO nuev;
                        setINODO(nuev,'0',664);

                        copiarS(c.b_content[j].b_name,nombre,nombre.length());
                        c.b_content[j].b_inode = ni;

                        sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                        sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                        BCARPETA bc;
                        setBLOQUEC(bc,inodoa,ni);

                        nuev.i_block[0] = nb;
                        fecha(nuev.i_mtime);

                        fseek(f,sb.s_bm_block_start,SEEK_SET);
                        fwrite(&tempb,sizeof(tempb),1,f);

                        fseek(f,sb.s_bm_inode_start,SEEK_SET);
                        fwrite(&tempi,sizeof(tempi),1,f);

                        fseek(f,sb.s_block_start+p.i_block[i]*sb.s_block_size,SEEK_SET);
                        fwrite(&c,sizeof(c),1,f);

                        fseek(f,sb.s_block_start+nb*sb.s_block_size,SEEK_SET);
                        fwrite(&bc,sizeof(bc),1,f);

                        fseek(f,sb.s_inode_start+ni*sb.s_inode_size,SEEK_SET);
                        fwrite(&nuev,sizeof(nuev),1,f);

                        return 0;

                    }else{
                        int inodoarchivo = buscarlibre(tempi,sb.s_inodes_count);
                        sb.s_free_inodes_count = sb.s_free_inodes_count-1;

                        inodon = inodoarchivo;
                        strcat(c.b_content[j].b_name,nombre.c_str());

                        c.b_content[j].b_inode = inodoarchivo;
                        tempi[inodoarchivo] = '1';

                        fseek(f,sb.s_block_start+p.i_block[i]*sb.s_block_size,SEEK_SET);
                        fwrite(&c,sizeof(c),1,f);

                        char tipp ='*';
                        if(aux_cont == "")
                        {
                            tipp = 's';
                        }else
                        {
                            tipp = 'r';

                        }

                        INODO arc;
                        setINODO(arc,'1',664);

                        BARCHIVO co;
                        setBLOQUEA(co);


                        FILE* fi = fopen(aux_cont.c_str(),"r+b");
                        char char_temporal = 0;


                        int indicebloque = -1;
                        int indicen = 0;
                        int t = 0,e = 0;

                        for(t = 0; t<12 ; t++)
                        {
                            clean_char(co.b_content,64);
                            indicebloque = 0;
                            arc.i_block[t] = buscarlibre(tempb,sb.s_blocks_count);
                            sb.s_free_blocks_count = sb.s_free_blocks_count-1;
                            tempb[arc.i_block[t]] = '1';
                            if(tipp == 'r')
                            {
                                do
                                {
                                    if(indicebloque == 64)
                                    {
                                        fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                        fwrite(&co,sizeof(co),1,f);
                                        break;
                                    }
                                    if(char_temporal != 0)
                                    {
                                        co.b_content[indicebloque] = char_temporal;
                                        indicebloque++;
                                        arc.i_size = arc.i_size+1;
                                    }

                                }while((char_temporal = fgetc(fi)) != EOF);
                                if(char_temporal == EOF)
                                {
                                    fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                    fwrite(&co,sizeof(co),1,f);

                                    if(tipp == 'r')
                                    fclose(fi);

                                    fseek(f,sb.s_bm_block_start,SEEK_SET);
                                    fwrite(&tempb,sizeof(tempb),1,f);

                                    fseek(f,sb.s_bm_inode_start,SEEK_SET);
                                    fwrite(&tempi,sizeof(tempi),1,f);

                                    fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                    fwrite(&co,sizeof(co),1,f);

                                    sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                                    sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                                    fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                                    fwrite(&arc,sizeof(arc),1,f);

                                    //fseek(f,isb,SEEK_SET);
                                    //fwrite(&sb,sizeof(sb),1,f);
                                    printf("\nSe creo el archivo correctamente\n\n");
                                    return aux_size;
                                    //fclose(f);
                                }
                                if(indicebloque == 64){
                                    continue;
                                }
                            }else if(tipp == 's')
                            {

                                for( ; e<aux_size ; e++)
                                {
                                    if(indicebloque == 64)
                                    {
                                        fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                        fwrite(&co,sizeof(co),1,f);
                                        break;
                                    }
                                    co.b_content[indicebloque] = indicen+48;
                                    indicen++;
                                    indicebloque++;
                                    arc.i_size += 1;
                                    if(indicen == 10)
                                    {
                                        indicen = 0;
                                    }

                                }
                                if(indicebloque == 64)
                                {
                                    continue;
                                }
                            }

                            fseek(f,sb.s_bm_block_start,SEEK_SET);
                            fwrite(&tempb,sizeof(tempb),1,f);

                            fseek(f,sb.s_bm_inode_start,SEEK_SET);
                            fwrite(&tempi,sizeof(tempi),1,f);

                            fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                            fwrite(&co,sizeof(co),1,f);

                            sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                            sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                            fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                            fwrite(&arc,sizeof(arc),1,f);
                            inodop = inodoa;
                            //fseek(f,isb,SEEK_SET);
                            //fwrite(&sb,sizeof(sb),1,f);
                            printf("\nSe creo el archivo correctamente\n\n");
                            return aux_size;
                            //fclose(f);

                        }

                        if(tipp == 'r')
                        fclose(fi);
                    }
                }
            }
        }else{
            int nbb = buscarlibre(tempb,sb.s_blocks_count);
            tempb[nbb] = '1';
            p.i_block[i] = nbb;


            if(tipo == 'c'){


                int ni = buscarlibre(tempi,sb.s_inodes_count);
                sb.s_free_inodes_count = sb.s_free_inodes_count-1;
                int nb = buscarlibre(tempb,sb.s_blocks_count);
                sb.s_free_blocks_count = sb.s_free_blocks_count-1;

                inodon = ni;

                tempi[ni] = '1';
                tempb[nb] = '1';

                INODO nuev;
                setINODO(nuev,'0',664);

                BCARPETA bcc;
                setBLOQUEC2(bcc);

                copiarS(bcc.b_content[0].b_name,nombre,nombre.length());
                bcc.b_content[0].b_inode = ni;

                fseek(f,sb.s_block_start+nbb*sb.s_block_size,SEEK_SET);
                fwrite(&bcc,sizeof(bcc),1,f);

                sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                BCARPETA bc;
                setBLOQUEC(bc,inodoa,ni);

                nuev.i_block[0] = nb;
                fecha(nuev.i_mtime);

                fseek(f,sb.s_bm_block_start,SEEK_SET);
                fwrite(&tempb,sizeof(tempb),1,f);

                fseek(f,sb.s_bm_inode_start,SEEK_SET);
                fwrite(&tempi,sizeof(tempi),1,f);

                fseek(f,sb.s_block_start+nb*sb.s_block_size,SEEK_SET);
                fwrite(&bc,sizeof(bc),1,f);

                fseek(f,sb.s_inode_start+ni*sb.s_inode_size,SEEK_SET);
                fwrite(&nuev,sizeof(nuev),1,f);

                fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
                fwrite(&p,sizeof(p),1,f);

                return 0;

            }else{
                int inodoarchivo = buscarlibre(tempi,sb.s_inodes_count);
                sb.s_free_inodes_count = sb.s_free_inodes_count-1;

                inodon = inodoarchivo;
                BCARPETA bcc;
                setBLOQUEC2(bcc);

                copiarS(bcc.b_content[0].b_name,nombre,nombre.length());
                bcc.b_content[0].b_inode = inodoarchivo;

                fseek(f,sb.s_block_start+nbb*sb.s_block_size,SEEK_SET);
                fwrite(&bcc,sizeof(bcc),1,f);

                tempi[inodoarchivo] = '1';

                char tipp ='*';
                if(aux_cont == "")
                {
                    tipp = 's';
                }else
                {
                    tipp = 'r';

                }
                //fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
                //fread(&p,sizeof(p),1,f);
                INODO arc;
                setINODO(arc,'1',664);

                BARCHIVO co;
                setBLOQUEA(co);


                FILE* fi = fopen(aux_cont.c_str(),"r+b");
                char char_temporal = 0;


                int indicebloque = -1;
                int indicen = 0;
                int t = 0,e = 0;

                for(t = 0; t<12 ; t++)
                {
                    clean_char(co.b_content,64);
                    indicebloque = 0;
                    arc.i_block[t] = buscarlibre(tempb,sb.s_blocks_count);
                    sb.s_free_blocks_count = sb.s_free_blocks_count-1;
                    tempb[arc.i_block[t]] = '1';
                    if(tipp == 'r')
                    {
                        do
                        {
                            if(indicebloque == 64)
                            {
                                fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                fwrite(&co,sizeof(co),1,f);
                                break;
                            }
                            if(char_temporal != 0)
                            {
                                co.b_content[indicebloque] = char_temporal;
                                indicebloque++;
                                arc.i_size = arc.i_size+1;
                            }

                        }while((char_temporal = fgetc(fi)) != EOF);
                        if(char_temporal == EOF)
                        {
                            fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                            fwrite(&co,sizeof(co),1,f);


                            if(tipp == 'r')
                            fclose(fi);

                            fseek(f,sb.s_bm_block_start,SEEK_SET);
                            fwrite(&tempb,sizeof(tempb),1,f);

                            fseek(f,sb.s_bm_inode_start,SEEK_SET);
                            fwrite(&tempi,sizeof(tempi),1,f);

                            fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                            fwrite(&co,sizeof(co),1,f);

                            sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                            sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                            fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                            fwrite(&arc,sizeof(arc),1,f);

                            fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
                            fwrite(&p,sizeof(p),1,f);
                            inodop = inodoa;
                            //fseek(f,isb,SEEK_SET);
                            //fwrite(&sb,sizeof(sb),1,f);
                            printf("\nSe creo el archivo correctamente\n\n");
                            return aux_size;
                            //fclose(f);

                        }
                        if(indicebloque == 64)
                        {
                            continue;
                        }
                    }else if(tipp == 's')
                    {

                        for( ; e<aux_size ; e++)
                        {
                            if(indicebloque == 64)
                            {
                                fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                fwrite(&co,sizeof(co),1,f);
                                break;
                            }
                            co.b_content[indicebloque] = indicen+48;
                            indicen++;
                            indicebloque++;
                            arc.i_size += 1;
                            if(indicen == 10)
                            {
                                indicen = 0;
                            }

                        }
                        if(indicebloque == 64)
                        {
                            continue;
                        }
                    }

                    if(tipp == 'r')
                    fclose(fi);

                    fseek(f,sb.s_bm_block_start,SEEK_SET);
                    fwrite(&tempb,sizeof(tempb),1,f);

                    fseek(f,sb.s_bm_inode_start,SEEK_SET);
                    fwrite(&tempi,sizeof(tempi),1,f);

                    fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                    fwrite(&co,sizeof(co),1,f);

                    sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                    sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                    fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                    fwrite(&arc,sizeof(arc),1,f);

                    fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
                    fwrite(&p,sizeof(p),1,f);
                    inodop = inodoa;
                    //fseek(f,isb,SEEK_SET);
                    //fwrite(&sb,sizeof(sb),1,f);
                    printf("\nSe creo el archivo correctamente\n\n");
                    return aux_size;
                    //fclose(f);

                }
            }
        }
    }

    BAPUNTADOR bap;

    if(p.i_block[12] != -1){
        fseek(f,sb.s_block_start+p.i_block[12]*sb.s_block_size,SEEK_SET);
        fread(&bap,sizeof(bap),1,f);
        for (int n = 0; n<16; n++) {
            if(bap.b_pointers[n] != -1){
                fseek(f,sb.s_block_start+bap.b_pointers[n]*sb.s_block_size,SEEK_SET);
                fread(&c,sizeof(c),1,f);
                for(int j = 0; j<4; j++){
                    if(c.b_content[j].b_inode == -1){
                        if(tipo == 'c'){
                            //char tempb[sb.s_blocks_count];
                            //char tempi[sb.s_inodes_count];
                            //fseek(f,sb.s_bm_block_start,SEEK_SET);
                            //fread(&tempb,sizeof(tempb),1,f);
                            //fseek(f,sb.s_bm_inode_start,SEEK_SET);
                            //fread(&tempi,sizeof(tempi),1,f);

                            int ni = buscarlibre(tempi,sb.s_inodes_count);
                            sb.s_free_inodes_count = sb.s_free_inodes_count-1;
                            int nb = buscarlibre(tempb,sb.s_blocks_count);
                            sb.s_free_blocks_count = sb.s_free_blocks_count-1;

                            inodon = ni;

                            tempi[ni] = '1';
                            tempb[nb] = '1';

                            INODO nuev;
                            setINODO(nuev,'0',664);

                            copiarS(c.b_content[j].b_name,nombre,nombre.length());
                            c.b_content[j].b_inode = ni;

                            sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                            sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                            BCARPETA bc;
                            setBLOQUEC(bc,inodoa,ni);

                            nuev.i_block[0] = nb;
                            fecha(nuev.i_mtime);

                            fseek(f,sb.s_bm_block_start,SEEK_SET);
                            fwrite(&tempb,sizeof(tempb),1,f);

                            fseek(f,sb.s_bm_inode_start,SEEK_SET);
                            fwrite(&tempi,sizeof(tempi),1,f);

                            fseek(f,sb.s_block_start+bap.b_pointers[n]*sb.s_block_size,SEEK_SET);
                            fwrite(&c,sizeof(c),1,f);

                            fseek(f,sb.s_block_start+nb*sb.s_block_size,SEEK_SET);
                            fwrite(&bc,sizeof(bc),1,f);

                            fseek(f,sb.s_inode_start+ni*sb.s_inode_size,SEEK_SET);
                            fwrite(&nuev,sizeof(nuev),1,f);

                            return 0;

                        }else{
                            int inodoarchivo = buscarlibre(tempi,sb.s_inodes_count);
                            sb.s_free_inodes_count = sb.s_free_inodes_count-1;

                            inodon = inodoarchivo;
                            strcat(c.b_content[j].b_name,nombre.c_str());

                            c.b_content[j].b_inode = inodoarchivo;
                            tempi[inodoarchivo] = '1';

                            fseek(f,sb.s_block_start+bap.b_pointers[n]*sb.s_block_size,SEEK_SET);
                            fwrite(&c,sizeof(c),1,f);

                            char tipp ='*';
                            if(aux_cont == "")
                            {
                                tipp = 's';
                            }else
                            {
                                tipp = 'r';

                            }

                            INODO arc;
                            setINODO(arc,'1',664);

                            BARCHIVO co;
                            setBLOQUEA(co);


                            FILE* fi = fopen(aux_cont.c_str(),"r+b");
                            char char_temporal = 0;


                            int indicebloque = -1;
                            int indicen = 0;
                            int t = 0,e = 0;

                            for(t = 0; t<12 ; t++)
                            {
                                clean_char(co.b_content,64);
                                indicebloque = 0;
                                arc.i_block[t] = buscarlibre(tempb,sb.s_blocks_count);
                                sb.s_free_blocks_count = sb.s_free_blocks_count-1;
                                tempb[arc.i_block[t]] = '1';
                                if(tipp == 'r')
                                {
                                    do
                                    {
                                        if(indicebloque == 64)
                                        {
                                            fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                            fwrite(&co,sizeof(co),1,f);
                                            break;
                                        }
                                        if(char_temporal != 0)
                                        {
                                            co.b_content[indicebloque] = char_temporal;
                                            indicebloque++;
                                            arc.i_size = arc.i_size+1;
                                        }

                                    }while((char_temporal = fgetc(fi)) != EOF);
                                    if(char_temporal == EOF)
                                    {
                                        fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                        fwrite(&co,sizeof(co),1,f);

                                        if(tipp == 'r')
                                        fclose(fi);

                                        fseek(f,sb.s_bm_block_start,SEEK_SET);
                                        fwrite(&tempb,sizeof(tempb),1,f);

                                        fseek(f,sb.s_bm_inode_start,SEEK_SET);
                                        fwrite(&tempi,sizeof(tempi),1,f);

                                        fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                        fwrite(&co,sizeof(co),1,f);

                                        sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                                        sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                                        fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                                        fwrite(&arc,sizeof(arc),1,f);

                                        //fseek(f,isb,SEEK_SET);
                                        //fwrite(&sb,sizeof(sb),1,f);
                                        printf("\nSe creo el archivo correctamente\n\n");
                                        return aux_size;
                                        //fclose(f);
                                    }
                                    if(indicebloque == 64){
                                        continue;
                                    }
                                }else if(tipp == 's')
                                {

                                    for( ; e<aux_size ; e++)
                                    {
                                        if(indicebloque == 64)
                                        {
                                            fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                            fwrite(&co,sizeof(co),1,f);
                                            break;
                                        }
                                        co.b_content[indicebloque] = indicen+48;
                                        indicen++;
                                        indicebloque++;
                                        arc.i_size += 1;
                                        if(indicen == 10)
                                        {
                                            indicen = 0;
                                        }

                                    }
                                    if(indicebloque == 64)
                                    {
                                        continue;
                                    }
                                }

                                fseek(f,sb.s_bm_block_start,SEEK_SET);
                                fwrite(&tempb,sizeof(tempb),1,f);

                                fseek(f,sb.s_bm_inode_start,SEEK_SET);
                                fwrite(&tempi,sizeof(tempi),1,f);

                                fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                fwrite(&co,sizeof(co),1,f);

                                sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                                sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                                fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                                fwrite(&arc,sizeof(arc),1,f);
                                inodop = inodoa;
                                //fseek(f,isb,SEEK_SET);
                                //fwrite(&sb,sizeof(sb),1,f);
                                printf("\nSe creo el archivo correctamente\n\n");
                                return aux_size;
                                //fclose(f);

                            }

                            if(tipp == 'r')
                            fclose(fi);
                        }
                    }
                }
            }else{

                int nbb = buscarlibre(tempb,sb.s_blocks_count);
                tempb[nbb] = '1';
                bap.b_pointers[n] = nbb;


                if(tipo == 'c'){


                    int ni = buscarlibre(tempi,sb.s_inodes_count);
                    sb.s_free_inodes_count = sb.s_free_inodes_count-1;
                    int nb = buscarlibre(tempb,sb.s_blocks_count);
                    sb.s_free_blocks_count = sb.s_free_blocks_count-1;

                    inodon = ni;

                    tempi[ni] = '1';
                    tempb[nb] = '1';

                    INODO nuev;
                    setINODO(nuev,'0',664);

                    BCARPETA bcc;
                    setBLOQUEC2(bcc);

                    copiarS(bcc.b_content[0].b_name,nombre,nombre.length());
                    bcc.b_content[0].b_inode = ni;

                    fseek(f,sb.s_block_start+nbb*sb.s_block_size,SEEK_SET);
                    fwrite(&bcc,sizeof(bcc),1,f);

                    sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                    sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                    BCARPETA bc;
                    setBLOQUEC(bc,inodoa,ni);

                    nuev.i_block[0] = nb;
                    fecha(nuev.i_mtime);

                    fseek(f,sb.s_bm_block_start,SEEK_SET);
                    fwrite(&tempb,sizeof(tempb),1,f);

                    fseek(f,sb.s_bm_inode_start,SEEK_SET);
                    fwrite(&tempi,sizeof(tempi),1,f);

                    fseek(f,sb.s_block_start+nb*sb.s_block_size,SEEK_SET);
                    fwrite(&bc,sizeof(bc),1,f);

                    fseek(f,sb.s_inode_start+ni*sb.s_inode_size,SEEK_SET);
                    fwrite(&nuev,sizeof(nuev),1,f);

                    fseek(f,sb.s_inode_start+p.i_block[12]*sb.s_inode_size,SEEK_SET);
                    fwrite(&bap,sizeof(bap),1,f);

                    return 0;

                }else{
                    int inodoarchivo = buscarlibre(tempi,sb.s_inodes_count);
                    sb.s_free_inodes_count = sb.s_free_inodes_count-1;

                    inodon = inodoarchivo;
                    BCARPETA bcc;
                    setBLOQUEC2(bcc);

                    copiarS(bcc.b_content[0].b_name,nombre,nombre.length());
                    bcc.b_content[0].b_inode = inodoarchivo;

                    fseek(f,sb.s_block_start+nbb*sb.s_block_size,SEEK_SET);
                    fwrite(&bcc,sizeof(bcc),1,f);

                    tempi[inodoarchivo] = '1';

                    //fseek(f,sb.s_block_start+p.i_block[i]*sb.s_block_size,SEEK_SET);
                    //fwrite(&c,sizeof(c),1,f);

                    char tipp ='*';
                    if(aux_cont == "")
                    {
                        tipp = 's';
                    }else
                    {
                        tipp = 'r';

                    }
                    //fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
                    //fread(&p,sizeof(p),1,f);
                    INODO arc;
                    setINODO(arc,'1',664);

                    BARCHIVO co;
                    setBLOQUEA(co);


                    FILE* fi = fopen(aux_cont.c_str(),"r+b");
                    char char_temporal = 0;


                    int indicebloque = -1;
                    int indicen = 0;
                    int t = 0,e = 0;

                    for(t = 0; t<12 ; t++)
                    {
                        clean_char(co.b_content,64);
                        indicebloque = 0;
                        arc.i_block[t] = buscarlibre(tempb,sb.s_blocks_count);
                        sb.s_free_blocks_count = sb.s_free_blocks_count-1;
                        tempb[arc.i_block[t]] = '1';
                        if(tipp == 'r')
                        {
                            do
                            {
                                if(indicebloque == 64)
                                {
                                    fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                    fwrite(&co,sizeof(co),1,f);
                                    break;
                                }
                                if(char_temporal != 0)
                                {
                                    co.b_content[indicebloque] = char_temporal;
                                    indicebloque++;
                                    arc.i_size = arc.i_size+1;
                                }

                            }while((char_temporal = fgetc(fi)) != EOF);
                            if(char_temporal == EOF)
                            {
                                fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                fwrite(&co,sizeof(co),1,f);


                                if(tipp == 'r')
                                fclose(fi);

                                fseek(f,sb.s_bm_block_start,SEEK_SET);
                                fwrite(&tempb,sizeof(tempb),1,f);

                                fseek(f,sb.s_bm_inode_start,SEEK_SET);
                                fwrite(&tempi,sizeof(tempi),1,f);

                                fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                fwrite(&co,sizeof(co),1,f);

                                sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                                sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                                fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                                fwrite(&arc,sizeof(arc),1,f);

                                fseek(f,sb.s_inode_start+p.i_block[12]*sb.s_inode_size,SEEK_SET);
                                fwrite(&bap,sizeof(bap),1,f);
                                inodop = inodoa;
                                //fseek(f,isb,SEEK_SET);
                                //fwrite(&sb,sizeof(sb),1,f);
                                printf("\nSe creo el archivo correctamente\n\n");
                                return aux_size;
                                //fclose(f);

                            }
                            if(indicebloque == 64)
                            {
                                continue;
                            }
                        }else if(tipp == 's')
                        {

                            for( ; e<aux_size ; e++)
                            {
                                if(indicebloque == 64)
                                {
                                    fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                    fwrite(&co,sizeof(co),1,f);
                                    break;
                                }
                                co.b_content[indicebloque] = indicen+48;
                                indicen++;
                                indicebloque++;
                                arc.i_size += 1;
                                if(indicen == 10)
                                {
                                    indicen = 0;
                                }

                            }
                            if(indicebloque == 64)
                            {
                                continue;
                            }
                        }

                        if(tipp == 'r')
                        fclose(fi);

                        fseek(f,sb.s_bm_block_start,SEEK_SET);
                        fwrite(&tempb,sizeof(tempb),1,f);

                        fseek(f,sb.s_bm_inode_start,SEEK_SET);
                        fwrite(&tempi,sizeof(tempi),1,f);

                        fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                        fwrite(&co,sizeof(co),1,f);

                        sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                        sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                        fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                        fwrite(&arc,sizeof(arc),1,f);

                        fseek(f,sb.s_inode_start+p.i_block[12]*sb.s_inode_size,SEEK_SET);
                        fwrite(&bap,sizeof(bap),1,f);
                        inodop = inodoa;
                        //fseek(f,isb,SEEK_SET);
                        //fwrite(&sb,sizeof(sb),1,f);
                        printf("\nSe creo el archivo correctamente\n\n");
                        return aux_size;
                        //fclose(f);

                    }
                }
            }

        }

    }else {
        setBAPUNTADOR(bap);
        int ibap = buscarlibre(tempb,sb.s_blocks_count);
        p.i_block[12] = ibap;
        fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
        fwrite(&p,sizeof(p),1,f);
        for (int n = 0; n<16; n++) {
            if(bap.b_pointers[n] != -1){
                fseek(f,sb.s_block_start+bap.b_pointers[n]*sb.s_block_size,SEEK_SET);
                fread(&c,sizeof(c),1,f);
                for(int j = 0; j<4; j++){
                    if(c.b_content[j].b_inode == -1){
                        if(tipo == 'c'){
                            //char tempb[sb.s_blocks_count];
                            //char tempi[sb.s_inodes_count];
                            //fseek(f,sb.s_bm_block_start,SEEK_SET);
                            //fread(&tempb,sizeof(tempb),1,f);
                            //fseek(f,sb.s_bm_inode_start,SEEK_SET);
                            //fread(&tempi,sizeof(tempi),1,f);

                            int ni = buscarlibre(tempi,sb.s_inodes_count);
                            sb.s_free_inodes_count = sb.s_free_inodes_count-1;
                            int nb = buscarlibre(tempb,sb.s_blocks_count);
                            sb.s_free_blocks_count = sb.s_free_blocks_count-1;

                            inodon = ni;

                            tempi[ni] = '1';
                            tempb[nb] = '1';

                            INODO nuev;
                            setINODO(nuev,'0',664);

                            copiarS(c.b_content[j].b_name,nombre,nombre.length());
                            c.b_content[j].b_inode = ni;

                            sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                            sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                            BCARPETA bc;
                            setBLOQUEC(bc,inodoa,ni);

                            nuev.i_block[0] = nb;
                            fecha(nuev.i_mtime);

                            fseek(f,sb.s_bm_block_start,SEEK_SET);
                            fwrite(&tempb,sizeof(tempb),1,f);

                            fseek(f,sb.s_bm_inode_start,SEEK_SET);
                            fwrite(&tempi,sizeof(tempi),1,f);

                            fseek(f,sb.s_block_start+bap.b_pointers[n]*sb.s_block_size,SEEK_SET);
                            fwrite(&c,sizeof(c),1,f);

                            fseek(f,sb.s_block_start+nb*sb.s_block_size,SEEK_SET);
                            fwrite(&bc,sizeof(bc),1,f);

                            fseek(f,sb.s_inode_start+ni*sb.s_inode_size,SEEK_SET);
                            fwrite(&nuev,sizeof(nuev),1,f);

                            return 0;

                        }else{
                            int inodoarchivo = buscarlibre(tempi,sb.s_inodes_count);
                            sb.s_free_inodes_count = sb.s_free_inodes_count-1;

                            inodon = inodoarchivo;
                            strcat(c.b_content[j].b_name,nombre.c_str());

                            c.b_content[j].b_inode = inodoarchivo;
                            tempi[inodoarchivo] = '1';

                            fseek(f,sb.s_block_start+bap.b_pointers[n]*sb.s_block_size,SEEK_SET);
                            fwrite(&c,sizeof(c),1,f);

                            char tipp ='*';
                            if(aux_cont == "")
                            {
                                tipp = 's';
                            }else
                            {
                                tipp = 'r';

                            }

                            INODO arc;
                            setINODO(arc,'1',664);

                            BARCHIVO co;
                            setBLOQUEA(co);


                            FILE* fi = fopen(aux_cont.c_str(),"r+b");
                            char char_temporal = 0;


                            int indicebloque = -1;
                            int indicen = 0;
                            int t = 0,e = 0;

                            for(t = 0; t<12 ; t++)
                            {
                                clean_char(co.b_content,64);
                                indicebloque = 0;
                                arc.i_block[t] = buscarlibre(tempb,sb.s_blocks_count);
                                sb.s_free_blocks_count = sb.s_free_blocks_count-1;
                                tempb[arc.i_block[t]] = '1';
                                if(tipp == 'r')
                                {
                                    do
                                    {
                                        if(indicebloque == 64)
                                        {
                                            fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                            fwrite(&co,sizeof(co),1,f);
                                            break;
                                        }
                                        if(char_temporal != 0)
                                        {
                                            co.b_content[indicebloque] = char_temporal;
                                            indicebloque++;
                                            arc.i_size = arc.i_size+1;
                                        }

                                    }while((char_temporal = fgetc(fi)) != EOF);
                                    if(char_temporal == EOF)
                                    {
                                        fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                        fwrite(&co,sizeof(co),1,f);

                                        if(tipp == 'r')
                                        fclose(fi);

                                        fseek(f,sb.s_bm_block_start,SEEK_SET);
                                        fwrite(&tempb,sizeof(tempb),1,f);

                                        fseek(f,sb.s_bm_inode_start,SEEK_SET);
                                        fwrite(&tempi,sizeof(tempi),1,f);

                                        fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                        fwrite(&co,sizeof(co),1,f);

                                        sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                                        sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                                        fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                                        fwrite(&arc,sizeof(arc),1,f);

                                        //fseek(f,isb,SEEK_SET);
                                        //fwrite(&sb,sizeof(sb),1,f);
                                        printf("\nSe creo el archivo correctamente\n\n");
                                        return aux_size;
                                        //fclose(f);
                                    }
                                    if(indicebloque == 64){
                                        continue;
                                    }
                                }else if(tipp == 's')
                                {

                                    for( ; e<aux_size ; e++)
                                    {
                                        if(indicebloque == 64)
                                        {
                                            fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                            fwrite(&co,sizeof(co),1,f);
                                            break;
                                        }
                                        co.b_content[indicebloque] = indicen+48;
                                        indicen++;
                                        indicebloque++;
                                        arc.i_size += 1;
                                        if(indicen == 10)
                                        {
                                            indicen = 0;
                                        }

                                    }
                                    if(indicebloque == 64)
                                    {
                                        continue;
                                    }
                                }

                                fseek(f,sb.s_bm_block_start,SEEK_SET);
                                fwrite(&tempb,sizeof(tempb),1,f);

                                fseek(f,sb.s_bm_inode_start,SEEK_SET);
                                fwrite(&tempi,sizeof(tempi),1,f);

                                fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                fwrite(&co,sizeof(co),1,f);

                                sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                                sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                                fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                                fwrite(&arc,sizeof(arc),1,f);
                                inodop = inodoa;
                                //fseek(f,isb,SEEK_SET);
                                //fwrite(&sb,sizeof(sb),1,f);
                                printf("\nSe creo el archivo correctamente\n\n");
                                return aux_size;
                                //fclose(f);

                            }

                            if(tipp == 'r')
                            fclose(fi);
                        }
                    }
                }
            }else{

                int nbb = buscarlibre(tempb,sb.s_blocks_count);
                tempb[nbb] = '1';
                bap.b_pointers[n] = nbb;


                if(tipo == 'c'){


                    int ni = buscarlibre(tempi,sb.s_inodes_count);
                    sb.s_free_inodes_count = sb.s_free_inodes_count-1;
                    int nb = buscarlibre(tempb,sb.s_blocks_count);
                    sb.s_free_blocks_count = sb.s_free_blocks_count-1;

                    inodon = ni;

                    tempi[ni] = '1';
                    tempb[nb] = '1';

                    INODO nuev;
                    setINODO(nuev,'0',664);

                    BCARPETA bcc;
                    setBLOQUEC2(bcc);

                    copiarS(bcc.b_content[0].b_name,nombre,nombre.length());
                    bcc.b_content[0].b_inode = ni;

                    fseek(f,sb.s_block_start+nbb*sb.s_block_size,SEEK_SET);
                    fwrite(&bcc,sizeof(bcc),1,f);

                    sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                    sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                    BCARPETA bc;
                    setBLOQUEC(bc,inodoa,ni);

                    nuev.i_block[0] = nb;
                    fecha(nuev.i_mtime);

                    fseek(f,sb.s_bm_block_start,SEEK_SET);
                    fwrite(&tempb,sizeof(tempb),1,f);

                    fseek(f,sb.s_bm_inode_start,SEEK_SET);
                    fwrite(&tempi,sizeof(tempi),1,f);

                    fseek(f,sb.s_block_start+nb*sb.s_block_size,SEEK_SET);
                    fwrite(&bc,sizeof(bc),1,f);

                    fseek(f,sb.s_inode_start+ni*sb.s_inode_size,SEEK_SET);
                    fwrite(&nuev,sizeof(nuev),1,f);

                    fseek(f,sb.s_inode_start+p.i_block[12]*sb.s_inode_size,SEEK_SET);
                    fwrite(&bap,sizeof(bap),1,f);

                    return 0;

                }else{
                    int inodoarchivo = buscarlibre(tempi,sb.s_inodes_count);
                    sb.s_free_inodes_count = sb.s_free_inodes_count-1;

                    inodon = inodoarchivo;
                    BCARPETA bcc;
                    setBLOQUEC2(bcc);

                    copiarS(bcc.b_content[0].b_name,nombre,nombre.length());
                    bcc.b_content[0].b_inode = inodoarchivo;

                    fseek(f,sb.s_block_start+nbb*sb.s_block_size,SEEK_SET);
                    fwrite(&bcc,sizeof(bcc),1,f);

                    tempi[inodoarchivo] = '1';

                    //fseek(f,sb.s_block_start+p.i_block[i]*sb.s_block_size,SEEK_SET);
                    //fwrite(&c,sizeof(c),1,f);

                    char tipp ='*';
                    if(aux_cont == "")
                    {
                        tipp = 's';
                    }else
                    {
                        tipp = 'r';

                    }
                    //fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
                    //fread(&p,sizeof(p),1,f);
                    INODO arc;
                    setINODO(arc,'1',664);

                    BARCHIVO co;
                    setBLOQUEA(co);


                    FILE* fi = fopen(aux_cont.c_str(),"r+b");
                    char char_temporal = 0;


                    int indicebloque = -1;
                    int indicen = 0;
                    int t = 0,e = 0;

                    for(t = 0; t<12 ; t++)
                    {
                        clean_char(co.b_content,64);
                        indicebloque = 0;
                        arc.i_block[t] = buscarlibre(tempb,sb.s_blocks_count);
                        sb.s_free_blocks_count = sb.s_free_blocks_count-1;
                        tempb[arc.i_block[t]] = '1';
                        if(tipp == 'r')
                        {
                            do
                            {
                                if(indicebloque == 64)
                                {
                                    fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                    fwrite(&co,sizeof(co),1,f);
                                    break;
                                }
                                if(char_temporal != 0)
                                {
                                    co.b_content[indicebloque] = char_temporal;
                                    indicebloque++;
                                    arc.i_size = arc.i_size+1;
                                }

                            }while((char_temporal = fgetc(fi)) != EOF);
                            if(char_temporal == EOF)
                            {
                                fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                fwrite(&co,sizeof(co),1,f);


                                if(tipp == 'r')
                                fclose(fi);

                                fseek(f,sb.s_bm_block_start,SEEK_SET);
                                fwrite(&tempb,sizeof(tempb),1,f);

                                fseek(f,sb.s_bm_inode_start,SEEK_SET);
                                fwrite(&tempi,sizeof(tempi),1,f);

                                fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                fwrite(&co,sizeof(co),1,f);

                                sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                                sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                                fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                                fwrite(&arc,sizeof(arc),1,f);

                                fseek(f,sb.s_inode_start+p.i_block[12]*sb.s_inode_size,SEEK_SET);
                                fwrite(&bap,sizeof(bap),1,f);
                                inodop = inodoa;
                                //fseek(f,isb,SEEK_SET);
                                //fwrite(&sb,sizeof(sb),1,f);
                                printf("\nSe creo el archivo correctamente\n\n");
                                return aux_size;
                                //fclose(f);

                            }
                            if(indicebloque == 64)
                            {
                                continue;
                            }
                        }else if(tipp == 's')
                        {

                            for( ; e<aux_size ; e++)
                            {
                                if(indicebloque == 64)
                                {
                                    fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                                    fwrite(&co,sizeof(co),1,f);
                                    break;
                                }
                                co.b_content[indicebloque] = indicen+48;
                                indicen++;
                                indicebloque++;
                                arc.i_size += 1;
                                if(indicen == 10)
                                {
                                    indicen = 0;
                                }

                            }
                            if(indicebloque == 64)
                            {
                                continue;
                            }
                        }

                        if(tipp == 'r')
                        fclose(fi);

                        fseek(f,sb.s_bm_block_start,SEEK_SET);
                        fwrite(&tempb,sizeof(tempb),1,f);

                        fseek(f,sb.s_bm_inode_start,SEEK_SET);
                        fwrite(&tempi,sizeof(tempi),1,f);

                        fseek(f,sb.s_block_start+arc.i_block[t]*sb.s_block_size,SEEK_SET);
                        fwrite(&co,sizeof(co),1,f);

                        sb.s_first_blo = buscarlibre(tempb,sb.s_blocks_count);
                        sb.s_first_ino = buscarlibre(tempi,sb.s_inodes_count);

                        fseek(f,sb.s_inode_start+inodoarchivo*sb.s_inode_size,SEEK_SET);
                        fwrite(&arc,sizeof(arc),1,f);

                        fseek(f,sb.s_inode_start+p.i_block[12]*sb.s_inode_size,SEEK_SET);
                        fwrite(&bap,sizeof(bap),1,f);
                        inodop = inodoa;
                        //fseek(f,isb,SEEK_SET);
                        //fwrite(&sb,sizeof(sb),1,f);
                        printf("\nSe creo el archivo correctamente\n\n");
                        return aux_size;
                        //fclose(f);

                    }
                }
            }

        }
    }

    return -1;
}

void setINODO(INODO& ino, char tipoi,int perm)
{
    ino.i_uid = idusuarioactual;
    ino.I_gid = idgrupoactual;
    ino.i_size = 0;
    char fec[18];
    time_t tiempo = time(0);
    struct tm *tiem = localtime(&tiempo);
    clean_char(fec,18);
    strftime(fec, 18, "%d/%m/%Y %H:%M", tiem);

    clean_char(ino.i_atime,16);
    copiar(ino.i_atime,fec,16);

    clean_char(ino.i_ctime,16);
    copiar(ino.i_ctime,fec,16);

    clean_char(ino.i_mtime,16);
    copiar(ino.i_mtime,fec,16);
    for(int i = 0; i<15 ; i++)
    {
        ino.i_block[i] = -1;
    }
    ino.i_type = tipoi;
    ino.i_perm = perm;
}

void setBLOQUEC(BCARPETA& bc, int ipad, int ipro)
{
    for(int i = 0; i<4; i++)
    {
        bc.b_content[i].b_inode = -1;
        clean_char(bc.b_content[i].b_name,12);
    }
    bc.b_content[0].b_name[0] = '.';
    bc.b_content[0].b_inode = ipro;

    bc.b_content[1].b_name[0] = '.';
    bc.b_content[1].b_name[1] = '.';
    bc.b_content[1].b_inode = ipad;
}

void setBLOQUEC2(BCARPETA& bc)
{
    for(int i = 0; i<4; i++)
    {
        bc.b_content[i].b_inode = -1;
        clean_char(bc.b_content[i].b_name,12);
    }
}

void setBLOQUEA(BARCHIVO& bc)
{
    for(int i = 0; i<64; i++)
    {
        bc.b_content[i] = '\0';
    }
}

void setBAPUNTADOR(BAPUNTADOR& ba){
    for(int i = 0; i<16; i++){
        ba.b_pointers[16] = -1;
    }
}


void cat()
{
    inodon = -1;
    inodop = 0;
    inodos = 0;
    if(file == ""){
        printf("\nError se necesita ingresar una ruta valida\n\n");
        return;
    }
    if(idactual == ""){
        printf("\nError se necesita una sesion activa para este comando\n\n");
        return;
    }
    PM part = buscarmontada(idactual);
    if(part.direccion == -1)
    {
        printf("\nError no se encontro la particion para realizar el comando\n\n");
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }

    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    if(file[0] != '/')
    {
        printf("\nError ruta no valida para la lectura del archivo\n\n");
        fclose(f);
        return;
    }

    vector<string> ruta = split(file,'/');
    INODO iaux;
    BCARPETA caux;
    BARCHIVO aaux;
    fseek(f,sb.s_inode_start,SEEK_SET);
    fread(&iaux,sizeof(iaux),1,f);
    char bandera = '*';

    if(ruta.size() >1){
        for(unsigned int indexf = 1; indexf<ruta.size(); indexf++){
            for(int i = 0; i<12; i++){
                if(iaux.i_block[i] != -1){
                    fseek(f,sb.s_block_start+iaux.i_block[i]*sb.s_block_size,SEEK_SET);
                    fread(&caux,sizeof(caux),1,f);
                    for(int j = 0; j<4; j++){
                        if(strcmp(caux.b_content[j].b_name,ruta[indexf].c_str())== 0){
                            if(indexf == ruta.size()-1){
                                fseek(f,sb.s_inode_start+caux.b_content[j].b_inode*sb.s_inode_size,SEEK_SET);
                                fread(&iaux,sizeof(iaux),1,f);
                                for(int m = 0; m<12; m++){
                                    if(iaux.i_block[m] != -1){
                                        fseek(f,sb.s_block_start+iaux.i_block[m]*sb.s_block_size,SEEK_SET);
                                        fread(&aaux,sizeof(aaux),1,f);
                                        for(int n = 0; n<64; n++){
                                            if(aaux.b_content[n] == '\0'){
                                                break;
                                            }
                                            if(refil == false){
                                                printf("%c",aaux.b_content[n]);
                                            }else{
                                                repfile += aaux.b_content[n];
                                            }

                                        }
                                    }
                                }
                                fclose(f);
                                printf("\n");
                                return;
                            }
                            bandera = 's';
                            fseek(f,sb.s_inode_start+caux.b_content[j].b_inode*sb.s_inode_size,SEEK_SET);
                            fread(&iaux,sizeof(iaux),1,f);
                            break;
                        }
                    }
                    if(bandera != '*'){
                        bandera = '*';
                        break;
                    }
                }
            }
        }
    }
    printf("\nNo se encontro el archivo\n\n");
    fclose(f);
}

void loss()
{
    if(id == "")
    {
        printf("\nError ingrese un id valido\n\n");
        return;
    }
    PM part = buscarmontada(id);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    JOURNAL jo[sb.s_inodes_count];
    fseek(f,isb+sizeof(sb),SEEK_SET);
    fread(&jo,sizeof(jo),1,f);


    for(int i = isb+sizeof(sb)+sizeof(jo)+1; i<(part.part_size+part.direccion)-1; i++)
    {
        fseek(f,i,SEEK_SET);
        fwrite("\0",sizeof(char),1,f);
    }
}

void recovery()
{
    if(id == "")
    {
        printf("\nError ingrese un id valido\n\n");
        return;
    }
    PM part = buscarmontada(id);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    JOURNAL jo[sb.s_inodes_count];
    fseek(f,isb+sizeof(sb),SEEK_SET);
    fread(&jo,sizeof(jo),1,f);

    char ida[12];
    clean_char(ida,12);
    copiarS(ida,idactual,11);
    idactual = "";
    idactual = id;

    int ide = idusuarioactual;
    int gre = idgrupoactual;

    for(int i = 0; i<sb.s_inodes_count; i++)
    {
        if(jo[i].type_trans == -1)
        {
            break;
        }else if(jo[i].type_trans == 1)
        {
            type = '*';
            fs = '3';

            idgrupoactual = 1;
            idusuarioactual = 1;
            mkfs();

            fs = '*';
        }else if(jo[i].type_trans == 2)
        {
            name = "";
            name = string(jo[i].name);

            for(int yu = 0; yu<10; yu++)
            {
                if(name[yu] == '\0')
                {
                    name[yu] = ' ';
                }
            }

            idusuarioactual = 1;
            idgrupoactual = 1;

            mkgrp();

            name = "";


        }else if(jo[i].type_trans == 3)
        {
            usr = "";
            pwd = "";
            grp = "";

            usr = string(jo[i].name);
            int yu = 0;
            for( ; yu<100; yu++)
            {
                if(jo[i].contenido[yu] == ',')
                {
                    break;
                }
                pwd += jo[i].contenido[yu];
            }
            int iuo = 0;
            for( ; yu<100; yu++)
            {
                if(jo[i].contenido[yu] == ',')
                {
                    continue;
                }
                if(jo[i].contenido[yu] == '\0')
                {
                    break;
                }
                grp += jo[i].contenido[yu];
                iuo++;
            }
            idusuarioactual = 1;
            idgrupoactual = 1;

            mkusr();

            usr = "";
            pwd = "";
            grp = "";
        }else if(jo[i].type_trans == 4)
        {
            name = "";
            name = string(jo[i].name);
            rmgrp();
            name = "";
        }else if(jo[i].type_trans == 5)
        {
            usr = "";
            usr = string(jo[i].name);
            rmusr();
            usr = "";
        }else if(jo[i].type_trans == 6)
        {
            path = "";
            path = string(jo[i].contenido);

            atribp = 's';


            idgrupoactual = jo[i].grupo;
            idusuarioactual = jo[i].propietario;

            mkdir();



            path = "";
            atribp = '*';
        }else if(jo[i].type_trans == 7)
        {
            vector<string> rt = split(string(jo[i].contenido),',');
            path = "";
            if(rt[0][0] == '/')
            {
                cont = "";
                cont = rt[0];
                path = rt[1];
                size = 0;
            }else
            {
                cont = "";
                size = atoi(rt[0].c_str());
                path = rt[1];
            }
            inodomkfj = -1;
            idusuarioactual = jo[i].propietario;
            idgrupoactual = jo[i].grupo;

            atribp = 's';

            mkfile();


            cont = "";
            size = 0;
            path = "";
            atribp = '*';
            inodomkfj = -1;
        }else if(jo[i].type_trans == 8)
        {
            path = string(jo[i].contenido);
            name = path.substr(0, i) + string(jo[i].name);
            idusuarioactual = jo[i].propietario;
            idgrupoactual = jo[i].grupo;
            ren();


        }
    }

    idactual = "";
    idactual = ida;

    idusuarioactual = ide;
    idgrupoactual = gre;

    //fseek(f,isb+sizeof(sb),SEEK_SET);
    //write(&jo,sizeof(jo),1,f);
}

void syncronice()
{
    if(id == "")
    {
        printf("\nError, se necesita un id de particion montada\n\n");
        return;
    }

    for(int i = 0; i<maxd ; i++)
    {
        for(int j = 0; j<maxp; j++)
        {
            if(mounts[i][j].id == id)
            {
                if(mounts[i][j].direccion == -1)
                {
                    printf("\nError, particion %s no montada\n\n",id.c_str());
                    return;
                }

                FILE* f = fopen(mounts[i][j].path.c_str(),"r+b");
                SB sb;
                int dirsb = -1;
                if(mounts[i][j].type == 'p')
                {
                    fseek(f,mounts[i][j].direccion,SEEK_SET);
                    dirsb = mounts[i][j].direccion;
                }else
                {
                    fseek(f,mounts[i][j].direccion + sizeof(EBR),SEEK_SET);
                    dirsb = mounts[i][j].direccion + sizeof(EBR);
                }
                fread(&sb,sizeof(sb),1,f);
                INODO aux;
                BARCHIVO archi;
                fseek(f,sb.s_inode_start+1*sb.s_inode_size,SEEK_SET);
                fread(&aux,sizeof(aux),1,f);

                string cadtemp = "";

                for(int r = 0; r<12; r++)
                {
                    if(aux.i_block[r] != -1)
                    {
                        fseek(f,sb.s_block_start+aux.i_block[r]*sb.s_block_size,SEEK_SET);
                        fread(&archi,sizeof(archi),1,f);
                        for(int nn= 0; nn<64; nn++){
                          cadtemp += archi.b_content[nn];
                        }
                        //cadtemp += string(archi.b_content);
                    }
                }

                cout << cadtemp.c_str();
                vector<string> sp = split(cadtemp,'\n');
                if(sp.size() == 0){
                    printf("\nError no se puede realizar el syncronize\n\n");
                    fclose(f);
                    return;
                }
                vector<string> spp;
                FILE* fi = fopen("/home/sync-users.code","w");
                fprintf(fi,"[");

                for(unsigned int iu = 0; iu< sp.size(); iu++){
                    spp = split(sp[iu],',');
                    if(spp[1] == "U" && spp[3] == "root      "){
                        continue;
                    }
                    if(spp[1] == "U"){
                        fprintf(fi,"{");
                        fprintf(fi,"\"USERNAME\": \"%s\",",spp[3].c_str());
                        fprintf(fi,"\"PASSWORD\": \"%s\"",spp[4].c_str());
                        fprintf(fi,"},");
                    }
                }
                fprintf(fi,"]");
                fclose(fi);
            }
        }
    }
}

void mkdir()
{
    inodon = -1;
    inodop = 0;
    inodos = 0;
    if(path == ""){
        printf("\nError se necesita ingresar una ruta valida\n\n");
        return;
    }
    if(idactual == ""){
        printf("\nError se necesita una sesion activa para este comando\n\n");
        return;
    }
    PM part = buscarmontada(idactual);
    if(part.direccion == -1)
    {
        printf("\nError no se encontro la particion para realizar el comando\n\n");
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }

    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    if(path[0] != '/')
    {
        printf("\nError ruta no valida para la creacion del archivo\n\n");
        fclose(f);
        return;
    }

    vector<string> ruta = split(path,'/');
    copy_vars();
    //aux = ;
    int ds = loopruta(ruta,1,0,sb,f,'c');
    if(ds > -1){
        if(sb.s_filesystem_type == 3)
        {
            JOURNAL jou[sb.s_inodes_count];
            fseek(f,isb+sizeof(sb),SEEK_SET);
            fread(&jou,sizeof(jou),1,f);
            int posj = buscarvaciojournal(jou,sb.s_inodes_count);
            jou[posj].type_trans = 6;
            jou[posj].type = 0;
            jou[posj].grupo = idgrupoactual;
            jou[posj].permiso = 664;
            jou[posj].propietario = idusuarioactual;
            copiarS(jou[posj].name,ruta[ruta.size()-1],12);
            copiarS(jou[posj].contenido,path,100);
            fecha(jou[posj].j_time);
            fseek(f,isb+sizeof(sb),SEEK_SET);
            fwrite(&jou,sizeof(jou),1,f);

        }
        printf("\nSe creo con exito la carpeta\n\n");
    }else{
        printf("\nNo se pudo crear la carpeta\n\n");
    }
    fseek(f,isb,SEEK_SET);
    fwrite(&sb,sizeof(sb),1,f);
    fclose(f);
}


void pause()
{
    printf("\nEl programa se puso en pausa\nPresione c para continuar\n\n");
    char ctempo = '*';
    while(1)
    {
        ctempo = char(getchar());
        if(ctempo == 'c' || ctempo == 'C')
        {
            break;
        }
    }
}

void copy_vars()
{
    aux_atribp = atribp;
    aux_cont = cont;
    aux_size = size;
}

void tree()
{
    int numtree = 0;
    int numestructura = numtree;
    FILE* f = fopen("./Images/grafo.dot","w");

    if(f == NULL)
    {
        printf("\nError no se pudo crear el grafo\n\n");
        return;
    }else
    {
        for(int i = 0; i<maxd ; i++)
        {
            for(int j = 0; j<maxp ; j++)
            {
                if(mounts[i][j].id == id)
                {
                    if(mounts[i][j].direccion == -1)
                    {
                        printf("\nError particion no montada para el id %s\n\n",id.c_str());
                        fclose(f);
                        return;
                    }
                    FILE* file = fopen(mounts[i][j].path.c_str(),"r+b");
                    if(file == NULL){
                        printf("\nError no se encontro el Disco de la particion montada %s\n\n",id.c_str());
                        return;
                    }
                    SB sb;
                    INODO in;
                    BARCHIVO ba;
                    BCARPETA bc;
                    BAPUNTADOR bap;

                    if(mounts[i][j].type == 'p')
                    {
                        fseek(file,mounts[i][j].direccion,SEEK_SET);
                    }else
                    {
                        fseek(file,mounts[i][j].direccion+sizeof(EBR),SEEK_SET);
                    }
                    fread(&sb,sizeof(sb),1,file);
                    fseek(file,sb.s_inode_start,SEEK_SET);
                    fread(&in,sizeof(in),1,file);

                    char fet[17];
                    clean_char(fet,17);

                    fprintf(f,"digraph G {\r\n");
                    fprintf(f,"graph [ rankdir = \"LR\" ]; node [ fontsize = \"16\" shape = \"ellipse\" ]; edge [ ];\r\n");
                    fprintf(f,"\"%i\" [\r\nlabel = \" ID Usuario: %i",numtree,in.i_uid);
                    numtree++;
                    fprintf(f,"| ID Grupo: %i",in.I_gid);
                    fprintf(f,"| Tamaño: %i",in.i_size);
                    copiar(fet,in.i_atime,16);
                    fprintf(f,"| Ultima Lectura: %s",fet);
                    copiar(fet,in.i_ctime,16);
                    fprintf(f,"| Fecha Creacion: %s",fet);
                    copiar(fet,in.i_mtime,16);
                    fprintf(f,"| Ultima Modificacion: %s",fet);
                    fprintf(f,"| Tipo: %c",in.i_type);
                    fprintf(f,"| Permisos: %i",in.i_perm);
                    for(int r = 0 ; r < 12 ; r++)
                    {
                        fprintf(f,"|<f%i>Ap Directo%i: %i",r,r+1,in.i_block[r]);
                    }

                    for(int r = 12 ; r < 15 ; r++)
                    {
                        fprintf(f,"|<f%i>Ap Indirecto%i: %i",r,r-11,in.i_block[r]);
                    }
                    fprintf(f,"\" \r\nshape = \"record\" \r\n];\r\n\r\n");

                    for(int r = 0 ; r < 15 ; r++)
                    {
                        if(in.i_block[r] != -1)
                        {
                            if(in.i_type == '0')
                            {
                                fseek(file,sb.s_block_start + in.i_block[r]*sb.s_block_size,SEEK_SET);
                                fread(&bc,sizeof(bc),1,file);
                                INODO aux;
                                aux.I_gid = -1;
                                ba.b_content[0] = '*';
                                bap.b_pointers[0] = -1;
                                looptree(f,file,numestructura,r,sb,aux,ba,bc,bap,numtree);
                            }else if(in.i_type == '1')
                            {
                                fseek(file,sb.s_block_start + in.i_block[r]*sb.s_block_size,SEEK_SET);
                                fread(&ba,sizeof(ba),1,file);
                                INODO aux;
                                aux.I_gid = -1;
                                bc.b_content[0].b_inode = -2;
                                bap.b_pointers[0] = -1;
                                looptree(f,file,numestructura,r,sb,aux,ba,bc,bap,numtree);
                            }
                        }
                    }




                    fprintf(f,"\r\n}");
                    fclose(f);
                    fclose(file);
                    crear_imagen();
                }
            }
        }

    }
}

void looptree(FILE* f, FILE* file,int nume, int numf,SB sb, INODO in, BARCHIVO ba, BCARPETA bc, BAPUNTADOR bap, int& numtree)
{
    int numestructura = numtree;

    if(in.I_gid != -1 && ba.b_content[0] == '*' && bc.b_content[0].b_inode == -2 && bap.b_pointers[0] == -1)
    {
        fprintf(f,"\"%i\" [\r\nlabel = \" ID Usuario: %i",numtree,in.i_uid);
        numtree++;
        fprintf(f,"| ID Grupo: %i",in.I_gid);
        fprintf(f,"| Tamaño: %i",in.i_size);
        char tf[17];

        clean_char(tf,17);
        copiar(tf,in.i_atime,16);
        fprintf(f,"| Ultima Lectura: %s",tf);

        clean_char(tf,17);
        copiar(tf,in.i_ctime,16);
        fprintf(f,"| Fecha Creacion: %s",tf);

        clean_char(tf,17);
        copiar(tf,in.i_mtime,16);
        fprintf(f,"| Ultima Modificacion: %s",tf);
        fprintf(f,"| Tipo: %c",in.i_type);
        fprintf(f,"| Permisos: %i",in.i_perm);
        for(int r = 0 ; r < 12 ; r++)
        {
            //if(in.i_block[r] == -1)
            {
                //continue;
            }
            fprintf(f,"|<f%i>Ap Directo%i: %i",r,r+1,in.i_block[r]);
        }

        for(int r = 12 ; r < 15 ; r++)
        {
            //if(in.i_block[r] == -1)
            {
                //continue;
            }
            fprintf(f,"|<f%i>Ap Indirecto%i: %i",r,r-11,in.i_block[r]);
        }

        fprintf(f,"\" \r\nshape = \"record\" \r\n];\r\n\r\n");

        fprintf(f,"\"%i\":f%i -> \"%i\":f0 [];\r\n\r\n",nume,numf,numestructura);

        for(int r = 0 ; r < 12 ; r++)
        {
            if(in.i_block[r] != -1)
            {
                if(in.i_type == '0')
                {
                    BCARPETA aux;
                    fseek(file,sb.s_block_start + in.i_block[r]*sb.s_block_size,SEEK_SET);
                    fread(&aux,sizeof(aux),1,file);
                    INODO inaux;
                    inaux.I_gid = -1;
                    ba.b_content[0] = '*';
                    bap.b_pointers[0] = -1;
                    looptree(f,file,numestructura,r,sb,inaux,ba,aux,bap, numtree);
                }else if(in.i_type == '1')
                {
                    BARCHIVO aux;
                    fseek(file,sb.s_block_start + in.i_block[r]*sb.s_block_size,SEEK_SET);
                    fread(&aux,sizeof(aux),1,file);
                    INODO inaux;
                    inaux.I_gid = -1;
                    bc.b_content[0].b_inode = -2;
                    bap.b_pointers[0] = -1;
                    looptree(f,file,numestructura,r,sb,inaux,aux,bc,bap, numtree);
                }
            }
        }
        if(in.i_block[12] != -1)
        {
            BAPUNTADOR aux;
            fseek(file,sb.s_block_start + in.i_block[12]*sb.s_block_size,SEEK_SET);
            fread(&aux,sizeof(aux),1,file);
            INODO inaux;
            BCARPETA caux;
            caux.b_content[0].b_inode = -1;
            inaux.I_gid = -1;
            ba.b_content[0] = '*';
            bap.b_pointers[0] = -1;
            looptree(f,file,numestructura,12,sb,inaux,ba,caux,aux, numtree);
        }
    }else if(in.I_gid == -1 && ba.b_content[0] != '*' && bc.b_content[0].b_inode == -2 && bap.b_pointers[0] == -1)
    {
        char tc[65];
        clean_char(tc,65);
        copiarsinEspacios(tc,ba.b_content,64);
        fprintf(f,"\"%i\" [\r\nlabel = \"<f0>Contenido: %s",numtree,tc);
        numtree++;
        fprintf(f,"\" \r\nshape = \"record\" \r\n];\r\n\r\n");
        fprintf(f,"\"%i\":f%i -> \"%i\":f0 [];\r\n\r\n",nume,numf,numestructura);
    }else if(in.I_gid == -1 && ba.b_content[0] == '*' && bc.b_content[0].b_inode != -2 && bap.b_pointers[0] == -1)
    {
        fprintf(f,"\"%i\" [\r\nlabel = \"<f0>Nombre: %s ; Inodo: %i",numtree,bc.b_content[0].b_name,bc.b_content[0].b_inode);
        numtree++;
        fprintf(f,"|<f1>Nombre: %s ; Inodo: %i",bc.b_content[1].b_name,bc.b_content[1].b_inode);
        fprintf(f,"|<f2>Nombre: %s ; Inodo: %i",bc.b_content[2].b_name,bc.b_content[2].b_inode);
        fprintf(f,"|<f3>Nombre: %s ; Inodo: %i",bc.b_content[3].b_name,bc.b_content[3].b_inode);
        fprintf(f,"\" \r\nshape = \"record\" \r\n];\r\n\r\n");
        fprintf(f,"\"%i\":f%i -> \"%i\":f0 [];\r\n\r\n",nume,numf,numestructura);

        for(int j = 0 ; j<4 ; j++)
        {
            if(strcmp(bc.b_content[j].b_name,".") == 0 || strcmp(bc.b_content[j].b_name,"..") == 0)
            {
                continue;
            }
            if(bc.b_content[j].b_inode != -1)
            {
                INODO aux;
                fseek(file,sb.s_inode_start+bc.b_content[j].b_inode*sb.s_inode_size,SEEK_SET);
                fread(&aux,sizeof(aux),1,file);
                ba.b_content[0] = '*';
                BCARPETA bcaux;
                bcaux.b_content[0].b_inode = -2;
                bap.b_pointers[0] = -1;
                looptree(f,file,numestructura,j,sb,aux,ba,bcaux,bap,numtree);
            }
        }


    }else if(in.I_gid == -1 && ba.b_content[0] == '*' && bc.b_content[0].b_inode == -2 && bap.b_pointers[0] != -1)
    {
        fprintf(f,"\"%i\" [\r\nlabel = \" Apuntador Bloque%i: %i",numtree,0,bap.b_pointers[0]);
        numtree++;

        for(int r = 0; r<16; r++)
        {
            fprintf(f,"| Apuntador Bloque%i: %i",r,bap.b_pointers[r]);
        }

        fprintf(f,"\" \r\nshape = \"record\" \r\n];\r\n\r\n");

        fprintf(f,"\"%i\":f%i -> \"%i\":f0 [];\r\n\r\n",nume,numf,numestructura);
        for(int r = 0; r<16; r++)
        {
            if(bap.b_pointers[r] != -1)
            {
                BCARPETA aux;
                fseek(file,sb.s_block_start + bap.b_pointers[r]*sb.s_block_size,SEEK_SET);
                fread(&aux,sizeof(aux),1,file);
                INODO inaux;
                inaux.I_gid = -1;
                ba.b_content[0] = '*';
                BAPUNTADOR bapp;
                bapp.b_pointers[0] = -1;
                looptree(f,file,numestructura,r,sb,inaux,ba,aux,bapp, numtree);
            }
        }
    }
}

void repinodo()
{
    if(id == "")
    {
        printf("\nError no se ha ingresado un id valido\n\n");
        return;
    }

    if(name == "")
    {
        printf("\nError no se ha ingresado un nombre valido de reporte\n\n");
        return;
    }

    if(path == "")
    {
        printf("\nError no se ha ingresado una ruta valida para crear el reporte\n\n");
        return;
    }
    PM part = buscarmontada(id);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    FILE* fi = fopen("./Images/grafo.dot","w");

    fprintf(fi,"digraph G { \n");
    fprintf(fi,"subgraph cluster1 {\n");
    fprintf(fi,"node [shape=rectangle]\n");
    fprintf(fi,"graf [label=<\n");
    fprintf(fi,"<table border=\"0\" cellspacing=\"10\" cellpadding=\"10\" >\n");
    fprintf(fi,"<tr>\n");

    char tempi[sb.s_inodes_count];
    clean_char(tempi,sb.s_inodes_count);
    fseek(f,sb.s_bm_inode_start,SEEK_SET);
    fread(&tempi,sizeof(tempi),1,f);
    int sig = 0;
    INODO auxi;
    char fet[17];

    for(int i = 0; i< sb.s_inodes_count; i++)
    {
        if(tempi[i] == '1')
        {
            fseek(f,sb.s_inode_start+i*sb.s_inode_size,SEEK_SET);
            fread(&auxi,sizeof(auxi),1,f);
            fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">");
            fprintf(fi,"i_uid: %i",auxi.i_uid);
            fprintf(fi,"<br></br>i_gid: %i",auxi.I_gid);
            fprintf(fi,"<br></br>i_size: %i",auxi.i_size);
            clean_char(fet,17);
            copiar(fet,auxi.i_atime,16);
            fprintf(fi,"<br></br>i_atime: %s",fet);
            clean_char(fet,17);
            copiar(fet,auxi.i_ctime,16);
            fprintf(fi,"<br></br>i_ctime: %s",fet);
            clean_char(fet,17);
            copiar(fet,auxi.i_mtime,16);
            fprintf(fi,"<br></br>i_mtime: %s",fet);
            fprintf(fi,"<br></br>i_type: %c",auxi.i_type);
            fprintf(fi,"<br></br>i_perm: %i",auxi.i_perm);
            for(int j = 0; j<15 ; j++)
            {
                fprintf(fi,"<br></br>i_block_%i: %i",j,auxi.i_block[j]);
            }
            fprintf(fi," </td>\n");
            sig++;
        }
        if(sig == 25)
        {
            fprintf(fi,"</tr><tr>");
            sig = 0;
        }

    }

    fprintf(fi,"</tr>\n");
    fprintf(fi,"</table>>];\n}\n} ");
    fclose(fi);
    fclose(f);
    crear_imagen();
}

void repbloque()
{
    if(id == "")
    {
        printf("\nError no se ha ingresado un id valido\n\n");
        return;
    }

    if(name == "")
    {
        printf("\nError no se ha ingresado un nombre valido de reporte\n\n");
        return;
    }

    if(path == "")
    {
        printf("\nError no se ha ingresado una ruta valida para crear el reporte\n\n");
        return;
    }
    PM part = buscarmontada(id);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    FILE* fi = fopen("./Images/grafo.dot","w");
    fprintf(fi,"digraph G { \n");
    fprintf(fi,"subgraph cluster1 {\n");
    fprintf(fi,"node [shape=rectangle]\n");
    fprintf(fi,"graf [label=<\n");
    fprintf(fi,"<table border=\"0\" cellspacing=\"10\" cellpadding=\"10\" >\n");
    fprintf(fi,"<tr>\n");

    char tempi[sb.s_inodes_count];
    clean_char(tempi,sb.s_inodes_count);
    fseek(f,sb.s_bm_inode_start,SEEK_SET);
    fread(&tempi,sizeof(tempi),1,f);
    int sig = 0;
    INODO auxi;
    BCARPETA auxc;
    BARCHIVO auxa;
    char fet[65];

    for(int i = 0; i< sb.s_inodes_count; i++)
    {
        if(tempi[i] == '1')
        {
            fseek(f,sb.s_inode_start+i*sb.s_inode_size,SEEK_SET);
            fread(&auxi,sizeof(auxi),1,f);

            for(int e = 0; e<15; e++)
            {
                if(auxi.i_block[e] != -1)
                {
                    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">");
                    fseek(f,sb.s_block_start+auxi.i_block[e]*sb.s_block_size,SEEK_SET);
                    if(auxi.i_type == '0')
                    {
                        fread(&auxc,sizeof(auxc),1,f);

                        for(int ty= 0; ty<4; ty++)
                        {
                            clean_char(fet,65);
                            copiar(fet,auxc.b_content[ty].b_name,12);
                            fprintf(fi,"Nombre: %s | Inodo: %i",fet,auxc.b_content[ty].b_inode);
                            fprintf(fi,"<br></br>");
                        }

                    }else
                    {
                        fread(&auxa,sizeof(auxa),1,f);
                        clean_char(fet,65);
                        copiar(fet,auxa.b_content,64);
                        fprintf(fi,"Contenido: %s",fet);
                        fprintf(fi,"<br></br>");
                    }

                    fprintf(fi," </td>\n");
                    sig++;
                    if(sig == 25)
                    {
                        fprintf(fi,"</tr><tr>");
                        sig = 0;
                    }
                }
            }

        }


    }

    fprintf(fi,"</tr>\n");
    fprintf(fi,"</table>>];\n}\n} ");
    fclose(fi);
    fclose(f);
    crear_imagen();
}

void repbminodo()
{
    if(id == "")
    {
        printf("\nError no se ha ingresado un id valido\n\n");
        return;
    }

    if(name == "")
    {
        printf("\nError no se ha ingresado un nombre valido de reporte\n\n");
        return;
    }

    if(path == "")
    {
        printf("\nError no se ha ingresado una ruta valida para crear el reporte\n\n");
        return;
    }
    PM part = buscarmontada(id);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    FILE* fi = fopen(path.c_str(),"w");

    char tempi[sb.s_inodes_count];
    clean_char(tempi,sb.s_inodes_count);
    fseek(f,sb.s_bm_inode_start,SEEK_SET);
    fread(&tempi,sizeof(tempi),1,f);
    int sig = 0;

    for(int i = 0; i< sb.s_inodes_count; i++)
    {
        fprintf(fi,"%c",tempi[i]);
        if(sig == 20)
        {
            fprintf(fi,"\n");
            sig = 0;
        }else
        {
            fprintf(fi," ");
        }

    }
    fclose(fi);
    fclose(f);
}

void repbmblock()
{
    if(id == "")
    {
        printf("\nError no se ha ingresado un id valido\n\n");
        return;
    }

    if(name == "")
    {
        printf("\nError no se ha ingresado un nombre valido de reporte\n\n");
        return;
    }

    if(path == "")
    {
        printf("\nError no se ha ingresado una ruta valida para crear el reporte\n\n");
        return;
    }
    PM part = buscarmontada(id);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    FILE* fi = fopen(path.c_str(),"w");

    char tempi[sb.s_blocks_count];
    clean_char(tempi,sb.s_blocks_count);
    fseek(f,sb.s_bm_block_start,SEEK_SET);
    fread(&tempi,sizeof(tempi),1,f);
    int sig = 0;

    for(int i = 0; i< sb.s_blocks_count; i++)
    {
        fprintf(fi,"%c",tempi[i]);
        if(sig == 20)
        {
            fprintf(fi,"\n");
            sig = 0;
        }else
        {
            fprintf(fi," ");
        }

    }
    fclose(fi);
    fclose(f);
}

void repsb()
{
    if(id == "")
    {
        printf("\nError no se ha ingresado un id valido\n\n");
        return;
    }

    if(name == "")
    {
        printf("\nError no se ha ingresado un nombre valido de reporte\n\n");
        return;
    }

    if(path == "")
    {
        printf("\nError no se ha ingresado una ruta valida para crear el reporte\n\n");
        return;
    }
    PM part = buscarmontada(id);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    FILE* fi = fopen("./Images/grafo.dot","w");

    fprintf(fi,"digraph G { \n");
    fprintf(fi,"subgraph cluster1 {\n");
    fprintf(fi,"node [shape=rectangle]\n");
    fprintf(fi,"graf [label=<\n");
    fprintf(fi,"<table border=\"0\" cellspacing=\"10\" cellpadding=\"10\" >\n");

    char fet[17];
    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">Nombre</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">Valor</td></tr>\n");

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_filesystem_type</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_filesystem_type);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_inodes_count</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_inodes_count);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_blocks_count</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_blocks_count);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_free_blocks_count</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_free_blocks_count);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_free_inodes_count</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_free_inodes_count);

    clean_char(fet,17);
    copiar(fet,sb.s_mtime,16);
    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_mtime</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%s</td></tr>\n",fet);

    clean_char(fet,17);
    copiar(fet,sb.s_umtime,16);
    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_umtime</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%s</td></tr>\n",fet);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_mnt_count</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_mnt_count);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_magic</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_magic);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_inode_size</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_inode_size);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_block_size</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_block_size);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_first_ino</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_first_ino);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_first_blo</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_first_blo);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_bm_inode_start</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_bm_inode_start);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_bm_block_start</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_bm_block_start);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_inode_start</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_inode_start);

    fprintf(fi,"<tr><td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">s_block_start</td>");
    fprintf(fi,"<td border=\"3\"  bgcolor=\"white\" gradientangle=\"315\">%i</td></tr>\n",sb.s_block_start);

    fprintf(fi,"</table>>];\n}\n} ");
    fclose(fi);
    fclose(f);
    crear_imagen();
}

void repjournal()
{
    if(id == "")
    {
        printf("\nError no se ha ingresado un id valido\n\n");
        return;
    }

    if(name == "")
    {
        printf("\nError no se ha ingresado un nombre valido de reporte\n\n");
        return;
    }

    if(path == "")
    {
        printf("\nError no se ha ingresado una ruta valida para crear el reporte\n\n");
        return;
    }
    PM part = buscarmontada(id);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    JOURNAL lista[sb.s_inodes_count];

    fseek(f,isb+sizeof(sb),SEEK_SET);
    fread(&lista,sizeof(lista),1,f);

    FILE* fi = fopen("./Images/grafo.dot","w");
    fprintf(fi,"digraph G { \n");
    fprintf(fi,"subgraph cluster1 {\n");
    fprintf(fi,"node [shape=rectangle]\n");
    fprintf(fi,"graf [label=<\n");
    fprintf(fi,"<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n");

    fprintf(fi,"<tr><td>Tipo Transaccion</td>");
    fprintf(fi,"<td>Tipo</td>");
    fprintf(fi,"<td>Nombre</td>");
    fprintf(fi,"<td>Propietario</td>");
    fprintf(fi,"<td>Grupo</td>");
    fprintf(fi,"<td>Permiso</td>");
    fprintf(fi,"<td>Fecha</td>");
    fprintf(fi,"<td>Contenido</td></tr>\n");

    char fet[65];
    for(int t = 0; t<sb.s_inodes_count; t++)
    {
        if(lista[t].type_trans != -1)
        {
            fprintf(fi,"<tr><td>%i</td>",lista[t].type_trans);
            fprintf(fi,"<td>%i</td>",lista[t].type);
            clean_char(fet,65);
            copiar(fet,lista[t].name,12);
            fprintf(fi,"<td>%s</td>",fet);
            fprintf(fi,"<td>%i</td>",lista[t].propietario);
            fprintf(fi,"<td>%i</td>",lista[t].grupo);
            fprintf(fi,"<td>%i</td>",lista[t].permiso);
            clean_char(fet,65);
            copiar(fet,lista[t].j_time,16);
            fprintf(fi,"<td>%s</td>",fet);
            clean_char(fet,65);
            copiarsinEspacios(fet,lista[t].contenido,64);
            fprintf(fi,"<td>%s</td></tr>\n",fet);
        }
    }

    fprintf(fi,"</table>>];\n}\n} ");
    fclose(fi);
    fclose(f);
    crear_imagen();
}

void repls()
{
    if(path == "")
    {
        printf("\nError ingrese un path valido\n\n");
        return;
    }
    if(id == "")
    {
        printf("\nError ingrese un id valido\n\n");
        return;
    }
    if(ruta == "")
    {
        printf("\nError ingrese una ruta valida\n\n");
        return;
    }
    PM part = buscarmontada(id);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    if(ruta[0] != '/')
    {
        printf("\nError ruta no valida para la creacion del reporte\n\n");
        fclose(f);
        return;
    }
    char te[13];
    clean_char(te,13);
    int inodoa = 0;
    INODO auxi;
    BCARPETA auxc;
    char tempi[sb.s_inodes_count];
    char tempb[sb.s_blocks_count];

    fseek(f,sb.s_bm_block_start,SEEK_SET);
    fread(&tempb,sizeof(tempb),1,f);

    fseek(f,sb.s_bm_inode_start,SEEK_SET);
    fread(&tempi,sizeof(tempi),1,f);

    char permisos[4];

    vector<string> rutas = split(ruta,'/');

    int ia = looprutals(rutas,1,0,sb,f);

    if(ia == -1){
        printf("\nNo se encontro el archivo para el reporte ls\n\n");
        fclose(f);
        return;
    }
    //fclose(f);


    FILE* fi = fopen("./Images/grafo.dot","w");
    if(fi == NULL)
    {
        printf("\nError no se pudo crear el archivo del reporte\n\n");
        fclose(f);
        return;
    }
    fprintf(fi,"digraph G { \n");
    fprintf(fi,"subgraph cluster1 {\n");
    fprintf(fi,"node [shape=rectangle]\n");
    fprintf(fi,"graf [label=<\n");
    fprintf(fi,"<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n");

    fprintf(fi,"<tr><td>Permisos</td>");
    fprintf(fi,"<td>Owner</td>");
    fprintf(fi,"<td>Grupo</td>");
    fprintf(fi,"<td>Size</td>");
    fprintf(fi,"<td>Fecha</td>");
    fprintf(fi,"<td>Hora</td>");
    fprintf(fi,"<td>Tipo</td>");
    fprintf(fi,"<td>Nombre</td></tr>\n");
    fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
    fread(&auxi,sizeof(auxi),1,f);
    INODO au;
    for(int q = 0; q<15; q++)
    {
        if(auxi.i_block[q] != -1)
        {
            fseek(f,sb.s_block_start+auxi.i_block[q]*sb.s_block_size,SEEK_SET);
            fread(&auxc,sizeof(auxc),1,f);
            for(int w= 0; w<4; w++)
            {
                if(strcmp(auxc.b_content[w].b_name,".") == 0 || strcmp(auxc.b_content[w].b_name,"..") == 0)
                {
                    continue;
                }
                if(auxc.b_content[w].b_inode != -1)
                {
                    fseek(f,sb.s_inode_start+auxc.b_content[w].b_inode*sb.s_inode_size,SEEK_SET);
                    fread(&au,sizeof(au),1,f);
                    clean_char(permisos,4);
                    verificarpermisos(permisos,sb,auxc.b_content[w].b_inode,f);
                    if(permisos[0] == '0')
                    {
                        continue;
                    }
                    clean_char(permisos,4);
                    sprintf(permisos,"%i",au.i_perm);
                    fprintf(fi,"<tr><td>");
                    if(au.i_type == '0')
                    {
                        fprintf(fi,"d");
                    }else
                    {
                        fprintf(fi,"-");
                    }
                    char cad[17];
                    clean_char(cad,17);
                    cadpermisos(cad,permisos[0]);
                    fprintf(fi,"%s",cad);
                    cadpermisos(cad,permisos[1]);
                    fprintf(fi,"%s",cad);
                    cadpermisos(cad,permisos[2]);
                    fprintf(fi,"%s",cad);
                    fprintf(fi,"</td>");
                    clean_char(cad,17);
                    buscaruid(cad,au.i_uid,1,f,sb);
                    fprintf(fi,"<td>%s</td>",cad);
                    clean_char(cad,17);
                    buscaruid(cad,au.i_uid,2,f,sb);
                    fprintf(fi,"<td>%s</td>",cad);
                    fprintf(fi,"<td>%i</td>",au.i_size);
                    clean_char(cad,17);
                    copiar(cad,au.i_mtime,10);
                    fprintf(fi,"<td>%s</td>",cad);
                    clean_char(cad,17);
                    for(int er= 11; er<16;er++)
                    {
                        cad[er-11] = au.i_mtime[er];
                    }
                    fprintf(fi,"<td>%s</td>",cad);
                    if(au.i_type == '0')
                    {
                        fprintf(fi,"<td>Carpeta</td>");
                    }else
                    {
                        fprintf(fi,"<td>Archivo</td>");
                    }
                    fprintf(fi,"<td>%s</td></tr>",auxc.b_content[w].b_name);

                }
            }
        }
    }

    fprintf(fi,"</table>>];\n}\n} ");
    fclose(fi);
    fclose(f);
    crear_imagen();
}

void buscaruid(char nombre[],int id, int ti, FILE* f, SB sb)
{
    INODO aux;
    fseek(f,sb.s_inode_start+sb.s_inode_size,SEEK_SET);
    fread(&aux,sizeof(aux),1,f);

    int co = 0;

    for(int i = 0; i<15 ; i++)
    {
        if(aux.i_block[i] != -1)
        {
            co++;
        }
    }

    char fil[64*(co+1)];
    clean_char(fil,64*(co+1));
    char temm[65];


    BARCHIVO ar;
    for(int i = 0; i<15 ; i++)
    {
        if(aux.i_block[i] != -1)
        {
            fseek(f,sb.s_block_start+aux.i_block[i]*sb.s_block_size,SEEK_SET);
            fread(&ar,sizeof(ar),1,f);
            clean_char(temm,65);
            copiar(temm,ar.b_content,64);
            strcat(fil,temm);

        }
    }

    if(ti == 1)
    {
        int y = 0;



        for(int r = 0; r<(64*(co+1)) ; r++)
        {
            if(fil[r] == '\0')
            {
                return;
            }
            if(fil[r+2] == 'U')
            {
                if(id == fil[r]-48)
                {
                    y = 0;
                    for(int g = r; g<r+10 ; g++)
                    {
                        nombre[y] = fil[g+15];
                        y++;
                    }
                    return;
                }

                r = r + 36;
            }else if(fil[r+2] == 'G')
            {

                r = r + 14;
            }
        }

    }else if(ti == 2)
    {
        int y = 0;



        for(int r = 0; r<(64*(co+1)) ; r++)
        {
            if(fil[r] == '\0')
            {
                return;
            }
            if(fil[r+2] == 'U')
            {
                r = r + 36;
            }else if(fil[r+2] == 'G')
            {
                if(id == fil[r]-48)
                {
                    y = 0;
                    for(int g = r; g<r+10 ; g++)
                    {
                        nombre[y] = fil[g+4];
                        y++;
                    }
                    return;
                }
                r = r + 14;
            }
        }
    }
}

void cadpermisos(char cad[],char per)
{
    cad[3] = '\0';
    switch (per) {
    case '0':
        cad[0] = '-';
        cad[1] = '-';
        cad[2] = '-';
        break;
    case '1':
        cad[0] = '-';
        cad[1] = '-';
        cad[2] = 'x';
        break;
    case '2':
        cad[0] = '-';
        cad[1] = 'w';
        cad[2] = '-';
        break;
    case '3':
        cad[0] = '-';
        cad[1] = 'w';
        cad[2] = 'x';
        break;
    case '4':
        cad[0] = 'r';
        cad[1] = '-';
        cad[2] = '-';
        break;
    case '5':
        cad[0] = 'r';
        cad[1] = '-';
        cad[2] = 'x';
        break;
    case '6':
        cad[0] = 'r';
        cad[1] = 'w';
        cad[2] = '-';
        break;
    case '7':
        cad[0] = 'r';
        cad[1] = 'w';
        cad[2] = 'x';
        break;
    default:
        break;
    }
}

void verificarpermisos(char cper[],SB sb,int ia,FILE* f)
{
    INODO auxp;
    fseek(f,sb.s_inode_start+ia*sb.s_inode_size,SEEK_SET);
    fread(&auxp,sizeof(auxp),1,f);
    cper[0] = '0';
    cper[1] = '0';
    cper[2] = '0';
    if(tienepermisolectura(auxp.i_perm,auxp.I_gid,auxp.i_uid) == 1)
    {
        cper[0] = '1';
    }
    if(tienepermisoescritura(auxp.i_perm,auxp.I_gid,auxp.i_uid) == 1)
    {
        cper[1] = '1';
    }
    if(tienepermisoejecucion(auxp.i_perm,auxp.I_gid,auxp.i_uid) == 1)
    {
        cper[2] = '1';
    }
}

int tienepermisolectura(int per, int gid, int uid)
{
    char cper[4];
    clean_char(cper,4);
    sprintf(cper,"%i",per);
    if(idusuarioactual == 1 || idgrupoactual == 1)
    {
        return 1;
    }
    if(uid == idusuarioactual)
    {
        if(cper[0]-48 > 3)
        {
            return 1;
        }
    }else if(gid == idgrupoactual)
    {
        if(cper[1]-48 > 3)
        {
            return 1;
        }
    }else
    {
        if(cper[2]-48 > 3)
        {
            return 1;
        }
    }

    return -1;
}

int tienepermisoescritura(int per, int gid, int uid)
{
    char cper[4];
    clean_char(cper,4);
    sprintf(cper,"%i",per);
    if(idusuarioactual == 1 || idgrupoactual == 1)
    {
        return 1;
    }
    if(uid == idusuarioactual)
    {
        if(cper[0]-48 == 2 || cper[0]-48 == 3 || cper[0]-48 == 6 || cper[0]-48 == 7)
        {
            return 1;
        }
    }else if(gid == idgrupoactual)
    {
        if(cper[1]-48 == 2 || cper[1]-48 == 3 || cper[1]-48 == 6 || cper[1]-48 == 7)
        {
            return 1;
        }
    }else
    {
        if(cper[2]-48 == 2 || cper[2]-48 == 3 || cper[2]-48 == 6 || cper[2]-48 == 7)
        {
            return 1;
        }
    }

    return -1;
}

int tienepermisoejecucion(int per, int gid, int uid)
{
    char cper[4];
    clean_char(cper,4);
    sprintf(cper,"%i",per);
    if(idusuarioactual == 1 || idgrupoactual == 1)
    {
        return 1;
    }
    if(uid == idusuarioactual)
    {
        if(cper[0]-48 == 1 || cper[0]-48 == 3 || cper[0]-48 == 5 || cper[0]-48 == 7)
        {
            return 1;
        }
    }else if(gid == idgrupoactual)
    {
        if(cper[1]-48 == 1 || cper[1]-48 == 3 || cper[1]-48 == 5 || cper[1]-48 == 7)
        {
            return 1;
        }
    }else
    {
        if(cper[2]-48 == 1 || cper[2]-48 == 3 || cper[2]-48 == 5 || cper[2]-48 == 7)
        {
            return 1;
        }
    }

    return -1;
}

int looprutals(vector<string> ruta, int posr, int inodoa,SB& sb,FILE* f)
{

    INODO act;
    fseek(f,sb.s_inode_start+inodoa*sb.s_inode_size,SEEK_SET);
    fread(&act,sizeof(act),1,f);
    BCARPETA bact;
    int tam = 0;
    for(int i = 0; i<12;i++){
        if(act.i_block[i] != -1){
            fseek(f,sb.s_block_start+act.i_block[i]*sb.s_block_size,SEEK_SET);
            fread(&bact,sizeof(bact),1,f);
            for (int j = 0; j< 4; j++) {
                if(string(bact.b_content[j].b_name) == ruta[posr]){
                    if(unsigned(posr) == ruta.size()-1){
                        printf("Ya existe ");
                        return bact.b_content[j].b_inode;
                    }
                    tam = looprutals(ruta,posr+1,bact.b_content[j].b_inode,sb,f);

                    return tam;
                }
            }
        }
    }

    if(unsigned(posr) == ruta.size()-1)
        return -1;
    return -1;
}

void remover()
{
    if(path.compare("") == 0)
    {
        printf("\nError, ingrese una path valida\n\n");
        return;
    }

    PM part = buscarmontada(idactual);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    if(path[0] != '/')
    {
        printf("\nError ruta no valida para la creacion del archivo\n\n");
        fclose(f);
        return;
    }
    char te[13];
    clean_char(te,13);
    int inodoa = 0;
    int inodop = 0;
    char tempi[sb.s_inodes_count];
    char tempb[sb.s_blocks_count];

    fseek(f,sb.s_bm_block_start,SEEK_SET);
    fread(&tempb,sizeof(tempb),1,f);

    fseek(f,sb.s_bm_inode_start,SEEK_SET);
    fread(&tempi,sizeof(tempi),1,f);

    char permisos[4];

    vector<string> ruta = split(path,'/');

    for(unsigned int i = 1 ; i < ruta.size(); i++)
    {
        if(ruta[i].size() > 12)
        {
            printf("\nError el nombre de un archivo no puede tener mas de 12 caracteres\n\n");
            fclose(f);
            return;
        }else
            copiar(te,const_cast<char*>(ruta[i].c_str()), ruta[i].size());

        int ia = -1;
        clean_char(permisos,4);
        verificarpermisos(permisos,sb,inodoa,f);
        if(permisos[0] == '0')
        {
            printf("\nError no se tiene acceso de lectura en la carpeta %s\n\n",te);
            fclose(f);
            return;
        }
        ia = buscarcarpeta(te,inodoa,&sb,f);
        if(ia != -1)
        {
            inodop = inodoa;
            inodoa = ia;
            clean_char(te,13);
        }else
        {
            printf("\nError, la ruta ingresada no existe\n\n");
            fclose(f);
            return;
        }

    }

    clean_char(permisos,4);
    verificarpermisos(permisos,sb,inodoa,f);
    if(permisos[1] == '0')
    {
        printf("\nError el usuario no puede eliminar la carpeta\n\n");
        fclose(f);
        return;
    }

    if(reminodo(inodoa,f,sb) == -1)
    {
        printf("\nError el usuario no puede eliminar la carpeta\n\n");
        fclose(f);
        return;
    }

    if(reminodo2(tempi,tempb,inodoa,f,sb) == 1)
    {
        printf("\nSe elimino la carpeta correctamente\n\n");
        if(sb.s_filesystem_type == 3)
        {
            JOURNAL jou[sb.s_inodes_count];
            fseek(f,isb+sizeof(sb),SEEK_SET);
            fread(&jou,sizeof(jou),1,f);
            int posj = buscarvaciojournal(jou,sb.s_inodes_count);
            jou[posj].type_trans = 6;
            jou[posj].type = 0;
            jou[posj].grupo = idgrupoactual;
            jou[posj].permiso = 0;
            jou[posj].propietario = idusuarioactual;
            jou[posj].ipadre = 0;
            copiar(jou[posj].name, te,12);
            clean_char(jou[posj].contenido,100);
            copiar(jou[posj].contenido, const_cast<char*>(path.c_str()) ,100);
            fecha(jou[posj].j_time);
            fseek(f,isb+sizeof(sb),SEEK_SET);
            fwrite(&jou,sizeof(jou),1,f);

        }
        INODO a;
        BCARPETA c;
        fseek(f,sb.s_inode_start+inodop*sb.s_inode_size,SEEK_SET);
        fread(&a,sizeof(a),1,f);
        for(int w=0; w<15; w++)
        {
            if(a.i_block[w] != -1)
            {
                fseek(f,sb.s_block_start+a.i_block[w]*sb.s_block_size,SEEK_SET);
                fread(&c,sizeof(c),1,f);
                for(int q = 0; q<4; q++)
                {
                    if(strcmp(te,c.b_content[q].b_name) == 0)
                    {
                        clean_char(c.b_content[q].b_name,12);
                        tempi[c.b_content[q].b_inode] = '0';
                        c.b_content[q].b_inode = -1;
                        if(c.b_content[0].b_inode == -1 && c.b_content[1].b_inode == -1 && c.b_content[2].b_inode == -1 && c.b_content[3].b_inode == -1)
                        {
                            tempb[a.i_block[w]] = '0';
                            a.i_block[w] = -1;
                            fseek(f,sb.s_inode_start+inodop*sb.s_inode_size,SEEK_SET);
                            fwrite(&a,sizeof(a),1,f);
                            break;
                        }
                        fseek(f,sb.s_block_start+a.i_block[w]*sb.s_block_size,SEEK_SET);
                        fwrite(&c,sizeof(c),1,f);

                    }
                }
            }
        }
    }

    fseek(f,sb.s_bm_block_start,SEEK_SET);
    fwrite(&tempb,sizeof(tempb),1,f);

    fseek(f,sb.s_bm_inode_start,SEEK_SET);
    fwrite(&tempi,sizeof(tempi),1,f);

    fseek(f,isb,SEEK_SET);
    fwrite(&sb,sizeof(sb),1,f);

    fclose(f);

}

int buscarcarpeta(char nombre[], int inodoactual,SB* sb, FILE* f)
{
    INODO iactual;
    BCARPETA bactual;
    fseek(f,sb->s_inode_start+inodoactual*sb->s_inode_size,SEEK_SET);
    fread(&iactual,sizeof(iactual),1,f);
    for(int i = 0; i<15 ; i++)
    {
        if(iactual.i_block[i] != -1)
        {
            fseek(f,sb->s_block_start+iactual.i_block[i]*sb->s_block_size,SEEK_SET);
            fread(&bactual,sizeof(bactual),1,f);
            for(int j = 0; j<4; j++)
            {
                if(strcmp(bactual.b_content[j].b_name,nombre) == 0)
                {
                    return bactual.b_content[j].b_inode;
                }
            }
        }
    }
    return -1;
}

int reminodo(int ino, FILE* f,SB sb)
{
    INODO aux;
    fseek(f,sb.s_inode_start+ino*sb.s_inode_size,SEEK_SET);
    fread(&aux,sizeof(aux),1,f);
    int elim = 0;

    char perm[4];
    clean_char(perm,4);
    verificarpermisos(perm,sb,ino,f);
    if(perm[1] == '0')
    {
        return -1;
    }

    for(int i = 0; i<15 ; i++)
    {
        if(aux.i_block[i] != -1)
        {
            if(aux.i_type == '0')
            {
                elim = remblock(aux.i_block[i],f,sb);
                if(elim == -1)
                {
                    return -1;
                }
            }
        }
    }


    return 1;
}

int remblock(int blo, FILE* f,SB sb)
{
    BCARPETA aux;
    fseek(f,sb.s_block_start+blo*sb.s_block_size,SEEK_SET);
    fread(&aux,sizeof(aux),1,f);
    int elim = 0;
    for(int i = 0; i<4 ; i++)
    {
        if(strcmp(aux.b_content[i].b_name,".") == 0 || strcmp(aux.b_content[i].b_name,"..") == 0)
        {
            continue;
        }
        if(aux.b_content[i].b_inode != -1)
        {
            elim = reminodo(aux.b_content[i].b_inode,f,sb);
            if(elim == -1)
            {
                return -1;
            }
        }
    }
    return 1;
}

int reminodo2(char* ti, char* tb,int ino, FILE* f,SB sb)
{
    INODO aux;
    fseek(f,sb.s_inode_start+ino*sb.s_inode_size,SEEK_SET);
    fread(&aux,sizeof(aux),1,f);
    int elim = 0;
    char el = '*';
    for(int i = 0; i<15 ; i++)
    {
        if(aux.i_block[i] != -1)
        {
            if(aux.i_type == '0')
            {
                remblock2(ti,tb,aux.i_block[i],f,sb);
                if(elim == -1)
                {
                    el = 'n';
                }else
                {
                    tb[aux.i_block[i]] = '0';
                    aux.i_block[i] = -1;
                    sb.s_free_blocks_count = sb.s_free_blocks_count + 1;
                }
            }else
            {
                tb[aux.i_block[i]] = '0';
            }
        }
    }
    fseek(f,sb.s_inode_start+ino*sb.s_inode_size,SEEK_SET);
    fwrite(&aux,sizeof(aux),1,f);


    return 1;
}

int remblock2(char* ti, char* tb,int blo, FILE* f,SB sb)
{
    BCARPETA aux;
    fseek(f,sb.s_block_start+blo*sb.s_block_size,SEEK_SET);
    fread(&aux,sizeof(aux),1,f);
    int elim = 0;
    char el = '*';
    for(int i = 0; i<4 ; i++)
    {
        if(strcmp(aux.b_content[i].b_name,".") == 0 || strcmp(aux.b_content[i].b_name,"..") == 0)
        {
            continue;
        }
        if(aux.b_content[i].b_inode != -1)
        {
            reminodo2(ti,tb,aux.b_content[i].b_inode,f,sb);
            if(elim == -1)
            {
                el = 'n';
            }else
            {
                ti[aux.b_content[i].b_inode] = '0';
                clean_char(aux.b_content[i].b_name,12);
                aux.b_content[i].b_inode = -1;
                sb.s_free_inodes_count = sb.s_free_inodes_count + 1;
            }
        }
    }
    fseek(f,sb.s_block_start+blo*sb.s_block_size,SEEK_SET);
    fwrite(&aux,sizeof(aux),1,f);

    return 1;
}

int reminodo3(char* ti, char* tb,int ino, FILE* f,SB sb)
{
    INODO aux;
    fseek(f,sb.s_inode_start+ino*sb.s_inode_size,SEEK_SET);
    fread(&aux,sizeof(aux),1,f);
    int elim = 0;
    char el = '*';
    for(int i = 0; i<15 ; i++)
    {
        if(aux.i_block[i] != -1)
        {
            if(aux.i_type == '0')
            {
                elim = remblock2(ti,tb,aux.i_block[i],f,sb);
                if(elim == -1)
                {
                    el = 'n';
                }else
                {
                    tb[aux.i_block[i]] = '0';
                    aux.i_block[i] = -1;
                    sb.s_free_blocks_count = sb.s_free_blocks_count + 1;
                }
            }
        }
    }
    fseek(f,sb.s_inode_start+ino*sb.s_inode_size,SEEK_SET);
    fwrite(&aux,sizeof(aux),1,f);
    if(el != '*')
    {
        return -1;
    }
    char perm[4];
    clean_char(perm,4);
    verificarpermisos(perm,sb,ino,f);
    if(perm[1] == '0')
    {
        return -1;
    }

    return 1;
}

int remblock3(char* ti, char* tb,int blo, FILE* f,SB sb)
{
    BCARPETA aux;
    fseek(f,sb.s_block_start+blo*sb.s_block_size,SEEK_SET);
    fread(&aux,sizeof(aux),1,f);
    int elim = 0;
    char el = '*';
    for(int i = 0; i<4 ; i++)
    {
        if(strcmp(aux.b_content[i].b_name,".") == 0 || strcmp(aux.b_content[i].b_name,"..") == 0)
        {
            continue;
        }
        if(aux.b_content[i].b_inode != -1)
        {
            elim = reminodo2(ti,tb,aux.b_content[i].b_inode,f,sb);
            if(elim == -1)
            {
                el = 'n';
            }else
            {
                ti[aux.b_content[i].b_inode] = '0';
                clean_char(aux.b_content[i].b_name,12);
                aux.b_content[i].b_inode = -1;
                sb.s_free_inodes_count = sb.s_free_inodes_count + 1;
            }
        }
    }
    fseek(f,sb.s_block_start+blo*sb.s_block_size,SEEK_SET);
    fwrite(&aux,sizeof(aux),1,f);

    if(el != '*')
    {
        return -1;
    }
    return 1;
}

void mover()
{
    if(path.compare("") == 0)
    {
        printf("\nError ingrese una ruta origen valida\n\n");
        return;
    }
    if(dest.compare("") == 0)
    {
        printf("\nError ingrese una ruta destino valida\n\n");
        return;
    }

    PM part = buscarmontada(idactual);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    if(path[0] != '/')
    {
        printf("\nError ruta no valida para la creacion del archivo\n\n");
        fclose(f);
        return;
    }

    //--------------------------------------------------ORIGEN
    char te[13];
    clean_char(te,13);
    int punt = 0;
    int inodoa = 0;
    int inodop = 0;

    char tempi[sb.s_inodes_count];
    char tempb[sb.s_blocks_count];

    fseek(f,sb.s_bm_block_start,SEEK_SET);
    fread(&tempb,sizeof(tempb),1,f);

    fseek(f,sb.s_bm_inode_start,SEEK_SET);
    fread(&tempi,sizeof(tempi),1,f);

    for(int i = 1; i<300;i++)
    {

        if(path[i] != '/' && path[i] != '\0')
        {
            te[punt] = path[i];
            punt++;
        }else
        {
            int ia = -1;
            ia = buscarcarpeta(te,inodoa,&sb,f);
            if(ia != -1)
            {
                inodop = inodoa;
                inodoa = ia;
                if(path[i] == '\0')
                {
                    break;
                }
                clean_char(te,13);
                punt = 0;
            }else
            {
                printf("\nError, la ruta ingresada no existe\n\n");
                fclose(f);
                return;
            }
        }
    }

    //----------------------------------------------------------DESTINO

    char te2[13];
    clean_char(te2,13);
    int punt2 = 0;
    int inodoa2 = 0;
    int inodop2 = 0;

    for(int i = 1; i<300;i++)
    {

        if(dest[i] != '/' && dest[i] != '\0')
        {
            te2[punt2] = dest[i];
            punt2++;
        }else
        {
            int ia = -1;
            ia = buscarcarpeta(te2,inodoa2,&sb,f);
            if(ia != -1)
            {
                inodop2 = inodoa2;
                inodoa2 = ia;
                if(dest[i] == '\0')
                {
                    break;
                }
                clean_char(te2,13);
                punt2 = 0;
            }else
            {
                printf("\nError, la ruta ingresada no existe\n\n");
                fclose(f);
                return;
            }
        }
    }

    INODO origen;
    fseek(f,sb.s_inode_start+inodop*sb.s_inode_size,SEEK_SET);
    fread(&origen,sizeof(origen),1,f);

    INODO destino;
    fseek(f,sb.s_inode_start+inodoa2*sb.s_inode_size,SEEK_SET);
    fread(&destino,sizeof(destino),1,f);

    BCARPETA borigen;
    BCARPETA borigen2;

    int apuntador = -1;

    for(int i= 0; i<15; i++)
    {
        if(origen.i_block[i] != -1)
        {
            fseek(f,sb.s_block_start+origen.i_block[i]*sb.s_block_size,SEEK_SET);
            fread(&borigen,sizeof(borigen),1,f);
            for(int j = 0; j<4; j++)
            {
                if(strcmp(te,borigen.b_content[j].b_name) == 0)
                {
                    apuntador = borigen.b_content[j].b_inode;
                    borigen.b_content[j].b_inode = -1;
                    clean_char(borigen.b_content[j].b_name,12);
                    if(borigen.b_content[0].b_inode == -1 && borigen.b_content[1].b_inode == -1 && borigen.b_content[2].b_inode == -1 && borigen.b_content[3].b_inode == -1)
                    {
                        tempb[origen.i_block[i]] = '0';
                        origen.i_block[i] = -1;
                        fseek(f,sb.s_inode_start+inodop*sb.s_inode_size,SEEK_SET);
                        fwrite(&origen,sizeof(origen),1,f);
                        break;
                    }
                    fseek(f,sb.s_block_start+origen.i_block[i]*sb.s_block_size,SEEK_SET);
                    fwrite(&borigen,sizeof(borigen),1,f);
                }
            }
        }
    }

    if(apuntador == -1)
    {
        printf("\nError el directorio de origen no existe\n\n");
        fclose(f);
        return;
    }
    char sal = '*';
    for(int i= 0; i<15; i++)
    {
        if(destino.i_block[i] != -1)
        {
            fseek(f,sb.s_block_start+destino.i_block[i]*sb.s_block_size,SEEK_SET);
            fread(&borigen2,sizeof(borigen2),1,f);
            for(int j = 0; j<4; j++)
            {
                if(borigen2.b_content[j].b_inode == -1)
                {
                    borigen2.b_content[j].b_inode = apuntador;
                    copiar(borigen2.b_content[j].b_name,te,12);
                    fseek(f,sb.s_block_start+destino.i_block[i]*sb.s_block_size,SEEK_SET);
                    fwrite(&borigen2,sizeof(borigen2),1,f);
                    sal = 's';
                    break;
                }
            }
            if(sal != '*')
            {
                break;
            }
        }else
        {
            BCARPETA nuev;
            setBLOQUEC2(nuev);

            int bnuev = buscarlibre(tempb,sb.s_blocks_count);

            destino.i_block[i] = bnuev;
            fseek(f,sb.s_inode_start+inodop2*sb.s_inode_size,SEEK_SET);
            fwrite(&destino,sizeof(destino),1,f);

            nuev.b_content[0].b_inode = apuntador;
            clean_char(nuev.b_content[0].b_name,12);
            copiar(nuev.b_content[0].b_name,te,12);

            fseek(f,sb.s_block_start+bnuev*sb.s_block_size,SEEK_SET);
            fwrite(&nuev,sizeof(nuev),1,f);
            break;


        }
    }

    if(sb.s_filesystem_type == 3)
    {
        JOURNAL jou[sb.s_inodes_count];
        fseek(f,isb+sizeof(sb),SEEK_SET);
        fread(&jou,sizeof(jou),1,f);
        int posj = buscarvaciojournal(jou,sb.s_inodes_count);
        jou[posj].type_trans = 7;
        jou[posj].type = 0;
        jou[posj].grupo = idgrupoactual;
        jou[posj].permiso = 0;
        jou[posj].propietario = idusuarioactual;
        jou[posj].ipadre = inodoa2;
        copiar(jou[posj].name,te2,12);
        clean_char(jou[posj].contenido,100);
        copiar(jou[posj].contenido, const_cast<char*>(path.c_str()),100);
        fecha(jou[posj].j_time);
        fseek(f,isb+sizeof(sb),SEEK_SET);
        fwrite(&jou,sizeof(jou),1,f);
    }

    printf("\nSe movio la carpeta %s con exito\n\n",te);

    fclose(f);


}

void ren()
{
    if(path.compare("") == 0)
    {
        printf("\nError, ingrese una path valida\n\n");
        return;
    }
    if(name.compare("") == 0)
    {
        printf("\nError, ingrese un nombre valido\n\n");
        return;
    }

    PM part = buscarmontada(idactual);
    if(part.direccion == -2)
    {
        return;
    }
    FILE* f = fopen(part.path.c_str(),"r+b");
    if(f == NULL)
    {
        printf("\nError no se pudo leer el disco\n\n");
        return;
    }
    SB sb;
    int isb = -1;
    if(part.type == 'l')
    {
        isb = part.direccion+sizeof(EBR);
    }else if(part.type == 'p')
    {
        isb = part.direccion;
    }

    fseek(f,isb,SEEK_SET);
    fread(&sb,sizeof(sb),1,f);

    if(path[0] != '/')
    {
        printf("\nError ruta no valida para la creacion del archivo\n\n");
        fclose(f);
        return;
    }
    char te[13];
    clean_char(te,13);
    int inodoa = 0;
    int inodop = 0;
    char tempi[sb.s_inodes_count];
    char tempb[sb.s_blocks_count];

    fseek(f,sb.s_bm_block_start,SEEK_SET);
    fread(&tempb,sizeof(tempb),1,f);

    fseek(f,sb.s_bm_inode_start,SEEK_SET);
    fread(&tempi,sizeof(tempi),1,f);

    char permisos[4];

    vector<string> ruta = split(path,'/');

    char te2[13];
    copiarS(te2, name, 12);

    for(unsigned int i = 1 ; i < ruta.size(); i++)
    {
        if(ruta[i].size() > 12)
        {
            printf("\nError el nombre de un archivo no puede tener mas de 12 caracteres\n\n");
            fclose(f);
            return;
        }else
            copiar(te,const_cast<char*>(ruta[i].c_str()), ruta[i].size());

        int ia = -1;
        clean_char(permisos,4);
        verificarpermisos(permisos,sb,inodoa,f);
        if(permisos[0] == '0')
        {
            printf("\nError no se tiene acceso de lectura en la carpeta %s\n\n",te);
            fclose(f);
            return;
        }

        if(i == ruta.size()-1)
        {
            ia = buscarcarpeta(te2,inodoa,&sb,f);
            if(ia != -1)
            {
                printf("\nError, el nombre ya existe\n\n");
                return;
            }
            ia = buscar_rename(te,inodoa, &sb, f, te2);

            if(sb.s_filesystem_type == 3)
            {
                JOURNAL jou[sb.s_inodes_count];
                fseek(f,isb+sizeof(sb),SEEK_SET);
                fread(&jou,sizeof(jou),1,f);
                int posj = buscarvaciojournal(jou,sb.s_inodes_count);
                jou[posj].type_trans = 8;
                jou[posj].type = 0;
                jou[posj].grupo = idgrupoactual;
                jou[posj].permiso = 0;
                jou[posj].propietario = idusuarioactual;
                jou[posj].ipadre = 0;
                copiar(jou[posj].name, te2,12);
                clean_char(jou[posj].contenido,100);
                copiar(jou[posj].contenido, const_cast<char*>(path.c_str()) ,100);
                fecha(jou[posj].j_time);
                fseek(f,isb+sizeof(sb),SEEK_SET);
                fwrite(&jou,sizeof(jou),1,f);
            }
            break;
        }else
            ia = buscarcarpeta(te,inodoa,&sb,f);
        if(ia != -1)
        {
            inodop = inodoa;
            inodoa = ia;
            clean_char(te,13);
        }else
        {
            printf("\nError, la ruta ingresada no existe\n\n");
            fclose(f);
            return;
        }
    }


}

int buscar_rename(char nombre[], int inodoactual,SB* sb, FILE* f, char nombre_new[])
{
    INODO iactual;
    BCARPETA bactual;
    fseek(f,sb->s_inode_start+inodoactual*sb->s_inode_size,SEEK_SET);
    fread(&iactual,sizeof(iactual),1,f);
    for(int i = 0; i<15 ; i++)
    {
        if(iactual.i_block[i] != -1)
        {
            fseek(f,sb->s_block_start+iactual.i_block[i]*sb->s_block_size,SEEK_SET);
            fread(&bactual,sizeof(bactual),1,f);
            for(int j = 0; j<4; j++)
            {
                if(strcmp(bactual.b_content[j].b_name,nombre) == 0)
                {
                    int inodoa = bactual.b_content[j].b_inode;

                    char permisos[4];
                    clean_char(permisos,4);
                    verificarpermisos(permisos,*sb,inodoa,f);

                    if(permisos[1] == '0')
                    {
                        printf("\nError el usuario no puede modificar la carpeta\n\n");
                        fclose(f);
                        return -1;
                    }

                    INODO origen;
                    fseek(f,sb->s_inode_start+inodoa*sb->s_inode_size,SEEK_SET);
                    fread(&origen,sizeof(origen),1,f);

                    if(origen.i_type == '1' && verificar_carpeta(nombre_new, 12))
                    {
                        clean_char(bactual.b_content[j].b_name, 12);
                        copiar(bactual.b_content[j].b_name, nombre_new, 12);
                        fseek(f,sb->s_block_start+iactual.i_block[i]*sb->s_block_size,SEEK_SET);
                        fwrite(&bactual,sizeof(bactual),1,f);

                        fseek(f,sb->s_block_start+iactual.i_block[i]*sb->s_block_size,SEEK_SET);
                        fread(&bactual,sizeof(bactual),1,f);

                        fecha(origen.i_mtime);
                        fseek(f,sb->s_inode_start+inodoa*sb->s_inode_size,SEEK_SET);
                        fwrite(&origen,sizeof(origen),1,f);

                        fseek(f,sb->s_inode_start+inodoa*sb->s_inode_size,SEEK_SET);
                        fread(&origen,sizeof(origen),1,f);
                        printf("\nModificacion con exito\n\n");
                        return 1;
                    }else
                        printf("\nNo se puede renombrar un archivo como carpeta o viseversa\n\n");

                }
            }
        }
    }
    return -1;
}

bool verificar_carpeta(char name[], int size)
{
    for(int i = size-1; i > -1 ; i--)
    {
        if(name[i] == '.')
            return true;
    }
    return false;
}
