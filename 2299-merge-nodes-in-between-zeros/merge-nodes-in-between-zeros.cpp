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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* parent=head;
        ListNode* cur=head->next;
        int sum=0;
        while(cur!=NULL){
            if(cur->val==0){
                head->val=sum;
                sum=0;
                if(cur->next!=NULL)
                head=head->next;
            }
            sum+=cur->val;
            cur=cur->next;
        }
        head->next=NULL;
        return parent;
    }
};