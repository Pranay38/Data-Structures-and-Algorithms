class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int>prevxor(n+1,0);
        for(int i=0;i<n;i++){
            prevxor[i+1]=prevxor[i]^arr[i];
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
                if(prevxor[k+1]==prevxor[i])
                c+=k-i;
            }
        }
        return c;
    }
};