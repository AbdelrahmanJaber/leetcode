class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> numbers;
    int K;

    KthLargest(int k, vector<int>& nums) {
        K = k;

        for(int i = 0 ; i < nums.size() ; i++){
            numbers.push(nums[i]);
        }

        // pop from the heap untill we have heap length == k
        while(numbers.size() > k){
            numbers.pop();
        }
    }
    
    int add(int val) {
        numbers.push(val);

        if (numbers.size() > K){
            numbers.pop();
        }

        return numbers.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */