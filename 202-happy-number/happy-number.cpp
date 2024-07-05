class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n!=1&&st.find(n)==st.end()){
            st.insert(n);
            int sum=0;
            while(n>0){
                int p=n%10;
                sum+=(p*p);
                n=n/10;
            }
            n=sum;

        }
        return (n==1);
    }
};