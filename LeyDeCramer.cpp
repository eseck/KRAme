#include <iostream>
#include "Kramer.h"
using namespace std;
//Declaraciones de Estructuras
// cuando colocamos un string en el main o las funciones insertar,se ejecuta una sola linea de cout infinitamente
int main() {
    int Tipo;
    D* ejercicioDos = new D;
    T* ejercicioTres = new T;
    C* ejercicioCuatro =  new C;
    cout << "Bienvenido a la Calculadora de matrices de NeoTel Companny."<<endl;
    do {
        cout << "Para elijir que tipo de matriz planea usar,ingrese el numero de la opcion"<<endl<<"opcion 1) matriz 2x2"<<endl;
        cout <<"opcion 2) matrix 3x3"<<endl<<"opcion 3) matrix 4x4"<<endl<<"Introducir cualquier otro caracter distintos a las opciones terminara el programa.";
        cin >> Tipo;
        switch(Tipo) {
            case 1:
                // Desarrollo para un 2x2
                InsertarDos(ejercicioDos);
                DesarrolloDos(ejercicioDos);
                break;
            case 2:
                InsertarTres(ejercicioTres);
                DesarrolloTres(ejercicioTres);
                break;
            case 3:
                InsertarCuatro(ejercicioCuatro);
                DesarrolloCuatroSistema(ejercicioCuatro);
                DesarrolloCuatroX(ejercicioCuatro);
                DesarrolloCuatroY(ejercicioCuatro);
                DesarrolloCuatroZ(ejercicioCuatro);
                DesarrolloCuatroW(ejercicioCuatro);
                Imprimir(ejercicioCuatro);
                break;

            case 4:
                cout << "Gracias por preferir nuestra Calculadora. Hasta pronto!!";
                break;
            default:
                cout << "Gracias por preferir nuestra Calculadora. Hasta pronto!!";
                Tipo= 4;
                break;
        }
        continue;
    }
    while(Tipo != 4);
    return 0;
}