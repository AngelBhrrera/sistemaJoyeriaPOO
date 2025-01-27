#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <iomanip>

using namespace std;

class Usuario
{
    public:
        public:
        string nombre;
        string password;
        int tipo;

        Usuario();
        Usuario(const string &n, const string &p, int t);

        string getNombre()const;
        string getTipoTxt()const;
        int getTipo();
        string getPassword();
        void setNombre(const string &n);
        void setPassword(const string &p);
        void setTipo(int t);

        bool operator==(const Usuario& u){
            return nombre == u.nombre;
        }

        bool operator==(const Usuario& u)const{
            return nombre == u.nombre;
        }

        ~Usuario();

        friend istream& operator>>(istream &interno, Usuario &u ){

            cout << "Registro datos" << endl;
            cin.ignore();
            cout << "Nombre: ";
            getline(cin, u.nombre);

            cout << "Password: ";
            getline(cin, u.password);

            cout << "Tipo: ";
            cin >> u.tipo;
            if(u.tipo > 2){
                u.tipo = 2;
            }

            cout << endl;
            return interno;
        }

        friend ostream& operator<<(ostream &externo, Usuario &u){
            externo << "Nombre: " << u.nombre << "  " ;
            externo << "Tipo: ";
            if(u. tipo == 0){
                externo << " Admin";
            }else if(u.tipo == 1){
                externo << " Gerente";
            }else if(u.tipo == 2){
                externo << " - ";
            }
            externo << u.password;
            externo << endl;

            return externo;
        }

    private:
};

#endif // USUARIO_H
