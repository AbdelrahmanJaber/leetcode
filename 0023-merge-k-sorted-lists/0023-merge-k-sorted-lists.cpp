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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // naive approach using array of pointers: vector<int, ListNode*>
        // Time conplexity = O(k (k * (n1 + n2 + n3 + ...))) = O(k * N), where N: number of all nodes in all linked lists
        // Space complexity = O(k)

        // We can optimize this by using a min heap to store the vlues
        // Time complexity = O(log k * (n1 + n2 + n3)) = O(logk * N), where N: number of all nodes in all linked lists
        // Space complexity = O(k)

        // initialize the priority_queue (min heap)
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> values;

        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i] != nullptr){
                values.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* pre = new ListNode(-1);
        ListNode* tail = pre;

        while(!values.empty()){
            tail -> next = new ListNode(values.top().first);
            tail = tail -> next;

            ListNode* nextNode = values.top().second->next;
            if(nextNode != nullptr){
                values.push({nextNode->val, nextNode});
            }

            values.pop();
        }

        return pre->next;
    }
};