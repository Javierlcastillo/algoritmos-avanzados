#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// class Nodo{
//     public:
//         int inicio, siguiente;
//         Nodo* hijo;
//         Nodo(){
//             inicio = -1;
//             siguiente = NULL;
//             hijo = nullptr;
//         }
// };

vector <pair<int,int>> llenarListado(int buses){
    vector<pair<int, int>> listado;
    for(int i = 0; i < buses; i++){
        int inicio, fin;
        cin >> inicio >> fin;
        listado.push_back(make_pair(inicio, fin));
    }
    return listado;
}
int solucion(int buses, int serval){
    if(buses == 0 || serval == 0) return 0;
    vector<pair<int, int>> listado = llenarListado(buses);
    int minimo = serval; 
    int devolver;
    for(int i = 0; i < listado.size(); i++){
        if(listado[i].first < minimo){
            listado[i].first = listado[i].first + listado[i].second;
            if (listado[i].first >= serval){
                if (minimo > listado[i].first){
                    minimo = listado[i].first;
                    devolver = i+1;
                }
            }
        }
        else if (minimo > listado[i].first){
            minimo = listado[i].first;
            devolver = i;
        }
    }
    return devolver;
}

int main(){
    int buses, serval;
    cin >> buses >> serval;
    cout << solucion(buses, serval) << endl;
    return 0; 
}