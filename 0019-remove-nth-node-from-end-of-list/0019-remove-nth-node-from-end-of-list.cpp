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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL  && n==1)
            return nullptr;
        ListNode* nh=head;
        int count=0;
        while(nh!=NULL)
        {
            nh=nh->next;
            count++;
        }
        count=count-n-1;
        if(count==-1)
            return head->next;
            
        nh=head;
        while(count--)
        {
            nh=nh->next;
        }
        nh->next=nh->next->next;
        
        return head;
    }
};