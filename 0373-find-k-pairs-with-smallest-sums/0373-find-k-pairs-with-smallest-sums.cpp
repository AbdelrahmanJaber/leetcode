class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // initialize a priority_queue (min heap)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> sums;

        // push all the pairs from all elements from nums1 with first element from nums2
        for(int i = 0 ; i < nums1.size() ; i++){
            sums.push({nums1[i] + nums2[0], {i, 0}});
        }


        vector<vector<int>> output;

        while(k-- && !sums.empty()){
            // pop the first element and push it to the result
            int first = sums.top().second.first;
            int second = sums.top().second.second;
            output.push_back({nums1[first], nums2[second]});
            sums.pop();

            // add next pair to the mn heap
            if(second + 1 < nums2.size()){
                sums.push({nums1[first] + nums2[second+1], {first, second+1}});
            }
        }

        return output;
    }
};

// Time complexity = O(n logn + k logn)), n: nums1.size(), m: nums2.size()
// Note that when we push all the pairs from nums1 with firts element with nums2: this will cost: n logn, after that we will do k times: pop and push (the size will still n)  

// Space complexity = O(n), when we first push all the pairs from nums1 with first element from nums2, then I will keep pop and push (size will still the same)