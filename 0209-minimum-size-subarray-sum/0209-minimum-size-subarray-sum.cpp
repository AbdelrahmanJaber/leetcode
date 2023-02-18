class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window
        int left = 0;
        int right = 0;

        int sum = 0;
        int minWindow = INT_MAX;

        while(right < nums.size()){
            // extending
            sum += nums[right];

            // shrinking
            while(sum >= target){
                sum -= nums[left];
                left++;

                minWindow = min(minWindow, right - left + 2); // notice the position of left and right to determine the length equation
            }

            right++;
        }

        return minWindow == INT_MAX ? 0 : minWindow;
    }
};

// Time complexity = O(n), where n: nums size
// Space complexity = O(1)