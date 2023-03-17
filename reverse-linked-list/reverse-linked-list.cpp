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
    ListNode* reverseList(ListNode* head) {
        // reverse the linked list recursively

        // base case
        if(head == nullptr || head -> next == nullptr){
            return head;
        }

        // recursive call
        ListNode* p = reverseList(head->next);

        // reverse the pointers
        head->next->next = head;
        head->next = nullptr;

        // return the reversed linkedlist
        return p;
    }
};

// Time complexity = O(n), where n: number of nodes in the linked list
// Space complexity = O(n)