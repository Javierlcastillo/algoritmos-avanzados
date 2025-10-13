// ACT07 - longest common subsequence
// Autor: Javier Luis Castillo
// Matricula: A0167658415

#include <iostream>
#include <vector>
using namespace std; 

void printDP(const vector<vector<int>>& dp) {
    for (const auto& row : dp) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}

int lcs(int casos, string u, string d){
    string uno = "$" + u;
    string dos = "$" + d;
    vector<vector<int>> dp(uno.size(), vector<int>(dos.size(),0)); 
    for (int i=1; i<uno.size(); i++){
        for (int j=1; j<dos.size(); j++){
            if(uno[i] == dos[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // cout << "\nMatriz de DP para '" << u << "' y '" << d << "':" << endl;
    // printDP(dp);

    return dp[uno.size()-1][dos.size()-1];    
}
int main() {
    int cases;
    cin >> cases;
    vector<int> resultados;
    for (int i=0; i < cases; i ++){
        string uno, dos;
        cin >> uno;
        cin >> dos;
        resultados.push_back(lcs(cases, uno, dos));
    }
    for(int i=0; i < cases; i++)
        cout << "Case " << i+1 << ": " << resultados[i] << endl;
    return 0;
}