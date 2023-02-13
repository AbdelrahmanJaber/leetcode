class Solution {
public:
    int countOdds(int low, int high) {
        int counter = 0;

        if(low % 2 == 1){
            counter++;
            low++;
        }
        if(high % 2 == 1){
            counter++;
            high--;
        }

        counter += (high - low ) / 2;

        return counter;
    }
};