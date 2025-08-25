//act04 - Robot
//Autor: Javier Luis Castillo 
//Matricula: A01658415

#include <iostream>
#define MAX 10
using namespace std;

void llenaTablero(int mat[MAX][MAX], int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }
}

void imprimeTablero(int mat[MAX][MAX], int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

//Complejidad O(n*m)
int resolver(int mat[MAX][MAX], int n, int m){
    int minimos[MAX][MAX];
    minimos[0][0] = mat[0][0];
    for (int i=1; i<n; i++)
        minimos[i][0] = minimos[i-1][0] + mat[i][0];
    for (int j=1; j<m; j++)
        minimos[0][j] = minimos[0][j-1] + mat[0][j];
    for (int i=1; i<n; i++){
        for (int j=1; j<m; j++){
            minimos[i][j] = mat[i][j] + min(minimos[i-1][j], minimos[i][j-1]);
        }
    }

    return minimos[n-1][m-1];
}

int main() {
    int n, m;
    int mat[MAX][MAX];
    cin >> n >> m;
    llenaTablero(mat, n, m);
    cout << resolver(mat, n, m) << endl;
    return 0;
}