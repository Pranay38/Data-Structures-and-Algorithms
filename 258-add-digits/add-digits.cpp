class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            int sum=0;
            while(num>0){
                int p=num%10;
                sum+=p;
                num=num/10;
            }
            num=sum;
        }
        return num;
    }
};