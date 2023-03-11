class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // follow up: time: O(m+n)
        // enhance space complexity to be O(1)
        // two pointers approach

        
        // initialize three pointers, 2 for reading and 1 for writing
        int p1 = m-1;
        int p2 = n-1;

        int pWrite = m + n - 1;

        while(p1 >= 0 && p2 >= 0){
            if(nums1[p1] > nums2[p2]){
                nums1[pWrite] = nums1[p1];
                p1--;
            }
            else{
                nums1[pWrite] = nums2[p2];
                p2--;
            }

            pWrite--;
        }

        // push the remaining elements from nums1Copy if exists
        while(p1 >= 0){
            nums1[pWrite] = nums1[p1];
            p1--;
            pWrite--;
        }

        // push the remaining elements from nums2 if exists
        while(p2 >= 0){
            nums1[pWrite] = nums2[p2];
            p2--;
            pWrite--;
        }

    }
};

// Time complexity = O(m + n)
// Space complexity = O(1)