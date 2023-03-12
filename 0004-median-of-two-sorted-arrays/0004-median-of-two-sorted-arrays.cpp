class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // naive approach
        vector<int> mergedArray(nums1.size()+nums2.size(), 0);
        int i = 0;

        for(; i < nums1.size() ; i++){
            mergedArray[i] = nums1[i];
        }

        for(int j = 0 ; j < nums2.size() ; j++){
            mergedArray[i+j] = nums2[j];
        }

        sort(mergedArray.begin(), mergedArray.end());

        double median;
        if(mergedArray.size() % 2 == 1){
            median = mergedArray[mergedArray.size() / 2];
        }
        else{
            median = ((double) mergedArray[mergedArray.size() / 2] + (double) mergedArray[(mergedArray.size()/2) - 1]) / 2.0;
        }

        return median;
    }
};