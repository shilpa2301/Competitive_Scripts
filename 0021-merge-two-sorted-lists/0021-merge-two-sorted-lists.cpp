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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        ListNode *merged=new ListNode();
        merged=NULL;
        ListNode *head1=list1;
        ListNode *head2=list2;
        ListNode *head3=NULL;
        
        while(head1 && head2)
        {
            //ListNode *newnode=new ListNode();
           // newnode=NULL;
            if(head1->val < head2->val)
            {
                ListNode *newnode=new ListNode(head1->val);
                //newnode->val=head1->val;
                //newnode->next=NULL;
                if(!merged)
                {
                    merged=newnode;
                    head3=merged;
                }
                else
                {
                    merged->next=newnode;
                    merged=merged->next;
                }
                
                head1=head1->next;
                
            }
            else
            {
                ListNode *newnode=new ListNode(head2->val);
                //newnode->val=head2->val;
                //newnode->next=NULL;
                //merged->next=newnode;
                if(!merged)
                {
                    merged=newnode;
                    head3=merged;
                }
                else
                {
                    merged->next=newnode;
                    merged=merged->next;
                }
                head2=head2->next;
            }
        }
         if(!head1)
             merged->next=head2;
        if(!head2)
            merged->next=head1;
        return head3;
    }
};