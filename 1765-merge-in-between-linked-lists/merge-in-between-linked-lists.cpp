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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
       ListNode* cur=list1;
       int l=0;
       while(cur){
        l++;
        cur=cur->next;
       }
       cur=list2;
       while(cur->next){
        cur=cur->next;
       }
       ListNode* begin=list1;
       for(int i=0;i<a-1;i++)
        begin=begin->next;
        ListNode* e=list1;
        for(int i=0;i<b+1;i++)
        e=e->next;
        begin->next=list2;
        cur->next=e;
        return list1;
    }
};