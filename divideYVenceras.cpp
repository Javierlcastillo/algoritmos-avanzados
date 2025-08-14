// Divide y Venceras
// Autor: Yo
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
vector<int> genera(int n)
{
    vector<int> resul;
    for (int i = 0; i < n; i++)
    {
        resul.push_back(rand() % 1000 + 1);
    }
    return resul;
}
void print(vector<int> &datos)
{
    for (int i = 0; i < datos.size(); i++)
    {
        cout << datos[i] << " ";
    }
    cout << endl;
}
// 
int cuentaIT(vector<int> &datos)
{
    int cont = 0;
    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i] > 100)
        {
            cont++;
        }
    }
    return cont;
}
/* Complejidad: O(n)
 * T(n) = T(n/2) + T(n/2) : se suman las llamadas recursivas de una mitad más la otra
 * T(n) = 2T(n/2)
 * O(n^log2^2) = O(n) : no hay ventaja de hacerlo iterativamente
 */
int cuentaDyV(vector<int> &datos, int ini, int fin)
{
    if (fin == ini)
        return (datos[ini]>100)? 1 : 0;
    else {
        int mitad = (ini+fin)/2;
        return cuentaDyV(datos, ini, mitad) + cuentaDyV(datos, mitad+1, fin);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> datos = genera(n);
    print(datos);
    cout << "La cantidad mayor a 100 (ITER): " << cuentaIT(datos) << endl;
    cout << "La cantidad mayor a 100 (DyV) : " << cuentaDyV(datos, 0, n - 1) << endl;
    return 0;
}
