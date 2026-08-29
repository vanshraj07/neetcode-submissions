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
        ListNode*temp=head;
        if(temp->next==NULL) return NULL;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        int k=size-n-1;
        temp=head;
        if(k<0){
            ListNode*node=temp->next;
            temp->next=NULL;
            return node;
        }
        temp=head;
        while(temp && k>0){
            k--;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;

    }
};
