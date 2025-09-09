#include <iostream>
#include <vector>
using namespace std;

bool dangerousSituation(string entrada){
    int contador = 1;
    for (int i = 1; i < entrada.size(); i++){
        if (entrada[i] == entrada[i - 1]){
            contador++;
            if (contador == 7){
                return true;
            }
        } else {
            contador = 1;
        }
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
