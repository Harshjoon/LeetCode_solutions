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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int v=0,r=0;
        ListNode*ans = new ListNode;
        ListNode*temp = ans;

        while(l1 || l2){
            v = r;
            if(l1!=NULL){
                v+=l1->val;
                l1 = l1->next;
            } 
            if(l2!=NULL){
                v+=l2->val;
                l2 = l2->next;  
            }
            //v = v+r;
            ListNode*temp_ = new ListNode;
            temp_->val  = v%10;
            r = v/10;
            temp_->next = NULL;
            temp->next = temp_;
            temp = temp->next;
        }
        if(r){
            ListNode*temp_ = new ListNode;
            temp_->val  = 1;
            temp_->next = NULL;
            temp->next = temp_;
        }
        return ans->next;
    }
};