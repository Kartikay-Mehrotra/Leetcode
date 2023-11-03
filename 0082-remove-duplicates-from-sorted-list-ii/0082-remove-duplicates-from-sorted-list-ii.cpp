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
    ListNode* deleteDuplicates(ListNode* head) {
     map<int,int> mp;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            mp[curr->val]++;
            curr=curr->next;
        }
        curr=new ListNode(0);
        head=curr;
        for(auto i:mp)
        {
            if(i.second==1)
            {
                curr->next=new ListNode(i.first);
                curr=curr->next;
            }
        }
        return head->next;
        
        
    }
};