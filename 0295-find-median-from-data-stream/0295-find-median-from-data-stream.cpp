class MedianFinder {
public:

    // Two Heaps approach (another solution, see first submissions for another solutions on the same approach)
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
    }
    
    void addNum(int num) {
        // determine which heap to push
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }

        // balancing step (In briefly: maxHeap.size() should always be eaual or greater than by just one element from minHeap.size())
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        else if(minHeap.size() > maxHeap.size()){
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
