#ifndef JOYA_H
#define JOYA_H
#include <iostream>
#include <iomanip>

using namespace std;


class Joya
{
    public:
        string nombre;
        string tipo;
        string forma;
        int cantidad;
        float precio;

        void setNombre(const string &n);
        string getNombre();

        void setTipo(string t);
        string getTipo();

        void setForma(string f);
        string getForma();

        void setCantidad(int c);
        int getCantidad();

        void setPrecio(float p);
        float getPrecio();

        Joya();
        Joya(string n, string t, string f, int c, float p);
        ~Joya();

        friend istream& operator>>(istream &interno, Joya &j ){

            cout << "Registro de datos" << endl;
            cin.ignore();

            cout << "Tipo: ";
            getline(cin, j.tipo);
            j.setTipo(j.tipo);

            cout << "Forma: ";
            getline(cin, j.forma);
            j.setForma(j.forma);

            cout << "Cantidad: ";
            cin >> j.cantidad;

            cout << "Precio: ";
            cin >> j.precio;

            cout << endl;

            return interno;
        }

        friend ostream& operator<<(ostream &externo, Joya &j){

            externo << left;
            externo << "  " << setw(10) << j.nombre;
            externo << "  " << setw(10) << j.precio;
            externo << "  " << setw(10) << j.tipo;
            externo << "  " << setw(15) << j.forma;
            externo << "  " << j.cantidad ;

            return externo;
        }

         bool operator==(const Joya& j){
            return nombre == j.nombre;
        }

        bool operator==(const Joya& j)const{
            return nombre == j.nombre;
        }

    protected:

    private:
};

#endif // JOYA_H
