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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head||!head->next||!head->next->next)
        return {-1,-1};
        int mn=INT_MAX;
        int mx=INT_MIN;
        int j=1,start=-1,end=-1;
        ListNode* before=head;
        ListNode* cur=head->next;
        ListNode* after=cur->next;
        while(after){
            if((before->val<cur->val&&cur->val>after->val)||(before->val>cur->val&&cur->val<after->val)){
            if(start==-1)
            start=j;
            else{
                mn=min(mn,j-end);
                mx=max(mx,j-start);
            }
            end=j;
            }
            before=cur;
            cur=after;
            after=after->next;
            j++;

        }
        if(mn==INT_MAX||mx==INT_MIN)
        return {-1,-1};
        return {mn,mx};

    }
};