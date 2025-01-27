#include "Registro.h"

Registro::Registro()
{

}

Registro::~Registro()
{
    //dtor
}


void Registro::insertFront(Recibo* r){

    if(head==NULL){
         head = r;
    }else{
            r->next = head;
            head = r;
    }
}

void Registro::deleteFront(){
    if(head == NULL){
        cout << "Nothing to delete" << endl;
        return;
    }
    Recibo *temp = head;
    head = head->next;
    delete temp;

}

void Registro::display(int v){
    Recibo *temp = head;
    for(int i = 0; i < v; i++){
        temp = temp->next;
    }
    cout << *temp;

}

int Registro::tam(){

    Recibo *temp = head;
    int cont = 0;

    while(temp != NULL){
        temp = temp->next;
        cont ++;
    }
    return cont;
}

void Registro::bubble(){

    int cont = tam();
    int laps = cont;
    do{
        do{
            Recibo *presorted = head;
            Recibo *sorted = head->next;

            for(int i = 1; i < cont; i++){
                if(presorted->adquirida.getCantidad() > sorted->adquirida.getCantidad()){
                    swap(presorted->adquirida.cantidad, sorted->adquirida.cantidad);
                }
                presorted = presorted->next;
                sorted = sorted->next;
                if(sorted == nullptr){
                    break;
                }
            }
            laps --;
        }while(laps != 0);
        break;
    }while(true);
}


