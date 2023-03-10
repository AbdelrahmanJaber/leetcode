class MedianFinder {
public:

    // Two Heaps approach
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
    }
    
    void addNum(int num) {
        // push always in the max heap in the beginning
        maxHeap.push(num);

        // balancing step
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        

        // maintain size property
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }
    
    double findMedian() {
        // check if both the heaps have the same sizes
        if(minHeap.size() == maxHeap.size()){
            return (minHeap.top() + maxHeap.top()) /2.0;
        }
        else{
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 // Time complexity = for one call: addNum: O(log n), findMedian: O(1)
 // Space complexity = O(n), where n: number of elements
