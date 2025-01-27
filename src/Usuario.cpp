#include "Usuario.h"

Usuario::Usuario()
{
    //ctor
}

void Usuario::setNombre(const string &n){
    nombre = n;
}

void Usuario::setTipo(int t){
    tipo = t;
}

void Usuario::setPassword(const string &p){
    password = p;
}

string Usuario::getNombre()const{
    return nombre;
}

string Usuario::getPassword(){
    return password;
}

int Usuario::getTipo(){
    return tipo;
}

string Usuario::getTipoTxt()const
{
    string cero = "Admin";
    string uno = "Gerente";
    string dos = "Trabajador";
    if(tipo == 0){
        return cero;
    }else if(tipo == 1){
        return uno;
    }else if(tipo == 2){
        return dos;
    }else{
        return NULL;
    }

}

Usuario::~Usuario()
{
    //dtor
}
