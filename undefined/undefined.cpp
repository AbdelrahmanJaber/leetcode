class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long result=0;
        
        vector<bool> marked(nums.size(), false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0 ; i < nums.size() ; i++){
            pq.push({nums[i], i});
        }
        
        while(!pq.empty()){
            pair<int, int> element = pq.top();
            int index = element.second;
            
            if(!marked[index]){
                result += element.first;
                
                marked[index] = true;
            
                if(index + 1 < nums.size()){
                    marked[index+1] = true;
                }
                
                if(index - 1 >= 0){
                    marked[index-1] = true;
                }
            }
            
            pq.pop();
        }
        
        return result;
        
    }
};