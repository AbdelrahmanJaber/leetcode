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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // using in place reversal of linked list, O(1) space, one pass

        if(left == right) return head;

        ListNode* start = nullptr;
        ListNode* curr = head;
        ListNode* previousHeadOfPortion = nullptr;
        int counter = 1;

        while(counter < left){
            start = curr;
            curr = curr -> next;

            counter++;
        }

        previousHeadOfPortion = curr;
        ListNode* prev = nullptr;
        while(counter <= right){
            ListNode* next = curr -> next;

            curr->next = prev;
            prev = curr;
            curr = next;

            counter++;
        }
        
        // connect the first part with the reversed potion
        if(start){
            start -> next = prev;
        }

        // connect the reversed portion with the end of the list
        previousHeadOfPortion -> next = curr;


        return left == 1? prev : head;
    }
};

// Time complexity = O(n), where n: number of nodes in the linked list
// Space complexity = O(1)