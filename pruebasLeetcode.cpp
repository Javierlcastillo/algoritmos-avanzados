#include <iostream>
#include <unordered_map>

using namespace std;

void printer(unordered_map<char, int> um){
    for (auto i : um)
        cout << i.first << " " << i.second << endl;
}

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int>  mag;
    for (int i = 0; i < magazine.size(); i ++){
        mag[mag[i]] += 1;
    }
    printer(mag);
    for(int i = 0; i < ransomNote.size(); i++){
        if (mag.find(ransomNote[i]) == mag.end())
            return false;
        else if (mag[ransomNote[i]] <= 0)
            return false;
        else
            mag[i]--; 
    }
    return true;
}


int main(){
    string note, mag;
    cin >> note >> mag;
    cout << canConstruct(note, mag); 
    return 0; 
}