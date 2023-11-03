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
    int length(ListNode* head)
    {
        if(head==NULL)
            return 0;
        return 1+length(head->next);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int len=length(head);
        if(len<k)
            return  head;
        int count=k;
        ListNode* prev=NULL,*n=NULL,*curr=head;
        while(count--)
        {
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};