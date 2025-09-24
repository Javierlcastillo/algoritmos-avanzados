#include <iostream>
#include <vector>
using namespace std;

vector <pair<int,int>> llenarListado(int buses){
    vector<pair<int, int>> listado;
    for(int i = 0; i < buses; i++){
        int inicio, fin;
        cin >> inicio >> fin;
        listado.push_back(make_pair(inicio, fin));
    }
    return listado;
}

void printVector(const vector<pair<int, int>>& vec) {
    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int solucion(int buses, int serval){
    if (buses == 0 || serval == 0) return 0;
    vector<pair<int, int>> listado = llenarListado(buses);
    int devolver = -1;
    int minimo = INT_MAX;
    for (int i = 0; i < listado.size(); i++){
        if (listado[i].first >= serval){
            minimo = min(listado[i].first, minimo);
            if (minimo == listado[i].first)
                devolver = i+1;
        }
        else if (listado[i].first < serval){
            while (listado[i].first < serval){
                listado[i].first += listado[i].second;
            }
            minimo = min(minimo, listado[i].first);
            if (minimo == listado[i].first){
                devolver = i+1;
            }
        }
    }
    return devolver;
}

int main(){
    int buses, serval;
    cin >> buses >> serval;
    // printVector(llenarListado(buses)); // Debugging line to print the input list
    cout << solucion(buses, serval) << endl;
    return 0; 
}