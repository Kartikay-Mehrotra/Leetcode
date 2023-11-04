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
class comp{
    public:
    bool operator()(const ListNode* a,const ListNode* b)
    {
        return a->val>b->val;
    }
};
class Solution {
public:
  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> pq;
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        for(int i=0;i<lists.size();i++)
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        
        while(pq.size())
        {
            ListNode* t=pq.top();
            pq.pop();
            temp->next=t;
            temp=temp->next;
            if(t->next)
            pq.push(t->next);
        }
        return head->next;
    }
};