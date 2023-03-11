class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // use min heap to store elements from both arrays
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> values;
        vector<int> output;

        int index1 = 0;
        int index2 = 0;

        bool shouldPush1 = true;
        bool shouldPush2 = true;

        while(index1 < m || index2 < n){
            if(index1 < m && shouldPush1){
                values.push({nums1[index1], 1});
            }
            if(index2 < n && shouldPush2){
                values.push({nums2[index2], 2});
            }

            // take the smaller value
            pair<int, int> smallerValue = values.top();
            output.push_back(smallerValue.first);

            if(smallerValue.second == 1) {
                index1++;
                shouldPush1 = true;
                shouldPush2 = false;
            }
            else{
                index2++;
                shouldPush2 = true;
                shouldPush1 = false;
            }

            values.pop();

        }

        while(!values.empty()){
            pair<int, int> smallerValue = values.top();
            output.push_back(smallerValue.first);
            values.pop();
        }

        for(int i = 0 ; i < output.size() ; i++){
            nums1[i] = output[i];
        }
    }
};