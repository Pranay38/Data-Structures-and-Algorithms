class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int c=0,n=hours.size();
        sort(hours.begin(),hours.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               int s=hours[i]+hours[j];
                if(s%24==0)
                c++;
            }


        }
        return c;
    }
};