class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        multiset<int> pq;
        vector<int> result;

        int i = 0;

        for(; i < k && i < nums.size(); i++){
            pq.insert(nums[i]);
        }

        result.push_back(*pq.rbegin());


        while(i < nums.size()){
            pq.insert(nums[i]); 

            auto it = pq.find(nums[i-k]);
            pq.erase(it);

            result.push_back(*pq.rbegin());
            i++;
        }

        return result;
    }
};
