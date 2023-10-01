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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* odd=new ListNode(-1);
        ListNode* even=new ListNode(-1);
        ListNode* o=odd,*e=even;
        int t=-1;
        while(head!=NULL)
        {
            if(t& 1)
            {
                odd->next=new ListNode(head->val);
                odd=odd->next;
            }
            else
            {
                even->next=new ListNode(head->val);
                even=even->next;
            }
            head=head->next;
            t++;
        }
        o=o->next;
        odd->next=e->next;
        return o;
    }
};