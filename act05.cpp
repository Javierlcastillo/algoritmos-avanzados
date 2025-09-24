// ACT05 - Railroad
// Autor: Javier Luis Castillo Solórzano
// Matrícula: A01658415

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <typename T>
void imprimirVector(const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <typename T>
void llenarVectores(int length, vector<T> &listado){
    for (int i = 0; i < length; i++){
        T valor;
        cin >> valor; 
        listado.push_back(valor);
    }
}


template <typename T>
bool trainCombiner(int a, int b){
    vector<T> solucion, valores_a, valores_b;
    llenarVectores(a, valores_a);
    llenarVectores(b, valores_b);
    llenarVectores(a+b, solucion);
    for (auto i : solucion){

    }
    return true;
}

int main() {
    int a = -1, b = -1;
    cin >> a >> b;
    while (a != 0 && b != 0){
        bool entrada = trainCombiner<int>(a, b);
        cin >> a >> b;
    }

    return 0; 
}