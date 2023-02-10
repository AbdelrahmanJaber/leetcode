class Solution {
public:
    int sumOfSquares(int number){
        int sum = 0;

        while(number > 0){
            sum += (number%10) * (number%10);
            number /= 10;
        }

        return sum;
    }

    bool isHappy(int n){
        // slow, fast pointer approach

        if(n == 1) return true;

        int slow = sumOfSquares(n);
        int fast = sumOfSquares(sumOfSquares(n));

        while(true){
            if(slow == fast && fast != 1) return false;

            if(fast == 1) return true;

            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }
    }
};

// Time complexity = O(i), where i: number of iterations to get the number 1 or the number of iterations to detect a cycle
// Sapce complexity = O(1)
