class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    vector<vector<int>> counts(nums.size() + 1);

    unordered_map<int, int> umap;
    for(int element: nums) {
        umap[element]++;
    }

    for(auto it: umap){
        counts[it.second].push_back(it.first);
    }

    for(int i = counts.size() - 1 ; i >=0 ; i--){
        if(k == 0){
            break;
        }

        for(int j = 0 ; j < counts[i].size(); j++){
            result.push_back(counts[i][j]);
            k--;
        }
    }

    return result;
}
};

// Time complexity = O(n), where n: length of the nums
// Space complexity = O(n)