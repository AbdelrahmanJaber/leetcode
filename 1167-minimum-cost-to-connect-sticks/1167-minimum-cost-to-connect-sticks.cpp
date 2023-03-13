class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        // using min heap
        priority_queue<int, vector<int>, greater<int>> sticksCost;

        // insert all the sticks into the min heap
        for(int i = 0 ; i < sticks.size() ; i++){
            sticksCost.push(sticks[i]);
        } // O(log 1 + log 2 + logn) = O(log n!) =  O(n logn)

        int totalCost = 0;

        // pop the top two sticks and push their cost(sum of them) again to the min heap
        while(!sticksCost.empty()){ // will loop O(n) time. It is exactly: O(n-1) because we pop twice and push once
            int firstStick = sticksCost.top();
            sticksCost.pop(); // O(log n)

            if(sticksCost.empty()){
                break;
            }

            int secondStick = 0;
            secondStick = sticksCost.top();
            sticksCost.pop(); // O(log n)

            totalCost += firstStick + secondStick;

            // push the cost again to the heap
            sticksCost.push(firstStick + secondStick); // O(log n)
        }

        return totalCost;
    }
};

// Time complexity = O(n logn + n (3 logn)) = O(n logn), where n: sticks size()
// Space complexity = O(n), due to the min heap (in the first step we push all the elements in the heap and then we start popping from it untill it becomes empty)