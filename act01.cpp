// act01 - Changing the product name
// Autor: Javier Luis Castillo Solórzano
// Matrícula: A01658415

#include <iostream> 
using namespace std;

string renombre(int n, string nombre) {
    if (n < 1) {
        return nombre;
    }
    else if (n == 1){
        int letra, cambio;
        cin >>  letra >> cambio;
        for (int i = 0; i < nombre.length(); i++) {
            if (nombre[i] == letra){
                nombre[i] = cambio;
            }
        }
        return nombre;
    }
    else 
        return "fuck this shit";
}
int main() { 
    int designers; 
    cin >> designers; 
    string nombre; 
    cin >> nombre;
    string resultado = renombre(designers, nombre);
    cout << resultado;

    return 0; 
}