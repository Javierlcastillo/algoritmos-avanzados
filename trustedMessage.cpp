// ASC02 - Trusted Message
// Autor: Javier Luis Castillo Solórzano
// Matricula: A01658415

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Calcula el arreglo LPS
vector<int> computeLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0; // longitud del prefijo/sufijo previo más largo
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // retrocede a prefijo anterior
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Función de búsqueda KMP
vector<int> KMPSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> lps = computeLPS(pattern);
    vector<int> coincidencias(text.size(), true); // todos los elementos son true
    int i = 0; // índice para text
    int j = 0; // índice para pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++; j++;
        }

        if (j == m) {
            for (int h = 0; h < pattern.size(); h++){
                coincidencias[i-j+h] = false; // LOS ELEMENTOS CON FALSE SON LOS QUE SE ELIMINAN
            }
            j = lps[j - 1]; // busca siguiente ocurrencia
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    } 
    return coincidencias; 
}

string eliminarCoincidencias2(string text, string pattern, vector<int> coincidencias) {
    string copia = "";
    for (int i = 0; i < coincidencias.size(); i++){
        if (coincidencias[i] == true){
            copia = copia + text[i];
        }
    }
    return copia;
}

int main() { 
    string text, pattern;
    cin >> text;
    cin >> pattern;
    vector<int> coincidencias = KMPSearch(text, pattern);
    cout << eliminarCoincidencias2(text, pattern, coincidencias);
    return 0;
}
