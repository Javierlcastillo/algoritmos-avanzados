#include <iostream>
#include <vector>
#include <algorithm> // Para std::max

#define MAXOBJ 11
#define MAXMOCH 101

using namespace std;

struct obj{
    int valor, peso;
    float valpeso;
};

int MochilaDP(vector<obj> &datos, int &cantDP, int N, int PESO){
    cantDP = 0;
    int matDP[MAXOBJ][MAXMOCH] = {0};
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= PESO; j++){
            cantDP++; // Contando cada paso en la matriz como una operación
            // Si el peso del objeto actual es mayor que la capacidad de la mochila en esta iteración
            if(datos[i-1].peso > j){
                // No podemos incluir el objeto, así que tomamos el valor de la fila anterior
                matDP[i][j] = matDP[i-1][j];
            }
            else{
                // Comparamos el valor de no incluir el objeto vs. incluirlo
                matDP[i][j] = max(matDP[i-1][j], datos[i-1].valor + matDP[i-1][j-datos[i-1].peso]);
            }
        }
    }
    return matDP[N][PESO];
}

int MochilaDyV(vector<obj> &datos, int &cantDyV, int N , int PESO){
    // Caso base: no hay más objetos o la capacidad de la mochila es 0 o menor.
    if (N == 0 || PESO <= 0){
        return 0;
    }
    cantDyV++; // Contando cada llamada recursiva como una operación

    // El objeto actual no cabe en la mochila.
    if(datos[N-1].peso > PESO){
        // Pasamos al siguiente objeto sin agregarlo.
        return MochilaDyV(datos, cantDyV, N-1, PESO);
    }
    // Si el objeto cabe, decidimos si es óptimo incluirlo.
    else{
        // Retornamos el máximo valor entre no incluir el objeto y sí incluirlo.
        return max(MochilaDyV(datos, cantDyV, N-1, PESO), // Opción 1: No incluir el objeto.
                    datos[N-1].valor + MochilaDyV(datos, cantDyV, N-1, PESO-datos[N-1].peso)); // Opción 2: Incluir el objeto.
    }
}

int main(){
    int v, p , N, PESO;

    cin >> N >> PESO;
    vector<obj> datos(N);
    for(int i = 0; i < N; i++){
        cin >> v >> p;
        datos[i].valor = v;
        datos[i].peso = p;
        datos[i].valpeso = v*(1.0)/p;
    }
    int cantDP = 0;
    cout << "mochila con DP: " << MochilaDP(datos, cantDP, N, PESO) << endl;
    cout << "Con " << cantDP << " operaciones" << endl;
    cout << "=====================" << endl;

    int cantDyV = 0;
    cout << "mochila con DyV: " << MochilaDyV(datos, cantDyV, N, PESO) << endl;
    cout << "Con " << cantDyV << " operaciones" << endl;
    cout << "=====================" << endl;
}
