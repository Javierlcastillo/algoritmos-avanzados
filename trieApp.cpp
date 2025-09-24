#include "trie.h"
#include <iostream>

using namespace std;

int main(){
    trie miTrie;
    int n;
    string dato;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> dato; 
        miTrie.insert(dato);
    }
    cout << "========================" << endl;
    int q;
    cin >> q;
    for (int i=0; i<q; i++){
        cin >> dato;
        if (miTrie.search(dato)){
            cout << "si esta" << endl;
        }
        else {
            cout << "no esta" << endl;
        }
    }
    return 0;
}
