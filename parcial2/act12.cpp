// Modificado Por Javier Luis Castillo
// A01658415

// MST (Primm y Kruskal)
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
#include <queue>
#include <cmath>
#include <iomanip>
#include <cfloat>

#define INF DBL_MAX

using namespace std;

struct Point {
    double x, y;
};

// Calculo de distancia entre pecas
double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

struct Graph{
	// V = Cantidad de nodos (Vertex)
	int V;
    double costMSTPrim;
	vector<vector<pair<int, double>>> adjList;		// Lista de Adj utilizado en Prim

    double costMSTKruskal;
	vector<pair<double, pair<int, int>>> edges;	// Utilizar en Kruskal
	vector<pair<int, int>> selectedEdgesK;		// Arcos seleccionados por Kruskal


	vector<pair<int, int>> selectedEdgesP;		// Arcos seleccionados por Prim
	
    Graph(int V){
		this->V = V;
		adjList.resize(V);
		costMSTKruskal = costMSTPrim = 0.0;
	}

	// u = salida del arco
	// v = llegada del arco
	// w = costo del arco
	void addEdge(int u, int v, double w){ // -> u vetice1, v vertice2, w costo
		edges.push_back({w, {u, v}}); // -> utilizado en kruskal
		adjList[u].push_back({v,w}); // -> utilizado en PRIM
		adjList[v].push_back({u,w}); // -> utilizado en PRIM
	}

	void primMST();
	void kruskalMST();
    vector<int> dijkstra(int s);
    void printEdgesP();
    void printEdgesK();
};


//Disjoint Sets (Union-Find) - Para Kruskal
struct DisjointSets{
	int *parent, *rank;
	int n;
	DisjointSets(int n){
		this->n = n;
		parent = new int[n+1];
		rank = new int[n+1];
		for (int i=0; i<=n; i++){
			rank[i] = 0;
			parent[i] = i;
		}
	}
	int find(int u){
		if (u != parent[u]){
			parent[u] = find(parent[u]);
		}
		return parent[u];
	}
	void merge(int x, int y){
		x = find(x);
        y = find(y);
		if (rank[x] > rank[y]){
			parent[y] = x;
		}
		else{
			parent[x] = y;
		}
		if (rank[x] == rank[y]){
			rank[y]++;
		}
	}
};

// Complejidad: O(V^2)
void Graph::primMST(){
    if (V == 0) {
        costMSTPrim = 0;
        return;
    }
	int selSource = 0;
	costMSTPrim = 0.0; 
	unordered_set<int> selected;
	unordered_set<int> missing;
	selected.insert(0);
	for(int i=1; i<V; i++) {
		missing.insert(i);
	}
	int connected = V-1;
    int selVertex = -1;

	while (connected > 0) {
		double minCost = INF;
		for(auto it1:selected){
			for(auto it2: adjList[it1]){
				if(missing.find(it2.first) != missing.end() && it2.second < minCost){
					minCost = it2.second;
					selVertex = it2.first;
					selSource = it1;
				}
			}
		}
        if (minCost == INF) break; // Grafo no conectado

		costMSTPrim += minCost;
		selected.insert(selVertex);
		missing.erase(selVertex);
		selectedEdgesP.push_back({selSource, selVertex});
		connected--;
	}
}

void Graph::printEdgesP(){
	cout << "Selected Edges Prim: ";
	for (auto it:selectedEdgesP){
		cout << "(" << it.first << ", " << it.second << ") ";
	}
	cout << endl;
}

// Complejiodad: O(E logE)
void Graph::kruskalMST(){
	sort(edges.begin(), edges.end());
	DisjointSets ds(V);
	costMSTKruskal = 0;
	for(auto it:edges){
		int p1 = ds.find(it.second.first);
		int p2 = ds.find(it.second.second);
		if(p1 != p2){
			costMSTKruskal += it.first;
			selectedEdgesK.push_back({it.second});
			ds.merge(it.second.first, it.second.second);
		}
	}
}

void Graph::printEdgesK(){
	cout << "Selected Edges Kruskal: ";
	for (auto it:selectedEdgesK){
		cout << "(" << it.first << ", " << it.second << ") ";
	}
	cout << endl;
}


int main(){
    int n;
    cin >> n;
    
    vector<Point> freckles(n);
    for(int i=0; i<n; ++i){
        cin >> freckles[i].x >> freckles[i].y;
    }

    Graph g(n);

    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            double distance = dist(freckles[i], freckles[j]);
            g.addEdge(i, j, distance);
        }
    }

    g.primMST();

    cout << fixed << setprecision(2) << g.costMSTPrim << endl;
	
	return 0;
}