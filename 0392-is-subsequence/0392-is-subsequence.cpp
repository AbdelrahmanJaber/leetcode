class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_ptr = 0; // O(1)

        // loop through t_string
        for(int i = 0 ; i < t.size() ; i++){ // O(t), where t: size of string t
            // I have found the character in t, so increment the s_ptr
            if(s[s_ptr] == t[i]){
                s_ptr++;
            }

             
            if(s_ptr == s.size()){
                return true;
            }

        }

        // if(s_ptr == s.size()){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        // check if the s_ptr has reached the end of the string s
        return s_ptr == s.size(); // O(1)
    }
};

// Time complexity = O(t), where t: size of string t
// Space complexity = O(1)