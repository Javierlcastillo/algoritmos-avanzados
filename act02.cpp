// act02 - Zeros and Ones 
// Autor: Javier Luis Castillo Solórzano
// Matrícula: A0165841
// 010110011

#include <iostream>
#include <tuple>
#include <cstdlib>
using namespace std;


// Función que cuenta la cantida de 0 y 1 en el string, deuelve una tupla con estos valores
// Complejidad: O(n)
tuple<int, int> contar(string entrada, int largo) {
    int ceros = 0;
    int unos = 0; 
    for (int i=0; i < largo; i++){
        if (entrada[i] == '0')
            ceros++;
        else if (entrada[i] == '1')
            unos++;
    }
    return make_tuple(ceros,unos);
}

// Fución que obtenie la diferencia ente unos y ceros y devuelve el resultado 
// Complejidad: O(1)
int resultado(string entrada, int largo) {
    int ceros, unos;
    tie(ceros, unos)= contar(entrada, largo);
    int diferencia = abs(ceros - unos);
    return diferencia;
}

int main() {
    int tamano; 
    string cadena;
    cin >> tamano;
    cin >> cadena; 
    // int ceros, unos;
    cout << resultado(cadena, tamano);
    // cout << "Ceros: " << ceros << "\nUnos: " << unos << endl;
    return 0; 
}