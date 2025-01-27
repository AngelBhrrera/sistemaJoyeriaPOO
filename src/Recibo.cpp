#include "Recibo.h"

Recibo::Recibo()
{
    next = NULL;
}

void Recibo::setPago(float p){
    pago = p;
}

float Recibo::getPago(){
    return pago;
}

void Recibo::setCambio(float c){
    cambio = adquirida.getPrecio() - pago;
}

float Recibo::getCambio(){
    return cambio;
}

string Recibo::getMDP(){
    return metodoDP;
}

void Recibo::setMDP(string s){
    metodoDP = s;
}

Recibo::~Recibo()
{
    //dtor
}
