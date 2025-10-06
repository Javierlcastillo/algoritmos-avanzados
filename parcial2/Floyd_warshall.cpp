// Javier Luis Castillo
// A01658415


#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define INF INT_MAX
#define Edge pair<int, int>
#define Graph vector<vector<Edge>> //Grapho representatod en lista de adjacencias
#define Vertex pair<int,int> //Distancia en costo, id
#define MAX 10


void initMatAdj (int matAdj[MAX][MAX]){
    for (int i = 0; i < MAX; i++){
        matAdj [i][i] = 0;
        for (int j = i + 1; j < MAX; j++){
            matAdj[i][j] = matAdj [j][i] = INF;
        }
    }
}


void leeDatos( int matAdj[MAX][MAX], Graph &G, int e) {
    int u, v, w;

    for (int i = 0; i < e; i++){

        cin >> u >> v >> w;
        matAdj[u - 1][v - 1] = matAdj [v - 1][u - 1] = w;


        Edge edge1(v - 1, w);
        G[u - 1].push_back(edge1);
        
        Edge edge2(u - 1, w);
        G[v - 1].push_back(edge2);


    }
}


void print(int matAdj [MAX][MAX], Graph &G){
    cout << "Matriz de Adjacencias" << endl;
    for (int i = 0; i < G.size(); i++){
        for (int j = 0; j < G.size(); j++){
            cout << matAdj[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl << "Lista de Adjacencias" << endl;
    for (int i = 0; i < G.size(); i++){
        cout << i << " ==> ";
        for (int j = 0; j < G[i].size(); j++){
            cout << "(" << G[i][j].first << "," << G[i][j].second << ") ";
        }
        cout << endl;
    }
}

//O(n^3) Floyd
void Floyd(int matAdj[MAX][MAX], int v){
    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(matAdj[i][k] != INF && matAdj[k][j] != INF && matAdj[i][j] > matAdj[i][k]+matAdj[k][j])
                    matAdj[i][j] = matAdj[i][k]+matAdj[k][j]; 
            }
        }
    }
}
// O(V logV)
vector<int> Dijkstra(Graph &G, int s){
    s--; 
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
void checarTrayectoria(int p[MAX][MAX], int i, int j){
    if (p[i][j] != -1){
        checarTrayectoria(p, i, p[i][j]);
        cout << p[i][j] + 1 << "-";
        checarTrayectoria(p, p[i][j], j);
    }
}

void despliega(int matAdj[MAX][MAX], Graph &G, int s, vector<int> &dist){
    s--; 
    cout << "Floyd: " << endl;
    for (int j=0; j<G.size(); j++){
        if(s != j)
            cout << s+1 << "-->" << j+1 << ": " << matAdj[s][j] << endl;
    }
    cout << "Dijikstra: " << endl;
    for(int i = 0; i < dist.size(); i++){
        if(s != 0){
            cout << s+1 << "--> " << i+1 << ": " << dist[i] << endl; 
        }
    }
}

int main () {


    int matAdj[MAX] [MAX];
    int v, e, s;
    cin >> v >> e >> s;

    Graph G(v);
    initMatAdj(matAdj);
    leeDatos(matAdj, G, e);
    //print(matAdj, G);
    Floyd(matAdj, v);
    vector<int> dist = Dijkstra(G, s);
    despliega(matAdj, G, s, dist);

    return 0;
}

/* 7 9 3 
1 2 50 
1 3 60 
2 4 120 
2 5 90 
3 6 50 
4 6 80 
4 7 70 
5 7 40 
6 7 140 
 
Sample Output 
 
Floyd: 
3 --> 1: 60 
3 --> 2: 110 
3 --> 4: 130 
3 --> 5: 200 
3 --> 6: 50 
3 --> 7: 190 
Dijkstra: 
3 --> 1: 60 
3 --> 2: 110 
3 --> 4: 130 
3 --> 5: 200 
3 --> 6: 50 
3 --> 7: 1907*/