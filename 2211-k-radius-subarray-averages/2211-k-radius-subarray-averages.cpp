class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // using prefix sum
        int n = nums.size();
        vector<long long> prefixSum(n+1);

        prefixSum[0] = 0;
        prefixSum[1]=nums[0];
        for(int i = 2 ; i <= n ; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        vector<int> avgerages;
        for(int i = 0 ; i < n ; i++){
            if(i - k < 0 || i + k >= n){
                avgerages.push_back(-1);
                continue;
            }

            int avg = (prefixSum[i+1+k] - prefixSum[i-k]) / (2*k +1);
            avgerages.push_back(avg);
        }

        return avgerages;
    }
};

// Time complexity = O(n)
// Space complexity = O(n)