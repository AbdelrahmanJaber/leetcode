class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int k = 10; // because we need 10-letter-long sequences
        if(s.size() <= 10) return {};

        // using rolling hash
        int base = 4; // since max number of nucleotides = 4

        unordered_map<char, int> umap; // map each nucleotides with number
        umap['A'] = 1;
        umap['C'] = 2;
        umap['G'] = 3;
        umap['T'] = 4;

        int hashing = 0;
        unordered_set<int> hashValues;
        unordered_set<string> setValues;
        vector<string> result;

        int index = 0;
        // calculate the hash for the first k char
        for(; index < k ; index++){
            hashing += umap[s[index]] * pow(4 , k - (index + 1)); // becasue we are 0-indexed // i = index + 1
        }
        hashValues.insert(hashing);


        while(index < s.size()){
            // remove the first element from the hash
            hashing -= umap[s[index-k]] * pow(base, k-1); // becasue first element in the window has i = 1

            // multiply the hashing by 4 to uodate the location
            hashing *= 4;

            // add the new element to the hashing
            hashing += umap[s[index]] * pow(4, k - k); // becasue last element in the hash has i = k

            if(hashValues.count(hashing)){
                setValues.insert(s.substr(index - k + 1, k));

            }
            else{
                hashValues.insert(hashing);
            }

            index++;
        }


        for(auto it = setValues.begin() ; it != setValues.end() ; it++){
            result.push_back(*it);
        }

        return result;

    }
};


// Time complexity = O(n), where n: size of string s

// Sapce complexity = O(n-k+1) where k = 10 in this question and n-k+1 is the total number of subsets which in the worst case the hashValues will 
// contains n-k+1 values. Note: we have ignored the space for the result output