class Solution {
public:
    int binarySearch(vector<int>& sums, int start, int target){
        // find the first value that is greater or equal to the target

        int end = sums.size() - 1;
        int mid = -1;

        while(start < end){
            mid = (start + end) / 2;

            if(sums[mid] >= target){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }

        if(start == end) mid = start;

        return sums[mid]>=target ? mid:-1;
    }


    int minSubArrayLen(int target, vector<int>& nums) {
        int minWindow = INT_MAX;

        // commulative sum
        vector<int> sums(nums.size()+1, 0);
 
        for(int i = 1 ; i <= nums.size() ; i++){
            sums[i] = nums[i-1] + sums[i-1];
        }

        for(int start = 1 ; start < sums.size() ; start++){
            int end  = binarySearch(sums, start, target + sums[start-1]);
            if(end != -1){
                minWindow = min(minWindow, end - start + 1);
            }
        }

        return (minWindow == INT_MAX) ? 0 : minWindow;
    }
};

// Time complexity = O(n log(n)), where n: nums size (follow up question)
// Space complexity = O(n) becasue of the commulative sum array