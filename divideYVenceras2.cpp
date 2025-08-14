#include <iostream>
#include <vector>
#include <cstdlib>
#define MAX 128
using namespace std;

void genera(int datos[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            datos[i][j] = rand() % 1000 + 1;
        }
    }
}
void print(int datos[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << datos[i][j] << " ";
        }
        cout << endl;
    }
}
// Complejidad O(n^2)
int cuentaIT(int datos[MAX][MAX], int n)
{
    int cont = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (datos[i][j] > 100)
                cont++;
        }
    }
    return cont;
}
// Complejidad: O(n^2)
int cuentaDyV(int datos[MAX][MAX], int rI, int rF, int cI, int cF)
{
    if (rI == rF && cI == cF)
        return (datos[rI][cI] > 100)? 1 : 0;
    else {
        int rM = (rF-rI)/2;
        int cM = (cF-rI)/2;
        return  cuentaDyV(datos, rI, rM, cI, cM) + 
        cuentaDyV(datos, rM+1, rF, cI, cM) + 
        cuentaDyV(datos, rI, rM, cM+1, cF) + 
        cuentaDyV(datos, rM+1, rF, cM+1, cF);
    }
}
int main()
{
    int mat[MAX][MAX];
    int n;
    cin >> n;
    genera(mat, n);
    print(mat, n);
    cout << "La cantidad mayor a 100 (ITER): " << cuentaIT(mat, n) << endl;
    cout << "La cantidad mayor a 100 (DyV) : " << cuentaDyV(mat, 0, n - 1, 0, n - 1)
         << endl;
    return 0;
}
