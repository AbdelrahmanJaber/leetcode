/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;

        // slow, fast pointer
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(true){
            if(fast == NULL) return false;

            if(slow == fast) return true;

            slow = slow->next;
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
        }
    }
};

// Time complexity = n, where n: number of nodes in the linked list
// Space complexity = O(1)