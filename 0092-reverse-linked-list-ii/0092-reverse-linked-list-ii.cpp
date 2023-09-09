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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* dummy=new ListNode(0,head);
        ListNode* curr=head,*leftp=dummy;
        for(int i=0;i<left-1;i++)
        {
            leftp=curr;
            curr=curr->next;
        }
        ListNode* prev=NULL;
        for(int i=0;i<(right-left+1);i++)
        {
            ListNode* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        leftp->next->next=curr;
        leftp->next=prev;
        return dummy->next;
        
    }
};