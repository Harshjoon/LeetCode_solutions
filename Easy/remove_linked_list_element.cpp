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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL ) return head;
        ListNode * temp = head->next;
        while(head->val==val){
            head = temp;
            if(temp==NULL) break;
            temp = temp->next;
        }
        if (head == NULL ) return head;
        ListNode * prev = head;
        while( temp ){
            if( temp->val == val ){
                prev->next = temp->next;
                temp = temp->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};