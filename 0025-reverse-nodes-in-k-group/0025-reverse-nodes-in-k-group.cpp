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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // brute force (using stack)

        stack<ListNode*> nodes;
        ListNode* resultHead=nullptr;
        ListNode* resultTail=nullptr;


        while(true){
            
            ListNode* tmp = head;
            int i = 0;
            for(; i < k ; i++){
                if(head == NULL) break;

                ListNode* node= new ListNode(head->val);
                nodes.push(node);
                head=head->next;
            }

            // remaining nodes less than k
            if(i < k){
                while(tmp != nullptr){
                    if(resultHead == nullptr){
                        resultHead = tmp;
                        resultTail = resultHead;
                        tmp = tmp -> next;
                    }
                    else{
                        resultTail -> next = tmp;
                        resultTail = resultTail -> next;
                        tmp = tmp -> next;
                    }
                }
                break;
            }

            else{
                while(!nodes.empty()){
                    // ListNode* currentNode = nodes.top();

                    if(resultHead == nullptr){
                        resultHead = nodes.top();
                        resultTail = resultHead;
                        nodes.pop();
                    }
                    else{
                        resultTail->next = nodes.top();
                        resultTail = resultTail -> next;
                        nodes.pop();
                    }
                }
            }

        }

        return resultHead;
    }
};