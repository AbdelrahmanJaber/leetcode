class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // we will run the binary search in the smallest array size, to make it more efficient log(min(n, m))
        // here we will ensure that nums1 is always the smallest
        if(nums2.size() < nums1.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        // run binary search on nums1
        int low = 0;
        int high = nums1.size() - 1;

        int total_elements = nums1.size() + nums2.size();
        int number_of_left_elements = total_elements / 2;

        while(true){
            int mid = low + floor((high-low)/2.0);

            int index2 = number_of_left_elements - (mid+1) -1;

            int ALeft = (mid >= 0) ? nums1[mid] : INT_MIN;
            int ARight = (mid+1 < nums1.size()) ? nums1[mid+1] : INT_MAX;
            int BLeft = (index2 >= 0) ? nums2[index2] : INT_MIN;
            int BRight = (index2+1 < nums2.size()) ? nums2[index2+1] : INT_MAX;

            if(ALeft <= BRight && BLeft <= ARight){
                // this means the total_elements is odd
                if(total_elements & 1){
                    return min(ARight, BRight);
                }
                else{
                    return ((double)max(ALeft, BLeft) + (double)min(ARight, BRight)) / 2.0;
                }
            }
            else if(ALeft > BRight){
                high = mid - 1;
            }
            else if(BLeft > ARight){
                low = mid + 1;
            }
        }
    }
};

// Time complexity = O(log(min(n, m))), where n: nums1 size, m: nums2 size, because we run the binary search on the minimum length array
// Space cinplexity = O(1)