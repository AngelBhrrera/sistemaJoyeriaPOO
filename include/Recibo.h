#ifndef RECIBO_H
#define RECIBO_H
#include <iostream>
#include <iomanip>
#include "Joya.h"

using namespace std;

class Recibo
{
    public:
        Joya adquirida;
        string metodoDP;
        float pago;
        float cambio;
        Recibo* next;
        Recibo* prev;
        Recibo();
        ~Recibo();

        string getMDP();
        void setMDP(string s);

        void setPago(float p);
        float getPago();

        void setCambio(float c);
        float getCambio();

        friend ostream& operator<<(ostream &externo, Recibo &r){

            externo << left;
            externo << r.adquirida;
            externo << setw(10) << r.metodoDP;
            externo << setw(10) << r.pago;
            externo << setw(15) << r.cambio;

            return externo;
        }

    private:
};

#endif // RECIBO_H
