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
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;



string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

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
//Es mas eficiente por:
//                     > No tiene ciclos, por lo que no hace que el sistema adelante trabajo y
//                       tenga que deshacerlo porque sobrepasa pa condicion de parada
int* compareTripletsV2( int lista1[3], int lista2[3]){
    
    static int resul[2]= {0,0};
    
    resul[0]= ((lista1[0] > lista2[0])? 1 : 0) + ((lista1[1] > lista2[1])? 1 : 0) + ((lista1[2] > lista2[2])? 1 : 0);
    resul[1]= ((lista1[0] < lista2[0])? 1 : 0) + ((lista1[1] < lista2[1])? 1 : 0) + ((lista1[2] < lista2[2])? 1 : 0);
    

    cout<< "Resultado Alice: " << resul[0] << endl;
    cout<< "Resultado Bob: " << resul[1] << endl;
    return resul;
}

//Time Coversion______________________________________________________
//Entradas: Una hora tipo String en formato HH:MM:SSAM O HH:MM:SSPM con formato
//          12 horas
//Salidas: La hora en formato de 24 horas
//Resticciones: NA

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
//Utiliza solamente una sentencia if, en comparacion a la otra que usa 3

string timeConversionV2(string horaInicial){
    string horaFinal = horaInicial.substr(2, 6); //Corta desde el primer: hasta los segundos
    int hora = stoi(horaInicial.substr(0,2));
    int factor = ((hora%12)/hora); //Evalua el caso especial(son las 12) 
                                        //Si las horas son 12 el resultado de la
                                        //division sera 1, de lo contrario, sera 0

    if(horaInicial[8]=='A') //Si las horas son antes de las 12 am o son las 12 am
        factor--; //Este factor se disminuye y tenemos 2 casos:
                        // 1- Son las 12 am por lo que el factor tiene un valor de 0, pasaria a ser -1 
                        // 2- No son las 12 am por lo que el factor pasa a ser 0

    hora += (12 * factor); //Aqui se modifican las horas, tenemos 3 casos:
                                // 1- El fator tiene un valor de -1, lo que significa que la hora anterior era 12 AM, por lo que en vez de sumar, resta 12
                                // 2- El factor tiene el valor de 0, lo que siginifa que eran antes de las 12 AM por lo que a la hora no se le debe sumar nada
                                // 3- El factor tiene un valor de 1, lo que indica que eran pasadas las 12 AM por lo que a la hora se le debe sumar 12        
	//cout<< "F: " << factor << " Hora: " << hora <<endl; //Para pruebas y entender el comportamiento del factor
    //Aqui forma la hora de acuerdo al formato, concatenando la hora con el resto(:minutos:seguntos)
    horaFinal = (hora<10) ? "0"+to_string(hora)+horaFinal : to_string(hora)+horaFinal;

    return horaFinal;
   
}


//Subarray Division______________________________________________________
//Entradas: Una lista que representan los enteros que tienen los trozos de chocolate
//          el dia de cumpleaños, el mes de cumpleaños
//Salidas: Todas las posibles combinaciones con la que puedo, con la suma de los
//          enteros obtener el dia de cumpleaños y la cantidad de elementos
//          debe ser el mes.

//Funcion para suma de arrays, se usa en la version menos eficiente
int suma(int listaInt[], int size){
    int resul = 0;
    for(int i =0; i< size; i++){
        resul+= listaInt[i];
    }
    return resul;
}

//Version 1.
//Esta solucion es menos eficiente, pues usa 1 ciclo para recorrer la lista, un segundo ciclo para hacer combinaciones y un 
//tercer ciclo para verificar la suma de los elementos del array
int subarrayDivisionV1(int listaInt[], int size, int dia, int mes){
    int comboCumple[mes];
    int contElementos;
    int contResul=0;
    int control;

    for(int i = 0; i < (size - (mes-1)); i++ ){
        comboCumple[0]= listaInt[i];
        control= i+1;
        contElementos=1;
        for(int i2 = 1; i2 <= mes; i2++){
            comboCumple[i2]= listaInt[control];
            if (contElementos==mes && suma(comboCumple, mes)== dia){
                contResul++;  
            } else if (contElementos==mes){
                break;
            }else {
                contElementos++;
            }
        } 
    }
    return contResul;
}


//Version 2.
//Es mas eficiente porque, a comparacion de la solucion anterior, solo usa un ciclo for, no 3.
int subarrayDivisionV2(int listaInt[], int size, int dia, int mes){
    int inicial = 0;
    int contResul = 0;
    int suma = 0;
    int control= 1;
    for (int i=0; i < size; i++){
        suma+=listaInt[i];
        if (control == mes && suma == dia){
            contResul+=1;
            suma-= listaInt[inicial];
            inicial++;
        } else if (control == mes){
            suma-= listaInt[inicial];
            inicial+=1;
        } else
            control++;
    }
   return contResul;
}

//The Minion Game___________________________________________________________________
//Entradas: Un string con la palabra con la que se va a jugar en letras mayusculas
//Salidas: El nombre del jugador ganador y el puntaje obtenido
//Restricciones: NA

string minionGame( string palabra){

    string resul;
    int lim = palabra.length(); int lim2 = lim;
    int contC = 0 ; int contV = 0;

    for(int i = 0; i <= lim; i++){
        char letra = palabra[i]; //La letra de la palabra en la que estoy actualmente
        if( letra == 65 || letra == 69 || letra == 73 || letra == 79 || letra == 85){  //Comparacion con codigos ascci
            contV += lim2; //Se aumenta el contador de vocales
        } else
            contC += lim2;  //Se aumenta en contador de consonantes
        lim2--; //El lim 2 dse disminuye porque conforme avamzo en la palabra, las posibles combinaciones son menos
    }
    //EVALUACION DEL VALOR DE RETORNO
    if (contV > contC){
        resul = "Kevin " + to_string(contV);
    } else
        resul = "Stuart " + to_string(contC);
    return resul;
}

//The Cipher___________________________________________________________________
//Entradas: Un entero K que representa las veces que se han hecho corrimientos
//          Un entero N que representa la longitud que debe tener la salida
//          Un string compuesto de 1 y 0
//Salidas: El mensaje decodificado
//Restricciones: NA
string cipher(int k, int n, string s) {
//    /* n es la longitud del string resultado
    vector<char> result(n);

    result[0] = s[0]-48;

    // Calcular los elementos de 1 a k-1
    for (int i = 1; i < k; i++) {
        result[i] = s[i-1] ^ s[i];
    }
    // Calcular los elementos de k en adelante
    char aux;
    for (int i = k; i < n; i++) {
        aux = '0';
        for (int j = i-(k-1); j < i; j++) {
            aux = aux ^ result[j];
        }
        result[i] = aux ^ s[i];
    }
    // Armar el string con el resultado
    string final_result = "";
    for (int i = 0; i < n; i++) {
        final_result += result[i]+48;
    }
    return final_result;
}

int pairs(int diferencia, vector<int> arr){
    int pointers[] = {1, 0, 0};     //Ayudan a ir avanzando en el array
    int resul = 0;                  //contador con el resultado de numeros que tienen diferencia K
    int valueDif = 0;               //Diferencia entre 2 numeros

    //Ciclo while para hacer los recorridos
    while (pointers[0] < arr.size()) {
        //cout <<  "Pointer[0]:" << pointers[0] <<  " Pointer[1]:" << pointers[1] <<  " Pointer[2]:" << pointers[2]<< endl;
        valueDif = abs(arr[pointers[0]] - arr[pointers[2]]); //resta entre numeros
        //cout << "Pos1: " << arr[pointers[0]] << "| pos2 : "<<  arr[pointers[2]] << endl;
        if (valueDif == diferencia) {        //si la diferencia en de k
            resul++;                        //Se aumenta en contador
            pointers[0]++;                  //el puntero sub 0 aumenta en uno el valor actual
            continue;                       //sale del ciclo y vuelve a evaluar 
        }
        //En este caso no entro al if anterior
        // Mueve el puntero necesario dependiendo si es mayor o menor
        pointers[((valueDif - diferencia)/abs(valueDif - diferencia)) + 1 ]++; // se realiza un calculo qie hara que aumente el puntero de x posicion
        //cout << "Resultado Calculo: " << ((valueDif - diferencia)/abs(valueDif - diferencia)) + 1 << endl;
    }
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


    cout<< "\n\nPruebas Ejercicio 2 v2"<< endl;
    cout << "\nHORA EN FORMATO 12 HORAS: 02:00:22PM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV2("02:00:22PM")<<endl;

    cout << "\nHORA EN FORMATO 12 HORAS: 08:27:53PM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV2("08:27:53PM")<<endl;

    cout << "\nHORA EN FORMATO 12 HORAS: 12:27:53PM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV2("12:27:53PM")<<endl;

    cout << "\nHORA EN FORMATO 12 HORAS: 12:27:53AM" << endl;
    cout << "HORA EN FORMATO 24 HORAS: " << timeConversionV2("12:27:53AM")<<endl;

    cout <<"\nPruebas de SubarrayDivision Version 1" << endl;
    //LISTA, SIZE, DIA, MES
    int list[5] = {2, 2, 1, 3, 2};
    cout << "Prueba con {2, 2, 1, 3, 2}, dia 4, mes 2 " << " Resultado: " << subarrayDivisionV1( list, 5, 4, 2) <<endl;

    int list2[5] = {1, 2, 1, 3, 2};
    cout << "Prueba con {1, 2, 1, 3, 2}, dia 3, mes 2 " << " Resultado: " << subarrayDivisionV1( list2, 5, 3, 2) <<endl;

    int list3[6] = {1, 1, 1, 1, 1, 1};
    cout << "Prueba con {1, 1, 1, 1, 1, 1}, dia 3, mes 3 " << " Resultado: " << subarrayDivisionV1( list3, 6, 3, 3) <<endl;
    cout << "Prueba con {1, 1, 1, 1, 1, 1}, dia 2, mes 3 " << " Resultado: " << subarrayDivisionV1( list3, 6, 2, 3) <<endl;
    
    int list4[1] = {4};
    cout << "Prueba con {4}, dia 4, mes 1 " << " Resultado: " << subarrayDivisionV1( list4, 1, 4, 1) <<endl;
    cout << "Prueba con {1, 1, 1, 1, 1, 1}, dia 4, mes 3 " << " Resultado: " << subarrayDivisionV1( list3, 6, 4, 3) <<endl;
    cout << "Prueba con {1, 1, 1, 1, 1, 1}, dia 4, mes 4 " << " Resultado: " << subarrayDivisionV1( list3, 6, 4, 4) <<endl;
     cout <<"\nPruebas de SubarrayDivision Version 2" << endl;
    //LISTA, SIZE, DIA, MES
    cout << "Prueba con {2, 2, 1, 3, 2}, dia 4, mes 2 " << " Resultado: " << subarrayDivisionV2( list, 5, 4, 2) <<endl;

    cout << "Prueba con {1, 2, 1, 3, 2}, dia 3, mes 2 " << " Resultado: " << subarrayDivisionV2( list2, 5, 3, 2) <<endl;

    cout << "Prueba con {1, 1, 1, 1, 1, 1}, dia 3, mes 3 " << " Resultado: " << subarrayDivisionV2( list3, 6, 3, 3) <<endl;
    cout << "Prueba con {1, 1, 1, 1, 1, 1}, dia 2, mes 3 " << " Resultado: " << subarrayDivisionV2( list3, 6, 2, 3) <<endl;
    cout << "Prueba con {4}, dia 4, mes 1 " << " Resultado: " << subarrayDivisionV2( list4, 1, 4, 1) <<endl;
    cout << "Prueba con {1, 1, 1, 1, 1, 1}, dia 4, mes 3 " << " Resultado: " << subarrayDivisionV2( list3, 6, 4, 3) <<endl;
    cout << "Prueba con {1, 1, 1, 1, 1, 1}, dia 4, mes 4 " << " Resultado: " << subarrayDivisionV2( list3, 6, 4, 4) <<endl;

    cout <<"\n Pruebas de The minion Game" << endl;
    cout << "\nPalabra: BANANA Resultado: " << minionGame( "BANANA") << endl;
    cout << "Palabra: HOLA Resultado: " << minionGame( "HOLA") << endl;
    cout << "Palabra: HOLAAA Resultado: " << minionGame( "HOLAAA") << endl;
    cout << "Palabra: FEBRERO Resultado: " << minionGame("FEBRERO") << endl;

    //Cipher(2, 6, 1110001);
    cout << "\n----------------Pruebas Cipher--------------" << endl;
    cout<< "Prueba con K= 2, N = 6, MENSAJE=1110001, Resultado: " << cipher(2, 6, "1110001") << endl;
    cout<< "Prueba con K= 2, N = 6, MENSAJE=1110100110, Resultado: " << cipher(4, 7, "1110100110") << endl;
   // cout<< "Prueba con K= 2, N = 6, MENSAJE=1110001, Resultado: " << cipher(2, 6, "1110001") << endl;

   cout << "\n--------------Pruebas Pairs--------------" << endl;
   vector<int> p1 = {1,2,3,4};
   cout <<"Array: {1,2,3,4}, k=1, Resultado: " << pairs(1, p1) << endl;
   vector<int> p2 = {1,2,3,4};
   cout << "Array: {1,2,3,4}, k=2, Resultado: " << pairs(2, p1) << endl;

    return 0;
}