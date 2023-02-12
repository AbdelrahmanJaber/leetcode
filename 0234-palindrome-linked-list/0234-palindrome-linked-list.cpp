/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nodesValues;

        ListNode* current = head;
        while(current != NULL){
            nodesValues.push_back(current->val);
            current = current -> next;
        }


        for(int i = 0 ; i < nodesValues.size()/2 ; i++){
            if(nodesValues[i] != nodesValues[nodesValues.size()-i-1]) return false;
        }

        return true;
    }
};

// Time complexity = O(n), where n: number of nodes in the linked list
// Space complexity = O(n) because of the nodesValues array