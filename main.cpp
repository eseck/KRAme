#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

typedef struct persona{
    string name;
    int edad;
    string rut;
    int number;
}P;

int main(){
    P* Yo = new P;

    delete(Yo);
    return 0;
}
void imprimir(P X){
    cout <<"Nombre: "<< X.name<<endl;
    cout<< "Edad: "<< X.edad<<endl;
    cout<<"Rut:" << X.rut<<endl;
    cout<<"Numero: "<< X.number<<endl;
}
void insertar(P* X){
    string name, rut;
    int number,edad;
    cout <<"Nombre: ";
    cin>>name;
    cout<<"Rut:";
    cin>>rut;
    cout<<"Numero: ";
    cin>>number;
    cout<< "Edad: ";
    cin>>edad;
    X->name=name;
    X->edad=edad;
    X->number=number;
    X->rut=rut;
}

