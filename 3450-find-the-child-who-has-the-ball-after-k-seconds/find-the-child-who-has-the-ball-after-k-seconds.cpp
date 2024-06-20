class Solution {
public:
    int numberOfChild(int n, int k) {
        int i=0,d=1;
        int c=0;
        while(k>0){
            if(i==n-1&&d==1){
                i--;
                d=-1;
            }
            else if(i==0&&d==-1){
                i++;
                d=1;
            }
            else
            i+=d;
            k--;
        }
        return i;
    }
};