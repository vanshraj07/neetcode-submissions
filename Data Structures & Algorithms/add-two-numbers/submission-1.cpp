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
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        ListNode*dummy=new ListNode(-1);
        ListNode*curr=dummy;
        int rem=0;
        while(temp1 && temp2){
            int sum=(temp1->val+temp2->val+rem);
            ListNode*node=new ListNode(sum%10);
            curr->next=node;
            curr=curr->next;
            rem=sum/10;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp2!=NULL){
            while(temp2){
                int sum=(temp2->val+rem);
                ListNode*Node=new ListNode(sum%10);
                curr->next=Node;
                curr=curr->next;
                rem=sum/10;
                temp2=temp2->next;
            }
        }
        if(temp1!=NULL){
            while(temp1){
                int sum=(temp1->val+rem);
                ListNode*Node=new ListNode(sum%10);
                curr->next=Node;
                curr=curr->next;
                rem=sum/10;
                temp1=temp1->next;
            }
        }
        if(rem!=0){
            ListNode*node=new ListNode(rem);
            curr->next=node;
            curr=curr->next;
        }
        return dummy->next;
    }
};
