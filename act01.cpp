// act01 - Changing the product name
// Autor: Javier Luis Castillo Solórzano
// Matrícula: A01658415

#include <iostream> 
using namespace std;

/* Funcion que reemplaza las letras dentro de un string dependiendo el input
 * Complejidad: O(n*m) = O(nm)
 */

string renombre1(int n, string nombre){
    if (n==0){
        return nombre;
    } else {
        char a,b;
        cin >> a >> b;
        // se recorre el string m veces O(m)
        for (int i=0; i < nombre.length(); i++){
            if (nombre.at(i) == a){
                nombre[i] = b;
            } else if (nombre.at(i) == b){
                nombre[i] = a;
            }
        } 
        // recursividad ocurre n veces O(n)
        return renombre1(n-1, nombre);
    }
}

int main() { 
    int designers; 
    cin >> designers; 
    string nombre; 
    cin >> nombre;
    string resultado = renombre1(designers, nombre);
    cout << resultado; 
    return 0; 
}