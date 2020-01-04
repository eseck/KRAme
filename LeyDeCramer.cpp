//
// Created by TheusZero on 04-01-2020.
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
    float determinanteSistema;
    float determinanteX;
    float determianteY;
    float Resultado;
}D;

//Declaraciones de Funciones

//Funciones para Resolver un sistema 2X2
void Insertar(D* X);
void DetSistemaDos (float x, float y,float r,float X, float Y,float R); //Determinante Sistema.
void DetXDos(float x, float y,float r,float X, float Y,float R); //Determinante de la X.
void DetYDos(float x, float y,float r,float X, float Y,float R); //Determinante de la Y.
void DivCoefDos(float determinanteX, float determinanteSistema); //Division de los Coeficientes
void ImprimirResultados(float Resultado);


int main() {
    return 0;
}

void Insertar(D* Ejercicio){
    float x,y,r,X,Y,R;
    cout << "Ingrese el valor de X para la primera ecuacion";
    cin >> x;
    cout << "Ingrese el valor de Y para la primera ecuacion";
    cin >> y;
    cout << "Ingrese el valor de la ecuacion";
    cin >> r;
    cout << "Ingrese el valor de X para la segunda ecuacion";
    cin >> X;
    cout << "Ingrese el valor de Y para la segunda ecuacion";
    cin >> Y;
    cout << "Ingrese el valor de la segunda ecuacion";
    cin >> R;



    /*
    cout <<"Nombre: ";
    cin>>name;cout<<"Rut:";
    cin>>rut;cout<<"Numero: ";
    cin>>number;cout<< "Edad: ";
    cin>>edad;X->name=name;
    X->edad=edad;
    X->number=number;
    X->rut=rut;*/
}

void DetSistemaDos (float x, float y,float r,float X, float Y,float R){
    //Determinante Sistema.
    float uno[2] = {x,y};
    float dos[2] = {X,Y};
    float semiUno = uno[0] * dos[1];
    float semiDos = uno[1] * dos[0];
    float determinanteSistema = semiUno - semiDos;
    cout << determinanteSistema;
}

void DetXDos(float x, float y,float r,float X, float Y,float R){
    //Determinante de la X.
    float uno[2] = {r,y};
    float dos[2] = {R,Y};
    float semiUno = uno[0] * dos[1];
    float semiDos = uno[1] * dos[0];
    float determinanteX = semiUno - semiDos;
    cout << determinanteX;
}

void DetYDos(float x, float y,float r,float X, float Y,float R){
    //Determinante de la Y.
    float uno[2] = {x,r};
    float dos[2] = {X,R};
    float semiUno = uno[0] * dos[1];
    float semiDos = uno[1] * dos[0];
    float determianteY = semiUno - semiDos;
    cout << determianteY;
}

void DivCoefDos(float determinanteX, float determinanteSistema){
    //Division de los Coeficientes
    float ValorX = (determinanteX/determinanteSistema);
    float ValorY = (determinanteX/determinanteSistema);
    float Resultado[2] = {ValorX,ValorY};
    cout << ValorX << "," << ValorY;
}

void ImprimirResultados(float Resultado){
    cout << "el programa ha terminando de operar, los resultados fueron: "<< endl;
    cout << "(" << Resultado << "," << ")" << endl;
    cout << "Gracias por preferir NeoTel Companny" << endl;
}
//wena wena geente//
//wewen wen wue wueeeee buan buan buooooo tutarariruta tutararitibirurirubi//