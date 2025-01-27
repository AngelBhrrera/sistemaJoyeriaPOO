#ifndef GENERALMANAGER_H
#define GENERALMANAGER_H
#include <iostream>
#include "vector"

#include "Usuario.h"
#include "Cliente.h"
#include "Joya.h"

using namespace std;

class GeneralManager
{

    public:
        vector <Joya> inventario;
        vector <Cliente> clientela;
        vector<Usuario> users;

        void userGenerator(const Usuario &u);
        void itemAdd(const Joya &j);
        void newClient(const Cliente &c);

        void prefab();
        int passwordChecker(string p, Usuario* u);
        void menuAdmin(Usuario* u);
        void menuGerente(Usuario* u);
        void menuTrabajador(Usuario* u);

        void showUsers();
        void showInvent();
        void showClient();

        Usuario* buscarUsuario(const Usuario &u);
        Joya* buscarJoya(const Joya &j);
        Cliente* buscarCliente(const Cliente &c);

        int indexU(string &u);
        int indexC(string &c);
        int indexI(string &i);

        void respaldar();

        void recuperarUser();
        void recuperarInvent();
        void recuperarClient();

        string inventoryID(const Joya &j);

        GeneralManager();

    protected:

    private:

};

#endif // GENERALMANAGER_H
