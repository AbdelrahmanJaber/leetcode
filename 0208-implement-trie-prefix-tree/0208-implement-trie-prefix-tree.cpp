class Node{
public:
    char ch;
    unordered_map<char, Node*> uset;
    bool isCompleteWord;

    Node(char ch, bool isCompleteWord){
        this->ch = ch;
        this->isCompleteWord = isCompleteWord;
    }
};

class Trie {
private: 
        Node* root;

public:

    Trie() {
        root = new Node('\0', false);
    }
    
    void insert(string word) {
        Node* current = root;

        for(int i = 0 ; i < word.size() ; i++){
            if(!current->uset.count(word[i])){
                Node* node = new Node(word[i], false);
                current->uset[word[i]] = node;
                current = node;
            }
            else{
                current = current->uset[word[i]];
            }
            
        }
        current->isCompleteWord = true;
    }
    
    bool search(string word) {
        Node* current = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(!current->uset.count(word[i])){
                return false;
            }
            current = current->uset[word[i]];
        }

        return current->isCompleteWord;
    }
    
    bool startsWith(string prefix) {
        Node* current = root;
        for(int i = 0 ; i < prefix.size() ; i++){
            if(!current->uset.count(prefix[i])){
                return false;
            }
            current = current->uset[prefix[i]];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */