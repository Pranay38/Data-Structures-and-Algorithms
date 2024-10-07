class Solution {
public:
void merge(vector<int>&nums,int low,int mid,int high){
        vector<int>t;
        int l=low;
        int r=mid+1;
        while(l<=mid&&r<=high){
            if(nums[l]<=nums[r]){
                t.push_back(nums[l]);
                l++;
            }
            else {
                t.push_back(nums[r]);
                r++;
            }
        }
            while(l<=mid){
                t.push_back(nums[l]);
                l++;
            }
            while(r<=high){
                t.push_back(nums[r]);
                r++;
            }
            //nums=t;
            for(int i=0;i<t.size();i++){
                nums[low+i]=t[i];
            }
        }
    
    void mergesort(vector<int>&nums,int low,int high){
        if(low>=high)
        return;
        int mid=(low+high)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);

    }
    vector<int> sortArray(vector<int>& nums) {
        //int n=nums.size();
    //-------Selection Sort--------------------   
    //    for(int i=0;i<nums.size()-1;i++){
    //     int mini=i;
    //     for(int j=i+1;j<nums.size();j++){
    //         if(nums[j]<nums[mini])
    //         mini=j;

    //     }
    //     int temp=nums[mini];
    //     nums[mini]=nums[i];
    //     nums[i]=temp;
    //    }
    //    return nums;
    //------T.C. = O(n^2)

//-------------insertion sort-------
    // for(int i=0;i<n;i++){
    //     int j=i;
    //     while(j>0&&nums[j-1]>nums[j]){
    //         swap(nums[j-1],nums[j]);
    //         j--;
    //     }
    // }
    // return nums;
    //--------T.C.=O(N^2)------
    
    int n=nums.size();
    mergesort(nums,0,n-1);
    return nums;
    }
};