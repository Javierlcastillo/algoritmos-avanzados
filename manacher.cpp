//Autor: Javier Luis Castillo 
//Matricula: A016658415


#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

//Complejidad O(n)
// Función para ejecutar Manacher y devolver el palíndromo más largo
tuple<int, int> manacher(string s) {
    // 1. Transformación del string para manejar palíndromos pares e impares
    // Ejemplo: "aba" -> "^#a#b#a#$"
    string t = "^";
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$";

    int n = t.size();
    vector<int> P(n, 0); // P[i] guarda el radio del palíndromo centrado en i

    int C = 0, R = 0; // C = centro actual, R = borde derecho actual

    // 2. Recorremos todo el string transformado
    for (int i = 1; i < n - 1; i++) {
        // i_mirror es el índice espejo de i respecto a C
        int i_mirror = 2 * C - i;

        // Si i está dentro del palíndromo actual, usa el espejo como punto de inicio
        if (i < R)
            P[i] = min(R - i, P[i_mirror]);
        else
            P[i] = 0;

        // 3. Intentamos expandir alrededor de i mientras los extremos coincidan
        while (t[i + 1 + P[i]] == t[i - 1 - P[i]])
            P[i]++;

        // 4. Si expandimos más allá del borde derecho, actualizamos centro y borde
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // 5. Encontrar el palíndromo más largo
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // 6. Convertimos el índice en t a índice en s y extraemos el palíndromo
    int start = (centerIndex - maxLen) / 2;
    return make_tuple(start, maxLen);
}

int main() {
    string s;
    cin >> s;
    auto [start, maxLen] = manacher(s);
    int right_start = start + maxLen; 
    //Left
    if (start == 0)
        cout << "Left: NO LEFT PART" << endl;
    else 
        cout << "Left: " << s.substr(0, start-1) << endl; 
    
    //Middle
    cout << "Middle: " << s.substr(start,maxLen) << endl;

    //Right
    if (right_start == s.size())
        cout << "Right: " << "NO RIGHT PART" << endl;
    else
        cout << "Right: " << s.substr(right_start, s.size()) << endl;
    return 0;
}
