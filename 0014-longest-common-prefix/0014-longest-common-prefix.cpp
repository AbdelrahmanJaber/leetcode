class Solution {
public:
     
    bool isStartWith(string word, string prefix){
        for(int i = 0 ; i < prefix.size(); i++){
            if(word[i] != prefix[i]){
                return false;
            }
        }
        return true;
    }

    string commonPrefix(string word, string prefix){
        while(true){
            if(word.empty() || prefix.empty()){
                return "";
            }

            if(prefix.size() > word.size()){
                prefix.pop_back();
                continue;
            }

            if(isStartWith(word, prefix)){
                return prefix;
            }
            else{
                prefix.pop_back();
            }
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for(int i = 1 ; i < strs.size() ; i++){
            prefix = commonPrefix(strs[i], prefix);
        }

        return prefix;
    }
};