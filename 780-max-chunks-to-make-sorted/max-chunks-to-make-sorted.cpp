class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> v(arr.size(),0),vec=arr;
         
         int MaxChunks=0,Max=0,Mex=0;
         for(int i=0,j=0;i<arr.size();i++){
           Max=max(Max,arr[i]);
           v[arr[i]]++;
           while(Mex<arr.size()&&v[Mex]>0){
            v[Mex]--;
            Mex++;
           }
           if(Mex<Max){

           }
           else{
            MaxChunks++;
        
           }




         }
         return MaxChunks;

        
    }
};