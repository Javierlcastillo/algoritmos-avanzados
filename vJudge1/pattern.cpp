#include <iostream>
#include <vector>

using namespace std;

int solucion(string s, string p){
    int completado = 0;
    for (int i = 0; i <= s.size() - p.size(); i++){
        bool coincidencia = true;
        for (int j = 0; j < p.size(); j++){
            if (s[i+j] != p[j]){ /* aumentamos el valor de i con cada iteracion de j para que "acompane" al patron. */
                coincidencia = false;
                break;
            }       /* Si el patron no coincide pasamos a la siguiente iteracion de i 
                        si el patron si coincide, se queda el true */
        }
        if (coincidencia)
            completado++;
    }
    return completado;
}

int main(){
    string s, pattern;
    cin >> s;
    cin >> pattern;
    int resultado = solucion(s, pattern);
    cout << resultado << endl;
}