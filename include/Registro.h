#ifndef REGISTRO_H
#define REGISTRO_H
#include "Recibo.h"
#include <iostream>
#include <iomanip>

class Registro
{

    public:
        Registro();
        ~Registro();

        Recibo* head;

        void insertFront(Recibo* r);
        void deleteFront();
        void display(int v);
        void busqueda(int v);
        int tam();
        void bubble();

    protected:

    private:
};

#endif // REGISTRO_H
