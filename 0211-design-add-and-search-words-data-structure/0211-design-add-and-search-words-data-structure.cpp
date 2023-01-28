class trieNode{
public:
    // Note: it is preferred to make them private and implement get and put for eath member
    char ch;
    unordered_map<char, trieNode*> umap;
    bool isCompletedWord;

    trieNode(char ch, bool isCompletedWord){
        this->ch = ch;
        this->isCompletedWord = isCompletedWord;
    }
};

class WordDictionary {
private:
    trieNode* root;

public:
    WordDictionary() {
        root = new trieNode('\0', false);
    }
    
    void addWord(string word) {
        trieNode* current = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(!current->umap.count(word[i])){
                trieNode* node = new trieNode(word[i], false);
                current->umap[word[i]] = node; 
            }
            current = current->umap[word[i]];
        }

        current->isCompletedWord = true;
    }

    void searchWord(string word, trieNode* current, int index, bool& result){
        // base case
        if(index == word.size()){
            result = result || current->isCompletedWord;
            return;
        }

        if(word[index] == '.'){
            for(auto it: current->umap){
                searchWord(word, it.second, index+1, result);
                if(result) return;
            }
        }
        else{
            if(!current->umap.count(word[index])){
                return;
            }
            searchWord(word, current->umap[word[index]], index+1, result);
            if(result) return;
        }
    }

    
    bool search(string word) {
        trieNode* current = root;
        bool result=false;
        searchWord(word, current, 0, result);

        return result;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */