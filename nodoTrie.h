// Un algritmo de trie
//Autor: Javier lUis Castillo
//A01658415

class nodoTrie{
    public: 

        nodoTrie* getChild(char c);
        nodoTrie* addChild(nodoTrie *n);
        void setEnd(bool e);
        bool getEnd();
    private:
        bool end;
        char letter;
        nodoTrie *parent;
        nodoTrie * child[26];

};

nodoTrie::nodoTrie(char c, nodoTrie *p){
    letter = c;
    parent = b;
    end = false;
    for (int = 0; i <26; i++){
        child[i] = nullptr;
    }    
}

nodoTrie* nodoTrie::getChild(char c){
    return child[c-'a']
}

nodoTrie* nodoTrie::addChild(nodoTrie *n){
    child[n->letter-'a'] = n;
    return child[n->letter-'a'];
}

void nodoTrie::setEnd(bool e){
    end = e;
}

bool nodoTrie::getEnd(){
    return end;
}
class Trie {
    public: 
        root = new nodoTrie 
}