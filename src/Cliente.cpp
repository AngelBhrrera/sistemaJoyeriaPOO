#include "Cliente.h"
#include <fstream>
#include <algorithm>

Cliente::Cliente()
{
    //ctor
}

void Cliente::setNombre(string n){
    transform(n.begin(), n.end(), n.begin(),[](unsigned char c){return toupper(c);});
    nombre = n;
}

string Cliente::getNombre()const{
    return nombre;
}

void Cliente::respaldar_Recibos(){
    ofstream archivo1(getNombre() + ".txt");
    Recibo *r;
    r = cuentaPersonal.head;
    while(r != NULL){
        archivo1 << r->adquirida.nombre << endl;
        archivo1 << r->adquirida.tipo << endl;
        archivo1 << r->adquirida.forma << endl;
        archivo1 << r->adquirida.cantidad << endl;
        archivo1 << r->adquirida.precio << endl;
        archivo1 << r->getPago() << endl;
        archivo1 << r->getMDP() << endl;
        r = r->next;
    }
    archivo1.close();
}

void Cliente::recuperar_Recibos()
{
        ifstream archivo(getNombre()+".txt");
        if(archivo.is_open()){

            string temporal;
            int inTemporal;
            float floaTemporal;

            while(true){
                Recibo* r = new Recibo();

                getline(archivo, temporal);
                r->adquirida.setNombre(temporal);
                if(archivo.eof()){
                    break;
                }
                getline(archivo, temporal);
                r->adquirida.setTipo(temporal);

                getline(archivo, temporal);
                r->adquirida.setForma(temporal);

                getline(archivo, temporal);
                inTemporal = stoi (temporal);
                r->adquirida.setCantidad(inTemporal);

                getline(archivo, temporal);
                floaTemporal = stof (temporal);
                r->adquirida.setPrecio(floaTemporal);

                getline(archivo, temporal);
                floaTemporal = stof (temporal);
                r->setPago(floaTemporal);

                getline(archivo, temporal);
                r->setMDP(temporal);

                floaTemporal = r->getPago() - r->adquirida.getPrecio();
                r->setCambio(floaTemporal);

                cuentaPersonal.insertFront(r);
            }
        archivo.close();
        }
}

Cliente::~Cliente()
{
    //dtor
}
