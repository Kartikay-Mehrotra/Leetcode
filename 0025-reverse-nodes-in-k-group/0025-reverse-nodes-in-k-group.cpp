class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        if(count<k)
            return head;
        
        count=k;
        temp=head;
        ListNode* prev=NULL;
        ListNode* nex=NULL;
        while(temp!=NULL && count--)
        {
            nex=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nex;
        }
        head->next=reverseKGroup(temp,k);
        return prev ;
    }
};