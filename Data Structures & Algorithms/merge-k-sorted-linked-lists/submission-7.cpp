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
        if(lists.size()==0) return NULL;
        priority_queue<pair<int,ListNode*>,
        vector<pair<int,ListNode*>>,
        greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            ListNode*temp=lists[i];
            if(temp){
                pq.push({temp->val,temp});
            }
        }
        if(pq.size()==0) return NULL;
        ListNode*dummy=new ListNode(-1);
        ListNode*curr=dummy;
        while(!pq.empty()){
            ListNode*node=pq.top().second;
            int value=pq.top().first;
            ListNode*Node=new ListNode(value);
            pq.pop();
            if(node->next){
                pq.push({node->next->val,node->next});
            }
            curr->next=Node;
            curr=curr->next;
        }
        return dummy->next;
    }
};
