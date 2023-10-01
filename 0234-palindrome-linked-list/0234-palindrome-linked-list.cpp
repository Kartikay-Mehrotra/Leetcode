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
    ListNode* middle(ListNode* head)
    {
        if(head==NULL|| head->next==nullptr)
            return head;
        ListNode* slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* l=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return l;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        ListNode* mid=middle(head);
        ListNode* rev=reverse(mid);
        
        while(head!=NULL && rev!=NULL)
        {
            if(head->val!=rev->val)
                return false;
            head=head->next;
            rev=rev->next;
        }
        return true;
    }
};