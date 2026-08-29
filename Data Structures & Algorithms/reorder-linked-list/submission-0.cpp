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
private:
    ListNode*Reverse(ListNode*head){
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp){
            ListNode*next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        int size=0;
        ListNode*temp=head;
        while(temp){
            temp=temp->next;
            size++;
        }
        temp=head;
        int halfsize=(size+1)/2;
        while(temp && halfsize>1){
            halfsize--;
            temp=temp->next;
        }
        ListNode*tempHead=temp->next;
        temp->next=NULL;
        ListNode*newHead=Reverse(tempHead);
        ListNode*curr=head;
        temp=head->next;
        ListNode*node=newHead;
        while(temp && node){
            curr->next=node;
            node=node->next;
            curr=curr->next;
            curr->next=temp;
            temp=temp->next;
            curr=curr->next;
        }
        while(temp){
            curr->next=temp;
            temp=temp->next;
            curr=curr->next;
        }
        while(node){
            curr->next=node;
            node=node->next;
            curr=curr->next;
        }
    }
};
