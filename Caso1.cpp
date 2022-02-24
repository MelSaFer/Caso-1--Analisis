/*
Instituto Tecnologico de Costa Rica, Analisis de Algoritmos
CASO 1
MELANY DAHIANA SALAS FERNANDEZ
2021121147
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

//---------------------------------PARTE-1----------------------------------
//Compare the triplets______________________________________________________
//Entradas: 2 arrays lists con 3 numeros enteros cada uno
//Salidas: el resultado de la comparacion de los array lists con los puntos respectivos
//Restricciones: ????

//Version 1.

int compareTripletsV1( int lista1[3], int lista2[3]){
    
    int resul[2]= {0,0};
    
    for(int i = 0; i < 3; i++){
        
        if (lista1[i] == lista2[i]){
            //cout<< "Punto para Ninguno"<< endl;
        } else if(lista1[i] < lista2[i]){ //Punto para Bob
            //cout<< "Punto para Bob"<< endl;
            resul[1]++;
        } else{
            //cout<< "Punto para Alice"<< endl;
            resul[0]++;
        }
    }
    cout<< "Resultado Alice: " << resul[0] << endl;
    cout<< "Resultado Bob: " << resul[1] << endl;
    return 0;
}
//Version 2- Optimizada
int compareTripletsV2( int lista1[3], int lista2[3]){
    
    int resul[2]= {0,0};
    //(lista1[0] > lista2[0])? printf("1") : printf("0"); (lista1[1] > lista2[1])? printf("1") : printf("0"); (lista1[2] > lista2[2])? printf("1") : printf("0");
    //(lista1[0] < lista2[0])? printf("|1") : printf("0"); (lista1[1] < lista2[1])? printf("1") : printf("0"); (lista1[2] < lista2[2])? printf("1") : printf("0");
    
    resul[0]= ((lista1[0] > lista2[0])? 1 : 0) + ((lista1[1] > lista2[1])? 1 : 0) + ((lista1[2] > lista2[2])? 1 : 0);
    resul[1]= ((lista1[0] < lista2[0])? 1 : 0) + ((lista1[1] < lista2[1])? 1 : 0) + ((lista1[2] < lista2[2])? 1 : 0);
    

    cout<< "Resultado Alice: " << resul[0] << endl;
    cout<< "Resultado Bob: " << resul[1] << endl;
    return 0;
}

//Time Coversion______________________________________________________
//Entradas: Una hora tipo String en formato HH:MM:SSAM O HH:MM:SSPM con formato
//          12 horas
//Salidas: La hora en formato de 24 horas
//Resticciones: ?????????????

//Version 1.
string timeConversionV1(string hora12){
     int hora = stoi(hora12.substr(0,2));

    if(hora12.substr(8,2) == "PM"){
        if (hora < 12){
            hora12.replace(0,2, to_string(hora + 12));
        }
    } else if( hora == 12){
        hora12.replace(0,2, "00");
    }
    hora12.erase(8,2);
    return hora12;
}

//Version 2
//Usa menos variables
string timeConversionV2(string hora12){
    int hora = stoi(hora12.substr(0,2));

    if(hora12.substr(8,2) == "PM"){
        
        if (hora < 12){
            hora12.replace(0,2, to_string(hora + 12));
        }
    } else if( hora == 12){
        hora12.replace(0,2, "00");
    }
    hora12.erase(8,2);
    return hora12;
}

//Subarray Division______________________________________________________
//Entradas: Una lista que representan los enteros que tienen los trozos de chocolate
//          el dia de cumpleaños, el mes de cumpleaños
//Salidas: Todas las posibles combinaciones con la que puedo, con la suma de los
//          enteros obtener el dia de cumpleaños y la cantidad de elementos
//          debe ser el mes.

//Version 1.
int subarrayDivisionV1(int listaInt[], int dia, int mes){
    int resul = 0; //posibles combinaciones
    //for(int i = 0, i )

    return resul;
}

//Version 2.
int subarrayDivisionV2(int listaInt[], int dia, int mes){
    int resul = 0;
    
    //cout << sizeof(listaInt) << endl;
    return resul;
}

//The Minion Game___________________________________________________________________
//Entradas: Un string con la palabra con la que se va a jugar en letras mayusculas
//Salidas: El nombre del jugador ganador y el puntaje obtenido
//Restricciones: 

string minionGame( string palabra){

    string resul;

    int lim = palabra.length(); int lim2 = lim;
    int contC = 0 ; int contV = 0;

    for(int i = 0; i <= lim; i++){
        char letra = palabra[i];
        if( letra == 65 || letra == 69 || letra == 73 || letra == 79 || letra == 85){
            contV += lim2;
        } else
            contC += lim2;
        lim2--;
    }
    //EVALUACION DEL VALOR DE RETORNO
    if (contV > contC){
        resul = "Kevin " + to_string(contV);
    } else
        resul = "Stuart " + to_string(contC);
    
    return resul;
}















int main(){
    //Listas para probar ejercicio 1
    int lista1[3]= {1,3,4};
    int lista2[3]= {2,3,7};
    int lista3[3]= {2,4,5};

    cout << "Prueba 1- Listas {1,3,4} y {1,3,4}" << endl;
    compareTripletsV1(lista1, lista1);

    cout << "\nPrueba 2- Listas {1,3,4} y {2,3,7}" << endl;
    compareTripletsV1(lista1, lista2);

     cout << "\nPrueba 3- Listas {2,4,5} y {2,3,7}" << endl;
    compareTripletsV1(lista3, lista2);

    cout << "\n\nPrueba 1 V2- {1,3,4} y {1,3,4}" << endl;
    compareTripletsV2(lista1, lista1);

    cout << "\nPrueba 2 V2- Listas {1,3,4} y {2,3,7}" << endl;
    compareTripletsV2(lista1, lista2);

     cout << "\nPrueba 3 V2- Listas {2,4,5} y {2,3,7}" << endl;
    compareTripletsV2(lista3, lista2);

    cout<< "\n\nPruebas Ejercicio 2"<< endl;
    cout << "\nHORA EN FORMATO 12 HORAS: 02:00:22PM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV1("02:00:22PM")<<endl;
    cout << "\nHORA EN FORMATO 12 HORAS: 11:20:16AM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV1("11:20:16AM")<<endl;
    cout << "\nHORA EN FORMATO 12 HORAS: 09:42:09PM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV1("09:42:09PM")<<endl;
    cout << "\nHORA EN FORMATO 12 HORAS: 12:27:53PM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV1("12:27:53PM")<<endl;

    //cout << "\nHORA EN FORMATO 12 HORAS: 12:27:53AM" << endl;
    //cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV1("12:27:53AM")<<en

    cout<< "\n\nPruebas Ejercicio 2 v2"<< endl;
    cout << "\nHORA EN FORMATO 12 HORAS: 02:00:22PM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV2("02:00:22PM")<<endl;

    cout << "\nHORA EN FORMATO 12 HORAS: 08:27:53PM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV2("08:27:53PM")<<endl;

    cout << "\nHORA EN FORMATO 12 HORAS: 12:27:53PM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV2("12:27:53PM")<<endl;

    cout << "\nHORA EN FORMATO 12 HORAS: 12:27:53AM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV2("12:27:53AM")<<endl;

    //int list[8] = {1,2,34,4,2,2,1,1};
    //subarrayDivisionV2( list, 3, 4);
    cout << minionGame( "BANANA") << endl;
    cout << minionGame( "HOLA") << endl;
    cout << minionGame( "HOLAAA") << endl;


    return 0;
}