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
        if(head==NULL) return NULL;
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp){
            ListNode*node=temp->next;
            temp->next=prev;
            prev=temp;
            temp=node;
        }
        return prev;
    }
    ListNode*getKthNode(ListNode*head,int k){
        ListNode*temp=head;
        k-=1;
        while(temp && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp){
            ListNode*KthNode=getKthNode(temp,k);
            if(KthNode==NULL){
                if(prev){
                    prev->next=temp;
                    break;
                }
            }
            ListNode*nextNode=KthNode->next;
            KthNode->next=NULL;
            Reverse(temp);
            if(temp==head){
                head=KthNode;
            }
            else{
                prev->next=KthNode;
            }
            prev=temp;
            temp=nextNode;
        }
        return head;
    }
};
