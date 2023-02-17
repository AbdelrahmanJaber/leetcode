class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Monotonic decreasing deque
        deque<int> dq;
        vector<int> result;

        int i = 0;
        // initialize the first k elements
        for(; i < k && i < nums.size() ; i++){
            while(!dq.empty() && nums[i] > dq.back()){
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
        }
        result.push_back(dq.front());

        while(i < nums.size()){
            // remove the element from the window
            if(dq.front() == nums[i-k]){
                dq.pop_front();
            }

            while(!dq.empty() && nums[i] > dq.back()){
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
            result.push_back(dq.front());

            i++;
        }

        return result;
    }
};

// Time complexity = O(n), where n: nums.size()
// Space complexity = O(n) [ O(k) for deque + O(n - k + 1) for result array ]