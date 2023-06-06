class Solution {
public:
vector<int> nextSmallerElementIndex(vector<int>& heights,int n){
        stack<int> st;
        vector<int> res(n);
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    
    vector<int> prevSmallerElementIndex(vector<int>& heights,int n){
        stack<int> st;
        vector<int> res(n);
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    int mah(vector<int>& heights) {
        int n=heights.size();
        //Storing next smaller element index
        vector<int> next=nextSmallerElementIndex(heights,n);
        //Storing prev smaller element index
        vector<int> prev=prevSmallerElementIndex(heights,n);
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1) next[i]=n;
            int b=next[i]-prev[i]-1;
            ans=max(ans,l*b);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
        vector<int>v;
        for(int i=0;i<m;i++){
            v.push_back(matrix[0][i]-'0');
        }
        int mx=mah(v);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                v[j]=0;
                else
                v[j]=v[j]+(matrix[i][j]-'0');
            }
            mx=max(mx,mah(v));
        }
        return mx;

    }
};