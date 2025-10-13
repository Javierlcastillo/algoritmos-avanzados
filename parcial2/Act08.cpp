//Javier Luis Castillo Solorzano
//A01658415
#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits>
#include <queue>    

using namespace std;

#define INF INT_MAX
#define Edge pair<int,int>
#define Graph vector<vector<Edge>>

// Descripcion: Inicializa la matriz de adyacencia.
// Complejidad: O(C^2), donde C es el número de nodos.
void initMatAdj (vector<vector<int>> &matAdj, int C){ 
    for (int i = 0; i < C; i++){
        matAdj [i][i] = 0;                  //DISTANCIA ES 0 DE UN NODO A SI MISMO
        for (int j = i + 1; j < C; j++){
            matAdj[i][j] = matAdj [j][i] = INF; //Grafo no dirigido
        }
    }
}

// Lee los datos de las aristas (calles) y sus pesos desde la entrada estándar y actualiza la matriz de adyacencia.
// Complejidad: O(S)
void leeDatos(vector<vector<int>> &matAdj, int e) {
    int u, v, w;
    for (int i = 0; i < e; i++){
        cin >> u >> v >> w;
        matAdj[u - 1][v - 1] = matAdj [v - 1][u - 1] = w; // Manejo de datos en matriz de adjacencias
    }
}

//Implementa el algoritmo de Floyd-Warshall
//busca minimizar la máxima arista en el camino entre dos nodos.
// Complejidad: O(C^3)
void Floyd(vector<vector<int>> &matAdj, int v){
    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                matAdj[i][j] = min(matAdj[i][j], max(matAdj[i][k], matAdj[k][j]));
            }
        }
    }
}

// Procesa un único caso de prueba.
// Devuelve una cola con los resultados
// Complejidad: O(C^3 + S + Q)
queue<int> intensityLevel(int caseNum){
    int C, S, Q;
    cin >> C >> S >> Q;

    vector<vector<int>> matAdj(C, vector<int>(C,0));
    initMatAdj(matAdj, C);
    leeDatos(matAdj, S);
    Floyd(matAdj, C);
    queue<int> resultados;
    for (int i = 0; i < Q; i++){
        int c1, c2;
        cin >> c1 >> c2;
        resultados.push(matAdj[c1-1][c2-1]); //  indexacion (1-based a 0-based)
    }
    return resultados;
}

// Función principal
int main(){
    int casos;
    cin >> casos; 
    for (int i = 1; i <= casos; i++){
        queue<int> resultados = intensityLevel(i);
        cout << "Case " << i << ":" << endl;
        while (!resultados.empty()){
            if (resultados.front() == INF) {
                cout << "no path" << endl;
            } else {
                cout << resultados.front() << endl;
            }
            resultados.pop();
        }
    }
    return 0;
}

