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
    void updateList(
        ListNode* starter, 
        ListNode* ender, 
        unordered_map<int, ListNode*> &mp,
        int sum) {

        if (starter == NULL) return;
        ListNode* it = starter->next;
        int total = sum;
        
        while (it != NULL) {
            total += it->val;
            mp[total] = NULL;
            
            if (it == ender)
                break;
            
            it = it->next;
        }
        
        starter->next = ender->next;
        mp[sum] = starter;
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* newHead = new ListNode(0, head), *last;
        unordered_map<int, ListNode*> mp;
        mp[0] = newHead;
        
        int sum = 0;

        while (head != NULL) {
            sum += head->val;
            updateList(mp[sum], head, mp, sum);
            
            if (mp[sum] == NULL)
                mp[sum] = head;

            head = head->next;
        }

    return newHead->next;

    }
};