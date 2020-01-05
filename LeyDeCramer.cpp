//
// Created by TheusZero and Eseck for on NeoTel Companny 04-01-2020.
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

//Declaraciones de Estructuras
typedef struct dosXdos{
    float x;
    float y;
    float r;
    float X;
    float Y;
    float R;
    float ResultadoX;
    float ResultadoY;
}D;

//Declaraciones de Funciones

//Funciones para Resolver un sistema 2X2
void Insertar(D* X);
void Desarrollo(D* X);
void ImprimirResultados(D* X);

int main() {
    D* ejercicio = new D;
    Insertar(ejercicio);
    Desarrollo(ejercicio);
    ImprimirResultados(ejercicio);
    delete(ejercicio);
    return 0;
}

void Insertar(D* Ejercicio){
    float x,y,r,X,Y,R;
    cout << "Ingrese el valor que acompañara al X para la primera ecuacion  ";
    cin >> x;
    cout << "Ingrese el valor que acompañara al Y para la primera ecuacion ";
    cin >> y;
    cout << "Ingrese el valor de la ecuacion ";
    cin >> r;
    cout << "Ingrese el valor que acompañara al X para la segunda ecuacion ";
    cin >> X;
    cout << "Ingrese el valor que acompañara al Y para la segunda ecuacion ";
    cin >> Y;
    cout << "Ingrese el valor de la segunda ecuacion ";
    cin >> R;
    Ejercicio->x=x;
    Ejercicio->y=y;
    Ejercicio->r=r;
    Ejercicio->X=X;
    Ejercicio->Y=Y;
    Ejercicio->R=R;
}

void Desarrollo(D* Ejercicio){
    //arrays para ordenar los valores
    float uno[3] = {Ejercicio->x,Ejercicio->y,Ejercicio->r};
    float dos[3] = {Ejercicio->X,Ejercicio->Y,Ejercicio->R};
    //Determinante Sistema.
    float determinanteSistema = (uno[0] * dos[1])-(uno[1] * dos[0]);
    cout<<determinanteSistema<<endl;
    //Determinante de la X.
    float determinanteX = (uno[2] * dos[1])-(dos[2] * uno[1]);
    cout<<determinanteX<<endl;
    //Determinante de la Y.
    float determianteY = (uno[0] * dos[2]) - (uno[2] * dos[0]);
    cout<<determianteY<<endl;
    //Division de los Coeficientes
    float ValorX = (determinanteX/determinanteSistema);
    float ValorY = (determianteY/determinanteSistema);
    float Resultado[2] = {ValorX,ValorY};
    Ejercicio->ResultadoX=Resultado[0];
    Ejercicio->ResultadoY=Resultado[1];

}

void ImprimirResultados(D* Ejercicio){
    float resultado[2] = {Ejercicio->ResultadoX,Ejercicio->ResultadoY};
    cout << "el programa ha terminando de operar, los resultados fueron: "<< endl;
    cout << "(" << resultado[0] << "," << resultado[1] << ")" << endl;
    cout << "Gracias por preferir NeoTel Companny" << endl;
}
