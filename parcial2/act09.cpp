//Javier Luis Castillo Solorzano
//A01658415
#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits>
#include <queue>

using namespace std;

#define INF INT_MAX
#define MAX 20
#define Edge pair<int,int>
#define Graph vector<vector<Edge>>
#define Vertex pair<int,int> //Distancia en costo, id

// Lee los datos de las aristas (calles) y sus pesos desde la entrada estándar y actualiza la matriz de adyacencia.
// Complejidad: O(S)
void leeDatos(Graph &G, int e) {
    char u_char, v_char;
    int u, v, w;
    for (int i = 0; i < e; i++){
        cin >> u_char >> v_char >> w;
        u = u_char - 'A';
        v = v_char - 'A';
        
        Edge edge1(v, w);
        G[u].push_back(edge1);
        
        Edge edge2(u, w);
        G[v].push_back(edge2);
    }
}

// Complejidad: O(V logV)
vector<int> Dijkstra(Graph &G, int s = 0){
    //s--; 
    vector<int> dist(G.size(), INF); 
    dist[s] = 0;
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
    Vertex vs(0,s);
    pq.push(vs);
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(int j=0; j< G[u].size(); j++){
            Edge e = G[u][j];
            int v = e.first; // hacia donde llego
            int w = e.second; // costo de ir de u-> v
            if (dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                Vertex vtx(dist[v], v);
                pq.push(vtx);
            }
        }
    }
    return dist; 
}

// Encuentra el longest shortest path utilizando los valores de Djikstra
// Complejidad: O(E logV)
char longestShortest(){
    Graph G;
    int rooms, edges;
    cin >> rooms >> edges;

    G.assign(rooms, vector<Edge>());

    leeDatos(G, edges);
    vector<int> dist = Dijkstra(G);

    int max_dist = -1;
    int best_room_idx = 0;

    for (int i = 1; i < dist.size(); i++){
        if (dist[i] != INF) {
            if (dist[i] > max_dist) {
                max_dist = dist[i];      
                best_room_idx = i;       
            }
        }
    }
    return best_room_idx + 'A';
}

// Función principal
int main(){
    int casos;
    cin >> casos;
    for (int i = 1; i <= casos; i++){
        char resultado = longestShortest();
        cout << "Case " << i << ": " << resultado << endl;
    }
    return 0;
}