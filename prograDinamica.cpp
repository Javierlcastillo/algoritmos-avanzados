//triangulo suma
#include <iostream>
#include <array>
using namespace std;
#define MAX 10

void llenaTriangulo (int mat[MAX][MAX], int tamano) {
    for (int i=0; i < tamano; i++){
        for (int j = 0; j <= i; j++){
            cin >> mat[i][j];
        }
    } 
}

void print(int mat[MAX][MAX], int n) {
    for (int i=0; i < tamano; i++){
        for (int j = 0; j <= i; j++){
            cout <<  mat[i][j] << "\t";
        }
        cout << endl;
    } 
}

void solve(int mat[MAX][MAX], int n){
    for(int i=n-2; i>=0; i--) {
        for (int j=0; j<=i; j++) {
            mat[i][j] += max(mat[i+1][j], mat[i+1][j+1]);
        }
    }
    return mat[0][0];
}
int main() {
    int mat[MAX][MAX];
    int t, n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        llenaTriangulo(mat,n);
        print(mat, n);
        //cout << solve(mat,n);
    }
    return 0; 
}