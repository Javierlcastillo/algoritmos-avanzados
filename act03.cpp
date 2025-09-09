// Act03 - Invest
// Autor: Javier Luis Castillo Solorzano 
// Matricula: A01658415

#include <iostream>
#define MAX 50
using namespace std;

//complejidad O(D)
void solve(int arr[MAX], int &buy, int &sell){
    int d;
    cin >> d;
    int minIndex = 1;
    int minPrice;
    cin >> arr[1];
    minPrice = arr[1];
    buy = 1;
    sell = 1;
    int maxProfit = -1;
    for (int j=2; j<=d; j++){
        cin >> arr[j];
        int profit = arr[j] - minPrice;
        if (profit > maxProfit){
            maxProfit = profit;
            buy = minIndex;
            sell = j;
        }
        if (arr[j] < minPrice){
            minPrice = arr[j];
            minIndex = j;
        }
    }
}

//Complejidad O(N*D)
int main() {
    int n; 
    cin >> n;
    int arr[MAX]; 
    for (int i=0; i<n; i++){
        int buy, sell;
        solve(arr, buy, sell);
        cout << "Buy in " << buy << ", sell in " << sell << endl; 
    }
    return 0;
}
