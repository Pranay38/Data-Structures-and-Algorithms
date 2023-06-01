class Solution {
public:
    bool isPalindrome(int x) {
        long long rem,num=x,rev=0;
        while(x){
            rem=x%10;
            rev=rev*10+rem;
            x=x/10;
        }
        if(num>=0){
        if(rev==num)
        return true;
        else
        return false;
    }
    else{
        return false;
    }

    }
    
};