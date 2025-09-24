#include <iostream>
#include <vector>
using namespace std;

bool dangerousSituation(string entrada){
    int contador = 0;
    char valor = 'j';
    for (int i = 0; i < entrada.size(); i++){
        if (entrada[i] == valor){
            contador++;
            if (contador == 7){
                return true;
            }
        } else {
            contador = 0;
        }
        valor = entrada[i];
    }
    return false; 
}

int main(){
    string entrada;
    cin >> entrada;
    string resultado = dangerousSituation(entrada)? "YES" : "NO";
    cout << resultado << endl;
    return 0;
}
