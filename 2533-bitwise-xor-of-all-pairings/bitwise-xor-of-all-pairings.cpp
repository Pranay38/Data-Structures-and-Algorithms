class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int ans=0;
        if(n1%2==0 && n2%2==0) return 0;

        if(n1%2==0 && n2%2!=0){
            for(auto i:nums1) ans^=i;
        }
        else if(n1%2!=0 && n2%2==0){
            for(auto i:nums2) ans^=i;
        }
        else{
            for(auto i:nums1) ans^=i;
            for(auto i:nums2) ans^=i;
        }

        return ans;
    }
};