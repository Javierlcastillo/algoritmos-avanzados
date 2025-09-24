// Act06 - Longest Common Substring
//Autor: Javier LUis Castillo Solorzano
//Matricula: A01658415

#include <iostream>
#include <vector>
using namespace std;

//Complejidad O(n*m(min(n,m))) = O(n^3)
int longestPt2(){
    string s1, s2;
    int longest = 0; 
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s1.size(); i++){
        for (int j = 0; j < s2.size(); j++){
            int x = 0;
            if (s1[i] == s2[j]){
                while(i+x < s1.size() && j+x < s2.size() && s1[i+x] == s2[j+x]){
                    x++;
                }
                if(x > longest) longest = x;
            }
        }
    }
    return longest;
}

//Complejidad O(n*m)
int longestSubstring(){
    string s1, s2;
    cin >> s1;
    cin >> s2; 
    
    int n, m, longest = 0; 
    n = s1.size(); 
    m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                longest = max(longest, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return longest;
}

int main(){
    int cases; 
    cin >> cases;
    for (int i = 0; i < cases; i++){
        cout << longestSubstring();
    }
    return 0; 
}