class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>s;
        for(auto it:logs){
            if(it=="../"){
                if(!s.empty())
                s.pop();
            }
            else if(it!="./")
            s.push(it);
        }
        return s.size();

    }
};