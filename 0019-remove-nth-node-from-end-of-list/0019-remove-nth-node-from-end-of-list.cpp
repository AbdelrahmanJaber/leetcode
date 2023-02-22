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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* currentNode = head;
    ListNode* NodeBeforeDeletion = head;
    
    for(int i = 0 ; i < n ; i++){
        currentNode = currentNode-> next;
    }
    
    if(currentNode == NULL){
        return head -> next;
    }
    
    while(currentNode -> next != NULL){
        currentNode = currentNode -> next;
        NodeBeforeDeletion = NodeBeforeDeletion -> next;
    }

    NodeBeforeDeletion -> next = NodeBeforeDeletion -> next -> next;

    return head;
}
};

/* Time complexity = O(n)
    Space complexity = O(1)
    */