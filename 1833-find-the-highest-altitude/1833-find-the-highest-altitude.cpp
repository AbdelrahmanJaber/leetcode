class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int maxAltitude = 0;

        for(int i = 0 ; i < gain.size() ; i++){
            currentAltitude += gain[i];
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};

// Time complexity = O(n), where n: number of elements in the gain array
// Space complexity = O(1)