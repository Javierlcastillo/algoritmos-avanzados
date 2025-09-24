// ACT05 - Railroad - versión DP
// Autor: Javier Luis Castillo Solórzano
// Matrícula: A01658415

#include <iostream>
#include <vector>
using namespace std;

bool railroadDP(const vector<int>& train1, const vector<int>& train2, const vector<int>& solution) {
    int N1 = train1.size();
    int N2 = train2.size();

    vector<vector<bool>> dp(N1+1, vector<bool>(N2+1, false));
    dp[0][0] = true;

    for (int i = 0; i <= N1; ++i) {
        for (int j = 0; j <= N2; ++j) {
            int k = i + j;
            if (dp[i][j] && k < solution.size()) {
                // Tomar de train1
                if (i < N1 && train1[i] == solution[k]) {
                    dp[i+1][j] = true;
                }
                // Tomar de train2
                if (j < N2 && train2[j] == solution[k]) {
                    dp[i][j+1] = true;
                }
            }
        }
    }


    return dp[N1][N2];
}

int main() {
    int N1, N2;
    cin >> N1 >> N2;
    while(N1 != 0 && N2 != 0){

    vector<int> train1(N1);
    vector<int> train2(N2);
    vector<int> solution(N1+N2);

    for (int i = 0; i < N1; ++i){
        cin >> train1[i];
    }
    for (int i = 0; i < N2; ++i){
        cin >> train2[i];
    }
    for (int i = 0; i < N1+N2; ++i){
        cin >> solution[i];
    }

    if (railroadDP(train1, train2, solution)) {
        cout << "possible" << endl;
    } else {
        cout << "not possible" << endl;
    }
    cin >> N1 >> N2; 
}

    return 0;
}
