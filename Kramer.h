#include <iostream>
#include <string>
using namespace std;
typedef struct dosXdos{
    float x,y,r,X,Y,R;
    float ResultadoX;
    float ResultadoY;
}D;
typedef struct tresXtres{
    float x,y,z,r,X,Y,Z,R,aX,aY,aZ,aR;
    float ResultadoX;
    float ResultadoY;
    float ResultadoZ;
}T;
typedef struct cuatroXcuatro{
    float x,y,z,w,r,X,Y,Z,W,R,aX,aY,aZ,aW,aR,ax,ay,az,aw,ar;
    float DetSistema;
    float DetX;
    float DetY;
    float DetZ;
    float DetW;
}C;
void InsertarDos(D* Ejercicio);
void DesarrolloDos(D* Ejercicio);
//Funcion para Resolver un sistema 3x3
void InsertarTres(T* Ejercicio);
void DesarrolloTres(T* Ejercicio);
//Funcion para Resolver un sistema 4x4
void InsertarCuatro(C* Ejercicio);
void DesarrolloCuatroSistema(C* Ejercicio);
void DesarrolloCuatroX(C* Ejercicio);
void DesarrolloCuatroY(C* Ejercicio);
void DesarrolloCuatroZ(C* Ejercicio);
void DesarrolloCuatroW(C* Ejercicio);
void Imprimir(C* Ejercicio);
