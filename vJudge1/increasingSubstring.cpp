#include <iostream>
#include <vector>
using namespace std;

vector<int> llenarVector(int tamano){
    vector<int> vec;
    for(int i = 0; i < tamano; i++){
        int valor;
        cin >> valor;
        vec.push_back(valor);
    }
    vec.push_back(-1); // para evitar errores de rango
    return vec;
}

int solucion(int tamano){
    vector<int> vec = llenarVector(tamano);
    vector<int> dp(tamano+1, 1);
    int cont = 1;
    for(int i = 0; i < tamano; i++){ // si el siguiente es mayor que el actual
        if (vec[i+1] > vec[i]){
            cont++;
            dp[i+1] = max(dp[i], cont); // se obtiene el mayor entre el maximo y el contador
        }
        else {
            cont = 1;
            dp[i+1] = dp[i];
        }
        //cout << "terminamos vuelta " << i << endl;
    }
    return dp[tamano];
}

int main(){
    int tamano;
    cin >> tamano;
    cout << solucion(tamano) << endl;
    return 0;
}