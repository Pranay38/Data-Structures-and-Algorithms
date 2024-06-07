class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        set<string> s(begin(dict), end(dict));
        vector<string> temp;
        string word, res; 

        int i = 0;
        while(i < sentence.length()) {
            string curr;
            while(sentence[i] != ' ' && i < sentence.length()) {
                curr += sentence[i++];
            }
            temp.push_back(curr);
            i++;
        }
        
        for(string t : temp) {
            int i = 0;
            while(i++ <= t.length()) {
                string curr = t.substr(0, i);
                if(s.find(curr) != s.end()) {
                    res += curr + " ";
                    break;
                }
                
                if(i == t.length()) res += curr + " ";
            }
        }

        res.erase(res.size() - 1);
        return res;
    }
};
