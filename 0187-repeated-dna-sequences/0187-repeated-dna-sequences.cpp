class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};

        unordered_set<string> uset;

        unordered_set<string> uset_result;
        vector<string> result;

        int index = 0;
        while(index <= s.size() - 10){
            string str = s.substr(index, 10);
            if(!uset.count(str)){
                uset.insert(str);
            }
            else{
                uset_result.insert(str);
            }

            index++;
        }

        for(auto it = uset_result.begin() ; it != uset_result.end() ; it++){
            result.push_back(*it);
        }

        return result;
    }
};