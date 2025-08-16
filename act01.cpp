// act01 - Changing the product name
// Autor: Javier Luis Castillo Solórzano
// Matrícula: A01658415

#include <iostream> 
using namespace std;

string renombre1(int n, string nombre){
    if (n==0){
        return nombre;
    } else {
        char a,b;
        cin >> a >> b;
        for (int i=0; i < nombre.length(); i++){
            if (nombre.at(i) == a){
                nombre.replace(i, 1, 1, b);
            } else if (nombre.at(i) == b){
                nombre.replace(i, 1, 1, a);
            }
        } 
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