//
// Created by TheusZero and Eseck for on NeoTel Companny 04-01-2020.
//
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
//Declaraciones de Estructuras
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
//Declaraciones de Funciones
//Funciones para Resolver un sistema 2x2
void InsertarDos(D* X);
void DesarrolloDos(D* X);
//Funcion para Resolver un sistema 3x3
void InsertarTres(T* X);
void DesarrolloTres(T* X);
//Funcion para Resolver un sistema 4x4
void InsertarCuatro(C* X);
void DesarrolloCuatroSistema(C* X);
void DesarrolloCuatroX(C* Ejercicio);
void DesarrolloCuatroY(C* Ejercicio);
void DesarrolloCuatroZ(C* Ejercicio);
void DesarrolloCuatroW(C* Ejercicio);
void Imprimir(C* Ejercicio);
//Main
// cuando colocamos un string en el main o las funciones insertar,se ejecuta una sola linea de cout infinitamente
int main() {
    int Tipo;
    cout << "Bienvenido a la Calculadora de matrices de NeoTel Companny."<<endl;
    D* ejercicioDos = new D;
    T* ejercicioTres = new T;
    C* ejercicioCuatro =  new C;
    do {
        cout << "Para elijir que tipo de matriz planea usar,ingrese el numero de la opcion"<<endl<<"opcion 1) matriz 2x2"<<endl;
        cout <<"opcion 2) matrix 3x3"<<endl<<"opcion 3) matrix 4x4"<<endl<<"Introducir cualquier otro caracter distintos a las opciones terminara el programa.";
        cin >> Tipo;
        switch(Tipo) {
            case 1:
                // Desarrollo para un 2x2
                InsertarDos(ejercicioDos);
                DesarrolloDos(ejercicioDos);
                delete(ejercicioDos);
                break;
            case 2:
                InsertarTres(ejercicioTres);
                DesarrolloTres(ejercicioTres);
                delete(ejercicioTres);
                break;
            case 3:
                InsertarCuatro(ejercicioCuatro);
                DesarrolloCuatroSistema(ejercicioCuatro);
                DesarrolloCuatroX(ejercicioCuatro);
                DesarrolloCuatroY(ejercicioCuatro);
                DesarrolloCuatroZ(ejercicioCuatro);
                DesarrolloCuatroW(ejercicioCuatro);
                Imprimir(ejercicioCuatro);
                delete(ejercicioCuatro);
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
//Funciones2X2
void InsertarDos(D* Ejercicio){
    try {
        float x, y, r, X, Y, R;
        cout << "Ingrese el valor que acompañara al X para la primera ecuacion" << endl;
        cin >> x;
        cout << "Ingrese el valor que acompañara al Y para la primera ecuacion" << endl;
        cin >> y;
        cout << "Ingrese el valor de la ecuacion" << endl;
        cin >> r;
        cout << "Ingrese el valor que acompañara al X para la segunda ecuacion" << endl;
        cin >> X;
        cout << "Ingrese el valor que acompañara al Y para la segunda ecuacion" << endl;
        cin >> Y;
        cout << "Ingrese el valor de la segunda ecuacion" << endl;
        cin >> R;
        Ejercicio->x = x;
        Ejercicio->y = y;
        Ejercicio->r = r;
        Ejercicio->X = X;
        Ejercicio->Y = Y;
        Ejercicio->R = R;
    }
    catch (invalid_argument){
        cout<<"skere";
    }
}
void DesarrolloDos(D* Ejercicio) {
    //arrays para ordenar los valores
    float uno[3] = {Ejercicio->x, Ejercicio->y, Ejercicio->r};
    float dos[3] = {Ejercicio->X, Ejercicio->Y, Ejercicio->R};
    //Determinante Sistema.
    float determinanteSistema = (uno[0] * dos[1]) - (uno[1] * dos[0]);
    cout << determinanteSistema << endl;
    if (determinanteSistema==0) {
        cout << "el sistema no presenta un formato valido para esta calculadora.";
    }
    else{
        //Determinante de la X.
        float determinanteX = (uno[2] * dos[1]) - (dos[2] * uno[1]);
        cout << determinanteX << endl;
        //Determinante de la Y.
        float determianteY = (uno[0] * dos[2]) - (uno[2] * dos[0]);
        cout << determianteY << endl;
        //Division de los Coeficientes
        float ValorX = (determinanteX / determinanteSistema);
        float ValorY = (determianteY / determinanteSistema);
        float Resultado[2] = {ValorX, ValorY};
        Ejercicio->ResultadoX = Resultado[0];
        Ejercicio->ResultadoY = Resultado[1];
        float resultado[2] = {Ejercicio->ResultadoX,Ejercicio->ResultadoY};
        cout << "el programa ha terminando de operar, los resultados fueron: "<< endl;
        cout << "(" << resultado[0] << "," << resultado[1] << ")" << endl;
        cout << endl << endl;
    }
}
//Funciones3X3
void InsertarTres(T* Ejercicio) {
    float x,y,z,r,X,Y,Z,R,aX,aY,aZ,aR;
    cout << "Ingrese el valor que acompañara al X para la primera ecuacion"<<endl;cin >> x;
    cout << "Ingrese el valor que acompañara al Y para la primera ecuacion"<<endl;cin >> y;
    cout << "Ingrese el valor que acompañara al Z para la primera ecuacion"<<endl;cin >> z;
    cout << "Ingrese el valor de la ecuacion"<<endl;cin >> r;
    cout << "Ingrese el valor que acompañara al X para la segunda ecuacion"<<endl;cin >> X;
    cout << "Ingrese el valor que acompañara al Y para la segunda ecuacion"<<endl;cin >> Y;
    cout << "Ingrese el valor que acompañara al Z para la segunda ecuacion"<<endl;cin >> Z;
    cout << "Ingrese el valor de la segunda ecuacion"<<endl;cin >> R;
    cout << "Ingrese el valor que acompañara al X para la tercera ecuacion"<<endl;cin >> aX;
    cout << "Ingrese el valor que acompañara al Y para la tercera ecuacion"<<endl;cin >> aY;
    cout << "Ingrese el valor que acompañara al Z para la tercera ecuacion"<<endl;cin >> aZ;
    cout << "Ingrese el valor de la tercera ecuacion"<<endl;cin >> aR;
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
            (uno[2] * dos[1] * tres[0]) + (dos[2] * tres[1] * uno[0]) + (tres[2] * uno[1] * dos[0]);
    float DeterminanteSistema = DeterminanteSistemaA - DeterminanteSistemaB;
    if (DeterminanteSistema==0){
        cout << "el sistema no presenta un formato valido para esta calculadora.";
    }
    else {
        //Determinante X
        float DeterminanteXA =
                (uno[3] * dos[1] * tres[2]) + (dos[2] * tres[3] * uno[1]) + (tres[1] * uno[2] * dos[3]);
        float DeterminanteXB =
                (uno[2] * dos[1] * tres[3]) + (dos[2] * tres[1] * uno[3]) + (tres[2] * uno[1] * dos[3]);
        float DeterminanteX = DeterminanteXA - DeterminanteXB;
        //Determinante Y
        float DeterminanteYA =
                (uno[0] * dos[3] * tres[2]) + (dos[2] * tres[0] * uno[3]) + (tres[3] * uno[2] * dos[0]);
        float DeterminanteYB =
                (uno[2] * dos[3] * tres[0]) + (dos[2] * tres[3] * uno[0]) + (tres[2] * uno[3] * dos[0]);
        float DeterminanteY = DeterminanteYA - DeterminanteYB;
        //Determinante Z
        float DeterminanteZA =
                (uno[0] * dos[1] * tres[3]) + (dos[3] * tres[0] * uno[1]) + (tres[1] * uno[3] * dos[0]);
        float DeterminanteZB =
                (uno[3] * dos[1] * tres[0]) + (dos[3] * tres[1] * uno[0]) + (tres[3] * uno[1] * dos[0]);
        float DeterminanteZ = DeterminanteZA - DeterminanteZB;
        //Valores incognitas
        float ValorX = (DeterminanteX / DeterminanteSistema);
        float ValorY = (DeterminanteY / DeterminanteSistema);
        float ValorZ = (DeterminanteZ / DeterminanteSistema);
        float Resultados[3] = {ValorX, ValorY, ValorZ};
        Ejercicio->ResultadoX = Resultados[0];
        Ejercicio->ResultadoY = Resultados[1];
        Ejercicio->ResultadoZ = Resultados[2];
        float resultado[3] = {Ejercicio->ResultadoX, Ejercicio->ResultadoY, Ejercicio->ResultadoZ};
        cout << "el programa ha terminando de operar, los resultados fueron: " << endl;
        cout << "(" << resultado[0] << "," << resultado[1] << "," << resultado[2] << ")" << endl;
        cout << endl << endl;
    }
}
//Funciones4X4
void InsertarCuatro(C* Ejercicio){
    float x,y,z,w,r,X,Y,Z,W,R,aX,aY,aZ,aW,aR,ax,ay,az,aw,ar;
    cout << "Ingrese el valor que acompañara al X para la primera ecuacion"<<endl;cin >> x;
    cout << "Ingrese el valor que acompañara al Y para la primera ecuacion"<<endl;cin >> y;
    cout << "Ingrese el valor que acompañara al Z para la primera ecuacion"<<endl;cin >> z;
    cout << "Ingrese el valor que acompañara al W para la primera ecuacion"<<endl;cin >> w;
    cout << "Ingrese el valor de la ecuacion"<<endl;cin >> r;
    cout << "Ingrese el valor que acompañara al X para la segunda ecuacion"<<endl;cin >> X;
    cout << "Ingrese el valor que acompañara al Y para la segunda ecuacion"<<endl;cin >> Y;
    cout << "Ingrese el valor que acompañara al Z para la segunda ecuacion"<<endl;cin >> Z;
    cout << "Ingrese el valor que acompañara al W para la segunda ecuacion"<<endl;cin >> W;
    cout << "Ingrese el valor de la segunda ecuacion"<<endl;cin >> R;
    cout << "Ingrese el valor que acompañara al X para la tercera ecuacion"<<endl;cin >> aX;
    cout << "Ingrese el valor que acompañara al Y para la tercera ecuacion"<<endl;cin >> aY;
    cout << "Ingrese el valor que acompañara al Z para la tercera ecuacion"<<endl;cin >> aZ;
    cout << "Ingrese el valor que acompañara al W para la tercera ecuacion"<<endl;cin >> aW;
    cout << "Ingrese el valor de la tercera ecuacion"<<endl;cin >> aR;
    cout << "Ingrese el valor que acompañara al X para la cuarta ecuacion"<<endl;cin >> ax;
    cout << "Ingrese el valor que acompañara al Y para la cuarta ecuacion"<<endl;cin >> ay;
    cout << "Ingrese el valor que acompañara al Z para la cuarta ecuacion"<<endl;cin >> az;
    cout << "Ingrese el valor que acompañara al W para la cuarta ecuacion"<<endl;cin >> aw;
    cout << "Ingrese el valor para la cuarta ecuacion"<<endl;cin >> ar;
    Ejercicio->z=z;Ejercicio->x=x;Ejercicio->y=y;Ejercicio->r=r;Ejercicio->w=w;
    Ejercicio->W=W;Ejercicio->Z=Z;Ejercicio->X=X;Ejercicio->Y=Y;Ejercicio->R=R;
    Ejercicio->aW=aW;Ejercicio->aZ=aZ;Ejercicio->aX=aX;Ejercicio->aY=aY;Ejercicio->aR=aR;
    Ejercicio->ax=ax;Ejercicio->ay=ay;Ejercicio->aw=aw;Ejercicio->az=az;Ejercicio->ar=ar;
}
void DesarrolloCuatroSistema(C* Ejercicio){
    //Determinante el sistema
    float FilaUno[4] = {Ejercicio->x,Ejercicio->y,Ejercicio->z,Ejercicio->w};
    float UnoFilaUno[5] = {Ejercicio->Y,Ejercicio->Z,Ejercicio->W,Ejercicio->Y,Ejercicio->Z};
    float UnoFilaDos[5] = {Ejercicio->aY,Ejercicio->aZ,Ejercicio->aW,Ejercicio->aY,Ejercicio->aZ};
    float UnoFilaTres[5] = {Ejercicio->ay,Ejercicio->az,Ejercicio->aw,Ejercicio->ay,Ejercicio->az};
    float UnoDiagonal= ((UnoFilaUno[0]*UnoFilaDos[1]*UnoFilaTres[2])+(UnoFilaUno[1]*UnoFilaDos[2]*UnoFilaTres[3])+(UnoFilaUno[2]*UnoFilaDos[3]*UnoFilaTres[4])) - ((UnoFilaUno[4]*UnoFilaDos[3]*UnoFilaTres[2])+(UnoFilaUno[3]*UnoFilaDos[2]*UnoFilaTres[1])+(UnoFilaUno[2]*UnoFilaDos[1]*UnoFilaTres[0]));
    float DosFilaUno[5] = {Ejercicio->X,Ejercicio->Z,Ejercicio->W,Ejercicio->X,Ejercicio->Z};
    float DosFilaDos[5] = {Ejercicio->aX,Ejercicio->aZ,Ejercicio->aW,Ejercicio->aX,Ejercicio->aZ};
    float DosFilaTres[5] = {Ejercicio->ax,Ejercicio->az,Ejercicio->aw,Ejercicio->ax,Ejercicio->az};
    float DosDiagonal= ((DosFilaUno[0]*DosFilaDos[1]*DosFilaTres[2])+(DosFilaUno[1]*DosFilaDos[2]*DosFilaTres[3])+(DosFilaUno[2]*DosFilaDos[3]*DosFilaTres[4])) - ((DosFilaUno[4]*DosFilaDos[3]*DosFilaTres[2])+(DosFilaUno[3]*DosFilaDos[2]*DosFilaTres[1])+(DosFilaUno[2]*DosFilaDos[1]*DosFilaTres[0]));
    float TresFilaUno[5] = {Ejercicio->X,Ejercicio->Y,Ejercicio->W,Ejercicio->X,Ejercicio->Y};
    float TresFilaDos[5] = {Ejercicio->aX,Ejercicio->aY,Ejercicio->aW,Ejercicio->aX,Ejercicio->aY};
    float TresFilaTres[5] = {Ejercicio->ax,Ejercicio->ay,Ejercicio->aw,Ejercicio->ax,Ejercicio->ay};
    float TresDiagonal= ((TresFilaUno[0]*TresFilaDos[1]*TresFilaTres[2])+(TresFilaUno[1]*TresFilaDos[2]*TresFilaTres[3])+(TresFilaUno[2]*TresFilaDos[3]*TresFilaTres[4])) - ((TresFilaUno[4]*TresFilaDos[3]*TresFilaTres[2])+(TresFilaUno[3]*TresFilaDos[2]*TresFilaTres[1])+(TresFilaUno[2]*TresFilaDos[1]*TresFilaTres[0]));
    float CuatroFilaUno[5] = {Ejercicio->X,Ejercicio->Y,Ejercicio->Z,Ejercicio->X,Ejercicio->Y};
    float CuatroFilaDos[5] = {Ejercicio->aX,Ejercicio->aY,Ejercicio->aZ,Ejercicio->aX,Ejercicio->aY};
    float CuatroFilaTres[5] = {Ejercicio->ax,Ejercicio->ay,Ejercicio->az,Ejercicio->ax,Ejercicio->ay};
    float CuatroDiagonal= ((CuatroFilaUno[0]*CuatroFilaDos[1]*CuatroFilaTres[2])+(CuatroFilaUno[1]*CuatroFilaDos[2]*CuatroFilaTres[3])+(CuatroFilaUno[2]*CuatroFilaDos[3]*CuatroFilaTres[4])) - ((CuatroFilaUno[4]*CuatroFilaDos[3]*CuatroFilaTres[2])+(CuatroFilaUno[3]*CuatroFilaDos[2]*CuatroFilaTres[1])+(CuatroFilaUno[2]*CuatroFilaDos[1]*CuatroFilaTres[0]));
    float ResultadoUno = ((FilaUno[0]*UnoDiagonal)+(FilaUno[1]*DosDiagonal*-1)+(FilaUno[2]*TresDiagonal*1)+(FilaUno[3]*CuatroDiagonal*-1));
    cout<<"El determinante del sistema corresponde a: "<<ResultadoUno<<endl;
    Ejercicio->DetSistema=ResultadoUno;
    cout<<"El determinante del sistema es: "<< ResultadoUno<<endl;
}
void DesarrolloCuatroX(C* Ejercicio){
    float FilaUno[4] = {Ejercicio->r,Ejercicio->y,Ejercicio->z,Ejercicio->w};
    float UnoFilaUno[5] = {Ejercicio->Y,Ejercicio->Z,Ejercicio->W,Ejercicio->Y,Ejercicio->Z};
    float UnoFilaDos[5] = {Ejercicio->aY,Ejercicio->aZ,Ejercicio->aW,Ejercicio->aY,Ejercicio->aZ};
    float UnoFilaTres[5] = {Ejercicio->ay,Ejercicio->az,Ejercicio->aw,Ejercicio->ay,Ejercicio->az};
    float UnoDiagonal= ((UnoFilaUno[0]*UnoFilaDos[1]*UnoFilaTres[2])+(UnoFilaUno[1]*UnoFilaDos[2]*UnoFilaTres[3])+(UnoFilaUno[2]*UnoFilaDos[3]*UnoFilaTres[4])) - ((UnoFilaUno[4]*UnoFilaDos[3]*UnoFilaTres[2])+(UnoFilaUno[3]*UnoFilaDos[2]*UnoFilaTres[1])+(UnoFilaUno[2]*UnoFilaDos[1]*UnoFilaTres[0]));
    float DosFilaUno[5] = {Ejercicio->R,Ejercicio->Z,Ejercicio->W,Ejercicio->R,Ejercicio->Z};
    float DosFilaDos[5] = {Ejercicio->aR,Ejercicio->aZ,Ejercicio->aW,Ejercicio->aR,Ejercicio->aZ};
    float DosFilaTres[5] = {Ejercicio->ar,Ejercicio->az,Ejercicio->aw,Ejercicio->ar,Ejercicio->az};
    float DosDiagonal= ((DosFilaUno[0]*DosFilaDos[1]*DosFilaTres[2])+(DosFilaUno[1]*DosFilaDos[2]*DosFilaTres[3])+(DosFilaUno[2]*DosFilaDos[3]*DosFilaTres[4])) - ((DosFilaUno[4]*DosFilaDos[3]*DosFilaTres[2])+(DosFilaUno[3]*DosFilaDos[2]*DosFilaTres[1])+(DosFilaUno[2]*DosFilaDos[1]*DosFilaTres[0]));
    float TresFilaUno[5] = {Ejercicio->R,Ejercicio->Y,Ejercicio->W,Ejercicio->R,Ejercicio->Y};
    float TresFilaDos[5] = {Ejercicio->aR,Ejercicio->aY,Ejercicio->aW,Ejercicio->aR,Ejercicio->aY};
    float TresFilaTres[5] = {Ejercicio->ar,Ejercicio->ay,Ejercicio->aw,Ejercicio->ar,Ejercicio->ay};
    float TresDiagonal= ((TresFilaUno[0]*TresFilaDos[1]*TresFilaTres[2])+(TresFilaUno[1]*TresFilaDos[2]*TresFilaTres[3])+(TresFilaUno[2]*TresFilaDos[3]*TresFilaTres[4])) - ((TresFilaUno[4]*TresFilaDos[3]*TresFilaTres[2])+(TresFilaUno[3]*TresFilaDos[2]*TresFilaTres[1])+(TresFilaUno[2]*TresFilaDos[1]*TresFilaTres[0]));
    float CuatroFilaUno[5] = {Ejercicio->R,Ejercicio->Y,Ejercicio->Z,Ejercicio->R,Ejercicio->Y};
    float CuatroFilaDos[5] = {Ejercicio->aR,Ejercicio->aY,Ejercicio->aZ,Ejercicio->aR,Ejercicio->aY};
    float CuatroFilaTres[5] = {Ejercicio->ar,Ejercicio->ay,Ejercicio->az,Ejercicio->ar,Ejercicio->ay};
    float CuatroDiagonal= ((CuatroFilaUno[0]*CuatroFilaDos[1]*CuatroFilaTres[2])+(CuatroFilaUno[1]*CuatroFilaDos[2]*CuatroFilaTres[3])+(CuatroFilaUno[2]*CuatroFilaDos[3]*CuatroFilaTres[4])) - ((CuatroFilaUno[4]*CuatroFilaDos[3]*CuatroFilaTres[2])+(CuatroFilaUno[3]*CuatroFilaDos[2]*CuatroFilaTres[1])+(CuatroFilaUno[2]*CuatroFilaDos[1]*CuatroFilaTres[0]));
    float ResultadoX = ((FilaUno[0]*UnoDiagonal)+(FilaUno[1]*DosDiagonal*-1)+(FilaUno[2]*TresDiagonal*1)+(FilaUno[3]*CuatroDiagonal*-1));
    cout<<"El determinante de X es: "<< ResultadoX<<endl;
    Ejercicio->DetX=ResultadoX;
}
void DesarrolloCuatroY(C* Ejercicio){
    float FilaUno[4] = {Ejercicio->x,Ejercicio->r,Ejercicio->z,Ejercicio->w};
    float UnoFilaUno[5] = {Ejercicio->R,Ejercicio->Z,Ejercicio->W,Ejercicio->R,Ejercicio->Z};
    float UnoFilaDos[5] = {Ejercicio->aR,Ejercicio->aZ,Ejercicio->aW,Ejercicio->aR,Ejercicio->aZ};
    float UnoFilaTres[5] = {Ejercicio->ar,Ejercicio->az,Ejercicio->aw,Ejercicio->ar,Ejercicio->az};
    float UnoDiagonal= ((UnoFilaUno[0]*UnoFilaDos[1]*UnoFilaTres[2])+(UnoFilaUno[1]*UnoFilaDos[2]*UnoFilaTres[3])+(UnoFilaUno[2]*UnoFilaDos[3]*UnoFilaTres[4])) - ((UnoFilaUno[4]*UnoFilaDos[3]*UnoFilaTres[2])+(UnoFilaUno[3]*UnoFilaDos[2]*UnoFilaTres[1])+(UnoFilaUno[2]*UnoFilaDos[1]*UnoFilaTres[0]));
    float DosFilaUno[5] = {Ejercicio->X,Ejercicio->Z,Ejercicio->W,Ejercicio->X,Ejercicio->Z};
    float DosFilaDos[5] = {Ejercicio->aX,Ejercicio->aZ,Ejercicio->aW,Ejercicio->aX,Ejercicio->aZ};
    float DosFilaTres[5] = {Ejercicio->ax,Ejercicio->az,Ejercicio->aw,Ejercicio->ax,Ejercicio->az};
    float DosDiagonal= ((DosFilaUno[0]*DosFilaDos[1]*DosFilaTres[2])+(DosFilaUno[1]*DosFilaDos[2]*DosFilaTres[3])+(DosFilaUno[2]*DosFilaDos[3]*DosFilaTres[4])) - ((DosFilaUno[4]*DosFilaDos[3]*DosFilaTres[2])+(DosFilaUno[3]*DosFilaDos[2]*DosFilaTres[1])+(DosFilaUno[2]*DosFilaDos[1]*DosFilaTres[0]));
    float TresFilaUno[5] = {Ejercicio->X,Ejercicio->R,Ejercicio->W,Ejercicio->X,Ejercicio->R};
    float TresFilaDos[5] = {Ejercicio->aX,Ejercicio->aR,Ejercicio->aW,Ejercicio->aX,Ejercicio->aR};
    float TresFilaTres[5] = {Ejercicio->ax,Ejercicio->ar,Ejercicio->aw,Ejercicio->ax,Ejercicio->ar};
    float TresDiagonal= ((TresFilaUno[0]*TresFilaDos[1]*TresFilaTres[2])+(TresFilaUno[1]*TresFilaDos[2]*TresFilaTres[3])+(TresFilaUno[2]*TresFilaDos[3]*TresFilaTres[4])) - ((TresFilaUno[4]*TresFilaDos[3]*TresFilaTres[2])+(TresFilaUno[3]*TresFilaDos[2]*TresFilaTres[1])+(TresFilaUno[2]*TresFilaDos[1]*TresFilaTres[0]));
    float CuatroFilaUno[5] = {Ejercicio->X,Ejercicio->R,Ejercicio->Z,Ejercicio->X,Ejercicio->R};
    float CuatroFilaDos[5] = {Ejercicio->aX,Ejercicio->aR,Ejercicio->aZ,Ejercicio->aX,Ejercicio->aR};
    float CuatroFilaTres[5] = {Ejercicio->ax,Ejercicio->ar,Ejercicio->az,Ejercicio->ax,Ejercicio->ar};
    float CuatroDiagonal= ((CuatroFilaUno[0]*CuatroFilaDos[1]*CuatroFilaTres[2])+(CuatroFilaUno[1]*CuatroFilaDos[2]*CuatroFilaTres[3])+(CuatroFilaUno[2]*CuatroFilaDos[3]*CuatroFilaTres[4])) - ((CuatroFilaUno[4]*CuatroFilaDos[3]*CuatroFilaTres[2])+(CuatroFilaUno[3]*CuatroFilaDos[2]*CuatroFilaTres[1])+(CuatroFilaUno[2]*CuatroFilaDos[1]*CuatroFilaTres[0]));
    float ResultadoY = ((FilaUno[0]*UnoDiagonal)+(FilaUno[1]*DosDiagonal*-1)+(FilaUno[2]*TresDiagonal*1)+(FilaUno[3]*CuatroDiagonal*-1));
    cout<<"El Determinante de Y es: "<<ResultadoY<<endl;
    Ejercicio->DetY=ResultadoY;
}
void DesarrolloCuatroZ(C* Ejercicio){
    float FilaUno[4] = {Ejercicio->x,Ejercicio->y,Ejercicio->r,Ejercicio->w};
    float UnoFilaUno[5] = {Ejercicio->Y,Ejercicio->R,Ejercicio->W,Ejercicio->Y,Ejercicio->R};
    float UnoFilaDos[5] = {Ejercicio->aY,Ejercicio->aR,Ejercicio->aW,Ejercicio->aY,Ejercicio->aR};
    float UnoFilaTres[5] = {Ejercicio->ay,Ejercicio->ar,Ejercicio->aw,Ejercicio->ay,Ejercicio->ar};
    float UnoDiagonal= ((UnoFilaUno[0]*UnoFilaDos[1]*UnoFilaTres[2])+(UnoFilaUno[1]*UnoFilaDos[2]*UnoFilaTres[3])+(UnoFilaUno[2]*UnoFilaDos[3]*UnoFilaTres[4])) - ((UnoFilaUno[4]*UnoFilaDos[3]*UnoFilaTres[2])+(UnoFilaUno[3]*UnoFilaDos[2]*UnoFilaTres[1])+(UnoFilaUno[2]*UnoFilaDos[1]*UnoFilaTres[0]));
    float DosFilaUno[5] = {Ejercicio->X,Ejercicio->R,Ejercicio->W,Ejercicio->X,Ejercicio->R};
    float DosFilaDos[5] = {Ejercicio->aX,Ejercicio->aR,Ejercicio->aW,Ejercicio->aX,Ejercicio->aR};
    float DosFilaTres[5] = {Ejercicio->ax,Ejercicio->ar,Ejercicio->aw,Ejercicio->ax,Ejercicio->ar};
    float DosDiagonal= ((DosFilaUno[0]*DosFilaDos[1]*DosFilaTres[2])+(DosFilaUno[1]*DosFilaDos[2]*DosFilaTres[3])+(DosFilaUno[2]*DosFilaDos[3]*DosFilaTres[4])) - ((DosFilaUno[4]*DosFilaDos[3]*DosFilaTres[2])+(DosFilaUno[3]*DosFilaDos[2]*DosFilaTres[1])+(DosFilaUno[2]*DosFilaDos[1]*DosFilaTres[0]));
    float TresFilaUno[5] = {Ejercicio->X,Ejercicio->Y,Ejercicio->W,Ejercicio->X,Ejercicio->Y};
    float TresFilaDos[5] = {Ejercicio->aX,Ejercicio->aY,Ejercicio->aW,Ejercicio->aX,Ejercicio->aY};
    float TresFilaTres[5] = {Ejercicio->ax,Ejercicio->ay,Ejercicio->aw,Ejercicio->ax,Ejercicio->ay};
    float TresDiagonal= ((TresFilaUno[0]*TresFilaDos[1]*TresFilaTres[2])+(TresFilaUno[1]*TresFilaDos[2]*TresFilaTres[3])+(TresFilaUno[2]*TresFilaDos[3]*TresFilaTres[4])) - ((TresFilaUno[4]*TresFilaDos[3]*TresFilaTres[2])+(TresFilaUno[3]*TresFilaDos[2]*TresFilaTres[1])+(TresFilaUno[2]*TresFilaDos[1]*TresFilaTres[0]));
    float CuatroFilaUno[5] = {Ejercicio->X,Ejercicio->Y,Ejercicio->R,Ejercicio->X,Ejercicio->Y};
    float CuatroFilaDos[5] = {Ejercicio->aX,Ejercicio->aY,Ejercicio->aR,Ejercicio->aX,Ejercicio->aY};
    float CuatroFilaTres[5] = {Ejercicio->ax,Ejercicio->ay,Ejercicio->az,Ejercicio->ax,Ejercicio->ay};
    float CuatroDiagonal= ((CuatroFilaUno[0]*CuatroFilaDos[1]*CuatroFilaTres[2])+(CuatroFilaUno[1]*CuatroFilaDos[2]*CuatroFilaTres[3])+(CuatroFilaUno[2]*CuatroFilaDos[3]*CuatroFilaTres[4])) - ((CuatroFilaUno[4]*CuatroFilaDos[3]*CuatroFilaTres[2])+(CuatroFilaUno[3]*CuatroFilaDos[2]*CuatroFilaTres[1])+(CuatroFilaUno[2]*CuatroFilaDos[1]*CuatroFilaTres[0]));
    float ResultadoZ = ((FilaUno[0]*UnoDiagonal)+(FilaUno[1]*DosDiagonal*-1)+(FilaUno[2]*TresDiagonal*1)+(FilaUno[3]*CuatroDiagonal*-1));
    cout<<"El Determinante de Z es: "<<ResultadoZ<<endl;
    Ejercicio->DetZ=ResultadoZ;
}
void DesarrolloCuatroW(C* Ejercicio){
    float FilaUno[4] = {Ejercicio->x,Ejercicio->y,Ejercicio->z,Ejercicio->r};
    float UnoFilaUno[5] = {Ejercicio->Y,Ejercicio->Z,Ejercicio->R,Ejercicio->Y,Ejercicio->Z};
    float UnoFilaDos[5] = {Ejercicio->aY,Ejercicio->aZ,Ejercicio->aR,Ejercicio->aY,Ejercicio->aZ};
    float UnoFilaTres[5] = {Ejercicio->ay,Ejercicio->az,Ejercicio->ar,Ejercicio->ay,Ejercicio->az};
    float UnoDiagonal= ((UnoFilaUno[0]*UnoFilaDos[1]*UnoFilaTres[2])+(UnoFilaUno[1]*UnoFilaDos[2]*UnoFilaTres[3])+(UnoFilaUno[2]*UnoFilaDos[3]*UnoFilaTres[4])) - ((UnoFilaUno[4]*UnoFilaDos[3]*UnoFilaTres[2])+(UnoFilaUno[3]*UnoFilaDos[2]*UnoFilaTres[1])+(UnoFilaUno[2]*UnoFilaDos[1]*UnoFilaTres[0]));
    float DosFilaUno[5] = {Ejercicio->X,Ejercicio->Z,Ejercicio->R,Ejercicio->X,Ejercicio->Z};
    float DosFilaDos[5] = {Ejercicio->aX,Ejercicio->aZ,Ejercicio->aR,Ejercicio->aX,Ejercicio->aZ};
    float DosFilaTres[5] = {Ejercicio->ax,Ejercicio->az,Ejercicio->ar,Ejercicio->ax,Ejercicio->az};
    float DosDiagonal= ((DosFilaUno[0]*DosFilaDos[1]*DosFilaTres[2])+(DosFilaUno[1]*DosFilaDos[2]*DosFilaTres[3])+(DosFilaUno[2]*DosFilaDos[3]*DosFilaTres[4])) - ((DosFilaUno[4]*DosFilaDos[3]*DosFilaTres[2])+(DosFilaUno[3]*DosFilaDos[2]*DosFilaTres[1])+(DosFilaUno[2]*DosFilaDos[1]*DosFilaTres[0]));
    float TresFilaUno[5] = {Ejercicio->X,Ejercicio->Y,Ejercicio->R,Ejercicio->X,Ejercicio->Y};
    float TresFilaDos[5] = {Ejercicio->aX,Ejercicio->aY,Ejercicio->aR,Ejercicio->aX,Ejercicio->aY};
    float TresFilaTres[5] = {Ejercicio->ax,Ejercicio->ay,Ejercicio->ar,Ejercicio->ax,Ejercicio->ay};
    float TresDiagonal= ((TresFilaUno[0]*TresFilaDos[1]*TresFilaTres[2])+(TresFilaUno[1]*TresFilaDos[2]*TresFilaTres[3])+(TresFilaUno[2]*TresFilaDos[3]*TresFilaTres[4])) - ((TresFilaUno[4]*TresFilaDos[3]*TresFilaTres[2])+(TresFilaUno[3]*TresFilaDos[2]*TresFilaTres[1])+(TresFilaUno[2]*TresFilaDos[1]*TresFilaTres[0]));
    float CuatroFilaUno[5] = {Ejercicio->X,Ejercicio->Y,Ejercicio->Z,Ejercicio->X,Ejercicio->Y};
    float CuatroFilaDos[5] = {Ejercicio->aX,Ejercicio->aY,Ejercicio->aZ,Ejercicio->aX,Ejercicio->aY};
    float CuatroFilaTres[5] = {Ejercicio->ax,Ejercicio->ay,Ejercicio->az,Ejercicio->ax,Ejercicio->ay};
    float CuatroDiagonal= ((CuatroFilaUno[0]*CuatroFilaDos[1]*CuatroFilaTres[2])+(CuatroFilaUno[1]*CuatroFilaDos[2]*CuatroFilaTres[3])+(CuatroFilaUno[2]*CuatroFilaDos[3]*CuatroFilaTres[4])) - ((CuatroFilaUno[4]*CuatroFilaDos[3]*CuatroFilaTres[2])+(CuatroFilaUno[3]*CuatroFilaDos[2]*CuatroFilaTres[1])+(CuatroFilaUno[2]*CuatroFilaDos[1]*CuatroFilaTres[0]));
    float ResultadoUno = ((FilaUno[0]*UnoDiagonal)+(FilaUno[1]*DosDiagonal*-1)+(FilaUno[2]*TresDiagonal*1)+(FilaUno[3]*CuatroDiagonal*-1));
    cout<<"El Determinante W es: "<<ResultadoUno<<endl;
    Ejercicio->DetW=ResultadoUno;
}
void Imprimir(C* Ejercicio){
    float resultado[4] = {Ejercicio->DetX, Ejercicio->DetY, Ejercicio->DetZ,Ejercicio->DetW};
    cout << "el programa ha terminando de operar, los resultados fueron: " << endl;
    cout << "(" << resultado[0] << "," << resultado[1] << "," << resultado[2] << "," << resultado[3] << ")" << endl;
    cout << endl << endl;
}