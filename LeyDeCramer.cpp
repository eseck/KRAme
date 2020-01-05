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
typedef struct tresXtres{
    float x;
    float y;
    float z;
    float r;
    float X;
    float Y;
    float Z;
    float R;
    float aX;
    float aY;
    float aZ;
    float aR;
    float ResultadoX;
    float ResultadoY;
    float ResultadoZ;
}T;
//Declaraciones de Funciones
//Funciones para Resolver un sistema 2X2
void InsertarDos(D* X);
void DesarrolloDos(D* X);
void ImprimirResultadosDos(D* X);
//Funcion para Resolver un sistema 3x3
void InsertarTres(T* Ejercicio);
void DesarrolloTres(T* X);
void ImprimirResultadosTres(T* X);
//Main
int main() {
    int Tipo;
    cout << "Bienvenido a la Calculadora de matrices de NeoTel Companny."<<endl;
    D* ejercicio = new D;
    do {
        cout << "Por favor, elija que tipo de matriz planea usar.";
        cin >> Tipo;
        switch(Tipo) {
            case 1:
                // Desarrollo para un 2x2
                InsertarDos(ejercicio);
                DesarrolloDos(ejercicio);
                ImprimirResultadosDos(ejercicio);
                delete(ejercicio);
                break;
            case 2:
                InsertarTres();
                DesarrolloTres(ejercicio);
                ImprimirResultadosTres(ejercicio);
                break;
            case 3:
                cout << "Gracias por preferir nuestra Calculadora. Hasta pronto!!";
                break;
        }
    }
    while(Tipo != 4);
    return 0;
}
//Funciones2X2
void InsertarDos(D* Ejercicio){
    float x,y,r,X,Y,R;
    cout << "Ingrese el valor que acompañara al X para la primera ecuacion"<<endl;
    cin >> x;
    cout << "Ingrese el valor que acompañara al Y para la primera ecuacion"<<endl;
    cin >> y;
    cout << "Ingrese el valor de la ecuacion"<<endl;
    cin >> r;
    cout << "Ingrese el valor que acompañara al X para la segunda ecuacion"<<endl;
    cin >> X;
    cout << "Ingrese el valor que acompañara al Y para la segunda ecuacion"<<endl;
    cin >> Y;
    cout << "Ingrese el valor de la segunda ecuacion"<<endl;
    cin >> R;
    Ejercicio->x=x;
    Ejercicio->y=y;
    Ejercicio->r=r;
    Ejercicio->X=X;
    Ejercicio->Y=Y;
    Ejercicio->R=R;
}
void DesarrolloDos(D* Ejercicio){
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
void ImprimirResultadosDos(D* Ejercicio){
    float resultado[2] = {Ejercicio->ResultadoX,Ejercicio->ResultadoY};
    cout << "el programa ha terminando de operar, los resultados fueron: "<< endl;
    cout << "(" << resultado[0] << "," << resultado[1] << ")" << endl;
    cout << endl << endl;
}
//Funciones3X3
void InsertarTres(T* Ejercicio) {
    float x,y,z,r,X,Y,Z,R,aX,aY,aZ,aR;
    cout << "Ingrese el valor que acompañara al X para la primera ecuacion"<<endl;
    cin >> x;
    cout << "Ingrese el valor que acompañara al Y para la primera ecuacion"<<endl;
    cin >> y;
    cout << "Ingrese el valor que acompañara al Z para la primera ecuacion"<<endl;
    cin >> z;
    cout << "Ingrese el valor de la ecuacion"<<endl;
    cin >> r;
    cout << "Ingrese el valor que acompañara al X para la segunda ecuacion"<<endl;
    cin >> X;
    cout << "Ingrese el valor que acompañara al Y para la segunda ecuacion"<<endl;
    cin >> Y;
    cout << "Ingrese el valor que acompañara al Z para la segunda ecuacion"<<endl;
    cin >> Z;
    cout << "Ingrese el valor de la segunda ecuacion"<<endl;
    cin >> R;
    cout << "Ingrese el valor que acompañara al X para la tercera ecuacion"<<endl;
    cin >> aX;
    cout << "Ingrese el valor que acompañara al Y para la tercera ecuacion"<<endl;
    cin >> aY;
    cout << "Ingrese el valor que acompañara al Z para la tercera ecuacion"<<endl;
    cin >> aZ;
    cout << "Ingrese el valor de la tercera ecuacion"<<endl;
    cin >> aR;
    Ejercicio->z=z;
    Ejercicio->x=x;
    Ejercicio->y=y;
    Ejercicio->r=r;
    Ejercicio->Z=Z;
    Ejercicio->X=X;
    Ejercicio->Y=Y;
    Ejercicio->R=R;
    Ejercicio->aZ=aZ;
    Ejercicio->aX=aX;
    Ejercicio->aY=aY;
    Ejercicio->aR=aR;
}
void DesarrolloTres(T* Ejercicio){
    float uno[4] = {Ejercicio->x, Ejercicio->y, Ejercicio->z, Ejercicio->r};
    float dos[4] = {Ejercicio->X, Ejercicio->Y, Ejercicio->Z, Ejercicio->R};
    float tres[4] = {Ejercicio->aX, Ejercicio->aY, Ejercicio->aZ, Ejercicio->aR};
    //determinante Sistema
    float DeterminanteSistemaA =
            (uno[0] * dos[1] * tres[2]) + (dos[0] * tres[1] * uno[2]) + (tres[0] * uno[1] * dos[2]);
    float DeterminanteSistemaB =
            (uno[2] * dos[1] * tres[0]) + (dos[2] * tres[1] * uno[0]) + (tres[2] * uno[1] * dos[1]);
    float DeterminanteSistema = DeterminanteSistemaA - DeterminanteSistemaB;
    //Determinante X
    //Determinante Y
    //Determinante Z
}