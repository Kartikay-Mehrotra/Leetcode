/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* curr=head;
        Node* temp;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=temp;
            curr=temp;
        }
        curr=head;
        while(curr!=NULL)
        {
            if(curr->random)
            {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        Node* copy=head->next;
        Node* org=head;
        temp=copy;
        while(org && copy)
        {
            org->next=copy->next;
            copy->next=copy->next?copy->next->next:copy->next;
            copy=copy->next;
            org=org->next;
        }
        return temp;
    }
};