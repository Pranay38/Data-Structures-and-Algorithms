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
ListNode* fun(ListNode* head){
    ListNode* prev=NULL;
    ListNode* cur=head;
    ListNode* next=NULL;
    while(cur){
         next=cur->next;
         cur->next=prev;
         prev=cur;
         cur=next;

    }
    return prev;
}
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
        return head;

        ListNode* ans=fun(head->next);
        head->next->next=head;
        head->next=NULL;
        return ans;

    }
};