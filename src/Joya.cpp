#include "Joya.h"
#include <algorithm>

Joya::Joya()
{
    //ctor
}

Joya::Joya(string n, string t, string f, int c, float p){

    this->nombre = n;
    this->tipo = t;
    this->forma = f;
    this->cantidad = c;
    this->precio = p;
}


void Joya::setCantidad(int c){
    cantidad = c;
}

void Joya::setForma(string f){
     transform(f.begin(), f.end(), f.begin(),[](unsigned char c){return toupper(c);});
    forma = f;
}

void Joya::setNombre(const string &n){
    nombre = n;
}

void Joya::setPrecio(float p){
    precio = p;
}

void Joya::setTipo(string t){
    transform(t.begin(), t.end(), t.begin(),[](unsigned char c){return toupper(c);});
    tipo = t;
}

string Joya::getNombre(){
    return nombre;
}
string Joya::getTipo(){
    return tipo;
}
string Joya::getForma(){
    return forma;
}

float Joya::getPrecio(){
    return precio;
}

int Joya::getCantidad(){
    return cantidad;
}

Joya::~Joya()
{
    //dtor
}
