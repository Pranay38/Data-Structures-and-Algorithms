class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int> nums) {
        std::sort(nums.begin(), nums.end());  
        vector<int> prev(nums.size(),-1);
        vector<int> size(nums.size(),1);
        for(int i = 1;i<nums.size();++i){
            for(int j = i-1;j>=0;--j){
                if(nums[i]%nums[j]==0 && size[j]+1>size[i]){
                    size[i] = size[j]+1;
                    prev[i] = j;
                }
            }
        }
        /*for(int i = 0;i<nums.size();++i){
            cout<<prev[i]<<" ";
        }
        cout<<endl;
        for(int i = 0;i<nums.size();++i){
            cout<<size[i]<<" ";
        }
        cout<<endl;*/
        int maxIndex = -1;
        int max = -1;
        for(int i = 0;i<nums.size(); ++i){
            if(size[i]>max){
                max = size[i];
                maxIndex = i;
            }
        }
        vector<int> res(max);


        int index = 0;
        int cur = maxIndex;
        while(cur!=-1){
            res[index++] = nums[cur];
            cur = prev[cur];
        }

        return res;
    }
};