#include <iostream>

using namespace std;

bool solve(int entrada)
{
    vector<int> Ts;
    vector<int> Ms;
    for (int j = 0; j < largo, j++){
        // utilizamos los indices del string y basados en el lugar del string podemos determinar si hay una T despues del indice
        // de la m. (la tablita del wicho de T's y M's).
        if (caden[j] == 'M')
        {
            Ms.push_back(j);
        }
        else {
            Ts.push_back(j);
        }
    }
    if (Ms.size() * 2 != Ts.size()){
        return false;
    }
    for (int i=0; i<Ms.size(); i++){
        if (!(Ts < Ms[i] && Ms[i] < Ts[Ms.size()+i]))
            return false; 
    }
    return true;
}

int main() {
    int entradas; 
    cin >> entradas;
    for (int i=0; i<entrada; i++){
        int largo;
        string cadena;
        cin >> largo;
        cin >> cadena;
        cout << (solve(largo, cadena)? "YES" : 'NO');
    }
    return 0; 
}
