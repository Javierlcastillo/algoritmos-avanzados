// Act03 - Invest
// Autor: Javier Luis Castillo Solorzano 
// Matricula: A01658415

#include <iostream>
#include <array>
#define MAX 49
using namespace std;


void solve(int arr[MAX], int &buy, int &sell){
    int d;
    cin >> d;
    for (int j=d; j>0; j--){
        cin >> arr[j];
        if (j == d){
            buy = j;
            sell = j;
        }
        else if (arr[j] < arr[buy]){
            cout << arr[j];
            buy = j;
        }
        if (arr[j]-arr[buy] > arr[sell]-arr[buy]){
            sell = j;
        }
    }
}

int main() {
    int n, price; 
    cin >> n;
    int arr[MAX]; 
    for (int i=0; i<n; i++){
        int buy, sell;
        solve(arr, buy, sell);
        cout << "Buy in " << buy << ", sell in " << sell << endl; 
    }
    return 0;
}
