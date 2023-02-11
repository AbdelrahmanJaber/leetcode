class Solution {
public:

    int calculateNextStep(int index, vector<int>& nums){
        
        int nextIndex = index + nums[index];
        if(nextIndex < 0){
            nextIndex = (abs(nextIndex) % nums.size()) * -1;
            nextIndex = nums.size() + nextIndex;
        }
        else{
            nextIndex = nextIndex % nums.size();
        }

        return nextIndex;
    }


    bool circularArrayLoop(vector<int>& nums) {
        // slow, fast pointers approach

        if(nums.size() == 1)return false;

        for(int i = 0 ; i < nums.size() ; i++){
            bool direction = nums[i] > 0; // trur: forward, false: backward

            int left = i;
            int right = calculateNextStep(i, nums);

            if(i == calculateNextStep(i, nums)) continue; // loop with one element

            while(true){
                if((nums[left] > 0) != direction || (nums[right] > 0) != direction) break;

                if(left == calculateNextStep(left, nums) ||
                    right == calculateNextStep(right, nums)
                ) break; // loop with one element

                if(left == right) return true;

                left = calculateNextStep(left, nums);

                if((nums[calculateNextStep(right, nums)] > 0) != direction) break;
                right = calculateNextStep(calculateNextStep(right, nums), nums);
            }
        }

        return false;
    }
};


/*
[-1 , -2 , -3 , -4 , -5 , 6]
  0    1    2    3    4   5 

i = 0
direction = false (backward)


left = 0
right = 5

*/