class Solution {
public:
    vector<pair<char, int>> constructCharCount(string st){
        vector<pair<char, int>> st_map;
        char ch = st[0];
        int char_count = 1;
        
        for(int i = 1 ; i < st.size() ; i++){
            if(ch == st[i]){
                char_count++;
            }
            else{
                st_map.push_back({ch, char_count});
                ch = st[i];
                char_count = 1;
            }
        }
        st_map.push_back({ch, char_count});

        return st_map;
    }
    
    bool canStretch(vector<pair<char, int>>& s_map, vector<pair<char, int>>& w_map){
        if(s_map.size() != w_map.size()){
            return false;
        }
        
        for(int i = 0 ; i < s_map.size() ; i++){
            if(w_map[i].first != s_map[i].first){
                return false;
            }
            
            if(w_map[i].second > s_map[i].second){
                return false;
            }
            
            if(s_map[i].second < 3){
                if(s_map[i].second != w_map[i].second){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    int expressiveWords(string s, vector<string>& words) {
        int counter = 0;
        
        vector<pair<char, int>> s_map;
        vector<pair<char, int>> w_map;
        
        s_map = constructCharCount(s);
        
        for(int i = 0 ; i < words.size() ; i++){
            w_map = constructCharCount(words[i]);
            
            // check if we can stretch w to s
            if(canStretch(s_map, w_map)){
                counter++;
            }

        }
        return counter;
    }
};


// Time complexity = s (becasue of constructCharCount) + words.length(m(becasue of constructCharCount) + 
// m(because of canStretch)), where s: length of s string, words.length = n, m: max string size in words
// = O(s + n.m)
// Space complexity = O(s + m)

// Note we can consider s and m are the same since the worrst case will be both in same size
// so we can change every s to m 


// ---***&&&***--- //