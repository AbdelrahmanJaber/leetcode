class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(n logn)
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0 ; i < nums.size() ; i++){
            pq.push(nums[i]);
        } // O(n log n)
        
        int index = 0;
        int counter = 0;
            
        while(!pq.empty() && index < nums.size()){
            if(pq.top() > nums[index]){
                counter++;
                index++;
            }
            pq.pop();
        }
        
        
    
        
        return counter;
        
    }
};