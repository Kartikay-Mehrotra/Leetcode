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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        if(count<k)
            return head;
        ListNode* prev=NULL;
        ListNode* nex=NULL;
        temp=head;
        int c=k;
        while(c--)
        {
            nex=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nex;
        }
        head->next=reverseKGroup(temp,k);
        return prev;
        
    }
};