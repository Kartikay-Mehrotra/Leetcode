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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* les=new ListNode(0);
        ListNode* gre=new ListNode(0);
        ListNode *l=les,*g=gre;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                les->next=new ListNode(head->val);
                les=les->next;
            }
            else
            {
                gre->next=new ListNode(head->val);
                gre=gre->next;
            }
            head=head->next;
        }
        l=l->next;
        les->next=g->next;
        return l==NULL?g->next:l;
    }
};