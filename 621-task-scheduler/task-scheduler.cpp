class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty()) return 0;
        vector<int> freqs(26);
        for(auto task : tasks)
            ++freqs[task - 'A'];
        sort(freqs.begin(), freqs.end(), greater<int>());
        int f = freqs[0], i = 1;
        while(i < 26 && freqs[i] == f) ++i;
        int frame_size = max(i, n + 1) * (f - 1) + i;
        int num = i * f;
        while(i < 26 && freqs[i] > 0){
            num += freqs[i];
            ++i;
        }
        return max(num, frame_size);
    }
};