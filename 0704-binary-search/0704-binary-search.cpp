class Solution {
public:
    int search(vector<int>& nums, int target) {
        // binary search

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if (target > nums[mid]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return -1;
    }
};

// Time complexity = O(log n)
// Space complexity = O(1)