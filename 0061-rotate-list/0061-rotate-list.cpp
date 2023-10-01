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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int count=0;
        ListNode* th=head;
        ListNode* prev=NULL;
        while(th)
        {
            prev=th;
            th=th->next;
            count++;
        }
        prev->next=head;
        k=k%count;
        k=count-k;
        th=head;
        while(k--)
        {
            prev=th;
            th=th->next;
        }
        prev->next=NULL;
        return th;
    }
};