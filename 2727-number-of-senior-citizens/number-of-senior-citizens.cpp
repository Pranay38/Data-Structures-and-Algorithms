class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(int i=0;i<details.size();i++)
        {
            string str="";
            str+=details[i][11];
            str+=details[i][12];
            int x=stoi(str);
            if(x>60)
            {
                res++;
            }
        }
        return res;
    }
};