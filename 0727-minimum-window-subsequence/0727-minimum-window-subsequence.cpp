class Solution {
public:
    string minWindow(string s1, string s2) {
        int s1_index = 0;
        int s2_index = 0;

        int start = 0;
        int end = 0;

        int min_length = INT_MAX;
        string substring = "";

        while(s1_index < s1.size()){ //O(n)

            // try to find the subsequence
            if(s1[s1_index] == s2[s2_index]){
                s2_index++;
            }

            if(s2_index == s2.size()){
                end = s1_index;
                start = s1_index;
                s2_index--;

                while(s2_index >= 0){
                    if(s1[start] == s2[s2_index]) s2_index--;
                    start--;
                } //O(m)

                if(end - start < min_length){
                    min_length = end - start;
                    substring = s1.substr(start + 1, end - start);
                }
                
                s2_index = 0;
                s1_index = start+2;
            }

            s1_index++;
        }

        return substring;
    }
};

// Time complexity = O(n * m), where n: s1 size() and m: s2 size() // outer loop O(n), inner loop O(m)
// Space complexity = O(n) due to result string, in the worst case if the result substring is the whole s1 (ex: s1 = abbbbf, s2 = af)