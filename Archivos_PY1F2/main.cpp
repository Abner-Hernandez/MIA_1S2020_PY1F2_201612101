#include <iostream>
#include <driver.h>
#include<iostream>
#include<fstream>

using namespace std;

void create_folder_img();
string verificate_line(string line);

int main()
{
    create_folder_img();
    string entry = "";
    analizer_driver driver;
    driver.init_mount();
    while (true) {

        getline(cin, entry);
        if(entry.compare("exit") != 0 && entry.compare("") != 0)
        {
            entry = verificate_line(entry);
            if(driver.parse(entry)){
              printf("La entrada es incorrecta\n");
            }else{
                if(driver.get_bool_exec() == true)
                {
                    driver.set_exec_bool();
                    string d = driver.get_path();
                    ifstream  file(d);
                    if(file.is_open())
                    {
                        string line;
                        while (getline(file, line)) {
                            line = verificate_line(line);
                            if(line.compare("") != 0)
                            {
                                if(!driver.parse(line))
                                    printf("La entrada es correcta\n");
                                else
                                    printf("La entrada es incorrecta\n");
                                driver.set_default_vars_methods();
                            }
                        }
                        printf("El archivo se termino de leer\n");
                        file.close();
                    }

                }
            }
        }else if(entry.compare("exit") == 0)
            break;
    }

    return 0;
}

void create_folder_img()
{
    FILE *f = fopen("./Images", "rb");
    if(f == NULL)
        system("mkdir ./Images");
}

string verificate_line(string line)
{
    if(line.at(line.size()-1) == '\r' && line.size() > 1)
        return line.substr(0, line.size()-1);
    else if (line.at(0) == '\r' && line.size() == 1)
        return "";
    return line;
}
