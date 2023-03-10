class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> maxHeapForSmallerElements;
        priority_queue<int, vector<int>, greater<int>> minHeapForGreaterElements;
        vector<double> result;
        unordered_map<int, int> invalidElements;

        // process first k elements
            // push all k elements into the maxHeap
            for(int i = 0 ; i < k ; i++){
                maxHeapForSmallerElements.push(nums[i]);
            }
            // pop larger k/2 elements from maxHeap and push them into minHeap
            for(int i = 0 ; i < k/2 ; i++){
                minHeapForGreaterElements.push(maxHeapForSmallerElements.top());
                maxHeapForSmallerElements.pop();
            }

            int idx = k;

        // begin an infinite loop
        while(true){
            // calculate the median
            double median;
            if(k % 2 == 1){
                median = maxHeapForSmallerElements.top();
            }
            else{
                median = ((double)minHeapForGreaterElements.top() + (double)maxHeapForSmallerElements.top()) / 2.0;
            }
            result.push_back(median);

            // base case
            if(idx >= nums.size()){
                break;
            }

            // take the in_num and out_num
            int in_num = nums[idx];
            int out_num = nums[idx-k];
            idx++;

            // initialize the balance variable
            int balance = 0;
            
            // push the in_num to the heap
            if(maxHeapForSmallerElements.empty() || in_num <= maxHeapForSmallerElements.top()){
                maxHeapForSmallerElements.push(in_num);
                balance++;
            }
            else{
                minHeapForGreaterElements.push(in_num);
                balance--;
            }

            // handle the out_num
            invalidElements[out_num]++;
            // this means out_num exists in the maxHeapForSmallerElements
            if(out_num <= maxHeapForSmallerElements.top()){
                balance--;
            }
            // this means out_num exists in minHeapForGreaterElements
            else{
                balance++;
            }

            // do the balancing
            // this means that max_heap have more elements than min_heap
            if(balance > 0){
                minHeapForGreaterElements.push(maxHeapForSmallerElements.top());
                maxHeapForSmallerElements.pop();
                balance--;
            }
            else if(balance < 0){
                maxHeapForSmallerElements.push(minHeapForGreaterElements.top());
                minHeapForGreaterElements.pop();
                balance++;
            }

            // remove the invalidElements if they exists on the top of the heaps
            while(invalidElements[maxHeapForSmallerElements.top()]){
                invalidElements[maxHeapForSmallerElements.top()]--;
                maxHeapForSmallerElements.pop();
            }

            while(!minHeapForGreaterElements.empty() && invalidElements[minHeapForGreaterElements.top()]){
                invalidElements[minHeapForGreaterElements.top()]--;
                minHeapForGreaterElements.pop();
            }

        }
        
        return result;
        }
};