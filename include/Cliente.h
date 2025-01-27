#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include "Registro.h"
#include <stack>

using namespace std;

class Cliente
{
    string nombre;

    public:
        Cliente();
        ~Cliente();

        Registro cuentaPersonal;

        void setNombre(string n);
        string getNombre()const;

        void respaldar_Recibos();
        void recuperar_Recibos();

        bool operator==(const Cliente& c){
            return nombre == c.nombre;
        }

        bool operator==(const Cliente& c)const{
            return nombre == c.nombre;
        }

    protected:

    private:
};

#endif // CLIENTE_H
