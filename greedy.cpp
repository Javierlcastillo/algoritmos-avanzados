#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int solve(int n){
    vector<int> datos(n);
    for (int i=0; i<n; i++){
        cin >> datos[i];
    }
    sort(datos.begin(), datos.end(), greater<int>());
    int salida = 0; 
    for (int i =0; i<n; i++){
        salida = salida*10  + datos[i];
    }
    return salida;
}
int main() {
    int n;
    cin >> n; 
    cout << solve(n) << endl;

    return 0;
}