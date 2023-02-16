class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int sum = 0, carry = 0, kDigit, index = num.size()-1;


        while(k > 0 || index >= 0){
            kDigit = k % 10;
            
            sum = carry;
            if(k > 0) sum += kDigit;
            if(index >= 0) sum += num[index];

            result.push_back(sum % 10);

            carry = sum / 10;
            k = k / 10;
            index--;
        }

        if(carry == 1) result.push_back(1);

        reverse(result.begin(), result.end());

        return result;
    }
};

// Time complexity = O(n + log k), where n: num size, log k: means number of digits in k
// space complexity = O(max(n, logk)) because of the result array