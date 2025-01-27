#include "GeneralManager.h"
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <fstream>

GeneralManager::GeneralManager(){

}

void GeneralManager:: prefab(){
     if(users.empty()){
        string uno = "Admin";
        string dos = "12345";
        int tres = 0;
        Usuario admin;
        admin.setNombre(uno);
        admin.setPassword(dos);
        admin.setTipo(tres);
        users.push_back(admin);
        Cliente c;
        string a = "Publico general";
        c.setNombre(a);
        newClient(c);
    }
}

void GeneralManager::userGenerator(const Usuario &u){

    users.push_back(u);

}

void GeneralManager::newClient(const Cliente &c){

    for(size_t i = 0; i < clientela.size() ; i++){
            if(clientela[i].getNombre() == c.getNombre()){
                cout << "No se puede agregar el cliente porque ya existe" << endl;
                return;
            }
    }
    clientela.push_back(c);
}

void GeneralManager::itemAdd(const Joya &j){

    inventario.push_back(j);

}

void GeneralManager::showUsers()
{
    for(size_t i = 0; i < users.size() ; i++){
            Usuario sample = users[i];
            cout << sample.getNombre() << "       ";
            }
}

void GeneralManager::showInvent()
{
    cout << left;
    cout << setw(10) << "|  ID  |";
    cout << setw(10) << "|  PRECIO  | ";
    cout << setw(15) << "|  TIPO  | ";
    cout << setw(15) << "|  FORMA  | ";
    cout << "|  CANTIDAD  | " << endl << endl;

    for(size_t i = 0; i < inventario.size() ; i++){
            Joya sample = inventario[i];
            cout << sample << endl;

            }
}

void GeneralManager::showClient(){

    for(size_t i = 0; i < clientela.size() ; i++){
            Cliente sample = clientela[i];
            cout << "Nombre: " << sample.getNombre() << endl;
            }
}

Usuario* GeneralManager::buscarUsuario(const Usuario &u)
{
    auto it = find(users.begin(), users.end(), u);
    if(it == users.end()){
        return nullptr;
    }else{
        return &(*it);
    }
}

Joya* GeneralManager::buscarJoya(const Joya &j)
{
    auto it = find(inventario.begin(), inventario.end(), j);
    if(it == inventario.end()){
        return nullptr;
    }else{
        return &(*it);
    }
}

Cliente* GeneralManager::buscarCliente(const Cliente &c){
    auto it = find(clientela.begin(), clientela.end(), c);
    if(it == clientela.end()){
        return nullptr;
    }else{
        return &(*it);
    }
}

int GeneralManager::passwordChecker(string p, Usuario* u){
    cout << "b";
    string sample;
    sample = u->password;
    cout << sample;
    if(p == sample){
            cout << "d";
        return 1;
    }else{
        cout << "d";
        return 0;
    }
}

int GeneralManager::indexU(string &c)
{
    string sample = c;
    int indicador;

    for(size_t i = 0; i < users.size() ; i++){
            if(users[i].getNombre() == c){
                indicador = i;
                return indicador;
            }
    }
    return -1;
}

int GeneralManager::indexI(string &c)
{
    string sample = c;
    int indicador;

    for(size_t i = 0; i < inventario.size() ; i++){
            if(inventario[i].getNombre() == c){
                indicador = i;
                return indicador;
            }
    }
    cout << "No  existe";
    return -1;
}

int GeneralManager::indexC(string &c){
    string sample = c;
    int indicador;

    for(size_t i = 0; i < clientela.size() ; i++){
            if(clientela[i].getNombre() == c){
                indicador = i;
                return indicador;
            }
    }
    return -1;
}

string GeneralManager::inventoryID(const Joya &j){

    string n;
    int base;
    string joy;
    string tip;
    string ID;

            n = 48 + inventario.size();
            base = stoi(n);
            if(base >= 58){
                n = "1" + 38 + inventario.size();
                if( base >= 68){
                    n = "2" + 28 + inventario.size();
                    if(base >= 78){
                        n = "3" + 18 + inventario.size();
                        if(base >= 88){
                            n = "4" + 8 + inventario.size();
                        }
                    }
                }
            }
            cout << n;

            if(j.tipo == "DIAMANTE"){
                joy = "DE";
            }else if(j.tipo == "ORO"){
                joy  = "OO";
            }else if(j.tipo == "AQUA"){
                joy = "AA";
            }else if(j.tipo == "ESMERALDA"){
                joy = "EA";
            }else if(j.tipo == "RUBI"){
                joy = "RI";
            }else if(j.tipo == "ZAFIRO"){
                joy = "ZO";
            }else if(j.tipo == "TOPACIO"){
                joy = "TO";
            }else if(j.tipo == "TANZANITA"){
                joy = "TA";
            }else if(j.tipo == "MORGANITA"){
                joy = "MA";
            }else if(j.tipo == "LUNA"){
                joy = "LA";
            }else if(j.tipo == "JADE"){
                joy = "JE";
            }else{
                joy = "MI";
            }

            if(j.forma == "ARGOLLA"){
                tip = "01";
            }else if(j.forma == "BROQUELES"){
                tip = "02";
            }else if(j.forma == "CHURUMBELAS"){
                tip = "03";
            }else if(j.forma == "DIJE"){
                tip = "04";
            }else if(j.forma == "GENERAL"){
                tip = "05";
            }else if(j.forma == "SOLITARIO"){
                tip = "06";
            }else{
                tip = "07";
            }

    ID = joy + tip + n;
    return ID;
}

void GeneralManager::menuAdmin(Usuario* u){

    while(true){
            system("cls");
            int opcion;
            cout << endl << right;
            cout << "     ----  M    E    N    U  ----     " << endl << endl;
            cout << "1. COMPRA  | 2. CLIENTE | 3. INVENTARIO " << endl;
            cout << "4. USUARIO | 5. CUENTAS | 6 SALIR" << endl;
            cin >> opcion;

            if(opcion == 1){
                cin.ignore();
                string name;
                cout << "Nombre del cliente: ";
                getline(cin, name);
                int use;
                use = indexC(name);
                if(use == -1){
                    int opt;
                    cout << endl << "Este cliente no existe, ¿desea crear un nuevo cliente?" << endl;
                    cout << " | 1. Si   | 2. No" << endl;
                    cin >> opt;
                    if(opt == 1){
                        Cliente c;
                        c.setNombre(name);
                        newClient(c);
                        cout << "Cliente agregado" << endl;
                        Cliente* srch = buscarCliente(c);
                        showInvent();
                        while(true){
                            string temp;
                            int base;
                            cin.ignore();
                            cout << "Ingrese el ID de la joya: ";
                            getline(cin, temp);
                            base = indexI(temp);
                            if(base == -1){
                                cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                                cin.get();
                            }else{
                                cout << left;
                                cout << setw(10) << "|  ID  |";
                                cout << setw(10) << "|  PRECIO  | ";
                                cout << setw(15) << "|  TIPO  | ";
                                cout << setw(15) << "|  FORMA  | ";
                                cout << "|  CANTIDAD  | " << endl << endl;
                                cout << inventario[base];
                                int cantidad;
                                cout << endl << "Defina la cantidad de piezas seleccionadas: "<< endl;
                                cin >> cantidad;
                                if(cantidad > inventario[base].getCantidad()){
                                    cout << " Falta de inventario para completar el pedido, esperar resurtido" << endl;
                                    cin.get();
                                    cin.get();
                                    break;
                                }

                                Joya ex;
                                ex.setNombre(temp);
                                inventario[base].cantidad = inventario[base].cantidad -cantidad;
                                ex.setTipo(inventario[base].getTipo());
                                ex.setForma(inventario[base].getForma());
                                ex.setPrecio(inventario[base].getPrecio()*cantidad);
                                ex.setCantidad(cantidad);

                                float pago;
                                float cambio;
                                string mdp;

                                cout << "El precio a pagar es: " << ex.getPrecio() << endl;
                                while(true){
                                    cin.ignore();
                                    cout << endl << "El dinero recibido es: ";
                                    cin >> pago;
                                    if(pago < inventario[base].getPrecio()){
                                            cout << "Pago insuficiente" << endl;
                                    }else{
                                        break;
                                    }
                                }
                                cin.ignore();
                                cout << "El metodo de pago es: " << endl;
                                getline(cin, mdp);

                                cambio = pago - ex.getPrecio();
                                Recibo* nuevo = new Recibo();
                                nuevo->adquirida = ex;
                                nuevo->setPago(pago);
                                nuevo->setCambio(cambio);
                                nuevo->metodoDP = mdp;
                                srch->cuentaPersonal.insertFront(nuevo);
                                cout << "Recibo creado con exito" << endl << endl;
                                cout << nuevo;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                    }else{
                        showInvent();
                        while(true){
                            string temp;
                            int base;
                            cin.ignore();
                            cout << "Ingrese el ID de la joya: ";
                            getline(cin, temp);
                            base = indexI(temp);
                            if(base == -1){
                                cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                                cin.get();
                            }else{
                                cout << left;
                                cout << setw(10) << "|  ID  |";
                                cout << setw(10) << "|  PRECIO  | ";
                                cout << setw(15) << "|  TIPO  | ";
                                cout << setw(15) << "|  FORMA  | ";
                                cout << "|  CANTIDAD  | " << endl << endl;
                                cout << inventario[base];
                                int cantidad;
                                cout << endl << "Defina la cantidad de piezas seleccionadas: "<< endl;
                                cin >> cantidad;
                                if(cantidad > inventario[base].getCantidad()){
                                    cout << " Falta de inventario para completar el pedido, esperar resurtido" << endl;
                                    cin.get();
                                    cin.get();
                                    break;
                                }

                                Joya ex;
                                ex.setNombre(temp);
                                inventario[base].cantidad = inventario[base].cantidad -cantidad;
                                ex.setTipo(inventario[base].getTipo());
                                ex.setForma(inventario[base].getForma());
                                ex.setPrecio(inventario[base].getPrecio()*cantidad);
                                ex.setCantidad(cantidad);

                                float pago;
                                float cambio;
                                string mdp;

                                cout << "El precio a pagar es: " << ex.getPrecio() << endl;
                                while(true){
                                    cout << endl << "El dinero recibido es: ";
                                    cin >> pago;
                                    if(pago < ex.getPrecio()){
                                            cout << "Pago insuficiente" << endl;
                                    }else{
                                        break;
                                    }
                                }
                                cin.ignore();
                                cout << "El metodo de pago es: " << endl;
                                getline(cin, mdp);

                                cambio = pago - ex.getPrecio();

                                Recibo* nuevo = new Recibo();
                                nuevo->adquirida = ex;
                                nuevo->setPago(pago);
                                nuevo->setCambio(cambio);
                                nuevo->metodoDP = mdp;

                                clientela[0].cuentaPersonal.insertFront(nuevo);
                                cout << "Recibo creado con exito" << endl << endl;
                                cout << nuevo;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                    }
                }else{
                    Cliente cl;
                    cl.setNombre(name);
                    Cliente* srch = buscarCliente(cl);
                    showInvent();
                    while(true){
                        string temp;
                        int base;
                        cout << "Ingrese el ID de la joya: ";
                        getline(cin, temp);
                        base = indexI(temp);
                        if(base == -1){
                            cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                            cin.get();
                        }else{
                            if(inventario[base].getCantidad() == 0){
                                cout << "Articulo agotado" << endl;
                                break;
                            }
                            cout << left;
                            cout << setw(10) << "|  ID  |";
                            cout << setw(10) << "|  PRECIO  | ";
                            cout << setw(15) << "|  TIPO  | ";
                            cout << setw(15) << "|  FORMA  | ";
                            cout << "|  CANTIDAD  | " << endl << endl;
                            cout << inventario[base];
                            int cantidad;
                            cout << endl << "Defina la cantidad de piezas seleccionadas: "<< endl;
                            cin >> cantidad;
                            if(cantidad > inventario[base].getCantidad()){
                                cout << " Falta de inventario para completar el pedido, esperar resurtido" << endl;
                                cin.get();
                                cin.get();
                                break;
                            }

                            Joya ex;
                            ex.setNombre(temp);
                            inventario[base].cantidad = inventario[base].cantidad -cantidad;
                            ex.setTipo(inventario[base].getTipo());
                            ex.setForma(inventario[base].getForma());
                            ex.setPrecio(inventario[base].getPrecio()*cantidad);
                            ex.setCantidad(cantidad);

                            float pago;
                            float cambio;
                            string mdp;

                            cout << "El precio a pagar es: " << ex.getPrecio() << endl;
                            while(true){
                                cout << endl << "El dinero recibido es: ";
                                cin >> pago;
                                if(pago < inventario[base].getPrecio()){
                                        cout << "Pago insuficiente" << endl;
                                }else{
                                    break;
                                }
                            }
                            cin.ignore();
                            cout << "El metodo de pago es: " << endl;
                            getline(cin, mdp);

                            cambio = pago - ex.getPrecio();

                            Recibo* nuevo = new Recibo();
                            nuevo->adquirida = ex;
                            nuevo->setPago(pago);
                            nuevo->setCambio(cambio);
                            nuevo->metodoDP = mdp;

                            srch->cuentaPersonal.insertFront(nuevo);
                            cout << "Recibo creado con exito" << endl << endl;
                            cout << nuevo;
                            cin.get();
                            cin.get();
                            break;
                        }
                    }
                }
            }else if(opcion == 2){
                while(true){
                system("cls");
                int clientOp;
                cout << " |   C L I E N T E   |" << endl << endl;
                cout << "1. Registrar | 2. Editar | 3. Eliminar | 4. Consultar | 5. Volver" << endl;
                cin >> clientOp;

                if(clientOp == 1){
                    cin.ignore();
                    string temp;
                    Cliente c;
                    cout << "Registrar nombre de nuevo cliente: ";
                    getline(cin, temp);
                    c.setNombre(temp);
                    newClient(c);
                }else if(clientOp == 2){
                    showClient();
                    string temp;
                    cin.ignore();
                    cout << endl << "Ingrese el nombre del cliente a editar" << endl;
                    getline(cin, temp);
                    Cliente c;
                    c.setNombre(temp);
                    Cliente* point;
                    point = buscarCliente(c);
                    cout << point->getNombre();
                    while(true){
                        int opc;
                        cout << "¿Que desea editar" << endl << "1. NOMBRE | 2. ORDENAR RECIBOS | 3. salir" << endl;
                        cin >> opc;
                        if(opc == 1){
                            string sample;
                            cin.ignore();
                            cout << "Escribir el nuevo nombre" << endl << endl;
                            getline(cin, sample);
                            point->setNombre(sample);
                        }else if(opc == 2){
                            point->cuentaPersonal.bubble();
                        }else if(opc == 3){
                            break;
                        }else{
                            cout << "Opcion no valida" << endl;
                        }
                    }
                }else if(clientOp == 3){
                    cin.ignore();
                    string temp;
                    int base;
                    cout << "Ingrese nombre de cliente a eliminar: " << endl;
                    getline(cin, temp);
                    base = indexC(temp);
                    if(base >= 0){
                        cout << "Cliente eliminado con exito!" << endl;
                        cin.get();
                        clientela.erase(clientela.begin()+base);
                    }
                }else if(clientOp == 4){
                    showClient();
                    int opt;
                    cout << "¿Ver registro de algun cliente?" << endl;
                    cout << "1. Si | 2. No" << endl;
                    cin >> opt;

                    if(opt == 1){
                        string temp;
                        int base;
                        cin.ignore();
                        cout << "Ingrese el nombre del cliente del que quieres ver el registro" << endl;
                        getline(cin, temp);
                        base = indexC(temp);
                        if(base == -1){
                            cout << "El cliente no se encuentra en la base de datos" << endl;
                        }else{
                            int op;
                            int adv = 0;
                            clientela[base].cuentaPersonal.display(adv);
                            cin.get();
                            cout << endl << "¿Ver el siguiente?" << endl << "1. SI 2. NO";
                            cin >> op;
                            if(op == 2){
                                break;
                            }else{
                                while(true){
                                    int a;
                                    adv++;
                                    clientela[base].cuentaPersonal.display(adv);
                                    cout << endl << "¿Ver siguiente?" << endl << "1. SI 2. NO" << endl;
                                    cin >> a;
                                    if(a == 2){
                                        break;
                                    }
                                }
                            }
                        }
                    }else{
                        break;
                    }

                }else if(clientOp == 5){
                    break;
                }else{
                    cout << "Opcion no valida" << endl << endl;
                }
            }
            }else if(opcion == 3){
            while(true){
                system("cls");
                int itemOp;
                cout << " |   I N V E N T A R I O   |" << endl << endl;
                cout << "1. Registrar | 2. Editar | 3. Eliminar | 4. Consultar | 5. Volver" << endl;
                cin >> itemOp;
                if(itemOp == 1){
                    Joya j;
                    string temp;
                    cin >> j;
                    temp = inventoryID(j);
                    j.setNombre(temp);
                    itemAdd(j);
                }else if(itemOp == 2){
                    cin.ignore();
                    string temp;
                    int base;
                    cout << "Ingrese el ID: ";
                    getline(cin, temp);
                    base = indexI(temp);
                    if(base == -1){
                        cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                        cin.get();
                    }else{
                        while(true){
                            int editOp;
                            cout << left;
                            cout << setw(10) << "|  ID  |";
                            cout << setw(10) << "|  PRECIO  | ";
                            cout << setw(15) << "|  TIPO  | ";
                            cout << setw(15) << "|  FORMA  | ";
                            cout << "|  CANTIDAD  | " << endl << endl;

                            cout << inventario[base];
                            cout << endl << endl << "| 1. Editar precio | 2. Volver" << endl;
                            cin >> editOp;
                            if(editOp == 1){
                                    float temp;
                                    cout << "Insertar nuevo precio: " << endl;
                                    cin >> temp;
                                    inventario[base].setPrecio(temp);
                                    cout << "Precio actualizado!" << endl;
                                    break;

                            }else if(editOp == 2){
                                break;
                            }
                        }
                    }
                }else if(itemOp == 3){
                    cin.ignore();
                    string temp;
                    int base;
                    cout << "ID del objeto a eliminar:  ";
                    getline(cin, temp);
                    base = indexI(temp);
                    if(base >= 0){
                        inventario.erase(inventario.begin()+ base);
                        cout << "Objeto eliminado con exito!" << endl;
                        cin.get();
                    }
                }else if(itemOp == 4){
                    showInvent();
                    cin.get();
                    cin.get();
                }else if(itemOp == 5){
                    break;
                }else{
                    cout << "Opcion no valida" << endl << endl;
                }

            }
            }else if(opcion == 4){
            while(true){
                system("cls");
                int userOp;
                cout << " |   U S U A R I O   | " << endl << endl;
                cout << "Nombre: " << u->getNombre() << endl;
                cout << u->getTipoTxt() << endl << endl;
                cout << " 1. Editar nombre | 2. Editar contraseña | 3. Editar ambos | 4. Volver" << endl;
                cin >> userOp;
                if(userOp == 1){
                    cin.ignore();
                    string temp;
                    cout << "Nombre actual:" << u->getNombre() << endl;
                    cout << "Ingrese el nuevo nombre: " << endl;
                    getline(cin, temp);
                    u->setNombre(temp);
                }else if(userOp == 2){
                    string temp;
                    cin.ignore();
                    cout << "Ingrese la nueva contraseña: " << endl;
                    getline(cin, temp);
                    u->setPassword(temp);
                }else if(userOp == 3){
                    cin.ignore();
                    string tempOne, tempTwo;
                    cout << "Ingrese el nuevo nombre: " << endl;
                    getline(cin, tempOne);
                    u->setNombre(tempOne);
                    cout << "Ingrese la nueva contraseña: " << endl;
                    getline(cin, tempTwo);
                    u->setPassword(tempTwo);
                }else if(userOp == 4){
                    break;
                }else{
                    cout << "Opcion invalida" << endl;
                }
            }

            }else if(opcion == 5){
                while(true){
                system("cls");
                int countOp;
                cout << " |    C U E N T A S    |" << endl << endl;
                showUsers();
                cout << endl << " 1. Registrar   |  2. Eliminar  | 3. Editar cuenta | 4. Volver" << endl;
                cin >> countOp;
                if(countOp == 1){
                    Usuario temp;
                    cin >> temp;
                    users.push_back(temp);
                }else if(countOp == 2){
                    cin.ignore();
                    string temp;
                    int base;
                    cout << "Nombre de la cuenta a eliminar:  ";
                    getline(cin, temp);
                    base = indexU(temp);
                    if(base > 0){
                        users.erase(users.begin()+ base);
                        cout << "Usuario eliminado con exito!" << endl;
                        cin.get();
                    }else if(base == 0){
                        cout << "No se puede eliminar la cuenta principal" << endl;
                    }
                }else if(countOp == 3){
                    showUsers();
                    string c;
                    int d;
                    cin.ignore();
                    cout << endl << "Elige cuenta a editar " << endl;
                    getline(cin, c);
                    d = indexU(c);
                    while(true){
                        int userOp;
                        cout << "Nombre: " << users[d].getNombre() << endl;
                        cout << users[d].getTipoTxt() << endl << endl;
                        cout << " 1. Editar nombre | 2. Editar contraseña | 3. Editar ambos | 4. Editar tipo | 5. Volver" << endl;
                        cin >> userOp;
                        if(userOp == 1){
                            cin.ignore();
                            string temp;
                            cout << "Nombre actual:" << u->getNombre() << endl;
                            cout << "Ingrese el nuevo nombre: " << endl;
                            getline(cin, temp);
                            users[d].setNombre(temp);
                        }else if(userOp == 2){
                            cin.ignore();
                            string temp;
                            cout << "Ingrese la nueva contraseña: " << endl;
                            getline(cin, temp);
                            users[d].setPassword(temp);
                        }else if(userOp == 3){
                            cin.ignore();
                            string tempOne, tempTwo;
                            cout << "Ingrese el nuevo nombre: " << endl;
                            getline(cin, tempOne);
                            users[d].setNombre(tempOne);
                            cout << "Ingrese la nueva contraseña: " << endl;
                            getline(cin, tempTwo);
                            users[d].setPassword(tempTwo);
                        }else if(userOp == 4){
                            if(users[d].getTipo() == 1){
                                users[d].setTipo(2);
                                cout << "¡Cambio de tipo realizado con exito!" << endl;
                            }else if(users[d].getTipo() == 2){
                                users[d].setTipo(1);
                                cout << endl << "¡Cambio de tipo realizado con exito!" << endl;
                            }else{
                                cout << "No se puede cambiar el tipo de usuario de esa cuenta." << endl;
                            }

                        }else if(userOp == 5){
                            break;
                        }else{
                            cout << "Opcion invalida" << endl;
                        }
                    }
                }else if(countOp == 4){
                    break;
                }else{

                }
            }
            }else if(opcion == 6){
                break;
            }else{
                cout << "Opcion no valida" << endl;
            }

        }
}

void GeneralManager::menuGerente(Usuario* u){
     while(true){
          system("cls");
            int opcion;
            cout << endl << right;
            cout << "     ----  M    E    N    U  ----     " << endl << endl;
            cout << "1. COMPRA  | 2. CLIENTE | 3. INVENTARIO " << endl;
            cout << "4. USUARIO | 5. CUENTAS | 6 SALIR" << endl;
            cin >> opcion;

            if(opcion == 1){
                  cin.ignore();
                string name;
                cout << "Nombre del cliente: ";
                getline(cin, name);
                int use;
                use = indexC(name);
                if(use == -1){
                    int opt;
                    cout << endl << "Este cliente no existe, ¿desea crear un nuevo cliente?" << endl;
                    cout << " | 1. Si   | 2. No" << endl;
                    cin >> opt;
                    if(opt == 1){
                        Cliente c;
                        c.setNombre(name);
                        newClient(c);
                        cout << "Cliente agregado" << endl;
                        Cliente* srch = buscarCliente(c);
                        showInvent();
                        while(true){
                            string temp;
                            int base;
                            cin.ignore();
                            cout << "Ingrese el ID de la joya: ";
                            getline(cin, temp);
                            base = indexI(temp);
                            if(base == -1){
                                cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                                cin.get();
                            }else{
                                cout << left;
                                cout << setw(10) << "|  ID  |";
                                cout << setw(10) << "|  PRECIO  | ";
                                cout << setw(15) << "|  TIPO  | ";
                                cout << setw(15) << "|  FORMA  | ";
                                cout << "|  CANTIDAD  | " << endl << endl;
                                cout << inventario[base];
                                int cantidad;
                                cout << endl << "Defina la cantidad de piezas seleccionadas: "<< endl;
                                cin >> cantidad;
                                if(cantidad > inventario[base].getCantidad()){
                                    cout << " Falta de inventario para completar el pedido, esperar resurtido" << endl;
                                    cin.get();
                                    cin.get();
                                    break;
                                }

                                Joya ex;
                                ex.setNombre(temp);
                                inventario[base].cantidad = inventario[base].cantidad -cantidad;
                                ex.setTipo(inventario[base].getTipo());
                                ex.setForma(inventario[base].getForma());
                                ex.setPrecio(inventario[base].getPrecio()*cantidad);
                                ex.setCantidad(cantidad);

                                float pago;
                                float cambio;
                                string mdp;

                                cout << "El precio a pagar es: " << ex.getPrecio() << endl;
                                while(true){
                                    cin.ignore();
                                    cout << endl << "El dinero recibido es: ";
                                    cin >> pago;
                                    if(pago < inventario[base].getPrecio()){
                                            cout << "Pago insuficiente" << endl;
                                    }else{
                                        break;
                                    }
                                }
                                cin.ignore();
                                cout << "El metodo de pago es: " << endl;
                                getline(cin, mdp);

                                cambio = pago - ex.getPrecio();
                                Recibo* nuevo = new Recibo();
                                nuevo->adquirida = ex;
                                nuevo->setPago(pago);
                                nuevo->setCambio(cambio);
                                nuevo->metodoDP = mdp;
                                srch->cuentaPersonal.insertFront(nuevo);
                                cout << "Recibo creado con exito" << endl << endl;
                                cout << nuevo;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                    }else{
                        showInvent();
                        while(true){
                            string temp;
                            int base;
                            cin.ignore();
                            cout << "Ingrese el ID de la joya: ";
                            getline(cin, temp);
                            base = indexI(temp);
                            if(base == -1){
                                cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                                cin.get();
                            }else{
                                cout << left;
                                cout << setw(10) << "|  ID  |";
                                cout << setw(10) << "|  PRECIO  | ";
                                cout << setw(15) << "|  TIPO  | ";
                                cout << setw(15) << "|  FORMA  | ";
                                cout << "|  CANTIDAD  | " << endl << endl;
                                cout << inventario[base];
                                int cantidad;
                                cout << endl << "Defina la cantidad de piezas seleccionadas: "<< endl;
                                cin >> cantidad;
                                if(cantidad > inventario[base].getCantidad()){
                                    cout << " Falta de inventario para completar el pedido, esperar resurtido" << endl;
                                    cin.get();
                                    cin.get();
                                    break;
                                }

                                Joya ex;
                                ex.setNombre(temp);
                                inventario[base].cantidad = inventario[base].cantidad -cantidad;
                                ex.setTipo(inventario[base].getTipo());
                                ex.setForma(inventario[base].getForma());
                                ex.setPrecio(inventario[base].getPrecio()*cantidad);
                                ex.setCantidad(cantidad);

                                float pago;
                                float cambio;
                                string mdp;

                                cout << "El precio a pagar es: " << ex.getPrecio() << endl;
                                while(true){
                                    cout << endl << "El dinero recibido es: ";
                                    cin >> pago;
                                    if(pago < ex.getPrecio()){
                                            cout << "Pago insuficiente" << endl;
                                    }else{
                                        break;
                                    }
                                }
                                cin.ignore();
                                cout << "El metodo de pago es: " << endl;
                                getline(cin, mdp);

                                cambio = pago - ex.getPrecio();

                                Recibo* nuevo = new Recibo();
                                nuevo->adquirida = ex;
                                nuevo->setPago(pago);
                                nuevo->setCambio(cambio);
                                nuevo->metodoDP = mdp;

                                clientela[0].cuentaPersonal.insertFront(nuevo);
                                cout << "Recibo creado con exito" << endl << endl;
                                cout << nuevo;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                    }
                }else{
                    Cliente cl;
                    cl.setNombre(name);
                    Cliente* srch = buscarCliente(cl);
                    showInvent();
                    while(true){
                        string temp;
                        int base;
                        cout << "Ingrese el ID de la joya: ";
                        getline(cin, temp);
                        base = indexI(temp);
                        if(base == -1){
                            cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                            cin.get();
                        }else{
                            if(inventario[base].getCantidad() == 0){
                                cout << "Articulo agotado" << endl;
                                break;
                            }
                            cout << left;
                            cout << setw(10) << "|  ID  |";
                            cout << setw(10) << "|  PRECIO  | ";
                            cout << setw(15) << "|  TIPO  | ";
                            cout << setw(15) << "|  FORMA  | ";
                            cout << "|  CANTIDAD  | " << endl << endl;
                            cout << inventario[base];
                            int cantidad;
                            cout << endl << "Defina la cantidad de piezas seleccionadas: "<< endl;
                            cin >> cantidad;
                            if(cantidad > inventario[base].getCantidad()){
                                cout << " Falta de inventario para completar el pedido, esperar resurtido" << endl;
                                cin.get();
                                cin.get();
                                break;
                            }

                            Joya ex;
                            ex.setNombre(temp);
                            inventario[base].cantidad = inventario[base].cantidad -cantidad;
                            ex.setTipo(inventario[base].getTipo());
                            ex.setForma(inventario[base].getForma());
                            ex.setPrecio(inventario[base].getPrecio()*cantidad);
                            ex.setCantidad(cantidad);

                            float pago;
                            float cambio;
                            string mdp;

                            cout << "El precio a pagar es: " << ex.getPrecio() << endl;
                            while(true){
                                cout << endl << "El dinero recibido es: ";
                                cin >> pago;
                                if(pago < inventario[base].getPrecio()){
                                        cout << "Pago insuficiente" << endl;
                                }else{
                                    break;
                                }
                            }
                            cin.ignore();
                            cout << "El metodo de pago es: " << endl;
                            getline(cin, mdp);

                            cambio = pago - ex.getPrecio();

                            Recibo* nuevo = new Recibo();
                            nuevo->adquirida = ex;
                            nuevo->setPago(pago);
                            nuevo->setCambio(cambio);
                            nuevo->metodoDP = mdp;

                            srch->cuentaPersonal.insertFront(nuevo);
                            cout << "Recibo creado con exito" << endl << endl;
                            cout << nuevo;
                            cin.get();
                            cin.get();
                            break;
                        }
                    }
                }
            }else if(opcion == 2){
                 while(true){
                    system("cls");
                    int clientOp;
                    cout << " |   C L I E N T E   |" << endl << endl;
                    cout << "1. Registrar | 2. Editar | 3. Eliminar | 4. Consultar | 5. Volver" << endl;
                    cin >> clientOp;

                    if(clientOp == 1){
                        cin.ignore();
                        string temp;
                        Cliente c;
                        cout << "Registrar nombre de nuevo cliente: ";
                        getline(cin, temp);
                        c.setNombre(temp);
                        newClient(c);
                    }else if(clientOp == 2){
                    showClient();
                    string temp;
                    cin.ignore();
                    cout << endl << "Ingrese el nombre del cliente a editar" << endl;
                    getline(cin, temp);
                    Cliente c;
                    c.setNombre(temp);
                    Cliente* point;
                    point = buscarCliente(c);
                    cout << point->getNombre();
                    while(true){
                        int opc;
                        cout << "¿Que desea editar" << endl << "1. NOMBRE | 2. ORDENAR RECIBOS | 3. salir" << endl;
                        cin >> opc;
                        if(opc == 1){
                            string sample;
                            cin.ignore();
                            cout << "Escribir el nuevo nombre" << endl << endl;
                            getline(cin, sample);
                            point->setNombre(sample);
                        }else if(opc == 2){
                            point->cuentaPersonal.bubble();
                        }else if(opc == 3){
                            break;
                        }else{
                            cout << "Opcion no valida" << endl;
                        }
                    }
                    }else if(clientOp == 3){
                        cin.ignore();
                        string temp;
                        int base;
                        cout << "Ingrese nombre de cliente a eliminar: " << endl;
                        getline(cin, temp);
                        base = indexC(temp);
                        if(base >= 0){
                            cout << "Cliente eliminado con exito!" << endl;
                            cin.get();
                            clientela.erase(clientela.begin()+base);
                        }
                    }else if(clientOp == 4){
                        showClient();
                        cin.get();
                        cin.get();
                    }else if(clientOp == 5){
                        break;
                    }else{
                        cout << "Opcion no valida" << endl << endl;
                    }
            }
            }else if(opcion == 3){
                 while(true){
                    system("cls");
                    int itemOp;
                    cout << " |   I N V E N T A R I O   |" << endl << endl;
                    cout << "1. Editar | 2. Eliminar | 3. Consultar | 4. Volver" << endl;
                    cin >> itemOp;
                    if(itemOp == 1){
                      cin.ignore();
                    string temp;
                    int base;
                    cout << "Ingrese el ID: ";
                    getline(cin, temp);
                    base = indexI(temp);
                    if(base == -1){
                        cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                        cin.get();
                        }else{
                            while(true){
                                int editOp;
                                cout << inventario[base];
                                cout << "| 1. Editar precio | 2. Volver" << endl;
                                cin >> editOp;
                                if(editOp == 1){
                                        float temp;
                                        cout << "Insertar nuevo precio: " << endl;
                                        cin >> temp;
                                        inventario[base].setPrecio(temp);
                                        cout << "Precio actualizado!" << endl;
                                        break;

                                }else if(editOp == 2){
                                    break;
                                }
                            }
                        }
                    }else if(itemOp == 2){
                        cin.ignore();
                        string temp;
                        int base;
                        cout << "ID del objeto a eliminar:  ";
                        getline(cin, temp);
                        base = indexI(temp);
                        if(base >= 0){
                            inventario.erase(inventario.begin()+ base);
                            cout << "Objeto eliminado con exito!" << endl;
                            cin.get();
                        }
                    }else if(itemOp == 3){
                        showInvent();
                        cin.get();
                        cin.get();
                    }else if(itemOp == 4){
                        break;
                    }else{
                        cout << "Opcion no valida" << endl << endl;
                    }
                }
            }else if(opcion == 4){
                while(true){
                    system("cls");
                    int userOp;
                    cout << " |   U S U A R I O   | " << endl << endl;
                    cout << "Nombre: " << u->getNombre() << endl;
                    cout << u->getTipoTxt() << endl << endl;
                    cout << " 1. Editar nombre | 2. Editar contraseña | 3. Editar ambos | 4. Volver" << endl;
                    cin >> userOp;
                    if(userOp == 1){
                        cin.ignore();
                        string temp;
                        cout << "Nombre actual:" << u->getNombre() << endl;
                        cout << "Ingrese el nuevo nombre: " << endl;
                        getline(cin, temp);
                        u->setNombre(temp);
                    }else if(userOp == 2){
                        string temp;
                        cout << "Ingrese la nueva contraseña: " << endl;
                        getline(cin, temp);
                        u->setPassword(temp);
                    }else if(userOp == 3){
                        cin.ignore();
                        string tempOne, tempTwo;
                        cout << "Ingrese el nuevo nombre: " << endl;
                        getline(cin, tempOne);
                        u->setNombre(tempOne);
                        cout << "Ingrese la nueva contraseña: " << endl;
                        getline(cin, tempTwo);
                        u->setPassword(tempTwo);
                    }else if(userOp == 4){
                        break;
                    }else{
                        cout << "Opcion invalida" << endl;
                    }
                }
            }else if(opcion == 5){
                int countOp;
                cout << " |    C U E N T A S    |" << endl << endl;
                showUsers();
                cout << endl << " 1. Registrar  | 2. Editar cuenta | 3. Volver" << endl;
                cin >> countOp;
                if(countOp == 1){
                    Usuario temp;
                    cin >> temp;
                    users.push_back(temp);
                }else if(countOp == 2){
                    showUsers();
                    string c;
                    int d;
                    cin.ignore();
                    cout << endl << "Elige cuenta a editar " << endl;
                    getline(cin, c);
                    d = indexU(c);
                    while(true){
                        int userOp;
                        cout << "Nombre: " << users[d].getNombre() << endl;
                        cout << users[d].getTipoTxt() << endl << endl;
                        cout << " 1. Editar nombre | 2. Editar contraseña | 3. Editar ambos | 4. Editar tipo | 5. Volver" << endl;
                        cin >> userOp;
                        if(userOp == 1){
                            cin.ignore();
                            string temp;
                            cout << "Nombre actual:" << u->getNombre() << endl;
                            cout << "Ingrese el nuevo nombre: " << endl;
                            getline(cin, temp);
                            users[d].setNombre(temp);
                        }else if(userOp == 2){
                            cin.ignore();
                            string temp;
                            cout << "Ingrese la nueva contraseña: " << endl;
                            getline(cin, temp);
                            users[d].setPassword(temp);
                        }else if(userOp == 3){
                            cin.ignore();
                            string tempOne, tempTwo;
                            cout << "Ingrese el nuevo nombre: " << endl;
                            getline(cin, tempOne);
                            users[d].setNombre(tempOne);
                            cout << "Ingrese la nueva contraseña: " << endl;
                            getline(cin, tempTwo);
                            users[d].setPassword(tempTwo);
                        }else if(userOp == 4){
                            if(users[d].getTipo() == 1){
                                users[d].setTipo(2);
                                cout << "¡Cambio de tipo realizado con exito!" << endl;
                            }else if(users[d].getTipo() == 2){
                                users[d].setTipo(1);
                                cout << "¡Cambio de tipo realizado con exito!" << endl;
                            }else{
                                cout << "No se puede cambiar el tipo de usuario de esa cuenta." << endl;
                            }

                        }else if(userOp == 5){
                            break;
                        }else{
                            cout << "Opcion invalida" << endl;
                        }
                    }
                }else if(countOp == 3){
                    break;
                }else{
                    cout << "Opcion no valida" << endl;
                }
            }else if(opcion == 6){
                break;
            }else{
                cout << "Opcion no valida" << endl;
            }

        }
}

void GeneralManager::menuTrabajador(Usuario* u){
    while(true){
          system("cls");
            int opcion;
            cout << endl << right;
            cout << "     ----  M    E    N    U  ----     " << endl << endl;
            cout << "1. COMPRA  | 2. CLIENTE | 3. INVENTARIO " << endl;
            cout << "4. USUARIO | 5. SALIR" << endl;
            cin >> opcion;

            if(opcion == 1){
                  cin.ignore();
                string name;
                cout << "Nombre del cliente: ";
                getline(cin, name);
                int use;
                use = indexC(name);
                if(use == -1){
                    int opt;
                    cout << endl << "Este cliente no existe, ¿desea crear un nuevo cliente?" << endl;
                    cout << " | 1. Si   | 2. No" << endl;
                    cin >> opt;
                    if(opt == 1){
                        Cliente c;
                        c.setNombre(name);
                        newClient(c);
                        cout << "Cliente agregado" << endl;
                        Cliente* srch = buscarCliente(c);
                        showInvent();
                        while(true){
                            string temp;
                            int base;
                            cin.ignore();
                            cout << "Ingrese el ID de la joya: ";
                            getline(cin, temp);
                            base = indexI(temp);
                            if(base == -1){
                                cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                                cin.get();
                            }else{
                                cout << left;
                                cout << setw(10) << "|  ID  |";
                                cout << setw(10) << "|  PRECIO  | ";
                                cout << setw(15) << "|  TIPO  | ";
                                cout << setw(15) << "|  FORMA  | ";
                                cout << "|  CANTIDAD  | " << endl << endl;
                                cout << inventario[base];
                                int cantidad;
                                cout << endl << "Defina la cantidad de piezas seleccionadas: "<< endl;
                                cin >> cantidad;
                                if(cantidad > inventario[base].getCantidad()){
                                    cout << " Falta de inventario para completar el pedido, esperar resurtido" << endl;
                                    cin.get();
                                    cin.get();
                                    break;
                                }

                                Joya ex;
                                ex.setNombre(temp);
                                inventario[base].cantidad = inventario[base].cantidad -cantidad;
                                ex.setTipo(inventario[base].getTipo());
                                ex.setForma(inventario[base].getForma());
                                ex.setPrecio(inventario[base].getPrecio()*cantidad);
                                ex.setCantidad(cantidad);

                                float pago;
                                float cambio;
                                string mdp;

                                cout << "El precio a pagar es: " << ex.getPrecio() << endl;
                                while(true){
                                    cin.ignore();
                                    cout << endl << "El dinero recibido es: ";
                                    cin >> pago;
                                    if(pago < inventario[base].getPrecio()){
                                            cout << "Pago insuficiente" << endl;
                                    }else{
                                        break;
                                    }
                                }
                                cin.ignore();
                                cout << "El metodo de pago es: " << endl;
                                getline(cin, mdp);

                                cambio = pago - ex.getPrecio();
                                Recibo* nuevo = new Recibo();
                                nuevo->adquirida = ex;
                                nuevo->setPago(pago);
                                nuevo->setCambio(cambio);
                                nuevo->metodoDP = mdp;
                                srch->cuentaPersonal.insertFront(nuevo);
                                cout << "Recibo creado con exito" << endl << endl;
                                cout << nuevo;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                    }else{
                        showInvent();
                        while(true){
                            string temp;
                            int base;
                            cin.ignore();
                            cout << "Ingrese el ID de la joya: ";
                            getline(cin, temp);
                            base = indexI(temp);
                            if(base == -1){
                                cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                                cin.get();
                            }else{
                                cout << left;
                                cout << setw(10) << "|  ID  |";
                                cout << setw(10) << "|  PRECIO  | ";
                                cout << setw(15) << "|  TIPO  | ";
                                cout << setw(15) << "|  FORMA  | ";
                                cout << "|  CANTIDAD  | " << endl << endl;
                                cout << inventario[base];
                                int cantidad;
                                cout << endl << "Defina la cantidad de piezas seleccionadas: "<< endl;
                                cin >> cantidad;
                                if(cantidad > inventario[base].getCantidad()){
                                    cout << " Falta de inventario para completar el pedido, esperar resurtido" << endl;
                                    cin.get();
                                    cin.get();
                                    break;
                                }

                                Joya ex;
                                ex.setNombre(temp);
                                inventario[base].cantidad = inventario[base].cantidad -cantidad;
                                ex.setTipo(inventario[base].getTipo());
                                ex.setForma(inventario[base].getForma());
                                ex.setPrecio(inventario[base].getPrecio()*cantidad);
                                ex.setCantidad(cantidad);

                                float pago;
                                float cambio;
                                string mdp;

                                cout << "El precio a pagar es: " << ex.getPrecio() << endl;
                                while(true){
                                    cout << endl << "El dinero recibido es: ";
                                    cin >> pago;
                                    if(pago < ex.getPrecio()){
                                            cout << "Pago insuficiente" << endl;
                                    }else{
                                        break;
                                    }
                                }
                                cin.ignore();
                                cout << "El metodo de pago es: " << endl;
                                getline(cin, mdp);

                                cambio = pago - ex.getPrecio();

                                Recibo* nuevo = new Recibo();
                                nuevo->adquirida = ex;
                                nuevo->setPago(pago);
                                nuevo->setCambio(cambio);
                                nuevo->metodoDP = mdp;

                                clientela[0].cuentaPersonal.insertFront(nuevo);
                                cout << "Recibo creado con exito" << endl << endl;
                                cout << nuevo;
                                cin.get();
                                cin.get();
                                break;
                            }
                        }
                    }
                }else{
                    Cliente cl;
                    cl.setNombre(name);
                    Cliente* srch = buscarCliente(cl);
                    showInvent();
                    while(true){
                        string temp;
                        int base;
                        cout << "Ingrese el ID de la joya: ";
                        getline(cin, temp);
                        base = indexI(temp);
                        if(base == -1){
                            cout << "La ID que buscas, no existe, ingrese una ID valida" << endl;
                            cin.get();
                        }else{
                            if(inventario[base].getCantidad() == 0){
                                cout << "Articulo agotado" << endl;
                                break;
                            }
                            cout << left;
                            cout << setw(10) << "|  ID  |";
                            cout << setw(10) << "|  PRECIO  | ";
                            cout << setw(15) << "|  TIPO  | ";
                            cout << setw(15) << "|  FORMA  | ";
                            cout << "|  CANTIDAD  | " << endl << endl;
                            cout << inventario[base];
                            int cantidad;
                            cout << endl << "Defina la cantidad de piezas seleccionadas: "<< endl;
                            cin >> cantidad;
                            if(cantidad > inventario[base].getCantidad()){
                                cout << " Falta de inventario para completar el pedido, esperar resurtido" << endl;
                                cin.get();
                                cin.get();
                                break;
                            }

                            Joya ex;
                            ex.setNombre(temp);
                            inventario[base].cantidad = inventario[base].cantidad -cantidad;
                            ex.setTipo(inventario[base].getTipo());
                            ex.setForma(inventario[base].getForma());
                            ex.setPrecio(inventario[base].getPrecio()*cantidad);
                            ex.setCantidad(cantidad);

                            float pago;
                            float cambio;
                            string mdp;

                            cout << "El precio a pagar es: " << ex.getPrecio() << endl;
                            while(true){
                                cout << endl << "El dinero recibido es: ";
                                cin >> pago;
                                if(pago < inventario[base].getPrecio()){
                                        cout << "Pago insuficiente" << endl;
                                }else{
                                    break;
                                }
                            }
                            cin.ignore();
                            cout << "El metodo de pago es: " << endl;
                            getline(cin, mdp);

                            cambio = pago - ex.getPrecio();

                            Recibo* nuevo = new Recibo();
                            nuevo->adquirida = ex;
                            nuevo->setPago(pago);
                            nuevo->setCambio(cambio);
                            nuevo->metodoDP = mdp;

                            srch->cuentaPersonal.insertFront(nuevo);
                            cout << "Recibo creado con exito" << endl << endl;
                            cout << nuevo;
                            cin.get();
                            cin.get();
                            break;
                        }
                    }
                }
            }else if(opcion == 2){
                while(true){
                    system("cls");
                    int clientOp;
                    cout << " |   C L I E N T E   |" << endl << endl;
                    cout << "1. Registrar | 2. Consultar | 3. Volver" << endl;
                    cin >> clientOp;

                    if(clientOp == 1){
                        cin.ignore();
                        string temp;
                        Cliente c;
                        cout << "Registrar nombre de nuevo cliente: ";
                        getline(cin, temp);
                        c.setNombre(temp);
                        newClient(c);
                    }else if(clientOp == 2){
                        showClient();
                        cin.get();
                        cin.get();
                    }else if(clientOp == 3){
                        break;
                    }else{
                        cout << "Opcion no valida" << endl << endl;
                   }
                }
            }else if(opcion == 3){
                while(true){
                    system("cls");
                    int itemOp;
                    cout << " |   I N V E N T A R I O   |" << endl << endl;
                    cout << "1. Consultar | 2. Volver" << endl;
                    cin >> itemOp;
                    if(itemOp == 1){
                        showInvent();
                        cin.get();
                        cin.get();
                    }else if(itemOp == 2){
                        break;
                    }else{
                        cout << "Opcion no valida" << endl << endl;
                    }
                }
            }else if(opcion == 4){
                while(true){
                    system("cls");
                    int userOp;
                    cout << " |   U S U A R I O   | " << endl << endl;
                    cout << "Nombre: " << u->getNombre() << endl;
                    cout << u->getTipoTxt() << endl << endl;
                    cout << " 1. Editar nombre | 2. Editar contraseña | 3. Editar ambos | 4. Volver" << endl;
                    cin >> userOp;
                    if(userOp == 1){
                        cin.ignore();
                        string temp;
                        cout << "Nombre actual:" << u->getNombre() << endl;
                        cout << "Ingrese el nuevo nombre: " << endl;
                        getline(cin, temp);
                        u->setNombre(temp);
                    }else if(userOp == 2){
                        string temp;
                        cout << "Ingrese la nueva contraseña: " << endl;
                        getline(cin, temp);
                        u->setPassword(temp);
                    }else if(userOp == 3){
                        cin.ignore();
                        string tempOne, tempTwo;
                        cout << "Ingrese el nuevo nombre: " << endl;
                        getline(cin, tempOne);
                        u->setNombre(tempOne);
                        cout << "Ingrese la nueva contraseña: " << endl;
                        getline(cin, tempTwo);
                        u->setPassword(tempTwo);
                    }else if(userOp == 4){
                        break;
                    }else{
                        cout << "Opcion invalida" << endl;
                    }
                }
            }else if(opcion == 5){
                break;
            }else{
                cout << "Opcion no valida" << endl;
            }

        }
}


void GeneralManager::respaldar(){

    ofstream archivoU("users.txt");
    if(archivoU.is_open()){
        for(size_t i = 0; i < users.size(); i++){
             Usuario &u = users[i];
             archivoU << u.getNombre() << endl;
             archivoU << u.getTipo() << endl;
             archivoU << u.getPassword() << endl;
        }
    }
    archivoU.close();

    ofstream archivoI("inventory.txt");
    if(archivoI.is_open()){
        for(size_t i = 0; i < inventario.size(); i++){
             Joya &j = inventario[i];
             archivoI << j.getNombre() << endl;
             archivoI << j.getTipo() << endl;
             archivoI << j.getForma() << endl;
             archivoI << j.getCantidad() << endl;
             archivoI << j.getPrecio() << endl;
        }
    }
    archivoI.close();

    ofstream archivoC("client.txt");
    if(archivoC.is_open()){
        for(size_t i = 0; i < clientela.size(); i++){
             Cliente &c = clientela[i];
             archivoC << c.getNombre() << endl;
             c.respaldar_Recibos();
        }
    }
    archivoC.close();
}

void GeneralManager::recuperarUser(){
    ifstream archivo("users.txt");
    if(archivo.is_open()){

        string temporal;
        int inTemporal;

        while(true){
            Usuario u;
            getline(archivo, temporal);
            u.setNombre(temporal);
            if(archivo.eof()){
                break;
            }
            getline(archivo, temporal);
            inTemporal = stoi (temporal);
            u.setTipo(inTemporal);
            getline(archivo, temporal);
            u.setPassword(temporal);

            userGenerator(u);

        }
    }
    archivo.close();
}

void GeneralManager::recuperarInvent(){
    ifstream archivo("inventory.txt");
    if(archivo.is_open()){

        string temporal;
        int inTemporal;
        float floaTemporal;

        while(true){
            Joya j;
            getline(archivo, temporal);
            j.setNombre(temporal);
            if(archivo.eof()){
                break;
            }
            getline(archivo, temporal);
            j.setTipo(temporal);

            getline(archivo, temporal);
            j.setForma(temporal);

            getline(archivo, temporal);
            inTemporal = stoi (temporal);
            j.setCantidad(inTemporal);

            getline(archivo, temporal);
            floaTemporal = stof (temporal);
            j.setPrecio(floaTemporal);

            itemAdd(j);

        }
    }
    archivo.close();
}


void GeneralManager::recuperarClient(){

    ifstream archivo("client.txt");
    if(archivo.is_open()){

        string temporal;

        while(true){
            Cliente c;
            getline(archivo, temporal);
            c.setNombre(temporal);
            if(archivo.eof()){
                break;
            }

            c.recuperar_Recibos();
            newClient(c);

        }
    }
    archivo.close();
}


