#include <iostream>
#include "GeneralManager.h"
#include <cstdlib>
#include <conio.h>
#include <algorithm>

using namespace std;

int main()
{
    GeneralManager control;
    control.recuperarUser();
    control.recuperarInvent();
    control.recuperarClient();
    control.prefab();

    while(true){
    bool validation = false;
    string nombre;

    while(validation == false){
        cout << endl;
        control.showUsers();
        cout << endl << endl << "Elija el usuario para ingresar: " << endl;

        string eleccion;
        getline(cin, eleccion);

        Usuario temp; temp.setNombre(eleccion);
        Usuario* test = control.buscarUsuario(temp);

        if(test == nullptr){
            cout << "Vuelvalo a intentar" << endl << endl;
        }else{
            int contador = 0;
            while(true){
                if(contador == 3){
                    break;
                }
                cout << "Ingrese contraseña: ";
                string pw;
                char caracter;
                caracter = getch();

                pw = "" ;

                while(caracter != 13){
                    if(caracter != 8){
                        pw.push_back(caracter);
                        cout << "*";
                    }else{
                        if(pw.length() > 0){
                            cout << "\b \b";
                            pw = pw.substr(0, pw.length()-1);
                        }
                    }
                    caracter = getch();
                }
                string a = test->getPassword();
                if(pw == a){
                    cout << "Ingreso con exito" << endl;
                    validation = true;
                    string c = test->getNombre();
                    nombre = c;
                    break;
                }else{
                    cout << endl << "Contraseña incorrecta" << endl;
                    contador ++;
                }
            }
        }
        system("cls");
    }
        int cS;
        Usuario temp; temp.setNombre(nombre);
        Usuario* base = control.buscarUsuario(temp);

        cout << "Bienvenido/a, " << nombre << "¿Que desea hacer" << endl;
        if (base->getTipo() == 0){
            control.menuAdmin(base);
        }else if(base->getTipo() == 1){
            control.menuGerente(base);
        }else if(base->getTipo() == 2){
            control.menuTrabajador(base);
        }else{
            cout << "Error de sistema" << endl;
        }
        cout << "¿Desea cerrar sesion ?" << endl << "1. Si" << endl;
        cin >> cS;
        if(cS == 1){
            control.respaldar();
            break;
        }
    }
    return 0;
}
