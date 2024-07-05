class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      int la=0;
      ListNode* ca=headA;
      while(ca){
        la++;
        ca=ca->next;
      }  
      int lb=0;
      ListNode* cb=headB;
      while(cb){
        lb++;
        cb=cb->next;
      }
      ca=headA;
      cb=headB;
      if(la>lb){
        for(int i=0;i<la-lb;i++)
        ca=ca->next;
      }
      else{
        for(int i=0;i<lb-la;i++)
        cb=cb->next;
      }
      while(ca&&cb){
        if(ca==cb)
        return ca;
        ca=ca->next;
        cb=cb->next;
      }
      return NULL;
    
    }
};
