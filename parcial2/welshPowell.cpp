#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;



struct color{
    int conex; // cantidad de conexiones
    int vtx; // numero de vetice
};

bool my_comp(const color &c1, const color &c2){
    if (c1.conex == c2.conex){
        return c1.vtx > c2.vtx;
    }
    return c1.vtx > c2.conex;
}
void leeArcos(bool matAdj[100][100], vector<color> &vtxColor, int m){
    int u, v;
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        u--;
        v--;
        matAdj[u][v] = matAdj[v][u] = true;
        vtxColor[u].conex++;
        vtxColor[v].conex++;
    }
}

bool canColor(bool matAdj[100][100], unordered_set<int> &conj, int j ){
    for (int num : conj){
        if (matAdj[num][j]){
            return false;
        }
    }
    return true;
}
// Complejidad O(m^2)
vector<int> colorGraph(bool matAdj[100][100], vector<color> &vtxColor){
    int numColor = 0;
    int n = vtxColor.size();
    vector<int> colored(n,0);
    for (int a = 0; a < n; a++){
        int i = vtxColor[a].vtx;
        if(!colored[i]){
            colored[i] = ++numColor;
            unordered_set<int> conj;
            conj.insert(i);
            for (int b = a+1; b<n; b++){
                int j = vtxColor[b].vtx;
                // Verificar: 
                // j no ha sido coloreado
                // j no tenga adjacencia con i\
                // j no tenga adjeacencia con alguien que haya sido coloreado con numColor
                if(!colored[j] && canColor(matAdj, conj, j)){
                    colored[j] = numColor;
                    conj.insert(j);
                }
            }
        }
    }
    return colored;
}

int main(){
    // n = vertices , m = cantidad de arcos
    int n,m;
    cin >> n >> m; 
    bool matAdj[100][100] = {false};

    vector<color> vtxColor;
    color c;
    for (int i = 0; i < n ; i++){
        c.conex = 0;
        c.vtx = i;
        vtxColor.push_back(c);
    }
    leeArcos(matAdj, vtxColor, m);
    sort(vtxColor.begin(), vtxColor.end(), my_comp);
    vector<int> colored = colorGraph(matAdj, vtxColor);
    for (int i = 0; i < n; i++){
        cout <<  "Vertex " << (i+1) << " with color " << colored[i] << endl;  
    }
    return 0; 
}

/*
7 11
1 2
1 3
1 4
2 3
2 5
3 4
3 5
4 5 
4 6
5 7
6 7
*/