#include "nodoTrie.h"

class trie{
    public:
        trie();
        void insert(string word);
        bool search(string word);
    private:
        nodoTrie *root;
}

trie::trie(){
    root = new nodoTrie('\0', nulllptr);
}

bool trie::search(string word){
    nodoTrie* current = root; 
    for (int i = 0; i < word.size(); i++){
        char c = word[i];
        current = current->getChild(c);
        if (current == nullptr){
            return false; 
        }
    }
    return current->getEnd();
}

void trie::insert(string word){
    nodoTrie* current = root;
    for (int i = 0; i < word.size(); i++){
        char c = word[i];
        nodoTrie* sub = current-> getChild();
        if (sub != nullptr){
            current = sub;
        }
        else {
            current -> addChild(new nodoTrie*(c, current));
        }
    }
    current -> setEnd(true);
}
