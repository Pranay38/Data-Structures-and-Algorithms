class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        mp['b']=0;
        mp['a']=0;
        mp['l']=0;
        mp['o']=0;
        mp['n']=0;
        for(int i=0;i<text.size();i++){
            mp[text[i]]++;
        }
        vector<int>v;
        for(auto it:mp){
            if(it.first=='b')
            v.push_back(it.second);
            if(it.first=='a')
            v.push_back(it.second);
            if(it.first=='l')
            v.push_back(it.second/2);
            if(it.first=='o')
            v.push_back(it.second/2);
            if(it.first=='n')
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        return v[0];
    }
};