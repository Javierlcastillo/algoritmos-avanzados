//Z-Function
//Autor: Javier Luis Castillo
//Matricula: a01658415

#include <iostream>
#include <vector>
#include <string>

using namespace std; 

vector<int> z_Function(string p, string t) {
    string texto = p + "$" + t;
    int n = texto.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && texto[z[i]] == texto[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
int main() {
    // t -> texto
    // p==> patron
    string t, p;
    cin >> p >> t;
    vector<int> zF = z_Function(p,t);
    bool entre = false; 
    for (int i = 0; i<zF.size(); i++){
        if(zF[i] == p.size())
        cout << i-p.size() << " ";
        entre = true;
    }
    if (!entre){
        cout << "No se encontraron coincidencias." << endl;
    }

    return 0;
};
